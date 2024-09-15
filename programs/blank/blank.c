#include "lilos.h"
#include "stdlib.h"
#include "stdio.h"

int main(int argc, char** argv) {
    printf("My age is %i\n", 98);
    print("Hello how are you!\n");

    print(itoa(8578));
    putchar('Z');
    void* ptr = malloc(512);
    free(ptr);
    if (ptr) {}
    while(1) {
        if (lilos_getkey() != 0)
            print("Key was pressed.\n");
    }
    return 0;
}