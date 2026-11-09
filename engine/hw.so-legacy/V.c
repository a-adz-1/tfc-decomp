// V_ApplyShake  @ 001d04d0
void V_ApplyShake(float *origin,float *angles,float factor)

{
  (*g_engdstAddrs.V_ApplyShake)(&origin,&angles,&factor);
  if (origin != (float *)0x0) {
    VectorMA(origin,factor,gVShake.appliedOffset,origin);
  }
  if (angles != (float *)0x0) {
    angles[2] = gVShake.appliedAngle * factor + angles[2];
  }
  return;
}


// V_CalcBlend  @ 001cf990
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void V_CalcBlend(void)

{
                    /* Unresolved local var: float r@[???]
                       Unresolved local var: float g@[???]
                       Unresolved local var: float b@[???]
                       Unresolved local var: float a@[???] */
  v_blend[0] = 0.0;
  v_blend[1] = 0.0;
  v_blend[2] = 0.0;
  v_blend[3] = 0.0;
  return;
}


// V_CalcShake  @ 001d0270
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void V_CalcShake(void)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  double dVar9;
  
                    /* Unresolved local var: float frametime@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float fraction@[???]
                       Unresolved local var: float freq@[???] */
  (*g_engdstAddrs.V_CalcShake)();
  lVar3 = (longdouble)cl.time;
  lVar4 = (longdouble)gVShake.time;
  if (lVar3 <= lVar4) {
    lVar5 = (longdouble)gVShake.duration;
    lVar8 = (longdouble)0;
    if (((lVar8 < lVar5) && (lVar6 = (longdouble)gVShake.amplitude, lVar8 < lVar6)) &&
       (lVar7 = (longdouble)gVShake.frequency, lVar8 < lVar7)) {
      lVar8 = lVar3 - (longdouble)cl.oldtime;
      if ((longdouble)gVShake.nextShake < lVar3) {
        gVShake.nextShake = (float)(lVar3 + lVar5 / lVar7);
        gVShake.offset[0] = RandomFloat((float)-lVar6,gVShake.amplitude);
        gVShake.offset[1] = RandomFloat(-gVShake.amplitude,gVShake.amplitude);
        gVShake.offset[2] = RandomFloat(-gVShake.amplitude,gVShake.amplitude);
        gVShake.angle = RandomFloat(-gVShake.amplitude * 0.25,gVShake.amplitude * 0.25);
        lVar3 = (longdouble)cl.time;
        lVar4 = (longdouble)gVShake.time;
        lVar5 = (longdouble)gVShake.duration;
        lVar7 = (longdouble)gVShake.frequency;
        lVar6 = (longdouble)gVShake.amplitude;
      }
      fVar2 = gVShake.angle;
      fVar1 = (float)((lVar3 - lVar4) / lVar5);
      lVar4 = (longdouble)0;
      if ((longdouble)fVar1 != lVar4) {
        lVar4 = (lVar7 / (longdouble)fVar1) * lVar7;
      }
      dVar9 = sin((double)(lVar3 * lVar4));
      fVar1 = fVar1 * fVar1 * (float)dVar9;
      gVShake.amplitude =
           (float)lVar6 - ((float)lVar8 / ((float)lVar7 * (float)lVar5)) * (float)lVar6;
      gVShake.appliedOffset[0] = gVShake.offset[0] * fVar1;
      gVShake.appliedOffset[1] = gVShake.offset[1] * fVar1;
      gVShake.appliedOffset[2] = gVShake.offset[2] * fVar1;
      gVShake.appliedAngle = fVar2 * fVar1;
      return;
    }
  }
  if (lVar4 != (longdouble)0) {
    gVShake.time = 0.0;
    gVShake.appliedOffset[0] = 0.0;
    gVShake.appliedOffset[1] = 0.0;
    gVShake.appliedOffset[2] = 0.0;
    gVShake.appliedAngle = 0.0;
  }
  return;
}


// V_CheckGamma  @ 001cf8d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean V_CheckGamma(void)

