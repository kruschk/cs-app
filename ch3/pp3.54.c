double funct2(double w, int x, float y, long z) {
    return x*y - w/z
}

/*
# double funct2(double w, int x, float y, long z)
# w in %xmm0, x in %edi, y in %xmm1, z in %rsi
funct2:
    vcvtsi2ss   %edi, %xmm2, %xmm2  # xmm2 <- x
    vmulss      %xmm1, %xmm2, %xmm1 # xmm1 <- xmm2*xmm1 = x*y
    vunpcklps   %xmm1, %xmm1, %xmm1 #
    vcvtps2pd   %xmm1, %xmm2        # xmm2 <- xmm1 = x*y
    vcvtsi2sdq  %rsi, %xmm1, %xmm1  # xmm1 <- z
    vdivsd      %xmm1, %xmm0, %xmm0 # xmm0 <- xmm0/xmm1 = w/z
    vsubsd      %xmm0, %xmm2, %xmm0 # xmm0 <- xmm2 - xmm0 = x*y - w/z
    ret
*/
