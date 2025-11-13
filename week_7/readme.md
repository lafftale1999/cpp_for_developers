### x86 Assembly "Hello world"
```asm
section        .text         
global         _start          
_start:
    mov edx, len 
    mov ecx, msg 
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov eax, 1
    int 0x80

section        .data             
    msg        db "Hello world!", 0xa
    len        equ $ -msg
```

### ARM Assembly "Hello world"
```asm
    .section .text
    .global _start

_start:
    mov     r0, #1
    ldr     r1, =msg
    ldr     r2, =len
    mov     r7, #4
    svc     #0

    @ exit(0)
    mov     r0, #0
    mov     r7, #1
    svc     #0

    .section .data
msg:
    .ascii  "Hello world!"
len = . - msg
```