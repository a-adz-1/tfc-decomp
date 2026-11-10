// GetNext__10CPathTrack  @ 000c16e8
int GetNext__10CPathTrack(int *param_1)

{
  int iVar1;
  
  if ((param_1[0xfa] == 0) || ((*(uint *)(*param_1 + 0x1a0) & 0x8004) != 0x8000)) {
    iVar1 = param_1[0xf8];
  }
  else {
    iVar1 = param_1[0xfa];
  }
  return iVar1;
}


