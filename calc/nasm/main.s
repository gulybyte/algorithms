%include 'utils.inc'
%include 'calc.inc'

section .data
	msgOption 	db 	LF,'What is the option number to proceed? ', NULL
	msgError 	db 	'Invalid Option Value',LF, NULL
	msgEnd 		db 	LF,'Program finished', LF, NULL
	numVal1 	db 	LF,'Value 1: ', NULL
	numVal2 	db 	LF,'Value 2: ', NULL
	options 	db 	LF,'1. Addition',LF,'2. Subtraction',LF,'3. Multiplication',LF,'4. Division',LF,NULL
	max_val_num	equ 0x5 ; 4 digit

section .bss
	optionCalc 		resb 1
	; máx 5 digit
	num1 			resb 5
	num2 			resb 5

section .text
global _start

_start:
	call	get_values
	call 	show_options
	call 	get_input_option_as_int
	jmp 	make_equation



show_options:
	mov 	ecx, 	options
	call 	output_value
	ret



get_input_option_as_int:
	call 	show_message_option
	call	get_input_option
	call	convert_option_in_int
	call 	valid_size_option
	ret
	get_input_option:
		mov 	eax, 	SYS_READ
		mov 	ebx, 	STD_IN
		mov 	ecx, 	optionCalc
		mov 	edx, 	0x1
		int 	SYS_CALL
		ret
	show_message_option:
		mov 	ecx, 	msgOption
		call 	output_value
		ret
	convert_option_in_int:
		mov 	ah, 	[optionCalc]
		sub 	ah, 	'0'
		ret
	valid_size_option:
		cmp 	ah, 	4
		jg 		validation_error
		cmp 	ah, 	1
		jl 		validation_error
		ret
	validation_error:
		mov 	ecx, 	msgError
		call 	output_value
		jmp		end



get_values:
	get_val1:
		mov 	ecx, 	numVal1
		call 	output_value
		mov 	eax, 	SYS_READ
		mov 	ebx, 	STD_IN
		mov 	ecx, 	num1
		mov 	edx, 	max_val_num
		int 	SYS_CALL
		call	string_to_int
		mov 	ebp,	eax
	get_val2:
		mov 	ecx, 	numVal2
		call 	output_value
		mov 	eax, 	SYS_READ
		mov 	ebx, 	STD_IN
		mov 	ecx, 	num2
		mov 	edx, 	max_val_num
		int 	SYS_CALL
		call	string_to_int
		mov 	edi,	eax
	ret




end:
	mov 	ecx, 	msgEnd
	call 	output_value
    mov   	eax,  	SYS_EXIT
    xor   	ebx,  	ebx
    int   	SYS_CALL
