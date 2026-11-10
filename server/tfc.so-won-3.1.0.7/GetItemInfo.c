// GetItemInfo__10CTFMedikitP8ItemInfo  @ 00128eb4
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
  param_1[0x11b] = 3;
  param_2[10] = 0;
  return 1;
}


// GetItemInfo__10CTFNailgunP8ItemInfo  @ 0012ad14
undefined4 GetItemInfo__10CTFNailgunP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = &DAT_00156172;
  if (param_1[0x119] == 0) {
    param_2[3] = 200;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0x119] + 0xd0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0;
  *param_2 = 3;
  param_2[1] = 4;
  param_1[0x11b] = 10;
  param_2[8] = 10;
  param_2[9] = 0;
  param_2[10] = 0xf;
  return 1;
}


// GetItemInfo__10CTFRailgunP8ItemInfo  @ 0012b6a8
undefined4 GetItemInfo__10CTFRailgunP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = &DAT_00156275;
  if (param_1[0x119] == 0) {
    param_2[3] = 0x32;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0x119] + 0xd0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 1;
  param_2[1] = 2;
  param_2[9] = 0;
  param_1[0x11b] = 0x15;
  param_2[8] = 0x15;
  param_2[10] = 10;
  return 1;
}


// GetItemInfo__10CTFShotgunP8ItemInfo  @ 0012c594
undefined4 GetItemInfo__10CTFShotgunP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "buckshot";
  if (param_1[0x119] == 0) {
    param_2[3] = 200;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0x119] + 0xc0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = param_1[0x132];
  *param_2 = 1;
  param_2[1] = 3;
  param_2[9] = 0;
  param_1[0x11b] = 8;
  param_2[8] = 8;
  param_2[10] = 0xf;
  return 1;
}


// GetItemInfo__10CTFSpannerP8ItemInfo  @ 00127800
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
  param_1[0x11b] = 4;
  param_2[10] = 0;
  return 1;
}


// GetItemInfo__11CTFAssaultCP8ItemInfo  @ 00125d4c
undefined4 GetItemInfo__11CTFAssaultCP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "buckshot";
  if (param_1[0x119] == 0) {
    param_2[3] = 200;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0x119] + 0xc0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 4;
  param_2[1] = 3;
  param_2[9] = 0;
  param_1[0x11b] = 0x11;
  param_2[8] = 0x11;
  param_2[10] = 0xf;
  return 1;
}


// GetItemInfo__12CHandGrenadeP8ItemInfo  @ 000b5778
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
  param_1[0x11b] = 0xc;
  param_2[8] = 0xc;
  param_2[10] = 5;
  param_2[9] = 0x18;
  return 1;
}


// GetItemInfo__12CTFAutoRifleP8ItemInfo  @ 00126684
undefined4 GetItemInfo__12CTFAutoRifleP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "buckshot";
  if (param_1[0x119] == 0) {
    param_2[3] = 0x4b;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0x119] + 0xc0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 2;
  param_2[1] = 1;
  param_1[0x11b] = 7;
  param_2[8] = 7;
  param_2[9] = 0;
  param_2[10] = 10;
  return 1;
}


// GetItemInfo__13CWeaponCyclerP8ItemInfo  @ 000b5470
undefined4 GetItemInfo__13CWeaponCyclerP8ItemInfo(void)

{
  return 0;
}


// GetItemInfo__14CTFIncendiaryCP8ItemInfo  @ 0012a63c
undefined4 GetItemInfo__14CTFIncendiaryCP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "rockets";
  if (param_1[0x119] == 0) {
    param_2[3] = 0x14;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0x119] + 0xe0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 4;
  param_2[1] = 2;
  param_1[0x11b] = 0xf;
  param_2[8] = 0xf;
  param_2[9] = 0;
  param_2[10] = 0x14;
  return 1;
}


// GetItemInfo__14CTFSniperRifleP8ItemInfo  @ 0012d300
undefined4 GetItemInfo__14CTFSniperRifleP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "buckshot";
  if (param_1[0x119] == 0) {
    param_2[3] = 0x4b;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0x119] + 0xc0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 1;
  param_2[1] = 1;
  param_2[8] = 6;
  param_1[0x11b] = 6;
  param_2[9] = 0;
  param_2[10] = 10;
  return 1;
}


// GetItemInfo__15CBasePlayerItemP8ItemInfo  @ 00122010
undefined4 GetItemInfo__15CBasePlayerItemP8ItemInfo(void)

