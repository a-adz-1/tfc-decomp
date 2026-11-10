// GiveTFAmmo__11CBasePlayeriiii  @ 000dc558
undefined4
GiveTFAmmo__11CBasePlayeriiii(undefined4 *param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_2 + param_1[0x33];
  param_1[0x33] = iVar2;
  if ((int)param_1[0x30] < iVar2) {
    param_2 = param_2 - (iVar2 - param_1[0x30]);
    param_1[0x33] = param_1[0x30];
  }
  iVar2 = param_3 + param_1[0x35];
  param_1[0x35] = iVar2;
  if ((int)param_1[0x34] < iVar2) {
    param_3 = param_3 - (iVar2 - param_1[0x34]);
    param_1[0x35] = param_1[0x34];
  }
  iVar2 = param_4 + param_1[0x39];
  param_1[0x39] = iVar2;
  if ((int)param_1[0x38] < iVar2) {
    param_4 = param_4 - (iVar2 - param_1[0x38]);
    param_1[0x39] = param_1[0x38];
  }
  iVar2 = param_5 + param_1[0x37];
  param_1[0x37] = iVar2;
  if ((int)param_1[0x36] < iVar2) {
    param_5 = param_5 - (iVar2 - param_1[0x36]);
    param_1[0x37] = param_1[0x36];
  }
  if ((((param_2 == 0) && (param_5 == 0)) && (param_3 == 0)) && (param_4 == 0)) {
    uVar1 = 0;
  }
  else {
    SendAmmoPickupMessage__FP9entvars_sPci(*param_1,"buckshot",param_2);
    SendAmmoPickupMessage__FP9entvars_sPci(*param_1,&UNK_0014ac9c,param_3);
    SendAmmoPickupMessage__FP9entvars_sPci(*param_1,"rockets",param_4);
    SendAmmoPickupMessage__FP9entvars_sPci(*param_1,"uranium",param_5);
    uVar1 = 1;
  }
  return uVar1;
}


