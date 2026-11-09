// Ghidra decompilation of functions from tfc/util.h
// 1 functions, ordered by original source line

// FStrEq  @ 000bc1f0  (line 203)

BOOL FStrEq(char *sz1,char *sz2)

{
  int iVar1;
  
  iVar1 = strcmp(sz1,sz2);
  return (uint)(iVar1 == 0);
}


