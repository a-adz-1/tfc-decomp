// R_AddToStudioCache  @ 00075b00
void R_AddToStudioCache(float frame,int sequence,vec_t *angles,vec_t *origin,vec_t *size,
                       byte *controller,byte *pblending,model_t *pModel,hull_t *pHulls,int numhulls)

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
    uVar3 = 1;
    Q_memset(rgStudioCache,0,0x440);
    r_cachecurrent = 1;
    nCurrentHull = 0;
    nCurrentPlane = 0;
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
  iVar1 = nCurrentPlane;
  rgStudioCache[uVar3].pModel = pModel;
  iVar2 = nCurrentHull;
  rgStudioCache[uVar3].nStartPlane = iVar1;
  rgStudioCache[uVar3].nStartHull = iVar2;
  Q_memcpy(cache_hull + iVar2,pHulls,numhulls * 0x28);
  Q_memcpy(cache_planes + nCurrentPlane,studio_planes,numhulls * 0x78);
  Q_memcpy(cache_hull_hitgroup + nCurrentHull,studio_hull_hitgroup,numhulls * 4);
  rgStudioCache[uVar3].numhulls = numhulls;
  nCurrentHull = nCurrentHull + numhulls;
  nCurrentPlane = nCurrentPlane + numhulls * 6;
  return;
}


// R_CheckStudioCache  @ 000759f0
r_studiocache_t *
R_CheckStudioCache(model_t *pModel,float frame,int sequence,vec_t *angles,vec_t *origin,vec_t *size,
                  byte *controller,byte *blending)

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


// R_ConcatRotations  @ 00060fe0
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


// R_ConcatTransforms  @ 000610d0
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


// R_DecalRemoveAll  @ 000452b0
void R_DecalRemoveAll(void)

{
  return;
}


// R_FlushStudioCache  @ 00077e10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_FlushStudioCache(void)

{
  Q_memset(rgStudioCache,0,0x440);
  nCurrentHull = 0;
  r_cachecurrent = 0;
  nCurrentPlane = 0;
  return;
}


// R_GetAnim  @ 00077450
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
  if (iVar1 == 0) {
    pcVar6 = pstudiohdr->name + pseqdesc->animindex + -8;
  }
  else {
    iVar2 = pstudiohdr->seqgroupindex;
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
    pcVar6 = (char *)(pseqdesc->animindex + (int)pdVar7->mins[pseqdesc->seqgroup]);
  }
  return (mstudioanim_t *)pcVar6;
}


// R_GetStudioBounds  @ 00079220
int R_GetStudioBounds(char *filename,float *mins,float *maxs)

{
  bool bVar1;
  char *pcVar2;
  FileHandle_t file;
  int32 *pBuffer;
  int32 iVar3;
  int iVar4;
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
  if (((pcVar2 == (char *)0x0) || (pcVar2 = Q_strstr(filename,".mdl"), pcVar2 == (char *)0x0)) ||
     (file = FS_Open(filename,"rb"), file == (FileHandle_t)0x0)) {
    return 0;
  }
  pBuffer = FS_GetReadBuffer(file,local_20);
  bVar1 = true;
  if (pBuffer == (int32 *)0x0) {
    pBuffer = (int32 *)COM_LoadFile(filename,5,(int *)0x0);
    if (pBuffer != (int32 *)0x0) {
      bVar1 = false;
      goto LAB_000792ef;
    }
    iVar4 = 0;
  }
  else {
LAB_000792ef:
    iVar3 = (*LittleLong)(*pBuffer);
    if (iVar3 == 0x54534449) {
      iVar4 = R_StudioComputeBounds((byte *)pBuffer,mins,maxs);
    }
    else {
      iVar4 = 0;
      COM_FreeFile(pBuffer);
    }
    if (bVar1) {
      FS_ReleaseReadBuffer(file,pBuffer);
      goto LAB_0007932b;
    }
  }
  COM_FreeFile(pBuffer);
LAB_0007932b:
  FS_Close(file);
  return iVar4;
}


// R_Init  @ 000b3140
void R_Init(void)

{
  return;
}


// R_InitSky  @ 000b3170
void R_InitSky(void)

{
  return;
}


// R_InitStudioCache  @ 00077dd0
void R_InitStudioCache(void)

{
  Q_memset(rgStudioCache,0,0x440);
  nCurrentHull = 0;
  r_cachecurrent = 0;
  nCurrentPlane = 0;
  return;
}


// R_InitTextures  @ 000b3190
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_InitTextures(void)

{
  bool bVar1;
  texture_t *ptVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_20;
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int m@[???]
                       Unresolved local var: byte * dest@[???] */
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
    iVar5 = 0x10 >> ((byte)local_20 & 0x1f);
    pcVar3 = ptVar2->name + ptVar2->offsets[local_20] + 0xf;
    iVar6 = 8 >> ((byte)local_20 & 0x1f);
    iVar7 = 0;
    do {
      bVar1 = iVar7 < iVar6;
      pcVar3[-0xf] = -bVar1;
      pcVar3[-0xe] = (1 < iVar6 != bVar1) + -1;
      if ((((iVar5 != 2) && (pcVar3[-0xd] = (bVar1 != 2 < iVar6) + -1, iVar5 != 3)) &&
          (pcVar3[-0xc] = (bVar1 != 3 < iVar6) + -1, iVar5 != 4)) &&
         (((pcVar3[-0xb] = (bVar1 != 4 < iVar6) + -1, iVar5 != 5 &&
           (pcVar3[-10] = (bVar1 != 5 < iVar6) + -1, iVar5 != 6)) &&
          ((pcVar3[-9] = (bVar1 != 6 < iVar6) + -1, iVar5 != 7 &&
           (pcVar3[-8] = (bVar1 != 7 < iVar6) + -1, iVar5 != 8)))))) {
        cVar4 = -(iVar6 <= iVar7);
        pcVar3[-7] = cVar4;
        if ((((iVar5 != 9) && (pcVar3[-6] = cVar4, iVar5 != 10)) &&
            ((pcVar3[-5] = cVar4, iVar5 != 0xb &&
             (((pcVar3[-4] = cVar4, iVar5 != 0xc && (pcVar3[-3] = cVar4, iVar5 != 0xd)) &&
              (pcVar3[-2] = cVar4, iVar5 != 0xe)))))) && (pcVar3[-1] = cVar4, iVar5 == 0x10)) {
          *pcVar3 = cVar4;
        }
      }
      iVar7 = iVar7 + 1;
      pcVar3 = pcVar3 + iVar5;
    } while (iVar5 != iVar7);
    local_20 = local_20 + 1;
    ptVar2 = r_notexture_mip;
  } while (local_20 != 4);
  return;
}


