#ifndef KEYBOARD_H
#define KEYBOARD_H

typedef unsigned int KEYBOARD_CAPSLOCK_STATE;
enum {
    KEYBOARD_CAPSLOCK_OFF,
    KEYBOARD_CAPSLOCK_ON
};
struct process;
typedef int (*KEYBOARD_INIT_FUNCTION)();
struct keyboard {
    KEYBOARD_INIT_FUNCTION init;
    char name[20];
    struct keyboard* next;
};

void keyboard_init();
void keyboard_push(char c);
void keyboard_backspace(struct process* process);
char keyboard_pop();
int keyboard_insert(struct keyboard* keyboard);

KEYBOARD_CAPSLOCK_STATE keyboard_get_capslock();
void keyboard_set_capslock(KEYBOARD_CAPSLOCK_STATE state);
void keyboard_toggle_capslock();

#endif