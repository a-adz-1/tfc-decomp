// SetSequenceBox__FP12CBaseMonster  @ 000c7b30
void SetSequenceBox__FP12CBaseMonster(int *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  longdouble lVar7;
  longdouble lVar8;
  int iStack_88;
  int iStack_84;
  float afStack_80 [4];
  float fStack_70;
  float fStack_6c;
  float afStack_68 [12];
  float local_38;
  float local_34;
  float local_2c;
  float local_28;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar3 = (*DAT_001755e8)(*(undefined4 *)(*param_1 + 0x1e8));
  iVar4 = ExtractBbox__FPviPfT2(uVar3,*(undefined4 *)(*param_1 + 0x108),&local_10,&local_1c);
  if (iVar4 != 0) {
    lVar7 = (longdouble)(*(float *)(*param_1 + 0x54) * 0.017453292);
    lVar8 = (longdouble)fcos(lVar7);
    local_2c = (float)lVar8;
    lVar8 = (longdouble)fsin(lVar7);
    local_28 = (float)lVar8;
    lVar8 = (longdouble)fsin(lVar7);
    local_38 = (float)-lVar8;
    lVar7 = (longdouble)fcos(lVar7);
    local_34 = (float)lVar7;
    iVar4 = 1;
    do {
      bVar6 = iVar4 != 0;
      iVar4 = iVar4 + -1;
    } while (bVar6);
    afStack_68[6] = (float)local_10;
    afStack_68[7] = (float)local_c;
    afStack_68[8] = (float)local_8;
    afStack_68[9] = (float)local_1c;
    afStack_68[10] = (float)local_18;
    afStack_68[0xb] = (float)local_14;
    afStack_68[3] = 9999.0;
    afStack_68[4] = 9999.0;
    afStack_68[5] = 9999.0;
    afStack_68[0] = -9999.0;
    afStack_68[1] = -9999.0;
    afStack_68[2] = -9999.0;
    iStack_84 = 0;
    do {
      afStack_80[3] = afStack_68[iStack_84 * 3 + 6];
      iVar4 = 0;
      do {
        fStack_70 = afStack_68[iVar4 * 3 + 7];
        iVar5 = 0;
        do {
          fStack_6c = afStack_68[iVar5 * 3 + 8];
          afStack_80[0] = local_38 * fStack_70 + local_2c * afStack_80[3];
          afStack_80[1] = local_34 * fStack_70 + local_28 * afStack_80[3];
          afStack_80[2] = fStack_6c;
          iStack_88 = 0;
          do {
            fVar1 = afStack_80[iStack_88];
            fVar2 = afStack_68[iStack_88 + 3];
            if ((byte)(fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
              afStack_68[iStack_88 + 3] = fVar1;
            }
            if (afStack_68[iStack_88] < afStack_80[iStack_88]) {
              afStack_68[iStack_88] = afStack_80[iStack_88];
            }
            iStack_88 = iStack_88 + 1;
          } while (iStack_88 < 3);
          iVar5 = iVar5 + 1;
        } while (iVar5 < 2);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 2);
      iStack_84 = iStack_84 + 1;
    } while (iStack_84 < 2);
    afStack_68[5] = 0.0;
    afStack_68[2] = 1.0;
    local_20 = local_34;
    UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,afStack_68 + 3,afStack_68);
  }
  return;
}


