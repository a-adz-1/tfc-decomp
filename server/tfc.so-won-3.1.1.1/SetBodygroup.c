// SetBodygroup__14CBaseAnimatingii  @ 000c1be4
void SetBodygroup__14CBaseAnimatingii(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_0019f7c8)(*(undefined4 *)(*param_1 + 0x208),*param_1,param_2,param_3);
  SetBodygroup__FPvP9entvars_sii(uVar1);
  return;
}


// SetBodygroup__FPvP9entvars_sii  @ 00087970
void SetBodygroup__FPvP9entvars_sii(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != 0) && (param_3 <= *(int *)(param_1 + 0xcc))) {
    iVar1 = param_1 + *(int *)(param_1 + 0xd0) + param_3 * 0x4c;
    iVar2 = *(int *)(iVar1 + 0x40);
    if (param_4 < iVar2) {
      iVar1 = *(int *)(iVar1 + 0x44);
      *(int *)(param_2 + 0x114) =
           (*(int *)(param_2 + 0x114) - ((*(int *)(param_2 + 0x114) / iVar1) % iVar2) * iVar1) +
           param_4 * iVar1;
    }
  }
  return;
}


