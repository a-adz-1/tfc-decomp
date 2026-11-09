// NearestPath__15CFuncTrackTrain  @ 000d3e90
void NearestPath__15CFuncTrackTrain(int *param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int *piVar9;
  int *local_40;
  float local_28;
  
  piVar9 = (int *)0x0;
  local_40 = (int *)0x0;
  local_28 = 1024.0;
  while (piVar9 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                   (piVar9,*param_1 + 8,0x44800000), piVar9 != (int *)0x0) {
    if (((*(byte *)((int *)*piVar9 + 0x61) & 0x28) == 0) &&
       (iVar8 = strcmp((char *)(*(int *)*piVar9 + *(int *)(gpGlobals + 0x98)),"path_track"),
       iVar8 == 0)) {
      iVar8 = *param_1;
      fVar1 = *(float *)(iVar8 + 8) - *(float *)(*piVar9 + 8);
      fVar4 = *(float *)(iVar8 + 0xc) - *(float *)(*piVar9 + 0xc);
      fVar3 = *(float *)(iVar8 + 0x10) - *(float *)(*piVar9 + 0x10);
      fVar1 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar1 * fVar1);
      if ((byte)(fVar1 < local_28 |
                 (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_28)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == local_28) << 0xe) >> 8)) == 1) {
        local_40 = piVar9;
        local_28 = fVar1;
      }
    }
  }
  if (local_40 == (int *)0x0) {
    (*DAT_001755b4)(1,"Can\'t find a nearby track !!!\n");
    param_1[3] = 0;
    param_1[4] = 0;
  }
  else {
    (*DAT_001755b4)(2,"TRAIN: %s, Nearest track is %s\n",
                    *(int *)(*param_1 + 0x1ac) + *(int *)(gpGlobals + 0x98),
                    *(int *)(*local_40 + 0x1ac) + *(int *)(gpGlobals + 0x98));
    piVar9 = (int *)GetNext__10CPathTrack(local_40);
    if (piVar9 != (int *)0x0) {
      iVar8 = *param_1;
      fVar1 = *(float *)(iVar8 + 8) - *(float *)(*piVar9 + 8);
      fVar4 = *(float *)(iVar8 + 0xc) - *(float *)(*piVar9 + 0xc);
      fVar3 = *(float *)(iVar8 + 0x10) - *(float *)(*piVar9 + 0x10);
      iVar2 = *local_40;
      fVar5 = *(float *)(iVar8 + 8) - *(float *)(iVar2 + 8);
      fVar7 = *(float *)(iVar8 + 0xc) - *(float *)(iVar2 + 0xc);
      fVar6 = *(float *)(iVar8 + 0x10) - *(float *)(iVar2 + 0x10);
      if (SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar1 * fVar1) <
          SQRT(fVar6 * fVar6 + fVar7 * fVar7 + fVar5 * fVar5)) {
        local_40 = piVar9;
      }
    }
    param_1[0xf3] = (int)local_40;
    fVar1 = *(float *)(*param_1 + 0x1d8);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      NextThink__15CFuncTrackTrainfi(param_1,*(float *)(*param_1 + 0xe0) + 0.1,0);
      param_1[3] = -0x10000;
      param_1[4] = (int)Next__15CFuncTrackTrain;
    }
  }
  return;
}


