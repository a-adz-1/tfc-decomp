// PM_AddToTouched  @ 00088d90
qboolean PM_AddToTouched(pmtrace_t tr,vec_t *impactvelocity)

{
  int iVar1;
  playermove_t *ppVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  vec_t vVar7;
  int *piVar8;
  vec_t vVar9;
  vec_t local_20;
  
                    /* Unresolved local var: int i@[???] */
  iVar3 = tr.ent;
  iVar6 = pmove->numtouch;
  if (iVar6 < 1) {
    if (iVar6 != 0) {
      return false;
    }
    local_20 = impactvelocity[2];
    vVar7 = *impactvelocity;
    vVar9 = impactvelocity[1];
  }
  else {
    iVar4 = 0;
    piVar8 = &pmove->touchindex[1].ent;
    if (pmove->touchindex[0].ent == tr.ent) {
      return false;
    }
    while (iVar4 = iVar4 + 1, iVar4 != iVar6) {
      iVar1 = *piVar8;
      piVar8 = piVar8 + 0x11;
      if (iVar1 == tr.ent) {
        return false;
      }
    }
    local_20 = impactvelocity[2];
    vVar7 = *impactvelocity;
    vVar9 = impactvelocity[1];
    if (599 < iVar6) {
      (*pmove->Con_DPrintf)("Too many entities were touched!\n");
      iVar6 = pmove->numtouch;
    }
  }
  ppVar2 = pmove;
  uVar5 = 0;
  do {
    *(undefined4 *)((int)ppVar2->touchindex[iVar6].endpos + (uVar5 - 0x14)) =
         *(undefined4 *)((int)tr.endpos + (uVar5 - 0x14));
    uVar5 = uVar5 + 4;
  } while (uVar5 < 0x44);
  ppVar2->touchindex[iVar6].ent = iVar3;
  ppVar2->touchindex[iVar6].deltavelocity[0] = vVar7;
  ppVar2->touchindex[iVar6].deltavelocity[1] = vVar9;
  ppVar2->touchindex[iVar6].deltavelocity[2] = local_20;
  ppVar2->numtouch = iVar6 + 1;
  return true;
}


// PM_GetModelBounds  @ 000890c0
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


// PM_GetModelType  @ 00089100
int PM_GetModelType(model_s *mod)

{
  return mod->type;
}


// PM_HullForBox  @ 00089260
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


// PM_HullForBsp  @ 0008a600
hull_t * PM_HullForBsp(physent_t *pe,vec_t *offset)

{
  int iVar1;
  model_s *pmVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  playermove_t *ppVar6;
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


// PM_HullForStudioModel  @ 00089bb0
hull_t * PM_HullForStudioModel
                   (model_t *pModel,vec_t *offset,float frame,int sequence,vec_t *angles,
                   vec_t *origin,uchar *pcontroller,uchar *pblending,int *pNumHulls)

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


// PM_HullPointContents  @ 000892b0
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
          if (0.0 <= p[pmVar2->type] - pmVar2->dist) goto LAB_00089341;
LAB_000892e9:
          sVar3 = pdVar1->children[1];
        }
        else {
          if ((pmVar2->normal[2] * p[2] + pmVar2->normal[1] * p[1] + pmVar2->normal[0] * *p) -
              pmVar2->dist < 0.0) goto LAB_000892e9;
LAB_00089341:
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


// PM_Init  @ 00088f00
void PM_Init(playermove_t *ppm)

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


// PM_InitBoxHull  @ 00089110
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


// PM_LinkContents  @ 00089950
int PM_LinkContents(vec_t *p,int *pIndex)

{
  model_s *pmVar1;
  int iVar2;
  playermove_t *ppVar3;
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


// PM_PlayerTrace  @ 0008b680
pmtrace_t *
PM_PlayerTrace(pmtrace_t *__return_storage_ptr__,vec_t *start,vec_t *end,int traceFlags,
              int ignore_pe)

{
                    /* Unresolved local var: pmtrace_t tr@[???] */
  _PM_PlayerTrace(__return_storage_ptr__,start,end,traceFlags,pmove->numphysent,pmove->physents,
                  ignore_pe,(_func_int_physent_t_ptr *)0x0);
  return __return_storage_ptr__;
}


// PM_PlayerTraceEx  @ 0008b6e0
pmtrace_t *
PM_PlayerTraceEx(pmtrace_t *__return_storage_ptr__,vec_t *start,vec_t *end,int traceFlags,
                _func_int_physent_t_ptr *pfnIgnore)

{
                    /* Unresolved local var: pmtrace_t tr@[???] */
  _PM_PlayerTrace(__return_storage_ptr__,start,end,traceFlags,pmove->numphysent,pmove->physents,-1,
                  pfnIgnore);
  return __return_storage_ptr__;
}


// PM_PointContents  @ 00089a30
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


// PM_RecursiveHullCheck  @ 00089360
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
LAB_00089758:
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
    goto LAB_000897bf;
  }
  if (0.0 <= fVar3) {
    fVar5 = fVar3 - 0.03125;
LAB_000893de:
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
LAB_000897d2:
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
      goto LAB_000893de;
    }
    iVar9 = (int)pdVar8->children[1];
    if (iVar9 < 0) goto LAB_000897d2;
    if (hull->firstclipnode < hull->lastclipnode) goto LAB_00089758;
  }
  trace->allsolid = false;
