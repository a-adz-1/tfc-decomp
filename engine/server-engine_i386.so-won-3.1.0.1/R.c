// R_AddToStudioCache  @ 0005e2e8
void R_AddToStudioCache(undefined4 param_1,undefined4 param_2,undefined4 *param_3,
                       undefined4 *param_4,undefined4 *param_5,undefined4 param_6,undefined4 param_7
                       ,undefined4 param_8,undefined4 param_9,int param_10)

{
  int iVar1;
  int iVar2;
  
  if (0x7f < param_10 + nCurrentHull) {
    R_FlushStudioCache();
  }
  r_cachecurrent = r_cachecurrent + 1;
  iVar1 = (r_cachecurrent & 0xf) * 0x44;
  *(undefined4 *)(rgStudioCache + iVar1) = param_1;
  *(undefined4 *)(rgStudioCache + iVar1 + 4) = param_2;
  *(undefined4 *)(rgStudioCache + iVar1 + 8) = *param_3;
  *(undefined4 *)(rgStudioCache + iVar1 + 0xc) = param_3[1];
  *(undefined4 *)(rgStudioCache + iVar1 + 0x10) = param_3[2];
  *(undefined4 *)(rgStudioCache + iVar1 + 0x14) = *param_4;
  *(undefined4 *)(rgStudioCache + iVar1 + 0x18) = param_4[1];
  *(undefined4 *)(rgStudioCache + iVar1 + 0x1c) = param_4[2];
  *(undefined4 *)(rgStudioCache + iVar1 + 0x20) = *param_5;
  *(undefined4 *)(rgStudioCache + iVar1 + 0x24) = param_5[1];
  *(undefined4 *)(rgStudioCache + iVar1 + 0x28) = param_5[2];
  Q_memcpy(iVar1 + 0xceb2c,param_6,4);
  Q_memcpy(iVar1 + 0xceb30,param_7,2);
  *(undefined4 *)(rgStudioCache + iVar1 + 0x34) = param_8;
  iVar2 = nCurrentHull;
  *(int *)(rgStudioCache + iVar1 + 0x38) = nCurrentHull;
  *(int *)(rgStudioCache + iVar1 + 0x3c) = nCurrentPlane;
  Q_memcpy(cache_hull + iVar2 * 0x28,param_9,param_10 * 0x28);
  Q_memcpy(cache_planes + nCurrentPlane * 0x14,studio_planes,param_10 * 0x78);
  Q_memcpy(cache_hull_hitgroup + nCurrentHull * 4,studio_hull_hitgroup,param_10 * 4);
  nCurrentHull = nCurrentHull + param_10;
  nCurrentPlane = nCurrentPlane + param_10 * 6;
  *(int *)(rgStudioCache + iVar1 + 0x40) = param_10;
  return;
}


// R_CheckStudioCache  @ 0005e1f8
float * R_CheckStudioCache(int param_1,float param_2,int param_3,undefined4 param_4,
                          undefined4 param_5,undefined4 param_6,undefined4 param_7,
                          undefined4 param_8)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  while( true ) {
    iVar1 = (r_cachecurrent - iVar4 & 0xfU) * 0x44;
    if (((((*(int *)(rgStudioCache + iVar1 + 0x34) == param_1) &&
          (fVar2 = *(float *)(rgStudioCache + iVar1),
          (byte)((byte)((ushort)((ushort)(NAN(param_2) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(param_2 == fVar2) << 0xe) >> 8)) == 0x40)) &&
         (*(int *)(rgStudioCache + iVar1 + 4) == param_3)) &&
        ((iVar3 = VectorCompare(iVar1 + 0xceb08,param_4), iVar3 != 0 &&
         (iVar3 = VectorCompare(iVar1 + 0xceb14,param_5), iVar3 != 0)))) &&
       ((iVar3 = VectorCompare(iVar1 + 0xceb20,param_6), iVar3 != 0 &&
        ((iVar3 = Q_memcmp(iVar1 + 0xceb2c,param_7,4), iVar3 == 0 &&
         (iVar3 = Q_memcmp(iVar1 + 0xceb30,param_8,2), iVar3 == 0)))))) break;
    iVar4 = iVar4 + 1;
    if (0xf < iVar4) {
      return (float *)0x0;
    }
  }
  return (float *)(rgStudioCache + iVar1);
}


// R_ConcatRotations  @ 00061eb4
void R_ConcatRotations(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_1[2] * param_2[6] + param_1[1] * param_2[3] + *param_1 * *param_2;
  param_3[1] = param_1[2] * param_2[7] + param_1[1] * param_2[4] + *param_1 * param_2[1];
  param_3[2] = param_1[2] * param_2[8] + param_1[1] * param_2[5] + *param_1 * param_2[2];
  param_3[3] = param_1[5] * param_2[6] + param_1[4] * param_2[3] + param_1[3] * *param_2;
  param_3[4] = param_1[5] * param_2[7] + param_1[4] * param_2[4] + param_1[3] * param_2[1];
  param_3[5] = param_1[5] * param_2[8] + param_1[4] * param_2[5] + param_1[3] * param_2[2];
  param_3[6] = param_1[8] * param_2[6] + param_1[7] * param_2[3] + param_1[6] * *param_2;
  param_3[7] = param_1[8] * param_2[7] + param_1[7] * param_2[4] + param_1[6] * param_2[1];
  param_3[8] = param_1[8] * param_2[8] + param_1[7] * param_2[5] + param_1[6] * param_2[2];
  return;
}


