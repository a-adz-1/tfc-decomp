// BarnacleVictimReleased__11CBasePlayer  @ 000d316c
void BarnacleVictimReleased__11CBasePlayer(int param_1)

{
  *(byte *)(param_1 + 0x678) = *(byte *)(param_1 + 0x678) & 0xfb;
  return;
}


// BarnacleVictimReleased__12CBaseMonster  @ 000aead4
void BarnacleVictimReleased__12CBaseMonster(int *param_1)

{
  int iVar1;
  
  param_1[0x13e] = 1;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x24) = DAT_001a7e04;
  *(undefined4 *)(iVar1 + 0x28) = DAT_001a7e08;
  *(undefined4 *)(*param_1 + 0x108) = 4;
  return;
}


