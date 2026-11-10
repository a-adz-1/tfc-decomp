// GetSkillCvar__FPc  @ 000ef174
longdouble GetSkillCvar__FPc(undefined4 param_1)

{
  float fVar1;
  longdouble lVar2;
  char local_44 [64];
  
  sprintf(local_44,"%s%d",param_1,gSkillData);
  lVar2 = (longdouble)(*DAT_0019f784)(local_44);
  fVar1 = (float)lVar2;
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    (*DAT_0019f794)(1,"\n\n** GetSkillCVar Got a zero for %s **\n\n",local_44);
  }
  return (longdouble)fVar1;
}


