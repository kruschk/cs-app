	.file	"pp3.33.c"
	.text
	.globl	procprob
	.type	procprob, @function
procprob:
.LFB0:
	.cfi_startproc
	movslq	%edi, %rdi
	addq	%rdi, (%rdx)
	addb	%sil, (%rcx)
	movl	$6, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	procprob, .-procprob
	.globl	procprob2
	.type	procprob2, @function
procprob2:
.LFB1:
	.cfi_startproc
	movslq	%esi, %rsi
	addq	%rsi, (%rcx)
	addb	%dil, (%rdx)
	movl	$6, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	procprob2, .-procprob2
	.ident	"GCC: (Debian 8.3.0-6) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
