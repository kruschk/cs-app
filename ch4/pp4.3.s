## Original:
## long sum(long *start, long count)
## start in %rdi, count in %rsi
#sum:
#    irmovq  $8,%r8      # Constant 8
#    irmovq  $1,%r9      # Constant 1
#    xorq    %rax,%rax   # sum = 0
#    andq    %rsi,%rsi   # Set CC
#    jmp     test        # Goto test
#loop:
#    mrmovq  (%rdi),%r10 # Get *start
#    addq	%r10,%rax   # Add to sum
#    addq	%r8,%rdi    # start++
#    subq	%r9,%rsi    # count--. Set CC
#test:
#    jne loop            # Stop when 0
#    ret                 # Return

# Revised:
# long sum(long *start, long count)
# start in %rdi, count in %rsi
sum:
    xorq    %rax,%rax   # sum = 0
    andq    %rsi,%rsi   # Set CC
    jmp     test        # Goto test
loop:
    mrmovq  (%rdi),%r10 # Get *start
    addq	%r10,%rax   # Add to sum
    iaddq	$8,%rdi     # start++
    iaddq   $-1,%rsi    # count--. Set CC
test:
    jne loop            # Stop when 0
    ret                 # Return
