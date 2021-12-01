/* 5 x 1 loop unrolling */
void combine5(vec_ptr v, data_t *dest)
{
    long i;
    long k = 5;
    long length = vec_length(v);
    long limit = length - k + 1;
    data_t *data = get_vec_start(v);
    data_t acc = IDENT;
    /* Combine 5 elements at a time */
    for (i = 0; i < limit; i += k) {
        acc = acc OP data[i];
        acc = acc OP data[i+1];
        acc = acc OP data[i+2];
        acc = acc OP data[i+3];
        acc = acc OP data[i+4];
    }
    /* Finish any remaining elements */
    for (; i < length; i++) {
        acc = acc OP data[i];
    }
    *dest = acc;
}
