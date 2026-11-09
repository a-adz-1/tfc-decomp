// PM_AddToTouched  @ 000cac90
qboolean PM_AddToTouched(pmtrace_t tr,vec_t *impactvelocity)

{
  int iVar1;
  int *piVar2;
  playermove_t_conflict *ppVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  vec_t vVar7;
  vec_t vVar8;
  vec_t vVar9;
  
                    /* Unresolved local var: int i@[???] */
  iVar6 = pmove->numtouch;
  if (iVar6 < 1) {
    if (iVar6 == 0) {
      vVar9 = *impactvelocity;
      vVar8 = impactvelocity[1];
      vVar7 = impactvelocity[2];
LAB_000caceb:
      ppVar3 = pmove;
      pmove->numtouch = iVar6 + 1;
      tr.deltavelocity[0] = vVar9;
      tr.deltavelocity[1] = vVar8;
      uVar5 = 0;
      tr.deltavelocity[2] = vVar7;
      do {
        *(undefined4 *)((int)ppVar3->touchindex[iVar6].endpos + (uVar5 - 0x14)) =
             *(undefined4 *)((int)tr.endpos + (uVar5 - 0x14));
        uVar5 = uVar5 + 4;
      } while (uVar5 < 0x44);
      return true;
    }
  }
  else {
    iVar4 = 0;
    iVar1 = pmove->touchindex[0].ent;
    piVar2 = &pmove->touchindex[1].ent;
    while (tr.ent != iVar1) {
      iVar4 = iVar4 + 1;
      if (iVar4 == iVar6) {
        vVar9 = *impactvelocity;
        vVar8 = impactvelocity[1];
        vVar7 = impactvelocity[2];
        if (599 < iVar6) {
          (*pmove->Con_DPrintf)("Too many entities were touched!\n");
          iVar6 = pmove->numtouch;
        }
        goto LAB_000caceb;
      }
      iVar1 = *piVar2;
      piVar2 = piVar2 + 0x11;
    }
  }
  return false;
}


// PM_CL_PlaySound  @ 0013a310
void PM_CL_PlaySound(int channel,char *sample,float volume,float attenuation,int fFlags,int pitch)

{
  sfx_t *sfxin;
  int iVar1;
  int in_GS_OFFSET;
  sfx_t local_58;
  int local_10;
  
                    /* Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: sfx_t sfxsentence@[???]
                       Unresolved local var: int i@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (pmove->runfuncs != false) {
    g_laststepgap = (float)cl.time - PM_CL_PlaySound::lexical_block_0::last;
    PM_CL_PlaySound::lexical_block_0::last = (float)cl.time;
    if ((fFlags & 0x10U) == 0) {
      sfxin = CL_LookupSound(sample);
    }
    else {
      iVar1 = Q_atoi(sample + 1);
      sfxin = &local_58;
      __snprintf_chk(sfxin,0x40,1,0x40,&DAT_00263ab4,rgpszrawsentence[iVar1]);
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
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// PM_CL_PlaybackEventFull  @ 00139f20
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
    local_64.iparam1 = iparam1;
    local_64.angles[0] = *angles;
    local_64.angles[1] = angles[1];
    local_64.angles[2] = angles[2];
    local_64.iparam2 = iparam2;
    local_64.bparam1 = bparam1;
    local_64.bparam2 = bparam2;
    local_64.fparam1 = fparam1;
    local_64.fparam2 = fparam2;
    CL_ClientQueueEvent(flags,(uint)eventindex,clientindex,delay,&local_64);
  }
  return;
}


// PM_CL_TraceTexture  @ 0013a060
char * PM_CL_TraceTexture(int ground,float *vstart,float *vend)

{
  float fVar1;
  float fVar2;
  float fVar3;
  playermove_t_conflict *ppVar4;
  msurface_t *pmVar5;
  int iVar6;
  model_s *pModel;
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
  if (((-1 < ground) && (ground < pmove->numphysent)) &&
     (pModel = pmove->physents[ground].model, pModel != (model_s *)0x0)) {
    if (ground < 1) {
      local_58 = *vstart;
      iVar6 = 0;
      local_54 = vstart[1];
      local_50 = vstart[2];
      local_4c = *vend;
      local_48 = vend[1];
      local_44 = vend[2];
    }
    else {
                    /* Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: hull_t * phull@[???] */
      local_4c = pModel->hulls[0].clip_mins[0] + pmove->physents[ground].origin[0];
      iVar6 = pModel->hulls[0].firstclipnode;
      local_48 = pModel->hulls[0].clip_mins[1] + pmove->physents[ground].origin[1];
      local_44 = pModel->hulls[0].clip_mins[2] + pmove->physents[ground].origin[2];
      local_58 = *vstart - local_4c;
      local_54 = vstart[1] - local_48;
      local_50 = vstart[2] - local_44;
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
        fVar3 = local_38 * local_50;
        fVar1 = local_34 * local_58;
        fVar2 = local_2c * local_50;
        local_50 = local_50 * local_20 + local_54 * local_24 + local_58 * local_28;
        local_38 = local_38 * local_44;
        local_34 = local_34 * local_4c;
        local_2c = local_2c * local_44;
        local_44 = local_20 * local_44 + local_48 * local_24 + local_4c * local_28;
        pModel = ppVar4->physents[ground].model;
        local_58 = fVar3 + local_3c * local_54 + local_40 * local_58;
        local_54 = -(fVar2 + local_30 * local_54 + fVar1);
        local_4c = local_38 + local_3c * local_48 + local_40 * local_4c;
        local_48 = -(local_2c + local_30 * local_48 + local_34);
        if (pModel == (model_s *)0x0) {
          return (char *)0x0;
        }
      }
    }
    if (((pModel->type == mod_brush) && (pModel->nodes != (mnode_t *)0x0)) &&
       (pmVar5 = SurfaceAtPoint(pModel,pModel->nodes + iVar6,&local_58,&local_4c),
       pmVar5 != (msurface_t *)0x0)) {
      return pmVar5->texinfo->texture->name;
    }
  }
  return (char *)0x0;
}


