// PlatUse__9CFuncPlatP11CBaseEntityT18USE_TYPEf  @ 000c29c4
void PlatUse__9CFuncPlatP11CBaseEntityT18USE_TYPEf
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x3d4) + 0x104))(param_1);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    if (*(int *)(param_1 + 0x3f4) != 0) {
      return;
    }
  }
  else {
    iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,*(int *)(param_1 + 0x3f4) == 1);
    if (iVar1 == 0) {
      return;
    }
    if (*(int *)(param_1 + 0x3f4) != 0) {
      if (*(int *)(param_1 + 0x3f4) != 1) {
        return;
      }
      FUN_000c2a54();
      return;
    }
  }
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x10c))(param_1);
  return;
}


