// RemoveAllItems__11CBasePlayeri  @ 000d4fc8
void RemoveAllItems__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1[0x237] != 0) {
    ResetAutoaim__11CBasePlayer(param_1);
    (**(code **)(*(int *)(param_1[0x237] + 0x454) + 0x128))(param_1[0x237],0);
    param_1[0x237] = 0;
  }
  iVar2 = param_1[0x239];
  if (iVar2 != 0) {
    iVar2 = (**(code **)(*(int *)(iVar2 + 0x454) + 0xa8))(iVar2);
    param_1[0x23a] = iVar2;
  }
  param_1[0x239] = 0;
  iVar2 = 0;
  do {
    iVar3 = param_1[iVar2 + 0x231];
    param_1[0x237] = iVar3;
    while (iVar3 != 0) {
      iVar1 = param_1[0x237];
      iVar3 = *(int *)(iVar1 + 0x478);
      (**(code **)(*(int *)(iVar1 + 0x454) + 0x138))(iVar1);
      param_1[0x237] = iVar3;
    }
    iVar3 = iVar2 + 1;
    param_1[iVar2 + 0x231] = 0;
    iVar2 = iVar3;
  } while (iVar3 < 6);
  param_1[0x237] = 0;
  *(undefined4 *)(*param_1 + 0xbc) = 0;
  *(undefined4 *)(*param_1 + 0xc0) = 0;
  if (param_2 == 0) {
    *(uint *)(*param_1 + 0x168) = *(uint *)(*param_1 + 0x168) & 0x80000000;
  }
  else {
    *(undefined4 *)(*param_1 + 0x168) = 0;
  }
  iVar2 = 0;
  do {
    param_1[iVar2 + 0x23b] = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x20);
  UpdateClientData__11CBasePlayer(param_1);
  (*DAT_0019f758)(1,gmsgCurWeapon,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_0019f760)(0);
  (*DAT_0019f760)(0);
  (*DAT_0019f760)(0);
  (*DAT_0019f75c)();
  return;
}


