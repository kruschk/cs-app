// Search for a free block that is at least as large as asize using a first-fit
// algorithm.
static void *find_fit(size_t asize) {
    char *bp = heap_listp;
    do { // The prologue block is guaranteed to exist, so a do-while works.
        char *hdr = HDRP(bp);
        if (!GET_ALLOC(hdr) && asize <= GET_SIZE(hdr)) {
            return bp;
        }
        bp = NEXT_BLKP(bp);
    } while (0 != size); // The epilogue block is the only zero-sized block.
    return NULL;
}

// Alternatively...
static void *find_fit(size_t asize) {
    for (char *bp = NEXT_BLKP(heap_listp);
         0 != GET_SIZE(HDRP(bp));
         bp = NEXT_BLKP(bp))
    {
        if (!GET_ALLOC(HDRP(bp)) && asize <= GET_SIZE(HDRP(bp))) {
            return bp;
        }
    }
    return NULL;
}
