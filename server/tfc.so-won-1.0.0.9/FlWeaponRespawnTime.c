// FlWeaponRespawnTime__14CHalfLifeRulesP15CBasePlayerItem  @ 000b7090
longdouble FlWeaponRespawnTime__14CHalfLifeRulesP15CBasePlayerItem(void)

{
  return (longdouble)-1.0;
}


// FlWeaponRespawnTime__18CHalfLifeMultiplayP15CBasePlayerItem  @ 000b8100
longdouble
FlWeaponRespawnTime__18CHalfLifeMultiplayP15CBasePlayerItem(undefined4 param_1,int param_2)

{
  undefined1 local_30 [36];
  uint local_c;
  
  if (0.0 < (float)weaponstay._12_4_) {
    local_c = 0;
    (**(code **)(*(int *)(param_2 + 0x3c8) + 0x110))(param_2,local_30);
    if ((local_c & 8) == 0) {
      return (longdouble)*gpGlobals + (longdouble)0.0;
    }
  }
  return (longdouble)20.0 + (longdouble)*gpGlobals;
}