// PM_DrawBBox  @ 001a3060
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
  int *piVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c [4];
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
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: vec_t[8][3] p@[???]
                       Unresolved local var: float gap@[???] */
  piVar13 = PM_boxpnt[0] + 3;
  local_7c[1] = maxs[1] + 0.0 + origin[1];
  local_7c[2] = maxs[2] + 0.0 + origin[2];
  local_7c[0] = *maxs + 0.0 + *origin;
  local_7c[3] = *origin + *mins;
  local_6c = local_7c[1];
  local_68 = local_7c[2];
  local_60 = origin[1] + mins[1];
  local_64 = local_7c[0];
  local_5c = local_7c[2];
  local_58 = local_7c[3];
  local_54 = local_60;
  local_50 = local_7c[2];
  local_44 = origin[2] + mins[2];
  local_4c = local_7c[0];
  local_48 = local_7c[1];
  local_40 = local_7c[3];
  local_3c = local_7c[1];
  local_38 = local_44;
  local_34 = local_7c[0];
  local_30 = local_60;
  local_2c = local_44;
  local_28 = local_7c[3];
  local_24 = local_60;
  local_20 = local_44;
  do {
    iVar8 = *piVar13;
    iVar9 = piVar13[-1];
    iVar10 = (*(int (*) [4])(piVar13 + -3))[0];
    iVar11 = piVar13[-2];
                    /* Unresolved local var: float linestep@[???]
                       Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???] */
    fVar1 = local_7c[iVar10 * 3];
    fVar2 = local_7c[iVar11 * 3];
    local_88 = fVar1 - fVar2;
    fVar3 = local_7c[iVar10 * 3 + 1];
    fVar16 = local_7c[iVar11 * 3 + 1];
    local_84 = fVar3 - fVar16;
    fVar4 = local_7c[iVar10 * 3 + 2];
    fVar5 = local_7c[iVar11 * 3 + 2];
    local_80 = fVar4 - fVar5;
    fVar14 = VectorNormalize(&local_88);
    fVar6 = 0.0;
    if (0.0 <= fVar14) {
      do {
        local_94 = local_88 * fVar6 + fVar2;
        local_90 = local_84 * fVar6 + fVar16;
        local_8c = fVar6 * local_80 + fVar5;
        CL_Particle(&local_94,pcolor,life,0,0);
        fVar6 = fVar6 + 2.0;
      } while (fVar6 <= fVar14);
    }
                    /* Unresolved local var: float linestep@[???]
                       Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???] */
    fVar6 = local_7c[iVar8 * 3];
    local_88 = fVar6 - fVar1;
    fVar14 = local_7c[iVar8 * 3 + 1];
    local_84 = fVar14 - fVar3;
    fVar7 = local_7c[iVar8 * 3 + 2];
    local_80 = fVar7 - fVar4;
    fVar15 = VectorNormalize(&local_88);
    fVar12 = 0.0;
    if (0.0 <= fVar15) {
      do {
        local_94 = local_88 * fVar12 + fVar1;
        local_90 = local_84 * fVar12 + fVar3;
        local_8c = fVar12 * local_80 + fVar4;
        CL_Particle(&local_94,pcolor,life,0,0);
        fVar12 = fVar12 + 2.0;
      } while (fVar12 <= fVar15);
    }
                    /* Unresolved local var: float linestep@[???]
                       Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???] */
    fVar1 = local_7c[iVar9 * 3];
    local_88 = fVar1 - fVar6;
    fVar3 = local_7c[iVar9 * 3 + 1];
    local_84 = fVar3 - fVar14;
    fVar4 = local_7c[iVar9 * 3 + 2];
    local_80 = fVar4 - fVar7;
    fVar15 = VectorNormalize(&local_88);
    fVar12 = 0.0;
    if (0.0 <= fVar15) {
      do {
        local_94 = local_88 * fVar12 + fVar6;
        local_90 = local_84 * fVar12 + fVar14;
        local_8c = fVar12 * local_80 + fVar7;
        CL_Particle(&local_94,pcolor,life,0,0);
        fVar12 = fVar12 + 2.0;
      } while (fVar12 <= fVar15);
    }
                    /* Unresolved local var: float linestep@[???]
                       Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???] */
    local_88 = fVar2 - fVar1;
    local_84 = fVar16 - fVar3;
    local_80 = fVar5 - fVar4;
    fVar16 = VectorNormalize(&local_88);
    fVar2 = 0.0;
    if (0.0 <= fVar16) {
      do {
        local_94 = local_88 * fVar2 + fVar1;
        local_90 = local_84 * fVar2 + fVar3;
        local_8c = fVar2 * local_80 + fVar4;
        CL_Particle(&local_94,pcolor,life,0,0);
        fVar2 = fVar2 + 2.0;
      } while (fVar2 <= fVar16);
    }
    piVar13 = piVar13 + 4;
  } while (piVar13 != (int *)0x26ddec);
  return;
}


