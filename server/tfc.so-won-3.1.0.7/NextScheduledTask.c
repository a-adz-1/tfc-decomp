// NextScheduledTask__12CBaseMonster  @ 000e5750
void NextScheduledTask__12CBaseMonster(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x56c) = 0;
  *(int *)(param_1 + 0x574) = *(int *)(param_1 + 0x574) + 1;
  iVar1 = FScheduleDone__12CBaseMonster(param_1);
  if (iVar1 != 0) {
    *(byte *)(param_1 + 0x4eb) = *(byte *)(param_1 + 0x4eb) | 0x80;
  }
  return;
}


