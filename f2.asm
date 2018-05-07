section .rodata
    const8 dd 8

section .text
global f2
f2:
    push ebp
    mov ebp, esp

    finit
    fild dword[const8]
    fld qword[ebp + 8]
    fld st0
    faddp
    fsubp

    leave
    ret