{
  qboolean qVar1;
  
                    /* Unresolved local var: float ambientr@[???]
                       Unresolved local var: float ambientg@[???]
                       Unresolved local var: float ambientb@[???] */
  FilterLightParams();
  if ((((v_gamma.value != V_CheckGamma::oldgammavalue) ||
       (v_lightgamma.value != V_CheckGamma::oldlightgamma)) ||
      (v_texgamma.value != V_CheckGamma::oldtexgamma)) ||
     (qVar1 = false, v_brightness.value != V_CheckGamma::oldbrightness)) {
    BuildGammaTable(v_gamma.value);
    V_CheckGamma::oldgammavalue = v_gamma.value;
    V_CheckGamma::oldlightgamma = v_lightgamma.value;
    V_CheckGamma::oldtexgamma = v_texgamma.value;
    V_CheckGamma::oldbrightness = v_brightness.value;
    D_FlushCaches();
    vid.recalc_refdef = 1;
    qVar1 = true;
  }
  return qVar1;
}


// V_FadeAlpha  @ 001d0740
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int V_FadeAlpha(void)

{
  uint uVar1;
  uint uVar2;
  longdouble lVar3;
  
                    /* Unresolved local var: int alpha@[???] */
  lVar3 = (longdouble)cl.time;
  if ((lVar3 <= (longdouble)cl.sf.fadeReset) || (lVar3 <= (longdouble)cl.sf.fadeEnd)) {
    if ((cl.sf.fadeFlags & 4U) != 0) goto LAB_001d0772;
    if ((cl.sf.fadeFlags & 1U) == 0) {
      uVar2 = (uint)(((longdouble)cl.sf.fadeEnd - lVar3) * (longdouble)cl.sf.fadeSpeed);
    }
    else {
      uVar2 = (uint)(((longdouble)cl.sf.fadeEnd - lVar3) * (longdouble)cl.sf.fadeSpeed +
                    (longdouble)cl.sf.fadealpha);
    }
  }
  else {
    if ((cl.sf.fadeFlags & 4U) == 0) {
      return 0;
    }
LAB_001d0772:
    if (((cl.sf.fadeFlags & 1U) == 0) || ((longdouble)cl.sf.fadeTotalEnd <= lVar3)) {
      uVar2 = (uint)cl.sf.fadealpha;
      cl.sf.fadeEnd = (float)(lVar3 + (longdouble)0.1);
      goto LAB_001d079a;
    }
    uVar2 = (uint)(((longdouble)cl.sf.fadeTotalEnd - lVar3) * (longdouble)cl.sf.fadeSpeed +
                  (longdouble)cl.sf.fadealpha);
  }
  if ((int)(uint)cl.sf.fadealpha < (int)uVar2) {
    return (uint)cl.sf.fadealpha;
  }
LAB_001d079a:
  uVar1 = 0;
  if (-1 < (int)uVar2) {
    uVar1 = uVar2;
  }
  return uVar1;
}


// V_GetRefParams  @ 001cfd40
void V_GetRefParams(ref_params_t *pparams)

{
  r_refdef.vieworg[0] = pparams->vieworg[0];
  r_refdef.vieworg[1] = pparams->vieworg[1];
  r_refdef.vieworg[2] = pparams->vieworg[2];
  r_refdef.viewangles[0] = pparams->viewangles[0];
  r_refdef.viewangles[1] = pparams->viewangles[1];
  r_refdef.viewangles[2] = pparams->viewangles[2];
  forward[0] = pparams->forward[0];
  forward[1] = pparams->forward[1];
  forward[2] = pparams->forward[2];
  right[0] = pparams->right[0];
  right[1] = pparams->right[1];
  right[2] = pparams->right[2];
  up[0] = pparams->up[0];
  up[1] = pparams->up[1];
  up[2] = pparams->up[2];
  cl.simvel[0] = pparams->simvel[0];
  cl.simvel[1] = pparams->simvel[1];
  cl.simvel[2] = pparams->simvel[2];
  cl.simorg[0] = pparams->simorg[0];
  cl.simorg[1] = pparams->simorg[1];
  cl.simorg[2] = pparams->simorg[2];
  cl.viewangles[0] = pparams->cl_viewangles[0];
  cl.viewangles[1] = pparams->cl_viewangles[1];
  cl.viewangles[2] = pparams->cl_viewangles[2];
  cl.crosshairangle[0] = pparams->crosshairangle[0];
  cl.crosshairangle[1] = pparams->crosshairangle[1];
  cl.crosshairangle[2] = pparams->crosshairangle[2];
  cl.punchangle[0] = pparams->punchangle[0];
  cl.punchangle[1] = pparams->punchangle[1];
  cl.punchangle[2] = pparams->punchangle[2];
  cl.viewheight[0] = pparams->viewheight[0];
  cl.viewheight[1] = pparams->viewheight[1];
  cl.viewheight[2] = pparams->viewheight[2];
  r_refdef.vrect.x = pparams->viewport[0];
  r_refdef.vrect.y = pparams->viewport[1];
  r_refdef.vrect.width = pparams->viewport[2];
  r_refdef.vrect.height = pparams->viewport[3];
  r_refdef.onlyClientDraws = pparams->onlyClientDraw;
  return;
}


