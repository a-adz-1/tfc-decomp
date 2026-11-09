// LookupActivityHeaviest__14CBaseAnimatingi  @ 000c54a0
void LookupActivityHeaviest__14CBaseAnimatingi(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_001755e8)(*(undefined4 *)(*param_1 + 0x1e8));
  LookupActivityHeaviest__FPvP9entvars_ti(uVar1,*param_1,param_2);
  return;
}


// LookupActivityHeaviest__FPvP9entvars_ti  @ 0009ab40
int LookupActivityHeaviest__FPvP9entvars_ti(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_8;
  
  if (param_1 == 0) {
    local_8 = 0;
  }
  else {
    iVar2 = param_1 + *(int *)(param_1 + 0xa8);
    iVar4 = 0;
    local_8 = -1;
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0xa4)) {
      do {
        iVar1 = iVar3 * 0xb0;
        if ((*(int *)(iVar2 + 0x28 + iVar1) == param_3) && (iVar4 < *(int *)(iVar2 + 0x2c + iVar1)))
        {
          iVar4 = *(int *)(iVar2 + 0x2c + iVar1);
          local_8 = iVar3;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0xa4));
    }
  }
  return local_8;
}


