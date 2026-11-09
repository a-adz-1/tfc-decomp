// R_AddDynamicLights  @ 0018fd90
void R_AddDynamicLights(msurface_t *surf)

{
  short sVar1;
  short sVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  mtexinfo_t *pmVar12;
  mplane_t *pmVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  cl_entity_t *pcVar18;
  int iVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  colorVec *pcVar24;
  uint uVar25;
  int iVar26;
  float *pfVar27;
  int local_30;
  colorVec *local_2c;
  int local_28;
  
                    /* Unresolved local var: int lnum@[???]
                       Unresolved local var: int sd@[???]
                       Unresolved local var: int td@[???]
                       Unresolved local var: float dist@[???]
                       Unresolved local var: float rad@[???]
                       Unresolved local var: float minlight@[???]
                       Unresolved local var: vec3_t local@[???]
                       Unresolved local var: vec3_t impact@[???]
                       Unresolved local var: int s@[???]
                       Unresolved local var: int t@[???]
                       Unresolved local var: int smax@[???]
                       Unresolved local var: int tmax@[???]
                       Unresolved local var: mtexinfo_t * tex@[???] */
  pcVar18 = currententity;
  pfVar27 = &cl_dlights[0].radius;
                    /* Unresolved local var: int32 delta@[???] */
  iVar19 = ((int)surf->extents[0] >> 4) + 1;
  iVar20 = (int)surf->extents[1] >> 4;
  pmVar12 = surf->texinfo;
  local_28 = 0;
  do {
    if ((surf->dlightbits >> ((byte)local_28 & 0x1f) & 1U) != 0) {
      fVar17 = ((dlight_t *)(pfVar27 + -3))->origin[0] - pcVar18->origin[0];
      fVar15 = pfVar27[-2] - pcVar18->origin[1];
      fVar16 = pfVar27[-1] - pcVar18->origin[2];
      pmVar13 = surf->plane;
      fVar14 = *pfVar27 -
               ABS((pmVar13->normal[2] * fVar16 +
                   pmVar13->normal[1] * fVar15 + pmVar13->normal[0] * fVar17) - pmVar13->dist);
      fVar3 = pfVar27[4];
      if (fVar3 <= fVar14) {
        fVar4 = pmVar12->vecs[0][0];
        fVar5 = pmVar12->vecs[0][1];
        fVar6 = pmVar12->vecs[0][2];
        fVar7 = pmVar12->vecs[0][3];
        sVar1 = surf->texturemins[0];
        fVar8 = pmVar12->vecs[1][0];
        fVar9 = pmVar12->vecs[1][1];
        fVar10 = pmVar12->vecs[1][2];
        fVar11 = pmVar12->vecs[1][3];
        sVar2 = surf->texturemins[1];
        if (-1 < iVar20) {
          local_2c = blocklights;
          local_30 = 0;
          do {
            uVar25 = (uint)(((fVar16 * fVar10 + fVar15 * fVar9 + fVar17 * fVar8 + fVar11) -
                            (float)sVar2) - (float)local_30);
            uVar21 = (int)uVar25 >> 0x1f;
            iVar26 = (uVar25 ^ uVar21) - uVar21;
            if (0 < iVar19) {
              iVar23 = 0;
              pcVar24 = local_2c;
              do {
                uVar21 = (uint)(((fVar6 * fVar16 + fVar5 * fVar15 + fVar4 * fVar17 + fVar7) -
                                (float)sVar1) - (float)iVar23);
                uVar25 = (int)uVar21 >> 0x1f;
                iVar22 = (uVar21 ^ uVar25) - uVar25;
                if (iVar26 < iVar22) {
                  iVar22 = iVar22 + (iVar26 >> 1);
                }
                else {
                  iVar22 = (iVar22 >> 1) + iVar26;
                }
                if ((float)iVar22 < fVar14 - fVar3) {
                  iVar22 = (int)((fVar14 - (float)iVar22) * 256.0);
                  pcVar24->r = pcVar24->r +
                               ((int)((uint)((color24 *)(pfVar27 + 1))->r * iVar22) >> 8);
                  pcVar24->g = pcVar24->g + ((int)((uint)*(byte *)((int)pfVar27 + 5) * iVar22) >> 8)
                  ;
                  pcVar24->b = pcVar24->b + ((int)(iVar22 * (uint)*(byte *)((int)pfVar27 + 6)) >> 8)
                  ;
                }
                iVar23 = iVar23 + 0x10;
                pcVar24 = pcVar24 + 1;
              } while (iVar23 != iVar19 * 0x10);
            }
            local_30 = local_30 + 0x10;
            local_2c = local_2c + iVar19;
          } while (local_30 != (iVar20 + 1) * 0x10);
        }
      }
    }
    local_28 = local_28 + 1;
    pfVar27 = pfVar27 + 10;
  } while (local_28 != 0x20);
  return;
}


// R_AddEfrags  @ 001a3680
void R_AddEfrags(cl_entity_t *ent)

{
  model_s *pmVar1;
  
                    /* Unresolved local var: model_t * entmodel@[???]
                       Unresolved local var: int i@[???] */
  pmVar1 = ent->model;
  if (pmVar1 != (model_s *)0x0) {
    lastlink = &ent->efrag;
    r_emins[0] = pmVar1->mins[0] + ent->origin[0];
    r_addent = ent;
    r_pefragtopnode = (mnode_t *)0x0;
    r_emaxs[0] = pmVar1->maxs[0] + ent->origin[0];
    r_emins[1] = pmVar1->mins[1] + ent->origin[1];
    r_emaxs[1] = pmVar1->maxs[1] + ent->origin[1];
    r_emins[2] = pmVar1->mins[2] + ent->origin[2];
    r_emaxs[2] = pmVar1->maxs[2] + ent->origin[2];
    R_SplitEntityOnNode((cl.worldmodel)->nodes);
    ent->topnode = r_pefragtopnode;
  }
  return;
}


// R_AddToStudioCache  @ 000d8f30
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


// R_AllocObjects  @ 001c0740
void R_AllocObjects(int nMax)

{
  if (transObjects != (transObjRef *)0x0) {
    Con_Printf("Transparent objects reallocate\n");
  }
  transObjects = Mem_Malloc(nMax * 8);
  Q_memset(transObjects,0,nMax * 8);
  maxTransObjs = nMax;
  return;
}


// R_AllocParticle  @ 001a2110
particle_s * R_AllocParticle(_func_void_particle_s_ptr_float *callback)

{
  particle_s **pppVar1;
  vec_t vVar2;
  vec_t vVar3;
  particle_t *ppVar4;
  particle_t *ppVar5;
  
  ppVar5 = free_particles;
                    /* Unresolved local var: particle_t * p@[???] */
  vVar2 = vec3_origin[0];
  if (free_particles == (particle_t *)0x0) {
    Con_Printf("Not enough free particles\n");
  }
  else {
    free_particles->type = pt_clientcustom;
    ppVar4 = active_particles;
    active_particles = free_particles;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar4;
    ppVar5->die = (float)cl.time;
    ppVar5->org[0] = vVar2;
    ppVar5->color = 0;
    vVar2 = vec3_origin[1];
    ppVar5->callback = callback;
    ppVar5->deathfunc = (_func_void_particle_s_ptr *)0x0;
    ppVar5->org[1] = vVar2;
    ppVar5->ramp = 0.0;
    ppVar5->org[2] = vec3_origin[2];
    vVar3 = vec3_origin[2];
    vVar2 = vec3_origin[0];
    ppVar5->vel[1] = vec3_origin[1];
    ppVar5->vel[2] = vVar3;
    ppVar5->vel[0] = vVar2;
    ppVar5->packedColor = 0;
  }
  return ppVar5;
}


// R_AnimateLight  @ 001984c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_AnimateLight(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  lightstyle_t *plVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[DW_OP_reg1(ECX)]
                       Unresolved local var: int k@[???] */
  iVar3 = 0;
  plVar4 = cl_lightstyle;
  fVar1 = (float)cl.time;
  do {
    iVar2 = 0x100;
    if (plVar4->length != 0) {
      iVar2 = (*(char *)(iVar3 * 0x44 + 0xc3e984 + (int)(fVar1 * 10.0) % plVar4->length) + -0x61) *
              0x16;
    }
    d_lightstylevalue[iVar3] = iVar2;
    iVar3 = iVar3 + 1;
    plVar4 = plVar4 + 1;
  } while (iVar3 != 0x40);
  return;
}


// R_AttachTentToPlayer  @ 0014e620
void R_AttachTentToPlayer(int client,int modelIndex,float zoffset,float life)

{
  model_s *pmVar1;
  model_t *model;
  TEMPENTITY *pTVar2;
  int iVar3;
  vec_t local_18;
  vec_t local_14;
  float local_10;
  
                    /* Unresolved local var: model_t * pModel@[???] */
  model = CL_GetModelByIndex(modelIndex);
  if (model != (model_t *)0x0) {
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: cl_entity_t * pent@[???]
                       Unresolved local var: vec3_t position@[???]
                       Unresolved local var: int frameCount@[DW_OP_reg0(EAX)] */
    if ((client < 0) || (cl.maxclients < client)) {
      Con_Printf("Bad client in R_AttachTentToPlayer()!\n");
    }
    else if (cl_entities[client].curstate.messagenum == cl.parsecount) {
      local_10 = cl_entities[client].origin[2] + zoffset;
      local_18 = cl_entities[client].origin[0];
      local_14 = cl_entities[client].origin[1];
      pTVar2 = (*efx.CL_TempEntAllocHigh)(&local_18,model);
      if (pTVar2 == (TEMPENTITY *)0x0) {
        Con_Printf("No temp ent.\n");
      }
      else {
        (pTVar2->entity).curstate.rendermode = 0;
        pTVar2->tentOffset[2] = zoffset;
        (pTVar2->entity).curstate.renderfx = 0xe;
        (pTVar2->entity).curstate.renderamt = 0xff;
        (pTVar2->entity).baseline.renderamt = 0xff;
        (pTVar2->entity).curstate.framerate = 1.0;
        pTVar2->clientIndex = (short)client;
        pTVar2->tentOffset[0] = 0.0;
        pTVar2->tentOffset[1] = 0.0;
        pTVar2->die = life + (float)cl.time;
        pmVar1 = (pTVar2->entity).model;
        pTVar2->flags = pTVar2->flags | 0xa000;
        if (pmVar1->type == mod_sprite) {
          iVar3 = ModelFrameCount(model);
          pTVar2->flags = pTVar2->flags | 0x10100;
          (pTVar2->entity).curstate.framerate = 10.0;
          pTVar2->frameMax = (float)iVar3;
        }
        else {
          pTVar2->frameMax = 0.0;
        }
        (pTVar2->entity).curstate.frame = 0.0;
      }
    }
    return;
  }
  Con_Printf("No model %d!\n",modelIndex);
  return;
}


// R_AttachTentToPlayer2  @ 0014e4c0
void R_AttachTentToPlayer2(int client,model_s *pModel,float zoffset,float life)

{
  model_s *pmVar1;
  TEMPENTITY *pTVar2;
  int iVar3;
  vec_t local_18;
  vec_t local_14;
  float local_10;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: cl_entity_t * pent@[???]
                       Unresolved local var: vec3_t position@[???]
                       Unresolved local var: int frameCount@[???] */
  if ((client < 0) || (cl.maxclients < client)) {
    Con_Printf("Bad client in R_AttachTentToPlayer()!\n");
  }
  else if (cl_entities[client].curstate.messagenum == cl.parsecount) {
    local_10 = cl_entities[client].origin[2] + zoffset;
    local_18 = cl_entities[client].origin[0];
    local_14 = cl_entities[client].origin[1];
    pTVar2 = (*efx.CL_TempEntAllocHigh)(&local_18,pModel);
    if (pTVar2 == (TEMPENTITY *)0x0) {
      Con_Printf("No temp ent.\n");
    }
    else {
      (pTVar2->entity).curstate.rendermode = 0;
      pTVar2->tentOffset[2] = zoffset;
      (pTVar2->entity).curstate.renderfx = 0xe;
      (pTVar2->entity).curstate.renderamt = 0xff;
      (pTVar2->entity).baseline.renderamt = 0xff;
      (pTVar2->entity).curstate.framerate = 1.0;
      pTVar2->clientIndex = (short)client;
      pTVar2->tentOffset[0] = 0.0;
      pTVar2->tentOffset[1] = 0.0;
      pTVar2->die = life + (float)cl.time;
      pmVar1 = (pTVar2->entity).model;
      pTVar2->flags = pTVar2->flags | 0xa000;
      if (pmVar1->type == mod_sprite) {
        iVar3 = ModelFrameCount(pModel);
        pTVar2->flags = pTVar2->flags | 0x10100;
        (pTVar2->entity).curstate.framerate = 10.0;
        pTVar2->frameMax = (float)iVar3;
      }
      else {
        pTVar2->frameMax = 0.0;
      }
      (pTVar2->entity).curstate.frame = 0.0;
    }
  }
  return;
}


// R_BeamAlloc  @ 0019c0f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BEAM * R_BeamAlloc(void)

{
  BEAM **ppBVar1;
  BEAM *pBVar2;
  BEAM *pBVar3;
  
  pBVar2 = gpActiveBeams;
                    /* Unresolved local var: BEAM * pbeam@[???] */
  pBVar3 = gpFreeBeams;
  if (gpFreeBeams != (BEAM *)0x0) {
    gpActiveBeams = gpFreeBeams;
    ppBVar1 = &gpFreeBeams->next;
    gpFreeBeams = gpFreeBeams->next;
    *ppBVar1 = pBVar2;
  }
  return pBVar3;
}


// R_BeamCirclePoints  @ 0019cce0
BEAM * R_BeamCirclePoints(int type,vec_t *start,vec_t *end,int modelIndex,float life,float width,
                         float amplitude,float brightness,float speed,int startFrame,float framerate
                         ,float r,float g,float b)

{
  BEAM **ppBVar1;
  BEAM *pBVar2;
  BEAM *pBVar3;
  model_t *model;
  int iVar4;
  float fVar5;
  
  pBVar3 = gpActiveBeams;
                    /* Unresolved local var: BEAM * pbeam@[???] */
  pBVar2 = gpFreeBeams;
                    /* Unresolved local var: BEAM * pbeam@[???] */
  if (gpFreeBeams != (BEAM *)0x0) {
    gpActiveBeams = gpFreeBeams;
    ppBVar1 = &gpFreeBeams->next;
    gpFreeBeams = gpFreeBeams->next;
    *ppBVar1 = pBVar3;
    pBVar2->die = (float)cl.time;
    if (-1 < modelIndex) {
                    /* Unresolved local var: model_t * sprite@[???] */
      model = CL_GetModelByIndex(modelIndex);
      if (model != (model_t *)0x0) {
        pBVar2->type = 0;
        pBVar2->modelIndex = modelIndex;
        pBVar2->frame = 0.0;
        pBVar2->frameRate = 0.0;
        iVar4 = ModelFrameCount(model);
        pBVar2->frameCount = iVar4;
        pBVar2->source[0] = *start;
        pBVar2->source[1] = start[1];
        pBVar2->source[2] = start[2];
        pBVar2->target[0] = *end;
        pBVar2->target[1] = end[1];
        pBVar2->target[2] = end[2];
        pBVar2->delta[0] = *end - *start;
        pBVar2->delta[1] = end[1] - start[1];
        pBVar2->delta[2] = end[2] - start[2];
        pBVar2->freq = speed * (float)cl.time;
        pBVar2->die = life + (float)cl.time;
        pBVar2->width = width;
        pBVar2->amplitude = amplitude;
        pBVar2->brightness = brightness;
        pBVar2->speed = speed;
        if (0.5 <= amplitude) {
          fVar5 = Length(pBVar2->delta);
          pBVar2->segments = (int)(fVar5 * 0.25 + 3.0);
        }
        else {
          fVar5 = Length(pBVar2->delta);
          pBVar2->segments = (int)(fVar5 * 0.075 + 3.0);
        }
        pBVar2->flags = 0;
        pBVar2->pFollowModel = (model_s *)0x0;
      }
      pBVar2->type = type;
      if (life == 0.0) {
        pBVar2->flags = pBVar2->flags | 0x80000000;
      }
      pBVar2->frameRate = framerate;
      pBVar2->r = r;
      pBVar2->g = g;
      pBVar2->frame = (float)startFrame;
      pBVar2->b = b;
      return pBVar2;
    }
  }
  return (BEAM *)0x0;
}


// R_BeamClear  @ 00199950
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_BeamClear(void)

{
  BEAM *pBVar1;
  BEAM *pBVar2;
  BEAM *pBVar3;
  
                    /* Unresolved local var: int i@[???] */
  gpActiveBeams = (BEAM *)0x0;
                    /* try { // try from 00199965 to 001a9969 has its CatchHandler @ 00199d6d */
  gpFreeBeams = gBeams;
  Q_memset(gBeams,0,0x3e00);
  pBVar2 = gBeams;
  pBVar3 = gBeams + 1;
  pBVar1 = gBeams + 0x81;
  do {
    pBVar3[-1].next = pBVar3;
    pBVar3 = pBVar3 + 1;
  } while (pBVar1 != pBVar3);
  pBVar2[0x7f].next = (BEAM *)0x0;
  return;
}


// R_BeamCull  @ 0019f920
int R_BeamCull(vec_t *start,vec_t *end,int pvsOnly)

{
  float fVar1;
  mnode_t *pmVar2;
  qboolean qVar3;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: int i@[???] */
  if (cl.worldmodel != (model_s *)0x0) {
    fVar1 = *start;
    local_18 = *end;
    local_24 = fVar1;
    if (local_18 <= fVar1) {
      local_24 = local_18;
      local_18 = fVar1;
    }
    if (local_24 == local_18) {
      local_18 = local_18 + 1.0;
    }
    fVar1 = start[1];
    local_14 = end[1];
    local_20 = fVar1;
    if (local_14 <= fVar1) {
      local_20 = local_14;
      local_14 = fVar1;
    }
    if (local_20 == local_14) {
      local_14 = local_14 + 1.0;
    }
    fVar1 = start[2];
    local_10 = end[2];
    local_1c = fVar1;
    if (local_10 <= fVar1) {
      local_1c = local_10;
      local_10 = fVar1;
    }
    if (local_1c == local_10) {
      local_10 = local_10 + 1.0;
    }
    pmVar2 = PVSNode((cl.worldmodel)->nodes,&local_24,&local_18);
    if (pmVar2 != (mnode_t *)0x0) {
      if (pvsOnly != 0) {
        return 1;
      }
      qVar3 = R_CullBox(&local_24,&local_18);
      return (uint)(qVar3 == false);
    }
  }
  return 0;
}


// R_BeamDraw  @ 0019fa70
void R_BeamDraw(BEAM *pbeam,float frametime)

{
  particle_s **pppVar1;
  vec_t vVar2;
  model_s *pmVar3;
  float fVar4;
  particle_t *ppVar5;
  particle_t *ppVar6;
  model_t *pmVar7;
  vec_t *pvVar8;
  mnode_t *pmVar9;
  qboolean qVar10;
  int iVar11;
  cl_entity_t *pcVar12;
  uint uVar13;
  float *pfVar14;
  float fVar15;
  double dVar16;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: model_t * sprite@[???]
                       Unresolved local var: vec3_t difference@[???] */
  if (pbeam->modelIndex < 0) {
    pbeam->die = (float)cl.time;
  }
  else {
    pmVar7 = CL_GetModelByIndex(pbeam->modelIndex);
    if (pmVar7 != (model_t *)0x0) {
      if ((pbeam->flags & 0x20) == 0) {
        (*tri.RenderMode)(5);
      }
      else {
        (*tri.RenderMode)(0);
      }
      pbeam->freq = pbeam->freq + frametime;
      gNoise[0] = 0.0;
      gNoise[0x80] = 0.0;
      if (pbeam->amplitude != 0.0) {
        if ((pbeam->flags & 0x10) == 0) {
          Noise(gNoise,0x80);
        }
        else {
          fVar4 = 0.0;
          pfVar14 = gNoise;
          fVar15 = 0.0;
          while( true ) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float freq@[???]
                       Unresolved local var: float freq2@[???]
                       Unresolved local var: float step@[???] */
            *pfVar14 = fVar4;
            pfVar14 = pfVar14 + 1;
            fVar15 = fVar15 + 0.024543693;
            if (pfVar14 == gNoise + 0x80) break;
            dVar16 = sin((double)fVar15);
            fVar4 = (float)dVar16;
          }
        }
      }
      uVar13 = pbeam->flags;
      if ((uVar13 & 3) != 0) {
        if ((uVar13 & 1) != 0) {
                    /* Unresolved local var: cl_entity_t * start@[???] */
          uVar13 = pbeam->startEntity;
          if ((int)uVar13 < 0) {
                    /* Unresolved local var: int client_index@[???] */
            pcVar12 = ClientDLL_GetUserEntity(-uVar13 & 0xfff);
          }
          else {
            pcVar12 = cl_entities + (uVar13 & 0xfff);
          }
          if (pcVar12 == (cl_entity_t *)0x0) {
            return;
          }
          if ((pcVar12->model == (model_s *)0x0) ||
             ((pmVar3 = pbeam->pFollowModel, pmVar3 != (model_s *)0x0 && (pcVar12->model != pmVar3))
             )) {
            uVar13 = pbeam->flags;
            if (-1 < (int)uVar13) {
              uVar13 = uVar13 & 0xfffffffe;
              pbeam->flags = uVar13;
            }
          }
          else {
                    /* Unresolved local var: float * attachmentPoint@[???] */
            iVar11 = pbeam->startEntity;
                    /* Unresolved local var: int attach@[???] */
            if (iVar11 < 0) {
              iVar11 = -iVar11;
            }
            uVar13 = iVar11 >> 0xc & 0xf;
            if (uVar13 == 0) {
                    /* Unresolved local var: int attach@[???] */
              pvVar8 = pcVar12->origin;
              if (pcVar12->index == cl.playernum + 1) {
                pvVar8 = cl.simorg;
              }
            }
            else {
              pvVar8 = pcVar12->angles + uVar13 * 3;
            }
            pbeam->source[0] = *pvVar8;
            pbeam->source[1] = pvVar8[1];
            pbeam->source[2] = pvVar8[2];
            uVar13 = pbeam->flags | 0x10000000;
            pbeam->flags = uVar13;
            if (pmVar3 == (model_s *)0x0) {
              pbeam->pFollowModel = pcVar12->model;
            }
          }
        }
        if ((uVar13 & 2) != 0) {
                    /* Unresolved local var: cl_entity_t * end@[???] */
          uVar13 = pbeam->endEntity;
          if ((int)uVar13 < 0) {
                    /* Unresolved local var: int client_index@[???] */
            pcVar12 = ClientDLL_GetUserEntity(-uVar13 & 0xfff);
          }
          else {
            pcVar12 = cl_entities + (uVar13 & 0xfff);
          }
          if (pcVar12 == (cl_entity_t *)0x0) {
            return;
          }
          if (pcVar12->model == (model_s *)0x0) {
            if (pbeam->flags < 0) {
              return;
            }
            pbeam->flags = pbeam->flags & 0xfffffffd;
            pbeam->die = (float)cl.time;
            return;
          }
                    /* Unresolved local var: float * attachmentPoint@[???] */
          iVar11 = pbeam->endEntity;
                    /* Unresolved local var: int attach@[???] */
          if (iVar11 < 0) {
            iVar11 = -iVar11;
          }
          uVar13 = iVar11 >> 0xc & 0xf;
          if (uVar13 == 0) {
                    /* Unresolved local var: int attach@[???] */
            pvVar8 = cl.simorg;
            if (pcVar12->index != cl.playernum + 1) {
              pvVar8 = pcVar12->origin;
            }
          }
          else {
            pvVar8 = pcVar12->angles + uVar13 * 3;
          }
          pbeam->target[0] = *pvVar8;
          pbeam->target[1] = pvVar8[1];
          vVar2 = pvVar8[2];
          pbeam->flags = pbeam->flags | 0x20000000;
          pbeam->target[2] = vVar2;
        }
        if ((pbeam->flags & 0x10000001U) == 1) {
          return;
        }
        local_40 = pbeam->target[0] - pbeam->source[0];
        local_3c = pbeam->target[1] - pbeam->source[1];
        local_38 = pbeam->target[2] - pbeam->source[2];
        fVar15 = Length(&local_40);
        if (1e-07 < fVar15) {
          pbeam->delta[0] = local_40;
          pbeam->delta[1] = local_3c;
          pbeam->delta[2] = local_38;
        }
        if (pbeam->amplitude < 0.5) {
          fVar15 = Length(pbeam->delta);
          pbeam->segments = (int)(fVar15 * 0.075 + 3.0);
        }
        else {
          fVar15 = Length(pbeam->delta);
          pbeam->segments = (int)(fVar15 * 0.25 + 3.0);
        }
      }
      if (pbeam->type == 0) {
                    /* Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: int i@[???] */
        if (cl.worldmodel == (model_s *)0x0) {
          return;
        }
        local_28 = pbeam->source[0];
        fVar15 = pbeam->target[0];
        local_34 = fVar15;
        if (local_28 < fVar15) {
          local_34 = local_28;
          local_28 = fVar15;
        }
        if (local_28 == local_34) {
          local_28 = local_28 + 1.0;
        }
        local_24 = pbeam->source[1];
        fVar15 = pbeam->target[1];
        local_30 = fVar15;
        if (local_24 < fVar15) {
          local_30 = local_24;
          local_24 = fVar15;
        }
        if (local_24 == local_30) {
          local_24 = local_24 + 1.0;
        }
        local_20 = pbeam->source[2];
        fVar15 = pbeam->target[2];
        local_2c = fVar15;
        if (local_20 < fVar15) {
          local_2c = local_20;
          local_20 = fVar15;
        }
        if (local_2c == local_20) {
          local_20 = local_20 + 1.0;
        }
        pmVar9 = PVSNode((cl.worldmodel)->nodes,&local_34,&local_28);
        if (pmVar9 == (mnode_t *)0x0) {
          return;
        }
        qVar10 = R_CullBox(&local_34,&local_28);
        if (qVar10 != false) {
          return;
        }
      }
      iVar11 = (*tri.SpriteTexture)
                         (pmVar7,(int)(pbeam->frameRate * (float)cl.time + pbeam->frame) %
                                 pbeam->frameCount);
      fVar15 = egon_amplitude.value;
      if (iVar11 != 0) {
        uVar13 = pbeam->flags;
        if (((uVar13 & 0x10) != 0) && (0.0 < egon_amplitude.value)) {
                    /* Unresolved local var: particle_t * p@[???]
                       Unresolved local var: vec3_t org@[???]
                       Unresolved local var: vec3_t speed@[???]
                       Unresolved local var: float length@[???] */
          dVar16 = sin((double)(pbeam->freq * 10.0));
          VectorMA(pbeam->target,fVar15 * pbeam->amplitude * (float)dVar16,vup,&local_34);
          dVar16 = cos((double)(pbeam->freq * 10.0));
          VectorMA(&local_34,egon_amplitude.value * pbeam->amplitude * (float)dVar16,vright,
                   &local_34);
          local_28 = pbeam->source[0] - local_34;
          local_24 = pbeam->source[1] - local_30;
          local_20 = pbeam->source[2] - local_2c;
          fVar15 = Length(&local_28);
          if (fVar15 != 0.0) {
            VectorScale(&local_28,1000.0 / fVar15,&local_28);
          }
          ppVar6 = free_particles;
          ppVar5 = gpActiveTracers;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: particle_t * p@[???] */
          if (free_particles != (particle_t *)0x0) {
            gpActiveTracers = free_particles;
            pppVar1 = &free_particles->next;
            free_particles = free_particles->next;
            *pppVar1 = ppVar5;
            ppVar6->die = fVar15 * 0.001 + (float)cl.time;
            ppVar6->color = 4;
            ppVar6->packedColor = 0xff;
            fVar15 = tracerLength.value;
            ppVar6->type = pt_static;
            ppVar6->ramp = fVar15;
            ppVar6->org[0] = local_34;
            ppVar6->vel[0] = local_28;
            ppVar6->org[1] = local_30;
            ppVar6->vel[1] = local_24;
            ppVar6->org[2] = local_2c;
            ppVar6->color = 7;
            ppVar6->vel[2] = local_20;
          }
          uVar13 = pbeam->flags;
        }
        fVar15 = (pbeam->die - (float)cl.time) + pbeam->freq;
        if (fVar15 != 0.0) {
          fVar15 = 1.0 - pbeam->freq / fVar15;
        }
        pbeam->t = fVar15;
        if ((uVar13 & 4) == 0) {
          if ((uVar13 & 8) == 0) {
            (*tri.Color4f)(pbeam->r,pbeam->g,pbeam->b,pbeam->brightness);
          }
          else {
            (*tri.Color4f)(pbeam->r,pbeam->g,pbeam->b,(1.0 - fVar15) * pbeam->brightness);
          }
        }
        else {
          (*tri.Color4f)(pbeam->r,pbeam->g,pbeam->b,fVar15 * pbeam->brightness);
        }
        switch(pbeam->type) {
        case 0:
          (*tri.Begin)(2);
          R_DrawSegs(pbeam->source,pbeam->delta,pbeam->width,pbeam->amplitude,pbeam->freq,
                     pbeam->speed,pbeam->segments,pbeam->flags);
          (*tri.End)();
          break;
        case 0x13:
          (*tri.Begin)(6);
          R_DrawTorus(pbeam->source,pbeam->delta,pbeam->width,pbeam->amplitude,pbeam->freq,
                      pbeam->speed,pbeam->segments);
          (*tri.End)();
          break;
        case 0x14:
          (*tri.Begin)(6);
          R_DrawDisk(pbeam->source,pbeam->delta,pbeam->width,pbeam->amplitude,pbeam->freq,
                     pbeam->speed,pbeam->segments);
          (*tri.End)();
          break;
        case 0x15:
          (*tri.Begin)(6);
          R_DrawCylinder(pbeam->source,pbeam->delta,pbeam->width,pbeam->amplitude,pbeam->freq,
                         pbeam->speed,pbeam->segments);
          (*tri.End)();
          break;
        case 0x16:
          (*tri.Begin)(2);
          R_DrawBeamFollow(pbeam);
          (*tri.End)();
          break;
        case 0x18:
          (*tri.Begin)(6);
          R_DrawRing(pbeam->source,pbeam->delta,pbeam->width,pbeam->amplitude,pbeam->freq,
                     pbeam->speed,pbeam->segments);
          (*tri.End)();
        }
      }
    }
  }
  return;
}


// R_BeamDrawList  @ 001a0770
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_BeamDrawList(void)

{
  particle_s **pppVar1;
  vec_t vVar2;
  model_s *pmVar3;
  particle_t *ppVar4;
  particle_t *ppVar5;
  model_t *pmVar6;
  vec_t *pvVar7;
  mnode_t *pmVar8;
  qboolean qVar9;
  int iVar10;
  cl_entity_t *pcVar11;
  uint uVar12;
  BEAM *pBVar13;
  float *pfVar14;
  BEAM *pbeam;
  longdouble lVar15;
  float fVar16;
  double dVar17;
  float fVar18;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float frametime@[???]
                       Unresolved local var: BEAM * pbeam@[???]
                       Unresolved local var: BEAM * pkill@[???] */
  if (gpActiveBeams == (BEAM *)0x0) {
    if (cl_numbeamentities == 0) {
      return;
    }
    lVar15 = (longdouble)cl.time - (longdouble)cl.oldtime;
    (*qglDisable)(0xbc0);
    (*qglDepthMask)('\0');
    (*tri.CullFace)(TRI_NONE);
    pbeam = gpActiveBeams;
  }
  else {
    lVar15 = (longdouble)cl.time - (longdouble)cl.oldtime;
    (*qglDisable)(0xbc0);
    (*qglDepthMask)('\0');
    (*tri.CullFace)(TRI_NONE);
    pbeam = gpActiveBeams;
  }
  gpActiveBeams = pbeam;
  if (pbeam != (BEAM *)0x0) {
    if ((-1 < pbeam->flags) && (pBVar13 = gpFreeBeams, pbeam->die < (float)cl.time)) {
      do {
        gpFreeBeams = pbeam;
        pbeam = gpFreeBeams->next;
        gpFreeBeams->next = pBVar13;
        if (pbeam == (BEAM *)0x0) {
          gpActiveBeams = (BEAM *)0x0;
          goto LAB_001a0e7b;
        }
        gpActiveBeams = pbeam;
      } while ((-1 < pbeam->flags) && (pBVar13 = gpFreeBeams, pbeam->die < (float)cl.time));
    }
    do {
      pBVar13 = pbeam->next;
      if ((pBVar13 != (BEAM *)0x0) && ((-1 < pBVar13->flags && (pBVar13->die <= (float)cl.time)))) {
        pbeam->next = pBVar13->next;
        pBVar13->next = gpFreeBeams;
        gpFreeBeams = pBVar13;
        pBVar13 = pbeam->next;
        while (((pBVar13 != (BEAM *)0x0 && (-1 < pBVar13->flags)) &&
               (pBVar13->die <= (float)cl.time))) {
          pbeam->next = pBVar13->next;
          pBVar13->next = gpFreeBeams;
          gpFreeBeams = pBVar13;
          pBVar13 = pbeam->next;
        }
      }
                    /* Unresolved local var: model_t * sprite@[???]
                       Unresolved local var: vec3_t difference@[???] */
      if (pbeam->modelIndex < 0) {
LAB_001a0ed0:
        pbeam->die = (float)cl.time;
        pbeam = pbeam->next;
        goto joined_r0x001a10c0;
      }
      pmVar6 = CL_GetModelByIndex(pbeam->modelIndex);
      if (pmVar6 == (model_t *)0x0) goto switchD_001a0dc2_caseD_1;
      if ((pbeam->flags & 0x20) == 0) {
        (*tri.RenderMode)(5);
      }
      else {
        (*tri.RenderMode)(0);
      }
      pbeam->freq = (float)lVar15 + pbeam->freq;
      gNoise[0] = 0.0;
      gNoise[0x80] = 0.0;
      if (pbeam->amplitude != 0.0) {
        if ((pbeam->flags & 0x10) == 0) {
          Noise(gNoise,0x80);
        }
        else {
          fVar18 = 0.0;
          pfVar14 = gNoise;
          fVar16 = 0.0;
          while( true ) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float freq@[???]
                       Unresolved local var: float freq2@[???]
                       Unresolved local var: float step@[???] */
            *pfVar14 = fVar18;
            pfVar14 = pfVar14 + 1;
            fVar16 = fVar16 + 0.024543693;
            if (pfVar14 == gNoise + 0x80) break;
            dVar17 = sin((double)fVar16);
            fVar18 = (float)dVar17;
          }
        }
      }
      uVar12 = pbeam->flags;
      if ((uVar12 & 3) != 0) {
        if ((uVar12 & 1) != 0) {
                    /* Unresolved local var: cl_entity_t * start@[???] */
          uVar12 = pbeam->startEntity;
          if ((int)uVar12 < 0) {
                    /* Unresolved local var: int client_index@[???] */
            pcVar11 = ClientDLL_GetUserEntity(-uVar12 & 0xfff);
          }
          else {
            pcVar11 = cl_entities + (uVar12 & 0xfff);
          }
          if (pcVar11 == (cl_entity_t *)0x0) goto switchD_001a0dc2_caseD_1;
          if ((pcVar11->model == (model_s *)0x0) ||
             ((pmVar3 = pbeam->pFollowModel, pcVar11->model != pmVar3 && (pmVar3 != (model_s *)0x0))
             )) {
            uVar12 = pbeam->flags;
            if (-1 < (int)uVar12) {
              uVar12 = uVar12 & 0xfffffffe;
              pbeam->flags = uVar12;
            }
          }
          else {
                    /* Unresolved local var: float * attachmentPoint@[???] */
            iVar10 = pbeam->startEntity;
                    /* Unresolved local var: int attach@[???] */
            if (iVar10 < 0) {
              iVar10 = -iVar10;
            }
            uVar12 = iVar10 >> 0xc & 0xf;
            if (uVar12 == 0) {
                    /* Unresolved local var: int attach@[???] */
              pvVar7 = pcVar11->origin;
              if (pcVar11->index == cl.playernum + 1) {
                pvVar7 = cl.simorg;
              }
            }
            else {
              pvVar7 = pcVar11->angles + uVar12 * 3;
            }
            pbeam->source[0] = *pvVar7;
            pbeam->source[1] = pvVar7[1];
            pbeam->source[2] = pvVar7[2];
            uVar12 = pbeam->flags | 0x10000000;
            pbeam->flags = uVar12;
            if (pmVar3 == (model_s *)0x0) {
              pbeam->pFollowModel = pcVar11->model;
            }
          }
        }
        if ((uVar12 & 2) == 0) {
LAB_001a09e7:
          if ((pbeam->flags & 0x10000001U) != 1) {
            local_40 = pbeam->target[0] - pbeam->source[0];
            local_3c = pbeam->target[1] - pbeam->source[1];
            local_38 = pbeam->target[2] - pbeam->source[2];
            fVar16 = Length(&local_40);
            if (1e-07 < fVar16) {
              pbeam->delta[0] = local_40;
              pbeam->delta[1] = local_3c;
              pbeam->delta[2] = local_38;
            }
            if (pbeam->amplitude < 0.5) {
              fVar16 = Length(pbeam->delta);
              pbeam->segments = (int)(fVar16 * 0.075 + 3.0);
            }
            else {
              fVar16 = Length(pbeam->delta);
              pbeam->segments = (int)(fVar16 * 0.25 + 3.0);
            }
            goto LAB_001a0a90;
          }
        }
        else {
                    /* Unresolved local var: cl_entity_t * end@[???] */
          uVar12 = pbeam->endEntity;
          if ((int)uVar12 < 0) {
                    /* Unresolved local var: int client_index@[???] */
            pcVar11 = ClientDLL_GetUserEntity(-uVar12 & 0xfff);
          }
          else {
            pcVar11 = cl_entities + (uVar12 & 0xfff);
          }
          if (pcVar11 != (cl_entity_t *)0x0) {
            if (pcVar11->model != (model_s *)0x0) {
                    /* Unresolved local var: float * attachmentPoint@[???] */
              iVar10 = pbeam->endEntity;
                    /* Unresolved local var: int attach@[???] */
              if (iVar10 < 0) {
                uVar12 = -iVar10 >> 0xc & 0xf;
                if (uVar12 == 0) goto LAB_001a09aa;
LAB_001a0fb0:
                pvVar7 = pcVar11->angles + uVar12 * 3;
              }
              else {
                uVar12 = iVar10 >> 0xc & 0xf;
                if (uVar12 != 0) goto LAB_001a0fb0;
LAB_001a09aa:
                    /* Unresolved local var: int attach@[???] */
                pvVar7 = cl.simorg;
                if (pcVar11->index != cl.playernum + 1) {
                  pvVar7 = pcVar11->origin;
                }
              }
              pbeam->target[0] = *pvVar7;
              pbeam->target[1] = pvVar7[1];
              vVar2 = pvVar7[2];
              pbeam->flags = pbeam->flags | 0x20000000;
              pbeam->target[2] = vVar2;
              goto LAB_001a09e7;
            }
            if (-1 < pbeam->flags) {
              pbeam->flags = pbeam->flags & 0xfffffffd;
              goto LAB_001a0ed0;
            }
          }
        }
        goto switchD_001a0dc2_caseD_1;
      }
LAB_001a0a90:
      if (pbeam->type == 0) {
                    /* Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: int i@[???] */
        if (cl.worldmodel != (model_s *)0x0) {
          fVar16 = pbeam->source[0];
          local_28 = pbeam->target[0];
          local_34 = fVar16;
          if (local_28 <= fVar16) {
            local_34 = local_28;
            local_28 = fVar16;
          }
          if (local_34 == local_28) {
            local_28 = local_28 + 1.0;
          }
          fVar16 = pbeam->source[1];
          local_24 = pbeam->target[1];
          local_30 = fVar16;
          if (local_24 <= fVar16) {
            local_30 = local_24;
            local_24 = fVar16;
          }
          if (local_30 == local_24) {
            local_24 = local_24 + 1.0;
          }
          fVar16 = pbeam->source[2];
          local_20 = pbeam->target[2];
          local_2c = fVar16;
          if (local_20 <= fVar16) {
            local_2c = local_20;
            local_20 = fVar16;
          }
          if (local_2c == local_20) {
            local_20 = local_20 + 1.0;
          }
          pmVar8 = PVSNode((cl.worldmodel)->nodes,&local_34,&local_28);
          if ((pmVar8 != (mnode_t *)0x0) && (qVar9 = R_CullBox(&local_34,&local_28), qVar9 == false)
             ) goto LAB_001a0b84;
        }
        goto switchD_001a0dc2_caseD_1;
      }
LAB_001a0b84:
      iVar10 = (*tri.SpriteTexture)
                         (pmVar6,(int)(pbeam->frameRate * (float)cl.time + pbeam->frame) %
                                 pbeam->frameCount);
      fVar16 = egon_amplitude.value;
      if (iVar10 == 0) goto switchD_001a0dc2_caseD_1;
      uVar12 = pbeam->flags;
      if (((uVar12 & 0x10) != 0) && (0.0 < egon_amplitude.value)) {
                    /* Unresolved local var: particle_t * p@[???]
                       Unresolved local var: vec3_t org@[???]
                       Unresolved local var: vec3_t speed@[???]
                       Unresolved local var: float length@[???] */
        dVar17 = sin((double)(pbeam->freq * 10.0));
        VectorMA(pbeam->target,fVar16 * pbeam->amplitude * (float)dVar17,vup,&local_34);
        dVar17 = cos((double)(pbeam->freq * 10.0));
        VectorMA(&local_34,egon_amplitude.value * pbeam->amplitude * (float)dVar17,vright,&local_34)
        ;
        local_28 = pbeam->source[0] - local_34;
        local_24 = pbeam->source[1] - local_30;
        local_20 = pbeam->source[2] - local_2c;
        fVar16 = Length(&local_28);
        if (fVar16 != 0.0) {
          VectorScale(&local_28,1000.0 / fVar16,&local_28);
        }
        ppVar5 = free_particles;
        ppVar4 = gpActiveTracers;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: particle_t * p@[???] */
        if (free_particles != (particle_t *)0x0) {
          gpActiveTracers = free_particles;
          pppVar1 = &free_particles->next;
          free_particles = free_particles->next;
          *pppVar1 = ppVar4;
          ppVar5->die = fVar16 * 0.001 + (float)cl.time;
          ppVar5->color = 4;
          ppVar5->packedColor = 0xff;
          fVar16 = tracerLength.value;
          ppVar5->type = pt_static;
          ppVar5->ramp = fVar16;
          ppVar5->org[0] = local_34;
          ppVar5->vel[0] = local_28;
          ppVar5->org[1] = local_30;
          ppVar5->vel[1] = local_24;
          ppVar5->org[2] = local_2c;
          ppVar5->color = 7;
          ppVar5->vel[2] = local_20;
        }
        uVar12 = pbeam->flags;
      }
      fVar16 = (pbeam->die - (float)cl.time) + pbeam->freq;
      if (fVar16 == 0.0) {
        pbeam->t = fVar16;
        if ((uVar12 & 4) != 0) goto LAB_001a0f3b;
LAB_001a0d7a:
        if ((uVar12 & 8) != 0) {
          fVar16 = (1.0 - fVar16) * pbeam->brightness;
          fVar18 = pbeam->b;
          goto LAB_001a0f8e;
        }
        (*tri.Color4f)(pbeam->r,pbeam->g,pbeam->b,pbeam->brightness);
      }
      else {
        fVar16 = 1.0 - pbeam->freq / fVar16;
        pbeam->t = fVar16;
        if ((uVar12 & 4) == 0) goto LAB_001a0d7a;
LAB_001a0f3b:
        fVar16 = fVar16 * pbeam->brightness;
        fVar18 = pbeam->b;
LAB_001a0f8e:
        (*tri.Color4f)(pbeam->r,pbeam->g,fVar18,fVar16);
      }
      switch(pbeam->type) {
      case 0:
        (*tri.Begin)(2);
        R_DrawSegs(pbeam->source,pbeam->delta,pbeam->width,pbeam->amplitude,pbeam->freq,pbeam->speed
                   ,pbeam->segments,pbeam->flags);
        (*tri.End)();
        pbeam = pbeam->next;
        break;
      case 0x13:
        (*tri.Begin)(6);
        R_DrawTorus(pbeam->source,pbeam->delta,pbeam->width,pbeam->amplitude,pbeam->freq,
                    pbeam->speed,pbeam->segments);
        (*tri.End)();
        pbeam = pbeam->next;
        break;
      case 0x14:
        (*tri.Begin)(6);
        R_DrawDisk(pbeam->source,pbeam->delta,pbeam->width,pbeam->amplitude,pbeam->freq,pbeam->speed
                   ,pbeam->segments);
        (*tri.End)();
        pbeam = pbeam->next;
        break;
      case 0x15:
        (*tri.Begin)(6);
        R_DrawCylinder(pbeam->source,pbeam->delta,pbeam->width,pbeam->amplitude,pbeam->freq,
                       pbeam->speed,pbeam->segments);
        (*tri.End)();
      default:
switchD_001a0dc2_caseD_1:
        pbeam = pbeam->next;
        break;
      case 0x16:
        (*tri.Begin)(2);
        R_DrawBeamFollow(pbeam);
        (*tri.End)();
        pbeam = pbeam->next;
        break;
      case 0x18:
        (*tri.Begin)(6);
        R_DrawRing(pbeam->source,pbeam->delta,pbeam->width,pbeam->amplitude,pbeam->freq,pbeam->speed
                   ,pbeam->segments);
        (*tri.End)();
        pbeam = pbeam->next;
      }
joined_r0x001a10c0:
    } while (pbeam != (BEAM *)0x0);
  }
LAB_001a0e7b:
  R_DrawBeamEntList((float)lVar15);
  (*qglDepthMask)('\x01');
  (*tri.CullFace)(TRI_FRONT);
  (*tri.RenderMode)(0);
  return;
}


// R_BeamEntPoint  @ 0019c790
BEAM * R_BeamEntPoint(int startEnt,vec_t *end,int modelIndex,float life,float width,float amplitude,
                     float brightness,float speed,int startFrame,float framerate,float r,float g,
                     float b)

{
  BEAM **ppBVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  BEAM *pBVar5;
  BEAM *pBVar6;
  model_t *model;
  int iVar7;
  cl_entity_t *pcVar8;
  float fVar9;
  
                    /* Unresolved local var: BEAM * pbeam@[???]
                       Unresolved local var: cl_entity_t * start@[???] */
  if (startEnt < 0) {
                    /* Unresolved local var: int client_index@[???] */
    pcVar8 = ClientDLL_GetUserEntity(-startEnt & 0xfff);
  }
  else {
    pcVar8 = cl_entities + (startEnt & 0xfff);
  }
  pBVar6 = gpActiveBeams;
  pBVar5 = gpFreeBeams;
                    /* Unresolved local var: BEAM * pbeam@[???] */
  if ((pcVar8 != (cl_entity_t *)0x0) &&
     (((life == 0.0 || (pcVar8->model != (model_s *)0x0)) && (gpFreeBeams != (BEAM *)0x0)))) {
    gpActiveBeams = gpFreeBeams;
    ppBVar1 = &gpFreeBeams->next;
    gpFreeBeams = gpFreeBeams->next;
    *ppBVar1 = pBVar6;
    pBVar5->die = (float)cl.time;
    if (-1 < modelIndex) {
                    /* Unresolved local var: model_t * sprite@[???] */
      model = CL_GetModelByIndex(modelIndex);
      if (model != (model_t *)0x0) {
        pBVar5->type = 0;
        pBVar5->modelIndex = modelIndex;
        pBVar5->frame = 0.0;
        pBVar5->frameRate = 0.0;
        iVar7 = ModelFrameCount(model);
        vVar2 = vec3_origin[0];
        pBVar5->frameCount = iVar7;
        pBVar5->source[0] = vVar2;
        vVar3 = vec3_origin[1];
        pBVar5->source[1] = vec3_origin[1];
        vVar4 = vec3_origin[2];
        pBVar5->source[2] = vec3_origin[2];
        pBVar5->target[0] = *end;
        pBVar5->target[1] = end[1];
        pBVar5->target[2] = end[2];
        pBVar5->delta[0] = *end - vVar2;
        pBVar5->delta[1] = end[1] - vVar3;
        pBVar5->delta[2] = end[2] - vVar4;
        pBVar5->freq = speed * (float)cl.time;
        pBVar5->die = life + (float)cl.time;
        pBVar5->width = width;
        pBVar5->amplitude = amplitude;
        pBVar5->brightness = brightness;
        pBVar5->speed = speed;
        if (0.5 <= amplitude) {
          fVar9 = Length(pBVar5->delta);
          pBVar5->segments = (int)(fVar9 * 0.25 + 3.0);
        }
        else {
          fVar9 = Length(pBVar5->delta);
          pBVar5->segments = (int)(fVar9 * 0.075 + 3.0);
        }
        pBVar5->pFollowModel = (model_s *)0x0;
      }
      pBVar5->type = 0;
      if (life == 0.0) {
        pBVar5->flags = -0x7fffffff;
      }
      else {
        pBVar5->flags = 1;
      }
      pBVar5->frameRate = framerate;
      pBVar5->r = r;
      pBVar5->g = g;
      pBVar5->frame = (float)startFrame;
      pBVar5->b = b;
      pBVar5->startEntity = startEnt;
      pBVar5->endEntity = 0;
      return pBVar5;
    }
  }
  return (BEAM *)0x0;
}


// R_BeamEnts  @ 0019c4e0
BEAM * R_BeamEnts(int startEnt,int endEnt,int modelIndex,float life,float width,float amplitude,
                 float brightness,float speed,int startFrame,float framerate,float r,float g,float b
                 )

{
  BEAM **ppBVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  BEAM *pBVar5;
  BEAM *pBVar6;
  model_t *model;
  int iVar7;
  cl_entity_t *pcVar8;
  cl_entity_t *pcVar9;
  float fVar10;
  
                    /* Unresolved local var: BEAM * pbeam@[???]
                       Unresolved local var: cl_entity_t * start@[???]
                       Unresolved local var: cl_entity_t * end@[???] */
  if (startEnt < 0) {
                    /* Unresolved local var: int client_index@[???] */
    pcVar8 = ClientDLL_GetUserEntity(-startEnt & 0xfff);
  }
  else {
    pcVar8 = cl_entities + (startEnt & 0xfff);
  }
  if (endEnt < 0) {
                    /* Unresolved local var: int client_index@[???] */
    pcVar9 = ClientDLL_GetUserEntity(-endEnt & 0xfff);
  }
  else {
    pcVar9 = cl_entities + (endEnt & 0xfff);
  }
  pBVar6 = gpActiveBeams;
  pBVar5 = gpFreeBeams;
                    /* Unresolved local var: BEAM * pbeam@[???] */
  if ((((pcVar8 != (cl_entity_t *)0x0) && (pcVar9 != (cl_entity_t *)0x0)) &&
      ((life == 0.0 || ((pcVar8->model != (model_s *)0x0 && (pcVar9->model != (model_s *)0x0))))))
     && (gpFreeBeams != (BEAM *)0x0)) {
    gpActiveBeams = gpFreeBeams;
    ppBVar1 = &gpFreeBeams->next;
    gpFreeBeams = gpFreeBeams->next;
    *ppBVar1 = pBVar6;
    pBVar5->die = (float)cl.time;
    if (-1 < modelIndex) {
                    /* Unresolved local var: model_t * sprite@[???] */
      model = CL_GetModelByIndex(modelIndex);
      if (model != (model_t *)0x0) {
        pBVar5->type = 0;
        pBVar5->modelIndex = modelIndex;
        pBVar5->frame = 0.0;
        pBVar5->frameRate = 0.0;
        iVar7 = ModelFrameCount(model);
        vVar2 = vec3_origin[0];
        pBVar5->frameCount = iVar7;
        pBVar5->source[0] = vVar2;
        vVar3 = vec3_origin[1];
        pBVar5->source[1] = vec3_origin[1];
        vVar4 = vec3_origin[2];
        pBVar5->source[2] = vec3_origin[2];
        pBVar5->target[0] = vVar2;
        pBVar5->target[1] = vVar3;
        pBVar5->target[2] = vVar4;
        pBVar5->delta[0] = vVar2 - vVar2;
        pBVar5->delta[1] = vVar3 - vVar3;
        pBVar5->delta[2] = vVar4 - vVar4;
        pBVar5->freq = speed * (float)cl.time;
        pBVar5->die = life + (float)cl.time;
        pBVar5->width = width;
        pBVar5->amplitude = amplitude;
        pBVar5->brightness = brightness;
        pBVar5->speed = speed;
        if (0.5 <= amplitude) {
          fVar10 = Length(pBVar5->delta);
          pBVar5->segments = (int)(fVar10 * 0.25 + 3.0);
        }
        else {
          fVar10 = Length(pBVar5->delta);
          pBVar5->segments = (int)(fVar10 * 0.075 + 3.0);
        }
        pBVar5->pFollowModel = (model_s *)0x0;
      }
      pBVar5->type = 0;
      if (life == 0.0) {
        pBVar5->flags = -0x7ffffffd;
      }
      else {
        pBVar5->flags = 3;
      }
      pBVar5->frameRate = framerate;
      pBVar5->r = r;
      pBVar5->g = g;
      pBVar5->frame = (float)startFrame;
      pBVar5->b = b;
      pBVar5->startEntity = startEnt;
      pBVar5->endEntity = endEnt;
      return pBVar5;
    }
  }
  return (BEAM *)0x0;
}


// R_BeamFollow  @ 0019cee0
BEAM * R_BeamFollow(int startEnt,int modelIndex,float life,float width,float r,float g,float b,
                   float brightness)

{
  BEAM **ppBVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  BEAM *pBVar5;
  BEAM *pBVar6;
  model_t *model;
  int iVar7;
  float fVar8;
  
  pBVar6 = gpActiveBeams;
                    /* Unresolved local var: BEAM * pbeam@[???] */
  pBVar5 = gpFreeBeams;
                    /* Unresolved local var: BEAM * pbeam@[???] */
  if (gpFreeBeams != (BEAM *)0x0) {
    gpActiveBeams = gpFreeBeams;
    ppBVar1 = &gpFreeBeams->next;
    gpFreeBeams = gpFreeBeams->next;
    *ppBVar1 = pBVar6;
    pBVar5->die = (float)cl.time;
    if (-1 < modelIndex) {
                    /* Unresolved local var: model_t * sprite@[???] */
      model = CL_GetModelByIndex(modelIndex);
      if (model != (model_t *)0x0) {
        pBVar5->type = 0;
        pBVar5->modelIndex = modelIndex;
        pBVar5->frame = 0.0;
        pBVar5->frameRate = 0.0;
        iVar7 = ModelFrameCount(model);
        vVar2 = vec3_origin[0];
        pBVar5->frameCount = iVar7;
        pBVar5->source[0] = vVar2;
        vVar3 = vec3_origin[1];
        pBVar5->source[1] = vec3_origin[1];
        vVar4 = vec3_origin[2];
        pBVar5->source[2] = vec3_origin[2];
        pBVar5->target[0] = vVar2;
        pBVar5->target[1] = vVar3;
        pBVar5->target[2] = vVar4;
        pBVar5->delta[0] = vVar2 - vVar2;
        pBVar5->delta[1] = vVar3 - vVar3;
        pBVar5->delta[2] = vVar4 - vVar4;
        pBVar5->freq = (float)cl.time;
        pBVar5->die = life + (float)cl.time;
        pBVar5->width = width;
        pBVar5->amplitude = life;
        pBVar5->brightness = brightness;
        pBVar5->speed = 1.0;
        if (0.5 <= life) {
          fVar8 = Length(pBVar5->delta);
          pBVar5->segments = (int)(fVar8 * 0.25 + 3.0);
        }
        else {
          fVar8 = Length(pBVar5->delta);
          pBVar5->segments = (int)(fVar8 * 0.075 + 3.0);
        }
        pBVar5->pFollowModel = (model_s *)0x0;
      }
      pBVar5->r = r;
      pBVar5->g = g;
      pBVar5->b = b;
      pBVar5->startEntity = startEnt;
      pBVar5->type = 0x16;
      pBVar5->flags = 1;
      pBVar5->frame = 0.0;
      pBVar5->frameRate = 1.0;
      return pBVar5;
    }
  }
  return (BEAM *)0x0;
}


// R_BeamGetAttachmentPoint  @ 0019c490
float * R_BeamGetAttachmentPoint(cl_entity_t *ent,int attachment)

{
  uint uVar1;
  vec_t *pvVar2;
  
                    /* Unresolved local var: int attach@[???] */
  if (attachment < 0) {
    attachment = -attachment;
  }
  uVar1 = attachment >> 0xc & 0xf;
  if (uVar1 == 0) {
                    /* Unresolved local var: int attach@[???] */
    pvVar2 = ent->origin;
    if (ent->index == cl.playernum + 1) {
      pvVar2 = cl.simorg;
    }
    return pvVar2;
  }
  return ent->angles + uVar1 * 3;
}


// R_BeamInit  @ 00199920
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_BeamInit(void)

{
  gBeams = Hunk_AllocName(0x3e00,"lightning");
  return;
}


// R_BeamKill  @ 0019d410
void R_BeamKill(int deadEntity)

{
  BEAM *pBVar1;
  uint uVar2;
  
  pBVar1 = gpActiveBeams;
  do {
    if (pBVar1 == (BEAM *)0x0) {
      return;
    }
    while( true ) {
      uVar2 = pBVar1->flags;
      if (((uVar2 & 1) != 0) && (pBVar1->startEntity == deadEntity)) {
        uVar2 = uVar2 & 0x7ffffffe;
        pBVar1->flags = uVar2;
        if (pBVar1->type != 0x16) {
          pBVar1->die = (float)cl.time;
        }
      }
      if (((uVar2 & 2) != 0) && (deadEntity == pBVar1->endEntity)) break;
      pBVar1 = pBVar1->next;
      if (pBVar1 == (BEAM *)0x0) {
        return;
      }
    }
    pBVar1->flags = uVar2 & 0x7ffffffd;
    pBVar1->die = (float)cl.time;
    pBVar1 = pBVar1->next;
  } while( true );
}


// R_BeamLightning  @ 0019c110
BEAM * R_BeamLightning(vec_t *start,vec_t *end,int modelIndex,float life,float width,float amplitude
                      ,float brightness,float speed)

{
  BEAM **ppBVar1;
  BEAM *pBVar2;
  BEAM *pBVar3;
  model_t *model;
  int iVar4;
  float fVar5;
  
  pBVar3 = gpActiveBeams;
                    /* Unresolved local var: BEAM * pbeam@[???] */
  pBVar2 = gpFreeBeams;
                    /* Unresolved local var: BEAM * pbeam@[???] */
  if (gpFreeBeams != (BEAM *)0x0) {
    gpActiveBeams = gpFreeBeams;
    ppBVar1 = &gpFreeBeams->next;
    gpFreeBeams = gpFreeBeams->next;
    *ppBVar1 = pBVar3;
    pBVar2->die = (float)cl.time;
    if (-1 < modelIndex) {
                    /* Unresolved local var: model_t * sprite@[???] */
      model = CL_GetModelByIndex(modelIndex);
      if (model != (model_t *)0x0) {
        pBVar2->type = 0;
        pBVar2->modelIndex = modelIndex;
        pBVar2->frame = 0.0;
        pBVar2->frameRate = 0.0;
        iVar4 = ModelFrameCount(model);
        pBVar2->frameCount = iVar4;
        pBVar2->source[0] = *start;
        pBVar2->source[1] = start[1];
        pBVar2->source[2] = start[2];
        pBVar2->target[0] = *end;
        pBVar2->target[1] = end[1];
        pBVar2->target[2] = end[2];
        pBVar2->delta[0] = *end - *start;
        pBVar2->delta[1] = end[1] - start[1];
        pBVar2->delta[2] = end[2] - start[2];
        pBVar2->freq = speed * (float)cl.time;
        pBVar2->die = life + (float)cl.time;
        pBVar2->width = width;
        pBVar2->amplitude = amplitude;
        pBVar2->brightness = brightness;
        pBVar2->speed = speed;
        if (0.5 <= amplitude) {
          fVar5 = Length(pBVar2->delta);
          pBVar2->segments = (int)(fVar5 * 0.25 + 3.0);
        }
        else {
          fVar5 = Length(pBVar2->delta);
          pBVar2->segments = (int)(fVar5 * 0.075 + 3.0);
        }
        pBVar2->flags = 0;
        pBVar2->pFollowModel = (model_s *)0x0;
      }
      return pBVar2;
    }
  }
  return (BEAM *)0x0;
}


// R_BeamPoints  @ 0019c9f0
BEAM * R_BeamPoints(vec_t *start,vec_t *end,int modelIndex,float life,float width,float amplitude,
                   float brightness,float speed,int startFrame,float framerate,float r,float g,
                   float b)

{
  BEAM **ppBVar1;
  BEAM *pBVar2;
  BEAM *pBVar3;
  model_t *model;
  int iVar4;
  mnode_t *pmVar5;
  float fVar6;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: BEAM * pbeam@[???] */
  if (life != 0.0) {
                    /* Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: int i@[???] */
    if (cl.worldmodel == (model_s *)0x0) {
      return (BEAM *)0x0;
    }
    fVar6 = *start;
    local_28 = *end;
    local_34 = fVar6;
    if (local_28 <= fVar6) {
      local_34 = local_28;
      local_28 = fVar6;
    }
    if (local_28 == local_34) {
      local_28 = local_28 + 1.0;
    }
    fVar6 = start[1];
    local_24 = end[1];
    local_30 = fVar6;
    if (local_24 <= fVar6) {
      local_30 = local_24;
      local_24 = fVar6;
    }
    if (local_30 == local_24) {
      local_24 = local_24 + 1.0;
    }
    fVar6 = start[2];
    local_20 = end[2];
    local_2c = fVar6;
    if (local_20 <= fVar6) {
      local_2c = local_20;
      local_20 = fVar6;
    }
    if (local_2c == local_20) {
      local_20 = local_20 + 1.0;
    }
    pmVar5 = PVSNode((cl.worldmodel)->nodes,&local_34,&local_28);
    if (pmVar5 == (mnode_t *)0x0) {
      return (BEAM *)0x0;
    }
  }
                    /* Unresolved local var: BEAM * pbeam@[???] */
  pBVar3 = gpActiveBeams;
  pBVar2 = gpFreeBeams;
  if (gpFreeBeams != (BEAM *)0x0) {
    gpActiveBeams = gpFreeBeams;
    ppBVar1 = &gpFreeBeams->next;
    gpFreeBeams = gpFreeBeams->next;
    *ppBVar1 = pBVar3;
    pBVar2->die = (float)cl.time;
    if (-1 < modelIndex) {
                    /* Unresolved local var: model_t * sprite@[???] */
      model = CL_GetModelByIndex(modelIndex);
      if (model != (model_t *)0x0) {
        pBVar2->type = 0;
        pBVar2->modelIndex = modelIndex;
        pBVar2->frame = 0.0;
        pBVar2->frameRate = 0.0;
        iVar4 = ModelFrameCount(model);
        pBVar2->frameCount = iVar4;
        pBVar2->source[0] = *start;
        pBVar2->source[1] = start[1];
        pBVar2->source[2] = start[2];
        pBVar2->target[0] = *end;
        pBVar2->target[1] = end[1];
        pBVar2->target[2] = end[2];
        pBVar2->delta[0] = *end - *start;
        pBVar2->delta[1] = end[1] - start[1];
        pBVar2->delta[2] = end[2] - start[2];
        pBVar2->freq = speed * (float)cl.time;
        pBVar2->die = life + (float)cl.time;
        pBVar2->width = width;
        pBVar2->amplitude = amplitude;
        pBVar2->brightness = brightness;
        pBVar2->speed = speed;
        if (0.5 <= amplitude) {
          fVar6 = Length(pBVar2->delta);
          pBVar2->segments = (int)(fVar6 * 0.25 + 3.0);
        }
        else {
          fVar6 = Length(pBVar2->delta);
          pBVar2->segments = (int)(fVar6 * 0.075 + 3.0);
        }
        pBVar2->flags = 0;
        pBVar2->pFollowModel = (model_s *)0x0;
      }
      if (life == 0.0) {
        pBVar2->flags = pBVar2->flags | 0x80000000;
      }
      pBVar2->frameRate = framerate;
      pBVar2->r = r;
      pBVar2->g = g;
      pBVar2->frame = (float)startFrame;
      pBVar2->b = b;
      return pBVar2;
    }
  }
  return (BEAM *)0x0;
}


// R_BeamRing  @ 0019d090
BEAM * R_BeamRing(int startEnt,int endEnt,int modelIndex,float life,float width,float amplitude,
                 float brightness,float speed,int startFrame,float framerate,float r,float g,float b
                 )

{
  BEAM **ppBVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  BEAM *pBVar5;
  BEAM *pBVar6;
  model_t *model;
  int iVar7;
  cl_entity_t *pcVar8;
  cl_entity_t *pcVar9;
  float fVar10;
  
                    /* Unresolved local var: BEAM * pbeam@[???]
                       Unresolved local var: cl_entity_t * start@[???]
                       Unresolved local var: cl_entity_t * end@[???] */
  if (startEnt < 0) {
                    /* Unresolved local var: int client_index@[???] */
    pcVar8 = ClientDLL_GetUserEntity(-startEnt & 0xfff);
  }
  else {
    pcVar8 = cl_entities + (startEnt & 0xfff);
  }
  if (endEnt < 0) {
                    /* Unresolved local var: int client_index@[???] */
    pcVar9 = ClientDLL_GetUserEntity(-endEnt & 0xfff);
  }
  else {
    pcVar9 = cl_entities + (endEnt & 0xfff);
  }
  pBVar6 = gpActiveBeams;
  pBVar5 = gpFreeBeams;
                    /* Unresolved local var: BEAM * pbeam@[???] */
  if ((((pcVar8 != (cl_entity_t *)0x0) && (pcVar9 != (cl_entity_t *)0x0)) &&
      ((life == 0.0 || ((pcVar8->model != (model_s *)0x0 && (pcVar9->model != (model_s *)0x0))))))
     && (gpFreeBeams != (BEAM *)0x0)) {
    gpActiveBeams = gpFreeBeams;
    ppBVar1 = &gpFreeBeams->next;
    gpFreeBeams = gpFreeBeams->next;
    *ppBVar1 = pBVar6;
    pBVar5->die = (float)cl.time;
    if (-1 < modelIndex) {
                    /* Unresolved local var: model_t * sprite@[???] */
      model = CL_GetModelByIndex(modelIndex);
      if (model != (model_t *)0x0) {
        pBVar5->type = 0;
        pBVar5->modelIndex = modelIndex;
        pBVar5->frame = 0.0;
        pBVar5->frameRate = 0.0;
        iVar7 = ModelFrameCount(model);
        vVar2 = vec3_origin[0];
        pBVar5->frameCount = iVar7;
        pBVar5->source[0] = vVar2;
        vVar3 = vec3_origin[1];
        pBVar5->source[1] = vec3_origin[1];
        vVar4 = vec3_origin[2];
        pBVar5->source[2] = vec3_origin[2];
        pBVar5->target[0] = vVar2;
        pBVar5->target[1] = vVar3;
        pBVar5->target[2] = vVar4;
        pBVar5->delta[0] = vVar2 - vVar2;
        pBVar5->delta[1] = vVar3 - vVar3;
        pBVar5->delta[2] = vVar4 - vVar4;
        pBVar5->freq = speed * (float)cl.time;
        pBVar5->die = life + (float)cl.time;
        pBVar5->width = width;
        pBVar5->amplitude = amplitude;
        pBVar5->brightness = brightness;
        pBVar5->speed = speed;
        if (0.5 <= amplitude) {
          fVar10 = Length(pBVar5->delta);
          pBVar5->segments = (int)(fVar10 * 0.25 + 3.0);
        }
        else {
          fVar10 = Length(pBVar5->delta);
          pBVar5->segments = (int)(fVar10 * 0.075 + 3.0);
        }
        pBVar5->pFollowModel = (model_s *)0x0;
      }
      pBVar5->type = 0x18;
      if (life == 0.0) {
        pBVar5->flags = -0x7ffffffd;
      }
      else {
        pBVar5->flags = 3;
      }
      pBVar5->frameRate = framerate;
      pBVar5->r = r;
      pBVar5->g = g;
      pBVar5->frame = (float)startFrame;
      pBVar5->b = b;
      pBVar5->startEntity = startEnt;
      pBVar5->endEntity = endEnt;
      return pBVar5;
    }
  }
  return (BEAM *)0x0;
}


// R_BeamSetup  @ 0019c2b0
void R_BeamSetup(BEAM *pbeam,vec_t *start,vec_t *end,int modelIndex,float life,float width,
                float amplitude,float brightness,float speed)

{
  model_t *model;
  int iVar1;
  float fVar2;
  
                    /* Unresolved local var: model_t * sprite@[???] */
  model = CL_GetModelByIndex(modelIndex);
  if (model != (model_t *)0x0) {
    pbeam->type = 0;
    pbeam->modelIndex = modelIndex;
    pbeam->frame = 0.0;
    pbeam->frameRate = 0.0;
    iVar1 = ModelFrameCount(model);
    pbeam->frameCount = iVar1;
    pbeam->source[0] = *start;
    pbeam->source[1] = start[1];
    pbeam->source[2] = start[2];
    pbeam->target[0] = *end;
    pbeam->target[1] = end[1];
    pbeam->target[2] = end[2];
    pbeam->delta[0] = *end - *start;
    pbeam->delta[1] = end[1] - start[1];
    pbeam->delta[2] = end[2] - start[2];
    pbeam->freq = speed * (float)cl.time;
    pbeam->die = life + (float)cl.time;
    pbeam->width = width;
    pbeam->amplitude = amplitude;
    pbeam->brightness = brightness;
    pbeam->speed = speed;
    if (0.5 <= amplitude) {
      fVar2 = Length(pbeam->delta);
      pbeam->segments = (int)(fVar2 * 0.25 + 3.0);
    }
    else {
      fVar2 = Length(pbeam->delta);
      pbeam->segments = (int)(fVar2 * 0.075 + 3.0);
    }
    pbeam->flags = 0;
    pbeam->pFollowModel = (model_s *)0x0;
  }
  return;
}


// R_BlendLightmaps  @ 00098df5
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_BlendLightmaps(void)

{
  glpoly_s **ppgVar1;
  int iVar2;
  glpoly_t *p;
  float (*pafVar3) [7];
  int iVar4;
  glpoly_s *pgVar5;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: glpoly_t * p@[???]
                       Unresolved local var: float * v@[???] */
  (*qglDepthMask)('\0');
  if (gl_lightmap_format == 0x1909) {
    (*qglBlendFunc)(0,0x301);
  }
  else if (((gl_lightmap_format == 0x8049) || (gl_lightmap_format != 0x1908)) ||
          (gl_monolights.value != 0.0)) {
    (*qglTexEnvf)(0x2300,0x2200,8448.0);
    (*qglColor4f)(0.0,0.0,0.0,1.0);
    (*qglBlendFunc)(0x302,0x303);
  }
  else {
    (*qglTexEnvf)(0x2300,0x2200,8448.0);
    if (gl_overbright.value == 0.0) {
      (*qglBlendFunc)(0,0x300);
    }
    else {
      (*qglBlendFunc)(0x306,0x300);
      (*qglColor4f)(0.6666667,0.6666667,0.6666667,1.0);
    }
  }
  if (r_lightmap.value == 0.0) {
    (*qglEnable)(0xbe2);
  }
  iVar4 = 0;
  do {
    p = lightmap_polys[iVar4];
    if (p != (glpoly_t *)0x0) {
      GL_Bind(lightmap_textures[iVar4]);
      (*qglTexParameterf)(0xde1,0x2801,9729.0);
      (*qglTexParameterf)(0xde1,0x2800,9729.0);
      iVar2 = lightmap_bytes;
      if (lightmap_modified[iVar4] != false) {
        lightmap_modified[iVar4] = false;
        (*qglTexSubImage2D)(0xde1,0,0,0,0x80,0x80,gl_lightmap_format,0x1401,
                            lightmaps + iVar2 * iVar4 * 0x4000);
      }
      do {
        if ((p->flags & 0x80U) == 0) {
          pgVar5 = p;
          if ((p->flags & 0x10U) == 0) {
            (*qglBegin)(9);
            pafVar3 = p->verts;
            for (iVar2 = 0; iVar2 < p->numverts; iVar2 = iVar2 + 1) {
              (*qglTexCoord2f)((*pafVar3)[5],(*pafVar3)[6]);
              (*qglVertex3fv)(*pafVar3);
              pafVar3 = pafVar3 + 1;
            }
            (*qglEnd)();
          }
          else {
            do {
                    /* Unresolved local var: float[3] tempVert@[???]
                       Unresolved local var: glpoly_t * wp@[???] */
              (*qglBegin)(9);
              (*qglColor3f)(1.0,1.0,1.0);
              pafVar3 = pgVar5->verts;
              for (iVar2 = 0; iVar2 < pgVar5->numverts; iVar2 = iVar2 + 1) {
                (*qglTexCoord2f)((*pafVar3)[5],(*pafVar3)[6]);
                local_28 = (*pafVar3)[0];
                local_24 = (*pafVar3)[1];
                local_20 = gl_wateramp.value * 0.8 *
                           turbsin[(int)((local_28 * 5.0 + (float)cl.time * 171.0) - local_24) &
                                   0xff] +
                           gl_wateramp.value *
                           turbsin[(int)((float)cl.time * 160.0 + local_28 + local_24) & 0xff] +
                           (*pafVar3)[2];
                (*qglVertex3fv)(&local_28);
                pafVar3 = pafVar3 + 1;
              }
              (*qglEnd)();
              ppgVar1 = &pgVar5->next;
              pgVar5 = *ppgVar1;
            } while (*ppgVar1 != (glpoly_s *)0x0);
          }
        }
        else {
          DrawGLWaterPolyLightmap(p);
        }
        p = p->chain;
      } while (p != (glpoly_s *)0x0);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0x40);
  (*qglDisable)(0xbe2);
  if (gl_lightmap_format == 0x1909) {
    (*qglBlendFunc)(0x302,0x303);
  }
  else if ((gl_lightmap_format == 0x8049) || (gl_monolights.value != 0.0)) {
    (*qglTexEnvf)(0x2300,0x2200,7681.0);
    (*qglColor4f)(1.0,1.0,1.0,1.0);
  }
  (*qglDepthMask)('\x01');
  return;
}


// R_BlendLightmaps  @ 00191690
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_BlendLightmaps(void)

{
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: glpoly_t * p@[???]
                       Unresolved local var: float * v@[???] */
  if (((filterMode == false) && (r_fullbright.value == 0.0)) && (gl_texsort != false)) {
    R_BlendLightmaps();
    return;
  }
  return;
}


// R_BlobExplosion  @ 0019a400
void R_BlobExplosion(vec_t *org)

{
  particle_s **pppVar1;
  double dVar2;
  particle_t *ppVar3;
  particle_t *ppVar4;
  int32 iVar5;
  int iVar6;
  uint uVar7;
  float fVar8;
  float fVar9;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: particle_t * p@[???] */
  uVar7 = 0;
  do {
    while( true ) {
      ppVar4 = free_particles;
      ppVar3 = active_particles;
      if (free_particles == (particle_t *)0x0) {
        return;
      }
      active_particles = free_particles;
      pppVar1 = &free_particles->next;
      free_particles = free_particles->next;
      *pppVar1 = ppVar3;
      dVar2 = cl.time;
      fVar8 = RandomFloat(1.0,1.4);
      ppVar4->die = (float)dVar2 + fVar8;
      if ((uVar7 & 1) != 0) break;
      iVar6 = 0;
      ppVar4->type = pt_blob2;
      iVar5 = RandomLong(0x96,0x9b);
      ppVar4->packedColor = 0;
      ppVar4->color = (short)iVar5;
      do {
        fVar8 = org[iVar6];
                    /* try { // try from 0019a522 to 001aa55b has its CatchHandler @ 0019a2d0 */
        fVar9 = RandomFloat(-16.0,16.0);
        ppVar4->org[iVar6] = fVar9 + fVar8;
        fVar8 = RandomFloat(-256.0,256.0);
        ppVar4->vel[iVar6] = fVar8;
        iVar6 = iVar6 + 1;
      } while (iVar6 != 3);
      uVar7 = uVar7 + 1;
      if (uVar7 == 0x400) {
        return;
      }
    }
    iVar6 = 0;
    ppVar4->type = pt_blob;
    iVar5 = RandomLong(0x42,0x47);
    ppVar4->packedColor = 0;
    ppVar4->color = (short)iVar5;
    do {
      fVar8 = org[iVar6];
      fVar9 = RandomFloat(-16.0,16.0);
      ppVar4->org[iVar6] = fVar9 + fVar8;
      fVar8 = RandomFloat(-256.0,256.0);
                    /* try { // try from 0019a4c6 to 001aa4ca has its CatchHandler @ 0019a5e4 */
      ppVar4->vel[iVar6] = fVar8;
      iVar6 = iVar6 + 1;
    } while (iVar6 != 3);
    uVar7 = uVar7 + 1;
  } while (uVar7 != 0x400);
  return;
}


// R_Blood  @ 0019b8c0
void R_Blood(vec_t *org,vec_t *dir,int pcolor,int speed)

{
  particle_s **pppVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  particle_t *ppVar5;
  particle_t *ppVar6;
  int32 iVar7;
  int iVar8;
  vec_t *out;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  int local_4c;
  int local_3c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: vec3_t dirCopy@[???]
                       Unresolved local var: vec3_t orgCopy@[???]
                       Unresolved local var: float arc@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int count2@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: int pspeed@[???] */
  local_4c = speed * 3;
  VectorNormalize(dir);
  local_3c = 0;
  if (0 < speed / 2) {
    do {
      iVar8 = 8;
      fVar2 = *org;
      fVar9 = RandomFloat(-3.0,3.0);
      fVar3 = org[1];
      fVar10 = RandomFloat(-3.0,3.0);
      fVar4 = org[2];
      fVar11 = RandomFloat(-3.0,3.0);
      fVar12 = *dir;
      local_28 = RandomFloat(-0.06,0.06);
      local_28 = local_28 + fVar12;
      fVar12 = dir[1];
      local_24 = RandomFloat(-0.06,0.06);
      local_24 = local_24 + fVar12;
      fVar12 = dir[2];
      local_20 = RandomFloat(-0.06,0.06);
      local_20 = local_20 + fVar12;
      do {
        ppVar6 = free_particles;
        ppVar5 = active_particles;
        if (free_particles == (particle_t *)0x0) {
          return;
        }
        active_particles = free_particles;
        out = free_particles->vel;
        pppVar1 = &free_particles->next;
        free_particles = free_particles->next;
        *pppVar1 = ppVar5;
        ppVar6->die = (float)cl.time + 1.5;
        iVar7 = RandomLong(0,9);
        ppVar6->packedColor = 0;
        ppVar6->type = pt_vox_grav;
        ppVar6->color = (short)iVar7 + (short)pcolor;
        fVar12 = RandomFloat(-1.0,1.0);
        ppVar6->org[0] = fVar12 + fVar9 + fVar2;
        fVar12 = RandomFloat(-1.0,1.0);
        ppVar6->org[1] = fVar12 + fVar10 + fVar3;
        fVar12 = RandomFloat(-1.0,1.0);
        ppVar6->org[2] = fVar12 + fVar11 + fVar4;
        VectorScale(&local_28,(float)local_4c,out);
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      local_3c = local_3c + 1;
      local_4c = local_4c - speed;
    } while (speed / 2 != local_3c);
  }
  return;
}


// R_BloodSprite  @ 0014ed60
void R_BloodSprite(vec_t *org,int colorindex,int modelIndex,int modelIndex2,float size)

{
  word wVar1;
  word wVar2;
  word wVar3;
  word wVar4;
  word wVar5;
  word wVar6;
  double dVar7;
  int32 iVar8;
  int iVar9;
  model_t *pmVar10;
  TEMPENTITY *pTVar11;
  int32 iVar12;
  int iVar13;
  int iVar14;
  float fVar15;
  byte local_38;
  byte local_34;
  byte local_30;
  byte local_2c;
  byte local_28;
  byte local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int splatter@[???]
                       Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: model_t * model@[???]
                       Unresolved local var: model_t * model2@[???]
                       Unresolved local var: int frameCount@[???]
                       Unresolved local var: int frameCount2@[???]
                       Unresolved local var: uint impactindex@[???]
                       Unresolved local var: uint spatterindex@[???]
                       Unresolved local var: color24 impactcolor@[???]
                       Unresolved local var: color24 splattercolor@[???] */
  iVar8 = RandomLong(1,3);
  iVar9 = iVar8 + colorindex;
  wVar1 = host_basepal[iVar9 * 4 + 2];
  wVar2 = host_basepal[iVar9 * 4 + 1];
  wVar3 = host_basepal[iVar9 * 4];
  if (modelIndex2 != 0) {
    wVar4 = host_basepal[iVar9 * 4 + -2];
    wVar5 = host_basepal[iVar9 * 4 + -3];
    wVar6 = host_basepal[iVar9 * 4 + -4];
    pmVar10 = CL_GetModelByIndex(modelIndex2);
    if (pmVar10 != (model_t *)0x0) {
      iVar9 = ModelFrameCount(pmVar10);
      iVar8 = RandomLong(1,8);
      iVar12 = RandomLong(1,8);
      iVar14 = (int)((float)(iVar12 + iVar8) + size);
      if (0 < iVar14) {
        iVar13 = 0;
        do {
          pTVar11 = (*efx.CL_TempEntAlloc)(org,pmVar10);
          if (pTVar11 != (TEMPENTITY *)0x0) {
            (pTVar11->entity).curstate.rendermode = 0;
            (pTVar11->entity).curstate.renderfx = 0x14;
            (pTVar11->entity).baseline.renderamt = 0xfa;
            (pTVar11->entity).curstate.renderamt = 0xfa;
            fVar15 = RandomFloat(size / 15.0,size / 25.0);
            local_38 = (byte)wVar4;
            pTVar11->flags = 0x2c;
            (pTVar11->entity).curstate.rendercolor.r = local_38;
            local_34 = (byte)wVar5;
            (pTVar11->entity).curstate.scale = fVar15;
            (pTVar11->entity).curstate.rendercolor.g = local_34;
            local_30 = (byte)wVar6;
            (pTVar11->entity).curstate.rendercolor.b = local_30;
            fVar15 = RandomFloat(-96.0,95.0);
            (pTVar11->entity).baseline.origin[0] = fVar15;
            fVar15 = RandomFloat(-96.0,95.0);
            (pTVar11->entity).baseline.origin[1] = fVar15;
            fVar15 = RandomFloat(-32.0,95.0);
            (pTVar11->entity).baseline.origin[2] = fVar15;
            fVar15 = RandomFloat(-256.0,-255.0);
            (pTVar11->entity).baseline.angles[0] = fVar15;
            fVar15 = RandomFloat(-256.0,-255.0);
            (pTVar11->entity).baseline.angles[1] = fVar15;
            fVar15 = RandomFloat(-256.0,-255.0);
            (pTVar11->entity).curstate.framerate = 0.0;
            (pTVar11->entity).baseline.angles[2] = fVar15;
            dVar7 = cl.time;
            fVar15 = RandomFloat(1.0,2.0);
            pTVar11->die = (float)dVar7 + fVar15;
            iVar8 = RandomLong(1,iVar9 + -1);
            fVar15 = (float)iVar8;
            if (8.0 < fVar15) {
              fVar15 = (float)(iVar9 + -1);
            }
            (pTVar11->entity).curstate.frame = fVar15;
            iVar8 = RandomLong(0,0x168);
            pTVar11->bounceFactor = 0.0;
            (pTVar11->entity).angles[2] = (float)iVar8;
          }
          iVar13 = iVar13 + 1;
        } while (iVar14 != iVar13);
      }
    }
  }
  if ((modelIndex != 0) && (pmVar10 = CL_GetModelByIndex(modelIndex), pmVar10 != (model_t *)0x0)) {
    iVar9 = ModelFrameCount(pmVar10);
    pTVar11 = (*efx.CL_TempEntAllocHigh)(org,pmVar10);
    if (pTVar11 != (TEMPENTITY *)0x0) {
      (pTVar11->entity).curstate.rendermode = 0;
      (pTVar11->entity).curstate.renderfx = 0x14;
      (pTVar11->entity).baseline.renderamt = 0xfa;
      (pTVar11->entity).curstate.renderamt = 0xfa;
      fVar15 = RandomFloat(size / 25.0,size / 35.0);
      local_2c = (byte)wVar1;
      pTVar11->flags = 0x100;
      (pTVar11->entity).baseline.origin[0] = 0.0;
      (pTVar11->entity).baseline.origin[1] = 0.0;
      (pTVar11->entity).curstate.rendercolor.r = local_2c;
      local_28 = (byte)wVar2;
      (pTVar11->entity).baseline.origin[2] = 0.0;
      (pTVar11->entity).curstate.scale = fVar15;
      (pTVar11->entity).curstate.rendercolor.g = local_28;
      local_24 = (byte)wVar3;
      (pTVar11->entity).curstate.rendercolor.b = local_24;
      (pTVar11->entity).curstate.framerate = (float)(iVar9 * 4);
      pTVar11->die = (float)iVar9 / (float)(iVar9 * 4) + (float)cl.time;
      pTVar11->frameMax = (float)iVar9;
      (pTVar11->entity).curstate.frame = 0.0;
      iVar8 = RandomLong(0,0x168);
      pTVar11->bounceFactor = 0.0;
      (pTVar11->entity).angles[2] = (float)iVar8;
      return;
    }
  }
  return;
}


// R_BloodStream  @ 0019b4d0
void R_BloodStream(vec_t *org,vec_t *dir,int pcolor,int speed)

{
  particle_s **pppVar1;
  float fVar2;
  short sVar3;
  particle_t *ppVar4;
  int32 iVar5;
  int iVar6;
  vec_t *pvVar7;
  particle_t *ppVar8;
  float fVar9;
  float fVar10;
  float local_5c;
  float local_50;
  int local_48;
  int local_40;
  int local_3c;
  vec_t local_28;
  vec_t local_24;
  float local_20;
  
                    /* Unresolved local var: vec3_t dirCopy@[???]
                       Unresolved local var: float arc@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int count2@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: float num@[???]
                       Unresolved local var: int speedCopy@[???] */
  VectorNormalize(dir);
  local_48 = 100;
  local_50 = 0.05;
  iVar6 = speed;
  do {
    ppVar4 = free_particles;
    ppVar8 = active_particles;
    if (free_particles == (particle_t *)0x0) {
      return;
    }
    active_particles = free_particles;
    pvVar7 = free_particles->vel;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar8;
    ppVar4->die = (float)cl.time + 2.0;
    iVar5 = RandomLong(0,9);
    ppVar4->packedColor = 0;
    ppVar4->type = pt_vox_grav;
    sVar3 = (short)pcolor;
    ppVar4->color = (short)iVar5 + sVar3;
    ppVar4->org[0] = *org;
    ppVar4->org[1] = org[1];
    ppVar4->org[2] = org[2];
    local_20 = dir[2] - local_50;
    local_28 = *dir;
    local_24 = dir[1];
    local_50 = local_50 - 0.005;
    VectorScale(&local_28,(float)iVar6,pvVar7);
    local_48 = local_48 + -1;
    iVar6 = (int)((double)iVar6 - 1e-05);
  } while (local_48 != 0);
  if ((0 < speed / 5) && (free_particles != (particle_t *)0x0)) {
    local_40 = 0;
    local_5c = 0.075;
    ppVar8 = free_particles;
    do {
      free_particles = ppVar8->next;
      ppVar4 = ppVar8;
      ppVar8->next = active_particles;
      active_particles = ppVar4;
      ppVar8->die = (float)cl.time + 3.0;
      iVar5 = RandomLong(0,9);
      ppVar8->packedColor = 0;
      ppVar8->type = pt_vox_slowgrav;
      ppVar8->color = (short)iVar5 + sVar3;
      ppVar8->org[0] = *org;
      ppVar8->org[1] = org[1];
      ppVar8->org[2] = org[2];
      local_20 = dir[2] - local_5c;
      local_28 = *dir;
      local_24 = dir[1];
      local_5c = local_5c - 0.005;
      fVar10 = RandomFloat(0.0,1.0);
      VectorScale(&local_28,fVar10 * 1.7,&local_28);
      VectorScale(&local_28,(float)(int)(fVar10 * (float)speed),ppVar8->vel);
      local_3c = 2;
      do {
        ppVar4 = free_particles;
        ppVar8 = active_particles;
        if (free_particles == (particle_t *)0x0) {
          return;
        }
        active_particles = free_particles;
        pvVar7 = free_particles->vel;
        pppVar1 = &free_particles->next;
        free_particles = free_particles->next;
        *pppVar1 = ppVar8;
        ppVar4->die = (float)cl.time + 3.0;
        iVar5 = RandomLong(0,9);
        ppVar4->packedColor = 0;
        ppVar4->type = pt_vox_slowgrav;
        ppVar4->color = (short)iVar5 + sVar3;
        fVar2 = *org;
        fVar9 = RandomFloat(-1.0,1.0);
        ppVar4->org[0] = fVar9 + fVar2;
        fVar2 = org[1];
        fVar9 = RandomFloat(-1.0,1.0);
        ppVar4->org[1] = fVar9 + fVar2;
        fVar2 = org[2];
        fVar9 = RandomFloat(-1.0,1.0);
        ppVar4->org[2] = fVar9 + fVar2;
        local_20 = dir[2] - local_5c;
        local_28 = *dir;
        local_24 = dir[1];
        VectorScale(&local_28,fVar10 * 1.7,&local_28);
        VectorScale(&local_28,(float)(int)(fVar10 * (float)speed),pvVar7);
        local_3c = local_3c + -1;
      } while (local_3c != 0);
      local_40 = local_40 + 1;
    } while ((local_40 != speed / 5) &&
            (ppVar8 = free_particles, free_particles != (particle_t *)0x0));
  }
  return;
}


// R_BreakModel  @ 0014d290
void R_BreakModel(float *pos,float *size,float *dir,float random,float life,int count,int modelIndex
                 ,char flags)

{
  int iVar1;
  model_t *model;
  int iVar2;
  int iVar3;
  TEMPENTITY *pTVar4;
  int32 iVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int frameCount@[???]
                       Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: model_t * pModel@[???]
                       Unresolved local var: char type@[???] */
  if ((modelIndex != 0) && (model = CL_GetModelByIndex(modelIndex), model != (model_t *)0x0)) {
    iVar2 = ModelFrameCount(model);
    if (count == 0) {
      count = (int)((*size * size[2] + size[1] * size[2] + *size * size[1]) / 432.0);
    }
    iVar3 = 100;
    if (count < 0x65) {
      iVar3 = count;
    }
    if (0 < iVar3) {
                    /* Unresolved local var: vec3_t vecSpot@[???] */
      iVar1 = 0;
      do {
        fVar9 = *pos;
        fVar8 = RandomFloat(-0.5,0.5);
        local_28 = fVar8 * *size + fVar9;
        fVar9 = pos[1];
        fVar8 = RandomFloat(-0.5,0.5);
        local_24 = fVar8 * size[1] + fVar9;
        fVar9 = pos[2];
        fVar8 = RandomFloat(-0.5,0.5);
        local_20 = fVar8 * size[2] + fVar9;
        pTVar4 = (*efx.CL_TempEntAlloc)(&local_28,model);
        if (pTVar4 == (TEMPENTITY *)0x0) {
          return;
        }
        pTVar4->hitSound = (int)(char)(flags & 0x4fU);
        if (model->type == mod_sprite) {
          iVar5 = RandomLong(0,iVar2 + -1);
          (pTVar4->entity).curstate.frame = (float)iVar5;
        }
        else if (model->type == mod_studio) {
          iVar5 = RandomLong(0,iVar2 + -1);
          (pTVar4->entity).curstate.body = iVar5;
        }
        pTVar4->flags = pTVar4->flags | 0xa8;
        iVar5 = RandomLong(0,0xff);
        if (iVar5 < 200) {
          pTVar4->flags = pTVar4->flags | 4;
          fVar9 = RandomFloat(-256.0,255.0);
          (pTVar4->entity).baseline.angles[0] = fVar9;
          fVar9 = RandomFloat(-256.0,255.0);
          (pTVar4->entity).baseline.angles[1] = fVar9;
          fVar9 = RandomFloat(-256.0,255.0);
          (pTVar4->entity).baseline.angles[2] = fVar9;
        }
        iVar5 = RandomLong(0,0xff);
        if ((iVar5 < 100) && ((flags & 0x10U) != 0)) {
          pTVar4->flags = pTVar4->flags | 0x10;
        }
        if (((flags & 0x4fU) == 1) || ((flags & 0x20U) != 0)) {
          iVar7 = 0x80;
          (pTVar4->entity).curstate.renderamt = 0x80;
          iVar6 = 2;
        }
        else {
          iVar7 = 0xff;
          iVar6 = 0;
        }
        (pTVar4->entity).curstate.rendermode = iVar6;
        (pTVar4->entity).baseline.renderamt = iVar7;
        fVar9 = *dir;
        fVar8 = RandomFloat(-random,random);
        (pTVar4->entity).baseline.origin[0] = fVar8 + fVar9;
        fVar9 = dir[1];
        fVar8 = RandomFloat(-random,random);
        (pTVar4->entity).baseline.origin[1] = fVar8 + fVar9;
        fVar9 = dir[2];
        fVar8 = RandomFloat(0.0,random);
        (pTVar4->entity).baseline.origin[2] = fVar8 + fVar9;
        fVar9 = (float)cl.time;
        fVar8 = RandomFloat(0.0,1.0);
        iVar1 = iVar1 + 1;
        pTVar4->die = life + fVar9 + fVar8;
      } while (iVar1 != iVar3);
    }
  }
  return;
}


// R_BubbleTrail  @ 0014ca70
void R_BubbleTrail(vec_t *start,vec_t *end,float height,int modelIndex,int count,float speed)

{
  model_t *model;
  int iVar1;
  int32 iVar2;
  TEMPENTITY *pTVar3;
  int iVar4;
  float fVar5;
  double local_3c;
  double local_34;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: model_t * model@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int frameCount@[???]
                       Unresolved local var: float dist@[???]
                       Unresolved local var: float angle@[???]
                       Unresolved local var: vec3_t origin@[???] */
  if ((modelIndex != 0) && (model = CL_GetModelByIndex(modelIndex), model != (model_t *)0x0)) {
    iVar4 = 0;
    iVar1 = ModelFrameCount(model);
    if (0 < count) {
      do {
        fVar5 = RandomFloat(0.0,1.0);
        local_28 = (*end - *start) * fVar5 + *start;
        local_24 = (end[1] - start[1]) * fVar5 + start[1];
        local_20 = (end[2] - start[2]) * fVar5 + start[2];
        pTVar3 = (*efx.CL_TempEntAlloc)(&local_28,model);
        if (pTVar3 == (TEMPENTITY *)0x0) {
          return;
        }
        pTVar3->flags = pTVar3->flags | 1;
        iVar4 = iVar4 + 1;
        pTVar3->x = local_28;
        pTVar3->y = local_24;
        iVar2 = RandomLong(-3,3);
        sincos((double)iVar2,&local_34,&local_3c);
        (pTVar3->entity).baseline.origin[0] = (float)local_3c * speed;
        (pTVar3->entity).baseline.origin[1] = speed * (float)local_34;
        iVar2 = RandomLong(0x50,0x8c);
        (pTVar3->entity).baseline.origin[2] = (float)iVar2;
        pTVar3->die = ((height - (local_20 - start[2])) / (float)iVar2 + (float)cl.time) - 0.1;
        iVar2 = RandomLong(0,iVar1 + -1);
        (pTVar3->entity).curstate.frame = (float)iVar2;
        fVar5 = RandomFloat(2.0,5.0);
        (pTVar3->entity).curstate.rendermode = 4;
        (pTVar3->entity).curstate.renderamt = 0xff;
        (pTVar3->entity).curstate.scale = 1.0 / fVar5;
      } while (count != iVar4);
    }
  }
  return;
}


// R_Bubbles  @ 0014c880
void R_Bubbles(vec_t *mins,vec_t *maxs,float height,int modelIndex,int count,float speed)

{
  model_t *model;
  int iVar1;
  int32 iVar2;
  TEMPENTITY *pTVar3;
  int iVar4;
  float fVar5;
  double local_3c;
  double local_34;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: model_t * model@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int frameCount@[???]
                       Unresolved local var: float angle@[???]
                       Unresolved local var: vec3_t origin@[???] */
  if ((modelIndex != 0) && (model = CL_GetModelByIndex(modelIndex), model != (model_t *)0x0)) {
    iVar4 = 0;
    iVar1 = ModelFrameCount(model);
    if (0 < count) {
      do {
        iVar2 = RandomLong((int)*mins,(int)*maxs);
        local_28 = (float)iVar2;
        iVar2 = RandomLong((int)mins[1],(int)maxs[1]);
        local_24 = (float)iVar2;
        iVar2 = RandomLong((int)mins[2],(int)maxs[2]);
        local_20 = (float)iVar2;
        pTVar3 = (*efx.CL_TempEntAlloc)(&local_28,model);
        if (pTVar3 == (TEMPENTITY *)0x0) {
          return;
        }
        pTVar3->flags = pTVar3->flags | 1;
        iVar4 = iVar4 + 1;
        pTVar3->x = local_28;
        pTVar3->y = local_24;
        iVar2 = RandomLong(-3,3);
        sincos((double)iVar2,&local_34,&local_3c);
        (pTVar3->entity).baseline.origin[0] = (float)local_3c * speed;
        (pTVar3->entity).baseline.origin[1] = speed * (float)local_34;
        iVar2 = RandomLong(0x50,0x8c);
        (pTVar3->entity).baseline.origin[2] = (float)iVar2;
        pTVar3->die = ((height - (local_20 - mins[2])) / (float)iVar2 + (float)cl.time) - 0.1;
        iVar2 = RandomLong(0,iVar1 + -1);
        (pTVar3->entity).curstate.frame = (float)iVar2;
        fVar5 = RandomFloat(2.0,5.0);
        (pTVar3->entity).curstate.rendermode = 4;
        (pTVar3->entity).curstate.renderamt = 0xff;
        (pTVar3->entity).curstate.scale = 1.0 / fVar5;
      } while (count != iVar4);
    }
  }
  return;
}


// R_BuildLightMap  @ 0018ffe0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void R_BuildLightMap(msurface_t *psurf,byte *dest,int stride)

{
  colorVec *pcVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  short sVar14;
  short sVar15;
  short sVar16;
  short sVar17;
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  uint *puVar22;
  uint uVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  colorVec *pcVar28;
  colorVec *pcVar29;
  byte *pbVar30;
  byte bVar31;
  color24_conflict *pcVar32;
  uint uVar33;
  colorVec *pcVar34;
  uint uVar35;
  uint uVar36;
  int iVar37;
  int iVar38;
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar43 [16];
  undefined1 auVar47 [16];
  undefined1 auVar50 [16];
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
  undefined1 auVar53 [16];
  undefined1 auVar54 [16];
  undefined1 auVar55 [16];
  undefined1 auVar58 [16];
  undefined1 auVar62 [16];
  undefined1 auVar65 [16];
  int iVar66;
  undefined1 auVar67 [16];
  undefined1 auVar68 [16];
  undefined1 auVar69 [16];
  undefined1 auVar70 [16];
  undefined1 auVar71 [16];
  undefined1 auVar72 [16];
  undefined1 auVar73 [16];
  double dVar74;
  byte *local_48;
  int local_44;
  colorVec *local_40;
  color24_conflict *local_38;
  uint local_2c;
  undefined1 auVar44 [16];
  undefined1 auVar41 [16];
  undefined1 auVar45 [16];
  undefined1 auVar48 [16];
  undefined1 auVar42 [16];
  undefined1 auVar46 [16];
  undefined1 auVar49 [16];
  undefined1 auVar59 [16];
  undefined1 auVar56 [16];
  undefined1 auVar60 [16];
  undefined1 auVar63 [16];
  undefined1 auVar57 [16];
  undefined1 auVar61 [16];
  undefined1 auVar64 [16];
  
                    /* Unresolved local var: int smax@[???]
                       Unresolved local var: int tmax@[???]
                       Unresolved local var: int t@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: color24 * lightmap@[???]
                       Unresolved local var: colorVec * bl@[???]
                       Unresolved local var: uint scale@[???]
                       Unresolved local var: uint lightscale@[???]
                       Unresolved local var: int maps@[???]
                       Unresolved local var: int maxSize@[???] */
  local_48 = dest;
  if (((g_bHasShaderFunctions == false) || (gl_use_shaders.value == 0.0)) ||
     (sv_allow_shaders.value == 0.0)) {
    if ((gl_overbright.value == 0.0) || (iVar37 = 0x100, gl_texsort == false)) {
      dVar74 = pow(2.0,(double)(1.0 / v_lightgamma.value));
      iVar37 = (int)(dVar74 * 256.0 + 0.5);
    }
  }
  else {
    iVar37 = 0x100;
  }
  uVar23 = psurf->dlightbits & r_dlightactive;
  psurf->cached_dlight = uVar23;
  psurf->dlightbits = uVar23;
  iVar24 = (int)psurf->extents[0] >> 4;
  uVar23 = iVar24 + 1;
  iVar25 = (int)psurf->extents[1] >> 4;
  iVar26 = iVar25 + 1;
  iVar27 = uVar23 * iVar26;
  if (0x144 < iVar27) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Error: lightmap for texture %s too large (%d x %d = %d luxels); cannot exceed %d\n",
              psurf->texinfo->texture,uVar23,iVar26,iVar27,0x144);
  }
  auVar20 = _DAT_00267f50;
  auVar21 = _DAT_0026dab0;
  if (filterMode == false) {
    if ((r_fullbright.value == 0.0) && ((cl.worldmodel)->lightdata != (color24 *)0x0)) {
      local_38 = psurf->samples;
      if (0 < iVar27) {
        pcVar28 = blocklights;
        do {
          pcVar28->r = 0;
          pcVar34 = pcVar28 + 1;
          pcVar28->g = 0;
          pcVar28->b = 0;
          pcVar28 = pcVar34;
        } while (blocklights + iVar27 != pcVar34);
      }
      if (local_38 != (color24_conflict *)0x0) {
        iVar38 = 0;
        do {
          if (psurf->styles[iVar38] == 0xff) break;
          iVar66 = d_lightstylevalue[psurf->styles[iVar38]];
          psurf->cached_light[iVar38] = iVar66;
          if (0 < iVar27) {
            pcVar28 = blocklights;
            pcVar32 = local_38;
            do {
              pcVar28->r = pcVar28->r + (uint)pcVar32->r * iVar66;
              pcVar28->g = pcVar28->g + (uint)pcVar32->g * iVar66;
              pcVar28->b = pcVar28->b + (uint)pcVar32->b * iVar66;
              pcVar28 = pcVar28 + 1;
              pcVar32 = pcVar32 + 1;
            } while (pcVar28 != blocklights + iVar27);
          }
          iVar38 = iVar38 + 1;
          local_38 = local_38 + iVar27;
        } while (iVar38 != 4);
      }
      auVar20 = _DAT_00267f50;
      auVar21 = _DAT_0026dab0;
      if (psurf->dlightframe == r_framecount) {
        R_AddDynamicLights(psurf);
        auVar20 = _DAT_00267f50;
        auVar21 = _DAT_0026dab0;
      }
    }
    else if (0 < iVar27) {
      pcVar28 = blocklights;
      do {
        pcVar28->r = 0xff00;
        pcVar34 = pcVar28 + 1;
        pcVar28->g = 0xff00;
        pcVar28->b = 0xff00;
        pcVar28 = pcVar34;
        auVar20 = _DAT_00267f50;
        auVar21 = _DAT_0026dab0;
      } while (pcVar34 != blocklights + iVar27);
    }
  }
  else if (0 < iVar27) {
    local_2c = (uint)(longlong)ROUND(filterColorRed * 65280.0 * filterBrightness);
    uVar33 = local_2c;
    local_2c = (uint)(longlong)ROUND(filterColorGreen * 65280.0 * filterBrightness);
    uVar36 = local_2c;
    local_2c = (uint)(longlong)ROUND(filterColorBlue * 65280.0 * filterBrightness);
    pcVar28 = blocklights;
    do {
      pcVar28->r = uVar33;
      pcVar34 = pcVar28 + 1;
      pcVar28->g = uVar36;
      pcVar28->b = local_2c;
      pcVar28 = pcVar34;
      auVar20 = _DAT_00267f50;
      auVar21 = _DAT_0026dab0;
    } while (pcVar34 != blocklights + iVar27);
  }
  _DAT_00267f50 = auVar20;
  _DAT_0026dab0 = auVar21;
                    /* WARNING: Read-only address (ram,0x00267f50) is written */
                    /* WARNING: Read-only address (ram,0x0026dab0) is written */
  if ((gl_lightmap_format == 0x1909) || (gl_lightmap_format == 0x8049)) {
    if (0 < iVar26) {
      iVar37 = 1;
      uVar33 = (iVar24 - 0x10U >> 4) + 1;
      pcVar28 = blocklights;
      do {
        pcVar34 = pcVar28;
        if (0 < (int)uVar23) {
          pcVar34 = pcVar28 + uVar23;
          if ((pcVar28 < (colorVec *)((int)&((colorVec *)dest)->r + uVar23) && dest < pcVar34) ||
             (uVar23 < 0x10)) {
            iVar26 = 0;
            do {
              puVar22 = &pcVar28->r;
              pcVar28 = pcVar28 + 1;
              iVar27 = (int)*puVar22 >> 8;
              if (0xff < iVar27) {
                iVar27 = 0xff;
              }
              *(byte *)((int)&((colorVec *)dest)->r + iVar26) = ~(byte)iVar27;
              iVar26 = iVar26 + 1;
            } while (iVar26 < (int)uVar23);
          }
          else {
            if (iVar24 == 0xf) {
              uVar36 = 0;
            }
            else {
              pcVar29 = pcVar28 + 1;
              uVar36 = 0;
              do {
                uVar35 = uVar36 + 1;
                auVar51._0_4_ = (int)pcVar29[-1].r >> 8;
                auVar51._4_4_ = (int)pcVar29->r >> 8;
                auVar51._8_4_ = (int)pcVar29[1].r >> 8;
                auVar51._12_4_ = (int)pcVar29[2].r >> 8;
                iVar26 = auVar21._0_4_;
                auVar67._0_4_ = -(uint)(iVar26 < auVar51._0_4_);
                iVar27 = auVar21._4_4_;
                auVar67._4_4_ = -(uint)(iVar27 < auVar51._4_4_);
                iVar38 = auVar21._8_4_;
                auVar67._8_4_ = -(uint)(iVar38 < auVar51._8_4_);
                iVar66 = auVar21._12_4_;
                auVar67._12_4_ = -(uint)(iVar66 < auVar51._12_4_);
                auVar39 = auVar21 & auVar67 | ~auVar67 & auVar51;
                auVar52._0_4_ = (int)pcVar29[3].r >> 8;
                auVar52._4_4_ = (int)pcVar29[4].r >> 8;
                auVar52._8_4_ = (int)pcVar29[5].r >> 8;
                auVar52._12_4_ = (int)pcVar29[6].r >> 8;
                auVar68._0_4_ = -(uint)(iVar26 < auVar52._0_4_);
                auVar68._4_4_ = -(uint)(iVar27 < auVar52._4_4_);
                auVar68._8_4_ = -(uint)(iVar38 < auVar52._8_4_);
                auVar68._12_4_ = -(uint)(iVar66 < auVar52._12_4_);
                auVar53 = ~auVar68 & auVar52 | auVar21 & auVar68;
                auVar42._0_12_ = auVar39._0_12_;
                auVar42._12_2_ = auVar39._6_2_;
                auVar42._14_2_ = auVar53._6_2_;
                auVar41._12_4_ = auVar42._12_4_;
                auVar41._0_10_ = auVar39._0_10_;
                auVar41._10_2_ = auVar53._4_2_;
                auVar40._10_6_ = auVar41._10_6_;
                auVar40._0_8_ = auVar39._0_8_;
                auVar40._8_2_ = auVar39._4_2_;
                auVar71._2_8_ = auVar40._8_8_;
                auVar71._0_2_ = auVar53._2_2_;
                auVar71._10_6_ = 0;
                auVar50._0_2_ = auVar39._0_2_;
                auVar54._12_4_ = 0;
                auVar54._0_12_ = SUB1612(auVar71 << 0x30,4);
                auVar54 = auVar54 << 0x20;
                auVar46._0_12_ = auVar54._0_12_;
                auVar46._12_2_ = auVar53._2_2_;
                auVar46._14_2_ = auVar53._10_2_;
                auVar45._12_4_ = auVar46._12_4_;
                auVar45._0_10_ = auVar54._0_10_;
                auVar45._10_2_ = auVar39._10_2_;
                auVar44._10_6_ = auVar45._10_6_;
                auVar44._0_8_ = auVar54._0_8_;
                auVar44._8_2_ = auVar39._2_2_;
                auVar18._2_8_ = auVar44._8_8_;
                auVar18._0_2_ = auVar53._8_2_;
                auVar18._10_6_ = 0;
                auVar43._12_4_ = 0;
                auVar43._0_12_ = SUB1612(auVar18 << 0x30,4);
                auVar43 = auVar43 << 0x20;
                auVar49._0_12_ = auVar43._0_12_;
                auVar49._12_2_ = auVar53._8_2_;
                auVar49._14_2_ = auVar53._12_2_;
                auVar48._12_4_ = auVar49._12_4_;
                auVar48._0_10_ = auVar43._0_10_;
                auVar48._10_2_ = auVar53._4_2_;
                auVar47._10_6_ = auVar48._10_6_;
                auVar47._0_8_ = auVar43._0_8_;
                auVar47._8_2_ = auVar53._0_2_;
                auVar50._8_8_ = auVar47._8_8_;
                auVar50._6_2_ = auVar39._12_2_;
                auVar50._4_2_ = auVar39._8_2_;
                auVar50._2_2_ = auVar39._4_2_;
                auVar50 = auVar50 & auVar20;
                auVar69._0_4_ = (int)pcVar29[7].r >> 8;
                auVar69._4_4_ = (int)pcVar29[8].r >> 8;
                auVar69._8_4_ = (int)pcVar29[9].r >> 8;
                auVar69._12_4_ = (int)pcVar29[10].r >> 8;
                auVar72._0_4_ = -(uint)(iVar26 < auVar69._0_4_);
                auVar72._4_4_ = -(uint)(iVar27 < auVar69._4_4_);
                auVar72._8_4_ = -(uint)(iVar38 < auVar69._8_4_);
                auVar72._12_4_ = -(uint)(iVar66 < auVar69._12_4_);
                auVar54 = auVar21 & auVar72 | ~auVar72 & auVar69;
                auVar70._0_4_ = (int)pcVar29[0xb].r >> 8;
                auVar70._4_4_ = (int)pcVar29[0xc].r >> 8;
                auVar70._8_4_ = (int)pcVar29[0xd].r >> 8;
                auVar70._12_4_ = (int)pcVar29[0xe].r >> 8;
                auVar73._0_4_ = -(uint)(iVar26 < auVar70._0_4_);
                auVar73._4_4_ = -(uint)(iVar27 < auVar70._4_4_);
                auVar73._8_4_ = -(uint)(iVar38 < auVar70._8_4_);
                auVar73._12_4_ = -(uint)(iVar66 < auVar70._12_4_);
                auVar71 = ~auVar73 & auVar70 | auVar21 & auVar73;
                auVar57._0_12_ = auVar54._0_12_;
                auVar57._12_2_ = auVar54._6_2_;
                auVar57._14_2_ = auVar71._6_2_;
                auVar56._12_4_ = auVar57._12_4_;
                auVar56._0_10_ = auVar54._0_10_;
                auVar56._10_2_ = auVar71._4_2_;
                auVar55._10_6_ = auVar56._10_6_;
                auVar55._0_8_ = auVar54._0_8_;
                auVar55._8_2_ = auVar54._4_2_;
                auVar53._2_8_ = auVar55._8_8_;
                auVar53._0_2_ = auVar71._2_2_;
                auVar53._10_6_ = 0;
                auVar65._0_2_ = auVar54._0_2_;
                auVar39._12_4_ = 0;
                auVar39._0_12_ = SUB1612(auVar53 << 0x30,4);
                auVar39 = auVar39 << 0x20;
                auVar61._0_12_ = auVar39._0_12_;
                auVar61._12_2_ = auVar71._2_2_;
                auVar61._14_2_ = auVar71._10_2_;
                auVar60._12_4_ = auVar61._12_4_;
                auVar60._0_10_ = auVar39._0_10_;
                auVar60._10_2_ = auVar54._10_2_;
                auVar59._10_6_ = auVar60._10_6_;
                auVar59._0_8_ = auVar39._0_8_;
                auVar59._8_2_ = auVar54._2_2_;
                auVar19._2_8_ = auVar59._8_8_;
                auVar19._0_2_ = auVar71._8_2_;
                auVar19._10_6_ = 0;
                auVar58._12_4_ = 0;
                auVar58._0_12_ = SUB1612(auVar19 << 0x30,4);
                auVar58 = auVar58 << 0x20;
                auVar64._0_12_ = auVar58._0_12_;
                auVar64._12_2_ = auVar71._8_2_;
                auVar64._14_2_ = auVar71._12_2_;
                auVar63._12_4_ = auVar64._12_4_;
                auVar63._0_10_ = auVar58._0_10_;
                auVar63._10_2_ = auVar71._4_2_;
                auVar62._10_6_ = auVar63._10_6_;
                auVar62._0_8_ = auVar58._0_8_;
                auVar62._8_2_ = auVar71._0_2_;
                auVar65._8_8_ = auVar62._8_8_;
                auVar65._6_2_ = auVar54._12_2_;
                auVar65._4_2_ = auVar54._8_2_;
                auVar65._2_2_ = auVar54._4_2_;
                auVar65 = auVar65 & auVar20;
                sVar2 = auVar50._0_2_;
                sVar3 = auVar50._2_2_;
                sVar4 = auVar50._4_2_;
                sVar5 = auVar50._6_2_;
                sVar6 = auVar50._8_2_;
                sVar7 = auVar50._10_2_;
                sVar8 = auVar50._12_2_;
                sVar9 = auVar50._14_2_;
                sVar10 = auVar65._0_2_;
                sVar11 = auVar65._2_2_;
                sVar12 = auVar65._4_2_;
                sVar13 = auVar65._6_2_;
                sVar14 = auVar65._8_2_;
                sVar15 = auVar65._10_2_;
                sVar16 = auVar65._12_2_;
                sVar17 = auVar65._14_2_;
                pcVar1 = (colorVec *)((int)dest + uVar36 * 0x10);
                *(byte *)&pcVar1->r =
                     (0 < sVar2) * (sVar2 < 0x100) * auVar50[0] - (0xff < sVar2) ^ 0xff;
                *(byte *)((int)&pcVar1->r + 1) =
                     (0 < sVar3) * (sVar3 < 0x100) * auVar50[2] - (0xff < sVar3) ^ 0xff;
                *(byte *)((int)&pcVar1->r + 2) =
                     (0 < sVar4) * (sVar4 < 0x100) * auVar50[4] - (0xff < sVar4) ^ 0xff;
                *(byte *)((int)&pcVar1->r + 3) =
                     (0 < sVar5) * (sVar5 < 0x100) * auVar50[6] - (0xff < sVar5) ^ 0xff;
                *(byte *)&pcVar1->g =
                     (0 < sVar6) * (sVar6 < 0x100) * auVar50[8] - (0xff < sVar6) ^ 0xff;
                *(byte *)((int)&pcVar1->g + 1) =
                     (0 < sVar7) * (sVar7 < 0x100) * auVar50[10] - (0xff < sVar7) ^ 0xff;
                *(byte *)((int)&pcVar1->g + 2) =
                     (0 < sVar8) * (sVar8 < 0x100) * auVar50[0xc] - (0xff < sVar8) ^ 0xff;
                *(byte *)((int)&pcVar1->g + 3) =
                     (0 < sVar9) * (sVar9 < 0x100) * auVar50[0xe] - (0xff < sVar9) ^ 0xff;
                *(byte *)&pcVar1->b =
                     (0 < sVar10) * (sVar10 < 0x100) * auVar65[0] - (0xff < sVar10) ^ 0xff;
                *(byte *)((int)&pcVar1->b + 1) =
                     (0 < sVar11) * (sVar11 < 0x100) * auVar65[2] - (0xff < sVar11) ^ 0xff;
                *(byte *)((int)&pcVar1->b + 2) =
                     (0 < sVar12) * (sVar12 < 0x100) * auVar65[4] - (0xff < sVar12) ^ 0xff;
                *(byte *)((int)&pcVar1->b + 3) =
                     (0 < sVar13) * (sVar13 < 0x100) * auVar65[6] - (0xff < sVar13) ^ 0xff;
                *(byte *)&pcVar1->a =
                     (0 < sVar14) * (sVar14 < 0x100) * auVar65[8] - (0xff < sVar14) ^ 0xff;
                *(byte *)((int)&pcVar1->a + 1) =
                     (0 < sVar15) * (sVar15 < 0x100) * auVar65[10] - (0xff < sVar15) ^ 0xff;
                *(byte *)((int)&pcVar1->a + 2) =
                     (0 < sVar16) * (sVar16 < 0x100) * auVar65[0xc] - (0xff < sVar16) ^ 0xff;
                *(byte *)((int)&pcVar1->a + 3) =
                     (0 < sVar17) * (sVar17 < 0x100) * auVar65[0xe] - (0xff < sVar17) ^ 0xff;
                pcVar29 = pcVar29 + 0x10;
                uVar36 = uVar35;
              } while (uVar35 < uVar33);
              pcVar28 = pcVar28 + uVar33 * 0x10;
              uVar36 = uVar33 * 0x10;
              if (uVar33 * 0x10 == uVar23) goto LAB_0019073e;
            }
            do {
              puVar22 = &pcVar28->r;
              pcVar28 = pcVar28 + 1;
              iVar26 = (int)*puVar22 >> 8;
              if (0xff < iVar26) {
                iVar26 = 0xff;
              }
              *(byte *)((int)&((colorVec *)dest)->r + uVar36) = ~(byte)iVar26;
              uVar36 = uVar36 + 1;
            } while ((int)uVar36 < (int)uVar23);
          }
        }
LAB_0019073e:
        iVar37 = iVar37 + 1;
        dest = (byte *)((int)&((colorVec *)dest)->r + stride);
        pcVar28 = pcVar34;
        if (iVar25 + 2 == iVar37) {
          return;
        }
      } while( true );
    }
  }
  else {
    if (gl_lightmap_format != 0x1908) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Bad lightmap format");
    }
    if (0 < iVar26) {
      local_44 = 1;
      local_40 = blocklights;
      do {
        if (0 < (int)uVar23) {
          iVar26 = 1;
          pbVar30 = local_48;
          pcVar28 = local_40;
          do {
            uVar33 = pcVar28->r * iVar37 >> 0xe;
            if (0x3ff < uVar33) {
              uVar33 = 0x3ff;
            }
            iVar27 = lightgammatable[uVar33];
            *pbVar30 = (byte)(iVar27 >> 2);
            uVar33 = pcVar28->g * iVar37 >> 0xe;
            if (0x3ff < uVar33) {
              uVar33 = 0x3ff;
            }
            iVar38 = lightgammatable[uVar33];
            pbVar30[1] = (byte)(iVar38 >> 2);
            uVar33 = pcVar28->b * iVar37 >> 0xe;
            if (0x3ff < uVar33) {
              uVar33 = 0x3ff;
            }
            pcVar28 = pcVar28 + 1;
            iVar66 = lightgammatable[uVar33];
            pbVar30[2] = (byte)(iVar66 >> 2);
            if (gl_monolights.value == 0.0) {
              bVar31 = 0xff;
            }
            else {
              pbVar30[2] = 0xff;
              pbVar30[1] = 0xff;
              bVar31 = ~(byte)((iVar38 >> 2 & 0xffU) * 0x95 + (iVar27 >> 2 & 0xffU) * 0x4c +
                               (iVar66 >> 2 & 0xffU) * 0x1d >> 8);
              *pbVar30 = 0xff;
            }
            iVar26 = iVar26 + 1;
            pbVar30[3] = bVar31;
            pbVar30 = pbVar30 + 4;
          } while (iVar26 != iVar24 + 2);
          local_40 = local_40 + uVar23;
          local_48 = local_48 + uVar23 * 4;
        }
        local_44 = local_44 + 1;
        local_48 = local_48 + stride + uVar23 * -4;
      } while (local_44 != iVar25 + 2);
    }
  }
  return;
}


// R_BulletImpactParticles  @ 0019a840
void R_BulletImpactParticles(vec_t *pos)

{
  particle_s **pppVar1;
  double dVar2;
  particle_t *ppVar3;
  int iVar4;
  int iVar5;
  particle_t *ppVar6;
  float fVar7;
  int local_38;
  short local_34;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int quantity@[???]
                       Unresolved local var: int color@[???]
                       Unresolved local var: float dist@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: vec3_t dir@[???] */
  local_28 = *pos - r_origin[0];
  local_24 = pos[1] - r_origin[1];
  local_20 = pos[2] - r_origin[2];
  fVar7 = Length(&local_28);
  if ((1000.0 < fVar7) || (local_38 = (int)((1000.0 - fVar7) / 100.0), local_38 == 0)) {
    local_38 = 4;
    local_34 = 3;
  }
  else {
    local_34 = 3 - (short)((local_38 * 0x1e) / 100);
    local_38 = local_38 * 4;
  }
  iVar5 = 2;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: particle_t * p@[???] */
    ppVar3 = free_particles;
    ppVar6 = gpActiveTracers;
    if (free_particles == (particle_t *)0x0) {
      return;
    }
    iVar4 = 0;
    gpActiveTracers = free_particles;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar6;
    dVar2 = cl.time;
    fVar7 = RandomFloat(0.1,0.5);
    ppVar3->die = (float)dVar2 + fVar7;
    ppVar3->color = 5;
    ppVar3->packedColor = 0xff;
    ppVar3->type = pt_grav;
    ppVar3->ramp = 0.5;
    do {
      ppVar3->org[iVar4] = pos[iVar4];
      fVar7 = RandomFloat(-200.0,200.0);
      ppVar3->vel[iVar4] = fVar7;
      iVar4 = iVar4 + 1;
    } while (iVar4 != 3);
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if ((0 < local_38) && (free_particles != (particle_t *)0x0)) {
    iVar5 = 0;
    ppVar6 = free_particles;
    do {
      free_particles = ppVar6->next;
      iVar5 = iVar5 + 1;
      ppVar3 = ppVar6;
      ppVar6->next = active_particles;
      active_particles = ppVar3;
      ppVar6->org[0] = *pos;
      ppVar6->org[1] = pos[1];
      ppVar6->org[2] = pos[2];
      local_28 = RandomFloat(-1.0,1.0);
      local_24 = RandomFloat(-1.0,1.0);
      local_20 = RandomFloat(-1.0,1.0);
      ppVar6->vel[0] = local_28;
      ppVar6->vel[1] = local_24;
      ppVar6->vel[2] = local_20;
      fVar7 = RandomFloat(50.0,100.0);
      VectorScale(ppVar6->vel,fVar7,ppVar6->vel);
      ppVar6->color = 3 - local_34;
      ppVar6->packedColor = 0;
      ppVar6->type = pt_grav;
      ppVar6->die = (float)cl.time + 0.5;
      if (iVar5 == local_38) {
        return;
      }
      ppVar6 = free_particles;
    } while (free_particles != (particle_t *)0x0);
  }
  return;
}


// R_CheckProgram  @ 0018e750
bool __regparm3 R_CheckProgram(GLuint program)

{
  int iVar1;
  undefined1 *puVar2;
  int in_GS_OFFSET;
  undefined4 uStack_30;
  int aiStack_20 [4];
  int local_10;
  
                    /* Unresolved local var: GLint status@[???]
                       Unresolved local var: GLint logLength@[???] */
  puVar2 = &stack0xffffffd4;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  uStack_30 = 0x18e783;
  (*qglGetProgramiv)(program,0x8b82,aiStack_20 + 2);
  uStack_30 = 0x18e797;
  (*qglGetProgramiv)(program,0x8b84,aiStack_20 + 3);
  if (aiStack_20[2] == 1) {
    uStack_30 = 0x18e814;
    Con_Printf("Successfully linked program!\n");
  }
  else {
    uStack_30 = 0x18e7a9;
    Con_Printf("ERROR: failed to link program!\n");
  }
  if (1 < aiStack_20[3]) {
                    /* Unresolved local var: GLchar * msg@[???] */
    iVar1 = -(aiStack_20[3] + 0x1eU & 0xfffffff0);
    puVar2 = &stack0xffffffd4 + iVar1;
    *(int *)((int)aiStack_20 + iVar1) = (int)&local_10 + iVar1;
    *(undefined4 *)(&stack0xffffffdc + iVar1) = 0;
    *(int *)(&stack0xffffffd8 + iVar1) = aiStack_20[3];
    *(GLuint *)(&stack0xffffffd4 + iVar1) = program;
    *(undefined4 *)((int)&uStack_30 + iVar1) = 0x18e7d7;
    (*qglGetProgramInfoLog)
              (*(GLuint *)(&stack0xffffffd4 + iVar1),*(GLsizei *)(&stack0xffffffd8 + iVar1),
               *(GLsizei **)(&stack0xffffffdc + iVar1),*(GLchar **)((int)aiStack_20 + iVar1));
    *(int *)(&stack0xffffffd8 + iVar1) = (int)&local_10 + iVar1;
    *(char **)(&stack0xffffffd4 + iVar1) = "Compiler reported: %s";
    *(undefined4 *)((int)&uStack_30 + iVar1) = 0x18e7e7;
    Con_Printf(*(char **)(&stack0xffffffd4 + iVar1));
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return aiStack_20[2] == 1;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar2 + -4) = &UNK_0018e81b;
  __stack_chk_fail();
}


// R_CheckShader  @ 0018e580
bool __regparm3 R_CheckShader(GLuint shader,char *filename)

{
  int iVar1;
  undefined1 *puVar2;
  int in_GS_OFFSET;
  undefined4 uStack_30;
  int aiStack_20 [4];
  int local_10;
  
                    /* Unresolved local var: GLint status@[???]
                       Unresolved local var: GLint logLength@[???] */
  puVar2 = &stack0xffffffd4;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  uStack_30 = 0x18e5b0;
  (*qglGetShaderiv)(shader,0x8b81,aiStack_20 + 2);
  uStack_30 = 0x18e5c9;
  (*qglGetShaderiv)(shader,0x8b84,aiStack_20 + 3);
  if (aiStack_20[2] == 1) {
    uStack_30 = 0x18e64c;
    Con_Printf("Successfully compiled \"%s\"\n");
  }
  else {
    uStack_30 = 0x18e5df;
    Con_Printf("ERROR: failed to compile shader \"%s\"\n");
  }
  if (1 < aiStack_20[3]) {
                    /* Unresolved local var: GLchar * msg@[???] */
    iVar1 = -(aiStack_20[3] + 0x1eU & 0xfffffff0);
    puVar2 = &stack0xffffffd4 + iVar1;
    *(int *)((int)aiStack_20 + iVar1) = (int)&local_10 + iVar1;
    *(undefined4 *)(&stack0xffffffdc + iVar1) = 0;
    *(int *)(&stack0xffffffd8 + iVar1) = aiStack_20[3];
    *(GLuint *)(&stack0xffffffd4 + iVar1) = shader;
    *(undefined4 *)((int)&uStack_30 + iVar1) = 0x18e60d;
    (*qglGetShaderInfoLog)
              (*(GLuint *)(&stack0xffffffd4 + iVar1),*(GLsizei *)(&stack0xffffffd8 + iVar1),
               *(GLsizei **)(&stack0xffffffdc + iVar1),*(GLchar **)((int)aiStack_20 + iVar1));
    *(int *)(&stack0xffffffd8 + iVar1) = (int)&local_10 + iVar1;
    *(char **)(&stack0xffffffd4 + iVar1) = "Compiler reported: %s";
    *(undefined4 *)((int)&uStack_30 + iVar1) = 0x18e61d;
    Con_Printf(*(char **)(&stack0xffffffd4 + iVar1));
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return aiStack_20[2] == 1;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar2 + -4) = &UNK_0018e653;
  __stack_chk_fail();
}


// R_CheckStudioCache  @ 000d8e20
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


// R_CheckVariables  @ 001bae80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_CheckVariables(void)

{
  if (((((float)filterMode == R_CheckVariables::oldFilterMode) &&
       (filterColorRed == R_CheckVariables::oldFilterColorRed)) &&
      (filterColorGreen == R_CheckVariables::oldFilterColorGreen)) &&
     ((filterColorBlue == R_CheckVariables::oldFilterColorBlue &&
      (filterBrightness == R_CheckVariables::oldFilterBrightness)))) {
    return;
  }
  R_CheckVariables::oldFilterMode = (float)filterMode;
  R_CheckVariables::oldFilterColorRed = filterColorRed;
  R_CheckVariables::oldFilterColorGreen = filterColorGreen;
  R_CheckVariables::oldFilterColorBlue = filterColorBlue;
  R_CheckVariables::oldFilterBrightness = filterBrightness;
  GL_LoadFilterTexture(filterColorRed,filterColorGreen,filterColorBlue,filterBrightness);
  GL_BuildLightmaps();
  return;
}


// R_CleanupShaders  @ 0018f570
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_CleanupShaders(void)

{
  uint uVar1;
  uint uVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (g_fsWorldProgram[0] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[0]);
  }
  g_fsWorldProgram[0] = 0;
  if (g_fsWorldProgram[1] != 0) {
    g_fsWorldProgram[0] = 0;
    (*qglDeleteProgram)(g_fsWorldProgram[1]);
  }
  g_fsWorldProgram[1] = 0;
  if (g_fsWorldProgram[2] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[2]);
  }
  g_fsWorldProgram[2] = 0;
  if (g_fsWorldProgram[3] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[3]);
  }
  g_fsWorldProgram[3] = 0;
  if (g_fsWorldProgram[4] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[4]);
  }
  g_fsWorldProgram[4] = 0;
  if (g_fsWorldProgram[5] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[5]);
  }
  g_fsWorldProgram[5] = 0;
  if (g_fsWorldProgram[6] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[6]);
    g_fsWorldProgram[6] = 0;
  }
  if (g_fsWorldProgram[7] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[7]);
    g_fsWorldProgram[7] = 0;
  }
  uVar2 = 0;
  do {
    *(undefined4 *)((int)g_nFogEnabledUniformLocation + uVar2) = 0xffffffff;
    uVar1 = uVar2 + 8;
    *(undefined4 *)((int)g_nFogEnabledUniformLocation + uVar2 + 4) = 0xffffffff;
    uVar2 = uVar1;
  } while (uVar1 < 0x20);
  uVar2 = 0;
  do {
    *(undefined4 *)((int)g_nFogModeUniformLocation + uVar2) = 0xffffffff;
    uVar1 = uVar2 + 8;
    *(undefined4 *)((int)g_nFogModeUniformLocation + uVar2 + 4) = 0xffffffff;
    uVar2 = uVar1;
  } while (uVar1 < 0x20);
  return;
}


// R_Clear  @ 0017f4d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_Clear(void)

{
  qboolean in_stack_ffffffe4;
  
  if (1 < cl.maxclients) {
    R_ForceCVars(in_stack_ffffffe4);
  }
  if (r_mirroralpha.value == 1.0) {
    if (gl_ztrick.value == 0.0) {
      if (gl_clear.value == 0.0) {
        (*qglClear)(0x100);
      }
      else {
        (*qglClear)(0x4100);
      }
      gldepthmin = 0.0;
      gldepthmax = 1.0;
      (*qglDepthFunc)(0x203);
    }
    else {
      if (gl_clear.value != 0.0) {
        (*qglClear)(0x4000);
      }
      R_Clear::lexical_block_1::trickframe = R_Clear::lexical_block_1::trickframe + 1;
      if ((R_Clear::lexical_block_1::trickframe & 1U) == 0) {
        gldepthmin = 1.0;
        gldepthmax = 0.5;
        (*qglDepthFunc)(0x206);
      }
      else {
        gldepthmin = 0.0;
        gldepthmax = 0.49999;
        (*qglDepthFunc)(0x203);
      }
    }
  }
  else {
    if (gl_clear.value == 0.0) {
      (*qglClear)(0x100);
    }
    else {
      (*qglClear)(0x4100);
    }
    gldepthmin = 0.0;
    gldepthmax = 0.5;
    (*qglDepthFunc)(0x203);
  }
  (*qglDepthRange)((double)gldepthmin,(double)gldepthmax);
  return;
}


// R_ClearParticles  @ 00199c30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_ClearParticles(void)

{
  BEAM *pBVar1;
  BEAM *pBVar2;
  particle_t *ppVar3;
  int iVar4;
  particle_t *ppVar5;
  BEAM *pBVar6;
  particle_t *ppVar7;
  
  iVar4 = r_numparticles;
                    /* Unresolved local var: int i@[???] */
  ppVar3 = particles;
  active_particles = (particle_t *)0x0;
  gpActiveTracers = (particle_t *)0x0;
  free_particles = particles;
  if (0 < r_numparticles) {
    ppVar5 = particles + 1;
    ppVar7 = particles + r_numparticles + 1;
    do {
      ppVar5[-1].next = ppVar5;
      ppVar5 = ppVar5 + 1;
    } while (ppVar5 != ppVar7);
  }
  gpFreeBeams = gBeams;
                    /* Unresolved local var: int i@[???] */
  ppVar3[iVar4 + -1].next = (particle_s *)0x0;
  gpActiveBeams = (BEAM *)0x0;
  Q_memset(gpFreeBeams,0,0x3e00);
  pBVar2 = gBeams;
  pBVar6 = gBeams + 1;
  pBVar1 = gBeams + 0x81;
  do {
    pBVar6[-1].next = pBVar6;
    pBVar6 = pBVar6 + 1;
  } while (pBVar1 != pBVar6);
  pBVar2[0x7f].next = (BEAM *)0x0;
  return;
}


// R_ClearSkyBox  @ 0018dc50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_ClearSkyBox(void)

{
                    /* Unresolved local var: int i@[???] */
  skymins[1][4] = 9999.0;
  skymins[0][4] = 9999.0;
  skymins[1][0] = 9999.0;
  skymins[1][1] = 9999.0;
  skymins[1][2] = 9999.0;
  skymins[1][3] = 9999.0;
  skymins[0][0] = 9999.0;
  skymins[0][1] = 9999.0;
  skymins[0][2] = 9999.0;
  skymins[0][3] = 9999.0;
  skymaxs[1][4] = -9999.0;
  skymaxs[0][4] = -9999.0;
  skymaxs[1][0] = -9999.0;
  skymaxs[1][1] = -9999.0;
  skymaxs[1][2] = -9999.0;
  skymaxs[1][3] = -9999.0;
  skymins[1][5] = 9999.0;
  skymaxs[0][0] = -9999.0;
  skymaxs[0][1] = -9999.0;
  skymaxs[0][2] = -9999.0;
  skymaxs[0][3] = -9999.0;
  skymins[0][5] = 9999.0;
  skymaxs[1][5] = -9999.0;
  skymaxs[0][5] = -9999.0;
  return;
}


// R_ConcatRotations  @ 000c6220
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


// R_ConcatTransforms  @ 000c6310
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


// R_CreateShader  @ 0018e660
GLuint __regparm3 R_CreateShader(char *filename,GLenum type,char *pExtra)

{
  bool bVar1;
  byte *p;
  GLuint shader;
  GLuint GVar2;
  GLsizei GVar3;
  char *local_2c [2];
  size_t local_24 [5];
  
                    /* Unresolved local var: GLchar * filebuffer@[???]
                       Unresolved local var: GLchar *[2] buffer@[???]
                       Unresolved local var: int[2] bufferLen@[???]
                       Unresolved local var: int bufferCount@[???]
                       Unresolved local var: GLuint shader@[???] */
  if (pExtra == (char *)0x0) {
    GVar3 = 1;
  }
  else {
    GVar3 = 2;
    local_2c[0] = pExtra;
    local_24[0] = strlen(pExtra);
  }
  bVar1 = pExtra != (char *)0x0;
  p = COM_LoadFile(filename,5,(int *)(local_24 + bVar1));
  if (p == (byte *)0x0) {
    GVar2 = 0;
  }
  else {
    local_2c[bVar1] = (char *)p;
    shader = (*qglCreateShader)(type);
    (*qglShaderSource)(shader,GVar3,local_2c,(GLint *)local_24);
    Mem_Free(p);
    (*qglCompileShader)(shader);
    bVar1 = R_CheckShader(shader,filename);
    GVar2 = shader;
    if (!bVar1) {
      GVar2 = 0;
      (*qglDeleteShader)(shader);
    }
  }
  return GVar2;
}


// R_CullBox  @ 0017c680
qboolean R_CullBox(vec_t *mins,vec_t *maxs)

{
  int iVar1;
  mplane_t *p;
  
                    /* Unresolved local var: int i@[???] */
  p = frustum;
  do {
    iVar1 = BoxOnPlaneSide(mins,maxs,p);
    if (iVar1 == 2) {
      return true;
    }
    p = p + 1;
  } while (p != (mplane_t *)&r_oldviewleaf);
  return false;
}


// R_CustomDecalShoot  @ 00194490
void R_CustomDecalShoot(texture_t *ptexture,int playernum,int entity,int modelIndex,vec_t *position,
                       int flags)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  cl_entity_t *pcVar4;
  mnode_t *node;
  float flScale;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int plindex@[???] */
                    /* Unresolved local var: mnode_t * pnodes@[???]
                       Unresolved local var: cl_entity_t * pent@[???] */
  if ((g_bUsingInGameAdvertisements != false) && (ptexture != (texture_t *)0x0)) {
    iVar1 = Q_stricmp(ptexture->name,"}lambda06");
    if (iVar1 == 0) {
      flags = flags | 4;
    }
  }
  gDecalPos[0] = *position;
  gDecalPos[1] = position[1];
  gDecalPos[2] = position[2];
  pcVar4 = cl_entities + entity;
  if (pcVar4 == (cl_entity_t *)0x0) {
    gDecalModel = (model_t *)0x0;
  }
  else {
    gDecalModel = pcVar4->model;
    if ((modelIndex != 0) && (gDecalModel == (model_s *)0x0)) {
      gDecalModel = CL_GetModelByIndex(modelIndex);
    }
    if ((((gDecalModel != (model_t *)0x0) ||
         ((sv.active != false &&
          (gDecalModel = sv.models[sv.edicts[entity].v.modelindex], gDecalModel != (model_s *)0x0)))
         ) && (gDecalModel->type == mod_brush)) && (ptexture != (texture_t *)0x0)) {
      node = gDecalModel->nodes;
      if (entity != 0) {
                    /* Unresolved local var: hull_t * phull@[???]
                       Unresolved local var: vec3_t temp@[???] */
        if (gDecalModel->firstmodelsurface != 0) {
          gDecalPos[0] = (*position - gDecalModel->hulls[0].clip_mins[0]) - pcVar4->origin[0];
          node = node + gDecalModel->hulls[0].firstclipnode;
          gDecalPos[1] = (position[1] - gDecalModel->hulls[0].clip_mins[1]) - pcVar4->origin[1];
          gDecalPos[2] = (position[2] - gDecalModel->hulls[0].clip_mins[2]) - pcVar4->origin[2];
        }
        if (((pcVar4->angles[0] != 0.0) || (pcVar4->angles[1] != 0.0)) || (pcVar4->angles[2] != 0.0)
           ) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???] */
          AngleVectors(pcVar4->angles,&local_40,&local_34,&local_28);
          local_38 = local_38 * gDecalPos[2];
          local_34 = local_34 * gDecalPos[0];
          local_2c = local_2c * gDecalPos[2];
          gDecalPos[2] = gDecalPos[2] * local_20 + gDecalPos[1] * local_24 + gDecalPos[0] * local_28
          ;
          gDecalPos[0] = local_38 + local_3c * gDecalPos[1] + local_40 * gDecalPos[0];
          gDecalPos[1] = -(local_2c + local_30 * gDecalPos[1] + local_34);
        }
      }
      gDecalTexture = ptexture;
      gDecalAppliedScale = -1.0;
      gDecalIndex = ~playernum;
      gDecalFlags = flags;
      if ((flags & 4U) == 0) {
        gDecalFlags = flags | 0x20;
      }
      uVar3 = ptexture->height >> 1;
      gDecalEntity = entity;
      gDecalSize = ptexture->width >> 1;
      if ((uint)gDecalSize < uVar3) {
        gDecalSize = uVar3;
      }
      pcVar2 = strstr(ptexture->name,"}z_");
      if (pcVar2 != (char *)0x0) {
        flScale = RandomFloat(0.1,0.15);
        R_DecalNode(node,flScale);
        return;
      }
      R_DecalNode(node,-1.0);
      return;
    }
  }
  Con_DPrintf("Decals must hit mod_brush!\n");
  return;
}


// R_DecalAlloc  @ 00192b80
decal_t * R_DecalAlloc(decal_t *pdecal)

{
  msurface_s *pmVar1;
  decal_t *pdVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  decal_t *pdVar7;
  
                    /* Unresolved local var: int limit@[???] */
  if ((4096.0 <= r_decals.value) || (((byte)gDecalFlags & 0x80) != 0)) {
    iVar5 = 0x1000;
  }
  else {
    iVar5 = (int)r_decals.value;
    if (iVar5 == 0) {
      return (decal_t *)0x0;
    }
  }
  if (pdecal == (decal_t *)0x0) {
    iVar4 = 0;
    do {
      gDecalCount = gDecalCount + 1;
      if (gDecalCount < iVar5) {
                    /* Unresolved local var: int count@[???] */
        pdecal = gDecalPool + gDecalCount;
      }
      else {
        pdecal = gDecalPool;
        gDecalCount = 0;
      }
      iVar4 = iVar4 + 1;
    } while (((pdecal->flags & 0x81U) != 0) && (iVar4 < iVar5));
  }
                    /* Unresolved local var: decal_t * tmp@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: decalcache_t * pCache@[???] */
  uVar3 = ((int)(pdecal + -0x49fd8) >> 2) * -0x49249249;
                    /* Unresolved local var: int cacheIndex@[???] */
  uVar6 = uVar3 & 0xff;
  if (uVar3 - gDecalCache[uVar6].decalIndex == 0) {
    gDecalCache[uVar6].decalIndex = -1;
  }
  pmVar1 = pdecal->psurface;
  if (pmVar1 != (msurface_s *)0x0) {
    pdVar2 = pmVar1->pdecals;
    if (pdecal == pdVar2) {
      pmVar1->pdecals = pdecal->pnext;
    }
    else {
      if (pdVar2 == (decal_t *)0x0) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Bad decal list");
      }
      do {
        pdVar7 = pdVar2;
        pdVar2 = pdVar7->pnext;
        if (pdVar2 == (decal_s *)0x0) goto LAB_00192c12;
      } while (pdecal != pdVar2);
      pdVar7->pnext = pdecal->pnext;
    }
  }
LAB_00192c12:
  pdecal->psurface = (msurface_s *)0x0;
  return pdecal;
}


// R_DecalCacheClear  @ 00192aa0
void R_DecalCacheClear(decal_t *pdecal)

{
  uint uVar1;
  uint uVar2;
  
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: decalcache_t * pCache@[???] */
  uVar1 = ((int)(pdecal + -0x49fd8) >> 2) * -0x49249249;
                    /* Unresolved local var: int cacheIndex@[???] */
  uVar2 = uVar1 & 0xff;
  if (gDecalCache[uVar2].decalIndex != uVar1) {
    return;
  }
  gDecalCache[uVar2].decalIndex = -1;
  return;
}


// R_DecalCacheIndex  @ 00192a80
int R_DecalCacheIndex(int index)

{
  return index & 0xff;
}


// R_DecalCacheSlot  @ 00192a90
decalcache_t * R_DecalCacheSlot(int decalIndex)

{
                    /* Unresolved local var: int cacheIndex@[???] */
  return gDecalCache + (decalIndex & 0xff);
}


// R_DecalCreate  @ 001936a0
void R_DecalCreate(msurface_t *psurface,int textureIndex,float scale,float x,float y)

{
  msurface_s *pmVar1;
  decal_s *pdVar2;
  decal_t *pdVar3;
  decal_s *pdVar4;
  decal_s *pdVar5;
  uint uVar6;
  decal_t *pdVar7;
  int iVar8;
  ushort uVar9;
  uint uVar10;
  int iVar11;
  decal_t *pdVar12;
  int local_10;
  
                    /* Unresolved local var: decal_t * pdecal@[???]
                       Unresolved local var: decal_t * pold@[???]
                       Unresolved local var: int count@[???] */
  pdVar3 = R_DecalIntersect(psurface,&local_10,x,y);
                    /* Unresolved local var: int limit@[???] */
  uVar9 = (ushort)gDecalFlags;
  if (local_10 < 4) {
    if ((r_decals.value < 4096.0) && ((gDecalFlags & 0x80U) == 0)) {
      pdVar3 = (decal_t *)0x0;
      goto LAB_00193813;
    }
    iVar11 = 0x1000;
LAB_00193895:
    iVar8 = 0;
    do {
      gDecalCount = gDecalCount + 1;
      if (gDecalCount < iVar11) {
                    /* Unresolved local var: int count@[???] */
        pdVar3 = gDecalPool + gDecalCount;
      }
      else {
        pdVar3 = gDecalPool;
        gDecalCount = 0;
      }
      iVar8 = iVar8 + 1;
    } while (((pdVar3->flags & 0x81U) != 0) && (iVar8 < iVar11));
  }
  else {
    if ((4096.0 <= r_decals.value) || ((gDecalFlags & 0x80U) != 0)) {
      iVar11 = 0x1000;
    }
    else {
LAB_00193813:
      pdVar7 = (decal_t *)0x0;
      iVar11 = (int)r_decals.value;
      if (iVar11 == 0) goto LAB_00193767;
    }
    if (pdVar3 == (decal_t *)0x0) goto LAB_00193895;
  }
                    /* Unresolved local var: decal_t * tmp@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: decalcache_t * pCache@[???] */
  uVar10 = ((int)(pdVar3 + -0x49fd8) >> 2) * -0x49249249;
                    /* Unresolved local var: int cacheIndex@[???] */
  uVar6 = uVar10 & 0xff;
  if (uVar10 - gDecalCache[uVar6].decalIndex == 0) {
    gDecalCache[uVar6].decalIndex = -1;
  }
  pmVar1 = pdVar3->psurface;
  if (pmVar1 != (msurface_s *)0x0) {
    pdVar7 = pmVar1->pdecals;
    if (pdVar3 == pdVar7) {
      pmVar1->pdecals = pdVar3->pnext;
    }
    else {
      if (pdVar7 == (decal_t *)0x0) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Bad decal list");
      }
      do {
        pdVar12 = pdVar7;
        pdVar7 = pdVar12->pnext;
        if (pdVar7 == (decal_s *)0x0) goto LAB_00193758;
      } while (pdVar3 != pdVar7);
      pdVar12->pnext = pdVar3->pnext;
    }
  }
LAB_00193758:
  uVar9 = (ushort)gDecalFlags;
  pdVar3->psurface = (msurface_s *)0x0;
  pdVar7 = pdVar3;
LAB_00193767:
  pdVar7->flags = uVar9;
  pdVar7->dx = x;
  pdVar7->dy = y;
  pdVar7->texture = (short)textureIndex;
  pdVar7->pnext = (decal_s *)0x0;
  pdVar2 = psurface->pdecals;
  if (pdVar2 == (decal_s *)0x0) {
LAB_00193860:
    psurface->pdecals = pdVar7;
  }
  else {
    if ((uVar9 & 4) == 0) {
      do {
        pdVar5 = pdVar2;
        pdVar2 = pdVar5->pnext;
      } while (pdVar5->pnext != (decal_s *)0x0);
    }
    else {
      pdVar5 = (decal_s *)0x0;
      do {
        pdVar4 = pdVar2;
        if ((pdVar4->flags & 0x80) != 0) {
          pdVar7->pnext = pdVar4;
          if (pdVar5 == (decal_s *)0x0) goto LAB_00193860;
          break;
        }
        pdVar2 = pdVar4->pnext;
        pdVar5 = pdVar4;
      } while (pdVar4->pnext != (decal_s *)0x0);
    }
    pdVar5->pnext = pdVar7;
  }
  iVar11 = gDecalEntity;
  pdVar7->psurface = psurface;
  pdVar7->scale = scale;
  pdVar7->entityIndex = (short)iVar11;
  return;
}


// R_DecalIndex  @ 00192a60
int R_DecalIndex(decal_t *pdecal)

{
  return ((int)(pdecal + -0x49fd8) >> 2) * -0x49249249;
}


// R_DecalInit  @ 00192a10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_DecalInit(void)

{
  decalcache_t *pdVar1;
  
                    /* Unresolved local var: int i@[???] */
  Q_memset(gDecalPool,0,0x1c000);
  pdVar1 = gDecalCache;
  gDecalCount = 0;
  do {
    pdVar1->decalIndex = -1;
    pdVar1 = pdVar1 + 1;
  } while (pdVar1 != (decalcache_t *)lightmap_rectchange);
  return;
}


// R_DecalIntersect  @ 00193470
decal_t * R_DecalIntersect(msurface_t *psurf,int *pcount,float x,float y)

{
  uint uVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  texture_t *ptVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  decal_t *pdVar11;
  int iVar12;
  int iVar13;
  decal_t *pdVar14;
  decal_t *pdVar15;
  
                    /* Unresolved local var: decal_t * plist@[???]
                       Unresolved local var: decal_t * plast@[???]
                       Unresolved local var: int dist@[???]
                       Unresolved local var: int lastDist@[???]
                       Unresolved local var: int dx@[???]
                       Unresolved local var: int dy@[???]
                       Unresolved local var: texture_t * ptexture@[???]
                       Unresolved local var: float w@[???]
                       Unresolved local var: float h@[???]
                       Unresolved local var: float maxWidth@[???]
                       Unresolved local var: qboolean bPermanent@[???] */
  *pcount = 0;
  ptVar6 = psurf->texinfo->texture;
  fVar3 = (float)ptVar6->width;
  pdVar11 = psurf->pdecals;
  uVar1 = gDecalTexture->width;
  uVar2 = gDecalTexture->height;
  fVar4 = (float)ptVar6->height;
  if (pdVar11 == (decal_t *)0x0) {
    pdVar15 = (decal_t *)0x0;
  }
  else {
    iVar13 = 0xffff;
    pdVar14 = (decal_t *)0x0;
    do {
      ptVar6 = Draw_DecalTexture((int)pdVar11->texture);
      iVar12 = iVar13;
      pdVar15 = pdVar14;
      if (((pdVar11->flags & 0x81U) == 0) && ((float)ptVar6->width <= (float)uVar1 * 1.5)) {
        uVar9 = (uint)(((float)(uVar1 >> 1) + x * fVar3) -
                      ((float)(ptVar6->width >> 1) + fVar3 * pdVar11->dx));
        uVar8 = (int)uVar9 >> 0x1f;
        iVar10 = (uVar9 ^ uVar8) - uVar8;
        uVar8 = (uint)(((float)(uVar2 >> 1) + y * fVar4) -
                      (fVar4 * pdVar11->dy + (float)(ptVar6->height >> 1)));
        uVar9 = (int)uVar8 >> 0x1f;
        iVar7 = (uVar8 ^ uVar9) - uVar9;
        if (iVar10 < iVar7) {
          fVar5 = (float)iVar7 + (float)iVar10 * 0.5;
        }
        else {
          fVar5 = (float)iVar10 + (float)iVar7 * 0.5;
        }
        iVar7 = (int)fVar5;
        if ((((float)iVar7 * pdVar11->scale < 8.0) &&
            (*pcount = *pcount + 1, iVar12 = iVar7, pdVar15 = pdVar11, pdVar14 != (decal_t *)0x0))
           && (iVar13 < iVar7)) {
          iVar12 = iVar13;
          pdVar15 = pdVar14;
        }
      }
      pdVar11 = pdVar11->pnext;
      iVar13 = iVar12;
      pdVar14 = pdVar15;
    } while (pdVar11 != (decal_s *)0x0);
  }
  return pdVar15;
}


// R_DecalMPoly  @ 00195df0
void R_DecalMPoly(float *v,texture_t *ptexture,msurface_t *psurf,int vertCount)

{
  int iVar1;
  
                    /* Unresolved local var: int j@[???] */
  GL_SelectTexture(TEXTURE0_SGIS);
  GL_Bind(ptexture->gl_texturenum);
  (*qglTexEnvf)(0x2300,0x2200,8448.0);
  if (gl_mtexable != 0) {
    GL_SelectTexture(TEXTURE1_SGIS);
    (*qglEnable)(0xde1);
    mtexenabled = true;
  }
  iVar1 = 0;
  GL_Bind(lightmap_textures[psurf->lightmaptexturenum]);
  (*qglBegin)(9);
  if (0 < vertCount) {
    do {
      iVar1 = iVar1 + 1;
      (*qglMTexCoord2fSGIS)(TEXTURE0_SGIS,v[3],v[4]);
      (*qglMTexCoord2fSGIS)(TEXTURE1_SGIS,v[5],v[6]);
      (*qglVertex3fv)(v);
      v = v + 7;
    } while (vertCount != iVar1);
  }
                    /* WARNING: Could not recover jumptable at 0x00195ed0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglEnd)();
  return;
}


// R_DecalNode  @ 00193900
void R_DecalNode(mnode_t *node,float flScale)

{
  short sVar1;
  short sVar2;
  mplane_t *pmVar3;
  mtexinfo_t *v;
  uint uVar4;
  mtexinfo_t *pmVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  msurface_t *psurface;
  int iVar13;
  float fVar14;
  float local_34;
  float local_30;
  float local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: mplane_t * splitplane@[???]
                       Unresolved local var: float dist@[???] */
  if ((node != (mnode_t *)0x0) && (-1 < node->contents)) {
    pmVar3 = node->plane;
    fVar14 = (gDecalPos[2] * pmVar3->normal[2] +
             gDecalPos[1] * pmVar3->normal[1] + gDecalPos[0] * pmVar3->normal[0]) - pmVar3->dist;
    if ((float)gDecalSize < fVar14) {
      R_DecalNode(node->children[0],flScale);
    }
    else if (fVar14 < (float)-gDecalSize) {
      R_DecalNode(node->children[1],flScale);
    }
    else {
      if ((fVar14 < 4.0) && (-4.0 < fVar14)) {
                    /* Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: float s@[???]
                       Unresolved local var: float t@[???]
                       Unresolved local var: float scale@[???]
                       Unresolved local var: msurface_t * surf@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: mtexinfo_t * tex@[???]
                       Unresolved local var: vec3_t cross@[???]
                       Unresolved local var: vec3_t normal@[???]
                       Unresolved local var: float face@[???] */
        iVar13 = 0;
        psurface = gDecalModel->surfaces + node->firstsurface;
        uVar11 = (uint)node->numsurfaces;
        if (uVar11 != 0) {
          do {
            if (((psurface->flags & 0x30U) == 0) &&
               (((psurface->flags & 0x100U) == 0 || ((gDecalFlags & 4U) == 0)))) {
              v = psurface->texinfo;
              fVar14 = flScale;
              if (flScale == -1.0) {
                fVar14 = Length((vec_t *)v);
              }
              if (fVar14 != 0.0) {
                sVar1 = psurface->texturemins[0];
                iVar10 = (int)((float)gDecalTexture->width * fVar14);
                fVar9 = ((v->vecs[0][2] * gDecalPos[2] +
                          v->vecs[0][1] * gDecalPos[1] + v->vecs[0][0] * gDecalPos[0] +
                         v->vecs[0][3]) - (float)sVar1) - (float)iVar10 * 0.5;
                if ((float)-iVar10 < fVar9) {
                  sVar2 = psurface->texturemins[1];
                  iVar12 = (int)((float)gDecalTexture->height * fVar14);
                  fVar8 = ((gDecalPos[2] * v->vecs[1][2] +
                            gDecalPos[1] * v->vecs[1][1] + gDecalPos[0] * v->vecs[1][0] +
                           v->vecs[1][3]) - (float)sVar2) - (float)iVar12 * 0.5;
                  if ((((float)-iVar12 < fVar8) && (fVar9 <= (float)(iVar10 + psurface->extents[0]))
                      ) && (fVar8 <= (float)(psurface->extents[1] + iVar12))) {
                    uVar11 = v->texture->width;
                    uVar4 = v->texture->height;
                    if ((gDecalFlags & 0x84U) != 0) {
                      if ((psurface->flags & 2) == 0) {
                        local_28 = psurface->plane->normal[0];
                        local_24 = psurface->plane->normal[1];
                        local_20 = psurface->plane->normal[2];
                      }
                      else {
                        VectorScale(psurface->plane->normal,-1.0,&local_28);
                      }
                      CrossProduct((vec_t *)psurface->texinfo,&local_28,&local_34);
                      pmVar5 = psurface->texinfo;
                      if (local_2c * pmVar5->vecs[1][2] +
                          local_30 * pmVar5->vecs[1][1] + local_34 * pmVar5->vecs[1][0] < 0.0) {
                        gDecalFlags = gDecalFlags | 8;
                      }
                      else {
                        gDecalFlags = gDecalFlags & 0xfffffff7;
                      }
                      CrossProduct(pmVar5->vecs[1],&local_28,&local_34);
                      pmVar5 = psurface->texinfo;
                      fVar6 = local_2c * pmVar5->vecs[0][2] +
                              local_30 * pmVar5->vecs[0][1] + local_34 * pmVar5->vecs[0][0];
                      fVar7 = -fVar6;
                      if ((gDecalFlags & 8U) == 0) {
                        fVar7 = fVar6;
                      }
                      if (fVar7 <= 0.0) {
                        gDecalFlags = gDecalFlags & 0xffffffef;
                      }
                      else {
                        gDecalFlags = gDecalFlags | 0x10;
                      }
                    }
                    if (((gDecalFlags & 0x80U) != 0) && (gDecalAppliedScale == -1.0)) {
                      gDecalAppliedScale = Length((vec_t *)v);
                    }
                    R_DecalCreate(psurface,gDecalIndex,1.0 / fVar14,
                                  (fVar9 + (float)sVar1) / (float)uVar11,
                                  ((float)sVar2 + fVar8) / (float)uVar4);
                  }
                }
              }
              uVar11 = (uint)node->numsurfaces;
            }
            iVar13 = iVar13 + 1;
            psurface = psurface + 1;
          } while (iVar13 < (int)uVar11);
        }
      }
      R_DecalNode(node->children[0],flScale);
      R_DecalNode(node->children[1],flScale);
    }
  }
  return;
}


// R_DecalPoly  @ 00195d60
void R_DecalPoly(float *v,texture_t *ptexture,msurface_t *psurf,int vertCount)

{
  int iVar1;
  
                    /* Unresolved local var: int j@[???] */
  iVar1 = 0;
  GL_Bind(ptexture->gl_texturenum);
  (*qglTexEnvf)(0x2300,0x2200,8448.0);
  (*qglBegin)(9);
  if (0 < vertCount) {
    do {
      iVar1 = iVar1 + 1;
      (*qglTexCoord2f)(v[3],v[4]);
      (*qglVertex3fv)(v);
      v = v + 7;
    } while (vertCount != iVar1);
  }
                    /* WARNING: Could not recover jumptable at 0x00195de2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglEnd)();
  return;
}


// R_DecalRemoveAll  @ 00192cd0
void R_DecalRemoveAll(int textureIndex)

{
  msurface_s *pmVar1;
  uint uVar2;
  uint uVar3;
  decal_t *dest;
  decal_t *pdVar4;
  decal_t *pdVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: decal_t * pDecal@[???] */
  dest = gDecalPool;
  do {
    while (dest->texture != textureIndex) {
      dest = dest + 1;
      if (dest == (decal_t *)&wasUsingShaders) {
        return;
      }
    }
                    /* Unresolved local var: decal_t * tmp@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: decalcache_t * pCache@[???] */
    uVar2 = ((int)(dest + -0x49fd8) >> 2) * -0x49249249;
                    /* Unresolved local var: int cacheIndex@[???] */
    uVar3 = uVar2 & 0xff;
    if (uVar2 - gDecalCache[uVar3].decalIndex == 0) {
      gDecalCache[uVar3].decalIndex = -1;
    }
    pmVar1 = dest->psurface;
    if (pmVar1 != (msurface_s *)0x0) {
      pdVar4 = pmVar1->pdecals;
      if (pdVar4 == dest) {
        pmVar1->pdecals = dest->pnext;
      }
      else {
        if (pdVar4 == (decal_t *)0x0) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("Bad decal list");
        }
        do {
          pdVar5 = pdVar4;
          pdVar4 = pdVar5->pnext;
          if (pdVar4 == (decal_s *)0x0) goto LAB_00192d44;
        } while (pdVar4 != dest);
        pdVar5->pnext = dest->pnext;
      }
    }
LAB_00192d44:
    dest->psurface = (msurface_s *)0x0;
    pdVar4 = dest + 1;
    Q_memset(dest,0,0x1c);
    dest = pdVar4;
    if (pdVar4 == (decal_t *)&wasUsingShaders) {
      return;
    }
  } while( true );
}


// R_DecalRemoveNonPermanent  @ 00192db0
void R_DecalRemoveNonPermanent(int textureIndex)

{
  msurface_s *pmVar1;
  uint uVar2;
  uint uVar3;
  decal_t *dest;
  decal_t *pdVar4;
  decal_t *pdVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: decal_t * pDecal@[???] */
  dest = gDecalPool;
  do {
    while ((dest->texture != textureIndex || ((dest != (decal_t *)0x0 && ((dest->flags & 1) != 0))))
          ) {
      dest = dest + 1;
      if (dest == (decal_t *)&wasUsingShaders) {
        return;
      }
    }
                    /* Unresolved local var: decal_t * tmp@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: decalcache_t * pCache@[???] */
    uVar2 = ((int)(dest + -0x49fd8) >> 2) * -0x49249249;
                    /* Unresolved local var: int cacheIndex@[???] */
    uVar3 = uVar2 & 0xff;
    if (uVar2 - gDecalCache[uVar3].decalIndex == 0) {
      gDecalCache[uVar3].decalIndex = -1;
    }
    pmVar1 = dest->psurface;
    if (pmVar1 != (msurface_s *)0x0) {
      pdVar4 = pmVar1->pdecals;
      if (pdVar4 == dest) {
        pmVar1->pdecals = dest->pnext;
      }
      else {
        if (pdVar4 == (decal_t *)0x0) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("Bad decal list");
        }
        do {
          pdVar5 = pdVar4;
          pdVar4 = pdVar5->pnext;
          if (pdVar4 == (decal_s *)0x0) goto LAB_00192e2c;
        } while (pdVar4 != dest);
        pdVar5->pnext = dest->pnext;
      }
    }
LAB_00192e2c:
    dest->psurface = (msurface_s *)0x0;
    pdVar4 = dest + 1;
    Q_memset(dest,0,0x1c);
    dest = pdVar4;
    if (pdVar4 == (decal_t *)&wasUsingShaders) {
      return;
    }
  } while( true );
}


// R_DecalRemoveWithFlag  @ 00192ea0
void R_DecalRemoveWithFlag(int flags)

{
  msurface_s *pmVar1;
  uint uVar2;
  uint uVar3;
  decal_t *dest;
  decal_t *pdVar4;
  decal_t *pdVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: decal_t * pDecal@[???] */
  dest = gDecalPool;
  do {
    while ((dest->flags & flags) == 0) {
      dest = dest + 1;
      if (dest == (decal_t *)&wasUsingShaders) {
        return;
      }
    }
                    /* Unresolved local var: decal_t * tmp@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: decalcache_t * pCache@[???] */
    uVar2 = ((int)(dest + -0x49fd8) >> 2) * -0x49249249;
                    /* Unresolved local var: int cacheIndex@[???] */
    uVar3 = uVar2 & 0xff;
    if (uVar2 - gDecalCache[uVar3].decalIndex == 0) {
      gDecalCache[uVar3].decalIndex = -1;
    }
    pmVar1 = dest->psurface;
    if (pmVar1 != (msurface_s *)0x0) {
      pdVar4 = pmVar1->pdecals;
      if (pdVar4 == dest) {
        pmVar1->pdecals = dest->pnext;
      }
      else {
        if (pdVar4 == (decal_t *)0x0) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("Bad decal list");
        }
        do {
          pdVar5 = pdVar4;
          pdVar4 = pdVar5->pnext;
          if (pdVar4 == (decal_s *)0x0) goto LAB_00192f14;
        } while (pdVar4 != dest);
        pdVar5->pnext = dest->pnext;
      }
    }
LAB_00192f14:
    dest->psurface = (msurface_s *)0x0;
    pdVar4 = dest + 1;
    Q_memset(dest,0,0x1c);
    dest = pdVar4;
    if (pdVar4 == (decal_t *)&wasUsingShaders) {
      return;
    }
  } while( true );
}


// R_DecalShoot  @ 001947e0
void R_DecalShoot(int textureIndex,int entity,int modelIndex,vec_t *position,int flags)

{
  texture_t *s1;
  int iVar1;
  char *pcVar2;
  uint uVar3;
  cl_entity_t *pcVar4;
  float flScale;
  mnode_t *local_50;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: texture_t * ptexture@[???] */
  s1 = Draw_DecalTexture(textureIndex);
                    /* Unresolved local var: mnode_t * pnodes@[???]
                       Unresolved local var: cl_entity_t * pent@[???] */
  if ((g_bUsingInGameAdvertisements != false) && (s1 != (texture_t *)0x0)) {
    iVar1 = Q_stricmp(s1->name,"}lambda06");
    if (iVar1 == 0) {
      flags = flags | 4;
    }
  }
  gDecalPos[0] = *position;
  gDecalPos[1] = position[1];
  gDecalPos[2] = position[2];
  pcVar4 = cl_entities + entity;
  if (pcVar4 == (cl_entity_t *)0x0) {
    gDecalModel = (model_t *)0x0;
  }
  else {
    gDecalModel = pcVar4->model;
    if ((modelIndex != 0) && (gDecalModel == (model_s *)0x0)) {
      gDecalModel = CL_GetModelByIndex(modelIndex);
    }
    if ((((gDecalModel != (model_t *)0x0) ||
         ((sv.active != false &&
          (gDecalModel = sv.models[sv.edicts[entity].v.modelindex], gDecalModel != (model_s *)0x0)))
         ) && (gDecalModel->type == mod_brush)) && (s1 != (texture_t *)0x0)) {
      local_50 = gDecalModel->nodes;
      if (entity != 0) {
                    /* Unresolved local var: hull_t * phull@[???]
                       Unresolved local var: vec3_t temp@[???] */
        if (gDecalModel->firstmodelsurface != 0) {
          gDecalPos[0] = (*position - gDecalModel->hulls[0].clip_mins[0]) - pcVar4->origin[0];
          local_50 = local_50 + gDecalModel->hulls[0].firstclipnode;
          gDecalPos[1] = (position[1] - gDecalModel->hulls[0].clip_mins[1]) - pcVar4->origin[1];
          gDecalPos[2] = (position[2] - gDecalModel->hulls[0].clip_mins[2]) - pcVar4->origin[2];
        }
        if (((pcVar4->angles[0] != 0.0) || (pcVar4->angles[1] != 0.0)) || (pcVar4->angles[2] != 0.0)
           ) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???] */
          AngleVectors(pcVar4->angles,&local_40,&local_34,&local_28);
          local_38 = local_38 * gDecalPos[2];
          local_34 = local_34 * gDecalPos[0];
          local_2c = local_2c * gDecalPos[2];
          gDecalPos[2] = gDecalPos[2] * local_20 + gDecalPos[1] * local_24 + gDecalPos[0] * local_28
          ;
          gDecalPos[0] = local_38 + local_3c * gDecalPos[1] + local_40 * gDecalPos[0];
          gDecalPos[1] = -(local_2c + local_30 * gDecalPos[1] + local_34);
        }
      }
      gDecalAppliedScale = -1.0;
      gDecalIndex = textureIndex;
      gDecalFlags = flags;
      if ((flags & 4U) == 0) {
        gDecalFlags = flags | 0x20;
      }
      uVar3 = s1->height >> 1;
      gDecalEntity = entity;
      gDecalSize = s1->width >> 1;
      if ((uint)gDecalSize < uVar3) {
        gDecalSize = uVar3;
      }
      gDecalTexture = s1;
      pcVar2 = strstr(s1->name,"}z_");
      if (pcVar2 != (char *)0x0) {
        flScale = RandomFloat(0.1,0.15);
        R_DecalNode(local_50,flScale);
        return;
      }
      R_DecalNode(local_50,-1.0);
      return;
    }
  }
  Con_DPrintf("Decals must hit mod_brush!\n");
  return;
}


// R_DecalShootScaled  @ 00194b40
void R_DecalShootScaled(int textureIndex,int entity,int modelIndex,vec_t *position,int flags,
                       float flScale)

{
  texture_t *s1;
  int iVar1;
  char *pcVar2;
  uint uVar3;
  cl_entity_t *pcVar4;
  float flScale_00;
  mnode_t *local_50;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: texture_t * ptexture@[???] */
  s1 = Draw_DecalTexture(textureIndex);
                    /* Unresolved local var: mnode_t * pnodes@[???]
                       Unresolved local var: cl_entity_t * pent@[???] */
  if ((g_bUsingInGameAdvertisements != false) && (s1 != (texture_t *)0x0)) {
    iVar1 = Q_stricmp(s1->name,"}lambda06");
    if (iVar1 == 0) {
      flags = flags | 4;
    }
  }
  gDecalPos[0] = *position;
  gDecalPos[1] = position[1];
  gDecalPos[2] = position[2];
  pcVar4 = cl_entities + entity;
  if (pcVar4 == (cl_entity_t *)0x0) {
    gDecalModel = (model_t *)0x0;
  }
  else {
    gDecalModel = pcVar4->model;
    if ((modelIndex != 0) && (gDecalModel == (model_s *)0x0)) {
      gDecalModel = CL_GetModelByIndex(modelIndex);
    }
    if ((((gDecalModel != (model_t *)0x0) ||
         ((sv.active != false &&
          (gDecalModel = sv.models[sv.edicts[entity].v.modelindex], gDecalModel != (model_s *)0x0)))
         ) && (gDecalModel->type == mod_brush)) && (s1 != (texture_t *)0x0)) {
      local_50 = gDecalModel->nodes;
      if (entity != 0) {
                    /* Unresolved local var: hull_t * phull@[???]
                       Unresolved local var: vec3_t temp@[???] */
        if (gDecalModel->firstmodelsurface != 0) {
          gDecalPos[0] = (*position - gDecalModel->hulls[0].clip_mins[0]) - pcVar4->origin[0];
          local_50 = local_50 + gDecalModel->hulls[0].firstclipnode;
          gDecalPos[1] = (position[1] - gDecalModel->hulls[0].clip_mins[1]) - pcVar4->origin[1];
          gDecalPos[2] = (position[2] - gDecalModel->hulls[0].clip_mins[2]) - pcVar4->origin[2];
        }
        if (((pcVar4->angles[0] != 0.0) || (pcVar4->angles[1] != 0.0)) || (pcVar4->angles[2] != 0.0)
           ) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???] */
          AngleVectors(pcVar4->angles,&local_40,&local_34,&local_28);
          local_38 = local_38 * gDecalPos[2];
          local_34 = local_34 * gDecalPos[0];
          local_2c = local_2c * gDecalPos[2];
          gDecalPos[2] = gDecalPos[2] * local_20 + gDecalPos[1] * local_24 + gDecalPos[0] * local_28
          ;
          gDecalPos[0] = local_38 + local_3c * gDecalPos[1] + local_40 * gDecalPos[0];
          gDecalPos[1] = -(local_2c + local_30 * gDecalPos[1] + local_34);
        }
      }
      gDecalAppliedScale = -1.0;
      gDecalIndex = textureIndex;
      gDecalFlags = flags;
      if ((flags & 4U) == 0) {
        gDecalFlags = flags | 0x20;
      }
      uVar3 = s1->height >> 1;
      gDecalEntity = entity;
      gDecalSize = s1->width >> 1;
      if ((uint)gDecalSize < uVar3) {
        gDecalSize = uVar3;
      }
      gDecalTexture = s1;
      pcVar2 = strstr(s1->name,"}z_");
      if (pcVar2 == (char *)0x0) {
        if (flScale != 1.0) {
          R_DecalNode(local_50,flScale);
          return;
        }
        R_DecalNode(local_50,-1.0);
        return;
      }
      flScale_00 = RandomFloat(0.1,0.15);
      R_DecalNode(local_50,flScale_00);
      return;
    }
  }
  Con_DPrintf("Decals must hit mod_brush!\n");
  return;
}


// R_DecalShoot_  @ 00193e20
void R_DecalShoot_(texture_t *ptexture,int index,int entity,int modelIndex,vec_t *position,int flags
                  ,float flScale)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  cl_entity_t *pcVar4;
  mnode_t *node;
  float flScale_00;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: mnode_t * pnodes@[???]
                       Unresolved local var: cl_entity_t * pent@[???] */
  if ((g_bUsingInGameAdvertisements != false) && (ptexture != (texture_t *)0x0)) {
    iVar1 = Q_stricmp(ptexture->name,"}lambda06");
    if (iVar1 == 0) {
      flags = flags | 4;
    }
  }
  gDecalPos[0] = *position;
  gDecalPos[1] = position[1];
  gDecalPos[2] = position[2];
  pcVar4 = cl_entities + entity;
  if (pcVar4 == (cl_entity_t *)0x0) {
    gDecalModel = (model_t *)0x0;
  }
  else {
    gDecalModel = pcVar4->model;
    if ((modelIndex != 0) && (gDecalModel == (model_s *)0x0)) {
      gDecalModel = CL_GetModelByIndex(modelIndex);
    }
    if ((((gDecalModel != (model_t *)0x0) ||
         ((sv.active != false &&
          (gDecalModel = sv.models[sv.edicts[entity].v.modelindex], gDecalModel != (model_s *)0x0)))
         ) && (gDecalModel->type == mod_brush)) && (ptexture != (texture_t *)0x0)) {
      node = gDecalModel->nodes;
      if (entity != 0) {
                    /* Unresolved local var: hull_t * phull@[???]
                       Unresolved local var: vec3_t temp@[???] */
        if (gDecalModel->firstmodelsurface != 0) {
          gDecalPos[0] = (*position - gDecalModel->hulls[0].clip_mins[0]) - pcVar4->origin[0];
          node = node + gDecalModel->hulls[0].firstclipnode;
          gDecalPos[1] = (position[1] - gDecalModel->hulls[0].clip_mins[1]) - pcVar4->origin[1];
          gDecalPos[2] = (position[2] - gDecalModel->hulls[0].clip_mins[2]) - pcVar4->origin[2];
        }
        if (((pcVar4->angles[0] != 0.0) || (pcVar4->angles[1] != 0.0)) || (pcVar4->angles[2] != 0.0)
           ) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???] */
          AngleVectors(pcVar4->angles,&local_40,&local_34,&local_28);
          local_38 = local_38 * gDecalPos[2];
          local_34 = local_34 * gDecalPos[0];
          local_2c = local_2c * gDecalPos[2];
          gDecalPos[2] = gDecalPos[2] * local_20 + gDecalPos[1] * local_24 + gDecalPos[0] * local_28
          ;
          gDecalPos[0] = local_38 + local_3c * gDecalPos[1] + local_40 * gDecalPos[0];
          gDecalPos[1] = -(local_2c + local_30 * gDecalPos[1] + local_34);
        }
      }
      gDecalTexture = ptexture;
      gDecalAppliedScale = -1.0;
      gDecalIndex = index;
      gDecalFlags = flags;
      if ((flags & 4U) == 0) {
        gDecalFlags = flags | 0x20;
      }
      uVar3 = ptexture->height >> 1;
      gDecalEntity = entity;
      gDecalSize = ptexture->width >> 1;
      if ((uint)gDecalSize < uVar3) {
        gDecalSize = uVar3;
      }
      pcVar2 = strstr(ptexture->name,"}z_");
      if (pcVar2 == (char *)0x0) {
        if (flScale != 1.0) {
          R_DecalNode(node,flScale);
          return;
        }
        R_DecalNode(node,-1.0);
        return;
      }
      flScale_00 = RandomFloat(0.1,0.15);
      R_DecalNode(node,flScale_00);
      return;
    }
  }
  Con_DPrintf("Decals must hit mod_brush!\n");
  return;
}


// R_DecalUnProject  @ 00193010
int R_DecalUnProject(decal_t *pdecal,vec_t *position)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  msurface_s *pmVar9;
  mtexinfo_t *v;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  mplane_t *vecb;
  int iVar14;
  model_s *pmVar15;
  edict_t *peVar16;
  texture_t *ptVar17;
  int iVar18;
  int iVar19;
  float fVar20;
  float fVar21;
  float local_64;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float s@[???]
                       Unresolved local var: float t@[???]
                       Unresolved local var: float scale@[???]
                       Unresolved local var: float inverseScale@[???]
                       Unresolved local var: mtexinfo_t * pTexinfo@[???]
                       Unresolved local var: texture_t * ptexture@[???]
                       Unresolved local var: int entityIndex@[???] */
  if ((pdecal == (decal_t *)0x0) || (pmVar9 = pdecal->psurface, pmVar9 == (msurface_s *)0x0)) {
    iVar18 = -1;
  }
  else {
    v = pmVar9->texinfo;
    uVar10 = v->texture->width;
    fVar5 = pdecal->dx;
    uVar11 = v->texture->height;
    sVar1 = pmVar9->texturemins[0];
    fVar6 = pdecal->dy;
    sVar2 = pmVar9->texturemins[1];
    fVar20 = Length((vec_t *)v);
    ptVar17 = Draw_DecalTexture((int)pdecal->texture);
    uVar12 = ptVar17->width;
    uVar13 = ptVar17->height;
    sVar3 = pdecal->psurface->texturemins[0];
    fVar7 = v->vecs[0][3];
    sVar4 = pdecal->psurface->texturemins[1];
    fVar8 = v->vecs[1][3];
    fVar21 = Length((vec_t *)v);
    if (ABS(fVar21) != 0.0) {
      fVar21 = 1.0 / ABS(fVar21);
      local_64 = fVar21 * fVar21;
    }
    VectorScale((vec_t *)v,
                (((float)sVar3 +
                 (float)uVar12 * fVar20 * 0.5 + ((float)uVar10 * fVar5 - (float)sVar1)) - fVar7) *
                local_64,position);
    VectorMA(position,local_64 *
                      (((float)sVar4 +
                       (float)uVar13 * fVar20 * 0.5 + ((float)uVar11 * fVar6 - (float)sVar2)) -
                      fVar8),v->vecs[1],position);
    vecb = pdecal->psurface->plane;
    VectorMA(position,vecb->dist,vecb->normal,position);
    peVar16 = sv.edicts;
    iVar19 = (int)pdecal->entityIndex;
    iVar18 = 0;
    if (iVar19 != 0) {
                    /* Unresolved local var: hull_t * phull@[???]
                       Unresolved local var: vec3_t temp@[???]
                       Unresolved local var: edict_t * pEdict@[???]
                       Unresolved local var: model_t * pModel@[???] */
      iVar14 = sv.edicts[iVar19].v.modelindex;
      iVar18 = 0;
      if (iVar14 != 0) {
        pmVar15 = sv.models[iVar14];
        iVar18 = 0;
        if ((pmVar15 != (model_s *)0x0) && (pmVar15->type == mod_brush)) {
          if ((sv.edicts[iVar19].v.angles[0] != 0.0) ||
             ((sv.edicts[iVar19].v.angles[1] != 0.0 || (sv.edicts[iVar19].v.angles[2] != 0.0)))) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???] */
            AngleVectorsTranspose(sv.edicts[iVar19].v.angles,&local_40,&local_34,&local_28);
            fVar5 = *position;
            fVar6 = position[1];
            fVar7 = position[2];
            *position = local_38 * fVar7 + local_3c * fVar6 + local_40 * fVar5;
            position[1] = local_2c * fVar7 + local_30 * fVar6 + local_34 * fVar5;
            position[2] = fVar7 * local_20 + fVar6 * local_24 + fVar5 * local_28;
          }
          iVar18 = iVar19;
          if (pmVar15->firstmodelsurface != 0) {
            fVar5 = *position + pmVar15->hulls[0].clip_mins[0];
            *position = fVar5;
            fVar6 = position[1] + pmVar15->hulls[0].clip_mins[1];
            position[1] = fVar6;
            fVar7 = position[2] + pmVar15->hulls[0].clip_mins[2];
            position[2] = fVar7;
            *position = fVar5 + peVar16[iVar19].v.origin[0];
            position[1] = fVar6 + peVar16[iVar19].v.origin[1];
            position[2] = fVar7 + peVar16[iVar19].v.origin[2];
          }
        }
      }
    }
  }
  return iVar18;
}


// R_DecalUnlink  @ 00192ae0
void R_DecalUnlink(decal_t *pdecal)

{
  msurface_s *pmVar1;
  decal_t *pdVar2;
  uint uVar3;
  uint uVar4;
  decal_t *pdVar5;
  
                    /* Unresolved local var: decal_t * tmp@[???] */
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: decalcache_t * pCache@[???] */
  uVar3 = ((int)(pdecal + -0x49fd8) >> 2) * -0x49249249;
                    /* Unresolved local var: int cacheIndex@[???] */
  uVar4 = uVar3 & 0xff;
  if (uVar3 - gDecalCache[uVar4].decalIndex == 0) {
    gDecalCache[uVar4].decalIndex = -1;
  }
  pmVar1 = pdecal->psurface;
  if (pmVar1 != (msurface_s *)0x0) {
    pdVar2 = pmVar1->pdecals;
    if (pdecal == pdVar2) {
      pmVar1->pdecals = pdecal->pnext;
    }
    else {
      if (pdVar2 == (decal_t *)0x0) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Bad decal list");
      }
      while (pdVar5 = pdVar2, pdVar2 = pdVar5->pnext, pdVar2 != (decal_s *)0x0) {
        if (pdecal == pdVar2) {
          pdVar5->pnext = pdecal->pnext;
          pdecal->psurface = (msurface_s *)0x0;
          return;
        }
      }
    }
  }
  pdecal->psurface = (msurface_s *)0x0;
  return;
}


// R_DecalVertsClip  @ 0018ee40
float * __regparm3
R_DecalVertsClip(float *poutVerts,decal_t *pdecal,msurface_t *psurf,texture_t *ptexture,
                int *pvertCount)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  ushort uVar9;
  float *pfVar10;
  float *out;
  float *out_00;
  float *out_01;
  int vertCount;
  int vertCount_00;
  int iVar11;
  int in_stack_ffffffe4;
  float *vert;
  
                    /* Unresolved local var: float * v@[???]
                       Unresolved local var: float scalex@[???]
                       Unresolved local var: float scaley@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int outCount@[???] */
  iVar11 = *(int *)((int)pdecal[1].scale + 0x24);
  uVar3 = *(uint *)(iVar11 + 0x10);
  fVar1 = poutVerts[4];
  uVar4 = psurf->numedges;
  uVar5 = *(uint *)(iVar11 + 0x14);
  uVar6 = *(uint *)psurf->texturemins;
  fVar2 = poutVerts[4];
  pfVar10 = (float *)((int)pdecal[1].dx + 0x10);
  vert = *(float **)((int)pdecal[1].dx + 8);
  if (0 < (int)vert) {
    psurf = (msurface_t *)(::vert[0] + 3);
    iVar11 = 0;
    do {
      (*(float (*) [7])((int)psurf + -0xc))[0] = *pfVar10;
      *(float *)((int)psurf + -8) = pfVar10[1];
      *(float *)((int)psurf + -4) = pfVar10[2];
      fVar7 = (pfVar10[3] - poutVerts[2]) * (((float)uVar3 * fVar1) / (float)uVar4);
      *(float *)psurf = fVar7;
      fVar8 = (pfVar10[4] - poutVerts[3]) * (((float)uVar5 * fVar2) / (float)uVar6);
      *(float *)((int)psurf + 4) = fVar8;
      uVar9 = *(ushort *)((int)poutVerts + 0x16);
      if ((uVar9 & 8) != 0) {
        *(float *)psurf = 1.0 - fVar7;
        uVar9 = *(ushort *)((int)poutVerts + 0x16);
      }
      if ((uVar9 & 0x10) != 0) {
        *(float *)((int)psurf + 4) = 1.0 - fVar8;
      }
      iVar11 = iVar11 + 1;
      pfVar10 = pfVar10 + 7;
      psurf = (msurface_t *)((int)psurf + 0x1c);
      vert = *(float **)((int)pdecal[1].dx + 8);
    } while (iVar11 < (int)vert);
  }
  pfVar10 = (float *)SHClip(vert,(int)pdecal,(float *)psurf,in_stack_ffffffe4);
  pfVar10 = (float *)SHClip(pfVar10,vertCount,out,in_stack_ffffffe4);
  pfVar10 = (float *)SHClip(pfVar10,vertCount_00,out_00,in_stack_ffffffe4);
  iVar11 = SHClip(pfVar10,0x8177e0,out_01,in_stack_ffffffe4);
  if ((iVar11 != 0) && ((*(ushort *)((int)poutVerts + 0x16) & 0x20) != 0)) {
    uVar9 = *(ushort *)((int)poutVerts + 0x16) & 0xffdf;
    *(ushort *)((int)poutVerts + 0x16) = uVar9;
                    /* Unresolved local var: int clipped@[???]
                       Unresolved local var: float s@[???]
                       Unresolved local var: float t@[???] */
    if ((((((iVar11 == 4) && ((::vert[0][3] == 1.0 || (::vert[0][3] == 0.0)))) &&
          ((::vert[0][4] == 1.0 || (::vert[0][4] == 0.0)))) &&
         ((((::vert[1][3] == 0.0 || (::vert[1][3] == 1.0)) &&
           ((::vert[1][4] == 0.0 || (::vert[1][4] == 1.0)))) &&
          ((::vert[2][3] == 0.0 || (::vert[2][3] == 1.0)))))) &&
        ((::vert[2][4] == 0.0 || (::vert[2][4] == 1.0)))) &&
       (((::vert[3][3] == 0.0 || (::vert[3][3] == 1.0)) &&
        ((::vert[3][4] == 0.0 || (::vert[3][4] == 1.0)))))) {
      *(ushort *)((int)poutVerts + 0x16) = uVar9 | 0x40;
    }
  }
  *(int *)ptexture->name = iVar11;
  return ::vert[0];
}


// R_DecalVertsClip  @ 001954c0
float * R_DecalVertsClip(float *poutVerts,decal_t *pdecal,msurface_t *psurf,texture_t *ptexture,
                        int *pvertCount)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  ushort uVar9;
  float *pfVar10;
  float (*out) [7];
  float *out_00;
  float *out_01;
  float *out_02;
  texture_t *vertCount;
  int vertCount_00;
  int vertCount_01;
  int iVar11;
  int in_stack_ffffffd4;
  
                    /* Unresolved local var: float * v@[???]
                       Unresolved local var: float scalex@[???]
                       Unresolved local var: float scaley@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int outCount@[???] */
  vertCount = psurf->texinfo->texture;
  uVar3 = vertCount->width;
  fVar1 = pdecal->scale;
  uVar4 = ptexture->width;
  uVar5 = vertCount->height;
  uVar6 = ptexture->height;
  if (poutVerts == (float *)0x0) {
    poutVerts = vert[0];
  }
  fVar2 = pdecal->scale;
  out = psurf->polys->verts;
  pfVar10 = (float *)psurf->polys->numverts;
  if (0 < (int)pfVar10) {
    vertCount = (texture_t *)(vert[0] + 3);
    iVar11 = 0;
    do {
      (*(float (*) [7])((int)vertCount + -0xc))[0] = (*out)[0];
      *(float *)((int)vertCount + -8) = (*out)[1];
      *(float *)((int)vertCount + -4) = (*out)[2];
      fVar7 = ((*out)[3] - pdecal->dx) * (((float)uVar3 * fVar1) / (float)uVar4);
      *(float *)vertCount = fVar7;
      fVar8 = ((*out)[4] - pdecal->dy) * (((float)uVar5 * fVar2) / (float)uVar6);
      *(float *)((int)vertCount + 4) = fVar8;
      uVar9 = pdecal->flags;
      if ((uVar9 & 8) != 0) {
        *(float *)vertCount = 1.0 - fVar7;
        uVar9 = pdecal->flags;
      }
      if ((uVar9 & 0x10) != 0) {
        *(float *)((int)vertCount + 4) = 1.0 - fVar8;
      }
      iVar11 = iVar11 + 1;
      out = out + 1;
      vertCount = (texture_t *)((int)vertCount + 0x1c);
      pfVar10 = (float *)psurf->polys->numverts;
    } while (iVar11 < (int)pfVar10);
  }
  pfVar10 = (float *)SHClip(pfVar10,(int)vertCount,*out,in_stack_ffffffd4);
  pfVar10 = (float *)SHClip(pfVar10,vertCount_00,out_00,in_stack_ffffffd4);
  pfVar10 = (float *)SHClip(pfVar10,vertCount_01,out_01,in_stack_ffffffd4);
  iVar11 = SHClip(pfVar10,(int)poutVerts,out_02,in_stack_ffffffd4);
  if ((iVar11 != 0) && ((pdecal->flags & 0x20U) != 0)) {
    uVar9 = pdecal->flags & 0xffdf;
    pdecal->flags = uVar9;
    if (iVar11 == 4) {
                    /* Unresolved local var: float s@[???]
                       Unresolved local var: float t@[???] */
      if ((((*(float (*) [7])poutVerts)[3] == 1.0) || ((*(float (*) [7])poutVerts)[3] == 0.0)) &&
         (((*(float (*) [7])poutVerts)[4] == 1.0 || ((*(float (*) [7])poutVerts)[4] == 0.0)))) {
        if ((((*(float (*) [7])((int)poutVerts + 0x1c))[3] == 0.0) ||
            ((*(float (*) [7])((int)poutVerts + 0x1c))[3] == 1.0)) &&
           (((*(float (*) [7])((int)poutVerts + 0x1c))[4] == 0.0 ||
            ((*(float (*) [7])((int)poutVerts + 0x1c))[4] == 1.0)))) {
          if ((((*(float (*) [7])((int)poutVerts + 0x38))[3] == 0.0) ||
              ((*(float (*) [7])((int)poutVerts + 0x38))[3] == 1.0)) &&
             (((*(float (*) [7])((int)poutVerts + 0x38))[4] == 0.0 ||
              ((*(float (*) [7])((int)poutVerts + 0x38))[4] == 1.0)))) {
            if ((((*(float (*) [7])((int)poutVerts + 0x54))[3] == 0.0) ||
                ((*(float (*) [7])((int)poutVerts + 0x54))[3] == 1.0)) &&
               (((*(float (*) [7])((int)poutVerts + 0x54))[4] == 0.0 ||
                ((*(float (*) [7])((int)poutVerts + 0x54))[4] == 1.0)))) {
              pdecal->flags = uVar9 | 0x40;
            }
          }
        }
      }
    }
  }
  *pvertCount = iVar11;
  return *(float (*) [7])poutVerts;
}


// R_DecalVertsLight  @ 00195400
void R_DecalVertsLight(float *v,msurface_t *psurf,int vertCount)

{
  short sVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  mtexinfo_t *pmVar6;
  int iVar7;
  int iVar8;
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: float s@[???]
                       Unresolved local var: float t@[???] */
  if (0 < vertCount) {
    iVar8 = 0;
    do {
      pmVar6 = psurf->texinfo;
      iVar8 = iVar8 + 1;
      fVar2 = pmVar6->vecs[1][0];
      fVar3 = pmVar6->vecs[1][1];
      fVar4 = pmVar6->vecs[1][2];
      fVar5 = pmVar6->vecs[1][3];
      iVar7 = psurf->light_t;
      sVar1 = psurf->texturemins[1];
      v[5] = ((float)(psurf->light_s << 4) +
              ((v[2] * pmVar6->vecs[0][2] + v[1] * pmVar6->vecs[0][1] + *v * pmVar6->vecs[0][0] +
               pmVar6->vecs[0][3]) - (float)psurf->texturemins[0]) + 8.0) * 0.00048828125;
      v[6] = ((float)(iVar7 << 4) +
              ((v[2] * fVar4 + v[1] * fVar3 + *v * fVar2 + fVar5) - (float)sVar1) + 8.0) *
             0.00048828125;
      v = v + 7;
    } while (vertCount != iVar8);
  }
  return;
}


// R_DecalVertsNoclip  @ 00195b10
float * R_DecalVertsNoclip(decal_t *pdecal,msurface_t *psurf,texture_t *ptexture,
                          qboolean bMultitexture)

{
  short sVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  mtexinfo_t *pmVar6;
  int iVar7;
  float *pfVar8;
  uint uVar9;
  uint uVar10;
  int local_10 [2];
  
                    /* Unresolved local var: float * vlist@[???]
                       Unresolved local var: decalcache_t * pCache@[???]
                       Unresolved local var: int decalIndex@[???]
                       Unresolved local var: int outCount@[???] */
  uVar10 = ((int)(pdecal + -0x49fd8) >> 2) * -0x49249249;
                    /* Unresolved local var: int cacheIndex@[???] */
  uVar9 = uVar10 & 0xff;
  if (gDecalCache[uVar9].decalIndex == uVar10) {
    return gDecalCache[uVar9].decalVert[0];
  }
  gDecalCache[uVar9].decalIndex = uVar10;
  pfVar8 = R_DecalVertsClip(gDecalCache[uVar9].decalVert[0],pdecal,psurf,ptexture,local_10);
  if (bMultitexture == false) {
    return pfVar8;
  }
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: float s@[???]
                       Unresolved local var: float t@[???] */
  pmVar6 = psurf->texinfo;
  iVar7 = psurf->light_t;
  fVar2 = pmVar6->vecs[1][1];
  fVar3 = pmVar6->vecs[1][0];
  fVar4 = pmVar6->vecs[1][2];
  fVar5 = pmVar6->vecs[1][3];
  sVar1 = psurf->texturemins[1];
  pfVar8[5] = ((float)(psurf->light_s << 4) +
               ((pfVar8[2] * pmVar6->vecs[0][2] +
                 *pfVar8 * pmVar6->vecs[0][0] + pfVar8[1] * pmVar6->vecs[0][1] + pmVar6->vecs[0][3])
               - (float)psurf->texturemins[0]) + 8.0) * 0.00048828125;
  pfVar8[6] = ((float)(iVar7 << 4) +
               ((pfVar8[2] * fVar4 + *pfVar8 * fVar3 + pfVar8[1] * fVar2 + fVar5) - (float)sVar1) +
              8.0) * 0.00048828125;
  pmVar6 = psurf->texinfo;
  iVar7 = psurf->light_t;
  fVar2 = pmVar6->vecs[1][1];
  fVar3 = pmVar6->vecs[1][0];
  fVar4 = pmVar6->vecs[1][2];
  fVar5 = pmVar6->vecs[1][3];
  sVar1 = psurf->texturemins[1];
  pfVar8[0xc] = ((float)(psurf->light_s << 4) +
                 ((pfVar8[9] * pmVar6->vecs[0][2] +
                   pfVar8[7] * pmVar6->vecs[0][0] + pfVar8[8] * pmVar6->vecs[0][1] +
                  pmVar6->vecs[0][3]) - (float)psurf->texturemins[0]) + 8.0) * 0.00048828125;
  pfVar8[0xd] = ((float)(iVar7 << 4) +
                 ((pfVar8[9] * fVar4 + pfVar8[7] * fVar3 + pfVar8[8] * fVar2 + fVar5) - (float)sVar1
                 ) + 8.0) * 0.00048828125;
  pmVar6 = psurf->texinfo;
  fVar2 = pmVar6->vecs[1][0];
  iVar7 = psurf->light_t;
  fVar3 = pmVar6->vecs[1][1];
  fVar4 = pmVar6->vecs[1][2];
  fVar5 = pmVar6->vecs[1][3];
  sVar1 = psurf->texturemins[1];
  pfVar8[0x13] = ((float)(psurf->light_s << 4) +
                  ((pfVar8[0x10] * pmVar6->vecs[0][2] +
                    pfVar8[0xf] * pmVar6->vecs[0][1] + pfVar8[0xe] * pmVar6->vecs[0][0] +
                   pmVar6->vecs[0][3]) - (float)psurf->texturemins[0]) + 8.0) * 0.00048828125;
  pfVar8[0x14] = ((float)(iVar7 << 4) +
                  ((pfVar8[0x10] * fVar4 + pfVar8[0xf] * fVar3 + pfVar8[0xe] * fVar2 + fVar5) -
                  (float)sVar1) + 8.0) * 0.00048828125;
  pmVar6 = psurf->texinfo;
  fVar2 = pmVar6->vecs[1][0];
  fVar3 = pmVar6->vecs[1][1];
  fVar4 = pmVar6->vecs[1][2];
  fVar5 = pmVar6->vecs[1][3];
  sVar1 = psurf->texturemins[1];
  iVar7 = psurf->light_t;
  pfVar8[0x1a] = ((float)(psurf->light_s << 4) +
                  ((pfVar8[0x17] * pmVar6->vecs[0][2] +
                    pfVar8[0x16] * pmVar6->vecs[0][1] + pfVar8[0x15] * pmVar6->vecs[0][0] +
                   pmVar6->vecs[0][3]) - (float)psurf->texturemins[0]) + 8.0) * 0.00048828125;
  pfVar8[0x1b] = ((float)(iVar7 << 4) +
                  ((pfVar8[0x17] * fVar4 + pfVar8[0x16] * fVar3 + pfVar8[0x15] * fVar2 + fVar5) -
                  (float)sVar1) + 8.0) * 0.00048828125;
  return pfVar8;
}


// R_DefaultSprite  @ 0014f150
TEMPENTITY * R_DefaultSprite(float *pos,int spriteIndex,float framerate)

{
  float fVar1;
  model_t *model;
  int iVar2;
  TEMPENTITY *pTVar3;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: int frameCount@[???]
                       Unresolved local var: model_t * pSprite@[???] */
  if (cl.time != cl.oldtime) {
    model = CL_GetModelByIndex(spriteIndex);
    if (((spriteIndex == 0) || (model == (model_t *)0x0)) || (model->type != mod_sprite)) {
      Con_DPrintf("No Sprite %d!\n",spriteIndex);
    }
    else {
      iVar2 = ModelFrameCount(model);
      pTVar3 = (*efx.CL_TempEntAlloc)(pos,model);
      if (pTVar3 != (TEMPENTITY *)0x0) {
        pTVar3->flags = pTVar3->flags | 0x100;
        pTVar3->frameMax = (float)iVar2;
        fVar1 = 10.0;
        if (framerate != 0.0) {
          fVar1 = framerate;
        }
        framerate = fVar1;
        (pTVar3->entity).curstate.framerate = framerate;
        pTVar3->die = (float)iVar2 / framerate + (float)cl.time;
        (pTVar3->entity).curstate.frame = 0.0;
        (pTVar3->entity).origin[0] = *pos;
        (pTVar3->entity).origin[1] = pos[1];
        (pTVar3->entity).origin[2] = pos[2];
        return pTVar3;
      }
    }
  }
  return (TEMPENTITY *)0x0;
}


// R_DestroyObjects  @ 001c07a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_DestroyObjects(void)

{
  if (transObjects != (transObjRef *)0x0) {
    Mem_Free(transObjects);
    transObjects = (transObjRef *)0x0;
    maxTransObjs = 0;
    return;
  }
  maxTransObjs = 0;
  return;
}


// R_DrawAliasModel  @ 0017d4c0
void R_DrawAliasModel(cl_entity_t *e)

{
  float fVar1;
  model_s *s1;
  int iVar2;
  int iVar3;
  aliashdr_t *paliashdr;
  int posenum;
  mplane_t *p;
  float *pfVar4;
  float fVar5;
  double local_5c;
  double local_54 [2];
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int lnum@[???]
                       Unresolved local var: vec3_t dist@[???]
                       Unresolved local var: float add@[???]
                       Unresolved local var: model_t * clmodel@[???]
                       Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: aliashdr_t * paliashdr@[???]
                       Unresolved local var: float an@[???] */
  p = frustum;
  s1 = currententity->model;
  local_34 = s1->mins[0] + currententity->origin[0];
  local_30 = s1->mins[1] + currententity->origin[1];
  local_2c = s1->mins[2] + currententity->origin[2];
  local_28 = currententity->origin[0] + s1->maxs[0];
  local_24 = currententity->origin[1] + s1->maxs[1];
  local_20 = currententity->origin[2] + s1->maxs[2];
  do {
                    /* Unresolved local var: int i@[???] */
    iVar3 = BoxOnPlaneSide(&local_34,&local_28,p);
    if (iVar3 == 2) {
      return;
    }
    p = p + 1;
  } while (p != (mplane_t *)&r_oldviewleaf);
  r_entorigin[0] = currententity->origin[0];
  r_entorigin[1] = currententity->origin[1];
  r_entorigin[2] = currententity->origin[2];
  modelorg[0] = r_origin[0] - r_entorigin[0];
  modelorg[1] = r_origin[1] - r_entorigin[1];
  modelorg[2] = r_origin[2] - r_entorigin[2];
  if ((e == &cl.viewent) && (ambientlight < 24.0)) {
    shadelight = 24.0;
    ambientlight = 24.0;
  }
  pfVar4 = &cl_dlights[0].die;
  do {
    while (*pfVar4 < (float)cl.time) {
LAB_0017d5d0:
      pfVar4 = pfVar4 + 10;
      if (pfVar4 == (float *)(cl_lightstyle[0].map + 0x10)) goto LAB_0017d643;
    }
    local_40 = currententity->origin[0] - ((dlight_t *)(pfVar4 + -5))->origin[0];
    local_3c = currententity->origin[1] - pfVar4[-4];
    local_38 = currententity->origin[2] - pfVar4[-3];
    fVar1 = pfVar4[-2];
    fVar5 = Length(&local_40);
    if (fVar1 - fVar5 <= 0.0) goto LAB_0017d5d0;
    ambientlight = (fVar1 - fVar5) + ambientlight;
    pfVar4 = pfVar4 + 10;
  } while (pfVar4 != (float *)(cl_lightstyle[0].map + 0x10));
LAB_0017d643:
  if (128.0 < ambientlight) {
    ambientlight = 128.0;
  }
  if (192.0 < shadelight + ambientlight) {
    shadelight = 192.0 - ambientlight;
  }
  iVar3 = Q_strcmp(s1->name,"progs/flame2.mdl");
  if ((iVar3 == 0) || (iVar3 = Q_strcmp(s1->name,"progs/flame.mdl"), iVar3 == 0)) {
    ambientlight = 256.0;
    shadelight = 1.28;
  }
  else {
    shadelight = shadelight / 200.0;
  }
  shadedots = r_avertexnormal_dots[(int)(e->angles[1] * 0.044444446) & 0xf];
  sincos((double)-((e->angles[1] / 180.0) * 3.1415927),local_54,&local_5c);
  shadevector[2] = 1.0;
  shadevector[0] = (vec_t)local_5c;
  shadevector[1] = (vec_t)local_54[0];
  VectorNormalize(shadevector);
  paliashdr = Mod_Extradata(currententity->model);
  c_alias_polys = c_alias_polys + paliashdr->numtris;
  (*qglPushMatrix)();
  R_RotateForEntity(e->origin,e);
  (*qglTranslatef)(paliashdr->scale_origin[0],paliashdr->scale_origin[1],paliashdr->scale_origin[2])
  ;
  (*qglScalef)(paliashdr->scale[0],paliashdr->scale[1],paliashdr->scale[2]);
  GL_Bind(paliashdr->gl_texturenum[(currententity->curstate).skin]);
  (*qglShadeModel)(0x1d01);
  (*qglTexEnvf)(0x2300,0x2200,8448.0);
  if (gl_affinemodels.value != 0.0) {
    (*qglHint)(0xc50,0x1101);
  }
  iVar3 = (int)(currententity->curstate).frame;
                    /* Unresolved local var: int pose@[???]
                       Unresolved local var: int numposes@[???]
                       Unresolved local var: float interval@[???] */
  if ((paliashdr->numframes <= iVar3) || (iVar3 < 0)) {
    Con_DPrintf("R_AliasSetupFrame: no such frame %d\n");
    iVar3 = 0;
  }
  iVar2 = paliashdr->frames[iVar3].numposes;
  posenum = paliashdr->frames[iVar3].firstpose;
  if (1 < iVar2) {
    posenum = posenum + (int)(cl.time / (double)paliashdr->frames[iVar3].interval) % iVar2;
  }
  GL_DrawAliasFrame(paliashdr,posenum);
  (*qglTexEnvf)(0x2300,0x2200,7681.0);
  (*qglShadeModel)(0x1d00);
  if (gl_affinemodels.value != 0.0) {
    (*qglHint)(0xc50,0x1102);
  }
  (*qglPopMatrix)();
  if (r_shadows.value == 0.0) {
    return;
  }
  (*qglPushMatrix)();
  R_RotateForEntity(e->origin,e);
  (*qglDisable)(0xde1);
  (*qglEnable)(0xbe2);
  (*qglColor4f)(0.0,0.0,0.0,0.5);
  GL_DrawAliasShadow(paliashdr,lastposenum);
  (*qglEnable)(0xde1);
  (*qglDisable)(0xbe2);
  (*qglColor4f)(1.0,1.0,1.0,1.0);
  (*qglPopMatrix)();
  return;
}


// R_DrawBeamEntList  @ 001a0420
void R_DrawBeamEntList(float frametime)

{
  float fVar1;
  cl_entity_t *ent;
  int index;
  float fVar2;
  int iVar3;
  model_t *model;
  uint uVar4;
  int iVar5;
  float fVar6;
  BEAM local_98;
  
                    /* Unresolved local var: BEAM beam@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int beamType@[???]
                       Unresolved local var: cl_entity_t * ent@[???] */
  if (0 < cl_numbeamentities) {
    iVar5 = 0;
    do {
      ent = cl_beamentities[iVar5];
      fVar6 = (ent->curstate).animtime;
      uVar4 = (ent->curstate).rendermode;
      iVar3 = CL_FxBlend(ent);
      uVar4 = uVar4 & 0xf;
      fVar2 = (float)(ent->curstate).body * 0.01;
      index = (ent->curstate).movetype;
      fVar1 = (ent->curstate).scale;
      model = CL_GetModelByIndex(index);
      if (model != (model_t *)0x0) {
        local_98.type = 0;
        local_98.frame = 0.0;
        local_98.frameRate = 0.0;
        local_98.modelIndex = index;
        local_98.frameCount = ModelFrameCount(model);
        local_98.source[0] = ent->origin[0];
        local_98.source[1] = ent->origin[1];
        local_98.source[2] = ent->origin[2];
        local_98.target[0] = (ent->curstate).angles[0];
        local_98.delta[0] = (ent->curstate).angles[0] - ent->origin[0];
        local_98.target[1] = (ent->curstate).angles[1];
        local_98.target[2] = (ent->curstate).angles[2];
        local_98.delta[1] = (ent->curstate).angles[1] - ent->origin[1];
        local_98.delta[2] = (ent->curstate).angles[2] - ent->origin[2];
        local_98.freq = (float)cl.time * fVar6;
        local_98.die = (float)cl.time + 0.0;
        local_98.width = fVar1;
        local_98.amplitude = fVar2;
        local_98.brightness = (float)iVar3 * 0.003921569;
        local_98.speed = fVar6;
        if (0.5 <= fVar2) {
                    /* Unresolved local var: model_t * sprite@[???] */
          fVar6 = Length(local_98.delta);
          fVar6 = fVar6 * 0.25;
        }
        else {
          fVar6 = Length(local_98.delta);
          fVar6 = fVar6 * 0.075;
        }
        local_98.segments = (int)(fVar6 + 3.0);
        local_98.flags = 0;
      }
      local_98.frameRate = 0.0;
      local_98.b = (float)(ent->curstate).rendercolor.b * 0.003921569;
      local_98.g = (float)(ent->curstate).rendercolor.g * 0.003921569;
      local_98.r = (float)(ent->curstate).rendercolor.r * 0.003921569;
      local_98.frame = (float)(int)(ent->curstate).frame;
      if (uVar4 == 1) {
        local_98.endEntity = (int)(ent->curstate).skin;
        local_98.type = 0;
        local_98.flags = 2;
        local_98.startEntity = 0;
      }
      else if (uVar4 == 2) {
        local_98.flags = 3;
        local_98.startEntity = (ent->curstate).sequence;
        local_98.type = 0;
        local_98.endEntity = (int)(ent->curstate).skin;
      }
      uVar4 = (ent->curstate).rendermode;
      if ((uVar4 & 0x10) != 0) {
        local_98.flags = local_98.flags | 0x10;
      }
      if ((uVar4 & 0x20) != 0) {
        local_98.flags = local_98.flags | 0x20;
      }
      if ((uVar4 & 0x40) != 0) {
        local_98.flags = local_98.flags | 0x40;
      }
      if ((uVar4 & 0x80) != 0) {
        local_98.flags = local_98.flags | 0x80;
      }
      local_98.pFollowModel = (model_s *)0x0;
      iVar5 = iVar5 + 1;
      R_BeamDraw(&local_98,frametime);
    } while (iVar5 < cl_numbeamentities);
  }
  return;
}


// R_DrawBeamFollow  @ 0019e9a0
void R_DrawBeamFollow(BEAM *pbeam)

{
  particle_t *ppVar1;
  particle_s *ppVar2;
  longdouble lVar3;
  longdouble lVar4;
  float fVar5;
  double dVar6;
  vec_t *local_94;
  float local_90;
  vec_t *local_84;
  float local_70;
  float local_6c;
  float local_68;
  float local_64 [3];
  vec_t local_58 [3];
  float local_4c;
  float local_48;
  undefined4 local_44;
  float local_40;
  float local_3c;
  undefined4 local_38;
  vec_t local_34;
  float local_30;
  undefined4 local_2c;
  vec_t local_28 [6];
  
                    /* Unresolved local var: particle_t * pNew@[???]
                       Unresolved local var: particle_t * pHead@[???]
                       Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: float fraction@[???]
                       Unresolved local var: float div@[???]
                       Unresolved local var: float vLast@[???]
                       Unresolved local var: float vStep@[???]
                       Unresolved local var: vec3_t last1@[???]
                       Unresolved local var: vec3_t last2@[???]
                       Unresolved local var: vec3_t screen@[???]
                       Unresolved local var: vec3_t screenLast@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: vec3_t normal@[???] */
  R_FreeDeadParticles(&pbeam->particles);
  ppVar2 = pbeam->particles;
  if ((pbeam->flags & 1) == 0) {
    if (ppVar2 == (particle_s *)0x0) {
      return;
    }
  }
  else {
    if (ppVar2 == (particle_s *)0x0) {
      ppVar1 = free_particles;
      if (free_particles == (particle_t *)0x0) {
        return;
      }
    }
    else {
      local_70 = ppVar2->org[0] - pbeam->source[0];
      local_6c = ppVar2->org[1] - pbeam->source[1];
      local_68 = ppVar2->org[2] - pbeam->source[2];
      fVar5 = Length(&local_70);
      if ((fVar5 < 32.0) || (ppVar1 = free_particles, free_particles == (particle_t *)0x0)) {
        if (fVar5 != 0.0) {
          local_70 = pbeam->source[0];
          local_6c = pbeam->source[1];
          local_68 = pbeam->source[2];
          ScreenTransform(pbeam->source,&local_40);
          ScreenTransform(ppVar2->org,&local_4c);
          goto LAB_0019ead5;
        }
        goto LAB_0019ea78;
      }
    }
    free_particles = ppVar1->next;
    ppVar1->org[0] = pbeam->source[0];
    ppVar1->org[1] = pbeam->source[1];
    ppVar1->org[2] = pbeam->source[2];
    ppVar1->die = pbeam->amplitude + (float)cl.time;
    ppVar1->vel[0] = 0.0;
    ppVar1->vel[1] = 0.0;
    ppVar1->vel[2] = 0.0;
    pbeam->die = pbeam->amplitude + (float)cl.time;
    ppVar1->next = ppVar2;
    pbeam->particles = ppVar1;
    ppVar2 = ppVar1;
  }
LAB_0019ea78:
  if (ppVar2->next == (particle_s *)0x0) {
    return;
  }
  local_70 = ppVar2->org[0];
  local_6c = ppVar2->org[1];
  local_68 = ppVar2->org[2];
  ScreenTransform(ppVar2->org,&local_40);
  ScreenTransform(ppVar2->next->org,&local_4c);
  ppVar2 = ppVar2->next;
LAB_0019ead5:
  local_84 = &local_4c;
  local_94 = &local_70;
  local_34 = local_4c - local_40;
  local_2c = 0;
  local_30 = local_48 - local_3c;
  VectorNormalize(&local_34);
  VectorScale(vup,local_34,local_28);
  VectorMA(local_28,-local_30,vright,local_28);
  VectorMA(local_94,pbeam->width,local_28,local_64);
  VectorMA(local_94,-pbeam->width,local_28,local_58);
  lVar3 = (longdouble)cl.time;
  lVar4 = (longdouble)1 / (longdouble)pbeam->amplitude;
  local_94 = (vec_t *)(float)(((longdouble)pbeam->die - lVar3) * lVar4);
  if (ppVar2 != (particle_s *)0x0) {
    local_90 = 0.0;
    do {
      (*tri.Brightness)((float)local_94);
      (*tri.TexCoord2f)(0.0,0.0);
      (*tri.Vertex3fv)(local_64);
      (*tri.Brightness)((float)local_94);
      (*tri.TexCoord2f)(1.0,0.0);
      (*tri.Vertex3fv)(local_58);
      ScreenTransform(ppVar2->org,local_84);
      local_2c = 0;
      local_34 = local_4c - local_40;
      local_30 = local_48 - local_3c;
      VectorNormalize(&local_34);
      VectorScale(vup,local_34,local_28);
      VectorMA(local_28,-local_30,vright,local_28);
      VectorMA(ppVar2->org,pbeam->width,local_28,local_64);
      VectorMA(ppVar2->org,-pbeam->width,local_28,local_58);
      if (ppVar2->next == (particle_s *)0x0) {
        local_94 = (vec_t *)0x0;
      }
      else {
        local_94 = (vec_t *)((ppVar2->die - (float)cl.time) * (float)lVar4);
      }
      (*tri.Brightness)((float)local_94);
      (*tri.TexCoord2f)(1.0,1.0);
      (*tri.Vertex3fv)(local_58);
      (*tri.Brightness)((float)local_94);
      (*tri.TexCoord2f)(0.0,1.0);
      (*tri.Vertex3fv)(local_64);
      local_40 = local_4c;
      local_3c = local_48;
      local_38 = local_44;
      dVar6 = fmod((double)(local_90 + 1.0),1.0);
      local_90 = (float)dVar6;
      ppVar2 = ppVar2->next;
    } while (ppVar2 != (particle_s *)0x0);
    lVar3 = (longdouble)cl.time;
  }
  ppVar2 = pbeam->particles;
  lVar4 = (longdouble)cl.oldtime;
  if (ppVar2 == (particle_s *)0x0) {
    return;
  }
  do {
    VectorMA(ppVar2->org,(float)(lVar3 - lVar4),ppVar2->vel,ppVar2->org);
    ppVar2 = ppVar2->next;
  } while (ppVar2 != (particle_s *)0x0);
  return;
}


// R_DrawBrushModel  @ 00197840
void R_DrawBrushModel(cl_entity_t *e)

{
  float fVar1;
  float fVar2;
  float fVar3;
  model_s *pmVar4;
  mplane_t *pmVar5;
  bool bVar6;
  qboolean qVar7;
  int iVar8;
  uint uVar9;
  dlight_t *light;
  cl_entity_t *s;
  int iVar10;
  cl_entity_t *bMultitexture;
  qboolean local_6c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: msurface_t * psurf@[???]
                       Unresolved local var: float dot@[???]
                       Unresolved local var: mplane_t * pplane@[???]
                       Unresolved local var: model_t * clmodel@[???]
                       Unresolved local var: qboolean rotated@[???]
                       Unresolved local var: bool cleanUpShaderState@[???] */
  currenttexture = -1;
  pmVar4 = e->model;
  currententity = e;
  if (((e->angles[0] == 0.0) && (e->angles[1] == 0.0)) && (e->angles[2] == 0.0)) {
    bVar6 = false;
    local_58 = pmVar4->mins[0] + e->origin[0];
    local_54 = pmVar4->mins[1] + e->origin[1];
    local_50 = pmVar4->mins[2] + e->origin[2];
    local_4c = pmVar4->maxs[0] + e->origin[0];
    local_48 = pmVar4->maxs[1] + e->origin[1];
    local_44 = pmVar4->maxs[2] + e->origin[2];
  }
  else {
    local_44 = pmVar4->radius;
    bVar6 = true;
    local_58 = e->origin[0] - local_44;
    local_4c = e->origin[0] + local_44;
    local_54 = e->origin[1] - local_44;
    local_48 = e->origin[1] + local_44;
    local_50 = e->origin[2] - local_44;
    local_44 = local_44 + e->origin[2];
  }
  qVar7 = R_CullBox(&local_58,&local_4c);
  if (qVar7 != false) {
    return;
  }
  (*qglColor3f)(1.0,1.0,1.0);
  Q_memset(lightmap_polys,0,0x100);
  fVar1 = r_refdef.vieworg[0] - e->origin[0];
  fVar2 = r_refdef.vieworg[1] - e->origin[1];
  fVar3 = r_refdef.vieworg[2] - e->origin[2];
  modelorg[0] = fVar1;
  modelorg[1] = fVar2;
  modelorg[2] = fVar3;
  if (bVar6) {
                    /* Unresolved local var: vec3_t temp@[???]
                       Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???] */
    AngleVectors(e->angles,&local_40,&local_34,&local_28);
    modelorg[0] = local_38 * fVar3 + local_3c * fVar2 + local_40 * fVar1;
    modelorg[1] = -(local_2c * fVar3 + local_30 * fVar2 + local_34 * fVar1);
    modelorg[2] = fVar3 * local_20 + fVar2 * local_24 + fVar1 * local_28;
  }
  s = (cl_entity_t *)(pmVar4->surfaces + pmVar4->firstmodelsurface);
  if ((pmVar4->firstmodelsurface != 0) && (gl_flashblend.value == 0.0)) {
    light = cl_dlights;
    iVar8 = 0;
    do {
      if (((float)cl.time <= light->die) && (light->radius != 0.0)) {
        fVar1 = light->origin[0];
        fVar2 = light->origin[1];
        fVar3 = light->origin[2];
        light->origin[0] = fVar1 - e->origin[0];
        light->origin[1] = fVar2 - e->origin[1];
        light->origin[2] = fVar3 - e->origin[2];
        R_MarkLights(light,1 << ((byte)iVar8 & 0x1f),pmVar4->nodes + pmVar4->hulls[0].firstclipnode)
        ;
        light->origin[0] = fVar1;
        light->origin[1] = fVar2;
        light->origin[2] = fVar3;
      }
                    /* Unresolved local var: vec3_t saveOrigin@[???] */
      iVar8 = iVar8 + 1;
      light = light + 1;
    } while (iVar8 != 0x20);
  }
  (*qglPushMatrix)();
  R_RotateForEntity(e->origin,e);
  local_6c = (qboolean)(gl_reduce_shader_changes.value == 0.0);
  bMultitexture = e;
  R_SetRenderMode(e);
  iVar8 = pmVar4->nummodelsurfaces;
  if (0 < iVar8) {
    iVar10 = 0;
    do {
      uVar9 = (s->baseline).entityType;
      pmVar5 = (mplane_t *)s->player;
      if ((uVar9 & 0x10) == 0) {
        fVar1 = pmVar5->dist;
LAB_00197b64:
        fVar1 = (modelorg[2] * pmVar5->normal[2] +
                modelorg[1] * pmVar5->normal[1] + modelorg[0] * pmVar5->normal[0]) - fVar1;
        if ((uVar9 & 2) == 0) {
          if (fVar1 <= 0.01) goto LAB_00197ce8;
LAB_00197b9f:
          if (gl_texsort == false) {
            R_SetRenderMode(e);
            iVar8 = 0;
            goto LAB_00197d13;
          }
          if ((g_bHasShaderFunctions != false) && (g_uCurrentProgram != 0)) {
            bMultitexture = (cl_entity_t *)0x0;
            (*qglUseProgram)(0);
            uVar9 = (s->baseline).entityType;
            g_uCurrentProgram = 0;
          }
                    /* Unresolved local var: texture_t * t@[???]
                       Unresolved local var: byte * base@[???]
                       Unresolved local var: int maps@[???] */
          c_brush_polys = c_brush_polys + 1;
          if ((uVar9 & 4) == 0) {
            R_RenderBrushPoly((msurface_t *)s);
            iVar8 = pmVar4->nummodelsurfaces;
            goto LAB_00197c00;
          }
        }
        else {
          if (fVar1 < -0.01) goto LAB_00197b9f;
LAB_00197ce8:
          if ((uVar9 & 0x10) == 0) goto LAB_00197c00;
          R_SetRenderMode(e);
          iVar8 = 1;
LAB_00197d13:
          bMultitexture = s;
          R_DrawSequentialPoly((msurface_t *)s,iVar8,local_6c);
        }
        iVar8 = pmVar4->nummodelsurfaces;
      }
      else if (((pmVar5->type == '\x02') || (gl_watersides.value != 0.0)) &&
              (fVar1 = pmVar5->dist, local_50 + 1.0 < fVar1)) goto LAB_00197b64;
LAB_00197c00:
      iVar10 = iVar10 + 1;
      s = (cl_entity_t *)&(s->baseline).body;
    } while (iVar10 < iVar8);
  }
  if ((g_bHasShaderFunctions != false) && (g_uCurrentProgram != 0)) {
    bMultitexture = (cl_entity_t *)0x0;
    (*qglUseProgram)(0);
    g_uCurrentProgram = 0;
  }
  if ((currententity->curstate).rendermode == 0) {
    if (gl_texsort == false) goto LAB_00197c55;
  }
  else {
    (*qglTexEnvf)(0x2300,0x2200,8448.0);
    bMultitexture = (cl_entity_t *)0xbe2;
    (*qglDisable)(0xbe2);
    if (gl_texsort == false) {
      if ((currententity->curstate).rendermode != 1) goto LAB_00197c55;
    }
    else if ((currententity->curstate).rendermode == 4) {
      if (gl_lightholes.value != 0.0) {
        (*qglDepthFunc)(0x202);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: glpoly_t * p@[???]
                       Unresolved local var: float * v@[???] */
        if (((filterMode == false) && (r_fullbright.value == 0.0)) && (gl_texsort != false)) {
          R_BlendLightmaps();
        }
        if ((gl_ztrick.value == 0.0) || (gldepthmin < 0.5)) {
          (*qglDepthFunc)(0x203);
        }
        else {
          (*qglDepthFunc)(0x206);
        }
      }
      goto LAB_00197c55;
    }
  }
  R_DrawDecals((qboolean)bMultitexture);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: glpoly_t * p@[???]
                       Unresolved local var: float * v@[???] */
  if ((((currententity->curstate).rendermode == 0) && (filterMode == false)) &&
     ((r_fullbright.value == 0.0 && (gl_texsort != false)))) {
    R_BlendLightmaps();
  }
LAB_00197c55:
  (*qglPopMatrix)();
  (*qglDepthMask)('\x01');
  (*qglDisable)(0xbc0);
  (*qglAlphaFunc)(0x205,0.0);
  (*qglDisable)(0xbe2);
  return;
}


// R_DrawCylinder  @ 0019e7b0
void R_DrawCylinder(vec_t *source,vec_t *delta,float width,float scale,float freq,float speed,
                   int segments)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  double dVar6;
  float local_70;
  int local_5c;
  double local_44;
  double local_3c;
  float local_30;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float div@[???]
                       Unresolved local var: float length@[???]
                       Unresolved local var: float fraction@[???]
                       Unresolved local var: float vLast@[???]
                       Unresolved local var: float vStep@[???]
                       Unresolved local var: vec3_t point@[???] */
  if (1 < segments) {
    iVar4 = 0x80;
    if (segments < 0x81) {
      iVar4 = segments;
    }
    fVar5 = Length(delta);
    fVar1 = 0.5;
    if (0.5 <= fVar5 * 0.01) {
      fVar1 = fVar5 * 0.01;
    }
    fVar5 = 1.0 / (float)(iVar4 + -1);
    local_30 = fVar5;
    dVar6 = fmod((double)(freq * speed),1.0);
    local_5c = 0;
    do {
      local_70 = (float)dVar6;
      sincos((double)(((float)local_5c * fVar5 + (float)local_5c * fVar5) * 3.1415927),&local_3c,
             &local_44);
      fVar3 = (float)local_3c;
      local_28 = fVar3 * freq * delta[2] + *source;
      fVar2 = (float)local_44;
      local_24 = delta[2] * freq * fVar2 + source[1];
      local_20 = source[2] + width;
      (*tri.Brightness)(0.0);
      (*tri.TexCoord2f)(1.0,local_70);
      (*tri.Vertex3fv)(&local_28);
      local_28 = fVar3 * freq * (width + delta[2]) + *source;
      local_24 = freq * fVar2 * (width + delta[2]) + source[1];
      local_20 = source[2] - width;
      (*tri.Brightness)(1.0);
      (*tri.TexCoord2f)(0.0,local_70);
      (*tri.Vertex3fv)(&local_28);
      dVar6 = fmod((double)(local_70 + fVar5 * fVar1),1.0);
      local_5c = local_5c + 1;
    } while (local_5c < iVar4);
  }
  return;
}


// R_DrawDecals  @ 00195800
void R_DrawDecals(qboolean bMultitexture)

{
  msurface_t *psurf;
  decal_t *pdecal;
  msurface_t *psurf_00;
  float (*poutVerts) [7];
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *pvertCount;
  int local_30;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: decal_t * plist@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int outCount@[???]
                       Unresolved local var: texture_t * ptexture@[???]
                       Unresolved local var: msurface_t * psurf@[???]
                       Unresolved local var: float * v@[???] */
  if (gDecalSurfCount == 0) {
    return;
  }
  (*qglEnable)(0xbe2);
  (*qglEnable)(0xbc0);
  pvertCount = (int *)0x303;
  (*qglBlendFunc)(0x302,0x303);
  (*qglDepthMask)('\0');
  if (gl_polyoffset.value == 0.0) {
    if (gDecalSurfCount < 1) goto LAB_001959ca;
LAB_0019587b:
    local_30 = 0;
    do {
      psurf = gDecalSurfs[local_30];
      for (pdecal = psurf->pdecals; pdecal != (decal_t *)0x0; pdecal = pdecal->pnext) {
        psurf_00 = (msurface_t *)Draw_DecalTexture((int)pdecal->texture);
        if (((pdecal->flags & 0x40) == 0) &&
           (poutVerts = (float (*) [7])
                        R_DecalVertsClip((float *)pdecal,(decal_t *)psurf,psurf_00,
                                         (texture_t *)&local_24,pvertCount), iVar3 = local_24,
           (pdecal->flags & 0x40) == 0)) {
          if (local_24 != 0) {
            GL_Bind(*(int *)psurf_00->extents);
            pvertCount = (int *)0x2200;
            (*qglTexEnvf)(0x2300,0x2200,8448.0);
            (*qglBegin)(9);
            if (0 < iVar3) goto LAB_00195959;
            goto LAB_0019598c;
          }
        }
        else {
                    /* Unresolved local var: float * vlist@[???]
                       Unresolved local var: decalcache_t * pCache@[???]
                       Unresolved local var: int decalIndex@[???]
                       Unresolved local var: int outCount@[???] */
          uVar2 = ((int)(pdecal + -0x49fd8) >> 2) * -0x49249249;
                    /* Unresolved local var: int cacheIndex@[???] */
          uVar1 = uVar2 & 0xff;
          poutVerts = gDecalCache[uVar1].decalVert;
          if (uVar2 - gDecalCache[uVar1].decalIndex != 0) {
            gDecalCache[uVar1].decalIndex = uVar2;
            poutVerts = (float (*) [7])
                        R_DecalVertsClip(*poutVerts,pdecal,psurf,(texture_t *)psurf_00,local_20);
          }
                    /* Unresolved local var: int j@[???] */
          local_24 = 4;
          iVar3 = 4;
          GL_Bind(*(int *)psurf_00->extents);
          (*qglTexEnvf)(0x2300,0x2200,8448.0);
          (*qglBegin)(9);
LAB_00195959:
          iVar4 = 0;
          do {
            pvertCount = (int *)(*poutVerts)[4];
            iVar4 = iVar4 + 1;
            (*qglTexCoord2f)((*poutVerts)[3],(GLfloat)pvertCount);
            (*qglVertex3fv)(*poutVerts);
            poutVerts = poutVerts + 1;
          } while (iVar3 != iVar4);
LAB_0019598c:
          (*qglEnd)();
        }
      }
      local_30 = local_30 + 1;
    } while (local_30 < gDecalSurfCount);
  }
  else {
    (*qglEnable)(0x8037);
    if ((gl_ztrick.value == 0.0) || (gldepthmin < 0.5)) {
      pvertCount = (int *)-gl_polyoffset.value;
      (*qglPolygonOffset)(-1.0,(GLfloat)pvertCount);
    }
    else {
      pvertCount = (int *)gl_polyoffset.value;
      (*qglPolygonOffset)(1.0,gl_polyoffset.value);
    }
    if (0 < gDecalSurfCount) goto LAB_0019587b;
  }
  if (gl_polyoffset.value != 0.0) {
    (*qglDisable)(0x8037);
  }
LAB_001959ca:
  (*qglDisable)(0xbc0);
  (*qglDisable)(0xbe2);
  (*qglDepthMask)('\x01');
  gDecalSurfCount = 0;
  return;
}


// R_DrawDecals  @ 00197f60
void R_DrawDecals(qboolean bMultitexture)

{
  short sVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  msurface_t *psurf;
  mtexinfo_t *pmVar9;
  msurface_t *psurf_00;
  float (*v) [7];
  uint uVar10;
  uint uVar11;
  decal_s *pdecal;
  int iVar12;
  int iVar13;
  msurface_t *pvertCount;
  int local_34;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: decal_t * plist@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int outCount@[???]
                       Unresolved local var: texture_t * ptexture@[???]
                       Unresolved local var: msurface_t * psurf@[???]
                       Unresolved local var: float * v@[???] */
  if (gDecalSurfCount == 0) {
    return;
  }
  (*qglEnable)(0xbe2);
  (*qglEnable)(0xbc0);
  pvertCount = (msurface_t *)0x303;
  (*qglBlendFunc)(0x302,0x303);
  (*qglDepthMask)('\0');
  if (gl_polyoffset.value == 0.0) {
    if (gDecalSurfCount < 1) goto LAB_0019838a;
LAB_00197fdc:
    local_34 = 0;
    do {
      psurf = gDecalSurfs[local_34];
      for (pdecal = psurf->pdecals; pdecal != (decal_t *)0x0; pdecal = pdecal->pnext) {
LAB_0019827c:
        psurf_00 = (msurface_t *)Draw_DecalTexture((int)pdecal->texture);
        if ((pdecal->flags & 0x40) != 0) {
LAB_00198010:
                    /* Unresolved local var: float * vlist@[???]
                       Unresolved local var: decalcache_t * pCache@[???]
                       Unresolved local var: int decalIndex@[???]
                       Unresolved local var: int outCount@[???] */
          uVar11 = ((int)(pdecal + -0x49fd8) >> 2) * -0x49249249;
                    /* Unresolved local var: int cacheIndex@[???] */
          uVar10 = uVar11 & 0xff;
          v = gDecalCache[uVar10].decalVert;
          if (uVar11 - gDecalCache[uVar10].decalIndex != 0) {
            gDecalCache[uVar10].decalIndex = uVar11;
            v = (float (*) [7])R_DecalVertsClip(*v,pdecal,psurf,(texture_t *)psurf_00,local_20);
            if (bMultitexture != false) {
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: float s@[???]
                       Unresolved local var: float t@[???] */
              pmVar9 = psurf->texinfo;
              iVar13 = psurf->light_t;
              fVar2 = (*v)[0];
              fVar3 = pmVar9->vecs[1][0];
              fVar4 = pmVar9->vecs[1][1];
              fVar5 = pmVar9->vecs[1][2];
              fVar6 = pmVar9->vecs[1][3];
              sVar1 = psurf->texturemins[1];
              (*v)[5] = ((float)(psurf->light_s << 4) +
                         (((*v)[2] * pmVar9->vecs[0][2] +
                           (*v)[1] * pmVar9->vecs[0][1] + (*v)[0] * pmVar9->vecs[0][0] +
                          pmVar9->vecs[0][3]) - (float)psurf->texturemins[0]) + 8.0) * 0.00048828125
              ;
              (*v)[6] = ((float)(iVar13 << 4) +
                         (((*v)[2] * fVar5 + (*v)[1] * fVar4 + fVar2 * fVar3 + fVar6) - (float)sVar1
                         ) + 8.0) * 0.00048828125;
              pmVar9 = psurf->texinfo;
              iVar13 = psurf->light_t;
              fVar2 = v[1][0];
              fVar3 = pmVar9->vecs[1][0];
              fVar4 = v[1][1];
              fVar5 = pmVar9->vecs[1][1];
              fVar6 = v[1][2];
              fVar7 = pmVar9->vecs[1][2];
              fVar8 = pmVar9->vecs[1][3];
              sVar1 = psurf->texturemins[1];
              v[1][5] = ((float)(psurf->light_s << 4) +
                         ((v[1][2] * pmVar9->vecs[0][2] +
                           v[1][1] * pmVar9->vecs[0][1] + v[1][0] * pmVar9->vecs[0][0] +
                          pmVar9->vecs[0][3]) - (float)psurf->texturemins[0]) + 8.0) * 0.00048828125
              ;
              v[1][6] = ((float)(iVar13 << 4) +
                         ((fVar6 * fVar7 + fVar4 * fVar5 + fVar2 * fVar3 + fVar8) - (float)sVar1) +
                        8.0) * 0.00048828125;
              pmVar9 = psurf->texinfo;
              iVar13 = psurf->light_t;
              fVar2 = v[2][0];
              fVar3 = pmVar9->vecs[1][0];
              fVar4 = v[2][1];
              fVar5 = pmVar9->vecs[1][1];
              fVar6 = v[2][2];
              fVar7 = pmVar9->vecs[1][2];
              fVar8 = pmVar9->vecs[1][3];
              sVar1 = psurf->texturemins[1];
              v[2][5] = ((float)(psurf->light_s << 4) +
                         ((v[2][2] * pmVar9->vecs[0][2] +
                           v[2][1] * pmVar9->vecs[0][1] + v[2][0] * pmVar9->vecs[0][0] +
                          pmVar9->vecs[0][3]) - (float)psurf->texturemins[0]) + 8.0) * 0.00048828125
              ;
              v[2][6] = ((float)(iVar13 << 4) +
                         ((fVar6 * fVar7 + fVar4 * fVar5 + fVar2 * fVar3 + fVar8) - (float)sVar1) +
                        8.0) * 0.00048828125;
              pmVar9 = psurf->texinfo;
              fVar2 = v[3][0];
              fVar3 = pmVar9->vecs[1][0];
              fVar4 = v[3][1];
              fVar5 = pmVar9->vecs[1][1];
              fVar6 = v[3][2];
              fVar7 = pmVar9->vecs[1][2];
              fVar8 = pmVar9->vecs[1][3];
              sVar1 = psurf->texturemins[1];
              iVar13 = psurf->light_t;
              v[3][5] = ((float)(psurf->light_s << 4) +
                         ((v[3][2] * pmVar9->vecs[0][2] +
                           v[3][1] * pmVar9->vecs[0][1] + v[3][0] * pmVar9->vecs[0][0] +
                          pmVar9->vecs[0][3]) - (float)psurf->texturemins[0]) + 8.0) * 0.00048828125
              ;
              v[3][6] = ((float)(iVar13 << 4) +
                         ((fVar6 * fVar7 + fVar4 * fVar5 + fVar2 * fVar3 + fVar8) - (float)sVar1) +
                        8.0) * 0.00048828125;
            }
          }
          local_24 = 4;
          if (bMultitexture == false) {
            iVar13 = 4;
            GL_Bind(*(int *)psurf_00->extents);
            (*qglTexEnvf)(0x2300,0x2200,8448.0);
            (*qglBegin)(9);
            goto LAB_00198314;
          }
LAB_0019825a:
          R_DecalMPoly(*v,(texture_t *)psurf_00,psurf,local_24);
          pvertCount = psurf_00;
LAB_00198272:
          pdecal = pdecal->pnext;
          if (pdecal == (decal_s *)0x0) break;
          goto LAB_0019827c;
        }
        v = (float (*) [7])
            R_DecalVertsClip((float *)pdecal,(decal_t *)psurf,psurf_00,(texture_t *)&local_24,
                             &pvertCount->visframe);
        if ((bMultitexture != false) && (local_24 != 0)) {
          pvertCount = psurf;
          R_DecalVertsLight((float *)v,psurf,local_24);
        }
        iVar13 = local_24;
        if ((pdecal->flags & 0x40) != 0) goto LAB_00198010;
        if (local_24 == 0) goto LAB_00198272;
        if (bMultitexture != false) goto LAB_0019825a;
                    /* Unresolved local var: int j@[???] */
        GL_Bind(*(int *)psurf_00->extents);
        pvertCount = (msurface_t *)0x2200;
        (*qglTexEnvf)(0x2300,0x2200,8448.0);
        (*qglBegin)(9);
        if (0 < iVar13) {
LAB_00198314:
          iVar12 = 0;
          do {
            pvertCount = (msurface_t *)(*v)[4];
            iVar12 = iVar12 + 1;
            (*qglTexCoord2f)((*v)[3],(GLfloat)pvertCount);
            (*qglVertex3fv)(*v);
            v = v + 1;
          } while (iVar13 != iVar12);
        }
        (*qglEnd)();
      }
      local_34 = local_34 + 1;
    } while (local_34 < gDecalSurfCount);
  }
  else {
    (*qglEnable)(0x8037);
    if ((gl_ztrick.value == 0.0) || (gldepthmin < 0.5)) {
      pvertCount = (msurface_t *)-gl_polyoffset.value;
      (*qglPolygonOffset)(-1.0,(GLfloat)pvertCount);
    }
    else {
      pvertCount = (msurface_t *)gl_polyoffset.value;
      (*qglPolygonOffset)(1.0,gl_polyoffset.value);
    }
    if (0 < gDecalSurfCount) goto LAB_00197fdc;
  }
  if (gl_polyoffset.value != 0.0) {
    (*qglDisable)(0x8037);
  }
LAB_0019838a:
  (*qglDisable)(0xbc0);
  (*qglDisable)(0xbe2);
  (*qglDepthMask)('\x01');
  gDecalSurfCount = 0;
  return;
}


// R_DrawDisk  @ 0019e5e0
void R_DrawDisk(vec_t *source,vec_t *delta,float width,float scale,float freq,float speed,
               int segments)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  double dVar7;
  float local_60;
  double local_44;
  double local_3c;
  float local_30;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float div@[???]
                       Unresolved local var: float length@[???]
                       Unresolved local var: float fraction@[???]
                       Unresolved local var: float vLast@[???]
                       Unresolved local var: float vStep@[???]
                       Unresolved local var: vec3_t point@[???]
                       Unresolved local var: float w@[???] */
  if (1 < segments) {
    iVar3 = 0x80;
    if (segments < 0x81) {
      iVar3 = segments;
    }
    fVar6 = Length(delta);
    fVar1 = 0.5;
    if (0.5 <= fVar6 * 0.01) {
      fVar1 = fVar6 * 0.01;
    }
    fVar2 = 1.0 / (float)(iVar3 + -1);
    local_30 = fVar2;
    dVar7 = fmod((double)(freq * speed),1.0);
    fVar6 = delta[2];
    iVar4 = 0;
    do {
      local_60 = (float)dVar7;
      local_28 = *source;
      iVar5 = iVar4 + 1;
      local_24 = source[1];
      local_20 = source[2];
      (*tri.Brightness)(1.0);
      (*tri.TexCoord2f)(1.0,local_60);
      (*tri.Vertex3fv)(&local_28);
      sincos((double)(((float)iVar4 * fVar2 + (float)iVar4 * fVar2) * 3.1415927),&local_3c,&local_44
            );
      local_28 = (float)local_3c * freq * fVar6 + *source;
      local_24 = (float)local_44 * freq * fVar6 + source[1];
      local_20 = source[2];
      (*tri.Brightness)(1.0);
      (*tri.TexCoord2f)(0.0,local_60);
      (*tri.Vertex3fv)(&local_28);
      dVar7 = fmod((double)(local_60 + fVar2 * fVar1),1.0);
      iVar4 = iVar5;
    } while (iVar5 < iVar3);
  }
  return;
}


// R_DrawEntitiesOnList  @ 0017cec0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_DrawEntitiesOnList(void)

{
  modtype_t mVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  cl_entity_t *pcVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
  if (cl_numvisedicts < 1) {
    r_blend = 1.0;
    return;
  }
  iVar7 = 0;
  iVar6 = cl_numvisedicts;
LAB_0017cee0:
  do {
    while( true ) {
      while( true ) {
        while (currententity = cl_visedicts[iVar7], (currententity->curstate).rendermode != 0) {
          iVar7 = iVar7 + 1;
          AddTEntity((cl_entity_t_conflict *)currententity);
          iVar6 = cl_numvisedicts;
          if (cl_numvisedicts <= iVar7) goto LAB_0017cf69;
        }
        mVar1 = currententity->model->type;
        if (mVar1 != mod_brush) break;
        iVar7 = iVar7 + 1;
        R_DrawBrushModel(currententity);
        iVar6 = cl_numvisedicts;
        if (cl_numvisedicts <= iVar7) goto LAB_0017cf69;
      }
      if (mVar1 == mod_studio) break;
LAB_0017cf60:
      iVar7 = iVar7 + 1;
      if (iVar6 <= iVar7) goto LAB_0017cf69;
    }
    if (currententity->player == false) {
      if ((currententity->curstate).movetype == 0xc) {
        if (iVar6 < 1) goto LAB_0017cf60;
        iVar2 = (currententity->curstate).aiment;
        pcVar5 = cl_visedicts[0];
        if (cl_visedicts[0]->index != iVar2) {
          iVar3 = 0;
          do {
            iVar3 = iVar3 + 1;
            if (iVar3 == iVar6) goto LAB_0017cf60;
            pcVar5 = cl_visedicts[iVar3];
          } while (pcVar5->index != iVar2);
        }
        currententity = pcVar5;
        if (pcVar5->player == false) {
          (*pStudioAPI->StudioDrawModel)(0);
        }
        else {
          (*pStudioAPI->StudioDrawPlayer)
                    (0,(entity_state_s *)
                       ((cl.parsecount & CL_UPDATE_MASK) * 0x4318 + 0xc6aa3c +
                       (pcVar5->index * 5 + -5) * 0x44));
        }
        currententity = cl_visedicts[iVar7];
        iVar7 = iVar7 + 1;
        (*pStudioAPI->StudioDrawModel)(3);
        iVar6 = cl_numvisedicts;
        if (cl_numvisedicts <= iVar7) goto LAB_0017cf69;
      }
      else {
        iVar7 = iVar7 + 1;
        (*pStudioAPI->StudioDrawModel)(3);
        iVar6 = cl_numvisedicts;
        if (cl_numvisedicts <= iVar7) goto LAB_0017cf69;
      }
      goto LAB_0017cee0;
    }
    iVar7 = iVar7 + 1;
    (*pStudioAPI->StudioDrawPlayer)
              (3,(entity_state_s *)
                 ((cl.parsecount & CL_UPDATE_MASK) * 0x4318 + 0xc6aa3c +
                 (currententity->index * 5 + -5) * 0x44));
    iVar6 = cl_numvisedicts;
    if (cl_numvisedicts <= iVar7) {
LAB_0017cf69:
      r_blend = 1.0;
      if (0 < iVar6) {
        iVar7 = 0;
        do {
          currententity = cl_visedicts[iVar7];
          if (((currententity->curstate).rendermode == 0) &&
             (currententity->model->type == mod_sprite)) {
            iVar6 = (currententity->curstate).body;
            if (iVar6 == 0) {
              r_entorigin[0] = currententity->origin[0];
              r_entorigin[1] = currententity->origin[1];
              r_entorigin[2] = currententity->origin[2];
            }
            else {
                    /* Unresolved local var: float * pAttachment@[???] */
              pfVar4 = R_GetAttachmentPoint((int)(currententity->curstate).skin,iVar6);
              r_entorigin[0] = *pfVar4;
              r_entorigin[1] = pfVar4[1];
              r_entorigin[2] = pfVar4[2];
            }
            R_DrawSpriteModel(currententity);
            iVar6 = cl_numvisedicts;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar6);
      }
      return;
    }
  } while( true );
}


// R_DrawEntitiesOnList  @ 0017da60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_DrawEntitiesOnList(void)

{
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
  if (r_drawentities.value != 0.0) {
    R_DrawEntitiesOnList();
    return;
  }
  return;
}


// R_DrawParticles  @ 001a1320
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_DrawParticles(void)

{
  ushort *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  particle_s *ppVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  double dVar10;
  double dVar11;
  short sVar12;
  ptype_t pVar13;
  int iVar14;
  int32 iVar15;
  int in_GS_OFFSET;
  vec_t *local_c0;
  vec_t *local_bc;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  vec_t local_84 [3];
  vec_t local_78 [3];
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_48;
  float local_44;
  float local_3c;
  float local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  float local_28;
  GLubyte local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: particle_t * p@[???]
                       Unresolved local var: float grav@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float time2@[???]
                       Unresolved local var: float time3@[???]
                       Unresolved local var: float time1@[???]
                       Unresolved local var: float dvel@[???]
                       Unresolved local var: float frametime@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: float scale@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  GL_Bind(particletexture);
  (*qglEnable)(0xbc0);
  (*qglEnable)(0xbe2);
  (*qglTexEnvf)(0x2300,0x2200,8448.0);
  (*qglBlendFunc)(0x302,0x303);
  (*qglBegin)(4);
  VectorScale(vup,1.5,&local_9c);
  VectorScale(vright,1.5,&local_90);
  fVar2 = (float)((longdouble)cl.time - (longdouble)cl.oldtime);
  fVar9 = movevars.gravity * fVar2 * 0.05;
  fVar7 = fVar2 * 4.0;
  R_FreeDeadParticles(&active_particles);
  for (ppVar6 = active_particles; ppVar6 != (particle_s *)0x0; ppVar6 = ppVar6->next) {
    pVar13 = ppVar6->type;
    if (pVar13 == pt_blob) {
LAB_001a1639:
      fVar3 = ppVar6->vel[0];
      ppVar6->org[0] = ppVar6->org[0] + fVar2 * fVar3;
      fVar4 = ppVar6->vel[1];
      ppVar6->org[1] = ppVar6->org[1] + fVar2 * fVar4;
      fVar5 = ppVar6->vel[2];
      ppVar6->org[2] = ppVar6->org[2] + fVar2 * fVar5;
      switch(pVar13) {
      case pt_static:
        break;
      case pt_grav:
        ppVar6->vel[2] = fVar5 - fVar9 * 20.0;
        break;
      case pt_slowgrav:
        ppVar6->vel[2] = fVar9;
        break;
      case pt_fire:
        fVar3 = fVar2 * 5.0 + ppVar6->ramp;
        ppVar6->ramp = fVar3;
        if (fVar3 < 6.0) {
          iVar14 = ramp3[(int)fVar3];
          ppVar6->packedColor = 0;
          ppVar6->color = (short)iVar14;
        }
        else {
          ppVar6->die = -1.0;
        }
        ppVar6->vel[2] = fVar5 + fVar9;
        break;
      case pt_explode:
        fVar8 = fVar2 * 10.0 + ppVar6->ramp;
        ppVar6->ramp = fVar8;
        if (fVar8 < 8.0) {
          iVar14 = ramp1[(int)fVar8];
          ppVar6->packedColor = 0;
          ppVar6->color = (short)iVar14;
        }
        else {
          ppVar6->die = -1.0;
        }
        ppVar6->vel[0] = fVar7 * fVar3 + fVar3;
        ppVar6->vel[1] = fVar7 * fVar4 + fVar4;
        ppVar6->vel[2] = (fVar5 + fVar7 * fVar5) - fVar9;
        break;
      case pt_explode2:
        fVar8 = fVar2 * 15.0 + ppVar6->ramp;
        ppVar6->ramp = fVar8;
        if (fVar8 < 8.0) {
          iVar14 = ramp2[(int)fVar8];
          ppVar6->packedColor = 0;
          ppVar6->color = (short)iVar14;
        }
        else {
          ppVar6->die = -1.0;
        }
        ppVar6->vel[0] = fVar3 - fVar2 * fVar3;
        ppVar6->vel[1] = fVar4 - fVar2 * fVar4;
        ppVar6->vel[2] = (fVar5 - fVar2 * fVar5) - fVar9;
        break;
      case pt_blob:
      case pt_blob2:
        fVar8 = fVar2 * 10.0 + ppVar6->ramp;
        if (9.0 <= fVar8) {
          ppVar6->ramp = 0.0;
          iVar14 = 0;
        }
        else {
          ppVar6->ramp = fVar8;
          iVar14 = (int)fVar8;
        }
        iVar14 = gSparkRamp[iVar14];
        ppVar6->packedColor = 0;
        ppVar6->color = (short)iVar14;
        ppVar6->vel[0] = fVar3 - fVar3 * 0.5 * fVar2;
        ppVar6->vel[1] = fVar4 - fVar4 * 0.5 * fVar2;
        ppVar6->vel[2] = fVar5 - fVar9 * 5.0;
        iVar15 = RandomLong(0,3);
        ppVar6->type = ~-(uint)(iVar15 == 0) + pt_blob2;
        break;
      case pt_vox_slowgrav:
        ppVar6->vel[2] = fVar5 - fVar9 * 4.0;
        break;
      case pt_vox_grav:
        ppVar6->vel[2] = fVar5 - fVar9 * 8.0;
      }
    }
    else {
      fVar3 = (ppVar6->org[2] - r_origin[2]) * vpn[2] +
              (ppVar6->org[1] - r_origin[1]) * vpn[1] + vpn[0] * (ppVar6->org[0] - r_origin[0]);
      fVar4 = 1.0;
      if (20.0 <= fVar3) {
        fVar4 = fVar3 * 0.004 + 1.0;
      }
                    /* Unresolved local var: word * pb@[???]
                       Unresolved local var: byte[4] rgba@[???] */
      puVar1 = host_basepal + ppVar6->color * 4;
      if (filterMode == false) {
        local_24 = (GLubyte)puVar1[2];
        local_23 = (undefined1)puVar1[1];
        local_22 = (undefined1)*puVar1;
        local_21 = 0xff;
      }
      else {
        local_24 = (GLubyte)(int)((float)puVar1[2] * filterColorRed * filterBrightness);
        local_23 = (undefined1)(int)((float)puVar1[1] * filterColorGreen * filterBrightness);
        local_22 = (undefined1)(int)((float)*puVar1 * filterColorBlue * filterBrightness);
        local_21 = (undefined1)(int)(filterBrightness * 255.0 * filterBrightness);
      }
      (*qglColor3ubv)(&local_24);
      (*qglTexCoord2f)(0.0,0.0);
      (*qglVertex3fv)(ppVar6->org);
      (*qglTexCoord2f)(1.0,0.0);
      (*qglVertex3f)(local_9c * fVar4 + ppVar6->org[0],local_98 * fVar4 + ppVar6->org[1],
                     local_94 * fVar4 + ppVar6->org[2]);
      (*qglTexCoord2f)(0.0,1.0);
      (*qglVertex3f)(local_90 * fVar4 + ppVar6->org[0],local_8c * fVar4 + ppVar6->org[1],
                     local_88 * fVar4 + ppVar6->org[2]);
      pVar13 = ppVar6->type;
      if (pVar13 != pt_clientcustom) goto LAB_001a1639;
      if (ppVar6->callback != (_func_void_particle_s_ptr_float *)0x0) {
        (*ppVar6->callback)(ppVar6,fVar2);
      }
    }
  }
  (*qglEnd)();
                    /* Unresolved local var: float scale@[???]
                       Unresolved local var: float attenuation@[???]
                       Unresolved local var: float frametime@[???]
                       Unresolved local var: float clipDist@[???]
                       Unresolved local var: float gravity@[???]
                       Unresolved local var: float size@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t start@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: vec3_t screenLast@[???]
                       Unresolved local var: vec3_t screen@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: vec3_t normal@[???]
                       Unresolved local var: int clip@[???]
                       Unresolved local var: qboolean draw@[???] */
  if (gpActiveTracers != (particle_t *)0x0) {
    gTracerColors[4].r = (byte)(int)(tracerRed.value * tracerAlpha.value * 255.0);
    gTracerColors[4].g = (byte)(int)(tracerGreen.value * tracerAlpha.value * 255.0);
    gTracerColors[4].b = (byte)(int)(tracerAlpha.value * tracerBlue.value * 255.0);
    R_FreeDeadParticles(&gpActiveTracers);
    dVar11 = cl.oldtime;
    dVar10 = cl.time;
    VectorScale(vup,1.5,local_84);
    VectorScale(vright,1.5,local_78);
    iVar14 = (*tri.SpriteTexture)(cl_sprite_dot,0);
    if (iVar14 != 0) {
                    /* Unresolved local var: color24 * pColor@[???] */
      fVar2 = (float)((longdouble)dVar10 - (longdouble)dVar11);
      fVar9 = movevars.gravity * fVar2;
      fVar4 = r_origin[2] * vpn[2] + r_origin[1] * vpn[1] + r_origin[0] * vpn[0];
      fVar3 = 1.0 - fVar2 * 0.9;
      fVar7 = 0.0;
      if (0.0 <= fVar3) {
        fVar7 = fVar3;
      }
      (*tri.RenderMode)(5);
      (*tri.CullFace)(TRI_NONE);
      for (ppVar6 = gpActiveTracers; ppVar6 != (particle_t *)0x0; ppVar6 = ppVar6->next) {
        sVar12 = ppVar6->color;
        if ((float)cl.time < ppVar6->die - 0.1) {
          fVar3 = ppVar6->ramp * 0.1;
        }
        else {
          fVar3 = (ppVar6->die - (float)cl.time) * ppVar6->ramp;
        }
        local_60 = ppVar6->vel[0] * fVar3 + ppVar6->org[0];
        local_5c = ppVar6->vel[1] * fVar3 + ppVar6->org[1];
        local_58 = fVar3 * ppVar6->vel[2] + ppVar6->org[2];
        local_6c = ppVar6->org[0];
        local_68 = ppVar6->org[1];
        local_64 = ppVar6->org[2];
        iVar14 = ScreenTransform(&local_6c,&local_54);
        if ((iVar14 == 0) && (iVar14 = ScreenTransform(&local_60,&local_48), iVar14 == 0)) {
LAB_001a19e3:
          local_bc = &local_48;
          local_c0 = &local_60;
          ScreenTransform(&local_6c,&local_54);
          ScreenTransform(local_c0,local_bc);
          local_34 = 0;
          local_3c = local_48 - local_54;
          local_38 = local_44 - local_50;
          fVar3 = gTracerSize[ppVar6->type];
          VectorNormalize(&local_3c);
          VectorScale(vup,fVar3 * local_3c,&local_30);
          VectorMA(&local_30,fVar3 * -local_38,vright,&local_30);
          (*tri.Begin)(2);
          (*tri.Color4ub)(gTracerColors[sVar12].r,gTracerColors[sVar12].g,gTracerColors[sVar12].b,
                          (uchar)ppVar6->packedColor);
          (*tri.Brightness)(0.0);
          (*tri.TexCoord2f)(0.0,0.0);
          (*tri.Vertex3f)(local_6c + local_30,local_68 + local_2c,local_64 + local_28);
          (*tri.Brightness)(1.0);
          (*tri.TexCoord2f)(0.0,1.0);
          (*tri.Vertex3f)(local_60 + local_30,local_5c + local_2c,local_58 + local_28);
          (*tri.Brightness)(1.0);
          (*tri.TexCoord2f)(1.0,1.0);
          (*tri.Vertex3f)(local_60 - local_30,local_5c - local_2c,local_58 - local_28);
          (*tri.Brightness)(0.0);
          (*tri.TexCoord2f)(1.0,0.0);
          (*tri.Vertex3f)(local_6c - local_30,local_68 - local_2c,local_64 - local_28);
          (*tri.End)();
        }
        else {
                    /* Unresolved local var: float fraction@[???]
                       Unresolved local var: float dist1@[???]
                       Unresolved local var: float dist2@[???] */
          fVar5 = (vpn[2] * local_64 + vpn[1] * local_68 + vpn[0] * local_6c) - fVar4;
          fVar3 = (vpn[2] * local_58 + vpn[1] * local_5c + vpn[0] * local_60) - fVar4;
          if (((0.0 < fVar5) || (0.0 < fVar3)) && (fVar3 = fVar3 - fVar5, 0.01 <= fVar3)) {
            fVar3 = fVar5 / fVar3;
            fVar8 = (local_60 - local_6c) * fVar3;
            if (fVar5 <= 0.0) {
              local_6c = fVar8 + local_6c;
              local_68 = (local_5c - local_68) * fVar3 + local_68;
              local_64 = local_64 + (local_58 - local_64) * fVar3;
            }
            else {
              local_60 = fVar8 + local_6c;
              local_5c = (local_5c - local_68) * fVar3 + local_68;
              local_58 = local_64 + (local_58 - local_64) * fVar3;
            }
            ScreenTransform(&local_6c,&local_54);
            ScreenTransform(&local_60,&local_48);
            goto LAB_001a19e3;
          }
        }
        fVar3 = ppVar6->vel[0];
        pVar13 = ppVar6->type;
        ppVar6->org[0] = fVar2 * fVar3 + ppVar6->org[0];
        fVar5 = ppVar6->vel[1];
        ppVar6->org[1] = fVar2 * fVar5 + ppVar6->org[1];
        ppVar6->org[2] = fVar2 * ppVar6->vel[2] + ppVar6->org[2];
        if (pVar13 == pt_grav) {
          ppVar6->vel[2] = ppVar6->vel[2] - fVar9;
          ppVar6->vel[0] = fVar3 * fVar7;
          ppVar6->vel[1] = fVar5 * fVar7;
          fVar3 = ppVar6->die - (float)cl.time;
          sVar12 = (short)(int)((fVar3 + fVar3) * 255.0);
          if (sVar12 < 0x100) {
            ppVar6->packedColor = sVar12;
          }
          else {
            ppVar6->packedColor = 0xff;
          }
        }
        else if (pVar13 == pt_slowgrav) {
          ppVar6->vel[2] = fVar9 * 0.05;
        }
      }
      (*tri.CullFace)(TRI_FRONT);
      (*tri.RenderMode)(0);
    }
  }
  R_BeamDrawList();
  (*qglDisable)(0xbe2);
  (*qglDisable)(0xbc0);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// R_DrawRing  @ 0019eec0
void R_DrawRing(vec_t *source,vec_t *delta,float width,float amplitude,float freq,float speed,
               int segments)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  mnode_t *pmVar8;
  qboolean qVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  float fVar13;
  float fVar14;
  double dVar15;
  float local_ec;
  uint local_c4;
  float local_b8;
  float local_b4;
  int local_b0;
  double local_94;
  double local_8c;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  vec_t local_70 [3];
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  vec_t local_40 [3];
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int noiseIndex@[???]
                       Unresolved local var: int noiseStep@[???]
                       Unresolved local var: float div@[???]
                       Unresolved local var: float length@[???]
                       Unresolved local var: float fraction@[???]
                       Unresolved local var: float factor@[???]
                       Unresolved local var: float vLast@[???]
                       Unresolved local var: float vStep@[???]
                       Unresolved local var: vec3_t last1@[???]
                       Unresolved local var: vec3_t last2@[???]
                       Unresolved local var: vec3_t point@[???]
                       Unresolved local var: vec3_t screen@[???]
                       Unresolved local var: vec3_t screenLast@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: vec3_t normal@[???]
                       Unresolved local var: vec3_t center@[???]
                       Unresolved local var: vec3_t xaxis@[???]
                       Unresolved local var: vec3_t yaxis@[???]
                       Unresolved local var: vec3_t zaxis@[???]
                       Unresolved local var: float radius@[???]
                       Unresolved local var: float x@[???]
                       Unresolved local var: float y@[???]
                       Unresolved local var: float scale@[???] */
  if (1 < segments) {
    fVar13 = Length(delta);
    local_80 = fVar13 * 0.01 * 3.1415927;
    fVar13 = 0.5;
    if (0.5 <= local_80) {
      fVar13 = local_80;
    }
    dVar15 = fmod((double)(freq * speed),1.0);
    fVar2 = fVar13 * amplitude * 0.125;
    VectorScale(delta,0.5,delta);
    local_34 = *delta;
    local_30 = delta[1];
    local_2c = delta[2];
    fVar3 = local_34 + *source;
    fVar4 = local_30 + source[1];
    fVar5 = local_2c + source[2];
    fVar14 = Length(&local_34);
    local_4c = fVar3 + fVar14;
    local_48 = fVar4 + fVar14;
    local_44 = fVar2 + fVar5;
    local_58 = fVar3 - fVar14;
    local_54 = fVar4 - fVar14;
    local_50 = fVar5 - fVar2;
    if (cl.worldmodel != (model_s *)0x0) {
      local_7c = fVar14;
      local_78 = fVar14;
      local_74 = fVar2;
      pmVar8 = PVSNode((cl.worldmodel)->nodes,&local_58,&local_4c);
      if ((pmVar8 != (mnode_t *)0x0) && (qVar9 = R_CullBox(&local_58,&local_4c), qVar9 == false)) {
        local_20 = 0.0;
        local_28 = local_30;
        local_24 = -local_34;
        iVar11 = 0x400;
        if ((int)((double)segments * 3.141592653589793) < 0x401) {
          iVar11 = (int)((double)segments * 3.141592653589793);
        }
        VectorNormalize(&local_28);
        VectorScale(&local_28,fVar14,&local_28);
        iVar10 = iVar11 + 7;
        if (-1 < iVar11) {
          iVar10 = iVar11;
        }
        if (-1 < iVar11) {
          fVar14 = 1.0 / (float)(iVar11 + -1);
          iVar1 = 0;
          iVar12 = 0;
          local_b0 = iVar10 >> 3;
          do {
            local_ec = (float)dVar15;
            fVar6 = (float)iVar1 * fVar14;
            sincos((double)((fVar6 + fVar6) * 3.1415927),&local_8c,&local_94);
            fVar7 = (float)local_8c;
            local_80 = (float)local_94;
            local_c4 = iVar12 >> 0x10 & 0x7f;
            local_64 = local_28 * local_80 + local_34 * fVar7 + fVar3;
            local_60 = local_24 * local_80 + local_30 * fVar7 + fVar4;
            local_5c = local_80 * local_20 + fVar7 * local_2c + fVar5;
            VectorMA(&local_64,fVar2 * gNoise[iVar12 >> 0x10 & 0x7f],vup,&local_64);
            dVar15 = cos((double)fVar6 * 3.141592653589793 * 3.0 * 8.0 + (double)freq);
            VectorMA(&local_64,fVar2 * gNoise[local_c4] * (float)dVar15,vright,&local_64);
            ScreenTransform(&local_64,&local_58);
            if (iVar1 != 0) {
              local_4c = local_58 - local_b8;
              local_44 = 0.0;
              local_48 = local_54 - local_b4;
              VectorNormalize(&local_4c);
              VectorScale(vup,local_4c,local_40);
              VectorMA(local_40,-local_48,vright,local_40);
              VectorMA(&local_64,width,local_40,&local_7c);
              VectorMA(&local_64,-width,local_40,local_70);
              local_ec = fVar13 * fVar14 * 0.125 + local_ec;
              (*tri.TexCoord2f)(1.0,local_ec);
              (*tri.Vertex3fv)(local_70);
              (*tri.TexCoord2f)(0.0,local_ec);
              (*tri.Vertex3fv)(&local_7c);
            }
            local_b8 = local_58;
            local_b4 = local_54;
            dVar15 = fmod((double)local_ec,1.0);
            local_b0 = local_b0 + -1;
            iVar12 = iVar12 + (int)(fVar14 * 128.0 * 65536.0) * 8;
            if ((local_b0 == 0) && (amplitude != 0.0)) {
              Noise(gNoise,0x80);
              local_b0 = iVar10 >> 3;
            }
            iVar1 = iVar1 + 1;
          } while (iVar1 <= iVar11);
        }
      }
    }
  }
  return;
}


// R_DrawSegs  @ 0019dbd0
void R_DrawSegs(vec_t *source,vec_t *delta,float width,float scale,float freq,float speed,
               int segments,int flags)

{
  float scale_00;
  float fVar1;
  float scale_01;
  uint uVar2;
  int iVar3;
  float fVar4;
  double dVar5;
  float local_e4;
  float local_d8;
  int local_cc;
  float local_c8;
  int local_c4;
  int local_b8;
  float local_98;
  double local_94;
  double local_8c;
  float local_80;
  float local_70 [3];
  float local_64 [3];
  vec_t local_58 [3];
  float local_4c;
  float local_48;
  undefined4 local_44;
  float local_40;
  float local_3c;
  undefined4 local_38;
  vec_t local_34;
  float local_30;
  undefined4 local_2c;
  vec_t local_28 [6];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int noiseIndex@[???]
                       Unresolved local var: int noiseStep@[???]
                       Unresolved local var: float div@[???]
                       Unresolved local var: float length@[???]
                       Unresolved local var: float fraction@[???]
                       Unresolved local var: float factor@[???]
                       Unresolved local var: float vLast@[???]
                       Unresolved local var: float vStep@[???]
                       Unresolved local var: float brightness@[???]
                       Unresolved local var: vec3_t last1@[???]
                       Unresolved local var: vec3_t last2@[???]
                       Unresolved local var: vec3_t point@[???]
                       Unresolved local var: vec3_t screen@[???]
                       Unresolved local var: vec3_t screenLast@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: vec3_t normal@[???] */
  if (1 < segments) {
    local_b8 = 0x80;
    if (segments < 0x81) {
      local_b8 = segments;
    }
    fVar4 = Length(delta);
    local_98 = 0.5;
    if (0.5 <= fVar4 * 0.01) {
      local_98 = fVar4 * 0.01;
    }
    scale_00 = 1.0 / (float)(local_b8 + -1);
    fVar4 = scale_00 * local_98;
    local_80 = scale_00;
    dVar5 = fmod((double)(freq * speed),1.0);
    uVar2 = flags & 0x10;
    if (uVar2 == 0) {
      local_c8 = local_98 * scale;
    }
    else {
      if (local_b8 < 0x10) {
        local_b8 = 0x10;
        local_98 = 1.6;
      }
      else {
        local_98 = (float)local_b8 * 0.1;
      }
      local_c8 = scale * 100.0;
    }
    ScreenTransform(source,&local_40);
    VectorMA(source,scale_00,delta,local_58);
    ScreenTransform(local_58,&local_4c);
    local_2c = 0;
    local_34 = local_4c - local_40;
    local_30 = local_48 - local_3c;
    VectorNormalize(&local_34);
    VectorScale(vup,local_34,local_28);
    VectorMA(local_28,-local_30,vright,local_28);
    VectorMA(source,width,local_28,local_70);
    VectorMA(source,-width,local_28,local_64);
    iVar3 = (int)(scale_00 * 128.0 * 65536.0);
    local_e4 = 1.0;
    local_c4 = 0;
    if (uVar2 == 0) {
      local_c4 = iVar3;
    }
    if ((flags & 0x40U) != 0) {
      local_e4 = 0.0;
    }
    local_cc = 1;
    do {
      local_d8 = (float)dVar5;
      scale_01 = (float)local_cc * scale_00;
      (*tri.Brightness)(local_e4);
      (*tri.TexCoord2f)(0.0,local_d8);
      (*tri.Vertex3fv)(local_70);
      (*tri.Brightness)(local_e4);
      (*tri.TexCoord2f)(1.0,local_d8);
      (*tri.Vertex3fv)(local_64);
      fVar1 = scale_01;
      if (((flags & 0x40U) == 0) && (fVar1 = local_e4, (flags & 0x80U) != 0)) {
        fVar1 = 1.0 - scale_01;
      }
      local_e4 = fVar1;
      VectorMA(source,scale_01,delta,local_58);
      if (local_c8 != 0.0) {
        fVar1 = local_c8 * gNoise[local_c4 >> 0x10 & 0x7f];
        if (uVar2 == 0) {
          VectorMA(local_58,fVar1,vup,local_58);
          dVar5 = cos((double)scale_01 * 3.141592653589793 * 3.0 + (double)freq);
          VectorMA(local_58,local_c8 * gNoise[local_c4 >> 0x10 & 0x7f] * (float)dVar5,vright,
                   local_58);
        }
        else {
          sincos((double)scale_01 * 3.141592653589793 * (double)local_98 + (double)freq,&local_8c,
                 &local_94);
          dVar5 = local_94;
          VectorMA(local_58,fVar1 * (float)local_8c,vup,local_58);
          VectorMA(local_58,(float)dVar5 * fVar1,vright,local_58);
        }
      }
      ScreenTransform(local_58,&local_4c);
      local_2c = 0;
      local_34 = local_4c - local_40;
      local_30 = local_48 - local_3c;
      VectorNormalize(&local_34);
      VectorScale(vup,local_34,local_28);
      VectorMA(local_28,-local_30,vright,local_28);
      VectorMA(local_58,width,local_28,local_70);
      VectorMA(local_58,-width,local_28,local_64);
      local_d8 = local_d8 + fVar4;
      (*tri.Brightness)(local_e4);
      (*tri.TexCoord2f)(1.0,local_d8);
      (*tri.Vertex3fv)(local_64);
      (*tri.Brightness)(local_e4);
      (*tri.TexCoord2f)(0.0,local_d8);
      (*tri.Vertex3fv)(local_70);
      local_40 = local_4c;
      local_3c = local_48;
      local_38 = local_44;
      dVar5 = fmod((double)local_d8,1.0);
      local_cc = local_cc + 1;
      local_c4 = local_c4 + iVar3;
    } while (local_b8 != local_cc);
  }
  return;
}


// R_DrawSequentialPoly  @ 00195f10
void R_DrawSequentialPoly(msurface_t *s,int face,qboolean cleanUpShaderState)

{
  short sVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  glpoly_t *pgVar9;
  mtexinfo_t *pmVar10;
  cl_entity_t *pcVar11;
  qboolean qVar12;
  texture_t *ptVar13;
  msurface_t *psurf;
  float (*pafVar14) [7];
  uint uVar15;
  uint uVar16;
  decal_s *pdecal;
  GLuint GVar17;
  int iVar18;
  msurface_t *pmVar19;
  int iVar20;
  double dVar21;
  msurface_t *pmVar22;
  float local_48;
  uint local_44;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: glpoly_t * p@[???]
                       Unresolved local var: float * v@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: texture_t * t@[???]
                       Unresolved local var: glRect_t * theRect@[???]
                       Unresolved local var: int renderDetailTexture@[???]
                       Unresolved local var: int textureMask@[???] */
  qVar12 = R_UseLegacyRender();
  if ((((((qVar12 == 0) && (qglCreateShader != (_func_GLuint_GLenum *)0x0)) &&
        (qglDeleteShader != (_func_void_GLuint *)0x0)) &&
       (((qglShaderSource != (_func_void_GLuint_GLsizei_GLchar_ptr_ptr_GLint_ptr *)0x0 &&
         (qglGetProgramiv != (_func_void_GLuint_GLenum_GLint_ptr *)0x0)) &&
        ((qglGetProgramInfoLog != (_func_void_GLuint_GLsizei_GLsizei_ptr_GLchar_ptr *)0x0 &&
         ((qglAttachShader != (_func_void_GLuint_GLuint *)0x0 &&
          (qglLinkProgram != (_func_void_GLuint *)0x0)))))))) &&
      (qglCreateProgram != (_func_GLuint *)0x0)) &&
     ((qglDeleteProgram != (_func_void_GLuint *)0x0 && (qglUseProgram != (_func_void_GLuint *)0x0)))
     ) {
    R_LoadShaders();
  }
  if ((currententity->curstate).rendermode == 1) {
    if ((g_bHasShaderFunctions != false) && (g_uCurrentProgram != 0)) {
      (*qglUseProgram)(0);
      g_uCurrentProgram = 0;
    }
    if (mtexenabled != false) {
      (*qglDisable)(0xde1);
      GL_SelectTexture(TEXTURE0_SGIS);
      mtexenabled = false;
    }
    (*qglBlendFunc)(0x302,0x303);
    (*qglEnable)(0xbe2);
    ptVar13 = R_TextureAnimation(s);
    GL_Bind(ptVar13->gl_texturenum);
    (*qglDisable)(0xde1);
    DrawGLSolidPoly(s->polys);
    (*qglEnable)(0xde1);
    if (gl_mtexable == 0) {
      return;
    }
    GL_SelectTexture(TEXTURE1_SGIS);
    (*qglEnable)(0xde1);
    mtexenabled = true;
    return;
  }
  uVar15 = s->flags;
  if ((uVar15 & 0x94) != 0) {
    if ((uVar15 & 0x10) == 0) {
      return;
    }
    if ((g_bHasShaderFunctions != false) && (g_uCurrentProgram != 0)) {
      (*qglUseProgram)(0);
      g_uCurrentProgram = 0;
    }
    if (mtexenabled != false) {
      (*qglDisable)(0xde1);
      GL_SelectTexture(TEXTURE0_SGIS);
      mtexenabled = false;
    }
    GL_Bind(s->texinfo->texture->gl_texturenum);
    EmitWaterPolys(s,face);
    return;
  }
                    /* Unresolved local var: int maps@[???] */
  if ((filterMode == false) && (c_brush_polys = c_brush_polys + 1, (uVar15 & 0x14) == 0)) {
    s->polys->chain = lightmap_polys[s->lightmaptexturenum];
    lightmap_polys[s->lightmaptexturenum] = s->polys;
                    /* Unresolved local var: int maps@[???] */
    if (((((s->styles[0] != 0xff) &&
          ((d_lightstylevalue[s->styles[0]] != s->cached_light[0] ||
           ((s->styles[1] != 0xff &&
            ((s->cached_light[1] != d_lightstylevalue[s->styles[1]] ||
             ((s->styles[2] != 0xff &&
              ((s->cached_light[2] != d_lightstylevalue[s->styles[2]] ||
               ((s->styles[3] != 0xff && (d_lightstylevalue[s->styles[3]] != s->cached_light[3])))))
              ))))))))) || (s->dlightframe == r_framecount)) || (s->cached_dlight != 0)) &&
       (r_dynamic.value != 0.0)) {
      R_ReUploadLightmap(s);
    }
  }
  if ((gl_mtexable != 0) && (((currententity->curstate).rendermode & 0xfffffffbU) == 0)) {
                    /* Unresolved local var: float sOffset@[???] */
    pgVar9 = s->polys;
    ptVar13 = R_TextureAnimation(s);
    GL_SelectTexture(TEXTURE0_SGIS);
    GL_Bind(ptVar13->gl_texturenum);
    (*qglTexEnvf)(0x2300,0x2200,8448.0);
    local_44 = 3;
    if ((currententity->curstate).rendermode == 1) {
      (*qglDisable)(0xde1);
      local_44 = 2;
    }
    if (gl_mtexable != 0) {
      GL_SelectTexture(TEXTURE1_SGIS);
      (*qglEnable)(0xde1);
      mtexenabled = true;
    }
    if (filterMode == false) {
      GL_Bind(lightmap_textures[s->lightmaptexturenum]);
    }
    else {
      GL_Bind(gl_FilterTexture);
    }
    iVar18 = s->lightmaptexturenum;
    if (lightmap_modified[iVar18] != false) {
      lightmap_modified[iVar18] = false;
      (*qglTexSubImage2D)(0xde1,0,0,lightmap_rectchange[iVar18].t,0x80,lightmap_rectchange[iVar18].h
                          ,gl_lightmap_format,0x1401,
                          lightmaps +
                          (iVar18 * 0x80 + lightmap_rectchange[iVar18].t) * 0x80 * lightmap_bytes);
      lightmap_rectchange[iVar18].t = 0x80;
      lightmap_rectchange[iVar18].h = 0;
      lightmap_rectchange[iVar18].w = 0;
      lightmap_rectchange[iVar18].l = 0x80;
    }
    (*qglTexEnvf)(0x2300,0x2200,8448.0);
    iVar18 = DT_SetRenderState(ptVar13->gl_texturenum);
    uVar15 = local_44 | 4;
    if (iVar18 == 0) {
      uVar15 = local_44;
    }
    local_48 = 0.0;
    if ((s->flags & 0x20) != 0) {
                    /* Unresolved local var: float speed@[???]
                       Unresolved local var: float sOffset@[???] */
      fVar2 = (float)((uint)(currententity->curstate).rendercolor.g * 0x100 +
                     (uint)(currententity->curstate).rendercolor.b) * 0.0625;
      fVar3 = -fVar2;
      if ((currententity->curstate).rendercolor.r != '\0') {
        fVar3 = fVar2;
      }
      fVar2 = fVar3 * (float)cl.time * (1.0 / (float)s->texinfo->texture->width);
      if (fVar2 < 0.0) {
        dVar21 = fmod((double)fVar2,-1.0);
        local_48 = (float)dVar21;
      }
      else {
        dVar21 = fmod((double)fVar2,1.0);
        local_48 = (float)dVar21;
      }
    }
    if (g_bHasShaderFunctions != false) {
      GVar17 = 0;
      if ((gl_use_shaders.value != 0.0) &&
         (GVar17 = g_fsWorldProgram[uVar15], sv_allow_shaders.value == 0.0)) {
        GVar17 = 0;
      }
      if (g_uCurrentProgram != GVar17) {
        (*qglUseProgram)(GVar17);
        g_uCurrentProgram = GVar17;
      }
    }
    uVar16 = (s->displaylist).gl_displaylist;
    local_44 = uVar15;
    if (uVar16 == 0) {
LAB_001966e8:
      if (gl_display_lists.value != 0.0) {
        uVar16 = glGenLists(1);
        pcVar11 = currententity;
        (s->displaylist).gl_displaylist = uVar16;
        iVar20 = (pcVar11->curstate).rendermode;
        (s->displaylist).scrolloffset = local_48;
        (s->displaylist).renderDetailTexture = iVar18;
        (s->displaylist).rendermode = iVar20;
        glNewList(uVar16);
      }
LAB_00196702:
      pafVar14 = pgVar9->verts;
      (*qglBegin)(9);
      if (pgVar9->numverts < 1) {
        (*qglEnd)();
        if (gl_display_lists.value != 0.0) goto LAB_001969ec;
        goto LAB_001969f1;
      }
      iVar20 = 0;
      if (iVar18 != 0) {
        do {
          iVar20 = iVar20 + 1;
          (*qglMTexCoord2fSGIS)(TEXTURE0_SGIS,local_48 + (*pafVar14)[3],(*pafVar14)[4]);
          (*qglMTexCoord2fSGIS)(TEXTURE1_SGIS,(*pafVar14)[5],(*pafVar14)[6]);
          DT_SetTextureCoordinates(local_48 + (*pafVar14)[3],(*pafVar14)[4]);
          (*qglVertex3fv)(*pafVar14);
          pafVar14 = pafVar14 + 1;
        } while (iVar20 < pgVar9->numverts);
        (*qglEnd)();
        if (gl_display_lists.value != 0.0) goto LAB_001969ec;
        goto LAB_001969fd;
      }
      do {
        iVar20 = iVar20 + 1;
        (*qglMTexCoord2fSGIS)(TEXTURE0_SGIS,local_48 + (*pafVar14)[3],(*pafVar14)[4]);
        (*qglMTexCoord2fSGIS)(TEXTURE1_SGIS,(*pafVar14)[5],(*pafVar14)[6]);
        (*qglVertex3fv)(*pafVar14);
        pafVar14 = pafVar14 + 1;
      } while (iVar20 < pgVar9->numverts);
      (*qglEnd)();
      if (gl_display_lists.value != 0.0) {
LAB_001969ec:
        glEndList();
        goto LAB_001969f1;
      }
    }
    else {
      if ((((currententity->curstate).rendermode != (s->displaylist).rendermode) ||
          ((s->displaylist).scrolloffset != local_48)) ||
         (iVar18 != (s->displaylist).renderDetailTexture)) {
        glDeleteLists(uVar16);
        (s->displaylist).gl_displaylist = 0;
        goto LAB_001966e8;
      }
      if (gl_display_lists.value == 0.0) goto LAB_00196702;
      glCallList(uVar16);
LAB_001969f1:
      if (iVar18 != 0) {
LAB_001969fd:
        DT_ClearRenderState();
        local_44 = uVar15 & 0xfffffffb;
      }
    }
    if (g_bHasShaderFunctions != false) {
      GVar17 = 0;
      if ((gl_use_shaders.value != 0.0) &&
         (GVar17 = g_fsWorldProgram[local_44], sv_allow_shaders.value == 0.0)) {
        GVar17 = 0;
      }
      if (g_uCurrentProgram != GVar17) {
        (*qglUseProgram)(GVar17);
        g_uCurrentProgram = GVar17;
      }
    }
    if ((gl_texsort == false) && (s->pdecals != (decal_t *)0x0)) {
      gDecalSurfs[gDecalSurfCount] = s;
      gDecalSurfCount = gDecalSurfCount + 1;
      if (500 < gDecalSurfCount) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Too many decal surfaces!\n");
      }
                    /* Unresolved local var: decal_t * plist@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int outCount@[???]
                       Unresolved local var: texture_t * ptexture@[???]
                       Unresolved local var: msurface_t * psurf@[???]
                       Unresolved local var: float * v@[???] */
      if (((currententity->curstate).rendermode == 0) && (gDecalSurfCount != 0)) {
        (*qglEnable)(0xbe2);
        (*qglEnable)(0xbc0);
        pmVar19 = (msurface_t *)0x303;
        (*qglBlendFunc)(0x302,0x303);
        (*qglDepthMask)('\0');
        if (gl_polyoffset.value == 0.0) {
          if (0 < gDecalSurfCount) {
LAB_00196db3:
            iVar18 = 0;
            do {
              pmVar22 = gDecalSurfs[iVar18];
              for (pdecal = pmVar22->pdecals; pdecal != (decal_t *)0x0; pdecal = pdecal->pnext) {
LAB_00197013:
                psurf = (msurface_t *)Draw_DecalTexture((int)pdecal->texture);
                if ((pdecal->flags & 0x40) != 0) {
LAB_00196de0:
                    /* Unresolved local var: float * vlist@[???]
                       Unresolved local var: decalcache_t * pCache@[???]
                       Unresolved local var: int decalIndex@[???]
                       Unresolved local var: int outCount@[???] */
                  uVar16 = ((int)(pdecal + -0x49fd8) >> 2) * -0x49249249;
                    /* Unresolved local var: int cacheIndex@[???] */
                  uVar15 = uVar16 & 0xff;
                  pafVar14 = gDecalCache[uVar15].decalVert;
                  if (uVar16 - gDecalCache[uVar15].decalIndex != 0) {
                    gDecalCache[uVar15].decalIndex = uVar16;
                    pafVar14 = (float (*) [7])
                               R_DecalVertsClip(*pafVar14,pdecal,pmVar22,(texture_t *)psurf,local_20
                                               );
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: float s@[???]
                       Unresolved local var: float t@[???] */
                    pmVar10 = pmVar22->texinfo;
                    iVar20 = pmVar22->light_t;
                    fVar2 = (*pafVar14)[0];
                    fVar3 = pmVar10->vecs[1][0];
                    fVar4 = pmVar10->vecs[1][1];
                    fVar5 = pmVar10->vecs[1][2];
                    fVar6 = pmVar10->vecs[1][3];
                    sVar1 = pmVar22->texturemins[1];
                    (*pafVar14)[5] =
                         ((float)(pmVar22->light_s << 4) +
                          (((*pafVar14)[2] * pmVar10->vecs[0][2] +
                            (*pafVar14)[1] * pmVar10->vecs[0][1] +
                            (*pafVar14)[0] * pmVar10->vecs[0][0] + pmVar10->vecs[0][3]) -
                          (float)pmVar22->texturemins[0]) + 8.0) * 0.00048828125;
                    (*pafVar14)[6] =
                         ((float)(iVar20 << 4) +
                          (((*pafVar14)[2] * fVar5 + (*pafVar14)[1] * fVar4 + fVar2 * fVar3 + fVar6)
                          - (float)sVar1) + 8.0) * 0.00048828125;
                    pmVar10 = pmVar22->texinfo;
                    iVar20 = pmVar22->light_t;
                    fVar2 = pafVar14[1][0];
                    fVar3 = pmVar10->vecs[1][0];
                    fVar4 = pafVar14[1][1];
                    fVar5 = pmVar10->vecs[1][1];
                    fVar6 = pafVar14[1][2];
                    fVar7 = pmVar10->vecs[1][2];
                    fVar8 = pmVar10->vecs[1][3];
                    sVar1 = pmVar22->texturemins[1];
                    pafVar14[1][5] =
                         ((float)(pmVar22->light_s << 4) +
                          ((pafVar14[1][2] * pmVar10->vecs[0][2] +
                            pafVar14[1][1] * pmVar10->vecs[0][1] +
                            pafVar14[1][0] * pmVar10->vecs[0][0] + pmVar10->vecs[0][3]) -
                          (float)pmVar22->texturemins[0]) + 8.0) * 0.00048828125;
                    pafVar14[1][6] =
                         ((float)(iVar20 << 4) +
                          ((fVar6 * fVar7 + fVar4 * fVar5 + fVar2 * fVar3 + fVar8) - (float)sVar1) +
                         8.0) * 0.00048828125;
                    pmVar10 = pmVar22->texinfo;
                    fVar2 = pafVar14[2][0];
                    fVar3 = pmVar10->vecs[1][0];
                    iVar20 = pmVar22->light_t;
                    fVar4 = pafVar14[2][1];
                    fVar5 = pmVar10->vecs[1][1];
                    fVar6 = pafVar14[2][2];
                    fVar7 = pmVar10->vecs[1][2];
                    fVar8 = pmVar10->vecs[1][3];
                    sVar1 = pmVar22->texturemins[1];
                    pafVar14[2][5] =
                         ((float)(pmVar22->light_s << 4) +
                          ((pafVar14[2][2] * pmVar10->vecs[0][2] +
                            pafVar14[2][1] * pmVar10->vecs[0][1] +
                            pafVar14[2][0] * pmVar10->vecs[0][0] + pmVar10->vecs[0][3]) -
                          (float)pmVar22->texturemins[0]) + 8.0) * 0.00048828125;
                    pafVar14[2][6] =
                         ((float)(iVar20 << 4) +
                          ((fVar6 * fVar7 + fVar4 * fVar5 + fVar2 * fVar3 + fVar8) - (float)sVar1) +
                         8.0) * 0.00048828125;
                    pmVar10 = pmVar22->texinfo;
                    fVar2 = pafVar14[3][0];
                    fVar3 = pmVar10->vecs[1][0];
                    fVar4 = pafVar14[3][1];
                    fVar5 = pmVar10->vecs[1][1];
                    fVar6 = pafVar14[3][2];
                    fVar7 = pmVar10->vecs[1][2];
                    fVar8 = pmVar10->vecs[1][3];
                    sVar1 = pmVar22->texturemins[1];
                    iVar20 = pmVar22->light_t;
                    pafVar14[3][5] =
                         ((float)(pmVar22->light_s << 4) +
                          ((pafVar14[3][2] * pmVar10->vecs[0][2] +
                            pafVar14[3][1] * pmVar10->vecs[0][1] +
                            pafVar14[3][0] * pmVar10->vecs[0][0] + pmVar10->vecs[0][3]) -
                          (float)pmVar22->texturemins[0]) + 8.0) * 0.00048828125;
                    pafVar14[3][6] =
                         ((float)(iVar20 << 4) +
                          ((fVar6 * fVar7 + fVar4 * fVar5 + fVar2 * fVar3 + fVar8) - (float)sVar1) +
                         8.0) * 0.00048828125;
                  }
                  local_24 = 4;
LAB_00196ff9:
                  pmVar19 = psurf;
                  R_DecalMPoly(*pafVar14,(texture_t *)psurf,pmVar22,local_24);
LAB_0019700d:
                  pdecal = pdecal->pnext;
                  if (pdecal == (decal_s *)0x0) break;
                  goto LAB_00197013;
                }
                pafVar14 = (float (*) [7])
                           R_DecalVertsClip((float *)pdecal,(decal_t *)pmVar22,psurf,
                                            (texture_t *)&local_24,&pmVar19->visframe);
                if (local_24 == 0) {
                  if ((pdecal->flags & 0x40) != 0) goto LAB_00196de0;
                  goto LAB_0019700d;
                }
                pmVar19 = pmVar22;
                R_DecalVertsLight((float *)pafVar14,pmVar22,local_24);
                if ((pdecal->flags & 0x40) != 0) goto LAB_00196de0;
                if (local_24 != 0) goto LAB_00196ff9;
              }
              iVar18 = iVar18 + 1;
            } while (iVar18 < gDecalSurfCount);
            goto LAB_0019708a;
          }
        }
        else {
          (*qglEnable)(0x8037);
          if ((gl_ztrick.value == 0.0) || (gldepthmin < 0.5)) {
            pmVar19 = (msurface_t *)-gl_polyoffset.value;
            (*qglPolygonOffset)(-1.0,(GLfloat)pmVar19);
          }
          else {
            pmVar19 = (msurface_t *)gl_polyoffset.value;
            (*qglPolygonOffset)(1.0,gl_polyoffset.value);
          }
          if (0 < gDecalSurfCount) goto LAB_00196db3;
LAB_0019708a:
          if (gl_polyoffset.value != 0.0) {
            (*qglDisable)(0x8037);
          }
        }
        (*qglDisable)(0xbc0);
        (*qglDisable)(0xbe2);
        (*qglDepthMask)('\x01');
        gDecalSurfCount = 0;
      }
    }
    if (cleanUpShaderState != false) {
      if ((g_bHasShaderFunctions == false) || (g_uCurrentProgram == 0)) {
        if (gl_wireframe.value == 0.0) {
          return;
        }
        goto LAB_00196846;
      }
      (*qglUseProgram)(0);
      g_uCurrentProgram = 0;
    }
    if (gl_wireframe.value == 0.0) {
      return;
    }
    if ((g_bHasShaderFunctions != false) && (g_uCurrentProgram != 0)) {
      (*qglUseProgram)(0);
      g_uCurrentProgram = 0;
    }
LAB_00196846:
    (*qglDisable)(0xde1);
    (*qglColor3f)(1.0,1.0,1.0);
    if (gl_wireframe.value == 2.0) {
      (*qglDisable)(0xb71);
    }
    iVar18 = 0;
    (*qglBegin)(2);
    pafVar14 = pgVar9->verts;
    if (0 < pgVar9->numverts) {
      do {
        iVar18 = iVar18 + 1;
        (*qglVertex3fv)(*pafVar14);
        pafVar14 = pafVar14 + 1;
      } while (iVar18 < pgVar9->numverts);
    }
    (*qglEnd)();
    (*qglEnable)(0xde1);
    if (gl_wireframe.value != 2.0) {
      return;
    }
    (*qglEnable)(0xb71);
    return;
  }
  pgVar9 = s->polys;
  ptVar13 = R_TextureAnimation(s);
  if (mtexenabled != false) {
    (*qglDisable)(0xde1);
    GL_SelectTexture(TEXTURE0_SGIS);
    mtexenabled = false;
  }
  GL_Bind(ptVar13->gl_texturenum);
  if (g_bHasShaderFunctions != false) {
    GVar17 = 0;
    if ((gl_use_shaders.value != 0.0) &&
       (GVar17 = g_fsWorldProgram[1], sv_allow_shaders.value == 0.0)) {
      GVar17 = 0;
    }
    if (g_uCurrentProgram != GVar17) {
      (*qglUseProgram)(GVar17);
      g_uCurrentProgram = GVar17;
    }
  }
  if ((s->flags & 0x20) == 0) {
    pmVar22 = (msurface_t *)0x9;
    iVar18 = 0;
    (*qglBegin)(9);
    pmVar19 = (msurface_t *)pgVar9->verts;
    if (0 < pgVar9->numverts) {
      do {
        iVar18 = iVar18 + 1;
        (*qglTexCoord2f)((GLfloat)pmVar19->firstedge,(GLfloat)pmVar19->numedges);
        pmVar22 = pmVar19;
        (*qglVertex3fv)((GLfloat *)pmVar19);
        pmVar19 = (msurface_t *)&pmVar19->light_s;
      } while (iVar18 < pgVar9->numverts);
    }
    (*qglEnd)();
  }
  else {
    pmVar22 = s;
    DrawGLPolyScroll(s,currententity);
  }
  if ((gl_texsort == false) && (s->pdecals != (decal_t *)0x0)) {
    gDecalSurfs[gDecalSurfCount] = s;
    gDecalSurfCount = gDecalSurfCount + 1;
    if (500 < gDecalSurfCount) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Too many decal surfaces!\n");
    }
    R_DrawDecals((qboolean)pmVar22);
  }
  if (cleanUpShaderState == false) {
LAB_00196062:
    if (gl_wireframe.value == 0.0) goto LAB_0019607c;
    if ((g_bHasShaderFunctions != false) && (g_uCurrentProgram != 0)) {
      (*qglUseProgram)(0);
      g_uCurrentProgram = 0;
    }
  }
  else {
    if ((g_bHasShaderFunctions != false) && (g_uCurrentProgram != 0)) {
      (*qglUseProgram)(0);
      g_uCurrentProgram = 0;
      goto LAB_00196062;
    }
    if (gl_wireframe.value == 0.0) goto LAB_0019607c;
  }
  (*qglDisable)(0xde1);
  (*qglColor3f)(1.0,1.0,1.0);
  if (gl_wireframe.value == 2.0) {
    (*qglDisable)(0xb71);
  }
  (*qglBegin)(2);
  if (0 < pgVar9->numverts) {
    iVar18 = 0;
    pafVar14 = pgVar9->verts;
    do {
      iVar18 = iVar18 + 1;
      (*qglVertex3fv)(*pafVar14);
      pafVar14 = pafVar14 + 1;
    } while (iVar18 < pgVar9->numverts);
  }
  (*qglEnd)();
  (*qglEnable)(0xde1);
  if (gl_wireframe.value == 2.0) {
    (*qglEnable)(0xb71);
  }
LAB_0019607c:
  if ((currententity->curstate).rendermode == 0) {
    if (g_bHasShaderFunctions != false) {
      GVar17 = 0;
      if ((gl_use_shaders.value != 0.0) &&
         (GVar17 = g_fsWorldProgram[1], sv_allow_shaders.value == 0.0)) {
        GVar17 = 0;
      }
      if (g_uCurrentProgram != GVar17) {
        (*qglUseProgram)(GVar17);
        g_uCurrentProgram = GVar17;
      }
    }
    if (filterMode == false) {
      GL_Bind(lightmap_textures[s->lightmaptexturenum]);
    }
    else {
      GL_Bind(gl_FilterTexture);
    }
    (*qglEnable)(0xbe2);
    (*qglBegin)(9);
    if (0 < pgVar9->numverts) {
      iVar18 = 0;
      pafVar14 = pgVar9->verts;
      do {
        iVar18 = iVar18 + 1;
        (*qglTexCoord2f)((*pafVar14)[5],(*pafVar14)[6]);
        (*qglVertex3fv)(*pafVar14);
        pafVar14 = pafVar14 + 1;
      } while (iVar18 < pgVar9->numverts);
    }
    (*qglEnd)();
    (*qglDisable)(0xbe2);
    if (((cleanUpShaderState != false) && (g_bHasShaderFunctions != false)) &&
       (g_uCurrentProgram != 0)) {
      (*qglUseProgram)(0);
      g_uCurrentProgram = 0;
    }
  }
  return;
}


// R_DrawSkyBox  @ 0018dec0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_DrawSkyBox(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  GLboolean GVar5;
  uint uVar6;
  int iVar7;
  int axis;
  GLfloat local_18;
  GLfloat local_14;
  GLfloat local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iFogTurnedOff@[???]
                       Unresolved local var: vec3_t normal@[???]
                       Unresolved local var: float r@[???]
                       Unresolved local var: float g@[???]
                       Unresolved local var: float b@[???] */
  if (filterMode == false) {
    local_18 = 1.0;
    local_10 = 1.0;
    local_14 = 1.0;
    GL_DisableMultitexture();
  }
  else {
    local_14 = filterColorRed * filterBrightness;
    local_10 = filterColorGreen * filterBrightness;
    local_18 = filterBrightness * filterColorBlue;
    GL_DisableMultitexture();
  }
  if ((g_bFogSkybox == 0) && (GVar5 = (*qglIsEnabled)(0xb60), GVar5 == '\x01')) {
    bVar4 = true;
    R_SetFogEnabled(false);
  }
  else {
    bVar4 = false;
  }
  iVar7 = 0;
  axis = 0;
  do {
    if ((*(float *)((int)skymins[0] + iVar7) < *(float *)((int)skymaxs[0] + iVar7)) &&
       (*(float *)((int)skymins[1] + iVar7) < *(float *)((int)skymaxs[1] + iVar7))) {
      uVar6 = *(int *)((int)gFakePlaneType + iVar7) + 3;
      if (uVar6 < 7) {
        fVar1 = *(float *)(CSWTCH_165 + uVar6 * 4);
        fVar2 = *(float *)(CSWTCH_167 + uVar6 * 4);
        fVar3 = *(float *)(CSWTCH_166 + uVar6 * 4);
      }
      else {
        fVar1 = 0.0;
        fVar2 = fVar1;
        fVar3 = fVar1;
      }
      if (-0.29289323 <= fVar2 * vpn[2] + fVar3 * vpn[1] + fVar1 * vpn[0]) {
        GL_Bind(gSkyTexNumber[*(int *)((int)skytexorder + iVar7)]);
        (*qglColor3f)(local_14,local_10,local_18);
        (*qglBegin)(7);
        MakeSkyVec(*(float *)((int)skymins[0] + iVar7),*(float *)((int)skymins[1] + iVar7),axis);
        MakeSkyVec(*(float *)((int)skymins[0] + iVar7),*(float *)((int)skymaxs[1] + iVar7),axis);
        MakeSkyVec(*(float *)((int)skymaxs[0] + iVar7),*(float *)((int)skymaxs[1] + iVar7),axis);
        MakeSkyVec(*(float *)((int)skymaxs[0] + iVar7),*(float *)((int)skymins[1] + iVar7),axis);
        (*qglEnd)();
      }
    }
    axis = axis + 1;
    iVar7 = iVar7 + 4;
  } while (axis != 6);
  if (bVar4) {
    R_SetFogEnabled(true);
  }
  return;
}


// R_DrawSkyChain  @ 0018e110
void R_DrawSkyChain(msurface_t *s)

{
  float fVar1;
  float fVar2;
  float fVar3;
  glpoly_t *pgVar4;
  bool bVar5;
  byte bVar6;
  byte bVar7;
  int iVar8;
  float *pfVar9;
  float *pfVar10;
  float (*pafVar11) [7];
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int local_b24;
  float local_b1c [63];
  int aiStack_a20 [65];
  float local_91c [192];
  vec_t local_61c;
  float local_618 [191];
  vec_t local_31c;
  float local_318 [194];
  
                    /* Unresolved local var: msurface_t * fa@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec_t[64][3] verts@[???]
                       Unresolved local var: glpoly_t * p@[???] */
  iVar8 = CL_IsDevOverviewMode();
  if (iVar8 == 0) {
    c_sky = 0;
    for (; s != (msurface_t *)0x0; s = s->texturechain) {
      for (pgVar4 = s->polys; pgVar4 != (glpoly_t *)0x0; pgVar4 = pgVar4->next) {
        local_b24 = pgVar4->numverts;
        if (local_b24 < 1) {
LAB_0018e507:
          ClipSkyPolygon(local_b24,local_91c,1);
        }
        else {
          iVar8 = 0;
          pfVar10 = local_91c;
          pafVar11 = pgVar4->verts;
          do {
            iVar8 = iVar8 + 1;
            *pfVar10 = (*pafVar11)[0] - r_origin[0];
            pfVar10[1] = (*pafVar11)[1] - r_origin[1];
            pfVar10[2] = (*pafVar11)[2] - r_origin[2];
            local_b24 = pgVar4->numverts;
            pfVar10 = pfVar10 + 3;
            pafVar11 = pafVar11 + 1;
          } while (iVar8 < local_b24);
                    /* Unresolved local var: float * norm@[???]
                       Unresolved local var: float * v@[???]
                       Unresolved local var: qboolean front@[???]
                       Unresolved local var: qboolean back@[???]
                       Unresolved local var: float d@[???]
                       Unresolved local var: float e@[???]
                       Unresolved local var: float[64] dists@[???]
                       Unresolved local var: int[64] sides@[???]
                       Unresolved local var: vec_t[2][64][3] newv@[???]
                       Unresolved local var: int[2] newc@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
          if (0x3e < local_b24) {
                    /* WARNING: Subroutine does not return */
            Sys_Error("ClipSkyPolygon: MAX_CLIP_VERTS");
          }
          if (local_b24 < 1) goto LAB_0018e507;
          iVar8 = 0;
          bVar6 = 0;
          pfVar9 = local_91c;
          bVar7 = 0;
          pfVar10 = pfVar9 + local_b24 * 3;
          do {
            while (fVar1 = pfVar9[2] * skyclip[0][2] +
                           pfVar9[1] * skyclip[0][1] + *pfVar9 * skyclip[0][0], 0.1 < fVar1) {
              bVar7 = 1;
              *(undefined4 *)((int)aiStack_a20 + iVar8 + 4) = 0;
LAB_0018e220:
              pfVar9 = pfVar9 + 3;
              *(float *)((int)local_b1c + iVar8) = fVar1;
              iVar8 = iVar8 + 4;
              if (pfVar9 == pfVar10) goto LAB_0018e288;
            }
            if (0.1 <= fVar1) {
              *(undefined4 *)((int)aiStack_a20 + iVar8 + 4) = 2;
              goto LAB_0018e220;
            }
            pfVar9 = pfVar9 + 3;
            *(undefined4 *)((int)aiStack_a20 + iVar8 + 4) = 1;
            *(float *)((int)local_b1c + iVar8) = fVar1;
            iVar8 = iVar8 + 4;
            bVar6 = 1;
          } while (pfVar9 != pfVar10);
LAB_0018e288:
          iVar8 = aiStack_a20[1];
          if ((bool)(bVar7 ^ 1 | bVar6 ^ 1)) goto LAB_0018e507;
          local_91c[local_b24 * 3] = local_91c[0];
          local_b1c[local_b24] = local_b1c[0];
          fVar1 = local_91c[1];
          aiStack_a20[local_b24 + 1] = iVar8;
          local_91c[local_b24 * 3 + 1] = fVar1;
          local_91c[local_b24 * 3 + 2] = local_91c[2];
          pfVar10 = local_91c;
          iVar8 = 1;
          iVar13 = 0;
          iVar15 = 0;
          do {
            while( true ) {
              iVar14 = aiStack_a20[iVar8];
              iVar16 = iVar15;
              if (iVar14 == 1) {
                fVar1 = pfVar10[1];
                fVar2 = pfVar10[2];
                (&local_31c)[iVar13 * 3] = *pfVar10;
                local_318[iVar13 * 3] = fVar1;
                local_318[iVar13 * 3 + 1] = fVar2;
                iVar12 = iVar13 + 1;
                goto LAB_0018e320;
              }
              if (iVar14 == 2) break;
              iVar12 = iVar13;
              if (iVar14 == 0) {
                fVar1 = pfVar10[1];
                fVar2 = pfVar10[2];
                iVar16 = iVar15 + 1;
                (&local_61c)[iVar15 * 3] = *pfVar10;
                local_618[iVar15 * 3] = fVar1;
                local_618[iVar15 * 3 + 1] = fVar2;
LAB_0018e320:
                iVar13 = iVar12;
                iVar15 = iVar16;
                if ((iVar14 != aiStack_a20[iVar8 + 1]) && (aiStack_a20[iVar8 + 1] != 2)) {
                  iVar15 = iVar16 + 1;
                  iVar13 = iVar12 + 1;
                  fVar1 = local_b1c[iVar8 + -1] / (local_b1c[iVar8 + -1] - local_b1c[iVar8]);
                  fVar2 = (pfVar10[3] - *pfVar10) * fVar1 + *pfVar10;
                  (&local_61c)[iVar16 * 3] = fVar2;
                  (&local_31c)[iVar12 * 3] = fVar2;
                  fVar2 = (pfVar10[4] - pfVar10[1]) * fVar1 + pfVar10[1];
                  local_618[iVar16 * 3] = fVar2;
                  local_318[iVar12 * 3] = fVar2;
                  fVar1 = (pfVar10[5] - pfVar10[2]) * fVar1 + pfVar10[2];
                  local_618[iVar16 * 3 + 1] = fVar1;
                  local_318[iVar12 * 3 + 1] = fVar1;
                }
              }
              else if (iVar14 != 2) goto LAB_0018e320;
              bVar5 = local_b24 <= iVar8;
              pfVar10 = pfVar10 + 3;
              iVar8 = iVar8 + 1;
              iVar14 = iVar13;
              iVar16 = iVar15;
              if (bVar5) goto LAB_0018e494;
            }
            fVar1 = *pfVar10;
            iVar16 = iVar15 + 1;
            (&local_61c)[iVar15 * 3] = fVar1;
            fVar2 = pfVar10[1];
            local_618[iVar15 * 3] = fVar2;
            fVar3 = pfVar10[2];
            local_618[iVar15 * 3 + 1] = fVar3;
            iVar14 = iVar13 + 1;
            (&local_31c)[iVar13 * 3] = fVar1;
            local_318[iVar13 * 3] = fVar2;
            local_318[iVar13 * 3 + 1] = fVar3;
            bVar5 = iVar8 < local_b24;
            pfVar10 = pfVar10 + 3;
            iVar8 = iVar8 + 1;
            iVar13 = iVar14;
            iVar15 = iVar16;
          } while (bVar5);
LAB_0018e494:
          ClipSkyPolygon(iVar16,&local_61c,1);
          ClipSkyPolygon(iVar14,&local_31c,1);
        }
      }
    }
    R_DrawSkyBox();
  }
  return;
}


// R_DrawSpriteModel  @ 0017c950
void R_DrawSpriteModel(cl_entity_t *e)

{
  float fVar1;
  msprite_t *pSprite;
  float fVar2;
  GLubyte GVar3;
  mspriteframe_t *pmVar4;
  int iVar5;
  vec_t local_5c [3];
  vec_t local_50 [3];
  vec_t local_44 [3];
  vec_t local_38 [3];
  colorVec local_2c;
  
                    /* Unresolved local var: vec3_t point@[???]
                       Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: mspriteframe_t * frame@[???]
                       Unresolved local var: float scale@[???]
                       Unresolved local var: msprite_t * psprite@[???]
                       Unresolved local var: colorVec color@[???] */
  pSprite = (e->model->cache).data;
  pmVar4 = R_GetSpriteFrame(pSprite,(int)(e->curstate).frame);
  if (pmVar4 == (mspriteframe_t *)0x0) {
    Sys_Warning("R_DrawSpriteModel:  couldn\'t get sprite frame for %s\n",e->model);
    return;
  }
  fVar1 = (e->curstate).scale;
  fVar2 = 1.0;
  if (0.0 < fVar1) {
    fVar2 = fVar1;
  }
  if ((e->curstate).rendermode == 0) {
    r_blend = 1.0;
    iVar5 = 0xff;
  }
  else {
    iVar5 = (int)(r_blend * 255.0);
  }
  R_SpriteColor(&local_2c,e,iVar5);
  iVar5 = (e->curstate).rendermode;
  if ((gl_spriteblend.value == 0.0) && (iVar5 == 0)) {
    (*qglTexEnvf)(0x2300,0x2200,8448.0);
    (*qglColor4ub)((GLubyte)local_2c.r,(GLubyte)local_2c.g,(GLubyte)local_2c.b,0xff);
    (*qglDisable)(0xbe2);
    goto LAB_0017ca9f;
  }
  if (iVar5 == 1) {
    (*qglBlendFunc)(0x302,0x303);
    (*qglTexEnvi)(0x2300,0x2200,0x1906);
LAB_0017ca55:
    (*qglColor4ub)((GLubyte)local_2c.r,(GLubyte)local_2c.g,(GLubyte)local_2c.b,
                   (GLubyte)(int)(r_blend * 255.0));
  }
  else {
    if (iVar5 == 5) {
      (*qglTexEnvf)(0x2300,0x2200,8448.0);
      (*qglBlendFunc)(1,1);
      GVar3 = 0xff;
    }
    else {
      if (iVar5 == 3) {
        (*qglTexEnvf)(0x2300,0x2200,8448.0);
        (*qglBlendFunc)(1,1);
        (*qglColor4ub)((GLubyte)local_2c.r,(GLubyte)local_2c.g,(GLubyte)local_2c.b,0xff);
        (*qglDisable)(0xb71);
        (*qglDepthMask)('\0');
        goto LAB_0017ca92;
      }
      if (iVar5 != 4) {
        (*qglTexEnvf)(0x2300,0x2200,8448.0);
        (*qglBlendFunc)(0x302,0x303);
        goto LAB_0017ca55;
      }
      (*qglTexEnvf)(0x2300,0x2200,8448.0);
      (*qglBlendFunc)(0x302,0x303);
      GVar3 = (GLubyte)(int)(r_blend * 255.0);
    }
    (*qglColor4ub)((GLubyte)local_2c.r,(GLubyte)local_2c.g,(GLubyte)local_2c.b,GVar3);
    (*qglDepthMask)('\0');
  }
LAB_0017ca92:
  (*qglEnable)(0xbe2);
LAB_0017ca9f:
  R_GetSpriteAxes(e,(int)pSprite->type,local_50,local_44,local_38);
  GL_DisableMultitexture();
  GL_Bind(pmVar4->gl_texturenum);
  (*qglEnable)(0xbc0);
  (*qglBegin)(7);
  (*qglTexCoord2f)(0.0,1.0);
  VectorMA(r_entorigin,fVar2 * pmVar4->down,local_38,local_5c);
  VectorMA(local_5c,fVar2 * pmVar4->left,local_44,local_5c);
  (*qglVertex3fv)(local_5c);
  (*qglTexCoord2f)(0.0,0.0);
  VectorMA(r_entorigin,fVar2 * pmVar4->up,local_38,local_5c);
  VectorMA(local_5c,fVar2 * pmVar4->left,local_44,local_5c);
  (*qglVertex3fv)(local_5c);
  (*qglTexCoord2f)(1.0,0.0);
  VectorMA(r_entorigin,fVar2 * pmVar4->up,local_38,local_5c);
  VectorMA(local_5c,fVar2 * pmVar4->right,local_44,local_5c);
  (*qglVertex3fv)(local_5c);
  (*qglTexCoord2f)(1.0,1.0);
  VectorMA(r_entorigin,fVar2 * pmVar4->down,local_38,local_5c);
  VectorMA(local_5c,fVar2 * pmVar4->right,local_44,local_5c);
  (*qglVertex3fv)(local_5c);
  (*qglEnd)();
  (*qglDisable)(0xbc0);
  (*qglDepthMask)('\x01');
  if (((e->curstate).rendermode != 0) || (gl_spriteblend.value != 0.0)) {
    (*qglTexEnvf)(0x2300,0x2200,7681.0);
    (*qglDisable)(0xbe2);
    (*qglEnable)(0xb71);
  }
  return;
}


// R_DrawTEntitiesOnList  @ 001c0c90
void R_DrawTEntitiesOnList(qboolean clientOnly)

{
  modtype_t mVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  cl_entity_t *pcVar5;
  int iVar6;
  float fVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
  if (r_drawentities.value != 0.0) {
    if ((clientOnly == false) && (0 < numTransObjs)) {
      iVar6 = 0;
      do {
        R_SetFogEnabled(false);
        currententity = (cl_entity_t *)transObjects[iVar6].pEnt;
        iVar2 = CL_FxBlend(currententity);
        r_blend = (float)iVar2;
        if (0.0 < r_blend) {
          r_blend = r_blend * 0.003921569;
          if ((currententity->curstate).rendermode == 3) {
            if (currententity->model->type != mod_sprite) {
              Con_DPrintf("Non-sprite set to glow!\n");
              mVar1 = currententity->model->type;
              goto joined_r0x001c0ef3;
            }
          }
          else {
            mVar1 = currententity->model->type;
joined_r0x001c0ef3:
            if (mVar1 != mod_sprite) {
              if (mVar1 == mod_brush) {
                if ((g_bUserFogOn != 0) &&
                   (((currententity->curstate).rendermode - 3U & 0xfffffffd) != 0)) {
                  R_SetFogEnabled(true);
                }
                R_DrawBrushModel(currententity);
              }
              else if (mVar1 == mod_alias) {
                R_DrawAliasModel(currententity);
              }
              else if ((mVar1 == mod_studio) && ((currententity->curstate).renderamt != 0)) {
                if (currententity->player == false) {
                  if ((currententity->curstate).movetype == 0xc) {
                    if (0 < numTransObjs) {
                      iVar2 = (currententity->curstate).aiment;
                      pcVar5 = (cl_entity_t *)transObjects->pEnt;
                      if (pcVar5->index != iVar2) {
                        iVar3 = 0;
                        do {
                          iVar3 = iVar3 + 1;
                          if (iVar3 == numTransObjs) goto LAB_001c0e50;
                          pcVar5 = (cl_entity_t *)transObjects[iVar3].pEnt;
                        } while (pcVar5->index != iVar2);
                      }
                      currententity = pcVar5;
                      if (pcVar5->player == false) {
                        (*pStudioAPI->StudioDrawModel)(0);
                      }
                      else {
                        (*pStudioAPI->StudioDrawPlayer)
                                  (0,(entity_state_s *)
                                     ((cl.parsecount & CL_UPDATE_MASK) * 0x4318 + 0xc6aa3c +
                                     (pcVar5->index * 5 + -5) * 0x44));
                      }
                      currententity = (cl_entity_t *)transObjects[iVar6].pEnt;
                      (*pStudioAPI->StudioDrawModel)(3);
                    }
                  }
                  else {
                    (*pStudioAPI->StudioDrawModel)(3);
                  }
                }
                else {
                  (*pStudioAPI->StudioDrawPlayer)
                            (3,(entity_state_s *)
                               ((cl.parsecount & CL_UPDATE_MASK) * 0x4318 + 0xc6aa3c +
                               (currententity->index * 5 + -5) * 0x44));
                }
              }
              goto LAB_001c0e50;
            }
          }
          iVar2 = (currententity->curstate).body;
          if (iVar2 == 0) {
            r_entorigin[0] = currententity->origin[0];
            r_entorigin[1] = currententity->origin[1];
            r_entorigin[2] = currententity->origin[2];
          }
          else {
                    /* Unresolved local var: float * pAttachment@[???] */
            pfVar4 = R_GetAttachmentPoint((int)(currententity->curstate).skin,iVar2);
            r_entorigin[0] = *pfVar4;
            r_entorigin[1] = pfVar4[1];
            r_entorigin[2] = pfVar4[2];
          }
          if ((currententity->curstate).rendermode == 3) {
            fVar7 = GlowBlend((cl_entity_t_conflict *)currententity);
            r_blend = fVar7 * r_blend;
          }
          if (r_blend != 0.0) {
            R_DrawSpriteModel(currententity);
          }
        }
LAB_001c0e50:
        iVar6 = iVar6 + 1;
      } while (iVar6 < numTransObjs);
    }
    GL_DisableMultitexture();
    (*qglEnable)(0xbc0);
    (*qglTexEnvf)(0x2300,0x2200,8448.0);
    if (g_bUserFogOn == 0) {
      ClientDLL_DrawTransparentTriangles();
    }
    else {
      R_SetFogEnabled(false);
      ClientDLL_DrawTransparentTriangles();
    }
    if (g_bUserFogOn != 0) {
      R_SetFogEnabled(true);
    }
    numTransObjs = 0;
    r_blend = 1.0;
  }
  return;
}


// R_DrawTorus  @ 0019e250
void R_DrawTorus(vec_t *source,vec_t *delta,float width,float scale,float freq,float speed,
                int segments)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  double dVar7;
  float local_b8;
  int local_a8;
  float local_a0;
  float local_9c;
  double local_84;
  double local_7c;
  float local_70;
  vec_t local_64 [3];
  vec_t local_58 [3];
  float local_4c;
  float local_48;
  vec_t local_44;
  float local_40;
  float local_3c;
  vec_t local_34;
  float local_30;
  undefined4 local_2c;
  vec_t local_28 [6];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int noiseIndex@[???]
                       Unresolved local var: int noiseStep@[???]
                       Unresolved local var: float div@[???]
                       Unresolved local var: float length@[???]
                       Unresolved local var: float fraction@[???]
                       Unresolved local var: float factor@[???]
                       Unresolved local var: float vLast@[???]
                       Unresolved local var: float vStep@[???]
                       Unresolved local var: vec3_t last1@[???]
                       Unresolved local var: vec3_t last2@[???]
                       Unresolved local var: vec3_t point@[???]
                       Unresolved local var: vec3_t screen@[???]
                       Unresolved local var: vec3_t screenLast@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: vec3_t normal@[???] */
  if (1 < segments) {
    iVar4 = 0x80;
    if (segments < 0x81) {
      iVar4 = segments;
    }
    fVar6 = Length(delta);
    fVar1 = 0.5;
    if (0.5 <= fVar6 * 0.01) {
      fVar1 = fVar6 * 0.01;
    }
    fVar6 = 1.0 / (float)(iVar4 + -1);
    local_70 = fVar6;
    dVar7 = fmod((double)(freq * speed),1.0);
    local_a8 = 0;
    iVar5 = 0;
    do {
      local_b8 = (float)dVar7;
      fVar2 = (float)iVar5 * fVar6;
      sincos((double)((fVar2 + fVar2) * 3.1415927),&local_7c,&local_84);
      uVar3 = local_a8 >> 0x10 & 0x7f;
      local_4c = (float)local_7c * freq * delta[2] + *source;
      local_48 = (float)local_84 * freq * delta[2] + source[1];
      local_44 = source[2];
      VectorMA(&local_4c,fVar1 * scale * gNoise[uVar3],vup,&local_4c);
      dVar7 = cos((double)fVar2 * 3.141592653589793 * 3.0 + (double)freq);
      VectorMA(&local_4c,fVar1 * scale * gNoise[uVar3] * (float)dVar7,vright,&local_4c);
      ScreenTransform(&local_4c,&local_40);
      if (iVar5 != 0) {
        local_34 = local_40 - local_a0;
        local_2c = 0;
        local_30 = local_3c - local_9c;
        VectorNormalize(&local_34);
        VectorScale(vup,local_34,local_28);
        VectorMA(local_28,-local_30,vright,local_28);
        VectorMA(&local_4c,width,local_28,local_64);
        VectorMA(&local_4c,-width,local_28,local_58);
        local_b8 = local_b8 + fVar6 * fVar1;
        (*tri.TexCoord2f)(1.0,local_b8);
        (*tri.Vertex3fv)(local_58);
        (*tri.TexCoord2f)(0.0,local_b8);
        (*tri.Vertex3fv)(local_64);
      }
      iVar5 = iVar5 + 1;
      local_a0 = local_40;
      local_9c = local_3c;
      dVar7 = fmod((double)local_b8,1.0);
      local_a8 = local_a8 + (int)(fVar6 * 128.0 * 65536.0);
    } while (iVar5 <= iVar4);
  }
  return;
}


// R_DrawViewModel  @ 0017da90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_DrawViewModel(void)

{
  float fVar1;
  modtype_t mVar2;
  cl_entity_t *pcVar3;
  int iVar4;
  vec_t *p;
  uint uVar5;
  float *pfVar6;
  float fVar7;
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  float local_20;
  colorVec local_1c;
  
                    /* Unresolved local var: float[3] lightvec@[???]
                       Unresolved local var: colorVec c@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int lnum@[???]
                       Unresolved local var: vec3_t dist@[???]
                       Unresolved local var: float add@[???]
                       Unresolved local var: float oldShadows@[???]
                       Unresolved local var: dlight_t * dl@[???] */
  local_30 = 0;
  local_34 = -1.0;
  currententity = &cl.viewent;
  local_2c = local_30;
  if (((((r_drawviewmodel.value == 0.0) || (iVar4 = ClientDLL_IsThirdPerson(), iVar4 != 0)) ||
       (chase_active.value != 0.0)) || ((envmap != false || (r_drawentities.value == 0.0)))) ||
     ((cl.stats[0] < 1 ||
      ((currententity->model == (model_s *)0x0 || (cl.maxclients < cl.viewentity)))))) {
    R_LightPoint(&local_1c,currententity->origin);
    cl.light_level = (local_1c.g + local_1c.r + local_1c.b) / 3;
  }
  else {
    (*qglDepthRange)((double)gldepthmin,(double)((gldepthmax - gldepthmin) * 0.3 + gldepthmin));
    pcVar3 = currententity;
    iVar4 = cl.weaponsequence;
    mVar2 = currententity->model->type;
    if (mVar2 == mod_alias) {
      pfVar6 = &cl_dlights[0].radius;
      R_LightPoint(&local_1c,currententity->origin);
      uVar5 = (local_1c.g + local_1c.r + local_1c.b) / 3;
      r_viewlighting.ambientlight = 0x18;
      r_viewlighting.shadelight = 0x18;
      if (0x17 < uVar5) {
        r_viewlighting.ambientlight = uVar5;
        r_viewlighting.shadelight = uVar5;
      }
      do {
        fVar1 = *pfVar6;
        if ((fVar1 != 0.0) && ((float)cl.time <= pfVar6[2])) {
          local_28 = currententity->origin[0] - ((dlight_t *)(pfVar6 + -3))->origin[0];
          local_24 = currententity->origin[1] - pfVar6[-2];
          local_20 = currententity->origin[2] - pfVar6[-1];
          fVar7 = Length(&local_28);
          fVar1 = fVar1 - fVar7;
          if (0.0 < fVar1) {
            r_viewlighting.ambientlight = (int)((float)r_viewlighting.ambientlight + fVar1);
          }
        }
        pfVar6 = pfVar6 + 10;
      } while (pfVar6 != (float *)(cl_lightstyle[0].map + 8));
      if (0x80 < r_viewlighting.ambientlight) {
        r_viewlighting.ambientlight = 0x80;
      }
      if (0xc0 < r_viewlighting.shadelight + r_viewlighting.ambientlight) {
        r_viewlighting.shadelight = 0xc0 - r_viewlighting.ambientlight;
      }
      r_viewlighting.plightvec = &local_34;
      R_DrawAliasModel(currententity);
    }
    else if (mVar2 == mod_studio) {
      if (cl.weaponstarttime == 0.0) {
        cl.weaponstarttime = (float)cl.time;
      }
      p = currententity->origin;
      (currententity->curstate).frame = 0.0;
      (pcVar3->curstate).framerate = 1.0;
      (pcVar3->curstate).sequence = iVar4;
      (pcVar3->curstate).animtime = cl.weaponstarttime;
      uVar5 = (uint)(byte)cl.players[cl.playernum].topcolor;
      (pcVar3->curstate).colormap = uVar5;
      (pcVar3->curstate).colormap = (cl.players[cl.playernum].bottomcolor & 0xffU) << 8 | uVar5;
      R_LightPoint(&local_1c,p);
      fVar1 = r_shadows.value;
      r_shadows.value = 0.0;
      cl.light_level = (local_1c.g + local_1c.r + local_1c.b) / 3;
      (*pStudioAPI->StudioDrawModel)(1);
      r_shadows.value = fVar1;
    }
    else if (mVar2 == mod_brush) {
      R_DrawBrushModel(currententity);
    }
    (*qglDepthRange)((double)gldepthmin,(double)gldepthmax);
    (*qglTexEnvf)(0x2300,0x2200,8448.0);
  }
  return;
}


// R_DrawWaterChain  @ 00191710
void R_DrawWaterChain(msurface_t *pChain)

{
                    /* Unresolved local var: msurface_t * s@[???] */
  if (pChain != (msurface_t *)0x0) {
    (*qglColor4ub)(0xff,0xff,0xff,0xff);
    do {
                    /* Unresolved local var: msurface_t * s@[???] */
      GL_Bind(pChain->texinfo->texture->gl_texturenum);
      EmitWaterPolys(pChain,0);
      pChain = pChain->texturechain;
    } while (pChain != (msurface_s *)0x0);
  }
  return;
}


// R_DrawWorld  @ 00197510
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_DrawWorld(void)

{
  qboolean qVar1;
  int iVar2;
  int in_GS_OFFSET;
  mnode_t *node;
  cl_entity_t local_bc8;
  int local_10;
  
                    /* Unresolved local var: cl_entity_t ent@[???]
                       Unresolved local var: bool cleanUpShaderState@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(&local_bc8,0,3000);
  local_bc8.model = cl.worldmodel;
  currenttexture = -1;
  modelorg[0] = r_refdef.vieworg[0];
  modelorg[1] = r_refdef.vieworg[1];
  modelorg[2] = r_refdef.vieworg[2];
  local_bc8.curstate.rendercolor.r = (byte)gWaterColor.r;
  local_bc8.curstate.rendercolor.g = (byte)gWaterColor.g;
  local_bc8.curstate.rendercolor.b = (byte)gWaterColor.b;
  currententity = &local_bc8;
  (*qglColor3f)(1.0,1.0,1.0);
  Q_memset(lightmap_polys,0,0x100);
  R_ClearSkyBox();
  qVar1 = false;
  if (((g_bHasShaderFunctions != false) && (qVar1 = false, gl_use_shaders.value != 0.0)) &&
     (qVar1 = (qboolean)NAN(sv_allow_shaders.value), sv_allow_shaders.value != 0.0)) {
    qVar1 = true;
  }
  if (wasUsingShaders != qVar1) {
    R_ReUploadLightmaps();
    wasUsingShaders = false;
    if (((g_bHasShaderFunctions != false) && (wasUsingShaders = false, gl_use_shaders.value != 0.0))
       && (wasUsingShaders = (qboolean)NAN(sv_allow_shaders.value), sv_allow_shaders.value != 0.0))
    {
      wasUsingShaders = true;
    }
  }
  if (gl_texsort == false) {
    if (gl_lightmap_format == 0x1909) {
      (*qglBlendFunc)(0,0x301);
    }
    else if (gl_lightmap_format == 0x8049) {
      (*qglTexEnvf)(0x2300,0x2200,8448.0);
      (*qglColor4f)(0.0,0.0,0.0,1.0);
      (*qglBlendFunc)(0x302,0x303);
    }
    else if (gl_lightmap_format == 0x1908) {
      (*qglTexEnvf)(0x2300,0x2200,8448.0);
    }
  }
  gDecalSurfCount = 0;
  qVar1 = (qboolean)!NAN(gl_reduce_shader_changes.value);
  if (gl_reduce_shader_changes.value != 0.0) {
    qVar1 = false;
  }
  node = (cl.worldmodel)->nodes;
  R_RecursiveWorldNode(node,qVar1);
  if ((g_bHasShaderFunctions != false) && (g_uCurrentProgram != 0)) {
    node = (mnode_t *)0x0;
    (*qglUseProgram)(0);
    g_uCurrentProgram = 0;
  }
  gDecalSurfCount = 0;
  DrawTextureChains();
  S_ExtraUpdate();
  iVar2 = CL_IsDevOverviewMode();
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: glpoly_t * p@[???]
                       Unresolved local var: float * v@[???] */
  if ((((iVar2 == 0) && (R_DrawDecals((qboolean)node), filterMode == false)) &&
      (r_fullbright.value == 0.0)) && (gl_texsort != false)) {
    R_BlendLightmaps();
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// R_EntityParticles  @ 00199a60
void R_EntityParticles(cl_entity_s *ent)

{
  particle_s **pppVar1;
  double dVar2;
  particle_t *ppVar3;
  particle_t *ppVar4;
  double dVar5;
  double dVar6;
  vec_t (*pavVar7) [3];
  vec_t *pvVar8;
  vec_t *pvVar9;
  float (*pafVar10) [3];
  float (*pafVar11) [3];
  float fVar12;
  double local_2c;
  double local_24 [2];
  
                    /* Unresolved local var: int count@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float sp@[???]
                       Unresolved local var: float sy@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: float cp@[???]
                       Unresolved local var: float cy@[???]
                       Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: float dist@[???] */
  if (avelocities[0][0] == 0.0) {
    pvVar8 = avelocities[0];
    do {
      pvVar9 = pvVar8 + 1;
      fVar12 = RandomFloat(0.0,2.55);
      *pvVar8 = fVar12;
      pvVar8 = pvVar9;
    } while (pvVar9 != r_pup);
  }
  pavVar7 = avelocities;
  pafVar11 = r_avertexnormals;
  do {
    dVar2 = cl.time;
    sincos((double)((float)cl.time * (*pavVar7)[0]),local_24,&local_2c);
    dVar6 = local_24[0];
    dVar5 = local_2c;
    sincos((double)((float)dVar2 * (*pavVar7)[1]),local_24,&local_2c);
    ppVar4 = free_particles;
    ppVar3 = active_particles;
    if (free_particles == (particle_t *)0x0) {
      return;
    }
    pafVar10 = pafVar11 + 1;
    pavVar7 = pavVar7 + 1;
    active_particles = free_particles;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar3;
    ppVar4->die = (float)((longdouble)0.01 + (longdouble)cl.time);
    ppVar4->color = 0x6f;
    ppVar4->packedColor = 0;
    ppVar4->type = pt_explode;
    ppVar4->org[0] =
         (float)dVar5 * (float)local_2c * beamlength + (*pafVar11)[0] * 64.0 + ent->origin[0];
    ppVar4->org[1] =
         (float)dVar6 * (float)local_2c * beamlength + (*pafVar11)[1] * 64.0 + ent->origin[1];
    ppVar4->org[2] = -(float)local_24[0] * beamlength + ent->origin[2] + (*pafVar11)[2] * 64.0;
    pafVar11 = pafVar10;
  } while (pafVar10 != (float (*) [3])cnttextures);
  return;
}


// R_Envmap_f  @ 001b9da0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_Envmap_f(void)

{
  int in_GS_OFFSET;
  undefined1 local_464 [20];
  char local_450 [64];
  char local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: char[1024] name@[???]
                       Unresolved local var: vrect_t saveVrect@[???]
                       Unresolved local var: char[64] base@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (cl.worldmodel == (model_s *)0x0) {
    Con_Printf("No map loaded\n");
  }
  else if (gl_envmapsize.value <= 0.0) {
    Con_Printf("Invalid gl_envmapsize value\n");
  }
  else {
    if ((cl.num_entities == 0) || (cl_entities->model == (model_s *)0x0)) {
      Q_strcpy(local_450,"Env");
    }
    else {
      COM_FileBase(cl_entities->model->name,local_450);
    }
    (*qglDrawBuffer)(0x404);
    (*qglReadBuffer)(0x404);
    envmap = true;
    Q_memcpy(local_464,&r_refdef,0x14);
    r_refdef.vrect.y = 0;
    r_refdef.vrect.width = (int)gl_envmapsize.value;
    r_refdef.vrect.x = 0;
    r_refdef.viewangles[0] = 0.0;
    r_refdef.viewangles[1] = 0.0;
    r_refdef.viewangles[2] = 0.0;
    r_refdef.vrect.height = r_refdef.vrect.width;
    GL_BeginRendering(&glx,&gly,&glwidth,&glheight);
    R_RenderView();
    __snprintf_chk(local_410,0x400,1,0x400,"%srt.bmp",local_450);
    VID_TakeSnapshotRect(local_410,0,0,(int)gl_envmapsize.value,(int)gl_envmapsize.value);
    r_refdef.viewangles[1] = 90.0;
    GL_BeginRendering(&glx,&gly,&glwidth,&glheight);
    R_RenderView();
    __snprintf_chk(local_410,0x400,1,0x400,"%sbk.bmp",local_450);
    VID_TakeSnapshotRect(local_410,0,0,(int)gl_envmapsize.value,(int)gl_envmapsize.value);
    r_refdef.viewangles[1] = 180.0;
    GL_BeginRendering(&glx,&gly,&glwidth,&glheight);
    R_RenderView();
    __snprintf_chk(local_410,0x400,1,0x400,"%slf.bmp",local_450);
    VID_TakeSnapshotRect(local_410,0,0,(int)gl_envmapsize.value,(int)gl_envmapsize.value);
    r_refdef.viewangles[1] = 270.0;
    GL_BeginRendering(&glx,&gly,&glwidth,&glheight);
    R_RenderView();
    __snprintf_chk(local_410,0x400,1,0x400,"%sft.bmp",local_450);
    VID_TakeSnapshotRect(local_410,0,0,(int)gl_envmapsize.value,(int)gl_envmapsize.value);
    r_refdef.viewangles[0] = -90.0;
    r_refdef.viewangles[1] = 0.0;
    GL_BeginRendering(&glx,&gly,&glwidth,&glheight);
    R_RenderView();
    __snprintf_chk(local_410,0x400,1,0x400,"%sup.bmp",local_450);
    VID_TakeSnapshotRect(local_410,0,0,(int)gl_envmapsize.value,(int)gl_envmapsize.value);
    r_refdef.viewangles[0] = 90.0;
    r_refdef.viewangles[1] = 0.0;
    GL_BeginRendering(&glx,&gly,&glwidth,&glheight);
    R_RenderView();
    __snprintf_chk(local_410,0x400,1,0x400,"%sdn.bmp",local_450);
    VID_TakeSnapshotRect(local_410,0,0,(int)gl_envmapsize.value,(int)gl_envmapsize.value);
    Q_memcpy(&r_refdef,local_464,0x14);
    envmap = false;
    (*qglDrawBuffer)(0x405);
    (*qglReadBuffer)(0x405);
    GL_EndRendering();
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// R_Explosion  @ 00153950
void R_Explosion(float *pos,int model,float scale,float framerate,int flags)

{
  vec_t vVar1;
  _func_void_TEMPENTITY_ptr_float_int *p_Var2;
  int32 iVar3;
  TEMPENTITY *pTVar4;
  dlight_t *pdVar5;
  
                    /* Unresolved local var: dlight_t * dl@[???] */
  p_Var2 = efx.R_Sprite_Explode;
  if (scale != 0.0) {
    pTVar4 = R_DefaultSprite(pos,model,framerate);
    (*p_Var2)(pTVar4,scale,flags);
    if ((flags & 8U) == 0) {
      (*efx.R_FlickerParticles)(pos);
    }
    if ((flags & 2U) == 0) {
      pdVar5 = (*efx.CL_AllocDlight)(0);
      pdVar5->origin[0] = *pos;
      pdVar5->origin[1] = pos[1];
      vVar1 = pos[2];
      pdVar5->radius = 200.0;
      (pdVar5->color).g = 0xfa;
      pdVar5->origin[2] = vVar1;
      (pdVar5->color).r = 0xfa;
      (pdVar5->color).b = 0x96;
      pdVar5->die = (float)((longdouble)0.01 + (longdouble)cl.time);
      pdVar5->decay = 800.0;
      pdVar5 = (*efx.CL_AllocDlight)(0);
      pdVar5->origin[0] = *pos;
      pdVar5->origin[1] = pos[1];
      vVar1 = pos[2];
      pdVar5->radius = 150.0;
      (pdVar5->color).r = 0xff;
      pdVar5->origin[2] = vVar1;
      (pdVar5->color).g = 0xbe;
      (pdVar5->color).b = '(';
      pdVar5->die = (float)cl.time + 1.0;
      pdVar5->decay = 200.0;
    }
  }
  if ((flags & 4U) == 0) {
    iVar3 = RandomLong(0,2);
    if (iVar3 == 1) {
      S_StartDynamicSound(-1,0,cl_sfx_r_exp2,pos,1.0,0.3,0,100);
    }
    else if (iVar3 == 2) {
      S_StartDynamicSound(-1,0,cl_sfx_r_exp3,pos,1.0,0.3,0,100);
    }
    else if (iVar3 == 0) {
      S_StartDynamicSound(-1,0,cl_sfx_r_exp1,pos,1.0,0.3,0,100);
    }
  }
  return;
}


// R_FireCustomDecal  @ 001941a0
void R_FireCustomDecal(int textureIndex,int entity,int modelIndex,vec_t *position,int flags,
                      float scale)

{
  texture_t *ptVar1;
  mnode_t *node;
  uint uVar2;
  cl_entity_t *pcVar3;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: texture_t * ptexture@[???]
                       Unresolved local var: mnode_t * pnodes@[???]
                       Unresolved local var: cl_entity_t * pent@[???] */
  ptVar1 = Draw_DecalTexture(textureIndex);
  gDecalPos[0] = *position;
  gDecalPos[1] = position[1];
  gDecalPos[2] = position[2];
  pcVar3 = cl_entities + entity;
  if (pcVar3 == (cl_entity_t *)0x0) {
    gDecalModel = (model_t *)0x0;
  }
  else {
    gDecalModel = pcVar3->model;
    if ((gDecalModel == (model_s *)0x0) && (modelIndex != 0)) {
      gDecalModel = CL_GetModelByIndex(modelIndex);
    }
    if ((((gDecalModel != (model_t *)0x0) ||
         ((sv.active != false &&
          (gDecalModel = sv.models[sv.edicts[entity].v.modelindex], gDecalModel != (model_s *)0x0)))
         ) && (gDecalModel->type == mod_brush)) && (ptVar1 != (texture_t *)0x0)) {
      node = gDecalModel->nodes;
      if (entity != 0) {
                    /* Unresolved local var: hull_t * phull@[???]
                       Unresolved local var: vec3_t temp@[???] */
        if (gDecalModel->firstmodelsurface != 0) {
          gDecalPos[0] = (*position - gDecalModel->hulls[0].clip_mins[0]) - pcVar3->origin[0];
          node = node + gDecalModel->hulls[0].firstclipnode;
          gDecalPos[1] = (position[1] - gDecalModel->hulls[0].clip_mins[1]) - pcVar3->origin[1];
          gDecalPos[2] = (position[2] - gDecalModel->hulls[0].clip_mins[2]) - pcVar3->origin[2];
        }
        if (((pcVar3->angles[0] != 0.0) || (pcVar3->angles[1] != 0.0)) || (pcVar3->angles[2] != 0.0)
           ) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???] */
          AngleVectors(pcVar3->angles,&local_40,&local_34,&local_28);
          local_38 = local_38 * gDecalPos[2];
          local_34 = local_34 * gDecalPos[0];
          local_2c = local_2c * gDecalPos[2];
          gDecalPos[2] = gDecalPos[2] * local_20 + gDecalPos[1] * local_24 + gDecalPos[0] * local_28
          ;
          gDecalPos[0] = local_38 + local_3c * gDecalPos[1] + local_40 * gDecalPos[0];
          gDecalPos[1] = -(local_2c + local_30 * gDecalPos[1] + local_34);
        }
      }
      gDecalEntity = entity;
      gDecalIndex = textureIndex;
      gDecalFlags = flags;
      if ((flags & 4U) == 0) {
        gDecalFlags = flags | 0x20;
      }
      gDecalSize = ptVar1->width >> 1;
      uVar2 = ptVar1->height >> 1;
      if ((uint)gDecalSize < uVar2) {
        gDecalSize = uVar2;
      }
      gDecalTexture = ptVar1;
      R_DecalNode(node,scale);
      return;
    }
  }
  Con_DPrintf("Decals must hit mod_brush!\n");
  return;
}


// R_FireField  @ 0014e180
void R_FireField(vec_t *org,int radius,int modelIndex,int count,int flags,float life)

{
  uint uVar1;
  float flHigh;
  float flLow;
  model_t *model;
  int iVar2;
  TEMPENTITY *pTVar3;
  int32 iVar4;
  int iVar5;
  float fVar6;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: model_t * pModel@[???]
                       Unresolved local var: int frameCount@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float time@[???]
                       Unresolved local var: vec3_t position@[???] */
  model = CL_GetModelByIndex(modelIndex);
  if (model == (model_t *)0x0) {
    Con_Printf("No model %d!\n",modelIndex);
    return;
  }
  iVar2 = ModelFrameCount(model);
  iVar2 = iVar2 + -1;
  if (0 < count) {
    flHigh = (float)radius;
    flLow = (float)-radius;
    iVar5 = 0;
    do {
      while( true ) {
        fVar6 = *org;
        local_28 = RandomFloat(flLow,flHigh);
        local_28 = local_28 + fVar6;
        fVar6 = org[1];
        local_24 = RandomFloat(flLow,flHigh);
        local_24 = local_24 + fVar6;
        if ((flags & 0x10U) == 0) {
          fVar6 = org[2];
          local_20 = RandomFloat(flLow,flHigh);
          local_20 = local_20 + fVar6;
        }
        else {
          local_20 = org[2];
        }
        pTVar3 = (*efx.CL_TempEntAlloc)(&local_28,model);
        if (pTVar3 == (TEMPENTITY *)0x0) {
          return;
        }
        if ((flags & 8U) == 0) {
          if ((flags & 0x20U) == 0) {
            (pTVar3->entity).curstate.renderfx = 0xe;
            (pTVar3->entity).curstate.renderamt = 0xff;
            (pTVar3->entity).curstate.rendermode = 0;
            (pTVar3->entity).baseline.renderamt = 0xff;
          }
          else {
            (pTVar3->entity).curstate.rendermode = 5;
            (pTVar3->entity).curstate.renderamt = 0xb4;
          }
        }
        else {
          (pTVar3->entity).curstate.renderamt = 0x80;
          (pTVar3->entity).curstate.rendermode = 4;
          (pTVar3->entity).curstate.renderfx = 0xe;
          (pTVar3->entity).baseline.renderamt = 0x80;
        }
        fVar6 = RandomFloat(0.75,1.25);
        (pTVar3->entity).curstate.framerate = fVar6;
        fVar6 = RandomFloat(-0.25,0.5);
        pTVar3->die = fVar6 + life + (float)cl.time;
        if (1 < iVar2) {
          uVar1 = pTVar3->flags;
          pTVar3->flags = uVar1 | 0x100;
          if ((flags & 4U) == 0) {
            (pTVar3->entity).curstate.framerate = (float)iVar2 / (fVar6 + life);
          }
          else {
            (pTVar3->entity).curstate.framerate = 15.0;
            pTVar3->flags = uVar1 | 0x10100;
          }
        }
        pTVar3->frameMax = (float)iVar2;
        (pTVar3->entity).curstate.frame = 0.0;
        (pTVar3->entity).baseline.origin[0] = 0.0;
        (pTVar3->entity).baseline.origin[1] = 0.0;
        (pTVar3->entity).baseline.origin[2] = 0.0;
        if (((flags & 1U) == 0) && (((flags & 2U) == 0 || (iVar4 = RandomLong(0,1), iVar4 != 0))))
        break;
        iVar5 = iVar5 + 1;
        fVar6 = RandomFloat(10.0,30.0);
        (pTVar3->entity).baseline.origin[2] = fVar6;
        if (count == iVar5) {
          return;
        }
      }
      iVar5 = iVar5 + 1;
    } while (count != iVar5);
  }
  return;
}


// R_FizzEffect  @ 0014c5f0
void R_FizzEffect(cl_entity_s *pent,int modelIndex,int density)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  model_s *pmVar7;
  float fVar8;
  model_t *model;
  int iVar9;
  int32 iVar10;
  TEMPENTITY *pTVar11;
  int iVar12;
  float fVar13;
  double local_44;
  double local_3c;
  float local_30;
  float local_28;
  float local_24;
  vec_t local_20;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: model_t * model@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int width@[???]
                       Unresolved local var: int depth@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int frameCount@[???]
                       Unresolved local var: float maxHeight@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: float xspeed@[???]
                       Unresolved local var: float yspeed@[???]
                       Unresolved local var: vec3_t origin@[???] */
  if ((pent->model != (model_s *)0x0) && (modelIndex != 0)) {
    model = CL_GetModelByIndex(modelIndex);
    if (model != (model_t *)0x0) {
      pmVar7 = pent->model;
      fVar1 = pmVar7->maxs[2];
      fVar2 = pmVar7->mins[2];
      fVar3 = pmVar7->maxs[0];
      fVar4 = pmVar7->mins[0];
      fVar5 = pmVar7->maxs[1];
      fVar6 = pmVar7->mins[1];
      local_30 = (float)(pent->curstate).rendercolor.g +
                 (float)(pent->curstate).rendercolor.r * 256.0;
      fVar8 = -local_30;
      if ((pent->curstate).rendercolor.b == '\0') {
        fVar8 = local_30;
      }
      sincos(((double)pent->angles[1] * 3.141592653589793) / 180.0,&local_3c,&local_44);
      iVar9 = ModelFrameCount(model);
      if (-1 < density) {
        iVar12 = 0;
        do {
          fVar13 = pent->model->mins[0];
          iVar10 = RandomLong(0,(int)(fVar3 - fVar4) + -1);
          local_28 = (float)iVar10 + fVar13;
          fVar13 = pent->model->mins[1];
          iVar10 = RandomLong(0,(int)(fVar5 - fVar6) + -1);
          local_24 = (float)iVar10 + fVar13;
          local_20 = pent->model->mins[2];
          pTVar11 = (*efx.CL_TempEntAlloc)(&local_28,model);
          if (pTVar11 == (TEMPENTITY *)0x0) {
            return;
          }
          pTVar11->flags = pTVar11->flags | 1;
          iVar12 = iVar12 + 1;
          (pTVar11->entity).baseline.origin[0] = (float)local_44 * fVar8;
          (pTVar11->entity).baseline.origin[1] = fVar8 * (float)local_3c;
          pTVar11->x = local_28;
          pTVar11->y = local_24;
          iVar10 = RandomLong(0x50,0x8c);
          (pTVar11->entity).baseline.origin[2] = (float)iVar10;
          pTVar11->die = ((fVar1 - fVar2) / (float)iVar10 + (float)cl.time) - 0.1;
          iVar10 = RandomLong(0,iVar9 + -1);
          (pTVar11->entity).curstate.frame = (float)iVar10;
          fVar13 = RandomFloat(2.0,5.0);
          (pTVar11->entity).curstate.rendermode = 4;
          (pTVar11->entity).curstate.renderamt = 0xff;
          (pTVar11->entity).curstate.scale = 1.0 / fVar13;
        } while (iVar12 <= density);
      }
    }
  }
  return;
}


// R_FlickerParticles  @ 0019aac0
void R_FlickerParticles(vec_t *org)

{
  particle_s **pppVar1;
  particle_t *ppVar2;
  particle_t *ppVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: particle_t * p@[???] */
  iVar5 = 0xf;
  do {
    ppVar3 = free_particles;
    ppVar2 = active_particles;
    if (free_particles == (particle_t *)0x0) {
      return;
    }
    iVar4 = 0;
    active_particles = free_particles;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar2;
    do {
      ppVar3->org[iVar4] = org[iVar4];
      fVar6 = RandomFloat(-32.0,32.0);
      ppVar3->vel[iVar4] = fVar6;
      iVar4 = iVar4 + 1;
    } while (iVar4 != 3);
    fVar6 = RandomFloat(80.0,143.0);
    iVar5 = iVar5 + -1;
    ppVar3->vel[2] = fVar6;
    ppVar3->die = (float)cl.time + 2.0;
    ppVar3->ramp = 0.0;
    ppVar3->color = 0xfe;
    ppVar3->packedColor = 0;
    ppVar3->type = pt_blob2;
  } while (iVar5 != 0);
  return;
}


// R_FlushStudioCache  @ 000db240
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_FlushStudioCache(void)

{
  Q_memset(rgStudioCache,0,0x440);
  nCurrentHull = 0;
  r_cachecurrent = 0;
  nCurrentPlane = 0;
  return;
}


// R_FogParams  @ 001c0060
void R_FogParams(float flDensity,int iFogSkybox)

{
  g_bFogSkybox = iFogSkybox;
  flFogDensity = flDensity;
  return;
}


// R_ForceCVars  @ 0017bde0
void R_ForceCVars(qboolean mp)

{
  if (r_lightmap.value != 0.0) {
    Cvar_DirectSet(&r_lightmap,"0");
  }
  if (gl_clear.value != 0.0) {
    Cvar_DirectSet(&gl_clear,"0");
  }
  if (r_novis.value != 0.0) {
    Cvar_DirectSet(&r_novis,"0");
  }
  if (r_fullbright.value != 0.0) {
    Cvar_DirectSet(&r_fullbright,"0");
  }
  if (snd_show.value != 0.0) {
    Cvar_DirectSet(&snd_show,"0");
  }
  if (chase_active.value != 0.0) {
    Cvar_DirectSet(&chase_active,"0");
  }
  if (v_lambert.value != 1.5) {
    Cvar_DirectSet(&v_lambert,"1.5");
  }
  if (gl_monolights.value != 0.0) {
    Cvar_DirectSet(&gl_monolights,"0");
    GL_BuildLightmaps();
  }
  if (gl_wireframe.value != 0.0) {
    Cvar_DirectSet(&gl_wireframe,"0");
  }
  if (r_dynamic.value != 1.0) {
    Cvar_DirectSet(&r_dynamic,"1");
  }
  if (gl_alphamin.value != 0.25) {
    Cvar_DirectSet(&gl_alphamin,"0.25");
  }
  if (gl_max_size.value < 255.0) {
    Cvar_DirectSet(&gl_max_size,"256");
  }
  if (0.0 < gl_polyoffset.value) {
    if (gl_polyoffset.value < 0.001) {
      Cvar_DirectSet(&gl_polyoffset,"0.001");
    }
    else if (25.0 < gl_polyoffset.value) {
      Cvar_DirectSet(&gl_polyoffset,"25");
    }
  }
  else if (gl_polyoffset.value < -0.001) {
    Cvar_DirectSet(&gl_polyoffset,"-0.001");
  }
  if ((sv_cheats.value == 0.0) &&
     (((r_drawentities.value == 1.0 ||
       (Cvar_DirectSet(&r_drawentities,"1.0"), sv_cheats.value == 0.0)) && (r_shadows.value != 0.0))
     )) {
    Cvar_DirectSet(&r_shadows,"0.0");
  }
  if (v_lightgamma.value < 1.8) {
    Cvar_DirectSet(&v_lightgamma,"1.8");
    D_FlushCaches();
    return;
  }
  return;
}


// R_ForceCVars  @ 0017e7e0
void R_ForceCVars(qboolean mp)

{
  if (mp != false) {
    R_ForceCVars(mp);
    return;
  }
  return;
}


// R_FreeDeadParticles  @ 00199cf0
void R_FreeDeadParticles(particle_t **ppparticles)

{
  float fVar1;
  particle_s *ppVar2;
  particle_s *ppVar3;
  
                    /* Unresolved local var: particle_t * kill@[???]
                       Unresolved local var: particle_t * p@[???] */
  ppVar2 = *ppparticles;
  while( true ) {
    if (ppVar2 == (particle_s *)0x0) {
      return;
    }
    fVar1 = (float)cl.time;
    if (fVar1 <= ppVar2->die) break;
    if (ppVar2->deathfunc != (_func_void_particle_s_ptr *)0x0) {
      (*ppVar2->deathfunc)(ppVar2);
    }
    ppVar2->deathfunc = (_func_void_particle_s_ptr *)0x0;
    *ppparticles = ppVar2->next;
    ppVar2->next = free_particles;
    free_particles = ppVar2;
    ppVar2 = *ppparticles;
  }
  do {
    do {
      ppVar3 = ppVar2;
      ppVar2 = ppVar3->next;
      if (ppVar2 == (particle_s *)0x0) {
        return;
      }
    } while (fVar1 <= ppVar2->die);
    do {
      if (ppVar2->deathfunc != (_func_void_particle_s_ptr *)0x0) {
        (*ppVar2->deathfunc)(ppVar2);
      }
      ppVar2->deathfunc = (_func_void_particle_s_ptr *)0x0;
                    /* catch() { ... } // from try @ 00199908 with catch @ 00199d88
                       catch() { ... } // from try @ 001999b3 with catch @ 00199d88
                       catch() { ... } // from try @ 00199be7 with catch @ 00199d88 */
      ppVar3->next = ppVar2->next;
                    /* catch() { ... } // from try @ 00199924 with catch @ 00199d8c */
      ppVar2->next = free_particles;
      free_particles = ppVar2;
      ppVar2 = ppVar3->next;
      if (ppVar2 == (particle_s *)0x0) {
        return;
      }
                    /* catch() { ... } // from try @ 0019a276 with catch @ 00199da0 */
      fVar1 = (float)cl.time;
    } while (ppVar2->die < fVar1);
  } while( true );
}


// R_FunnelSprite  @ 0014e8b0
void R_FunnelSprite(float *org,int modelIndex,int reverse)

{
  float fVar1;
  model_t *model;
  int iVar2;
  TEMPENTITY *pTVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int local_48;
  int local_3c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: float flDist@[???]
                       Unresolved local var: float vel@[???]
                       Unresolved local var: vec3_t dir@[???]
                       Unresolved local var: vec3_t dest@[???]
                       Unresolved local var: model_t * model@[???]
                       Unresolved local var: int frameCount@[???] */
  if (modelIndex == 0) {
    Con_Printf("No modelindex for funnel!!\n");
  }
  else {
    model = CL_GetModelByIndex(modelIndex);
    if (model != (model_t *)0x0) {
      iVar2 = ModelFrameCount(model);
      local_3c = -0x100;
      do {
        local_48 = -0x100;
        do {
          pTVar3 = (*efx.CL_TempEntAlloc)(org,model);
          if (pTVar3 == (TEMPENTITY *)0x0) {
            return;
          }
          if (reverse == 0) {
            (pTVar3->entity).origin[0] = (float)local_3c + *org;
            (pTVar3->entity).origin[1] = (float)local_48 + org[1];
            fVar1 = org[2];
            fVar6 = RandomFloat(100.0,800.0);
            fVar1 = fVar1 + fVar6;
            (pTVar3->entity).origin[2] = fVar1;
            local_28 = *org - (pTVar3->entity).origin[0];
            local_24 = org[1] - (pTVar3->entity).origin[1];
            local_20 = org[2] - fVar1;
          }
          else {
            (pTVar3->entity).origin[0] = *org;
            (pTVar3->entity).origin[1] = org[1];
            (pTVar3->entity).origin[2] = org[2];
            fVar6 = *org;
            fVar5 = org[1];
            fVar1 = org[2];
            fVar4 = RandomFloat(100.0,800.0);
            fVar1 = fVar1 + fVar4;
            local_28 = ((float)local_3c + fVar6) - (pTVar3->entity).origin[0];
            local_24 = ((float)local_48 + fVar5) - (pTVar3->entity).origin[1];
            local_20 = fVar1 - (pTVar3->entity).origin[2];
          }
          fVar1 = fVar1 * 0.125;
          (pTVar3->entity).curstate.renderamt = 200;
          (pTVar3->entity).baseline.renderamt = 200;
          (pTVar3->entity).curstate.rendermode = 3;
          (pTVar3->entity).curstate.renderfx = 0xe;
          (pTVar3->entity).curstate.framerate = 10.0;
          pTVar3->frameMax = (float)iVar2;
          fVar6 = RandomFloat(0.1,0.4);
          pTVar3->flags = 0x84;
          (pTVar3->entity).curstate.framerate = fVar6;
          fVar6 = VectorNormalize(&local_28);
          if (fVar1 < 64.0) {
            fVar1 = 64.0;
          }
          fVar5 = RandomFloat(64.0,128.0);
          VectorScale(&local_28,fVar1 + fVar5,(pTVar3->entity).baseline.origin);
          local_48 = local_48 + 0x40;
          pTVar3->fadeSpeed = 2.0;
          pTVar3->die = (fVar6 / (fVar1 + fVar5) - 0.5) + (float)cl.time;
        } while (local_48 != 0x140);
        local_3c = local_3c + 0x40;
      } while (local_3c != 0x140);
      return;
    }
    Con_Printf("No model %d!\n",modelIndex);
  }
  return;
}


// R_GLStudioDrawPoints  @ 000dfb00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_GLStudioDrawPoints(void)

{
  char *pcVar1;
  byte bVar2;
  short sVar3;
  model_t *src;
  mstudiomodel_t *pmVar4;
  studiohdr_t *psVar5;
  studiohdr_t *psVar6;
  float fVar7;
  int iVar8;
  auxvert_t *paVar9;
  uint uVar10;
  char *pcVar11;
  char *pcVar12;
  void *pvVar13;
  int iVar14;
  model_t *pmVar15;
  float (*light) [3] [4];
  vec3_t *pavVar16;
  int iVar17;
  char *pcVar18;
  vec3_t *pavVar19;
  vec3_t *pavVar20;
  bool bVar21;
  char *pcVar22;
  int iVar23;
  char *pcVar24;
  uint uVar25;
  studiohdr_t *psVar26;
  int iVar27;
  int in_GS_OFFSET;
  float local_174;
  float local_170;
  int local_16c;
  int local_168;
  int local_164;
  char *local_160;
  char *local_158;
  studiohdr_t *local_154;
  float local_140;
  GLfloat local_13c;
  GLfloat local_138;
  GLfloat local_134;
  float local_130;
  float local_12c;
  undefined4 local_128;
  char local_124 [258];
  undefined1 local_22;
  int local_20;
  
  psVar5 = pstudiohdr;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: byte * pvertbone@[???]
                       Unresolved local var: byte * pnormbone@[???]
                       Unresolved local var: vec3_t * pstudioverts@[???]
                       Unresolved local var: vec3_t * pstudionorms@[???]
                       Unresolved local var: studiohdr_t * ptexturehdr@[???]
                       Unresolved local var: mstudiotexture_t * ptexture@[???]
                       Unresolved local var: mstudiomesh_t * pmesh@[???]
                       Unresolved local var: auxvert_t * av@[???]
                       Unresolved local var: float * lv@[???]
                       Unresolved local var: vec3_t fl@[???]
                       Unresolved local var: float lv_tmp@[???]
                       Unresolved local var: short * pskinref@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: int iFlippedVModel@[???] */
  src = r_model;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar27 = psubmodel->vertinfoindex;
  pcVar22 = pstudiohdr->name + psubmodel->norminfoindex + -8;
                    /* Unresolved local var: model_t * texmodel@[???] */
  iVar14 = pstudiohdr->textureindex;
  if (iVar14 == 0) {
                    /* Unresolved local var: model_t * texmodel@[???] */
    pmVar15 = (model_t *)r_model->texinfo;
    if ((pmVar15 == (model_t *)0x0) ||
       (pvVar13 = Cache_Check(&pmVar15->cache), pvVar13 == (void *)0x0)) {
                    /* Unresolved local var: studiohdr_t * ptexturehdr@[???]
                       Unresolved local var: char[260] modelname@[???] */
      Q_strncpy(local_124,src->name,0x102);
      local_22 = 0;
      iVar14 = Q_strlen(local_124);
      Q_strcpy(local_124 + iVar14 + -4,"T.mdl");
      pmVar15 = Mod_ForName(local_124,true,false);
      src->texinfo = (mtexinfo_t *)pmVar15;
      pvVar13 = (pmVar15->cache).data;
      Q_strncpy((char *)((int)pvVar13 + 8),local_124,0x3f);
      *(undefined1 *)((int)pvVar13 + 0x47) = 0;
    }
    local_154 = (pmVar15->cache).data;
    iVar14 = local_154->textureindex;
  }
  else {
    local_154 = pstudiohdr;
  }
  psVar6 = pstudiohdr;
  pmVar4 = psubmodel;
  iVar17 = psubmodel->meshindex;
  iVar23 = psubmodel->vertindex;
  local_160 = local_154->name + local_154->skinindex + -8;
  pcVar24 = pstudiohdr->name;
  local_158 = pstudiohdr->name + psubmodel->normindex + -8;
  iVar8 = (int)(currententity->curstate).skin;
  if ((iVar8 == 0) || (local_154->numskinfamilies <= iVar8)) {
    if ((currententity->curstate).renderfx == 0x13) goto LAB_000e077c;
LAB_000dfba8:
    if (psubmodel->numverts < 1) goto LAB_000dfca8;
    iVar8 = 0;
    paVar9 = pauxverts;
    pcVar24 = pcVar24 + iVar23 + -8;
    do {
      bVar2 = psVar5->name[iVar8 + iVar27 + -8];
      iVar8 = iVar8 + 1;
      paVar9->fv[0] =
           *(float *)(pcVar24 + 8) * bonetransform[bVar2][0][2] +
           *(float *)(pcVar24 + 4) * bonetransform[bVar2][0][1] +
           *(float *)pcVar24 * bonetransform[bVar2][0][0] + bonetransform[bVar2][0][3];
      paVar9->fv[1] =
           *(float *)(pcVar24 + 8) * bonetransform[bVar2][1][2] +
           *(float *)(pcVar24 + 4) * bonetransform[bVar2][1][1] +
           *(float *)pcVar24 * bonetransform[bVar2][1][0] + bonetransform[bVar2][1][3];
      paVar9->fv[2] =
           *(float *)(pcVar24 + 8) * bonetransform[bVar2][2][2] +
           *(float *)(pcVar24 + 4) * bonetransform[bVar2][2][1] +
           *(float *)pcVar24 * bonetransform[bVar2][2][0] + bonetransform[bVar2][2][3];
      iVar23 = psubmodel->numverts;
      paVar9 = paVar9 + 1;
      pcVar24 = pcVar24 + 0xc;
      psVar26 = psVar6;
    } while (iVar8 < iVar23);
  }
  else {
    local_160 = local_160 + iVar8 * local_154->numskinref * 2;
    if ((currententity->curstate).renderfx != 0x13) goto LAB_000dfba8;
LAB_000e077c:
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: mstudiomesh_t * pmesh@[???] */
    if (0 < psubmodel->numverts) {
      iVar27 = 0;
      do {
        g_NormalIndex[iVar27] = -1;
        iVar27 = iVar27 + 1;
      } while (iVar27 < pmVar4->numverts);
    }
    local_174 = 0.0;
    local_16c = 0;
    if (0 < pmVar4->nummesh) {
      do {
                    /* Unresolved local var: short * ptricmds@[???] */
        pcVar18 = psVar6->name + *(int *)(psVar6->name + pmVar4->meshindex + local_16c + -4) + -8;
        while (pcVar11 = pcVar18, uVar25 = (uint)*(short *)pcVar11, uVar25 != 0) {
          while( true ) {
            pcVar18 = pcVar11 + 2;
            iVar27 = (uVar25 ^ (int)uVar25 >> 0x1f) - ((int)uVar25 >> 0x1f);
            if (iVar27 == 0) break;
            pcVar12 = pcVar18;
            do {
              while (sVar3 = *(short *)pcVar12, -1 < g_NormalIndex[sVar3]) {
                pcVar12 = pcVar12 + 8;
                if (pcVar12 == pcVar11 + (iVar27 * 4 + 1) * 2) goto LAB_000e0827;
              }
              pcVar1 = pcVar12 + 2;
              pcVar12 = pcVar12 + 8;
              g_NormalIndex[sVar3] = (int)*(short *)pcVar1;
            } while (pcVar12 != pcVar11 + (iVar27 * 4 + 1) * 2);
LAB_000e0827:
            pcVar11 = pcVar18 + iVar27 * 8;
            uVar25 = (uint)*(short *)pcVar11;
            if (uVar25 == 0) goto LAB_000e0834;
          }
        }
LAB_000e0834:
        local_174 = (float)((int)local_174 + 1);
        local_16c = local_16c + 0x14;
      } while ((int)local_174 < pmVar4->nummesh);
    }
    BuildGlowShellVerts((vec3_t *)(pcVar24 + iVar23 + -8),pauxverts);
    iVar23 = psubmodel->numverts;
    psVar26 = pstudiohdr;
  }
  iVar27 = psubmodel->vertinfoindex;
  if (0 < iVar23) {
    iVar23 = 0;
    light = lightpos;
    pcVar24 = psVar26->name + psubmodel->vertindex + -8;
    do {
      iVar8 = iVar23 + iVar27;
      iVar23 = iVar23 + 1;
      R_LightStrength((uint)(byte)psVar26->name[iVar8 + -8],(float *)pcVar24,*light);
      light = light + 1;
      pcVar24 = pcVar24 + 0xc;
    } while (iVar23 < psubmodel->numverts);
  }
LAB_000dfca8:
  iVar27 = psubmodel->nummesh;
  local_164 = 0;
  pcVar24 = psVar6->name + iVar17 + -8;
  pavVar16 = pvlightvalues;
  if (0 < iVar27) {
    do {
      pavVar20 = pvlightvalues;
      iVar17 = pvlightvalues_size;
      uVar10 = *(uint *)(local_154->name +
                        *(short *)(local_160 + *(int *)(pcVar24 + 8) * 2) * 0x50 + iVar14 + 0x38) |
               g_ForcedFaceFlags;
      uVar25 = uVar10 & 0xfffffffc;
      if (r_fullbright.value < 2.0) {
        uVar25 = uVar10;
      }
      if ((currententity->curstate).rendermode == 5) {
                    /* Unresolved local var: int idx@[???] */
        if ((0 < *(int *)(pcVar24 + 0xc)) &&
           (iVar23 = ((int)pavVar16 - (int)pvlightvalues >> 2) * -0x55555555,
           iVar23 < pvlightvalues_size)) {
          if ((uVar25 & 2) == 0) {
            iVar27 = 0;
            pavVar19 = pavVar16;
            do {
              fVar7 = r_blend;
              iVar27 = iVar27 + 1;
              pavVar16 = pavVar19 + 1;
              (*pavVar19)[2] = r_blend;
              (*pavVar19)[1] = fVar7;
              (*pavVar19)[0] = fVar7;
              if (*(int *)(pcVar24 + 0xc) <= iVar27) break;
              pavVar19 = pavVar16;
            } while (((int)pavVar16 - (int)pavVar20 >> 2) * -0x55555555 < iVar17);
          }
          else {
            iVar27 = 0;
            pavVar20 = pavVar16;
            do {
              fVar7 = r_blend;
              iVar27 = iVar27 + 1;
              pavVar16 = pavVar20 + 1;
              (*pavVar20)[2] = r_blend;
              (*pavVar20)[1] = fVar7;
              (*pavVar20)[0] = fVar7;
              R_StudioChrome(chrome[iVar23],(uint)(byte)*pcVar22,(vec_t *)local_158);
              if (*(int *)(pcVar24 + 0xc) <= iVar27) break;
              iVar23 = ((int)pavVar16 - (int)pvlightvalues >> 2) * -0x55555555;
              pavVar20 = pavVar16;
            } while (iVar23 < pvlightvalues_size);
          }
          goto LAB_000dfdf5;
        }
      }
      else {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: int idx@[???] */
        if ((0 < *(int *)(pcVar24 + 0xc)) &&
           (iVar23 = ((int)pavVar16 - (int)pvlightvalues >> 2) * -0x55555555,
           iVar23 < pvlightvalues_size)) {
          if ((uVar25 & 2) == 0) {
            iVar27 = 0;
            pavVar19 = pavVar16;
            pcVar18 = pcVar22;
            pcVar11 = local_158;
            do {
              iVar27 = iVar27 + 1;
              pavVar16 = pavVar19 + 1;
              pcVar22 = pcVar18 + 1;
              local_158 = pcVar11 + 0xc;
              R_StudioLighting(&local_140,(uint)(byte)*pcVar18,uVar25,(vec_t *)pcVar11);
              (*pavVar19)[0] = r_colormix[0] * local_140;
              (*pavVar19)[1] = r_colormix[1] * local_140;
              (*pavVar19)[2] = local_140 * r_colormix[2];
              if (*(int *)(pcVar24 + 0xc) <= iVar27) break;
              pavVar19 = pavVar16;
              pcVar18 = pcVar22;
              pcVar11 = local_158;
            } while (((int)pavVar16 - (int)pavVar20 >> 2) * -0x55555555 < iVar17);
          }
          else {
            iVar27 = 0;
            pcVar18 = pcVar22;
            pavVar20 = pavVar16;
            pcVar11 = local_158;
            do {
              pavVar16 = pavVar20 + 1;
              pcVar22 = pcVar18 + 1;
              R_StudioLighting(&local_140,(uint)(byte)*pcVar18,uVar25,(vec_t *)pcVar11);
              local_158 = pcVar11 + 0xc;
              R_StudioChrome(chrome[iVar23],(uint)(byte)*pcVar18,(vec_t *)pcVar11);
              iVar27 = iVar27 + 1;
              (*pavVar20)[0] = r_colormix[0] * local_140;
              (*pavVar20)[1] = r_colormix[1] * local_140;
              (*pavVar20)[2] = local_140 * r_colormix[2];
              if (*(int *)(pcVar24 + 0xc) <= iVar27) break;
              iVar23 = ((int)pavVar16 - (int)pvlightvalues >> 2) * -0x55555555;
              pcVar18 = pcVar22;
              pavVar20 = pavVar16;
              pcVar11 = local_158;
            } while (iVar23 < pvlightvalues_size);
          }
LAB_000dfdf5:
          iVar27 = psubmodel->nummesh;
        }
      }
      local_164 = local_164 + 1;
      pcVar24 = pcVar24 + 0x14;
    } while (local_164 < iVar27);
  }
  (*qglCullFace)(0x404);
  if (((cl_righthand == (cvar_t *)0x0) || (cl_righthand->value <= 0.0)) ||
     (cl.viewent.index != currententity->index)) {
    bVar21 = false;
  }
  else {
    bVar21 = true;
    (*qglDisable)(0xb44);
  }
  psVar5 = pstudiohdr;
  iVar27 = psubmodel->normindex;
  if (0 < psubmodel->nummesh) {
    local_168 = 0;
    do {
                    /* Unresolved local var: float s@[???]
                       Unresolved local var: float t@[???]
                       Unresolved local var: short * ptricmds@[???] */
      pcVar24 = pstudiohdr->name + psubmodel->meshindex + local_168 * 0x14 + -8;
      c_alias_polys = c_alias_polys + *(int *)pcVar24;
      pcVar22 = pstudiohdr->name + *(int *)(pcVar24 + 4) + -8;
      uVar25 = *(uint *)(local_154->name +
                        *(short *)(local_160 + *(int *)(pcVar24 + 8) * 2) * 0x50 + iVar14 + 0x38) |
               g_ForcedFaceFlags;
      if (2.0 <= r_fullbright.value) {
        uVar25 = uVar25 & 0xfffffffc;
      }
      if ((uVar25 & 0x40) != 0) {
        (*qglEnable)(0xbc0);
        (*qglAlphaFunc)(0x204,0.5);
        (*qglDepthMask)('\x01');
      }
      if (((uVar25 & 0x20) != 0) && ((currententity->curstate).rendermode == 0)) {
        (*qglBlendFunc)(1,1);
        (*qglEnable)(0xbe2);
        (*qglDepthMask)('\0');
        (*qglShadeModel)(0x1d01);
      }
      if (2.0 <= r_fullbright.value) {
        (*tri.SpriteTexture)(cl_sprite_white,0);
        local_174 = 0.00390625;
        local_170 = 0.00390625;
LAB_000e02f5:
        if ((uVar25 & 2) == 0) {
LAB_000e00b6:
          while( true ) {
            iVar17 = (int)*(short *)pcVar22;
            pcVar24 = pcVar22 + 2;
            if (iVar17 == 0) break;
            if (iVar17 < 0) {
              iVar17 = -iVar17;
              (*qglBegin)(6);
LAB_000e00e1:
              pcVar18 = pcVar24;
              if (*(short *)(pcVar22 + 4) < pvlightvalues_size) {
                do {
                  (*qglTexCoord2f)((float)*(short *)(pcVar18 + 4) * local_170,
                                   (float)*(short *)(pcVar18 + 6) * local_174);
                  iVar23 = *(short *)(pcVar18 + 2) * 0xc;
                  pavVar16 = pvlightvalues + *(short *)(pcVar18 + 2);
                  if (bVar21) {
                    /* Unresolved local var: vec3_t vNormal@[???] */
                    local_130 = *(float *)(psVar5->name + iVar23 + iVar27 + -8);
                    local_12c = -*(float *)(psVar5->name +
                                           *(short *)(pcVar18 + 2) * 0xc + iVar27 + -4);
                    local_128 = *(undefined4 *)
                                 (psVar5->name + *(short *)(pcVar18 + 2) * 0xc + iVar27);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float adjr@[???]
                       Unresolved local var: float adjg@[???]
                       Unresolved local var: float adjb@[???]
                       Unresolved local var: float c@[???] */
                    if (numlights == 0) {
LAB_000e0105:
                      local_13c = (*pavVar16)[0];
                      local_138 = (*pavVar16)[1];
                      local_134 = (*pavVar16)[2];
                    }
                    else {
                      R_LightLambert(lightpos[*(short *)pcVar18],&local_130,*pavVar16,&local_13c);
                    }
                  }
                  else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float adjr@[???]
                       Unresolved local var: float adjg@[???]
                       Unresolved local var: float adjb@[???]
                       Unresolved local var: float c@[???] */
                    if (numlights == 0) goto LAB_000e0105;
                    R_LightLambert(lightpos[*(short *)pcVar18],
                                   (float *)(psVar5->name + iVar23 + iVar27 + -8),*pavVar16,
                                   &local_13c);
                  }
                  pcVar24 = pcVar18 + 8;
                  (*qglColor4f)(local_13c,local_138,local_134,r_blend);
                  paVar9 = pauxverts + *(short *)pcVar18;
                  (*qglVertex3f)(paVar9->fv[0],paVar9->fv[1],paVar9->fv[2]);
                  iVar17 = iVar17 + -1;
                } while ((iVar17 != 0) &&
                        (pcVar22 = pcVar18 + 10, pcVar18 = pcVar24,
                        *(short *)pcVar22 < pvlightvalues_size));
              }
            }
            else {
              (*qglBegin)(5);
              if (iVar17 != 0) goto LAB_000e00e1;
            }
            (*qglEnd)();
            pcVar22 = pcVar24;
          }
        }
        else {
          local_170 = local_170 * 0.0009765625;
          local_174 = local_174 * 0.0009765625;
          if ((g_ForcedFaceFlags & 2U) != 0) goto LAB_000dff76;
          sVar3 = *(short *)pcVar22;
          while (iVar17 = (int)sVar3, iVar17 != 0) {
            pcVar24 = pcVar22 + 2;
            if (iVar17 < 0) {
              iVar17 = -iVar17;
              (*qglBegin)(6);
LAB_000e035d:
              iVar23 = (int)*(short *)(pcVar22 + 4);
              pcVar22 = pcVar24;
              if (iVar23 < pvlightvalues_size) {
                do {
                  (*qglTexCoord2f)((float)chrome[iVar23][0] * local_170,
                                   (float)chrome[iVar23][1] * local_174);
                  pavVar16 = pvlightvalues + *(short *)(pcVar22 + 2);
                  if (numlights == 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float adjr@[???]
                       Unresolved local var: float adjg@[???]
                       Unresolved local var: float adjb@[???]
                       Unresolved local var: float c@[???] */
                    local_13c = (*pavVar16)[0];
                    local_138 = (*pavVar16)[1];
                    local_134 = (*pavVar16)[2];
                  }
                  else {
                    R_LightLambert(lightpos[*(short *)pcVar22],
                                   (float *)(psVar5->name +
                                            *(short *)(pcVar22 + 2) * 0xc + iVar27 + -8),*pavVar16,
                                   &local_13c);
                  }
                  pcVar24 = pcVar22 + 8;
                  (*qglColor4f)(local_13c,local_138,local_134,r_blend);
                  paVar9 = pauxverts + *(short *)pcVar22;
                  (*qglVertex3f)(paVar9->fv[0],paVar9->fv[1],paVar9->fv[2]);
                  iVar17 = iVar17 + -1;
                } while ((iVar17 != 0) &&
                        (iVar23 = (int)*(short *)(pcVar22 + 10), pcVar22 = pcVar24,
                        iVar23 < pvlightvalues_size));
              }
            }
            else {
              (*qglBegin)(5);
              if (iVar17 != 0) goto LAB_000e035d;
            }
            (*qglEnd)();
            pcVar22 = pcVar24;
            sVar3 = *(short *)pcVar24;
          }
        }
      }
      else {
        iVar17 = *(short *)(local_160 + *(int *)(pcVar24 + 8) * 2) * 0x50 + iVar14;
                    /* Unresolved local var: mstudiotexture_t * ptexture@[???]
                       Unresolved local var: float temp@[???] */
        local_170 = 1.0 / (float)*(int *)(local_154->name + iVar17 + 0x3c);
        local_174 = 1.0 / (float)*(int *)((int)local_154->eyeposition + iVar17 + -4);
        if ((g_ForcedFaceFlags & 2U) == 0) {
          R_StudioSetupSkin(local_154,(int)*(short *)(local_160 + *(int *)(pcVar24 + 8) * 2));
          goto LAB_000e02f5;
        }
        if ((uVar25 & 2) == 0) goto LAB_000e00b6;
        local_170 = local_170 * 0.0009765625;
        local_174 = local_174 * 0.0009765625;
LAB_000dff76:
        sVar3 = *(short *)pcVar22;
        while (iVar17 = (int)sVar3, iVar17 != 0) {
          pcVar22 = pcVar22 + 2;
          pcVar24 = pcVar22;
          if (iVar17 < 0) {
            iVar17 = -iVar17;
            (*qglBegin)(6);
            iVar23 = iVar17;
LAB_000dffd0:
            do {
                    /* Unresolved local var: int normalIndex@[???] */
              (*qglTexCoord2f)((float)chrome[g_NormalIndex[*(short *)pcVar24]][0] * local_170,
                               (float)chrome[g_NormalIndex[*(short *)pcVar24]][1] * local_174);
              paVar9 = pauxverts + *(short *)pcVar24;
              (*qglVertex3f)(paVar9->fv[0],paVar9->fv[1],paVar9->fv[2]);
              iVar17 = iVar17 + -1;
              pcVar24 = pcVar24 + 8;
            } while (iVar17 != 0);
            pcVar22 = pcVar22 + iVar23 * 8;
          }
          else {
            (*qglBegin)(5);
            iVar23 = iVar17;
            if (iVar17 != 0) goto LAB_000dffd0;
          }
          (*qglEnd)();
          sVar3 = *(short *)pcVar22;
        }
      }
      if ((uVar25 & 0x40) != 0) {
        (*qglAlphaFunc)(0x205,0.0);
        (*qglDisable)(0xbc0);
      }
      if (((uVar25 & 0x20) != 0) && ((currententity->curstate).rendermode == 0)) {
        (*qglDisable)(0xbe2);
        (*qglDepthMask)('\x01');
        (*qglShadeModel)(0x1d00);
      }
      local_168 = local_168 + 1;
    } while (local_168 < psubmodel->nummesh);
  }
  (*qglEnable)(0xb44);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// R_GetAnim  @ 000da880
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


// R_GetAttachmentPoint  @ 00153920
float * R_GetAttachmentPoint(int entity,int attachment)

{
                    /* Unresolved local var: cl_entity_t * pEntity@[DW_OP_reg2(EDX)] */
  if (attachment == 0) {
    return cl_entities[entity].origin;
  }
  return cl_entities[entity].angles + attachment * 3;
}


// R_GetBeamAttachmentEntity  @ 0019c460
cl_entity_t * R_GetBeamAttachmentEntity(int index)

{
  cl_entity_t *pcVar1;
  
  if (-1 < index) {
    return cl_entities + (index & 0xfff);
  }
                    /* Unresolved local var: int client_index@[???] */
  pcVar1 = ClientDLL_GetUserEntity(-index & 0xfff);
  return pcVar1;
}


// R_GetPackedColor  @ 001a21d0
void R_GetPackedColor(short *packed,short color)

{
  if (packed != (short *)0x0) {
    *packed = 0;
    return;
  }
  Con_Printf("R_GetPackedColor called without packed!\n");
  return;
}


// R_GetSpriteAxes  @ 001534a0
void R_GetSpriteAxes(cl_entity_t *pEntity,int type,vec_t *forward,vec_t *right,vec_t *up)

{
  vec_t vVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double local_2c;
  double local_24;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float dot@[???]
                       Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: vec3_t tvec@[???] */
  if ((pEntity->angles[2] == 0.0) || (type != 2)) {
    switch(type) {
    case 0:
      if ((vpn[2] <= 0.999848) && (-0.999848 <= vpn[2])) {
        *up = 0.0;
        up[1] = 0.0;
        up[2] = 1.0;
        *right = vpn[1];
        fVar2 = -vpn[0];
        right[2] = 0.0;
        right[1] = fVar2;
        VectorNormalize(right);
        *forward = -right[1];
        vVar1 = *right;
        forward[2] = 0.0;
        forward[1] = vVar1;
      }
      break;
    case 1:
      local_18 = -modelorg[0];
      local_14 = -modelorg[1];
      local_10 = -modelorg[2];
      VectorNormalize(&local_18);
      if ((local_10 <= 0.999848) && (-0.999848 <= local_10)) {
        *up = 0.0;
        up[1] = 0.0;
        up[2] = 1.0;
        right[1] = -local_18;
        *right = local_14;
        right[2] = 0.0;
        VectorNormalize(right);
        *forward = -right[1];
        vVar1 = *right;
        forward[2] = 0.0;
        forward[1] = vVar1;
      }
      break;
    case 2:
      *up = vup[0];
      *right = vright[0];
      *forward = vpn[0];
      up[1] = vup[1];
      right[1] = vright[1];
      forward[1] = vpn[1];
      up[2] = vup[2];
      right[2] = vright[2];
      forward[2] = vpn[2];
      return;
    case 3:
      AngleVectors(pEntity->angles,forward,right,up);
      return;
    case 4:
      goto switchD_001534e0_caseD_4;
    default:
                    /* WARNING: Subroutine does not return */
      Sys_Error("R_DrawSprite: Bad sprite type %d");
    }
  }
  else {
switchD_001534e0_caseD_4:
    sincos((double)(currententity->angles[2] * 0.017453292),&local_24,&local_2c);
    fVar2 = (float)local_24;
    fVar3 = (float)local_2c;
    *forward = vpn[0];
    fVar4 = -fVar2;
    *right = vup[0] * fVar2 + vright[0] * fVar3;
    *up = vup[0] * fVar3 + vright[0] * fVar4;
    forward[1] = vpn[1];
    right[1] = vup[1] * fVar2 + vright[1] * fVar3;
    up[1] = vup[1] * fVar3 + vright[1] * fVar4;
    forward[2] = vpn[2];
    right[2] = fVar2 * vup[2] + vright[2] * fVar3;
    up[2] = fVar3 * vup[2] + fVar4 * vright[2];
  }
  return;
}


// R_GetSpriteFrame  @ 00153420
mspriteframe_t * R_GetSpriteFrame(msprite_t *pSprite,int frame)

{
  mspriteframe_t *pmVar1;
  
                    /* Unresolved local var: mspriteframe_t * pspriteframe@[???] */
  if (pSprite == (msprite_t *)0x0) {
    Con_Printf("Sprite:  no pSprite!!!\n");
    pmVar1 = (mspriteframe_t *)0x0;
  }
  else if (pSprite->numframes == 0) {
    Con_Printf("Sprite:  pSprite has no frames!!!\n");
    pmVar1 = (mspriteframe_t *)0x0;
  }
  else {
    if ((frame < 0) || (pSprite->numframes <= frame)) {
      Con_DPrintf("Sprite: no such frame %d\n",frame);
      frame = 0;
    }
    if (pSprite->frames[frame].type == SPR_SINGLE) {
      pmVar1 = pSprite->frames[frame].frameptr;
    }
    else {
      pmVar1 = (mspriteframe_t *)0x0;
    }
  }
  return pmVar1;
}


// R_GetStudioBounds  @ 000e3c00
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
      goto LAB_000e3ccf;
    }
    iVar4 = 0;
  }
  else {
LAB_000e3ccf:
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
      goto LAB_000e3d0b;
    }
  }
  COM_FreeFile(pBuffer);
LAB_000e3d0b:
  FS_Close(file);
  return iVar4;
}


// R_Implosion  @ 0019d480
void R_Implosion(vec_t *end,float radius,int count,float life)

{
  particle_s **pppVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  particle_t *ppVar7;
  particle_t *ppVar8;
  int iVar9;
  float local_34;
  float local_30;
  float local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t start@[???]
                       Unresolved local var: vec3_t temp@[???]
                       Unresolved local var: vec3_t vel@[???] */
  fVar2 = radius / 100.0;
  if (0 < count) {
    iVar9 = 0;
    do {
      local_34 = RandomFloat(-100.0,100.0);
      local_34 = local_34 * fVar2;
      local_30 = RandomFloat(-100.0,100.0);
      local_30 = local_30 * fVar2;
      local_2c = RandomFloat(0.0,100.0);
      local_2c = local_2c * fVar2;
      fVar4 = *end + local_34;
      fVar5 = end[1] + local_30;
      fVar3 = local_2c + end[2];
      VectorScale(&local_34,-1.0 / life,&local_28);
      ppVar8 = free_particles;
      ppVar7 = gpActiveTracers;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: particle_t * p@[???] */
      if (free_particles != (particle_t *)0x0) {
        gpActiveTracers = free_particles;
        pppVar1 = &free_particles->next;
        free_particles = free_particles->next;
        *pppVar1 = ppVar7;
        ppVar8->die = life + (float)cl.time;
        ppVar8->color = 4;
        ppVar8->packedColor = 0xff;
        fVar6 = tracerLength.value;
        ppVar8->org[0] = fVar4;
        ppVar8->org[1] = fVar5;
        ppVar8->org[2] = fVar3;
        ppVar8->ramp = fVar6;
        ppVar8->vel[0] = local_28;
        ppVar8->vel[1] = local_24;
        ppVar8->vel[2] = local_20;
        ppVar8->type = pt_static;
      }
      iVar9 = iVar9 + 1;
    } while (count != iVar9);
  }
  return;
}


// R_Init  @ 001ba850
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_Init(void)

{
  int iVar1;
  char *pcVar2;
  GLint GVar3;
  int *piVar4;
  int *piVar5;
  
                    /* Unresolved local var: byte * hunk_base@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: qboolean bUseDisplayLists@[???] */
  Cmd_AddCommandWithFlags("timerefresh",R_TimeRefresh_f,0x10);
  Cmd_AddCommand("envmap",R_Envmap_f);
  Cmd_AddCommand("pointfile",R_ReadPointFile_f);
  Cmd_AddCommand("gl_dump",GL_Dump_f);
  Cvar_RegisterVariable(&ati_npatch);
  Cvar_RegisterVariable(&gl_wireframe);
  Cvar_RegisterVariable(&gl_widescreen_yfov);
  Cvar_RegisterVariable(&r_cachestudio);
  Cvar_RegisterVariable(&r_cullsequencebox);
  Cvar_RegisterVariable(&r_bmodelinterp);
  Cvar_RegisterVariable(&r_norefresh);
  Cvar_RegisterVariable(&r_lightmap);
  Cvar_RegisterVariable(&r_fullbright);
  Cvar_RegisterVariable(&r_decals);
  Cvar_RegisterVariable(&sp_decals);
  Cvar_RegisterVariable(&mp_decals);
  Cvar_SetValue("r_decals",4096.0);
  Cvar_RegisterVariable(&r_drawentities);
  Cvar_RegisterVariable(&r_drawviewmodel);
  Cvar_RegisterVariable(&r_mirroralpha);
  Cvar_RegisterVariable(&r_wateralpha);
  Cvar_RegisterVariable(&r_dynamic);
  Cvar_RegisterVariable(&r_novis);
  Cvar_RegisterVariable(&r_speeds);
  Cvar_RegisterVariable(&d_spriteskip);
  Cvar_RegisterVariable(&r_wadtextures);
  Cvar_RegisterVariable(&r_shadows);
  Cvar_RegisterVariable(&r_mmx);
  Cvar_RegisterVariable(&r_traceglow);
  Cvar_RegisterVariable(&r_glowshellfreq);
  Cvar_RegisterVariable(&r_prefertexturefiltering);
  Cvar_HookVariable(r_prefertexturefiltering.name,&r_prefertexturefiltering_hook);
  Cvar_RegisterVariable(&gl_clear);
  Cvar_RegisterVariable(&gl_cull);
  Cvar_RegisterVariable(&gl_affinemodels);
  Cvar_RegisterVariable(&gl_dither);
  Cvar_RegisterVariable(&gl_spriteblend);
  Cvar_RegisterVariable(&gl_polyoffset);
  Cvar_RegisterVariable(&gl_lightholes);
  Cvar_RegisterVariable(&gl_keeptjunctions);
  Cvar_RegisterVariable(&gl_wateramp);
  Cvar_RegisterVariable(&gl_overbright);
  Cvar_RegisterVariable(&gl_zmax);
  Cvar_RegisterVariable(&gl_alphamin);
  Cvar_RegisterVariable(&gl_flipmatrix);
  Cvar_RegisterVariable(&gl_monolights);
  Cvar_RegisterVariable(&gl_fog);
  Cvar_RegisterVariable(&gl_use_shaders);
  Cvar_RegisterVariable(&gl_reduce_shader_changes);
  Cvar_RegisterVariable(&gl_display_lists);
  Cmd_AddCommand("gl_reloadshaders",R_ReloadShaders);
  if (gl_mtexable != 0) {
    gl_texsort = false;
    Cvar_SetValue("gl_overbright",0.0);
  }
  iVar1 = COM_CheckParm("-displaylists");
  if (iVar1 == 0) {
LAB_001bab1e:
    pcVar2 = getenv("SteamDeck");
    if (pcVar2 == (char *)0x0) {
      pcVar2 = "0";
      goto LAB_001bab3f;
    }
  }
  else {
    iVar1 = COM_CheckParm("-nodisplaylists");
    if (iVar1 != 0) goto LAB_001bab1e;
    pcVar2 = getenv("SteamDeck");
    if (pcVar2 == (char *)0x0) {
      pcVar2 = "1";
      goto LAB_001bab3f;
    }
  }
  Con_Printf("Running on Steam Deck.\n");
  pcVar2 = "1";
LAB_001bab3f:
  Cvar_Set("gl_display_lists",pcVar2);
  R_InitParticles();
  R_InitParticleTexture();
  R_UploadEmptyTex();
  piVar4 = playertextures;
  do {
    GVar3 = GL_GenTexture();
    piVar5 = piVar4 + 1;
    *piVar4 = GVar3;
    piVar4 = piVar5;
  } while (piVar5 != d_lightstylevalue);
  return;
}


// R_InitParticleTexture  @ 001ba610
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_InitParticleTexture(void)

{
  byte bVar1;
  char *pcVar2;
  byte (*pabVar3) [8];
  int iVar4;
  int local_118;
  int local_114;
  int local_110;
  char local_10c [32];
  char local_ec [32];
  char local_cc [32];
  char local_ac [32];
  char local_8c [32];
  char local_6c [32];
  char local_4c [32];
  char local_2c [36];
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: byte[8][8][4] data@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int bpp@[???] */
  iVar4 = 0;
  particletexture = GL_GenTexture();
  GL_Bind(particletexture);
  pcVar2 = local_10c;
  pabVar3 = dottexture;
  do {
    bVar1 = (*pabVar3)[0];
    iVar4 = iVar4 + 1;
    *pcVar2 = -1;
    pcVar2[1] = -1;
    pcVar2[2] = -1;
    pcVar2[3] = -bVar1;
    bVar1 = (*pabVar3)[1];
    pcVar2[0x20] = -1;
    pcVar2[0x21] = -1;
    pcVar2[0x22] = -1;
    pcVar2[0x23] = -bVar1;
    bVar1 = (*pabVar3)[2];
    pcVar2[0x40] = -1;
    pcVar2[0x41] = -1;
    pcVar2[0x42] = -1;
    pcVar2[0x43] = -bVar1;
    bVar1 = (*pabVar3)[3];
    pcVar2[0x60] = -1;
    pcVar2[0x61] = -1;
    pcVar2[0x62] = -1;
    pcVar2[99] = -bVar1;
    bVar1 = (*pabVar3)[4];
    pcVar2[0x80] = -1;
    pcVar2[0x81] = -1;
    pcVar2[0x82] = -1;
    pcVar2[0x83] = -bVar1;
    bVar1 = (*pabVar3)[5];
    pcVar2[0xa0] = -1;
    pcVar2[0xa1] = -1;
    pcVar2[0xa2] = -1;
    pcVar2[0xa3] = -bVar1;
    pcVar2[0xc0] = -1;
    pcVar2[0xc1] = -1;
    pcVar2[0xc2] = -1;
    bVar1 = (*pabVar3)[6];
    pcVar2[0xe0] = -1;
    pcVar2[0xe1] = -1;
    pcVar2[0xe2] = -1;
    pcVar2[0xc3] = -bVar1;
    pcVar2[0xe3] = -(*pabVar3)[7];
    pcVar2 = pcVar2 + 4;
    pabVar3 = pabVar3 + 1;
  } while (iVar4 != 8);
  VideoMode_GetCurrentVideoMode(&local_118,&local_114,&local_110);
  if (local_110 == 0x20) {
    (*qglTexImage2D)(0xde1,0,0x8058,8,8,0,0x1908,0x1401,local_10c);
  }
  else {
    (*qglTexImage2D)(0xde1,0,0x8057,8,8,0,0x1908,0x1401,local_10c);
  }
  (*qglTexEnvf)(0x2300,0x2200,8448.0);
  (*qglTexParameterf)(0xde1,0x2801,9729.0);
  (*qglTexParameterf)(0xde1,0x2800,9729.0);
  (*qglTexParameterf)(0xde1,0x84fe,gl_ansio.value);
  return;
}


// R_InitParticles  @ 001999b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_InitParticles(void)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???] */
                    /* try { // try from 001999b3 to 001a9a11 has its CatchHandler @ 00199d88 */
  iVar1 = COM_CheckParm("-particles");
  if (iVar1 == 0) {
    r_numparticles = 0x800;
    iVar1 = 0x1c000;
  }
  else {
    r_numparticles = Q_atoi(com_argv[iVar1 + 1]);
    if (r_numparticles < 0x200) {
      r_numparticles = 0x200;
      iVar1 = 0x7000;
    }
    else {
      iVar1 = r_numparticles * 0x38;
    }
  }
  particles = Hunk_AllocName(iVar1,"particles");
  gBeams = Hunk_AllocName(0x3e00,"lightning");
  return;
}


// R_InitSky  @ 0018e540
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_InitSky(void)

{
  gLoadSky = 1;
  return;
}


// R_InitStudioCache  @ 000db200
void R_InitStudioCache(void)

{
  Q_memset(rgStudioCache,0,0x440);
  nCurrentHull = 0;
  r_cachecurrent = 0;
  nCurrentPlane = 0;
  return;
}


// R_InitTextures  @ 001ba3c0
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
  ptVar2 = Hunk_AllocName(0x19c,"notexture");
  local_20 = 0;
  r_notexture_mip = ptVar2;
  ptVar2->height = 0x10;
  ptVar2->width = 0x10;
  ptVar2->offsets[0] = 0x48;
  ptVar2->offsets[1] = 0x148;
  ptVar2->offsets[2] = 0x188;
  ptVar2->offsets[3] = 0x198;
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


// R_InsertCustomDecal  @ 00193650
void R_InsertCustomDecal(decal_t *pdecal,msurface_t *surface)

{
  decal_s *pdVar1;
  decal_s *pdVar2;
  
                    /* Unresolved local var: decal_t * p@[???]
                       Unresolved local var: decal_t * prev@[???] */
  pdVar2 = surface->pdecals;
  if (pdVar2 != (decal_s *)0x0) {
    pdVar1 = pdVar2;
    if ((pdVar2->flags & 0x80) != 0) {
      pdecal->pnext = pdVar2;
      surface->pdecals = pdecal;
      return;
    }
    while (pdVar2 = pdVar1, pdVar1 = pdVar2->pnext, pdVar1 != (decal_s *)0x0) {
      if ((pdVar1->flags & 0x80) != 0) {
        pdecal->pnext = pdVar1;
        pdVar2->pnext = pdecal;
        return;
      }
    }
  }
  pdVar2->pnext = pdecal;
  return;
}


// R_IsRemapSkin  @ 000de600
int R_IsRemapSkin(char *texture,int *low,int *mid,int *high)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int in_GS_OFFSET;
  char local_40 [32];
  int local_20;
  
                    /* Unresolved local var: char[32] sz@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: char ch@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = 0;
  iVar1 = Q_strnicmp(texture,"Remap",5);
  if (iVar1 == 0) {
                    /* Unresolved local var: char[32] sz@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: char ch@[???] */
    uVar2 = Q_strlen(texture);
    iVar3 = 0;
    if ((uVar2 & 0xfffffffb) == 0x12) {
      if (uVar2 == 0x12) {
        if ((texture[5] & 0xdfU) != 0x43) goto LAB_000de653;
        Q_memset(local_40,0,0x20);
        Q_strncpy(local_40,texture + 7,3);
        iVar3 = Q_atoi(local_40);
        *low = iVar3;
        Q_strncpy(local_40,texture + 0xb,3);
        iVar3 = Q_atoi(local_40);
        *mid = iVar3;
      }
      else {
        Q_memset(local_40,0,0x20);
        Q_strncpy(local_40,texture + 7,3);
        iVar3 = Q_atoi(local_40);
        *low = iVar3;
        Q_strncpy(local_40,texture + 0xb,3);
        iVar3 = Q_atoi(local_40);
        *mid = iVar3;
        if (uVar2 == 0x16) {
          Q_strncpy(local_40,texture + 0xf,3);
          iVar3 = 1;
          iVar1 = Q_atoi(local_40);
          *high = iVar1;
          goto LAB_000de653;
        }
      }
      *high = 0;
      iVar3 = 1;
    }
  }
LAB_000de653:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// R_KillAttachedTents  @ 0014e7c0
void R_KillAttachedTents(int client)

{
  tempent_s *ptVar1;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???] */
  if ((-1 < client) && (ptVar1 = gpTempEntActive, client <= cl.maxclients)) {
    do {
      if (ptVar1 == (TEMPENTITY *)0x0) {
        return;
      }
      while (((ptVar1->flags & 0x8000U) == 0 || (client != ptVar1->clientIndex))) {
        ptVar1 = ptVar1->next;
        if (ptVar1 == (tempent_s *)0x0) {
          return;
        }
      }
      ptVar1->die = (float)cl.time;
      ptVar1 = ptVar1->next;
    } while( true );
  }
  Con_Printf("Bad client in R_KillAttachedTents()!\n");
  return;
}


// R_KillDeadBeams  @ 0019d340
void R_KillDeadBeams(int deadEntity)

{
  BEAM *pBVar1;
  particle_s *ppVar2;
  BEAM *dest;
  BEAM *pBVar3;
  
                    /* Unresolved local var: BEAM * pbeam@[???]
                       Unresolved local var: BEAM * pnewlist@[???]
                       Unresolved local var: BEAM * pnext@[???]
                       Unresolved local var: particle_t * pHead@[???] */
  pBVar3 = (BEAM *)0x0;
  pBVar1 = gpActiveBeams;
  do {
    if (pBVar1 == (BEAM *)0x0) {
      gpActiveBeams = pBVar3;
      return;
    }
    while ((dest = pBVar1, pBVar1 = dest->next, dest->startEntity != deadEntity ||
           (dest->flags = dest->flags & 0xfffffffc, dest->type == 0x16))) {
      dest->next = pBVar3;
      pBVar3 = dest;
      if (pBVar1 == (BEAM *)0x0) {
        gpActiveBeams = dest;
        return;
      }
    }
    dest->die = (float)((longdouble)cl.time - (longdouble)0.1);
    for (ppVar2 = dest->particles; ppVar2 != (particle_s *)0x0; ppVar2 = ppVar2->next) {
      ppVar2->die = (float)((longdouble)cl.time - (longdouble)0.1);
    }
    R_FreeDeadParticles(&dest->particles);
    Q_memset(dest,0,0x7c);
    dest->next = gpFreeBeams;
    gpFreeBeams = dest;
  } while( true );
}


// R_LargeFunnel  @ 0019afe0
void R_LargeFunnel(vec_t *org,int reverse)

{
  particle_s **pppVar1;
  float fVar2;
  particle_t *ppVar3;
  particle_t *ppVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int local_38;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: float vel@[???]
                       Unresolved local var: vec3_t dir@[???]
                       Unresolved local var: vec3_t dest@[???]
                       Unresolved local var: float flDist@[???] */
  local_38 = -0x100;
  do {
    iVar5 = -0x100;
    do {
      ppVar4 = free_particles;
      ppVar3 = active_particles;
      if (free_particles == (particle_t *)0x0) {
        return;
      }
      active_particles = free_particles;
      pppVar1 = &free_particles->next;
      free_particles = free_particles->next;
      *pppVar1 = ppVar3;
      if (reverse == 0) {
        ppVar4->org[0] = (float)local_38 + *org;
        ppVar4->org[1] = (float)iVar5 + org[1];
        fVar7 = org[2];
        fVar8 = RandomFloat(100.0,800.0);
        ppVar4->org[2] = fVar8 + fVar7;
        local_28 = *org - ppVar4->org[0];
        local_24 = org[1] - ppVar4->org[1];
        local_20 = org[2] - (fVar8 + fVar7);
        fVar2 = ppVar4->org[2];
      }
      else {
        ppVar4->org[0] = *org;
        ppVar4->org[1] = org[1];
        ppVar4->org[2] = org[2];
        fVar7 = *org;
        fVar8 = org[1];
        fVar2 = org[2];
        fVar6 = RandomFloat(100.0,800.0);
        fVar2 = fVar2 + fVar6;
        local_28 = ((float)local_38 + fVar7) - ppVar4->org[0];
        local_24 = ((float)iVar5 + fVar8) - ppVar4->org[1];
        local_20 = fVar2 - ppVar4->org[2];
      }
      fVar2 = fVar2 * 0.125;
      ppVar4->color = 0xf4;
      ppVar4->packedColor = 0;
      ppVar4->type = pt_static;
      fVar7 = VectorNormalize(&local_28);
      if (fVar2 < 64.0) {
        fVar2 = 64.0;
      }
      iVar5 = iVar5 + 0x20;
      fVar8 = RandomFloat(64.0,128.0);
      VectorScale(&local_28,fVar2 + fVar8,ppVar4->vel);
      ppVar4->die = fVar7 / (fVar2 + fVar8) + (float)cl.time;
    } while (iVar5 != 0x120);
    local_38 = local_38 + 0x20;
  } while (local_38 != 0x120);
  return;
}


// R_LavaSplash  @ 0019ae60
void R_LavaSplash(vec_t *org)

{
  particle_s **pppVar1;
  double dVar2;
  particle_t *ppVar3;
  particle_t *ppVar4;
  int32 iVar5;
  vec_t *out;
  int iVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  int local_34;
  float local_28;
  float local_24;
  undefined4 local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: float vel@[???]
                       Unresolved local var: vec3_t dir@[???] */
  local_34 = -0x80;
  do {
    iVar7 = -0x80;
    do {
      ppVar4 = free_particles;
      ppVar3 = active_particles;
      if (free_particles == (particle_t *)0x0) {
        return;
      }
      active_particles = free_particles;
      out = free_particles->vel;
      pppVar1 = &free_particles->next;
      free_particles = free_particles->next;
      *pppVar1 = ppVar3;
      dVar2 = cl.time;
      fVar8 = RandomFloat(2.0,2.62);
      ppVar4->die = (float)dVar2 + fVar8;
      iVar5 = RandomLong(0xe0,0xe7);
      ppVar4->packedColor = 0;
      ppVar4->type = pt_slowgrav;
      ppVar4->color = (short)iVar5;
      local_28 = RandomFloat(0.0,7.0);
      iVar6 = iVar7 + 8;
      local_28 = (float)iVar7 + local_28;
      local_24 = RandomFloat(0.0,7.0);
      local_20 = 0x43800000;
      local_24 = (float)local_34 + local_24;
      ppVar4->org[0] = *org + local_28;
      ppVar4->org[1] = org[1] + local_24;
      fVar8 = org[2];
      fVar9 = RandomFloat(0.0,63.0);
      ppVar4->org[2] = fVar9 + fVar8;
      VectorNormalize(&local_28);
      fVar8 = RandomFloat(50.0,113.0);
      VectorScale(&local_28,fVar8,out);
      iVar7 = iVar6;
    } while (iVar6 != 0x80);
    local_34 = local_34 + 8;
  } while (local_34 != 0x80);
  return;
}


// R_LightLambert  @ 000d7110
void __regparm3 R_LightLambert(float (*light) [4],float *normal,float *src,float *lambert)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float *pfVar8;
  int (*paiVar9) [3];
  int iVar10;
  float fVar11;
  float local_40;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float adjr@[???]
                       Unresolved local var: float adjg@[???]
                       Unresolved local var: float adjb@[???]
                       Unresolved local var: float c@[???] */
  iVar7 = numlights;
  if (0 < numlights) {
    fVar4 = 0.0;
    paiVar9 = locallinearlight;
    pfVar8 = *light + 3;
    iVar10 = 0;
    local_40 = 0.0;
    fVar5 = fVar4;
    do {
      fVar1 = (*(float (*) [4])(pfVar8 + -3))[0];
      fVar11 = pfVar8[-2];
      fVar2 = pfVar8[-1];
      fVar6 = -(normal[2] * fVar2 + normal[1] * fVar11 + *normal * fVar1);
      if (0.0 < fVar6) {
        fVar3 = *pfVar8;
        if (fVar3 == 0.0) {
          fVar1 = fVar2 * fVar2 + fVar11 * fVar11 + fVar1 * fVar1;
          if (0.0 < fVar1) {
                    /* Unresolved local var: float r2@[???]
                       Unresolved local var: float r@[???] */
            fVar11 = SQRT(fVar1);
            if (NAN(fVar11)) {
              fVar11 = sqrtf(fVar1);
            }
            fVar3 = locallightR2[iVar10] / (fVar11 * fVar1);
            *pfVar8 = fVar3;
          }
          else {
            *pfVar8 = 1.0;
            fVar3 = 1.0;
          }
        }
        fVar3 = fVar3 * fVar6;
        fVar5 = (float)(*paiVar9)[0] * fVar3 + fVar5;
        fVar4 = (float)(*paiVar9)[1] * fVar3 + fVar4;
        local_40 = (float)(*paiVar9)[2] * fVar3 + local_40;
      }
      iVar10 = iVar10 + 1;
      paiVar9 = paiVar9 + 1;
      pfVar8 = pfVar8 + 4;
    } while (iVar10 != iVar7);
    if ((fVar5 != 0.0 || fVar4 != 0.0) || (local_40 != 0.0)) {
                    /* Unresolved local var: int j@[???] */
      fVar1 = 1.0;
      if ((int)((float)lineargammatable[(int)(*src * 1023.0)] + fVar5) < 0x400) {
        fVar1 = (float)screengammatable
                       [(int)((float)lineargammatable[(int)(*src * 1023.0)] + fVar5)] / 1023.0;
      }
      *lambert = fVar1;
      fVar5 = 1.0;
      if ((int)((float)lineargammatable[(int)(src[1] * 1023.0)] + fVar4) < 0x400) {
        fVar5 = (float)screengammatable
                       [(int)((float)lineargammatable[(int)(src[1] * 1023.0)] + fVar4)] / 1023.0;
      }
      lambert[1] = fVar5;
      if ((int)((float)lineargammatable[(int)(src[2] * 1023.0)] + local_40) < 0x400) {
        lambert[2] = (float)screengammatable
                            [(int)((float)lineargammatable[(int)(src[2] * 1023.0)] + local_40)] /
                     1023.0;
        return;
      }
      lambert[2] = 1.0;
      return;
    }
  }
  *lambert = *src;
  lambert[1] = src[1];
  lambert[2] = src[2];
  return;
}


// R_LightLambert  @ 000ddea0
void R_LightLambert(float (*light) [4],float *normal,float *src,float *lambert)

{
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float adjr@[???]
                       Unresolved local var: float adjg@[???]
                       Unresolved local var: float adjb@[???]
                       Unresolved local var: float c@[???] */
  if (numlights != 0) {
    R_LightLambert(light,normal,src,lambert);
    return;
  }
  *lambert = *src;
  lambert[1] = src[1];
  lambert[2] = src[2];
  return;
}


// R_LightPoint  @ 00199450
colorVec * R_LightPoint(colorVec *__return_storage_ptr__,vec_t *p)

{
  float fVar1;
  mnode_t *pmVar2;
  mplane_t *pmVar3;
  mtexinfo_t *pmVar4;
  float fVar5;
  float fVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  msurface_t *pmVar10;
  uint uVar11;
  color24_conflict *pcVar12;
  int iVar13;
  mnode_s *node;
  uint local_70;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  colorVec local_3c;
  colorVec local_2c;
  
                    /* Unresolved local var: vec3_t end@[???] */
                    /* Unresolved local var: colorVec c@[???] */
  local_3c.r = 0;
  local_3c.g = 0;
  local_3c.b = 0;
  local_54 = *p;
  local_3c.a = 0;
  local_50 = p[1];
  fVar1 = p[2];
  local_4c = fVar1 - 2048.0;
  if ((cl.worldmodel)->lightdata == (color24 *)0x0) {
    __return_storage_ptr__->r = 0xff;
    __return_storage_ptr__->g = 0xff;
    __return_storage_ptr__->b = 0xff;
    __return_storage_ptr__->a = 0;
    return __return_storage_ptr__;
  }
  pmVar2 = (cl.worldmodel)->nodes;
                    /* Unresolved local var: colorVec c@[???]
                       Unresolved local var: float front@[???]
                       Unresolved local var: float back@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: vec3_t mid@[???]
                       Unresolved local var: msurface_t * surf@[???]
                       Unresolved local var: int s@[???]
                       Unresolved local var: int t@[???]
                       Unresolved local var: int ds@[???]
                       Unresolved local var: int dt@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: mtexinfo_t * tex@[???]
                       Unresolved local var: color24 * lightmap@[???]
                       Unresolved local var: uint scale@[???]
                       Unresolved local var: int maps@[???] */
  local_2c.g = 0;
  local_2c.b = 0;
  local_2c.a = 0;
  local_2c.r = 0;
  if (pmVar2->contents < 0) {
    local_3c.b = 0;
    local_3c.a = 0;
    local_2c.g = 0;
    local_2c.r = 0;
  }
  else {
    pmVar3 = pmVar2->plane;
    fVar5 = pmVar3->normal[1] * local_50 + pmVar3->normal[0] * local_54;
    fVar6 = (pmVar3->normal[2] * fVar1 + fVar5) - pmVar3->dist;
    fVar5 = (pmVar3->normal[2] * local_4c + fVar5) - pmVar3->dist;
    bVar7 = fVar6 < 0.0;
    if (fVar5 < 0.0 == bVar7) {
      node = pmVar2->children[bVar7];
    }
    else {
      fVar6 = fVar6 / (fVar6 - fVar5);
      local_48 = (local_54 - local_54) * fVar6 + local_54;
      local_44 = (local_50 - local_50) * fVar6 + local_50;
      local_40 = fVar1 + (local_4c - fVar1) * fVar6;
      RecursiveLightPoint(&local_2c,pmVar2->children[bVar7],p,&local_48);
      if ((local_2c.g != 0 || local_2c.r != 0) || local_2c.b != 0) {
        local_3c.a = local_2c.a;
        local_3c.b = local_2c.b;
        goto LAB_0019979e;
      }
      lightspot[0] = local_48;
      lightspot[1] = local_44;
      lightspot[2] = local_40;
      pmVar10 = (cl.worldmodel)->surfaces + pmVar2->firstsurface;
      lightplane = pmVar3;
      if (pmVar2->numsurfaces != 0) {
        uVar11 = 0;
        do {
          if ((pmVar10->flags & 0x20) == 0) {
            pmVar4 = pmVar10->texinfo;
            iVar8 = (int)(pmVar4->vecs[0][2] * local_40 +
                          pmVar4->vecs[0][1] * local_44 + pmVar4->vecs[0][0] * local_48 +
                         pmVar4->vecs[0][3]);
            if (pmVar10->texturemins[0] <= iVar8) {
              iVar9 = (int)(pmVar4->vecs[1][2] * local_40 +
                            pmVar4->vecs[1][1] * local_44 + pmVar4->vecs[1][0] * local_48 +
                           pmVar4->vecs[1][3]);
              if (pmVar10->texturemins[1] <= iVar9) {
                iVar8 = iVar8 - pmVar10->texturemins[0];
                if (iVar8 <= pmVar10->extents[0]) {
                  iVar9 = iVar9 - pmVar10->texturemins[1];
                  if (iVar9 <= pmVar10->extents[1]) {
                    if (pmVar10->samples == (color24_conflict *)0x0) {
                      local_3c.a = local_2c.a;
                      local_3c.b = 0;
                    }
                    else {
                      iVar13 = ((int)pmVar10->extents[0] >> 4) + 1;
                      pcVar12 = pmVar10->samples + (iVar8 >> 4) + (iVar9 >> 4) * iVar13;
                      iVar13 = iVar13 * (((int)pmVar10->extents[1] >> 4) + 1);
                      if (pmVar10->styles[0] == 0xff) {
                        local_3c.b = 0;
                        local_2c.g = 0;
                        local_2c.r = 1;
                      }
                      else {
                        iVar8 = d_lightstylevalue[pmVar10->styles[0]];
                        local_2c.r = (uint)pcVar12->r * iVar8;
                        local_70 = (uint)pcVar12->g * iVar8;
                        local_3c.b = iVar8 * (uint)pcVar12->b;
                        pcVar12 = pcVar12 + iVar13;
                        if (pmVar10->styles[1] != 0xff) {
                          iVar8 = d_lightstylevalue[pmVar10->styles[1]];
                          local_2c.r = local_2c.r + (uint)pcVar12->r * iVar8;
                          local_70 = local_70 + (uint)pcVar12->g * iVar8;
                          local_3c.b = local_3c.b + iVar8 * (uint)pcVar12->b;
                          pcVar12 = pcVar12 + iVar13;
                          if (pmVar10->styles[2] != 0xff) {
                            iVar8 = d_lightstylevalue[pmVar10->styles[2]];
                            local_2c.r = local_2c.r + (uint)pcVar12->r * iVar8;
                            local_70 = local_70 + (uint)pcVar12->g * iVar8;
                            local_3c.b = local_3c.b + iVar8 * (uint)pcVar12->b;
                            pcVar12 = pcVar12 + iVar13;
                            if (pmVar10->styles[3] != 0xff) {
                              iVar8 = d_lightstylevalue[pmVar10->styles[3]];
                              local_2c.r = local_2c.r + (uint)pcVar12->r * iVar8;
                              local_70 = local_70 + (uint)pcVar12->g * iVar8;
                              local_3c.b = local_3c.b + iVar8 * (uint)pcVar12->b;
                            }
                          }
                        }
                        local_3c.b = local_3c.b >> 8;
                        local_2c.g = local_70 >> 8;
                        local_2c.r = local_2c.r >> 8;
                        if (local_2c.r == 0) {
                          local_2c.r = 1;
                        }
                      }
                      local_3c.a = local_2c.a;
                    }
                    goto LAB_0019979e;
                  }
                }
              }
            }
          }
          uVar11 = uVar11 + 1;
          pmVar10 = pmVar10 + 1;
        } while (uVar11 != pmVar2->numsurfaces);
      }
      p = &local_48;
      node = pmVar2->children[!bVar7];
    }
    RecursiveLightPoint(&local_3c,node,p,&local_54);
    local_2c.r = local_3c.r;
    local_2c.g = local_3c.g;
  }
LAB_0019979e:
  local_2c.r = local_2c.r + r_refdef.ambientlight.r;
  local_2c.g = local_2c.g + r_refdef.ambientlight.g;
  local_3c.b = local_3c.b + r_refdef.ambientlight.b;
  if (0xff < local_2c.r) {
    local_2c.r = 0xff;
  }
  if (0xff < local_2c.g) {
    local_2c.g = 0xff;
  }
  if (0xff < local_3c.b) {
    local_3c.b = 0xff;
  }
  __return_storage_ptr__->b = local_3c.b;
  __return_storage_ptr__->r = local_2c.r;
  __return_storage_ptr__->g = local_2c.g;
  __return_storage_ptr__->a = local_3c.a;
  return __return_storage_ptr__;
}


// R_LightStrength  @ 000ddbd0
void R_LightStrength(int bone,float *vert,float (*light) [4])

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
  int iVar16;
  int iVar17;
  bool bVar18;
  
  iVar17 = r_smodels_total;
                    /* Unresolved local var: int i@[???] */
  iVar16 = numlights;
                    /* Unresolved local var: vec3_t lpos@[???] */
  if (lightage[bone] != r_smodels_total) {
    if (0 < numlights) {
      bVar18 = numlights != 1;
      fVar1 = lighttransform[bone][0][3];
      fVar2 = lighttransform[bone][1][3];
      fVar3 = lighttransform[bone][2][3];
      fVar4 = lighttransform[bone][0][0];
      fVar5 = lighttransform[bone][1][0];
      fVar6 = lighttransform[bone][2][0];
      fVar7 = lighttransform[bone][0][1];
      fVar8 = lighttransform[bone][1][1];
      fVar9 = lighttransform[bone][2][1];
      fVar10 = lighttransform[bone][0][2];
      fVar11 = lighttransform[bone][1][2];
      fVar12 = lighttransform[bone][2][2];
      fVar15 = locallight[0]->origin[0] - fVar1;
      fVar13 = locallight[0]->origin[1] - fVar2;
      fVar14 = locallight[0]->origin[2] - fVar3;
      lightbonepos[bone][0][0] = fVar6 * fVar14 + fVar4 * fVar15 + fVar5 * fVar13;
      lightbonepos[bone][0][1] = fVar9 * fVar14 + fVar8 * fVar13 + fVar7 * fVar15;
      lightbonepos[bone][0][2] = fVar14 * fVar12 + fVar13 * fVar11 + fVar15 * fVar10;
      if (bVar18) {
        fVar15 = locallight[1]->origin[0] - fVar1;
        fVar14 = locallight[1]->origin[1] - fVar2;
        fVar13 = locallight[1]->origin[2] - fVar3;
        lightbonepos[bone][1][0] = fVar6 * fVar13 + fVar5 * fVar14 + fVar4 * fVar15;
        lightbonepos[bone][1][1] = fVar9 * fVar13 + fVar8 * fVar14 + fVar7 * fVar15;
        lightbonepos[bone][1][2] = fVar13 * fVar12 + fVar15 * fVar10 + fVar14 * fVar11;
        if (iVar16 != 2) {
          fVar1 = locallight[2]->origin[0] - fVar1;
          fVar2 = locallight[2]->origin[1] - fVar2;
          fVar3 = locallight[2]->origin[2] - fVar3;
          lightbonepos[bone][2][0] = fVar6 * fVar3 + fVar5 * fVar2 + fVar4 * fVar1;
          lightbonepos[bone][2][1] = fVar9 * fVar3 + fVar8 * fVar2 + fVar7 * fVar1;
          lightbonepos[bone][2][2] = fVar3 * fVar12 + fVar11 * fVar2 + fVar1 * fVar10;
        }
      }
    }
    lightage[bone] = iVar17;
  }
  if (0 < iVar16) {
    (*light)[0] = *vert - lightbonepos[bone][0][0];
    (*light)[1] = vert[1] - lightbonepos[bone][0][1];
    fVar1 = vert[2];
    fVar2 = lightbonepos[bone][0][2];
    (*light)[3] = 0.0;
    (*light)[2] = fVar1 - fVar2;
    if (iVar16 != 1) {
      light[1][0] = *vert - lightbonepos[bone][1][0];
      light[1][1] = vert[1] - lightbonepos[bone][1][1];
      fVar1 = vert[2];
      fVar2 = lightbonepos[bone][1][2];
      light[1][3] = 0.0;
      light[1][2] = fVar1 - fVar2;
      if (iVar16 != 2) {
        light[2][0] = *vert - lightbonepos[bone][2][0];
        light[2][1] = vert[1] - lightbonepos[bone][2][1];
        fVar1 = vert[2];
        fVar2 = lightbonepos[bone][2][2];
        light[2][3] = 0.0;
        light[2][2] = fVar1 - fVar2;
      }
    }
  }
  return;
}


// R_LightVec  @ 00198f60
colorVec * R_LightVec(colorVec *__return_storage_ptr__,vec_t *start,vec_t *end)

{
  float fVar1;
  float fVar2;
  float fVar3;
  color24 *pcVar4;
  mnode_t *pmVar5;
  mplane_t *pmVar6;
  mtexinfo_t *pmVar7;
  float fVar8;
  float fVar9;
  bool bVar10;
  model_s *pmVar11;
  int iVar12;
  mnode_s *node;
  int iVar13;
  msurface_t *pmVar14;
  int iVar15;
  color24_conflict *pcVar16;
  color24_conflict *pcVar17;
  uint uVar18;
  uint local_50;
  float local_38;
  float local_34;
  float local_30;
  colorVec local_2c;
  
                    /* Unresolved local var: colorVec c@[???] */
  pmVar11 = cl.worldmodel;
  pcVar4 = (cl.worldmodel)->lightdata;
  __return_storage_ptr__->r = 0;
  __return_storage_ptr__->g = 0;
  __return_storage_ptr__->b = 0;
  __return_storage_ptr__->a = 0;
  if (pcVar4 == (color24 *)0x0) {
    __return_storage_ptr__->r = 0xff;
    __return_storage_ptr__->g = 0xff;
    __return_storage_ptr__->b = 0xff;
    return __return_storage_ptr__;
  }
  pmVar5 = pmVar11->nodes;
                    /* Unresolved local var: colorVec c@[???]
                       Unresolved local var: float front@[???]
                       Unresolved local var: float back@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: vec3_t mid@[???]
                       Unresolved local var: msurface_t * surf@[???]
                       Unresolved local var: int s@[???]
                       Unresolved local var: int t@[???]
                       Unresolved local var: int ds@[???]
                       Unresolved local var: int dt@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: mtexinfo_t * tex@[???]
                       Unresolved local var: color24 * lightmap@[???]
                       Unresolved local var: uint scale@[???]
                       Unresolved local var: int maps@[???] */
  local_2c.r = 0;
  local_2c.g = 0;
  local_2c.b = 0;
  local_2c.a = 0;
  if (pmVar5->contents < 0) {
    __return_storage_ptr__->r = 0;
    local_2c.b = 0;
    local_2c.g = 0;
    __return_storage_ptr__->g = 0;
    local_2c.r = 0;
    __return_storage_ptr__->b = 0;
    __return_storage_ptr__->a = 0;
  }
  else {
    pmVar6 = pmVar5->plane;
    fVar1 = *start;
    fVar2 = start[1];
    fVar3 = start[2];
    fVar8 = (pmVar6->normal[2] * fVar3 + pmVar6->normal[1] * fVar2 + pmVar6->normal[0] * fVar1) -
            pmVar6->dist;
    fVar9 = (end[2] * pmVar6->normal[2] + pmVar6->normal[1] * end[1] + pmVar6->normal[0] * *end) -
            pmVar6->dist;
    bVar10 = fVar8 < 0.0;
    if (fVar9 < 0.0 == bVar10) {
      node = pmVar5->children[bVar10];
    }
    else {
      fVar8 = fVar8 / (fVar8 - fVar9);
      local_38 = (*end - fVar1) * fVar8 + fVar1;
      local_34 = (end[1] - fVar2) * fVar8 + fVar2;
                    /* catch() { ... } // from try @ 00198eb1 with catch @ 00199061 */
      local_30 = fVar3 + (end[2] - fVar3) * fVar8;
      RecursiveLightPoint(&local_2c,pmVar5->children[bVar10],start,&local_38);
                    /* try { // try from 0019907d to 001a9081 has its CatchHandler @ 00198df0 */
                    /* catch() { ... } // from try @ 00199315 with catch @ 00199090 */
      if ((local_2c.g != 0 || local_2c.r != 0) || local_2c.b != 0) {
        __return_storage_ptr__->r = local_2c.r;
        __return_storage_ptr__->b = local_2c.b;
        __return_storage_ptr__->g = local_2c.g;
        __return_storage_ptr__->a = local_2c.a;
        goto LAB_001992d7;
      }
      lightspot[0] = local_38;
      lightspot[1] = local_34;
      lightspot[2] = local_30;
      pmVar14 = (cl.worldmodel)->surfaces + pmVar5->firstsurface;
      lightplane = pmVar6;
      if (pmVar5->numsurfaces != 0) {
        uVar18 = 0;
        do {
          if ((pmVar14->flags & 0x20) == 0) {
            pmVar7 = pmVar14->texinfo;
            iVar12 = (int)(pmVar7->vecs[0][2] * local_30 +
                           pmVar7->vecs[0][1] * local_34 + pmVar7->vecs[0][0] * local_38 +
                          pmVar7->vecs[0][3]);
            if (pmVar14->texturemins[0] <= iVar12) {
              iVar13 = (int)(pmVar7->vecs[1][2] * local_30 +
                             pmVar7->vecs[1][1] * local_34 + pmVar7->vecs[1][0] * local_38 +
                            pmVar7->vecs[1][3]);
              if (pmVar14->texturemins[1] <= iVar13) {
                iVar12 = iVar12 - pmVar14->texturemins[0];
                if (iVar12 <= pmVar14->extents[0]) {
                  iVar13 = iVar13 - pmVar14->texturemins[1];
                    /* try { // try from 00199176 to 001a917a has its CatchHandler @ 0019931a */
                  if (iVar13 <= pmVar14->extents[1]) {
                    if (pmVar14->samples == (color24_conflict *)0x0) {
                      __return_storage_ptr__->r = local_2c.r;
                      __return_storage_ptr__->g = local_2c.g;
                      __return_storage_ptr__->b = local_2c.b;
                      __return_storage_ptr__->a = local_2c.a;
                      local_2c.b = 0;
                    }
                    else {
                      iVar15 = ((int)pmVar14->extents[0] >> 4) + 1;
                      pcVar16 = pmVar14->samples + (iVar12 >> 4) + (iVar13 >> 4) * iVar15;
                      iVar15 = iVar15 * (((int)pmVar14->extents[1] >> 4) + 1);
                      if (pmVar14->styles[0] == 0xff) {
                        local_2c.b = 0;
                        local_2c.g = 0;
                        local_2c.r = 1;
                      }
                      else {
                        iVar12 = d_lightstylevalue[pmVar14->styles[0]];
                        local_50 = (uint)pcVar16->r * iVar12;
                        local_2c.g = (uint)pcVar16->g * iVar12;
                        pcVar17 = pcVar16 + iVar15;
                        local_2c.b = iVar12 * (uint)pcVar16->b;
                    /* try { // try from 00199205 to 001a9209 has its CatchHandler @ 001992f9 */
                        if (pmVar14->styles[1] != 0xff) {
                          iVar12 = d_lightstylevalue[pmVar14->styles[1]];
                          local_50 = local_50 + (uint)pcVar17->r * iVar12;
                          local_2c.g = local_2c.g + (uint)pcVar17->g * iVar12;
                          local_2c.b = local_2c.b + iVar12 * (uint)pcVar17->b;
                          pcVar17 = pcVar17 + iVar15;
                          if (pmVar14->styles[2] != 0xff) {
                            iVar12 = d_lightstylevalue[pmVar14->styles[2]];
                            local_50 = local_50 + (uint)pcVar17->r * iVar12;
                            local_2c.g = local_2c.g + (uint)pcVar17->g * iVar12;
                            local_2c.b = local_2c.b + iVar12 * (uint)pcVar17->b;
                            pcVar17 = pcVar17 + iVar15;
                            if (pmVar14->styles[3] != 0xff) {
                              iVar12 = d_lightstylevalue[pmVar14->styles[3]];
                              local_50 = local_50 + (uint)pcVar17->r * iVar12;
                              local_2c.g = local_2c.g + (uint)pcVar17->g * iVar12;
                              local_2c.b = local_2c.b + iVar12 * (uint)pcVar17->b;
                            }
                          }
                        }
                        local_2c.g = local_2c.g >> 8;
                        local_2c.b = local_2c.b >> 8;
                        local_2c.r = local_50 >> 8;
                        if (local_2c.r == 0) {
                          local_2c.r = 1;
                        }
                      }
                      __return_storage_ptr__->r = local_2c.r;
                      __return_storage_ptr__->g = local_2c.g;
                      __return_storage_ptr__->b = local_2c.b;
                      __return_storage_ptr__->a = local_2c.a;
                    }
                    goto LAB_001992d7;
                  }
                }
              }
            }
          }
          uVar18 = uVar18 + 1;
          pmVar14 = pmVar14 + 1;
        } while (uVar18 != pmVar5->numsurfaces);
      }
      start = &local_38;
                    /* catch() { ... } // from try @ 0019974c with catch @ 001993a0 */
      node = pmVar5->children[!bVar10];
    }
    RecursiveLightPoint(__return_storage_ptr__,node,start,end);
    local_2c.r = __return_storage_ptr__->r;
    local_2c.g = __return_storage_ptr__->g;
    local_2c.b = __return_storage_ptr__->b;
  }
LAB_001992d7:
  local_2c.r = local_2c.r + r_refdef.ambientlight.r;
  local_2c.g = local_2c.g + r_refdef.ambientlight.g;
  local_2c.b = local_2c.b + r_refdef.ambientlight.b;
                    /* catch() { ... } // from try @ 00199205 with catch @ 001992f9 */
  if (0xff < local_2c.r) {
    local_2c.r = 0xff;
  }
  if (0xff < local_2c.g) {
    local_2c.g = 0xff;
  }
  if (0xff < local_2c.b) {
    local_2c.b = 0xff;
  }
  __return_storage_ptr__->b = local_2c.b;
                    /* try { // try from 00199315 to 001a9319 has its CatchHandler @ 00199090 */
  __return_storage_ptr__->r = local_2c.r;
                    /* catch() { ... } // from try @ 00199176 with catch @ 0019931a */
  __return_storage_ptr__->g = local_2c.g;
  return __return_storage_ptr__;
}


// R_LoadFragmentOnlyProgram  @ 0018f4e0
GLuint R_LoadFragmentOnlyProgram(char *filename,char *pExtra)

{
  bool bVar1;
  GLuint GVar2;
  GLuint program;
  GLuint GVar3;
  
                    /* Unresolved local var: GLuint fs@[???] */
  GVar2 = R_CreateShader(filename,0x8b30,pExtra);
  if (GVar2 == 0) {
    return 0;
  }
                    /* Unresolved local var: GLuint program@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: GLuint prog@[???] */
  program = (*qglCreateProgram)();
  (*qglAttachShader)(program,GVar2);
  (*qglLinkProgram)(program);
  bVar1 = R_CheckProgram(program);
  GVar3 = program;
  if (!bVar1) {
    GVar3 = 0;
    (*qglDeleteProgram)(program);
  }
  (*qglDeleteShader)(GVar2);
  return GVar3;
}


// R_LoadMapSprite  @ 0017f8d0
model_t * R_LoadMapSprite(char *szFilename)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  model_t *mod;
  int iVar8;
  FileHandle_t hFile;
  qboolean qVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  uint uVar13;
  uint uVar14;
  byte *pbVar15;
  byte *pbVar16;
  int iVar17;
  int in_GS_OFFSET;
  char *fmt;
  char *pcVar18;
  byte *local_168;
  byte *local_164;
  byte *local_160;
  int local_15c;
  int local_158;
  byte *local_154;
  int local_150;
  int local_14c;
  char *local_140 [2];
  uint local_138;
  uint local_134;
  int local_130;
  byte *local_12c;
  undefined4 local_128;
  char local_124 [259];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: char[260] filename@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int width@[???]
                       Unresolved local var: int height@[???]
                       Unresolved local var: int palCount@[???]
                       Unresolved local var: int xStep@[???]
                       Unresolved local var: int yStep@[???]
                       Unresolved local var: uint * yStart1@[???]
                       Unresolved local var: uint * yStart2@[???]
                       Unresolved local var: model_t * mod@[???]
                       Unresolved local var: int colorBytes@[???]
                       Unresolved local var: byte * buffer1@[???]
                       Unresolved local var: byte * buffer2@[???]
                       Unresolved local var: byte * buffer3@[???] */
  local_140[0] = szFilename;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_12c = (byte *)0x0;
  (*g_engdstAddrs.LoadMapSprite)(local_140);
  Q_strncpy(local_124,local_140[0],0x103);
  local_21 = 0;
  Q_strlwr(local_124);
  mod = Mod_FindName(false,local_124);
  mod->needload = false;
  iVar8 = Q_strlen(local_124);
  iVar8 = Q_strcmp("tga",local_124 + iVar8 + -3);
  if (iVar8 == 0) {
    local_154 = Mem_Malloc(0x300000);
    if (local_154 == (byte *)0x0) goto LAB_0017feb9;
    qVar9 = LoadTGA(local_124,local_154,0x300000,(int *)&local_138,(int *)&local_134);
    if (qVar9 == false) {
      fmt = "Couldn\'t open %s\n";
      pcVar18 = local_140[0];
    }
    else {
      iVar8 = 0;
      iVar17 = local_134 * local_138;
      if (0 < iVar17) {
        do {
          if (((local_154[iVar8 * 4] == '\0') && (local_154[iVar8 * 4 + 1] == 0xff)) &&
             (local_154[iVar8 * 4 + 2] == '\0')) {
            pbVar16 = local_154 + iVar8 * 4;
            pbVar16[0] = '\0';
            pbVar16[1] = '\0';
            pbVar16[2] = '\0';
            pbVar16[3] = '\0';
          }
          iVar8 = iVar8 + 1;
          iVar17 = local_138 * local_134;
        } while (iVar17 - iVar8 != 0 && iVar8 <= iVar17);
      }
LAB_0017fb11:
      if ((iVar17 != 0) && (((local_134 | local_138) & 0x7f) == 0)) {
        pbVar16 = Mem_Malloc(0x300000);
        if (pbVar16 == (byte *)0x0) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("Not enough memory to load map images (2).\n");
        }
        if (0 < (int)local_134) {
          local_150 = 0;
          local_160 = pbVar16;
          do {
            local_14c = 0;
            if (0 < (int)local_138) {
              do {
                pbVar1 = local_160 + 0x10000;
                pbVar15 = local_154 + (local_138 * local_150 + local_14c) * 4;
                do {
                  if ((local_160 < pbVar15 + 0x10) && (pbVar15 < local_160 + 0x10)) {
                    iVar8 = 0;
                    do {
                      *(undefined4 *)(local_160 + iVar8) = *(undefined4 *)(pbVar15 + iVar8);
                      iVar8 = iVar8 + 4;
                    } while (iVar8 != 0x200);
                  }
                  else {
                    uVar10 = -(((uint)pbVar15 & 0xf) >> 2) & 3;
                    if (uVar10 == 0) {
                      local_15c = 0x80;
                      uVar14 = 0x20;
                      iVar8 = 0x80;
                      local_158 = 0x80;
                      local_168 = local_160;
                      local_164 = pbVar15;
                    }
                    else {
                      local_168 = local_160 + 4;
                      local_164 = pbVar15 + 4;
                      *(undefined4 *)local_160 = *(undefined4 *)pbVar15;
                      if (uVar10 == 1) {
                        local_15c = 0x7f;
                      }
                      else {
                        local_168 = local_160 + 8;
                        local_164 = pbVar15 + 8;
                        *(undefined4 *)(local_160 + 4) = *(undefined4 *)(pbVar15 + 4);
                        if (uVar10 == 3) {
                          local_168 = local_160 + 0xc;
                          local_164 = pbVar15 + 0xc;
                          local_15c = 0x7d;
                          *(undefined4 *)(local_160 + 8) = *(undefined4 *)(pbVar15 + 8);
                        }
                        else {
                          local_15c = 0x7e;
                        }
                      }
                      uVar14 = 0x1f;
                      local_158 = 0x80 - uVar10;
                      iVar8 = 0x7c;
                    }
                    uVar13 = 0;
                    pbVar12 = pbVar15 + uVar10 * 4;
                    pbVar11 = local_160 + uVar10 * 4;
                    do {
                      uVar13 = uVar13 + 1;
                      uVar5 = *(undefined4 *)(pbVar12 + 4);
                      uVar6 = *(undefined4 *)(pbVar12 + 8);
                      uVar7 = *(undefined4 *)(pbVar12 + 0xc);
                      *(undefined4 *)pbVar11 = *(undefined4 *)pbVar12;
                      *(undefined4 *)(pbVar11 + 4) = uVar5;
                      *(undefined4 *)(pbVar11 + 8) = uVar6;
                      *(undefined4 *)(pbVar11 + 0xc) = uVar7;
                      pbVar12 = pbVar12 + 0x10;
                      pbVar11 = pbVar11 + 0x10;
                    } while (uVar13 < uVar14);
                    local_164 = local_164 + iVar8 * 4;
                    local_168 = local_168 + iVar8 * 4;
                    if (((iVar8 != local_158) &&
                        (*(undefined4 *)local_168 = *(undefined4 *)local_164, local_15c - iVar8 != 1
                        )) && (*(undefined4 *)(local_168 + 4) = *(undefined4 *)(local_164 + 4),
                              local_15c - iVar8 != 2)) {
                      *(undefined4 *)(local_168 + 8) = *(undefined4 *)(local_164 + 8);
                    }
                  }
                  local_160 = local_160 + 0x200;
                  pbVar15 = pbVar15 + local_138 * 4;
                } while (local_160 != pbVar1);
                local_14c = local_14c + 0x80;
                local_160 = pbVar1;
              } while (local_14c < (int)local_138);
            }
            local_150 = local_150 + 0x80;
          } while (local_150 < (int)local_134);
        }
        if ((int)local_134 < 0) {
          local_134 = local_134 + 0x7f;
        }
        if ((int)local_138 < 0) {
          local_138 = local_138 + 0x7f;
        }
        R_LoadOverviewSpriteModel(mod,pbVar16,(int)local_138 >> 7,(int)local_134 >> 7);
        Mem_Free(local_154);
        Mem_Free(pbVar16);
        goto LAB_0017fdac;
      }
      fmt = "Wrong map image dimensions or file could not be loaded in %s\n";
      pcVar18 = local_124;
    }
    Con_Printf(fmt,pcVar18);
    Mem_Free(local_154);
    Mem_Free((void *)0x0);
    mod = (model_t *)0x0;
  }
  else {
    iVar8 = Q_strlen(local_124);
    iVar8 = Q_strcmp("bmp",local_124 + iVar8 + -3);
    if (iVar8 != 0) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Unsupported map image file format.\n");
    }
    local_154 = Mem_Malloc(0x300000);
    if (local_154 == (byte *)0x0) {
LAB_0017feb9:
                    /* WARNING: Subroutine does not return */
      Sys_Error("Not enough memory to load map images (1).\n");
    }
                    /* Unresolved local var: FileHandle_t hFile@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: byte * packPalette@[???] */
    local_128 = (byte *)0x0;
    hFile = FS_Open(local_124,"rb");
    if (hFile == (FileHandle_t)0x0) {
      Con_Printf("Couldn\'t open %s\n",local_124);
      Mem_Free(local_154);
      Mem_Free((void *)0x0);
    }
    else {
      LoadBMP8(hFile,(byte **)&local_128,&local_130,&local_12c,(int *)&local_138,(int *)&local_134);
      if ((local_12c != (byte *)0x0) && (local_128 != (byte *)0x0)) {
        if (0 < (int)(local_138 * local_134)) {
          iVar8 = 0;
          pbVar16 = local_154;
          do {
            iVar17 = (uint)local_12c[iVar8] * 3;
            bVar2 = local_128[iVar17];
            *pbVar16 = bVar2;
            bVar3 = local_128[iVar17 + 1];
            pbVar16[1] = bVar3;
            bVar4 = local_128[iVar17 + 2];
            pbVar16[2] = bVar4;
            if ((bVar3 == 0xff && bVar4 == '\0') && (bVar2 == '\0')) {
              pbVar16[0] = '\0';
              pbVar16[1] = '\0';
              pbVar16[2] = '\0';
              pbVar16[3] = '\0';
            }
            else {
              pbVar16[3] = 0xff;
            }
            iVar8 = iVar8 + 1;
            pbVar16 = pbVar16 + 4;
          } while (local_138 * local_134 - iVar8 != 0 && iVar8 <= (int)(local_138 * local_134));
        }
        Mem_Free(local_12c);
        Mem_Free(local_128);
        iVar17 = local_138 * local_134;
        goto LAB_0017fb11;
      }
      Con_Printf("Error loading %s\n",local_124);
      Mem_Free(local_154);
      Mem_Free((void *)0x0);
      if (local_12c != (byte *)0x0) {
        Mem_Free(local_12c);
      }
      if (local_128 != (byte *)0x0) {
        Mem_Free(local_128);
      }
    }
    mod = (model_t *)0x0;
  }
LAB_0017fdac:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return mod;
}


// R_LoadOverviewSpriteModel  @ 0017f680
void R_LoadOverviewSpriteModel(model_t *mod,byte *pdata,int XTiles,int yTiles)

{
  int iVar1;
  undefined2 *puVar2;
  undefined4 *dest;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_GS_OFFSET;
  byte *local_138;
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: mspriteframe_t * pspriteframe@[???]
                       Unresolved local var: int width@[???]
                       Unresolved local var: int height@[???]
                       Unresolved local var: int[2] origin@[???]
                       Unresolved local var: int textureType@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: int numframes@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: msprite_t * psprite@[???] */
  local_138 = pdata;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = yTiles * XTiles;
  puVar2 = Hunk_AllocName(iVar1 * 8 + 0x1c,mod->name);
  (mod->cache).data = puVar2;
  *(undefined4 *)(puVar2 + 2) = 0x80;
  *(undefined4 *)(puVar2 + 4) = 0x80;
  *puVar2 = 4;
  puVar2[1] = 3;
  *(undefined4 *)(puVar2 + 10) = 0;
  mod->synctype = ST_SYNC;
  iVar3 = *(int *)(puVar2 + 2);
  *(int *)(puVar2 + 6) = iVar1;
  mod->mins[1] = (float)-(iVar3 / 2);
  mod->mins[0] = (float)-(iVar3 / 2);
  iVar3 = *(int *)(puVar2 + 2);
  mod->maxs[1] = (float)(iVar3 / 2);
  mod->maxs[0] = (float)(iVar3 / 2);
  mod->mins[2] = (float)-(*(int *)(puVar2 + 4) / 2);
  iVar3 = *(int *)(puVar2 + 4);
  mod->numframes = iVar1;
  mod->flags = 0;
  mod->maxs[2] = (float)(iVar3 / 2);
  if (0 < iVar1) {
    iVar3 = 0;
    puVar5 = (undefined4 *)(puVar2 + 0xe);
    do {
      *puVar5 = 0;
      dest = Hunk_AllocName(0x1c,mod->name);
      Q_memset(dest,0,0x1c);
      puVar5[1] = dest;
      *dest = 0x80;
      dest[1] = 0x80;
      dest[2] = 0;
      dest[3] = 0xc3000000;
      dest[4] = 0;
      dest[5] = 0x43000000;
      iVar4 = iVar3 + 1;
      Mod_SpriteTextureName(local_120,0x100,mod->name,iVar3);
      iVar3 = GL_LoadTexture(local_120,GLT_SPRITE,0x80,0x80,local_138,0,4,(byte *)0x0);
      dest[6] = iVar3;
      (*qglTexParameterf)(0xde1,0x2802,10496.0);
      (*qglTexParameterf)(0xde1,0x2803,10496.0);
      local_138 = local_138 + 0x10000;
      iVar3 = iVar4;
      puVar5 = puVar5 + 2;
    } while (iVar1 != iVar4);
  }
  iVar3 = *(int *)(in_GS_OFFSET + 0x14);
  mod->type = mod_sprite;
  if (local_20 == iVar3) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// R_LoadShaders  @ 0018f260
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_LoadShaders(void)

{
  GLuint GVar1;
  GLint GVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int in_GS_OFFSET;
  char local_90 [128];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((qglCompileShader == (_func_void_GLuint *)0x0) ||
     (g_bHasShaderFunctions = true, g_bTriedToCreateWorldShader != false)) {
LAB_0018f351:
    if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  iVar5 = 0;
  while( true ) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[128] defineBuffer@[???] */
    __snprintf_chk(local_90,0x80,1,0x80,"#version 420 compatibility\n#define TEXTURE_MASK %d\n",
                   iVar5);
    GVar1 = R_LoadVertexAndFragmentProgram
                      ("gl_shaders/vs_world.vert","gl_shaders/fs_world.frag",local_90);
    g_fsWorldProgram[iVar5] = GVar1;
    if (GVar1 == 0) break;
    GVar2 = (*qglGetUniformLocation)(GVar1,"fogEnabled");
    g_nFogEnabledUniformLocation[iVar5] = GVar2;
    GVar2 = (*qglGetUniformLocation)(g_fsWorldProgram[iVar5],"fogMode");
    g_nFogModeUniformLocation[iVar5] = GVar2;
    iVar5 = iVar5 + 1;
    if (iVar5 == 8) goto LAB_0018f347;
  }
                    /* Unresolved local var: int i@[???] */
  if (g_fsWorldProgram[0] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[0]);
    g_fsWorldProgram[0] = 0;
  }
  if (g_fsWorldProgram[1] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[1]);
    g_fsWorldProgram[1] = 0;
  }
  if (g_fsWorldProgram[2] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[2]);
    g_fsWorldProgram[2] = 0;
  }
  if (g_fsWorldProgram[3] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[3]);
    g_fsWorldProgram[3] = 0;
  }
  if (g_fsWorldProgram[4] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[4]);
    g_fsWorldProgram[4] = 0;
  }
  if (g_fsWorldProgram[5] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[5]);
    g_fsWorldProgram[5] = 0;
  }
  if (g_fsWorldProgram[6] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[6]);
    g_fsWorldProgram[6] = 0;
  }
  if (g_fsWorldProgram[7] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[7]);
    g_fsWorldProgram[7] = 0;
  }
  uVar4 = 0;
  do {
    *(undefined4 *)((int)g_nFogEnabledUniformLocation + uVar4) = 0xffffffff;
    uVar3 = uVar4 + 8;
    *(undefined4 *)((int)g_nFogEnabledUniformLocation + uVar4 + 4) = 0xffffffff;
    uVar4 = uVar3;
  } while (uVar3 < 0x20);
  uVar4 = 0;
  do {
    *(undefined4 *)((int)g_nFogModeUniformLocation + uVar4) = 0xffffffff;
    uVar3 = uVar4 + 8;
    *(undefined4 *)((int)g_nFogModeUniformLocation + uVar4 + 4) = 0xffffffff;
    uVar4 = uVar3;
  } while (uVar3 < 0x20);
LAB_0018f347:
  g_bTriedToCreateWorldShader = true;
  goto LAB_0018f351;
}


// R_LoadShaders  @ 0018f700
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_LoadShaders(void)

{
  qboolean qVar1;
  
  qVar1 = R_UseLegacyRender();
  if ((((((qVar1 == 0) && (qglCreateShader != (_func_GLuint_GLenum *)0x0)) &&
        (qglDeleteShader != (_func_void_GLuint *)0x0)) &&
       ((qglShaderSource != (_func_void_GLuint_GLsizei_GLchar_ptr_ptr_GLint_ptr *)0x0 &&
        (qglGetProgramiv != (_func_void_GLuint_GLenum_GLint_ptr *)0x0)))) &&
      ((qglGetProgramInfoLog != (_func_void_GLuint_GLsizei_GLsizei_ptr_GLchar_ptr *)0x0 &&
       ((qglAttachShader != (_func_void_GLuint_GLuint *)0x0 &&
        (qglLinkProgram != (_func_void_GLuint *)0x0)))))) &&
     ((qglCreateProgram != (_func_GLuint *)0x0 &&
      ((qglDeleteProgram != (_func_void_GLuint *)0x0 && (qglUseProgram != (_func_void_GLuint *)0x0))
      )))) {
    R_LoadShaders();
    return;
  }
  return;
}


// R_LoadSkys  @ 0018cb10
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_LoadSkys(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  ushort uVar4;
  byte *buffer;
  qboolean qVar5;
  byte *pbVar6;
  FileHandle_t hFile;
  int iVar7;
  byte bVar8;
  int iVar9;
  int in_GS_OFFSET;
  char *pcVar10;
  char *pcVar11;
  int local_80;
  int local_7c;
  int local_78;
  byte *local_74;
  byte *local_70;
  int local_6c;
  int local_68;
  int local_64;
  char local_60 [64];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int skipBMP@[???]
                       Unresolved local var: char[64] name@[???]
                       Unresolved local var: byte * buffer@[???]
                       Unresolved local var: qboolean printed@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (gLoadSky == 0) {
    if (gSkyTexNumber[0] != 0) {
      (*qglDeleteTextures)(1,(GLuint *)gSkyTexNumber);
      gSkyTexNumber[0] = 0;
    }
    if (gSkyTexNumber[1] != 0) {
      (*qglDeleteTextures)(1,(GLuint *)(gSkyTexNumber + 1));
    }
    gSkyTexNumber[1] = 0;
    if (gSkyTexNumber[2] != 0) {
      (*qglDeleteTextures)(1,(GLuint *)(gSkyTexNumber + 2));
    }
    gSkyTexNumber[2] = 0;
    if (gSkyTexNumber[3] != 0) {
      (*qglDeleteTextures)(1,(GLuint *)(gSkyTexNumber + 3));
    }
    gSkyTexNumber[3] = 0;
    if (gSkyTexNumber[4] != 0) {
      (*qglDeleteTextures)(1,(GLuint *)(gSkyTexNumber + 4));
    }
    gSkyTexNumber[4] = 0;
    if (gSkyTexNumber[5] != 0) {
      (*qglDeleteTextures)(1,(GLuint *)(gSkyTexNumber + 5));
      gSkyTexNumber[5] = 0;
    }
LAB_0018cb82:
    if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  if ((qglColorTableEXT == (_func_void_int_int_int_int_int_void_ptr *)0x0) ||
     (gl_palette_tex.value == 0.0)) {
    bVar2 = true;
  }
  else {
    GL_PaletteClearSky();
    bVar2 = false;
  }
  buffer = Mem_Malloc(0x40000);
  bVar3 = false;
LAB_0018cbec:
  iVar9 = 0;
  do {
                    /* Unresolved local var: int loadedBMP@[???]
                       Unresolved local var: int palCount@[???]
                       Unresolved local var: int bmpWidth@[???]
                       Unresolved local var: int bmpHeight@[???]
                       Unresolved local var: int paletteIndex@[???]
                       Unresolved local var: byte * packPalette@[???]
                       Unresolved local var: byte * pImage@[???]
                       Unresolved local var: FileHandle_t hFile@[???] */
    __snprintf_chk(local_60,0x40,1,0x40,"gfx/env/%s%s.bmp",0x95d984,suf[iVar9]);
    if (((bVar2) || (hFile = FS_Open(local_60,"rb"), hFile == (FileHandle_t)0x0)) ||
       (LoadBMP8(hFile,&local_74,&local_80,&local_70,&local_7c,&local_78), local_7c * local_78 < 1))
    {
LAB_0018cc3c:
                    /* Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int bpp@[???] */
      __snprintf_chk(local_60,0x40,1,0x40,"gfx/env/%s%s.tga",0x95d984,suf[iVar9]);
      pcVar11 = "G2\x13";
      qVar5 = LoadTGA2(local_60,buffer,0x40000,(int *)0x0,(int *)0x0,0);
      if (qVar5 == false) {
        pcVar10 = local_60;
        Con_Printf("R_LoadSkys: Couldn\'t load %s\n",local_60);
        if (iVar9 == 0) {
          pcVar10 = "desert";
          iVar7 = Q_strcmp(movevars.skyName,"desert");
          if (iVar7 != 0) break;
        }
        bVar2 = true;
      }
      else {
        pbVar6 = buffer;
        if (gl_dither.value != 0.0) {
          do {
            bVar8 = *pbVar6;
            if (bVar8 < 0xfc) {
              bVar8 = bVar8 | bVar8 >> 6;
              *pbVar6 = bVar8;
              *pbVar6 = texgammatable[bVar8];
            }
            bVar8 = pbVar6[1];
            if (bVar8 < 0xfc) {
              bVar8 = bVar8 | bVar8 >> 6;
              pbVar6[1] = bVar8;
              pbVar6[1] = texgammatable[bVar8];
            }
            bVar8 = pbVar6[2];
            if (bVar8 < 0xfc) {
              bVar8 = bVar8 | bVar8 >> 6;
              pbVar6[2] = bVar8;
              pbVar6[2] = texgammatable[bVar8];
            }
            pbVar6 = pbVar6 + 4;
          } while (pbVar6 != buffer + 0x40000);
        }
        iVar7 = gSkyTexNumber[iVar9];
        if (iVar7 == 0) {
          iVar7 = GL_GenTexture();
          gSkyTexNumber[iVar9] = iVar7;
        }
        GL_Bind(iVar7);
        VideoMode_GetCurrentVideoMode(&local_6c,&local_68,&local_64);
        if (local_64 == 0x20) {
          (*qglTexImage2D)(0xde1,0,0x8058,0x100,0x100,0,0x1908,0x1401,buffer);
        }
        else {
          (*qglTexImage2D)(0xde1,0,0x8057,0x100,0x100,0,0x1908,0x1401,buffer);
        }
        (*qglTexParameterf)(0xde1,0x2801,9729.0);
        (*qglTexParameterf)(0xde1,0x2800,9729.0);
        if (!bVar3) {
          bVar1 = false;
          bVar2 = true;
          goto LAB_0018d1ac;
        }
        bVar2 = true;
LAB_0018ce00:
        pcVar11 = suf[iVar9];
        pcVar10 = movevars.skyName;
        Con_DPrintf("%s%s, ",0x95d984,pcVar11);
      }
    }
    else {
      uVar4 = GL_PaletteAdd(local_74,true);
      if ((uVar4 & 0x8000) != 0) {
        Mem_Free(local_70);
        Mem_Free(local_74);
        goto LAB_0018cc3c;
      }
      iVar7 = gSkyTexNumber[iVar9];
      if (iVar7 == 0) {
        iVar7 = GL_GenTexture();
        gSkyTexNumber[iVar9] = iVar7;
      }
      GL_Bind(iVar7);
      (*qglTexImage2D)(0xde1,0,0x80e5,0x100,0x100,0,0x1900,0x1401,local_70);
      Mem_Free(local_70);
      Mem_Free(local_74);
      (*qglTexParameterf)(0xde1,0x2801,9729.0);
      (*qglTexParameterf)(0xde1,0x2800,9729.0);
      if (!bVar3) {
        bVar1 = true;
LAB_0018d1ac:
        Con_DPrintf("SKY:  ");
        bVar3 = true;
        if (!bVar1) goto LAB_0018ce00;
      }
      pcVar11 = suf[iVar9];
      pcVar10 = movevars.skyName;
      Con_DPrintf("%s%s - paletted, ",0x95d984,pcVar11);
    }
    iVar9 = iVar9 + 1;
    if (iVar9 == 6) {
      if (bVar3) {
        Con_DPrintf("done\n",pcVar10,pcVar11);
      }
      Mem_Free(buffer);
      gLoadSky = 0;
      goto LAB_0018cb82;
    }
  } while( true );
  Q_strcpy(movevars.skyName,"desert");
  bVar2 = true;
  goto LAB_0018cbec;
}


// R_LoadTextures  @ 000d73e0
studiohdr_t * __regparm3 R_LoadTextures(model_t *psubmodel)

{
  void *pvVar1;
  int iVar2;
  model_t *pmVar3;
  int in_GS_OFFSET;
  char acStack_118 [4];
  char local_114 [258];
  undefined1 local_12;
  int local_10;
  
                    /* Unresolved local var: model_t * texmodel@[???] */
  pmVar3 = (model_t *)psubmodel->texinfo;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (pmVar3 != (model_t *)0x0) {
    pvVar1 = Cache_Check(&pmVar3->cache);
    if (pvVar1 != (void *)0x0) goto LAB_000d7428;
  }
                    /* Unresolved local var: studiohdr_t * ptexturehdr@[???]
                       Unresolved local var: char[260] modelname@[???] */
  Q_strncpy(local_114,psubmodel->name,0x102);
  local_12 = 0;
  iVar2 = Q_strlen(local_114);
  Q_strcpy(acStack_118 + iVar2,"T.mdl");
  pmVar3 = Mod_ForName(local_114,true,false);
  psubmodel->texinfo = (mtexinfo_t *)pmVar3;
  pvVar1 = (pmVar3->cache).data;
  Q_strncpy((char *)((int)pvVar1 + 8),local_114,0x3f);
  *(undefined1 *)((int)pvVar1 + 0x47) = 0;
LAB_000d7428:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (pmVar3->cache).data;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// R_LoadTextures  @ 000de160
studiohdr_t * R_LoadTextures(model_t *psubmodel)

{
  studiohdr_t *psVar1;
  
                    /* Unresolved local var: model_t * texmodel@[???] */
  if (pstudiohdr->textureindex == 0) {
    psVar1 = R_LoadTextures(psubmodel);
    return psVar1;
  }
  return pstudiohdr;
}


// R_LoadVertexAndFragmentProgram  @ 0018f180
GLuint R_LoadVertexAndFragmentProgram(char *vertexFilename,char *fragmentFilename,char *pExtra)

{
  bool bVar1;
  GLuint GVar2;
  GLuint GVar3;
  GLuint program;
  GLuint GVar4;
  
                    /* Unresolved local var: GLuint[2] shaders@[???] */
  GVar2 = R_CreateShader(vertexFilename,0x8b31,pExtra);
  GVar3 = R_CreateShader(fragmentFilename,0x8b30,pExtra);
  GVar4 = GVar3;
  if (GVar2 == 0) {
    if (GVar3 != 0) {
      GVar4 = 0;
      (*qglDeleteShader)(GVar3);
    }
  }
  else if (GVar3 == 0) {
    (*qglDeleteShader)(GVar2);
  }
  else {
                    /* Unresolved local var: GLuint program@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: GLuint prog@[???] */
    program = (*qglCreateProgram)();
    (*qglAttachShader)(program,GVar2);
    (*qglAttachShader)(program,GVar3);
    (*qglLinkProgram)(program);
    bVar1 = R_CheckProgram(program);
    GVar4 = program;
    if (!bVar1) {
      GVar4 = 0;
      (*qglDeleteProgram)(program);
    }
    (*qglDeleteShader)(GVar2);
    (*qglDeleteShader)(GVar3);
  }
  return GVar4;
}


// R_LookupColor  @ 001a21f0
short R_LookupColor(uchar r,uchar g,uchar b)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int best@[???]
                       Unresolved local var: float diff@[???]
                       Unresolved local var: float bestdiff@[???]
                       Unresolved local var: float rf@[???]
                       Unresolved local var: float gf@[???]
                       Unresolved local var: float bf@[???] */
  iVar4 = 0;
  fVar1 = 999999.0;
  iVar3 = -1;
  do {
    fVar2 = (float)(int)((uint)b - (uint)host_basepal[iVar4 * 4]) * 0.2 *
            (float)(int)((uint)b - (uint)host_basepal[iVar4 * 4]) +
            (float)(int)((uint)g - (uint)host_basepal[iVar4 * 4 + 1]) * 0.5 *
            (float)(int)((uint)g - (uint)host_basepal[iVar4 * 4 + 1]) +
            (float)(int)((uint)r - (uint)host_basepal[iVar4 * 4 + 2]) * 0.3 *
            (float)(int)((uint)r - (uint)host_basepal[iVar4 * 4 + 2]);
    if (fVar2 < fVar1) {
      fVar1 = fVar2;
      iVar3 = iVar4;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0x100);
  return (short)iVar3;
}


// R_MarkLeaves  @ 00191bb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_MarkLeaves(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  model_s *pmVar5;
  int in_GS_OFFSET;
  byte *local_1030;
  byte local_1020 [4096];
  int local_20;
  
                    /* Unresolved local var: byte * vis@[???]
                       Unresolved local var: mnode_t * node@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: byte[4096] solid@[???] */
  iVar2 = r_visframecount;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (r_oldviewleaf == r_viewleaf) {
    if ((r_novis.value == 0.0) || (mirror != false)) goto LAB_00191c8b;
LAB_00191cc7:
    r_visframecount = iVar2 + 1;
    local_1030 = local_1020;
    Q_memset(local_1030,0xff,(cl.worldmodel)->numleafs + 7 >> 3);
  }
  else {
    if (mirror != false) goto LAB_00191c8b;
    r_visframecount = r_visframecount + 1;
    r_oldviewleaf = r_viewleaf;
    if (r_novis.value != 0.0) goto LAB_00191cc7;
    local_1030 = Mod_LeafPVS(r_viewleaf,cl.worldmodel);
  }
  iVar1 = r_visframecount;
  iVar2 = (cl.worldmodel)->numleafs;
  if (0 < iVar2) {
    iVar4 = 0x3c;
    iVar3 = 0;
    pmVar5 = cl.worldmodel;
    do {
      if (((int)(uint)local_1030[iVar3 >> 3] >> ((byte)iVar3 & 7) & 1U) != 0) {
        iVar2 = (int)pmVar5->leafs->minmaxs + iVar4 + -8;
        do {
          if (*(int *)(iVar2 + 4) == iVar1) break;
          *(int *)(iVar2 + 4) = iVar1;
          iVar2 = *(int *)(iVar2 + 0x20);
        } while (iVar2 != 0);
        iVar2 = (cl.worldmodel)->numleafs;
        pmVar5 = cl.worldmodel;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x3c;
    } while (iVar3 < iVar2);
  }
LAB_00191c8b:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// R_MarkLights  @ 001988f0
void R_MarkLights(dlight_t *light,int bit,mnode_t *node)

{
  float fVar1;
  mplane_t *pmVar2;
  mtexinfo_t *pmVar3;
  float fVar4;
  int iVar5;
  msurface_t *pmVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  do {
    iVar5 = r_dlightframecount;
    if (node->contents < 0) {
      return;
    }
    while( true ) {
      pmVar2 = node->plane;
      fVar4 = (light->origin[2] * pmVar2->normal[2] +
              light->origin[1] * pmVar2->normal[1] + light->origin[0] * pmVar2->normal[0]) -
              pmVar2->dist;
      fVar1 = light->radius;
      if (fVar4 <= fVar1) break;
      node = node->children[0];
      if (node->contents < 0) {
        return;
      }
    }
    if (-fVar1 <= fVar4) {
      uVar9 = (uint)node->numsurfaces;
      pmVar6 = (cl.worldmodel)->surfaces + node->firstsurface;
      if (uVar9 != 0) {
                    /* Unresolved local var: float rad@[???]
                       Unresolved local var: float minlight@[???]
                       Unresolved local var: int s@[???]
                       Unresolved local var: int t@[???]
                       Unresolved local var: int delta@[???]
                       Unresolved local var: int smax@[???]
                       Unresolved local var: int tmax@[???]
                       Unresolved local var: mtexinfo_t * tex@[???] */
        iVar8 = 0;
        while( true ) {
          if (light->minlight <= fVar1 - ABS(fVar4)) {
            pmVar3 = pmVar6->texinfo;
            iVar10 = (int)((light->origin[2] * pmVar3->vecs[0][2] +
                            light->origin[1] * pmVar3->vecs[0][1] +
                            light->origin[0] * pmVar3->vecs[0][0] + pmVar3->vecs[0][3]) -
                          (float)pmVar6->texturemins[0]);
            iVar11 = (int)((light->origin[2] * pmVar3->vecs[1][2] +
                            light->origin[1] * pmVar3->vecs[1][1] +
                            light->origin[0] * pmVar3->vecs[1][0] + pmVar3->vecs[1][3]) -
                          (float)pmVar6->texturemins[1]);
            iVar7 = (int)((fVar1 - ABS(fVar4)) - light->minlight);
            if ((((-iVar7 < iVar11) && (-iVar7 < iVar10)) && (iVar10 <= pmVar6->extents[0] + iVar7))
               && (iVar11 <= iVar7 + pmVar6->extents[1])) {
              if (pmVar6->dlightframe != iVar5) {
                pmVar6->dlightframe = iVar5;
              }
              pmVar6->dlightbits = pmVar6->dlightbits | bit;
              uVar9 = (uint)node->numsurfaces;
            }
          }
          iVar8 = iVar8 + 1;
          pmVar6 = pmVar6 + 1;
          if ((int)uVar9 <= iVar8) break;
          fVar1 = light->radius;
        }
      }
      R_MarkLights(light,bit,node->children[0]);
    }
    node = node->children[1];
  } while( true );
}


// R_MirrorChain  @ 001916e0
void R_MirrorChain(msurface_t *s)

{
  if (mirror == false) {
    mirror = true;
    mirror_plane = s->plane;
  }
  return;
}


// R_MultiGunshot  @ 0014f410
void R_MultiGunshot(vec_t *org,vec_t *dir,vec_t *noise,int count,int decalCount,int *decalIndices)

{
  int iVar1;
  _func_void_int_int_int_float_ptr_int *p_Var2;
  int32 iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  pmtrace_t local_10c;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  vec_t local_84 [3];
  vec_t local_78 [3];
  vec_t local_6c [3];
  float afStack_60 [12];
  int iStack_30;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float x@[???]
                       Unresolved local var: float y@[???]
                       Unresolved local var: float z@[???]
                       Unresolved local var: float temp@[???]
                       Unresolved local var: vec3_t vecDir@[???]
                       Unresolved local var: vec3_t vecEnd@[???]
                       Unresolved local var: vec3_t vecSpread1@[???]
                       Unresolved local var: vec3_t vecSpread2@[???]
                       Unresolved local var: vec3_t vecSpread@[???]
                       Unresolved local var: vec3_t vecUp@[???]
                       Unresolved local var: vec3_t vecRight@[???]
                       Unresolved local var: vec3_t angles@[???]
                       Unresolved local var: pmtrace_t pmtrace@[???]
                       Unresolved local var: int iDecal@[???] */
  VectorAngles(dir,local_6c);
  AngleVectors(local_6c,(vec_t *)0x0,local_78,local_84);
  if (0 < count) {
    uVar6 = 0;
    do {
      while( true ) {
        do {
          fVar7 = RandomFloat(-0.5,0.5);
          fVar8 = RandomFloat(-0.5,0.5);
          fVar7 = fVar7 + fVar8;
          fVar9 = RandomFloat(-0.5,0.5);
          fVar8 = RandomFloat(-0.5,0.5);
          fVar8 = fVar8 + fVar9;
        } while (1.0 < fVar8 * fVar8 + fVar7 * fVar7);
        iVar3 = RandomLong(0,decalCount + -1);
        VectorScale(local_78,fVar7 * *noise,&local_9c);
        VectorScale(local_84,fVar8 * noise[1],&local_90);
        local_b4 = local_9c + local_90 + *dir;
        local_b0 = local_98 + local_8c + dir[1];
        local_ac = local_94 + local_88 + dir[2];
        VectorScale(&local_b4,4096.0,&local_a8);
        local_a8 = local_a8 + *org;
        local_a4 = local_a4 + org[1];
        local_a0 = local_a0 + org[2];
        pmove->usehull = 2;
        PM_PlayerTrace(&local_10c,org,&local_a8,1,-1);
        uVar4 = 0;
        do {
          *(undefined4 *)((int)afStack_60 + uVar4) =
               *(undefined4 *)((int)local_10c.endpos + (uVar4 - 0x14));
          uVar4 = uVar4 + 4;
        } while (uVar4 < 0x44);
        if (afStack_60[4] != 1.0) break;
LAB_0014f6a0:
        uVar6 = uVar6 + 1;
        if (count == uVar6) {
          return;
        }
      }
      if ((uVar6 & 2) != 0) {
        (*efx.R_RicochetSound)(afStack_60 + 5);
      }
      (*efx.R_BulletImpactParticles)(afStack_60 + 5);
      p_Var2 = efx.R_DecalShoot;
      if (r_decals.value == 0.0) goto LAB_0014f6a0;
      uVar6 = uVar6 + 1;
      iVar1 = pmove->physents[iStack_30].info;
      iVar5 = (*efx.Draw_DecalIndex)(decalIndices[iVar3]);
      (*p_Var2)(iVar5,iVar1,0,afStack_60 + 5,0);
    } while (count != uVar6);
  }
  return;
}


// R_MuzzleFlash  @ 0014f760
void R_MuzzleFlash(float *pos1,int type)

{
  float fVar1;
  float fVar2;
  int iVar3;
  TEMPENTITY *pTVar4;
  int32 iVar5;
  int iVar6;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: float scale@[???]
                       Unresolved local var: int frameCount@[???] */
  iVar6 = (type % 10) % 3;
  fVar1 = (float)(type / 10) * 0.1;
  fVar2 = 0.5;
  if (fVar1 != 0.0) {
    fVar2 = fVar1;
  }
  iVar3 = ModelFrameCount(cl_sprite_muzzleflash[iVar6]);
  pTVar4 = (*efx.CL_TempEntAlloc)(pos1,cl_sprite_muzzleflash[iVar6]);
  if (pTVar4 != (TEMPENTITY *)0x0) {
    (pTVar4->entity).curstate.rendermode = 5;
    (pTVar4->entity).curstate.renderamt = 0xff;
    (pTVar4->entity).curstate.renderfx = 0;
    (pTVar4->entity).curstate.scale = fVar2;
    (pTVar4->entity).curstate.rendercolor.r = 0xff;
    (pTVar4->entity).curstate.rendercolor.g = 0xff;
    (pTVar4->entity).curstate.rendercolor.b = 0xff;
    (pTVar4->entity).origin[0] = *pos1;
    (pTVar4->entity).origin[1] = pos1[1];
    (pTVar4->entity).origin[2] = pos1[2];
    pTVar4->die = (float)((longdouble)0.01 + (longdouble)cl.time);
    iVar5 = RandomLong(0,iVar3 + -1);
    (pTVar4->entity).angles[0] = 0.0;
    (pTVar4->entity).angles[1] = 0.0;
    (pTVar4->entity).angles[2] = 0.0;
    (pTVar4->entity).curstate.frame = (float)iVar5;
    pTVar4->frameMax = (float)iVar3;
    if (iVar6 == 0) {
      iVar5 = 0x14;
    }
    else {
      iVar5 = 0x167;
    }
    iVar5 = RandomLong(0,iVar5);
    (pTVar4->entity).angles[2] = (float)iVar5;
    AppendTEntity((cl_entity_t_conflict *)&pTVar4->entity);
    return;
  }
  return;
}


// R_NewMap  @ 001bac00
/* WARNING: Removing unreachable block (ram,0x001bac45) */
/* WARNING: Removing unreachable block (ram,0x001bac1d) */
/* WARNING: Removing unreachable block (ram,0x001bac31) */
/* WARNING: Removing unreachable block (ram,0x001bae50) */
/* WARNING: Removing unreachable block (ram,0x001bae60) */
/* WARNING: Removing unreachable block (ram,0x001bac5a) */
/* WARNING: Removing unreachable block (ram,0x001bac94) */
/* WARNING: Removing unreachable block (ram,0x001baca8) */
/* WARNING: Removing unreachable block (ram,0x001bacbc) */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_NewMap(void)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  model_s *pmVar6;
  
                    /* Unresolved local var: int i@[???] */
  piVar4 = d_lightstylevalue;
  uVar2 = 0;
  do {
    uVar2 = uVar2 + 1;
    *piVar4 = 0x108;
    piVar4[1] = 0x108;
    piVar4[2] = 0x108;
    piVar4[3] = 0x108;
    piVar4 = piVar4 + 4;
  } while (uVar2 < 0x40);
  Q_memset(&r_worldentity,0,3000);
  iVar3 = 0;
  iVar5 = 0;
  r_worldentity.model = cl.worldmodel;
  if (0 < (cl.worldmodel)->numleafs) {
    do {
      iVar5 = iVar5 + 1;
      pbVar1 = (cl.worldmodel)->leafs->ambient_sound_level + iVar3 + -0x10;
      pbVar1[0] = '\0';
      pbVar1[1] = '\0';
      pbVar1[2] = '\0';
      pbVar1[3] = '\0';
      iVar3 = iVar3 + 0x3c;
    } while (iVar5 < (cl.worldmodel)->numleafs);
  }
  iVar5 = 0;
  r_viewleaf = (mleaf_t *)0x0;
  R_ClearParticles();
  R_DecalInit();
  V_InitLevel();
  GL_BuildLightmaps();
  skytexturenum = -1;
  mirrortexturenum = -1;
  iVar3 = (cl.worldmodel)->numtextures;
  pmVar6 = cl.worldmodel;
  if (0 < iVar3) {
    do {
                    /* Unresolved local var: qboolean IsCzeroAndIsSkyCullAndIsD3D@[???] */
      if (pmVar6->textures[iVar5] != (texture_t *)0x0) {
        iVar3 = Q_strncmp(pmVar6->textures[iVar5]->name,"sky",3);
        if (iVar3 == 0) {
          skytexturenum = iVar5;
        }
        iVar3 = Q_strncmp((cl.worldmodel)->textures[iVar5]->name,"window02_1",10);
        if (iVar3 == 0) {
          mirrortexturenum = iVar5;
        }
        (cl.worldmodel)->textures[iVar5]->texturechain = (msurface_s *)0x0;
        iVar3 = (cl.worldmodel)->numtextures;
        pmVar6 = cl.worldmodel;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar3);
  }
  R_LoadSkys();
  (cl_entities->curstate).scale = gl_wateramp.value;
  GL_UnloadTextures();
  return;
}


// R_ParseParticleEffect  @ 0019a1b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_ParseParticleEffect(void)

{
  int iVar1;
  int color;
  vec_t *pvVar2;
  vec_t *pvVar3;
  float fVar4;
  vec_t local_34 [3];
  vec_t local_28 [3];
  vec_t avStack_1c [3];
  
                    /* Unresolved local var: vec3_t org@[???]
                       Unresolved local var: vec3_t dir@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int msgcount@[???]
                       Unresolved local var: int color@[???] */
  pvVar3 = local_34;
  do {
    pvVar2 = pvVar3 + 1;
    fVar4 = MSG_ReadCoord(&net_message);
    *pvVar3 = fVar4;
    pvVar3 = pvVar2;
  } while (pvVar2 != local_28);
  pvVar3 = local_28;
  do {
    iVar1 = MSG_ReadChar();
    pvVar2 = pvVar3 + 1;
    *pvVar3 = (float)iVar1 * 0.0625;
    pvVar3 = pvVar2;
  } while (avStack_1c != pvVar2);
  iVar1 = MSG_ReadByte();
  color = MSG_ReadByte();
  if (iVar1 == 0xff) {
    iVar1 = 0x400;
  }
  R_RunParticleEffect(local_34,local_28,color,iVar1);
  return;
}


// R_ParticleBox  @ 0014f9a0
void R_ParticleBox(float *mins,float *maxs,uchar r,uchar g,uchar b,float life)

{
  short sVar1;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int pcolor@[???]
                       Unresolved local var: vec3_t mmin@[???]
                       Unresolved local var: vec3_t mmax@[???]
                       Unresolved local var: vec3_t origin@[???] */
  sVar1 = R_LookupColor(r,g,b);
  local_18 = (*mins + *maxs) * 0.5;
  local_24 = *maxs - local_18;
  local_30 = *mins - local_18;
  local_14 = (maxs[1] + mins[1]) * 0.5;
  local_20 = maxs[1] - local_14;
  local_2c = mins[1] - local_14;
  local_10 = (maxs[2] + mins[2]) * 0.5;
  local_1c = maxs[2] - local_10;
  local_28 = mins[2] - local_10;
  PM_DrawBBox(&local_30,&local_24,&local_18,(int)sVar1,life);
  return;
}


// R_ParticleBurst  @ 0019aca0
void R_ParticleBurst(vec_t *pos,int size,int color,float life)

{
  particle_s **pppVar1;
  float fVar2;
  float flLow;
  particle_t *ppVar3;
  particle_t *ppVar4;
  int32 iVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  int local_34;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: vec3_t dir@[???]
                       Unresolved local var: vec3_t dest@[???]
                       Unresolved local var: float velocity@[???]
                       Unresolved local var: float dist@[???] */
  local_34 = 0x20;
  do {
    iVar6 = 0x20;
    do {
      ppVar4 = free_particles;
      ppVar3 = active_particles;
      if (free_particles == (particle_t *)0x0) {
        return;
      }
      active_particles = free_particles;
      pppVar1 = &free_particles->next;
      free_particles = free_particles->next;
      *pppVar1 = ppVar3;
      iVar5 = RandomLong(0,10);
      ppVar4->packedColor = 0;
      ppVar4->type = pt_static;
      ppVar4->color = (short)iVar5 + (short)color;
      ppVar4->org[0] = *pos;
      ppVar4->org[1] = pos[1];
      ppVar4->org[2] = pos[2];
      fVar2 = *pos;
      fVar9 = (float)size;
      flLow = (float)-size;
      fVar7 = RandomFloat(flLow,fVar9);
      fVar10 = pos[1];
      fVar8 = RandomFloat(flLow,fVar9);
      fVar11 = pos[2];
      fVar9 = RandomFloat(flLow,fVar9);
      local_28 = (fVar2 + fVar7) - ppVar4->org[0];
      local_24 = (fVar10 + fVar8) - ppVar4->org[1];
      local_20 = (fVar9 + fVar11) - ppVar4->org[2];
      fVar10 = VectorNormalize(&local_28);
      fVar2 = (float)cl.time;
      fVar11 = RandomFloat(-0.5,0.5);
      ppVar4->die = fVar2 + life + fVar11;
      VectorScale(&local_28,fVar10 / life,ppVar4->vel);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    local_34 = local_34 + -1;
  } while (local_34 != 0);
  return;
}


// R_ParticleExplosion  @ 0019a230
void R_ParticleExplosion(vec_t *org)

{
  particle_s **pppVar1;
  float fVar2;
  float fVar3;
  particle_t *ppVar4;
  particle_t *ppVar5;
  int32 iVar6;
  int iVar7;
  uint uVar8;
  float fVar9;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: particle_t * p@[???] */
  uVar8 = 0;
  do {
    ppVar5 = free_particles;
    ppVar4 = active_particles;
    if (free_particles == (particle_t *)0x0) {
      return;
    }
                    /* catch() { ... } // from try @ 00199fa4 with catch @ 0019a24f */
    active_particles = free_particles;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar4;
    iVar7 = ramp1[0];
                    /* try { // try from 0019a276 to 001aa27a has its CatchHandler @ 00199da0 */
    ppVar5->die = (float)cl.time + 5.0;
                    /* catch() { ... } // from try @ 0019a1c3 with catch @ 0019a27b */
    ppVar5->color = (short)iVar7;
    ppVar5->packedColor = 0;
                    /* catch() { ... } // from try @ 00199f0f with catch @ 0019a294 */
    iVar6 = RandomLong(0,3);
    ppVar5->type = pt_explode2 - (uVar8 & 1);
                    /* catch() { ... } // from try @ 00199e33 with catch @ 0019a2ac
                       catch() { ... } // from try @ 00199f95 with catch @ 0019a2ac
                       catch() { ... } // from try @ 0019a03f with catch @ 0019a2ac
                       catch() { ... } // from try @ 0019a1fb with catch @ 0019a2ac */
    ppVar5->ramp = (float)iVar6;
    do {
      iVar7 = 0;
      do {
                    /* catch() { ... } // from try @ 0019a600 with catch @ 0019a2d0 */
        fVar9 = RandomFloat(-512.0,512.0);
        ppVar5->vel[iVar7] = fVar9;
        iVar7 = iVar7 + 1;
      } while (iVar7 != 3);
      fVar9 = ppVar5->vel[0];
      fVar2 = ppVar5->vel[1];
      fVar3 = ppVar5->vel[2];
    } while (262144.0 < fVar3 * fVar3 + fVar2 * fVar2 + fVar9 * fVar9);
    uVar8 = uVar8 + 1;
    ppVar5->org[0] = fVar9 * 0.25 + *org;
    ppVar5->org[1] = fVar2 * 0.25 + org[1];
    ppVar5->org[2] = fVar3 * 0.25 + org[2];
  } while (uVar8 != 0x400);
  return;
}


// R_ParticleExplosion2  @ 0019a340
void R_ParticleExplosion2(vec_t *org,int colorStart,int colorLength)

{
  particle_s **pppVar1;
  particle_t *ppVar2;
  particle_t *ppVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: int colorMod@[???] */
  iVar4 = 0;
  do {
    ppVar3 = free_particles;
    ppVar2 = active_particles;
    if (free_particles == (particle_t *)0x0) {
      return;
    }
                    /* try { // try from 0019a361 to 001aa4b3 has its CatchHandler @ 0019a2d0 */
    iVar6 = 0;
    active_particles = free_particles;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar2;
    iVar5 = iVar4 + 1;
    ppVar3->die = (float)((longdouble)0.3 + (longdouble)cl.time);
    ppVar3->packedColor = 0;
    ppVar3->type = pt_blob;
    ppVar3->color = (short)(iVar4 % colorLength) + (short)colorStart;
    do {
      fVar8 = org[iVar6];
      fVar7 = RandomFloat(-16.0,16.0);
      ppVar3->org[iVar6] = fVar7 + fVar8;
      fVar8 = RandomFloat(-256.0,256.0);
      ppVar3->vel[iVar6] = fVar8;
      iVar6 = iVar6 + 1;
    } while (iVar6 != 3);
    iVar4 = iVar5;
  } while (iVar5 != 0x200);
  return;
}


// R_ParticleLine  @ 0014f930
void R_ParticleLine(float *start,float *end,uchar r,uchar g,uchar b,float life)

{
  short sVar1;
  
                    /* Unresolved local var: int pcolor@[???] */
  sVar1 = R_LookupColor(r,g,b);
  PM_ParticleLine(start,end,(int)sVar1,life,0.0);
  return;
}


// R_PlayerSprites  @ 0014dee0
void R_PlayerSprites(int client,int modelIndex,int count,int size)

{
  cl_entity_t *pcVar1;
  model_t *model;
  int iVar2;
  TEMPENTITY *pTVar3;
  int iVar4;
  float fVar5;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: model_t * pModel@[???]
                       Unresolved local var: cl_entity_t * pent@[DW_OP_reg3(EBX)]
                       Unresolved local var: int frameCount@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float flMinScale@[???]
                       Unresolved local var: float flMaxScale@[???]
                       Unresolved local var: vec3_t position@[???]
                       Unresolved local var: vec3_t dir@[???] */
  pcVar1 = cl_entities;
  if ((client < 1) || (cl.maxclients < client)) {
    Con_Printf("Bad ent in R_PlayerSprites!\n");
  }
  else {
    model = CL_GetModelByIndex(modelIndex);
    if (model == (model_t *)0x0) {
      Con_Printf("No model %d!\n",modelIndex);
    }
    else {
      iVar4 = 0;
      iVar2 = ModelFrameCount(model);
      iVar2 = iVar2 + -1;
      if (0 < count) {
        do {
          fVar5 = pcVar1[client].origin[0];
          local_34 = RandomFloat(-10.0,10.0);
          local_34 = local_34 + fVar5;
          fVar5 = pcVar1[client].origin[1];
          local_30 = RandomFloat(-10.0,10.0);
          local_30 = local_30 + fVar5;
          fVar5 = pcVar1[client].origin[2];
          local_2c = RandomFloat(-20.0,36.0);
          local_2c = local_2c + fVar5;
          pTVar3 = (*efx.CL_TempEntAlloc)(&local_34,model);
          if (pTVar3 == (TEMPENTITY *)0x0) {
            return;
          }
          pTVar3->tentOffset[0] = (pTVar3->entity).origin[0] - pcVar1[client].origin[0];
          pTVar3->tentOffset[1] = (pTVar3->entity).origin[1] - pcVar1[client].origin[1];
          pTVar3->tentOffset[2] = (pTVar3->entity).origin[2] - pcVar1[client].origin[2];
          if (iVar4 == 0) {
            local_28 = local_34 - pcVar1[client].origin[0];
            local_24 = local_30 - pcVar1[client].origin[1];
            local_20 = local_2c - pcVar1[client].origin[2];
            VectorNormalize(&local_28);
            VectorScale(&local_28,60.0,&local_28);
            (pTVar3->entity).baseline.origin[0] = local_28;
            (pTVar3->entity).baseline.origin[1] = local_24;
            fVar5 = RandomFloat(20.0,60.0);
            (pTVar3->entity).baseline.origin[2] = fVar5;
          }
          else {
            pTVar3->flags = pTVar3->flags | 0x8000;
            pTVar3->clientIndex = (short)client;
          }
          (pTVar3->entity).curstate.rendermode = 0;
          (pTVar3->entity).curstate.renderamt = 0xff;
          (pTVar3->entity).baseline.renderamt = 0xff;
          (pTVar3->entity).curstate.renderfx = 0xe;
          fVar5 = RandomFloat(1.0 - (float)size / 100.0,1.0);
          (pTVar3->entity).curstate.framerate = fVar5;
          if (iVar2 < 2) {
            pTVar3->die = (float)((longdouble)0.35 + (longdouble)cl.time);
          }
          else {
            pTVar3->flags = pTVar3->flags | 0x100;
            (pTVar3->entity).curstate.framerate = 20.0;
            pTVar3->die = (float)iVar2 * 0.05 + (float)cl.time;
          }
          iVar4 = iVar4 + 1;
          (pTVar3->entity).curstate.frame = 0.0;
          pTVar3->frameMax = (float)iVar2;
        } while (count != iVar4);
      }
    }
  }
  return;
}


// R_PolyBlend  @ 0017e0d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_PolyBlend(void)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int in_GS_OFFSET;
  byte local_14;
  byte local_13;
  byte local_12;
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: byte[4] color@[???]
                       Unresolved local var: int alpha@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = V_FadeAlpha();
  if (iVar3 != 0) {
    GL_DisableMultitexture();
    (*qglDisable)(0xbc0);
    (*qglEnable)(0xbe2);
    (*qglDisable)(0xb71);
    (*qglDisable)(0xde1);
    if (((byte)cl.sf.fadeFlags & 2) == 0) {
      (*qglBlendFunc)(0x302,0x303);
      local_14 = cl.sf.fader;
      local_11 = (undefined1)iVar3;
      local_13 = cl.sf.fadeg;
      local_12 = cl.sf.fadeb;
    }
    else {
      (*qglBlendFunc)(0,0x300);
      iVar1 = (0xff - iVar3) * 0xff;
      local_11 = 0xff;
      local_14 = (byte)((uint)cl.sf.fader * iVar3 + iVar1 >> 8);
      local_13 = (byte)((uint)cl.sf.fadeg * iVar3 + iVar1 >> 8);
      local_12 = (byte)(iVar1 + iVar3 * (uint)cl.sf.fadeb >> 8);
    }
    bVar2 = (*qglIsEnabled)(0xb60);
    AllowFog::isFogEnabled = (int)bVar2;
    if (AllowFog::isFogEnabled == 1) {
      R_SetFogEnabled(false);
    }
    (*qglViewport)(glx,gly,glwidth,glheight);
    (*qglMatrixMode)(0x1701);
    (*qglPushMatrix)();
    (*qglLoadIdentity)();
    (*qglOrtho)(0.0,(double)glwidth,(double)glheight,0.0,-99999.0,99999.0);
    (*qglMatrixMode)(0x1700);
    (*qglPushMatrix)();
    (*qglLoadIdentity)();
    (*qglDisable)(0xb44);
    (*qglColor4ubv)(&local_14);
    (*qglBegin)(7);
    (*qglVertex2f)(0.0,0.0);
    (*qglVertex2f)(0.0,(float)glheight);
    (*qglVertex2f)((float)glwidth,(float)glheight);
    (*qglVertex2f)((float)glwidth,0.0);
    (*qglEnd)();
    (*qglPopMatrix)();
    (*qglMatrixMode)(0x1701);
    (*qglPopMatrix)();
    (*qglEnable)(0xb71);
    (*qglEnable)(0xb44);
    (*qglEnable)(0xde1);
    (*qglEnable)(0xbc0);
    if (AllowFog::isFogEnabled == 1) {
      R_SetFogEnabled(true);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// R_PreDrawViewModel  @ 0017de90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_PreDrawViewModel(void)

{
  int iVar1;
  cl_entity_t *pcVar2;
  cl_entity_t *pcVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???] */
  currententity = &cl.viewent;
                    /* Unresolved local var: int i@[???] */
  if ((((((r_drawviewmodel.value != 0.0) &&
         (iVar4 = ClientDLL_IsThirdPerson(), pcVar3 = currententity, iVar1 = cl.weaponsequence,
         iVar4 == 0)) && (chase_active.value == 0.0)) &&
       ((envmap == false && (r_drawentities.value != 0.0)))) &&
      ((0 < cl.stats[0] &&
       ((currententity->model != (model_s *)0x0 && (cl.viewentity <= cl.maxclients)))))) &&
     (currententity->model->type == mod_studio)) {
    if (cl.weaponstarttime == 0.0) {
      cl.weaponstarttime = (float)cl.time;
    }
    (currententity->curstate).frame = 0.0;
    pcVar2 = cl_entities;
    (pcVar3->curstate).framerate = 1.0;
    (pcVar3->curstate).sequence = iVar1;
    iVar1 = pcVar3->index;
    (pcVar3->curstate).animtime = cl.weaponstarttime;
    pcVar3->attachment[0][0] = pcVar2[iVar1].origin[0];
    pcVar3->attachment[0][1] = pcVar2[iVar1].origin[1];
    pcVar3->attachment[0][2] = pcVar2[iVar1].origin[2];
    pcVar3->attachment[1][0] = pcVar2[iVar1].origin[0];
    pcVar3->attachment[1][1] = pcVar2[iVar1].origin[1];
    pcVar3->attachment[1][2] = pcVar2[iVar1].origin[2];
    pcVar3->attachment[2][0] = pcVar2[iVar1].origin[0];
    pcVar3->attachment[2][1] = pcVar2[iVar1].origin[1];
    pcVar3->attachment[2][2] = pcVar2[iVar1].origin[2];
    pcVar3->attachment[3][0] = pcVar2[iVar1].origin[0];
    pcVar3->attachment[3][1] = pcVar2[iVar1].origin[1];
    pcVar3->attachment[3][2] = pcVar2[iVar1].origin[2];
    (*pStudioAPI->StudioDrawModel)(2);
  }
  return;
}


// R_Projectile  @ 0014cc40
void R_Projectile(vec_t *origin,vec_t *velocity,int modelIndex,int life,int owner,
                 _func_void_tempent_s_ptr_pmtrace_s_ptr *hitcallback)

{
  vec_t vVar1;
  uint uVar2;
  model_t *model;
  TEMPENTITY *pTVar3;
  int iVar4;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: TEMPENTITY * ptemp@[???]
                       Unresolved local var: model_t * model@[???]
                       Unresolved local var: vec3_t orientation@[???]
                       Unresolved local var: int frameCount@[???] */
  model = CL_GetModelByIndex(modelIndex);
  if (model != (model_t *)0x0) {
    pTVar3 = (*efx.CL_TempEntAllocHigh)(origin,model);
    if (pTVar3 == (TEMPENTITY *)0x0) {
      Con_Printf("Couldn\'t allocate temp ent in R_Projectile!\n");
    }
    else if ((owner < 0) || (cl.maxclients < owner)) {
      Con_Printf("Bad ent in R_Projectile!\n");
    }
    else {
      pTVar3->flags = pTVar3->flags | 0x7000;
      (pTVar3->entity).baseline.origin[0] = *velocity;
      (pTVar3->entity).baseline.origin[1] = velocity[1];
      vVar1 = velocity[2];
      pTVar3->clientIndex = (short)owner;
      (pTVar3->entity).baseline.origin[2] = vVar1;
      if (((pTVar3->entity).model)->type == mod_sprite) {
        iVar4 = ModelFrameCount(model);
        uVar2 = pTVar3->flags;
        pTVar3->flags = uVar2 | 0x100;
        pTVar3->frameMax = (float)iVar4;
        if (iVar4 < 10) {
          (pTVar3->entity).curstate.framerate = 10.0;
          pTVar3->flags = uVar2 | 0x10100;
        }
        else {
          (pTVar3->entity).curstate.framerate = (float)(iVar4 / life);
        }
      }
      else {
        pTVar3->frameMax = 0.0;
        VectorNormalize(velocity);
        VectorAngles(velocity,&local_28);
        (pTVar3->entity).angles[0] = local_28;
        (pTVar3->entity).angles[1] = local_24;
        (pTVar3->entity).angles[2] = local_20;
      }
      (pTVar3->entity).curstate.rendermode = 0;
      (pTVar3->entity).curstate.renderfx = 0;
      (pTVar3->entity).curstate.renderamt = 0xff;
      (pTVar3->entity).baseline.renderamt = 0xff;
      pTVar3->die = (float)life + (float)cl.time;
      (pTVar3->entity).curstate.frame = 0.0;
      (pTVar3->entity).curstate.body = 0;
      (pTVar3->entity).curstate.scale = 1.0;
      (pTVar3->entity).curstate.rendercolor.r = 0xff;
      (pTVar3->entity).curstate.rendercolor.g = 0xff;
      (pTVar3->entity).curstate.rendercolor.b = 0xff;
      pTVar3->hitcallback = hitcallback;
    }
  }
  return;
}


// R_PushDlights  @ 00198ab0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_PushDlights(void)

{
  char *pcVar1;
  byte bVar2;
  lightstyle_t *light;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: dlight_t * l@[???] */
  if (gl_flashblend.value == 0.0) {
    bVar2 = 0;
    r_dlightframecount = r_framecount + 1;
    light = (lightstyle_t *)cl_dlights;
    do {
      while (((float)cl.time <= *(float *)(light->map + 0x10) && (*(float *)(light->map + 8) != 0.0)
             )) {
        pcVar1 = light->map;
        R_MarkLights((dlight_t *)light,1 << (bVar2 & 0x1f),(cl.worldmodel)->nodes);
        bVar2 = bVar2 + 1;
        light = (lightstyle_t *)(pcVar1 + 0x24);
        if ((lightstyle_t *)(pcVar1 + 0x24) == cl_lightstyle) {
          return;
        }
      }
      light = (lightstyle_t *)(light->map + 0x24);
      bVar2 = bVar2 + 1;
    } while (light != cl_lightstyle);
  }
  return;
}


// R_ReUploadLightmap  @ 001909f0
void R_ReUploadLightmap(msurface_t *fa)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_28;
  
                    /* Unresolved local var: byte * base@[???]
                       Unresolved local var: glRect_t * theRect@[???]
                       Unresolved local var: int smax@[???]
                       Unresolved local var: int tmax@[???] */
  lightmap_modified[fa->lightmaptexturenum] = true;
  iVar1 = fa->lightmaptexturenum;
  iVar4 = fa->light_t;
  iVar3 = lightmap_rectchange[iVar1].t;
  if (iVar4 < iVar3) {
    if (lightmap_rectchange[iVar1].h != 0) {
      lightmap_rectchange[iVar1].h = lightmap_rectchange[iVar1].h + (iVar3 - iVar4);
      iVar4 = fa->light_t;
    }
    iVar3 = iVar4;
    lightmap_rectchange[iVar1].t = iVar3;
  }
  iVar4 = fa->light_s;
  local_28 = lightmap_rectchange[iVar1].l;
  iVar2 = iVar4;
  if (iVar4 < local_28) {
    if (lightmap_rectchange[iVar1].w != 0) {
      lightmap_rectchange[iVar1].w = lightmap_rectchange[iVar1].w + (local_28 - iVar4);
      iVar4 = fa->light_s;
    }
    lightmap_rectchange[iVar1].l = iVar4;
    iVar2 = fa->light_s;
    local_28 = iVar4;
  }
  iVar4 = ((int)fa->extents[0] >> 4) + 1;
  iVar5 = ((int)fa->extents[1] >> 4) + 1;
  if (local_28 + lightmap_rectchange[iVar1].w < iVar4 + iVar2) {
    lightmap_rectchange[iVar1].w = (iVar2 - local_28) + iVar4;
  }
  iVar4 = fa->light_t;
  if (lightmap_rectchange[iVar1].h + iVar3 < iVar5 + iVar4) {
    lightmap_rectchange[iVar1].h = (iVar4 - iVar3) + iVar5;
    iVar4 = fa->light_t;
  }
  R_BuildLightMap(fa,lightmaps +
                     lightmap_bytes * fa->lightmaptexturenum * 0x4000 +
                     (iVar4 * 0x80 + fa->light_s) * lightmap_bytes,lightmap_bytes << 7);
  return;
}


// R_ReUploadLightmaps  @ 00190b60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_ReUploadLightmaps(void)

{
  msurface_t *psurf;
  model_s *pmVar1;
  model_t *pmVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_34;
  int local_2c;
  
                    /* Unresolved local var: model_t * m@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
  local_34 = 1;
  do {
    pmVar1 = cl.model_precache[local_34];
    if (pmVar1 == (model_s *)0x0) {
      return;
    }
    if ((pmVar1->name[0] != '*') && (pmVar1->numsurfaces != 0)) {
      pmVar2 = CL_GetModelByIndex(local_34);
      iVar6 = pmVar2->numsurfaces;
      if (0 < iVar6) {
        iVar8 = 0;
        do {
                    /* Unresolved local var: msurface_t * surf@[???] */
          psurf = pmVar2->surfaces + iVar8;
          if (((psurf->flags & 0x14U) == 0) &&
             (((psurf->flags & 0x20U) == 0 || ((psurf->texinfo->flags & 1) == 0)))) {
                    /* Unresolved local var: byte * base@[???]
                       Unresolved local var: glRect_t * theRect@[???]
                       Unresolved local var: int smax@[???]
                       Unresolved local var: int tmax@[???] */
            lightmap_modified[psurf->lightmaptexturenum] = true;
            iVar6 = psurf->lightmaptexturenum;
            iVar5 = psurf->light_t;
            local_2c = lightmap_rectchange[iVar6].t;
            if (iVar5 < local_2c) {
              if (lightmap_rectchange[iVar6].h != 0) {
                lightmap_rectchange[iVar6].h = lightmap_rectchange[iVar6].h + (local_2c - iVar5);
                iVar5 = psurf->light_t;
              }
              lightmap_rectchange[iVar6].t = iVar5;
              local_2c = iVar5;
            }
            iVar5 = psurf->light_s;
            iVar3 = lightmap_rectchange[iVar6].l;
            iVar7 = iVar3;
            if (iVar5 < iVar3) {
              iVar7 = iVar5;
              if (lightmap_rectchange[iVar6].w != 0) {
                lightmap_rectchange[iVar6].w = lightmap_rectchange[iVar6].w + (iVar3 - iVar5);
                iVar7 = psurf->light_s;
              }
              lightmap_rectchange[iVar6].l = iVar7;
              iVar5 = psurf->light_s;
            }
            iVar3 = ((int)psurf->extents[0] >> 4) + 1;
            iVar4 = ((int)psurf->extents[1] >> 4) + 1;
            if (iVar7 + lightmap_rectchange[iVar6].w < iVar3 + iVar5) {
              lightmap_rectchange[iVar6].w = (iVar5 - iVar7) + iVar3;
            }
            iVar5 = psurf->light_t;
            if (local_2c + lightmap_rectchange[iVar6].h < iVar4 + iVar5) {
              lightmap_rectchange[iVar6].h = (iVar5 - local_2c) + iVar4;
              iVar5 = psurf->light_t;
            }
            R_BuildLightMap(psurf,lightmaps +
                                  lightmap_bytes * psurf->lightmaptexturenum * 0x4000 +
                                  (iVar5 * 0x80 + psurf->light_s) * lightmap_bytes,
                            lightmap_bytes << 7);
            iVar6 = pmVar2->numsurfaces;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar6);
      }
    }
    local_34 = local_34 + 1;
  } while (local_34 != 0x200);
  return;
}


// R_ReadPointFile_f  @ 00199dc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_ReadPointFile_f(void)

{
  vec_t *pvVar1;
  vec_t vVar2;
  vec_t vVar3;
  particle_t *ppVar4;
  particle_t *ppVar5;
  FILE *__stream;
  int iVar6;
  int iVar7;
  ushort uVar8;
  int in_GS_OFFSET;
  vec_t vStack_230;
  vec_t vStack_22c;
  vec_t vStack_228;
  char local_224 [256];
  char local_124 [259];
  undefined1 uStack_21;
  int local_20;
  
                    /* Unresolved local var: FILE * f@[???]
                       Unresolved local var: vec3_t org@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: char[256] base@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cl.worldmodel != (model_s *)0x0) {
    COM_StripExtension((cl.worldmodel)->name,local_224);
    __snprintf_chk(local_124,0x104,1,0x104,"%s.pts",local_224);
    uStack_21 = 0;
    COM_FixSlashes(local_124);
    __stream = fopen(local_124,"rb");
    if (__stream == (FILE *)0x0) {
      Con_Printf("couldn\'t open %s\n",local_124);
    }
    else {
      iVar7 = 0;
      Con_Printf("Reading %s...\n",local_124);
      uVar8 = 0xffff;
      while( true ) {
        iVar6 = __isoc99_fscanf(__stream,"%f %f %f\n",&vStack_230,&vStack_22c,&vStack_228);
        ppVar5 = free_particles;
        if (iVar6 != 3) break;
        iVar7 = iVar7 + 1;
        if (free_particles == (particle_t *)0x0) {
          Con_Printf("Not enough free particles\n");
          break;
        }
        free_particles->packedColor = 0;
        ppVar4 = active_particles;
        active_particles = free_particles;
        pvVar1 = free_particles->vel;
        free_particles = free_particles->next;
        *pvVar1 = vec3_origin[0];
        ppVar5->die = 99999.0;
        ppVar5->next = ppVar4;
        ppVar5->color = uVar8 & 0xf;
        vVar3 = vec3_origin[2];
        vVar2 = vec3_origin[1];
        ppVar5->org[0] = vStack_230;
        ppVar5->vel[1] = vVar2;
        ppVar5->vel[2] = vVar3;
        ppVar5->type = pt_static;
        ppVar5->org[1] = vStack_22c;
        ppVar5->org[2] = vStack_228;
        uVar8 = uVar8 - 1;
      }
      fclose(__stream);
      Con_Printf("%i points read\n",iVar7);
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// R_RecursiveWorldNode  @ 00197260
void R_RecursiveWorldNode(mnode_t *node,qboolean cleanUpShaderState)

{
  byte bVar1;
  mplane_t *pmVar2;
  uint uVar3;
  texture_t *ptVar4;
  float fVar5;
  int *piVar6;
  qboolean qVar7;
  int iVar8;
  mnode_s *pmVar9;
  msurface_t *s;
  uint uVar10;
  uint local_24;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: msurface_t * surf@[???]
                       Unresolved local var: msurface_t * * mark@[???]
                       Unresolved local var: mleaf_t * pleaf@[???]
                       Unresolved local var: double dot@[???] */
  iVar8 = node->contents;
  do {
    if (iVar8 == -2) {
      return;
    }
    while( true ) {
      if (node->visframe != r_visframecount) {
        return;
      }
      qVar7 = R_CullBox(node->minmaxs,node->minmaxs + 3);
      if (qVar7 != false) {
        return;
      }
      if (node->contents < 0) {
        iVar8._0_2_ = node->firstsurface;
        iVar8._2_2_ = node->numsurfaces;
        if (iVar8 != 0) {
          pmVar9 = node->children[1];
          do {
            piVar6 = &pmVar9->contents;
            pmVar9 = (mnode_s *)&pmVar9->visframe;
            iVar8 = iVar8 + -1;
            *(int *)*piVar6 = r_framecount;
          } while (iVar8 != 0);
        }
        if (node->children[0] == (mnode_s *)0x0) {
          return;
        }
        R_StoreEfrags((efrag_t **)node->children);
        return;
      }
      pmVar2 = node->plane;
      bVar1 = pmVar2->type;
      if (bVar1 == '\x01') {
        fVar5 = modelorg[1] - pmVar2->dist;
      }
      else if (bVar1 == '\0') {
        fVar5 = modelorg[0] - pmVar2->dist;
      }
      else if (bVar1 == '\x02') {
        fVar5 = modelorg[2] - pmVar2->dist;
      }
      else {
        fVar5 = (modelorg[2] * pmVar2->normal[2] +
                modelorg[1] * pmVar2->normal[1] + modelorg[0] * pmVar2->normal[0]) - pmVar2->dist;
      }
      R_RecursiveWorldNode(node->children[0.0 > fVar5],cleanUpShaderState);
      uVar10 = (uint)node->numsurfaces;
      uVar3 = (uint)(0.0 <= fVar5);
      if (uVar10 == 0) break;
      s = (cl.worldmodel)->surfaces + node->firstsurface;
      if (fVar5 < -0.01) {
        local_24 = 0;
      }
      else {
        local_24 = 1;
        if (fVar5 <= 0.01) {
          local_24 = uVar3;
        }
      }
      do {
        while ((s->visframe != r_framecount ||
               ((uVar3 = s->flags, (uVar3 & 0x80) == 0 &&
                (fVar5 < 0.0 != (bool)((byte)(uVar3 >> 1) & 1)))))) {
LAB_00197380:
          s = s + 1;
          uVar10 = uVar10 - 1;
          if (uVar10 == 0) goto LAB_001973f2;
        }
        if (gl_texsort == false) {
          if ((uVar3 & 4) == 0) {
            if ((uVar3 & 0x10) == 0) {
              R_DrawSequentialPoly(s,0,cleanUpShaderState);
            }
            else {
              s->texturechain = waterchain;
              waterchain = s;
            }
          }
          else {
            s->texturechain = skychain;
            skychain = s;
          }
          goto LAB_00197380;
        }
        ptVar4 = s->texinfo->texture;
        if ((mirror != false) && (ptVar4 == (cl.worldmodel)->textures[mirrortexturenum]))
        goto LAB_00197380;
        s->texturechain = ptVar4->texturechain;
        s->texinfo->texture->texturechain = s;
        s = s + 1;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
LAB_001973f2:
      node = node->children[local_24];
      if (node->contents == -2) {
        return;
      }
    }
    node = node->children[uVar3];
    iVar8 = node->contents;
  } while( true );
}


// R_ReloadShaders  @ 0018f780
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_ReloadShaders(void)

{
  uint uVar1;
  uint uVar2;
  qboolean qVar3;
  
                    /* Unresolved local var: int i@[???] */
  if (g_fsWorldProgram[0] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[0]);
  }
  g_fsWorldProgram[0] = 0;
  if (g_fsWorldProgram[1] != 0) {
    g_fsWorldProgram[0] = 0;
    (*qglDeleteProgram)(g_fsWorldProgram[1]);
  }
  g_fsWorldProgram[1] = 0;
  if (g_fsWorldProgram[2] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[2]);
  }
  g_fsWorldProgram[2] = 0;
  if (g_fsWorldProgram[3] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[3]);
  }
  g_fsWorldProgram[3] = 0;
  if (g_fsWorldProgram[4] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[4]);
  }
  g_fsWorldProgram[4] = 0;
  if (g_fsWorldProgram[5] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[5]);
  }
  g_fsWorldProgram[5] = 0;
  if (g_fsWorldProgram[6] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[6]);
    g_fsWorldProgram[6] = 0;
  }
  if (g_fsWorldProgram[7] != 0) {
    (*qglDeleteProgram)(g_fsWorldProgram[7]);
    g_fsWorldProgram[7] = 0;
  }
  uVar2 = 0;
  do {
    *(undefined4 *)((int)g_nFogEnabledUniformLocation + uVar2) = 0xffffffff;
    uVar1 = uVar2 + 8;
    *(undefined4 *)((int)g_nFogEnabledUniformLocation + uVar2 + 4) = 0xffffffff;
    uVar2 = uVar1;
  } while (uVar1 < 0x20);
  uVar2 = 0;
  do {
    *(undefined4 *)((int)g_nFogModeUniformLocation + uVar2) = 0xffffffff;
    uVar1 = uVar2 + 8;
    *(undefined4 *)((int)g_nFogModeUniformLocation + uVar2 + 4) = 0xffffffff;
    uVar2 = uVar1;
  } while (uVar1 < 0x20);
  g_bTriedToCreateWorldShader = false;
  qVar3 = R_UseLegacyRender();
  if ((((((qVar3 == 0) && (qglCreateShader != (_func_GLuint_GLenum *)0x0)) &&
        (qglDeleteShader != (_func_void_GLuint *)0x0)) &&
       ((qglShaderSource != (_func_void_GLuint_GLsizei_GLchar_ptr_ptr_GLint_ptr *)0x0 &&
        (qglGetProgramiv != (_func_void_GLuint_GLenum_GLint_ptr *)0x0)))) &&
      ((qglGetProgramInfoLog != (_func_void_GLuint_GLsizei_GLsizei_ptr_GLchar_ptr *)0x0 &&
       ((qglAttachShader != (_func_void_GLuint_GLuint *)0x0 &&
        (qglLinkProgram != (_func_void_GLuint *)0x0)))))) &&
     ((qglCreateProgram != (_func_GLuint *)0x0 &&
      ((qglDeleteProgram != (_func_void_GLuint *)0x0 && (qglUseProgram != (_func_void_GLuint *)0x0))
      )))) {
    R_LoadShaders();
    return;
  }
  return;
}


// R_RemoveEfrags  @ 001a34d0
void R_RemoveEfrags(cl_entity_t *ent)

{
  efrag_s *peVar1;
  efrag_s *peVar2;
  efrag_s *peVar3;
  efrag_s **ppeVar4;
  
                    /* Unresolved local var: efrag_t * ef@[???]
                       Unresolved local var: efrag_t * old@[???]
                       Unresolved local var: efrag_t * walk@[???]
                       Unresolved local var: efrag_t * * prev@[???] */
  peVar1 = ent->efrag;
  do {
    peVar2 = peVar1;
    if (peVar2 == (efrag_s *)0x0) {
      ent->efrag = (efrag_s *)0x0;
      return;
    }
    peVar1 = peVar2->leaf->efrags;
    if (peVar1 != (efrag_s *)0x0) {
      if (peVar1 == peVar2) {
        ppeVar4 = &peVar2->leaf->efrags;
      }
      else {
        do {
          peVar3 = peVar1;
          peVar1 = peVar3->leafnext;
          if (peVar1 == (efrag_s *)0x0) goto LAB_001a34fd;
        } while (peVar1 != peVar2);
        ppeVar4 = &peVar3->leafnext;
      }
      *ppeVar4 = peVar2->leafnext;
    }
LAB_001a34fd:
    peVar1 = peVar2->entnext;
    peVar2->entnext = cl.free_efrags;
    cl.free_efrags = peVar2;
  } while( true );
}


// R_RenderBrushPoly  @ 00191440
void __regparm3 R_RenderBrushPoly(msurface_t *fa)

{
  uint uVar1;
  glpoly_t *pgVar2;
  texture_t *ptVar3;
  float (*pafVar4) [7];
  int iVar5;
  
                    /* Unresolved local var: texture_t * t@[???]
                       Unresolved local var: byte * base@[???]
                       Unresolved local var: int maps@[???] */
  ptVar3 = R_TextureAnimation(fa);
  GL_Bind(ptVar3->gl_texturenum);
  uVar1 = fa->flags;
  if ((uVar1 & 0x10) != 0) {
    EmitWaterPolys(fa,0);
    return;
  }
  if ((uVar1 & 0x80) == 0) {
    if ((currententity->curstate).rendermode == 1) {
      (*qglDisable)(0xde1);
      DrawGLSolidPoly(fa->polys);
      (*qglEnable)(0xde1);
    }
    else if ((uVar1 & 0x20) == 0) {
      pgVar2 = fa->polys;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float * v@[???] */
      (*qglBegin)(9);
      if (0 < pgVar2->numverts) {
        iVar5 = 0;
        pafVar4 = pgVar2->verts;
        do {
          iVar5 = iVar5 + 1;
          (*qglTexCoord2f)((*pafVar4)[3],(*pafVar4)[4]);
          (*qglVertex3fv)(*pafVar4);
          pafVar4 = pafVar4 + 1;
        } while (iVar5 < pgVar2->numverts);
      }
      (*qglEnd)();
    }
    else {
      DrawGLPolyScroll(fa,currententity);
    }
  }
  else {
    DrawGLWaterPoly(fa->polys);
  }
  fa->polys->chain = lightmap_polys[fa->lightmaptexturenum];
  lightmap_polys[fa->lightmaptexturenum] = fa->polys;
  if (fa->pdecals != (decal_t *)0x0) {
    gDecalSurfs[gDecalSurfCount] = fa;
    gDecalSurfCount = gDecalSurfCount + 1;
    if (500 < gDecalSurfCount) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Too many decal surfaces!\n");
    }
  }
  if (((((fa->styles[0] != 0xff) &&
        ((fa->cached_light[0] != d_lightstylevalue[fa->styles[0]] ||
         ((fa->styles[1] != 0xff &&
          ((fa->cached_light[1] != d_lightstylevalue[fa->styles[1]] ||
           ((fa->styles[2] != 0xff &&
            ((d_lightstylevalue[fa->styles[2]] != fa->cached_light[2] ||
             ((fa->styles[3] != 0xff && (d_lightstylevalue[fa->styles[3]] != fa->cached_light[3]))))
            )))))))))) || (fa->dlightframe == r_framecount)) || (fa->cached_dlight != 0)) &&
     (r_dynamic.value != 0.0)) {
    lightmap_modified[fa->lightmaptexturenum] = true;
    R_BuildLightMap(fa,lightmaps +
                       lightmap_bytes * fa->lightmaptexturenum * 0x4000 +
                       (fa->light_t * 0x80 + fa->light_s) * lightmap_bytes,lightmap_bytes << 7);
    return;
  }
  return;
}


// R_RenderBrushPoly  @ 001916c0
void R_RenderBrushPoly(msurface_t *fa)

{
                    /* Unresolved local var: texture_t * t@[???]
                       Unresolved local var: byte * base@[???]
                       Unresolved local var: int maps@[???] */
  c_brush_polys = c_brush_polys + 1;
  if ((fa->flags & 4) != 0) {
    return;
  }
  R_RenderBrushPoly(fa);
  return;
}


// R_RenderDlight  @ 001985a0
void R_RenderDlight(dlight_t *light)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  double local_44;
  double local_3c;
  float local_30;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: float a@[???]
                       Unresolved local var: vec3_t v@[???]
                       Unresolved local var: float rad@[???] */
  fVar1 = light->radius * 0.35;
  local_28 = light->origin[0] - r_origin[0];
  local_24 = light->origin[1] - r_origin[1];
  local_20 = light->origin[2] - r_origin[2];
  fVar4 = Length(&local_28);
  if (fVar1 <= fVar4) {
    iVar3 = 0x10;
    (*qglBegin)(6);
    (*qglColor3f)(0.2,0.1,0.0);
    local_28 = light->origin[0] - vpn[0] * fVar1;
    local_24 = light->origin[1] - vpn[1] * fVar1;
    local_20 = light->origin[2] - vpn[2] * fVar1;
    (*qglVertex3fv)(&local_28);
    (*qglColor3f)(0.0,0.0,0.0);
    fVar2 = 1.0;
    fVar4 = 1.7484555e-07;
    while( true ) {
      iVar3 = iVar3 + -1;
      local_28 = fVar4 * vup[0] * fVar1 + fVar2 * vright[0] * fVar1 + light->origin[0];
      local_24 = fVar4 * vup[1] * fVar1 + fVar2 * vright[1] * fVar1 + light->origin[1];
      local_20 = fVar2 * vright[2] * fVar1 + light->origin[2] + fVar4 * vup[2] * fVar1;
      (*qglVertex3fv)(&local_28);
      if (iVar3 == -1) break;
      local_30 = (float)iVar3 * 0.0625 * 3.1415927;
      local_30 = local_30 + local_30;
      sincos((double)local_30,&local_3c,&local_44);
      fVar2 = (float)local_44;
      fVar4 = (float)local_3c;
    }
    (*qglEnd)();
    return;
  }
  fVar1 = light->radius * 0.0003;
                    /* Unresolved local var: float a@[???] */
  v_blend[3] = (1.0 - v_blend[3]) * fVar1 + v_blend[3];
  fVar1 = fVar1 / v_blend[3];
  fVar4 = v_blend[1] * (1.0 - fVar1);
  v_blend[0] = fVar1 + fVar4;
  v_blend[1] = fVar1 * 0.5 + fVar4;
  v_blend[2] = fVar1 * 0.0 + (1.0 - fVar1) * v_blend[2];
  return;
}


// R_RenderDlights  @ 001987d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_RenderDlights(void)

{
  char *pcVar1;
  lightstyle_t *light;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: dlight_t * l@[???] */
  if (gl_flashblend.value == 0.0) {
    return;
  }
  r_dlightframecount = r_framecount + 1;
  (*qglDepthMask)('\0');
  (*qglDisable)(0xde1);
  (*qglShadeModel)(0x1d01);
  (*qglEnable)(0xbe2);
  (*qglBlendFunc)(1,1);
  light = (lightstyle_t *)cl_dlights;
  do {
    while ((*(float *)(light->map + 0x10) < (float)cl.time || (*(float *)(light->map + 8) == 0.0)))
    {
      light = (lightstyle_t *)(light->map + 0x24);
      if (light == cl_lightstyle) goto LAB_0019888c;
    }
    pcVar1 = light->map;
    R_RenderDlight((dlight_t *)light);
    light = (lightstyle_t *)(pcVar1 + 0x24);
  } while ((lightstyle_t *)(pcVar1 + 0x24) != cl_lightstyle);
LAB_0019888c:
  (*qglColor3f)(1.0,1.0,1.0);
  (*qglDisable)(0xbe2);
  (*qglEnable)(0xde1);
  (*qglBlendFunc)(0x302,0x303);
  (*qglDepthMask)('\x01');
  return;
}


// R_RenderDynamicLightmaps  @ 00190d70
void R_RenderDynamicLightmaps(msurface_t *fa)

{
                    /* Unresolved local var: int maps@[???] */
  c_brush_polys = c_brush_polys + 1;
  if ((fa->flags & 0x14) == 0) {
    fa->polys->chain = lightmap_polys[fa->lightmaptexturenum];
    lightmap_polys[fa->lightmaptexturenum] = fa->polys;
                    /* Unresolved local var: int maps@[???] */
    if (((((fa->styles[0] != 0xff) &&
          ((d_lightstylevalue[fa->styles[0]] != fa->cached_light[0] ||
           ((fa->styles[1] != 0xff &&
            ((d_lightstylevalue[fa->styles[1]] != fa->cached_light[1] ||
             ((fa->styles[2] != 0xff &&
              ((d_lightstylevalue[fa->styles[2]] != fa->cached_light[2] ||
               ((fa->styles[3] != 0xff && (d_lightstylevalue[fa->styles[3]] != fa->cached_light[3]))
               )))))))))))) || (fa->dlightframe == r_framecount)) || (fa->cached_dlight != 0)) &&
       (r_dynamic.value != 0.0)) {
      R_ReUploadLightmap(fa);
      return;
    }
  }
  return;
}


// R_RenderFinalFog  @ 001c0690
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_RenderFinalFog(void)

{
  if (gD3DMode != 1) {
    R_SetFogEnabled(true);
    R_SetFogMode(0x801);
    (*qglFogf)(0xb62,flFogDensity);
    (*qglHint)(0xc54,0x1102);
    (*qglFogfv)(0xb66,flFinalFogColor);
    (*qglFogf)(0xb63,flFogStart);
    (*qglFogf)(0xb64,flFogEnd);
  }
  return;
}


// R_RenderFog  @ 001c0540
void R_RenderFog(float *flFogColor,float flStart,float flEnd,BOOL bOn)

{
  if ((bOn != 0) && (0.0 < gl_fog.value)) {
    g_bUserFogOn = 1;
    flFogStart = flStart;
    flFogEnd = flEnd;
    flFinalFogColor[0] = *flFogColor / 255.0;
    flFinalFogColor[1] = flFogColor[1] / 255.0;
    flFinalFogColor[3] = 1.0;
    flFinalFogColor[2] = flFogColor[2] / 255.0;
    return;
  }
  g_bUserFogOn = 0;
  return;
}


// R_RenderScene  @ 0017fee0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_RenderScene(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = CL_IsDevOverviewMode();
  if (iVar2 != 0) {
    CL_SetDevOverView(&r_refdef);
  }
  R_SetupFrame();
  R_SetFrustum();
  R_SetupGL();
  R_MarkLeaves();
  if (r_refdef.onlyClientDraws == false) {
    iVar2 = CL_IsDevOverviewMode();
    if (iVar2 != 0) {
      (*qglClearColor)(0.0,1.0,0.0,0.0);
      (*qglClear)(0x4000);
    }
    R_DrawWorld();
    S_ExtraUpdate();
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
    if (r_drawentities.value != 0.0) {
      R_DrawEntitiesOnList();
    }
  }
  if (g_bUserFogOn != 0) {
    R_RenderFinalFog();
  }
  bVar1 = (*qglIsEnabled)(0xb60);
  AllowFog::isFogEnabled = (int)bVar1;
  if (AllowFog::isFogEnabled == 1) {
    R_SetFogEnabled(false);
    ClientDLL_DrawNormalTriangles();
  }
  else {
    ClientDLL_DrawNormalTriangles();
  }
  if (AllowFog::isFogEnabled == 1) {
    R_SetFogEnabled(true);
  }
  if ((cl.waterlevel < 3) || (r_refdef.onlyClientDraws != false)) {
    if (g_bUserFogOn == 0) {
      R_SetFogEnabled(false);
    }
  }
  else {
    R_SetFogEnabled(false);
  }
  R_DrawTEntitiesOnList(r_refdef.onlyClientDraws);
  S_ExtraUpdate();
  if (r_refdef.onlyClientDraws != false) {
    return;
  }
  R_RenderDlights();
  GL_DisableMultitexture();
  R_DrawParticles();
  return;
}


// R_RenderView  @ 001800b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_RenderView(void)

{
  float fVar1;
  double dVar2;
  double local_1c;
  
                    /* Unresolved local var: double time1@[???]
                       Unresolved local var: double time2@[???] */
  if (r_norefresh.value == 0.0) {
    if ((r_worldentity.model == (model_s *)0x0) || (cl.worldmodel == (model_s *)0x0)) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("R_RenderView: NULL worldmodel");
    }
    if (r_speeds.value != 0.0) {
      (*qglFinish)();
      local_1c = Sys_FloatTime();
      c_brush_polys = 0;
      c_alias_polys = 0;
    }
    mirror = false;
    R_Clear();
    if (r_refdef.onlyClientDraws == false) {
      R_PreDrawViewModel();
      R_RenderScene();
    }
    else {
      R_RenderScene();
    }
    if (r_refdef.onlyClientDraws == false) {
      R_DrawViewModel();
      R_PolyBlend();
    }
    S_ExtraUpdate();
    if (r_speeds.value != 0.0) {
                    /* Unresolved local var: float framerate@[???] */
      fVar1 = (float)((longdouble)cl.time - (longdouble)cl.oldtime);
      if (0.0 < fVar1) {
        fVar1 = 1.0 / fVar1;
      }
      dVar2 = Sys_FloatTime();
      Con_Printf("%3ifps %3i ms  %4i wpoly %4i epoly\n",(int)(fVar1 + 0.5),
                 (int)((dVar2 - local_1c) * 1000.0),c_brush_polys,c_alias_polys);
    }
  }
  return;
}


// R_ResetLatched  @ 000e3020
void R_ResetLatched(cl_entity_t *ent,qboolean full_reset)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  vec_t vVar5;
  model_t *mod;
  undefined4 uVar6;
  cl_entity_t *pcVar7;
  uint uVar8;
  uint uVar9;
  void *pvVar10;
  int iVar11;
  float fVar12;
  
  if (full_reset == false) {
    iVar11 = (ent->curstate).sequence;
  }
  else {
    Q_memcpy((ent->latched).prevcontroller,(ent->curstate).controller,4);
    Q_memcpy((ent->latched).prevblending,(ent->curstate).blending,2);
                    /* Unresolved local var: float f@[???]
                       Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: cl_entity_t * oldce@[???] */
    mod = ent->model;
    (ent->latched).sequencetime = (ent->curstate).animtime;
    pcVar7 = currententity;
    if ((mod == (model_t *)0x0) || (mod->type != mod_studio)) {
      iVar11 = (ent->curstate).sequence;
      fVar12 = 0.0;
      currententity = pcVar7;
    }
    else {
      pvVar10 = Mod_Extradata(mod);
      iVar11 = (ent->curstate).sequence;
      if (pvVar10 == (void *)0x0) {
        fVar12 = 0.0;
      }
      else {
        currententity = ent;
        fVar12 = CL_StudioEstimateFrame
                           ((mstudioseqdesc_t *)
                            ((int)pvVar10 + iVar11 * 0xb0 + *(int *)((int)pvVar10 + 0xa8)));
        currententity = pcVar7;
      }
    }
    (ent->latched).prevframe = fVar12;
    uVar8 = 0;
    do {
      uVar9 = uVar8;
      uVar6 = *(undefined4 *)((int)(ent->curstate).origin + (uVar9 - 0xc));
      *(undefined4 *)((int)(ent->prevstate).origin + (uVar9 - 0x10)) =
           *(undefined4 *)((int)(ent->curstate).origin + (uVar9 - 0x10));
      *(undefined4 *)((int)(ent->prevstate).origin + (uVar9 - 0xc)) = uVar6;
      uVar8 = uVar9 + 8;
    } while (uVar9 + 8 < 0x150);
    *(undefined4 *)((int)(ent->prevstate).origin + (uVar9 - 8)) =
         *(undefined4 *)((int)(ent->curstate).origin + (uVar9 - 8));
  }
  fVar12 = (float)cl.mtime[0];
  vVar1 = (ent->curstate).origin[1];
  vVar2 = (ent->curstate).origin[2];
  vVar3 = (ent->curstate).angles[0];
  vVar4 = (ent->curstate).angles[1];
  vVar5 = (ent->curstate).angles[2];
  (ent->latched).prevorigin[0] = (ent->curstate).origin[0];
  (ent->curstate).animtime = fVar12;
  (ent->latched).prevorigin[1] = vVar1;
  (ent->latched).prevanimtime = fVar12;
  (ent->latched).prevorigin[2] = vVar2;
  (ent->latched).prevangles[0] = vVar3;
  (ent->latched).prevangles[1] = vVar4;
  (ent->latched).prevangles[2] = vVar5;
  (ent->latched).prevsequence = iVar11;
  return;
}


// R_ResetStudio  @ 000e3d90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_ResetStudio(void)

{
  pStudioAPI = &studio;
  return;
}


// R_ResetSvBlending  @ 000e3da0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_ResetSvBlending(void)

{
  g_pSvBlendingAPI = &svBlending;
  return;
}


// R_RicochetSound  @ 0014c3b0
void R_RicochetSound(vec_t *pos)

{
  int32 iVar1;
  
  iVar1 = RandomLong(0,4);
  switch(iVar1) {
  case 0:
    S_StartDynamicSound(-1,0,cl_sfx_ric1,pos,1.0,1.0,0,100);
    return;
  case 1:
    S_StartDynamicSound(-1,0,cl_sfx_ric2,pos,1.0,1.0,0,100);
    return;
  case 2:
    S_StartDynamicSound(-1,0,cl_sfx_ric3,pos,1.0,1.0,0,100);
    return;
  case 3:
    S_StartDynamicSound(-1,0,cl_sfx_ric4,pos,1.0,1.0,0,100);
    return;
  case 4:
    S_StartDynamicSound(-1,0,cl_sfx_ric5,pos,1.0,1.0,0,100);
  }
  return;
}


// R_RicochetSprite  @ 0014eb60
void R_RicochetSprite(float *pos,model_t *pmodel,float duration,float scale)

{
  vec_t vVar1;
  TEMPENTITY *pTVar2;
  int32 iVar3;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???] */
  pTVar2 = (*efx.CL_TempEntAlloc)(pos,pmodel);
  if (pTVar2 != (TEMPENTITY *)0x0) {
    (pTVar2->entity).curstate.rendermode = 3;
    (pTVar2->entity).curstate.scale = scale;
    (pTVar2->entity).curstate.renderfx = 0xe;
    (pTVar2->entity).baseline.renderamt = 200;
    (pTVar2->entity).curstate.renderamt = 200;
    pTVar2->flags = 0x80;
    (pTVar2->entity).baseline.origin[0] = 0.0;
    (pTVar2->entity).baseline.origin[1] = 0.0;
    (pTVar2->entity).baseline.origin[2] = 0.0;
    (pTVar2->entity).origin[0] = *pos;
    (pTVar2->entity).origin[1] = pos[1];
    vVar1 = pos[2];
    pTVar2->fadeSpeed = 8.0;
    (pTVar2->entity).origin[2] = vVar1;
    pTVar2->die = (float)cl.time;
    (pTVar2->entity).curstate.frame = 0.0;
    iVar3 = RandomLong(0,7);
    (pTVar2->entity).angles[2] = (float)(iVar3 * 0x2d);
  }
  return;
}


// R_RocketFlare  @ 0014ec50
void R_RocketFlare(float *pos)

{
  int iVar1;
  TEMPENTITY *pTVar2;
  int32 iVar3;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: int frameCount@[???] */
  if (cl.time != cl.oldtime) {
    iVar1 = ModelFrameCount(cl_sprite_glow);
    pTVar2 = (*efx.CL_TempEntAlloc)(pos,cl_sprite_glow);
    if (pTVar2 != (TEMPENTITY *)0x0) {
      pTVar2->frameMax = (float)iVar1;
      (pTVar2->entity).curstate.rendermode = 3;
      (pTVar2->entity).curstate.renderamt = 0xff;
      (pTVar2->entity).curstate.renderfx = 0xe;
      (pTVar2->entity).curstate.framerate = 1.0;
      (pTVar2->entity).origin[0] = *pos;
      (pTVar2->entity).origin[1] = pos[1];
      (pTVar2->entity).origin[2] = pos[2];
      pTVar2->die = (float)((longdouble)0.01 + (longdouble)cl.time);
      iVar3 = RandomLong(0,iVar1 + -1);
      (pTVar2->entity).curstate.frame = (float)iVar3;
      return;
    }
  }
  return;
}


// R_RocketTrail  @ 0019baf0
void R_RocketTrail(vec_t *start,vec_t *end,int type)

{
  vec_t *in;
  float fVar1;
  uint uVar2;
  vec_t vVar3;
  particle_t *ppVar4;
  particle_t *ppVar5;
  short sVar6;
  int32 iVar7;
  int32 iVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  float local_74;
  float local_70;
  double local_64;
  double local_5c;
  float local_50;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: vec3_t vec@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: int dec@[???] */
  local_40 = *end - *start;
  local_3c = end[1] - start[1];
  local_38 = end[2] - start[2];
  local_74 = VectorNormalize(&local_40);
  if (type == 7) {
    VectorMatrix(&local_40,&local_34,&local_28);
    local_70 = 1.0;
  }
  else {
    local_70 = 3.0;
    if (0x7f < type) {
      type = type + -0x80;
      local_70 = 1.0;
    }
  }
  VectorScale(&local_40,local_70,&local_40);
  vVar3 = vec3_origin[1];
  ppVar4 = active_particles;
  ppVar5 = free_particles;
  while ((0.0 < local_74 && (ppVar5 != (particle_t *)0x0))) {
    local_74 = local_74 - local_70;
    free_particles = ppVar5->next;
    vec3_origin[1] = vVar3;
    ppVar5->vel[0] = vec3_origin[0];
    ppVar5->vel[1] = vVar3;
    active_particles = ppVar5;
    ppVar5->next = ppVar4;
    ppVar5->vel[2] = vec3_origin[2];
    ppVar5->die = (float)cl.time + 2.0;
    switch(type) {
    case 0:
      iVar9 = 0;
      iVar7 = RandomLong(0,3);
      ppVar5->type = pt_fire;
      ppVar5->ramp = (float)iVar7;
      ppVar5->color = (short)ramp3[(int)(float)iVar7];
      do {
        fVar11 = start[iVar9];
        fVar10 = RandomFloat(-3.0,3.0);
        ppVar5->org[iVar9] = fVar10 + fVar11;
        iVar9 = iVar9 + 1;
      } while (iVar9 != 3);
      break;
    case 1:
      iVar9 = 0;
      iVar7 = RandomLong(2,5);
      ppVar5->type = pt_fire;
      ppVar5->ramp = (float)iVar7;
      ppVar5->color = (short)ramp3[(int)(float)iVar7];
      do {
        fVar11 = start[iVar9];
        fVar10 = RandomFloat(-3.0,3.0);
        ppVar5->org[iVar9] = fVar10 + fVar11;
        iVar9 = iVar9 + 1;
      } while (iVar9 != 3);
      break;
    case 2:
      iVar9 = 0;
      ppVar5->type = pt_grav;
      iVar7 = RandomLong(0x43,0x4a);
      ppVar5->color = (short)iVar7;
      do {
        fVar11 = start[iVar9];
        fVar10 = RandomFloat(-3.0,3.0);
        ppVar5->org[iVar9] = fVar10 + fVar11;
        iVar9 = iVar9 + 1;
      } while (iVar9 != 3);
      break;
    case 3:
    case 5:
      sVar6 = ((ushort)R_RocketTrail::tracercount & 4) * 2;
      ppVar5->die = (float)cl.time + 0.5;
      ppVar5->type = pt_static;
      if (type == 3) {
        sVar6 = sVar6 + 0x34;
      }
      else {
        sVar6 = sVar6 + 0xe6;
      }
      ppVar5->color = sVar6;
      R_RocketTrail::tracercount = R_RocketTrail::tracercount + 1;
      uVar2 = R_RocketTrail::tracercount & 1;
      ppVar5->org[0] = *start;
      ppVar5->org[1] = start[1];
      ppVar5->org[2] = start[2];
      if (uVar2 == 0) {
        ppVar5->vel[0] = -local_3c * 30.0;
        ppVar5->vel[1] = local_40 * 30.0;
      }
      else {
        ppVar5->vel[0] = local_3c * 30.0;
        ppVar5->vel[1] = -local_40 * 30.0;
      }
      break;
    case 4:
      iVar9 = 0;
      ppVar5->type = pt_grav;
      iVar7 = RandomLong(0x43,0x46);
      ppVar5->color = (short)iVar7;
      do {
        fVar11 = start[iVar9];
        fVar10 = RandomFloat(-3.0,3.0);
        ppVar5->org[iVar9] = fVar10 + fVar11;
        iVar9 = iVar9 + 1;
      } while (iVar9 != 3);
      local_74 = local_74 - 3.0;
      break;
    case 6:
      iVar7 = RandomLong(0,3);
      ppVar5->type = pt_fire;
      ppVar5->ramp = (float)iVar7;
      ppVar5->color = (short)ramp3[(int)(float)iVar7];
      ppVar5->org[0] = *start;
      ppVar5->org[1] = start[1];
      ppVar5->org[2] = start[2];
      break;
    case 7:
                    /* Unresolved local var: float s@[???]
                       Unresolved local var: float c@[???]
                       Unresolved local var: float x@[???]
                       Unresolved local var: float y@[???] */
      in = ppVar5->vel;
      iVar7 = RandomLong(0,0xffff);
      iVar8 = RandomLong(8,0x10);
      sincos((double)iVar7,&local_5c,&local_64);
      fVar11 = (float)local_5c * (float)iVar8;
      local_50 = (float)iVar8 * (float)local_64;
      fVar1 = local_28 * local_50 + local_34 * fVar11 + *start;
      ppVar5->org[0] = fVar1;
      fVar10 = local_24 * local_50 + local_30 * fVar11 + start[1];
      ppVar5->org[1] = fVar10;
      fVar11 = local_50 * local_20 + fVar11 * local_2c + start[2];
      ppVar5->org[2] = fVar11;
      ppVar5->vel[0] = *start - fVar1;
      ppVar5->vel[1] = start[1] - fVar10;
      ppVar5->vel[2] = start[2] - fVar11;
      VectorScale(in,2.0,in);
      fVar11 = RandomFloat(96.0,111.0);
      VectorMA(in,fVar11,&local_40,in);
      ppVar5->die = (float)cl.time + 2.0;
      ppVar5->type = pt_explode2;
      iVar7 = RandomLong(0,3);
      ppVar5->ramp = (float)iVar7;
      ppVar5->color = (short)ramp3[(int)(float)iVar7];
    }
    ppVar5->packedColor = 0;
    *start = local_40 + *start;
    start[1] = local_3c + start[1];
    start[2] = start[2] + local_38;
    vVar3 = vec3_origin[1];
    ppVar4 = active_particles;
    ppVar5 = free_particles;
  }
  vec3_origin[1] = vVar3;
  active_particles = ppVar4;
  free_particles = ppVar5;
  return;
}


// R_RotateForEntity  @ 0017c6d0
void R_RotateForEntity(vec_t *origin,cl_entity_t *e)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  GLfloat local_1c;
  GLfloat local_18;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t angles@[???]
                       Unresolved local var: vec3_t modelpos@[???] */
  fVar1 = *origin;
  fVar2 = origin[1];
  fVar3 = origin[2];
  local_1c = e->angles[2];
  fVar4 = e->angles[0];
  local_18 = e->angles[1];
  if ((e->curstate).movetype != 0) {
                    /* Unresolved local var: float f@[???]
                       Unresolved local var: float d@[???] */
    fVar5 = (e->curstate).animtime;
    if ((fVar5 + 0.2 <= (float)cl.time) || (fVar6 = (e->latched).prevanimtime, fVar5 == fVar6)) {
      fVar5 = 0.0;
    }
    else {
      fVar5 = ((float)cl.time - fVar5) / (fVar5 - fVar6);
    }
    fVar1 = fVar1 - ((e->latched).prevorigin[0] - e->origin[0]) * fVar5;
    fVar2 = fVar2 - ((e->latched).prevorigin[1] - e->origin[1]) * fVar5;
    fVar3 = fVar3 - ((e->latched).prevorigin[2] - e->origin[2]) * fVar5;
    if ((0.0 < fVar5) && (fVar5 < 1.5)) {
      fVar5 = 1.0 - fVar5;
      fVar6 = (e->latched).prevangles[0] - fVar4;
      if (180.0 < fVar6) {
        fVar6 = fVar6 - 360.0;
      }
      else if (fVar6 < -180.0) {
        fVar6 = fVar6 + 360.0;
      }
      fVar4 = fVar6 * fVar5 + fVar4;
      fVar6 = (e->latched).prevangles[1] - e->angles[1];
      if (180.0 < fVar6) {
        fVar6 = fVar6 - 360.0;
      }
      else if (fVar6 < -180.0) {
        fVar6 = fVar6 + 360.0;
      }
      local_18 = fVar6 * fVar5 + local_18;
      fVar6 = (e->latched).prevangles[2] - e->angles[2];
      if (fVar6 <= 180.0) {
        if (fVar6 < -180.0) {
          fVar6 = fVar6 + 360.0;
        }
      }
      else {
        fVar6 = fVar6 - 360.0;
      }
      local_1c = fVar6 * fVar5 + local_1c;
    }
  }
  (*qglTranslatef)(fVar1,fVar2,fVar3);
  (*qglRotatef)(local_18,0.0,0.0,1.0);
  (*qglRotatef)(fVar4,0.0,1.0,0.0);
  (*qglRotatef)(local_1c,1.0,0.0,0.0);
  return;
}


// R_RunParticleEffect  @ 00199fa0
void R_RunParticleEffect(vec_t *org,vec_t *dir,int color,int count)

{
  float *pfVar1;
  double dVar2;
  particle_t *ppVar3;
  int32 iVar4;
  particle_t *ppVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  uint local_28;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: particle_t * p@[???] */
                    /* try { // try from 00199fa4 to 001a9fa8 has its CatchHandler @ 0019a24f */
  if ((0 < count) && (free_particles != (particle_t *)0x0)) {
    local_28 = 0;
    ppVar5 = free_particles;
    do {
      free_particles = ppVar5->next;
      ppVar3 = ppVar5;
      ppVar5->next = active_particles;
      active_particles = ppVar3;
      dVar2 = cl.time;
      iVar6 = ramp1[0];
      if (count == 0x400) {
        ppVar5->die = (float)cl.time + 5.0;
        ppVar5->color = (short)iVar6;
        ppVar5->packedColor = 0;
        iVar4 = RandomLong(0,3);
        ppVar5->ramp = (float)iVar4;
        if ((local_28 & 1) == 0) {
          ppVar5->type = pt_explode2;
          iVar6 = 0;
          do {
            fVar7 = org[iVar6];
            fVar8 = RandomFloat(-16.0,16.0);
            ppVar5->org[iVar6] = fVar8 + fVar7;
            fVar7 = RandomFloat(-256.0,256.0);
            ppVar5->vel[iVar6] = fVar7;
            iVar6 = iVar6 + 1;
          } while (iVar6 != 3);
        }
        else {
          ppVar5->type = pt_explode;
          iVar6 = 0;
          do {
            fVar7 = org[iVar6];
            fVar8 = RandomFloat(-16.0,16.0);
            ppVar5->org[iVar6] = fVar8 + fVar7;
            fVar7 = RandomFloat(-256.0,256.0);
            ppVar5->vel[iVar6] = fVar7;
            iVar6 = iVar6 + 1;
          } while (iVar6 != 3);
        }
      }
      else {
        fVar7 = RandomFloat(0.0,0.4);
        ppVar5->die = (float)dVar2 + fVar7;
                    /* try { // try from 0019a03f to 001aa12f has its CatchHandler @ 0019a2ac */
        iVar4 = RandomLong(0,7);
        ppVar5->packedColor = 0;
        ppVar5->type = pt_slowgrav;
        ppVar5->color = (short)iVar4 + ((ushort)color & 0xfff8);
        iVar6 = 0;
        do {
          fVar7 = org[iVar6];
          fVar8 = RandomFloat(-8.0,8.0);
          ppVar5->org[0] = fVar8 + fVar7;
          pfVar1 = dir + iVar6;
          iVar6 = iVar6 + 1;
          ppVar5->vel[0] = *pfVar1 * 15.0;
          ppVar5 = (particle_t *)(ppVar5->org + 1);
        } while (iVar6 != 3);
      }
      local_28 = local_28 + 1;
    } while ((count != local_28) && (ppVar5 = free_particles, free_particles != (particle_t *)0x0));
  }
  return;
}


// R_SetFogEnabled  @ 0018fa70
void R_SetFogEnabled(qboolean bEnable)

{
  qboolean qVar1;
  int iVar2;
  qboolean qVar3;
  int iVar4;
  GLuint GVar5;
  
  if (bEnable == false) {
    glDisable(0xb60);
  }
  else {
    glEnable();
  }
  qVar1 = R_UseLegacyRender();
  if ((((((qVar1 == 0) && (qglCreateShader != (_func_GLuint_GLenum *)0x0)) &&
        (qglDeleteShader != (_func_void_GLuint *)0x0)) &&
       ((qglShaderSource != (_func_void_GLuint_GLsizei_GLchar_ptr_ptr_GLint_ptr *)0x0 &&
        (qglGetProgramiv != (_func_void_GLuint_GLenum_GLint_ptr *)0x0)))) &&
      ((qglGetProgramInfoLog != (_func_void_GLuint_GLsizei_GLsizei_ptr_GLchar_ptr *)0x0 &&
       ((qglAttachShader != (_func_void_GLuint_GLuint *)0x0 &&
        (qglLinkProgram != (_func_void_GLuint *)0x0)))))) &&
     ((qglCreateProgram != (_func_GLuint *)0x0 &&
      ((qglDeleteProgram != (_func_void_GLuint *)0x0 && (qglUseProgram != (_func_void_GLuint *)0x0))
      )))) {
    R_LoadShaders();
  }
  if (((g_bHasShaderFunctions != false) && (gl_use_shaders.value != 0.0)) &&
     (sv_allow_shaders.value != 0.0)) {
    iVar4 = 0;
                    /* Unresolved local var: int i@[???] */
    qVar3 = g_bHasShaderFunctions;
    do {
      GVar5 = *(GLuint *)((int)g_fsWorldProgram + iVar4);
      if ((GVar5 != 0) && (iVar2 = *(int *)((int)g_nFogEnabledUniformLocation + iVar4), iVar2 != -1)
         ) {
        if (qVar3 != false) {
          if (gl_use_shaders.value == 0.0) {
            GVar5 = 0;
          }
          else if (sv_allow_shaders.value == 0.0) {
            GVar5 = 0;
          }
          if (g_uCurrentProgram != GVar5) {
            (*qglUseProgram)(GVar5);
            iVar2 = *(GLint *)((int)g_nFogEnabledUniformLocation + iVar4);
            g_uCurrentProgram = GVar5;
          }
        }
        (*qglUniform1ui)(iVar2,bEnable);
        qVar3 = g_bHasShaderFunctions;
      }
      iVar4 = iVar4 + 4;
    } while (iVar4 != 0x20);
    if ((qVar3 != false) && (g_uCurrentProgram != 0)) {
      (*qglUseProgram)(0);
      g_uCurrentProgram = 0;
    }
  }
  return;
}


// R_SetFogMode  @ 0018fc00
void R_SetFogMode(int nGLFogMode)

{
  qboolean qVar1;
  int iVar2;
  qboolean qVar3;
  int iVar4;
  GLuint GVar5;
  undefined1 uVar6;
  
  glFogi(0xb65,nGLFogMode);
  qVar1 = R_UseLegacyRender();
  if ((((((qVar1 == 0) && (qglCreateShader != (_func_GLuint_GLenum *)0x0)) &&
        (qglDeleteShader != (_func_void_GLuint *)0x0)) &&
       ((qglShaderSource != (_func_void_GLuint_GLsizei_GLchar_ptr_ptr_GLint_ptr *)0x0 &&
        (qglGetProgramiv != (_func_void_GLuint_GLenum_GLint_ptr *)0x0)))) &&
      ((qglGetProgramInfoLog != (_func_void_GLuint_GLsizei_GLsizei_ptr_GLchar_ptr *)0x0 &&
       ((qglAttachShader != (_func_void_GLuint_GLuint *)0x0 &&
        (qglLinkProgram != (_func_void_GLuint *)0x0)))))) &&
     ((qglCreateProgram != (_func_GLuint *)0x0 &&
      ((qglDeleteProgram != (_func_void_GLuint *)0x0 && (qglUseProgram != (_func_void_GLuint *)0x0))
      )))) {
    R_LoadShaders();
  }
  if (((g_bHasShaderFunctions != false) && (gl_use_shaders.value != 0.0)) &&
     (sv_allow_shaders.value != 0.0)) {
    uVar6 = 2;
    if (nGLFogMode != 0x801) {
      uVar6 = nGLFogMode == 0x800;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int nShaderFogMode@[???] */
    iVar4 = 0;
    qVar3 = g_bHasShaderFunctions;
    do {
      GVar5 = *(GLuint *)((int)g_fsWorldProgram + iVar4);
      if ((GVar5 != 0) && (iVar2 = *(int *)((int)g_nFogModeUniformLocation + iVar4), iVar2 != -1)) {
        if (qVar3 != false) {
          if (gl_use_shaders.value == 0.0) {
            GVar5 = 0;
          }
          else if (sv_allow_shaders.value == 0.0) {
            GVar5 = 0;
          }
          if (g_uCurrentProgram != GVar5) {
            (*qglUseProgram)(GVar5);
            iVar2 = *(GLint *)((int)g_nFogModeUniformLocation + iVar4);
            g_uCurrentProgram = GVar5;
          }
        }
        (*qglUniform1ui)(iVar2,(GLuint)uVar6);
        qVar3 = g_bHasShaderFunctions;
      }
      iVar4 = iVar4 + 4;
    } while (iVar4 != 0x20);
    if ((qVar3 != false) && (g_uCurrentProgram != 0)) {
      (*qglUseProgram)(0);
      g_uCurrentProgram = 0;
    }
  }
  return;
}


// R_SetFrustum  @ 0017e420
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_SetFrustum(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float fovx@[???]
                       Unresolved local var: float fovy@[???]
                       Unresolved local var: float screenaspect@[???] */
  fVar3 = (float)glwidth;
  fVar4 = (float)glheight;
  fVar1 = scr_fov_value;
  if ((gl_widescreen_yfov.value != 0.0) && (fVar2 = fVar3 / fVar4, 1.5 < fVar2)) {
                    /* Unresolved local var: float halfAngleRadians@[???]
                       Unresolved local var: float retDegrees@[???]
                       Unresolved local var: float t@[???] */
    dVar5 = tan((double)(scr_fov_value * 0.008726646));
    dVar5 = atan((double)(fVar2 * 0.75 * (float)dVar5));
    fVar1 = (float)((longdouble)dVar5 * (longdouble)57.29577951308232) +
            (float)((longdouble)dVar5 * (longdouble)57.29577951308232);
  }
                    /* Unresolved local var: float a@[???]
                       Unresolved local var: float x@[???] */
  if ((fVar1 < 1.0) || (179.0 < fVar1)) {
    fVar2 = 1.0;
  }
  else {
    dVar5 = tan((double)((fVar1 / 360.0) * 3.1415927));
    fVar2 = (float)dVar5;
  }
  dVar5 = atan((double)(fVar4 / (fVar3 / fVar2)));
  fVar1 = 90.0 - fVar1 * 0.5;
  RotatePointAroundVector(frustum[0].normal,vup,vpn,-fVar1);
  RotatePointAroundVector(frustum[1].normal,vup,vpn,fVar1);
  fVar1 = 90.0 - (((float)dVar5 * 360.0) / 3.1415927) * 0.5;
  RotatePointAroundVector(frustum[2].normal,vright,vpn,fVar1);
  RotatePointAroundVector(frustum[3].normal,vright,vpn,-fVar1);
                    /* Unresolved local var: int bits@[???]
                       Unresolved local var: int j@[???] */
  frustum[0].type = '\x05';
  frustum[1].type = '\x05';
  frustum[2].type = '\x05';
  frustum[3].type = '\x05';
  frustum[0].dist =
       frustum[0].normal[2] * r_origin[2] +
       frustum[0].normal[0] * r_origin[0] + frustum[0].normal[1] * r_origin[1];
  frustum[0].signbits = frustum[0].normal[0] < 0.0 | 2;
  if (0.0 <= frustum[0].normal[1]) {
    frustum[0].signbits = frustum[0].normal[0] < 0.0;
  }
  if (frustum[0].normal[2] < 0.0) {
    frustum[0].signbits = frustum[0].signbits | 4;
  }
  frustum[1].dist =
       frustum[1].normal[2] * r_origin[2] +
       frustum[1].normal[0] * r_origin[0] + frustum[1].normal[1] * r_origin[1];
  frustum[1].signbits = frustum[1].normal[0] < 0.0 | 2;
  if (0.0 <= frustum[1].normal[1]) {
    frustum[1].signbits = frustum[1].normal[0] < 0.0;
  }
  if (frustum[1].normal[2] < 0.0) {
    frustum[1].signbits = frustum[1].signbits | 4;
  }
  frustum[2].dist =
       frustum[2].normal[2] * r_origin[2] +
       frustum[2].normal[0] * r_origin[0] + frustum[2].normal[1] * r_origin[1];
  frustum[2].signbits = frustum[2].normal[0] < 0.0 | 2;
  if (0.0 <= frustum[2].normal[1]) {
    frustum[2].signbits = frustum[2].normal[0] < 0.0;
  }
  if (frustum[2].normal[2] < 0.0) {
    frustum[2].signbits = frustum[2].signbits | 4;
  }
  frustum[3].dist =
       r_origin[2] * frustum[3].normal[2] +
       r_origin[1] * frustum[3].normal[1] + r_origin[0] * frustum[3].normal[0];
  frustum[3].signbits = frustum[3].normal[0] < 0.0 | 2;
  if (0.0 <= frustum[3].normal[1]) {
    frustum[3].signbits = frustum[3].normal[0] < 0.0;
  }
  if (frustum[3].normal[2] < 0.0) {
    frustum[3].signbits = frustum[3].signbits | 4;
  }
  return;
}


// R_SetRenderMode  @ 001919a0
void R_SetRenderMode(cl_entity_t *pEntity)

{
  int iVar1;
  
  iVar1 = (pEntity->curstate).rendermode;
  if (iVar1 == 0) {
    (*qglColor4f)(1.0,1.0,1.0,1.0);
    return;
  }
  if (iVar1 == 1) {
    (*qglBlendFunc)(0x302,0x303);
    (*qglTexEnvi)(0x2300,0x2200,0x1906);
  }
  else if (iVar1 == 5) {
    (*qglTexEnvf)(0x2300,0x2200,8448.0);
    (*qglBlendFunc)(1,1);
    (*qglColor4f)(r_blend,r_blend,r_blend,1.0);
    (*qglDepthMask)('\0');
  }
  else {
    if (iVar1 == 4) {
      (*qglEnable)(0xbc0);
      (*qglTexEnvf)(0x2300,0x2200,8448.0);
      (*qglColor4f)(1.0,1.0,1.0,1.0);
      (*qglDisable)(0xbe2);
      (*qglAlphaFunc)(0x204,gl_alphamin.value);
      return;
    }
    (*qglTexEnvf)(0x2300,0x2200,8448.0);
    (*qglBlendFunc)(0x302,0x303);
    (*qglColor4f)(1.0,1.0,1.0,r_blend);
    (*qglDepthMask)('\0');
  }
                    /* WARNING: Could not recover jumptable at 0x00191a48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglEnable)(0xbe2);
  return;
}


// R_SetStackBase  @ 001800a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_SetStackBase(void)

{
  return;
}


// R_SetupAliasFrame  @ 0017d440
void R_SetupAliasFrame(int frame,aliashdr_t *paliashdr)

{
  int iVar1;
  int posenum;
  
                    /* Unresolved local var: int pose@[???]
                       Unresolved local var: int numposes@[???]
                       Unresolved local var: float interval@[???] */
  if ((paliashdr->numframes <= frame) || (frame < 0)) {
    Con_DPrintf("R_AliasSetupFrame: no such frame %d\n",frame);
    frame = 0;
  }
  iVar1 = paliashdr->frames[frame].numposes;
  posenum = paliashdr->frames[frame].firstpose;
  if (1 < iVar1) {
    posenum = posenum + (int)(cl.time / (double)paliashdr->frames[frame].interval) % iVar1;
  }
  GL_DrawAliasFrame(paliashdr,posenum);
  return;
}


// R_SetupFrame  @ 0017e800
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_SetupFrame(void)

{
  qboolean in_stack_ffffffc4;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  
  if (1 < cl.maxclients) {
    R_ForceCVars(in_stack_ffffffc4);
  }
  R_CheckVariables();
  R_AnimateLight();
  r_framecount = r_framecount + 1;
  r_origin[0] = r_refdef.vieworg[0];
  r_origin[1] = r_refdef.vieworg[1];
  r_origin[2] = r_refdef.vieworg[2];
  AngleVectors(r_refdef.viewangles,vpn,vright,vup);
  r_oldviewleaf = r_viewleaf;
  r_viewleaf = Mod_PointInLeaf(r_origin,cl.worldmodel);
  if ((2 < cl.waterlevel) && (r_refdef.onlyClientDraws == false)) {
                    /* Unresolved local var: float[4] fogColor@[???] */
    local_1c = (float)cshift_water.destcolor[0] / 255.0;
    local_10 = 0x3f800000;
    local_18 = (float)cshift_water.destcolor[1] / 255.0;
    local_14 = (float)cshift_water.destcolor[2] / 255.0;
    R_SetFogMode(0x2601);
    (*qglFogfv)(0xb66,&local_1c);
    (*qglFogf)(0xb63,0.0);
    (*qglFogf)(0xb64,(float)(cshift_water.percent * -4 + 0x600));
    R_SetFogEnabled(true);
  }
  V_CalcBlend();
  r_cache_thrash = false;
  c_brush_polys = 0;
  c_alias_polys = 0;
  return;
}


// R_SetupGL  @ 0017ead0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_SetupGL(void)

{
  int iVar1;
  GLsizei GVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
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
  float fVar20;
  float fVar21;
  double dVar22;
  
                    /* Unresolved local var: float screenaspect@[???]
                       Unresolved local var: float xfov@[???]
                       Unresolved local var: float yfov@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int x2@[???]
                       Unresolved local var: int y2@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int glwidth@[???]
                       Unresolved local var: int glheight@[???] */
  if (gl_mtexable != 0) {
    (*qglMatrixMode)(0x1702);
    (*qglSelectTextureSGIS)(TEXTURE0_SGIS);
    (*qglLoadIdentity)();
    (*qglSelectTextureSGIS)(TEXTURE1_SGIS);
    (*qglLoadIdentity)();
    (*qglSelectTextureSGIS)(TEXTURE2_SGIS);
    (*qglLoadIdentity)();
    (*qglSelectTextureSGIS)(TEXTURE0_SGIS);
  }
  (*qglMatrixMode)(0x1701);
  (*qglLoadIdentity)();
  uVar4 = glheight - (r_refdef.vrect.y + r_refdef.vrect.height);
  iVar1 = r_refdef.vrect.x - (uint)(0 < r_refdef.vrect.x);
  iVar3 = (uVar4 - 1) + (uint)(uVar4 < 0x80000000);
  if (envmap == false) {
    GVar2 = (r_refdef.vrect.width + r_refdef.vrect.x +
            (uint)(r_refdef.vrect.width + r_refdef.vrect.x < glwidth)) - iVar1;
    iVar5 = ((glheight - r_refdef.vrect.y) + (uint)(glheight - r_refdef.vrect.y < glheight)) - iVar3
    ;
  }
  else {
    GVar2 = (GLsizei)gl_envmapsize.value;
    iVar3 = 0;
    iVar1 = 0;
    iVar5 = GVar2;
    glheight = GVar2;
    glwidth = GVar2;
  }
  (*qglViewport)(iVar1 + glx,iVar3 + gly,GVar2,iVar5);
  fVar8 = (float)r_refdef.vrect.width;
  fVar7 = (float)r_refdef.vrect.height;
  fVar6 = fVar8 / fVar7;
  fVar9 = scr_fov_value;
  if ((gl_widescreen_yfov.value != 0.0) && (1.5 < fVar6)) {
                    /* Unresolved local var: float halfAngleRadians@[???]
                       Unresolved local var: float retDegrees@[???]
                       Unresolved local var: float t@[???] */
    dVar22 = tan((double)(scr_fov_value * 0.008726646));
    dVar22 = atan((double)(fVar6 * 0.75 * (float)dVar22));
    fVar9 = (float)((longdouble)dVar22 * (longdouble)57.29577951308232) +
            (float)((longdouble)dVar22 * (longdouble)57.29577951308232);
  }
                    /* Unresolved local var: float a@[???]
                       Unresolved local var: float x@[???] */
  if ((fVar9 < 1.0) || (179.0 < fVar9)) {
    fVar9 = 1.0;
  }
  else {
    dVar22 = tan((double)((fVar9 / 360.0) * 3.1415927));
    fVar9 = (float)dVar22;
  }
  dVar22 = atan((double)(fVar7 / (fVar8 / fVar9)));
  fVar7 = ((float)dVar22 * 360.0) / 3.1415927;
  if (r_refdef.onlyClientDraws == false) {
    iVar1 = CL_IsDevOverviewMode();
    if (iVar1 == 0) {
                    /* Unresolved local var: GLdouble xmin@[???]
                       Unresolved local var: GLdouble xmax@[???]
                       Unresolved local var: GLdouble ymin@[???]
                       Unresolved local var: GLdouble ymax@[???] */
      dVar22 = tan(((double)fVar7 * 3.141592653589793) / 360.0);
      dVar22 = dVar22 * 4.0;
      (*qglFrustum)(-dVar22 * (double)fVar6,dVar22 * (double)fVar6,-dVar22,dVar22,4.0,
                    (double)movevars.zmax);
    }
    else {
      iVar1 = (int)(4096.0 / (fVar6 * gDevOverview.zoom));
      (*qglOrtho)((double)-(int)(4096.0 / gDevOverview.zoom),
                  (double)(int)(4096.0 / gDevOverview.zoom),(double)-iVar1,(double)iVar1,
                  (double)(16000.0 - gDevOverview.z_min),(double)(16000.0 - gDevOverview.z_max));
    }
  }
  else {
                    /* Unresolved local var: GLdouble xmin@[???]
                       Unresolved local var: GLdouble xmax@[???]
                       Unresolved local var: GLdouble ymin@[???]
                       Unresolved local var: GLdouble ymax@[???] */
    dVar22 = tan((double)((fVar7 * 3.1415927) / 360.0));
    dVar22 = dVar22 * 4.0;
    (*qglFrustum)(-dVar22 * (double)fVar6,dVar22 * (double)fVar6,-dVar22,dVar22,4.0,16000.0);
  }
  if (mirror == false) {
    (*qglCullFace)(0x404);
  }
  else {
    if (mirror_plane->normal[2] == 0.0) {
      (*qglScalef)(-1.0,1.0,1.0);
    }
    else {
      (*qglScalef)(1.0,-1.0,1.0);
    }
    (*qglCullFace)(0x405);
  }
  (*qglGetFloatv)(0xba7,gProjectionMatrix);
  (*qglMatrixMode)(0x1700);
  (*qglLoadIdentity)();
  (*qglRotatef)(-90.0,1.0,0.0,0.0);
  (*qglRotatef)(90.0,0.0,0.0,1.0);
  (*qglRotatef)(-r_refdef.viewangles[2],1.0,0.0,0.0);
  (*qglRotatef)(-r_refdef.viewangles[0],0.0,1.0,0.0);
  (*qglRotatef)(-r_refdef.viewangles[1],0.0,0.0,1.0);
  (*qglTranslatef)(-r_refdef.vieworg[0],-r_refdef.vieworg[1],-r_refdef.vieworg[2]);
  (*qglGetFloatv)(0xba6,r_world_matrix);
  if (gl_cull.value == 0.0) {
    (*qglDisable)(0xb44);
  }
  else {
    (*qglEnable)(0xb44);
  }
  (*qglDisable)(0xbe2);
  (*qglDisable)(0xbc0);
  (*qglEnable)(0xb71);
  fVar18 = (float)r_world_matrix._0_8_;
  fVar19 = SUB84(r_world_matrix._0_8_,4);
  fVar20 = (float)r_world_matrix._8_8_;
  fVar21 = SUB84(r_world_matrix._8_8_,4);
  fVar14 = (float)r_world_matrix._16_8_;
  fVar15 = SUB84(r_world_matrix._16_8_,4);
  fVar16 = (float)r_world_matrix._24_8_;
  fVar17 = SUB84(r_world_matrix._24_8_,4);
  fVar10 = (float)r_world_matrix._32_8_;
  fVar11 = SUB84(r_world_matrix._32_8_,4);
  fVar12 = (float)r_world_matrix._40_8_;
  fVar13 = SUB84(r_world_matrix._40_8_,4);
  fVar6 = (float)r_world_matrix._48_8_;
  fVar7 = SUB84(r_world_matrix._48_8_,4);
  fVar8 = (float)r_world_matrix._56_8_;
  fVar9 = SUB84(r_world_matrix._56_8_,4);
  if (gl_flipmatrix.value == 0.0) {
    gWorldToScreen[2] =
         fVar21 * gProjectionMatrix[0xe] +
         fVar20 * gProjectionMatrix[10] +
         fVar18 * gProjectionMatrix[2] + 0.0 + fVar19 * gProjectionMatrix[6];
    gWorldToScreen[3] =
         fVar21 * gProjectionMatrix[0xf] +
         fVar20 * gProjectionMatrix[0xb] +
         fVar18 * gProjectionMatrix[3] + 0.0 + fVar19 * gProjectionMatrix[7];
    gWorldToScreen[1] =
         fVar21 * gProjectionMatrix[0xd] +
         fVar20 * gProjectionMatrix[9] +
         fVar18 * gProjectionMatrix[1] + 0.0 + fVar19 * gProjectionMatrix[5];
    gWorldToScreen[0] =
         fVar21 * gProjectionMatrix[0xc] +
         fVar20 * gProjectionMatrix[8] +
         fVar18 * gProjectionMatrix[0] + 0.0 + fVar19 * gProjectionMatrix[4];
    gWorldToScreen[4] =
         fVar17 * gProjectionMatrix[0xc] +
         fVar16 * gProjectionMatrix[8] +
         fVar14 * gProjectionMatrix[0] + 0.0 + fVar15 * gProjectionMatrix[4];
    gWorldToScreen[5] =
         fVar17 * gProjectionMatrix[0xd] +
         fVar16 * gProjectionMatrix[9] +
         fVar14 * gProjectionMatrix[1] + 0.0 + fVar15 * gProjectionMatrix[5];
    gWorldToScreen[6] =
         fVar17 * gProjectionMatrix[0xe] +
         fVar16 * gProjectionMatrix[10] +
         fVar14 * gProjectionMatrix[2] + 0.0 + fVar15 * gProjectionMatrix[6];
    gWorldToScreen[7] =
         fVar17 * gProjectionMatrix[0xf] +
         fVar16 * gProjectionMatrix[0xb] +
         fVar14 * gProjectionMatrix[3] + 0.0 + fVar15 * gProjectionMatrix[7];
    gWorldToScreen[10] =
         fVar13 * gProjectionMatrix[0xe] +
         fVar12 * gProjectionMatrix[10] +
         fVar10 * gProjectionMatrix[2] + 0.0 + fVar11 * gProjectionMatrix[6];
    gWorldToScreen[0xb] =
         fVar13 * gProjectionMatrix[0xf] +
         fVar12 * gProjectionMatrix[0xb] +
         fVar10 * gProjectionMatrix[3] + 0.0 + fVar11 * gProjectionMatrix[7];
    gWorldToScreen[9] =
         fVar13 * gProjectionMatrix[0xd] +
         fVar12 * gProjectionMatrix[9] +
         fVar10 * gProjectionMatrix[1] + 0.0 + fVar11 * gProjectionMatrix[5];
    gWorldToScreen[8] =
         fVar13 * gProjectionMatrix[0xc] +
         fVar12 * gProjectionMatrix[8] +
         fVar10 * gProjectionMatrix[0] + 0.0 + fVar11 * gProjectionMatrix[4];
    gWorldToScreen[0xd] =
         fVar9 * gProjectionMatrix[0xd] +
         gProjectionMatrix[1] * fVar6 + 0.0 + gProjectionMatrix[5] * fVar7 +
         gProjectionMatrix[9] * fVar8;
    gWorldToScreen[0xc] =
         fVar9 * gProjectionMatrix[0xc] +
         gProjectionMatrix[0] * fVar6 + 0.0 + gProjectionMatrix[4] * fVar7 +
         gProjectionMatrix[8] * fVar8;
    gWorldToScreen[0xf] =
         fVar9 * gProjectionMatrix[0xf] +
         SUB124(SUB1612((undefined1  [16])0x0,4),8) + gProjectionMatrix[3] * fVar6 +
         gProjectionMatrix[7] * fVar7 + gProjectionMatrix[0xb] * fVar8;
    gWorldToScreen[0xe] =
         fVar9 * gProjectionMatrix[0xe] +
         gProjectionMatrix[2] * fVar6 + 0.0 + gProjectionMatrix[6] * fVar7 +
         gProjectionMatrix[10] * fVar8;
  }
  else {
    gWorldToScreen[4] =
         gProjectionMatrix[3] * fVar7 +
         gProjectionMatrix[0] * fVar19 + 0.0 + gProjectionMatrix[1] * fVar15 +
         gProjectionMatrix[2] * fVar11;
    gWorldToScreen[5] =
         gProjectionMatrix[6] * fVar11 +
         gProjectionMatrix[4] * fVar19 + 0.0 + gProjectionMatrix[5] * fVar15 +
         gProjectionMatrix[7] * fVar7;
    gWorldToScreen[2] =
         gProjectionMatrix[0xb] * fVar6 +
         gProjectionMatrix[9] * fVar14 + gProjectionMatrix[8] * fVar18 + 0.0 +
         gProjectionMatrix[10] * fVar10;
    gWorldToScreen[6] =
         gProjectionMatrix[0xb] * fVar7 +
         gProjectionMatrix[9] * fVar15 + gProjectionMatrix[8] * fVar19 + 0.0 +
         gProjectionMatrix[10] * fVar11;
    gWorldToScreen[10] =
         gProjectionMatrix[0xb] * fVar8 +
         gProjectionMatrix[9] * fVar16 + gProjectionMatrix[8] * fVar20 + 0.0 +
         gProjectionMatrix[10] * fVar12;
    gWorldToScreen[3] =
         fVar6 * gProjectionMatrix[0xf] +
         fVar10 * gProjectionMatrix[0xe] +
         fVar14 * gProjectionMatrix[0xd] + fVar18 * gProjectionMatrix[0xc] + 0.0;
    gWorldToScreen[7] =
         fVar7 * gProjectionMatrix[0xf] +
         fVar11 * gProjectionMatrix[0xe] +
         fVar15 * gProjectionMatrix[0xd] + fVar19 * gProjectionMatrix[0xc] + 0.0;
    gWorldToScreen[0xb] =
         fVar8 * gProjectionMatrix[0xf] +
         fVar12 * gProjectionMatrix[0xe] +
         fVar16 * gProjectionMatrix[0xd] + fVar20 * gProjectionMatrix[0xc] + 0.0;
    gWorldToScreen[1] =
         gProjectionMatrix[6] * fVar10 +
         gProjectionMatrix[4] * fVar18 + 0.0 + gProjectionMatrix[5] * fVar14 +
         gProjectionMatrix[7] * fVar6;
    gWorldToScreen[0] =
         gProjectionMatrix[3] * fVar6 +
         gProjectionMatrix[0] * fVar18 + 0.0 + gProjectionMatrix[1] * fVar14 +
         gProjectionMatrix[2] * fVar10;
    gWorldToScreen[9] =
         gProjectionMatrix[6] * fVar12 +
         gProjectionMatrix[4] * fVar20 + 0.0 + gProjectionMatrix[5] * fVar16 +
         gProjectionMatrix[7] * fVar8;
    gWorldToScreen[8] =
         gProjectionMatrix[3] * fVar8 +
         gProjectionMatrix[0] * fVar20 + 0.0 + gProjectionMatrix[1] * fVar16 +
         gProjectionMatrix[2] * fVar12;
    gWorldToScreen[0xf] =
         fVar9 * gProjectionMatrix[0xf] +
         fVar13 * gProjectionMatrix[0xe] +
         fVar17 * gProjectionMatrix[0xd] +
         SUB124(SUB1612((undefined1  [16])0x0,4),8) + fVar21 * gProjectionMatrix[0xc];
    gWorldToScreen[0xe] =
         gProjectionMatrix[0xb] * fVar9 +
         gProjectionMatrix[9] * fVar17 + gProjectionMatrix[8] * fVar21 + 0.0 +
         gProjectionMatrix[10] * fVar13;
    gWorldToScreen[0xd] =
         gProjectionMatrix[6] * fVar13 +
         gProjectionMatrix[4] * fVar21 + 0.0 + gProjectionMatrix[5] * fVar17 +
         gProjectionMatrix[7] * fVar9;
    gWorldToScreen[0xc] =
         gProjectionMatrix[3] * fVar9 +
         gProjectionMatrix[0] * fVar21 + 0.0 + gProjectionMatrix[1] * fVar17 +
         gProjectionMatrix[2] * fVar13;
  }
  InvertMatrix(gWorldToScreen,gScreenToWorld);
  return;
}


// R_ShowLine  @ 0019b370
void R_ShowLine(vec_t *start,vec_t *end)

{
  vec_t vVar1;
  particle_t *ppVar2;
  particle_t *ppVar3;
  float fVar4;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: vec3_t vec@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: int dec@[???]
                       Unresolved local var: int tracercount@[???] */
  local_18 = *end - *start;
  local_14 = end[1] - start[1];
  local_10 = end[2] - start[2];
  fVar4 = VectorNormalize(&local_18);
  VectorScale(&local_18,5.0,&local_18);
  vVar1 = vec3_origin[1];
  ppVar2 = active_particles;
  ppVar3 = free_particles;
  while ((0.0 < fVar4 && (ppVar3 != (particle_t *)0x0))) {
    fVar4 = fVar4 - 5.0;
    free_particles = ppVar3->next;
    vec3_origin[1] = vVar1;
    ppVar3->vel[0] = vec3_origin[0];
    ppVar3->vel[1] = vVar1;
    active_particles = ppVar3;
    ppVar3->next = ppVar2;
    ppVar3->vel[2] = vec3_origin[2];
    ppVar3->die = (float)cl.time + 30.0;
    ppVar3->color = 0x4b;
    ppVar3->packedColor = 0;
    ppVar3->type = pt_static;
    ppVar3->org[0] = *start;
    ppVar3->org[1] = start[1];
    ppVar3->org[2] = start[2];
    *start = *start + local_18;
    start[1] = start[1] + local_14;
    start[2] = start[2] + local_10;
    vVar1 = vec3_origin[1];
    ppVar2 = active_particles;
    ppVar3 = free_particles;
  }
  vec3_origin[1] = vVar1;
  active_particles = ppVar2;
  free_particles = ppVar3;
  return;
}


// R_SparkEffect  @ 0014e830
void R_SparkEffect(float *pos,int count,int velocityMin,int velocityMax)

{
  _func_void_float_ptr_model_s_ptr_float_float *UNRECOVERED_JUMPTABLE;
  float fVar1;
  
  (*efx.R_SparkStreaks)(pos,count,velocityMin,velocityMax);
  UNRECOVERED_JUMPTABLE = efx.R_RicochetSprite;
  fVar1 = RandomFloat(0.5,1.0);
                    /* WARNING: Could not recover jumptable at 0x0014e8a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pos,cl_sprite_ricochet,0.1,fVar1);
  return;
}


// R_SparkShower  @ 0014d820
void R_SparkShower(float *pos)

{
  TEMPENTITY *pTVar1;
  float fVar2;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???] */
  pTVar1 = (*efx.CL_TempEntAllocNoModel)(pos);
  if (pTVar1 != (TEMPENTITY *)0x0) {
    fVar2 = RandomFloat(-300.0,300.0);
    (pTVar1->entity).baseline.origin[0] = fVar2;
    fVar2 = RandomFloat(-300.0,300.0);
    (pTVar1->entity).baseline.origin[1] = fVar2;
    fVar2 = RandomFloat(-200.0,200.0);
    pTVar1->flags = pTVar1->flags | 0x20028;
    (pTVar1->entity).baseline.angles[0] = 0.0;
    (pTVar1->entity).baseline.angles[1] = 0.0;
    (pTVar1->entity).baseline.angles[2] = 0.0;
    (pTVar1->entity).baseline.origin[2] = fVar2;
    pTVar1->die = (float)cl.time + 0.5;
    fVar2 = RandomFloat(0.5,1.5);
    (pTVar1->entity).curstate.framerate = fVar2;
    (pTVar1->entity).curstate.scale = (float)cl.time;
  }
  return;
}


// R_SparkStreaks  @ 0019a750
void R_SparkStreaks(vec_t *pos,int count,int velocityMin,int velocityMax)

{
  double dVar1;
  particle_t *ppVar2;
  int iVar3;
  particle_t *ppVar4;
  int iVar5;
  float fVar6;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: particle_t * p@[???] */
  if ((0 < count) && (free_particles != (particle_t *)0x0)) {
    iVar5 = 0;
    ppVar4 = free_particles;
    do {
      free_particles = ppVar4->next;
      iVar3 = 0;
      ppVar2 = ppVar4;
      ppVar4->next = gpActiveTracers;
      gpActiveTracers = ppVar2;
      dVar1 = cl.time;
      fVar6 = RandomFloat(0.1,0.5);
      ppVar4->die = (float)dVar1 + fVar6;
      ppVar4->color = 5;
      ppVar4->packedColor = 0xff;
      ppVar4->type = pt_grav;
      ppVar4->ramp = 0.5;
      do {
        ppVar4->org[iVar3] = pos[iVar3];
        fVar6 = RandomFloat((float)velocityMin,(float)velocityMax);
        ppVar4->vel[iVar3] = fVar6;
        iVar3 = iVar3 + 1;
      } while (iVar3 != 3);
      iVar5 = iVar5 + 1;
    } while ((count != iVar5) && (ppVar4 = free_particles, free_particles != (particle_t *)0x0));
  }
  return;
}


// R_SplitEntityOnNode  @ 001a3540
void R_SplitEntityOnNode(mnode_t *node)

{
  byte bVar1;
  msurface_t *pmVar2;
  mplane_t *p;
  efrag_s *peVar3;
  uint uVar4;
  
                    /* Unresolved local var: efrag_t * ef@[???]
                       Unresolved local var: mplane_t * splitplane@[???]
                       Unresolved local var: mleaf_t * leaf@[???]
                       Unresolved local var: int sides@[???] */
  pmVar2 = (msurface_t *)node->contents;
  peVar3 = cl.free_efrags;
  do {
    if (pmVar2 == (msurface_t *)0xfffffffe) {
      cl.free_efrags = peVar3;
      return;
    }
    cl.free_efrags = peVar3;
    if ((int)pmVar2 < 0) {
      if (r_pefragtopnode == (mnode_t *)0x0) {
        r_pefragtopnode = node;
      }
      if (peVar3 == (efrag_s *)0x0) {
        Con_Printf("Too many efrags!\n");
        return;
      }
      cl.free_efrags = peVar3->entnext;
      peVar3->entity = (cl_entity_s_conflict *)r_addent;
      *lastlink = peVar3;
      lastlink = &peVar3->entnext;
      peVar3->entnext = (efrag_s *)0x0;
      peVar3->leaf = (mleaf_s *)node;
      peVar3->leafnext = ((mleaf_s *)node)->efrags;
      ((mleaf_s *)node)->efrags = peVar3;
      return;
    }
    p = (mplane_t *)((mleaf_s *)node)->compressed_vis;
    bVar1 = p->type;
    if (bVar1 < 3) {
      if (p->dist <= r_emins[bVar1]) {
        uVar4 = 0;
        goto LAB_001a3576;
      }
      if (p->dist < r_emaxs[bVar1]) goto LAB_001a3567;
    }
    else {
      uVar4 = BoxOnPlaneSide(r_emins,r_emaxs,p);
      if (uVar4 == 3) {
LAB_001a3567:
        if (r_pefragtopnode == (mnode_t *)0x0) {
          r_pefragtopnode = node;
        }
        uVar4 = 2;
      }
      else {
        if ((uVar4 & 1) == 0) {
          if ((uVar4 & 2) == 0) {
            return;
          }
          goto LAB_001a3585;
        }
        uVar4 = uVar4 & 2;
      }
LAB_001a3576:
      R_SplitEntityOnNode((mnode_t *)((mleaf_s *)node)->efrags);
      if (uVar4 == 0) {
        return;
      }
    }
LAB_001a3585:
    node = (mnode_t *)((mleaf_s *)node)->firstmarksurface;
    pmVar2 = (msurface_t *)((mleaf_s *)node)->contents;
    peVar3 = cl.free_efrags;
  } while( true );
}


// R_Spray  @ 0014dca0
void R_Spray(vec_t *pos,vec_t *dir,int modelIndex,int count,int speed,int spread,int rendermode)

{
  vec_t *in;
  vec_t vVar1;
  uint uVar2;
  float flHigh;
  float flHigh_00;
  model_t *model;
  int iVar3;
  TEMPENTITY *pTVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: model_t * pModel@[???]
                       Unresolved local var: float noise@[???]
                       Unresolved local var: float znoise@[???]
                       Unresolved local var: int frameCount@[???]
                       Unresolved local var: int i@[???] */
  flHigh = (float)spread / 100.0;
  flHigh_00 = flHigh * 1.5;
  if (1.0 < flHigh_00) {
    flHigh_00 = 1.0;
  }
  model = CL_GetModelByIndex(modelIndex);
  if (model != (model_t *)0x0) {
    iVar5 = 0;
    iVar3 = ModelFrameCount(model);
    iVar3 = iVar3 + -1;
    if (0 < count) {
      do {
        pTVar4 = (*efx.CL_TempEntAlloc)(pos,model);
        if (pTVar4 == (TEMPENTITY *)0x0) {
          return;
        }
        (pTVar4->entity).curstate.renderfx = 0xe;
        (pTVar4->entity).baseline.renderamt = 0xff;
        (pTVar4->entity).curstate.framerate = 1.0;
        (pTVar4->entity).curstate.rendermode = rendermode;
        (pTVar4->entity).curstate.renderamt = 0xff;
        uVar2 = pTVar4->flags;
        pTVar4->flags = uVar2 | 0x28;
        if (iVar3 < 2) {
          pTVar4->die = (float)((longdouble)0.35 + (longdouble)cl.time);
        }
        else {
          pTVar4->flags = uVar2 | 0x128;
          (pTVar4->entity).curstate.framerate = 10.0;
          pTVar4->die = (float)iVar3 * 0.1 + (float)cl.time;
        }
        iVar5 = iVar5 + 1;
        fVar7 = *dir;
        fVar6 = RandomFloat(-flHigh,flHigh);
        (pTVar4->entity).baseline.origin[0] = fVar6 + fVar7;
        fVar7 = dir[1];
        fVar6 = RandomFloat(-flHigh,flHigh);
        (pTVar4->entity).baseline.origin[1] = fVar6 + fVar7;
        fVar7 = dir[2];
        fVar6 = RandomFloat(0.0,flHigh_00);
        (pTVar4->entity).baseline.origin[2] = fVar6 + fVar7;
        fVar7 = RandomFloat((float)speed * 0.8,(float)speed * 1.2);
        in = (pTVar4->entity).baseline.origin;
        VectorScale(in,fVar7,in);
        (pTVar4->entity).origin[0] = *pos;
        (pTVar4->entity).origin[1] = pos[1];
        vVar1 = pos[2];
        (pTVar4->entity).curstate.frame = 0.0;
        pTVar4->frameMax = (float)iVar3;
        (pTVar4->entity).origin[2] = vVar1;
      } while (count != iVar5);
    }
    return;
  }
  Con_Printf("No model %d!\n");
  return;
}


// R_SpriteColor  @ 00153820
void R_SpriteColor(colorVec *pColor,cl_entity_t *pEntity,int alpha)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
                    /* Unresolved local var: int a@[???] */
  iVar1 = 0x100;
  if (((pEntity->curstate).rendermode - 3U & 0xfffffffd) == 0) {
    iVar1 = alpha;
  }
  if ((*(uint *)&(pEntity->curstate).rendercolor & 0xffffff) != 0) {
    uVar3 = (int)((uint)(pEntity->curstate).rendercolor.r * iVar1) >> 8;
    pColor->r = uVar3;
    uVar4 = (int)((uint)(pEntity->curstate).rendercolor.g * iVar1) >> 8;
    pColor->g = uVar4;
    uVar2 = (int)(iVar1 * (uint)(pEntity->curstate).rendercolor.b) >> 8;
    bVar5 = filterMode != false;
    pColor->b = uVar2;
    if (bVar5) {
      pColor->r = (int)((float)uVar3 * filterColorRed);
      pColor->g = (int)((float)uVar4 * filterColorGreen);
      pColor->b = (int)((float)uVar2 * filterColorBlue);
    }
    return;
  }
  uVar2 = iVar1 * 0xff >> 8;
  pColor->b = uVar2;
  pColor->g = uVar2;
  pColor->r = uVar2;
  return;
}


// R_Sprite_Explode  @ 0014f300
void R_Sprite_Explode(TEMPENTITY *pTemp,float scale,int flags)

{
  float fVar1;
  
  if (pTemp != (TEMPENTITY *)0x0) {
    fVar1 = (pTemp->entity).origin[2];
    (pTemp->entity).curstate.scale = scale;
    (pTemp->entity).curstate.renderamt = (-(uint)((flags & 1U) == 0) & 0xffffffb5) + 0xff;
    (pTemp->entity).curstate.rendermode = -(uint)((flags & 1U) == 0) & 5;
    (pTemp->entity).origin[2] = fVar1 + 10.0;
    (pTemp->entity).curstate.renderfx = 0;
    (pTemp->entity).baseline.origin[2] = 8.0;
    (pTemp->entity).curstate.rendercolor.r = '\0';
    (pTemp->entity).curstate.rendercolor.g = '\0';
    (pTemp->entity).curstate.rendercolor.b = '\0';
  }
  return;
}


// R_Sprite_Smoke  @ 0014f280
void R_Sprite_Smoke(TEMPENTITY *pTemp,float scale)

{
  float fVar1;
  byte bVar2;
  int32 iVar3;
  
  if (pTemp != (TEMPENTITY *)0x0) {
    (pTemp->entity).curstate.rendermode = 4;
    (pTemp->entity).curstate.renderamt = 0xff;
    (pTemp->entity).curstate.renderfx = 0;
    (pTemp->entity).baseline.origin[2] = 30.0;
    iVar3 = RandomLong(0x14,0x23);
    (pTemp->entity).curstate.scale = scale;
    fVar1 = (pTemp->entity).origin[2];
    bVar2 = (byte)iVar3;
    (pTemp->entity).curstate.rendercolor.r = bVar2;
    (pTemp->entity).curstate.rendercolor.g = bVar2;
    (pTemp->entity).curstate.rendercolor.b = bVar2;
    (pTemp->entity).origin[2] = fVar1 + 20.0;
  }
  return;
}


// R_Sprite_Spray  @ 0014da80
void R_Sprite_Spray(vec_t *pos,vec_t *dir,int modelIndex,int count,int speed,int iRand)

{
  vec_t *in;
  float flHigh;
  float flHigh_00;
  model_t *model;
  int iVar1;
  int32 iVar2;
  TEMPENTITY *pTVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: model_t * pModel@[???]
                       Unresolved local var: float noise@[???]
                       Unresolved local var: float znoise@[???]
                       Unresolved local var: int frameCount@[???]
                       Unresolved local var: int i@[???] */
  flHigh = (float)iRand / 100.0;
  flHigh_00 = flHigh * 1.5;
  if (1.0 < flHigh_00) {
    flHigh_00 = 1.0;
  }
  model = CL_GetModelByIndex(modelIndex);
  if (model != (model_t *)0x0) {
    iVar4 = 0;
    iVar1 = ModelFrameCount(model);
    if (0 < count) {
      do {
        pTVar3 = (*efx.CL_TempEntAlloc)(pos,model);
        if (pTVar3 == (TEMPENTITY *)0x0) {
          return;
        }
        pTVar3->flags = pTVar3->flags | 0x88;
        iVar4 = iVar4 + 1;
        (pTVar3->entity).curstate.rendermode = 4;
        (pTVar3->entity).curstate.renderamt = 0xff;
        (pTVar3->entity).baseline.renderamt = 0xff;
        (pTVar3->entity).curstate.renderfx = 0xe;
        (pTVar3->entity).curstate.framerate = 0.5;
        pTVar3->fadeSpeed = 2.0;
        fVar6 = *dir;
        fVar5 = RandomFloat(-flHigh,flHigh);
        (pTVar3->entity).baseline.origin[0] = fVar5 + fVar6;
        fVar6 = dir[1];
        fVar5 = RandomFloat(-flHigh,flHigh);
        (pTVar3->entity).baseline.origin[1] = fVar5 + fVar6;
        fVar6 = dir[2];
        fVar5 = RandomFloat(0.0,flHigh_00);
        (pTVar3->entity).baseline.origin[2] = fVar5 + fVar6;
        fVar6 = RandomFloat((float)speed * 0.8,(float)speed * 1.2);
        in = (pTVar3->entity).baseline.origin;
        VectorScale(in,fVar6,in);
        (pTVar3->entity).origin[0] = *pos;
        (pTVar3->entity).origin[1] = pos[1];
        (pTVar3->entity).origin[2] = pos[2];
        pTVar3->die = (float)((longdouble)0.35 + (longdouble)cl.time);
        iVar2 = RandomLong(0,iVar1 + -1);
        (pTVar3->entity).curstate.frame = (float)iVar2;
      } while (count != iVar4);
    }
    return;
  }
  Con_Printf("No model %d!\n");
  return;
}


// R_Sprite_Trail  @ 0014ce40
void R_Sprite_Trail(int type,vec_t *start,vec_t *end,int modelIndex,int count,float life,float size,
                   float amplitude,int renderamt,float speed)

{
  float fVar1;
  float fVar2;
  model_t *model;
  int iVar3;
  int32 iVar4;
  TEMPENTITY *pTVar5;
  int iVar6;
  float fVar7;
  float local_40;
  float local_3c;
  float local_38;
  vec_t local_34 [3];
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: TEMPENTITY * ptemp@[???]
                       Unresolved local var: model_t * model@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int frameCount@[???]
                       Unresolved local var: vec3_t delta@[???]
                       Unresolved local var: vec3_t pos@[???]
                       Unresolved local var: vec3_t dir@[???] */
  model = CL_GetModelByIndex(modelIndex);
  if (model != (model_t *)0x0) {
    iVar3 = ModelFrameCount(model);
    local_40 = *end - *start;
    local_3c = end[1] - start[1];
    local_38 = end[2] - start[2];
    local_28 = local_40;
    local_24 = local_3c;
    local_20 = local_38;
    VectorNormalize(&local_28);
    fVar1 = amplitude * 0.00390625;
    if (0 < count) {
      iVar6 = 0;
      do {
        if (iVar6 == 0) {
          VectorMA(start,0.0,&local_40,local_34);
        }
        else {
          VectorMA(start,(float)iVar6 / ((float)count - 1.0),&local_40,local_34);
        }
        pTVar5 = (*efx.CL_TempEntAlloc)(local_34,model);
        if (pTVar5 == (TEMPENTITY *)0x0) {
          return;
        }
        iVar6 = iVar6 + 1;
        pTVar5->flags = pTVar5->flags | 0x8a8;
        VectorScale(&local_28,speed,(pTVar5->entity).baseline.origin);
        iVar4 = RandomLong(-0x7f,0x80);
        (pTVar5->entity).baseline.origin[0] =
             (float)iVar4 * fVar1 + (pTVar5->entity).baseline.origin[0];
        iVar4 = RandomLong(-0x7f,0x80);
        (pTVar5->entity).baseline.origin[1] =
             (float)iVar4 * fVar1 + (pTVar5->entity).baseline.origin[1];
        iVar4 = RandomLong(-0x7f,0x80);
        (pTVar5->entity).curstate.renderamt = renderamt;
        (pTVar5->entity).curstate.scale = size;
        (pTVar5->entity).curstate.rendermode = 3;
        (pTVar5->entity).curstate.renderfx = 0xe;
        (pTVar5->entity).baseline.origin[2] =
             (float)iVar4 * fVar1 + (pTVar5->entity).baseline.origin[2];
        fVar2 = (float)cl.time;
        fVar7 = RandomFloat(0.0,4.0);
        pTVar5->die = life + fVar2 + fVar7;
        iVar4 = RandomLong(0,iVar3 + -1);
        (pTVar5->entity).baseline.renderamt = renderamt;
        (pTVar5->entity).curstate.rendercolor.r = 0xff;
        (pTVar5->entity).curstate.rendercolor.g = 0xff;
        (pTVar5->entity).curstate.rendercolor.b = 0xff;
        (pTVar5->entity).curstate.frame = (float)iVar4;
        pTVar5->frameMax = (float)iVar3;
      } while (count != iVar6);
    }
  }
  return;
}


// R_Sprite_WallPuff  @ 0014f380
void R_Sprite_WallPuff(TEMPENTITY *pTemp,float scale)

{
  int32 iVar1;
  
  if (pTemp != (TEMPENTITY *)0x0) {
    (pTemp->entity).curstate.rendermode = 4;
    (pTemp->entity).curstate.scale = scale;
    (pTemp->entity).curstate.renderamt = 0xff;
    (pTemp->entity).curstate.renderfx = 0;
    (pTemp->entity).curstate.rendercolor.r = '\0';
    (pTemp->entity).curstate.rendercolor.g = '\0';
    (pTemp->entity).curstate.rendercolor.b = '\0';
    pTemp->die = (float)((longdouble)0.01 + (longdouble)cl.time);
    iVar1 = RandomLong(0,0x167);
    (pTemp->entity).curstate.frame = 0.0;
    (pTemp->entity).angles[2] = (float)iVar1;
  }
  return;
}


// R_StoreEfrags  @ 001a3730
void R_StoreEfrags(efrag_t **ppefrag)

{
  efrag_t *peVar1;
  cl_entity_s *ent;
  modtype_t mVar2;
  int iVar3;
  
                    /* Unresolved local var: cl_entity_t * pent@[???]
                       Unresolved local var: model_t * clmodel@[???]
                       Unresolved local var: efrag_t * pefrag@[???] */
  peVar1 = *ppefrag;
  while( true ) {
    if (peVar1 == (efrag_t *)0x0) {
      return;
    }
    ent = (cl_entity_s *)peVar1->entity;
    mVar2 = ent->model->type;
    if (mod_alias < mVar2) break;
    if (((ent->visframe != r_framecount) && (cl_numvisedicts < 0x200)) &&
       (iVar3 = ClientDLL_AddEntity(4,ent), iVar3 != 0)) {
      ent->visframe = r_framecount;
    }
    peVar1 = peVar1->leafnext;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("R_StoreEfrags: Bad entity type %d\n",mVar2);
}


// R_StreakSplash  @ 0019ab70
void R_StreakSplash(vec_t *pos,vec_t *dir,int color,int count,float speed,int velocityMin,
                   int velocityMax)

{
  double dVar1;
  particle_t *ppVar2;
  particle_t *ppVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  int local_40;
  vec_t local_28 [6];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: vec3_t initialVelocity@[???] */
  VectorScale(dir,speed,local_28);
  if ((0 < count) && (free_particles != (particle_t *)0x0)) {
    local_40 = 0;
    ppVar3 = free_particles;
    do {
      free_particles = ppVar3->next;
      iVar4 = 0;
      ppVar2 = ppVar3;
      ppVar3->next = gpActiveTracers;
      gpActiveTracers = ppVar2;
      dVar1 = cl.time;
      fVar5 = RandomFloat(0.1,0.5);
      ppVar3->die = (float)dVar1 + fVar5;
      ppVar3->color = (short)color;
      ppVar3->packedColor = 0xff;
      ppVar3->type = pt_grav;
      ppVar3->ramp = 1.0;
      do {
        ppVar3->org[iVar4] = pos[iVar4];
        fVar5 = local_28[iVar4];
        fVar6 = RandomFloat((float)velocityMin,(float)velocityMax);
        ppVar3->vel[iVar4] = fVar6 + fVar5;
        iVar4 = iVar4 + 1;
      } while (iVar4 != 3);
      local_40 = local_40 + 1;
    } while ((count != local_40) && (ppVar3 = free_particles, free_particles != (particle_t *)0x0));
  }
  return;
}


// R_StudioAbsBB  @ 000d7af0
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioAbsBB(void)

{
  float fVar1;
  studiohdr_t *psVar2;
  int iVar3;
  int extraout_ECX;
  int extraout_ECX_00;
  int iVar4;
  int iVar5;
  int (*paiVar6) [4];
  float *normal;
  float local_7c [5];
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: float lv@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: vec_t[8][3] p@[???]
                       Unresolved local var: mstudiobone_t * pbones@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???] */
  psVar2 = pstudiohdr;
  iVar3 = (currententity->curstate).sequence * 0xb0 + pstudiohdr->seqindex;
  (*tri.RenderMode)(5);
  (*tri.SpriteTexture)(cl_sprite_white,0);
  local_18 = currententity->origin[0];
  local_14 = currententity->origin[1];
  local_10 = currententity->origin[2];
  local_7c[4] = *(float *)((int)psVar2->max + iVar3 + 8) + local_18;
  local_68 = *(float *)((int)psVar2->bbmin + iVar3) + local_14;
  local_64 = *(float *)((int)psVar2->bbmin + iVar3 + 4) + local_10;
  local_60 = *(float *)((int)psVar2->min + iVar3 + 8) + local_18;
  local_54 = *(float *)((int)psVar2->max + iVar3 + 8) + local_18;
  local_50 = *(float *)((int)psVar2->max + iVar3) + local_14;
  local_48 = *(float *)((int)psVar2->min + iVar3 + 8) + local_18;
  local_44 = *(float *)((int)psVar2->max + iVar3) + local_14;
  local_40 = *(float *)((int)psVar2->bbmin + iVar3 + 4) + local_10;
  local_3c = *(float *)((int)psVar2->max + iVar3 + 8) + local_18;
  local_38 = *(float *)((int)psVar2->bbmin + iVar3) + local_14;
  local_34 = *(float *)((int)psVar2->max + iVar3 + 4) + local_10;
  local_30 = *(float *)((int)psVar2->min + iVar3 + 8) + local_18;
  local_2c = *(float *)((int)psVar2->bbmin + iVar3) + local_14;
  local_28 = *(float *)((int)psVar2->max + iVar3 + 4) + local_10;
  local_24 = *(float *)((int)psVar2->max + iVar3 + 8) + local_18;
  local_20 = *(float *)((int)psVar2->max + iVar3) + local_14;
  local_1c = *(float *)((int)psVar2->max + iVar3 + 4) + local_10;
  local_18 = local_18 + *(float *)((int)psVar2->min + iVar3 + 8);
  iVar5 = 0;
  local_14 = *(float *)((int)psVar2->max + iVar3) + local_14;
  local_10 = local_10 + *(float *)((int)psVar2->max + iVar3 + 4);
  local_5c = local_68;
  local_58 = local_64;
  local_4c = local_64;
  (*tri.Begin)(2);
  normal = (vec_t *)0x3f000000;
  (*tri.Color4f)(0.5,0.5,1.0,1.0);
  iVar3 = extraout_ECX;
  paiVar6 = boxpnt;
  do {
    iVar4 = iVar5 % 3;
    fVar1 = 1.0;
    if (2 < iVar5) {
      fVar1 = -1.0;
    }
    iVar5 = iVar5 + 1;
    local_7c[3] = 0.0;
    local_7c[2] = 0.0;
    local_7c[1] = 0.0;
    local_7c[iVar4 + 1] = fVar1;
    R_StudioLighting(local_7c,(int)(local_7c + 1),iVar3,normal);
    (*tri.Brightness)(local_7c[0]);
    (*tri.Vertex3fv)(local_7c + (*paiVar6)[0] * 3 + 4);
    (*tri.Vertex3fv)(local_7c + (*paiVar6)[1] * 3 + 4);
    (*tri.Vertex3fv)(local_7c + (*paiVar6)[2] * 3 + 4);
    normal = local_7c + (*paiVar6)[3] * 3 + 4;
    (*tri.Vertex3fv)(normal);
    iVar3 = extraout_ECX_00;
    paiVar6 = paiVar6 + 1;
  } while (iVar5 != 6);
  (*tri.End)();
  (*tri.RenderMode)(0);
  return;
}


// R_StudioAccumulateBoneVerts  @ 000e3380
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


// R_StudioBodyVariations  @ 000db280
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


// R_StudioBoundBone  @ 000e32b0
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


// R_StudioBoundVertex  @ 000e31e0
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


// R_StudioCalcAttachments  @ 000dfa50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioCalcAttachments(void)

{
  int iVar1;
  int iVar2;
  vec_t *in1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: mstudioattachment_t * pattachment@[???] */
  if (4 < pstudiohdr->numattachments) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Too many attachments on %s\n",currententity->model);
  }
  iVar1 = 0;
  in1 = (vec_t *)(pstudiohdr->name + pstudiohdr->attachmentindex + 0x20);
  if (0 < pstudiohdr->numattachments) {
    do {
      iVar2 = iVar1 + 1;
      VectorTransform(in1,lighttransform[(int)in1[-1]],currententity->attachment[iVar1]);
      iVar1 = iVar2;
      in1 = in1 + 0x16;
    } while (iVar2 < pstudiohdr->numattachments);
  }
  return;
}


// R_StudioCalcBoneAdj  @ 000d9600
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
LAB_000d9700:
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
        goto LAB_000d9700;
      }
      pcVar5 = pcVar5 + 0x18;
      adj[iVar8] = local_24 * 0.017453292;
      iVar8 = iVar8 + 1;
    } while (iVar8 < psVar4->numbonecontrollers);
  }
  return;
}


// R_StudioCalcBonePosition  @ 000d9a40
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
LAB_000d9af6:
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
          goto LAB_000d9af6;
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


// R_StudioCalcBoneQuaterion  @ 000d9870
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
          if (iVar6 < (int)uVar9) goto LAB_000d999e;
          fVar3 = (float)*(short *)(pbVar5 + uVar4 * 2 + 4);
          *local_60 = fVar3;
        }
      }
      else {
        fVar1 = (float)*(short *)(pbVar5 + uVar4 * 2);
        local_54[iVar10] = fVar1;
        fVar3 = fVar1;
        if (iVar6 + 1 < (int)uVar9) {
LAB_000d999e:
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


// R_StudioCalcRotations  @ 000dc2e0
void R_StudioCalcRotations
               (vec3_t *pos,vec4_t *q,mstudioseqdesc_t *pseqdesc,mstudioanim_t *panim,float f)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  studiohdr_t *psVar4;
  uint uVar5;
  int iVar6;
  mstudiobone_t *pbone;
  vec3_t *pos_00;
  float local_50;
  int local_4c;
  float local_3c [11];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int frame@[???]
                       Unresolved local var: mstudiobone_t * pbone@[???]
                       Unresolved local var: float s@[???]
                       Unresolved local var: float[8] adj@[???]
                       Unresolved local var: float dadt@[DW_OP_reg11(ST0)] */
  psVar4 = pstudiohdr;
  if ((float)(pseqdesc->numframes + -1) < f) {
    local_4c = 0;
    local_50 = 0.0;
  }
  else if (f < -0.01) {
                    /* Unresolved local var: float dadt@[???] */
    local_4c = 0;
                    /* Unresolved local var: float dadt@[???] */
    local_50 = -0.01;
  }
  else {
    local_4c = (int)f;
    local_50 = f - (float)local_4c;
  }
  if ((r_dointerp == 0) ||
     (fVar1 = (currententity->curstate).animtime,
     fVar1 < (currententity->latched).prevanimtime + 0.01)) {
    fVar1 = 1.0;
  }
  else {
    fVar1 = ((float)cl.time - fVar1) / 0.1;
    if (2.0 < fVar1) {
      fVar1 = 2.0;
    }
  }
  iVar2 = pstudiohdr->boneindex;
  pcVar3 = pstudiohdr->name;
  R_StudioCalcBoneAdj(fVar1,local_3c,(currententity->curstate).controller,
                      (currententity->latched).prevcontroller,(currententity->mouth).mouthopen);
  if (0 < psVar4->numbones) {
    iVar6 = 0;
    pbone = (mstudiobone_t *)(pcVar3 + iVar2 + -8);
    pos_00 = pos;
    do {
      R_StudioCalcBoneQuaterion(local_4c,local_50,pbone,panim,local_3c,*q);
      R_StudioCalcBonePosition(local_4c,local_50,pbone,panim,local_3c,*pos_00);
      iVar6 = iVar6 + 1;
      q = q + 1;
      pbone = pbone + 1;
      pos_00 = pos_00 + 1;
      panim = panim + 1;
    } while (iVar6 < pstudiohdr->numbones);
  }
  uVar5 = pseqdesc->motiontype;
  if ((uVar5 & 1) != 0) {
    pos[pseqdesc->motionbone][0] = 0.0;
    uVar5 = pseqdesc->motiontype;
  }
  if ((uVar5 & 2) != 0) {
    pos[pseqdesc->motionbone][1] = 0.0;
    uVar5 = pseqdesc->motiontype;
  }
  if ((uVar5 & 4) != 0) {
    pos[pseqdesc->motionbone][2] = 0.0;
    uVar5 = pseqdesc->motiontype;
  }
  fVar1 = ((1.0 - local_50) / (float)pseqdesc->numframes) * 0.0 *
          (currententity->curstate).framerate;
  if ((uVar5 & 0x40) != 0) {
    pos[pseqdesc->motionbone][0] =
         pseqdesc->linearmovement[0] * fVar1 + pos[pseqdesc->motionbone][0];
    uVar5 = pseqdesc->motiontype;
  }
  if ((uVar5 & 0x80) != 0) {
    pos[pseqdesc->motionbone][1] =
         pseqdesc->linearmovement[1] * fVar1 + pos[pseqdesc->motionbone][1];
    uVar5 = pseqdesc->motiontype;
  }
  if ((uVar5 & 0x100) != 0) {
    pos[pseqdesc->motionbone][2] =
         fVar1 * pseqdesc->linearmovement[2] + pos[pseqdesc->motionbone][2];
  }
  return;
}


// R_StudioChangePlayerModel  @ 000df490
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioChangePlayerModel(void)

{
  int iVar1;
  skin_t (*pasVar2) [11];
  int iVar3;
  cl_entity_t *pcVar4;
  skin_t *psVar5;
  
  pcVar4 = currententity;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: skin_t * pskin@[???] */
  iVar3 = r_remapindex;
  iVar1 = currententity->index;
                    /* Unresolved local var: skin_t * pskin@[???] */
  psVar5 = pDM_RemapSkin[iVar1][0];
  if ((psVar5 == (skin_t *)0x0) || (iVar1 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex];
    r_remapindex = (r_remapindex + 1) % 0x40;
    pDM_RemapSkin[iVar1][0] = psVar5;
    DM_RemapSkin[iVar3][0].keynum = iVar1;
    DM_RemapSkin[iVar3][0].topcolor = -1;
    DM_RemapSkin[iVar3][0].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar1 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar1][1];
  if ((psVar5 == (skin_t *)0x0) || (iVar1 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 1;
    r_remapindex = (r_remapindex + 1) % 0x40;
    pDM_RemapSkin[iVar1][1] = psVar5;
    DM_RemapSkin[iVar3][1].keynum = iVar1;
    DM_RemapSkin[iVar3][1].topcolor = -1;
    DM_RemapSkin[iVar3][1].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar1 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar1][2];
  if ((psVar5 == (skin_t *)0x0) || (iVar1 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 2;
    r_remapindex = (r_remapindex + 1) % 0x40;
    pDM_RemapSkin[iVar1][2] = psVar5;
    DM_RemapSkin[iVar3][2].keynum = iVar1;
    DM_RemapSkin[iVar3][2].topcolor = -1;
    DM_RemapSkin[iVar3][2].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar1 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar1][3];
  if ((psVar5 == (skin_t *)0x0) || (iVar1 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 3;
    pasVar2 = DM_RemapSkin + r_remapindex;
    r_remapindex = (r_remapindex + 1) % 0x40;
    (*pasVar2)[3].keynum = iVar1;
    pDM_RemapSkin[iVar1][3] = psVar5;
    DM_RemapSkin[iVar3][3].topcolor = -1;
    DM_RemapSkin[iVar3][3].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar1 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar1][4];
  if ((psVar5 == (skin_t *)0x0) || (iVar1 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 4;
    r_remapindex = (r_remapindex + 1) % 0x40;
    pDM_RemapSkin[iVar1][4] = psVar5;
    DM_RemapSkin[iVar3][4].keynum = iVar1;
    DM_RemapSkin[iVar3][4].topcolor = -1;
    DM_RemapSkin[iVar3][4].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar1 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar1][5];
  if ((psVar5 == (skin_t *)0x0) || (iVar1 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 5;
    r_remapindex = (r_remapindex + 1) % 0x40;
    pDM_RemapSkin[iVar1][5] = psVar5;
    DM_RemapSkin[iVar3][5].keynum = iVar1;
    DM_RemapSkin[iVar3][5].topcolor = -1;
    DM_RemapSkin[iVar3][5].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar1 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar1][6];
  if ((psVar5 == (skin_t *)0x0) || (iVar1 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 6;
    pasVar2 = DM_RemapSkin + r_remapindex;
    r_remapindex = (r_remapindex + 1) % 0x40;
    (*pasVar2)[6].keynum = iVar1;
    pDM_RemapSkin[iVar1][6] = psVar5;
    DM_RemapSkin[iVar3][6].topcolor = -1;
    DM_RemapSkin[iVar3][6].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar1 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar1][7];
  if ((psVar5 == (skin_t *)0x0) || (iVar1 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 7;
    r_remapindex = (r_remapindex + 1) % 0x40;
    pDM_RemapSkin[iVar1][7] = psVar5;
    DM_RemapSkin[iVar3][7].keynum = iVar1;
    DM_RemapSkin[iVar3][7].topcolor = -1;
    DM_RemapSkin[iVar3][7].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar1 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar1][8];
  if ((psVar5 == (skin_t *)0x0) || (iVar1 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 8;
    r_remapindex = (r_remapindex + 1) % 0x40;
    pDM_RemapSkin[iVar1][8] = psVar5;
    DM_RemapSkin[iVar3][8].keynum = iVar1;
    DM_RemapSkin[iVar3][8].topcolor = -1;
    DM_RemapSkin[iVar3][8].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar1 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar1][9];
  if ((psVar5 == (skin_t *)0x0) || (iVar1 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 9;
    pasVar2 = DM_RemapSkin + r_remapindex;
    r_remapindex = (r_remapindex + 1) % 0x40;
    (*pasVar2)[9].keynum = iVar1;
    pDM_RemapSkin[iVar1][9] = psVar5;
    DM_RemapSkin[iVar3][9].topcolor = -1;
    DM_RemapSkin[iVar3][9].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar1 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar1][10];
  if ((psVar5 == (skin_t *)0x0) || (iVar1 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 10;
    r_remapindex = (r_remapindex + 1) % 0x40;
    pDM_RemapSkin[iVar1][10] = psVar5;
    DM_RemapSkin[iVar3][10].keynum = iVar1;
    DM_RemapSkin[iVar3][10].topcolor = -1;
    DM_RemapSkin[iVar3][10].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  return;
}


// R_StudioCheckBBox  @ 000d81f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean R_StudioCheckBBox(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  studiohdr_t *psVar7;
  int iVar8;
  uint uVar9;
  qboolean qVar10;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  mplane_t local_20;
  
                    /* Unresolved local var: mplane_t plane@[???]
                       Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???] */
  iVar8 = VectorCompare(vec3_origin,pstudiohdr->bbmin);
  if (iVar8 == 0) {
    local_38 = pstudiohdr->bbmin[0] + currententity->origin[0];
    local_34 = pstudiohdr->bbmin[1] + currententity->origin[1];
    local_30 = pstudiohdr->bbmin[2] + currententity->origin[2];
    local_2c = pstudiohdr->bbmax[0] + currententity->origin[0];
    local_28 = pstudiohdr->bbmax[1] + currententity->origin[1];
    local_24 = pstudiohdr->bbmax[2] + currententity->origin[2];
  }
  else {
    iVar8 = VectorCompare(vec3_origin,pstudiohdr->min);
    if (iVar8 == 0) {
      local_38 = pstudiohdr->min[0] + currententity->origin[0];
      local_34 = pstudiohdr->min[1] + currententity->origin[1];
      local_30 = pstudiohdr->min[2] + currententity->origin[2];
      local_2c = pstudiohdr->max[0] + currententity->origin[0];
      local_28 = pstudiohdr->max[1] + currententity->origin[1];
      local_24 = pstudiohdr->max[2] + currententity->origin[2];
    }
    else {
      local_38 = currententity->origin[0] - 16.0;
      local_34 = currententity->origin[1] - 16.0;
      local_30 = currententity->origin[2] - 16.0;
      local_2c = currententity->origin[0] + 16.0;
      local_28 = currententity->origin[1] + 16.0;
      local_24 = currententity->origin[2] + 16.0;
    }
  }
  psVar7 = pstudiohdr;
  iVar8 = (currententity->curstate).sequence;
  if (iVar8 < pstudiohdr->numseq) {
    iVar8 = iVar8 * 0xb0;
  }
  else {
    (currententity->curstate).sequence = 0;
    iVar8 = 0;
  }
  iVar8 = iVar8 + psVar7->seqindex;
  uVar9 = 0;
  fVar4 = local_24;
  do {
    if ((uVar9 & 1) == 0) {
      fVar1 = *(float *)((int)psVar7->max + iVar8 + 8);
      if ((uVar9 & 2) != 0) goto LAB_000d832b;
LAB_000d841b:
      fVar2 = *(float *)((int)psVar7->bbmin + iVar8);
      if ((uVar9 & 4) != 0) goto LAB_000d8336;
LAB_000d8426:
      fVar3 = *(float *)((int)psVar7->bbmin + iVar8 + 4);
    }
    else {
                    /* Unresolved local var: vec3_t p1@[???]
                       Unresolved local var: vec3_t p2@[???] */
      fVar1 = *(float *)((int)psVar7->min + iVar8 + 8);
      if ((uVar9 & 2) == 0) goto LAB_000d841b;
LAB_000d832b:
      fVar2 = *(float *)((int)psVar7->max + iVar8);
      if ((uVar9 & 4) == 0) goto LAB_000d8426;
LAB_000d8336:
      fVar3 = *(float *)((int)psVar7->max + iVar8 + 4);
    }
    fVar6 = rotationmatrix[0][2] * fVar3 +
            rotationmatrix[0][1] * fVar2 + rotationmatrix[0][0] * fVar1 + rotationmatrix[0][3];
    fVar5 = rotationmatrix[1][2] * fVar3 +
            rotationmatrix[1][1] * fVar2 + rotationmatrix[1][0] * fVar1 + rotationmatrix[1][3];
    fVar1 = fVar3 * rotationmatrix[2][2] +
            fVar2 * rotationmatrix[2][1] + fVar1 * rotationmatrix[2][0] + rotationmatrix[2][3];
    if (fVar6 < local_38) {
      local_38 = fVar6;
    }
    if (local_2c < fVar6) {
      local_2c = fVar6;
    }
    if (fVar5 < local_34) {
      local_34 = fVar5;
    }
    if (local_28 < fVar5) {
      local_28 = fVar5;
    }
    if (fVar1 < local_30) {
      local_30 = fVar1;
    }
    if (fVar4 < fVar1) {
      local_24 = fVar1;
      fVar4 = fVar1;
    }
    uVar9 = uVar9 + 1;
    if (uVar9 == 8) {
      qVar10 = Host_IsSinglePlayerGame();
      if ((qVar10 == false) && (r_cullsequencebox.value != 0.0)) {
        qVar10 = R_CullBox(&local_38,&local_2c);
        if (qVar10 != false) {
          return false;
        }
      }
      else {
        local_20.normal[0] = vpn[0];
        local_20.type = '\x05';
        local_20.normal[1] = vpn[1];
        local_20.normal[2] = vpn[2];
        local_20.dist = vpn[2] * r_origin[2] + vpn[1] * r_origin[1] + vpn[0] * r_origin[0];
        iVar8 = SignbitsForPlane(&local_20);
        local_20.signbits = (byte)iVar8;
        iVar8 = BoxOnPlaneSide(&local_38,&local_2c,&local_20);
        if (iVar8 == 2) {
          return false;
        }
      }
      return true;
    }
  } while( true );
}


// R_StudioChrome  @ 000ddef0
void R_StudioChrome(int *pchrome,int bone,vec_t *normal)

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
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float n@[???] */
  if (chromeage[bone] != r_smodels_total) {
                    /* Unresolved local var: vec3_t chromeupvec@[???]
                       Unresolved local var: vec3_t chromerightvec@[???]
                       Unresolved local var: vec3_t tmp@[???] */
    VectorScale(g_ChromeOrigin,-1.0,&local_28);
    local_28 = local_28 + lighttransform[bone][0][3];
    local_24 = local_24 + lighttransform[bone][1][3];
    local_20 = local_20 + lighttransform[bone][2][3];
    VectorNormalize(&local_28);
    CrossProduct(&local_28,vright,&local_40);
    VectorNormalize(&local_40);
    CrossProduct(&local_40,&local_28,&local_34);
    VectorNormalize(&local_34);
    fVar1 = lighttransform[bone][0][0];
    fVar2 = lighttransform[bone][1][0];
    fVar3 = lighttransform[bone][2][0];
    r_chromeup[bone][0] = local_38 * fVar3 + local_3c * fVar2 + local_40 * fVar1;
    fVar4 = lighttransform[bone][0][1];
    fVar5 = lighttransform[bone][1][1];
    fVar6 = lighttransform[bone][2][1];
    r_chromeup[bone][1] = fVar6 * local_38 + local_3c * fVar5 + local_40 * fVar4;
    fVar7 = lighttransform[bone][0][2];
    fVar8 = lighttransform[bone][1][2];
    fVar9 = lighttransform[bone][2][2];
    r_chromeup[bone][2] = local_38 * fVar9 + local_3c * fVar8 + local_40 * fVar7;
    r_chromeright[bone][0] = fVar3 * local_2c + fVar2 * local_30 + fVar1 * local_34;
    r_chromeright[bone][1] = fVar6 * local_2c + fVar5 * local_30 + fVar4 * local_34;
    r_chromeright[bone][2] = fVar9 * local_2c + fVar8 * local_30 + fVar7 * local_34;
    chromeage[bone] = r_smodels_total;
  }
  *pchrome = (int)((normal[2] * r_chromeright[bone][2] +
                    normal[1] * r_chromeright[bone][1] + *normal * r_chromeright[bone][0] + 1.0) *
                   32.0 * 1024.0);
  pchrome[1] = (int)((normal[2] * r_chromeup[bone][2] +
                      normal[1] * r_chromeup[bone][1] + *normal * r_chromeup[bone][0] + 1.0) * 32.0
                    * 1024.0);
  return;
}


// R_StudioClientEvents  @ 000dc700
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioClientEvents(void)

{
  int *piVar1;
  mstudioseqdesc_t *pseqdesc;
  vec_t vVar2;
  float fVar3;
  float fVar4;
  studiohdr_t *psVar5;
  studiohdr_t *psVar6;
  dlight_t *pdVar7;
  cl_entity_t *pcVar8;
  mstudioevent_s *event;
  int iVar9;
  int iVar10;
  float fVar11;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: mstudioevent_t * pevent@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: float flStart@[???]
                       Unresolved local var: float flEnd@[???] */
  psVar5 = pstudiohdr;
  if (cl.time != cl.oldtime) {
    iVar10 = pstudiohdr->seqindex;
    iVar9 = (currententity->curstate).sequence;
    pcVar8 = currententity;
    if (((currententity->curstate).effects & 2) != 0) {
                    /* Unresolved local var: dlight_t * el@[DW_OP_reg0(EAX)] */
      if (g_bIsTerrorStrike == 0) {
                    /* Unresolved local var: dlight_t * el@[???] */
        pdVar7 = CL_AllocElight(0);
        pdVar7->origin[0] = currententity->attachment[0][0];
        pcVar8 = currententity;
        pdVar7->origin[1] = currententity->attachment[0][1];
        vVar2 = pcVar8->attachment[0][2];
        pdVar7->radius = 16.0;
        pdVar7->decay = 320.0;
        pdVar7->origin[2] = vVar2;
        pdVar7->die = (float)((longdouble)0.05 + (longdouble)cl.time);
        (pdVar7->color).r = 0xff;
        (pdVar7->color).g = 0xc0;
        (pdVar7->color).b = '@';
      }
      else {
        pdVar7 = CL_AllocDlight(0);
        pdVar7->origin[0] = currententity->attachment[0][0];
        pcVar8 = currententity;
        pdVar7->origin[1] = currententity->attachment[0][1];
        vVar2 = pcVar8->attachment[0][2];
        pdVar7->radius = 300.0;
        pdVar7->origin[2] = vVar2;
        pdVar7->die = (float)((longdouble)0.05 + (longdouble)cl.time);
        (pdVar7->color).r = 0xff;
        (pdVar7->color).g = 0xc0;
        (pdVar7->color).b = 0x80;
      }
      piVar1 = &(pcVar8->curstate).effects;
      *piVar1 = *piVar1 & 0xfffffffd;
    }
    psVar6 = pstudiohdr;
    pseqdesc = (mstudioseqdesc_t *)(psVar5->name + iVar10 + iVar9 * 0xb0 + -8);
    iVar10 = pseqdesc->numevents;
    if (iVar10 != 0) {
      iVar9 = pseqdesc->eventindex;
      fVar11 = CL_StudioEstimateFrame(pseqdesc);
      fVar3 = fVar11 - (pcVar8->curstate).framerate * (float)host_frametime * pseqdesc->fps;
      fVar4 = fVar3;
      if (((pcVar8->latched).sequencetime == (pcVar8->curstate).animtime) &&
         (fVar4 = -0.01, (pseqdesc->flags & 1) != 0)) {
        fVar4 = fVar3;
      }
      if (0 < iVar10) {
        event = (mstudioevent_s *)(psVar6->name + iVar9 + -8);
        iVar9 = 0;
        do {
          if (((4999 < event->event) && (fVar4 < (float)event->frame)) &&
             ((float)event->frame <= fVar11)) {
            ClientDLL_StudioEvent(event,currententity);
            iVar10 = pseqdesc->numevents;
          }
          iVar9 = iVar9 + 1;
          event = event + 1;
        } while (iVar9 < iVar10);
      }
    }
  }
  return;
}


// R_StudioComputeBounds  @ 000e35c0
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
              if (iVar19 == 1) goto LAB_000e36dc;
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
LAB_000e36dc:
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
LAB_000e3849:
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
                      goto LAB_000e3849;
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


// R_StudioDrawBones  @ 000d7600
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioDrawBones(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  studiohdr_t *psVar7;
  float *pfVar8;
  int extraout_ECX;
  int iVar9;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_ECX_03;
  uint uVar10;
  int (*paiVar11) [4];
  int iVar12;
  float (*paafVar13) [3] [4];
  vec_t *in;
  int local_c4;
  vec_t *local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  vec_t local_88 [3];
  float local_7c [27];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: float lv@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: vec_t[8][3] p@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t a1@[???]
                       Unresolved local var: mstudiobone_t * pbones@[???] */
  psVar7 = pstudiohdr;
  iVar9 = pstudiohdr->boneindex;
  (*tri.SpriteTexture)(cl_sprite_white,0);
  iVar12 = pstudiohdr->numbones;
  if (0 < iVar12) {
    local_c0 = (vec_t *)(psVar7->name + iVar9 + -8);
    paafVar13 = lighttransform;
    local_c4 = 0;
    do {
      iVar9 = (int)local_c0[8];
      if (iVar9 != -1) {
        local_ac = (*paafVar13)[0][3] - lighttransform[iVar9][0][3];
        local_88[2] = 1.0;
        local_88[1] = 1.0;
        local_88[0] = 1.0;
        local_a8 = (*paafVar13)[1][3] - lighttransform[iVar9][1][3];
        local_a4 = (*paafVar13)[2][3] - lighttransform[iVar9][2][3];
        if (local_ac <= local_a8) {
          if (local_a8 <= local_a4) goto LAB_000d7ac0;
          local_88[1] = 0.0;
        }
        else if (local_a4 < local_ac) {
          local_88[0] = 0.0;
        }
        else {
LAB_000d7ac0:
          local_88[2] = 0.0;
        }
        CrossProduct(&local_ac,local_88,&local_a0);
        VectorNormalize(&local_a0);
        CrossProduct(&local_ac,&local_a0,&local_94);
        VectorNormalize(&local_94);
        VectorScale(&local_a0,2.0,&local_a0);
        VectorScale(&local_94,2.0,&local_94);
        uVar10 = 0;
        fVar1 = lighttransform[iVar9][0][3];
        fVar2 = lighttransform[iVar9][1][3];
        fVar3 = lighttransform[iVar9][2][3];
        pfVar8 = local_7c;
        do {
          *pfVar8 = fVar1;
          pfVar8[1] = fVar2;
          pfVar8[2] = fVar3;
          if ((uVar10 & 1) == 0) {
            *pfVar8 = fVar1 + local_a0;
            pfVar8[1] = fVar2 + local_9c;
            pfVar8[2] = local_98 + fVar3;
            if ((uVar10 & 2) == 0) goto LAB_000d785f;
LAB_000d77d1:
            fVar4 = *pfVar8 - local_94;
            *pfVar8 = fVar4;
            fVar5 = pfVar8[1] - local_90;
            pfVar8[1] = fVar5;
            fVar6 = pfVar8[2] - local_8c;
            pfVar8[2] = fVar6;
          }
          else {
            *pfVar8 = fVar1 - local_a0;
            pfVar8[1] = fVar2 - local_9c;
            pfVar8[2] = fVar3 - local_98;
            if ((uVar10 & 2) != 0) goto LAB_000d77d1;
LAB_000d785f:
            fVar4 = local_94 + *pfVar8;
            *pfVar8 = fVar4;
            fVar5 = local_90 + pfVar8[1];
            pfVar8[1] = fVar5;
            fVar6 = local_8c + pfVar8[2];
            pfVar8[2] = fVar6;
          }
          if ((uVar10 & 4) == 0) {
            *pfVar8 = fVar4 + local_ac;
            pfVar8[1] = fVar5 + local_a8;
            pfVar8[2] = fVar6 + local_a4;
          }
          uVar10 = uVar10 + 1;
          pfVar8 = pfVar8 + 3;
        } while (uVar10 != 8);
        iVar12 = 0;
        VectorNormalize(&local_ac);
        VectorNormalize(&local_a0);
        VectorNormalize(&local_94);
        (*tri.Begin)(2);
        (*tri.Color4f)(1.0,1.0,1.0,1.0);
        in = (float *)0x0;
        (*tri.TexCoord2f)(0.0,0.0);
        iVar9 = extraout_ECX_01;
        paiVar11 = boxpnt;
        do {
          switch(iVar12) {
          default:
            local_b8 = local_a0;
            local_b4 = local_9c;
            local_b0 = local_98;
            break;
          case 1:
            local_b8 = local_94;
            local_b4 = local_90;
            local_b0 = local_8c;
            break;
          case 2:
            local_b8 = local_ac;
            local_b4 = local_a8;
            local_b0 = local_a4;
            break;
          case 3:
            in = &local_a0;
            VectorScale(in,-1.0,&local_b8);
            iVar9 = extraout_ECX_02;
            break;
          case 4:
            in = &local_94;
            VectorScale(in,-1.0,&local_b8);
            iVar9 = extraout_ECX;
            break;
          case 5:
            in = &local_ac;
            VectorScale(in,-1.0,&local_b8);
            iVar9 = extraout_ECX_03;
          }
          iVar12 = iVar12 + 1;
          R_StudioLighting(&local_bc,(int)&local_b8,iVar9,in);
          (*tri.Brightness)(local_bc);
          (*tri.Vertex3fv)(local_7c + (*paiVar11)[0] * 3);
          (*tri.Vertex3fv)(local_7c + (*paiVar11)[1] * 3);
          (*tri.Vertex3fv)(local_7c + (*paiVar11)[2] * 3);
          in = local_7c + (*paiVar11)[3] * 3;
          (*tri.Vertex3fv)(in);
          iVar9 = extraout_ECX_00;
          paiVar11 = paiVar11 + 1;
        } while (iVar12 != 6);
        (*tri.End)();
        iVar12 = pstudiohdr->numbones;
      }
      local_c4 = local_c4 + 1;
      paafVar13 = paafVar13 + 1;
      local_c0 = local_c0 + 0x1c;
    } while (local_c4 < iVar12);
  }
  return;
}


// R_StudioDrawHulls  @ 000d7d50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioDrawHulls(void)

{
  vec_t vVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  vec_t *out;
  int (*paiVar7) [4];
  char *pcVar8;
  int local_98;
  vec_t local_88;
  float local_84;
  float local_80;
  vec_t local_7c [27];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: float lv@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: vec_t[8][3] p@[???]
                       Unresolved local var: mstudiobbox_t * pbbox@[???] */
  pcVar8 = pstudiohdr->name + pstudiohdr->hitboxindex + -8;
  (*tri.SpriteTexture)(cl_sprite_white,0);
  if (0 < pstudiohdr->numhitboxes) {
    local_98 = 0;
    do {
      uVar5 = 0;
      out = local_7c;
      do {
        if ((uVar5 & 1) == 0) {
          local_88 = *(vec_t *)(pcVar8 + 0x14);
          if ((uVar5 & 2) != 0) goto LAB_000d7dbc;
LAB_000d7e06:
          local_84 = *(float *)(pcVar8 + 0x18);
          if ((uVar5 & 4) != 0) goto LAB_000d7dc8;
LAB_000d7e12:
          local_80 = *(float *)(pcVar8 + 0x1c);
        }
        else {
          local_88 = *(vec_t *)(pcVar8 + 8);
          if ((uVar5 & 2) == 0) goto LAB_000d7e06;
LAB_000d7dbc:
          local_84 = *(float *)(pcVar8 + 0xc);
          if ((uVar5 & 4) == 0) goto LAB_000d7e12;
LAB_000d7dc8:
          local_80 = *(float *)(pcVar8 + 0x10);
        }
        uVar5 = uVar5 + 1;
        VectorTransform(&local_88,lighttransform[*(int *)pcVar8],out);
        out = out + 3;
      } while (uVar5 != 8);
      iVar6 = 0;
      (*tri.Begin)(2);
      iVar4 = *(int *)(pcVar8 + 4) % 8;
      (*tri.Color4f)(hullcolor[iVar4][0],hullcolor[iVar4][1],hullcolor[iVar4][2],1.0);
      (*tri.TexCoord2f)(0.0,0.0);
      paiVar7 = boxpnt;
      do {
        vVar1 = 1.0;
        if (2 < iVar6) {
          vVar1 = -1.0;
        }
        local_80 = 0.0;
        local_84 = 0.0;
        local_88 = 0.0;
        (&local_88)[iVar6 % 3] = vVar1;
        iVar4 = *(int *)pcVar8;
        if (iVar4 == -1) {
          fVar2 = local_80 * r_plightvec[2] + local_84 * r_plightvec[1] + local_88 * r_plightvec[0];
        }
        else {
                    /* Unresolved local var: float illum@[???]
                       Unresolved local var: float lightcos@[???]
                       Unresolved local var: float r@[???] */
          fVar2 = local_80 * r_blightvec[iVar4][2] +
                  local_84 * r_blightvec[iVar4][1] + local_88 * r_blightvec[iVar4][0];
        }
        if (1.0 < fVar2) {
          fVar2 = 1.0;
        }
        fVar3 = (float)r_ambientlight;
        if (v_lambert1 < 1.0) {
          fVar2 = (v_lambert1 - fVar2) / (v_lambert1 + 1.0);
          if (0.0 < fVar2) {
            fVar3 = fVar2 * r_shadelight + fVar3;
          }
        }
        else {
          fVar3 = fVar3 + r_shadelight;
          fVar2 = ((v_lambert1 - 1.0) + fVar2) / v_lambert1;
          if (0.0 < fVar2) {
            fVar3 = fVar3 - fVar2 * r_shadelight;
          }
        }
        if (fVar3 <= 0.0) {
          iVar4 = 0;
        }
        else {
          iVar4 = 0x3fc;
          if (fVar3 <= 255.0) {
            iVar4 = (int)(fVar3 * 4.0);
          }
        }
        iVar6 = iVar6 + 1;
        (*tri.Brightness)((float)lightgammatable[iVar4] * 0.0009775171);
        (*tri.Vertex3fv)(local_7c + (*paiVar7)[0] * 3);
        (*tri.Vertex3fv)(local_7c + (*paiVar7)[1] * 3);
        (*tri.Vertex3fv)(local_7c + (*paiVar7)[2] * 3);
        (*tri.Vertex3fv)(local_7c + (*paiVar7)[3] * 3);
        paiVar7 = paiVar7 + 1;
      } while (iVar6 != 6);
      (*tri.End)();
      pcVar8 = pcVar8 + 0x20;
      local_98 = local_98 + 1;
    } while (local_98 < pstudiohdr->numhitboxes);
  }
  return;
}


// R_StudioDrawModel  @ 000e28e0
int R_StudioDrawModel(int flags)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  vec_t vVar5;
  int iVar6;
  int iVar7;
  vec_t *pvVar8;
  uint uVar9;
  uint uVar10;
  qboolean qVar11;
  int iVar12;
  char (*dest) [32];
  float (*dest_00) [3] [4];
  float (*dest_01) [3] [4];
  float (*src) [3] [4];
  int in_GS_OFFSET;
  float (*local_1ac) [3] [4];
  float local_198 [3];
  alight_t local_18c;
  entity_state_t local_174;
  int local_20;
  
                    /* Unresolved local var: alight_t lighting@[???]
                       Unresolved local var: vec3_t dir@[???] */
  iVar12 = r_dointerp;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar7 = 0;
  if ((currententity->curstate).renderfx == 0x11) {
                    /* Unresolved local var: entity_state_t deadplayer@[???]
                       Unresolved local var: int result@[???]
                       Unresolved local var: int save_interp@[???] */
    iVar6 = (currententity->curstate).renderamt;
    r_dointerp = iVar12;
    if (iVar6 < 1) {
      iVar7 = 0;
    }
    else if (iVar6 <= cl.maxclients) {
      r_playerindex = iVar6 + -1;
      iVar7 = (cl.parsecount & CL_UPDATE_MASK) * 0x4318 + 0xc6aa30 + r_playerindex * 0x154;
      uVar10 = 0;
      do {
        uVar9 = uVar10;
        *(undefined4 *)((int)local_174.origin + (uVar9 - 0x10)) =
             *(undefined4 *)(iVar7 + 0xc + uVar9);
        *(undefined4 *)((int)local_174.origin + (uVar9 - 0xc)) =
             *(undefined4 *)(iVar7 + 0x10 + uVar9);
        uVar10 = uVar9 + 8;
      } while (uVar10 < 0x150);
      local_174.gaitsequence = 0;
      local_174.angles[0] = (currententity->curstate).angles[0];
      vVar1 = (currententity->curstate).angles[1];
      vVar2 = (currententity->curstate).angles[2];
      vVar3 = (currententity->curstate).origin[0];
      vVar4 = (currententity->curstate).origin[1];
      vVar5 = (currententity->curstate).origin[2];
      *(undefined4 *)((int)local_174.origin + (uVar9 - 8)) = *(undefined4 *)(iVar7 + 0xc + uVar10);
      local_174.movetype = 0;
                    /* Unresolved local var: alight_t lighting@[???]
                       Unresolved local var: vec3_t dir@[???] */
      local_174.weaponmodel = 0;
      r_dointerp = 0;
      local_174.number = iVar6;
      local_174.origin[0] = vVar3;
      local_174.origin[1] = vVar4;
      local_174.origin[2] = vVar5;
      local_174.angles[1] = vVar1;
      local_174.angles[2] = vVar2;
      if ((r_playerindex < cl.maxclients) && (-1 < r_playerindex)) {
        iVar7 = R_StudioDrawPlayer(flags,&local_174);
        r_dointerp = iVar12;
      }
      else {
        iVar7 = 0;
        r_dointerp = iVar12;
      }
    }
    goto LAB_000e2a39;
  }
  r_model = currententity->model;
  pstudiohdr = Mod_Extradata(r_model);
  R_StudioSetUpTransform(0);
  if ((flags & 1U) == 0) {
LAB_000e2944:
    if ((currententity->curstate).movetype == 0xc) {
      R_StudioMergeBones(r_model);
    }
    else {
      R_StudioSetupBones();
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: mstudiobone_t * pbones@[???] */
    cached_numbones = pstudiohdr->numbones;
    if (0 < cached_numbones) {
      pvVar8 = (vec_t *)(pstudiohdr->name + pstudiohdr->boneindex + -8);
      local_1ac = lighttransform;
      iVar12 = 0;
      dest = cached_bonename;
      dest_00 = cached_bonetransform;
      dest_01 = cached_lighttransform;
      src = bonetransform;
      do {
        Q_strncpy(*dest,(char *)pvVar8,0x1f);
        (*dest)[0x1f] = '\0';
        Q_memcpy(dest_00,src,0x30);
        Q_memcpy(dest_01,local_1ac,0x30);
        local_1ac = local_1ac + 1;
        iVar12 = iVar12 + 1;
        pvVar8 = pvVar8 + 0x1c;
        dest = dest + 1;
        dest_00 = dest_00 + 1;
        dest_01 = dest_01 + 1;
        src = src + 1;
      } while (iVar12 < pstudiohdr->numbones);
    }
    if ((flags & 2U) != 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: mstudioattachment_t * pattachment@[???] */
      if (4 < pstudiohdr->numattachments) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Too many attachments on %s\n",currententity->model);
      }
      iVar12 = 0;
      pvVar8 = (vec_t *)(pstudiohdr->name + pstudiohdr->attachmentindex + 0x20);
      if (0 < pstudiohdr->numattachments) {
        do {
          iVar7 = iVar12 + 1;
          VectorTransform(pvVar8,lighttransform[(int)pvVar8[-1]],currententity->attachment[iVar12]);
          iVar12 = iVar7;
          pvVar8 = pvVar8 + 0x16;
        } while (iVar7 < pstudiohdr->numattachments);
      }
      R_StudioClientEvents();
      if (0 < currententity->index) {
        Q_memcpy(cl_entities[currententity->index].attachment,currententity->attachment,0x30);
      }
    }
    if ((flags & 1U) != 0) {
      local_18c.plightvec = local_198;
      R_StudioDynamicLight(currententity,&local_18c);
      R_StudioEntityLight(&local_18c);
      R_StudioSetupLighting(&local_18c);
      uVar10 = (currententity->curstate).colormap;
      g_ChromeOrigin[0] = r_origin[0];
      g_ChromeOrigin[1] = r_origin[1];
      r_topcolor = uVar10 & 0xff;
      r_bottomcolor = uVar10 >> 8 & 0xff;
      g_ChromeOrigin[2] = r_origin[2];
      g_ForcedFaceFlags = 0;
      if ((currententity->curstate).renderfx == 0x13) {
        (currententity->curstate).renderfx = 0;
        R_StudioRenderFinal();
        g_ForcedFaceFlags = 2;
        (*tri.SpriteTexture)(cl_sprite_shell,0);
        (currententity->curstate).renderfx = 0x13;
        R_StudioRenderFinal();
        iVar7 = 1;
        goto LAB_000e2a39;
      }
      R_StudioRenderFinal();
    }
  }
  else {
    qVar11 = R_StudioCheckBBox();
    iVar7 = 0;
    if (qVar11 == false) goto LAB_000e2a39;
    r_amodels_drawn = r_amodels_drawn + 1;
    r_smodels_total = r_smodels_total + 1;
    if (pstudiohdr->numbodyparts != 0) goto LAB_000e2944;
  }
  iVar7 = 1;
LAB_000e2a39:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}


// R_StudioDrawPlayer  @ 000e1550
/* WARNING: Removing unreachable block (ram,0x000e287f) */

int __regparm3 R_StudioDrawPlayer(int flags,entity_state_t *pplayer)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  skin_t (*pasVar4) [11];
  player_info_t *ppVar5;
  uint uVar6;
  qboolean qVar7;
  int iVar8;
  model_t *pmVar9;
  void *pvVar10;
  cl_entity_t *pcVar11;
  studiohdr_t *psVar12;
  vec_t *pvVar13;
  skin_t *psVar14;
  char (*dest) [32];
  int iVar15;
  int iVar16;
  float (*dest_00) [3] [4];
  float (*dest_01) [3] [4];
  int *piVar17;
  float (*src) [3] [4];
  int *piVar18;
  int in_GS_OFFSET;
  byte bVar19;
  float (*local_c14) [3] [4];
  float local_bfc [3];
  alight_t local_bf0;
  int local_bd8;
  int local_bd4 [727];
  undefined1 local_78 [88];
  int local_20;
  
                    /* Unresolved local var: alight_t lighting@[???]
                       Unresolved local var: vec3_t dir@[???] */
  bVar19 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((developer.value == 0.0) && (qVar7 = Host_IsSinglePlayerGame(), qVar7 != false)) ||
     (cl.players[r_playerindex].model[0] == '\0')) {
    iVar8 = r_playerindex;
    DM_PlayerState[r_playerindex].name[0] = '\0';
    pcVar11 = currententity;
    if (DM_PlayerState[iVar8].model != currententity->model) {
      DM_PlayerState[iVar8].model = currententity->model;
      iVar16 = r_remapindex;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: skin_t * pskin@[???] */
      iVar15 = pcVar11->index;
                    /* Unresolved local var: skin_t * pskin@[???] */
      psVar14 = pDM_RemapSkin[iVar15][0];
      if ((psVar14 == (skin_t *)0x0) || (psVar14->keynum != iVar15)) {
        psVar14 = DM_RemapSkin[r_remapindex];
        r_remapindex = (r_remapindex + 1) % 0x40;
        pDM_RemapSkin[iVar15][0] = psVar14;
        DM_RemapSkin[iVar16][0].keynum = iVar15;
        DM_RemapSkin[iVar16][0].topcolor = -1;
        DM_RemapSkin[iVar16][0].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][1];
      if ((psVar14 == (skin_t *)0x0) || (psVar14->keynum != iVar15)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 1;
        r_remapindex = (r_remapindex + 1) % 0x40;
        pDM_RemapSkin[iVar15][1] = psVar14;
        DM_RemapSkin[iVar16][1].keynum = iVar15;
        DM_RemapSkin[iVar16][1].topcolor = -1;
        DM_RemapSkin[iVar16][1].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][2];
      if ((psVar14 == (skin_t *)0x0) || (psVar14->keynum != iVar15)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 2;
        r_remapindex = (r_remapindex + 1) % 0x40;
        pDM_RemapSkin[iVar15][2] = psVar14;
        DM_RemapSkin[iVar16][2].keynum = iVar15;
        DM_RemapSkin[iVar16][2].topcolor = -1;
        DM_RemapSkin[iVar16][2].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][3];
      if ((psVar14 == (skin_t *)0x0) || (psVar14->keynum != iVar15)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 3;
        pasVar4 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar4)[3].keynum = iVar15;
        pDM_RemapSkin[iVar15][3] = psVar14;
        DM_RemapSkin[iVar16][3].topcolor = -1;
        DM_RemapSkin[iVar16][3].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][4];
      if ((psVar14 == (skin_t *)0x0) || (iVar15 != psVar14->keynum)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 4;
        r_remapindex = (r_remapindex + 1) % 0x40;
        pDM_RemapSkin[iVar15][4] = psVar14;
        DM_RemapSkin[iVar16][4].keynum = iVar15;
        DM_RemapSkin[iVar16][4].topcolor = -1;
        DM_RemapSkin[iVar16][4].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][5];
      if ((psVar14 == (skin_t *)0x0) || (iVar15 != psVar14->keynum)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 5;
        r_remapindex = (r_remapindex + 1) % 0x40;
        pDM_RemapSkin[iVar15][5] = psVar14;
        DM_RemapSkin[iVar16][5].keynum = iVar15;
        DM_RemapSkin[iVar16][5].topcolor = -1;
        DM_RemapSkin[iVar16][5].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][6];
      if ((psVar14 == (skin_t *)0x0) || (iVar15 != psVar14->keynum)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 6;
        pasVar4 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar4)[6].keynum = iVar15;
        pDM_RemapSkin[iVar15][6] = psVar14;
        DM_RemapSkin[iVar16][6].topcolor = -1;
        DM_RemapSkin[iVar16][6].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][7];
      if ((psVar14 == (skin_t *)0x0) || (iVar15 != psVar14->keynum)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 7;
        r_remapindex = (r_remapindex + 1) % 0x40;
        pDM_RemapSkin[iVar15][7] = psVar14;
        DM_RemapSkin[iVar16][7].keynum = iVar15;
        DM_RemapSkin[iVar16][7].topcolor = -1;
        DM_RemapSkin[iVar16][7].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][8];
      if ((psVar14 == (skin_t *)0x0) || (iVar15 != psVar14->keynum)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 8;
        r_remapindex = (r_remapindex + 1) % 0x40;
        pDM_RemapSkin[iVar15][8] = psVar14;
        DM_RemapSkin[iVar16][8].keynum = iVar15;
        DM_RemapSkin[iVar16][8].topcolor = -1;
        DM_RemapSkin[iVar16][8].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][9];
      if ((psVar14 == (skin_t *)0x0) || (iVar15 != psVar14->keynum)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 9;
        pasVar4 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar4)[9].keynum = iVar15;
        pDM_RemapSkin[iVar15][9] = psVar14;
        DM_RemapSkin[iVar16][9].topcolor = -1;
        DM_RemapSkin[iVar16][9].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar15 = pcVar11->index;
LAB_000e1a69:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: skin_t * pskin@[???] */
      iVar16 = r_remapindex;
      psVar14 = pDM_RemapSkin[iVar15][10];
      if ((psVar14 == (skin_t *)0x0) || (iVar15 != psVar14->keynum)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 10;
        r_remapindex = (r_remapindex + 1) % 0x40;
        pDM_RemapSkin[iVar15][10] = psVar14;
        DM_RemapSkin[iVar16][10].keynum = iVar15;
        DM_RemapSkin[iVar16][10].topcolor = -1;
        DM_RemapSkin[iVar16][10].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
    }
  }
  else {
    iVar15 = Q_strcmp(DM_PlayerState[r_playerindex].name,cl.players[r_playerindex].model);
    iVar8 = r_playerindex;
    if (iVar15 != 0) {
      Q_strncpy(DM_PlayerState[r_playerindex].name,cl.players[r_playerindex].model,0x103);
      iVar15 = r_playerindex * 0x20c;
      iVar8 = r_playerindex * 0x250 + 0xde5490;
      DM_PlayerState[r_playerindex].name[0x103] = '\0';
      __snprintf_chk(iVar15 + 0x9b7f44,0x104,1,0x104,&DAT_0025bb19,iVar8,iVar8);
      iVar8 = r_playerindex;
      pmVar9 = Mod_ForName(DM_PlayerState[r_playerindex].modelname,false,true);
      pcVar11 = currententity;
      DM_PlayerState[iVar8].model = pmVar9;
      iVar8 = r_playerindex;
      if (DM_PlayerState[r_playerindex].model == (model_t *)0x0) {
        DM_PlayerState[r_playerindex].model = pcVar11->model;
      }
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][0];
      if ((psVar14 == (skin_t *)0x0) || (iVar15 != psVar14->keynum)) {
        psVar14 = DM_RemapSkin[r_remapindex];
        r_remapindex = (r_remapindex + 1) % 0x40;
        pDM_RemapSkin[iVar15][0] = psVar14;
        DM_RemapSkin[iVar16][0].keynum = iVar15;
        DM_RemapSkin[iVar16][0].topcolor = -1;
        DM_RemapSkin[iVar16][0].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][1];
      if ((psVar14 == (skin_t *)0x0) || (iVar15 != psVar14->keynum)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 1;
        r_remapindex = (r_remapindex + 1) % 0x40;
        pDM_RemapSkin[iVar15][1] = psVar14;
        DM_RemapSkin[iVar16][1].keynum = iVar15;
        DM_RemapSkin[iVar16][1].topcolor = -1;
        DM_RemapSkin[iVar16][1].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][2];
      if ((psVar14 == (skin_t *)0x0) || (iVar15 != psVar14->keynum)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 2;
        r_remapindex = (r_remapindex + 1) % 0x40;
        pDM_RemapSkin[iVar15][2] = psVar14;
        DM_RemapSkin[iVar16][2].keynum = iVar15;
        DM_RemapSkin[iVar16][2].topcolor = -1;
        DM_RemapSkin[iVar16][2].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][3];
      if ((psVar14 == (skin_t *)0x0) || (iVar15 != psVar14->keynum)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 3;
        pasVar4 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar4)[3].keynum = iVar15;
        pDM_RemapSkin[iVar15][3] = psVar14;
        DM_RemapSkin[iVar16][3].topcolor = -1;
        DM_RemapSkin[iVar16][3].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][4];
      if ((psVar14 == (skin_t *)0x0) || (iVar15 != psVar14->keynum)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 4;
        r_remapindex = (r_remapindex + 1) % 0x40;
        pDM_RemapSkin[iVar15][4] = psVar14;
        DM_RemapSkin[iVar16][4].keynum = iVar15;
        DM_RemapSkin[iVar16][4].topcolor = -1;
        DM_RemapSkin[iVar16][4].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][5];
      if ((psVar14 == (skin_t *)0x0) || (iVar15 != psVar14->keynum)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 5;
        r_remapindex = (r_remapindex + 1) % 0x40;
        pDM_RemapSkin[iVar15][5] = psVar14;
        DM_RemapSkin[iVar16][5].keynum = iVar15;
        DM_RemapSkin[iVar16][5].topcolor = -1;
        DM_RemapSkin[iVar16][5].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][6];
      if ((psVar14 == (skin_t *)0x0) || (iVar15 != psVar14->keynum)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 6;
        pasVar4 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar4)[6].keynum = iVar15;
        pDM_RemapSkin[iVar15][6] = psVar14;
        DM_RemapSkin[iVar16][6].topcolor = -1;
        DM_RemapSkin[iVar16][6].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][7];
      if ((psVar14 == (skin_t *)0x0) || (iVar15 != psVar14->keynum)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 7;
        r_remapindex = (r_remapindex + 1) % 0x40;
        pDM_RemapSkin[iVar15][7] = psVar14;
        DM_RemapSkin[iVar16][7].keynum = iVar15;
        DM_RemapSkin[iVar16][7].topcolor = -1;
        DM_RemapSkin[iVar16][7].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][8];
      if ((psVar14 == (skin_t *)0x0) || (iVar15 != psVar14->keynum)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 8;
        r_remapindex = (r_remapindex + 1) % 0x40;
        pDM_RemapSkin[iVar15][8] = psVar14;
        DM_RemapSkin[iVar16][8].keynum = iVar15;
        DM_RemapSkin[iVar16][8].topcolor = -1;
        DM_RemapSkin[iVar16][8].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar16 = r_remapindex;
      iVar15 = pcVar11->index;
      psVar14 = pDM_RemapSkin[iVar15][9];
      if ((psVar14 == (skin_t *)0x0) || (iVar15 != psVar14->keynum)) {
        psVar14 = DM_RemapSkin[r_remapindex] + 9;
        pasVar4 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar4)[9].keynum = iVar15;
        pDM_RemapSkin[iVar15][9] = psVar14;
        DM_RemapSkin[iVar16][9].topcolor = -1;
        DM_RemapSkin[iVar16][9].bottomcolor = -1;
      }
      psVar14->topcolor = -1;
      psVar14->bottomcolor = -1;
      iVar15 = pcVar11->index;
      goto LAB_000e1a69;
    }
  }
  r_model = DM_PlayerState[iVar8].model;
  if (r_model == (model_t *)0x0) {
LAB_000e212c:
    iVar8 = 0;
    goto LAB_000e2065;
  }
  pstudiohdr = Mod_Extradata(r_model);
  pcVar11 = currententity;
  if (pplayer->gaitsequence == 0) {
    builtin_memcpy((currententity->curstate).controller,"\x7f\x7f\x7f\x7f",4);
    builtin_memcpy((pcVar11->latched).prevcontroller,"\x7f\x7f\x7f\x7f",4);
    cl.players[r_playerindex].gaitsequence = 0;
    R_StudioSetUpTransform(0);
  }
  else {
                    /* Unresolved local var: vec3_t orig_angles@[???] */
    r_playerinfo = cl.players + r_playerindex;
    vVar1 = currententity->angles[0];
    vVar2 = currententity->angles[1];
    vVar3 = currententity->angles[2];
    R_StudioProcessGait(pplayer);
    ppVar5 = r_playerinfo;
    r_playerinfo = (player_info_t *)0x0;
    ppVar5->gaitsequence = pplayer->gaitsequence;
    R_StudioSetUpTransform(0);
    pcVar11 = currententity;
    currententity->angles[0] = vVar1;
    pcVar11->angles[1] = vVar2;
    pcVar11->angles[2] = vVar3;
  }
  uVar6 = flags & 1;
  if (uVar6 == 0) {
LAB_000e1bad:
    r_playerinfo = cl.players + r_playerindex;
    R_StudioSetupBones();
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: mstudiobone_t * pbones@[???] */
    cached_numbones = pstudiohdr->numbones;
    if (0 < cached_numbones) {
      pvVar13 = (vec_t *)(pstudiohdr->name + pstudiohdr->boneindex + -8);
      local_c14 = lighttransform;
      iVar8 = 0;
      dest = cached_bonename;
      dest_00 = cached_bonetransform;
      dest_01 = cached_lighttransform;
      src = bonetransform;
      do {
        Q_strncpy(*dest,(char *)pvVar13,0x1f);
        (*dest)[0x1f] = '\0';
        Q_memcpy(dest_00,src,0x30);
        Q_memcpy(dest_01,local_c14,0x30);
        local_c14 = local_c14 + 1;
        iVar8 = iVar8 + 1;
        pvVar13 = pvVar13 + 0x1c;
        dest = dest + 1;
        dest_00 = dest_00 + 1;
        dest_01 = dest_01 + 1;
        src = src + 1;
      } while (iVar8 < pstudiohdr->numbones);
    }
    psVar12 = pstudiohdr;
    r_playerinfo->renderframe = r_framecount;
    r_playerinfo = (player_info_t *)0x0;
    if ((flags & 2U) == 0) {
LAB_000e1d8d:
      if (uVar6 == 0) goto LAB_000e2060;
    }
    else {
                    /* Unresolved local var: studiohdr_t * modelheader@[???] */
      if (((uVar6 == 0) || (pplayer == (entity_state_t *)0x0)) || (pplayer->weaponmodel == 0)) {
LAB_000e1cf1:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: mstudioattachment_t * pattachment@[???] */
        if (4 < psVar12->numattachments) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("Too many attachments on %s\n",currententity->model);
        }
        iVar8 = 0;
        pvVar13 = (vec_t *)(psVar12->name + psVar12->attachmentindex + 0x20);
        if (0 < psVar12->numattachments) {
          do {
            iVar15 = iVar8 + 1;
            VectorTransform(pvVar13,lighttransform[(int)pvVar13[-1]],
                            currententity->attachment[iVar8]);
            iVar8 = iVar15;
            pvVar13 = pvVar13 + 0x16;
          } while (iVar15 < pstudiohdr->numattachments);
        }
        R_StudioClientEvents();
        if (0 < currententity->index) {
          Q_memcpy(cl_entities[currententity->index].attachment,currententity->attachment,0x30);
        }
        goto LAB_000e1d8d;
      }
      pmVar9 = CL_GetModelByIndex(pplayer->weaponmodel);
      pvVar10 = Mod_Extradata(pmVar9);
      psVar12 = pstudiohdr;
      if (*(int *)((int)pvVar10 + 0xd4) == 0) goto LAB_000e1cf1;
    }
    if ((cl_himodels.value != 0.0) && (DM_PlayerState[r_playerindex].model != currententity->model))
    {
      (currententity->curstate).body = 0xff;
    }
    if (((developer.value != 0.0) ||
        (qVar7 = Host_IsSinglePlayerGame(), pcVar11 = currententity, qVar7 == false)) &&
       ((pcVar11 = currententity, DM_PlayerState[r_playerindex].name[0] != '\0' &&
        (DM_PlayerState[r_playerindex].model == currententity->model)))) {
      (currententity->curstate).body = 1;
    }
    local_bf0.plightvec = local_bfc;
    R_StudioDynamicLight(pcVar11,&local_bf0);
    R_StudioEntityLight(&local_bf0);
    R_StudioSetupLighting(&local_bf0);
    r_playerinfo = cl.players + r_playerindex;
    r_topcolor = cl.players[r_playerindex].topcolor;
    if (r_topcolor < 0) {
      r_topcolor = 0;
    }
    else if (0x168 < r_topcolor) {
      r_topcolor = 0x168;
    }
    r_bottomcolor = cl.players[r_playerindex].bottomcolor;
    if (r_bottomcolor < 0) {
      r_bottomcolor = 0;
    }
    else if (0x168 < r_bottomcolor) {
      r_bottomcolor = 0x168;
    }
    g_ChromeOrigin[0] = r_origin[0];
    g_ChromeOrigin[1] = r_origin[1];
    g_ChromeOrigin[2] = r_origin[2];
    g_ForcedFaceFlags = 0;
    if ((currententity->curstate).renderfx == 0x13) {
      (currententity->curstate).renderfx = 0;
      R_StudioRenderFinal();
      g_ForcedFaceFlags = 2;
      (*tri.SpriteTexture)(cl_sprite_shell,0);
      (currententity->curstate).renderfx = 0x13;
      R_StudioRenderFinal();
    }
    else {
      R_StudioRenderFinal();
    }
    psVar12 = pstudiohdr;
    r_playerinfo = (player_info_t *)0x0;
    iVar8 = pplayer->weaponmodel;
    pstudiohdr = psVar12;
    if (iVar8 != 0) {
                    /* Unresolved local var: studiohdr_t * saveheader@[???]
                       Unresolved local var: cl_entity_t saveent@[???]
                       Unresolved local var: model_t * pweaponmodel@[???] */
      piVar17 = &local_bd8;
      pcVar11 = currententity;
      piVar18 = piVar17;
      for (iVar15 = 0x2ee; iVar15 != 0; iVar15 = iVar15 + -1) {
        *piVar18 = pcVar11->index;
        pcVar11 = (cl_entity_t *)((int)pcVar11 + (uint)bVar19 * -8 + 4);
        piVar18 = piVar18 + (uint)bVar19 * -2 + 1;
      }
      pmVar9 = CL_GetModelByIndex(iVar8);
      pstudiohdr = Mod_Extradata(pmVar9);
      R_StudioMergeBones(pmVar9);
      R_StudioSetupLighting(&local_bf0);
      g_ForcedFaceFlags = 0;
      g_ChromeOrigin[0] = r_origin[0];
      g_ChromeOrigin[1] = r_origin[1];
      g_ChromeOrigin[2] = r_origin[2];
      if ((currententity->curstate).renderfx == 0x13) {
        (currententity->curstate).renderfx = 0;
        R_StudioRenderFinal();
        g_ForcedFaceFlags = 2;
        (*tri.SpriteTexture)(cl_sprite_shell,0);
        (currententity->curstate).renderfx = 0x13;
        R_StudioRenderFinal();
      }
      else {
        R_StudioRenderFinal();
      }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: mstudioattachment_t * pattachment@[???] */
      iVar8 = pstudiohdr->numattachments;
      if (4 < iVar8) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("Too many attachments on %s\n",currententity->model);
      }
      if (0 < iVar8) {
        iVar15 = 0;
        pvVar13 = (vec_t *)(pstudiohdr->name + pstudiohdr->attachmentindex + 0x20);
        do {
          iVar16 = iVar15 + 1;
          VectorTransform(pvVar13,lighttransform[(int)pvVar13[-1]],currententity->attachment[iVar15]
                         );
          iVar8 = pstudiohdr->numattachments;
          iVar15 = iVar16;
          pvVar13 = pvVar13 + 0x16;
        } while (iVar16 < iVar8);
      }
      if (0 < currententity->index) {
        Q_memcpy(local_78,currententity->attachment,iVar8 * 0xc);
      }
      uVar6 = 3000;
      pcVar11 = currententity;
      if (((uint)currententity & 4) != 0) {
        pcVar11 = (cl_entity_t *)&currententity->player;
        uVar6 = 0xbb4;
        piVar17 = local_bd4;
        currententity->index = local_bd8;
      }
      for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        pcVar11->index = *piVar17;
        piVar17 = piVar17 + (uint)bVar19 * -2 + 1;
        pcVar11 = (cl_entity_t *)((int)pcVar11 + (uint)bVar19 * -8 + 4);
      }
      pstudiohdr = psVar12;
      if ((flags & 2U) != 0) {
        R_StudioClientEvents();
      }
    }
  }
  else {
    qVar7 = R_StudioCheckBBox();
    if (qVar7 == false) goto LAB_000e212c;
    r_amodels_drawn = r_amodels_drawn + 1;
    r_smodels_total = r_smodels_total + 1;
    if (pstudiohdr->numbodyparts != 0) goto LAB_000e1bad;
  }
LAB_000e2060:
  iVar8 = 1;
LAB_000e2065:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}


// R_StudioDrawPlayer  @ 000e28b0
int R_StudioDrawPlayer(int flags,entity_state_t *pplayer)

{
  int iVar1;
  
                    /* Unresolved local var: alight_t lighting@[???]
                       Unresolved local var: vec3_t dir@[???] */
  r_playerindex = pplayer->number + -1;
  if ((-1 < r_playerindex) && (r_playerindex < cl.maxclients)) {
    iVar1 = R_StudioDrawPlayer(flags,pplayer);
    return iVar1;
  }
  return 0;
}


// R_StudioDrawPoints  @ 000e0980
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioDrawPoints(void)

{
  char *pcVar1;
  byte bVar2;
  short sVar3;
  model_t *src;
  mstudiomodel_t *pmVar4;
  studiohdr_t *psVar5;
  studiohdr_t *psVar6;
  float fVar7;
  int iVar8;
  auxvert_t *paVar9;
  uint uVar10;
  char *pcVar11;
  char *pcVar12;
  void *pvVar13;
  int iVar14;
  model_t *pmVar15;
  float (*light) [3] [4];
  vec3_t *pavVar16;
  int iVar17;
  char *pcVar18;
  vec3_t *pavVar19;
  vec3_t *pavVar20;
  bool bVar21;
  char *pcVar22;
  int iVar23;
  char *pcVar24;
  uint uVar25;
  studiohdr_t *psVar26;
  int iVar27;
  int in_GS_OFFSET;
  float fStack_174;
  float fStack_170;
  int iStack_16c;
  int iStack_168;
  int iStack_164;
  char *pcStack_160;
  char *pcStack_158;
  studiohdr_t *psStack_154;
  float fStack_140;
  GLfloat GStack_13c;
  GLfloat GStack_138;
  GLfloat GStack_134;
  float fStack_130;
  float fStack_12c;
  undefined4 uStack_128;
  char acStack_124 [258];
  undefined1 uStack_22;
  int iStack_20;
  
  psVar5 = pstudiohdr;
  src = r_model;
  iStack_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar27 = psubmodel->vertinfoindex;
  pcVar22 = pstudiohdr->name + psubmodel->norminfoindex + -8;
  iVar14 = pstudiohdr->textureindex;
  if (iVar14 == 0) {
    pmVar15 = (model_t *)r_model->texinfo;
    if ((pmVar15 == (model_t *)0x0) ||
       (pvVar13 = Cache_Check(&pmVar15->cache), pvVar13 == (void *)0x0)) {
      Q_strncpy(acStack_124,src->name,0x102);
      uStack_22 = 0;
      iVar14 = Q_strlen(acStack_124);
      Q_strcpy(acStack_124 + iVar14 + -4,"T.mdl");
      pmVar15 = Mod_ForName(acStack_124,true,false);
      src->texinfo = (mtexinfo_t *)pmVar15;
      pvVar13 = (pmVar15->cache).data;
      Q_strncpy((char *)((int)pvVar13 + 8),acStack_124,0x3f);
      *(undefined1 *)((int)pvVar13 + 0x47) = 0;
    }
    psStack_154 = (pmVar15->cache).data;
    iVar14 = psStack_154->textureindex;
  }
  else {
    psStack_154 = pstudiohdr;
  }
  psVar6 = pstudiohdr;
  pmVar4 = psubmodel;
  iVar17 = psubmodel->meshindex;
  iVar23 = psubmodel->vertindex;
  pcStack_160 = psStack_154->name + psStack_154->skinindex + -8;
  pcVar24 = pstudiohdr->name;
  pcStack_158 = pstudiohdr->name + psubmodel->normindex + -8;
  iVar8 = (int)(currententity->curstate).skin;
  if ((iVar8 == 0) || (psStack_154->numskinfamilies <= iVar8)) {
    if ((currententity->curstate).renderfx == 0x13) goto LAB_000e077c;
LAB_000dfba8:
    if (psubmodel->numverts < 1) goto LAB_000dfca8;
    iVar8 = 0;
    paVar9 = pauxverts;
    pcVar24 = pcVar24 + iVar23 + -8;
    do {
      bVar2 = psVar5->name[iVar8 + iVar27 + -8];
      iVar8 = iVar8 + 1;
      paVar9->fv[0] =
           *(float *)(pcVar24 + 8) * bonetransform[bVar2][0][2] +
           *(float *)(pcVar24 + 4) * bonetransform[bVar2][0][1] +
           *(float *)pcVar24 * bonetransform[bVar2][0][0] + bonetransform[bVar2][0][3];
      paVar9->fv[1] =
           *(float *)(pcVar24 + 8) * bonetransform[bVar2][1][2] +
           *(float *)(pcVar24 + 4) * bonetransform[bVar2][1][1] +
           *(float *)pcVar24 * bonetransform[bVar2][1][0] + bonetransform[bVar2][1][3];
      paVar9->fv[2] =
           *(float *)(pcVar24 + 8) * bonetransform[bVar2][2][2] +
           *(float *)(pcVar24 + 4) * bonetransform[bVar2][2][1] +
           *(float *)pcVar24 * bonetransform[bVar2][2][0] + bonetransform[bVar2][2][3];
      iVar23 = psubmodel->numverts;
      paVar9 = paVar9 + 1;
      pcVar24 = pcVar24 + 0xc;
      psVar26 = psVar6;
    } while (iVar8 < iVar23);
  }
  else {
    pcStack_160 = pcStack_160 + iVar8 * psStack_154->numskinref * 2;
    if ((currententity->curstate).renderfx != 0x13) goto LAB_000dfba8;
LAB_000e077c:
    if (0 < psubmodel->numverts) {
      iVar27 = 0;
      do {
        g_NormalIndex[iVar27] = -1;
        iVar27 = iVar27 + 1;
      } while (iVar27 < pmVar4->numverts);
    }
    fStack_174 = 0.0;
    iStack_16c = 0;
    if (0 < pmVar4->nummesh) {
      do {
        pcVar18 = psVar6->name + *(int *)(psVar6->name + pmVar4->meshindex + iStack_16c + -4) + -8;
        while (pcVar11 = pcVar18, uVar25 = (uint)*(short *)pcVar11, uVar25 != 0) {
          while( true ) {
            pcVar18 = pcVar11 + 2;
            iVar27 = (uVar25 ^ (int)uVar25 >> 0x1f) - ((int)uVar25 >> 0x1f);
            if (iVar27 == 0) break;
            pcVar12 = pcVar18;
            do {
              while (sVar3 = *(short *)pcVar12, -1 < g_NormalIndex[sVar3]) {
                pcVar12 = pcVar12 + 8;
                if (pcVar12 == pcVar11 + (iVar27 * 4 + 1) * 2) goto LAB_000e0827;
              }
              pcVar1 = pcVar12 + 2;
              pcVar12 = pcVar12 + 8;
              g_NormalIndex[sVar3] = (int)*(short *)pcVar1;
            } while (pcVar12 != pcVar11 + (iVar27 * 4 + 1) * 2);
LAB_000e0827:
            pcVar11 = pcVar18 + iVar27 * 8;
            uVar25 = (uint)*(short *)pcVar11;
            if (uVar25 == 0) goto LAB_000e0834;
          }
        }
LAB_000e0834:
        fStack_174 = (float)((int)fStack_174 + 1);
        iStack_16c = iStack_16c + 0x14;
      } while ((int)fStack_174 < pmVar4->nummesh);
    }
    BuildGlowShellVerts((vec3_t *)(pcVar24 + iVar23 + -8),pauxverts);
    iVar23 = psubmodel->numverts;
    psVar26 = pstudiohdr;
  }
  iVar27 = psubmodel->vertinfoindex;
  if (0 < iVar23) {
    iVar23 = 0;
    light = lightpos;
    pcVar24 = psVar26->name + psubmodel->vertindex + -8;
    do {
      iVar8 = iVar23 + iVar27;
      iVar23 = iVar23 + 1;
      R_LightStrength((uint)(byte)psVar26->name[iVar8 + -8],(float *)pcVar24,*light);
      light = light + 1;
      pcVar24 = pcVar24 + 0xc;
    } while (iVar23 < psubmodel->numverts);
  }
LAB_000dfca8:
  iVar27 = psubmodel->nummesh;
  iStack_164 = 0;
  pcVar24 = psVar6->name + iVar17 + -8;
  pavVar16 = pvlightvalues;
  if (0 < iVar27) {
    do {
      pavVar20 = pvlightvalues;
      iVar17 = pvlightvalues_size;
      uVar10 = *(uint *)(psStack_154->name +
                        *(short *)(pcStack_160 + *(int *)(pcVar24 + 8) * 2) * 0x50 + iVar14 + 0x38)
               | g_ForcedFaceFlags;
      uVar25 = uVar10 & 0xfffffffc;
      if (r_fullbright.value < 2.0) {
        uVar25 = uVar10;
      }
      if ((currententity->curstate).rendermode == 5) {
        if ((0 < *(int *)(pcVar24 + 0xc)) &&
           (iVar23 = ((int)pavVar16 - (int)pvlightvalues >> 2) * -0x55555555,
           iVar23 < pvlightvalues_size)) {
          if ((uVar25 & 2) == 0) {
            iVar27 = 0;
            pavVar19 = pavVar16;
            do {
              fVar7 = r_blend;
              iVar27 = iVar27 + 1;
              pavVar16 = pavVar19 + 1;
              (*pavVar19)[2] = r_blend;
              (*pavVar19)[1] = fVar7;
              (*pavVar19)[0] = fVar7;
              if (*(int *)(pcVar24 + 0xc) <= iVar27) break;
              pavVar19 = pavVar16;
            } while (((int)pavVar16 - (int)pavVar20 >> 2) * -0x55555555 < iVar17);
          }
          else {
            iVar27 = 0;
            pavVar20 = pavVar16;
            do {
              fVar7 = r_blend;
              iVar27 = iVar27 + 1;
              pavVar16 = pavVar20 + 1;
              (*pavVar20)[2] = r_blend;
              (*pavVar20)[1] = fVar7;
              (*pavVar20)[0] = fVar7;
              R_StudioChrome(chrome[iVar23],(uint)(byte)*pcVar22,(vec_t *)pcStack_158);
              if (*(int *)(pcVar24 + 0xc) <= iVar27) break;
              iVar23 = ((int)pavVar16 - (int)pvlightvalues >> 2) * -0x55555555;
              pavVar20 = pavVar16;
            } while (iVar23 < pvlightvalues_size);
          }
          goto LAB_000dfdf5;
        }
      }
      else if ((0 < *(int *)(pcVar24 + 0xc)) &&
              (iVar23 = ((int)pavVar16 - (int)pvlightvalues >> 2) * -0x55555555,
              iVar23 < pvlightvalues_size)) {
        if ((uVar25 & 2) == 0) {
          iVar27 = 0;
          pavVar19 = pavVar16;
          pcVar18 = pcVar22;
          pcVar11 = pcStack_158;
          do {
            iVar27 = iVar27 + 1;
            pavVar16 = pavVar19 + 1;
            pcVar22 = pcVar18 + 1;
            pcStack_158 = pcVar11 + 0xc;
            R_StudioLighting(&fStack_140,(uint)(byte)*pcVar18,uVar25,(vec_t *)pcVar11);
            (*pavVar19)[0] = r_colormix[0] * fStack_140;
            (*pavVar19)[1] = r_colormix[1] * fStack_140;
            (*pavVar19)[2] = fStack_140 * r_colormix[2];
            if (*(int *)(pcVar24 + 0xc) <= iVar27) break;
            pavVar19 = pavVar16;
            pcVar18 = pcVar22;
            pcVar11 = pcStack_158;
          } while (((int)pavVar16 - (int)pavVar20 >> 2) * -0x55555555 < iVar17);
        }
        else {
          iVar27 = 0;
          pcVar18 = pcVar22;
          pavVar20 = pavVar16;
          pcVar11 = pcStack_158;
          do {
            pavVar16 = pavVar20 + 1;
            pcVar22 = pcVar18 + 1;
            R_StudioLighting(&fStack_140,(uint)(byte)*pcVar18,uVar25,(vec_t *)pcVar11);
            pcStack_158 = pcVar11 + 0xc;
            R_StudioChrome(chrome[iVar23],(uint)(byte)*pcVar18,(vec_t *)pcVar11);
            iVar27 = iVar27 + 1;
            (*pavVar20)[0] = r_colormix[0] * fStack_140;
            (*pavVar20)[1] = r_colormix[1] * fStack_140;
            (*pavVar20)[2] = fStack_140 * r_colormix[2];
            if (*(int *)(pcVar24 + 0xc) <= iVar27) break;
            iVar23 = ((int)pavVar16 - (int)pvlightvalues >> 2) * -0x55555555;
            pcVar18 = pcVar22;
            pavVar20 = pavVar16;
            pcVar11 = pcStack_158;
          } while (iVar23 < pvlightvalues_size);
        }
LAB_000dfdf5:
        iVar27 = psubmodel->nummesh;
      }
      iStack_164 = iStack_164 + 1;
      pcVar24 = pcVar24 + 0x14;
    } while (iStack_164 < iVar27);
  }
  (*qglCullFace)(0x404);
  if (((cl_righthand == (cvar_t *)0x0) || (cl_righthand->value <= 0.0)) ||
     (cl.viewent.index != currententity->index)) {
    bVar21 = false;
  }
  else {
    bVar21 = true;
    (*qglDisable)(0xb44);
  }
  psVar5 = pstudiohdr;
  iVar27 = psubmodel->normindex;
  if (0 < psubmodel->nummesh) {
    iStack_168 = 0;
    do {
      pcVar24 = pstudiohdr->name + psubmodel->meshindex + iStack_168 * 0x14 + -8;
      c_alias_polys = c_alias_polys + *(int *)pcVar24;
      pcVar22 = pstudiohdr->name + *(int *)(pcVar24 + 4) + -8;
      uVar25 = *(uint *)(psStack_154->name +
                        *(short *)(pcStack_160 + *(int *)(pcVar24 + 8) * 2) * 0x50 + iVar14 + 0x38)
               | g_ForcedFaceFlags;
      if (2.0 <= r_fullbright.value) {
        uVar25 = uVar25 & 0xfffffffc;
      }
      if ((uVar25 & 0x40) != 0) {
        (*qglEnable)(0xbc0);
        (*qglAlphaFunc)(0x204,0.5);
        (*qglDepthMask)('\x01');
      }
      if (((uVar25 & 0x20) != 0) && ((currententity->curstate).rendermode == 0)) {
        (*qglBlendFunc)(1,1);
        (*qglEnable)(0xbe2);
        (*qglDepthMask)('\0');
        (*qglShadeModel)(0x1d01);
      }
      if (2.0 <= r_fullbright.value) {
        (*tri.SpriteTexture)(cl_sprite_white,0);
        fStack_174 = 0.00390625;
        fStack_170 = 0.00390625;
LAB_000e02f5:
        if ((uVar25 & 2) == 0) {
LAB_000e00b6:
          while( true ) {
            iVar17 = (int)*(short *)pcVar22;
            pcVar24 = pcVar22 + 2;
            if (iVar17 == 0) break;
            if (iVar17 < 0) {
              iVar17 = -iVar17;
              (*qglBegin)(6);
LAB_000e00e1:
              pcVar18 = pcVar24;
              if (*(short *)(pcVar22 + 4) < pvlightvalues_size) {
                do {
                  (*qglTexCoord2f)((float)*(short *)(pcVar18 + 4) * fStack_170,
                                   (float)*(short *)(pcVar18 + 6) * fStack_174);
                  iVar23 = *(short *)(pcVar18 + 2) * 0xc;
                  pavVar16 = pvlightvalues + *(short *)(pcVar18 + 2);
                  if (bVar21) {
                    fStack_130 = *(float *)(psVar5->name + iVar23 + iVar27 + -8);
                    fStack_12c = -*(float *)(psVar5->name +
                                            *(short *)(pcVar18 + 2) * 0xc + iVar27 + -4);
                    uStack_128 = *(undefined4 *)
                                  (psVar5->name + *(short *)(pcVar18 + 2) * 0xc + iVar27);
                    if (numlights == 0) {
LAB_000e0105:
                      GStack_13c = (*pavVar16)[0];
                      GStack_138 = (*pavVar16)[1];
                      GStack_134 = (*pavVar16)[2];
                    }
                    else {
                      R_LightLambert(lightpos[*(short *)pcVar18],&fStack_130,*pavVar16,&GStack_13c);
                    }
                  }
                  else {
                    if (numlights == 0) goto LAB_000e0105;
                    R_LightLambert(lightpos[*(short *)pcVar18],
                                   (float *)(psVar5->name + iVar23 + iVar27 + -8),*pavVar16,
                                   &GStack_13c);
                  }
                  pcVar24 = pcVar18 + 8;
                  (*qglColor4f)(GStack_13c,GStack_138,GStack_134,r_blend);
                  paVar9 = pauxverts + *(short *)pcVar18;
                  (*qglVertex3f)(paVar9->fv[0],paVar9->fv[1],paVar9->fv[2]);
                  iVar17 = iVar17 + -1;
                } while ((iVar17 != 0) &&
                        (pcVar22 = pcVar18 + 10, pcVar18 = pcVar24,
                        *(short *)pcVar22 < pvlightvalues_size));
              }
            }
            else {
              (*qglBegin)(5);
              if (iVar17 != 0) goto LAB_000e00e1;
            }
            (*qglEnd)();
            pcVar22 = pcVar24;
          }
        }
        else {
          fStack_170 = fStack_170 * 0.0009765625;
          fStack_174 = fStack_174 * 0.0009765625;
          if ((g_ForcedFaceFlags & 2U) != 0) goto LAB_000dff76;
          sVar3 = *(short *)pcVar22;
          while (iVar17 = (int)sVar3, iVar17 != 0) {
            pcVar24 = pcVar22 + 2;
            if (iVar17 < 0) {
              iVar17 = -iVar17;
              (*qglBegin)(6);
LAB_000e035d:
              iVar23 = (int)*(short *)(pcVar22 + 4);
              pcVar22 = pcVar24;
              if (iVar23 < pvlightvalues_size) {
                do {
                  (*qglTexCoord2f)((float)chrome[iVar23][0] * fStack_170,
                                   (float)chrome[iVar23][1] * fStack_174);
                  pavVar16 = pvlightvalues + *(short *)(pcVar22 + 2);
                  if (numlights == 0) {
                    GStack_13c = (*pavVar16)[0];
                    GStack_138 = (*pavVar16)[1];
                    GStack_134 = (*pavVar16)[2];
                  }
                  else {
                    R_LightLambert(lightpos[*(short *)pcVar22],
                                   (float *)(psVar5->name +
                                            *(short *)(pcVar22 + 2) * 0xc + iVar27 + -8),*pavVar16,
                                   &GStack_13c);
                  }
                  pcVar24 = pcVar22 + 8;
                  (*qglColor4f)(GStack_13c,GStack_138,GStack_134,r_blend);
                  paVar9 = pauxverts + *(short *)pcVar22;
                  (*qglVertex3f)(paVar9->fv[0],paVar9->fv[1],paVar9->fv[2]);
                  iVar17 = iVar17 + -1;
                } while ((iVar17 != 0) &&
                        (iVar23 = (int)*(short *)(pcVar22 + 10), pcVar22 = pcVar24,
                        iVar23 < pvlightvalues_size));
              }
            }
            else {
              (*qglBegin)(5);
              if (iVar17 != 0) goto LAB_000e035d;
            }
            (*qglEnd)();
            pcVar22 = pcVar24;
            sVar3 = *(short *)pcVar24;
          }
        }
      }
      else {
        iVar17 = *(short *)(pcStack_160 + *(int *)(pcVar24 + 8) * 2) * 0x50 + iVar14;
        fStack_170 = 1.0 / (float)*(int *)(psStack_154->name + iVar17 + 0x3c);
        fStack_174 = 1.0 / (float)*(int *)((int)psStack_154->eyeposition + iVar17 + -4);
        if ((g_ForcedFaceFlags & 2U) == 0) {
          R_StudioSetupSkin(psStack_154,(int)*(short *)(pcStack_160 + *(int *)(pcVar24 + 8) * 2));
          goto LAB_000e02f5;
        }
        if ((uVar25 & 2) == 0) goto LAB_000e00b6;
        fStack_170 = fStack_170 * 0.0009765625;
        fStack_174 = fStack_174 * 0.0009765625;
LAB_000dff76:
        sVar3 = *(short *)pcVar22;
        while (iVar17 = (int)sVar3, iVar17 != 0) {
          pcVar22 = pcVar22 + 2;
          pcVar24 = pcVar22;
          if (iVar17 < 0) {
            iVar17 = -iVar17;
            (*qglBegin)(6);
            iVar23 = iVar17;
LAB_000dffd0:
            do {
              (*qglTexCoord2f)((float)chrome[g_NormalIndex[*(short *)pcVar24]][0] * fStack_170,
                               (float)chrome[g_NormalIndex[*(short *)pcVar24]][1] * fStack_174);
              paVar9 = pauxverts + *(short *)pcVar24;
              (*qglVertex3f)(paVar9->fv[0],paVar9->fv[1],paVar9->fv[2]);
              iVar17 = iVar17 + -1;
              pcVar24 = pcVar24 + 8;
            } while (iVar17 != 0);
            pcVar22 = pcVar22 + iVar23 * 8;
          }
          else {
            (*qglBegin)(5);
            iVar23 = iVar17;
            if (iVar17 != 0) goto LAB_000dffd0;
          }
          (*qglEnd)();
          sVar3 = *(short *)pcVar22;
        }
      }
      if ((uVar25 & 0x40) != 0) {
        (*qglAlphaFunc)(0x205,0.0);
        (*qglDisable)(0xbc0);
      }
      if (((uVar25 & 0x20) != 0) && ((currententity->curstate).rendermode == 0)) {
        (*qglDisable)(0xbe2);
        (*qglDepthMask)('\x01');
        (*qglShadeModel)(0x1d00);
      }
      iStack_168 = iStack_168 + 1;
    } while (iStack_168 < psubmodel->nummesh);
  }
  (*qglEnable)(0xb44);
  if (iStack_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// R_StudioDynamicLight  @ 000d6420
void R_StudioDynamicLight(cl_entity_t *ent,alight_t *plight)

{
  float fVar1;
  vec_t vVar2;
  cl_entity_t *pcVar3;
  uint uVar4;
  int iVar5;
  msurface_t *pmVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  longdouble lVar10;
  longdouble lVar11;
  ulonglong uVar12;
  float fVar13;
  float fVar14;
  colorVec *local_a0;
  float local_9c;
  float local_94;
  float local_90;
  float local_8c;
  vec_t *pvStack_80;
  uint local_74;
  vec_t local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  colorVec local_3c;
  colorVec local_2c;
  
                    /* Unresolved local var: int lnum@[???]
                       Unresolved local var: vec3_t dist@[???]
                       Unresolved local var: colorVec down@[???]
                       Unresolved local var: vec3_t light@[???]
                       Unresolved local var: float total@[???]
                       Unresolved local var: float r@[???]
                       Unresolved local var: float add@[???]
                       Unresolved local var: vec3_t uporigin@[???]
                       Unresolved local var: vec3_t upend@[???]
                       Unresolved local var: float floor@[???]
                       Unresolved local var: vec3_t color@[???] */
  if (filterMode != false) {
    fVar14 = filterBrightness * 192.0;
    plight->shadelight = 0;
    plight->ambientlight = (int)fVar14;
    *plight->plightvec = 0.0;
    fVar13 = filterBrightness;
    fVar14 = filterColorRed * filterBrightness;
    plight->plightvec[1] = 0.0;
    plight->plightvec[2] = -1.0;
    plight->color[0] = fVar14;
    plight->color[1] = filterColorGreen * fVar13;
    plight->color[2] = fVar13 * filterColorBlue;
    return;
  }
  if (r_fullbright.value == 1.0) {
    plight->shadelight = 0;
    plight->ambientlight = 0xc0;
    *plight->plightvec = 0.0;
    plight->plightvec[1] = 0.0;
    plight->plightvec[2] = -1.0;
    plight->color[0] = 1.0;
    plight->color[1] = 1.0;
    plight->color[2] = 1.0;
    return;
  }
  local_60 = 0.0;
  local_5c = 0.0;
  if (((ent->curstate).effects & 0x10) == 0) {
    local_58 = -1.0;
    local_4c = -8.0;
  }
  else {
    local_58 = 1.0;
    local_4c = 8.0;
  }
  local_54 = ent->origin[0];
  local_50 = ent->origin[1];
  local_4c = ent->origin[2] - local_4c;
  if (movevars.skycolor_r + movevars.skycolor_g + movevars.skycolor_b != 0.0) {
                    /* Unresolved local var: vec3_t end@[???]
                       Unresolved local var: msurface_t * psurf@[???] */
    local_2c.r = (uint)(local_54 - movevars.skyvec_x * 8192.0);
    local_2c.g = (uint)(local_50 - movevars.skyvec_y * 8192.0);
    local_2c.b = (uint)(ent->origin[2] - movevars.skyvec_z * 8192.0);
    pmVar6 = SurfaceAtPoint(cl.worldmodel,(cl.worldmodel)->nodes,&local_54,(vec_t *)&local_2c);
    if (((ent->model->flags & 0x400) != 0) ||
       ((pmVar6 != (msurface_t *)0x0 && ((pmVar6->flags & 4) != 0)))) {
      local_60 = movevars.skyvec_x;
      local_5c = movevars.skyvec_y;
      local_58 = movevars.skyvec_z;
      local_74 = (uint)(longlong)ROUND(movevars.skycolor_r);
      fVar14 = (float)local_74;
      local_74 = (uint)(longlong)ROUND(movevars.skycolor_g);
      local_9c = (float)(longlong)ROUND(movevars.skycolor_b);
      if ((int)fVar14 + local_74 + (int)local_9c != 0) goto LAB_000d67fd;
    }
  }
  local_a0 = &local_2c;
  VectorScale(&local_60,2048.0,&local_48);
  local_48 = local_48 + local_54;
  local_44 = local_44 + local_50;
  local_40 = local_40 + local_4c;
  R_LightVec(&local_3c,&local_54,&local_48);
                    /* Unresolved local var: colorVec gcolor@[???]
                       Unresolved local var: float[4] grad@[???] */
  local_54 = local_54 - 16.0;
  local_50 = local_50 - 16.0;
  local_48 = local_48 - 16.0;
  local_44 = local_44 - 16.0;
  R_LightVec(local_a0,&local_54,&local_48);
  fVar14 = (float)((longdouble)(local_2c.g + local_2c.r + local_2c.b) / (longdouble)768.0);
  local_54 = local_54 + 32.0;
  local_48 = local_48 + 32.0;
  R_LightVec(local_a0,&local_54,&local_48);
  fVar13 = (float)((longdouble)(local_2c.r + local_2c.g + local_2c.b) / (longdouble)768.0);
  local_50 = local_50 + 32.0;
  local_44 = local_44 + 32.0;
  R_LightVec(local_a0,&local_54,&local_48);
  fVar1 = (float)((longdouble)(local_2c.r + local_2c.g + local_2c.b) / (longdouble)768.0);
  local_54 = local_54 - 32.0;
  local_48 = local_48 - 32.0;
  R_LightVec(local_a0,&local_54,&local_48);
  local_5c = (float)((longdouble)(local_2c.r + local_2c.g + local_2c.b) / (longdouble)768.0);
  local_60 = ((fVar14 - fVar13) - fVar1) + local_5c;
  local_5c = ((fVar13 + fVar14) - fVar1) - local_5c;
  VectorNormalize(&local_60);
  local_74 = local_3c.g;
  fVar14 = (float)local_3c.r;
  local_9c = (float)local_3c.b;
LAB_000d67fd:
  pcVar3 = currententity;
  local_a0 = &local_2c;
  pvStack_80 = &local_60;
  if (((currententity->curstate).renderfx == 0x15) &&
     (iVar7 = (currententity->curstate).iuser4, iVar7 != 10)) {
    fVar13 = (float)iVar7 / 10.0;
    uVar12 = (ulonglong)(uint)local_9c;
    local_9c = (float)(longlong)ROUND((float)(uint)fVar14 * fVar13);
    fVar14 = local_9c;
    local_9c = (float)(longlong)ROUND((float)local_74 * fVar13);
    local_74 = (uint)local_9c;
    local_9c = (float)(longlong)ROUND((float)uVar12 * fVar13);
  }
  (currententity->cvFloorColor).g = local_74;
  (pcVar3->cvFloorColor).r = (uint)fVar14;
  (pcVar3->cvFloorColor).b = (uint)local_9c;
  (pcVar3->cvFloorColor).a = local_3c.a;
  local_8c = (float)(uint)fVar14;
  uVar4 = local_74;
  if (local_74 < (uint)fVar14) {
    uVar4 = (uint)fVar14;
  }
  local_90 = (float)local_74;
  local_94 = (float)(uint)local_9c;
  lVar10 = (longdouble)uVar4;
  if ((longdouble)uVar4 <= (longdouble)(uint)local_9c) {
    lVar10 = (longdouble)(uint)local_9c;
  }
  lVar11 = (longdouble)1;
  if (lVar10 != (longdouble)0) {
    lVar11 = lVar10;
  }
  local_3c.r = (uint)fVar14;
  local_3c.g = local_74;
  local_3c.b = (uint)local_9c;
  VectorScale(pvStack_80,(float)lVar11,pvStack_80);
  pfVar8 = &cl_dlights[0].die;
  local_9c = (float)lVar11;
  do {
    while (*pfVar8 < (float)cl.time) {
LAB_000d68f0:
      pfVar8 = pfVar8 + 10;
      if (pfVar8 == (float *)(cl_lightstyle[0].map + 0x10)) goto LAB_000d6a1b;
    }
    local_2c.r = (uint)(ent->origin[0] - ((dlight_t *)(pfVar8 + -5))->origin[0]);
    local_2c.g = (uint)(ent->origin[1] - pfVar8[-4]);
    local_2c.b = (uint)(ent->origin[2] - pfVar8[-3]);
    fVar13 = Length((vec_t *)local_a0);
    fVar14 = pfVar8[-2] - fVar13;
    if (fVar14 <= 0.0) goto LAB_000d68f0;
    vVar2 = fVar14;
    if (1.0 < fVar13) {
      vVar2 = fVar14 / fVar13;
    }
    pfVar9 = pfVar8 + 10;
    local_9c = local_9c + fVar14;
    VectorScale((vec_t *)local_a0,vVar2,(vec_t *)local_a0);
    local_60 = local_60 + (float)local_2c.r;
    local_5c = local_5c + (float)local_2c.g;
    local_58 = local_58 + (float)local_2c.b;
    local_8c = (float)((color24 *)(pfVar8 + -1))->r * fVar14 * 0.00390625 + local_8c;
    local_90 = (float)*(byte *)((int)pfVar8 + -3) * fVar14 * 0.00390625 + local_90;
    local_94 = (float)*(byte *)((int)pfVar8 + -2) * fVar14 * 0.00390625 + local_94;
    pfVar8 = pfVar9;
  } while (pfVar9 != (float *)(cl_lightstyle[0].map + 0x10));
LAB_000d6a1b:
  vVar2 = 0.6;
  if ((ent->model->flags & 0x100) == 0) {
    if (v_direct.value <= 1.0) {
      vVar2 = 0.75;
      if (0.75 <= v_direct.value) {
        vVar2 = v_direct.value;
      }
    }
    else {
      vVar2 = 1.0;
    }
  }
  VectorScale(pvStack_80,vVar2,pvStack_80);
  fVar14 = Length(pvStack_80);
  iVar7 = (int)fVar14;
  plight->shadelight = iVar7;
  fVar14 = local_8c;
  if (local_8c <= local_90) {
    fVar14 = local_90;
  }
  if (fVar14 <= local_94) {
    fVar14 = local_94;
  }
  iVar5 = (int)(local_9c - (float)iVar7);
  plight->ambientlight = iVar5;
  if (fVar14 == 0.0) {
    plight->color[0] = 1.0;
    plight->color[1] = 1.0;
    plight->color[2] = 1.0;
  }
  else {
    fVar14 = 1.0 / fVar14;
    plight->color[0] = local_8c * fVar14;
    plight->color[1] = local_90 * fVar14;
    plight->color[2] = local_94 * fVar14;
  }
  if (0x80 < iVar5) {
    plight->ambientlight = 0x80;
    iVar5 = 0x80;
  }
  if (0xff < iVar7 + iVar5) {
    plight->shadelight = 0xff - iVar5;
  }
  VectorNormalize(pvStack_80);
  *plight->plightvec = local_60;
  plight->plightvec[1] = local_5c;
  plight->plightvec[2] = local_58;
  return;
}


// R_StudioEntityLight  @ 000d5da0
void R_StudioEntityLight(alight_t *plight)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  byte bVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  bool bVar14;
  cl_entity_t *pcVar15;
  uint uVar16;
  uint uVar17;
  dlight_t *pdVar18;
  uint uVar19;
  uint uVar20;
  float local_20 [4];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: dlight_t * el@[???]
                       Unresolved local var: vec3_t mid@[???]
                       Unresolved local var: vec3_t pos@[???]
                       Unresolved local var: float dist2@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: float[3] lstrength@[???]
                       Unresolved local var: float minstrength@[???] */
  pcVar15 = currententity;
  uVar20 = 0;
  numlights = 0;
  pdVar18 = cl_elights;
  local_20[0] = 0.0;
  local_20[1] = 0.0;
  fVar1 = currententity->origin[0];
  fVar2 = currententity->origin[1];
  fVar3 = currententity->origin[2];
  local_20[2] = 0.0;
  fVar13 = (float)cl.time;
  bVar14 = false;
  fVar11 = 1e+06;
LAB_000d5e00:
  uVar16 = uVar20;
  if ((fVar13 < pdVar18->die) && (fVar4 = pdVar18->radius, 0.0 < fVar4)) {
    uVar19 = pdVar18->key;
    uVar17 = numlights;
    fVar5 = fVar11;
    fVar6 = fVar13;
    fVar7 = fVar2;
    if ((uVar19 & 0xfff) == pcVar15->index) goto LAB_000d5f60;
    fVar5 = pdVar18->origin[0];
    fVar6 = pdVar18->origin[1];
    fVar7 = pdVar18->origin[2];
LAB_000d5e31:
    fVar7 = fVar3 - fVar7;
    fVar10 = fVar7 * fVar7 + (fVar2 - fVar6) * (fVar2 - fVar6) + (fVar1 - fVar5) * (fVar1 - fVar5);
    fVar12 = fVar4 * fVar4;
    if (fVar10 <= fVar12) {
      fVar10 = 1.0;
    }
    else {
      fVar10 = fVar12 / fVar10;
      if (fVar10 <= 0.004) goto LAB_000d5e82;
    }
    uVar19 = uVar20;
    if ((int)uVar20 < 3) goto LAB_000d5f9c;
    uVar19 = 0xffffffff;
    if ((local_20[0] < fVar11) && (uVar19 = (local_20[0] < fVar10) - 1, local_20[0] < fVar10)) {
      fVar11 = local_20[0];
    }
    if ((local_20[1] < fVar11) && (local_20[1] < fVar10)) {
      uVar19 = 1;
      fVar11 = local_20[1];
    }
    uVar17 = uVar20;
    fVar4 = fVar1;
    fVar5 = fVar1;
    fVar6 = fVar1;
    fVar7 = fVar1;
    if ((fVar11 <= local_20[2]) || (fVar10 <= local_20[2])) {
      if (uVar20 == 3) goto code_r0x000d6025;
    }
    else if (uVar20 == 3) {
      uVar19 = 2;
      fVar11 = local_20[2];
      goto LAB_000d5f9c;
    }
LAB_000d5f60:
    numlights = uVar17;
                    /* Unresolved local var: int att@[???] */
    uVar19 = (int)uVar19 >> 0xc & 0xf;
    fVar2 = fVar7;
    fVar11 = fVar5;
    fVar13 = fVar6;
    if (uVar19 == 0) {
      fVar5 = pcVar15->origin[0];
      pdVar18->origin[0] = fVar5;
      fVar6 = pcVar15->origin[1];
      pdVar18->origin[1] = fVar6;
      fVar7 = pcVar15->origin[2];
      pdVar18->origin[2] = fVar7;
    }
    else {
      fVar5 = pcVar15->angles[uVar19 * 3];
      pdVar18->origin[0] = fVar5;
      fVar6 = pcVar15->attachment[uVar19 - 1][1];
      pdVar18->origin[1] = fVar6;
      fVar7 = pcVar15->attachment[uVar19 - 1][2];
      pdVar18->origin[2] = fVar7;
    }
    goto LAB_000d5e31;
  }
  goto LAB_000d5e82;
code_r0x000d6025:
  uVar16 = 3;
  if (uVar19 != 0xffffffff) {
LAB_000d5f9c:
    bVar8 = (pdVar18->color).r;
    local_20[uVar19] = fVar10;
    iVar9 = lineargammatable[(uint)bVar8 * 4];
    locallightR2[uVar19] = fVar12;
    locallight[uVar19] = pdVar18;
    locallinearlight[uVar19][0] = iVar9;
    locallinearlight[uVar19][1] = lineargammatable[(uint)(pdVar18->color).g * 4];
    locallinearlight[uVar19][2] = lineargammatable[(uint)(pdVar18->color).b * 4];
    uVar16 = uVar20;
    if ((int)uVar20 <= (int)uVar19) {
      bVar14 = true;
      uVar16 = uVar19 + 1;
    }
  }
LAB_000d5e82:
  uVar20 = uVar16;
  pdVar18 = pdVar18 + 1;
  if (pdVar18 == (dlight_t *)&cl_playerindex) {
    if (bVar14) {
      numlights = uVar20;
    }
    return;
  }
  goto LAB_000d5e00;
}


// R_StudioEstimateGait  @ 000dede0
void R_StudioEstimateGait(entity_state_t *pplayer)

{
  float fVar1;
  player_info_t *ppVar2;
  cl_entity_t *pcVar3;
  float fVar4;
  double dVar5;
  float local_18;
  float local_14;
  float local_10;
  
  pcVar3 = currententity;
                    /* Unresolved local var: float dt@[???]
                       Unresolved local var: vec3_t est_velocity@[???] */
  ppVar2 = r_playerinfo;
  fVar1 = (float)((longdouble)cl.time - (longdouble)cl.oldtime);
  if (fVar1 < 0.0) {
    r_gaitmovement = 0.0;
    return;
  }
  if (fVar1 <= 1.0) {
    if (fVar1 == 0.0) {
      r_gaitmovement = 0.0;
      return;
    }
  }
  else {
    fVar1 = 1.0;
  }
  if (r_playerinfo->renderframe == r_framecount) {
    r_gaitmovement = 0.0;
    return;
  }
  if (cl_gaitestimation.value == 0.0) {
    local_18 = pplayer->velocity[0];
    local_14 = pplayer->velocity[1];
    local_10 = pplayer->velocity[2];
    fVar4 = Length(&local_18);
    r_gaitmovement = fVar4 * fVar1;
  }
  else {
    local_18 = currententity->origin[0] - r_playerinfo->prevgaitorigin[0];
    local_14 = currententity->origin[1] - r_playerinfo->prevgaitorigin[1];
    local_10 = currententity->origin[2];
    r_playerinfo->prevgaitorigin[0] = currententity->origin[0];
    local_10 = local_10 - ppVar2->prevgaitorigin[2];
    ppVar2->prevgaitorigin[1] = pcVar3->origin[1];
    ppVar2->prevgaitorigin[2] = pcVar3->origin[2];
    r_gaitmovement = Length(&local_18);
    if ((fVar1 <= 0.0) || (r_gaitmovement / fVar1 < 5.0)) goto LAB_000def00;
  }
  ppVar2 = r_playerinfo;
  if ((local_14 != 0.0) || (local_18 != 0.0)) {
    dVar5 = atan2((double)local_14,(double)local_18);
    fVar1 = ((float)dVar5 * 180.0) / 3.1415927;
    if (180.0 < fVar1) {
      ppVar2->gaityaw = 180.0;
      return;
    }
    fVar4 = -180.0;
    if (-180.0 <= fVar1) {
      fVar4 = fVar1;
    }
    ppVar2->gaityaw = fVar4;
    return;
  }
LAB_000def00:
                    /* Unresolved local var: float flYawDiff@[???] */
  fVar4 = currententity->angles[1] - r_playerinfo->gaityaw;
  fVar4 = fVar4 - (float)((int)(fVar4 / 360.0) * 0x168);
  if (180.0 < fVar4) {
    fVar4 = fVar4 - 360.0;
  }
  if (fVar4 < -180.0) {
    fVar4 = fVar4 + 360.0;
  }
  if (fVar1 < 0.25) {
    fVar1 = fVar1 * 4.0;
  }
  fVar1 = r_playerinfo->gaityaw + fVar1 * fVar4;
  r_playerinfo->gaityaw = fVar1 - (float)((int)(fVar1 / 360.0) * 0x168);
  r_gaitmovement = 0.0;
  return;
}


// R_StudioFlushSkins  @ 000de440
void R_StudioFlushSkins(int keynum)

{
                    /* Unresolved local var: int index@[???] */
  if (pDM_RemapSkin[keynum][0] != (skin_t *)0x0) {
    pDM_RemapSkin[keynum][0]->model = (model_t *)0x0;
  }
  if (pDM_RemapSkin[keynum][1] != (skin_t *)0x0) {
    pDM_RemapSkin[keynum][1]->model = (model_t *)0x0;
  }
  if (pDM_RemapSkin[keynum][2] != (skin_t *)0x0) {
    pDM_RemapSkin[keynum][2]->model = (model_t *)0x0;
  }
  if (pDM_RemapSkin[keynum][3] != (skin_t *)0x0) {
    pDM_RemapSkin[keynum][3]->model = (model_t *)0x0;
  }
  if (pDM_RemapSkin[keynum][4] != (skin_t *)0x0) {
    pDM_RemapSkin[keynum][4]->model = (model_t *)0x0;
  }
  if (pDM_RemapSkin[keynum][5] != (skin_t *)0x0) {
    pDM_RemapSkin[keynum][5]->model = (model_t *)0x0;
  }
  if (pDM_RemapSkin[keynum][6] != (skin_t *)0x0) {
    pDM_RemapSkin[keynum][6]->model = (model_t *)0x0;
  }
  if (pDM_RemapSkin[keynum][7] != (skin_t *)0x0) {
    pDM_RemapSkin[keynum][7]->model = (model_t *)0x0;
  }
  if (pDM_RemapSkin[keynum][8] != (skin_t *)0x0) {
    pDM_RemapSkin[keynum][8]->model = (model_t *)0x0;
  }
  if (pDM_RemapSkin[keynum][9] != (skin_t *)0x0) {
    pDM_RemapSkin[keynum][9]->model = (model_t *)0x0;
  }
  if (pDM_RemapSkin[keynum][10] != (skin_t *)0x0) {
    pDM_RemapSkin[keynum][10]->model = (model_t *)0x0;
  }
  return;
}


// R_StudioGetSkin  @ 000de550
skin_t * R_StudioGetSkin(int keynum,int index)

{
  int iVar1;
  skin_t *psVar2;
  
                    /* Unresolved local var: skin_t * pskin@[???] */
  iVar1 = r_remapindex;
  if (10 < index) {
    index = 0;
  }
  psVar2 = pDM_RemapSkin[keynum][index];
  if ((psVar2 == (skin_t *)0x0) || (keynum != psVar2->keynum)) {
    psVar2 = DM_RemapSkin[r_remapindex] + index;
    r_remapindex = (r_remapindex + 1) % 0x40;
    pDM_RemapSkin[keynum][index] = psVar2;
    DM_RemapSkin[iVar1][index].keynum = keynum;
    DM_RemapSkin[iVar1][index].topcolor = -1;
    DM_RemapSkin[iVar1][index].bottomcolor = -1;
  }
  return psVar2;
}


// R_StudioHull  @ 000da9d0
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
        goto LAB_000daeb4;
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
        if (iVar26 <= iVar27) goto LAB_000dae82;
      }
      iVar27 = 0x16;
      pcVar24 = pcVar24 + 0x20;
      pmVar25 = pmVar25 + 6;
    } while (0x16 < iVar26);
  }
LAB_000dae82:
  iVar26 = iVar26 - (uint)(bSkipShield == 1);
  *pNumHulls = iVar26;
  if (r_cachestudio.value != 0.0) {
    R_AddToStudioCache(frame,sequence,angles,origin,size,pcontroller,pblending,pModel,studio_hull,
                       iVar26);
    return studio_hull;
  }
LAB_000daeb4:
  return studio_hull;
}


// R_StudioLighting  @ 000d74f0
void __regparm3 R_StudioLighting(float *lv,int bone,int flags,vec_t *normal)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
                    /* Unresolved local var: float illum@[???]
                       Unresolved local var: float lightcos@[???] */
                    /* Unresolved local var: float r@[???] */
  fVar1 = *(float *)(bone + 8) * r_plightvec[2] +
          *(float *)(bone + 4) * r_plightvec[1] + *(float *)bone * r_plightvec[0];
  if (1.0 < fVar1) {
    fVar1 = 1.0;
  }
  fVar2 = (float)r_ambientlight;
  if (v_lambert1 < 1.0) {
    fVar1 = (v_lambert1 - fVar1) / (v_lambert1 + 1.0);
    if (0.0 < fVar1) {
      fVar2 = fVar1 * r_shadelight + fVar2;
    }
  }
  else {
    fVar2 = fVar2 + r_shadelight;
    fVar1 = ((v_lambert1 - 1.0) + fVar1) / v_lambert1;
    if (0.0 < fVar1) {
      fVar2 = fVar2 - fVar1 * r_shadelight;
    }
  }
  if (fVar2 <= 0.0) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0x3fc;
    if (fVar2 <= 255.0) {
      iVar3 = (int)(fVar2 * 4.0);
    }
  }
  *lv = (float)lightgammatable[iVar3] * 0.0009775171;
  return;
}


// R_StudioLighting  @ 000dda60
void R_StudioLighting(float *lv,int bone,int flags,vec_t *normal)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
                    /* Unresolved local var: float illum@[???]
                       Unresolved local var: float lightcos@[???] */
  fVar1 = (float)r_ambientlight;
  if ((flags & 1U) == 0) {
                    /* Unresolved local var: float r@[???] */
    if (bone == -1) {
      fVar2 = normal[2] * r_plightvec[2] + normal[1] * r_plightvec[1] + *normal * r_plightvec[0];
    }
    else {
      fVar2 = normal[2] * r_blightvec[bone][2] +
              normal[1] * r_blightvec[bone][1] + *normal * r_blightvec[bone][0];
    }
    if (1.0 < fVar2) {
      fVar2 = 1.0;
    }
    if (v_lambert1 < 1.0) {
      fVar2 = (v_lambert1 - fVar2) / (v_lambert1 + 1.0);
      if (0.0 < fVar2) {
        fVar1 = fVar2 * r_shadelight + fVar1;
      }
    }
    else {
      fVar1 = fVar1 + r_shadelight;
      fVar2 = ((v_lambert1 - 1.0) + fVar2) / v_lambert1;
      if (0.0 < fVar2) {
        fVar1 = fVar1 - fVar2 * r_shadelight;
      }
    }
    if (fVar1 <= 0.0) {
      iVar3 = 0;
      goto LAB_000ddaaa;
    }
  }
  else {
    fVar1 = r_shadelight * 0.8 + fVar1;
  }
  iVar3 = 0x3fc;
  if (fVar1 <= 255.0) {
    iVar3 = (int)(fVar1 * 4.0);
  }
LAB_000ddaaa:
  *lv = (float)lightgammatable[iVar3] * 0.0009775171;
  return;
}


// R_StudioMergeBones  @ 000dd6a0
void R_StudioMergeBones(model_t *psubmodel)

{
  studiohdr_t *psVar1;
  int iVar2;
  void *pvVar3;
  char *panim;
  int iVar4;
  dmodel_t *pdVar5;
  int iVar6;
  mstudioseqdesc_t *pseqdesc;
  vec_t *s1;
  char (*s2) [32];
  vec_t (*pavVar7) [3];
  float f;
  int local_5c;
  float (*local_58) [3] [4];
  float (*local_54) [3] [4];
  vec_t (*local_50) [4];
  float local_4c [3];
  vec_t local_40;
  vec_t local_30;
  vec_t local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: double f@[???]
                       Unresolved local var: int do_hunt@[???]
                       Unresolved local var: mstudiobone_t * pbones@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: mstudioanim_t * panim@[???]
                       Unresolved local var: float[3][4] bonematrix@[???] */
  psVar1 = pstudiohdr;
  iVar6 = (currententity->curstate).sequence;
  if (iVar6 < pstudiohdr->numseq) {
    iVar6 = iVar6 * 0xb0;
  }
  else {
    iVar6 = 0;
    (currententity->curstate).sequence = 0;
  }
  pseqdesc = (mstudioseqdesc_t *)(psVar1->name + iVar6 + psVar1->seqindex + -8);
  f = CL_StudioEstimateFrame(pseqdesc);
                    /* Unresolved local var: mstudioseqgroup_t * pseqgroup@[???]
                       Unresolved local var: cache_user_t * paSequences@[???] */
  iVar6 = pseqdesc->seqgroup;
  if (iVar6 == 0) {
    panim = psVar1->name + pseqdesc->animindex + -8;
  }
  else {
    iVar4 = psVar1->seqgroupindex;
    pdVar5 = psubmodel->submodels;
    iVar2 = iVar6;
    if (pdVar5 == (dmodel_t *)0x0) {
      pdVar5 = Mem_Calloc(0x10,4);
      psubmodel->submodels = pdVar5;
      iVar2 = pseqdesc->seqgroup;
    }
    pvVar3 = Cache_Check((cache_user_t *)(pdVar5->mins + iVar2));
    if (pvVar3 == (void *)0x0) {
      Con_DPrintf("loading %s\n",psVar1->name + iVar4 + iVar6 * 0x68 + 0x18);
      COM_LoadCacheFile(psVar1->name + iVar4 + iVar6 * 0x68 + 0x18,
                        (cache_user_s *)(pdVar5->mins + pseqdesc->seqgroup));
    }
    panim = (char *)(pseqdesc->animindex + (int)pdVar5->mins[pseqdesc->seqgroup]);
  }
  R_StudioCalcRotations
            (R_StudioMergeBones::pos,R_StudioMergeBones::q,pseqdesc,(mstudioanim_t *)panim,f);
  s1 = (vec_t *)(pstudiohdr->name + pstudiohdr->boneindex + -8);
  if (0 < pstudiohdr->numbones) {
    local_54 = bonetransform;
    pavVar7 = R_StudioMergeBones::pos;
    local_58 = lighttransform;
    local_50 = R_StudioMergeBones::q;
    local_5c = 0;
    do {
      iVar6 = 0;
      s2 = cached_bonename;
      if (0 < cached_numbones) {
        do {
          iVar4 = Q_stricmp((char *)s1,*s2);
          if (iVar4 == 0) {
            Q_memcpy(local_54,cached_bonetransform + iVar6,0x30);
            Q_memcpy(local_58,cached_lighttransform + iVar6,0x30);
            if (iVar6 < cached_numbones) goto LAB_000dd827;
            break;
          }
          iVar6 = iVar6 + 1;
          s2 = s2 + 1;
        } while (iVar6 < cached_numbones);
      }
      QuaternionMatrix(*local_50,(float (*) [4])local_4c);
      local_40 = (*pavVar7)[0];
      local_30 = (*pavVar7)[1];
      local_20 = (*pavVar7)[2];
      if (s1[8] == -NAN) {
        R_ConcatTransforms(rotationmatrix,(float (*) [4])local_4c,*local_54);
        R_ConcatTransforms(rotationmatrix,(float (*) [4])local_4c,*local_58);
        CL_FxTransform(currententity,*local_54);
      }
      else {
        R_ConcatTransforms(bonetransform[(int)s1[8]],(float (*) [4])local_4c,*local_54);
        R_ConcatTransforms(lighttransform[(int)s1[8]],(float (*) [4])local_4c,*local_58);
      }
LAB_000dd827:
      local_5c = local_5c + 1;
      s1 = s1 + 0x1c;
      pavVar7 = pavVar7 + 1;
      local_54 = local_54 + 1;
      local_58 = local_58 + 1;
      local_50 = local_50 + 1;
    } while (local_5c < pstudiohdr->numbones);
  }
  return;
}


// R_StudioPlayerBlend  @ 000db300
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


// R_StudioProcessGait  @ 000df100
void R_StudioProcessGait(entity_state_t *pplayer)

{
  float fVar1;
  float fVar2;
  float fVar3;
  player_info_t *ppVar4;
  studiohdr_t *psVar5;
  cl_entity_t *pcVar6;
  byte bVar7;
  int iVar8;
  float fVar9;
  
  pcVar6 = currententity;
                    /* Unresolved local var: mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: float dt@[???]
                       Unresolved local var: int iBlend@[???]
                       Unresolved local var: float flYaw@[???] */
  psVar5 = pstudiohdr;
  iVar8 = (currententity->curstate).sequence;
  if (iVar8 < pstudiohdr->numseq) {
    iVar8 = iVar8 * 0xb0;
  }
  else {
    (currententity->curstate).sequence = 0;
    iVar8 = 0;
  }
  fVar9 = pcVar6->angles[0];
  iVar8 = iVar8 + psVar5->seqindex;
  fVar3 = (float)(int)(fVar9 * 3.0);
  fVar1 = *(float *)((int)psVar5->bbmax + iVar8 + 0xc);
  if (fVar3 < fVar1) {
    bVar7 = '\0';
    fVar9 = fVar9 - fVar1 / 3.0;
    pcVar6->angles[0] = fVar9;
  }
  else {
    fVar2 = *(float *)((int)psVar5->bbmax + iVar8 + 0x14);
    if (fVar2 < fVar3) {
      bVar7 = 0xff;
      fVar9 = fVar9 - fVar2 / 3.0;
      pcVar6->angles[0] = fVar9;
    }
    else {
      bVar7 = '\x7f';
      if (0.1 <= fVar2 - fVar1) {
        fVar9 = 0.0;
        pcVar6->angles[0] = 0.0;
        bVar7 = (byte)(int)(((fVar3 - fVar1) * 255.0) / (fVar2 - fVar1));
      }
      else {
        pcVar6->angles[0] = 0.0;
        fVar9 = 0.0;
      }
    }
  }
  (pcVar6->latched).prevangles[0] = fVar9;
  (pcVar6->curstate).blending[0] = bVar7;
  (pcVar6->latched).prevblending[0] = bVar7;
  (pcVar6->latched).prevseqblending[0] = bVar7;
  fVar9 = (float)((longdouble)cl.time - (longdouble)cl.oldtime);
  if (fVar9 < 0.0) {
    fVar9 = 0.0;
  }
  else if (1.0 < fVar9) {
    fVar9 = 1.0;
  }
  R_StudioEstimateGait(pplayer);
  pcVar6 = currententity;
  ppVar4 = r_playerinfo;
  fVar1 = r_playerinfo->gaityaw;
  fVar3 = currententity->angles[1] - fVar1;
  fVar3 = fVar3 - (float)((int)(fVar3 / 360.0) * 0x168);
  if (fVar3 < -180.0) {
    fVar3 = fVar3 + 360.0;
  }
  if (180.0 < fVar3) {
    fVar3 = fVar3 - 360.0;
  }
  if (fVar3 <= 120.0) {
    if (fVar3 < -120.0) {
      r_playerinfo->gaityaw = fVar1 + 180.0;
      r_gaitmovement = -r_gaitmovement;
      fVar3 = fVar3 + 180.0;
    }
  }
  else {
    r_playerinfo->gaityaw = fVar1 - 180.0;
    r_gaitmovement = -r_gaitmovement;
    fVar3 = fVar3 - 180.0;
  }
  bVar7 = (byte)(int)((fVar3 * 0.25 + 30.0) / 0.23529412);
  (pcVar6->curstate).controller[0] = bVar7;
  (pcVar6->curstate).controller[1] = bVar7;
  (pcVar6->curstate).controller[2] = bVar7;
  (pcVar6->curstate).controller[3] = bVar7;
  (pcVar6->latched).prevcontroller[0] = bVar7;
  (pcVar6->latched).prevcontroller[1] = bVar7;
  (pcVar6->latched).prevcontroller[2] = bVar7;
  (pcVar6->latched).prevcontroller[3] = bVar7;
  fVar1 = ppVar4->gaityaw;
  if (fVar1 < 0.0) {
    fVar1 = fVar1 + 360.0;
  }
  pcVar6->angles[1] = fVar1;
  psVar5 = pstudiohdr;
  (pcVar6->latched).prevangles[1] = fVar1;
  iVar8 = pplayer->gaitsequence * 0xb0 + psVar5->seqindex;
  fVar1 = *(float *)((int)psVar5->eyeposition + iVar8);
  if (fVar1 <= 0.0) {
    fVar9 = fVar9 * *(float *)(psVar5->name + iVar8 + 0x18) + ppVar4->gaitframe;
  }
  else {
    fVar9 = (float)*(int *)(psVar5->name + iVar8 + 0x30) * (r_gaitmovement / fVar1) +
            ppVar4->gaitframe;
  }
  ppVar4->gaitframe = fVar9;
  fVar9 = fVar9 - (float)((int)(fVar9 / (float)*(int *)(psVar5->name + iVar8 + 0x30)) *
                         *(int *)(psVar5->name + iVar8 + 0x30));
  ppVar4->gaitframe = fVar9;
  if (fVar9 < 0.0) {
    ppVar4->gaitframe = (float)*(int *)(psVar5->name + iVar8 + 0x30) + fVar9;
  }
  return;
}


// R_StudioReloadSkin  @ 000de7e0
byte * R_StudioReloadSkin(model_t *pModel,int index,skin_t *pskin)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int *dest;
  byte *p;
  int iVar4;
  int iVar5;
  int *piVar6;
  
                    /* Unresolved local var: int modelindex@[???]
                       Unresolved local var: cache_user_t * pCache@[???]
                       Unresolved local var: int * pData@[???]
                       Unresolved local var: mstudiotexture_t * ptexture@[???]
                       Unresolved local var: byte * pbase@[???]
                       Unresolved local var: int size@[???] */
  iVar5 = (int)(pModel[-0x9e46].name + 0x10) >> 3;
  if ((uint)(iVar5 * 0x1a1f58d1) < 0x400) {
    pvVar3 = Cache_Check(model_texture_cache[iVar5 * 0x1f58d1] + index);
    if (pvVar3 == (void *)0x0) {
      p = COM_LoadFileForMe(pModel->name,(int *)0x0);
      iVar4 = index * 0x50 + *(int *)(p + 0xb8);
      iVar1 = *(int *)(p + iVar4 + 0x48);
      iVar2 = *(int *)(p + iVar4 + 0x44);
      Cache_Alloc(model_texture_cache[iVar5 * 0x1f58d1] + index,iVar2 * iVar1 + 0x308,pskin->name);
      piVar6 = model_texture_cache[iVar5 * 0x1f58d1][index].data;
      dest = piVar6 + 2;
      *piVar6 = *(int *)(p + iVar4 + 0x44);
      piVar6[1] = *(int *)(p + iVar4 + 0x48);
      Q_memcpy(dest,p + *(int *)(p + iVar4 + 0x4c),iVar2 * iVar1 + 0x300);
      Mem_Free(p);
    }
    else {
      piVar6 = model_texture_cache[iVar5 * 0x1f58d1][index].data;
      dest = piVar6 + 2;
    }
    pskin->index = index;
    pskin->width = *piVar6;
    pskin->height = piVar6[1];
  }
  else {
    dest = (int *)0x0;
  }
  return (byte *)dest;
}


// R_StudioRenderFinal  @ 000e0f30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioRenderFinal(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float an@[???]
                       Unresolved local var: int rendermode@[???] */
  pauxverts = auxverts;
  pvlightvalues = lightvalues;
  pvlightvalues_size = 0x800;
  shadevector[0] = 1.0;
  shadevector[1] = -0.0;
  shadevector[2] = 1.0;
  VectorNormalize(shadevector);
  GL_DisableMultitexture();
  (*qglPushMatrix)();
  (*qglShadeModel)(0x1d01);
  (*qglTexEnvf)(0x2300,0x2200,8448.0);
  if (gl_affinemodels.value != 0.0) {
    (*qglHint)(0xc50,0x1101);
  }
  iVar3 = 5;
  if (g_ForcedFaceFlags == 0) {
    iVar3 = (currententity->curstate).rendermode;
  }
  if (r_drawentities.value == 2.0) {
    R_StudioDrawBones();
  }
  else if (r_drawentities.value == 3.0) {
    R_StudioDrawHulls();
  }
  else if (0 < pstudiohdr->numbodyparts) {
    iVar2 = 0;
    do {
      while( true ) {
                    /* Unresolved local var: int index@[???] */
        pbodypart = (mstudiobodyparts_t *)
                    (pstudiohdr->name + pstudiohdr->bodypartindex + iVar2 * 0x4c + -8);
        psubmodel = (mstudiomodel_t *)
                    (pstudiohdr->name +
                    (((currententity->curstate).body / pbodypart->base) % pbodypart->nummodels) *
                    0x70 + pbodypart->modelindex + -8);
        if (r_dointerp != 0) {
          currententity->trivial_accept = 0;
        }
        if (iVar3 != 0) {
          if (iVar3 == 1) {
            (*qglBlendFunc)(0x302,0x303);
            (*qglTexEnvi)(0x2300,0x2200,0x1906);
          }
          else if (iVar3 == 5) {
            (*qglTexEnvf)(0x2300,0x2200,8448.0);
            (*qglBlendFunc)(1,1);
            (*qglColor4f)(r_blend,r_blend,r_blend,1.0);
            (*qglDepthMask)('\0');
          }
          else {
            (*qglTexEnvf)(0x2300,0x2200,8448.0);
            (*qglBlendFunc)(0x302,0x303);
            (*qglColor4f)(1.0,1.0,1.0,r_blend);
            (*qglDepthMask)('\x01');
          }
          (*qglEnable)(0xbe2);
        }
        R_GLStudioDrawPoints();
        (*qglDepthMask)('\x01');
        if (((r_shadows.value != 0.0) && (iVar3 != 5)) && ((r_model->flags & 0x100) == 0)) break;
        iVar2 = iVar2 + 1;
        if (pstudiohdr->numbodyparts <= iVar2) goto LAB_000e11cd;
      }
                    /* Unresolved local var: float color@[???] */
      fVar1 = r_blend * 0.5;
      (*qglDisable)(0xde1);
      (*qglBlendFunc)(0x302,0x303);
      (*qglEnable)(0xbe2);
      (*qglColor4f)(0.0,0.0,0.0,1.0 - (1.0 - fVar1));
      if ((gl_ztrick.value == 0.0) || (gldepthmin < 0.5)) {
        (*qglDepthFunc)(0x201);
      }
      else {
        (*qglDepthFunc)(0x204);
      }
      GLR_StudioDrawShadow();
      if ((gl_ztrick.value == 0.0) || (gldepthmin < 0.5)) {
        (*qglDepthFunc)(0x203);
      }
      else {
        (*qglDepthFunc)(0x206);
      }
      iVar2 = iVar2 + 1;
      (*qglEnable)(0xde1);
      (*qglDisable)(0xbe2);
      (*qglColor4f)(1.0,1.0,1.0,1.0);
      (*qglShadeModel)(0x1d01);
    } while (iVar2 < pstudiohdr->numbodyparts);
  }
LAB_000e11cd:
  if (r_drawentities.value == 4.0) {
    (*tri.RenderMode)(5);
    R_StudioDrawHulls();
    (*tri.RenderMode)(0);
  }
  if (iVar3 != 0) {
    (*qglDisable)(0xbe2);
  }
  (*qglTexEnvf)(0x2300,0x2200,7681.0);
  (*qglShadeModel)(0x1d00);
  if (gl_affinemodels.value == 0.0) {
                    /* WARNING: Could not recover jumptable at 0x000e1235. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglPopMatrix)();
    return;
  }
  (*qglHint)(0xc50,0x1102);
                    /* WARNING: Could not recover jumptable at 0x000e13cd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglPopMatrix)();
  return;
}


// R_StudioRenderModel  @ 000e14b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioRenderModel(void)

{
  g_ChromeOrigin[0] = r_origin[0];
  g_ChromeOrigin[1] = r_origin[1];
  g_ChromeOrigin[2] = r_origin[2];
  g_ForcedFaceFlags = 0;
  if ((currententity->curstate).renderfx != 0x13) {
    R_StudioRenderFinal();
    return;
  }
  (currententity->curstate).renderfx = 0;
  R_StudioRenderFinal();
  g_ForcedFaceFlags = 2;
  (*tri.SpriteTexture)(cl_sprite_shell,0);
  (currententity->curstate).renderfx = 0x13;
  R_StudioRenderFinal();
  return;
}


// R_StudioSaveBones  @ 000dd5c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioSaveBones(void)

{
  vec_t *src;
  int iVar1;
  char (*dest) [32];
  float (*dest_00) [3] [4];
  float (*dest_01) [3] [4];
  float (*src_00) [3] [4];
  float (*local_28) [3] [4];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: mstudiobone_t * pbones@[???] */
  cached_numbones = pstudiohdr->numbones;
  if (0 < cached_numbones) {
    src = (vec_t *)(pstudiohdr->name + pstudiohdr->boneindex + -8);
    iVar1 = 0;
    local_28 = lighttransform;
    dest = cached_bonename;
    dest_00 = cached_bonetransform;
    dest_01 = cached_lighttransform;
    src_00 = bonetransform;
    do {
      Q_strncpy(*dest,(char *)src,0x1f);
      (*dest)[0x1f] = '\0';
      Q_memcpy(dest_00,src_00,0x30);
      Q_memcpy(dest_01,local_28,0x30);
      local_28 = local_28 + 1;
      iVar1 = iVar1 + 1;
      src = src + 0x1c;
      dest = dest + 1;
      dest_00 = dest_00 + 1;
      dest_01 = dest_01 + 1;
      src_00 = src_00 + 1;
    } while (iVar1 < pstudiohdr->numbones);
  }
  return;
}


// R_StudioSetUpTransform  @ 000dbfe0
void R_StudioSetUpTransform(int trivial_accept)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float local_2c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t angles@[???]
                       Unresolved local var: vec3_t modelpos@[???] */
  fVar1 = currententity->origin[0];
  fVar2 = currententity->origin[1];
  local_2c = currententity->origin[2];
  iVar5 = (currententity->curstate).movetype;
  local_10 = (currententity->curstate).angles[2];
  local_18 = (currententity->curstate).angles[0];
  local_14 = (currententity->curstate).angles[1];
  if (iVar5 == 4) {
                    /* Unresolved local var: float f@[???]
                       Unresolved local var: float d@[???] */
    fVar3 = (currententity->curstate).animtime;
    if ((fVar3 + 1.0 <= (float)cl.time) ||
       (fVar4 = (currententity->latched).prevanimtime, fVar3 == fVar4)) {
      fVar3 = 0.0;
    }
    else {
      fVar3 = ((float)cl.time - fVar3) / (fVar3 - fVar4);
    }
    if (r_dointerp == 0) {
      fVar3 = 0.0;
    }
    else {
      fVar3 = fVar3 - 1.0;
    }
    fVar1 = (fVar1 - (currententity->latched).prevorigin[0]) * fVar3 + fVar1;
    fVar2 = (currententity->origin[1] - (currententity->latched).prevorigin[1]) * fVar3 + fVar2;
    local_2c = (currententity->origin[2] - (currententity->latched).prevorigin[2]) * fVar3 +
               local_2c;
                    /* Unresolved local var: float ang1@[???]
                       Unresolved local var: float ang2@[???] */
    fVar4 = currententity->angles[0] - (currententity->latched).prevangles[0];
    if (180.0 < fVar4) {
      fVar4 = fVar4 - 360.0;
    }
    else if (fVar4 < -180.0) {
      fVar4 = fVar4 + 360.0;
    }
    local_18 = fVar4 * fVar3 + local_18;
    fVar4 = currententity->angles[1] - (currententity->latched).prevangles[1];
    if (fVar4 <= 180.0) {
      if (fVar4 < -180.0) {
        fVar4 = fVar4 + 360.0;
      }
    }
    else {
      fVar4 = fVar4 - 360.0;
    }
    local_14 = fVar4 * fVar3 + local_14;
    fVar4 = currententity->angles[2] - (currententity->latched).prevangles[2];
    if (fVar4 <= 180.0) {
      if (fVar4 < -180.0) {
        fVar4 = fVar4 + 360.0;
      }
    }
    else {
      fVar4 = fVar4 - 360.0;
    }
    local_10 = fVar4 * fVar3 + local_10;
  }
  else if (iVar5 != 0) {
    local_14 = currententity->angles[1];
    local_10 = currententity->angles[2];
    local_18 = currententity->angles[0];
  }
  local_18 = -local_18;
  AngleMatrix(&local_18,rotationmatrix);
  rotationmatrix[2][3] = local_2c;
  rotationmatrix[0][3] = fVar1;
  rotationmatrix[1][3] = fVar2;
  return;
}


// R_StudioSetupBones  @ 000dcaa0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioSetupBones(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  model_t *pmVar6;
  void *pvVar7;
  int iVar8;
  player_info_t *ppVar9;
  int iVar10;
  dmodel_t *pdVar11;
  float (*out) [3] [4];
  int iVar12;
  mstudioseqdesc_t *pmVar13;
  studiohdr_t *psVar14;
  vec_t *pvVar15;
  int *piVar16;
  char *pcVar17;
  int iVar18;
  vec_t (*dest) [4];
  vec_t (*pavVar19) [3];
  vec_t (*src) [3];
  float (*out_00) [3] [4];
  float fVar20;
  int local_74;
  vec_t (*local_6c) [4];
  float local_4c;
  float local_48;
  float local_44;
  vec_t local_40;
  float local_3c;
  float local_38;
  float local_34;
  vec_t local_30;
  float local_2c;
  float local_28;
  float local_24;
  vec_t local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: double f@[???]
                       Unresolved local var: mstudiobone_t * pbones@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: mstudioanim_t * panim@[???]
                       Unresolved local var: float[3][4] bonematrix@[???] */
  psVar14 = pstudiohdr;
  iVar12 = (currententity->curstate).sequence;
  if (iVar12 < pstudiohdr->numseq) {
    iVar12 = iVar12 * 0xb0;
  }
  else {
    iVar12 = 0;
    (currententity->curstate).sequence = 0;
  }
  pmVar13 = (mstudioseqdesc_t *)(psVar14->name + iVar12 + psVar14->seqindex + -8);
  fVar20 = CL_StudioEstimateFrame(pmVar13);
  pmVar6 = r_model;
                    /* Unresolved local var: mstudioseqgroup_t * pseqgroup@[???]
                       Unresolved local var: cache_user_t * paSequences@[???] */
  iVar12 = pmVar13->seqgroup;
  if (iVar12 == 0) {
    pcVar17 = psVar14->name + pmVar13->animindex + -8;
  }
  else {
    iVar18 = psVar14->seqgroupindex;
    pdVar11 = r_model->submodels;
    iVar10 = iVar12;
    if (pdVar11 == (dmodel_t *)0x0) {
      pdVar11 = Mem_Calloc(0x10,4);
      pmVar6->submodels = pdVar11;
      iVar10 = pmVar13->seqgroup;
    }
    pvVar7 = Cache_Check((cache_user_t *)(pdVar11->mins + iVar10));
    if (pvVar7 == (void *)0x0) {
      Con_DPrintf("loading %s\n",psVar14->name + iVar18 + iVar12 * 0x68 + 0x18);
      COM_LoadCacheFile(psVar14->name + iVar18 + iVar12 * 0x68 + 0x18,
                        (cache_user_s *)(pdVar11->mins + pmVar13->seqgroup));
    }
    pcVar17 = (char *)(pmVar13->animindex + (int)pdVar11->mins[pmVar13->seqgroup]);
  }
  R_StudioCalcRotations
            (R_StudioSetupBones::pos,R_StudioSetupBones::q,pmVar13,(mstudioanim_t *)pcVar17,fVar20);
  if (1 < pmVar13->numblends) {
                    /* Unresolved local var: float s@[???]
                       Unresolved local var: float dadt@[???] */
    pcVar17 = pcVar17 + pstudiohdr->numbones * 0xc;
    R_StudioCalcRotations
              (R_StudioSetupBones::pos2,R_StudioSetupBones::q2,pmVar13,(mstudioanim_t *)pcVar17,
               fVar20);
                    /* Unresolved local var: float dadt@[???] */
                    /* Unresolved local var: float dadt@[???] */
    if ((r_dointerp == 0) ||
       (fVar1 = (currententity->curstate).animtime,
       fVar1 < (currententity->latched).prevanimtime + 0.01)) {
      fVar1 = 0.0;
      local_6c = (vec_t (*) [4])0x3f800000;
    }
    else {
      local_6c = (vec_t (*) [4])(((float)cl.time - fVar1) / 0.1);
      if ((float)local_6c <= 2.0) {
        fVar1 = 1.0 - (float)local_6c;
      }
      else {
        local_6c = (vec_t (*) [4])0x40000000;
        fVar1 = -1.0;
      }
    }
    R_StudioSlerpBones(R_StudioSetupBones::q,R_StudioSetupBones::pos,R_StudioSetupBones::q2,
                       R_StudioSetupBones::pos2,
                       ((float)(currententity->latched).prevblending[0] * fVar1 +
                       (float)(currententity->curstate).blending[0] * (float)local_6c) / 255.0);
    if (pmVar13->numblends == 4) {
      iVar12 = pstudiohdr->numbones;
      R_StudioCalcRotations
                (R_StudioSetupBones::pos3,R_StudioSetupBones::q3,pmVar13,
                 (mstudioanim_t *)(pcVar17 + iVar12 * 0xc),fVar20);
      R_StudioCalcRotations
                (R_StudioSetupBones::pos4,R_StudioSetupBones::q4,pmVar13,
                 (mstudioanim_t *)(pcVar17 + iVar12 * 0xc + pstudiohdr->numbones * 0xc),fVar20);
      R_StudioSlerpBones(R_StudioSetupBones::q3,R_StudioSetupBones::pos3,R_StudioSetupBones::q4,
                         R_StudioSetupBones::pos4,
                         ((float)(currententity->latched).prevblending[0] * fVar1 +
                         (float)(currententity->curstate).blending[0] * (float)local_6c) / 255.0);
      R_StudioSlerpBones(R_StudioSetupBones::q,R_StudioSetupBones::pos,R_StudioSetupBones::q3,
                         R_StudioSetupBones::pos3,
                         ((float)(currententity->latched).prevblending[1] * fVar1 +
                         (float)(currententity->curstate).blending[1] * (float)local_6c) / 255.0);
    }
  }
  psVar14 = pstudiohdr;
  pmVar6 = r_model;
  if ((((r_dointerp == 0) || (fVar1 = (currententity->latched).sequencetime, fVar1 == 0.0)) ||
      (fVar1 + 0.2 <= (float)cl.time)) ||
     (iVar12 = (currententity->latched).prevsequence, pstudiohdr->numseq <= iVar12)) {
    (currententity->latched).prevframe = fVar20;
  }
  else {
                    /* Unresolved local var: float s@[???] */
    pmVar13 = (mstudioseqdesc_t *)(pstudiohdr->name + iVar12 * 0xb0 + pstudiohdr->seqindex + -8);
                    /* Unresolved local var: mstudioseqgroup_t * pseqgroup@[???]
                       Unresolved local var: cache_user_t * paSequences@[???] */
    iVar12 = pmVar13->seqgroup;
    if (iVar12 == 0) {
      pcVar17 = pstudiohdr->name + pmVar13->animindex + -8;
    }
    else {
      iVar18 = pstudiohdr->seqgroupindex;
      pdVar11 = r_model->submodels;
      iVar10 = iVar12;
      if (pdVar11 == (dmodel_t *)0x0) {
        pdVar11 = Mem_Calloc(0x10,4);
        pmVar6->submodels = pdVar11;
        iVar10 = pmVar13->seqgroup;
      }
      pvVar7 = Cache_Check((cache_user_t *)(pdVar11->mins + iVar10));
      if (pvVar7 == (void *)0x0) {
        pcVar17 = psVar14->name + iVar18 + iVar12 * 0x68 + 0x18;
        Con_DPrintf("loading %s\n",pcVar17);
        COM_LoadCacheFile(pcVar17,(cache_user_s *)(pdVar11->mins + pmVar13->seqgroup));
      }
      pcVar17 = (char *)(pmVar13->animindex + (int)pdVar11->mins[pmVar13->seqgroup]);
    }
    R_StudioCalcRotations
              (R_StudioSetupBones::lexical_block_4::pos1b,R_StudioSetupBones::lexical_block_4::q1b,
               pmVar13,(mstudioanim_t *)pcVar17,(currententity->latched).prevframe);
    if (1 < pmVar13->numblends) {
      pcVar17 = pcVar17 + pstudiohdr->numbones * 0xc;
      R_StudioCalcRotations
                (R_StudioSetupBones::pos2,R_StudioSetupBones::q2,pmVar13,(mstudioanim_t *)pcVar17,
                 (currententity->latched).prevframe);
      R_StudioSlerpBones(R_StudioSetupBones::lexical_block_4::q1b,
                         R_StudioSetupBones::lexical_block_4::pos1b,R_StudioSetupBones::q2,
                         R_StudioSetupBones::pos2,
                         (float)(currententity->latched).prevseqblending[0] / 255.0);
      if (pmVar13->numblends == 4) {
        iVar12 = pstudiohdr->numbones;
        R_StudioCalcRotations
                  (R_StudioSetupBones::pos3,R_StudioSetupBones::q3,pmVar13,
                   (mstudioanim_t *)(pcVar17 + iVar12 * 0xc),(currententity->latched).prevframe);
        R_StudioCalcRotations
                  (R_StudioSetupBones::pos4,R_StudioSetupBones::q4,pmVar13,
                   (mstudioanim_t *)(pcVar17 + iVar12 * 0xc + pstudiohdr->numbones * 0xc),
                   (currententity->latched).prevframe);
        R_StudioSlerpBones(R_StudioSetupBones::q3,R_StudioSetupBones::pos3,R_StudioSetupBones::q4,
                           R_StudioSetupBones::pos4,
                           (float)(currententity->latched).prevseqblending[0] / 255.0);
        R_StudioSlerpBones(R_StudioSetupBones::lexical_block_4::q1b,
                           R_StudioSetupBones::lexical_block_4::pos1b,R_StudioSetupBones::q3,
                           R_StudioSetupBones::pos3,
                           (float)(currententity->latched).prevseqblending[1] / 255.0);
      }
    }
    R_StudioSlerpBones(R_StudioSetupBones::q,R_StudioSetupBones::pos,
                       R_StudioSetupBones::lexical_block_4::q1b,
                       R_StudioSetupBones::lexical_block_4::pos1b,
                       1.0 - ((float)cl.time - (currententity->latched).sequencetime) / 0.2);
    psVar14 = pstudiohdr;
  }
  ppVar9 = r_playerinfo;
  iVar12 = psVar14->boneindex;
  if ((r_playerinfo == (player_info_t *)0x0) || (iVar18 = r_playerinfo->gaitsequence, iVar18 == 0))
  {
    iVar18 = psVar14->numbones;
  }
  else {
    if (iVar18 < psVar14->numseq) {
      iVar18 = iVar18 * 0xb0;
    }
    else {
      iVar18 = 0;
      r_playerinfo->gaitsequence = 0;
    }
    pmVar6 = r_model;
    pmVar13 = (mstudioseqdesc_t *)(psVar14->name + iVar18 + psVar14->seqindex + -8);
                    /* Unresolved local var: mstudioseqgroup_t * pseqgroup@[???]
                       Unresolved local var: cache_user_t * paSequences@[???] */
    iVar18 = pmVar13->seqgroup;
    if (iVar18 == 0) {
      pcVar17 = psVar14->name + pmVar13->animindex + -8;
    }
    else {
      iVar10 = psVar14->seqgroupindex;
      pdVar11 = r_model->submodels;
      iVar8 = iVar18;
      if (pdVar11 == (dmodel_t *)0x0) {
        pdVar11 = Mem_Calloc(0x10,4);
        pmVar6->submodels = pdVar11;
        iVar8 = pmVar13->seqgroup;
      }
      pvVar7 = Cache_Check((cache_user_t *)(pdVar11->mins + iVar8));
      if (pvVar7 == (void *)0x0) {
        Con_DPrintf("loading %s\n",psVar14->name + iVar10 + iVar18 * 0x68 + 0x18);
        COM_LoadCacheFile(psVar14->name + iVar10 + iVar18 * 0x68 + 0x18,
                          (cache_user_s *)(pdVar11->mins + pmVar13->seqgroup));
      }
      pcVar17 = (char *)(pmVar13->animindex + (int)pdVar11->mins[pmVar13->seqgroup]);
      ppVar9 = r_playerinfo;
    }
    R_StudioCalcRotations
              (R_StudioSetupBones::pos2,R_StudioSetupBones::q2,pmVar13,(mstudioanim_t *)pcVar17,
               ppVar9->gaitframe);
    if (pstudiohdr->numbones < 1) {
      return;
    }
    local_6c = R_StudioSetupBones::q2;
    local_74 = 0;
    pvVar15 = (vec_t *)(psVar14->name + iVar12 + -8);
    pavVar19 = R_StudioSetupBones::pos;
    dest = R_StudioSetupBones::q;
    src = R_StudioSetupBones::pos2;
    do {
      iVar18 = Q_strcmp((char *)pvVar15,"Bip01 Spine");
      if (iVar18 == 0) {
        iVar18 = pstudiohdr->numbones;
        break;
      }
      pvVar15 = pvVar15 + 0x1c;
      Q_memcpy(pavVar19,src,0xc);
      Q_memcpy(dest,local_6c,0x10);
      local_74 = local_74 + 1;
      local_6c = local_6c + 1;
      iVar18 = pstudiohdr->numbones;
      pavVar19 = pavVar19 + 1;
      dest = dest + 1;
      src = src + 1;
    } while (local_74 < iVar18);
  }
  if (0 < iVar18) {
    pvVar15 = R_StudioSetupBones::q[0] + 1;
    pavVar19 = R_StudioSetupBones::pos;
    out = bonetransform;
    out_00 = lighttransform;
    iVar18 = 0;
    piVar16 = (int *)((int)(psVar14->name + iVar12 + -8) + 0x20);
    do {
      fVar20 = *pvVar15;
      fVar3 = (fVar20 + fVar20) * fVar20;
      fVar1 = pvVar15[1];
      local_38 = (fVar1 + fVar1) * fVar1;
      local_4c = (1.0 - fVar3) - local_38;
      fVar2 = (*(vec_t (*) [4])(pvVar15 + -1))[0];
      fVar4 = fVar2 + fVar2;
      fVar5 = pvVar15[2] + pvVar15[2];
      local_3c = fVar20 * fVar4 + fVar1 * fVar5;
      local_2c = fVar1 * fVar4 - fVar20 * fVar5;
      local_48 = fVar20 * fVar4 - fVar1 * fVar5;
      local_24 = 1.0 - fVar4 * fVar2;
      local_38 = local_24 - local_38;
      local_34 = fVar1 * (fVar20 + fVar20);
      local_28 = local_34 + fVar5 * fVar2;
      local_44 = fVar20 * fVar5 + fVar1 * fVar4;
      local_34 = local_34 - fVar5 * fVar2;
      local_24 = local_24 - fVar3;
      local_40 = (*pavVar19)[0];
      local_30 = (*pavVar19)[1];
      local_20 = (*pavVar19)[2];
      if (*piVar16 == -1) {
        R_ConcatTransforms(rotationmatrix,(float (*) [4])&local_4c,*out);
        R_ConcatTransforms(rotationmatrix,(float (*) [4])&local_4c,*out_00);
        CL_FxTransform(currententity,*out);
      }
      else {
        R_ConcatTransforms(bonetransform[*piVar16],(float (*) [4])&local_4c,*out);
        R_ConcatTransforms(lighttransform[*piVar16],(float (*) [4])&local_4c,*out_00);
      }
      iVar18 = iVar18 + 1;
      pvVar15 = pvVar15 + 4;
      pavVar19 = pavVar19 + 1;
      piVar16 = piVar16 + 0x1c;
      out = out + 1;
      out_00 = out_00 + 1;
    } while (iVar18 < pstudiohdr->numbones);
  }
  return;
}


// R_StudioSetupLighting  @ 000d80c0
void R_StudioSetupLighting(alight_t *plighting)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  studiohdr_t *psVar5;
  float (*paafVar6) [3] [4];
  int iVar7;
  vec_t (*pavVar8) [3];
  
                    /* Unresolved local var: int i@[???] */
  psVar5 = pstudiohdr;
  r_ambientlight = plighting->ambientlight;
  r_shadelight = (float)plighting->shadelight;
  pfVar4 = plighting->plightvec;
  fVar1 = *pfVar4;
  fVar2 = pfVar4[1];
  fVar3 = pfVar4[2];
  r_plightvec[0] = fVar1;
  r_plightvec[1] = fVar2;
  r_plightvec[2] = fVar3;
  if (0 < pstudiohdr->numbones) {
    iVar7 = 0;
    paafVar6 = lighttransform;
    pavVar8 = r_blightvec;
    do {
      iVar7 = iVar7 + 1;
      (*pavVar8)[0] =
           (*paafVar6)[2][0] * fVar3 + (*paafVar6)[1][0] * fVar2 + (*paafVar6)[0][0] * fVar1;
      (*pavVar8)[1] =
           (*paafVar6)[2][1] * fVar3 + (*paafVar6)[1][1] * fVar2 + (*paafVar6)[0][1] * fVar1;
      (*pavVar8)[2] =
           (*paafVar6)[2][2] * fVar3 + (*paafVar6)[1][2] * fVar2 + (*paafVar6)[0][2] * fVar1;
      paafVar6 = paafVar6 + 1;
      pavVar8 = pavVar8 + 1;
    } while (iVar7 < psVar5->numbones);
  }
  r_icolormix.r = (int)(plighting->color[0] * 49407.0) & 0xff00;
  r_icolormix.g = (int)(plighting->color[1] * 49407.0) & 0xff00;
  r_icolormix.b = (int)(plighting->color[2] * 49407.0) & 0xff00;
  r_colormix[1] = plighting->color[1];
  r_colormix[2] = plighting->color[2];
  r_colormix[0] = plighting->color[0];
  return;
}


// R_StudioSetupModel  @ 000ded60
void R_StudioSetupModel(int bodypart)

{
  int iVar1;
  
                    /* Unresolved local var: int index@[???] */
  if (pstudiohdr->numbodyparts < bodypart) {
    Con_DPrintf("R_StudioSetupModel: no such bodypart %d\n",bodypart);
    iVar1 = 0;
  }
  else {
    iVar1 = bodypart * 0x4c;
  }
  pbodypart = (mstudiobodyparts_t *)(pstudiohdr->name + iVar1 + pstudiohdr->bodypartindex + -8);
  psubmodel = (mstudiomodel_t *)
              (pstudiohdr->name +
              (((currententity->curstate).body / pbodypart->base) % pbodypart->nummodels) * 0x70 +
              pbodypart->modelindex + -8);
  return;
}


// R_StudioSetupSkin  @ 000de920
void __regparm3 R_StudioSetupSkin(studiohdr_t *ptexturehdr,int index)

{
  char *s1;
  float fVar1;
  int iVar2;
  model_t *pModel;
  cl_entity_t *pcVar3;
  int iVar4;
  int iVar5;
  byte *data;
  vec_t texnum;
  skin_t *pskin;
  int in_GS_OFFSET;
  int local_12c;
  int local_128;
  int local_124;
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: mstudiotexture_t * ptexture@[???]
                       Unresolved local var: float temp@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  s1 = ptexturehdr->name + index * 0x50 + ptexturehdr->textureindex + -8;
  if (currententity->index < 1) {
LAB_000dec7a:
    texnum = *(vec_t *)(s1 + 0x4c);
  }
  else {
                    /* Unresolved local var: int l@[???]
                       Unresolved local var: int m@[???]
                       Unresolved local var: int h@[???] */
    local_12c = 0xa0;
    local_128 = 0xbf;
    local_124 = 0xdf;
    iVar4 = Q_stricmp(s1,"DM_Base.bmp");
    if ((iVar4 != 0) && (iVar4 = R_IsRemapSkin(s1,&local_12c,&local_128,&local_124), iVar4 == 0))
    goto LAB_000dec7a;
                    /* Unresolved local var: skin_t * pskin@[DW_OP_reg6(ESI)] */
    pcVar3 = currententity;
    iVar2 = r_remapindex;
                    /* Unresolved local var: skin_t * pskin@[???] */
    iVar4 = currententity->index;
    iVar5 = 0;
    if (index < 0xb) {
      iVar5 = index;
    }
    pskin = pDM_RemapSkin[iVar4][iVar5];
    if ((pskin == (skin_t *)0x0) || (iVar4 != pskin->keynum)) {
      pskin = DM_RemapSkin[r_remapindex] + iVar5;
      r_remapindex = (r_remapindex + 1) % 0x40;
      pDM_RemapSkin[iVar4][iVar5] = pskin;
      DM_RemapSkin[iVar2][iVar5].topcolor = -1;
      DM_RemapSkin[iVar2][iVar5].bottomcolor = -1;
      DM_RemapSkin[iVar2][iVar5].keynum = iVar4;
    }
    pModel = r_model;
    if (((pskin->model == r_model) && (pskin->topcolor == r_topcolor)) &&
       (pskin->bottomcolor == r_bottomcolor)) {
      texnum = (vec_t)pskin->gl_index;
    }
    else {
                    /* Unresolved local var: byte * orig_palette@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: byte * pData@[???] */
      if (pskin->model != (model_t *)0x0) {
        iVar4 = pcVar3->index;
                    /* Unresolved local var: int index@[???] */
        if (pDM_RemapSkin[iVar4][0] != (skin_t *)0x0) {
          pDM_RemapSkin[iVar4][0]->model = (model_t *)0x0;
        }
        if (pDM_RemapSkin[iVar4][1] != (skin_t *)0x0) {
          pDM_RemapSkin[iVar4][1]->model = (model_t *)0x0;
        }
        if (pDM_RemapSkin[iVar4][2] != (skin_t *)0x0) {
          pDM_RemapSkin[iVar4][2]->model = (model_t *)0x0;
        }
        if (pDM_RemapSkin[iVar4][3] != (skin_t *)0x0) {
          pDM_RemapSkin[iVar4][3]->model = (model_t *)0x0;
        }
        if (pDM_RemapSkin[iVar4][4] != (skin_t *)0x0) {
          pDM_RemapSkin[iVar4][4]->model = (model_t *)0x0;
        }
        if (pDM_RemapSkin[iVar4][5] != (skin_t *)0x0) {
          pDM_RemapSkin[iVar4][5]->model = (model_t *)0x0;
        }
        if (pDM_RemapSkin[iVar4][6] != (skin_t *)0x0) {
          pDM_RemapSkin[iVar4][6]->model = (model_t *)0x0;
        }
        if (pDM_RemapSkin[iVar4][7] != (skin_t *)0x0) {
          pDM_RemapSkin[iVar4][7]->model = (model_t *)0x0;
        }
        if (pDM_RemapSkin[iVar4][8] != (skin_t *)0x0) {
          pDM_RemapSkin[iVar4][8]->model = (model_t *)0x0;
        }
        if (pDM_RemapSkin[iVar4][9] != (skin_t *)0x0) {
          pDM_RemapSkin[iVar4][9]->model = (model_t *)0x0;
        }
        if (pDM_RemapSkin[iVar4][10] != (skin_t *)0x0) {
          pDM_RemapSkin[iVar4][10]->model = (model_t *)0x0;
        }
      }
      data = R_StudioReloadSkin(pModel,index,pskin);
      if (data == (byte *)0x0) goto LAB_000dec85;
      __snprintf_chk(local_120,0x100,1,0x100,0x25bb4f,s1,currententity->index);
      Q_memcpy(R_StudioSetupSkin::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::
               tmp_palette,data + (int)*(vec_t *)(s1 + 0x44) * (int)*(vec_t *)(s1 + 0x48),0x300);
      iVar4 = r_bottomcolor;
      pskin->model = r_model;
      iVar2 = r_topcolor;
      pskin->bottomcolor = iVar4;
      pskin->topcolor = iVar2;
      PaletteHueReplace(R_StudioSetupSkin::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::
                        tmp_palette,iVar2,local_12c,local_128);
      if (local_124 != 0) {
        PaletteHueReplace(R_StudioSetupSkin::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0
                          ::tmp_palette,pskin->bottomcolor,local_128 + 1,local_124);
      }
      GL_UnloadTexture(local_120);
      fVar1 = gl_dither.value;
      gl_dither.value = 0.0;
      texnum = (vec_t)GL_LoadTexture(local_120,GLT_STUDIO,pskin->width,pskin->height,data,0,0,
                                     R_StudioSetupSkin::lexical_block_0::lexical_block_0_0::
                                     lexical_block_0_0_0::tmp_palette);
      gl_dither.value = fVar1;
      pskin->gl_index = (int)texnum;
    }
    if (texnum == 0.0) goto LAB_000dec7a;
  }
  GL_Bind((int)texnum);
LAB_000dec85:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// R_StudioSetupSkin  @ 000ded30
void R_StudioSetupSkin(studiohdr_t *ptexturehdr,int index)

{
                    /* Unresolved local var: mstudiotexture_t * ptexture@[???]
                       Unresolved local var: float temp@[???] */
  if (((byte)g_ForcedFaceFlags & 2) == 0) {
    R_StudioSetupSkin(ptexturehdr,index);
    return;
  }
  return;
}


// R_StudioSlerpBones  @ 000d9b80
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


// R_StudioTransformAuxVert  @ 000dd9d0
void R_StudioTransformAuxVert(auxvert_t *av,int bone,vec_t *vert)

{
  av->fv[0] = vert[2] * bonetransform[bone][0][2] +
              vert[1] * bonetransform[bone][0][1] + *vert * bonetransform[bone][0][0] +
              bonetransform[bone][0][3];
  av->fv[1] = vert[2] * bonetransform[bone][1][2] +
              vert[1] * bonetransform[bone][1][1] + *vert * bonetransform[bone][1][0] +
              bonetransform[bone][1][3];
  av->fv[2] = vert[2] * bonetransform[bone][2][2] +
              vert[1] * bonetransform[bone][2][1] + *vert * bonetransform[bone][2][0] +
              bonetransform[bone][2][3];
  return;
}


// R_StudioTransformVector  @ 000dbc30
void R_StudioTransformVector(vec_t *in,vec_t *out)

{
  *out = in[2] * rotationmatrix[0][2] + in[1] * rotationmatrix[0][1] + *in * rotationmatrix[0][0] +
         rotationmatrix[0][3];
  out[1] = in[2] * rotationmatrix[1][2] + in[1] * rotationmatrix[1][1] + *in * rotationmatrix[1][0]
           + rotationmatrix[1][3];
  out[2] = in[2] * rotationmatrix[2][2] + in[1] * rotationmatrix[2][1] + *in * rotationmatrix[2][0]
           + rotationmatrix[2][3];
  return;
}


// R_TeleportSplash  @ 0019b1c0
void R_TeleportSplash(vec_t *org)

{
  particle_s **pppVar1;
  double dVar2;
  particle_t *ppVar3;
  particle_t *ppVar4;
  int32 iVar5;
  vec_t *out;
  int iVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  int local_40;
  int local_3c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: float vel@[???]
                       Unresolved local var: vec3_t dir@[???] */
  local_3c = -0x10;
  do {
    local_40 = -0x10;
    do {
      iVar6 = -0x18;
      do {
        ppVar4 = free_particles;
        ppVar3 = active_particles;
        if (free_particles == (particle_t *)0x0) {
          return;
        }
        active_particles = free_particles;
        out = free_particles->vel;
        pppVar1 = &free_particles->next;
        free_particles = free_particles->next;
        *pppVar1 = ppVar3;
        dVar2 = cl.time;
        fVar8 = RandomFloat(0.2,0.34);
        ppVar4->die = (float)dVar2 + fVar8;
        iVar5 = RandomLong(7,0xe);
        ppVar4->packedColor = 0;
        ppVar4->type = pt_slowgrav;
        local_28 = (float)(local_40 << 3);
        ppVar4->color = (short)iVar5;
        local_24 = (float)(local_3c << 3);
        local_20 = (float)(iVar6 * 8);
        fVar8 = *org;
        fVar9 = RandomFloat(0.0,3.0);
        ppVar4->org[0] = fVar9 + (float)local_3c + fVar8;
        fVar8 = org[1];
        fVar9 = RandomFloat(0.0,3.0);
        iVar7 = iVar6 + 4;
        ppVar4->org[1] = fVar9 + (float)local_40 + fVar8;
        fVar8 = org[2];
        fVar9 = RandomFloat(0.0,3.0);
        ppVar4->org[2] = fVar9 + (float)iVar6 + fVar8;
        VectorNormalize(&local_28);
        fVar8 = RandomFloat(50.0,113.0);
        VectorScale(&local_28,fVar8,out);
        iVar6 = iVar7;
      } while (iVar7 != 0x20);
      local_40 = local_40 + 4;
    } while (local_40 != 0x10);
    local_3c = local_3c + 4;
  } while (local_3c != 0x10);
  return;
}


// R_TempModel  @ 0014d610
TEMPENTITY *
R_TempModel(float *pos,float *dir,float *angles,float life,int modelIndex,int soundtype)

{
  vec_t vVar1;
  model_t *model;
  int iVar2;
  TEMPENTITY *pTVar3;
  int32 iVar4;
  float fVar5;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: model_t * model@[???]
                       Unresolved local var: int frameCount@[???] */
  if (modelIndex != 0) {
    model = CL_GetModelByIndex(modelIndex);
    if (model == (model_t *)0x0) {
      Con_Printf("No model %d!\n",modelIndex);
    }
    else {
      iVar2 = ModelFrameCount(model);
      pTVar3 = (*efx.CL_TempEntAlloc)(pos,model);
      if (pTVar3 != (TEMPENTITY *)0x0) {
        (pTVar3->entity).angles[0] = *angles;
        (pTVar3->entity).angles[1] = angles[1];
        vVar1 = angles[2];
        pTVar3->flags = pTVar3->flags | 0x22;
        (pTVar3->entity).angles[2] = vVar1;
        pTVar3->frameMax = (float)iVar2;
        if (soundtype == 1) {
          pTVar3->hitSound = 0x20;
          fVar5 = RandomFloat(-512.0,511.0);
          (pTVar3->entity).baseline.angles[0] = fVar5;
          fVar5 = RandomFloat(-256.0,255.0);
          (pTVar3->entity).baseline.angles[1] = fVar5;
          fVar5 = RandomFloat(-256.0,255.0);
          pTVar3->flags = pTVar3->flags | 4;
          (pTVar3->entity).baseline.angles[2] = fVar5;
        }
        else if (soundtype == 2) {
          pTVar3->hitSound = 0x80;
          fVar5 = RandomFloat(-512.0,511.0);
          (pTVar3->entity).baseline.angles[0] = fVar5;
          fVar5 = RandomFloat(-256.0,255.0);
          (pTVar3->entity).baseline.angles[1] = fVar5;
          fVar5 = RandomFloat(-256.0,255.0);
          pTVar3->flags = pTVar3->flags | 0xc;
          (pTVar3->entity).baseline.angles[2] = fVar5;
        }
        else if (soundtype == 0) {
          pTVar3->hitSound = 0;
        }
        (pTVar3->entity).baseline.origin[0] = *dir;
        (pTVar3->entity).baseline.origin[1] = dir[1];
        (pTVar3->entity).baseline.origin[2] = dir[2];
        pTVar3->die = life + (float)cl.time;
        if (model->type != mod_sprite) {
          iVar4 = RandomLong(0,iVar2 + -1);
          (pTVar3->entity).curstate.body = iVar4;
          return pTVar3;
        }
        iVar4 = RandomLong(0,iVar2 + -1);
        (pTVar3->entity).curstate.frame = (float)iVar4;
        return pTVar3;
      }
    }
  }
  return (TEMPENTITY *)0x0;
}


// R_TempSphereModel  @ 0014d0b0
void R_TempSphereModel(float *pos,float speed,float life,int count,int modelIndex)

{
  vec_t *v;
  model_t *model;
  int iVar1;
  TEMPENTITY *pTVar2;
  int32 iVar3;
  uint uVar4;
  uint uVar5;
  float fVar6;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int frameCount@[???]
                       Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: model_t * model@[???] */
  if (((modelIndex != 0) && (model = CL_GetModelByIndex(modelIndex), model != (model_t *)0x0)) &&
     (iVar1 = ModelFrameCount(model), 0 < count)) {
    uVar5 = 0;
    do {
      pTVar2 = (*efx.CL_TempEntAlloc)(pos,model);
      if (pTVar2 == (TEMPENTITY *)0x0) {
        return;
      }
      iVar3 = RandomLong(0,iVar1 + -1);
      (pTVar2->entity).curstate.body = iVar3;
      iVar3 = RandomLong(0,0xff);
      if (iVar3 < 10) {
        uVar4 = pTVar2->flags | 8;
      }
      else {
        uVar4 = pTVar2->flags | 2;
      }
      pTVar2->flags = uVar4;
      iVar3 = RandomLong(0,0xff);
      if (iVar3 < 0xdc) {
        pTVar2->flags = pTVar2->flags | 4;
        fVar6 = RandomFloat(-256.0,-255.0);
        (pTVar2->entity).baseline.angles[0] = fVar6;
        fVar6 = RandomFloat(-256.0,-255.0);
        (pTVar2->entity).baseline.angles[1] = fVar6;
        fVar6 = RandomFloat(-256.0,-255.0);
        (pTVar2->entity).baseline.angles[2] = fVar6;
      }
      iVar3 = RandomLong(0,0xff);
      uVar4 = pTVar2->flags;
      if (iVar3 < 100) {
        uVar4 = uVar4 | 0x10;
      }
      pTVar2->flags = uVar4 | 0x60;
      uVar4 = uVar5 + 1;
      (pTVar2->entity).curstate.effects = uVar5 & 0x1f;
      (pTVar2->entity).curstate.rendermode = 0;
      v = (pTVar2->entity).baseline.origin;
      fVar6 = RandomFloat(-1.0,1.0);
      (pTVar2->entity).baseline.origin[0] = fVar6;
      fVar6 = RandomFloat(-1.0,1.0);
      (pTVar2->entity).baseline.origin[1] = fVar6;
      fVar6 = RandomFloat(-1.0,1.0);
      (pTVar2->entity).baseline.origin[2] = fVar6;
      VectorNormalize(v);
      VectorScale(v,speed,v);
      pTVar2->die = life + (float)cl.time;
      uVar5 = uVar4;
    } while (count != uVar4);
  }
  return;
}


// R_TempSprite  @ 0014d8e0
TEMPENTITY *
R_TempSprite(float *pos,float *dir,float scale,int modelIndex,int rendermode,int renderfx,float a,
            float life,int flags)

{
  float fVar1;
  model_t *model;
  int iVar2;
  TEMPENTITY *pTVar3;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: model_t * model@[???]
                       Unresolved local var: int frameCount@[???] */
  if (modelIndex != 0) {
    model = CL_GetModelByIndex(modelIndex);
    if (model == (model_t *)0x0) {
      Con_Printf("No model %d!\n",modelIndex);
    }
    else {
      iVar2 = ModelFrameCount(model);
      pTVar3 = (*efx.CL_TempEntAlloc)(pos,model);
      if (pTVar3 != (TEMPENTITY *)0x0) {
        (pTVar3->entity).curstate.framerate = 10.0;
        (pTVar3->entity).curstate.rendercolor.r = 0xff;
        (pTVar3->entity).curstate.rendermode = rendermode;
        (pTVar3->entity).curstate.scale = scale;
        pTVar3->frameMax = (float)iVar2;
        (pTVar3->entity).curstate.renderfx = renderfx;
        (pTVar3->entity).curstate.rendercolor.g = 0xff;
        (pTVar3->entity).curstate.rendercolor.b = 0xff;
        (pTVar3->entity).curstate.renderamt = (int)(a * 255.0);
        (pTVar3->entity).baseline.renderamt = (int)(a * 255.0);
        pTVar3->flags = pTVar3->flags | flags;
        (pTVar3->entity).baseline.origin[0] = *dir;
        (pTVar3->entity).baseline.origin[1] = dir[1];
        (pTVar3->entity).baseline.origin[2] = dir[2];
        (pTVar3->entity).origin[0] = *pos;
        (pTVar3->entity).origin[1] = pos[1];
        (pTVar3->entity).origin[2] = pos[2];
        if (life == 0.0) {
          fVar1 = (float)iVar2 * 0.1 + (float)cl.time + 1.0;
        }
        else {
          fVar1 = life + (float)cl.time;
        }
        pTVar3->die = fVar1;
        (pTVar3->entity).curstate.frame = 0.0;
        return pTVar3;
      }
    }
  }
  return (TEMPENTITY *)0x0;
}


// R_TextureAnimation  @ 001907d0
texture_t * R_TextureAnimation(msurface_t *s)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  texture_s *ptVar4;
  int (*paiVar5) [20];
  float *pfVar6;
  int iVar7;
  
                    /* Unresolved local var: texture_t * base@[???]
                       Unresolved local var: int reletive@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int tu@[???]
                       Unresolved local var: int tv@[???]
                       Unresolved local var: texture_t * tm2@[DW_OP_reg3(EBX)] */
  ptVar4 = s->texinfo->texture;
  if (R_TextureAnimation::rtable[0][0] == 0) {
    paiVar5 = R_TextureAnimation::rtable;
    do {
      pfVar1 = (float *)((int)paiVar5 + 0x50);
      pfVar6 = (float *)paiVar5;
      do {
        paiVar5 = (int (*) [20])(pfVar6 + 1);
        fVar2 = (float)RandomLong(0,0x7fff);
        *pfVar6 = fVar2;
        pfVar6 = (float *)paiVar5;
      } while (paiVar5 != (int (*) [20])pfVar1);
    } while (paiVar5 != (int (*) [20])outvert);
  }
  if (((currententity->curstate).frame != 0.0) && (ptVar4->alternate_anims != (texture_s *)0x0)) {
    ptVar4 = ptVar4->alternate_anims;
  }
  iVar3 = ptVar4->anim_total;
  if (iVar3 != 0) {
    if (ptVar4->name[0] == '-') {
      iVar7 = 0;
      iVar3 = R_TextureAnimation::rtable
              [(int)((ptVar4->width * 0x10000 + (int)s->texturemins[0]) / ptVar4->width) % 0x14]
              [(int)((ptVar4->height * 0x10000 + (int)s->texturemins[1]) / ptVar4->height) % 0x14] %
              iVar3;
      while ((iVar3 < ptVar4->anim_min || (ptVar4->anim_max <= iVar3))) {
        ptVar4 = ptVar4->anim_next;
        if (ptVar4 == (texture_s *)0x0) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("R_TextureAnimation: broken cycle");
        }
        iVar7 = iVar7 + 1;
        if (100 < iVar7) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("R_TextureAnimation: infinite cycle");
        }
      }
    }
    else {
      iVar3 = (int)((float)cl.time * 10.0) % iVar3;
      iVar7 = 0;
      while ((iVar3 < ptVar4->anim_min || (ptVar4->anim_max <= iVar3))) {
        ptVar4 = ptVar4->anim_next;
        if (ptVar4 == (texture_s *)0x0) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("R_TextureAnimation: broken cycle");
        }
        iVar7 = iVar7 + 1;
        if (100 < iVar7) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("R_TextureAnimation: infinite cycle");
        }
      }
    }
  }
  return ptVar4;
}


// R_TimeRefresh_f  @ 001ba2e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_TimeRefresh_f(void)

{
  int iVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float start@[???]
                       Unresolved local var: float stop@[???]
                       Unresolved local var: float time@[???] */
  if (cl.worldmodel == (model_s *)0x0) {
    Con_Printf("No map loaded\n");
  }
  else {
    if (sv_cheats.value != 0.0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float start@[???]
                       Unresolved local var: float stop@[???]
                       Unresolved local var: float time@[???] */
      (*qglDrawBuffer)(0x404);
      (*qglFinish)();
      dVar3 = Sys_FloatTime();
      iVar1 = 0;
      do {
        iVar2 = iVar1 + 1;
        r_refdef.viewangles[1] = (float)iVar1 * 0.0078125 * 360.0;
        R_RenderView();
        iVar1 = iVar2;
      } while (iVar2 != 0x80);
      (*qglFinish)();
      dVar4 = Sys_FloatTime();
      Con_Printf("%f seconds (%f fps)\n",(double)((float)dVar4 - (float)dVar3),
                 (double)(128.0 / ((float)dVar4 - (float)dVar3)));
      (*qglDrawBuffer)(0x405);
      GL_EndRendering();
      return;
    }
    Con_Printf("sv_cheats not enabled\n");
  }
  return;
}


// R_TracerEffect  @ 0014c4e0
void R_TracerEffect(vec_t *start,vec_t *end)

{
  float fVar1;
  int32 iVar2;
  float fVar3;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: vec3_t temp@[???]
                       Unresolved local var: vec3_t vel@[???]
                       Unresolved local var: float len@[???] */
  if (tracerSpeed.value <= 0.0) {
    tracerSpeed.value = 3.0;
  }
  local_24 = *end - *start;
  local_20 = end[1] - start[1];
  local_1c = end[2] - start[2];
  fVar3 = Length(&local_24);
  VectorScale(&local_24,1.0 / fVar3,&local_24);
  fVar1 = tracerOffset.value;
  iVar2 = RandomLong(-10,9);
  VectorScale(&local_24,(float)iVar2 + fVar1,&local_18);
  *start = *start + local_18;
  start[1] = start[1] + local_14;
  start[2] = start[2] + local_10;
  VectorScale(&local_24,tracerSpeed.value,&local_18);
  (*efx.R_TracerParticles)(start,&local_18,fVar3 / tracerSpeed.value);
  return;
}


// R_TracerParticles  @ 0019a570
particle_t * R_TracerParticles(vec_t *org,vec_t *vel,float life)

{
  particle_s **pppVar1;
  float fVar2;
  particle_t *ppVar3;
  particle_t *ppVar4;
  
  ppVar4 = free_particles;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: particle_t * p@[???] */
  ppVar3 = gpActiveTracers;
  if (free_particles != (particle_t *)0x0) {
    gpActiveTracers = free_particles;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar3;
    ppVar4->die = life + (float)cl.time;
    ppVar4->color = 4;
    ppVar4->packedColor = 0xff;
    fVar2 = tracerLength.value;
    ppVar4->type = pt_static;
    ppVar4->ramp = fVar2;
    ppVar4->org[0] = *org;
    ppVar4->vel[0] = *vel;
    ppVar4->org[1] = org[1];
                    /* catch() { ... } // from try @ 0019a4c6 with catch @ 0019a5e4
                       catch() { ... } // from try @ 0019a56e with catch @ 0019a5e4 */
    ppVar4->vel[1] = vel[1];
    ppVar4->org[2] = org[2];
                    /* try { // try from 0019a600 to 001aa604 has its CatchHandler @ 0019a2d0 */
    ppVar4->vel[2] = vel[2];
  }
  return ppVar4;
}


// R_TranslatePlayerSkin  @ 001babf0
void R_TranslatePlayerSkin(int playernum)

{
  return;
}


// R_TriangleSpriteTexture  @ 001c0430
int R_TriangleSpriteTexture(model_t *pSpriteModel,int frame)

{
  mspriteframe_t *pmVar1;
  
                    /* Unresolved local var: mspriteframe_t * pSpriteFrame@[???] */
  VGUI2_ResetCurrentTexture();
  pmVar1 = R_GetSpriteFrame((pSpriteModel->cache).data,frame);
  if (pmVar1 != (mspriteframe_t *)0x0) {
    GL_Bind(pmVar1->gl_texturenum);
    return 1;
  }
  return 0;
}


// R_UpdateLatchedVars  @ 000e2f40
void R_UpdateLatchedVars(cl_entity_t *ent)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  vec_t vVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  byte bVar10;
  byte bVar11;
  
                    /* Unresolved local var: int i@[???] */
  iVar7 = (ent->prevstate).sequence;
  vVar1 = (ent->prevstate).origin[1];
  vVar2 = (ent->prevstate).origin[2];
  vVar3 = (ent->prevstate).angles[0];
  vVar4 = (ent->prevstate).angles[1];
  vVar5 = (ent->prevstate).angles[2];
  fVar6 = (ent->prevstate).animtime;
  iVar8 = (ent->curstate).sequence;
  (ent->latched).prevorigin[0] = (ent->prevstate).origin[0];
  (ent->latched).prevorigin[1] = vVar1;
  (ent->latched).prevorigin[2] = vVar2;
  (ent->latched).prevangles[0] = vVar3;
  (ent->latched).prevangles[1] = vVar4;
  (ent->latched).prevangles[2] = vVar5;
  (ent->latched).prevanimtime = fVar6;
  if (iVar8 == iVar7) {
    bVar10 = (ent->prevstate).blending[0];
    bVar11 = (ent->prevstate).blending[1];
  }
  else {
    fVar6 = (ent->curstate).animtime;
    (ent->latched).prevsequence = iVar7;
    bVar10 = (ent->prevstate).blending[0];
    bVar11 = (ent->prevstate).blending[1];
    (ent->latched).sequencetime = fVar6;
    (ent->latched).prevseqblending[0] = bVar10;
    (ent->latched).prevseqblending[1] = bVar11;
  }
  uVar9 = *(undefined4 *)(ent->prevstate).controller;
  (ent->latched).prevblending[0] = bVar10;
  (ent->latched).prevblending[1] = bVar11;
  *(undefined4 *)(ent->latched).prevcontroller = uVar9;
  return;
}


// R_UploadEmptyTex  @ 001ba560
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_UploadEmptyTex(void)

{
  texture_t *ptVar1;
  int iVar2;
  int in_GS_OFFSET;
  byte local_310 [765];
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: byte[768] pPal@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(local_310,0,0x300);
  ptVar1 = r_notexture_mip;
  local_12 = 0;
  local_11 = 0xff;
  local_13 = 0xff;
  iVar2 = GL_LoadTexture("**empty**",GLT_SYSTEM,r_notexture_mip->width,r_notexture_mip->height,
                         (byte *)(r_notexture_mip + 1),1,0,local_310);
  ptVar1->gl_texturenum = iVar2;
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// R_UseLegacyRender  @ 001c2d40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean R_UseLegacyRender(void)

{
  uint uVar1;
  
  if (game->_vptr_IGame[0x10] == IGame::OnlyLegacyRender) {
    return 1;
  }
  uVar1 = (*game->_vptr_IGame[0x10])(game);
  return uVar1 & 0xff;
}


// R_UseProgram  @ 0018fa00
void R_UseProgram(GLuint prog)

{
  if (g_bHasShaderFunctions != false) {
    if (gl_use_shaders.value == 0.0) {
      prog = 0;
    }
    else if (sv_allow_shaders.value == 0.0) {
      prog = 0;
    }
    if (prog != g_uCurrentProgram) {
      (*qglUseProgram)(prog);
      g_uCurrentProgram = prog;
    }
  }
  return;
}


// R_UserTracerParticle  @ 0019a610
void R_UserTracerParticle
               (vec_t *org,vec_t *vel,float life,int colorIndex,float length,uchar context,
               _func_void_particle_s_ptr *deathfunc)

{
  particle_s **pppVar1;
  vec_t vVar2;
  particle_t *ppVar3;
  particle_t *ppVar4;
  
  ppVar4 = free_particles;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: particle_t * p@[???] */
  ppVar3 = gpActiveTracers;
  if (colorIndex < 0) {
    Con_Printf("UserTracer with color < 0\n");
    return;
  }
  if (0xc < colorIndex) {
    Con_Printf("UserTracer with color > %d\n");
    return;
  }
  if (free_particles != (particle_t *)0x0) {
    gpActiveTracers = free_particles;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar3;
    ppVar4->die = life + (float)cl.time;
    ppVar4->ramp = length;
    ppVar4->color = (short)colorIndex;
    ppVar4->packedColor = 0xff;
    ppVar4->type = pt_static;
    ppVar4->org[0] = *org;
    ppVar4->vel[0] = *vel;
    ppVar4->org[1] = org[1];
    ppVar4->vel[1] = vel[1];
    ppVar4->org[2] = org[2];
    vVar2 = vel[2];
    ppVar4->deathfunc = deathfunc;
    ppVar4->context = context;
    ppVar4->vel[2] = vVar2;
  }
  return;
}


// R_UsingShaders  @ 0018f9c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean R_UsingShaders(void)

{
  qboolean qVar1;
  
  qVar1 = false;
  if (((g_bHasShaderFunctions != false) && (qVar1 = false, gl_use_shaders.value != 0.0)) &&
     (qVar1 = (qboolean)NAN(sv_allow_shaders.value), sv_allow_shaders.value != 0.0)) {
    qVar1 = true;
  }
  return qVar1;
}


