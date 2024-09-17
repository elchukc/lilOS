#include "shell.h"
#include "stdio.h"
#include "stdlib.h"
#include "lilos.h"

int main(int argc, char** argv) {
    print("LilOS v1.0.0\n");
    while(1) {
        print("\n> ");
        char buf[1024];
        lilos_terminal_readline(buf, sizeof(buf), true);
        print("\n");
        lilos_system_run(buf);
    }
    return 0;
}