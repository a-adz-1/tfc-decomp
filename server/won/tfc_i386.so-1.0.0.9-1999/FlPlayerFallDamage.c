// FlPlayerFallDamage__14CHalfLifeRulesP11CBasePlayer  @ 000b6fc0
longdouble FlPlayerFallDamage__14CHalfLifeRulesP11CBasePlayer(undefined4 param_1,int param_2)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)*(float *)(param_2 + 0x648) - (longdouble)650.0;
  *(float *)(param_2 + 0x648) = (float)lVar1;
  return ((longdouble)100.0 * lVar1) / (longdouble)374.0;
}


// FlPlayerFallDamage__18CHalfLifeMultiplayP11CBasePlayer  @ 000b7ae0
longdouble FlPlayerFallDamage__18CHalfLifeMultiplayP11CBasePlayer(undefined4 param_1,int param_2)

{
  longdouble lVar1;
  
  if (((int)ROUND((float)falldamage._12_4_) == 0) || ((int)ROUND((float)falldamage._12_4_) != 1)) {
    lVar1 = (longdouble)10.0;
  }
  else {
    lVar1 = (longdouble)*(float *)(param_2 + 0x648) - (longdouble)650.0;
    *(float *)(param_2 + 0x648) = (float)lVar1;
    lVar1 = ((longdouble)100.0 * lVar1) / (longdouble)374.0;
  }
  return lVar1;
}


