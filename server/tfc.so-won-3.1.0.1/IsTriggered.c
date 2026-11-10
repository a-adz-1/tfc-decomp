// IsTriggered__11CBaseEntity  @ 00100710
undefined4 IsTriggered__11CBaseEntity(void)

{
  return 1;
}


// IsTriggered__12CMultiSource  @ 00082d50
undefined4 IsTriggered__12CMultiSource(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
    if (0 < param_1[0x156]) {
      uVar1 = param_1[0x156] & 3;
      if (param_1[0x156] < 1) goto LAB_00082db9;
      if (uVar1 == 0) goto LAB_00082da4;
      if (uVar1 < 2) goto LAB_00082db9;
      if (uVar1 < 3) goto LAB_00082db2;
      for (; param_1[iVar2 + 0x136] != 0; iVar2 = iVar2 + 1) {
        iVar2 = iVar2 + 1;
LAB_00082db2:
        if (param_1[iVar2 + 0x136] == 0) break;
        iVar2 = iVar2 + 1;
LAB_00082db9:
        if ((param_1[iVar2 + 0x136] == 0) || (iVar2 = iVar2 + 1, param_1[0x156] <= iVar2)) break;
LAB_00082da4:
        if (param_1[iVar2 + 0x136] == 0) break;
      }
    }
    if ((iVar2 == param_1[0x156]) &&
       ((param_1[0x157] == 0 ||
        (iVar2 = EntityGetState__12CGlobalStatei(&gGlobalState,param_1[0x157]), iVar2 == 1)))) {
      return 1;
    }
  }
  return 0;
}


