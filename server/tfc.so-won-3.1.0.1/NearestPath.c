// NearestPath__15CFuncTrackTrain  @ 000c5518
void NearestPath__15CFuncTrackTrain(int *param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int *local_3c;
  float local_24;
  
  local_3c = (int *)0x0;
  local_24 = 1024.0;
  piVar8 = (int *)0x0;
  while (local_3c = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                     (local_3c,*param_1 + 8,0x44800000), local_3c != (int *)0x0) {
    if (((*(byte *)((int *)*local_3c + 0x69) & 0x28) == 0) &&
       (iVar6 = strcmp((char *)(*(int *)*local_3c + *(int *)(gpGlobals + 0x98)),"path_track"),
       iVar6 == 0)) {
      iVar6 = *param_1;
      iVar2 = *local_3c;
      fVar1 = *(float *)(iVar6 + 8) - *(float *)(iVar2 + 8);
      fVar4 = *(float *)(iVar6 + 0xc) - *(float *)(iVar2 + 0xc);
      fVar3 = *(float *)(iVar6 + 0x10) - *(float *)(iVar2 + 0x10);
      fVar1 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar1 * fVar1);
      if (fVar1 < local_24) {
        piVar8 = local_3c;
        local_24 = fVar1;
      }
    }
  }
  if (piVar8 == (int *)0x0) {
    (*DAT_001a7f34)(1,"Can\'t find a nearby track !!!\n");
    param_1[3] = 0;
    param_1[4] = 0;
  }
  else {
    (*DAT_001a7f34)(2,"TRAIN: %s, Nearest track is %s\n",
                    *(int *)(*param_1 + 0x1cc) + *(int *)(gpGlobals + 0x98),
                    *(int *)(*piVar8 + 0x1cc) + *(int *)(gpGlobals + 0x98));
    piVar7 = (int *)GetNext__10CPathTrack(piVar8);
    if (piVar7 != (int *)0x0) {
      iVar6 = *param_1;
      iVar2 = *piVar7;
      fVar1 = *(float *)(iVar6 + 8) - *(float *)(iVar2 + 8);
      fVar4 = *(float *)(iVar6 + 0xc) - *(float *)(iVar2 + 0xc);
      fVar3 = *(float *)(iVar6 + 0x10) - *(float *)(iVar2 + 0x10);
      fVar1 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar1 * fVar1);
      fVar3 = *(float *)(iVar6 + 8) - *(float *)(*piVar8 + 8);
      fVar5 = *(float *)(iVar6 + 0xc) - *(float *)(*piVar8 + 0xc);
      fVar4 = *(float *)(iVar6 + 0x10) - *(float *)(*piVar8 + 0x10);
      fVar3 = SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar3 * fVar3);
      if (0x3f < (byte)((fVar3 < fVar1 |
                         (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) - 1)) {
        piVar8 = piVar7;
      }
    }
    param_1[0xf6] = (int)piVar8;
    fVar1 = *(float *)(*param_1 + 0x1f8);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      NextThink__15CFuncTrackTrainfi(param_1,*(float *)(*param_1 + 0x100) + 0.1,0);
      param_1[3] = -0x10000;
      param_1[4] = (int)Next__15CFuncTrackTrain;
    }
  }
  return;
}