// PM_DrawRectangle  @ 001a2d30
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
  
                    /* Unresolved local var: float linestep@[???]
                       Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???] */
  local_28 = *bl - *tl;
  local_24 = bl[1] - tl[1];
  local_20 = bl[2] - tl[2];
  fVar2 = VectorNormalize(&local_28);
  fVar1 = 0.0;
  if (0.0 <= fVar2) {
    do {
      local_34 = local_28 * fVar1 + *tl;
      local_30 = local_24 * fVar1 + tl[1];
      local_2c = fVar1 * local_20 + tl[2];
      CL_Particle(&local_34,pcolor,life,0,0);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
                    /* Unresolved local var: float linestep@[???]
                       Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???] */
  local_28 = *br - *bl;
  local_24 = br[1] - bl[1];
  local_20 = br[2] - bl[2];
  fVar2 = VectorNormalize(&local_28);
  fVar1 = 0.0;
  if (0.0 <= fVar2) {
    do {
      local_34 = local_28 * fVar1 + *bl;
      local_30 = local_24 * fVar1 + bl[1];
      local_2c = fVar1 * local_20 + bl[2];
      CL_Particle(&local_34,pcolor,life,0,0);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
                    /* Unresolved local var: float linestep@[???]
                       Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???] */
  local_28 = *tr - *br;
  local_24 = tr[1] - br[1];
  local_20 = tr[2] - br[2];
  fVar2 = VectorNormalize(&local_28);
  fVar1 = 0.0;
  if (0.0 <= fVar2) {
    do {
      local_34 = local_28 * fVar1 + *br;
      local_30 = local_24 * fVar1 + br[1];
      local_2c = fVar1 * local_20 + br[2];
      CL_Particle(&local_34,pcolor,life,0,0);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
                    /* Unresolved local var: float linestep@[???]
                       Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???] */
  local_28 = *tl - *tr;
  local_24 = tl[1] - tr[1];
  local_20 = tl[2] - tr[2];
  fVar2 = VectorNormalize(&local_28);
  fVar1 = 0.0;
  if (0.0 <= fVar2) {
    do {
      local_34 = local_28 * fVar1 + *tr;
      local_30 = local_24 * fVar1 + tr[1];
      local_2c = fVar1 * local_20 + tr[2];
      CL_Particle(&local_34,pcolor,life,0,0);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
  return;
}


// PM_GetModelBounds  @ 000cb8c0
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


// PM_GetModelType  @ 000cb910
int PM_GetModelType(model_s *mod)

{
  return mod->type;
}


// PM_HullForBox  @ 000cba60
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


// PM_HullForBsp  @ 000cc4a0
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


// PM_HullForStudioModel  @ 000cc3d0
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


// PM_HullPointContents  @ 000cbac0
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
                    /* WARNING: Subroutine does not return */
          Sys_Error("PM_HullPointContents: bad node number");
        }
        pdVar1 = hull->clipnodes + num;
        pmVar2 = hull->planes + pdVar1->planenum;
        if (pmVar2->type < 3) {
          if (p[pmVar2->type] - pmVar2->dist < 0.0) goto LAB_000cbb46;
LAB_000cbaee:
          sVar3 = pdVar1->children[0];
        }
        else {
          if (0.0 <= (pmVar2->normal[2] * p[2] + pmVar2->normal[1] * p[1] + pmVar2->normal[0] * *p)
                     - pmVar2->dist) goto LAB_000cbaee;
LAB_000cbb46:
          sVar3 = pdVar1->children[1];
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


// PM_Init  @ 000cada0
void PM_Init(playermove_t_conflict *ppm)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  vec_t vVar6;
  vec_t vVar7;
  vec_t vVar8;
  vec_t vVar9;
  vec_t vVar10;
  vec_t vVar11;
  vec_t vVar12;
  
                    /* Unresolved local var: int i@[???] */
  PM_InitBoxHull();
  vVar9 = player_mins[0][2];
  vVar7 = player_mins[0][1];
  vVar6 = player_maxs[0][0];
  if ((ppm->player_mins < &pm_showclip && player_mins < &ppm->PM_Info_ValueForKey) ||
     (ppm->player_mins < &DAT_002cd270 && player_maxs < &ppm->PM_Info_ValueForKey)) {
    ppm->player_mins[0][0] = player_mins[0][0];
    ppm->player_mins[0][1] = vVar7;
    vVar8 = player_maxs[0][2];
    vVar7 = player_maxs[0][1];
    ppm->player_mins[0][2] = vVar9;
    ppm->player_maxs[0][0] = vVar6;
    vVar10 = player_mins[1][1];
    vVar9 = player_mins[1][0];
    ppm->player_maxs[0][1] = vVar7;
    ppm->player_maxs[0][2] = vVar8;
    vVar8 = player_mins[1][2];
    vVar6 = player_maxs[1][0];
    ppm->player_mins[1][0] = vVar9;
    ppm->player_mins[1][1] = vVar10;
    vVar9 = player_maxs[1][2];
    vVar7 = player_maxs[1][1];
    ppm->player_mins[1][2] = vVar8;
    ppm->player_maxs[1][0] = vVar6;
    vVar10 = player_mins[2][1];
    vVar8 = player_mins[2][0];
    ppm->player_maxs[1][1] = vVar7;
    ppm->player_maxs[1][2] = vVar9;
    vVar7 = player_mins[2][2];
    vVar6 = player_maxs[2][0];
    ppm->player_mins[2][0] = vVar8;
    ppm->player_mins[2][1] = vVar10;
    ppm->player_mins[2][2] = vVar7;
    ppm->player_maxs[2][0] = vVar6;
    vVar12 = player_mins[3][2];
    vVar11 = player_mins[3][1];
    vVar10 = player_mins[3][0];
    vVar8 = player_maxs[3][2];
    vVar9 = player_maxs[3][1];
    vVar7 = player_maxs[3][0];
    vVar6 = player_maxs[2][2];
    ppm->player_maxs[2][1] = player_maxs[2][1];
    ppm->player_maxs[2][2] = vVar6;
    ppm->player_mins[3][0] = vVar10;
    ppm->player_mins[3][1] = vVar11;
    ppm->player_mins[3][2] = vVar12;
    ppm->player_maxs[3][0] = vVar7;
    ppm->player_maxs[3][1] = vVar9;
    ppm->player_maxs[3][2] = vVar8;
  }
  else {
    uVar1 = CONCAT44(player_mins[1][0],player_mins[0][2]);
    uVar2 = CONCAT44(player_mins[1][2],player_mins[1][1]);
    uVar3 = CONCAT44(player_mins[2][1],player_mins[2][0]);
    *(ulonglong *)ppm->player_mins[0] = CONCAT44(player_mins[0][1],player_mins[0][0]);
    *(undefined8 *)(ppm->player_mins[0] + 2) = uVar1;
    uVar4 = CONCAT44(player_mins[3][0],player_mins[2][2]);
    uVar5 = CONCAT44(player_mins[3][2],player_mins[3][1]);
    *(undefined8 *)(ppm->player_mins[1] + 1) = uVar2;
    *(undefined8 *)ppm->player_mins[2] = uVar3;
    uVar1 = CONCAT44(player_maxs[0][1],player_maxs[0][0]);
    uVar2 = CONCAT44(player_maxs[1][0],player_maxs[0][2]);
    *(undefined8 *)(ppm->player_mins[2] + 2) = uVar4;
    *(undefined8 *)(ppm->player_mins[3] + 1) = uVar5;
    uVar3 = CONCAT44(player_maxs[1][2],player_maxs[1][1]);
    uVar4 = CONCAT44(player_maxs[2][1],player_maxs[2][0]);
    *(undefined8 *)ppm->player_maxs[0] = uVar1;
    *(undefined8 *)(ppm->player_maxs[0] + 2) = uVar2;
    uVar1 = CONCAT44(player_maxs[3][0],player_maxs[2][2]);
    uVar2 = CONCAT44(player_maxs[3][2],player_maxs[3][1]);
    *(undefined8 *)(ppm->player_maxs[1] + 1) = uVar3;
    *(undefined8 *)ppm->player_maxs[2] = uVar4;
    *(undefined8 *)(ppm->player_maxs[2] + 2) = uVar1;
    *(undefined8 *)(ppm->player_maxs[3] + 1) = uVar2;
  }
  ppm->movevars = &movevars;
  ppm->Con_NPrintf = Con_NPrintf;
  ppm->Con_DPrintf = Con_DPrintf;
  ppm->Con_Printf = Con_Printf;
  ppm->Sys_FloatTime = Sys_FloatTime;
  ppm->PM_StuckTouch = PM_StuckTouch;
  ppm->PM_PointContents = PM_PointContents;
  ppm->PM_TraceLine = PM_TraceLine;
  ppm->PM_TraceModel = PM_TraceModel;
  ppm->RandomLong = RandomLong;
  ppm->RandomFloat = RandomFloat;
  ppm->PM_GetModelType = PM_GetModelType;
  ppm->PM_HullForBsp = PM_HullForBsp;
  ppm->COM_FreeFile = COM_FreeFile;
  ppm->memfgets = memfgets;
  ppm->PM_Info_ValueForKey = Info_ValueForKey;
  ppm->PM_Particle = CL_Particle;
  ppm->PM_TestPlayerPosition = PM_TestPlayerPosition;
  ppm->PM_PlayerTraceEx = PM_PlayerTraceEx;
  ppm->PM_TruePointContents = PM_TruePointContents;
  ppm->PM_HullPointContents = PM_HullPointContents;
  ppm->PM_PlayerTrace = PM_PlayerTrace;
  ppm->PM_TestPlayerPositionEx = PM_TestPlayerPositionEx;
  ppm->PM_GetModelBounds = PM_GetModelBounds;
  ppm->COM_FileSize = COM_FileSize;
  ppm->COM_LoadFile = COM_LoadFile;
  ppm->PM_TraceLineEx = PM_TraceLineEx;
  return;
}


// PM_InitBoxHull  @ 000cb920
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_InitBoxHull(void)

{
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???] */
  box_hull.clipnodes = box_clipnodes;
  box_hull.lastclipnode = 5;
  box_clipnodes[0].planenum = 0;
  box_clipnodes[0].children[0] = -1;
  box_clipnodes[0].children[1] = 1;
  box_clipnodes[1].planenum = 1;
  box_clipnodes[1].children[1] = -1;
  box_clipnodes[2].children[0] = -1;
  box_clipnodes[2].children[1] = 3;
  box_clipnodes[3].planenum = 3;
  box_planes[0].normal[0] = 1.0;
  box_clipnodes[3].children[1] = -1;
  box_planes[1].normal[0] = 1.0;
  box_clipnodes[3].children[0] = 4;
  box_planes[2].normal[1] = 1.0;
  box_clipnodes[4].planenum = 4;
  box_hull.planes = box_planes;
  box_planes[3].normal[1] = 1.0;
  box_hull.firstclipnode = 0;
  box_clipnodes[5].planenum = 5;
  box_clipnodes[1].children[0] = 2;
  box_planes[4].normal[2] = 1.0;
  box_clipnodes[2].planenum = 2;
  box_clipnodes[5].children[1] = -1;
  box_planes[0].type = '\0';
  box_planes[1].type = '\0';
  box_planes[2].type = '\x01';
  box_planes[3].type = '\x01';
  box_clipnodes[4].children[0] = -1;
  box_clipnodes[4].children[1] = 5;
  box_planes[4].type = '\x02';
  box_clipnodes[5].children[0] = -2;
  box_planes[5].type = '\x02';
  box_planes[5].normal[2] = 1.0;
  return;
}


// PM_LinkContents  @ 000cbb60
/* WARNING: Type propagation algorithm not settling */

int PM_LinkContents(vec_t *p,int *pIndex)

{
  dclipnode_t *pdVar1;
  mplane_t *pmVar2;
  short sVar3;
  model_s *pmVar4;
  playermove_t_conflict *ppVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float local_28 [6];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: physent_t * pe@[???]
                       Unresolved local var: vec3_t test@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: int num@[???]
                       Unresolved local var: int cont@[???] */
  ppVar5 = pmove;
  iVar6 = pmove->numphysent;
  if (1 < iVar6) {
    iVar7 = 1;
    do {
      while ((pmove->physents[iVar7].solid == 0 &&
             (pmVar4 = pmove->physents[iVar7].model, pmVar4 != (model_s *)0x0))) {
        local_28[0] = *p - pmove->physents[iVar7].origin[0];
        iVar6 = pmVar4->hulls[0].firstclipnode;
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???] */
        local_28[1] = p[1] - pmove->physents[iVar7].origin[1];
        local_28[2] = p[2] - pmove->physents[iVar7].origin[2];
        if (pmVar4->hulls[0].lastclipnode <= iVar6) {
          iVar6 = pmove->numphysent;
          break;
        }
        iVar8 = iVar6;
        if (-1 < iVar6) {
          do {
            if ((iVar8 < iVar6) || (pmVar4->hulls[0].lastclipnode < iVar8)) {
                    /* WARNING: Subroutine does not return */
              Sys_Error("PM_HullPointContents: bad node number");
            }
            pdVar1 = pmVar4->hulls[0].clipnodes + iVar8;
            pmVar2 = pmVar4->hulls[0].planes + pdVar1->planenum;
            if (pmVar2->type < 3) {
              if (local_28[pmVar2->type] - pmVar2->dist < 0.0) goto LAB_000cbc98;
LAB_000cbc2f:
              sVar3 = pdVar1->children[0];
            }
            else {
              if (0.0 <= (local_28[2] * pmVar2->normal[2] +
                         local_28[1] * pmVar2->normal[1] + local_28[0] * pmVar2->normal[0]) -
                         pmVar2->dist) goto LAB_000cbc2f;
LAB_000cbc98:
              sVar3 = pdVar1->children[1];
            }
            iVar8 = (int)sVar3;
            if (iVar8 < 0) break;
            iVar6 = pmVar4->hulls[0].firstclipnode;
          } while( true );
        }
        if (iVar8 != -1) {
          if (pIndex != (int *)0x0) {
            *pIndex = pmove->physents[iVar7].info;
          }
          return ppVar5->physents[iVar7].skin;
        }
        iVar7 = iVar7 + 1;
        iVar6 = pmove->numphysent;
        if (iVar6 <= iVar7) {
          return -1;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar6);
  }
  return -1;
}


// PM_ParticleLine  @ 001a2c60
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
  if (0.0 <= fVar2) {
    fVar1 = 0.0;
    do {
      local_34 = local_28 * fVar1 + *start;
      local_30 = local_24 * fVar1 + start[1];
      local_2c = fVar1 * local_20 + start[2];
      CL_Particle(&local_34,pcolor,life,0,(int)vert);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
  return;
}


// PM_PlayerTrace  @ 000cd690
pmtrace_t *
PM_PlayerTrace(pmtrace_t *__return_storage_ptr__,vec_t *start,vec_t *end,int traceFlags,
              int ignore_pe)

{
                    /* Unresolved local var: pmtrace_t tr@[???] */
  _PM_PlayerTrace(__return_storage_ptr__,start,end,traceFlags,pmove->numphysent,pmove->physents,
                  ignore_pe,(_func_int_physent_t_ptr *)0x0);
  return __return_storage_ptr__;
}


// PM_PlayerTraceEx  @ 000cd6f0
pmtrace_t *
PM_PlayerTraceEx(pmtrace_t *__return_storage_ptr__,vec_t *start,vec_t *end,int traceFlags,
                _func_int_physent_t_ptr *pfnIgnore)

{
                    /* Unresolved local var: pmtrace_t tr@[???] */
  _PM_PlayerTrace(__return_storage_ptr__,start,end,traceFlags,pmove->numphysent,pmove->physents,-1,
                  pfnIgnore);
  return __return_storage_ptr__;
}


// PM_PointContents  @ 000cbd30
/* WARNING: Type propagation algorithm not settling */

int PM_PointContents(vec_t *p,int *truecontents)

{
  dclipnode_t *pdVar1;
  mplane_t *pmVar2;
  short sVar3;
  model_s *pmVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  playermove_t_conflict *local_40;
  float local_28 [6];
  
                    /* Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: int num@[???]
                       Unresolved local var: int cont@[???]
                       Unresolved local var: int entityContents@[???] */
  (*g_engdstAddrs.PM_PointContents)(&p,&truecontents);
  pmVar4 = pmove->physents[0].model;
  local_40 = pmove;
  if (pmVar4 == (model_s *)0xffffff30) {
    if (truecontents != (int *)0x0) {
      *truecontents = -1;
    }
LAB_000cbfa5:
    iVar7 = -2;
  }
  else {
    iVar5 = pmVar4->hulls[0].firstclipnode;
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???] */
    if (iVar5 < pmVar4->hulls[0].lastclipnode) {
      iVar7 = iVar5;
      if (-1 < iVar5) {
        do {
          if ((iVar7 < iVar5) || (pmVar4->hulls[0].lastclipnode < iVar7)) {
                    /* WARNING: Subroutine does not return */
            Sys_Error("PM_HullPointContents: bad node number");
          }
          pdVar1 = pmVar4->hulls[0].clipnodes + iVar7;
          pmVar2 = pmVar4->hulls[0].planes + pdVar1->planenum;
          if (pmVar2->type < 3) {
            if (p[pmVar2->type] - pmVar2->dist < 0.0) goto LAB_000cbe03;
LAB_000cbd9e:
            sVar3 = pdVar1->children[0];
          }
          else {
            if (0.0 <= (pmVar2->normal[2] * p[2] + pmVar2->normal[1] * p[1] + pmVar2->normal[0] * *p
                       ) - pmVar2->dist) goto LAB_000cbd9e;
LAB_000cbe03:
            sVar3 = pdVar1->children[1];
          }
          iVar7 = (int)sVar3;
          if (iVar7 < 0) break;
          iVar5 = pmVar4->hulls[0].firstclipnode;
        } while( true );
      }
      uVar6 = iVar7 + 0xe;
      if (truecontents != (int *)0x0) {
LAB_000cbe16:
        *truecontents = iVar7;
      }
      if (uVar6 < 6) {
        iVar7 = -3;
        local_40 = pmove;
      }
      else {
        if (iVar7 == -2) goto LAB_000cbfa5;
        local_40 = pmove;
      }
    }
    else {
      if (truecontents != (int *)0x0) {
        uVar6 = 0xd;
        iVar7 = -1;
        goto LAB_000cbe16;
      }
      iVar7 = -1;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: physent_t * pe@[???]
                       Unresolved local var: vec3_t test@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: int num@[???]
                       Unresolved local var: int cont@[???] */
    iVar5 = local_40->numphysent;
    pmove = local_40;
    if (1 < iVar5) {
      iVar9 = 1;
      do {
        while ((local_40->physents[iVar9].solid == 0 &&
               (pmVar4 = local_40->physents[iVar9].model, pmVar4 != (model_s *)0x0))) {
          local_28[0] = *p - local_40->physents[iVar9].origin[0];
          iVar5 = pmVar4->hulls[0].firstclipnode;
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???] */
          local_28[1] = p[1] - local_40->physents[iVar9].origin[1];
          local_28[2] = p[2] - local_40->physents[iVar9].origin[2];
          if (pmVar4->hulls[0].lastclipnode <= iVar5) {
            iVar5 = local_40->numphysent;
            break;
          }
          iVar8 = iVar5;
          if (-1 < iVar5) {
            do {
              if ((iVar8 < iVar5) || (pmVar4->hulls[0].lastclipnode < iVar8)) {
                    /* WARNING: Subroutine does not return */
                Sys_Error("PM_HullPointContents: bad node number");
              }
              pdVar1 = pmVar4->hulls[0].clipnodes + iVar8;
              pmVar2 = pmVar4->hulls[0].planes + pdVar1->planenum;
              if (pmVar2->type < 3) {
                if (local_28[pmVar2->type] - pmVar2->dist < 0.0) goto LAB_000cbf60;
LAB_000cbef7:
                sVar3 = pdVar1->children[0];
              }
              else {
                if (0.0 <= (local_28[2] * pmVar2->normal[2] +
                           local_28[1] * pmVar2->normal[1] + local_28[0] * pmVar2->normal[0]) -
                           pmVar2->dist) goto LAB_000cbef7;
LAB_000cbf60:
                sVar3 = pdVar1->children[1];
              }
              iVar8 = (int)sVar3;
              if (iVar8 < 0) break;
              iVar5 = pmVar4->hulls[0].firstclipnode;
            } while( true );
          }
          if (iVar8 != -1) {
            iVar5 = local_40->physents[iVar9].skin;
            if (iVar5 == -1) {
              iVar5 = iVar7;
            }
            return iVar5;
          }
          iVar9 = iVar9 + 1;
          iVar5 = local_40->numphysent;
          if (iVar5 <= iVar9) {
            return iVar7;
          }
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar5);
    }
  }
  return iVar7;
}


// PM_RecursiveHullCheck  @ 000cb130
qboolean __regparm3
PM_RecursiveHullCheck(hull_t *hull,int num,float p1f,float p2f,vec_t *p1,vec_t *p2,pmtrace_t *trace)

{
  dclipnode_t *pdVar1;
  mplane_t *pmVar2;
  dclipnode_t *pdVar3;
  mplane_t *pmVar4;
  byte bVar5;
  short sVar6;
  float fVar7;
  bool bVar8;
  qboolean qVar9;
  int iVar10;
  int iVar11;
  float local_44;
  float local_40;
  vec_t *local_38;
  float local_28 [6];
  
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
  pdVar1 = hull->clipnodes + num;
  pmVar2 = hull->planes + pdVar1->planenum;
  bVar5 = pmVar2->type;
  if (bVar5 < 3) {
    local_40 = *(float *)((int)p1f + (uint)bVar5 * 4) - pmVar2->dist;
    fVar7 = p2[bVar5] - pmVar2->dist;
  }
  else {
    local_40 = (pmVar2->normal[2] * *(float *)((int)p1f + 8) +
               pmVar2->normal[1] * *(float *)((int)p1f + 4) + pmVar2->normal[0] * *(float *)p1f) -
               pmVar2->dist;
    fVar7 = (pmVar2->normal[2] * p2[2] + pmVar2->normal[1] * p2[1] + pmVar2->normal[0] * *p2) -
            pmVar2->dist;
  }
  if ((local_40 < 0.0) || (fVar7 < 0.0)) {
    if (0.0 <= local_40) {
      if (local_40 < 0.0) goto LAB_000cb644;
      local_44 = (local_40 - 0.03125) / (local_40 - fVar7);
      if (local_44 < 0.0) goto LAB_000cb672;
LAB_000cb1ce:
      if (1.0 < local_44) {
        local_44 = 1.0;
      }
    }
    else {
      if (fVar7 < 0.0) {
        iVar10 = (int)pdVar1->children[1];
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
        if (-1 < iVar10) {
          if (hull->firstclipnode < hull->lastclipnode) {
            qVar9 = PM_RecursiveHullCheck(hull,iVar10,p1f,p2f,p1,p2,trace);
            return qVar9;
          }
          goto LAB_000cb618;
        }
        goto LAB_000cb698;
      }
LAB_000cb644:
      local_44 = (local_40 + 0.03125) / (local_40 - fVar7);
      if (0.0 <= local_44) goto LAB_000cb1ce;
LAB_000cb672:
      local_44 = 0.0;
    }
    local_38 = (vec_t *)(((float)p1 - p2f) * local_44 + p2f);
    local_28[0] = (*p2 - *(float *)p1f) * local_44 + *(float *)p1f;
    local_28[1] = (p2[1] - *(float *)((int)p1f + 4)) * local_44 + *(float *)((int)p1f + 4);
    local_28[2] = (p2[2] - *(float *)((int)p1f + 8)) * local_44 + *(float *)((int)p1f + 8);
    iVar10 = (int)pdVar1->children[local_40 < 0.0];
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
    if (iVar10 < 0) {
      if (iVar10 == -2) {
        trace->startsolid = true;
      }
      else {
        trace->allsolid = false;
        if (iVar10 == -1) goto LAB_000cb686;
        trace->inwater = true;
      }
    }
    else if (hull->firstclipnode < hull->lastclipnode) {
      qVar9 = PM_RecursiveHullCheck(hull,iVar10,p1f,p2f,local_38,local_28,trace);
      if (qVar9 == false) {
        return false;
      }
    }
    else {
      trace->allsolid = false;
LAB_000cb686:
      trace->inopen = true;
    }
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???] */
    iVar11 = hull->firstclipnode;
    bVar8 = local_40 >= 0.0;
    iVar10 = (int)pdVar1->children[bVar8];
    if (hull->lastclipnode <= iVar11) {
      if (-1 < iVar10) goto LAB_000cb618;
      goto LAB_000cb698;
    }
    if (-1 < iVar10) {
      do {
        if ((iVar10 < iVar11) || (hull->lastclipnode < iVar10)) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("PM_HullPointContents: bad node number");
        }
        pdVar3 = hull->clipnodes + iVar10;
        pmVar4 = hull->planes + pdVar3->planenum;
        if (pmVar4->type < 3) {
          if (local_28[pmVar4->type] - pmVar4->dist < 0.0) goto LAB_000cb3fb;
LAB_000cb39f:
          sVar6 = pdVar3->children[0];
        }
        else {
          if (0.0 <= (pmVar4->normal[2] * local_28[2] +
                     pmVar4->normal[1] * local_28[1] + pmVar4->normal[0] * local_28[0]) -
                     pmVar4->dist) goto LAB_000cb39f;
LAB_000cb3fb:
          sVar6 = pdVar3->children[1];
        }
        iVar10 = (int)sVar6;
        if (iVar10 < 0) {
          if (iVar10 == -2) goto LAB_000cb40c;
          iVar10 = (int)pdVar1->children[bVar8];
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
          if (iVar10 < 0) goto LAB_000cb698;
          if (hull->firstclipnode < hull->lastclipnode) {
            qVar9 = PM_RecursiveHullCheck(hull,iVar10,(float)local_28,(float)local_38,p1,p2,trace);
            return qVar9;
          }
          goto LAB_000cb618;
        }
        iVar11 = hull->firstclipnode;
      } while( true );
    }
    if (iVar10 == -2) {
LAB_000cb40c:
      if (trace->allsolid != false) {
        return false;
      }
      if (local_40 < 0.0) {
        (trace->plane).normal[0] = vec3_origin[0] - pmVar2->normal[0];
        (trace->plane).normal[1] = vec3_origin[1] - pmVar2->normal[1];
        (trace->plane).normal[2] = vec3_origin[2] - pmVar2->normal[2];
        (trace->plane).dist = -pmVar2->dist;
      }
      else {
        (trace->plane).normal[0] = pmVar2->normal[0];
        (trace->plane).normal[1] = pmVar2->normal[1];
        (trace->plane).normal[2] = pmVar2->normal[2];
        (trace->plane).dist = pmVar2->dist;
      }
      iVar10 = hull->firstclipnode;
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???] */
      if (iVar10 < hull->lastclipnode) {
        do {
          iVar11 = iVar10;
          if (-1 < iVar10) {
            do {
              if ((iVar11 < iVar10) || (hull->lastclipnode < iVar11)) {
                    /* WARNING: Subroutine does not return */
                Sys_Error("PM_HullPointContents: bad node number");
              }
              pdVar1 = hull->clipnodes + iVar11;
              pmVar2 = hull->planes + pdVar1->planenum;
              if (pmVar2->type < 3) {
                if (local_28[pmVar2->type] - pmVar2->dist < 0.0) goto LAB_000cb4fc;
LAB_000cb49f:
                sVar6 = pdVar1->children[0];
              }
              else {
                if (0.0 <= (pmVar2->normal[2] * local_28[2] +
                           pmVar2->normal[1] * local_28[1] + pmVar2->normal[0] * local_28[0]) -
                           pmVar2->dist) goto LAB_000cb49f;
LAB_000cb4fc:
                sVar6 = pdVar1->children[1];
              }
              iVar11 = (int)sVar6;
              if (iVar11 < 0) break;
              iVar10 = hull->firstclipnode;
            } while( true );
          }
          if (iVar11 != -2) break;
          local_44 = local_44 - 0.05;
          if (local_44 < 0.0) {
            trace->fraction = (float)local_38;
            trace->endpos[0] = local_28[0];
            trace->endpos[1] = local_28[1];
            trace->endpos[2] = local_28[2];
            Con_DPrintf("Trace backed up past 0.0.\n");
            return false;
          }
          iVar10 = hull->firstclipnode;
          local_38 = (vec_t *)(((float)p1 - p2f) * local_44 + p2f);
          local_28[0] = (*p2 - *(float *)p1f) * local_44 + *(float *)p1f;
          local_28[1] = (p2[1] - *(float *)((int)p1f + 4)) * local_44 + *(float *)((int)p1f + 4);
          local_28[2] = (p2[2] - *(float *)((int)p1f + 8)) * local_44 + *(float *)((int)p1f + 8);
        } while (iVar10 < hull->lastclipnode);
      }
      trace->fraction = (float)local_38;
      trace->endpos[0] = local_28[0];
      *(ulonglong *)(trace->endpos + 1) = CONCAT44(local_28[2],local_28[1]);
      return false;
    }
  }
  else {
    iVar10 = (int)pdVar1->children[0];
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
    if (-1 < iVar10) {
      if (hull->firstclipnode < hull->lastclipnode) {
        qVar9 = PM_RecursiveHullCheck(hull,iVar10,p1f,p2f,p1,p2,trace);
        return qVar9;
      }
LAB_000cb618:
      trace->allsolid = false;
      goto LAB_000cb622;
    }
LAB_000cb698:
    if (iVar10 == -2) {
      trace->startsolid = true;
      return true;
    }
  }
  trace->allsolid = false;
  if (iVar10 != -1) {
    trace->inwater = true;
    return true;
  }
LAB_000cb622:
  trace->inopen = true;
  return true;
}


// PM_RecursiveHullCheck  @ 000cda00
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


// PM_SV_PlaySound  @ 00104290
void PM_SV_PlaySound(int channel,char *sample,float volume,float attenuation,int fFlags,int pitch)

{
  SV_StartSound(1,host_client->edict,channel,sample,(int)(volume * 255.0),attenuation,fFlags,pitch);
  return;
}


// PM_SV_PlaybackEventFull  @ 00104270
void PM_SV_PlaybackEventFull
               (int flags,int clientindex,ushort eventindex,float delay,float *origin,float *angles,
               float fparam1,float fparam2,int iparam1,int iparam2,int bparam1,int bparam2)

{
  EV_SV_Playback(flags | 1,clientindex,eventindex,delay,origin,angles,fparam1,fparam2,iparam1,
                 iparam2,bparam1,bparam2);
  return;
}


// PM_SV_TraceTexture  @ 00104300
char * PM_SV_TraceTexture(int ground,vec_t *vstart,vec_t *vend)

{
  int iVar1;
  char *pcVar2;
  
                    /* Unresolved local var: physent_t * pe@[???]
                       Unresolved local var: edict_t * pent@[???] */
  if ((((-1 < ground) && (ground < pmove->numphysent)) &&
      (pmove->physents[ground].model != (model_s *)0x0)) &&
     (((iVar1 = pmove->physents[ground].info, -1 < iVar1 && (iVar1 < sv.max_edicts)) &&
      (sv.edicts + iVar1 != (edict_t *)0x0)))) {
    pcVar2 = TraceTexture(sv.edicts + iVar1,vstart,vend);
    return pcVar2;
  }
  return (char *)0x0;
}


// PM_StuckTouch  @ 000cab40
void PM_StuckTouch(int hitent,pmtrace_t *ptraceresult)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  playermove_t_conflict *ppVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  vec_t vVar8;
  vec_t vVar9;
  vec_t vVar10;
  int aiStack_50 [13];
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  
                    /* Unresolved local var: edict_t * info@[???]
                       Unresolved local var: int n@[???] */
  if (pmove->server == false) {
    return;
  }
  EDICT_NUM(pmove->physents[hitent].info);
  uVar5 = 0;
  do {
    *(undefined4 *)((int)aiStack_50 + uVar5) =
         *(undefined4 *)((int)ptraceresult->endpos + (uVar5 - 0x14));
    uVar5 = uVar5 + 4;
  } while (uVar5 < 0x44);
                    /* Unresolved local var: int i@[???] */
  iVar7 = pmove->numtouch;
  iVar2 = ptraceresult->ent;
  if (iVar7 < 1) {
    if (iVar7 == 0) {
      vVar10 = pmove->velocity[0];
      vVar9 = pmove->velocity[1];
      vVar8 = pmove->velocity[2];
LAB_000cabe4:
      ppVar4 = pmove;
      pmove->numtouch = iVar7 + 1;
      local_1c = vVar10;
      local_18 = vVar9;
      uVar5 = 0;
      local_14 = vVar8;
      aiStack_50[0xc] = iVar2;
      do {
        *(undefined4 *)((int)ppVar4->touchindex[iVar7].endpos + (uVar5 - 0x14)) =
             *(undefined4 *)((int)aiStack_50 + uVar5);
        uVar5 = uVar5 + 4;
      } while (uVar5 < 0x44);
    }
  }
  else {
    iVar6 = 0;
    iVar1 = pmove->touchindex[0].ent;
    piVar3 = &pmove->touchindex[1].ent;
    while (iVar2 != iVar1) {
      iVar6 = iVar6 + 1;
      if (iVar6 == iVar7) {
        vVar10 = pmove->velocity[0];
        vVar9 = pmove->velocity[1];
        vVar8 = pmove->velocity[2];
        if (599 < iVar7) {
          (*pmove->Con_DPrintf)("Too many entities were touched!\n");
          iVar7 = pmove->numtouch;
        }
        goto LAB_000cabe4;
      }
      iVar1 = *piVar3;
      piVar3 = piVar3 + 0x11;
    }
  }
  return;
}


// PM_TestPlayerPosition  @ 000cd650
int PM_TestPlayerPosition(vec_t *pos,pmtrace_t *ptrace)

{
  int iVar1;
  
  iVar1 = _PM_TestPlayerPosition(pos,ptrace,(_func_int_physent_t_ptr *)0x0);
  return iVar1;
}


// PM_TestPlayerPositionEx  @ 000cd680
int PM_TestPlayerPositionEx(vec_t *pos,pmtrace_t *ptrace,_func_int_physent_t_ptr *pfnIgnore)

{
  dclipnode_t *pdVar1;
  mplane_t *pmVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  short sVar6;
  model_s *pmVar7;
  model_t *pModel;
  uint uVar8;
  int iVar9;
  playermove_t_conflict *ppVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  hull_t *phVar14;
  playermove_t_conflict *ppVar15;
  int iVar16;
  int iStack_cc;
  float afStack_c8 [4];
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  undefined4 auStack_a4 [17];
  pmtrace_t pStack_60;
  
  _PM_PlayerTrace(&pStack_60,pmove->origin,pmove->origin,0,pmove->numphysent,pmove->physents,-1,
                  (_func_int_physent_t_ptr *)0x0);
  uVar8 = 0;
  do {
    *(undefined4 *)((int)auStack_a4 + uVar8) =
         *(undefined4 *)((int)pStack_60.endpos + (uVar8 - 0x14));
    uVar8 = uVar8 + 4;
  } while (uVar8 < 0x44);
  if (ptrace != (pmtrace_t *)0x0) {
    uVar8 = 0;
    do {
      *(undefined4 *)((int)ptrace->endpos + (uVar8 - 0x14)) =
           *(undefined4 *)((int)auStack_a4 + uVar8);
      uVar8 = uVar8 + 4;
    } while (uVar8 < 0x44);
  }
  iVar12 = 0;
  ppVar15 = pmove;
  if (0 < pmove->numphysent) {
    do {
      ppVar10 = ppVar15;
      if ((pfnIgnore == (_func_int_physent_t_ptr *)0x0) ||
         (iVar9 = (*pfnIgnore)(ppVar15->physents + iVar12), ppVar10 = pmove, iVar9 == 0)) {
        pmVar7 = ppVar15->physents[iVar12].model;
        if (pmVar7 == (model_s *)0x0) {
          pModel = ppVar15->physents[iVar12].studiomodel;
          fVar3 = ppVar15->physents[iVar12].origin[0];
          fVar4 = ppVar15->physents[iVar12].origin[1];
          fVar5 = ppVar15->physents[iVar12].origin[2];
          iStack_cc = 1;
          if ((pModel == (model_t *)0x0) || (pModel->type != mod_studio)) {
            iVar9 = ppVar10->usehull;
          }
          else {
            iVar9 = ppVar10->usehull;
            if (((pModel->flags & 0x200) != 0) || (iVar9 == 2)) {
              pStack_60.allsolid = (qboolean)(player_maxs[iVar9][0] - player_mins[iVar9][0]);
              iVar11 = ppVar15->physents[iVar12].sequence;
              fVar3 = ppVar15->physents[iVar12].frame;
              pStack_60.startsolid = (qboolean)(player_maxs[iVar9][1] - player_mins[iVar9][1]);
              pStack_60.inopen = (qboolean)(player_maxs[iVar9][2] - player_mins[iVar9][2]);
              VectorScale((vec_t *)&pStack_60,0.5,(vec_t *)&pStack_60);
              phVar14 = R_StudioHull(pModel,fVar3,iVar11,ppVar15->physents[iVar12].angles,
                                     ppVar15->physents[iVar12].origin,(vec_t *)&pStack_60,
                                     ppVar15->physents[iVar12].controller,
                                     ppVar15->physents[iVar12].blending,&iStack_cc,(edict_t *)0x0,0)
              ;
              iVar11 = ppVar15->physents[iVar12].solid;
              fVar5 = 0.0;
              fVar4 = 0.0;
              fVar3 = 0.0;
              goto LAB_000cd157;
            }
          }
          phVar14 = &box_hull;
          iVar11 = ppVar15->physents[iVar12].solid;
          box_planes[1].dist = ppVar15->physents[iVar12].mins[0] - player_maxs[iVar9][0];
          box_planes[3].dist = ppVar15->physents[iVar12].mins[1] - player_maxs[iVar9][1];
          box_planes[5].dist = ppVar15->physents[iVar12].mins[2] - player_maxs[iVar9][2];
          box_planes[2].dist = ppVar15->physents[iVar12].maxs[1] - player_mins[iVar9][1];
          box_planes[4].dist = ppVar15->physents[iVar12].maxs[2] - player_mins[iVar9][2];
          box_planes[0].dist = ppVar15->physents[iVar12].maxs[0] - player_mins[iVar9][0];
        }
        else {
          iVar11 = ppVar15->physents[iVar12].solid;
          if ((iVar11 == 0) && (ppVar15->physents[iVar12].skin != 0)) goto LAB_000cd0b0;
          iStack_cc = 1;
          iVar9 = ppVar10->usehull;
          if (iVar9 == 2) {
            phVar14 = pmVar7->hulls;
          }
          else if (iVar9 == 3) {
            phVar14 = pmVar7->hulls + 2;
          }
          else {
            phVar14 = pmVar7->hulls + 1;
            if (iVar9 == 1) {
              phVar14 = pmVar7->hulls + 3;
            }
          }
          fVar3 = (phVar14->clip_mins[0] - player_mins[iVar9][0]) +
                  ppVar15->physents[iVar12].origin[0];
          fVar4 = (phVar14->clip_mins[1] - player_mins[iVar9][1]) +
                  ppVar15->physents[iVar12].origin[1];
          fVar5 = (phVar14->clip_mins[2] - player_mins[iVar9][2]) +
                  ppVar15->physents[iVar12].origin[2];
        }
LAB_000cd157:
        fVar3 = *pos - fVar3;
        fVar4 = pos[1] - fVar4;
        afStack_c8[0] = fVar3;
        fVar5 = pos[2] - fVar5;
        afStack_c8[1] = fVar4;
        afStack_c8[2] = fVar5;
        ppVar10 = pmove;
        if ((iVar11 == 4) &&
           (((ppVar15->physents[iVar12].angles[0] != 0.0 ||
             (ppVar15->physents[iVar12].angles[1] != 0.0)) ||
            (ppVar15->physents[iVar12].angles[2] != 0.0)))) {
          AngleVectors(ppVar15->physents[iVar12].angles,afStack_c8 + 3,&fStack_b0,
                       (vec_t *)&pStack_60);
          afStack_c8[0] = fStack_b4 * fVar5 + fStack_b8 * fVar4 + afStack_c8[3] * fVar3;
          afStack_c8[1] = -(fStack_a8 * fVar5 + fStack_ac * fVar4 + fStack_b0 * fVar3);
          afStack_c8[2] =
               fVar3 * (float)pStack_60.allsolid + (float)pStack_60.startsolid * fVar4 +
               (float)pStack_60.inopen * fVar5;
          ppVar10 = pmove;
        }
        pmove = ppVar10;
        if (iStack_cc == 1) {
          iVar9 = phVar14->firstclipnode;
          if (iVar9 < phVar14->lastclipnode) {
            iVar11 = iVar9;
            if (-1 < iVar9) {
              do {
                if ((iVar11 < iVar9) || (phVar14->lastclipnode < iVar11)) {
                    /* WARNING: Subroutine does not return */
                  Sys_Error("PM_HullPointContents: bad node number");
                }
                pdVar1 = phVar14->clipnodes + iVar11;
                pmVar2 = phVar14->planes + pdVar1->planenum;
                if (pmVar2->type < 3) {
                  if (0.0 <= afStack_c8[pmVar2->type] - pmVar2->dist) goto LAB_000cd495;
LAB_000cd4f5:
                  sVar6 = pdVar1->children[1];
                }
                else {
                  if ((afStack_c8[2] * pmVar2->normal[2] +
                      afStack_c8[1] * pmVar2->normal[1] + afStack_c8[0] * pmVar2->normal[0]) -
                      pmVar2->dist < 0.0) goto LAB_000cd4f5;
LAB_000cd495:
                  sVar6 = pdVar1->children[0];
                }
                iVar11 = (int)sVar6;
                if (iVar11 < 0) break;
                iVar9 = phVar14->firstclipnode;
              } while( true );
            }
            if (iVar11 == -2) {
              return iVar12;
            }
          }
        }
        else {
          piVar13 = &phVar14->firstclipnode;
          iVar9 = 0;
          if (0 < iStack_cc) {
            do {
              iVar11 = *piVar13;
              if (iVar11 < piVar13[1]) {
                iVar16 = iVar11;
                if (-1 < iVar11) {
                  do {
                    if ((iVar16 < iVar11) || (piVar13[1] < iVar16)) {
                    /* WARNING: Subroutine does not return */
                      Sys_Error("PM_HullPointContents: bad node number");
                    }
                    pdVar1 = ((hull_t *)(piVar13 + -2))->clipnodes + iVar16;
                    pmVar2 = (mplane_t *)piVar13[-1] + pdVar1->planenum;
                    if (pmVar2->type < 3) {
                      if (0.0 <= afStack_c8[pmVar2->type] - pmVar2->dist) goto LAB_000cd1e7;
LAB_000cd243:
                      sVar6 = pdVar1->children[1];
                    }
                    else {
                      if ((afStack_c8[2] * pmVar2->normal[2] +
                          afStack_c8[1] * pmVar2->normal[1] + afStack_c8[0] * pmVar2->normal[0]) -
                          pmVar2->dist < 0.0) goto LAB_000cd243;
LAB_000cd1e7:
                      sVar6 = pdVar1->children[0];
                    }
                    iVar16 = (int)sVar6;
                    if (iVar16 < 0) break;
                    iVar11 = *piVar13;
                  } while( true );
                }
                if (iVar16 == -2) {
                  return iVar12;
                }
              }
              iVar9 = iVar9 + 1;
              piVar13 = piVar13 + 10;
            } while (iVar9 < iStack_cc);
          }
        }
      }
LAB_000cd0b0:
      iVar12 = iVar12 + 1;
      ppVar15 = ppVar10;
    } while (iVar12 < ppVar10->numphysent);
  }
  return -1;
}


// PM_TraceLine  @ 000cd750
pmtrace_s * PM_TraceLine(float *start,float *end,int flags,int usehull,int ignore_pe)

{
  int iVar1;
  playermove_t_conflict *ppVar2;
  uint uVar3;
  uint uVar4;
  pmtrace_t local_5c;
  
                    /* Unresolved local var: int oldhull@[???] */
  (*g_engdstAddrs.PM_TraceLine)(&start,&end,&flags,&usehull,&ignore_pe);
  ppVar2 = pmove;
  iVar1 = pmove->usehull;
  pmove->usehull = usehull;
  if (flags == 0) {
    _PM_PlayerTrace(&local_5c,start,end,0,ppVar2->numphysent,ppVar2->physents,ignore_pe,
                    (_func_int_physent_t_ptr *)0x0);
    uVar3 = 0;
    do {
      uVar4 = uVar3 + 4;
      *(undefined4 *)((int)PM_TraceLine::tr.endpos + (uVar3 - 0x14)) =
           *(undefined4 *)((int)local_5c.endpos + (uVar3 - 0x14));
      uVar3 = uVar4;
      ppVar2 = pmove;
    } while (uVar4 < 0x44);
  }
  else if (flags == 1) {
    _PM_PlayerTrace(&local_5c,start,end,0,ppVar2->numvisent,ppVar2->visents,ignore_pe,
                    (_func_int_physent_t_ptr *)0x0);
    uVar3 = 0;
    do {
      uVar4 = uVar3 + 4;
      *(undefined4 *)((int)PM_TraceLine::tr.endpos + (uVar3 - 0x14)) =
           *(undefined4 *)((int)local_5c.endpos + (uVar3 - 0x14));
      uVar3 = uVar4;
      ppVar2 = pmove;
    } while (uVar4 < 0x44);
  }
  ppVar2->usehull = iVar1;
  return &PM_TraceLine::tr;
}


// PM_TraceLineEx  @ 000cd8b0
pmtrace_s *
PM_TraceLineEx(float *start,float *end,int flags,int usehull,_func_int_physent_t_ptr *pfnIgnore)

{
  int iVar1;
  playermove_t_conflict *ppVar2;
  uint uVar3;
  uint uVar4;
  pmtrace_t local_ec;
  pmtrace_t local_94;
  undefined4 auStack_50 [17];
  
                    /* Unresolved local var: int oldhull@[???] */
  ppVar2 = pmove;
  iVar1 = pmove->usehull;
  pmove->usehull = usehull;
  if (flags == 0) {
                    /* Unresolved local var: pmtrace_t tr@[???] */
    _PM_PlayerTrace(&local_94,start,end,0,ppVar2->numphysent,ppVar2->physents,-1,pfnIgnore);
    uVar4 = 0;
    do {
      *(undefined4 *)((int)auStack_50 + uVar4) =
           *(undefined4 *)((int)local_94.endpos + (uVar4 - 0x14));
      uVar4 = uVar4 + 4;
    } while (uVar4 < 0x44);
    uVar4 = 0;
    do {
      uVar3 = uVar4 + 4;
      *(undefined4 *)((int)PM_TraceLineEx::tr.endpos + (uVar4 - 0x14)) =
           *(undefined4 *)((int)auStack_50 + uVar4);
      uVar4 = uVar3;
    } while (uVar3 < 0x44);
  }
  else {
    _PM_PlayerTrace(&local_ec,start,end,0,ppVar2->numvisent,ppVar2->visents,-1,pfnIgnore);
    uVar4 = 0;
    do {
      uVar3 = uVar4 + 4;
      *(undefined4 *)((int)PM_TraceLineEx::tr.endpos + (uVar4 - 0x14)) =
           *(undefined4 *)((int)local_ec.endpos + (uVar4 - 0x14));
      uVar4 = uVar3;
    } while (uVar3 < 0x44);
  }
  pmove->usehull = iVar1;
  return &PM_TraceLineEx::tr;
}


// PM_TraceModel  @ 000cb7d0
float PM_TraceModel(physent_t *pEnt,vec_t *start,vec_t *end,trace_t *trace)

{
  int iVar1;
  model_s *pmVar2;
  playermove_t_conflict *ppVar3;
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
  ppVar3 = pmove;
  iVar1 = pmove->usehull;
  pmove->usehull = 2;
                    /* Unresolved local var: hull_t * hull@[???] */
  pmVar2 = pEnt->model;
  local_28 = (pmVar2->hulls[0].clip_mins[0] - player_mins[2][0]) + pEnt->origin[0];
  local_24 = (pmVar2->hulls[0].clip_mins[1] - player_mins[2][1]) + pEnt->origin[1];
  local_20 = (pmVar2->hulls[0].clip_mins[2] - player_mins[2][2]) + pEnt->origin[2];
  ppVar3->usehull = iVar1;
  local_34 = *start - local_28;
  local_30 = start[1] - local_24;
  local_2c = start[2] - local_20;
  local_28 = *end - local_28;
  local_24 = end[1] - local_24;
  local_20 = end[2] - local_20;
  SV_RecursiveHullCheck
            (pmVar2->hulls,pmVar2->hulls[0].firstclipnode,0.0,1.0,&local_34,&local_28,trace);
  trace->ent = (edict_t *)0x0;
  return trace->fraction;
}


// PM_TruePointContents  @ 000cc300
int PM_TruePointContents(vec_t *p)

{
  dclipnode_t *pdVar1;
  mplane_t *pmVar2;
  short sVar3;
  model_s *pmVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: hull_t * hull@[???] */
  pmVar4 = pmove->physents[0].model;
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???] */
  if ((pmVar4 == (model_s *)0xffffff30) ||
     (iVar5 = pmVar4->hulls[0].firstclipnode, pmVar4->hulls[0].lastclipnode <= iVar5)) {
    iVar5 = -1;
  }
  else {
    iVar6 = iVar5;
    if (-1 < iVar5) {
      do {
        if ((iVar6 < iVar5) || (pmVar4->hulls[0].lastclipnode < iVar6)) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("PM_HullPointContents: bad node number");
        }
        pdVar1 = pmVar4->hulls[0].clipnodes + iVar6;
        pmVar2 = pmVar4->hulls[0].planes + pdVar1->planenum;
        if (pmVar2->type < 3) {
          if (p[pmVar2->type] - pmVar2->dist < 0.0) goto LAB_000cc3b3;
LAB_000cc34e:
          sVar3 = pdVar1->children[0];
        }
        else {
          if (0.0 <= (pmVar2->normal[2] * p[2] + pmVar2->normal[1] * p[1] + pmVar2->normal[0] * *p)
                     - pmVar2->dist) goto LAB_000cc34e;
LAB_000cc3b3:
          sVar3 = pdVar1->children[1];
        }
        iVar6 = (int)sVar3;
        if (iVar6 < 0) {
          return iVar6;
        }
        iVar5 = pmVar4->hulls[0].firstclipnode;
      } while( true );
    }
  }
  return iVar5;
}


// PM_WaterEntity  @ 000cc050
/* WARNING: Type propagation algorithm not settling */

int PM_WaterEntity(vec_t *p)

{
  dclipnode_t *pdVar1;
  mplane_t *pmVar2;
  short sVar3;
  model_s *pmVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_30;
  float local_28 [6];
  
                    /* Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: int num@[???]
                       Unresolved local var: int entityIndex@[???]
                       Unresolved local var: int cont@[???] */
  (*g_engdstAddrs.PM_WaterEntity)(&p);
  pmVar4 = pmove->physents[0].model;
  iVar5 = pmVar4->hulls[0].firstclipnode;
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???] */
  if (iVar5 < pmVar4->hulls[0].lastclipnode) {
    iVar7 = iVar5;
    if (-1 < iVar5) {
      do {
        if ((iVar7 < iVar5) || (pmVar4->hulls[0].lastclipnode < iVar7)) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("PM_HullPointContents: bad node number");
        }
        pdVar1 = pmVar4->hulls[0].clipnodes + iVar7;
        pmVar2 = pmVar4->hulls[0].planes + pdVar1->planenum;
        if (pmVar2->type < 3) {
          if (p[pmVar2->type] - pmVar2->dist < 0.0) goto LAB_000cc10b;
LAB_000cc0a6:
          sVar3 = pdVar1->children[0];
        }
        else {
          if (0.0 <= (pmVar2->normal[2] * p[2] + pmVar2->normal[1] * p[1] + pmVar2->normal[0] * *p)
                     - pmVar2->dist) goto LAB_000cc0a6;
LAB_000cc10b:
          sVar3 = pdVar1->children[1];
        }
        iVar7 = (int)sVar3;
        if (iVar7 < 0) break;
        iVar5 = pmVar4->hulls[0].firstclipnode;
      } while( true );
    }
    if (iVar7 < -2) {
      local_30 = 0;
    }
    else {
      local_30 = -1;
      if (iVar7 == -2) {
        return -1;
      }
    }
  }
  else {
    local_30 = -1;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: physent_t * pe@[???]
                       Unresolved local var: vec3_t test@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: int num@[???]
                       Unresolved local var: int cont@[???] */
  iVar5 = pmove->numphysent;
  if (1 < iVar5) {
    iVar7 = 1;
    do {
      while ((pmove->physents[iVar7].solid == 0 &&
             (pmVar4 = pmove->physents[iVar7].model, pmVar4 != (model_s *)0x0))) {
        local_28[0] = *p - pmove->physents[iVar7].origin[0];
        iVar5 = pmVar4->hulls[0].firstclipnode;
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???] */
        local_28[1] = p[1] - pmove->physents[iVar7].origin[1];
        local_28[2] = p[2] - pmove->physents[iVar7].origin[2];
        if (pmVar4->hulls[0].lastclipnode <= iVar5) {
          iVar5 = pmove->numphysent;
          break;
        }
        iVar6 = iVar5;
        if (-1 < iVar5) {
          do {
            if ((iVar6 < iVar5) || (pmVar4->hulls[0].lastclipnode < iVar6)) {
                    /* WARNING: Subroutine does not return */
              Sys_Error("PM_HullPointContents: bad node number");
            }
            pdVar1 = pmVar4->hulls[0].clipnodes + iVar6;
            pmVar2 = pmVar4->hulls[0].planes + pdVar1->planenum;
            if (pmVar2->type < 3) {
              if (local_28[pmVar2->type] - pmVar2->dist < 0.0) goto LAB_000cc258;
LAB_000cc1ef:
              sVar3 = pdVar1->children[0];
            }
            else {
              if (0.0 <= (local_28[2] * pmVar2->normal[2] +
                         local_28[1] * pmVar2->normal[1] + local_28[0] * pmVar2->normal[0]) -
                         pmVar2->dist) goto LAB_000cc1ef;
LAB_000cc258:
              sVar3 = pdVar1->children[1];
            }
            iVar6 = (int)sVar3;
            if (iVar6 < 0) break;
            iVar5 = pmVar4->hulls[0].firstclipnode;
          } while( true );
        }
        if (iVar6 != -1) {
          return pmove->physents[iVar7].info;
        }
        iVar7 = iVar7 + 1;
        iVar5 = pmove->numphysent;
        if (iVar5 <= iVar7) {
          return local_30;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar5);
  }
  return local_30;
}


