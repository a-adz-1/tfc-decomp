// GetBodygroup__14CBaseAnimatingi  @ 000c1ba4
void GetBodygroup__14CBaseAnimatingi(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_0019f7c8)(*(undefined4 *)(*param_1 + 0x208),*param_1,param_2);
  GetBodygroup__FPvP9entvars_si(uVar1);
  return;
}


// GetBodygroup__FPvP9entvars_si  @ 00087920
int GetBodygroup__FPvP9entvars_si(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != 0) && (param_3 <= *(int *)(param_1 + 0xcc))) {
    iVar1 = param_1 + *(int *)(param_1 + 0xd0) + param_3 * 0x4c;
    iVar2 = *(int *)(iVar1 + 0x40);
    if (1 < iVar2) {
      return (*(int *)(param_2 + 0x114) / *(int *)(iVar1 + 0x44)) % iVar2;
    }
  }
  return 0;
}


