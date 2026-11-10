// RandomArea__10CLightning  @ 000acdb0
void RandomArea__10CLightning(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  int local_b8;
  undefined1 auStack_a8 [16];
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float local_70;
  float local_6c;
  float local_68;
  undefined1 auStack_64 [16];
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
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
    local_10 = *(float *)(*param_1 + 8);
    local_c = *(float *)(*param_1 + 0xc);
    local_8 = *(float *)(*param_1 + 0x10);
    lVar4 = (longdouble)(*DAT_0017562c)(0xbf800000,0x3f800000);
    fVar1 = (float)lVar4;
    lVar4 = (longdouble)(*DAT_0017562c)(0xbf800000,0x3f800000);
    lVar5 = (longdouble)(*DAT_0017562c)(0xbf800000,0x3f800000);
    lVar6 = (longdouble)(float)lVar4;
    local_20 = (float)SQRT(lVar5 * lVar5 + lVar6 * lVar6 + (longdouble)fVar1 * (longdouble)fVar1);
    if ((byte)((byte)((ushort)((ushort)NAN(local_20) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_20 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_28 = 0.0;
      local_24 = 0.0;
      local_20 = 1.0;
    }
    else {
      local_20 = 1.0 / local_20;
      local_28 = local_20 * fVar1;
      local_24 = local_20 * (float)lVar4;
      local_20 = local_20 * (float)lVar5;
    }
    local_1c = local_28;
    local_18 = local_24;
    local_14 = local_20;
    local_68 = (float)param_1[0xff];
    local_70 = local_68 * local_28;
    local_6c = local_68 * local_24;
    local_68 = local_68 * local_20;
    local_2c = local_10 + local_70;
    local_28 = local_c + local_6c;
    local_24 = local_8 + local_68;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_10,&local_2c,1,*(undefined4 *)(*param_1 + 0x1e8),auStack_64);
    if ((byte)(1.0 < fStack_54 | (byte)((ushort)((ushort)NAN(fStack_54) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_54 == 1.0) << 0xe) >> 8)) != 0x40) {
      do {
        lVar4 = (longdouble)(*DAT_0017562c)(0xbf800000,0x3f800000);
        fVar1 = (float)lVar4;
        lVar4 = (longdouble)(*DAT_0017562c)(0xbf800000,0x3f800000);
        fVar2 = (float)lVar4;
        lVar4 = (longdouble)(*DAT_0017562c)(0xbf800000,0x3f800000);
        local_68 = (float)lVar4;
        fVar3 = local_14 * local_68 + local_18 * fVar2 + local_1c * fVar1;
        local_70 = fVar1;
        local_6c = fVar2;
        local_2c = fVar1;
        local_28 = fVar2;
        local_24 = local_68;
      } while ((byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) == 1);
      local_20 = SQRT(local_68 * local_68 + fVar2 * fVar2 + fVar1 * fVar1);
      if ((byte)((byte)((ushort)((ushort)NAN(local_20) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_20 == 0.0) << 0xe) >> 8)) == 0x40) {
        local_2c = 0.0;
        local_28 = 0.0;
        local_24 = 1.0;
      }
      else {
        local_24 = 1.0 / local_20;
        local_2c = local_24 * fVar1;
        local_28 = local_24 * fVar2;
        local_24 = local_24 * local_68;
      }
      local_70 = local_2c;
      local_6c = local_28;
      local_68 = local_24;
      fVar1 = (float)param_1[0xff];
      local_2c = local_10 + fVar1 * local_2c;
      local_28 = local_c + fVar1 * local_28;
      local_24 = local_8 + fVar1 * local_24;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (&local_10,&local_2c,1,*(undefined4 *)(*param_1 + 0x1e8),auStack_a8);
      if (((byte)(1.0 < fStack_98 | (byte)((ushort)((ushort)NAN(fStack_98) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fStack_98 == 1.0) << 0xe) >> 8)) != 0x40) &&
         (local_2c = SQRT((fStack_48 - fStack_8c) * (fStack_48 - fStack_8c) +
                          (fStack_4c - fStack_90) * (fStack_4c - fStack_90) +
                          (fStack_50 - fStack_94) * (fStack_50 - fStack_94)),
         (float)param_1[0xff] * 0.1 <= local_2c)) {
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (&fStack_50,&fStack_94,1,*(undefined4 *)(*param_1 + 0x1e8),auStack_a8);
        if ((byte)((byte)((ushort)((ushort)NAN(fStack_98) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fStack_98 == 1.0) << 0xe) >> 8)) == 0x40) {
          Zap__10CLightningRC6VectorT1(param_1,&fStack_50,&fStack_94);
          return;
        }
      }
    }
    local_b8 = local_b8 + 1;
  } while (local_b8 < 10);
  return;
}


