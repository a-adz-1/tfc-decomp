// UpdateStats__FP11CBasePlayer  @ 000c7b44
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UpdateStats__FP11CBasePlayer(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  bool bVar9;
  longdouble lVar10;
  longdouble lVar11;
  longdouble lVar12;
  longdouble lVar13;
  float fStack_c4;
  int local_c0;
  undefined1 auStack_ac [8];
  undefined4 uStack_a4;
  int local_80 [32];
  
  piVar7 = param_1 + 0x214;
  piVar8 = local_80;
  for (iVar6 = 0x20; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar8 = *piVar7;
    piVar7 = piVar7 + 1;
    piVar8 = piVar8 + 1;
  }
  if (*gpGlobals < (float)gStats._24_4_) {
    gStats._16_4_ = gStats._20_4_;
    gStats._24_4_ = *gpGlobals;
  }
  gStats._20_4_ = (*gpGlobals - (float)gStats._24_4_) + (float)gStats._20_4_;
  gStats._24_4_ = *gpGlobals;
  local_c0 = 0;
  do {
    iVar6 = param_1[local_c0 + 0x20b];
    if (iVar6 != 0) {
      do {
        memset(auStack_ac,0,0x2c);
        (**(code **)(*(int *)(iVar6 + 0x3d4) + 0x110))(iVar6,auStack_ac);
        iVar5 = GetAmmoIndex__11CBasePlayerPCc(uStack_a4);
        if (-1 < iVar5) {
          local_80[iVar5] = local_80[iVar5] + *(int *)(iVar6 + 0x440);
        }
        iVar6 = *(int *)(iVar6 + 0x3f8);
      } while (iVar6 != 0);
    }
    iVar6 = param_1[local_c0 + 0x20c];
    if (iVar6 != 0) {
      do {
        memset(auStack_ac,0,0x2c);
        (**(code **)(*(int *)(iVar6 + 0x3d4) + 0x110))(iVar6,auStack_ac);
        iVar5 = GetAmmoIndex__11CBasePlayerPCc(uStack_a4);
        if (-1 < iVar5) {
          local_80[iVar5] = local_80[iVar5] + *(int *)(iVar6 + 0x440);
        }
        iVar6 = *(int *)(iVar6 + 0x3f8);
      } while (iVar6 != 0);
    }
    local_c0 = local_c0 + 2;
  } while (local_c0 < 6);
  lVar10 = (longdouble)AmmoDamage__FPCc(DAT_001b5388);
  lVar11 = (longdouble)AmmoDamage__FPCc(DAT_001b5390);
  lVar12 = (longdouble)AmmoDamage__FPCc(DAT_001b5398);
  fStack_c4 = (float)(lVar12 * (longdouble)local_80[3] +
                     (longdouble)
                     (float)(lVar11 * (longdouble)local_80[2] +
                            (longdouble)(float)(lVar10 * (longdouble)local_80[1])));
  local_c0 = 4;
  do {
    lVar10 = (longdouble)AmmoDamage__FPCc((&_15CBasePlayerItem_AmmoInfoArray)[local_c0 * 2]);
    iVar6 = local_80[local_c0];
    lVar11 = (longdouble)AmmoDamage__FPCc((&_15CBasePlayerItem_AmmoInfoArray)[(local_c0 + 1) * 2]);
    iVar5 = local_80[local_c0 + 1];
    lVar12 = (longdouble)AmmoDamage__FPCc((&_15CBasePlayerItem_AmmoInfoArray)[(local_c0 + 2) * 2]);
    iVar1 = local_80[local_c0 + 2];
    lVar13 = (longdouble)AmmoDamage__FPCc((&_15CBasePlayerItem_AmmoInfoArray)[(local_c0 + 3) * 2]);
    fStack_c4 = (float)(lVar13 * (longdouble)local_80[local_c0 + 3] +
                       (longdouble)
                       (float)(lVar12 * (longdouble)iVar1 +
                              (longdouble)
                              (float)(lVar11 * (longdouble)iVar5 +
                                     (longdouble)
                                     (float)(lVar10 * (longdouble)iVar6 + (longdouble)fStack_c4))));
    local_c0 = local_c0 + 4;
  } while (local_c0 < 0x20);
  fVar2 = *(float *)(*param_1 + 0x1bc);
  fVar2 = fVar2 + fVar2 + *(float *)(*param_1 + 0x160);
  fVar3 = ABS(fStack_c4 - (float)(int)gStats._0_4_);
  fVar4 = ABS(fVar2 - (float)gStats._4_4_);
  bVar9 = false;
  if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1) {
    bVar9 = (byte)(0.0 < (float)gStats._4_4_ |
                   (byte)((ushort)((ushort)NAN((float)gStats._4_4_) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)gStats._4_4_ == 0.0) << 0xe) >> 8)) == 1;
  }
  if ((((byte)(_FUN_0013a3cc < fVar3 |
               (byte)((ushort)((ushort)(NAN(_FUN_0013a3cc) || NAN(fVar3)) << 10) >> 8) |
              (byte)((ushort)((ushort)(_FUN_0013a3cc == fVar3) << 0xe) >> 8)) != 1) &&
      ((byte)((fVar4 < _FUN_0013a3cc |
               (byte)((ushort)((ushort)(NAN(fVar4) || NAN(_FUN_0013a3cc)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar4 == _FUN_0013a3cc) << 0xe) >> 8)) - 1) < 0x40)) ||
     (bVar9)) {
    if ((((byte)(0.0 < (float)gStats._12_4_ |
                 (byte)((ushort)((ushort)NAN((float)gStats._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)gStats._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) &&
        ((byte)((float)gStats._12_4_ < (float)gStats._20_4_ |
                (byte)((ushort)((ushort)(NAN((float)gStats._12_4_) || NAN((float)gStats._20_4_)) <<
                               10) >> 8) |
               (byte)((ushort)((ushort)((float)gStats._12_4_ == (float)gStats._20_4_) << 0xe) >> 8))
         == 1)) || (bVar9)) {
      lVar10 = (longdouble)(*DAT_001a7f24)("skill");
      UpdateStatsFile__FfPcffi
                (gStats._16_4_,(int)gpGlobals[3] + (int)gpGlobals[0x26],fVar2,fStack_c4,
                 (int)ROUND(lVar10));
      gStats._0_4_ = (undefined4)ROUND(fStack_c4);
      gStats._8_4_ = gStats._20_4_;
      gStats._12_4_ = 0;
      gStats._4_4_ = fVar2;
    }
  }
  else {
    if ((byte)((byte)((ushort)((ushort)NAN((float)gStats._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)gStats._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
      gStats._16_4_ = gStats._20_4_;
    }
    gStats._0_4_ = (undefined4)ROUND(fStack_c4);
    gStats._12_4_ = (float)gStats._20_4_ + 3.0;
    gStats._4_4_ = fVar2;
  }
  return;
}


