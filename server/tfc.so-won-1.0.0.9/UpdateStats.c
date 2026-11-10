// UpdateStats__FP11CBasePlayer  @ 000d6180
void UpdateStats__FP11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  longdouble lVar9;
  float local_c8;
  undefined1 local_b0 [8];
  undefined4 local_a8;
  int local_84 [32];
  
  piVar7 = param_1 + 0x20f;
  piVar8 = local_84;
  for (iVar5 = 0x20; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar8 = *piVar7;
    piVar7 = piVar7 + 1;
    piVar8 = piVar8 + 1;
  }
  fVar1 = *gpGlobals;
  if ((byte)(fVar1 < (float)gStats._24_4_ |
             (byte)((ushort)((ushort)(NAN(fVar1) || NAN((float)gStats._24_4_)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == (float)gStats._24_4_) << 0xe) >> 8)) == 1) {
    gStats._16_4_ = gStats._20_4_;
    gStats._24_4_ = fVar1;
  }
  gStats._20_4_ = (*gpGlobals - (float)gStats._24_4_) + (float)gStats._20_4_;
  gStats._24_4_ = *gpGlobals;
  iVar5 = 0;
  do {
    iVar6 = param_1[iVar5 + 0x206];
    if (iVar6 != 0) {
      do {
        memset(local_b0,0,0x2c);
        (**(code **)(*(int *)(iVar6 + 0x3c8) + 0x110))(iVar6,local_b0);
        iVar4 = GetAmmoIndex__11CBasePlayerPCc(local_a8);
        if (-1 < iVar4) {
          local_84[iVar4] = local_84[iVar4] + *(int *)(iVar6 + 0x410);
        }
        iVar6 = *(int *)(iVar6 + 0x3ec);
      } while (iVar6 != 0);
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 6);
  local_c8 = 0.0;
  iVar5 = 1;
  do {
    lVar9 = (longdouble)AmmoDamage__FPCc((&_15CBasePlayerItem_AmmoInfoArray)[iVar5 * 2]);
    local_c8 = (float)(lVar9 * (longdouble)local_84[iVar5] + (longdouble)local_c8);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x20);
  fVar1 = *(float *)(*param_1 + 0x19c);
  fVar1 = fVar1 + fVar1 + *(float *)(*param_1 + 0x140);
  fVar2 = ABS(local_c8 - (float)(int)gStats._0_4_);
  bVar3 = false;
  if ((fVar1 <= 0.0) &&
     ((byte)(0.0 < (float)gStats._4_4_ |
             (byte)((ushort)((ushort)NAN((float)gStats._4_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)gStats._4_4_ == 0.0) << 0xe) >> 8)) == 1)) {
    bVar3 = true;
  }
  if ((((byte)(10.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 10.0) << 0xe) >> 8)) != 1) &&
      (ABS(fVar1 - (float)gStats._4_4_) <= 10.0)) || (bVar3)) {
    if ((((byte)(0.0 < (float)gStats._12_4_ |
                 (byte)((ushort)((ushort)NAN((float)gStats._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)gStats._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) &&
        ((byte)((float)gStats._12_4_ < (float)gStats._20_4_ |
                (byte)((ushort)((ushort)(NAN((float)gStats._12_4_) || NAN((float)gStats._20_4_)) <<
                               10) >> 8) |
               (byte)((ushort)((ushort)((float)gStats._12_4_ == (float)gStats._20_4_) << 0xe) >> 8))
         == 1)) || (bVar3)) {
      lVar9 = (longdouble)(*DAT_001755a4)("skill");
      UpdateStatsFile__FfPcffi
                (gStats._16_4_,(int)gpGlobals[3] + (int)gpGlobals[0x26],fVar1,local_c8,
                 (int)ROUND(lVar9));
      gStats._0_4_ = (undefined4)ROUND(local_c8);
      gStats._8_4_ = gStats._20_4_;
      gStats._12_4_ = 0;
      gStats._4_4_ = fVar1;
    }
  }
  else {
    if ((byte)((byte)((ushort)((ushort)NAN((float)gStats._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)gStats._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
      gStats._16_4_ = gStats._20_4_;
    }
    gStats._0_4_ = (undefined4)ROUND(local_c8);
    gStats._12_4_ = (float)gStats._20_4_ + 3.0;
    gStats._4_4_ = fVar1;
  }
  return;
}


