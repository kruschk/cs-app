#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint32_t x = 0x87654321;

    // A.
    uint32_t a = x & 0xFF;

    // B.
    uint32_t b = (~(x & ~0xFF) & ~0xFF) | (x & 0xFF);
    // Solution (duh!):
    b = x ^ ~0xFF;

    // C.
    uint32_t c = (x & ~0xFF) | (x | 0xFF);
    // Solution:
    c = x | 0xFF;

    printf("A: 0x%X\nB: 0x%X\nC: 0x%X\n", a, b, c);
}
