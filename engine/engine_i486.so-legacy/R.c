// R_AddToStudioCache  @ 00092790
void R_AddToStudioCache(float frame,int sequence,vec_t *angles,vec_t *origin,vec_t *size,
                       uchar *controller,uchar *pblending,model_t *pModel,hull_t *pHulls,
                       int numhulls)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
                    /* Unresolved local var: r_studiocache_t * p@[???] */
  if (nCurrentHull + numhulls < 0x80) {
    r_cachecurrent = r_cachecurrent + 1;
    uVar3 = r_cachecurrent & 0xf;
  }
  else {
    Q_memset(rgStudioCache,0,0x440);
    uVar3 = 1;
    nCurrentPlane = 0;
    r_cachecurrent = 1;
    nCurrentHull = 0;
  }
  rgStudioCache[uVar3].frame = frame;
  rgStudioCache[uVar3].sequence = sequence;
  rgStudioCache[uVar3].angles[0] = *angles;
  rgStudioCache[uVar3].angles[1] = angles[1];
  rgStudioCache[uVar3].angles[2] = angles[2];
  rgStudioCache[uVar3].origin[0] = *origin;
  rgStudioCache[uVar3].origin[1] = origin[1];
  rgStudioCache[uVar3].origin[2] = origin[2];
  rgStudioCache[uVar3].size[0] = *size;
  rgStudioCache[uVar3].size[1] = size[1];
  rgStudioCache[uVar3].size[2] = size[2];
  Q_memcpy(rgStudioCache[uVar3].controller,controller,4);
  Q_memcpy(rgStudioCache[uVar3].blending,pblending,2);
  iVar2 = nCurrentPlane;
  rgStudioCache[uVar3].pModel = pModel;
  iVar1 = nCurrentHull;
  rgStudioCache[uVar3].nStartPlane = iVar2;
  rgStudioCache[uVar3].nStartHull = iVar1;
  Q_memcpy(cache_hull + iVar1,pHulls,numhulls * 0x28);
  Q_memcpy(cache_planes + nCurrentPlane,studio_planes,numhulls * 0x78);
  Q_memcpy(cache_hull_hitgroup + nCurrentHull,studio_hull_hitgroup,numhulls * 4);
  rgStudioCache[uVar3].numhulls = numhulls;
  nCurrentHull = nCurrentHull + numhulls;
  nCurrentPlane = nCurrentPlane + numhulls * 6;
  return;
}


// R_CheckStudioCache  @ 00092670
r_studiocache_t *
R_CheckStudioCache(model_t *pModel,float frame,int sequence,vec_t *angles,vec_t *origin,vec_t *size,
                  uchar *controller,uchar *blending)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: r_studiocache_t * pCached@[???] */
  iVar3 = 0;
  while( true ) {
    uVar1 = r_cachecurrent - iVar3 & 0xf;
    if (((((rgStudioCache[uVar1].pModel == pModel) && (rgStudioCache[uVar1].frame == frame)) &&
         (rgStudioCache[uVar1].sequence == sequence)) &&
        ((iVar2 = VectorCompare(rgStudioCache[uVar1].angles,angles), iVar2 != 0 &&
         (iVar2 = VectorCompare(rgStudioCache[uVar1].origin,origin), iVar2 != 0)))) &&
       ((iVar2 = VectorCompare(rgStudioCache[uVar1].size,size), iVar2 != 0 &&
        ((iVar2 = Q_memcmp(rgStudioCache[uVar1].controller,controller,4), iVar2 == 0 &&
         (iVar2 = Q_memcmp(rgStudioCache[uVar1].blending,blending,2), iVar2 == 0)))))) break;
    iVar3 = iVar3 + 1;
    if (iVar3 == 0x10) {
      return (r_studiocache_t *)0x0;
    }
  }
  return rgStudioCache + uVar1;
}


// R_ConcatRotations  @ 00080a40
void R_ConcatRotations(float (*in1) [3],float (*in2) [3],float (*out) [3])

{
  (*out)[0] = (*in1)[2] * in2[2][0] + (*in1)[1] * in2[1][0] + (*in1)[0] * (*in2)[0];
  (*out)[1] = (*in1)[2] * in2[2][1] + (*in1)[1] * in2[1][1] + (*in1)[0] * (*in2)[1];
  (*out)[2] = (*in1)[2] * in2[2][2] + (*in1)[1] * in2[1][2] + (*in1)[0] * (*in2)[2];
  out[1][0] = in1[1][2] * in2[2][0] + in1[1][1] * in2[1][0] + in1[1][0] * (*in2)[0];
  out[1][1] = in1[1][2] * in2[2][1] + in1[1][1] * in2[1][1] + in1[1][0] * (*in2)[1];
  out[1][2] = in1[1][2] * in2[2][2] + in1[1][1] * in2[1][2] + in1[1][0] * (*in2)[2];
  out[2][0] = in1[2][2] * in2[2][0] + in1[2][1] * in2[1][0] + in1[2][0] * (*in2)[0];
  out[2][1] = in1[2][2] * in2[2][1] + in1[2][1] * in2[1][1] + in1[2][0] * (*in2)[1];
  out[2][2] = in1[2][2] * in2[2][2] + in1[2][1] * in2[1][2] + in1[2][0] * (*in2)[2];
  return;
}


// R_ConcatTransforms  @ 00080b30
void R_ConcatTransforms(float (*in1) [4],float (*in2) [4],float (*out) [4])

