// VecCheckToss__FP9entvars_sRC6VectorG6Vectorf  @ 000b2ce8
float * VecCheckToss__FP9entvars_sRC6VectorG6Vectorf
                  (float *param_1,int param_2,float *param_3,float *param_4,float param_5)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  undefined1 auStack_38 [16];
  float fStack_28;
  float fStack_24;
  undefined4 uStack_20;
  float fStack_1c;
  
  lVar3 = (longdouble)(*DAT_001c1104)("sv_gravity");
  if (param_4[2] - param_3[2] <= 500.0) {
    UTIL_MakeVectors__FRC6Vector(param_2 + 0x50);
    lVar4 = (longdouble)(*DAT_001c118c)(0xc1000000,0x41000000);
    lVar5 = (longdouble)(*DAT_001c118c)(0xc1800000,0x41800000);
    lVar5 = (longdouble)(float)lVar4 + lVar5;
    fStack_80 = *param_4 + (float)(lVar5 * (longdouble)*(float *)(gpGlobals + 0x40));
    fStack_7c = param_4[1] + (float)(lVar5 * (longdouble)*(float *)(gpGlobals + 0x44));
    fStack_78 = param_4[2] + (float)(lVar5 * (longdouble)*(float *)(gpGlobals + 0x48));
    *param_4 = fStack_80;
    param_4[1] = fStack_7c;
    param_4[2] = fStack_78;
    lVar4 = (longdouble)(*DAT_001c118c)(0xc1000000,0x41000000);
    lVar5 = (longdouble)(*DAT_001c118c)(0xc1800000,0x41800000);
    lVar5 = (longdouble)(float)lVar4 + lVar5;
    fVar1 = *(float *)(gpGlobals + 0x2c);
    fVar2 = *(float *)(gpGlobals + 0x30);
    *param_4 = *param_4 + (float)(lVar5 * (longdouble)*(float *)(gpGlobals + 0x28));
    param_4[1] = param_4[1] + (float)(lVar5 * (longdouble)fVar1);
    param_4[2] = param_4[2] + (float)(lVar5 * (longdouble)fVar2);
    fStack_80 = *param_3 + (*param_4 - *param_3) * 0.5;
    fStack_7c = param_3[1] + (param_4[1] - param_3[1]) * 0.5;
    fStack_3c = param_3[2] + (param_4[2] - param_3[2]) * 0.5;
    fStack_78 = fStack_3c + 500.0;
    fStack_44 = fStack_80;
    fStack_40 = fStack_7c;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&fStack_44,&fStack_80,1,*(undefined4 *)(param_2 + 0x208),auStack_38);
    fStack_44 = fStack_24;
    fStack_40 = (float)uStack_20;
    fStack_48 = fStack_1c - 15.0;
    fVar1 = param_3[2];
    if (((byte)(fStack_48 < fVar1 |
                (byte)((ushort)((ushort)(NAN(fStack_48) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fStack_48 == fVar1) << 0xe) >> 8)) != 1) &&
       (param_4[2] <= fStack_48)) {
      fVar2 = (float)(lVar3 * (longdouble)param_5) * 0.5;
      fVar1 = SQRT((fStack_48 - param_3[2]) / fVar2);
      if ((byte)((0.1 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.1) << 0xe) >> 8)) - 1) < 0x40) {
        fStack_64 = SQRT((fStack_48 - param_4[2]) / fVar2) + fVar1;
        fStack_68 = (*param_4 - *param_3) / fStack_64;
        fStack_64 = (param_4[1] - param_3[1]) / fStack_64;
        fStack_60 = (float)(lVar3 * (longdouble)param_5) * fVar1;
        fStack_50 = *param_3 + fVar1 * fStack_68;
        fStack_4c = param_3[1] + fVar1 * fStack_64;
        fStack_3c = fStack_48;
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (param_3,&fStack_50,0,*(undefined4 *)(param_2 + 0x208),auStack_38);
        if (((byte)((byte)((ushort)((ushort)NAN(fStack_28) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fStack_28 == 1.0) << 0xe) >> 8)) == 0x40) &&
           (UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                      (param_4,&fStack_50,1,*(undefined4 *)(param_2 + 0x208),auStack_38),
           (byte)(1.0 < fStack_28 | (byte)((ushort)((ushort)NAN(fStack_28) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fStack_28 == 1.0) << 0xe) >> 8)) == 0x40)) {
          *param_1 = fStack_68;
          param_1[1] = fStack_64;
          goto LAB_000b323d;
        }
      }
    }
  }
  *param_1 = g_vecZero;
  param_1[1] = DAT_001c0fe4;
  fStack_60 = DAT_001c0fe8;
LAB_000b323d:
  param_1[2] = fStack_60;
  return param_1;
}


