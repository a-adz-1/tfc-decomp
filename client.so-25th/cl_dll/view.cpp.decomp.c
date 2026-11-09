// Ghidra decompilation of functions from cl_dll/view.cpp
// 27 functions, ordered by original source line

// V_CalcBob  @ 00082c70  (line 165)

float V_CalcBob(ref_params_s *pparams)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  
                    /* Unresolved local var: float cycle@[???]
                       Unresolved local var: Vector vel@[???] */
  if ((pparams->onground != -1) && (fVar1 = pparams->time, fVar1 != V_CalcBob::lasttime)) {
    fVar3 = pparams->frametime + (float)V_CalcBob::bobtime;
    V_CalcBob::bobtime = (double)fVar3;
    fVar2 = cl_bobcycle->value;
    fVar2 = (fVar3 - (float)(int)(fVar3 / fVar2) * fVar2) / fVar2;
    fVar3 = cl_bobup->value;
    if (fVar3 <= fVar2) {
      fVar3 = ((fVar2 - fVar3) * 3.1415927) / (1.0 - fVar3) + 3.1415927;
    }
    else {
      fVar3 = (fVar2 * 3.1415927) / fVar3;
    }
    fVar2 = pparams->simvel[1] * pparams->simvel[1] + pparams->simvel[0] * pparams->simvel[0];
    fVar4 = SQRT(fVar2);
    V_CalcBob::lasttime = fVar1;
    if (NAN(fVar4)) {
      dVar5 = sqrt((double)fVar2);
      fVar4 = (float)dVar5;
    }
    fVar4 = fVar4 * cl_bob->value;
    dVar5 = sin((double)fVar3);
    fVar1 = fVar4 * 0.3 + fVar4 * 0.7 * (float)dVar5;
    if (4.0 < fVar1) {
      V_CalcBob::bob = 4.0;
    }
    else {
      V_CalcBob::bob = -7.0;
      if (-7.0 <= fVar1) {
        V_CalcBob::bob = fVar1;
      }
    }
    return V_CalcBob::bob;
  }
  return V_CalcBob::bob;
}


// V_CalcRoll  @ 00082de0  (line 215)

float V_CalcRoll(Vector angles,Vector velocity,float rollangle,float rollspeed)

{
  float fVar1;
  float fVar2;
  float local_30 [3];
  float local_24;
  float local_20;
  float local_1c;
  float local_18 [5];
  
                    /* Unresolved local var: float sign@[???]
                       Unresolved local var: float side@[???]
                       Unresolved local var: float value@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???] */
  (*gEngfuncs.pfnAngleVectors)((float *)angles.x,local_30,&local_24,local_18);
  fVar1 = *(float *)((int)angles.y + 8) * local_1c +
          *(float *)((int)angles.y + 4) * local_20 + *(float *)angles.y * local_24;
  fVar2 = -1.0;
  if (0.0 <= fVar1) {
    fVar2 = 1.0;
  }
  if (fVar1 <= 0.0) {
    fVar1 = 0.0 - fVar1;
  }
  if (fVar1 < velocity.x) {
    angles.z = (fVar1 * angles.z) / velocity.x;
  }
  return fVar2 * angles.z;
}


// V_StartPitchDrift  @ 00082c00  (line 250)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void V_StartPitchDrift(void)

{
  double dVar1;
  longdouble extraout_ST0;
  
  dVar1 = pd.laststop;
  (*gEngfuncs.GetClientTime)();
  if (((longdouble)dVar1 != extraout_ST0) && ((pd.nodrift != 0 || (pd.pitchvel == 0.0)))) {
    pd.driftmove = 0.0;
    pd.pitchvel = v_centerspeed->value;
    pd.nodrift = 0;
  }
  return;
}


// V_StopPitchDrift  @ 00082e70  (line 265)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void V_StopPitchDrift(void)

{
  longdouble extraout_ST0;
  
  (*gEngfuncs.GetClientTime)();
  pd.nodrift = 1;
  pd.pitchvel = 0.0;
  pd.laststop = (double)extraout_ST0;
  return;
}


// V_DriftPitch  @ 00082ea0  (line 282)

void V_DriftPitch(ref_params_s *pparams)

{
  float fVar1;
  float fVar2;
  double dVar3;
  float fVar4;
  int iVar5;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: float delta@[???]
                       Unresolved local var: float move@[???] */
  iVar5 = (*gEngfuncs.IsNoClipping)();
  dVar3 = pd.laststop;
  if ((((iVar5 == 0) && (pparams->onground != 0)) && (pparams->demoplayback == 0)) &&
     (pparams->spectator == 0)) {
                    /* Unresolved local var: float delta@[???]
                       Unresolved local var: float move@[???] */
    if (pd.nodrift != 0) {
      if (v_centermove->value <= 0.0) {
        return;
      }
      if (((byte)in_mlook.state & 1) != 0) {
        return;
      }
      fVar1 = pparams->cmd->forwardmove;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      fVar4 = 0.0;
      if (cl_forwardspeed->value <= fVar1) {
        fVar4 = pd.driftmove + pparams->frametime;
      }
      pd.driftmove = fVar4;
      if (pd.driftmove <= v_centermove->value) {
        return;
      }
      (*gEngfuncs.GetClientTime)();
      if ((longdouble)dVar3 == extraout_ST0) {
        return;
      }
      if ((pd.nodrift == 0) && (pd.pitchvel != 0.0)) {
        return;
      }
      pd.pitchvel = v_centerspeed->value;
      pd.nodrift = 0;
      pd.driftmove = 0.0;
      return;
    }
    fVar1 = pparams->cl_viewangles[0];
    fVar4 = pparams->idealpitch - fVar1;
    if (fVar4 != 0.0) {
      fVar2 = pparams->frametime * pd.pitchvel;
      pd.pitchvel = (pparams->frametime * 0.25 + 1.0) * pd.pitchvel;
      if (0.0 < fVar4) {
        if (fVar4 < fVar2) {
          pd.pitchvel = 0.0;
          fVar2 = fVar4;
        }
        pparams->cl_viewangles[0] = fVar2 + fVar1;
        return;
      }
      if (0.0 <= fVar4) {
        return;
      }
      if (-fVar4 < fVar2) {
        pd.pitchvel = 0.0;
        fVar2 = -fVar4;
      }
      pparams->cl_viewangles[0] = fVar1 - fVar2;
      return;
    }
  }
  else {
    pd.driftmove = 0.0;
  }
  pd.pitchvel = 0.0;
  return;
}


// V_CalcGunAngle  @ 000830c0  (line 363)

void V_CalcGunAngle(ref_params_s *pparams)

{
  float fVar1;
  float fVar2;
  float fVar3;
  cl_entity_s *pcVar4;
  double dVar5;
  
                    /* Unresolved local var: cl_entity_t * viewent@[???] */
  pcVar4 = (*gEngfuncs.GetViewModel)();
  if (pcVar4 != (cl_entity_s *)0x0) {
    fVar1 = pparams->viewangles[1] + pparams->crosshairangle[1];
    (pcVar4->angles).y = fVar1;
    fVar3 = v_idlescale;
    fVar2 = pparams->crosshairangle[0] * 0.25 + -pparams->viewangles[0];
    (pcVar4->angles).x = fVar2;
    dVar5 = sin((double)(pparams->time * v_iroll_cycle.value));
    (pcVar4->angles).z = (pcVar4->angles).z - (float)dVar5 * fVar3 * v_iroll_level.value;
    dVar5 = sin((double)(pparams->time * v_ipitch_cycle.value));
    (pcVar4->angles).x = fVar2 - (float)dVar5 * fVar3 * v_ipitch_level.value * 0.5;
    dVar5 = sin((double)(pparams->time * v_iyaw_cycle.value));
    (pcVar4->angles).y = fVar1 - (float)dVar5 * fVar3 * v_iyaw_level.value;
  }
  return;
}


// V_AddIdle  @ 000831a0  (line 387)

void V_AddIdle(ref_params_s *pparams)

{
  float fVar1;
  float fVar2;
  double dVar3;
  
  fVar2 = v_idlescale;
  fVar1 = pparams->time;
  dVar3 = sin((double)(v_iroll_cycle.value * fVar1));
  pparams->viewangles[2] = (float)dVar3 * fVar2 * v_iroll_level.value + pparams->viewangles[2];
  dVar3 = sin((double)(fVar1 * v_ipitch_cycle.value));
  pparams->viewangles[0] = (float)dVar3 * fVar2 * v_ipitch_level.value + pparams->viewangles[0];
  dVar3 = sin((double)(fVar1 * v_iyaw_cycle.value));
  pparams->viewangles[1] = (float)dVar3 * fVar2 * v_iyaw_level.value + pparams->viewangles[1];
  return;
}


// V_CalcViewRoll  @ 00083230  (line 402)

void V_CalcViewRoll(ref_params_s *pparams)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  cl_entity_s *pcVar7;
  vec_t local_3c;
  vec_t local_38;
  vec_t local_34;
  float local_30 [3];
  float local_24;
  float local_20;
  float local_1c;
  float local_18 [5];
  
                    /* Unresolved local var: float side@[???]
                       Unresolved local var: cl_entity_t * viewentity@[???] */
  pcVar7 = (*gEngfuncs.GetEntityByIndex)(pparams->viewentity);
  if (pcVar7 != (cl_entity_s *)0x0) {
    local_3c = (pcVar7->angles).x;
    local_38 = (pcVar7->angles).y;
    local_34 = (pcVar7->angles).z;
    fVar1 = pparams->movevars->rollspeed;
                    /* Unresolved local var: float sign@[???]
                       Unresolved local var: float side@[???]
                       Unresolved local var: float value@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???] */
    fVar2 = pparams->movevars->rollangle;
    fVar3 = pparams->simvel[0];
    fVar4 = pparams->simvel[1];
    fVar5 = pparams->simvel[2];
    (*gEngfuncs.pfnAngleVectors)(&local_3c,local_30,&local_24,local_18);
    fVar3 = fVar5 * local_1c + fVar4 * local_20 + fVar3 * local_24;
    fVar4 = -1.0;
    if (0.0 <= fVar3) {
      fVar4 = 1.0;
    }
    if (fVar3 <= 0.0) {
      fVar3 = 0.0 - fVar3;
    }
    if (fVar3 < fVar1) {
      fVar2 = (fVar3 * fVar2) / fVar1;
    }
    iVar6 = pparams->health;
    pparams->viewangles[2] = pparams->viewangles[2] + fVar2 * fVar4;
    if ((iVar6 < 1) && (pparams->viewheight[2] != 0.0)) {
      pparams->viewangles[2] = 80.0;
      return;
    }
  }
  return;
}


