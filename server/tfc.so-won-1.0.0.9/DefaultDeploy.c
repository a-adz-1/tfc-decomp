// DefaultDeploy__17CBasePlayerWeaponPcT1iT1  @ 0011b9f0
undefined4
DefaultDeploy__17CBasePlayerWeaponPcT1iT1
          (int param_1,int param_2,int param_3,undefined4 param_4,char *param_5)

{
  float *pfVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0x114))(param_1);
  pfVar1 = gpGlobals;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    *(int *)(**(int **)(param_1 + 1000) + 0x9c) = param_2 - (int)gpGlobals[0x26];
    *(int *)(**(int **)(param_1 + 1000) + 0xa0) = param_3 - (int)pfVar1[0x26];
    *(float *)(*(int *)(param_1 + 1000) + 0x158) = (float)*(int *)(param_1 + 0x3f0);
    strcpy((char *)(*(int *)(param_1 + 1000) + 0xc94),param_5);
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0xcb4) = 0;
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,param_4);
    strcpy((char *)(*(int *)(param_1 + 1000) + 0xcbc),param_5);
    *(int *)(*(int *)(param_1 + 1000) + 0xcdc) = param_3;
    if (*(int *)(*(int *)(param_1 + 1000) + 0x2c) == 8) {
      Spy_DisguiseExternalWeaponModel__11CBasePlayer(*(int *)(param_1 + 1000));
    }
    pfVar1 = gpGlobals;
    *(float *)(*(int *)(param_1 + 1000) + 0x5cc) = *gpGlobals + 0.5;
    *(float *)(param_1 + 0x404) = *pfVar1 + 1.0;
    uVar3 = 1;
  }
  return uVar3;
}


