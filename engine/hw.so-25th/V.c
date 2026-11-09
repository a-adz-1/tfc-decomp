// V_ApplyShake  @ 0017a290
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


// V_CalcBlend  @ 001793c0
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


// V_CalcShake  @ 0017a020
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void V_CalcShake(void)

{
  anon_struct_52_9_e67e5413 *paVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  float fVar8;
  double dVar9;
  float local_28;
  
                    /* Unresolved local var: float frametime@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float fraction@[???]
                       Unresolved local var: float freq@[???] */
  (*g_engdstAddrs.V_CalcShake)();
  lVar2 = (longdouble)cl.time;
  lVar3 = (longdouble)gVShake.time;
  if (lVar2 <= lVar3) {
    lVar4 = (longdouble)gVShake.duration;
    lVar7 = (longdouble)0;
    if (((lVar7 < lVar4) && (lVar5 = (longdouble)gVShake.amplitude, lVar7 < lVar5)) &&
       (lVar6 = (longdouble)gVShake.frequency, lVar7 < lVar6)) {
      lVar7 = lVar2 - (longdouble)cl.oldtime;
      if ((longdouble)gVShake.nextShake < lVar2) {
        gVShake.nextShake = (float)(lVar2 + lVar4 / lVar6);
        paVar1 = &gVShake;
        while( true ) {
          fVar8 = RandomFloat((float)-lVar5,(float)lVar5);
          paVar1->offset[0] = fVar8;
          if (&paVar1->duration == (float *)0xf88dec) break;
          lVar5 = (longdouble)gVShake.amplitude;
          paVar1 = (anon_struct_52_9_e67e5413 *)&paVar1->duration;
        }
        local_28 = RandomFloat(-gVShake.amplitude * 0.25,gVShake.amplitude * 0.25);
        lVar2 = (longdouble)cl.time;
        lVar3 = (longdouble)gVShake.time;
        lVar4 = (longdouble)gVShake.duration;
        lVar6 = (longdouble)gVShake.frequency;
        lVar5 = (longdouble)gVShake.amplitude;
      }
      else {
        local_28 = gVShake.angle;
      }
      fVar8 = (float)((lVar2 - lVar3) / lVar4);
      if (fVar8 == 0.0) {
        lVar3 = (longdouble)0;
      }
      else {
        lVar3 = (lVar6 / (longdouble)fVar8) * lVar6;
      }
      gVShake.angle = local_28;
      dVar9 = sin((double)(lVar2 * lVar3));
      fVar8 = fVar8 * fVar8 * (float)dVar9;
      gVShake.amplitude =
           (float)lVar5 - ((float)lVar7 / ((float)lVar6 * (float)lVar4)) * (float)lVar5;
      gVShake.appliedOffset[0] = gVShake.offset[0] * fVar8;
      gVShake.appliedOffset[1] = gVShake.offset[1] * fVar8;
      gVShake.appliedOffset[2] = gVShake.offset[2] * fVar8;
      gVShake.appliedAngle = fVar8 * local_28;
      return;
    }
  }
  if (lVar3 == (longdouble)0) {
    return;
  }
  gVShake.time = 0.0;
  gVShake.appliedOffset[0] = 0.0;
  gVShake.appliedOffset[1] = 0.0;
  gVShake.appliedOffset[2] = 0.0;
  gVShake.appliedAngle = 0.0;
  return;
}


// V_CheckGamma  @ 001792e0
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


// V_FadeAlpha  @ 0017a4e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int V_FadeAlpha(void)

