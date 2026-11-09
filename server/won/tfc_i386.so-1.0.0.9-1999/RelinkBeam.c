// RelinkBeam__5CBeam  @ 000abab0
void RelinkBeam__5CBeam(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  
  pfVar4 = (float *)GetStartPos__5CBeam(param_1);
  pfVar5 = (float *)GetEndPos__5CBeam(param_1);
  fVar1 = *pfVar4;
  fVar2 = *pfVar5;
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
    fVar1 = *pfVar5;
  }
  *(float *)(*param_1 + 0xbc) = fVar1;
  fVar1 = pfVar4[1];
  fVar2 = pfVar5[1];
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
    fVar1 = pfVar5[1];
  }
  *(float *)(*param_1 + 0xc0) = fVar1;
  fVar1 = pfVar4[2];
  fVar2 = pfVar5[2];
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
    fVar1 = pfVar5[2];
  }
  *(float *)(*param_1 + 0xc4) = fVar1;
  fVar1 = *pfVar4;
  if (fVar1 <= *pfVar5) {
    fVar1 = *pfVar5;
  }
  *(float *)(*param_1 + 200) = fVar1;
  fVar1 = pfVar4[1];
  if (fVar1 <= pfVar5[1]) {
    fVar1 = pfVar5[1];
  }
  *(float *)(*param_1 + 0xcc) = fVar1;
  fVar1 = pfVar4[2];
  if (fVar1 <= pfVar5[2]) {
    fVar1 = pfVar5[2];
  }
  *(float *)(*param_1 + 0xd0) = fVar1;
  iVar3 = *param_1;
  *(float *)(iVar3 + 0xbc) = *(float *)(iVar3 + 0xbc) - *(float *)(iVar3 + 8);
  *(float *)(iVar3 + 0xc0) = *(float *)(iVar3 + 0xc0) - *(float *)(iVar3 + 0xc);
  *(float *)(iVar3 + 0xc4) = *(float *)(iVar3 + 0xc4) - *(float *)(iVar3 + 0x10);
  iVar3 = *param_1;
  *(float *)(iVar3 + 200) = *(float *)(iVar3 + 200) - *(float *)(iVar3 + 8);
  *(float *)(iVar3 + 0xcc) = *(float *)(iVar3 + 0xcc) - *(float *)(iVar3 + 0xc);
  *(float *)(iVar3 + 0xd0) = *(float *)(iVar3 + 0xd0) - *(float *)(iVar3 + 0x10);
  iVar3 = *param_1;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar3,iVar3 + 0xbc,iVar3 + 200);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  return;
}


