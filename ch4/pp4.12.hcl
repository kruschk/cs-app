word Median3 = [
    (B <= A && A <= C) || (C <= A && A <= B) : A; # A is the median
    (A <= B && B <= C) || (C <= B && B <= A) : A; # B is the median
    1                                        : C; # C is the median
]
