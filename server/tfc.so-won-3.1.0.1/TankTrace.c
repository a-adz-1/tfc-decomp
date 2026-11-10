// TankTrace__9CFuncTankRC6VectorN21R11TraceResult  @ 000a1720
void TankTrace__9CFuncTankRC6VectorN21R11TraceResult
               (int *param_1,float *param_2,float *param_3,float *param_4,undefined4 param_5)

{
  float fVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  float fStack_30;
  float fStack_2c;
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
  
  do {
    lVar2 = (longdouble)(*DAT_001a7fac)(0xbf000000,0x3f000000);
    lVar3 = (longdouble)(*DAT_001a7fac)(0xbf000000,0x3f000000);
    lVar4 = (longdouble)(*DAT_001a7fac)(0xbf000000,0x3f000000);
    lVar5 = (longdouble)(*DAT_001a7fac)(0xbf000000,0x3f000000);
    lVar5 = (longdouble)(float)lVar4 + lVar5;
    lVar4 = (longdouble)(float)(lVar3 + (longdouble)(float)lVar2);
    lVar6 = lVar5 * lVar5 + lVar4 * lVar4;
    lVar4 = (longdouble)1.0;
  } while ((byte)(lVar4 < lVar6 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar6)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(lVar4 == lVar6) << 0xe) >> 8)) == 1);
  fVar1 = (float)(lVar3 + (longdouble)(float)lVar2) * *param_4;
  lVar5 = lVar5 * (longdouble)param_4[1];
  fStack_4 = param_3[2] + fVar1 * *(float *)(gpGlobals + 0x48) +
             (float)(lVar5 * (longdouble)*(float *)(gpGlobals + 0x3c));
  fStack_c = (float)((longdouble)(*param_3 + fVar1 * *(float *)(gpGlobals + 0x40)) +
                    lVar5 * (longdouble)*(float *)(gpGlobals + 0x34));
  fStack_8 = (float)((longdouble)(param_3[1] + fVar1 * *(float *)(gpGlobals + 0x44)) +
                    lVar5 * (longdouble)*(float *)(gpGlobals + 0x38));
  fStack_18 = fStack_c * 4096.0;
  fStack_14 = fStack_8 * 4096.0;
  fStack_10 = fStack_4 * 4096.0;
  fStack_30 = *param_2 + fStack_18;
  fStack_2c = param_2[1] + fStack_14;
  fStack_28 = param_2[2] + fStack_10;
  fStack_24 = fStack_30;
  fStack_20 = fStack_2c;
  fStack_1c = fStack_28;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (param_2,&fStack_30,0,*(undefined4 *)(*param_1 + 0x208),param_5);
  return;
}


