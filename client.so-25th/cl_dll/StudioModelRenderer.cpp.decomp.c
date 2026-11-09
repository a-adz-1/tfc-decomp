// Ghidra decompilation of functions from cl_dll/StudioModelRenderer.cpp
// 32 functions, ordered by original source line

// CStudioModelRenderer::Init  @ 0007c260  (line 50)

/* DWARF original prototype: void Init(CStudioModelRenderer * this) */

void __thiscall CStudioModelRenderer::Init(CStudioModelRenderer *this)

{
  cvar_s *pcVar1;
  model_s *pmVar2;
  float (*paaafVar3) [128] [3] [4];
  float (*paafVar4) [3] [4];
  
  pcVar1 = (*IEngineStudio.GetCvar)("cl_himodels");
  this->m_pCvarHiModels = pcVar1;
  pcVar1 = (*IEngineStudio.GetCvar)("developer");
  this->m_pCvarDeveloper = pcVar1;
  pcVar1 = (*IEngineStudio.GetCvar)("r_drawentities");
  this->m_pCvarDrawEntities = pcVar1;
  pmVar2 = (*IEngineStudio.GetChromeSprite)();
  this->m_pChromeSprite = pmVar2;
  (*IEngineStudio.GetModelCounters)(&this->m_pStudioModelCount,&this->m_pModelsDrawn);
  paaafVar3 = (float (*) [128] [3] [4])(*IEngineStudio.StudioGetBoneTransform)();
  this->m_pbonetransform = paaafVar3;
  paaafVar3 = (float (*) [128] [3] [4])(*IEngineStudio.StudioGetLightTransform)();
  this->m_plighttransform = paaafVar3;
  paafVar4 = (float (*) [3] [4])(*IEngineStudio.StudioGetAliasTransform)();
  this->m_paliastransform = paafVar4;
  paafVar4 = (float (*) [3] [4])(*IEngineStudio.StudioGetRotationMatrix)();
  this->m_protationmatrix = paafVar4;
  return;
}


// CStudioModelRenderer::CStudioModelRenderer  @ 000819b0  (line 73)

/* DWARF original prototype: void CStudioModelRenderer(CStudioModelRenderer * this) */

void __thiscall CStudioModelRenderer::CStudioModelRenderer(CStudioModelRenderer *this)

{
  this->m_pStudioModelCount = (int *)0x0;
  this->m_pModelsDrawn = (int *)0x0;
  this->m_protationmatrix = (float (*) [3] [4])0x0;
  this->m_paliastransform = (float (*) [3] [4])0x0;
  this->_vptr_CStudioModelRenderer = (_func_int_varargs **)&PTR__CStudioModelRenderer_000c354c;
  this->m_fDoInterp = 1;
  this->m_fGaitEstimation = 1;
  this->m_pCurrentEntity = (cl_entity_t_conflict *)0x0;
  this->m_pCvarHiModels = (cvar_t *)0x0;
  this->m_pCvarDeveloper = (cvar_t *)0x0;
  this->m_pCvarDrawEntities = (cvar_t *)0x0;
  this->m_pChromeSprite = (model_t *)0x0;
  this->m_pbonetransform = (float (*) [128] [3] [4])0x0;
  this->m_plighttransform = (float (*) [128] [3] [4])0x0;
  this->m_pStudioHeader = (_1studiohdr_t *)0x0;
  this->m_pBodyPart = (mstudiobodyparts_t *)0x0;
  this->m_pSubModel = (mstudiomodel_t *)0x0;
  this->m_pPlayerInfo = (player_info_t *)0x0;
  this->m_pRenderModel = (model_t *)0x0;
  return;
}


// CStudioModelRenderer::~CStudioModelRenderer  @ 0007c2f0  (line 101)

/* DWARF original prototype: void ~CStudioModelRenderer(CStudioModelRenderer * this, int __in_chrg)
    */

void __thiscall
CStudioModelRenderer::~CStudioModelRenderer(CStudioModelRenderer *this,int __in_chrg)

{
  return;
}


// CStudioModelRenderer::~CStudioModelRenderer  @ 0007cbc0  (line 103)

/* DWARF original prototype: void ~CStudioModelRenderer(CStudioModelRenderer * this, int __in_chrg)
    */

void __thiscall
CStudioModelRenderer::~CStudioModelRenderer(CStudioModelRenderer *this,int __in_chrg)

{
  operator_delete(this);
  return;
}


// CStudioModelRenderer::StudioCalcBoneAdj  @ 0007c300  (line 112)

/* DWARF original prototype: void StudioCalcBoneAdj(CStudioModelRenderer * this, float dadt, float *
   adj, byte * pcontroller1, byte * pcontroller2, byte mouthopen) */

void __thiscall
CStudioModelRenderer::StudioCalcBoneAdj
          (CStudioModelRenderer *this,float dadt,float *adj,byte *pcontroller1,byte *pcontroller2,
          byte mouthopen)

{
  int iVar1;
  float fVar2;
  float fVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  _1studiohdr_t *p1Var8;
  uint uVar9;
  float local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: float value@[???]
                       Unresolved local var: mstudiobonecontroller_t * pbonecontroller@[???] */
  p1Var8 = this->m_pStudioHeader;
  pcVar4 = p1Var8->name + p1Var8->bonecontrollerindex + -8;
  if (0 < p1Var8->numbonecontrollers) {
    iVar7 = 0;
    do {
      while( true ) {
        iVar1 = *(int *)(pcVar4 + 0x14);
        if (iVar1 < 4) {
          uVar5 = *(uint *)(pcVar4 + 4);
          if ((uVar5 & 0x8000) == 0) {
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
            local_24 = fVar2 * *(float *)(pcVar4 + 0xc) + fVar3 * *(float *)(pcVar4 + 8);
          }
          else {
            uVar6 = (uint)pcontroller1[iVar1] - (uint)pcontroller2[iVar1];
            uVar9 = (int)uVar6 >> 0x1f;
            if ((int)((uVar6 ^ uVar9) - uVar9) < 0x81) {
              local_24 = ((float)pcontroller1[iVar1] * dadt +
                         (1.0 - dadt) * (float)pcontroller2[iVar1]) * 1.40625 +
                         *(float *)(pcVar4 + 8);
            }
            else {
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???] */
              local_24 = (((float)(byte)(pcontroller1[iVar7] + 0x80) * dadt +
                          (1.0 - dadt) * (float)(byte)(pcontroller2[iVar7] + 0x80)) - 128.0) *
                         1.40625 + *(float *)(pcVar4 + 8);
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
          local_24 = fVar2 * *(float *)(pcVar4 + 0xc) + fVar3 * *(float *)(pcVar4 + 8);
          uVar5 = *(uint *)(pcVar4 + 4);
        }
        uVar5 = (uVar5 & 0x7fff) - 1;
        if (uVar5 < 0x20) break;
LAB_0007c400:
        iVar7 = iVar7 + 1;
        pcVar4 = pcVar4 + 0x18;
        if (p1Var8->numbonecontrollers <= iVar7) {
          return;
        }
      }
      uVar5 = 1 << ((byte)uVar5 & 0x1f);
      if ((uVar5 & 0x80008080) == 0) {
        if ((uVar5 & 0xb) != 0) {
          adj[iVar7] = local_24;
          p1Var8 = this->m_pStudioHeader;
        }
        goto LAB_0007c400;
      }
      pcVar4 = pcVar4 + 0x18;
      adj[iVar7] = local_24 * 0.017453292;
      iVar7 = iVar7 + 1;
      p1Var8 = this->m_pStudioHeader;
    } while (iVar7 < p1Var8->numbonecontrollers);
  }
  return;
}


// CStudioModelRenderer::StudioCalcBoneQuaterion  @ 0007cd30  (line 179)

/* DWARF original prototype: void StudioCalcBoneQuaterion(CStudioModelRenderer * this, int frame,
   float s, mstudiobone_t * pbone, mstudioanim_t * panim, float * adj, float * q) */

void __thiscall
CStudioModelRenderer::StudioCalcBoneQuaterion
          (CStudioModelRenderer *this,int frame,float s,mstudiobone_t *pbone,mstudioanim_t *panim,
          float *adj,float *q)

{
  short sVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  byte bVar8;
  float *pfVar9;
  uint uVar10;
  float *local_68;
  float *local_64;
  ushort *local_60;
  float local_54 [6];
  float local_3c [4];
  vec_t local_2c [7];
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: vec4_t q1@[???]
                       Unresolved local var: vec4_t q2@[???]
                       Unresolved local var: Vector angle1@[???]
                       Unresolved local var: Vector angle2@[???]
                       Unresolved local var: mstudioanimvalue_t * panimvalue@[???] */
  local_60 = panim->offset + 3;
  local_68 = local_54 + 3;
  local_64 = local_54;
  pfVar9 = pbone->value + 3;
  do {
    if (*local_60 == 0) {
      fVar2 = *pfVar9;
      *local_64 = fVar2;
      *local_68 = fVar2;
      fVar4 = fVar2;
    }
    else {
      pbVar6 = (byte *)((int)panim->offset + (uint)*local_60);
      bVar8 = pbVar6[1];
      uVar7 = (uint)*pbVar6;
      iVar5 = 0;
      if (*pbVar6 <= bVar8) {
        iVar5 = frame;
      }
      while (uVar10 = (uint)bVar8, (int)uVar10 <= iVar5) {
        pbVar6 = pbVar6 + uVar7 * 2 + 2;
        bVar8 = pbVar6[1];
        uVar7 = (uint)*pbVar6;
        iVar5 = iVar5 - uVar10;
        if (bVar8 < *pbVar6) {
          iVar5 = 0;
        }
      }
      if (iVar5 < (int)uVar7) {
        iVar5 = iVar5 + 1;
        fVar2 = (float)*(short *)(pbVar6 + iVar5 * 2);
        *local_64 = fVar2;
        if (iVar5 < (int)(uint)*pbVar6) {
          sVar1 = *(short *)(pbVar6 + iVar5 * 2 + 2);
          *local_68 = (float)sVar1;
          fVar4 = (float)sVar1;
        }
        else if (iVar5 < (int)(uint)pbVar6[1]) {
          *local_68 = fVar2;
          fVar4 = fVar2;
        }
        else {
          sVar1 = *(short *)(pbVar6 + (uint)*pbVar6 * 2 + 4);
          *local_68 = (float)sVar1;
          fVar4 = (float)sVar1;
        }
      }
      else {
        fVar2 = (float)*(short *)(pbVar6 + uVar7 * 2);
        *local_64 = fVar2;
        if (iVar5 + 1 < (int)(uint)pbVar6[1]) {
          *local_68 = fVar2;
          fVar4 = fVar2;
        }
        else {
          sVar1 = *(short *)(pbVar6 + (uint)*pbVar6 * 2 + 4);
          *local_68 = (float)sVar1;
          fVar4 = (float)sVar1;
        }
      }
      fVar2 = fVar2 * pfVar9[6] + *pfVar9;
      *local_64 = fVar2;
      fVar4 = fVar4 * pfVar9[6] + *pfVar9;
      *local_68 = fVar4;
    }
    if (pfVar9[-6] != -NAN) {
      fVar3 = adj[(int)pfVar9[-6]];
      *local_64 = fVar2 + fVar3;
      *local_68 = fVar4 + fVar3;
    }
    local_68 = local_68 + 1;
    pfVar9 = pfVar9 + 1;
    local_60 = local_60 + 1;
    local_64 = local_64 + 1;
  } while (local_3c != local_68);
  iVar5 = VectorCompare(local_54,local_54 + 3);
  if (iVar5 == 0) {
    AngleQuaternion(local_54,local_3c);
    AngleQuaternion(local_54 + 3,local_2c);
    QuaternionSlerp(local_3c,local_2c,s,q);
    return;
  }
  AngleQuaternion(local_54,q);
  return;
}


// CStudioModelRenderer::StudioCalcBonePosition  @ 0007c570  (line 265)

/* DWARF original prototype: void StudioCalcBonePosition(CStudioModelRenderer * this, int frame,
   float s, mstudiobone_t * pbone, mstudioanim_t * panim, float * adj, float * pos) */

void __thiscall
CStudioModelRenderer::StudioCalcBonePosition
          (CStudioModelRenderer *this,int frame,float s,mstudiobone_t *pbone,mstudioanim_t *panim,
          float *adj,float *pos)

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
LAB_0007c626:
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
          goto LAB_0007c626;
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


// CStudioModelRenderer::StudioSlerpBones  @ 0007cbd0  (line 333)

/* DWARF original prototype: void StudioSlerpBones(CStudioModelRenderer * this, vec4_t * q1,
   float[3] * pos1, vec4_t * q2, float[3] * pos2, float s) */

void __thiscall
CStudioModelRenderer::StudioSlerpBones
          (CStudioModelRenderer *this,vec4_t *q1,float (*pos1) [3],vec4_t *q2,float (*pos2) [3],
          float s)

{
  int iVar1;
  float local_30;
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec4_t q3@[???]
                       Unresolved local var: float s1@[???] */
  if (s < 0.0) {
    s = 0.0;
    local_30 = 1.0;
  }
  else if (s <= 1.0) {
    local_30 = 1.0 - s;
  }
  else {
    local_30 = 0.0;
    s = 1.0;
  }
  if (0 < this->m_pStudioHeader->numbones) {
    iVar1 = 0;
    do {
      QuaternionSlerp(q1,q2,s,&local_2c);
      *(vec_t *)q1 = local_2c;
      *(vec_t *)((int)q1 + 4) = local_28;
      *(vec_t *)((int)q1 + 8) = local_24;
      *(vec_t *)((int)q1 + 0xc) = local_20;
      iVar1 = iVar1 + 1;
      (*pos1)[0] = s * (*pos2)[0] + (*pos1)[0] * local_30;
      (*pos1)[1] = s * (*pos2)[1] + (*pos1)[1] * local_30;
      (*pos1)[2] = s * (*pos2)[2] + (*pos1)[2] * local_30;
      pos1 = pos1 + 1;
      q2 = (vec_t *)((int)q2 + 0x10);
      q1 = (vec_t *)((int)q1 + 0x10);
      pos2 = pos2 + 1;
    } while (iVar1 < this->m_pStudioHeader->numbones);
  }
  return;
}


// CStudioModelRenderer::StudioGetAnim  @ 0007c6b0  (line 363)

/* DWARF original prototype: mstudioanim_t * StudioGetAnim(CStudioModelRenderer * this, model_t *
   m_pSubModel, 16mstudioseqdesc_t * pseqdesc) */

mstudioanim_t * __thiscall
CStudioModelRenderer::StudioGetAnim
          (CStudioModelRenderer *this,model_t *m_pSubModel,_6mstudioseqdesc_t *pseqdesc)

{
  int iVar1;
  _1studiohdr_t *p1Var2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  char *pcVar6;
  dmodel_t *pdVar7;
  
                    /* Unresolved local var: mstudioseqgroup_t * pseqgroup@[???]
                       Unresolved local var: cache_user_t * paSequences@[???] */
  iVar1 = pseqdesc->seqgroup;
  p1Var2 = this->m_pStudioHeader;
  if (iVar1 == 0) {
    pcVar6 = p1Var2->name + pseqdesc->animindex + -8;
  }
  else {
    iVar3 = p1Var2->seqgroupindex;
    pdVar7 = m_pSubModel->submodels;
    iVar4 = iVar1;
    if (pdVar7 == (dmodel_t *)0x0) {
      pdVar7 = (*IEngineStudio.Mem_Calloc)(0x10,4);
      m_pSubModel->submodels = pdVar7;
      iVar4 = pseqdesc->seqgroup;
    }
    pvVar5 = (*IEngineStudio.Cache_Check)((cache_user_s *)(pdVar7->mins + iVar4));
    if (pvVar5 == (void *)0x0) {
      (*gEngfuncs.Con_DPrintf)("loading %s\n",p1Var2->name + iVar3 + iVar1 * 0x68 + 0x18);
      (*IEngineStudio.LoadCacheFile)
                (p1Var2->name + iVar3 + iVar1 * 0x68 + 0x18,
                 (cache_user_s *)(pdVar7->mins + pseqdesc->seqgroup));
    }
    pcVar6 = (char *)(pseqdesc->animindex + (int)pdVar7->mins[pseqdesc->seqgroup]);
  }
  return (mstudioanim_t *)pcVar6;
}


// CStudioModelRenderer::StudioPlayerBlend  @ 0007c7b0  (line 397)

/* DWARF original prototype: void StudioPlayerBlend(CStudioModelRenderer * this, 16mstudioseqdesc_t
   * pseqdesc, int * pBlend, float * pPitch) */

void __thiscall
CStudioModelRenderer::StudioPlayerBlend
          (CStudioModelRenderer *this,_6mstudioseqdesc_t *pseqdesc,int *pBlend,float *pPitch)

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


// CStudioModelRenderer::StudioSetUpTransform  @ 0007cf60  (line 427)

/* DWARF original prototype: void StudioSetUpTransform(CStudioModelRenderer * this, int
   trivial_accept) */

void __thiscall
CStudioModelRenderer::StudioSetUpTransform(CStudioModelRenderer *this,int trivial_accept)

{
  float fVar1;
  float fVar2;
  cl_entity_t_conflict *pcVar3;
  float fVar4;
  int iVar5;
  float local_34;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector modelpos@[???] */
  pcVar3 = this->m_pCurrentEntity;
  local_18 = (pcVar3->origin).x;
  iVar5 = (pcVar3->curstate).movetype;
  local_14 = (pcVar3->origin).y;
  local_10 = (pcVar3->origin).z;
  local_1c = (pcVar3->curstate).angles.z;
  local_24 = (pcVar3->curstate).angles.x;
  local_20 = (pcVar3->curstate).angles.y;
  if (iVar5 == 4) {
                    /* Unresolved local var: float f@[???]
                       Unresolved local var: float d@[???] */
    fVar1 = (pcVar3->curstate).animtime;
    if ((fVar1 + 1.0 <= (float)this->m_clTime) ||
       (fVar2 = (pcVar3->latched).prevanimtime, fVar1 == fVar2)) {
      fVar2 = 0.0;
      fVar1 = local_18;
      fVar4 = local_10;
      local_34 = local_14;
    }
    else {
      fVar2 = ((float)this->m_clTime - fVar1) / (fVar1 - fVar2);
      fVar1 = (pcVar3->origin).x;
      fVar4 = (pcVar3->origin).z;
      local_34 = (pcVar3->origin).y;
    }
    if (this->m_fDoInterp == 0) {
      fVar2 = 0.0;
    }
    else {
      fVar2 = fVar2 - 1.0;
    }
    local_18 = (fVar1 - (pcVar3->latched).prevorigin.x) * fVar2 + local_18;
    local_14 = (local_34 - (pcVar3->latched).prevorigin.y) * fVar2 + local_14;
    local_10 = (fVar4 - (pcVar3->latched).prevorigin.z) * fVar2 + local_10;
                    /* Unresolved local var: float ang1@[???]
                       Unresolved local var: float ang2@[???] */
    fVar1 = (pcVar3->angles).x - (pcVar3->latched).prevangles.x;
    if (180.0 < fVar1) {
      fVar1 = fVar1 - 360.0;
    }
    else if (fVar1 < -180.0) {
      fVar1 = fVar1 + 360.0;
    }
    local_24 = fVar1 * fVar2 + local_24;
    fVar1 = (pcVar3->angles).y - (pcVar3->latched).prevangles.y;
    if (180.0 < fVar1) {
      fVar1 = fVar1 - 360.0;
    }
    else if (fVar1 < -180.0) {
      fVar1 = fVar1 + 360.0;
    }
    local_20 = fVar1 * fVar2 + local_20;
    fVar1 = (pcVar3->angles).z - (pcVar3->latched).prevangles.z;
    if (fVar1 <= 180.0) {
      if (fVar1 < -180.0) {
        fVar1 = fVar1 + 360.0;
      }
    }
    else {
      fVar1 = fVar1 - 360.0;
    }
    local_1c = local_1c + fVar1 * fVar2;
  }
  else if (iVar5 != 0) {
    local_20 = (pcVar3->angles).y;
    local_1c = (pcVar3->angles).z;
    local_24 = (pcVar3->angles).x;
  }
  fVar4 = local_10;
  fVar2 = local_14;
  fVar1 = local_18;
  local_24 = -local_24;
  AngleMatrix(&local_24,*this->m_protationmatrix);
  iVar5 = (*IEngineStudio.IsHardware)();
  if (iVar5 == 0) {
    StudioSetUpTransform::lexical_block_1::viewmatrix[0][0] = this->m_vRight[0];
    StudioSetUpTransform::lexical_block_1::viewmatrix[0][1] = this->m_vRight[1];
    StudioSetUpTransform::lexical_block_1::viewmatrix[0][2] = this->m_vRight[2];
    StudioSetUpTransform::lexical_block_1::viewmatrix[1][0] = this->m_vUp[0];
    StudioSetUpTransform::lexical_block_1::viewmatrix[1][1] = this->m_vUp[1];
    StudioSetUpTransform::lexical_block_1::viewmatrix[1][2] = this->m_vUp[2];
    VectorInverse(StudioSetUpTransform::lexical_block_1::viewmatrix[1]);
    StudioSetUpTransform::lexical_block_1::viewmatrix[2][0] = this->m_vNormal[0];
    StudioSetUpTransform::lexical_block_1::viewmatrix[2][1] = this->m_vNormal[1];
    StudioSetUpTransform::lexical_block_1::viewmatrix[2][2] = this->m_vNormal[2];
    (*this->m_protationmatrix)[0][3] = fVar1 - this->m_vRenderOrigin[0];
    (*this->m_protationmatrix)[1][3] = fVar2 - this->m_vRenderOrigin[1];
    (*this->m_protationmatrix)[2][3] = fVar4 - this->m_vRenderOrigin[2];
    ConcatTransforms(StudioSetUpTransform::lexical_block_1::viewmatrix,*this->m_protationmatrix,
                     *this->m_paliastransform);
    if (trivial_accept != 0) {
      (*this->m_paliastransform)[0][0] =
           this->m_fSoftwareXScale * 4.656613e-10 * (*this->m_paliastransform)[0][0];
      (*this->m_paliastransform)[1][0] =
           this->m_fSoftwareYScale * 4.656613e-10 * (*this->m_paliastransform)[1][0];
      (*this->m_paliastransform)[2][0] = (*this->m_paliastransform)[2][0] * 4.656613e-10;
      (*this->m_paliastransform)[0][1] =
           this->m_fSoftwareXScale * 4.656613e-10 * (*this->m_paliastransform)[0][1];
      (*this->m_paliastransform)[1][1] =
           this->m_fSoftwareYScale * 4.656613e-10 * (*this->m_paliastransform)[1][1];
      (*this->m_paliastransform)[2][1] = (*this->m_paliastransform)[2][1] * 4.656613e-10;
      (*this->m_paliastransform)[0][2] =
           this->m_fSoftwareXScale * 4.656613e-10 * (*this->m_paliastransform)[0][2];
      (*this->m_paliastransform)[1][2] =
           this->m_fSoftwareYScale * 4.656613e-10 * (*this->m_paliastransform)[1][2];
      (*this->m_paliastransform)[2][2] = (*this->m_paliastransform)[2][2] * 4.656613e-10;
      (*this->m_paliastransform)[0][3] =
           this->m_fSoftwareXScale * 4.656613e-10 * (*this->m_paliastransform)[0][3];
      (*this->m_paliastransform)[1][3] =
           this->m_fSoftwareYScale * 4.656613e-10 * (*this->m_paliastransform)[1][3];
      (*this->m_paliastransform)[2][3] = (*this->m_paliastransform)[2][3] * 4.656613e-10;
    }
  }
  (*this->m_protationmatrix)[0][3] = fVar1;
  (*this->m_protationmatrix)[1][3] = fVar2;
  (*this->m_protationmatrix)[2][3] = fVar4;
  return;
}


// CStudioModelRenderer::StudioEstimateInterpolant  @ 0007d9e0  (line 563)

/* DWARF original prototype: float StudioEstimateInterpolant(CStudioModelRenderer * this) */

float __thiscall CStudioModelRenderer::StudioEstimateInterpolant(CStudioModelRenderer *this)

{
  float fVar1;
  
                    /* Unresolved local var: float dadt@[???] */
  fVar1 = 1.0;
  if (this->m_fDoInterp != 0) {
                    /* Unresolved local var: float dadt@[???] */
    fVar1 = (this->m_pCurrentEntity->curstate).animtime;
    if (fVar1 < (this->m_pCurrentEntity->latched).prevanimtime + 0.01) {
      fVar1 = 1.0;
    }
    else {
      fVar1 = ((float)this->m_clTime - fVar1) / 0.1;
      if (2.0 < fVar1) {
        fVar1 = 2.0;
      }
    }
  }
  return fVar1;
}


// CStudioModelRenderer::StudioCalcRotations  @ 0007da40  (line 584)

/* DWARF original prototype: void StudioCalcRotations(CStudioModelRenderer * this, float[3] * pos,
   vec4_t * q, 16mstudioseqdesc_t * pseqdesc, mstudioanim_t * panim, float f) */

void __thiscall
CStudioModelRenderer::StudioCalcRotations
          (CStudioModelRenderer *this,float (*pos) [3],vec4_t *q,_6mstudioseqdesc_t *pseqdesc,
          mstudioanim_t *panim,float f)

{
  float fVar1;
  _func_int_varargs *p_Var2;
  _1studiohdr_t *p1Var3;
  int iVar4;
  int iVar5;
  cl_entity_t_conflict *pcVar6;
  uint uVar7;
  vec_t *pvVar8;
  _func_int_varargs **pp_Var9;
  float (*pafVar10) [3];
  longdouble extraout_ST0;
  longdouble lVar11;
  int local_4c;
  undefined1 local_3c [44];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int frame@[???]
                       Unresolved local var: mstudiobone_t * pbone@[???]
                       Unresolved local var: float s@[???]
                       Unresolved local var: float[8] adj@[???]
                       Unresolved local var: float dadt@[???] */
  if ((float)(pseqdesc->numframes + -1) < f) {
    local_4c = 0;
    f = 0.0;
  }
  else {
    if (f < -0.01) {
      pp_Var9 = this->_vptr_CStudioModelRenderer;
      local_4c = 0;
      f = -0.01;
      p_Var2 = pp_Var9[0xb];
      goto joined_r0x0007dad6;
    }
    local_4c = (int)f;
  }
  pp_Var9 = this->_vptr_CStudioModelRenderer;
  p_Var2 = pp_Var9[0xb];
joined_r0x0007dad6:
  if (p_Var2 == StudioEstimateInterpolant) {
                    /* Unresolved local var: float dadt@[???] */
                    /* Unresolved local var: float dadt@[???] */
    pcVar6 = this->m_pCurrentEntity;
    if ((this->m_fDoInterp == 0) ||
       (fVar1 = (pcVar6->curstate).animtime, fVar1 < (pcVar6->latched).prevanimtime + 0.01)) {
      lVar11 = (longdouble)1;
    }
    else {
      lVar11 = (longdouble)(((float)this->m_clTime - fVar1) / 0.1);
      if ((longdouble)2.0 < lVar11) {
        lVar11 = (longdouble)2.0;
      }
    }
  }
  else {
    (*p_Var2)(this);
    pp_Var9 = this->_vptr_CStudioModelRenderer;
    pcVar6 = this->m_pCurrentEntity;
    lVar11 = extraout_ST0;
  }
  p1Var3 = this->m_pStudioHeader;
  iVar4 = p1Var3->boneindex;
  fVar1 = f - (float)local_4c;
  (*pp_Var9[0xf])(this,(float)lVar11,local_3c,(pcVar6->curstate).controller,
                  (pcVar6->latched).prevcontroller,(uint)(pcVar6->mouth).mouthopen);
  if (0 < this->m_pStudioHeader->numbones) {
    iVar5 = 0;
    pvVar8 = (vec_t *)(p1Var3->name + iVar4 + -8);
    pafVar10 = pos;
    do {
      (*this->_vptr_CStudioModelRenderer[0x10])(this,local_4c,fVar1,pvVar8,panim,local_3c,q);
      (*this->_vptr_CStudioModelRenderer[0x11])(this,local_4c,fVar1,pvVar8,panim,local_3c,pafVar10);
      iVar5 = iVar5 + 1;
      q = (vec4_t *)((int)q + 0x10);
      pvVar8 = pvVar8 + 0x1c;
      panim = panim + 1;
      pafVar10 = pafVar10 + 1;
    } while (iVar5 < this->m_pStudioHeader->numbones);
  }
  uVar7 = pseqdesc->motiontype;
  if ((uVar7 & 1) != 0) {
    pos[pseqdesc->motionbone][0] = 0.0;
    uVar7 = pseqdesc->motiontype;
  }
  if ((uVar7 & 2) != 0) {
    pos[pseqdesc->motionbone][1] = 0.0;
    uVar7 = pseqdesc->motiontype;
  }
  if ((uVar7 & 4) != 0) {
    pos[pseqdesc->motionbone][2] = 0.0;
    uVar7 = pseqdesc->motiontype;
  }
  fVar1 = ((1.0 - fVar1) / (float)pseqdesc->numframes) * 0.0 *
          (this->m_pCurrentEntity->curstate).framerate;
  if ((uVar7 & 0x40) != 0) {
    pos[pseqdesc->motionbone][0] =
         (pseqdesc->linearmovement).x * fVar1 + pos[pseqdesc->motionbone][0];
    uVar7 = pseqdesc->motiontype;
  }
  if ((uVar7 & 0x80) != 0) {
    pos[pseqdesc->motionbone][1] =
         (pseqdesc->linearmovement).y * fVar1 + pos[pseqdesc->motionbone][1];
    uVar7 = pseqdesc->motiontype;
  }
  if ((uVar7 & 0x100) != 0) {
    pos[pseqdesc->motionbone][2] =
         fVar1 * (pseqdesc->linearmovement).z + pos[pseqdesc->motionbone][2];
  }
  return;
}


// CStudioModelRenderer::StudioFxTransform  @ 0007d830  (line 666)

/* DWARF original prototype: void StudioFxTransform(CStudioModelRenderer * this,
   cl_entity_t.conflict * ent, float[4] * transform) */

void __thiscall
CStudioModelRenderer::StudioFxTransform
          (CStudioModelRenderer *this,cl_entity_t_conflict *ent,float (*transform) [4])

{
  int in_EAX;
  int32 iVar1;
  int iVar2;
  longdouble lVar3;
  
  iVar1 = (*gEngfuncs.pfnRandomLong)(0,0x31);
  if (iVar1 == 0) {
                    /* Unresolved local var: int axis@[???] */
    iVar1 = (*gEngfuncs.pfnRandomLong)(0,1);
    iVar2 = 0x20;
    if (iVar1 != 1) {
      iVar2 = iVar1 << 4;
    }
    lVar3 = (longdouble)(*gEngfuncs.pfnRandomFloat)(1.0,1.484);
    VectorScale((float *)(in_EAX + iVar2),(float)lVar3,(float *)(in_EAX + iVar2));
  }
  else {
    iVar1 = (*gEngfuncs.pfnRandomLong)(0,0x31);
    if (iVar1 == 0) {
                    /* Unresolved local var: float offset@[???]
                       Unresolved local var: int axis@[???] */
      (*gEngfuncs.pfnRandomLong)(0,1);
      lVar3 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-10.0,10.0);
      iVar1 = (*gEngfuncs.pfnRandomLong)(0,2);
      iVar2 = in_EAX + iVar1 * 0x10;
      *(float *)(iVar2 + 0xc) = (float)lVar3 + *(float *)(iVar2 + 0xc);
      return;
    }
  }
  return;
}


