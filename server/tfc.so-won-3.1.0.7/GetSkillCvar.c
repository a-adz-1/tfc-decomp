// GetSkillCvar__FPc  @ 000ed3f4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longdouble GetSkillCvar__FPc(undefined4 param_1)

{
  float fVar1;
  longdouble lVar2;
  char local_40 [64];
  
  sprintf(local_40,"%s%d",param_1,gSkillData);
  lVar2 = (longdouble)(*DAT_001c1104)(local_40);
  fVar1 = (float)lVar2;
  if ((byte)(_FUN_0014d2ec < fVar1 |
             (byte)((ushort)((ushort)(NAN(_FUN_0014d2ec) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(_FUN_0014d2ec == fVar1) << 0xe) >> 8)) != 1) {
    (*DAT_001c1114)(1,"\n\n** GetSkillCVar Got a zero for %s **\n\n",local_40);
  }
  return (longdouble)fVar1;
}