// V_Init  @ 001d0840
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void V_Init(void)

{
  Cvar_RegisterVariable(&v_dark);
  Cvar_RegisterVariable(&crosshair);
  Cvar_RegisterVariable(&v_gamma);
  Cvar_RegisterVariable(&v_lightgamma);
  Cvar_RegisterVariable(&v_texgamma);
  Cvar_RegisterVariable(&v_brightness);
  Cvar_RegisterVariable(&v_lambert);
  Cvar_RegisterVariable(&v_direct);
  BuildGammaTable(2.5);
  return;
}


// V_InitLevel  @ 001d08c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void V_InitLevel(void)

{
  Q_memset(&gVShake,0,0x34);
  if (v_dark.value != 0.0) {
    cl.sf.fadeReset = (float)cl.time + 5.0;
    cl.sf.fadeFlags = 0;
    cl.sf.fadeb = '\0';
    cl.sf.fadeg = '\0';
    cl.sf.fadeEnd = cl.sf.fadeReset + 5.0;
    cl.sf.fader = '\0';
    cl.sf.fadealpha = 0xff;
    cl.sf.fadeSpeed = 51.0;
    Cvar_DirectSet(&v_dark,"0");
    return;
  }
  cl.sf.fadeSpeed = 0.0;
  cl.sf.fadeEnd = 0.0;
  cl.sf.fadeReset = 0.0;
  cl.sf.fadealpha = '\0';
  cl.sf.fadeb = '\0';
  cl.sf.fadeg = '\0';
  cl.sf.fader = '\0';
  cl.sf.fadeFlags = 0;
  return;
}


// V_RenderView  @ 001cfed0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void V_RenderView(void)

