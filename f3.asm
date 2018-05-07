section .rodata
    constneg5 dd -5

section .text
global f3
f3:
    push ebp
    mov ebp, esp

    finit
    fild dword[constneg5]
    fld qword[ebp + 8]
    fdivp

    leave
    ret