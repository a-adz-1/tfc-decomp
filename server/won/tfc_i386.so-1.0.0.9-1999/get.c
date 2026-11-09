// get_reg  @ 0011fab8
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 get_reg(int param_1,int *param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = *(char *)(param_1 + 0x5c + (int)param_2);
  if (cVar1 == '\x01') {
    uVar2 = *(undefined4 *)(param_2[param_1 + 4] + *param_2);
  }
  else {
    if ((cVar1 != '\x02') || (param_3 == 0)) {
                    /* WARNING: Subroutine does not return */
      abort();
    }
    uVar2 = get_reg(param_2[param_1 + 4],param_3,0);
  }
  return uVar2;
}


