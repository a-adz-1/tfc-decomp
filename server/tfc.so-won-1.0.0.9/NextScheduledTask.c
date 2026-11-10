// NextScheduledTask__12CBaseMonster  @ 000e4c70
void NextScheduledTask__12CBaseMonster(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x4f0) = 0;
  *(int *)(param_1 + 0x4f8) = *(int *)(param_1 + 0x4f8) + 1;
  iVar1 = FScheduleDone__12CBaseMonster(param_1);
  if (iVar1 != 0) {
    *(byte *)(param_1 + 0x46f) = *(byte *)(param_1 + 0x46f) | 0x80;
  }
  return;
}


