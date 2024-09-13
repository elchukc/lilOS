#include "io.h"
#include "task/task.h"
#include "kernel.h"
#include "keyboard/keyboard.h"

void* isr80h_command1_print(struct interrupt_frame* frame) {
    // The message to print is the first element on the user stack
    // task_get_stack_item will pull the first element pushed to the task stack
    void* user_space_msg_buffer = task_get_stack_item(task_current(), 0);
    char buf[1024];
    copy_string_from_task(task_current(), user_space_msg_buffer, buf, sizeof(buf));
    print(buf);
    return 0;
}

void* isr80h_command2_getkey(struct interrupt_frame* frame) {
    char c = keyboard_pop();
    return (void*)((int)c);
}