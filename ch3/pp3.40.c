#define N 16

typedef int fix_matrix[N][N];

void fix_set_diag_opt(fix_matrix A, int val) {
    long i = 0;
    int *A_ptr = &A[0][0];
    int *A_end = A_ptr + N*(N + 1);
    do {
        *A_ptr = val;
        A_ptr += N + 1;
    } while (A_ptr != A_end);
}
