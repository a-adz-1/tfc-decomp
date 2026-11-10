// R_AddToStudioCache  @ 0008f134
void R_AddToStudioCache(undefined4 param_1,undefined4 param_2,undefined4 *param_3,
                       undefined4 *param_4,undefined4 *param_5,undefined4 param_6,undefined4 param_7
                       ,undefined4 param_8,undefined4 param_9,int param_10)

{
  int iVar1;
  
  if (0x7f < nCurrentHull + param_10) {
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
  Q_memcpy(iVar1 + 0x12f04c,param_6,4);
  Q_memcpy(iVar1 + 0x12f050,param_7,2);
  *(undefined4 *)(rgStudioCache + iVar1 + 0x34) = param_8;
  *(int *)(rgStudioCache + iVar1 + 0x38) = nCurrentHull;
  *(int *)(rgStudioCache + iVar1 + 0x3c) = nCurrentPlane;
  Q_memcpy(cache_hull + nCurrentHull * 0x28,param_9,param_10 * 0x28);
  Q_memcpy(cache_planes + nCurrentPlane * 0x14,studio_planes,param_10 * 0x78);
  Q_memcpy(cache_hull_hitgroup + nCurrentHull * 4,studio_hull_hitgroup,param_10 * 4);
  nCurrentHull = nCurrentHull + param_10;
  nCurrentPlane = nCurrentPlane + param_10 * 6;
  *(int *)(rgStudioCache + iVar1 + 0x40) = param_10;
  return;
}


// R_CheckStudioCache  @ 0008efe0
float * R_CheckStudioCache(int param_1,float param_2,int param_3,undefined4 param_4,
                          undefined4 param_5,undefined4 param_6,undefined4 param_7,
                          undefined4 param_8)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0xf < local_8) {
      return (float *)0x0;
    }
    iVar1 = (r_cachecurrent - local_8 & 0xfU) * 0x44;
    if (((((*(int *)(rgStudioCache + iVar1 + 0x34) == param_1) &&
          (fVar2 = *(float *)(rgStudioCache + iVar1),
          (byte)(param_2 < fVar2 | (byte)((ushort)((ushort)(NAN(param_2) || NAN(fVar2)) << 10) >> 8)
                | (byte)((ushort)((ushort)(param_2 == fVar2) << 0xe) >> 8)) == 0x40)) &&
         (*(int *)(rgStudioCache + iVar1 + 4) == param_3)) &&
        ((iVar3 = VectorCompare(iVar1 + 0x12f028,param_4), iVar3 != 0 &&
         (iVar3 = VectorCompare(iVar1 + 0x12f034,param_5), iVar3 != 0)))) &&
       ((iVar3 = VectorCompare(iVar1 + 0x12f040,param_6), iVar3 != 0 &&
        ((iVar3 = Q_memcmp(iVar1 + 0x12f04c,param_7,4), iVar3 == 0 &&
         (iVar3 = Q_memcmp(iVar1 + 0x12f050,param_8,2), iVar3 == 0)))))) break;
    local_8 = local_8 + 1;
  }
  return (float *)(rgStudioCache + iVar1);
}


// R_ConcatRotations  @ 00079f48
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


// R_ConcatTransforms  @ 0007a158
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


// R_DecalRemoveAll  @ 0005f128
void R_DecalRemoveAll(void)

{
  return;
}


// R_FlushStudioCache  @ 000922a8
void R_FlushStudioCache(void)

{
  R_InitStudioCache();
  return;
}


// R_GetAnim  @ 00090f64
int R_GetAnim(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_c;
  
  iVar2 = *(int *)(param_2 + 0x9c) * 0x68 + *(int *)(pstudiohdr + 0xb0) + pstudiohdr;
  if (*(int *)(param_2 + 0x9c) == 0) {
    iVar2 = pstudiohdr + *(int *)(iVar2 + 100) + *(int *)(param_2 + 0x7c);
  }
  else {
    local_c = *(int *)(param_1 + 0x7c);
    if (local_c == 0) {
      local_c = Mem_Calloc(0x10,4);
      *(int *)(param_1 + 0x7c) = local_c;
    }
    iVar1 = Cache_Check(*(int *)(param_2 + 0x9c) * 4 + local_c);
    if (iVar1 == 0) {
      Con_DPrintf("loading %s\n",iVar2 + 0x20);
      COM_LoadCacheFile(iVar2 + 0x20,*(int *)(param_2 + 0x9c) * 4 + local_c);
    }
    iVar2 = *(int *)(param_2 + 0x7c) + *(int *)(local_c + *(int *)(param_2 + 0x9c) * 4);
  }
  return iVar2;
}


