// SetSequenceBox__FP12CBaseMonster  @ 000c1a68
void SetSequenceBox__FP12CBaseMonster(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  longdouble lVar10;
  longdouble lVar11;
  longdouble lVar12;
  longdouble lVar13;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float afStack_4c [5];
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_28;
  float fStack_24;
  float local_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  float fStack_10;
  float local_c;
  undefined4 uStack_8;
  float fStack_4;
  
  uVar5 = (*DAT_001c1148)(*(undefined4 *)(*param_1 + 0x208));
  iVar6 = ExtractBbox__FPviPfT2(uVar5,*(undefined4 *)(*param_1 + 0x128),&local_c,&local_18);
  if (iVar6 != 0) {
    lVar10 = (longdouble)(*(float *)(*param_1 + 0x54) * 0.017453292);
    lVar11 = (longdouble)fcos(lVar10);
    fStack_28 = (float)lVar11;
    lVar12 = (longdouble)fsin(lVar10);
    fStack_24 = (float)lVar12;
    lVar13 = (longdouble)fsin(lVar10);
    fStack_34 = (float)-lVar13;
    lVar10 = (longdouble)fcos(lVar10);
    local_1c = (float)lVar10;
    fStack_30 = local_1c;
    afStack_4c[0] = local_c;
    afStack_4c[1] = (float)uStack_8;
    afStack_4c[2] = fStack_4;
    afStack_4c[3] = (float)local_18;
    afStack_4c[4] = (float)uStack_14;
    fStack_38 = fStack_10;
    fStack_58 = 9999.0;
    fStack_64 = -9999.0;
    iVar9 = 0;
    iVar6 = 0;
    fStack_60 = fStack_64;
    fStack_5c = fStack_64;
    fStack_54 = fStack_58;
    fStack_50 = fStack_58;
    do {
      iVar7 = 0;
      iVar8 = 0;
      do {
        fVar1 = *(float *)((int)afStack_4c + iVar8 + 4);
        fVar2 = (float)lVar11 * *(float *)((int)afStack_4c + iVar6) + (float)-lVar13 * fVar1;
        fVar3 = (float)lVar12 * *(float *)((int)afStack_4c + iVar6);
        fVar4 = local_1c * fVar1 + fVar3;
        if (fVar2 < fStack_58) {
          fStack_58 = fVar2;
        }
        if (0x3f < (byte)((fVar2 < fStack_64 |
                           (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fStack_64)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == fStack_64) << 0xe) >> 8)) - 1)) {
          fStack_64 = fVar2;
        }
        if (fVar4 < fStack_54) {
          fStack_54 = fVar4;
        }
        if (0x3f < (byte)((fVar4 < fStack_60 |
                           (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fStack_60)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar4 == fStack_60) << 0xe) >> 8)) - 1)) {
          fStack_60 = fVar4;
        }
        if (fStack_4 < fStack_50) {
          fStack_50 = fStack_4;
        }
        if (0x3f < (byte)((fStack_4 < fStack_5c |
                           (byte)((ushort)((ushort)(NAN(fStack_4) || NAN(fStack_5c)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fStack_4 == fStack_5c) << 0xe) >> 8)) - 1)) {
          fStack_5c = fStack_4;
        }
        fVar3 = local_1c * fVar1 + fVar3;
        if (fVar2 < fStack_58) {
          fStack_58 = fVar2;
        }
        if (0x3f < (byte)((fVar2 < fStack_64 |
                           (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fStack_64)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == fStack_64) << 0xe) >> 8)) - 1)) {
          fStack_64 = fVar2;
        }
        if (fVar3 < fStack_54) {
          fStack_54 = fVar3;
        }
        if (0x3f < (byte)((fVar3 < fStack_60 |
                           (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fStack_60)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar3 == fStack_60) << 0xe) >> 8)) - 1)) {
          fStack_60 = fVar3;
        }
        if (fStack_10 < fStack_50) {
          fStack_50 = fStack_10;
        }
        if (0x3f < (byte)((fStack_10 < fStack_5c |
                           (byte)((ushort)((ushort)(NAN(fStack_10) || NAN(fStack_5c)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fStack_10 == fStack_5c) << 0xe) >> 8)) - 1)) {
          fStack_5c = fStack_10;
        }
        iVar8 = iVar8 + 0xc;
        iVar7 = iVar7 + 1;
      } while (iVar7 < 2);
      iVar6 = iVar6 + 0xc;
      iVar9 = iVar9 + 1;
    } while (iVar9 < 2);
    fStack_50 = 0.0;
    fStack_5c = 1.0;
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&fStack_58,&fStack_64);
  }
  return;
}


