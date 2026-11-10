// IAllocSound__9CSoundEnt  @ 000e40ec
int IAllocSound__9CSoundEnt(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x3d8) == -1) {
    (*DAT_001a7f34)(1,"Free Sound List is full!\n");
    iVar1 = -1;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x3d8);
    *(undefined4 *)(param_1 + 0x3d8) = *(undefined4 *)(iVar1 * 0x20 + param_1 + 0x400);
    *(undefined4 *)(iVar1 * 0x20 + param_1 + 0x400) = *(undefined4 *)(param_1 + 0x3dc);
    *(int *)(param_1 + 0x3dc) = iVar1;
  }
  return iVar1;
}


