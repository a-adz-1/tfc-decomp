// FShouldSwitchWeapon__14CHalfLifeRulesP11CBasePlayerP15CBasePlayerItem  @ 000a389c
undefined4
FShouldSwitchWeapon__14CHalfLifeRulesP11CBasePlayerP15CBasePlayerItem
          (undefined4 param_1,int param_2)

{
  int iVar1;
  
  if ((*(int *)(param_2 + 0x844) != 0) &&
     (iVar1 = (**(code **)(*(int *)(*(int *)(param_2 + 0x844) + 0x3d4) + 0x11c))
                        (*(int *)(param_2 + 0x844)), iVar1 == 0)) {
    return 0;
  }
  return 1;
}


// FShouldSwitchWeapon__18CHalfLifeMultiplayP11CBasePlayerP15CBasePlayerItem  @ 000a3e0c
undefined4 FShouldSwitchWeapon__18CHalfLifeMultiplayP11CBasePlayerP15CBasePlayerItem(void)

{
  return 0;
}