{
  uint uVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  
                    /* Unresolved local var: int alpha@[???] */
  lVar3 = (longdouble)cl.time;
  if ((lVar3 <= (longdouble)cl.sf.fadeReset) || (lVar3 <= (longdouble)cl.sf.fadeEnd)) {
    if ((cl.sf.fadeFlags & 4U) != 0) goto LAB_0017a512;
    if ((cl.sf.fadeFlags & 1U) == 0) {
      lVar3 = ((longdouble)cl.sf.fadeEnd - lVar3) * (longdouble)cl.sf.fadeSpeed;
      goto LAB_0017a55d;
    }
    lVar4 = (longdouble)cl.sf.fadeEnd;
  }
  else {
    if ((cl.sf.fadeFlags & 4U) == 0) {
      return 0;
    }
LAB_0017a512:
    if (((cl.sf.fadeFlags & 1U) == 0) || (lVar4 = (longdouble)cl.sf.fadeTotalEnd, lVar4 <= lVar3)) {
      cl.sf.fadeEnd = (float)(lVar3 + (longdouble)0.1);
      return (uint)cl.sf.fadealpha;
    }
  }
  lVar3 = (longdouble)cl.sf.fadealpha + (lVar4 - lVar3) * (longdouble)cl.sf.fadeSpeed;
LAB_0017a55d:
  uVar1 = (uint)cl.sf.fadealpha;
  iVar2 = (int)lVar3;
  if ((iVar2 <= (int)uVar1) && (uVar1 = 0, -1 < iVar2)) {
    return iVar2;
  }
  return uVar1;
}


// V_GetRefParams  @ 00179840
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


// V_Init  @ 0017a5c0
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


// V_InitLevel  @ 0017a640
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void V_InitLevel(void)

{
  Q_memset(&gVShake,0,0x34);
  if (v_dark.value != 0.0) {
    cl.sf.fadeReset = (float)cl.time + 5.0;
    cl.sf.fadeb = '\0';
    cl.sf.fadeg = '\0';
    cl.sf.fader = '\0';
    cl.sf.fadeEnd = cl.sf.fadeReset + 5.0;
    cl.sf.fadealpha = 0xff;
    cl.sf.fadeFlags = 0;
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


// V_RenderView  @ 00179a50
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
        local_fc.nextView = 0;
        cl.viewent.curstate.angles[1] = local_fc.viewangles[1];
        cl.viewent.curstate.angles[2] = local_fc.viewangles[2];
        cl.viewent.curstate.angles[0] = -local_fc.viewangles[0];
        cl.viewent.latched.prevangles[0] = cl.viewent.curstate.angles[0];
        cl.viewent.latched.prevangles[1] = cl.viewent.curstate.angles[1];
        cl.viewent.latched.prevangles[2] = cl.viewent.curstate.angles[2];
        cl.viewent.angles[0] = cl.viewent.curstate.angles[0];
        cl.viewent.angles[1] = cl.viewent.curstate.angles[1];
        cl.viewent.angles[2] = cl.viewent.curstate.angles[2];
      }
      r_refdef.vieworg[0] = local_fc.vieworg[0];
      r_refdef.vieworg[1] = local_fc.vieworg[1];
      r_refdef.vieworg[2] = local_fc.vieworg[2];
      forward[0] = local_fc.forward[0];
      forward[1] = local_fc.forward[1];
      forward[2] = local_fc.forward[2];
      right[0] = local_fc.right[0];
      right[1] = local_fc.right[1];
      r_refdef.viewangles[0] = local_fc.viewangles[0];
      right[2] = local_fc.right[2];
      r_refdef.viewangles[1] = local_fc.viewangles[1];
      up[0] = local_fc.up[0];
      r_refdef.viewangles[2] = local_fc.viewangles[2];
      up[1] = local_fc.up[1];
      up[2] = local_fc.up[2];
      cl.simvel[0] = local_fc.simvel[0];
      cl.simvel[1] = local_fc.simvel[1];
      cl.simvel[2] = local_fc.simvel[2];
      cl.simorg[0] = local_fc.simorg[0];
      cl.simorg[1] = local_fc.simorg[1];
      cl.simorg[2] = local_fc.simorg[2];
      cl.viewangles[0] = local_fc.cl_viewangles[0];
      cl.viewangles[1] = local_fc.cl_viewangles[1];
      cl.viewangles[2] = local_fc.cl_viewangles[2];
      cl.crosshairangle[0] = local_fc.crosshairangle[0];
      cl.crosshairangle[1] = local_fc.crosshairangle[1];
      cl.crosshairangle[2] = local_fc.crosshairangle[2];
      cl.punchangle[0] = local_fc.punchangle[0];
      cl.punchangle[1] = local_fc.punchangle[1];
      cl.punchangle[2] = local_fc.punchangle[2];
      cl.viewheight[0] = local_fc.viewheight[0];
      cl.viewheight[1] = local_fc.viewheight[1];
      cl.viewheight[2] = local_fc.viewheight[2];
      r_refdef.vrect.x = local_fc.viewport[0];
      r_refdef.vrect.y = local_fc.viewport[1];
      r_refdef.vrect.width = local_fc.viewport[2];
      r_refdef.vrect.height = local_fc.viewport[3];
      r_refdef.onlyClientDraws = local_fc.onlyClientDraw;
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
      if (local_fc.onlyClientDraw == false) {
        r_soundOrigin[0] = r_origin[0];
        r_playerViewportAngles[0] = local_fc.viewangles[0];
        r_soundOrigin[1] = r_origin[1];
        r_playerViewportAngles[1] = local_fc.viewangles[1];
        r_playerViewportAngles[2] = local_fc.viewangles[2];
        r_soundOrigin[2] = r_origin[2];
      }
      iVar1 = iVar1 + 1;
    } while (local_fc.nextView != 0);
    return;
  }
  return;
}


