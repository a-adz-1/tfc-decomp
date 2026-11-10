// BarnacleVictimReleased__11CBasePlayer  @ 000de870
void BarnacleVictimReleased__11CBasePlayer(int param_1)

{
  *(byte *)(param_1 + 0x6e8) = *(byte *)(param_1 + 0x6e8) & 0xfb;
  return;
}


// BarnacleVictimReleased__12CBaseMonster  @ 000b9d34
void BarnacleVictimReleased__12CBaseMonster(int *param_1)

{
  int iVar1;
  
  param_1[0x15a] = 1;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x24) = DAT_001c0fe4;
  *(undefined4 *)(iVar1 + 0x28) = DAT_001c0fe8;
  *(undefined4 *)(*param_1 + 0x108) = 4;
  return;
}


