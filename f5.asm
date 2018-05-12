; 2x+3
section .rodata
    const3 dd 3

section .text
global f5
f5:
    push ebp
    mov ebp, esp

    finit
    fld qword[ebp + 8]
    fld st0
    faddp
    fild dword[const3]
    faddp

    leave
    ret