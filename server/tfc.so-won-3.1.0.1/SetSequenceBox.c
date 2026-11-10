// SetSequenceBox__FP12CBaseMonster  @ 000b6808
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c [5];
  float local_38;
  float local_34;
  float local_30;
  float local_28;
  float local_24;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  undefined4 local_8;
  float local_4;
  
  uVar5 = (*DAT_001a7f68)(*(undefined4 *)(*param_1 + 0x208));
  iVar6 = ExtractBbox__FPviPfT2(uVar5,*(undefined4 *)(*param_1 + 0x128),&local_c,&local_18);
  if (iVar6 != 0) {
    lVar10 = (longdouble)(*(float *)(*param_1 + 0x54) * 0.017453292);
    lVar11 = (longdouble)fcos(lVar10);
    local_28 = (float)lVar11;
    lVar12 = (longdouble)fsin(lVar10);
    local_24 = (float)lVar12;
    lVar13 = (longdouble)fsin(lVar10);
    local_34 = (float)-lVar13;
    lVar10 = (longdouble)fcos(lVar10);
    local_1c = (float)lVar10;
    local_30 = local_1c;
    local_4c[0] = local_c;
    local_4c[1] = (float)local_8;
    local_4c[2] = local_4;
    local_4c[3] = (float)local_18;
    local_4c[4] = (float)local_14;
    local_38 = local_10;
    local_58 = _FUN_00138470;
    local_64 = -9999.0;
    iVar9 = 0;
    iVar6 = 0;
    local_60 = local_64;
    local_5c = local_64;
    local_54 = local_58;
    local_50 = local_58;
    do {
      iVar7 = 0;
      iVar8 = 0;
      do {
        fVar1 = *(float *)((int)local_4c + iVar8 + 4);
        fVar2 = (float)lVar11 * *(float *)((int)local_4c + iVar6) + (float)-lVar13 * fVar1;
        fVar3 = (float)lVar12 * *(float *)((int)local_4c + iVar6);
        fVar4 = local_1c * fVar1 + fVar3;
        if (fVar2 < local_58) {
          local_58 = fVar2;
        }
        if (0x3f < (byte)((fVar2 < local_64 |
                           (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_64)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == local_64) << 0xe) >> 8)) - 1)) {
          local_64 = fVar2;
        }
        if (fVar4 < local_54) {
          local_54 = fVar4;
        }
        if (0x3f < (byte)((fVar4 < local_60 |
                           (byte)((ushort)((ushort)(NAN(fVar4) || NAN(local_60)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar4 == local_60) << 0xe) >> 8)) - 1)) {
          local_60 = fVar4;
        }
        if (local_4 < local_50) {
          local_50 = local_4;
        }
        if (0x3f < (byte)((local_4 < local_5c |
                           (byte)((ushort)((ushort)(NAN(local_4) || NAN(local_5c)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(local_4 == local_5c) << 0xe) >> 8)) - 1)) {
          local_5c = local_4;
        }
        fVar3 = local_1c * fVar1 + fVar3;
        if (fVar2 < local_58) {
          local_58 = fVar2;
        }
        if (0x3f < (byte)((fVar2 < local_64 |
                           (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_64)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == local_64) << 0xe) >> 8)) - 1)) {
          local_64 = fVar2;
        }
        if (fVar3 < local_54) {
          local_54 = fVar3;
        }
        if (0x3f < (byte)((fVar3 < local_60 |
                           (byte)((ushort)((ushort)(NAN(fVar3) || NAN(local_60)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar3 == local_60) << 0xe) >> 8)) - 1)) {
          local_60 = fVar3;
        }
        if (local_10 < local_50) {
          local_50 = local_10;
        }
        if (0x3f < (byte)((local_10 < local_5c |
                           (byte)((ushort)((ushort)(NAN(local_10) || NAN(local_5c)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(local_10 == local_5c) << 0xe) >> 8)) - 1)) {
          local_5c = local_10;
        }
        iVar8 = iVar8 + 0xc;
        iVar7 = iVar7 + 1;
      } while (iVar7 < 2);
      iVar6 = iVar6 + 0xc;
      iVar9 = iVar9 + 1;
    } while (iVar9 < 2);
    local_50 = 0.0;
    local_5c = 1.0;
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_58,&local_64);
  }
  return;
}


