word Min3 = [
    A <= B && A <= C : A; # A is the min
    B <= C           : B; # We know A is not the minimum, so we discard it
                          # and compare B to C
    1                : C;
]
