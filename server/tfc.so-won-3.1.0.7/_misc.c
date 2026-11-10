// AngleIMatrix  @ 00135440
void AngleIMatrix(float *param_1,float *param_2)

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
  param_2[1] = fVar4 * fVar1;
  param_2[2] = -fVar3;
  param_2[4] = fVar6 * -fVar1 + fVar5 * fVar3 * fVar2;
  param_2[5] = fVar6 * fVar2 + fVar5 * fVar3 * fVar1;
  param_2[6] = fVar4 * fVar5;
  param_2[8] = fVar3 * fVar6 * fVar2 + -fVar1 * -fVar5;
  param_2[9] = fVar3 * fVar6 * fVar1 + -fVar5 * fVar2;
  param_2[10] = fVar6 * fVar4;
  param_2[3] = 0.0;
  param_2[7] = 0.0;
  param_2[0xb] = 0.0;
  return;
}


// AngleMatrix  @ 0013532c
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
  param_2[5] = fVar6 * fVar2 + fVar5 * fVar3 * fVar1;
  param_2[9] = fVar4 * fVar5;
  param_2[2] = fVar3 * fVar6 * fVar2 + -fVar1 * -fVar5;
  param_2[6] = fVar3 * fVar6 * fVar1 + -fVar5 * fVar2;
  param_2[10] = fVar6 * fVar4;
  param_2[3] = 0.0;
  param_2[7] = 0.0;
  param_2[0xb] = 0.0;
  return;
}


// AngleVectors  @ 001350ec
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
    *param_3 = fVar6 * fVar1 + -fVar3 * fVar5 * fVar2;
    param_3[1] = -fVar2 * fVar6 + -fVar3 * fVar5 * fVar1;
    param_3[2] = -fVar4 * fVar5;
  }
  if (param_4 != (float *)0x0) {
    *param_4 = -fVar1 * -fVar5 + fVar3 * fVar6 * fVar2;
    param_4[1] = -fVar5 * fVar2 + fVar3 * fVar6 * fVar1;
    param_4[2] = fVar6 * fVar4;
  }
  return;
}


// AngleVectorsTranspose  @ 00135208
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


// CreateInterface  @ 0013685c
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


// CrossProduct  @ 001356b4
void CrossProduct(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_1[1] * param_2[2] - param_1[2] * param_2[1];
  param_3[1] = param_1[2] * *param_2 - *param_1 * param_2[2];
  param_3[2] = *param_1 * param_2[1] - param_1[1] * *param_2;
  return;
}


// DelayedUse  @ 000f3b3c
void DelayedUse(undefined4 param_1)

{
  GetClassPtr__H1Z10CBaseDelay_PX01_PX01(param_1);
  return;
}


// GetChaseOrigin  @ 00131fe0
void GetChaseOrigin(void)

{
  FUN_00131fec();
  return;
}


// GetEntityAPI  @ 0008db5c
undefined4 GetEntityAPI(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined **ppuVar3;
  
  if ((param_1 == (undefined4 *)0x0) || (param_2 != 0x8c)) {
    uVar1 = 0;
  }
  else {
    ppuVar3 = &gFunctionTable;
    for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_1 = *ppuVar3;
      ppuVar3 = ppuVar3 + 1;
      param_1 = param_1 + 1;
    }
    uVar1 = 1;
  }
  return uVar1;
}


// GetEntityAPI2  @ 0008db9c
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
    ppuVar3 = &gFunctionTable;
    for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_1 = *ppuVar3;
      ppuVar3 = ppuVar3 + 1;
      param_1 = param_1 + 1;
    }
    uVar1 = 1;
  }
  return uVar1;
}


// GetNewDLLFunctions  @ 0008dbe4
undefined4 GetNewDLLFunctions(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == (undefined4 *)0x0) || (*param_2 != 1)) {
    *param_2 = 1;
    uVar1 = 0;
  }
  else {
    *param_1 = gNewDLLFunctions;
    param_1[1] = PTR_GameDLLShutdown__Fv_00159b0c;
    param_1[2] = PTR_ShouldCollide__FP7edict_sT0_00159b10;
    uVar1 = 1;
  }
  return uVar1;
}


