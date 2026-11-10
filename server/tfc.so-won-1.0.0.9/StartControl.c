// StartControl__9CFuncTankP11CBasePlayer  @ 000b4580
undefined4 StartControl__9CFuncTankP11CBasePlayer(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[0xf3] == 0) {
    (*DAT_001755b4)(1,"using TANK!\n");
    param_1[0xf3] = param_2;
    if (*(int *)(param_2 + 0x830) != 0) {
      (**(code **)(*(int *)(*(int *)(param_2 + 0x830) + 0x3c8) + 0x120))(*(int *)(param_2 + 0x830));
      *(undefined4 *)(*(int *)param_1[0xf3] + 0xa0) = 0;
    }
    *(byte *)(param_1[0xf3] + 0x808) = *(byte *)(param_1[0xf3] + 0x808) | 1;
    iVar1 = *(int *)param_1[0xf3];
    param_1[0xf5] = *(int *)(iVar1 + 8);
    param_1[0xf6] = *(int *)(iVar1 + 0xc);
    param_1[0xf7] = *(int *)(iVar1 + 0x10);
    *(float *)(*param_1 + 0xe4) = *(float *)(*param_1 + 0xe0) + 0.1;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