// R_GetStudioBounds  @ 000931f0
undefined4 R_GetStudioBounds(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined1 local_10 [4];
  undefined4 local_c;
  undefined4 *local_8;
  
  local_c = 0;
  *param_2 = vec3_origin;
  param_2[1] = DAT_000f1be0;
  param_2[2] = DAT_000f1be4;
  *param_3 = vec3_origin;
  param_3[1] = DAT_000f1be0;
  param_3[2] = DAT_000f1be4;
  iVar1 = Q_strstr(param_1,"models");
  if (((iVar1 != 0) && (iVar1 = Q_strstr(param_1,&DAT_000e6ec7), iVar1 != 0)) &&
     (iVar1 = FS_Open(param_1,&DAT_000e6ecc), iVar1 != 0)) {
    local_8 = (undefined4 *)FS_GetReadBuffer(iVar1,local_10);
    bVar3 = local_8 == (undefined4 *)0x0;
    if (bVar3) {
      local_8 = (undefined4 *)COM_LoadFile(param_1,5,0);
    }
    if (local_8 != (undefined4 *)0x0) {
      iVar2 = (*LittleLong)(*local_8);
      if (iVar2 == 0x54534449) {
        local_c = R_StudioComputeBounds(local_8,param_2,param_3);
      }
      else {
        COM_FreeFile(local_8);
      }
    }
    if (bVar3) {
      COM_FreeFile(local_8);
    }
    else {
      FS_ReleaseReadBuffer(iVar1,local_8);
    }
    FSMC_HintFileShouldStayInCache(iVar1);
    FS_Close(iVar1);
  }
  return local_c;
}


// R_Init  @ 000c61ac
void R_Init(void)

{
  return;
}


// R_InitSky  @ 000c61c4
void R_InitSky(void)

{
  return;
}


// R_InitStudioCache  @ 00092254
void R_InitStudioCache(void)

{
  Q_memset(rgStudioCache,0,0x440);
  r_cachecurrent = 0;
  nCurrentHull = 0;
  nCurrentPlane = 0;
  return;
}


// R_InitTextures  @ 000c61d4
void R_InitTextures(void)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  undefined1 *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar2 = Hunk_AllocName(0x194,"notexture");
  r_notexture_mip = iVar2;
  *(undefined4 *)(iVar2 + 0x14) = 0x10;
  *(undefined4 *)(iVar2 + 0x10) = 0x10;
  *(undefined4 *)(r_notexture_mip + 0x2c) = 0x40;
  *(int *)(r_notexture_mip + 0x30) = *(int *)(r_notexture_mip + 0x2c) + 0x100;
  *(int *)(r_notexture_mip + 0x34) = *(int *)(r_notexture_mip + 0x30) + 0x40;
  *(int *)(r_notexture_mip + 0x38) = *(int *)(r_notexture_mip + 0x34) + 0x10;
  local_10 = 0;
  do {
    if (3 < local_10) {
      return;
    }
    local_14 = (undefined1 *)(*(int *)(local_10 * 4 + r_notexture_mip + 0x2c) + r_notexture_mip);
    for (local_c = 0; bVar3 = (byte)local_10, local_c < 0x10 >> (bVar3 & 0x1f);
        local_c = local_c + 1) {
      for (local_8 = 0; local_8 < 0x10 >> (bVar3 & 0x1f); local_8 = local_8 + 1) {
        bVar1 = 8 >> (bVar3 & 0x1f) <= local_c;
        if (local_8 < 8 >> (bVar3 & 0x1f)) {
          if (bVar1) goto LAB_000c6334;
LAB_000c6340:
          *local_14 = 0xff;
        }
        else {
          if (bVar1) goto LAB_000c6340;
LAB_000c6334:
          *local_14 = 0;
        }
        local_14 = local_14 + 1;
      }
    }
    local_10 = local_10 + 1;
  } while( true );
}


