// GetItemInfo__10CTFMedikitP8ItemInfo  @ 000fa230
undefined4 GetItemInfo__10CTFMedikitP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = 0;
  param_2[3] = 0xffffffff;
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 0;
  param_2[1] = 1;
  param_2[8] = 3;
  param_1[0xfc] = 3;
  param_2[10] = 0;
  return 1;
}


// GetItemInfo__10CTFNailgunP8ItemInfo  @ 001004c0
undefined4 GetItemInfo__10CTFNailgunP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = &DAT_001450e0;
  if (param_1[0xfa] == 0) {
    param_2[3] = 200;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0xfa] + 0xd0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0;
  *param_2 = 3;
  param_2[1] = 4;
  param_1[0xfc] = 10;
  param_2[8] = 10;
  param_2[9] = 0;
  param_2[10] = 0xf;
  return 1;
}


// GetItemInfo__10CTFRailgunP8ItemInfo  @ 00100d50
undefined4 GetItemInfo__10CTFRailgunP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = &DAT_00145726;
  if (param_1[0xfa] == 0) {
    param_2[3] = 0x32;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0xfa] + 0xd0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 1;
  param_2[1] = 2;
  param_2[9] = 0;
  param_1[0xfc] = 0x15;
  param_2[8] = 0x15;
  param_2[10] = 10;
  return 1;
}


// GetItemInfo__10CTFShotgunP8ItemInfo  @ 00102050
undefined4 GetItemInfo__10CTFShotgunP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "buckshot";
  if (param_1[0xfa] == 0) {
    param_2[3] = 200;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0xfa] + 0xc0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = param_1[0x10e];
  *param_2 = 1;
  param_2[1] = 3;
  param_2[9] = 0;
  param_1[0xfc] = 8;
  param_2[8] = 8;
  param_2[10] = 0xf;
  return 1;
}


// GetItemInfo__10CTFSpannerP8ItemInfo  @ 000f9560
undefined4 GetItemInfo__10CTFSpannerP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "uranium";
  param_2[3] = 0xffffffff;
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 0;
  param_2[1] = 2;
  param_2[8] = 4;
  param_1[0xfc] = 4;
  param_2[10] = 0;
  return 1;
}


// GetItemInfo__11CTFAssaultCP8ItemInfo  @ 000f7670
undefined4 GetItemInfo__11CTFAssaultCP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "buckshot";
  if (param_1[0xfa] == 0) {
    param_2[3] = 200;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0xfa] + 0xc0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 4;
  param_2[1] = 3;
  param_2[9] = 0;
  param_1[0xfc] = 0x11;
  param_2[8] = 0x11;
  param_2[10] = 0xf;
  return 1;
}


// GetItemInfo__12CHandGrenadeP8ItemInfo  @ 000bc5b0
undefined4 GetItemInfo__12CHandGrenadeP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "Hand Grenade";
  param_2[3] = 10;
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 4;
  param_2[1] = 0;
  param_1[0xfc] = 0xc;
  param_2[8] = 0xc;
  param_2[10] = 5;
  param_2[9] = 0x18;
  return 1;
}


// GetItemInfo__12CTFAutoRifleP8ItemInfo  @ 000f8240
undefined4 GetItemInfo__12CTFAutoRifleP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "buckshot";
  if (param_1[0xfa] == 0) {
    param_2[3] = 0x4b;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0xfa] + 0xc0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 2;
  param_2[1] = 1;
  param_1[0xfc] = 7;
  param_2[8] = 7;
  param_2[9] = 0;
  param_2[10] = 10;
  return 1;
}


// GetItemInfo__13CWeaponCyclerP8ItemInfo  @ 000bc3a0
undefined4 GetItemInfo__13CWeaponCyclerP8ItemInfo(void)

{
  return 0;
}


// GetItemInfo__14CTFIncendiaryCP8ItemInfo  @ 000ff6f0
undefined4 GetItemInfo__14CTFIncendiaryCP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "rockets";
  if (param_1[0xfa] == 0) {
    param_2[3] = 0x14;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0xfa] + 0xe0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 4;
  param_2[1] = 2;
  param_1[0xfc] = 0xf;
  param_2[8] = 0xf;
  param_2[9] = 0;
  param_2[10] = 0x14;
  return 1;
}


// GetItemInfo__14CTFSniperRifleP8ItemInfo  @ 001032c0
undefined4 GetItemInfo__14CTFSniperRifleP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "buckshot";
  if (param_1[0xfa] == 0) {
    param_2[3] = 0x4b;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0xfa] + 0xc0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 1;
  param_2[1] = 1;
  param_2[8] = 6;
  param_1[0xfc] = 6;
  param_2[9] = 0;
  param_2[10] = 10;
  return 1;
}


