section .data
	SHADOW_SPACE_BUFF equ 32
	some_float dd 1.0

section .text 
	bits 64
	default rel

global saxpy_asm

; n		RCX
; *Z	RDX
; A		xmm2
; *X	R9
; *Y	stack
saxpy_asm:
	push	r15
	;push	xmm6
	;push	xmm7
	;push	xmm8
	push	rbp
	mov		rbp, rsp
	add		rbp, 16
	add		rbp, 8		; for pushing r15

	; xmm6: Z
	; xmm7: A
	; xmm8: X
	; xmm9: Y

	; cvtsd2ss		xmm2, xmm2
	
	mov			r15, [rbp + SHADOW_SPACE_BUFF]
	traverse:
		movss		xmm7, xmm2
		movss		xmm8, [r9 + rcx * 4]	; X
		movss		xmm9, [r15 + rcx * 4] ; Y
		
		vmulss		xmm6, xmm2, xmm8
		addss		xmm6, xmm9 ; nice

		movss		dword [rdx + rcx * 4], xmm6
		loop		traverse

		
	movss		xmm8, [r9 + rcx * 4]	; X
	movss		xmm9, [r15 + rcx * 4] ; Y

		
	vmulss		xmm6, xmm2, xmm8
	addss		xmm6, xmm9 ; nice

	movss		dword [rdx + rcx * 4], xmm6
	
	pop		rbp
	;pop		xmm8
	;pop		xmm7
	;pop		xmm6
	pop		r15

	ret
