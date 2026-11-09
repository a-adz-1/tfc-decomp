// GiveTFAmmo__11CBasePlayeriiii  @ 000de270
undefined4
GiveTFAmmo__11CBasePlayeriiii(undefined4 *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_2 + param_1[0x33];
  param_1[0x33] = iVar1;
  if ((int)param_1[0x30] < iVar1) {
    param_2 = param_2 - (iVar1 - param_1[0x30]);
    param_1[0x33] = param_1[0x30];
  }
  iVar1 = param_3 + param_1[0x35];
  param_1[0x35] = iVar1;
  if ((int)param_1[0x34] < iVar1) {
    param_3 = param_3 - (iVar1 - param_1[0x34]);
    param_1[0x35] = param_1[0x34];
  }
  iVar1 = param_4 + param_1[0x39];
  param_1[0x39] = iVar1;
  if ((int)param_1[0x38] < iVar1) {
    param_4 = param_4 - (iVar1 - param_1[0x38]);
    param_1[0x39] = param_1[0x38];
  }
  iVar1 = param_5 + param_1[0x37];
  param_1[0x37] = iVar1;
  if ((int)param_1[0x36] < iVar1) {
    param_5 = param_5 - (iVar1 - param_1[0x36]);
    param_1[0x37] = param_1[0x36];
  }
  if ((((param_2 == 0) && (param_5 == 0)) && (param_3 == 0)) && (param_4 == 0)) {
    uVar2 = 0;
  }
  else {
    SendAmmoPickupMessage__FP9entvars_tPci(*param_1,"buckshot",param_2);
    SendAmmoPickupMessage__FP9entvars_tPci(*param_1,&DAT_001395c0,param_3);
    SendAmmoPickupMessage__FP9entvars_tPci(*param_1,"rockets",param_4);
    SendAmmoPickupMessage__FP9entvars_tPci(*param_1,"uranium",param_5);
    uVar2 = 1;
  }
  return uVar2;
}