{
  int iVar1;
  ref_params_t local_fc;
  
                    /* Unresolved local var: ref_params_t rp@[???]
                       Unresolved local var: cl_entity_t * view@[???]
                       Unresolved local var: int viewnum@[???] */
  r_soundOrigin[2] = 0.0;
  r_soundOrigin[1] = 0.0;
  r_soundOrigin[0] = 0.0;
  r_playerViewportAngles[2] = 0.0;
  r_playerViewportAngles[1] = 0.0;
  r_playerViewportAngles[0] = 0.0;
  if (((con_forcedup == false) && (cls.state == ca_active)) && (cls.signon == 2)) {
    iVar1 = 0;
    cl.viewent.model = CL_GetModelByIndex(cl.stats[2]);
    cl.viewent.curstate.frame = 0.0;
    cl.viewent.curstate.modelindex = cl.stats[2];
    cl.viewent.curstate.colormap = 0;
    cl.viewent.index = cl.playernum + 1;
    V_SetRefParams(&local_fc);
    do {
      ClientDLL_CalcRefdef(&local_fc);
      if (((iVar1 == 0) &&
          ((cls.demoplayback != false ||
           (CL_SetDemoViewInfo(&local_fc,cl.viewent.origin,cl.stats[2]), cls.demoplayback != false))
          )) && (cls.spectator == false)) {
                    /* Unresolved local var: vec3_t angles@[???] */
        CL_GetDemoViewInfo(&local_fc,cl.viewent.origin,cl.stats + 2);
        cl.viewent.curstate.angles[1] = local_fc.viewangles[1];
        cl.viewent.curstate.angles[2] = local_fc.viewangles[2];
        cl.viewent.curstate.angles[0] = -local_fc.viewangles[0];
        local_fc.nextView = 0;
        cl.viewent.latched.prevangles[0] = cl.viewent.curstate.angles[0];
        cl.viewent.latched.prevangles[1] = cl.viewent.curstate.angles[1];
        cl.viewent.latched.prevangles[2] = cl.viewent.curstate.angles[2];
        cl.viewent.angles[0] = cl.viewent.curstate.angles[0];
        cl.viewent.angles[1] = cl.viewent.curstate.angles[1];
        cl.viewent.angles[2] = cl.viewent.curstate.angles[2];
      }
      V_GetRefParams(&local_fc);
      if (local_fc.intermission == 0) {
        if ((local_fc.paused == 0) && (chase_active.value != 0.0)) {
          Chase_Update();
        }
      }
      else {
        cl.viewent.model = (model_s *)0x0;
      }
      R_PushDlights();
      if ((iVar1 == 0) && (r_refdef.onlyClientDraws != false)) {
        (*qglClearColor)(0.0,0.0,0.0,0.0);
        (*qglClear)(0x4000);
      }
      if (lcd_x.value == 0.0) {
        R_RenderView();
      }
      else {
                    /* Unresolved local var: int i@[???] */
        vid.aspect = vid.aspect * 0.5;
        vid.rowbytes = vid.rowbytes << 1;
        r_refdef.viewangles[1] = r_refdef.viewangles[1] - lcd_yaw.value;
        r_refdef.vieworg[0] = r_refdef.vieworg[0] - local_fc.right[0] * lcd_x.value;
        r_refdef.vieworg[1] = r_refdef.vieworg[1] - local_fc.right[1] * lcd_x.value;
        r_refdef.vieworg[2] = r_refdef.vieworg[2] - lcd_x.value * local_fc.right[2];
        R_RenderView();
        vid.buffer = vid.buffer + (vid.rowbytes >> 1);
        R_PushDlights();
        r_refdef.viewangles[1] = lcd_yaw.value + lcd_yaw.value + r_refdef.viewangles[1];
        r_refdef.vieworg[0] =
             (local_fc.right[0] + local_fc.right[0]) * lcd_x.value + r_refdef.vieworg[0];
        r_refdef.vieworg[1] =
             (local_fc.right[1] + local_fc.right[1]) * lcd_x.value + r_refdef.vieworg[1];
        r_refdef.vieworg[2] =
             (local_fc.right[2] + local_fc.right[2]) * lcd_x.value + r_refdef.vieworg[2];
        R_RenderView();
        r_refdef.vrect.height = r_refdef.vrect.height << 1;
        vid.rowbytes = vid.rowbytes >> 1;
        vid.aspect = vid.aspect + vid.aspect;
        vid.buffer = vid.buffer + -vid.rowbytes;
      }
      if (local_fc.onlyClientDraw == 0) {
        r_soundOrigin[0] = r_origin[0];
        r_soundOrigin[1] = r_origin[1];
        r_soundOrigin[2] = r_origin[2];
        r_playerViewportAngles[0] = local_fc.viewangles[0];
        r_playerViewportAngles[1] = local_fc.viewangles[1];
        r_playerViewportAngles[2] = local_fc.viewangles[2];
      }
      iVar1 = iVar1 + 1;
    } while (local_fc.nextView != 0);
  }
  return;
}


// V_ScreenFade  @ 001d05d0
int V_ScreenFade(char *pszName,int iSize,void *pbuf)

