// Nearest__10CPathTrackG6Vector  @ 000cce84
int * Nearest__10CPathTrackG6Vector(int *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  float local_1c;
  
  fVar1 = *param_2 - *(float *)(*param_1 + 8);
  fVar2 = param_2[1] - *(float *)(*param_1 + 0xc);
  local_1c = SQRT(fVar2 * fVar2 + fVar1 * fVar1);
  piVar3 = (int *)GetNext__10CPathTrack(param_1);
  iVar4 = 0;
  piVar5 = param_1;
  while( true ) {
    if (piVar3 == (int *)0x0) {
      return piVar5;
    }
    if (piVar3 == param_1) break;
    iVar4 = iVar4 + 1;
    if (9999 < iVar4) {
      (*DAT_001c1114)(4,"Bad sequence of path_tracks from %s",
                      *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98));
      return (int *)0x0;
    }
    fVar1 = *param_2 - *(float *)(*piVar3 + 8);
    fVar2 = param_2[1] - *(float *)(*piVar3 + 0xc);
    fVar1 = SQRT(fVar2 * fVar2 + fVar1 * fVar1);
    if (fVar1 < local_1c) {
      piVar5 = piVar3;
      local_1c = fVar1;
    }
    piVar3 = (int *)GetNext__10CPathTrack(piVar3);
  }
  return piVar5;
}


