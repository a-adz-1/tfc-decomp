// GetNext__10CPathTrack  @ 000d0630
int GetNext__10CPathTrack(int *param_1)

{
  int iVar1;
  
  if ((param_1[0xf7] == 0) || ((*(uint *)(*param_1 + 0x180) & 0x8004) != 0x8000)) {
    iVar1 = param_1[0xf5];
  }
  else {
    iVar1 = param_1[0xf7];
  }
  return iVar1;
}


