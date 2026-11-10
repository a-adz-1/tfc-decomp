// ShootThink__11CGibShooter  @ 000995ec
void ShootThink__11CGibShooter(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  longdouble lVar16;
  longdouble lVar17;
  longdouble lVar18;
  float local_30;
  float local_2c;
  float local_28;
  
  *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0xf6];
  iVar15 = *param_1;
  fVar10 = *(float *)(iVar15 + 0x44);
  fVar11 = *(float *)(iVar15 + 0x48);
  fVar12 = *(float *)(iVar15 + 0x4c);
  lVar16 = (longdouble)(*DAT_001a7fac)(0xbf800000,0x3f800000);
  fVar1 = gpGlobals[0x10];
  fVar2 = gpGlobals[0x11];
  fVar3 = gpGlobals[0x12];
  fVar4 = (float)param_1[0xfd];
  lVar17 = (longdouble)(*DAT_001a7fac)(0xbf800000,0x3f800000);
  fVar5 = gpGlobals[10];
  fVar6 = gpGlobals[0xb];
  fVar7 = gpGlobals[0xc];
  fVar8 = (float)param_1[0xfd];
  lVar18 = (longdouble)(*DAT_001a7fac)(0xbf800000,0x3f800000);
  fVar9 = (float)param_1[0xfd];
  local_30 = fVar10 + fVar4 * (float)(lVar16 * (longdouble)fVar1) +
             fVar8 * (float)(lVar17 * (longdouble)fVar5) +
             fVar9 * (float)(lVar18 * (longdouble)gpGlobals[0xd]);
  local_2c = fVar11 + fVar4 * (float)(lVar16 * (longdouble)fVar2) +
             fVar8 * (float)(lVar17 * (longdouble)fVar6) +
             fVar9 * (float)(lVar18 * (longdouble)gpGlobals[0xe]);
  fVar1 = fVar12 + fVar4 * (float)(lVar16 * (longdouble)fVar3) +
          fVar8 * (float)(lVar17 * (longdouble)fVar7) +
          fVar9 * (float)(lVar18 * (longdouble)gpGlobals[0xf]);
  local_28 = SQRT(fVar1 * fVar1 + local_2c * local_2c + local_30 * local_30);
  if ((byte)((byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_28 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_30 = 0.0;
    local_2c = 0.0;
    local_28 = 1.0;
  }
  else {
    local_28 = 1.0 / local_28;
    local_30 = local_28 * local_30;
    local_2c = local_28 * local_2c;
    local_28 = local_28 * fVar1;
  }
  piVar14 = (int *)(**(code **)(param_1[0xf5] + 0x100))(param_1);
  if (piVar14 != (int *)0x0) {
    iVar15 = *piVar14;
    iVar13 = *param_1;
    *(undefined4 *)(iVar15 + 8) = *(undefined4 *)(iVar13 + 8);
    *(undefined4 *)(iVar15 + 0xc) = *(undefined4 *)(iVar13 + 0xc);
    *(undefined4 *)(iVar15 + 0x10) = *(undefined4 *)(iVar13 + 0x10);
    iVar15 = *piVar14;
    fVar1 = (float)param_1[0xfc];
    *(float *)(iVar15 + 0x20) = fVar1 * local_30;
    *(float *)(iVar15 + 0x24) = fVar1 * local_2c;
    *(float *)(iVar15 + 0x28) = fVar1 * local_28;
    lVar16 = (longdouble)(*DAT_001a7fac)(0x42c80000,0x43480000);
    *(float *)(*piVar14 + 0x5c) = (float)lVar16;
    lVar16 = (longdouble)(*DAT_001a7fac)(0x42c80000,0x43960000);
    *(float *)(*piVar14 + 0x60) = (float)lVar16;
    fVar1 = *(float *)(*piVar14 + 0x104);
    fVar2 = *gpGlobals;
    lVar16 = (longdouble)(*DAT_001a7fac)(0x3f733333,0x3f866666);
    fVar3 = (float)param_1[0xfe];
    piVar14[0xf9] = (int)(float)(lVar16 * (longdouble)fVar3);
    if (lVar16 * (longdouble)fVar3 < (longdouble)(fVar1 - fVar2)) {
      *(float *)(*piVar14 + 0x104) = *gpGlobals + (float)piVar14[0xf9];
      piVar14[0xf9] = 0;
    }
  }
  param_1[0xf8] = param_1[0xf8] + -1;
  if (param_1[0xf8] < 1) {
    iVar15 = *param_1;
    if ((*(byte *)(iVar15 + 0x1a0) & 1) == 0) {
      param_1[3] = -0x10000;
      param_1[4] = (int)SUB_Remove__11CBaseEntity;
      iVar15 = *param_1;
    }
    else {
      param_1[0xf8] = param_1[0xf9];
      param_1[3] = 0;
      param_1[4] = 0;
    }
    *(float *)(iVar15 + 0x104) = *gpGlobals;
  }
  return;
}


