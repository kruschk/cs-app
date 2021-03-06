#long rproduct(long *start, long count) {
#    if (count <= 1) {
#        return 1;
#    }
#    return *start * rproduct(start+1, count-1);
#}

# Generated by GCC:
	.file	"pp4.4.c"
	.text
	.globl	rproduct
	.type	rproduct, @function
rproduct:
.LFB0:
	.cfi_startproc
	cmpq	$1, %rsi
	jle	.L3
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	(%rdi), %rbx
	subq	$1, %rsi
	addq	$8, %rdi
	call	rproduct
	imulq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L3:
	.cfi_restore 3
	movl	$1, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	rproduct, .-rproduct
	.ident	"GCC: (Debian 8.3.0-6) 8.3.0"
	.section	.note.GNU-stack,"",@progbits

# Trimmed and annotated:
# long rproduct(long *start, long count)
# start in %rdi, count in %rsi
rproduct:
	cmpq	$1, %rsi        #     Compare 1:rsi
	jle     .L3             #     If <=, go to L3 (end)
	pushq	%rbx            #     Save rbx
	movq	(%rdi), %rbx    #     rbx <- M[rdi]
	subq	$1, %rsi        #     rsi <- rsi - 1
	addq	$8, %rdi        #     rdi <- rdi + 8
	call	rproduct        #     Call rproduct
	imulq	%rbx, %rax      #     rax <- rax*rbx
	popq	%rbx            #     Restore rbx
	ret                     #     Return to caller
.L3:                        # end:
	movl	$1, %eax        #     rax <- 1
	ret                     #     Return to caller

# Converted to Y86-64:
# long rproduct(long *start, long count)
# start in %rdi, count in %rsi
rproduct:
    irmovq  $1, %r8         #     r8 <- 1
    irmovq  $8, %r9         #     r9 <- 8
    rrmovq  %rsi, %r10      #     r10 <- rsi = count
    subq    %r8, %r10       #     r10 <- r10 - r8 = rsi - 1 = count - 1
	jle     .L3             #     If <=, go to L3 (end)
	pushq	%rbx            #     Save rbx
	mrmovq	(%rdi), %rbx    #     rbx <- M[rdi] = *start
	subq	%r8, %rsi       #     rsi <- rsi - r8 = count - 1 (argument 2)
	addq	%r9, %rdi       #     rdi <- rdi + r9 = start + 8 (argument 1)
	call	rproduct        #     Call rproduct (sets rax)
	mulq	%rbx, %rax      #     rax <- rax*rbx = *start * rproduct(start + 8, count - 1)
                            # The book is wrong here; Y86-64 doesn't support multiplication.
	popq	%rbx            #     Restore rbx
	ret                     #     Return to caller
.L3:                        # end:
	irmovq	$1, %rax        #     rax <- 1
	ret                     #     Return to caller
