// IsEmpty__10CWeaponBox  @ 0011c8c0
undefined4 IsEmpty__10CWeaponBox(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(int *)(param_1 + 0x3cc + iVar1 * 4) != 0) {
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  iVar1 = 0;
  do {
    if (*(int *)(param_1 + 0x3ec + iVar1 * 4) != 0) {
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  return 1;
}


// IsEmpty__9CSoundEnt  @ 000ee550
bool IsEmpty__9CSoundEnt(int param_1)

{
  return *(int *)(param_1 + 0x3d0) == -1;
}


