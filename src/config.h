#ifndef CONFIG_H
#define CONFIG_H

// Correspond to consts in kernel.asm
#define KERNEL_CODE_SELECTOR 0x08 // CODE_SEG equ 0x08
#define KERNEL_DATA_SELECTOR 0x10 // DATA_SEG equ 0x10


#define LILOS_TOTAL_INTERRUPTS 512

// 100 MB heap size
#define LILOS_HEAP_SIZE_BYTES 104857600
#define LILOS_HEAP_BLOCK_SIZE 4096
#define LILOS_HEAP_ADDRESS 0x01000000
#define LILOS_HEAP_TABLE_ADDRESS 0x00007E00

#define LILOS_SECTOR_SIZE 512

#define LILOS_MAX_FILESYSTEMS 12
#define LILOS_MAX_FILE_DESCRIPTORS 512

#define LILOS_TOTAL_GDT_SEGMENTS 6

#endif