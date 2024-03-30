.section data
	SHADOW_SPACE_BUFF equ 32

.section text 
	bits 64
	default rel

global saxpy_asm

; n		RCX
; *Z	RDX
; A		R8/xmm2
; *X	R
; *Y	stack
saxpy_asm:
	push	rbp
	push	xmm6
	push	xmm7
	push	xmm8
	add		rbp, 16
	mov		r10, rbp + SHADOW_SPACE_BUFF
	
	traverse:
		; movss		xmm6, [rdx + rcx * 8]
		movss		xmm7, xmm2
		movss		xmm8, [r9 + rcx * 8]
		movss		xmm9, [r10 + rcx * 8]
		
		vmulss		xmm6, xmm7, xmm8
		addss		xmm6, xmm9 ; nice
		movss		qword [rdx + rcx * 8], xmm6
		loop		traverse

	; pop 
	pop rbp