// V_CalcIntermissionRefdef  @ 00083360  (line 431)

void V_CalcIntermissionRefdef(ref_params_s *pparams)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  cl_entity_s *pcVar6;
  int iVar7;
  double dVar8;
  
                    /* Unresolved local var: cl_entity_t * ent@[???]
                       Unresolved local var: cl_entity_t * view@[???]
                       Unresolved local var: float old@[???] */
  (*gEngfuncs.GetLocalPlayer)();
  pcVar6 = (*gEngfuncs.GetViewModel)();
  fVar1 = pparams->simorg[1];
  fVar2 = pparams->simorg[2];
  fVar3 = pparams->cl_viewangles[0];
  fVar4 = pparams->cl_viewangles[1];
  fVar5 = pparams->cl_viewangles[2];
  pparams->vieworg[0] = pparams->simorg[0];
  pparams->vieworg[1] = fVar1;
  pparams->vieworg[2] = fVar2;
  pparams->viewangles[0] = fVar3;
  pparams->viewangles[1] = fVar4;
  pparams->viewangles[2] = fVar5;
  pcVar6->model = (model_s *)0x0;
  fVar2 = v_idlescale;
  fVar1 = pparams->time;
  v_idlescale = 1.0;
  dVar8 = sin((double)(v_iroll_cycle.value * fVar1));
  pparams->viewangles[2] = (float)dVar8 * v_iroll_level.value + pparams->viewangles[2];
  dVar8 = sin((double)(fVar1 * v_ipitch_cycle.value));
  pparams->viewangles[0] = (float)dVar8 * v_ipitch_level.value + pparams->viewangles[0];
  dVar8 = sin((double)(fVar1 * v_iyaw_cycle.value));
  pparams->viewangles[1] = (float)dVar8 * v_iyaw_level.value + pparams->viewangles[1];
  iVar7 = (*gEngfuncs.IsSpectateOnly)();
  if (iVar7 == 0) {
    v_angles.x = pparams->viewangles[0];
    v_angles.y = pparams->viewangles[1];
    v_angles.z = pparams->viewangles[2];
  }
  else {
    pparams->vieworg[0] = gHUD.m_Spectator.m_cameraOrigin.x;
    pparams->vieworg[1] = gHUD.m_Spectator.m_cameraOrigin.y;
    pparams->vieworg[2] = gHUD.m_Spectator.m_cameraOrigin.z;
    v_angles.x = gHUD.m_Spectator.m_cameraAngles.x;
    pparams->viewangles[0] = gHUD.m_Spectator.m_cameraAngles.x;
    v_angles.y = gHUD.m_Spectator.m_cameraAngles.y;
    pparams->viewangles[1] = gHUD.m_Spectator.m_cameraAngles.y;
    v_angles.z = gHUD.m_Spectator.m_cameraAngles.z;
    pparams->viewangles[2] = gHUD.m_Spectator.m_cameraAngles.z;
  }
  v_idlescale = fVar2;
  v_cl_angles.y = pparams->cl_viewangles[1];
  v_cl_angles.z = pparams->cl_viewangles[2];
  v_cl_angles.x = pparams->cl_viewangles[0];
  v_origin.x = pparams->vieworg[0];
  v_origin.y = pparams->vieworg[1];
  v_origin.z = pparams->vieworg[2];
  return;
}


// V_CalcNormalRefdef  @ 00083520  (line 488)