// R_MarkLeaves  @ 000c61cc
void R_MarkLeaves(void)

{
  return;
}


// R_ResetSvBlending  @ 000933e0
void R_ResetSvBlending(void)

{
  g_pSvBlendingAPI = &svBlending;
  return;
}


// R_SetStackBase  @ 000c6184
void R_SetStackBase(void)

{
  return;
}


// R_StudioAccumulateBoneVerts  @ 00092da4
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


// R_StudioBodyVariations  @ 000922c8
int R_StudioBodyVariations(int param_1)

{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  
  if (*(int *)(param_1 + 0x44) == 3) {
    iVar1 = Mod_Extradata(param_1);
    if (iVar1 == 0) {
      local_14 = 0;
    }
    else {
      local_14 = 1;
      for (local_10 = 0; local_10 < *(int *)(iVar1 + 0xcc); local_10 = local_10 + 1) {
        local_14 = local_14 * *(int *)(*(int *)(iVar1 + 0xd0) + iVar1 + 0x40 + local_10 * 0x4c);
      }
    }
  }
  else {
    local_14 = 0;
  }
  return local_14;
}


// R_StudioBoundBone  @ 00092c80
void R_StudioBoundBone(undefined4 *param_1,undefined4 *param_2,int *param_3,undefined4 *param_4)

{
  float fVar1;
  float fVar2;
  int local_8;
  
  if (*param_3 == 0) {
    *param_1 = *param_4;
    param_1[1] = param_4[1];
    param_1[2] = param_4[2];
    *param_2 = *param_4;
    param_2[1] = param_4[1];
    param_2[2] = param_4[2];
  }
  else {
    for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
      fVar1 = (float)param_4[local_8];
      fVar2 = (float)param_1[local_8];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
        param_1[local_8] = param_4[local_8];
      }
      if ((float)param_2[local_8] < (float)param_4[local_8]) {
        param_2[local_8] = param_4[local_8];
      }
    }
  }
  *param_3 = *param_3 + 1;
  return;
}


// R_StudioBoundVertex  @ 00092b5c
void R_StudioBoundVertex(undefined4 *param_1,undefined4 *param_2,int *param_3,undefined4 *param_4)

{
  float fVar1;
  float fVar2;
  int local_8;
  
  if (*param_3 == 0) {
    *param_1 = *param_4;
    param_1[1] = param_4[1];
    param_1[2] = param_4[2];
    *param_2 = *param_4;
    param_2[1] = param_4[1];
    param_2[2] = param_4[2];
  }
  else {
    for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
      fVar1 = (float)param_4[local_8];
      fVar2 = (float)param_1[local_8];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
        param_1[local_8] = param_4[local_8];
      }
      if ((float)param_2[local_8] < (float)param_4[local_8]) {
        param_2[local_8] = param_4[local_8];
      }
    }
  }
  *param_3 = *param_3 + 1;
  return;
}


// R_StudioCalcBoneAdj  @ 0008fd98
/* WARNING: Removing unreachable block (ram,0x0008fe7f) */
/* WARNING: Removing unreachable block (ram,0x0008feb6) */

