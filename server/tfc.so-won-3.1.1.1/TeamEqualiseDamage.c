// TeamEqualiseDamage__FP11CBaseEntityT0f  @ 00113c98
longdouble
TeamEqualiseDamage__FP11CBaseEntityT0f(undefined4 *param_1,undefined4 *param_2,float param_3)

{
  int iVar1;
  float *pfVar2;
  longdouble lVar3;
  longdouble lVar4;
  
  iVar1 = strcmp((char *)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98)),"player");
  if ((((iVar1 == 0) &&
       (iVar1 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"player"), iVar1 == 0
       )) && (param_1[0x48] != 0)) &&
     ((param_2[0x48] != 0 &&
      (iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(param_2,param_1), iVar1 == 0)))) {
    lVar3 = (longdouble)(float)(&teamadvantage)[param_2[0x48]];
    if ((byte)((byte)((ushort)((ushort)(NAN(lVar3) || NAN((longdouble)0.0)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar3 == (longdouble)0.0) << 0xe) >> 8)) == 0x40) {
      (*DAT_0019f794)(1,"There is a team with an advantage of 0\n");
      lVar3 = (longdouble)0.1;
    }
    lVar4 = (longdouble)(float)(&teamadvantage)[param_1[0x48]];
    if ((byte)((byte)((ushort)((ushort)(NAN(lVar4) || NAN((longdouble)0.0)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar4 == (longdouble)0.0) << 0xe) >> 8)) == 0x40) {
      (*DAT_0019f794)(1,"There is a team with an advantage of 0\n");
      lVar4 = (longdouble)0.1;
    }
    lVar3 = ((longdouble)1 / lVar4) * (longdouble)param_3 * lVar3;
    if ((longdouble)param_3 <= lVar3) {
      lVar4 = lVar3 - (longdouble)param_3;
      pfVar2 = (float *)&gfPrototypeExtraDamage;
    }
    else {
      lVar4 = (longdouble)param_3 - lVar3;
      pfVar2 = (float *)&gfPrototypeLessDamage;
    }
    *pfVar2 = (float)(lVar4 + (longdouble)*pfVar2);
    return lVar3;
  }
  return (longdouble)param_3;
}


