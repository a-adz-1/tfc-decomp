// copy_reg  @ 0011fb64
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void copy_reg(int param_1,int *param_2,int *param_3)

{
  size_t __n;
  
  if ((*(char *)(param_1 + 0x5c + (int)param_2) == '\x01') &&
     (*(char *)(param_1 + 0x5c + (int)param_3) == '\x01')) {
    __n = 4;
    if (param_1 - 0xbU < 8) {
      __n = 0xc;
    }
    memcpy((void *)(*param_3 + param_3[param_1 + 4]),(void *)(*param_2 + param_2[param_1 + 4]),__n);
    return;
  }
                    /* WARNING: Subroutine does not return */
  abort();
}


