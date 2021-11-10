word Stat = [
    dmem_error || imem_error : SADR;
    IHALT == icode : SHLT
    !instr_valid : SINS;
    1 : SAOK
];
