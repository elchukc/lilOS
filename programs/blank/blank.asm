[BITS 32]

section .asm

global _start

_start:

_loop:
    call getkey
    push eax
    mov eax, 3 ; Command PUTCHAR
    int 0x80
    add esp, 4
    jmp _loop

getkey:
    mov eax, 2 ; Command GETKEY
    int 0x80
    cmp eax, 0x00
    je getkey
    ret