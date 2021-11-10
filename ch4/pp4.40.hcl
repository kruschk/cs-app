bool E_bubble = (E_icode in { IMRMOVQ, IPOPQ }
                  && E_dstM in { d_srcA, d_srcB }) // load/use hazard
                || (E_icode == IJXX && !e_Cnd); // mispredicted branch
