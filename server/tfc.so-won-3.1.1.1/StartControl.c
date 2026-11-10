// StartControl__9CFuncTankP11CBasePlayer  @ 000ac970
undefined4 StartControl__9CFuncTankP11CBasePlayer(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[0x116] == 0) {
    (*DAT_0019f794)(1,"using TANK!\n");
    param_1[0x116] = param_2;
    iVar1 = *(int *)(param_2 + 0x8dc);
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar1 + 0x454) + 0x128))(iVar1,0);
      *(undefined4 *)(*(int *)param_1[0x116] + 0xc0) = 0;
    }
    *(byte *)(param_1[0x116] + 0x8b4) = *(byte *)(param_1[0x116] + 0x8b4) | 1;
    iVar1 = *(int *)param_1[0x116];
    param_1[0x118] = *(int *)(iVar1 + 8);
    param_1[0x119] = *(int *)(iVar1 + 0xc);
    param_1[0x11a] = *(int *)(iVar1 + 0x10);
    *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