// R_MarkLeaves  @ 000b3180
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_MarkLeaves(void)

{
  return;
}


// R_ResetSvBlending  @ 000793b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_ResetSvBlending(void)

{
  g_pSvBlendingAPI = &svBlending;
  return;
}


// R_SetStackBase  @ 000b30f0
void R_SetStackBase(void)

{
  return;
}


// R_StudioAccumulateBoneVerts  @ 000789a0
void R_StudioAccumulateBoneVerts
               (vec_t *mins,vec_t *maxs,int *vertcount,vec_t *bone_mins,vec_t *bone_maxs,
               int *bonecount)

{
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: vec3_t point@[???] */
  if (0 < *bonecount) {
                    /* Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: vec3_t point@[???] */
    local_34 = *bone_maxs - *bone_mins;
    local_30 = bone_maxs[1] - bone_mins[1];
    local_2c = bone_maxs[2] - bone_mins[2];
    VectorScale(&local_34,0.5,&local_28);
                    /* Unresolved local var: int i@[???] */
    if (*vertcount == 0) {
      *mins = local_28;
      mins[1] = local_24;
      mins[2] = local_20;
      *maxs = local_28;
      maxs[1] = local_24;
      maxs[2] = local_20;
    }
    else {
      if (local_28 < *mins) {
        *mins = local_28;
      }
      if (*maxs < local_28) {
        *maxs = local_28;
      }
      if (local_24 < mins[1]) {
        mins[1] = local_24;
      }
      if (maxs[1] < local_24) {
        maxs[1] = local_24;
      }
      if (local_20 < mins[2]) {
        mins[2] = local_20;
      }
      if (maxs[2] < local_20) {
        maxs[2] = local_20;
      }
    }
    *vertcount = *vertcount + 1;
    VectorScale(&local_34,-0.5,&local_28);
                    /* Unresolved local var: int i@[???] */
    if (*vertcount == 0) {
      *mins = local_28;
      mins[1] = local_24;
      mins[2] = local_20;
      *maxs = local_28;
      maxs[1] = local_24;
      maxs[2] = local_20;
    }
    else {
      if (local_28 < *mins) {
        *mins = local_28;
      }
      if (*maxs < local_28) {
        *maxs = local_28;
      }
      if (local_24 < mins[1]) {
        mins[1] = local_24;
      }
      if (maxs[1] < local_24) {
        maxs[1] = local_24;
      }
      if (local_20 < mins[2]) {
        mins[2] = local_20;
      }
      if (maxs[2] < local_20) {
        maxs[2] = local_20;
      }
    }
    *vertcount = *vertcount + 1;
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


// R_StudioBodyVariations  @ 00077e50
int R_StudioBodyVariations(model_t *model)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudiobodyparts_t * pbodypart@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudiobodyparts_t * pbodypart@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
  if ((model->type == mod_studio) && (pvVar2 = Mod_Extradata(model), pvVar2 != (void *)0x0)) {
    if (*(int *)((int)pvVar2 + 0xcc) < 1) {
      return 1;
    }
    iVar4 = (int)pvVar2 + *(int *)((int)pvVar2 + 0xd0);
    iVar3 = 1;
    do {
      piVar1 = (int *)(iVar4 + 0x40);
      iVar4 = iVar4 + 0x4c;
      iVar3 = iVar3 * *piVar1;
    } while (*(int *)((int)pvVar2 + 0xd0) + *(int *)((int)pvVar2 + 0xcc) * 0x4c + (int)pvVar2 !=
             iVar4);
    return iVar3;
  }
  return 0;
}


// R_StudioBoundBone  @ 000788d0
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


// R_StudioBoundVertex  @ 00078800
void R_StudioBoundVertex(float *param_1,float *param_2,int *param_3,float *param_4)

{
  float fVar1;
  
  if (*param_3 == 0) {
    *param_1 = *param_4;
    param_1[1] = param_4[1];
    param_1[2] = param_4[2];
    *param_2 = *param_4;
    param_2[1] = param_4[1];
    param_2[2] = param_4[2];
    *param_3 = *param_3 + 1;
    return;
  }
  fVar1 = *param_4;
  if (fVar1 < *param_1) {
    *param_1 = fVar1;
    fVar1 = *param_4;
  }
  if (*param_2 < fVar1) {
    *param_2 = fVar1;
  }
  fVar1 = param_4[1];
  if (fVar1 < param_1[1]) {
    param_1[1] = fVar1;
    fVar1 = param_4[1];
  }
  if (param_2[1] < fVar1) {
    param_2[1] = fVar1;
  }
  fVar1 = param_4[2];
  if (fVar1 < param_1[2]) {
    param_1[2] = fVar1;
    fVar1 = param_4[2];
  }
  if (param_2[2] < fVar1) {
    param_2[2] = fVar1;
  }
  *param_3 = *param_3 + 1;
  return;
}


// R_StudioCalcBoneAdj  @ 000761d0
void R_StudioCalcBoneAdj(float dadt,float *adj,byte *pcontroller1,byte *pcontroller2,byte mouthopen)

{
  int iVar1;
  float fVar2;
  float fVar3;
  studiohdr_t *psVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  float local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: float value@[???]
                       Unresolved local var: mstudiobonecontroller_t * pbonecontroller@[???] */
  psVar4 = pstudiohdr;
  pcVar5 = pstudiohdr->name + pstudiohdr->bonecontrollerindex + -8;
  if (0 < pstudiohdr->numbonecontrollers) {
    iVar8 = 0;
    do {
      while( true ) {
        iVar1 = *(int *)(pcVar5 + 0x14);
        if (iVar1 < 4) {
          uVar6 = *(uint *)(pcVar5 + 4);
          if ((uVar6 & 0x8000) == 0) {
            fVar2 = ((float)pcontroller1[iVar1] * dadt + (1.0 - dadt) * (float)pcontroller2[iVar1])
                    / 255.0;
            if (fVar2 < 0.0) {
              fVar3 = 1.0;
              fVar2 = 0.0;
            }
            else if (fVar2 <= 1.0) {
              fVar3 = 1.0 - fVar2;
            }
            else {
              fVar3 = 0.0;
              fVar2 = 1.0;
            }
            local_24 = fVar2 * *(float *)(pcVar5 + 0xc) + fVar3 * *(float *)(pcVar5 + 8);
          }
          else {
            uVar7 = (uint)pcontroller1[iVar1] - (uint)pcontroller2[iVar1];
            uVar9 = (int)uVar7 >> 0x1f;
            if ((int)((uVar7 ^ uVar9) - uVar9) < 0x81) {
              local_24 = ((float)pcontroller1[iVar1] * dadt +
                         (1.0 - dadt) * (float)pcontroller2[iVar1]) * 1.40625 +
                         *(float *)(pcVar5 + 8);
            }
            else {
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???] */
              local_24 = (((float)(byte)(pcontroller1[iVar8] + 0x80) * dadt +
                          (1.0 - dadt) * (float)(byte)(pcontroller2[iVar8] + 0x80)) - 128.0) *
                         1.40625 + *(float *)(pcVar5 + 8);
            }
          }
        }
        else {
          fVar2 = (float)mouthopen * 0.015625;
          if (fVar2 <= 1.0) {
            fVar3 = 1.0 - fVar2;
          }
          else {
            fVar3 = 0.0;
            fVar2 = 1.0;
          }
          local_24 = fVar2 * *(float *)(pcVar5 + 0xc) + fVar3 * *(float *)(pcVar5 + 8);
          uVar6 = *(uint *)(pcVar5 + 4);
        }
        uVar6 = (uVar6 & 0x7fff) - 1;
        if (uVar6 < 0x20) break;
LAB_000762d0:
        iVar8 = iVar8 + 1;
        pcVar5 = pcVar5 + 0x18;
        if (psVar4->numbonecontrollers <= iVar8) {
          return;
        }
      }
      uVar6 = 1 << ((byte)uVar6 & 0x1f);
      if ((uVar6 & 0x80008080) == 0) {
        if ((uVar6 & 0xb) != 0) {
          adj[iVar8] = local_24;
        }
        goto LAB_000762d0;
      }
      pcVar5 = pcVar5 + 0x18;
      adj[iVar8] = local_24 * 0.017453292;
      iVar8 = iVar8 + 1;
    } while (iVar8 < psVar4->numbonecontrollers);
  }
  return;
}


