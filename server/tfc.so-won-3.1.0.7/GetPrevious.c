// GetPrevious__10CPathTrack  @ 000cca3c
int GetPrevious__10CPathTrack(int *param_1)

{
  int iVar1;
  
  if ((param_1[0x116] == 0) || ((*(uint *)(*param_1 + 0x1a0) & 0x8004) != 0x8004)) {
    iVar1 = param_1[0x115];
  }
  else {
    iVar1 = param_1[0x116];
  }
  return iVar1;
}


