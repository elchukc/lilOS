#ifndef PROCESS_H
#define PROCESS_H

#include "config.h"
#include "task.h"
#include <stdint.h>

struct process {
    // The process id
    uint16_t id;

    char filename[LILOS_MAX_PATH];

    // The main process task
    struct task* task;

    // The memory (malloc) allocations of the process
    void* allocations[LILOS_MAX_PROGRAM_ALLOCATIONS];

    // The physical pointer to the process memory
    // This assumes binary processes; no headers or sections (<7:18 in video)
    void* ptr;

    // The physical pointer to the stack memory
    void* stack;

    // The size of the data pointer to by "ptr"
    uint32_t size;
};

#endif