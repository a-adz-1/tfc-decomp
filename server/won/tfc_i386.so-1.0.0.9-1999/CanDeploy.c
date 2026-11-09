// CanDeploy__15CBasePlayerItem  @ 0011cc60
undefined4 CanDeploy__15CBasePlayerItem(void)

{
  return 1;
}


// CanDeploy__17CBasePlayerWeapon  @ 0011b930
undefined4 CanDeploy__17CBasePlayerWeapon(int param_1)

{
  uint uVar1;
  undefined1 local_30 [8];
  int local_28;
  int local_24;
  int local_20;
  
  uVar1 = 0;
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x110))(param_1,local_30);
  if ((local_28 != 0) && (local_24 != -1)) {
    if (local_28 != 0) {
      if (*(int *)(param_1 + 0xb0) == 0) {
        if (*(int *)(*(int *)(param_1 + 0x408) * 4 + *(int *)(param_1 + 1000) + 0x83c) != 0) {
          uVar1 = 1;
        }
      }
      else {
        uVar1 = **(uint **)(param_1 + 0xb0);
      }
    }
    if ((local_20 != 0) &&
       (*(int *)(*(int *)(param_1 + 0x40c) * 4 + *(int *)(param_1 + 1000) + 0x83c) != 0)) {
      uVar1 = uVar1 | 1;
    }
    if (0 < *(int *)(param_1 + 0x410)) {
      uVar1 = uVar1 | 1;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


