word d_dstE = [
    D_icode in { IRRMOVQ } : rB;
    D_icode in { IIRMOVQ, IOPQ } : rB;
    D_icode in { IPUSHQ, IPOPQ, ICALL, IRET } : RRSP;
    1 : RNONE;
];
