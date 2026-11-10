// AmmoShouldRespawn__14CHalfLifeRulesP15CBasePlayerAmmo  @ 000afed8
undefined4 AmmoShouldRespawn__14CHalfLifeRulesP15CBasePlayerAmmo(void)

{
  return 4;
}


// AmmoShouldRespawn__18CHalfLifeMultiplayP15CBasePlayerAmmo  @ 000af860
undefined4
AmmoShouldRespawn__18CHalfLifeMultiplayP15CBasePlayerAmmo(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((*(byte *)(*param_2 + 0x1a3) & 0x40) == 0) {
    uVar1 = 3;
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}


