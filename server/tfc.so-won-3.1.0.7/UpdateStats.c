// UpdateStats__FP11CBasePlayer  @ 000d30c4
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
  float local_c4;
  int local_c0;
  undefined1 local_ac [8];
  undefined4 local_a4;
  int local_80 [32];
  
  piVar7 = param_1 + 0x231;
  piVar8 = local_80;
  for (iVar6 = 0x20; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar8 = *piVar7;
    piVar7 = piVar7 + 1;
    piVar8 = piVar8 + 1;
  }
  if (*gpGlobals < DAT_00162168) {
    DAT_00162160 = DAT_00162164;
    DAT_00162168 = *gpGlobals;
  }
  DAT_00162164 = (*gpGlobals - DAT_00162168) + DAT_00162164;
  DAT_00162168 = *gpGlobals;
  local_c0 = 0;
  do {
    iVar6 = param_1[local_c0 + 0x227];
    if (iVar6 != 0) {
      do {
        memset(local_ac,0,0x2c);
        (**(code **)(*(int *)(iVar6 + 0x444) + 0x118))(iVar6,local_ac);
        iVar5 = GetAmmoIndex__11CBasePlayerPCc(local_a4);
        if (-1 < iVar5) {
          local_80[iVar5] = local_80[iVar5] + *(int *)(iVar6 + 0x4b0);
        }
        iVar6 = *(int *)(iVar6 + 0x468);
      } while (iVar6 != 0);
    }
    iVar6 = param_1[local_c0 + 0x228];
    if (iVar6 != 0) {
      do {
        memset(local_ac,0,0x2c);
        (**(code **)(*(int *)(iVar6 + 0x444) + 0x118))(iVar6,local_ac);
        iVar5 = GetAmmoIndex__11CBasePlayerPCc(local_a4);
        if (-1 < iVar5) {
          local_80[iVar5] = local_80[iVar5] + *(int *)(iVar6 + 0x4b0);
        }
        iVar6 = *(int *)(iVar6 + 0x468);
      } while (iVar6 != 0);
    }
    local_c0 = local_c0 + 2;
  } while (local_c0 < 6);
  lVar10 = (longdouble)AmmoDamage__FPCc(DAT_001ce748);
  lVar11 = (longdouble)AmmoDamage__FPCc(DAT_001ce750);
  lVar12 = (longdouble)AmmoDamage__FPCc(DAT_001ce758);
  local_c4 = (float)(lVar12 * (longdouble)local_80[3] +
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
    local_c4 = (float)(lVar13 * (longdouble)local_80[local_c0 + 3] +
                      (longdouble)
                      (float)(lVar12 * (longdouble)iVar1 +
                             (longdouble)
                             (float)(lVar11 * (longdouble)iVar5 +
                                    (longdouble)
                                    (float)(lVar10 * (longdouble)iVar6 + (longdouble)local_c4))));
    local_c0 = local_c0 + 4;
  } while (local_c0 < 0x20);
  fVar2 = *(float *)(*param_1 + 0x1bc);
  fVar2 = fVar2 + fVar2 + *(float *)(*param_1 + 0x160);
  fVar3 = ABS(local_c4 - (float)gStats);
  fVar4 = ABS(fVar2 - DAT_00162154);
  bVar9 = false;
  if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1) {
    bVar9 = (byte)(0.0 < DAT_00162154 | (byte)((ushort)((ushort)NAN(DAT_00162154) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_00162154 == 0.0) << 0xe) >> 8)) == 1;
  }
  if ((((byte)(10.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar3 == 10.0) << 0xe) >> 8)) != 1) &&
      ((byte)((fVar4 < 10.0 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar4 == 10.0) << 0xe) >> 8)) - 1) < 0x40)) || (bVar9)) {
    if ((((byte)(0.0 < DAT_0016215c | (byte)((ushort)((ushort)NAN(DAT_0016215c) << 10) >> 8) |
                (byte)((ushort)((ushort)(DAT_0016215c == 0.0) << 0xe) >> 8)) != 0x40) &&
        ((byte)(DAT_0016215c < DAT_00162164 |
                (byte)((ushort)((ushort)(NAN(DAT_0016215c) || NAN(DAT_00162164)) << 10) >> 8) |
               (byte)((ushort)((ushort)(DAT_0016215c == DAT_00162164) << 0xe) >> 8)) == 1)) ||
       (bVar9)) {
      lVar10 = (longdouble)(*DAT_001c1104)("skill");
      UpdateStatsFile__FfPcffi
                (DAT_00162160,(int)gpGlobals[3] + (int)gpGlobals[0x26],fVar2,local_c4,
                 (int)ROUND(lVar10));
      gStats = (int)ROUND(local_c4);
      DAT_00162158 = DAT_00162164;
      DAT_0016215c = 0.0;
      DAT_00162154 = fVar2;
    }
  }
  else {
    if ((byte)((byte)((ushort)((ushort)NAN(DAT_0016215c) << 10) >> 8) |
              (byte)((ushort)((ushort)(DAT_0016215c == 0.0) << 0xe) >> 8)) == 0x40) {
      DAT_00162160 = DAT_00162164;
    }
    gStats = (int)ROUND(local_c4);
    DAT_0016215c = DAT_00162164 + 3.0;
    DAT_00162154 = fVar2;
  }
  return;
}


