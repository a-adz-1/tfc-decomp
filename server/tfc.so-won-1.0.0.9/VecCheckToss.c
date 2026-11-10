// VecCheckToss__FP9entvars_tRC6VectorG6Vectorf  @ 000ba2b0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * VecCheckToss__FP9entvars_tRC6VectorG6Vectorf
                  (float *param_1,int param_2,float *param_3,float *param_4,float param_5)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  float local_84;
  float local_80;
  float local_7c;
  float local_6c;
  float local_68;
  float local_64;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [16];
  float local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  
  lVar3 = (longdouble)(*DAT_001755a4)("sv_gravity");
  if (param_4[2] - param_3[2] <= 500.0) {
    UTIL_MakeVectors__FRC6Vector(param_2 + 0x50);
    lVar4 = (longdouble)(*DAT_0017562c)(0xc1000000,0x41000000);
    lVar5 = (longdouble)(*DAT_0017562c)(0xc1800000,0x41800000);
    lVar5 = (longdouble)(float)lVar4 + lVar5;
    local_84 = *param_4 + (float)(lVar5 * (longdouble)*(float *)(gpGlobals + 0x40));
    local_80 = param_4[1] + (float)(lVar5 * (longdouble)*(float *)(gpGlobals + 0x44));
    local_7c = param_4[2] + (float)(lVar5 * (longdouble)*(float *)(gpGlobals + 0x48));
    *param_4 = local_84;
    param_4[1] = local_80;
    param_4[2] = local_7c;
    lVar4 = (longdouble)(*DAT_0017562c)(0xc1000000,0x41000000);
    lVar5 = (longdouble)(*DAT_0017562c)(0xc1800000,0x41800000);
    lVar5 = (longdouble)(float)lVar4 + lVar5;
    fVar1 = *(float *)(gpGlobals + 0x2c);
    fVar2 = *(float *)(gpGlobals + 0x30);
    *param_4 = *param_4 + (float)(lVar5 * (longdouble)*(float *)(gpGlobals + 0x28));
    param_4[1] = param_4[1] + (float)(lVar5 * (longdouble)fVar1);
    param_4[2] = param_4[2] + (float)(lVar5 * (longdouble)fVar2);
    local_48 = *param_3 + (*param_4 - *param_3) * _FUN_001328fc;
    local_44 = param_3[1] + (param_4[1] - param_3[1]) * _FUN_001328fc;
    local_40 = param_3[2] + _FUN_001328fc * (param_4[2] - param_3[2]);
    local_84 = local_48 + 0.0;
    local_80 = local_44 + 0.0;
    local_7c = local_40 + 500.0;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_48,&local_84,1,*(undefined4 *)(param_2 + 0x1e8),local_3c);
    local_48 = local_28;
    local_44 = (float)local_24;
    local_4c = local_20 - 15.0;
    fVar1 = param_3[2];
    if (((byte)(local_4c < fVar1 |
                (byte)((ushort)((ushort)(NAN(local_4c) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_4c == fVar1) << 0xe) >> 8)) != 1) &&
       (fVar1 = param_4[2],
       (byte)(local_4c < fVar1 | (byte)((ushort)((ushort)(NAN(local_4c) || NAN(fVar1)) << 10) >> 8)
             | (byte)((ushort)((ushort)(local_4c == fVar1) << 0xe) >> 8)) != 1)) {
      fVar2 = (float)(lVar3 * (longdouble)param_5) * 0.5;
      fVar1 = SQRT((local_4c - param_3[2]) / fVar2);
      if (0.1 <= fVar1) {
        local_68 = fVar1 + SQRT((local_4c - param_4[2]) / fVar2);
        local_6c = (*param_4 - *param_3) / local_68;
        local_68 = (param_4[1] - param_3[1]) / local_68;
        local_64 = (float)(lVar3 * (longdouble)param_5) * fVar1;
        local_54 = *param_3 + fVar1 * local_6c;
        local_50 = param_3[1] + fVar1 * local_68;
        local_40 = local_4c;
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (param_3,&local_54,0,*(undefined4 *)(param_2 + 0x1e8),local_3c);
        if (((byte)((byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                   (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40) &&
           (UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                      (param_4,&local_54,1,*(undefined4 *)(param_2 + 0x1e8),local_3c),
           (byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                 (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40)) {
          *param_1 = local_6c;
          param_1[1] = local_68;
          goto LAB_000ba74e;
        }
      }
    }
  }
  *param_1 = g_vecZero;
  param_1[1] = DAT_00175484;
  local_64 = DAT_00175488;
LAB_000ba74e:
  param_1[2] = local_64;
  return param_1;
}


