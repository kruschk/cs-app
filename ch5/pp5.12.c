/* Compute prefix sum of vector a */
void psum1(float a[], float p[], long n) {
    long i;
    float acc = a[0];
    p[0] = acc;
    for (i = 1; i < n; i++) {
        acc += a[i];
        p[i] = acc;
    }
}
