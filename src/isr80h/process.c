#include "process.h"
#include "kernel.h"
#include "string/string.h"
#include "task/task.h"
#include "task/process.h"
#include "status.h"
#include "config.h"

/** Userland task handling works differently from kernel re: concurrency */
void* isr80h_command6_process_load_start(struct interrupt_frame* frame) {
    void* filename_user_ptr = task_get_stack_item(task_current(), 0);
    char filename[LILOS_MAX_PATH];
    int res = copy_string_from_task(task_current(), filename_user_ptr, filename, sizeof(filename));
    if (res < 0)
        goto out;
    
    /** TODO this should be some environment variables ideally */
    char path[LILOS_MAX_PATH];
    strcpy(path, "0:/");
    strcpy(path+3, filename);

    struct process* process = 0;
    res = process_load_switch(path, &process);
    if (res < 0)
        goto out;
    
    task_switch(process->task);
    task_return(&process->task->registers);
out:
    // We will never be able to actually return from here
    return 0;
}

void* isr80h_command7_invoke_system_command(struct interrupt_frame* frame) {
    struct command_argument* arguments = task_virtual_address_to_physical(task_current(), task_get_stack_item(task_current(), 0));
    if (!arguments || strlen(arguments[0].argument) == 0)
        return ERROR(-EINVARG);
    
    struct command_argument* root_command_arg = &arguments[0];
    // root_command_arg arg1 arg2
    //        blank.elf arg1 arg2
    const char* program_name = root_command_arg->argument;

    char path[LILOS_MAX_PATH];
    // TODO should really do this with a PATH env variable.
    // But env vars are not implemented.
    strcpy(path, "0:/");
    strncpy(path+3, program_name, sizeof(path));

    struct process* process = 0;
    int res = process_load_switch(path, &process);
    if (res < 0)
        return ERROR(res);

    /** TODO Because we don't have multitasking yet, this command will
     *    have to block. We have to switch to the next task.
     *    Meaning we will never return from here if successful.
     *    Instead we fake it with assembly to redirect execution flow.
     */
    res = process_inject_arguments(process, root_command_arg);
    if (res < 0)
        return ERROR(res);
    task_switch(process->task);
    task_return(&process->task->registers);
    return 0;
}

void* isr80h_command8_get_program_arguments(struct interrupt_frame* frame) {
    struct process* process = task_current()->process;
    struct process_arguments* arguments = task_virtual_address_to_physical(task_current(), task_get_stack_item(task_current(), 0));

    process_get_arguments(process, &arguments->argc, &arguments->argv);
    return 0;
}