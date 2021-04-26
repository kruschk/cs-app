	.file	"pp3.50.c"
	.text
	.p2align 4,,15
	.globl	fcvt2
	.type	fcvt2, @function
fcvt2:
.LFB0:
	.cfi_startproc
	movl	(%rdi), %eax
	pxor	%xmm1, %xmm1
	cvttsd2si	(%rdx), %r8d
	movss	(%rsi), %xmm0
	cvtsi2ss	%eax, %xmm1
	cvtss2sd	%xmm0, %xmm0
	movl	%r8d, (%rdi)
	movss	%xmm1, (%rsi)
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rcx, %xmm1
	movsd	%xmm1, (%rdx)
	ret
	.cfi_endproc
.LFE0:
	.size	fcvt2, .-fcvt2
	.ident	"GCC: (Debian 8.3.0-6) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
