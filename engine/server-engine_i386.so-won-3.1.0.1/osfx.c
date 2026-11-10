// osfx__7ostream  @ 00046850
void osfx__7ostream(int *param_1)

{
  int iVar1;
  
  _IO_funlockfile(*(_IO_FILE **)*param_1);
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if ((*(byte *)(iVar1 + 0xd) & 0x60) != 0) {
    do_osfx__7ostream(param_1);
  }
  return;
}


