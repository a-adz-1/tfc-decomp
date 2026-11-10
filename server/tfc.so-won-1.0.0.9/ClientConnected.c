// ClientConnected__13CTeamFortressP7edict_sPCcT2Pc  @ 000f4eb0
void ClientConnected__13CTeamFortressP7edict_sPCcT2Pc
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined4 uVar1;
  
  if (g_bFirstClient == 0) {
    g_bFirstClient = 1;
    ParseTFServerSettings__Fv();
  }
  (*DAT_00175578)(2,gmsgTeamInfo,0,0);
  uVar1 = (*DAT_001755dc)(param_2);
  (*DAT_00175580)(uVar1);
  (*DAT_00175598)(&DAT_0013f6c6);
  (*DAT_0017557c)();
  ClientConnected__18CHalfLifeMultiplayP7edict_sPCcT2Pc(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ClientConnected__14CHalfLifeRulesP7edict_sPCcT2Pc  @ 000b6f90
undefined4 ClientConnected__14CHalfLifeRulesP7edict_sPCcT2Pc(void)

{
  return 1;
}


// ClientConnected__18CHalfLifeMultiplayP7edict_sPCcT2Pc  @ 000b75b0
undefined4
ClientConnected__18CHalfLifeMultiplayP7edict_sPCcT2Pc
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4,char *param_5)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar2 = GetBattleID__FP7edict_s(param_2);
  if (iVar2 != 0) {
    iVar5 = FindGhost__Fi(iVar2);
  }
  if ((((byte)(0.0 < (float)tfc_clanbattle_locked._12_4_ |
               (byte)((ushort)((ushort)NAN((float)tfc_clanbattle_locked._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)tfc_clanbattle_locked._12_4_ == 0.0) << 0xe) >> 8)) !=
        0x40) &&
      (fVar1 = *gpGlobals,
      (byte)(cb_prematch_time < fVar1 |
             (byte)((ushort)((ushort)(NAN(cb_prematch_time) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(cb_prematch_time == fVar1) << 0xe) >> 8)) == 1)) &&
     (iVar5 == 0)) {
    builtin_strncpy(param_5,"#Game_locked",0xd);
    return 0;
  }
  iVar2 = 0;
  while( true ) {
    if ((int)gpGlobals[0x24] < iVar2) {
      return 1;
    }
    if ((&g_IpStorage)[iVar2 * 2] == 0) break;
    iVar2 = iVar2 + 1;
  }
  pcVar3 = strchr(param_4,0x3a);
  if (pcVar3 != (char *)0x0) {
    *pcVar3 = '\0';
  }
  uVar4 = (*DAT_001755cc)(param_4);
  (&g_IpStorage)[iVar2 * 2] = uVar4;
  (&DAT_00175384)[iVar2 * 2] = param_2;
  if (pcVar3 == (char *)0x0) {
    return 1;
  }
  *pcVar3 = ':';
  return 1;
}


