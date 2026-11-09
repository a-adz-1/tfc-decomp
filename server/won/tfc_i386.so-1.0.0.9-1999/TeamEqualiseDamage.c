// TeamEqualiseDamage__FP11CBaseEntityT0f  @ 0010efb0
longdouble
TeamEqualiseDamage__FP11CBaseEntityT0f(undefined4 *param_1,undefined4 *param_2,float param_3)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  
  iVar2 = strcmp((char *)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98)),"player");
  if ((((iVar2 == 0) &&
       (iVar2 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"player"), iVar2 == 0
       )) && (param_1[0x48] != 0)) &&
     ((param_2[0x48] != 0 &&
      (iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(param_2,param_1), iVar2 == 0)))) {
    fVar1 = (float)(&teamadvantage)[param_2[0x48]];
    if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      (*DAT_001755b4)(1,"There is a team with an advantage of 0\n");
      fVar1 = 0.1;
    }
    lVar3 = (longdouble)(float)(&teamadvantage)[param_1[0x48]];
    if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar3)) << 10) >> 8) |
              (byte)((ushort)((ushort)((longdouble)0 == lVar3) << 0xe) >> 8)) == 0x40) {
      (*DAT_001755b4)(1,"There is a team with an advantage of 0\n");
      lVar3 = (longdouble)0.1;
    }
    return ((longdouble)1 / lVar3) * (longdouble)(fVar1 * param_3);
  }
  return (longdouble)param_3;
}


