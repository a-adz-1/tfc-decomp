// FlWeaponTryRespawn__14CHalfLifeRulesP15CBasePlayerItem  @ 000b70a0
longdouble FlWeaponTryRespawn__14CHalfLifeRulesP15CBasePlayerItem(void)

{
  return (longdouble)0;
}


// FlWeaponTryRespawn__18CHalfLifeMultiplayP15CBasePlayerItem  @ 000b8170
longdouble FlWeaponTryRespawn__18CHalfLifeMultiplayP15CBasePlayerItem(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  if ((((param_2 != 0) && (*(int *)(param_2 + 0x3f0) != 0)) &&
      ((*(byte *)(&DAT_00182aa4 + *(int *)(param_2 + 0x3f0) * 0xb) & 8) != 0)) &&
     (iVar1 = (*DAT_00175664)(), *(int *)(gpGlobals + 0x94) + -100 <= iVar1)) {
    lVar2 = (longdouble)(**(code **)(*param_1 + 0x88))(param_1,param_2);
    return lVar2;
  }
  return (longdouble)0;
}


