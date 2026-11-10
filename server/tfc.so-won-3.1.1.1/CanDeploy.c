// CanDeploy__15CBasePlayerItem  @ 001266ac
undefined4 CanDeploy__15CBasePlayerItem(void)

{
  return 1;
}


// CanDeploy__17CBasePlayerWeapon  @ 0012573c
undefined4 CanDeploy__17CBasePlayerWeapon(int param_1)

{
  uint uVar1;
  undefined1 local_30 [8];
  int local_28;
  int local_24;
  int iStack_20;
  
  uVar1 = 0;
  (**(code **)(*(int *)(param_1 + 0x454) + 0x118))(param_1,local_30);
  if ((local_28 != 0) && (local_24 != -1)) {
    if (*(uint **)(param_1 + 0xb0) == (uint *)0x0) {
      if (*(int *)(*(int *)(param_1 + 0x4b8) * 4 + *(int *)(param_1 + 0x474) + 0x8ec) != 0) {
        uVar1 = 1;
      }
    }
    else {
      uVar1 = **(uint **)(param_1 + 0xb0);
    }
    if ((iStack_20 != 0) &&
       (*(int *)(*(int *)(param_1 + 0x4bc) * 4 + *(int *)(param_1 + 0x474) + 0x8ec) != 0)) {
      uVar1 = uVar1 | 1;
    }
    if (0 < *(int *)(param_1 + 0x4c0)) {
      uVar1 = uVar1 | 1;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


