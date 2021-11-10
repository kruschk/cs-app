.text
.globl poptest
poptest:
    movq %rsp, %rdi # rdi <- rsp0
    pushq $0xabcd   # rsp1 <- rsp0 - 8
                    # M[rsp1] <- 0xabcd
    popq %rsp       # rsp2 <- M[rsp1]
                    # rsp2 <- rsp1 + 8
    movq %rsp, %rax # rax <- rsp
    movq %rdi, %rsp # rsp <- rdi
    ret

# Since the function always returns 0xabcd, we can deduce that `popq %rsp`
# obeys the convention of assigning the value read from memory to register
# %rsp. A clearer way to achieve the same thing is with the instruction
# `movq (%rsp), %rsp` (or `mrmovq (%rsp), %rsp` in Y86-64).
