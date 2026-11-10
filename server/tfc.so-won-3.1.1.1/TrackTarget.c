// TrackTarget__9CFuncTank  @ 000aa834
void TrackTarget__9CFuncTank(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  code *pcVar6;
  bool bVar7;
  float *pfVar8;
  int iVar9;
  float **ppfVar10;
  undefined1 *puVar11;
  bool bVar12;
  longdouble lVar13;
  longdouble lVar14;
  int aiStackY_1b0 [2];
  float fStackY_1a8;
  float *pfStack_194;
  float *local_144;
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
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float local_48;
  float local_44;
  float local_40;
  float afStack_3c [4];
  float fStack_2c;
  float *pfStack_c;
  
  puVar11 = &stack0xfffffe70;
  pfStack_194 = *(float **)(*param_1 + 0x208);
  pfVar8 = (float *)(*DAT_0019f6e4)();
  bVar12 = false;
  if ((int *)param_1[0x116] == (int *)0x0) {
    iVar9 = *param_1;
    if ((*(byte *)(iVar9 + 0x1a0) & 1) == 0) {
      return;
    }
    local_70 = *(float *)(iVar9 + 0x100) + 0.1;
    bVar7 = false;
    *(float *)(iVar9 + 0x104) = local_70;
    if ((pfVar8 == (float *)0x0) || (pfStack_194 = pfVar8, iVar9 = (*DAT_0019f7b8)(), iVar9 == 0)) {
      bVar7 = true;
    }
    if (bVar7) {
      iVar9 = *param_1;
      if ((*(byte *)(iVar9 + 0x1a0) & 1) == 0) {
        return;
      }
      *(float *)(iVar9 + 0x104) = *(float *)(iVar9 + 0x100) + 2.0;
      return;
    }
    if (pfVar8 == (float *)0x0) {
      return;
    }
    pfStack_194 = &local_a0;
    (*DAT_0019f6f0)(*param_1 + 0x50,&local_88,&local_94);
    local_bc = (float)param_1[0x129];
    local_c4 = local_88 * local_bc;
    local_c0 = local_84 * local_bc;
    local_bc = local_bc * local_80;
    iVar9 = *param_1;
    local_b8 = local_c4 + *(float *)(iVar9 + 8);
    local_b4 = local_c0 + *(float *)(iVar9 + 0xc);
    local_b0 = local_bc + *(float *)(iVar9 + 0x10);
    local_c8 = (float)param_1[0x12a];
    local_d0 = local_94 * local_c8;
    local_ac = local_b8 + local_d0;
    local_cc = local_90 * local_c8;
    local_a8 = local_b4 + local_cc;
    local_c8 = local_c8 * local_8c;
    local_a4 = local_b0 + local_c8;
    fVar1 = (float)param_1[299];
    local_7c = local_ac + local_a0 * fVar1;
    local_78 = local_a8 + local_9c * fVar1;
    local_74 = local_a4 + fVar1 * local_98;
    local_60 = pfVar8[0x22] + pfVar8[0x7d];
    local_5c = pfVar8[0x23] + pfVar8[0x7e];
    fStack_58 = pfVar8[0x24] + pfVar8[0x7f];
    local_dc = local_60 - local_7c;
    local_d8 = local_5c - local_78;
    local_d4 = fStack_58 - local_74;
    fVar2 = SQRT(local_d4 * local_d4 + local_d8 * local_d8 + local_dc * local_dc);
    fVar1 = (float)param_1[0x127];
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
      return;
    }
    fVar1 = (float)param_1[0x128];
    if (0x3f < (byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) && fVar1 < fVar2) {
      return;
    }
    pfStack_194 = afStack_3c;
    local_6c = local_7c;
    local_68 = local_78;
    local_64 = local_74;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_6c,&local_60,0,*(undefined4 *)(iVar9 + 0x208));
    if (((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
               (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) == 0x40) ||
       (ppfVar10 = (float **)&stack0xfffffe70, pfStack_c == pfVar8)) {
      pfVar4 = (float *)pfVar8[0x1f];
      fVar1 = (float)param_1[0x127];
      ppfVar10 = (float **)&stack0xfffffe70;
      if (((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 1) &&
         (((fVar1 = (float)param_1[0x128], ppfVar10 = (float **)&stack0xfffffe70,
           (byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40 ||
           fVar2 <= fVar1 && (ppfVar10 = (float **)&stack0xfffffe70, pfVar4 != (float *)0x0)) &&
          (pfStack_194 = pfVar4, iVar9 = (**(code **)((int)pfVar4[0x115] + 0x8c))(),
          ppfVar10 = (float **)&stack0xfffffe70, iVar9 != 0)))) {
        bVar12 = true;
        pfStack_194 = pfVar4;
        (**(code **)(param_1[0x115] + 0x10c))(&local_dc,param_1);
        ppfVar10 = &pfStack_194;
        param_1[0x131] = (int)local_dc;
        param_1[0x132] = (int)local_d8;
        param_1[0x133] = (int)local_d4;
      }
    }
    iVar9 = *param_1;
    local_dc = (float)param_1[0x131] - *(float *)(iVar9 + 8);
    local_d8 = (float)param_1[0x132] - *(float *)(iVar9 + 0xc);
    local_d4 = (float)param_1[0x133] - *(float *)(iVar9 + 0x10);
    *(float **)((int)ppfVar10 + -4) = &fStack_54;
    *(float **)((int)ppfVar10 + -8) = &local_dc;
    *(undefined4 *)((int)ppfVar10 + -0xc) = 0xaad0d;
    fStack_54 = local_dc;
    fStack_50 = local_d8;
    fStack_4c = local_d4;
    UTIL_VecToAngles__FRC6Vector();
    local_48 = local_dc;
    local_44 = local_d8;
    local_40 = local_d4;
    local_dc = SQRT(fStack_4c * fStack_4c + fStack_50 * fStack_50 + fStack_54 * fStack_54);
    *(float *)((int)ppfVar10 + -8) = local_dc;
    *(float **)((int)ppfVar10 + -0xc) = &local_48;
    *(int **)((int)ppfVar10 + -0x10) = param_1;
    *(undefined4 *)((int)ppfVar10 + -0x14) = 0xaad5f;
    AdjustAnglesForBarrel__9CFuncTankR6Vectorf();
    puVar11 = (undefined1 *)((int)ppfVar10 + -4);
    local_144 = pfVar8;
  }
  else {
    iVar9 = *(int *)param_1[0x116];
    local_44 = *(float *)(iVar9 + 0x78);
    local_40 = *(float *)(iVar9 + 0x7c);
    local_48 = -*(float *)(iVar9 + 0x74);
    local_70 = *(float *)(*param_1 + 0x100) + 0.05;
    *(float *)(*param_1 + 0x104) = local_70;
  }
  local_48 = -local_48;
  *(int *)(puVar11 + -4) = param_1[0x11b];
  *(float *)(puVar11 + -8) = local_44;
  *(undefined4 *)(puVar11 + -0xc) = 0xaad87;
  lVar13 = (longdouble)UTIL_AngleDistance__Fff();
  local_44 = (float)(lVar13 + (longdouble)(float)param_1[0x11b]);
  *(int *)(puVar11 + -0xc) = param_1[0x11f];
  *(float *)(puVar11 + -0x10) = local_48;
  *(undefined4 *)(puVar11 + -0x14) = 0xaadaa;
  lVar13 = (longdouble)UTIL_AngleDistance__Fff();
  local_48 = (float)(lVar13 + (longdouble)(float)param_1[0x11f]);
  fVar1 = (float)param_1[0x11b] + (float)param_1[0x11d];
  if ((byte)((local_44 < fVar1 | (byte)((ushort)((ushort)(NAN(local_44) || NAN(fVar1)) << 10) >> 8)
             | (byte)((ushort)((ushort)(local_44 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
    fVar1 = (float)param_1[0x11b] - (float)param_1[0x11d];
    if (0x3f < (byte)((fVar1 < local_44 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_44)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == local_44) << 0xe) >> 8)) - 1)) {
      bVar12 = false;
      local_44 = fVar1;
    }
    fVar1 = local_44;
    if (bVar12) {
      param_1[0x125] = (int)*gpGlobals;
    }
  }
  local_44 = fVar1;
  *(undefined4 *)(puVar11 + -4) = *(undefined4 *)(*param_1 + 0x54);
  *(float *)(puVar11 + -8) = local_44;
  *(undefined4 *)(puVar11 + -0xc) = 0xaae41;
  lVar13 = (longdouble)UTIL_AngleDistance__Fff();
  *(float *)(*param_1 + 0x60) = (float)((longdouble)10.0 * lVar13);
  fVar1 = (float)param_1[0x11c];
  fVar2 = *(float *)(*param_1 + 0x60);
  if ((fVar1 < fVar2) ||
     (fVar1 = -fVar1,
     0x3f < (byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1))) {
    *(float *)(*param_1 + 0x60) = fVar1;
  }
  fVar1 = (float)param_1[0x11f] + (float)param_1[0x121];
  if ((local_48 <= fVar1) &&
     (fVar1 = (float)param_1[0x11f] - (float)param_1[0x121],
     (byte)((fVar1 < local_48 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_48)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == local_48) << 0xe) >> 8)) - 1) < 0x40)) {
    fVar1 = local_48;
  }
  local_48 = fVar1;
  *(undefined4 *)(puVar11 + -4) = *(undefined4 *)(*param_1 + 0x50);
  *(float *)(puVar11 + -8) = local_48;
  *(undefined4 *)(puVar11 + -0xc) = 0xaaeeb;
  lVar14 = (longdouble)UTIL_AngleDistance__Fff();
  *(float *)(*param_1 + 0x5c) = (float)((longdouble)10.0 * lVar14);
  fVar1 = (float)param_1[0x120];
  fVar2 = *(float *)(*param_1 + 0x5c);
  if ((fVar1 < fVar2) ||
     (fVar1 = -fVar1,
     0x3f < (byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1))) {
    *(float *)(*param_1 + 0x5c) = fVar1;
  }
  if (param_1[0x116] != 0) {
    return;
  }
  if ((float)param_1[0x126] <= *gpGlobals - (float)param_1[0x125]) {
LAB_000ab204:
    param_1[0x123] = 0;
  }
  else {
    iVar9 = *param_1;
    if ((longdouble)(float)param_1[0x122] <= ABS(lVar14)) {
LAB_000aaf92:
      if ((*(byte *)(iVar9 + 0x1a0) & 0x10) == 0) goto LAB_000ab204;
    }
    else {
      fVar2 = ABS((float)lVar13);
      fVar1 = (float)param_1[0x11e];
      if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 1) goto LAB_000aaf92;
    }
    *(undefined4 *)(puVar11 + -4) = 0;
    *(undefined4 *)(puVar11 + -8) = 0;
    *(float **)(puVar11 + -0xc) = &local_dc;
    *(int *)(puVar11 + -0x10) = iVar9 + 0x50;
    *(undefined4 *)(puVar11 + -0x14) = 0xaafcb;
    (*DAT_0019f6f0)();
    iVar9 = *param_1;
    if ((*(byte *)(iVar9 + 0x1a0) & 0x10) == 0) {
      bVar12 = true;
    }
    else {
      local_bc = SQRT(fStack_4c * fStack_4c + fStack_50 * fStack_50 + fStack_54 * fStack_54);
      local_c4 = local_dc * local_bc;
      local_d0 = local_c4 + local_6c;
      local_c0 = local_d8 * local_bc;
      local_cc = local_c0 + local_68;
      local_bc = local_bc * local_d4;
      local_c8 = local_bc + local_64;
      *(float **)(puVar11 + -4) = afStack_3c;
      *(undefined4 *)(puVar11 + -8) = *(undefined4 *)(iVar9 + 0x208);
      *(undefined4 *)(puVar11 + -0xc) = 0;
      *(float **)(puVar11 + -0x10) = &local_d0;
      *(float **)(puVar11 + -0x14) = &local_6c;
      *(undefined4 *)(puVar11 + -0x18) = 0xab067;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
      bVar12 = pfStack_c == local_144;
    }
    if (bVar12) {
      iVar9 = *param_1;
      *(float **)(puVar11 + -4) = &fStack_100;
      *(float **)(puVar11 + -8) = &fStack_f4;
      *(float **)(puVar11 + -0xc) = &fStack_e8;
      *(int *)(puVar11 + -0x10) = iVar9 + 0x50;
      *(undefined4 *)(puVar11 + -0x14) = 0xab0be;
      (*DAT_0019f6f0)();
      fVar1 = (float)param_1[0x129];
      iVar9 = *param_1;
      fVar2 = (float)param_1[0x12a];
      fVar3 = (float)param_1[299];
      local_d0 = fStack_e8 * fVar1 + *(float *)(iVar9 + 8) + fStack_f4 * fVar2 + fStack_100 * fVar3;
      local_cc = fStack_e4 * fVar1 + *(float *)(iVar9 + 0xc) + fStack_f0 * fVar2 + fStack_fc * fVar3
      ;
      local_c8 = fVar1 * fStack_e0 + *(float *)(iVar9 + 0x10) + fVar2 * fStack_ec +
                 fVar3 * fStack_f8;
      iVar5 = param_1[0x115];
      *(int *)(puVar11 + -4) = iVar9;
      *(float **)(puVar11 + -8) = &local_dc;
      *(float **)(puVar11 + -0xc) = &local_d0;
      *(int **)(puVar11 + -0x10) = param_1;
      pcVar6 = *(code **)(iVar5 + 0x108);
      *(undefined4 *)(puVar11 + -0x14) = 0xab1ed;
      (*pcVar6)();
    }
    else {
      param_1[0x123] = 0;
    }
  }
  return;
}