void R_StudioCalcBoneAdj(float param_1,int param_2,int param_3,int param_4,byte param_5)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  float local_14;
  int local_10;
  
  iVar1 = *(int *)(pstudiohdr + 0x98) + pstudiohdr;
  for (local_10 = 0; local_10 < *(int *)(pstudiohdr + 0x94); local_10 = local_10 + 1) {
    iVar2 = *(int *)(iVar1 + 0x14 + local_10 * 0x18);
    if (iVar2 < 4) {
      if ((*(ushort *)(iVar1 + 4 + local_10 * 0x18) & 0x8000) == 0) {
        local_14 = ((float)*(byte *)(param_3 + iVar2) * param_1 +
                   (float)*(byte *)(param_4 + iVar2) * (1.0 - param_1)) / 255.0;
        if ((byte)(local_14 < 0.0 | (byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) == 1) {
          local_14 = 0.0;
        }
        if (1.0 < local_14) {
          local_14 = 1.0;
        }
        fVar3 = (1.0 - local_14) * *(float *)(iVar1 + 8 + local_10 * 0x18) +
                local_14 * *(float *)(iVar1 + 0xc + local_10 * 0x18);
      }
      else {
        iVar4 = (uint)*(byte *)(iVar2 + param_3) - (uint)*(byte *)(param_4 + iVar2);
        if (iVar4 < 0) {
          iVar4 = -iVar4;
        }
        if (iVar4 < 0x81) {
          fVar3 = ((float)*(byte *)(param_3 + iVar2) * param_1 +
                  (float)*(byte *)(param_4 + iVar2) * (1.0 - param_1)) * 1.40625 +
                  *(float *)(iVar1 + 8 + local_10 * 0x18);
        }
        else {
          iVar2 = *(byte *)(param_3 + local_10) + 0x80;
          iVar4 = *(byte *)(param_4 + local_10) + 0x80;
          fVar3 = (((float)(iVar2 + (iVar2 >> 8) * -0x100) * param_1 +
                   (float)(iVar4 + (iVar4 >> 8) * -0x100) * (1.0 - param_1)) - 128.0) * 1.40625 +
                  *(float *)(iVar1 + 8 + local_10 * 0x18);
        }
      }
    }
    else {
      local_14 = (float)param_5 / 64.0;
      if (1.0 < local_14) {
        local_14 = 1.0;
      }
      fVar3 = (1.0 - local_14) * *(float *)(iVar1 + 8 + local_10 * 0x18) +
              local_14 * *(float *)(iVar1 + 0xc + local_10 * 0x18);
    }
    switch(*(uint *)(iVar1 + 4 + local_10 * 0x18) & 0x7fff) {
    case 1:
    case 2:
    case 4:
      *(float *)(param_2 + local_10 * 4) = fVar3;
      break;
    case 8:
    case 0x10:
    case 0x20:
      *(float *)(param_2 + local_10 * 4) = fVar3 * 0.017453292;
    }
  }
  return;
}


// R_StudioCalcBonePosition  @ 000909e8
void R_StudioCalcBonePosition
               (int param_1,float param_2,int param_3,int param_4,int param_5,int param_6)

{
  byte *local_10;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    *(undefined4 *)(param_6 + local_8 * 4) = *(undefined4 *)(local_8 * 4 + param_3 + 0x40);
    if (*(short *)(local_8 * 2 + param_4) != 0) {
      local_10 = (byte *)(param_4 + (uint)*(ushort *)(local_8 * 2 + param_4));
      local_c = param_1;
      if (local_10[1] < *local_10) {
        local_c = 0;
      }
      while ((int)(uint)local_10[1] <= local_c) {
        local_c = local_c - (uint)local_10[1];
        local_10 = local_10 + (uint)*local_10 * 2 + 2;
        if (local_10[1] < *local_10) {
          local_c = 0;
        }
      }
      if (local_c < (int)(uint)*local_10) {
        if (local_c + 1 < (int)(uint)*local_10) {
          *(float *)(param_6 + local_8 * 4) =
               *(float *)(local_8 * 4 + param_3 + 0x58) *
               ((float)*(short *)(local_10 + local_c * 2 + 4) * param_2 +
               (1.0 - param_2) * (float)*(short *)(local_10 + local_c * 2 + 2)) +
               *(float *)(param_6 + local_8 * 4);
        }
        else {
          *(float *)(param_6 + local_8 * 4) =
               *(float *)(param_6 + local_8 * 4) +
               (float)*(short *)(local_10 + local_c * 2 + 2) *
               *(float *)(local_8 * 4 + param_3 + 0x58);
        }
      }
      else if (local_c + 1 < (int)(uint)local_10[1]) {
        *(float *)(param_6 + local_8 * 4) =
             *(float *)(param_6 + local_8 * 4) +
             (float)*(short *)(local_10 + (uint)*local_10 * 2) *
             *(float *)(local_8 * 4 + param_3 + 0x58);
      }
      else {
        *(float *)(param_6 + local_8 * 4) =
             *(float *)(local_8 * 4 + param_3 + 0x58) *
             ((float)*(short *)(local_10 + (uint)*local_10 * 2 + 4) * param_2 +
             (1.0 - param_2) * (float)*(short *)(local_10 + (uint)*local_10 * 2)) +
             *(float *)(param_6 + local_8 * 4);
      }
    }
    if ((*(int *)(local_8 * 4 + param_3 + 0x28) != -1) && (param_5 != 0)) {
      *(float *)(param_6 + local_8 * 4) =
           *(float *)(param_6 + local_8 * 4) +
           *(float *)(param_5 + *(int *)(local_8 * 4 + param_3 + 0x28) * 4);
    }
  }
  return;
}


