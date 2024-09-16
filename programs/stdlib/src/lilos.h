#ifndef LILOS_H
#define LILOS_H

#include <stddef.h>
#include <stdbool.h>

void print(const char* message);
int lilos_getkey();
void* lilos_malloc(size_t size);
void lilos_free(void* ptr);
void lilos_putchar(char c);
void lilos_process_load_start(const char* filename);

int lilos_getkeyblock();
void lilos_terminal_readline(char* out, int max, bool output_while_typing);

#endif