long loop_while2(long a, long b) {
    long result = b;
    while (b > 0) {
        result = result*a;
        b = b - a;
    }
    return result;
}

# a in %rdi, b in %rsi
loop_while2:
    testq   %rsi, %rsi # b & b
    jle     .L8        # jump if <= 0
    movq    %rsi, %rax # result <- b
.L7:
    imulq   %rdi, %rax # result <- result*a
    subq    %rdi, %rsi # b <- b - a
    testq   %rsi, %rsi # b & b
    jg      .L7        # jump if b > 0
    rep; ret
.L8:
    movq    %rsi, %rax # result <- b
    ret
