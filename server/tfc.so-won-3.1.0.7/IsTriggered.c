// IsTriggered__11CBaseEntity  @ 0010fa18
undefined4 IsTriggered__11CBaseEntity(void)

{
  return 1;
}


// IsTriggered__12CMultiSource  @ 0008ad54
undefined4 IsTriggered__12CMultiSource(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
    if (0 < param_1[0x172]) {
      uVar1 = param_1[0x172] & 3;
      if (param_1[0x172] < 1) goto LAB_0008adbd;
      if (uVar1 == 0) goto LAB_0008ada8;
      if (uVar1 < 2) goto LAB_0008adbd;
      if (uVar1 < 3) goto LAB_0008adb6;
      for (; param_1[iVar2 + 0x152] != 0; iVar2 = iVar2 + 1) {
        iVar2 = iVar2 + 1;
LAB_0008adb6:
        if (param_1[iVar2 + 0x152] == 0) break;
        iVar2 = iVar2 + 1;
LAB_0008adbd:
        if ((param_1[iVar2 + 0x152] == 0) || (iVar2 = iVar2 + 1, param_1[0x172] <= iVar2)) break;
LAB_0008ada8:
        if (param_1[iVar2 + 0x152] == 0) break;
      }
    }
    if ((iVar2 == param_1[0x172]) &&
       ((param_1[0x173] == 0 ||
        (iVar2 = EntityGetState__12CGlobalStatei(&gGlobalState,param_1[0x173]), iVar2 == 1)))) {
      return 1;
    }
  }
  return 0;
}


