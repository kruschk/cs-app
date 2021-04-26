A.
This implementation uses the jump-to-middle technique.

B.
short test_one(unsigned short x) {
    short val = 1;
    while (x != 0) {
        val = val ^ x;
        x = x >> 1;
    }
    return val & 1;
}

# short test_one(unsigned short x)
# x in %rdi
test_one:
    movl    $1, %eax    # a <- 1
    jmp     .L5
.L6:
    xorq    %rdi, %rax  # a <- a ^ x
    shrq    %rdi        # logical-shift-right by 1
.L5:
    testq   %rdi, %rdi  # x & x
    jne     .L6         # jump if != 0
    andl    $0, %eax    # a <- a & 0 (should be 1???)
    ret

C.
Consider:
x      ^ val    = 
-------+--------+-------
[1101] ^ [0001] = [1100]
[0110] ^ [1100] = [1010]
[0011] ^ [1010] = [1001]
[0001] ^ [1001] = [1000]
then, [0001] & [1000] = 0.

This function computes the parity of the given argument. If there are an odd
number of bits set, it returns 0, and 1 for an even number of bits.
