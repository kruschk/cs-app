/* Swap value x at xp with value y at yp */
void swap(long *xp, long *yp)
{
    // Given: xp = yp
    *xp = *xp + *yp; // *xp <- *xp + *xp = x + x = 2*x
    *yp = *xp - *yp; // *xp <- *xp - *xp = 2*x - 2*x = 0
    *xp = *xp - *yp; // *xp <- *xp - *xp = 0 - 0 = 0
}

// We can conclude that, if the pointers xp and yp are aliases (i.e., xp = yp),
// this procedure would effectively clear the value at the given memory
// location.
