// Master_Heartbeat_f  @ 000b8a80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Master_Heartbeat_f(void)

{
  return;
}


// Master_IsLanGame  @ 000b8a60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Master_IsLanGame(void)

{
  qboolean qVar1;
  
  qVar1 = (qboolean)NAN(sv_lan.value);
  if (sv_lan.value != 0.0) {
    qVar1 = true;
  }
  return qVar1;
}


// Master_SetMaster_f  @ 00130cf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Master_SetMaster_f(void)

{
  int iVar1;
  char *s1;
  undefined4 *puVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int ipPort@[???]
                       Unresolved local var: char * pszCmd@[???] */
  iVar1 = Cmd_Argc();
  if (s_Steam3Server == (CSteam3Server *)0x0) {
    Con_Printf("Usage:\nSetmaster unavailable, start a server first.\n");
  }
  else {
    if (3 < iVar1 - 2U) {
      Con_Printf("Usage:\nSetmaster <enable | disable>\n");
      return;
    }
    s1 = Cmd_Argv(1);
    if ((s1 != (char *)0x0) && (*s1 != '\0')) {
      iVar1 = Q_stricmp(s1,"disable");
      if ((iVar1 == 0) && (gfNoMasterServer == false)) {
        gfNoMasterServer = true;
      }
      else {
        iVar1 = Q_stricmp(s1,"enable");
        if (iVar1 != 0) {
          return;
        }
        if (gfNoMasterServer == false) {
          return;
        }
        gfNoMasterServer = false;
      }
      puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext)
      ;
      (**(code **)(*(int *)*puVar2 + 0x60))((int *)*puVar2,gfNoMasterServer != false);
      return;
    }
  }
  return;
}


