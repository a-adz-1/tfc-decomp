// VecCheckThrow__FP9entvars_tRC6VectorG6Vectorff  @ 000ba770
float * VecCheckThrow__FP9entvars_tRC6VectorG6Vectorff
                  (float *param_1,int param_2,float *param_3,float *param_4,float param_5,
                  float param_6)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  undefined1 auStack_74 [16];
  float fStack_64;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  lVar3 = (longdouble)(*DAT_001755a4)("sv_gravity");
  local_10 = *param_4 - *param_3;
  local_c = param_4[1] - param_3[1];
  fVar1 = param_4[2] - param_3[2];
  local_14 = SQRT(fVar1 * fVar1 + local_c * local_c + local_10 * local_10);
  param_5 = local_14 / param_5;
  fVar2 = 1.0 / param_5;
  local_10 = fVar2 * local_10;
  local_c = fVar2 * local_c;
  local_24 = param_5 * (float)(lVar3 * (longdouble)param_6) * 0.5 + fVar2 * fVar1;
  fStack_3c = *param_4 - *param_3;
  fStack_38 = param_4[1] - param_3[1];
  fStack_34 = param_4[2] - param_3[2];
  fStack_30 = fStack_3c * 0.5;
  fStack_2c = fStack_38 * 0.5;
  fStack_28 = fStack_34 * 0.5;
  local_20 = *param_3 + fStack_30;
  local_1c = param_3[1] + fStack_2c;
  local_18 = (float)(lVar3 * (longdouble)param_6) * 0.5 * param_5 * 0.5 * param_5 * 0.5 +
             param_3[2] + fStack_28;
  local_8 = local_24;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (param_3,&local_20,0,*(undefined4 *)(param_2 + 0x1e8),auStack_74);
  if ((byte)((byte)((ushort)((ushort)NAN(fStack_64) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_64 == 1.0) << 0xe) >> 8)) == 0x40) {
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (param_4,&local_20,1,*(undefined4 *)(param_2 + 0x1e8),auStack_74);
    if ((byte)(1.0 < fStack_64 | (byte)((ushort)((ushort)NAN(fStack_64) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_64 == 1.0) << 0xe) >> 8)) == 0x40) {
      *param_1 = local_10;
      param_1[1] = local_c;
      goto LAB_000ba92e;
    }
  }
  *param_1 = g_vecZero;
  param_1[1] = DAT_00175484;
  local_8 = DAT_00175488;
LAB_000ba92e:
  param_1[2] = local_8;
  return param_1;
}


