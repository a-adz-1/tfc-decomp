// SetPrevious__10CPathTrackP10CPathTrack  @ 000ccad4
void SetPrevious__10CPathTrackP10CPathTrack(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 != (int *)0x0) {
    iVar1 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + *(int *)(*param_2 + 0x1cc)),
                   (char *)(*(int *)(gpGlobals + 0x98) + *(int *)(param_1 + 0x45c)));
    if (iVar1 != 0) {
      *(int **)(param_1 + 0x464) = param_2;
    }
  }
  return;
}


