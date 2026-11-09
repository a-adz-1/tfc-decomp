// ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0  @ 0010ae60
undefined4 ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (cb_prematch_time <= *gpGlobals) {
    iVar1 = ShouldActivate__FP11CBaseEntityT0(param_1,param_2);
    if (iVar1 != 0) {
      return 1;
    }
    if ((*(int *)(param_1 + 0x230) != 0) &&
       (iVar1 = Findgoal__Fi(*(undefined4 *)(param_1 + 0x230)), iVar1 != 0)) {
      ActivateDoResults__FP11CBaseEntityP11CBasePlayerT0(iVar1,param_2,param_1);
    }
  }
  return 0;
}


