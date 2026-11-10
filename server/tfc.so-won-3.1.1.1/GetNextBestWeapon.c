// GetNextBestWeapon__14CHalfLifeRulesP11CBasePlayerP15CBasePlayerItem  @ 000b00a0
undefined4 GetNextBestWeapon__14CHalfLifeRulesP11CBasePlayerP15CBasePlayerItem(void)

{
  return 0;
}


// GetNextBestWeapon__18CHalfLifeMultiplayP11CBasePlayerP15CBasePlayerItem  @ 000adbd4
undefined4
GetNextBestWeapon__18CHalfLifeMultiplayP11CBasePlayerP15CBasePlayerItem
          (undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int local_38;
  int local_34;
  undefined1 local_30 [40];
  int local_8;
  
  local_38 = -1;
  local_34 = 0;
  iVar2 = (**(code **)(*(int *)(param_3 + 0x454) + 0x124))(param_3);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    (**(code **)(*(int *)(param_3 + 0x454) + 0x118))(param_3,local_30);
    iVar2 = local_8;
    iVar5 = 0;
    do {
      for (iVar1 = *(int *)(param_2 + 0x8c4 + iVar5 * 4); iVar1 != 0;
          iVar1 = *(int *)(iVar1 + 0x478)) {
        (**(code **)(*(int *)(iVar1 + 0x454) + 0x118))(iVar1,local_30);
        if (((local_8 < 0) || (local_8 != iVar2)) || (iVar1 == param_3)) {
          if (((local_38 < local_8) && (iVar1 != param_3)) &&
             (iVar4 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x11c))(iVar1), iVar4 != 0)) {
            local_38 = local_8;
            local_34 = iVar1;
          }
        }
        else {
          iVar4 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x11c))(iVar1);
          if ((iVar4 != 0) &&
             (iVar4 = SwitchWeapon__11CBasePlayerP15CBasePlayerItem(param_2,iVar1), iVar4 != 0)) {
            return 1;
          }
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 6);
    if (local_34 == 0) {
      uVar3 = 0;
    }
    else {
      SwitchWeapon__11CBasePlayerP15CBasePlayerItem(param_2,local_34);
      uVar3 = 1;
    }
  }
  return uVar3;
}


