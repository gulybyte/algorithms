segment .data
	NULL        equ   0x0
	LF          equ   0xA
	CR          equ   0xD
	SYS_CALL    equ   0x80

	; for EAX
	SYS_EXIT    equ   0x1
	SYS_READ    equ   0x3
	SYS_WRITE   equ   0x4

	; for EBX
	STD_IN      equ   0x0
	STD_OUT     equ   0x1

segment .bss
    BUFFER 		resb 0x1

segment .text

; ------------------------------------------------------------------------------------- ;
; Performs Output
; ---------------------------------------------
; Input: String value in ECX
; ---------------------------------------------
output_value:
	call  string_length
	mov   eax,  SYS_WRITE
	mov   ebx,  STD_OUT
	int   SYS_CALL
	ret
; ------------------------------------------------------------------------------------- ;



; ------------------------------------------------------------------------------------- ;
; Clears the Buffer ECX
; ---------------------------------------------
clear_buffer:
	mov   	eax,  	SYS_READ
	mov   	ebx,  	STD_IN
	mov   	ecx,  	BUFFER
	mov   	edx,  	0x1
	int   	SYS_CALL
	ret
; ------------------------------------------------------------------------------------- ;



; ------------------------------------------------------------------------------------- ;
; Calculate the length of the String
; ---------------------------------------------
; Input: String value in ECX
; Output: Number of characters in EDX
; ---------------------------------------------
string_length:
    xor 	edx, 	edx
.count_loop:
	movzx   eax, byte[ecx + edx]      ; Load the next byte of the string
	cmp     eax, 0                    ; Compare with zero (end of string)
	je      .done                     ; If zero, end the loop
	inc     edx                       ; Increment the character count
	jmp     .count_loop               ; Jump back to the beginning of the loop
.done:
	ret
; ------------------------------------------------------------------------------------- ;



; ------------------------------------------------------------------------------------- ;
; Convert String to integer
; ---------------------------------------------
; Input: String value in ECX
; Output: Integer value in EAX
; ---------------------------------------------
string_to_int:
    xor   eax,  eax                ; Clear EAX to store the integer value
.next_digit_int:
    movzx   ebx,  byte[ecx]        ; Load the next byte of the string into EBX
    cmp     ebx,  '0'              ; Compare with '0' to validate if it is a valid digit
    jl      .done                  ; If less than '0', end the loop
    cmp     ebx,  '9'              ; Compare with '9' to check if it is a valid digit
    jg      .done                  ; If greater than '9', end the loop
    sub     ebx, '0'               ; Convert the ASCII character to the numeric value
    imul    eax,  eax, 10          ; Multiply the current value by 10 (shift left)
    add     eax,  ebx              ; Add the new digit to the accumulated value
    inc     ecx                    ; Move to the next character in the string
    jmp     .next_digit_int        ; Jump back to the beginning of the loop
.done:
    ret                            ; Return with the integer value in EAX
; ------------------------------------------------------------------------------------- ;



; ------------------------------------------------------------------------------------- ;
; Convert integer to string (up to 4 digits)
; ---------------------------------------------
; Input: Integer value in EAX
; Output: String value in ECX
; ---------------------------------------------
int_to_string:
    lea esi, [BUFFER]  ; Load the address of the buffer into esi
    add esi, 0x9       ; Move esi to position 9 in the buffer
    mov byte [esi], 0xA; Place the newline character (0xA) at position 9
    mov ecx, esi       ; Initialize ecx with the address of position 9 in the buffer
    mov ebx, 0xA       ; Set ebx to 10 (divisor)

.prox_digito:
    xor edx, edx       ; Clear the edx register (remainder of division)
    div ebx            ; Divide eax by ebx; result in eax, remainder in edx
    add dl, '0'        ; Convert the digit to ASCII
    dec esi            ; Move to the next position in the buffer
    mov [esi], dl      ; Store the converted character in the buffer
    test eax, eax      ; Test if eax still has digits
    jnz .prox_digito   ; If yes, continue the loop

    mov ecx, esi       ; Update ecx to point to the beginning of the converted string

    ret
; ------------------------------------------------------------------------------------- ;
