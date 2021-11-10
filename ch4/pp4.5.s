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
    irmovq  $8,%r8      # Constant 8
    irmovq  $1,%r9      # Constant 1
    xorq    %rax,%rax   # sum = 0
    andq    %rsi,%rsi   # Set CC
    jmp     test        # Goto test
loop:
    mrmovq  (%rdi),%r10 # Get *start
    andq    %r10,%r10   # Set CC
    jl      neg         # If <, go to neg
    addq	%r10,%rax   # rax <- rax + r10
    jmp     continue    # Continue
neg:
    subq    %r10,%rax   # rax <- rax - r10
continue:
    addq	%r8,%rdi    # start++
    subq	%r9,%rsi    # count--. Set CC
test:
    jne loop            # Stop when 0
    ret                 # Return

# I believe this will work, but the book's implementation is cleverer.
