// RemoveAllItems__11CBasePlayeri  @ 000c9cc8
void RemoveAllItems__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *local_8;
  
  if (param_1[0x211] != 0) {
    ResetAutoaim__11CBasePlayer(param_1);
    (**(code **)(*(int *)(param_1[0x211] + 0x3d4) + 0x120))(param_1[0x211],0);
    param_1[0x211] = 0;
  }
  param_1[0x213] = 0;
  piVar2 = param_1 + 0x20b;
  local_8 = piVar2;
  do {
    iVar3 = *piVar2;
    param_1[0x211] = iVar3;
    while (iVar3 != 0) {
      iVar1 = param_1[0x211];
      iVar3 = *(int *)(iVar1 + 0x3f8);
      (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x130))(iVar1);
      param_1[0x211] = iVar3;
    }
    *piVar2 = 0;
    iVar3 = piVar2[1];
    param_1[0x211] = iVar3;
    while (iVar3 != 0) {
      iVar1 = param_1[0x211];
      iVar3 = *(int *)(iVar1 + 0x3f8);
      (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x130))(iVar1);
      param_1[0x211] = iVar3;
    }
    piVar2[1] = 0;
    iVar3 = piVar2[2];
    param_1[0x211] = iVar3;
    while (iVar3 != 0) {
      iVar1 = param_1[0x211];
      iVar3 = *(int *)(iVar1 + 0x3f8);
      (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x130))(iVar1);
      param_1[0x211] = iVar3;
    }
    piVar2[2] = 0;
    piVar2 = piVar2 + 3;
    local_8 = local_8 + 3;
  } while ((int)local_8 <= (int)(param_1 + 0x210));
  param_1[0x211] = 0;
  *(undefined4 *)(*param_1 + 0xbc) = 0;
  *(undefined4 *)(*param_1 + 0xc0) = 0;
  if (param_2 == 0) {
    *(uint *)(*param_1 + 0x168) = *(uint *)(*param_1 + 0x168) & 0x80000000;
  }
  else {
    *(undefined4 *)(*param_1 + 0x168) = 0;
  }
  iVar3 = 0x1f;
  piVar2 = param_1 + 0x233;
  do {
    *piVar2 = 0;
    piVar2[-1] = 0;
    piVar2[-2] = 0;
    piVar2[-3] = 0;
    piVar2[-4] = 0;
    piVar2[-5] = 0;
    piVar2[-6] = 0;
    piVar2[-7] = 0;
    piVar2[-8] = 0;
    piVar2[-9] = 0;
    piVar2[-10] = 0;
    piVar2[-0xb] = 0;
    piVar2[-0xc] = 0;
    piVar2[-0xd] = 0;
    piVar2[-0xe] = 0;
    piVar2[-0xf] = 0;
    piVar2 = piVar2 + -0x10;
    iVar3 = iVar3 + -0x10;
  } while (-1 < iVar3);
  UpdateClientData__11CBasePlayer(param_1);
  (*DAT_001a7ef8)(1,gmsgCurWeapon,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001a7f00)(0);
  (*DAT_001a7f00)(0);
  (*DAT_001a7f00)(0);
  (*DAT_001a7efc)();
  return;
}


