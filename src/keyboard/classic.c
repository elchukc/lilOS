#include "classic.h"
#include "keyboard.h"
#include "io/io.h"
#include <stdint.h>
#include <stddef.h>

int classic_keyboard_init();

static uint8_t keyboard_scan_set_one[] = {
    0x00,
    0x1B,
    '1', // 0x02
    '2', // 0x03
    '3', // 0x04
    '4', // 0x05
    '5', // 0x06
    '6', // 0x07
    '7', // 0x08
    '8', // 0x09
    '9', // 0x0A
    '0', // 0x0B
    '-', // 0x0C
    '=', // 0x0D
    0x08, // 0x0E
    '\t', // 0x0F
    'Q', // 0x10
    'W', // 0x11
    'E', // 0x12
    'R', // 0x13
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

int classic_keyboard_init() {
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
    
}

struct keyboard* classic_init() {
    return &classic_keyboard;
}