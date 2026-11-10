// VecCheckThrow__FP9entvars_sRC6VectorG6Vectorff  @ 000b26c4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * VecCheckThrow__FP9entvars_sRC6VectorG6Vectorff
                  (float *param_1,int param_2,float *param_3,float *param_4,float param_5,
                  float param_6)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  undefined1 local_74 [16];
  float local_64;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_10;
  float local_c;
  float local_8;
  
  lVar1 = (longdouble)(*DAT_0019f784)("sv_gravity");
  local_3c = *param_4 - *param_3;
  lVar2 = (longdouble)param_4[1] - (longdouble)param_3[1];
  lVar3 = (longdouble)param_4[2] - (longdouble)param_3[2];
  lVar4 = (longdouble)
          (float)SQRT(lVar3 * lVar3 + lVar2 * lVar2 + (longdouble)local_3c * (longdouble)local_3c) /
          (longdouble)param_5;
  lVar5 = (longdouble)(1.0 / (float)lVar4);
  local_10 = (float)((longdouble)local_3c * lVar5);
  local_c = (float)(lVar2 * lVar5);
  local_24 = (float)((longdouble)0.5 * (longdouble)(float)(lVar1 * (longdouble)param_6) * lVar4 +
                    (longdouble)(float)(lVar3 * lVar5));
  lVar5 = (longdouble)_FUN_0014c2e0;
  local_38 = (float)lVar2;
  local_2c = (float)(lVar2 * lVar5);
  local_34 = (float)lVar3;
  local_30 = (float)((longdouble)local_3c * lVar5);
  local_28 = (float)(lVar3 * lVar5);
  local_20 = (float)((longdouble)*param_3 + (longdouble)local_3c * lVar5);
  local_1c = (float)(lVar2 * lVar5 + (longdouble)param_3[1]);
  local_18 = (float)((longdouble)(double)lVar4 * (longdouble)0.25 *
                     (longdouble)(float)(lVar1 * (longdouble)param_6) * (longdouble)0.5 *
                     (longdouble)(double)lVar4 + (longdouble)param_3[2] + lVar3 * lVar5);
  local_8 = local_24;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (param_3,&local_20,0,*(undefined4 *)(param_2 + 0x208),local_74);
  if ((byte)((byte)((ushort)((ushort)NAN(local_64) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_64 == 1.0) << 0xe) >> 8)) == 0x40) {
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (param_4,&local_20,1,*(undefined4 *)(param_2 + 0x208),local_74);
    if ((byte)(1.0 < local_64 | (byte)((ushort)((ushort)NAN(local_64) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_64 == 1.0) << 0xe) >> 8)) == 0x40) {
      *param_1 = local_10;
      param_1[1] = local_c;
      goto LAB_000b28d2;
    }
  }
  *param_1 = g_vecZero;
  param_1[1] = DAT_0019f664;
  local_8 = DAT_0019f668;
LAB_000b28d2:
  param_1[2] = local_8;
  return param_1;
}


