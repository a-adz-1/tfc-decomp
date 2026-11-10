// GiveAmmo__10CWeaponBoxiPciPi  @ 0011c740
int GiveAmmo__10CWeaponBoxiPciPi(int param_1,int param_2,char *param_3,int param_4,int *param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  do {
    if (0x1f < iVar3) {
LAB_0011c820:
      (*DAT_001755b4)(1,"out of named ammo slots\n");
      return iVar3;
    }
    iVar2 = *(int *)(param_1 + 0x3ec + iVar3 * 4);
    if (iVar2 == 0) {
      if (iVar3 < 0x20) {
        if (param_5 != (int *)0x0) {
          *param_5 = iVar3;
        }
        *(int *)(iVar3 * 4 + 0x3ec + param_1) = (int)param_3 - *(int *)(gpGlobals + 0x98);
        *(int *)(iVar3 * 4 + 0x46c + param_1) = param_2;
        return iVar3;
      }
      goto LAB_0011c820;
    }
    iVar2 = strcasecmp(param_3,(char *)(*(int *)(gpGlobals + 0x98) + iVar2));
    if (iVar2 == 0) {
      if (param_5 != (int *)0x0) {
        *param_5 = iVar3;
      }
      param_4 = param_4 - *(int *)(param_1 + 0x46c + iVar3 * 4);
      if (param_2 < param_4) {
        param_4 = param_2;
      }
      if ((param_2 != 0) && (param_4 < 1)) {
        return -1;
      }
      piVar1 = (int *)(param_1 + 0x46c + iVar3 * 4);
      *piVar1 = *piVar1 + param_4;
      return iVar3;
    }
    iVar3 = iVar3 + 1;
  } while( true );
}


// GiveAmmo__11CBaseEntityiPciPi  @ 0010e4a0
undefined4 GiveAmmo__11CBaseEntityiPciPi(void)

{
  return 0xffffffff;
}


// GiveAmmo__11CBasePlayeriPciPi  @ 000de180
uint GiveAmmo__11CBasePlayeriPciPi(int param_1,int param_2,int param_3,int param_4,uint *param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  if (((param_3 == 0) ||
      (iVar2 = (**(code **)(*g_pGameRules + 0xa8))(g_pGameRules,param_1,param_3,param_4), iVar2 == 0
      )) || (uVar3 = GetAmmoIndex__11CBasePlayerPCc(param_3), 0x1f < uVar3)) {
    uVar3 = 0xffffffff;
  }
  else {
    param_4 = param_4 - *(int *)(param_1 + 0x83c + uVar3 * 4);
    if (param_2 < param_4) {
      param_4 = param_2;
    }
    if ((0 < param_4) &&
       (piVar1 = (int *)(param_1 + 0x83c + uVar3 * 4), *piVar1 = *piVar1 + param_4,
       param_5 != (uint *)0x0)) {
      *param_5 = uVar3;
    }
  }
  return uVar3;
}


