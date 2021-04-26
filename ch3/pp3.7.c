short scale3(short x, short y, short z) {
    short t = 10*y + z + x*y;
    return t;
}

/*
scale3:
    # x in %rdi, y in %rsi, z in %rdx
    leaq (%rsi,%rsi,9), %rbx    # b = 10*y
    leaq (%rbx,%rdx), %rbx      # b = b + z
                                #   = 10*y + z
    leaq (%rbx,%rdi,%rsi), %rbx # b = b + x*y
                                #   = (10*y + z) + x*y
                                #   = 10y + z + x*y
    ret
*/