// R_StudioCalcBonePosition  @ 00076610
void R_StudioCalcBonePosition
               (int frame,float s,mstudiobone_t *pbone,mstudioanim_t *panim,float *adj,float *pos)

{
  short sVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  byte bVar7;
  float *pfVar8;
  uint uVar9;
  int local_24;
  float *local_20;
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: mstudioanimvalue_t * panimvalue@[???] */
  local_24 = 0;
  local_20 = pos;
  pfVar8 = pbone->scale;
  do {
    fVar2 = pfVar8[-6];
    *local_20 = fVar2;
    if (panim->offset[local_24] != 0) {
      pbVar5 = (byte *)((int)panim->offset + (uint)panim->offset[local_24]);
      bVar7 = pbVar5[1];
      uVar6 = (uint)*pbVar5;
      iVar4 = 0;
      if (*pbVar5 <= bVar7) {
        iVar4 = frame;
      }
      while (uVar9 = (uint)bVar7, (int)uVar9 <= iVar4) {
        pbVar5 = pbVar5 + uVar6 * 2 + 2;
        bVar7 = pbVar5[1];
        uVar6 = (uint)*pbVar5;
        iVar4 = iVar4 - uVar9;
        if (bVar7 < *pbVar5) {
          iVar4 = 0;
        }
      }
      if (iVar4 < (int)uVar6) {
        iVar4 = iVar4 + 1;
        if (iVar4 < (int)uVar6) {
          fVar3 = (1.0 - s) * (float)*(short *)(pbVar5 + iVar4 * 2);
          sVar1 = *(short *)(pbVar5 + iVar4 * 2 + 2);
LAB_000766c6:
          fVar2 = ((float)sVar1 * s + fVar3) * *pfVar8 + fVar2;
          *local_20 = fVar2;
        }
        else {
          fVar2 = (float)*(short *)(pbVar5 + iVar4 * 2) * *pfVar8 + fVar2;
          *local_20 = fVar2;
        }
      }
      else {
        if ((int)uVar9 <= iVar4 + 1) {
          fVar3 = (1.0 - s) * (float)*(short *)(pbVar5 + uVar6 * 2);
          sVar1 = *(short *)(pbVar5 + uVar6 * 2 + 4);
          goto LAB_000766c6;
        }
        fVar2 = (float)*(short *)(pbVar5 + uVar6 * 2) * *pfVar8 + fVar2;
        *local_20 = fVar2;
      }
    }
    if ((pfVar8[-0xc] != -NAN) && (adj != (float *)0x0)) {
      *local_20 = fVar2 + adj[(int)pfVar8[-0xc]];
    }
    local_24 = local_24 + 1;
    pfVar8 = pfVar8 + 1;
    local_20 = local_20 + 1;
    if (local_24 == 3) {
      return;
    }
  } while( true );
}


