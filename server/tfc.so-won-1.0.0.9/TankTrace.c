// TankTrace__9CFuncTankRC6VectorN21R11TraceResult  @ 000b5730
void TankTrace__9CFuncTankRC6VectorN21R11TraceResult
               (int *param_1,float *param_2,float *param_3,float *param_4,undefined4 param_5)

{
  float fVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
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
  
  do {
    lVar2 = (longdouble)(*DAT_0017562c)(0xbf000000,0x3f000000);
    lVar3 = (longdouble)(*DAT_0017562c)(0xbf000000,0x3f000000);
    lVar4 = (longdouble)(*DAT_0017562c)(0xbf000000,0x3f000000);
    lVar5 = (longdouble)(*DAT_0017562c)(0xbf000000,0x3f000000);
    lVar5 = (longdouble)(float)lVar4 + lVar5;
    lVar4 = (longdouble)(float)(lVar3 + (longdouble)(float)lVar2);
    lVar6 = lVar5 * lVar5 + lVar4 * lVar4;
    lVar4 = (longdouble)1;
  } while ((byte)(lVar4 < lVar6 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar6)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(lVar4 == lVar6) << 0xe) >> 8)) == 1);
  fVar1 = (float)(lVar3 + (longdouble)(float)lVar2) * *param_4;
  lVar5 = lVar5 * (longdouble)param_4[1];
  local_8 = param_3[2] + fVar1 * *(float *)(gpGlobals + 0x48) +
            (float)(lVar5 * (longdouble)*(float *)(gpGlobals + 0x3c));
  local_10 = (float)((longdouble)(*param_3 + fVar1 * *(float *)(gpGlobals + 0x40)) +
                    lVar5 * (longdouble)*(float *)(gpGlobals + 0x34));
  local_c = (float)((longdouble)(param_3[1] + fVar1 * *(float *)(gpGlobals + 0x44)) +
                   lVar5 * (longdouble)*(float *)(gpGlobals + 0x38));
  local_1c = local_10 * 4096.0;
  local_18 = local_c * 4096.0;
  local_14 = local_8 * 4096.0;
  local_34 = *param_2 + local_1c;
  local_30 = param_2[1] + local_18;
  local_2c = param_2[2] + local_14;
  local_28 = local_34;
  local_24 = local_30;
  local_20 = local_2c;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (param_2,&local_34,0,*(undefined4 *)(*param_1 + 0x1e8),param_5);
  return;
}