{
  float fVar1;
  
                    /* Unresolved local var: float flScale@[???]
                       Unresolved local var: ScreenFade * pFade@[???] */
  if (pbuf != (void *)0x0) {
    if ((*(byte *)((int)pbuf + 4) & 8) == 0) {
      fVar1 = 0.00024414062;
    }
    else {
      fVar1 = 0.00390625;
    }
    cl.sf.fadeEnd = (float)*(ushort *)pbuf * fVar1;
    cl.sf.fadeReset = (float)*(ushort *)((int)pbuf + 2) * fVar1;
    cl.sf.fader = *(byte *)((int)pbuf + 6);
    cl.sf.fadeg = *(byte *)((int)pbuf + 7);
    cl.sf.fadeb = *(byte *)((int)pbuf + 8);
    cl.sf.fadealpha = *(byte *)((int)pbuf + 9);
    cl.sf.fadeFlags = (int)*(short *)((int)pbuf + 4);
    cl.sf.fadeSpeed = 0.0;
    if (*(short *)pbuf != 0) {
      if ((*(byte *)((int)pbuf + 4) & 1) == 0) {
        if (cl.sf.fadeEnd != 0.0) {
          cl.sf.fadeSpeed = (float)cl.sf.fadealpha / cl.sf.fadeEnd;
        }
        cl.sf.fadeReset = cl.sf.fadeReset + (float)cl.time;
        cl.sf.fadeEnd = cl.sf.fadeReset + cl.sf.fadeEnd;
        return 1;
      }
      if (cl.sf.fadeEnd != 0.0) {
        cl.sf.fadeSpeed = -(float)cl.sf.fadealpha / cl.sf.fadeEnd;
      }
      cl.sf.fadeEnd = cl.sf.fadeEnd + (float)cl.time;
      cl.sf.fadeReset = cl.sf.fadeEnd + cl.sf.fadeReset;
      cl.sf.fadeTotalEnd = cl.sf.fadeEnd;
    }
  }
  return 1;
}


// V_ScreenShake  @ 001d0540
int V_ScreenShake(char *pszName,int iSize,void *pbuf)

{
                    /* Unresolved local var: ScreenShake * pShake@[???]
                       Unresolved local var: float amplitude@[???] */
  gVShake.duration = (float)*(ushort *)((int)pbuf + 2) * 0.00024414062;
  gVShake.time = gVShake.duration + (float)cl.time;
  if (gVShake.amplitude < (float)*(ushort *)pbuf * 0.00024414062) {
    gVShake.amplitude = (float)*(ushort *)pbuf * 0.00024414062;
  }
  gVShake.nextShake = 0.0;
  gVShake.frequency = (float)*(ushort *)((int)pbuf + 4) * 0.00390625;
  return 1;
}


// V_SetRefParams  @ 001cfae0
void V_SetRefParams(ref_params_t *pparams)

{
  qboolean qVar1;
  
  Q_memset(pparams,0,0xe8);
  pparams->vieworg[0] = r_refdef.vieworg[0];
  pparams->vieworg[1] = r_refdef.vieworg[1];
  pparams->vieworg[2] = r_refdef.vieworg[2];
  pparams->viewangles[0] = r_refdef.viewangles[0];
  pparams->viewangles[1] = r_refdef.viewangles[1];
  pparams->viewangles[2] = r_refdef.viewangles[2];
  pparams->forward[0] = forward[0];
  pparams->forward[1] = forward[1];
  pparams->forward[2] = forward[2];
  pparams->right[0] = right[0];
  pparams->right[1] = right[1];
  pparams->right[2] = right[2];
  pparams->up[0] = up[0];
  pparams->up[1] = up[1];
  pparams->up[2] = up[2];
  pparams->time = (float)cl.time;
  pparams->frametime = (float)host_frametime;
  pparams->intermission = (uint)(cl.intermission != 0);
  pparams->paused = (uint)(cl.paused != false);
  pparams->spectator = (uint)(cls.spectator != false);
  pparams->onground = (uint)(cl.onground != -1);
  pparams->waterlevel = cl.waterlevel;
  pparams->simvel[0] = cl.simvel[0];
  pparams->simvel[1] = cl.simvel[1];
  pparams->simvel[2] = cl.simvel[2];
  pparams->simorg[0] = cl.simorg[0];
  pparams->simorg[1] = cl.simorg[1];
  pparams->simorg[2] = cl.simorg[2];
  pparams->viewheight[0] = cl.viewheight[0];
  pparams->viewheight[1] = cl.viewheight[1];
  pparams->viewheight[2] = cl.viewheight[2];
  pparams->idealpitch = cl.idealpitch;
  pparams->cl_viewangles[0] = cl.viewangles[0];
  pparams->cl_viewangles[1] = cl.viewangles[1];
  pparams->cl_viewangles[2] = cl.viewangles[2];
  pparams->health = cl.stats[0];
  pparams->crosshairangle[0] = cl.crosshairangle[0];
  pparams->crosshairangle[1] = cl.crosshairangle[1];
  pparams->crosshairangle[2] = cl.crosshairangle[2];
  pparams->viewsize = scr_viewsize.value;
  pparams->punchangle[0] = cl.punchangle[0];
  pparams->punchangle[1] = cl.punchangle[1];
  pparams->punchangle[2] = cl.punchangle[2];
  pparams->maxclients = cl.maxclients;
  pparams->viewentity = cl.viewentity;
  pparams->playernum = cl.playernum;
  pparams->max_entities = cl.max_edicts;
  qVar1 = cls.demoplayback;
  pparams->cmd = &cl.cmd;
  pparams->demoplayback = qVar1;
  pparams->movevars = &movevars;
  pparams->hardware = 1;
  pparams->smoothing = cl.pushmsec;
  pparams->viewport[0] = 0;
  pparams->viewport[1] = 0;
  pparams->viewport[2] = vid.width;
  pparams->viewport[3] = vid.height;
  pparams->nextView = 0;
  pparams->onlyClientDraw = 0;
  return;
}