// V_ScreenFade  @ 0017a390
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


// V_ScreenShake  @ 0017a300
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


// V_SetRefParams  @ 00179530
void V_SetRefParams(ref_params_t *pparams)

{
  float fVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  vec_t vVar5;
  vec_t vVar6;
  vec_t vVar7;
  vec_t vVar8;
  vec_t vVar9;
  int iVar10;
  vec_t vVar11;
  
  Q_memset(pparams,0,0xe8);
  vVar8 = forward[1];
  vVar3 = forward[0];
  pparams->vieworg[0] = r_refdef.vieworg[0];
  vVar9 = forward[2];
  pparams->vieworg[1] = r_refdef.vieworg[1];
  vVar5 = right[0];
  pparams->vieworg[2] = r_refdef.vieworg[2];
  vVar6 = right[1];
  pparams->viewangles[0] = r_refdef.viewangles[0];
  vVar7 = right[2];
  pparams->viewangles[1] = r_refdef.viewangles[1];
  vVar11 = r_refdef.viewangles[2];
  vVar2 = up[0];
  pparams->forward[0] = vVar3;
  vVar4 = up[2];
  pparams->viewangles[2] = vVar11;
  vVar3 = up[1];
  pparams->forward[1] = vVar8;
  pparams->forward[2] = vVar9;
  pparams->right[0] = vVar5;
  pparams->right[1] = vVar6;
  pparams->right[2] = vVar7;
  pparams->up[0] = vVar2;
  pparams->up[1] = vVar3;
  pparams->up[2] = vVar4;
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
  fVar1 = scr_viewsize.value;
  pparams->cl_viewangles[0] = cl.viewangles[0];
  pparams->cl_viewangles[1] = cl.viewangles[1];
  pparams->cl_viewangles[2] = cl.viewangles[2];
  pparams->health = cl.stats[0];
  pparams->crosshairangle[0] = cl.crosshairangle[0];
  pparams->crosshairangle[1] = cl.crosshairangle[1];
  vVar2 = cl.crosshairangle[2];
  pparams->viewsize = fVar1;
  pparams->crosshairangle[2] = vVar2;
  pparams->punchangle[0] = cl.punchangle[0];
  pparams->punchangle[1] = cl.punchangle[1];
  pparams->punchangle[2] = cl.punchangle[2];
  pparams->maxclients = cl.maxclients;
  pparams->viewentity = cl.viewentity;
  pparams->playernum = cl.playernum;
  pparams->max_entities = cl.max_edicts;
  pparams->demoplayback = cls.demoplayback;
  pparams->cmd = &cl.cmd;
  pparams->movevars = &movevars;
  pparams->hardware = 1;
  iVar10 = cl.pushmsec;
  pparams->onlyClientDraw = 0;
  pparams->smoothing = iVar10;
  pparams->viewport[0] = 0;
  pparams->viewport[1] = 0;
  pparams->viewport[2] = vid.width;
  pparams->viewport[3] = vid.height;
  pparams->nextView = 0;
  return;
}


