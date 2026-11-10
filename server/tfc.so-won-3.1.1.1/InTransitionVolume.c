// InTransitionVolume__12CChangeLevelP11CBaseEntityPc  @ 00115d38
undefined4 InTransitionVolume__12CChangeLevelP11CBaseEntityPc(int *param_1,undefined4 param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 local_c;
  
  cVar2 = (**(code **)(param_1[0x115] + 0x20))(param_1);
  if (-1 < cVar2) {
    if ((*(int *)(*param_1 + 0x108) == 0xc) && (iVar5 = *(int *)(*param_1 + 0x194), iVar5 != 0)) {
      param_1 = *(int **)(iVar5 + 0x7c);
    }
    local_c = 1;
    iVar5 = 0;
    while( true ) {
      do {
        iVar5 = (*DAT_0019f6d8)(iVar5,"targetname",param_2);
        bVar1 = false;
        if ((iVar5 == 0) || (iVar3 = (*DAT_0019f7b8)(iVar5), iVar3 == 0)) {
          bVar1 = true;
        }
        if (bVar1) {
          return local_c;
        }
        iVar3 = iVar5;
        if ((iVar5 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          puVar4 = *(undefined4 **)(iVar3 + 0x7c);
        }
      } while ((puVar4 == (undefined4 *)0x0) ||
              (iVar3 = strcmp((char *)(*(int *)*puVar4 + *(int *)(gpGlobals + 0x98)),
                              "trigger_transition"), iVar3 != 0));
      iVar3 = Intersects__11CBaseEntityP11CBaseEntity(puVar4,param_1);
      if (iVar3 != 0) break;
      local_c = 0;
    }
  }
  return 1;
}


