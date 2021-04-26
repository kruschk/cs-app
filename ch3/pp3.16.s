	.file	"pp3.16.c"
	.text
	.globl	cond
	.type	cond, @function
cond:
.LFB0:
	.cfi_startproc
	testw	%di, %di
	je	.L1
	cmpw	%di, (%rsi)
	jge	.L1
	movw	%di, (%rsi)
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	cond, .-cond
	.ident	"GCC: (Debian 8.3.0-6) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
