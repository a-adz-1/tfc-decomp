// R_AddToStudioCache  @ 0805fb00
void R_AddToStudioCache(undefined4 param_1,undefined4 param_2,undefined4 *param_3,
                       undefined4 *param_4,undefined4 *param_5,undefined4 *param_6,
                       undefined2 *param_7,undefined4 param_8,void *param_9,int param_10)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (0x7f < param_10 + nCurrentHull) {
    R_FlushStudioCache();
  }
  r_cachecurrent = r_cachecurrent + 1;
  uVar3 = r_cachecurrent & 0xf;
  iVar2 = uVar3 * 0x44;
  (&rgStudioCache)[uVar3 * 0x11] = param_1;
  (&DAT_080bd384)[uVar3 * 0x11] = param_2;
  *(undefined4 *)(&DAT_080bd388 + iVar2) = *param_3;
  *(undefined4 *)(&DAT_080bd38c + iVar2) = param_3[1];
  *(undefined4 *)(&DAT_080bd390 + iVar2) = param_3[2];
  *(undefined4 *)(&DAT_080bd394 + iVar2) = *param_4;
  *(undefined4 *)(&DAT_080bd398 + iVar2) = param_4[1];
  *(undefined4 *)(&DAT_080bd39c + iVar2) = param_4[2];
  *(undefined4 *)(&DAT_080bd3a0 + iVar2) = *param_5;
  *(undefined4 *)(&DAT_080bd3a4 + iVar2) = param_5[1];
  *(undefined4 *)(&DAT_080bd3a8 + iVar2) = param_5[2];
  *(undefined4 *)(&DAT_080bd3ac + iVar2) = *param_6;
  *(undefined2 *)(&DAT_080bd3b0 + iVar2) = *param_7;
  *(undefined4 *)(&DAT_080bd3b4 + iVar2) = param_8;
  iVar1 = nCurrentHull;
  *(int *)(&DAT_080bd3b8 + iVar2) = nCurrentHull;
  *(int *)(&DAT_080bd3bc + iVar2) = nCurrentPlane;
  memcpy(cache_hull + iVar1 * 0x28,param_9,param_10 * 0x28);
  memcpy(cache_planes + nCurrentPlane * 0x14,&studio_planes,param_10 * 0x78);
  memcpy(cache_hull_hitgroup + nCurrentHull * 4,studio_hull_hitgroup,param_10 * 4);
  nCurrentHull = nCurrentHull + param_10;
  nCurrentPlane = nCurrentPlane + param_10 * 6;
  *(int *)(&DAT_080bd3c0 + iVar2) = param_10;
  return;
}


// R_CheckStudioCache  @ 0805fa10
undefined4 *
R_CheckStudioCache(int param_1,float param_2,int param_3,undefined4 param_4,undefined4 param_5,
                  undefined4 param_6,char *param_7,char *param_8)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  int local_8;
  
  local_8 = 0;
  do {
    uVar2 = r_cachecurrent - local_8 & 0xf;
    iVar3 = uVar2 * 0x44;
    if ((((*(int *)(&DAT_080bd3b4 + iVar3) == param_1) &&
         ((byte)((byte)((ushort)((ushort)(NAN(param_2) || NAN((float)(&rgStudioCache)[uVar2 * 0x11])
                                         ) << 10) >> 8) |
                (byte)((ushort)((ushort)(param_2 == (float)(&rgStudioCache)[uVar2 * 0x11]) << 0xe)
                      >> 8)) == 0x40)) && ((&DAT_080bd384)[uVar2 * 0x11] == param_3)) &&
       (((iVar1 = VectorCompare(&DAT_080bd388 + iVar3,param_4), iVar1 != 0 &&
         (iVar1 = VectorCompare(&DAT_080bd394 + iVar3,param_5), iVar1 != 0)) &&
        (iVar1 = VectorCompare(&DAT_080bd3a0 + iVar3,param_6), iVar1 != 0)))) {
      iVar1 = 4;
      bVar6 = true;
      pcVar4 = &DAT_080bd3ac + iVar3;
      pcVar5 = param_7;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        iVar1 = 2;
        bVar6 = true;
        pcVar4 = &DAT_080bd3b0 + iVar3;
        pcVar5 = param_8;
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar6 = *pcVar4 == *pcVar5;
          pcVar4 = pcVar4 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (bVar6) {
          return &rgStudioCache + uVar2 * 0x11;
        }
      }
    }
    local_8 = local_8 + 1;
    if (0xf < local_8) {
      return (undefined4 *)0x0;
    }
  } while( true );
}


