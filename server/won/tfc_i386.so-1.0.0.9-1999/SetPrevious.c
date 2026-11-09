// SetPrevious__10CPathTrackP10CPathTrack  @ 000d06b0
void SetPrevious__10CPathTrackP10CPathTrack(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 != (int *)0x0) {
    iVar1 = strcmp((char *)(*(int *)(*param_2 + 0x1ac) + *(int *)(gpGlobals + 0x98)),
                   (char *)(*(int *)(gpGlobals + 0x98) + *(int *)(param_1 + 0x3d0)));
    if (iVar1 != 0) {
      *(int **)(param_1 + 0x3d8) = param_2;
    }
  }
  return;
}


