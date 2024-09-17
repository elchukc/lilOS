[BITS 32]

section .asm

; :function ensures elf type is a function symbol type
global print:function
global lilos_getkey:function
global lilos_putchar:function
global lilos_malloc:function
global lilos_free:function
global lilos_process_load_start:function
global lilos_system:function
global lilos_process_get_arguments:function

; void print(const char* message)
print:
    ; Pushing ebp, then popping off ebp and returning
    ;   is how C compilers create stack frames
    push ebp
    ; move stack ptr into the base ptr
    mov ebp, esp
    ; +8 because we pushed our base ptr to stack (4 bytes)
    ; plus caller of this fn pushed return addr to stack (4 bytes)
    push dword[ebp+8]
    mov eax, 1 ; Command PRINT
    int 0x80
    ; Restore the stack ptr
    add esp, 4
    pop ebp
    ret

; int lilos_getkey()
lilos_getkey:
    push ebp
    mov ebp, esp
    ; if the return type in C can fit into 4 bytes,
    ;   C uses the eax register
    mov eax, 2 ; Command GETKEY
    int 0x80

    pop ebp
    ret

; void putchar(char c)
lilos_putchar:
    push ebp
    mov ebp, esp
    mov eax, 3 ; Command PUTCHAR
    push dword[ebp+8] ; Variable 'c'
    int 0x80
    add esp, 4
    pop ebp
    ret

; void* lilos_malloc(size_t size)
lilos_malloc:
    push ebp
    mov ebp, esp
    mov eax, 4 ; Command MALLOC (allocates memory for process)
    push dword[ebp+8] ; Variable "size"
    int 0x80
    add esp, 4
    pop ebp
    ret

; void lilos_free(void* ptr)
lilos_free:
    push ebp
    mov ebp, esp
    mov eax, 5 ; Command FREE
    push dword[ebp+8] ; Variable "ptr"
    int 0x80
    add esp, 4
    pop ebp
    ret

; void lilos_process_load_start(const char* filename)
lilos_process_load_start:
    ; There should really be error handling on this function
    push ebp
    mov ebp, esp
    mov eax, 6 ; Command PROCESS_LOAD_START (starts a process)
    push dword[ebp+8] ; Variable "filename"
    int 0x80 ; We won't actually be returning from this interrupt
    add esp, 4
    pop ebp
    ret

; int lilos_system(struct command_argument* arguments)
lilos_system:
    push ebp
    mov ebp, esp
    mov eax, 7 ; Command PROCESS_SYSTEM (runs a system command based on the arguments)
    push dword[ebp+8] ; Variable "arguments"
    int 0x80
    add esp, 4
    pop ebp
    ; Because this never returns, eax will contain 7 if command is successful
    ret

; void lilos_process_get_arguments(struct process_arguments* arguments)
lilos_process_get_arguments:
    push ebp
    mov ebp, esp
    mov eax, 8 ; Command GET_PROGRAM_ARGUMENTS
    push dword[ebp+8] ; Variable "arguments"
    int 0x80
    add esp, 4
    pop ebp
    ret