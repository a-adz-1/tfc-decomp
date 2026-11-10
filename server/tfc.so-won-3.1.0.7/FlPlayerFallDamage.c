// FlPlayerFallDamage__14CHalfLifeRulesP11CBasePlayer  @ 000ae42c
longdouble FlPlayerFallDamage__14CHalfLifeRulesP11CBasePlayer(undefined4 param_1,int param_2)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)*(float *)(param_2 + 0x6c8) - (longdouble)650.0;
  *(float *)(param_2 + 0x6c8) = (float)lVar1;
  return (longdouble)0.26737967 * lVar1;
}


// FlPlayerFallDamage__18CHalfLifeMultiplayP11CBasePlayer  @ 000af1d0
longdouble FlPlayerFallDamage__18CHalfLifeMultiplayP11CBasePlayer(undefined4 param_1,int param_2)

{
  longdouble lVar1;
  
  if (((int)ROUND((float)falldamage._12_4_) == 0) || ((int)ROUND((float)falldamage._12_4_) != 1)) {
    lVar1 = (longdouble)10.0;
  }
  else {
    lVar1 = (longdouble)*(float *)(param_2 + 0x6c8) - (longdouble)650.0;
    *(float *)(param_2 + 0x6c8) = (float)lVar1;
    lVar1 = (longdouble)0.26737967 * lVar1;
  }
  return lVar1;
}


