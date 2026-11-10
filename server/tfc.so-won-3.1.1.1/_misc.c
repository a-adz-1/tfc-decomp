// AngleBetweenVectors  @ 00139f14
longdouble AngleBetweenVectors(float *param_1,float *param_2)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  
  lVar1 = (longdouble)Length(param_1);
  lVar2 = (longdouble)Length(param_2);
  lVar3 = (longdouble)0;
  if (((byte)(lVar3 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar3 == lVar1) << 0xe) >> 8)) == 0x40) ||
     ((byte)((byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar3 == lVar2) << 0xe) >> 8)) == 0x40)) {
    lVar3 = (longdouble)0;
  }
  else {
    lVar3 = (longdouble)(param_1[1] * param_2[1] + *param_1 * *param_2) +
            (longdouble)param_1[2] * (longdouble)param_2[2];
    lVar3 = (longdouble)fpatan((longdouble)(double)SQRT((longdouble)1.0 - lVar3 * lVar3),lVar3);
    lVar3 = (longdouble)((float)(lVar3 / (lVar1 * lVar2)) * 180.0 * 0.31830987);
  }
  return lVar3;
}


// AngleIMatrix  @ 00139754
void AngleIMatrix(void)

{
  FUN_00139760();
  return;
}


// AngleMatrix  @ 00139650
void AngleMatrix(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  longdouble lVar7;
  
  lVar7 = (longdouble)fsin((longdouble)(param_1[1] * 0.017453292));
  fVar1 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(param_1[1] * 0.017453292));
  fVar2 = (float)lVar7;
  lVar7 = (longdouble)fsin((longdouble)(*param_1 * 0.017453292));
  fVar3 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(*param_1 * 0.017453292));
  fVar4 = (float)lVar7;
  lVar7 = (longdouble)fsin((longdouble)(param_1[2] * 0.017453292));
  fVar5 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(param_1[2] * 0.017453292));
  fVar6 = (float)lVar7;
  *param_2 = fVar4 * fVar2;
  param_2[4] = fVar4 * fVar1;
  param_2[8] = -fVar3;
  param_2[1] = fVar6 * -fVar1 + fVar5 * fVar3 * fVar2;
  param_2[5] = fVar5 * fVar3 * fVar1 + fVar6 * fVar2;
  param_2[9] = fVar5 * fVar4;
  param_2[2] = fVar6 * fVar3 * fVar2 + -fVar5 * -fVar1;
  param_2[3] = 0.0;
  param_2[7] = 0.0;
  param_2[0xb] = 0.0;
  param_2[6] = fVar6 * fVar3 * fVar1 + -fVar5 * fVar2;
  param_2[10] = fVar6 * fVar4;
  return;
}


// AngleVectors  @ 00139538
void AngleVectors(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  longdouble lVar7;
  
  lVar7 = (longdouble)fsin((longdouble)(param_1[1] * 0.017453292));
  fVar1 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(param_1[1] * 0.017453292));
  fVar2 = (float)lVar7;
  lVar7 = (longdouble)fsin((longdouble)(*param_1 * 0.017453292));
  fVar3 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(*param_1 * 0.017453292));
  fVar4 = (float)lVar7;
  lVar7 = (longdouble)fsin((longdouble)(param_1[2] * 0.017453292));
  fVar5 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(param_1[2] * 0.017453292));
  fVar6 = (float)lVar7;
  if (param_2 != (float *)0x0) {
    *param_2 = fVar4 * fVar2;
    param_2[1] = fVar4 * fVar1;
    param_2[2] = -fVar3;
  }
  if (param_3 != (float *)0x0) {
    *param_3 = fVar6 * fVar1 + fVar5 * -fVar3 * fVar2;
    param_3[1] = fVar6 * -fVar2 + fVar5 * -fVar3 * fVar1;
    param_3[2] = fVar5 * -fVar4;
  }
  if (param_4 != (float *)0x0) {
    *param_4 = -fVar5 * -fVar1 + fVar6 * fVar3 * fVar2;
    param_4[1] = fVar6 * fVar3 * fVar1 + -fVar5 * fVar2;
    param_4[2] = fVar6 * fVar4;
  }
  return;
}


