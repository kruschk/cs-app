/* Determine whether arguments can be added without overflow */
int tadd_ok(const int x, const int y) {
    const int sum = x + y;
    const int negative_overflow = x < 0 && y < 0 && 0 <= sum;
    const int positive_overflow = 0 < x && 0 < y && sum <= 0;
    // Alternatively (from the book):
    //const int positive_overflow = 0 <= x && 0 <= y && sum < 0;
    return !(negative_overflow || positive_overflow);
    // Alternatively (from the book):
    //return !negative_overflow && !positive_overflow;
}