void V_CalcNormalRefdef(ref_params_s *pparams)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  cvar_t *pcVar4;
  cvar_t *pcVar5;
  cvar_t *pcVar6;
  int iVar7;
  cl_entity_s *pcVar8;
  int iVar9;
  uint uVar10;
  cl_entity_s *pcVar11;
  uint uVar12;
  int iVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  double dVar18;
  float local_90;
  cl_entity_s *local_84;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c [3];
  float local_40 [3];
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: cl_entity_t * ent@[???]
                       Unresolved local var: cl_entity_t * view@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: float bob@[???]
                       Unresolved local var: float waterOffset@[???]
                       Unresolved local var: Vector camAngles@[???]
                       Unresolved local var: Vector camForward@[???]
                       Unresolved local var: Vector camRight@[???]
                       Unresolved local var: Vector camUp@[???]
                       Unresolved local var: cl_entity_t * pwater@[???] */
  V_DriftPitch(pparams);
  iVar7 = (*gEngfuncs.IsSpectateOnly)();
  if (iVar7 == 0) {
    local_84 = (*gEngfuncs.GetLocalPlayer)();
  }
  else {
    local_84 = (*gEngfuncs.GetEntityByIndex)(g_iUser2);
  }
  pcVar8 = (*gEngfuncs.GetViewModel)();
  fVar15 = V_CalcBob(pparams);
  fVar17 = pparams->cl_viewangles[1];
  fVar16 = pparams->cl_viewangles[2];
  pparams->viewangles[0] = pparams->cl_viewangles[0];
  pparams->viewangles[1] = fVar17;
  pparams->viewangles[2] = fVar16;
  fVar17 = pparams->simorg[2];
  pparams->vieworg[0] = pparams->simorg[0] + pparams->viewheight[0];
  pparams->vieworg[1] = pparams->viewheight[1] + pparams->simorg[1];
  pparams->vieworg[2] = fVar15 + fVar17 + pparams->viewheight[2];
  (*gEngfuncs.V_CalcShake)();
  (*gEngfuncs.V_ApplyShake)(pparams->vieworg,pparams->viewangles,1.0);
  iVar7 = pparams->waterlevel;
  fVar17 = pparams->vieworg[0] + 0.03125;
  pparams->vieworg[0] = fVar17;
  fVar16 = pparams->vieworg[1] + 0.03125;
  pparams->vieworg[1] = fVar16;
  fVar14 = pparams->vieworg[2] + 0.03125;
  pparams->vieworg[2] = fVar14;
  if (iVar7 < 2) {
    local_90 = 0.0;
  }
  else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int contents@[???]
                       Unresolved local var: int waterDist@[???]
                       Unresolved local var: int waterEntity@[???]
                       Unresolved local var: Vector point@[???] */
    iVar13 = (int)cl_waterdist->value;
    if (pparams->hardware != 0) {
      iVar7 = (*gEngfuncs.PM_WaterEntity)(pparams->simorg);
      if ((((-1 < iVar7) && (iVar7 < pparams->max_entities)) &&
          (pcVar11 = (*gEngfuncs.GetEntityByIndex)(iVar7), pcVar11 != (cl_entity_s *)0x0)) &&
         (pcVar11->model != (model_s *)0x0)) {
        iVar13 = (int)((float)iVar13 + (pcVar11->curstate).scale * 16.0);
      }
      fVar17 = pparams->vieworg[0];
      fVar16 = pparams->vieworg[1];
      fVar14 = pparams->vieworg[2];
      iVar7 = pparams->waterlevel;
    }
    local_28 = fVar17;
    local_24 = fVar16;
    if (iVar7 == 2) {
      local_20 = fVar14 - (float)iVar13;
      if (0 < iVar13) {
        iVar7 = 0;
        do {
          iVar9 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
          if (-3 < iVar9) {
            fVar14 = pparams->vieworg[2];
            goto LAB_0008415e;
          }
          iVar7 = iVar7 + 1;
          local_20 = local_20 + 1.0;
        } while (iVar13 != iVar7);
        fVar14 = pparams->vieworg[2];
      }
LAB_0008415e:
      local_90 = (local_20 + (float)iVar13) - fVar14;
    }
    else {
      local_20 = (float)iVar13 + fVar14;
      if (0 < iVar13) {
        iVar7 = 0;
        do {
          iVar9 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
          if (iVar9 < -2) {
            fVar14 = pparams->vieworg[2];
            goto LAB_000836b2;
          }
          iVar7 = iVar7 + 1;
          local_20 = local_20 - 1.0;
        } while (iVar13 != iVar7);
        fVar14 = pparams->vieworg[2];
      }
LAB_000836b2:
      local_90 = (local_20 - (float)iVar13) - fVar14;
    }
  }
  pparams->vieworg[2] = fVar14 + local_90;
  V_CalcViewRoll(pparams);
  fVar16 = v_idlescale;
  fVar17 = pparams->time;
  dVar18 = sin((double)(v_iroll_cycle.value * fVar17));
  pparams->viewangles[2] = (float)dVar18 * fVar16 * v_iroll_level.value + pparams->viewangles[2];
  dVar18 = sin((double)(fVar17 * v_ipitch_cycle.value));
  pparams->viewangles[0] = (float)dVar18 * fVar16 * v_ipitch_level.value + pparams->viewangles[0];
  dVar18 = sin((double)(fVar17 * v_iyaw_cycle.value));
  pparams->viewangles[1] = (float)dVar18 * fVar16 * v_iyaw_level.value + pparams->viewangles[1];
  local_70 = pparams->cl_viewangles[0];
  local_6c = pparams->cl_viewangles[1];
  local_68 = pparams->cl_viewangles[2];
  (*gEngfuncs.pfnAngleVectors)(&local_70,pparams->forward,pparams->right,pparams->up);
  if (pparams->maxclients < 2) {
    pparams->vieworg[0] =
         scr_ofsz->value * pparams->up[0] +
         scr_ofsx->value * pparams->forward[0] + pparams->right[0] * scr_ofsy->value +
         pparams->vieworg[0];
    pcVar6 = scr_ofsx;
    pcVar5 = scr_ofsy;
    pcVar4 = scr_ofsz;
    pparams->vieworg[1] =
         pparams->up[1] * scr_ofsz->value +
         pparams->forward[1] * scr_ofsx->value + pparams->right[1] * scr_ofsy->value +
         pparams->vieworg[1];
    pparams->vieworg[2] =
         pcVar4->value * pparams->up[2] +
         pcVar5->value * pparams->right[2] + pparams->forward[2] * pcVar6->value +
         pparams->vieworg[2];
  }
  iVar7 = CL_IsThirdPerson();
  if (iVar7 != 0) {
                    /* Unresolved local var: Vector ofs@[???] */
    local_20 = 0.0;
    local_24 = 0.0;
    local_28 = 0.0;
    CL_CameraOffset(&local_28);
    local_64 = local_28;
    local_60 = local_24;
    local_5c = 0.0;
    (*gEngfuncs.pfnAngleVectors)(&local_64,&local_58,local_4c,local_40);
    fVar17 = -local_20;
    pparams->vieworg[0] = local_58 * fVar17 + pparams->vieworg[0];
    pparams->vieworg[1] = local_54 * fVar17 + pparams->vieworg[1];
    pparams->vieworg[2] = fVar17 * local_50 + pparams->vieworg[2];
  }
  (pcVar8->angles).x = pparams->cl_viewangles[0];
  (pcVar8->angles).y = pparams->cl_viewangles[1];
  (pcVar8->angles).z = pparams->cl_viewangles[2];
  V_CalcGunAngle(pparams);
  fVar17 = pparams->simorg[0];
  (pcVar8->origin).x = fVar17;
  fVar16 = pparams->simorg[1];
  (pcVar8->origin).y = fVar16;
  local_90 = local_90 + pparams->simorg[2];
  (pcVar8->origin).z = local_90;
  (pcVar8->origin).x = fVar17 + pparams->viewheight[0];
  (pcVar8->origin).y = fVar16 + pparams->viewheight[1];
  (pcVar8->origin).z = local_90 + pparams->viewheight[2];
  (*gEngfuncs.V_ApplyShake)(&(pcVar8->origin).x,&(pcVar8->angles).x,0.9);
  fVar17 = fVar15 * 0.4;
  (pcVar8->origin).x = fVar17 * pparams->forward[0] + (pcVar8->origin).x;
  (pcVar8->origin).y = fVar17 * pparams->forward[1] + (pcVar8->origin).y;
  (pcVar8->origin).z = fVar17 * pparams->forward[2] + (pcVar8->origin).z;
  fVar17 = (pcVar8->origin).z;
  (pcVar8->angles).y = (pcVar8->angles).y - fVar15 * 0.5;
  (pcVar8->angles).z = (pcVar8->angles).z - fVar15;
  (pcVar8->angles).x = (pcVar8->angles).x - fVar15 * 0.3;
  fVar16 = (fVar17 + fVar15) - 1.0;
  (pcVar8->origin).z = fVar16;
  fVar17 = pparams->viewsize;
  if (fVar17 == 110.0) {
    (pcVar8->origin).z = fVar16 + 1.0;
  }
  else if (fVar17 == 100.0) {
    (pcVar8->origin).z = fVar16 + 2.0;
  }
  else if (fVar17 == 90.0) {
    (pcVar8->origin).z = fVar16 + 1.0;
  }
  else if (fVar17 == 80.0) {
    (pcVar8->origin).z = fVar16 + 0.5;
  }
  fVar17 = pparams->viewangles[1];
  fVar16 = pparams->punchangle[1];
  fVar14 = pparams->viewangles[2];
  fVar15 = pparams->punchangle[2];
  pparams->viewangles[0] = pparams->viewangles[0] + pparams->punchangle[0] + ev_punchangle.x;
  pparams->viewangles[1] = fVar17 + fVar16 + ev_punchangle.y;
  pparams->viewangles[2] = fVar14 + fVar15 + ev_punchangle.z;
  fVar17 = pparams->frametime;
                    /* Unresolved local var: float len@[???] */
  fVar16 = VectorNormalize(&ev_punchangle.x);
  fVar16 = fVar16 - (fVar16 * 0.5 + 10.0) * fVar17;
  fVar17 = 0.0;
  if (0.0 <= fVar16) {
    fVar17 = fVar16;
  }
  VectorScale(&ev_punchangle.x,fVar17,&ev_punchangle.x);
  if ((pparams->smoothing == 0) && (pparams->onground != 0)) {
    local_20 = pparams->simorg[2];
    fVar17 = local_20;
    if (0.0 < local_20 - V_CalcNormalRefdef::oldz) {
                    /* Unresolved local var: float steptime@[???] */
      fVar17 = pparams->time - V_CalcNormalRefdef::lasttime;
      if (fVar17 < 0.0) {
        fVar17 = 0.0;
      }
      else {
        fVar17 = fVar17 * 150.0;
      }
      fVar17 = fVar17 + V_CalcNormalRefdef::oldz;
      V_CalcNormalRefdef::oldz = local_20;
      if (fVar17 <= local_20) {
        V_CalcNormalRefdef::oldz = fVar17;
      }
      if (18.0 < local_20 - V_CalcNormalRefdef::oldz) {
        V_CalcNormalRefdef::oldz = local_20 - 18.0;
      }
      local_20 = V_CalcNormalRefdef::oldz - local_20;
      pparams->vieworg[2] = pparams->vieworg[2] + local_20;
      (pcVar8->origin).z = local_20 + (pcVar8->origin).z;
      local_20 = pparams->simorg[2];
      fVar17 = V_CalcNormalRefdef::oldz;
    }
  }
  else {
    local_20 = pparams->simorg[2];
    fVar17 = local_20;
  }
  V_CalcNormalRefdef::oldz = fVar17;
                    /* Unresolved local var: Vector delta@[???] */
  local_28 = pparams->simorg[0] - V_CalcNormalRefdef::lexical_block_7::lastorg[0];
  local_24 = pparams->simorg[1] - V_CalcNormalRefdef::lexical_block_7::lastorg[1];
  local_20 = local_20 - V_CalcNormalRefdef::lexical_block_7::lastorg[2];
  fVar17 = Length(&local_28);
  if (fVar17 != 0.0) {
    uVar12 = V_CalcNormalRefdef::ViewInterp.CurrentOrigin & 0x3f;
    V_CalcNormalRefdef::ViewInterp.Origins[uVar12][0] = pparams->simorg[0];
    V_CalcNormalRefdef::ViewInterp.Origins[uVar12][1] = pparams->simorg[1];
    V_CalcNormalRefdef::ViewInterp.Origins[uVar12][2] = pparams->simorg[2];
    V_CalcNormalRefdef::ViewInterp.CurrentOrigin = V_CalcNormalRefdef::ViewInterp.CurrentOrigin + 1;
    V_CalcNormalRefdef::ViewInterp.OriginTime[uVar12] = pparams->time;
    V_CalcNormalRefdef::lexical_block_7::lastorg[0] = pparams->simorg[0];
    V_CalcNormalRefdef::lexical_block_7::lastorg[1] = pparams->simorg[1];
    V_CalcNormalRefdef::lexical_block_7::lastorg[2] = pparams->simorg[2];
  }
  if (((cl_vsmoothing != (cvar_t *)0x0) && (fVar17 = cl_vsmoothing->value, fVar17 != 0.0)) &&
     ((pparams->smoothing != 0 && (1 < pparams->maxclients)))) {
                    /* Unresolved local var: int foundidx@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float t@[???] */
    if (fVar17 < 0.0) {
      (*gEngfuncs.Cvar_SetValue)("cl_vsmoothing",0.0);
      fVar17 = cl_vsmoothing->value;
    }
    fVar17 = pparams->time - fVar17;
    uVar12 = V_CalcNormalRefdef::ViewInterp.CurrentOrigin - 2;
    do {
      uVar10 = uVar12 & 0x3f;
      fVar16 = V_CalcNormalRefdef::ViewInterp.OriginTime[uVar10];
      if (fVar16 <= fVar17) {
        if (fVar16 != 0.0) {
                    /* Unresolved local var: Vector delta@[???]
                       Unresolved local var: double frac@[???]
                       Unresolved local var: double dt@[???]
                       Unresolved local var: Vector neworg@[???] */
          uVar12 = uVar12 + 1 & 0x3f;
          fVar14 = V_CalcNormalRefdef::ViewInterp.OriginTime[uVar12] - fVar16;
          if (0.0 < fVar14) {
            fVar14 = (fVar17 - fVar16) / fVar14;
            if (1.0 <= fVar14) {
              fVar14 = 1.0;
            }
            local_34 = V_CalcNormalRefdef::ViewInterp.Origins[uVar12][0] -
                       V_CalcNormalRefdef::ViewInterp.Origins[uVar10][0];
            local_30 = V_CalcNormalRefdef::ViewInterp.Origins[uVar12][1] -
                       V_CalcNormalRefdef::ViewInterp.Origins[uVar10][1];
            local_2c = V_CalcNormalRefdef::ViewInterp.Origins[uVar12][2] -
                       V_CalcNormalRefdef::ViewInterp.Origins[uVar10][2];
            VectorMA(V_CalcNormalRefdef::ViewInterp.Origins[uVar10],fVar14,&local_34,&local_28);
            fVar17 = Length(&local_34);
            if (fVar17 < 64.0) {
              fVar17 = local_28 - pparams->simorg[0];
              fVar16 = local_24 - pparams->simorg[1];
              fVar14 = local_20 - pparams->simorg[2];
              pparams->simorg[0] = pparams->simorg[0] + fVar17;
              pparams->simorg[1] = pparams->simorg[1] + fVar16;
              pparams->simorg[2] = pparams->simorg[2] + fVar14;
              pparams->vieworg[0] = pparams->vieworg[0] + fVar17;
              pparams->vieworg[1] = pparams->vieworg[1] + fVar16;
              pparams->vieworg[2] = pparams->vieworg[2] + fVar14;
              (pcVar8->origin).x = fVar17 + (pcVar8->origin).x;
              (pcVar8->origin).y = fVar16 + (pcVar8->origin).y;
              (pcVar8->origin).z = fVar14 + (pcVar8->origin).z;
            }
          }
        }
        break;
      }
      uVar12 = uVar12 - 1;
    } while (uVar12 != V_CalcNormalRefdef::ViewInterp.CurrentOrigin - 0x40U);
  }
  v_lastAngles.x = pparams->viewangles[0];
  v_lastAngles.y = pparams->viewangles[1];
  v_lastAngles.z = pparams->viewangles[2];
  v_angles.x = v_lastAngles.x;
  v_angles.y = v_lastAngles.y;
  v_angles.z = v_lastAngles.z;
  iVar7 = CL_IsThirdPerson();
  if (iVar7 != 0) {
                    /* Unresolved local var: float pitch@[???] */
    pparams->viewangles[0] = local_64;
    pparams->viewangles[1] = local_60;
    pparams->viewangles[2] = local_5c;
    if (local_64 <= 180.0) {
      fVar17 = local_64;
      if (local_64 < -180.0) {
        fVar17 = local_64 + 360.0;
      }
    }
    else {
      fVar17 = local_64 - 360.0;
    }
    fVar17 = fVar17 / -3.0;
    (local_84->angles).x = fVar17;
    (local_84->curstate).angles.x = fVar17;
    (local_84->prevstate).angles.x = fVar17;
    (local_84->latched).prevangles.x = fVar17;
  }
                    /* Unresolved local var: cl_entity_t * viewentity@[???] */
  if ((pparams->maxclients < pparams->viewentity) &&
     (pcVar11 = (*gEngfuncs.GetEntityByIndex)(pparams->viewentity), pcVar11 != (cl_entity_s *)0x0))
  {
    pparams->vieworg[0] = (pcVar11->origin).x;
    pparams->vieworg[1] = (pcVar11->origin).y;
    pparams->vieworg[2] = (pcVar11->origin).z;
    v_angles.x = (pcVar11->angles).x;
    pparams->viewangles[0] = v_angles.x;
    v_angles.y = (pcVar11->angles).y;
    pparams->viewangles[1] = v_angles.y;
    v_angles.z = (pcVar11->angles).z;
    pparams->viewangles[2] = v_angles.z;
  }
  vVar1 = (pcVar8->origin).x;
  (pcVar8->curstate).origin.x = vVar1;
  vVar2 = (pcVar8->origin).y;
  (pcVar8->curstate).origin.y = vVar2;
  vVar3 = (pcVar8->origin).z;
  (pcVar8->curstate).origin.z = vVar3;
  (pcVar8->latched).prevorigin.x = vVar1;
  (pcVar8->latched).prevorigin.y = vVar2;
  (pcVar8->latched).prevorigin.z = vVar3;
  vVar1 = (pcVar8->angles).x;
  (pcVar8->curstate).angles.x = vVar1;
  vVar2 = (pcVar8->angles).y;
  (pcVar8->curstate).angles.y = vVar2;
  vVar3 = (pcVar8->angles).z;
  (pcVar8->curstate).angles.z = vVar3;
  (pcVar8->latched).prevangles.x = vVar1;
  (pcVar8->latched).prevangles.y = vVar2;
  (pcVar8->latched).prevangles.z = vVar3;
  v_origin.x = pparams->vieworg[0];
  V_CalcNormalRefdef::lasttime = pparams->time;
  v_origin.y = pparams->vieworg[1];
  v_origin.z = pparams->vieworg[2];
  return;
}


