// CheckUncoveringSpies__11CBasePlayerP11CBasePlayer  @ 000d8450
void CheckUncoveringSpies__11CBasePlayerP11CBasePlayer(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(*param_1 + 0x20c) == 8) || (*(int *)(*param_1 + 0x20c) == 1)) {
    iVar1 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,param_2);
    if ((iVar1 == 0) && ((param_2[0x75] != 0 || (param_2[0x76] != 0)))) {
      TF_AddFrags__11CBasePlayeri(param_1,1);
      Spy_RemoveDisguise__11CBasePlayer(param_2);
      UTIL_ClientPrintAll__FiPCcN41
                (1,"#Spy_uncovered",*(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),0,0,0);
      uVar2 = (*DAT_001a8004)(*(undefined4 *)(*param_2 + 0x208));
      uVar2 = (*DAT_001a8004)(*(undefined4 *)(*param_1 + 0x208),
                              *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar2);
      UTIL_LogPrintf__FPce
                ("\"%s<%i>\" uncovered \"%s<%i>\".\n",
                 *(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar2);
    }
  }
  return;
}


