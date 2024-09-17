#ifndef LILOS_H
#define LILOS_H

#include <stddef.h>
#include <stdbool.h>

struct command_argument {
    char argument[512];
    struct command_argument* next;
};

struct process_arguments {
    int argc;
    char** argv;
};

void print(const char* message);
int lilos_getkey();
void lilos_putchar(char c);
void* lilos_malloc(size_t size);
void lilos_free(void* ptr);
void lilos_process_load_start(const char* filename);
int lilos_system(struct command_argument* arguments);
void lilos_process_get_arguments(struct process_arguments* arguments);

int lilos_getkeyblock();
void lilos_terminal_readline(char* out, int max, bool output_while_typing);
struct command_argument* lilos_parse_command(const char* command, int max);
int lilos_system_run(const char* command);

#endif