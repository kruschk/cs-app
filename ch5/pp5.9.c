void merge(long src1[], long src2[], long dest[], long n) {
    long i1 = 0;
    long i2 = 0;
    long id = 0;
    while (i1 < n && i2 < n) {
        int condition = src1[i1] < src2[i2];
        dest[id] = condition ? src1[i1] : src2[i2];
        i1 = condition ? i1 + 1 : i1;
        i2 = condition ? i2 : i2 + 1;
        id++;
    }
    while (i1 < n)
        dest[id++] = src1[i1++];
    while (i2 < n)
        dest[id++] = src2[i2++];
}
