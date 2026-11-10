// RelinkBeam__5CBeam  @ 0009f6fc
void RelinkBeam__5CBeam(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  float *pfVar6;
  
  iVar3 = *param_1;
  if ((*(uint *)(iVar3 + 0x148) & 0xf) == 2) {
    iVar3 = (*DAT_0019f7c0)(*(uint *)(iVar3 + 0x128) & 0xfff);
    pfVar6 = (float *)(iVar3 + 0x88);
    iVar3 = *param_1;
  }
  else {
    pfVar6 = (float *)(iVar3 + 8);
  }
  uVar4 = *(uint *)(iVar3 + 0x148) & 0xf;
  if ((uVar4 != 0) && (uVar4 != 3)) {
    iVar3 = (*DAT_0019f7c0)(*(uint *)(iVar3 + 0x110) & 0xfff);
    if (iVar3 != 0) {
      pfVar5 = (float *)(iVar3 + 0x88);
      iVar3 = *param_1;
      goto LAB_0009f795;
    }
    iVar3 = *param_1;
  }
  pfVar5 = (float *)(iVar3 + 0x50);
LAB_0009f795:
  fVar1 = *pfVar5;
  if (*pfVar6 < fVar1) {
    fVar1 = *pfVar6;
  }
  *(float *)(iVar3 + 0xdc) = fVar1;
  fVar1 = pfVar5[1];
  if (pfVar6[1] < fVar1) {
    fVar1 = pfVar6[1];
  }
  *(float *)(*param_1 + 0xe0) = fVar1;
  fVar1 = pfVar5[2];
  if (pfVar6[2] < fVar1) {
    fVar1 = pfVar6[2];
  }
  *(float *)(*param_1 + 0xe4) = fVar1;
  fVar1 = *pfVar5;
  fVar2 = *pfVar6;
  if (0x3f < (byte)((fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
    fVar1 = fVar2;
  }
  *(float *)(*param_1 + 0xe8) = fVar1;
  fVar1 = pfVar5[1];
  fVar2 = pfVar6[1];
  if (0x3f < (byte)((fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
    fVar1 = fVar2;
  }
  *(float *)(*param_1 + 0xec) = fVar1;
  fVar1 = pfVar5[2];
  fVar2 = pfVar6[2];
  if (0x3f < (byte)((fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
    fVar1 = fVar2;
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


