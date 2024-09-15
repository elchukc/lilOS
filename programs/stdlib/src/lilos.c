#include "lilos.h"

/** Block until a value is pressed */
int lilos_getkeyblock() {
    int val = 0;
    do {
        val = lilos_getkey();
    } while(val == 0);
    return val;
}

void lilos_terminal_readline(char* out, int max, bool output_while_typing) {
    int i = 0;
    for (i = 0; i < max - 1; i++) {
        char key = lilos_getkeyblock();
        // Carriage return means we have read the line
        if (key == 13) {
            break;
        }

        if (output_while_typing) {
            lilos_putchar(key);
        }

        // Backspace
        if (key == 0x08 && i >= 1) {
            out[i-1] = 0x00;
            // -2 because we will +1 when we go to continue
            i -= 2;
            continue;
        }

        out[i] = key;
    }

    // Add the null terminator
    out[i] = 0x00;
}