// R_StudioCalcBoneQuaterion  @ 00076440
void R_StudioCalcBoneQuaterion
               (int frame,float s,mstudiobone_t *pbone,mstudioanim_t *panim,float *adj,float *q)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  byte bVar7;
  float *pfVar8;
  uint uVar9;
  int iVar10;
  float *local_60;
  vec_t local_54 [3];
  float local_48 [3];
  vec_t local_3c [4];
  vec_t local_2c [7];
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: vec4_t q1@[???]
                       Unresolved local var: vec4_t q2@[???]
                       Unresolved local var: vec3_t angle1@[???]
                       Unresolved local var: vec3_t angle2@[???]
                       Unresolved local var: mstudioanimvalue_t * panimvalue@[???] */
  iVar10 = 0;
  local_60 = local_48;
  pfVar8 = pbone->value + 3;
  do {
    if (panim->offset[iVar10 + 3] == 0) {
      fVar1 = *pfVar8;
      local_54[iVar10] = fVar1;
      *local_60 = fVar1;
      fVar3 = fVar1;
    }
    else {
      pbVar5 = (byte *)((int)panim->offset + (uint)panim->offset[iVar10 + 3]);
      bVar7 = pbVar5[1];
      uVar4 = (uint)*pbVar5;
      iVar6 = 0;
      if (*pbVar5 <= bVar7) {
        iVar6 = frame;
      }
      while (uVar9 = (uint)bVar7, (int)uVar9 <= iVar6) {
        pbVar5 = pbVar5 + uVar4 * 2 + 2;
        bVar7 = pbVar5[1];
        uVar4 = (uint)*pbVar5;
        iVar6 = iVar6 - uVar9;
        if (bVar7 < *pbVar5) {
          iVar6 = 0;
        }
      }
      if (iVar6 < (int)uVar4) {
        iVar6 = iVar6 + 1;
        fVar1 = (float)*(short *)(pbVar5 + iVar6 * 2);
        local_54[iVar10] = fVar1;
        if (iVar6 < (int)uVar4) {
          fVar3 = (float)*(short *)(pbVar5 + iVar6 * 2 + 2);
          *local_60 = fVar3;
        }
        else {
          fVar3 = fVar1;
          if (iVar6 < (int)uVar9) goto LAB_0007656e;
          fVar3 = (float)*(short *)(pbVar5 + uVar4 * 2 + 4);
          *local_60 = fVar3;
        }
      }
      else {
        fVar1 = (float)*(short *)(pbVar5 + uVar4 * 2);
        local_54[iVar10] = fVar1;
        fVar3 = fVar1;
        if (iVar6 + 1 < (int)uVar9) {
LAB_0007656e:
          *local_60 = fVar3;
          fVar1 = fVar3;
        }
        else {
          fVar3 = (float)*(short *)(pbVar5 + uVar4 * 2 + 4);
          *local_60 = fVar3;
        }
      }
      fVar1 = fVar1 * pfVar8[6] + *pfVar8;
      local_54[iVar10] = fVar1;
      fVar3 = fVar3 * pfVar8[6] + *pfVar8;
      *local_60 = fVar3;
    }
    if (pfVar8[-6] != -NAN) {
      fVar2 = adj[(int)pfVar8[-6]];
      local_54[iVar10] = fVar1 + fVar2;
      *local_60 = fVar3 + fVar2;
    }
    iVar10 = iVar10 + 1;
    pfVar8 = pfVar8 + 1;
    local_60 = local_60 + 1;
    if (iVar10 == 3) {
      iVar10 = VectorCompare(local_54,local_48);
      if (iVar10 == 0) {
        AngleQuaternion(local_54,local_3c);
        AngleQuaternion(local_48,local_2c);
        QuaternionSlerp(local_3c,local_2c,s,q);
        return;
      }
      AngleQuaternion(local_54,q);
      return;
    }
  } while( true );
}


// R_StudioComputeBounds  @ 00078be0
int R_StudioComputeBounds(byte *pBuffer,float *mins,float *maxs)

