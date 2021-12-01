	.file	"pp5.9.c"
	.text
	.globl	merge
	.type	merge, @function
merge:
.LFB0:
	.cfi_startproc
	testq	%rcx, %rcx
	jle	.L13
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %r10
	movq	%rsi, %r9
	movq	%rdx, %r11
	movq	%rcx, %r8
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %eax
	jmp	.L4
.L16:
	cmpq	%r8, %rax
	jge	.L5
	movq	%rax, %rbx
	movq	%rcx, %rbp
	subq	%rax, %rcx
	leaq	(%r11,%rcx,8), %rdi
.L6:
	addq	$1, %rax
	movq	%rax, %rcx
	movq	-8(%r10,%rax,8), %rsi
	movq	%rsi, -8(%rdi,%rax,8)
	cmpq	%rax, %r8
	jne	.L6
	addq	%rbp, %rcx
	subq	%rbx, %rcx
.L5:
	cmpq	%r8, %rdx
	jge	.L1
	subq	%rdx, %rcx
	leaq	(%r11,%rcx,8), %rcx
.L7:
	addq	$1, %rdx
	movq	-8(%r9,%rdx,8), %rax
	movq	%rax, -8(%rcx,%rdx,8)
	cmpq	%rdx, %r8
	jne	.L7
.L1:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L3:
	.cfi_restore_state
	addq	$1, %rdx
.L8:
	addq	$1, %rcx
	cmpq	%rax, %rdx
	movq	%rax, %rsi
	cmovge	%rdx, %rsi
	cmpq	%r8, %rsi
	jge	.L16
; src1 = %r10, i1 = %rax, src2 = %r9, i2 = %rdx
.L4:
	movq	(%r10,%rax,8), %rdi ; rdi <- src1[i1]
	movq	(%r9,%rdx,8), %rsi  ; rsi <- src2[i2]
	cmpq	%rsi, %rdi          ; Compare rsi:rdi
	movq	%rsi, %rbx          ; rbx <- rsi
	cmovle	%rdi, %rbx          ; rbx <- rsi <= rdi ? rdi : rsi
	movq	%rbx, (%r11,%rcx,8) ; dest[id] <- rbx
	jge	.L3
	addq	$1, %rax
	jmp	.L8
.L13:
	.cfi_def_cfa_offset 8
	.cfi_restore 3
	.cfi_restore 6
	ret
	.cfi_endproc
.LFE0:
	.size	merge, .-merge
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
