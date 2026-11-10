// ActivateDoResults__FP11CBaseEntityP11CBasePlayerT0  @ 00111cc8
undefined4
ActivateDoResults__FP11CBaseEntityP11CBasePlayerT0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    if ((param_3 == param_1) || (*(int *)(param_1 + 0x27c) == 1)) {
      uVar3 = 1;
    }
    else if (param_3 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(uint *)(param_3 + 0x230) & 2;
    }
    DoResults__FP11CBaseEntityP11CBasePlayeri(param_1,param_2,uVar3);
    uVar2 = 1;
  }
  return uVar2;
}


