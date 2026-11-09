// BarnacleVictimReleased__11CBasePlayer  @ 000df660
void BarnacleVictimReleased__11CBasePlayer(int param_1)

{
  *(byte *)(param_1 + 0x668) = *(byte *)(param_1 + 0x668) & 0xfb;
  return;
}


// BarnacleVictimReleased__12CBaseMonster  @ 000c1030
void BarnacleVictimReleased__12CBaseMonster(int *param_1)

{
  int iVar1;
  
  param_1[0x13b] = 1;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x24) = DAT_00175484;
  *(undefined4 *)(iVar1 + 0x28) = DAT_00175488;
  *(undefined4 *)(*param_1 + 0xe8) = 4;
  return;
}


