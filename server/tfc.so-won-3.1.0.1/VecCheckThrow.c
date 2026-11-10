// VecCheckThrow__FP9entvars_sRC6VectorG6Vectorff  @ 000a82e0
float * VecCheckThrow__FP9entvars_sRC6VectorG6Vectorff
                  (float *param_1,int param_2,float *param_3,float *param_4,float param_5,
                  float param_6)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  undefined1 local_70 [16];
  float local_60;
  float local_38;
  float local_34;
  float local_30;
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
  float local_4;
  
  lVar3 = (longdouble)(*DAT_001a7f24)(FUN_00136430);
  local_c = *param_4 - *param_3;
  local_8 = param_4[1] - param_3[1];
  fVar1 = param_4[2] - param_3[2];
  local_10 = SQRT(fVar1 * fVar1 + local_8 * local_8 + local_c * local_c);
  param_5 = local_10 / param_5;
  fVar2 = 1.0 / param_5;
  local_c = fVar2 * local_c;
  local_8 = fVar2 * local_8;
  local_20 = param_5 * (float)(lVar3 * (longdouble)param_6) * 0.5 + fVar2 * fVar1;
  local_38 = *param_4 - *param_3;
  local_34 = param_4[1] - param_3[1];
  local_30 = param_4[2] - param_3[2];
  local_2c = local_38 * 0.5;
  local_28 = local_34 * 0.5;
  local_24 = local_30 * 0.5;
  local_1c = *param_3 + local_2c;
  local_18 = param_3[1] + local_28;
  local_14 = param_3[2] + local_24 +
             param_5 * 0.25 * (float)(lVar3 * (longdouble)param_6) * 0.5 * param_5;
  local_4 = local_20;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (param_3,&local_1c,0,*(undefined4 *)(param_2 + 0x208),local_70);
  if ((byte)((byte)((ushort)((ushort)NAN(local_60) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_60 == 1.0) << 0xe) >> 8)) == 0x40) {
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (param_4,&local_1c,1,*(undefined4 *)(param_2 + 0x208),local_70);
    if ((byte)(1.0 < local_60 | (byte)((ushort)((ushort)NAN(local_60) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_60 == 1.0) << 0xe) >> 8)) == 0x40) {
      *param_1 = local_c;
      param_1[1] = local_8;
      goto LAB_000a8572;
    }
  }
  *param_1 = g_vecZero;
  param_1[1] = DAT_001a7e04;
  local_4 = DAT_001a7e08;
LAB_000a8572:
  param_1[2] = local_4;
  return param_1;
}


