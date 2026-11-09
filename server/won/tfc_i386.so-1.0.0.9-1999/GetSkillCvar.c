// GetSkillCvar__FPc  @ 000eaf80
longdouble GetSkillCvar__FPc(undefined4 param_1)

{
  longdouble lVar1;
  char local_44 [64];
  
  sprintf(local_44,"%s%d",param_1,gSkillData);
  lVar1 = (longdouble)(*DAT_001755a4)(local_44);
  if ((float)lVar1 <= 0.0) {
    (*DAT_001755b4)(1,"\n\n** GetSkillCVar Got a zero for %s **\n\n",local_44);
  }
  return (longdouble)(float)lVar1;
}


