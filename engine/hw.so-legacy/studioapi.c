// studioapi_GL_SetRenderMode  @ 00139f00
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
                    /* WARNING: Could not recover jumptable at 0x00139f95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglEnable)(0xbe2);
    return;
  }
  return;
}


// studioapi_GL_StudioDrawShadow  @ 00144720
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void studioapi_GL_StudioDrawShadow(void)

{
  float fVar1;
  
  (*qglDepthMask)('\x01');
  if (r_shadows.value == 0.0) {
    return;
  }
  if ((g_rendermode != 5) && ((r_model->flags & 0x100) == 0)) {
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


// studioapi_GetAliasScale  @ 00139d10
void studioapi_GetAliasScale(float *x,float *y)

{
  *y = 1.0;
  *x = 1.0;
  return;
}


// studioapi_GetChromeSprite  @ 00139ce0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

model_t * studioapi_GetChromeSprite(void)

{
  return cl_sprite_shell;
}


// studioapi_GetCurrentEntity  @ 00139aa0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

cl_entity_t * studioapi_GetCurrentEntity(void)

{
  return currententity;
}


// studioapi_GetCvar  @ 00139e20
cvar_s * studioapi_GetCvar(char *name)

{
  cvar_s *pcVar1;
  int iVar2;
  
  (*g_engdstAddrs.pfnGetCvarPointer)(&name);
                    /* Unresolved local var: cvar_t * retval@[???] */
  pcVar1 = cvar_vars;
  while ((pcVar1 != (cvar_t *)0x0 && (iVar2 = Q_stricmp(name,pcVar1->name), iVar2 != 0))) {
    pcVar1 = pcVar1->next;
  }
  return pcVar1;
}


// studioapi_GetForceFaceFlags  @ 00139d50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int studioapi_GetForceFaceFlags(void)

{
  return g_ForcedFaceFlags;
}


// studioapi_GetModelByIndex  @ 00139dd0
model_t * studioapi_GetModelByIndex(int index)

{
  char *pcVar1;
  model_t *mod;
  double dVar2;
  double dVar3;
  
  mod = (model_t *)0x0;
  if (index < 0x200) {
    pcVar1 = "_ZN5vgui219AnimatingImagePanel13GetMessageMapEv";
    mod = *(model_t **)(cl.resourcesneeded.szFileName + (int)pcVar1 * 4 + index * 4 + 0x18);
    if ((mod != (model_t *)0x0) && (mod->needload - true < 2)) {
      if (fs_precache_timings.value != 0.0) {
        dVar2 = Sys_FloatTime();
        Mod_LoadModel(mod,false,false);
        dVar3 = Sys_FloatTime();
        Con_DPrintf("fs_precache_timings: loaded model %s in time %.3f sec\n",mod,
                    (double)(float)((longdouble)dVar3 - (longdouble)dVar2));
        return *(model_t **)(cl.resourcesneeded.szFileName + (int)pcVar1 * 4 + index * 4 + 0x18);
      }
      Mod_LoadModel(mod,false,false);
      return *(model_t **)(cl.resourcesneeded.szFileName + (int)pcVar1 * 4 + index * 4 + 0x18);
    }
  }
  return mod;
}


// studioapi_GetModelCounters  @ 00139cf0
void studioapi_GetModelCounters(int **s,int **a)

{
  *s = &r_smodels_total;
  *a = &r_amodels_drawn;
  return;
}


// studioapi_GetPlayerState  @ 00139ae0
entity_state_t * studioapi_GetPlayerState(int index)

{
  entity_state_t *peVar1;
  
  peVar1 = (entity_state_t *)0x0;
  if ((-1 < index) && (index < cl.maxclients)) {
    peVar1 = (entity_state_t *)(cl.parsecountmod * 0x42b8 + 0xc7f6fc + index * 0x154);
  }
  return peVar1;
}


// studioapi_GetTimes  @ 00139b20
void studioapi_GetTimes(int *framecount,double *cl_time,double *cl_oldtime)

{
  *framecount = r_framecount;
  *cl_time = cl.time;
  *cl_oldtime = cl.oldtime;
  return;
}


// studioapi_GetViewEntity  @ 00139b10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

cl_entity_t * studioapi_GetViewEntity(void)

{
  return &cl.viewent;
}


// studioapi_GetViewInfo  @ 00139c60
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


// studioapi_PlayerInfo  @ 00139ab0
player_info_t * studioapi_PlayerInfo(int index)

{
  player_info_t *ppVar1;
  
  ppVar1 = (player_info_t *)0x0;
  if ((-1 < index) && (index < cl.maxclients)) {
    ppVar1 = cl.players + index;
  }
  return ppVar1;
}


