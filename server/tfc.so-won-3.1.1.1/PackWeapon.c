// PackWeapon__10CWeaponBoxP15CBasePlayerItem  @ 0012496c
undefined4 PackWeapon__10CWeaponBoxP15CBasePlayerItem(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = HasWeapon__10CWeaponBoxP15CBasePlayerItem(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = param_2[0x11d];
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x60))(iVar1,param_2);
      if (iVar1 == 0) goto LAB_001249b0;
    }
    iVar1 = (**(code **)(param_2[0x115] + 0x114))(param_2);
    if (param_1[iVar1 + 0x116] == 0) {
      param_1[iVar1 + 0x116] = (int)param_2;
      param_2[0x11e] = 0;
    }
    else {
      param_2[0x11e] = param_1[iVar1 + 0x116];
      param_1[iVar1 + 0x116] = (int)param_2;
    }
    *(byte *)(*param_2 + 0x1a3) = *(byte *)(*param_2 + 0x1a3) | 0x40;
    *(undefined4 *)(*param_2 + 0x108) = 0;
    *(undefined4 *)(*param_2 + 0x10c) = 0;
    *(undefined4 *)(*param_2 + 0x118) = 0x80;
    *(undefined4 *)(*param_2 + 0xb4) = 0;
    *(undefined4 *)(*param_2 + 0xb8) = 0;
    *(undefined4 *)(*param_2 + 0x198) = *(undefined4 *)(*param_1 + 0x208);
    param_2[3] = 0;
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[0x11d] = 0;
    uVar2 = 1;
  }
  else {
LAB_001249b0:
    uVar2 = 0;
  }
  return uVar2;
}


