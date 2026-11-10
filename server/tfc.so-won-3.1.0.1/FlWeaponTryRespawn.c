// FlWeaponTryRespawn__14CHalfLifeRulesP15CBasePlayerItem  @ 000a399c
longdouble FlWeaponTryRespawn__14CHalfLifeRulesP15CBasePlayerItem(void)

{
  return (longdouble)0.0;
}


// FlWeaponTryRespawn__18CHalfLifeMultiplayP15CBasePlayerItem  @ 000a4c88
longdouble FlWeaponTryRespawn__18CHalfLifeMultiplayP15CBasePlayerItem(int *param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  
  if (((param_2 == 0) || (*(int *)(param_2 + 0x3fc) == 0)) ||
     ((_15CBasePlayerItem_ItemInfoArray[*(int *)(param_2 + 0x3fc) * 0x2c + 0x24] & 8) == 0)) {
    lVar2 = (longdouble)0.0;
  }
  else {
    iVar1 = (*DAT_001a7fe4)();
    if (iVar1 < *(int *)(gpGlobals + 0x94) + -100) {
      lVar2 = (longdouble)0.0;
    }
    else {
      lVar2 = (longdouble)(**(code **)(*param_1 + 0x88))(param_1,param_2);
    }
  }
  return lVar2;
}


