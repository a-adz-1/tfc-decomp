// CanHavePlayerItem__10CGameRulesP11CBasePlayerP15CBasePlayerItem  @ 000ae19c
undefined4
CanHavePlayerItem__10CGameRulesP11CBasePlayerP15CBasePlayerItem
          (int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 local_2c [8];
  int local_24;
  undefined4 local_20;
  
  iVar1 = (**(code **)(*(int *)(param_3 + 0x444) + 0x118))(param_3,local_2c);
  if ((iVar1 != 0) &&
     (((local_24 == 0 ||
       (iVar1 = (**(code **)(*param_1 + 0xa8))(param_1,param_2,local_24,local_20), iVar1 == 0)) &&
      (iVar1 = HasPlayerItem__11CBasePlayerP15CBasePlayerItem(param_2,param_3), iVar1 != 0)))) {
    return 0;
  }
  return 1;
}


// CanHavePlayerItem__18CHalfLifeMultiplayP11CBasePlayerP15CBasePlayerItem  @ 000afabc
void CanHavePlayerItem__18CHalfLifeMultiplayP11CBasePlayerP15CBasePlayerItem(void)

{
  FUN_000afac8();
  return;
}


