#include "lilos.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main(int argc, char** argv) {
    char words[] = "I walk across the room and look out";

    const char* token = strtok(words, " ");
    while(token) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    while(1) {}
    return 0;
}