// Register__12CMultiSource  @ 0009da70
void Register__12CMultiSource(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  param_1[0x153] = 0;
  memset(param_1 + 0xf3,0,0x100);
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_DoNothing__11CBaseEntity;
  iVar2 = (*DAT_001754f8)(0,"target",*(int *)(*param_1 + 0x1ac) + *(int *)(gpGlobals + 0x98));
  while( true ) {
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001755d8)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if ((bVar1) || (0x1f < param_1[0x153])) break;
    iVar3 = iVar2;
    if ((iVar2 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0xd8);
    }
    if (iVar3 != 0) {
      iVar4 = param_1[0x153];
      param_1[0x153] = param_1[0x153] + 1;
      __as__7EHANDLEP11CBaseEntity(param_1 + iVar4 * 2 + 0xf3,iVar3);
    }
    iVar2 = (*DAT_001754f8)(iVar2,"target",*(int *)(*param_1 + 0x1ac) + *(int *)(gpGlobals + 0x98));
  }
  iVar2 = 0;
  while( true ) {
    iVar2 = (*DAT_001754f8)(iVar2,"classname","multi_manager");
    bVar1 = false;
    if ((iVar2 == 0) || (iVar3 = (*DAT_001755d8)(iVar2), iVar3 == 0)) {
      bVar1 = true;
    }
    if ((bVar1) || (0x1f < param_1[0x153])) break;
    iVar3 = iVar2;
    if ((iVar2 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0xd8);
    }
    if ((iVar3 != 0) &&
       (iVar4 = (**(code **)(*(int *)(iVar3 + 0x3c8) + 0x94))
                          (iVar3,*(undefined4 *)(*param_1 + 0x1ac)), iVar4 != 0)) {
      iVar4 = param_1[0x153];
      param_1[0x153] = param_1[0x153] + 1;
      __as__7EHANDLEP11CBaseEntity(param_1 + iVar4 * 2 + 0xf3,iVar3);
    }
  }
  *(byte *)(*param_1 + 0x180) = *(byte *)(*param_1 + 0x180) & 0xfe;
  return;
}


