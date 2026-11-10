// EvaluateTrain__16CFuncTrackChangeP10CPathTrack  @ 000d1794
undefined4 EvaluateTrain__16CFuncTrackChangeP10CPathTrack(int *param_1,int param_2)

{
  float fVar1;
  int *piVar2;
  float fVar3;
  undefined4 uVar4;
  
  if (((param_2 == 0) || (param_1[0x144] == 0)) ||
     (((*(int *)(param_1[0x144] + 0x448) != param_2 &&
       ((*(int *)(param_2 + 0x454) == 0 ||
        (*(int *)(param_1[0x144] + 0x448) != *(int *)(param_2 + 0x454))))) &&
      ((*(int *)(param_2 + 0x450) == 0 ||
       (*(int *)(param_1[0x144] + 0x448) != *(int *)(param_2 + 0x450))))))) {
LAB_000d18b7:
    uVar4 = 0;
  }
  else {
    fVar1 = *(float *)(*(int *)param_1[0x144] + 0x1f8);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      piVar2 = (int *)param_1[0x144];
      fVar1 = *(float *)(*param_1 + 8) - *(float *)(*piVar2 + 8);
      fVar3 = *(float *)(*param_1 + 0xc) - *(float *)(*piVar2 + 0xc);
      fVar1 = SQRT(fVar3 * fVar3 + fVar1 * fVar1);
      if (fVar1 < (float)piVar2[0x113]) {
        return 2;
      }
      if (*(float *)(param_1[0x144] + 0x44c) + 150.0 < fVar1) goto LAB_000d18b7;
    }
    uVar4 = 1;
  }
  return uVar4;
}