// R_ConcatRotations  @ 08062220
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


// R_ConcatTransforms  @ 08062310
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


// R_DecalRemoveAll  @ 0808d2f0
void R_DecalRemoveAll(void)

{
  return;
}


// R_FlushStudioCache  @ 080611e0
void R_FlushStudioCache(void)

{
  R_InitStudioCache();
  return;
}


// R_GetAnim  @ 080606c0
int R_GetAnim(int param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  iVar1 = pstudiohdr + *(int *)(pstudiohdr + 0xb0) + *(int *)(param_2 + 0x9c) * 0x68;
  if (*(int *)(param_2 + 0x9c) == 0) {
    iVar1 = pstudiohdr + *(int *)(iVar1 + 100) + *(int *)(param_2 + 0x7c);
  }
  else {
    pvVar2 = *(void **)(param_1 + 0x7c);
    if (pvVar2 == (void *)0x0) {
      pvVar2 = calloc(0x10,4);
      *(void **)(param_1 + 0x7c) = pvVar2;
    }
    iVar3 = Cache_Check((void *)(*(int *)(param_2 + 0x9c) * 4 + (int)pvVar2));
    if (iVar3 == 0) {
      iVar1 = iVar1 + 0x20;
      Con_DPrintf("loading %s\n",iVar1);
      COM_LoadCacheFile(iVar1,(void *)(*(int *)(param_2 + 0x9c) * 4 + (int)pvVar2));
    }
    iVar1 = *(int *)(param_2 + 0x7c) + *(int *)((int)pvVar2 + *(int *)(param_2 + 0x9c) * 4);
  }
  return iVar1;
}


// R_Init  @ 0808d290
void R_Init(void)

{
  return;
}


// R_InitSky  @ 0808d2c0
void R_InitSky(void)

{
  return;
}


// R_InitStudioCache  @ 080611a0
void R_InitStudioCache(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &rgStudioCache;
  for (iVar1 = 0x110; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  r_cachecurrent = 0;
  nCurrentHull = 0;
  nCurrentPlane = 0;
  return;
}


// R_InitTextures  @ 0808d4e0
void R_InitTextures(void)

{
  return;
}


// R_MarkLeaves  @ 0808d2d0
void R_MarkLeaves(void)

{
  return;
}


// R_SetStackBase  @ 0808d240
void R_SetStackBase(void)

{
  return;
}


// R_StudioBodyVariations  @ 080611f0
int R_StudioBodyVariations(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0x44) == 3) && (iVar1 = Mod_Extradata(param_1), iVar1 != 0)) {
    iVar2 = 1;
    iVar3 = 0;
    if (0 < *(int *)(iVar1 + 0xcc)) {
      do {
        iVar2 = iVar2 * *(int *)(iVar1 + *(int *)(iVar1 + 0xd0) + 0x40 + iVar3 * 0x4c);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(iVar1 + 0xcc));
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// R_StudioCalcBoneAdj  @ 0805ffc0
void R_StudioCalcBoneAdj(float param_1,int param_2,int param_3,int param_4,byte param_5)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = pstudiohdr + *(int *)(pstudiohdr + 0x98);
  iVar6 = 0;
  if (0 < *(int *)(pstudiohdr + 0x94)) {
    do {
      iVar1 = *(int *)(iVar7 + 0x14 + iVar6 * 0x18);
      if (iVar1 < 4) {
        if (-1 < *(short *)(iVar7 + 4 + iVar6 * 0x18)) {
          fVar2 = ((1.0 - param_1) * (float)*(byte *)(iVar1 + param_4) +
                  param_1 * (float)*(byte *)(iVar1 + param_3)) / 255.0;
          if (fVar2 < 0.0) {
            fVar2 = 0.0;
          }
          goto LAB_0806013c;
        }
        iVar4 = (uint)*(byte *)(iVar1 + param_3) - (uint)*(byte *)(iVar1 + param_4);
        if (iVar4 < 0) {
          iVar4 = -iVar4;
        }
        if (iVar4 < 0x81) {
          fVar2 = (1.0 - param_1) * (float)*(byte *)(iVar1 + param_4) +
                  param_1 * (float)*(byte *)(iVar1 + param_3);
        }
        else {
          uVar3 = *(byte *)(iVar6 + param_3) + 0x80;
          uVar5 = *(byte *)(iVar6 + param_4) + 0x80;
          fVar2 = ((1.0 - param_1) * (float)(int)(uVar5 - (uVar5 & 0x300)) +
                  param_1 * (float)(int)(uVar3 - (uVar3 & 0x300))) - 128.0;
        }
        fVar2 = fVar2 * 1.40625 + *(float *)(iVar7 + 8 + iVar6 * 0x18);
      }
      else {
        fVar2 = (float)param_5 * 0.015625;
LAB_0806013c:
        if ((byte)(1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 1.0) << 0xe) >> 8)) == 1) {
          fVar2 = 1.0;
        }
        fVar2 = fVar2 * *(float *)(iVar7 + 0xc + iVar6 * 0x18) +
                (1.0 - fVar2) * *(float *)(iVar7 + 8 + iVar6 * 0x18);
      }
      switch(*(uint *)(iVar7 + 4 + iVar6 * 0x18) & 0x7fff) {
      case 1:
      case 2:
      case 4:
        *(float *)(param_2 + iVar6 * 4) = fVar2;
        break;
      default:
        break;
      case 8:
      case 0x10:
      case 0x20:
        *(float *)(param_2 + iVar6 * 4) = fVar2 * 0.017453292;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(pstudiohdr + 0x94));
  }
  return;
}