// V_UTF8ToUChar32  @ 001c8fe0
qboolean V_UTF8ToUChar32(char *pUTF8_,uchar32 *uValueOut)

{
  uint uVar1;
  uint uVar2;
  qboolean qVar3;
  int iVar4;
  uint uVar5;
  
                    /* Unresolved local var: bool bError@[???] */
                    /* Unresolved local var: uint8 * pUTF8@[???]
                       Unresolved local var: int nBytes@[???]
                       Unresolved local var: uint32 uValue@[???]
                       Unresolved local var: uint32 uMinValue@[???] */
  uVar2 = (uint)(byte)*pUTF8_;
  if (uVar2 < 0x80) {
LAB_001c90e0:
    qVar3 = 0;
  }
  else {
    if ((uVar2 - 0xc0 < 0x38) && ((pUTF8_[1] & 0xc0U) == 0x80)) {
      uVar2 = uVar2 * 0x40 + -0x3080 + (uint)(byte)pUTF8_[1];
      if ((uVar2 & 0x800) == 0) {
        uVar5 = 0x80;
        goto LAB_001c9155;
      }
      if ((pUTF8_[2] & 0xc0U) == 0x80) {
        iVar4 = (uint)(byte)pUTF8_[2] + uVar2 * 0x40;
        uVar2 = iVar4 - 0x20080;
        if ((uVar2 & 0x10000) == 0) {
          uVar1 = iVar4 - 0x2d880;
          uVar5 = 0x800;
          if ((((0x3ff < uVar1) || (pUTF8_[3] != -0x13)) || (0xf < (byte)(pUTF8_[4] + 0x50U))) ||
             ((pUTF8_[5] & 0xc0U) != 0x80)) goto LAB_001c9155;
          uVar2 = (uint)(byte)(pUTF8_[4] + 0x50U) * 0x40 + 0xff80 + (uint)(byte)pUTF8_[5] +
                  uVar1 * 0x400;
LAB_001c90a0:
          if (((0x7ff < uVar2 - 0xd800) && (uVar2 < 0x110000)) &&
             (((ushort)uVar2 < 0xfffe && (0x1f < uVar2 - 0xfdd0)))) goto LAB_001c90e0;
        }
        else if ((pUTF8_[3] & 0xc0U) == 0x80) {
          uVar5 = 0x10000;
          uVar2 = uVar2 * 0x40 + -0x400080 + (uint)(byte)pUTF8_[3];
LAB_001c9155:
          if (uVar5 <= uVar2) goto LAB_001c90a0;
        }
      }
    }
    qVar3 = 1;
    uVar2 = 0x3f;
  }
  *uValueOut = uVar2;
  return qVar3;
}


// V_UpdatePalette  @ 001793e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void V_UpdatePalette(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean newFlag@[???]
                       Unresolved local var: float r@[???]
                       Unresolved local var: float g@[???]
                       Unresolved local var: float b@[???]
                       Unresolved local var: float a@[???]
                       Unresolved local var: int ir@[???]
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
    vid.recalc_refdef = 1;
                    /* Unresolved local var: float r@[???]
                       Unresolved local var: float g@[???]
                       Unresolved local var: float b@[???]
                       Unresolved local var: float a@[???] */
    v_blend[0] = 0.0;
    v_blend[1] = 0.0;
    v_blend[2] = 0.0;
    v_blend[3] = 0.0;
    iVar3 = 0;
    do {
      iVar2 = (int)((float)iVar3 + 0.0);
      if (0xff < iVar2) {
        iVar2 = 0xff;
      }
      iVar4 = iVar3 + 1;
      bVar1 = texgammatable[iVar2];
      ramps[0][iVar3] = bVar1;
      ramps[1][iVar3] = bVar1;
      ramps[2][iVar3] = bVar1;
      iVar3 = iVar4;
    } while (iVar4 != 0x100);
  }
  return;
}