{
  (*out)[0] = (*in1)[2] * in2[2][0] + (*in1)[1] * in2[1][0] + (*in1)[0] * (*in2)[0];
  (*out)[1] = (*in1)[2] * in2[2][1] + (*in1)[1] * in2[1][1] + (*in1)[0] * (*in2)[1];
  (*out)[2] = (*in1)[2] * in2[2][2] + (*in1)[1] * in2[1][2] + (*in1)[0] * (*in2)[2];
  (*out)[3] = (*in1)[2] * in2[2][3] + (*in1)[1] * in2[1][3] + (*in1)[0] * (*in2)[3] + (*in1)[3];
  out[1][0] = in1[1][2] * in2[2][0] + in1[1][1] * in2[1][0] + in1[1][0] * (*in2)[0];
  out[1][1] = in1[1][2] * in2[2][1] + in1[1][1] * in2[1][1] + in1[1][0] * (*in2)[1];
  out[1][2] = in1[1][2] * in2[2][2] + in1[1][1] * in2[1][2] + in1[1][0] * (*in2)[2];
  out[1][3] = in1[1][2] * in2[2][3] + in1[1][1] * in2[1][3] + in1[1][0] * (*in2)[3] + in1[1][3];
  out[2][0] = in1[2][2] * in2[2][0] + in1[2][1] * in2[1][0] + in1[2][0] * (*in2)[0];
  out[2][1] = in1[2][2] * in2[2][1] + in1[2][1] * in2[1][1] + in1[2][0] * (*in2)[1];
  out[2][2] = in1[2][2] * in2[2][2] + in1[2][1] * in2[1][2] + in1[2][0] * (*in2)[2];
  out[2][3] = in1[2][2] * in2[2][3] + in1[2][1] * in2[1][3] + in1[2][0] * (*in2)[3] + in1[2][3];
  return;
}


// R_DecalRemoveAll  @ 000683a0
void R_DecalRemoveAll(int textureIndex)

{
  return;
}


// R_FlushStudioCache  @ 00094580
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_FlushStudioCache(void)

{
  Q_memset(rgStudioCache,0,0x440);
  nCurrentHull = 0;
  r_cachecurrent = 0;
  nCurrentPlane = 0;
  return;
}


// R_GetAnim  @ 00093490
mstudioanim_t * R_GetAnim(model_t *psubmodel,mstudioseqdesc_t *pseqdesc)

{
  int iVar1;
  int iVar2;
  studiohdr_t *psVar3;
  int iVar4;
  void *pvVar5;
  char *pcVar6;
  dmodel_t *pdVar7;
  
                    /* Unresolved local var: mstudioseqgroup_t * pseqgroup@[???]
                       Unresolved local var: cache_user_t * paSequences@[???] */
  psVar3 = pstudiohdr;
  iVar1 = pseqdesc->seqgroup;
  iVar2 = pstudiohdr->seqgroupindex;
  if (iVar1 == 0) {
    pcVar6 = pstudiohdr->name + pseqdesc->animindex + -8;
  }
  else {
    pdVar7 = psubmodel->submodels;
    iVar4 = iVar1;
    if (pdVar7 == (dmodel_t *)0x0) {
      pdVar7 = Mem_Calloc(0x10,4);
      psubmodel->submodels = pdVar7;
      iVar4 = pseqdesc->seqgroup;
    }
    pvVar5 = Cache_Check((cache_user_t *)(pdVar7->mins + iVar4));
    if (pvVar5 == (void *)0x0) {
      Con_DPrintf("loading %s\n",psVar3->name + iVar2 + iVar1 * 0x68 + 0x18);
      COM_LoadCacheFile(psVar3->name + iVar2 + iVar1 * 0x68 + 0x18,
                        (cache_user_s *)(pdVar7->mins + pseqdesc->seqgroup));
    }
    pcVar6 = (char *)((int)pdVar7->mins[pseqdesc->seqgroup] + pseqdesc->animindex);
  }
  return (mstudioanim_t *)pcVar6;
}


// R_GetStudioBounds  @ 00095310
int R_GetStudioBounds(char *filename,float *mins,float *maxs)

{
  bool bVar1;
  char *pcVar2;
  FileHandle_t file;
  int32 *pBuffer;
  int32 iVar3;
  int local_34;
  int local_20 [4];
  
                    /* Unresolved local var: char * pBuffer@[???]
                       Unresolved local var: int iret@[???]
                       Unresolved local var: int length@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: qboolean usingReadBuffer@[???] */
  *mins = vec3_origin[0];
  mins[1] = vec3_origin[1];
  mins[2] = vec3_origin[2];
  *maxs = vec3_origin[0];
  maxs[1] = vec3_origin[1];
  maxs[2] = vec3_origin[2];
  pcVar2 = Q_strstr(filename,"models");
  if (pcVar2 == (char *)0x0) {
    return 0;
  }
  pcVar2 = Q_strstr(filename,".mdl");
  if (pcVar2 == (char *)0x0) {
    return 0;
  }
  file = FS_Open(filename,"rb");
  if (file == (FileHandle_t)0x0) {
    return 0;
  }
  pBuffer = FS_GetReadBuffer(file,local_20);
  bVar1 = true;
  if (pBuffer == (int32 *)0x0) {
    pBuffer = (int32 *)COM_LoadFile(filename,5,(int *)0x0);
    if (pBuffer != (int32 *)0x0) {
      bVar1 = false;
      goto LAB_000953cb;
    }
    local_34 = 0;
  }
  else {
LAB_000953cb:
    iVar3 = (*LittleLong)(*pBuffer);
    if (iVar3 == 0x54534449) {
      local_34 = R_StudioComputeBounds((uchar *)pBuffer,mins,maxs);
    }
    else {
      COM_FreeFile(pBuffer);
      local_34 = 0;
    }
    if (bVar1) {
      FS_ReleaseReadBuffer(file,pBuffer);
      goto LAB_0009540f;
    }
  }
  COM_FreeFile(pBuffer);
LAB_0009540f:
  FS_Close(file);
  return local_34;
}


// R_Init  @ 000c7970
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_Init(void)

{
  return;
}


// R_InitSky  @ 000c79a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_InitSky(void)

{
  return;
}


// R_InitStudioCache  @ 00094540
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_InitStudioCache(void)

{
  Q_memset(rgStudioCache,0,0x440);
  r_cachecurrent = 0;
  nCurrentHull = 0;
  nCurrentPlane = 0;
  return;
}


// R_InitTextures  @ 000c79c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_InitTextures(void)

