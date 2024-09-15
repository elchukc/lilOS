#ifndef LILOS_H
#define LILOS_H

#include <stddef.h>

void print(const char* message);
int lilos_getkey();
void* lilos_malloc(size_t size);
void lilos_free(void* ptr);
void lilos_putchar(char c);

#endif