// CStudioModelRenderer::StudioFxTransform  @ 0007f0f0  (line 667)

/* DWARF original prototype: void StudioFxTransform(CStudioModelRenderer * this,
   cl_entity_t.conflict * ent, float[4] * transform) */

void __thiscall
CStudioModelRenderer::StudioFxTransform
          (CStudioModelRenderer *this,cl_entity_t_conflict *ent,float (*transform) [4])

{
  float fVar1;
  int32 iVar2;
  int iVar3;
  float *in;
  longdouble lVar4;
  
  iVar3 = (ent->curstate).renderfx;
  if (0xe < iVar3) {
    if (iVar3 < 0x11) {
      iVar2 = (*gEngfuncs.pfnRandomLong)(0,0x31);
      if (iVar2 == 0) {
                    /* Unresolved local var: int axis@[???] */
        iVar2 = (*gEngfuncs.pfnRandomLong)(0,1);
        iVar3 = 0x20;
        if (iVar2 != 1) {
          iVar3 = iVar2 << 4;
        }
        in = (float *)((int)*transform + iVar3);
        lVar4 = (longdouble)(*gEngfuncs.pfnRandomFloat)(1.0,1.484);
        VectorScale(in,(float)lVar4,in);
        return;
      }
      iVar2 = (*gEngfuncs.pfnRandomLong)(0,0x31);
      if (iVar2 == 0) {
                    /* Unresolved local var: float offset@[???]
                       Unresolved local var: int axis@[???] */
        (*gEngfuncs.pfnRandomLong)(0,1);
        lVar4 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-10.0,10.0);
        iVar2 = (*gEngfuncs.pfnRandomLong)(0,2);
        transform[iVar2][3] = (float)lVar4 + transform[iVar2][3];
      }
    }
    else if (iVar3 == 0x12) {
                    /* Unresolved local var: float scale@[???] */
      fVar1 = ((float)this->m_clTime - (ent->curstate).animtime) * 10.0 + 1.0;
      if (2.0 < fVar1) {
        fVar1 = 2.0;
      }
      (*transform)[1] = (*transform)[1] * fVar1;
      transform[1][1] = transform[1][1] * fVar1;
      transform[2][1] = fVar1 * transform[2][1];
    }
  }
  return;
}


// CStudioModelRenderer::StudioEstimateFrame  @ 0007c880  (line 712)

/* DWARF original prototype: float StudioEstimateFrame(CStudioModelRenderer * this,
   16mstudioseqdesc_t * pseqdesc) */

float __thiscall
CStudioModelRenderer::StudioEstimateFrame(CStudioModelRenderer *this,_6mstudioseqdesc_t *pseqdesc)

{
  int iVar1;
  float fVar2;
  int iVar3;
  
                    /* Unresolved local var: double dfdt@[???]
                       Unresolved local var: double f@[???] */
  if (this->m_fDoInterp == 0) {
LAB_0007c8ab:
    fVar2 = 0.0;
  }
  else {
    fVar2 = (this->m_pCurrentEntity->curstate).animtime;
    if ((float)this->m_clTime < fVar2) goto LAB_0007c8ab;
    fVar2 = ((float)this->m_clTime - fVar2) * (this->m_pCurrentEntity->curstate).framerate *
            pseqdesc->fps;
  }
  iVar3 = pseqdesc->numframes;
  if (iVar3 < 2) {
    fVar2 = fVar2 + 0.0;
    if ((pseqdesc->flags & 1) == 0) goto LAB_0007c914;
  }
  else {
    iVar1 = iVar3 + -1;
    fVar2 = (float)iVar1 * (this->m_pCurrentEntity->curstate).frame * 0.00390625 + fVar2;
    if ((pseqdesc->flags & 1) == 0) {
LAB_0007c914:
      if ((float)iVar3 - 1.001 <= fVar2) {
        fVar2 = (float)iVar3 - 1.001;
      }
      if (fVar2 < 0.0) {
        return 0.0;
      }
      return fVar2;
    }
    fVar2 = fVar2 - (float)((int)(fVar2 / (float)iVar1) * iVar1);
  }
  if (fVar2 < 0.0) {
    fVar2 = (float)(iVar3 + -1) + fVar2;
  }
  return fVar2;
}


// CStudioModelRenderer::StudioSetupBones  @ 0007dd90  (line 775)

/* DWARF original prototype: void StudioSetupBones(CStudioModelRenderer * this) */

void __thiscall CStudioModelRenderer::StudioSetupBones(CStudioModelRenderer *this)

{
  undefined8 uVar1;
  float fVar2;
  player_info_t *ppVar3;
  cl_entity_t_conflict *pcVar4;
  bool bVar5;
  int iVar6;
  cl_entity_t_conflict *pcVar7;
  _1studiohdr_t *p1Var8;
  int iVar9;
  vec_t *pvVar10;
  float (*paafVar11) [3] [4];
  int iVar12;
  _func_int_varargs **pp_Var13;
  vec_t *pvVar14;
  _6mstudioseqdesc_t *pseqdesc;
  float (*pafVar15) [3];
  vec_t *pvVar16;
  char *pcVar17;
  bool bVar18;
  byte bVar19;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  CStudioModelRenderer *this_00;
  float (*out) [3] [4];
  int *local_64;
  vec_t (*local_60) [4];
  float local_4c [3];
  float local_40;
  float local_30;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: double f@[???]
                       Unresolved local var: mstudiobone_t * pbones@[???]
                       Unresolved local var: 16mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: mstudioanim_t * panim@[???]
                       Unresolved local var: float[3][4] bonematrix@[???] */
  bVar19 = 0;
  p1Var8 = this->m_pStudioHeader;
  iVar6 = (this->m_pCurrentEntity->curstate).sequence;
  if (p1Var8->numseq <= iVar6) {
    (this->m_pCurrentEntity->curstate).sequence = 0;
    p1Var8 = this->m_pStudioHeader;
    iVar6 = (this->m_pCurrentEntity->curstate).sequence;
  }
  pp_Var13 = this->_vptr_CStudioModelRenderer;
  pseqdesc = (_6mstudioseqdesc_t *)(p1Var8->name + iVar6 * 0xb0 + p1Var8->seqindex + -8);
  if (pp_Var13[0xc] == StudioEstimateFrame) {
    local_64 = (int *)StudioEstimateFrame(this,pseqdesc);
  }
  else {
    (*pp_Var13[0xc])();
    pp_Var13 = this->_vptr_CStudioModelRenderer;
    local_64 = (int *)(float)extraout_ST0;
  }
  iVar6 = (*pp_Var13[5])(this,this->m_pRenderModel,pseqdesc);
  (*this->_vptr_CStudioModelRenderer[0x12])
            (this,StudioSetupBones::pos,StudioSetupBones::q,pseqdesc,iVar6,local_64);
  if (1 < pseqdesc->numblends) {
                    /* Unresolved local var: float s@[???]
                       Unresolved local var: float dadt@[???] */
    iVar6 = iVar6 + this->m_pStudioHeader->numbones * 0xc;
    (*this->_vptr_CStudioModelRenderer[0x12])
              (this,StudioSetupBones::pos2,StudioSetupBones::q2,pseqdesc,iVar6,local_64);
    pp_Var13 = this->_vptr_CStudioModelRenderer;
    if (pp_Var13[0xb] == StudioEstimateInterpolant) {
                    /* Unresolved local var: float dadt@[???] */
                    /* Unresolved local var: float dadt@[???] */
      pcVar7 = this->m_pCurrentEntity;
      if (this->m_fDoInterp == 0) {
        fVar2 = 0.0;
        local_60 = (vec_t (*) [4])0x3f800000;
      }
      else {
        fVar2 = (pcVar7->curstate).animtime;
        if (fVar2 < (pcVar7->latched).prevanimtime + 0.01) {
          fVar2 = 0.0;
          local_60 = (vec_t (*) [4])0x3f800000;
        }
        else {
          local_60 = (vec_t (*) [4])(((float)this->m_clTime - fVar2) / 0.1);
          if ((float)local_60 <= 2.0) {
            fVar2 = 1.0 - (float)local_60;
          }
          else {
            local_60 = (vec_t (*) [4])0x40000000;
            fVar2 = -1.0;
          }
        }
      }
    }
    else {
      (*pp_Var13[0xb])(this);
      pcVar7 = this->m_pCurrentEntity;
      pp_Var13 = this->_vptr_CStudioModelRenderer;
      local_60 = (vec_t (*) [4])(float)extraout_ST0_00;
      fVar2 = (float)((longdouble)1 - extraout_ST0_00);
    }
    (*pp_Var13[0xe])(this,StudioSetupBones::q,StudioSetupBones::pos,StudioSetupBones::q2,
                     StudioSetupBones::pos2,
                     ((float)(pcVar7->latched).prevblending[0] * fVar2 +
                     (float)local_60 * (float)(pcVar7->curstate).blending[0]) / 255.0);
    if (pseqdesc->numblends == 4) {
      iVar6 = iVar6 + this->m_pStudioHeader->numbones * 0xc;
      (*this->_vptr_CStudioModelRenderer[0x12])
                (this,StudioSetupBones::pos3,StudioSetupBones::q3,pseqdesc,iVar6,local_64);
      (*this->_vptr_CStudioModelRenderer[0x12])
                (this,StudioSetupBones::pos4,StudioSetupBones::q4,pseqdesc,
                 iVar6 + this->m_pStudioHeader->numbones * 0xc,local_64);
      (*this->_vptr_CStudioModelRenderer[0xe])
                (this,StudioSetupBones::q3,StudioSetupBones::pos3,StudioSetupBones::q4,
                 StudioSetupBones::pos4,
                 ((float)(this->m_pCurrentEntity->latched).prevblending[0] * fVar2 +
                 (float)(this->m_pCurrentEntity->curstate).blending[0] * (float)local_60) / 255.0);
      (*this->_vptr_CStudioModelRenderer[0xe])
                (this,StudioSetupBones::q,StudioSetupBones::pos,StudioSetupBones::q3,
                 StudioSetupBones::pos3,
                 ((float)(this->m_pCurrentEntity->latched).prevblending[1] * fVar2 +
                 (float)(this->m_pCurrentEntity->curstate).blending[1] * (float)local_60) / 255.0);
    }
  }
  pcVar7 = this->m_pCurrentEntity;
  if (((this->m_fDoInterp == 0) || (fVar2 = (pcVar7->latched).sequencetime, fVar2 == 0.0)) ||
     (fVar2 + 0.2 <= (float)this->m_clTime)) {
LAB_0007e0d6:
    (pcVar7->latched).prevframe = (float)local_64;
  }
  else {
    p1Var8 = this->m_pStudioHeader;
    iVar6 = (pcVar7->latched).prevsequence;
    if (p1Var8->numseq <= iVar6) goto LAB_0007e0d6;
                    /* Unresolved local var: float s@[???] */
    pcVar17 = p1Var8->name + iVar6 * 0xb0 + p1Var8->seqindex + -8;
    iVar6 = (*this->_vptr_CStudioModelRenderer[5])(this,this->m_pRenderModel,pcVar17);
    (*this->_vptr_CStudioModelRenderer[0x12])
              (this,StudioSetupBones::lexical_block_1::pos1b,StudioSetupBones::lexical_block_1::q1b,
               pcVar17,iVar6,(this->m_pCurrentEntity->latched).prevframe);
    if (1 < (int)*(vec_t *)(pcVar17 + 0x78)) {
      iVar6 = iVar6 + this->m_pStudioHeader->numbones * 0xc;
      (*this->_vptr_CStudioModelRenderer[0x12])
                (this,StudioSetupBones::pos2,StudioSetupBones::q2,pcVar17,iVar6,
                 (this->m_pCurrentEntity->latched).prevframe);
      (*this->_vptr_CStudioModelRenderer[0xe])
                (this,StudioSetupBones::lexical_block_1::q1b,
                 StudioSetupBones::lexical_block_1::pos1b,StudioSetupBones::q2,
                 StudioSetupBones::pos2,
                 (float)(this->m_pCurrentEntity->latched).prevseqblending[0] / 255.0);
      if (*(vec_t *)(pcVar17 + 0x78) == 5.60519e-45) {
        iVar6 = iVar6 + this->m_pStudioHeader->numbones * 0xc;
        (*this->_vptr_CStudioModelRenderer[0x12])
                  (this,StudioSetupBones::pos3,StudioSetupBones::q3,pcVar17,iVar6,
                   (this->m_pCurrentEntity->latched).prevframe);
        (*this->_vptr_CStudioModelRenderer[0x12])
                  (this,StudioSetupBones::pos4,StudioSetupBones::q4,pcVar17,
                   iVar6 + this->m_pStudioHeader->numbones * 0xc,
                   (this->m_pCurrentEntity->latched).prevframe);
        (*this->_vptr_CStudioModelRenderer[0xe])
                  (this,StudioSetupBones::q3,StudioSetupBones::pos3,StudioSetupBones::q4,
                   StudioSetupBones::pos4,
                   (float)(this->m_pCurrentEntity->latched).prevseqblending[0] / 255.0);
        (*this->_vptr_CStudioModelRenderer[0xe])
                  (this,StudioSetupBones::lexical_block_1::q1b,
                   StudioSetupBones::lexical_block_1::pos1b,StudioSetupBones::q3,
                   StudioSetupBones::pos3,
                   (float)(this->m_pCurrentEntity->latched).prevseqblending[1] / 255.0);
      }
    }
    (*this->_vptr_CStudioModelRenderer[0xe])
              (this,StudioSetupBones::q,StudioSetupBones::pos,StudioSetupBones::lexical_block_1::q1b
               ,StudioSetupBones::lexical_block_1::pos1b,
               1.0 - ((float)this->m_clTime - (this->m_pCurrentEntity->latched).sequencetime) / 0.2)
    ;
  }
  p1Var8 = this->m_pStudioHeader;
  ppVar3 = this->m_pPlayerInfo;
  pvVar14 = (vec_t *)(p1Var8->name + p1Var8->boneindex + -8);
  if (ppVar3 == (player_info_t *)0x0) {
LAB_0007e20f:
    local_64 = (int *)p1Var8->numbones;
  }
  else {
    iVar6 = ppVar3->gaitsequence;
    if (iVar6 < p1Var8->numseq) {
      if (iVar6 == 0) goto LAB_0007e20f;
    }
    else {
      ppVar3->gaitsequence = 0;
      ppVar3 = this->m_pPlayerInfo;
      if (ppVar3 == (player_info_t *)0x0) {
        local_64 = (int *)this->m_pStudioHeader->numbones;
        goto LAB_0007e219;
      }
      iVar6 = ppVar3->gaitsequence;
      p1Var8 = this->m_pStudioHeader;
      if (iVar6 == 0) goto LAB_0007e20f;
      if (p1Var8->numseq <= iVar6) {
        ppVar3->gaitsequence = 0;
        p1Var8 = this->m_pStudioHeader;
        iVar6 = this->m_pPlayerInfo->gaitsequence;
      }
    }
                    /* Unresolved local var: int copy@[???] */
    iVar12 = p1Var8->seqindex;
    iVar9 = (*this->_vptr_CStudioModelRenderer[5])
                      (this,this->m_pRenderModel,p1Var8->name + iVar6 * 0xb0 + iVar12 + -8);
    (*this->_vptr_CStudioModelRenderer[0x12])
              (this,StudioSetupBones::pos2,StudioSetupBones::q2,
               p1Var8->name + iVar6 * 0xb0 + iVar12 + -8,iVar9,this->m_pPlayerInfo->gaitframe);
    local_64 = (int *)this->m_pStudioHeader->numbones;
    if ((int)local_64 < 1) {
      return;
    }
    bVar18 = true;
    local_60 = (vec_t (*) [4])StudioSetupBones::pos;
    pafVar15 = StudioSetupBones::pos2;
    iVar6 = 0;
    bVar5 = true;
    pvVar10 = pvVar14;
    do {
      iVar12 = 0xc;
      pvVar16 = pvVar10;
      pcVar17 = "Bip01 Spine";
      do {
        if (iVar12 == 0) break;
        iVar12 = iVar12 + -1;
        bVar18 = *(char *)pvVar16 == *pcVar17;
        pvVar16 = (vec_t *)((int)pvVar16 + (uint)bVar19 * -2 + 1);
        pcVar17 = pcVar17 + (uint)bVar19 * -2 + 1;
      } while (bVar18);
      if (bVar18) {
        bVar5 = false;
      }
      else {
        bVar18 = pvVar14 + (int)pvVar10[8] * 0x1c == (vec_t *)0x0;
        iVar12 = 0xd;
        pvVar16 = pvVar14 + (int)pvVar10[8] * 0x1c;
        pcVar17 = "Bip01 Pelvis";
        do {
          if (iVar12 == 0) break;
          iVar12 = iVar12 + -1;
          bVar18 = *(char *)pvVar16 == *pcVar17;
          pvVar16 = (vec_t *)((int)pvVar16 + (uint)bVar19 * -2 + 1);
          pcVar17 = pcVar17 + (uint)bVar19 * -2 + 1;
        } while (bVar18);
        if ((bVar18) || (bVar5)) {
          (*local_60)[0] = (*pafVar15)[0];
          (*local_60)[1] = (*pafVar15)[1];
          (*local_60)[2] = (*pafVar15)[2];
          uVar1 = *(undefined8 *)(StudioSetupBones::q2[iVar6] + 2);
          *(undefined8 *)StudioSetupBones::q[iVar6] = *(undefined8 *)StudioSetupBones::q2[iVar6];
          *(undefined8 *)(StudioSetupBones::q[iVar6] + 2) = uVar1;
          bVar5 = true;
          local_64 = (int *)this->m_pStudioHeader->numbones;
        }
      }
      iVar6 = iVar6 + 1;
      pvVar10 = pvVar10 + 0x1c;
      local_60 = (vec_t (*) [4])((int)local_60 + 0xc);
      pafVar15 = pafVar15 + 1;
      bVar18 = (int *)iVar6 == local_64;
    } while (iVar6 < (int)local_64);
  }
LAB_0007e219:
  if (0 < (int)local_64) {
    pafVar15 = StudioSetupBones::pos;
    local_60 = StudioSetupBones::q;
    iVar6 = 0;
    local_64 = (int *)(pvVar14 + 8);
    do {
      QuaternionMatrix(*local_60,(float (*) [4])local_4c);
      local_40 = (*pafVar15)[0];
      local_30 = (*pafVar15)[1];
      local_20 = (*pafVar15)[2];
      if (*local_64 == -1) {
        iVar12 = (*IEngineStudio.IsHardware)();
        if (iVar12 == 0) {
          ConcatTransforms(*this->m_paliastransform,(float (*) [4])local_4c,
                           (*this->m_pbonetransform)[iVar6]);
          out = *this->m_plighttransform + iVar6;
          pcVar7 = (cl_entity_t_conflict *)local_4c;
          this_00 = (CStudioModelRenderer *)this->m_protationmatrix;
          ConcatTransforms((float (*) [4])this_00,(float (*) [4])pcVar7,*out);
        }
        else {
          out = *this->m_pbonetransform + iVar6;
          ConcatTransforms(*this->m_protationmatrix,(float (*) [4])local_4c,*out);
          pcVar7 = (cl_entity_t_conflict *)(*this->m_plighttransform + iVar6);
          this_00 = (CStudioModelRenderer *)(*this->m_pbonetransform + iVar6);
          MatrixCopy((float (*) [4])this_00,(float (*) [4])pcVar7);
        }
        pcVar4 = this->m_pCurrentEntity;
        paafVar11 = *this->m_pbonetransform + iVar6;
        if (this->_vptr_CStudioModelRenderer[0xd] == StudioFxTransform) {
          iVar12 = (pcVar4->curstate).renderfx;
          if (0xe < iVar12) {
            if (iVar12 < 0x11) {
              StudioFxTransform(this_00,pcVar7,*out);
            }
            else if (iVar12 == 0x12) {
                    /* Unresolved local var: float scale@[???] */
              fVar2 = ((float)this->m_clTime - (pcVar4->curstate).animtime) * 10.0 + 1.0;
              if (2.0 < fVar2) {
                fVar2 = 2.0;
              }
              (*paafVar11)[0][1] = (*paafVar11)[0][1] * fVar2;
              (*paafVar11)[1][1] = (*paafVar11)[1][1] * fVar2;
              (*paafVar11)[2][1] = fVar2 * (*paafVar11)[2][1];
            }
          }
        }
        else {
          (*this->_vptr_CStudioModelRenderer[0xd])(this,pcVar4,paafVar11);
        }
      }
      else {
        ConcatTransforms((*this->m_pbonetransform)[*local_64],(float (*) [4])local_4c,
                         (*this->m_pbonetransform)[iVar6]);
        ConcatTransforms((*this->m_plighttransform)[*local_64],(float (*) [4])local_4c,
                         (*this->m_plighttransform)[iVar6]);
      }
      iVar6 = iVar6 + 1;
      pafVar15 = pafVar15 + 1;
      local_60 = local_60 + 1;
      local_64 = local_64 + 0x1c;
    } while (iVar6 < this->m_pStudioHeader->numbones);
  }
  return;
}


