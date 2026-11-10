// CanHavePlayerItem__10CGameRulesP11CBasePlayerP15CBasePlayerItem  @ 000b0154
undefined4
CanHavePlayerItem__10CGameRulesP11CBasePlayerP15CBasePlayerItem
          (int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 local_30 [8];
  int local_28;
  undefined4 local_24;
  
  iVar1 = (**(code **)(*(int *)(param_3 + 0x454) + 0x118))(param_3,local_30);
  if ((iVar1 != 0) &&
     (((local_28 == 0 ||
       (iVar1 = (**(code **)(*param_1 + 0xa8))(param_1,param_2,local_28,local_24), iVar1 == 0)) &&
      (iVar1 = HasPlayerItem__11CBasePlayerP15CBasePlayerItem(param_2,param_3), iVar1 != 0)))) {
    return 0;
  }
  return 1;
}


// CanHavePlayerItem__18CHalfLifeMultiplayP11CBasePlayerP15CBasePlayerItem  @ 000ae84c
undefined4
CanHavePlayerItem__18CHalfLifeMultiplayP11CBasePlayerP15CBasePlayerItem
          (int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_5c [8];
  int local_54;
  undefined4 local_50;
  undefined1 local_30 [32];
  int local_10;
  uint local_c;
  
  if (0.0 < (float)weaponstay._12_4_) {
    local_c = 0;
    (**(code **)(*(int *)(param_3 + 0x454) + 0x118))(param_3,local_30);
    if ((local_c & 8) != 0) {
      iVar2 = (**(code **)(*(int *)(param_3 + 0x454) + 0x118))(param_3,local_5c);
      if (iVar2 == 0) {
        return 1;
      }
      if (local_54 == 0) {
        uVar3 = FUN_000ae964();
        return uVar3;
      }
      goto LAB_000ae923;
    }
    iVar2 = 0;
    do {
      for (iVar1 = *(int *)(param_2 + 0x8c4 + iVar2 * 4); iVar1 != 0;
          iVar1 = *(int *)(iVar1 + 0x478)) {
        if (*(int *)(iVar1 + 0x47c) == local_10) {
          return 0;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 6);
  }
  iVar2 = (**(code **)(*(int *)(param_3 + 0x454) + 0x118))(param_3,local_5c);
  if (iVar2 == 0) {
    return 1;
  }
  if (local_54 == 0) {
    iVar2 = HasPlayerItem__11CBasePlayerP15CBasePlayerItem(param_2,param_3);
    if (iVar2 == 0) {
      return 1;
    }
    return 0;
  }
LAB_000ae923:
  iVar2 = (**(code **)(*param_1 + 0xa8))(param_1,param_2,local_54,local_50);
  if ((iVar2 == 0) &&
     (iVar2 = HasPlayerItem__11CBasePlayerP15CBasePlayerItem(param_2,param_3), iVar2 != 0)) {
    return 0;
  }
  return 1;
}


