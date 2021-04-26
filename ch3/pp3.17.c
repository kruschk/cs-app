// A.

long gotodiff_se_alt(long x, long y) {
    long result;
    if (x < y) {
        goto x_lt_y;
    }
    ge_cnt++;
    result = x - y;
    return result;
x_lt_y:
    lt_cnt++;
    result = y - x;
    return result;
}

/*
 * B.
 * Assuming a jump instruction is relatively expensive, this form allows the
 * false clause to be executed with one less jump than the true clause. If the
 * false condition is expected to occur more frequently than the true one,
 * this could result in faster code.
 */
