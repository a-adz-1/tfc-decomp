// GiveAmmo__10CWeaponBoxiPciPi  @ 00111dc0
int GiveAmmo__10CWeaponBoxiPciPi(int param_1,int param_2,char *param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *local_4;
  
  iVar3 = 1;
  local_4 = (int *)(param_1 + 0x47c);
  iVar2 = 4;
  do {
    if (0x1f < iVar3) {
LAB_00111ebc:
      (*DAT_001a7f34)(1,"out of named ammo slots\n");
      return iVar3;
    }
    iVar1 = *(int *)(iVar2 + 0x3f8 + param_1);
    if (iVar1 == 0) {
      if (iVar3 < 0x20) {
        if (param_5 != (int *)0x0) {
          *param_5 = iVar3;
        }
        *(int *)(iVar3 * 4 + 0x3f8 + param_1) = (int)param_3 - *(int *)(gpGlobals + 0x98);
        *(int *)(iVar3 * 4 + 0x478 + param_1) = param_2;
        return iVar3;
      }
      goto LAB_00111ebc;
    }
    iVar1 = strcasecmp(param_3,(char *)(iVar1 + *(int *)(gpGlobals + 0x98)));
    if (iVar1 == 0) {
      if (param_5 != (int *)0x0) {
        *param_5 = iVar3;
      }
      iVar2 = param_4 - *local_4;
      if (param_2 < param_4 - *local_4) {
        iVar2 = param_2;
      }
      if ((param_2 != 0) && (iVar2 < 1)) {
        return -1;
      }
      *local_4 = *local_4 + iVar2;
      return iVar3;
    }
    local_4 = local_4 + 1;
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + 1;
  } while( true );
}


// GiveAmmo__11CBaseEntityiPciPi  @ 001006f4
undefined4 GiveAmmo__11CBaseEntityiPciPi(void)

{
  return 0xffffffff;
}


// GiveAmmo__11CBasePlayeriPciPi  @ 000d0d78
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
    param_4 = param_4 - *(int *)(param_1 + 0x850 + uVar3 * 4);
    if (param_2 < param_4) {
      param_4 = param_2;
    }
    if ((0 < param_4) &&
       (piVar1 = (int *)(param_1 + 0x850 + uVar3 * 4), *piVar1 = *piVar1 + param_4,
       param_5 != (uint *)0x0)) {
      *param_5 = uVar3;
    }
  }
  return uVar3;
}


