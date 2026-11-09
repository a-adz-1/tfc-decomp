// CL_CameraOffset  @ 27025fe0
void __cdecl CL_CameraOffset(undefined4 *param_1)

{
                    /* 0x25fe0  472  CL_CameraOffset */
  *param_1 = DAT_270b56f4;
  param_1[1] = DAT_270b56f8;
  param_1[2] = DAT_270b56fc;
  return;
}


// CL_CreateMove  @ 270269e0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl CL_CreateMove(float param_1,undefined4 *param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  bool bVar3;
  char cVar4;
  undefined3 extraout_var;
  uint uVar5;
  undefined *puVar6;
  int iVar7;
  undefined4 *puVar8;
  float10 fVar9;
  float local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
                    /* 0x269e0  473  CL_CreateMove */
  if ((DAT_270b577c & 1) == 0) {
    DAT_270b577c = DAT_270b577c | 1;
    FUN_27046dec(&DAT_27026cf0);
  }
  if ((param_3 != 0) && (bVar3 = FUN_270221a0(), CONCAT31(extraout_var,bVar3) == 0)) {
    (*DAT_270a8250)(&local_c);
    FUN_27026840(param_1,&local_c);
    puVar8 = param_2;
    for (iVar7 = 0xd; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    (*DAT_270a8254)(&local_c);
    if ((DAT_270b5878 & 1) != 0) {
      fVar9 = FUN_270267c0(0x270b5820);
      param_2[5] = (float)(fVar9 * (float10)*(float *)(DAT_270b5888 + 0xc) +
                          (float10)(float)param_2[5]);
      fVar9 = FUN_270267c0(0x270b5814);
      param_2[5] = (float)((float10)(float)param_2[5] -
                          fVar9 * (float10)*(float *)(DAT_270b5888 + 0xc));
    }
    fVar9 = FUN_270267c0(0x270b587c);
    param_2[5] = (float)(fVar9 * (float10)*(float *)(DAT_270b5888 + 0xc) +
                        (float10)(float)param_2[5]);
    fVar9 = FUN_270267c0(0x270b583c);
    param_2[5] = (float)((float10)(float)param_2[5] -
                        fVar9 * (float10)*(float *)(DAT_270b5888 + 0xc));
    fVar9 = FUN_270267c0(0x270b57a0);
    param_2[6] = (float)(fVar9 * (float10)*(float *)(DAT_270b58c0 + 0xc) +
                        (float10)(float)param_2[6]);
    fVar9 = FUN_270267c0(0x270b57c0);
    param_2[6] = (float)((float10)(float)param_2[6] -
                        fVar9 * (float10)*(float *)(DAT_270b58c0 + 0xc));
    if ((DAT_270b58d4 & 1) == 0) {
      fVar9 = FUN_270267c0(0x270b5804);
      param_2[4] = (float)(fVar9 * (float10)*(float *)(DAT_270b57bc + 0xc) +
                          (float10)(float)param_2[4]);
      fVar9 = FUN_270267c0(0x270b5898);
      param_2[4] = (float)((float10)(float)param_2[4] -
                          fVar9 * (float10)*(float *)(DAT_270b58b0 + 0xc));
    }
    if ((DAT_270b578c & 1) != 0) {
      param_2[4] = *(float *)(DAT_270b5790 + 0xc) * (float)param_2[4];
      param_2[5] = *(float *)(DAT_270b5790 + 0xc) * (float)param_2[5];
      param_2[6] = *(float *)(DAT_270b5790 + 0xc) * (float)param_2[6];
    }
    fVar9 = (float10)(*DAT_270a8280)();
    if ((fVar9 != (float10)0.0) &&
       (fVar2 = SQRT((float)param_2[5] * (float)param_2[5] +
                     (float)param_2[6] * (float)param_2[6] + (float)param_2[4] * (float)param_2[4]),
       (float)fVar9 < fVar2)) {
      fVar2 = (float)fVar9 / fVar2;
      param_2[4] = fVar2 * (float)param_2[4];
      param_2[5] = fVar2 * (float)param_2[5];
      param_2[6] = fVar2 * (float)param_2[6];
    }
    FUN_27028320(param_1,(int)param_2);
  }
  *(undefined1 *)(param_2 + 8) = DAT_270b58d8;
  _DAT_270b58d8 = 0;
  *(undefined1 *)((int)param_2 + 0x21) = DAT_270a6518;
  _DAT_270a6518 = 0;
  uVar5 = FUN_27026d10(1);
  *(short *)((int)param_2 + 0x1e) = (short)uVar5;
  puVar6 = FUN_27019c20();
  cVar4 = FUN_2701aea0((int)puVar6);
  if (cVar4 != '\0') {
    *(byte *)((int)param_2 + 0x1e) = *(byte *)((int)param_2 + 0x1e) & 0xfe;
  }
  if (*(float *)(DAT_270b5934 + 0xc) != 0.0) {
    if ((float)param_2[4] <= 0.0) {
      if ((float)param_2[4] < 0.0) {
        *(byte *)((int)param_2 + 0x1e) = *(byte *)((int)param_2 + 0x1e) | 0x10;
      }
    }
    else {
      *(byte *)((int)param_2 + 0x1e) = *(byte *)((int)param_2 + 0x1e) | 8;
    }
  }
  (*DAT_270a8250)(&local_c);
  pfVar1 = (float *)(param_2 + 1);
  if (DAT_27076390 == 0) {
    *pfVar1 = DAT_270b58a4;
    param_2[2] = DAT_270b58a8;
    param_2[3] = DAT_270b58ac;
    FUN_27023980(1,pfVar1,param_1,(int)param_2);
    return;
  }
  *pfVar1 = local_c;
  param_2[2] = uStack_8;
  param_2[3] = uStack_4;
  DAT_270b58a4 = local_c;
  DAT_270b58a8 = uStack_8;
  DAT_270b58ac = uStack_4;
  FUN_27023980(1,pfVar1,param_1,(int)param_2);
  return;
}


// CL_IsThirdPerson  @ 27025fb0
undefined4 CL_IsThirdPerson(void)

{
  int *piVar1;
  
                    /* 0x25fb0  474  CL_IsThirdPerson */
  if (DAT_270b5750 != 0) {
    return 1;
  }
  if ((DAT_270c28a8 != 0) && (piVar1 = (int *)(*DAT_270a8294)(), DAT_270c28b0 == *piVar1)) {
    return 1;
  }
  return 0;
}


