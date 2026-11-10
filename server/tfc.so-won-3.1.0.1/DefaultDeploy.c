// DefaultDeploy__17CBasePlayerWeaponPcT1iT1i  @ 00110d64
undefined4
DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
          (int param_1,int param_2,int param_3,undefined4 param_4,char *param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x3d4) + 0x114))(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(int *)(**(int **)(param_1 + 0x3f4) + 0xbc) = param_2 - *(int *)(gpGlobals + 0x98);
    *(int *)(**(int **)(param_1 + 0x3f4) + 0xc0) = param_3 - *(int *)(gpGlobals + 0x98);
    *(float *)(*(int *)(param_1 + 0x3f4) + 0x158) = (float)*(int *)(param_1 + 0x3fc);
    strcpy((char *)(*(int *)(param_1 + 0x3f4) + 0xcac),param_5);
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0xccc) = 0;
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,param_4,param_6);
    strcpy((char *)(*(int *)(param_1 + 0x3f4) + 0xcd4),param_5);
    *(int *)(*(int *)(param_1 + 0x3f4) + 0xcf4) = param_3;
    if (*(int *)(**(int **)(param_1 + 0x3f4) + 0x20c) == 8) {
      Spy_DisguiseExternalWeaponModel__11CBasePlayer(*(int **)(param_1 + 0x3f4));
    }
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x5d8) = 0x3f000000;
    *(undefined4 *)(param_1 + 0x410) = 0x3f800000;
    uVar2 = 1;
  }
  return uVar2;
}


