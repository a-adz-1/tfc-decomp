// LookupActivityHeaviest__14CBaseAnimatingi  @ 000c2028
void LookupActivityHeaviest__14CBaseAnimatingi(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_0019f7c8)(*(undefined4 *)(*param_1 + 0x208));
  LookupActivityHeaviest__FPvP9entvars_si(uVar1,*param_1,param_2);
  return;
}


// LookupActivityHeaviest__FPvP9entvars_si  @ 00087bb0
int LookupActivityHeaviest__FPvP9entvars_si(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_c;
  
  if (param_1 == 0) {
    local_c = 0;
  }
  else {
    iVar4 = 0;
    local_c = -1;
    iVar3 = 0;
    iVar2 = param_1 + *(int *)(param_1 + 0xa8);
    if (0 < *(int *)(param_1 + 0xa4)) {
      do {
        if ((*(int *)(iVar2 + 0x28 + iVar3 * 0xb0) == param_3) &&
           (iVar1 = *(int *)(iVar2 + 0x2c + iVar3 * 0xb0), iVar4 < iVar1)) {
          iVar4 = iVar1;
          local_c = iVar3;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0xa4));
    }
  }
  return local_c;
}


