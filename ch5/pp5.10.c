#include <stdio.h>

void copy_array(long *src, long *dest, long n) {
    long i;
    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void print_array(long *arr, long n) {
    for (long i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

int main(void) {
    long n = 10;

    printf("copy_array(a + 1, a, n - 1):\n");
    long a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };
    copy_array(a + 1, a, n - 1);
    print_array(a, n);

    printf("copy_array(a, a + 1, n - 1):\n");
    long b[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };
    copy_array(b, b + 1, n - 1);
    print_array(b, n);
}
