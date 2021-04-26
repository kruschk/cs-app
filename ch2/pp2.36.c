// The result of any 32 bit multiplication, two's complement or unsigned,
// can be represented by a 2w = 2*32 = 64 bit word. Therefore, we can simply
// expand the 32 bit operands to 64 bits, perform the multiplication, and
// store that as the correct result. Then we can check whether truncating
// that value and expanding it again is the same as our correct result. If
// it is, then no overflow will occur. If not, overflow will occur.
int tmult_ok(int32_t x, int32_t y) {
    int64_t result = (int64_t) x*y;
    return result == (int32_t) result;
}
