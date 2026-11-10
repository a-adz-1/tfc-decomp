// HasWeapons__11CBasePlayer  @ 000dd280
undefined4 HasWeapons__11CBasePlayer(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(int *)(param_1 + 0x818 + iVar1 * 4) != 0) {
      return 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  return 0;
}


