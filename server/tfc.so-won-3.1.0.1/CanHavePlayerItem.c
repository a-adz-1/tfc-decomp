// CanHavePlayerItem__10CGameRulesP11CBasePlayerP15CBasePlayerItem  @ 000a3664
undefined4
CanHavePlayerItem__10CGameRulesP11CBasePlayerP15CBasePlayerItem
          (int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 local_2c [8];
  int local_24;
  undefined4 local_20;
  
  iVar1 = (**(code **)(*(int *)(param_3 + 0x3d4) + 0x110))(param_3,local_2c);
  if ((iVar1 != 0) &&
     (((local_24 == 0 ||
       (iVar1 = (**(code **)(*param_1 + 0xa8))(param_1,param_2,local_24,local_20), iVar1 == 0)) &&
      (iVar1 = HasPlayerItem__11CBasePlayerP15CBasePlayerItem(param_2,param_3), iVar1 != 0)))) {
    return 0;
  }
  return 1;
}


// CanHavePlayerItem__18CHalfLifeMultiplayP11CBasePlayerP15CBasePlayerItem  @ 000a4d58
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
CanHavePlayerItem__18CHalfLifeMultiplayP11CBasePlayerP15CBasePlayerItem
          (undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_2c [32];
  int local_c;
  uint local_8;
  
  if (_FUN_00136090 < (float)weaponstay._12_4_) {
    local_8 = 0;
    (**(code **)(*(int *)(param_3 + 0x3d4) + 0x110))(param_3,local_2c);
    if ((local_8 & 8) == 0) {
      for (iVar1 = *(int *)(param_2 + 0x82c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x3f8)) {
        if (*(int *)(iVar1 + 0x3fc) == local_c) {
          return 0;
        }
      }
      for (iVar1 = *(int *)(param_2 + 0x830); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x3f8)) {
        if (*(int *)(iVar1 + 0x3fc) == local_c) {
          return 0;
        }
      }
      for (iVar1 = *(int *)(param_2 + 0x834); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x3f8)) {
        if (*(int *)(iVar1 + 0x3fc) == local_c) {
          return 0;
        }
      }
      for (iVar1 = *(int *)(param_2 + 0x838); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x3f8)) {
        if (*(int *)(iVar1 + 0x3fc) == local_c) {
          return 0;
        }
      }
      for (iVar1 = *(int *)(param_2 + 0x83c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x3f8)) {
        if (*(int *)(iVar1 + 0x3fc) == local_c) {
          return 0;
        }
      }
      for (iVar1 = *(int *)(param_2 + 0x840); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x3f8)) {
        if (*(int *)(iVar1 + 0x3fc) == local_c) {
          return 0;
        }
      }
    }
  }
  uVar2 = CanHavePlayerItem__10CGameRulesP11CBasePlayerP15CBasePlayerItem(param_1,param_2,param_3);
  return uVar2;
}


