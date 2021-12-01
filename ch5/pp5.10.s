	.file	"pp5.10.c"
	.text
	.globl	copy_array
	.type	copy_array, @function
copy_array:
; %rdi = src, %rsi = dest, %rdx = n
.LFB11:
	.cfi_startproc
	testq	%rdx, %rdx ; Test n:n
	jle	.L1
	movl	$0, %eax   ; i <- 0
.L3:
	movq	(%rdi,%rax,8), %rcx ; t <- src[i]
	movq	%rcx, (%rsi,%rax,8) ; dest[i] <- t
	addq	$1, %rax            ; i <- i + 1
	cmpq	%rax, %rdx          ; Test i:n
	jne	.L3
.L1:
	ret
	.cfi_endproc
.LFE11:
	.size	copy_array, .-copy_array
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d "
	.text
	.globl	print_array
	.type	print_array, @function
print_array:
.LFB12:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	testq	%rsi, %rsi
	jle	.L6
	movq	%rdi, %r12
	movq	%rsi, %rbp
	movl	$0, %ebx
	leaq	.LC0(%rip), %r13
.L7:
	movq	(%r12,%rbx,8), %rsi
	movq	%r13, %rdi
	movl	$0, %eax
	call	printf@PLT
	addq	$1, %rbx
	cmpq	%rbx, %rbp
	jne	.L7
.L6:
	movq	stdout(%rip), %rsi
	movl	$10, %edi
	call	putc@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE12:
	.size	print_array, .-print_array
	.section	.rodata.str1.1
.LC1:
	.string	"copy_array(a + 1, a, n - 1):"
.LC2:
	.string	"copy_array(a, a + 1, n - 1):"
	.text
	.globl	main
	.type	main, @function
main:
.LFB13:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subq	$176, %rsp
	.cfi_def_cfa_offset 192
	movq	%fs:40, %rax
	movq	%rax, 168(%rsp)
	xorl	%eax, %eax
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	movq	$0, (%rsp)
	movq	$1, 8(%rsp)
	movq	$2, 16(%rsp)
	movq	$3, 24(%rsp)
	movq	$4, 32(%rsp)
	movq	$5, 40(%rsp)
	movq	$6, 48(%rsp)
	movq	$7, 56(%rsp)
	movq	$8, 64(%rsp)
	movq	$9, 72(%rsp)
	movq	%rsp, %rbx
	leaq	8(%rsp), %rdi
	movl	$9, %edx
	movq	%rbx, %rsi
	call	copy_array
	movl	$10, %esi
	movq	%rbx, %rdi
	call	print_array
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	movq	$0, 80(%rsp)
	movq	$1, 88(%rsp)
	movq	$2, 96(%rsp)
	movq	$3, 104(%rsp)
	movq	$4, 112(%rsp)
	movq	$5, 120(%rsp)
	movq	$6, 128(%rsp)
	movq	$7, 136(%rsp)
	movq	$8, 144(%rsp)
	movq	$9, 152(%rsp)
	leaq	80(%rsp), %rbx
	leaq	88(%rsp), %rsi
	movl	$9, %edx
	movq	%rbx, %rdi
	call	copy_array
	movl	$10, %esi
	movq	%rbx, %rdi
	call	print_array
	movq	168(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L13
	movl	$0, %eax
	addq	$176, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L13:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE13:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
