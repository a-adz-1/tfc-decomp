// RelinkBeam__5CBeam  @ 00095fe0
void RelinkBeam__5CBeam(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  
  pfVar4 = (float *)GetStartPos__5CBeam(param_1);
  pfVar5 = (float *)GetEndPos__5CBeam(param_1);
  fVar1 = *pfVar5;
  fVar2 = *pfVar4;
  if (0x3f < (byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
    fVar1 = *pfVar4;
  }
  *(float *)(*param_1 + 0xdc) = fVar1;
  fVar1 = pfVar5[1];
  fVar2 = pfVar4[1];
  if (0x3f < (byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
    fVar1 = pfVar4[1];
  }
  *(float *)(*param_1 + 0xe0) = fVar1;
  fVar1 = pfVar5[2];
  fVar2 = pfVar4[2];
  if (0x3f < (byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
    fVar1 = pfVar4[2];
  }
  *(float *)(*param_1 + 0xe4) = fVar1;
  fVar1 = *pfVar5;
  if (fVar1 < *pfVar4) {
    fVar1 = *pfVar4;
  }
  *(float *)(*param_1 + 0xe8) = fVar1;
  fVar1 = pfVar5[1];
  if (fVar1 < pfVar4[1]) {
    fVar1 = pfVar4[1];
  }
  *(float *)(*param_1 + 0xec) = fVar1;
  fVar1 = pfVar5[2];
  if (fVar1 < pfVar4[2]) {
    fVar1 = pfVar4[2];
  }
  *(float *)(*param_1 + 0xf0) = fVar1;
  iVar3 = *param_1;
  *(float *)(iVar3 + 0xdc) = *(float *)(iVar3 + 0xdc) - *(float *)(iVar3 + 8);
  *(float *)(iVar3 + 0xe0) = *(float *)(iVar3 + 0xe0) - *(float *)(iVar3 + 0xc);
  *(float *)(iVar3 + 0xe4) = *(float *)(iVar3 + 0xe4) - *(float *)(iVar3 + 0x10);
  iVar3 = *param_1;
  *(float *)(iVar3 + 0xe8) = *(float *)(iVar3 + 0xe8) - *(float *)(iVar3 + 8);
  *(float *)(iVar3 + 0xec) = *(float *)(iVar3 + 0xec) - *(float *)(iVar3 + 0xc);
  *(float *)(iVar3 + 0xf0) = *(float *)(iVar3 + 0xf0) - *(float *)(iVar3 + 0x10);
  iVar3 = *param_1;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar3,iVar3 + 0xdc,iVar3 + 0xe8);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  return;
}


