// NextScheduledTask__12CBaseMonster  @ 000d96b4
void NextScheduledTask__12CBaseMonster(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x4fc) = 0;
  *(int *)(param_1 + 0x504) = *(int *)(param_1 + 0x504) + 1;
  iVar1 = FScheduleDone__12CBaseMonster(param_1);
  if (iVar1 != 0) {
    *(byte *)(param_1 + 0x47b) = *(byte *)(param_1 + 0x47b) | 0x80;
  }
  return;
}


