// StartControl__9CFuncTankP11CBasePlayer  @ 000aacb0
undefined4 StartControl__9CFuncTankP11CBasePlayer(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[0x112] == 0) {
    (*DAT_001c1114)(1,"using TANK!\n");
    param_1[0x112] = param_2;
    if (*(int *)(param_2 + 0x8b4) != 0) {
      (**(code **)(*(int *)(*(int *)(param_2 + 0x8b4) + 0x444) + 0x128))
                (*(int *)(param_2 + 0x8b4),0);
      *(undefined4 *)(*(int *)param_1[0x112] + 0xc0) = 0;
    }
    *(byte *)(param_1[0x112] + 0x88c) = *(byte *)(param_1[0x112] + 0x88c) | 1;
    iVar1 = *(int *)param_1[0x112];
    param_1[0x114] = *(int *)(iVar1 + 8);
    param_1[0x115] = *(int *)(iVar1 + 0xc);
    param_1[0x116] = *(int *)(iVar1 + 0x10);
    *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 0.1;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


