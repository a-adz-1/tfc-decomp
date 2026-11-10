// WeaponShouldRespawn__14CHalfLifeRulesP15CBasePlayerItem  @ 000aff60
undefined4 WeaponShouldRespawn__14CHalfLifeRulesP15CBasePlayerItem(void)

{
  return 2;
}


// WeaponShouldRespawn__18CHalfLifeMultiplayP15CBasePlayerItem  @ 000af920
undefined4
WeaponShouldRespawn__18CHalfLifeMultiplayP15CBasePlayerItem(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((*(byte *)(*param_2 + 0x1a3) & 0x40) == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}


