#include "lilos.h"
#include "stdlib.h"

int main(int argc, char** argv) {
    print("Hello how are you!\n");

    print(itoa(8578));
    void* ptr = malloc(512);
    free(ptr);
    if (ptr) {}
    while(1) {
        if (lilos_getkey() != 0)
            print("Key was pressed.\n");
    }
    return 0;
}