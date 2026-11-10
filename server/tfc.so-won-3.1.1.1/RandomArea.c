// RandomArea__10CLightning  @ 000a0bac
void RandomArea__10CLightning(int *param_1)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  int local_b8;
  undefined1 local_a8 [16];
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_70;
  float local_6c;
  float local_68;
  undefined1 local_64 [16];
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_b8 = 0;
  do {
    iVar2 = *param_1;
    local_10 = *(float *)(iVar2 + 8);
    local_c = *(float *)(iVar2 + 0xc);
    local_8 = *(float *)(iVar2 + 0x10);
    lVar3 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
    lVar4 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
    lVar5 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
    lVar6 = (longdouble)(float)SQRT(lVar5 * lVar5 + lVar4 * lVar4 + lVar3 * lVar3);
    lVar7 = (longdouble)0;
    if ((byte)((byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar6)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar7 == lVar6) << 0xe) >> 8)) == 0x40) {
      local_20 = 1.0;
      lVar4 = lVar7;
    }
    else {
      lVar6 = (longdouble)1 / lVar6;
      lVar7 = lVar3 * lVar6;
      lVar4 = lVar4 * lVar6;
      local_20 = (float)(lVar6 * lVar5);
    }
    local_24 = (float)lVar4;
    local_28 = (float)lVar7;
    local_1c = local_28;
    local_18 = local_24;
    local_14 = local_20;
    local_68 = (float)param_1[0x122];
    local_70 = local_28 * local_68;
    local_2c = local_70 + local_10;
    local_6c = local_24 * local_68;
    local_28 = local_6c + local_c;
    local_68 = local_68 * local_20;
    local_24 = local_68 + local_8;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_10,&local_2c,1,*(undefined4 *)(*param_1 + 0x208),local_64);
    if ((byte)(1.0 < local_54 | (byte)((ushort)((ushort)NAN(local_54) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_54 == 1.0) << 0xe) >> 8)) != 0x40) {
      do {
        lVar7 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
        fVar1 = (float)lVar7;
        lVar7 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
        lVar4 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
        local_6c = (float)lVar7;
        local_68 = (float)lVar4;
        local_70 = fVar1;
        local_2c = fVar1;
        local_28 = local_6c;
        local_24 = local_68;
      } while (0.0 < local_14 * local_68 + local_18 * local_6c + local_1c * fVar1);
      local_20 = SQRT(local_68 * local_68 + local_6c * local_6c + fVar1 * fVar1);
      if ((byte)((byte)((ushort)((ushort)NAN(local_20) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_20 == 0.0) << 0xe) >> 8)) == 0x40) {
        local_2c = 0.0;
        local_28 = 0.0;
        local_24 = 1.0;
      }
      else {
        local_24 = 1.0 / local_20;
        local_2c = fVar1 * local_24;
        local_28 = local_6c * local_24;
        local_24 = local_68 * local_24;
      }
      local_70 = local_2c;
      local_6c = local_28;
      local_68 = local_24;
      fVar1 = (float)param_1[0x122];
      local_2c = local_2c * fVar1 + local_10;
      local_28 = local_28 * fVar1 + local_c;
      local_24 = fVar1 * local_24 + local_8;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (&local_10,&local_2c,1,*(undefined4 *)(*param_1 + 0x208),local_a8);
      if (((byte)(1.0 < local_98 | (byte)((ushort)((ushort)NAN(local_98) << 10) >> 8) |
                 (byte)((ushort)((ushort)(local_98 == 1.0) << 0xe) >> 8)) != 0x40) &&
         (local_2c = SQRT((local_48 - local_8c) * (local_48 - local_8c) +
                          (local_4c - local_90) * (local_4c - local_90) +
                          (local_50 - local_94) * (local_50 - local_94)),
         (float)param_1[0x122] * 0.1 <= local_2c)) {
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (&local_50,&local_94,1,*(undefined4 *)(*param_1 + 0x208),local_a8);
        if ((byte)((byte)((ushort)((ushort)NAN(local_98) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_98 == 1.0) << 0xe) >> 8)) == 0x40) {
          Zap__10CLightningRC6VectorT1(param_1,&local_50,&local_94);
          return;
        }
      }
    }
    local_b8 = local_b8 + 1;
  } while (local_b8 < 10);
  return;
}


