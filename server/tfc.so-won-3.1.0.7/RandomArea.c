// RandomArea__10CLightning  @ 000a1c04
void RandomArea__10CLightning(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  longdouble lVar4;
  int local_b4;
  undefined1 auStack_a4 [16];
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float local_6c;
  float local_68;
  float local_64;
  undefined1 local_60 [16];
  float local_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_b4 = 0;
  do {
    local_c = *(float *)(*param_1 + 8);
    local_8 = *(float *)(*param_1 + 0xc);
    local_4 = *(float *)(*param_1 + 0x10);
    lVar4 = (longdouble)(*DAT_001c118c)(0xbf800000,0x3f800000);
    fVar1 = (float)lVar4;
    lVar4 = (longdouble)(*DAT_001c118c)(0xbf800000,0x3f800000);
    fVar2 = (float)lVar4;
    lVar4 = (longdouble)(*DAT_001c118c)(0xbf800000,0x3f800000);
    local_1c = (float)SQRT(lVar4 * lVar4 + (longdouble)(fVar1 * fVar1) + (longdouble)(fVar2 * fVar2)
                          );
    if ((byte)((byte)((ushort)((ushort)NAN(local_1c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_1c == 0.0) << 0xe) >> 8)) == 0x40) {
      local_24 = 0.0;
      local_20 = 0.0;
      local_1c = 1.0;
    }
    else {
      local_1c = 1.0 / local_1c;
      local_24 = local_1c * fVar1;
      local_20 = local_1c * fVar2;
      local_1c = local_1c * (float)lVar4;
    }
    local_18 = local_24;
    local_14 = local_20;
    local_10 = local_1c;
    local_64 = (float)param_1[0x11e];
    local_6c = local_64 * local_24;
    local_68 = local_64 * local_20;
    local_64 = local_64 * local_1c;
    local_28 = local_c + local_6c;
    local_24 = local_8 + local_68;
    local_20 = local_4 + local_64;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_c,&local_28,1,*(undefined4 *)(*param_1 + 0x208),local_60);
    if ((byte)(1.0 < local_50 | (byte)((ushort)((ushort)NAN(local_50) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_50 == 1.0) << 0xe) >> 8)) != 0x40) {
      do {
        lVar4 = (longdouble)(*DAT_001c118c)(0xbf800000,0x3f800000);
        fVar1 = (float)lVar4;
        lVar4 = (longdouble)(*DAT_001c118c)(0xbf800000,0x3f800000);
        fVar2 = (float)lVar4;
        lVar4 = (longdouble)(*DAT_001c118c)(0xbf800000,0x3f800000);
        local_64 = (float)lVar4;
        fVar3 = local_10 * local_64 + local_14 * fVar2 + local_18 * fVar1;
        local_6c = fVar1;
        local_68 = fVar2;
        local_28 = fVar1;
        local_24 = fVar2;
        local_20 = local_64;
      } while ((byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) == 1);
      local_1c = SQRT(local_64 * local_64 + fVar2 * fVar2 + fVar1 * fVar1);
      if ((byte)((byte)((ushort)((ushort)NAN(local_1c) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_1c == 0.0) << 0xe) >> 8)) == 0x40) {
        local_28 = 0.0;
        local_24 = 0.0;
        local_20 = 1.0;
      }
      else {
        local_20 = 1.0 / local_1c;
        local_28 = local_20 * fVar1;
        local_24 = local_20 * fVar2;
        local_20 = local_20 * local_64;
      }
      local_6c = local_28;
      local_68 = local_24;
      local_64 = local_20;
      fVar1 = (float)param_1[0x11e];
      local_28 = local_c + fVar1 * local_28;
      local_24 = local_8 + fVar1 * local_24;
      local_20 = local_4 + fVar1 * local_20;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (&local_c,&local_28,1,*(undefined4 *)(*param_1 + 0x208),auStack_a4);
      if (((byte)(1.0 < fStack_94 | (byte)((ushort)((ushort)NAN(fStack_94) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fStack_94 == 1.0) << 0xe) >> 8)) != 0x40) &&
         (local_28 = SQRT((fStack_44 - fStack_88) * (fStack_44 - fStack_88) +
                          (fStack_48 - fStack_8c) * (fStack_48 - fStack_8c) +
                          (fStack_4c - fStack_90) * (fStack_4c - fStack_90)),
         (float)param_1[0x11e] * 0.1 <= local_28)) {
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (&fStack_4c,&fStack_90,1,*(undefined4 *)(*param_1 + 0x208),auStack_a4);
        if ((byte)((byte)((ushort)((ushort)NAN(fStack_94) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fStack_94 == 1.0) << 0xe) >> 8)) == 0x40) {
          Zap__10CLightningRC6VectorT1(param_1,&fStack_4c,&fStack_90);
          return;
        }
      }
    }
    local_b4 = local_b4 + 1;
  } while (local_b4 < 10);
  return;
}


