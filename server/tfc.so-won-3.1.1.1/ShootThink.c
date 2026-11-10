// ShootThink__11CGibShooter  @ 000a1e34
void ShootThink__11CGibShooter(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int iVar11;
  int *piVar12;
  longdouble lVar13;
  longdouble lVar14;
  longdouble lVar15;
  longdouble lVar16;
  longdouble lVar17;
  longdouble lVar18;
  float local_34;
  float local_30;
  float local_2c;
  
  *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0x116];
  iVar7 = *param_1;
  fVar8 = *(float *)(iVar7 + 0x44);
  fVar9 = *(float *)(iVar7 + 0x48);
  fVar10 = *(float *)(iVar7 + 0x4c);
  lVar13 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
  fVar1 = gpGlobals[0x10];
  fVar2 = gpGlobals[0x11];
  fVar3 = gpGlobals[0x12];
  lVar14 = (longdouble)(float)param_1[0x11d];
  lVar15 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
  fVar4 = gpGlobals[10];
  fVar5 = gpGlobals[0xb];
  fVar6 = gpGlobals[0xc];
  lVar16 = (longdouble)(float)param_1[0x11d];
  lVar17 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
  lVar18 = (longdouble)(float)param_1[0x11d];
  local_34 = (float)((longdouble)gpGlobals[0xd] * lVar17 * lVar18 +
                    (longdouble)
                    (float)((longdouble)fVar4 * lVar15 * lVar16 +
                           (longdouble)
                           (float)((longdouble)fVar1 * lVar13 * lVar14 + (longdouble)fVar8)));
  local_30 = (float)((longdouble)gpGlobals[0xe] * lVar17 * lVar18 +
                    (longdouble)
                    (float)((longdouble)fVar5 * lVar15 * lVar16 +
                           (longdouble)
                           (float)((longdouble)fVar2 * lVar13 * lVar14 + (longdouble)fVar9)));
  fVar1 = (float)(lVar17 * (longdouble)gpGlobals[0xf] * lVar18 +
                 (longdouble)
                 (float)(lVar15 * (longdouble)fVar6 * lVar16 +
                        (longdouble)
                        (float)(lVar13 * (longdouble)fVar3 * lVar14 + (longdouble)fVar10)));
  local_2c = SQRT(fVar1 * fVar1 + local_30 * local_30 + local_34 * local_34);
  if ((byte)((byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_2c == 0.0) << 0xe) >> 8)) == 0x40) {
    local_34 = 0.0;
    local_30 = 0.0;
    local_2c = 1.0;
  }
  else {
    local_2c = 1.0 / local_2c;
    local_34 = local_34 * local_2c;
    local_30 = local_30 * local_2c;
    local_2c = local_2c * fVar1;
  }
  piVar12 = (int *)(**(code **)(param_1[0x115] + 0x108))(param_1);
  if (piVar12 != (int *)0x0) {
    iVar7 = *param_1;
    iVar11 = *piVar12;
    *(undefined4 *)(iVar11 + 8) = *(undefined4 *)(iVar7 + 8);
    *(undefined4 *)(iVar11 + 0xc) = *(undefined4 *)(iVar7 + 0xc);
    *(undefined4 *)(iVar11 + 0x10) = *(undefined4 *)(iVar7 + 0x10);
    iVar7 = *piVar12;
    fVar1 = (float)param_1[0x11c];
    *(float *)(iVar7 + 0x20) = local_34 * fVar1;
    *(float *)(iVar7 + 0x24) = local_30 * fVar1;
    *(float *)(iVar7 + 0x28) = fVar1 * local_2c;
    lVar13 = (longdouble)(*DAT_0019f80c)(0x42c80000,0x43480000);
    *(float *)(*piVar12 + 0x5c) = (float)lVar13;
    lVar13 = (longdouble)(*DAT_0019f80c)(0x42c80000,0x43960000);
    *(float *)(*piVar12 + 0x60) = (float)lVar13;
    fVar1 = *(float *)(*piVar12 + 0x104);
    fVar2 = *gpGlobals;
    lVar13 = (longdouble)(*DAT_0019f80c)(0x3f733333,0x3f866666);
    lVar13 = lVar13 * (longdouble)(float)param_1[0x11e];
    piVar12[0x119] = (int)(float)lVar13;
    if (lVar13 < (longdouble)(fVar1 - fVar2)) {
      *(float *)(*piVar12 + 0x104) = (float)(lVar13 + (longdouble)*gpGlobals);
      piVar12[0x119] = 0;
    }
  }
  iVar7 = param_1[0x118];
  param_1[0x118] = iVar7 + -1;
  if (iVar7 + -1 < 1) {
    if ((*(byte *)(*param_1 + 0x1a0) & 1) == 0) {
      param_1[3] = -0x10000;
      param_1[4] = (int)SUB_Remove__11CBaseEntity;
    }
    else {
      param_1[0x118] = param_1[0x119];
      param_1[3] = 0;
      param_1[4] = 0;
    }
    *(float *)(*param_1 + 0x104) = *gpGlobals;
  }
  return;
}