// AngleVectorsTranspose  @ 00139d30
void AngleVectorsTranspose(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  longdouble lVar7;
  
  lVar7 = (longdouble)fsin((longdouble)(param_1[1] * 0.017453292));
  fVar1 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(param_1[1] * 0.017453292));
  fVar2 = (float)lVar7;
  lVar7 = (longdouble)fsin((longdouble)(*param_1 * 0.017453292));
  fVar3 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(*param_1 * 0.017453292));
  fVar4 = (float)lVar7;
  lVar7 = (longdouble)fsin((longdouble)(param_1[2] * 0.017453292));
  fVar5 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(param_1[2] * 0.017453292));
  fVar6 = (float)lVar7;
  if (param_2 != (float *)0x0) {
    *param_2 = fVar4 * fVar2;
    param_2[1] = fVar6 * -fVar1 + fVar5 * fVar3 * fVar2;
    param_2[2] = fVar6 * fVar3 * fVar2 + -fVar5 * -fVar1;
  }
  if (param_3 != (float *)0x0) {
    *param_3 = fVar4 * fVar1;
    param_3[1] = fVar6 * fVar2 + fVar5 * fVar3 * fVar1;
    param_3[2] = fVar6 * fVar3 * fVar1 + -fVar5 * fVar2;
  }
  if (param_4 != (float *)0x0) {
    *param_4 = -fVar3;
    param_4[1] = fVar5 * fVar4;
    param_4[2] = fVar6 * fVar4;
  }
  return;
}


// CreateInterface  @ 0013b4f0
undefined4 CreateInterface(char *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = _12InterfaceReg_s_pInterfaceRegs;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = 1;
      }
      return 0;
    }
    iVar2 = strcmp((char *)puVar1[1],param_1);
    if (iVar2 == 0) break;
    puVar1 = (undefined4 *)puVar1[2];
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  uVar3 = (*(code *)*puVar1)();
  return uVar3;
}


// CrossProduct  @ 00139c38
void CrossProduct(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_1[1] * param_2[2] - param_1[2] * param_2[1];
  param_3[1] = param_1[2] * *param_2 - *param_1 * param_2[2];
  param_3[2] = *param_1 * param_2[1] - param_1[1] * *param_2;
  return;
}


// DelayedUse  @ 000f6664
void DelayedUse(undefined4 param_1)

{
  GetClassPtr__H1Z10CBaseDelay_PX01_PX01(param_1);
  return;
}


// Distance  @ 0013a104
longdouble Distance(float *param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float local_10 [3];
  
  local_10[0] = *param_2 - *param_1;
  local_10[1] = param_2[1] - param_1[1];
  fVar2 = 0.0;
  iVar3 = 0;
  local_10[2] = param_2[2] - param_1[2];
  do {
    pfVar1 = local_10 + iVar3;
    iVar3 = iVar3 + 1;
    fVar2 = *pfVar1 * *pfVar1 + fVar2;
  } while (iVar3 < 3);
  return (longdouble)SQRT(fVar2);
}


// GetEntityAPI  @ 0008f1c8
undefined4 GetEntityAPI(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined **ppuVar3;
  
  if ((param_1 == (undefined4 *)0x0) || (param_2 != 0x8c)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
    ppuVar3 = &gFunctionTable;
    for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_1 = *ppuVar3;
      ppuVar3 = ppuVar3 + 1;
      param_1 = param_1 + 1;
    }
  }
  return uVar1;
}


// GetEntityAPI2  @ 0008f178
undefined4 GetEntityAPI2(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined **ppuVar3;
  
  if ((param_1 == (undefined4 *)0x0) || (*param_2 != 0x8c)) {
    *param_2 = 0x8c;
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
    ppuVar3 = &gFunctionTable;
    for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_1 = *ppuVar3;
      ppuVar3 = ppuVar3 + 1;
      param_1 = param_1 + 1;
    }
  }
  return uVar1;
}


// GetNewDLLFunctions  @ 0008f128
undefined4 GetNewDLLFunctions(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == (undefined4 *)0x0) || (*param_2 != 1)) {
    *param_2 = 1;
    uVar1 = 0;
  }
  else {
    *param_1 = gNewDLLFunctions;
    param_1[1] = PTR_GameDLLShutdown__Fv_0015ec2c;
    param_1[2] = PTR_ShouldCollide__FP7edict_sT0_0015ec30;
    uVar1 = 1;
  }
  return uVar1;
}


