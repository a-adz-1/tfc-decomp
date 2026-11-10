// GetPrevious__10CPathTrack  @ 000ccb2c
int GetPrevious__10CPathTrack(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x11a];
  if ((iVar1 == 0) || ((*(uint *)(*param_1 + 0x1a0) & 0x8004) != 0x8004)) {
    iVar1 = param_1[0x119];
  }
  return iVar1;
}


