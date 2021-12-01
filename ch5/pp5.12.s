	.file	"pp5.12.c"
	.text
	.globl	psum1
	.type	psum1, @function
psum1:
; %rdi = a, %rsi = p, %rdx = n
.LFB0:
	.cfi_startproc
	movss	(%rdi), %xmm0 ; acc <- M[a]
	movss	%xmm0, (%rsi) ; M[p] <- acc
	cmpq	$1, %rdx      ; Compare 1:n
	jle	.L1               ; Jump if <=
	movl	$1, %eax      ; i <- 1

.L3:
	addss	(%rdi,%rax,4), %xmm0 ; acc <- M[a+i*4] + acc = a[i] + acc
	movss	%xmm0, (%rsi,%rax,4) ; M[p+i*4] = p[i] <- acc
	addq	$1, %rax             ; i <- 1 + i
	cmpq	%rax, %rdx           ; Compare i:n
	jne	.L3                      ; Jump if !=
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	psum1, .-psum1
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