{
  bool bVar1;
  texture_t *ptVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  char *local_24;
  int local_20;
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int m@[???]
                       Unresolved local var: uchar * dest@[???] */
  ptVar2 = Hunk_AllocName(0x194,"notexture");
  local_20 = 0;
  r_notexture_mip = ptVar2;
  ptVar2->height = 0x10;
  ptVar2->width = 0x10;
  ptVar2->offsets[0] = 0x40;
  ptVar2->offsets[1] = 0x140;
  ptVar2->offsets[2] = 0x180;
  ptVar2->offsets[3] = 400;
  do {
    iVar4 = 0;
    iVar6 = 8 >> ((byte)local_20 & 0x1f);
    local_24 = ptVar2->name + ptVar2->offsets[local_20] + 1;
    do {
      iVar3 = 0;
      pcVar5 = local_24;
      do {
        bVar1 = iVar3 < iVar6;
        iVar3 = iVar3 + 1;
        pcVar5[-1] = -(bVar1 == iVar4 < iVar6);
        pcVar5 = pcVar5 + 1;
      } while (iVar3 != 0x10 >> ((byte)local_20 & 0x1f));
      iVar4 = iVar4 + 1;
      local_24 = local_24 + iVar3;
    } while (iVar4 != iVar3);
    local_20 = local_20 + 1;
    ptVar2 = r_notexture_mip;
  } while (local_20 != 4);
  return;
}


// R_MarkLeaves  @ 000c79b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_MarkLeaves(void)

{
  return;
}


// R_ResetSvBlending  @ 000954a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_ResetSvBlending(void)

{
  g_pSvBlendingAPI = &svBlending;
  return;
}


// R_SetStackBase  @ 000c7920
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_SetStackBase(void)

{
  return;
}


// R_StudioAccumulateBoneVerts  @ 00094f10
void R_StudioAccumulateBoneVerts
               (vec_t *mins,vec_t *maxs,int *vertcount,vec_t *bone_mins,vec_t *bone_maxs,
               int *bonecount)

{
  float local_34;
  float local_30;
  float local_2c;
  vec_t local_28 [6];
  
                    /* Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: vec3_t point@[???] */
  if (0 < *bonecount) {
    local_34 = *bone_maxs - *bone_mins;
    local_30 = bone_maxs[1] - bone_mins[1];
    local_2c = bone_maxs[2] - bone_mins[2];
    VectorScale(&local_34,0.5,local_28);
    R_StudioBoundVertex(mins,maxs,vertcount,local_28);
    VectorScale(&local_34,-0.5,local_28);
    R_StudioBoundVertex(mins,maxs,vertcount,local_28);
    *bone_mins = 0.0;
    bone_mins[1] = 0.0;
    bone_mins[2] = 0.0;
    *bone_maxs = 0.0;
    bone_maxs[1] = 0.0;
    bone_maxs[2] = 0.0;
    *bonecount = 0;
  }
  return;
}


// R_StudioBodyVariations  @ 000945c0
int R_StudioBodyVariations(model_t *model)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudiobodyparts_t * pbodypart@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
  iVar4 = 0;
  if (model->type == mod_studio) {
    pvVar1 = Mod_Extradata(model);
    if (pvVar1 != (void *)0x0) {
      iVar4 = 1;
      iVar3 = *(int *)((int)pvVar1 + 0xd0) + (int)pvVar1;
      if (0 < *(int *)((int)pvVar1 + 0xcc)) {
        iVar2 = 0;
        do {
          iVar2 = iVar2 + 1;
          iVar4 = iVar4 * *(int *)(iVar3 + 0x40);
          iVar3 = iVar3 + 0x4c;
        } while (iVar2 != *(int *)((int)pvVar1 + 0xcc));
        return iVar4;
      }
    }
  }
  return iVar4;
}


// R_StudioBoundBone  @ 00094e50
void R_StudioBoundBone(vec_t *mins,vec_t *maxs,int *bonecount,vec_t *point)

{
  float fVar1;
  
                    /* Unresolved local var: int i@[???] */
  if (*bonecount == 0) {
    *mins = *point;
    mins[1] = point[1];
    mins[2] = point[2];
    *maxs = *point;
    maxs[1] = point[1];
    maxs[2] = point[2];
    *bonecount = *bonecount + 1;
    return;
  }
  fVar1 = *point;
  if (fVar1 < *mins) {
    *mins = fVar1;
    fVar1 = *point;
  }
  if (*maxs < fVar1) {
    *maxs = fVar1;
  }
  fVar1 = point[1];
  if (fVar1 < mins[1]) {
    mins[1] = fVar1;
    fVar1 = point[1];
  }
  if (maxs[1] < fVar1) {
    maxs[1] = fVar1;
  }
  fVar1 = point[2];
  if (fVar1 < mins[2]) {
    mins[2] = fVar1;
    fVar1 = point[2];
  }
  if (maxs[2] < fVar1) {
    maxs[2] = fVar1;
  }
  *bonecount = *bonecount + 1;
  return;
}


// R_StudioBoundVertex  @ 00094d90
void R_StudioBoundVertex(vec_t *mins,vec_t *maxs,int *vertcount,vec_t *point)

{
  float fVar1;
  
                    /* Unresolved local var: int i@[???] */
  if (*vertcount == 0) {
    *mins = *point;
    mins[1] = point[1];
    mins[2] = point[2];
    *maxs = *point;
    maxs[1] = point[1];
    maxs[2] = point[2];
    *vertcount = *vertcount + 1;
    return;
  }
  fVar1 = *point;
  if (fVar1 < *mins) {
    *mins = fVar1;
    fVar1 = *point;
  }
  if (*maxs < fVar1) {
    *maxs = fVar1;
  }
  fVar1 = point[1];
  if (fVar1 < mins[1]) {
    mins[1] = fVar1;
    fVar1 = point[1];
  }
  if (maxs[1] < fVar1) {
    maxs[1] = fVar1;
  }
  fVar1 = point[2];
  if (fVar1 < mins[2]) {
    mins[2] = fVar1;
    fVar1 = point[2];
  }
  if (maxs[2] < fVar1) {
    maxs[2] = fVar1;
  }
  *vertcount = *vertcount + 1;
  return;
}


