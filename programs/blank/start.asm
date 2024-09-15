[BITS 32]

global _start
extern main

section .asm

_start:
    push 50 ; argv
    push 20 ; argc
    call main
    ret