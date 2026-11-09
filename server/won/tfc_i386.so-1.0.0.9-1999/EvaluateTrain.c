// EvaluateTrain__16CFuncTrackChangeP10CPathTrack  @ 000d4c10
undefined4 EvaluateTrain__16CFuncTrackChangeP10CPathTrack(int *param_1,int param_2)

{
  float fVar1;
  int *piVar2;
  float fVar3;
  undefined4 uVar4;
  
  if (((param_2 == 0) || (param_1[0x125] == 0)) ||
     (((*(int *)(param_1[0x125] + 0x3cc) != param_2 &&
       ((*(int *)(param_2 + 0x3d8) == 0 ||
        (*(int *)(param_1[0x125] + 0x3cc) != *(int *)(param_2 + 0x3d8))))) &&
      ((*(int *)(param_2 + 0x3d4) == 0 ||
       (*(int *)(param_1[0x125] + 0x3cc) != *(int *)(param_2 + 0x3d4))))))) {
LAB_000d4d32:
    uVar4 = 0;
  }
  else {
    fVar1 = *(float *)(*(int *)param_1[0x125] + 0x1d8);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      piVar2 = (int *)param_1[0x125];
      fVar1 = *(float *)(*param_1 + 8) - *(float *)(*piVar2 + 8);
      fVar3 = *(float *)(*param_1 + 0xc) - *(float *)(*piVar2 + 0xc);
      fVar3 = SQRT(fVar3 * fVar3 + fVar1 * fVar1);
      fVar1 = (float)piVar2[0xf4];
      if ((byte)(fVar3 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) == 1) {
        return 2;
      }
      fVar1 = *(float *)(param_1[0x125] + 0x3d0) + 150.0;
      if ((byte)(fVar1 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar3)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar3) << 0xe) >> 8)) == 1) goto LAB_000d4d32;
    }
    uVar4 = 1;
  }
  return uVar4;
}


