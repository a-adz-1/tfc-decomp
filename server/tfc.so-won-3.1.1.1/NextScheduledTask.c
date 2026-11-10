// NextScheduledTask__12CBaseMonster  @ 000e90cc
void NextScheduledTask__12CBaseMonster(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x57c) = 0;
  iVar1 = *(int *)(param_1 + 0x584) + 1;
  *(int *)(param_1 + 0x584) = iVar1;
  if (iVar1 == *(int *)(*(int *)(param_1 + 0x580) + 4)) {
    *(byte *)(param_1 + 0x4fb) = *(byte *)(param_1 + 0x4fb) | 0x80;
  }
  return;
}


