#include "lilos.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main(int argc, char** argv) {
    char str[] = "I walk across the room and look out.";
    struct command_argument* root_command = lilos_parse_command(str, sizeof(str));
    struct command_argument* command = root_command;
    while(command != 0x00) {
        printf("%s\n", command->argument);
        command = command->next;
    }

    while(1) {}
    return 0;
}