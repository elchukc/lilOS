[BITS 32]

global _start
extern c_start
extern lilos_exit

section .asm

_start:
    call c_start
    call lilos_exit
    ret