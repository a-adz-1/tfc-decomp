// SetSequenceBox__FP12CBaseMonster  @ 000c0b70
void SetSequenceBox__FP12CBaseMonster(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  longdouble lVar9;
  longdouble lVar10;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50 [4];
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  float local_34;
  float local_2c;
  float local_28;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar4 = (*DAT_0019f7c8)(*(undefined4 *)(*param_1 + 0x208));
  iVar5 = ExtractBbox__FPviPfT2(uVar4,*(undefined4 *)(*param_1 + 0x128),&local_10,&local_1c);
  if (iVar5 != 0) {
    lVar9 = (longdouble)(*(float *)(*param_1 + 0x54) * 0.017453292);
    lVar10 = (longdouble)fcos(lVar9);
    local_2c = (float)lVar10;
    lVar10 = (longdouble)fsin(lVar9);
    local_28 = (float)lVar10;
    lVar10 = (longdouble)fsin(lVar9);
    local_38 = (float)-lVar10;
    lVar9 = (longdouble)fcos(lVar9);
    local_34 = (float)lVar9;
    iVar5 = 1;
    do {
      bVar8 = iVar5 != 0;
      iVar5 = iVar5 + -1;
    } while (bVar8);
    local_50[0] = local_10;
    local_50[1] = (float)local_c;
    local_50[2] = (float)local_8;
    local_50[3] = (float)local_1c;
    local_40 = local_18;
    local_3c = local_14;
    local_5c = 9999.0;
    local_68 = -9999.0;
    iVar5 = 0;
    local_64 = local_68;
    local_60 = local_68;
    local_58 = local_5c;
    local_54 = local_5c;
    do {
      iVar6 = 0;
      do {
        fVar2 = local_2c * local_50[iVar5 * 3] + local_38 * local_50[iVar6 * 3 + 1];
        iVar7 = 0;
        fVar3 = local_28 * local_50[iVar5 * 3] + local_34 * local_50[iVar6 * 3 + 1];
        do {
          fVar1 = local_50[iVar7 * 3 + 2];
          if (fVar2 < local_5c) {
            local_5c = fVar2;
          }
          if (0x3f < (byte)((fVar2 < local_68 |
                             (byte)((ushort)((ushort)(NAN(fVar2) || NAN(local_68)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar2 == local_68) << 0xe) >> 8)) - 1)) {
            local_68 = fVar2;
          }
          if (fVar3 < local_58) {
            local_58 = fVar3;
          }
          if (0x3f < (byte)((fVar3 < local_64 |
                             (byte)((ushort)((ushort)(NAN(fVar3) || NAN(local_64)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar3 == local_64) << 0xe) >> 8)) - 1)) {
            local_64 = fVar3;
          }
          if (fVar1 < local_54) {
            local_54 = fVar1;
          }
          if (0x3f < (byte)((fVar1 < local_60 |
                             (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_60)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar1 == local_60) << 0xe) >> 8)) - 1)) {
            local_60 = fVar1;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < 2);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 2);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
    local_54 = 0.0;
    local_60 = 1.0;
    local_20 = local_34;
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_5c,&local_68);
  }
  return;
}


