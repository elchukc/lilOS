#include "classic.h"
#include "idt/idt.h"
#include "kernel.h"
#include "keyboard.h"
#include "io/io.h"
#include "task/task.h"
#include <stdint.h>
#include <stddef.h>

int classic_keyboard_init();

static uint8_t keyboard_scan_set_one[] = {
    0x00,
    0x1B,
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    '0',
    '-',
    '=',
    0x08,
    '\t',
    'Q',
    'W',
    'E',
    'R',
    'T',
    'Y',
    'U',
    'I',
    'O',
    'P', // 0x19
    '[', // 0x1A
    ']',
    0x0D, // 0x1C
    0x00,  // My Guess Was: 0x11, // 0x1D 	left control pressed 
    'A',
    'S', // 0x1F
    'D',
    'F', // 0x21
    'G',
    'H',
    'J',
    'K',
    'L',
    ';', // 0x27
    '\'', // 0x28
    '`',  // 0x29
    0x00, // My Guess Was: 0x0E,  // 0x2A 	left shift pressed - equiv "Shift Out?"
    '\\', // 0x2B 	\ pressed 
    'Z',
    'X',
    'C',
    'V',
    'B',
    'N',
    'M', // 0x32
    ',',
    '.',
    '/',
    0x00, // My Guess Was: 0x0F, // 0x36 	right shift pressed  - equiv "Shift In"
    '*',
    0x00, // 0x38 	left alt pressed 
    ' ', // 0x39 IF BUGGY use 0x20 for space
    0x00, // Capslock
    0x00, // 0x3B  - F1
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00, // 0x44  - F10
    0x00,
    0x00,
    '7',
    '8',
    '9',
    '-',
    '4',
    '5',
    '6',
    '+',
    '1',
    '2',
    '3',
    '0',
    '.', // 0x53
};

struct keyboard classic_keyboard = {
    .name = {"Classic"},
    .init = classic_keyboard_init
};

void classic_keyboard_handle_interrupt();

int classic_keyboard_init() {
    idt_register_interrupt_callback(ISR_KEYBOARD_INTERRUPT, classic_keyboard_handle_interrupt);
    outb(PS2_PORT, PS2_COMMAND_ENABLE_FIRST_PORT);
    return 0;
}

uint8_t classic_keyboard_scancode_to_char(uint8_t scancode) {
    // because it's an array of 8 bits, we don't actually have to divide it by 8
    size_t size_of_keyboard_set_one = sizeof(keyboard_scan_set_one) / sizeof(uint8_t);
    if (scancode > size_of_keyboard_set_one)
    	return 0;
    
    char c = keyboard_scan_set_one[scancode];
    // TODO handle shifts
    return c;
}

void classic_keyboard_handle_interrupt() {
    kernel_page();
    uint8_t scancode = 0;
    scancode = insb(KEYBOARD_INPUT_PORT);
    // ignore rogue bytes sent after the info we care about
    insb(KEYBOARD_INPUT_PORT);

    if (scancode & CLASSIC_KEYBOARD_KEY_RELEASED) {
        return;
    }

    uint8_t c = classic_keyboard_scancode_to_char(scancode);
    if (c != 0) {
        keyboard_push(c);
    }

    task_page();
}

struct keyboard* classic_init() {
    return &classic_keyboard;
}