// R_StudioCalcBonePosition  @ 08060460
void R_StudioCalcBonePosition
               (int param_1,float param_2,int param_3,int param_4,int param_5,int param_6)

{
  short sVar1;
  float fVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  do {
    *(undefined4 *)(param_6 + iVar6 * 4) = *(undefined4 *)(param_3 + 0x40 + iVar6 * 4);
    if (*(short *)(iVar6 * 2 + param_4) != 0) {
      pbVar4 = (byte *)(param_4 + (uint)*(ushort *)(iVar6 * 2 + param_4));
      iVar5 = param_1;
      if (pbVar4[1] < *pbVar4) {
        iVar5 = 0;
      }
      uVar3 = (uint)pbVar4[1];
      if ((int)uVar3 <= iVar5) {
        do {
          iVar5 = iVar5 - uVar3;
          pbVar4 = pbVar4 + (uint)*pbVar4 * 2 + 2;
          if (pbVar4[1] < *pbVar4) {
            iVar5 = 0;
          }
          uVar3 = (uint)pbVar4[1];
        } while ((int)uVar3 <= iVar5);
      }
      if (iVar5 < (int)(uint)*pbVar4) {
        if ((int)(uint)*pbVar4 <= iVar5 + 1) {
          sVar1 = *(short *)(pbVar4 + iVar5 * 2 + 2);
          goto LAB_08060578;
        }
        fVar2 = (1.0 - param_2) * (float)(int)*(short *)(pbVar4 + iVar5 * 2 + 2);
        sVar1 = *(short *)(pbVar4 + iVar5 * 2 + 4);
LAB_08060544:
        fVar2 = (param_2 * (float)(int)sVar1 + fVar2) * *(float *)(param_3 + 0x58 + iVar6 * 4) +
                *(float *)(param_6 + iVar6 * 4);
      }
      else {
        if ((int)(uint)pbVar4[1] <= iVar5 + 1) {
          fVar2 = (1.0 - param_2) * (float)(int)*(short *)(pbVar4 + (uint)*pbVar4 * 2);
          sVar1 = *(short *)(pbVar4 + (uint)*pbVar4 * 2 + 4);
          goto LAB_08060544;
        }
        sVar1 = *(short *)(pbVar4 + (uint)*pbVar4 * 2);
LAB_08060578:
        fVar2 = (float)(int)sVar1 * *(float *)(param_3 + 0x58 + iVar6 * 4) +
                *(float *)(param_6 + iVar6 * 4);
      }
      *(float *)(param_6 + iVar6 * 4) = fVar2;
    }
    if (*(int *)(iVar6 * 4 + param_3 + 0x28) != -1) {
      *(float *)(param_6 + iVar6 * 4) =
           *(float *)(param_6 + iVar6 * 4) +
           *(float *)(param_5 + *(int *)(iVar6 * 4 + param_3 + 0x28) * 4);
    }
    iVar6 = iVar6 + 1;
    if (2 < iVar6) {
      return;
    }
  } while( true );
}


