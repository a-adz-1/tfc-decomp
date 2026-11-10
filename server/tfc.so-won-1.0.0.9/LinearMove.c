// LinearMove__11CBaseToggleG6Vectorf  @ 000f0bc0
void LinearMove__11CBaseToggleG6Vectorf(int *param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  bool bVar5;
  
  param_1[0x113] = (int)*param_2;
  param_1[0x114] = (int)param_2[1];
  param_1[0x115] = (int)param_2[2];
  bVar5 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(*param_1 + 8)) || NAN(*param_2)) << 10) >> 8)
             | (byte)((ushort)((ushort)(*(float *)(*param_1 + 8) == *param_2) << 0xe) >> 8)) == 0x40
      ) && (fVar1 = *(float *)(*param_1 + 0xc),
           (byte)((byte)((ushort)((ushort)(NAN(fVar1) || NAN(param_2[1])) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == param_2[1]) << 0xe) >> 8)) == 0x40)) {
    fVar1 = param_2[2];
    fVar2 = *(float *)(*param_1 + 0x10);
    bVar5 = (byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (bVar5) {
    LinearMoveDone__11CBaseToggle(param_1);
  }
  else {
    iVar3 = *param_1;
    fVar1 = *param_2 - *(float *)(iVar3 + 8);
    fVar4 = param_2[1] - *(float *)(iVar3 + 0xc);
    fVar2 = param_2[2] - *(float *)(iVar3 + 0x10);
    param_3 = SQRT(fVar2 * fVar2 + fVar4 * fVar4 + fVar1 * fVar1) / param_3;
    *(float *)(iVar3 + 0xe4) = param_3 + *(float *)(iVar3 + 0xe0);
    param_1[3] = -0x10000;
    param_1[4] = (int)LinearMoveDone__11CBaseToggle;
    iVar3 = *param_1;
    *(float *)(iVar3 + 0x20) = fVar1 / param_3;
    *(float *)(iVar3 + 0x24) = fVar4 / param_3;
    *(float *)(iVar3 + 0x28) = fVar2 / param_3;
  }
  return;
}


