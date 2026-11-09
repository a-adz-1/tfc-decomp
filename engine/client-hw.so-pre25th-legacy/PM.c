// PM_AddToTouched  @ 00130050
qboolean PM_AddToTouched(pmtrace_t tr,vec_t *impactvelocity)

{
  int iVar1;
  char *pcVar2;
  playermove_t_conflict *ppVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  vec_t vVar8;
  int *piVar9;
  vec_t vVar10;
  vec_t local_20;
  
                    /* Unresolved local var: int i@[???] */
  iVar4 = tr.ent;
  iVar7 = pmove->numtouch;
  if (iVar7 < 1) {
    if (iVar7 != 0) {
      return false;
    }
    local_20 = impactvelocity[2];
    vVar8 = *impactvelocity;
    vVar10 = impactvelocity[1];
  }
  else {
    iVar5 = 0;
    piVar9 = &pmove->touchindex[1].ent;
    if (pmove->touchindex[0].ent == tr.ent) {
      return false;
    }
    while (iVar5 = iVar5 + 1, iVar5 != iVar7) {
      iVar1 = *piVar9;
      piVar9 = piVar9 + 0x11;
      if (iVar1 == tr.ent) {
        return false;
      }
    }
    local_20 = impactvelocity[2];
    vVar8 = *impactvelocity;
    vVar10 = impactvelocity[1];
    if (599 < iVar7) {
      (*pmove->Con_DPrintf)("Too many entities were touched!\n");
      iVar7 = pmove->numtouch;
    }
  }
  ppVar3 = pmove;
  uVar6 = 0;
  do {
    *(undefined4 *)((int)ppVar3->touchindex[iVar7].endpos + (uVar6 - 0x14)) =
         *(undefined4 *)((int)tr.endpos + (uVar6 - 0x14));
    uVar6 = uVar6 + 4;
  } while (uVar6 < 0x44);
  iVar5 = iVar7 * 0x44;
  pcVar2 = "SV_SetCallback";
  *(int *)((int)ppVar3->origin + (int)(pcVar2 + iVar5 + 5)) = iVar4;
  *(vec_t *)((int)ppVar3->origin + (int)(pcVar2 + iVar5 + 9)) = vVar8;
  *(vec_t *)((int)ppVar3->angles + (int)(pcVar2 + iVar5 + 1)) = vVar10;
  *(vec_t *)((int)ppVar3->angles + (int)(pcVar2 + iVar5 + 5)) = local_20;
  ppVar3->numtouch = iVar7 + 1;
  return true;
}


// PM_CL_PlaySound  @ 00192550
void PM_CL_PlaySound(int channel,char *sample,float volume,float attenuation,int fFlags,int pitch)

{
  float fVar1;
  sfx_t *sfxin;
  int iVar2;
  sfx_t local_64;
  
                    /* Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: sfx_t sfxsentence@[???]
                       Unresolved local var: int i@[???] */
  if (pmove->runfuncs != false) {
    fVar1 = (float)cl.time;
    g_laststepgap = fVar1 - PM_CL_PlaySound::lexical_block_0::last;
    PM_CL_PlaySound::lexical_block_0::last = fVar1;
    if ((fFlags & 0x10U) == 0) {
      sfxin = CL_LookupSound(sample);
    }
    else {
      iVar2 = Q_atoi(sample + 1);
      sfxin = &local_64;
      snprintf(sfxin->name,0x40,"!%s",rgpszrawsentence[iVar2]);
    }
    if (cls.demorecording != false) {
      CL_DemoQueueSound(channel,sample,volume,attenuation,fFlags,pitch);
    }
    if (channel == 6) {
      S_StartStaticSound(pmove->player_index + 1,6,sfxin,pmove->origin,volume,attenuation,fFlags,
                         pitch);
    }
    else {
      S_StartDynamicSound(pmove->player_index + 1,channel,sfxin,pmove->origin,volume,attenuation,
                          fFlags,pitch);
    }
  }
  return;
}


// PM_CL_PlaybackEventFull  @ 001921d0
void PM_CL_PlaybackEventFull
               (int flags,int clientindex,ushort eventindex,float delay,float *origin,float *angles,
               float fparam1,float fparam2,int iparam1,int iparam2,int bparam1,int bparam2)

{
  event_args_t local_64;
  
                    /* Unresolved local var: event_args_t eargs@[???] */
  if ((flags & 0x20U) == 0) {
    Q_memset(&local_64,0,0x48);
    local_64.origin[0] = *origin;
    local_64.origin[1] = origin[1];
    local_64.origin[2] = origin[2];
    local_64.angles[0] = *angles;
    local_64.angles[1] = angles[1];
    local_64.angles[2] = angles[2];
    local_64.fparam1 = fparam1;
    local_64.fparam2 = fparam2;
    local_64.iparam1 = iparam1;
    local_64.iparam2 = iparam2;
    local_64.bparam1 = bparam1;
    local_64.bparam2 = bparam2;
    CL_ClientQueueEvent(flags,(uint)eventindex,clientindex,delay,&local_64);
  }
  return;
}


// PM_CL_TraceTexture  @ 001922f0
char * PM_CL_TraceTexture(int ground,float *vstart,float *vend)