// R_ConcatTransforms  @ 00061fa0
void R_ConcatTransforms(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_1[2] * param_2[8] + param_1[1] * param_2[4] + *param_1 * *param_2;
  param_3[1] = param_1[2] * param_2[9] + param_1[1] * param_2[5] + *param_1 * param_2[1];
  param_3[2] = param_1[2] * param_2[10] + param_1[1] * param_2[6] + *param_1 * param_2[2];
  param_3[3] = param_1[2] * param_2[0xb] + param_1[1] * param_2[7] + *param_1 * param_2[3] +
               param_1[3];
  param_3[4] = param_1[6] * param_2[8] + param_1[5] * param_2[4] + param_1[4] * *param_2;
  param_3[5] = param_1[6] * param_2[9] + param_1[5] * param_2[5] + param_1[4] * param_2[1];
  param_3[6] = param_1[6] * param_2[10] + param_1[5] * param_2[6] + param_1[4] * param_2[2];
  param_3[7] = param_1[6] * param_2[0xb] + param_1[5] * param_2[7] + param_1[4] * param_2[3] +
               param_1[7];
  param_3[8] = param_1[10] * param_2[8] + param_1[9] * param_2[4] + param_1[8] * *param_2;
  param_3[9] = param_1[10] * param_2[9] + param_1[9] * param_2[5] + param_1[8] * param_2[1];
  param_3[10] = param_1[10] * param_2[10] + param_1[9] * param_2[6] + param_1[8] * param_2[2];
  param_3[0xb] = param_1[10] * param_2[0xb] + param_1[9] * param_2[7] + param_1[8] * param_2[3] +
                 param_1[0xb];
  return;
}


// R_DecalRemoveAll  @ 00092070
void R_DecalRemoveAll(void)

{
  return;
}


// R_FlushStudioCache  @ 000602d0
void R_FlushStudioCache(void)

{
  R_InitStudioCache();
  return;
}


// R_GetAnim  @ 0005f36c
int R_GetAnim(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_10;
  int local_c;
  
  local_c = *(int *)(param_2 + 0x9c);
  iVar2 = pstudiohdr + *(int *)(pstudiohdr + 0xb0) + local_c * 0x68;
  if (local_c == 0) {
    iVar2 = pstudiohdr + *(int *)(iVar2 + 100) + *(int *)(param_2 + 0x7c);
  }
  else {
    local_10 = *(int *)(param_1 + 0x7c);
    if (local_10 == 0) {
      local_10 = Mem_Calloc(0x10,4);
      *(int *)(param_1 + 0x7c) = local_10;
      local_c = *(int *)(param_2 + 0x9c);
    }
    iVar1 = Cache_Check(local_10 + local_c * 4);
    if (iVar1 == 0) {
      iVar2 = iVar2 + 0x20;
      Con_DPrintf("loading %s\n",iVar2);
      COM_LoadCacheFile(iVar2,*(int *)(param_2 + 0x9c) * 4 + local_10);
    }
    iVar2 = *(int *)(param_2 + 0x7c) + *(int *)(local_10 + *(int *)(param_2 + 0x9c) * 4);
  }
  return iVar2;
}


// R_GetStudioBounds  @ 000612ac
undefined4 R_GetStudioBounds(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  *param_2 = vec3_origin;
  param_2[1] = DAT_000b2e2c;
  param_2[2] = DAT_000b2e30;
  *param_3 = vec3_origin;
  param_3[1] = DAT_000b2e2c;
  param_3[2] = DAT_000b2e30;
  iVar1 = Q_strstr(param_1,"models");
  if (((iVar1 != 0) && (iVar1 = Q_strstr(param_1,&DAT_000a84cb), iVar1 != 0)) &&
     (puVar2 = (undefined4 *)COM_LoadFile(param_1,5,0), puVar2 != (undefined4 *)0x0)) {
    iVar1 = (*LittleLong)(*puVar2);
    if (iVar1 == 0x54534449) {
      uVar3 = R_StudioComputeBounds(puVar2,param_2,param_3);
      COM_FreeFile(puVar2);
      return uVar3;
    }
    COM_FreeFile(puVar2);
  }
  return 0;
}


// R_Init  @ 00092040
void R_Init(void)

{
  return;
}


// R_InitSky  @ 00092058
void R_InitSky(void)

{
  return;
}


// R_InitStudioCache  @ 00060288
void R_InitStudioCache(void)

{
  Q_memset(rgStudioCache,0,0x440);
  r_cachecurrent = 0;
  nCurrentHull = 0;
  nCurrentPlane = 0;
  return;
}


// R_InitTextures  @ 0009214c
void R_InitTextures(void)

{
  return;
}


// R_MarkLeaves  @ 00092060
void R_MarkLeaves(void)

{
  return;
}


// R_SetStackBase  @ 00092018
void R_SetStackBase(void)

{
  return;
}


// R_StudioAccumulateBoneVerts  @ 00060c4c
void R_StudioAccumulateBoneVerts
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,float *param_4,
               float *param_5,int *param_6)

{
  undefined1 local_1c [12];
  float local_10;
  float local_c;
  float local_8;
  
  if (0 < *param_6) {
    local_10 = *param_5 - *param_4;
    local_c = param_5[1] - param_4[1];
    local_8 = param_5[2] - param_4[2];
    VectorScale(&local_10,0x3f000000,local_1c);
    R_StudioBoundVertex(param_1,param_2,param_3,local_1c);
    VectorScale(&local_10,0xbf000000,local_1c);
    R_StudioBoundVertex(param_1,param_2,param_3,local_1c);
    *param_4 = 0.0;
    param_4[1] = 0.0;
    param_4[2] = 0.0;
    *param_5 = 0.0;
    param_5[1] = 0.0;
    param_5[2] = 0.0;
    *param_6 = 0;
  }
  return;
}


