// PackWeapon__10CWeaponBoxP15CBasePlayerItem  @ 0011c5a0
undefined4 PackWeapon__10CWeaponBoxP15CBasePlayerItem(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = HasWeapon__10CWeaponBoxP15CBasePlayerItem(param_1,param_2);
  if (iVar1 == 0) {
    if (param_2[0xfa] != 0) {
      iVar1 = (**(code **)(*(int *)(param_2[0xfa] + 0x3c8) + 0x5c))(param_2[0xfa],param_2);
      if (iVar1 == 0) goto LAB_0011c5dd;
    }
    iVar1 = (**(code **)(param_2[0xf2] + 0x10c))(param_2);
    if (param_1[iVar1 + 0xf3] == 0) {
      param_1[iVar1 + 0xf3] = (int)param_2;
      param_2[0xfb] = 0;
    }
    else {
      param_2[0xfb] = param_1[iVar1 + 0xf3];
      param_1[iVar1 + 0xf3] = (int)param_2;
    }
    *(byte *)(*param_2 + 0x183) = *(byte *)(*param_2 + 0x183) | 0x40;
    *(undefined4 *)(*param_2 + 0xe8) = 0;
    *(undefined4 *)(*param_2 + 0xec) = 0;
    *(undefined4 *)(*param_2 + 0xf8) = 0x80;
    *(undefined4 *)(*param_2 + 0x94) = 0;
    *(undefined4 *)(*param_2 + 0x98) = 0;
    *(undefined4 *)(*param_2 + 0x178) = *(undefined4 *)(*param_1 + 0x1e8);
    param_2[3] = 0;
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[0xfa] = 0;
    uVar2 = 1;
  }
  else {
LAB_0011c5dd:
    uVar2 = 0;
  }
  return uVar2;
}


