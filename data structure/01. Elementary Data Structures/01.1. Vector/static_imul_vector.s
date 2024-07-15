%include 'utils.inc'

section .data
    vector:         dd      1, 1, 2, 3, 5, 8, 13
    size_vector:    equ     7

section .text
    global _start

_start:
    mov     edi,    size_vector
    mov     r8d,    vector
	call    show_vector

show_vector:
    cmp     edi,    0
    je      end

    mov     eax,    [r8d]
    call    int_to_string
    call    output_value

    add     r8d,    4
    dec     edi
    jmp     show_vector

end:
    mov   	eax,  	SYS_EXIT
    xor   	ebx,  	ebx
    int   	SYS_CALL