{
  float fVar1;
  float fVar2;
  float fVar3;
  playermove_t_conflict *ppVar4;
  model_s *pModel;
  msurface_t *pmVar5;
  texture_t *ptVar6;
  int iVar7;
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
  
                    /* Unresolved local var: physent_t * pe@[???]
                       Unresolved local var: msurface_t * psurf@[???]
                       Unresolved local var: int firstnode@[???]
                       Unresolved local var: vec3_t start@[???]
                       Unresolved local var: vec3_t end@[???] */
  ppVar4 = pmove;
  ptVar6 = (texture_t *)0x0;
  if (((-1 < ground) && (ground < pmove->numphysent)) &&
     (pModel = pmove->physents[ground].model, pModel != (model_s *)0x0)) {
    if (ground < 1) {
      local_58 = *vstart;
      local_54 = vstart[1];
      local_50 = vstart[2];
      iVar7 = 0;
      local_4c = *vend;
      local_48 = vend[1];
      local_44 = vend[2];
    }
    else {
                    /* Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: hull_t * phull@[???] */
      local_4c = pModel->hulls[0].clip_mins[0] + pmove->physents[ground].origin[0];
      local_48 = pModel->hulls[0].clip_mins[1] + pmove->physents[ground].origin[1];
      local_44 = pModel->hulls[0].clip_mins[2] + pmove->physents[ground].origin[2];
      local_58 = *vstart - local_4c;
      local_54 = vstart[1] - local_48;
      local_50 = vstart[2] - local_44;
      iVar7 = pModel->hulls[0].firstclipnode;
      local_4c = *vend - local_4c;
      local_48 = vend[1] - local_48;
      local_44 = vend[2] - local_44;
      if (((pmove->physents[ground].angles[0] != 0.0) || (pmove->physents[ground].angles[1] != 0.0))
         || (pmove->physents[ground].angles[2] != 0.0)) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t temp@[???] */
        AngleVectors(pmove->physents[ground].angles,&local_40,&local_34,&local_28);
        pModel = ppVar4->physents[ground].model;
        fVar3 = local_50 * local_38;
        fVar1 = local_34 * local_58;
        fVar2 = local_2c * local_50;
        local_50 = local_50 * local_20 + local_54 * local_24 + local_58 * local_28;
        local_38 = local_38 * local_44;
        local_34 = local_34 * local_4c;
        local_2c = local_2c * local_44;
        local_44 = local_44 * local_20 + local_48 * local_24 + local_4c * local_28;
        local_58 = fVar3 + local_54 * local_3c + local_58 * local_40;
        local_54 = -(fVar2 + local_30 * local_54 + fVar1);
        local_4c = local_38 + local_3c * local_48 + local_40 * local_4c;
        local_48 = -(local_2c + local_30 * local_48 + local_34);
        if (pModel == (model_s *)0x0) {
          return (char *)0x0;
        }
      }
    }
    ptVar6 = (texture_t *)0x0;
    if (((pModel->type == mod_brush) && (pModel->nodes != (mnode_t *)0x0)) &&
       (pmVar5 = SurfaceAtPoint(pModel,pModel->nodes + iVar7,&local_58,&local_4c),
       pmVar5 != (msurface_t *)0x0)) {
      ptVar6 = pmVar5->texinfo->texture;
    }
  }
  return ptVar6->name;
}


// PM_DrawBBox  @ 001f27b0
void PM_DrawBBox(vec_t *mins,vec_t *maxs,vec_t *origin,int pcolor,float life)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  int local_a4;
  float local_9c [4];
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
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: vec_t[8][3] p@[???]
                       Unresolved local var: float gap@[???] */
                    /* Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float linestep@[???] */
  local_9c[1] = maxs[1] + 0.0 + origin[1];
  local_9c[2] = maxs[2] + 0.0 + origin[2];
  local_9c[0] = *maxs + 0.0 + *origin;
  local_9c[3] = *mins + *origin;
  local_8c = local_9c[1];
  local_88 = local_9c[2];
  local_80 = origin[1] + mins[1];
  local_84 = local_9c[0];
  local_7c = local_9c[2];
  local_78 = local_9c[3];
  local_74 = local_80;
  local_70 = local_9c[2];
  local_64 = mins[2] + origin[2];
  local_6c = local_9c[0];
  local_68 = local_9c[1];
  local_60 = local_9c[3];
  local_5c = local_9c[1];
  local_58 = local_64;
  local_54 = local_9c[0];
  local_50 = local_80;
  local_4c = local_64;
  local_48 = local_9c[3];
  local_44 = local_80;
  local_40 = local_64;
  local_a4 = 0;
  do {
    iVar8 = *(int *)((int)PM_boxpnt[0] + local_a4 + 0xc);
    iVar9 = *(int *)((int)PM_boxpnt[0] + local_a4 + 8);
    iVar10 = *(int *)((int)PM_boxpnt[0] + local_a4);
    iVar11 = *(int *)((int)PM_boxpnt[0] + local_a4 + 4);
                    /* Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float linestep@[???] */
    fVar1 = local_9c[iVar10 * 3];
    fVar2 = local_9c[iVar11 * 3];
    local_28 = fVar1 - fVar2;
    fVar3 = local_9c[iVar10 * 3 + 1];
    fVar15 = local_9c[iVar11 * 3 + 1];
    local_24 = fVar3 - fVar15;
    fVar4 = local_9c[iVar10 * 3 + 2];
    fVar5 = local_9c[iVar11 * 3 + 2];
    local_20 = fVar4 - fVar5;
    fVar13 = VectorNormalize(&local_28);
    fVar6 = 0.0;
    if (0.0 <= fVar13) {
      do {
        local_34 = local_28 * fVar6 + fVar2;
        local_30 = local_24 * fVar6 + fVar15;
        local_2c = local_20 * fVar6 + fVar5;
        CL_Particle(&local_34,pcolor,life,0,0);
        fVar6 = fVar6 + 2.0;
      } while (fVar6 <= fVar13);
    }
                    /* Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float linestep@[???] */
    fVar6 = local_9c[iVar8 * 3];
    local_34 = fVar6 - fVar1;
    fVar13 = local_9c[iVar8 * 3 + 1];
    local_30 = fVar13 - fVar3;
    fVar7 = local_9c[iVar8 * 3 + 2];
    local_2c = fVar7 - fVar4;
    fVar14 = VectorNormalize(&local_34);
    fVar12 = 0.0;
    if (0.0 <= fVar14) {
      do {
        local_28 = local_34 * fVar12 + fVar1;
        local_24 = local_30 * fVar12 + fVar3;
        local_20 = local_2c * fVar12 + fVar4;
        CL_Particle(&local_28,pcolor,life,0,0);
        fVar12 = fVar12 + 2.0;
      } while (fVar12 <= fVar14);
    }
                    /* Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float linestep@[???] */
    fVar1 = local_9c[iVar9 * 3];
    local_28 = fVar1 - fVar6;
    fVar3 = local_9c[iVar9 * 3 + 1];
    local_24 = fVar3 - fVar13;
    fVar4 = local_9c[iVar9 * 3 + 2];
    local_20 = fVar4 - fVar7;
    fVar14 = VectorNormalize(&local_28);
    fVar12 = 0.0;
    if (0.0 <= fVar14) {
      do {
        local_34 = local_28 * fVar12 + fVar6;
        local_30 = local_24 * fVar12 + fVar13;
        local_2c = local_20 * fVar12 + fVar7;
        CL_Particle(&local_34,pcolor,life,0,0);
        fVar12 = fVar12 + 2.0;
      } while (fVar12 <= fVar14);
    }
    local_34 = fVar2 - fVar1;
    local_30 = fVar15 - fVar3;
    local_2c = fVar5 - fVar4;
    fVar15 = VectorNormalize(&local_34);
    fVar2 = 0.0;
    if (0.0 <= fVar15) {
      do {
        local_28 = local_34 * fVar2 + fVar1;
        local_24 = local_30 * fVar2 + fVar3;
        local_20 = local_2c * fVar2 + fVar4;
        CL_Particle(&local_28,pcolor,life,0,0);
        fVar2 = fVar2 + 2.0;
      } while (fVar2 <= fVar15);
    }
    local_a4 = local_a4 + 0x10;
  } while (local_a4 != 0x60);
  return;
}