// V_SmoothInterpolateAngles  @ 00084230  (line 842)

void V_SmoothInterpolateAngles
               (float *startAngle,float *endAngle,float *finalAngle,float degreesPerSec)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
                    /* Unresolved local var: float absd@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: float d@[???]
                       Unresolved local var: float threshhold@[???] */
  NormalizeAngles(startAngle);
  NormalizeAngles(endAngle);
                    /* Unresolved local var: int i@[???] */
  fVar1 = *startAngle;
  fVar2 = *endAngle - fVar1;
  if (180.0 < fVar2) {
    fVar2 = fVar2 - 360.0;
  }
  else if (fVar2 < -180.0) {
    fVar2 = fVar2 + 360.0;
  }
  fVar3 = fVar2;
  if (fVar2 <= 0.0) {
    fVar3 = 0.0 - fVar2;
  }
  if (fVar3 <= 0.01) {
LAB_00084328:
    *finalAngle = *endAngle;
  }
  else {
    fVar5 = v_frametime * degreesPerSec;
    if (fVar3 < degreesPerSec * 0.25) {
                    /* Unresolved local var: float h@[???] */
      fVar4 = fVar3 / (degreesPerSec * 0.25);
      fVar5 = fVar4 * fVar4 * fVar5;
    }
    if (fVar3 < fVar5) goto LAB_00084328;
    if (fVar2 <= 0.0) {
      *finalAngle = fVar1 - fVar5;
    }
    else {
      *finalAngle = fVar5 + fVar1;
    }
  }
  fVar1 = startAngle[1];
  fVar2 = endAngle[1] - fVar1;
  if (180.0 < fVar2) {
    fVar2 = fVar2 - 360.0;
    fVar3 = fVar2;
    if (0.0 < fVar2) goto LAB_00084374;
LAB_000843e2:
    fVar3 = 0.0 - fVar2;
    if (fVar3 <= 0.01) goto LAB_00084416;
LAB_00084382:
    fVar5 = v_frametime * degreesPerSec;
    if (fVar3 < degreesPerSec * 0.25) {
      fVar4 = fVar3 / (degreesPerSec * 0.25);
      fVar5 = fVar4 * fVar4 * fVar5;
    }
    if (fVar3 < fVar5) goto LAB_00084416;
    if (fVar2 <= 0.0) {
      finalAngle[1] = fVar1 - fVar5;
    }
    else {
      finalAngle[1] = fVar5 + fVar1;
    }
  }
  else {
    if (fVar2 < -180.0) {
      fVar2 = fVar2 + 360.0;
    }
    fVar3 = fVar2;
    if (fVar2 <= 0.0) goto LAB_000843e2;
LAB_00084374:
    fVar2 = fVar3;
    if (0.01 < fVar3) goto LAB_00084382;
LAB_00084416:
    finalAngle[1] = endAngle[1];
  }
  fVar1 = startAngle[2];
  fVar2 = endAngle[2] - fVar1;
  if (fVar2 <= 180.0) {
    if (fVar2 < -180.0) {
      fVar2 = fVar2 + 360.0;
    }
  }
  else {
    fVar2 = fVar2 - 360.0;
  }
  fVar3 = fVar2;
  if (fVar2 <= 0.0) {
    fVar3 = 0.0 - fVar2;
  }
  if (0.01 < fVar3) {
    fVar5 = v_frametime * degreesPerSec;
    if (fVar3 < degreesPerSec * 0.25) {
      fVar4 = fVar3 / (degreesPerSec * 0.25);
      fVar5 = fVar4 * fVar4 * fVar5;
    }
    if (fVar5 <= fVar3) {
      if (0.0 < fVar2) {
        finalAngle[2] = fVar1 + fVar5;
        NormalizeAngles(finalAngle);
        return;
      }
      finalAngle[2] = fVar1 - fVar5;
      goto LAB_00084509;
    }
  }
  finalAngle[2] = endAngle[2];
LAB_00084509:
  NormalizeAngles(finalAngle);
  return;
}


// V_GetChaseOrigin  @ 000845a0  (line 900)

void V_GetChaseOrigin(float *angles,float *origin,float distance,float *returnvec)

{
  pfnEngSrc_GetEntityByIndex_t p_Var1;
  pmtrace_s *ppVar2;
  cl_entity_s *pcVar3;
  int iVar4;
  float fVar5;
  int local_50;
  vec_t local_40 [3];
  float local_34 [3];
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector vecStart@[???]
                       Unresolved local var: pmtrace_t * trace@[???]
                       Unresolved local var: int maxLoops@[???]
                       Unresolved local var: int ignoreent@[???]
                       Unresolved local var: cl_entity_t * ent@[???] */
  (*gEngfuncs.pfnAngleVectors)(angles,local_34,(float *)0x0,(float *)0x0);
  VectorScale(local_34,-1.0,local_34);
  local_28 = *origin;
  local_24 = origin[1];
  local_20 = origin[2];
  VectorMA(&local_28,distance,local_34,local_40);
  iVar4 = -1;
  local_50 = 8;
  while( true ) {
    ppVar2 = (*gEngfuncs.PM_TraceLine)(&local_28,local_40,0,2,iVar4);
    p_Var1 = gEngfuncs.GetEntityByIndex;
    if (ppVar2->ent < 1) break;
    iVar4 = PM_GetPhysEntInfo(ppVar2->ent);
    pcVar3 = (*p_Var1)(iVar4);
    if ((pcVar3 == (cl_entity_s *)0x0) ||
       ((((pcVar3->curstate).solid == 4 && (pcVar3->player == 0)) ||
        (fVar5 = Distance(&(ppVar2->endpos).x,local_40), fVar5 < 1.0)))) break;
    local_50 = local_50 + -1;
    local_28 = (ppVar2->endpos).x;
    local_24 = (ppVar2->endpos).y;
    local_20 = (ppVar2->endpos).z;
    iVar4 = ppVar2->ent;
    if (local_50 == 0) break;
  }
  VectorMA(&(ppVar2->endpos).x,4.0,(float *)&ppVar2->plane,returnvec);
  v_lastDistance = Distance(&(ppVar2->endpos).x,origin);
  return;
}


