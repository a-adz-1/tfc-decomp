// put_reg  @ 00136fb0
void put_reg(int param_1,undefined4 param_2,int *param_3)

{
  if (*(char *)(param_1 + 0x5c + (int)param_3) == '\x01') {
    *(undefined4 *)(param_3[param_1 + 4] + *param_3) = param_2;
    return;
  }
                    /* WARNING: Subroutine does not return */
  abort();
}


