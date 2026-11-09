// MaxPlayers_f  @ 00176180
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void MaxPlayers_f(void)

{
  int iVar1;
  char *str;
  int iVar2;
  
                    /* Unresolved local var: int n@[???] */
  iVar1 = Cmd_Argc();
  if (iVar1 != 2) {
    Con_Printf("\"maxplayers\" is \"%u\"\n",svs.maxclients);
    return;
  }
  if (sv.active == false) {
    str = Cmd_Argv(1);
    iVar2 = Q_atoi(str);
    iVar1 = svs.maxclientslimit;
    if (iVar2 < 1) {
      iVar2 = 1;
    }
    if (svs.maxclientslimit < iVar2) {
      Con_Printf("\"maxplayers\" set to \"%u\"\n",svs.maxclientslimit);
      iVar2 = iVar1;
    }
    svs.maxclients = iVar2;
    if (iVar2 == 1) {
                    /* Unresolved local var: int n@[???] */
      Cvar_Set("deathmatch","0");
    }
    else {
      Cvar_Set("deathmatch","1");
    }
    return;
  }
  Con_Printf("maxplayers cannot be changed while a server is running.\n");
  return;
}


