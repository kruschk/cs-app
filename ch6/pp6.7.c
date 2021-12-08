// To improve the spacial locality of this procedure, simply change the array
// indexing order such that the least-frequently changing index is the leftmost
// and the most-frequently changing index is the rightmost. This results in the
// elements being accessed in the same order that they are arranged in memory.
int productarray3d(int a[N][N][N]) {
    int i, j, k, product = 1;
    for (i = N-1; i >= 0; i--) {
        for (j = N-1; j >= 0; j--) {
            for (k = N-1; k >= 0; k--) {
                product *= a[i][j][k]; // Changed
            }
        }
    }
}
