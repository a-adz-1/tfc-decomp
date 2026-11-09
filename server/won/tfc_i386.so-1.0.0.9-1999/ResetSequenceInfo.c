// ResetSequenceInfo__14CBaseAnimating  @ 000c55d0
void ResetSequenceInfo__14CBaseAnimating(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = (*DAT_001755e8)(*(undefined4 *)(*param_1 + 0x1e8));
  GetSequenceInfo__FPvP9entvars_tPfT2(uVar2,*param_1,param_1 + 0xf5,param_1 + 0xf6);
  uVar3 = GetSequenceFlags__14CBaseAnimating(param_1);
  param_1[0xf9] = uVar3 & 1;
  piVar1 = gpGlobals;
  *(int *)(*param_1 + 0x114) = *gpGlobals;
  *(undefined4 *)(*param_1 + 0x118) = 0x3f800000;
  param_1[0xf8] = 0;
  param_1[0xf7] = *piVar1;
  return;
}


