// VecCheckToss__FP9entvars_sRC6VectorG6Vectorf  @ 000b21b8
float * VecCheckToss__FP9entvars_sRC6VectorG6Vectorf
                  (float *param_1,int param_2,float *param_3,float *param_4,float param_5)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined1 auStack_3c [16];
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  float fStack_20;
  
  lVar3 = (longdouble)(*DAT_0019f784)("sv_gravity");
  if (param_4[2] - param_3[2] <= 500.0) {
    UTIL_MakeVectors__FRC6Vector(param_2 + 0x50);
    lVar4 = (longdouble)(*DAT_0019f80c)(0xc1000000,0x41000000);
    lVar5 = (longdouble)(*DAT_0019f80c)(0xc1800000,0x41800000);
    lVar5 = (longdouble)(float)lVar4 + lVar5;
    fStack_84 = (float)((longdouble)*(float *)(gpGlobals + 0x40) * lVar5 + (longdouble)*param_4);
    fStack_80 = (float)((longdouble)*(float *)(gpGlobals + 0x44) * lVar5 + (longdouble)param_4[1]);
    fStack_7c = (float)(lVar5 * (longdouble)*(float *)(gpGlobals + 0x48) + (longdouble)param_4[2]);
    *param_4 = fStack_84;
    param_4[1] = fStack_80;
    param_4[2] = fStack_7c;
    lVar4 = (longdouble)(*DAT_0019f80c)(0xc1000000,0x41000000);
    lVar5 = (longdouble)(*DAT_0019f80c)(0xc1800000,0x41800000);
    lVar5 = (longdouble)(float)lVar4 + lVar5;
    fVar1 = *(float *)(gpGlobals + 0x2c);
    fVar2 = *(float *)(gpGlobals + 0x30);
    *param_4 = (float)((longdouble)*(float *)(gpGlobals + 0x28) * lVar5 + (longdouble)*param_4);
    param_4[1] = (float)((longdouble)fVar1 * lVar5 + (longdouble)param_4[1]);
    param_4[2] = (float)(lVar5 * (longdouble)fVar2 + (longdouble)param_4[2]);
    fStack_84 = *param_3 + (*param_4 - *param_3) * 0.5;
    fStack_80 = param_3[1] + (param_4[1] - param_3[1]) * 0.5;
    fStack_40 = param_3[2] + (param_4[2] - param_3[2]) * 0.5;
    fStack_7c = fStack_40 + 500.0;
    fStack_48 = fStack_84;
    fStack_44 = fStack_80;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&fStack_48,&fStack_84,1,*(undefined4 *)(param_2 + 0x208),auStack_3c);
    fStack_48 = fStack_28;
    fStack_4c = fStack_20 - 15.0;
    fStack_44 = (float)uStack_24;
    fVar1 = param_3[2];
    if (((byte)(fStack_4c < fVar1 |
                (byte)((ushort)((ushort)(NAN(fStack_4c) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fStack_4c == fVar1) << 0xe) >> 8)) != 1) &&
       (param_4[2] <= fStack_4c)) {
      fVar2 = (float)(lVar3 * (longdouble)param_5) * 0.5;
      fStack_64 = SQRT((fStack_4c - fVar1) / fVar2);
      if ((byte)((0.1 < fStack_64 | (byte)((ushort)((ushort)NAN(fStack_64) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fStack_64 == 0.1) << 0xe) >> 8)) - 1) < 0x40) {
        fStack_68 = fStack_64 + SQRT((fStack_4c - param_4[2]) / fVar2);
        fStack_6c = (*param_4 - *param_3) / fStack_68;
        fStack_68 = (param_4[1] - param_3[1]) / fStack_68;
        fStack_54 = *param_3 + fStack_6c * fStack_64;
        fStack_50 = param_3[1] + fStack_68 * fStack_64;
        fStack_64 = (float)(lVar3 * (longdouble)param_5) * fStack_64;
        fStack_40 = fStack_4c;
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (param_3,&fStack_54,0,*(undefined4 *)(param_2 + 0x208),auStack_3c);
        if (((byte)((byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) == 0x40) &&
           (UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                      (param_4,&fStack_54,1,*(undefined4 *)(param_2 + 0x208),auStack_3c),
           (byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) == 0x40)) {
          *param_1 = fStack_6c;
          param_1[1] = fStack_68;
          goto LAB_000b26ae;
        }
      }
    }
  }
  *param_1 = g_vecZero;
  param_1[1] = DAT_0019f664;
  fStack_64 = DAT_0019f668;
LAB_000b26ae:
  param_1[2] = fStack_64;
  return param_1;
}