// CStudioModelRenderer::StudioSaveBones  @ 0007d450  (line 997)

/* DWARF original prototype: void StudioSaveBones(CStudioModelRenderer * this) */

void __thiscall CStudioModelRenderer::StudioSaveBones(CStudioModelRenderer *this)

{
  float (*out) [3] [4];
  _1studiohdr_t *p1Var1;
  char (*__dest) [32];
  vec_t *__src;
  int iVar2;
  int iVar3;
  float (*out_00) [3] [4];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: mstudiobone_t * pbones@[???] */
  p1Var1 = this->m_pStudioHeader;
  iVar2 = p1Var1->boneindex;
  this->m_nCachedBones = p1Var1->numbones;
  if (0 < p1Var1->numbones) {
    __dest = this->m_nCachedBoneNames;
    __src = (vec_t *)(p1Var1->name + iVar2 + -8);
    out_00 = this->m_rgCachedBoneTransform;
    iVar2 = 0;
    do {
      iVar3 = iVar2 + 1;
      strcpy(*__dest,(char *)__src);
      MatrixCopy((*this->m_pbonetransform)[iVar2],*out_00);
      out = out_00 + 0x80;
      out_00 = out_00 + 1;
      MatrixCopy((*this->m_plighttransform)[iVar2],*out);
      __dest = __dest + 1;
      __src = __src + 0x1c;
      iVar2 = iVar3;
    } while (iVar3 < this->m_pStudioHeader->numbones);
  }
  return;
}


// CStudioModelRenderer::StudioMergeBones  @ 0007ec90  (line 1021)

/* DWARF original prototype: void StudioMergeBones(CStudioModelRenderer * this, model_t *
   m_pSubModel) */

void __thiscall
CStudioModelRenderer::StudioMergeBones(CStudioModelRenderer *this,model_t *m_pSubModel)

{
  cl_entity_t_conflict *pcVar1;
  int iVar2;
  int iVar3;
  float (*paafVar4) [3] [4];
  _1studiohdr_t *p1Var5;
  _6mstudioseqdesc_t *pseqdesc;
  vec_t *__s1;
  int iVar6;
  _func_int_varargs **pp_Var7;
  char (*__s2) [32];
  longdouble lVar8;
  longdouble extraout_ST0;
  float fVar9;
  CStudioModelRenderer *this_00;
  cl_entity_t_conflict *ent;
  float (*out) [3] [4];
  int local_64;
  float (*local_60) [3];
  vec_t (*local_54) [4];
  float local_4c [3];
  float local_40;
  float local_30;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: double f@[???]
                       Unresolved local var: int do_hunt@[???]
                       Unresolved local var: mstudiobone_t * pbones@[???]
                       Unresolved local var: 16mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: mstudioanim_t * panim@[???]
                       Unresolved local var: float[3][4] bonematrix@[???] */
  p1Var5 = this->m_pStudioHeader;
  iVar2 = (this->m_pCurrentEntity->curstate).sequence;
  if (p1Var5->numseq <= iVar2) {
    (this->m_pCurrentEntity->curstate).sequence = 0;
    p1Var5 = this->m_pStudioHeader;
    iVar2 = (this->m_pCurrentEntity->curstate).sequence;
  }
  pseqdesc = (_6mstudioseqdesc_t *)(p1Var5->name + iVar2 * 0xb0 + p1Var5->seqindex + -8);
  pp_Var7 = this->_vptr_CStudioModelRenderer;
  if (pp_Var7[0xc] == StudioEstimateFrame) {
    fVar9 = StudioEstimateFrame(this,pseqdesc);
    lVar8 = (longdouble)fVar9;
  }
  else {
    (*pp_Var7[0xc])(this);
    pp_Var7 = this->_vptr_CStudioModelRenderer;
    lVar8 = extraout_ST0;
  }
  iVar2 = (*pp_Var7[5])(this,m_pSubModel,pseqdesc);
  (*this->_vptr_CStudioModelRenderer[0x12])
            (this,StudioMergeBones::pos,StudioMergeBones::q,pseqdesc,iVar2,(float)lVar8);
  p1Var5 = this->m_pStudioHeader;
  __s1 = (vec_t *)(p1Var5->name + p1Var5->boneindex + -8);
  if (0 < p1Var5->numbones) {
    local_54 = StudioMergeBones::q;
    local_60 = StudioMergeBones::pos;
    local_64 = 0;
    do {
      iVar6 = 0;
      iVar2 = this->m_nCachedBones;
      __s2 = this->m_nCachedBoneNames;
      if (0 < iVar2) {
        do {
          iVar3 = strcasecmp((char *)__s1,*__s2);
          if (iVar3 == 0) {
            MatrixCopy(this->m_rgCachedBoneTransform[iVar6],(*this->m_pbonetransform)[local_64]);
            MatrixCopy(this->m_rgCachedLightTransform[iVar6],(*this->m_plighttransform)[local_64]);
            if (iVar6 < this->m_nCachedBones) goto LAB_0007ee47;
            break;
          }
          iVar6 = iVar6 + 1;
          __s2 = __s2 + 1;
        } while (iVar6 != iVar2);
      }
      QuaternionMatrix(*local_54,(float (*) [4])local_4c);
      local_40 = (*local_60)[0];
      local_30 = (*local_60)[1];
      local_20 = (*local_60)[2];
      if (__s1[8] == -NAN) {
        iVar2 = (*IEngineStudio.IsHardware)();
        if (iVar2 == 0) {
          ConcatTransforms(*this->m_paliastransform,(float (*) [4])local_4c,
                           (*this->m_pbonetransform)[local_64]);
          ent = (cl_entity_t_conflict *)local_4c;
          out = *this->m_plighttransform + local_64;
          this_00 = (CStudioModelRenderer *)this->m_protationmatrix;
          ConcatTransforms((float (*) [4])this_00,(float (*) [4])ent,*out);
        }
        else {
          out = *this->m_pbonetransform + local_64;
          ConcatTransforms(*this->m_protationmatrix,(float (*) [4])local_4c,*out);
          ent = (cl_entity_t_conflict *)(*this->m_plighttransform + local_64);
          this_00 = (CStudioModelRenderer *)(*this->m_pbonetransform + local_64);
          MatrixCopy((float (*) [4])this_00,(float (*) [4])ent);
        }
        pcVar1 = this->m_pCurrentEntity;
        paafVar4 = *this->m_pbonetransform + local_64;
        if (this->_vptr_CStudioModelRenderer[0xd] == StudioFxTransform) {
          iVar2 = (pcVar1->curstate).renderfx;
          if (0xe < iVar2) {
            if (iVar2 < 0x11) {
              StudioFxTransform(this_00,ent,*out);
            }
            else if (iVar2 == 0x12) {
                    /* Unresolved local var: float scale@[???] */
              fVar9 = ((float)this->m_clTime - (pcVar1->curstate).animtime) * 10.0 + 1.0;
              if (2.0 < fVar9) {
                fVar9 = 2.0;
              }
              (*paafVar4)[0][1] = (*paafVar4)[0][1] * fVar9;
              (*paafVar4)[1][1] = (*paafVar4)[1][1] * fVar9;
              (*paafVar4)[2][1] = fVar9 * (*paafVar4)[2][1];
            }
          }
        }
        else {
          (*this->_vptr_CStudioModelRenderer[0xd])(this,pcVar1,paafVar4);
        }
      }
      else {
        ConcatTransforms((*this->m_pbonetransform)[(int)__s1[8]],(float (*) [4])local_4c,
                         (*this->m_pbonetransform)[local_64]);
        ConcatTransforms((*this->m_plighttransform)[(int)__s1[8]],(float (*) [4])local_4c,
                         (*this->m_plighttransform)[local_64]);
      }
LAB_0007ee47:
      __s1 = __s1 + 0x1c;
      local_64 = local_64 + 1;
      local_54 = local_54 + 1;
      local_60 = local_60 + 1;
    } while (local_64 < this->m_pStudioHeader->numbones);
  }
  return;
}


// GetRemapColor  @ 00081a40  (line 1107)

int GetRemapColor(int iTeam,bool bTopColor)

{
                    /* Unresolved local var: int retVal@[???] */
  if (iTeam == 3) {
    return (-(uint)!bTopColor & 0xfffffff6) + 0x2d;
  }
  if (iTeam != 4) {
    if (iTeam != 2) {
      return (-(uint)!bTopColor & 0xfffffff6) + 0x96;
    }
    return (-(uint)!bTopColor & 0xfffffff6) + 0xfa;
  }
  return (-(uint)!bTopColor & 0xfffffff6) + 100;
}


// CStudioModelRenderer::StudioDrawModel  @ 0007f3c0  (line 1154)

/* DWARF original prototype: int StudioDrawModel(CStudioModelRenderer * this, int flags) */