// R_StudioCalcBoneAdj  @ 00092e10
void R_StudioCalcBoneAdj(float dadt,float *adj,uchar *pcontroller1,uchar *pcontroller2,
                        uchar mouthopen)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  studiohdr_t *psVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: float value@[???]
                       Unresolved local var: mstudiobonecontroller_t * pbonecontroller@[???] */
  psVar5 = pstudiohdr;
  iVar9 = pstudiohdr->numbonecontrollers;
  pcVar6 = pstudiohdr->name + pstudiohdr->bonecontrollerindex + -8;
  if (0 < iVar9) {
    iVar8 = 0;
    do {
      while( true ) {
        iVar1 = *(int *)(pcVar6 + 0x14);
        if (iVar1 < 4) {
          uVar7 = *(uint *)(pcVar6 + 4);
          uVar10 = (uint)pcontroller1[iVar1];
          if ((uVar7 & 0x8000) == 0) {
            fVar4 = 1.0;
            fVar2 = ((1.0 - dadt) * (float)pcontroller2[iVar1] + (float)uVar10 * dadt) / 255.0;
            fVar3 = 0.0;
            if (fVar2 < 0.0) {
              fVar3 = 1.0;
              fVar4 = 0.0;
            }
            else if (fVar2 <= 1.0) {
              fVar3 = 1.0 - fVar2;
              fVar4 = fVar2;
            }
            fVar2 = fVar4 * *(float *)(pcVar6 + 0xc) + fVar3 * *(float *)(pcVar6 + 8);
          }
          else {
            uVar12 = uVar10 - pcontroller2[iVar1];
            uVar11 = (int)uVar12 >> 0x1f;
            if ((int)((uVar12 ^ uVar11) - uVar11) < 0x81) {
              fVar2 = ((1.0 - dadt) * (float)pcontroller2[iVar1] + (float)uVar10 * dadt) * 1.40625 +
                      *(float *)(pcVar6 + 8);
            }
            else {
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???] */
              fVar2 = (((1.0 - dadt) * (float)(pcontroller2[iVar8] ^ 0x80) +
                       (float)(pcontroller1[iVar8] ^ 0x80) * dadt) - 128.0) * 1.40625 +
                      *(float *)(pcVar6 + 8);
            }
          }
        }
        else {
          fVar2 = (float)mouthopen * 0.015625;
          fVar3 = 1.0;
          if (1.0 < fVar2) {
            fVar4 = 0.0;
          }
          else {
            fVar4 = 1.0 - fVar2;
            fVar3 = fVar2;
          }
          fVar2 = fVar3 * *(float *)(pcVar6 + 0xc) + fVar4 * *(float *)(pcVar6 + 8);
          uVar7 = *(uint *)(pcVar6 + 4);
        }
        uVar7 = (uVar7 & 0x7fff) - 1;
        if (uVar7 < 0x20) break;
LAB_00092f40:
        iVar8 = iVar8 + 1;
        pcVar6 = pcVar6 + 0x18;
        if (iVar9 <= iVar8) {
          return;
        }
      }
      uVar7 = 1 << ((byte)uVar7 & 0x1f);
      if ((uVar7 & 0x80008080) == 0) {
        if ((uVar7 & 0xb) != 0) {
          adj[iVar8] = fVar2;
          iVar9 = psVar5->numbonecontrollers;
        }
        goto LAB_00092f40;
      }
      pcVar6 = pcVar6 + 0x18;
      adj[iVar8] = fVar2 * 0.017453292;
      iVar8 = iVar8 + 1;
      iVar9 = psVar5->numbonecontrollers;
    } while (iVar8 < iVar9);
  }
  return;
}


// R_StudioCalcBonePosition  @ 00093240
void R_StudioCalcBonePosition
               (int frame,float s,mstudiobone_t *pbone,mstudioanim_t *panim,float *adj,float *pos)

{
  int iVar1;
  short sVar2;
  float fVar3;
  float fVar4;
  byte bVar5;
  uint uVar6;
  byte *pbVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  mstudiobone_t *local_20;
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: mstudioanimvalue_t * panimvalue@[???] */
  iVar11 = 0;
  local_20 = pbone;
  do {
    fVar3 = local_20->value[0];
    pos[iVar11] = fVar3;
    if (panim->offset[iVar11] != 0) {
      pbVar7 = (byte *)((int)panim->offset + (uint)panim->offset[iVar11]);
      bVar8 = pbVar7[1];
      bVar5 = *pbVar7;
      iVar9 = frame;
      if (bVar8 < bVar5) {
        iVar9 = 0;
      }
      while( true ) {
        uVar10 = (uint)bVar8;
        uVar6 = (uint)bVar5;
        if (iVar9 < (int)uVar10) break;
        pbVar7 = pbVar7 + uVar6 * 2 + 2;
        bVar8 = pbVar7[1];
        bVar5 = *pbVar7;
        iVar9 = iVar9 - uVar10;
        if (bVar8 < bVar5) {
          iVar9 = 0;
        }
      }
      if (iVar9 < (int)uVar6) {
        iVar1 = iVar9 + 1;
        if ((int)uVar6 <= iVar1) {
          sVar2 = *(short *)(pbVar7 + iVar1 * 2);
LAB_00093353:
          fVar3 = (float)sVar2 * local_20->scale[0] + fVar3;
          pos[iVar11] = fVar3;
          goto LAB_00093302;
        }
        fVar4 = (1.0 - s) * (float)*(short *)(pbVar7 + iVar1 * 2);
        sVar2 = *(short *)(pbVar7 + iVar9 * 2 + 4);
      }
      else {
        if (iVar9 + 1 < (int)uVar10) {
          sVar2 = *(short *)(pbVar7 + uVar6 * 2);
          goto LAB_00093353;
        }
        fVar4 = (1.0 - s) * (float)*(short *)(pbVar7 + uVar6 * 2);
        sVar2 = *(short *)(pbVar7 + uVar6 * 2 + 4);
      }
      fVar3 = ((float)sVar2 * s + fVar4) * local_20->scale[0] + fVar3;
      pos[iVar11] = fVar3;
    }
LAB_00093302:
    if ((local_20->bonecontroller[0] != -1) && (adj != (float *)0x0)) {
      pos[iVar11] = fVar3 + adj[local_20->bonecontroller[0]];
    }
    iVar11 = iVar11 + 1;
    local_20 = (mstudiobone_t *)(local_20->name + 4);
    if (iVar11 == 3) {
      return;
    }
  } while( true );
}