// V_GetSingleTargetCam  @ 00084750  (line 1005)

void V_GetSingleTargetCam(cl_entity_t *ent1,float *angle,float *origin)

{
  float fVar1;
  float distance;
  float fVar2;
  bool bVar3;
  float local_24;
  float local_20;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  float local_10;
  
                    /* Unresolved local var: float[3] newAngle@[???]
                       Unresolved local var: float[3] newOrigin@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: qboolean deadPlayer@[???]
                       Unresolved local var: float dfactor@[???]
                       Unresolved local var: float distance@[???] */
  bVar3 = false;
  if (ent1->player != 0) {
    bVar3 = (ent1->curstate).solid == 0;
  }
  if ((gHUD.m_Spectator.m_iObserverFlags & 0x20U) == 0) {
    fVar1 = 192.0;
    distance = 256.0;
    local_24 = 12.5;
    fVar2 = 128.0;
  }
  else {
    fVar1 = 144.0;
    distance = 192.0;
    local_24 = -12.5;
    fVar2 = 96.0;
  }
  if (((gHUD.m_Spectator.m_iObserverFlags & 0x200U) == 0) && (distance = fVar2, bVar3)) {
    distance = fVar1;
  }
  local_18 = (ent1->origin).x;
  local_14 = (ent1->origin).y;
  v_lastDistance = v_frametime * 32.0 + v_lastDistance;
  if (v_lastDistance < distance) {
    distance = v_lastDistance;
  }
  local_10 = (ent1->origin).z;
  if (ent1->player == 0) {
    local_10 = local_10 + 8.0;
  }
  else if (bVar3) {
    local_10 = local_10 + 2.0;
  }
  else {
    local_10 = local_10 + 17.0;
  }
  local_1c = (ent1->angles).z;
  local_20 = (ent1->angles).y;
  if ((gHUD.m_Spectator.m_iObserverFlags & 0x80U) != 0) {
    local_20 = local_20 + 180.0;
  }
  if ((gHUD.m_Spectator.m_iObserverFlags & 0x200U) == 0) {
    local_24 = local_24 + (ent1->angles).x;
  }
  else {
    local_24 = 22.5;
  }
  if ((gHUD.m_Spectator.m_iObserverFlags & 0x10U) == 0) {
    local_20 = local_20 - 22.5;
  }
  else {
    local_20 = local_20 + 22.5;
  }
  V_SmoothInterpolateAngles(&v_lastAngles.x,&local_24,angle,120.0);
  V_GetChaseOrigin(angle,&local_18,distance,origin);
  return;
}


// MaxAngleBetweenAngles  @ 00084900  (line 1070)

float MaxAngleBetweenAngles(float *a1,float *a2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: float maxd@[???] */
  NormalizeAngles(a1);
  NormalizeAngles(a2);
                    /* Unresolved local var: int i@[???] */
  fVar1 = *a2 - *a1;
  if (180.0 < fVar1) {
    fVar1 = fVar1 - 360.0;
  }
  else if (fVar1 < -180.0) {
    fVar1 = fVar1 + 360.0;
  }
  fVar2 = fVar1;
  if (fVar1 <= 0.0) {
    fVar2 = 0.0 - fVar1;
    if (0.0 - fVar1 <= 0.0) {
      fVar2 = 0.0;
    }
  }
  fVar1 = a2[1] - a1[1];
  if (180.0 < fVar1) {
    fVar1 = fVar1 - 360.0;
  }
  else if (fVar1 < -180.0) {
    fVar1 = fVar1 + 360.0;
  }
  if (fVar1 <= 0.0) {
    fVar1 = 0.0 - fVar1;
  }
  if (fVar1 <= fVar2) {
    fVar1 = fVar2;
  }
  fVar2 = a2[2] - a1[2];
  if (fVar2 <= 180.0) {
    if (fVar2 < -180.0) {
      fVar2 = fVar2 + 360.0;
    }
  }
  else {
    fVar2 = fVar2 - 360.0;
  }
  if (fVar2 <= 0.0) {
    fVar3 = 0.0 - fVar2;
    if (0.0 - fVar2 <= fVar1) {
      fVar3 = fVar1;
    }
    return fVar3;
  }
  if (fVar2 <= fVar1) {
    fVar2 = fVar1;
  }
  return fVar2;
}


// V_GetDoubleTargetsCam  @ 00084a50  (line 1098)

void V_GetDoubleTargetsCam(cl_entity_t *ent1,cl_entity_t *ent2,float *angle,float *origin)

{
  float fVar1;
  float fVar2;
  float distance;
  int iVar3;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float[3] newAngle@[???]
                       Unresolved local var: float[3] newOrigin@[???]
                       Unresolved local var: float[3] tempVec@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: float dfactor@[???]
                       Unresolved local var: float distance@[???]
                       Unresolved local var: float d@[???] */
  iVar3 = gHUD.m_Spectator.m_iObserverFlags;
  if ((gHUD.m_Spectator.m_iObserverFlags & 0x20U) == 0) {
    fVar1 = 256.0;
    distance = 128.0;
    fVar2 = 1.0;
  }
  else {
    fVar1 = 192.0;
    distance = 96.0;
    fVar2 = -1.0;
  }
  if ((gHUD.m_Spectator.m_iObserverFlags & 0x200U) != 0) {
    distance = fVar1;
  }
  v_lastDistance = v_frametime * 32.0 + v_lastDistance;
  if (v_lastDistance < distance) {
    distance = v_lastDistance;
  }
  local_34 = (ent1->origin).x;
  local_30 = (ent1->origin).y;
  fVar1 = (ent1->origin).z;
  if (ent1->player == 0) {
    local_2c = fVar1 + 8.0;
  }
  else {
    local_2c = fVar1 + 17.0;
  }
  local_40 = (ent2->origin).x - local_34;
  local_3c = (ent2->origin).y - local_30;
  local_38 = (ent2->origin).z - fVar1;
  VectorAngles(&local_40,&local_40);
  local_40 = fVar2 * 12.5 - local_40;
  if ((iVar3 & 0x10U) == 0) {
    local_3c = local_3c - 22.5;
  }
  else {
    local_3c = local_3c + 22.5;
  }
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: float maxd@[???] */
  NormalizeAngles(&v_lastAngles.x);
  NormalizeAngles(&local_40);
                    /* Unresolved local var: int i@[???] */
  fVar2 = local_40 - v_lastAngles.x;
  if (180.0 < fVar2) {
    fVar2 = fVar2 - 360.0;
  }
  else if (fVar2 < -180.0) {
    fVar2 = fVar2 + 360.0;
  }
  fVar1 = fVar2;
  if (fVar2 <= 0.0) {
    fVar1 = 0.0 - fVar2;
    if (0.0 - fVar2 <= 0.0) {
      fVar1 = 0.0;
    }
  }
  fVar2 = local_3c - v_lastAngles.y;
  if (180.0 < fVar2) {
    fVar2 = fVar2 - 360.0;
  }
  else if (fVar2 < -180.0) {
    fVar2 = fVar2 + 360.0;
  }
  if (fVar2 <= 0.0) {
    fVar2 = 0.0 - fVar2;
  }
  if (fVar2 <= fVar1) {
    fVar2 = fVar1;
  }
  fVar1 = local_38 - v_lastAngles.z;
  if (fVar1 <= 180.0) {
    if (fVar1 < -180.0) {
      fVar1 = fVar1 + 360.0;
    }
  }
  else {
    fVar1 = fVar1 - 360.0;
  }
  if (fVar1 <= 0.0) {
    fVar1 = 0.0 - fVar1;
  }
  if (fVar1 <= fVar2) {
    fVar1 = fVar2;
  }
  if ((v_cameraFocusAngle <= fVar1) || (v_cameraMode != 1)) {
    if ((v_cameraRelaxAngle <= fVar1) || (v_cameraMode != 2)) {
      v_cameraMode = 2;
      if (v_resetCamera == 0) {
        V_SmoothInterpolateAngles(&v_lastAngles.x,&local_40,angle,180.0);
        goto LAB_00084cd3;
      }
    }
    else {
      v_cameraMode = 1;
    }
  }
  else {
    local_40 = v_lastAngles.x;
    local_3c = v_lastAngles.y;
    local_38 = v_lastAngles.z;
  }
  *angle = local_40;
  angle[1] = local_3c;
  angle[2] = local_38;
LAB_00084cd3:
  V_GetChaseOrigin(&local_40,&local_34,distance,origin);
  if (64.0 <= v_lastDistance) {
    local_20 = origin[2];
  }
  else {
    local_20 = (1.0 - v_lastDistance * 0.015625) * 16.0 + origin[2];
    origin[2] = local_20;
  }
  local_28 = (ent2->origin).x - *origin;
  local_24 = (ent2->origin).y - origin[1];
  local_20 = (ent2->origin).z - local_20;
  VectorAngles(&local_28,&local_28);
  return;
}


// V_GetDirectedChasePosition  @ 00084ea0  (line 1185)

void V_GetDirectedChasePosition(cl_entity_t *ent1,cl_entity_t *ent2,float *angle,float *origin)

