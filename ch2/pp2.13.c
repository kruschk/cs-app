#include <stdio.h>

// bis | 0 1
// ----+----
//   0 | 0 1
//   1 | 1 1
int bis(int x, int m) {
    return x | m;
}

// bic | 0 1
// ----+-----
//   0 | 0 0
//   1 | 1 0
int bic(int x, int m) {
    return x & ~m
}

//  or | 0 1
// ----+----
//   0 | 0 1
//   1 | 1 1
int bool_or(int x, int y) {
    return bis(x, y);
}

// xor | 0 1
// ----+----
//   0 | 0 1
//   1 | 1 0
// Holy crap, I got it right!
int bool_xor(int x, int y) {
    return bis(bic(x, y), bic(y, x));
}
