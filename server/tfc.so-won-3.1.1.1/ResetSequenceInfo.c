// ResetSequenceInfo__14CBaseAnimating  @ 000c1e74
void ResetSequenceInfo__14CBaseAnimating(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = (*DAT_0019f7c8)(*(undefined4 *)(*param_1 + 0x208));
  GetSequenceInfo__FPvP9entvars_sPfT2(uVar1,*param_1,param_1 + 0x118,param_1 + 0x119);
  uVar2 = GetSequenceFlags__14CBaseAnimating(param_1);
  param_1[0x11c] = uVar2 & 1;
  *(int *)(*param_1 + 0x134) = *gpGlobals;
  *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
  param_1[0x11b] = 0;
  param_1[0x11a] = *gpGlobals;
  return;
}


