// SetBodygroup__14CBaseAnimatingii  @ 000bf5d0
void SetBodygroup__14CBaseAnimatingii(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_001c1148)(*(undefined4 *)(*param_1 + 0x208),*param_1,param_2,param_3);
  SetBodygroup__FPvP9entvars_sii(uVar1);
  return;
}


// SetBodygroup__FPvP9entvars_sii  @ 000882e8
void SetBodygroup__FPvP9entvars_sii(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_3 <= *(int *)(param_1 + 0xcc))) {
    iVar1 = param_1 + *(int *)(param_1 + 0xd0) + param_3 * 0x4c;
    if (param_4 < *(int *)(iVar1 + 0x40)) {
      *(int *)(param_2 + 0x114) =
           (*(int *)(param_2 + 0x114) -
           ((*(int *)(param_2 + 0x114) / *(int *)(iVar1 + 0x44)) % *(int *)(iVar1 + 0x40)) *
           *(int *)(iVar1 + 0x44)) + param_4 * *(int *)(iVar1 + 0x44);
    }
  }
  return;
}


