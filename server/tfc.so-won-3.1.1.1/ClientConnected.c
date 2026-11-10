// ClientConnected__13CTeamFortressP7edict_sPCcT2Pc  @ 000fbc40
void ClientConnected__13CTeamFortressP7edict_sPCcT2Pc
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined4 uVar1;
  
  ClientConnected__13CVoiceGameMgrP7edict_s(param_1 + 0x18,param_2);
  if (g_bFirstClient == 0) {
    g_bFirstClient = 1;
    ParseTFServerSettings__Fv();
  }
  (*DAT_0019f758)(2,gmsgTeamInfo,0,0);
  uVar1 = (*DAT_0019f7bc)(param_2);
  (*DAT_0019f760)(uVar1);
  (*DAT_0019f778)(&DAT_00153be6);
  (*DAT_0019f75c)();
  (*DAT_0019f758)(1,9,0,param_2);
  uVar1 = UTIL_VarArgs__FPce("cl_forwardspeed %d\ncl_backspeed %d\ncl_sidespeed %d\n",400,400,400);
  (*DAT_0019f778)(uVar1);
  (*DAT_0019f75c)();
  ClientConnected__18CHalfLifeMultiplayP7edict_sPCcT2Pc(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ClientConnected__13CVoiceGameMgrP7edict_s  @ 0013ab14
void ClientConnected__13CVoiceGameMgrP7edict_s(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = (*DAT_0019f7bc)(param_2);
  iVar2 = iVar2 + -1;
  iVar4 = 0;
  (&g_bWantModEnable)[iVar2 >> 5] = (&g_bWantModEnable)[iVar2 >> 5] | 1 << ((byte)iVar2 & 0x1f);
  do {
    iVar3 = iVar4 >> 5;
    bVar1 = (byte)iVar4;
    iVar4 = iVar4 + 1;
    (&g_SentGameRulesMasks)[iVar2 + iVar3] =
         (&g_SentGameRulesMasks)[iVar2 + iVar3] & ~(1 << (bVar1 & 0x1f));
  } while (iVar4 < 0x20);
  iVar4 = 0;
  do {
    iVar3 = iVar4 >> 5;
    bVar1 = (byte)iVar4;
    iVar4 = iVar4 + 1;
    (&g_SentBanMasks)[iVar2 + iVar3] = (&g_SentBanMasks)[iVar2 + iVar3] & ~(1 << (bVar1 & 0x1f));
  } while (iVar4 < 0x20);
  return;
}


// ClientConnected__14CHalfLifeRulesP7edict_sPCcT2Pc  @ 000b0094
undefined4 ClientConnected__14CHalfLifeRulesP7edict_sPCcT2Pc(void)

{
  return 1;
}


// ClientConnected__18CHalfLifeMultiplayP7edict_sPCcT2Pc  @ 000afc68
undefined4
ClientConnected__18CHalfLifeMultiplayP7edict_sPCcT2Pc
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4,char *param_5)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar2 = GetBattleID__FP7edict_s(param_2);
  if (iVar2 != 0) {
    iVar5 = FindGhost__Fi(iVar2);
  }
  if ((((byte)((float)tfc_clanbattle_locked._12_4_ < 0.0 |
               (byte)((ushort)((ushort)NAN((float)tfc_clanbattle_locked._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)tfc_clanbattle_locked._12_4_ == 0.0) << 0xe) >> 8)) ==
        0x40) ||
      (fVar1 = *gpGlobals,
      (byte)((fVar1 < cb_prematch_time |
              (byte)((ushort)((ushort)(NAN(fVar1) || NAN(cb_prematch_time)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == cb_prematch_time) << 0xe) >> 8)) - 1) < 0x40)) ||
     (iVar5 != 0)) {
    iVar2 = 0;
    if ((uint)gpGlobals[0x24] < 0x80000000) {
      do {
        if ((&g_IpStorage)[iVar2 * 2] == 0) {
          pcVar4 = strchr(param_4,0x3a);
          if (pcVar4 != (char *)0x0) {
            *pcVar4 = '\0';
          }
          uVar3 = (*DAT_0019f7ac)(param_4);
          (&g_IpStorage)[iVar2 * 2] = uVar3;
          (&DAT_0019ef84)[iVar2 * 2] = param_2;
          if (pcVar4 != (char *)0x0) {
            *pcVar4 = ':';
          }
          break;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 <= (int)gpGlobals[0x24]);
    }
    uVar3 = 1;
  }
  else {
    builtin_strncpy(param_5,"#Game_locked",0xd);
    uVar3 = 0;
  }
  return uVar3;
}


