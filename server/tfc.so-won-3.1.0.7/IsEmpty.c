// IsEmpty__10CWeaponBox  @ 00121aa8
undefined4 IsEmpty__10CWeaponBox(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((((*(int *)(param_1 + 0x448) == 0) && (*(int *)(param_1 + 0x44c) == 0)) &&
       (*(int *)(param_1 + 0x450) == 0)) &&
      ((*(int *)(param_1 + 0x454) == 0 && (*(int *)(param_1 + 0x458) == 0)))) &&
     (*(int *)(param_1 + 0x45c) == 0)) {
    iVar1 = 0;
    do {
      if (((*(int *)(param_1 + 0x468 + iVar1 * 4) != 0) ||
          (*(int *)(param_1 + 0x46c + iVar1 * 4) != 0)) ||
         ((*(int *)(param_1 + 0x470 + iVar1 * 4) != 0 ||
          (*(int *)(param_1 + 0x474 + iVar1 * 4) != 0)))) goto LAB_00121aff;
      iVar1 = iVar1 + 4;
    } while (iVar1 < 0x20);
    uVar2 = 1;
  }
  else {
LAB_00121aff:
    uVar2 = 0;
  }
  return uVar2;
}


// IsEmpty__9CSoundEnt  @ 000f0f64
bool IsEmpty__9CSoundEnt(int param_1)

{
  return *(int *)(param_1 + 0x44c) == -1;
}


