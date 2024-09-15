#include "stdio.h"
#include "lilos.h"
#include "stdlib.h"
#include <stdarg.h>

int putchar(int c) {
    lilos_putchar((char)c);
    return 0;
}

int printf(const char *fmt, ...) {
    va_list ap;
    const char* p;
    char* sval;
    int ival;

    va_start(ap, fmt);
    // While no null terminator, carry on processing
    for (p = fmt;  *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        switch (*++p) {
        case 'i':
            // read next argument available to us as an int
            ival = va_arg(ap, int);
            print(itoa(ival));
            break;

        case 's':
            // read next argument available to us as an int
            sval = va_arg(ap, char*);
            print(sval);
            break;
        
        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap);

    return 0;
}