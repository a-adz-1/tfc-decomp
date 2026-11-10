// TankTrace__9CFuncTankRC6VectorN21R11TraceResult  @ 000ab4dc
void TankTrace__9CFuncTankRC6VectorN21R11TraceResult
               (int *param_1,float *param_2,float *param_3,float *param_4,undefined4 param_5)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  float fStack_34;
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
  
  do {
    lVar1 = (longdouble)(*DAT_0019f80c)(0xbf000000,0x3f000000);
    lVar2 = (longdouble)(*DAT_0019f80c)(0xbf000000,0x3f000000);
    lVar3 = (longdouble)(*DAT_0019f80c)(0xbf000000,0x3f000000);
    lVar4 = (longdouble)(*DAT_0019f80c)(0xbf000000,0x3f000000);
    lVar4 = (longdouble)(float)lVar3 + lVar4;
    lVar3 = (longdouble)(float)(lVar2 + (longdouble)(float)lVar1);
    lVar5 = lVar4 * lVar4 + lVar3 * lVar3;
    lVar3 = (longdouble)1;
  } while ((byte)(lVar3 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar5)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(lVar3 == lVar5) << 0xe) >> 8)) == 1);
  lVar3 = (longdouble)(float)(lVar2 + (longdouble)(float)lVar1) * (longdouble)*param_4;
  lVar4 = lVar4 * (longdouble)param_4[1];
  lVar1 = (longdouble)*(float *)(gpGlobals + 0x40) * lVar3 + (longdouble)*param_3 +
          (longdouble)*(float *)(gpGlobals + 0x34) * lVar4;
  lVar2 = (longdouble)*(float *)(gpGlobals + 0x44) * lVar3 + (longdouble)param_3[1] +
          (longdouble)*(float *)(gpGlobals + 0x38) * lVar4;
  lVar4 = lVar3 * (longdouble)*(float *)(gpGlobals + 0x48) + (longdouble)param_3[2] +
          lVar4 * (longdouble)*(float *)(gpGlobals + 0x3c);
  lVar3 = (longdouble)4096.0;
  fStack_10 = (float)lVar1;
  lVar1 = lVar1 * lVar3;
  fStack_c = (float)lVar2;
  lVar2 = lVar2 * lVar3;
  fStack_8 = (float)lVar4;
  lVar4 = lVar4 * lVar3;
  fStack_1c = (float)lVar1;
  fStack_18 = (float)lVar2;
  fStack_14 = (float)lVar4;
  fStack_34 = (float)(lVar1 + (longdouble)*param_2);
  fStack_30 = (float)(lVar2 + (longdouble)param_2[1]);
  fStack_2c = (float)(lVar4 + (longdouble)param_2[2]);
  fStack_28 = fStack_34;
  fStack_24 = fStack_30;
  fStack_20 = fStack_2c;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (param_2,&fStack_34,0,*(undefined4 *)(*param_1 + 0x208),param_5);
  return;
}


