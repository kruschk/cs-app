bool D_stall = (E_icode in { IMRMOVQ, IPOPQ }
                  && E_dstM in { d_srcA, d_srcB }) // load/use hazard
               || (E_icode in { IMRMOVQ, IPOPQ }
                     && E_dstM in { d_srcA, d_srcB } // load/use hazard
                     && IRET in { d_icode, E_icode, M_icode }) // processing ret
             = E_icode in { IMRMOVQ, IPOPQ }
                 && E_dstM in { d_srcA, d_srcB } // load/use hazard
