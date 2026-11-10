// GetGrenadePossibility__16CItemAmmoRocketsP11CBasePlayer  @ 000fc614
undefined4 GetGrenadePossibility__16CItemAmmoRocketsP11CBasePlayer(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  
  lVar3 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
  if ((longdouble)0.5 <= lVar3) {
    iVar2 = 4;
    lVar3 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
    lVar4 = (longdouble)0.5;
    if ((byte)((lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
               (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) - 1) < 0x40) {
      iVar1 = *(int *)(param_2 + 0x50);
      if (iVar1 == 3) {
        iVar2 = 2;
      }
      if (iVar1 == 4) {
        iVar2 = 2;
      }
      if (iVar1 == 2) {
        iVar2 = 3;
      }
      if ((iVar1 != 0) && (*(int *)(param_2 + 0x48) < iVar2)) {
        *(int *)(param_2 + 0x48) = *(int *)(param_2 + 0x48) + 1;
        return 1;
      }
    }
    else {
      iVar1 = *(int *)(param_2 + 0x4c);
      if (iVar1 == 3) {
        iVar2 = 2;
      }
      if (iVar1 == 4) {
        iVar2 = 2;
      }
      if (iVar1 == 9) {
        iVar2 = 3;
      }
      if ((iVar1 != 0) && (*(int *)(param_2 + 0x44) < iVar2)) {
        *(int *)(param_2 + 0x44) = *(int *)(param_2 + 0x44) + 1;
        return 1;
      }
    }
  }
  return 0;
}


// GetGrenadePossibility__9CItemAmmoP11CBasePlayer  @ 000fd6e4
undefined4 GetGrenadePossibility__9CItemAmmoP11CBasePlayer(void)

{
  return 0;
}