// R_StudioCalcBoneQuaterion  @ 080601e0
void R_StudioCalcBoneQuaterion
               (int param_1,undefined4 param_2,int param_3,int param_4,int param_5,
               undefined4 param_6)

{
  float fVar1;
  short sVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int local_54;
  float local_3c [6];
  undefined1 local_24 [16];
  undefined1 local_14 [16];
  
  local_54 = 0;
  iVar6 = param_3 + 0x40;
  do {
    if (*(short *)(param_4 + (local_54 + 3) * 2) == 0) {
      fVar1 = *(float *)(iVar6 + (local_54 + 3) * 4);
      local_3c[local_54 + 3] = fVar1;
      local_3c[local_54] = fVar1;
    }
    else {
      pbVar4 = (byte *)(param_4 + (uint)*(ushort *)(param_4 + 6 + local_54 * 2));
      iVar5 = param_1;
      if (pbVar4[1] < *pbVar4) {
        iVar5 = 0;
      }
      uVar3 = (uint)pbVar4[1];
      if ((int)uVar3 <= iVar5) {
        do {
          iVar5 = iVar5 - uVar3;
          pbVar4 = pbVar4 + (uint)*pbVar4 * 2 + 2;
          if (pbVar4[1] < *pbVar4) {
            iVar5 = 0;
          }
          uVar3 = (uint)pbVar4[1];
        } while ((int)uVar3 <= iVar5);
      }
      if (iVar5 < (int)(uint)*pbVar4) {
        local_3c[local_54 + 3] = (float)(int)*(short *)(pbVar4 + iVar5 * 2 + 2);
        if (iVar5 + 1 < (int)(uint)*pbVar4) {
          local_3c[local_54] = (float)(int)*(short *)(pbVar4 + iVar5 * 2 + 4);
        }
        else {
          if ((int)(uint)pbVar4[1] <= iVar5 + 1) goto LAB_08060350;
          local_3c[local_54] = local_3c[local_54 + 3];
        }
      }
      else {
        sVar2 = *(short *)(pbVar4 + (uint)*pbVar4 * 2);
        local_3c[local_54 + 3] = (float)(int)sVar2;
        if (iVar5 + 1 < (int)(uint)pbVar4[1]) {
          local_3c[local_54] = (float)(int)sVar2;
        }
        else {
LAB_08060350:
          local_3c[local_54] = (float)(int)*(short *)(pbVar4 + (uint)*pbVar4 * 2 + 4);
        }
      }
      iVar5 = local_54 * 4 + 0xc;
      local_3c[local_54 + 3] =
           local_3c[local_54 + 3] * *(float *)(iVar5 + param_3 + 0x58) + *(float *)(iVar5 + iVar6);
      local_3c[local_54] =
           local_3c[local_54] * *(float *)(iVar5 + param_3 + 0x58) + *(float *)(iVar5 + iVar6);
    }
    iVar5 = local_54 * 4 + 0xc;
    if (*(int *)(iVar5 + param_3 + 0x28) != -1) {
      iVar5 = *(int *)(iVar5 + param_3 + 0x28);
      local_3c[local_54 + 3] = local_3c[local_54 + 3] + *(float *)(param_5 + iVar5 * 4);
      local_3c[local_54] = local_3c[local_54] + *(float *)(param_5 + iVar5 * 4);
    }
    local_54 = local_54 + 1;
    if (2 < local_54) {
      iVar6 = VectorCompare(local_3c + 3,local_3c);
      if (iVar6 == 0) {
        AngleQuaternion(local_3c + 3,local_14);
        AngleQuaternion(local_3c,local_24);
        QuaternionSlerp(local_14,local_24,param_2,param_6);
      }
      else {
        AngleQuaternion(local_3c + 3,param_6);
      }
      return;
    }
  } while( true );
}