// R_StudioCalcBoneQuaterion  @ 00093090
void R_StudioCalcBoneQuaterion
               (int frame,float s,mstudiobone_t *pbone,mstudioanim_t *panim,float *adj,float *q)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  byte bVar6;
  uint uVar7;
  byte *pbVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  vec_t local_5c [4];
  vec_t local_4c [4];
  vec_t local_3c [4];
  vec_t local_2c [7];
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: vec4_t q1@[???]
                       Unresolved local var: vec4_t q2@[???]
                       Unresolved local var: vec3_t angle1@[???]
                       Unresolved local var: vec3_t angle2@[???]
                       Unresolved local var: mstudioanimvalue_t * panimvalue@[???] */
  iVar12 = 0;
  do {
    if (panim->offset[iVar12 + 3] == 0) {
      fVar2 = pbone->value[3];
      local_3c[iVar12] = fVar2;
      local_2c[iVar12] = fVar2;
      fVar3 = fVar2;
    }
    else {
      pbVar8 = (byte *)((int)panim->offset + (uint)panim->offset[iVar12 + 3]);
      bVar9 = pbVar8[1];
      bVar6 = *pbVar8;
      iVar10 = 0;
      if (bVar6 <= bVar9) {
        iVar10 = frame;
      }
      while( true ) {
        uVar11 = (uint)bVar9;
        uVar7 = (uint)bVar6;
        if (iVar10 < (int)uVar11) break;
        pbVar8 = pbVar8 + uVar7 * 2 + 2;
        bVar9 = pbVar8[1];
        bVar6 = *pbVar8;
        iVar10 = iVar10 - uVar11;
        if (bVar9 < bVar6) {
          iVar10 = 0;
        }
      }
      if (iVar10 < (int)uVar7) {
        iVar1 = iVar10 + 1;
        fVar2 = (float)*(short *)(pbVar8 + iVar1 * 2);
        local_3c[iVar12] = fVar2;
        if (iVar1 < (int)(uint)*pbVar8) {
          fVar5 = (float)*(short *)(pbVar8 + iVar10 * 2 + 4);
          local_2c[iVar12] = fVar5;
        }
        else {
          fVar5 = fVar2;
          if (iVar1 < (int)(uint)pbVar8[1]) goto LAB_000931a0;
          fVar5 = (float)*(short *)(pbVar8 + (uint)*pbVar8 * 2 + 4);
          local_2c[iVar12] = fVar5;
        }
      }
      else {
        fVar2 = (float)*(short *)(pbVar8 + uVar7 * 2);
        local_3c[iVar12] = fVar2;
        fVar5 = fVar2;
        if (iVar10 + 1 < (int)(uint)pbVar8[1]) {
LAB_000931a0:
          local_2c[iVar12] = fVar5;
          fVar2 = fVar5;
        }
        else {
          fVar5 = (float)*(short *)(pbVar8 + (uint)*pbVar8 * 2 + 4);
          local_2c[iVar12] = fVar5;
        }
      }
      fVar3 = pbone->value[3];
      fVar4 = pbone->scale[3];
      fVar2 = fVar2 * fVar4 + fVar3;
      local_3c[iVar12] = fVar2;
      fVar3 = fVar3 + fVar4 * fVar5;
      local_2c[iVar12] = fVar3;
    }
    iVar10 = pbone->bonecontroller[3];
    if (iVar10 != -1) {
      local_3c[iVar12] = fVar2 + adj[iVar10];
      local_2c[iVar12] = fVar3 + adj[iVar10];
    }
    iVar12 = iVar12 + 1;
    pbone = (mstudiobone_t *)(pbone->name + 4);
    if (iVar12 == 3) {
      iVar12 = VectorCompare(local_3c,local_2c);
      if (iVar12 == 0) {
        AngleQuaternion(local_3c,local_5c);
        AngleQuaternion(local_2c,local_4c);
        QuaternionSlerp(local_5c,local_4c,s,q);
        return;
      }
      AngleQuaternion(local_3c,q);
      return;
    }
  } while( true );
}