// GetItemInfo__15CBasePlayerItemP8ItemInfo  @ 0011cc70
undefined4 GetItemInfo__15CBasePlayerItemP8ItemInfo(void)

{
  return 0;
}


// GetItemInfo__15CTFFlamethrowerP8ItemInfo  @ 000fa870
undefined4 GetItemInfo__15CTFFlamethrowerP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "uranium";
  if (param_1[0xfa] == 0) {
    param_2[3] = 200;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0xfa] + 0xd8);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 3;
  param_2[1] = 2;
  param_1[0xfc] = 0xd;
  param_2[8] = 0xd;
  param_2[9] = 0;
  param_2[10] = 0x14;
  return 1;
}


// GetItemInfo__15CTFSuperNailgunP8ItemInfo  @ 00100b30
undefined4 GetItemInfo__15CTFSuperNailgunP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = &DAT_001450e0;
  if (param_1[0xfa] == 0) {
    param_2[3] = 0x96;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0xfa] + 0xd0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0;
  *param_2 = 3;
  param_2[1] = 1;
  param_1[0xfc] = 0xb;
  param_2[8] = 0xb;
  param_2[9] = 0;
  param_2[10] = 0xf;
  return 1;
}


// GetItemInfo__15CTFSuperShotgunP8ItemInfo  @ 00102aa0
undefined4 GetItemInfo__15CTFSuperShotgunP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "buckshot";
  if (param_1[0xfa] == 0) {
    param_2[3] = 200;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0xfa] + 0xc0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = param_1[0x10e];
  *param_2 = 2;
  param_2[1] = 2;
  param_2[9] = 0;
  param_1[0xfc] = 9;
  param_2[8] = 9;
  param_2[10] = 0xf;
  return 1;
}


// GetItemInfo__18CTFGrenadeLauncherP8ItemInfo  @ 000fb8a0
undefined4 GetItemInfo__18CTFGrenadeLauncherP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "rockets";
  if (param_1[0xfa] == 0) {
    param_2[3] = 0x32;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0xfa] + 0xe0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 6;
  *param_2 = 3;
  param_2[1] = 3;
  param_1[0xfc] = 0xc;
  param_2[8] = 0xc;
  param_2[9] = 0;
  param_2[10] = 0xf;
  return 1;
}


// GetItemInfo__19CTFPipebombLauncherP8ItemInfo  @ 000fc230
undefined4 GetItemInfo__19CTFPipebombLauncherP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "rockets";
  if (param_1[0xfa] == 0) {
    param_2[3] = 0x32;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0xfa] + 0xe0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 6;
  *param_2 = 4;
  param_2[1] = 4;
  param_1[0xfc] = 0x16;
  param_2[8] = 0x16;
  param_2[9] = 0;
  param_2[10] = 0xf;
  return 1;
}


// GetItemInfo__6CTFAxeP8ItemInfo  @ 000f8840
undefined4 GetItemInfo__6CTFAxeP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = 0;
  param_2[3] = 0xffffffff;
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 0;
  param_2[1] = 3;
  param_2[8] = 5;
  param_1[0xfc] = 5;
  param_2[10] = 0;
  return 1;
}


// GetItemInfo__6CTFRpgP8ItemInfo  @ 00101880
undefined4 GetItemInfo__6CTFRpgP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "rockets";
  if (param_1[0xfa] == 0) {
    param_2[3] = 0x32;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0xfa] + 0xe0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 4;
  *param_2 = 4;
  param_2[1] = 1;
  param_1[0xfc] = 0xe;
  param_2[8] = 0xe;
  param_2[9] = 0;
  param_2[10] = 0x14;
  return 1;
}


// GetItemInfo__8CCrowbarP8ItemInfo  @ 000a6570
undefined4 GetItemInfo__8CCrowbarP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = 0;
  param_2[3] = 0xffffffff;
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[8] = 1;
  param_2[10] = 0;
  return 1;
}


// GetItemInfo__8CTFKnifeP8ItemInfo  @ 000f9770
undefined4 GetItemInfo__8CTFKnifeP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = 0;
  param_2[3] = 0xffffffff;
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 0;
  param_2[1] = 4;
  param_2[8] = 0x17;
  param_1[0xfc] = 0x17;
  param_2[10] = 0;
  return 1;
}


// GetItemInfo__8CTFTranqP8ItemInfo  @ 00103ed0
undefined4 GetItemInfo__8CTFTranqP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "buckshot";
  if (param_1[0xfa] == 0) {
    param_2[3] = 0x28;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0xfa] + 0xc0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 1;
  param_2[1] = 4;
  param_2[9] = 0;
  param_1[0xfc] = 0x14;
  param_2[8] = 0x14;
  param_2[10] = 10;
  return 1;
}


