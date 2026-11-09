// R_AddDynamicLights  @ 001e29c0
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
  float *pfVar20;
  uint uVar21;
  colorVec *pcVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  uint uVar26;
  int iVar27;
  int local_34;
  int local_30;
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
  local_28 = 0;
  iVar19 = ((int)surf->extents[0] >> 4) + 1;
  pmVar12 = surf->texinfo;
  iVar23 = (int)surf->extents[1] >> 4;
  pfVar20 = &cl_dlights[0].minlight;
  do {
    if ((surf->dlightbits >> ((byte)local_28 & 0x1f) & 1U) != 0) {
      fVar14 = ((dlight_t *)(pfVar20 + -7))->origin[0] - pcVar18->origin[0];
      fVar17 = pfVar20[-6] - pcVar18->origin[1];
      fVar16 = pfVar20[-5] - pcVar18->origin[2];
      pmVar13 = surf->plane;
      fVar15 = pfVar20[-4] -
               ABS((pmVar13->normal[2] * fVar16 +
                   pmVar13->normal[1] * fVar17 + pmVar13->normal[0] * fVar14) - pmVar13->dist);
      fVar3 = *pfVar20;
      if (fVar3 <= fVar15) {
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
        if (-1 < iVar23) {
                    /* Unresolved local var: int32 delta@[???] */
          local_30 = 0;
          local_34 = 0;
          do {
            uVar26 = (uint)(((fVar16 * fVar10 + fVar17 * fVar9 + fVar14 * fVar8 + fVar11) -
                            (float)sVar2) - (float)local_34);
            uVar21 = (int)uVar26 >> 0x1f;
            iVar27 = (uVar26 ^ uVar21) - uVar21;
            if (0 < iVar19) {
              iVar25 = 0;
              pcVar22 = blocklights + local_30;
              do {
                uVar21 = (uint)(((fVar6 * fVar16 + fVar5 * fVar17 + fVar14 * fVar4 + fVar7) -
                                (float)sVar1) - (float)iVar25);
                uVar26 = (int)uVar21 >> 0x1f;
                iVar24 = (uVar21 ^ uVar26) - uVar26;
                if (iVar27 < iVar24) {
                  iVar24 = iVar24 + (iVar27 >> 1);
                }
                else {
                  iVar24 = (iVar24 >> 1) + iVar27;
                }
                if ((float)iVar24 < fVar15 - fVar3) {
                  iVar24 = (int)((fVar15 - (float)iVar24) * 256.0);
                  pcVar22->r = pcVar22->r +
                               ((int)((uint)((color24 *)(pfVar20 + -3))->r * iVar24) >> 8);
                  pcVar22->g = pcVar22->g +
                               ((int)((uint)*(byte *)((int)pfVar20 + -0xb) * iVar24) >> 8);
                  pcVar22->b = pcVar22->b +
                               ((int)((uint)*(byte *)((int)pfVar20 + -10) * iVar24) >> 8);
                }
                iVar25 = iVar25 + 0x10;
                pcVar22 = pcVar22 + 1;
              } while (iVar25 != iVar19 * 0x10);
            }
            local_34 = local_34 + 0x10;
            local_30 = local_30 + iVar19;
          } while (local_34 != (iVar23 + 1) * 0x10);
        }
      }
    }
    local_28 = local_28 + 1;
    pfVar20 = pfVar20 + 10;
  } while (local_28 != 0x20);
  return;
}


// R_AddEfrags  @ 001f2e60
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
    r_emaxs[0] = ent->origin[0] + pmVar1->maxs[0];
    r_emins[1] = pmVar1->mins[1] + ent->origin[1];
    r_emaxs[1] = ent->origin[1] + pmVar1->maxs[1];
    r_emins[2] = pmVar1->mins[2] + ent->origin[2];
    r_emaxs[2] = ent->origin[2] + pmVar1->maxs[2];
    R_SplitEntityOnNode((cl.worldmodel)->nodes);
    ent->topnode = r_pefragtopnode;
  }
  return;
}


// R_AddToStudioCache  @ 0013c010
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


// R_AllocObjects  @ 002104f0
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


// R_AllocParticle  @ 001f1910
particle_s * R_AllocParticle(_func_void_particle_s_ptr_float *callback)

{
  particle_s **pppVar1;
  vec_t vVar2;
  particle_t *ppVar3;
  particle_t *ppVar4;
  
                    /* Unresolved local var: particle_t * p@[???] */
  ppVar4 = free_particles;
  if (free_particles == (particle_t *)0x0) {
    Con_Printf("Not enough free particles\n");
  }
  else {
    free_particles->type = pt_clientcustom;
    ppVar3 = active_particles;
    active_particles = free_particles;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar3;
    ppVar4->die = (float)cl.time;
    ppVar4->color = 0;
    ppVar4->callback = callback;
    vVar2 = vec3_origin[0];
    ppVar4->deathfunc = (_func_void_particle_s_ptr *)0x0;
    ppVar4->ramp = 0.0;
    ppVar4->org[0] = vVar2;
    ppVar4->org[1] = vec3_origin[1];
    ppVar4->org[2] = vec3_origin[2];
    ppVar4->vel[0] = vec3_origin[0];
    ppVar4->vel[1] = vec3_origin[1];
    vVar2 = vec3_origin[2];
    ppVar4->packedColor = 0;
    ppVar4->vel[2] = vVar2;
  }
  return ppVar4;
}


// R_AnimateLight  @ 001e9110
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_AnimateLight(void)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  lightstyle_t *plVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???] */
  iVar3 = 0;
  plVar4 = cl_lightstyle;
  fVar1 = (float)cl.time;
  do {
    while (piVar2 = &plVar4->length, *piVar2 != 0) {
      plVar4 = plVar4 + 1;
      d_lightstylevalue[iVar3] =
           (*(char *)((int)(fVar1 * 10.0) % *piVar2 + 0xc53644 + iVar3 * 0x44) + -0x61) * 0x16;
      iVar3 = iVar3 + 1;
      if (iVar3 == 0x40) {
        return;
      }
    }
    plVar4 = plVar4 + 1;
    d_lightstylevalue[iVar3] = 0x100;
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x40);
  return;
}


// R_AttachTentToPlayer  @ 001a63d0
void R_AttachTentToPlayer(int client,int modelIndex,float zoffset,float life)

{
  model_t *pModel;
  
                    /* Unresolved local var: model_t * pModel@[???] */
  pModel = CL_GetModelByIndex(modelIndex);
  if (pModel != (model_t *)0x0) {
    R_AttachTentToPlayer2(client,pModel,zoffset,life);
    return;
  }
  Con_Printf("No model %d!\n");
  return;
}


// R_AttachTentToPlayer2  @ 001a6250
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
  if ((-1 < client) && (client <= cl.maxclients)) {
    if (cl_entities[client].curstate.messagenum == cl.parsecount) {
      local_18 = cl_entities[client].origin[0];
      local_10 = zoffset + cl_entities[client].origin[2];
      local_14 = cl_entities[client].origin[1];
      pTVar2 = (*efx.CL_TempEntAllocHigh)(&local_18,pModel);
      if (pTVar2 != (TEMPENTITY *)0x0) {
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
        return;
      }
      Con_Printf("No temp ent.\n");
    }
    return;
  }
  Con_Printf("Bad client in R_AttachTentToPlayer()!\n");
  return;
}


// R_BeamAlloc  @ 001ecce0
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


// R_BeamCirclePoints  @ 001ed2f0
BEAM * R_BeamCirclePoints(int type,vec_t *start,vec_t *end,int modelIndex,float life,float width,
                         float amplitude,float brightness,float speed,int startFrame,float framerate
                         ,float r,float g,float b)

{
  BEAM **ppBVar1;
  BEAM *pBVar2;
  BEAM *pbeam;
  
  pBVar2 = gpActiveBeams;
                    /* Unresolved local var: BEAM * pbeam@[DW_OP_reg3(EBX)] */
  pbeam = gpFreeBeams;
                    /* Unresolved local var: BEAM * pbeam@[???] */
  if (gpFreeBeams != (BEAM *)0x0) {
    gpActiveBeams = gpFreeBeams;
    ppBVar1 = &gpFreeBeams->next;
    gpFreeBeams = gpFreeBeams->next;
    *ppBVar1 = pBVar2;
    pbeam->die = (float)cl.time;
    if (modelIndex < 0) {
      pbeam = (BEAM *)0x0;
    }
    else {
      R_BeamSetup(pbeam,start,end,modelIndex,life,width,amplitude,brightness,speed);
      pbeam->type = type;
      if (life == 0.0) {
        pbeam->flags = pbeam->flags | 0x80000000;
      }
      pbeam->frameRate = framerate;
      pbeam->r = r;
      pbeam->frame = (float)startFrame;
      pbeam->g = g;
      pbeam->b = b;
    }
  }
  return pbeam;
}


// R_BeamClear  @ 001e9d90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_BeamClear(void)

{
  BEAM *pBVar1;
  BEAM *pBVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  gpActiveBeams = (BEAM *)0x0;
  gpFreeBeams = gBeams;
  Q_memset(gBeams,0,0x3e00);
  pBVar2 = gBeams;
  iVar3 = 0;
  pBVar1 = gBeams;
  do {
    iVar3 = iVar3 + 1;
    pBVar1->next = pBVar1 + 1;
    pBVar1 = pBVar1 + 1;
  } while (iVar3 != 0x80);
  pBVar2[0x7f].next = (BEAM *)0x0;
  return;
}


// R_BeamCull  @ 001efc50
int R_BeamCull(vec_t *start,vec_t *end,int pvsOnly)

{
  float fVar1;
  mnode_t *pmVar2;
  qboolean qVar3;
  uint uVar4;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: int i@[???] */
  uVar4 = 0;
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
    local_10 = start[2];
    fVar1 = end[2];
    local_1c = fVar1;
    if (local_10 < fVar1) {
      local_1c = local_10;
      local_10 = fVar1;
    }
    if (local_1c == local_10) {
      local_10 = local_10 + 1.0;
    }
    pmVar2 = PVSNode((cl.worldmodel)->nodes,&local_24,&local_18);
    uVar4 = 0;
    if ((pmVar2 != (mnode_t *)0x0) && (uVar4 = 1, pvsOnly == 0)) {
      qVar3 = R_CullBox(&local_24,&local_18);
      uVar4 = (uint)(qVar3 == false);
    }
  }
  return uVar4;
}


// R_BeamDraw  @ 001eff20
void __regparm1 R_BeamDraw(BEAM *pbeam,float frametime)

{
  particle_s **pppVar1;
  model_s *pmVar2;
  vec_t vVar3;
  particle_t *ppVar4;
  particle_t *ppVar5;
  model_t *pmVar6;
  int iVar7;
  cl_entity_t *pcVar8;
  uint uVar9;
  vec_t *pvVar10;
  float *pfVar11;
  float fVar12;
  float fVar13;
  double dVar14;
  float local_4c;
  float local_48;
  float local_44;
  float local_3c;
  float local_38;
  float local_34;
  float local_2c;
  float local_28;
  float local_24;
  
                    /* Unresolved local var: model_t * sprite@[???]
                       Unresolved local var: vec3_t difference@[???] */
  pmVar6 = CL_GetModelByIndex(pbeam->modelIndex);
  if (pmVar6 == (model_t *)0x0) {
    return;
  }
  if ((pbeam->flags & 0x20) == 0) {
    (*tri.RenderMode)(5);
  }
  else {
    (*tri.RenderMode)(0);
  }
  pbeam->freq = frametime + pbeam->freq;
  gNoise[0] = 0.0;
  gNoise[0x80] = 0.0;
  if (pbeam->amplitude != 0.0) {
    if ((pbeam->flags & 0x10) == 0) {
      Noise(gNoise,0x80);
    }
    else {
      fVar13 = 0.0;
      pfVar11 = gNoise;
      fVar12 = fVar13;
      while( true ) {
        *pfVar11 = fVar12;
        pfVar11 = pfVar11 + 1;
        if (pfVar11 == gNoise + 0x80) break;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float freq@[???]
                       Unresolved local var: float step@[???]
                       Unresolved local var: float freq2@[???] */
        fVar13 = fVar13 + 0.024543693;
        fVar12 = sinf(fVar13);
      }
    }
  }
  uVar9 = pbeam->flags;
  if ((uVar9 & 3) != 0) {
    if ((uVar9 & 1) != 0) {
                    /* Unresolved local var: cl_entity_t * start@[DW_OP_reg0(EAX)] */
      uVar9 = pbeam->startEntity;
      if ((int)uVar9 < 0) {
                    /* Unresolved local var: int client_index@[???] */
        pcVar8 = ClientDLL_GetUserEntity(-uVar9 & 0xfff);
      }
      else {
        pcVar8 = cl_entities + (uVar9 & 0xfff);
      }
      if (pcVar8 == (cl_entity_t *)0x0) {
        return;
      }
      if ((pcVar8->model == (model_s *)0x0) ||
         ((pmVar2 = pbeam->pFollowModel, pmVar2 != (model_s *)0x0 && (pcVar8->model != pmVar2)))) {
        uVar9 = pbeam->flags;
        if (-1 < (int)uVar9) {
          uVar9 = uVar9 & 0xfffffffe;
          pbeam->flags = uVar9;
        }
      }
      else {
                    /* Unresolved local var: float * attachmentPoint@[DW_OP_reg2(EDX)] */
        iVar7 = pbeam->startEntity;
                    /* Unresolved local var: int attach@[???] */
        if (iVar7 < 0) {
          iVar7 = -iVar7;
        }
        uVar9 = iVar7 >> 0xc & 0xf;
        if (uVar9 == 0) {
                    /* Unresolved local var: int attach@[???] */
          pvVar10 = cl.simorg;
          if (pcVar8->index != cl.playernum + 1) {
            pvVar10 = pcVar8->origin;
          }
        }
        else {
          pvVar10 = pcVar8->angles + uVar9 * 3;
        }
        pbeam->source[0] = *pvVar10;
        pbeam->source[1] = pvVar10[1];
        pbeam->source[2] = pvVar10[2];
        uVar9 = pbeam->flags | 0x10000000;
        pbeam->flags = uVar9;
        if (pmVar2 == (model_s *)0x0) {
          pbeam->pFollowModel = pcVar8->model;
        }
      }
    }
    if ((uVar9 & 2) != 0) {
      uVar9 = pbeam->endEntity;
      if ((int)uVar9 < 0) {
                    /* Unresolved local var: int client_index@[???] */
        pcVar8 = ClientDLL_GetUserEntity(-uVar9 & 0xfff);
      }
      else {
        pcVar8 = cl_entities + (uVar9 & 0xfff);
      }
      if (pcVar8 == (cl_entity_t *)0x0) {
        return;
      }
      if (pcVar8->model == (model_s *)0x0) {
                    /* Unresolved local var: cl_entity_t * end@[DW_OP_reg0(EAX)] */
        if (pbeam->flags < 0) {
          return;
        }
        pbeam->flags = pbeam->flags & 0xfffffffd;
        pbeam->die = (float)cl.time;
        return;
      }
                    /* Unresolved local var: float * attachmentPoint@[DW_OP_reg2(EDX)] */
      iVar7 = pbeam->endEntity;
                    /* Unresolved local var: int attach@[???] */
      if (iVar7 < 0) {
        iVar7 = -iVar7;
      }
      uVar9 = iVar7 >> 0xc & 0xf;
      if (uVar9 == 0) {
                    /* Unresolved local var: int attach@[???] */
        pvVar10 = cl.simorg;
        if (pcVar8->index != cl.playernum + 1) {
          pvVar10 = pcVar8->origin;
        }
      }
      else {
        pvVar10 = pcVar8->angles + uVar9 * 3;
      }
      pbeam->target[0] = *pvVar10;
      pbeam->target[1] = pvVar10[1];
      vVar3 = pvVar10[2];
      pbeam->flags = pbeam->flags | 0x20000000;
      pbeam->target[2] = vVar3;
    }
    if ((pbeam->flags & 0x10000001U) == 1) {
      return;
    }
    local_4c = pbeam->target[0] - pbeam->source[0];
    local_48 = pbeam->target[1] - pbeam->source[1];
    local_44 = pbeam->target[2] - pbeam->source[2];
    fVar13 = Length(&local_4c);
    if (1e-07 < fVar13) {
      pbeam->delta[0] = local_4c;
      pbeam->delta[1] = local_48;
      pbeam->delta[2] = local_44;
    }
    if (pbeam->amplitude < 0.5) {
      fVar13 = Length(pbeam->delta);
      pbeam->segments = (int)(fVar13 * 0.075 + 3.0);
    }
    else {
      fVar13 = Length(pbeam->delta);
      pbeam->segments = (int)(fVar13 * 0.25 + 3.0);
    }
  }
  if (((pbeam->type != 0) || (iVar7 = R_BeamCull(pbeam->source,pbeam->target,0), iVar7 != 0)) &&
     (iVar7 = (*tri.SpriteTexture)
                        (pmVar6,(int)(pbeam->frameRate * (float)cl.time + pbeam->frame) %
                                pbeam->frameCount), fVar13 = egon_amplitude.value, iVar7 != 0)) {
    uVar9 = pbeam->flags;
    if (((uVar9 & 0x10) != 0) && (0.0 < egon_amplitude.value)) {
                    /* Unresolved local var: particle_t * p@[DW_OP_reg0(EAX)]
                       Unresolved local var: vec3_t org@[???]
                       Unresolved local var: vec3_t speed@[???]
                       Unresolved local var: float length@[???] */
      dVar14 = sin((double)(pbeam->freq * 10.0));
      VectorMA(pbeam->target,fVar13 * pbeam->amplitude * (float)dVar14,vup,&local_3c);
      dVar14 = cos((double)(pbeam->freq * 10.0));
      VectorMA(&local_3c,egon_amplitude.value * pbeam->amplitude * (float)dVar14,vright,&local_3c);
      local_2c = pbeam->source[0] - local_3c;
      local_28 = pbeam->source[1] - local_38;
      local_24 = pbeam->source[2] - local_34;
      fVar13 = Length(&local_2c);
      if (fVar13 != 0.0) {
        VectorScale(&local_2c,1000.0 / fVar13,&local_2c);
      }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: particle_t * p@[???] */
      ppVar5 = free_particles;
      ppVar4 = gpActiveTracers;
      if (free_particles != (particle_t *)0x0) {
        gpActiveTracers = free_particles;
        pppVar1 = &free_particles->next;
        free_particles = free_particles->next;
        *pppVar1 = ppVar4;
        ppVar5->die = fVar13 * 0.001 + (float)cl.time;
        ppVar5->color = 4;
        ppVar5->packedColor = 0xff;
        fVar13 = tracerLength.value;
        ppVar5->type = pt_static;
        ppVar5->ramp = fVar13;
        ppVar5->org[0] = local_3c;
        ppVar5->vel[0] = local_2c;
        ppVar5->org[1] = local_38;
        ppVar5->vel[1] = local_28;
        ppVar5->org[2] = local_34;
        ppVar5->color = 7;
        ppVar5->vel[2] = local_24;
      }
      uVar9 = pbeam->flags;
    }
    fVar13 = (pbeam->die - (float)cl.time) + pbeam->freq;
    pbeam->t = fVar13;
    if (fVar13 != 0.0) {
      fVar13 = 1.0 - pbeam->freq / fVar13;
      pbeam->t = fVar13;
    }
    if ((uVar9 & 4) == 0) {
      if ((uVar9 & 8) == 0) {
        fVar13 = pbeam->brightness;
      }
      else {
        fVar13 = (1.0 - fVar13) * pbeam->brightness;
      }
    }
    else {
      fVar13 = fVar13 * pbeam->brightness;
    }
    (*tri.Color4f)(pbeam->r,pbeam->g,pbeam->b,fVar13);
    switch(pbeam->type) {
    case 0:
      (*tri.Begin)(2);
      R_DrawSegs(pbeam->source,pbeam->delta,pbeam->width,pbeam->amplitude,pbeam->freq,pbeam->speed,
                 pbeam->segments,pbeam->flags);
      (*tri.End)();
      break;
    case 0x13:
      (*tri.Begin)(6);
      R_DrawTorus(pbeam->source,pbeam->delta,pbeam->width,pbeam->amplitude,pbeam->freq,pbeam->speed,
                  pbeam->segments);
      (*tri.End)();
      break;
    case 0x14:
      (*tri.Begin)(6);
      R_DrawDisk(pbeam->source,pbeam->delta,pbeam->width,pbeam->amplitude,pbeam->freq,pbeam->speed,
                 pbeam->segments);
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
      R_DrawRing(pbeam->source,pbeam->delta,pbeam->width,pbeam->amplitude,pbeam->freq,pbeam->speed,
                 pbeam->segments);
      (*tri.End)();
    }
  }
  return;
}


// R_BeamDraw  @ 001f0950
void R_BeamDraw(BEAM *pbeam,float frametime)

{
                    /* Unresolved local var: model_t * sprite@[???]
                       Unresolved local var: vec3_t difference@[???] */
  if (-1 < pbeam->modelIndex) {
    R_BeamDraw(pbeam,frametime);
    return;
  }
  pbeam->die = (float)cl.time;
  return;
}


// R_BeamDrawList  @ 001f0980
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_BeamDrawList(void)

{
  longdouble lVar1;
  BEAM **ppBVar2;
  BEAM *pBVar3;
  BEAM *pbeam;
  longdouble lVar4;
  
                    /* Unresolved local var: float frametime@[???]
                       Unresolved local var: BEAM * pbeam@[???]
                       Unresolved local var: BEAM * pkill@[???] */
  if ((gpActiveBeams == (BEAM *)0x0) && (cl_numbeamentities == 0)) {
    return;
  }
  lVar4 = (longdouble)cl.time;
  lVar1 = (longdouble)cl.oldtime;
  (*qglDisable)(0xbc0);
  (*qglDepthMask)('\0');
  (*tri.CullFace)(TRI_NONE);
  if (gpActiveBeams != (BEAM *)0x0) {
    pbeam = gpActiveBeams;
    if ((-1 < gpActiveBeams->flags) && (pBVar3 = gpFreeBeams, gpActiveBeams->die < (float)cl.time))
    {
      do {
        gpFreeBeams = gpActiveBeams;
        gpActiveBeams = gpFreeBeams->next;
        gpFreeBeams->next = pBVar3;
        if (gpActiveBeams == (BEAM *)0x0) {
          gpActiveBeams = (BEAM *)0x0;
          goto LAB_001f0a88;
        }
        pbeam = gpActiveBeams;
      } while ((-1 < gpActiveBeams->flags) &&
              (pBVar3 = gpFreeBeams, gpActiveBeams->die < (float)cl.time));
    }
    do {
      pBVar3 = pbeam->next;
      if ((pBVar3 != (BEAM *)0x0) && ((-1 < pBVar3->flags && (pBVar3->die <= (float)cl.time)))) {
        pbeam->next = pBVar3->next;
        pBVar3->next = gpFreeBeams;
        gpFreeBeams = pBVar3;
        pBVar3 = pbeam->next;
        while (((pBVar3 != (BEAM *)0x0 && (-1 < pBVar3->flags)) && (pBVar3->die <= (float)cl.time)))
        {
          pbeam->next = pBVar3->next;
          pBVar3->next = gpFreeBeams;
          gpFreeBeams = pBVar3;
          pBVar3 = pbeam->next;
        }
      }
                    /* Unresolved local var: model_t * sprite@[???]
                       Unresolved local var: vec3_t difference@[???] */
      if (pbeam->modelIndex < 0) {
        pbeam->die = (float)cl.time;
      }
      else {
        R_BeamDraw(pbeam,(float)(lVar4 - lVar1));
      }
      ppBVar2 = &pbeam->next;
      pbeam = *ppBVar2;
    } while (*ppBVar2 != (BEAM *)0x0);
  }
LAB_001f0a88:
  R_DrawBeamEntList((float)(lVar4 - lVar1));
  (*qglDepthMask)('\x01');
  (*tri.CullFace)(TRI_FRONT);
  (*tri.RenderMode)(0);
  return;
}


// R_BeamEntPoint  @ 001ed150
BEAM * R_BeamEntPoint(int startEnt,vec_t *end,int modelIndex,float life,float width,float amplitude,
                     float brightness,float speed,int startFrame,float framerate,float r,float g,
                     float b)

{
  BEAM **ppBVar1;
  BEAM *pbeam;
  BEAM *pBVar2;
  cl_entity_t *pcVar3;
  
                    /* Unresolved local var: BEAM * pbeam@[DW_OP_reg7(EDI)]
                       Unresolved local var: cl_entity_t * start@[DW_OP_reg0(EAX)] */
  if (startEnt < 0) {
                    /* Unresolved local var: int client_index@[???] */
    pcVar3 = ClientDLL_GetUserEntity(-startEnt & 0xfff);
  }
  else {
    pcVar3 = cl_entities + (startEnt & 0xfff);
  }
  pBVar2 = gpActiveBeams;
  pbeam = gpFreeBeams;
  if ((pcVar3 != (cl_entity_t *)0x0) && ((life == 0.0 || (pcVar3->model != (model_s *)0x0)))) {
                    /* Unresolved local var: BEAM * pbeam@[???] */
    if (gpFreeBeams != (BEAM *)0x0) {
      gpActiveBeams = gpFreeBeams;
      ppBVar1 = &gpFreeBeams->next;
      gpFreeBeams = gpFreeBeams->next;
      *ppBVar1 = pBVar2;
      pbeam->die = (float)cl.time;
      if (modelIndex < 0) {
        return (BEAM *)0x0;
      }
      R_BeamSetup(pbeam,vec3_origin,end,modelIndex,life,width,amplitude,brightness,speed);
      pbeam->type = 0;
      pbeam->flags = 1;
      if (life == 0.0) {
        pbeam->flags = -0x7fffffff;
      }
      pbeam->startEntity = startEnt;
      pbeam->endEntity = 0;
      pbeam->frameRate = framerate;
      pbeam->r = r;
      pbeam->frame = (float)startFrame;
      pbeam->g = g;
      pbeam->b = b;
    }
    return pbeam;
  }
  return (BEAM *)0x0;
}


// R_BeamEnts  @ 001ecf80
BEAM * R_BeamEnts(int startEnt,int endEnt,int modelIndex,float life,float width,float amplitude,
                 float brightness,float speed,int startFrame,float framerate,float r,float g,float b
                 )

{
  BEAM **ppBVar1;
  BEAM *pbeam;
  BEAM *pBVar2;
  cl_entity_t *pcVar3;
  cl_entity_t *pcVar4;
  
                    /* Unresolved local var: BEAM * pbeam@[DW_OP_reg3(EBX)]
                       Unresolved local var: cl_entity_t * start@[DW_OP_reg3(EBX)]
                       Unresolved local var: cl_entity_t * end@[DW_OP_reg0(EAX)] */
  if (startEnt < 0) {
                    /* Unresolved local var: int client_index@[???] */
    pcVar3 = ClientDLL_GetUserEntity(-startEnt & 0xfff);
  }
  else {
    pcVar3 = cl_entities + (startEnt & 0xfff);
  }
  if (endEnt < 0) {
                    /* Unresolved local var: int client_index@[???] */
    pcVar4 = ClientDLL_GetUserEntity(-endEnt & 0xfff);
  }
  else {
    pcVar4 = cl_entities + (endEnt & 0xfff);
  }
  pBVar2 = gpActiveBeams;
  pbeam = gpFreeBeams;
  if (((pcVar4 != (cl_entity_t *)0x0) && (pcVar3 != (cl_entity_t *)0x0)) &&
     ((life == 0.0 || ((pcVar3->model != (model_s *)0x0 && (pcVar4->model != (model_s *)0x0)))))) {
                    /* Unresolved local var: BEAM * pbeam@[???] */
    if (gpFreeBeams != (BEAM *)0x0) {
      gpActiveBeams = gpFreeBeams;
      ppBVar1 = &gpFreeBeams->next;
      gpFreeBeams = gpFreeBeams->next;
      *ppBVar1 = pBVar2;
      pbeam->die = (float)cl.time;
      if (modelIndex < 0) {
        return (BEAM *)0x0;
      }
      R_BeamSetup(pbeam,vec3_origin,vec3_origin,modelIndex,life,width,amplitude,brightness,speed);
      pbeam->type = 0;
      pbeam->flags = 3;
      if (life == 0.0) {
        pbeam->flags = -0x7ffffffd;
      }
      pbeam->startEntity = startEnt;
      pbeam->endEntity = endEnt;
      pbeam->frameRate = framerate;
      pbeam->r = r;
      pbeam->frame = (float)startFrame;
      pbeam->g = g;
      pbeam->b = b;
    }
    return pbeam;
  }
  return (BEAM *)0x0;
}


// R_BeamFollow  @ 001ed400
BEAM * R_BeamFollow(int startEnt,int modelIndex,float life,float width,float r,float g,float b,
                   float brightness)

{
  BEAM **ppBVar1;
  BEAM *pBVar2;
  BEAM *pbeam;
  
  pBVar2 = gpActiveBeams;
                    /* Unresolved local var: BEAM * pbeam@[DW_OP_reg3(EBX)] */
  pbeam = gpFreeBeams;
                    /* Unresolved local var: BEAM * pbeam@[???] */
  if (gpFreeBeams != (BEAM *)0x0) {
    gpActiveBeams = gpFreeBeams;
    ppBVar1 = &gpFreeBeams->next;
    gpFreeBeams = gpFreeBeams->next;
    *ppBVar1 = pBVar2;
    pbeam->die = (float)cl.time;
    if (modelIndex < 0) {
      pbeam = (BEAM *)0x0;
    }
    else {
      R_BeamSetup(pbeam,vec3_origin,vec3_origin,modelIndex,life,width,life,brightness,1.0);
      pbeam->type = 0x16;
      pbeam->flags = 1;
      pbeam->frame = 0.0;
      pbeam->startEntity = startEnt;
      pbeam->frameRate = 1.0;
      pbeam->r = r;
      pbeam->g = g;
      pbeam->b = b;
    }
  }
  return pbeam;
}


// R_BeamGetAttachmentPoint  @ 001ecf30
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
    pvVar2 = cl.simorg;
    if (ent->index != cl.playernum + 1) {
      pvVar2 = ent->origin;
    }
    return pvVar2;
  }
  return ent->angles + uVar1 * 3;
}


// R_BeamInit  @ 001e9d60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_BeamInit(void)

{
  gBeams = Hunk_AllocName(0x3e00,"lightning");
  return;
}


// R_BeamKill  @ 001ed770
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
      if (((uVar2 & 2) != 0) && (pBVar1->endEntity == deadEntity)) break;
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


// R_BeamLightning  @ 001ece40
BEAM * R_BeamLightning(vec_t *start,vec_t *end,int modelIndex,float life,float width,float amplitude
                      ,float brightness,float speed)

{
  BEAM **ppBVar1;
  BEAM *pBVar2;
  BEAM *pbeam;
  
  pBVar2 = gpActiveBeams;
                    /* Unresolved local var: BEAM * pbeam@[DW_OP_reg3(EBX)] */
  pbeam = gpFreeBeams;
                    /* Unresolved local var: BEAM * pbeam@[???] */
  if (gpFreeBeams != (BEAM *)0x0) {
    gpActiveBeams = gpFreeBeams;
    ppBVar1 = &gpFreeBeams->next;
    gpFreeBeams = gpFreeBeams->next;
    *ppBVar1 = pBVar2;
    pbeam->die = (float)cl.time;
    if (modelIndex < 0) {
      pbeam = (BEAM *)0x0;
    }
    else {
      R_BeamSetup(pbeam,start,end,modelIndex,life,width,amplitude,brightness,speed);
    }
  }
  return pbeam;
}


// R_BeamPoints  @ 001efdd0
/* WARNING: Variable defined which should be unmapped: pbeam */

BEAM * R_BeamPoints(vec_t *start,vec_t *end,int modelIndex,float life,float width,float amplitude,
                   float brightness,float speed,int startFrame,float framerate,float r,float g,
                   float b)

{
  BEAM **ppBVar1;
  BEAM *pBVar2;
  int iVar3;
  BEAM *pbeam_00;
  BEAM *pbeam;
  
  if ((life != 0.0) && (iVar3 = R_BeamCull(start,end,1), iVar3 == 0)) {
    return (BEAM *)0x0;
  }
                    /* Unresolved local var: BEAM * pbeam@[???] */
  pBVar2 = gpActiveBeams;
  pbeam_00 = gpFreeBeams;
  if (gpFreeBeams != (BEAM *)0x0) {
    gpActiveBeams = gpFreeBeams;
    ppBVar1 = &gpFreeBeams->next;
    gpFreeBeams = gpFreeBeams->next;
    *ppBVar1 = pBVar2;
    pbeam_00->die = (float)cl.time;
    if (modelIndex < 0) {
      pbeam_00 = (BEAM *)0x0;
    }
    else {
      R_BeamSetup(pbeam_00,start,end,modelIndex,life,width,amplitude,brightness,speed);
      if (life == 0.0) {
        pbeam_00->flags = pbeam_00->flags | 0x80000000;
      }
      pbeam_00->frameRate = framerate;
      pbeam_00->r = r;
      pbeam_00->frame = (float)startFrame;
      pbeam_00->g = g;
      pbeam_00->b = b;
    }
  }
  return pbeam_00;
}


// R_BeamRing  @ 001ed4d0
BEAM * R_BeamRing(int startEnt,int endEnt,int modelIndex,float life,float width,float amplitude,
                 float brightness,float speed,int startFrame,float framerate,float r,float g,float b
                 )

{
  BEAM **ppBVar1;
  BEAM *pbeam;
  BEAM *pBVar2;
  cl_entity_t *pcVar3;
  cl_entity_t *pcVar4;
  
                    /* Unresolved local var: BEAM * pbeam@[DW_OP_reg3(EBX)]
                       Unresolved local var: cl_entity_t * start@[DW_OP_reg3(EBX)]
                       Unresolved local var: cl_entity_t * end@[DW_OP_reg0(EAX)] */
  if (startEnt < 0) {
                    /* Unresolved local var: int client_index@[???] */
    pcVar3 = ClientDLL_GetUserEntity(-startEnt & 0xfff);
  }
  else {
    pcVar3 = cl_entities + (startEnt & 0xfff);
  }
  if (endEnt < 0) {
                    /* Unresolved local var: int client_index@[???] */
    pcVar4 = ClientDLL_GetUserEntity(-endEnt & 0xfff);
  }
  else {
    pcVar4 = cl_entities + (endEnt & 0xfff);
  }
  pBVar2 = gpActiveBeams;
  pbeam = gpFreeBeams;
  if (((pcVar4 != (cl_entity_t *)0x0) && (pcVar3 != (cl_entity_t *)0x0)) &&
     ((life == 0.0 || ((pcVar3->model != (model_s *)0x0 && (pcVar4->model != (model_s *)0x0)))))) {
                    /* Unresolved local var: BEAM * pbeam@[???] */
    if (gpFreeBeams != (BEAM *)0x0) {
      gpActiveBeams = gpFreeBeams;
      ppBVar1 = &gpFreeBeams->next;
      gpFreeBeams = gpFreeBeams->next;
      *ppBVar1 = pBVar2;
      pbeam->die = (float)cl.time;
      if (modelIndex < 0) {
        return (BEAM *)0x0;
      }
      R_BeamSetup(pbeam,vec3_origin,vec3_origin,modelIndex,life,width,amplitude,brightness,speed);
      pbeam->type = 0x18;
      pbeam->flags = 3;
      if (life == 0.0) {
        pbeam->flags = -0x7ffffffd;
      }
      pbeam->startEntity = startEnt;
      pbeam->endEntity = endEnt;
      pbeam->frameRate = framerate;
      pbeam->r = r;
      pbeam->frame = (float)startFrame;
      pbeam->g = g;
      pbeam->b = b;
    }
    return pbeam;
  }
  return (BEAM *)0x0;
}


// R_BeamSetup  @ 001ecd00
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
    pbeam->speed = speed;
    pbeam->brightness = brightness;
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


// R_BlendLightmaps  @ 00103c40
void processEntry R_BlendLightmaps(void)

{
  float *pfVar1;
  glpoly_s **ppgVar2;
  float (*pafVar3) [7];
  int iVar4;
  glpoly_s *pgVar5;
  glpoly_t *local_38;
  int local_34;
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
  local_34 = 0;
                    /* Unresolved local var: float[3] tempVert@[???]
                       Unresolved local var: glpoly_t * wp@[???] */
  do {
    local_38 = lightmap_polys[local_34];
    if (local_38 != (glpoly_t *)0x0) {
      GL_Bind(lightmap_textures[local_34]);
      (*qglTexParameterf)(0xde1,0x2801,9729.0);
      (*qglTexParameterf)(0xde1,0x2800,9729.0);
      if (lightmap_modified[local_34] != false) {
        lightmap_modified[local_34] = false;
        (*qglTexSubImage2D)(0xde1,0,0,0,0x80,0x80,gl_lightmap_format,0x1401,
                            lightmaps + local_34 * lightmap_bytes * 0x4000);
      }
      do {
        if ((local_38->flags & 0x80U) == 0) {
          pgVar5 = local_38;
          if ((local_38->flags & 0x10U) == 0) {
            (*qglBegin)(9);
            pafVar3 = local_38->verts;
            for (iVar4 = 0; iVar4 < local_38->numverts; iVar4 = iVar4 + 1) {
              (*qglTexCoord2f)((*pafVar3)[5],(*pafVar3)[6]);
              (*qglVertex3fv)(*pafVar3);
              pafVar3 = pafVar3 + 1;
            }
            (*qglEnd)();
          }
          else {
            do {
              pafVar3 = pgVar5->verts;
              (*qglBegin)(9);
              (*qglColor3f)(1.0,1.0,1.0);
              for (iVar4 = 0; iVar4 < pgVar5->numverts; iVar4 = iVar4 + 1) {
                (*qglTexCoord2f)((*pafVar3)[5],(*pafVar3)[6]);
                local_28 = (*pafVar3)[0];
                local_24 = (*pafVar3)[1];
                pfVar1 = *pafVar3;
                pafVar3 = pafVar3 + 1;
                local_20 = gl_wateramp.value * 0.8 *
                           turbsin[(int)((local_28 * 5.0 + (float)cl.time * 171.0) - local_24) &
                                   0xff] +
                           turbsin[(int)((float)cl.time * 160.0 + local_28 + local_24) & 0xff] *
                           gl_wateramp.value + pfVar1[2];
                (*qglVertex3fv)(&local_28);
              }
              (*qglEnd)();
              ppgVar2 = &pgVar5->next;
              pgVar5 = *ppgVar2;
            } while (*ppgVar2 != (glpoly_s *)0x0);
          }
        }
        else {
          DrawGLWaterPolyLightmap(local_38);
        }
        local_38 = local_38->chain;
      } while (local_38 != (glpoly_s *)0x0);
    }
    local_34 = local_34 + 1;
  } while (local_34 != 0x40);
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


// R_BlendLightmaps  @ 001e4090
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


// R_BlobExplosion  @ 001ea8b0
void R_BlobExplosion(vec_t *org)

{
  particle_s **pppVar1;
  double dVar2;
  particle_t *ppVar3;
  particle_t *ppVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  int32 iVar8;
  int32 lHigh;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: particle_t * p@[???] */
  uVar5 = 0;
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
    dVar2 = cl.time;
    fVar7 = RandomFloat(1.0,1.4);
    ppVar4->die = (float)dVar2 + fVar7;
    if ((uVar5 & 1) == 0) {
      ppVar4->type = pt_blob2;
      lHigh = 0x9b;
      iVar8 = 0x96;
    }
    else {
      ppVar4->type = pt_blob;
      lHigh = 0x47;
      iVar8 = 0x42;
    }
    iVar8 = RandomLong(iVar8,lHigh);
    uVar5 = uVar5 + 1;
    ppVar4->packedColor = 0;
    ppVar4->color = (short)iVar8;
    fVar7 = *org;
    fVar6 = RandomFloat(-16.0,16.0);
    ppVar4->org[0] = fVar6 + fVar7;
    fVar7 = RandomFloat(-256.0,256.0);
    ppVar4->vel[0] = fVar7;
    fVar7 = org[1];
    fVar6 = RandomFloat(-16.0,16.0);
    ppVar4->org[1] = fVar6 + fVar7;
    fVar7 = RandomFloat(-256.0,256.0);
    ppVar4->vel[1] = fVar7;
    fVar7 = org[2];
    fVar6 = RandomFloat(-16.0,16.0);
    ppVar4->org[2] = fVar6 + fVar7;
    fVar7 = RandomFloat(-256.0,256.0);
    ppVar4->vel[2] = fVar7;
  } while (uVar5 != 0x400);
  return;
}


// R_Blood  @ 001ebf50
void R_Blood(vec_t *org,vec_t *dir,int pcolor,int speed)

{
  particle_s **pppVar1;
  float fVar2;
  float fVar3;
  particle_t *ppVar4;
  particle_t *ppVar5;
  int32 iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  int local_4c;
  int local_48;
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
  VectorNormalize(dir);
  if (0 < speed / 2) {
    local_48 = 0;
    local_4c = speed * 3;
    do {
      fVar11 = *org;
      fVar7 = RandomFloat(-3.0,3.0);
      fVar2 = org[1];
      fVar8 = RandomFloat(-3.0,3.0);
      fVar3 = org[2];
      fVar9 = RandomFloat(-3.0,3.0);
      fVar10 = *dir;
      local_28 = RandomFloat(-0.06,0.06);
      local_28 = local_28 + fVar10;
      fVar10 = dir[1];
      local_24 = RandomFloat(-0.06,0.06);
      local_24 = local_24 + fVar10;
      fVar10 = dir[2];
      local_20 = RandomFloat(-0.06,0.06);
      ppVar4 = free_particles;
      local_20 = local_20 + fVar10;
      if (free_particles == (particle_t *)0x0) {
        return;
      }
      fVar11 = fVar11 + fVar7;
      fVar2 = fVar2 + fVar8;
      pppVar1 = &free_particles->next;
      free_particles = free_particles->next;
      *pppVar1 = active_particles;
      active_particles = ppVar4;
      fVar3 = fVar3 + fVar9;
      ppVar4->die = (float)((longdouble)1.5 + (longdouble)cl.time);
      iVar6 = RandomLong(0,9);
      ppVar4->packedColor = 0;
      ppVar4->type = pt_vox_grav;
      ppVar4->color = (short)iVar6 + (short)pcolor;
      fVar10 = RandomFloat(-1.0,1.0);
      ppVar4->org[0] = fVar10 + fVar11;
      fVar10 = RandomFloat(-1.0,1.0);
      ppVar4->org[1] = fVar10 + fVar2;
      fVar10 = RandomFloat(-1.0,1.0);
      ppVar4->org[2] = fVar10 + fVar3;
      fVar10 = (float)local_4c;
      VectorScale(&local_28,fVar10,ppVar4->vel);
      ppVar5 = free_particles;
      ppVar4 = active_particles;
      if (free_particles == (particle_t *)0x0) {
        return;
      }
      active_particles = free_particles;
      pppVar1 = &free_particles->next;
      free_particles = free_particles->next;
      *pppVar1 = ppVar4;
      ppVar5->die = (float)((longdouble)1.5 + (longdouble)cl.time);
      iVar6 = RandomLong(0,9);
      ppVar5->packedColor = 0;
      ppVar5->type = pt_vox_grav;
      ppVar5->color = (short)iVar6 + (short)pcolor;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[0] = fVar7 + fVar11;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[1] = fVar7 + fVar2;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[2] = fVar7 + fVar3;
      VectorScale(&local_28,fVar10,ppVar5->vel);
      ppVar5 = free_particles;
      ppVar4 = active_particles;
      if (free_particles == (particle_t *)0x0) {
        return;
      }
      active_particles = free_particles;
      pppVar1 = &free_particles->next;
      free_particles = free_particles->next;
      *pppVar1 = ppVar4;
      ppVar5->die = (float)((longdouble)1.5 + (longdouble)cl.time);
      iVar6 = RandomLong(0,9);
      ppVar5->packedColor = 0;
      ppVar5->type = pt_vox_grav;
      ppVar5->color = (short)iVar6 + (short)pcolor;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[0] = fVar7 + fVar11;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[1] = fVar7 + fVar2;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[2] = fVar7 + fVar3;
      VectorScale(&local_28,fVar10,ppVar5->vel);
      ppVar5 = free_particles;
      ppVar4 = active_particles;
      if (free_particles == (particle_t *)0x0) {
        return;
      }
      active_particles = free_particles;
      pppVar1 = &free_particles->next;
      free_particles = free_particles->next;
      *pppVar1 = ppVar4;
      ppVar5->die = (float)((longdouble)1.5 + (longdouble)cl.time);
      iVar6 = RandomLong(0,9);
      ppVar5->packedColor = 0;
      ppVar5->type = pt_vox_grav;
      ppVar5->color = (short)iVar6 + (short)pcolor;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[0] = fVar7 + fVar11;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[1] = fVar7 + fVar2;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[2] = fVar7 + fVar3;
      VectorScale(&local_28,fVar10,ppVar5->vel);
      ppVar5 = free_particles;
      ppVar4 = active_particles;
      if (free_particles == (particle_t *)0x0) {
        return;
      }
      active_particles = free_particles;
      pppVar1 = &free_particles->next;
      free_particles = free_particles->next;
      *pppVar1 = ppVar4;
      ppVar5->die = (float)((longdouble)1.5 + (longdouble)cl.time);
      iVar6 = RandomLong(0,9);
      ppVar5->packedColor = 0;
      ppVar5->type = pt_vox_grav;
      ppVar5->color = (short)iVar6 + (short)pcolor;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[0] = fVar7 + fVar11;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[1] = fVar7 + fVar2;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[2] = fVar7 + fVar3;
      VectorScale(&local_28,fVar10,ppVar5->vel);
      ppVar5 = free_particles;
      ppVar4 = active_particles;
      if (free_particles == (particle_t *)0x0) {
        return;
      }
      active_particles = free_particles;
      pppVar1 = &free_particles->next;
      free_particles = free_particles->next;
      *pppVar1 = ppVar4;
      ppVar5->die = (float)((longdouble)1.5 + (longdouble)cl.time);
      iVar6 = RandomLong(0,9);
      ppVar5->packedColor = 0;
      ppVar5->type = pt_vox_grav;
      ppVar5->color = (short)iVar6 + (short)pcolor;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[0] = fVar7 + fVar11;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[1] = fVar7 + fVar2;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[2] = fVar7 + fVar3;
      VectorScale(&local_28,fVar10,ppVar5->vel);
      ppVar5 = free_particles;
      ppVar4 = active_particles;
      if (free_particles == (particle_t *)0x0) {
        return;
      }
      active_particles = free_particles;
      pppVar1 = &free_particles->next;
      free_particles = free_particles->next;
      *pppVar1 = ppVar4;
      ppVar5->die = (float)((longdouble)1.5 + (longdouble)cl.time);
      iVar6 = RandomLong(0,9);
      ppVar5->packedColor = 0;
      ppVar5->type = pt_vox_grav;
      ppVar5->color = (short)iVar6 + (short)pcolor;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[0] = fVar7 + fVar11;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[1] = fVar7 + fVar2;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[2] = fVar7 + fVar3;
      VectorScale(&local_28,fVar10,ppVar5->vel);
      ppVar5 = free_particles;
      ppVar4 = active_particles;
      if (free_particles == (particle_t *)0x0) {
        return;
      }
      active_particles = free_particles;
      pppVar1 = &free_particles->next;
      free_particles = free_particles->next;
      *pppVar1 = ppVar4;
      ppVar5->die = (float)((longdouble)1.5 + (longdouble)cl.time);
      iVar6 = RandomLong(0,9);
      ppVar5->packedColor = 0;
      ppVar5->type = pt_vox_grav;
      ppVar5->color = (short)iVar6 + (short)pcolor;
      fVar7 = RandomFloat(-1.0,1.0);
      ppVar5->org[0] = fVar7 + fVar11;
      fVar11 = RandomFloat(-1.0,1.0);
      ppVar5->org[1] = fVar11 + fVar2;
      fVar11 = RandomFloat(-1.0,1.0);
      ppVar5->org[2] = fVar11 + fVar3;
      VectorScale(&local_28,fVar10,ppVar5->vel);
      local_48 = local_48 + 1;
      local_4c = local_4c - speed;
    } while (local_48 != speed / 2);
  }
  return;
}


// R_BloodSprite  @ 001a6a00
void R_BloodSprite(vec_t *org,int colorindex,int modelIndex,int modelIndex2,float size)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  double dVar7;
  int32 iVar8;
  int iVar9;
  model_t *pmVar10;
  TEMPENTITY *pTVar11;
  int32 iVar12;
  int iVar13;
  int iVar14;
  float fVar15;
  byte local_30;
  byte local_2c;
  byte local_28;
  
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
  uVar1 = host_basepal[iVar9 * 4 + 2];
  uVar2 = host_basepal[iVar9 * 4 + 1];
  uVar3 = host_basepal[iVar9 * 4];
  uVar4 = host_basepal[iVar9 * 4 + -3];
  uVar5 = host_basepal[iVar9 * 4 + -2];
  uVar6 = host_basepal[iVar9 * 4 + -4];
  if ((modelIndex2 != 0) && (pmVar10 = CL_GetModelByIndex(modelIndex2), pmVar10 != (model_t *)0x0))
  {
    iVar9 = ModelFrameCount(pmVar10);
    iVar8 = RandomLong(1,8);
    iVar12 = RandomLong(1,8);
    iVar13 = (int)((float)(iVar12 + iVar8) + size);
    if (0 < iVar13) {
      iVar14 = 0;
      do {
        pTVar11 = (*efx.CL_TempEntAlloc)(org,pmVar10);
        if (pTVar11 != (TEMPENTITY *)0x0) {
          (pTVar11->entity).curstate.rendermode = 0;
          (pTVar11->entity).curstate.renderfx = 0x14;
          (pTVar11->entity).baseline.renderamt = 0xfa;
          (pTVar11->entity).curstate.renderamt = 0xfa;
          fVar15 = RandomFloat(size / 15.0,size / 25.0);
          pTVar11->flags = 0x2c;
          (pTVar11->entity).curstate.rendercolor.b = (byte)uVar6;
          (pTVar11->entity).curstate.rendercolor.r = (byte)uVar5;
          (pTVar11->entity).curstate.scale = fVar15;
          (pTVar11->entity).curstate.rendercolor.g = (byte)uVar4;
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
          (pTVar11->entity).curstate.frame = (float)iVar8;
          if (8.0 < (float)iVar8) {
            (pTVar11->entity).curstate.frame = (float)(iVar9 + -1);
          }
          iVar8 = RandomLong(0,0x168);
          pTVar11->bounceFactor = 0.0;
          (pTVar11->entity).angles[2] = (float)iVar8;
        }
        iVar14 = iVar14 + 1;
      } while (iVar14 != iVar13);
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
      local_30 = (byte)uVar1;
      local_2c = (byte)uVar2;
      pTVar11->flags = 0x100;
      (pTVar11->entity).baseline.origin[0] = 0.0;
      (pTVar11->entity).curstate.rendercolor.r = local_30;
      local_28 = (byte)uVar3;
      (pTVar11->entity).curstate.rendercolor.g = local_2c;
      (pTVar11->entity).baseline.origin[1] = 0.0;
      (pTVar11->entity).curstate.scale = fVar15;
      (pTVar11->entity).curstate.rendercolor.b = local_28;
      (pTVar11->entity).baseline.origin[2] = 0.0;
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


// R_BloodStream  @ 001eba90
void R_BloodStream(vec_t *org,vec_t *dir,int pcolor,int speed)

{
  particle_s **pppVar1;
  float fVar2;
  short sVar3;
  float scale;
  particle_t *ppVar4;
  int32 iVar5;
  int iVar6;
  particle_t *ppVar7;
  float fVar8;
  float fVar9;
  float local_54;
  int local_50;
  int local_40;
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
  local_50 = 100;
  local_54 = 0.05;
  iVar6 = speed;
  do {
    ppVar4 = free_particles;
    ppVar7 = active_particles;
    if (free_particles == (particle_t *)0x0) {
      return;
    }
    active_particles = free_particles;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar7;
    ppVar4->die = (float)cl.time + 2.0;
    iVar5 = RandomLong(0,9);
    ppVar4->packedColor = 0;
    ppVar4->type = pt_vox_grav;
    sVar3 = (short)pcolor;
    ppVar4->color = (short)iVar5 + sVar3;
    ppVar4->org[0] = *org;
    ppVar4->org[1] = org[1];
    ppVar4->org[2] = org[2];
    local_20 = dir[2] - local_54;
    local_28 = *dir;
    local_24 = dir[1];
    local_54 = local_54 - 0.005;
    VectorScale(&local_28,(float)iVar6,ppVar4->vel);
    local_50 = local_50 + -1;
    iVar6 = (int)((double)iVar6 - 1e-05);
  } while (local_50 != 0);
  if ((0 < speed / 5) && (free_particles != (particle_t *)0x0)) {
    local_40 = 0;
    local_54 = 0.075;
    ppVar7 = free_particles;
    while( true ) {
      free_particles = ppVar7->next;
      ppVar4 = ppVar7;
      ppVar7->next = active_particles;
      active_particles = ppVar4;
      ppVar7->die = (float)((longdouble)3.0 + (longdouble)cl.time);
      iVar5 = RandomLong(0,9);
      ppVar7->packedColor = 0;
      ppVar7->type = pt_vox_slowgrav;
      ppVar7->color = (short)iVar5 + sVar3;
      ppVar7->org[0] = *org;
      ppVar7->org[1] = org[1];
      ppVar7->org[2] = org[2];
      local_28 = *dir;
      local_20 = dir[2] - local_54;
      local_24 = dir[1];
      fVar9 = RandomFloat(0.0,1.0);
      scale = fVar9 * 1.7;
      VectorScale(&local_28,scale,&local_28);
      fVar9 = (float)(int)(fVar9 * (float)speed);
      VectorScale(&local_28,fVar9,ppVar7->vel);
      ppVar4 = free_particles;
      ppVar7 = active_particles;
      if (free_particles == (particle_t *)0x0) break;
      local_54 = local_54 - 0.005;
      active_particles = free_particles;
      pppVar1 = &free_particles->next;
      free_particles = free_particles->next;
      *pppVar1 = ppVar7;
      ppVar4->die = (float)((longdouble)3.0 + (longdouble)cl.time);
      iVar5 = RandomLong(0,9);
      ppVar4->packedColor = 0;
      ppVar4->type = pt_vox_slowgrav;
      ppVar4->color = (short)iVar5 + sVar3;
      fVar2 = *org;
      fVar8 = RandomFloat(-1.0,1.0);
      ppVar4->org[0] = fVar8 + fVar2;
      fVar2 = org[1];
      fVar8 = RandomFloat(-1.0,1.0);
      ppVar4->org[1] = fVar8 + fVar2;
      fVar2 = org[2];
      fVar8 = RandomFloat(-1.0,1.0);
      ppVar4->org[2] = fVar8 + fVar2;
      local_20 = dir[2] - local_54;
      local_28 = *dir;
      local_24 = dir[1];
      VectorScale(&local_28,scale,&local_28);
      VectorScale(&local_28,fVar9,ppVar4->vel);
      ppVar4 = free_particles;
      ppVar7 = active_particles;
      if (free_particles == (particle_t *)0x0) {
        return;
      }
      active_particles = free_particles;
      pppVar1 = &free_particles->next;
      free_particles = free_particles->next;
      *pppVar1 = ppVar7;
      ppVar4->die = (float)((longdouble)3.0 + (longdouble)cl.time);
      iVar5 = RandomLong(0,9);
      ppVar4->packedColor = 0;
      ppVar4->type = pt_vox_slowgrav;
      ppVar4->color = (short)iVar5 + sVar3;
      fVar2 = *org;
      fVar8 = RandomFloat(-1.0,1.0);
      ppVar4->org[0] = fVar8 + fVar2;
      fVar2 = org[1];
      fVar8 = RandomFloat(-1.0,1.0);
      ppVar4->org[1] = fVar8 + fVar2;
      fVar2 = org[2];
      fVar8 = RandomFloat(-1.0,1.0);
      ppVar4->org[2] = fVar8 + fVar2;
      local_20 = dir[2] - local_54;
      local_28 = *dir;
      local_24 = dir[1];
      VectorScale(&local_28,scale,&local_28);
      VectorScale(&local_28,fVar9,ppVar4->vel);
      local_40 = local_40 + 1;
      if (local_40 == speed / 5) {
        return;
      }
      ppVar7 = free_particles;
      if (free_particles == (particle_t *)0x0) {
        return;
      }
    }
  }
  return;
}


// R_BreakModel  @ 001a5030
void R_BreakModel(float *pos,float *size,float *dir,float random,float life,int count,int modelIndex
                 ,char flags)

{
  int iVar1;
  model_t *model;
  int iVar2;
  TEMPENTITY *pTVar3;
  int32 iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int frameCount@[???]
                       Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: model_t * pModel@[???]
                       Unresolved local var: char type@[???] */
  if (modelIndex != 0) {
    model = CL_GetModelByIndex(modelIndex);
    if (model != (model_t *)0x0) {
      iVar2 = ModelFrameCount(model);
      if (count == 0) {
        count = (int)((size[1] * size[2] + *size * size[1] + size[2] * *size) / 432.0);
      }
      iVar5 = 100;
      if (count < 0x65) {
        iVar5 = count;
      }
      if (0 < iVar5) {
                    /* Unresolved local var: vec3_t vecSpot@[???] */
        iVar1 = 0;
        do {
          fVar7 = *pos;
          fVar6 = RandomFloat(-0.5,0.5);
          local_28 = fVar6 * *size + fVar7;
          fVar7 = pos[1];
          fVar6 = RandomFloat(-0.5,0.5);
          local_24 = fVar6 * size[1] + fVar7;
          fVar7 = pos[2];
          fVar6 = RandomFloat(-0.5,0.5);
          local_20 = fVar6 * size[2] + fVar7;
          pTVar3 = (*efx.CL_TempEntAlloc)(&local_28,model);
          if (pTVar3 == (TEMPENTITY *)0x0) {
            return;
          }
          pTVar3->hitSound = (int)(char)(flags & 0x4fU);
          if (model->type == mod_sprite) {
            iVar4 = RandomLong(0,iVar2 + -1);
            (pTVar3->entity).curstate.frame = (float)iVar4;
          }
          else if (model->type == mod_studio) {
            iVar4 = RandomLong(0,iVar2 + -1);
            (pTVar3->entity).curstate.body = iVar4;
          }
          pTVar3->flags = pTVar3->flags | 0xa8;
          iVar4 = RandomLong(0,0xff);
          if (iVar4 < 200) {
            pTVar3->flags = pTVar3->flags | 4;
            fVar7 = RandomFloat(-256.0,255.0);
            (pTVar3->entity).baseline.angles[0] = fVar7;
            fVar7 = RandomFloat(-256.0,255.0);
            (pTVar3->entity).baseline.angles[1] = fVar7;
            fVar7 = RandomFloat(-256.0,255.0);
            (pTVar3->entity).baseline.angles[2] = fVar7;
          }
          iVar4 = RandomLong(0,0xff);
          if ((iVar4 < 100) && ((flags & 0x10U) != 0)) {
            pTVar3->flags = pTVar3->flags | 0x10;
          }
          if (((flags & 0x4fU) == 1) || ((flags & 0x20U) != 0)) {
            (pTVar3->entity).curstate.rendermode = 2;
            (pTVar3->entity).curstate.renderamt = 0x80;
            (pTVar3->entity).baseline.renderamt = 0x80;
          }
          else {
            (pTVar3->entity).curstate.rendermode = 0;
            (pTVar3->entity).baseline.renderamt = 0xff;
          }
          fVar7 = *dir;
          fVar6 = RandomFloat(-random,random);
          (pTVar3->entity).baseline.origin[0] = fVar6 + fVar7;
          fVar7 = dir[1];
          fVar6 = RandomFloat(-random,random);
          (pTVar3->entity).baseline.origin[1] = fVar6 + fVar7;
          fVar7 = dir[2];
          fVar6 = RandomFloat(0.0,random);
          (pTVar3->entity).baseline.origin[2] = fVar6 + fVar7;
          fVar7 = (float)cl.time;
          fVar6 = RandomFloat(0.0,1.0);
          iVar1 = iVar1 + 1;
          pTVar3->die = life + fVar7 + fVar6;
        } while (iVar1 != iVar5);
      }
    }
  }
  return;
}


// R_BubbleTrail  @ 001a47e0
void R_BubbleTrail(vec_t *start,vec_t *end,float height,int modelIndex,int count,float speed)

{
  model_t *model;
  int iVar1;
  int32 iVar2;
  TEMPENTITY *pTVar3;
  float fVar4;
  int local_50;
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
  if (modelIndex != 0) {
    model = CL_GetModelByIndex(modelIndex);
    if (model != (model_t *)0x0) {
      iVar1 = ModelFrameCount(model);
      if (0 < count) {
        local_50 = 0;
        do {
          fVar4 = RandomFloat(0.0,1.0);
          local_28 = (*end - *start) * fVar4 + *start;
          local_24 = (end[1] - start[1]) * fVar4 + start[1];
          local_20 = start[2] + (end[2] - start[2]) * fVar4;
          pTVar3 = (*efx.CL_TempEntAlloc)(&local_28,model);
          if (pTVar3 == (TEMPENTITY *)0x0) {
            return;
          }
          pTVar3->flags = pTVar3->flags | 1;
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
          fVar4 = RandomFloat(2.0,5.0);
          local_50 = local_50 + 1;
          (pTVar3->entity).curstate.rendermode = 4;
          (pTVar3->entity).curstate.renderamt = 0xff;
          (pTVar3->entity).curstate.scale = 1.0 / fVar4;
        } while (local_50 != count);
      }
    }
  }
  return;
}


// R_Bubbles  @ 001a45f0
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
  if (modelIndex != 0) {
    model = CL_GetModelByIndex(modelIndex);
    if (model != (model_t *)0x0) {
      iVar1 = ModelFrameCount(model);
      if (0 < count) {
        iVar4 = 0;
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
        } while (iVar4 != count);
      }
    }
  }
  return;
}


// R_BuildLightMap  @ 001e2c20
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void R_BuildLightMap(msurface_t *psurf,uchar *dest,int stride)

{
  byte *pbVar1;
  colorVec *pcVar2;
  colorVec *pcVar3;
  colorVec *pcVar4;
  colorVec *pcVar5;
  short sVar6;
  int iVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  uint *puVar25;
  undefined1 auVar26 [16];
  uint uVar27;
  uint uVar28;
  int iVar29;
  colorVec *pcVar30;
  colorVec *pcVar31;
  int iVar32;
  int iVar33;
  colorVec *pcVar34;
  uint uVar35;
  uint uVar36;
  uchar *puVar37;
  int iVar38;
  int iVar39;
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  undefined1 auVar53 [16];
  undefined1 auVar57 [16];
  undefined1 auVar61 [16];
  undefined1 auVar69 [16];
  undefined1 auVar77 [16];
  undefined1 auVar85 [16];
  undefined1 auVar93 [16];
  double dVar94;
  int local_60;
  uint local_54;
  colorVec *local_50;
  uint local_48;
  uchar *local_44;
  int local_40;
  colorVec *local_3c;
  uint local_2c;
  undefined1 auVar54 [16];
  undefined1 auVar58 [16];
  undefined1 auVar62 [16];
  undefined1 auVar70 [16];
  undefined1 auVar78 [16];
  undefined1 auVar86 [16];
  undefined1 auVar63 [16];
  undefined1 auVar71 [16];
  undefined1 auVar79 [16];
  undefined1 auVar87 [16];
  undefined1 auVar51 [16];
  undefined1 auVar55 [16];
  undefined1 auVar59 [16];
  undefined1 auVar64 [16];
  undefined1 auVar72 [16];
  undefined1 auVar80 [16];
  undefined1 auVar88 [16];
  undefined1 auVar65 [16];
  undefined1 auVar73 [16];
  undefined1 auVar81 [16];
  undefined1 auVar89 [16];
  undefined1 auVar52 [16];
  undefined1 auVar56 [16];
  undefined1 auVar60 [16];
  undefined1 auVar66 [16];
  undefined1 auVar74 [16];
  undefined1 auVar82 [16];
  undefined1 auVar90 [16];
  undefined1 auVar67 [16];
  undefined1 auVar75 [16];
  undefined1 auVar83 [16];
  undefined1 auVar91 [16];
  undefined1 auVar68 [16];
  undefined1 auVar76 [16];
  undefined1 auVar84 [16];
  undefined1 auVar92 [16];
  
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
  local_44 = dest;
  if ((gl_overbright.value == 0.0) || (iVar38 = 0x100, gl_texsort == false)) {
    dVar94 = pow(2.0,(double)(1.0 / v_lightgamma.value));
    iVar38 = (int)(dVar94 * 256.0 + 0.5);
  }
  sVar6 = psurf->extents[1];
  local_3c = (colorVec *)psurf->samples;
  uVar27 = r_dlightactive & psurf->dlightbits;
  psurf->cached_dlight = uVar27;
  iVar32 = (int)sVar6 >> 4;
  psurf->dlightbits = uVar27;
  iVar33 = iVar32 + 1;
  uVar27 = (int)psurf->extents[0] >> 4;
  uVar28 = uVar27 + 1;
  iVar29 = uVar28 * iVar33;
  if (0x144 < iVar29) {
    Sys_Error("Error: lightmap for texture %s too large (%d x %d = %d luxels); cannot exceed %d\n",
              psurf->texinfo->texture,uVar28,iVar33,iVar29,0x144);
    return;
  }
  if (filterMode == false) {
    if ((r_fullbright.value == 0.0) && ((cl.worldmodel)->lightdata != (color24 *)0x0)) {
      if (0 < iVar29) {
        pcVar34 = blocklights;
        do {
          pcVar34->r = 0;
          pcVar34->g = 0;
          pcVar34->b = 0;
          pcVar34 = pcVar34 + 1;
        } while (pcVar34 != blocklights + iVar29);
      }
      if (local_3c != (colorVec *)0x0) {
        iVar39 = 0;
        do {
          if (psurf->styles[iVar39] == 0xff) break;
          iVar7 = d_lightstylevalue[psurf->styles[iVar39]];
          psurf->cached_light[iVar39] = iVar7;
          if (0 < iVar29) {
            pcVar31 = blocklights;
            pcVar34 = local_3c;
            do {
              pcVar31->r = pcVar31->r + (uint)((color24_conflict *)pcVar34)->r * iVar7;
              pcVar31->g = pcVar31->g + (uint)((color24_conflict *)pcVar34)->g * iVar7;
              pbVar1 = &((color24_conflict *)pcVar34)->b;
              pcVar34 = (colorVec *)((int)pcVar34 + 3);
              pcVar31->b = pcVar31->b + (uint)*pbVar1 * iVar7;
              pcVar31 = pcVar31 + 1;
            } while (pcVar31 != blocklights + iVar29);
          }
          iVar39 = iVar39 + 1;
          local_3c = (colorVec *)((int)local_3c + iVar29 * 3);
        } while (iVar39 != 4);
      }
      if (psurf->dlightframe == r_framecount) {
        R_AddDynamicLights(psurf);
      }
    }
    else if (0 < iVar29) {
      pcVar34 = blocklights;
      do {
        pcVar34->r = 0xff00;
        pcVar34->g = 0xff00;
        pcVar34->b = 0xff00;
        pcVar34 = pcVar34 + 1;
      } while (pcVar34 != blocklights + iVar29);
    }
  }
  else if (0 < iVar29) {
    pcVar34 = blocklights;
    local_2c = (uint)(longlong)ROUND(filterColorRed * 65280.0 * filterBrightness);
    uVar36 = local_2c;
    local_2c = (uint)(longlong)ROUND(filterColorGreen * 65280.0 * filterBrightness);
    uVar35 = local_2c;
    local_2c = (uint)(longlong)ROUND(filterColorBlue * 65280.0 * filterBrightness);
    do {
      pcVar34->r = uVar36;
      pcVar34->g = uVar35;
      pcVar34->b = local_2c;
      pcVar34 = pcVar34 + 1;
    } while (pcVar34 != blocklights + iVar29);
  }
                    /* WARNING: Read-only address (ram,0x00292ad0) is written */
  if ((gl_lightmap_format == 0x1909) || (gl_lightmap_format == 0x8049)) {
    if (0 < iVar33) {
      local_50 = (colorVec *)(dest + uVar28);
      uVar27 = uVar27 >> 4;
      local_54 = 1;
      pcVar34 = blocklights;
      do {
        auVar26 = _DAT_00292ad0;
        pcVar31 = pcVar34;
        if (0 < (int)uVar28) {
          pcVar31 = pcVar34 + uVar28;
          if ((uVar27 == 0) || (uVar28 < 0x10 || pcVar34 <= local_50 && dest <= pcVar31)) {
            uVar36 = 0;
          }
          else {
            pcVar30 = pcVar34;
            uVar36 = 0;
            do {
              pcVar2 = pcVar30 + 0xf;
              uVar35 = uVar36 + 1;
              auVar45._0_4_ = (int)pcVar30->r >> 8;
              auVar45._4_4_ = (int)pcVar30[1].r >> 8;
              auVar45._8_4_ = (int)pcVar30[2].r >> 8;
              auVar45._12_4_ = (int)pcVar30[3].r >> 8;
              iVar38 = auVar26._0_4_;
              auVar46._0_4_ = -(uint)(iVar38 < auVar45._0_4_);
              iVar29 = auVar26._4_4_;
              auVar46._4_4_ = -(uint)(iVar29 < auVar45._4_4_);
              iVar33 = auVar26._8_4_;
              auVar46._8_4_ = -(uint)(iVar33 < auVar45._8_4_);
              iVar39 = auVar26._12_4_;
              auVar46._12_4_ = -(uint)(iVar39 < auVar45._12_4_);
              auVar46 = ~auVar46 & auVar45 | auVar26 & auVar46;
              auVar40._0_4_ = (int)pcVar30[4].r >> 8;
              auVar40._4_4_ = (int)pcVar30[5].r >> 8;
              auVar40._8_4_ = (int)pcVar30[6].r >> 8;
              auVar40._12_4_ = (int)pcVar30[7].r >> 8;
              auVar49._0_4_ = -(uint)(iVar38 < auVar40._0_4_);
              auVar49._4_4_ = -(uint)(iVar29 < auVar40._4_4_);
              auVar49._8_4_ = -(uint)(iVar33 < auVar40._8_4_);
              auVar49._12_4_ = -(uint)(iVar39 < auVar40._12_4_);
              auVar41 = ~auVar49 & auVar40 | auVar26 & auVar49;
              auVar52._0_12_ = auVar46._0_12_;
              auVar52._12_2_ = auVar46._6_2_;
              auVar52._14_2_ = auVar41._6_2_;
              auVar51._12_4_ = auVar52._12_4_;
              auVar51._0_10_ = auVar46._0_10_;
              auVar51._10_2_ = auVar41._4_2_;
              auVar50._10_6_ = auVar51._10_6_;
              auVar50._0_8_ = auVar46._0_8_;
              auVar50._8_2_ = auVar46._4_2_;
              auVar48._2_8_ = auVar50._8_8_;
              auVar48._0_2_ = auVar41._2_2_;
              auVar48._10_6_ = 0;
              auVar44._12_4_ = 0;
              auVar44._0_12_ = SUB1612(auVar48 << 0x30,4);
              auVar44 = auVar44 << 0x20;
              auVar56._0_12_ = auVar44._0_12_;
              auVar56._12_2_ = auVar41._2_2_;
              auVar56._14_2_ = auVar41._10_2_;
              auVar55._12_4_ = auVar56._12_4_;
              auVar55._0_10_ = auVar44._0_10_;
              auVar55._10_2_ = auVar46._10_2_;
              auVar54._10_6_ = auVar55._10_6_;
              auVar54._0_8_ = auVar44._0_8_;
              auVar54._8_2_ = auVar46._2_2_;
              auVar8._2_8_ = auVar54._8_8_;
              auVar8._0_2_ = auVar41._8_2_;
              auVar8._10_6_ = 0;
              auVar53._12_4_ = 0;
              auVar53._0_12_ = SUB1612(auVar8 << 0x30,4);
              auVar53 = auVar53 << 0x20;
              auVar60._0_12_ = auVar53._0_12_;
              auVar60._12_2_ = auVar41._8_2_;
              auVar60._14_2_ = auVar41._12_2_;
              auVar59._12_4_ = auVar60._12_4_;
              auVar59._0_10_ = auVar53._0_10_;
              auVar59._10_2_ = auVar41._4_2_;
              auVar58._10_6_ = auVar59._10_6_;
              auVar58._0_8_ = auVar53._0_8_;
              auVar58._8_2_ = auVar41._0_2_;
              auVar9._2_8_ = auVar58._8_8_;
              auVar9._0_2_ = auVar46._12_2_;
              auVar9._10_6_ = 0;
              auVar57._12_4_ = 0;
              auVar57._0_12_ = SUB1612(auVar9 << 0x30,4);
              auVar57 = auVar57 << 0x20;
              auVar47._0_4_ = (int)pcVar30[8].r >> 8;
              auVar47._4_4_ = (int)pcVar30[9].r >> 8;
              auVar47._8_4_ = (int)pcVar30[10].r >> 8;
              auVar47._12_4_ = (int)pcVar30[0xb].r >> 8;
              auVar42._0_4_ = -(uint)(iVar38 < auVar47._0_4_);
              auVar42._4_4_ = -(uint)(iVar29 < auVar47._4_4_);
              auVar42._8_4_ = -(uint)(iVar33 < auVar47._8_4_);
              auVar42._12_4_ = -(uint)(iVar39 < auVar47._12_4_);
              pcVar3 = pcVar30 + 0xc;
              auVar48 = ~auVar42 & auVar47 | auVar26 & auVar42;
              pcVar4 = pcVar30 + 0xd;
              pcVar5 = pcVar30 + 0xe;
              pcVar30 = pcVar30 + 0x10;
              auVar43._0_4_ = (int)pcVar3->r >> 8;
              auVar43._4_4_ = (int)pcVar4->r >> 8;
              auVar43._8_4_ = (int)pcVar5->r >> 8;
              auVar43._12_4_ = (int)pcVar2->r >> 8;
              auVar93._0_4_ = -(uint)(iVar38 < auVar43._0_4_);
              auVar93._4_4_ = -(uint)(iVar29 < auVar43._4_4_);
              auVar93._8_4_ = -(uint)(iVar33 < auVar43._8_4_);
              auVar93._12_4_ = -(uint)(iVar39 < auVar43._12_4_);
              auVar44 = ~auVar93 & auVar43 | auVar26 & auVar93;
              auVar68._0_14_ = auVar57._0_14_;
              auVar68[0xe] = auVar46[0xd];
              auVar68[0xf] = auVar48[0xd];
              auVar67._14_2_ = auVar68._14_2_;
              auVar67._0_13_ = auVar57._0_13_;
              auVar67[0xd] = auVar48[0xc];
              auVar66._13_3_ = auVar67._13_3_;
              auVar66._0_12_ = auVar57._0_12_;
              auVar66[0xc] = auVar46[0xc];
              auVar65._12_4_ = auVar66._12_4_;
              auVar65._0_11_ = auVar57._0_11_;
              auVar65[0xb] = auVar48[9];
              auVar64._11_5_ = auVar65._11_5_;
              auVar64._0_10_ = auVar57._0_10_;
              auVar64[10] = auVar46[9];
              auVar63._10_6_ = auVar64._10_6_;
              auVar63._0_9_ = auVar57._0_9_;
              auVar63[9] = auVar48[8];
              auVar62._9_7_ = auVar63._9_7_;
              auVar62._0_8_ = auVar57._0_8_;
              auVar62[8] = auVar46[8];
              auVar14._1_8_ = auVar62._8_8_;
              auVar14[0] = auVar48[5];
              auVar14._9_7_ = 0;
              auVar13._10_6_ = 0;
              auVar13._0_10_ = SUB1610(auVar14 << 0x38,6);
              auVar12._11_5_ = 0;
              auVar12._0_11_ = SUB1611(auVar13 << 0x30,5);
              auVar11._12_4_ = 0;
              auVar11._0_12_ = SUB1612(auVar12 << 0x28,4);
              auVar10._13_3_ = 0;
              auVar10._0_13_ = SUB1613(auVar11 << 0x20,3);
              auVar85[0] = auVar46[0];
              auVar61._14_2_ = 0;
              auVar61._0_14_ = SUB1614(auVar10 << 0x18,2);
              auVar61 = auVar61 << 0x10;
              auVar76._0_14_ = auVar61._0_14_;
              auVar76[0xe] = auVar48[5];
              auVar76[0xf] = auVar44[5];
              auVar75._14_2_ = auVar76._14_2_;
              auVar75._0_13_ = auVar61._0_13_;
              auVar75[0xd] = auVar41[5];
              auVar74._13_3_ = auVar75._13_3_;
              auVar74._0_12_ = auVar61._0_12_;
              auVar74[0xc] = auVar46[5];
              auVar73._12_4_ = auVar74._12_4_;
              auVar73._0_11_ = auVar61._0_11_;
              auVar73[0xb] = auVar44[4];
              auVar72._11_5_ = auVar73._11_5_;
              auVar72._0_10_ = auVar61._0_10_;
              auVar72[10] = auVar48[4];
              auVar71._10_6_ = auVar72._10_6_;
              auVar71._0_9_ = auVar61._0_9_;
              auVar71[9] = auVar41[4];
              auVar70._9_7_ = auVar71._9_7_;
              auVar70._0_8_ = auVar61._0_8_;
              auVar70[8] = auVar46[4];
              auVar19._1_8_ = auVar70._8_8_;
              auVar19[0] = auVar44[1];
              auVar19._9_7_ = 0;
              auVar18._10_6_ = 0;
              auVar18._0_10_ = SUB1610(auVar19 << 0x38,6);
              auVar17._11_5_ = 0;
              auVar17._0_11_ = SUB1611(auVar18 << 0x30,5);
              auVar16._12_4_ = 0;
              auVar16._0_12_ = SUB1612(auVar17 << 0x28,4);
              auVar15._13_3_ = 0;
              auVar15._0_13_ = SUB1613(auVar16 << 0x20,3);
              auVar69._14_2_ = 0;
              auVar69._0_14_ = SUB1614(auVar15 << 0x18,2);
              auVar69 = auVar69 << 0x10;
              auVar84._0_14_ = auVar69._0_14_;
              auVar84[0xe] = auVar44[1];
              auVar84[0xf] = auVar44[9];
              auVar83._14_2_ = auVar84._14_2_;
              auVar83._0_13_ = auVar69._0_13_;
              auVar83[0xd] = auVar48[9];
              auVar82._13_3_ = auVar83._13_3_;
              auVar82._0_12_ = auVar69._0_12_;
              auVar82[0xc] = auVar48[1];
              auVar81._12_4_ = auVar82._12_4_;
              auVar81._0_11_ = auVar69._0_11_;
              auVar81[0xb] = auVar41[9];
              auVar80._11_5_ = auVar81._11_5_;
              auVar80._0_10_ = auVar69._0_10_;
              auVar80[10] = auVar41[1];
              auVar79._10_6_ = auVar80._10_6_;
              auVar79._0_9_ = auVar69._0_9_;
              auVar79[9] = auVar46[9];
              auVar78._9_7_ = auVar79._9_7_;
              auVar78._0_8_ = auVar69._0_8_;
              auVar78[8] = auVar46[1];
              auVar24._1_8_ = auVar78._8_8_;
              auVar24[0] = auVar44[8];
              auVar24._9_7_ = 0;
              auVar23._10_6_ = 0;
              auVar23._0_10_ = SUB1610(auVar24 << 0x38,6);
              auVar22._11_5_ = 0;
              auVar22._0_11_ = SUB1611(auVar23 << 0x30,5);
              auVar21._12_4_ = 0;
              auVar21._0_12_ = SUB1612(auVar22 << 0x28,4);
              auVar20._13_3_ = 0;
              auVar20._0_13_ = SUB1613(auVar21 << 0x20,3);
              auVar77._14_2_ = 0;
              auVar77._0_14_ = SUB1614(auVar20 << 0x18,2);
              auVar77 = auVar77 << 0x10;
              auVar92._0_14_ = auVar77._0_14_;
              auVar92[0xe] = auVar44[8];
              auVar92[0xf] = auVar44[0xc];
              auVar91._14_2_ = auVar92._14_2_;
              auVar91._0_13_ = auVar77._0_13_;
              auVar91[0xd] = auVar44[4];
              auVar90._13_3_ = auVar91._13_3_;
              auVar90._0_12_ = auVar77._0_12_;
              auVar90[0xc] = auVar44[0];
              auVar89._12_4_ = auVar90._12_4_;
              auVar89._0_11_ = auVar77._0_11_;
              auVar89[0xb] = auVar48[0xc];
              auVar88._11_5_ = auVar89._11_5_;
              auVar88._0_10_ = auVar77._0_10_;
              auVar88[10] = auVar48[8];
              auVar87._10_6_ = auVar88._10_6_;
              auVar87._0_9_ = auVar77._0_9_;
              auVar87[9] = auVar48[4];
              auVar86._9_7_ = auVar87._9_7_;
              auVar86._0_8_ = auVar77._0_8_;
              auVar86[8] = auVar48[0];
              auVar85._8_8_ = auVar86._8_8_;
              auVar85[7] = auVar41[0xc];
              auVar85[6] = auVar41[8];
              auVar85[5] = auVar41[4];
              auVar85[4] = auVar41[0];
              auVar85[3] = auVar46[0xc];
              auVar85[2] = auVar46[8];
              auVar85[1] = auVar46[4];
              auVar41._8_4_ = 0xffffffff;
              auVar41._0_8_ = 0xffffffffffffffff;
              auVar41._12_4_ = 0xffffffff;
              *(undefined1 (*) [16])((int)dest + uVar36 * 0x10) = auVar85 ^ auVar41;
              uVar36 = uVar35;
            } while (uVar35 < uVar27);
            pcVar34 = pcVar34 + uVar27 * 0x10;
            uVar36 = uVar27 << 4;
            if (uVar27 << 4 == uVar28) goto LAB_001e30be;
          }
          do {
            puVar25 = &pcVar34->r;
            pcVar34 = pcVar34 + 1;
            iVar38 = (int)*puVar25 >> 8;
            if (0xff < iVar38) {
              iVar38 = 0xff;
            }
            *(byte *)((int)&((colorVec *)dest)->r + uVar36) = ~(byte)iVar38;
            uVar36 = uVar36 + 1;
          } while ((int)uVar36 < (int)uVar28);
        }
LAB_001e30be:
        local_54 = local_54 + 1;
        dest = (uchar *)((int)&((colorVec *)dest)->r + stride);
        local_50 = (colorVec *)((int)&local_50->r + stride);
        pcVar34 = pcVar31;
      } while (local_54 != iVar32 + 2);
    }
  }
  else {
    if (gl_lightmap_format != 0x1908) {
      Sys_Error("Bad lightmap format");
      return;
    }
    if (0 < iVar33) {
      local_3c = blocklights;
      local_40 = 1;
      gl_lightmap_format = 0x1908;
      do {
        if (0 < (int)uVar28) {
          local_60 = 0;
          pcVar34 = local_3c;
          puVar37 = local_44;
          do {
            uVar27 = pcVar34->r * iVar38 >> 0xe;
            if (0x3ff < uVar27) {
              uVar27 = 0x3ff;
            }
            iVar29 = lightgammatable[uVar27];
            *puVar37 = (uchar)(iVar29 >> 2);
            local_48 = iVar29 >> 2 & 0xff;
            uVar27 = pcVar34->g * iVar38 >> 0xe;
            if (0x3ff < uVar27) {
              uVar27 = 0x3ff;
            }
            iVar29 = lightgammatable[uVar27];
            puVar37[1] = (uchar)(iVar29 >> 2);
            local_54 = iVar29 >> 2 & 0xff;
            uVar27 = pcVar34->b * iVar38 >> 0xe;
            if (0x3ff < uVar27) {
              uVar27 = 0x3ff;
            }
            pcVar34 = pcVar34 + 1;
            iVar29 = lightgammatable[uVar27];
            puVar37[2] = (uchar)(iVar29 >> 2);
            local_50 = (colorVec *)(iVar29 >> 2 & 0xff);
            if (gl_monolights.value == 0.0) {
              puVar37[3] = 0xff;
            }
            else {
              puVar37[2] = 0xff;
              puVar37[1] = 0xff;
              *puVar37 = 0xff;
              puVar37[3] = ~(byte)((int)local_50 * 0x1d + local_54 * 0x95 + local_48 * 0x4c >> 8);
            }
            local_60 = local_60 + 1;
            puVar37 = puVar37 + 4;
          } while (local_60 < (int)uVar28);
          local_3c = local_3c + uVar28;
          local_44 = local_44 + uVar28 * 4;
        }
        local_40 = local_40 + 1;
        local_44 = local_44 + stride + uVar28 * -4;
      } while (local_40 != iVar32 + 2);
      return;
    }
  }
  return;
}


// R_BulletImpactParticles  @ 001eace0
void R_BulletImpactParticles(vec_t *pos)

{
  particle_s **pppVar1;
  double dVar2;
  particle_t *ppVar3;
  int iVar4;
  int iVar5;
  particle_t *ppVar6;
  short sVar7;
  float fVar8;
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
  fVar8 = Length(&local_28);
  ppVar3 = free_particles;
  ppVar6 = gpActiveTracers;
  if ((1000.0 < fVar8) || (iVar4 = (int)((1000.0 - fVar8) / 100.0), iVar4 == 0)) {
    iVar5 = 4;
    sVar7 = 3;
  }
  else {
    iVar5 = iVar4 * 4;
    sVar7 = 3 - (short)((iVar4 * 0x1e) / 100);
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: particle_t * p@[???] */
  if (free_particles != (particle_t *)0x0) {
    gpActiveTracers = free_particles;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar6;
    dVar2 = cl.time;
    fVar8 = RandomFloat(0.1,0.5);
    ppVar3->die = (float)dVar2 + fVar8;
    ppVar3->color = 5;
    ppVar3->packedColor = 0xff;
    ppVar3->type = pt_grav;
    ppVar3->ramp = 0.5;
    ppVar3->org[0] = *pos;
    fVar8 = RandomFloat(-200.0,200.0);
    ppVar3->vel[0] = fVar8;
    ppVar3->org[1] = pos[1];
    fVar8 = RandomFloat(-200.0,200.0);
    ppVar3->vel[1] = fVar8;
    ppVar3->org[2] = pos[2];
    fVar8 = RandomFloat(-200.0,200.0);
    ppVar3->vel[2] = fVar8;
    ppVar3 = free_particles;
    ppVar6 = gpActiveTracers;
    if (free_particles != (particle_t *)0x0) {
      gpActiveTracers = free_particles;
      pppVar1 = &free_particles->next;
      free_particles = free_particles->next;
      *pppVar1 = ppVar6;
      dVar2 = cl.time;
      fVar8 = RandomFloat(0.1,0.5);
      ppVar3->die = (float)dVar2 + fVar8;
      ppVar3->color = 5;
      ppVar3->packedColor = 0xff;
      ppVar3->type = pt_grav;
      ppVar3->ramp = 0.5;
      ppVar3->org[0] = *pos;
      fVar8 = RandomFloat(-200.0,200.0);
      ppVar3->vel[0] = fVar8;
      ppVar3->org[1] = pos[1];
      fVar8 = RandomFloat(-200.0,200.0);
      ppVar3->vel[1] = fVar8;
      ppVar3->org[2] = pos[2];
      fVar8 = RandomFloat(-200.0,200.0);
      ppVar3->vel[2] = fVar8;
    }
  }
  if ((0 < iVar5) && (free_particles != (particle_t *)0x0)) {
    iVar4 = 0;
    ppVar6 = free_particles;
    do {
      free_particles = ppVar6->next;
      iVar4 = iVar4 + 1;
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
      fVar8 = RandomFloat(50.0,100.0);
      VectorScale(ppVar6->vel,fVar8,ppVar6->vel);
      ppVar6->packedColor = 0;
      ppVar6->type = pt_grav;
      ppVar6->color = 3 - sVar7;
      ppVar6->die = (float)cl.time + 0.5;
      if (iVar4 == iVar5) {
        return;
      }
      ppVar6 = free_particles;
    } while (free_particles != (particle_t *)0x0);
  }
  return;
}


// R_CheckStudioCache  @ 0013bef0
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


// R_CheckVariables  @ 0020b200
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_CheckVariables(void)

{
  if (((((float)filterMode != R_CheckVariables::oldFilterMode) ||
       (filterColorRed != R_CheckVariables::oldFilterColorRed)) ||
      (filterColorGreen != R_CheckVariables::oldFilterColorGreen)) ||
     ((filterColorBlue != R_CheckVariables::oldFilterColorBlue ||
      (filterBrightness != R_CheckVariables::oldFilterBrightness)))) {
    R_CheckVariables::oldFilterMode = (float)filterMode;
    R_CheckVariables::oldFilterColorRed = filterColorRed;
    R_CheckVariables::oldFilterColorGreen = filterColorGreen;
    R_CheckVariables::oldFilterColorBlue = filterColorBlue;
    R_CheckVariables::oldFilterBrightness = filterBrightness;
    GL_LoadFilterTexture(filterColorRed,filterColorGreen,filterColorBlue,filterBrightness);
  }
  return;
}


// R_Clear  @ 001d5440
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


// R_ClearParticles  @ 001ea010
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_ClearParticles(void)

{
  particle_t *ppVar1;
  BEAM *pBVar2;
  BEAM *pBVar3;
  particle_t *ppVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = r_numparticles;
                    /* Unresolved local var: int i@[???] */
  ppVar4 = particles;
  active_particles = (particle_t *)0x0;
  gpActiveTracers = (particle_t *)0x0;
  free_particles = particles;
  if (0 < r_numparticles) {
    iVar5 = 0;
    ppVar1 = particles;
    do {
      iVar5 = iVar5 + 1;
      ppVar1->next = ppVar1 + 1;
      ppVar1 = ppVar1 + 1;
    } while (iVar5 != iVar6);
  }
                    /* Unresolved local var: int i@[???] */
  ppVar4[iVar6 + -1].next = (particle_s *)0x0;
  gpActiveBeams = (BEAM *)0x0;
  gpFreeBeams = gBeams;
  Q_memset(gBeams,0,0x3e00);
  pBVar3 = gBeams;
  iVar6 = 0x80;
  pBVar2 = gBeams;
  do {
    pBVar2->next = pBVar2 + 1;
    iVar6 = iVar6 + -1;
    pBVar2 = pBVar2 + 1;
  } while (iVar6 != 0);
  pBVar3[0x7f].next = (BEAM *)0x0;
  return;
}


// R_ClearSkyBox  @ 001e1ee0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_ClearSkyBox(void)

{
                    /* Unresolved local var: int i@[???] */
  skymins[1][4] = 9999.0;
  skymins[1][0] = 9999.0;
  skymins[1][1] = 9999.0;
  skymins[1][2] = 9999.0;
  skymins[1][3] = 9999.0;
  skymins[0][0] = 9999.0;
  skymins[0][1] = 9999.0;
  skymins[0][2] = 9999.0;
  skymins[0][3] = 9999.0;
  skymins[0][4] = 9999.0;
  skymaxs[1][0] = -9999.0;
  skymaxs[1][1] = -9999.0;
  skymaxs[1][2] = -9999.0;
  skymaxs[1][3] = -9999.0;
  skymaxs[0][0] = -9999.0;
  skymaxs[0][1] = -9999.0;
  skymaxs[0][2] = -9999.0;
  skymaxs[0][3] = -9999.0;
  skymaxs[1][4] = -9999.0;
  skymaxs[0][4] = -9999.0;
  skymins[1][5] = 9999.0;
  skymins[0][5] = 9999.0;
  skymaxs[1][5] = -9999.0;
  skymaxs[0][5] = -9999.0;
  return;
}


// R_ConcatRotations  @ 0012c070
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


// R_ConcatTransforms  @ 0012c160
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


// R_CullBox  @ 001d28e0
qboolean R_CullBox(vec_t *mins,vec_t *maxs)

{
  int iVar1;
  qboolean qVar2;
  
                    /* Unresolved local var: int i@[???] */
  qVar2 = true;
  iVar1 = BoxOnPlaneSide(mins,maxs,frustum);
  if (iVar1 != 2) {
    iVar1 = BoxOnPlaneSide(mins,maxs,frustum + 1);
    if (iVar1 != 2) {
      iVar1 = BoxOnPlaneSide(mins,maxs,frustum + 2);
      if (iVar1 != 2) {
        iVar1 = BoxOnPlaneSide(mins,maxs,frustum + 3);
        qVar2 = (qboolean)(iVar1 == 2);
      }
    }
  }
  return qVar2;
}


// R_CustomDecalShoot  @ 001e6cc0
void R_CustomDecalShoot(texture_t *ptexture,int playernum,int entity,int modelIndex,vec_t *position,
                       int flags)

{
                    /* Unresolved local var: int plindex@[???] */
  R_DecalShoot_(ptexture,~playernum,entity,modelIndex,position,flags,1.0);
  return;
}


// R_DecalAlloc  @ 001e5250
decal_t * R_DecalAlloc(decal_t *pdecal)

{
  msurface_s *pmVar1;
  decal_t *pdVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  decal_t *pdVar6;
  int iVar7;
  
                    /* Unresolved local var: int limit@[???] */
  iVar3 = 0x1000;
  if (((r_decals.value < 4096.0) && (((byte)gDecalFlags & 0x80) == 0)) &&
     (iVar3 = (int)r_decals.value, iVar3 == 0)) {
    return (decal_t *)0x0;
  }
  if (pdecal == (decal_t *)0x0) {
    iVar7 = 0;
    do {
                    /* Unresolved local var: int count@[???] */
      gDecalCount = gDecalCount + 1;
      if (iVar3 <= gDecalCount) {
        gDecalCount = 0;
      }
      iVar7 = iVar7 + 1;
      pdecal = gDecalPool + gDecalCount;
    } while ((iVar7 < iVar3) && ((gDecalPool[gDecalCount].flags & 0x81U) != 0));
  }
                    /* Unresolved local var: decal_t * tmp@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: decalcache_t * pCache@[???] */
  uVar5 = ((int)&pdecal[-0x4ac4f].psurface >> 2) * -0x49249249;
                    /* Unresolved local var: int cacheIndex@[???] */
  uVar4 = uVar5 & 0xff;
  if (uVar5 - gDecalCache[uVar4].decalIndex == 0) {
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
        Sys_Error("Bad decal list");
      }
      do {
        pdVar6 = pdVar2;
        pdVar2 = pdVar6->pnext;
        if (pdVar2 == (decal_s *)0x0) goto LAB_001e52d4;
      } while (pdecal != pdVar2);
      pdVar6->pnext = pdecal->pnext;
    }
  }
LAB_001e52d4:
  pdecal->psurface = (msurface_s *)0x0;
  return pdecal;
}


// R_DecalCacheClear  @ 001e5170
void R_DecalCacheClear(decal_t *pdecal)

{
  uint uVar1;
  uint uVar2;
  
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: decalcache_t * pCache@[???] */
  uVar1 = ((int)&pdecal[-0x4ac4f].psurface >> 2) * -0x49249249;
                    /* Unresolved local var: int cacheIndex@[???] */
  uVar2 = uVar1 & 0xff;
  if (gDecalCache[uVar2].decalIndex != uVar1) {
    return;
  }
  gDecalCache[uVar2].decalIndex = -1;
  return;
}


// R_DecalCacheIndex  @ 001e5150
int R_DecalCacheIndex(int index)

{
  return index & 0xff;
}


// R_DecalCacheSlot  @ 001e5160
decalcache_t * R_DecalCacheSlot(int decalIndex)

{
                    /* Unresolved local var: int cacheIndex@[???] */
  return gDecalCache + (decalIndex & 0xff);
}


// R_DecalCreate  @ 001e5df0
void R_DecalCreate(msurface_t *psurface,int textureIndex,float scale,float x,float y)

{
  msurface_s *pmVar1;
  decal_s *pdVar2;
  ushort uVar3;
  decal_t *pdVar4;
  uint uVar5;
  decal_s *pdVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  decal_t *pdVar10;
  decal_t *pdVar11;
  int local_20 [4];
  
                    /* Unresolved local var: decal_t * pdecal@[DW_OP_reg1(ECX)]
                       Unresolved local var: decal_t * pold@[???]
                       Unresolved local var: int count@[???] */
  pdVar4 = R_DecalIntersect(psurface,local_20,x,y);
                    /* Unresolved local var: int limit@[???] */
  pdVar10 = (decal_t *)0x0;
  if (3 < local_20[0]) {
    pdVar10 = pdVar4;
  }
  if ((4096.0 <= r_decals.value) || (uVar3 = (ushort)gDecalFlags, (gDecalFlags & 0x80U) != 0)) {
    iVar9 = 0x1000;
joined_r0x001e5e54:
    pdVar4 = pdVar10;
    if (pdVar10 == (decal_t *)0x0) {
      iVar7 = 0;
      do {
                    /* Unresolved local var: int count@[???] */
        gDecalCount = gDecalCount + 1;
        if (iVar9 <= gDecalCount) {
          gDecalCount = 0;
        }
        iVar7 = iVar7 + 1;
        pdVar4 = gDecalPool + gDecalCount;
      } while ((iVar7 < iVar9) && ((gDecalPool[gDecalCount].flags & 0x81U) != 0));
    }
                    /* Unresolved local var: decal_t * tmp@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: decalcache_t * pCache@[???] */
    uVar5 = ((int)&pdVar4[-0x4ac4f].psurface >> 2) * -0x49249249;
                    /* Unresolved local var: int cacheIndex@[???] */
    uVar8 = uVar5 & 0xff;
    if (uVar5 - gDecalCache[uVar8].decalIndex == 0) {
      gDecalCache[uVar8].decalIndex = -1;
    }
    pmVar1 = pdVar4->psurface;
    if (pmVar1 != (msurface_s *)0x0) {
      pdVar10 = pmVar1->pdecals;
      if (pdVar4 == pdVar10) {
        pmVar1->pdecals = pdVar4->pnext;
      }
      else {
        if (pdVar10 == (decal_t *)0x0) {
          Sys_Error("Bad decal list");
        }
        do {
          pdVar11 = pdVar10;
          pdVar10 = pdVar11->pnext;
          if (pdVar10 == (decal_s *)0x0) goto LAB_001e5eb2;
        } while (pdVar4 != pdVar10);
        pdVar11->pnext = pdVar4->pnext;
      }
    }
LAB_001e5eb2:
    uVar3 = (ushort)gDecalFlags;
    pdVar4->psurface = (msurface_s *)0x0;
  }
  else {
    pdVar4 = (decal_t *)0x0;
    iVar9 = (int)r_decals.value;
    if (iVar9 != 0) goto joined_r0x001e5e54;
  }
  pdVar4->flags = uVar3;
  pdVar4->dx = x;
  pdVar4->pnext = (decal_s *)0x0;
  pdVar4->dy = y;
  pdVar4->texture = (short)textureIndex;
  pdVar2 = psurface->pdecals;
  if (pdVar2 == (decal_s *)0x0) {
LAB_001e5ff0:
    psurface->pdecals = pdVar4;
  }
  else {
    if ((uVar3 & 4) == 0) {
      do {
        pdVar6 = pdVar2;
        pdVar2 = pdVar6->pnext;
      } while (pdVar6->pnext != (decal_s *)0x0);
    }
    else {
                    /* Unresolved local var: decal_t * p@[???]
                       Unresolved local var: decal_t * prev@[???] */
      if ((pdVar2->flags & 0x80) != 0) {
        pdVar4->pnext = pdVar2;
        goto LAB_001e5ff0;
      }
      do {
        pdVar6 = pdVar2;
        pdVar2 = pdVar6->pnext;
        if (pdVar2 == (decal_s *)0x0) goto LAB_001e5f12;
      } while ((pdVar2->flags & 0x80) == 0);
      pdVar4->pnext = pdVar2;
    }
LAB_001e5f12:
    pdVar6->pnext = pdVar4;
  }
  pdVar4->psurface = psurface;
  pdVar4->scale = scale;
  pdVar4->entityIndex = (short)gDecalEntity;
  return;
}


// R_DecalIndex  @ 001e5130
int R_DecalIndex(decal_t *pdecal)

{
  return ((int)&pdecal[-0x4ac4f].psurface >> 2) * -0x49249249;
}


// R_DecalInit  @ 001e50e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_DecalInit(void)

{
  decalcache_t *pdVar1;
  
                    /* Unresolved local var: int i@[???] */
  Q_memset(gDecalPool,0,0x1c000);
  gDecalCount = 0;
  pdVar1 = gDecalCache;
  do {
    pdVar1->decalIndex = -1;
    pdVar1 = pdVar1 + 1;
  } while (pdVar1 != (decalcache_t *)lightmap_rectchange);
  return;
}


// R_DecalIntersect  @ 001e5bb0
decal_t * R_DecalIntersect(msurface_t *psurf,int *pcount,float x,float y)

{
  uint uVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  texture_t *ptVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  decal_t *pdVar10;
  int iVar11;
  decal_t *pdVar12;
  int local_2c;
  
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
  pdVar12 = (decal_t *)0x0;
  *pcount = 0;
  ptVar5 = psurf->texinfo->texture;
  fVar3 = (float)ptVar5->width;
  pdVar10 = psurf->pdecals;
  uVar1 = gDecalTexture->width;
  fVar4 = (float)ptVar5->height;
  uVar2 = gDecalTexture->height;
  if (pdVar10 != (decal_t *)0x0) {
    iVar11 = 0xffff;
    pdVar12 = (decal_t *)0x0;
    do {
      ptVar5 = Draw_DecalTexture((int)pdVar10->texture);
      if (((pdVar10->flags & 0x81U) == 0) && ((float)ptVar5->width <= (float)uVar1 * 1.5)) {
        uVar8 = (uint)(((float)(uVar1 >> 1) + fVar3 * x) -
                      ((float)(ptVar5->width >> 1) + fVar3 * pdVar10->dx));
        uVar7 = (int)uVar8 >> 0x1f;
        iVar9 = (uVar8 ^ uVar7) - uVar7;
        uVar7 = (uint)(((float)(uVar2 >> 1) + fVar4 * y) -
                      ((float)(ptVar5->height >> 1) + fVar4 * pdVar10->dy));
        uVar8 = (int)uVar7 >> 0x1f;
        local_2c = (uVar7 ^ uVar8) - uVar8;
        iVar6 = iVar9;
        if (iVar9 < local_2c) {
          iVar6 = local_2c;
          local_2c = iVar9;
        }
        iVar6 = (int)((float)local_2c * 0.5 + (float)iVar6);
        if (((float)iVar6 * pdVar10->scale < 8.0) &&
           ((*pcount = *pcount + 1, iVar6 <= iVar11 || (pdVar12 == (decal_t *)0x0)))) {
          iVar11 = iVar6;
          pdVar12 = pdVar10;
        }
      }
      pdVar10 = pdVar10->pnext;
    } while (pdVar10 != (decal_s *)0x0);
  }
  return pdVar12;
}


// R_DecalMPoly  @ 001e76a0
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
  GL_Bind(lightmap_textures[psurf->lightmaptexturenum]);
  (*qglBegin)(9);
  if (0 < vertCount) {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      (*qglMTexCoord2fSGIS)(TEXTURE0_SGIS,v[3],v[4]);
      (*qglMTexCoord2fSGIS)(TEXTURE1_SGIS,v[5],v[6]);
      (*qglVertex3fv)(v);
      v = v + 7;
    } while (iVar1 != vertCount);
  }
                    /* WARNING: Could not recover jumptable at 0x001e7795. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglEnd)();
  return;
}


// R_DecalNode  @ 001e6020
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
    else {
      if ((float)-gDecalSize <= fVar14) {
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
          uVar11 = (uint)node->numsurfaces;
          if (uVar11 != 0) {
            iVar13 = 0;
            psurface = gDecalModel->surfaces + node->firstsurface;
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
                  sVar2 = psurface->texturemins[1];
                  iVar10 = (int)((float)gDecalTexture->width * fVar14);
                  fVar9 = ((v->vecs[0][2] * gDecalPos[2] +
                            v->vecs[0][1] * gDecalPos[1] + v->vecs[0][0] * gDecalPos[0] +
                           v->vecs[0][3]) - (float)sVar1) - (float)iVar10 * 0.5;
                  if ((float)-iVar10 < fVar9) {
                    iVar12 = (int)((float)gDecalTexture->height * fVar14);
                    fVar8 = ((gDecalPos[2] * v->vecs[1][2] +
                              gDecalPos[1] * v->vecs[1][1] + gDecalPos[0] * v->vecs[1][0] +
                             v->vecs[1][3]) - (float)sVar2) - (float)iVar12 * 0.5;
                    if ((((float)-iVar12 < fVar8) &&
                        (fVar9 <= (float)(iVar10 + psurface->extents[0]))) &&
                       (fVar8 <= (float)(iVar12 + psurface->extents[1]))) {
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
                        if (0.0 <= local_2c * pmVar5->vecs[1][2] +
                                   local_30 * pmVar5->vecs[1][1] + local_34 * pmVar5->vecs[1][0]) {
                          gDecalFlags = gDecalFlags & 0xfffffff7;
                        }
                        else {
                          gDecalFlags = gDecalFlags | 8;
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
                                    (fVar8 + (float)sVar2) / (float)uVar4);
                      uVar11 = (uint)node->numsurfaces;
                      goto LAB_001e64e4;
                    }
                  }
                }
                uVar11 = (uint)node->numsurfaces;
              }
LAB_001e64e4:
              iVar13 = iVar13 + 1;
              psurface = psurface + 1;
            } while (iVar13 < (int)uVar11);
          }
        }
        R_DecalNode(node->children[0],flScale);
      }
      R_DecalNode(node->children[1],flScale);
    }
  }
  return;
}


// R_DecalPoly  @ 001e7610
void R_DecalPoly(float *v,texture_t *ptexture,msurface_t *psurf,int vertCount)

{
  int iVar1;
  
                    /* Unresolved local var: int j@[???] */
  GL_Bind(ptexture->gl_texturenum);
  (*qglTexEnvf)(0x2300,0x2200,8448.0);
  (*qglBegin)(9);
  if (0 < vertCount) {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      (*qglTexCoord2f)(v[3],v[4]);
      (*qglVertex3fv)(v);
      v = v + 7;
    } while (iVar1 != vertCount);
  }
                    /* WARNING: Could not recover jumptable at 0x001e768f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglEnd)();
  return;
}


// R_DecalRemoveAll  @ 001e53a0
void R_DecalRemoveAll(int textureIndex)

{
  decal_t *dest;
  msurface_s *pmVar1;
  decal_t *pdVar2;
  uint uVar3;
  int iVar4;
  short *psVar5;
  uint uVar6;
  decal_t *pdVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: decal_t * pDecal@[???] */
                    /* Unresolved local var: decal_t * tmp@[???] */
  psVar5 = &gDecalPool[0].texture;
  iVar4 = 0;
  do {
    while (*psVar5 != textureIndex) {
      iVar4 = iVar4 + 1;
      psVar5 = psVar5 + 0xe;
      if (iVar4 == 0x1000) {
        return;
      }
    }
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: decalcache_t * pCache@[???] */
    uVar3 = (iVar4 * 0x1c >> 2) * -0x49249249;
    dest = gDecalPool + iVar4;
                    /* Unresolved local var: int cacheIndex@[???] */
    uVar6 = uVar3 & 0xff;
    if (uVar3 - gDecalCache[uVar6].decalIndex == 0) {
      gDecalCache[uVar6].decalIndex = -1;
    }
    pmVar1 = gDecalPool[iVar4].psurface;
    if (pmVar1 != (msurface_s *)0x0) {
      pdVar2 = pmVar1->pdecals;
      if (dest == pdVar2) {
        pmVar1->pdecals = gDecalPool[iVar4].pnext;
      }
      else {
        if (pdVar2 == (decal_t *)0x0) {
          Sys_Error("Bad decal list");
        }
        do {
          pdVar7 = pdVar2;
          pdVar2 = pdVar7->pnext;
          if (pdVar2 == (decal_s *)0x0) goto LAB_001e5424;
        } while (dest != pdVar2);
        pdVar7->pnext = gDecalPool[iVar4].pnext;
      }
    }
LAB_001e5424:
    gDecalPool[iVar4].psurface = (msurface_s *)0x0;
    iVar4 = iVar4 + 1;
    psVar5 = psVar5 + 0xe;
    Q_memset(dest,0,0x1c);
    if (iVar4 == 0x1000) {
      return;
    }
  } while( true );
}


// R_DecalRemoveNonPermanent  @ 001e54c0
void R_DecalRemoveNonPermanent(int textureIndex)

{
  decal_t *dest;
  msurface_s *pmVar1;
  decal_t *pdVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  decal_t *pdVar7;
  short *psVar8;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: decal_t * pDecal@[???] */
                    /* Unresolved local var: decal_t * tmp@[???] */
  psVar8 = &gDecalPool[0].texture;
  iVar4 = 0;
LAB_001e54e8:
  do {
    if (*psVar8 == textureIndex) {
      dest = gDecalPool + iVar4;
      if ((gDecalPool[iVar4].flags & 1) == 0) {
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: decalcache_t * pCache@[???] */
        uVar3 = (iVar4 * 0x1c >> 2) * -0x49249249;
                    /* Unresolved local var: int cacheIndex@[???] */
        uVar6 = uVar3 & 0xff;
        if (uVar3 - gDecalCache[uVar6].decalIndex == 0) {
          gDecalCache[uVar6].decalIndex = -1;
        }
        pmVar1 = gDecalPool[iVar4].psurface;
        if (pmVar1 != (msurface_s *)0x0) {
          pdVar2 = pmVar1->pdecals;
          if (dest == pdVar2) {
            pmVar1->pdecals = gDecalPool[iVar4].pnext;
          }
          else {
            if (pdVar2 == (decal_t *)0x0) {
              Sys_Error("Bad decal list");
            }
            do {
              pdVar7 = pdVar2;
              pdVar2 = pdVar7->pnext;
              if (pdVar2 == (decal_s *)0x0) goto LAB_001e555d;
            } while (dest != pdVar2);
            pdVar7->pnext = gDecalPool[iVar4].pnext;
          }
        }
LAB_001e555d:
        iVar5 = iVar4 + 1;
        psVar8 = psVar8 + 0xe;
        gDecalPool[iVar4].psurface = (msurface_s *)0x0;
        Q_memset(dest,0,0x1c);
        iVar4 = iVar5;
        if (iVar5 == 0x1000) {
          return;
        }
        goto LAB_001e54e8;
      }
    }
    iVar4 = iVar4 + 1;
    psVar8 = psVar8 + 0xe;
    if (iVar4 == 0x1000) {
      return;
    }
  } while( true );
}


// R_DecalRemoveWithFlag  @ 001e5600
void R_DecalRemoveWithFlag(int flags)

{
  decal_t *dest;
  msurface_s *pmVar1;
  decal_t *pdVar2;
  uint uVar3;
  uint uVar4;
  decal_t *pdVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: decal_t * pDecal@[???] */
                    /* Unresolved local var: decal_t * tmp@[???] */
  psVar6 = &gDecalPool[0].flags;
  iVar7 = 0;
  do {
    while ((*psVar6 & flags) == 0) {
      iVar7 = iVar7 + 1;
      psVar6 = psVar6 + 0xe;
      if (iVar7 == 0x1000) {
        return;
      }
    }
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: decalcache_t * pCache@[???] */
    uVar3 = (iVar7 * 0x1c >> 2) * -0x49249249;
    dest = gDecalPool + iVar7;
                    /* Unresolved local var: int cacheIndex@[???] */
    uVar4 = uVar3 & 0xff;
    if (uVar3 - gDecalCache[uVar4].decalIndex == 0) {
      gDecalCache[uVar4].decalIndex = -1;
    }
    pmVar1 = gDecalPool[iVar7].psurface;
    if (pmVar1 != (msurface_s *)0x0) {
      pdVar2 = pmVar1->pdecals;
      if (dest == pdVar2) {
        pmVar1->pdecals = gDecalPool[iVar7].pnext;
      }
      else {
        if (pdVar2 == (decal_t *)0x0) {
          Sys_Error("Bad decal list");
        }
        do {
          pdVar5 = pdVar2;
          pdVar2 = pdVar5->pnext;
          if (pdVar2 == (decal_s *)0x0) goto LAB_001e5684;
        } while (dest != pdVar2);
        pdVar5->pnext = gDecalPool[iVar7].pnext;
      }
    }
LAB_001e5684:
    iVar8 = iVar7 + 1;
    psVar6 = psVar6 + 0xe;
    gDecalPool[iVar7].psurface = (msurface_s *)0x0;
    Q_memset(dest,0,0x1c);
    iVar7 = iVar8;
    if (iVar8 == 0x1000) {
      return;
    }
  } while( true );
}


// R_DecalShoot  @ 001e6d60
void R_DecalShoot(int textureIndex,int entity,int modelIndex,vec_t *position,int flags)

{
  texture_t *ptexture;
  
                    /* Unresolved local var: texture_t * ptexture@[???] */
  ptexture = Draw_DecalTexture(textureIndex);
  R_DecalShoot_(ptexture,textureIndex,entity,modelIndex,position,flags,1.0);
  return;
}


// R_DecalShootScaled  @ 001e6d10
void R_DecalShootScaled(int textureIndex,int entity,int modelIndex,vec_t *position,int flags,
                       float flScale)

{
  texture_t *ptexture;
  
                    /* Unresolved local var: texture_t * ptexture@[???] */
  ptexture = Draw_DecalTexture(textureIndex);
  R_DecalShoot_(ptexture,textureIndex,entity,modelIndex,position,flags,flScale);
  return;
}


// R_DecalShoot_  @ 001e6920
void R_DecalShoot_(texture_t *ptexture,int index,int entity,int modelIndex,vec_t *position,int flags
                  ,float flScale)

{
  char *pcVar1;
  int iVar2;
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
  
                    /* Unresolved local var: mnode_t * pnodes@[???]
                       Unresolved local var: cl_entity_t * pent@[???] */
  if ((ptexture != (texture_t *)0x0) && (g_bUsingInGameAdvertisements != false)) {
    iVar2 = Q_stricmp(ptexture->name,"}lambda06");
    if (iVar2 == 0) {
      flags = flags | 4;
    }
  }
  pcVar4 = cl_entities + entity;
  gDecalPos[0] = *position;
  gDecalPos[1] = position[1];
  gDecalPos[2] = position[2];
  if (pcVar4 == (cl_entity_t *)0x0) {
    gDecalModel = (model_t *)0x0;
  }
  else {
    gDecalModel = pcVar4->model;
    if ((modelIndex != 0) && (gDecalModel == (model_s *)0x0)) {
      gDecalModel = CL_GetModelByIndex(modelIndex);
    }
    if ((((gDecalModel != (model_s *)0x0) ||
         ((sv.active != false &&
          (gDecalModel = sv.models[sv.edicts[entity].v.modelindex], gDecalModel != (model_s *)0x0)))
         ) && (ptexture != (texture_t *)0x0)) && (gDecalModel->type == mod_brush)) {
      local_50 = gDecalModel->nodes;
      if (entity != 0) {
                    /* Unresolved local var: hull_t * phull@[???]
                       Unresolved local var: vec3_t temp@[???] */
        if (gDecalModel->firstmodelsurface != 0) {
          gDecalPos[0] = (*position - gDecalModel->hulls[0].clip_mins[0]) - pcVar4->origin[0];
          gDecalPos[1] = (position[1] - gDecalModel->hulls[0].clip_mins[1]) - pcVar4->origin[1];
          local_50 = local_50 + gDecalModel->hulls[0].firstclipnode;
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
          gDecalPos[2] = gDecalPos[2] * local_20 + gDecalPos[1] * local_24 + local_28 * gDecalPos[0]
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
      gDecalSize = ptexture->width >> 1;
      if ((uint)gDecalSize < uVar3) {
        gDecalSize = uVar3;
      }
      gDecalEntity = entity;
      pcVar1 = strstr(ptexture->name,"}z_");
      if (pcVar1 == (char *)0x0) {
        if (flScale == 1.0) {
          R_DecalNode(local_50,-1.0);
          return;
        }
        R_DecalNode(local_50,flScale);
      }
      else {
        flScale_00 = RandomFloat(0.1,0.15);
        R_DecalNode(local_50,flScale_00);
      }
      return;
    }
  }
  Con_DPrintf("Decals must hit mod_brush!\n");
  return;
}


// R_DecalUnProject  @ 001e57b0
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
  edict_t_conflict *peVar16;
  texture_t *ptVar17;
  int iVar18;
  float fVar19;
  float fVar20;
  float local_48;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
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
    fVar19 = Length((vec_t *)v);
    ptVar17 = Draw_DecalTexture((int)pdecal->texture);
    uVar12 = ptVar17->width;
    uVar13 = ptVar17->height;
    sVar3 = pdecal->psurface->texturemins[0];
    fVar7 = v->vecs[0][3];
    sVar4 = pdecal->psurface->texturemins[1];
    fVar8 = v->vecs[1][3];
    fVar20 = Length((vec_t *)v);
    if (ABS(fVar20) != 0.0) {
      fVar20 = 1.0 / ABS(fVar20);
      local_48 = fVar20 * fVar20;
    }
    VectorScale((vec_t *)v,
                (((float)sVar3 +
                 ((float)uVar10 * fVar5 - (float)sVar1) + (float)uVar12 * fVar19 * 0.5) - fVar7) *
                local_48,position);
    VectorMA(position,(((float)sVar4 +
                       ((float)uVar11 * fVar6 - (float)sVar2) + (float)uVar13 * fVar19 * 0.5) -
                      fVar8) * local_48,v->vecs[1],position);
    vecb = pdecal->psurface->plane;
    VectorMA(position,vecb->dist,vecb->normal,position);
    peVar16 = sv.edicts;
    iVar18 = (int)pdecal->entityIndex;
    if (iVar18 != 0) {
                    /* Unresolved local var: hull_t * phull@[???]
                       Unresolved local var: vec3_t temp@[???]
                       Unresolved local var: edict_t.conflict * pEdict@[???]
                       Unresolved local var: model_t * pModel@[???] */
      iVar14 = sv.edicts[iVar18].v.modelindex;
      if (((iVar14 == 0) || (pmVar15 = sv.models[iVar14], pmVar15 == (model_s *)0x0)) ||
         (pmVar15->type != mod_brush)) {
        return 0;
      }
      if (((sv.edicts[iVar18].v.angles[0] != 0.0) || (sv.edicts[iVar18].v.angles[1] != 0.0)) ||
         (sv.edicts[iVar18].v.angles[2] != 0.0)) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???] */
        AngleVectorsTranspose(sv.edicts[iVar18].v.angles,&local_30,&local_24,&local_18);
        fVar5 = *position;
        fVar6 = position[1];
        fVar7 = position[2];
        *position = local_28 * fVar7 + local_2c * fVar6 + local_30 * fVar5;
        position[1] = local_1c * fVar7 + local_20 * fVar6 + local_24 * fVar5;
        position[2] = fVar7 * local_10 + fVar6 * local_14 + fVar5 * local_18;
      }
      if (pmVar15->firstmodelsurface != 0) {
        fVar5 = *position + pmVar15->hulls[0].clip_mins[0];
        *position = fVar5;
        fVar6 = position[1] + pmVar15->hulls[0].clip_mins[1];
        position[1] = fVar6;
        fVar7 = position[2] + pmVar15->hulls[0].clip_mins[2];
        position[2] = fVar7;
        *position = fVar5 + peVar16[iVar18].v.origin[0];
        position[1] = fVar6 + peVar16[iVar18].v.origin[1];
        position[2] = fVar7 + peVar16[iVar18].v.origin[2];
      }
    }
  }
  return iVar18;
}


// R_DecalUnlink  @ 001e51b0
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
  uVar3 = ((int)&pdecal[-0x4ac4f].psurface >> 2) * -0x49249249;
                    /* Unresolved local var: int cacheIndex@[???] */
  uVar4 = uVar3 & 0xff;
  if (uVar3 - gDecalCache[uVar4].decalIndex == 0) {
    gDecalCache[uVar4].decalIndex = -1;
  }
  pmVar1 = pdecal->psurface;
  if (pmVar1 != (msurface_s *)0x0) {
    pdVar2 = pmVar1->pdecals;
    if (pdVar2 == pdecal) {
      pmVar1->pdecals = pdecal->pnext;
    }
    else {
      if (pdVar2 == (decal_t *)0x0) {
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


// R_DecalVertsClip  @ 001e7220
float * R_DecalVertsClip(float *poutVerts,decal_t *pdecal,msurface_t *psurf,texture_t *ptexture,
                        int *pvertCount)

{
  float fVar1;
  texture_t *ptVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  float *pfVar7;
  int iVar8;
  ushort uVar9;
  float (*pafVar10) [7];
  int iVar11;
  
                    /* Unresolved local var: float * v@[???]
                       Unresolved local var: float scalex@[???]
                       Unresolved local var: float scaley@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int outCount@[???] */
  fVar1 = pdecal->scale;
  ptVar2 = psurf->texinfo->texture;
  uVar3 = ptVar2->width;
  uVar4 = ptexture->width;
  uVar5 = ptVar2->height;
  uVar6 = ptexture->height;
  if (poutVerts == (float *)0x0) {
    poutVerts = vert[0];
  }
  iVar8 = psurf->polys->numverts;
  if (0 < iVar8) {
    pafVar10 = psurf->polys->verts;
    pfVar7 = vert[0] + 3;
    iVar11 = 0;
    do {
      (*(float (*) [7])(pfVar7 + -3))[0] = (*pafVar10)[0];
      pfVar7[-2] = (*pafVar10)[1];
      pfVar7[-1] = (*pafVar10)[2];
      *pfVar7 = ((*pafVar10)[3] - pdecal->dx) * (((float)uVar3 * fVar1) / (float)uVar4);
      pfVar7[1] = ((*pafVar10)[4] - pdecal->dy) * (((float)uVar5 * fVar1) / (float)uVar6);
      uVar9 = pdecal->flags;
      if ((uVar9 & 8) != 0) {
        *pfVar7 = 1.0 - *pfVar7;
        uVar9 = pdecal->flags;
      }
      if ((uVar9 & 0x10) != 0) {
        pfVar7[1] = 1.0 - pfVar7[1];
      }
      iVar11 = iVar11 + 1;
      pafVar10 = pafVar10 + 1;
      pfVar7 = pfVar7 + 7;
      iVar8 = psurf->polys->numverts;
    } while (iVar11 < iVar8);
  }
  iVar8 = SHClip(vert[0],iVar8,outvert[0],0);
  iVar8 = SHClip(outvert[0],iVar8,vert[0],1);
  iVar8 = SHClip(vert[0],iVar8,outvert[0],2);
  iVar8 = SHClip(outvert[0],iVar8,poutVerts,3);
  if ((iVar8 != 0) && ((pdecal->flags & 0x20U) != 0)) {
    uVar9 = pdecal->flags & 0xffdf;
    pdecal->flags = uVar9;
    if (iVar8 == 4) {
                    /* Unresolved local var: int clipped@[???]
                       Unresolved local var: float s@[???]
                       Unresolved local var: float t@[???] */
      if ((((*(float (*) [7])poutVerts)[3] == 0.0) || ((*(float (*) [7])poutVerts)[3] == 1.0)) &&
         (((*(float (*) [7])poutVerts)[4] == 0.0 || ((*(float (*) [7])poutVerts)[4] == 1.0)))) {
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
  *pvertCount = iVar8;
  return *(float (*) [7])poutVerts;
}


// R_DecalVertsLight  @ 001e7170
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
              ((pmVar6->vecs[0][2] * v[2] + pmVar6->vecs[0][1] * v[1] + pmVar6->vecs[0][0] * *v +
               pmVar6->vecs[0][3]) - (float)psurf->texturemins[0]) + 8.0) * 0.00048828125;
      v[6] = ((float)(iVar7 << 4) +
              ((v[2] * fVar4 + v[1] * fVar3 + *v * fVar2 + fVar5) - (float)sVar1) + 8.0) *
             0.00048828125;
      v = v + 7;
    } while (iVar8 != vertCount);
  }
  return;
}


// R_DecalVertsNoclip  @ 001e7560
float * R_DecalVertsNoclip(decal_t *pdecal,msurface_t *psurf,texture_t *ptexture,
                          qboolean bMultitexture)

{
  uint uVar1;
  float *v;
  uint uVar2;
  int local_10 [2];
  
                    /* Unresolved local var: float * vlist@[???]
                       Unresolved local var: decalcache_t * pCache@[DW_OP_reg6(ESI)]
                       Unresolved local var: int decalIndex@[???]
                       Unresolved local var: int outCount@[???] */
  uVar1 = ((int)&pdecal[-0x4ac4f].psurface >> 2) * -0x49249249;
                    /* Unresolved local var: int cacheIndex@[???] */
  uVar2 = uVar1 & 0xff;
  if (gDecalCache[uVar2].decalIndex == uVar1) {
    return gDecalCache[uVar2].decalVert[0];
  }
  gDecalCache[uVar2].decalIndex = uVar1;
  v = R_DecalVertsClip(gDecalCache[uVar2].decalVert[0],pdecal,psurf,ptexture,local_10);
  if (bMultitexture == false) {
    return v;
  }
  R_DecalVertsLight(v,psurf,4);
  return v;
}


// R_DefaultSprite  @ 001a6e10
TEMPENTITY * R_DefaultSprite(float *pos,int spriteIndex,float framerate)

{
  float fVar1;
  model_t *model;
  int iVar2;
  TEMPENTITY *pTVar3;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: int frameCount@[???]
                       Unresolved local var: model_t * pSprite@[???] */
  pTVar3 = (TEMPENTITY *)0x0;
  if (cl.time != cl.oldtime) {
    model = CL_GetModelByIndex(spriteIndex);
    if (((model == (model_t *)0x0) || (spriteIndex == 0)) || (model->type != mod_sprite)) {
      Con_DPrintf("No Sprite %d!\n",spriteIndex);
      return (TEMPENTITY *)0x0;
    }
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
    }
  }
  return pTVar3;
}


// R_DestroyObjects  @ 00210550
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_DestroyObjects(void)

{
  if (transObjects != (transObjRef *)0x0) {
    Mem_Free(transObjects);
    transObjects = (transObjRef *)0x0;
  }
  maxTransObjs = 0;
  return;
}


// R_DrawAliasModel  @ 001d34f0
void R_DrawAliasModel(cl_entity_t *e)

{
  float fVar1;
  model_s *s1;
  int iVar2;
  int iVar3;
  aliashdr_t *paliashdr;
  int posenum;
  dlight_t *pdVar4;
  float fVar5;
  vec_t local_54;
  vec_t local_50 [4];
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
                    /* Unresolved local var: int i@[???] */
  s1 = currententity->model;
  local_34 = s1->mins[0] + currententity->origin[0];
  local_30 = s1->mins[1] + currententity->origin[1];
  local_2c = s1->mins[2] + currententity->origin[2];
  local_28 = currententity->origin[0] + s1->maxs[0];
  local_24 = currententity->origin[1] + s1->maxs[1];
  local_20 = currententity->origin[2] + s1->maxs[2];
  iVar3 = BoxOnPlaneSide(&local_34,&local_28,frustum);
  if ((((iVar3 != 2) && (iVar3 = BoxOnPlaneSide(&local_34,&local_28,frustum + 1), iVar3 != 2)) &&
      (iVar3 = BoxOnPlaneSide(&local_34,&local_28,frustum + 2), iVar3 != 2)) &&
     (iVar3 = BoxOnPlaneSide(&local_34,&local_28,frustum + 3), iVar3 != 2)) {
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
    pdVar4 = cl_dlights;
LAB_001d365b:
    do {
      if ((float)cl.time <= *(float *)(((lightstyle_t *)pdVar4)->map + 0x10)) {
        local_40 = currententity->origin[0] - (float)((lightstyle_t *)pdVar4)->length;
        local_3c = currententity->origin[1] - *(float *)((lightstyle_t *)pdVar4)->map;
        local_38 = currententity->origin[2] - *(float *)(((lightstyle_t *)pdVar4)->map + 4);
        fVar1 = *(float *)(((lightstyle_t *)pdVar4)->map + 8);
        fVar5 = Length(&local_40);
        fVar1 = fVar1 - fVar5;
        if (0.0 < fVar1) {
          ambientlight = fVar1 + ambientlight;
          pdVar4 = (dlight_t *)(((lightstyle_t *)pdVar4)->map + 0x24);
          if ((lightstyle_t *)pdVar4 == cl_lightstyle) break;
          goto LAB_001d365b;
        }
      }
      pdVar4 = (dlight_t *)(((lightstyle_t *)pdVar4)->map + 0x24);
    } while ((lightstyle_t *)pdVar4 != cl_lightstyle);
    if (128.0 < ambientlight) {
      ambientlight = 128.0;
    }
    if (192.0 < shadelight + ambientlight) {
      shadelight = 192.0 - ambientlight;
    }
    iVar3 = Q_strcmp(s1->name,"progs/flame2.mdl");
    if ((iVar3 == 0) || (iVar3 = Q_strcmp(s1->name,"progs/flame.mdl"), iVar3 == 0)) {
      ambientlight = 256.0;
      shadelight = 256.0;
    }
    shadelight = shadelight / 200.0;
    shadedots = r_avertexnormal_dots[(int)(e->angles[1] * 0.044444446) & 0xf];
    sincosf(-((e->angles[1] / 180.0) * 3.1415927),local_50,&local_54);
    shadevector[2] = 1.0;
    shadevector[0] = local_54;
    shadevector[1] = local_50[0];
    VectorNormalize(shadevector);
    paliashdr = Mod_Extradata(currententity->model);
    c_alias_polys = c_alias_polys + paliashdr->numtris;
    (*qglPushMatrix)();
    R_RotateForEntity(e->origin,e);
    (*qglTranslatef)(paliashdr->scale_origin[0],paliashdr->scale_origin[1],
                     paliashdr->scale_origin[2]);
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
    if ((iVar3 < 0) || (paliashdr->numframes <= iVar3)) {
      Con_DPrintf("R_AliasSetupFrame: no such frame %d\n",iVar3);
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
    if (r_shadows.value != 0.0) {
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
  }
  return;
}


// R_DrawBeamEntList  @ 001f0740
void R_DrawBeamEntList(float frametime)

{
  cl_entity_t *ent;
  float speed;
  int iVar1;
  uint uVar2;
  int iVar3;
  BEAM local_9c;
  
                    /* Unresolved local var: BEAM beam@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int beamType@[???]
                       Unresolved local var: cl_entity_t * ent@[???] */
  if (0 < cl_numbeamentities) {
    iVar3 = 0;
    do {
      while( true ) {
        ent = cl_beamentities[iVar3];
        uVar2 = (ent->curstate).rendermode;
        speed = (ent->curstate).animtime;
        iVar1 = CL_FxBlend(ent);
        uVar2 = uVar2 & 0xf;
        R_BeamSetup(&local_9c,ent->origin,(ent->curstate).angles,(ent->curstate).movetype,0.0,
                    (ent->curstate).scale,(float)(ent->curstate).body * 0.01,
                    (float)iVar1 * 0.003921569,speed);
        local_9c.frameRate = 0.0;
        local_9c.b = (float)(ent->curstate).rendercolor.b * 0.003921569;
        local_9c.g = (float)(ent->curstate).rendercolor.g * 0.003921569;
        local_9c.r = (float)(ent->curstate).rendercolor.r * 0.003921569;
        local_9c.frame = (float)(int)(ent->curstate).frame;
        if (uVar2 == 1) {
          local_9c.type = 0;
          local_9c.flags = 2;
          local_9c.startEntity = 0;
          local_9c.endEntity = (int)(ent->curstate).skin;
        }
        else if (uVar2 == 2) {
          local_9c.type = 0;
          local_9c.startEntity = (ent->curstate).sequence;
          local_9c.flags = 3;
          local_9c.endEntity = (int)(ent->curstate).skin;
        }
        uVar2 = (ent->curstate).rendermode;
        if ((uVar2 & 0x10) != 0) {
          local_9c.flags = local_9c.flags | 0x10;
        }
        if ((uVar2 & 0x20) != 0) {
          local_9c.flags = local_9c.flags | 0x20;
        }
        if ((uVar2 & 0x40) != 0) {
          local_9c.flags = local_9c.flags | 0x40;
        }
        if ((uVar2 & 0x80) != 0) {
          local_9c.flags = local_9c.flags | 0x80;
        }
        local_9c.pFollowModel = (model_s *)0x0;
        if (-1 < local_9c.modelIndex) break;
        iVar3 = iVar3 + 1;
        local_9c.die = (float)cl.time;
        if (cl_numbeamentities <= iVar3) {
          return;
        }
      }
                    /* Unresolved local var: model_t * sprite@[???]
                       Unresolved local var: vec3_t difference@[???] */
      iVar3 = iVar3 + 1;
      R_BeamDraw(&local_9c,frametime);
    } while (iVar3 < cl_numbeamentities);
  }
  return;
}


// R_DrawBeamFollow  @ 001eee40
void R_DrawBeamFollow(BEAM *pbeam)

{
  longdouble lVar1;
  particle_t *point;
  particle_s *ppVar2;
  ushort in_FPUStatusWord;
  longdouble lVar3;
  float fVar4;
  double dVar5;
  float local_94;
  float local_90;
  vec_t *local_84;
  float local_70;
  float local_6c;
  float local_68;
  vec_t local_64 [3];
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
    fVar4 = 0.0;
LAB_001ef2b0:
    in_FPUStatusWord = in_FPUStatusWord & 0xfdff;
    point = ppVar2;
    if (fVar4 != 0.0) {
      local_70 = pbeam->source[0];
      local_6c = pbeam->source[1];
      local_68 = pbeam->source[2];
      ScreenTransform(pbeam->source,&local_40);
      ScreenTransform(ppVar2->org,&local_4c);
      goto LAB_001eef72;
    }
  }
  else {
    if (ppVar2 == (particle_s *)0x0) {
      if (free_particles == (particle_t *)0x0) {
        return;
      }
      fVar4 = 0.0;
      point = free_particles;
      free_particles = free_particles->next;
    }
    else {
      local_70 = ppVar2->org[0] - pbeam->source[0];
      local_6c = ppVar2->org[1] - pbeam->source[1];
      local_68 = ppVar2->org[2] - pbeam->source[2];
      fVar4 = Length(&local_70);
      in_FPUStatusWord = in_FPUStatusWord & 0xfdff;
      if ((fVar4 < 32.0) || (free_particles == (particle_t *)0x0)) goto LAB_001ef2b0;
      point = free_particles;
      free_particles = free_particles->next;
    }
    point->org[0] = pbeam->source[0];
    point->org[1] = pbeam->source[1];
    point->org[2] = pbeam->source[2];
    point->die = pbeam->amplitude + (float)cl.time;
    point->vel[0] = 0.0;
    point->vel[1] = 0.0;
    point->vel[2] = 0.0;
    pbeam->die = pbeam->amplitude + (float)cl.time;
    point->next = ppVar2;
    pbeam->particles = point;
    if (point == (particle_t *)0x0) {
      ppVar2 = (particle_s *)0x0;
      goto LAB_001ef2b0;
    }
  }
  if (point->next == (particle_s *)0x0) {
    return;
  }
  local_70 = point->org[0];
  local_6c = point->org[1];
  local_68 = point->org[2];
  ScreenTransform(point->org,&local_40);
  ScreenTransform(point->next->org,&local_4c);
  ppVar2 = point->next;
LAB_001eef72:
  local_84 = &local_4c;
  local_34 = local_4c - local_40;
  local_2c = 0;
  local_30 = local_48 - local_3c;
  VectorNormalize(&local_34);
  VectorScale(vup,local_34,local_28);
  VectorMA(local_28,-local_30,vright,local_28);
  VectorMA(&local_70,pbeam->width,local_28,local_64);
  VectorMA(&local_70,-pbeam->width,local_28,local_58);
  lVar3 = (longdouble)cl.time;
  if (ppVar2 != (particle_s *)0x0) {
    fVar4 = 1.0 / pbeam->amplitude;
    local_90 = 0.0;
    local_94 = (float)(((longdouble)pbeam->die - lVar3) * (longdouble)fVar4);
    do {
      (*tri.Brightness)(local_94);
      (*tri.TexCoord2f)(0.0,0.0);
      (*tri.Vertex3fv)(local_64);
      (*tri.Brightness)(local_94);
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
      local_94 = 0.0;
      if (ppVar2->next != (particle_s *)0x0) {
        local_94 = (ppVar2->die - (float)cl.time) * fVar4;
      }
      (*tri.Brightness)(local_94);
      (*tri.TexCoord2f)(1.0,1.0);
      (*tri.Vertex3fv)(local_58);
      (*tri.Brightness)(local_94);
      (*tri.TexCoord2f)(0.0,1.0);
      (*tri.Vertex3fv)(local_64);
      local_40 = local_4c;
      lVar3 = (longdouble)(local_90 + 1.0);
      local_3c = local_48;
      local_38 = local_44;
      do {
        lVar3 = lVar3 - (longdouble)(unkint10)(lVar3 / (longdouble)1) * (longdouble)1;
      } while ((in_FPUStatusWord & 0x400) != 0);
      in_FPUStatusWord = in_FPUStatusWord & 0xfdff;
      if (NAN(lVar3)) {
        dVar5 = fmod((double)(local_90 + 1.0),1.0);
        lVar3 = (longdouble)dVar5;
      }
      local_90 = (float)lVar3;
      ppVar2 = ppVar2->next;
    } while (ppVar2 != (particle_s *)0x0);
    lVar3 = (longdouble)cl.time;
  }
  ppVar2 = pbeam->particles;
  lVar1 = (longdouble)cl.oldtime;
  if (ppVar2 == (particle_s *)0x0) {
    return;
  }
  do {
    VectorMA(ppVar2->org,(float)(lVar3 - lVar1),ppVar2->vel,ppVar2->org);
    ppVar2 = ppVar2->next;
  } while (ppVar2 != (particle_s *)0x0);
  return;
}


// R_DrawBrushModel  @ 001e8a20
void R_DrawBrushModel(cl_entity_t *e)

{
  float fVar1;
  float fVar2;
  float fVar3;
  model_s *pmVar4;
  uint uVar5;
  mplane_t *pmVar6;
  bool bVar7;
  qboolean qVar8;
  int iVar9;
  texture_t *ptVar10;
  int iVar11;
  GLenum *pGVar12;
  int iVar13;
  dlight_t *pdVar14;
  msurface_t *pmVar15;
  undefined4 local_b0;
  float local_5c;
  float local_58;
  float local_54;
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
                       Unresolved local var: qboolean rotated@[???] */
  pGVar12 = (GLenum *)&stack0xffffff54;
  currenttexture = -1;
  pmVar4 = e->model;
  currententity = e;
  if (((e->angles[0] == 0.0) && (e->angles[1] == 0.0)) && (e->angles[2] == 0.0)) {
    bVar7 = false;
    local_5c = pmVar4->mins[0] + e->origin[0];
    local_58 = pmVar4->mins[1] + e->origin[1];
    local_54 = pmVar4->mins[2] + e->origin[2];
    local_4c = e->origin[0] + pmVar4->maxs[0];
    local_48 = e->origin[1] + pmVar4->maxs[1];
    local_44 = e->origin[2] + pmVar4->maxs[2];
  }
  else {
    local_44 = pmVar4->radius;
    bVar7 = true;
    local_5c = e->origin[0] - local_44;
    local_4c = e->origin[0] + local_44;
    local_58 = e->origin[1] - local_44;
    local_48 = e->origin[1] + local_44;
    local_54 = e->origin[2] - local_44;
    local_44 = e->origin[2] + local_44;
  }
  local_b0 = 0x1e8ad8;
  qVar8 = R_CullBox(&local_5c,&local_4c);
  if (qVar8 != false) {
    return;
  }
  local_b0 = 0x1e8b87;
  (*qglColor3f)(1.0,1.0,1.0);
  local_b0 = 0x1e8ba0;
  Q_memset(lightmap_polys,0,0x100);
  fVar1 = r_refdef.vieworg[0] - e->origin[0];
  fVar2 = r_refdef.vieworg[1] - e->origin[1];
  fVar3 = r_refdef.vieworg[2] - e->origin[2];
  modelorg[0] = fVar1;
  modelorg[1] = fVar2;
  modelorg[2] = fVar3;
  if (bVar7) {
                    /* Unresolved local var: vec3_t temp@[???]
                       Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???] */
    local_b0 = 0x1e901d;
    AngleVectors(e->angles,&local_40,&local_34,&local_28);
    modelorg[0] = local_38 * fVar3 + local_3c * fVar2 + local_40 * fVar1;
    modelorg[1] = -(local_2c * fVar3 + local_30 * fVar2 + local_34 * fVar1);
    modelorg[2] = fVar3 * local_20 + fVar2 * local_24 + fVar1 * local_28;
  }
  iVar9 = pmVar4->firstmodelsurface;
  pmVar15 = pmVar4->surfaces;
  if ((iVar9 != 0) && (gl_flashblend.value == 0.0)) {
    pdVar14 = cl_dlights;
    iVar11 = 0;
    do {
                    /* Unresolved local var: vec3_t saveOrigin@[???] */
      if (((float)cl.time <= pdVar14->die) && (pdVar14->radius != 0.0)) {
        fVar1 = pdVar14->origin[0];
        fVar2 = pdVar14->origin[1];
        fVar3 = pdVar14->origin[2];
        pdVar14->origin[0] = fVar1 - e->origin[0];
        pdVar14->origin[1] = fVar2 - e->origin[1];
        pdVar14->origin[2] = fVar3 - e->origin[2];
        local_b0 = 0x1e8f56;
        R_MarkLights(cl_dlights + iVar11,1 << ((byte)iVar11 & 0x1f),
                     pmVar4->nodes + pmVar4->hulls[0].firstclipnode);
        pdVar14->origin[0] = fVar1;
        pdVar14->origin[1] = fVar2;
        pdVar14->origin[2] = fVar3;
      }
      iVar11 = iVar11 + 1;
      pdVar14 = pdVar14 + 1;
    } while (iVar11 != 0x20);
  }
  local_b0 = 0x1e8bff;
  (*qglPushMatrix)();
  local_b0 = 0x1e8c11;
  R_RotateForEntity(e->origin,e);
  local_b0 = 0x1e8c19;
  R_SetRenderMode(e);
  iVar11 = pmVar4->nummodelsurfaces;
  if (0 < iVar11) {
    iVar13 = 0;
    pmVar15 = pmVar15 + iVar9;
    do {
      while( true ) {
        uVar5 = pmVar15->flags;
        pmVar6 = pmVar15->plane;
        if ((uVar5 & 0x10) != 0) break;
        fVar1 = pmVar6->dist;
LAB_001e8c3b:
        fVar1 = (modelorg[2] * pmVar6->normal[2] +
                modelorg[1] * pmVar6->normal[1] + modelorg[0] * pmVar6->normal[0]) - fVar1;
        if ((uVar5 & 2) == 0) {
          if (fVar1 <= 0.01) goto LAB_001e8dc0;
LAB_001e8c76:
          if (gl_texsort != false) {
                    /* Unresolved local var: texture_t * t@[???]
                       Unresolved local var: uchar * base@[???]
                       Unresolved local var: int maps@[???] */
            c_brush_polys = c_brush_polys + 1;
            if ((uVar5 & 4) == 0) {
              local_b0 = 0x1e8e18;
              ptVar10 = R_TextureAnimation(pmVar15);
              local_b0 = 0x1e8e23;
              GL_Bind(ptVar10->gl_texturenum);
              if ((pmVar15->flags & 0x10) == 0) {
                local_b0 = 0x1e8e34;
                R_RenderBrushPoly(pmVar15);
                iVar11 = pmVar4->nummodelsurfaces;
              }
              else {
                local_b0 = 0x1e90de;
                EmitWaterPolys(pmVar15,0);
                iVar11 = pmVar4->nummodelsurfaces;
              }
            }
            goto LAB_001e8ca0;
          }
          local_b0 = 0x1e8dfe;
          R_SetRenderMode(e);
          iVar9 = 0;
        }
        else {
          if (fVar1 < -0.01) goto LAB_001e8c76;
LAB_001e8dc0:
          if ((uVar5 & 0x10) == 0) goto LAB_001e8ca0;
          local_b0 = 0x1e8dd4;
          R_SetRenderMode(e);
          iVar9 = 1;
        }
        local_b0 = 0x1e8de5;
        R_DrawSequentialPoly(pmVar15,iVar9);
        iVar11 = pmVar4->nummodelsurfaces;
LAB_001e8ca0:
        iVar13 = iVar13 + 1;
        pmVar15 = pmVar15 + 1;
        if (iVar11 <= iVar13) goto LAB_001e8cf0;
      }
      if ((pmVar6->type != '\x02') && (gl_watersides.value == 0.0)) goto LAB_001e8ca0;
      fVar1 = pmVar6->dist;
      if (local_54 + 1.0 < fVar1) goto LAB_001e8c3b;
      iVar13 = iVar13 + 1;
      pmVar15 = pmVar15 + 1;
    } while (iVar13 < iVar11);
  }
LAB_001e8cf0:
  iVar9 = 0;
  if ((currententity->curstate).rendermode != 0) {
    local_b0 = 0x1e90ae;
    (*qglTexEnvf)(0x2300,0x2200,8448.0);
    local_b0 = 0x1e90bb;
    (*qglDisable)(0xbe2);
    iVar9 = (currententity->curstate).rendermode;
  }
  if (gl_texsort == false) {
    if (iVar9 != 1) goto LAB_001e8e47;
  }
  else if (iVar9 == 4) {
    pGVar12 = (GLenum *)&stack0xffffff54;
    if (gl_lightholes.value != 0.0) {
      local_b0 = 0x1e8d3e;
      (*qglDepthFunc)(0x202);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: glpoly_t * p@[???]
                       Unresolved local var: float * v@[???]
                       Unresolved local var: int j@[???] */
      pGVar12 = (GLenum *)&stack0xffffff54;
      if (((filterMode == false) &&
          (pGVar12 = (GLenum *)&stack0xffffff54, r_fullbright.value == 0.0)) &&
         (pGVar12 = (GLenum *)&stack0xffffff54, gl_texsort != false)) {
        pGVar12 = &local_b0;
        local_b0 = 0x1e8d66;
        R_BlendLightmaps();
      }
      if ((gl_ztrick.value == 0.0) || (gldepthmin < 0.5)) {
        *pGVar12 = 0x203;
        pGVar12[-1] = 0x1e8da5;
        (*qglDepthFunc)(*pGVar12);
      }
      else {
        *pGVar12 = 0x206;
        pGVar12[-1] = 0x1e9102;
        (*qglDepthFunc)(*pGVar12);
      }
    }
    goto LAB_001e8e47;
  }
  local_b0 = 0x1e8f94;
  R_DrawDecals(false);
  pGVar12 = (GLenum *)&stack0xffffff54;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: glpoly_t * p@[???]
                       Unresolved local var: float * v@[???]
                       Unresolved local var: int j@[???] */
  if ((((currententity->curstate).rendermode == 0) &&
      (pGVar12 = (GLenum *)&stack0xffffff54, filterMode == false)) &&
     ((pGVar12 = (GLenum *)&stack0xffffff54, r_fullbright.value == 0.0 &&
      (pGVar12 = (GLenum *)&stack0xffffff54, gl_texsort != false)))) {
    pGVar12 = &local_b0;
    local_b0 = 0x1e8fe0;
    R_BlendLightmaps();
  }
LAB_001e8e47:
  pGVar12[-1] = 0x1e8e4d;
  (*qglPopMatrix)();
  *pGVar12 = 1;
  pGVar12[-1] = 0x1e8e5a;
  (*qglDepthMask)((GLboolean)*pGVar12);
  *pGVar12 = 0xbc0;
  pGVar12[-1] = 0x1e8e67;
  (*qglDisable)(*pGVar12);
  pGVar12[1] = 0;
  *pGVar12 = 0x205;
  pGVar12[-1] = 0x1e8e7c;
  (*qglAlphaFunc)(*pGVar12,(GLclampf)pGVar12[1]);
  *pGVar12 = 0xbe2;
  pGVar12[-1] = 0x1e8e89;
  (*qglDisable)(*pGVar12);
  return;
}


// R_DrawCylinder  @ 001eec00
void R_DrawCylinder(vec_t *source,vec_t *delta,float width,float scale,float freq,float speed,
                   int segments)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  ushort in_FPUStatusWord;
  ushort uVar6;
  longdouble lVar7;
  longdouble lVar8;
  double dVar9;
  float local_60;
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
    if (0x80 < segments) {
      segments = 0x80;
    }
    local_30 = Length(delta);
    local_30 = local_30 * 0.01;
    uVar6 = in_FPUStatusWord & 0xfdff;
    fVar1 = 0.5;
    if (0.5 <= local_30) {
      fVar1 = local_30;
    }
    fVar2 = 1.0 / (float)(segments + -1);
    lVar7 = (longdouble)freq * (longdouble)speed;
    do {
      lVar7 = lVar7 - (longdouble)(unkint10)(lVar7 / (longdouble)1) * (longdouble)1;
    } while ((in_FPUStatusWord & 0x400) != 0);
    if (NAN(lVar7)) {
      dVar9 = fmod((double)((longdouble)freq * (longdouble)speed),1.0);
      lVar7 = (longdouble)dVar9;
    }
    iVar5 = 0;
    do {
      local_60 = (float)lVar7;
      fVar3 = (float)iVar5 * fVar2;
      sincos((double)((fVar3 + fVar3) * 3.1415927),&local_3c,&local_44);
      fVar3 = (float)local_44;
      fVar4 = (float)local_3c;
      local_28 = freq * fVar4 * delta[2] + *source;
      local_24 = delta[2] * fVar3 * freq + source[1];
      local_20 = width + source[2];
      (*tri.Brightness)(0.0);
      (*tri.TexCoord2f)(1.0,local_60);
      (*tri.Vertex3fv)(&local_28);
      local_28 = freq * fVar4 * (width + delta[2]) + *source;
      local_24 = fVar3 * freq * (width + delta[2]) + source[1];
      local_20 = source[2] - width;
      (*tri.Brightness)(1.0);
      (*tri.TexCoord2f)(0.0,local_60);
      (*tri.Vertex3fv)(&local_28);
      lVar8 = (longdouble)local_60 + (longdouble)(fVar1 * fVar2);
      lVar7 = lVar8;
      do {
        lVar7 = lVar7 - (longdouble)(unkint10)(lVar7 / (longdouble)1) * (longdouble)1;
      } while ((uVar6 & 0x400) != 0);
      uVar6 = uVar6 & 0xfdff;
      if (NAN(lVar7)) {
        dVar9 = fmod((double)lVar8,1.0);
        lVar7 = (longdouble)dVar9;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < segments);
  }
  return;
}


// R_DrawDecals  @ 001e77a0
void R_DrawDecals(qboolean bMultitexture)

{
  msurface_t *psurf;
  texture_t *ptexture;
  float (*v) [7];
  int iVar1;
  uint uVar2;
  uint uVar3;
  decal_s *pdecal;
  int iVar4;
  int local_30;
  int local_2c [3];
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
  (*qglBlendFunc)(0x302,0x303);
  (*qglDepthMask)('\0');
  if (gl_polyoffset.value != 0.0) {
    (*qglEnable)(0x8037);
    if ((gl_ztrick.value == 0.0) || (gldepthmin < 0.5)) {
      (*qglPolygonOffset)(-1.0,-gl_polyoffset.value);
    }
    else {
      (*qglPolygonOffset)(1.0,gl_polyoffset.value);
    }
  }
  if (0 < gDecalSurfCount) {
    local_30 = 0;
    iVar1 = gDecalSurfCount;
    do {
      psurf = gDecalSurfs[local_30];
      for (pdecal = psurf->pdecals; pdecal != (decal_t *)0x0; pdecal = pdecal->pnext) {
        while (ptexture = Draw_DecalTexture((int)pdecal->texture), (pdecal->flags & 0x40) == 0) {
          v = (float (*) [7])R_DecalVertsClip((float *)0x0,pdecal,psurf,ptexture,local_2c);
          if ((bMultitexture != false) && (local_2c[0] != 0)) {
            R_DecalVertsLight((float *)v,psurf,local_2c[0]);
          }
          if ((pdecal->flags & 0x40) != 0) break;
          if (local_2c[0] != 0) goto LAB_001e78cd;
          pdecal = pdecal->pnext;
          iVar1 = gDecalSurfCount;
          if (pdecal == (decal_s *)0x0) goto LAB_001e7950;
        }
                    /* Unresolved local var: float * vlist@[???]
                       Unresolved local var: decalcache_t * pCache@[DW_OP_reg0(EAX)]
                       Unresolved local var: int decalIndex@[???]
                       Unresolved local var: int outCount@[???] */
        uVar2 = ((int)&pdecal[-0x4ac4f].psurface >> 2) * -0x49249249;
                    /* Unresolved local var: int cacheIndex@[???] */
        uVar3 = uVar2 & 0xff;
        if (uVar2 - gDecalCache[uVar3].decalIndex == 0) {
          v = gDecalCache[uVar3].decalVert;
        }
        else {
          gDecalCache[uVar3].decalIndex = uVar2;
          v = (float (*) [7])
              R_DecalVertsClip(gDecalCache[uVar3].decalVert[0],pdecal,psurf,ptexture,local_20);
          if (bMultitexture != false) {
            R_DecalVertsLight((float *)v,psurf,4);
          }
        }
        local_2c[0] = 4;
LAB_001e78cd:
        iVar1 = local_2c[0];
        if (bMultitexture == false) {
                    /* Unresolved local var: int j@[???] */
          GL_Bind(ptexture->gl_texturenum);
          (*qglTexEnvf)(0x2300,0x2200,8448.0);
          (*qglBegin)(9);
          if (0 < iVar1) {
            iVar4 = 0;
            do {
              iVar4 = iVar4 + 1;
              (*qglTexCoord2f)((*v)[3],(*v)[4]);
              (*qglVertex3fv)(*v);
              v = v + 1;
            } while (iVar4 != iVar1);
          }
          (*qglEnd)();
        }
        else {
          R_DecalMPoly(*v,ptexture,psurf,local_2c[0]);
        }
        iVar1 = gDecalSurfCount;
      }
LAB_001e7950:
      local_30 = local_30 + 1;
    } while (local_30 < iVar1);
  }
  if (gl_polyoffset.value != 0.0) {
    (*qglDisable)(0x8037);
  }
  (*qglDisable)(0xbc0);
  (*qglDisable)(0xbe2);
  (*qglDepthMask)('\x01');
  gDecalSurfCount = 0;
  return;
}


// R_DrawDisk  @ 001eea00
void R_DrawDisk(vec_t *source,vec_t *delta,float width,float scale,float freq,float speed,
               int segments)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  ushort in_FPUStatusWord;
  ushort uVar6;
  longdouble lVar7;
  longdouble lVar8;
  double dVar9;
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
    if (0x80 < segments) {
      segments = 0x80;
    }
    local_30 = Length(delta);
    local_30 = local_30 * 0.01;
    uVar6 = in_FPUStatusWord & 0xfdff;
    fVar2 = 0.5;
    if (0.5 <= local_30) {
      fVar2 = local_30;
    }
    fVar3 = 1.0 / (float)(segments + -1);
    lVar7 = (longdouble)freq * (longdouble)speed;
    do {
      lVar7 = lVar7 - (longdouble)(unkint10)(lVar7 / (longdouble)1) * (longdouble)1;
    } while ((in_FPUStatusWord & 0x400) != 0);
    if (NAN(lVar7)) {
      dVar9 = fmod((double)((longdouble)freq * (longdouble)speed),1.0);
      lVar7 = (longdouble)dVar9;
    }
    fVar1 = delta[2];
    iVar5 = 0;
    do {
      local_60 = (float)lVar7;
      local_28 = *source;
      fVar4 = (float)iVar5 * fVar3;
      local_24 = source[1];
      local_20 = source[2];
      (*tri.Brightness)(1.0);
      (*tri.TexCoord2f)(1.0,local_60);
      (*tri.Vertex3fv)(&local_28);
      sincos((double)((fVar4 + fVar4) * 3.1415927),&local_3c,&local_44);
      local_28 = freq * fVar1 * (float)local_3c + *source;
      local_24 = (float)local_44 * freq * fVar1 + source[1];
      local_20 = source[2];
      (*tri.Brightness)(1.0);
      (*tri.TexCoord2f)(0.0,local_60);
      (*tri.Vertex3fv)(&local_28);
      lVar8 = (longdouble)local_60 + (longdouble)(fVar2 * fVar3);
      lVar7 = lVar8;
      do {
        lVar7 = lVar7 - (longdouble)(unkint10)(lVar7 / (longdouble)1) * (longdouble)1;
      } while ((uVar6 & 0x400) != 0);
      uVar6 = uVar6 & 0xfdff;
      if (NAN(lVar7)) {
        dVar9 = fmod((double)lVar8,1.0);
        lVar7 = (longdouble)dVar9;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < segments);
  }
  return;
}


// R_DrawEntitiesOnList  @ 001d3ab0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_DrawEntitiesOnList(void)

{
  modtype_t mVar1;
  int iVar2;
  cl_entity_t *pcVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
  if (r_drawentities.value == 0.0) {
    return;
  }
  if (cl_numvisedicts < 1) {
    r_blend = 1.0;
    return;
  }
  iVar7 = 0;
  iVar6 = cl_numvisedicts;
  do {
    currententity = cl_visedicts[iVar7];
    if ((currententity->curstate).rendermode == 0) {
      mVar1 = currententity->model->type;
      if (mVar1 == mod_brush) {
        R_DrawBrushModel(currententity);
        iVar6 = cl_numvisedicts;
        goto LAB_001d3aee;
      }
      if (mVar1 != mod_studio) goto LAB_001d3aee;
      if (currententity->player != false) {
        (*pStudioAPI->StudioDrawPlayer)
                  (3,(entity_state_s *)
                     ((CL_UPDATE_MASK & cl.parsecount) * 0x42b8 + 0xc7f6fc +
                     (currententity->index * 5 + -5) * 0x44));
        iVar6 = cl_numvisedicts;
        goto LAB_001d3aee;
      }
      if ((currententity->curstate).movetype != 0xc) {
        (*pStudioAPI->StudioDrawModel)(3);
        iVar6 = cl_numvisedicts;
        goto LAB_001d3aee;
      }
      if (iVar6 < 1) goto LAB_001d3aee;
      iVar4 = 0;
      iVar2 = cl_visedicts[0]->index;
      pcVar3 = cl_visedicts[0];
      while (iVar2 != (currententity->curstate).aiment) {
        iVar4 = iVar4 + 1;
        if (iVar4 == iVar6) goto LAB_001d3aee;
        pcVar3 = cl_visedicts[iVar4];
        iVar2 = pcVar3->index;
      }
      currententity = pcVar3;
      if (pcVar3->player == false) {
        (*pStudioAPI->StudioDrawModel)(0);
      }
      else {
        (*pStudioAPI->StudioDrawPlayer)
                  (0,(entity_state_s *)
                     ((CL_UPDATE_MASK & cl.parsecount) * 0x42b8 + 0xc7f6fc +
                     (pcVar3->index * 5 + -5) * 0x44));
      }
      currententity = cl_visedicts[iVar7];
      (*pStudioAPI->StudioDrawModel)(3);
      iVar6 = cl_numvisedicts;
      if (cl_numvisedicts <= iVar7 + 1) goto LAB_001d3be5;
    }
    else {
      AddTEntity((cl_entity_t_conflict *)currententity);
      iVar6 = cl_numvisedicts;
LAB_001d3aee:
      if (iVar6 <= iVar7 + 1) {
LAB_001d3be5:
        r_blend = 1.0;
        if (0 < iVar6) {
          iVar7 = 0;
          do {
            while ((currententity = cl_visedicts[iVar7], (currententity->curstate).rendermode == 0
                   && (currententity->model->type == mod_sprite))) {
              iVar6 = (currententity->curstate).body;
              if (iVar6 == 0) {
                r_entorigin[0] = currententity->origin[0];
                r_entorigin[1] = currententity->origin[1];
                r_entorigin[2] = currententity->origin[2];
              }
              else {
                    /* Unresolved local var: float * pAttachment@[???] */
                pfVar5 = R_GetAttachmentPoint((int)(currententity->curstate).skin,iVar6);
                r_entorigin[0] = *pfVar5;
                r_entorigin[1] = pfVar5[1];
                r_entorigin[2] = pfVar5[2];
              }
              iVar7 = iVar7 + 1;
              R_DrawSpriteModel(currententity);
              iVar6 = cl_numvisedicts;
              if (cl_numvisedicts <= iVar7) {
                return;
              }
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < iVar6);
        }
        return;
      }
    }
    iVar7 = iVar7 + 1;
  } while( true );
}


// R_DrawParticles  @ 001f0b40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_DrawParticles(void)

{
  ushort *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  double dVar9;
  double dVar10;
  short sVar11;
  ptype_t_conflict pVar12;
  int iVar13;
  int32 iVar14;
  particle_s *ppVar15;
  vec_t *local_bc;
  vec_t *local_b8;
  float local_9c;
  float local_98;
  float local_94;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  vec_t local_68 [3];
  vec_t local_5c [3];
  float local_50;
  float local_4c;
  float local_44;
  float local_40;
  float local_38;
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  
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
  GL_Bind(particletexture);
  (*qglEnable)(0xbc0);
  (*qglEnable)(0xbe2);
  (*qglTexEnvf)(0x2300,0x2200,8448.0);
  (*qglBlendFunc)(0x302,0x303);
  (*qglBegin)(4);
  VectorScale(vup,1.5,&local_80);
  VectorScale(vright,1.5,&local_74);
  fVar2 = (float)((longdouble)cl.time - (longdouble)cl.oldtime);
  fVar8 = fVar2 * movevars.gravity * 0.05;
  fVar6 = fVar2 * 4.0;
  R_FreeDeadParticles(&active_particles);
  if (active_particles != (particle_t *)0x0) {
                    /* Unresolved local var: word * pb@[???]
                       Unresolved local var: byte[4] rgba@[???] */
    ppVar15 = active_particles;
    do {
      while (pVar12 = ppVar15->type, pVar12 != pt_blob) {
        fVar3 = (ppVar15->org[2] - r_origin[2]) * vpn[2] +
                (ppVar15->org[1] - r_origin[1]) * vpn[1] + (ppVar15->org[0] - r_origin[0]) * vpn[0];
        fVar4 = 1.0;
        if (20.0 <= fVar3) {
          fVar4 = fVar3 * 0.004 + 1.0;
        }
        puVar1 = host_basepal + ppVar15->color * 4;
        if (filterMode == false) {
          local_2c = (float)CONCAT13(0xff,CONCAT12((char)*puVar1,
                                                   CONCAT11((char)puVar1[1],(char)puVar1[2])));
        }
        else {
          local_2c = (float)CONCAT13((char)(int)(filterBrightness * 255.0 * filterBrightness),
                                     CONCAT12((char)(int)((float)*puVar1 * filterColorBlue *
                                                         filterBrightness),
                                              CONCAT11((char)(int)((float)puVar1[1] *
                                                                   filterColorGreen *
                                                                  filterBrightness),
                                                       (char)(int)((float)puVar1[2] * filterColorRed
                                                                  * filterBrightness))));
        }
        (*qglColor3ubv)((GLubyte *)&local_2c);
        (*qglTexCoord2f)(0.0,0.0);
        (*qglVertex3fv)(ppVar15->org);
        (*qglTexCoord2f)(1.0,0.0);
        (*qglVertex3f)(local_80 * fVar4 + ppVar15->org[0],local_7c * fVar4 + ppVar15->org[1],
                       local_78 * fVar4 + ppVar15->org[2]);
        (*qglTexCoord2f)(0.0,1.0);
        (*qglVertex3f)(fVar4 * local_74 + ppVar15->org[0],local_70 * fVar4 + ppVar15->org[1],
                       local_6c * fVar4 + ppVar15->org[2]);
        pVar12 = ppVar15->type;
        if (pVar12 != pt_clientcustom) break;
LAB_001f1540:
        if (ppVar15->callback == (_func_void_particle_s_ptr_float *)0x0)
        goto switchD_001f0e90_default;
        (*ppVar15->callback)(ppVar15,fVar2);
        ppVar15 = ppVar15->next;
        if (ppVar15 == (particle_s *)0x0) goto LAB_001f0f0b;
      }
      fVar3 = ppVar15->vel[0];
      ppVar15->org[0] = ppVar15->org[0] + fVar2 * fVar3;
      fVar4 = ppVar15->vel[1];
      ppVar15->org[1] = ppVar15->org[1] + fVar2 * fVar4;
      fVar5 = ppVar15->vel[2];
      ppVar15->org[2] = ppVar15->org[2] + fVar2 * fVar5;
      switch(pVar12) {
      case pt_static:
      default:
switchD_001f0e90_default:
        ppVar15 = ppVar15->next;
        break;
      case pt_grav:
        ppVar15->vel[2] = fVar5 - fVar8 * 20.0;
        ppVar15 = ppVar15->next;
        break;
      case pt_slowgrav:
        ppVar15->vel[2] = fVar8;
        ppVar15 = ppVar15->next;
        break;
      case pt_fire:
        fVar3 = fVar2 * 5.0 + ppVar15->ramp;
        ppVar15->ramp = fVar3;
        if (fVar3 < 6.0) {
          iVar13 = ramp3[(int)fVar3];
          ppVar15->packedColor = 0;
          ppVar15->color = (short)iVar13;
        }
        else {
          ppVar15->die = -1.0;
        }
        ppVar15->vel[2] = fVar5 + fVar8;
        ppVar15 = ppVar15->next;
        break;
      case pt_explode:
        fVar7 = fVar2 * 10.0 + ppVar15->ramp;
        ppVar15->ramp = fVar7;
        if (fVar7 < 8.0) {
          iVar13 = ramp1[(int)fVar7];
          ppVar15->packedColor = 0;
          ppVar15->color = (short)iVar13;
        }
        else {
          ppVar15->die = -1.0;
        }
        ppVar15->vel[0] = fVar6 * fVar3 + fVar3;
        ppVar15->vel[1] = fVar6 * fVar4 + fVar4;
        ppVar15->vel[2] = (fVar6 * fVar5 + fVar5) - fVar8;
        ppVar15 = ppVar15->next;
        break;
      case pt_explode2:
        fVar7 = fVar2 * 15.0 + ppVar15->ramp;
        ppVar15->ramp = fVar7;
        if (fVar7 < 8.0) {
          iVar13 = ramp2[(int)fVar7];
          ppVar15->packedColor = 0;
          ppVar15->color = (short)iVar13;
        }
        else {
          ppVar15->die = -1.0;
        }
        ppVar15->vel[0] = fVar3 - fVar2 * fVar3;
        ppVar15->vel[1] = fVar4 - fVar2 * fVar4;
        ppVar15->vel[2] = (fVar5 - fVar2 * fVar5) - fVar8;
        goto switchD_001f0e90_default;
      case pt_blob:
      case pt_blob2:
        fVar7 = fVar2 * 10.0 + ppVar15->ramp;
        ppVar15->ramp = fVar7;
        if (9.0 <= fVar7) {
          ppVar15->ramp = 0.0;
          iVar13 = 0;
        }
        else {
          iVar13 = (int)fVar7;
        }
        ppVar15->color = (short)gSparkRamp[iVar13];
        ppVar15->packedColor = 0;
        ppVar15->vel[0] = fVar3 - fVar3 * 0.5 * fVar2;
        ppVar15->vel[1] = fVar4 - fVar4 * 0.5 * fVar2;
        ppVar15->vel[2] = fVar5 - fVar8 * 5.0;
        iVar14 = RandomLong(0,3);
        ppVar15->type = ~-(uint)(iVar14 == 0) + pt_blob2;
        ppVar15 = ppVar15->next;
        break;
      case pt_vox_slowgrav:
        ppVar15->vel[2] = fVar5 - fVar8 * 4.0;
        ppVar15 = ppVar15->next;
        break;
      case pt_vox_grav:
        ppVar15->vel[2] = fVar5 - fVar8 * 8.0;
        ppVar15 = ppVar15->next;
        break;
      case pt_clientcustom:
        goto LAB_001f1540;
      }
    } while (ppVar15 != (particle_s *)0x0);
  }
LAB_001f0f0b:
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
    dVar10 = cl.oldtime;
    dVar9 = cl.time;
    VectorScale(vup,1.5,local_68);
    VectorScale(vright,1.5,local_5c);
    iVar13 = (*tri.SpriteTexture)(cl_sprite_dot,0);
    if (iVar13 != 0) {
      fVar2 = (float)((longdouble)dVar9 - (longdouble)dVar10);
      fVar3 = fVar2 * movevars.gravity;
      fVar4 = r_origin[2] * vpn[2] + r_origin[1] * vpn[1] + r_origin[0] * vpn[0];
      fVar6 = 1.0 - fVar2 * 0.9;
      fVar8 = 0.0;
      if (0.0 <= fVar6) {
        fVar8 = fVar6;
      }
      (*tri.RenderMode)(5);
      (*tri.CullFace)(TRI_NONE);
      if (gpActiveTracers != (particle_t *)0x0) {
        ppVar15 = gpActiveTracers;
        do {
          fVar6 = 0.1;
          sVar11 = ppVar15->color;
          if (ppVar15->die - 0.1 <= (float)cl.time) {
            fVar6 = ppVar15->die - (float)cl.time;
          }
          fVar6 = fVar6 * ppVar15->ramp;
          local_8c = ppVar15->vel[0] * fVar6 + ppVar15->org[0];
          local_88 = ppVar15->vel[1] * fVar6 + ppVar15->org[1];
          local_84 = fVar6 * ppVar15->vel[2] + ppVar15->org[2];
          local_9c = ppVar15->org[0];
          local_98 = ppVar15->org[1];
          local_94 = ppVar15->org[2];
          iVar13 = ScreenTransform(&local_9c,&local_50);
          if ((iVar13 == 0) && (iVar13 = ScreenTransform(&local_8c,&local_44), iVar13 == 0)) {
LAB_001f118f:
            local_b8 = &local_8c;
            local_bc = &local_44;
            ScreenTransform(&local_9c,&local_50);
            ScreenTransform(local_b8,local_bc);
            local_30 = 0;
            local_38 = local_44 - local_50;
            local_34 = local_40 - local_4c;
            fVar6 = gTracerSize[ppVar15->type];
            VectorNormalize(&local_38);
            VectorScale(vup,fVar6 * local_38,(vec_t *)&local_2c);
            VectorMA((vec_t *)&local_2c,-local_34 * fVar6,vright,(vec_t *)&local_2c);
            (*tri.Begin)(2);
            (*tri.Color4ub)(gTracerColors[sVar11].r,gTracerColors[sVar11].g,gTracerColors[sVar11].b,
                            (uchar)ppVar15->packedColor);
            (*tri.Brightness)(0.0);
            (*tri.TexCoord2f)(0.0,0.0);
            (*tri.Vertex3f)(local_9c + local_2c,local_98 + local_28,local_94 + local_24);
            (*tri.Brightness)(1.0);
            (*tri.TexCoord2f)(0.0,1.0);
            (*tri.Vertex3f)(local_8c + local_2c,local_88 + local_28,local_84 + local_24);
            (*tri.Brightness)(1.0);
            (*tri.TexCoord2f)(1.0,1.0);
            (*tri.Vertex3f)(local_8c - local_2c,local_88 - local_28,local_84 - local_24);
            (*tri.Brightness)(0.0);
            (*tri.TexCoord2f)(1.0,0.0);
            (*tri.Vertex3f)(local_9c - local_2c,local_98 - local_28,local_94 - local_24);
            (*tri.End)();
          }
          else {
                    /* Unresolved local var: color24 * pColor@[???]
                       Unresolved local var: float fraction@[???]
                       Unresolved local var: float dist1@[???]
                       Unresolved local var: float dist2@[???] */
            fVar5 = (local_94 * vpn[2] + local_98 * vpn[1] + local_9c * vpn[0]) - fVar4;
            fVar6 = (vpn[2] * local_84 + vpn[1] * local_88 + vpn[0] * local_8c) - fVar4;
            if (((0.0 < fVar5) || (0.0 < fVar6)) && (fVar6 = fVar6 - fVar5, 0.01 <= fVar6)) {
              fVar6 = fVar5 / fVar6;
              fVar7 = (local_8c - local_9c) * fVar6 + local_9c;
              if (0.0 < fVar5) {
                local_88 = (local_88 - local_98) * fVar6 + local_98;
                local_84 = (local_84 - local_94) * fVar6 + local_94;
                local_8c = fVar7;
              }
              else {
                local_98 = (local_88 - local_98) * fVar6 + local_98;
                local_94 = (local_84 - local_94) * fVar6 + local_94;
                local_9c = fVar7;
              }
              ScreenTransform(&local_9c,&local_50);
              ScreenTransform(&local_8c,&local_44);
              goto LAB_001f118f;
            }
          }
          fVar6 = ppVar15->vel[0];
          pVar12 = ppVar15->type;
          ppVar15->org[0] = fVar2 * fVar6 + ppVar15->org[0];
          fVar5 = ppVar15->vel[1];
          ppVar15->org[1] = fVar2 * fVar5 + ppVar15->org[1];
          ppVar15->org[2] = fVar2 * ppVar15->vel[2] + ppVar15->org[2];
          if (pVar12 == pt_grav) {
            ppVar15->vel[2] = ppVar15->vel[2] - fVar3;
            ppVar15->vel[0] = fVar6 * fVar8;
            ppVar15->vel[1] = fVar5 * fVar8;
            fVar6 = ppVar15->die - (float)cl.time;
            sVar11 = (short)(int)((fVar6 + fVar6) * 255.0);
            ppVar15->packedColor = sVar11;
            if (0xff < sVar11) {
              ppVar15->packedColor = 0xff;
            }
          }
          else if (pVar12 == pt_slowgrav) {
            ppVar15->vel[2] = fVar3 * 0.05;
          }
          ppVar15 = ppVar15->next;
        } while (ppVar15 != (particle_s *)0x0);
      }
      (*tri.CullFace)(TRI_FRONT);
      (*tri.RenderMode)(0);
    }
  }
  R_BeamDrawList();
  (*qglDisable)(0xbe2);
  (*qglDisable)(0xbc0);
  return;
}


// R_DrawRing  @ 001ef350
void R_DrawRing(vec_t *source,vec_t *delta,float width,float amplitude,float freq,float speed,
               int segments)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  mnode_t *pmVar7;
  qboolean qVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  ushort in_FPUStatusWord;
  ushort uVar14;
  longdouble lVar15;
  float fVar16;
  float fVar17;
  double dVar18;
  double local_dc;
  float local_b0;
  float local_ac;
  double local_94;
  double local_8c;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70 [3];
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
    iVar10 = 0x400;
    if ((int)((double)segments * 3.141592653589793) < 0x401) {
      iVar10 = (int)((double)segments * 3.141592653589793);
    }
    fVar16 = Length(delta);
    local_80 = fVar16 * 0.01 * 3.1415927;
    uVar14 = in_FPUStatusWord & 0xfdff;
    fVar16 = 0.5;
    if (0.5 <= local_80) {
      fVar16 = local_80;
    }
    fVar2 = 1.0 / (float)(iVar10 + -1);
    lVar15 = (longdouble)freq * (longdouble)speed;
    do {
      lVar15 = lVar15 - (longdouble)(unkint10)(lVar15 / (longdouble)1) * (longdouble)1;
    } while ((in_FPUStatusWord & 0x400) != 0);
    local_dc = (double)lVar15;
    if (NAN(lVar15)) {
      local_dc = fmod((double)((longdouble)freq * (longdouble)speed),1.0);
    }
    fVar1 = fVar16 * amplitude * 0.125;
    VectorScale(delta,0.5,delta);
    local_34 = *delta;
    fVar3 = *source + local_34;
    local_30 = delta[1];
    fVar4 = source[1] + local_30;
    local_2c = delta[2];
    fVar5 = source[2] + local_2c;
    fVar17 = Length(&local_34);
    local_4c = fVar3 + fVar17;
    local_48 = fVar4 + fVar17;
    local_44 = fVar5 + fVar1;
    local_58 = fVar3 - fVar17;
    local_54 = fVar4 - fVar17;
    local_50 = fVar5 - fVar1;
    if (((cl.worldmodel != (model_s *)0x0) &&
        (local_7c = fVar17, local_78 = fVar17, local_74 = fVar1,
        pmVar7 = PVSNode((cl.worldmodel)->nodes,&local_58,&local_4c), pmVar7 != (mnode_t *)0x0)) &&
       (qVar8 = R_CullBox(&local_58,&local_4c), qVar8 == false)) {
      local_24 = -local_34;
      local_20 = 0.0;
      local_28 = local_30;
      VectorNormalize(&local_28);
      VectorScale(&local_28,fVar17,&local_28);
      if (-1 < iVar10) {
        local_dc._0_4_ = (float)local_dc;
        iVar12 = 0;
        iVar11 = 0;
        iVar13 = iVar10 >> 3;
        do {
          fVar17 = (float)iVar12 * fVar2;
          sincos((double)((fVar17 + fVar17) * 3.1415927),&local_8c,&local_94);
          uVar9 = iVar11 >> 0x10 & 0x7f;
          fVar6 = (float)local_8c;
          local_80 = (float)local_94;
          local_64 = local_28 * local_80 + local_34 * fVar6 + fVar3;
          local_60 = local_24 * local_80 + local_30 * fVar6 + fVar4;
          local_5c = local_80 * local_20 + fVar6 * local_2c + fVar5;
          VectorMA(&local_64,fVar1 * gNoise[uVar9],vup,&local_64);
          dVar18 = cos((double)(fVar17 * 3.1415927 * 3.0 * 8.0 + freq));
          VectorMA(&local_64,fVar1 * gNoise[uVar9] * (float)dVar18,vright,&local_64);
          ScreenTransform(&local_64,&local_58);
          if (iVar12 != 0) {
            local_4c = local_58 - local_ac;
            local_44 = 0.0;
            local_48 = local_54 - local_b0;
            VectorNormalize(&local_4c);
            VectorScale(vup,local_4c,local_40);
            VectorMA(local_40,-local_48,vright,local_40);
            VectorMA(&local_64,width,local_40,&local_7c);
            VectorMA(&local_64,-width,local_40,local_70);
            local_dc._0_4_ = local_dc._0_4_ + fVar2 * fVar16 * 0.125;
            (*tri.TexCoord2f)(1.0,local_dc._0_4_);
            (*tri.Vertex3fv)(local_70);
            (*tri.TexCoord2f)(0.0,local_dc._0_4_);
            (*tri.Vertex3fv)(&local_7c);
          }
          local_ac = local_58;
          local_b0 = local_54;
          lVar15 = (longdouble)local_dc._0_4_;
          do {
            lVar15 = lVar15 - (longdouble)(unkint10)(lVar15 / (longdouble)1) * (longdouble)1;
          } while ((uVar14 & 0x400) != 0);
          uVar14 = uVar14 & 0xfdff;
          if (NAN(lVar15)) {
            dVar18 = fmod((double)local_dc._0_4_,1.0);
            lVar15 = (longdouble)dVar18;
          }
          local_dc._0_4_ = (float)lVar15;
          iVar11 = iVar11 + (int)(fVar2 * 128.0 * 65536.0) * 8;
          iVar13 = iVar13 + -1;
          if ((iVar13 == 0) && (uVar14 = uVar14 & 0xfdff, amplitude != 0.0)) {
            Noise(gNoise,0x80);
            iVar13 = iVar10 >> 3;
          }
          iVar12 = iVar12 + 1;
        } while (iVar12 <= iVar10);
      }
    }
  }
  return;
}


// R_DrawSegs  @ 001edf90
void R_DrawSegs(vec_t *source,vec_t *delta,float width,float scale,float freq,float speed,
               int segments,int flags)

{
  float scale_00;
  float fVar1;
  float scale_01;
  uint uVar2;
  int iVar3;
  int iVar4;
  ushort in_FPUStatusWord;
  ushort uVar5;
  longdouble lVar6;
  float fVar7;
  double dVar8;
  float local_e0;
  float local_d4;
  int local_cc;
  float local_c8;
  int local_c0;
  float local_a4;
  double local_94;
  double local_8c [3];
  vec_t local_70 [3];
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
    local_c0 = segments;
    if (0x80 < segments) {
      local_c0 = 0x80;
    }
    fVar7 = Length(delta);
    uVar5 = in_FPUStatusWord & 0xfdff;
    local_a4 = 0.5;
    if (0.5 <= fVar7 * 0.01) {
      local_a4 = fVar7 * 0.01;
    }
    scale_00 = 1.0 / (float)(local_c0 + -1);
    fVar7 = local_a4 * scale_00;
    lVar6 = (longdouble)freq * (longdouble)speed;
    do {
      lVar6 = lVar6 - (longdouble)(unkint10)(lVar6 / (longdouble)1) * (longdouble)1;
    } while ((in_FPUStatusWord & 0x400) != 0);
    if (NAN(lVar6)) {
      dVar8 = fmod((double)((longdouble)freq * (longdouble)speed),1.0);
      lVar6 = (longdouble)dVar8;
    }
    uVar2 = flags & 0x10;
    if (uVar2 == 0) {
      local_c8 = scale * local_a4;
    }
    else {
      if (local_c0 < 0x10) {
        local_c0 = 0x10;
        local_a4 = 1.6;
      }
      else {
        local_a4 = (float)local_c0 * 0.1;
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
    local_d4 = 1.0;
    local_cc = 0;
    if (uVar2 == 0) {
      local_cc = iVar3;
    }
    if ((flags & 0x40U) != 0) {
      local_d4 = 0.0;
    }
    iVar4 = 1;
    do {
      local_e0 = (float)lVar6;
      scale_01 = (float)iVar4 * scale_00;
      (*tri.Brightness)(local_d4);
      (*tri.TexCoord2f)(0.0,local_e0);
      (*tri.Vertex3fv)(local_70);
      (*tri.Brightness)(local_d4);
      (*tri.TexCoord2f)(1.0,local_e0);
      (*tri.Vertex3fv)(local_64);
      fVar1 = scale_01;
      if (((flags & 0x40U) == 0) && (fVar1 = local_d4, (flags & 0x80U) != 0)) {
        fVar1 = 1.0 - scale_01;
      }
      local_d4 = fVar1;
      VectorMA(source,scale_01,delta,local_58);
      uVar5 = uVar5 & 0xfdff;
      if (local_c8 != 0.0) {
        fVar1 = local_c8 * gNoise[local_cc >> 0x10];
        if (uVar2 == 0) {
          VectorMA(local_58,fVar1,vup,local_58);
          dVar8 = cos((double)scale_01 * 3.141592653589793 * 3.0 + (double)freq);
          VectorMA(local_58,local_c8 * gNoise[local_cc >> 0x10] * (float)dVar8,vright,local_58);
        }
        else {
          sincos((double)scale_01 * 3.141592653589793 * (double)local_a4 + (double)freq,local_8c,
                 &local_94);
          dVar8 = local_94;
          VectorMA(local_58,(float)local_8c[0] * fVar1,vup,local_58);
          VectorMA(local_58,fVar1 * (float)dVar8,vright,local_58);
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
      local_e0 = local_e0 + fVar7;
      (*tri.Brightness)(local_d4);
      (*tri.TexCoord2f)(1.0,local_e0);
      (*tri.Vertex3fv)(local_64);
      (*tri.Brightness)(local_d4);
      (*tri.TexCoord2f)(0.0,local_e0);
      (*tri.Vertex3fv)(local_70);
      local_40 = local_4c;
      lVar6 = (longdouble)local_e0;
      local_3c = local_48;
      local_38 = local_44;
      do {
        lVar6 = lVar6 - (longdouble)(unkint10)(lVar6 / (longdouble)1) * (longdouble)1;
      } while ((uVar5 & 0x400) != 0);
      uVar5 = uVar5 & 0xfdff;
      if (NAN(lVar6)) {
        dVar8 = fmod((double)local_e0,1.0);
        lVar6 = (longdouble)dVar8;
      }
      iVar4 = iVar4 + 1;
      local_cc = local_cc + iVar3;
    } while (iVar4 < local_c0);
  }
  return;
}


// R_DrawSequentialPoly  @ 001e7b10
void R_DrawSequentialPoly(msurface_t *s,int face)

{
  float fVar1;
  glpoly_t *pgVar2;
  longdouble lVar3;
  float fVar4;
  texture_t *ptVar5;
  _func_void_GLenum *UNRECOVERED_JUMPTABLE;
  int iVar6;
  float (*pafVar7) [7];
  float (*pafVar8) [7];
  int iVar9;
  ushort in_FPUStatusWord;
  longdouble lVar10;
  double dVar11;
  
                    /* Unresolved local var: glpoly_t * p@[???]
                       Unresolved local var: float * v@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: texture_t * t@[???]
                       Unresolved local var: glRect_t * theRect@[???]
                       Unresolved local var: int renderDetailTexture@[???] */
  if ((currententity->curstate).rendermode == 1) {
    if (mtexenabled != false) {
      (*qglDisable)(0xde1);
      GL_SelectTexture(TEXTURE0_SGIS);
      mtexenabled = false;
    }
    (*qglBlendFunc)(0x302,0x303);
    (*qglEnable)(0xbe2);
    ptVar5 = R_TextureAnimation(s);
    GL_Bind(ptVar5->gl_texturenum);
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
  if ((s->flags & 0x94U) != 0) {
    if ((s->flags & 0x10U) == 0) {
      return;
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
  if (filterMode == false) {
    R_RenderDynamicLightmaps(s);
  }
  if ((gl_mtexable == 0) ||
     ((iVar9 = (currententity->curstate).rendermode, iVar9 != 4 && (iVar9 != 0)))) {
    pgVar2 = s->polys;
    ptVar5 = R_TextureAnimation(s);
    if (mtexenabled != false) {
      (*qglDisable)(0xde1);
      GL_SelectTexture(TEXTURE0_SGIS);
      mtexenabled = false;
    }
    GL_Bind(ptVar5->gl_texturenum);
    if ((s->flags & 0x20) == 0) {
      (*qglBegin)(9);
      if (0 < pgVar2->numverts) {
        iVar9 = 0;
        pafVar7 = pgVar2->verts;
        do {
          iVar9 = iVar9 + 1;
          (*qglTexCoord2f)((*pafVar7)[3],(*pafVar7)[4]);
          (*qglVertex3fv)(*pafVar7);
          pafVar7 = pafVar7 + 1;
        } while (iVar9 < pgVar2->numverts);
      }
      (*qglEnd)();
    }
    else {
      DrawGLPolyScroll(s,currententity);
    }
    if ((gl_texsort == false) && (s->pdecals != (decal_t *)0x0)) {
      gDecalSurfs[gDecalSurfCount] = s;
      gDecalSurfCount = gDecalSurfCount + 1;
      if (500 < gDecalSurfCount) {
        Sys_Error("Too many decal surfaces!\n");
      }
      R_DrawDecals(false);
    }
    if (gl_wireframe.value != 0.0) {
      (*qglDisable)(0xde1);
      (*qglColor3f)(1.0,1.0,1.0);
      if (gl_wireframe.value == 2.0) {
        (*qglDisable)(0xb71);
      }
      (*qglBegin)(2);
      if (0 < pgVar2->numverts) {
        iVar9 = 0;
        pafVar7 = pgVar2->verts;
        do {
          iVar9 = iVar9 + 1;
          (*qglVertex3fv)(*pafVar7);
          pafVar7 = pafVar7 + 1;
        } while (iVar9 < pgVar2->numverts);
      }
      (*qglEnd)();
      (*qglEnable)(0xde1);
      if (gl_wireframe.value == 2.0) {
        (*qglEnable)(0xb71);
      }
    }
    if ((currententity->curstate).rendermode != 0) {
      return;
    }
    if (filterMode == false) {
      GL_Bind(lightmap_textures[s->lightmaptexturenum]);
    }
    else {
      GL_Bind(gl_FilterTexture);
    }
    (*qglEnable)(0xbe2);
    (*qglBegin)(9);
    if (0 < pgVar2->numverts) {
      iVar9 = 0;
      pafVar7 = pgVar2->verts;
      do {
        iVar9 = iVar9 + 1;
        (*qglTexCoord2f)((*pafVar7)[5],(*pafVar7)[6]);
        (*qglVertex3fv)(*pafVar7);
        pafVar7 = pafVar7 + 1;
      } while (iVar9 < pgVar2->numverts);
    }
    (*qglEnd)();
    s = (msurface_t *)0xbe2;
    UNRECOVERED_JUMPTABLE = qglDisable;
    goto LAB_001e7cb9;
  }
  pgVar2 = s->polys;
  ptVar5 = R_TextureAnimation(s);
  GL_SelectTexture(TEXTURE0_SGIS);
  GL_Bind(ptVar5->gl_texturenum);
  (*qglTexEnvf)(0x2300,0x2200,8448.0);
  if ((currententity->curstate).rendermode == 1) {
    (*qglDisable)(0xde1);
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
  iVar9 = s->lightmaptexturenum;
  if (lightmap_modified[iVar9] != false) {
    lightmap_modified[iVar9] = false;
    (*qglTexSubImage2D)(0xde1,0,0,lightmap_rectchange[iVar9].t,0x80,lightmap_rectchange[iVar9].h,
                        gl_lightmap_format,0x1401,
                        lightmaps +
                        (iVar9 * 0x80 + lightmap_rectchange[iVar9].t) * 0x80 * lightmap_bytes);
    lightmap_rectchange[iVar9].l = 0x80;
    lightmap_rectchange[iVar9].t = 0x80;
    lightmap_rectchange[iVar9].h = 0;
    lightmap_rectchange[iVar9].w = 0;
  }
  (*qglTexEnvf)(0x2300,0x2200,8448.0);
  pafVar7 = pgVar2->verts;
  iVar9 = DT_SetRenderState(ptVar5->gl_texturenum);
  (*qglBegin)(9);
  if ((s->flags & 0x20) == 0) {
    if (pgVar2->numverts < 1) {
LAB_001e8540:
      (*qglEnd)();
      if (iVar9 == 0) goto LAB_001e7eaa;
    }
    else {
                    /* Unresolved local var: float sOffset@[DW_OP_breg4(ESP): +60] */
      iVar6 = 0;
      pafVar8 = pafVar7;
      if (iVar9 == 0) {
        do {
          (*qglMTexCoord2fSGIS)(TEXTURE0_SGIS,(*pafVar8)[3],(*pafVar8)[4]);
          (*qglMTexCoord2fSGIS)(TEXTURE1_SGIS,(*pafVar8)[5],(*pafVar8)[6]);
          (*qglVertex3fv)(*pafVar8);
          iVar6 = iVar6 + 1;
          pafVar8 = pafVar8 + 1;
        } while (iVar6 < pgVar2->numverts);
        goto LAB_001e7ea4;
      }
      do {
        (*qglMTexCoord2fSGIS)(TEXTURE0_SGIS,(*pafVar8)[3],(*pafVar8)[4]);
        (*qglMTexCoord2fSGIS)(TEXTURE1_SGIS,(*pafVar8)[5],(*pafVar8)[6]);
        DT_SetTextureCoordinates((*pafVar8)[3],(*pafVar8)[4]);
        (*qglVertex3fv)(*pafVar8);
        iVar6 = iVar6 + 1;
        pafVar8 = pafVar8 + 1;
      } while (iVar6 < pgVar2->numverts);
LAB_001e8226:
      (*qglEnd)();
    }
    DT_ClearRenderState();
  }
  else {
                    /* Unresolved local var: float speed@[???]
                       Unresolved local var: float sOffset@[???] */
    fVar1 = (float)CONCAT11((currententity->curstate).rendercolor.g,
                            (currententity->curstate).rendercolor.b) * 0.0625;
    fVar4 = -fVar1;
    if ((currententity->curstate).rendercolor.r != '\0') {
      fVar4 = fVar1;
    }
    fVar1 = (1.0 / (float)s->texinfo->texture->width) * fVar4 * (float)cl.time;
    lVar10 = (longdouble)fVar1;
    lVar3 = (longdouble)1;
    if (lVar10 < (longdouble)0) {
      do {
        lVar10 = lVar10 - (longdouble)(unkint10)(lVar10 / -lVar3) * -lVar3;
      } while ((in_FPUStatusWord & 0x400) != 0);
      if (NAN(lVar10)) {
        dVar11 = fmod((double)fVar1,-1.0);
        lVar10 = (longdouble)dVar11;
      }
    }
    else {
      do {
        lVar10 = lVar10 - (longdouble)(unkint10)(lVar10 / lVar3) * lVar3;
      } while ((in_FPUStatusWord & 0x400) != 0);
      if (NAN(lVar10)) {
        dVar11 = fmod((double)fVar1,1.0);
        lVar10 = (longdouble)dVar11;
      }
    }
    fVar1 = (float)lVar10;
    if (pgVar2->numverts < 1) goto LAB_001e8540;
    iVar6 = 0;
    pafVar8 = pafVar7;
    if (iVar9 != 0) {
      do {
        (*qglMTexCoord2fSGIS)(TEXTURE0_SGIS,fVar1 + (*pafVar8)[3],(*pafVar8)[4]);
        (*qglMTexCoord2fSGIS)(TEXTURE1_SGIS,(*pafVar8)[5],(*pafVar8)[6]);
        DT_SetTextureCoordinates(fVar1 + (*pafVar8)[3],(*pafVar8)[4]);
        (*qglVertex3fv)(*pafVar8);
        iVar6 = iVar6 + 1;
        pafVar8 = pafVar8 + 1;
      } while (iVar6 < pgVar2->numverts);
      goto LAB_001e8226;
    }
    do {
      (*qglMTexCoord2fSGIS)(TEXTURE0_SGIS,fVar1 + (*pafVar8)[3],(*pafVar8)[4]);
      (*qglMTexCoord2fSGIS)(TEXTURE1_SGIS,(*pafVar8)[5],(*pafVar8)[6]);
      (*qglVertex3fv)(*pafVar8);
      iVar6 = iVar6 + 1;
      pafVar8 = pafVar8 + 1;
    } while (iVar6 < pgVar2->numverts);
LAB_001e7ea4:
    (*qglEnd)();
  }
LAB_001e7eaa:
  if ((gl_texsort == false) && (s->pdecals != (decal_t *)0x0)) {
    gDecalSurfs[gDecalSurfCount] = s;
    gDecalSurfCount = gDecalSurfCount + 1;
    if (500 < gDecalSurfCount) {
      Sys_Error("Too many decal surfaces!\n");
    }
    if ((currententity->curstate).rendermode == 0) {
      R_DrawDecals(true);
    }
  }
  if (gl_wireframe.value != 0.0) {
    (*qglDisable)(0xde1);
    (*qglColor3f)(1.0,1.0,1.0);
    if (gl_wireframe.value == 2.0) {
      (*qglDisable)(0xb71);
    }
    (*qglBegin)(2);
    if (0 < pgVar2->numverts) {
      iVar9 = 0;
      do {
        iVar9 = iVar9 + 1;
        (*qglVertex3fv)(*pafVar7);
        pafVar7 = pafVar7 + 1;
      } while (iVar9 < pgVar2->numverts);
    }
    (*qglEnd)();
    (*qglEnable)(0xde1);
    if (gl_wireframe.value == 2.0) {
      s = (msurface_t *)0xb71;
      UNRECOVERED_JUMPTABLE = qglEnable;
LAB_001e7cb9:
                    /* WARNING: Could not recover jumptable at 0x001e7cc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)((GLenum)s);
      return;
    }
  }
  return;
}


// R_DrawSkyBox  @ 001e2180
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_DrawSkyBox(void)

{
  bool bVar1;
  GLboolean GVar2;
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
  bVar1 = false;
  if (g_bFogSkybox == 0) {
    bVar1 = false;
    GVar2 = (*qglIsEnabled)(0xb60);
    if (GVar2 == '\x01') {
      bVar1 = true;
      (*qglDisable)(0xb60);
    }
  }
  if (((skymins[0][0] < skymaxs[0][0]) && (skymins[1][0] < skymaxs[1][0])) &&
     (-0.29289323 <= vpn[2] * 0.0 + vpn[1] * 0.0 + vpn[0])) {
    GL_Bind(gSkyTexNumber[skytexorder[0]]);
    (*qglColor3f)(local_14,local_10,local_18);
    (*qglBegin)(7);
    MakeSkyVec(skymins[0][0],skymins[1][0],0);
    MakeSkyVec(skymins[0][0],skymaxs[1][0],0);
    MakeSkyVec(skymaxs[0][0],skymaxs[1][0],0);
    MakeSkyVec(skymaxs[0][0],skymins[1][0],0);
    (*qglEnd)();
  }
  if (((skymins[0][1] < skymaxs[0][1]) && (skymins[1][1] < skymaxs[1][1])) &&
     (-0.29289323 <= vpn[2] * 0.0 + (vpn[1] * 0.0 - vpn[0]))) {
    GL_Bind(gSkyTexNumber[skytexorder[1]]);
    (*qglColor3f)(local_14,local_10,local_18);
    (*qglBegin)(7);
    MakeSkyVec(skymins[0][1],skymins[1][1],1);
    MakeSkyVec(skymins[0][1],skymaxs[1][1],1);
    MakeSkyVec(skymaxs[0][1],skymaxs[1][1],1);
    MakeSkyVec(skymaxs[0][1],skymins[1][1],1);
    (*qglEnd)();
  }
  if (((skymins[0][2] < skymaxs[0][2]) && (skymins[1][2] < skymaxs[1][2])) &&
     (-0.29289323 <= vpn[2] * 0.0 + vpn[0] * 0.0 + vpn[1])) {
    GL_Bind(gSkyTexNumber[skytexorder[2]]);
    (*qglColor3f)(local_14,local_10,local_18);
    (*qglBegin)(7);
    MakeSkyVec(skymins[0][2],skymins[1][2],2);
    MakeSkyVec(skymins[0][2],skymaxs[1][2],2);
    MakeSkyVec(skymaxs[0][2],skymaxs[1][2],2);
    MakeSkyVec(skymaxs[0][2],skymins[1][2],2);
    (*qglEnd)();
  }
  if (((skymins[0][3] < skymaxs[0][3]) && (skymins[1][3] < skymaxs[1][3])) &&
     (-0.29289323 <= vpn[2] * 0.0 + (vpn[0] * 0.0 - vpn[1]))) {
    GL_Bind(gSkyTexNumber[skytexorder[3]]);
    (*qglColor3f)(local_14,local_10,local_18);
    (*qglBegin)(7);
    MakeSkyVec(skymins[0][3],skymins[1][3],3);
    MakeSkyVec(skymins[0][3],skymaxs[1][3],3);
    MakeSkyVec(skymaxs[0][3],skymaxs[1][3],3);
    MakeSkyVec(skymaxs[0][3],skymins[1][3],3);
    (*qglEnd)();
  }
  if (((skymins[0][4] < skymaxs[0][4]) && (skymins[1][4] < skymaxs[1][4])) &&
     (-0.29289323 <= vpn[1] * 0.0 + vpn[0] * 0.0 + vpn[2])) {
    GL_Bind(gSkyTexNumber[skytexorder[4]]);
    (*qglColor3f)(local_14,local_10,local_18);
    (*qglBegin)(7);
    MakeSkyVec(skymins[0][4],skymins[1][4],4);
    MakeSkyVec(skymins[0][4],skymaxs[1][4],4);
    MakeSkyVec(skymaxs[0][4],skymaxs[1][4],4);
    MakeSkyVec(skymaxs[0][4],skymins[1][4],4);
    (*qglEnd)();
  }
  if (((skymins[0][5] < skymaxs[0][5]) && (skymins[1][5] < skymaxs[1][5])) &&
     (-0.29289323 <= (vpn[1] * 0.0 + vpn[0] * 0.0) - vpn[2])) {
    GL_Bind(gSkyTexNumber[skytexorder[5]]);
    (*qglColor3f)(local_14,local_10,local_18);
    (*qglBegin)(7);
    MakeSkyVec(skymins[0][5],skymins[1][5],5);
    MakeSkyVec(skymins[0][5],skymaxs[1][5],5);
    MakeSkyVec(skymaxs[0][5],skymaxs[1][5],5);
    MakeSkyVec(skymaxs[0][5],skymins[1][5],5);
    (*qglEnd)();
  }
  if (bVar1) {
    (*qglEnable)(0xb60);
  }
  return;
}


// R_DrawSkyChain  @ 001e28c0
void R_DrawSkyChain(msurface_t *s)

{
  glpoly_t *pgVar1;
  float (*pafVar2) [7];
  int iVar3;
  vec_t *pvVar4;
  int iVar5;
  glpoly_t *pgVar6;
  vec_t local_31c [195];
  
                    /* Unresolved local var: msurface_t * fa@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec_t[64][3] verts@[???]
                       Unresolved local var: glpoly_t * p@[???] */
  iVar3 = CL_IsDevOverviewMode();
  if (iVar3 == 0) {
    c_sky = 0;
    if (s != (msurface_t *)0x0) {
      do {
        for (pgVar1 = s->polys; pgVar1 != (glpoly_t *)0x0; pgVar1 = pgVar1->next) {
          iVar3 = pgVar1->numverts;
          if (0 < iVar3) {
            iVar5 = 0;
            pvVar4 = local_31c;
            pgVar6 = pgVar1;
            do {
              iVar5 = iVar5 + 1;
              *pvVar4 = pgVar6->verts[0][0] - r_origin[0];
              pvVar4[1] = pgVar6->verts[0][1] - r_origin[1];
              pafVar2 = pgVar6->verts;
              pgVar6 = (glpoly_t *)(pgVar6->verts[0] + 3);
              pvVar4[2] = (*pafVar2)[2] - r_origin[2];
              pvVar4 = pvVar4 + 3;
              iVar3 = pgVar1->numverts;
            } while (iVar5 < iVar3);
          }
          ClipSkyPolygon(iVar3,local_31c,0);
        }
        s = s->texturechain;
      } while (s != (msurface_s *)0x0);
    }
    R_DrawSkyBox();
  }
  return;
}


// R_DrawSpriteModel  @ 001d2c70
void R_DrawSpriteModel(cl_entity_t *e)

{
  float fVar1;
  msprite_t *pSprite;
  int iVar2;
  float fVar3;
  mspriteframe_t *pmVar4;
  GLubyte GVar5;
  colorVec local_5c;
  vec_t local_4c [3];
  vec_t local_40 [3];
  vec_t local_34 [3];
  vec_t local_28 [6];
  
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
  fVar3 = 1.0;
  if (0.0 < fVar1) {
    fVar3 = fVar1;
  }
  if ((e->curstate).rendermode == 0) {
    r_blend = 1.0;
  }
  R_SpriteColor(&local_5c,e,(int)(r_blend * 255.0));
  iVar2 = (e->curstate).rendermode;
  if ((gl_spriteblend.value == 0.0) && (iVar2 == 0)) {
    (*qglTexEnvf)(0x2300,0x2200,8448.0);
    (*qglColor4ub)((GLubyte)local_5c.r,(GLubyte)local_5c.g,(GLubyte)local_5c.b,0xff);
    (*qglDisable)(0xbe2);
    goto LAB_001d2dbf;
  }
  if (iVar2 == 1) {
    (*qglBlendFunc)(0x302,0x303);
    (*qglTexEnvi)(0x2300,0x2200,0x1906);
LAB_001d2d75:
    (*qglColor4ub)((GLubyte)local_5c.r,(GLubyte)local_5c.g,(GLubyte)local_5c.b,
                   (GLubyte)(int)(r_blend * 255.0));
  }
  else {
    if (iVar2 == 5) {
      (*qglTexEnvf)(0x2300,0x2200,8448.0);
      (*qglBlendFunc)(1,1);
      GVar5 = 0xff;
    }
    else {
      if (iVar2 == 3) {
        (*qglTexEnvf)(0x2300,0x2200,8448.0);
        (*qglBlendFunc)(1,1);
        (*qglColor4ub)((GLubyte)local_5c.r,(GLubyte)local_5c.g,(GLubyte)local_5c.b,0xff);
        (*qglDisable)(0xb71);
        (*qglDepthMask)('\0');
        goto LAB_001d2db2;
      }
      if (iVar2 != 4) {
        (*qglTexEnvf)(0x2300,0x2200,8448.0);
        (*qglBlendFunc)(0x302,0x303);
        goto LAB_001d2d75;
      }
      (*qglTexEnvf)(0x2300,0x2200,8448.0);
      (*qglBlendFunc)(0x302,0x303);
      GVar5 = (GLubyte)(int)(r_blend * 255.0);
    }
    (*qglColor4ub)((GLubyte)local_5c.r,(GLubyte)local_5c.g,(GLubyte)local_5c.b,GVar5);
    (*qglDepthMask)('\0');
  }
LAB_001d2db2:
  (*qglEnable)(0xbe2);
LAB_001d2dbf:
  R_GetSpriteAxes(e,(int)pSprite->type,local_40,local_34,local_28);
  GL_DisableMultitexture();
  GL_Bind(pmVar4->gl_texturenum);
  (*qglEnable)(0xbc0);
  (*qglBegin)(7);
  (*qglTexCoord2f)(0.0,1.0);
  VectorMA(r_entorigin,fVar3 * pmVar4->down,local_28,local_4c);
  VectorMA(local_4c,fVar3 * pmVar4->left,local_34,local_4c);
  (*qglVertex3fv)(local_4c);
  (*qglTexCoord2f)(0.0,0.0);
  VectorMA(r_entorigin,fVar3 * pmVar4->up,local_28,local_4c);
  VectorMA(local_4c,fVar3 * pmVar4->left,local_34,local_4c);
  (*qglVertex3fv)(local_4c);
  (*qglTexCoord2f)(1.0,0.0);
  VectorMA(r_entorigin,fVar3 * pmVar4->up,local_28,local_4c);
  VectorMA(local_4c,fVar3 * pmVar4->right,local_34,local_4c);
  (*qglVertex3fv)(local_4c);
  (*qglTexCoord2f)(1.0,1.0);
  VectorMA(r_entorigin,fVar3 * pmVar4->down,local_28,local_4c);
  VectorMA(local_4c,fVar3 * pmVar4->right,local_34,local_4c);
  (*qglVertex3fv)(local_4c);
  (*qglEnd)();
  (*qglDisable)(0xbc0);
  (*qglDepthMask)('\x01');
  if (((e->curstate).rendermode == 0) && (gl_spriteblend.value == 0.0)) {
    return;
  }
  (*qglTexEnvf)(0x2300,0x2200,7681.0);
  (*qglDisable)(0xbe2);
  (*qglEnable)(0xb71);
  return;
}


// R_DrawTEntitiesOnList  @ 00210a30
void R_DrawTEntitiesOnList(qboolean clientOnly)

{
  modtype_t mVar1;
  cl_entity_t *pcVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  float fVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
  if (r_drawentities.value != 0.0) {
    if ((clientOnly == false) && (0 < numTransObjs)) {
      iVar6 = 0;
LAB_00210a70:
      (*qglDisable)(0xb60);
      currententity = (cl_entity_t *)transObjects[iVar6].pEnt;
      iVar3 = CL_FxBlend(currententity);
      r_blend = (float)iVar3;
      if (0.0 < r_blend) {
        r_blend = r_blend * 0.003921569;
        if ((currententity->curstate).rendermode == 3) {
          if (currententity->model->type != mod_sprite) {
            Con_DPrintf("Non-sprite set to glow!\n");
            mVar1 = currententity->model->type;
            goto joined_r0x00210bfb;
          }
        }
        else {
          mVar1 = currententity->model->type;
joined_r0x00210bfb:
          if (mVar1 != mod_sprite) {
            if (mVar1 == mod_brush) {
              if (((g_bUserFogOn != 0) && (iVar3 = (currententity->curstate).rendermode, iVar3 != 3)
                  ) && (iVar3 != 5)) {
                (*qglEnable)(0xb60);
              }
              R_DrawBrushModel(currententity);
            }
            else if (mVar1 == mod_alias) {
              R_DrawAliasModel(currententity);
            }
            else if ((mVar1 == mod_studio) && ((currententity->curstate).renderamt != 0)) {
              if (currententity->player == false) {
                if ((currententity->curstate).movetype != 0xc) {
                  (*pStudioAPI->StudioDrawModel)(3);
                  goto LAB_00210b32;
                }
                if (numTransObjs < 1) goto LAB_00210b3b;
                iVar4 = 0;
                pcVar2 = (cl_entity_t *)transObjects->pEnt;
                iVar3 = pcVar2->index;
                while (iVar3 != (currententity->curstate).aiment) {
                  iVar4 = iVar4 + 1;
                  if (iVar4 == numTransObjs) goto LAB_00210b32;
                  pcVar2 = (cl_entity_t *)transObjects[iVar4].pEnt;
                  iVar3 = pcVar2->index;
                }
                currententity = pcVar2;
                if (pcVar2->player == false) {
                  (*pStudioAPI->StudioDrawModel)(0);
                }
                else {
                  (*pStudioAPI->StudioDrawPlayer)
                            (0,(entity_state_s *)
                               ((CL_UPDATE_MASK & cl.parsecount) * 0x42b8 + 0xc7f6fc +
                               (pcVar2->index * 5 + -5) * 0x44));
                }
                currententity = (cl_entity_t *)transObjects[iVar6].pEnt;
                (*pStudioAPI->StudioDrawModel)(3);
              }
              else {
                (*pStudioAPI->StudioDrawPlayer)
                          (3,(entity_state_s *)
                             ((CL_UPDATE_MASK & cl.parsecount) * 0x42b8 + 0xc7f6fc +
                             (currententity->index * 5 + -5) * 0x44));
              }
            }
            goto LAB_00210b32;
          }
        }
        iVar3 = (currententity->curstate).body;
        if (iVar3 == 0) {
          r_entorigin[0] = currententity->origin[0];
          r_entorigin[1] = currententity->origin[1];
          r_entorigin[2] = currententity->origin[2];
        }
        else {
                    /* Unresolved local var: float * pAttachment@[???] */
          pfVar5 = R_GetAttachmentPoint((int)(currententity->curstate).skin,iVar3);
          r_entorigin[0] = *pfVar5;
          r_entorigin[1] = pfVar5[1];
          r_entorigin[2] = pfVar5[2];
        }
        if ((currententity->curstate).rendermode == 3) {
          fVar7 = GlowBlend((cl_entity_t_conflict *)currententity);
          r_blend = fVar7 * r_blend;
        }
        if (r_blend != 0.0) {
          R_DrawSpriteModel(currententity);
        }
      }
LAB_00210b32:
      iVar6 = iVar6 + 1;
      if (numTransObjs <= iVar6) goto LAB_00210b3b;
      goto LAB_00210a70;
    }
LAB_00210b3b:
    GL_DisableMultitexture();
    (*qglEnable)(0xbc0);
    (*qglTexEnvf)(0x2300,0x2200,8448.0);
    if (g_bUserFogOn == 0) {
      ClientDLL_DrawTransparentTriangles();
    }
    else {
      (*qglDisable)(0xb60);
      ClientDLL_DrawTransparentTriangles();
    }
    if (g_bUserFogOn != 0) {
      (*qglEnable)(0xb60);
    }
    numTransObjs = 0;
    r_blend = 1.0;
  }
  return;
}


// R_DrawTorus  @ 001ee620
void R_DrawTorus(vec_t *source,vec_t *delta,float width,float scale,float freq,float speed,
                int segments)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  ushort in_FPUStatusWord;
  ushort uVar6;
  longdouble lVar7;
  double dVar8;
  float local_b0;
  float local_a4;
  float local_a0;
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
    if (0x80 < segments) {
      segments = 0x80;
    }
    local_70 = Length(delta);
    local_70 = local_70 * 0.01;
    uVar6 = in_FPUStatusWord & 0xfdff;
    fVar1 = 0.5;
    if (0.5 <= local_70) {
      fVar1 = local_70;
    }
    fVar2 = 1.0 / (float)(segments + -1);
    lVar7 = (longdouble)freq * (longdouble)speed;
    do {
      lVar7 = lVar7 - (longdouble)(unkint10)(lVar7 / (longdouble)1) * (longdouble)1;
    } while ((in_FPUStatusWord & 0x400) != 0);
    if (NAN(lVar7)) {
      dVar8 = fmod((double)((longdouble)freq * (longdouble)speed),1.0);
      lVar7 = (longdouble)dVar8;
    }
    iVar4 = 0;
    iVar5 = 0;
    do {
      local_b0 = (float)lVar7;
      fVar3 = (float)iVar5 * fVar2;
      sincos((double)((fVar3 + fVar3) * 3.1415927),&local_7c,&local_84);
      local_4c = freq * (float)local_7c * delta[2] + *source;
      local_48 = (float)local_84 * freq * delta[2] + source[1];
      local_44 = source[2];
      VectorMA(&local_4c,fVar1 * scale * gNoise[iVar4 >> 0x10],vup,&local_4c);
      dVar8 = cos((double)(fVar3 * 3.1415927 * 3.0 + freq));
      VectorMA(&local_4c,fVar1 * scale * gNoise[iVar4 >> 0x10] * (float)dVar8,vright,&local_4c);
      ScreenTransform(&local_4c,&local_40);
      if (iVar5 != 0) {
        local_34 = local_40 - local_a4;
        local_2c = 0;
        local_30 = local_3c - local_a0;
        VectorNormalize(&local_34);
        VectorScale(vup,local_34,local_28);
        VectorMA(local_28,-local_30,vright,local_28);
        VectorMA(&local_4c,width,local_28,local_64);
        VectorMA(&local_4c,-width,local_28,local_58);
        local_b0 = local_b0 + fVar2 * fVar1;
        (*tri.TexCoord2f)(1.0,local_b0);
        (*tri.Vertex3fv)(local_58);
        (*tri.TexCoord2f)(0.0,local_b0);
        (*tri.Vertex3fv)(local_64);
      }
      local_a4 = local_40;
      local_a0 = local_3c;
      lVar7 = (longdouble)local_b0;
      do {
        lVar7 = lVar7 - (longdouble)(unkint10)(lVar7 / (longdouble)1) * (longdouble)1;
      } while ((uVar6 & 0x400) != 0);
      uVar6 = uVar6 & 0xfdff;
      if (NAN(lVar7)) {
        dVar8 = fmod((double)local_b0,1.0);
        lVar7 = (longdouble)dVar8;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + (int)(fVar2 * 128.0 * 65536.0);
    } while (iVar5 <= segments);
  }
  return;
}


// R_DrawViewModel  @ 001d3d60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_DrawViewModel(void)

{
  float fVar1;
  modtype_t mVar2;
  cl_entity_t *pcVar3;
  int iVar4;
  uint uVar5;
  float fVar6;
  colorVec local_3c;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_18;
  float local_14;
  float fStack_10;
  
                    /* Unresolved local var: float[3] lightvec@[???]
                       Unresolved local var: colorVec c@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int lnum@[???]
                       Unresolved local var: vec3_t dist@[???]
                       Unresolved local var: float add@[???]
                       Unresolved local var: float oldShadows@[???]
                       Unresolved local var: dlight_t * dl@[???] */
  local_28 = 0;
  local_2c = -1.0;
  currententity = &cl.viewent;
  local_24 = local_28;
  if (((((r_drawviewmodel.value == 0.0) || (iVar4 = ClientDLL_IsThirdPerson(), iVar4 != 0)) ||
       (chase_active.value != 0.0)) || ((envmap != false || (r_drawentities.value == 0.0)))) ||
     ((cl.stats[0] < 1 ||
      ((currententity->model == (model_s *)0x0 || (cl.maxclients < cl.viewentity)))))) {
    R_LightPoint(&local_3c,currententity->origin);
    cl.light_level = (local_3c.r + local_3c.b + local_3c.g) / 3;
  }
  else {
    (*qglDepthRange)((double)gldepthmin,(double)((gldepthmax - gldepthmin) * 0.3 + gldepthmin));
    pcVar3 = currententity;
    iVar4 = cl.weaponsequence;
    mVar2 = currententity->model->type;
    if (mVar2 == mod_alias) {
      R_LightPoint(&local_3c,currententity->origin);
      r_viewlighting.ambientlight = (local_3c.b + local_3c.r + local_3c.g) / 3;
      if ((uint)r_viewlighting.ambientlight < 0x18) {
        r_viewlighting.ambientlight = 0x18;
      }
      iVar4 = 0;
      r_viewlighting.shadelight = r_viewlighting.ambientlight;
      do {
        fVar1 = cl_dlights[iVar4].radius;
        if ((fVar1 != 0.0) && ((float)cl.time <= cl_dlights[iVar4].die)) {
          local_18 = currententity->origin[0] - cl_dlights[iVar4].origin[0];
          local_14 = currententity->origin[1] - cl_dlights[iVar4].origin[1];
          fStack_10 = currententity->origin[2] - cl_dlights[iVar4].origin[2];
          fVar6 = Length(&local_18);
          fVar1 = fVar1 - fVar6;
          if (0.0 < fVar1) {
            r_viewlighting.ambientlight = (int)((float)r_viewlighting.ambientlight + fVar1);
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != 0x20);
      if (0x80 < r_viewlighting.ambientlight) {
        r_viewlighting.ambientlight = 0x80;
      }
      if (0xc0 < r_viewlighting.shadelight + r_viewlighting.ambientlight) {
        r_viewlighting.shadelight = 0xc0 - r_viewlighting.ambientlight;
      }
      r_viewlighting.plightvec = &local_2c;
      R_DrawAliasModel(currententity);
    }
    else if (mVar2 == mod_studio) {
      if (cl.weaponstarttime == 0.0) {
        cl.weaponstarttime = (float)cl.time;
      }
      (currententity->curstate).frame = 0.0;
      (pcVar3->curstate).framerate = 1.0;
      (pcVar3->curstate).sequence = iVar4;
      (pcVar3->curstate).animtime = cl.weaponstarttime;
      uVar5 = (uint)(byte)cl.players[cl.playernum].topcolor;
      (pcVar3->curstate).colormap = uVar5;
      (pcVar3->curstate).colormap = (cl.players[cl.playernum].bottomcolor & 0xffU) << 8 | uVar5;
      R_LightPoint(&local_3c,pcVar3->origin);
      fVar1 = r_shadows.value;
      r_shadows.value = 0.0;
      cl.light_level = (local_3c.b + local_3c.g + local_3c.r) / 3;
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


// R_DrawWaterChain  @ 001e4150
void R_DrawWaterChain(msurface_t *pChain)

{
                    /* Unresolved local var: msurface_t * s@[???] */
  if (pChain != (msurface_t *)0x0) {
    (*qglColor4ub)(0xff,0xff,0xff,0xff);
    do {
      GL_Bind(pChain->texinfo->texture->gl_texturenum);
      EmitWaterPolys(pChain,0);
      pChain = pChain->texturechain;
    } while (pChain != (msurface_s *)0x0);
  }
  return;
}


// R_DrawWorld  @ 001e8810
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_DrawWorld(void)

{
  int iVar1;
  cl_entity_t local_bc4;
  
                    /* Unresolved local var: cl_entity_t ent@[???] */
  Q_memset(&local_bc4,0,3000);
  local_bc4.model = cl.worldmodel;
  modelorg[0] = r_refdef.vieworg[0];
  modelorg[1] = r_refdef.vieworg[1];
  modelorg[2] = r_refdef.vieworg[2];
  currenttexture = -1;
  local_bc4.curstate.rendercolor.r = (byte)gWaterColor.r;
  local_bc4.curstate.rendercolor.g = (byte)gWaterColor.g;
  local_bc4.curstate.rendercolor.b = (byte)gWaterColor.b;
  currententity = &local_bc4;
  (*qglColor3f)(1.0,1.0,1.0);
  Q_memset(lightmap_polys,0,0x100);
  R_ClearSkyBox();
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
  R_RecursiveWorldNode((cl.worldmodel)->nodes);
  gDecalSurfCount = 0;
  DrawTextureChains();
  S_ExtraUpdate();
  iVar1 = CL_IsDevOverviewMode();
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: glpoly_t * p@[???]
                       Unresolved local var: float * v@[???]
                       Unresolved local var: int j@[???] */
  if ((((iVar1 == 0) && (R_DrawDecals(false), filterMode == false)) && (r_fullbright.value == 0.0))
     && (gl_texsort != false)) {
    R_BlendLightmaps();
  }
  return;
}


// R_EntityParticles  @ 001e9e90
void R_EntityParticles(cl_entity_s *ent)

{
  particle_s **pppVar1;
  int iVar2;
  particle_t *ppVar3;
  particle_t *ppVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float fVar8;
  float local_24;
  float local_20 [4];
  
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
    iVar7 = 0;
    do {
      fVar8 = RandomFloat(0.0,2.55);
      avelocities[0][iVar7] = fVar8;
      iVar7 = iVar7 + 1;
    } while (iVar7 != 0x1e6);
  }
  iVar7 = 0;
  do {
    fVar8 = (float)cl.time;
    sincosf(fVar8 * *(float *)((int)avelocities[0] + iVar7),local_20,&local_24);
    fVar6 = local_20[0];
    fVar5 = local_24;
    sincosf(fVar8 * *(float *)((int)avelocities[0] + iVar7 + 4),local_20,&local_24);
    ppVar4 = free_particles;
    ppVar3 = active_particles;
    if (free_particles == (particle_t *)0x0) {
      return;
    }
    active_particles = free_particles;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar3;
    ppVar4->die = (float)((longdouble)0.01 + (longdouble)cl.time);
    ppVar4->color = 0x6f;
    ppVar4->packedColor = 0;
    ppVar4->type = pt_explode;
    ppVar4->org[0] =
         fVar5 * local_24 * beamlength +
         *(float *)((int)r_avertexnormals[0] + iVar7) * 64.0 + ent->origin[0];
    fVar8 = beamlength;
    ppVar4->org[1] =
         local_24 * fVar6 * beamlength +
         *(float *)((int)r_avertexnormals[0] + iVar7 + 4) * 64.0 + ent->origin[1];
    iVar2 = iVar7 + 8;
    iVar7 = iVar7 + 0xc;
    ppVar4->org[2] =
         (*(float *)((int)r_avertexnormals[0] + iVar2) * 64.0 + ent->origin[2]) -
         local_20[0] * fVar8;
  } while (iVar7 != 0x798);
  return;
}


// R_Envmap_f  @ 00209b20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_Envmap_f(void)

{
  char local_460 [1024];
  char local_60 [64];
  undefined1 local_20 [20];
  
                    /* Unresolved local var: char[1024] name@[???]
                       Unresolved local var: vrect_t saveVrect@[???]
                       Unresolved local var: char[64] base@[???] */
  if (cl.worldmodel == (model_s *)0x0) {
    Con_Printf("No map loaded\n");
  }
  else {
    if (gl_envmapsize.value <= 0.0) {
      Con_Printf("Invalid gl_envmapsize value\n");
      return;
    }
    if ((cl.num_entities == 0) || (cl_entities->model == (model_s *)0x0)) {
      Q_strcpy(local_60,"Env");
    }
    else {
      COM_FileBase(cl_entities->model->name,local_60);
    }
    (*qglDrawBuffer)(0x404);
    (*qglReadBuffer)(0x404);
    envmap = true;
    Q_memcpy(local_20,&r_refdef,0x14);
    r_refdef.vrect.y = 0;
    r_refdef.vrect.width = (int)gl_envmapsize.value;
    r_refdef.vrect.x = 0;
    r_refdef.viewangles[0] = 0.0;
    r_refdef.viewangles[1] = 0.0;
    r_refdef.viewangles[2] = 0.0;
    r_refdef.vrect.height = r_refdef.vrect.width;
    GL_BeginRendering(&glx,&gly,&glwidth,&SCR_CalcRefdef::h);
    R_RenderView();
    snprintf(local_460,0x400,"%srt.bmp",local_60);
    VID_TakeSnapshotRect(local_460,0,0,(int)gl_envmapsize.value,(int)gl_envmapsize.value);
    r_refdef.viewangles[1] = 90.0;
    GL_BeginRendering(&glx,&gly,&glwidth,&SCR_CalcRefdef::h);
    R_RenderView();
    snprintf(local_460,0x400,"%sbk.bmp",local_60);
    VID_TakeSnapshotRect(local_460,0,0,(int)gl_envmapsize.value,(int)gl_envmapsize.value);
    r_refdef.viewangles[1] = 180.0;
    GL_BeginRendering(&glx,&gly,&glwidth,&SCR_CalcRefdef::h);
    R_RenderView();
    snprintf(local_460,0x400,"%slf.bmp",local_60);
    VID_TakeSnapshotRect(local_460,0,0,(int)gl_envmapsize.value,(int)gl_envmapsize.value);
    r_refdef.viewangles[1] = 270.0;
    GL_BeginRendering(&glx,&gly,&glwidth,&SCR_CalcRefdef::h);
    R_RenderView();
    snprintf(local_460,0x400,"%sft.bmp",local_60);
    VID_TakeSnapshotRect(local_460,0,0,(int)gl_envmapsize.value,(int)gl_envmapsize.value);
    r_refdef.viewangles[0] = -90.0;
    r_refdef.viewangles[1] = 0.0;
    GL_BeginRendering(&glx,&gly,&glwidth,&SCR_CalcRefdef::h);
    R_RenderView();
    snprintf(local_460,0x400,"%sup.bmp",local_60);
    VID_TakeSnapshotRect(local_460,0,0,(int)gl_envmapsize.value,(int)gl_envmapsize.value);
    r_refdef.viewangles[0] = 90.0;
    r_refdef.viewangles[1] = 0.0;
    GL_BeginRendering(&glx,&gly,&glwidth,&SCR_CalcRefdef::h);
    R_RenderView();
    snprintf(local_460,0x400,"%sdn.bmp",local_60);
    VID_TakeSnapshotRect(local_460,0,0,(int)gl_envmapsize.value,(int)gl_envmapsize.value);
    Q_memcpy(&r_refdef,local_20,0x14);
    envmap = false;
    (*qglDrawBuffer)(0x405);
    (*qglReadBuffer)(0x405);
    GL_EndRendering();
  }
  return;
}


// R_Explosion  @ 001ab5a0
void R_Explosion(float *pos,int model,float scale,float framerate,int flags)

{
  vec_t vVar1;
  _func_void_TEMPENTITY_ptr_float_int *p_Var2;
  int32 iVar3;
  TEMPENTITY *pTVar4;
  dlight_t_conflict *pdVar5;
  
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
      (pdVar5->color).r = 0xfa;
      pdVar5->origin[2] = vVar1;
      (pdVar5->color).b = 0x96;
      pdVar5->die = (float)((longdouble)0.01 + (longdouble)cl.time);
      pdVar5->decay = 800.0;
      pdVar5 = (*efx.CL_AllocDlight)(0);
      pdVar5->origin[0] = *pos;
      pdVar5->origin[1] = pos[1];
      vVar1 = pos[2];
      pdVar5->radius = 150.0;
      (pdVar5->color).r = 0xff;
      (pdVar5->color).g = 0xbe;
      pdVar5->origin[2] = vVar1;
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


// R_FireCustomDecal  @ 001e6640
void R_FireCustomDecal(int textureIndex,int entity,int modelIndex,vec_t *position,int flags,
                      float scale)

{
  texture_t *ptVar1;
  uint uVar2;
  mnode_t *node;
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
  pcVar3 = cl_entities + entity;
  gDecalPos[0] = *position;
  gDecalPos[1] = position[1];
  gDecalPos[2] = position[2];
  if (pcVar3 == (cl_entity_t *)0x0) {
    gDecalModel = (model_t *)0x0;
  }
  else {
    gDecalModel = pcVar3->model;
    if ((modelIndex != 0) && (gDecalModel == (model_s *)0x0)) {
      gDecalModel = CL_GetModelByIndex(modelIndex);
    }
    if ((((gDecalModel != (model_s *)0x0) ||
         ((sv.active != false &&
          (gDecalModel = sv.models[sv.edicts[entity].v.modelindex], gDecalModel != (model_s *)0x0)))
         ) && (ptVar1 != (texture_t *)0x0)) && (gDecalModel->type == mod_brush)) {
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
          gDecalPos[2] = gDecalPos[2] * local_20 + gDecalPos[1] * local_24 + local_28 * gDecalPos[0]
          ;
          gDecalPos[0] = local_38 + local_3c * gDecalPos[1] + local_40 * gDecalPos[0];
          gDecalPos[1] = -(local_2c + local_30 * gDecalPos[1] + local_34);
        }
      }
      gDecalIndex = textureIndex;
      gDecalFlags = flags;
      if ((flags & 4U) == 0) {
        gDecalFlags = flags | 0x20;
      }
      uVar2 = ptVar1->height >> 1;
      gDecalEntity = entity;
      gDecalSize = ptVar1->width >> 1;
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


// R_FireField  @ 001a5f20
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
  float local_2c;
  float local_28;
  float local_24;
  
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
    iVar5 = 0;
    flLow = (float)-radius;
    do {
      while( true ) {
        fVar6 = *org;
        local_2c = RandomFloat(flLow,flHigh);
        local_2c = local_2c + fVar6;
        fVar6 = org[1];
        local_28 = RandomFloat(flLow,flHigh);
        local_28 = local_28 + fVar6;
        if ((flags & 0x10U) == 0) {
          fVar6 = org[2];
          local_24 = RandomFloat(flLow,flHigh);
          local_24 = local_24 + fVar6;
        }
        else {
          local_24 = org[2];
        }
        pTVar3 = (*efx.CL_TempEntAlloc)(&local_2c,model);
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
        if (iVar5 == count) {
          return;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != count);
  }
  return;
}


// R_FizzEffect  @ 001a4350
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
  if ((modelIndex != 0) && (pent->model != (model_s *)0x0)) {
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


// R_FlickerParticles  @ 001eb020
void R_FlickerParticles(vec_t *org)

{
  particle_s **pppVar1;
  particle_t *ppVar2;
  particle_t *ppVar3;
  int iVar4;
  float fVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: particle_t * p@[???] */
  iVar4 = 0xf;
  do {
    ppVar3 = free_particles;
    ppVar2 = active_particles;
    if (free_particles == (particle_t *)0x0) {
      return;
    }
    active_particles = free_particles;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar2;
    ppVar3->org[0] = *org;
    fVar5 = RandomFloat(-32.0,32.0);
    ppVar3->vel[0] = fVar5;
    ppVar3->org[1] = org[1];
    fVar5 = RandomFloat(-32.0,32.0);
    ppVar3->vel[1] = fVar5;
    ppVar3->org[2] = org[2];
    fVar5 = RandomFloat(-32.0,32.0);
    ppVar3->vel[2] = fVar5;
    fVar5 = RandomFloat(80.0,143.0);
    iVar4 = iVar4 + -1;
    ppVar3->vel[2] = fVar5;
    ppVar3->die = (float)cl.time + 2.0;
    ppVar3->ramp = 0.0;
    ppVar3->color = 0xfe;
    ppVar3->packedColor = 0;
    ppVar3->type = pt_blob2;
  } while (iVar4 != 0);
  return;
}


// R_FlushStudioCache  @ 0013db80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_FlushStudioCache(void)

{
  Q_memset(rgStudioCache,0,0x440);
  nCurrentHull = 0;
  r_cachecurrent = 0;
  nCurrentPlane = 0;
  return;
}


// R_FogParams  @ 0020fe20
void R_FogParams(float flDensity,int iFogSkybox)

{
  flFogDensity = flDensity;
  g_bFogSkybox = iFogSkybox;
  return;
}


// R_ForceCVars  @ 001d1e10
/* WARNING: Type propagation algorithm not settling */

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
  if (gl_polyoffset.value <= 0.0) {
    if (gl_polyoffset.value < -0.001) {
      Cvar_DirectSet(&gl_polyoffset,"-0.001");
    }
  }
  else if (gl_polyoffset.value < 0.001) {
    Cvar_DirectSet(&gl_polyoffset,"0.001");
  }
  else if (25.0 < gl_polyoffset.value) {
    Cvar_DirectSet(&gl_polyoffset,"25");
  }
  if ((sv_cheats.value == 0.0) && (r_drawentities.value != 1.0)) {
    Cvar_DirectSet(&r_drawentities,"1.0");
  }
  if (v_lightgamma.value < 1.8) {
    Cvar_DirectSet(&v_lightgamma,"1.8");
    GL_BuildLightmaps();
    D_FlushCaches();
    return;
  }
  return;
}


// R_ForceCVars  @ 001d49a0
void R_ForceCVars(qboolean mp)

{
  if (mp != false) {
    R_ForceCVars(mp);
    return;
  }
  return;
}


// R_FreeDeadParticles  @ 001ea0c0
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
      ppVar3->next = ppVar2->next;
      ppVar2->next = free_particles;
      free_particles = ppVar2;
      ppVar2 = ppVar3->next;
      if (ppVar2 == (particle_s *)0x0) {
        return;
      }
      fVar1 = (float)cl.time;
    } while (ppVar2->die < fVar1);
  } while( true );
}


// R_FunnelSprite  @ 001a6550
void R_FunnelSprite(float *org,int modelIndex,int reverse)

{
  float fVar1;
  model_t *model;
  int iVar2;
  TEMPENTITY *pTVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
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
      iVar4 = -0x100;
      iVar2 = ModelFrameCount(model);
      do {
        iVar5 = -0x100;
        do {
          pTVar3 = (*efx.CL_TempEntAlloc)(org,model);
          if (pTVar3 == (TEMPENTITY *)0x0) {
            return;
          }
          if (reverse == 0) {
            (pTVar3->entity).origin[0] = (float)iVar4 + *org;
            (pTVar3->entity).origin[1] = (float)iVar5 + org[1];
            fVar6 = org[2];
            fVar8 = RandomFloat(100.0,800.0);
            fVar8 = fVar8 + fVar6;
            (pTVar3->entity).origin[2] = fVar8;
            local_28 = *org - (pTVar3->entity).origin[0];
            local_24 = org[1] - (pTVar3->entity).origin[1];
            local_20 = org[2] - fVar8;
          }
          else {
            (pTVar3->entity).origin[0] = *org;
            (pTVar3->entity).origin[1] = org[1];
            (pTVar3->entity).origin[2] = org[2];
            fVar6 = *org;
            fVar7 = org[1];
            fVar1 = org[2];
            fVar8 = RandomFloat(100.0,800.0);
            fVar8 = fVar8 + fVar1;
            local_28 = ((float)iVar4 + fVar6) - (pTVar3->entity).origin[0];
            local_24 = ((float)iVar5 + fVar7) - (pTVar3->entity).origin[1];
            local_20 = fVar8 - (pTVar3->entity).origin[2];
          }
          fVar8 = fVar8 * 0.125;
          (pTVar3->entity).curstate.rendermode = 3;
          (pTVar3->entity).curstate.renderfx = 0xe;
          (pTVar3->entity).curstate.renderamt = 200;
          (pTVar3->entity).baseline.renderamt = 200;
          (pTVar3->entity).curstate.framerate = 10.0;
          pTVar3->frameMax = (float)iVar2;
          fVar6 = RandomFloat(0.1,0.4);
          pTVar3->flags = 0x84;
          (pTVar3->entity).curstate.framerate = fVar6;
          fVar6 = VectorNormalize(&local_28);
          if (fVar8 < 64.0) {
            fVar8 = 64.0;
          }
          iVar5 = iVar5 + 0x40;
          fVar7 = RandomFloat(64.0,128.0);
          VectorScale(&local_28,fVar8 + fVar7,(pTVar3->entity).baseline.origin);
          pTVar3->fadeSpeed = 2.0;
          pTVar3->die = (fVar6 / (fVar8 + fVar7) - 0.5) + (float)cl.time;
        } while (iVar5 != 0x140);
        iVar4 = iVar4 + 0x40;
      } while (iVar4 != 0x140);
      return;
    }
    Con_Printf("No model %d!\n",modelIndex);
  }
  return;
}


// R_GLStudioDrawPoints  @ 00143660
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_GLStudioDrawPoints(void)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  studiohdr_t *psVar6;
  studiohdr_t *psVar7;
  float fVar8;
  studiohdr_t *ptexturehdr;
  int iVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  vec3_t *pavVar14;
  auxvert_t *paVar15;
  char *pcVar16;
  uint uVar17;
  float (*light) [3] [4];
  char *pcVar18;
  studiohdr_t *psVar19;
  int iVar20;
  float local_68;
  float local_64;
  int local_60;
  int local_5c;
  int local_58;
  char *local_54;
  GLfloat local_3c;
  GLfloat local_38;
  GLfloat local_34;
  float local_2c;
  float local_28;
  undefined4 local_24;
  float local_20 [4];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: uchar * pvertbone@[???]
                       Unresolved local var: uchar * pnormbone@[???]
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
  psVar6 = pstudiohdr;
  iVar12 = psubmodel->vertinfoindex;
  iVar20 = psubmodel->norminfoindex;
  ptexturehdr = R_LoadTextures(r_model);
  psVar7 = pstudiohdr;
  iVar3 = ptexturehdr->textureindex;
  iVar11 = psubmodel->vertindex;
  pcVar13 = pstudiohdr->name;
  pcVar10 = pstudiohdr->name + psubmodel->meshindex + -8;
  iVar4 = psubmodel->normindex;
  local_54 = ptexturehdr->name + ptexturehdr->skinindex + -8;
  iVar9 = (int)(currententity->curstate).skin;
  if ((iVar9 == 0) || (ptexturehdr->numskinfamilies <= iVar9)) {
    if ((currententity->curstate).renderfx == 0x13) goto LAB_0014413f;
LAB_00143705:
    if (psubmodel->numverts < 1) goto LAB_00143786;
    iVar9 = 0;
    paVar15 = pauxverts;
    pcVar13 = pcVar13 + iVar11 + -8;
    do {
      iVar11 = iVar9 + iVar12;
      iVar9 = iVar9 + 1;
      R_StudioTransformAuxVert(paVar15,(uint)(byte)psVar6->name[iVar11 + -8],(vec_t *)pcVar13);
      iVar11 = psubmodel->numverts;
      paVar15 = paVar15 + 1;
      psVar19 = psVar7;
      pcVar13 = pcVar13 + 0xc;
    } while (iVar9 < iVar11);
  }
  else {
    local_54 = local_54 + iVar9 * ptexturehdr->numskinref * 2;
    if ((currententity->curstate).renderfx != 0x13) goto LAB_00143705;
LAB_0014413f:
    BuildNormalIndexTable();
    BuildGlowShellVerts((vec3_t *)(pcVar13 + iVar11 + -8),pauxverts);
    iVar11 = psubmodel->numverts;
    psVar19 = pstudiohdr;
  }
  if (0 < iVar11) {
    pcVar16 = psVar19->name + psubmodel->vertinfoindex + -8;
    iVar12 = 0;
    light = lightpos;
    pcVar13 = psVar19->name + psubmodel->vertindex + -8;
    do {
      iVar12 = iVar12 + 1;
      bVar1 = *pcVar16;
      pcVar16 = pcVar16 + 1;
      R_LightStrength((uint)bVar1,(float *)pcVar13,*light);
      light = light + 1;
      pcVar13 = pcVar13 + 0xc;
    } while (iVar12 < psubmodel->numverts);
  }
LAB_00143786:
  local_68 = (float)psubmodel->nummesh;
  if (0 < (int)local_68) {
    local_60 = 0;
    pcVar13 = psVar7->name + iVar4 + -8;
    pcVar16 = psVar6->name + iVar20 + -8;
    pavVar14 = pvlightvalues;
    do {
      uVar17 = g_ForcedFaceFlags |
               *(uint *)(ptexturehdr->name +
                        *(short *)(local_54 + *(int *)(pcVar10 + 8) * 2) * 0x50 + iVar3 + 0x38);
      if (2.0 <= r_fullbright.value) {
        uVar17 = uVar17 & 0xfffffffc;
      }
      if ((currententity->curstate).rendermode == 5) {
                    /* Unresolved local var: int idx@[???] */
        if ((0 < *(int *)(pcVar10 + 0xc)) &&
           (iVar12 = ((int)pavVar14 - (int)pvlightvalues >> 2) * -0x55555555,
           iVar12 < pvlightvalues_size)) {
          if ((uVar17 & 2) == 0) {
            iVar12 = 0;
            do {
              fVar8 = r_blend;
              iVar12 = iVar12 + 1;
              (*pavVar14)[2] = r_blend;
              (*pavVar14)[1] = fVar8;
              (*pavVar14)[0] = fVar8;
              pavVar14 = pavVar14 + 1;
              if (*(int *)(pcVar10 + 0xc) <= iVar12) break;
            } while (((int)pavVar14 - (int)pvlightvalues >> 2) * -0x55555555 < pvlightvalues_size);
          }
          else {
            iVar20 = 0;
            do {
              fVar8 = r_blend;
              iVar20 = iVar20 + 1;
              (*pavVar14)[2] = r_blend;
              (*pavVar14)[1] = fVar8;
              (*pavVar14)[0] = fVar8;
              pavVar14 = pavVar14 + 1;
              R_StudioChrome(chrome[iVar12],(uint)(byte)*pcVar16,(vec_t *)pcVar13);
              if (*(int *)(pcVar10 + 0xc) <= iVar20) break;
              iVar12 = ((int)pavVar14 - (int)pvlightvalues >> 2) * -0x55555555;
            } while (iVar12 < pvlightvalues_size);
          }
          goto LAB_001438c1;
        }
      }
      else {
                    /* Unresolved local var: int k@[???]
                       Unresolved local var: int idx@[???] */
        if ((0 < *(int *)(pcVar10 + 0xc)) &&
           (iVar12 = ((int)pavVar14 - (int)pvlightvalues >> 2) * -0x55555555,
           iVar12 < pvlightvalues_size)) {
          if ((uVar17 & 2) == 0) {
            iVar12 = 0;
            pcVar18 = pcVar13;
            do {
              iVar12 = iVar12 + 1;
              pcVar13 = pcVar18 + 0xc;
              bVar1 = *pcVar16;
              pcVar16 = pcVar16 + 1;
              R_StudioLighting(local_20,(uint)bVar1,uVar17,(vec_t *)pcVar18);
              (*pavVar14)[0] = r_colormix[0] * local_20[0];
              (*pavVar14)[1] = r_colormix[1] * local_20[0];
              (*pavVar14)[2] = local_20[0] * r_colormix[2];
              pavVar14 = pavVar14 + 1;
              if (*(int *)(pcVar10 + 0xc) <= iVar12) break;
              pcVar18 = pcVar13;
            } while (((int)pavVar14 - (int)pvlightvalues >> 2) * -0x55555555 < pvlightvalues_size);
          }
          else {
            iVar20 = 0;
            pcVar18 = pcVar13;
            do {
              iVar20 = iVar20 + 1;
              R_StudioLighting(local_20,(uint)(byte)*pcVar16,uVar17,(vec_t *)pcVar18);
              pcVar13 = pcVar18 + 0xc;
              bVar1 = *pcVar16;
              pcVar16 = pcVar16 + 1;
              R_StudioChrome(chrome[iVar12],(uint)bVar1,(vec_t *)pcVar18);
              (*pavVar14)[0] = r_colormix[0] * local_20[0];
              (*pavVar14)[1] = r_colormix[1] * local_20[0];
              (*pavVar14)[2] = local_20[0] * r_colormix[2];
              pavVar14 = pavVar14 + 1;
              if (*(int *)(pcVar10 + 0xc) <= iVar20) break;
              iVar12 = ((int)pavVar14 - (int)pvlightvalues >> 2) * -0x55555555;
              pcVar18 = pcVar13;
            } while (iVar12 < pvlightvalues_size);
          }
LAB_001438c1:
          local_68 = (float)psubmodel->nummesh;
        }
      }
      local_60 = local_60 + 1;
      pcVar10 = pcVar10 + 0x14;
    } while (local_60 < (int)local_68);
  }
  (*qglCullFace)(0x404);
  bVar5 = false;
  if (((cl_righthand != (cvar_t *)0x0) && (0.0 < cl_righthand->value)) &&
     (cl.viewent.index == currententity->index)) {
    (*qglDisable)(0xb44);
    bVar5 = true;
  }
  psVar6 = pstudiohdr;
  iVar12 = psubmodel->normindex;
  if (0 < psubmodel->nummesh) {
    local_58 = 0;
    local_5c = 0;
    do {
                    /* Unresolved local var: float s@[???]
                       Unresolved local var: float t@[???]
                       Unresolved local var: short * ptricmds@[???] */
      pcVar10 = pstudiohdr->name + local_58 + psubmodel->meshindex + -8;
      c_alias_polys = c_alias_polys + *(int *)pcVar10;
      pcVar13 = pstudiohdr->name + *(int *)(pcVar10 + 4) + -8;
      uVar17 = g_ForcedFaceFlags |
               *(uint *)(ptexturehdr->name +
                        *(short *)(local_54 + *(int *)(pcVar10 + 8) * 2) * 0x50 + iVar3 + 0x38);
      if (2.0 <= r_fullbright.value) {
        uVar17 = uVar17 & 0xfffffffc;
      }
      if ((uVar17 & 0x40) != 0) {
        (*qglEnable)(0xbc0);
        (*qglAlphaFunc)(0x204,0.5);
        (*qglDepthMask)('\x01');
      }
      if (((uVar17 & 0x20) != 0) && ((currententity->curstate).rendermode == 0)) {
        (*qglBlendFunc)(1,1);
        (*qglEnable)(0xbe2);
        (*qglDepthMask)('\0');
        (*qglShadeModel)(0x1d01);
      }
      if (2.0 <= r_fullbright.value) {
        (*tri.SpriteTexture)(cl_sprite_white,0);
        local_68 = 0.00390625;
        local_64 = 0.00390625;
      }
      else {
        iVar20 = *(short *)(local_54 + *(int *)(pcVar10 + 8) * 2) * 0x50 + iVar3;
                    /* Unresolved local var: mstudiotexture_t * ptexture@[???]
                       Unresolved local var: float temp@[???] */
        local_64 = 1.0 / (float)*(int *)(ptexturehdr->name + iVar20 + 0x3c);
        local_68 = 1.0 / (float)*(int *)((int)ptexturehdr->eyeposition + iVar20 + -4);
        if ((g_ForcedFaceFlags & 2U) == 0) {
          R_StudioSetupSkin(ptexturehdr,(int)*(short *)(local_54 + *(int *)(pcVar10 + 8) * 2));
        }
      }
      if ((uVar17 & 2) == 0) {
        sVar2 = *(short *)pcVar13;
        while (iVar20 = (int)sVar2, iVar20 != 0) {
          pcVar10 = pcVar13 + 2;
          if (iVar20 < 0) {
            iVar20 = -iVar20;
            (*qglBegin)(6);
LAB_00143a5d:
            pcVar16 = pcVar10;
            if (*(short *)(pcVar13 + 4) < pvlightvalues_size) {
              do {
                (*qglTexCoord2f)((float)*(short *)(pcVar16 + 4) * local_64,
                                 (float)*(short *)(pcVar16 + 6) * local_68);
                iVar11 = *(short *)(pcVar16 + 2) * 0xc;
                pavVar14 = pvlightvalues + *(short *)(pcVar16 + 2);
                if (bVar5) {
                    /* Unresolved local var: vec3_t vNormal@[???] */
                  local_2c = *(float *)(psVar6->name + iVar11 + iVar12 + -8);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float adjr@[???]
                       Unresolved local var: float adjg@[???]
                       Unresolved local var: float adjb@[???]
                       Unresolved local var: float c@[???] */
                  local_28 = -*(float *)(psVar6->name + *(short *)(pcVar16 + 2) * 0xc + iVar12 + -4)
                  ;
                  local_24 = *(undefined4 *)(psVar6->name + *(short *)(pcVar16 + 2) * 0xc + iVar12);
                  if (numlights == 0) goto LAB_00143b3f;
                  R_LightLambert(lightpos[*(short *)pcVar16],&local_2c,*pavVar14,&local_3c);
                }
                else if (numlights == 0) {
LAB_00143b3f:
                  local_3c = (*pavVar14)[0];
                  local_38 = (*pavVar14)[1];
                  local_34 = (*pavVar14)[2];
                }
                else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float adjr@[???]
                       Unresolved local var: float adjg@[???]
                       Unresolved local var: float adjb@[???]
                       Unresolved local var: float c@[???] */
                  R_LightLambert(lightpos[*(short *)pcVar16],
                                 (float *)(psVar6->name + iVar11 + iVar12 + -8),*pavVar14,&local_3c)
                  ;
                }
                (*qglColor4f)(local_3c,local_38,local_34,r_blend);
                pcVar10 = pcVar16 + 8;
                paVar15 = pauxverts + *(short *)pcVar16;
                (*qglVertex3f)(paVar15->fv[0],paVar15->fv[1],paVar15->fv[2]);
                iVar20 = iVar20 + -1;
              } while ((iVar20 != 0) &&
                      (pcVar13 = pcVar16 + 10, pcVar16 = pcVar10,
                      *(short *)pcVar13 < pvlightvalues_size));
            }
          }
          else {
            (*qglBegin)(5);
            if (iVar20 != 0) goto LAB_00143a5d;
          }
          (*qglEnd)();
          pcVar13 = pcVar10;
          sVar2 = *(short *)pcVar10;
        }
      }
      else {
        iVar20 = (int)*(short *)pcVar13;
        if ((g_ForcedFaceFlags & 2U) == 0) {
          pcVar13 = pcVar13 + 2;
          if (iVar20 != 0) {
            if (iVar20 < 0) goto LAB_00143dac;
            do {
              (*qglBegin)(5);
              if (iVar20 == 0) goto LAB_00143d90;
              while( true ) {
                iVar11 = (int)*(short *)(pcVar13 + 2);
                pcVar10 = pcVar13;
                if (iVar11 < pvlightvalues_size) {
                  do {
                    (*qglTexCoord2f)((float)chrome[iVar11][0] * local_64 * 0.0009765625,
                                     (float)chrome[iVar11][1] * local_68 * 0.0009765625);
                    pavVar14 = pvlightvalues + *(short *)(pcVar10 + 2);
                    if (numlights == 0) {
                      local_3c = (*pavVar14)[0];
                      local_38 = (*pavVar14)[1];
                      local_34 = (*pavVar14)[2];
                    }
                    else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float adjr@[???]
                       Unresolved local var: float adjg@[???]
                       Unresolved local var: float adjb@[???]
                       Unresolved local var: float c@[???] */
                      R_LightLambert(lightpos[*(short *)pcVar10],
                                     (float *)(psVar6->name +
                                              *(short *)(pcVar10 + 2) * 0xc + iVar12 + -8),*pavVar14
                                     ,&local_3c);
                    }
                    (*qglColor4f)(local_3c,local_38,local_34,r_blend);
                    pcVar13 = pcVar10 + 8;
                    paVar15 = pauxverts + *(short *)pcVar10;
                    (*qglVertex3f)(paVar15->fv[0],paVar15->fv[1],paVar15->fv[2]);
                    iVar20 = iVar20 + -1;
                  } while ((iVar20 != 0) &&
                          (iVar11 = (int)*(short *)(pcVar10 + 10), pcVar10 = pcVar13,
                          iVar11 < pvlightvalues_size));
                }
LAB_00143d90:
                (*qglEnd)();
                iVar20 = (int)*(short *)pcVar13;
                pcVar13 = pcVar13 + 2;
                if (iVar20 == 0) goto LAB_00143bd4;
                if (-1 < iVar20) break;
LAB_00143dac:
                iVar20 = -iVar20;
                (*qglBegin)(6);
              }
            } while( true );
          }
        }
        else {
          while (iVar20 != 0) {
            pcVar13 = pcVar13 + 2;
            pcVar10 = pcVar13;
            if (iVar20 < 0) {
              iVar20 = -iVar20;
              (*qglBegin)(6);
              iVar11 = iVar20;
LAB_00143ef0:
              do {
                    /* Unresolved local var: int normalIndex@[???] */
                (*qglTexCoord2f)((float)chrome[g_NormalIndex[*(short *)pcVar10]][0] *
                                 local_64 * 0.0009765625,
                                 (float)chrome[g_NormalIndex[*(short *)pcVar10]][1] *
                                 local_68 * 0.0009765625);
                paVar15 = pauxverts + *(short *)pcVar10;
                (*qglVertex3f)(paVar15->fv[0],paVar15->fv[1],paVar15->fv[2]);
                iVar20 = iVar20 + -1;
                pcVar10 = pcVar10 + 8;
              } while (iVar20 != 0);
              pcVar13 = pcVar13 + iVar11 * 8;
            }
            else {
              (*qglBegin)(5);
              iVar11 = iVar20;
              if (iVar20 != 0) goto LAB_00143ef0;
            }
            (*qglEnd)();
            iVar20 = (int)*(short *)pcVar13;
          }
        }
      }
LAB_00143bd4:
      if ((uVar17 & 0x40) != 0) {
        (*qglAlphaFunc)(0x205,0.0);
        (*qglDisable)(0xbc0);
      }
      if (((uVar17 & 0x20) != 0) && ((currententity->curstate).rendermode == 0)) {
        (*qglDisable)(0xbe2);
        (*qglDepthMask)('\x01');
        (*qglShadeModel)(0x1d00);
      }
      local_5c = local_5c + 1;
      local_58 = local_58 + 0x14;
    } while (local_5c < psubmodel->nummesh);
  }
  (*qglEnable)(0xb44);
  return;
}


// R_GetAnim  @ 0013cd10
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


// R_GetAttachmentPoint  @ 001ab570
float * R_GetAttachmentPoint(int entity,int attachment)

{
                    /* Unresolved local var: cl_entity_t * pEntity@[DW_OP_reg2(EDX)] */
  if (attachment == 0) {
    return cl_entities[entity].origin;
  }
  return cl_entities[entity].angles + attachment * 3;
}


// R_GetBeamAttachmentEntity  @ 001ecf00
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


// R_GetPackedColor  @ 001f19c0
void R_GetPackedColor(short *packed,short color)

{
  if (packed != (short *)0x0) {
    *packed = 0;
    return;
  }
  Con_Printf("R_GetPackedColor called without packed!\n");
  return;
}


// R_GetSpriteAxes  @ 001ab170
void R_GetSpriteAxes(cl_entity_t *pEntity,int type,vec_t *forward,vec_t *right,vec_t *up)

{
  vec_t vVar1;
  float fVar2;
  float local_24;
  float local_20 [2];
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float dot@[???]
                       Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: vec3_t tvec@[???] */
  if ((type == 2) && (pEntity->angles[2] != 0.0)) {
switchD_001ab2c8_caseD_4:
    sincosf(currententity->angles[2] * 0.017453292,local_20,&local_24);
    *forward = vpn[0];
    fVar2 = -local_20[0];
    *right = vup[0] * local_20[0] + vright[0] * local_24;
    *up = vup[0] * local_24 + vright[0] * fVar2;
    forward[1] = vpn[1];
    right[1] = vup[1] * local_20[0] + vright[1] * local_24;
    up[1] = vup[1] * local_24 + vright[1] * fVar2;
    forward[2] = vpn[2];
    right[2] = local_20[0] * vup[2] + vright[2] * local_24;
    up[2] = local_24 * vup[2] + vright[2] * fVar2;
  }
  else {
    switch(type) {
    case 0:
      if (0.999848 < vpn[2]) {
        return;
      }
      if (vpn[2] < -0.999848) {
        return;
      }
      *up = 0.0;
      up[1] = 0.0;
      up[2] = 1.0;
      *right = vpn[1];
      fVar2 = vpn[0];
      break;
    case 1:
      local_18 = -modelorg[0];
      local_14 = -modelorg[1];
      local_10 = -modelorg[2];
      VectorNormalize(&local_18);
      if (0.999848 < local_10) {
        return;
      }
      if (local_10 < -0.999848) {
        return;
      }
      *up = 0.0;
      up[1] = 0.0;
      up[2] = 1.0;
      *right = local_14;
      fVar2 = local_18;
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
      goto switchD_001ab2c8_caseD_4;
    default:
      Sys_Error("R_DrawSprite: Bad sprite type %d",type);
      return;
    }
    right[2] = 0.0;
    right[1] = -fVar2;
    VectorNormalize(right);
    *forward = -right[1];
    vVar1 = *right;
    forward[2] = 0.0;
    forward[1] = vVar1;
  }
  return;
}


// R_GetSpriteFrame  @ 001ab0e0
mspriteframe_t * R_GetSpriteFrame(msprite_t *pSprite,int frame)

{
  spriteframetype_t sVar1;
  mspriteframe_t *pmVar2;
  int iVar3;
  
                    /* Unresolved local var: mspriteframe_t * pspriteframe@[???] */
  if (pSprite == (msprite_t *)0x0) {
    Con_Printf("Sprite:  no pSprite!!!\n");
    pmVar2 = (mspriteframe_t *)0x0;
  }
  else if (pSprite->numframes == 0) {
    Con_Printf("Sprite:  pSprite has no frames!!!\n");
    pmVar2 = (mspriteframe_t *)0x0;
  }
  else {
    if ((frame < 0) || (pSprite->numframes <= frame)) {
      Con_DPrintf("Sprite: no such frame %d\n",frame);
      iVar3 = 2;
      sVar1 = pSprite->frames[0].type;
    }
    else {
      iVar3 = frame + 2;
      sVar1 = pSprite->frames[frame].type;
    }
    pmVar2 = (mspriteframe_t *)0x0;
    if (sVar1 == SPR_SINGLE) {
      pmVar2 = pSprite->frames[iVar3 + -2].frameptr;
    }
  }
  return pmVar2;
}


// R_GetStudioBounds  @ 00146ec0
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
      goto LAB_00146f7b;
    }
    local_34 = 0;
  }
  else {
LAB_00146f7b:
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
      goto LAB_00146fbf;
    }
  }
  COM_FreeFile(pBuffer);
LAB_00146fbf:
  FS_Close(file);
  return local_34;
}


// R_Implosion  @ 001ed7f0
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
  float fVar9;
  float fVar10;
  int iVar11;
  float fVar12;
  vec_t local_3c;
  vec_t local_38;
  vec_t local_34;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t start@[???]
                       Unresolved local var: vec3_t temp@[???]
                       Unresolved local var: vec3_t vel@[???] */
  fVar5 = radius / 100.0;
  if (0 < count) {
    iVar11 = 0;
    do {
      local_28 = RandomFloat(-100.0,100.0);
      local_28 = local_28 * fVar5;
      local_24 = RandomFloat(-100.0,100.0);
      local_24 = local_24 * fVar5;
      fVar12 = RandomFloat(0.0,100.0);
      fVar10 = local_24;
      fVar9 = local_28;
      fVar2 = *end;
      fVar3 = end[1];
      fVar4 = end[2];
      local_20 = fVar12 * fVar5;
      VectorScale(&local_28,-1.0 / life,&local_3c);
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
        ppVar8->type = pt_static;
        ppVar8->org[0] = fVar2 + fVar9;
        ppVar8->ramp = fVar6;
        ppVar8->vel[0] = local_3c;
        ppVar8->org[1] = fVar3 + fVar10;
        ppVar8->vel[1] = local_38;
        ppVar8->org[2] = fVar12 * fVar5 + fVar4;
        ppVar8->vel[2] = local_34;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 != count);
  }
  return;
}


// R_Init  @ 0020aca0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_Init(void)

{
                    /* Unresolved local var: uchar * hunk_base@[???]
                       Unresolved local var: int i@[???] */
  Cmd_AddCommandWithFlags("timerefresh",R_TimeRefresh_f,0x10);
  Cmd_AddCommand("envmap",R_Envmap_f);
  Cmd_AddCommand("pointfile",R_ReadPointFile_f);
  Cmd_AddCommand("gl_dump",GL_Dump_f);
  Cvar_RegisterVariable(&ati_npatch);
  Cvar_RegisterVariable(&gl_wireframe);
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
  Cvar_RegisterVariable(&r_mmx);
  Cvar_RegisterVariable(&r_traceglow);
  Cvar_RegisterVariable(&r_glowshellfreq);
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
  if (gl_mtexable != 0) {
    gl_texsort = false;
    Cvar_SetValue("gl_overbright",0.0);
  }
  R_InitParticles();
  R_InitParticleTexture();
  R_UploadEmptyTex();
  playertextures[0] = GL_GenTexture();
  playertextures[1] = GL_GenTexture();
  playertextures[2] = GL_GenTexture();
  playertextures[3] = GL_GenTexture();
  playertextures[4] = GL_GenTexture();
  playertextures[5] = GL_GenTexture();
  playertextures[6] = GL_GenTexture();
  playertextures[7] = GL_GenTexture();
  playertextures[8] = GL_GenTexture();
  playertextures[9] = GL_GenTexture();
  playertextures[10] = GL_GenTexture();
  playertextures[0xb] = GL_GenTexture();
  playertextures[0xc] = GL_GenTexture();
  playertextures[0xd] = GL_GenTexture();
  playertextures[0xe] = GL_GenTexture();
  playertextures[0xf] = GL_GenTexture();
  return;
}


// R_InitParticleTexture  @ 0020a1c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_InitParticleTexture(void)

{
  undefined1 local_11c;
  undefined1 local_11b;
  undefined1 local_11a;
  char local_119;
  undefined1 local_118;
  undefined1 local_117;
  undefined1 local_116;
  char local_115;
  undefined1 local_114;
  undefined1 local_113;
  undefined1 local_112;
  char local_111;
  undefined1 local_110;
  undefined1 local_10f;
  undefined1 local_10e;
  char local_10d;
  undefined1 local_10c;
  undefined1 local_10b;
  undefined1 local_10a;
  char local_109;
  undefined1 local_108;
  undefined1 local_107;
  undefined1 local_106;
  char local_105;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_101;
  undefined1 local_100;
  undefined1 local_ff;
  undefined1 local_fe;
  char local_fd;
  undefined1 local_fc;
  undefined1 local_fb;
  undefined1 local_fa;
  char local_f9;
  undefined1 local_f8;
  undefined1 local_f7;
  undefined1 local_f6;
  char local_f5;
  undefined1 local_f4;
  undefined1 local_f3;
  undefined1 local_f2;
  char local_f1;
  undefined1 local_f0;
  undefined1 local_ef;
  undefined1 local_ee;
  char local_ed;
  undefined1 local_ec;
  undefined1 local_eb;
  undefined1 local_ea;
  char local_e9;
  undefined1 local_e8;
  undefined1 local_e7;
  undefined1 local_e6;
  char local_e5;
  undefined1 local_e4;
  undefined1 local_e3;
  undefined1 local_e2;
  char local_e1;
  undefined1 local_e0;
  undefined1 local_df;
  undefined1 local_de;
  char local_dd;
  undefined1 local_dc;
  undefined1 local_db;
  undefined1 local_da;
  char local_d9;
  undefined1 local_d8;
  undefined1 local_d7;
  undefined1 local_d6;
  char local_d5;
  undefined1 local_d4;
  undefined1 local_d3;
  undefined1 local_d2;
  char local_d1;
  undefined1 local_d0;
  undefined1 local_cf;
  undefined1 local_ce;
  char local_cd;
  undefined1 local_cc;
  undefined1 local_cb;
  undefined1 local_ca;
  char local_c9;
  undefined1 local_c8;
  undefined1 local_c7;
  undefined1 local_c6;
  char local_c5;
  undefined1 local_c4;
  undefined1 local_c3;
  undefined1 local_c2;
  char local_c1;
  undefined1 local_c0;
  undefined1 local_bf;
  undefined1 local_be;
  char local_bd;
  undefined1 local_bc;
  undefined1 local_bb;
  undefined1 local_ba;
  char local_b9;
  undefined1 local_b8;
  undefined1 local_b7;
  undefined1 local_b6;
  char local_b5;
  undefined1 local_b4;
  undefined1 local_b3;
  undefined1 local_b2;
  char local_b1;
  undefined1 local_b0;
  undefined1 local_af;
  undefined1 local_ae;
  char local_ad;
  undefined1 local_ac;
  undefined1 local_ab;
  undefined1 local_aa;
  char local_a9;
  undefined1 local_a8;
  undefined1 local_a7;
  undefined1 local_a6;
  char local_a5;
  undefined1 local_a4;
  undefined1 local_a3;
  undefined1 local_a2;
  char local_a1;
  undefined1 local_a0;
  undefined1 local_9f;
  undefined1 local_9e;
  char local_9d;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a;
  char local_99;
  undefined1 local_98;
  undefined1 local_97;
  undefined1 local_96;
  char local_95;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92;
  char local_91;
  undefined1 local_90;
  undefined1 local_8f;
  undefined1 local_8e;
  char local_8d;
  undefined1 local_8c;
  undefined1 local_8b;
  undefined1 local_8a;
  char local_89;
  undefined1 local_88;
  undefined1 local_87;
  undefined1 local_86;
  char local_85;
  undefined1 local_84;
  undefined1 local_83;
  undefined1 local_82;
  char local_81;
  undefined1 local_80;
  undefined1 local_7f;
  undefined1 local_7e;
  char local_7d;
  undefined1 local_7c;
  undefined1 local_7b;
  undefined1 local_7a;
  char local_79;
  undefined1 local_78;
  undefined1 local_77;
  undefined1 local_76;
  char local_75;
  undefined1 local_74;
  undefined1 local_73;
  undefined1 local_72;
  char local_71;
  undefined1 local_70;
  undefined1 local_6f;
  undefined1 local_6e;
  char local_6d;
  undefined1 local_6c;
  undefined1 local_6b;
  undefined1 local_6a;
  char local_69;
  undefined1 local_68;
  undefined1 local_67;
  undefined1 local_66;
  char local_65;
  undefined1 local_64;
  undefined1 local_63;
  undefined1 local_62;
  char local_61;
  undefined1 local_60;
  undefined1 local_5f;
  undefined1 local_5e;
  char local_5d;
  undefined1 local_5c;
  undefined1 local_5b;
  undefined1 local_5a;
  char local_59;
  undefined1 local_58;
  undefined1 local_57;
  undefined1 local_56;
  char local_55;
  undefined1 local_54;
  undefined1 local_53;
  undefined1 local_52;
  char local_51;
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  char local_4d;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  char local_49;
  undefined1 local_48;
  undefined1 local_47;
  undefined1 local_46;
  char local_45;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  char local_41;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  char local_3d;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  char local_39;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  char local_35;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  char local_31;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  char local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  char local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  char local_25;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  char local_21;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  char local_1d;
  int local_18;
  int local_14;
  int local_10 [4];
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: uchar[8][8][4] data@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int bpp@[???] */
  particletexture = GL_GenTexture();
  GL_Bind(particletexture);
  local_7c = 0xff;
  local_7b = 0xff;
  local_119 = -dottexture[0][0];
  local_11c = 0xff;
  local_11b = 0xff;
  local_11a = 0xff;
  local_f9 = -dottexture[0][1];
  local_fc = 0xff;
  local_fb = 0xff;
  local_fa = 0xff;
  local_d9 = -dottexture[0][2];
  local_bc = 0xff;
  local_bb = 0xff;
  local_ba = 0xff;
  local_dc = 0xff;
  local_db = 0xff;
  local_da = 0xff;
  local_b9 = -dottexture[0][3];
  local_9c = 0xff;
  local_9b = 0xff;
  local_9a = 0xff;
  local_99 = -dottexture[0][4];
  local_7a = 0xff;
  local_79 = -dottexture[0][5];
  local_5c = 0xff;
  local_5b = 0xff;
  local_5a = 0xff;
  local_59 = -dottexture[0][6];
  local_3c = 0xff;
  local_3b = 0xff;
  local_3a = 0xff;
  local_b8 = 0xff;
  local_77 = 0xff;
  local_39 = -dottexture[0][7];
  local_76 = 0xff;
  local_118 = 0xff;
  local_117 = 0xff;
  local_115 = -dottexture[1][0];
  local_116 = 0xff;
  local_f8 = 0xff;
  local_f7 = 0xff;
  local_f5 = -dottexture[1][1];
  local_f6 = 0xff;
  local_d8 = 0xff;
  local_d7 = 0xff;
  local_d5 = -dottexture[1][2];
  local_b7 = 0xff;
  local_b6 = 0xff;
  local_d6 = 0xff;
  local_b5 = -dottexture[1][3];
  local_98 = 0xff;
  local_97 = 0xff;
  local_96 = 0xff;
  local_95 = -dottexture[1][4];
  local_78 = 0xff;
  local_75 = -dottexture[1][5];
  local_58 = 0xff;
  local_57 = 0xff;
  local_56 = 0xff;
  local_b4 = 0xff;
  local_b3 = 0xff;
  local_114 = 0xff;
  local_55 = -dottexture[1][6];
  local_38 = 0xff;
  local_37 = 0xff;
  local_36 = 0xff;
  local_113 = 0xff;
  local_112 = 0xff;
  local_f4 = 0xff;
  local_35 = -dottexture[1][7];
  local_f3 = 0xff;
  local_f2 = 0xff;
  local_d4 = 0xff;
  local_111 = -dottexture[2][0];
  local_d3 = 0xff;
  local_d2 = 0xff;
  local_f1 = -dottexture[2][1];
  local_d1 = -dottexture[2][2];
  local_b2 = 0xff;
  local_b1 = -dottexture[2][3];
  local_94 = 0xff;
  local_93 = 0xff;
  local_92 = 0xff;
  local_91 = -dottexture[2][4];
  local_74 = 0xff;
  local_73 = 0xff;
  local_72 = 0xff;
  local_54 = 0xff;
  local_af = 0xff;
  local_71 = -dottexture[2][5];
  local_53 = 0xff;
  local_52 = 0xff;
  local_ae = 0xff;
  local_110 = 0xff;
  local_10f = 0xff;
  local_51 = -dottexture[2][6];
  local_34 = 0xff;
  local_33 = 0xff;
  local_32 = 0xff;
  local_10e = 0xff;
  local_f0 = 0xff;
  local_ef = 0xff;
  local_31 = -dottexture[2][7];
  local_ee = 0xff;
  local_d0 = 0xff;
  local_cf = 0xff;
  local_10d = -dottexture[3][0];
  local_ce = 0xff;
  local_ed = -dottexture[3][1];
  local_cd = -dottexture[3][2];
  local_b0 = 0xff;
  local_ad = -dottexture[3][3];
  local_90 = 0xff;
  local_8f = 0xff;
  local_8e = 0xff;
  local_50 = 0xff;
  local_4f = 0xff;
  local_ca = 0xff;
  local_8d = -dottexture[3][4];
  local_70 = 0xff;
  local_6f = 0xff;
  local_6e = 0xff;
  local_10c = 0xff;
  local_10b = 0xff;
  local_10a = 0xff;
  local_6d = -dottexture[3][5];
  local_4e = 0xff;
  local_ec = 0xff;
  local_eb = 0xff;
  local_ea = 0xff;
  local_4d = -dottexture[3][6];
  local_30 = 0xff;
  local_2f = 0xff;
  local_2e = 0xff;
  local_2d = -dottexture[3][7];
  local_109 = -dottexture[4][0];
  local_e9 = -dottexture[4][1];
  local_cc = 0xff;
  local_cb = 0xff;
  local_c9 = -dottexture[4][2];
  local_ab = 0xff;
  local_aa = 0xff;
  local_ac = 0xff;
  local_6b = 0xff;
  local_6a = 0xff;
  local_a9 = -dottexture[4][3];
  local_8c = 0xff;
  local_8b = 0xff;
  local_8a = 0xff;
  local_108 = 0xff;
  local_107 = 0xff;
  local_106 = 0xff;
  local_89 = -dottexture[4][4];
  local_6c = 0xff;
  local_e8 = 0xff;
  local_e7 = 0xff;
  local_e6 = 0xff;
  local_69 = -dottexture[4][5];
  local_4c = 0xff;
  local_4b = 0xff;
  local_4a = 0xff;
  local_49 = -dottexture[4][6];
  local_2c = 0xff;
  local_2b = 0xff;
  local_2a = 0xff;
  local_29 = -dottexture[4][7];
  local_105 = -dottexture[5][0];
  local_e5 = -dottexture[5][1];
  local_c6 = 0xff;
  local_c8 = 0xff;
  local_c7 = 0xff;
  local_86 = 0xff;
  local_c5 = -dottexture[5][2];
  local_a8 = 0xff;
  local_a7 = 0xff;
  local_a6 = 0xff;
  local_68 = 0xff;
  local_27 = 0xff;
  local_26 = 0xff;
  local_a5 = -dottexture[5][3];
  local_88 = 0xff;
  local_87 = 0xff;
  local_104 = 0xff;
  local_103 = 0xff;
  local_102 = 0xff;
  local_85 = -dottexture[5][4];
  local_67 = 0xff;
  local_66 = 0xff;
  local_65 = -dottexture[5][5];
  local_48 = 0xff;
  local_47 = 0xff;
  local_46 = 0xff;
  local_45 = -dottexture[5][6];
  local_28 = 0xff;
  local_25 = -dottexture[5][7];
  local_101 = -dottexture[6][0];
  local_84 = 0xff;
  local_83 = 0xff;
  local_42 = 0xff;
  local_e1 = -dottexture[6][1];
  local_c4 = 0xff;
  local_c3 = 0xff;
  local_c2 = 0xff;
  local_24 = 0xff;
  local_e4 = 0xff;
  local_e3 = 0xff;
  local_c1 = -dottexture[6][2];
  local_a4 = 0xff;
  local_a3 = 0xff;
  local_a2 = 0xff;
  local_e2 = 0xff;
  local_a1 = -dottexture[6][3];
  local_82 = 0xff;
  local_81 = -dottexture[6][4];
  local_64 = 0xff;
  local_63 = 0xff;
  local_62 = 0xff;
  local_61 = -dottexture[6][5];
  local_44 = 0xff;
  local_43 = 0xff;
  local_41 = -dottexture[6][6];
  local_23 = 0xff;
  local_22 = 0xff;
  local_21 = -dottexture[6][7];
  local_9f = 0xff;
  local_9e = 0xff;
  local_40 = 0xff;
  local_fd = -dottexture[7][0];
  local_3f = 0xff;
  local_100 = 0xff;
  local_ff = 0xff;
  local_dd = -dottexture[7][1];
  local_c0 = 0xff;
  local_bf = 0xff;
  local_be = 0xff;
  local_fe = 0xff;
  local_e0 = 0xff;
  local_df = 0xff;
  local_bd = -dottexture[7][2];
  local_a0 = 0xff;
  local_de = 0xff;
  local_9d = -dottexture[7][3];
  local_80 = 0xff;
  local_7f = 0xff;
  local_7e = 0xff;
  local_7d = -dottexture[7][4];
  local_60 = 0xff;
  local_5f = 0xff;
  local_5e = 0xff;
  local_5d = -dottexture[7][5];
  local_3e = 0xff;
  local_3d = -dottexture[7][6];
  local_20 = 0xff;
  local_1f = 0xff;
  local_1e = 0xff;
  local_1d = -dottexture[7][7];
  VideoMode_GetCurrentVideoMode(&local_18,&local_14,local_10);
  if (local_10[0] == 0x20) {
    (*qglTexImage2D)(0xde1,0,0x8058,8,8,0,0x1908,0x1401,&local_11c);
  }
  else {
    (*qglTexImage2D)(0xde1,0,0x8057,8,8,0,0x1908,0x1401,&local_11c);
  }
  (*qglTexEnvf)(0x2300,0x2200,8448.0);
  (*qglTexParameterf)(0xde1,0x2801,9729.0);
  (*qglTexParameterf)(0xde1,0x2800,9729.0);
  (*qglTexParameterf)(0xde1,0x84fe,gl_ansio.value);
  return;
}


// R_InitParticles  @ 001e9df0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_InitParticles(void)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???] */
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


// R_InitSky  @ 001e2990
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_InitSky(void)

{
  gLoadSky = 1;
  return;
}


// R_InitStudioCache  @ 0013db40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_InitStudioCache(void)

{
  Q_memset(rgStudioCache,0,0x440);
  r_cachecurrent = 0;
  nCurrentHull = 0;
  nCurrentPlane = 0;
  return;
}


// R_InitTextures  @ 0020a060
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


// R_InsertCustomDecal  @ 001e5da0
void R_InsertCustomDecal(decal_t *pdecal,msurface_t *surface)

{
  decal_s *pdVar1;
  decal_s *pdVar2;
  
                    /* Unresolved local var: decal_t * p@[???]
                       Unresolved local var: decal_t * prev@[???] */
  pdVar1 = surface->pdecals;
  if (pdVar1 == (decal_s *)0x0) {
    pdVar2 = (decal_s *)0x0;
  }
  else {
    if ((pdVar1->flags & 0x80) != 0) {
      pdecal->pnext = pdVar1;
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


// R_IsRemapSkin  @ 001422c0
int R_IsRemapSkin(char *texture,int *low,int *mid,int *high)

{
  int iVar1;
  int iVar2;
  char local_3c [44];
  
                    /* Unresolved local var: char[32] sz@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: char ch@[???] */
  iVar2 = 0;
  iVar1 = Q_strnicmp(texture,"Remap",5);
  if ((iVar1 == 0) && ((iVar1 = Q_strlen(texture), iVar1 == 0x12 || (iVar1 == 0x16)))) {
    if (iVar1 == 0x12) {
      if ((texture[5] != 'c') && (texture[5] != 'C')) {
        return 0;
      }
      Q_memset(local_3c,0,0x20);
      Q_strncpy(local_3c,texture + 7,3);
      iVar1 = Q_atoi(local_3c);
      *low = iVar1;
      Q_strncpy(local_3c,texture + 0xb,3);
      iVar1 = Q_atoi(local_3c);
      *mid = iVar1;
    }
    else {
      Q_memset(local_3c,0,0x20);
      Q_strncpy(local_3c,texture + 7,3);
      iVar2 = Q_atoi(local_3c);
      *low = iVar2;
      Q_strncpy(local_3c,texture + 0xb,3);
      iVar2 = Q_atoi(local_3c);
      *mid = iVar2;
      if (iVar1 == 0x16) {
        Q_strncpy(local_3c,texture + 0xf,3);
        iVar1 = Q_atoi(local_3c);
        *high = iVar1;
        return 1;
      }
    }
    *high = 0;
    iVar2 = 1;
  }
  return iVar2;
}


// R_KillAttachedTents  @ 001a6460
void R_KillAttachedTents(int client)

{
  tempent_s *ptVar1;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???] */
  if ((-1 < client) && (ptVar1 = gpTempEntActive, client <= cl.maxclients)) {
    do {
      if (ptVar1 == (TEMPENTITY *)0x0) {
        return;
      }
      while (((ptVar1->flags & 0x8000U) == 0 || (ptVar1->clientIndex != client))) {
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


// R_KillDeadBeams  @ 001ed6a0
void R_KillDeadBeams(int deadEntity)

{
  BEAM *pBVar1;
  particle_s *ppVar2;
  BEAM *pBVar3;
  BEAM *dest;
  
                    /* Unresolved local var: BEAM * pbeam@[???]
                       Unresolved local var: BEAM * pnewlist@[???]
                       Unresolved local var: BEAM * pnext@[???]
                       Unresolved local var: particle_t * pHead@[???] */
  pBVar3 = (BEAM *)0x0;
  pBVar1 = gpActiveBeams;
  do {
    dest = pBVar1;
    if (pBVar1 == (BEAM *)0x0) {
      gpActiveBeams = pBVar3;
      return;
    }
    while ((pBVar1 = dest->next, dest->startEntity == deadEntity &&
           (dest->flags = dest->flags & 0xfffffffc, dest->type != 0x16))) {
      dest->die = (float)((longdouble)cl.time - (longdouble)0.1);
      for (ppVar2 = dest->particles; ppVar2 != (particle_s *)0x0; ppVar2 = ppVar2->next) {
        ppVar2->die = (float)((longdouble)cl.time - (longdouble)0.1);
      }
      R_FreeDeadParticles(&dest->particles);
      Q_memset(dest,0,0x7c);
      dest->next = gpFreeBeams;
      gpFreeBeams = dest;
      dest = pBVar1;
      if (pBVar1 == (BEAM *)0x0) {
        gpActiveBeams = pBVar3;
        return;
      }
    }
    dest->next = pBVar3;
    pBVar3 = dest;
  } while( true );
}


// R_LargeFunnel  @ 001eb5a0
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
        fVar6 = ppVar4->org[2];
      }
      else {
        ppVar4->org[0] = *org;
        ppVar4->org[1] = org[1];
        ppVar4->org[2] = org[2];
        fVar7 = *org;
        fVar8 = org[1];
        fVar2 = org[2];
        fVar6 = RandomFloat(100.0,800.0);
        fVar6 = fVar6 + fVar2;
        local_28 = ((float)local_38 + fVar7) - ppVar4->org[0];
        local_24 = ((float)iVar5 + fVar8) - ppVar4->org[1];
        local_20 = fVar6 - ppVar4->org[2];
      }
      fVar6 = fVar6 * 0.125;
      ppVar4->color = 0xf4;
      ppVar4->packedColor = 0;
      ppVar4->type = pt_static;
      fVar7 = VectorNormalize(&local_28);
      if (fVar6 < 64.0) {
        fVar6 = 64.0;
      }
      iVar5 = iVar5 + 0x20;
      fVar8 = RandomFloat(64.0,128.0);
      VectorScale(&local_28,fVar6 + fVar8,ppVar4->vel);
      ppVar4->die = fVar7 / (fVar6 + fVar8) + (float)cl.time;
    } while (iVar5 != 0x120);
    local_38 = local_38 + 0x20;
  } while (local_38 != 0x120);
  return;
}


// R_LavaSplash  @ 001eb420
void R_LavaSplash(vec_t *org)

{
  particle_s **pppVar1;
  double dVar2;
  particle_t *ppVar3;
  particle_t *ppVar4;
  int32 iVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  int local_38;
  float local_28;
  float local_24;
  undefined4 local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: float vel@[???]
                       Unresolved local var: vec3_t dir@[???] */
  local_38 = -0x80;
  do {
    iVar7 = -0x80;
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
      local_24 = (float)local_38 + local_24;
      ppVar4->org[0] = *org + local_28;
      ppVar4->org[1] = org[1] + local_24;
      fVar8 = org[2];
      fVar9 = RandomFloat(0.0,63.0);
      ppVar4->org[2] = fVar9 + fVar8;
      VectorNormalize(&local_28);
      fVar8 = RandomFloat(50.0,113.0);
      VectorScale(&local_28,fVar8,ppVar4->vel);
      iVar7 = iVar6;
    } while (iVar6 != 0x80);
    local_38 = local_38 + 8;
  } while (local_38 != 0x80);
  return;
}


// R_LightLambert  @ 0013ac00
void __regparm3 R_LightLambert(float (*light) [4],float *normal,float *src,float *lambert)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int (*paiVar7) [3];
  int iVar8;
  int iVar9;
  float fVar10;
  float local_28;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float adjr@[???]
                       Unresolved local var: float adjg@[???]
                       Unresolved local var: float adjb@[???]
                       Unresolved local var: float c@[???] */
  if (numlights < 1) {
    fVar5 = 0.0;
    fVar4 = 0.0;
    local_28 = 0.0;
  }
  else {
    fVar4 = 0.0;
    paiVar7 = locallinearlight;
    iVar8 = 0;
    local_28 = 0.0;
    iVar9 = numlights;
    fVar5 = fVar4;
    do {
      fVar1 = (*light)[0];
      fVar10 = (*light)[1];
      fVar2 = (*light)[2];
      fVar6 = -(normal[2] * fVar2 + normal[1] * fVar10 + *normal * fVar1);
      if (0.0 < fVar6) {
        fVar3 = (*light)[3];
        if (fVar3 == 0.0) {
                    /* Unresolved local var: float r2@[???]
                       Unresolved local var: float r@[???] */
          fVar1 = fVar2 * fVar2 + fVar10 * fVar10 + fVar1 * fVar1;
          if (0.0 < fVar1) {
            fVar10 = SQRT(fVar1);
            if (NAN(fVar10)) {
              fVar10 = sqrtf(fVar1);
              iVar9 = numlights;
            }
            fVar3 = locallightR2[iVar8] / (fVar10 * fVar1);
            (*light)[3] = fVar3;
          }
          else {
            (*light)[3] = 1.0;
            fVar3 = 1.0;
          }
        }
        fVar3 = fVar3 * fVar6;
        fVar5 = (float)(*paiVar7)[0] * fVar3 + fVar5;
        local_28 = (float)(*paiVar7)[1] * fVar3 + local_28;
        fVar4 = (float)(*paiVar7)[2] * fVar3 + fVar4;
      }
      iVar8 = iVar8 + 1;
      light = light + 1;
      paiVar7 = paiVar7 + 1;
    } while (iVar8 < iVar9);
    if ((fVar5 != 0.0) || (local_28 != 0.0)) goto LAB_0013ad10;
  }
  if (fVar4 == 0.0) {
    *lambert = *src;
    lambert[1] = src[1];
    lambert[2] = src[2];
    return;
  }
LAB_0013ad10:
                    /* Unresolved local var: int j@[???] */
  if ((int)((float)lineargammatable[(int)(*src * 1023.0)] + fVar5) < 0x400) {
    *lambert = (float)screengammatable[(int)((float)lineargammatable[(int)(*src * 1023.0)] + fVar5)]
               / 1023.0;
  }
  else {
    *lambert = 1.0;
  }
  if ((int)((float)lineargammatable[(int)(src[1] * 1023.0)] + local_28) < 0x400) {
    lambert[1] = (float)screengammatable
                        [(int)((float)lineargammatable[(int)(src[1] * 1023.0)] + local_28)] / 1023.0
    ;
  }
  else {
    lambert[1] = 1.0;
  }
  if ((int)((float)lineargammatable[(int)(src[2] * 1023.0)] + fVar4) < 0x400) {
    lambert[2] = (float)screengammatable
                        [(int)((float)lineargammatable[(int)(src[2] * 1023.0)] + fVar4)] / 1023.0;
    return;
  }
  lambert[2] = 1.0;
  return;
}


// R_LightLambert  @ 00141ad0
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


// R_LightPoint  @ 001e9d10
colorVec * R_LightPoint(colorVec *__return_storage_ptr__,vec_t *p)

{
  vec_t local_18;
  vec_t local_14;
  float local_10;
  
                    /* Unresolved local var: vec3_t end@[???] */
  local_18 = *p;
  local_10 = p[2] - 2048.0;
  local_14 = p[1];
  R_LightVec(__return_storage_ptr__,p,&local_18);
  return __return_storage_ptr__;
}


// R_LightStrength  @ 00141960
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
  dlight_t *pdVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  int iVar17;
  vec_t (*pavVar18) [3];
  int iVar19;
  int iVar20;
  
  iVar20 = r_smodels_total;
                    /* Unresolved local var: int i@[???] */
  iVar17 = numlights;
                    /* Unresolved local var: vec3_t lpos@[???] */
  if (lightage[bone] != r_smodels_total) {
    if (0 < numlights) {
      fVar1 = lighttransform[bone][0][3];
      fVar2 = lighttransform[bone][1][3];
      pavVar18 = lightbonepos[bone];
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
      iVar19 = 0;
      do {
        pdVar13 = locallight[iVar19];
        iVar19 = iVar19 + 1;
        fVar14 = pdVar13->origin[0] - fVar1;
        fVar16 = pdVar13->origin[1] - fVar2;
        fVar15 = pdVar13->origin[2] - fVar3;
        (*(vec_t (*) [3])*pavVar18)[0] = fVar6 * fVar15 + fVar5 * fVar16 + fVar4 * fVar14;
        (*(vec_t (*) [3])*pavVar18)[1] = fVar9 * fVar15 + fVar8 * fVar16 + fVar7 * fVar14;
        (*(vec_t (*) [3])*pavVar18)[2] = fVar15 * fVar12 + fVar16 * fVar11 + fVar14 * fVar10;
        pavVar18 = pavVar18 + 1;
      } while (iVar19 != iVar17);
    }
    lightage[bone] = iVar20;
  }
  if (0 < iVar17) {
    iVar20 = 0;
    pavVar18 = lightbonepos[bone];
    do {
      iVar20 = iVar20 + 1;
      (*light)[0] = *vert - (*(vec_t (*) [3])*pavVar18)[0];
      (*light)[1] = vert[1] - (*(vec_t (*) [3])*pavVar18)[1];
      fVar1 = vert[2];
      fVar2 = (*(vec_t (*) [3])*pavVar18)[2];
      pavVar18 = pavVar18 + 1;
      (*light)[3] = 0.0;
      (*light)[2] = fVar1 - fVar2;
      light = light + 1;
    } while (iVar20 != iVar17);
  }
  return;
}


// R_LightVec  @ 001e9c20
colorVec * R_LightVec(colorVec *__return_storage_ptr__,vec_t *start,vec_t *end)

{
  colorVec local_1c;
  
                    /* Unresolved local var: colorVec c@[???] */
  local_1c.r = 0;
  local_1c.g = 0;
  local_1c.b = 0;
  local_1c.a = 0;
  if ((cl.worldmodel)->lightdata != (color24 *)0x0) {
    RecursiveLightPoint(&local_1c,(cl.worldmodel)->nodes,start,end);
    local_1c.g = r_refdef.ambientlight.g + local_1c.g;
    local_1c.r = r_refdef.ambientlight.r + local_1c.r;
    local_1c.b = r_refdef.ambientlight.b + local_1c.b;
    __return_storage_ptr__->a = local_1c.a;
    if (0xff < local_1c.r) {
      local_1c.r = 0xff;
    }
    if (0xff < local_1c.g) {
      local_1c.g = 0xff;
    }
    if (0xff < local_1c.b) {
      local_1c.b = 0xff;
    }
    __return_storage_ptr__->r = local_1c.r;
    __return_storage_ptr__->g = local_1c.g;
    __return_storage_ptr__->b = local_1c.b;
    return __return_storage_ptr__;
  }
  __return_storage_ptr__->a = 0;
  __return_storage_ptr__->r = 0xff;
  __return_storage_ptr__->g = 0xff;
  __return_storage_ptr__->b = 0xff;
  return __return_storage_ptr__;
}


// R_LoadMapSprite  @ 001d5820
model_t * R_LoadMapSprite(char *szFilename)

{
  uchar *puVar1;
  uchar *puVar2;
  char *dest;
  uchar uVar3;
  uchar uVar4;
  uchar uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  model_t *mod;
  int iVar9;
  uchar *buffer;
  FileHandle_t hFile;
  uchar *puVar10;
  uchar *puVar11;
  uchar *puVar12;
  qboolean qVar13;
  uchar *puVar14;
  int iVar15;
  char *fmt;
  char *pcVar16;
  int local_174;
  char acStack_163 [262];
  undefined1 local_5d;
  uint local_5c [4];
  uint local_4c [4];
  byte *local_3c [4];
  byte *local_2c [3];
  int local_20 [4];
  
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
                       Unresolved local var: uchar * buffer1@[???]
                       Unresolved local var: uchar * buffer2@[???]
                       Unresolved local var: uchar * buffer3@[???] */
  iVar15 = 4;
  local_3c[0] = (byte *)0x0;
  dest = acStack_163 + 3;
  (*g_engdstAddrs.LoadMapSprite)(&szFilename);
  Q_strncpy(dest,szFilename,0x103);
  local_5d = 0;
  Q_strlwr(dest);
  mod = Mod_FindName(false,dest);
  mod->needload = false;
  iVar9 = Q_strlen(dest);
  iVar9 = Q_strcmp("tga",acStack_163 + iVar9);
  if (iVar9 != 0) {
    iVar15 = 1;
    iVar9 = Q_strlen(dest);
    iVar9 = Q_strcmp("bmp",acStack_163 + iVar9);
    if (iVar9 != 0) {
      Sys_Error("Unsupported map image file format.\n");
      return (model_t *)0x0;
    }
  }
  buffer = Mem_Malloc(0x300000);
  if (buffer == (uchar *)0x0) {
    Sys_Error("Not enough memory to load map images (1).\n");
    return (model_t *)0x0;
  }
  if (iVar15 == 4) {
    qVar13 = LoadTGA(dest,buffer,0x300000,(int *)local_5c,(int *)local_4c);
    pcVar16 = szFilename;
    if (qVar13 != false) {
      iVar9 = 0;
      iVar15 = local_5c[0] * local_4c[0];
      if (0 < iVar15) {
        do {
          if (((buffer[iVar9 * 4] == '\0') && (buffer[iVar9 * 4 + 1] == 0xff)) &&
             (buffer[iVar9 * 4 + 2] == '\0')) {
            puVar10 = buffer + iVar9 * 4;
            puVar10[0] = '\0';
            puVar10[1] = '\0';
            puVar10[2] = '\0';
            puVar10[3] = '\0';
          }
          iVar9 = iVar9 + 1;
          iVar15 = local_5c[0] * local_4c[0];
        } while (iVar15 - iVar9 != 0 && iVar9 <= iVar15);
      }
      goto LAB_001d5a4e;
    }
  }
  else {
                    /* Unresolved local var: FileHandle_t hFile@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: uchar * packPalette@[???] */
    local_2c[0] = (uchar *)0x0;
    hFile = FS_Open(dest,"rb");
    pcVar16 = dest;
    if (hFile != (FileHandle_t)0x0) {
      LoadBMP8(hFile,local_2c,local_20,local_3c,(int *)local_5c,(int *)local_4c);
      if ((local_3c[0] == (byte *)0x0) || (local_2c[0] == (uchar *)0x0)) {
        Con_Printf("Error loading %s\n",dest);
        Mem_Free(buffer);
        Mem_Free((void *)0x0);
        if (local_3c[0] != (byte *)0x0) {
          Mem_Free(local_3c[0]);
        }
        mod = (model_t *)0x0;
        puVar10 = local_2c[0];
        if (local_2c[0] == (uchar *)0x0) {
          return (model_t *)0x0;
        }
        goto LAB_001d5bbe;
      }
      iVar9 = 0;
      if (0 < (int)(local_5c[0] * local_4c[0])) {
        do {
          iVar15 = (uint)local_3c[0][iVar9] * 3;
          uVar3 = local_2c[0][iVar15];
          buffer[iVar9 * 4] = uVar3;
          uVar4 = local_2c[0][iVar15 + 1];
          buffer[iVar9 * 4 + 1] = uVar4;
          uVar5 = local_2c[0][iVar15 + 2];
          buffer[iVar9 * 4 + 2] = uVar5;
          if (((uVar4 == 0xff) && (uVar3 == '\0')) && (uVar5 == '\0')) {
            puVar10 = buffer + iVar9 * 4;
            puVar10[0] = '\0';
            puVar10[1] = '\0';
            puVar10[2] = '\0';
            puVar10[3] = '\0';
          }
          else {
            buffer[iVar9 * 4 + 3] = 0xff;
          }
          iVar9 = iVar9 + 1;
        } while (local_5c[0] * local_4c[0] - iVar9 != 0 && iVar9 <= (int)(local_5c[0] * local_4c[0])
                );
      }
      Mem_Free(local_3c[0]);
      Mem_Free(local_2c[0]);
      iVar15 = local_5c[0] * local_4c[0];
LAB_001d5a4e:
      if ((iVar15 != 0) && (((local_5c[0] | local_4c[0]) & 0x7f) == 0)) {
        puVar10 = Mem_Malloc(0x300000);
        if (puVar10 == (uchar *)0x0) {
          Sys_Error("Not enough memory to load map images (2).\n");
          return (model_t *)0x0;
        }
        if (0 < (int)local_4c[0]) {
          local_174 = 0;
          puVar12 = puVar10;
          do {
            iVar9 = 0;
            puVar11 = puVar12;
            if (0 < (int)local_5c[0]) {
              do {
                puVar12 = puVar11 + 0x10000;
                puVar14 = buffer + (local_174 * local_5c[0] + iVar9) * 4;
                do {
                  if ((puVar11 + 0x10 < puVar14) || (puVar14 + 0x10 < puVar11)) {
                    iVar15 = 0;
                    do {
                      puVar1 = puVar14 + iVar15;
                      uVar6 = *(undefined4 *)(puVar1 + 4);
                      uVar7 = *(undefined4 *)(puVar1 + 8);
                      uVar8 = *(undefined4 *)(puVar1 + 0xc);
                      puVar2 = puVar11 + iVar15;
                      *(undefined4 *)puVar2 = *(undefined4 *)puVar1;
                      *(undefined4 *)(puVar2 + 4) = uVar6;
                      *(undefined4 *)(puVar2 + 8) = uVar7;
                      *(undefined4 *)(puVar2 + 0xc) = uVar8;
                      iVar15 = iVar15 + 0x10;
                    } while (iVar15 != 0x200);
                  }
                  else {
                    iVar15 = 0;
                    do {
                      *(undefined4 *)(puVar11 + iVar15) = *(undefined4 *)(puVar14 + iVar15);
                      iVar15 = iVar15 + 4;
                    } while (iVar15 != 0x200);
                  }
                  puVar11 = puVar11 + 0x200;
                  puVar14 = puVar14 + local_5c[0] * 4;
                } while (puVar12 != puVar11);
                iVar9 = iVar9 + 0x80;
                puVar11 = puVar12;
              } while (iVar9 < (int)local_5c[0]);
            }
            local_174 = local_174 + 0x80;
          } while (local_174 < (int)local_4c[0]);
        }
        if ((int)local_4c[0] < 0) {
          local_4c[0] = local_4c[0] + 0x7f;
        }
        if ((int)local_5c[0] < 0) {
          local_5c[0] = local_5c[0] + 0x7f;
        }
        R_LoadOverviewSpriteModel(mod,puVar10,(int)local_5c[0] >> 7,(int)local_4c[0] >> 7);
        Mem_Free(buffer);
LAB_001d5bbe:
        Mem_Free(puVar10);
        return mod;
      }
      fmt = "Wrong map image dimensions or file could not be loaded in %s\n";
      pcVar16 = dest;
      goto LAB_001d5be9;
    }
  }
  fmt = "Couldn\'t open %s\n";
LAB_001d5be9:
  Con_Printf(fmt,pcVar16);
  Mem_Free(buffer);
  Mem_Free((void *)0x0);
  return (model_t *)0x0;
}


// R_LoadOverviewSpriteModel  @ 001d55e0
void R_LoadOverviewSpriteModel(model_t *mod,uchar *pdata,int XTiles,int yTiles)

{
  undefined2 *puVar1;
  undefined4 *dest;
  int iVar2;
  int iVar3;
  int iVar4;
  char local_11c [268];
  
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
  iVar3 = yTiles * XTiles;
  puVar1 = Hunk_AllocName(iVar3 * 8 + 0x1c,mod->name);
  (mod->cache).data = puVar1;
  *(undefined4 *)(puVar1 + 2) = 0x80;
  *(undefined4 *)(puVar1 + 4) = 0x80;
  *puVar1 = 4;
  puVar1[1] = 3;
  *(undefined4 *)(puVar1 + 10) = 0;
  mod->synctype = ST_SYNC;
  *(int *)(puVar1 + 6) = iVar3;
  iVar2 = *(int *)(puVar1 + 2);
  mod->mins[1] = (float)-(iVar2 / 2);
  mod->mins[0] = (float)-(iVar2 / 2);
  iVar2 = *(int *)(puVar1 + 2);
  mod->maxs[1] = (float)(iVar2 / 2);
  mod->maxs[0] = (float)(iVar2 / 2);
  mod->mins[2] = (float)-(*(int *)(puVar1 + 4) / 2);
  iVar2 = *(int *)(puVar1 + 4);
  mod->flags = 0;
  mod->numframes = iVar3;
  mod->maxs[2] = (float)(iVar2 / 2);
  if (0 < iVar3) {
    iVar2 = 0;
    do {
      *(undefined4 *)(puVar1 + 0xe) = 0;
      dest = Hunk_AllocName(0x1c,mod->name);
      Q_memset(dest,0,0x1c);
      *(undefined4 **)(puVar1 + 0x10) = dest;
      puVar1 = puVar1 + 4;
      *dest = 0x80;
      dest[1] = 0x80;
      dest[2] = 0;
      dest[3] = 0xc3000000;
      dest[4] = 0;
      dest[5] = 0x43000000;
      iVar4 = iVar2 + 1;
      Mod_SpriteTextureName(local_11c,0x100,mod->name,iVar2);
      iVar2 = GL_LoadTexture(local_11c,GLT_SPRITE,0x80,0x80,pdata,0,4,(uchar *)0x0);
      dest[6] = iVar2;
      (*qglTexParameterf)(0xde1,0x2802,10496.0);
      (*qglTexParameterf)(0xde1,0x2803,10496.0);
      pdata = pdata + 0x10000;
      iVar2 = iVar4;
    } while (iVar4 != iVar3);
  }
  mod->type = mod_sprite;
  return;
}


// R_LoadSkys  @ 001e0970
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_LoadSkys(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  ushort uVar6;
  byte *p;
  byte *pbVar7;
  FileHandle_t hFile;
  int *pLength;
  int iVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  byte *pbVar16;
  byte *pbVar17;
  char *pcVar18;
  GLint GVar19;
  byte *local_b4;
  int local_a8;
  byte *local_98;
  char local_8c [64];
  int local_4c [4];
  int local_3c;
  int local_38;
  int local_34;
  uchar *local_30;
  byte *local_2c;
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int skipBMP@[???]
                       Unresolved local var: char[64] name@[???]
                       Unresolved local var: uchar * buffer@[???]
                       Unresolved local var: qboolean printed@[???] */
  if (gLoadSky == 0) {
    if (gSkyTexNumber[0] != 0) {
      (*qglDeleteTextures)(1,(GLuint *)gSkyTexNumber);
    }
    gSkyTexNumber[0] = 0;
    if (gSkyTexNumber[1] != 0) {
      gSkyTexNumber[0] = 0;
      (*qglDeleteTextures)(1,(GLuint *)0x82c8e4);
    }
    gSkyTexNumber[1] = 0;
    if (gSkyTexNumber[2] != 0) {
      (*qglDeleteTextures)(1,(GLuint *)0x82c8e8);
    }
    gSkyTexNumber[2] = 0;
    if (gSkyTexNumber[3] != 0) {
      (*qglDeleteTextures)(1,(GLuint *)0x82c8ec);
    }
    gSkyTexNumber[3] = 0;
    if (gSkyTexNumber[4] != 0) {
      (*qglDeleteTextures)(1,(GLuint *)0x82c8f0);
    }
    gSkyTexNumber[4] = 0;
    if (gSkyTexNumber[5] == 0) {
      gSkyTexNumber[4] = 0;
      return;
    }
    (*qglDeleteTextures)(1,(GLuint *)0x82c8f4);
    gSkyTexNumber[5] = 0;
    return;
  }
  iVar12 = 1;
  if ((qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0) &&
     (gl_palette_tex.value != 0.0)) {
    GL_PaletteClearSky();
    iVar12 = 0;
  }
  p = Mem_Malloc(0x40000);
  bVar4 = false;
  iVar14 = 0;
LAB_001e0a20:
  do {
                    /* Unresolved local var: int loadedBMP@[???]
                       Unresolved local var: int palCount@[???]
                       Unresolved local var: int bmpWidth@[???]
                       Unresolved local var: int bmpHeight@[???]
                       Unresolved local var: int paletteIndex@[???]
                       Unresolved local var: uchar * packPalette@[???]
                       Unresolved local var: uchar * pImage@[???]
                       Unresolved local var: FileHandle_t hFile@[???] */
    snprintf(local_8c,0x40,"gfx/env/%s%s.bmp",0x973c84,suf[iVar14]);
    if (((iVar12 == 0) && (hFile = FS_Open(local_8c,"rb"), hFile != (FileHandle_t)0x0)) &&
       (LoadBMP8(hFile,&local_30,&local_3c,&local_2c,&local_38,&local_34), 0 < local_38 * local_34))
    {
      uVar6 = GL_PaletteAdd(local_30,true);
      if ((uVar6 & 0x8000) != 0) {
        Mem_Free(local_2c);
        Mem_Free(local_30);
        goto LAB_001e0a5a;
      }
      iVar8 = gSkyTexNumber[iVar14];
      if (iVar8 == 0) {
        iVar8 = GL_GenTexture();
        gSkyTexNumber[iVar14] = iVar8;
      }
      GL_Bind(iVar8);
      (*qglTexImage2D)(0xde1,0,0x80e5,0x100,0x100,0,0x1900,0x1401,local_2c);
      Mem_Free(local_2c);
      Mem_Free(local_30);
      bVar3 = true;
LAB_001e0c60:
      (*qglTexParameterf)(0xde1,0x2801,9729.0);
      (*qglTexParameterf)(0xde1,0x2800,9729.0);
      if (!bVar4) {
        Con_DPrintf("SKY:  ");
      }
      pLength = (int *)suf[iVar14];
      pcVar18 = movevars.skyName;
      if (bVar3) {
        Con_DPrintf("%s%s - paletted, ",0x973c84,pLength);
        bVar4 = true;
      }
      else {
        Con_DPrintf("%s%s, ",0x973c84,pLength);
        bVar4 = true;
      }
    }
    else {
LAB_001e0a5a:
                    /* Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int bpp@[???] */
                    /* Unresolved local var: int columns@[???]
                       Unresolved local var: int rows@[???]
                       Unresolved local var: int numPixels@[???]
                       Unresolved local var: int targaPixelBytes@[???]
                       Unresolved local var: uchar * pixbuf@[???]
                       Unresolved local var: int row@[???]
                       Unresolved local var: int column@[???]
                       Unresolved local var: uchar * tgafile_mem_buffer@[???]
                       Unresolved local var: uchar * p@[???]
                       Unresolved local var: uchar * end@[???]
                       Unresolved local var: int fileLen@[???]
                       Unresolved local var: int requiredBufferBytes@[???]
                       Unresolved local var: uchar * targa_rgba@[???] */
      snprintf(local_8c,0x40,"gfx/env/%s%s.tga",0x973c84,suf[iVar14]);
      pLength = local_4c;
      pbVar7 = COM_LoadFile(local_8c,5,pLength);
      if (pbVar7 != (byte *)0x0) {
        if (pbVar7 + local_4c[0] < pbVar7 + 0x14) {
          COM_FreeFile(pbVar7);
          Con_Printf("LoadTGA: file shorter than TGA file header length\n");
        }
        else {
                    /* Unresolved local var: uchar b1@[???]
                       Unresolved local var: uchar b2@[???] */
          targa_header.colormap_index = *(ushort *)(pbVar7 + 3);
          targa_header.id_length = *pbVar7;
          targa_header.colormap_type = pbVar7[1];
                    /* Unresolved local var: uchar b1@[???]
                       Unresolved local var: uchar b2@[???] */
          targa_header.image_type = pbVar7[2];
          targa_header.colormap_length = *(ushort *)(pbVar7 + 5);
                    /* Unresolved local var: uchar b1@[???]
                       Unresolved local var: uchar b2@[???] */
          targa_header.colormap_size = pbVar7[7];
          targa_header.x_origin = *(ushort *)(pbVar7 + 8);
                    /* Unresolved local var: uchar b1@[???]
                       Unresolved local var: uchar b2@[???] */
          targa_header.y_origin = *(ushort *)(pbVar7 + 10);
                    /* Unresolved local var: uchar b1@[???]
                       Unresolved local var: uchar b2@[???] */
          uVar6 = *(ushort *)(pbVar7 + 0xc);
          uVar13 = (uint)uVar6;
                    /* Unresolved local var: uchar b1@[???]
                       Unresolved local var: uchar b2@[???] */
          local_a8 = (uint)pbVar7[0xe] + (uint)pbVar7[0xf] * 0x100;
          targa_header.height = (ushort)local_a8;
          targa_header.pixel_size = pbVar7[0x10];
          targa_header.attributes = pbVar7[0x11];
          targa_header.width = uVar6;
          if ((targa_header.image_type == 10) || (targa_header.image_type == 2)) {
            if ((targa_header.colormap_type == 0) &&
               ((targa_header.pixel_size == 0x18 || (targa_header.pixel_size == 0x20)))) {
              iVar12 = local_a8 * uVar13;
              if (iVar12 < 0x20000000) {
                if (iVar12 * 4 < 0x40001) {
                  local_98 = pbVar7 + 0x12;
                  if (targa_header.id_length != 0) {
                    local_98 = local_98 + targa_header.id_length;
                  }
                  if (targa_header.image_type == 2) {
                    iVar8 = iVar12 * 3;
                    if (targa_header.pixel_size != 0x18) {
                      iVar8 = iVar12 * 4;
                    }
                    if (pbVar7 + local_4c[0] < local_98 + iVar8) {
                      COM_FreeFile(pbVar7);
                      Con_Printf("LoadTGA: file shorter than length of texture\n");
                      goto LAB_001e0ad8;
                    }
                    iVar12 = local_a8 + -1;
                    if (iVar12 != -1) {
                      local_b4 = p + (local_a8 * 4 + -4) * uVar13;
                      do {
                        if (uVar6 != 0) {
                          iVar8 = 0;
                          pbVar17 = local_b4;
                          do {
                            if (targa_header.pixel_size == '\x18') {
                              bVar10 = *local_98;
                              pbVar16 = local_98 + 1;
                              bVar1 = local_98[2];
                              local_98 = local_98 + 3;
                              pbVar17[1] = *pbVar16;
                              pbVar17[3] = 0xff;
                              *pbVar17 = bVar1;
                              pbVar17[2] = bVar10;
                              pbVar17 = pbVar17 + 4;
                            }
                            else {
                    /* Unresolved local var: uchar red@[???]
                       Unresolved local var: uchar green@[???]
                       Unresolved local var: uchar blue@[???]
                       Unresolved local var: uchar alphabyte@[???] */
                              if (targa_header.pixel_size == ' ') {
                                bVar10 = *local_98;
                                bVar1 = local_98[1];
                                pbVar16 = local_98 + 2;
                                bVar9 = local_98[3];
                                local_98 = local_98 + 4;
                                *pbVar17 = *pbVar16;
                                pbVar17[3] = bVar9;
                                pbVar17[1] = bVar1;
                                pbVar17[2] = bVar10;
                                pbVar17 = pbVar17 + 4;
                              }
                            }
                            iVar8 = iVar8 + 1;
                          } while (iVar8 < (int)uVar13);
                        }
                        iVar12 = iVar12 + -1;
                        local_b4 = local_b4 + uVar13 * -4;
                      } while (iVar12 != -1);
                    }
                  }
                  else {
                    /* Unresolved local var: uchar red@[???]
                       Unresolved local var: uchar green@[???]
                       Unresolved local var: uchar blue@[???]
                       Unresolved local var: uchar alphabyte@[???]
                       Unresolved local var: uchar packetHeader@[???]
                       Unresolved local var: uchar packetSize@[???]
                       Unresolved local var: uchar j@[???] */
                    if ((targa_header.image_type == 10) &&
                       (local_a8 = local_a8 + -1, local_a8 != -1)) {
                      bVar10 = 0;
                      bVar9 = 0;
                      bVar1 = 0;
                      bVar2 = 0;
                      do {
                        if (uVar6 != 0) {
                          pbVar17 = p + local_a8 * uVar13 * 4;
                          uVar15 = 0;
                          do {
                            pbVar16 = local_98 + 1;
                            bVar5 = (*local_98 & 0x7f) + 1;
                            bVar11 = 0;
                            if ((char)*local_98 < '\0') {
                              if (targa_header.pixel_size == '\x18') {
                                bVar10 = 0xff;
                                bVar1 = local_98[2];
                                bVar9 = local_98[1];
                                bVar2 = local_98[3];
                                pbVar16 = local_98 + 4;
                              }
                              else if (targa_header.pixel_size == ' ') {
                                bVar1 = local_98[2];
                                bVar9 = local_98[1];
                                bVar2 = local_98[3];
                                bVar10 = local_98[4];
                                pbVar16 = local_98 + 5;
                              }
                              local_98 = pbVar16;
                              bVar11 = 0;
                              do {
                                uVar15 = uVar15 + 1;
                                pbVar17[2] = bVar9;
                                pbVar17[3] = bVar10;
                                *pbVar17 = bVar2;
                                pbVar17[1] = bVar1;
                                pbVar17 = pbVar17 + 4;
                                if (uVar13 == uVar15) {
                                  if (local_a8 == 0) goto LAB_001e106c;
                                  local_a8 = local_a8 + -1;
                                  pbVar17 = p + local_a8 * uVar13 * 4;
                                  uVar15 = 0;
                                }
                                bVar11 = bVar11 + 1;
                              } while (bVar11 < bVar5);
                            }
                            else {
                              do {
                                while (targa_header.pixel_size == '\x18') {
                                  bVar1 = pbVar16[1];
                                  bVar9 = *pbVar16;
                                  bVar2 = pbVar16[2];
                                  pbVar16 = pbVar16 + 3;
                                  pbVar17[2] = bVar9;
                                  pbVar17[3] = 0xff;
                                  *pbVar17 = bVar2;
                                  pbVar17[1] = bVar1;
                                  pbVar17 = pbVar17 + 4;
                                  if (uVar13 == uVar15 + 1) goto LAB_001e12e8;
LAB_001e12a5:
                                  uVar15 = uVar15 + 1;
                                  bVar11 = bVar11 + 1;
                                  local_98 = pbVar16;
                                  if (bVar5 <= bVar11) goto LAB_001e1310;
                                }
                                if (targa_header.pixel_size == ' ') {
                                  bVar1 = pbVar16[1];
                                  bVar9 = *pbVar16;
                                  bVar2 = pbVar16[2];
                                  bVar10 = pbVar16[3];
                                  pbVar16 = pbVar16 + 4;
                                  pbVar17[2] = bVar9;
                                  *pbVar17 = bVar2;
                                  pbVar17[1] = bVar1;
                                  pbVar17[3] = bVar10;
                                  pbVar17 = pbVar17 + 4;
                                }
                                if (uVar13 != uVar15 + 1) goto LAB_001e12a5;
LAB_001e12e8:
                                if (local_a8 == 0) goto LAB_001e106c;
                                local_a8 = local_a8 + -1;
                                bVar11 = bVar11 + 1;
                                pbVar17 = p + local_a8 * uVar13 * 4;
                                uVar15 = 0;
                                local_98 = pbVar16;
                              } while (bVar11 < bVar5);
                            }
LAB_001e1310:
                          } while ((int)uVar15 < (int)uVar13);
                        }
                        local_a8 = local_a8 + -1;
                      } while (local_a8 != -1);
                    }
                  }
LAB_001e106c:
                  COM_FreeFile(pbVar7);
                  if (gl_dither.value != 0.0) {
                    iVar12 = 0;
                    pbVar7 = p;
                    do {
                      bVar10 = *pbVar7;
                      if (bVar10 < 0xfc) {
                        bVar10 = bVar10 >> 6 | bVar10;
                        *pbVar7 = bVar10;
                        *pbVar7 = texgammatable[bVar10];
                      }
                      bVar10 = pbVar7[1];
                      if (bVar10 < 0xfc) {
                        bVar10 = bVar10 >> 6 | bVar10;
                        pbVar7[1] = bVar10;
                        pbVar7[1] = texgammatable[bVar10];
                      }
                      bVar10 = pbVar7[2];
                      if (bVar10 < 0xfc) {
                        bVar10 = bVar10 >> 6 | bVar10;
                        pbVar7[2] = bVar10;
                        pbVar7[2] = texgammatable[bVar10];
                      }
                      iVar12 = iVar12 + 4;
                      pbVar7 = pbVar7 + 4;
                    } while (iVar12 != 0x40000);
                  }
                  iVar12 = gSkyTexNumber[iVar14];
                  if (iVar12 == 0) {
                    iVar12 = GL_GenTexture();
                    gSkyTexNumber[iVar14] = iVar12;
                  }
                  GL_Bind(iVar12);
                  VideoMode_GetCurrentVideoMode(&local_28,&local_24,local_20);
                  if (local_20[0] == 0x20) {
                    GVar19 = 0x8058;
                  }
                  else {
                    GVar19 = 0x8057;
                  }
                  bVar3 = false;
                  iVar12 = 1;
                  (*qglTexImage2D)(0xde1,0,GVar19,0x100,0x100,0,0x1908,0x1401,p);
                  goto LAB_001e0c60;
                }
                COM_FreeFile(pbVar7);
                pLength = (int *)(uint)targa_header.height;
                Con_Printf("LoadTGA: texture too large (%ux%u>256x256)\n",(uint)targa_header.width,
                           pLength);
              }
            }
            else {
              COM_FreeFile(pbVar7);
              Con_Printf("Texture_LoadTGA: Only 32 or 24 bit images supported (no colormaps)\n");
            }
          }
          else {
            COM_FreeFile(pbVar7);
            Con_Printf("LoadTGA: Only type 2 and 10 targa RGB images supported\n");
          }
        }
      }
LAB_001e0ad8:
      pcVar18 = local_8c;
      iVar12 = 1;
      Con_Printf("R_LoadSkys: Couldn\'t load %s\n",pcVar18,pLength);
      if (iVar14 == 0) {
        iVar8 = Q_strcmp(movevars.skyName,"desert");
        if (iVar8 == 0) {
          iVar12 = 1;
          iVar14 = iVar12;
        }
        else {
          Q_strcpy(movevars.skyName,"desert");
        }
        goto LAB_001e0a20;
      }
    }
    iVar14 = iVar14 + 1;
    if (5 < iVar14) {
      if (bVar4) {
        Con_DPrintf("done\n",pcVar18,pLength);
      }
      Mem_Free(p);
      gLoadSky = 0;
      return;
    }
  } while( true );
}


// R_LoadTextures  @ 00141d80
studiohdr_t * R_LoadTextures(model_t *psubmodel)

{
  void *pvVar1;
  int iVar2;
  model_t *pmVar3;
  char acStack_114 [4];
  char local_110 [258];
  undefined1 local_e;
  
                    /* Unresolved local var: model_t * texmodel@[???] */
  if (pstudiohdr->textureindex == 0) {
    pmVar3 = (model_t *)psubmodel->texinfo;
    if ((pmVar3 == (model_t *)0x0) || (pvVar1 = Cache_Check(&pmVar3->cache), pvVar1 == (void *)0x0))
    {
                    /* Unresolved local var: studiohdr_t * ptexturehdr@[???]
                       Unresolved local var: char[260] modelname@[???] */
      Q_strncpy(local_110,psubmodel->name,0x102);
      local_e = 0;
      iVar2 = Q_strlen(local_110);
      Q_strcpy(acStack_114 + iVar2,"T.mdl");
      pmVar3 = Mod_ForName(local_110,true,false);
      psubmodel->texinfo = (mtexinfo_t *)pmVar3;
      pvVar1 = (pmVar3->cache).data;
      Q_strncpy((char *)((int)pvVar1 + 8),local_110,0x3f);
      *(undefined1 *)((int)pvVar1 + 0x47) = 0;
    }
    return (pmVar3->cache).data;
  }
  return pstudiohdr;
}


// R_LookupColor  @ 001f19e0
short R_LookupColor(uchar r,uchar g,uchar b)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int best@[???]
                       Unresolved local var: float diff@[DW_OP_reg11(ST0)]
                       Unresolved local var: float bestdiff@[???]
                       Unresolved local var: float rf@[???]
                       Unresolved local var: float gf@[???]
                       Unresolved local var: float bf@[???] */
  iVar3 = -1;
  iVar4 = 0;
  fVar1 = 999999.0;
  do {
    fVar2 = (float)(int)((uint)r - (uint)host_basepal[iVar4 * 4 + 2]) * 0.3 *
            (float)(int)((uint)r - (uint)host_basepal[iVar4 * 4 + 2]) +
            (float)(int)((uint)g - (uint)host_basepal[iVar4 * 4 + 1]) * 0.5 *
            (float)(int)((uint)g - (uint)host_basepal[iVar4 * 4 + 1]) +
            (float)(int)((uint)b - (uint)host_basepal[iVar4 * 4]) * 0.2 *
            (float)(int)((uint)b - (uint)host_basepal[iVar4 * 4]);
    if (fVar2 < fVar1) {
      fVar1 = fVar2;
      iVar3 = iVar4;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0x100);
  return (short)iVar3;
}


// R_MarkLeaves  @ 001e4620
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_MarkLeaves(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  model_s *pmVar5;
  int local_1024;
  byte *local_1020;
  byte local_101c [4108];
  
                    /* Unresolved local var: uchar * vis@[???]
                       Unresolved local var: mnode_t * node@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: uchar[4096] solid@[???] */
  if (((r_oldviewleaf != r_viewleaf) || (r_novis.value != 0.0)) && (mirror == false)) {
    r_visframecount = r_visframecount + 1;
    r_oldviewleaf = r_viewleaf;
    if (r_novis.value == 0.0) {
      local_1020 = Mod_LeafPVS(r_viewleaf,cl.worldmodel);
    }
    else {
      local_1020 = local_101c;
      Q_memset(local_1020,0xff,(cl.worldmodel)->numleafs + 7 >> 3);
    }
    iVar1 = r_visframecount;
    local_1024 = (cl.worldmodel)->numleafs;
    if (0 < local_1024) {
      iVar4 = 0x3c;
      iVar3 = 0;
      pmVar5 = cl.worldmodel;
      do {
        if (((int)(uint)local_1020[iVar3 >> 3] >> ((byte)iVar3 & 7) & 1U) != 0) {
          iVar2 = (int)pmVar5->leafs->minmaxs + iVar4 + -8;
          do {
            if (*(int *)(iVar2 + 4) == iVar1) break;
            *(int *)(iVar2 + 4) = iVar1;
            iVar2 = *(int *)(iVar2 + 0x20);
          } while (iVar2 != 0);
          local_1024 = (cl.worldmodel)->numleafs;
          pmVar5 = cl.worldmodel;
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x3c;
      } while (iVar3 < local_1024);
    }
  }
  return;
}


// R_MarkLights  @ 001e9530
void R_MarkLights(dlight_t *light,int bit,mnode_t *node)

{
  float fVar1;
  mplane_t *pmVar2;
  mtexinfo_t *pmVar3;
  float fVar4;
  int iVar5;
  msurface_t *pmVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
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
      uVar7 = (uint)node->numsurfaces;
      if (uVar7 != 0) {
                    /* Unresolved local var: float rad@[???]
                       Unresolved local var: float minlight@[???]
                       Unresolved local var: int s@[???]
                       Unresolved local var: int t@[???]
                       Unresolved local var: int delta@[???]
                       Unresolved local var: int smax@[???]
                       Unresolved local var: int tmax@[???]
                       Unresolved local var: mtexinfo_t * tex@[???] */
        pmVar6 = (cl.worldmodel)->surfaces + node->firstsurface;
        iVar8 = 0;
        while( true ) {
          if (light->minlight <= fVar1 - ABS(fVar4)) {
            pmVar3 = pmVar6->texinfo;
            iVar9 = (int)((pmVar3->vecs[0][2] * light->origin[2] +
                           pmVar3->vecs[0][1] * light->origin[1] +
                           pmVar3->vecs[0][0] * light->origin[0] + pmVar3->vecs[0][3]) -
                         (float)pmVar6->texturemins[0]);
            iVar11 = (int)((fVar1 - ABS(fVar4)) - light->minlight);
            if ((((-iVar11 < iVar9) &&
                 (iVar10 = (int)((light->origin[2] * pmVar3->vecs[1][2] +
                                  pmVar3->vecs[1][0] * light->origin[0] +
                                  light->origin[1] * pmVar3->vecs[1][1] + pmVar3->vecs[1][3]) -
                                (float)pmVar6->texturemins[1]), -iVar11 < iVar10)) &&
                (iVar9 <= pmVar6->extents[0] + iVar11)) && (iVar10 <= iVar11 + pmVar6->extents[1]))
            {
              if (pmVar6->dlightframe != iVar5) {
                pmVar6->dlightframe = iVar5;
              }
              pmVar6->dlightbits = pmVar6->dlightbits | bit;
              uVar7 = (uint)node->numsurfaces;
            }
          }
          iVar8 = iVar8 + 1;
          if ((int)uVar7 <= iVar8) break;
          pmVar6 = pmVar6 + 1;
          fVar1 = light->radius;
        }
      }
      R_MarkLights(light,bit,node->children[0]);
    }
    node = node->children[1];
  } while( true );
}


// R_MirrorChain  @ 001e4120
void R_MirrorChain(msurface_t *s)

{
  if (mirror == false) {
    mirror = true;
    mirror_plane = s->plane;
  }
  return;
}


// R_MultiGunshot  @ 001a70e0
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
  float afStack_b4 [12];
  int iStack_84;
  float local_70;
  float local_6c;
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
  vec_t local_40 [3];
  vec_t local_34 [3];
  vec_t local_28 [6];
  
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
  VectorAngles(dir,local_28);
  AngleVectors(local_28,(vec_t *)0x0,local_34,local_40);
  if (0 < count) {
    uVar6 = 0;
    do {
      do {
        fVar7 = RandomFloat(-0.5,0.5);
        fVar8 = RandomFloat(-0.5,0.5);
        fVar8 = fVar8 + fVar7;
        fVar7 = RandomFloat(-0.5,0.5);
        fVar9 = RandomFloat(-0.5,0.5);
        fVar7 = fVar7 + fVar9;
      } while (1.0 < fVar7 * fVar7 + fVar8 * fVar8);
      iVar3 = RandomLong(0,decalCount + -1);
      VectorScale(local_34,fVar8 * *noise,&local_58);
      VectorScale(local_40,fVar7 * noise[1],&local_4c);
      local_70 = local_58 + local_4c + *dir;
      local_6c = local_54 + local_48 + dir[1];
      local_68 = local_50 + local_44 + dir[2];
      VectorScale(&local_70,4096.0,&local_64);
      local_64 = local_64 + *org;
      local_60 = local_60 + org[1];
      local_5c = local_5c + org[2];
      pmove->usehull = 2;
      PM_PlayerTrace(&local_10c,org,&local_64,1,-1);
      uVar4 = 0;
      do {
        *(undefined4 *)((int)afStack_b4 + uVar4) =
             *(undefined4 *)((int)local_10c.endpos + (uVar4 - 0x14));
        uVar4 = uVar4 + 4;
      } while (uVar4 < 0x44);
      if (afStack_b4[4] != 1.0) {
        if ((uVar6 & 2) != 0) {
          (*efx.R_RicochetSound)(afStack_b4 + 5);
        }
        (*efx.R_BulletImpactParticles)(afStack_b4 + 5);
        p_Var2 = efx.R_DecalShoot;
        if (r_decals.value != 0.0) {
          iVar1 = pmove->physents[iStack_84].info;
          iVar5 = (*efx.Draw_DecalIndex)(decalIndices[iVar3]);
          (*p_Var2)(iVar5,iVar1,0,afStack_b4 + 5,0);
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 != count);
  }
  return;
}


// R_MuzzleFlash  @ 001a7430
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
  fVar1 = (float)(type / 10) * 0.1;
  iVar6 = (type % 10) % 3;
  fVar2 = 0.5;
  if (fVar1 != 0.0) {
    fVar2 = fVar1;
  }
  iVar3 = ModelFrameCount(cl_sprite_muzzleflash[iVar6]);
  pTVar4 = (*efx.CL_TempEntAlloc)(pos1,cl_sprite_muzzleflash[iVar6]);
  if (pTVar4 != (TEMPENTITY *)0x0) {
    (pTVar4->entity).curstate.rendermode = 5;
    (pTVar4->entity).curstate.renderamt = 0xff;
    (pTVar4->entity).curstate.scale = fVar2;
    (pTVar4->entity).curstate.renderfx = 0;
    (pTVar4->entity).curstate.rendercolor.r = 0xff;
    (pTVar4->entity).curstate.rendercolor.g = 0xff;
    (pTVar4->entity).curstate.rendercolor.b = 0xff;
    (pTVar4->entity).origin[0] = *pos1;
    (pTVar4->entity).origin[1] = pos1[1];
    (pTVar4->entity).origin[2] = pos1[2];
    pTVar4->die = (float)((longdouble)0.01 + (longdouble)cl.time);
    iVar5 = RandomLong(0,iVar3 + -1);
    (pTVar4->entity).curstate.frame = (float)iVar5;
    (pTVar4->entity).angles[0] = 0.0;
    (pTVar4->entity).angles[1] = 0.0;
    (pTVar4->entity).angles[2] = 0.0;
    pTVar4->frameMax = (float)iVar3;
    if (iVar6 == 0) {
      iVar5 = 0x14;
    }
    else {
      iVar5 = 0x167;
    }
    iVar5 = RandomLong(0,iVar5);
    (pTVar4->entity).angles[2] = (float)iVar5;
    AppendTEntity(&pTVar4->entity);
    return;
  }
  return;
}


// R_NewMap  @ 0020afd0
/* WARNING: Removing unreachable block (ram,0x0020afed) */
/* WARNING: Removing unreachable block (ram,0x0020b000) */
/* WARNING: Removing unreachable block (ram,0x0020b054) */
/* WARNING: Removing unreachable block (ram,0x0020b070) */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_NewMap(void)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  model_s *pmVar6;
  
                    /* Unresolved local var: int i@[???] */
  piVar2 = d_lightstylevalue;
  uVar4 = 0;
  do {
    uVar4 = uVar4 + 1;
    *piVar2 = 0x108;
    piVar2[1] = 0x108;
    piVar2[2] = 0x108;
    piVar2[3] = 0x108;
    piVar2 = piVar2 + 4;
  } while (uVar4 < 0x40);
  Q_memset(&r_worldentity,0,3000);
  r_worldentity.model = cl.worldmodel;
  if (0 < (cl.worldmodel)->numleafs) {
    iVar3 = 0;
    iVar5 = 0;
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
  r_viewleaf = (mleaf_t *)0x0;
  R_ClearParticles();
  R_DecalInit();
  V_InitLevel();
  GL_BuildLightmaps();
  skytexturenum = -1;
  mirrortexturenum = -1;
  iVar3 = (cl.worldmodel)->numtextures;
  if (0 < iVar3) {
    iVar5 = 0;
    pmVar6 = cl.worldmodel;
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


// R_ParseParticleEffect  @ 001ea5a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_ParseParticleEffect(void)

{
  int iVar1;
  int iVar2;
  int color;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: vec3_t org@[???]
                       Unresolved local var: vec3_t dir@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int msgcount@[???]
                       Unresolved local var: int color@[???] */
  local_24 = MSG_ReadCoord(&net_message);
  local_20 = MSG_ReadCoord(&net_message);
  local_1c = MSG_ReadCoord(&net_message);
  iVar1 = MSG_ReadChar();
  local_18 = (float)iVar1 * 0.0625;
  iVar1 = MSG_ReadChar();
  local_14 = (float)iVar1 * 0.0625;
  iVar1 = MSG_ReadChar();
  local_10 = (float)iVar1 * 0.0625;
  iVar2 = MSG_ReadByte();
  color = MSG_ReadByte();
  iVar1 = 0x400;
  if (iVar2 != 0xff) {
    iVar1 = iVar2;
  }
  R_RunParticleEffect(&local_24,&local_18,color,iVar1);
  return;
}


// R_ParticleBox  @ 001a7650
void R_ParticleBox(float *mins,float *maxs,uchar r,uchar g,uchar b,float life)

{
  short sVar1;
  float local_3c;
  float local_38;
  float local_34;
  float local_2c;
  float local_28;
  float local_24;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int pcolor@[???]
                       Unresolved local var: vec3_t mmin@[???]
                       Unresolved local var: vec3_t mmax@[???]
                       Unresolved local var: vec3_t origin@[???] */
  sVar1 = R_LookupColor(r,g,b);
  local_1c = (*maxs + *mins) * 0.5;
  local_2c = *maxs - local_1c;
  local_3c = *mins - local_1c;
  local_18 = (maxs[1] + mins[1]) * 0.5;
  local_28 = maxs[1] - local_18;
  local_38 = mins[1] - local_18;
  local_14 = (maxs[2] + mins[2]) * 0.5;
  local_24 = maxs[2] - local_14;
  local_34 = mins[2] - local_14;
  PM_DrawBBox(&local_3c,&local_2c,&local_1c,(int)sVar1,life);
  return;
}


// R_ParticleBurst  @ 001eb270
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
  int local_38;
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
  local_38 = 0x20;
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
      local_28 = (fVar7 + fVar2) - ppVar4->org[0];
      local_24 = (fVar8 + fVar10) - ppVar4->org[1];
      local_20 = (fVar9 + fVar11) - ppVar4->org[2];
      fVar10 = VectorNormalize(&local_28);
      fVar2 = (float)cl.time;
      fVar11 = RandomFloat(-0.5,0.5);
      ppVar4->die = life + fVar2 + fVar11;
      VectorScale(&local_28,fVar10 / life,ppVar4->vel);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    local_38 = local_38 + -1;
  } while (local_38 != 0);
  return;
}


// R_ParticleExplosion  @ 001ea660
/* WARNING: Removing unreachable block (ram,0x001ea6e6) */

void R_ParticleExplosion(vec_t *org)

{
  particle_s **pppVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  particle_t *ppVar5;
  particle_t *ppVar6;
  int32 iVar7;
  int iVar8;
  uint uVar9;
  float fVar10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: particle_t * p@[???] */
  uVar9 = 0;
  do {
    ppVar6 = free_particles;
    ppVar5 = active_particles;
    if (free_particles == (particle_t *)0x0) {
      return;
    }
    iVar8 = 0;
    active_particles = free_particles;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar5;
    iVar4 = ramp1[0];
    ppVar6->die = (float)cl.time + 5.0;
    ppVar6->color = (short)iVar4;
    ppVar6->packedColor = 0;
    iVar7 = RandomLong(0,3);
    ppVar6->type = pt_explode2 - (uVar9 & 1);
    ppVar6->ramp = (float)iVar7;
    while( true ) {
      do {
        fVar10 = RandomFloat(-512.0,512.0);
        ppVar6->vel[iVar8] = fVar10;
        iVar8 = iVar8 + 1;
      } while (iVar8 < 3);
      fVar10 = ppVar6->vel[0];
      fVar2 = ppVar6->vel[1];
      fVar3 = ppVar6->vel[2];
      if (fVar3 * fVar3 + fVar2 * fVar2 + fVar10 * fVar10 <= 262144.0) break;
      iVar8 = 0;
    }
    uVar9 = uVar9 + 1;
    ppVar6->org[0] = fVar10 * 0.25 + *org;
    ppVar6->org[1] = fVar2 * 0.25 + org[1];
    ppVar6->org[2] = fVar3 * 0.25 + org[2];
  } while (uVar9 != 0x400);
  return;
}


// R_ParticleExplosion2  @ 001ea780
void R_ParticleExplosion2(vec_t *org,int colorStart,int colorLength)

{
  particle_s **pppVar1;
  particle_t *ppVar2;
  particle_t *ppVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: int colorMod@[???] */
  iVar5 = 0;
  do {
    ppVar3 = free_particles;
    ppVar2 = active_particles;
    if (free_particles == (particle_t *)0x0) {
      return;
    }
    active_particles = free_particles;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar2;
    iVar4 = iVar5 + 1;
    ppVar3->die = (float)((longdouble)0.3 + (longdouble)cl.time);
    ppVar3->packedColor = 0;
    ppVar3->type = pt_blob;
    ppVar3->color = (short)(iVar5 % colorLength) + (short)colorStart;
    fVar7 = *org;
    fVar6 = RandomFloat(-16.0,16.0);
    ppVar3->org[0] = fVar6 + fVar7;
    fVar7 = RandomFloat(-256.0,256.0);
    ppVar3->vel[0] = fVar7;
    fVar7 = org[1];
    fVar6 = RandomFloat(-16.0,16.0);
    ppVar3->org[1] = fVar6 + fVar7;
    fVar7 = RandomFloat(-256.0,256.0);
    ppVar3->vel[1] = fVar7;
    fVar7 = org[2];
    fVar6 = RandomFloat(-16.0,16.0);
    ppVar3->org[2] = fVar6 + fVar7;
    fVar7 = RandomFloat(-256.0,256.0);
    ppVar3->vel[2] = fVar7;
    iVar5 = iVar4;
  } while (iVar4 != 0x200);
  return;
}


// R_ParticleLine  @ 001a75e0
void R_ParticleLine(float *start,float *end,uchar r,uchar g,uchar b,float life)

{
  short sVar1;
  
                    /* Unresolved local var: int pcolor@[???] */
  sVar1 = R_LookupColor(r,g,b);
  PM_ParticleLine(start,end,(int)sVar1,life,0.0);
  return;
}


// R_PlayerSprites  @ 001a5c60
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
      iVar2 = ModelFrameCount(model);
      iVar2 = iVar2 + -1;
      if (0 < count) {
        iVar4 = 0;
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
          (pTVar3->entity).curstate.frame = 0.0;
          iVar4 = iVar4 + 1;
          pTVar3->frameMax = (float)iVar2;
        } while (iVar4 != count);
      }
    }
  }
  return;
}


// R_PolyBlend  @ 001d43a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_PolyBlend(void)

{
  byte bVar1;
  int iVar2;
  byte local_10;
  byte local_f;
  byte local_e;
  undefined1 local_d;
  
                    /* Unresolved local var: uchar[4] color@[???]
                       Unresolved local var: int alpha@[???] */
  iVar2 = V_FadeAlpha();
  if (iVar2 != 0) {
    GL_DisableMultitexture();
    (*qglDisable)(0xbc0);
    (*qglEnable)(0xbe2);
    (*qglDisable)(0xb71);
    (*qglDisable)(0xde1);
    if (((byte)cl.sf.fadeFlags & 2) == 0) {
      (*qglBlendFunc)(0x302,0x303);
      local_10 = cl.sf.fader;
      local_d = (undefined1)iVar2;
      local_f = cl.sf.fadeg;
      local_e = cl.sf.fadeb;
    }
    else {
      (*qglBlendFunc)(0,0x300);
      local_d = 0xff;
      local_10 = (byte)((cl.sf.fader - 0xff) * iVar2 + 0xfe01 >> 8);
      local_f = (byte)((cl.sf.fadeg - 0xff) * iVar2 + 0xfe01 >> 8);
      local_e = (byte)((cl.sf.fadeb - 0xff) * iVar2 + 0xfe01 >> 8);
    }
    bVar1 = (*qglIsEnabled)(0xb60);
    AllowFog::isFogEnabled = (int)bVar1;
    if (AllowFog::isFogEnabled == 1) {
      (*qglDisable)(0xb60);
    }
    (*qglViewport)(glx,gly,glwidth,SCR_CalcRefdef::h);
    (*qglMatrixMode)(0x1701);
    (*qglPushMatrix)();
    (*qglLoadIdentity)();
    (*qglOrtho)(0.0,(double)glwidth,(double)SCR_CalcRefdef::h,0.0,-99999.0,99999.0);
    (*qglMatrixMode)(0x1700);
    (*qglPushMatrix)();
    (*qglLoadIdentity)();
    (*qglDisable)(0xb44);
    (*qglColor4ubv)(&local_10);
    (*qglBegin)(7);
    (*qglVertex2f)(0.0,0.0);
    (*qglVertex2f)(0.0,(float)SCR_CalcRefdef::h);
    (*qglVertex2f)((float)glwidth,(float)SCR_CalcRefdef::h);
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
      (*qglEnable)(0xb60);
    }
  }
  return;
}


// R_PreDrawViewModel  @ 001d4160
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_PreDrawViewModel(void)

{
  int iVar1;
  cl_entity_t *pcVar2;
  cl_entity_t *pcVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???] */
  currententity = &cl.viewent;
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
    (pcVar3->curstate).animtime = cl.weaponstarttime;
    iVar1 = pcVar3->index;
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


// R_Projectile  @ 001a49d0
void R_Projectile(vec_t *origin,vec_t *velocity,int modelIndex,int life,int owner,
                 _func_void_tempent_s_ptr_pmtrace_s_ptr *hitcallback)

{
  uint uVar1;
  model_t *model;
  TEMPENTITY *pTVar2;
  int iVar3;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: TEMPENTITY * ptemp@[???]
                       Unresolved local var: model_t * model@[???]
                       Unresolved local var: vec3_t orientation@[???]
                       Unresolved local var: int frameCount@[???] */
  model = CL_GetModelByIndex(modelIndex);
  if (model != (model_t *)0x0) {
    pTVar2 = (*efx.CL_TempEntAllocHigh)(origin,model);
    if (pTVar2 == (TEMPENTITY *)0x0) {
      Con_Printf("Couldn\'t allocate temp ent in R_Projectile!\n");
    }
    else if ((owner < 0) || (cl.maxclients < owner)) {
      Con_Printf("Bad ent in R_Projectile!\n");
    }
    else {
      pTVar2->flags = pTVar2->flags | 0x7000;
      (pTVar2->entity).baseline.origin[0] = *velocity;
      (pTVar2->entity).baseline.origin[1] = velocity[1];
      (pTVar2->entity).baseline.origin[2] = velocity[2];
      pTVar2->clientIndex = (short)owner;
      if (((pTVar2->entity).model)->type == mod_sprite) {
        iVar3 = ModelFrameCount(model);
        uVar1 = pTVar2->flags;
        pTVar2->frameMax = (float)iVar3;
        pTVar2->flags = uVar1 | 0x100;
        if (iVar3 < 10) {
          (pTVar2->entity).curstate.framerate = 10.0;
          pTVar2->flags = uVar1 | 0x10100;
        }
        else {
          (pTVar2->entity).curstate.framerate = (float)(iVar3 / life);
        }
      }
      else {
        pTVar2->frameMax = 0.0;
        VectorNormalize(velocity);
        VectorAngles(velocity,&local_28);
        (pTVar2->entity).angles[0] = local_28;
        (pTVar2->entity).angles[1] = local_24;
        (pTVar2->entity).angles[2] = local_20;
      }
      (pTVar2->entity).curstate.rendermode = 0;
      (pTVar2->entity).curstate.renderfx = 0;
      (pTVar2->entity).curstate.renderamt = 0xff;
      (pTVar2->entity).baseline.renderamt = 0xff;
      pTVar2->die = (float)life + (float)cl.time;
      (pTVar2->entity).curstate.frame = 0.0;
      (pTVar2->entity).curstate.body = 0;
      (pTVar2->entity).curstate.scale = 1.0;
      (pTVar2->entity).curstate.rendercolor.r = 0xff;
      (pTVar2->entity).curstate.rendercolor.g = 0xff;
      (pTVar2->entity).curstate.rendercolor.b = 0xff;
      pTVar2->hitcallback = hitcallback;
    }
  }
  return;
}


// R_PushDlights  @ 001e9720
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_PushDlights(void)

{
  byte bVar1;
  dlight_t *light;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: dlight_t * l@[???] */
  if (gl_flashblend.value == 0.0) {
    light = cl_dlights;
    bVar1 = 0;
    r_dlightframecount = r_framecount + 1;
    do {
      if (((float)cl.time <= *(float *)(((lightstyle_t *)light)->map + 0x10)) &&
         (*(float *)(((lightstyle_t *)light)->map + 8) != 0.0)) {
        R_MarkLights(light,1 << (bVar1 & 0x1f),(cl.worldmodel)->nodes);
      }
      light = (dlight_t *)(((lightstyle_t *)light)->map + 0x24);
      bVar1 = bVar1 + 1;
    } while ((lightstyle_t *)light != cl_lightstyle);
  }
  return;
}


// R_ReadPointFile_f  @ 001ea190
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_ReadPointFile_f(void)

{
  particle_s **pppVar1;
  particle_t *ppVar2;
  particle_t *ppVar3;
  FILE *__stream;
  int iVar4;
  int iVar5;
  char local_230 [259];
  undefined1 local_12d;
  char local_12c [256];
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24 [5];
  
                    /* Unresolved local var: FILE * f@[???]
                       Unresolved local var: vec3_t org@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: char[256] base@[???] */
  if (cl.worldmodel != (model_s *)0x0) {
    COM_StripExtension((cl.worldmodel)->name,local_12c);
    snprintf(local_230,0x104,"%s.pts",local_12c);
    local_12d = 0;
    COM_FixSlashes(local_230);
    __stream = fopen(local_230,"rb");
    if (__stream == (FILE *)0x0) {
      Con_Printf("couldn\'t open %s\n",local_230);
    }
    else {
      iVar5 = 0;
      Con_Printf("Reading %s...\n",local_230);
      while( true ) {
        iVar4 = __isoc99_fscanf(__stream,"%f %f %f\n",&local_2c,&local_28,local_24);
        ppVar3 = free_particles;
        if (iVar4 != 3) break;
        iVar5 = iVar5 + 1;
        if (free_particles == (particle_t *)0x0) {
          Con_Printf("Not enough free particles\n");
          break;
        }
        free_particles->packedColor = 0;
        free_particles->die = 99999.0;
        free_particles->type = pt_static;
        ppVar2 = active_particles;
        active_particles = free_particles;
        pppVar1 = &free_particles->next;
        free_particles = free_particles->next;
        *pppVar1 = ppVar2;
        ppVar3->color = -(short)iVar5 & 0xf;
        ppVar3->vel[0] = vec3_origin[0];
        ppVar3->vel[1] = vec3_origin[1];
        ppVar3->vel[2] = vec3_origin[2];
        ppVar3->org[0] = local_2c;
        ppVar3->org[1] = local_28;
        ppVar3->org[2] = local_24[0];
      }
      fclose(__stream);
      Con_Printf("%i points read\n",iVar5);
    }
  }
  return;
}


// R_RecursiveWorldNode  @ 001e8580
void R_RecursiveWorldNode(mnode_t *node)

{
  byte bVar1;
  mplane_t *pmVar2;
  texture_t *ptVar3;
  int iVar4;
  mnode_s *pmVar5;
  float fVar6;
  int iVar7;
  qboolean qVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  msurface_t *s;
  uint uVar12;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: msurface_t * surf@[???]
                       Unresolved local var: msurface_t * * mark@[???]
                       Unresolved local var: mleaf_t * pleaf@[???]
                       Unresolved local var: double dot@[???] */
  if (node->contents == -2) {
    return;
  }
  if (node->visframe != r_visframecount) {
    return;
  }
  while( true ) {
    qVar8 = R_CullBox(node->minmaxs,node->minmaxs + 3);
    if (qVar8 != false) {
      return;
    }
    if (node->contents < 0) break;
    pmVar2 = node->plane;
    bVar1 = pmVar2->type;
    if (bVar1 == '\x01') {
      fVar6 = modelorg[1] - pmVar2->dist;
    }
    else if (bVar1 == '\0') {
      fVar6 = modelorg[0] - pmVar2->dist;
    }
    else if (bVar1 == '\x02') {
      fVar6 = modelorg[2] - pmVar2->dist;
    }
    else {
      fVar6 = (modelorg[2] * pmVar2->normal[2] +
              modelorg[1] * pmVar2->normal[1] + modelorg[0] * pmVar2->normal[0]) - pmVar2->dist;
    }
    uVar9 = (uint)(fVar6 < 0.0);
    R_RecursiveWorldNode(node->children[uVar9]);
    uVar12 = (uint)node->numsurfaces;
    if (uVar12 == 0) {
      uVar11 = uVar9 ^ 1;
    }
    else {
      uVar11 = 0;
      s = (cl.worldmodel)->surfaces + node->firstsurface;
      if ((-0.01 <= fVar6) && (uVar11 = uVar9 ^ 1, 0.01 < fVar6)) {
        uVar11 = 1;
      }
      do {
        if ((s->visframe == r_framecount) &&
           ((uVar9 = s->flags, (uVar9 & 0x80) != 0 || (((uVar9 & 2) != 0) == fVar6 < 0.0)))) {
          if (gl_texsort == false) {
            if ((uVar9 & 4) == 0) {
              if ((uVar9 & 0x10) == 0) {
                R_DrawSequentialPoly(s,0);
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
          }
          else {
            ptVar3 = s->texinfo->texture;
            if ((mirror == false) || (ptVar3 != (cl.worldmodel)->textures[mirrortexturenum])) {
              s->texturechain = ptVar3->texturechain;
              s->texinfo->texture->texturechain = s;
            }
          }
        }
        s = s + 1;
        uVar12 = uVar12 - 1;
      } while (uVar12 != 0);
    }
    node = node->children[uVar11];
    if (node->contents == -2) {
      return;
    }
    if (node->visframe != r_visframecount) {
      return;
    }
  }
  iVar4._0_2_ = node->firstsurface;
  iVar4._2_2_ = node->numsurfaces;
  pmVar5 = node->children[1];
  iVar10 = 0;
  if (iVar4 != 0) {
    do {
      *(int *)pmVar5->minmaxs[iVar10 + -2] = r_framecount;
      if (iVar10 + 1 == iVar4) break;
      iVar7 = iVar10 + -1;
      iVar10 = iVar10 + 2;
      *(int *)pmVar5->minmaxs[iVar7] = r_framecount;
    } while (iVar10 != iVar4);
  }
  if (node->children[0] == (mnode_s *)0x0) {
    return;
  }
  R_StoreEfrags((efrag_t **)node->children);
  return;
}


// R_RemoveEfrags  @ 001f2ca0
void R_RemoveEfrags(cl_entity_t *ent)

{
  efrag_s *peVar1;
  efrag_s *peVar2;
  efrag_s **ppeVar3;
  
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
      ppeVar3 = &peVar2->leaf->efrags;
      do {
        if (peVar1 == peVar2) {
          *ppeVar3 = peVar2->leafnext;
          break;
        }
        ppeVar3 = &peVar1->leafnext;
        peVar1 = peVar1->leafnext;
      } while (peVar1 != (efrag_s *)0x0);
    }
    peVar1 = peVar2->entnext;
    peVar2->entnext = cl.free_efrags;
    cl.free_efrags = peVar2;
  } while( true );
}


// R_RenderBrushPoly  @ 001e3e70
void __regparm3 R_RenderBrushPoly(msurface_t *fa)

{
  glpoly_t *pgVar1;
  float (*pafVar2) [7];
  int iVar3;
  
                    /* Unresolved local var: texture_t * t@[???]
                       Unresolved local var: uchar * base@[???]
                       Unresolved local var: int maps@[???] */
  if ((fa->flags & 0x80U) == 0) {
    if ((currententity->curstate).rendermode == 1) {
      (*qglDisable)(0xde1);
      DrawGLSolidPoly(fa->polys);
      (*qglEnable)(0xde1);
    }
    else if ((fa->flags & 0x20U) == 0) {
      pgVar1 = fa->polys;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float * v@[???] */
      (*qglBegin)(9);
      if (0 < pgVar1->numverts) {
        iVar3 = 0;
        pafVar2 = pgVar1->verts;
        do {
          iVar3 = iVar3 + 1;
          (*qglTexCoord2f)((*pafVar2)[3],(*pafVar2)[4]);
          (*qglVertex3fv)(*pafVar2);
          pafVar2 = pafVar2 + 1;
        } while (iVar3 < pgVar1->numverts);
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
      Sys_Error("Too many decal surfaces!\n");
    }
  }
  iVar3 = lightmap_bytes;
  if (((((fa->styles[0] != 0xff) &&
        ((d_lightstylevalue[fa->styles[0]] != fa->cached_light[0] ||
         ((fa->styles[1] != 0xff &&
          ((d_lightstylevalue[fa->styles[1]] != fa->cached_light[1] ||
           ((fa->styles[2] != 0xff &&
            ((d_lightstylevalue[fa->styles[2]] != fa->cached_light[2] ||
             ((fa->styles[3] != 0xff && (d_lightstylevalue[fa->styles[3]] != fa->cached_light[3]))))
            )))))))))) || (fa->dlightframe == r_framecount)) || (fa->cached_dlight != 0)) &&
     (r_dynamic.value != 0.0)) {
    lightmap_modified[fa->lightmaptexturenum] = true;
    R_BuildLightMap(fa,lightmaps +
                       (fa->light_t * 0x80 + fa->light_s) * iVar3 +
                       fa->lightmaptexturenum * iVar3 * 0x4000,iVar3 << 7);
    return;
  }
  return;
}


// R_RenderBrushPoly  @ 001e40c0
void R_RenderBrushPoly(msurface_t *fa)

{
  texture_t *ptVar1;
  
                    /* Unresolved local var: texture_t * t@[???]
                       Unresolved local var: uchar * base@[???]
                       Unresolved local var: int maps@[???] */
  c_brush_polys = c_brush_polys + 1;
  if ((fa->flags & 4) == 0) {
    ptVar1 = R_TextureAnimation(fa);
    GL_Bind(ptVar1->gl_texturenum);
    if ((fa->flags & 0x10) == 0) {
      R_RenderBrushPoly(fa);
      return;
    }
    EmitWaterPolys(fa,0);
  }
  return;
}


// R_RenderDlight  @ 001e91f0
void R_RenderDlight(dlight_t *light)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  double local_44;
  double local_3c;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: float a@[???]
                       Unresolved local var: vec3_t v@[???]
                       Unresolved local var: float rad@[???] */
  fVar1 = light->radius * 0.35;
  local_2c = light->origin[0] - r_origin[0];
  local_28 = light->origin[1] - r_origin[1];
  local_24 = light->origin[2] - r_origin[2];
  fVar5 = Length(&local_2c);
  if (fVar1 <= fVar5) {
    (*qglBegin)(6);
    (*qglColor3f)(0.2,0.1,0.0);
    local_2c = light->origin[0] - fVar1 * vpn[0];
    local_28 = light->origin[1] - fVar1 * vpn[1];
    local_24 = light->origin[2] - fVar1 * vpn[2];
    (*qglVertex3fv)(&local_2c);
    (*qglColor3f)(0.0,0.0,0.0);
    iVar3 = 0x10;
    do {
      iVar4 = iVar3 + -1;
      local_30 = (float)iVar3 * 0.0625 * 3.1415927;
      local_30 = local_30 + local_30;
      sincos((double)local_30,&local_3c,&local_44);
      fVar2 = (float)local_44;
      fVar5 = (float)local_3c;
      local_2c = fVar5 * vup[0] * fVar1 + fVar2 * vright[0] * fVar1 + light->origin[0];
      local_28 = fVar5 * vup[1] * fVar1 + fVar2 * vright[1] * fVar1 + light->origin[1];
      local_24 = fVar5 * vup[2] * fVar1 + fVar2 * vright[2] * fVar1 + light->origin[2];
      (*qglVertex3fv)(&local_2c);
      iVar3 = iVar4;
    } while (iVar4 != -1);
    (*qglEnd)();
    return;
  }
  fVar1 = light->radius * 0.0003;
                    /* Unresolved local var: float a@[???] */
  v_blend[3] = (1.0 - v_blend[3]) * fVar1 + v_blend[3];
  fVar1 = fVar1 / v_blend[3];
  fVar5 = v_blend[1] * (1.0 - fVar1);
  v_blend[0] = fVar1 + fVar5;
  v_blend[1] = fVar1 * 0.5 + fVar5;
  v_blend[2] = fVar1 * 0.0 + (1.0 - fVar1) * v_blend[2];
  return;
}


// R_RenderDlights  @ 001e9410
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_RenderDlights(void)

{
  dlight_t *light;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: dlight_t * l@[???] */
  if (gl_flashblend.value != 0.0) {
    light = cl_dlights;
    r_dlightframecount = r_framecount + 1;
    (*qglDepthMask)('\0');
    (*qglDisable)(0xde1);
    (*qglShadeModel)(0x1d01);
    (*qglEnable)(0xbe2);
    (*qglBlendFunc)(1,1);
    do {
      if (((float)cl.time <= *(float *)(((lightstyle_t *)light)->map + 0x10)) &&
         (*(float *)(((lightstyle_t *)light)->map + 8) != 0.0)) {
        R_RenderDlight(light);
      }
      light = (dlight_t *)(((lightstyle_t *)light)->map + 0x24);
    } while ((lightstyle_t *)light != cl_lightstyle);
    (*qglColor3f)(1.0,1.0,1.0);
    (*qglDisable)(0xbe2);
    (*qglEnable)(0xde1);
    (*qglBlendFunc)(0x302,0x303);
    (*qglDepthMask)('\x01');
  }
  return;
}


// R_RenderDynamicLightmaps  @ 001e35e0
void R_RenderDynamicLightmaps(msurface_t *fa)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_28;
  int local_24;
  
                    /* Unresolved local var: uchar * base@[???]
                       Unresolved local var: int maps@[???]
                       Unresolved local var: glRect_t * theRect@[???]
                       Unresolved local var: int smax@[???]
                       Unresolved local var: int tmax@[???] */
  c_brush_polys = c_brush_polys + 1;
  if ((fa->flags & 0x14) != 0) {
    return;
  }
  fa->polys->chain = lightmap_polys[fa->lightmaptexturenum];
  lightmap_polys[fa->lightmaptexturenum] = fa->polys;
  if ((((fa->styles[0] == 0xff) ||
       ((d_lightstylevalue[fa->styles[0]] == fa->cached_light[0] &&
        ((fa->styles[1] == 0xff ||
         ((d_lightstylevalue[fa->styles[1]] == fa->cached_light[1] &&
          ((fa->styles[2] == 0xff ||
           ((d_lightstylevalue[fa->styles[2]] == fa->cached_light[2] &&
            ((fa->styles[3] == 0xff || (d_lightstylevalue[fa->styles[3]] == fa->cached_light[3])))))
           ))))))))) && (fa->dlightframe != r_framecount)) && (fa->cached_dlight == 0)) {
    return;
  }
  if (r_dynamic.value == 0.0) {
    return;
  }
  lightmap_modified[fa->lightmaptexturenum] = true;
  iVar1 = fa->lightmaptexturenum;
  iVar3 = fa->light_t;
  iVar5 = lightmap_rectchange[iVar1].t;
  if (iVar3 < iVar5) {
    local_24 = 0;
    if (lightmap_rectchange[iVar1].h != 0) {
      local_24 = (iVar5 - iVar3) + lightmap_rectchange[iVar1].h;
      lightmap_rectchange[iVar1].h = local_24;
      iVar3 = fa->light_t;
    }
    lightmap_rectchange[iVar1].t = iVar3;
    iVar6 = lightmap_rectchange[iVar1].l;
    iVar4 = fa->light_s;
    iVar2 = iVar4;
    if (iVar6 <= iVar4) goto LAB_001e36ed;
  }
  else {
    iVar4 = fa->light_s;
    iVar6 = lightmap_rectchange[iVar1].l;
    local_24 = lightmap_rectchange[iVar1].h;
    iVar2 = iVar4;
    iVar3 = iVar5;
    if (iVar6 <= iVar4) {
LAB_001e36ed:
      iVar4 = iVar6;
      local_28 = lightmap_rectchange[iVar1].w;
      goto LAB_001e36f4;
    }
  }
  local_28 = 0;
  if (lightmap_rectchange[iVar1].w != 0) {
    local_28 = (iVar6 - iVar4) + lightmap_rectchange[iVar1].w;
    lightmap_rectchange[iVar1].w = local_28;
    iVar4 = fa->light_s;
  }
  lightmap_rectchange[iVar1].l = iVar4;
  iVar2 = fa->light_s;
LAB_001e36f4:
  iVar5 = ((int)fa->extents[0] >> 4) + 1;
  iVar6 = ((int)fa->extents[1] >> 4) + 1;
  if (local_28 + iVar4 < iVar5 + iVar2) {
    lightmap_rectchange[iVar1].w = iVar5 + (iVar2 - iVar4);
  }
  iVar5 = fa->light_t;
  if (local_24 + iVar3 < iVar5 + iVar6) {
    lightmap_rectchange[iVar1].h = iVar6 + (iVar5 - iVar3);
    iVar5 = fa->light_t;
  }
  R_BuildLightMap(fa,lightmaps +
                     (iVar5 * 0x80 + fa->light_s) * lightmap_bytes +
                     fa->lightmaptexturenum * lightmap_bytes * 0x4000,lightmap_bytes << 7);
  return;
}


// R_RenderFinalFog  @ 00210440
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_RenderFinalFog(void)

{
  if (gD3DMode != 1) {
    (*qglEnable)(0xb60);
    (*qglFogi)(0xb65,0x801);
    (*qglFogf)(0xb62,flFogDensity);
    (*qglHint)(0xc54,0x1102);
    (*qglFogfv)(0xb66,flFinalFogColor);
    (*qglFogf)(0xb63,flFogStart);
    (*qglFogf)(0xb64,flFogEnd);
  }
  return;
}


// R_RenderFog  @ 002102f0
void R_RenderFog(float *flFogColor,float flStart,float flEnd,BOOL bOn)

{
  if ((bOn != 0) && (0.0 < gl_fog.value)) {
    g_bUserFogOn = 1;
    flFinalFogColor[0] = *flFogColor / 255.0;
    flFinalFogColor[1] = flFogColor[1] / 255.0;
    flFinalFogColor[3] = 1.0;
    flFogStart = flStart;
    flFogEnd = flEnd;
    flFinalFogColor[2] = flFogColor[2] / 255.0;
    return;
  }
  g_bUserFogOn = 0;
  return;
}


// R_RenderScene  @ 001d5cc0
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
    R_DrawEntitiesOnList();
  }
  if (g_bUserFogOn != 0) {
    R_RenderFinalFog();
  }
  bVar1 = (*qglIsEnabled)(0xb60);
  AllowFog::isFogEnabled = (int)bVar1;
  if (AllowFog::isFogEnabled == 1) {
    (*qglDisable)(0xb60);
    ClientDLL_DrawNormalTriangles();
  }
  else {
    ClientDLL_DrawNormalTriangles();
  }
  if (AllowFog::isFogEnabled == 1) {
    (*qglEnable)(0xb60);
  }
  if ((cl.waterlevel < 3) || (r_refdef.onlyClientDraws != false)) {
    if (g_bUserFogOn == 0) {
      (*qglDisable)(0xb60);
    }
  }
  else {
    (*qglDisable)(0xb60);
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


// R_RenderView  @ 001d5e80
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
    }
    R_RenderScene();
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
    return;
  }
  return;
}


// R_ResetLatched  @ 001467b0
void R_ResetLatched(cl_entity_t *ent,qboolean full_reset)

{
  vec_t vVar1;
  model_t *mod;
  undefined4 uVar2;
  cl_entity_t *pcVar3;
  uint uVar4;
  uint uVar5;
  void *pvVar6;
  int iVar7;
  float fVar8;
  
  if (full_reset == false) {
    iVar7 = (ent->curstate).sequence;
  }
  else {
    Q_memcpy((ent->latched).prevcontroller,(ent->curstate).controller,4);
    Q_memcpy((ent->latched).prevblending,(ent->curstate).blending,2);
    pcVar3 = currententity;
                    /* Unresolved local var: float f@[???]
                       Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: cl_entity_t * oldce@[???] */
    (ent->latched).sequencetime = (ent->curstate).animtime;
    mod = ent->model;
    if ((mod == (model_t *)0x0) || (mod->type != mod_studio)) {
      iVar7 = (ent->curstate).sequence;
      fVar8 = 0.0;
    }
    else {
      pvVar6 = Mod_Extradata(mod);
      iVar7 = (ent->curstate).sequence;
      if (pvVar6 == (void *)0x0) {
        fVar8 = 0.0;
      }
      else {
        currententity = ent;
        fVar8 = CL_StudioEstimateFrame
                          ((mstudioseqdesc_t *)
                           ((int)pvVar6 + iVar7 * 0xb0 + *(int *)((int)pvVar6 + 0xa8)));
        currententity = pcVar3;
      }
    }
    (ent->latched).prevframe = fVar8;
    uVar4 = 0;
    do {
      uVar5 = uVar4;
      uVar2 = *(undefined4 *)((int)(ent->curstate).origin + (uVar5 - 0xc));
      *(undefined4 *)((int)(ent->prevstate).origin + (uVar5 - 0x10)) =
           *(undefined4 *)((int)(ent->curstate).origin + (uVar5 - 0x10));
      *(undefined4 *)((int)(ent->prevstate).origin + (uVar5 - 0xc)) = uVar2;
      uVar4 = uVar5 + 8;
    } while (uVar5 + 8 < 0x150);
    *(undefined4 *)((int)(ent->prevstate).origin + (uVar5 - 8)) =
         *(undefined4 *)((int)(ent->curstate).origin + (uVar5 - 8));
  }
  fVar8 = (float)cl.mtime[0];
  vVar1 = (ent->curstate).origin[0];
  (ent->latched).prevsequence = iVar7;
  (ent->curstate).animtime = fVar8;
  (ent->latched).prevorigin[0] = vVar1;
  vVar1 = (ent->curstate).origin[1];
  (ent->latched).prevanimtime = fVar8;
  (ent->latched).prevorigin[1] = vVar1;
  (ent->latched).prevorigin[2] = (ent->curstate).origin[2];
  (ent->latched).prevangles[0] = (ent->curstate).angles[0];
  (ent->latched).prevangles[1] = (ent->curstate).angles[1];
  (ent->latched).prevangles[2] = (ent->curstate).angles[2];
  return;
}


// R_ResetStudio  @ 00147050
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_ResetStudio(void)

{
  pStudioAPI = &studio;
  return;
}


// R_ResetSvBlending  @ 00147060
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_ResetSvBlending(void)

{
  g_pSvBlendingAPI = &svBlending;
  return;
}


// R_RicochetSound  @ 001a4160
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


// R_RicochetSprite  @ 001a6820
void R_RicochetSprite(float *pos,model_t *pmodel,float duration,float scale)

{
  vec_t vVar1;
  TEMPENTITY *pTVar2;
  int32 iVar3;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???] */
  pTVar2 = (*efx.CL_TempEntAlloc)(pos,pmodel);
  if (pTVar2 != (TEMPENTITY *)0x0) {
    (pTVar2->entity).curstate.rendermode = 3;
    (pTVar2->entity).curstate.renderfx = 0xe;
    (pTVar2->entity).curstate.renderamt = 200;
    (pTVar2->entity).baseline.renderamt = 200;
    pTVar2->flags = 0x80;
    (pTVar2->entity).baseline.origin[0] = 0.0;
    (pTVar2->entity).baseline.origin[1] = 0.0;
    (pTVar2->entity).curstate.scale = scale;
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


// R_RocketFlare  @ 001a6900
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


// R_RocketTrail  @ 001ec6f0
void R_RocketTrail(vec_t *start,vec_t *end,int type)

{
  vec_t *in;
  int iVar1;
  short sVar2;
  uint uVar3;
  float fVar4;
  particle_t *ppVar5;
  particle_t *ppVar6;
  int iVar7;
  int32 iVar8;
  int32 iVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  double local_64;
  double local_5c;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
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
  local_4c = *end - *start;
  local_48 = end[1] - start[1];
  local_44 = end[2] - start[2];
  fVar10 = VectorNormalize(&local_4c);
  if (type == 7) {
    VectorMatrix(&local_4c,&local_34,&local_28);
    iVar7 = 1;
  }
  else {
    iVar7 = 3;
    if (0x7f < type) {
      type = type + -0x80;
      iVar7 = 1;
    }
  }
  VectorScale(&local_4c,(float)iVar7,&local_4c);
  ppVar5 = active_particles;
  ppVar6 = free_particles;
  do {
    if ((fVar10 <= 0.0) || (ppVar6 == (particle_t *)0x0)) {
      active_particles = ppVar5;
      free_particles = ppVar6;
      return;
    }
    fVar10 = fVar10 - (float)iVar7;
    free_particles = ppVar6->next;
    active_particles = ppVar6;
    ppVar6->next = ppVar5;
    ppVar6->vel[0] = vec3_origin[0];
    ppVar6->vel[1] = vec3_origin[1];
    ppVar6->vel[2] = vec3_origin[2];
    ppVar6->die = (float)cl.time + 2.0;
    switch(type) {
    case 0:
      iVar9 = 3;
      iVar8 = 0;
      goto LAB_001eca60;
    case 1:
      iVar9 = 5;
      iVar8 = 2;
LAB_001eca60:
      iVar8 = RandomLong(iVar8,iVar9);
      ppVar6->ramp = (float)iVar8;
      iVar1 = ramp3[(int)(float)iVar8];
      ppVar6->type = pt_fire;
      ppVar6->color = (short)iVar1;
LAB_001ec9d4:
      fVar12 = *start;
      fVar11 = RandomFloat(-3.0,3.0);
      ppVar6->org[0] = fVar11 + fVar12;
      fVar12 = start[1];
      fVar11 = RandomFloat(-3.0,3.0);
      ppVar6->org[1] = fVar11 + fVar12;
      fVar12 = start[2];
      fVar11 = RandomFloat(-3.0,3.0);
      ppVar6->org[2] = fVar11 + fVar12;
      break;
    case 2:
      ppVar6->type = pt_grav;
      iVar8 = RandomLong(0x43,0x4a);
      ppVar6->color = (short)iVar8;
      goto LAB_001ec9d4;
    case 3:
    case 5:
      sVar2 = ((ushort)R_RocketTrail::tracercount & 4) * 2;
      ppVar6->die = (float)cl.time + 0.5;
      ppVar6->type = pt_static;
      if (type == 3) {
        ppVar6->color = sVar2 + 0x34;
      }
      else {
        ppVar6->color = sVar2 + 0xe6;
      }
      R_RocketTrail::tracercount = R_RocketTrail::tracercount + 1;
      uVar3 = R_RocketTrail::tracercount & 1;
      ppVar6->org[0] = *start;
      ppVar6->org[1] = start[1];
      ppVar6->org[2] = start[2];
      if (uVar3 == 0) {
        ppVar6->vel[0] = -local_48 * 30.0;
        ppVar6->vel[1] = local_4c * 30.0;
      }
      else {
        ppVar6->vel[0] = local_48 * 30.0;
        ppVar6->vel[1] = -local_4c * 30.0;
      }
      break;
    case 4:
      ppVar6->type = pt_grav;
      iVar8 = RandomLong(0x43,0x46);
      ppVar6->color = (short)iVar8;
      fVar12 = *start;
      fVar11 = RandomFloat(-3.0,3.0);
      ppVar6->org[0] = fVar11 + fVar12;
      fVar12 = start[1];
      fVar11 = RandomFloat(-3.0,3.0);
      ppVar6->org[1] = fVar11 + fVar12;
      fVar12 = start[2];
      fVar11 = RandomFloat(-3.0,3.0);
      ppVar6->org[2] = fVar11 + fVar12;
      fVar10 = fVar10 - 3.0;
      break;
    case 6:
      iVar8 = RandomLong(0,3);
      ppVar6->ramp = (float)iVar8;
      iVar1 = ramp3[(int)(float)iVar8];
      ppVar6->type = pt_fire;
      ppVar6->color = (short)iVar1;
      ppVar6->org[0] = *start;
      ppVar6->org[1] = start[1];
      ppVar6->org[2] = start[2];
      break;
    case 7:
                    /* Unresolved local var: float s@[???]
                       Unresolved local var: float c@[???]
                       Unresolved local var: float x@[???]
                       Unresolved local var: float y@[???] */
      iVar8 = RandomLong(0,0xffff);
      iVar9 = RandomLong(8,0x10);
      sincos((double)iVar8,&local_5c,&local_64);
      in = ppVar6->vel;
      fVar12 = (float)local_5c * (float)iVar9;
      local_50 = (float)local_64 * (float)iVar9;
      fVar4 = local_28 * local_50 + local_34 * fVar12 + *start;
      ppVar6->org[0] = fVar4;
      fVar11 = local_24 * local_50 + local_30 * fVar12 + start[1];
      ppVar6->org[1] = fVar11;
      fVar12 = local_50 * local_20 + fVar12 * local_2c + start[2];
      ppVar6->org[2] = fVar12;
      ppVar6->vel[0] = *start - fVar4;
      ppVar6->vel[1] = start[1] - fVar11;
      ppVar6->vel[2] = start[2] - fVar12;
      VectorScale(in,2.0,in);
      fVar12 = RandomFloat(96.0,111.0);
      VectorMA(in,fVar12,&local_4c,in);
      ppVar6->die = (float)cl.time + 2.0;
      ppVar6->type = pt_explode2;
      iVar8 = RandomLong(0,3);
      ppVar6->ramp = (float)iVar8;
      ppVar6->color = (short)ramp3[(int)(float)iVar8];
    }
    ppVar6->packedColor = 0;
    *start = local_4c + *start;
    start[1] = local_48 + start[1];
    start[2] = start[2] + local_44;
    ppVar5 = active_particles;
    ppVar6 = free_particles;
  } while( true );
}


// R_RotateForEntity  @ 001d2980
void R_RotateForEntity(vec_t *origin,cl_entity_t *e)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t angles@[???]
                       Unresolved local var: vec3_t modelpos@[???] */
  fVar6 = *origin;
  fVar7 = origin[1];
  fVar1 = origin[2];
  fVar8 = e->angles[0];
  fVar9 = e->angles[1];
  fVar2 = e->angles[2];
  if ((e->curstate).movetype != 0) {
                    /* Unresolved local var: float f@[???]
                       Unresolved local var: float d@[???] */
    fVar3 = (e->curstate).animtime;
    if ((fVar3 + 0.2 <= (float)cl.time) || (fVar4 = (e->latched).prevanimtime, fVar3 == fVar4)) {
      bVar5 = false;
      fVar3 = 0.0;
    }
    else {
      fVar3 = ((float)cl.time - fVar3) / (fVar3 - fVar4);
      bVar5 = 0.0 < fVar3;
    }
    fVar6 = fVar6 - ((e->latched).prevorigin[0] - e->origin[0]) * fVar3;
    fVar7 = fVar7 - ((e->latched).prevorigin[1] - e->origin[1]) * fVar3;
    fVar1 = fVar1 - ((e->latched).prevorigin[2] - e->origin[2]) * fVar3;
    if ((bVar5) && (fVar3 < 1.5)) {
      fVar3 = 1.0 - fVar3;
      fVar4 = (e->latched).prevangles[0] - e->angles[0];
      if (180.0 < fVar4) {
        fVar4 = fVar4 - 360.0;
      }
      else if (fVar4 < -180.0) {
        fVar4 = fVar4 + 360.0;
      }
      fVar8 = fVar4 * fVar3 + fVar8;
      fVar4 = (e->latched).prevangles[1] - e->angles[1];
      if (180.0 < fVar4) {
        fVar4 = fVar4 - 360.0;
      }
      else if (fVar4 < -180.0) {
        fVar4 = fVar4 + 360.0;
      }
      fVar9 = fVar4 * fVar3 + fVar9;
      fVar4 = (e->latched).prevangles[2] - e->angles[2];
      if (fVar4 <= 180.0) {
        if (fVar4 < -180.0) {
          fVar4 = fVar4 + 360.0;
        }
      }
      else {
        fVar4 = fVar4 - 360.0;
      }
      fVar2 = fVar4 * fVar3 + fVar2;
    }
  }
  (*qglTranslatef)(fVar6,fVar7,fVar1);
  (*qglRotatef)(fVar9,0.0,0.0,1.0);
  (*qglRotatef)(fVar8,0.0,1.0,0.0);
  (*qglRotatef)(fVar2,1.0,0.0,0.0);
  return;
}


// R_RunParticleEffect  @ 001ea320
void R_RunParticleEffect(vec_t *org,vec_t *dir,int color,int count)

{
  int iVar1;
  double dVar2;
  particle_t *ppVar3;
  int32 iVar4;
  particle_t *ppVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: particle_t * p@[???] */
  if ((0 < count) && (free_particles != (particle_t *)0x0)) {
    uVar6 = 0;
    ppVar5 = free_particles;
    do {
      free_particles = ppVar5->next;
      ppVar3 = ppVar5;
      ppVar5->next = active_particles;
      active_particles = ppVar3;
      dVar2 = cl.time;
      iVar1 = ramp1[0];
      if (count == 0x400) {
        ppVar5->die = (float)cl.time + 5.0;
        ppVar5->color = (short)iVar1;
        ppVar5->packedColor = 0;
        iVar4 = RandomLong(0,3);
        ppVar5->ramp = (float)iVar4;
        if ((uVar6 & 1) == 0) {
          ppVar5->type = pt_explode2;
        }
        else {
          ppVar5->type = pt_explode;
        }
        fVar8 = *org;
        fVar7 = RandomFloat(-16.0,16.0);
        ppVar5->org[0] = fVar7 + fVar8;
        fVar8 = RandomFloat(-256.0,256.0);
        ppVar5->vel[0] = fVar8;
        fVar8 = org[1];
        fVar7 = RandomFloat(-16.0,16.0);
        ppVar5->org[1] = fVar7 + fVar8;
        fVar8 = RandomFloat(-256.0,256.0);
        ppVar5->vel[1] = fVar8;
        fVar8 = org[2];
        fVar7 = RandomFloat(-16.0,16.0);
        ppVar5->org[2] = fVar7 + fVar8;
        fVar8 = RandomFloat(-256.0,256.0);
        ppVar5->vel[2] = fVar8;
        if (uVar6 == 0x3ff) {
          return;
        }
      }
      else {
        fVar8 = RandomFloat(0.0,0.4);
        ppVar5->die = (float)dVar2 + fVar8;
        iVar4 = RandomLong(0,7);
        ppVar5->packedColor = 0;
        ppVar5->type = pt_slowgrav;
        ppVar5->color = (short)iVar4 + ((ushort)color & 0xfff8);
        fVar8 = *org;
        fVar7 = RandomFloat(-8.0,8.0);
        ppVar5->org[0] = fVar7 + fVar8;
        ppVar5->vel[0] = *dir * 15.0;
        fVar8 = org[1];
        fVar7 = RandomFloat(-8.0,8.0);
        ppVar5->org[1] = fVar7 + fVar8;
        ppVar5->vel[1] = dir[1] * 15.0;
        fVar8 = org[2];
        fVar7 = RandomFloat(-8.0,8.0);
        ppVar5->org[2] = fVar7 + fVar8;
        ppVar5->vel[2] = dir[2] * 15.0;
        if (uVar6 + 1 == count) {
          return;
        }
      }
      uVar6 = uVar6 + 1;
      ppVar5 = free_particles;
    } while (free_particles != (particle_t *)0x0);
  }
  return;
}


// R_SetFrustum  @ 001d46d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_SetFrustum(void)

{
  vec_t *pvVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  byte bVar5;
  float fVar6;
  double dVar7;
  double __x;
  float degrees;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float fovx@[???]
                       Unresolved local var: float fovy@[???] */
  fVar4 = scr_fov_value;
  fVar2 = (float)SCR_CalcRefdef::h;
  fVar3 = (float)glwidth;
                    /* Unresolved local var: float a@[???]
                       Unresolved local var: float x@[???] */
  fVar6 = 90.0;
  if ((1.0 <= scr_fov_value) && (scr_fov_value <= 179.0)) {
    fVar6 = scr_fov_value;
  }
  __x = (double)((fVar6 / 360.0) * 3.1415927);
  dVar7 = tan(__x);
  degrees = (float)((ulonglong)__x >> 0x20);
  fVar6 = atanf(fVar2 / (fVar3 / (float)dVar7));
  pvVar1 = (vec_t *)(90.0 - fVar4 * 0.5);
  RotatePointAroundVector(frustum[0].normal,vup,(vec_t *)-(float)pvVar1,degrees);
  RotatePointAroundVector(frustum[1].normal,vup,pvVar1,degrees);
  pvVar1 = (vec_t *)(90.0 - ((fVar6 * 360.0) / 3.1415927) * 0.5);
  RotatePointAroundVector(frustum[2].normal,vright,pvVar1,degrees);
  RotatePointAroundVector(frustum[3].normal,vright,(vec_t *)-(float)pvVar1,degrees);
  frustum[0].type = '\x05';
  frustum[1].type = '\x05';
  frustum[2].type = '\x05';
  frustum[3].type = '\x05';
  frustum[0].dist =
       frustum[0].normal[2] * r_origin[2] +
       frustum[0].normal[1] * r_origin[1] + frustum[0].normal[0] * r_origin[0];
                    /* Unresolved local var: int bits@[???]
                       Unresolved local var: int j@[???] */
  bVar5 = frustum[0].normal[0] < 0.0 | 2;
  if (0.0 <= frustum[0].normal[1]) {
    bVar5 = frustum[0].normal[0] < 0.0;
  }
  frustum[0].signbits = bVar5 | 4;
  if (0.0 <= frustum[0].normal[2]) {
    frustum[0].signbits = bVar5;
  }
  frustum[1].dist =
       frustum[1].normal[2] * r_origin[2] +
       frustum[1].normal[1] * r_origin[1] + frustum[1].normal[0] * r_origin[0];
  bVar5 = frustum[1].normal[0] < 0.0 | 2;
  if (0.0 <= frustum[1].normal[1]) {
    bVar5 = frustum[1].normal[0] < 0.0;
  }
  frustum[1].signbits = bVar5 | 4;
  if (0.0 <= frustum[1].normal[2]) {
    frustum[1].signbits = bVar5;
  }
  frustum[2].dist =
       frustum[2].normal[2] * r_origin[2] +
       frustum[2].normal[1] * r_origin[1] + frustum[2].normal[0] * r_origin[0];
  bVar5 = frustum[2].normal[0] < 0.0 | 2;
  if (0.0 <= frustum[2].normal[1]) {
    bVar5 = frustum[2].normal[0] < 0.0;
  }
  frustum[2].signbits = bVar5 | 4;
  if (0.0 <= frustum[2].normal[2]) {
    frustum[2].signbits = bVar5;
  }
  frustum[3].dist =
       r_origin[2] * frustum[3].normal[2] +
       r_origin[1] * frustum[3].normal[1] + r_origin[0] * frustum[3].normal[0];
  bVar5 = frustum[3].normal[0] < 0.0 | 2;
  if (0.0 <= frustum[3].normal[1]) {
    bVar5 = frustum[3].normal[0] < 0.0;
  }
  frustum[3].signbits = bVar5 | 4;
  if (0.0 <= frustum[3].normal[2]) {
    frustum[3].signbits = bVar5;
  }
  return;
}


// R_SetRenderMode  @ 001e4410
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
                    /* WARNING: Could not recover jumptable at 0x001e44b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglEnable)(0xbe2);
  return;
}


// R_SetStackBase  @ 001d5e70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_SetStackBase(void)

{
  return;
}


// R_SetupAliasFrame  @ 001d3470
void R_SetupAliasFrame(int frame,aliashdr_t *paliashdr)

{
  int iVar1;
  int posenum;
  
                    /* Unresolved local var: int pose@[???]
                       Unresolved local var: int numposes@[???]
                       Unresolved local var: float interval@[???] */
  if ((frame < 0) || (paliashdr->numframes <= frame)) {
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


// R_SetupFrame  @ 001d49c0
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
    (*qglFogi)(0xb65,0x2601);
    (*qglFogfv)(0xb66,&local_1c);
    (*qglFogf)(0xb63,0.0);
    (*qglFogf)(0xb64,(float)(cshift_water.percent * -4 + 0x600));
    (*qglEnable)(0xb60);
  }
  V_CalcBlend();
  c_brush_polys = 0;
  r_cache_thrash = false;
  c_alias_polys = 0;
  return;
}


// R_SetupGL  @ 001d4c30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_SetupGL(void)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  GLsizei GVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  double dVar13;
  double dVar14;
  double local_3c;
  
                    /* Unresolved local var: float screenaspect@[???]
                       Unresolved local var: float yfov@[DW_OP_reg11(ST0)]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: int glwidth@[???]
                       Unresolved local var: int glheight@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int x2@[???]
                       Unresolved local var: int y2@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???] */
  (*qglMatrixMode)(0x1701);
  (*qglLoadIdentity)();
  uVar3 = SCR_CalcRefdef::h - (r_refdef.vrect.y + r_refdef.vrect.height);
  iVar5 = r_refdef.vrect.x - (uint)(0 < r_refdef.vrect.x);
  iVar4 = (uVar3 - 1) + (uint)(uVar3 < 0x80000000);
  if (envmap == false) {
    GVar6 = ((SCR_CalcRefdef::h - r_refdef.vrect.y) +
            (uint)(SCR_CalcRefdef::h - r_refdef.vrect.y < SCR_CalcRefdef::h)) - iVar4;
    iVar7 = (r_refdef.vrect.width + r_refdef.vrect.x +
            (uint)(r_refdef.vrect.width + r_refdef.vrect.x < glwidth)) - iVar5;
  }
  else {
    GVar6 = (GLsizei)gl_envmapsize.value;
    iVar4 = 0;
    iVar5 = 0;
    iVar7 = GVar6;
    SCR_CalcRefdef::h = GVar6;
    glwidth = GVar6;
  }
  (*qglViewport)(iVar5 + glx,iVar4 + gly,iVar7,GVar6);
  fVar2 = (float)r_refdef.vrect.width;
  fVar12 = (float)r_refdef.vrect.height;
  fVar1 = fVar2 / fVar12;
                    /* Unresolved local var: float a@[???]
                       Unresolved local var: float x@[???] */
  fVar8 = 1.0;
  if ((1.0 <= scr_fov_value) && (scr_fov_value <= 179.0)) {
    dVar14 = tan((double)((scr_fov_value / 360.0) * 3.1415927));
    fVar8 = (float)dVar14;
  }
  fVar12 = atanf(fVar12 / (fVar2 / fVar8));
  fVar12 = (fVar12 * 360.0) / 3.1415927;
  if (r_refdef.onlyClientDraws == false) {
    iVar4 = CL_IsDevOverviewMode();
    if (iVar4 != 0) {
      iVar4 = (int)(4096.0 / (gDevOverview.zoom * fVar1));
      (*qglOrtho)((double)-(int)(4096.0 / gDevOverview.zoom),
                  (double)(int)(4096.0 / gDevOverview.zoom),(double)-iVar4,(double)iVar4,
                  (double)(16000.0 - gDevOverview.z_min),(double)(16000.0 - gDevOverview.z_max));
      goto joined_r0x001d5206;
    }
    dVar13 = tan((double)((fVar12 * 3.1415927) / 360.0));
    dVar14 = (double)movevars.zmax;
  }
  else {
                    /* Unresolved local var: GLdouble xmin@[???]
                       Unresolved local var: GLdouble xmax@[???]
                       Unresolved local var: GLdouble ymin@[???]
                       Unresolved local var: GLdouble ymax@[???] */
    dVar13 = tan((double)((fVar12 * 3.1415927) / 360.0));
    dVar14 = 16000.0;
  }
                    /* Unresolved local var: GLdouble xmin@[???]
                       Unresolved local var: GLdouble xmax@[???]
                       Unresolved local var: GLdouble ymin@[???]
                       Unresolved local var: GLdouble ymax@[???] */
  local_3c = (double)fVar1;
  dVar13 = dVar13 * 4.0;
  (*qglFrustum)(-dVar13 * local_3c,dVar13 * local_3c,-dVar13,dVar13,4.0,dVar14);
joined_r0x001d5206:
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
  if (gl_flipmatrix.value == 0.0) {
    gWorldToScreen[0] =
         gProjectionMatrix[8] * r_world_matrix[2] +
         gProjectionMatrix[4] * r_world_matrix[1] + gProjectionMatrix[0] * r_world_matrix[0] + 0.0 +
         gProjectionMatrix[0xc] * r_world_matrix[3];
    gWorldToScreen[4] =
         gProjectionMatrix[8] * r_world_matrix[6] +
         gProjectionMatrix[4] * r_world_matrix[5] + gProjectionMatrix[0] * r_world_matrix[4] + 0.0 +
         gProjectionMatrix[0xc] * r_world_matrix[7];
    gWorldToScreen[8] =
         gProjectionMatrix[8] * r_world_matrix[10] +
         gProjectionMatrix[4] * r_world_matrix[9] + gProjectionMatrix[0] * r_world_matrix[8] + 0.0 +
         gProjectionMatrix[0xc] * r_world_matrix[0xb];
    gWorldToScreen[0xc] =
         gProjectionMatrix[8] * r_world_matrix[0xe] +
         gProjectionMatrix[4] * r_world_matrix[0xd] +
         gProjectionMatrix[0] * r_world_matrix[0xc] + 0.0 +
         gProjectionMatrix[0xc] * r_world_matrix[0xf];
    gWorldToScreen[1] =
         gProjectionMatrix[1] * r_world_matrix[0] + 0.0 + gProjectionMatrix[5] * r_world_matrix[1] +
         gProjectionMatrix[9] * r_world_matrix[2] + gProjectionMatrix[0xd] * r_world_matrix[3];
    gWorldToScreen[5] =
         gProjectionMatrix[1] * r_world_matrix[4] + 0.0 + gProjectionMatrix[5] * r_world_matrix[5] +
         gProjectionMatrix[9] * r_world_matrix[6] + gProjectionMatrix[0xd] * r_world_matrix[7];
    gWorldToScreen[9] =
         gProjectionMatrix[1] * r_world_matrix[8] + 0.0 + gProjectionMatrix[5] * r_world_matrix[9] +
         gProjectionMatrix[9] * r_world_matrix[10] + gProjectionMatrix[0xd] * r_world_matrix[0xb];
    gWorldToScreen[0xd] =
         gProjectionMatrix[1] * r_world_matrix[0xc] + 0.0 +
         gProjectionMatrix[5] * r_world_matrix[0xd] + gProjectionMatrix[9] * r_world_matrix[0xe] +
         gProjectionMatrix[0xd] * r_world_matrix[0xf];
    gWorldToScreen[2] =
         gProjectionMatrix[2] * r_world_matrix[0] + 0.0 + gProjectionMatrix[6] * r_world_matrix[1] +
         gProjectionMatrix[10] * r_world_matrix[2] + gProjectionMatrix[0xe] * r_world_matrix[3];
    gWorldToScreen[6] =
         gProjectionMatrix[2] * r_world_matrix[4] + 0.0 + gProjectionMatrix[6] * r_world_matrix[5] +
         gProjectionMatrix[10] * r_world_matrix[6] + gProjectionMatrix[0xe] * r_world_matrix[7];
    gWorldToScreen[10] =
         gProjectionMatrix[2] * r_world_matrix[8] + 0.0 + gProjectionMatrix[6] * r_world_matrix[9] +
         gProjectionMatrix[10] * r_world_matrix[10] + gProjectionMatrix[0xe] * r_world_matrix[0xb];
    gWorldToScreen[0xe] =
         gProjectionMatrix[2] * r_world_matrix[0xc] + 0.0 +
         gProjectionMatrix[6] * r_world_matrix[0xd] + gProjectionMatrix[10] * r_world_matrix[0xe] +
         gProjectionMatrix[0xe] * r_world_matrix[0xf];
    fVar8 = gProjectionMatrix[3] * r_world_matrix[0] + 0.0 +
            gProjectionMatrix[7] * r_world_matrix[1] + gProjectionMatrix[0xb] * r_world_matrix[2];
    fVar9 = gProjectionMatrix[3] * r_world_matrix[4] + 0.0 +
            gProjectionMatrix[7] * r_world_matrix[5] + gProjectionMatrix[0xb] * r_world_matrix[6];
    fVar10 = gProjectionMatrix[3] * r_world_matrix[8] + 0.0 +
             gProjectionMatrix[7] * r_world_matrix[9] + gProjectionMatrix[0xb] * r_world_matrix[10];
    fVar11 = gProjectionMatrix[3] * r_world_matrix[0xc] + 0.0 +
             gProjectionMatrix[7] * r_world_matrix[0xd] +
             gProjectionMatrix[0xb] * r_world_matrix[0xe];
    fVar1 = r_world_matrix[3];
    fVar12 = r_world_matrix[7];
    fVar2 = r_world_matrix[0xb];
  }
  else {
    gWorldToScreen[0] =
         gProjectionMatrix[0] * r_world_matrix[0] + 0.0 + gProjectionMatrix[1] * r_world_matrix[4] +
         gProjectionMatrix[2] * r_world_matrix[8] + gProjectionMatrix[3] * r_world_matrix[0xc];
    gWorldToScreen[4] =
         gProjectionMatrix[0] * r_world_matrix[1] + 0.0 + gProjectionMatrix[1] * r_world_matrix[5] +
         gProjectionMatrix[2] * r_world_matrix[9] + gProjectionMatrix[3] * r_world_matrix[0xd];
    gWorldToScreen[8] =
         gProjectionMatrix[0] * r_world_matrix[2] + 0.0 + gProjectionMatrix[1] * r_world_matrix[6] +
         gProjectionMatrix[2] * r_world_matrix[10] + gProjectionMatrix[3] * r_world_matrix[0xe];
    gWorldToScreen[0xc] =
         gProjectionMatrix[0] * r_world_matrix[3] + 0.0 + gProjectionMatrix[1] * r_world_matrix[7] +
         gProjectionMatrix[2] * r_world_matrix[0xb] + gProjectionMatrix[3] * r_world_matrix[0xf];
    gWorldToScreen[1] =
         gProjectionMatrix[4] * r_world_matrix[0] + 0.0 + gProjectionMatrix[5] * r_world_matrix[4] +
         gProjectionMatrix[6] * r_world_matrix[8] + gProjectionMatrix[7] * r_world_matrix[0xc];
    gWorldToScreen[5] =
         gProjectionMatrix[4] * r_world_matrix[1] + 0.0 + gProjectionMatrix[5] * r_world_matrix[5] +
         gProjectionMatrix[6] * r_world_matrix[9] + gProjectionMatrix[7] * r_world_matrix[0xd];
    gWorldToScreen[9] =
         gProjectionMatrix[4] * r_world_matrix[2] + 0.0 + gProjectionMatrix[5] * r_world_matrix[6] +
         gProjectionMatrix[6] * r_world_matrix[10] + gProjectionMatrix[7] * r_world_matrix[0xe];
    gWorldToScreen[0xd] =
         gProjectionMatrix[4] * r_world_matrix[3] + 0.0 + gProjectionMatrix[5] * r_world_matrix[7] +
         gProjectionMatrix[6] * r_world_matrix[0xb] + gProjectionMatrix[7] * r_world_matrix[0xf];
    gWorldToScreen[2] =
         gProjectionMatrix[8] * r_world_matrix[0] + 0.0 + gProjectionMatrix[9] * r_world_matrix[4] +
         gProjectionMatrix[10] * r_world_matrix[8] + gProjectionMatrix[0xb] * r_world_matrix[0xc];
    gWorldToScreen[6] =
         gProjectionMatrix[8] * r_world_matrix[1] + 0.0 + gProjectionMatrix[9] * r_world_matrix[5] +
         gProjectionMatrix[10] * r_world_matrix[9] + gProjectionMatrix[0xb] * r_world_matrix[0xd];
    gWorldToScreen[10] =
         gProjectionMatrix[8] * r_world_matrix[2] + 0.0 + gProjectionMatrix[9] * r_world_matrix[6] +
         gProjectionMatrix[10] * r_world_matrix[10] + gProjectionMatrix[0xb] * r_world_matrix[0xe];
    gWorldToScreen[0xe] =
         gProjectionMatrix[8] * r_world_matrix[3] + 0.0 + gProjectionMatrix[9] * r_world_matrix[7] +
         gProjectionMatrix[10] * r_world_matrix[0xb] + gProjectionMatrix[0xb] * r_world_matrix[0xf];
    fVar8 = gProjectionMatrix[0xc] * r_world_matrix[0] + 0.0 +
            gProjectionMatrix[0xd] * r_world_matrix[4] + gProjectionMatrix[0xe] * r_world_matrix[8];
    fVar9 = gProjectionMatrix[0xc] * r_world_matrix[1] + 0.0 +
            gProjectionMatrix[0xd] * r_world_matrix[5] + gProjectionMatrix[0xe] * r_world_matrix[9];
    fVar10 = gProjectionMatrix[0xc] * r_world_matrix[2] + 0.0 +
             gProjectionMatrix[0xd] * r_world_matrix[6] +
             gProjectionMatrix[0xe] * r_world_matrix[10];
    fVar11 = gProjectionMatrix[0xc] * r_world_matrix[3] + 0.0 +
             gProjectionMatrix[0xd] * r_world_matrix[7] +
             gProjectionMatrix[0xe] * r_world_matrix[0xb];
    fVar1 = r_world_matrix[0xc];
    fVar12 = r_world_matrix[0xd];
    fVar2 = r_world_matrix[0xe];
  }
  gWorldToScreen[3] = fVar8 + gProjectionMatrix[0xf] * fVar1;
  gWorldToScreen[7] = fVar9 + gProjectionMatrix[0xf] * fVar12;
  gWorldToScreen[0xb] = fVar10 + gProjectionMatrix[0xf] * fVar2;
  gWorldToScreen[0xf] = fVar11 + gProjectionMatrix[0xf] * r_world_matrix[0xf];
  InvertMatrix(gWorldToScreen,gScreenToWorld);
  return;
}


// R_ShowLine  @ 001eb940
void R_ShowLine(vec_t *start,vec_t *end)

{
  particle_t *ppVar1;
  particle_t *ppVar2;
  float fVar3;
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
  fVar3 = VectorNormalize(&local_18);
  VectorScale(&local_18,5.0,&local_18);
  ppVar1 = active_particles;
  ppVar2 = free_particles;
  while ((0.0 < fVar3 && (ppVar2 != (particle_t *)0x0))) {
    fVar3 = fVar3 - 5.0;
    free_particles = ppVar2->next;
    active_particles = ppVar2;
    ppVar2->next = ppVar1;
    ppVar2->vel[0] = vec3_origin[0];
    ppVar2->vel[1] = vec3_origin[1];
    ppVar2->vel[2] = vec3_origin[2];
    ppVar2->die = (float)cl.time + 30.0;
    ppVar2->color = 0x4b;
    ppVar2->packedColor = 0;
    ppVar2->type = pt_static;
    ppVar2->org[0] = *start;
    ppVar2->org[1] = start[1];
    ppVar2->org[2] = start[2];
    *start = *start + local_18;
    start[1] = start[1] + local_14;
    start[2] = start[2] + local_10;
    ppVar1 = active_particles;
    ppVar2 = free_particles;
  }
  active_particles = ppVar1;
  free_particles = ppVar2;
  return;
}


// R_SparkEffect  @ 001a64d0
void R_SparkEffect(float *pos,int count,int velocityMin,int velocityMax)

{
  _func_void_float_ptr_model_s_ptr_float_float *UNRECOVERED_JUMPTABLE;
  float fVar1;
  
  (*efx.R_SparkStreaks)(pos,count,velocityMin,velocityMax);
  UNRECOVERED_JUMPTABLE = efx.R_RicochetSprite;
  fVar1 = RandomFloat(0.5,1.0);
                    /* WARNING: Could not recover jumptable at 0x001a6540. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pos,cl_sprite_ricochet,0.1,fVar1);
  return;
}


// R_SparkShower  @ 001a55d0
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


// R_SparkStreaks  @ 001eabd0
void R_SparkStreaks(vec_t *pos,int count,int velocityMin,int velocityMax)

{
  float flHigh;
  float flLow;
  double dVar1;
  particle_t *ppVar2;
  particle_t *ppVar3;
  int iVar4;
  float fVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: particle_t * p@[???] */
  if ((0 < count) && (free_particles != (particle_t *)0x0)) {
    flHigh = (float)velocityMax;
    iVar4 = 0;
    flLow = (float)velocityMin;
    ppVar3 = free_particles;
    do {
      free_particles = ppVar3->next;
      iVar4 = iVar4 + 1;
      ppVar2 = ppVar3;
      ppVar3->next = gpActiveTracers;
      gpActiveTracers = ppVar2;
      dVar1 = cl.time;
      fVar5 = RandomFloat(0.1,0.5);
      ppVar3->die = (float)dVar1 + fVar5;
      ppVar3->color = 5;
      ppVar3->packedColor = 0xff;
      ppVar3->type = pt_grav;
      ppVar3->ramp = 0.5;
      ppVar3->org[0] = *pos;
      fVar5 = RandomFloat(flLow,flHigh);
      ppVar3->vel[0] = fVar5;
      ppVar3->org[1] = pos[1];
      fVar5 = RandomFloat(flLow,flHigh);
      ppVar3->vel[1] = fVar5;
      ppVar3->org[2] = pos[2];
      fVar5 = RandomFloat(flLow,flHigh);
      ppVar3->vel[2] = fVar5;
      if (iVar4 == count) {
        return;
      }
      ppVar3 = free_particles;
    } while (free_particles != (particle_t *)0x0);
  }
  return;
}


// R_SplitEntityOnNode  @ 001f2d10
void R_SplitEntityOnNode(mnode_t *node)

{
  byte bVar1;
  msurface_t *pmVar2;
  mplane_t *p;
  efrag_s *peVar3;
  uint uVar4;
  uint uVar5;
  
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
      uVar5 = 0;
      if (p->dist <= r_emins[bVar1]) goto LAB_001f2d2a;
      if (p->dist < r_emaxs[bVar1]) goto LAB_001f2d80;
    }
    else {
      uVar4 = BoxOnPlaneSide(r_emins,r_emaxs,p);
      if (uVar4 == 3) {
LAB_001f2d80:
        if (r_pefragtopnode == (mnode_t *)0x0) {
          r_pefragtopnode = node;
        }
        uVar5 = 2;
      }
      else {
        uVar5 = uVar4 & 2;
        if ((uVar4 & 1) == 0) {
          if (uVar5 == 0) {
            return;
          }
          goto LAB_001f2d3d;
        }
      }
LAB_001f2d2a:
      R_SplitEntityOnNode((mnode_t *)((mleaf_s *)node)->efrags);
      if (uVar5 == 0) {
        return;
      }
    }
LAB_001f2d3d:
    node = (mnode_t *)((mleaf_s *)node)->firstmarksurface;
    pmVar2 = (msurface_t *)((mleaf_s *)node)->contents;
    peVar3 = cl.free_efrags;
  } while( true );
}


// R_Spray  @ 001a5a10
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
    iVar3 = ModelFrameCount(model);
    iVar3 = iVar3 + -1;
    if (0 < count) {
      iVar5 = 0;
      do {
        pTVar4 = (*efx.CL_TempEntAlloc)(pos,model);
        if (pTVar4 == (TEMPENTITY *)0x0) {
          return;
        }
        (pTVar4->entity).baseline.renderamt = 0xff;
        (pTVar4->entity).curstate.framerate = 1.0;
        (pTVar4->entity).curstate.rendermode = rendermode;
        (pTVar4->entity).curstate.renderamt = 0xff;
        (pTVar4->entity).curstate.renderfx = 0xe;
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
        fVar7 = *dir;
        iVar5 = iVar5 + 1;
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
        (pTVar4->entity).origin[2] = vVar1;
        pTVar4->frameMax = (float)iVar3;
      } while (iVar5 != count);
    }
    return;
  }
  Con_Printf("No model %d!\n");
  return;
}


// R_SpriteColor  @ 001ab460
void R_SpriteColor(colorVec *pColor,cl_entity_t *pEntity,int alpha)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
                    /* Unresolved local var: int a@[???] */
  iVar1 = (pEntity->curstate).rendermode;
  if ((iVar1 == 3) || (iVar5 = 0x100, iVar1 == 5)) {
    uVar2 = *(uint *)&(pEntity->curstate).rendercolor;
    iVar5 = alpha;
  }
  else {
    uVar2 = *(uint *)&(pEntity->curstate).rendercolor;
  }
  if ((uVar2 & 0xffffff) != 0) {
    uVar4 = (int)((uint)(pEntity->curstate).rendercolor.r * iVar5) >> 8;
    pColor->r = uVar4;
    uVar2 = (int)((uint)(pEntity->curstate).rendercolor.g * iVar5) >> 8;
    pColor->g = uVar2;
    uVar3 = (int)((uint)(pEntity->curstate).rendercolor.b * iVar5) >> 8;
    bVar6 = filterMode != false;
    pColor->b = uVar3;
    if (bVar6) {
      pColor->r = (int)((float)uVar4 * filterColorRed);
      pColor->g = (int)((float)uVar2 * filterColorGreen);
      pColor->b = (int)((float)uVar3 * filterColorBlue);
    }
    return;
  }
  uVar2 = iVar5 * 0xff >> 8;
  pColor->b = uVar2;
  pColor->g = uVar2;
  pColor->r = uVar2;
  return;
}


// R_Sprite_Explode  @ 001a6fc0
void R_Sprite_Explode(TEMPENTITY *pTemp,float scale,int flags)

{
  float fVar1;
  
  if (pTemp != (TEMPENTITY *)0x0) {
    if ((flags & 1U) == 0) {
      (pTemp->entity).curstate.rendermode = 5;
      (pTemp->entity).curstate.renderamt = 0xb4;
    }
    else {
      (pTemp->entity).curstate.rendermode = 0;
      (pTemp->entity).curstate.renderamt = 0xff;
    }
    fVar1 = (pTemp->entity).origin[2];
    (pTemp->entity).curstate.renderfx = 0;
    (pTemp->entity).baseline.origin[2] = 8.0;
    (pTemp->entity).curstate.rendercolor.r = '\0';
    (pTemp->entity).curstate.rendercolor.g = '\0';
    (pTemp->entity).curstate.rendercolor.b = '\0';
    (pTemp->entity).origin[2] = fVar1 + 10.0;
    (pTemp->entity).curstate.scale = scale;
  }
  return;
}


// R_Sprite_Smoke  @ 001a6f40
void R_Sprite_Smoke(TEMPENTITY *pTemp,float scale)

{
  float fVar1;
  byte bVar2;
  int32 iVar3;
  
  if (pTemp != (TEMPENTITY *)0x0) {
    (pTemp->entity).curstate.renderamt = 0xff;
    (pTemp->entity).curstate.renderfx = 0;
    (pTemp->entity).curstate.rendermode = 4;
    (pTemp->entity).baseline.origin[2] = 30.0;
    iVar3 = RandomLong(0x14,0x23);
    fVar1 = (pTemp->entity).origin[2];
    bVar2 = (byte)iVar3;
    (pTemp->entity).curstate.rendercolor.r = bVar2;
    (pTemp->entity).curstate.rendercolor.g = bVar2;
    (pTemp->entity).curstate.rendercolor.b = bVar2;
    (pTemp->entity).origin[2] = fVar1 + 20.0;
    (pTemp->entity).curstate.scale = scale;
  }
  return;
}


// R_Sprite_Spray  @ 001a5810
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
    iVar1 = ModelFrameCount(model);
    if (0 < count) {
      iVar4 = 0;
      do {
        pTVar3 = (*efx.CL_TempEntAlloc)(pos,model);
        if (pTVar3 == (TEMPENTITY *)0x0) {
          return;
        }
        iVar4 = iVar4 + 1;
        (pTVar3->entity).curstate.rendermode = 4;
        (pTVar3->entity).curstate.renderamt = 0xff;
        pTVar3->flags = pTVar3->flags | 0x88;
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
      } while (iVar4 != count);
    }
    return;
  }
  Con_Printf("No model %d!\n");
  return;
}


// R_Sprite_Trail  @ 001a4bc0
void R_Sprite_Trail(int type,vec_t *start,vec_t *end,int modelIndex,int count,float life,float size,
                   float amplitude,int renderamt,float speed)

{
  float fVar1;
  float fVar2;
  model_t *model;
  int iVar3;
  TEMPENTITY *pTVar4;
  int32 iVar5;
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
    fVar2 = amplitude * 0.00390625;
    if (0 < count) {
      iVar6 = 0;
      do {
        if (iVar6 == 0) {
          VectorMA(start,0.0,&local_40,local_34);
        }
        else {
          VectorMA(start,(float)iVar6 / ((float)count - 1.0),&local_40,local_34);
        }
        pTVar4 = (*efx.CL_TempEntAlloc)(local_34,model);
        if (pTVar4 == (TEMPENTITY *)0x0) {
          return;
        }
        pTVar4->flags = pTVar4->flags | 0x8a8;
        iVar6 = iVar6 + 1;
        VectorScale(&local_28,speed,(pTVar4->entity).baseline.origin);
        fVar1 = (pTVar4->entity).baseline.origin[0];
        iVar5 = RandomLong(-0x7f,0x80);
        (pTVar4->entity).baseline.origin[0] = (float)iVar5 * fVar2 + fVar1;
        fVar1 = (pTVar4->entity).baseline.origin[1];
        iVar5 = RandomLong(-0x7f,0x80);
        (pTVar4->entity).baseline.origin[1] = (float)iVar5 * fVar2 + fVar1;
        fVar1 = (pTVar4->entity).baseline.origin[2];
        iVar5 = RandomLong(-0x7f,0x80);
        (pTVar4->entity).curstate.renderamt = renderamt;
        (pTVar4->entity).curstate.scale = size;
        (pTVar4->entity).curstate.rendermode = 3;
        (pTVar4->entity).curstate.renderfx = 0xe;
        (pTVar4->entity).baseline.origin[2] = (float)iVar5 * fVar2 + fVar1;
        fVar1 = (float)cl.time;
        fVar7 = RandomFloat(0.0,4.0);
        pTVar4->die = life + fVar1 + fVar7;
        iVar5 = RandomLong(0,iVar3 + -1);
        (pTVar4->entity).baseline.renderamt = renderamt;
        (pTVar4->entity).curstate.rendercolor.r = 0xff;
        (pTVar4->entity).curstate.rendercolor.g = 0xff;
        (pTVar4->entity).curstate.rendercolor.b = 0xff;
        (pTVar4->entity).curstate.frame = (float)iVar5;
        pTVar4->frameMax = (float)iVar3;
      } while (iVar6 != count);
    }
  }
  return;
}


// R_Sprite_WallPuff  @ 001a7050
void R_Sprite_WallPuff(TEMPENTITY *pTemp,float scale)

{
  int32 iVar1;
  
  if (pTemp != (TEMPENTITY *)0x0) {
    (pTemp->entity).curstate.renderamt = 0xff;
    (pTemp->entity).curstate.renderfx = 0;
    (pTemp->entity).curstate.rendermode = 4;
    (pTemp->entity).curstate.rendercolor.r = '\0';
    (pTemp->entity).curstate.rendercolor.g = '\0';
    (pTemp->entity).curstate.scale = scale;
    (pTemp->entity).curstate.rendercolor.b = '\0';
    pTemp->die = (float)((longdouble)0.01 + (longdouble)cl.time);
    iVar1 = RandomLong(0,0x167);
    (pTemp->entity).curstate.frame = 0.0;
    (pTemp->entity).angles[2] = (float)iVar1;
  }
  return;
}


// R_StoreEfrags  @ 001f2f10
void R_StoreEfrags(efrag_t **ppefrag)

{
  cl_entity_s *ent;
  modtype_t mVar1;
  int iVar2;
  efrag_t *peVar3;
  
  do {
    peVar3 = *ppefrag;
    if (peVar3 == (efrag_t *)0x0) {
      return;
    }
    while( true ) {
      ent = (cl_entity_s *)peVar3->entity;
      mVar1 = ent->model->type;
      if (mVar1 < mod_studio) break;
      Sys_Error("R_StoreEfrags: Bad entity type %d\n",mVar1);
      peVar3 = *ppefrag;
      if (peVar3 == (efrag_t *)0x0) {
        return;
      }
    }
    if (((ent->visframe != r_framecount) && (cl_numvisedicts < 0x200)) &&
       (iVar2 = ClientDLL_AddEntity(4,ent), iVar2 != 0)) {
      ent->visframe = r_framecount;
    }
    ppefrag = &peVar3->leafnext;
  } while( true );
}


// R_StreakSplash  @ 001eb100
void R_StreakSplash(vec_t *pos,vec_t *dir,int color,int count,float speed,int velocityMin,
                   int velocityMax)

{
  float flHigh;
  float flLow;
  double dVar1;
  float fVar2;
  particle_t *ppVar3;
  particle_t *ppVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: vec3_t initialVelocity@[???] */
  VectorScale(dir,speed,&local_28);
  if ((0 < count) && (free_particles != (particle_t *)0x0)) {
    flHigh = (float)velocityMax;
    iVar5 = 0;
    flLow = (float)velocityMin;
    ppVar4 = free_particles;
    do {
      free_particles = ppVar4->next;
      iVar5 = iVar5 + 1;
      ppVar3 = ppVar4;
      ppVar4->next = gpActiveTracers;
      gpActiveTracers = ppVar3;
      dVar1 = cl.time;
      fVar6 = RandomFloat(0.1,0.5);
      fVar2 = local_28;
      ppVar4->die = (float)dVar1 + fVar6;
      ppVar4->color = (short)color;
      ppVar4->packedColor = 0xff;
      ppVar4->type = pt_grav;
      ppVar4->ramp = 1.0;
      ppVar4->org[0] = *pos;
      fVar7 = RandomFloat(flLow,flHigh);
      fVar6 = local_24;
      ppVar4->vel[0] = fVar7 + fVar2;
      ppVar4->org[1] = pos[1];
      fVar7 = RandomFloat(flLow,flHigh);
      fVar2 = local_20;
      ppVar4->vel[1] = fVar7 + fVar6;
      ppVar4->org[2] = pos[2];
      fVar6 = RandomFloat(flLow,flHigh);
      ppVar4->vel[2] = fVar6 + fVar2;
      if (iVar5 == count) {
        return;
      }
      ppVar4 = free_particles;
    } while (free_particles != (particle_t *)0x0);
  }
  return;
}


// R_StudioAbsBB  @ 00140dd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioAbsBB(void)

{
  studiohdr_t *psVar1;
  int iVar2;
  float local_8c [4];
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
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
  vec_t local_2c [3];
  float local_20 [4];
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: float lv@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: vec_t[8][3] p@[???]
                       Unresolved local var: mstudiobone_t * pbones@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???] */
  psVar1 = pstudiohdr;
  iVar2 = (currententity->curstate).sequence * 0xb0 + pstudiohdr->seqindex;
  (*tri.RenderMode)(5);
  (*tri.SpriteTexture)(cl_sprite_white,0);
  local_38 = currententity->origin[0];
  local_34 = currententity->origin[1];
  local_30 = currententity->origin[2];
  local_8c[0] = *(float *)((int)psVar1->max + iVar2 + 8) + local_38;
  local_8c[1] = *(float *)((int)psVar1->bbmin + iVar2) + local_34;
  local_8c[2] = *(float *)((int)psVar1->bbmin + iVar2 + 4) + local_30;
  local_8c[3] = *(float *)((int)psVar1->min + iVar2 + 8) + local_38;
  local_74 = *(float *)((int)psVar1->max + iVar2 + 8) + local_38;
  local_70 = *(float *)((int)psVar1->max + iVar2) + local_34;
  local_6c = *(float *)((int)psVar1->bbmin + iVar2 + 4) + local_30;
  local_68 = *(float *)((int)psVar1->min + iVar2 + 8) + local_38;
  local_64 = *(float *)((int)psVar1->max + iVar2) + local_34;
  local_60 = *(float *)((int)psVar1->bbmin + iVar2 + 4) + local_30;
  local_5c = *(float *)((int)psVar1->max + iVar2 + 8) + local_38;
  local_58 = *(float *)((int)psVar1->bbmin + iVar2) + local_34;
  local_54 = *(float *)((int)psVar1->max + iVar2 + 4) + local_30;
  local_50 = *(float *)((int)psVar1->min + iVar2 + 8) + local_38;
  local_4c = *(float *)((int)psVar1->bbmin + iVar2) + local_34;
  local_48 = *(float *)((int)psVar1->max + iVar2 + 4) + local_30;
  local_44 = *(float *)((int)psVar1->max + iVar2 + 8) + local_38;
  local_40 = *(float *)((int)psVar1->max + iVar2) + local_34;
  local_3c = *(float *)((int)psVar1->max + iVar2 + 4) + local_30;
  local_38 = local_38 + *(float *)((int)psVar1->min + iVar2 + 8);
  local_34 = *(float *)((int)psVar1->max + iVar2) + local_34;
  local_30 = local_30 + *(float *)((int)psVar1->max + iVar2 + 4);
  local_7c = local_8c[1];
  local_78 = local_8c[2];
  (*tri.Begin)(2);
  (*tri.Color4f)(0.5,0.5,1.0,1.0);
  local_2c[2] = 0.0;
  local_2c[1] = 0.0;
  local_2c[0] = 1.0;
  R_StudioLighting(local_20,-1,0,local_2c);
  (*tri.Brightness)(local_20[0]);
  (*tri.Vertex3fv)(local_8c + boxpnt[0][0] * 3);
  (*tri.Vertex3fv)(local_8c + boxpnt[0][1] * 3);
  (*tri.Vertex3fv)(local_8c + boxpnt[0][2] * 3);
  (*tri.Vertex3fv)(local_8c + boxpnt[0][3] * 3);
  local_2c[2] = 0.0;
  local_2c[0] = 0.0;
  local_2c[1] = 1.0;
  R_StudioLighting(local_20,-1,0,local_2c);
  (*tri.Brightness)(local_20[0]);
  (*tri.Vertex3fv)(local_8c + boxpnt[1][0] * 3);
  (*tri.Vertex3fv)(local_8c + boxpnt[1][1] * 3);
  (*tri.Vertex3fv)(local_8c + boxpnt[1][2] * 3);
  (*tri.Vertex3fv)(local_8c + boxpnt[1][3] * 3);
  local_2c[1] = 0.0;
  local_2c[0] = 0.0;
  local_2c[2] = 1.0;
  R_StudioLighting(local_20,-1,0,local_2c);
  (*tri.Brightness)(local_20[0]);
  (*tri.Vertex3fv)(local_8c + boxpnt[2][0] * 3);
  (*tri.Vertex3fv)(local_8c + boxpnt[2][1] * 3);
  (*tri.Vertex3fv)(local_8c + boxpnt[2][2] * 3);
  (*tri.Vertex3fv)(local_8c + boxpnt[2][3] * 3);
  local_2c[2] = 0.0;
  local_2c[1] = 0.0;
  local_2c[0] = -1.0;
  R_StudioLighting(local_20,-1,0,local_2c);
  (*tri.Brightness)(local_20[0]);
  (*tri.Vertex3fv)(local_8c + boxpnt[3][0] * 3);
  (*tri.Vertex3fv)(local_8c + boxpnt[3][1] * 3);
  (*tri.Vertex3fv)(local_8c + boxpnt[3][2] * 3);
  (*tri.Vertex3fv)(local_8c + boxpnt[3][3] * 3);
  local_2c[2] = 0.0;
  local_2c[0] = 0.0;
  local_2c[1] = -1.0;
  R_StudioLighting(local_20,-1,0,local_2c);
  (*tri.Brightness)(local_20[0]);
  (*tri.Vertex3fv)(local_8c + boxpnt[4][0] * 3);
  (*tri.Vertex3fv)(local_8c + boxpnt[4][1] * 3);
  (*tri.Vertex3fv)(local_8c + boxpnt[4][2] * 3);
  (*tri.Vertex3fv)(local_8c + boxpnt[4][3] * 3);
  local_2c[1] = 0.0;
  local_2c[0] = 0.0;
  local_2c[2] = -1.0;
  R_StudioLighting(local_20,-1,0,local_2c);
  (*tri.Brightness)(local_20[0]);
  (*tri.Vertex3fv)(local_8c + boxpnt[5][0] * 3);
  (*tri.Vertex3fv)(local_8c + boxpnt[5][1] * 3);
  (*tri.Vertex3fv)(local_8c + boxpnt[5][2] * 3);
  (*tri.Vertex3fv)(local_8c + boxpnt[5][3] * 3);
  (*tri.End)();
  (*tri.RenderMode)(0);
  return;
}


// R_StudioAccumulateBoneVerts  @ 00146ac0
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


// R_StudioBodyVariations  @ 0013dbc0
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


// R_StudioBoundBone  @ 00146a00
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


// R_StudioBoundVertex  @ 00146940
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


// R_StudioCalcAttachments  @ 001435b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioCalcAttachments(void)

{
  vec_t *pvVar1;
  int *in1;
  int iVar2;
  int iVar3;
  vec_t *pvVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: mstudioattachment_t * pattachment@[???] */
  iVar2 = pstudiohdr->numattachments;
  if (4 < iVar2) {
    Sys_Error("Too many attachments on %s\n",currententity->model);
    iVar2 = pstudiohdr->numattachments;
  }
  pvVar4 = (vec_t *)(pstudiohdr->name + pstudiohdr->attachmentindex + -8);
  if (0 < iVar2) {
    iVar2 = 0;
    do {
      iVar3 = iVar2 + 1;
      pvVar1 = pvVar4 + 9;
      in1 = (int *)(pvVar4 + 10);
      pvVar4 = pvVar4 + 0x16;
      VectorTransform((vec_t *)in1,lighttransform[(int)*pvVar1],currententity->attachment[iVar2]);
      iVar2 = iVar3;
    } while (iVar3 < pstudiohdr->numattachments);
  }
  return;
}


// R_StudioCalcBoneAdj  @ 0013c690
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
LAB_0013c7c0:
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
        goto LAB_0013c7c0;
      }
      pcVar6 = pcVar6 + 0x18;
      adj[iVar8] = fVar2 * 0.017453292;
      iVar8 = iVar8 + 1;
      iVar9 = psVar5->numbonecontrollers;
    } while (iVar8 < iVar9);
  }
  return;
}


// R_StudioCalcBonePosition  @ 0013cac0
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
LAB_0013cbd3:
          fVar3 = (float)sVar2 * local_20->scale[0] + fVar3;
          pos[iVar11] = fVar3;
          goto LAB_0013cb82;
        }
        fVar4 = (1.0 - s) * (float)*(short *)(pbVar7 + iVar1 * 2);
        sVar2 = *(short *)(pbVar7 + iVar9 * 2 + 4);
      }
      else {
        if (iVar9 + 1 < (int)uVar10) {
          sVar2 = *(short *)(pbVar7 + uVar6 * 2);
          goto LAB_0013cbd3;
        }
        fVar4 = (1.0 - s) * (float)*(short *)(pbVar7 + uVar6 * 2);
        sVar2 = *(short *)(pbVar7 + uVar6 * 2 + 4);
      }
      fVar3 = ((float)sVar2 * s + fVar4) * local_20->scale[0] + fVar3;
      pos[iVar11] = fVar3;
    }
LAB_0013cb82:
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


// R_StudioCalcBoneQuaterion  @ 0013c910
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
          if (iVar1 < (int)(uint)pbVar8[1]) goto LAB_0013ca20;
          fVar5 = (float)*(short *)(pbVar8 + (uint)*pbVar8 * 2 + 4);
          local_2c[iVar12] = fVar5;
        }
      }
      else {
        fVar2 = (float)*(short *)(pbVar8 + uVar7 * 2);
        local_3c[iVar12] = fVar2;
        fVar5 = fVar2;
        if (iVar10 + 1 < (int)(uint)pbVar8[1]) {
LAB_0013ca20:
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


// R_StudioCalcRotations  @ 0013efd0
void R_StudioCalcRotations
               (vec3_t *pos,vec4_t *q,mstudioseqdesc_t *pseqdesc,mstudioanim_t *panim,float f)

{
  float fVar1;
  int iVar2;
  float s;
  studiohdr_t *psVar3;
  uint uVar4;
  mstudioanim_t *panim_00;
  mstudiobone_t *pbone;
  int iVar5;
  int local_4c;
  float local_3c [11];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int frame@[???]
                       Unresolved local var: mstudiobone_t * pbone@[???]
                       Unresolved local var: float s@[???]
                       Unresolved local var: float[8] adj@[???]
                       Unresolved local var: float dadt@[DW_OP_reg12(ST1)] */
  psVar3 = pstudiohdr;
  if ((float)(pseqdesc->numframes + -1) < f) {
    local_4c = 0;
    f = 0.0;
  }
  else if (f < -0.01) {
                    /* Unresolved local var: float dadt@[???] */
    local_4c = 0;
    f = -0.01;
  }
  else {
    local_4c = (int)f;
  }
  if ((r_dointerp == 0) ||
     (fVar1 = (currententity->curstate).animtime,
     fVar1 < (currententity->latched).prevanimtime + 0.01)) {
    fVar1 = 1.0;
  }
  else {
                    /* Unresolved local var: float dadt@[???] */
    fVar1 = ((float)cl.time - fVar1) / 0.1;
    if (2.0 < fVar1) {
      fVar1 = 2.0;
    }
  }
  s = f - (float)local_4c;
  iVar2 = pstudiohdr->boneindex;
  R_StudioCalcBoneAdj(fVar1,local_3c,(currententity->curstate).controller,
                      (currententity->latched).prevcontroller,(currententity->mouth).mouthopen);
  if (0 < psVar3->numbones) {
    iVar5 = 0;
    panim_00 = panim;
    pbone = (mstudiobone_t *)(psVar3->name + iVar2 + -8);
    do {
      iVar5 = iVar5 + 1;
      R_StudioCalcBoneQuaterion(local_4c,s,pbone,panim_00,local_3c,*q);
      R_StudioCalcBonePosition
                (local_4c,s,pbone,panim_00,local_3c,
                 (float *)(((int)pos - (int)panim) + (int)panim_00));
      panim_00 = panim_00 + 1;
      q = q + 1;
      pbone = pbone + 1;
    } while (iVar5 < pstudiohdr->numbones);
  }
  uVar4 = pseqdesc->motiontype;
  if ((uVar4 & 1) != 0) {
    pos[pseqdesc->motionbone][0] = 0.0;
    uVar4 = pseqdesc->motiontype;
  }
  if ((uVar4 & 2) != 0) {
    pos[pseqdesc->motionbone][1] = 0.0;
    uVar4 = pseqdesc->motiontype;
  }
  if ((uVar4 & 4) != 0) {
    pos[pseqdesc->motionbone][2] = 0.0;
    uVar4 = pseqdesc->motiontype;
  }
  fVar1 = ((1.0 - s) / (float)pseqdesc->numframes) * 0.0 * (currententity->curstate).framerate;
  if ((uVar4 & 0x40) != 0) {
    pos[pseqdesc->motionbone][0] =
         fVar1 * pseqdesc->linearmovement[0] + pos[pseqdesc->motionbone][0];
    uVar4 = pseqdesc->motiontype;
  }
  if ((uVar4 & 0x80) != 0) {
    pos[pseqdesc->motionbone][1] =
         fVar1 * pseqdesc->linearmovement[1] + pos[pseqdesc->motionbone][1];
    uVar4 = pseqdesc->motiontype;
  }
  if ((uVar4 & 0x100) != 0) {
    pos[pseqdesc->motionbone][2] =
         fVar1 * pseqdesc->linearmovement[2] + pos[pseqdesc->motionbone][2];
  }
  return;
}


// R_StudioChangePlayerModel  @ 00143050
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioChangePlayerModel(void)

{
  skin_t (*pasVar1) [11];
  int iVar2;
  int iVar3;
  cl_entity_t *pcVar4;
  skin_t *psVar5;
  
  pcVar4 = currententity;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: skin_t * pskin@[???] */
  iVar3 = r_remapindex;
  iVar2 = currententity->index;
                    /* Unresolved local var: skin_t * pskin@[???] */
  psVar5 = pDM_RemapSkin[iVar2][0];
  if ((psVar5 == (skin_t *)0x0) || (iVar2 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex];
    pasVar1 = DM_RemapSkin + r_remapindex;
    r_remapindex = (r_remapindex + 1) % 0x40;
    (*pasVar1)[0].keynum = iVar2;
    pDM_RemapSkin[iVar2][0] = psVar5;
    DM_RemapSkin[iVar3][0].topcolor = -1;
    DM_RemapSkin[iVar3][0].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar2 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar2][1];
  if ((psVar5 == (skin_t *)0x0) || (iVar2 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 1;
    pasVar1 = DM_RemapSkin + r_remapindex;
    r_remapindex = (r_remapindex + 1) % 0x40;
    (*pasVar1)[1].keynum = iVar2;
    pDM_RemapSkin[iVar2][1] = psVar5;
    DM_RemapSkin[iVar3][1].topcolor = -1;
    DM_RemapSkin[iVar3][1].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar2 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar2][2];
  if ((psVar5 == (skin_t *)0x0) || (iVar2 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 2;
    pasVar1 = DM_RemapSkin + r_remapindex;
    r_remapindex = (r_remapindex + 1) % 0x40;
    (*pasVar1)[2].keynum = iVar2;
    pDM_RemapSkin[iVar2][2] = psVar5;
    DM_RemapSkin[iVar3][2].topcolor = -1;
    DM_RemapSkin[iVar3][2].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar2 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar2][3];
  if ((psVar5 == (skin_t *)0x0) || (iVar2 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 3;
    pasVar1 = DM_RemapSkin + r_remapindex;
    r_remapindex = (r_remapindex + 1) % 0x40;
    (*pasVar1)[3].keynum = iVar2;
    pDM_RemapSkin[iVar2][3] = psVar5;
    DM_RemapSkin[iVar3][3].topcolor = -1;
    DM_RemapSkin[iVar3][3].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar2 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar2][4];
  if ((psVar5 == (skin_t *)0x0) || (iVar2 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 4;
    pasVar1 = DM_RemapSkin + r_remapindex;
    r_remapindex = (r_remapindex + 1) % 0x40;
    (*pasVar1)[4].keynum = iVar2;
    pDM_RemapSkin[iVar2][4] = psVar5;
    DM_RemapSkin[iVar3][4].topcolor = -1;
    DM_RemapSkin[iVar3][4].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar2 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar2][5];
  if ((psVar5 == (skin_t *)0x0) || (iVar2 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 5;
    pasVar1 = DM_RemapSkin + r_remapindex;
    r_remapindex = (r_remapindex + 1) % 0x40;
    (*pasVar1)[5].keynum = iVar2;
    pDM_RemapSkin[iVar2][5] = psVar5;
    DM_RemapSkin[iVar3][5].topcolor = -1;
    DM_RemapSkin[iVar3][5].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar2 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar2][6];
  if ((psVar5 == (skin_t *)0x0) || (iVar2 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 6;
    pasVar1 = DM_RemapSkin + r_remapindex;
    r_remapindex = (r_remapindex + 1) % 0x40;
    (*pasVar1)[6].keynum = iVar2;
    pDM_RemapSkin[iVar2][6] = psVar5;
    DM_RemapSkin[iVar3][6].topcolor = -1;
    DM_RemapSkin[iVar3][6].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar2 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar2][7];
  if ((psVar5 == (skin_t *)0x0) || (iVar2 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 7;
    pasVar1 = DM_RemapSkin + r_remapindex;
    r_remapindex = (r_remapindex + 1) % 0x40;
    (*pasVar1)[7].keynum = iVar2;
    pDM_RemapSkin[iVar2][7] = psVar5;
    DM_RemapSkin[iVar3][7].topcolor = -1;
    DM_RemapSkin[iVar3][7].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar2 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar2][8];
  if ((psVar5 == (skin_t *)0x0) || (iVar2 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 8;
    pasVar1 = DM_RemapSkin + r_remapindex;
    r_remapindex = (r_remapindex + 1) % 0x40;
    (*pasVar1)[8].keynum = iVar2;
    pDM_RemapSkin[iVar2][8] = psVar5;
    DM_RemapSkin[iVar3][8].topcolor = -1;
    DM_RemapSkin[iVar3][8].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar2 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar2][9];
  if ((psVar5 == (skin_t *)0x0) || (iVar2 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 9;
    pasVar1 = DM_RemapSkin + r_remapindex;
    r_remapindex = (r_remapindex + 1) % 0x40;
    (*pasVar1)[9].keynum = iVar2;
    pDM_RemapSkin[iVar2][9] = psVar5;
    DM_RemapSkin[iVar3][9].topcolor = -1;
    DM_RemapSkin[iVar3][9].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  iVar3 = r_remapindex;
  iVar2 = pcVar4->index;
  psVar5 = pDM_RemapSkin[iVar2][10];
  if ((psVar5 == (skin_t *)0x0) || (iVar2 != psVar5->keynum)) {
    psVar5 = DM_RemapSkin[r_remapindex] + 10;
    r_remapindex = (r_remapindex + 1) % 0x40;
    pDM_RemapSkin[iVar2][10] = psVar5;
    DM_RemapSkin[iVar3][10].keynum = iVar2;
    DM_RemapSkin[iVar3][10].topcolor = -1;
    DM_RemapSkin[iVar3][10].bottomcolor = -1;
  }
  psVar5->topcolor = -1;
  psVar5->bottomcolor = -1;
  return;
}


// R_StudioCheckBBox  @ 0013e410
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean R_StudioCheckBBox(void)

{
  studiohdr_t *psVar1;
  int iVar2;
  qboolean qVar3;
  mplane_t local_60;
  float local_4c;
  float local_48;
  float local_44;
  float local_3c;
  float local_38;
  float local_34;
  vec_t local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: mplane_t plane@[???]
                       Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???] */
  iVar2 = VectorCompare(vec3_origin,pstudiohdr->bbmin);
  if (iVar2 == 0) {
    local_4c = pstudiohdr->bbmin[0] + currententity->origin[0];
    local_48 = pstudiohdr->bbmin[1] + currententity->origin[1];
    local_44 = pstudiohdr->bbmin[2] + currententity->origin[2];
    local_3c = currententity->origin[0] + pstudiohdr->bbmax[0];
    local_38 = currententity->origin[1] + pstudiohdr->bbmax[1];
    local_34 = currententity->origin[2] + pstudiohdr->bbmax[2];
  }
  else {
    iVar2 = VectorCompare(vec3_origin,pstudiohdr->min);
    if (iVar2 == 0) {
      local_4c = pstudiohdr->min[0] + currententity->origin[0];
      local_48 = pstudiohdr->min[1] + currententity->origin[1];
      local_44 = pstudiohdr->min[2] + currententity->origin[2];
      local_3c = currententity->origin[0] + pstudiohdr->max[0];
      local_38 = currententity->origin[1] + pstudiohdr->max[1];
      local_34 = currententity->origin[2] + pstudiohdr->max[2];
    }
    else {
      local_4c = currententity->origin[0] - 16.0;
      local_48 = currententity->origin[1] - 16.0;
      local_44 = currententity->origin[2] - 16.0;
      local_3c = currententity->origin[0] + 16.0;
      local_38 = currententity->origin[1] + 16.0;
      local_34 = currententity->origin[2] + 16.0;
    }
  }
  psVar1 = pstudiohdr;
  iVar2 = (currententity->curstate).sequence;
  if (iVar2 < pstudiohdr->numseq) {
    iVar2 = iVar2 * 0xb0;
  }
  else {
    iVar2 = 0;
    (currententity->curstate).sequence = 0;
  }
                    /* Unresolved local var: vec3_t p1@[???]
                       Unresolved local var: vec3_t p2@[???] */
  iVar2 = iVar2 + psVar1->seqindex;
  local_2c = *(vec_t *)((int)psVar1->max + iVar2 + 8);
  local_28 = *(undefined4 *)((int)psVar1->bbmin + iVar2);
  local_24 = *(undefined4 *)((int)psVar1->bbmin + iVar2 + 4);
  R_StudioTransformVector(&local_2c,&local_1c);
  if (local_1c < local_4c) {
    local_4c = local_1c;
  }
  if (local_3c < local_1c) {
    local_3c = local_1c;
  }
  if (local_18 < local_48) {
    local_48 = local_18;
  }
  if (local_38 < local_18) {
    local_38 = local_18;
  }
  if (local_14 < local_44) {
    local_44 = local_14;
  }
  if (local_34 < local_14) {
    local_34 = local_14;
  }
  local_2c = *(vec_t *)((int)psVar1->min + iVar2 + 8);
  local_28 = *(undefined4 *)((int)psVar1->bbmin + iVar2);
  local_24 = *(undefined4 *)((int)psVar1->bbmin + iVar2 + 4);
  R_StudioTransformVector(&local_2c,&local_1c);
  if (local_1c < local_4c) {
    local_4c = local_1c;
  }
  if (local_3c < local_1c) {
    local_3c = local_1c;
  }
  if (local_18 < local_48) {
    local_48 = local_18;
  }
  if (local_38 < local_18) {
    local_38 = local_18;
  }
  if (local_14 < local_44) {
    local_44 = local_14;
  }
  if (local_34 < local_14) {
    local_34 = local_14;
  }
  local_2c = *(vec_t *)((int)psVar1->max + iVar2 + 8);
  local_28 = *(undefined4 *)((int)psVar1->max + iVar2);
  local_24 = *(undefined4 *)((int)psVar1->bbmin + iVar2 + 4);
  R_StudioTransformVector(&local_2c,&local_1c);
  if (local_1c < local_4c) {
    local_4c = local_1c;
  }
  if (local_3c < local_1c) {
    local_3c = local_1c;
  }
  if (local_18 < local_48) {
    local_48 = local_18;
  }
  if (local_38 < local_18) {
    local_38 = local_18;
  }
  if (local_14 < local_44) {
    local_44 = local_14;
  }
  if (local_34 < local_14) {
    local_34 = local_14;
  }
  local_2c = *(vec_t *)((int)psVar1->min + iVar2 + 8);
  local_28 = *(undefined4 *)((int)psVar1->max + iVar2);
  local_24 = *(undefined4 *)((int)psVar1->bbmin + iVar2 + 4);
  R_StudioTransformVector(&local_2c,&local_1c);
  if (local_1c < local_4c) {
    local_4c = local_1c;
  }
  if (local_3c < local_1c) {
    local_3c = local_1c;
  }
  if (local_18 < local_48) {
    local_48 = local_18;
  }
  if (local_38 < local_18) {
    local_38 = local_18;
  }
  if (local_14 < local_44) {
    local_44 = local_14;
  }
  if (local_34 < local_14) {
    local_34 = local_14;
  }
  local_2c = *(vec_t *)((int)psVar1->max + iVar2 + 8);
  local_28 = *(undefined4 *)((int)psVar1->bbmin + iVar2);
  local_24 = *(undefined4 *)((int)psVar1->max + iVar2 + 4);
  R_StudioTransformVector(&local_2c,&local_1c);
  if (local_1c < local_4c) {
    local_4c = local_1c;
  }
  if (local_3c < local_1c) {
    local_3c = local_1c;
  }
  if (local_18 < local_48) {
    local_48 = local_18;
  }
  if (local_38 < local_18) {
    local_38 = local_18;
  }
  if (local_14 < local_44) {
    local_44 = local_14;
  }
  if (local_34 < local_14) {
    local_34 = local_14;
  }
  local_2c = *(vec_t *)((int)psVar1->min + iVar2 + 8);
  local_28 = *(undefined4 *)((int)psVar1->bbmin + iVar2);
  local_24 = *(undefined4 *)((int)psVar1->max + iVar2 + 4);
  R_StudioTransformVector(&local_2c,&local_1c);
  if (local_1c < local_4c) {
    local_4c = local_1c;
  }
  if (local_3c < local_1c) {
    local_3c = local_1c;
  }
  if (local_18 < local_48) {
    local_48 = local_18;
  }
  if (local_38 < local_18) {
    local_38 = local_18;
  }
  if (local_14 < local_44) {
    local_44 = local_14;
  }
  if (local_34 < local_14) {
    local_34 = local_14;
  }
  local_2c = *(vec_t *)((int)psVar1->max + iVar2 + 8);
  local_28 = *(undefined4 *)((int)psVar1->max + iVar2);
  local_24 = *(undefined4 *)((int)psVar1->max + iVar2 + 4);
  R_StudioTransformVector(&local_2c,&local_1c);
  if (local_1c < local_4c) {
    local_4c = local_1c;
  }
  if (local_3c < local_1c) {
    local_3c = local_1c;
  }
  if (local_18 < local_48) {
    local_48 = local_18;
  }
  if (local_38 < local_18) {
    local_38 = local_18;
  }
  if (local_14 < local_44) {
    local_44 = local_14;
  }
  if (local_34 < local_14) {
    local_34 = local_14;
  }
  local_2c = *(vec_t *)((int)psVar1->min + iVar2 + 8);
  local_28 = *(undefined4 *)((int)psVar1->max + iVar2);
  local_24 = *(undefined4 *)((int)psVar1->max + iVar2 + 4);
  R_StudioTransformVector(&local_2c,&local_1c);
  if (local_1c < local_4c) {
    local_4c = local_1c;
  }
  if (local_3c < local_1c) {
    local_3c = local_1c;
  }
  if (local_18 < local_48) {
    local_48 = local_18;
  }
  if (local_38 < local_18) {
    local_38 = local_18;
  }
  if (local_14 < local_44) {
    local_44 = local_14;
  }
  if (local_34 < local_14) {
    local_34 = local_14;
  }
  qVar3 = Host_IsSinglePlayerGame();
  if ((qVar3 == false) && (r_cullsequencebox.value != 0.0)) {
    qVar3 = R_CullBox(&local_4c,&local_3c);
    return (uint)(qVar3 == false);
  }
  local_60.normal[0] = vpn[0];
  local_60.type = '\x05';
  local_60.normal[1] = vpn[1];
  local_60.normal[2] = vpn[2];
  local_60.dist = vpn[2] * r_origin[2] + vpn[1] * r_origin[1] + vpn[0] * r_origin[0];
  iVar2 = SignbitsForPlane(&local_60);
  local_60.signbits = (byte)iVar2;
  iVar2 = BoxOnPlaneSide(&local_4c,&local_3c,&local_60);
  return (uint)(iVar2 != 2);
}


// R_StudioChrome  @ 00141b10
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
    r_chromeup[bone][1] = local_38 * fVar6 + local_3c * fVar5 + local_40 * fVar4;
    fVar7 = lighttransform[bone][0][2];
    fVar8 = lighttransform[bone][1][2];
    fVar9 = lighttransform[bone][2][2];
    r_chromeup[bone][2] = local_38 * fVar9 + local_3c * fVar8 + local_40 * fVar7;
    r_chromeright[bone][0] = fVar3 * local_2c + fVar2 * local_30 + fVar1 * local_34;
    r_chromeright[bone][1] = fVar6 * local_2c + fVar5 * local_30 + fVar4 * local_34;
    chromeage[bone] = r_smodels_total;
    r_chromeright[bone][2] = local_2c * fVar9 + local_30 * fVar8 + local_34 * fVar7;
  }
  *pchrome = (int)((normal[2] * r_chromeright[bone][2] +
                    normal[1] * r_chromeright[bone][1] + *normal * r_chromeright[bone][0] + 1.0) *
                   32.0 * 1024.0);
  pchrome[1] = (int)((normal[2] * r_chromeup[bone][2] +
                      normal[1] * r_chromeup[bone][1] + *normal * r_chromeup[bone][0] + 1.0) * 32.0
                    * 1024.0);
  return;
}


// R_StudioClientEvents  @ 0013f3f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioClientEvents(void)

{
  int *piVar1;
  vec_t vVar2;
  float fVar3;
  float fVar4;
  studiohdr_t *psVar5;
  dlight_t *pdVar6;
  mstudioevent_s *event;
  cl_entity_t *pcVar7;
  int iVar8;
  mstudioseqdesc_t *pseqdesc;
  int iVar9;
  float fVar10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: mstudioevent_t * pevent@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: float flStart@[???]
                       Unresolved local var: float flEnd@[???] */
  psVar5 = pstudiohdr;
  iVar9 = pstudiohdr->seqindex;
  iVar8 = (currententity->curstate).sequence;
  if (cl.time != cl.oldtime) {
    pcVar7 = currententity;
    if (((currententity->curstate).effects & 2) != 0) {
                    /* Unresolved local var: dlight_t * el@[DW_OP_reg0(EAX)] */
      if (g_bIsTerrorStrike == 0) {
                    /* Unresolved local var: dlight_t * el@[???] */
        pdVar6 = CL_AllocElight(0);
        pdVar6->origin[0] = currententity->attachment[0][0];
        pcVar7 = currententity;
        pdVar6->origin[1] = currententity->attachment[0][1];
        vVar2 = pcVar7->attachment[0][2];
        pdVar6->radius = 16.0;
        pdVar6->decay = 320.0;
        pdVar6->origin[2] = vVar2;
        pdVar6->die = (float)((longdouble)0.05 + (longdouble)cl.time);
        (pdVar6->color).r = 0xff;
        (pdVar6->color).g = 0xc0;
        (pdVar6->color).b = '@';
      }
      else {
        pdVar6 = CL_AllocDlight(0);
        pdVar6->origin[0] = currententity->attachment[0][0];
        pcVar7 = currententity;
        pdVar6->origin[1] = currententity->attachment[0][1];
        vVar2 = pcVar7->attachment[0][2];
        pdVar6->radius = 300.0;
        pdVar6->origin[2] = vVar2;
        pdVar6->die = (float)((longdouble)0.05 + (longdouble)cl.time);
        (pdVar6->color).r = 0xff;
        (pdVar6->color).g = 0xc0;
        (pdVar6->color).b = 0x80;
      }
      piVar1 = &(pcVar7->curstate).effects;
      *piVar1 = *piVar1 & 0xfffffffd;
    }
    pseqdesc = (mstudioseqdesc_t *)(psVar5->name + iVar9 + iVar8 * 0xb0 + -8);
    iVar9 = pseqdesc->numevents;
    if (iVar9 != 0) {
      event = (mstudioevent_s *)(pstudiohdr->name + pseqdesc->eventindex + -8);
      fVar10 = CL_StudioEstimateFrame(pseqdesc);
      fVar3 = fVar10 - (pcVar7->curstate).framerate * (float)host_frametime * pseqdesc->fps;
      fVar4 = fVar3;
      if (((pcVar7->latched).sequencetime == (pcVar7->curstate).animtime) &&
         (fVar4 = -0.01, (pseqdesc->flags & 1) != 0)) {
        fVar4 = fVar3;
      }
      if (0 < iVar9) {
        iVar8 = 0;
        do {
          if (((4999 < event->event) && (fVar4 < (float)event->frame)) &&
             ((float)event->frame <= fVar10)) {
            ClientDLL_StudioEvent(event,currententity);
            iVar9 = pseqdesc->numevents;
          }
          iVar8 = iVar8 + 1;
          event = event + 1;
        } while (iVar8 < iVar9);
      }
    }
  }
  return;
}


// R_StudioComputeBounds  @ 00146bd0
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


// R_StudioDrawBones  @ 00140600
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioDrawBones(void)

{
  int iVar1;
  vec_t vVar2;
  studiohdr_t *psVar3;
  float *pfVar4;
  int iVar5;
  int local_d8;
  vec_t *local_d4;
  float local_cc [4];
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
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  vec_t local_5c [6];
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20 [4];
  
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
  psVar3 = pstudiohdr;
  iVar1 = pstudiohdr->boneindex;
  (*tri.SpriteTexture)(cl_sprite_white,0);
  iVar5 = pstudiohdr->numbones;
  if (0 < iVar5) {
    local_d4 = (vec_t *)(psVar3->name + iVar1 + 0x18);
    pfVar4 = lighttransform[0][0] + 3;
    local_d8 = 0;
    do {
      vVar2 = *local_d4;
      if (vVar2 != -NAN) {
        local_6c = *pfVar4 - lighttransform[(int)vVar2][0][3];
        local_5c[2] = 1.0;
        local_5c[1] = 1.0;
        local_5c[0] = 1.0;
        local_68 = pfVar4[4] - lighttransform[(int)vVar2][1][3];
        local_64 = pfVar4[8] - lighttransform[(int)vVar2][2][3];
        if (local_68 < local_6c) {
          if (local_6c <= local_64) goto LAB_00140da8;
          local_5c[0] = 0.0;
        }
        else if (local_68 <= local_64) {
LAB_00140da8:
          local_5c[2] = 0.0;
        }
        else {
          local_5c[1] = 0.0;
        }
        CrossProduct(&local_6c,local_5c,&local_38);
        VectorNormalize(&local_38);
        CrossProduct(&local_6c,&local_38,&local_2c);
        VectorNormalize(&local_2c);
        VectorScale(&local_38,2.0,&local_38);
        VectorScale(&local_2c,2.0,&local_2c);
        local_78 = lighttransform[(int)vVar2][0][3];
        local_74 = lighttransform[(int)vVar2][1][3];
        local_70 = lighttransform[(int)vVar2][2][3];
        local_84 = local_78 + local_38;
        local_80 = local_34 + local_74;
        local_7c = local_30 + local_70;
        local_9c = local_2c + local_84;
        local_98 = local_28 + local_80;
        local_94 = local_24 + local_7c;
        local_cc[0] = local_9c + local_6c;
        local_cc[1] = local_98 + local_68;
        local_cc[2] = local_94 + local_64;
        local_78 = local_78 - local_38;
        local_74 = local_74 - local_34;
        local_70 = local_70 - local_30;
        local_90 = local_2c + local_78;
        local_8c = local_28 + local_74;
        local_88 = local_24 + local_70;
        local_cc[3] = local_6c + local_90;
        local_bc = local_68 + local_8c;
        local_b8 = local_64 + local_88;
        local_84 = local_84 - local_2c;
        local_80 = local_80 - local_28;
        local_7c = local_7c - local_24;
        local_b4 = local_6c + local_84;
        local_b0 = local_68 + local_80;
        local_ac = local_64 + local_7c;
        local_78 = local_78 - local_2c;
        local_74 = local_74 - local_28;
        local_70 = local_70 - local_24;
        local_a8 = local_6c + local_78;
        local_a4 = local_68 + local_74;
        local_a0 = local_64 + local_70;
        VectorNormalize(&local_6c);
        VectorNormalize(&local_38);
        VectorNormalize(&local_2c);
        (*tri.Begin)(2);
        (*tri.Color4f)(1.0,1.0,1.0,1.0);
        (*tri.TexCoord2f)(0.0,0.0);
        local_44 = local_38;
        local_40 = local_34;
        local_3c = local_30;
        R_StudioLighting(local_20,-1,0,&local_44);
        (*tri.Brightness)(local_20[0]);
        (*tri.Vertex3fv)(local_cc + boxpnt[0][0] * 3);
        (*tri.Vertex3fv)(local_cc + boxpnt[0][1] * 3);
        (*tri.Vertex3fv)(local_cc + boxpnt[0][2] * 3);
        (*tri.Vertex3fv)(local_cc + boxpnt[0][3] * 3);
        local_44 = local_2c;
        local_40 = local_28;
        local_3c = local_24;
        R_StudioLighting(local_20,-1,0,&local_44);
        (*tri.Brightness)(local_20[0]);
        (*tri.Vertex3fv)(local_cc + boxpnt[1][0] * 3);
        (*tri.Vertex3fv)(local_cc + boxpnt[1][1] * 3);
        (*tri.Vertex3fv)(local_cc + boxpnt[1][2] * 3);
        (*tri.Vertex3fv)(local_cc + boxpnt[1][3] * 3);
        local_44 = local_6c;
        local_40 = local_68;
        local_3c = local_64;
        R_StudioLighting(local_20,-1,0,&local_44);
        (*tri.Brightness)(local_20[0]);
        (*tri.Vertex3fv)(local_cc + boxpnt[2][0] * 3);
        (*tri.Vertex3fv)(local_cc + boxpnt[2][1] * 3);
        (*tri.Vertex3fv)(local_cc + boxpnt[2][2] * 3);
        (*tri.Vertex3fv)(local_cc + boxpnt[2][3] * 3);
        VectorScale(&local_38,-1.0,&local_44);
        R_StudioLighting(local_20,-1,0,&local_44);
        (*tri.Brightness)(local_20[0]);
        (*tri.Vertex3fv)(local_cc + boxpnt[3][0] * 3);
        (*tri.Vertex3fv)(local_cc + boxpnt[3][1] * 3);
        (*tri.Vertex3fv)(local_cc + boxpnt[3][2] * 3);
        (*tri.Vertex3fv)(local_cc + boxpnt[3][3] * 3);
        VectorScale(&local_2c,-1.0,&local_44);
        R_StudioLighting(local_20,-1,0,&local_44);
        (*tri.Brightness)(local_20[0]);
        (*tri.Vertex3fv)(local_cc + boxpnt[4][0] * 3);
        (*tri.Vertex3fv)(local_cc + boxpnt[4][1] * 3);
        (*tri.Vertex3fv)(local_cc + boxpnt[4][2] * 3);
        (*tri.Vertex3fv)(local_cc + boxpnt[4][3] * 3);
        VectorScale(&local_6c,-1.0,&local_44);
        R_StudioLighting(local_20,-1,0,&local_44);
        (*tri.Brightness)(local_20[0]);
        (*tri.Vertex3fv)(local_cc + boxpnt[5][0] * 3);
        (*tri.Vertex3fv)(local_cc + boxpnt[5][1] * 3);
        (*tri.Vertex3fv)(local_cc + boxpnt[5][2] * 3);
        (*tri.Vertex3fv)(local_cc + boxpnt[5][3] * 3);
        (*tri.End)();
        iVar5 = pstudiohdr->numbones;
      }
      local_d8 = local_d8 + 1;
      pfVar4 = pfVar4 + 0xc;
      local_d4 = local_d4 + 0x1c;
    } while (local_d8 < iVar5);
  }
  return;
}


// R_StudioDrawHulls  @ 001412e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioDrawHulls(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  vec_t local_8c [6];
  vec_t local_74 [3];
  vec_t local_68 [3];
  vec_t local_5c [3];
  vec_t local_50 [3];
  vec_t local_44 [3];
  vec_t local_38 [3];
  vec_t local_2c;
  int local_28;
  int local_24;
  float local_20 [4];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: float lv@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: vec_t[8][3] p@[???]
                       Unresolved local var: mstudiobbox_t * pbbox@[???] */
  pcVar3 = pstudiohdr->name + pstudiohdr->hitboxindex + -8;
  (*tri.SpriteTexture)(cl_sprite_white,0);
  if (0 < pstudiohdr->numhitboxes) {
    iVar2 = 0;
    do {
      local_2c = *(vec_t *)(pcVar3 + 0x14);
      local_28 = *(int *)(pcVar3 + 0x18);
      local_24 = *(int *)(pcVar3 + 0x1c);
      VectorTransform(&local_2c,lighttransform[*(int *)pcVar3],local_8c);
      local_2c = *(vec_t *)(pcVar3 + 8);
      local_28 = *(int *)(pcVar3 + 0x18);
      local_24 = *(int *)(pcVar3 + 0x1c);
      VectorTransform(&local_2c,lighttransform[*(int *)pcVar3],local_8c + 3);
      local_2c = *(vec_t *)(pcVar3 + 0x14);
      local_28 = *(int *)(pcVar3 + 0xc);
      local_24 = *(int *)(pcVar3 + 0x1c);
      VectorTransform(&local_2c,lighttransform[*(int *)pcVar3],local_74);
      local_2c = *(vec_t *)(pcVar3 + 8);
      local_28 = *(int *)(pcVar3 + 0xc);
      local_24 = *(int *)(pcVar3 + 0x1c);
      VectorTransform(&local_2c,lighttransform[*(int *)pcVar3],local_68);
      local_2c = *(vec_t *)(pcVar3 + 0x14);
      local_28 = *(int *)(pcVar3 + 0x18);
      local_24 = *(int *)(pcVar3 + 0x10);
      VectorTransform(&local_2c,lighttransform[*(int *)pcVar3],local_5c);
      local_2c = *(vec_t *)(pcVar3 + 8);
      local_28 = *(int *)(pcVar3 + 0x18);
      local_24 = *(int *)(pcVar3 + 0x10);
      VectorTransform(&local_2c,lighttransform[*(int *)pcVar3],local_50);
      local_2c = *(vec_t *)(pcVar3 + 0x14);
      local_28 = *(int *)(pcVar3 + 0xc);
      local_24 = *(int *)(pcVar3 + 0x10);
      VectorTransform(&local_2c,lighttransform[*(int *)pcVar3],local_44);
      local_2c = *(vec_t *)(pcVar3 + 8);
      local_28 = *(int *)(pcVar3 + 0xc);
      local_24 = *(int *)(pcVar3 + 0x10);
      VectorTransform(&local_2c,lighttransform[*(int *)pcVar3],local_38);
      (*tri.Begin)(2);
      iVar1 = *(int *)(pcVar3 + 4) % 8;
      (*tri.Color4f)(hullcolor[iVar1][0],hullcolor[iVar1][1],hullcolor[iVar1][2],1.0);
      (*tri.TexCoord2f)(0.0,0.0);
      local_24 = 0;
      local_28 = 0;
      local_2c = 1.0;
      R_StudioLighting(local_20,*(int *)pcVar3,0,&local_2c);
      (*tri.Brightness)(local_20[0]);
      (*tri.Vertex3fv)(local_8c + boxpnt[0][0] * 3);
      (*tri.Vertex3fv)(local_8c + boxpnt[0][1] * 3);
      (*tri.Vertex3fv)(local_8c + boxpnt[0][2] * 3);
      (*tri.Vertex3fv)(local_8c + boxpnt[0][3] * 3);
      local_24 = 0;
      local_2c = 0.0;
      local_28 = 0x3f800000;
      R_StudioLighting(local_20,*(int *)pcVar3,0,&local_2c);
      (*tri.Brightness)(local_20[0]);
      (*tri.Vertex3fv)(local_8c + boxpnt[1][0] * 3);
      (*tri.Vertex3fv)(local_8c + boxpnt[1][1] * 3);
      (*tri.Vertex3fv)(local_8c + boxpnt[1][2] * 3);
      (*tri.Vertex3fv)(local_8c + boxpnt[1][3] * 3);
      local_28 = 0;
      local_2c = 0.0;
      local_24 = 0x3f800000;
      R_StudioLighting(local_20,*(int *)pcVar3,0,&local_2c);
      (*tri.Brightness)(local_20[0]);
      (*tri.Vertex3fv)(local_8c + boxpnt[2][0] * 3);
      (*tri.Vertex3fv)(local_8c + boxpnt[2][1] * 3);
      (*tri.Vertex3fv)(local_8c + boxpnt[2][2] * 3);
      (*tri.Vertex3fv)(local_8c + boxpnt[2][3] * 3);
      local_24 = 0;
      local_28 = 0;
      local_2c = -1.0;
      R_StudioLighting(local_20,*(int *)pcVar3,0,&local_2c);
      (*tri.Brightness)(local_20[0]);
      (*tri.Vertex3fv)(local_8c + boxpnt[3][0] * 3);
      (*tri.Vertex3fv)(local_8c + boxpnt[3][1] * 3);
      (*tri.Vertex3fv)(local_8c + boxpnt[3][2] * 3);
      (*tri.Vertex3fv)(local_8c + boxpnt[3][3] * 3);
      local_24 = 0;
      local_2c = 0.0;
      local_28 = 0xbf800000;
      R_StudioLighting(local_20,*(int *)pcVar3,0,&local_2c);
      (*tri.Brightness)(local_20[0]);
      (*tri.Vertex3fv)(local_8c + boxpnt[4][0] * 3);
      (*tri.Vertex3fv)(local_8c + boxpnt[4][1] * 3);
      (*tri.Vertex3fv)(local_8c + boxpnt[4][2] * 3);
      (*tri.Vertex3fv)(local_8c + boxpnt[4][3] * 3);
      local_28 = 0;
      local_2c = 0.0;
      local_24 = 0xbf800000;
      iVar1 = *(int *)pcVar3;
      pcVar3 = pcVar3 + 0x20;
      R_StudioLighting(local_20,iVar1,0,&local_2c);
      (*tri.Brightness)(local_20[0]);
      (*tri.Vertex3fv)(local_8c + boxpnt[5][0] * 3);
      (*tri.Vertex3fv)(local_8c + boxpnt[5][1] * 3);
      (*tri.Vertex3fv)(local_8c + boxpnt[5][2] * 3);
      (*tri.Vertex3fv)(local_8c + boxpnt[5][3] * 3);
      (*tri.End)();
      iVar2 = iVar2 + 1;
    } while (iVar2 < pstudiohdr->numhitboxes);
  }
  return;
}


// R_StudioDrawModel  @ 00146230
int R_StudioDrawModel(int flags)

{
  vec_t *pvVar1;
  int *in1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  qboolean qVar5;
  int iVar6;
  int iVar7;
  vec_t *pvVar8;
  entity_state_t local_1a0;
  alight_t local_4c;
  float local_2c [7];
  
                    /* Unresolved local var: alight_t lighting@[???]
                       Unresolved local var: vec3_t dir@[???] */
  iVar6 = r_dointerp;
  if ((currententity->curstate).renderfx == 0x11) {
                    /* Unresolved local var: entity_state_t deadplayer@[???]
                       Unresolved local var: int result@[DW_OP_reg0(EAX)]
                       Unresolved local var: int save_interp@[???] */
    iVar7 = (currententity->curstate).renderamt;
    if (iVar7 < 1) {
      return 0;
    }
    if (cl.maxclients < iVar7) {
      return 0;
    }
    r_playerindex = iVar7 + -1;
    iVar2 = (CL_UPDATE_MASK & cl.parsecount) * 0x42b8 + 0xc7f6fc + r_playerindex * 0x154;
    uVar4 = 0;
    do {
      uVar3 = uVar4;
      *(undefined4 *)((int)local_1a0.origin + (uVar3 - 0x10)) = *(undefined4 *)(iVar2 + uVar3);
      *(undefined4 *)((int)local_1a0.origin + (uVar3 - 0xc)) = *(undefined4 *)(iVar2 + 4 + uVar3);
      uVar4 = uVar3 + 8;
    } while (uVar4 < 0x150);
                    /* Unresolved local var: alight_t lighting@[???]
                       Unresolved local var: vec3_t dir@[???] */
    *(undefined4 *)((int)local_1a0.origin + (uVar3 - 8)) = *(undefined4 *)(iVar2 + uVar4);
    local_1a0.weaponmodel = 0;
    local_1a0.gaitsequence = 0;
    local_1a0.movetype = 0;
    local_1a0.angles[0] = (currententity->curstate).angles[0];
    local_1a0.angles[1] = (currententity->curstate).angles[1];
    local_1a0.angles[2] = (currententity->curstate).angles[2];
    local_1a0.origin[0] = (currententity->curstate).origin[0];
    local_1a0.origin[1] = (currententity->curstate).origin[1];
    local_1a0.origin[2] = (currententity->curstate).origin[2];
    r_dointerp = 0;
    if (r_playerindex < 0) {
      r_dointerp = iVar6;
      return 0;
    }
    if (cl.maxclients <= r_playerindex) {
      r_dointerp = iVar6;
      return 0;
    }
    local_1a0.number = iVar7;
    iVar7 = R_StudioDrawPlayer(flags,&local_1a0);
    r_dointerp = iVar6;
    return iVar7;
  }
  r_model = currententity->model;
  pstudiohdr = Mod_Extradata(r_model);
  R_StudioSetUpTransform(0);
  if ((flags & 1U) != 0) {
    qVar5 = R_StudioCheckBBox();
    if (qVar5 == false) {
      return 0;
    }
    r_amodels_drawn = r_amodels_drawn + 1;
    r_smodels_total = r_smodels_total + 1;
    if (pstudiohdr->numbodyparts == 0) {
      return 1;
    }
  }
  if ((currententity->curstate).movetype == 0xc) {
    R_StudioMergeBones(r_model);
  }
  else {
    R_StudioSetupBones();
  }
  R_StudioSaveBones();
  if ((flags & 2U) != 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: mstudioattachment_t * pattachment@[???] */
    iVar6 = pstudiohdr->numattachments;
    if (4 < iVar6) {
      Sys_Error("Too many attachments on %s\n",currententity->model);
      iVar6 = pstudiohdr->numattachments;
    }
    pvVar8 = (vec_t *)(pstudiohdr->name + pstudiohdr->attachmentindex + -8);
    if (0 < iVar6) {
      iVar6 = 0;
      do {
        iVar7 = iVar6 + 1;
        pvVar1 = pvVar8 + 9;
        in1 = (int *)(pvVar8 + 10);
        pvVar8 = pvVar8 + 0x16;
        VectorTransform((vec_t *)in1,lighttransform[(int)*pvVar1],currententity->attachment[iVar6]);
        iVar6 = iVar7;
      } while (iVar7 < pstudiohdr->numattachments);
    }
    R_StudioClientEvents();
    if (0 < currententity->index) {
      Q_memcpy(cl_entities[currententity->index].attachment,currententity->attachment,0x30);
    }
  }
  if ((flags & 1U) != 0) {
                    /* Unresolved local var: int lnum@[???]
                       Unresolved local var: vec3_t dist@[???]
                       Unresolved local var: colorVec down@[???]
                       Unresolved local var: float total@[???]
                       Unresolved local var: vec3_t light@[???]
                       Unresolved local var: float r@[???]
                       Unresolved local var: float add@[???]
                       Unresolved local var: vec3_t uporigin@[???]
                       Unresolved local var: vec3_t upend@[???]
                       Unresolved local var: float floor@[???]
                       Unresolved local var: vec3_t color@[???] */
    local_4c.plightvec = local_2c;
    if (filterMode == false) {
      R_StudioDynamicLight(currententity,&local_4c);
    }
    else {
      local_4c.shadelight = 0;
      local_2c[0] = 0.0;
      local_2c[1] = 0.0;
      local_2c[2] = -1.0;
      local_4c.color[0] = filterColorRed * filterBrightness;
      local_4c.ambientlight = (int)(filterBrightness * 192.0);
      local_4c.color[1] = filterColorGreen * filterBrightness;
      local_4c.color[2] = filterBrightness * filterColorBlue;
    }
    R_StudioEntityLight(&local_4c);
    R_StudioSetupLighting(&local_4c);
    uVar4 = (currententity->curstate).colormap;
    r_topcolor = uVar4 & 0xff;
    r_bottomcolor = uVar4 >> 8 & 0xff;
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
  }
  return 1;
}


// R_StudioDrawPlayer  @ 00144f50
int __regparm3 R_StudioDrawPlayer(int flags,entity_state_t *pplayer)

{
  vec_t *pvVar1;
  skin_t (*pasVar2) [11];
  vec_t vVar3;
  vec_t vVar4;
  vec_t vVar5;
  studiohdr_t *psVar6;
  player_info_t *ppVar7;
  qboolean qVar8;
  model_t *pmVar9;
  void *pvVar10;
  cl_entity_t *pcVar11;
  int iVar12;
  skin_t *psVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  vec_t *pvVar17;
  int *piVar18;
  int *piVar19;
  byte bVar20;
  int local_c04;
  int local_c00 [727];
  undefined1 local_a4 [88];
  alight_t local_4c;
  float local_2c [7];
  
                    /* Unresolved local var: alight_t lighting@[???]
                       Unresolved local var: vec3_t dir@[???] */
  bVar20 = 0;
  if (((developer.value == 0.0) && (qVar8 = Host_IsSinglePlayerGame(), qVar8 != false)) ||
     (cl.players[r_playerindex].model[0] == '\0')) {
    iVar12 = r_playerindex;
    r_model = DM_PlayerState[r_playerindex].model;
    DM_PlayerState[r_playerindex].name[0] = '\0';
    pcVar11 = currententity;
    if (r_model != currententity->model) {
      DM_PlayerState[iVar12].model = currententity->model;
      iVar15 = r_remapindex;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: skin_t * pskin@[???] */
      iVar16 = pcVar11->index;
                    /* Unresolved local var: skin_t * pskin@[???] */
      psVar13 = pDM_RemapSkin[iVar16][0];
      if ((psVar13 == (skin_t *)0x0) || (iVar16 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex];
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[0].keynum = iVar16;
        pDM_RemapSkin[iVar16][0] = psVar13;
        DM_RemapSkin[iVar15][0].topcolor = -1;
        DM_RemapSkin[iVar15][0].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar16 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar16][1];
      if ((psVar13 == (skin_t *)0x0) || (iVar16 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 1;
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[1].keynum = iVar16;
        pDM_RemapSkin[iVar16][1] = psVar13;
        DM_RemapSkin[iVar15][1].topcolor = -1;
        DM_RemapSkin[iVar15][1].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar16 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar16][2];
      if ((psVar13 == (skin_t *)0x0) || (iVar16 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 2;
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[2].keynum = iVar16;
        pDM_RemapSkin[iVar16][2] = psVar13;
        DM_RemapSkin[iVar15][2].topcolor = -1;
        DM_RemapSkin[iVar15][2].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar16 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar16][3];
      if ((psVar13 == (skin_t *)0x0) || (iVar16 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 3;
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[3].keynum = iVar16;
        pDM_RemapSkin[iVar16][3] = psVar13;
        DM_RemapSkin[iVar15][3].topcolor = -1;
        DM_RemapSkin[iVar15][3].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar16 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar16][4];
      if ((psVar13 == (skin_t *)0x0) || (iVar16 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 4;
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[4].keynum = iVar16;
        pDM_RemapSkin[iVar16][4] = psVar13;
        DM_RemapSkin[iVar15][4].topcolor = -1;
        DM_RemapSkin[iVar15][4].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar16 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar16][5];
      if ((psVar13 == (skin_t *)0x0) || (iVar16 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 5;
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[5].keynum = iVar16;
        pDM_RemapSkin[iVar16][5] = psVar13;
        DM_RemapSkin[iVar15][5].topcolor = -1;
        DM_RemapSkin[iVar15][5].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar16 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar16][6];
      if ((psVar13 == (skin_t *)0x0) || (iVar16 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 6;
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[6].keynum = iVar16;
        pDM_RemapSkin[iVar16][6] = psVar13;
        DM_RemapSkin[iVar15][6].topcolor = -1;
        DM_RemapSkin[iVar15][6].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar16 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar16][7];
      if ((psVar13 == (skin_t *)0x0) || (iVar16 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 7;
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[7].keynum = iVar16;
        pDM_RemapSkin[iVar16][7] = psVar13;
        DM_RemapSkin[iVar15][7].topcolor = -1;
        DM_RemapSkin[iVar15][7].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar16 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar16][8];
      if ((psVar13 == (skin_t *)0x0) || (iVar16 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 8;
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[8].keynum = iVar16;
        pDM_RemapSkin[iVar16][8] = psVar13;
        DM_RemapSkin[iVar15][8].topcolor = -1;
        DM_RemapSkin[iVar15][8].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar16 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar16][9];
      if ((psVar13 == (skin_t *)0x0) || (iVar16 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 9;
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[9].keynum = iVar16;
        pDM_RemapSkin[iVar16][9] = psVar13;
        DM_RemapSkin[iVar15][9].topcolor = -1;
        DM_RemapSkin[iVar15][9].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar16 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar16][10];
      if ((psVar13 == (skin_t *)0x0) || (iVar16 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 10;
        r_remapindex = (r_remapindex + 1) % 0x40;
        pDM_RemapSkin[iVar16][10] = psVar13;
        DM_RemapSkin[iVar15][10].keynum = iVar16;
        DM_RemapSkin[iVar15][10].topcolor = -1;
        DM_RemapSkin[iVar15][10].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      r_model = DM_PlayerState[iVar12].model;
    }
  }
  else {
    iVar12 = Q_strcmp(DM_PlayerState[r_playerindex].name,cl.players[r_playerindex].model);
    if (iVar12 == 0) {
      r_model = DM_PlayerState[r_playerindex].model;
    }
    else {
      Q_strncpy(DM_PlayerState[r_playerindex].name,cl.players[r_playerindex].model,0x103);
      iVar12 = r_playerindex;
      iVar16 = r_playerindex * 0x250 + 0xdf8950;
      DM_PlayerState[r_playerindex].name[0x103] = '\0';
      snprintf(DM_PlayerState[iVar12].modelname,0x104,"models/player/%s/%s.mdl",iVar16,iVar16);
      iVar12 = r_playerindex;
      pmVar9 = Mod_ForName(DM_PlayerState[r_playerindex].modelname,false,true);
      iVar16 = r_playerindex;
      DM_PlayerState[iVar12].model = pmVar9;
      pcVar11 = currententity;
      if (DM_PlayerState[iVar16].model == (model_t *)0x0) {
        DM_PlayerState[iVar16].model = currententity->model;
      }
      iVar15 = r_remapindex;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: skin_t * pskin@[???] */
      iVar12 = pcVar11->index;
                    /* Unresolved local var: skin_t * pskin@[???] */
      psVar13 = pDM_RemapSkin[iVar12][0];
      if ((psVar13 == (skin_t *)0x0) || (iVar12 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex];
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[0].keynum = iVar12;
        pDM_RemapSkin[iVar12][0] = psVar13;
        DM_RemapSkin[iVar15][0].topcolor = -1;
        DM_RemapSkin[iVar15][0].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar12 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar12][1];
      if ((psVar13 == (skin_t *)0x0) || (iVar12 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 1;
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[1].keynum = iVar12;
        pDM_RemapSkin[iVar12][1] = psVar13;
        DM_RemapSkin[iVar15][1].topcolor = -1;
        DM_RemapSkin[iVar15][1].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar12 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar12][2];
      if ((psVar13 == (skin_t *)0x0) || (iVar12 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 2;
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[2].keynum = iVar12;
        pDM_RemapSkin[iVar12][2] = psVar13;
        DM_RemapSkin[iVar15][2].topcolor = -1;
        DM_RemapSkin[iVar15][2].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar12 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar12][3];
      if ((psVar13 == (skin_t *)0x0) || (iVar12 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 3;
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[3].keynum = iVar12;
        pDM_RemapSkin[iVar12][3] = psVar13;
        DM_RemapSkin[iVar15][3].topcolor = -1;
        DM_RemapSkin[iVar15][3].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar12 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar12][4];
      if ((psVar13 == (skin_t *)0x0) || (iVar12 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 4;
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[4].keynum = iVar12;
        pDM_RemapSkin[iVar12][4] = psVar13;
        DM_RemapSkin[iVar15][4].topcolor = -1;
        DM_RemapSkin[iVar15][4].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar12 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar12][5];
      if ((psVar13 == (skin_t *)0x0) || (iVar12 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 5;
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[5].keynum = iVar12;
        pDM_RemapSkin[iVar12][5] = psVar13;
        DM_RemapSkin[iVar15][5].topcolor = -1;
        DM_RemapSkin[iVar15][5].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar12 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar12][6];
      if ((psVar13 == (skin_t *)0x0) || (iVar12 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 6;
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[6].keynum = iVar12;
        pDM_RemapSkin[iVar12][6] = psVar13;
        DM_RemapSkin[iVar15][6].topcolor = -1;
        DM_RemapSkin[iVar15][6].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar12 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar12][7];
      if ((psVar13 == (skin_t *)0x0) || (iVar12 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 7;
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[7].keynum = iVar12;
        pDM_RemapSkin[iVar12][7] = psVar13;
        DM_RemapSkin[iVar15][7].topcolor = -1;
        DM_RemapSkin[iVar15][7].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar12 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar12][8];
      if ((psVar13 == (skin_t *)0x0) || (iVar12 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 8;
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[8].keynum = iVar12;
        pDM_RemapSkin[iVar12][8] = psVar13;
        DM_RemapSkin[iVar15][8].topcolor = -1;
        DM_RemapSkin[iVar15][8].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar12 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar12][9];
      if ((psVar13 == (skin_t *)0x0) || (iVar12 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 9;
        pasVar2 = DM_RemapSkin + r_remapindex;
        r_remapindex = (r_remapindex + 1) % 0x40;
        (*pasVar2)[9].keynum = iVar12;
        pDM_RemapSkin[iVar12][9] = psVar13;
        DM_RemapSkin[iVar15][9].topcolor = -1;
        DM_RemapSkin[iVar15][9].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      iVar15 = r_remapindex;
      iVar12 = pcVar11->index;
      psVar13 = pDM_RemapSkin[iVar12][10];
      if ((psVar13 == (skin_t *)0x0) || (iVar12 != psVar13->keynum)) {
        psVar13 = DM_RemapSkin[r_remapindex] + 10;
        r_remapindex = (r_remapindex + 1) % 0x40;
        pDM_RemapSkin[iVar12][10] = psVar13;
        DM_RemapSkin[iVar15][10].keynum = iVar12;
        DM_RemapSkin[iVar15][10].topcolor = -1;
        DM_RemapSkin[iVar15][10].bottomcolor = -1;
      }
      psVar13->topcolor = -1;
      psVar13->bottomcolor = -1;
      r_model = DM_PlayerState[iVar16].model;
    }
  }
  if (r_model == (model_t *)0x0) {
    return 0;
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
    vVar3 = currententity->angles[0];
    vVar4 = currententity->angles[1];
    vVar5 = currententity->angles[2];
    R_StudioProcessGait(pplayer);
    r_playerinfo->gaitsequence = pplayer->gaitsequence;
    r_playerinfo = (player_info_t *)0x0;
    R_StudioSetUpTransform(0);
    pcVar11 = currententity;
    currententity->angles[0] = vVar3;
    pcVar11->angles[1] = vVar4;
    pcVar11->angles[2] = vVar5;
  }
  uVar14 = flags & 1;
  if (uVar14 != 0) {
    qVar8 = R_StudioCheckBBox();
    if (qVar8 == false) {
      return 0;
    }
    r_amodels_drawn = r_amodels_drawn + 1;
    r_smodels_total = r_smodels_total + 1;
    if (pstudiohdr->numbodyparts == 0) {
      return 1;
    }
  }
  r_playerinfo = cl.players + r_playerindex;
  R_StudioSetupBones();
  R_StudioSaveBones();
  ppVar7 = r_playerinfo;
  r_playerinfo = (player_info_t *)0x0;
  ppVar7->renderframe = r_framecount;
  if ((flags & 2U) != 0) {
    if ((uVar14 != 0) && (pplayer->weaponmodel != 0)) {
                    /* Unresolved local var: studiohdr_t * modelheader@[???] */
      pmVar9 = CL_GetModelByIndex(pplayer->weaponmodel);
      pvVar10 = Mod_Extradata(pmVar9);
      if (*(int *)((int)pvVar10 + 0xd4) != 0) goto LAB_001456a0;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: mstudioattachment_t * pattachment@[???] */
    iVar12 = pstudiohdr->numattachments;
    if (4 < iVar12) {
      Sys_Error("Too many attachments on %s\n",currententity->model);
      iVar12 = pstudiohdr->numattachments;
    }
    pvVar17 = (vec_t *)(pstudiohdr->name + pstudiohdr->attachmentindex + -8);
    if (0 < iVar12) {
      iVar12 = 0;
      do {
        iVar16 = iVar12 + 1;
        pvVar1 = pvVar17 + 9;
        piVar18 = (int *)(pvVar17 + 10);
        pvVar17 = pvVar17 + 0x16;
        VectorTransform((vec_t *)piVar18,lighttransform[(int)*pvVar1],
                        currententity->attachment[iVar12]);
        iVar12 = iVar16;
      } while (iVar16 < pstudiohdr->numattachments);
    }
    R_StudioClientEvents();
    if (0 < currententity->index) {
      Q_memcpy(cl_entities[currententity->index].attachment,currententity->attachment,0x30);
    }
  }
  if (uVar14 == 0) {
    return 1;
  }
LAB_001456a0:
  if ((cl_himodels.value != 0.0) && (DM_PlayerState[r_playerindex].model != currententity->model)) {
    (currententity->curstate).body = 0xff;
  }
  if ((((developer.value != 0.0) ||
       (qVar8 = Host_IsSinglePlayerGame(), pcVar11 = currententity, qVar8 == false)) &&
      (pcVar11 = currententity, DM_PlayerState[r_playerindex].name[0] != '\0')) &&
     (DM_PlayerState[r_playerindex].model == currententity->model)) {
    (currententity->curstate).body = 1;
  }
                    /* Unresolved local var: int lnum@[???]
                       Unresolved local var: vec3_t dist@[???]
                       Unresolved local var: colorVec down@[???]
                       Unresolved local var: float total@[???]
                       Unresolved local var: vec3_t light@[???]
                       Unresolved local var: float r@[???]
                       Unresolved local var: float add@[???]
                       Unresolved local var: vec3_t uporigin@[???]
                       Unresolved local var: vec3_t upend@[???]
                       Unresolved local var: float floor@[???]
                       Unresolved local var: vec3_t color@[???] */
  local_4c.plightvec = local_2c;
  if (filterMode == false) {
    R_StudioDynamicLight(pcVar11,&local_4c);
  }
  else {
    local_4c.shadelight = 0;
    local_2c[0] = 0.0;
    local_2c[1] = 0.0;
    local_2c[2] = -1.0;
    local_4c.color[0] = filterColorRed * filterBrightness;
    local_4c.ambientlight = (int)(filterBrightness * 192.0);
    local_4c.color[1] = filterColorGreen * filterBrightness;
    local_4c.color[2] = filterBrightness * filterColorBlue;
  }
  R_StudioEntityLight(&local_4c);
  R_StudioSetupLighting(&local_4c);
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
  psVar6 = pstudiohdr;
  r_playerinfo = (player_info_t *)0x0;
  iVar12 = pplayer->weaponmodel;
  pstudiohdr = psVar6;
  if (iVar12 != 0) {
                    /* Unresolved local var: studiohdr_t * saveheader@[???]
                       Unresolved local var: cl_entity_t saveent@[???]
                       Unresolved local var: model_t * pweaponmodel@[???] */
    piVar18 = &local_c04;
    pcVar11 = currententity;
    piVar19 = piVar18;
    for (iVar16 = 0x2ee; iVar16 != 0; iVar16 = iVar16 + -1) {
      *piVar19 = pcVar11->index;
      pcVar11 = (cl_entity_t *)((int)pcVar11 + (uint)bVar20 * -8 + 4);
      piVar19 = piVar19 + (uint)bVar20 * -2 + 1;
    }
    pmVar9 = CL_GetModelByIndex(iVar12);
    pstudiohdr = Mod_Extradata(pmVar9);
    R_StudioMergeBones(pmVar9);
    R_StudioSetupLighting(&local_4c);
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
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: mstudioattachment_t * pattachment@[???] */
    iVar12 = pstudiohdr->numattachments;
    if (4 < iVar12) {
      Sys_Error("Too many attachments on %s\n",currententity->model);
      iVar12 = pstudiohdr->numattachments;
    }
    pvVar17 = (vec_t *)(pstudiohdr->name + pstudiohdr->attachmentindex + -8);
    if (0 < iVar12) {
      iVar16 = 0;
      do {
        iVar15 = iVar16 + 1;
        pvVar1 = pvVar17 + 9;
        piVar19 = (int *)(pvVar17 + 10);
        pvVar17 = pvVar17 + 0x16;
        VectorTransform((vec_t *)piVar19,lighttransform[(int)*pvVar1],
                        currententity->attachment[iVar16]);
        iVar12 = pstudiohdr->numattachments;
        iVar16 = iVar15;
      } while (iVar15 < iVar12);
    }
    if (0 < currententity->index) {
      Q_memcpy(local_a4,currententity->attachment,iVar12 * 0xc);
    }
    pcVar11 = currententity;
    uVar14 = 3000;
    if (((uint)currententity & 4) != 0) {
      piVar18 = local_c00;
      uVar14 = 0xbb4;
      currententity->index = local_c04;
      pcVar11 = (cl_entity_t *)&pcVar11->player;
    }
    for (uVar14 = uVar14 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
      pcVar11->index = *piVar18;
      piVar18 = piVar18 + (uint)bVar20 * -2 + 1;
      pcVar11 = (cl_entity_t *)((int)pcVar11 + (uint)bVar20 * -8 + 4);
    }
    pstudiohdr = psVar6;
    if ((flags & 2U) != 0) {
      R_StudioClientEvents();
    }
  }
  return 1;
}


// R_StudioDrawPlayer  @ 00146200
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


// R_StudioDrawPoints  @ 00144190
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioDrawPoints(void)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  studiohdr_t *psVar6;
  studiohdr_t *psVar7;
  float fVar8;
  studiohdr_t *ptexturehdr;
  int iVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  vec3_t *pavVar14;
  auxvert_t *paVar15;
  char *pcVar16;
  uint uVar17;
  float (*light) [3] [4];
  char *pcVar18;
  studiohdr_t *psVar19;
  int iVar20;
  float fStack_68;
  float fStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  char *pcStack_54;
  GLfloat GStack_3c;
  GLfloat GStack_38;
  GLfloat GStack_34;
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  float afStack_20 [4];
  
  psVar6 = pstudiohdr;
  iVar12 = psubmodel->vertinfoindex;
  iVar20 = psubmodel->norminfoindex;
  ptexturehdr = R_LoadTextures(r_model);
  psVar7 = pstudiohdr;
  iVar3 = ptexturehdr->textureindex;
  iVar11 = psubmodel->vertindex;
  pcVar13 = pstudiohdr->name;
  pcVar10 = pstudiohdr->name + psubmodel->meshindex + -8;
  iVar4 = psubmodel->normindex;
  pcStack_54 = ptexturehdr->name + ptexturehdr->skinindex + -8;
  iVar9 = (int)(currententity->curstate).skin;
  if ((iVar9 == 0) || (ptexturehdr->numskinfamilies <= iVar9)) {
    if ((currententity->curstate).renderfx == 0x13) goto LAB_0014413f;
LAB_00143705:
    if (psubmodel->numverts < 1) goto LAB_00143786;
    iVar9 = 0;
    paVar15 = pauxverts;
    pcVar13 = pcVar13 + iVar11 + -8;
    do {
      iVar11 = iVar9 + iVar12;
      iVar9 = iVar9 + 1;
      R_StudioTransformAuxVert(paVar15,(uint)(byte)psVar6->name[iVar11 + -8],(vec_t *)pcVar13);
      iVar11 = psubmodel->numverts;
      paVar15 = paVar15 + 1;
      psVar19 = psVar7;
      pcVar13 = pcVar13 + 0xc;
    } while (iVar9 < iVar11);
  }
  else {
    pcStack_54 = pcStack_54 + iVar9 * ptexturehdr->numskinref * 2;
    if ((currententity->curstate).renderfx != 0x13) goto LAB_00143705;
LAB_0014413f:
    BuildNormalIndexTable();
    BuildGlowShellVerts((vec3_t *)(pcVar13 + iVar11 + -8),pauxverts);
    iVar11 = psubmodel->numverts;
    psVar19 = pstudiohdr;
  }
  if (0 < iVar11) {
    pcVar16 = psVar19->name + psubmodel->vertinfoindex + -8;
    iVar12 = 0;
    light = lightpos;
    pcVar13 = psVar19->name + psubmodel->vertindex + -8;
    do {
      iVar12 = iVar12 + 1;
      bVar1 = *pcVar16;
      pcVar16 = pcVar16 + 1;
      R_LightStrength((uint)bVar1,(float *)pcVar13,*light);
      light = light + 1;
      pcVar13 = pcVar13 + 0xc;
    } while (iVar12 < psubmodel->numverts);
  }
LAB_00143786:
  fStack_68 = (float)psubmodel->nummesh;
  if (0 < (int)fStack_68) {
    iStack_60 = 0;
    pcVar13 = psVar7->name + iVar4 + -8;
    pcVar16 = psVar6->name + iVar20 + -8;
    pavVar14 = pvlightvalues;
    do {
      uVar17 = g_ForcedFaceFlags |
               *(uint *)(ptexturehdr->name +
                        *(short *)(pcStack_54 + *(int *)(pcVar10 + 8) * 2) * 0x50 + iVar3 + 0x38);
      if (2.0 <= r_fullbright.value) {
        uVar17 = uVar17 & 0xfffffffc;
      }
      if ((currententity->curstate).rendermode == 5) {
        if ((0 < *(int *)(pcVar10 + 0xc)) &&
           (iVar12 = ((int)pavVar14 - (int)pvlightvalues >> 2) * -0x55555555,
           iVar12 < pvlightvalues_size)) {
          if ((uVar17 & 2) == 0) {
            iVar12 = 0;
            do {
              fVar8 = r_blend;
              iVar12 = iVar12 + 1;
              (*pavVar14)[2] = r_blend;
              (*pavVar14)[1] = fVar8;
              (*pavVar14)[0] = fVar8;
              pavVar14 = pavVar14 + 1;
              if (*(int *)(pcVar10 + 0xc) <= iVar12) break;
            } while (((int)pavVar14 - (int)pvlightvalues >> 2) * -0x55555555 < pvlightvalues_size);
          }
          else {
            iVar20 = 0;
            do {
              fVar8 = r_blend;
              iVar20 = iVar20 + 1;
              (*pavVar14)[2] = r_blend;
              (*pavVar14)[1] = fVar8;
              (*pavVar14)[0] = fVar8;
              pavVar14 = pavVar14 + 1;
              R_StudioChrome(chrome[iVar12],(uint)(byte)*pcVar16,(vec_t *)pcVar13);
              if (*(int *)(pcVar10 + 0xc) <= iVar20) break;
              iVar12 = ((int)pavVar14 - (int)pvlightvalues >> 2) * -0x55555555;
            } while (iVar12 < pvlightvalues_size);
          }
          goto LAB_001438c1;
        }
      }
      else if ((0 < *(int *)(pcVar10 + 0xc)) &&
              (iVar12 = ((int)pavVar14 - (int)pvlightvalues >> 2) * -0x55555555,
              iVar12 < pvlightvalues_size)) {
        if ((uVar17 & 2) == 0) {
          iVar12 = 0;
          pcVar18 = pcVar13;
          do {
            iVar12 = iVar12 + 1;
            pcVar13 = pcVar18 + 0xc;
            bVar1 = *pcVar16;
            pcVar16 = pcVar16 + 1;
            R_StudioLighting(afStack_20,(uint)bVar1,uVar17,(vec_t *)pcVar18);
            (*pavVar14)[0] = r_colormix[0] * afStack_20[0];
            (*pavVar14)[1] = r_colormix[1] * afStack_20[0];
            (*pavVar14)[2] = afStack_20[0] * r_colormix[2];
            pavVar14 = pavVar14 + 1;
            if (*(int *)(pcVar10 + 0xc) <= iVar12) break;
            pcVar18 = pcVar13;
          } while (((int)pavVar14 - (int)pvlightvalues >> 2) * -0x55555555 < pvlightvalues_size);
        }
        else {
          iVar20 = 0;
          pcVar18 = pcVar13;
          do {
            iVar20 = iVar20 + 1;
            R_StudioLighting(afStack_20,(uint)(byte)*pcVar16,uVar17,(vec_t *)pcVar18);
            pcVar13 = pcVar18 + 0xc;
            bVar1 = *pcVar16;
            pcVar16 = pcVar16 + 1;
            R_StudioChrome(chrome[iVar12],(uint)bVar1,(vec_t *)pcVar18);
            (*pavVar14)[0] = r_colormix[0] * afStack_20[0];
            (*pavVar14)[1] = r_colormix[1] * afStack_20[0];
            (*pavVar14)[2] = afStack_20[0] * r_colormix[2];
            pavVar14 = pavVar14 + 1;
            if (*(int *)(pcVar10 + 0xc) <= iVar20) break;
            iVar12 = ((int)pavVar14 - (int)pvlightvalues >> 2) * -0x55555555;
            pcVar18 = pcVar13;
          } while (iVar12 < pvlightvalues_size);
        }
LAB_001438c1:
        fStack_68 = (float)psubmodel->nummesh;
      }
      iStack_60 = iStack_60 + 1;
      pcVar10 = pcVar10 + 0x14;
    } while (iStack_60 < (int)fStack_68);
  }
  (*qglCullFace)(0x404);
  bVar5 = false;
  if (((cl_righthand != (cvar_t *)0x0) && (0.0 < cl_righthand->value)) &&
     (cl.viewent.index == currententity->index)) {
    (*qglDisable)(0xb44);
    bVar5 = true;
  }
  psVar6 = pstudiohdr;
  iVar12 = psubmodel->normindex;
  if (0 < psubmodel->nummesh) {
    iStack_58 = 0;
    iStack_5c = 0;
    do {
      pcVar10 = pstudiohdr->name + iStack_58 + psubmodel->meshindex + -8;
      c_alias_polys = c_alias_polys + *(int *)pcVar10;
      pcVar13 = pstudiohdr->name + *(int *)(pcVar10 + 4) + -8;
      uVar17 = g_ForcedFaceFlags |
               *(uint *)(ptexturehdr->name +
                        *(short *)(pcStack_54 + *(int *)(pcVar10 + 8) * 2) * 0x50 + iVar3 + 0x38);
      if (2.0 <= r_fullbright.value) {
        uVar17 = uVar17 & 0xfffffffc;
      }
      if ((uVar17 & 0x40) != 0) {
        (*qglEnable)(0xbc0);
        (*qglAlphaFunc)(0x204,0.5);
        (*qglDepthMask)('\x01');
      }
      if (((uVar17 & 0x20) != 0) && ((currententity->curstate).rendermode == 0)) {
        (*qglBlendFunc)(1,1);
        (*qglEnable)(0xbe2);
        (*qglDepthMask)('\0');
        (*qglShadeModel)(0x1d01);
      }
      if (2.0 <= r_fullbright.value) {
        (*tri.SpriteTexture)(cl_sprite_white,0);
        fStack_68 = 0.00390625;
        fStack_64 = 0.00390625;
      }
      else {
        iVar20 = *(short *)(pcStack_54 + *(int *)(pcVar10 + 8) * 2) * 0x50 + iVar3;
        fStack_64 = 1.0 / (float)*(int *)(ptexturehdr->name + iVar20 + 0x3c);
        fStack_68 = 1.0 / (float)*(int *)((int)ptexturehdr->eyeposition + iVar20 + -4);
        if ((g_ForcedFaceFlags & 2U) == 0) {
          R_StudioSetupSkin(ptexturehdr,(int)*(short *)(pcStack_54 + *(int *)(pcVar10 + 8) * 2));
        }
      }
      if ((uVar17 & 2) == 0) {
        sVar2 = *(short *)pcVar13;
        while (iVar20 = (int)sVar2, iVar20 != 0) {
          pcVar10 = pcVar13 + 2;
          if (iVar20 < 0) {
            iVar20 = -iVar20;
            (*qglBegin)(6);
LAB_00143a5d:
            pcVar16 = pcVar10;
            if (*(short *)(pcVar13 + 4) < pvlightvalues_size) {
              do {
                (*qglTexCoord2f)((float)*(short *)(pcVar16 + 4) * fStack_64,
                                 (float)*(short *)(pcVar16 + 6) * fStack_68);
                iVar11 = *(short *)(pcVar16 + 2) * 0xc;
                pavVar14 = pvlightvalues + *(short *)(pcVar16 + 2);
                if (bVar5) {
                  fStack_2c = *(float *)(psVar6->name + iVar11 + iVar12 + -8);
                  fStack_28 = -*(float *)(psVar6->name + *(short *)(pcVar16 + 2) * 0xc + iVar12 + -4
                                         );
                  uStack_24 = *(undefined4 *)(psVar6->name + *(short *)(pcVar16 + 2) * 0xc + iVar12)
                  ;
                  if (numlights == 0) goto LAB_00143b3f;
                  R_LightLambert(lightpos[*(short *)pcVar16],&fStack_2c,*pavVar14,&GStack_3c);
                }
                else if (numlights == 0) {
LAB_00143b3f:
                  GStack_3c = (*pavVar14)[0];
                  GStack_38 = (*pavVar14)[1];
                  GStack_34 = (*pavVar14)[2];
                }
                else {
                  R_LightLambert(lightpos[*(short *)pcVar16],
                                 (float *)(psVar6->name + iVar11 + iVar12 + -8),*pavVar14,&GStack_3c
                                );
                }
                (*qglColor4f)(GStack_3c,GStack_38,GStack_34,r_blend);
                pcVar10 = pcVar16 + 8;
                paVar15 = pauxverts + *(short *)pcVar16;
                (*qglVertex3f)(paVar15->fv[0],paVar15->fv[1],paVar15->fv[2]);
                iVar20 = iVar20 + -1;
              } while ((iVar20 != 0) &&
                      (pcVar13 = pcVar16 + 10, pcVar16 = pcVar10,
                      *(short *)pcVar13 < pvlightvalues_size));
            }
          }
          else {
            (*qglBegin)(5);
            if (iVar20 != 0) goto LAB_00143a5d;
          }
          (*qglEnd)();
          pcVar13 = pcVar10;
          sVar2 = *(short *)pcVar10;
        }
      }
      else {
        iVar20 = (int)*(short *)pcVar13;
        if ((g_ForcedFaceFlags & 2U) == 0) {
          pcVar13 = pcVar13 + 2;
          if (iVar20 != 0) {
            if (iVar20 < 0) goto LAB_00143dac;
            do {
              (*qglBegin)(5);
              if (iVar20 == 0) goto LAB_00143d90;
              while( true ) {
                iVar11 = (int)*(short *)(pcVar13 + 2);
                pcVar10 = pcVar13;
                if (iVar11 < pvlightvalues_size) {
                  do {
                    (*qglTexCoord2f)((float)chrome[iVar11][0] * fStack_64 * 0.0009765625,
                                     (float)chrome[iVar11][1] * fStack_68 * 0.0009765625);
                    pavVar14 = pvlightvalues + *(short *)(pcVar10 + 2);
                    if (numlights == 0) {
                      GStack_3c = (*pavVar14)[0];
                      GStack_38 = (*pavVar14)[1];
                      GStack_34 = (*pavVar14)[2];
                    }
                    else {
                      R_LightLambert(lightpos[*(short *)pcVar10],
                                     (float *)(psVar6->name +
                                              *(short *)(pcVar10 + 2) * 0xc + iVar12 + -8),*pavVar14
                                     ,&GStack_3c);
                    }
                    (*qglColor4f)(GStack_3c,GStack_38,GStack_34,r_blend);
                    pcVar13 = pcVar10 + 8;
                    paVar15 = pauxverts + *(short *)pcVar10;
                    (*qglVertex3f)(paVar15->fv[0],paVar15->fv[1],paVar15->fv[2]);
                    iVar20 = iVar20 + -1;
                  } while ((iVar20 != 0) &&
                          (iVar11 = (int)*(short *)(pcVar10 + 10), pcVar10 = pcVar13,
                          iVar11 < pvlightvalues_size));
                }
LAB_00143d90:
                (*qglEnd)();
                iVar20 = (int)*(short *)pcVar13;
                pcVar13 = pcVar13 + 2;
                if (iVar20 == 0) goto LAB_00143bd4;
                if (-1 < iVar20) break;
LAB_00143dac:
                iVar20 = -iVar20;
                (*qglBegin)(6);
              }
            } while( true );
          }
        }
        else {
          while (iVar20 != 0) {
            pcVar13 = pcVar13 + 2;
            pcVar10 = pcVar13;
            if (iVar20 < 0) {
              iVar20 = -iVar20;
              (*qglBegin)(6);
              iVar11 = iVar20;
LAB_00143ef0:
              do {
                (*qglTexCoord2f)((float)chrome[g_NormalIndex[*(short *)pcVar10]][0] *
                                 fStack_64 * 0.0009765625,
                                 (float)chrome[g_NormalIndex[*(short *)pcVar10]][1] *
                                 fStack_68 * 0.0009765625);
                paVar15 = pauxverts + *(short *)pcVar10;
                (*qglVertex3f)(paVar15->fv[0],paVar15->fv[1],paVar15->fv[2]);
                iVar20 = iVar20 + -1;
                pcVar10 = pcVar10 + 8;
              } while (iVar20 != 0);
              pcVar13 = pcVar13 + iVar11 * 8;
            }
            else {
              (*qglBegin)(5);
              iVar11 = iVar20;
              if (iVar20 != 0) goto LAB_00143ef0;
            }
            (*qglEnd)();
            iVar20 = (int)*(short *)pcVar13;
          }
        }
      }
LAB_00143bd4:
      if ((uVar17 & 0x40) != 0) {
        (*qglAlphaFunc)(0x205,0.0);
        (*qglDisable)(0xbc0);
      }
      if (((uVar17 & 0x20) != 0) && ((currententity->curstate).rendermode == 0)) {
        (*qglDisable)(0xbe2);
        (*qglDepthMask)('\x01');
        (*qglShadeModel)(0x1d00);
      }
      iStack_5c = iStack_5c + 1;
      iStack_58 = iStack_58 + 0x14;
    } while (iStack_5c < psubmodel->nummesh);
  }
  (*qglEnable)(0xb44);
  return;
}


// R_StudioDynamicLight  @ 0013a190
void __regparm3 R_StudioDynamicLight(cl_entity_t *ent,alight_t *plight)

{
  byte *pbVar1;
  float fVar2;
  vec_t vVar3;
  cl_entity_t *pcVar4;
  int iVar5;
  msurface_t *pmVar6;
  uint uVar7;
  int iVar8;
  float *pfVar9;
  ulonglong uVar10;
  float fVar11;
  float fVar12;
  float local_bc;
  ulonglong local_b4;
  float local_a8;
  float local_a4;
  uint local_9c;
  colorVec local_7c;
  colorVec local_6c;
  vec_t local_5c;
  float local_58;
  float local_54;
  float local_4c;
  float local_48;
  float local_44;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
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
  local_5c = 0.0;
  local_58 = 0.0;
  if (((ent->curstate).effects & 0x10) == 0) {
    local_54 = -1.0;
    local_44 = -8.0;
  }
  else {
    local_54 = 1.0;
    local_44 = 8.0;
  }
  local_4c = ent->origin[0];
  local_48 = ent->origin[1];
  local_44 = ent->origin[2] - local_44;
  if (movevars.skycolor_r + movevars.skycolor_g + movevars.skycolor_b != 0.0) {
                    /* Unresolved local var: vec3_t end@[???]
                       Unresolved local var: msurface_t * psurf@[???] */
    local_6c.r = (uint)(local_4c - movevars.skyvec_x * 8192.0);
    local_6c.g = (uint)(local_48 - movevars.skyvec_y * 8192.0);
    local_6c.b = (uint)(ent->origin[2] - movevars.skyvec_z * 8192.0);
    pmVar6 = SurfaceAtPoint(cl.worldmodel,(cl.worldmodel)->nodes,&local_4c,(vec_t *)&local_6c);
    if (((ent->model->flags & 0x400) != 0) ||
       ((pmVar6 != (msurface_t *)0x0 && ((pmVar6->flags & 4) != 0)))) {
      local_9c = (uint)(longlong)ROUND(movevars.skycolor_r);
      uVar7 = local_9c;
      local_9c = (uint)(longlong)ROUND(movevars.skycolor_g);
      local_b4 = (ulonglong)ROUND(movevars.skycolor_b);
      local_5c = movevars.skyvec_x;
      local_58 = movevars.skyvec_y;
      local_54 = movevars.skyvec_z;
      if (local_9c + uVar7 + (int)(float)local_b4 != 0) {
        iVar8 = (currententity->curstate).renderfx;
        local_7c.r = uVar7;
        local_bc = (float)local_9c;
        pcVar4 = currententity;
        goto joined_r0x0013aab4;
      }
    }
  }
  VectorScale(&local_5c,2048.0,&local_28);
  local_28 = local_28 + local_4c;
  local_24 = local_24 + local_48;
  local_20 = local_20 + local_44;
  R_LightVec(&local_7c,&local_4c,&local_28);
                    /* Unresolved local var: colorVec gcolor@[???]
                       Unresolved local var: float[4] grad@[???] */
  local_4c = local_4c - 16.0;
  local_48 = local_48 - 16.0;
  local_b4 = (ulonglong)local_7c.b;
  local_28 = local_28 - 16.0;
  local_24 = local_24 - 16.0;
  R_LightVec(&local_6c,&local_4c,&local_28);
  fVar12 = (float)((longdouble)(local_6c.g + local_6c.b + local_6c.r) / (longdouble)768.0);
  local_4c = local_4c + 32.0;
  local_28 = local_28 + 32.0;
  R_LightVec(&local_6c,&local_4c,&local_28);
  fVar11 = (float)((longdouble)(local_6c.g + local_6c.b + local_6c.r) / (longdouble)768.0);
  local_48 = local_48 + 32.0;
  local_24 = local_24 + 32.0;
  R_LightVec(&local_6c,&local_4c,&local_28);
  fVar2 = (float)((longdouble)(local_6c.r + local_6c.b + local_6c.g) / (longdouble)768.0);
  local_4c = local_4c - 32.0;
  local_28 = local_28 - 32.0;
  R_LightVec(&local_6c,&local_4c,&local_28);
  local_58 = (float)((longdouble)(local_6c.g + local_6c.r + local_6c.b) / (longdouble)768.0);
  local_5c = ((fVar12 - fVar11) - fVar2) + local_58;
  local_58 = ((fVar12 + fVar11) - fVar2) - local_58;
  VectorNormalize(&local_5c);
  iVar8 = (currententity->curstate).renderfx;
  local_bc = (float)local_7c.g;
  pcVar4 = currententity;
joined_r0x0013aab4:
  if ((iVar8 == 0x15) && (iVar8 = (pcVar4->curstate).iuser4, iVar8 != 10)) {
    fVar12 = (float)iVar8 / 10.0;
    uVar10 = (ulonglong)(uint)local_bc;
    local_bc = (float)(longlong)ROUND((float)local_7c.r * fVar12);
    local_7c.r = (uint)local_bc;
    local_bc = (float)(longlong)ROUND((float)uVar10 * fVar12);
    local_b4 = (ulonglong)ROUND((float)(local_b4 & 0xffffffff) * fVar12);
  }
  currententity = pcVar4;
  (pcVar4->cvFloorColor).r = local_7c.r;
  uVar7 = local_7c.r;
  if (local_7c.r <= (uint)local_bc) {
    uVar7 = (uint)local_bc;
  }
  (pcVar4->cvFloorColor).g = (uint)local_bc;
  (pcVar4->cvFloorColor).a = local_7c.a;
  (pcVar4->cvFloorColor).b = (uint)(float)local_b4;
  local_a4 = (float)local_7c.r;
  local_a8 = (float)(uint)local_bc;
  local_b4._0_4_ = (float)(local_b4 & 0xffffffff);
  fVar12 = (float)uVar7;
  if ((float)uVar7 <= (float)local_b4) {
    fVar12 = (float)local_b4;
  }
  local_bc = 1.0;
  if (fVar12 != 0.0) {
    local_bc = fVar12;
  }
  pfVar9 = &cl_dlights[0].die;
  VectorScale(&local_5c,local_bc,&local_5c);
LAB_0013a67f:
  do {
    if ((float)cl.time <= *pfVar9) {
      local_34 = ent->origin[0] - ((dlight_t *)(pfVar9 + -5))->origin[0];
      local_30 = ent->origin[1] - pfVar9[-4];
      local_2c = ent->origin[2] - pfVar9[-3];
      fVar11 = Length(&local_34);
      fVar12 = pfVar9[-2] - fVar11;
      if (0.0 < fVar12) {
        vVar3 = fVar12;
        if (1.0 < fVar11) {
          vVar3 = fVar12 / fVar11;
        }
        local_bc = local_bc + fVar12;
        VectorScale(&local_34,vVar3,&local_34);
        local_5c = local_5c + local_34;
        local_58 = local_58 + local_30;
        local_54 = local_54 + local_2c;
        local_a4 = (float)((color24 *)(pfVar9 + -1))->r * fVar12 * 0.00390625 + local_a4;
        local_a8 = (float)*(byte *)((int)pfVar9 + -3) * fVar12 * 0.00390625 + local_a8;
        pbVar1 = (byte *)((int)pfVar9 + -2);
        pfVar9 = pfVar9 + 10;
        local_b4._0_4_ = (float)*pbVar1 * fVar12 * 0.00390625 + (float)local_b4;
        if (pfVar9 == (float *)(cl_lightstyle[0].map + 0x10)) goto LAB_0013a7d0;
        goto LAB_0013a67f;
      }
    }
    pfVar9 = pfVar9 + 10;
    if (pfVar9 == (float *)(cl_lightstyle[0].map + 0x10)) {
LAB_0013a7d0:
      vVar3 = 0.6;
      if ((((ent->model->flags & 0x100) == 0) && (vVar3 = 1.0, v_direct.value <= 1.0)) &&
         (vVar3 = 0.75, 0.75 <= v_direct.value)) {
        vVar3 = v_direct.value;
      }
      VectorScale(&local_5c,vVar3,&local_5c);
      fVar12 = Length(&local_5c);
      iVar8 = (int)fVar12;
      plight->shadelight = iVar8;
      fVar12 = local_a4;
      if (local_a4 <= local_a8) {
        fVar12 = local_a8;
      }
      if (fVar12 <= (float)local_b4) {
        fVar12 = (float)local_b4;
      }
      iVar5 = (int)(local_bc - (float)iVar8);
      plight->ambientlight = iVar5;
      if (fVar12 == 0.0) {
        plight->color[0] = 1.0;
        plight->color[1] = 1.0;
        plight->color[2] = 1.0;
      }
      else {
        fVar12 = 1.0 / fVar12;
        plight->color[0] = local_a4 * fVar12;
        plight->color[1] = local_a8 * fVar12;
        plight->color[2] = fVar12 * (float)local_b4;
      }
      if (0x80 < iVar5) {
        plight->ambientlight = 0x80;
        iVar5 = 0x80;
      }
      if (0xff < iVar8 + iVar5) {
        plight->shadelight = 0xff - iVar5;
      }
      VectorNormalize(&local_5c);
      *plight->plightvec = local_5c;
      plight->plightvec[1] = local_58;
      plight->plightvec[2] = local_54;
      return;
    }
  } while( true );
}


// R_StudioDynamicLight  @ 0013ab70
void R_StudioDynamicLight(cl_entity_t *ent,alight_t *plight)

{
  float fVar1;
  float fVar2;
  
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
  if (filterMode == false) {
    R_StudioDynamicLight(ent,plight);
    return;
  }
  fVar1 = filterBrightness * 192.0;
  plight->shadelight = 0;
  plight->ambientlight = (int)fVar1;
  *plight->plightvec = 0.0;
  fVar2 = filterBrightness;
  fVar1 = filterColorRed * filterBrightness;
  plight->plightvec[1] = 0.0;
  plight->plightvec[2] = -1.0;
  plight->color[0] = fVar1;
  plight->color[1] = filterColorGreen * fVar2;
  plight->color[2] = fVar2 * filterColorBlue;
  return;
}


// R_StudioEntityLight  @ 00139860
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
  float fVar9;
  double dVar10;
  cl_entity_t *pcVar11;
  dlight_t *pdVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  float local_1c [4];
  
  pcVar11 = currententity;
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
  dVar10 = cl.time;
  numlights = 0;
  pdVar12 = cl_elights;
  local_1c[0] = 0.0;
  local_1c[1] = 0.0;
  fVar1 = currententity->origin[0];
  fVar2 = currententity->origin[1];
  local_1c[2] = 0.0;
  fVar3 = currententity->origin[2];
  fVar9 = 1e+06;
  do {
    while (((double)pdVar12->die <= dVar10 || (fVar4 = pdVar12->radius, fVar4 <= 0.0))) {
LAB_001398f0:
      pdVar12 = pdVar12 + 1;
      if (pdVar12 == (dlight_t *)&cl_playerindex) {
        return;
      }
    }
    if ((pdVar12->key & 0xfffU) == pcVar11->index) {
                    /* Unresolved local var: int att@[???] */
      uVar15 = pdVar12->key >> 0xc & 0xf;
      if (uVar15 == 0) {
        fVar5 = pcVar11->origin[0];
        pdVar12->origin[0] = fVar5;
        fVar6 = pcVar11->origin[1];
        pdVar12->origin[1] = fVar6;
        fVar7 = pcVar11->origin[2];
        pdVar12->origin[2] = fVar7;
      }
      else {
        fVar5 = pcVar11->angles[uVar15 * 3];
        pdVar12->origin[0] = fVar5;
        fVar6 = pcVar11->attachment[uVar15 - 1][1];
        pdVar12->origin[1] = fVar6;
        fVar7 = pcVar11->attachment[uVar15 - 1][2];
        pdVar12->origin[2] = fVar7;
      }
    }
    else {
      fVar5 = pdVar12->origin[0];
      fVar6 = pdVar12->origin[1];
      fVar7 = pdVar12->origin[2];
    }
    fVar5 = fVar1 - fVar5;
    fVar6 = fVar2 - fVar6;
    fVar7 = fVar3 - fVar7;
    fVar5 = fVar7 * fVar7 + fVar6 * fVar6 + fVar5 * fVar5;
    fVar4 = fVar4 * fVar4;
    if (fVar4 < fVar5) {
      fVar5 = fVar4 / fVar5;
      if (fVar5 <= 0.004) goto LAB_001398f0;
    }
    else {
      fVar5 = 1.0;
    }
    iVar14 = numlights;
    if (2 < numlights) {
      iVar14 = -1;
      iVar13 = 0;
      do {
        fVar6 = local_1c[iVar13];
        if ((fVar6 < fVar9) && (fVar6 < fVar5)) {
          iVar14 = iVar13;
          fVar9 = fVar6;
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 != numlights);
    }
    if (iVar14 == -1) goto LAB_001398f0;
    bVar8 = (pdVar12->color).r;
    locallight[iVar14] = pdVar12;
    local_1c[iVar14] = fVar5;
    locallightR2[iVar14] = fVar4;
    locallinearlight[iVar14][0] = lineargammatable[(uint)bVar8 * 4];
    locallinearlight[iVar14][1] = lineargammatable[(uint)(pdVar12->color).g * 4];
    locallinearlight[iVar14][2] = lineargammatable[(uint)(pdVar12->color).b * 4];
    if (numlights <= iVar14) {
      numlights = iVar14 + 1;
    }
    pdVar12 = pdVar12 + 1;
    if (pdVar12 == (dlight_t *)&cl_playerindex) {
      return;
    }
  } while( true );
}


// R_StudioEstimateGait  @ 00142a60
void R_StudioEstimateGait(entity_state_t *pplayer)

{
  float fVar1;
  player_info_t *ppVar2;
  cl_entity_t *pcVar3;
  float fVar4;
  double dVar5;
  vec_t local_1c;
  vec_t local_18;
  float local_14;
  
  pcVar3 = currententity;
                    /* Unresolved local var: float dt@[???]
                       Unresolved local var: vec3_t est_velocity@[???] */
  ppVar2 = r_playerinfo;
  fVar1 = (float)((longdouble)cl.time - (longdouble)cl.oldtime);
  if (fVar1 < 0.0) {
    r_gaitmovement = 0.0;
    return;
  }
  if (1.0 < fVar1) {
    fVar1 = 1.0;
  }
  else if (fVar1 == 0.0) {
    r_gaitmovement = 0.0;
    return;
  }
  if (r_playerinfo->renderframe == r_framecount) {
    r_gaitmovement = 0.0;
    return;
  }
  if (cl_gaitestimation.value == 0.0) {
    local_1c = pplayer->velocity[0];
    local_18 = pplayer->velocity[1];
    local_14 = pplayer->velocity[2];
    fVar4 = Length(&local_1c);
    r_gaitmovement = fVar4 * fVar1;
  }
  else {
    local_1c = currententity->origin[0] - r_playerinfo->prevgaitorigin[0];
    local_18 = currententity->origin[1] - r_playerinfo->prevgaitorigin[1];
    local_14 = currententity->origin[2] - r_playerinfo->prevgaitorigin[2];
    r_playerinfo->prevgaitorigin[0] = currententity->origin[0];
    ppVar2->prevgaitorigin[1] = pcVar3->origin[1];
    ppVar2->prevgaitorigin[2] = pcVar3->origin[2];
    r_gaitmovement = Length(&local_1c);
    if ((fVar1 <= 0.0) || (r_gaitmovement / fVar1 < 5.0)) goto LAB_00142c2a;
  }
  ppVar2 = r_playerinfo;
  if ((local_18 != 0.0) || (local_1c != 0.0)) {
    dVar5 = atan2((double)local_18,(double)local_1c);
    fVar1 = ((float)dVar5 * 180.0) / 3.1415927;
    ppVar2->gaityaw = fVar1;
    if (180.0 < fVar1) {
      ppVar2->gaityaw = 180.0;
      return;
    }
    if (fVar1 < -180.0) {
      ppVar2->gaityaw = -180.0;
      return;
    }
    return;
  }
LAB_00142c2a:
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


// R_StudioFlushSkins  @ 00142110
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


// R_StudioGetSkin  @ 00142220
skin_t * R_StudioGetSkin(int keynum,int index)

{
  skin_t (*pasVar1) [11];
  int iVar2;
  skin_t *psVar3;
  
                    /* Unresolved local var: skin_t * pskin@[???] */
  iVar2 = r_remapindex;
  if (10 < index) {
    index = 0;
  }
  psVar3 = pDM_RemapSkin[keynum][index];
  if ((psVar3 == (skin_t *)0x0) || (psVar3->keynum != keynum)) {
    psVar3 = DM_RemapSkin[r_remapindex] + index;
    pasVar1 = DM_RemapSkin + r_remapindex;
    r_remapindex = (r_remapindex + 1) % 0x40;
    (*pasVar1)[index].keynum = keynum;
    pDM_RemapSkin[keynum][index] = psVar3;
    DM_RemapSkin[iVar2][index].topcolor = -1;
    DM_RemapSkin[iVar2][index].bottomcolor = -1;
  }
  return psVar3;
}


// R_StudioHull  @ 0013d2f0
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
        if (iVar22 <= iVar19) goto LAB_0013d730;
      }
      iVar19 = 0x16;
      iVar21 = iVar21 + 6;
      pcVar20 = pcVar20 + 0x20;
      pmVar15 = pmVar15 + 6;
    } while (0x16 < iVar22);
  }
LAB_0013d730:
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


// R_StudioLighting  @ 00140470
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
    iVar3 = 0;
    if (fVar1 <= 0.0) goto LAB_001404d0;
  }
  else {
    fVar1 = r_shadelight * 0.8 + fVar1;
  }
  iVar3 = 0x3fc;
  if (fVar1 <= 255.0) {
    iVar3 = (int)(fVar1 * 4.0);
  }
LAB_001404d0:
  *lv = (float)lightgammatable[iVar3] * 0.0009775171;
  return;
}


// R_StudioMergeBones  @ 0013ffb0
void R_StudioMergeBones(model_t *psubmodel)

{
  mstudioseqdesc_t *pseqdesc;
  studiohdr_t *psVar1;
  int iVar2;
  mstudioanim_t *panim;
  int iVar3;
  int iVar4;
  char (*s2) [32];
  vec_t *s1;
  float f;
  float (*local_5c) [3] [4];
  vec_t (*local_58) [3];
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
  iVar2 = (currententity->curstate).sequence;
  if (iVar2 < pstudiohdr->numseq) {
    iVar2 = iVar2 * 0xb0;
  }
  else {
    iVar2 = 0;
    (currententity->curstate).sequence = 0;
  }
  pseqdesc = (mstudioseqdesc_t *)(psVar1->name + iVar2 + psVar1->seqindex + -8);
  f = CL_StudioEstimateFrame(pseqdesc);
  panim = R_GetAnim(psubmodel,pseqdesc);
  R_StudioCalcRotations(R_StudioMergeBones::pos,R_StudioMergeBones::q,pseqdesc,panim,f);
  s1 = (vec_t *)(pstudiohdr->name + pstudiohdr->boneindex + -8);
  if (0 < pstudiohdr->numbones) {
    iVar2 = 0;
    local_5c = bonetransform;
    local_54 = lighttransform;
    local_50 = R_StudioMergeBones::q;
    local_58 = R_StudioMergeBones::pos;
    do {
      if (0 < cached_numbones) {
        s2 = cached_bonename;
        iVar4 = 0;
        do {
          iVar3 = Q_stricmp((char *)s1,*s2);
          if (iVar3 == 0) {
            Q_memcpy(local_5c,cached_bonetransform + iVar4,0x30);
            Q_memcpy(local_54,cached_lighttransform + iVar4,0x30);
            if (iVar4 < cached_numbones) goto LAB_001400fc;
            break;
          }
          iVar4 = iVar4 + 1;
          s2 = s2 + 1;
        } while (iVar4 < cached_numbones);
      }
      QuaternionMatrix(*local_50,(float (*) [4])local_4c);
      local_40 = (*local_58)[0];
      local_30 = (*local_58)[1];
      local_20 = (*local_58)[2];
      if (s1[8] == -NAN) {
        R_ConcatTransforms(rotationmatrix,(float (*) [4])local_4c,*local_5c);
        R_ConcatTransforms(rotationmatrix,(float (*) [4])local_4c,*local_54);
        CL_FxTransform(currententity,*local_5c);
      }
      else {
        R_ConcatTransforms(bonetransform[(int)s1[8]],(float (*) [4])local_4c,*local_5c);
        R_ConcatTransforms(lighttransform[(int)s1[8]],(float (*) [4])local_4c,*local_54);
      }
LAB_001400fc:
      iVar2 = iVar2 + 1;
      s1 = s1 + 0x1c;
      local_5c = local_5c + 1;
      local_54 = local_54 + 1;
      local_50 = local_50 + 1;
      local_58 = local_58 + 1;
    } while (iVar2 < pstudiohdr->numbones);
  }
  return;
}


// R_StudioPlayerBlend  @ 0013dc30
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


// R_StudioProcessGait  @ 00142d70
void R_StudioProcessGait(entity_state_t *pplayer)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  studiohdr_t *psVar5;
  player_info_t *ppVar6;
  cl_entity_t *pcVar7;
  int iVar8;
  byte bVar9;
  byte local_10 [8];
  
  pcVar7 = currententity;
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
  R_StudioPlayerBlend((mstudioseqdesc_t *)(psVar5->name + iVar8 + psVar5->seqindex + -8),
                      (int *)local_10,pcVar7->angles);
  pcVar7 = currententity;
  (currententity->latched).prevangles[0] = currententity->angles[0];
  (pcVar7->curstate).blending[0] = local_10[0];
  (pcVar7->latched).prevblending[0] = local_10[0];
  (pcVar7->latched).prevseqblending[0] = local_10[0];
  fVar1 = (float)((longdouble)cl.time - (longdouble)cl.oldtime);
  fVar3 = 0.0;
  if ((0.0 <= fVar1) && (fVar3 = fVar1, 1.0 < fVar1)) {
    fVar3 = 1.0;
  }
  R_StudioEstimateGait(pplayer);
  pcVar7 = currententity;
  ppVar6 = r_playerinfo;
  fVar1 = r_playerinfo->gaityaw;
  fVar4 = currententity->angles[1] - fVar1;
  fVar4 = fVar4 - (float)((int)(fVar4 / 360.0) * 0x168);
  if (fVar4 < -180.0) {
    fVar4 = fVar4 + 360.0;
  }
  if (180.0 < fVar4) {
    fVar4 = fVar4 - 360.0;
  }
  if (fVar4 <= 120.0) {
    if (fVar4 < -120.0) {
      r_playerinfo->gaityaw = fVar1 + 180.0;
      r_gaitmovement = -r_gaitmovement;
      fVar4 = fVar4 + 180.0;
    }
  }
  else {
    r_playerinfo->gaityaw = fVar1 - 180.0;
    r_gaitmovement = -r_gaitmovement;
    fVar4 = fVar4 - 180.0;
  }
  bVar9 = (byte)(int)((fVar4 * 0.25 + 30.0) / 0.23529412);
  (pcVar7->curstate).controller[0] = bVar9;
  (pcVar7->curstate).controller[1] = bVar9;
  (pcVar7->curstate).controller[2] = bVar9;
  (pcVar7->curstate).controller[3] = bVar9;
  (pcVar7->latched).prevcontroller[0] = bVar9;
  (pcVar7->latched).prevcontroller[1] = bVar9;
  (pcVar7->latched).prevcontroller[2] = bVar9;
  (pcVar7->latched).prevcontroller[3] = bVar9;
  fVar1 = ppVar6->gaityaw;
  pcVar7->angles[1] = fVar1;
  if (fVar1 < 0.0) {
    fVar1 = fVar1 + 360.0;
    pcVar7->angles[1] = fVar1;
  }
  (pcVar7->latched).prevangles[1] = fVar1;
  psVar5 = pstudiohdr;
  iVar8 = pplayer->gaitsequence * 0xb0 + pstudiohdr->seqindex;
  fVar1 = *(float *)((int)pstudiohdr->eyeposition + iVar8);
  if (fVar1 <= 0.0) {
    fVar1 = *(float *)(pstudiohdr->name + iVar8 + 0x18) * fVar3 + ppVar6->gaitframe;
    ppVar6->gaitframe = fVar1;
  }
  else {
    fVar1 = (float)*(int *)(pstudiohdr->name + iVar8 + 0x30) * (r_gaitmovement / fVar1) +
            ppVar6->gaitframe;
    ppVar6->gaitframe = fVar1;
  }
  iVar2 = *(int *)(psVar5->name + iVar8 + 0x30);
  fVar1 = fVar1 - (float)(iVar2 * (int)(fVar1 / (float)iVar2));
  ppVar6->gaitframe = fVar1;
  if (fVar1 < 0.0) {
    ppVar6->gaitframe = (float)*(int *)(psVar5->name + iVar8 + 0x30) + fVar1;
  }
  return;
}


// R_StudioReloadSkin  @ 001424a0
uchar * R_StudioReloadSkin(model_t *pModel,int index,skin_t *pskin)

{
  int iVar1;
  int iVar2;
  int *dest;
  void *pvVar3;
  byte *p;
  int iVar4;
  int iVar5;
  int *piVar6;
  
                    /* Unresolved local var: int modelindex@[???]
                       Unresolved local var: cache_user_t * pCache@[???]
                       Unresolved local var: int * pData@[???]
                       Unresolved local var: mstudiotexture_t * ptexture@[???]
                       Unresolved local var: uchar * pbase@[???]
                       Unresolved local var: int size@[???] */
  dest = (int *)0x0;
  iVar5 = (int)&pModel[-0x9aa7].numedges >> 3;
  if ((uint)(iVar5 * 0x1a1f58d1) < 0x400) {
    pvVar3 = Cache_Check(model_texture_cache[iVar5 * 0x1f58d1] + index);
    if (pvVar3 == (void *)0x0) {
      p = COM_LoadFileForMe(pModel->name,(int *)0x0);
      iVar4 = index * 0x50 + *(int *)(p + 0xb8);
      iVar1 = *(int *)(p + iVar4 + 0x44);
      iVar2 = *(int *)(p + iVar4 + 0x48);
      Cache_Alloc(model_texture_cache[iVar5 * 0x1f58d1] + index,iVar1 * iVar2 + 0x308,pskin->name);
      piVar6 = model_texture_cache[iVar5 * 0x1f58d1][index].data;
      *piVar6 = *(int *)(p + iVar4 + 0x44);
      piVar6[1] = *(int *)(p + iVar4 + 0x48);
      dest = piVar6 + 2;
      Q_memcpy(dest,p + *(int *)(p + iVar4 + 0x4c),iVar1 * iVar2 + 0x300);
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
  return (uchar *)dest;
}


// R_StudioRenderFinal  @ 00144900
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioRenderFinal(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int local_2c;
  
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
    local_2c = 0;
    do {
                    /* Unresolved local var: int index@[???] */
      pbodypart = (mstudiobodyparts_t *)(pstudiohdr->name + pstudiohdr->bodypartindex + iVar2 + -8);
      psubmodel = (mstudiomodel_t *)
                  (pstudiohdr->name +
                  (((currententity->curstate).body / pbodypart->base) % pbodypart->nummodels) * 0x70
                  + pbodypart->modelindex + -8);
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
      if (((iVar3 != 5) && (r_shadows.value != 0.0)) && ((r_model->flags & 0x100) == 0)) {
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
        (*qglEnable)(0xde1);
        (*qglDisable)(0xbe2);
        (*qglColor4f)(1.0,1.0,1.0,1.0);
        (*qglShadeModel)(0x1d01);
      }
      local_2c = local_2c + 1;
      iVar2 = iVar2 + 0x4c;
    } while (local_2c < pstudiohdr->numbodyparts);
  }
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
  if (gl_affinemodels.value != 0.0) {
    (*qglHint)(0xc50,0x1102);
                    /* WARNING: Could not recover jumptable at 0x00144d22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglPopMatrix)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00144cfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglPopMatrix)();
  return;
}


// R_StudioRenderModel  @ 00144ec0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioRenderModel(void)

{
  g_ForcedFaceFlags = 0;
  g_ChromeOrigin[0] = r_origin[0];
  g_ChromeOrigin[1] = r_origin[1];
  g_ChromeOrigin[2] = r_origin[2];
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


// R_StudioSaveBones  @ 0013fee0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioSaveBones(void)

{
  float (*paafVar1) [3] [4];
  float (*paafVar2) [3] [4];
  float (*dest) [3] [4];
  vec_t *src;
  char (*dest_00) [32];
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: mstudiobone_t * pbones@[???] */
  cached_numbones = pstudiohdr->numbones;
  if (0 < cached_numbones) {
    dest = cached_bonetransform;
    iVar3 = 0;
    dest_00 = cached_bonename;
    src = (vec_t *)(pstudiohdr->name + pstudiohdr->boneindex + -8);
    do {
      iVar3 = iVar3 + 1;
      Q_strncpy(*dest_00,(char *)src,0x1f);
      (*dest_00)[0x1f] = '\0';
      dest_00 = dest_00 + 1;
      Q_memcpy(dest,dest + -0xb2e,0x30);
      paafVar1 = dest + -0xbaf;
      paafVar2 = dest + -0x1d7d;
      dest = dest + 1;
      Q_memcpy(*paafVar2 + 1,*paafVar1 + 1,0x30);
      src = src + 0x1c;
    } while (iVar3 < pstudiohdr->numbones);
  }
  return;
}


// R_StudioSetUpTransform  @ 0013ec60
void R_StudioSetUpTransform(int trivial_accept)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float local_2c;
  float local_28;
  float local_24;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t angles@[???]
                       Unresolved local var: vec3_t modelpos@[???] */
  local_1c = currententity->origin[0];
  local_18 = currententity->origin[1];
  local_14 = currententity->origin[2];
  local_24 = (currententity->curstate).angles[2];
  local_2c = (currententity->curstate).angles[0];
  local_28 = (currententity->curstate).angles[1];
  iVar4 = (currententity->curstate).movetype;
  if (iVar4 == 4) {
                    /* Unresolved local var: float f@[???]
                       Unresolved local var: float d@[???] */
    fVar1 = (currententity->curstate).animtime;
    if ((fVar1 + 1.0 <= (float)cl.time) ||
       (fVar2 = (currententity->latched).prevanimtime, fVar1 == fVar2)) {
      fVar5 = 0.0;
      fVar1 = local_1c;
      fVar3 = local_14;
      fVar2 = local_18;
    }
    else {
      fVar5 = ((float)cl.time - fVar1) / (fVar1 - fVar2);
      fVar1 = currententity->origin[0];
      fVar2 = currententity->origin[1];
      fVar3 = currententity->origin[2];
    }
    if (r_dointerp == 0) {
      fVar5 = 0.0;
    }
    else {
      fVar5 = fVar5 - 1.0;
    }
    local_1c = (fVar1 - (currententity->latched).prevorigin[0]) * fVar5 + local_1c;
    local_18 = (fVar2 - (currententity->latched).prevorigin[1]) * fVar5 + local_18;
    local_14 = (fVar3 - (currententity->latched).prevorigin[2]) * fVar5 + local_14;
                    /* Unresolved local var: float ang1@[???]
                       Unresolved local var: float ang2@[???] */
    fVar1 = currententity->angles[0] - (currententity->latched).prevangles[0];
    if (180.0 < fVar1) {
      fVar1 = fVar1 - 360.0;
    }
    else if (fVar1 < -180.0) {
      fVar1 = fVar1 + 360.0;
    }
    local_2c = fVar1 * fVar5 + local_2c;
    fVar1 = currententity->angles[1] - (currententity->latched).prevangles[1];
    if (180.0 < fVar1) {
      fVar1 = fVar1 - 360.0;
    }
    else if (fVar1 < -180.0) {
      fVar1 = fVar1 + 360.0;
    }
    local_28 = fVar1 * fVar5 + local_28;
    fVar1 = currententity->angles[2] - (currententity->latched).prevangles[2];
    if (fVar1 <= 180.0) {
      if (fVar1 < -180.0) {
        fVar1 = fVar1 + 360.0;
      }
    }
    else {
      fVar1 = fVar1 - 360.0;
    }
    local_24 = fVar1 * fVar5 + local_24;
  }
  else if (iVar4 != 0) {
    local_28 = currententity->angles[1];
    local_2c = currententity->angles[0];
    local_24 = currententity->angles[2];
  }
  fVar3 = local_14;
  fVar2 = local_18;
  fVar1 = local_1c;
  local_2c = -local_2c;
  AngleMatrix(&local_2c,rotationmatrix);
  rotationmatrix[0][3] = fVar1;
  rotationmatrix[1][3] = fVar2;
  rotationmatrix[2][3] = fVar3;
  return;
}


// R_StudioSetupBones  @ 0013f6b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_StudioSetupBones(void)

{
  float fVar1;
  float fVar2;
  mstudioanim_t *pmVar3;
  studiohdr_t *psVar4;
  int iVar5;
  studiohdr_t *psVar6;
  int iVar7;
  int iVar8;
  vec_t (*pavVar9) [3];
  mstudioseqdesc_t *pmVar10;
  vec_t (*dest) [4];
  int *piVar11;
  vec_t *s1;
  float (*out) [3] [4];
  float f;
  vec_t (*local_5c) [4];
  float (*local_58) [3] [4];
  float local_4c [3];
  vec_t local_40;
  vec_t local_30;
  vec_t local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: double f@[???]
                       Unresolved local var: mstudiobone_t * pbones@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: mstudioanim_t * panim@[???]
                       Unresolved local var: float[3][4] bonematrix@[???] */
  psVar4 = pstudiohdr;
  iVar7 = (currententity->curstate).sequence;
  if (iVar7 < pstudiohdr->numseq) {
    iVar7 = iVar7 * 0xb0;
  }
  else {
    iVar7 = 0;
    (currententity->curstate).sequence = 0;
  }
  pmVar10 = (mstudioseqdesc_t *)(psVar4->name + iVar7 + psVar4->seqindex + -8);
  f = CL_StudioEstimateFrame(pmVar10);
  pmVar3 = R_GetAnim(r_model,pmVar10);
  R_StudioCalcRotations(R_StudioSetupBones::pos,R_StudioSetupBones::q,pmVar10,pmVar3,f);
  if (1 < pmVar10->numblends) {
                    /* Unresolved local var: float s@[???]
                       Unresolved local var: float dadt@[DW_OP_reg11(ST0)] */
    pmVar3 = pmVar3 + pstudiohdr->numbones;
    R_StudioCalcRotations(R_StudioSetupBones::pos2,R_StudioSetupBones::q2,pmVar10,pmVar3,f);
                    /* Unresolved local var: float dadt@[???] */
    if ((r_dointerp == 0) ||
       (fVar1 = (currententity->curstate).animtime,
       fVar1 < (currententity->latched).prevanimtime + 0.01)) {
      fVar1 = 1.0;
    }
    else {
                    /* Unresolved local var: float dadt@[???] */
      fVar1 = ((float)cl.time - fVar1) / 0.1;
      if (2.0 < fVar1) {
        fVar1 = 2.0;
      }
    }
    fVar2 = 1.0 - fVar1;
    R_StudioSlerpBones(R_StudioSetupBones::q,R_StudioSetupBones::pos,R_StudioSetupBones::q2,
                       R_StudioSetupBones::pos2,
                       ((float)(currententity->latched).prevblending[0] * fVar2 +
                       (float)(currententity->curstate).blending[0] * fVar1) / 255.0);
    if (pmVar10->numblends == 4) {
      iVar7 = pstudiohdr->numbones;
      R_StudioCalcRotations
                (R_StudioSetupBones::pos3,R_StudioSetupBones::q3,pmVar10,pmVar3 + iVar7,f);
      R_StudioCalcRotations
                (R_StudioSetupBones::pos4,R_StudioSetupBones::q4,pmVar10,
                 pmVar3 + iVar7 + pstudiohdr->numbones,f);
      R_StudioSlerpBones(R_StudioSetupBones::q3,R_StudioSetupBones::pos3,R_StudioSetupBones::q4,
                         R_StudioSetupBones::pos4,
                         (fVar2 * (float)(currententity->latched).prevblending[0] +
                         fVar1 * (float)(currententity->curstate).blending[0]) / 255.0);
      R_StudioSlerpBones(R_StudioSetupBones::q,R_StudioSetupBones::pos,R_StudioSetupBones::q3,
                         R_StudioSetupBones::pos3,
                         (fVar2 * (float)(currententity->latched).prevblending[1] +
                         fVar1 * (float)(currententity->curstate).blending[1]) / 255.0);
    }
  }
  psVar4 = pstudiohdr;
  if ((((r_dointerp == 0) || (fVar1 = (currententity->latched).sequencetime, fVar1 == 0.0)) ||
      (fVar1 + 0.2 <= (float)cl.time)) ||
     (iVar7 = (currententity->latched).prevsequence, pstudiohdr->numseq <= iVar7)) {
    (currententity->latched).prevframe = f;
  }
  else {
                    /* Unresolved local var: float s@[???] */
    pmVar10 = (mstudioseqdesc_t *)(pstudiohdr->name + iVar7 * 0xb0 + pstudiohdr->seqindex + -8);
    pmVar3 = R_GetAnim(r_model,pmVar10);
    R_StudioCalcRotations
              (R_StudioSetupBones::lexical_block_1::pos1b,R_StudioSetupBones::lexical_block_1::q1b,
               pmVar10,pmVar3,(currententity->latched).prevframe);
    if (1 < pmVar10->numblends) {
      pmVar3 = pmVar3 + pstudiohdr->numbones;
      R_StudioCalcRotations
                (R_StudioSetupBones::pos2,R_StudioSetupBones::q2,pmVar10,pmVar3,
                 (currententity->latched).prevframe);
      R_StudioSlerpBones(R_StudioSetupBones::lexical_block_1::q1b,
                         R_StudioSetupBones::lexical_block_1::pos1b,R_StudioSetupBones::q2,
                         R_StudioSetupBones::pos2,
                         (float)(currententity->latched).prevseqblending[0] / 255.0);
      if (pmVar10->numblends == 4) {
        iVar7 = pstudiohdr->numbones;
        R_StudioCalcRotations
                  (R_StudioSetupBones::pos3,R_StudioSetupBones::q3,pmVar10,pmVar3 + iVar7,
                   (currententity->latched).prevframe);
        R_StudioCalcRotations
                  (R_StudioSetupBones::pos4,R_StudioSetupBones::q4,pmVar10,
                   pmVar3 + iVar7 + pstudiohdr->numbones,(currententity->latched).prevframe);
        R_StudioSlerpBones(R_StudioSetupBones::q3,R_StudioSetupBones::pos3,R_StudioSetupBones::q4,
                           R_StudioSetupBones::pos4,
                           (float)(currententity->latched).prevseqblending[0] / 255.0);
        R_StudioSlerpBones(R_StudioSetupBones::lexical_block_1::q1b,
                           R_StudioSetupBones::lexical_block_1::pos1b,R_StudioSetupBones::q3,
                           R_StudioSetupBones::pos3,
                           (float)(currententity->latched).prevseqblending[1] / 255.0);
      }
    }
    R_StudioSlerpBones(R_StudioSetupBones::q,R_StudioSetupBones::pos,
                       R_StudioSetupBones::lexical_block_1::q1b,
                       R_StudioSetupBones::lexical_block_1::pos1b,
                       1.0 - ((float)cl.time - (currententity->latched).sequencetime) / 0.2);
    psVar4 = pstudiohdr;
  }
  iVar7 = psVar4->boneindex;
  psVar6 = psVar4;
  if ((r_playerinfo == (player_info_t *)0x0) || (iVar8 = r_playerinfo->gaitsequence, iVar8 == 0)) {
LAB_0013f9ae:
    iVar5 = psVar6->numbones;
  }
  else {
    if (iVar8 < psVar4->numseq) {
      iVar8 = iVar8 * 0xb0;
    }
    else {
      r_playerinfo->gaitsequence = 0;
      iVar8 = 0;
    }
    iVar5 = psVar4->seqindex;
    pmVar3 = R_GetAnim(r_model,(mstudioseqdesc_t *)(psVar4->name + iVar8 + iVar5 + -8));
    R_StudioCalcRotations
              (R_StudioSetupBones::pos2,R_StudioSetupBones::q2,
               (mstudioseqdesc_t *)(psVar4->name + iVar8 + iVar5 + -8),pmVar3,
               r_playerinfo->gaitframe);
    if (pstudiohdr->numbones < 1) {
      return;
    }
    iVar8 = 0;
    pavVar9 = R_StudioSetupBones::pos;
    dest = R_StudioSetupBones::q;
    s1 = (vec_t *)(psVar4->name + iVar7 + -8);
    do {
      iVar5 = Q_strcmp((char *)s1,"Bip01 Spine");
      psVar6 = pstudiohdr;
      if (iVar5 == 0) goto LAB_0013f9ae;
      iVar8 = iVar8 + 1;
      s1 = s1 + 0x1c;
      Q_memcpy(pavVar9,pavVar9[0x12a] + 2,0xc);
      Q_memcpy(dest,dest + 0xe0,0x10);
      iVar5 = pstudiohdr->numbones;
      pavVar9 = pavVar9 + 1;
      dest = dest + 1;
    } while (iVar8 < iVar5);
  }
  if (0 < iVar5) {
    local_5c = R_StudioSetupBones::q;
    out = bonetransform;
    pavVar9 = R_StudioSetupBones::pos;
    local_58 = lighttransform;
    iVar8 = 0;
    piVar11 = (int *)((int)(psVar4->name + iVar7 + -8) + 0x20);
    do {
      QuaternionMatrix(*local_5c,(float (*) [4])local_4c);
      local_40 = (*pavVar9)[0];
      local_30 = (*pavVar9)[1];
      local_20 = (*pavVar9)[2];
      if (*piVar11 == -1) {
        R_ConcatTransforms(rotationmatrix,(float (*) [4])local_4c,*out);
        R_ConcatTransforms(rotationmatrix,(float (*) [4])local_4c,*local_58);
        CL_FxTransform(currententity,*out);
      }
      else {
        R_ConcatTransforms(bonetransform[*piVar11],(float (*) [4])local_4c,*out);
        R_ConcatTransforms(lighttransform[*piVar11],(float (*) [4])local_4c,*local_58);
      }
      iVar8 = iVar8 + 1;
      pavVar9 = pavVar9 + 1;
      local_5c = local_5c + 1;
      piVar11 = piVar11 + 0x1c;
      out = out + 1;
      local_58 = local_58 + 1;
    } while (iVar8 < pstudiohdr->numbones);
  }
  return;
}


// R_StudioSetupLighting  @ 0013b190
void R_StudioSetupLighting(alight_t *plighting)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  studiohdr_t *psVar5;
  float (*pafVar6) [4];
  float (*pafVar7) [4];
  vec_t (*pavVar8) [3];
  int iVar9;
  
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
    pafVar7 = lighttransform[0] + 2;
    pavVar8 = r_blightvec;
    iVar9 = 0;
    pafVar6 = lighttransform[0] + 1;
    do {
      iVar9 = iVar9 + 1;
      (*pavVar8)[0] =
           (*pafVar7)[0] * fVar3 +
           (*pafVar6)[0] * fVar2 + (*(float (*) [3] [4])(pafVar6 + -1))[0][0] * fVar1;
      (*pavVar8)[1] =
           (*pafVar7)[1] * fVar3 +
           (*pafVar6)[1] * fVar2 + (*(float (*) [3] [4])(pafVar6 + -1))[0][1] * fVar1;
      pfVar4 = *pafVar7;
      pafVar7 = pafVar7 + 3;
      (*pavVar8)[2] =
           pfVar4[2] * fVar3 +
           (*pafVar6)[2] * fVar2 + (*(float (*) [3] [4])(pafVar6 + -1))[0][2] * fVar1;
      pavVar8 = pavVar8 + 1;
      pafVar6 = pafVar6 + 3;
    } while (iVar9 < psVar5->numbones);
  }
  r_icolormix.r = (int)(plighting->color[0] * 49407.0) & 0xff00;
  r_icolormix.g = (int)(plighting->color[1] * 49407.0) & 0xff00;
  r_icolormix.b = (int)(plighting->color[2] * 49407.0) & 0xff00;
  r_colormix[1] = plighting->color[1];
  r_colormix[2] = plighting->color[2];
  r_colormix[0] = plighting->color[0];
  return;
}


// R_StudioSetupModel  @ 001429e0
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


// R_StudioSetupSkin  @ 001425e0
void __regparm3 R_StudioSetupSkin(studiohdr_t *ptexturehdr,int index)

{
  int iVar1;
  float fVar2;
  model_t *pModel;
  cl_entity_t *pcVar3;
  int iVar4;
  uchar *data;
  vec_t texnum;
  int iVar5;
  skin_t *pskin;
  char *s1;
  uchar *end;
  char local_128 [256];
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: mstudiotexture_t * ptexture@[???]
                       Unresolved local var: float temp@[???] */
  s1 = ptexturehdr->name + index * 0x50 + ptexturehdr->textureindex + -8;
  if (0 < currententity->index) {
                    /* Unresolved local var: int l@[???]
                       Unresolved local var: int m@[???]
                       Unresolved local var: int h@[???] */
    local_20[0] = 0xdf;
    local_28 = 0xa0;
    local_24 = 0xbf;
    iVar4 = Q_stricmp(s1,"DM_Base.bmp");
    if ((iVar4 == 0) || (iVar4 = R_IsRemapSkin(s1,&local_28,&local_24,local_20), iVar4 != 0)) {
                    /* Unresolved local var: skin_t * pskin@[DW_OP_reg3(EBX)] */
      pcVar3 = currententity;
      iVar4 = r_remapindex;
                    /* Unresolved local var: skin_t * pskin@[???] */
      iVar5 = 0;
      if (index < 0xb) {
        iVar5 = index;
      }
      iVar1 = currententity->index;
      pskin = pDM_RemapSkin[iVar1][iVar5];
      if ((pskin == (skin_t *)0x0) || (iVar1 != pskin->keynum)) {
        pskin = DM_RemapSkin[r_remapindex] + iVar5;
        r_remapindex = (r_remapindex + 1) % 0x40;
        pDM_RemapSkin[iVar1][iVar5] = pskin;
        DM_RemapSkin[iVar4][iVar5].keynum = iVar1;
        DM_RemapSkin[iVar4][iVar5].topcolor = -1;
        DM_RemapSkin[iVar4][iVar5].bottomcolor = -1;
      }
      pModel = r_model;
      if (((pskin->model == r_model) && (pskin->topcolor == r_topcolor)) &&
         (pskin->bottomcolor == r_bottomcolor)) {
        texnum = (vec_t)pskin->gl_index;
      }
      else {
                    /* Unresolved local var: uchar * orig_palette@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: uchar * pData@[???] */
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
        if (data == (uchar *)0x0) {
          return;
        }
        snprintf(local_128,0x100,"%s%d",s1,currententity->index);
        end = R_StudioSetupSkin::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::
              tmp_palette;
        Q_memcpy(R_StudioSetupSkin::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::
                 tmp_palette,data + (int)*(vec_t *)(s1 + 0x44) * (int)*(vec_t *)(s1 + 0x48),0x300);
        iVar5 = r_bottomcolor;
        pskin->model = r_model;
        iVar4 = r_topcolor;
        pskin->bottomcolor = iVar5;
        pskin->topcolor = iVar4;
        PaletteHueReplace((uchar *)iVar4,local_28,local_24,(int)end);
        if (local_20[0] != 0) {
          PaletteHueReplace((uchar *)pskin->bottomcolor,local_24 + 1,local_20[0],(int)end);
        }
        GL_UnloadTexture(local_128);
        fVar2 = gl_dither.value;
        gl_dither.value = 0.0;
        texnum = (vec_t)GL_LoadTexture(local_128,GLT_STUDIO,pskin->width,pskin->height,data,0,0,
                                       R_StudioSetupSkin::lexical_block_0::lexical_block_0_0::
                                       lexical_block_0_0_0::tmp_palette);
        pskin->gl_index = (int)texnum;
        gl_dither.value = fVar2;
      }
      if (texnum != 0.0) goto LAB_00142919;
    }
  }
  texnum = *(vec_t *)(s1 + 0x4c);
LAB_00142919:
  GL_Bind((int)texnum);
  return;
}


// R_StudioSetupSkin  @ 001429b0
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


// R_StudioSlerpBones  @ 0013cbf0
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


// R_StudioTransformAuxVert  @ 00140210
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


// R_StudioTransformVector  @ 0013e390
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


// R_TeleportSplash  @ 001eb780
void R_TeleportSplash(vec_t *org)

{
  particle_s **pppVar1;
  double dVar2;
  particle_t *ppVar3;
  particle_t *ppVar4;
  int32 iVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  int local_44;
  int local_40;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: particle_t * p@[???]
                       Unresolved local var: float vel@[???]
                       Unresolved local var: vec3_t dir@[???] */
  local_40 = -0x10;
  do {
    local_44 = -0x10;
    do {
      iVar6 = -0x18;
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
        dVar2 = cl.time;
        fVar8 = RandomFloat(0.2,0.34);
        ppVar4->die = (float)dVar2 + fVar8;
        iVar5 = RandomLong(7,0xe);
        ppVar4->packedColor = 0;
        ppVar4->type = pt_slowgrav;
        local_28 = (float)(local_44 << 3);
        ppVar4->color = (short)iVar5;
        local_24 = (float)(local_40 << 3);
        local_20 = (float)(iVar6 * 8);
        fVar8 = *org;
        fVar9 = RandomFloat(0.0,3.0);
        ppVar4->org[0] = (float)local_40 + fVar8 + fVar9;
        fVar8 = org[1];
        fVar9 = RandomFloat(0.0,3.0);
        ppVar4->org[1] = (float)local_44 + fVar8 + fVar9;
        iVar7 = iVar6 + 4;
        fVar8 = org[2];
        fVar9 = RandomFloat(0.0,3.0);
        ppVar4->org[2] = (float)iVar6 + fVar8 + fVar9;
        VectorNormalize(&local_28);
        fVar8 = RandomFloat(50.0,113.0);
        VectorScale(&local_28,fVar8,ppVar4->vel);
        iVar6 = iVar7;
      } while (iVar7 != 0x20);
      local_44 = local_44 + 4;
    } while (local_44 != 0x10);
    local_40 = local_40 + 4;
  } while (local_40 != 0x10);
  return;
}


// R_TempModel  @ 001a53d0
TEMPENTITY *
R_TempModel(float *pos,float *dir,float *angles,float life,int modelIndex,int soundtype)

{
  vec_t vVar1;
  model_t *model;
  int iVar2;
  int32 iVar3;
  TEMPENTITY *pTVar4;
  float fVar5;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: model_t * model@[???]
                       Unresolved local var: int frameCount@[???] */
  pTVar4 = (TEMPENTITY *)0x0;
  if (modelIndex != 0) {
    model = CL_GetModelByIndex(modelIndex);
    if (model == (model_t *)0x0) {
      Con_Printf("No model %d!\n",modelIndex);
    }
    else {
      iVar2 = ModelFrameCount(model);
      pTVar4 = (*efx.CL_TempEntAlloc)(pos,model);
      if (pTVar4 != (TEMPENTITY *)0x0) {
        (pTVar4->entity).angles[0] = *angles;
        (pTVar4->entity).angles[1] = angles[1];
        vVar1 = angles[2];
        pTVar4->frameMax = (float)iVar2;
        pTVar4->flags = pTVar4->flags | 0x22;
        (pTVar4->entity).angles[2] = vVar1;
        if (soundtype == 1) {
          pTVar4->hitSound = 0x20;
          fVar5 = RandomFloat(-512.0,511.0);
          (pTVar4->entity).baseline.angles[0] = fVar5;
          fVar5 = RandomFloat(-256.0,255.0);
          (pTVar4->entity).baseline.angles[1] = fVar5;
          fVar5 = RandomFloat(-256.0,255.0);
          pTVar4->flags = pTVar4->flags | 4;
          (pTVar4->entity).baseline.angles[2] = fVar5;
        }
        else if (soundtype == 2) {
          pTVar4->hitSound = 0x80;
          fVar5 = RandomFloat(-512.0,511.0);
          (pTVar4->entity).baseline.angles[0] = fVar5;
          fVar5 = RandomFloat(-256.0,255.0);
          (pTVar4->entity).baseline.angles[1] = fVar5;
          fVar5 = RandomFloat(-256.0,255.0);
          pTVar4->flags = pTVar4->flags | 0xc;
          (pTVar4->entity).baseline.angles[2] = fVar5;
        }
        else if (soundtype == 0) {
          pTVar4->hitSound = 0;
        }
        (pTVar4->entity).baseline.origin[0] = *dir;
        (pTVar4->entity).baseline.origin[1] = dir[1];
        (pTVar4->entity).baseline.origin[2] = dir[2];
        pTVar4->die = life + (float)cl.time;
        if (model->type == mod_sprite) {
          iVar3 = RandomLong(0,iVar2 + -1);
          (pTVar4->entity).curstate.frame = (float)iVar3;
        }
        else {
          iVar3 = RandomLong(0,iVar2 + -1);
          (pTVar4->entity).curstate.body = iVar3;
        }
      }
    }
  }
  return pTVar4;
}


// R_TempSphereModel  @ 001a4e50
void R_TempSphereModel(float *pos,float speed,float life,int count,int modelIndex)

{
  vec_t *v;
  model_t *model;
  int iVar1;
  uint uVar2;
  TEMPENTITY *pTVar3;
  int32 iVar4;
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
      pTVar3 = (*efx.CL_TempEntAlloc)(pos,model);
      if (pTVar3 == (TEMPENTITY *)0x0) {
        return;
      }
      iVar4 = RandomLong(0,iVar1 + -1);
      (pTVar3->entity).curstate.body = iVar4;
      iVar4 = RandomLong(0,0xff);
      if (iVar4 < 10) {
        pTVar3->flags = pTVar3->flags | 8;
      }
      else {
        pTVar3->flags = pTVar3->flags | 2;
      }
      iVar4 = RandomLong(0,0xff);
      if (iVar4 < 0xdc) {
        pTVar3->flags = pTVar3->flags | 4;
        fVar6 = RandomFloat(-256.0,-255.0);
        (pTVar3->entity).baseline.angles[0] = fVar6;
        fVar6 = RandomFloat(-256.0,-255.0);
        (pTVar3->entity).baseline.angles[1] = fVar6;
        fVar6 = RandomFloat(-256.0,-255.0);
        (pTVar3->entity).baseline.angles[2] = fVar6;
      }
      iVar4 = RandomLong(0,0xff);
      uVar2 = pTVar3->flags;
      if (iVar4 < 100) {
        uVar2 = uVar2 | 0x10;
      }
      pTVar3->flags = uVar2 | 0x60;
      uVar2 = uVar5 + 1;
      (pTVar3->entity).curstate.rendermode = 0;
      (pTVar3->entity).curstate.effects = uVar5 & 0x1f;
      fVar6 = RandomFloat(-1.0,1.0);
      (pTVar3->entity).baseline.origin[0] = fVar6;
      fVar6 = RandomFloat(-1.0,1.0);
      (pTVar3->entity).baseline.origin[1] = fVar6;
      fVar6 = RandomFloat(-1.0,1.0);
      v = (pTVar3->entity).baseline.origin;
      (pTVar3->entity).baseline.origin[2] = fVar6;
      VectorNormalize(v);
      VectorScale(v,speed,v);
      pTVar3->die = life + (float)cl.time;
      uVar5 = uVar2;
    } while (uVar2 != count);
  }
  return;
}


// R_TempSprite  @ 001a5690
TEMPENTITY *
R_TempSprite(float *pos,float *dir,float scale,int modelIndex,int rendermode,int renderfx,float a,
            float life,int flags)

{
  model_t *model;
  int iVar1;
  TEMPENTITY *pTVar2;
  
                    /* Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: model_t * model@[???]
                       Unresolved local var: int frameCount@[???] */
  pTVar2 = (TEMPENTITY *)0x0;
  if (modelIndex != 0) {
    model = CL_GetModelByIndex(modelIndex);
    if (model == (model_t *)0x0) {
      Con_Printf("No model %d!\n",modelIndex);
    }
    else {
      iVar1 = ModelFrameCount(model);
      pTVar2 = (*efx.CL_TempEntAlloc)(pos,model);
      if (pTVar2 != (TEMPENTITY *)0x0) {
        (pTVar2->entity).curstate.framerate = 10.0;
        pTVar2->frameMax = (float)iVar1;
        (pTVar2->entity).curstate.scale = scale;
        (pTVar2->entity).curstate.rendermode = rendermode;
        (pTVar2->entity).curstate.rendercolor.r = 0xff;
        (pTVar2->entity).curstate.rendercolor.g = 0xff;
        (pTVar2->entity).curstate.rendercolor.b = 0xff;
        (pTVar2->entity).curstate.renderfx = renderfx;
        (pTVar2->entity).curstate.renderamt = (int)(a * 255.0);
        (pTVar2->entity).baseline.renderamt = (int)(a * 255.0);
        pTVar2->flags = pTVar2->flags | flags;
        (pTVar2->entity).baseline.origin[0] = *dir;
        (pTVar2->entity).baseline.origin[1] = dir[1];
        (pTVar2->entity).baseline.origin[2] = dir[2];
        (pTVar2->entity).origin[0] = *pos;
        (pTVar2->entity).origin[1] = pos[1];
        (pTVar2->entity).origin[2] = pos[2];
        if (life == 0.0) {
          pTVar2->die = (float)iVar1 * 0.1 + (float)cl.time + 1.0;
        }
        else {
          pTVar2->die = life + (float)cl.time;
        }
        (pTVar2->entity).curstate.frame = 0.0;
      }
    }
  }
  return pTVar2;
}


// R_TextureAnimation  @ 001e33b0
texture_t * R_TextureAnimation(msurface_t *s)

{
  int32 iVar1;
  texture_s *ptVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: texture_t * base@[???]
                       Unresolved local var: int reletive@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int tu@[???]
                       Unresolved local var: int tv@[???]
                       Unresolved local var: texture_t * tm2@[DW_OP_reg3(EBX)] */
  iVar3 = 0;
  ptVar2 = s->texinfo->texture;
  if (R_TextureAnimation::rtable[0][0] == 0) {
    do {
      iVar4 = 0;
      do {
        iVar1 = RandomLong(0,0x7fff);
        *(int32 *)((int)R_TextureAnimation::rtable[0] + iVar4 * 4 + iVar3) = iVar1;
        iVar4 = iVar4 + 1;
      } while (iVar4 != 0x14);
      iVar3 = iVar3 + 0x50;
    } while (iVar3 != 0x640);
  }
  if ((currententity->curstate).frame == 0.0) {
    iVar3 = ptVar2->anim_total;
  }
  else {
    if (ptVar2->alternate_anims != (texture_s *)0x0) {
      ptVar2 = ptVar2->alternate_anims;
    }
    iVar3 = ptVar2->anim_total;
  }
  if (iVar3 != 0) {
    if (ptVar2->name[0] == '-') {
      iVar4 = 0;
      iVar3 = R_TextureAnimation::rtable
              [(int)(((int)s->texturemins[0] + ptVar2->width * 0x10000) / ptVar2->width) % 0x14]
              [(int)((ptVar2->height * 0x10000 + (int)s->texturemins[1]) / ptVar2->height) % 0x14] %
              iVar3;
      while ((iVar3 < ptVar2->anim_min || (ptVar2->anim_max <= iVar3))) {
        ptVar2 = ptVar2->anim_next;
        if (ptVar2 == (texture_s *)0x0) {
          Sys_Error("R_TextureAnimation: broken cycle");
        }
        iVar4 = iVar4 + 1;
        if (100 < iVar4) {
          Sys_Error("R_TextureAnimation: infinite cycle");
        }
      }
    }
    else {
      iVar3 = (int)((float)cl.time * 10.0) % iVar3;
      iVar4 = 0;
      while ((iVar3 < ptVar2->anim_min || (ptVar2->anim_max <= iVar3))) {
        ptVar2 = ptVar2->anim_next;
        if (ptVar2 == (texture_s *)0x0) {
          Sys_Error("R_TextureAnimation: broken cycle");
        }
        iVar4 = iVar4 + 1;
        if (100 < iVar4) {
          Sys_Error("R_TextureAnimation: infinite cycle");
        }
      }
    }
  }
  return ptVar2;
}


// R_TimeRefresh_f  @ 00209f80
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


// R_TracerEffect  @ 001a4250
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


// R_TracerParticles  @ 001eaa20
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
    ppVar4->vel[1] = vel[1];
    ppVar4->org[2] = org[2];
    ppVar4->vel[2] = vel[2];
  }
  return ppVar4;
}


// R_TranslatePlayerSkin  @ 0020afc0
void R_TranslatePlayerSkin(int playernum)

{
  return;
}


// R_TriangleSpriteTexture  @ 002102b0
int R_TriangleSpriteTexture(model_t *pSpriteModel,int frame)

{
  mspriteframe_t *pmVar1;
  
                    /* Unresolved local var: mspriteframe_t * pSpriteFrame@[???] */
  VGUI2_ResetCurrentTexture();
  pmVar1 = R_GetSpriteFrame((pSpriteModel->cache).data,frame);
  if (pmVar1 != (mspriteframe_t *)0x0) {
    GL_Bind(pmVar1->gl_texturenum);
  }
  return (uint)(pmVar1 != (mspriteframe_t *)0x0);
}


// R_UpdateLatchedVars  @ 001466c0
void R_UpdateLatchedVars(cl_entity_t *ent)

{
  byte bVar1;
  int iVar2;
  float fVar3;
  byte bVar4;
  byte bVar5;
  
                    /* Unresolved local var: int i@[???] */
  (ent->latched).prevorigin[0] = (ent->prevstate).origin[0];
  (ent->latched).prevorigin[1] = (ent->prevstate).origin[1];
  (ent->latched).prevorigin[2] = (ent->prevstate).origin[2];
  (ent->latched).prevangles[0] = (ent->prevstate).angles[0];
  (ent->latched).prevangles[1] = (ent->prevstate).angles[1];
  (ent->latched).prevangles[2] = (ent->prevstate).angles[2];
  (ent->latched).prevanimtime = (ent->prevstate).animtime;
  iVar2 = (ent->prevstate).sequence;
  if ((ent->curstate).sequence == iVar2) {
    bVar5 = (ent->prevstate).blending[0];
    bVar4 = (ent->prevstate).blending[1];
  }
  else {
    fVar3 = (ent->curstate).animtime;
    (ent->latched).prevsequence = iVar2;
    bVar4 = (ent->prevstate).blending[1];
    (ent->latched).sequencetime = fVar3;
    bVar5 = (ent->prevstate).blending[0];
    (ent->latched).prevseqblending[1] = bVar4;
    (ent->latched).prevseqblending[0] = bVar5;
  }
  bVar1 = (ent->prevstate).controller[0];
  (ent->latched).prevblending[0] = bVar5;
  (ent->latched).prevblending[1] = bVar4;
  (ent->latched).prevcontroller[0] = bVar1;
  (ent->latched).prevcontroller[1] = (ent->prevstate).controller[1];
  (ent->latched).prevcontroller[2] = (ent->prevstate).controller[2];
  (ent->latched).prevcontroller[3] = (ent->prevstate).controller[3];
  return;
}


// R_UploadEmptyTex  @ 0020a130
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void R_UploadEmptyTex(void)

{
  texture_t *ptVar1;
  int iVar2;
  uchar local_30c [765];
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  
                    /* Unresolved local var: uchar[768] pPal@[???] */
  Q_memset(local_30c,0,0x300);
  ptVar1 = r_notexture_mip;
  local_f = 0xff;
  local_e = 0;
  local_d = 0xff;
  iVar2 = GL_LoadTexture("**empty**",GLT_SYSTEM,r_notexture_mip->width,r_notexture_mip->height,
                         (uchar *)(r_notexture_mip + 1),1,0,local_30c);
  ptVar1->gl_texturenum = iVar2;
  return;
}


// R_UserTracerParticle  @ 001eaaa0
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
  if (0xc < (uint)colorIndex) {
    Con_Printf("UserTracer with color > %d\n");
    return;
  }
  if (free_particles != (particle_t *)0x0) {
    gpActiveTracers = free_particles;
    pppVar1 = &free_particles->next;
    free_particles = free_particles->next;
    *pppVar1 = ppVar3;
    ppVar4->die = life + (float)cl.time;
    ppVar4->color = (short)colorIndex;
    ppVar4->packedColor = 0xff;
    ppVar4->type = pt_static;
    ppVar4->ramp = length;
    ppVar4->org[0] = *org;
    ppVar4->vel[0] = *vel;
    ppVar4->org[1] = org[1];
    ppVar4->vel[1] = vel[1];
    ppVar4->org[2] = org[2];
    vVar2 = vel[2];
    ppVar4->deathfunc = deathfunc;
    ppVar4->vel[2] = vVar2;
    ppVar4->context = context;
  }
  return;
}


