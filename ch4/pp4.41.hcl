bool set_cc = E_icode == IOPQ
              && !(m_stat in { SADR, SINS, SHLT }
                   || W_stat in { SADR, SINS, SHLT });
            = E_icode == IOPQ
              && !m_stat in { SADR, SINS, SHLT }
              && !W_stat in { SADR, SINS, SHLT };
