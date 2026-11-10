// Throw__15CTFPrimeGrenade  @ 000fc870
void Throw__15CTFPrimeGrenade(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  int *piVar10;
  longdouble lVar11;
  longdouble lVar12;
  
  iVar9 = *(int *)(*param_1 + 0x178);
  if (iVar9 == 0) {
    iVar9 = (*DAT_001755d4)(0);
    if (iVar9 == 0) {
      piVar10 = (int *)0x0;
      goto LAB_000fc8a2;
    }
  }
  piVar10 = *(int **)(iVar9 + 0xd8);
LAB_000fc8a2:
  (**(code **)(param_1[0xf2] + 8))(param_1);
  UTIL_MakeVectors__FRC6Vector(*piVar10 + 0x74);
  iVar9 = *param_1;
  fVar1 = gpGlobals[10];
  fVar2 = gpGlobals[0xb];
  fVar3 = gpGlobals[0xc];
  lVar11 = (longdouble)(*DAT_0017562c)(0xc1200000,0x41200000);
  lVar11 = (longdouble)200.0 + lVar11;
  fVar4 = gpGlobals[0xd];
  fVar5 = gpGlobals[0xe];
  fVar6 = gpGlobals[0xf];
  lVar12 = (longdouble)(*DAT_0017562c)(0xc1200000,0x41200000);
  fVar7 = gpGlobals[0x11];
  fVar8 = gpGlobals[0x12];
  *(float *)(iVar9 + 0x20) =
       (float)((longdouble)(float)((longdouble)(fVar1 * 600.0) + lVar11 * (longdouble)fVar4) +
              lVar12 * (longdouble)gpGlobals[0x10]);
  *(float *)(iVar9 + 0x24) =
       (float)((longdouble)(float)((longdouble)(fVar2 * 600.0) + lVar11 * (longdouble)fVar5) +
              lVar12 * (longdouble)fVar7);
  *(float *)(iVar9 + 0x28) =
       fVar3 * 600.0 + (float)(lVar11 * (longdouble)fVar6) + (float)(lVar12 * (longdouble)fVar8);
  iVar9 = *param_1;
  *(undefined4 *)(iVar9 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar9 + 0x60) = DAT_00175484;
  *(undefined4 *)(iVar9 + 100) = DAT_00175488;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*piVar10 + 8);
  param_1[5] = -0x10000;
  param_1[6] = (int)BounceTouch__8CGrenadeP11CBaseEntity;
  *(int *)(*param_1 + 0x1c4) = param_1[0x189];
  param_1[3] = -0x10000;
  param_1[4] = (int)TumbleThink__8CGrenade;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  *(undefined4 *)(*param_1 + 0x118) = 0x3f800000;
  *(undefined4 *)(*param_1 + 0xfc) = 0x3f4f5c29;
  *(undefined4 *)(*param_1 + 0x100) = 0x3f19999a;
  return;
}


