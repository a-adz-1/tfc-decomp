// CanDeploy__15CBasePlayerItem  @ 00122008
undefined4 CanDeploy__15CBasePlayerItem(void)

{
  return 1;
}


// CanDeploy__17CBasePlayerWeapon  @ 001207f0
undefined4 CanDeploy__17CBasePlayerWeapon(int param_1)

{
  uint uVar1;
  undefined1 local_2c [8];
  int local_24;
  int local_20;
  int local_1c;
  
  uVar1 = 0;
  (**(code **)(*(int *)(param_1 + 0x444) + 0x118))(param_1,local_2c);
  if ((local_24 != 0) && (local_20 != -1)) {
    if (local_24 != 0) {
      if (*(int *)(param_1 + 0xb0) == 0) {
        if (*(int *)(*(int *)(param_1 + 0x4a8) * 4 + *(int *)(param_1 + 0x464) + 0x8c4) != 0) {
          uVar1 = 1;
        }
      }
      else {
        uVar1 = **(uint **)(param_1 + 0xb0);
      }
    }
    if ((local_1c != 0) &&
       (*(int *)(*(int *)(param_1 + 0x4ac) * 4 + *(int *)(param_1 + 0x464) + 0x8c4) != 0)) {
      uVar1 = uVar1 | 1;
    }
    if (0 < *(int *)(param_1 + 0x4b0)) {
      uVar1 = uVar1 | 1;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


