#include "keyboard.h"
#include "status.h"
#include "kernel.h"
#include "task/process.h"
#include "task/task.h"
#include "classic.h"

static struct keyboard* keyboard_list_head = 0;
static struct keyboard* keyboard_list_tail = 0;

void keyboard_init() {
    keyboard_insert(classic_init());
}

/** Adds a new keyboard to our system */
int keyboard_insert(struct keyboard* keyboard) {
    int res = 0;
    if (keyboard->init == 0) {
        res = -EINVARG;
        goto out;
    }

    if (keyboard_list_tail) {
        keyboard_list_tail->next = keyboard;
        keyboard_list_tail = keyboard;
    } else {
        keyboard_list_head = keyboard;
        keyboard_list_tail = keyboard;
    }

    res = keyboard->init();
out:
    return res;
}

static int keyboard_get_tail_index(struct process* process) {
    return process->keyboard.tail % sizeof(process->keyboard.buffer);
}

void keyboard_backspace(struct process* process) {
    process->keyboard.tail -= 1;
    int real_index = keyboard_get_tail_index(process);
    process->keyboard.buffer[real_index] = 0x00;
}

/** Currently only supports ascii character set */
void keyboard_push(char c) {
    struct process *process = process_current();
    // We don't allow keyboard access when no process is running
    if (!process)
    	return;
    
    // Will wrap around, the power of remainder ;)
    int real_index = keyboard_get_tail_index(process);
    process->keyboard.buffer[real_index] = c;
    process->keyboard.tail++;
    
    // Let all keyboard listeners know about this key press
    // (Not Implemented for this tutorial)
    // keyboard_listener_keypressed();
}

char keyboard_pop() {
    // We don't use the current process!! We use the current task's process.
    // This will save us errors in a multitasking environment
    // We don't allow keyboard access when no process is running
    if (!task_current())
    	return 0;
    	
    // Will wrap around, the power of remainder ;)
    struct process* process = task_current()->process;
    int real_index = process->keyboard.head % sizeof(process->keyboard.buffer);
    char c = process->keyboard.buffer[real_index];
    if (c == 0x00) {
        // Nothing to pop? Then no need to increase the head
        return 0;
    }
    process->keyboard.buffer[real_index] = 0;
    process->keyboard.head++;
    return c;
}
