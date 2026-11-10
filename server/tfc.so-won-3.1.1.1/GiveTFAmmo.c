// GiveTFAmmo__11CBasePlayeriiii  @ 000db444
undefined4
GiveTFAmmo__11CBasePlayeriiii(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = param_2 + param_1[0x33];
  param_1[0x33] = iVar1;
  iVar3 = param_1[0x30];
  if (iVar3 < iVar1) {
    param_2 = param_2 - (iVar1 - iVar3);
    param_1[0x33] = iVar3;
  }
  iVar1 = param_3 + param_1[0x35];
  param_1[0x35] = iVar1;
  iVar3 = param_1[0x34];
  if (iVar3 < iVar1) {
    param_3 = param_3 - (iVar1 - iVar3);
    param_1[0x35] = iVar3;
  }
  iVar1 = param_4 + param_1[0x39];
  param_1[0x39] = iVar1;
  iVar3 = param_1[0x38];
  if (iVar3 < iVar1) {
    param_4 = param_4 - (iVar1 - iVar3);
    param_1[0x39] = iVar3;
  }
  iVar1 = param_5 + param_1[0x37];
  param_1[0x37] = iVar1;
  iVar3 = param_1[0x36];
  if (iVar3 < iVar1) {
    param_5 = param_5 - (iVar1 - iVar3);
    param_1[0x37] = iVar3;
  }
  if ((((param_2 == 0) && (param_5 == 0)) && (param_3 == 0)) && (param_4 == 0)) {
    uVar2 = 0;
  }
  else {
    iVar3 = *param_1;
    if (0 < param_2) {
      (*DAT_0019f758)(1,gmsgAmmoPickup,0,*(undefined4 *)(iVar3 + 0x208));
      uVar2 = GetAmmoIndex__11CBasePlayerPCc("buckshot");
      (*DAT_0019f760)(uVar2);
      (*DAT_0019f760)(param_2);
      (*DAT_0019f75c)();
      iVar3 = *param_1;
    }
    if (0 < param_3) {
      (*DAT_0019f758)(1,gmsgAmmoPickup,0,*(undefined4 *)(iVar3 + 0x208));
      uVar2 = GetAmmoIndex__11CBasePlayerPCc(&DAT_0014fffc);
      (*DAT_0019f760)(uVar2);
      (*DAT_0019f760)(param_3);
      (*DAT_0019f75c)();
      iVar3 = *param_1;
    }
    if (0 < param_4) {
      (*DAT_0019f758)(1,gmsgAmmoPickup,0,*(undefined4 *)(iVar3 + 0x208));
      uVar2 = GetAmmoIndex__11CBasePlayerPCc("rockets");
      (*DAT_0019f760)(uVar2);
      (*DAT_0019f760)(param_4);
      (*DAT_0019f75c)();
      iVar3 = *param_1;
    }
    if (0 < param_5) {
      (*DAT_0019f758)(1,gmsgAmmoPickup,0,*(undefined4 *)(iVar3 + 0x208));
      uVar2 = GetAmmoIndex__11CBasePlayerPCc("uranium");
      (*DAT_0019f760)(uVar2);
      (*DAT_0019f760)(param_5);
      (*DAT_0019f75c)();
    }
    uVar2 = 1;
  }
  return uVar2;
}