// R_StudioBodyVariations  @ 000602ec
int R_StudioBodyVariations(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  
  if ((*(int *)(param_1 + 0x44) == 3) && (iVar2 = Mod_Extradata(param_1), iVar2 != 0)) {
    iVar3 = 1;
    iVar6 = 0;
    uVar1 = *(uint *)(iVar2 + 0xcc);
    iVar2 = iVar2 + *(int *)(iVar2 + 0xd0);
    if (0 < (int)uVar1) {
      piVar5 = (int *)(iVar2 + 0x40);
      uVar4 = uVar1 & 3;
      if (uVar4 != 0) {
        if (1 < uVar4) {
          if (2 < uVar4) {
            iVar3 = *(int *)(iVar2 + 0x40);
            piVar5 = (int *)(iVar2 + 0x8c);
          }
          iVar3 = iVar3 * *piVar5;
          piVar5 = piVar5 + 0x13;
          iVar6 = (2 < uVar4) + 1;
        }
        iVar3 = iVar3 * *piVar5;
        piVar5 = piVar5 + 0x13;
        iVar6 = iVar6 + 1;
        if ((int)uVar1 <= iVar6) {
          return iVar3;
        }
      }
      do {
        iVar3 = iVar3 * *piVar5 * piVar5[0x13] * piVar5[0x26] * piVar5[0x39];
        piVar5 = piVar5 + 0x4c;
        iVar6 = iVar6 + 4;
      } while (iVar6 < (int)uVar1);
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}


// R_StudioBoundBone  @ 00060a8c
void R_StudioBoundBone(float *param_1,float *param_2,int *param_3,float *param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  
  if (*param_3 == 0) {
    *param_1 = *param_4;
    param_1[1] = param_4[1];
    param_1[2] = param_4[2];
    *param_2 = *param_4;
    param_2[1] = param_4[1];
    param_2[2] = param_4[2];
  }
  else {
    pfVar1 = param_2 + 2;
    if ((int)param_2 < (int)param_2 + 9) {
      fVar2 = *param_4;
      if (fVar2 < *param_1) {
        *param_1 = fVar2;
        fVar2 = *param_4;
      }
      fVar3 = *param_2;
      if (0x3f < (byte)((fVar2 < fVar3 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
        *param_2 = fVar2;
      }
      fVar2 = param_4[1];
      if (fVar2 < param_1[1]) {
        param_1[1] = fVar2;
        fVar2 = param_4[1];
      }
      fVar3 = param_2[1];
      if (0x3f < (byte)((fVar2 < fVar3 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
        param_2[1] = fVar2;
      }
      param_2 = param_2 + 2;
      param_4 = param_4 + 2;
      param_1 = param_1 + 2;
    }
    fVar2 = *param_4;
    if (fVar2 < *param_1) {
      *param_1 = fVar2;
      fVar2 = *param_4;
    }
    fVar3 = *param_2;
    if (0x3f < (byte)((fVar2 < fVar3 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
      *param_2 = fVar2;
    }
    param_4 = param_4 + 1;
    param_1 = param_1 + 1;
    for (param_2 = param_2 + 1; (int)param_2 <= (int)pfVar1; param_2 = param_2 + 4) {
      fVar2 = *param_4;
      if (fVar2 < *param_1) {
        *param_1 = fVar2;
        fVar2 = *param_4;
      }
      fVar3 = *param_2;
      if (0x3f < (byte)((fVar2 < fVar3 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
        *param_2 = fVar2;
      }
      fVar2 = param_4[1];
      if (fVar2 < param_1[1]) {
        param_1[1] = fVar2;
        fVar2 = param_4[1];
      }
      fVar3 = param_2[1];
      if (0x3f < (byte)((fVar2 < fVar3 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
        param_2[1] = fVar2;
      }
      fVar2 = param_4[2];
      if (fVar2 < param_1[2]) {
        param_1[2] = fVar2;
        fVar2 = param_4[2];
      }
      fVar3 = param_2[2];
      if (0x3f < (byte)((fVar2 < fVar3 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
        param_2[2] = fVar2;
      }
      fVar2 = param_4[3];
      if (fVar2 < param_1[3]) {
        param_1[3] = fVar2;
        fVar2 = param_4[3];
      }
      fVar3 = param_2[3];
      if (0x3f < (byte)((fVar2 < fVar3 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
        param_2[3] = fVar2;
      }
      param_4 = param_4 + 4;
      param_1 = param_1 + 4;
    }
  }
  *param_3 = *param_3 + 1;
  return;
}


// R_StudioBoundVertex  @ 000608cc
void R_StudioBoundVertex(float *param_1,float *param_2,int *param_3,float *param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  
  if (*param_3 == 0) {
    *param_1 = *param_4;
    param_1[1] = param_4[1];
    param_1[2] = param_4[2];
    *param_2 = *param_4;
    param_2[1] = param_4[1];
    param_2[2] = param_4[2];
  }
  else {
    pfVar1 = param_2 + 2;
    if ((int)param_2 < (int)param_2 + 9) {
      fVar2 = *param_4;
      if (fVar2 < *param_1) {
        *param_1 = fVar2;
        fVar2 = *param_4;
      }
      fVar3 = *param_2;
      if (0x3f < (byte)((fVar2 < fVar3 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
        *param_2 = fVar2;
      }
      fVar2 = param_4[1];
      if (fVar2 < param_1[1]) {
        param_1[1] = fVar2;
        fVar2 = param_4[1];
      }
      fVar3 = param_2[1];
      if (0x3f < (byte)((fVar2 < fVar3 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
        param_2[1] = fVar2;
      }
      param_2 = param_2 + 2;
      param_4 = param_4 + 2;
      param_1 = param_1 + 2;
    }
    fVar2 = *param_4;
    if (fVar2 < *param_1) {
      *param_1 = fVar2;
      fVar2 = *param_4;
    }
    fVar3 = *param_2;
    if (0x3f < (byte)((fVar2 < fVar3 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
      *param_2 = fVar2;
    }
    param_4 = param_4 + 1;
    param_1 = param_1 + 1;
    for (param_2 = param_2 + 1; (int)param_2 <= (int)pfVar1; param_2 = param_2 + 4) {
      fVar2 = *param_4;
      if (fVar2 < *param_1) {
        *param_1 = fVar2;
        fVar2 = *param_4;
      }
      fVar3 = *param_2;
      if (0x3f < (byte)((fVar2 < fVar3 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
        *param_2 = fVar2;
      }
      fVar2 = param_4[1];
      if (fVar2 < param_1[1]) {
        param_1[1] = fVar2;
        fVar2 = param_4[1];
      }
      fVar3 = param_2[1];
      if (0x3f < (byte)((fVar2 < fVar3 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
        param_2[1] = fVar2;
      }
      fVar2 = param_4[2];
      if (fVar2 < param_1[2]) {
        param_1[2] = fVar2;
        fVar2 = param_4[2];
      }
      fVar3 = param_2[2];
      if (0x3f < (byte)((fVar2 < fVar3 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
        param_2[2] = fVar2;
      }
      fVar2 = param_4[3];
      if (fVar2 < param_1[3]) {
        param_1[3] = fVar2;
        fVar2 = param_4[3];
      }
      fVar3 = param_2[3];
      if (0x3f < (byte)((fVar2 < fVar3 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
        param_2[3] = fVar2;
      }
      param_4 = param_4 + 4;
      param_1 = param_1 + 4;
    }
  }
  *param_3 = *param_3 + 1;
  return;
}


// R_StudioCalcBoneAdj  @ 0005eb2c
void R_StudioCalcBoneAdj(float param_1,float *param_2,int param_3,int param_4,byte param_5)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  int local_20;
  int *local_1c;
  float *local_18;
  uint *local_14;
  float *local_10;
  
  iVar6 = 0;
  iVar4 = pstudiohdr + *(int *)(pstudiohdr + 0x98);
  if (0 < *(int *)(pstudiohdr + 0x94)) {
    local_10 = param_2;
    local_14 = (uint *)(iVar4 + 4);
    local_18 = (float *)(iVar4 + 0xc);
    pfVar5 = (float *)(iVar4 + 8);
    local_1c = (int *)(iVar4 + 0x14);
    do {
      iVar4 = *local_1c;
      if (iVar4 < 4) {
        if (-1 < (short)*local_14) {
          fVar1 = ((1.0 - param_1) * (float)*(byte *)(iVar4 + param_4) +
                  param_1 * (float)*(byte *)(iVar4 + param_3)) * 0.003921569;
          if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
            fVar1 = 0.0;
          }
          if (0x3f < (byte)((fVar1 < 1.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) - 1))
          goto LAB_0005ece5;
          goto LAB_0005ecef;
        }
        local_20 = (uint)*(byte *)(iVar4 + param_3) - (uint)*(byte *)(iVar4 + param_4);
        if (local_20 < 0) {
          local_20 = -local_20;
        }
        if (local_20 < 0x81) {
          fVar1 = ((1.0 - param_1) * (float)*(byte *)(iVar4 + param_4) +
                  param_1 * (float)*(byte *)(iVar4 + param_3)) * 1.40625 + *pfVar5;
        }
        else {
          uVar3 = *(byte *)(iVar6 + param_3) + 0x80;
          uVar2 = *(byte *)(iVar6 + param_4) + 0x80;
          fVar1 = (((1.0 - param_1) * (float)(int)(uVar2 - (uVar2 & 0x300)) +
                   param_1 * (float)(int)(uVar3 - (uVar3 & 0x300))) - 128.0) * 1.40625 + *pfVar5;
        }
      }
      else {
        fVar1 = (float)param_5 * 0.015625;
        if (1.0 < fVar1) {
LAB_0005ece5:
          fVar1 = 1.0;
        }
LAB_0005ecef:
        fVar1 = (1.0 - fVar1) * *pfVar5 + fVar1 * *local_18;
      }
      switch(*local_14 & 0x7fff) {
      case 1:
      case 2:
      case 4:
        *local_10 = fVar1;
        break;
      default:
        break;
      case 8:
      case 0x10:
      case 0x20:
        *local_10 = fVar1 * 0.017453292;
      }
      local_10 = local_10 + 1;
      local_14 = local_14 + 6;
      local_18 = local_18 + 6;
      pfVar5 = pfVar5 + 6;
      local_1c = local_1c + 6;
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(pstudiohdr + 0x94));
  }
  return;
}


// R_StudioCalcBonePosition  @ 0005f058
void R_StudioCalcBonePosition
               (int param_1,float param_2,int param_3,ushort *param_4,int param_5,float *param_6)

{
  short sVar1;
  float fVar2;
  byte bVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  ushort *local_24;
  float *local_20;
  int local_c;
  
  local_c = 0;
  local_20 = param_6;
  local_24 = param_4;
  do {
    iVar5 = local_c * 4;
    *local_20 = *(float *)(iVar5 + param_3 + 0x40);
    if (*local_24 != 0) {
      pbVar4 = (byte *)((int)param_4 + (uint)*local_24);
      iVar6 = param_3 + 0x58;
      bVar3 = *pbVar4;
      iVar9 = param_1;
      while( true ) {
        if (pbVar4[1] < bVar3) {
          iVar9 = 0;
        }
        uVar7 = (uint)pbVar4[1];
        if (iVar9 < (int)uVar7) break;
        iVar9 = iVar9 - uVar7;
        pbVar4 = pbVar4 + (uint)*pbVar4 * 2 + 2;
        bVar3 = *pbVar4;
      }
      uVar8 = (uint)*pbVar4;
      if (iVar9 < (int)uVar8) {
        if (iVar9 + 1 < (int)uVar8) {
          *local_20 = (param_2 * (float)(int)*(short *)(pbVar4 + iVar9 * 2 + 4) +
                      (1.0 - param_2) * (float)(int)*(short *)(pbVar4 + iVar9 * 2 + 2)) *
                      *(float *)(iVar5 + iVar6) + *local_20;
          goto LAB_0005f1a6;
        }
        sVar1 = *(short *)(pbVar4 + iVar9 * 2 + 2);
LAB_0005f195:
        fVar2 = *(float *)(iVar5 + iVar6) * (float)(int)sVar1 + *local_20;
      }
      else {
        if (iVar9 + 1 < (int)uVar7) {
          sVar1 = *(short *)(pbVar4 + uVar8 * 2);
          goto LAB_0005f195;
        }
        fVar2 = (param_2 * (float)(int)*(short *)(pbVar4 + uVar8 * 2 + 4) +
                (1.0 - param_2) * (float)(int)*(short *)(pbVar4 + uVar8 * 2)) *
                *(float *)(iVar5 + iVar6) + *local_20;
      }
      *local_20 = fVar2;
    }
LAB_0005f1a6:
    iVar5 = *(int *)(iVar5 + param_3 + 0x28);
    if ((iVar5 != -1) && (param_5 != 0)) {
      *local_20 = *local_20 + *(float *)(param_5 + iVar5 * 4);
    }
    local_20 = local_20 + 1;
    local_24 = local_24 + 1;
    local_c = local_c + 1;
    if (2 < local_c) {
      return;
    }
  } while( true );
}


// R_StudioCalcBoneQuaterion  @ 0005edf8
void R_StudioCalcBoneQuaterion
               (int param_1,undefined4 param_2,int param_3,int param_4,int param_5,
               undefined4 param_6)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  short sVar5;
  int iVar6;
  byte *pbVar7;
  float *pfVar8;
  float *pfVar9;
  float *local_74;
  ushort *local_70;
  float *local_6c;
  float *local_68;
  float *local_64;
  int local_60;
  int local_40;
  float local_3c [6];
  undefined1 local_24 [16];
  undefined1 local_14 [16];
  
  local_40 = 0;
  pfVar1 = local_3c + 3;
  local_60 = 0xc;
  local_6c = (float *)0x0;
  local_70 = (ushort *)(param_4 + 6);
  local_74 = (float *)(param_3 + 0x4c);
  local_68 = pfVar1;
  local_64 = local_3c;
  do {
    if (*local_70 == 0) {
      fVar2 = *local_74;
      *local_68 = fVar2;
      *local_64 = fVar2;
    }
    else {
      pbVar7 = (byte *)(param_4 + (uint)*local_70);
      bVar4 = *pbVar7;
      iVar6 = param_1;
      while( true ) {
        if (pbVar7[1] < bVar4) {
          iVar6 = 0;
        }
        if (iVar6 < (int)(uint)pbVar7[1]) break;
        iVar6 = iVar6 - (uint)pbVar7[1];
        pbVar7 = pbVar7 + (uint)*pbVar7 * 2 + 2;
        bVar4 = *pbVar7;
      }
      if (iVar6 < (int)(uint)*pbVar7) {
        fVar2 = (float)(int)*(short *)(pbVar7 + iVar6 * 2 + 2);
        *local_68 = fVar2;
        if (iVar6 + 1 < (int)(uint)*pbVar7) {
          *local_64 = (float)(int)*(short *)(pbVar7 + iVar6 * 2 + 4);
        }
        else {
          pfVar8 = local_6c;
          pfVar9 = local_3c;
          if ((int)(uint)pbVar7[1] <= iVar6 + 1) {
            sVar5 = *(short *)(pbVar7 + (uint)*pbVar7 * 2 + 4);
            goto LAB_0005ef6a;
          }
LAB_0005ef6d:
          *(float *)((int)pfVar9 + (int)pfVar8) = fVar2;
        }
      }
      else {
        sVar5 = *(short *)(pbVar7 + (uint)*pbVar7 * 2);
        *local_68 = (float)(int)sVar5;
        if ((int)(uint)pbVar7[1] <= iVar6 + 1) {
          sVar5 = *(short *)(pbVar7 + (uint)*pbVar7 * 2 + 4);
LAB_0005ef6a:
          fVar2 = (float)(int)sVar5;
          pfVar8 = local_3c;
          pfVar9 = local_6c;
          goto LAB_0005ef6d;
        }
        *local_64 = (float)(int)sVar5;
      }
      fVar2 = *(float *)(local_60 + param_3 + 0x58);
      fVar3 = *local_74;
      *(float *)((int)local_6c + (int)pfVar1) =
           fVar3 + *(float *)((int)local_6c + (int)pfVar1) * fVar2;
      *(float *)((int)local_6c + (int)local_3c) =
           fVar2 * *(float *)((int)local_6c + (int)local_3c) + fVar3;
    }
    iVar6 = *(int *)(local_60 + param_3 + 0x28);
    if (iVar6 != -1) {
      fVar2 = *(float *)(param_5 + iVar6 * 4);
      *(float *)((int)local_6c + (int)pfVar1) = *(float *)((int)local_6c + (int)pfVar1) + fVar2;
      *(float *)((int)local_6c + (int)local_3c) = fVar2 + *(float *)((int)local_6c + (int)local_3c);
    }
    local_74 = local_74 + 1;
    local_60 = local_60 + 4;
    local_64 = local_64 + 1;
    local_68 = local_68 + 1;
    local_6c = local_6c + 1;
    local_70 = local_70 + 1;
    local_40 = local_40 + 1;
    if (2 < local_40) {
      iVar6 = VectorCompare(pfVar1,local_3c);
      if (iVar6 == 0) {
        AngleQuaternion(pfVar1,local_14);
        AngleQuaternion(local_3c,local_24);
        QuaternionSlerp(local_14,local_24,param_2,param_6);
      }
      else {
        AngleQuaternion(pfVar1,param_6);
      }
      return;
    }
  } while( true );
}


// R_StudioComputeBounds  @ 00060d20
undefined4 R_StudioComputeBounds(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint local_ac;
  uint *local_a4;
  int *local_a0;
  uint *local_9c;
  int *local_98;
  int local_94;
  int local_60;
  int local_5c;
  int local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [12];
  
  local_48 = 0;
  local_44 = 0;
  local_50 = 0;
  local_ac = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  iVar4 = param_1 + *(int *)(param_1 + 0xd0);
  uVar1 = *(uint *)(param_1 + 0xcc);
  if (0 < (int)uVar1) {
    piVar2 = (int *)(iVar4 + 0x40);
    uVar3 = uVar1 & 3;
    if (uVar3 != 0) {
      if (1 < uVar3) {
        if (2 < uVar3) {
          local_50 = *(int *)(iVar4 + 0x40);
          piVar2 = (int *)(iVar4 + 0x8c);
        }
        local_ac = (uint)(2 < uVar3);
        local_50 = local_50 + *piVar2;
        piVar2 = piVar2 + 0x13;
        local_ac = local_ac + 1;
      }
      local_50 = local_50 + *piVar2;
      piVar2 = piVar2 + 0x13;
      local_ac = local_ac + 1;
      if ((int)uVar1 <= (int)local_ac) goto LAB_00060e51;
    }
    do {
      local_50 = local_50 + *piVar2 + piVar2[0x13] + piVar2[0x26] + piVar2[0x39];
      piVar2 = piVar2 + 0x4c;
      local_ac = local_ac + 4;
    } while ((int)local_ac < (int)uVar1);
  }
LAB_00060e51:
  local_4c = 0;
  iVar4 = iVar4 + *(int *)(param_1 + 0xcc) * 0x4c;
  if (0 < local_50) {
    local_a0 = (int *)(iVar4 + 0x58);
    local_a4 = (uint *)(iVar4 + 0x50);
    do {
      iVar6 = 0;
      uVar1 = *local_a4;
      iVar4 = param_1 + *local_a0;
      if (0 < (int)uVar1) {
        uVar3 = uVar1 & 3;
        if (uVar3 != 0) {
          if (1 < uVar3) {
            if (2 < uVar3) {
              R_StudioBoundVertex(&local_34,&local_40,&local_44,iVar4);
              iVar4 = iVar4 + 0xc;
            }
            R_StudioBoundVertex(&local_34,&local_40,&local_44,iVar4);
            iVar4 = iVar4 + 0xc;
            iVar6 = (2 < uVar3) + 1;
          }
          R_StudioBoundVertex(&local_34,&local_40,&local_44,iVar4);
          iVar4 = iVar4 + 0xc;
          iVar6 = iVar6 + 1;
          if ((int)uVar1 <= iVar6) goto LAB_00060f9c;
        }
        do {
          R_StudioBoundVertex(&local_34,&local_40,&local_44,iVar4);
          R_StudioBoundVertex(&local_34,&local_40,&local_44,iVar4 + 0xc);
          R_StudioBoundVertex(&local_34,&local_40,&local_44,iVar4 + 0x18);
          R_StudioBoundVertex(&local_34,&local_40,&local_44,iVar4 + 0x24);
          iVar4 = iVar4 + 0x30;
          iVar6 = iVar6 + 4;
        } while (iVar6 < (int)uVar1);
      }
LAB_00060f9c:
      local_a0 = local_a0 + 0x1c;
      local_a4 = local_a4 + 0x1c;
      local_4c = local_4c + 1;
    } while (local_4c < local_50);
  }
  local_60 = 0;
  iVar4 = *(int *)(param_1 + 0x90);
  iVar6 = param_1 + *(int *)(param_1 + 0xa8);
  if (0 < *(int *)(param_1 + 0xa4)) {
    local_98 = (int *)(iVar6 + 0x7c);
    local_9c = (uint *)(iVar6 + 0x38);
    do {
      uVar1 = *local_9c;
      local_5c = 0;
      iVar6 = param_1 + *local_98;
      local_94 = param_1 + iVar4;
      if (0 < *(int *)(param_1 + 0x8c)) {
        do {
          iVar5 = 0;
          if (0 < (int)uVar1) {
            uVar3 = uVar1 & 3;
            if (uVar3 != 0) {
              if (1 < uVar3) {
                if (2 < uVar3) {
                  R_StudioCalcBonePosition(0,0,local_94,iVar6,0,local_10);
                  R_StudioBoundBone(&local_1c,&local_28,&local_48,local_10);
                }
                R_StudioCalcBonePosition((uint)(2 < uVar3),0,local_94,iVar6,0,local_10);
                R_StudioBoundBone(&local_1c,&local_28,&local_48,local_10);
                iVar5 = (2 < uVar3) + 1;
              }
              R_StudioCalcBonePosition(iVar5,0,local_94,iVar6,0,local_10);
              R_StudioBoundBone(&local_1c,&local_28,&local_48,local_10);
              iVar5 = iVar5 + 1;
              if ((int)uVar1 <= iVar5) goto LAB_00061201;
            }
            do {
              R_StudioCalcBonePosition(iVar5,0,local_94,iVar6,0,local_10);
              R_StudioBoundBone(&local_1c,&local_28,&local_48,local_10);
              R_StudioCalcBonePosition(iVar5 + 1,0,local_94,iVar6,0,local_10);
              R_StudioBoundBone(&local_1c,&local_28,&local_48,local_10);
              R_StudioCalcBonePosition(iVar5 + 2,0,local_94,iVar6,0,local_10);
              R_StudioBoundBone(&local_1c,&local_28,&local_48,local_10);
              R_StudioCalcBonePosition(iVar5 + 3,0,local_94,iVar6,0,local_10);
              R_StudioBoundBone(&local_1c,&local_28,&local_48,local_10);
              iVar5 = iVar5 + 4;
            } while (iVar5 < (int)uVar1);
          }
LAB_00061201:
          local_5c = local_5c + 1;
          local_94 = local_94 + 0x70;
        } while (local_5c < *(int *)(param_1 + 0x8c));
      }
      R_StudioAccumulateBoneVerts(&local_34,&local_40,&local_44,&local_1c,&local_28,&local_48);
      local_98 = local_98 + 0x2c;
      local_9c = local_9c + 0x2c;
      local_60 = local_60 + 1;
    } while (local_60 < *(int *)(param_1 + 0xa4));
  }
  *param_2 = local_34;
  param_2[1] = local_30;
  param_2[2] = local_2c;
  *param_3 = local_40;
  param_3[1] = local_3c;
  param_3[2] = local_38;
  return 1;
}


// R_StudioHull  @ 0005fd40
undefined4 *
R_StudioHull(undefined4 param_1,undefined4 param_2,undefined4 param_3,float *param_4,
            undefined4 param_5,float *param_6,undefined4 param_7,undefined4 param_8,
            undefined4 *param_9)

{
  int iVar1;
  undefined4 *puVar2;
  int local_5c;
  float *local_58;
  int local_54;
  float *local_50;
  int local_4c;
  float *local_48;
  int local_44;
  float *local_40;
  int local_3c;
  float *local_38;
  int local_34;
  float *local_30;
  int local_2c;
  undefined4 *local_28;
  int local_18;
  float local_10;
  float local_c;
  float local_8;
  
  SV_InitStudioHull();
  if (((byte)((float)r_cachestudio._12_4_ < 0.0 |
              (byte)((ushort)((ushort)NAN((float)r_cachestudio._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)r_cachestudio._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) ||
     (iVar1 = R_CheckStudioCache(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8),
     iVar1 == 0)) {
    pstudiohdr = Mod_Extradata(param_1);
    local_8 = param_4[2];
    local_10 = -*param_4;
    local_c = param_4[1];
    SV_StudioSetupBones(param_1,param_2,param_3,&local_10,param_5,param_7,param_8,0xffffffff);
    local_18 = 0;
    puVar2 = (undefined4 *)(pstudiohdr + *(int *)(pstudiohdr + 0xa0));
    if (0 < *(int *)(pstudiohdr + 0x9c)) {
      local_2c = 0;
      local_30 = (float *)(studio_planes + 0x70);
      local_34 = 100;
      local_38 = (float *)(studio_planes + 0x5c);
      local_3c = 0x50;
      local_40 = (float *)(studio_planes + 0x48);
      local_44 = 0x3c;
      local_48 = (float *)(studio_planes + 0x34);
      local_4c = 0x28;
      local_50 = (float *)(studio_planes + 0x20);
      local_54 = 0x14;
      local_58 = (float *)(studio_planes + 0xc);
      local_5c = 0;
      local_28 = puVar2;
      do {
        *(undefined4 *)(studio_hull_hitgroup + local_18 * 4) =
             *(undefined4 *)((int)puVar2 + local_2c + 4);
        SV_SetStudioHullPlane
                  (studio_planes + local_5c,*local_28,0,
                   *(undefined4 *)((int)puVar2 + local_2c + 0x14));
        SV_SetStudioHullPlane
                  (local_5c + 0xd05b4,*local_28,0,*(undefined4 *)((int)puVar2 + local_2c + 8));
        SV_SetStudioHullPlane
                  (local_5c + 0xd05c8,*local_28,1,*(undefined4 *)((int)puVar2 + local_2c + 0x18));
        SV_SetStudioHullPlane
                  (local_5c + 0xd05dc,*local_28,1,*(undefined4 *)((int)puVar2 + local_2c + 0xc));
        SV_SetStudioHullPlane
                  (local_5c + 0xd05f0,*local_28,2,*(undefined4 *)((int)puVar2 + local_2c + 0x1c));
        SV_SetStudioHullPlane
                  (local_5c + 0xd0604,*local_28,2,*(undefined4 *)((int)puVar2 + local_2c + 0x10));
        *local_58 = ABS(*(float *)(studio_planes + local_5c) * *param_6) +
                    ABS(*(float *)(studio_planes + local_5c + 4) * param_6[1]) +
                    ABS(*(float *)(studio_planes + local_5c + 8) * param_6[2]) + *local_58;
        *local_50 = *local_50 -
                    (ABS(*(float *)(studio_planes + local_54) * *param_6) +
                     ABS(*(float *)(studio_planes + local_54 + 4) * param_6[1]) +
                    ABS(*(float *)(studio_planes + local_54 + 8) * param_6[2]));
        *local_48 = ABS(*(float *)(studio_planes + local_4c) * *param_6) +
                    ABS(*(float *)(studio_planes + local_4c + 4) * param_6[1]) +
                    ABS(*(float *)(studio_planes + local_4c + 8) * param_6[2]) + *local_48;
        *local_40 = *local_40 -
                    (ABS(*(float *)(studio_planes + local_44) * *param_6) +
                     ABS(*(float *)(studio_planes + local_44 + 4) * param_6[1]) +
                    ABS(*(float *)(studio_planes + local_44 + 8) * param_6[2]));
        *local_38 = ABS(*(float *)(studio_planes + local_3c) * *param_6) +
                    ABS(*(float *)(studio_planes + local_3c + 4) * param_6[1]) +
                    ABS(*(float *)(studio_planes + local_3c + 8) * param_6[2]) + *local_38;
        *local_30 = *local_30 -
                    (ABS(*(float *)(studio_planes + local_34) * *param_6) +
                     ABS(*(float *)(studio_planes + local_34 + 4) * param_6[1]) +
                    ABS(*(float *)(studio_planes + local_34 + 8) * param_6[2]));
        local_30 = local_30 + 0x1e;
        local_34 = local_34 + 0x78;
        local_38 = local_38 + 0x1e;
        local_3c = local_3c + 0x78;
        local_40 = local_40 + 0x1e;
        local_44 = local_44 + 0x78;
        local_48 = local_48 + 0x1e;
        local_4c = local_4c + 0x78;
        local_50 = local_50 + 0x1e;
        local_54 = local_54 + 0x78;
        local_58 = local_58 + 0x1e;
        local_5c = local_5c + 0x78;
        local_28 = local_28 + 8;
        local_2c = local_2c + 0x20;
        local_18 = local_18 + 1;
      } while (local_18 < *(int *)(pstudiohdr + 0x9c));
    }
    *param_9 = *(undefined4 *)(pstudiohdr + 0x9c);
    if ((byte)((float)r_cachestudio._12_4_ < 0.0 |
               (byte)((ushort)((ushort)NAN((float)r_cachestudio._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)r_cachestudio._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      R_AddToStudioCache(param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_1,
                         &studio_hull,*(undefined4 *)(pstudiohdr + 0x9c));
    }
  }
  else {
    Q_memcpy(studio_planes,cache_planes + *(int *)(iVar1 + 0x3c) * 0x14,
             (*(int *)(iVar1 + 0x40) * 0x10 - *(int *)(iVar1 + 0x40)) * 8);
    Q_memcpy(&studio_hull,cache_hull + *(int *)(iVar1 + 0x38) * 0x28,*(int *)(iVar1 + 0x40) * 0x28);
    Q_memcpy(studio_hull_hitgroup,cache_hull_hitgroup + *(int *)(iVar1 + 0x38) * 4,
             *(int *)(iVar1 + 0x40) << 2);
    *param_9 = *(undefined4 *)(iVar1 + 0x40);
  }
  return &studio_hull;
}


// R_StudioPlayerBlend  @ 0006039c
void R_StudioPlayerBlend(int param_1,int *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *param_3;
  *param_2 = (int)ROUND(fVar1 * 3.0);
  fVar3 = (float)(int)ROUND(fVar1 * 3.0);
  fVar1 = *(float *)(param_1 + 0x88);
  if ((byte)((fVar1 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar3)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar3) << 0xe) >> 8)) - 1) < 0x40) {
    fVar2 = *(float *)(param_1 + 0x90);
    if (fVar3 <= fVar2) {
      fVar2 = fVar2 - fVar1;
      if ((byte)((0.1 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == 0.1) << 0xe) >> 8)) - 1) < 0x40) {
        *param_2 = (int)ROUND(((fVar3 - fVar1) * 255.0) / fVar2);
      }
      else {
        *param_2 = 0x7f;
      }
      *param_3 = 0.0;
    }
    else {
      *param_3 = *param_3 - fVar2 * 0.33333334;
      *param_2 = 0xff;
    }
  }
  else {
    *param_3 = *param_3 - fVar1 * 0.33333334;
    *param_2 = 0;
  }
  return;
}


// R_StudioSlerpBones  @ 0005f1ec
void R_StudioSlerpBones(undefined4 *param_1,float *param_2,int param_3,float *param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int local_40;
  undefined4 *local_3c;
  undefined4 *local_38;
  undefined4 *local_34;
  float *local_30;
  float *local_2c;
  float *local_28;
  float *local_24;
  float *local_20;
  int local_1c;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  fVar2 = 0.0;
  if (((byte)((0.0 < param_5 | (byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_5 == 0.0) << 0xe) >> 8)) - 1) < 0x40) &&
     (fVar2 = param_5, 1.0 < param_5)) {
    fVar2 = 1.0;
  }
  fVar3 = 1.0 - fVar2;
  local_1c = 0;
  if (0 < *(int *)(pstudiohdr + 0x8c)) {
    local_20 = param_2 + 2;
    local_24 = param_4 + 2;
    local_28 = param_2 + 1;
    local_2c = param_4 + 1;
    local_30 = param_4;
    local_34 = param_1 + 3;
    local_38 = param_1 + 2;
    local_3c = param_1 + 1;
    local_40 = param_3;
    do {
      QuaternionSlerp(param_1,local_40,fVar2,&local_14);
      *param_1 = local_14;
      *local_3c = local_10;
      *local_38 = local_c;
      *local_34 = local_8;
      *param_2 = *local_30 * fVar2 + *param_2 * fVar3;
      *local_28 = *local_2c * fVar2 + *local_28 * fVar3;
      fVar1 = *local_24;
      param_1 = param_1 + 4;
      param_2 = param_2 + 3;
      local_24 = local_24 + 3;
      *local_20 = fVar1 * fVar2 + *local_20 * fVar3;
      local_20 = local_20 + 3;
      local_28 = local_28 + 3;
      local_2c = local_2c + 3;
      local_30 = local_30 + 3;
      local_34 = local_34 + 4;
      local_38 = local_38 + 4;
      local_3c = local_3c + 4;
      local_40 = local_40 + 0x10;
      local_1c = local_1c + 1;
    } while (local_1c < *(int *)(pstudiohdr + 0x8c));
  }
  return;
}


