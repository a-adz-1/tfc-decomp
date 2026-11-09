// FindGhost__Fi  @ 000f44a0
int FindGhost__Fi(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    iVar1 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar1,"ghost");
    if (iVar1 == 0) {
      return 0;
    }
  } while (*(int *)(iVar1 + 500) != param_1);
  return iVar1;
}


