// CreateTFPipebomb__10CTFGrenadeG6VectorT1P11CBaseEntityP18CTFGrenadeLauncher  @ 000f41b4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  (**(code **)(piVar1[0xf5] + 8))(piVar1);
  piVar1[5] = -0x10000;
  piVar1[6] = (int)BounceTouch__8CGrenadeP11CBaseEntity;
  *(undefined4 *)(*piVar1 + 0x198) = *(undefined4 *)(*param_3 + 0x208);
  piVar1[0x48] = param_3[0x48];
  *(int *)*piVar1 = (int)"tf_gl_pipebomb" - (int)gpGlobals[0x26];
  piVar1[0xde] = (int)"pipebomb" - (int)gpGlobals[0x26];
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
  *(float *)(*piVar1 + 0x104) = _FUN_0013ebfc + *gpGlobals;
  piVar1[3] = -0x10000;
  piVar1[4] = (int)PipebombDetonate__10CTFGrenade;
  piVar1[399] = (int)*gpGlobals;
  (*DAT_001a7ef8)(0,0x17,0,0);
  (*DAT_001a7f00)(0x16);
  uVar2 = (*DAT_001a7f5c)(*(undefined4 *)(*piVar1 + 0x208));
  (*DAT_001a7f08)(uVar2);
  (*DAT_001a7f08)(piVar1[0x18e]);
  (*DAT_001a7f00)(10);
  (*DAT_001a7f00)(5);
  (*DAT_001a7f00)(0xe0);
  (*DAT_001a7f00)(0xe0);
  (*DAT_001a7f00)(0xff);
  (*DAT_001a7f00)(0x50);
  (*DAT_001a7efc)();
  iVar3 = (**(code **)(param_3[0xf5] + 0x28))(param_3);
  if (iVar3 == 2) {
    param_3[0x345] = param_3[0x345] + 1;
    if (8 < param_3[0x345]) {
      ExplodeOldPipebomb__11CBasePlayerii(param_3,0,1);
    }
  }
  return piVar1;
}


