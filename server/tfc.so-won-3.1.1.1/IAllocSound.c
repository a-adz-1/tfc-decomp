// IAllocSound__9CSoundEnt  @ 000f30a4
int IAllocSound__9CSoundEnt(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x458);
  if (iVar1 == -1) {
    (*DAT_0019f794)(1,"Free Sound List is full!\n");
  }
  else {
    *(undefined4 *)(param_1 + 0x458) = *(undefined4 *)(iVar1 * 0x20 + param_1 + 0x480);
    *(undefined4 *)(iVar1 * 0x20 + param_1 + 0x480) = *(undefined4 *)(param_1 + 0x45c);
    *(int *)(param_1 + 0x45c) = iVar1;
  }
  return iVar1;
}