// R_StudioHull  @ 08060d30
undefined4 *
R_StudioHull(undefined4 param_1,undefined4 param_2,undefined4 param_3,float *param_4,
            undefined4 param_5,float *param_6,undefined4 param_7,undefined4 param_8,
            undefined4 *param_9)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_18;
  float local_10;
  float local_c;
  float local_8;
  
  SV_InitStudioHull();
  if (((byte)(0.0 < (float)r_cachestudio._12_4_ |
              (byte)((ushort)((ushort)NAN((float)r_cachestudio._12_4_) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)r_cachestudio._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) &&
     (iVar1 = R_CheckStudioCache(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8),
     iVar1 != 0)) {
    memcpy(&studio_planes,cache_planes + *(int *)(iVar1 + 0x3c) * 0x14,
           (*(int *)(iVar1 + 0x40) * 0x10 - *(int *)(iVar1 + 0x40)) * 8);
    memcpy(&studio_hull,cache_hull + *(int *)(iVar1 + 0x38) * 0x28,*(int *)(iVar1 + 0x40) * 0x28);
    memcpy(studio_hull_hitgroup,cache_hull_hitgroup + *(int *)(iVar1 + 0x38) * 4,
           *(int *)(iVar1 + 0x40) * 4);
    *param_9 = *(undefined4 *)(iVar1 + 0x40);
    return &studio_hull;
  }
  pstudiohdr = Mod_Extradata(param_1);
  local_8 = param_4[2];
  local_10 = -*param_4;
  local_c = param_4[1];
  SV_StudioSetupBones(param_1,param_2,param_3,&local_10,param_5,param_7,param_8,0xffffffff);
  iVar1 = pstudiohdr + *(int *)(pstudiohdr + 0xa0);
  local_18 = 0;
  iVar3 = 0;
  if (0 < *(int *)(pstudiohdr + 0x9c)) {
    do {
      iVar2 = local_18 * 0x20;
      *(undefined4 *)(studio_hull_hitgroup + local_18 * 4) = *(undefined4 *)(iVar1 + 4 + iVar2);
      SV_SetStudioHullPlane
                (&studio_planes + iVar3 * 5,*(undefined4 *)(iVar1 + iVar2),0,
                 *(undefined4 *)(iVar1 + 0x14 + iVar2));
      SV_SetStudioHullPlane
                (&DAT_080bee34 + iVar3 * 5,*(undefined4 *)(iVar1 + iVar2),0,
                 *(undefined4 *)(iVar1 + 8 + iVar2));
      SV_SetStudioHullPlane
                (&DAT_080bee48 + iVar3 * 5,*(undefined4 *)(iVar1 + iVar2),1,
                 *(undefined4 *)(iVar1 + 0x18 + iVar2));
      SV_SetStudioHullPlane
                (&DAT_080bee5c + iVar3 * 5,*(undefined4 *)(iVar1 + iVar2),1,
                 *(undefined4 *)(iVar1 + 0xc + iVar2));
      SV_SetStudioHullPlane
                (&DAT_080bee70 + iVar3 * 5,*(undefined4 *)(iVar1 + iVar2),2,
                 *(undefined4 *)(iVar1 + 0x1c + iVar2));
      SV_SetStudioHullPlane
                (&DAT_080bee84 + iVar3 * 5,*(undefined4 *)(iVar1 + iVar2),2,
                 *(undefined4 *)(iVar1 + 0x10 + iVar2));
      (&DAT_080bee2c)[iVar3 * 5] =
           ABS((float)(&DAT_080bee28)[iVar3 * 5] * param_6[2]) +
           ABS((float)(&DAT_080bee24)[iVar3 * 5] * param_6[1]) +
           ABS((float)(&studio_planes)[iVar3 * 5] * *param_6) + (float)(&DAT_080bee2c)[iVar3 * 5];
      iVar2 = iVar3 * 5 + 5;
      (&DAT_080bee2c)[iVar2] =
           (float)(&DAT_080bee2c)[iVar2] -
           (ABS((float)(&DAT_080bee28)[iVar2] * param_6[2]) +
           ABS((float)(&DAT_080bee24)[iVar2] * param_6[1]) +
           ABS((float)(&studio_planes)[iVar2] * *param_6));
      iVar2 = iVar3 * 5 + 10;
      (&DAT_080bee2c)[iVar2] =
           ABS((float)(&DAT_080bee28)[iVar2] * param_6[2]) +
           ABS((float)(&DAT_080bee24)[iVar2] * param_6[1]) +
           ABS((float)(&studio_planes)[iVar2] * *param_6) + (float)(&DAT_080bee2c)[iVar2];
      iVar2 = iVar3 * 5 + 0xf;
      (&DAT_080bee2c)[iVar2] =
           (float)(&DAT_080bee2c)[iVar2] -
           (ABS((float)(&DAT_080bee28)[iVar2] * param_6[2]) +
           ABS((float)(&DAT_080bee24)[iVar2] * param_6[1]) +
           ABS((float)(&studio_planes)[iVar2] * *param_6));
      iVar2 = iVar3 * 5 + 0x14;
      (&DAT_080bee2c)[iVar2] =
           ABS((float)(&DAT_080bee28)[iVar2] * param_6[2]) +
           ABS((float)(&DAT_080bee24)[iVar2] * param_6[1]) +
           ABS((float)(&studio_planes)[iVar2] * *param_6) + (float)(&DAT_080bee2c)[iVar2];
      iVar2 = iVar3 * 5 + 0x19;
      (&DAT_080bee2c)[iVar2] =
           (float)(&DAT_080bee2c)[iVar2] -
           (ABS((float)(&DAT_080bee28)[iVar2] * param_6[2]) +
           ABS((float)(&DAT_080bee24)[iVar2] * param_6[1]) +
           ABS((float)(&studio_planes)[iVar2] * *param_6));
      iVar3 = iVar3 + 6;
      local_18 = local_18 + 1;
    } while (local_18 < *(int *)(pstudiohdr + 0x9c));
  }
  *param_9 = *(undefined4 *)(pstudiohdr + 0x9c);
  if ((byte)(0.0 < (float)r_cachestudio._12_4_ |
             (byte)((ushort)((ushort)NAN((float)r_cachestudio._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)r_cachestudio._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    R_AddToStudioCache(param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_1,&studio_hull,
                       *(undefined4 *)(pstudiohdr + 0x9c));
  }
  return &studio_hull;
}


// R_StudioPlayerBlend  @ 08061250
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
      *param_2 = (int)ROUND((((float)*param_2 - *(float *)(param_1 + 0x88)) * 255.0) /
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


// R_StudioSlerpBones  @ 080605d0
void R_StudioSlerpBones(int param_1,int param_2,int param_3,int param_4,float param_5)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
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
  iVar5 = 0;
  if (0 < *(int *)(pstudiohdr + 0x8c)) {
    do {
      puVar4 = (undefined4 *)(iVar5 * 0x10 + param_1);
      QuaternionSlerp(puVar4,param_3 + iVar5 * 0x10,param_5,&local_14);
      *puVar4 = local_14;
      puVar4[1] = local_10;
      puVar4[2] = local_c;
      puVar4[3] = local_8;
      iVar2 = iVar5 * 0xc;
      *(float *)(param_2 + iVar2) =
           param_5 * *(float *)(param_4 + iVar2) + fVar1 * *(float *)(param_2 + iVar2);
      iVar3 = iVar2 + param_2;
      *(float *)(iVar3 + 4) =
           param_5 * *(float *)(iVar2 + param_4 + 4) + fVar1 * *(float *)(iVar3 + 4);
      *(float *)(iVar3 + 8) =
           param_5 * *(float *)(iVar2 + param_4 + 8) + fVar1 * *(float *)(iVar3 + 8);
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(pstudiohdr + 0x8c));
  }
  return;
}


