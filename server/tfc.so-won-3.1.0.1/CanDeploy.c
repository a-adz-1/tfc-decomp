// CanDeploy__15CBasePlayerItem  @ 00112458
undefined4 CanDeploy__15CBasePlayerItem(void)

{
  return 1;
}


// CanDeploy__17CBasePlayerWeapon  @ 00110ca0
undefined4 CanDeploy__17CBasePlayerWeapon(int param_1)

{
  uint uVar1;
  undefined1 local_2c [8];
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  
  uVar1 = 0;
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x110))(param_1,local_2c);
  if ((iStack_24 != 0) && (iStack_20 != -1)) {
    if (iStack_24 != 0) {
      if (*(int *)(param_1 + 0xb0) == 0) {
        if (*(int *)(*(int *)(param_1 + 0x438) * 4 + *(int *)(param_1 + 0x3f4) + 0x850) != 0) {
          uVar1 = 1;
        }
      }
      else {
        uVar1 = **(uint **)(param_1 + 0xb0);
      }
    }
    if ((iStack_1c != 0) &&
       (*(int *)(*(int *)(param_1 + 0x43c) * 4 + *(int *)(param_1 + 0x3f4) + 0x850) != 0)) {
      uVar1 = uVar1 | 1;
    }
    if (0 < *(int *)(param_1 + 0x440)) {
      uVar1 = uVar1 | 1;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


