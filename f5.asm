section .rodata
    const4 dd 4

; 4 - x^2
section .text
global f5
f5:
    push ebp
    mov ebp, esp

    finit
    fild dword[const4]
    fld qword[ebp + 8]
    fld st0
    fmulp
    fsubp

    leave
    ret