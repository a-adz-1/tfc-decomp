// CanHavePlayerItem__10CGameRulesP11CBasePlayerP15CBasePlayerItem  @ 000b6d00
undefined4
CanHavePlayerItem__10CGameRulesP11CBasePlayerP15CBasePlayerItem
          (int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 local_30 [8];
  int local_28;
  undefined4 local_24;
  
  iVar1 = (**(code **)(*(int *)(param_3 + 0x3c8) + 0x110))(param_3,local_30);
  if ((iVar1 != 0) &&
     (((local_28 == 0 ||
       (iVar1 = (**(code **)(*param_1 + 0xa8))(param_1,param_2,local_28,local_24), iVar1 == 0)) &&
      (iVar1 = HasPlayerItem__11CBasePlayerP15CBasePlayerItem(param_2,param_3), iVar1 != 0)))) {
    return 0;
  }
  return 1;
}


// CanHavePlayerItem__18CHalfLifeMultiplayP11CBasePlayerP15CBasePlayerItem  @ 000b8240
undefined8
CanHavePlayerItem__18CHalfLifeMultiplayP11CBasePlayerP15CBasePlayerItem
          (undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_30 [32];
  int local_10;
  uint local_c;
  
  if ((byte)(0.0 < (float)weaponstay._12_4_ |
             (byte)((ushort)((ushort)NAN((float)weaponstay._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)weaponstay._12_4_ == 0.0) << 0xe) >> 8)) == 1) {
    local_c = 0;
    (**(code **)(*(int *)(param_3 + 0x3c8) + 0x110))(param_3,local_30);
    if ((local_c & 8) == 0) {
      iVar1 = 0;
      do {
        for (iVar2 = *(int *)(param_2 + 0x818 + iVar1 * 4); iVar2 != 0;
            iVar2 = *(int *)(iVar2 + 0x3ec)) {
          if (*(int *)(iVar2 + 0x3f0) == local_10) {
            iVar1 = 0;
            goto LAB_000b82d8;
          }
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 6);
    }
  }
  iVar1 = CanHavePlayerItem__10CGameRulesP11CBasePlayerP15CBasePlayerItem(param_1,param_2,param_3);
  iVar2 = iVar1;
LAB_000b82d8:
  return CONCAT44(iVar2,iVar1);
}


