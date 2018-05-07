section .rodata
    conste dq 2.718281828459045 ; число е

; представляем e^x как 2^[x lb e] * 2^{x lb e}
section .text
global f1
f1:
    push ebp
    mov ebp, esp

    finit
    fld qword[ebp + 8]
    fld qword[conste]
    fyl2x ; x lb e
    fist dword[ebp - 4]
    fild dword[ebp - 4]
    fld1
    fscale ; целая часть
    fxch
    fstp st0
    fxch
    fild dword[ebp - 4]
    fsubp
    f2xm1 ; дробная часть
    fld1
    faddp
    fmulp
    fld1
    fld1
    faddp
    faddp

    leave
    ret