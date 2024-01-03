section .data
	p1 			db 	LF,'Result Addition: ', NULL
	p2 			db 	LF,'Result Subtraction: ', NULL
	p3 			db 	LF,'Result Multiplication: ', NULL
	p4 			db 	LF,'Result Division: ', NULL
	div_zero	db	'BOOOOOM!!!!!', NULL

; The rule is simple: the option of the equation must be contained in AH (already validated);
; and the numbers, respectively, in EBP and EDI. Keep in mind that the registers;
; AH, EBP, and EDI should already be "typed as int". The return of any;
; of the equations will be the result in EAX as an int. The only label that should;
; be called outside of this file is make_equation with a jmp. It will;
; do what it needs to do and, in the end, jmp to the 'end' label in main to finish;
; the program.
segment .text

	make_equation:
		cmp 	ah, 	1
		je		addition
		cmp 	ah, 	2
		je		subtraction
		cmp 	ah, 	3
		je		multiplication
		cmp 	ah, 	4
		je		division

	addition:
		show_msg_add:
			mov 	ecx, 	p1
			call 	output_value
		func_add:
			mov     eax, 	ebp
			add     eax, 	edi
		output_func_add:
			call	int_to_string
			call 	output_value
		jmp 	end


	subtraction:
		show_msg_sub:
			mov 	ecx, 	p2
			call 	output_value
		func_sub:
			mov     eax, 	ebp
			sub     eax, 	edi
		output_func_sub:
			call	int_to_string
			call 	output_value
		jmp 	end


	multiplication:
		show_msg_imul:
			mov 	ecx, 	p3
			call 	output_value
		func_imul:
			mov     eax, 	ebp
			imul	eax, 	edi
		output_func_imul:
			call	int_to_string
			call 	output_value
		jmp 	end


	division:
		show_msg_div:
			mov 	ecx, 	p4
			call 	output_value
		verify_edi_zero:
			cmp 	edi,	0
			jne		func_div
			mov		ecx, 	div_zero
			call	output_value
			jmp 	end
		func_div:
			mov     eax, 	ebp
			xor		edx, 	edx
			idiv	edi
		output_func_div:
			call	int_to_string
			call 	output_value
		jmp 	end

