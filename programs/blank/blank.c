#include "lilos.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main(int argc, char** argv) {
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    // Uncomment if you want to test multi-tasking
    //      because this will make the program run for a long time
    // while(1) {
    //     print(argv[0]);
    //     for (int i = 0; i < 100000000; i++) {  }
    // }

    return 0;
}