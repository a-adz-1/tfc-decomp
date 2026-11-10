// FShouldSwitchWeapon__14CHalfLifeRulesP11CBasePlayerP15CBasePlayerItem  @ 000b00ac
undefined4
FShouldSwitchWeapon__14CHalfLifeRulesP11CBasePlayerP15CBasePlayerItem
          (undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x8dc);
  if ((iVar1 != 0) && (iVar1 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x124))(iVar1), iVar1 == 0)) {
    return 0;
  }
  return 1;
}


// FShouldSwitchWeapon__18CHalfLifeMultiplayP11CBasePlayerP15CBasePlayerItem  @ 000afe20
undefined4 FShouldSwitchWeapon__18CHalfLifeMultiplayP11CBasePlayerP15CBasePlayerItem(void)

{
  return 0;
}


