// MaxPlayers_f  @ 00090964
void MaxPlayers_f(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    if (sv == 0) {
      uVar2 = Cmd_Argv(1);
      iVar3 = Q_atoi(uVar2);
      iVar1 = DAT_001ab4ec;
      if (iVar3 < 1) {
        iVar3 = 1;
      }
      if (DAT_001ab4ec < iVar3) {
        Con_Printf("\"maxplayers\" set to \"%u\"\n",DAT_001ab4ec);
        iVar3 = iVar1;
      }
      if (iVar3 == 1) {
        puVar4 = &DAT_000adf1a;
      }
      else {
        puVar4 = &DAT_000adf99;
      }
      DAT_001ab4e8 = iVar3;
      Cvar_Set("deathmatch",puVar4);
    }
    else {
      Con_Printf("maxplayers cannot be changed while a server is running.\n");
    }
  }
  else {
    Con_Printf("\"maxplayers\" is \"%u\"\n",DAT_001ab4e8);
  }
  return;
}