{
  return 0;
}


// GetItemInfo__15CTFFlamethrowerP8ItemInfo  @ 001292f8
undefined4 GetItemInfo__15CTFFlamethrowerP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "uranium";
  if (param_1[0x119] == 0) {
    param_2[3] = 200;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0x119] + 0xd8);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 3;
  param_2[1] = 2;
  param_1[0x11b] = 0xd;
  param_2[8] = 0xd;
  param_2[9] = 0;
  param_2[10] = 0x14;
  return 1;
}


// GetItemInfo__15CTFSuperNailgunP8ItemInfo  @ 0012b3c0
undefined4 GetItemInfo__15CTFSuperNailgunP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = &DAT_00156172;
  if (param_1[0x119] == 0) {
    param_2[3] = 0x96;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0x119] + 0xd0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0;
  *param_2 = 3;
  param_2[1] = 1;
  param_1[0x11b] = 0xb;
  param_2[8] = 0xb;
  param_2[9] = 0;
  param_2[10] = 0xf;
  return 1;
}


// GetItemInfo__15CTFSuperShotgunP8ItemInfo  @ 0012cdb8
undefined4 GetItemInfo__15CTFSuperShotgunP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "buckshot";
  if (param_1[0x119] == 0) {
    param_2[3] = 200;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0x119] + 0xc0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = param_1[0x132];
  *param_2 = 2;
  param_2[1] = 2;
  param_2[9] = 0;
  param_1[0x11b] = 9;
  param_2[8] = 9;
  param_2[10] = 0xf;
  return 1;
}


// GetItemInfo__18CTFGrenadeLauncherP8ItemInfo  @ 00129a40
undefined4 GetItemInfo__18CTFGrenadeLauncherP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "rockets";
  if (param_1[0x119] == 0) {
    param_2[3] = 0x32;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0x119] + 0xe0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 6;
  *param_2 = 3;
  param_2[1] = 3;
  param_1[0x11b] = 0xc;
  param_2[8] = 0xc;
  param_2[9] = 0;
  param_2[10] = 0xf;
  return 1;
}


// GetItemInfo__19CTFPipebombLauncherP8ItemInfo  @ 0012a348
undefined4 GetItemInfo__19CTFPipebombLauncherP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "rockets";
  if (param_1[0x119] == 0) {
    param_2[3] = 0x32;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0x119] + 0xe0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 6;
  *param_2 = 4;
  param_2[1] = 4;
  param_1[0x11b] = 0x16;
  param_2[8] = 0x16;
  param_2[9] = 0;
  param_2[10] = 0xf;
  return 1;
}


// GetItemInfo__6CTFAxeP8ItemInfo  @ 00126d78
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
  param_1[0x11b] = 5;
  param_2[10] = 0;
  return 1;
}


// GetItemInfo__6CTFRpgP8ItemInfo  @ 0012bd30
undefined4 GetItemInfo__6CTFRpgP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "rockets";
  if (param_1[0x119] == 0) {
    param_2[3] = 0x32;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0x119] + 0xe0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 4;
  *param_2 = 4;
  param_2[1] = 1;
  param_1[0x11b] = 0xe;
  param_2[8] = 0xe;
  param_2[9] = 0;
  param_2[10] = 0x14;
  return 1;
}


// GetItemInfo__8CCrowbarP8ItemInfo  @ 00097dcc
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


// GetItemInfo__8CTFKnifeP8ItemInfo  @ 00127a90
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
  param_1[0x11b] = 0x17;
  param_2[10] = 0;
  return 1;
}


// GetItemInfo__8CTFTranqP8ItemInfo  @ 0012e1d0
undefined4 GetItemInfo__8CTFTranqP8ItemInfo(undefined4 *param_1,undefined4 *param_2)

{
  param_2[6] = *(int *)*param_1 + *(int *)(gpGlobals + 0x98);
  param_2[2] = "buckshot";
  if (param_1[0x119] == 0) {
    param_2[3] = 0x28;
  }
  else {
    param_2[3] = *(undefined4 *)(param_1[0x119] + 0xc0);
  }
  param_2[4] = 0;
  param_2[5] = 0xffffffff;
  param_2[7] = 0xffffffff;
  *param_2 = 1;
  param_2[1] = 4;
  param_2[9] = 0;
  param_1[0x11b] = 0x14;
  param_2[8] = 0x14;
  param_2[10] = 10;
  return 1;
}


