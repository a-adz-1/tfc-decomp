// LookupActivity__14CBaseAnimatingi  @ 000c5470
void LookupActivity__14CBaseAnimatingi(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_001755e8)(*(undefined4 *)(*param_1 + 0x1e8));
  LookupActivity__FPvP9entvars_ti(uVar1,*param_1,param_2);
  return;
}


// LookupActivity__FPvP9entvars_ti  @ 0009aaa0
int LookupActivity__FPvP9entvars_ti(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_10;
  
  if (param_1 == 0) {
    local_10 = 0;
  }
  else {
    iVar2 = param_1 + *(int *)(param_1 + 0xa8);
    iVar5 = 0;
    local_10 = -1;
    for (iVar3 = 0; iVar3 < *(int *)(param_1 + 0xa4); iVar3 = iVar3 + 1) {
      iVar4 = iVar3 * 0xb0;
      if ((*(int *)(iVar2 + 0x28 + iVar4) == param_3) &&
         ((iVar5 = iVar5 + *(int *)(iVar2 + 0x2c + iVar4), iVar5 == 0 ||
          (iVar1 = (*DAT_00175628)(0,iVar5 + -1), iVar1 < *(int *)(iVar2 + 0x2c + iVar4))))) {
        local_10 = iVar3;
      }
    }
  }
  return local_10;
}


