// VecCheckToss__FP9entvars_sRC6VectorG6Vectorf  @ 000a7d78
float * VecCheckToss__FP9entvars_sRC6VectorG6Vectorf
                  (float *param_1,int param_2,float *param_3,float *param_4,float param_5)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  float local_80;
  float local_7c;
  float local_78;
  float local_68;
  float local_64;
  float local_60;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  undefined1 local_38 [16];
  float local_28;
  float local_24;
  undefined4 local_20;
  float local_1c;
  
  lVar3 = (longdouble)(*DAT_001a7f24)(FUN_00136430);
  if (param_4[2] - param_3[2] <= 500.0) {
    UTIL_MakeVectors__FRC6Vector(param_2 + 0x50);
    lVar4 = (longdouble)(*DAT_001a7fac)(0xc1000000,0x41000000);
    lVar5 = (longdouble)(*DAT_001a7fac)(0xc1800000,0x41800000);
    lVar5 = (longdouble)(float)lVar4 + lVar5;
    local_80 = *param_4 + (float)(lVar5 * (longdouble)*(float *)(gpGlobals + 0x40));
    local_7c = param_4[1] + (float)(lVar5 * (longdouble)*(float *)(gpGlobals + 0x44));
    local_78 = param_4[2] + (float)(lVar5 * (longdouble)*(float *)(gpGlobals + 0x48));
    *param_4 = local_80;
    param_4[1] = local_7c;
    param_4[2] = local_78;
    lVar4 = (longdouble)(*DAT_001a7fac)(0xc1000000,0x41000000);
    lVar5 = (longdouble)(*DAT_001a7fac)(0xc1800000,0x41800000);
    lVar5 = (longdouble)(float)lVar4 + lVar5;
    fVar1 = *(float *)(gpGlobals + 0x2c);
    fVar2 = *(float *)(gpGlobals + 0x30);
    *param_4 = *param_4 + (float)(lVar5 * (longdouble)*(float *)(gpGlobals + 0x28));
    param_4[1] = param_4[1] + (float)(lVar5 * (longdouble)fVar1);
    param_4[2] = param_4[2] + (float)(lVar5 * (longdouble)fVar2);
    local_80 = *param_3 + (*param_4 - *param_3) * 0.5;
    local_7c = param_3[1] + (param_4[1] - param_3[1]) * 0.5;
    local_3c = param_3[2] + (param_4[2] - param_3[2]) * 0.5;
    local_78 = local_3c + 500.0;
    local_44 = local_80;
    local_40 = local_7c;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_44,&local_80,1,*(undefined4 *)(param_2 + 0x208),local_38);
    local_44 = local_24;
    local_40 = (float)local_20;
    local_48 = local_1c - 15.0;
    fVar1 = param_3[2];
    if (((byte)(local_48 < fVar1 |
                (byte)((ushort)((ushort)(NAN(local_48) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_48 == fVar1) << 0xe) >> 8)) != 1) &&
       (param_4[2] <= local_48)) {
      fVar2 = (float)(lVar3 * (longdouble)param_5) * 0.5;
      fVar1 = SQRT((local_48 - param_3[2]) / fVar2);
      if ((byte)((0.1 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.1) << 0xe) >> 8)) - 1) < 0x40) {
        local_64 = SQRT((local_48 - param_4[2]) / fVar2) + fVar1;
        local_68 = (*param_4 - *param_3) / local_64;
        local_64 = (param_4[1] - param_3[1]) / local_64;
        local_60 = (float)(lVar3 * (longdouble)param_5) * fVar1;
        local_50 = *param_3 + fVar1 * local_68;
        local_4c = param_3[1] + fVar1 * local_64;
        local_3c = local_48;
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (param_3,&local_50,0,*(undefined4 *)(param_2 + 0x208),local_38);
        if (((byte)((byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
                   (byte)((ushort)((ushort)(local_28 == 1.0) << 0xe) >> 8)) == 0x40) &&
           (UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                      (param_4,&local_50,1,*(undefined4 *)(param_2 + 0x208),local_38),
           (byte)(1.0 < local_28 | (byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
                 (byte)((ushort)((ushort)(local_28 == 1.0) << 0xe) >> 8)) == 0x40)) {
          *param_1 = local_68;
          param_1[1] = local_64;
          goto LAB_000a82cd;
        }
      }
    }
  }
  *param_1 = g_vecZero;
  param_1[1] = DAT_001a7e04;
  local_60 = DAT_001a7e08;
LAB_000a82cd:
  param_1[2] = local_60;
  return param_1;
}


