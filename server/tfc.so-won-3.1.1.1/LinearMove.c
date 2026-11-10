// LinearMove__11CBaseToggleG6Vectorf  @ 000f604c
void LinearMove__11CBaseToggleG6Vectorf(int *param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  bool bVar5;
  
  bVar5 = false;
  param_1[0x136] = (int)*param_2;
  param_1[0x137] = (int)param_2[1];
  param_1[0x138] = (int)param_2[2];
  iVar4 = *param_1;
  fVar1 = *param_2;
  if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar4 + 8)) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(iVar4 + 8) == fVar1) << 0xe) >> 8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar4 + 0xc)) || NAN(param_2[1])) << 10) >> 8)
            | (byte)((ushort)((ushort)(*(float *)(iVar4 + 0xc) == param_2[1]) << 0xe) >> 8)) == 0x40
     )) {
    fVar2 = param_2[2];
    fVar3 = *(float *)(iVar4 + 0x10);
    bVar5 = (byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) == 0x40;
  }
  if (bVar5) {
    LinearMoveDone__11CBaseToggle(param_1);
  }
  else {
    fVar1 = fVar1 - *(float *)(iVar4 + 8);
    fVar3 = param_2[1] - *(float *)(iVar4 + 0xc);
    fVar2 = param_2[2] - *(float *)(iVar4 + 0x10);
    param_3 = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1) / param_3;
    *(float *)(iVar4 + 0x104) = *(float *)(iVar4 + 0x100) + param_3;
    param_1[3] = -0x10000;
    param_1[4] = (int)LinearMoveDone__11CBaseToggle;
    iVar4 = *param_1;
    *(float *)(iVar4 + 0x20) = fVar1 / param_3;
    *(float *)(iVar4 + 0x24) = fVar3 / param_3;
    *(float *)(iVar4 + 0x28) = fVar2 / param_3;
  }
  return;
}