// studioapi_RenderShadow  @ 0013a040
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
                    /* WARNING: Could not recover jumptable at 0x0013a18a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*tri.RenderMode)(0);
        return;
      }
    }
  }
  return;
}


// studioapi_RestoreRenderer  @ 00139b60
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
                    /* WARNING: Could not recover jumptable at 0x00139bd6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglPopMatrix)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00139baf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglPopMatrix)();
  return;
}


// studioapi_SetBackFaceCull  @ 00139b50
void studioapi_SetBackFaceCull(int iCull)

{
  g_iBackFaceCull = iCull;
  return;
}


// studioapi_SetChromeOrigin  @ 00139c00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void studioapi_SetChromeOrigin(void)

{
  g_ChromeOrigin[0] = r_origin[0];
  g_ChromeOrigin[1] = r_origin[1];
  g_ChromeOrigin[2] = r_origin[2];
  return;
}


// studioapi_SetForceFaceFlags  @ 00139d60
void studioapi_SetForceFaceFlags(int flags)

{
  g_ForcedFaceFlags = flags;
  return;
}


// studioapi_SetRenderModel  @ 00139d80
void studioapi_SetRenderModel(model_s *model)

{
  r_model = model;
  return;
}


// studioapi_SetupModel  @ 0013b2e0
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


// studioapi_SetupPlayerModel  @ 0013b380
model_t * studioapi_SetupPlayerModel(int playerindex)

{
  skin_t (*pasVar1) [11];
  int iVar2;
  cl_entity_t *pcVar3;
  skin_t *psVar4;
  qboolean qVar5;
  int iVar6;
  model_t *pmVar7;
  char *s2;
  
                    /* Unresolved local var: player_model_t * state@[???] */
  if (((developer.value == 0.0) && (qVar5 = Host_IsSinglePlayerGame(), qVar5 != false)) ||
     (cl.players[playerindex].model[0] == '\0')) {
    pcVar3 = currententity;
    DM_PlayerState[playerindex].name[0] = '\0';
    if (DM_PlayerState[playerindex].model == pcVar3->model) {
      return DM_PlayerState[playerindex].model;
    }
    DM_PlayerState[playerindex].model = pcVar3->model;
    iVar2 = r_remapindex;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: skin_t * pskin@[???] */
    iVar6 = pcVar3->index;
                    /* Unresolved local var: skin_t * pskin@[???] */
    psVar4 = pDM_RemapSkin[iVar6][0];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex];
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[0].keynum = iVar6;
      pDM_RemapSkin[iVar6][0] = psVar4;
      DM_RemapSkin[iVar2][0].topcolor = -1;
      DM_RemapSkin[iVar2][0].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][1];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex] + 1;
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[1].keynum = iVar6;
      pDM_RemapSkin[iVar6][1] = psVar4;
      DM_RemapSkin[iVar2][1].topcolor = -1;
      DM_RemapSkin[iVar2][1].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][2];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex] + 2;
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[2].keynum = iVar6;
      pDM_RemapSkin[iVar6][2] = psVar4;
      DM_RemapSkin[iVar2][2].topcolor = -1;
      DM_RemapSkin[iVar2][2].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][3];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex] + 3;
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[3].keynum = iVar6;
      pDM_RemapSkin[iVar6][3] = psVar4;
      DM_RemapSkin[iVar2][3].topcolor = -1;
      DM_RemapSkin[iVar2][3].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][4];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex] + 4;
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[4].keynum = iVar6;
      pDM_RemapSkin[iVar6][4] = psVar4;
      DM_RemapSkin[iVar2][4].topcolor = -1;
      DM_RemapSkin[iVar2][4].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][5];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex] + 5;
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[5].keynum = iVar6;
      pDM_RemapSkin[iVar6][5] = psVar4;
      DM_RemapSkin[iVar2][5].topcolor = -1;
      DM_RemapSkin[iVar2][5].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][6];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex] + 6;
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[6].keynum = iVar6;
      pDM_RemapSkin[iVar6][6] = psVar4;
      DM_RemapSkin[iVar2][6].topcolor = -1;
      DM_RemapSkin[iVar2][6].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][7];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex] + 7;
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[7].keynum = iVar6;
      pDM_RemapSkin[iVar6][7] = psVar4;
      DM_RemapSkin[iVar2][7].topcolor = -1;
      DM_RemapSkin[iVar2][7].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][8];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex] + 8;
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[8].keynum = iVar6;
      pDM_RemapSkin[iVar6][8] = psVar4;
      DM_RemapSkin[iVar2][8].topcolor = -1;
      DM_RemapSkin[iVar2][8].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][9];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex] + 9;
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[9].keynum = iVar6;
      pDM_RemapSkin[iVar6][9] = psVar4;
      DM_RemapSkin[iVar2][9].topcolor = -1;
      DM_RemapSkin[iVar2][9].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar6 = pcVar3->index;
  }
  else {
    s2 = cl.players[playerindex].model;
    iVar6 = Q_strcmp(DM_PlayerState[playerindex].name,s2);
    if (iVar6 == 0) goto LAB_0013b8a8;
    Q_strncpy(DM_PlayerState[playerindex].name,s2,0x103);
    DM_PlayerState[playerindex].name[0x103] = '\0';
    snprintf(DM_PlayerState[playerindex].modelname,0x104,"models/player/%s/%s.mdl",s2,s2);
    pmVar7 = Mod_ForName(DM_PlayerState[playerindex].modelname,false,true);
    DM_PlayerState[playerindex].model = pmVar7;
    pcVar3 = currententity;
    if (pmVar7 == (model_t *)0x0) {
      DM_PlayerState[playerindex].model = currententity->model;
    }
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][0];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex];
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[0].keynum = iVar6;
      pDM_RemapSkin[iVar6][0] = psVar4;
      DM_RemapSkin[iVar2][0].topcolor = -1;
      DM_RemapSkin[iVar2][0].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][1];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex] + 1;
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[1].keynum = iVar6;
      pDM_RemapSkin[iVar6][1] = psVar4;
      DM_RemapSkin[iVar2][1].topcolor = -1;
      DM_RemapSkin[iVar2][1].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][2];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex] + 2;
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[2].keynum = iVar6;
      pDM_RemapSkin[iVar6][2] = psVar4;
      DM_RemapSkin[iVar2][2].topcolor = -1;
      DM_RemapSkin[iVar2][2].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][3];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex] + 3;
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[3].keynum = iVar6;
      pDM_RemapSkin[iVar6][3] = psVar4;
      DM_RemapSkin[iVar2][3].topcolor = -1;
      DM_RemapSkin[iVar2][3].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][4];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex] + 4;
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[4].keynum = iVar6;
      pDM_RemapSkin[iVar6][4] = psVar4;
      DM_RemapSkin[iVar2][4].topcolor = -1;
      DM_RemapSkin[iVar2][4].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][5];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex] + 5;
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[5].keynum = iVar6;
      pDM_RemapSkin[iVar6][5] = psVar4;
      DM_RemapSkin[iVar2][5].topcolor = -1;
      DM_RemapSkin[iVar2][5].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][6];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex] + 6;
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[6].keynum = iVar6;
      pDM_RemapSkin[iVar6][6] = psVar4;
      DM_RemapSkin[iVar2][6].topcolor = -1;
      DM_RemapSkin[iVar2][6].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][7];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex] + 7;
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[7].keynum = iVar6;
      pDM_RemapSkin[iVar6][7] = psVar4;
      DM_RemapSkin[iVar2][7].topcolor = -1;
      DM_RemapSkin[iVar2][7].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][8];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex] + 8;
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[8].keynum = iVar6;
      pDM_RemapSkin[iVar6][8] = psVar4;
      DM_RemapSkin[iVar2][8].topcolor = -1;
      DM_RemapSkin[iVar2][8].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar2 = r_remapindex;
    iVar6 = pcVar3->index;
    psVar4 = pDM_RemapSkin[iVar6][9];
    if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
      psVar4 = DM_RemapSkin[r_remapindex] + 9;
      pasVar1 = DM_RemapSkin + r_remapindex;
      r_remapindex = (r_remapindex + 1) % 0x40;
      (*pasVar1)[9].keynum = iVar6;
      pDM_RemapSkin[iVar6][9] = psVar4;
      DM_RemapSkin[iVar2][9].topcolor = -1;
      DM_RemapSkin[iVar2][9].bottomcolor = -1;
    }
    psVar4->topcolor = -1;
    psVar4->bottomcolor = -1;
    iVar6 = pcVar3->index;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: skin_t * pskin@[???] */
  iVar2 = r_remapindex;
  psVar4 = pDM_RemapSkin[iVar6][10];
  if ((psVar4 == (skin_t *)0x0) || (iVar6 != psVar4->keynum)) {
    psVar4 = DM_RemapSkin[r_remapindex] + 10;
    r_remapindex = (r_remapindex + 1) % 0x40;
    pDM_RemapSkin[iVar6][10] = psVar4;
    DM_RemapSkin[iVar2][10].keynum = iVar6;
    DM_RemapSkin[iVar2][10].topcolor = -1;
    DM_RemapSkin[iVar2][10].bottomcolor = -1;
  }
  psVar4->topcolor = -1;
  psVar4->bottomcolor = -1;
LAB_0013b8a8:
  return DM_PlayerState[playerindex].model;
}


// studioapi_SetupRenderer  @ 00139e30
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


// studioapi_StudioGetAliasTransform  @ 00139c40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float *** studioapi_StudioGetAliasTransform(void)

{
  return (float ***)0x0;
}


// studioapi_StudioGetBoneTransform  @ 00139c20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float **** studioapi_StudioGetBoneTransform(void)

{
  return (float ****)bonetransform;
}


// studioapi_StudioGetLightTransform  @ 00139c30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float **** studioapi_StudioGetLightTransform(void)

{
  return (float ****)lighttransform;
}


// studioapi_StudioGetRotationMatrix  @ 00139c50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float *** studioapi_StudioGetRotationMatrix(void)

{
  return (float ***)rotationmatrix;
}


// studioapi_StudioSetHeader  @ 00139d70
void studioapi_StudioSetHeader(void *header)

{
  pstudiohdr = header;
  return;
}


// studioapi_StudioSetRemapColors  @ 00139d30
void studioapi_StudioSetRemapColors(int top,int bottom)

{
  r_topcolor = top;
  r_bottomcolor = bottom;
  return;
}


// studioapi_StudioSetRenderamt  @ 00139de0
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


