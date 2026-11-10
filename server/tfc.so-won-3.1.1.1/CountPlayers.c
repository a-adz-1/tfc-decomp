// CountPlayers__Fv  @ 000af574
int CountPlayers__Fv(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(gpGlobals + 0x90)) {
    iVar2 = 1;
    do {
      iVar1 = UTIL_PlayerByIndex__Fi(iVar2);
      if (iVar1 != 0) {
        iVar3 = iVar3 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= *(int *)(gpGlobals + 0x90));
  }
  return iVar3;
}


