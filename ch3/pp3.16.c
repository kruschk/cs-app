/*
A.
void cond(short a, short *p) {
    if (a && *p < a) {
        *p = a;
    }
}
*/

void cond(short a, short *p) {
    if (0 == a) {
        goto end;
    }
    if (*p >= a) {
        goto end;
    }
    *p = a;
end:
    return;
}

/*
B.
To implement `&&`, the machine must test both subexpressions separately.
Only if each subexpression is true will the consequent block be evaluated.
*/
