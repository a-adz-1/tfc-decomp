// TrackTarget__9CFuncTank  @ 000b4ad0
void TrackTarget__9CFuncTank(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  code *pcVar5;
  longdouble lVar6;
  bool bVar7;
  float *pfVar8;
  int iVar9;
  float *pfVar10;
  float **ppfVar11;
  undefined1 *puVar12;
  int unaff_EDI;
  bool bVar13;
  longdouble lVar14;
  longdouble lVar15;
  int aiStackY_178 [2];
  float fStackY_170;
  float *pfStack_15c;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c [4];
  float local_2c;
  int local_c;
  
  pfStack_15c = *(float **)(*param_1 + 0x1e8);
  pfVar8 = (float *)(*DAT_00175504)();
  bVar13 = false;
  puVar12 = &stack0xfffffea8;
  if (param_1[0xf3] == 0) {
    iVar9 = *param_1;
    if ((*(byte *)(iVar9 + 0x180) & 1) == 0) {
      return;
    }
    local_70 = *(float *)(iVar9 + 0xe0) + 0.1;
    *(float *)(iVar9 + 0xe4) = local_70;
    bVar7 = false;
    if ((pfVar8 == (float *)0x0) || (pfStack_15c = pfVar8, iVar9 = (*DAT_001755d8)(), iVar9 == 0)) {
      bVar7 = true;
    }
    if (bVar7) {
      iVar9 = *param_1;
      if ((*(byte *)(iVar9 + 0x180) & 1) == 0) {
        return;
      }
      *(float *)(iVar9 + 0xe4) = *(float *)(iVar9 + 0xe0) + 2.0;
      return;
    }
    pfStack_15c = pfVar8;
    unaff_EDI = FindTarget__9CFuncTankP7edict_s(param_1);
    if (unaff_EDI == 0) {
      return;
    }
    pfStack_15c = &local_a0;
    (*DAT_00175510)(*param_1 + 0x50,&local_88,&local_94);
    local_bc = (float)param_1[0x106];
    local_c4 = local_bc * local_88;
    local_c0 = local_bc * local_84;
    local_bc = local_bc * local_80;
    iVar9 = *param_1;
    local_b8 = *(float *)(iVar9 + 8) + local_c4;
    local_b4 = *(float *)(iVar9 + 0xc) + local_c0;
    local_b0 = *(float *)(iVar9 + 0x10) + local_bc;
    local_c8 = (float)param_1[0x107];
    local_d0 = local_c8 * local_94;
    local_cc = local_c8 * local_90;
    local_c8 = local_c8 * local_8c;
    local_ac = local_b8 + local_d0;
    local_a8 = local_b4 + local_cc;
    local_a4 = local_b0 + local_c8;
    fVar1 = (float)param_1[0x108];
    local_7c = local_ac + fVar1 * local_a0;
    local_78 = local_a8 + fVar1 * local_9c;
    local_74 = local_a4 + fVar1 * local_98;
    local_60 = *(float *)(unaff_EDI + 0xe4) + *(float *)(unaff_EDI + 0x230);
    local_5c = *(float *)(unaff_EDI + 0xe8) + *(float *)(unaff_EDI + 0x234);
    local_58 = *(float *)(unaff_EDI + 0xec) + *(float *)(unaff_EDI + 0x238);
    local_dc = local_60 - local_7c;
    local_d8 = local_5c - local_78;
    local_d4 = local_58 - local_74;
    pfVar8 = (float *)SQRT(local_d4 * local_d4 + local_d8 * local_d8 + local_dc * local_dc);
    pfStack_15c = pfVar8;
    local_6c = local_7c;
    local_68 = local_78;
    local_64 = local_74;
    iVar9 = InRange__9CFuncTankf(param_1);
    if (iVar9 == 0) {
      return;
    }
    pfStack_15c = local_3c;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_6c,&local_60,0,*(undefined4 *)(*param_1 + 0x1e8));
    if (((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40) ||
       (ppfVar11 = (float **)&stack0xfffffea8, local_c == unaff_EDI)) {
      iVar9 = unaff_EDI;
      if (unaff_EDI == 0) {
        pfStack_15c = (float *)0x0;
        iVar9 = (*DAT_001755d4)();
        if (iVar9 != 0) goto LAB_000b4e25;
        pfVar10 = (float *)0x0;
      }
      else {
LAB_000b4e25:
        pfVar10 = *(float **)(iVar9 + 0xd8);
      }
      pfStack_15c = pfVar8;
      iVar9 = InRange__9CFuncTankf(param_1);
      ppfVar11 = (float **)&stack0xfffffea8;
      if (((iVar9 != 0) && (ppfVar11 = (float **)&stack0xfffffea8, pfVar10 != (float *)0x0)) &&
         (pfStack_15c = pfVar10, iVar9 = (**(code **)((int)pfVar10[0xf2] + 0x88))(),
         ppfVar11 = (float **)&stack0xfffffea8, iVar9 != 0)) {
        bVar13 = true;
        pfStack_15c = pfVar10;
        (**(code **)(param_1[0xf2] + 0x104))(&local_dc,param_1);
        param_1[0x10e] = (int)local_dc;
        param_1[0x10f] = (int)local_d8;
        param_1[0x110] = (int)local_d4;
        ppfVar11 = &pfStack_15c;
      }
    }
    iVar9 = *param_1;
    local_dc = (float)param_1[0x10e] - *(float *)(iVar9 + 8);
    local_d8 = (float)param_1[0x10f] - *(float *)(iVar9 + 0xc);
    local_d4 = (float)param_1[0x110] - *(float *)(iVar9 + 0x10);
    *(float **)((int)ppfVar11 + -4) = &local_54;
    *(float **)((int)ppfVar11 + -8) = &local_dc;
    *(undefined4 *)((int)ppfVar11 + -0xc) = 0xb4f06;
    local_54 = local_dc;
    local_50 = local_d8;
    local_4c = local_d4;
    UTIL_VecToAngles__FRC6Vector();
    local_48 = local_dc;
    local_44 = local_d8;
    local_40 = local_d4;
    local_dc = SQRT(local_4c * local_4c + local_50 * local_50 + local_54 * local_54);
    *(float *)((int)ppfVar11 + -8) = local_dc;
    *(float **)((int)ppfVar11 + -0xc) = &local_48;
    *(int **)((int)ppfVar11 + -0x10) = param_1;
    *(undefined4 *)((int)ppfVar11 + -0x14) = 0xb4f55;
    AdjustAnglesForBarrel__9CFuncTankR6Vectorf();
    puVar12 = (undefined1 *)((int)ppfVar11 + -4);
  }
  else {
    iVar9 = *(int *)param_1[0xf3];
    local_44 = *(float *)(iVar9 + 0x78);
    local_40 = *(float *)(iVar9 + 0x7c);
    local_48 = 0.0 - *(float *)(iVar9 + 0x74);
    local_70 = *(float *)(*param_1 + 0xe0) + 0.05;
    *(float *)(*param_1 + 0xe4) = local_70;
  }
  local_48 = -local_48;
  *(int *)(puVar12 + -4) = param_1[0xf8];
  *(float *)(puVar12 + -8) = local_44;
  *(undefined4 *)(puVar12 + -0xc) = 0xb4f7a;
  lVar14 = (longdouble)UTIL_AngleDistance__Fff();
  local_44 = (float)(lVar14 + (longdouble)(float)param_1[0xf8]);
  *(int *)(puVar12 + -0xc) = param_1[0xfc];
  *(float *)(puVar12 + -0x10) = local_48;
  *(undefined4 *)(puVar12 + -0x14) = 0xb4f9d;
  lVar14 = (longdouble)UTIL_AngleDistance__Fff();
  local_48 = (float)(lVar14 + (longdouble)(float)param_1[0xfc]);
  fVar1 = (float)param_1[0xf8] + (float)param_1[0xfa];
  if ((byte)(fVar1 < local_44 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_44)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == local_44) << 0xe) >> 8)) != 1) {
    if (local_44 < (float)param_1[0xf8] - (float)param_1[0xfa]) {
      bVar13 = false;
      local_44 = (float)param_1[0xf8] - (float)param_1[0xfa];
    }
    fVar1 = local_44;
    if (bVar13) {
      param_1[0x102] = (int)*gpGlobals;
    }
  }
  local_44 = fVar1;
  *(undefined4 *)(puVar12 + -4) = *(undefined4 *)(*param_1 + 0x54);
  *(float *)(puVar12 + -8) = local_44;
  *(undefined4 *)(puVar12 + -0xc) = 0xb501f;
  lVar14 = (longdouble)UTIL_AngleDistance__Fff();
  *(float *)(*param_1 + 0x60) = (float)lVar14 * 10.0;
  iVar9 = *param_1;
  if (*(float *)(iVar9 + 0x60) <= (float)param_1[0xf9]) {
    iVar9 = *param_1;
    fVar1 = -(float)param_1[0xf9];
    if (*(float *)(iVar9 + 0x60) < fVar1) goto LAB_000b5074;
  }
  else {
    fVar1 = (float)param_1[0xf9];
LAB_000b5074:
    *(float *)(iVar9 + 0x60) = fVar1;
  }
  fVar1 = (float)param_1[0xfc] + (float)param_1[0xfe];
  if (((byte)(fVar1 < local_48 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_48)) << 10) >> 8)
             | (byte)((ushort)((ushort)(fVar1 == local_48) << 0xe) >> 8)) != 1) &&
     (fVar1 = (float)param_1[0xfc] - (float)param_1[0xfe],
     (float)param_1[0xfc] - (float)param_1[0xfe] <= local_48)) {
    fVar1 = local_48;
  }
  local_48 = fVar1;
  *(undefined4 *)(puVar12 + -4) = *(undefined4 *)(*param_1 + 0x50);
  *(float *)(puVar12 + -8) = local_48;
  *(undefined4 *)(puVar12 + -0xc) = 0xb50cc;
  lVar15 = (longdouble)UTIL_AngleDistance__Fff();
  *(float *)(*param_1 + 0x5c) = (float)((longdouble)10.0 * lVar15);
  iVar9 = *param_1;
  if (*(float *)(iVar9 + 0x5c) <= (float)param_1[0xfd]) {
    iVar9 = *param_1;
    fVar1 = -(float)param_1[0xfd];
    if (*(float *)(iVar9 + 0x5c) < fVar1) goto LAB_000b5114;
  }
  else {
    fVar1 = (float)param_1[0xfd];
LAB_000b5114:
    *(float *)(iVar9 + 0x5c) = fVar1;
  }
  if (param_1[0xf3] != 0) {
    return;
  }
  fVar2 = *gpGlobals - (float)param_1[0x102];
  fVar1 = (float)param_1[0x103];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 1) goto LAB_000b53e2;
  lVar15 = ABS(lVar15);
  lVar6 = (longdouble)(float)param_1[0xff];
  if ((byte)(lVar15 < lVar6 | (byte)((ushort)((ushort)(NAN(lVar15) || NAN(lVar6)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar15 == lVar6) << 0xe) >> 8)) == 1) {
    fVar2 = ABS((float)lVar14);
    fVar1 = (float)param_1[0xfb];
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 1) goto LAB_000b5178;
  }
  else {
LAB_000b5178:
    if ((*(byte *)(*param_1 + 0x180) & 0x10) == 0) goto LAB_000b53e2;
  }
  iVar9 = *param_1;
  *(undefined4 *)(puVar12 + -4) = 0;
  *(undefined4 *)(puVar12 + -8) = 0;
  *(float **)(puVar12 + -0xc) = &local_dc;
  *(int *)(puVar12 + -0x10) = iVar9 + 0x50;
  *(undefined4 *)(puVar12 + -0x14) = 0xb519f;
  (*DAT_00175510)();
  iVar9 = *param_1;
  if ((*(byte *)(iVar9 + 0x180) & 0x10) == 0) {
    bVar13 = true;
  }
  else {
    local_bc = SQRT(local_4c * local_4c + local_50 * local_50 + local_54 * local_54);
    local_c4 = local_bc * local_dc;
    local_c0 = local_bc * local_d8;
    local_bc = local_bc * local_d4;
    local_d0 = local_6c + local_c4;
    local_cc = local_68 + local_c0;
    local_c8 = local_64 + local_bc;
    *(float **)(puVar12 + -4) = local_3c;
    *(undefined4 *)(puVar12 + -8) = *(undefined4 *)(iVar9 + 0x1e8);
    *(undefined4 *)(puVar12 + -0xc) = 0;
    *(float **)(puVar12 + -0x10) = &local_d0;
    *(float **)(puVar12 + -0x14) = &local_6c;
    *(undefined4 *)(puVar12 + -0x18) = 0xb5246;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
    bVar13 = local_c == unaff_EDI;
  }
  if (bVar13) {
    iVar9 = *param_1;
    *(float **)(puVar12 + -4) = &fStack_100;
    *(float **)(puVar12 + -8) = &fStack_f4;
    *(float **)(puVar12 + -0xc) = &fStack_e8;
    *(int *)(puVar12 + -0x10) = iVar9 + 0x50;
    *(undefined4 *)(puVar12 + -0x14) = 0xb528f;
    (*DAT_00175510)();
    fVar1 = (float)param_1[0x106];
    iVar9 = *param_1;
    fVar2 = (float)param_1[0x107];
    fVar3 = (float)param_1[0x108];
    local_d0 = *(float *)(iVar9 + 8) + fVar1 * fStack_e8 + fVar2 * fStack_f4 + fVar3 * fStack_100;
    local_cc = *(float *)(iVar9 + 0xc) + fVar1 * fStack_e4 + fVar2 * fStack_f0 + fVar3 * fStack_fc;
    local_c8 = *(float *)(iVar9 + 0x10) + fVar1 * fStack_e0 + fVar2 * fStack_ec + fVar3 * fStack_f8;
    iVar4 = param_1[0xf2];
    *(int *)(puVar12 + -4) = iVar9;
    *(float **)(puVar12 + -8) = &local_dc;
    *(float **)(puVar12 + -0xc) = &local_d0;
    *(int **)(puVar12 + -0x10) = param_1;
    pcVar5 = *(code **)(iVar4 + 0x100);
    *(undefined4 *)(puVar12 + -0x14) = 0xb53de;
    (*pcVar5)();
    return;
  }
LAB_000b53e2:
  param_1[0x100] = 0;
  return;
}


