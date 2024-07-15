segment .data
	NULL        equ   0x0
	LF          equ   0xA
	CR          equ   0xD
	SYS_CALL    equ   0x80

	; for EAX
	SYS_WRITE   equ   0x4

	; for EBX
	STD_OUT     equ   0x1

	star 		DB '*',LF
	space		DB ' ',LF


segment .text

out_star:
	mov eax, SYS_WRITE
	mov ebx, STD_OUT
	mov ecx, star
	int SYS_CALL
	ret

out_space:
	mov eax, SYS_WRITE
	mov ebx, STD_OUT
	mov ecx, space
	int SYS_CALL
	ret
