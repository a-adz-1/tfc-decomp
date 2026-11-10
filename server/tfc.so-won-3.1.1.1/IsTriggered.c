// IsTriggered__11CBaseEntity  @ 00112f2c
undefined4 IsTriggered__11CBaseEntity(void)

{
  return 1;
}


// IsTriggered__12CMultiSource  @ 0008d018
undefined4 IsTriggered__12CMultiSource(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
    iVar1 = param_1[0x176];
    if (0 < iVar1) {
      do {
        if (param_1[iVar2 + 0x156] == 0) break;
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
    if ((iVar2 == iVar1) &&
       ((param_1[0x177] == 0 ||
        (iVar2 = EntityGetState__12CGlobalStatei(&gGlobalState,param_1[0x177]), iVar2 == 1)))) {
      return 1;
    }
  }
  return 0;
}


