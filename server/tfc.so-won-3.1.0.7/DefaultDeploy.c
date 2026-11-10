// DefaultDeploy__17CBasePlayerWeaponPcT1iT1i  @ 001208b4
undefined4
DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
          (int param_1,int param_2,int param_3,undefined4 param_4,char *param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x444) + 0x11c))(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(int *)(**(int **)(param_1 + 0x464) + 0xbc) = param_2 - *(int *)(gpGlobals + 0x98);
    *(int *)(**(int **)(param_1 + 0x464) + 0xc0) = param_3 - *(int *)(gpGlobals + 0x98);
    *(float *)(*(int *)(param_1 + 0x464) + 0x158) = (float)*(int *)(param_1 + 0x46c);
    strcpy((char *)(*(int *)(param_1 + 0x464) + 0xd20),param_5);
    *(undefined4 *)(*(int *)(param_1 + 0x464) + 0xd40) = 0;
    (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,param_4,param_6);
    strcpy((char *)(*(int *)(param_1 + 0x464) + 0xd48),param_5);
    *(int *)(*(int *)(param_1 + 0x464) + 0xd68) = param_3;
    if (*(int *)(**(int **)(param_1 + 0x464) + 0x20c) == 8) {
      Spy_DisguiseExternalWeaponModel__11CBasePlayer(*(int **)(param_1 + 0x464));
    }
    *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x648) = 0x3f000000;
    *(undefined4 *)(param_1 + 0x480) = 0x3f800000;
    uVar2 = 1;
  }
  return uVar2;
}


