// GetBodygroup__14CBaseAnimatingi  @ 000c5cd0
void GetBodygroup__14CBaseAnimatingi(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_001755e8)(*(undefined4 *)(*param_1 + 0x1e8),*param_1,param_2);
  GetBodygroup__FPvP9entvars_ti(uVar1);
  return;
}


// GetBodygroup__FPvP9entvars_ti  @ 0009b580
int GetBodygroup__FPvP9entvars_ti(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (((param_1 == 0) || (*(int *)(param_1 + 0xcc) < param_3)) ||
     (iVar1 = param_1 + *(int *)(param_1 + 0xd0) + param_3 * 0x4c, *(int *)(iVar1 + 0x40) < 2)) {
    iVar1 = 0;
  }
  else {
    iVar1 = (*(int *)(param_2 + 0xf4) / *(int *)(iVar1 + 0x44)) % *(int *)(iVar1 + 0x40);
  }
  return iVar1;
}


