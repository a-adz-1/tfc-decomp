// HasTarget__11CBaseEntityi  @ 00100558
bool HasTarget__11CBaseEntityi(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = strcmp((char *)(param_2 + *(int *)(gpGlobals + 0x98)),
                 (char *)(*(int *)(gpGlobals + 0x98) + *(int *)(*param_1 + 0x1cc)));
  return iVar1 == 0;
}


// HasTarget__13CMultiManageri  @ 00101e44
undefined4 HasTarget__13CMultiManageri(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x478)) {
    do {
      iVar1 = strcmp((char *)(param_2 + *(int *)(gpGlobals + 0x98)),
                     (char *)(*(int *)(gpGlobals + 0x98) + *(int *)(param_1 + 0x484 + iVar2 * 4)));
      if (iVar1 == 0) {
        return 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x478));
  }
  return 0;
}


