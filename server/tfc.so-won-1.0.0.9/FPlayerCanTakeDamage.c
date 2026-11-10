// FPlayerCanTakeDamage__10CGameRulesP11CBasePlayerP11CBaseEntity  @ 000b89a0
undefined4 FPlayerCanTakeDamage__10CGameRulesP11CBasePlayerP11CBaseEntity(void)

{
  return 1;
}


// FPlayerCanTakeDamage__17CHalfLifeTeamplayP11CBasePlayerP11CBaseEntity  @ 000f38d0
undefined4
FPlayerCanTakeDamage__17CHalfLifeTeamplayP11CBasePlayerP11CBaseEntity
          (int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x28))(g_pGameRules);
  if ((((iVar1 != 0) && (param_3 != 0)) &&
      (iVar1 = (**(code **)(*param_1 + 0xd0))(param_1,param_2,param_3), iVar1 == 1)) &&
     ((lVar3 = (longdouble)(*DAT_001755a4)("mp_friendlyfire"),
      (byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0 == lVar3) << 0xe) >> 8)) == 0x40 &&
      (param_3 != param_2)))) {
    return 0;
  }
  uVar2 = FPlayerCanTakeDamage__18CHalfLifeMultiplayP11CBasePlayerP11CBaseEntity
                    (param_1,param_2,param_3);
  return uVar2;
}


// FPlayerCanTakeDamage__18CHalfLifeMultiplayP11CBasePlayerP11CBaseEntity  @ 000b7b50
undefined4 FPlayerCanTakeDamage__18CHalfLifeMultiplayP11CBasePlayerP11CBaseEntity(void)

{
  return 1;
}