{
  short sVar1;
  short sVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  int iVar9;
  float *pfVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  byte *pbVar14;
  byte *pbVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  float *local_a8;
  int local_a4;
  float local_98;
  float *local_94;
  float local_88;
  int local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  int local_64;
  int local_60;
  int local_5c;
  byte *local_58;
  float local_40 [4];
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
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
  iVar6 = *(int *)(pBuffer + 0xd0);
  if (*(int *)(pBuffer + 0xcc) < 1) {
    local_64 = 0;
    local_88 = 0.0;
    local_70 = 0.0;
    local_74 = 0.0;
    local_78 = 0.0;
    local_80 = 0.0;
    local_7c = 0.0;
  }
  else {
    iVar9 = 0;
    iVar16 = *(int *)(pBuffer + 0xcc) * 0x4c;
    piVar13 = (int *)(pBuffer + iVar6 + 0x40);
    do {
      iVar19 = *piVar13;
      piVar13 = piVar13 + 0x13;
      iVar9 = iVar9 + iVar19;
    } while (piVar13 != (int *)(pBuffer + iVar16 + iVar6 + 0x40));
    if (iVar9 < 1) {
      local_64 = 0;
      local_88 = 0.0;
      local_70 = 0.0;
      local_74 = 0.0;
      local_78 = 0.0;
      local_80 = 0.0;
      local_7c = 0.0;
    }
    else {
      local_7c = 0.0;
      pbVar14 = pBuffer + iVar16 + iVar6;
      local_64 = 0;
      local_74 = local_7c;
      local_88 = local_7c;
      local_78 = local_7c;
      local_70 = local_7c;
      local_80 = local_7c;
      do {
        if (0 < *(int *)(pbVar14 + 0x50)) {
          iVar19 = *(int *)(pbVar14 + 0x50) + local_64;
          pfVar10 = (float *)(pBuffer + *(int *)(pbVar14 + 0x58));
          do {
            while (local_64 == 0) {
              local_7c = *pfVar10;
              local_64 = 1;
              local_70 = pfVar10[1];
              local_88 = pfVar10[2];
              pfVar10 = pfVar10 + 3;
              local_74 = local_7c;
              local_78 = local_88;
              local_80 = local_70;
              if (iVar19 == 1) goto LAB_00078cfc;
            }
                    /* Unresolved local var: int i@[???] */
            fVar3 = *pfVar10;
            if (fVar3 < local_7c) {
              local_7c = fVar3;
            }
            if (fVar3 <= local_74) {
              fVar3 = local_74;
            }
            fVar4 = pfVar10[1];
            if (fVar4 < local_80) {
              local_80 = fVar4;
            }
            if (fVar4 <= local_70) {
              fVar4 = local_70;
            }
            local_70 = fVar4;
            fVar4 = pfVar10[2];
            if (fVar4 < local_78) {
              local_78 = fVar4;
            }
            if (fVar4 <= local_88) {
              fVar4 = local_88;
            }
            local_88 = fVar4;
            local_64 = local_64 + 1;
            pfVar10 = pfVar10 + 3;
            local_74 = fVar3;
          } while (local_64 != iVar19);
        }
LAB_00078cfc:
        pbVar14 = pbVar14 + 0x70;
      } while (pbVar14 != pBuffer + iVar16 + iVar9 * 0x70 + iVar6);
    }
  }
  local_5c = *(int *)(pBuffer + 0xa4);
  iVar6 = *(int *)(pBuffer + 0x90);
  if (0 < local_5c) {
    local_2c = 0.0;
    local_58 = pBuffer + *(int *)(pBuffer + 0xa8);
    local_98 = 0.0;
    local_60 = 0;
    fVar3 = local_2c;
    local_30 = local_2c;
    fVar4 = local_2c;
    local_40[3] = local_2c;
    do {
      iVar9 = *(int *)(local_58 + 0x38);
      iVar16 = *(int *)(local_58 + 0x7c);
      iVar19 = *(int *)(pBuffer + 0x8c);
      if (0 < iVar19) {
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: mstudioanimvalue_t * panimvalue@[???] */
        local_84 = 0;
        local_a4 = 0;
        local_94 = (float *)(pBuffer + iVar6 + 0x58);
        do {
          iVar7 = local_a4;
          if (0 < iVar9) {
            iVar11 = iVar9 + local_a4;
            do {
              iVar20 = 0;
              local_a8 = local_94;
              do {
                fVar5 = local_a8[-6];
                local_40[iVar20] = fVar5;
                if (*(ushort *)(pBuffer + iVar20 * 2 + iVar16) != 0) {
                  pbVar15 = pBuffer + (uint)*(ushort *)(pBuffer + iVar20 * 2 + iVar16) + iVar16;
                  uVar18 = (uint)pbVar15[1];
                  uVar17 = (uint)*pbVar15;
                  iVar12 = local_a4 - iVar7;
                  if (pbVar15[1] < *pbVar15) {
                    iVar12 = 0;
                  }
                  while ((int)uVar18 <= iVar12) {
                    pbVar15 = pbVar15 + uVar17 * 2 + 2;
                    iVar12 = iVar12 - uVar18;
                    uVar18 = (uint)pbVar15[1];
                    uVar17 = (uint)*pbVar15;
                    if (pbVar15[1] < *pbVar15) {
                      iVar12 = 0;
                    }
                  }
                  if (iVar12 < (int)uVar17) {
                    iVar12 = iVar12 + 1;
                    if (iVar12 < (int)uVar17) {
                      sVar1 = *(short *)(pbVar15 + iVar12 * 2 + 2);
                      sVar2 = *(short *)(pbVar15 + iVar12 * 2);
LAB_00078e69:
                      local_40[iVar20] = ((float)sVar2 + (float)sVar1 * 0.0) * *local_a8 + fVar5;
                    }
                    else {
                      local_40[iVar20] = (float)*(short *)(pbVar15 + iVar12 * 2) * *local_a8 + fVar5
                      ;
                    }
                  }
                  else {
                    if ((int)uVar18 <= iVar12 + 1) {
                      sVar1 = *(short *)(pbVar15 + uVar17 * 2 + 4);
                      sVar2 = *(short *)(pbVar15 + uVar17 * 2);
                      goto LAB_00078e69;
                    }
                    local_40[iVar20] = (float)*(short *)(pbVar15 + uVar17 * 2) * *local_a8 + fVar5;
                  }
                }
                iVar20 = iVar20 + 1;
                local_a8 = local_a8 + 1;
              } while (iVar20 != 3);
                    /* Unresolved local var: int i@[???] */
              fVar5 = local_40[2];
              if (local_a4 == 0) {
                local_98 = local_40[0];
                fVar3 = local_40[2];
                local_30 = local_40[1];
                fVar4 = local_40[1];
                local_40[3] = local_40[0];
              }
              else {
                if (local_40[0] < local_98) {
                  local_98 = local_40[0];
                }
                fVar8 = local_40[0];
                if (local_40[0] <= local_40[3]) {
                  fVar8 = local_40[3];
                }
                local_40[3] = fVar8;
                if (local_40[1] < fVar4) {
                  fVar4 = local_40[1];
                }
                fVar8 = local_40[1];
                if (local_40[1] <= local_30) {
                  fVar8 = local_30;
                }
                local_30 = fVar8;
                if (local_40[2] < fVar3) {
                  fVar3 = local_40[2];
                }
                if (local_40[2] <= local_2c) {
                  fVar5 = local_2c;
                }
              }
              local_2c = fVar5;
              local_a4 = local_a4 + 1;
            } while (local_a4 != iVar11);
          }
          local_84 = local_84 + 1;
          local_94 = local_94 + 0x1c;
        } while (local_84 != iVar19);
                    /* Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: vec3_t point@[???] */
        if (local_a4 != 0) {
                    /* Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: vec3_t point@[???] */
          local_40[3] = local_40[3] - local_98;
          local_30 = local_30 - fVar4;
          local_2c = local_2c - fVar3;
          VectorScale(local_40 + 3,0.5,&local_28);
                    /* Unresolved local var: int i@[???] */
          fVar3 = local_28;
          fVar4 = local_24;
          fVar5 = local_20;
          if (local_64 == 0) {
            local_80 = local_24;
            local_78 = local_20;
            local_7c = local_28;
          }
          else {
            if (local_28 < local_7c) {
              local_7c = local_28;
            }
            if (local_28 <= local_74) {
              fVar3 = local_74;
            }
            if (local_24 < local_80) {
              local_80 = local_24;
            }
            if (local_24 <= local_70) {
              fVar4 = local_70;
            }
            if (local_20 < local_78) {
              local_78 = local_20;
            }
            if (local_20 <= local_88) {
              fVar5 = local_88;
            }
          }
          VectorScale(local_40 + 3,-0.5,&local_28);
          local_5c = *(int *)(pBuffer + 0xa4);
                    /* Unresolved local var: int i@[???] */
          if (local_28 < local_7c) {
            local_7c = local_28;
          }
          local_74 = local_28;
          if (local_28 <= fVar3) {
            local_74 = fVar3;
          }
          if (local_24 < local_80) {
            local_80 = local_24;
          }
          local_70 = local_24;
          if (local_24 <= fVar4) {
            local_70 = fVar4;
          }
          if (local_20 < local_78) {
            local_78 = local_20;
          }
          local_88 = local_20;
          if (local_20 <= fVar5) {
            local_88 = fVar5;
          }
          local_64 = local_64 + 2;
          fVar4 = 0.0;
          local_30 = 0.0;
          fVar3 = 0.0;
          local_98 = 0.0;
          local_40[3] = fVar4;
          local_2c = fVar4;
        }
      }
      local_60 = local_60 + 1;
      local_58 = local_58 + 0xb0;
    } while (local_60 < local_5c);
  }
  *mins = local_7c;
  mins[1] = local_80;
  mins[2] = local_78;
  *maxs = local_74;
  maxs[1] = local_70;
  maxs[2] = local_88;
  return 1;
}


