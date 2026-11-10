// Register__12CMultiSource  @ 0008ae08
void Register__12CMultiSource(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  param_1[0x172] = 0;
  memset(param_1 + 0x112,0,0x100);
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_DoNothing__11CBaseEntity;
  iVar2 = (*DAT_001c1058)(0,"target",*(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98));
  while( true ) {
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001c1138)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if ((bVar1) || (0x1f < param_1[0x172])) break;
    iVar3 = iVar2;
    if ((iVar2 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x7c);
    }
    if (iVar3 != 0) {
      iVar4 = param_1[0x172];
      param_1[0x172] = param_1[0x172] + 1;
      __as__7EHANDLEP11CBaseEntity(param_1 + iVar4 * 2 + 0x112,iVar3);
    }
    iVar2 = (*DAT_001c1058)(iVar2,"target",*(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98));
  }
  iVar2 = 0;
  while( true ) {
    iVar2 = (*DAT_001c1058)(iVar2,"classname","multi_manager");
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001c1138)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if ((bVar1) || (0x1f < param_1[0x172])) break;
    iVar3 = iVar2;
    if ((iVar2 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x7c);
    }
    if ((iVar3 != 0) &&
       (iVar4 = (**(code **)(*(int *)(iVar3 + 0x444) + 0x98))
                          (iVar3,*(undefined4 *)(*param_1 + 0x1cc)), iVar4 != 0)) {
      iVar4 = param_1[0x172];
      param_1[0x172] = param_1[0x172] + 1;
      __as__7EHANDLEP11CBaseEntity(param_1 + iVar4 * 2 + 0x112,iVar3);
    }
  }
  *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) & 0xfe;
  return;
}


