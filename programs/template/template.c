#include "lilos.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main(int argc, char** argv) {
    // Replace with your own code
    print("This is a template! You can write your own programs like this one.\n");
    for (int i = 0; i < argc; i++) {
        printf("arg %i: %s\n", i, argv[i]);
    }

    return 0;
}