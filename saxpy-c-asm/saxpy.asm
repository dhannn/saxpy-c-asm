section .data
	SHADOW_SPACE_BUFF equ 32
	some_float dq 761.7
	FMT db "Z[%d] = %.4f", 10, 0
	SPACING db 10, 0

section .text 
	bits 64
	default rel

global saxpy_asm


; Parameters:
;   n       : RCX
;   *Z      : RDX
;   A       : xmm2
;   *X      : R9
;   *Y      : stack
saxpy_asm:
	push	r15				; Preserve r15
	push	rbp				; Preserve rbp
	mov		rbp, rsp		; Set rbp to current stack pointer
	add		rbp, 16			; Adjust rbp for stack alignment
	add		rbp, 8			; Allocate space for pushing r15 

	; xmm6: Z
	; xmm7: A
	; xmm8: X
	; xmm9: Y
	
	mov			r15, [rbp + SHADOW_SPACE_BUFF]		; Load shadow space buffer address
	traverse:
		movss		xmm7, xmm2						; Move A to xmm7
		movss		xmm8, [r9 + rcx * 4]			; Load X[i] value
		movss		xmm9, [r15 + rcx * 4]			; Load Y[i] value
		
		vmulss		xmm6, xmm2, xmm8				; Multiply A by X and store in xmm6
		addss		xmm6, xmm9 ; nice				; Add Y to xmm6

		movss		dword [rdx + rcx * 4], xmm6		; Store result in Z[i]
		loop		traverse						; Loop until zero

	
	; Do the same process for the final element
	movss		xmm8, [r9 + rcx * 4]	
	movss		xmm9, [r15 + rcx * 4] 

		
	vmulss		xmm6, xmm2, xmm8
	addss		xmm6, xmm9 ; nice

	movss		dword [rdx + rcx * 4], xmm6

	pop		rbp		; Restore rbp
	pop		r15		; Restore r15

	ret
