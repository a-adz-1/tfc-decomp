// FindTarget__12CTFSentrygun  @ 000debd4
undefined4 FindTarget__12CTFSentrygun(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  while( true ) {
    if (*(int *)(gpGlobals + 0x90) < iVar3) {
      return 0;
    }
    iVar1 = UTIL_PlayerByIndex__Fi(iVar3);
    if ((((iVar1 != 0) && (iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x144), iVar1 != iVar2))
        && (iVar2 = ValidTarget__12CTFSentrygunP11CBaseEntity(param_1,iVar1), iVar2 != 0)) &&
       ((iVar2 = Range__12CTFSentrygunP11CBaseEntity(param_1,iVar1), iVar2 != 3 &&
        ((iVar2 != 2 ||
         (iVar2 = (**(code **)(*(int *)(param_1 + 0x3d4) + 0x130))(param_1,iVar1), iVar2 != 0))))))
    break;
    iVar3 = iVar3 + 1;
  }
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x47c,iVar1);
  FoundTarget__12CTFSentrygun(param_1);
  return 1;
}


// FindTarget__9CFuncTankP7edict_s  @ 000a079c
undefined4 FindTarget__9CFuncTankP7edict_s(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