// GiveFnptrsToDll  @ 000b5660
void GiveFnptrsToDll(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &g_engfuncs;
  for (iVar1 = 0x8d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  gpGlobals = param_2;
  return;
}


// Length  @ 001356f0
longdouble Length(float *param_1)

{
  return (longdouble)SQRT(param_1[2] * param_1[2] + param_1[1] * param_1[1] + *param_1 * *param_1);
}


// VectorAngles  @ 00135888
void VectorAngles(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  
  fVar1 = 0.0;
  if (((byte)((byte)((ushort)((ushort)NAN(param_1[1]) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_1[1] == 0.0) << 0xe) >> 8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)NAN(*param_1) << 10) >> 8) |
            (byte)((ushort)((ushort)(*param_1 == 0.0) << 0xe) >> 8)) == 0x40)) {
    fVar2 = 270.0;
    if (0.0 < param_1[2]) {
      fVar2 = 90.0;
    }
  }
  else {
    lVar3 = (longdouble)fpatan((longdouble)param_1[1],(longdouble)*param_1);
    fVar1 = (float)(lVar3 * (longdouble)57.29577951308232);
    if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
      fVar1 = fVar1 + 360.0;
    }
    lVar3 = (longdouble)
            fpatan((longdouble)param_1[2],
                   (longdouble)SQRT(param_1[1] * param_1[1] + *param_1 * *param_1));
    fVar2 = (float)(lVar3 * (longdouble)57.29577951308232);
    if (0x3f < (byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1)) {
      fVar2 = fVar2 + 360.0;
    }
  }
  *param_2 = fVar2;
  param_2[1] = fVar1;
  param_2[2] = 0.0;
  return;
}


// VectorCompare  @ 001355b0
undefined4 VectorCompare(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  
  if (((byte)((byte)((ushort)((ushort)(NAN(*param_2) || NAN(*param_1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*param_2 == *param_1) << 0xe) >> 8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(param_2[1]) || NAN(param_1[1])) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_2[1] == param_1[1]) << 0xe) >> 8)) == 0x40)) {
    fVar1 = param_1[2];
    fVar2 = param_2[2];
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 0x40) {
      return 1;
    }
  }
  return 0;
}


// VectorInverse  @ 0013577c
void VectorInverse(float *param_1)

{
  *param_1 = -*param_1;
  param_1[1] = -param_1[1];
  param_1[2] = -param_1[2];
  return;
}


// VectorMA  @ 001355f8
void VectorMA(float *param_1,float param_2,float *param_3,float *param_4)

{
  *param_4 = param_2 * *param_3 + *param_1;
  param_4[1] = param_2 * param_3[1] + param_1[1];
  param_4[2] = param_2 * param_3[2] + param_1[2];
  return;
}


// VectorMatrix  @ 001357cc
void VectorMatrix(float *param_1,undefined4 *param_2,float *param_3)

{
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (((byte)((byte)((ushort)((ushort)NAN(*param_1) << 10) >> 8) |
             (byte)((ushort)((ushort)(*param_1 == 0.0) << 0xe) >> 8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)NAN(param_1[1]) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_1[1] == 0.0) << 0xe) >> 8)) == 0x40)) {
    *param_2 = 0x3f800000;
    param_2[1] = 0;
    param_2[2] = 0;
    *param_3 = -param_1[2];
    param_3[1] = 0.0;
    param_3[2] = 0.0;
  }
  else {
    local_c = 0;
    local_8 = 0;
    local_4 = 0x3f800000;
    CrossProduct(param_1,&local_c,param_2);
    VectorNormalize(param_2);
    CrossProduct(param_2,param_1,param_3);
    VectorNormalize(param_3);
  }
  return;
}


// VectorNormalize  @ 00135718
void VectorNormalize(float *param_1)

{
  float fVar1;
  
  fVar1 = SQRT(param_1[2] * param_1[2] + param_1[1] * param_1[1] + *param_1 * *param_1);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    fVar1 = 1.0 / fVar1;
    *param_1 = fVar1 * *param_1;
    param_1[1] = fVar1 * param_1[1];
    param_1[2] = fVar1 * param_1[2];
  }
  return;
}


// VectorScale  @ 00135798
void VectorScale(float *param_1,float param_2,float *param_3)

{
  *param_3 = param_2 * *param_1;
  param_3[1] = param_2 * param_1[1];
  param_3[2] = param_2 * param_1[2];
  return;
}