// PM_DrawRectangle  @ 001f2470
void PM_DrawRectangle(vec_t *tl,vec_t *bl,vec_t *tr,vec_t *br,int pcolor,float life)

{
  float fVar1;
  float fVar2;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float linestep@[???] */
  local_28 = *bl - *tl;
  local_24 = bl[1] - tl[1];
  local_20 = bl[2] - tl[2];
  fVar2 = VectorNormalize(&local_28);
  fVar1 = 0.0;
  if (0.0 <= fVar2) {
    do {
      local_34 = local_28 * fVar1 + *tl;
      local_30 = local_24 * fVar1 + tl[1];
      local_2c = local_20 * fVar1 + tl[2];
      CL_Particle(&local_34,pcolor,life,0,0);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
                    /* Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float linestep@[???] */
  local_34 = *br - *bl;
  local_30 = br[1] - bl[1];
  local_2c = br[2] - bl[2];
  fVar2 = VectorNormalize(&local_34);
  fVar1 = 0.0;
  if (0.0 <= fVar2) {
    do {
      local_28 = local_34 * fVar1 + *bl;
      local_24 = local_30 * fVar1 + bl[1];
      local_20 = local_2c * fVar1 + bl[2];
      CL_Particle(&local_28,pcolor,life,0,0);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
                    /* Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float linestep@[???] */
  local_28 = *tr - *br;
  local_24 = tr[1] - br[1];
  local_20 = tr[2] - br[2];
  fVar2 = VectorNormalize(&local_28);
  fVar1 = 0.0;
  if (0.0 <= fVar2) {
    do {
      local_34 = local_28 * fVar1 + *br;
      local_30 = local_24 * fVar1 + br[1];
      local_2c = local_20 * fVar1 + br[2];
      CL_Particle(&local_34,pcolor,life,0,0);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
                    /* Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float linestep@[???] */
  local_34 = *tl - *tr;
  local_30 = tl[1] - tr[1];
  local_2c = tl[2] - tr[2];
  fVar2 = VectorNormalize(&local_34);
  fVar1 = 0.0;
  if (0.0 <= fVar2) {
    do {
      local_28 = local_34 * fVar1 + *tr;
      local_24 = local_30 * fVar1 + tr[1];
      local_20 = local_2c * fVar1 + tr[2];
      CL_Particle(&local_28,pcolor,life,0,0);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
  return;
}


// PM_GetModelBounds  @ 00130380
void PM_GetModelBounds(model_s *mod,vec_t *mins,vec_t *maxs)

{
  *mins = mod->mins[0];
  mins[1] = mod->mins[1];
  mins[2] = mod->mins[2];
  *maxs = mod->maxs[0];
  maxs[1] = mod->maxs[1];
  maxs[2] = mod->maxs[2];
  return;
}


// PM_GetModelType  @ 001303c0
int PM_GetModelType(model_s *mod)

{
  return mod->type;
}


// PM_HullForBox  @ 00130520
hull_t * PM_HullForBox(vec_t *mins,vec_t *maxs)

{
  box_planes[0].dist = *maxs;
  box_planes[1].dist = *mins;
  box_planes[2].dist = maxs[1];
  box_planes[3].dist = mins[1];
  box_planes[4].dist = maxs[2];
  box_planes[5].dist = mins[2];
  return &box_hull;
}


// PM_HullForBsp  @ 001318c0
hull_t * PM_HullForBsp(physent_t *pe,vec_t *offset)

{
  int iVar1;
  model_s *pmVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  playermove_t_conflict *ppVar6;
  hull_t *phVar7;
  
                    /* Unresolved local var: hull_t * hull@[???] */
  iVar1 = pmove->usehull;
  pmVar2 = pe->model;
  if (iVar1 == 2) {
    phVar7 = pmVar2->hulls;
  }
  else if (iVar1 == 3) {
    phVar7 = pmVar2->hulls + 2;
  }
  else if (iVar1 == 1) {
    phVar7 = pmVar2->hulls + 3;
  }
  else {
    phVar7 = pmVar2->hulls + 1;
  }
  fVar3 = phVar7->clip_mins[0] - player_mins[iVar1][0];
  *offset = fVar3;
  ppVar6 = pmove;
  fVar4 = phVar7->clip_mins[1] - player_mins[pmove->usehull][1];
  offset[1] = fVar4;
  fVar5 = phVar7->clip_mins[2] - player_mins[ppVar6->usehull][2];
  offset[2] = fVar5;
  *offset = fVar3 + pe->origin[0];
  offset[1] = fVar4 + pe->origin[1];
  offset[2] = fVar5 + pe->origin[2];
  return phVar7;
}


// PM_HullForStudioModel  @ 00130e70
hull_t * PM_HullForStudioModel
                   (model_t *pModel,vec_t *offset,float frame,int sequence,vec_t *angles,
                   vec_t *origin,byte *pcontroller,byte *pblending,int *pNumHulls)

{
  int iVar1;
  hull_t *phVar2;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: vec3_t size@[???] */
  iVar1 = pmove->usehull;
  local_18 = player_maxs[iVar1][0] - player_mins[iVar1][0];
  local_14 = player_maxs[iVar1][1] - player_mins[iVar1][1];
  local_10 = player_maxs[iVar1][2] - player_mins[iVar1][2];
  VectorScale(&local_18,0.5,&local_18);
  *offset = 0.0;
  offset[1] = 0.0;
  offset[2] = 0.0;
  phVar2 = R_StudioHull(pModel,frame,sequence,angles,origin,&local_18,pcontroller,pblending,
                        pNumHulls,(edict_t *)0x0,0);
  return phVar2;
}


// PM_HullPointContents  @ 00130570
int PM_HullPointContents(hull_t *hull,int num,vec_t *p)

{
  dclipnode_t *pdVar1;
  mplane_t *pmVar2;
  short sVar3;
  int iVar4;
  
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???] */
  iVar4 = hull->firstclipnode;
  if (iVar4 < hull->lastclipnode) {
    if (-1 < num) {
      do {
        if ((num < iVar4) || (hull->lastclipnode < num)) {
          Sys_Error("PM_HullPointContents: bad node number");
        }
        pdVar1 = hull->clipnodes + num;
        pmVar2 = hull->planes + pdVar1->planenum;
        if (pmVar2->type < 3) {
          if (0.0 <= p[pmVar2->type] - pmVar2->dist) goto LAB_00130601;
LAB_001305a9:
          sVar3 = pdVar1->children[1];
        }
        else {
          if ((pmVar2->normal[2] * p[2] + pmVar2->normal[1] * p[1] + pmVar2->normal[0] * *p) -
              pmVar2->dist < 0.0) goto LAB_001305a9;
LAB_00130601:
          sVar3 = pdVar1->children[0];
        }
        num = (int)sVar3;
        if (num < 0) {
          return num;
        }
        iVar4 = hull->firstclipnode;
      } while( true );
    }
  }
  else {
    num = -1;
  }
  return num;
}


// PM_Init  @ 001301c0
void PM_Init(playermove_t_conflict *ppm)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
                    /* Unresolved local var: int i@[???] */
  PM_InitBoxHull();
  uVar2 = player_mins[2]._0_8_;
  uVar1 = player_mins[1]._4_8_;
  ppm->movevars = &movevars;
  *(undefined8 *)(ppm->player_mins[1] + 1) = uVar1;
  ppm->PM_Info_ValueForKey = Info_ValueForKey;
  *(undefined8 *)ppm->player_mins[2] = uVar2;
  ppm->PM_Particle = CL_Particle;
  ppm->PM_TestPlayerPosition = PM_TestPlayerPosition;
  ppm->Con_NPrintf = Con_NPrintf;
  ppm->Con_DPrintf = Con_DPrintf;
  ppm->PM_StuckTouch = PM_StuckTouch;
  ppm->PM_PointContents = PM_PointContents;
  uVar4 = player_mins[3]._4_8_;
  uVar3 = player_mins._32_8_;
  ppm->PM_TruePointContents = PM_TruePointContents;
  uVar2 = player_mins._8_8_;
  uVar1 = player_mins[0]._0_8_;
  *(undefined8 *)(ppm->player_mins[2] + 2) = uVar3;
  *(undefined8 *)(ppm->player_mins[3] + 1) = uVar4;
  ppm->PM_HullPointContents = PM_HullPointContents;
  *(undefined8 *)ppm->player_mins[0] = uVar1;
  *(undefined8 *)(ppm->player_mins[0] + 2) = uVar2;
  uVar2 = player_maxs[2]._0_8_;
  uVar1 = player_maxs[1]._4_8_;
  ppm->PM_PlayerTrace = PM_PlayerTrace;
  uVar4 = player_maxs[3]._4_8_;
  uVar3 = player_maxs._32_8_;
  *(undefined8 *)(ppm->player_maxs[1] + 1) = uVar1;
  *(undefined8 *)ppm->player_maxs[2] = uVar2;
  ppm->Con_Printf = Con_Printf;
  uVar2 = player_maxs._8_8_;
  uVar1 = player_maxs[0]._0_8_;
  *(undefined8 *)(ppm->player_maxs[2] + 2) = uVar3;
  *(undefined8 *)(ppm->player_maxs[3] + 1) = uVar4;
  ppm->Sys_FloatTime = Sys_FloatTime;
  ppm->PM_TraceLine = PM_TraceLine;
  *(undefined8 *)ppm->player_maxs[0] = uVar1;
  ppm->PM_TraceModel = PM_TraceModel;
  *(undefined8 *)(ppm->player_maxs[0] + 2) = uVar2;
  ppm->RandomLong = RandomLong;
  ppm->RandomFloat = RandomFloat;
  ppm->PM_GetModelType = PM_GetModelType;
  ppm->PM_HullForBsp = PM_HullForBsp;
  ppm->PM_GetModelBounds = PM_GetModelBounds;
  ppm->COM_FileSize = COM_FileSize;
  ppm->COM_LoadFile = COM_LoadFile;
  ppm->PM_PlayerTraceEx = PM_PlayerTraceEx;
  ppm->PM_TestPlayerPositionEx = PM_TestPlayerPositionEx;
  ppm->COM_FreeFile = COM_FreeFile;
  ppm->memfgets = memfgets;
  ppm->PM_TraceLineEx = PM_TraceLineEx;
  return;
}


// PM_InitBoxHull  @ 001303d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_InitBoxHull(void)

{
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???] */
  box_hull.planes = box_planes;
  box_hull.firstclipnode = 0;
  box_clipnodes[1].planenum = 1;
  box_clipnodes[1].children[1] = -1;
  box_clipnodes[1].children[0] = 2;
  box_hull.clipnodes = box_clipnodes;
  box_clipnodes[2].planenum = 2;
  box_clipnodes[2].children[0] = -1;
  box_hull.lastclipnode = 5;
  box_clipnodes[2].children[1] = 3;
  box_clipnodes[3].planenum = 3;
  box_clipnodes[0].planenum = 0;
  box_clipnodes[3].children[1] = -1;
  box_clipnodes[3].children[0] = 4;
  box_clipnodes[0].children[0] = -1;
  box_clipnodes[4].planenum = 4;
  box_clipnodes[4].children[0] = -1;
  box_clipnodes[0].children[1] = 1;
  box_clipnodes[4].children[1] = 5;
  box_clipnodes[5].planenum = 5;
  box_planes[0].type = '\0';
  box_planes[0].normal[0] = 1.0;
  box_planes[1].type = '\0';
  box_planes[1].normal[0] = 1.0;
  box_planes[2].type = '\x01';
  box_planes[2].normal[1] = 1.0;
  box_planes[3].type = '\x01';
  box_planes[3].normal[1] = 1.0;
  box_planes[4].type = '\x02';
  box_planes[4].normal[2] = 1.0;
  box_clipnodes[5].children[1] = -1;
  box_clipnodes[5].children[0] = -2;
  box_planes[5].type = '\x02';
  box_planes[5].normal[2] = 1.0;
  return;
}


// PM_LinkContents  @ 00130c10
int PM_LinkContents(vec_t *p,int *pIndex)

{
  model_s *pmVar1;
  int iVar2;
  playermove_t_conflict *ppVar3;
  int iVar4;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: physent_t * pe@[???]
                       Unresolved local var: vec3_t test@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: int num@[???]
                       Unresolved local var: int cont@[???] */
  iVar2 = pmove->numphysent;
  if (iVar2 < 2) {
    return -1;
  }
  iVar4 = 1;
  ppVar3 = pmove;
  do {
    if ((ppVar3->physents[iVar4].solid == 0) &&
       (pmVar1 = ppVar3->physents[iVar4].model, pmVar1 != (model_s *)0x0)) {
      local_28 = *p - ppVar3->physents[iVar4].origin[0];
      local_24 = p[1] - ppVar3->physents[iVar4].origin[1];
      local_20 = p[2] - ppVar3->physents[iVar4].origin[2];
      iVar2 = PM_HullPointContents(pmVar1->hulls,pmVar1->hulls[0].firstclipnode,&local_28);
      if (iVar2 != -1) {
        if (pIndex != (int *)0x0) {
          *pIndex = ppVar3->physents[iVar4].info;
        }
        return ppVar3->physents[iVar4].skin;
      }
      iVar2 = pmove->numphysent;
      ppVar3 = pmove;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < iVar2);
  return -1;
}


// PM_ParticleLine  @ 001f2390
void PM_ParticleLine(vec_t *start,vec_t *end,int pcolor,float life,float vert)

{
  float fVar1;
  float fVar2;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float linestep@[???]
                       Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???] */
  local_28 = *end - *start;
  local_24 = end[1] - start[1];
  local_20 = end[2] - start[2];
  fVar2 = VectorNormalize(&local_28);
  fVar1 = 0.0;
  if (0.0 <= fVar2) {
    do {
      local_34 = local_28 * fVar1 + *start;
      local_30 = local_24 * fVar1 + start[1];
      local_2c = local_20 * fVar1 + start[2];
      CL_Particle(&local_34,pcolor,life,0,(int)vert);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
  return;
}


// PM_PlayerTrace  @ 00132940
pmtrace_t *
PM_PlayerTrace(pmtrace_t *__return_storage_ptr__,vec_t *start,vec_t *end,int traceFlags,
              int ignore_pe)

{
                    /* Unresolved local var: pmtrace_t tr@[???] */
  _PM_PlayerTrace(__return_storage_ptr__,start,end,traceFlags,pmove->numphysent,pmove->physents,
                  ignore_pe,(_func_int_physent_t_ptr *)0x0);
  return __return_storage_ptr__;
}


// PM_PlayerTraceEx  @ 001329a0
pmtrace_t *
PM_PlayerTraceEx(pmtrace_t *__return_storage_ptr__,vec_t *start,vec_t *end,int traceFlags,
                _func_int_physent_t_ptr *pfnIgnore)

{
                    /* Unresolved local var: pmtrace_t tr@[???] */
  _PM_PlayerTrace(__return_storage_ptr__,start,end,traceFlags,pmove->numphysent,pmove->physents,-1,
                  pfnIgnore);
  return __return_storage_ptr__;
}


// PM_PointContents  @ 00130cf0
int PM_PointContents(vec_t *p,int *truecontents)

{
  model_s *pmVar1;
  int iVar2;
  int iVar3;
  hull_t *hull;
  
                    /* Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: int num@[???]
                       Unresolved local var: int cont@[???]
                       Unresolved local var: int entityContents@[???] */
  (*g_engdstAddrs.PM_PointContents)(&p,&truecontents);
  pmVar1 = pmove->physents[0].model;
  hull = pmVar1->hulls;
  if (hull != (hull_t *)0x0) {
    iVar2 = PM_HullPointContents(hull,pmVar1->hulls[0].firstclipnode,p);
    if (truecontents != (int *)0x0) {
      *truecontents = iVar2;
    }
    if (iVar2 + 0xeU < 6) {
      iVar2 = -3;
    }
    else if (iVar2 == -2) {
      return -2;
    }
    iVar3 = PM_LinkContents(p,(int *)0x0);
    if (iVar3 == -1) {
      iVar3 = iVar2;
    }
    return iVar3;
  }
  if (truecontents == (int *)0x0) {
    return -2;
  }
  *truecontents = -1;
  return -2;
}


// PM_RecursiveHullCheck  @ 00130620
qboolean __regparm3
PM_RecursiveHullCheck(hull_t *hull,int num,float p1f,float p2f,vec_t *p1,vec_t *p2,pmtrace_t *trace)

{
  mplane_t *pmVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  vec_t *p1_00;
  uint uVar6;
  qboolean qVar7;
  dclipnode_t *pdVar8;
  int iVar9;
  vec_t *local_34;
  float local_2c;
  float local_28;
  float local_24;
  
                    /* Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t mid@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: int otherside@[???]
                       Unresolved local var: float midf@[???]
                       Unresolved local var: qboolean retval@[DW_OP_reg0(EAX)] */
  pdVar8 = hull->clipnodes + num;
  pmVar1 = hull->planes + pdVar8->planenum;
  bVar2 = pmVar1->type;
  if (bVar2 < 3) {
    fVar3 = *(float *)((int)p1f + (uint)bVar2 * 4) - pmVar1->dist;
    fVar4 = p2[bVar2] - pmVar1->dist;
  }
  else {
    fVar3 = (*(float *)((int)p1f + 8) * pmVar1->normal[2] +
            *(float *)((int)p1f + 4) * pmVar1->normal[1] + *(float *)p1f * pmVar1->normal[0]) -
            pmVar1->dist;
    fVar4 = (pmVar1->normal[2] * p2[2] + pmVar1->normal[1] * p2[1] + pmVar1->normal[0] * *p2) -
            pmVar1->dist;
  }
  if ((0.0 <= fVar3) && (0.0 <= fVar4)) {
    iVar9 = (int)pdVar8->children[0];
                    /* Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: vec3_t mid@[???]
                       Unresolved local var: qboolean retval@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: int otherside@[???]
                       Unresolved local var: float midf@[???] */
    if (-1 < iVar9) {
      if (hull->lastclipnode <= hull->firstclipnode) {
        trace->allsolid = false;
        trace->inopen = true;
        return true;
      }
LAB_00130a18:
                    /* Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: vec3_t mid@[???]
                       Unresolved local var: qboolean retval@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: int otherside@[???]
                       Unresolved local var: float midf@[???] */
      qVar7 = PM_RecursiveHullCheck(hull,iVar9,p1f,p2f,p1,p2,trace);
      return qVar7;
    }
    if (iVar9 == -2) {
      trace->startsolid = true;
      return true;
    }
    trace->allsolid = false;
    if (iVar9 != -1) {
      trace->inwater = true;
      return true;
    }
    goto LAB_00130a7f;
  }
  if (0.0 <= fVar3) {
    fVar5 = fVar3 - 0.03125;
LAB_0013069e:
    fVar5 = fVar5 / (fVar3 - fVar4);
    fVar4 = 0.0;
    if ((0.0 <= fVar5) && (fVar4 = fVar5, 1.0 < fVar5)) {
      fVar4 = 1.0;
    }
    p1_00 = (vec_t *)(((float)p1 - p2f) * fVar4 + p2f);
    local_2c = (*p2 - *(float *)p1f) * fVar4 + *(float *)p1f;
    local_28 = (p2[1] - *(float *)((int)p1f + 4)) * fVar4 + *(float *)((int)p1f + 4);
    local_24 = (p2[2] - *(float *)((int)p1f + 8)) * fVar4 + *(float *)((int)p1f + 8);
    uVar6 = (uint)(fVar3 < 0.0);
    iVar9 = (int)pdVar8->children[uVar6];
                    /* Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: vec3_t mid@[???]
                       Unresolved local var: qboolean retval@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: int otherside@[???]
                       Unresolved local var: float midf@[???] */
    if (iVar9 < 0) {
      if (iVar9 == -2) {
        trace->startsolid = true;
      }
      else {
        trace->allsolid = false;
        if (iVar9 == -1) {
          trace->inopen = true;
        }
        else {
          trace->inwater = true;
        }
      }
    }
    else if (hull->firstclipnode < hull->lastclipnode) {
      qVar7 = PM_RecursiveHullCheck(hull,iVar9,p1f,p2f,p1_00,&local_2c,trace);
      if (qVar7 == false) {
        return false;
      }
    }
    else {
      trace->allsolid = false;
      trace->inopen = true;
    }
    local_34 = &local_2c;
    iVar9 = PM_HullPointContents(hull,(int)pdVar8->children[uVar6 ^ 1],local_34);
    if (iVar9 == -2) {
      if (trace->allsolid != false) {
        return false;
      }
      if (uVar6 == 0) {
        (trace->plane).normal[0] = pmVar1->normal[0];
        (trace->plane).normal[1] = pmVar1->normal[1];
        (trace->plane).normal[2] = pmVar1->normal[2];
        (trace->plane).dist = pmVar1->dist;
      }
      else {
        (trace->plane).normal[0] = vec3_origin[0] - pmVar1->normal[0];
        (trace->plane).normal[1] = vec3_origin[1] - pmVar1->normal[1];
        (trace->plane).normal[2] = vec3_origin[2] - pmVar1->normal[2];
        (trace->plane).dist = -pmVar1->dist;
      }
      while( true ) {
        iVar9 = PM_HullPointContents(hull,hull->firstclipnode,local_34);
        if (iVar9 != -2) {
          trace->fraction = (float)p1_00;
          trace->endpos[0] = local_2c;
          trace->endpos[1] = local_28;
          trace->endpos[2] = local_24;
          return false;
        }
        fVar4 = fVar4 - 0.05;
        if (fVar4 < 0.0) break;
        p1_00 = (vec_t *)(((float)p1 - p2f) * fVar4 + p2f);
        local_2c = (*p2 - *(float *)p1f) * fVar4 + *(float *)p1f;
        local_28 = (p2[1] - *(float *)((int)p1f + 4)) * fVar4 + *(float *)((int)p1f + 4);
        local_24 = (p2[2] - *(float *)((int)p1f + 8)) * fVar4 + *(float *)((int)p1f + 8);
      }
      trace->fraction = (float)p1_00;
      trace->endpos[0] = local_2c;
      trace->endpos[1] = local_28;
      trace->endpos[2] = local_24;
      Con_DPrintf("Trace backed up past 0.0.\n");
      return false;
    }
    iVar9 = (int)pdVar8->children[uVar6 ^ 1];
                    /* Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: vec3_t mid@[???]
                       Unresolved local var: qboolean retval@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: int otherside@[???]
                       Unresolved local var: float midf@[???] */
    if (iVar9 < 0) {
LAB_00130a92:
      if (iVar9 == -2) {
        trace->startsolid = true;
        return true;
      }
      trace->allsolid = false;
      if (iVar9 != -1) {
        trace->inwater = true;
        return true;
      }
      trace->inopen = true;
      return true;
    }
    if (hull->firstclipnode < hull->lastclipnode) {
      qVar7 = PM_RecursiveHullCheck(hull,iVar9,(float)local_34,(float)p1_00,p1,p2,trace);
      return qVar7;
    }
  }
  else {
    if (0.0 <= fVar4) {
      fVar5 = fVar3 + 0.03125;
      goto LAB_0013069e;
    }
    iVar9 = (int)pdVar8->children[1];
    if (iVar9 < 0) goto LAB_00130a92;
    if (hull->firstclipnode < hull->lastclipnode) goto LAB_00130a18;
  }
  trace->allsolid = false;
LAB_00130a7f:
  trace->inopen = true;
  return true;
}


// PM_RecursiveHullCheck  @ 00132c50
qboolean PM_RecursiveHullCheck
                   (hull_t *hull,int num,float p1f,float p2f,vec_t *p1,vec_t *p2,pmtrace_t *trace)

{
  qboolean qVar1;
  
                    /* Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t mid@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: int otherside@[???]
                       Unresolved local var: float midf@[???]
                       Unresolved local var: qboolean retval@[???] */
  if (num < 0) {
    if (num == -2) {
      trace->startsolid = true;
      return true;
    }
    trace->allsolid = false;
    if (num != -1) {
      trace->inwater = true;
      return true;
    }
  }
  else {
    if (hull->firstclipnode < hull->lastclipnode) {
      qVar1 = PM_RecursiveHullCheck(hull,num,(float)p1,p1f,(vec_t *)p2f,p2,trace);
      return qVar1;
    }
    trace->allsolid = false;
  }
  trace->inopen = true;
  return true;
}


// PM_SV_PlaySound  @ 00163a20
void PM_SV_PlaySound(int channel,char *sample,float volume,float attenuation,int fFlags,int pitch)

{
  SV_StartSound(1,host_client->edict,channel,sample,(int)(volume * 255.0),attenuation,fFlags,pitch);
  return;
}


// PM_SV_PlaybackEventFull  @ 00163a00
void PM_SV_PlaybackEventFull
               (int flags,int clientindex,ushort eventindex,float delay,float *origin,float *angles,
               float fparam1,float fparam2,int iparam1,int iparam2,int bparam1,int bparam2)

{
  EV_SV_Playback(flags | 1,clientindex,eventindex,delay,origin,angles,fparam1,fparam2,iparam1,
                 iparam2,bparam1,bparam2);
  return;
}


// PM_SV_TraceTexture  @ 00163a90
char * PM_SV_TraceTexture(int ground,vec_t *vstart,vec_t *vend)

{
  int iVar1;
  char *pcVar2;
  
                    /* Unresolved local var: physent_t * pe@[???]
                       Unresolved local var: edict_t.conflict * pent@[???] */
  if ((((-1 < ground) && (ground < pmove->numphysent)) &&
      (pmove->physents[ground].model != (model_s *)0x0)) &&
     (((iVar1 = pmove->physents[ground].info, -1 < iVar1 && (iVar1 < sv.max_edicts)) &&
      (sv.edicts + iVar1 != (edict_t_conflict *)0x0)))) {
    pcVar2 = TraceTexture(sv.edicts + iVar1,vstart,vend);
    return pcVar2;
  }
  return (char *)0x0;
}


// PM_StuckTouch  @ 00130160
void PM_StuckTouch(int hitent,pmtrace_t *ptraceresult)

{
  pmtrace_t tr;
  uint uVar1;
  qboolean n;
  undefined1 auVar2 [16];
  undefined1 in_stack_ffffffa8 [64];
  
                    /* Unresolved local var: edict_t.conflict * info@[???]
                       Unresolved local var: int n@[???] */
  if (pmove->server != false) {
                    /* Unresolved local var: edict_t.conflict * info@[???]
                       Unresolved local var: int n@[???] */
    n = pmove->physents[hitent].info;
    EDICT_NUM(n);
    uVar1 = 0;
    do {
      *(undefined4 *)(&stack0xffffffa4 + uVar1) =
           *(undefined4 *)((int)ptraceresult->endpos + (uVar1 - 0x14));
      uVar1 = uVar1 + 4;
    } while (uVar1 < 0x44);
    auVar2 = in_stack_ffffffa8._28_16_;
    tr.startsolid = in_stack_ffffffa8._0_4_;
    tr.inopen = in_stack_ffffffa8._4_4_;
    tr.inwater = in_stack_ffffffa8._8_4_;
    tr.fraction = (float)in_stack_ffffffa8._12_4_;
    tr.endpos[0] = (vec_t)in_stack_ffffffa8._16_4_;
    tr.endpos[1] = (vec_t)in_stack_ffffffa8._20_4_;
    tr.endpos[2] = (vec_t)in_stack_ffffffa8._24_4_;
    tr.plane.normal[0] = (vec_t)auVar2._0_4_;
    tr.plane.normal[1] = (vec_t)auVar2._4_4_;
    tr.plane.normal[2] = (vec_t)auVar2._8_4_;
    tr.plane.dist = (float)auVar2._12_4_;
    tr.ent = in_stack_ffffffa8._44_4_;
    tr.deltavelocity[0] = (vec_t)in_stack_ffffffa8._48_4_;
    tr.deltavelocity[1] = (vec_t)in_stack_ffffffa8._52_4_;
    tr.deltavelocity[2] = (vec_t)in_stack_ffffffa8._56_4_;
    tr.hitgroup = in_stack_ffffffa8._60_4_;
    tr.allsolid = n;
    PM_AddToTouched(tr,pmove->velocity);
  }
  return;
}


// PM_TestPlayerPosition  @ 00131f00
int PM_TestPlayerPosition(vec_t *pos,pmtrace_t *ptrace)

{
  int iVar1;
  
  iVar1 = _PM_TestPlayerPosition(pos,ptrace,(_func_int_physent_t_ptr *)0x0);
  return iVar1;
}


// PM_TestPlayerPositionEx  @ 00131f30
int PM_TestPlayerPositionEx(vec_t *pos,pmtrace_t *ptrace,_func_int_physent_t_ptr *pfnIgnore)

{
  physent_t *pe;
  model_t *pModel;
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  hull_t *hull;
  _func_int_physent_t_ptr *in_stack_fffffed4;
  int iStack_104;
  undefined4 auStack_f4 [17];
  pmtrace_t pStack_b0;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  vec_t vStack_5c;
  vec_t vStack_58;
  vec_t vStack_54;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  int aiStack_2c [7];
  
  _PM_PlayerTrace(&pStack_b0,pmove->origin,pmove->origin,pmove->numphysent,(int)pmove->physents,
                  (physent_t *)0xffffffff,0,in_stack_fffffed4);
  uVar4 = 0;
  do {
    *(undefined4 *)((int)auStack_f4 + uVar4) =
         *(undefined4 *)((int)pStack_b0.endpos + (uVar4 - 0x14));
    uVar4 = uVar4 + 4;
  } while (uVar4 < 0x44);
  if (ptrace != (pmtrace_t *)0x0) {
    uVar4 = 0;
    do {
      *(undefined4 *)((int)ptrace->endpos + (uVar4 - 0x14)) =
           *(undefined4 *)((int)auStack_f4 + uVar4);
      uVar4 = uVar4 + 4;
    } while (uVar4 < 0x44);
  }
  if (0 < pmove->numphysent) {
    iStack_104 = 0;
    do {
      pe = pmove->physents + iStack_104;
      if ((pfnIgnore == (_func_int_physent_t_ptr *)0x0) || (iVar5 = (*pfnIgnore)(pe), iVar5 == 0)) {
        if (pe->model == (model_s *)0x0) {
          vStack_5c = pe->origin[0];
          pModel = pe->studiomodel;
          vStack_58 = pe->origin[1];
          aiStack_2c[0] = 1;
          vStack_54 = pe->origin[2];
          if ((pModel == (model_t *)0x0) || (pModel->type != mod_studio)) {
            iVar5 = pmove->usehull;
          }
          else if (((pModel->flags & 0x200) != 0) || (iVar5 = pmove->usehull, iVar5 == 2)) {
            hull = PM_HullForStudioModel
                             (pModel,&vStack_5c,pe->frame,pe->sequence,pe->angles,pe->origin,
                              pe->controller,pe->blending,aiStack_2c);
            goto LAB_00131bb9;
          }
          box_planes[1].dist = pe->mins[0] - player_maxs[iVar5][0];
          box_planes[3].dist = pe->mins[1] - player_maxs[iVar5][1];
          box_planes[5].dist = pe->mins[2] - player_maxs[iVar5][2];
          box_planes[2].dist = pe->maxs[1] - player_mins[iVar5][1];
          box_planes[4].dist = pe->maxs[2] - player_mins[iVar5][2];
          box_planes[0].dist = pe->maxs[0] - player_mins[iVar5][0];
          hull = &box_hull;
        }
        else {
          if ((pe->solid == 0) && (pe->skin != 0)) goto LAB_00131c60;
          vStack_5c = pe->origin[0];
          aiStack_2c[0] = 1;
          vStack_58 = pe->origin[1];
          vStack_54 = pe->origin[2];
          hull = PM_HullForBsp(pe,&vStack_5c);
        }
LAB_00131bb9:
        fStack_6c = *pos - vStack_5c;
        fStack_68 = pos[1] - vStack_58;
        fStack_64 = pos[2] - vStack_54;
        if ((pe->solid == 4) &&
           (((pe->angles[0] != 0.0 || (pe->angles[1] != 0.0)) || (pe->angles[2] != 0.0)))) {
          AngleVectors(pe->angles,(vec_t *)&pStack_b0,&fStack_44,&fStack_38);
          fVar3 = (float)pStack_b0.inopen * fStack_64;
          fVar1 = fStack_44 * fStack_6c;
          fVar2 = fStack_3c * fStack_64;
          fStack_64 = fStack_64 * fStack_30 + fStack_68 * fStack_34 + fStack_38 * fStack_6c;
          fStack_6c = fVar3 + (float)pStack_b0.startsolid * fStack_68 +
                              (float)pStack_b0.allsolid * fStack_6c;
          fStack_68 = -(fVar2 + fStack_40 * fStack_68 + fVar1);
        }
        if (aiStack_2c[0] == 1) {
          g_contentsresult = PM_HullPointContents(hull,hull->firstclipnode,&fStack_6c);
          if (g_contentsresult == -2) {
            return iStack_104;
          }
        }
        else if (0 < aiStack_2c[0]) {
          iVar5 = 0;
          do {
            g_contentsresult = PM_HullPointContents(hull,hull->firstclipnode,&fStack_6c);
            if (g_contentsresult == -2) {
              return iStack_104;
            }
            iVar5 = iVar5 + 1;
            hull = hull + 1;
          } while (iVar5 < aiStack_2c[0]);
        }
      }
LAB_00131c60:
      iStack_104 = iStack_104 + 1;
    } while (iStack_104 < pmove->numphysent);
  }
  return -1;
}


// PM_TraceLine  @ 00132a00
pmtrace_s * PM_TraceLine(float *start,float *end,int flags,int usehull,int ignore_pe)

{
  int iVar1;
  playermove_t_conflict *ppVar2;
  uint uVar3;
  _func_int_physent_t_ptr *pfnIgnore;
  pmtrace_t local_5c;
  
                    /* Unresolved local var: int oldhull@[???] */
  pfnIgnore = (_func_int_physent_t_ptr *)&ignore_pe;
  (*g_engdstAddrs.PM_TraceLine)(&start,&end,&flags,&usehull,(int *)pfnIgnore);
  ppVar2 = pmove;
  iVar1 = pmove->usehull;
  pmove->usehull = usehull;
  if (flags == 0) {
    _PM_PlayerTrace(&local_5c,start,end,ppVar2->numphysent,(int)ppVar2->physents,
                    (physent_t *)ignore_pe,0,pfnIgnore);
    uVar3 = 0;
    do {
      *(undefined4 *)((int)PM_TraceLine::tr.endpos + (uVar3 - 0x14)) =
           *(undefined4 *)((int)local_5c.endpos + (uVar3 - 0x14));
      uVar3 = uVar3 + 4;
      ppVar2 = pmove;
    } while (uVar3 < 0x44);
  }
  else if (flags == 1) {
    _PM_PlayerTrace(&local_5c,start,end,ppVar2->numvisent,(int)ppVar2->visents,
                    (physent_t *)ignore_pe,0,pfnIgnore);
    uVar3 = 0;
    do {
      *(undefined4 *)((int)PM_TraceLine::tr.endpos + (uVar3 - 0x14)) =
           *(undefined4 *)((int)local_5c.endpos + (uVar3 - 0x14));
      uVar3 = uVar3 + 4;
      ppVar2 = pmove;
    } while (uVar3 < 0x44);
  }
  ppVar2->usehull = iVar1;
  return &PM_TraceLine::tr;
}


// PM_TraceLineEx  @ 00132b40
pmtrace_s *
PM_TraceLineEx(float *start,float *end,int flags,int usehull,_func_int_physent_t_ptr *pfnIgnore)

{
  int iVar1;
  playermove_t_conflict *ppVar2;
  uint uVar3;
  _func_int_physent_t_ptr *in_stack_ffffff14;
  pmtrace_t local_94;
  undefined4 auStack_50 [17];
  
                    /* Unresolved local var: int oldhull@[???] */
  ppVar2 = pmove;
  iVar1 = pmove->usehull;
  pmove->usehull = usehull;
                    /* Unresolved local var: pmtrace_t tr@[???] */
  if (flags == 0) {
    _PM_PlayerTrace(&local_94,start,end,ppVar2->numphysent,(int)ppVar2->physents,
                    (physent_t *)0xffffffff,(int)pfnIgnore,in_stack_ffffff14);
    uVar3 = 0;
    do {
      *(undefined4 *)((int)auStack_50 + uVar3) =
           *(undefined4 *)((int)local_94.endpos + (uVar3 - 0x14));
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x44);
    uVar3 = 0;
    do {
      *(undefined4 *)((int)PM_TraceLineEx::tr.endpos + (uVar3 - 0x14)) =
           *(undefined4 *)((int)auStack_50 + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x44);
  }
  else {
    _PM_PlayerTrace((pmtrace_t *)&stack0xffffff14,start,end,ppVar2->numvisent,(int)ppVar2->visents,
                    (physent_t *)0xffffffff,(int)pfnIgnore,in_stack_ffffff14);
    uVar3 = 0;
    do {
      *(undefined4 *)((int)PM_TraceLineEx::tr.endpos + (uVar3 - 0x14)) =
           *(undefined4 *)(&stack0xffffff14 + uVar3);
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x44);
  }
  pmove->usehull = iVar1;
  return &PM_TraceLineEx::tr;
}


// PM_TraceModel  @ 00131980
float PM_TraceModel(physent_t *pEnt,vec_t *start,vec_t *end,trace_t *trace)

{
  int iVar1;
  hull_t *hull;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: hull_t * pHull@[???]
                       Unresolved local var: int saveHull@[???]
                       Unresolved local var: vec3_t start_l@[???]
                       Unresolved local var: vec3_t end_l@[???]
                       Unresolved local var: vec3_t offset@[???] */
  iVar1 = pmove->usehull;
  pmove->usehull = 2;
  hull = PM_HullForBsp(pEnt,&local_28);
  pmove->usehull = iVar1;
  local_40 = *start - local_28;
  local_3c = start[1] - local_24;
  local_38 = start[2] - local_20;
  local_34 = *end - local_28;
  local_30 = end[1] - local_24;
  local_2c = end[2] - local_20;
  SV_RecursiveHullCheck(hull,hull->firstclipnode,0.0,1.0,&local_40,&local_34,trace);
  trace->ent = (edict_t_conflict *)0x0;
  return trace->fraction;
}


// PM_TruePointContents  @ 00130e20
int PM_TruePointContents(vec_t *p)

{
  model_s *pmVar1;
  int iVar2;
  hull_t *hull;
  
                    /* Unresolved local var: hull_t * hull@[???] */
  pmVar1 = pmove->physents[0].model;
  hull = pmVar1->hulls;
  if (hull == (hull_t *)0x0) {
    iVar2 = -1;
  }
  else {
    iVar2 = PM_HullPointContents(hull,pmVar1->hulls[0].firstclipnode,p);
  }
  return iVar2;
}


// PM_WaterEntity  @ 00130da0
int PM_WaterEntity(vec_t *p)

{
  model_s *pmVar1;
  int iVar2;
  int local_1c [7];
  
                    /* Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: int num@[???]
                       Unresolved local var: int entityIndex@[???]
                       Unresolved local var: int cont@[???] */
  (*g_engdstAddrs.PM_WaterEntity)(&p);
  local_1c[0] = -1;
  pmVar1 = pmove->physents[0].model;
  iVar2 = PM_HullPointContents(pmVar1->hulls,pmVar1->hulls[0].firstclipnode,p);
  if (iVar2 < -2) {
    local_1c[0] = 0;
  }
  else if (iVar2 == -2) {
    return local_1c[0];
  }
  PM_LinkContents(p,local_1c);
  return local_1c[0];
}