// GiveFnptrsToDll  @ 000b4a0c
void GiveFnptrsToDll(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &g_engfuncs;
  for (iVar1 = 0x90; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  gpGlobals = param_2;
  return;
}


// InterpolateAngles  @ 00139858
void InterpolateAngles(int param_1,int param_2,int param_3,float param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    fVar1 = *(float *)(param_1 + iVar3 * 4);
    if ((byte)((fVar1 < 180.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 180.0) << 0xe) >> 8)) - 1) < 0x40) {
      if (fVar1 < -180.0) {
        fVar1 = fVar1 + 360.0;
        goto LAB_001398b3;
      }
    }
    else {
      fVar1 = fVar1 - 360.0;
LAB_001398b3:
      *(float *)(param_1 + iVar3 * 4) = fVar1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  iVar3 = 0;
  do {
    fVar1 = *(float *)(param_2 + iVar3 * 4);
    if ((byte)((fVar1 < 180.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 180.0) << 0xe) >> 8)) - 1) < 0x40) {
      if (fVar1 < -180.0) {
        fVar1 = fVar1 + 360.0;
        goto LAB_00139903;
      }
    }
    else {
      fVar1 = fVar1 - 360.0;
LAB_00139903:
      *(float *)(param_2 + iVar3 * 4) = fVar1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  iVar3 = 0;
  do {
    fVar1 = *(float *)(param_1 + iVar3 * 4);
    fVar2 = *(float *)(param_2 + iVar3 * 4) - fVar1;
    if ((byte)((fVar2 < 180.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == 180.0) << 0xe) >> 8)) - 1) < 0x40) {
      if (fVar2 < -180.0) {
        fVar2 = fVar2 + 360.0;
      }
    }
    else {
      fVar2 = fVar2 - 360.0;
    }
    *(float *)(param_3 + iVar3 * 4) = fVar2 * param_4 + fVar1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  iVar3 = 0;
  do {
    fVar1 = *(float *)(param_3 + iVar3 * 4);
    if ((byte)((fVar1 < 180.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 180.0) << 0xe) >> 8)) - 1) < 0x40) {
      if (fVar1 < -180.0) {
        fVar1 = fVar1 + 360.0;
        goto LAB_001399a3;
      }
    }
    else {
      fVar1 = fVar1 - 360.0;
LAB_001399a3:
      *(float *)(param_3 + iVar3 * 4) = fVar1;
    }
    iVar3 = iVar3 + 1;
    if (2 < iVar3) {
      return;
    }
  } while( true );
}


// Length  @ 00139c08
longdouble Length(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar2 = 0.0;
  iVar3 = 0;
  do {
    fVar1 = *(float *)(param_1 + iVar3 * 4);
    iVar3 = iVar3 + 1;
    fVar2 = fVar1 * fVar1 + fVar2;
  } while (iVar3 < 3);
  return (longdouble)SQRT(fVar2);
}


// NormalizeAngles  @ 00139ea4
void NormalizeAngles(int param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    fVar1 = *(float *)(param_1 + iVar2 * 4);
    if ((byte)((fVar1 < 180.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 180.0) << 0xe) >> 8)) - 1) < 0x40) {
      if (fVar1 < -180.0) {
        fVar1 = fVar1 + 360.0;
        goto LAB_00139ef3;
      }
    }
    else {
      fVar1 = fVar1 - 360.0;
LAB_00139ef3:
      *(float *)(param_1 + iVar2 * 4) = fVar1;
    }
    iVar2 = iVar2 + 1;
    if (2 < iVar2) {
      return;
    }
  } while( true );
}