// VectorTransform  @ 00135554
void VectorTransform(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_1[2] * param_2[2] + param_1[1] * param_2[1] + *param_1 * *param_2 + param_2[3];
  param_3[1] = param_1[2] * param_2[6] + param_1[1] * param_2[5] + *param_1 * param_2[4] +
               param_2[7];
  param_3[2] = param_1[2] * param_2[10] + param_1[1] * param_2[9] + *param_1 * param_2[8] +
               param_2[0xb];
  return;
}


// anglemod  @ 00135094
longdouble anglemod(float param_1)

{
  return (longdouble)((float)((int)ROUND(param_1 * 182.04445) & 0xffff) * 0.005493164);
}


// beam  @ 000a003c
void beam(undefined4 param_1)

{
  GetClassPtr__H1Z5CBeam_PX01_PX01(param_1);
  return;
}


// bodyque  @ 001224b4
void bodyque(undefined4 param_1)

{
  GetClassPtr__H1Z7CCorpse_PX01_PX01(param_1);
  return;
}


// cycler  @ 000b4564
void cycler(undefined4 param_1)

{
  GetClassPtr__H1Z14CGenericCycler_PX01_PX01(param_1);
  return;
}


// detpack  @ 0009a484
void detpack(undefined4 param_1)

{
  GetClassPtr__H1Z8CDetpack_PX01_PX01(param_1);
  return;
}


// fireanddie  @ 00112b80
void fireanddie(undefined4 param_1)

{
  GetClassPtr__H1Z11CFireAndDie_PX01_PX01(param_1);
  return;
}


// ghost  @ 000f83d4
void ghost(undefined4 param_1)

{
  GetClassPtr__H1Z6CGhost_PX01_PX01(param_1);
  return;
}


// gibshooter  @ 000a381c
void gibshooter(undefined4 param_1)

{
  GetClassPtr__H1Z11CGibShooter_PX01_PX01(param_1);
  return;
}


// grenade  @ 000b0d2c
void grenade(undefined4 param_1)

{
  GetClassPtr__H1Z8CGrenade_PX01_PX01(param_1);
  return;
}


// infodecal  @ 00122080
void infodecal(undefined4 param_1)

{
  GetClassPtr__H1Z6CDecal_PX01_PX01(param_1);
  return;
}


// light  @ 000b6e88
void light(undefined4 param_1)

{
  GetClassPtr__H1Z6CLight_PX01_PX01(param_1);
  return;
}


// multisource  @ 0008aad0
void multisource(undefined4 param_1)

{
  GetClassPtr__H1Z12CMultiSource_PX01_PX01(param_1);
  return;
}


// player  @ 000d2db8
void player(undefined4 param_1)

{
  GetClassPtr__H1Z11CBasePlayer_PX01_PX01(param_1);
  return;
}


// soundent  @ 000f0898
void soundent(undefined4 param_1)

{
  GetClassPtr__H1Z9CSoundEnt_PX01_PX01(param_1);
  return;
}


// speaker  @ 000f0234
void speaker(undefined4 param_1)

{
  GetClassPtr__H1Z8CSpeaker_PX01_PX01(param_1);
  return;
}


// teledeath  @ 001154a4
void teledeath(undefined4 param_1)

{
  GetClassPtr__H1Z14CTelefragDeath_PX01_PX01(param_1);
  return;
}


// testhull  @ 000c6654
void testhull(undefined4 param_1)

{
  GetClassPtr__H1Z9CTestHull_PX01_PX01(param_1);
  return;
}


// timer  @ 00102754
void timer(undefined4 param_1)

{
  GetClassPtr__H1Z6CTimer_PX01_PX01(param_1);
  return;
}


// trigger  @ 001118bc
void trigger(undefined4 param_1)

{
  GetClassPtr__H1Z12CBaseTrigger_PX01_PX01(param_1);
  return;
}


// weaponbox  @ 00120f1c
void weaponbox(undefined4 param_1)

{
  GetClassPtr__H1Z10CWeaponBox_PX01_PX01(param_1);
  return;
}


// worldspawn  @ 00122f08
void worldspawn(undefined4 param_1)

{
  GetClassPtr__H1Z6CWorld_PX01_PX01(param_1);
  return;
}


