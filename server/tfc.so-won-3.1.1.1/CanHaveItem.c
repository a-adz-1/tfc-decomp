// CanHaveItem__13CTeamFortressP11CBasePlayerP5CItem  @ 000fbb48
undefined4
CanHaveItem__13CTeamFortressP11CBasePlayerP5CItem(undefined4 param_1,int param_2,undefined4 param_3)

{
  float fVar1;
  int iVar2;
  
  if ((((*(int *)(param_2 + 0x70) == 0) && ((*(uint *)(param_2 + 0x84) & 0x10800) == 0)) &&
      (fVar1 = *gpGlobals,
      (byte)(fVar1 < cb_prematch_time |
             (byte)((ushort)((ushort)(NAN(fVar1) || NAN(cb_prematch_time)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == cb_prematch_time) << 0xe) >> 8)) != 1)) &&
     (iVar2 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_3,param_2,0), iVar2 != 0))
  {
    return 1;
  }
  return 0;
}


// CanHaveItem__14CHalfLifeRulesP11CBasePlayerP5CItem  @ 000aff54
undefined4 CanHaveItem__14CHalfLifeRulesP11CBasePlayerP5CItem(void)

{
  return 1;
}


// CanHaveItem__18CHalfLifeMultiplayP11CBasePlayerP5CItem  @ 000af914
undefined4 CanHaveItem__18CHalfLifeMultiplayP11CBasePlayerP5CItem(void)

{
  return 1;
}


