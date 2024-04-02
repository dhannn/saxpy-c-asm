section .data
	SHADOW_SPACE_BUFF equ 32
	some_float dq 761.7
	FMT db "Z[%d] = %.4f", 10, 0
	SPACING db 10, 0

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
	push	rbp
	mov		rbp, rsp
	add		rbp, 16
	add		rbp, 8		; for pushing r15

	; xmm6: Z
	; xmm7: A
	; xmm8: X
	; xmm9: Y
	
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
	pop		r15

	ret