{
  float fVar1;
  float distance;
  vec_t local_18;
  vec_t local_14;
  float local_10;
  
  if (v_resetCamera != 0) {
    v_lastDistance = 4096.0;
  }
  if ((ent2 == (cl_entity_t *)0xffffffff) || ((ent1->player != 0 && ((ent1->curstate).solid == 0))))
  {
    V_GetSingleTargetCam(ent1,angle,origin);
  }
  else if (ent2 == (cl_entity_t *)0x0) {
                    /* Unresolved local var: float[3] newOrigin@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: float dfactor@[???]
                       Unresolved local var: float distance@[???] */
    if ((gHUD.m_Spectator.m_iObserverFlags & 0x20U) == 0) {
      fVar1 = 256.0;
      distance = 128.0;
    }
    else {
      fVar1 = 192.0;
      distance = 96.0;
    }
    if ((gHUD.m_Spectator.m_iObserverFlags & 0x200U) != 0) {
      distance = fVar1;
    }
    local_18 = (ent1->origin).x;
    local_14 = (ent1->origin).y;
    v_lastDistance = v_frametime * 32.0 + v_lastDistance;
    if (v_lastDistance < distance) {
      distance = v_lastDistance;
    }
    local_10 = (ent1->origin).z;
    if (ent1->player == 0) {
      local_10 = local_10 + 8.0;
    }
    else {
      local_10 = local_10 + 17.0;
    }
    V_GetChaseOrigin(angle,&local_18,distance,origin);
  }
  else {
    V_GetDoubleTargetsCam(ent1,ent2,angle,origin);
  }
  v_lastAngles.x = *angle;
  v_lastAngles.y = angle[1];
  v_lastAngles.z = angle[2];
  return;
}


// V_GetChasePos  @ 00085010  (line 1240)

void V_GetChasePos(int target,float *cl_angles,float *origin,float *angles)

{
  vec_t vVar1;
  float fVar2;
  cvar_t *pcVar3;
  cl_entity_s *ent1;
  cl_entity_s *ent2;
  
                    /* Unresolved local var: cl_entity_t * ent@[???] */
  if ((target == 0) || (ent1 = (*gEngfuncs.GetEntityByIndex)(target), ent1 == (cl_entity_s *)0x0)) {
    *angles = vJumpAngles[0];
    angles[1] = vJumpAngles[1];
    angles[2] = vJumpAngles[2];
    *origin = vJumpOrigin[0];
    origin[1] = vJumpOrigin[1];
    origin[2] = vJumpOrigin[2];
  }
  else {
    if ((gHUD.m_Spectator.m_autoDirector)->value == 0.0) {
      if (cl_angles == (float *)0x0) {
        fVar2 = (ent1->angles).x;
        *angles = fVar2;
        angles[1] = (ent1->angles).y;
        vVar1 = (ent1->angles).z;
        *angles = -fVar2;
        angles[2] = vVar1;
      }
      else {
        *angles = *cl_angles;
        angles[1] = cl_angles[1];
        angles[2] = cl_angles[2];
      }
      *origin = (ent1->origin).x;
      pcVar3 = cl_chasedist;
      origin[1] = (ent1->origin).y;
      origin[2] = (ent1->origin).z + 28.0;
      V_GetChaseOrigin(angles,origin,pcVar3->value,origin);
    }
    else if (g_iUser3 == 0) {
      if (v_resetCamera != 0) {
        v_lastDistance = 4096.0;
      }
      V_GetSingleTargetCam(ent1,angles,origin);
      v_lastAngles.x = *angles;
      v_lastAngles.y = angles[1];
      v_lastAngles.z = angles[2];
    }
    else {
      ent2 = (*gEngfuncs.GetEntityByIndex)(g_iUser3);
      V_GetDirectedChasePosition(ent1,ent2,angles,origin);
    }
    v_resetCamera = 0;
  }
  return;
}


// V_ResetChaseCam  @ 00085200  (line 1290)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void V_ResetChaseCam(void)

{
  v_resetCamera = 1;
  return;
}


// V_GetInEyePos  @ 00085210  (line 1295)

void V_GetInEyePos(int target,float *origin,float *angles)

{
  float fVar1;
  cl_entity_s *pcVar2;
  
                    /* Unresolved local var: cl_entity_t * ent@[???] */
  if (target == 0) {
    *angles = vJumpAngles[0];
    angles[1] = vJumpAngles[1];
    angles[2] = vJumpAngles[2];
    *origin = vJumpOrigin[0];
    origin[1] = vJumpOrigin[1];
    origin[2] = vJumpOrigin[2];
  }
  else {
                    /* Unresolved local var: cl_entity_t * ent@[DW_OP_reg0(EAX)] */
    pcVar2 = (*gEngfuncs.GetEntityByIndex)(target);
    if (pcVar2 != (cl_entity_s *)0x0) {
      *origin = (pcVar2->origin).x;
      origin[1] = (pcVar2->origin).y;
      origin[2] = (pcVar2->origin).z;
      fVar1 = (pcVar2->angles).x;
      *angles = fVar1;
      angles[1] = (pcVar2->angles).y;
      angles[2] = (pcVar2->angles).z;
      *angles = fVar1 * -3.0;
      if ((pcVar2->curstate).solid == 0) {
        angles[2] = 80.0;
        origin[2] = origin[2] - 8.0;
        return;
      }
      if ((pcVar2->curstate).usehull != 1) {
        origin[2] = origin[2] + 28.0;
        return;
      }
      origin[2] = origin[2] + 12.0;
    }
  }
  return;
}


// V_GetMapFreePosition  @ 00085340  (line 1329)

void V_GetMapFreePosition(float *cl_angles,float *origin,float *angles)

{
  float fVar1;
  float local_24 [3];
  vec_t local_18;
  vec_t local_14;
  float local_10;
  
                    /* Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector zScaledTarget@[???] */
  fVar1 = *cl_angles;
  *angles = fVar1;
  angles[1] = cl_angles[1];
  angles[2] = cl_angles[2];
  fVar1 = (fVar1 / 90.0) * 38.75 + 51.25;
  *angles = fVar1;
  local_18 = gHUD.m_Spectator.m_mapOrigin.x;
  local_14 = gHUD.m_Spectator.m_mapOrigin.y;
  local_10 = ((90.0 - fVar1) / 90.0) * gHUD.m_Spectator.m_mapOrigin.z;
  (*gEngfuncs.pfnAngleVectors)(angles,local_24,(float *)0x0,(float *)0x0);
  VectorNormalize(local_24);
  VectorMA(&local_18,-(4096.0 / gHUD.m_Spectator.m_mapZoom),local_24,origin);
  return;
}


// V_GetMapChasePosition  @ 00085400  (line 1351)

void V_GetMapChasePosition(int target,float *cl_angles,float *origin,float *angles)

{
  float fVar1;
  cl_entity_s *pcVar2;
  float local_28 [6];
  
                    /* Unresolved local var: Vector forward@[???] */
  if (target == 0) {
    fVar1 = *cl_angles;
    *angles = fVar1;
    angles[1] = cl_angles[1];
    angles[2] = cl_angles[2];
  }
  else {
                    /* Unresolved local var: cl_entity_t * ent@[???] */
    pcVar2 = (*gEngfuncs.GetEntityByIndex)(target);
    if ((gHUD.m_Spectator.m_autoDirector)->value != 0.0) {
      V_GetChasePos(target,cl_angles,origin,angles);
      fVar1 = 0.5;
      *origin = (pcVar2->origin).x;
      origin[1] = (pcVar2->origin).y;
      origin[2] = (pcVar2->origin).z;
      *angles = 45.0;
      goto LAB_00085463;
    }
    *angles = *cl_angles;
    angles[1] = cl_angles[1];
    angles[2] = cl_angles[2];
    *origin = (pcVar2->origin).x;
    origin[1] = (pcVar2->origin).y;
    origin[2] = (pcVar2->origin).z;
    fVar1 = *angles;
  }
  fVar1 = (fVar1 / 90.0) * 38.75 + 51.25;
  *angles = fVar1;
  fVar1 = (90.0 - fVar1) / 90.0;
LAB_00085463:
  origin[2] = fVar1 * origin[2];
  angles[2] = 0.0;
  (*gEngfuncs.pfnAngleVectors)(angles,local_28,(float *)0x0,(float *)0x0);
  VectorNormalize(local_28);
  VectorMA(origin,-1536.0,local_28,origin);
  return;
}


// V_FindViewModelByWeaponModel  @ 00085590  (line 1394)

int V_FindViewModelByWeaponModel(int weaponindex)