// R_StudioComputeBounds  @ 00095020
int R_StudioComputeBounds(uchar *pBuffer,float *mins,float *maxs)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uchar *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  vec_t *point;
  mstudiobone_t *local_ac;
  int local_a8;
  int local_a4;
  uchar *local_9c;
  int local_98;
  vec_t local_8c [4];
  vec_t local_7c [4];
  vec_t local_6c;
  float local_68;
  float local_64;
  vec_t local_5c;
  float local_58;
  float local_54;
  vec_t local_48 [3];
  int local_3c [4];
  int local_2c [7];
  
                    /* Unresolved local var: studiohdr_t * header@[???]
                       Unresolved local var: mstudiobodyparts_t * bodyparts@[???]
                       Unresolved local var: mstudiomodel_t * pmodel@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: int model@[???]
                       Unresolved local var: int nummodels@[???]
                       Unresolved local var: int num_verts@[???]
                       Unresolved local var: int v@[???]
                       Unresolved local var: vec3_t * pverts@[???]
                       Unresolved local var: mstudiobone_t * pbones@[???]
                       Unresolved local var: int bone@[???]
                       Unresolved local var: mstudioseqdesc_t * pseq@[???]
                       Unresolved local var: int sequence@[???]
                       Unresolved local var: mstudioanim_t * panim@[???]
                       Unresolved local var: int f@[???]
                       Unresolved local var: int num_frames@[???]
                       Unresolved local var: char * temp@[???]
                       Unresolved local var: float[3] bone_position@[???]
                       Unresolved local var: vec3_t bone_mins@[???]
                       Unresolved local var: vec3_t bone_maxs@[???]
                       Unresolved local var: vec3_t vert_mins@[???]
                       Unresolved local var: vec3_t vert_maxs@[???]
                       Unresolved local var: int bone_count@[???]
                       Unresolved local var: int vert_count@[???] */
  local_3c[0] = 0;
  local_2c[0] = 0;
  local_8c[0] = 0.0;
  local_8c[1] = 0.0;
  local_8c[2] = 0.0;
  local_7c[0] = 0.0;
  local_7c[1] = 0.0;
  local_7c[2] = 0.0;
  local_6c = 0.0;
  local_68 = 0.0;
  local_64 = 0.0;
  local_5c = 0.0;
  local_58 = 0.0;
  local_54 = 0.0;
  if (0 < *(int *)(pBuffer + 0xcc)) {
    iVar2 = 0;
    iVar7 = 0;
    puVar4 = pBuffer + *(int *)(pBuffer + 0xd0);
    do {
      piVar1 = (int *)(puVar4 + 0x40);
      iVar2 = iVar2 + 1;
      puVar4 = puVar4 + 0x4c;
      iVar7 = iVar7 + *piVar1;
    } while (iVar2 != *(int *)(pBuffer + 0xcc));
    local_ac = (mstudiobone_t *)(pBuffer + *(int *)(pBuffer + 0xd0) + iVar2 * 0x4c);
    if (0 < iVar7) {
      local_a8 = 0;
      do {
        iVar2 = *(int *)((int)local_ac + 0x50);
        if (0 < iVar2) {
          iVar5 = 0;
          point = (vec_t *)(pBuffer + *(int *)((int)local_ac + 0x58));
          do {
            iVar5 = iVar5 + 1;
            R_StudioBoundVertex(&local_6c,&local_5c,local_2c,point);
            point = point + 3;
          } while (iVar5 != iVar2);
        }
        local_a8 = local_a8 + 1;
        local_ac = (mstudiobone_t *)((int)local_ac + 0x70);
      } while (local_a8 != iVar7);
    }
  }
  iVar2 = *(int *)(pBuffer + 0x90);
  local_9c = pBuffer + *(int *)(pBuffer + 0xa8);
  if (0 < *(int *)(pBuffer + 0xa4)) {
    local_98 = 0;
    do {
      iVar7 = *(int *)(local_9c + 0x38);
      iVar5 = *(int *)(local_9c + 0x7c);
      iVar3 = *(int *)(pBuffer + 0x8c);
      if (0 < iVar3) {
        local_a4 = 0;
        local_ac = (mstudiobone_t *)(pBuffer + iVar2);
        do {
          if (0 < iVar7) {
            iVar3 = 0;
            do {
              iVar6 = iVar3 + 1;
              R_StudioCalcBonePosition
                        (iVar3,0.0,local_ac,(mstudioanim_t *)(pBuffer + iVar5),(float *)0x0,local_48
                        );
              R_StudioBoundBone(local_8c,local_7c,local_3c,local_48);
              iVar3 = iVar6;
            } while (iVar6 != iVar7);
            iVar3 = *(int *)(pBuffer + 0x8c);
          }
          local_a4 = local_a4 + 1;
          local_ac = local_ac + 1;
        } while (local_a4 < iVar3);
      }
      R_StudioAccumulateBoneVerts(&local_6c,&local_5c,local_2c,local_8c,local_7c,local_3c);
      local_98 = local_98 + 1;
      local_9c = local_9c + 0xb0;
    } while (local_98 < *(int *)(pBuffer + 0xa4));
  }
  *mins = local_6c;
  mins[1] = local_68;
  mins[2] = local_64;
  *maxs = local_5c;
  maxs[1] = local_58;
  maxs[2] = local_54;
  return 1;
}