LAB_000897bf:
  trace->inopen = true;
  return true;
}


// PM_RecursiveHullCheck  @ 0008b990
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


// PM_SV_PlaySound  @ 000b1710
void PM_SV_PlaySound(int channel,char *sample,float volume,float attenuation,int fFlags,int pitch)

{
  SV_StartSound(1,host_client->edict,channel,sample,(int)(volume * 255.0),attenuation,fFlags,pitch);
  return;
}


// PM_SV_PlaybackEventFull  @ 000b16f0
void PM_SV_PlaybackEventFull
               (int flags,int clientindex,ushort eventindex,float delay,float *origin,float *angles,
               float fparam1,float fparam2,int iparam1,int iparam2,int bparam1,int bparam2)

{
  EV_SV_Playback(flags | 1,clientindex,eventindex,delay,origin,angles,fparam1,fparam2,iparam1,
                 iparam2,bparam1,bparam2);
  return;
}


// PM_SV_TraceTexture  @ 000b1780
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


// PM_StuckTouch  @ 00088ea0
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


// PM_TestPlayerPosition  @ 0008ac40
int PM_TestPlayerPosition(vec_t *pos,pmtrace_t *ptrace)

{
  int iVar1;
  
  iVar1 = _PM_TestPlayerPosition(pos,ptrace,(_func_int_physent_t_ptr *)0x0);
  return iVar1;
}


// PM_TestPlayerPositionEx  @ 0008ac70
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
            goto LAB_0008a8f9;
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
          if ((pe->solid == 0) && (pe->skin != 0)) goto LAB_0008a9a0;
          vStack_5c = pe->origin[0];
          aiStack_2c[0] = 1;
          vStack_58 = pe->origin[1];
          vStack_54 = pe->origin[2];
          hull = PM_HullForBsp(pe,&vStack_5c);
        }
LAB_0008a8f9:
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
LAB_0008a9a0:
      iStack_104 = iStack_104 + 1;
    } while (iStack_104 < pmove->numphysent);
  }
  return -1;
}


// PM_TraceLine  @ 0008b740
pmtrace_s * PM_TraceLine(float *start,float *end,int flags,int usehull,int ignore_pe)

{
  int iVar1;
  playermove_t *ppVar2;
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


// PM_TraceLineEx  @ 0008b880
pmtrace_s *
PM_TraceLineEx(float *start,float *end,int flags,int usehull,_func_int_physent_t_ptr *pfnIgnore)

{
  int iVar1;
  playermove_t *ppVar2;
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


// PM_TraceModel  @ 0008a6c0
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


// PM_TruePointContents  @ 00089b60
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


// PM_WaterEntity  @ 00089ae0
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


