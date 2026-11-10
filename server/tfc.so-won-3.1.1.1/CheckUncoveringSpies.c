// CheckUncoveringSpies__11CBasePlayerP11CBasePlayer  @ 000e3918
void CheckUncoveringSpies__11CBasePlayerP11CBasePlayer(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  if ((*(int *)(*param_1 + 0x20c) == 8) || (*(int *)(*param_1 + 0x20c) == 1)) {
    iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,param_2);
    if ((iVar1 == 0) && ((param_2[0x75] != 0 || (param_2[0x76] != 0)))) {
      iVar1 = param_1[0x4b] + 1;
      param_1[0x4b] = iVar1;
      if (param_1[0x48] == 0) {
        iVar2 = *param_1;
      }
      else {
        (&teamfrags)[param_1[0x48]] = (&teamfrags)[param_1[0x48]] + 1;
        iVar2 = *param_1;
        iVar1 = param_1[0x4b];
      }
      *(float *)(iVar2 + 0x164) = (float)iVar1;
      Spy_RemoveDisguise__11CBasePlayer(param_2);
      UTIL_ClientPrintAll__FiPCcN41
                (1,"#Spy_uncovered",*(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),0,0,0);
      if (param_2[0x48] == 0) {
        pcVar3 = "SPECTATOR";
      }
      else {
        pcVar3 = (char *)GetTeamName__Fi(param_2[0x48]);
      }
      uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
      uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar4);
      if (param_1[0x48] == 0) {
        pcVar3 = "SPECTATOR";
      }
      else {
        pcVar3 = (char *)GetTeamName__Fi(param_1[0x48],
                                         *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98),
                                         uVar4);
      }
      uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_1 + 0x208),pcVar3);
      uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_1 + 0x208),uVar4);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%s><%s>\" triggered \"Discovered_Spy\" against \"%s<%i><%s><%s>\"\n",
                 *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar4);
    }
  }
  return;
}


