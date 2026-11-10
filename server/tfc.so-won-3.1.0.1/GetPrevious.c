// GetPrevious__10CPathTrack  @ 000c171c
int GetPrevious__10CPathTrack(int *param_1)

{
  int iVar1;
  
  if ((param_1[0xfa] == 0) || ((*(uint *)(*param_1 + 0x1a0) & 0x8004) != 0x8004)) {
    iVar1 = param_1[0xf9];
  }
  else {
    iVar1 = param_1[0xfa];
  }
  return iVar1;
}