// VectorAngles  @ 00139fd4
void VectorAngles(float *param_1,float *param_2)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  
  lVar4 = (longdouble)0;
  lVar2 = (longdouble)param_1[1];
  if (((byte)((byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar4)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar2 == lVar4) << 0xe) >> 8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN((longdouble)*param_1) || NAN(lVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)*param_1 == lVar4) << 0xe) >> 8)) == 0x40)) {
    lVar2 = (longdouble)270.0;
    if (lVar4 < (longdouble)param_1[2]) {
      lVar2 = (longdouble)90.0;
    }
  }
  else {
    lVar3 = (longdouble)*param_1;
    lVar4 = (longdouble)fpatan(lVar2,lVar3);
    lVar4 = (longdouble)(float)(lVar4 * (longdouble)57.29577951308232);
    lVar1 = (longdouble)0;
    if (0x3f < (byte)((lVar1 < lVar4 |
                       (byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar4)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar1 == lVar4) << 0xe) >> 8)) - 1)) {
      lVar4 = (longdouble)360.0 + lVar4;
    }
    lVar2 = (longdouble)
            fpatan((longdouble)param_1[2],(longdouble)(float)SQRT(lVar2 * lVar2 + lVar3 * lVar3));
    lVar2 = (longdouble)(float)(lVar2 * (longdouble)57.29577951308232);
    if (lVar2 < lVar1) {
      lVar2 = (longdouble)360.0 + lVar2;
    }
  }
  *param_2 = (float)lVar2;
  param_2[1] = (float)lVar4;
  param_2[2] = 0.0;
  return;
}


// VectorCompare  @ 00139bd0
undefined4 VectorCompare(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    fVar1 = *(float *)(param_1 + iVar3 * 4);
    fVar2 = *(float *)(param_2 + iVar3 * 4);
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
      return 0;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return 1;
}


// VectorInverse  @ 00139cd4
void VectorInverse(float *param_1)

{
  *param_1 = -*param_1;
  param_1[1] = -param_1[1];
  param_1[2] = -param_1[2];
  return;
}


// VectorMA  @ 00139b0c
void VectorMA(float *param_1,float param_2,float *param_3,float *param_4)

{
  *param_4 = param_2 * *param_3 + *param_1;
  param_4[1] = param_2 * param_3[1] + param_1[1];
  param_4[2] = param_2 * param_3[2] + param_1[2];
  return;
}


// VectorMatrix  @ 001399c8
void VectorMatrix(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  if (((byte)((byte)((ushort)((ushort)NAN(*param_1) << 10) >> 8) |
             (byte)((ushort)((ushort)(*param_1 == 0.0) << 0xe) >> 8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)NAN(param_1[1]) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_1[1] == 0.0) << 0xe) >> 8)) == 0x40)) {
    *param_2 = 1.0;
    param_2[1] = 0.0;
    param_2[2] = 0.0;
    fVar1 = param_1[2];
    param_3[1] = 0.0;
    param_3[2] = 0.0;
    *param_3 = -fVar1;
  }
  else {
    fVar1 = param_1[1];
    *param_2 = fVar1;
    fVar3 = -*param_1;
    param_2[2] = 0.0;
    param_2[1] = fVar3;
    fVar2 = SQRT(fVar3 * fVar3 + fVar1 * fVar1);
    if ((byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
      param_2[2] = 0.0;
      *param_2 = fVar1 * (1.0 / fVar2);
      param_2[1] = fVar3 * (1.0 / fVar2);
    }
    fVar2 = param_2[1] * param_1[2] - param_2[2] * param_1[1];
    *param_3 = fVar2;
    fVar3 = param_2[2] * *param_1 - *param_2 * param_1[2];
    param_3[1] = fVar3;
    fVar4 = *param_2 * param_1[1] - param_2[1] * *param_1;
    param_3[2] = fVar4;
    fVar1 = SQRT(fVar4 * fVar4 + fVar3 * fVar3 + fVar2 * fVar2);
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      fVar1 = 1.0 / fVar1;
      *param_3 = fVar2 * fVar1;
      param_3[1] = fVar3 * fVar1;
      param_3[2] = fVar4 * fVar1;
    }
  }
  return;
}


// VectorNormalize  @ 00139c78
longdouble VectorNormalize(float *param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  
  lVar1 = (longdouble)*param_1;
  lVar2 = (longdouble)param_1[1];
  lVar3 = (longdouble)param_1[2];
  lVar4 = (longdouble)(float)SQRT(lVar3 * lVar3 + lVar2 * lVar2 + lVar1 * lVar1);
  lVar5 = (longdouble)0;
  if ((byte)(lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) != 0x40) {
    lVar5 = (longdouble)1 / lVar4;
    *param_1 = (float)(lVar1 * lVar5);
    param_1[1] = (float)(lVar2 * lVar5);
    param_1[2] = (float)(lVar5 * lVar3);
  }
  return lVar4;
}


