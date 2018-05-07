; x^2
section .text
global f4
f4:
    push ebp
    mov ebp, esp

    finit
    fld qword[ebp + 8]
    fld st0
    fmulp

    leave
    ret