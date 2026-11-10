// Register__12CMultiSource  @ 0008a3c8
void Register__12CMultiSource(int *param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int local_8;
  
  param_1[0x176] = 0;
  memset(param_1 + 0x116,0,0x100);
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_DoNothing__11CBaseEntity;
  iVar3 = (*DAT_0019f6d8)(0,"target",*(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98));
  while( true ) {
    bVar2 = false;
    if ((iVar3 == 0) || (iVar4 = (*DAT_0019f7b8)(iVar3), iVar4 == 0)) {
      bVar2 = true;
    }
    if ((bVar2) || (0x1f < param_1[0x176])) break;
    iVar4 = iVar3;
    if ((iVar3 == 0) && (iVar4 = (*DAT_0019f7b4)(0), iVar4 == 0)) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(iVar4 + 0x7c);
    }
    if (iVar4 != 0) {
      iVar1 = param_1[0x176];
      param_1[0x176] = param_1[0x176] + 1;
      __as__7EHANDLEP11CBaseEntity(param_1 + iVar1 * 2 + 0x116,iVar4);
    }
    iVar3 = (*DAT_0019f6d8)(iVar3,"target",*(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98));
  }
  iVar3 = 0;
  while( true ) {
    iVar3 = (*DAT_0019f6d8)(iVar3,"classname","multi_manager");
    bVar2 = false;
    if ((iVar3 == 0) || (iVar4 = (*DAT_0019f7b8)(iVar3), iVar4 == 0)) {
      bVar2 = true;
    }
    if ((bVar2) || (0x1f < param_1[0x176])) break;
    iVar4 = iVar3;
    if ((iVar3 == 0) && (iVar4 = (*DAT_0019f7b4)(0), iVar4 == 0)) {
      local_8 = 0;
    }
    else {
      local_8 = *(int *)(iVar4 + 0x7c);
    }
    if ((local_8 != 0) &&
       (iVar4 = (**(code **)(*(int *)(local_8 + 0x454) + 0x98))
                          (local_8,*(undefined4 *)(*param_1 + 0x1cc)), iVar4 != 0)) {
      iVar4 = param_1[0x176];
      param_1[0x176] = param_1[0x176] + 1;
      __as__7EHANDLEP11CBaseEntity(param_1 + iVar4 * 2 + 0x116,local_8);
    }
  }
  *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) & 0xfe;
  return;
}


