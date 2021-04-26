short loop_while(short a, short b) {
    short result = 0;
    while (a > b) {
        result += a*b;
        a = a - 1;
    }
    return result;
}

/*
# short loop_while(short a, short b)
# a in %rdi, b in %rsi
loop_while:
    movl $0, %eax           # result <- 0
    jmp .L2                 # jump to middle
.L3:
    leaq (,%rsi,%rdi), %rdx # t <- a*b
    addq %rdx, %rax         # result <- result + t
    subq $1, %rdi           # a <- a - 1
.L2:
    cmpq %rsi, %rdi         # compare a:b
    jg .L3                  # jump if >
    rep; ret
*/
