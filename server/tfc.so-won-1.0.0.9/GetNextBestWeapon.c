// GetNextBestWeapon__14CHalfLifeRulesP11CBasePlayerP15CBasePlayerItem  @ 000b6f80
undefined4 GetNextBestWeapon__14CHalfLifeRulesP11CBasePlayerP15CBasePlayerItem(void)

{
  return 0;
}


// GetNextBestWeapon__18CHalfLifeMultiplayP11CBasePlayerP15CBasePlayerItem  @ 000b7480
undefined4
GetNextBestWeapon__18CHalfLifeMultiplayP11CBasePlayerP15CBasePlayerItem
          (undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_38;
  int local_34;
  undefined1 auStack_30 [40];
  int iStack_8;
  
  local_38 = -1;
  local_34 = 0;
  iVar2 = (**(code **)(*(int *)(param_3 + 0x3c8) + 0x11c))(param_3);
  if (iVar2 != 0) {
    (**(code **)(*(int *)(param_3 + 0x3c8) + 0x110))(param_3,auStack_30);
    iVar2 = iStack_8;
    iVar4 = 0;
    do {
      for (iVar1 = *(int *)(param_2 + 0x818 + iVar4 * 4); iVar1 != 0;
          iVar1 = *(int *)(iVar1 + 0x3ec)) {
        (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x110))(iVar1,auStack_30);
        if (((iStack_8 < 0) || (iStack_8 != iVar2)) || (iVar1 == param_3)) {
          if (((local_38 < iStack_8) && (iVar1 != param_3)) &&
             (iVar3 = (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x114))(iVar1), iVar3 != 0)) {
            local_38 = iStack_8;
            local_34 = iVar1;
          }
        }
        else {
          iVar3 = (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x114))(iVar1);
          if ((iVar3 != 0) &&
             (iVar3 = SwitchWeapon__11CBasePlayerP15CBasePlayerItem(param_2,iVar1), iVar3 != 0)) {
            return 1;
          }
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 6);
    if (local_34 != 0) {
      SwitchWeapon__11CBasePlayerP15CBasePlayerItem(param_2,local_34);
      return 1;
    }
  }
  return 0;
}


