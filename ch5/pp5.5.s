	.file	"pp5.5.c"
	.text
	.globl	poly
	.type	poly, @function
poly:
; a = %rdi, degree = %rsi, x = %xmm0
.LFB0:
	.cfi_startproc
	movapd	%xmm0, %xmm3  ; xpwr <- x
	movsd	(%rdi), %xmm0 ; result <- M[a]
	testq	%rsi, %rsi    ; Compare degree:degree
	jle	.L1               ; Jump if <=
	leaq	8(%rdi), %rax ; a <- 8 + a
	leaq	8(%rdi,%rsi,8), %rdx ; limit <- a + 8*degree + 8
	movapd	%xmm3, %xmm1  ; xpwr <- xpwr = x
; a = %rax, result = %xmm0, xpwr = %xmm1, x = %xmm3
.L3:
	movapd	%xmm1, %xmm2  ; t <- xpwr
	mulsd	(%rax), %xmm2 ; t <- M[a]*t = M[a]*xpwr
	addsd	%xmm2, %xmm0  ; result <- t + result = M[a]*xpwr + result
	mulsd	%xmm3, %xmm1  ; xpwr <- x*xpwr
	addq	$8, %rax      ; a <- a + 8
	cmpq	%rdx, %rax    ; Compare limit:a
	jne	.L3               ; Jump if !=
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	poly, .-poly
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
