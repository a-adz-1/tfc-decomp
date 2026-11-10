// ShouldFadeOnDeath__11CBasePlayer  @ 000d8c84
undefined4 ShouldFadeOnDeath__11CBasePlayer(void)

{
  return 0;
}


// ShouldFadeOnDeath__12CBaseMonster  @ 000b737c
undefined4 ShouldFadeOnDeath__12CBaseMonster(int *param_1)

{
  bool bVar1;
  int iVar2;
  
  if ((*(byte *)(*param_1 + 0x1a1) & 2) == 0) {
    iVar2 = *(int *)(*param_1 + 0x198);
    bVar1 = false;
    if ((iVar2 == 0) || (iVar2 = (*DAT_001a7f58)(iVar2), iVar2 == 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      return 0;
    }
  }
  return 1;
}


