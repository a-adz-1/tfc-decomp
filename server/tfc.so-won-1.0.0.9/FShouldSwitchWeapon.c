// FShouldSwitchWeapon__14CHalfLifeRulesP11CBasePlayerP15CBasePlayerItem  @ 000b6f40
undefined4
FShouldSwitchWeapon__14CHalfLifeRulesP11CBasePlayerP15CBasePlayerItem
          (undefined4 param_1,int param_2)

{
  int iVar1;
  
  if ((*(int *)(param_2 + 0x830) != 0) &&
     (iVar1 = (**(code **)(*(int *)(*(int *)(param_2 + 0x830) + 0x3c8) + 0x11c))
                        (*(int *)(param_2 + 0x830)), iVar1 == 0)) {
    return 0;
  }
  return 1;
}


// FShouldSwitchWeapon__18CHalfLifeMultiplayP11CBasePlayerP15CBasePlayerItem  @ 000b73f0
undefined4 FShouldSwitchWeapon__18CHalfLifeMultiplayP11CBasePlayerP15CBasePlayerItem(void)

{
  return 0;
}


