// MaxPlayers_f  @ 000c5ab4
void MaxPlayers_f(void)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    if (sv == 0) {
      uVar2 = Cmd_Argv(1);
      local_8 = Q_atoi(uVar2);
      if (local_8 < 1) {
        local_8 = 1;
      }
      if (DAT_0052428c < local_8) {
        local_8 = DAT_0052428c;
        Con_Printf("\"maxplayers\" set to \"%u\"\n",DAT_0052428c);
      }
      DAT_00524288 = local_8;
      if (local_8 == 1) {
        Cvar_Set("deathmatch",&DAT_000ed3da);
      }
      else {
        Cvar_Set("deathmatch",&DAT_000ed47d);
      }
    }
    else {
      Con_Printf("maxplayers cannot be changed while a server is running.\n");
    }
  }
  else {
    Con_Printf("\"maxplayers\" is \"%u\"\n",DAT_00524288);
  }
  return;
}


