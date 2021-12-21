static void place(void *bp, size_t asize) {
    size_t remaining_free_size = GET_SIZE(HDRP(p)) - asize;
    PUT(HDRP(bp), PACK(asize, 1)); // Allocate
    PUT(FTRP(bp), PACK(asize, 1));
    if (2*DSIZE <= remaining_free_size) { // Split
        bp = NEXT_BLKP(bp);
        PUT(HDRP(bp), PACK(remaining_free_size, 0));
        PUT(FTRP(bp), PACK(remaining_free_size, 0));
    }
}
