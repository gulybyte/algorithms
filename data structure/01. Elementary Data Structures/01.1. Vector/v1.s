%include 'utils.inc'

section .text
global GeneratedStars

GeneratedStars:
	call stars_out
	ret

stars_out:
	; is_one_star?
	cmp edi, 1
	je one_star

	mov r8d, edi ; line
	add r8d, 1
	loop_line_star:
		sub r8d, 1
		cmp r8d, 0
		je end

		mov r9d, edi ; column
		sub r9d, 1
		loop_column_star:
			; output: "*"
			mov edx, 1
			call out_star

			sub r9d, 1
			cmp r9d, 0
			jne loop_column_star

			; output: "*\n"
			mov edx, 2
			call out_star
			jmp loop_line_star

	one_star:
		mov edx, 2
		call out_star
		jmp end

	end:
		ret

