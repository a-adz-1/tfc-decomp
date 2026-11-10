// BarnacleVictimReleased__11CBasePlayer  @ 000e525c
void BarnacleVictimReleased__11CBasePlayer(int param_1)

{
  *(byte *)(param_1 + 0x70c) = *(byte *)(param_1 + 0x70c) & 0xfb;
  return;
}


// BarnacleVictimReleased__12CBaseMonster  @ 000c2c7c
void BarnacleVictimReleased__12CBaseMonster(int *param_1)

{
  int iVar1;
  
  param_1[0x15e] = 1;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x24) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 0x28) = DAT_0019f668;
  *(undefined4 *)(*param_1 + 0x108) = 4;
  return;
}


