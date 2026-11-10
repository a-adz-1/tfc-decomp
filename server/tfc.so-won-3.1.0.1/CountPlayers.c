// CountPlayers__Fv  @ 000a558c
int CountPlayers__Fv(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  for (iVar2 = 1; iVar2 <= *(int *)(gpGlobals + 0x90); iVar2 = iVar2 + 1) {
    iVar1 = UTIL_PlayerByIndex__Fi(iVar2);
    if (iVar1 != 0) {
      iVar3 = iVar3 + 1;
    }
  }
  return iVar3;
}


