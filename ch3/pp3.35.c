/*
 * A.
 * x is stored in the callee-store register %rbx.
 */

// B.
long rfun(unsigned long x) {
    if (!x) {
        return 0;
    }
    unsigned long nx = x >> 2;
    long rv = rfun(nx);
    return rv + x;
}

// Written a little more concisely:
long rfun(unsigned long x) {
    if (!x) {
        return 0;
    } else {
        return x + rfun(x >> 2);
    }
}

/*
 * # long rfun(unsigned long x)
 * # x in %rdi
 * rfun:
 *     pushq   %rbx         # save old b so we can use %rbx (callee-saved)
 *     movq    %rdi, %rbx   # b <- x
 *     movl    $0, %eax     # a <- 0
 *     testq   %rdi, %rdi   # x & x
 *     je      .L2          # jump if == 0
 *     shrq    $2, %rdi     # d <- x >> 2
 *     call    rfun         # rfun(d)
 *     addq    %rbx, %rax   # a <- a + b
 * .L2:
 *     popq    %rbx
 *     ret
 */
