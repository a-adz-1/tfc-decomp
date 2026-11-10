// ResetSequenceInfo__14CBaseAnimating  @ 000beed8
void ResetSequenceInfo__14CBaseAnimating(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = (*DAT_001c1148)(*(undefined4 *)(*param_1 + 0x208));
  GetSequenceInfo__FPvP9entvars_sPfT2(uVar1,*param_1,param_1 + 0x114,param_1 + 0x115);
  uVar2 = GetSequenceFlags__14CBaseAnimating(param_1);
  param_1[0x118] = uVar2 & 1;
  *(int *)(*param_1 + 0x134) = *gpGlobals;
  *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
  param_1[0x117] = 0;
  param_1[0x116] = *gpGlobals;
  return;
}


