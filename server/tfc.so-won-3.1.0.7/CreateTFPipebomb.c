// CreateTFPipebomb__10CTFGrenadeG6VectorT1P11CBaseEntityP18CTFGrenadeLauncher  @ 00101930
int * CreateTFPipebomb__10CTFGrenadeG6VectorT1P11CBaseEntityP18CTFGrenadeLauncher
                (undefined4 param_1,undefined4 *param_2,int *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  piVar1 = (int *)GetClassPtr__H1Z10CTFGrenade_PX01_PX01(0);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar1,param_1);
  iVar3 = *piVar1;
  *(undefined4 *)(iVar3 + 0x50) = *param_2;
  *(undefined4 *)(iVar3 + 0x54) = param_2[1];
  *(undefined4 *)(iVar3 + 0x58) = param_2[2];
  (**(code **)(piVar1[0x111] + 0xc))(piVar1);
  piVar1[5] = -0x10000;
  piVar1[6] = (int)BounceTouch__8CGrenadeP11CBaseEntity;
  *(undefined4 *)(*piVar1 + 0x198) = *(undefined4 *)(*param_3 + 0x208);
  piVar1[0x48] = param_3[0x48];
  *(int *)*piVar1 = (int)"tf_gl_pipebomb" - (int)gpGlobals[0x26];
  piVar1[0xfa] = (int)"pipebomb" - (int)gpGlobals[0x26];
  iVar3 = 0x14;
  bVar6 = true;
  pcVar4 = (char *)((int)gpGlobals[0x26] + *(int *)(*piVar1 + 0xb8));
  pcVar5 = "models/pipebomb.mdl";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    *(undefined4 *)(*piVar1 + 0x110) = 0;
  }
  *(float *)(*piVar1 + 0x104) = *gpGlobals + 120.0;
  piVar1[3] = -0x10000;
  piVar1[4] = (int)PipebombDetonate__10CTFGrenade;
  piVar1[0x1ab] = (int)*gpGlobals;
  (*DAT_001c10d8)(0,0x17,0,0);
  (*DAT_001c10e0)(0x16);
  uVar2 = (*DAT_001c113c)(*(undefined4 *)(*piVar1 + 0x208));
  (*DAT_001c10e8)(uVar2);
  (*DAT_001c10e8)(piVar1[0x1aa]);
  (*DAT_001c10e0)(10);
  (*DAT_001c10e0)(5);
  (*DAT_001c10e0)(0xe0);
  (*DAT_001c10e0)(0xe0);
  (*DAT_001c10e0)(0xff);
  (*DAT_001c10e0)(0x50);
  (*DAT_001c10dc)();
  iVar3 = (**(code **)(param_3[0x111] + 0x2c))(param_3);
  if (iVar3 == 2) {
    param_3[0x365] = param_3[0x365] + 1;
    if (8 < param_3[0x365]) {
      ExplodeOldPipebomb__11CBasePlayerii(param_3,0,1);
    }
  }
  return piVar1;
}


