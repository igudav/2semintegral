; 2x-1
section .text
global f5
f5:
    push ebp
    mov ebp, esp

    finit
    fld qword[ebp + 8]
    fld st0
    faddp
    fld1
    fsubp

    leave
    ret