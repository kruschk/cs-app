void switcher(long a, long b, long c, long *dest) {
    long val;
    switch(a) {
        case 5: /* Case A */
            c = a ^ 15;
            /* Fall through */
        case 0: /* Case B */
            val = 112 + c;
            break;
        case 2: /* Case C */
        case 7: /* Case D */
            val = (a + c) << 2;
            break;
        case 4: /* Case E */
            //val = ; // This can't be right (?)
            break;
        default:
            val = a;
    }
    *dest = val;
}

/* Assembly code:
// Code
# void switcher(long a, long b, long c, long *dest)
# a in %rsi, b in %rdi, c in %rdx, dest in %rcx
switcher:
    cmpq    $7, %rdi            # Compare b:7 (should be a:7?)
    ja      .L2                 # Jump if >
    jmp     *.L4(,%rdi,8)       # Jump to jump_table[b] (should be a?)
    .section .rodata
.L7:
    xorq    $15, %rsi           # a <- a ^ 15
    movq    %rsi, %rdx          # c <- a
.L3:
    leaq    112(%rdx), %rdi     # b <- 112 + c
    jmp     .L6
.L5:
    leaq    (%rdx,%rsi), %rdi   # b <- c + a
    salq    $2, %rdi            # b <- b << 2
    jmp     .L6
.L2:
    movq    %rsi, %rdi          # b <- a
.L6:
    movq    %rdi, (%rcx)        # *dest <- b
    ret

// Jump table
.L4:
    .quad .L3   # case 0
    .quad .L2   # default
    .quad .L5   # case 2
    .quad .L2   # default
    .quad .L6   # case 4
    .quad .L7   # case 5
    .quad .L2   # default
    .quad .L5   # case 7
*/
