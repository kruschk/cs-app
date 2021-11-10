.text
.globl pushtest
pushtest:
    movq %rsp, %rax # rax <- rsp0
    pushq %rsp      # rsp1 <- rsp0 - 8
                    # M[rsp1] <- rsp?
    popq %rdx       # rdx <- M[rsp1]
                    # rsp2 <- rsp1 + 8
    subq %rdx, %rax # rax <- rax - rdx = rsp0 - rsp?
    ret

# Since this function always returns 0, it is implied that %rdx contains the
# original value of %rsp. This means the ISA follows the convention of pushing
# the original value of %rsp onto the stack.