// R_StudioCalcBoneQuaterion  @ 00090494
void R_StudioCalcBoneQuaterion
               (int param_1,undefined4 param_2,int param_3,int param_4,int param_5,
               undefined4 param_6)

{
  float fVar1;
  int iVar2;
  byte *local_48;
  float local_44 [6];
  undefined1 local_2c [16];
  undefined1 local_1c [16];
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    if (*(short *)((local_8 + 3) * 2 + param_4) == 0) {
      fVar1 = *(float *)((local_8 + 3) * 4 + param_3 + 0x40);
      local_44[local_8 + 3] = fVar1;
      local_44[local_8] = fVar1;
    }
    else {
      local_48 = (byte *)(param_4 + (uint)*(ushort *)((local_8 + 3) * 2 + param_4));
      local_c = param_1;
      if (local_48[1] < *local_48) {
        local_c = 0;
      }
      while ((int)(uint)local_48[1] <= local_c) {
        local_c = local_c - (uint)local_48[1];
        local_48 = local_48 + (uint)*local_48 * 2 + 2;
        if (local_48[1] < *local_48) {
          local_c = 0;
        }
      }
      if (local_c < (int)(uint)*local_48) {
        local_44[local_8 + 3] = (float)*(short *)(local_48 + local_c * 2 + 2);
        if (local_c + 1 < (int)(uint)*local_48) {
          local_44[local_8] = (float)*(short *)(local_48 + local_c * 2 + 4);
        }
        else if (local_c + 1 < (int)(uint)local_48[1]) {
          local_44[local_8] = local_44[local_8 + 3];
        }
        else {
          local_44[local_8] = (float)*(short *)(local_48 + (uint)*local_48 * 2 + 4);
        }
      }
      else {
        local_44[local_8 + 3] = (float)*(short *)(local_48 + (uint)*local_48 * 2);
        if (local_c + 1 < (int)(uint)local_48[1]) {
          local_44[local_8] = local_44[local_8 + 3];
        }
        else {
          local_44[local_8] = (float)*(short *)(local_48 + (uint)*local_48 * 2 + 4);
        }
      }
      local_44[local_8 + 3] =
           *(float *)((local_8 + 3) * 4 + param_3 + 0x40) +
           local_44[local_8 + 3] * *(float *)((local_8 + 3) * 4 + param_3 + 0x58);
      local_44[local_8] =
           *(float *)((local_8 + 3) * 4 + param_3 + 0x40) +
           local_44[local_8] * *(float *)((local_8 + 3) * 4 + param_3 + 0x58);
    }
    if (*(int *)((local_8 + 3) * 4 + param_3 + 0x28) != -1) {
      local_44[local_8 + 3] =
           local_44[local_8 + 3] +
           *(float *)(param_5 + *(int *)((local_8 + 3) * 4 + param_3 + 0x28) * 4);
      local_44[local_8] =
           local_44[local_8] +
           *(float *)(param_5 + *(int *)((local_8 + 3) * 4 + param_3 + 0x28) * 4);
    }
  }
  iVar2 = VectorCompare(local_44 + 3,local_44);
  if (iVar2 == 0) {
    AngleQuaternion(local_44 + 3,local_1c);
    AngleQuaternion(local_44,local_2c);
    QuaternionSlerp(local_1c,local_2c,param_2,param_6);
  }
  else {
    AngleQuaternion(local_44 + 3,param_6);
  }
  return;
}


