// CL_CameraOffset  @ 2701cbb0
void __cdecl CL_CameraOffset(undefined4 *param_1)

{
                    /* 0x1cbb0  419  CL_CameraOffset */
  *param_1 = DAT_27089dc0;
  param_1[1] = DAT_27089dc4;
  param_1[2] = DAT_27089dc8;
  return;
}


// CL_CreateMove  @ 2701d510
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
  
                    /* 0x1d510  420  CL_CreateMove */
  if ((DAT_27089e6c & 1) == 0) {
    DAT_27089e6c = DAT_27089e6c | 1;
    FUN_2703b22c(&DAT_2701d810);
  }
  if ((param_3 != 0) && (bVar3 = FUN_27018c30(), CONCAT31(extraout_var,bVar3) == 0)) {
    (*DAT_2707c950)(&local_c);
    FUN_2701d370(param_1,&local_c);
    puVar7 = param_2;
    for (iVar6 = 0xd; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    (*DAT_2707c954)(&local_c);
    if ((DAT_27089f98 & 1) != 0) {
      fVar8 = FUN_2701d2f0(0x27089f30);
      param_2[5] = (float)(fVar8 * (float10)*(float *)(DAT_27089fac + 0xc) +
                          (float10)(float)param_2[5]);
      fVar8 = FUN_2701d2f0(0x27089f20);
      param_2[5] = (float)((float10)(float)param_2[5] -
                          fVar8 * (float10)*(float *)(DAT_27089fac + 0xc));
    }
    fVar8 = FUN_2701d2f0(0x27089fa0);
    param_2[5] = (float)(fVar8 * (float10)*(float *)(DAT_27089fac + 0xc) +
                        (float10)(float)param_2[5]);
    fVar8 = FUN_2701d2f0(0x27089f50);
    param_2[5] = (float)((float10)(float)param_2[5] -
                        fVar8 * (float10)*(float *)(DAT_27089fac + 0xc));
    fVar8 = FUN_2701d2f0(0x27089e98);
    param_2[6] = (float)(fVar8 * (float10)*(float *)(DAT_27089fec + 0xc) +
                        (float10)(float)param_2[6]);
    fVar8 = FUN_2701d2f0(0x27089ec0);
    param_2[6] = (float)((float10)(float)param_2[6] -
                        fVar8 * (float10)*(float *)(DAT_27089fec + 0xc));
    if ((DAT_2708a000 & 1) == 0) {
      fVar8 = FUN_2701d2f0(0x27089f10);
      param_2[4] = (float)(fVar8 * (float10)*(float *)(DAT_27089eb8 + 0xc) +
                          (float10)(float)param_2[4]);
      fVar8 = FUN_2701d2f0(0x27089fc0);
      param_2[4] = (float)((float10)(float)param_2[4] -
                          fVar8 * (float10)*(float *)(DAT_27089fdc + 0xc));
    }
    if ((DAT_27089e80 & 1) != 0) {
      param_2[4] = *(float *)(DAT_27089e84 + 0xc) * (float)param_2[4];
      param_2[5] = *(float *)(DAT_27089e84 + 0xc) * (float)param_2[5];
      param_2[6] = *(float *)(DAT_27089e84 + 0xc) * (float)param_2[6];
    }
    fVar8 = (float10)(*DAT_2707c980)();
    if ((fVar8 != (float10)0.0) &&
       (fVar2 = SQRT((float)param_2[5] * (float)param_2[5] +
                     (float)param_2[6] * (float)param_2[6] + (float)param_2[4] * (float)param_2[4]),
       (float)fVar8 < fVar2)) {
      fVar2 = (float)fVar8 / fVar2;
      param_2[4] = fVar2 * (float)param_2[4];
      param_2[5] = fVar2 * (float)param_2[5];
      param_2[6] = fVar2 * (float)param_2[6];
    }
    FUN_2701ee60(param_1,(int)param_2);
  }
  *(undefined1 *)(param_2 + 8) = DAT_2708a004;
  _DAT_2708a004 = 0;
  *(undefined1 *)((int)param_2 + 0x21) = DAT_2707bea0;
  _DAT_2707bea0 = 0;
  uVar4 = FUN_2701d830(1);
  uVar5 = (ushort)uVar4;
  *(ushort *)((int)param_2 + 0x1e) = uVar5;
  if (*(float *)(DAT_2708a060 + 0xc) != 0.0) {
    if ((float)param_2[4] <= 0.0) {
      if (0.0 <= (float)param_2[4]) goto LAB_2701d77f;
      uVar5 = uVar5 | 0x10;
    }
    else {
      uVar5 = uVar5 | 8;
    }
    *(ushort *)((int)param_2 + 0x1e) = uVar5;
  }
LAB_2701d77f:
  (*DAT_2707c950)(&local_c);
  pfVar1 = (float *)(param_2 + 1);
  if (DAT_270655b4 == 0) {
    *pfVar1 = DAT_27089fd0;
    param_2[2] = DAT_27089fd4;
    param_2[3] = DAT_27089fd8;
    FUN_2701a430(1,pfVar1,param_1,(int)param_2);
    return;
  }
  *pfVar1 = local_c;
  param_2[2] = uStack_8;
  param_2[3] = uStack_4;
  DAT_27089fd0 = local_c;
  DAT_27089fd4 = uStack_8;
  DAT_27089fd8 = uStack_4;
  FUN_2701a430(1,pfVar1,param_1,(int)param_2);
  return;
}


// CL_IsThirdPerson  @ 2701cba0
bool CL_IsThirdPerson(void)

{
                    /* 0x1cba0  421  CL_IsThirdPerson */
  return DAT_27089e38 != 0;
}


