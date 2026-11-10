// UpdateTrain__16CFuncTrackChangeR6Vector  @ 000d0a48
void UpdateTrain__16CFuncTrackChangeR6Vector(int *param_1,float *param_2)

{
  byte *pbVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  float fVar13;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar10 = *param_1;
  fVar13 = *(float *)(iVar10 + 0x104) - *(float *)(iVar10 + 0x100);
  iVar11 = *(int *)param_1[0x148];
  *(undefined4 *)(iVar11 + 0x20) = *(undefined4 *)(iVar10 + 0x20);
  *(undefined4 *)(iVar11 + 0x24) = *(undefined4 *)(iVar10 + 0x24);
  *(undefined4 *)(iVar11 + 0x28) = *(undefined4 *)(iVar10 + 0x28);
  iVar10 = *param_1;
  iVar11 = *(int *)param_1[0x148];
  *(undefined4 *)(iVar11 + 0x5c) = *(undefined4 *)(iVar10 + 0x5c);
  *(undefined4 *)(iVar11 + 0x60) = *(undefined4 *)(iVar10 + 0x60);
  *(undefined4 *)(iVar11 + 100) = *(undefined4 *)(iVar10 + 100);
  piVar12 = (int *)param_1[0x148];
  iVar10 = *piVar12;
  pbVar1 = (byte *)(iVar10 + 0x1a6);
  *pbVar1 = *pbVar1 & 0xdf;
  *(float *)(*piVar12 + 0x104) = fVar13 + *(float *)(iVar10 + 0x100);
  if (0.0 < fVar13) {
    iVar10 = *(int *)param_1[0x148];
    local_10 = *(float *)(iVar10 + 8) - *(float *)(*param_1 + 8);
    local_c = *(float *)(iVar10 + 0xc) - *(float *)(*param_1 + 0xc);
    local_8 = *(float *)(iVar10 + 0x10) - *(float *)(*param_1 + 0x10);
    local_1c = *param_2 - *(float *)(*param_1 + 0x50);
    local_18 = param_2[1] - *(float *)(*param_1 + 0x54);
    local_14 = param_2[2] - *(float *)(*param_1 + 0x58);
    UTIL_MakeInvVectors__FRC6VectorP12globalvars_t(&local_1c,gpGlobals);
    fVar2 = *(float *)(gpGlobals + 0x40);
    fVar3 = *(float *)(gpGlobals + 0x44);
    fVar4 = *(float *)(gpGlobals + 0x48);
    fVar5 = *(float *)(gpGlobals + 0x34);
    fVar6 = *(float *)(gpGlobals + 0x38);
    fVar7 = *(float *)(gpGlobals + 0x3c);
    fVar13 = 1.0 / fVar13;
    iVar10 = *(int *)param_1[0x148];
    iVar11 = *param_1;
    fVar8 = *(float *)(iVar11 + 0x24);
    fVar9 = *(float *)(iVar11 + 0x28);
    *(float *)(iVar10 + 0x20) =
         ((local_8 * *(float *)(gpGlobals + 0x30) +
          local_c * *(float *)(gpGlobals + 0x2c) + local_10 * *(float *)(gpGlobals + 0x28)) -
         local_10) * fVar13 + *(float *)(iVar11 + 0x20);
    *(float *)(iVar10 + 0x24) =
         ((local_8 * fVar4 + local_c * fVar3 + local_10 * fVar2) - local_c) * fVar13 + fVar8;
    *(float *)(iVar10 + 0x28) =
         fVar13 * ((local_8 * fVar7 + local_c * fVar6 + local_10 * fVar5) - local_8) + fVar9;
  }
  return;
}


