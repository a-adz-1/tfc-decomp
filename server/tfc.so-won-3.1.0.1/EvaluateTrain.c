// EvaluateTrain__16CFuncTrackChangeP10CPathTrack  @ 000c6434
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 EvaluateTrain__16CFuncTrackChangeP10CPathTrack(int *param_1,int param_2)

{
  float fVar1;
  int *piVar2;
  float fVar3;
  undefined4 uVar4;
  
  if (((param_2 == 0) || (param_1[0x128] == 0)) ||
     (((*(int *)(param_1[0x128] + 0x3d8) != param_2 &&
       ((*(int *)(param_2 + 0x3e4) == 0 ||
        (*(int *)(param_1[0x128] + 0x3d8) != *(int *)(param_2 + 0x3e4))))) &&
      ((*(int *)(param_2 + 0x3e0) == 0 ||
       (*(int *)(param_1[0x128] + 0x3d8) != *(int *)(param_2 + 0x3e0))))))) {
LAB_000c6557:
    uVar4 = 0;
  }
  else {
    fVar1 = *(float *)(*(int *)param_1[0x128] + 0x1f8);
    if ((byte)(_FUN_00139ed4 < fVar1 |
               (byte)((ushort)((ushort)(NAN(_FUN_00139ed4) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(_FUN_00139ed4 == fVar1) << 0xe) >> 8)) == 0x40) {
      piVar2 = (int *)param_1[0x128];
      fVar1 = *(float *)(*param_1 + 8) - *(float *)(*piVar2 + 8);
      fVar3 = *(float *)(*param_1 + 0xc) - *(float *)(*piVar2 + 0xc);
      fVar1 = SQRT(fVar3 * fVar3 + fVar1 * fVar1);
      if (fVar1 < (float)piVar2[0xf7]) {
        return 2;
      }
      if (*(float *)(param_1[0x128] + 0x3dc) + 150.0 < fVar1) goto LAB_000c6557;
    }
    uVar4 = 1;
  }
  return uVar4;
}