// R_StudioComputeBounds  @ 00092eb8
undefined4 R_StudioComputeBounds(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_54 [12];
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_88 = 0;
  local_8c = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_8 = param_1;
  local_c = *(int *)(param_1 + 0xd0) + param_1;
  local_1c = 0;
  for (local_14 = 0; local_14 < *(int *)(param_1 + 0xcc); local_14 = local_14 + 1) {
    local_1c = local_1c + *(int *)(local_c + 0x40 + local_14 * 0x4c);
  }
  local_48 = local_c + *(int *)(param_1 + 0xcc) * 0x4c;
  local_10 = local_48;
  for (local_18 = 0; local_18 < local_1c; local_18 = local_18 + 1) {
    local_20 = *(int *)(local_10 + 0x50 + local_18 * 0x70);
    local_28 = *(int *)(local_10 + 0x58 + local_18 * 0x70) + param_1;
    for (local_24 = 0; local_24 < local_20; local_24 = local_24 + 1) {
      R_StudioBoundVertex(&local_78,&local_84,&local_8c,local_24 * 0xc + local_28);
    }
  }
  local_2c = *(int *)(local_8 + 0x90) + param_1;
  local_34 = *(int *)(local_8 + 0xa8) + param_1;
  for (local_38 = 0; local_38 < *(int *)(local_8 + 0xa4); local_38 = local_38 + 1) {
    local_44 = *(int *)(local_34 + 0x38 + local_38 * 0xb0);
    local_3c = *(int *)(local_34 + 0x7c + local_38 * 0xb0) + param_1;
    for (local_30 = 0; local_30 < *(int *)(local_8 + 0x8c); local_30 = local_30 + 1) {
      for (local_40 = 0; local_40 < local_44; local_40 = local_40 + 1) {
        R_StudioCalcBonePosition(local_40,0,local_30 * 0x70 + local_2c,local_3c,0,local_54);
        R_StudioBoundBone(&local_60,&local_6c,&local_88,local_54);
      }
    }
    R_StudioAccumulateBoneVerts(&local_78,&local_84,&local_8c,&local_60,&local_6c,&local_88);
  }
  *param_2 = local_78;
  param_2[1] = local_74;
  param_2[2] = local_70;
  *param_3 = local_84;
  param_3[1] = local_80;
  param_3[2] = local_7c;
  return 1;
}


// R_StudioHull  @ 00091930
undefined1 *
R_StudioHull(undefined4 param_1,undefined4 param_2,undefined4 param_3,float *param_4,
            undefined4 param_5,float *param_6,undefined4 param_7,undefined4 param_8,int *param_9,
            undefined4 param_10,int param_11)

