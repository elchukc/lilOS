[BITS 32]

; :function ensures elf type is a function symbol type
global print:function

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