// CheckUncoveringSpies__11CBasePlayerP11CBasePlayer  @ 000e42d8
void CheckUncoveringSpies__11CBasePlayerP11CBasePlayer(int *param_1,int *param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if ((*(int *)(*param_1 + 0x20c) == 8) || (*(int *)(*param_1 + 0x20c) == 1)) {
    iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,param_2);
    if ((iVar1 == 0) && ((param_2[0x75] != 0 || (param_2[0x76] != 0)))) {
      TF_AddFrags__11CBasePlayeri(param_1,1);
      Spy_RemoveDisguise__11CBasePlayer(param_2);
      UTIL_ClientPrintAll__FiPCcN41
                (1,"#Spy_uncovered",*(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),0,0,0);
      if (param_2[0x48] == 0) {
        pcVar2 = "SPECTATOR";
      }
      else {
        pcVar2 = (char *)GetTeamName__Fi(param_2[0x48]);
      }
      uVar3 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar2);
      uVar3 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar3);
      if (param_1[0x48] == 0) {
        pcVar2 = "SPECTATOR";
      }
      else {
        pcVar2 = (char *)GetTeamName__Fi(param_1[0x48],
                                         *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98),
                                         uVar3);
      }
      uVar3 = (*DAT_001c11f4)(*(undefined4 *)(*param_1 + 0x208),pcVar2);
      uVar3 = (*DAT_001c11e4)(*(undefined4 *)(*param_1 + 0x208),uVar3);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%u><%s>\" triggered \"Discovered_Spy\" against \"%s<%i><%u><%s>\"\n",
                 *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar3);
    }
  }
  return;
}


