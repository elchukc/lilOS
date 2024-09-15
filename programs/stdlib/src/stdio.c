#include "stdio.h"
#include "lilos.h"

int putchar(int c) {
    lilos_putchar((char)c);
    return 0;
}