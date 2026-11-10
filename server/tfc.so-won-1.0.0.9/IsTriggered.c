// IsTriggered__11CBaseEntity  @ 0010e500
undefined4 IsTriggered__11CBaseEntity(void)

{
  return 1;
}


// IsTriggered__12CMultiSource  @ 0009d9f0
undefined4 IsTriggered__12CMultiSource(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((*(byte *)(*param_1 + 0x180) & 1) == 0) {
    if (0 < param_1[0x153]) {
      do {
        if (param_1[iVar1 + 0x133] == 0) break;
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_1[0x153]);
    }
    if ((iVar1 == param_1[0x153]) &&
       ((param_1[0x154] == 0 ||
        (iVar1 = EntityGetState__12CGlobalStatei(&gGlobalState,param_1[0x154]), iVar1 == 1)))) {
      return 1;
    }
  }
  return 0;
}


