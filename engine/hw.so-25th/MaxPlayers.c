// MaxPlayers_f  @ 0011a610
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
  if (sv.active != false) {
    Con_Printf("maxplayers cannot be changed while a server is running.\n");
    return;
  }
  str = Cmd_Argv(1);
  iVar2 = Q_atoi(str);
  iVar1 = svs.maxclientslimit;
  if (iVar2 < 1) {
    if (0 < svs.maxclientslimit) {
      svs.maxclients = 1;
      goto LAB_0011a6ce;
    }
LAB_0011a6a8:
    Con_Printf("\"maxplayers\" set to \"%u\"\n",svs.maxclientslimit);
    iVar2 = iVar1;
  }
  else if (svs.maxclientslimit < iVar2) goto LAB_0011a6a8;
  svs.maxclients = iVar2;
  if (iVar2 != 1) {
    Cvar_Set("deathmatch","1");
    return;
  }
LAB_0011a6ce:
                    /* Unresolved local var: int n@[???] */
  Cvar_Set("deathmatch","0");
  return;
}