// V_UTF8ToUChar32  @ 00217d30
qboolean V_UTF8ToUChar32(char *pUTF8_,uchar32 *uValueOut)

{
  bool local_1;
  
                    /* Unresolved local var: bool bError@[???] */
  Q_UTF8ToUChar32(pUTF8_,uValueOut,&local_1);
  return (uint)local_1;
}


// V_UpdatePalette  @ 001cf9a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void V_UpdatePalette(void)

{
  uchar uVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean newFlag@[???]
                       Unresolved local var: float r@[???]
                       Unresolved local var: float g@[???]
                       Unresolved local var: float b@[???]
                       Unresolved local var: float a@[???]
                       Unresolved local var: int ir@[DW_OP_reg0(EAX)]
                       Unresolved local var: int ig@[???]
                       Unresolved local var: int ib@[???]
                       Unresolved local var: qboolean force@[???] */
                    /* Unresolved local var: float ambientr@[???]
                       Unresolved local var: float ambientg@[???]
                       Unresolved local var: float ambientb@[???] */
  FilterLightParams();
  if ((((v_gamma.value != V_CheckGamma::oldgammavalue) ||
       (v_lightgamma.value != V_CheckGamma::oldlightgamma)) ||
      (v_texgamma.value != V_CheckGamma::oldtexgamma)) ||
     (v_brightness.value != V_CheckGamma::oldbrightness)) {
    BuildGammaTable(v_gamma.value);
    V_CheckGamma::oldgammavalue = v_gamma.value;
    V_CheckGamma::oldlightgamma = v_lightgamma.value;
    V_CheckGamma::oldtexgamma = v_texgamma.value;
    V_CheckGamma::oldbrightness = v_brightness.value;
    D_FlushCaches();
                    /* Unresolved local var: float r@[???]
                       Unresolved local var: float g@[???]
                       Unresolved local var: float b@[???]
                       Unresolved local var: float a@[???] */
    iVar3 = 0;
    vid.recalc_refdef = 1;
    v_blend[0] = 0.0;
    v_blend[1] = 0.0;
    v_blend[2] = 0.0;
    v_blend[3] = 0.0;
    do {
      iVar2 = (int)((float)iVar3 + 0.0);
      if (0xff < iVar2) {
        iVar2 = 0xff;
      }
      uVar1 = texgammatable[iVar2];
      ramps[0][iVar3] = uVar1;
      ramps[1][iVar3] = uVar1;
      ramps[2][iVar3] = uVar1;
      iVar3 = iVar3 + 1;
    } while (iVar3 != 0x100);
  }
  return;
}


