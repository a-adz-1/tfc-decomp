// AngleIMatrix  @ 0011f278
void AngleIMatrix(void)

{
  FUN_0011f281();
  return;
}


// AngleMatrix  @ 0011f164
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


// AngleVectors  @ 0011ef24
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


// AngleVectorsTranspose  @ 0011f040
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


// CrossProduct  @ 0011f4ec
void CrossProduct(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_1[1] * param_2[2] - param_1[2] * param_2[1];
  param_3[1] = param_1[2] * *param_2 - *param_1 * param_2[2];
  param_3[2] = *param_1 * param_2[1] - param_1[1] * *param_2;
  return;
}


// DelayedUse  @ 000e6ee8
void DelayedUse(undefined4 param_1)

{
  GetClassPtr__H1Z10CBaseDelay_PX01_PX01(param_1);
  return;
}


// GetChaseOrigin  @ 00122f74
void GetChaseOrigin(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  iVar1 = pmove + 0x250 + param_2 * 0xe0;
  AngleVectors(param_1,local_c,0,0);
  local_24 = *(float *)(iVar1 + 0x24);
  local_20 = *(float *)(iVar1 + 0x28);
  local_1c = *(float *)(iVar1 + 0x2c) + 28.0;
  VectorMA(param_3,0x42e00000,local_c,&local_18);
  local_18 = local_24 - local_18;
  local_14 = local_20 - local_14;
  local_10 = local_1c - local_10;
  iVar1 = (**(code **)((int)&__DT_REL[0x1161].r_info + pmove))(&local_24,&local_18,0,2,param_2);
  VectorMA(iVar1 + 0x14,0x40800000,iVar1 + 0x20,param_4);
  return;
}


// GetEntityAPI  @ 00085a78
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


// GetEntityAPI2  @ 00085ab8
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


// GiveFnptrsToDll  @ 000aa5f0
void GiveFnptrsToDll(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &g_engfuncs;
  for (iVar1 = 0x8c; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  gpGlobals = param_2;
  return;
}


// Length  @ 0011f528
longdouble Length(float *param_1)

{
  return (longdouble)SQRT(param_1[2] * param_1[2] + param_1[1] * param_1[1] + *param_1 * *param_1);
}


// VectorAngles  @ 0011f6c0
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


// VectorCompare  @ 0011f3e8
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


// VectorInverse  @ 0011f5b4
void VectorInverse(float *param_1)

{
  *param_1 = -*param_1;
  param_1[1] = -param_1[1];
  param_1[2] = -param_1[2];
  return;
}


// VectorMA  @ 0011f430
void VectorMA(float *param_1,float param_2,float *param_3,float *param_4)

{
  *param_4 = param_2 * *param_3 + *param_1;
  param_4[1] = param_2 * param_3[1] + param_1[1];
  param_4[2] = param_2 * param_3[2] + param_1[2];
  return;
}


// VectorMatrix  @ 0011f604
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


// VectorNormalize  @ 0011f550
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


// VectorScale  @ 0011f5d0
void VectorScale(float *param_1,float param_2,float *param_3)

{
  *param_3 = param_2 * *param_1;
  param_3[1] = param_2 * param_1[1];
  param_3[2] = param_2 * param_1[2];
  return;
}


// VectorTransform  @ 0011f38c
void VectorTransform(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_1[2] * param_2[2] + param_1[1] * param_2[1] + *param_1 * *param_2 + param_2[3];
  param_3[1] = param_1[2] * param_2[6] + param_1[1] * param_2[5] + *param_1 * param_2[4] +
               param_2[7];
  param_3[2] = param_1[2] * param_2[10] + param_1[1] * param_2[9] + *param_1 * param_2[8] +
               param_2[0xb];
  return;
}


// anglemod  @ 0011eecc
longdouble anglemod(float param_1)

{
  return (longdouble)((float)((int)ROUND(param_1 * 182.04445) & 0xffff) * 0.005493164);
}


// beam  @ 00095adc
void beam(undefined4 param_1)

{
  GetClassPtr__H1Z5CBeam_PX01_PX01(param_1);
  return;
}


// bodyque  @ 001128e4
void bodyque(undefined4 param_1)

{
  GetClassPtr__H1Z7CCorpse_PX01_PX01(param_1);
  return;
}


// cycler  @ 000a9594
void cycler(undefined4 param_1)

{
  GetClassPtr__H1Z14CGenericCycler_PX01_PX01(param_1);
  return;
}


// detpack  @ 00090698
void detpack(undefined4 param_1)

{
  GetClassPtr__H1Z8CDetpack_PX01_PX01(param_1);
  return;
}


// fireanddie  @ 001034d0
void fireanddie(undefined4 param_1)

{
  GetClassPtr__H1Z11CFireAndDie_PX01_PX01(param_1);
  return;
}


// ghost  @ 000eb46c
void ghost(undefined4 param_1)

{
  GetClassPtr__H1Z6CGhost_PX01_PX01(param_1);
  return;
}


// gibshooter  @ 0009929c
void gibshooter(undefined4 param_1)

{
  GetClassPtr__H1Z11CGibShooter_PX01_PX01(param_1);
  return;
}


// grenade  @ 000a5f9c
void grenade(undefined4 param_1)

{
  GetClassPtr__H1Z8CGrenade_PX01_PX01(param_1);
  return;
}


// infodecal  @ 001124b0
void infodecal(undefined4 param_1)

{
  GetClassPtr__H1Z6CDecal_PX01_PX01(param_1);
  return;
}


// light  @ 000abd68
void light(undefined4 param_1)

{
  GetClassPtr__H1Z6CLight_PX01_PX01(param_1);
  return;
}


// multisource  @ 00082acc
void multisource(undefined4 param_1)

{
  GetClassPtr__H1Z12CMultiSource_PX01_PX01(param_1);
  return;
}


// player  @ 000c7918
void player(undefined4 param_1)

{
  GetClassPtr__H1Z11CBasePlayer_PX01_PX01(param_1);
  return;
}


// soundent  @ 000e3dfc
void soundent(undefined4 param_1)

{
  GetClassPtr__H1Z9CSoundEnt_PX01_PX01(param_1);
  return;
}


// speaker  @ 000e37f8
void speaker(undefined4 param_1)

{
  GetClassPtr__H1Z8CSpeaker_PX01_PX01(param_1);
  return;
}


// teledeath  @ 00105df4
void teledeath(undefined4 param_1)

{
  GetClassPtr__H1Z14CTelefragDeath_PX01_PX01(param_1);
  return;
}


// testhull  @ 000bb374
void testhull(undefined4 param_1)

{
  GetClassPtr__H1Z9CTestHull_PX01_PX01(param_1);
  return;
}


// timer  @ 000f4f18
void timer(undefined4 param_1)

{
  GetClassPtr__H1Z6CTimer_PX01_PX01(param_1);
  return;
}


// trigger  @ 0010220c
void trigger(undefined4 param_1)

{
  GetClassPtr__H1Z12CBaseTrigger_PX01_PX01(param_1);
  return;
}


// weaponbox  @ 001113cc
void weaponbox(undefined4 param_1)

{
  GetClassPtr__H1Z10CWeaponBox_PX01_PX01(param_1);
  return;
}


// worldspawn  @ 00113338
void worldspawn(undefined4 param_1)

{
  GetClassPtr__H1Z6CWorld_PX01_PX01(param_1);
  return;
}


