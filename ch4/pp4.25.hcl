word mem_addr = [
    icode in { IRMMOVQ, IPUSHQ, ICALL, IMRMOVQ } : valE;
    icode in { IPOPQ, IRET } : valA;
    # Other instructions don’t need address
];

word mem_data = [
    icode in { IRMMOVQ, IPUSHQ, } : valA
    icode in { ICALL, } : valP
    # Other instructions don’t write data
];
