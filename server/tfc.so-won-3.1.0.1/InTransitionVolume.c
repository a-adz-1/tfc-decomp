// InTransitionVolume__12CChangeLevelP11CBaseEntityPc  @ 00103f3c
undefined4 InTransitionVolume__12CChangeLevelP11CBaseEntityPc(int *param_1,undefined4 param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_4;
  
  cVar2 = (**(code **)(param_1[0xf5] + 0x1c))(param_1);
  if (-1 < cVar2) {
    iVar3 = *param_1;
    if ((*(int *)(iVar3 + 0x108) == 0xc) && (*(int *)(iVar3 + 0x194) != 0)) {
      iVar3 = *(int *)(iVar3 + 0x194);
      if ((iVar3 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
        param_1 = (int *)0x0;
      }
      else {
        param_1 = *(int **)(iVar3 + 0x7c);
      }
    }
    local_4 = 1;
    iVar3 = 0;
    while( true ) {
      do {
        iVar3 = (*DAT_001a7e78)(iVar3,"targetname",param_2);
        bVar1 = false;
        if ((iVar3 == 0) || (iVar4 = (*DAT_001a7f58)(iVar3), iVar4 == 0)) {
          bVar1 = true;
        }
        if (bVar1) {
          return local_4;
        }
        iVar4 = iVar3;
        if ((iVar3 == 0) && (iVar4 = (*DAT_001a7f54)(0), iVar4 == 0)) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          puVar5 = *(undefined4 **)(iVar4 + 0x7c);
        }
      } while ((puVar5 == (undefined4 *)0x0) ||
              (iVar4 = strcmp((char *)(*(int *)*puVar5 + *(int *)(gpGlobals + 0x98)),
                              "trigger_transition"), iVar4 != 0));
      iVar4 = Intersects__11CBaseEntityP11CBaseEntity(puVar5,param_1);
      if (iVar4 != 0) break;
      local_4 = 0;
    }
  }
  return 1;
}


