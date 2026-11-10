// Nearest__10CPathTrackG6Vector  @ 000cc8cc
int * Nearest__10CPathTrackG6Vector(int *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *local_20;
  
  iVar6 = *param_1;
  fVar1 = *param_2 - *(float *)(iVar6 + 8);
  fVar2 = param_2[1] - *(float *)(iVar6 + 0xc);
  fVar1 = SQRT(fVar2 * fVar2 + fVar1 * fVar1);
  local_20 = param_1;
  piVar4 = (int *)param_1[0x11a];
  if ((piVar4 == (int *)0x0) || ((*(uint *)(iVar6 + 0x1a0) & 0x8004) != 0x8000)) {
    piVar4 = (int *)param_1[0x118];
  }
  iVar6 = 0;
  while( true ) {
    piVar5 = piVar4;
    if (piVar5 == (int *)0x0) {
      return local_20;
    }
    if (piVar5 == param_1) break;
    iVar6 = iVar6 + 1;
    if (9999 < iVar6) {
      (*DAT_0019f794)(4,"Bad sequence of path_tracks from %s",
                      *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98));
      return (int *)0x0;
    }
    fVar2 = *param_2 - *(float *)(*piVar5 + 8);
    fVar3 = param_2[1] - *(float *)(*piVar5 + 0xc);
    fVar2 = SQRT(fVar3 * fVar3 + fVar2 * fVar2);
    if (fVar2 < fVar1) {
      fVar1 = fVar2;
      local_20 = piVar5;
    }
    if (((int *)piVar5[0x11a] == (int *)0x0) ||
       (piVar4 = (int *)piVar5[0x11a], (*(uint *)(*piVar5 + 0x1a0) & 0x8004) != 0x8000)) {
      piVar4 = (int *)piVar5[0x118];
    }
  }
  return local_20;
}