// R_StudioHull  @ 000775a0
hull_t * R_StudioHull(model_t *pModel,float frame,int sequence,vec_t *angles,vec_t *origin,
                     vec_t *size,byte *pcontroller,byte *pblending,int *pNumHulls,edict_t *pEdict,
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
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  studiohdr_t *psVar20;
  uint uVar21;
  hull_t *phVar22;
  hull_t *phVar23;
  char *pcVar24;
  mplane_t *pmVar25;
  int iVar26;
  int iVar27;
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
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???] */
    studio_clipnodes[0].planenum = 0;
    studio_clipnodes[1].children[0] = 2;
    studio_clipnodes[2].planenum = 2;
    studio_clipnodes[2].children[0] = -1;
    studio_clipnodes[2].children[1] = 3;
    studio_clipnodes[3].planenum = 3;
    studio_clipnodes[3].children[1] = -1;
    studio_clipnodes[5].planenum = 5;
    studio_clipnodes[0].children[0] = -1;
    studio_clipnodes[0].children[1] = 1;
    studio_clipnodes[1].planenum = 1;
    studio_clipnodes[1].children[1] = -1;
    studio_clipnodes[5].children[1] = -1;
    studio_clipnodes[3].children[0] = 4;
    pmVar25 = studio_planes;
    studio_clipnodes[4].planenum = 4;
    studio_clipnodes[5].children[0] = -2;
    studio_clipnodes[4].children[0] = -1;
    studio_clipnodes[4].children[1] = 5;
    phVar22 = studio_hull;
    do {
      phVar22->planes = pmVar25;
      phVar23 = phVar22 + 1;
      pmVar25 = pmVar25 + 6;
      phVar22->clipnodes = studio_clipnodes;
      phVar22->firstclipnode = 0;
      phVar22->lastclipnode = 5;
      phVar22 = phVar23;
    } while (phVar23 != (hull_t *)studio_hull_hitgroup);
  }
  if (r_cachestudio.value != 0.0) {
    iVar26 = 0;
    do {
      uVar21 = r_cachecurrent - iVar26 & 0xf;
      if (((((pModel == rgStudioCache[uVar21].pModel) && (frame == rgStudioCache[uVar21].frame)) &&
           (sequence == rgStudioCache[uVar21].sequence)) &&
          ((iVar27 = VectorCompare(rgStudioCache[uVar21].angles,angles), iVar27 != 0 &&
           (iVar27 = VectorCompare(rgStudioCache[uVar21].origin,origin), iVar27 != 0)))) &&
         ((iVar27 = VectorCompare(rgStudioCache[uVar21].size,size), iVar27 != 0 &&
          ((iVar27 = Q_memcmp(rgStudioCache[uVar21].controller,pcontroller,4), iVar27 == 0 &&
           (iVar27 = Q_memcmp(rgStudioCache[uVar21].blending,pblending,2), iVar27 == 0)))))) {
        Q_memcpy(studio_planes,cache_planes + rgStudioCache[uVar21].nStartPlane,
                 rgStudioCache[uVar21].numhulls * 0x78);
        Q_memcpy(studio_hull,cache_hull + rgStudioCache[uVar21].nStartHull,
                 rgStudioCache[uVar21].numhulls * 0x28);
        Q_memcpy(studio_hull_hitgroup,cache_hull_hitgroup + rgStudioCache[uVar21].nStartHull,
                 rgStudioCache[uVar21].numhulls << 2);
        *pNumHulls = rgStudioCache[uVar21].numhulls;
        goto LAB_00077a84;
      }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: r_studiocache_t * pCached@[???] */
      iVar26 = iVar26 + 1;
    } while (iVar26 != 0x10);
  }
  pstudiohdr = Mod_Extradata(pModel);
  local_20 = angles[2];
  local_28 = -*angles;
  local_24 = angles[1];
  (*g_pSvBlendingAPI->SV_StudioSetupBones)
            (pModel,frame,sequence,&local_28,origin,pcontroller,pblending,-1,pEdict);
  psVar20 = pstudiohdr;
  iVar26 = pstudiohdr->numhitboxes;
  if (0 < iVar26) {
    iVar27 = 0;
    pmVar25 = studio_planes;
    pcVar24 = pstudiohdr->name + pstudiohdr->hitboxindex + -8;
    do {
      while ((iVar27 != 0x15 || (bSkipShield != 1))) {
        studio_hull_hitgroup[iVar27] = *(int *)(pcVar24 + 4);
        iVar27 = iVar27 + 1;
        iVar26 = *(int *)pcVar24;
        fVar1 = *(float *)(pcVar24 + 0x14);
        pmVar25->type = '\x05';
        fVar2 = bonetransform[iVar26][0][0];
        pmVar25->normal[0] = fVar2;
        fVar3 = bonetransform[iVar26][1][0];
        fVar4 = bonetransform[iVar26][2][0];
        fVar5 = bonetransform[iVar26][0][3];
        pmVar25->normal[1] = fVar3;
        fVar6 = bonetransform[iVar26][1][3];
        pmVar25->normal[2] = fVar4;
        pmVar25->dist = fVar3 * fVar6 + fVar5 * fVar2 + bonetransform[iVar26][2][3] * fVar4 + fVar1;
        iVar26 = *(int *)pcVar24;
        fVar1 = *(float *)(pcVar24 + 8);
        pmVar25[1].type = '\x05';
        fVar5 = bonetransform[iVar26][0][0];
        fVar6 = bonetransform[iVar26][1][0];
        fVar7 = bonetransform[iVar26][2][0];
        pmVar25[1].normal[0] = fVar5;
        pmVar25[1].normal[1] = fVar6;
        fVar8 = bonetransform[iVar26][0][3];
        pmVar25[1].normal[2] = fVar7;
        pmVar25[1].dist =
             fVar7 * bonetransform[iVar26][2][3] +
             fVar5 * fVar8 + bonetransform[iVar26][1][3] * fVar6 + fVar1;
        iVar26 = *(int *)pcVar24;
        fVar1 = *(float *)(pcVar24 + 0x18);
        pmVar25[2].type = '\x05';
        fVar8 = bonetransform[iVar26][0][1];
        fVar9 = bonetransform[iVar26][1][1];
        fVar10 = bonetransform[iVar26][2][1];
        fVar11 = bonetransform[iVar26][0][3];
        pmVar25[2].normal[0] = fVar8;
        pmVar25[2].normal[1] = fVar9;
        pmVar25[2].normal[2] = fVar10;
        pmVar25[2].dist =
             fVar10 * bonetransform[iVar26][2][3] +
             fVar9 * bonetransform[iVar26][1][3] + fVar8 * fVar11 + fVar1;
        iVar26 = *(int *)pcVar24;
        fVar1 = *(float *)(pcVar24 + 0xc);
        pmVar25[3].type = '\x05';
        fVar11 = bonetransform[iVar26][0][1];
        fVar12 = bonetransform[iVar26][1][1];
        fVar13 = bonetransform[iVar26][2][1];
        fVar14 = bonetransform[iVar26][0][3];
        pmVar25[3].normal[0] = fVar11;
        pmVar25[3].normal[1] = fVar12;
        pmVar25[3].normal[2] = fVar13;
        pmVar25[3].dist =
             fVar13 * bonetransform[iVar26][2][3] +
             fVar12 * bonetransform[iVar26][1][3] + fVar11 * fVar14 + fVar1;
        iVar26 = *(int *)pcVar24;
        fVar1 = *(float *)(pcVar24 + 0x1c);
        pmVar25[4].type = '\x05';
        fVar14 = bonetransform[iVar26][0][2];
        pmVar25[4].normal[0] = fVar14;
        fVar15 = bonetransform[iVar26][1][2];
        fVar16 = bonetransform[iVar26][2][2];
        pmVar25[4].normal[2] = fVar16;
        fVar17 = bonetransform[iVar26][0][3];
        pmVar25[4].normal[1] = fVar15;
        pmVar25[4].dist =
             bonetransform[iVar26][2][3] * fVar16 +
             fVar17 * fVar14 + bonetransform[iVar26][1][3] * fVar15 + fVar1;
        iVar26 = *(int *)pcVar24;
        fVar1 = *(float *)(pcVar24 + 0x10);
        pmVar25[5].type = '\x05';
        fVar17 = bonetransform[iVar26][0][2];
        pmVar25[5].normal[0] = fVar17;
        fVar18 = bonetransform[iVar26][1][2];
        pmVar25[5].normal[1] = fVar18;
        fVar19 = bonetransform[iVar26][2][2];
        pmVar25[5].normal[2] = fVar19;
        pmVar25[5].dist =
             bonetransform[iVar26][2][3] * fVar19 +
             bonetransform[iVar26][1][3] * fVar18 + bonetransform[iVar26][0][3] * fVar17 + fVar1;
        pmVar25->dist =
             ABS(fVar4 * size[2]) + ABS(fVar3 * size[1]) + ABS(fVar2 * *size) + pmVar25->dist;
        pmVar25[1].dist =
             pmVar25[1].dist - (ABS(fVar7 * size[2]) + ABS(fVar6 * size[1]) + ABS(fVar5 * *size));
        pmVar25[2].dist =
             ABS(fVar10 * size[2]) + ABS(fVar9 * size[1]) + ABS(fVar8 * *size) + pmVar25[2].dist;
        pmVar25[3].dist =
             pmVar25[3].dist - (ABS(fVar13 * size[2]) + ABS(fVar12 * size[1]) + ABS(fVar11 * *size))
        ;
        pmVar25[4].dist =
             ABS(fVar16 * size[2]) + ABS(fVar15 * size[1]) + ABS(fVar14 * *size) + pmVar25[4].dist;
        pmVar25[5].dist =
             pmVar25[5].dist - (ABS(fVar19 * size[2]) + ABS(fVar18 * size[1]) + ABS(fVar17 * *size))
        ;
        iVar26 = psVar20->numhitboxes;
        pmVar25 = pmVar25 + 6;
        pcVar24 = pcVar24 + 0x20;
        if (iVar26 <= iVar27) goto LAB_00077a52;
      }
      iVar27 = 0x16;
      pcVar24 = pcVar24 + 0x20;
      pmVar25 = pmVar25 + 6;
    } while (0x16 < iVar26);
  }
