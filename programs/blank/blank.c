#include "lilos.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main(int argc, char** argv) {
    char* ptr = malloc(20);
    strcpy(ptr, "I walk across the room and look out.");
    print(ptr);

    while(1) {}
    return 0;
}