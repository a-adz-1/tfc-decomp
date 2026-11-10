// IAllocSound__9CSoundEnt  @ 000f0b88
int IAllocSound__9CSoundEnt(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x448) == -1) {
    (*DAT_001c1114)(1,"Free Sound List is full!\n");
    iVar1 = -1;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x448);
    *(undefined4 *)(param_1 + 0x448) = *(undefined4 *)(iVar1 * 0x20 + param_1 + 0x470);
    *(undefined4 *)(iVar1 * 0x20 + param_1 + 0x470) = *(undefined4 *)(param_1 + 0x44c);
    *(int *)(param_1 + 0x44c) = iVar1;
  }
  return iVar1;
}


