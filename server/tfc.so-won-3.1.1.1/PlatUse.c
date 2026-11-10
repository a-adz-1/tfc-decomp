// PlatUse__9CFuncPlatP11CBaseEntityT18USE_TYPEf  @ 000d2c70
void PlatUse__9CFuncPlatP11CBaseEntityT18USE_TYPEf
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x454) + 0x10c))(param_1);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    if (*(int *)(param_1 + 0x474) != 0) {
      return;
    }
  }
  else {
    iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,*(int *)(param_1 + 0x474) == 1);
    if (iVar1 == 0) {
      return;
    }
    if (*(int *)(param_1 + 0x474) != 0) {
      if (*(int *)(param_1 + 0x474) != 1) {
        return;
      }
      pcVar2 = *(code **)(*(int *)(param_1 + 0x454) + 0x110);
      goto LAB_000d2d00;
    }
  }
  pcVar2 = *(code **)(*(int *)(param_1 + 0x454) + 0x114);
LAB_000d2d00:
  (*pcVar2)(param_1);
  return;
}


