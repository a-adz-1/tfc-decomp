// RotMove__12CFuncPlatRotR6Vectorf  @ 000d1f90
void RotMove__12CFuncPlatRotR6Vectorf(int *param_1,float *param_2,float param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  iVar1 = *param_1;
  fVar4 = *param_2 - *(float *)(iVar1 + 0x50);
  fVar3 = param_2[1] - *(float *)(iVar1 + 0x54);
  fVar2 = param_2[2] - *(float *)(iVar1 + 0x58);
  if ((byte)((0.1 < param_3 | (byte)((ushort)((ushort)NAN(param_3) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_3 == 0.1) << 0xe) >> 8)) - 1) < 0x40) {
    *(float *)(iVar1 + 0x5c) = fVar4 / param_3;
    *(float *)(iVar1 + 0x60) = fVar3 / param_3;
    *(float *)(iVar1 + 100) = fVar2 / param_3;
  }
  else {
    iVar1 = *param_1;
    *(float *)(iVar1 + 0x5c) = fVar4;
    *(float *)(iVar1 + 0x60) = fVar3;
    *(float *)(iVar1 + 100) = fVar2;
    *(float *)(*param_1 + 0xe4) = *(float *)(*param_1 + 0xe0) + 1.0;
  }
  return;
}


