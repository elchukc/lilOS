[BITS 32]

section .asm

; :function ensures elf type is a function symbol type
global print:function
global lilos_getkey:function
global lilos_malloc:function
global lilos_free:function

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

; void* lilos_malloc(size_t size)
lilos_malloc:
    push ebp
    mov ebp, esp
    mov eax, 4 ; Command MALLOC (allocates memory for process)
    push dword[ebp+8] ; variable "size"
    int 0x80
    add esp, 4
    pop ebp
    ret

; void lilos_free(void* ptr)
lilos_free:
    push ebp
    mov ebp, esp
    mov eax, 5 ; Command FREE
    push dword[ebp+8] ; variable "ptr"
    int 0x80
    add esp, 4
    pop ebp
    ret