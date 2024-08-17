ORG 0
BITS 16

_start:
    jmp short start
    nop

; To get around USB emulation.
; See https://wiki.osdev.org/FAT#BPB_(BIOS_Parameter_Block)
times 33 db 0

start:
    jmp 0x7c0:step2

step2:
    cli ; Clear Interrupts
    mov ax, 0x7c0
    mov ds, ax
    mov es, ax
    mov ax, 0x00
    mov ss, ax
    mov sp, 0x7c00
    sti ; Enables Interrupts

    jmp $

print:
    mov bx, 0
.loop:
    lodsb
    cmp al, 0
    je .done
    call print_char
    jmp .loop
.done:
    ret

print_char:
    mov ah, 0eh
    int 0x10
    ret

times 510-($ - $$) db 0
dw 0xAA55