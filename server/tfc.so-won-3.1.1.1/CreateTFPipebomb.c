// CreateTFPipebomb__10CTFGrenadeG6VectorT1P11CBaseEntityP18CTFGrenadeLauncher  @ 00103c64
int * CreateTFPipebomb__10CTFGrenadeG6VectorT1P11CBaseEntityP18CTFGrenadeLauncher
                (undefined4 param_1,undefined4 *param_2,int *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  int local_c;
  
  piVar1 = (int *)GetClassPtr__H1Z10CTFGrenade_PX01_PX01(0);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar1,param_1);
  iVar3 = *piVar1;
  *(undefined4 *)(iVar3 + 0x50) = *param_2;
  *(undefined4 *)(iVar3 + 0x54) = param_2[1];
  *(undefined4 *)(iVar3 + 0x58) = param_2[2];
  (**(code **)(piVar1[0x115] + 0xc))(piVar1);
  piVar1[5] = -0x10000;
  piVar1[6] = (int)BounceTouch__8CGrenadeP11CBaseEntity;
  *(undefined4 *)(*piVar1 + 0x198) = *(undefined4 *)(*param_3 + 0x208);
  piVar1[0x48] = param_3[0x48];
  *(int *)*piVar1 = (int)"tf_gl_pipebomb" - (int)gpGlobals[0x26];
  local_c = *piVar1;
  piVar1[0xfe] = (int)"pipebomb" - (int)gpGlobals[0x26];
  iVar3 = 0x14;
  bVar6 = true;
  pcVar4 = (char *)(*(int *)(local_c + 0xb8) + (int)gpGlobals[0x26]);
  pcVar5 = "models/pipebomb.mdl";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    *(undefined4 *)(local_c + 0x110) = 0;
    local_c = *piVar1;
  }
  *(float *)(local_c + 0x104) = *gpGlobals + 120.0;
  piVar1[3] = -0x10000;
  piVar1[4] = (int)PipebombDetonate__10CTFGrenade;
  piVar1[0x1af] = (int)*gpGlobals;
  (*DAT_0019f758)(0,0x17,0,0);
  (*DAT_0019f760)(0x16);
  uVar2 = (*DAT_0019f7bc)(*(undefined4 *)(*piVar1 + 0x208));
  (*DAT_0019f768)(uVar2);
  (*DAT_0019f768)(piVar1[0x1ae]);
  (*DAT_0019f760)(10);
  (*DAT_0019f760)(5);
  (*DAT_0019f760)(0xe0);
  (*DAT_0019f760)(0xe0);
  (*DAT_0019f760)(0xff);
  (*DAT_0019f760)(0x50);
  (*DAT_0019f75c)();
  iVar3 = (**(code **)(param_3[0x115] + 0x2c))(param_3);
  if (iVar3 == 2) {
    iVar3 = param_3[0x36c];
    param_3[0x36c] = iVar3 + 1;
    if (8 < iVar3 + 1) {
      ExplodeOldPipebomb__11CBasePlayerii(param_3,0,1);
    }
  }
  return piVar1;
}


