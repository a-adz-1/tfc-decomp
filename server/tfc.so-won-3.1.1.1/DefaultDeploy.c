// DefaultDeploy__17CBasePlayerWeaponPcT1iT1i  @ 00125610
undefined4
DefaultDeploy__17CBasePlayerWeaponPcT1iT1i
          (int param_1,int param_2,int param_3,undefined4 param_4,char *param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x454) + 0x11c))(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(int *)(**(int **)(param_1 + 0x474) + 0xbc) = param_2 - *(int *)(gpGlobals + 0x98);
    *(int *)(**(int **)(param_1 + 0x474) + 0xc0) = param_3 - *(int *)(gpGlobals + 0x98);
    *(float *)(*(int *)(param_1 + 0x474) + 0x158) = (float)*(int *)(param_1 + 0x47c);
    strcpy((char *)(*(int *)(param_1 + 0x474) + 0xd48),param_5);
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0xd68) = 0;
    (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,param_4,param_6);
    strcpy((char *)(*(int *)(param_1 + 0x474) + 0xd70),param_5);
    *(int *)(*(int *)(param_1 + 0x474) + 0xd90) = param_3;
    piVar3 = *(int **)(param_1 + 0x474);
    if (*(int *)(*piVar3 + 0x20c) == 8) {
      Spy_DisguiseExternalWeaponModel__11CBasePlayer(piVar3);
      piVar3 = *(int **)(param_1 + 0x474);
    }
    uVar2 = 1;
    piVar3[0x196] = 0x3f000000;
    *(undefined4 *)(param_1 + 0x490) = 0x3f800000;
  }
  return uVar2;
}


