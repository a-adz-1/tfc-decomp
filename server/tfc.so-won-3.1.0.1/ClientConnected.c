// ClientConnected__13CTeamFortressP7edict_sPCcT2Pc  @ 000ec314
void ClientConnected__13CTeamFortressP7edict_sPCcT2Pc(void)

{
  FUN_000ec31c();
  return;
}


// ClientConnected__14CHalfLifeRulesP7edict_sPCcT2Pc  @ 000a38e4
undefined4 ClientConnected__14CHalfLifeRulesP7edict_sPCcT2Pc(void)

{
  return 1;
}


// ClientConnected__18CHalfLifeMultiplayP7edict_sPCcT2Pc  @ 000a3ff8
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
          uVar2 = (*DAT_001a7f4c)(param_4);
          *(undefined4 *)((int)&g_IpStorage + iVar4) = uVar2;
          *(undefined4 *)((int)&DAT_001a7724 + iVar4) = param_2;
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


