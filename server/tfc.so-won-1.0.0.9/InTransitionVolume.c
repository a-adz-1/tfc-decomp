// InTransitionVolume__12CChangeLevelP11CBaseEntityPc  @ 00111580
undefined4 InTransitionVolume__12CChangeLevelP11CBaseEntityPc(int *param_1,undefined4 param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_8;
  
  cVar2 = (**(code **)(param_1[0xf2] + 0x1c))(param_1);
  if (-1 < cVar2) {
    iVar3 = *param_1;
    if ((*(int *)(iVar3 + 0xe8) == 0xc) && (*(int *)(iVar3 + 0x174) != 0)) {
      iVar3 = *(int *)(iVar3 + 0x174);
      if ((iVar3 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
        param_1 = (int *)0x0;
      }
      else {
        param_1 = *(int **)(iVar3 + 0xd8);
      }
    }
    local_8 = 1;
    iVar3 = 0;
    while( true ) {
      do {
        iVar3 = (*DAT_001754f8)(iVar3,"targetname",param_2);
        bVar1 = false;
        if ((iVar3 == 0) || (iVar4 = (*DAT_001755d8)(iVar3), iVar4 == 0)) {
          bVar1 = true;
        }
        if (bVar1) {
          return local_8;
        }
        iVar4 = iVar3;
        if ((iVar3 == 0) && (iVar4 = (*DAT_001755d4)(0), iVar4 == 0)) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          puVar5 = *(undefined4 **)(iVar4 + 0xd8);
        }
      } while ((puVar5 == (undefined4 *)0x0) ||
              (iVar4 = strcmp((char *)(*(int *)*puVar5 + *(int *)(gpGlobals + 0x98)),
                              "trigger_transition"), iVar4 != 0));
      iVar4 = Intersects__11CBaseEntityP11CBaseEntity(puVar5,param_1);
      if (iVar4 != 0) break;
      local_8 = 0;
    }
  }
  return 1;
}


