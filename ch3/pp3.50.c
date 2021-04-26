double fcvt2(int *ip, float *fp, double *dp, long l) {
    int i = *ip; float f = *fp; double d = *dp;
    *ip = (int) d;
    *fp = (float) i;
    *dp = (double) l;
    return (double) f;
}

/*
// double fcvt2(int *ip, float *fp, double *dp, long l)
// ip in %rdi, fp in %rsi, dp in %rdx, l in %rcx
// Result returned in %xmm0
fcvt2:
    movl        (%rdi), %eax        // eax <- *ip
    vmovss      (%rsi), %xmm0       // xmm0 <- *fp
    vcvttsd2si  (%rdx), %r8d        // r8d <- (int) *dp
    movl        %r8d, (%rdi)        // *ip <- r8d
    vcvtsi2ss   %eax, %xmm1, %xmm1  // xmm1 <- (float) eax
    vmovss      %xmm1, (%rsi)       // *fp <- xmm1
    vcvtsi2sdq  %rcx, %xmm1, %xmm1  // xmm1 <- (double) l
    vmovsd      %xmm1, (%rdx)       // *dp <- xmm1
    vunpcklps   %xmm0, %xmm0, %xmm0 // xmm0 <- 
    vcvtps2pd   %xmm0, %xmm0        // xmm0 <- (double) xmm0
    ret
*/
