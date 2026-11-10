// UpdateTrain__16CFuncTrackChangeR6Vector  @ 000c6564
void UpdateTrain__16CFuncTrackChangeR6Vector(int *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  int iVar10;
  float fVar11;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar9 = *param_1;
  fVar11 = *(float *)(iVar9 + 0x104) - *(float *)(iVar9 + 0x100);
  iVar10 = *(int *)param_1[0x128];
  *(undefined4 *)(iVar10 + 0x20) = *(undefined4 *)(iVar9 + 0x20);
  *(undefined4 *)(iVar10 + 0x24) = *(undefined4 *)(iVar9 + 0x24);
  *(undefined4 *)(iVar10 + 0x28) = *(undefined4 *)(iVar9 + 0x28);
  iVar9 = *(int *)param_1[0x128];
  iVar10 = *param_1;
  *(undefined4 *)(iVar9 + 0x5c) = *(undefined4 *)(iVar10 + 0x5c);
  *(undefined4 *)(iVar9 + 0x60) = *(undefined4 *)(iVar10 + 0x60);
  *(undefined4 *)(iVar9 + 100) = *(undefined4 *)(iVar10 + 100);
  NextThink__15CFuncTrackTrainfi
            ((int *)param_1[0x128],fVar11 + *(float *)(*(int *)param_1[0x128] + 0x100),0);
  if (0.0 < fVar11) {
    iVar9 = *(int *)param_1[0x128];
    iVar10 = *param_1;
    local_c = *(float *)(iVar9 + 8) - *(float *)(iVar10 + 8);
    local_8 = *(float *)(iVar9 + 0xc) - *(float *)(iVar10 + 0xc);
    local_4 = *(float *)(iVar9 + 0x10) - *(float *)(iVar10 + 0x10);
    local_18 = *param_2 - *(float *)(iVar10 + 0x50);
    local_14 = param_2[1] - *(float *)(iVar10 + 0x54);
    local_10 = param_2[2] - *(float *)(iVar10 + 0x58);
    UTIL_MakeInvVectors__FRC6VectorP12globalvars_t(&local_18,gpGlobals);
    fVar1 = *(float *)(gpGlobals + 0x40);
    fVar2 = *(float *)(gpGlobals + 0x44);
    fVar3 = *(float *)(gpGlobals + 0x48);
    fVar4 = *(float *)(gpGlobals + 0x34);
    fVar5 = *(float *)(gpGlobals + 0x38);
    fVar6 = *(float *)(gpGlobals + 0x3c);
    iVar9 = *(int *)param_1[0x128];
    fVar11 = 1.0 / fVar11;
    iVar10 = *param_1;
    fVar7 = *(float *)(iVar10 + 0x24);
    fVar8 = *(float *)(iVar10 + 0x28);
    *(float *)(iVar9 + 0x20) =
         *(float *)(iVar10 + 0x20) +
         fVar11 * ((local_4 * *(float *)(gpGlobals + 0x30) +
                   local_8 * *(float *)(gpGlobals + 0x2c) + local_c * *(float *)(gpGlobals + 0x28))
                  - local_c);
    *(float *)(iVar9 + 0x24) =
         fVar7 + fVar11 * ((local_4 * fVar3 + local_8 * fVar2 + local_c * fVar1) - local_8);
    *(float *)(iVar9 + 0x28) =
         fVar8 + fVar11 * ((local_4 * fVar6 + local_8 * fVar5 + local_c * fVar4) - local_4);
  }
  return;
}


