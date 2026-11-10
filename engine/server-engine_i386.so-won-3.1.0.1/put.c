// put__7ostreamSc  @ 000467f0
undefined4 * put__7ostreamSc(undefined4 *param_1,char param_2)

{
  _IO_putc((int)param_2,*(_IO_FILE **)*param_1);
  return param_1;
}


// put__7ostreamUc  @ 00046810
undefined4 * put__7ostreamUc(undefined4 *param_1,char param_2)

{
  _IO_putc((int)param_2,*(_IO_FILE **)*param_1);
  return param_1;
}


// put__7ostreamc  @ 00046830
undefined4 * put__7ostreamc(undefined4 *param_1,char param_2)

{
  _IO_putc((int)param_2,*(_IO_FILE **)*param_1);
  return param_1;
}


// put_reg  @ 000a05c0
void put_reg(int param_1,undefined4 param_2,int *param_3)

{
  if (*(char *)(param_1 + 0x5c + (int)param_3) == '\x01') {
    *(undefined4 *)(param_3[param_1 + 4] + *param_3) = param_2;
    return;
  }
                    /* WARNING: Subroutine does not return */
  abort();
}


