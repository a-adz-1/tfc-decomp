// GetLaser__14CFuncTankLaser  @ 000ab8c0
int GetLaser__14CFuncTankLaser(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *local_8;
  
  if (param_1[0x135] != 0) {
    return param_1[0x135];
  }
  iVar2 = *(int *)(*param_1 + 0x1d4) + *(int *)(gpGlobals + 0x98);
  iVar3 = 0;
  while( true ) {
    iVar3 = (*DAT_0019f6d8)(iVar3,"targetname",iVar2);
    bVar1 = false;
    if ((iVar3 == 0) || (iVar2 = (*DAT_0019f7b8)(iVar3), iVar2 == 0)) {
      bVar1 = true;
    }
    if (bVar1) goto LAB_000ab9db;
    local_8 = (int *)(iVar3 + 0x80);
    if (iVar3 == 0) {
      local_8 = (int *)0x0;
    }
    iVar2 = strcmp((char *)(*local_8 + *(int *)(gpGlobals + 0x98)),"env_laser");
    if (iVar2 == 0) break;
    iVar2 = *(int *)(*param_1 + 0x1d4) + *(int *)(gpGlobals + 0x98);
  }
  if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(iVar3 + 0x7c);
  }
  param_1[0x135] = iVar2;
LAB_000ab9db:
  return param_1[0x135];
}


