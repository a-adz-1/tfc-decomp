// RemoveAllItems__11CBasePlayeri  @ 000d52f4
void RemoveAllItems__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *local_8;
  
  if (param_1[0x22d] != 0) {
    ResetAutoaim__11CBasePlayer(param_1);
    (**(code **)(*(int *)(param_1[0x22d] + 0x444) + 0x128))(param_1[0x22d],0);
    param_1[0x22d] = 0;
  }
  if (param_1[0x22f] != 0) {
    iVar2 = (**(code **)(*(int *)(param_1[0x22f] + 0x444) + 0xa8))(param_1[0x22f]);
    param_1[0x230] = iVar2;
  }
  param_1[0x22f] = 0;
  piVar3 = param_1 + 0x227;
  local_8 = piVar3;
  do {
    iVar2 = *piVar3;
    param_1[0x22d] = iVar2;
    while (iVar2 != 0) {
      iVar1 = param_1[0x22d];
      iVar2 = *(int *)(iVar1 + 0x468);
      (**(code **)(*(int *)(iVar1 + 0x444) + 0x138))(iVar1);
      param_1[0x22d] = iVar2;
    }
    *piVar3 = 0;
    iVar2 = piVar3[1];
    param_1[0x22d] = iVar2;
    while (iVar2 != 0) {
      iVar1 = param_1[0x22d];
      iVar2 = *(int *)(iVar1 + 0x468);
      (**(code **)(*(int *)(iVar1 + 0x444) + 0x138))(iVar1);
      param_1[0x22d] = iVar2;
    }
    piVar3[1] = 0;
    iVar2 = piVar3[2];
    param_1[0x22d] = iVar2;
    while (iVar2 != 0) {
      iVar1 = param_1[0x22d];
      iVar2 = *(int *)(iVar1 + 0x468);
      (**(code **)(*(int *)(iVar1 + 0x444) + 0x138))(iVar1);
      param_1[0x22d] = iVar2;
    }
    piVar3[2] = 0;
    piVar3 = piVar3 + 3;
    local_8 = local_8 + 3;
  } while ((int)local_8 <= (int)(param_1 + 0x22c));
  param_1[0x22d] = 0;
  *(undefined4 *)(*param_1 + 0xbc) = 0;
  *(undefined4 *)(*param_1 + 0xc0) = 0;
  if (param_2 == 0) {
    *(uint *)(*param_1 + 0x168) = *(uint *)(*param_1 + 0x168) & 0x80000000;
  }
  else {
    *(undefined4 *)(*param_1 + 0x168) = 0;
  }
  iVar2 = 0x1f;
  piVar3 = param_1 + 0x250;
  do {
    *piVar3 = 0;
    piVar3[-1] = 0;
    piVar3[-2] = 0;
    piVar3[-3] = 0;
    piVar3[-4] = 0;
    piVar3[-5] = 0;
    piVar3[-6] = 0;
    piVar3[-7] = 0;
    piVar3[-8] = 0;
    piVar3[-9] = 0;
    piVar3[-10] = 0;
    piVar3[-0xb] = 0;
    piVar3[-0xc] = 0;
    piVar3[-0xd] = 0;
    piVar3[-0xe] = 0;
    piVar3[-0xf] = 0;
    piVar3 = piVar3 + -0x10;
    iVar2 = iVar2 + -0x10;
  } while (-1 < iVar2);
  UpdateClientData__11CBasePlayer(param_1);
  (*DAT_001c10d8)(1,gmsgCurWeapon,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001c10e0)(0);
  (*DAT_001c10e0)(0);
  (*DAT_001c10e0)(0);
  (*DAT_001c10dc)();
  return;
}


