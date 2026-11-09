// studioapi_GL_SetRenderMode  @ 000d6e80
void studioapi_GL_SetRenderMode(int rendermode)

{
  if (rendermode != 0) {
    if (rendermode == 1) {
      (*qglBlendFunc)(0x302,0x303);
      (*qglTexEnvi)(0x2300,0x2200,0x1906);
    }
    else if (rendermode == 5) {
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
                    /* WARNING: Could not recover jumptable at 0x000d6f15. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglEnable)(0xbe2);
    return;
  }
  return;
}


// studioapi_GL_StudioDrawShadow  @ 000e2da0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void studioapi_GL_StudioDrawShadow(void)

{
  float fVar1;
  
  (*qglDepthMask)('\x01');
  if (((r_shadows.value != 0.0) && (g_rendermode != 5)) && ((r_model->flags & 0x100) == 0)) {
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
    return;
  }
  return;
}


// studioapi_GetAliasScale  @ 000d6360
void studioapi_GetAliasScale(float *x,float *y)

{
  *y = 1.0;
  *x = 1.0;
  return;
}


// studioapi_GetChromeSprite  @ 000d6330
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

model_t * studioapi_GetChromeSprite(void)

{
  return cl_sprite_shell;
}


// studioapi_GetCurrentEntity  @ 000d6090
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

cl_entity_t * studioapi_GetCurrentEntity(void)

{
  return currententity;
}


// studioapi_GetCvar  @ 000d6e30
cvar_s * studioapi_GetCvar(char *name)

{
  cvar_s *pcVar1;
  int iVar2;
  
  (*g_engdstAddrs.pfnGetCvarPointer)(&name);
                    /* Unresolved local var: cvar_t * retval@[???] */
  pcVar1 = cvar_vars;
  while( true ) {
    if (pcVar1 == (cvar_t *)0x0) {
      return (cvar_s *)0x0;
    }
    iVar2 = Q_stricmp(name,pcVar1->name);
    if (iVar2 == 0) break;
    pcVar1 = pcVar1->next;
  }
  return pcVar1;
}


// studioapi_GetForceFaceFlags  @ 000d6390
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int studioapi_GetForceFaceFlags(void)

{
  return g_ForcedFaceFlags;
}


// studioapi_GetModelByIndex  @ 000d6410
model_t * studioapi_GetModelByIndex(int index)

{
  model_t *mod;
  double dVar1;
  double dVar2;
  
  if (index < 0x200) {
    mod = cl.model_precache[index];
    if (mod != (model_t *)0x0) {
      if (1 < mod->needload - true) {
        return mod;
      }
      if (fs_precache_timings.value != 0.0) {
        dVar1 = Sys_FloatTime();
        Mod_LoadModel(mod,false,false);
        dVar2 = Sys_FloatTime();
        Con_DPrintf("fs_precache_timings: loaded model %s in time %.3f sec\n",mod,
                    (double)(float)((longdouble)dVar2 - (longdouble)dVar1));
        return cl.model_precache[index];
      }
      Mod_LoadModel(mod,false,false);
      return cl.model_precache[index];
    }
  }
  return (model_t *)0x0;
}


// studioapi_GetModelCounters  @ 000d6340
void studioapi_GetModelCounters(int **s,int **a)

{
  *s = &r_smodels_total;
  *a = &r_amodels_drawn;
  return;
}


// studioapi_GetPlayerState  @ 000d60d0
entity_state_t * studioapi_GetPlayerState(int index)

{
  if ((-1 < index) && (index < cl.maxclients)) {
    return (entity_state_t *)(cl.parsecountmod * 0x4318 + 0xc6aa3c + index * 0x154);
  }
  return (entity_state_t *)0x0;
}


// studioapi_GetTimes  @ 000d6120
void studioapi_GetTimes(int *framecount,double *cl_time,double *cl_oldtime)

{
  *framecount = r_framecount;
  *cl_time = cl.time;
  *cl_oldtime = cl.oldtime;
  return;
}


// studioapi_GetViewEntity  @ 000d6110
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

cl_entity_t * studioapi_GetViewEntity(void)

{
  return &cl.viewent;
}


// studioapi_GetViewInfo  @ 000d6280
void studioapi_GetViewInfo(float *origin,float *upv,float *rightv,float *vpnv)

{
  *origin = r_origin[0];
  origin[1] = r_origin[1];
  origin[2] = r_origin[2];
  *upv = vup[0];
  upv[1] = vup[1];
  upv[2] = vup[2];
  *rightv = vright[0];
  rightv[1] = vright[1];
  rightv[2] = vright[2];
  *vpnv = vpn[0];
  vpnv[1] = vpn[1];
  vpnv[2] = vpn[2];
  return;
}


// studioapi_PlayerInfo  @ 000d60a0
player_info_t * studioapi_PlayerInfo(int index)

{
  if ((-1 < index) && (index < cl.maxclients)) {
    return cl.players + index;
  }
  return (player_info_t *)0x0;
}


// studioapi_RenderShadow  @ 000d6fc0
void studioapi_RenderShadow(int iSprite,float *p1,float *p2,float *p3,float *p4)

{
  model_t *pmVar1;
  int iVar2;
  
                    /* Unresolved local var: model_t * sprite@[???]
                       Unresolved local var: float[4] color@[???] */
  if ((0 < iSprite) && (iSprite < cl.model_precache_count)) {
    pmVar1 = CL_GetModelByIndex(iSprite);
    if (pmVar1 != (model_t *)0x0) {
      iVar2 = (*tri.SpriteTexture)(pmVar1,0);
      if (iVar2 != 0) {
                    /* Unresolved local var: model_t * sprite@[???]
                       Unresolved local var: float[4] color@[???] */
        (*tri.RenderMode)(4);
        (*tri.Color4f)(0.0,0.0,0.0,1.0);
        (*tri.Begin)(2);
        (*tri.TexCoord2f)(0.0,0.0);
        (*tri.Vertex3fv)(p1);
        (*tri.TexCoord2f)(0.0,1.0);
        (*tri.Vertex3fv)(p2);
        (*tri.TexCoord2f)(1.0,1.0);
        (*tri.Vertex3fv)(p3);
        (*tri.TexCoord2f)(1.0,0.0);
        (*tri.Vertex3fv)(p4);
        (*tri.End)();
                    /* WARNING: Could not recover jumptable at 0x000d7105. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*tri.RenderMode)(0);
        return;
      }
    }
  }
  return;
}


// studioapi_RestoreRenderer  @ 000d6160
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void studioapi_RestoreRenderer(void)

{
  if (g_rendermode != 0) {
    (*qglDisable)(0xbe2);
  }
  (*qglTexEnvf)(0x2300,0x2200,7681.0);
  (*qglShadeModel)(0x1d00);
  if (gl_affinemodels.value != 0.0) {
    (*qglHint)(0xc50,0x1102);
                    /* WARNING: Could not recover jumptable at 0x000d61d1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglPopMatrix)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000d61ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglPopMatrix)();
  return;
}


// studioapi_SetBackFaceCull  @ 000d6150
void studioapi_SetBackFaceCull(int iCull)

{
  g_iBackFaceCull = iCull;
  return;
}


// studioapi_SetChromeOrigin  @ 000d6200
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void studioapi_SetChromeOrigin(void)

{
  g_ChromeOrigin[0] = r_origin[0];
  g_ChromeOrigin[1] = r_origin[1];
  g_ChromeOrigin[2] = r_origin[2];
  return;
}


// studioapi_SetForceFaceFlags  @ 000d63a0
void studioapi_SetForceFaceFlags(int flags)

{
  g_ForcedFaceFlags = flags;
  return;
}


// studioapi_SetRenderModel  @ 000d63c0
void studioapi_SetRenderModel(model_s *model)

{
  r_model = model;
  return;
}


// studioapi_SetupModel  @ 000d85f0
void studioapi_SetupModel(int bodypart,void **ppbodypart,void **ppsubmodel)

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
  *ppbodypart = &pbodypart;
  *ppsubmodel = &psubmodel;
  return;
}


// studioapi_SetupPlayerModel  @ 000d8690
model_t * studioapi_SetupPlayerModel(int playerindex)

{
  char *s2;
  skin_t (*pasVar1) [11];
  int iVar2;
  cl_entity_t *pcVar3;
  qboolean qVar4;
  int iVar5;
  model_t *pmVar6;
  skin_t *psVar7;
  
                    /* Unresolved local var: player_model_t * state@[???] */
  if (((developer.value == 0.0) && (qVar4 = Host_IsSinglePlayerGame(), qVar4 != false)) ||
     (cl.players[playerindex].model[0] == '\0')) {
    DM_PlayerState[playerindex].name[0] = '\0';
    pcVar3 = currententity;
    if (DM_PlayerState[playerindex].model == currententity->model) goto LAB_000d8bff;
    DM_PlayerState[playerindex].model = currententity->model;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: skin_t * pskin@[???] */
    iVar5 = pcVar3->index;
                    /* Unresolved local var: skin_t * pskin@[???] */
    psVar7 = pDM_RemapSkin[iVar5][0];
    if ((psVar7 == (skin_t *)0x0) || (psVar7->keynum != iVar5)) {
LAB_000d870e:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: skin_t * pskin@[???] */
      iVar2 = r_remapindex;
      psVar7 = DM_RemapSkin[r_remapindex];
      r_remapindex = (r_remapindex + 1) % 0x40;
      pDM_RemapSkin[iVar5][0] = psVar7;
      DM_RemapSkin[iVar2][0].keynum = iVar5;
      DM_RemapSkin[iVar2][0].topcolor = -1;
      DM_RemapSkin[iVar2][0].bottomcolor = -1;
    }
  }
  else {
    s2 = cl.players[playerindex].model;
    iVar5 = Q_strcmp(DM_PlayerState[playerindex].name,s2);
    if (iVar5 == 0) goto LAB_000d8bff;
    Q_strncpy(DM_PlayerState[playerindex].name,s2,0x103);
    DM_PlayerState[playerindex].name[0x103] = '\0';
    __snprintf_chk(DM_PlayerState[playerindex].modelname,0x104,1,0x104,&DAT_0025bb19,s2,s2);
    pmVar6 = Mod_ForName(DM_PlayerState[playerindex].modelname,false,true);
    DM_PlayerState[playerindex].model = pmVar6;
    pcVar3 = currententity;
    if (pmVar6 == (model_t *)0x0) {
      DM_PlayerState[playerindex].model = currententity->model;
    }
    iVar5 = pcVar3->index;
    psVar7 = pDM_RemapSkin[iVar5][0];
    if ((psVar7 == (skin_t *)0x0) || (iVar5 != psVar7->keynum)) goto LAB_000d870e;
  }
  psVar7->topcolor = -1;
  psVar7->bottomcolor = -1;
  iVar2 = r_remapindex;
  iVar5 = pcVar3->index;
  psVar7 = pDM_RemapSkin[iVar5][1];
  if ((psVar7 == (skin_t *)0x0) || (iVar5 != psVar7->keynum)) {
    psVar7 = DM_RemapSkin[r_remapindex] + 1;
    r_remapindex = (r_remapindex + 1) % 0x40;
    pDM_RemapSkin[iVar5][1] = psVar7;
    DM_RemapSkin[iVar2][1].keynum = iVar5;
    DM_RemapSkin[iVar2][1].topcolor = -1;
    DM_RemapSkin[iVar2][1].bottomcolor = -1;
  }
  psVar7->topcolor = -1;
  psVar7->bottomcolor = -1;
  iVar2 = r_remapindex;
  iVar5 = pcVar3->index;
  psVar7 = pDM_RemapSkin[iVar5][2];
  if ((psVar7 == (skin_t *)0x0) || (iVar5 != psVar7->keynum)) {
    psVar7 = DM_RemapSkin[r_remapindex] + 2;
    r_remapindex = (r_remapindex + 1) % 0x40;
    pDM_RemapSkin[iVar5][2] = psVar7;
    DM_RemapSkin[iVar2][2].keynum = iVar5;
    DM_RemapSkin[iVar2][2].topcolor = -1;
    DM_RemapSkin[iVar2][2].bottomcolor = -1;
  }
  psVar7->topcolor = -1;
  psVar7->bottomcolor = -1;
  iVar2 = r_remapindex;
  iVar5 = pcVar3->index;
  psVar7 = pDM_RemapSkin[iVar5][3];
  if ((psVar7 == (skin_t *)0x0) || (iVar5 != psVar7->keynum)) {
    psVar7 = DM_RemapSkin[r_remapindex] + 3;
    pasVar1 = DM_RemapSkin + r_remapindex;
    r_remapindex = (r_remapindex + 1) % 0x40;
    (*pasVar1)[3].keynum = iVar5;
    pDM_RemapSkin[iVar5][3] = psVar7;
    DM_RemapSkin[iVar2][3].topcolor = -1;
    DM_RemapSkin[iVar2][3].bottomcolor = -1;
  }
  psVar7->topcolor = -1;
  psVar7->bottomcolor = -1;
  iVar2 = r_remapindex;
  iVar5 = pcVar3->index;
  psVar7 = pDM_RemapSkin[iVar5][4];
  if ((psVar7 == (skin_t *)0x0) || (iVar5 != psVar7->keynum)) {
    psVar7 = DM_RemapSkin[r_remapindex] + 4;
    r_remapindex = (r_remapindex + 1) % 0x40;
    pDM_RemapSkin[iVar5][4] = psVar7;
    DM_RemapSkin[iVar2][4].keynum = iVar5;
    DM_RemapSkin[iVar2][4].topcolor = -1;
    DM_RemapSkin[iVar2][4].bottomcolor = -1;
  }
  psVar7->topcolor = -1;
  psVar7->bottomcolor = -1;
  iVar2 = r_remapindex;
  iVar5 = pcVar3->index;
  psVar7 = pDM_RemapSkin[iVar5][5];
  if ((psVar7 == (skin_t *)0x0) || (iVar5 != psVar7->keynum)) {
    psVar7 = DM_RemapSkin[r_remapindex] + 5;
    r_remapindex = (r_remapindex + 1) % 0x40;
    pDM_RemapSkin[iVar5][5] = psVar7;
    DM_RemapSkin[iVar2][5].keynum = iVar5;
    DM_RemapSkin[iVar2][5].topcolor = -1;
    DM_RemapSkin[iVar2][5].bottomcolor = -1;
  }
  psVar7->topcolor = -1;
  psVar7->bottomcolor = -1;
  iVar2 = r_remapindex;
  iVar5 = pcVar3->index;
  psVar7 = pDM_RemapSkin[iVar5][6];
  if ((psVar7 == (skin_t *)0x0) || (iVar5 != psVar7->keynum)) {
    psVar7 = DM_RemapSkin[r_remapindex] + 6;
    pasVar1 = DM_RemapSkin + r_remapindex;
    r_remapindex = (r_remapindex + 1) % 0x40;
    (*pasVar1)[6].keynum = iVar5;
    pDM_RemapSkin[iVar5][6] = psVar7;
    DM_RemapSkin[iVar2][6].topcolor = -1;
    DM_RemapSkin[iVar2][6].bottomcolor = -1;
  }
  psVar7->topcolor = -1;
  psVar7->bottomcolor = -1;
  iVar2 = r_remapindex;
  iVar5 = pcVar3->index;
  psVar7 = pDM_RemapSkin[iVar5][7];
  if ((psVar7 == (skin_t *)0x0) || (iVar5 != psVar7->keynum)) {
    psVar7 = DM_RemapSkin[r_remapindex] + 7;
    r_remapindex = (r_remapindex + 1) % 0x40;
    pDM_RemapSkin[iVar5][7] = psVar7;
    DM_RemapSkin[iVar2][7].keynum = iVar5;
    DM_RemapSkin[iVar2][7].topcolor = -1;
    DM_RemapSkin[iVar2][7].bottomcolor = -1;
  }
  psVar7->topcolor = -1;
  psVar7->bottomcolor = -1;
  iVar2 = r_remapindex;
  iVar5 = pcVar3->index;
  psVar7 = pDM_RemapSkin[iVar5][8];
  if ((psVar7 == (skin_t *)0x0) || (iVar5 != psVar7->keynum)) {
    psVar7 = DM_RemapSkin[r_remapindex] + 8;
    r_remapindex = (r_remapindex + 1) % 0x40;
    pDM_RemapSkin[iVar5][8] = psVar7;
    DM_RemapSkin[iVar2][8].keynum = iVar5;
    DM_RemapSkin[iVar2][8].topcolor = -1;
    DM_RemapSkin[iVar2][8].bottomcolor = -1;
  }
  psVar7->topcolor = -1;
  psVar7->bottomcolor = -1;
  iVar2 = r_remapindex;
  iVar5 = pcVar3->index;
  psVar7 = pDM_RemapSkin[iVar5][9];
  if ((psVar7 == (skin_t *)0x0) || (iVar5 != psVar7->keynum)) {
    psVar7 = DM_RemapSkin[r_remapindex] + 9;
    pasVar1 = DM_RemapSkin + r_remapindex;
    r_remapindex = (r_remapindex + 1) % 0x40;
    (*pasVar1)[9].keynum = iVar5;
    pDM_RemapSkin[iVar5][9] = psVar7;
    DM_RemapSkin[iVar2][9].topcolor = -1;
    DM_RemapSkin[iVar2][9].bottomcolor = -1;
  }
  psVar7->topcolor = -1;
  psVar7->bottomcolor = -1;
  iVar2 = r_remapindex;
  iVar5 = pcVar3->index;
  psVar7 = pDM_RemapSkin[iVar5][10];
  if ((psVar7 == (skin_t *)0x0) || (iVar5 != psVar7->keynum)) {
    psVar7 = DM_RemapSkin[r_remapindex] + 10;
    r_remapindex = (r_remapindex + 1) % 0x40;
    pDM_RemapSkin[iVar5][10] = psVar7;
    DM_RemapSkin[iVar2][10].keynum = iVar5;
    DM_RemapSkin[iVar2][10].topcolor = -1;
    DM_RemapSkin[iVar2][10].bottomcolor = -1;
  }
  psVar7->topcolor = -1;
  psVar7->bottomcolor = -1;
LAB_000d8bff:
  return DM_PlayerState[playerindex].model;
}


// studioapi_SetupRenderer  @ 000d6d60
void studioapi_SetupRenderer(int rendermode)

{
                    /* Unresolved local var: float an@[???] */
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
    g_rendermode = rendermode;
    return;
  }
  g_rendermode = rendermode;
  return;
}


// studioapi_StudioGetAliasTransform  @ 000d6260
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float *** studioapi_StudioGetAliasTransform(void)

{
  return (float ***)0x0;
}


// studioapi_StudioGetBoneTransform  @ 000d6240
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float **** studioapi_StudioGetBoneTransform(void)

{
  return (float ****)bonetransform;
}


// studioapi_StudioGetLightTransform  @ 000d6250
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float **** studioapi_StudioGetLightTransform(void)

{
  return (float ****)lighttransform;
}


// studioapi_StudioGetRotationMatrix  @ 000d6270
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float *** studioapi_StudioGetRotationMatrix(void)

{
  return (float ***)rotationmatrix;
}


// studioapi_StudioSetHeader  @ 000d63b0
void studioapi_StudioSetHeader(void *header)

{
  pstudiohdr = header;
  return;
}


// studioapi_StudioSetRemapColors  @ 000d6370
void studioapi_StudioSetRemapColors(int top,int bottom)

{
  r_topcolor = top;
  r_bottomcolor = bottom;
  return;
}


// studioapi_StudioSetRenderamt  @ 000d6e40
void studioapi_StudioSetRenderamt(int iRenderamt)

{
  cl_entity_t *ent;
  int iVar1;
  
  ent = currententity;
  (currententity->curstate).renderamt = iRenderamt;
  iVar1 = CL_FxBlend(ent);
  r_blend = (float)iVar1 * 0.003921569;
  return;
}


