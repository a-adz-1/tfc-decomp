// IAllocSound__9CSoundEnt  @ 000ee1e0
int IAllocSound__9CSoundEnt(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x3cc) == -1) {
    (*DAT_001755b4)(1,"Free Sound List is full!\n");
    iVar1 = -1;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x3cc);
    *(undefined4 *)(param_1 + 0x3cc) = *(undefined4 *)(iVar1 * 0x20 + param_1 + 0x3f4);
    *(undefined4 *)(iVar1 * 0x20 + param_1 + 0x3f4) = *(undefined4 *)(param_1 + 0x3d0);
    *(int *)(param_1 + 0x3d0) = iVar1;
  }
  return iVar1;
}


