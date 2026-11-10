// GetGrenadePossibility__16CItemAmmoRocketsP11CBasePlayer  @ 000f5f90
undefined4 GetGrenadePossibility__16CItemAmmoRocketsP11CBasePlayer(undefined4 param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  lVar2 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
  if ((longdouble)0.5 <= lVar2) {
    iVar1 = 4;
    lVar2 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
    if ((longdouble)0.5 <= lVar2) {
      if (*(int *)(param_2 + 0x54) == 3) {
        iVar1 = 2;
      }
      if (*(int *)(param_2 + 0x54) == 2) {
        iVar1 = 3;
      }
      if ((*(int *)(param_2 + 0x54) != 0) && (*(int *)(param_2 + 0x4c) < iVar1)) {
        *(int *)(param_2 + 0x4c) = *(int *)(param_2 + 0x4c) + 1;
        return 1;
      }
    }
    else {
      if (*(int *)(param_2 + 0x50) == 3) {
        iVar1 = 2;
      }
      if (*(int *)(param_2 + 0x50) == 9) {
        iVar1 = 3;
      }
      if ((*(int *)(param_2 + 0x50) != 0) && (*(int *)(param_2 + 0x48) < iVar1)) {
        *(int *)(param_2 + 0x48) = *(int *)(param_2 + 0x48) + 1;
        return 1;
      }
    }
  }
  return 0;
}


// GetGrenadePossibility__9CItemAmmoP11CBasePlayer  @ 000f68b0
undefined4 GetGrenadePossibility__9CItemAmmoP11CBasePlayer(void)

{
  return 0;
}


