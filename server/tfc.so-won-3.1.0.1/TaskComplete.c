// TaskComplete__12CBaseMonster  @ 000b7630
void TaskComplete__12CBaseMonster(int param_1)

{
  int iVar1;
  
  iVar1 = HasConditions__12CBaseMonsteri(param_1,0x40000000);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x4fc) = 4;
  }
  return;
}