{
  model_s *__s;
  size_t __n;
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: model_s * weaponModel@[???] */
  __s = (*IEngineStudio.GetModelByIndex)(weaponindex);
  if (__s != (model_s *)0x0) {
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int i@[???] */
    iVar2 = 0;
    __n = strlen(__s->name);
    while( true ) {
      iVar1 = strncasecmp(__s->name,V_FindViewModelByWeaponModel::modelmap[iVar2][0],__n);
      if (iVar1 == 0) break;
      iVar2 = iVar2 + 1;
    }
                    /* WARNING: Could not recover jumptable at 0x000855f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)
                      (V_FindViewModelByWeaponModel::modelmap[iVar2][1]);
    return iVar2;
  }
  return 0;
}


// V_CalcSpectatorRefdef  @ 00085600  (line 1465)

void V_CalcSpectatorRefdef(ref_params_s *pparams)

{
  vec_t vVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  vec_t vVar5;
  vec_t vVar6;
  vec_t vVar7;
  vec_t vVar8;
  vec_t vVar9;
  cl_entity_s *pcVar10;
  int iVar11;
  cl_entity_s *pcVar12;
  model_s *pmVar13;
  size_t __n;
  int iVar14;
  bool bVar15;
  float local_34 [3];
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: cl_entity_t * ent@[???] */
  if ((V_CalcSpectatorRefdef(ref_params_s*)::velocity == '\0') &&
     (iVar11 = __cxa_guard_acquire(&V_CalcSpectatorRefdef(ref_params_s*)::velocity), iVar11 != 0)) {
    V_CalcSpectatorRefdef::velocity.x = 0.0;
    V_CalcSpectatorRefdef::velocity.y = 0.0;
    V_CalcSpectatorRefdef::velocity.z = 0.0;
    __cxa_guard_release(&V_CalcSpectatorRefdef(ref_params_s*)::velocity);
  }
  pcVar10 = (*gEngfuncs.GetEntityByIndex)(g_iUser2);
  v_sim_org.x = pparams->simorg[0];
  v_sim_org.y = pparams->simorg[1];
  v_sim_org.z = pparams->simorg[2];
  v_cl_angles.x = pparams->cl_viewangles[0];
  v_cl_angles.y = pparams->cl_viewangles[1];
  v_cl_angles.z = pparams->cl_viewangles[2];
  v_angles.x = pparams->viewangles[0];
  v_angles.y = pparams->viewangles[1];
  v_angles.z = pparams->viewangles[2];
  v_origin.y = pparams->vieworg[1];
  v_origin.x = pparams->vieworg[0];
  v_origin.z = pparams->vieworg[2];
  bVar15 = g_iUser1 != 4;
  pparams->onlyClientDraw = 0;
  if (((bVar15) && ((gHUD.m_Spectator.m_pip)->value != 2.0)) || (pcVar10 == (cl_entity_s *)0x0))
  goto LAB_000858f0;
                    /* Unresolved local var: float timeDiff@[???] */
  fVar2 = (pcVar10->curstate).msg_time - (pcVar10->prevstate).msg_time;
  if (0.0 < fVar2) {
                    /* Unresolved local var: Vector distance@[???] */
    local_28 = (pcVar10->prevstate).origin.x - (pcVar10->curstate).origin.x;
    local_24 = (pcVar10->prevstate).origin.y - (pcVar10->curstate).origin.y;
    local_20 = (pcVar10->prevstate).origin.z - (pcVar10->curstate).origin.z;
    VectorScale(&local_28,1.0 / fVar2,&local_28);
    V_CalcSpectatorRefdef::velocity.x = local_28 * 0.1 + V_CalcSpectatorRefdef::velocity.x * 0.9;
    fVar3 = local_24 * 0.1 + V_CalcSpectatorRefdef::velocity.y * 0.9;
    fVar2 = local_20 * 0.1 + V_CalcSpectatorRefdef::velocity.z * 0.9;
    V_CalcSpectatorRefdef::velocity.y = fVar3;
    V_CalcSpectatorRefdef::velocity.z = fVar2;
    pparams->simvel[0] = V_CalcSpectatorRefdef::velocity.x;
    pparams->simvel[1] = fVar3;
    pparams->simvel[2] = fVar2;
  }
  iVar11 = (*gEngfuncs.IsSpectateOnly)();
  fVar2 = vJumpAngles[1];
  if ((iVar11 == 0) && ((gHUD.m_Spectator.m_pip)->value != 2.0)) {
    fVar2 = (pcVar10->angles).x;
    pparams->cl_viewangles[0] = fVar2;
    pparams->cl_viewangles[1] = (pcVar10->angles).y;
    vVar1 = (pcVar10->angles).z;
    pparams->cl_viewangles[0] = fVar2 * -3.0;
    pparams->cl_viewangles[2] = vVar1;
    goto LAB_000858f0;
  }
                    /* Unresolved local var: cl_entity_t * gunModel@[???] */
                    /* Unresolved local var: cl_entity_t * ent@[???] */
  if (g_iUser2 == 0) {
    pparams->cl_viewangles[0] = vJumpAngles[0];
    pparams->cl_viewangles[1] = fVar2;
    fVar2 = vJumpOrigin[0];
    pparams->cl_viewangles[2] = vJumpAngles[2];
    pparams->simorg[0] = fVar2;
    fVar2 = vJumpOrigin[2];
    pparams->simorg[1] = vJumpOrigin[1];
    pparams->simorg[2] = fVar2;
  }
  else {
                    /* Unresolved local var: cl_entity_t * ent@[???] */
    pcVar12 = (*gEngfuncs.GetEntityByIndex)(g_iUser2);
    if (pcVar12 != (cl_entity_s *)0x0) {
      pparams->simorg[0] = (pcVar12->origin).x;
      pparams->simorg[1] = (pcVar12->origin).y;
      fVar2 = (pcVar12->origin).z;
      pparams->simorg[2] = fVar2;
      fVar3 = (pcVar12->angles).x;
      pparams->cl_viewangles[0] = fVar3;
      pparams->cl_viewangles[1] = (pcVar12->angles).y;
      pparams->cl_viewangles[2] = (pcVar12->angles).z;
      pparams->cl_viewangles[0] = fVar3 * -3.0;
      if ((pcVar12->curstate).solid == 0) {
        pparams->cl_viewangles[2] = 80.0;
        pparams->simorg[2] = fVar2 - 8.0;
      }
      else if ((pcVar12->curstate).usehull == 1) {
        pparams->simorg[2] = fVar2 + 12.0;
      }
      else {
        pparams->simorg[2] = fVar2 + 28.0;
      }
    }
  }
  pparams->health = 1;
  pcVar12 = (*gEngfuncs.GetViewModel)();
  iVar11 = (pcVar10->curstate).weaponmodel;
  if (iVar11 == V_CalcSpectatorRefdef::lastWeaponModelIndex) {
LAB_00085eff:
    if (V_CalcSpectatorRefdef::lastViewModelIndex != 0) {
      pmVar13 = (*IEngineStudio.GetModelByIndex)(V_CalcSpectatorRefdef::lastViewModelIndex);
      (pcVar12->curstate).frame = 0.0;
      (pcVar12->curstate).colormap = 0;
      pcVar12->model = pmVar13;
      (pcVar12->curstate).modelindex = V_CalcSpectatorRefdef::lastViewModelIndex;
      pcVar12->index = g_iUser2;
      goto LAB_000858f0;
    }
  }
  else {
    V_CalcSpectatorRefdef::lastWeaponModelIndex = iVar11;
                    /* Unresolved local var: model_s * weaponModel@[???] */
    pmVar13 = (*IEngineStudio.GetModelByIndex)(iVar11);
    if (pmVar13 != (model_s *)0x0) {
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int i@[???] */
      iVar11 = 0;
      __n = strlen(pmVar13->name);
      while (iVar14 = strncasecmp(pmVar13->name,V_FindViewModelByWeaponModel::modelmap[iVar11][0],
                                  __n), iVar14 != 0) {
        iVar11 = iVar11 + 1;
      }
      V_CalcSpectatorRefdef::lastViewModelIndex =
           (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)
                     (V_FindViewModelByWeaponModel::modelmap[iVar11][1]);
      if (V_CalcSpectatorRefdef::lastViewModelIndex != 0) {
        (*gEngfuncs.pfnWeaponAnim)(0,0);
        goto LAB_00085eff;
      }
    }
    V_CalcSpectatorRefdef::lastViewModelIndex = 0;
    V_CalcSpectatorRefdef::lastWeaponModelIndex = 0;
  }
  pcVar12->model = (model_s *)0x0;
LAB_000858f0:
  v_frametime = pparams->frametime;
  if (pparams->nextView == 0) {
    switch(g_iUser1) {
    case 1:
      V_GetChasePos(g_iUser2,(float *)0x0,&v_origin.x,&v_angles.x);
      break;
    case 2:
      V_GetChasePos(g_iUser2,&v_cl_angles.x,&v_origin.x,&v_angles.x);
      break;
    case 3:
      v_angles.x = v_cl_angles.x;
      v_angles.y = v_cl_angles.y;
      v_angles.z = v_cl_angles.z;
      v_origin.x = v_sim_org.x;
      v_origin.y = v_sim_org.y;
      v_origin.z = v_sim_org.z;
      CHudSpectator::GetDirectorCamera(&gHUD.m_Spectator,&v_origin,&v_angles);
      break;
    case 4:
      V_CalcNormalRefdef(pparams);
      break;
    case 5:
                    /* Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector zScaledTarget@[???] */
      fVar2 = v_cl_angles.x / 90.0;
      pparams->onlyClientDraw = 1;
      v_angles.y = v_cl_angles.y;
      v_angles.z = v_cl_angles.z;
      local_28 = gHUD.m_Spectator.m_mapOrigin.x;
      local_24 = gHUD.m_Spectator.m_mapOrigin.y;
      v_angles.x = fVar2 * 38.75 + 51.25;
      local_20 = ((90.0 - v_angles.x) / 90.0) * gHUD.m_Spectator.m_mapOrigin.z;
      (*gEngfuncs.pfnAngleVectors)(&v_angles.x,local_34,(float *)0x0,(float *)0x0);
      VectorNormalize(local_34);
      VectorMA(&local_28,-(4096.0 / gHUD.m_Spectator.m_mapZoom),local_34,&v_origin.x);
      break;
    case 6:
      pparams->onlyClientDraw = 1;
      V_GetMapChasePosition(g_iUser2,&v_cl_angles.x,&v_origin.x,&v_angles.x);
    }
    if ((gHUD.m_Spectator.m_pip)->value != 0.0) {
      pparams->nextView = 1;
    }
    gHUD.m_Spectator.m_iDrawCycle = 0;
  }
  else {
    fVar3 = 1.0;
    fVar2 = (float)gHUD.m_scrinfo.iWidth / 1280.0;
    if ((float)gHUD.m_scrinfo.iWidth / 1280.0 <= 1.0) {
      fVar2 = fVar3;
    }
    pparams->viewport[0] = (int)(fVar2 * (float)gHUD.m_Spectator.m_OverviewData.insetWindowX);
    fVar2 = (float)gHUD.m_scrinfo.iHeight / 720.0;
    if ((float)gHUD.m_scrinfo.iHeight / 720.0 <= 1.0) {
      fVar2 = fVar3;
    }
    pparams->viewport[1] = (int)(fVar2 * (float)gHUD.m_Spectator.m_OverviewData.insetWindowY);
    fVar2 = (float)gHUD.m_scrinfo.iWidth / 1280.0;
    if ((float)gHUD.m_scrinfo.iWidth / 1280.0 <= 1.0) {
      fVar2 = fVar3;
    }
    pparams->viewport[2] = (int)(fVar2 * (float)gHUD.m_Spectator.m_OverviewData.insetWindowWidth);
    fVar4 = (float)gHUD.m_Spectator.m_OverviewData.insetWindowHeight;
    fVar2 = (float)gHUD.m_scrinfo.iHeight / 720.0;
    if ((float)gHUD.m_scrinfo.iHeight / 720.0 <= 1.0) {
      fVar2 = fVar3;
    }
    pparams->nextView = 0;
    pparams->viewport[3] = (int)(fVar4 * fVar2);
    iVar11 = (int)(gHUD.m_Spectator.m_pip)->value;
    if (iVar11 == 2) {
      V_CalcNormalRefdef(pparams);
    }
    else if (iVar11 < 3) {
      if (iVar11 == 1) {
        V_GetChasePos(g_iUser2,&v_cl_angles.x,&v_origin.x,&v_angles.x);
      }
    }
    else if (iVar11 == 3) {
                    /* Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector zScaledTarget@[???] */
      fVar2 = v_cl_angles.x / 90.0;
      pparams->onlyClientDraw = 1;
      v_angles.y = v_cl_angles.y;
      v_angles.z = v_cl_angles.z;
      local_28 = gHUD.m_Spectator.m_mapOrigin.x;
      local_24 = gHUD.m_Spectator.m_mapOrigin.y;
      v_angles.x = fVar2 * 38.75 + 51.25;
      local_20 = ((90.0 - v_angles.x) / 90.0) * gHUD.m_Spectator.m_mapOrigin.z;
      (*gEngfuncs.pfnAngleVectors)(&v_angles.x,local_34,(float *)0x0,(float *)0x0);
      VectorNormalize(local_34);
      VectorMA(&local_28,-(4096.0 / gHUD.m_Spectator.m_mapZoom),local_34,&v_origin.x);
    }
    else if (iVar11 == 4) {
      bVar15 = g_iUser1 == 3;
      pparams->onlyClientDraw = 1;
      if (bVar15) {
                    /* Unresolved local var: Vector forward@[???] */
        v_angles.y = v_cl_angles.y;
        v_angles.z = 0.0;
        v_angles.x = (v_cl_angles.x / 90.0) * 38.75 + 51.25;
        v_origin.z = ((90.0 - v_angles.x) / 90.0) * v_origin.z;
        (*gEngfuncs.pfnAngleVectors)(&v_angles.x,&local_28,(float *)0x0,(float *)0x0);
        VectorNormalize(&local_28);
        VectorMA(&v_origin.x,-1536.0,&local_28,&v_origin.x);
      }
      else {
        V_GetMapChasePosition(g_iUser2,&v_cl_angles.x,&v_origin.x,&v_angles.x);
      }
    }
    gHUD.m_Spectator.m_iDrawCycle = 1;
  }
  vVar9 = v_angles.z;
  vVar8 = v_angles.y;
  vVar7 = v_angles.x;
  vVar6 = v_cl_angles.z;
  vVar5 = v_cl_angles.y;
  vVar1 = v_cl_angles.x;
  pparams->vieworg[0] = v_origin.x;
  pparams->cl_viewangles[0] = vVar1;
  vVar1 = v_origin.y;
  pparams->cl_viewangles[1] = vVar5;
  pparams->cl_viewangles[2] = vVar6;
  pparams->vieworg[1] = vVar1;
  pparams->viewangles[0] = vVar7;
  vVar1 = v_origin.z;
  pparams->viewangles[1] = vVar8;
  pparams->viewangles[2] = vVar9;
  pparams->vieworg[2] = vVar1;
  return;
}


// V_CalcRefdef  @ 000860b0  (line 1639)

void V_CalcRefdef(ref_params_s *pparams)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  cl_entity_s *pcVar6;
  int iVar7;
  double dVar8;
  
  if (pparams->intermission != 0) {
                    /* Unresolved local var: cl_entity_t * ent@[???]
                       Unresolved local var: cl_entity_t * view@[???]
                       Unresolved local var: float old@[???] */
    (*gEngfuncs.GetLocalPlayer)();
    pcVar6 = (*gEngfuncs.GetViewModel)();
    fVar1 = pparams->simorg[1];
    fVar2 = pparams->simorg[2];
    fVar3 = pparams->cl_viewangles[0];
    fVar4 = pparams->cl_viewangles[1];
    fVar5 = pparams->cl_viewangles[2];
    pparams->vieworg[0] = pparams->simorg[0];
    pparams->vieworg[1] = fVar1;
    pparams->vieworg[2] = fVar2;
    pparams->viewangles[0] = fVar3;
    pparams->viewangles[1] = fVar4;
    pparams->viewangles[2] = fVar5;
    pcVar6->model = (model_s *)0x0;
    fVar2 = v_idlescale;
    fVar1 = pparams->time;
    v_idlescale = 1.0;
    dVar8 = sin((double)(v_iroll_cycle.value * fVar1));
    pparams->viewangles[2] = (float)dVar8 * v_iroll_level.value + pparams->viewangles[2];
    dVar8 = sin((double)(fVar1 * v_ipitch_cycle.value));
    pparams->viewangles[0] = (float)dVar8 * v_ipitch_level.value + pparams->viewangles[0];
    dVar8 = sin((double)(fVar1 * v_iyaw_cycle.value));
    pparams->viewangles[1] = (float)dVar8 * v_iyaw_level.value + pparams->viewangles[1];
    iVar7 = (*gEngfuncs.IsSpectateOnly)();
    if (iVar7 == 0) {
      v_angles.x = pparams->viewangles[0];
      v_angles.y = pparams->viewangles[1];
      v_angles.z = pparams->viewangles[2];
    }
    else {
      pparams->vieworg[0] = gHUD.m_Spectator.m_cameraOrigin.x;
      pparams->vieworg[1] = gHUD.m_Spectator.m_cameraOrigin.y;
      pparams->vieworg[2] = gHUD.m_Spectator.m_cameraOrigin.z;
      v_angles.x = gHUD.m_Spectator.m_cameraAngles.x;
      pparams->viewangles[0] = gHUD.m_Spectator.m_cameraAngles.x;
      v_angles.y = gHUD.m_Spectator.m_cameraAngles.y;
      pparams->viewangles[1] = gHUD.m_Spectator.m_cameraAngles.y;
      v_angles.z = gHUD.m_Spectator.m_cameraAngles.z;
      pparams->viewangles[2] = gHUD.m_Spectator.m_cameraAngles.z;
    }
    v_idlescale = fVar2;
    v_cl_angles.y = pparams->cl_viewangles[1];
    v_cl_angles.z = pparams->cl_viewangles[2];
    v_cl_angles.x = pparams->cl_viewangles[0];
    v_origin.x = pparams->vieworg[0];
    v_origin.y = pparams->vieworg[1];
    v_origin.z = pparams->vieworg[2];
    return;
  }
  if ((pparams->spectator == 0) && (g_iUser1 == 0)) {
    if (pparams->paused != 0) {
      return;
    }
    V_CalcNormalRefdef(pparams);
    return;
  }
  V_CalcSpectatorRefdef(pparams);
  return;
}


