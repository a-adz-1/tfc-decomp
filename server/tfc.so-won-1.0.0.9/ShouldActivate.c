// ShouldActivate__FP11CBaseEntityT0  @ 0010adb0
undefined4 ShouldActivate__FP11CBaseEntityT0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (((param_1[0x86] == 1) || (param_1[0x86] == 3)) || (param_1[0x86] == 4)) {
    uVar1 = 0;
  }
  else {
    iVar2 = APMeetsCriteria__FP11CBaseEntityT0(param_1,param_2);
    iVar3 = strcmp((char *)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98)),"item_tfgoal");
    if (iVar3 == 0) {
      uVar4 = param_1[0x88] & 0x40;
    }
    else {
      uVar4 = param_1[0x88] & 4;
    }
    if (iVar2 == 0) {
      if (uVar4 == 0) {
        return 0;
      }
    }
    else if (uVar4 != 0) {
      return 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}


