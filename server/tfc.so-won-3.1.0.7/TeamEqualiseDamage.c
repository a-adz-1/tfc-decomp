// TeamEqualiseDamage__FP11CBaseEntityT0f  @ 001108e4
longdouble
TeamEqualiseDamage__FP11CBaseEntityT0f(undefined4 *param_1,undefined4 *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = strcmp((char *)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98)),"player");
  if ((((iVar3 == 0) &&
       (iVar3 = strcmp((char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)),"player"), iVar3 == 0
       )) && (param_1[0x48] != 0)) &&
     ((param_2[0x48] != 0 &&
      (iVar3 = IsAlly__11CBaseEntityP11CBaseEntity(param_2,param_1), iVar3 == 0)))) {
    fVar1 = *(float *)(teamadvantage + param_2[0x48] * 4);
    if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      (*DAT_001c1114)(1,"There is a team with an advantage of 0\n");
      fVar1 = 0.1;
    }
    fVar2 = *(float *)(teamadvantage + param_1[0x48] * 4);
    if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
      (*DAT_001c1114)(1,"There is a team with an advantage of 0\n");
      fVar2 = 0.1;
    }
    fVar1 = (1.0 / fVar2) * fVar1 * param_3;
    if ((byte)((param_3 < fVar1 | (byte)((ushort)((ushort)(NAN(param_3) || NAN(fVar1)) << 10) >> 8)
               | (byte)((ushort)((ushort)(param_3 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
      gfPrototypeExtraDamage = (fVar1 - param_3) + gfPrototypeExtraDamage;
      param_3 = fVar1;
    }
    else {
      gfPrototypeLessDamage = (param_3 - fVar1) + gfPrototypeLessDamage;
      param_3 = fVar1;
    }
  }
  return (longdouble)param_3;
}