// V_DropPunchAngle  @ 000862b0  (line 1683)

void V_DropPunchAngle(float frametime,float *ev_punchangle)

{
  float scale;
  float fVar1;
  
                    /* Unresolved local var: float len@[???] */
  fVar1 = VectorNormalize(ev_punchangle);
  fVar1 = fVar1 - (fVar1 * 0.5 + 10.0) * frametime;
  scale = 0.0;
  if (0.0 <= fVar1) {
    scale = fVar1;
  }
  VectorScale(ev_punchangle,scale,ev_punchangle);
  return;
}


// V_PunchAxis  @ 00086300  (line 1701)

void V_PunchAxis(int axis,float punch)

{
  (&ev_punchangle.x)[axis] = punch;
  return;
}


// V_Init  @ 00086320  (line 1710)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void V_Init(void)

{
  (*gEngfuncs.pfnAddCommand)("centerview",V_StartPitchDrift);
  scr_ofsx = (*gEngfuncs.pfnRegisterVariable)("scr_ofsx","0",0);
  scr_ofsy = (*gEngfuncs.pfnRegisterVariable)("scr_ofsy","0",0);
  scr_ofsz = (*gEngfuncs.pfnRegisterVariable)("scr_ofsz","0",0);
  v_centermove = (*gEngfuncs.pfnRegisterVariable)("v_centermove","0.15",0);
  v_centerspeed = (*gEngfuncs.pfnRegisterVariable)("v_centerspeed","500",0);
  cl_bobcycle = (*gEngfuncs.pfnRegisterVariable)("cl_bobcycle","0.8",0);
  cl_bob = (*gEngfuncs.pfnRegisterVariable)("cl_bob","0.01",1);
  cl_bobup = (*gEngfuncs.pfnRegisterVariable)("cl_bobup","0.5",0);
  cl_waterdist = (*gEngfuncs.pfnRegisterVariable)("cl_waterdist","4",0);
  cl_chasedist = (*gEngfuncs.pfnRegisterVariable)("cl_chasedist","112",0);
  return;
}


