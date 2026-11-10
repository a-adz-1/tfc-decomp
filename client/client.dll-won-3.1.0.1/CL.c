// CL_CameraOffset  @ 2701cdb0
void __cdecl CL_CameraOffset(undefined4 *param_1)

{
                    /* 0x1cdb0  419  CL_CameraOffset */
  *param_1 = DAT_2707cee0;
  param_1[1] = DAT_2707cee4;
  param_1[2] = DAT_2707cee8;
  return;
}


// CL_CreateMove  @ 2701d710
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl CL_CreateMove(float param_1,undefined4 *param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  bool bVar3;
  undefined3 extraout_var;
  uint uVar4;
  ushort uVar5;
  int iVar6;
  undefined4 *puVar7;
  float10 fVar8;
  float local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
                    /* 0x1d710  420  CL_CreateMove */
  if ((DAT_2707cf8c & 1) == 0) {
    DAT_2707cf8c = DAT_2707cf8c | 1;
    FUN_27037017(0x2701da10);
  }
  if ((param_3 != 0) && (bVar3 = FUN_27018d70(), CONCAT31(extraout_var,bVar3) == 0)) {
    (*DAT_27073b28)(&local_c);
    FUN_2701d570(param_1,&local_c);
    puVar7 = param_2;
    for (iVar6 = 0xd; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    (*DAT_27073b2c)(&local_c);
    if ((DAT_2707d0b8 & 1) != 0) {
      fVar8 = FUN_2701d4f0(0x2707d050);
      param_2[5] = (float)(fVar8 * (float10)*(float *)(DAT_2707d0cc + 0xc) +
                          (float10)(float)param_2[5]);
      fVar8 = FUN_2701d4f0(0x2707d040);
      param_2[5] = (float)((float10)(float)param_2[5] -
                          fVar8 * (float10)*(float *)(DAT_2707d0cc + 0xc));
    }
    fVar8 = FUN_2701d4f0(0x2707d0c0);
    param_2[5] = (float)(fVar8 * (float10)*(float *)(DAT_2707d0cc + 0xc) +
                        (float10)(float)param_2[5]);
    fVar8 = FUN_2701d4f0(0x2707d070);
    param_2[5] = (float)((float10)(float)param_2[5] -
                        fVar8 * (float10)*(float *)(DAT_2707d0cc + 0xc));
    fVar8 = FUN_2701d4f0(0x2707cfb8);
    param_2[6] = (float)(fVar8 * (float10)*(float *)(DAT_2707d10c + 0xc) +
                        (float10)(float)param_2[6]);
    fVar8 = FUN_2701d4f0(0x2707cfe0);
    param_2[6] = (float)((float10)(float)param_2[6] -
                        fVar8 * (float10)*(float *)(DAT_2707d10c + 0xc));
    if ((DAT_2707d120 & 1) == 0) {
      fVar8 = FUN_2701d4f0(0x2707d030);
      param_2[4] = (float)(fVar8 * (float10)*(float *)(DAT_2707cfd8 + 0xc) +
                          (float10)(float)param_2[4]);
      fVar8 = FUN_2701d4f0(0x2707d0e0);
      param_2[4] = (float)((float10)(float)param_2[4] -
                          fVar8 * (float10)*(float *)(DAT_2707d0fc + 0xc));
    }
    if ((DAT_2707cfa0 & 1) != 0) {
      param_2[4] = *(float *)(DAT_2707cfa4 + 0xc) * (float)param_2[4];
      param_2[5] = *(float *)(DAT_2707cfa4 + 0xc) * (float)param_2[5];
      param_2[6] = *(float *)(DAT_2707cfa4 + 0xc) * (float)param_2[6];
    }
    fVar8 = (float10)(*DAT_27073b58)();
    if ((fVar8 != (float10)0.0) &&
       (fVar2 = SQRT((float)param_2[5] * (float)param_2[5] +
                     (float)param_2[6] * (float)param_2[6] + (float)param_2[4] * (float)param_2[4]),
       (float)fVar8 < fVar2)) {
      fVar2 = (float)fVar8 / fVar2;
      param_2[4] = fVar2 * (float)param_2[4];
      param_2[5] = fVar2 * (float)param_2[5];
      param_2[6] = fVar2 * (float)param_2[6];
    }
    FUN_2701f060(param_1,(int)param_2);
  }
  *(undefined1 *)(param_2 + 8) = DAT_2707d124;
  _DAT_2707d124 = 0;
  *(undefined1 *)((int)param_2 + 0x21) = DAT_27073080;
  _DAT_27073080 = 0;
  uVar4 = FUN_2701da30(1);
  uVar5 = (ushort)uVar4;
  *(ushort *)((int)param_2 + 0x1e) = uVar5;
  if (*(float *)(DAT_2707d180 + 0xc) != 0.0) {
    if ((float)param_2[4] <= 0.0) {
      if (0.0 <= (float)param_2[4]) goto LAB_2701d97f;
      uVar5 = uVar5 | 0x10;
    }
    else {
      uVar5 = uVar5 | 8;
    }
    *(ushort *)((int)param_2 + 0x1e) = uVar5;
  }
LAB_2701d97f:
  (*DAT_27073b28)(&local_c);
  pfVar1 = (float *)(param_2 + 1);
  if (DAT_2705f52c == 0) {
    *pfVar1 = DAT_2707d0f0;
    param_2[2] = DAT_2707d0f4;
    param_2[3] = DAT_2707d0f8;
    FUN_2701a630(1,pfVar1,param_1,(int)param_2);
    return;
  }
  *pfVar1 = local_c;
  param_2[2] = uStack_8;
  param_2[3] = uStack_4;
  DAT_2707d0f0 = local_c;
  DAT_2707d0f4 = uStack_8;
  DAT_2707d0f8 = uStack_4;
  FUN_2701a630(1,pfVar1,param_1,(int)param_2);
  return;
}


// CL_IsThirdPerson  @ 2701cda0
bool CL_IsThirdPerson(void)

{
                    /* 0x1cda0  421  CL_IsThirdPerson */
  return DAT_2707cf58 != 0;
}


