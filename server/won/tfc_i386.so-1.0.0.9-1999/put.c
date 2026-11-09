// put_reg  @ 0011fb1c
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void put_reg(int param_1,undefined4 param_2,int *param_3)

{
  if (*(char *)(param_1 + 0x5c + (int)param_3) == '\x01') {
    *(undefined4 *)(param_3[param_1 + 4] + *param_3) = param_2;
    return;
  }
                    /* WARNING: Subroutine does not return */
  abort();
}


