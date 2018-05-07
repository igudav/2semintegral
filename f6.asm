section .rodata
    const2 dd 2

; x + 2
section .text
global f6
f6:
    push ebp
    mov ebp, esp

    finit
    fild dword[const2]
    fld qword[ebp + 8]
    faddp

    leave
    ret