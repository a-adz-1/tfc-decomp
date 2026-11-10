// GetGrenadePossibility__16CItemAmmoRocketsP11CBasePlayer  @ 000fa524
undefined4 GetGrenadePossibility__16CItemAmmoRocketsP11CBasePlayer(undefined4 param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  longdouble lVar3;
  
  lVar2 = (longdouble)(*DAT_001c118c)(0,0x3f800000);
  if ((longdouble)0.5 <= lVar2) {
    iVar1 = 4;
    lVar2 = (longdouble)(*DAT_001c118c)(0,0x3f800000);
    lVar3 = (longdouble)0.5;
    if ((byte)((lVar3 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar2)) << 10) >> 8) |
               (byte)((ushort)((ushort)(lVar3 == lVar2) << 0xe) >> 8)) - 1) < 0x40) {
      if (*(int *)(param_2 + 0x50) == 3) {
        iVar1 = 2;
      }
      if (*(int *)(param_2 + 0x50) == 4) {
        iVar1 = 2;
      }
      if (*(int *)(param_2 + 0x50) == 2) {
        iVar1 = 3;
      }
      if ((*(int *)(param_2 + 0x50) != 0) && (*(int *)(param_2 + 0x48) < iVar1)) {
        *(int *)(param_2 + 0x48) = *(int *)(param_2 + 0x48) + 1;
        return 1;
      }
    }
    else {
      if (*(int *)(param_2 + 0x4c) == 3) {
        iVar1 = 2;
      }
      if (*(int *)(param_2 + 0x4c) == 4) {
        iVar1 = 2;
      }
      if (*(int *)(param_2 + 0x4c) == 9) {
        iVar1 = 3;
      }
      if ((*(int *)(param_2 + 0x4c) != 0) && (*(int *)(param_2 + 0x44) < iVar1)) {
        *(int *)(param_2 + 0x44) = *(int *)(param_2 + 0x44) + 1;
        return 1;
      }
    }
  }
  return 0;
}


// GetGrenadePossibility__9CItemAmmoP11CBasePlayer  @ 000fb15c
undefined4 GetGrenadePossibility__9CItemAmmoP11CBasePlayer(void)

{
  return 0;
}


