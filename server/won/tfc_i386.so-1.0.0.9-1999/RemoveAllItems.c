// RemoveAllItems__11CBasePlayeri  @ 000d7a10
void RemoveAllItems__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1[0x20c] != 0) {
    ResetAutoaim__11CBasePlayer(param_1);
    (**(code **)(*(int *)(param_1[0x20c] + 0x3c8) + 0x120))(param_1[0x20c]);
    param_1[0x20c] = 0;
  }
  param_1[0x20e] = 0;
  iVar3 = 0;
  do {
    iVar1 = param_1[iVar3 + 0x206];
    param_1[0x20c] = iVar1;
    while (iVar1 != 0) {
      iVar2 = param_1[0x20c];
      iVar1 = *(int *)(iVar2 + 0x3ec);
      (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x130))(iVar2);
      param_1[0x20c] = iVar1;
    }
    param_1[iVar3 + 0x206] = 0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 6);
  param_1[0x20c] = 0;
  *(undefined4 *)(*param_1 + 0x9c) = 0;
  *(undefined4 *)(*param_1 + 0xa0) = 0;
  if (param_2 == 0) {
    *(uint *)(*param_1 + 0x148) = *(uint *)(*param_1 + 0x148) & 0x80000000;
  }
  else {
    *(undefined4 *)(*param_1 + 0x148) = 0;
  }
  iVar3 = 0;
  do {
    param_1[iVar3 + 0x20f] = 0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x20);
  UpdateClientData__11CBasePlayer(param_1);
  (*DAT_00175578)(1,gmsgCurWeapon,0,*(undefined4 *)(*param_1 + 0x1e8));
  (*DAT_00175580)(0);
  (*DAT_00175580)(0);
  (*DAT_00175580)(0);
  (*DAT_0017557c)();
  return;
}