{
  int iVar1;
  int local_24;
  float local_1c;
  float local_18;
  float local_14;
  int local_10;
  int local_c;
  int local_8;
  
  SV_InitStudioHull();
  if (((byte)(0.0 < (float)r_cachestudio._12_4_ |
              (byte)((ushort)((ushort)NAN((float)r_cachestudio._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)r_cachestudio._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) ||
     (iVar1 = R_CheckStudioCache(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8),
     iVar1 == 0)) {
    pstudiohdr = Mod_Extradata(param_1);
    local_14 = param_4[2];
    local_1c = -*param_4;
    local_18 = param_4[1];
    (**(code **)(g_pSvBlendingAPI + 4))
              (param_1,param_2,param_3,&local_1c,param_5,param_7,param_8,0xffffffff,param_10);
    local_10 = *(int *)(pstudiohdr + 0xa0) + pstudiohdr;
    local_c = 0;
    for (local_8 = 0; local_8 < *(int *)(pstudiohdr + 0x9c); local_8 = local_8 + 1) {
      if ((param_11 != 1) || (local_8 != 0x15)) {
        *(undefined4 *)(studio_hull_hitgroup + local_8 * 4) =
             *(undefined4 *)(local_10 + 4 + local_8 * 0x20);
        SV_SetStudioHullPlane
                  (studio_planes + local_c * 0x14,*(undefined4 *)(local_10 + local_8 * 0x20),0,
                   *(undefined4 *)(local_10 + 0x14 + local_8 * 0x20));
        SV_SetStudioHullPlane
                  (local_c * 0x14 + 0x130ad4,*(undefined4 *)(local_10 + local_8 * 0x20),0,
                   *(undefined4 *)(local_10 + 8 + local_8 * 0x20));
        SV_SetStudioHullPlane
                  (local_c * 0x14 + 0x130ae8,*(undefined4 *)(local_10 + local_8 * 0x20),1,
                   *(undefined4 *)(local_10 + 0x18 + local_8 * 0x20));
        SV_SetStudioHullPlane
                  (local_c * 0x14 + 0x130afc,*(undefined4 *)(local_10 + local_8 * 0x20),1,
                   *(undefined4 *)(local_10 + 0xc + local_8 * 0x20));
        SV_SetStudioHullPlane
                  (local_c * 0x14 + 0x130b10,*(undefined4 *)(local_10 + local_8 * 0x20),2,
                   *(undefined4 *)(local_10 + 0x1c + local_8 * 0x20));
        SV_SetStudioHullPlane
                  (local_c * 0x14 + 0x130b24,*(undefined4 *)(local_10 + local_8 * 0x20),2,
                   *(undefined4 *)(local_10 + 0x10 + local_8 * 0x20));
        *(float *)(studio_planes + local_c * 0x14 + 0xc) =
             ABS(*(float *)(studio_planes + local_c * 0x14 + 8) * param_6[2]) +
             ABS(*(float *)(studio_planes + local_c * 0x14 + 4) * param_6[1]) +
             ABS(*(float *)(studio_planes + local_c * 0x14) * *param_6) +
             *(float *)(studio_planes + local_c * 0x14 + 0xc);
        *(float *)(studio_planes + (local_c + 1) * 0x14 + 0xc) =
             *(float *)(studio_planes + (local_c + 1) * 0x14 + 0xc) -
             (ABS(*(float *)(studio_planes + (local_c + 1) * 0x14 + 8) * param_6[2]) +
             ABS(*(float *)(studio_planes + (local_c + 1) * 0x14 + 4) * param_6[1]) +
             ABS(*(float *)(studio_planes + (local_c + 1) * 0x14) * *param_6));
        *(float *)(studio_planes + (local_c + 2) * 0x14 + 0xc) =
             ABS(*(float *)(studio_planes + (local_c + 2) * 0x14 + 8) * param_6[2]) +
             ABS(*(float *)(studio_planes + (local_c + 2) * 0x14 + 4) * param_6[1]) +
             ABS(*(float *)(studio_planes + (local_c + 2) * 0x14) * *param_6) +
             *(float *)(studio_planes + (local_c + 2) * 0x14 + 0xc);
        *(float *)(studio_planes + (local_c + 3) * 0x14 + 0xc) =
             *(float *)(studio_planes + (local_c + 3) * 0x14 + 0xc) -
             (ABS(*(float *)(studio_planes + (local_c + 3) * 0x14 + 8) * param_6[2]) +
             ABS(*(float *)(studio_planes + (local_c + 3) * 0x14 + 4) * param_6[1]) +
             ABS(*(float *)(studio_planes + (local_c + 3) * 0x14) * *param_6));
        *(float *)(studio_planes + (local_c + 4) * 0x14 + 0xc) =
             ABS(*(float *)(studio_planes + (local_c + 4) * 0x14 + 8) * param_6[2]) +
             ABS(*(float *)(studio_planes + (local_c + 4) * 0x14 + 4) * param_6[1]) +
             ABS(*(float *)(studio_planes + (local_c + 4) * 0x14) * *param_6) +
             *(float *)(studio_planes + (local_c + 4) * 0x14 + 0xc);
        *(float *)(studio_planes + (local_c + 5) * 0x14 + 0xc) =
             *(float *)(studio_planes + (local_c + 5) * 0x14 + 0xc) -
             (ABS(*(float *)(studio_planes + (local_c + 5) * 0x14 + 8) * param_6[2]) +
             ABS(*(float *)(studio_planes + (local_c + 5) * 0x14 + 4) * param_6[1]) +
             ABS(*(float *)(studio_planes + (local_c + 5) * 0x14) * *param_6));
      }
      local_c = local_c + 6;
    }
    if (param_11 == 1) {
      local_24 = *(int *)(pstudiohdr + 0x9c) + -1;
      *param_9 = local_24;
    }
    else {
      local_24 = *(int *)(pstudiohdr + 0x9c);
      *param_9 = local_24;
    }
    if ((byte)(0.0 < (float)r_cachestudio._12_4_ |
               (byte)((ushort)((ushort)NAN((float)r_cachestudio._12_4_) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)r_cachestudio._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
      R_AddToStudioCache(param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_1,studio_hull
                         ,local_24);
    }
  }
  else {
    Q_memcpy(studio_planes,cache_planes + *(int *)(iVar1 + 0x3c) * 0x14,
             *(int *)(iVar1 + 0x40) * 0x78);
    Q_memcpy(studio_hull,cache_hull + *(int *)(iVar1 + 0x38) * 0x28,*(int *)(iVar1 + 0x40) * 0x28);
    Q_memcpy(studio_hull_hitgroup,cache_hull_hitgroup + *(int *)(iVar1 + 0x38) * 4,
             *(int *)(iVar1 + 0x40) * 4);
    *param_9 = *(int *)(iVar1 + 0x40);
  }
  return studio_hull;
}


// R_StudioPlayerBlend  @ 00092374
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void R_StudioPlayerBlend(int param_1,int *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  
  *param_2 = (int)ROUND(*param_3 * 3.0);
  fVar2 = (float)*param_2;
  fVar1 = *(float *)(param_1 + 0x88);
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
    *param_3 = *param_3 - *(float *)(param_1 + 0x88) / 3.0;
    *param_2 = 0;
  }
  else if ((float)*param_2 <= *(float *)(param_1 + 0x90)) {
    if (0.1 <= *(float *)(param_1 + 0x90) - *(float *)(param_1 + 0x88)) {
      *param_2 = (int)ROUND((_FUN_000e6ea8 * ((float)*param_2 - *(float *)(param_1 + 0x88))) /
                            (*(float *)(param_1 + 0x90) - *(float *)(param_1 + 0x88)));
    }
    else {
      *param_2 = 0x7f;
    }
    *param_3 = 0.0;
  }
  else {
    *param_3 = *param_3 - *(float *)(param_1 + 0x90) / 3.0;
    *param_2 = 0xff;
  }
  return;
}


// R_StudioSlerpBones  @ 00090d5c
void R_StudioSlerpBones(int param_1,int param_2,int param_3,int param_4,float param_5)

{
  float fVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if (0.0 <= param_5) {
    if ((byte)(1.0 < param_5 | (byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_5 == 1.0) << 0xe) >> 8)) == 1) {
      param_5 = 1.0;
    }
  }
  else {
    param_5 = 0.0;
  }
  fVar1 = 1.0 - param_5;
  for (local_8 = 0; local_8 < *(int *)(pstudiohdr + 0x8c); local_8 = local_8 + 1) {
    QuaternionSlerp(local_8 * 0x10 + param_1,local_8 * 0x10 + param_3,param_5,&local_18);
    *(undefined4 *)(param_1 + local_8 * 0x10) = local_18;
    *(undefined4 *)(local_8 * 0x10 + param_1 + 4) = local_14;
    *(undefined4 *)(local_8 * 0x10 + param_1 + 8) = local_10;
    *(undefined4 *)(local_8 * 0x10 + param_1 + 0xc) = local_c;
    *(float *)(param_2 + local_8 * 0xc) =
         *(float *)(param_4 + local_8 * 0xc) * param_5 + *(float *)(param_2 + local_8 * 0xc) * fVar1
    ;
    *(float *)(local_8 * 0xc + param_2 + 4) =
         *(float *)(local_8 * 0xc + param_4 + 4) * param_5 +
         *(float *)(local_8 * 0xc + param_2 + 4) * fVar1;
    *(float *)(local_8 * 0xc + param_2 + 8) =
         *(float *)(local_8 * 0xc + param_4 + 8) * param_5 +
         *(float *)(local_8 * 0xc + param_2 + 8) * fVar1;
  }
  return;
}


