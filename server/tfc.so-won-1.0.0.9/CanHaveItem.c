// CanHaveItem__13CTeamFortressP11CBasePlayerP5CItem  @ 000f52c0
undefined4
CanHaveItem__13CTeamFortressP11CBasePlayerP5CItem(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((((*(int *)(param_2 + 0x74) == 0) && ((*(uint *)(param_2 + 0x88) & 0x10800) == 0)) &&
      (cb_prematch_time <= *gpGlobals)) &&
     (iVar1 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_3,param_2,0), iVar1 != 0))
  {
    return 1;
  }
  return 0;
}


// CanHaveItem__14CHalfLifeRulesP11CBasePlayerP5CItem  @ 000b70f0
undefined4 CanHaveItem__14CHalfLifeRulesP11CBasePlayerP5CItem(void)

{
  return 1;
}


// CanHaveItem__18CHalfLifeMultiplayP11CBasePlayerP5CItem  @ 000b82f0
undefined4 CanHaveItem__18CHalfLifeMultiplayP11CBasePlayerP5CItem(void)

{
  return 1;
}


