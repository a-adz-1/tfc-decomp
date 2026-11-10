// ShootThink__11CGibShooter  @ 000ae870
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
  float local_34;
  float local_30;
  float local_2c;
  
  *(float *)(*param_1 + 0xe4) = *gpGlobals + (float)param_1[0xf3];
  iVar15 = *param_1;
  fVar10 = *(float *)(iVar15 + 0x44);
  fVar11 = *(float *)(iVar15 + 0x48);
  fVar12 = *(float *)(iVar15 + 0x4c);
  lVar16 = (longdouble)(*DAT_0017562c)(0xbf800000,0x3f800000);
  fVar1 = gpGlobals[0x10];
  fVar2 = gpGlobals[0x11];
  fVar3 = gpGlobals[0x12];
  fVar4 = (float)param_1[0xfa];
  lVar17 = (longdouble)(*DAT_0017562c)(0xbf800000,0x3f800000);
  fVar5 = gpGlobals[10];
  fVar6 = gpGlobals[0xb];
  fVar7 = gpGlobals[0xc];
  fVar8 = (float)param_1[0xfa];
  lVar18 = (longdouble)(*DAT_0017562c)(0xbf800000,0x3f800000);
  fVar9 = (float)param_1[0xfa];
  local_34 = fVar10 + fVar4 * (float)(lVar16 * (longdouble)fVar1) +
             fVar8 * (float)(lVar17 * (longdouble)fVar5) +
             fVar9 * (float)(lVar18 * (longdouble)gpGlobals[0xd]);
  local_30 = fVar11 + fVar4 * (float)(lVar16 * (longdouble)fVar2) +
             fVar8 * (float)(lVar17 * (longdouble)fVar6) +
             fVar9 * (float)(lVar18 * (longdouble)gpGlobals[0xe]);
  fVar1 = fVar12 + fVar4 * (float)(lVar16 * (longdouble)fVar3) +
          fVar8 * (float)(lVar17 * (longdouble)fVar7) +
          fVar9 * (float)(lVar18 * (longdouble)gpGlobals[0xf]);
  local_2c = SQRT(fVar1 * fVar1 + local_30 * local_30 + local_34 * local_34);
  if ((byte)((byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_2c == 0.0) << 0xe) >> 8)) == 0x40) {
    local_34 = 0.0;
    local_30 = 0.0;
    local_2c = 1.0;
  }
  else {
    local_2c = 1.0 / local_2c;
    local_34 = local_2c * local_34;
    local_30 = local_2c * local_30;
    local_2c = local_2c * fVar1;
  }
  piVar14 = (int *)(**(code **)(param_1[0xf2] + 0x100))(param_1);
  if (piVar14 != (int *)0x0) {
    iVar15 = *piVar14;
    iVar13 = *param_1;
    *(undefined4 *)(iVar15 + 8) = *(undefined4 *)(iVar13 + 8);
    *(undefined4 *)(iVar15 + 0xc) = *(undefined4 *)(iVar13 + 0xc);
    *(undefined4 *)(iVar15 + 0x10) = *(undefined4 *)(iVar13 + 0x10);
    iVar15 = *piVar14;
    fVar1 = (float)param_1[0xf9];
    *(float *)(iVar15 + 0x20) = fVar1 * local_34;
    *(float *)(iVar15 + 0x24) = fVar1 * local_30;
    *(float *)(iVar15 + 0x28) = fVar1 * local_2c;
    lVar16 = (longdouble)(*DAT_0017562c)(0x42c80000,0x43480000);
    *(float *)(*piVar14 + 0x5c) = (float)lVar16;
    lVar16 = (longdouble)(*DAT_0017562c)(0x42c80000,0x43960000);
    *(float *)(*piVar14 + 0x60) = (float)lVar16;
    fVar1 = *(float *)(*piVar14 + 0xe4);
    fVar2 = *gpGlobals;
    lVar17 = (longdouble)(*DAT_0017562c)(0x3f733333,0x3f866666);
    lVar17 = lVar17 * (longdouble)(float)param_1[0xfb];
    piVar14[0xf6] = (int)(float)lVar17;
    lVar16 = (longdouble)(fVar1 - fVar2);
    if ((byte)(lVar17 < lVar16 | (byte)((ushort)((ushort)(NAN(lVar17) || NAN(lVar16)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar17 == lVar16) << 0xe) >> 8)) == 1) {
      *(float *)(*piVar14 + 0xe4) = *gpGlobals + (float)piVar14[0xf6];
      piVar14[0xf6] = 0;
    }
  }
  param_1[0xf5] = param_1[0xf5] + -1;
  if (param_1[0xf5] < 1) {
    iVar15 = *param_1;
    if ((*(byte *)(iVar15 + 0x180) & 1) == 0) {
      param_1[3] = -0x10000;
      param_1[4] = (int)SUB_Remove__11CBaseEntity;
      iVar15 = *param_1;
    }
    else {
      param_1[0xf5] = param_1[0xf6];
      param_1[3] = 0;
      param_1[4] = 0;
    }
    *(float *)(iVar15 + 0xe4) = *gpGlobals;
  }
  return;
}


