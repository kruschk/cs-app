#include <stdint.h>
#include <stdio.h>

int tmult_ok_int(int x, int y) {
    int p = x*y;
    return !x || p/x == y;
}

long fact_do(long n) {
    long result = 1;
    do {
        result *= n;
        n = n-1;
    } while (n > 1);
    return result;
}

int main(void) {
    // A. Overflow occurs
    for (long i = 1; i < 15; i++) {
        printf("%d\n", fact_do(i));
    }
    // B. Overflow does not occur
    for (long i = 1; i < 15; i++) {
        printf("%ld\n", fact_do(i));
    }
    return 0;
}
