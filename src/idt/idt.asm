section .asm

extern int21h_handler
extern no_interrupt_handler
extern isr80h_handler

global int21h
global idt_load
global no_interrupt
global enable_interrupts
global disable_interrupts
global isr80h_wrapper

enable_interrupts:
    sti
    ret

disable_interrupts:
    cli
    ret

idt_load:
    push ebp
    mov ebp, esp

    mov ebx, [ebp+8]
    lidt [ebx]
    pop ebp
    ret

int21h: ; Keyboard Interrupt
    pushad
    call int21h_handler
    popad
    iret

no_interrupt:
    pushad
    call no_interrupt_handler
    popad
    iret

isr80h_wrapper:
    ; INTERRUPT FRAME START
    ; ALREADY PUSHED TO US BY THE PROCESSOR UPON ENTRY TO THIS INTERRUPT
    ; Pushes the general purpose registers to the stack
    ; uint32_t ip;
    ; uint32_t cs;
    ; uint32_t flags;
    ; uint32_t sp;
    ; uint32_t ss;
    ; Save user land registers
    pushad

    ; INTERRUPT FRAME END

    ; Push a pointer to the user land registers, and the stack that was passed to us.
    ; Essentially push a pointer to the interrupt frame.
    push esp

    ; EAX holds our command let's push it
    push eax
    call isr80h_handler
    mov dword[tmp_res], eax
    add esp, 8 ; alternately, pop ebx twice

    ; Restore user land registers
    popad

    ; Set the EAX register to the return result stored in tmp_res
    mov eax, [tmp_res]

    iretd


section .data
; Inside here is stored the return result from isr80h_handler
tmp_res: dd 0