// R_StudioHull  @ 00093cf0
hull_t * R_StudioHull(model_t *pModel,float frame,int sequence,vec_t *angles,vec_t *origin,
                     vec_t *size,uchar *pcontroller,uchar *pblending,int *pNumHulls,edict_t *pEdict,
                     int bSkipShield)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  studiohdr_t *psVar14;
  mplane_t *pmVar15;
  r_studiocache_t *prVar16;
  uint uVar17;
  hull_t *phVar18;
  int iVar19;
  char *pcVar20;
  int iVar21;
  int iVar22;
  float local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: mstudiobbox_t * pbbox@[???]
                       Unresolved local var: vec3_t angles2@[???]
                       Unresolved local var: r_studiocache_t * pCached@[???]
                       Unresolved local var: int numHitBoxes@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???] */
  if (studio_hull[0].planes == (mplane_t *)0x0) {
    studio_clipnodes[0].children[0] = -1;
    studio_clipnodes[0].children[1] = 1;
    studio_clipnodes[1].planenum = 1;
    studio_clipnodes[1].children[1] = -1;
    studio_clipnodes[1].children[0] = 2;
    studio_clipnodes[2].planenum = 2;
    studio_clipnodes[4].planenum = 4;
    studio_clipnodes[4].children[0] = -1;
    studio_clipnodes[4].children[1] = 5;
    studio_clipnodes[5].planenum = 5;
    studio_clipnodes[0].planenum = 0;
    studio_clipnodes[5].children[1] = -1;
    studio_clipnodes[2].children[0] = -1;
    pmVar15 = studio_planes;
    studio_clipnodes[5].children[0] = -2;
    phVar18 = studio_hull;
    studio_clipnodes[2].children[1] = 3;
    studio_clipnodes[3].planenum = 3;
    studio_clipnodes[3].children[1] = -1;
    studio_clipnodes[3].children[0] = 4;
    do {
      phVar18->planes = pmVar15;
      pmVar15 = pmVar15 + 6;
      phVar18->clipnodes = studio_clipnodes;
      phVar18->firstclipnode = 0;
      phVar18->lastclipnode = 5;
      phVar18 = phVar18 + 1;
    } while (phVar18 != (hull_t *)studio_clipnodes);
  }
  if ((r_cachestudio.value != 0.0) &&
     (prVar16 = R_CheckStudioCache(pModel,frame,sequence,angles,origin,size,pcontroller,pblending),
     prVar16 != (r_studiocache_t *)0x0)) {
    Q_memcpy(studio_planes,cache_planes + prVar16->nStartPlane,prVar16->numhulls * 0x78);
    Q_memcpy(studio_hull,cache_hull + prVar16->nStartHull,prVar16->numhulls * 0x28);
    Q_memcpy(studio_hull_hitgroup,cache_hull_hitgroup + prVar16->nStartHull,prVar16->numhulls << 2);
    *pNumHulls = prVar16->numhulls;
    return studio_hull;
  }
  pstudiohdr = Mod_Extradata(pModel);
  local_20 = angles[2];
  local_28 = -*angles;
  local_24 = angles[1];
  (*g_pSvBlendingAPI->SV_StudioSetupBones)
            (pModel,frame,sequence,&local_28,origin,pcontroller,pblending,-1,pEdict);
  psVar14 = pstudiohdr;
  pcVar20 = pstudiohdr->name + pstudiohdr->hitboxindex + -8;
  iVar22 = pstudiohdr->numhitboxes;
  if (0 < iVar22) {
    pmVar15 = studio_planes;
    iVar19 = 0;
    iVar21 = 0;
    do {
      while ((iVar19 != 0x15 || (bSkipShield != 1))) {
        studio_hull_hitgroup[iVar19] = *(int *)(pcVar20 + 4);
        iVar19 = iVar19 + 1;
        iVar22 = *(int *)pcVar20;
        fVar1 = *(float *)(pcVar20 + 0x14);
        studio_planes[iVar21].type = '\x05';
        fVar2 = bonetransform[iVar22][0][0];
        studio_planes[iVar21].normal[0] = fVar2;
        fVar3 = bonetransform[iVar22][1][0];
        studio_planes[iVar21].normal[1] = fVar3;
        fVar4 = bonetransform[iVar22][2][0];
        studio_planes[iVar21].normal[2] = fVar4;
        studio_planes[iVar21].dist =
             fVar4 * bonetransform[iVar22][2][3] +
             fVar3 * bonetransform[iVar22][1][3] + fVar2 * bonetransform[iVar22][0][3] + fVar1;
        iVar22 = *(int *)pcVar20;
        fVar1 = *(float *)(pcVar20 + 8);
        studio_planes[iVar21 + 1].type = '\x05';
        fVar2 = bonetransform[iVar22][0][0];
        studio_planes[iVar21 + 1].normal[0] = fVar2;
        fVar3 = bonetransform[iVar22][1][0];
        studio_planes[iVar21 + 1].normal[1] = fVar3;
        fVar4 = bonetransform[iVar22][2][0];
        studio_planes[iVar21 + 1].normal[2] = fVar4;
        studio_planes[iVar21 + 1].dist =
             fVar4 * bonetransform[iVar22][2][3] +
             fVar3 * bonetransform[iVar22][1][3] + fVar2 * bonetransform[iVar22][0][3] + fVar1;
        iVar22 = *(int *)pcVar20;
        fVar1 = *(float *)(pcVar20 + 0x18);
        pmVar15[2].type = '\x05';
        fVar2 = bonetransform[iVar22][0][1];
        pmVar15[2].normal[0] = fVar2;
        fVar3 = bonetransform[iVar22][1][1];
        pmVar15[2].normal[1] = fVar3;
        fVar4 = bonetransform[iVar22][2][1];
        pmVar15[2].normal[2] = fVar4;
        pmVar15[2].dist =
             bonetransform[iVar22][2][3] * fVar4 +
             bonetransform[iVar22][1][3] * fVar3 + bonetransform[iVar22][0][3] * fVar2 + fVar1;
        iVar22 = *(int *)pcVar20;
        fVar1 = *(float *)(pcVar20 + 0xc);
        pmVar15[3].type = '\x05';
        fVar5 = bonetransform[iVar22][0][1];
        pmVar15[3].normal[0] = fVar5;
        fVar6 = bonetransform[iVar22][1][1];
        pmVar15[3].normal[1] = fVar6;
        fVar7 = bonetransform[iVar22][2][1];
        pmVar15[3].normal[2] = fVar7;
        pmVar15[3].dist =
             fVar7 * bonetransform[iVar22][2][3] +
             bonetransform[iVar22][1][3] * fVar6 + bonetransform[iVar22][0][3] * fVar5 + fVar1;
        iVar22 = *(int *)pcVar20;
        fVar1 = *(float *)(pcVar20 + 0x1c);
        pmVar15[4].type = '\x05';
        fVar8 = bonetransform[iVar22][0][2];
        pmVar15[4].normal[0] = fVar8;
        fVar9 = bonetransform[iVar22][1][2];
        pmVar15[4].normal[1] = fVar9;
        fVar10 = bonetransform[iVar22][2][2];
        pmVar15[4].normal[2] = fVar10;
        pmVar15[4].dist =
             fVar10 * bonetransform[iVar22][2][3] +
             fVar9 * bonetransform[iVar22][1][3] + fVar8 * bonetransform[iVar22][0][3] + fVar1;
        iVar22 = *(int *)pcVar20;
        fVar1 = *(float *)(pcVar20 + 0x10);
        pcVar20 = pcVar20 + 0x20;
        pmVar15[5].type = '\x05';
        fVar11 = bonetransform[iVar22][0][2];
        pmVar15[5].normal[0] = fVar11;
        fVar12 = bonetransform[iVar22][1][2];
        pmVar15[5].normal[1] = fVar12;
        fVar13 = bonetransform[iVar22][2][2];
        pmVar15[5].normal[2] = fVar13;
        pmVar15[5].dist =
             fVar13 * bonetransform[iVar22][2][3] +
             fVar12 * bonetransform[iVar22][1][3] + fVar11 * bonetransform[iVar22][0][3] + fVar1;
        pmVar15->dist =
             ABS(pmVar15->normal[2] * size[2]) +
             ABS(pmVar15->normal[1] * size[1]) + ABS(pmVar15->normal[0] * *size) + pmVar15->dist;
        pmVar15[1].dist =
             pmVar15[1].dist -
             (ABS(pmVar15[1].normal[2] * size[2]) +
             ABS(pmVar15[1].normal[1] * size[1]) + ABS(pmVar15[1].normal[0] * *size));
        pmVar15[2].dist =
             ABS(fVar4 * size[2]) + ABS(fVar3 * size[1]) + ABS(fVar2 * *size) + pmVar15[2].dist;
        pmVar15[3].dist =
             pmVar15[3].dist - (ABS(fVar7 * size[2]) + ABS(fVar6 * size[1]) + ABS(fVar5 * *size));
        pmVar15[4].dist =
             ABS(fVar10 * size[2]) + ABS(fVar9 * size[1]) + ABS(fVar8 * *size) + pmVar15[4].dist;
        pmVar15[5].dist =
             pmVar15[5].dist - (ABS(fVar13 * size[2]) + ABS(fVar12 * size[1]) + ABS(fVar11 * *size))
        ;
        pmVar15 = pmVar15 + 6;
        iVar22 = psVar14->numhitboxes;
        iVar21 = iVar21 + 6;
        if (iVar22 <= iVar19) goto LAB_00094130;
      }
      iVar19 = 0x16;
      iVar21 = iVar21 + 6;
      pcVar20 = pcVar20 + 0x20;
      pmVar15 = pmVar15 + 6;
    } while (0x16 < iVar22);
  }
