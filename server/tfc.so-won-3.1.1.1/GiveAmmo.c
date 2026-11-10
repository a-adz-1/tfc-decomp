// GiveAmmo__10CWeaponBoxiPciPi  @ 00124e5c
int GiveAmmo__10CWeaponBoxiPciPi(int param_1,int param_2,char *param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  if (*(int *)(param_1 + 0x47c) != 0) {
    do {
      iVar1 = iVar3 * 4;
      iVar2 = strcasecmp(param_3,(char *)(*(int *)(iVar1 + param_1 + 0x478) +
                                         *(int *)(gpGlobals + 0x98)));
      if (iVar2 == 0) {
        if (param_5 != (int *)0x0) {
          *param_5 = iVar3;
        }
        iVar2 = *(int *)(iVar1 + param_1 + 0x4f8);
        param_4 = param_4 - iVar2;
        if (param_2 < param_4) {
          param_4 = param_2;
        }
        if ((param_2 != 0) && (param_4 < 1)) {
          return -1;
        }
        *(int *)(iVar1 + param_1 + 0x4f8) = iVar2 + param_4;
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      if (0x1f < iVar3) goto LAB_00124f70;
    } while (*(int *)(param_1 + 0x478 + iVar3 * 4) != 0);
  }
  if (iVar3 < 0x20) {
    if (param_5 != (int *)0x0) {
      *param_5 = iVar3;
    }
    *(int *)(iVar3 * 4 + param_1 + 0x478) = (int)param_3 - *(int *)(gpGlobals + 0x98);
    *(int *)(iVar3 * 4 + 0x4f8 + param_1) = param_2;
  }
  else {
LAB_00124f70:
    (*DAT_0019f794)(1,"out of named ammo slots\n");
  }
  return iVar3;
}


// GiveAmmo__11CBaseEntityiPciPi  @ 00112ee4
undefined4 GiveAmmo__11CBaseEntityiPciPi(void)

{
  return 0xffffffff;
}


// GiveAmmo__11CBasePlayeriPciPi  @ 000e5480
uint GiveAmmo__11CBasePlayeriPciPi(int param_1,int param_2,int param_3,int param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  
  if (((param_3 == 0) ||
      (iVar1 = (**(code **)(*g_pGameRules + 0xa8))(g_pGameRules,param_1,param_3,param_4), iVar1 == 0
      )) || (uVar2 = GetAmmoIndex__11CBasePlayerPCc(param_3), 0x1f < uVar2)) {
    return 0xffffffff;
  }
  iVar1 = *(int *)(uVar2 * 4 + param_1 + 0x8ec);
  param_4 = param_4 - iVar1;
  if (param_2 < param_4) {
    param_4 = param_2;
  }
  if (param_4 < 1) {
    return uVar2;
  }
  *(int *)(uVar2 * 4 + param_1 + 0x8ec) = iVar1 + param_4;
  if (param_5 == (uint *)0x0) {
    return uVar2;
  }
  *param_5 = uVar2;
  return uVar2;
}


