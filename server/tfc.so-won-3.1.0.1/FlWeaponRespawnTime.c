// FlWeaponRespawnTime__14CHalfLifeRulesP15CBasePlayerItem  @ 000a3984
longdouble FlWeaponRespawnTime__14CHalfLifeRulesP15CBasePlayerItem(void)

{
  return (longdouble)-1.0;
}


// FlWeaponRespawnTime__18CHalfLifeMultiplayP15CBasePlayerItem  @ 000a4c14
longdouble
FlWeaponRespawnTime__18CHalfLifeMultiplayP15CBasePlayerItem(undefined4 param_1,int param_2)

{
  undefined1 local_2c [36];
  uint local_8;
  
  if (0.0 < (float)weaponstay._12_4_) {
    local_8 = 0;
    (**(code **)(*(int *)(param_2 + 0x3d4) + 0x110))(param_2,local_2c);
    if ((local_8 & 8) == 0) {
      return (longdouble)*gpGlobals;
    }
  }
  return (longdouble)20.0 + (longdouble)*gpGlobals;
}