LAB_00077a52:
  iVar26 = iVar26 - (uint)(bSkipShield == 1);
  *pNumHulls = iVar26;
  if (r_cachestudio.value != 0.0) {
    R_AddToStudioCache(frame,sequence,angles,origin,size,pcontroller,pblending,pModel,studio_hull,
                       iVar26);
    return studio_hull;
  }
LAB_00077a84:
  return studio_hull;
}


// R_StudioPlayerBlend  @ 00077ed0
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
    if (0.1 <= fVar2 - fVar1) {
      *pBlend = (int)(((fVar3 - fVar1) * 255.0) / (fVar2 - fVar1));
      *pPitch = 0.0;
    }
    else {
      *pBlend = 0x7f;
      *pPitch = 0.0;
    }
    return;
  }
  *pPitch = *pPitch - fVar2 / 3.0;
  *pBlend = 0xff;
  return;
}


// R_StudioSlerpBones  @ 00076750
void R_StudioSlerpBones(vec4_t *q1,vec3_t *pos1,vec4_t *q2,vec3_t *pos2,float s)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  studiohdr_t *psVar10;
  double dVar11;
  float local_4c;
  float local_44;
  float local_40;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec4_t q3@[???]
                       Unresolved local var: float s1@[???] */
  if (s < 0.0) {
    s = 0.0;
    local_40 = 1.0;
  }
  else if (s <= 1.0) {
    local_40 = 1.0 - s;
  }
  else {
    local_40 = 0.0;
    s = 1.0;
  }
  if (0 < pstudiohdr->numbones) {
    iVar9 = 0;
    psVar10 = pstudiohdr;
    do {
      fVar1 = (*q1)[0];
      fVar2 = (*q2)[0];
      local_44 = (*q1)[1];
      fVar3 = (*q2)[1];
      local_4c = (*q1)[2];
      fVar4 = (*q2)[2];
      fVar5 = (*q1)[3];
      fVar6 = (*q2)[3];
      if ((fVar6 + fVar5) * (fVar6 + fVar5) +
          (local_4c + fVar4) * (local_4c + fVar4) +
          (fVar3 + local_44) * (fVar3 + local_44) + (fVar1 + fVar2) * (fVar1 + fVar2) + 0.0 <
          (fVar5 - fVar6) * (fVar5 - fVar6) +
          (local_4c - fVar4) * (local_4c - fVar4) +
          (local_44 - fVar3) * (local_44 - fVar3) + (fVar1 - fVar2) * (fVar1 - fVar2) + 0.0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float a@[???]
                       Unresolved local var: float b@[???] */
        fVar2 = -fVar2;
        (*q2)[0] = fVar2;
        fVar3 = -fVar3;
        fVar4 = -fVar4;
        (*q2)[2] = fVar4;
        fVar6 = -fVar6;
        (*q2)[1] = fVar3;
        (*q2)[3] = fVar6;
        fVar1 = (*q1)[0];
        local_44 = (*q1)[1];
        local_4c = (*q1)[2];
        fVar5 = (*q1)[3];
      }
      cosom = fVar6 * fVar5 + local_4c * fVar4 + local_44 * fVar3 + fVar2 * fVar1;
      if (cosom + 1.0 <= 1e-06) {
        fVar1 = (*q2)[0];
        dVar11 = sin((double)((1.0 - s) * 1.5707964));
        fVar5 = (float)dVar11;
        sclp = fVar5;
        dVar11 = sin((double)s * 1.5707963267948966);
        sclq = (float)dVar11;
        fVar7 = (*q1)[0] * fVar5 - fVar3 * sclq;
        fVar2 = local_44 * fVar5 + fVar1 * sclq;
        fVar1 = fVar5 * local_4c - sclq * fVar6;
      }
      else {
        if (1e-06 < 1.0 - cosom) {
          dVar11 = acos((double)cosom);
          fVar1 = (float)dVar11;
          omega = fVar1;
          dVar11 = sin((double)fVar1);
          fVar2 = (float)dVar11;
          sinom = fVar2;
          dVar11 = sin((1.0 - (double)s) * (double)fVar1);
          fVar8 = (float)dVar11 / fVar2;
          sclp = fVar8;
          dVar11 = sin((double)(fVar1 * s));
          sclq = (float)dVar11 / fVar2;
          local_44 = (*q1)[1];
          fVar3 = (*q2)[1];
          local_4c = (*q1)[2];
          fVar4 = (*q2)[2];
          fVar5 = (*q1)[3];
          fVar6 = (*q2)[3];
          psVar10 = pstudiohdr;
        }
        else {
          sclp = local_40;
          sclq = s;
          fVar8 = local_40;
        }
        fVar7 = (*q2)[0] * sclq + (*q1)[0] * fVar8;
        fVar2 = fVar3 * sclq + local_44 * fVar8;
        fVar1 = fVar4 * sclq + local_4c * fVar8;
        fVar4 = sclq * fVar6 + fVar8 * fVar5;
      }
      (*q1)[0] = fVar7;
      iVar9 = iVar9 + 1;
      (*q1)[1] = fVar2;
      q2 = q2 + 1;
      (*q1)[2] = fVar1;
      (*q1)[3] = fVar4;
      q1 = q1 + 1;
      (*pos1)[0] = s * (*pos2)[0] + (*pos1)[0] * local_40;
      (*pos1)[1] = s * (*pos2)[1] + (*pos1)[1] * local_40;
      (*pos1)[2] = s * (*pos2)[2] + (*pos1)[2] * local_40;
      pos2 = pos2 + 1;
      pos1 = pos1 + 1;
    } while (iVar9 < psVar10->numbones);
  }
  return;
}


