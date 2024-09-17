#include "lilos.h"

extern int main(int argc, char** argv);

void c_start() {
    struct process_arguments arguments;
    lilos_process_get_arguments(&arguments);

    int res = main(arguments.argc, arguments.argv);
    if (res == 0) {
        // Eventually this return code be used to pass to the exit command
    }
}