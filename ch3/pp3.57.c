double funct3(int *ap, double b, long c, float *dp) {
    if (b <= *ap) {
        return c + 2*(*dp)
    } else {
        return c*(*dp)
    }
}

/*
# double funct3(int *ap, double b, long c, float *dp)
# ap in %rdi, b in %xmm0, c in %rsi, dp in %rdx
funct3:
    vmovss      (%rdx), %xmm1           # xmm1 <- *dp
    vcvtsi2sd   (%rdi), %xmm2, %xmm2    # xmm2 <- (double) *ap
    vucomisd    %xmm2, %xmm0            # Compare b:*ap
    jbe         .L8                     # Jump if <=
    vcvtsi2ssq  %rsi, %xmm0, %xmm0      # xmm0 <- (float) c
    vmulss      %xmm1, %xmm0, %xmm1     # xmm1 <- xmm0*xmm1 = (float)c*(*dp)
    vunpcklps	%xmm1, %xmm1, %xmm1
    vcvtps2pd	%xmm1, %xmm0            # xmm0 <- (double) xmm1 = (double)((float)c*(*dp))
    ret
.L8:
    vaddss      %xmm1, %xmm1, %xmm1     # xmm1 <- xmm1 + xmm1 = 2*(*dp)
    vcvtsi2ssq  %rsi, %xmm0, %xmm0      # xmm0 <- (float) c
    vaddss      %xmm1, %xmm0, %xmm0     # xmm0 <- xmm0 + xmm1 = (float)c + 2*(*dp)
    vunpcklps   %xmm0, %xmm0, %xmm0
    vcvtps2pd   %xmm0, %xmm0            # xmm0 <- (double) xmm0 = (double)((float)c + 2*(*dp))
    ret
