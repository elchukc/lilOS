#include "stdlib.h"
#include "lilos.h"

/* Should return any int passed in here as a string. */
char* itoa(int i) {
    // text variable is in global data, not on the stack.
    // Will have to copy text variable to buf if we intend to call it multiple times.
    static char text[12];
    int loc = 11;
    text[11] = 0;
    char neg = 1;
    if (i >= 0) {
        neg = 0;
        i = -i;
    }

    while(i) {
        text[--loc] = '0' - (i % 10);
        i /= 10;
    }

    if (loc == 11)
        text[--loc] = '0';
    
    if (neg)
        text[--loc] = '-';
    
    return &text[loc];
}

void* malloc(size_t size) {
    return lilos_malloc(size);
}

void free(void* ptr) {
    return lilos_free(ptr);
}