LAB_00094130:
  if (bSkipShield == 1) {
    iVar22 = iVar22 + -1;
    *pNumHulls = iVar22;
  }
  else {
    *pNumHulls = iVar22;
  }
  if (r_cachestudio.value == 0.0) {
    return studio_hull;
  }
                    /* Unresolved local var: r_studiocache_t * p@[???] */
  if (nCurrentHull + iVar22 < 0x80) {
    r_cachecurrent = r_cachecurrent + 1;
    uVar17 = r_cachecurrent & 0xf;
  }
  else {
    Q_memset(rgStudioCache,0,0x440);
    r_cachecurrent = 1;
    nCurrentHull = 0;
    nCurrentPlane = 0;
    uVar17 = 1;
  }
  rgStudioCache[uVar17].sequence = sequence;
  rgStudioCache[uVar17].frame = frame;
  rgStudioCache[uVar17].angles[0] = *angles;
  rgStudioCache[uVar17].angles[1] = angles[1];
  rgStudioCache[uVar17].angles[2] = angles[2];
  rgStudioCache[uVar17].origin[0] = *origin;
  rgStudioCache[uVar17].origin[1] = origin[1];
  rgStudioCache[uVar17].origin[2] = origin[2];
  rgStudioCache[uVar17].size[0] = *size;
  rgStudioCache[uVar17].size[1] = size[1];
  rgStudioCache[uVar17].size[2] = size[2];
  Q_memcpy(rgStudioCache[uVar17].controller,pcontroller,4);
  Q_memcpy(rgStudioCache[uVar17].blending,pblending,2);
  iVar21 = nCurrentHull;
  rgStudioCache[uVar17].pModel = pModel;
  iVar19 = nCurrentPlane;
  rgStudioCache[uVar17].nStartHull = iVar21;
  rgStudioCache[uVar17].nStartPlane = iVar19;
  Q_memcpy(cache_hull + iVar21,studio_hull,iVar22 * 0x28);
  Q_memcpy(cache_planes + nCurrentPlane,studio_planes,iVar22 * 0x78);
  Q_memcpy(cache_hull_hitgroup + nCurrentHull,studio_hull_hitgroup,iVar22 * 4);
  rgStudioCache[uVar17].numhulls = iVar22;
  nCurrentHull = nCurrentHull + iVar22;
  nCurrentPlane = nCurrentPlane + iVar22 * 6;
  return studio_hull;
}


// R_StudioPlayerBlend  @ 00094630
void R_StudioPlayerBlend(mstudioseqdesc_t *pseqdesc,int *pBlend,float *pPitch)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *pPitch;
  *pBlend = (int)(fVar1 * 3.0);
  fVar3 = (float)(int)(fVar1 * 3.0);
  fVar1 = pseqdesc->blendstart[0];
  if (fVar3 < fVar1) {
    *pPitch = *pPitch - fVar1 / 3.0;
    *pBlend = 0;
    return;
  }
  fVar2 = pseqdesc->blendend[0];
  if (fVar3 <= fVar2) {
    if (fVar2 - fVar1 < 0.1) {
      *pBlend = 0x7f;
    }
    else {
      *pBlend = (int)(((fVar3 - fVar1) * 255.0) / (fVar2 - fVar1));
    }
    *pPitch = 0.0;
    return;
  }
  *pPitch = *pPitch - fVar2 / 3.0;
  *pBlend = 0xff;
  return;
}


// R_StudioSlerpBones  @ 00093370
void R_StudioSlerpBones(vec4_t *q1,vec3_t *pos1,vec4_t *q2,vec3_t *pos2,float s)

{
  vec_t *pvVar1;
  studiohdr_t *psVar2;
  int iVar3;
  int iVar4;
  float local_38;
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec4_t q3@[???]
                       Unresolved local var: float s1@[???] */
  psVar2 = pstudiohdr;
  if (s < 0.0) {
    local_38 = 1.0;
    s = 0.0;
  }
  else if (s <= 1.0) {
    local_38 = 1.0 - s;
  }
  else {
    local_38 = 0.0;
    s = 1.0;
  }
  if (0 < pstudiohdr->numbones) {
    iVar4 = 0;
    iVar3 = (int)q2 - (int)q1;
    do {
      iVar4 = iVar4 + 1;
      QuaternionSlerp(*q1,(vec_t *)(iVar3 + (int)q1),s,&local_2c);
      (*q1)[0] = local_2c;
      (*q1)[1] = local_28;
      (*q1)[2] = local_24;
      (*q1)[3] = local_20;
      q1 = q1 + 1;
      (*pos1)[0] = s * (*pos2)[0] + local_38 * (*pos1)[0];
      (*pos1)[1] = s * (*pos2)[1] + local_38 * (*pos1)[1];
      pvVar1 = *pos2;
      pos2 = pos2 + 1;
      (*pos1)[2] = s * pvVar1[2] + local_38 * (*pos1)[2];
      pos1 = pos1 + 1;
    } while (iVar4 < psVar2->numbones);
  }
  return;
}


