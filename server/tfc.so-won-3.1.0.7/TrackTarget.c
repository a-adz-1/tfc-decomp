// TrackTarget__9CFuncTank  @ 000ab2a4
void TrackTarget__9CFuncTank(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  code *pcVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  float **ppfVar10;
  undefined1 *puVar11;
  float *pfVar12;
  bool bVar13;
  longdouble lVar14;
  int aiStackY_180 [3];
  float *pfStack_164;
  float local_150 [2];
  int aiStack_148 [2];
  float local_140 [35];
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float local_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float afStack_70 [5];
  float fStack_5c;
  float afStack_58 [7];
  undefined4 local_3c;
  float afStack_38 [4];
  float fStack_28;
  int aiStack_10 [4];
  
  puVar11 = &stack0xfffffea0;
  pfStack_164 = *(float **)(*param_1 + 0x208);
  pfVar7 = (float *)(*DAT_001c1064)();
  if (param_1[0x112] == 0) {
    iVar8 = *param_1;
    if ((*(byte *)(iVar8 + 0x1a0) & 1) == 0) {
      return;
    }
    afStack_70[1] = *(float *)(iVar8 + 0x100) + 0.1;
    *(float *)(iVar8 + 0x104) = afStack_70[1];
    bVar13 = false;
    if ((pfVar7 == (float *)0x0) || (pfStack_164 = pfVar7, iVar8 = (*DAT_001c1138)(), iVar8 == 0)) {
      bVar13 = true;
    }
    if (bVar13) {
      iVar8 = *param_1;
      if ((*(byte *)(iVar8 + 0x1a0) & 1) == 0) {
        return;
      }
      *(float *)(iVar8 + 0x104) = *(float *)(iVar8 + 0x100) + 2.0;
      return;
    }
    pfStack_164 = pfVar7;
    iVar8 = FindTarget__9CFuncTankP7edict_s(param_1);
    if (iVar8 == 0) {
      return;
    }
    pfStack_164 = &fStack_9c;
    (*DAT_001c1070)(*param_1 + 0x50,&local_84,&fStack_90);
    local_140[0x22] = (float)param_1[0x125];
    local_140[0x20] = local_140[0x22] * local_84;
    local_140[0x21] = local_140[0x22] * fStack_80;
    local_140[0x22] = local_140[0x22] * fStack_7c;
    fStack_b4 = *(float *)(*param_1 + 8) + local_140[0x20];
    fStack_b0 = *(float *)(*param_1 + 0xc) + local_140[0x21];
    fStack_ac = *(float *)(*param_1 + 0x10) + local_140[0x22];
    local_140[0x1f] = (float)param_1[0x126];
    local_140[0x1d] = local_140[0x1f] * fStack_90;
    local_140[0x1e] = local_140[0x1f] * fStack_8c;
    local_140[0x1f] = local_140[0x1f] * fStack_88;
    fStack_a8 = fStack_b4 + local_140[0x1d];
    fStack_a4 = fStack_b0 + local_140[0x1e];
    fStack_a0 = fStack_ac + local_140[0x1f];
    fVar2 = (float)param_1[0x127];
    fStack_78 = fStack_a8 + fVar2 * fStack_9c;
    fStack_74 = fStack_a4 + fVar2 * fStack_98;
    afStack_70[0] = fStack_a0 + fVar2 * fStack_94;
    fStack_5c = *(float *)(iVar8 + 0x88) + *(float *)(iVar8 + 500);
    afStack_58[0] = *(float *)(iVar8 + 0x8c) + *(float *)(iVar8 + 0x1f8);
    afStack_58[1] = *(float *)(iVar8 + 0x90) + *(float *)(iVar8 + 0x1fc);
    local_140[0x1a] = fStack_5c - fStack_78;
    local_140[0x1b] = afStack_58[0] - fStack_74;
    local_140[0x1c] = afStack_58[1] - afStack_70[0];
    pfVar7 = (float *)SQRT(local_140[0x1c] * local_140[0x1c] +
                           local_140[0x1b] * local_140[0x1b] + local_140[0x1a] * local_140[0x1a]);
    pfStack_164 = pfVar7;
    afStack_70[2] = fStack_78;
    afStack_70[3] = fStack_74;
    afStack_70[4] = afStack_70[0];
    iVar9 = InRange__9CFuncTankf(param_1);
    if (iVar9 == 0) {
      return;
    }
    pfStack_164 = afStack_38;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (afStack_70 + 2,&fStack_5c,0,*(undefined4 *)(*param_1 + 0x208));
    if (((byte)(1.0 < fStack_28 | (byte)((ushort)((ushort)NAN(fStack_28) << 10) >> 8) |
               (byte)((ushort)((ushort)(fStack_28 == 1.0) << 0xe) >> 8)) == 0x40) ||
       (ppfVar10 = (float **)&stack0xfffffea0, aiStack_10[2] == iVar8)) {
      if (iVar8 == 0) {
        pfStack_164 = (float *)0x0;
        iVar8 = (*DAT_001c1134)();
        if (iVar8 != 0) goto LAB_000ab712;
        pfVar12 = (float *)0x0;
      }
      else {
LAB_000ab712:
        pfVar12 = *(float **)(iVar8 + 0x7c);
      }
      pfStack_164 = pfVar7;
      iVar8 = InRange__9CFuncTankf(param_1);
      ppfVar10 = (float **)&stack0xfffffea0;
      if (((iVar8 != 0) && (ppfVar10 = (float **)&stack0xfffffea0, pfVar12 != (float *)0x0)) &&
         (pfStack_164 = pfVar12, iVar8 = (**(code **)((int)pfVar12[0x111] + 0x8c))(),
         ppfVar10 = (float **)&stack0xfffffea0, iVar8 != 0)) {
        pfStack_164 = pfVar12;
        (**(code **)(param_1[0x111] + 0x10c))(local_140 + 0x1a,param_1);
        param_1[0x12d] = (int)local_140[0x19];
        param_1[0x12e] = (int)local_140[0x1a];
        param_1[0x12f] = (int)local_140[0x1b];
        ppfVar10 = &pfStack_164;
      }
    }
    iVar8 = *param_1;
    fVar2 = (float)param_1[0x12e];
    fVar3 = *(float *)(iVar8 + 0xc);
    fVar4 = (float)param_1[0x12f];
    fVar1 = *(float *)(iVar8 + 0x10);
    *(float *)((int)ppfVar10 + 0x88) = (float)param_1[0x12d] - *(float *)(iVar8 + 8);
    *(float *)((int)ppfVar10 + 0x8c) = fVar2 - fVar3;
    *(float *)((int)ppfVar10 + 0x90) = fVar4 - fVar1;
    *(undefined4 *)((int)ppfVar10 + 0x110) = *(undefined4 *)((int)ppfVar10 + 0x88);
    *(undefined4 *)((int)ppfVar10 + 0x114) = *(undefined4 *)((int)ppfVar10 + 0x8c);
    *(undefined4 *)((int)ppfVar10 + 0x118) = *(undefined4 *)((int)ppfVar10 + 0x90);
    *(undefined1 **)((int)ppfVar10 + -4) = (undefined1 *)((int)ppfVar10 + 0x110);
    *(undefined1 **)((int)ppfVar10 + -8) = (undefined1 *)((int)ppfVar10 + 0x88);
    *(undefined4 *)((int)ppfVar10 + -0xc) = 0xab806;
    UTIL_VecToAngles__FRC6Vector();
    *(undefined4 *)((int)ppfVar10 + 0x118) = *(undefined4 *)((int)ppfVar10 + 0x84);
    *(undefined4 *)((int)ppfVar10 + 0x11c) = *(undefined4 *)((int)ppfVar10 + 0x88);
    *(undefined4 *)((int)ppfVar10 + 0x120) = *(undefined4 *)((int)ppfVar10 + 0x8c);
    *(float *)((int)ppfVar10 + 0x84) =
         SQRT(*(float *)((int)ppfVar10 + 0x114) * *(float *)((int)ppfVar10 + 0x114) +
              *(float *)((int)ppfVar10 + 0x110) * *(float *)((int)ppfVar10 + 0x110) +
              *(float *)((int)ppfVar10 + 0x10c) * *(float *)((int)ppfVar10 + 0x10c));
    *(undefined4 *)((int)ppfVar10 + -8) = *(undefined4 *)((int)ppfVar10 + 0x84);
    *(undefined1 **)((int)ppfVar10 + -0xc) = (undefined1 *)((int)ppfVar10 + 0x118);
    *(int **)((int)ppfVar10 + -0x10) = param_1;
    *(undefined4 *)((int)ppfVar10 + -0x14) = 0xab876;
    AdjustAnglesForBarrel__9CFuncTankR6Vectorf();
    puVar11 = (undefined1 *)((int)ppfVar10 + -4);
  }
  else {
    iVar8 = *(int *)param_1[0x112];
    afStack_58[6] = (float)*(undefined4 *)(iVar8 + 0x78);
    local_3c = *(undefined4 *)(iVar8 + 0x7c);
    afStack_58[5] = -*(float *)(iVar8 + 0x74);
    afStack_70[1] = *(float *)(*param_1 + 0x100) + 0.05;
    *(float *)(*param_1 + 0x104) = afStack_70[1];
  }
  *(float *)(puVar11 + 0x11c) = -*(float *)(puVar11 + 0x11c);
  *(int *)(puVar11 + -4) = param_1[0x117];
  *(undefined4 *)(puVar11 + -8) = *(undefined4 *)(puVar11 + 0x120);
  *(undefined4 *)(puVar11 + -0xc) = 0xab8a7;
  lVar14 = (longdouble)UTIL_AngleDistance__Fff();
  *(float *)(puVar11 + 0x120) = (float)(lVar14 + (longdouble)(float)param_1[0x117]);
  *(int *)(puVar11 + -0xc) = param_1[0x11b];
  *(undefined4 *)(puVar11 + -0x10) = *(undefined4 *)(puVar11 + 0x11c);
  *(undefined4 *)(puVar11 + -0x14) = 0xab8d2;
  lVar14 = (longdouble)UTIL_AngleDistance__Fff();
  *(float *)(puVar11 + 0x11c) = (float)(lVar14 + (longdouble)(float)param_1[0x11b]);
  if (*(float *)(puVar11 + 0x120) <= (float)param_1[0x117] + (float)param_1[0x119]) {
    fVar3 = (float)param_1[0x117] - (float)param_1[0x119];
    fVar2 = *(float *)(puVar11 + 0x120);
    if (0x3f < (byte)((fVar3 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) - 1)) {
      *(float *)(puVar11 + 0x120) = fVar3;
      *(undefined4 *)(puVar11 + 0x24) = 0;
    }
    if (*(int *)(puVar11 + 0x24) != 0) {
      param_1[0x121] = (int)*gpGlobals;
    }
  }
  else {
    *(float *)(puVar11 + 0x120) = (float)param_1[0x117] + (float)param_1[0x119];
  }
  *(undefined4 *)(puVar11 + -4) = *(undefined4 *)(*param_1 + 0x54);
  *(undefined4 *)(puVar11 + -8) = *(undefined4 *)(puVar11 + 0x120);
  *(undefined4 *)(puVar11 + -0xc) = 0xab96e;
  lVar14 = (longdouble)UTIL_AngleDistance__Fff();
  *(float *)(puVar11 + 0x18) = (float)lVar14;
  *(float *)(*param_1 + 0x60) = *(float *)(puVar11 + 0x18) * 10.0;
  iVar8 = *param_1;
  fVar2 = *(float *)(iVar8 + 0x60);
  fVar3 = (float)param_1[0x118];
  if ((byte)((fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1) < 0x40) {
    iVar8 = *param_1;
    fVar2 = -(float)param_1[0x118];
    fVar3 = *(float *)(iVar8 + 0x60);
    if (0x3f < (byte)((fVar2 < fVar3 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1))
    goto LAB_000ab9c2;
  }
  else {
    fVar2 = (float)param_1[0x118];
LAB_000ab9c2:
    *(float *)(iVar8 + 0x60) = fVar2;
  }
  fVar3 = (float)param_1[0x11b] + (float)param_1[0x11d];
  fVar2 = *(float *)(puVar11 + 0x11c);
  if ((byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) == 1) {
LAB_000aba07:
    *(float *)(puVar11 + 0x11c) = fVar3;
  }
  else {
    fVar3 = (float)param_1[0x11b] - (float)param_1[0x11d];
    fVar2 = *(float *)(puVar11 + 0x11c);
    if (0x3f < (byte)((fVar3 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) - 1))
    goto LAB_000aba07;
  }
  *(undefined4 *)(puVar11 + -4) = *(undefined4 *)(*param_1 + 0x50);
  *(undefined4 *)(puVar11 + -8) = *(undefined4 *)(puVar11 + 0x11c);
  *(undefined4 *)(puVar11 + -0xc) = 0xaba30;
  lVar14 = (longdouble)UTIL_AngleDistance__Fff();
  *(float *)(*param_1 + 0x5c) = (float)((longdouble)10.0 * lVar14);
  iVar8 = *param_1;
  fVar2 = *(float *)(iVar8 + 0x5c);
  fVar3 = (float)param_1[0x11c];
  if ((byte)((fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1) < 0x40) {
    iVar8 = *param_1;
    fVar2 = -(float)param_1[0x11c];
    fVar3 = *(float *)(iVar8 + 0x5c);
    if (0x3f < (byte)((fVar2 < fVar3 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1))
    goto LAB_000aba7e;
  }
  else {
    fVar2 = (float)param_1[0x11c];
LAB_000aba7e:
    *(float *)(iVar8 + 0x5c) = fVar2;
  }
  if (param_1[0x112] != 0) {
    return;
  }
  if ((float)param_1[0x122] <= *gpGlobals - (float)param_1[0x121]) goto LAB_000abd52;
  if ((longdouble)(float)param_1[0x11e] <= ABS(lVar14)) {
LAB_000abad8:
    if ((*(byte *)(*param_1 + 0x1a0) & 0x10) == 0) goto LAB_000abd52;
  }
  else {
    fVar3 = ABS(*(float *)(puVar11 + 0x18));
    fVar2 = (float)param_1[0x11a];
    if ((byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) != 1) goto LAB_000abad8;
  }
  iVar8 = *param_1;
  *(undefined4 *)(puVar11 + -4) = 0;
  *(undefined4 *)(puVar11 + -8) = 0;
  *(undefined1 **)(puVar11 + -0xc) = puVar11 + 0x88;
  *(int *)(puVar11 + -0x10) = iVar8 + 0x50;
  *(undefined4 *)(puVar11 + -0x14) = 0xabb06;
  (*DAT_001c1070)();
  iVar8 = *param_1;
  if ((*(byte *)(iVar8 + 0x1a0) & 0x10) == 0) {
    bVar13 = true;
  }
  else {
    *(float *)(puVar11 + 0x94) =
         SQRT(*(float *)(puVar11 + 0x118) * *(float *)(puVar11 + 0x118) +
              *(float *)(puVar11 + 0x114) * *(float *)(puVar11 + 0x114) +
              *(float *)(puVar11 + 0x110) * *(float *)(puVar11 + 0x110));
    fVar2 = *(float *)(puVar11 + 0x94);
    *(float *)(puVar11 + 0xa0) = fVar2 * *(float *)(puVar11 + 0x88);
    *(float *)(puVar11 + 0xa4) = fVar2 * *(float *)(puVar11 + 0x8c);
    *(float *)(puVar11 + 0xa8) = fVar2 * *(float *)(puVar11 + 0x90);
    *(float *)(puVar11 + 0x94) = *(float *)(puVar11 + 0xf8) + fVar2 * *(float *)(puVar11 + 0x88);
    *(float *)(puVar11 + 0x98) = *(float *)(puVar11 + 0xfc) + fVar2 * *(float *)(puVar11 + 0x8c);
    *(float *)(puVar11 + 0x9c) = *(float *)(puVar11 + 0x100) + *(float *)(puVar11 + 0xa8);
    *(undefined1 **)(puVar11 + 0x14) = puVar11 + 0x128;
    *(undefined1 **)(puVar11 + -4) = puVar11 + 0x128;
    uVar5 = *(undefined4 *)(iVar8 + 0x208);
    *(undefined4 *)(puVar11 + 0x14) = uVar5;
    *(undefined4 *)(puVar11 + -8) = uVar5;
    *(undefined4 *)(puVar11 + -0xc) = 0;
    *(undefined1 **)(puVar11 + -0x10) = puVar11 + 0x94;
    *(undefined1 **)(puVar11 + 0x14) = puVar11 + 0xf8;
    *(undefined1 **)(puVar11 + -0x14) = puVar11 + 0xf8;
    *(undefined4 *)(puVar11 + -0x18) = 0xabbeb;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
    bVar13 = *(int *)(puVar11 + 0x158) == *(int *)(puVar11 + 0x20);
  }
  if (bVar13) {
    iVar8 = *param_1;
    *(undefined1 **)(puVar11 + -4) = puVar11 + 100;
    *(undefined1 **)(puVar11 + -8) = puVar11 + 0x70;
    *(undefined1 **)(puVar11 + -0xc) = puVar11 + 0x7c;
    *(int *)(puVar11 + -0x10) = iVar8 + 0x50;
    *(undefined4 *)(puVar11 + -0x14) = 0xabc32;
    (*DAT_001c1070)();
    fVar2 = (float)param_1[0x125];
    *(float *)(puVar11 + 0x40) = fVar2 * *(float *)(puVar11 + 0x7c);
    *(float *)(puVar11 + 0x44) = fVar2 * *(float *)(puVar11 + 0x80);
    *(float *)(puVar11 + 0x48) = fVar2 * *(float *)(puVar11 + 0x84);
    iVar8 = *param_1;
    fVar3 = *(float *)(iVar8 + 0xc);
    fVar4 = *(float *)(iVar8 + 0x10);
    *(float *)(puVar11 + 0x4c) = *(float *)(iVar8 + 8) + fVar2 * *(float *)(puVar11 + 0x7c);
    *(float *)(puVar11 + 0x50) = fVar3 + fVar2 * *(float *)(puVar11 + 0x80);
    *(float *)(puVar11 + 0x54) = fVar4 + *(float *)(puVar11 + 0x48);
    fVar2 = (float)param_1[0x126];
    *(float *)(puVar11 + 0x34) = fVar2 * *(float *)(puVar11 + 0x70);
    *(float *)(puVar11 + 0x38) = fVar2 * *(float *)(puVar11 + 0x74);
    *(float *)(puVar11 + 0x3c) = fVar2 * *(float *)(puVar11 + 0x78);
    *(float *)(puVar11 + 0x58) = *(float *)(puVar11 + 0x4c) + fVar2 * *(float *)(puVar11 + 0x70);
    *(float *)(puVar11 + 0x5c) = *(float *)(puVar11 + 0x50) + fVar2 * *(float *)(puVar11 + 0x74);
    *(float *)(puVar11 + 0x60) = *(float *)(puVar11 + 0x54) + *(float *)(puVar11 + 0x3c);
    fVar2 = (float)param_1[0x127];
    *(float *)(puVar11 + 0x28) = fVar2 * *(float *)(puVar11 + 100);
    *(float *)(puVar11 + 0x2c) = fVar2 * *(float *)(puVar11 + 0x68);
    *(float *)(puVar11 + 0x30) = fVar2 * *(float *)(puVar11 + 0x6c);
    *(float *)(puVar11 + 0x94) = *(float *)(puVar11 + 0x58) + fVar2 * *(float *)(puVar11 + 100);
    *(float *)(puVar11 + 0x98) = *(float *)(puVar11 + 0x5c) + fVar2 * *(float *)(puVar11 + 0x68);
    *(float *)(puVar11 + 0x9c) = *(float *)(puVar11 + 0x60) + *(float *)(puVar11 + 0x30);
    iVar9 = param_1[0x111];
    *(int *)(puVar11 + -4) = iVar8;
    *(undefined1 **)(puVar11 + -8) = puVar11 + 0x88;
    *(undefined1 **)(puVar11 + -0xc) = puVar11 + 0x94;
    *(int **)(puVar11 + -0x10) = param_1;
    pcVar6 = *(code **)(iVar9 + 0x108);
    *(undefined4 *)(puVar11 + -0x14) = 0xabd4b;
    (*pcVar6)();
    return;
  }
LAB_000abd52:
  param_1[0x11f] = 0;
  return;
}


