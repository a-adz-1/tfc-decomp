// GetSkillCvar__FPc  @ 000e09c8
longdouble GetSkillCvar__FPc(undefined4 param_1)

{
  float fVar1;
  longdouble lVar2;
  char local_40 [64];
  
  sprintf(local_40,"%s%d",param_1,gSkillData);
  lVar2 = (longdouble)(*DAT_001a7f24)(local_40);
  fVar1 = (float)lVar2;
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    (*DAT_001a7f34)(1,"\n\n** GetSkillCVar Got a zero for %s **\n\n",local_40);
  }
  return (longdouble)fVar1;
}


