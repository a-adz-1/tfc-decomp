// StartControl__9CFuncTankP11CBasePlayer  @ 000a0288
undefined4 StartControl__9CFuncTankP11CBasePlayer(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[0xf6] == 0) {
    (*DAT_001a7f34)(1,"using TANK!\n");
    param_1[0xf6] = param_2;
    if (*(int *)(param_2 + 0x844) != 0) {
      (**(code **)(*(int *)(*(int *)(param_2 + 0x844) + 0x3d4) + 0x120))
                (*(int *)(param_2 + 0x844),0);
      *(undefined4 *)(*(int *)param_1[0xf6] + 0xc0) = 0;
    }
    *(byte *)(param_1[0xf6] + 0x81c) = *(byte *)(param_1[0xf6] + 0x81c) | 1;
    iVar1 = *(int *)param_1[0xf6];
    param_1[0xf8] = *(int *)(iVar1 + 8);
    param_1[0xf9] = *(int *)(iVar1 + 0xc);
    param_1[0xfa] = *(int *)(iVar1 + 0x10);
    *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


