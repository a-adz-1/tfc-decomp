// CreateTFPipebomb__10CTFGrenadeG6VectorT1P11CBaseEntityP18CTFGrenadeLauncher  @ 000fb000
int * CreateTFPipebomb__10CTFGrenadeG6VectorT1P11CBaseEntityP18CTFGrenadeLauncher
                (undefined4 param_1,undefined4 *param_2,int *param_3)

{
  float *pfVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
  piVar2 = (int *)GetClassPtr__H1Z10CTFGrenade_PX01_PX01(0);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*piVar2,param_1);
  iVar4 = *piVar2;
  *(undefined4 *)(iVar4 + 0x50) = *param_2;
  *(undefined4 *)(iVar4 + 0x54) = param_2[1];
  *(undefined4 *)(iVar4 + 0x58) = param_2[2];
  (**(code **)(piVar2[0xf2] + 8))(piVar2);
  piVar2[5] = -0x10000;
  piVar2[6] = (int)BounceTouch__8CGrenadeP11CBaseEntity;
  *(undefined4 *)(*piVar2 + 0x178) = *(undefined4 *)(*param_3 + 0x1e8);
  piVar2[0x48] = param_3[0x48];
  pfVar1 = gpGlobals;
  *(int *)*piVar2 = (int)"tf_gl_pipebomb" - (int)gpGlobals[0x26];
  piVar2[0xdb] = (int)"pipebomb" - (int)pfVar1[0x26];
  iVar4 = 0x14;
  bVar7 = true;
  pcVar5 = (char *)((int)pfVar1[0x26] + *(int *)(*piVar2 + 0x98));
  pcVar6 = "models/pipebomb.mdl";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar7 = *pcVar5 == *pcVar6;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    *(undefined4 *)(*piVar2 + 0xf0) = 0;
  }
  pfVar1 = gpGlobals;
  *(float *)(*piVar2 + 0xe4) = *gpGlobals + 120.0;
  piVar2[3] = -0x10000;
  piVar2[4] = (int)PipebombDetonate__10CTFGrenade;
  piVar2[0x18a] = (int)*pfVar1;
  (*DAT_00175578)(0,0x17,0,0);
  (*DAT_00175580)(0x16);
  uVar3 = (*DAT_001755dc)(*(undefined4 *)(*piVar2 + 0x1e8));
  (*DAT_00175588)(uVar3);
  (*DAT_00175588)(piVar2[0x189]);
  (*DAT_00175580)(10);
  (*DAT_00175580)(5);
  (*DAT_00175580)(0xe0);
  (*DAT_00175580)(0xe0);
  (*DAT_00175580)(0xff);
  (*DAT_00175580)(0x50);
  (*DAT_0017557c)();
  iVar4 = (**(code **)(param_3[0xf2] + 0x28))(param_3);
  if ((iVar4 == 2) && (param_3[0x339] = param_3[0x339] + 1, 8 < param_3[0x339])) {
    ExplodeOldPipebomb__11CBasePlayeri(param_3,0);
  }
  return piVar2;
}


