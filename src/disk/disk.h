#ifndef DISK_H
#define DISK_H

#include "fs/file.h"

typedef unsigned int LILOS_DISK_TYPE;

// Represents a real physical hard disk
#define LILOS_DISK_TYPE_REAL 0

struct disk {
    LILOS_DISK_TYPE type;
    int sector_size;

    // The id of the disk
    // In a better implementation, id would be the index in an array of disks
    int id;

    struct filesystem* filesystem;

    // The private data of our filesystem
    void* fs_private;
};

void disk_search_and_init();
struct disk* disk_get(int index);
int disk_read_block(struct disk* idisk, unsigned int lba, int total, void* buf);

#endif