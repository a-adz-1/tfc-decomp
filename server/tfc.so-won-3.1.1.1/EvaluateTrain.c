// EvaluateTrain__16CFuncTrackChangeP10CPathTrack  @ 000d0948
undefined4 EvaluateTrain__16CFuncTrackChangeP10CPathTrack(int *param_1,int param_2)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  float fVar4;
  undefined4 uVar5;
  
  if (((param_2 == 0) || (piVar2 = (int *)param_1[0x148], piVar2 == (int *)0x0)) ||
     (((iVar3 = piVar2[0x116], iVar3 != param_2 &&
       ((*(int *)(param_2 + 0x464) == 0 || (iVar3 != *(int *)(param_2 + 0x464))))) &&
      ((*(int *)(param_2 + 0x460) == 0 || (iVar3 != *(int *)(param_2 + 0x460))))))) {
LAB_000d0a39:
    uVar5 = 0;
  }
  else {
    iVar3 = *piVar2;
    fVar1 = *(float *)(iVar3 + 0x1f8);
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      fVar1 = *(float *)(*param_1 + 8) - *(float *)(iVar3 + 8);
      fVar4 = *(float *)(*param_1 + 0xc) - *(float *)(iVar3 + 0xc);
      fVar4 = SQRT(fVar4 * fVar4 + fVar1 * fVar1);
      fVar1 = (float)piVar2[0x117];
      if (0x3f < (byte)((fVar1 < fVar4 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar4)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar4) << 0xe) >> 8)) - 1)) {
        return 2;
      }
      if (fVar1 + 150.0 < fVar4) goto LAB_000d0a39;
    }
    uVar5 = 1;
  }
  return uVar5;
}