int __thiscall CStudioModelRenderer::StudioDrawModel(CStudioModelRenderer *this,int flags)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined2 uVar9;
  undefined4 uVar12;
  undefined2 uVar10;
  undefined2 uVar11;
  float fVar13;
  code *pcVar14;
  undefined4 uVar15;
  cvar_t *pcVar16;
  cl_entity_s *pcVar17;
  _1studiohdr_t *p1Var18;
  int iVar19;
  entity_state_s *peVar20;
  uint uVar21;
  uint uVar22;
  cl_entity_s *pcVar23;
  model_s *pmVar24;
  player_info_s *ppVar25;
  char *pcVar26;
  uint uVar27;
  undefined2 *puVar28;
  int iVar29;
  char (*pacVar30) [32];
  Vector *pVVar31;
  undefined2 *puVar32;
  vec_t *pvVar33;
  synctype_t sVar34;
  float *pfVar35;
  cl_entity_t_conflict *pcVar36;
  Vector *pVVar37;
  Vector *pVVar38;
  float (*paafVar39) [3] [4];
  CStudioModelRenderer *unaff_ESI;
  int *piVar40;
  int unaff_EDI;
  position_history_t *ppVar41;
  cl_entity_t_conflict *pcVar42;
  uint uVar43;
  int in_GS_OFFSET;
  bool bVar44;
  byte bVar45;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  longdouble extraout_ST0_04;
  CStudioModelRenderer *pCVar46;
  int iStack_dc0;
  float afStack_dbc [3];
  alight_s aStack_db0;
  int iStack_d98;
  qboolean qStack_d94;
  int iStack_d90;
  int iStack_d8c;
  float fStack_d88;
  int iStack_d84;
  vec_t vStack_d80;
  vec_t vStack_d7c;
  vec_t vStack_d78;
  vec_t vStack_d74;
  vec_t vStack_d70;
  vec_t vStack_d6c;
  int iStack_d68;
  int iStack_d64;
  float fStack_d60;
  int iStack_d5c;
  undefined2 uStack_d58;
  short sStack_d56;
  int iStack_d54;
  float fStack_d50;
  byte bStack_d4c;
  int iStack_d48;
  int iStack_d44;
  undefined2 uStack_d40;
  byte bStack_d3e;
  int iStack_d3c;
  int iStack_d38;
  float fStack_d34;
  float fStack_d30;
  int iStack_d2c;
  undefined4 uStack_d28;
  undefined4 uStack_d24;
  vec_t vStack_d20;
  vec_t vStack_d1c;
  vec_t vStack_d18;
  vec_t vStack_d14;
  vec_t vStack_d10;
  vec_t vStack_d0c;
  vec_t vStack_d08;
  vec_t vStack_d04;
  vec_t vStack_d00;
  int iStack_cfc;
  int iStack_cf8;
  float fStack_cf4;
  float fStack_cf0;
  int iStack_cec;
  int iStack_ce8;
  int iStack_ce4;
  qboolean qStack_ce0;
  int iStack_cdc;
  int iStack_cd8;
  vec_t vStack_cd4;
  vec_t vStack_cd0;
  vec_t vStack_ccc;
  int iStack_cc8;
  int iStack_cc4;
  int iStack_cc0;
  int iStack_cbc;
  float fStack_cb8;
  float fStack_cb4;
  int iStack_cb0;
  vec_t vStack_cac;
  vec_t vStack_ca8;
  vec_t vStack_ca4;
  vec_t vStack_ca0;
  vec_t vStack_c9c;
  vec_t vStack_c98;
  float fStack_c94;
  float fStack_c90;
  int iStack_c8c;
  int iStack_c88;
  int iStack_c84;
  int iStack_c80;
  float fStack_c7c;
  float fStack_c78;
  float fStack_c74;
  float fStack_c70;
  vec_t vStack_c6c;
  vec_t vStack_c68;
  vec_t vStack_c64;
  vec_t vStack_c60;
  vec_t vStack_c5c;
  vec_t vStack_c58;
  vec_t vStack_c54;
  vec_t vStack_c50;
  vec_t vStack_c4c;
  vec_t vStack_c48;
  vec_t vStack_c44;
  vec_t vStack_c40;
  int iStack_c3c;
  int iStack_c38;
  float fStack_c34;
  int iStack_c30;
  vec_t vStack_c2c;
  vec_t vStack_c28;
  vec_t vStack_c24;
  vec_t vStack_c20;
  vec_t vStack_c1c;
  vec_t vStack_c18;
  int iStack_c14;
  int iStack_c10;
  float fStack_c0c;
  int iStack_c08;
  undefined2 uStack_c04;
  short sStack_c02;
  int iStack_c00;
  float fStack_bfc;
  byte bStack_bf8;
  int iStack_bf4;
  int iStack_bf0;
  undefined2 uStack_bec;
  byte bStack_bea;
  int iStack_be8;
  int iStack_be4;
  float fStack_be0;
  float fStack_bdc;
  int iStack_bd8;
  undefined4 uStack_bd4;
  undefined4 uStack_bd0;
  vec_t vStack_bcc;
  vec_t vStack_bc8;
  vec_t vStack_bc4;
  vec_t vStack_bc0;
  vec_t vStack_bbc;
  vec_t vStack_bb8;
  vec_t vStack_bb4;
  vec_t vStack_bb0;
  vec_t vStack_bac;
  int iStack_ba8;
  int iStack_ba4;
  float fStack_ba0;
  float fStack_b9c;
  int iStack_b98;
  int iStack_b94;
  int iStack_b90;
  qboolean qStack_b8c;
  int iStack_b88;
  int iStack_b84;
  vec_t vStack_b80;
  vec_t vStack_b7c;
  vec_t vStack_b78;
  int iStack_b74;
  int iStack_b70;
  int iStack_b6c;
  int iStack_b68;
  float fStack_b64;
  float fStack_b60;
  int iStack_b5c;
  vec_t vStack_b58;
  vec_t vStack_b54;
  vec_t vStack_b50;
  vec_t vStack_b4c;
  vec_t vStack_b48;
  vec_t vStack_b44;
  float fStack_b40;
  float fStack_b3c;
  int iStack_b38;
  int iStack_b34;
  int iStack_b30;
  int iStack_b2c;
  float fStack_b28;
  float fStack_b24;
  float fStack_b20;
  float fStack_b1c;
  vec_t vStack_b18;
  vec_t vStack_b14;
  vec_t vStack_b10;
  vec_t vStack_b0c;
  vec_t vStack_b08;
  vec_t vStack_b04;
  vec_t vStack_b00;
  vec_t vStack_afc;
  vec_t vStack_af8;
  vec_t vStack_af4;
  vec_t vStack_af0;
  vec_t vStack_aec;
  int iStack_ae8;
  int iStack_ae4;
  float fStack_ae0;
  int iStack_adc;
  vec_t vStack_ad8;
  vec_t vStack_ad4;
  vec_t vStack_ad0;
  vec_t vStack_acc;
  vec_t vStack_ac8;
  vec_t vStack_ac4;
  int iStack_ac0;
  int iStack_abc;
  float fStack_ab8;
  int iStack_ab4;
  undefined2 uStack_ab0;
  short sStack_aae;
  int iStack_aac;
  float fStack_aa8;
  byte bStack_aa4;
  int iStack_aa0;
  int iStack_a9c;
  undefined2 uStack_a98;
  byte bStack_a96;
  int iStack_a94;
  int iStack_a90;
  float fStack_a8c;
  float fStack_a88;
  int iStack_a84;
  undefined4 uStack_a80;
  undefined4 uStack_a7c;
  vec_t vStack_a78;
  vec_t vStack_a74;
  vec_t vStack_a70;
  vec_t vStack_a6c;
  vec_t vStack_a68;
  vec_t vStack_a64;
  vec_t vStack_a60;
  vec_t vStack_a5c;
  vec_t vStack_a58;
  int iStack_a54;
  int iStack_a50;
  float fStack_a4c;
  float fStack_a48;
  int iStack_a44;
  int iStack_a40;
  int iStack_a3c;
  qboolean qStack_a38;
  int iStack_a34;
  int iStack_a30;
  vec_t vStack_a2c;
  vec_t vStack_a28;
  vec_t vStack_a24;
  int iStack_a20;
  int iStack_a1c;
  int iStack_a18;
  int iStack_a14;
  float fStack_a10;
  float fStack_a0c;
  int iStack_a08;
  vec_t vStack_a04;
  vec_t vStack_a00;
  vec_t vStack_9fc;
  vec_t vStack_9f8;
  vec_t vStack_9f4;
  vec_t vStack_9f0;
  float fStack_9ec;
  float fStack_9e8;
  int iStack_9e4;
  int iStack_9e0;
  int iStack_9dc;
  int iStack_9d8;
  float fStack_9d4;
  float fStack_9d0;
  float fStack_9cc;
  float fStack_9c8;
  vec_t vStack_9c4;
  vec_t vStack_9c0;
  vec_t vStack_9bc;
  vec_t vStack_9b8;
  vec_t vStack_9b4;
  vec_t vStack_9b0;
  vec_t vStack_9ac;
  vec_t vStack_9a8;
  vec_t vStack_9a4;
  vec_t vStack_9a0;
  vec_t vStack_99c;
  vec_t vStack_998;
  int iStack_994;
  float afStack_990 [448];
  float fStack_290;
  int iStack_28c;
  float fStack_288;
  float fStack_284;
  undefined2 uStack_280;
  vec_t vStack_27c;
  vec_t vStack_278;
  vec_t vStack_274;
  vec_t vStack_270;
  vec_t vStack_26c;
  vec_t vStack_268;
  int iStack_264;
  float fStack_260;
  undefined4 uStack_25c;
  undefined2 uStack_258;
  float fStack_254;
  vec_t vStack_250;
  vec_t vStack_24c;
  vec_t vStack_248;
  vec_t vStack_244;
  vec_t vStack_240;
  vec_t vStack_23c;
  vec_t vStack_238;
  vec_t vStack_234;
  vec_t vStack_230;
  vec_t vStack_22c;
  vec_t vStack_228;
  vec_t vStack_224;
  vec_t vStack_220;
  vec_t vStack_21c;
  undefined8 uStack_218;
  undefined8 uStack_210;
  int iStack_208;
  model_s_conflict *pmStack_204;
  efrag_s *peStack_200;
  mnode_s *pmStack_1fc;
  float fStack_1f8;
  int iStack_1f4;
  uint uStack_1f0;
  uint uStack_1ec;
  uint uStack_1e8;
  uint uStack_1e4;
  int iStack_1dc;
  CStudioModelRenderer *pCStack_1cc;
  CStudioModelRenderer *pCStack_1c8;
  int iStack_1c4;
  float (*paafStack_1c0) [3] [4];
  CStudioModelRenderer *out;
  float *pfVar47;
  float local_198 [3];
  alight_s local_18c;
  int local_174 [4];
  vec_t local_164;
  vec_t local_160;
  vec_t local_15c;
  vec_t local_158;
  vec_t local_154;
  vec_t local_150;
  undefined4 local_11c;
  undefined4 local_c0;
  undefined4 local_bc;
  int local_20;
  
                    /* Unresolved local var: alight_t lighting@[???]
                       Unresolved local var: Vector dir@[???] */
  bVar45 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  paafStack_1c0 = (float (*) [3] [4])0x7f3e6;
  pcVar17 = (*IEngineStudio.GetCurrentEntity)();
  this->m_pCurrentEntity = (cl_entity_t_conflict *)pcVar17;
  paafStack_1c0 = (float (*) [3] [4])0x7f403;
  (*IEngineStudio.GetTimes)(&this->m_nFrameCount,&this->m_clTime,&this->m_clOldTime);
  pfVar35 = this->m_vNormal;
  pfVar47 = this->m_vRight;
  paafStack_1c0 = (float (*) [3] [4])0x7f430;
  (*IEngineStudio.GetViewInfo)(this->m_vRenderOrigin,this->m_vUp,pfVar47,pfVar35);
  paafStack_1c0 = (float (*) [3] [4])0x7f449;
  (*IEngineStudio.GetAliasScale)(&this->m_fSoftwareXScale,&this->m_fSoftwareYScale);
  pcVar36 = this->m_pCurrentEntity;
  if ((pcVar36->curstate).renderfx == 0x11) {
                    /* Unresolved local var: entity_state_t deadplayer@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: int save_interp@[???] */
    iVar29 = (pcVar36->curstate).renderamt;
    if (0 < iVar29) {
      paafStack_1c0 = (float (*) [3] [4])0x7f5bc;
      iVar19 = (*gEngfuncs.GetMaxClients)();
      if (iVar29 <= iVar19) {
        paafStack_1c0 = (float (*) [3] [4])0x7f5d7;
        peVar20 = (*IEngineStudio.GetPlayerState)((this->m_pCurrentEntity->curstate).renderamt + -1)
        ;
        uVar21 = 0;
        do {
          uVar43 = uVar21;
          uVar12 = *(undefined4 *)(peVar20->controller + (uVar43 - 100));
          *(undefined4 *)((int)local_174 + uVar43) =
               *(undefined4 *)(peVar20->controller + (uVar43 - 0x68));
          *(undefined4 *)((int)local_174 + uVar43 + 4) = uVar12;
          uVar21 = uVar43 + 8;
        } while (uVar43 + 8 < 0x150);
        local_11c = 0;
        iVar29 = this->m_fDoInterp;
        local_bc = 0;
        *(undefined4 *)((int)local_174 + uVar43 + 8) =
             *(undefined4 *)(peVar20->controller + (uVar43 - 0x60));
        pcVar36 = this->m_pCurrentEntity;
        local_174[1] = (pcVar36->curstate).renderamt;
        local_158 = (pcVar36->curstate).angles.x;
        local_154 = (pcVar36->curstate).angles.y;
        local_150 = (pcVar36->curstate).angles.z;
        local_164 = (pcVar36->curstate).origin.x;
        local_160 = (pcVar36->curstate).origin.y;
        local_15c = (pcVar36->curstate).origin.z;
        this->m_fDoInterp = 0;
        local_c0 = 0;
        paafStack_1c0 = (float (*) [3] [4])0x7f69b;
        iVar19 = (*this->_vptr_CStudioModelRenderer[4])();
        this->m_fDoInterp = iVar29;
        goto LAB_0007f584;
      }
    }
    iVar19 = 0;
    goto LAB_0007f584;
  }
  pmVar24 = (model_s *)pcVar36->model;
  paafVar39 = (float (*) [3] [4])0x0;
  this->m_pRenderModel = pmVar24;
  paafStack_1c0 = (float (*) [3] [4])0x7f46d;
  p1Var18 = (*IEngineStudio.Mod_Extradata)(pmVar24);
  this->m_pStudioHeader = p1Var18;
  paafStack_1c0 = (float (*) [3] [4])0x7f479;
  (*IEngineStudio.StudioSetHeader)(p1Var18);
  paafStack_1c0 = (float (*) [3] [4])0x7f485;
  (*IEngineStudio.SetRenderModel)(this->m_pRenderModel);
  out = (CStudioModelRenderer *)0x0;
  paafStack_1c0 = (float (*) [3] [4])0x7f491;
  (*this->_vptr_CStudioModelRenderer[6])();
  if ((flags & 1U) == 0) {
LAB_0007f4a5:
    pCVar46 = this;
    if ((this->m_pCurrentEntity->curstate).movetype == 0xc) {
      out = (CStudioModelRenderer *)this->m_pRenderModel;
      paafStack_1c0 = (float (*) [3] [4])0x7f887;
      (*this->_vptr_CStudioModelRenderer[10])();
    }
    else {
      paafStack_1c0 = (float (*) [3] [4])0x7f4bd;
      (*this->_vptr_CStudioModelRenderer[7])();
    }
    if (this->_vptr_CStudioModelRenderer[9] == StudioSaveBones) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: mstudiobone_t * pbones@[???] */
      p1Var18 = this->m_pStudioHeader;
      iVar29 = p1Var18->boneindex;
      this->m_nCachedBones = p1Var18->numbones;
      unaff_ESI = (CStudioModelRenderer *)p1Var18->numbones;
      if (0 < (int)unaff_ESI) {
        pacVar30 = this->m_nCachedBoneNames;
        pvVar33 = (vec_t *)(p1Var18->name + iVar29 + -8);
        paafVar39 = this->m_rgCachedBoneTransform;
        iVar29 = 0;
        do {
          unaff_EDI = iVar29 + 1;
          paafStack_1c0 = (float (*) [3] [4])0x7f51b;
          strcpy(*pacVar30,(char *)pvVar33);
          paafStack_1c0 = (float (*) [3] [4])0x7f52f;
          MatrixCopy((*this->m_pbonetransform)[iVar29],*paafVar39);
          out = (CStudioModelRenderer *)(paafVar39 + 0x80);
          paafVar39 = paafVar39 + 1;
          unaff_ESI = (CStudioModelRenderer *)(*this->m_plighttransform + iVar29);
          paafStack_1c0 = (float (*) [3] [4])0x7f54c;
          pCVar46 = unaff_ESI;
          MatrixCopy((float (*) [4])unaff_ESI,(float (*) [4])out);
          pacVar30 = pacVar30 + 1;
          pvVar33 = pvVar33 + 0x1c;
          iVar29 = unaff_EDI;
        } while (unaff_EDI < this->m_pStudioHeader->numbones);
      }
    }
    else {
      paafStack_1c0 = (float (*) [3] [4])0x7f895;
      pCVar46 = this;
      (*this->_vptr_CStudioModelRenderer[9])();
    }
    if ((flags & 2U) != 0) {
      if (this->_vptr_CStudioModelRenderer[8] == StudioCalcAttachments) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: 19mstudioattachment_t * pattachment@[???] */
        p1Var18 = this->m_pStudioHeader;
        if (4 < p1Var18->numattachments) {
          paafStack_1c0 = (float (*) [3] [4])0x7fa81;
          StudioCalcAttachments(pCVar46);
          pCStack_1cc = this;
          iStack_1dc = *(int *)(in_GS_OFFSET + 0x14);
          pCStack_1c8 = unaff_ESI;
          iStack_1c4 = unaff_EDI;
          paafStack_1c0 = paafVar39;
          pcVar17 = (*IEngineStudio.GetCurrentEntity)();
          out->m_pCurrentEntity = (cl_entity_t_conflict *)pcVar17;
          (*IEngineStudio.GetTimes)(&out->m_nFrameCount,&out->m_clTime,&out->m_clOldTime);
          (*IEngineStudio.GetViewInfo)(out->m_vRenderOrigin,out->m_vUp,out->m_vRight,out->m_vNormal)
          ;
          (*IEngineStudio.GetAliasScale)(&out->m_fSoftwareXScale,&out->m_fSoftwareYScale);
          iVar29 = (int)pfVar35[1] + -1;
          out->m_nPlayerIndex = iVar29;
          if ((-1 < iVar29) && (iVar19 = (*gEngfuncs.GetMaxClients)(), iVar29 < iVar19)) {
            iVar29 = (int)pfVar35[0x2a];
            if (iVar29 == 8) {
              pmVar24 = (*IEngineStudio.SetupPlayerModel)(out->m_nPlayerIndex);
              out->m_pRenderModel = pmVar24;
              if ((pmVar24 == (model_s *)0x0) ||
                 (iVar19 = strcmp(pmVar24->name,sNewClassModelFiles[1]), iVar19 == 0)) {
                iVar29 = 1;
              }
              else {
                iVar19 = strcmp(pmVar24->name,sNewClassModelFiles[2]);
                if (iVar19 == 0) {
                  iVar29 = 2;
                }
                else {
                  iVar19 = strcmp(pmVar24->name,sNewClassModelFiles[3]);
                  if (iVar19 == 0) {
                    iVar29 = 3;
                  }
                  else {
                    iVar19 = strcmp(pmVar24->name,sNewClassModelFiles[4]);
                    if (iVar19 == 0) {
                      iVar29 = 4;
                    }
                    else {
                      iVar19 = strcmp(pmVar24->name,sNewClassModelFiles[5]);
                      if (iVar19 == 0) {
                        iVar29 = 5;
                      }
                      else {
                        iVar19 = strcmp(pmVar24->name,sNewClassModelFiles[6]);
                        if (iVar19 == 0) {
                          iVar29 = 6;
                        }
                        else {
                          iVar19 = strcmp(pmVar24->name,sNewClassModelFiles[7]);
                          if (iVar19 == 0) {
                            iVar29 = 7;
                          }
                          else {
                            iVar19 = strcmp(pmVar24->name,sNewClassModelFiles[8]);
                            if (iVar19 != 0) {
                              iVar29 = strcmp(pmVar24->name,sNewClassModelFiles[9]);
                              if (iVar29 == 0) {
                                iVar29 = 9;
                              }
                              else {
                                iVar29 = strcmp(pmVar24->name,sNewClassModelFiles[10]);
                                if (iVar29 == 0) {
                                  iVar29 = 10;
                                }
                                else {
                                  iVar29 = strcmp(pmVar24->name,sNewClassModelFiles[0xb]);
                                  iVar29 = (-(uint)(iVar29 == 0) & 10) + 1;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            if (pfVar35[0x45] == 0.0) {
              if (tfc_newmodels->value == 0.0) {
                pcVar26 = sOldClassModelFiles[iVar29];
                if (sOldClassModelFiles[iVar29] == (char *)0x0) {
                  pcVar26 = sOldClassModelFiles[1];
                }
              }
              else {
                pcVar26 = sNewClassModelFiles[iVar29];
                if (pcVar26 == (char *)0x0) {
                  pcVar26 = sNewClassModelFiles[1];
                }
              }
              pmVar24 = (*gEngfuncs.CL_LoadModel)(pcVar26,&iStack_dc0);
              out->m_pRenderModel = pmVar24;
            }
            else {
              pmVar24 = (*IEngineStudio.SetupPlayerModel)(out->m_nPlayerIndex);
              out->m_pRenderModel = pmVar24;
            }
            if (pmVar24 != (model_s *)0x0) {
              p1Var18 = (*IEngineStudio.Mod_Extradata)(pmVar24);
              out->m_pStudioHeader = p1Var18;
              (*IEngineStudio.StudioSetHeader)(p1Var18);
              (*IEngineStudio.SetRenderModel)(out->m_pRenderModel);
              if (pfVar35[0x2e] == 0.0) {
                (out->m_pCurrentEntity->curstate).controller[0] = '\x7f';
                (out->m_pCurrentEntity->curstate).controller[1] = '\x7f';
                (out->m_pCurrentEntity->curstate).controller[2] = '\x7f';
                (out->m_pCurrentEntity->curstate).controller[3] = '\x7f';
                (out->m_pCurrentEntity->latched).prevcontroller[0] =
                     (out->m_pCurrentEntity->curstate).controller[0];
                (out->m_pCurrentEntity->latched).prevcontroller[1] =
                     (out->m_pCurrentEntity->curstate).controller[1];
                (out->m_pCurrentEntity->latched).prevcontroller[2] =
                     (out->m_pCurrentEntity->curstate).controller[2];
                (out->m_pCurrentEntity->latched).prevcontroller[3] =
                     (out->m_pCurrentEntity->curstate).controller[3];
                ppVar25 = (*IEngineStudio.PlayerInfo)(out->m_nPlayerIndex);
                out->m_pPlayerInfo = ppVar25;
                ppVar25->gaitsequence = 0;
                pmVar24 = (model_s *)0x0;
                (**(code **)((int)(*(float (*) [4])&out->_vptr_CStudioModelRenderer)[0] + 0x18))
                          (out);
              }
              else {
                ppVar25 = (*IEngineStudio.PlayerInfo)(out->m_nPlayerIndex);
                out->m_pPlayerInfo = ppVar25;
                pcVar36 = out->m_pCurrentEntity;
                vVar1 = (pcVar36->angles).x;
                vVar2 = (pcVar36->angles).y;
                vVar3 = (pcVar36->angles).z;
                (**(code **)((int)(*(float (*) [4])&out->_vptr_CStudioModelRenderer)[0] + 100))
                          (out,pfVar35);
                out->m_pPlayerInfo->gaitsequence = (int)pfVar35[0x2e];
                fVar13 = (*(float (*) [4])&out->_vptr_CStudioModelRenderer)[0];
                out->m_pPlayerInfo = (player_info_t *)0x0;
                pmVar24 = (model_s *)0x0;
                (**(code **)((int)fVar13 + 0x18))(out);
                (out->m_pCurrentEntity->angles).x = vVar1;
                (out->m_pCurrentEntity->angles).y = vVar2;
                (out->m_pCurrentEntity->angles).z = vVar3;
              }
              uVar21 = (uint)pfVar47 & 1;
              if (uVar21 == 0) {
LAB_0007fcbd:
                ppVar25 = (*IEngineStudio.PlayerInfo)(out->m_nPlayerIndex);
                out->m_pPlayerInfo = ppVar25;
                pCVar46 = out;
                (**(code **)((int)(*(float (*) [4])&out->_vptr_CStudioModelRenderer)[0] + 0x1c))();
                pcVar14 = *(code **)((int)(*(float (*) [4])&out->_vptr_CStudioModelRenderer)[0] +
                                    0x24);
                if (pcVar14 == StudioSaveBones) {
                  p1Var18 = out->m_pStudioHeader;
                  iVar29 = p1Var18->boneindex;
                  out->m_nCachedBones = p1Var18->numbones;
                  if (0 < p1Var18->numbones) {
                    pacVar30 = out->m_nCachedBoneNames;
                    pvVar33 = (vec_t *)(p1Var18->name + iVar29 + -8);
                    paafVar39 = out->m_rgCachedBoneTransform;
                    iVar29 = 0;
                    do {
                      iVar19 = iVar29 + 1;
                      strcpy(*pacVar30,(char *)pvVar33);
                      MatrixCopy((*out->m_pbonetransform)[iVar29],*paafVar39);
                      pmVar24 = (model_s *)(paafVar39 + 0x80);
                      paafVar39 = paafVar39 + 1;
                      pCVar46 = (CStudioModelRenderer *)(*out->m_plighttransform + iVar29);
                      MatrixCopy((float (*) [4])pCVar46,(float (*) [4])pmVar24);
                      pacVar30 = pacVar30 + 1;
                      pvVar33 = pvVar33 + 0x1c;
                      iVar29 = iVar19;
                    } while (iVar19 < out->m_pStudioHeader->numbones);
                  }
                }
                else {
                  pCVar46 = out;
                  (*pcVar14)();
                }
                out->m_pPlayerInfo->renderframe = out->m_nFrameCount;
                out->m_pPlayerInfo = (player_info_t *)0x0;
                if (((uint)pfVar47 & 2) != 0) {
                  pcVar14 = *(code **)((int)(*(float (*) [4])&out->_vptr_CStudioModelRenderer)[0] +
                                      0x20);
                  if (pcVar14 == StudioCalcAttachments) {
                    p1Var18 = out->m_pStudioHeader;
                    if (4 < p1Var18->numattachments) goto LAB_0008199c;
                    if (0 < p1Var18->numattachments) {
                      iVar29 = 0;
                      pvVar33 = (vec_t *)(p1Var18->name + p1Var18->attachmentindex + 0x20);
                      do {
                        iVar19 = iVar29 + 1;
                        VectorTransform(pvVar33,(*out->m_plighttransform)[(int)pvVar33[-1]],
                                        &out->m_pCurrentEntity->attachment[iVar29].x);
                        iVar29 = iVar19;
                        pvVar33 = pvVar33 + 0x16;
                      } while (iVar19 < out->m_pStudioHeader->numattachments);
                    }
                  }
                  else {
                    (*pcVar14)(out);
                  }
                  (*IEngineStudio.StudioClientEvents)();
                  iVar29 = out->m_pCurrentEntity->index;
                  if (0 < iVar29) {
                    uVar43 = 0x30;
                    pcVar17 = (*gEngfuncs.GetEntityByIndex)(iVar29);
                    pcVar36 = out->m_pCurrentEntity;
                    pVVar31 = pcVar36->attachment;
                    pVVar37 = pcVar17->attachment;
                    bVar44 = ((uint)pVVar37 & 1) != 0;
                    if (bVar44) {
                      pVVar31 = (Vector *)((int)&pcVar36->attachment[0].x + 1);
                      uVar43 = 0x2f;
                      *(undefined1 *)&pcVar17->attachment[0].x =
                           *(undefined1 *)&pcVar36->attachment[0].x;
                      pVVar37 = (Vector *)((int)&pcVar17->attachment[0].x + 1);
                    }
                    pVVar38 = pVVar37;
                    if (((uint)pVVar37 & 2) != 0) {
                      pvVar33 = &pVVar31->x;
                      pVVar38 = (Vector *)((int)&pVVar37->x + 2);
                      pVVar31 = (Vector *)((int)&pVVar31->x + 2);
                      uVar43 = uVar43 - 2;
                      *(undefined2 *)&pVVar37->x = *(undefined2 *)pvVar33;
                    }
                    uVar22 = 0;
                    do {
                      uVar27 = uVar22;
                      *(undefined4 *)((int)&pVVar38->x + uVar27) =
                           *(undefined4 *)((int)&pVVar31->x + uVar27);
                      uVar22 = uVar27 + 4;
                    } while (uVar27 + 4 < (uVar43 & 0xfffffffc));
                    puVar32 = (undefined2 *)((int)&pVVar38->y + uVar27);
                    puVar28 = (undefined2 *)((int)&pVVar31->y + uVar27);
                    iVar29 = 0;
                    if ((uVar43 & 2) != 0) {
                      *puVar32 = *puVar28;
                      iVar29 = 2;
                    }
                    if (bVar44) {
                      *(undefined1 *)((int)puVar32 + iVar29) =
                           *(undefined1 *)((int)puVar28 + iVar29);
                    }
                  }
                }
                if (uVar21 != 0) {
                  if (*(float *)((int)(*(float (*) [4])&out->m_pCvarHiModels)[0] + 0xc) == 0.0) {
LAB_0007fdd1:
                    if (out->m_pCvarDeveloper->value == 0.0) {
LAB_00081650:
                      iVar29 = (*gEngfuncs.GetMaxClients)();
                      if (iVar29 != 1) goto LAB_0007fde7;
                      pcVar17 = (cl_entity_s *)out->m_pCurrentEntity;
                    }
                    else {
LAB_0007fde7:
                      pcVar17 = (cl_entity_s *)out->m_pCurrentEntity;
                      if (out->m_pRenderModel == pcVar17->model) goto LAB_000813c8;
                    }
                  }
                  else {
                    pcVar17 = (cl_entity_s *)out->m_pCurrentEntity;
                    if (out->m_pRenderModel != pcVar17->model) {
                      (pcVar17->curstate).body = 0xff;
                      goto LAB_0007fdd1;
                    }
                    if (out->m_pCvarDeveloper->value == 0.0) goto LAB_00081650;
LAB_000813c8:
                    (pcVar17->curstate).body = 1;
                    pcVar17 = (cl_entity_s *)out->m_pCurrentEntity;
                  }
                  aStack_db0.plightvec = afStack_dbc;
                  (*IEngineStudio.StudioDynamicLight)(pcVar17,&aStack_db0);
                  (*IEngineStudio.StudioEntityLight)(&aStack_db0);
                  (*IEngineStudio.StudioSetupLighting)(&aStack_db0);
                  ppVar25 = (*IEngineStudio.PlayerInfo)(out->m_nPlayerIndex);
                  pcVar16 = tfc_newmodels;
                  out->m_pPlayerInfo = ppVar25;
                  sVar34 = ppVar25->topcolor;
                  out->m_nTopColor = sVar34;
                  iVar29 = ppVar25->bottomcolor;
                  out->m_nBottomColor = iVar29;
                  if (pcVar16->value == 0.0) {
                    if (sVar34 - 0x88 < 0x13) {
                      out->m_nTopColor = 0x96;
                      sVar34 = 0x96;
                      out->m_nBottomColor = 0x8c;
                    }
                    else if (((int)sVar34 < 0x104) && ((0xf0 < (int)sVar34 || (sVar34 == 5)))) {
                      out->m_nTopColor = 0xfa;
                      sVar34 = 0xfa;
                      out->m_nBottomColor = 0xf0;
                    }
                    else if (sVar34 - 0x29 < 9) {
                      out->m_nTopColor = 0x2d;
                      sVar34 = 0x2d;
                      out->m_nBottomColor = 0x23;
                    }
                    else {
                      if (0x21 < sVar34 - 0x4c) goto LAB_000813a0;
                      out->m_nTopColor = 100;
                      sVar34 = 100;
                      out->m_nBottomColor = 0x5a;
                    }
LAB_0007fe84:
                    iVar29 = out->m_nBottomColor;
                  }
                  else {
LAB_000813a0:
                    if ((int)sVar34 < 0) {
                      out->m_nTopColor = ST_SYNC;
                      sVar34 = ST_SYNC;
                    }
                    else {
                      if ((int)sVar34 < 0x169) goto LAB_0007fe84;
                      out->m_nTopColor = 0x168;
                      iVar29 = out->m_nBottomColor;
                      sVar34 = 0x168;
                    }
                  }
                  if (iVar29 < 0) {
                    out->m_nBottomColor = 0;
                    iVar29 = 0;
                  }
                  else if (0x168 < iVar29) {
                    out->m_nBottomColor = 0x168;
                    iVar29 = 0x168;
                  }
                  (*IEngineStudio.StudioSetRemapColors)(sVar34,iVar29);
                  (**(code **)((int)(*(float (*) [4])&out->_vptr_CStudioModelRenderer)[0] + 0x4c))
                            (out);
                  out->m_pPlayerInfo = (player_info_t *)0x0;
                  iVar29 = (int)pfVar35[0x2d];
                  if (iVar29 != 0) {
                    pcVar36 = out->m_pCurrentEntity;
                    iStack_d84 = (pcVar36->baseline).messagenum;
                    iStack_d98 = pcVar36->index;
                    qStack_d94 = pcVar36->player;
                    iStack_d90 = (pcVar36->baseline).entityType;
                    iStack_d8c = (pcVar36->baseline).number;
                    fStack_d88 = (pcVar36->baseline).msg_time;
                    vStack_d74 = (pcVar36->baseline).angles.x;
                    vStack_d70 = (pcVar36->baseline).angles.y;
                    iStack_d68 = (pcVar36->baseline).modelindex;
                    vStack_d80 = (pcVar36->baseline).origin.x;
                    vStack_d6c = (pcVar36->baseline).angles.z;
                    iStack_d64 = (pcVar36->baseline).sequence;
                    vStack_d7c = (pcVar36->baseline).origin.y;
                    fStack_d60 = (pcVar36->baseline).frame;
                    iStack_d5c = (pcVar36->baseline).colormap;
                    vStack_d78 = (pcVar36->baseline).origin.z;
                    uVar9 = (pcVar36->baseline).skin;
                    sStack_d56 = (pcVar36->baseline).solid;
                    iStack_d54 = (pcVar36->baseline).effects;
                    bStack_d4c = (pcVar36->baseline).eflags;
                    fStack_d34 = (pcVar36->baseline).animtime;
                    fStack_d30 = (pcVar36->baseline).framerate;
                    vStack_d20 = (pcVar36->baseline).velocity.x;
                    iStack_d48 = (pcVar36->baseline).rendermode;
                    vStack_d1c = (pcVar36->baseline).velocity.y;
                    vStack_d18 = (pcVar36->baseline).velocity.z;
                    fStack_d50 = (pcVar36->baseline).scale;
                    iStack_d44 = (pcVar36->baseline).renderamt;
                    uStack_d40 = (undefined2)*(undefined4 *)&(pcVar36->baseline).rendercolor;
                    bStack_d3e = (pcVar36->baseline).rendercolor.b;
                    iStack_d3c = (pcVar36->baseline).renderfx;
                    iStack_d38 = (pcVar36->baseline).movetype;
                    iStack_d2c = (pcVar36->baseline).body;
                    uStack_d28 = *(undefined4 *)(pcVar36->baseline).controller;
                    uStack_d24 = *(undefined4 *)(pcVar36->baseline).blending;
                    vStack_d14 = (pcVar36->baseline).mins.x;
                    iStack_cfc = (pcVar36->baseline).aiment;
                    vStack_d10 = (pcVar36->baseline).mins.y;
                    vStack_d08 = (pcVar36->baseline).maxs.x;
                    vStack_d04 = (pcVar36->baseline).maxs.y;
                    iStack_cf8 = (pcVar36->baseline).owner;
                    vStack_d00 = (pcVar36->baseline).maxs.z;
                    iStack_cec = (pcVar36->baseline).team;
                    fStack_cf4 = (pcVar36->baseline).friction;
                    fStack_cf0 = (pcVar36->baseline).gravity;
                    vStack_d0c = (pcVar36->baseline).mins.z;
                    iStack_ce8 = (pcVar36->baseline).playerclass;
                    iStack_ce4 = (pcVar36->baseline).health;
                    qStack_ce0 = (pcVar36->baseline).spectator;
                    iStack_cdc = (pcVar36->baseline).weaponmodel;
                    iStack_cd8 = (pcVar36->baseline).gaitsequence;
                    vStack_cd4 = (pcVar36->baseline).basevelocity.x;
                    iStack_cc8 = (pcVar36->baseline).usehull;
                    vStack_cd0 = (pcVar36->baseline).basevelocity.y;
                    vStack_ccc = (pcVar36->baseline).basevelocity.z;
                    fStack_cb8 = (pcVar36->baseline).flFallVelocity;
                    iStack_cc4 = (pcVar36->baseline).oldbuttons;
                    fStack_cb4 = (pcVar36->baseline).fov;
                    iStack_cc0 = (pcVar36->baseline).onground;
                    vStack_ca8 = (pcVar36->baseline).startpos.y;
                    vStack_ca4 = (pcVar36->baseline).startpos.z;
                    iStack_cbc = (pcVar36->baseline).iStepLeft;
                    vStack_ca0 = (pcVar36->baseline).endpos.x;
                    iStack_cb0 = (pcVar36->baseline).weaponanim;
                    vStack_c9c = (pcVar36->baseline).endpos.y;
                    vStack_c98 = (pcVar36->baseline).endpos.z;
                    vStack_cac = (pcVar36->baseline).startpos.x;
                    fStack_c94 = (pcVar36->baseline).impacttime;
                    iStack_c8c = (pcVar36->baseline).iuser1;
                    fStack_c90 = (pcVar36->baseline).starttime;
                    fStack_c7c = (pcVar36->baseline).fuser1;
                    fStack_c78 = (pcVar36->baseline).fuser2;
                    iStack_c88 = (pcVar36->baseline).iuser2;
                    fStack_c74 = (pcVar36->baseline).fuser3;
                    fStack_c70 = (pcVar36->baseline).fuser4;
                    iStack_c84 = (pcVar36->baseline).iuser3;
                    vStack_c68 = (pcVar36->baseline).vuser1.y;
                    iStack_c80 = (pcVar36->baseline).iuser4;
                    vStack_c64 = (pcVar36->baseline).vuser1.z;
                    vStack_c60 = (pcVar36->baseline).vuser2.x;
                    vStack_c5c = (pcVar36->baseline).vuser2.y;
                    vStack_c6c = (pcVar36->baseline).vuser1.x;
                    vStack_c58 = (pcVar36->baseline).vuser2.z;
                    vStack_c54 = (pcVar36->baseline).vuser3.x;
                    iStack_c3c = (pcVar36->prevstate).entityType;
                    vStack_c50 = (pcVar36->baseline).vuser3.y;
                    vStack_c4c = (pcVar36->baseline).vuser3.z;
                    vStack_c48 = (pcVar36->baseline).vuser4.x;
                    iStack_c38 = (pcVar36->prevstate).number;
                    vStack_c44 = (pcVar36->baseline).vuser4.y;
                    vStack_c40 = (pcVar36->baseline).vuser4.z;
                    fStack_c34 = (pcVar36->prevstate).msg_time;
                    iStack_c30 = (pcVar36->prevstate).messagenum;
                    vStack_c2c = (pcVar36->prevstate).origin.x;
                    vStack_c28 = (pcVar36->prevstate).origin.y;
                    vStack_c24 = (pcVar36->prevstate).origin.z;
                    vStack_c20 = (pcVar36->prevstate).angles.x;
                    vStack_c1c = (pcVar36->prevstate).angles.y;
                    vStack_c18 = (pcVar36->prevstate).angles.z;
                    iStack_c14 = (pcVar36->prevstate).modelindex;
                    fStack_c0c = (pcVar36->prevstate).frame;
                    fStack_bfc = (pcVar36->prevstate).scale;
                    fStack_be0 = (pcVar36->prevstate).animtime;
                    iStack_c10 = (pcVar36->prevstate).sequence;
                    iStack_c08 = (pcVar36->prevstate).colormap;
                    uVar10 = (pcVar36->prevstate).skin;
                    sStack_c02 = (pcVar36->prevstate).solid;
                    iStack_c00 = (pcVar36->prevstate).effects;
                    bStack_bf8 = (pcVar36->prevstate).eflags;
                    iStack_bf4 = (pcVar36->prevstate).rendermode;
                    iStack_bf0 = (pcVar36->prevstate).renderamt;
                    uStack_bec = (undefined2)*(undefined4 *)&(pcVar36->prevstate).rendercolor;
                    bStack_bea = (pcVar36->prevstate).rendercolor.b;
                    iStack_be8 = (pcVar36->prevstate).renderfx;
                    iStack_be4 = (pcVar36->prevstate).movetype;
                    fStack_bdc = (pcVar36->prevstate).framerate;
                    iStack_bd8 = (pcVar36->prevstate).body;
                    vStack_bcc = (pcVar36->prevstate).velocity.x;
                    vStack_bc8 = (pcVar36->prevstate).velocity.y;
                    vStack_bc0 = (pcVar36->prevstate).mins.x;
                    uStack_bd4 = *(undefined4 *)(pcVar36->prevstate).controller;
                    vStack_bbc = (pcVar36->prevstate).mins.y;
                    vStack_bb8 = (pcVar36->prevstate).mins.z;
                    vStack_bb4 = (pcVar36->prevstate).maxs.x;
                    uStack_bd0 = *(undefined4 *)(pcVar36->prevstate).blending;
                    vStack_bb0 = (pcVar36->prevstate).maxs.y;
                    iStack_ba8 = (pcVar36->prevstate).aiment;
                    vStack_bac = (pcVar36->prevstate).maxs.z;
                    vStack_bc4 = (pcVar36->prevstate).velocity.z;
                    iStack_ba4 = (pcVar36->prevstate).owner;
                    fStack_ba0 = (pcVar36->prevstate).friction;
                    fStack_b9c = (pcVar36->prevstate).gravity;
                    iStack_b98 = (pcVar36->prevstate).team;
                    vStack_b80 = (pcVar36->prevstate).basevelocity.x;
                    vStack_b7c = (pcVar36->prevstate).basevelocity.y;
                    vStack_b78 = (pcVar36->prevstate).basevelocity.z;
                    iStack_b94 = (pcVar36->prevstate).playerclass;
                    fStack_b64 = (pcVar36->prevstate).flFallVelocity;
                    fStack_b60 = (pcVar36->prevstate).fov;
                    iStack_b90 = (pcVar36->prevstate).health;
                    qStack_b8c = (pcVar36->prevstate).spectator;
                    iStack_b88 = (pcVar36->prevstate).weaponmodel;
                    iStack_b84 = (pcVar36->prevstate).gaitsequence;
                    iStack_b74 = (pcVar36->prevstate).usehull;
                    iStack_b70 = (pcVar36->prevstate).oldbuttons;
                    iStack_b6c = (pcVar36->prevstate).onground;
                    iStack_b68 = (pcVar36->prevstate).iStepLeft;
                    iStack_b5c = (pcVar36->prevstate).weaponanim;
                    vStack_b58 = (pcVar36->prevstate).startpos.x;
                    vStack_b54 = (pcVar36->prevstate).startpos.y;
                    vStack_b50 = (pcVar36->prevstate).startpos.z;
                    iStack_b38 = (pcVar36->prevstate).iuser1;
                    vStack_b48 = (pcVar36->prevstate).endpos.y;
                    vStack_b44 = (pcVar36->prevstate).endpos.z;
                    fStack_b40 = (pcVar36->prevstate).impacttime;
                    iStack_b34 = (pcVar36->prevstate).iuser2;
                    fStack_b3c = (pcVar36->prevstate).starttime;
                    iStack_b30 = (pcVar36->prevstate).iuser3;
                    fStack_b28 = (pcVar36->prevstate).fuser1;
                    fStack_b24 = (pcVar36->prevstate).fuser2;
                    iStack_b2c = (pcVar36->prevstate).iuser4;
                    fStack_b20 = (pcVar36->prevstate).fuser3;
                    vStack_b4c = (pcVar36->prevstate).endpos.x;
                    fStack_b1c = (pcVar36->prevstate).fuser4;
                    iStack_ae8 = (pcVar36->curstate).entityType;
                    vStack_b18 = (pcVar36->prevstate).vuser1.x;
                    vStack_b14 = (pcVar36->prevstate).vuser1.y;
                    vStack_b10 = (pcVar36->prevstate).vuser1.z;
                    vStack_b0c = (pcVar36->prevstate).vuser2.x;
                    vStack_b08 = (pcVar36->prevstate).vuser2.y;
                    iStack_ae4 = (pcVar36->curstate).number;
                    vStack_b04 = (pcVar36->prevstate).vuser2.z;
                    vStack_b00 = (pcVar36->prevstate).vuser3.x;
                    vStack_afc = (pcVar36->prevstate).vuser3.y;
                    vStack_af8 = (pcVar36->prevstate).vuser3.z;
                    vStack_af4 = (pcVar36->prevstate).vuser4.x;
                    vStack_af0 = (pcVar36->prevstate).vuser4.y;
                    vStack_aec = (pcVar36->prevstate).vuser4.z;
                    fStack_ae0 = (pcVar36->curstate).msg_time;
                    iStack_adc = (pcVar36->curstate).messagenum;
                    vStack_ad8 = (pcVar36->curstate).origin.x;
                    vStack_ad4 = (pcVar36->curstate).origin.y;
                    vStack_ad0 = (pcVar36->curstate).origin.z;
                    iStack_ac0 = (pcVar36->curstate).modelindex;
                    vStack_acc = (pcVar36->curstate).angles.x;
                    vStack_ac8 = (pcVar36->curstate).angles.y;
                    vStack_ac4 = (pcVar36->curstate).angles.z;
                    iStack_abc = (pcVar36->curstate).sequence;
                    fStack_ab8 = (pcVar36->curstate).frame;
                    fStack_aa8 = (pcVar36->curstate).scale;
                    iStack_ab4 = (pcVar36->curstate).colormap;
                    uVar11 = (pcVar36->curstate).skin;
                    sStack_aae = (pcVar36->curstate).solid;
                    iStack_aac = (pcVar36->curstate).effects;
                    bStack_aa4 = (pcVar36->curstate).eflags;
                    iStack_aa0 = (pcVar36->curstate).rendermode;
                    fStack_a8c = (pcVar36->curstate).animtime;
                    fStack_a88 = (pcVar36->curstate).framerate;
                    vStack_a78 = (pcVar36->curstate).velocity.x;
                    iStack_a9c = (pcVar36->curstate).renderamt;
                    vStack_a74 = (pcVar36->curstate).velocity.y;
                    vStack_a70 = (pcVar36->curstate).velocity.z;
                    vStack_a6c = (pcVar36->curstate).mins.x;
                    vStack_a68 = (pcVar36->curstate).mins.y;
                    uStack_a98 = (undefined2)*(undefined4 *)&(pcVar36->curstate).rendercolor;
                    bStack_a96 = (pcVar36->curstate).rendercolor.b;
                    iStack_a94 = (pcVar36->curstate).renderfx;
                    iStack_a90 = (pcVar36->curstate).movetype;
                    iStack_a84 = (pcVar36->curstate).body;
                    uStack_a80 = *(undefined4 *)(pcVar36->curstate).controller;
                    uStack_a7c = *(undefined4 *)(pcVar36->curstate).blending;
                    vStack_a64 = (pcVar36->curstate).mins.z;
                    iStack_a54 = (pcVar36->curstate).aiment;
                    vStack_a60 = (pcVar36->curstate).maxs.x;
                    vStack_a5c = (pcVar36->curstate).maxs.y;
                    vStack_a58 = (pcVar36->curstate).maxs.z;
                    iStack_a50 = (pcVar36->curstate).owner;
                    fStack_a4c = (pcVar36->curstate).friction;
                    fStack_a48 = (pcVar36->curstate).gravity;
                    vStack_a2c = (pcVar36->curstate).basevelocity.x;
                    iStack_a44 = (pcVar36->curstate).team;
                    vStack_a28 = (pcVar36->curstate).basevelocity.y;
                    iStack_a40 = (pcVar36->curstate).playerclass;
                    iStack_a3c = (pcVar36->curstate).health;
                    qStack_a38 = (pcVar36->curstate).spectator;
                    iStack_a34 = (pcVar36->curstate).weaponmodel;
                    iStack_a30 = (pcVar36->curstate).gaitsequence;
                    vStack_a24 = (pcVar36->curstate).basevelocity.z;
                    iStack_a20 = (pcVar36->curstate).usehull;
                    fStack_a10 = (pcVar36->curstate).flFallVelocity;
                    fStack_a0c = (pcVar36->curstate).fov;
                    vStack_a04 = (pcVar36->curstate).startpos.x;
                    iStack_a1c = (pcVar36->curstate).oldbuttons;
                    vStack_a00 = (pcVar36->curstate).startpos.y;
                    vStack_9fc = (pcVar36->curstate).startpos.z;
                    vStack_9f8 = (pcVar36->curstate).endpos.x;
                    iStack_a18 = (pcVar36->curstate).onground;
                    vStack_9f4 = (pcVar36->curstate).endpos.y;
                    iStack_a14 = (pcVar36->curstate).iStepLeft;
                    vStack_9f0 = (pcVar36->curstate).endpos.z;
                    fStack_9ec = (pcVar36->curstate).impacttime;
                    iStack_a08 = (pcVar36->curstate).weaponanim;
                    fStack_9e8 = (pcVar36->curstate).starttime;
                    iStack_9e4 = (pcVar36->curstate).iuser1;
                    fStack_9d4 = (pcVar36->curstate).fuser1;
                    fStack_9d0 = (pcVar36->curstate).fuser2;
                    fStack_9cc = (pcVar36->curstate).fuser3;
                    iStack_9e0 = (pcVar36->curstate).iuser2;
                    fStack_9c8 = (pcVar36->curstate).fuser4;
                    vStack_9c0 = (pcVar36->curstate).vuser1.y;
                    vStack_9bc = (pcVar36->curstate).vuser1.z;
                    iStack_9dc = (pcVar36->curstate).iuser3;
                    vStack_9b8 = (pcVar36->curstate).vuser2.x;
                    iStack_9d8 = (pcVar36->curstate).iuser4;
                    vStack_9c4 = (pcVar36->curstate).vuser1.x;
                    vStack_9b4 = (pcVar36->curstate).vuser2.y;
                    vStack_9b0 = (pcVar36->curstate).vuser2.z;
                    vStack_9ac = (pcVar36->curstate).vuser3.x;
                    vStack_9a8 = (pcVar36->curstate).vuser3.y;
                    vStack_9a4 = (pcVar36->curstate).vuser3.z;
                    vStack_9a0 = (pcVar36->curstate).vuser4.x;
                    vStack_99c = (pcVar36->curstate).vuser4.y;
                    vStack_998 = (pcVar36->curstate).vuser4.z;
                    iStack_994 = pcVar36->current_position;
                    pfVar35 = afStack_990;
                    ppVar41 = pcVar36->ph;
                    do {
                      pfVar47 = pfVar35 + 7;
                      fVar13 = (ppVar41->origin).x;
                      fVar4 = (ppVar41->origin).y;
                      fVar5 = (ppVar41->origin).z;
                      fVar6 = (ppVar41->angles).x;
                      fVar7 = (ppVar41->angles).y;
                      fVar8 = (ppVar41->angles).z;
                      *pfVar35 = ppVar41->animtime;
                      pfVar35[1] = fVar13;
                      pfVar35[2] = fVar4;
                      pfVar35[3] = fVar5;
                      pfVar35[4] = fVar6;
                      pfVar35[5] = fVar7;
                      pfVar35[6] = fVar8;
                      pfVar35 = pfVar47;
                      ppVar41 = ppVar41 + 1;
                    } while (pfVar47 != &fStack_290);
                    uVar12._0_1_ = (pcVar36->latched).prevseqblending[0];
                    uVar12._1_1_ = (pcVar36->latched).prevseqblending[1];
                    uVar12._2_2_ = *(undefined2 *)&(pcVar36->latched).field_0xa;
                    fStack_288 = (pcVar36->latched).prevanimtime;
                    fStack_284 = (pcVar36->latched).sequencetime;
                    iStack_28c = (pcVar36->mouth).sndavg;
                    uStack_280 = (undefined2)uVar12;
                    iStack_264 = (pcVar36->latched).prevsequence;
                    fStack_290 = *(float *)&pcVar36->mouth;
                    vStack_278 = (pcVar36->latched).prevorigin.y;
                    vStack_274 = (pcVar36->latched).prevorigin.z;
                    uStack_25c = *(undefined4 *)(pcVar36->latched).prevcontroller;
                    vStack_270 = (pcVar36->latched).prevangles.x;
                    vStack_26c = (pcVar36->latched).prevangles.y;
                    vStack_268 = (pcVar36->latched).prevangles.z;
                    uVar15._0_1_ = (pcVar36->latched).prevblending[0];
                    uVar15._1_1_ = (pcVar36->latched).prevblending[1];
                    uVar15._2_2_ = *(undefined2 *)&(pcVar36->latched).field_0x32;
                    vStack_27c = (pcVar36->latched).prevorigin.x;
                    fStack_260 = (pcVar36->latched).prevframe;
                    fStack_254 = pcVar36->lastmove;
                    uStack_258 = (undefined2)uVar15;
                    vStack_250 = (pcVar36->origin).x;
                    vStack_228 = pcVar36->attachment[1].y;
                    vStack_224 = pcVar36->attachment[1].z;
                    vStack_220 = pcVar36->attachment[2].x;
                    vStack_21c = pcVar36->attachment[2].y;
                    iStack_208 = pcVar36->trivial_accept;
                    vStack_238 = pcVar36->attachment[0].x;
                    vStack_234 = pcVar36->attachment[0].y;
                    vStack_230 = pcVar36->attachment[0].z;
                    vStack_22c = pcVar36->attachment[1].x;
                    vStack_24c = (pcVar36->origin).y;
                    vStack_248 = (pcVar36->origin).z;
                    vStack_244 = (pcVar36->angles).x;
                    pmStack_204 = pcVar36->model;
                    vStack_240 = (pcVar36->angles).y;
                    vStack_23c = (pcVar36->angles).z;
                    fStack_1f8 = pcVar36->syncbase;
                    peStack_200 = pcVar36->efrag;
                    pmStack_1fc = pcVar36->topnode;
                    uStack_218 = *(undefined8 *)&pcVar36->attachment[2].z;
                    iStack_1f4 = pcVar36->visframe;
                    uStack_210._0_4_ = pcVar36->attachment[3].y;
                    uStack_210._4_4_ = pcVar36->attachment[3].z;
                    uStack_1f0 = (pcVar36->cvFloorColor).r;
                    uStack_1ec = (pcVar36->cvFloorColor).g;
                    uStack_1e8 = (pcVar36->cvFloorColor).b;
                    uStack_1e4 = (pcVar36->cvFloorColor).a;
                    uStack_d58 = uVar9;
                    uStack_c04 = uVar10;
                    uStack_ab0 = uVar11;
                    pmVar24 = (*IEngineStudio.GetModelByIndex)(iVar29);
                    if ((pmVar24 != (model_s *)0x0) && (tfc_newmodels->value == 0.0)) {
                      iVar29 = 0;
                      do {
                        iVar19 = strcasecmp(pmVar24->name,sNewWeaponPModels[iVar29]);
                        if (iVar19 == 0) {
                          (*gEngfuncs.CL_LoadModel)(sOldWeaponPModels[iVar29],&iStack_dc0);
                          pmVar24 = (*IEngineStudio.GetModelByIndex)(iStack_dc0);
                          break;
                        }
                        iVar29 = iVar29 + 1;
                      } while (iVar29 != 0x12);
                    }
                    p1Var18 = (*IEngineStudio.Mod_Extradata)(pmVar24);
                    out->m_pStudioHeader = p1Var18;
                    (*IEngineStudio.StudioSetHeader)(p1Var18);
                    pcVar26 = strstr(out->m_pStudioHeader->name,"p_mini.mdl");
                    iVar29 = out->m_nPlayerIndex;
                    if (pcVar26 == (char *)0x0) {
                      if ((g_flSpinUpTime[iVar29] != 0.0) || (g_flSpinDownTime[iVar29] != 0.0)) {
                        g_flSpinUpTime[iVar29] = 0.0;
                        g_flSpinDownTime[out->m_nPlayerIndex] = 0.0;
                      }
                    }
                    else {
                      fVar13 = g_flSpinUpTime[iVar29];
                      if (fVar13 == 0.0) {
LAB_00081165:
                        fVar13 = g_flSpinDownTime[iVar29];
                        if (fVar13 != 0.0) {
                          (*gEngfuncs.GetClientTime)();
                          iVar29 = out->m_nPlayerIndex;
                          if (((longdouble)fVar13 <= extraout_ST0_02) ||
                             (g_flSpinUpTime[iVar29] != 0.0)) {
                            fVar13 = g_flSpinDownTime[iVar29];
                            if ((fVar13 != 0.0) &&
                               (((*gEngfuncs.GetClientTime)(), (longdouble)fVar13 <= extraout_ST0_03
                                && (g_flSpinUpTime[out->m_nPlayerIndex] == 0.0)))) {
                              g_flSpinDownTime[out->m_nPlayerIndex] = 0.0;
                            }
                          }
                          else {
                            fVar13 = g_flSpinDownTime[iVar29];
                            (*gEngfuncs.GetClientTime)();
                            (out->m_pCurrentEntity->curstate).frame =
                                 (float)((longdouble)fVar13 - (extraout_ST0_04 + (longdouble)3.5)) *
                                 -30.0;
                            (out->m_pCurrentEntity->curstate).sequence = 3;
                          }
                        }
                      }
                      else {
                        (*gEngfuncs.GetClientTime)();
                        if ((longdouble)fVar13 <= extraout_ST0) {
                          iVar29 = out->m_nPlayerIndex;
                          fVar13 = g_flSpinUpTime[iVar29];
                          if (fVar13 != 0.0) {
                            (*gEngfuncs.GetClientTime)();
                            iVar29 = out->m_nPlayerIndex;
                            if ((longdouble)fVar13 <= extraout_ST0_00) {
                              g_flSpinUpTime[iVar29] = 0.0;
                              goto LAB_000811a0;
                            }
                          }
                          goto LAB_00081165;
                        }
                        fVar13 = g_flSpinUpTime[out->m_nPlayerIndex];
                        (*gEngfuncs.GetClientTime)();
                        (out->m_pCurrentEntity->curstate).frame =
                             (float)((longdouble)fVar13 - (extraout_ST0_01 + (longdouble)3.5)) *
                             -30.0;
                        (out->m_pCurrentEntity->curstate).sequence = 2;
                      }
LAB_000811a0:
                      pcVar36 = out->m_pCurrentEntity;
                      if (((pcVar36->curstate).sequence - 0x46U & 0xfffffffd) == 0) {
                        if (g_flSpinUpTime[out->m_nPlayerIndex] != 0.0) {
                          g_flSpinUpTime[out->m_nPlayerIndex] = 0.0;
                          pcVar36 = out->m_pCurrentEntity;
                        }
                        (pcVar36->curstate).sequence = 1;
                      }
                      (**(code **)((int)(*(float (*) [4])&out->_vptr_CStudioModelRenderer)[0] + 0x1c
                                  ))(out);
                    }
                    (**(code **)((int)(*(float (*) [4])&out->_vptr_CStudioModelRenderer)[0] + 0x28))
                              (out);
                    (*IEngineStudio.StudioSetupLighting)(&aStack_db0);
                    pCVar46 = out;
                    (**(code **)((int)(*(float (*) [4])&out->_vptr_CStudioModelRenderer)[0] + 0x4c))
                              ();
                    pcVar14 = *(code **)((int)(*(float (*) [4])&out->_vptr_CStudioModelRenderer)[0]
                                        + 0x20);
                    if (pcVar14 == StudioCalcAttachments) {
                      p1Var18 = out->m_pStudioHeader;
                      if (4 < p1Var18->numattachments) {
LAB_0008199c:
                        StudioCalcAttachments(pCVar46);
                        pmVar24[0x2a].type = mod_brush;
                        pmVar24[0x2a].numframes = 0;
                        pmVar24[0x2a].synctype = ST_SYNC;
                        pmVar24[0x2a].flags = 0;
                        *(undefined ***)pmVar24->name = &PTR__CStudioModelRenderer_000c354c;
                        *(undefined4 *)((int)pmVar24->name + 0x14) = 1;
                        *(undefined4 *)((int)pmVar24->name + 0x18) = 1;
                        *(undefined4 *)((int)pmVar24->name + 0x2c) = 0;
                        *(undefined4 *)((int)pmVar24->name + 0x20) = 0;
                        *(undefined4 *)((int)pmVar24->name + 0x24) = 0;
                        *(undefined4 *)((int)pmVar24->name + 0x28) = 0;
                        (pmVar24->mins).x = 0.0;
                        pmVar24[0x2a].mins.x = 0.0;
                        pmVar24[0x2a].mins.y = 0.0;
                        pmVar24->needload = 0;
                        pmVar24->type = mod_brush;
                        pmVar24->numframes = 0;
                        *(undefined4 *)((int)pmVar24->name + 0x34) = 0;
                        *(undefined4 *)((int)pmVar24->name + 0x30) = 0;
                        return (int)pmVar24;
                      }
                      if (0 < p1Var18->numattachments) {
                        iVar29 = 0;
                        pvVar33 = (vec_t *)(p1Var18->name + p1Var18->attachmentindex + 0x20);
                        do {
                          iVar19 = iVar29 + 1;
                          VectorTransform(pvVar33,(*out->m_plighttransform)[(int)pvVar33[-1]],
                                          &out->m_pCurrentEntity->attachment[iVar29].x);
                          iVar29 = iVar19;
                          pvVar33 = pvVar33 + 0x16;
                        } while (iVar19 < out->m_pStudioHeader->numattachments);
                      }
                    }
                    else {
                      (*pcVar14)(out);
                    }
                    pcVar36 = out->m_pCurrentEntity;
                    piVar40 = &iStack_d98;
                    uVar21 = 3000;
                    pcVar42 = pcVar36;
                    if (((uint)pcVar36 & 4) != 0) {
                      pcVar42 = (cl_entity_t_conflict *)&pcVar36->player;
                      uVar21 = 0xbb4;
                      piVar40 = &qStack_d94;
                      pcVar36->index = iStack_d98;
                    }
                    for (uVar21 = uVar21 >> 2; uVar21 != 0; uVar21 = uVar21 - 1) {
                      pcVar42->index = *piVar40;
                      piVar40 = piVar40 + (uint)bVar45 * -2 + 1;
                      pcVar42 = (cl_entity_t_conflict *)((int)pcVar42 + (uint)bVar45 * -8 + 4);
                    }
                  }
                }
LAB_0008129a:
                iVar29 = 1;
                goto LAB_0007fb43;
              }
              iVar29 = (*IEngineStudio.StudioCheckBBox)();
              if (iVar29 != 0) {
                *out->m_pModelsDrawn = *out->m_pModelsDrawn + 1;
                *out->m_pStudioModelCount = *out->m_pStudioModelCount + 1;
                if (out->m_pStudioHeader->numbodyparts != 0) goto LAB_0007fcbd;
                goto LAB_0008129a;
              }
            }
          }
          iVar29 = 0;
LAB_0007fb43:
          if (iStack_1dc != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
            __stack_chk_fail();
          }
          return iVar29;
        }
        if (0 < p1Var18->numattachments) {
          iVar29 = 0;
          pvVar33 = (vec_t *)(p1Var18->name + p1Var18->attachmentindex + 0x20);
          do {
            iVar19 = iVar29 + 1;
            paafStack_1c0 = (float (*) [3] [4])0x7f7e2;
            VectorTransform(pvVar33,(*this->m_plighttransform)[(int)pvVar33[-1]],
                            &this->m_pCurrentEntity->attachment[iVar29].x);
            iVar29 = iVar19;
            pvVar33 = pvVar33 + 0x16;
          } while (iVar19 < this->m_pStudioHeader->numattachments);
        }
      }
      else {
        paafStack_1c0 = (float (*) [3] [4])0x7f8ed;
        (*this->_vptr_CStudioModelRenderer[8])();
      }
      paafStack_1c0 = (float (*) [3] [4])0x7f7f3;
      (*IEngineStudio.StudioClientEvents)();
      iVar29 = this->m_pCurrentEntity->index;
      if (0 < iVar29) {
                    /* Unresolved local var: cl_entity_t.conflict * ent@[???] */
        uVar21 = 0x30;
        paafStack_1c0 = (float (*) [3] [4])0x7f80e;
        pcVar17 = (*gEngfuncs.GetEntityByIndex)(iVar29);
        pcVar36 = this->m_pCurrentEntity;
        pVVar31 = pcVar36->attachment;
        pVVar37 = pcVar17->attachment;
        bVar44 = ((uint)pVVar37 & 1) != 0;
        if (bVar44) {
          pVVar31 = (Vector *)((int)&pcVar36->attachment[0].x + 1);
          uVar21 = 0x2f;
          *(undefined1 *)&pcVar17->attachment[0].x = *(undefined1 *)&pcVar36->attachment[0].x;
          pVVar37 = (Vector *)((int)&pcVar17->attachment[0].x + 1);
        }
        pVVar38 = pVVar37;
        if (((uint)pVVar37 & 2) != 0) {
          pvVar33 = &pVVar31->x;
          pVVar38 = (Vector *)((int)&pVVar37->x + 2);
          pVVar31 = (Vector *)((int)&pVVar31->x + 2);
          uVar21 = uVar21 - 2;
          *(undefined2 *)&pVVar37->x = *(undefined2 *)pvVar33;
        }
        uVar43 = 0;
        do {
          uVar22 = uVar43;
          *(undefined4 *)((int)&pVVar38->x + uVar22) = *(undefined4 *)((int)&pVVar31->x + uVar22);
          uVar43 = uVar22 + 4;
        } while (uVar22 + 4 < (uVar21 & 0xfffffffc));
        puVar32 = (undefined2 *)((int)&pVVar38->y + uVar22);
        puVar28 = (undefined2 *)((int)&pVVar31->y + uVar22);
        iVar29 = 0;
        if ((uVar21 & 2) != 0) {
          iVar29 = 2;
          *puVar32 = *puVar28;
        }
        if (bVar44) {
          *(undefined1 *)((int)puVar32 + iVar29) = *(undefined1 *)((int)puVar28 + iVar29);
        }
      }
    }
    if ((flags & 1U) != 0) {
      local_18c.plightvec = local_198;
      paafStack_1c0 = (float (*) [3] [4])0x7f704;
      (*IEngineStudio.StudioDynamicLight)((cl_entity_s *)this->m_pCurrentEntity,&local_18c);
      paafStack_1c0 = (float (*) [3] [4])0x7f70d;
      (*IEngineStudio.StudioEntityLight)(&local_18c);
      paafStack_1c0 = (float (*) [3] [4])0x7f716;
      (*IEngineStudio.StudioSetupLighting)(&local_18c);
      pcVar17 = (cl_entity_s *)this->m_pCurrentEntity;
      uVar21 = (uint)(byte)(pcVar17->curstate).colormap;
      this->m_nTopColor = uVar21;
      this->m_nBottomColor = (uint)*(byte *)((int)&(pcVar17->curstate).colormap + 1);
      if (uVar21 - 0x88 < 0x13) {
        this->m_nTopColor = 0x96;
        this->m_nBottomColor = 0x8c;
      }
      else if ((uVar21 < 0xf1) && (uVar21 != 5)) {
        if (uVar21 - 0x29 < 9) {
          this->m_nTopColor = 0x2d;
          this->m_nBottomColor = 0x23;
        }
        else if (uVar21 - 0x4c < 0x22) {
          this->m_nTopColor = 100;
          this->m_nBottomColor = 0x5a;
        }
      }
      else {
        this->m_nTopColor = 0xfa;
        this->m_nBottomColor = 0xf0;
      }
      paafStack_1c0 = (float (*) [3] [4])0x7f8b4;
      pcVar23 = (*gEngfuncs.GetViewModel)();
      if (pcVar17 == pcVar23) {
                    /* Unresolved local var: cl_entity_t.conflict * pTarget@[???] */
        if ((g_iUser1 == 4) || ((g_iUser1 != 0 && ((gHUD.m_Spectator.m_pip)->value == 2.0)))) {
          paafStack_1c0 = (float (*) [3] [4])0x7f932;
          pcVar17 = (*gEngfuncs.GetEntityByIndex)(g_iUser2);
          if (pcVar17 != (cl_entity_s *)0x0) {
                    /* Unresolved local var: int retVal@[???] */
            iVar29 = 0x96;
            uVar21 = (ushort)g_PlayerExtraInfo[pcVar17->index].teamnumber - 2 & 0xffff;
            if (uVar21 < 3) {
              iVar29 = *(int *)(CSWTCH_95 + uVar21 * 4);
            }
            this->m_nTopColor = iVar29;
                    /* Unresolved local var: int retVal@[???] */
            iVar29 = 0x8c;
            uVar21 = (ushort)g_PlayerExtraInfo[pcVar17->index].teamnumber - 2 & 0xffff;
            if (uVar21 < 3) {
              iVar29 = *(int *)(CSWTCH_96 + uVar21 * 4);
            }
            this->m_nBottomColor = iVar29;
            goto LAB_0007f994;
          }
        }
        else {
          paafStack_1c0 = (float (*) [3] [4])0x7f9f4;
          pcVar17 = (*gEngfuncs.GetLocalPlayer)();
          if (pcVar17 != (cl_entity_s *)0x0) {
LAB_0007f994:
            if ((pcVar17->curstate).renderfx == 0x13) {
              (this->m_pCurrentEntity->curstate).renderfx = 0x13;
              (this->m_pCurrentEntity->curstate).rendercolor.r = (pcVar17->curstate).rendercolor.r;
              (this->m_pCurrentEntity->curstate).rendercolor.g = (pcVar17->curstate).rendercolor.g;
              (this->m_pCurrentEntity->curstate).rendercolor.b = (pcVar17->curstate).rendercolor.b;
              goto LAB_0007f8b8;
            }
          }
        }
        (this->m_pCurrentEntity->curstate).renderfx = 0;
        (this->m_pCurrentEntity->curstate).rendercolor.r = '\0';
        (this->m_pCurrentEntity->curstate).rendercolor.g = '\0';
        (this->m_pCurrentEntity->curstate).rendercolor.b = '\0';
      }
LAB_0007f8b8:
      paafStack_1c0 = (float (*) [3] [4])0x7f8cb;
      (*IEngineStudio.StudioSetRemapColors)(this->m_nTopColor,this->m_nBottomColor);
      paafStack_1c0 = (float (*) [3] [4])0x7f8d3;
      (*this->_vptr_CStudioModelRenderer[0x13])();
    }
  }
  else {
    paafStack_1c0 = (float (*) [3] [4])0x7f6b6;
    iVar29 = (*IEngineStudio.StudioCheckBBox)();
    iVar19 = 0;
    if (iVar29 == 0) goto LAB_0007f584;
    *this->m_pModelsDrawn = *this->m_pModelsDrawn + 1;
    *this->m_pStudioModelCount = *this->m_pStudioModelCount + 1;
    unaff_EDI = this->m_pStudioHeader->numbodyparts;
    if (unaff_EDI != 0) goto LAB_0007f4a5;
  }
  iVar19 = 1;
LAB_0007f584:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    paafStack_1c0 = (float (*) [3] [4])0x7fa7a;
    __stack_chk_fail();
  }
  return iVar19;
}


// CStudioModelRenderer::StudioEstimateGait  @ 0007d500  (line 1344)

/* DWARF original prototype: void StudioEstimateGait(CStudioModelRenderer * this, entity_state_t *
   pplayer) */

void __thiscall
CStudioModelRenderer::StudioEstimateGait(CStudioModelRenderer *this,entity_state_t *pplayer)

{
  float fVar1;
  cl_entity_t_conflict *pcVar2;
  float fVar3;
  player_info_t *ppVar4;
  float fVar5;
  double dVar6;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: float dt@[???]
                       Unresolved local var: Vector est_velocity@[???] */
  fVar1 = (float)((longdouble)this->m_clTime - (longdouble)this->m_clOldTime);
  if (fVar1 < 0.0) goto LAB_0007d6e0;
  if (fVar1 <= 1.0) {
    if (fVar1 == 0.0) goto LAB_0007d6e0;
  }
  else {
    fVar1 = 1.0;
  }
  ppVar4 = this->m_pPlayerInfo;
  if (ppVar4->renderframe == this->m_nFrameCount) goto LAB_0007d6e0;
  if (this->m_fGaitEstimation == 0) {
    local_18 = (pplayer->velocity).x;
    local_14 = (pplayer->velocity).y;
    local_10 = (pplayer->velocity).z;
    fVar5 = Length(&local_18);
    fVar5 = fVar5 * fVar1;
LAB_0007d732:
    this->m_flGaitMovement = fVar5;
    if ((local_14 != 0.0) || (local_18 != 0.0)) {
      ppVar4 = this->m_pPlayerInfo;
      dVar6 = atan2((double)local_14,(double)local_18);
      ppVar4->gaityaw = ((float)dVar6 * 180.0) / 3.1415927;
      ppVar4 = this->m_pPlayerInfo;
      fVar1 = ppVar4->gaityaw;
      if (180.0 < fVar1) {
        ppVar4->gaityaw = 180.0;
        ppVar4 = this->m_pPlayerInfo;
        fVar1 = ppVar4->gaityaw;
      }
      if (-180.0 <= fVar1) {
        return;
      }
      ppVar4->gaityaw = -180.0;
      return;
    }
  }
  else {
    pcVar2 = this->m_pCurrentEntity;
    fVar5 = (pcVar2->origin).x;
    local_18 = fVar5 - (ppVar4->prevgaitorigin).x;
    local_14 = (pcVar2->origin).y - (ppVar4->prevgaitorigin).y;
    local_10 = (pcVar2->origin).z - (ppVar4->prevgaitorigin).z;
    (ppVar4->prevgaitorigin).x = fVar5;
    (this->m_pPlayerInfo->prevgaitorigin).y = (this->m_pCurrentEntity->origin).y;
    (this->m_pPlayerInfo->prevgaitorigin).z = (this->m_pCurrentEntity->origin).z;
    fVar5 = Length(&local_18);
    if ((0.0 < fVar1) && (5.0 <= fVar5 / fVar1)) goto LAB_0007d732;
    this->m_flGaitMovement = 0.0;
  }
                    /* Unresolved local var: float flYawDiff@[???] */
  fVar5 = this->m_pPlayerInfo->gaityaw;
  fVar3 = (this->m_pCurrentEntity->angles).y - fVar5;
  fVar3 = fVar3 - (float)((int)(fVar3 / 360.0) * 0x168);
  if (180.0 < fVar3) {
    fVar3 = fVar3 - 360.0;
  }
  if (fVar3 < -180.0) {
    fVar3 = fVar3 + 360.0;
  }
  if (fVar1 < 0.25) {
    fVar1 = fVar1 * 4.0;
  }
  this->m_pPlayerInfo->gaityaw = fVar5 + fVar1 * fVar3;
  ppVar4 = this->m_pPlayerInfo;
  ppVar4->gaityaw = ppVar4->gaityaw - (float)((int)(ppVar4->gaityaw / 360.0) * 0x168);
LAB_0007d6e0:
  this->m_flGaitMovement = 0.0;
  return;
}


// CStudioModelRenderer::StudioProcessGait  @ 0007e820  (line 1416)

/* DWARF original prototype: void StudioProcessGait(CStudioModelRenderer * this, entity_state_t *
   pplayer) */

void __thiscall
CStudioModelRenderer::StudioProcessGait(CStudioModelRenderer *this,entity_state_t *pplayer)

{
  float fVar1;
  float fVar2;
  float fVar3;
  player_info_t *ppVar4;
  float fVar5;
  byte bVar6;
  char *pcVar7;
  cl_entity_t_conflict *pcVar8;
  int iVar9;
  _1studiohdr_t *p1Var10;
  int local_10;
  
                    /* Unresolved local var: 16mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: float dt@[???]
                       Unresolved local var: int iBlend@[???]
                       Unresolved local var: float flYaw@[???] */
  pcVar8 = this->m_pCurrentEntity;
  p1Var10 = this->m_pStudioHeader;
  iVar9 = (pcVar8->curstate).sequence;
  if (p1Var10->numseq <= iVar9) {
    (pcVar8->curstate).sequence = 0;
    pcVar8 = this->m_pCurrentEntity;
    p1Var10 = this->m_pStudioHeader;
    iVar9 = (pcVar8->curstate).sequence;
  }
  pcVar7 = p1Var10->name + iVar9 * 0xb0 + p1Var10->seqindex + -8;
  if (this->_vptr_CStudioModelRenderer[0x17] == StudioPlayerBlend) {
    fVar1 = (pcVar8->angles).x;
    fVar5 = (float)(int)(fVar1 * 3.0);
    fVar2 = *(float *)(pcVar7 + 0x88);
    if (fVar5 < fVar2) {
      local_10 = 0;
      (pcVar8->angles).x = fVar1 - fVar2 / 3.0;
      bVar6 = '\0';
    }
    else {
      fVar3 = *(float *)(pcVar7 + 0x90);
      if (fVar3 < fVar5) {
        local_10 = 0xff;
        (pcVar8->angles).x = fVar1 - fVar3 / 3.0;
        bVar6 = 0xff;
      }
      else {
        if (0.1 <= fVar3 - fVar2) {
          local_10 = (int)(((fVar5 - fVar2) * 255.0) / (fVar3 - fVar2));
          bVar6 = (byte)local_10;
        }
        else {
          bVar6 = '\x7f';
          local_10 = 0x7f;
        }
        (pcVar8->angles).x = 0.0;
      }
    }
  }
  else {
    (*this->_vptr_CStudioModelRenderer[0x17])(this,pcVar7,&local_10,&pcVar8->angles);
    bVar6 = (byte)local_10;
  }
  (this->m_pCurrentEntity->latched).prevangles.x = (this->m_pCurrentEntity->angles).x;
  (this->m_pCurrentEntity->curstate).blending[0] = bVar6;
  (this->m_pCurrentEntity->latched).prevblending[0] = (this->m_pCurrentEntity->curstate).blending[0]
  ;
  (this->m_pCurrentEntity->latched).prevseqblending[0] =
       (this->m_pCurrentEntity->curstate).blending[0];
  fVar1 = (float)((longdouble)this->m_clTime - (longdouble)this->m_clOldTime);
  if (fVar1 < 0.0) {
    fVar1 = 0.0;
  }
  else if (1.0 < fVar1) {
    fVar1 = 1.0;
  }
  (*this->_vptr_CStudioModelRenderer[0x18])(this,pplayer);
  ppVar4 = this->m_pPlayerInfo;
  pcVar8 = this->m_pCurrentEntity;
  fVar2 = ppVar4->gaityaw;
  fVar5 = (pcVar8->angles).y - fVar2;
  fVar5 = fVar5 - (float)((int)(fVar5 / 360.0) * 0x168);
  if (fVar5 < -180.0) {
    fVar5 = fVar5 + 360.0;
  }
  if (180.0 < fVar5) {
    fVar5 = fVar5 - 360.0;
  }
  if (fVar5 <= 120.0) {
    if (fVar5 < -120.0) {
      ppVar4->gaityaw = fVar2 + 180.0;
      pcVar8 = this->m_pCurrentEntity;
      this->m_flGaitMovement = -this->m_flGaitMovement;
      fVar5 = fVar5 + 180.0;
    }
  }
  else {
    ppVar4->gaityaw = fVar2 - 180.0;
    pcVar8 = this->m_pCurrentEntity;
    this->m_flGaitMovement = -this->m_flGaitMovement;
    fVar5 = fVar5 - 180.0;
  }
  bVar6 = (byte)(int)((fVar5 * 0.25 + 30.0) / 0.23529412);
  (pcVar8->curstate).controller[0] = bVar6;
  (this->m_pCurrentEntity->curstate).controller[1] = bVar6;
  (this->m_pCurrentEntity->curstate).controller[2] = bVar6;
  (this->m_pCurrentEntity->curstate).controller[3] = bVar6;
  (this->m_pCurrentEntity->latched).prevcontroller[0] =
       (this->m_pCurrentEntity->curstate).controller[0];
  (this->m_pCurrentEntity->latched).prevcontroller[1] =
       (this->m_pCurrentEntity->curstate).controller[1];
  (this->m_pCurrentEntity->latched).prevcontroller[2] =
       (this->m_pCurrentEntity->curstate).controller[2];
  (this->m_pCurrentEntity->latched).prevcontroller[3] =
       (this->m_pCurrentEntity->curstate).controller[3];
  (this->m_pCurrentEntity->angles).y = this->m_pPlayerInfo->gaityaw;
  pcVar8 = this->m_pCurrentEntity;
  fVar2 = (pcVar8->angles).y;
  if (fVar2 < 0.0) {
    (pcVar8->angles).y = fVar2 + 360.0;
    pcVar8 = this->m_pCurrentEntity;
    fVar2 = (pcVar8->angles).y;
  }
  (pcVar8->latched).prevangles.y = fVar2;
  p1Var10 = this->m_pStudioHeader;
  if (pplayer->gaitsequence < p1Var10->numseq) {
    iVar9 = pplayer->gaitsequence * 0xb0;
  }
  else {
    pplayer->gaitsequence = 0;
    iVar9 = 0;
    p1Var10 = this->m_pStudioHeader;
  }
  iVar9 = iVar9 + p1Var10->seqindex;
  ppVar4 = this->m_pPlayerInfo;
  if (*(float *)(p1Var10->name + iVar9 + 0x44) <= 0.0) {
    ppVar4->gaitframe = fVar1 * *(float *)(p1Var10->name + iVar9 + 0x18) + ppVar4->gaitframe;
  }
  else {
    ppVar4->gaitframe =
         (float)*(int *)(p1Var10->name + iVar9 + 0x30) *
         (this->m_flGaitMovement / *(float *)(p1Var10->name + iVar9 + 0x44)) + ppVar4->gaitframe;
  }
  ppVar4 = this->m_pPlayerInfo;
  ppVar4->gaitframe =
       ppVar4->gaitframe -
       (float)((int)(ppVar4->gaitframe / (float)*(int *)(p1Var10->name + iVar9 + 0x30)) *
              *(int *)(p1Var10->name + iVar9 + 0x30));
  fVar1 = this->m_pPlayerInfo->gaitframe;
  if (fVar1 < 0.0) {
    this->m_pPlayerInfo->gaitframe = (float)*(int *)(p1Var10->name + iVar9 + 0x30) + fVar1;
  }
  return;
}


// CStudioModelRenderer::ReturnDiguisedClass  @ 00081aa0  (line 1609)

/* DWARF original prototype: int ReturnDiguisedClass(CStudioModelRenderer * this, int iPlayerIndex)
    */

int __thiscall
CStudioModelRenderer::ReturnDiguisedClass(CStudioModelRenderer *this,int iPlayerIndex)

{
  model_s *__s1;
  int iVar1;
  int iVar2;
  
  __s1 = (*IEngineStudio.SetupPlayerModel)(iPlayerIndex);
  this->m_pRenderModel = __s1;
  if (__s1 != (model_s *)0x0) {
                    /* Unresolved local var: int i@[???] */
    iVar1 = strcmp(__s1->name,sNewClassModelFiles[1]);
    if (iVar1 != 0) {
      iVar1 = strcmp(__s1->name,sNewClassModelFiles[2]);
      if (iVar1 == 0) {
        iVar1 = 2;
      }
      else {
        iVar1 = strcmp(__s1->name,sNewClassModelFiles[3]);
        if (iVar1 == 0) {
          iVar1 = 3;
        }
        else {
          iVar1 = strcmp(__s1->name,sNewClassModelFiles[4]);
          if (iVar1 == 0) {
            iVar1 = 4;
          }
          else {
            iVar1 = strcmp(__s1->name,sNewClassModelFiles[5]);
            if (iVar1 == 0) {
              iVar1 = 5;
            }
            else {
              iVar1 = strcmp(__s1->name,sNewClassModelFiles[6]);
              if (iVar1 == 0) {
                iVar1 = 6;
              }
              else {
                iVar1 = strcmp(__s1->name,sNewClassModelFiles[7]);
                if (iVar1 == 0) {
                  iVar1 = 7;
                }
                else {
                  iVar1 = strcmp(__s1->name,sNewClassModelFiles[8]);
                  if (iVar1 == 0) {
                    iVar1 = 8;
                  }
                  else {
                    iVar1 = strcmp(__s1->name,sNewClassModelFiles[9]);
                    if (iVar1 == 0) {
                      iVar1 = 9;
                    }
                    else {
                      iVar1 = strcmp(__s1->name,sNewClassModelFiles[10]);
                      if (iVar1 == 0) {
                        iVar1 = 10;
                      }
                      else {
                        iVar2 = strcmp(__s1->name,sNewClassModelFiles[0xb]);
                        iVar1 = 1;
                        if (iVar2 == 0) {
                          iVar1 = 0xb;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      return iVar1;
    }
  }
  return 1;
}


// ReturnCorrectedModelString  @ 00081c90  (line 1626)

char * ReturnCorrectedModelString(int iSwitchClass)

{
  char *pcVar1;
  
  if (tfc_newmodels->value != 0.0) {
    pcVar1 = sNewClassModelFiles[iSwitchClass];
    if (sNewClassModelFiles[iSwitchClass] == (char *)0x0) {
      pcVar1 = sNewClassModelFiles[1];
    }
    return pcVar1;
  }
  pcVar1 = sOldClassModelFiles[iSwitchClass];
  if (sOldClassModelFiles[iSwitchClass] == (char *)0x0) {
    pcVar1 = sOldClassModelFiles[1];
  }
  return pcVar1;
}


// CStudioModelRenderer::StudioDrawPlayer  @ 0007fa90  (line 1657)

/* DWARF original prototype: int StudioDrawPlayer(CStudioModelRenderer * this, int flags,
   entity_state_t * pplayer) */

int __thiscall
CStudioModelRenderer::StudioDrawPlayer(CStudioModelRenderer *this,int flags,entity_state_t *pplayer)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  cvar_t *pcVar15;
  uint uVar16;
  cl_entity_s *pcVar17;
  int iVar18;
  int iVar19;
  model_s *pmVar20;
  _1studiohdr_t *p1Var21;
  player_info_s *ppVar22;
  char *pcVar23;
  uint uVar24;
  char (*__dest) [32];
  uint uVar25;
  Vector *pVVar26;
  undefined2 *puVar27;
  vec_t *pvVar28;
  float *pfVar29;
  float *pfVar30;
  cl_entity_t_conflict *pcVar31;
  Vector *pVVar32;
  Vector *pVVar33;
  undefined2 *puVar34;
  float (*out) [3] [4];
  int *piVar35;
  position_history_t *ppVar36;
  cl_entity_t_conflict *pcVar37;
  int in_GS_OFFSET;
  bool bVar38;
  byte bVar39;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  longdouble extraout_ST0_04;
  CStudioModelRenderer *this_00;
  int local_c04;
  float local_c00 [3];
  alight_s local_bf4;
  int local_bdc;
  qboolean qStack_bd8;
  int iStack_bd4;
  int iStack_bd0;
  float local_bcc;
  int local_bc8;
  vec_t local_bc4;
  vec_t local_bc0;
  vec_t local_bbc;
  vec_t local_bb8;
  vec_t local_bb4;
  vec_t local_bb0;
  int local_bac;
  int local_ba8;
  float local_ba4;
  int local_ba0;
  undefined2 local_b9c;
  short local_b9a;
  int local_b98;
  float local_b94;
  byte local_b90;
  int local_b8c;
  int local_b88;
  undefined2 local_b84;
  byte local_b82;
  int local_b80;
  int local_b7c;
  float local_b78;
  float local_b74;
  int local_b70;
  undefined4 local_b6c;
  undefined4 local_b68;
  vec_t local_b64;
  vec_t local_b60;
  vec_t local_b5c;
  vec_t local_b58;
  vec_t local_b54;
  vec_t local_b50;
  vec_t local_b4c;
  vec_t local_b48;
  vec_t local_b44;
  int local_b40;
  int local_b3c;
  float local_b38;
  float local_b34;
  int local_b30;
  int local_b2c;
  int local_b28;
  qboolean local_b24;
  int local_b20;
  int local_b1c;
  vec_t local_b18;
  vec_t local_b14;
  vec_t local_b10;
  int local_b0c;
  int local_b08;
  int local_b04;
  int local_b00;
  float local_afc;
  float local_af8;
  int local_af4;
  vec_t local_af0;
  vec_t local_aec;
  vec_t local_ae8;
  vec_t local_ae4;
  vec_t local_ae0;
  vec_t local_adc;
  float local_ad8;
  float local_ad4;
  int local_ad0;
  int local_acc;
  int local_ac8;
  int local_ac4;
  float local_ac0;
  float local_abc;
  float local_ab8;
  float local_ab4;
  vec_t local_ab0;
  vec_t local_aac;
  vec_t local_aa8;
  vec_t local_aa4;
  vec_t local_aa0;
  vec_t local_a9c;
  vec_t local_a98;
  vec_t local_a94;
  vec_t local_a90;
  vec_t local_a8c;
  vec_t local_a88;
  vec_t local_a84;
  int local_a80;
  int local_a7c;
  float local_a78;
  int local_a74;
  vec_t local_a70;
  vec_t local_a6c;
  vec_t local_a68;
  vec_t local_a64;
  vec_t local_a60;
  vec_t local_a5c;
  int local_a58;
  int local_a54;
  float local_a50;
  int local_a4c;
  undefined2 local_a48;
  short local_a46;
  int local_a44;
  float local_a40;
  byte local_a3c;
  int local_a38;
  int local_a34;
  undefined2 local_a30;
  byte local_a2e;
  int local_a2c;
  int local_a28;
  float local_a24;
  float local_a20;
  int local_a1c;
  undefined4 local_a18;
  undefined4 local_a14;
  vec_t local_a10;
  vec_t local_a0c;
  vec_t local_a08;
  vec_t local_a04;
  vec_t local_a00;
  vec_t local_9fc;
  vec_t local_9f8;
  vec_t local_9f4;
  vec_t local_9f0;
  int local_9ec;
  int local_9e8;
  float local_9e4;
  float local_9e0;
  int local_9dc;
  int local_9d8;
  int local_9d4;
  qboolean local_9d0;
  int local_9cc;
  int local_9c8;
  vec_t local_9c4;
  vec_t local_9c0;
  vec_t local_9bc;
  int local_9b8;
  int local_9b4;
  int local_9b0;
  int local_9ac;
  float local_9a8;
  float local_9a4;
  int local_9a0;
  vec_t local_99c;
  vec_t local_998;
  vec_t local_994;
  vec_t local_990;
  vec_t local_98c;
  vec_t local_988;
  float local_984;
  float local_980;
  int local_97c;
  int local_978;
  int local_974;
  int local_970;
  float local_96c;
  float local_968;
  float local_964;
  float local_960;
  vec_t local_95c;
  vec_t local_958;
  vec_t local_954;
  vec_t local_950;
  vec_t local_94c;
  vec_t local_948;
  vec_t local_944;
  vec_t local_940;
  vec_t local_93c;
  vec_t local_938;
  vec_t local_934;
  vec_t local_930;
  int local_92c;
  int local_928;
  float local_924;
  int local_920;
  vec_t local_91c;
  vec_t local_918;
  vec_t local_914;
  vec_t local_910;
  vec_t local_90c;
  vec_t local_908;
  int local_904;
  int local_900;
  float local_8fc;
  int local_8f8;
  undefined2 local_8f4;
  short local_8f2;
  int local_8f0;
  float local_8ec;
  byte local_8e8;
  int local_8e4;
  int local_8e0;
  undefined2 local_8dc;
  byte local_8da;
  int local_8d8;
  int local_8d4;
  float local_8d0;
  float local_8cc;
  int local_8c8;
  undefined4 local_8c4;
  undefined4 local_8c0;
  vec_t local_8bc;
  vec_t local_8b8;
  vec_t local_8b4;
  vec_t local_8b0;
  vec_t local_8ac;
  vec_t local_8a8;
  vec_t local_8a4;
  vec_t local_8a0;
  vec_t local_89c;
  int local_898;
  int local_894;
  float local_890;
  float local_88c;
  int local_888;
  int local_884;
  int local_880;
  qboolean local_87c;
  int local_878;
  int local_874;
  vec_t local_870;
  vec_t local_86c;
  vec_t local_868;
  int local_864;
  int local_860;
  int local_85c;
  int local_858;
  float local_854;
  float local_850;
  int local_84c;
  vec_t local_848;
  vec_t local_844;
  vec_t local_840;
  vec_t local_83c;
  vec_t local_838;
  vec_t local_834;
  float local_830;
  float local_82c;
  int local_828;
  int local_824;
  int local_820;
  int local_81c;
  float local_818;
  float local_814;
  float local_810;
  float local_80c;
  vec_t local_808;
  vec_t local_804;
  vec_t local_800;
  vec_t local_7fc;
  vec_t local_7f8;
  vec_t local_7f4;
  vec_t local_7f0;
  vec_t local_7ec;
  vec_t local_7e8;
  vec_t local_7e4;
  vec_t local_7e0;
  vec_t local_7dc;
  int local_7d8;
  float local_7d4 [448];
  float local_d4;
  int local_d0;
  float local_cc;
  float local_c8;
  undefined2 local_c4;
  vec_t local_c0;
  vec_t local_bc;
  vec_t local_b8;
  vec_t local_b4;
  vec_t local_b0;
  vec_t local_ac;
  int local_a8;
  float local_a4;
  undefined4 local_a0;
  undefined2 local_9c;
  float local_98;
  vec_t local_94;
  vec_t local_90;
  vec_t local_8c;
  vec_t local_88;
  vec_t local_84;
  vec_t local_80;
  vec_t local_7c;
  vec_t vStack_78;
  vec_t vStack_74;
  vec_t vStack_70;
  vec_t local_6c;
  vec_t vStack_68;
  vec_t vStack_64;
  vec_t vStack_60;
  undefined8 local_5c;
  undefined8 uStack_54;
  int local_4c;
  model_s_conflict *local_48;
  efrag_s *local_44;
  mnode_s *local_40;
  float local_3c;
  int local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  int local_20;
  
                    /* Unresolved local var: alight_t lighting@[???]
                       Unresolved local var: Vector dir@[???]
                       Unresolved local var: int modelindex@[???]
                       Unresolved local var: int iSwitchClass@[???] */
  bVar39 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar17 = (*IEngineStudio.GetCurrentEntity)();
  this->m_pCurrentEntity = (cl_entity_t_conflict *)pcVar17;
  (*IEngineStudio.GetTimes)(&this->m_nFrameCount,&this->m_clTime,&this->m_clOldTime);
  (*IEngineStudio.GetViewInfo)(this->m_vRenderOrigin,this->m_vUp,this->m_vRight,this->m_vNormal);
  (*IEngineStudio.GetAliasScale)(&this->m_fSoftwareXScale,&this->m_fSoftwareYScale);
  iVar19 = pplayer->number + -1;
  this->m_nPlayerIndex = iVar19;
  if ((-1 < iVar19) && (iVar18 = (*gEngfuncs.GetMaxClients)(), iVar19 < iVar18)) {
    iVar19 = pplayer->playerclass;
    if (iVar19 == 8) {
      pmVar20 = (*IEngineStudio.SetupPlayerModel)(this->m_nPlayerIndex);
      this->m_pRenderModel = pmVar20;
                    /* Unresolved local var: int i@[???] */
      if ((pmVar20 == (model_s *)0x0) ||
         (iVar18 = strcmp(pmVar20->name,sNewClassModelFiles[1]), iVar18 == 0)) {
        iVar19 = 1;
      }
      else {
        iVar18 = strcmp(pmVar20->name,sNewClassModelFiles[2]);
        if (iVar18 == 0) {
          iVar19 = 2;
        }
        else {
          iVar18 = strcmp(pmVar20->name,sNewClassModelFiles[3]);
          if (iVar18 == 0) {
            iVar19 = 3;
          }
          else {
            iVar18 = strcmp(pmVar20->name,sNewClassModelFiles[4]);
            if (iVar18 == 0) {
              iVar19 = 4;
            }
            else {
              iVar18 = strcmp(pmVar20->name,sNewClassModelFiles[5]);
              if (iVar18 == 0) {
                iVar19 = 5;
              }
              else {
                iVar18 = strcmp(pmVar20->name,sNewClassModelFiles[6]);
                if (iVar18 == 0) {
                  iVar19 = 6;
                }
                else {
                  iVar18 = strcmp(pmVar20->name,sNewClassModelFiles[7]);
                  if (iVar18 == 0) {
                    iVar19 = 7;
                  }
                  else {
                    iVar18 = strcmp(pmVar20->name,sNewClassModelFiles[8]);
                    if (iVar18 != 0) {
                      iVar19 = strcmp(pmVar20->name,sNewClassModelFiles[9]);
                      if (iVar19 == 0) {
                        iVar19 = 9;
                      }
                      else {
                        iVar19 = strcmp(pmVar20->name,sNewClassModelFiles[10]);
                        if (iVar19 == 0) {
                          iVar19 = 10;
                        }
                        else {
                          iVar19 = strcmp(pmVar20->name,sNewClassModelFiles[0xb]);
                          iVar19 = (-(uint)(iVar19 == 0) & 10) + 1;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if (pplayer->fuser1 == 0.0) {
      if (tfc_newmodels->value == 0.0) {
        pcVar23 = sOldClassModelFiles[iVar19];
        if (sOldClassModelFiles[iVar19] == (char *)0x0) {
          pcVar23 = sOldClassModelFiles[1];
        }
      }
      else {
        pcVar23 = sNewClassModelFiles[iVar19];
        if (pcVar23 == (char *)0x0) {
          pcVar23 = sNewClassModelFiles[1];
        }
      }
      pmVar20 = (*gEngfuncs.CL_LoadModel)(pcVar23,&local_c04);
      this->m_pRenderModel = pmVar20;
    }
    else {
      pmVar20 = (*IEngineStudio.SetupPlayerModel)(this->m_nPlayerIndex);
      this->m_pRenderModel = pmVar20;
    }
    if (pmVar20 != (model_s *)0x0) {
      p1Var21 = (*IEngineStudio.Mod_Extradata)(pmVar20);
      this->m_pStudioHeader = p1Var21;
      (*IEngineStudio.StudioSetHeader)(p1Var21);
      (*IEngineStudio.SetRenderModel)(this->m_pRenderModel);
      if (pplayer->gaitsequence == 0) {
        (this->m_pCurrentEntity->curstate).controller[0] = '\x7f';
        (this->m_pCurrentEntity->curstate).controller[1] = '\x7f';
        (this->m_pCurrentEntity->curstate).controller[2] = '\x7f';
        (this->m_pCurrentEntity->curstate).controller[3] = '\x7f';
        (this->m_pCurrentEntity->latched).prevcontroller[0] =
             (this->m_pCurrentEntity->curstate).controller[0];
        (this->m_pCurrentEntity->latched).prevcontroller[1] =
             (this->m_pCurrentEntity->curstate).controller[1];
        (this->m_pCurrentEntity->latched).prevcontroller[2] =
             (this->m_pCurrentEntity->curstate).controller[2];
        (this->m_pCurrentEntity->latched).prevcontroller[3] =
             (this->m_pCurrentEntity->curstate).controller[3];
        ppVar22 = (*IEngineStudio.PlayerInfo)(this->m_nPlayerIndex);
        this->m_pPlayerInfo = ppVar22;
        ppVar22->gaitsequence = 0;
        pmVar20 = (model_s *)0x0;
        (*this->_vptr_CStudioModelRenderer[6])(this);
      }
      else {
                    /* Unresolved local var: Vector orig_angles@[???] */
        ppVar22 = (*IEngineStudio.PlayerInfo)(this->m_nPlayerIndex);
        this->m_pPlayerInfo = ppVar22;
        pcVar31 = this->m_pCurrentEntity;
        vVar1 = (pcVar31->angles).x;
        vVar2 = (pcVar31->angles).y;
        vVar3 = (pcVar31->angles).z;
        (*this->_vptr_CStudioModelRenderer[0x19])(this,pplayer);
        this->m_pPlayerInfo->gaitsequence = pplayer->gaitsequence;
        this->m_pPlayerInfo = (player_info_t *)0x0;
        pmVar20 = (model_s *)0x0;
        (*this->_vptr_CStudioModelRenderer[6])(this);
        (this->m_pCurrentEntity->angles).x = vVar1;
        (this->m_pCurrentEntity->angles).y = vVar2;
        (this->m_pCurrentEntity->angles).z = vVar3;
      }
      if ((flags & 1U) == 0) {
LAB_0007fcbd:
        ppVar22 = (*IEngineStudio.PlayerInfo)(this->m_nPlayerIndex);
        this->m_pPlayerInfo = ppVar22;
        this_00 = this;
        (*this->_vptr_CStudioModelRenderer[7])();
        if (this->_vptr_CStudioModelRenderer[9] == StudioSaveBones) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: mstudiobone_t * pbones@[???] */
          p1Var21 = this->m_pStudioHeader;
          iVar19 = p1Var21->boneindex;
          this->m_nCachedBones = p1Var21->numbones;
          if (0 < p1Var21->numbones) {
            __dest = this->m_nCachedBoneNames;
            pvVar28 = (vec_t *)(p1Var21->name + iVar19 + -8);
            out = this->m_rgCachedBoneTransform;
            iVar19 = 0;
            do {
              iVar18 = iVar19 + 1;
              strcpy(*__dest,(char *)pvVar28);
              MatrixCopy((*this->m_pbonetransform)[iVar19],*out);
              pmVar20 = (model_s *)(out + 0x80);
              out = out + 1;
              this_00 = (CStudioModelRenderer *)(*this->m_plighttransform + iVar19);
              MatrixCopy((float (*) [4])this_00,(float (*) [4])pmVar20);
              __dest = __dest + 1;
              pvVar28 = pvVar28 + 0x1c;
              iVar19 = iVar18;
            } while (iVar18 < this->m_pStudioHeader->numbones);
          }
        }
        else {
          this_00 = this;
          (*this->_vptr_CStudioModelRenderer[9])();
        }
        this->m_pPlayerInfo->renderframe = this->m_nFrameCount;
        this->m_pPlayerInfo = (player_info_t *)0x0;
        if ((flags & 2U) != 0) {
          if (this->_vptr_CStudioModelRenderer[8] == StudioCalcAttachments) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: 19mstudioattachment_t * pattachment@[???] */
            p1Var21 = this->m_pStudioHeader;
            if (4 < p1Var21->numattachments) goto LAB_0008199c;
            if (0 < p1Var21->numattachments) {
              iVar19 = 0;
              pvVar28 = (vec_t *)(p1Var21->name + p1Var21->attachmentindex + 0x20);
              do {
                iVar18 = iVar19 + 1;
                VectorTransform(pvVar28,(*this->m_plighttransform)[(int)pvVar28[-1]],
                                &this->m_pCurrentEntity->attachment[iVar19].x);
                iVar19 = iVar18;
                pvVar28 = pvVar28 + 0x16;
              } while (iVar18 < this->m_pStudioHeader->numattachments);
            }
          }
          else {
            (*this->_vptr_CStudioModelRenderer[8])(this);
          }
          (*IEngineStudio.StudioClientEvents)();
          iVar19 = this->m_pCurrentEntity->index;
          if (0 < iVar19) {
                    /* Unresolved local var: cl_entity_t.conflict * ent@[???] */
            uVar25 = 0x30;
            pcVar17 = (*gEngfuncs.GetEntityByIndex)(iVar19);
            pcVar31 = this->m_pCurrentEntity;
            pVVar26 = pcVar31->attachment;
            pVVar32 = pcVar17->attachment;
            bVar38 = ((uint)pVVar32 & 1) != 0;
            if (bVar38) {
              pVVar26 = (Vector *)((int)&pcVar31->attachment[0].x + 1);
              uVar25 = 0x2f;
              *(undefined1 *)&pcVar17->attachment[0].x = *(undefined1 *)&pcVar31->attachment[0].x;
              pVVar32 = (Vector *)((int)&pcVar17->attachment[0].x + 1);
            }
            pVVar33 = pVVar32;
            if (((uint)pVVar32 & 2) != 0) {
              pvVar28 = &pVVar26->x;
              pVVar33 = (Vector *)((int)&pVVar32->x + 2);
              pVVar26 = (Vector *)((int)&pVVar26->x + 2);
              uVar25 = uVar25 - 2;
              *(undefined2 *)&pVVar32->x = *(undefined2 *)pvVar28;
            }
            uVar16 = 0;
            do {
              uVar24 = uVar16;
              *(undefined4 *)((int)&pVVar33->x + uVar24) =
                   *(undefined4 *)((int)&pVVar26->x + uVar24);
              uVar16 = uVar24 + 4;
            } while (uVar24 + 4 < (uVar25 & 0xfffffffc));
            puVar34 = (undefined2 *)((int)&pVVar33->y + uVar24);
            puVar27 = (undefined2 *)((int)&pVVar26->y + uVar24);
            iVar19 = 0;
            if ((uVar25 & 2) != 0) {
              *puVar34 = *puVar27;
              iVar19 = 2;
            }
            if (bVar38) {
              *(undefined1 *)((int)puVar34 + iVar19) = *(undefined1 *)((int)puVar27 + iVar19);
            }
          }
        }
        if ((flags & 1U) != 0) {
          if (this->m_pCvarHiModels->value == 0.0) {
LAB_0007fdd1:
            if (this->m_pCvarDeveloper->value == 0.0) {
LAB_00081650:
              iVar19 = (*gEngfuncs.GetMaxClients)();
              if (iVar19 != 1) goto LAB_0007fde7;
              pcVar17 = (cl_entity_s *)this->m_pCurrentEntity;
            }
            else {
LAB_0007fde7:
              pcVar17 = (cl_entity_s *)this->m_pCurrentEntity;
              if (this->m_pRenderModel == pcVar17->model) goto LAB_000813c8;
            }
          }
          else {
            pcVar17 = (cl_entity_s *)this->m_pCurrentEntity;
            if (this->m_pRenderModel != pcVar17->model) {
              (pcVar17->curstate).body = 0xff;
              goto LAB_0007fdd1;
            }
            if (this->m_pCvarDeveloper->value == 0.0) goto LAB_00081650;
LAB_000813c8:
            (pcVar17->curstate).body = 1;
            pcVar17 = (cl_entity_s *)this->m_pCurrentEntity;
          }
          local_bf4.plightvec = local_c00;
          (*IEngineStudio.StudioDynamicLight)(pcVar17,&local_bf4);
          (*IEngineStudio.StudioEntityLight)(&local_bf4);
          (*IEngineStudio.StudioSetupLighting)(&local_bf4);
          ppVar22 = (*IEngineStudio.PlayerInfo)(this->m_nPlayerIndex);
          pcVar15 = tfc_newmodels;
          this->m_pPlayerInfo = ppVar22;
          iVar19 = ppVar22->topcolor;
          this->m_nTopColor = iVar19;
          iVar18 = ppVar22->bottomcolor;
          this->m_nBottomColor = iVar18;
          if (pcVar15->value == 0.0) {
            if (iVar19 - 0x88U < 0x13) {
              this->m_nTopColor = 0x96;
              iVar19 = 0x96;
              this->m_nBottomColor = 0x8c;
            }
            else if ((iVar19 < 0x104) && ((0xf0 < iVar19 || (iVar19 == 5)))) {
              this->m_nTopColor = 0xfa;
              iVar19 = 0xfa;
              this->m_nBottomColor = 0xf0;
            }
            else if (iVar19 - 0x29U < 9) {
              this->m_nTopColor = 0x2d;
              iVar19 = 0x2d;
              this->m_nBottomColor = 0x23;
            }
            else {
              if (0x21 < iVar19 - 0x4cU) goto LAB_000813a0;
              this->m_nTopColor = 100;
              iVar19 = 100;
              this->m_nBottomColor = 0x5a;
            }
LAB_0007fe84:
            iVar18 = this->m_nBottomColor;
          }
          else {
LAB_000813a0:
            if (iVar19 < 0) {
              this->m_nTopColor = 0;
              iVar19 = 0;
            }
            else {
              if (iVar19 < 0x169) goto LAB_0007fe84;
              this->m_nTopColor = 0x168;
              iVar18 = this->m_nBottomColor;
              iVar19 = 0x168;
            }
          }
          if (iVar18 < 0) {
            this->m_nBottomColor = 0;
            iVar18 = 0;
          }
          else if (0x168 < iVar18) {
            this->m_nBottomColor = 0x168;
            iVar18 = 0x168;
          }
          (*IEngineStudio.StudioSetRemapColors)(iVar19,iVar18);
          (*this->_vptr_CStudioModelRenderer[0x13])(this);
          this->m_pPlayerInfo = (player_info_t *)0x0;
          iVar19 = pplayer->weaponmodel;
          if (iVar19 != 0) {
                    /* Unresolved local var: cl_entity_t.conflict saveent@[???]
                       Unresolved local var: model_t * pweaponmodel@[???] */
            pcVar31 = this->m_pCurrentEntity;
            local_bc8 = (pcVar31->baseline).messagenum;
            local_bdc = pcVar31->index;
            qStack_bd8 = pcVar31->player;
            iStack_bd4 = (pcVar31->baseline).entityType;
            iStack_bd0 = (pcVar31->baseline).number;
            local_bcc = (pcVar31->baseline).msg_time;
            local_bb8 = (pcVar31->baseline).angles.x;
            local_bb4 = (pcVar31->baseline).angles.y;
            local_bac = (pcVar31->baseline).modelindex;
            local_bc4 = (pcVar31->baseline).origin.x;
            local_bb0 = (pcVar31->baseline).angles.z;
            local_ba8 = (pcVar31->baseline).sequence;
            local_bc0 = (pcVar31->baseline).origin.y;
            local_ba4 = (pcVar31->baseline).frame;
            local_ba0 = (pcVar31->baseline).colormap;
            local_bbc = (pcVar31->baseline).origin.z;
            uVar10 = (pcVar31->baseline).skin;
            local_b9a = (pcVar31->baseline).solid;
            local_b98 = (pcVar31->baseline).effects;
            local_b90 = (pcVar31->baseline).eflags;
            local_b78 = (pcVar31->baseline).animtime;
            local_b74 = (pcVar31->baseline).framerate;
            local_b64 = (pcVar31->baseline).velocity.x;
            local_b8c = (pcVar31->baseline).rendermode;
            local_b60 = (pcVar31->baseline).velocity.y;
            local_b5c = (pcVar31->baseline).velocity.z;
            local_b94 = (pcVar31->baseline).scale;
            local_b88 = (pcVar31->baseline).renderamt;
            local_b84 = (undefined2)*(undefined4 *)&(pcVar31->baseline).rendercolor;
            local_b82 = (pcVar31->baseline).rendercolor.b;
            local_b80 = (pcVar31->baseline).renderfx;
            local_b7c = (pcVar31->baseline).movetype;
            local_b70 = (pcVar31->baseline).body;
            local_b6c = *(undefined4 *)(pcVar31->baseline).controller;
            local_b68 = *(undefined4 *)(pcVar31->baseline).blending;
            local_b58 = (pcVar31->baseline).mins.x;
            local_b40 = (pcVar31->baseline).aiment;
            local_b54 = (pcVar31->baseline).mins.y;
            local_b4c = (pcVar31->baseline).maxs.x;
            local_b48 = (pcVar31->baseline).maxs.y;
            local_b3c = (pcVar31->baseline).owner;
            local_b44 = (pcVar31->baseline).maxs.z;
            local_b30 = (pcVar31->baseline).team;
            local_b38 = (pcVar31->baseline).friction;
            local_b34 = (pcVar31->baseline).gravity;
            local_b50 = (pcVar31->baseline).mins.z;
            local_b2c = (pcVar31->baseline).playerclass;
            local_b28 = (pcVar31->baseline).health;
            local_b24 = (pcVar31->baseline).spectator;
            local_b20 = (pcVar31->baseline).weaponmodel;
            local_b1c = (pcVar31->baseline).gaitsequence;
            local_b18 = (pcVar31->baseline).basevelocity.x;
            local_b0c = (pcVar31->baseline).usehull;
            local_b14 = (pcVar31->baseline).basevelocity.y;
            local_b10 = (pcVar31->baseline).basevelocity.z;
            local_afc = (pcVar31->baseline).flFallVelocity;
            local_b08 = (pcVar31->baseline).oldbuttons;
            local_af8 = (pcVar31->baseline).fov;
            local_b04 = (pcVar31->baseline).onground;
            local_aec = (pcVar31->baseline).startpos.y;
            local_ae8 = (pcVar31->baseline).startpos.z;
            local_b00 = (pcVar31->baseline).iStepLeft;
            local_ae4 = (pcVar31->baseline).endpos.x;
            local_af4 = (pcVar31->baseline).weaponanim;
            local_ae0 = (pcVar31->baseline).endpos.y;
            local_adc = (pcVar31->baseline).endpos.z;
            local_af0 = (pcVar31->baseline).startpos.x;
            local_ad8 = (pcVar31->baseline).impacttime;
            local_ad0 = (pcVar31->baseline).iuser1;
            local_ad4 = (pcVar31->baseline).starttime;
            local_ac0 = (pcVar31->baseline).fuser1;
            local_abc = (pcVar31->baseline).fuser2;
            local_acc = (pcVar31->baseline).iuser2;
            local_ab8 = (pcVar31->baseline).fuser3;
            local_ab4 = (pcVar31->baseline).fuser4;
            local_ac8 = (pcVar31->baseline).iuser3;
            local_aac = (pcVar31->baseline).vuser1.y;
            local_ac4 = (pcVar31->baseline).iuser4;
            local_aa8 = (pcVar31->baseline).vuser1.z;
            local_aa4 = (pcVar31->baseline).vuser2.x;
            local_aa0 = (pcVar31->baseline).vuser2.y;
            local_ab0 = (pcVar31->baseline).vuser1.x;
            local_a9c = (pcVar31->baseline).vuser2.z;
            local_a98 = (pcVar31->baseline).vuser3.x;
            local_a80 = (pcVar31->prevstate).entityType;
            local_a94 = (pcVar31->baseline).vuser3.y;
            local_a90 = (pcVar31->baseline).vuser3.z;
            local_a8c = (pcVar31->baseline).vuser4.x;
            local_a7c = (pcVar31->prevstate).number;
            local_a88 = (pcVar31->baseline).vuser4.y;
            local_a84 = (pcVar31->baseline).vuser4.z;
            local_a78 = (pcVar31->prevstate).msg_time;
            local_a74 = (pcVar31->prevstate).messagenum;
            local_a70 = (pcVar31->prevstate).origin.x;
            local_a6c = (pcVar31->prevstate).origin.y;
            local_a68 = (pcVar31->prevstate).origin.z;
            local_a64 = (pcVar31->prevstate).angles.x;
            local_a60 = (pcVar31->prevstate).angles.y;
            local_a5c = (pcVar31->prevstate).angles.z;
            local_a58 = (pcVar31->prevstate).modelindex;
            local_a50 = (pcVar31->prevstate).frame;
            local_a40 = (pcVar31->prevstate).scale;
            local_a24 = (pcVar31->prevstate).animtime;
            local_a54 = (pcVar31->prevstate).sequence;
            local_a4c = (pcVar31->prevstate).colormap;
            uVar11 = (pcVar31->prevstate).skin;
            local_a46 = (pcVar31->prevstate).solid;
            local_a44 = (pcVar31->prevstate).effects;
            local_a3c = (pcVar31->prevstate).eflags;
            local_a38 = (pcVar31->prevstate).rendermode;
            local_a34 = (pcVar31->prevstate).renderamt;
            local_a30 = (undefined2)*(undefined4 *)&(pcVar31->prevstate).rendercolor;
            local_a2e = (pcVar31->prevstate).rendercolor.b;
            local_a2c = (pcVar31->prevstate).renderfx;
            local_a28 = (pcVar31->prevstate).movetype;
            local_a20 = (pcVar31->prevstate).framerate;
            local_a1c = (pcVar31->prevstate).body;
            local_a10 = (pcVar31->prevstate).velocity.x;
            local_a0c = (pcVar31->prevstate).velocity.y;
            local_a04 = (pcVar31->prevstate).mins.x;
            local_a18 = *(undefined4 *)(pcVar31->prevstate).controller;
            local_a00 = (pcVar31->prevstate).mins.y;
            local_9fc = (pcVar31->prevstate).mins.z;
            local_9f8 = (pcVar31->prevstate).maxs.x;
            local_a14 = *(undefined4 *)(pcVar31->prevstate).blending;
            local_9f4 = (pcVar31->prevstate).maxs.y;
            local_9ec = (pcVar31->prevstate).aiment;
            local_9f0 = (pcVar31->prevstate).maxs.z;
            local_a08 = (pcVar31->prevstate).velocity.z;
            local_9e8 = (pcVar31->prevstate).owner;
            local_9e4 = (pcVar31->prevstate).friction;
            local_9e0 = (pcVar31->prevstate).gravity;
            local_9dc = (pcVar31->prevstate).team;
            local_9c4 = (pcVar31->prevstate).basevelocity.x;
            local_9c0 = (pcVar31->prevstate).basevelocity.y;
            local_9bc = (pcVar31->prevstate).basevelocity.z;
            local_9d8 = (pcVar31->prevstate).playerclass;
            local_9a8 = (pcVar31->prevstate).flFallVelocity;
            local_9a4 = (pcVar31->prevstate).fov;
            local_9d4 = (pcVar31->prevstate).health;
            local_9d0 = (pcVar31->prevstate).spectator;
            local_9cc = (pcVar31->prevstate).weaponmodel;
            local_9c8 = (pcVar31->prevstate).gaitsequence;
            local_9b8 = (pcVar31->prevstate).usehull;
            local_9b4 = (pcVar31->prevstate).oldbuttons;
            local_9b0 = (pcVar31->prevstate).onground;
            local_9ac = (pcVar31->prevstate).iStepLeft;
            local_9a0 = (pcVar31->prevstate).weaponanim;
            local_99c = (pcVar31->prevstate).startpos.x;
            local_998 = (pcVar31->prevstate).startpos.y;
            local_994 = (pcVar31->prevstate).startpos.z;
            local_97c = (pcVar31->prevstate).iuser1;
            local_98c = (pcVar31->prevstate).endpos.y;
            local_988 = (pcVar31->prevstate).endpos.z;
            local_984 = (pcVar31->prevstate).impacttime;
            local_978 = (pcVar31->prevstate).iuser2;
            local_980 = (pcVar31->prevstate).starttime;
            local_974 = (pcVar31->prevstate).iuser3;
            local_96c = (pcVar31->prevstate).fuser1;
            local_968 = (pcVar31->prevstate).fuser2;
            local_970 = (pcVar31->prevstate).iuser4;
            local_964 = (pcVar31->prevstate).fuser3;
            local_990 = (pcVar31->prevstate).endpos.x;
            local_960 = (pcVar31->prevstate).fuser4;
            local_92c = (pcVar31->curstate).entityType;
            local_95c = (pcVar31->prevstate).vuser1.x;
            local_958 = (pcVar31->prevstate).vuser1.y;
            local_954 = (pcVar31->prevstate).vuser1.z;
            local_950 = (pcVar31->prevstate).vuser2.x;
            local_94c = (pcVar31->prevstate).vuser2.y;
            local_928 = (pcVar31->curstate).number;
            local_948 = (pcVar31->prevstate).vuser2.z;
            local_944 = (pcVar31->prevstate).vuser3.x;
            local_940 = (pcVar31->prevstate).vuser3.y;
            local_93c = (pcVar31->prevstate).vuser3.z;
            local_938 = (pcVar31->prevstate).vuser4.x;
            local_934 = (pcVar31->prevstate).vuser4.y;
            local_930 = (pcVar31->prevstate).vuser4.z;
            local_924 = (pcVar31->curstate).msg_time;
            local_920 = (pcVar31->curstate).messagenum;
            local_91c = (pcVar31->curstate).origin.x;
            local_918 = (pcVar31->curstate).origin.y;
            local_914 = (pcVar31->curstate).origin.z;
            local_904 = (pcVar31->curstate).modelindex;
            local_910 = (pcVar31->curstate).angles.x;
            local_90c = (pcVar31->curstate).angles.y;
            local_908 = (pcVar31->curstate).angles.z;
            local_900 = (pcVar31->curstate).sequence;
            local_8fc = (pcVar31->curstate).frame;
            local_8ec = (pcVar31->curstate).scale;
            local_8f8 = (pcVar31->curstate).colormap;
            uVar12 = (pcVar31->curstate).skin;
            local_8f2 = (pcVar31->curstate).solid;
            local_8f0 = (pcVar31->curstate).effects;
            local_8e8 = (pcVar31->curstate).eflags;
            local_8e4 = (pcVar31->curstate).rendermode;
            local_8d0 = (pcVar31->curstate).animtime;
            local_8cc = (pcVar31->curstate).framerate;
            local_8bc = (pcVar31->curstate).velocity.x;
            local_8e0 = (pcVar31->curstate).renderamt;
            local_8b8 = (pcVar31->curstate).velocity.y;
            local_8b4 = (pcVar31->curstate).velocity.z;
            local_8b0 = (pcVar31->curstate).mins.x;
            local_8ac = (pcVar31->curstate).mins.y;
            local_8dc = (undefined2)*(undefined4 *)&(pcVar31->curstate).rendercolor;
            local_8da = (pcVar31->curstate).rendercolor.b;
            local_8d8 = (pcVar31->curstate).renderfx;
            local_8d4 = (pcVar31->curstate).movetype;
            local_8c8 = (pcVar31->curstate).body;
            local_8c4 = *(undefined4 *)(pcVar31->curstate).controller;
            local_8c0 = *(undefined4 *)(pcVar31->curstate).blending;
            local_8a8 = (pcVar31->curstate).mins.z;
            local_898 = (pcVar31->curstate).aiment;
            local_8a4 = (pcVar31->curstate).maxs.x;
            local_8a0 = (pcVar31->curstate).maxs.y;
            local_89c = (pcVar31->curstate).maxs.z;
            local_894 = (pcVar31->curstate).owner;
            local_890 = (pcVar31->curstate).friction;
            local_88c = (pcVar31->curstate).gravity;
            local_870 = (pcVar31->curstate).basevelocity.x;
            local_888 = (pcVar31->curstate).team;
            local_86c = (pcVar31->curstate).basevelocity.y;
            local_884 = (pcVar31->curstate).playerclass;
            local_880 = (pcVar31->curstate).health;
            local_87c = (pcVar31->curstate).spectator;
            local_878 = (pcVar31->curstate).weaponmodel;
            local_874 = (pcVar31->curstate).gaitsequence;
            local_868 = (pcVar31->curstate).basevelocity.z;
            local_864 = (pcVar31->curstate).usehull;
            local_854 = (pcVar31->curstate).flFallVelocity;
            local_850 = (pcVar31->curstate).fov;
            local_848 = (pcVar31->curstate).startpos.x;
            local_860 = (pcVar31->curstate).oldbuttons;
            local_844 = (pcVar31->curstate).startpos.y;
            local_840 = (pcVar31->curstate).startpos.z;
            local_83c = (pcVar31->curstate).endpos.x;
            local_85c = (pcVar31->curstate).onground;
            local_838 = (pcVar31->curstate).endpos.y;
            local_858 = (pcVar31->curstate).iStepLeft;
            local_834 = (pcVar31->curstate).endpos.z;
            local_830 = (pcVar31->curstate).impacttime;
            local_84c = (pcVar31->curstate).weaponanim;
            local_82c = (pcVar31->curstate).starttime;
            local_828 = (pcVar31->curstate).iuser1;
            local_818 = (pcVar31->curstate).fuser1;
            local_814 = (pcVar31->curstate).fuser2;
            local_810 = (pcVar31->curstate).fuser3;
            local_824 = (pcVar31->curstate).iuser2;
            local_80c = (pcVar31->curstate).fuser4;
            local_804 = (pcVar31->curstate).vuser1.y;
            local_800 = (pcVar31->curstate).vuser1.z;
            local_820 = (pcVar31->curstate).iuser3;
            local_7fc = (pcVar31->curstate).vuser2.x;
            local_81c = (pcVar31->curstate).iuser4;
            local_808 = (pcVar31->curstate).vuser1.x;
            local_7f8 = (pcVar31->curstate).vuser2.y;
            local_7f4 = (pcVar31->curstate).vuser2.z;
            local_7f0 = (pcVar31->curstate).vuser3.x;
            local_7ec = (pcVar31->curstate).vuser3.y;
            local_7e8 = (pcVar31->curstate).vuser3.z;
            local_7e4 = (pcVar31->curstate).vuser4.x;
            local_7e0 = (pcVar31->curstate).vuser4.y;
            local_7dc = (pcVar31->curstate).vuser4.z;
            local_7d8 = pcVar31->current_position;
            pfVar29 = local_7d4;
            ppVar36 = pcVar31->ph;
            do {
              pfVar30 = pfVar29 + 7;
              fVar4 = (ppVar36->origin).x;
              fVar5 = (ppVar36->origin).y;
              fVar6 = (ppVar36->origin).z;
              fVar7 = (ppVar36->angles).x;
              fVar8 = (ppVar36->angles).y;
              fVar9 = (ppVar36->angles).z;
              *pfVar29 = ppVar36->animtime;
              pfVar29[1] = fVar4;
              pfVar29[2] = fVar5;
              pfVar29[3] = fVar6;
              pfVar29[4] = fVar7;
              pfVar29[5] = fVar8;
              pfVar29[6] = fVar9;
              pfVar29 = pfVar30;
              ppVar36 = ppVar36 + 1;
            } while (pfVar30 != &local_d4);
            uVar13._0_1_ = (pcVar31->latched).prevseqblending[0];
            uVar13._1_1_ = (pcVar31->latched).prevseqblending[1];
            uVar13._2_2_ = *(undefined2 *)&(pcVar31->latched).field_0xa;
            local_cc = (pcVar31->latched).prevanimtime;
            local_c8 = (pcVar31->latched).sequencetime;
            local_d0 = (pcVar31->mouth).sndavg;
            local_c4 = (undefined2)uVar13;
            local_a8 = (pcVar31->latched).prevsequence;
            local_d4 = *(float *)&pcVar31->mouth;
            local_bc = (pcVar31->latched).prevorigin.y;
            local_b8 = (pcVar31->latched).prevorigin.z;
            local_a0 = *(undefined4 *)(pcVar31->latched).prevcontroller;
            local_b4 = (pcVar31->latched).prevangles.x;
            local_b0 = (pcVar31->latched).prevangles.y;
            local_ac = (pcVar31->latched).prevangles.z;
            uVar14._0_1_ = (pcVar31->latched).prevblending[0];
            uVar14._1_1_ = (pcVar31->latched).prevblending[1];
            uVar14._2_2_ = *(undefined2 *)&(pcVar31->latched).field_0x32;
            local_c0 = (pcVar31->latched).prevorigin.x;
            local_a4 = (pcVar31->latched).prevframe;
            local_98 = pcVar31->lastmove;
            local_9c = (undefined2)uVar14;
            local_94 = (pcVar31->origin).x;
            local_6c = pcVar31->attachment[1].y;
            vStack_68 = pcVar31->attachment[1].z;
            vStack_64 = pcVar31->attachment[2].x;
            vStack_60 = pcVar31->attachment[2].y;
            local_4c = pcVar31->trivial_accept;
            local_7c = pcVar31->attachment[0].x;
            vStack_78 = pcVar31->attachment[0].y;
            vStack_74 = pcVar31->attachment[0].z;
            vStack_70 = pcVar31->attachment[1].x;
            local_90 = (pcVar31->origin).y;
            local_8c = (pcVar31->origin).z;
            local_88 = (pcVar31->angles).x;
            local_48 = pcVar31->model;
            local_84 = (pcVar31->angles).y;
            local_80 = (pcVar31->angles).z;
            local_3c = pcVar31->syncbase;
            local_44 = pcVar31->efrag;
            local_40 = pcVar31->topnode;
            local_5c = *(undefined8 *)&pcVar31->attachment[2].z;
            local_38 = pcVar31->visframe;
            uStack_54._0_4_ = pcVar31->attachment[3].y;
            uStack_54._4_4_ = pcVar31->attachment[3].z;
            local_34 = (pcVar31->cvFloorColor).r;
            local_30 = (pcVar31->cvFloorColor).g;
            local_2c = (pcVar31->cvFloorColor).b;
            local_28 = (pcVar31->cvFloorColor).a;
            local_b9c = uVar10;
            local_a48 = uVar11;
            local_8f4 = uVar12;
            pmVar20 = (*IEngineStudio.GetModelByIndex)(iVar19);
            if ((pmVar20 != (model_s *)0x0) && (tfc_newmodels->value == 0.0)) {
              iVar19 = 0;
              do {
                    /* Unresolved local var: int i@[???] */
                iVar18 = strcasecmp(pmVar20->name,sNewWeaponPModels[iVar19]);
                if (iVar18 == 0) {
                  (*gEngfuncs.CL_LoadModel)(sOldWeaponPModels[iVar19],&local_c04);
                  pmVar20 = (*IEngineStudio.GetModelByIndex)(local_c04);
                  break;
                }
                iVar19 = iVar19 + 1;
              } while (iVar19 != 0x12);
            }
            p1Var21 = (*IEngineStudio.Mod_Extradata)(pmVar20);
            this->m_pStudioHeader = p1Var21;
            (*IEngineStudio.StudioSetHeader)(p1Var21);
            pcVar23 = strstr(this->m_pStudioHeader->name,"p_mini.mdl");
            iVar19 = this->m_nPlayerIndex;
            if (pcVar23 == (char *)0x0) {
              if ((g_flSpinUpTime[iVar19] != 0.0) || (g_flSpinDownTime[iVar19] != 0.0)) {
                g_flSpinUpTime[iVar19] = 0.0;
                g_flSpinDownTime[this->m_nPlayerIndex] = 0.0;
              }
            }
            else {
              fVar4 = g_flSpinUpTime[iVar19];
              if (fVar4 == 0.0) {
LAB_00081165:
                fVar4 = g_flSpinDownTime[iVar19];
                if (fVar4 != 0.0) {
                  (*gEngfuncs.GetClientTime)();
                  iVar19 = this->m_nPlayerIndex;
                  if (((longdouble)fVar4 <= extraout_ST0_02) || (g_flSpinUpTime[iVar19] != 0.0)) {
                    fVar4 = g_flSpinDownTime[iVar19];
                    if ((fVar4 != 0.0) &&
                       (((*gEngfuncs.GetClientTime)(), (longdouble)fVar4 <= extraout_ST0_03 &&
                        (g_flSpinUpTime[this->m_nPlayerIndex] == 0.0)))) {
                      g_flSpinDownTime[this->m_nPlayerIndex] = 0.0;
                    }
                  }
                  else {
                    /* Unresolved local var: float flmod@[???] */
                    fVar4 = g_flSpinDownTime[iVar19];
                    (*gEngfuncs.GetClientTime)();
                    (this->m_pCurrentEntity->curstate).frame =
                         (float)((longdouble)fVar4 - (extraout_ST0_04 + (longdouble)3.5)) * -30.0;
                    (this->m_pCurrentEntity->curstate).sequence = 3;
                  }
                }
              }
              else {
                (*gEngfuncs.GetClientTime)();
                if ((longdouble)fVar4 <= extraout_ST0) {
                  iVar19 = this->m_nPlayerIndex;
                  fVar4 = g_flSpinUpTime[iVar19];
                  if (fVar4 != 0.0) {
                    (*gEngfuncs.GetClientTime)();
                    iVar19 = this->m_nPlayerIndex;
                    if ((longdouble)fVar4 <= extraout_ST0_00) {
                      g_flSpinUpTime[iVar19] = 0.0;
                      goto LAB_000811a0;
                    }
                  }
                  goto LAB_00081165;
                }
                    /* Unresolved local var: float flmod@[???] */
                fVar4 = g_flSpinUpTime[this->m_nPlayerIndex];
                (*gEngfuncs.GetClientTime)();
                (this->m_pCurrentEntity->curstate).frame =
                     (float)((longdouble)fVar4 - (extraout_ST0_01 + (longdouble)3.5)) * -30.0;
                (this->m_pCurrentEntity->curstate).sequence = 2;
              }
LAB_000811a0:
              pcVar31 = this->m_pCurrentEntity;
              if (((pcVar31->curstate).sequence - 0x46U & 0xfffffffd) == 0) {
                if (g_flSpinUpTime[this->m_nPlayerIndex] != 0.0) {
                  g_flSpinUpTime[this->m_nPlayerIndex] = 0.0;
                  pcVar31 = this->m_pCurrentEntity;
                }
                (pcVar31->curstate).sequence = 1;
              }
              (*this->_vptr_CStudioModelRenderer[7])(this);
            }
            (*this->_vptr_CStudioModelRenderer[10])(this);
            (*IEngineStudio.StudioSetupLighting)(&local_bf4);
            this_00 = this;
            (*this->_vptr_CStudioModelRenderer[0x13])();
            if (this->_vptr_CStudioModelRenderer[8] == StudioCalcAttachments) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: 19mstudioattachment_t * pattachment@[???] */
              p1Var21 = this->m_pStudioHeader;
              if (4 < p1Var21->numattachments) {
LAB_0008199c:
                StudioCalcAttachments(this_00);
                pmVar20[0x2a].type = mod_brush;
                pmVar20[0x2a].numframes = 0;
                pmVar20[0x2a].synctype = ST_SYNC;
                pmVar20[0x2a].flags = 0;
                *(undefined ***)pmVar20->name = &PTR__CStudioModelRenderer_000c354c;
                *(undefined4 *)((int)pmVar20->name + 0x14) = 1;
                *(undefined4 *)((int)pmVar20->name + 0x18) = 1;
                *(undefined4 *)((int)pmVar20->name + 0x2c) = 0;
                *(undefined4 *)((int)pmVar20->name + 0x20) = 0;
                *(undefined4 *)((int)pmVar20->name + 0x24) = 0;
                *(undefined4 *)((int)pmVar20->name + 0x28) = 0;
                (pmVar20->mins).x = 0.0;
                pmVar20[0x2a].mins.x = 0.0;
                pmVar20[0x2a].mins.y = 0.0;
                pmVar20->needload = 0;
                pmVar20->type = mod_brush;
                pmVar20->numframes = 0;
                *(undefined4 *)((int)pmVar20->name + 0x34) = 0;
                *(undefined4 *)((int)pmVar20->name + 0x30) = 0;
                return (int)pmVar20;
              }
              if (0 < p1Var21->numattachments) {
                iVar19 = 0;
                pvVar28 = (vec_t *)(p1Var21->name + p1Var21->attachmentindex + 0x20);
                do {
                  iVar18 = iVar19 + 1;
                  VectorTransform(pvVar28,(*this->m_plighttransform)[(int)pvVar28[-1]],
                                  &this->m_pCurrentEntity->attachment[iVar19].x);
                  iVar19 = iVar18;
                  pvVar28 = pvVar28 + 0x16;
                } while (iVar18 < this->m_pStudioHeader->numattachments);
              }
            }
            else {
              (*this->_vptr_CStudioModelRenderer[8])(this);
            }
            pcVar31 = this->m_pCurrentEntity;
            piVar35 = &local_bdc;
            uVar25 = 3000;
            pcVar37 = pcVar31;
            if (((uint)pcVar31 & 4) != 0) {
              pcVar37 = (cl_entity_t_conflict *)&pcVar31->player;
              uVar25 = 0xbb4;
              piVar35 = &qStack_bd8;
              pcVar31->index = local_bdc;
            }
            for (uVar25 = uVar25 >> 2; uVar25 != 0; uVar25 = uVar25 - 1) {
              pcVar37->index = *piVar35;
              piVar35 = piVar35 + (uint)bVar39 * -2 + 1;
              pcVar37 = (cl_entity_t_conflict *)((int)pcVar37 + (uint)bVar39 * -8 + 4);
            }
          }
        }
LAB_0008129a:
        iVar19 = 1;
        goto LAB_0007fb43;
      }
      iVar19 = (*IEngineStudio.StudioCheckBBox)();
      if (iVar19 != 0) {
        *this->m_pModelsDrawn = *this->m_pModelsDrawn + 1;
        *this->m_pStudioModelCount = *this->m_pStudioModelCount + 1;
        if (this->m_pStudioHeader->numbodyparts != 0) goto LAB_0007fcbd;
        goto LAB_0008129a;
      }
    }
  }
  iVar19 = 0;
LAB_0007fb43:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar19;
}


// CStudioModelRenderer::StudioCalcAttachments  @ 00047580  (line 1944)

/* DWARF original prototype: void StudioCalcAttachments(CStudioModelRenderer * this) */

void __thiscall CStudioModelRenderer::StudioCalcAttachments(CStudioModelRenderer *this)

{
  int in_EAX;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: 19mstudioattachment_t * pattachment@[???] */
  (*gEngfuncs.Con_DPrintf)
            ("Too many attachments on %s\n",*(undefined4 *)(*(int *)(in_EAX + 0x2c) + 0xb94));
                    /* WARNING: Subroutine does not return */
  exit(-1);
}


// CStudioModelRenderer::StudioCalcAttachments  @ 0007d920  (line 1945)

/* DWARF original prototype: void StudioCalcAttachments(CStudioModelRenderer * this) */

void __thiscall CStudioModelRenderer::StudioCalcAttachments(CStudioModelRenderer *this)

{
  _1studiohdr_t *p1Var1;
  int iVar2;
  int iVar3;
  vec_t *in1;
  CStudioModelRenderer *in_stack_ffffffe4;
  int *in_stack_ffffffe8;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: 19mstudioattachment_t * pattachment@[???] */
  p1Var1 = this->m_pStudioHeader;
  if (p1Var1->numattachments < 5) {
    iVar2 = 0;
    in1 = (vec_t *)(p1Var1->name + p1Var1->attachmentindex + 0x20);
    if (0 < p1Var1->numattachments) {
      do {
        iVar3 = iVar2 + 1;
        VectorTransform(in1,(*this->m_plighttransform)[(int)in1[-1]],
                        &this->m_pCurrentEntity->attachment[iVar2].x);
        iVar2 = iVar3;
        in1 = in1 + 0x16;
      } while (iVar3 < this->m_pStudioHeader->numattachments);
    }
    return;
  }
  StudioCalcAttachments(in_stack_ffffffe4);
  iVar2 = (*IEngineStudio.IsHardware)();
  if (iVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0007d9cf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*in_stack_ffffffe8 + 0x58))(in_stack_ffffffe8);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0007d9bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_stack_ffffffe8 + 0x54))();
  return;
}


// CStudioModelRenderer::StudioRenderModel  @ 0007f250  (line 1970)

/* DWARF original prototype: void StudioRenderModel(CStudioModelRenderer * this) */

void __thiscall CStudioModelRenderer::StudioRenderModel(CStudioModelRenderer *this)

{
  int iVar1;
  
  (*IEngineStudio.SetChromeOrigin)();
  (*IEngineStudio.SetForceFaceFlags)(0);
  if ((this->m_pCurrentEntity->curstate).renderfx == 0x13) {
    (this->m_pCurrentEntity->curstate).renderfx = 0;
    if (this->_vptr_CStudioModelRenderer[0x14] == StudioRenderFinal) {
      iVar1 = (*IEngineStudio.IsHardware)();
      if (iVar1 == 0) {
        (*this->_vptr_CStudioModelRenderer[0x15])();
      }
      else {
        (*this->_vptr_CStudioModelRenderer[0x16])(this);
      }
    }
    else {
      (*this->_vptr_CStudioModelRenderer[0x14])(this);
    }
    iVar1 = (*IEngineStudio.IsHardware)();
    if (iVar1 == 0) {
      (*(gEngfuncs.pTriAPI)->RenderMode)(5);
    }
    (*IEngineStudio.SetForceFaceFlags)(2);
    (*(gEngfuncs.pTriAPI)->SpriteTexture)(this->m_pChromeSprite,0);
    (this->m_pCurrentEntity->curstate).renderfx = 0x13;
    if (this->_vptr_CStudioModelRenderer[0x14] == StudioRenderFinal) {
      iVar1 = (*IEngineStudio.IsHardware)();
      if (iVar1 == 0) {
        (*this->_vptr_CStudioModelRenderer[0x15])();
      }
      else {
        (*this->_vptr_CStudioModelRenderer[0x16])(this);
      }
    }
    else {
      (*this->_vptr_CStudioModelRenderer[0x14])(this);
    }
    iVar1 = (*IEngineStudio.IsHardware)();
    if (iVar1 != 0) {
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x0007f382. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(gEngfuncs.pTriAPI)->RenderMode)(0);
    return;
  }
  if (this->_vptr_CStudioModelRenderer[0x14] != StudioRenderFinal) {
                    /* WARNING: Could not recover jumptable at 0x0007f360. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*this->_vptr_CStudioModelRenderer[0x14])();
    return;
  }
  iVar1 = (*IEngineStudio.IsHardware)();
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0007f29e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*this->_vptr_CStudioModelRenderer[0x15])();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0007f2a7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*this->_vptr_CStudioModelRenderer[0x16])();
  return;
}


// CStudioModelRenderer::StudioRenderFinal_Software  @ 0007c970  (line 2008)

/* DWARF original prototype: void StudioRenderFinal_Software(CStudioModelRenderer * this) */

void __thiscall CStudioModelRenderer::StudioRenderFinal_Software(CStudioModelRenderer *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  (*IEngineStudio.SetupRenderer)(0);
  fVar1 = this->m_pCvarDrawEntities->value;
  if (fVar1 == 2.0) {
    (*IEngineStudio.StudioDrawBones)();
    fVar1 = this->m_pCvarDrawEntities->value;
  }
  else if (fVar1 == 3.0) {
    (*IEngineStudio.StudioDrawHulls)();
    fVar1 = this->m_pCvarDrawEntities->value;
  }
  else if (0 < this->m_pStudioHeader->numbodyparts) {
    iVar2 = 0;
    do {
      iVar3 = iVar2 + 1;
      (*IEngineStudio.StudioSetupModel)(iVar2,&this->m_pBodyPart,&this->m_pSubModel);
      (*IEngineStudio.StudioDrawPoints)();
      iVar2 = iVar3;
    } while (iVar3 < this->m_pStudioHeader->numbodyparts);
    fVar1 = this->m_pCvarDrawEntities->value;
  }
  if (fVar1 == 4.0) {
    (*(gEngfuncs.pTriAPI)->RenderMode)(5);
    (*IEngineStudio.StudioDrawHulls)();
    (*(gEngfuncs.pTriAPI)->RenderMode)(0);
    fVar1 = this->m_pCvarDrawEntities->value;
  }
  if (fVar1 == 5.0) {
    (*IEngineStudio.StudioDrawAbsBBox)();
  }
                    /* WARNING: Could not recover jumptable at 0x0007ca26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*IEngineStudio.RestoreRenderer)();
  return;
}


// CStudioModelRenderer::StudioRenderFinal_Hardware  @ 0007ca90  (line 2053)

/* DWARF original prototype: void StudioRenderFinal_Hardware(CStudioModelRenderer * this) */

void __thiscall CStudioModelRenderer::StudioRenderFinal_Hardware(CStudioModelRenderer *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int rendermode@[???] */
  iVar3 = 5;
  iVar2 = (*IEngineStudio.GetForceFaceFlags)();
  if (iVar2 == 0) {
    iVar3 = (this->m_pCurrentEntity->curstate).rendermode;
  }
  (*IEngineStudio.SetupRenderer)(iVar3);
  fVar1 = this->m_pCvarDrawEntities->value;
  if (fVar1 == 2.0) {
    (*IEngineStudio.StudioDrawBones)();
    fVar1 = this->m_pCvarDrawEntities->value;
  }
  else if (fVar1 == 3.0) {
    (*IEngineStudio.StudioDrawHulls)();
    fVar1 = this->m_pCvarDrawEntities->value;
  }
  else if (0 < this->m_pStudioHeader->numbodyparts) {
    iVar2 = 0;
    do {
      (*IEngineStudio.StudioSetupModel)(iVar2,&this->m_pBodyPart,&this->m_pSubModel);
      if (this->m_fDoInterp != 0) {
        this->m_pCurrentEntity->trivial_accept = 0;
      }
      iVar2 = iVar2 + 1;
      (*IEngineStudio.GL_SetRenderMode)(iVar3);
      (*IEngineStudio.StudioDrawPoints)();
      (*IEngineStudio.GL_StudioDrawShadow)();
    } while (iVar2 < this->m_pStudioHeader->numbodyparts);
    fVar1 = this->m_pCvarDrawEntities->value;
  }
  if (fVar1 == 4.0) {
    (*(gEngfuncs.pTriAPI)->RenderMode)(5);
    (*IEngineStudio.StudioDrawHulls)();
    (*(gEngfuncs.pTriAPI)->RenderMode)(0);
  }
                    /* WARNING: Could not recover jumptable at 0x0007cb99. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*IEngineStudio.RestoreRenderer)();
  return;
}


// CStudioModelRenderer::StudioRenderFinal  @ 0007d9a0  (line 2103)

/* DWARF original prototype: void StudioRenderFinal(CStudioModelRenderer * this) */

void __thiscall CStudioModelRenderer::StudioRenderFinal(CStudioModelRenderer *this)

{
  int iVar1;
  
  iVar1 = (*IEngineStudio.IsHardware)();
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0007d9bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*this->_vptr_CStudioModelRenderer[0x15])();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0007d9cf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*this->_vptr_CStudioModelRenderer[0x16])();
  return;
}


