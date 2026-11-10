// ClientConnected__13CTeamFortressP7edict_sPCcT2Pc  @ 000f9160
void ClientConnected__13CTeamFortressP7edict_sPCcT2Pc
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined4 uVar1;
  
  if (g_bFirstClient == 0) {
    g_bFirstClient = 1;
    ParseTFServerSettings__Fv();
  }
  (*DAT_001c10d8)(2,gmsgTeamInfo,0,0);
  uVar1 = (*DAT_001c113c)(param_2);
  (*DAT_001c10e0)(uVar1);
  (*DAT_001c10f8)(&DAT_0014eaa6);
  (*DAT_001c10dc)();
  (*DAT_001c10d8)(1,9,0,param_2);
  uVar1 = UTIL_VarArgs__FPce("cl_forwardspeed %d\ncl_backspeed %d\ncl_sidespeed %d\n",400,400,400);
  (*DAT_001c10f8)(uVar1);
  (*DAT_001c10dc)();
  ClientConnected__18CHalfLifeMultiplayP7edict_sPCcT2Pc(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ClientConnected__14CHalfLifeRulesP7edict_sPCcT2Pc  @ 000ae41c
undefined4 ClientConnected__14CHalfLifeRulesP7edict_sPCcT2Pc(void)

{
  return 1;
}


// ClientConnected__18CHalfLifeMultiplayP7edict_sPCcT2Pc  @ 000aebcc
undefined4
ClientConnected__18CHalfLifeMultiplayP7edict_sPCcT2Pc
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4,char *param_5)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar1 = GetBattleID__FP7edict_s(param_2);
  if (iVar1 != 0) {
    iVar4 = FindGhost__Fi(iVar1);
  }
  if ((((byte)(0.0 < (float)tfc_clanbattle_locked._12_4_ |
               (byte)((ushort)((ushort)NAN((float)tfc_clanbattle_locked._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)tfc_clanbattle_locked._12_4_ == 0.0) << 0xe) >> 8)) ==
        0x40) || (*gpGlobals <= cb_prematch_time)) || (iVar4 != 0)) {
    iVar1 = 0;
    if ((uint)gpGlobals[0x24] < 0x80000000) {
      iVar4 = 0;
      do {
        if (*(int *)((int)&g_IpStorage + iVar4) == 0) {
          pcVar3 = strchr(param_4,0x3a);
          if (pcVar3 != (char *)0x0) {
            *pcVar3 = '\0';
          }
          uVar2 = (*DAT_001c112c)(param_4);
          *(undefined4 *)((int)&g_IpStorage + iVar4) = uVar2;
          *(undefined4 *)((int)&DAT_001c0904 + iVar4) = param_2;
          if (pcVar3 != (char *)0x0) {
            *pcVar3 = ':';
          }
          break;
        }
        iVar4 = iVar4 + 8;
        iVar1 = iVar1 + 1;
      } while (iVar1 <= (int)gpGlobals[0x24]);
    }
    uVar2 = 1;
  }
  else {
    builtin_strncpy(param_5,"#Game_locked",0xd);
    uVar2 = 0;
  }
  return uVar2;
}


