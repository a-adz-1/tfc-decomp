// ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0  @ 0010d188
undefined4
ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(undefined4 *param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  if ((cb_prematch_time <= *gpGlobals) ||
     (iVar2 = (**(code **)(param_1[0x115] + 0x2c))(param_1), iVar2 == 0x81)) {
    iVar2 = param_1[0x86];
    if ((iVar2 != 1) && ((iVar2 != 3 && (iVar2 != 4)))) {
      iVar2 = APMeetsCriteria__FP11CBaseEntityT0(param_1,param_2);
      bVar1 = false;
      iVar3 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"item_tfgoal");
      if (iVar3 == 0) {
        uVar5 = param_1[0x8a] & 0x40;
      }
      else {
        uVar5 = param_1[0x8a] & 4;
      }
      if (iVar2 == 0) {
        if (uVar5 != 0) {
          bVar1 = true;
        }
      }
      else if (uVar5 == 0) {
        uVar4 = FUN_0010d2f8();
        return uVar4;
      }
      if (bVar1) {
        return 1;
      }
    }
    if (param_1[0x8e] != 0) {
      uVar4 = FUN_0010d2b0("info_tfgoal");
      return uVar4;
    }
  }
  return 0;
}


