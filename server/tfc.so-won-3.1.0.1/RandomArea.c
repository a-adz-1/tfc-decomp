// RandomArea__10CLightning  @ 00097684
void RandomArea__10CLightning(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  longdouble lVar4;
  int iStack_b4;
  undefined1 auStack_a4 [16];
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  undefined1 auStack_60 [16];
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iStack_b4 = 0;
  do {
    fStack_c = *(float *)(*param_1 + 8);
    fStack_8 = *(float *)(*param_1 + 0xc);
    fStack_4 = *(float *)(*param_1 + 0x10);
    lVar4 = (longdouble)(*DAT_001a7fac)(0xbf800000,0x3f800000);
    fVar1 = (float)lVar4;
    lVar4 = (longdouble)(*DAT_001a7fac)(0xbf800000,0x3f800000);
    fVar2 = (float)lVar4;
    lVar4 = (longdouble)(*DAT_001a7fac)(0xbf800000,0x3f800000);
    fStack_1c = (float)SQRT(lVar4 * lVar4 +
                            (longdouble)(fVar1 * fVar1) + (longdouble)(fVar2 * fVar2));
    if ((byte)((byte)((ushort)((ushort)NAN(fStack_1c) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_1c == 0.0) << 0xe) >> 8)) == 0x40) {
      fStack_24 = 0.0;
      fStack_20 = 0.0;
      fStack_1c = 1.0;
    }
    else {
      fStack_1c = 1.0 / fStack_1c;
      fStack_24 = fStack_1c * fVar1;
      fStack_20 = fStack_1c * fVar2;
      fStack_1c = fStack_1c * (float)lVar4;
    }
    fStack_18 = fStack_24;
    fStack_14 = fStack_20;
    fStack_10 = fStack_1c;
    fStack_64 = (float)param_1[0x102];
    fStack_6c = fStack_64 * fStack_24;
    fStack_68 = fStack_64 * fStack_20;
    fStack_64 = fStack_64 * fStack_1c;
    fStack_28 = fStack_c + fStack_6c;
    fStack_24 = fStack_8 + fStack_68;
    fStack_20 = fStack_4 + fStack_64;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&fStack_c,&fStack_28,1,*(undefined4 *)(*param_1 + 0x208),auStack_60);
    if ((byte)(1.0 < fStack_50 | (byte)((ushort)((ushort)NAN(fStack_50) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_50 == 1.0) << 0xe) >> 8)) != 0x40) {
      do {
        lVar4 = (longdouble)(*DAT_001a7fac)(0xbf800000,0x3f800000);
        fVar1 = (float)lVar4;
        lVar4 = (longdouble)(*DAT_001a7fac)(0xbf800000,0x3f800000);
        fVar2 = (float)lVar4;
        lVar4 = (longdouble)(*DAT_001a7fac)(0xbf800000,0x3f800000);
        fStack_64 = (float)lVar4;
        fVar3 = fStack_10 * fStack_64 + fStack_14 * fVar2 + fStack_18 * fVar1;
        fStack_6c = fVar1;
        fStack_68 = fVar2;
        fStack_28 = fVar1;
        fStack_24 = fVar2;
        fStack_20 = fStack_64;
      } while ((byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) == 1);
      fStack_1c = SQRT(fStack_64 * fStack_64 + fVar2 * fVar2 + fVar1 * fVar1);
      if ((byte)((byte)((ushort)((ushort)NAN(fStack_1c) << 10) >> 8) |
                (byte)((ushort)((ushort)(fStack_1c == 0.0) << 0xe) >> 8)) == 0x40) {
        fStack_28 = 0.0;
        fStack_24 = 0.0;
        fStack_20 = 1.0;
      }
      else {
        fStack_20 = 1.0 / fStack_1c;
        fStack_28 = fStack_20 * fVar1;
        fStack_24 = fStack_20 * fVar2;
        fStack_20 = fStack_20 * fStack_64;
      }
      fStack_6c = fStack_28;
      fStack_68 = fStack_24;
      fStack_64 = fStack_20;
      fVar1 = (float)param_1[0x102];
      fStack_28 = fStack_c + fVar1 * fStack_28;
      fStack_24 = fStack_8 + fVar1 * fStack_24;
      fStack_20 = fStack_4 + fVar1 * fStack_20;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (&fStack_c,&fStack_28,1,*(undefined4 *)(*param_1 + 0x208),auStack_a4);
      if (((byte)(1.0 < fStack_94 | (byte)((ushort)((ushort)NAN(fStack_94) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fStack_94 == 1.0) << 0xe) >> 8)) != 0x40) &&
         (fStack_28 = SQRT((fStack_44 - fStack_88) * (fStack_44 - fStack_88) +
                           (fStack_48 - fStack_8c) * (fStack_48 - fStack_8c) +
                           (fStack_4c - fStack_90) * (fStack_4c - fStack_90)),
         (float)param_1[0x102] * 0.1 <= fStack_28)) {
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (&fStack_4c,&fStack_90,1,*(undefined4 *)(*param_1 + 0x208),auStack_a4);
        if ((byte)((byte)((ushort)((ushort)NAN(fStack_94) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fStack_94 == 1.0) << 0xe) >> 8)) == 0x40) {
          Zap__10CLightningRC6VectorT1(param_1,&fStack_4c,&fStack_90);
          return;
        }
      }
    }
    iStack_b4 = iStack_b4 + 1;
  } while (iStack_b4 < 10);
  return;
}