// VectorScale  @ 00139cf4
void VectorScale(float *param_1,float param_2,float *param_3)

{
  *param_3 = *param_1 * param_2;
  param_3[1] = param_1[1] * param_2;
  param_3[2] = param_2 * param_1[2];
  return;
}


// VectorTransform  @ 00139e44
void VectorTransform(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_1[2] * param_2[2] + param_1[1] * param_2[1] + *param_1 * *param_2 + param_2[3];
  param_3[1] = param_1[2] * param_2[6] + param_1[1] * param_2[5] + *param_1 * param_2[4] +
               param_2[7];
  param_3[2] = param_1[2] * param_2[10] + param_1[1] * param_2[9] + *param_1 * param_2[8] +
               param_2[0xb];
  return;
}


// anglemod  @ 0013a0b0
longdouble anglemod(float param_1)

{
  return (longdouble)((float)((int)ROUND(param_1 * 182.04445) & 0xffff) * 0.005493164);
}


// beam  @ 000a5888
void beam(undefined4 param_1)

{
  GetClassPtr__H1Z5CBeam_PX01_PX01(param_1);
  return;
}


// bodyque  @ 00127f50
void bodyque(undefined4 param_1)

{
  GetClassPtr__H1Z7CCorpse_PX01_PX01(param_1);
  return;
}


// cycler  @ 000b48cc
void cycler(undefined4 param_1)

{
  GetClassPtr__H1Z14CGenericCycler_PX01_PX01(param_1);
  return;
}


// detpack  @ 0009aca0
void detpack(void)

{
  FUN_0009aca9();
  return;
}


// fireanddie  @ 00118b4c
void fireanddie(undefined4 param_1)

{
  GetClassPtr__H1Z11CFireAndDie_PX01_PX01(param_1);
  return;
}


// ghost  @ 000fb5ac
void ghost(void)

{
  FUN_000fb5b5();
  return;
}


// gibshooter  @ 000a4180
void gibshooter(undefined4 param_1)

{
  GetClassPtr__H1Z11CGibShooter_PX01_PX01(param_1);
  return;
}


// grenade  @ 000b1f3c
void grenade(undefined4 param_1)

{
  GetClassPtr__H1Z8CGrenade_PX01_PX01(param_1);
  return;
}


// infodecal  @ 001280bc
void infodecal(undefined4 param_1)

{
  GetClassPtr__H1Z6CDecal_PX01_PX01(param_1);
  return;
}


// light  @ 000b6ac4
void light(undefined4 param_1)

{
  GetClassPtr__H1Z6CLight_PX01_PX01(param_1);
  return;
}


// multisource  @ 0008d1f8
void multisource(undefined4 param_1)

{
  GetClassPtr__H1Z12CMultiSource_PX01_PX01(param_1);
  return;
}


// player  @ 000e6074
void player(undefined4 param_1)

{
  GetClassPtr__H1Z11CBasePlayer_PX01_PX01(param_1);
  return;
}


// soundent  @ 000f32b0
void soundent(undefined4 param_1)

{
  GetClassPtr__H1Z9CSoundEnt_PX01_PX01(param_1);
  return;
}


// speaker  @ 000f202c
void speaker(undefined4 param_1)

{
  GetClassPtr__H1Z8CSpeaker_PX01_PX01(param_1);
  return;
}


// teledeath  @ 00117d48
void teledeath(undefined4 param_1)

{
  GetClassPtr__H1Z14CTelefragDeath_PX01_PX01(param_1);
  return;
}


// testhull  @ 000cb690
void testhull(undefined4 param_1)

{
  GetClassPtr__H1Z9CTestHull_PX01_PX01(param_1);
  return;
}


// timer  @ 0010858c
void timer(void)

{
  FUN_00108595();
  return;
}


// trigger  @ 001197a8
void trigger(undefined4 param_1)

{
  GetClassPtr__H1Z12CBaseTrigger_PX01_PX01(param_1);
  return;
}


// weaponbox  @ 001251f8
void weaponbox(undefined4 param_1)

{
  GetClassPtr__H1Z10CWeaponBox_PX01_PX01(param_1);
  return;
}


// worldspawn  @ 00127a4c
void worldspawn(undefined4 param_1)

{
  GetClassPtr__H1Z6CWorld_PX01_PX01(param_1);
  return;
}


