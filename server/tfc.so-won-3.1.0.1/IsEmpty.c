// IsEmpty__10CWeaponBox  @ 00111f58
undefined4 IsEmpty__10CWeaponBox(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((((*(int *)(param_1 + 0x3d8) == 0) && (*(int *)(param_1 + 0x3dc) == 0)) &&
       (*(int *)(param_1 + 0x3e0) == 0)) &&
      ((*(int *)(param_1 + 0x3e4) == 0 && (*(int *)(param_1 + 1000) == 0)))) &&
     (*(int *)(param_1 + 0x3ec) == 0)) {
    iVar1 = 0;
    do {
      if (((*(int *)(param_1 + 0x3f8 + iVar1 * 4) != 0) ||
          (*(int *)(param_1 + 0x3fc + iVar1 * 4) != 0)) ||
         ((*(int *)(param_1 + 0x400 + iVar1 * 4) != 0 ||
          (*(int *)(param_1 + 0x404 + iVar1 * 4) != 0)))) goto LAB_00111faf;
      iVar1 = iVar1 + 4;
    } while (iVar1 < 0x20);
    uVar2 = 1;
  }
  else {
LAB_00111faf:
    uVar2 = 0;
  }
  return uVar2;
}


// IsEmpty__9CSoundEnt  @ 000e44c8
bool IsEmpty__9CSoundEnt(int param_1)

{
  return *(int *)(param_1 + 0x3dc) == -1;
}


