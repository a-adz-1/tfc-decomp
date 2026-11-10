// IsEmpty__10CWeaponBox  @ 00124d98
undefined4 IsEmpty__10CWeaponBox(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(int *)(param_1 + 0x458 + iVar1 * 4) != 0) {
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  iVar1 = 0;
  do {
    if (*(int *)(param_1 + 0x478 + iVar1 * 4) != 0) {
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  return 1;
}


// IsEmpty__9CSoundEnt  @ 000f32dc
bool IsEmpty__9CSoundEnt(int param_1)

{
  return *(int *)(param_1 + 0x45c) == -1;
}


