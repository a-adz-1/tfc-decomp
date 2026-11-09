// V_AddIdle  @ 000a9040
void V_AddIdle(ref_params_s *pparams)

{
  float fVar1;
  float fVar2;
  double dVar3;
  
  fVar2 = v_idlescale;
  fVar1 = pparams->time;
  dVar3 = sin((double)(fVar1 * v_iroll_cycle.value));
  pparams->viewangles[2] = (float)dVar3 * fVar2 * v_iroll_level.value + pparams->viewangles[2];
  dVar3 = sin((double)(fVar1 * v_ipitch_cycle.value));
  pparams->viewangles[0] = (float)dVar3 * fVar2 * v_ipitch_level.value + pparams->viewangles[0];
  dVar3 = sin((double)(fVar1 * v_iyaw_cycle.value));
  pparams->viewangles[1] = (float)dVar3 * fVar2 * v_iyaw_level.value + pparams->viewangles[1];
  return;
}


// V_CalcBob  @ 000a8a80
float V_CalcBob(ref_params_s *pparams)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  
                    /* Unresolved local var: float cycle@[???]
                       Unresolved local var: Vector vel@[???] */
  if ((pparams->onground != -1) &&
     (fVar1 = pparams->time, fVar1 != V_CalcBob::lexical_block_0::lasttime)) {
    fVar3 = pparams->frametime + (float)V_CalcBob::lexical_block_0::bobtime;
    V_CalcBob::lexical_block_0::bobtime = (double)fVar3;
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
    V_CalcBob::lexical_block_0::lasttime = fVar1;
    if (NAN(fVar4)) {
      dVar5 = sqrt((double)fVar2);
      fVar4 = (float)dVar5;
    }
    fVar4 = fVar4 * cl_bob->value;
    dVar5 = sin((double)fVar3);
    fVar1 = fVar4 * 0.3 + fVar4 * 0.7 * (float)dVar5;
    V_CalcBob::lexical_block_0::bob = 4.0;
    if ((fVar1 < 4.0) && (V_CalcBob::lexical_block_0::bob = fVar1, fVar1 <= -7.0)) {
      V_CalcBob::lexical_block_0::bob = -7.0;
    }
    return V_CalcBob::lexical_block_0::bob;
  }
  return V_CalcBob::lexical_block_0::bob;
}


// V_CalcGunAngle  @ 000a8f10
void V_CalcGunAngle(ref_params_s *pparams)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  cl_entity_s *pcVar5;
  double dVar6;
  
                    /* Unresolved local var: cl_entity_t * viewent@[???] */
  pcVar5 = (*gEngfuncs.GetViewModel)();
  if (pcVar5 != (cl_entity_s *)0x0) {
    fVar1 = pparams->viewangles[1] + pparams->crosshairangle[1];
    (pcVar5->angles).y = fVar1;
    fVar2 = pparams->crosshairangle[0] * 0.25 + -pparams->viewangles[0];
    (pcVar5->angles).x = fVar2;
    fVar4 = v_idlescale;
    dVar6 = sin((double)(pparams->time * v_iroll_cycle.value));
    fVar3 = (pcVar5->angles).z - (float)dVar6 * fVar4 * v_iroll_level.value;
    (pcVar5->angles).z = fVar3;
    dVar6 = sin((double)(pparams->time * v_ipitch_cycle.value));
    fVar2 = fVar2 - v_ipitch_level.value * 0.5 * (float)dVar6 * fVar4;
    (pcVar5->angles).x = fVar2;
    dVar6 = sin((double)(pparams->time * v_iyaw_cycle.value));
    fVar1 = fVar1 - (float)dVar6 * fVar4 * v_iyaw_level.value;
    (pcVar5->angles).y = fVar1;
    (pcVar5->curstate).angles.x = fVar2;
    (pcVar5->curstate).angles.y = fVar1;
    (pcVar5->curstate).angles.z = fVar3;
    (pcVar5->latched).prevangles.x = fVar2;
    (pcVar5->latched).prevangles.y = fVar1;
    (pcVar5->latched).prevangles.z = fVar3;
  }
  return;
}


// V_CalcIntermissionRefdef  @ 000a9230
void V_CalcIntermissionRefdef(ref_params_s *pparams)

{
  float fVar1;
  cl_entity_s *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: cl_entity_t * ent@[???]
                       Unresolved local var: cl_entity_t * view@[???]
                       Unresolved local var: float old@[???] */
  (*gEngfuncs.GetLocalPlayer)();
  pcVar2 = (*gEngfuncs.GetViewModel)();
  pparams->vieworg[0] = pparams->simorg[0];
  fVar1 = v_idlescale;
  v_idlescale = 1.0;
  pparams->vieworg[1] = pparams->simorg[1];
  pparams->vieworg[2] = pparams->simorg[2];
  pparams->viewangles[0] = pparams->cl_viewangles[0];
  pparams->viewangles[1] = pparams->cl_viewangles[1];
  pparams->viewangles[2] = pparams->cl_viewangles[2];
  pcVar2->model = (model_s *)0x0;
  V_AddIdle(pparams);
  iVar3 = (*gEngfuncs.IsSpectateOnly)();
  if (iVar3 == 0) {
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
  v_idlescale = fVar1;
  v_cl_angles.y = pparams->cl_viewangles[1];
  v_cl_angles.x = pparams->cl_viewangles[0];
  v_cl_angles.z = pparams->cl_viewangles[2];
  v_origin.x = pparams->vieworg[0];
  v_origin.y = pparams->vieworg[1];
  v_origin.z = pparams->vieworg[2];
  return;
}


// V_CalcNormalRefdef  @ 000a9360
void V_CalcNormalRefdef(ref_params_s *pparams)

{
  float fVar1;
  float fVar2;
  cvar_t *pcVar3;
  cvar_t *pcVar4;
  cvar_t *pcVar5;
  int iVar6;
  cl_entity_s *pcVar7;
  int iVar8;
  uint uVar9;
  cl_entity_s *pcVar10;
  int iVar11;
  uint uVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float local_94;
  cl_entity_s *local_8c;
  float local_7c;
  float local_78;
  float local_74;
  float local_6c;
  float local_68;
  float local_64;
  float local_5c;
  float local_58;
  float local_54;
  float local_4c;
  float local_48;
  float local_44;
  float local_40 [3];
  float local_34 [3];
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
  iVar6 = (*gEngfuncs.IsSpectateOnly)();
  if (iVar6 == 0) {
    local_8c = (*gEngfuncs.GetLocalPlayer)();
  }
  else {
    local_8c = (*gEngfuncs.GetEntityByIndex)(g_iUser2);
  }
  pcVar7 = (*gEngfuncs.GetViewModel)();
  fVar13 = V_CalcBob(pparams);
  pparams->viewangles[0] = pparams->cl_viewangles[0];
  fVar15 = pparams->simorg[1];
  fVar14 = pparams->simorg[2];
  pparams->viewangles[1] = pparams->cl_viewangles[1];
  fVar1 = pparams->simorg[0];
  fVar2 = pparams->viewheight[0];
  pparams->viewangles[2] = pparams->cl_viewangles[2];
  pparams->vieworg[0] = fVar1 + fVar2;
  pparams->vieworg[1] = fVar15 + pparams->viewheight[1];
  pparams->vieworg[2] = fVar13 + fVar14 + pparams->viewheight[2];
  (*gEngfuncs.V_CalcShake)();
  (*gEngfuncs.V_ApplyShake)(pparams->vieworg,pparams->viewangles,1.0);
  iVar6 = pparams->waterlevel;
  fVar15 = pparams->vieworg[0] + 0.03125;
  pparams->vieworg[0] = fVar15;
  fVar14 = pparams->vieworg[1] + 0.03125;
  pparams->vieworg[1] = fVar14;
  fVar1 = pparams->vieworg[2] + 0.03125;
  pparams->vieworg[2] = fVar1;
  if (iVar6 < 2) {
    local_94 = 0.0;
  }
  else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int contents@[???]
                       Unresolved local var: int waterDist@[???]
                       Unresolved local var: int waterEntity@[???]
                       Unresolved local var: Vector point@[???] */
    iVar11 = (int)cl_waterdist->value;
    if (pparams->hardware != 0) {
      iVar6 = (*gEngfuncs.PM_WaterEntity)(pparams->simorg);
      if ((((-1 < iVar6) && (iVar6 < pparams->max_entities)) &&
          (pcVar10 = (*gEngfuncs.GetEntityByIndex)(iVar6), pcVar10 != (cl_entity_s *)0x0)) &&
         (pcVar10->model != (model_s *)0x0)) {
        iVar11 = (int)((pcVar10->curstate).scale * 16.0 + (float)iVar11);
      }
      fVar15 = pparams->vieworg[0];
      fVar14 = pparams->vieworg[1];
      fVar1 = pparams->vieworg[2];
      iVar6 = pparams->waterlevel;
    }
    fVar2 = (float)iVar11;
    local_5c = fVar15;
    local_58 = fVar14;
    if (iVar6 == 2) {
      local_54 = fVar1 - fVar2;
      if (0 < iVar11) {
        iVar6 = 0;
        do {
          iVar8 = (*gEngfuncs.PM_PointContents)(&local_5c,(int *)0x0);
          if (-3 < iVar8) {
            fVar1 = pparams->vieworg[2];
            goto LAB_000a9e30;
          }
          iVar6 = iVar6 + 1;
          local_54 = local_54 + 1.0;
        } while (iVar6 != iVar11);
        fVar1 = pparams->vieworg[2];
      }
LAB_000a9e30:
      local_94 = (local_54 + fVar2) - fVar1;
    }
    else {
      local_54 = fVar2 + fVar1;
      if (0 < iVar11) {
        iVar6 = 0;
        do {
          iVar8 = (*gEngfuncs.PM_PointContents)(&local_5c,(int *)0x0);
          if (iVar8 < -2) {
            fVar1 = pparams->vieworg[2];
            goto LAB_000a94bc;
          }
          iVar6 = iVar6 + 1;
          local_54 = local_54 - 1.0;
        } while (iVar6 != iVar11);
        fVar1 = pparams->vieworg[2];
      }
LAB_000a94bc:
      local_94 = (local_54 - fVar2) - fVar1;
    }
  }
  pparams->vieworg[2] = fVar1 + local_94;
  V_CalcViewRoll(pparams);
  V_AddIdle(pparams);
  local_4c = pparams->cl_viewangles[0];
  local_48 = pparams->cl_viewangles[1];
  local_44 = pparams->cl_viewangles[2];
  (*gEngfuncs.pfnAngleVectors)(&local_4c,pparams->forward,pparams->right,pparams->up);
  if (pparams->maxclients < 2) {
    pparams->vieworg[0] =
         scr_ofsz->value * pparams->up[0] +
         scr_ofsy->value * pparams->right[0] + scr_ofsx->value * pparams->forward[0] +
         pparams->vieworg[0];
    pcVar5 = scr_ofsx;
    pcVar4 = scr_ofsy;
    pcVar3 = scr_ofsz;
    pparams->vieworg[1] =
         scr_ofsz->value * pparams->up[1] +
         scr_ofsy->value * pparams->right[1] + scr_ofsx->value * pparams->forward[1] +
         pparams->vieworg[1];
    pparams->vieworg[2] =
         pcVar3->value * pparams->up[2] +
         pcVar4->value * pparams->right[2] + pcVar5->value * pparams->forward[2] +
         pparams->vieworg[2];
  }
  iVar6 = CL_IsThirdPerson();
  if (iVar6 != 0) {
                    /* Unresolved local var: Vector ofs@[???] */
    local_54 = 0.0;
    local_58 = 0.0;
    local_5c = 0.0;
    CL_CameraOffset(&local_5c);
    local_74 = 0.0;
    local_7c = local_5c;
    local_78 = local_58;
    (*gEngfuncs.pfnAngleVectors)(&local_7c,&local_6c,local_40,local_34);
    fVar15 = -local_54;
    pparams->vieworg[0] = local_6c * fVar15 + pparams->vieworg[0];
    pparams->vieworg[1] = local_68 * fVar15 + pparams->vieworg[1];
    pparams->vieworg[2] = fVar15 * local_64 + pparams->vieworg[2];
  }
  (pcVar7->angles).x = pparams->cl_viewangles[0];
  (pcVar7->angles).y = pparams->cl_viewangles[1];
  (pcVar7->angles).z = pparams->cl_viewangles[2];
  V_CalcGunAngle(pparams);
  fVar15 = pparams->simorg[0];
  (pcVar7->origin).x = fVar15;
  fVar14 = pparams->simorg[1];
  (pcVar7->origin).y = fVar14;
  local_94 = local_94 + pparams->simorg[2];
  (pcVar7->origin).z = local_94;
  (pcVar7->origin).x = fVar15 + pparams->viewheight[0];
  (pcVar7->origin).y = fVar14 + pparams->viewheight[1];
  (pcVar7->origin).z = local_94 + pparams->viewheight[2];
  (*gEngfuncs.V_ApplyShake)(&(pcVar7->origin).x,&(pcVar7->angles).x,0.9);
  fVar15 = fVar13 * 0.4;
  (pcVar7->origin).x = fVar15 * pparams->forward[0] + (pcVar7->origin).x;
  (pcVar7->origin).y = fVar15 * pparams->forward[1] + (pcVar7->origin).y;
  (pcVar7->origin).z = fVar15 * pparams->forward[2] + (pcVar7->origin).z;
  fVar15 = (pcVar7->origin).z;
  (pcVar7->angles).y = (pcVar7->angles).y - fVar13 * 0.5;
  (pcVar7->angles).z = (pcVar7->angles).z - fVar13;
  (pcVar7->angles).x = (pcVar7->angles).x - fVar13 * 0.3;
  fVar14 = (fVar13 + fVar15) - 1.0;
  (pcVar7->origin).z = fVar14;
  fVar15 = pparams->viewsize;
  if (fVar15 == 110.0) {
    (pcVar7->origin).z = fVar14 + 1.0;
  }
  else if (fVar15 == 100.0) {
    (pcVar7->origin).z = fVar14 + 2.0;
  }
  else if (fVar15 == 90.0) {
    (pcVar7->origin).z = fVar14 + 1.0;
  }
  else if (fVar15 == 80.0) {
    (pcVar7->origin).z = fVar14 + 0.5;
  }
  fVar15 = pparams->viewangles[1];
  fVar14 = pparams->punchangle[1];
  fVar1 = pparams->viewangles[2];
  fVar2 = pparams->punchangle[2];
  pparams->viewangles[0] = pparams->viewangles[0] + pparams->punchangle[0] + ev_punchangle.x;
  pparams->viewangles[1] = fVar15 + fVar14 + ev_punchangle.y;
  pparams->viewangles[2] = fVar1 + fVar2 + ev_punchangle.z;
  fVar15 = pparams->frametime;
                    /* Unresolved local var: float len@[???] */
  fVar14 = VectorNormalize(&ev_punchangle.x);
  fVar14 = fVar14 - (fVar14 * 0.5 + 10.0) * fVar15;
  if (fVar14 <= 0.0) {
    fVar14 = 0.0;
  }
  VectorScale(&ev_punchangle.x,fVar14,&ev_punchangle.x);
  fVar15 = 0.0;
  if (pparams->smoothing == 0) {
    local_54 = pparams->simorg[2];
    fVar14 = local_54;
    if ((pparams->onground != 0) && (0.0 < local_54 - V_CalcNormalRefdef::lexical_block_0::oldz)) {
                    /* Unresolved local var: float steptime@[???] */
      fVar14 = pparams->time - V_CalcNormalRefdef::lexical_block_0::lasttime;
      if (0.0 <= fVar14) {
        fVar15 = fVar14 * 150.0;
      }
      V_CalcNormalRefdef::lexical_block_0::oldz = fVar15 + V_CalcNormalRefdef::lexical_block_0::oldz
      ;
      if (local_54 < V_CalcNormalRefdef::lexical_block_0::oldz) {
        V_CalcNormalRefdef::lexical_block_0::oldz = local_54;
      }
      if (18.0 < local_54 - V_CalcNormalRefdef::lexical_block_0::oldz) {
        V_CalcNormalRefdef::lexical_block_0::oldz = local_54 - 18.0;
      }
      local_54 = V_CalcNormalRefdef::lexical_block_0::oldz - local_54;
      pparams->vieworg[2] = pparams->vieworg[2] + local_54;
      (pcVar7->origin).z = local_54 + (pcVar7->origin).z;
      local_54 = pparams->simorg[2];
      fVar14 = V_CalcNormalRefdef::lexical_block_0::oldz;
    }
  }
  else {
    local_54 = pparams->simorg[2];
    fVar14 = local_54;
  }
  V_CalcNormalRefdef::lexical_block_0::oldz = fVar14;
                    /* Unresolved local var: Vector delta@[???] */
  local_5c = pparams->simorg[0] - V_CalcNormalRefdef::lexical_block_0::lexical_block_0_4::lastorg[0]
  ;
  local_58 = pparams->simorg[1] - V_CalcNormalRefdef::lexical_block_0::lexical_block_0_4::lastorg[1]
  ;
  local_54 = local_54 - V_CalcNormalRefdef::lexical_block_0::lexical_block_0_4::lastorg[2];
  fVar15 = Length(&local_5c);
  if (fVar15 != 0.0) {
    uVar9 = V_CalcNormalRefdef::lexical_block_0::ViewInterp.CurrentOrigin & 0x3f;
    V_CalcNormalRefdef::lexical_block_0::ViewInterp.Origins[uVar9][0] = pparams->simorg[0];
    V_CalcNormalRefdef::lexical_block_0::ViewInterp.Origins[uVar9][1] = pparams->simorg[1];
    V_CalcNormalRefdef::lexical_block_0::ViewInterp.Origins[uVar9][2] = pparams->simorg[2];
    V_CalcNormalRefdef::lexical_block_0::ViewInterp.OriginTime[uVar9] = pparams->time;
    V_CalcNormalRefdef::lexical_block_0::lexical_block_0_4::lastorg[0] = pparams->simorg[0];
    V_CalcNormalRefdef::lexical_block_0::lexical_block_0_4::lastorg[1] = pparams->simorg[1];
    V_CalcNormalRefdef::lexical_block_0::lexical_block_0_4::lastorg[2] = pparams->simorg[2];
    V_CalcNormalRefdef::lexical_block_0::ViewInterp.CurrentOrigin =
         V_CalcNormalRefdef::lexical_block_0::ViewInterp.CurrentOrigin + 1;
  }
  if (((cl_vsmoothing != (cvar_t *)0x0) && (fVar15 = cl_vsmoothing->value, fVar15 != 0.0)) &&
     ((pparams->smoothing != 0 && (1 < pparams->maxclients)))) {
                    /* Unresolved local var: int foundidx@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float t@[???] */
    if (fVar15 < 0.0) {
      (*gEngfuncs.Cvar_SetValue)("cl_vsmoothing",0.0);
      fVar15 = cl_vsmoothing->value;
    }
    fVar15 = pparams->time - fVar15;
    uVar9 = V_CalcNormalRefdef::lexical_block_0::ViewInterp.CurrentOrigin - 2;
    do {
      uVar12 = uVar9 & 0x3f;
      fVar14 = V_CalcNormalRefdef::lexical_block_0::ViewInterp.OriginTime[uVar12];
      if (fVar14 <= fVar15) {
        if (fVar14 != 0.0) {
                    /* Unresolved local var: Vector delta@[???]
                       Unresolved local var: double frac@[???]
                       Unresolved local var: double dt@[???]
                       Unresolved local var: Vector neworg@[???] */
          uVar9 = uVar9 + 1 & 0x3f;
          fVar1 = V_CalcNormalRefdef::lexical_block_0::ViewInterp.OriginTime[uVar9] - fVar14;
          if (0.0 < fVar1) {
            fVar1 = (fVar15 - fVar14) / fVar1;
            if (1.0 < fVar1) {
              fVar1 = 1.0;
            }
            local_5c = V_CalcNormalRefdef::lexical_block_0::ViewInterp.Origins[uVar9][0] -
                       V_CalcNormalRefdef::lexical_block_0::ViewInterp.Origins[uVar12][0];
            local_58 = V_CalcNormalRefdef::lexical_block_0::ViewInterp.Origins[uVar9][1] -
                       V_CalcNormalRefdef::lexical_block_0::ViewInterp.Origins[uVar12][1];
            local_54 = V_CalcNormalRefdef::lexical_block_0::ViewInterp.Origins[uVar9][2] -
                       V_CalcNormalRefdef::lexical_block_0::ViewInterp.Origins[uVar12][2];
            VectorMA(V_CalcNormalRefdef::lexical_block_0::ViewInterp.Origins[uVar12],fVar1,&local_5c
                     ,&local_28);
            fVar15 = Length(&local_5c);
            if (fVar15 < 64.0) {
              local_5c = local_28 - pparams->simorg[0];
              fVar15 = pparams->simorg[1];
              local_58 = local_24 - fVar15;
              fVar14 = pparams->simorg[2];
              local_54 = local_20 - fVar14;
              pparams->simorg[0] = pparams->simorg[0] + local_5c;
              pparams->simorg[1] = fVar15 + local_58;
              pparams->simorg[2] = fVar14 + local_54;
              pparams->vieworg[0] = pparams->vieworg[0] + local_5c;
              pparams->vieworg[1] = pparams->vieworg[1] + local_58;
              pparams->vieworg[2] = pparams->vieworg[2] + local_54;
              (pcVar7->origin).x = local_5c + (pcVar7->origin).x;
              (pcVar7->origin).y = local_58 + (pcVar7->origin).y;
              (pcVar7->origin).z = local_54 + (pcVar7->origin).z;
            }
          }
        }
        break;
      }
      uVar9 = uVar9 - 1;
    } while (uVar9 != V_CalcNormalRefdef::lexical_block_0::ViewInterp.CurrentOrigin - 0x40U);
  }
  v_lastAngles.x = pparams->viewangles[0];
  v_lastAngles.y = pparams->viewangles[1];
  v_lastAngles.z = pparams->viewangles[2];
  v_angles.x = v_lastAngles.x;
  v_angles.y = v_lastAngles.y;
  v_angles.z = v_lastAngles.z;
  iVar6 = CL_IsThirdPerson();
  if (iVar6 != 0) {
                    /* Unresolved local var: float pitch@[???] */
    pparams->viewangles[0] = local_7c;
    pparams->viewangles[1] = local_78;
    pparams->viewangles[2] = local_74;
    if (local_7c <= 180.0) {
      fVar15 = local_7c;
      if (local_7c < -180.0) {
        fVar15 = local_7c + 360.0;
      }
    }
    else {
      fVar15 = local_7c - 360.0;
    }
    fVar15 = fVar15 / -3.0;
    (local_8c->angles).x = fVar15;
    (local_8c->curstate).angles.x = fVar15;
    (local_8c->prevstate).angles.x = fVar15;
    (local_8c->latched).prevangles.x = fVar15;
  }
                    /* Unresolved local var: cl_entity_t * viewentity@[???] */
  if ((pparams->maxclients < pparams->viewentity) &&
     (pcVar7 = (*gEngfuncs.GetEntityByIndex)(pparams->viewentity), pcVar7 != (cl_entity_s *)0x0)) {
    pparams->vieworg[0] = (pcVar7->origin).x;
    pparams->vieworg[1] = (pcVar7->origin).y;
    pparams->vieworg[2] = (pcVar7->origin).z;
    v_angles.x = (pcVar7->angles).x;
    pparams->viewangles[0] = v_angles.x;
    v_angles.y = (pcVar7->angles).y;
    pparams->viewangles[1] = v_angles.y;
    v_angles.z = (pcVar7->angles).z;
    pparams->viewangles[2] = v_angles.z;
  }
  V_CalcNormalRefdef::lexical_block_0::lasttime = pparams->time;
  v_origin.x = pparams->vieworg[0];
  v_origin.y = pparams->vieworg[1];
  v_origin.z = pparams->vieworg[2];
  return;
}


// V_CalcRefdef  @ 000abbd0
void V_CalcRefdef(ref_params_s *pparams)

{
  if (pparams->intermission != 0) {
    V_CalcIntermissionRefdef(pparams);
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


// V_CalcRoll  @ 000a8bf0
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
  if (velocity.x <= fVar1) {
    return angles.z * fVar2;
  }
  return ((fVar1 * angles.z) / velocity.x) * fVar2;
}


// V_CalcSpectatorRefdef  @ 000ab540
void V_CalcSpectatorRefdef(ref_params_s *pparams)

{
  float fVar1;
  vec_t vVar2;
  float fVar3;
  cl_entity_s *pcVar4;
  cl_entity_s *pcVar5;
  model_s *pmVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  float *extraout_ECX;
  float *extraout_ECX_00;
  float *extraout_ECX_01;
  float *extraout_ECX_02;
  float *extraout_ECX_03;
  float *extraout_ECX_04;
  float *extraout_ECX_05;
  float *pfVar10;
  float *extraout_ECX_06;
  float *cl_angles;
  float *extraout_EDX;
  float *extraout_EDX_00;
  float *extraout_EDX_01;
  float *extraout_EDX_02;
  float *extraout_EDX_03;
  float *extraout_EDX_04;
  float *extraout_EDX_05;
  bool bVar11;
  float *pfVar12;
  float *in_stack_ffffffb8;
  float *in_stack_ffffffbc;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: cl_entity_t * ent@[???] */
  if ((V_CalcSpectatorRefdef(ref_params_s*)::velocity == '\0') &&
     (iVar9 = __cxa_guard_acquire(&V_CalcSpectatorRefdef(ref_params_s*)::velocity), iVar9 != 0)) {
    V_CalcSpectatorRefdef::lexical_block_0::velocity.x = 0.0;
    V_CalcSpectatorRefdef::lexical_block_0::velocity.y = 0.0;
    V_CalcSpectatorRefdef::lexical_block_0::velocity.z = 0.0;
    __cxa_guard_release(&V_CalcSpectatorRefdef(ref_params_s*)::velocity);
  }
  pfVar7 = (float *)g_iUser2;
  pcVar4 = (*gEngfuncs.GetEntityByIndex)(g_iUser2);
  cl_angles = (float *)0x0;
  bVar11 = g_iUser1 != 4;
  pparams->onlyClientDraw = 0;
  v_sim_org.x = pparams->simorg[0];
  v_sim_org.y = pparams->simorg[1];
  v_sim_org.z = pparams->simorg[2];
  v_cl_angles.x = pparams->cl_viewangles[0];
  v_cl_angles.y = pparams->cl_viewangles[1];
  v_cl_angles.z = pparams->cl_viewangles[2];
  v_angles.x = pparams->viewangles[0];
  v_angles.y = pparams->viewangles[1];
  v_angles.z = pparams->viewangles[2];
  v_origin.x = pparams->vieworg[0];
  v_origin.y = pparams->vieworg[1];
  v_origin.z = pparams->vieworg[2];
  pfVar10 = extraout_ECX;
  if (((bVar11) && ((gHUD.m_Spectator.m_pip)->value != 2.0)) || (pcVar4 == (cl_entity_s *)0x0))
  goto LAB_000ab5ff;
                    /* Unresolved local var: float timeDiff@[???] */
  fVar1 = (pcVar4->curstate).msg_time - (pcVar4->prevstate).msg_time;
  if (0.0 < fVar1) {
                    /* Unresolved local var: Vector distance@[???] */
    pfVar7 = &local_28;
    local_28 = (pcVar4->prevstate).origin.x - (pcVar4->curstate).origin.x;
    local_24 = (pcVar4->prevstate).origin.y - (pcVar4->curstate).origin.y;
    local_20 = (pcVar4->prevstate).origin.z - (pcVar4->curstate).origin.z;
    in_stack_ffffffb8 = (float *)(1.0 / fVar1);
    in_stack_ffffffbc = pfVar7;
    VectorScale(pfVar7,(float)in_stack_ffffffb8,pfVar7);
    V_CalcSpectatorRefdef::lexical_block_0::velocity.x =
         local_28 * 0.1 + V_CalcSpectatorRefdef::lexical_block_0::velocity.x * 0.9;
    fVar3 = local_24 * 0.1 + V_CalcSpectatorRefdef::lexical_block_0::velocity.y * 0.9;
    fVar1 = local_20 * 0.1 + V_CalcSpectatorRefdef::lexical_block_0::velocity.z * 0.9;
    V_CalcSpectatorRefdef::lexical_block_0::velocity.y = fVar3;
    V_CalcSpectatorRefdef::lexical_block_0::velocity.z = fVar1;
    pparams->simvel[0] = V_CalcSpectatorRefdef::lexical_block_0::velocity.x;
    pparams->simvel[1] = fVar3;
    pparams->simvel[2] = fVar1;
    iVar9 = (*gEngfuncs.IsSpectateOnly)();
    pfVar10 = extraout_ECX_04;
    cl_angles = extraout_EDX_03;
  }
  else {
    iVar9 = (*gEngfuncs.IsSpectateOnly)();
    pfVar10 = extraout_ECX_00;
    cl_angles = extraout_EDX;
  }
  if ((iVar9 == 0) && ((gHUD.m_Spectator.m_pip)->value != 2.0)) {
    fVar1 = (pcVar4->angles).x;
    pparams->cl_viewangles[0] = fVar1;
    pparams->cl_viewangles[1] = (pcVar4->angles).y;
    vVar2 = (pcVar4->angles).z;
    pparams->cl_viewangles[0] = fVar1 * -3.0;
    pparams->cl_viewangles[2] = vVar2;
    goto LAB_000ab5ff;
  }
                    /* Unresolved local var: cl_entity_t * gunModel@[???] */
  in_stack_ffffffbc = pparams->cl_viewangles;
  in_stack_ffffffb8 = pparams->simorg;
  pfVar7 = (float *)g_iUser2;
  V_GetInEyePos(g_iUser2,in_stack_ffffffb8,in_stack_ffffffbc);
  pparams->health = 1;
  pcVar5 = (*gEngfuncs.GetViewModel)();
  pfVar12 = (float *)(pcVar4->curstate).weaponmodel;
  pfVar10 = extraout_ECX_01;
  cl_angles = extraout_EDX_00;
  if (pfVar12 == (float *)V_CalcSpectatorRefdef::lexical_block_0::lastWeaponModelIndex) {
LAB_000abb78:
    if (V_CalcSpectatorRefdef::lexical_block_0::lastViewModelIndex != 0) {
      pfVar7 = (float *)V_CalcSpectatorRefdef::lexical_block_0::lastViewModelIndex;
      pmVar6 = (*IEngineStudio.GetModelByIndex)
                         (V_CalcSpectatorRefdef::lexical_block_0::lastViewModelIndex);
      (pcVar5->curstate).frame = 0.0;
      pcVar5->model = pmVar6;
      (pcVar5->curstate).modelindex = V_CalcSpectatorRefdef::lexical_block_0::lastViewModelIndex;
      (pcVar5->curstate).colormap = 0;
      pcVar5->index = g_iUser2;
      pfVar10 = extraout_ECX_06;
      cl_angles = extraout_EDX_05;
      goto LAB_000ab5ff;
    }
  }
  else {
    V_CalcSpectatorRefdef::lexical_block_0::lastWeaponModelIndex = (int)pfVar12;
                    /* Unresolved local var: model_s * weaponModel@[???] */
    pmVar6 = (*IEngineStudio.GetModelByIndex)((int)pfVar12);
    pfVar10 = extraout_ECX_02;
    cl_angles = extraout_EDX_01;
    if (pmVar6 != (model_s *)0x0) {
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int i@[???] */
      iVar9 = 0;
      pfVar7 = (float *)strlen(pmVar6->name);
      while( true ) {
        in_stack_ffffffb8 =
             (float *)V_FindViewModelByWeaponModel::lexical_block_0::modelmap[iVar9][0];
        in_stack_ffffffbc = pfVar7;
        iVar8 = strncasecmp(pmVar6->name,(char *)in_stack_ffffffb8,(size_t)pfVar7);
        if (iVar8 == 0) break;
        iVar9 = iVar9 + 1;
      }
      pfVar12 = (float *)V_FindViewModelByWeaponModel::lexical_block_0::modelmap[iVar9][1];
      V_CalcSpectatorRefdef::lexical_block_0::lastViewModelIndex =
           (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)((char *)pfVar12);
      pfVar10 = extraout_ECX_03;
      cl_angles = extraout_EDX_02;
      if (V_CalcSpectatorRefdef::lexical_block_0::lastViewModelIndex != 0) {
        in_stack_ffffffb8 = (float *)0x0;
        pfVar7 = (float *)0x0;
        (*gEngfuncs.pfnWeaponAnim)(0,0);
        pfVar10 = extraout_ECX_05;
        cl_angles = extraout_EDX_04;
        goto LAB_000abb78;
      }
    }
    V_CalcSpectatorRefdef::lexical_block_0::lastViewModelIndex = 0;
    V_CalcSpectatorRefdef::lexical_block_0::lastWeaponModelIndex = 0;
    pfVar7 = pfVar12;
  }
  pcVar5->model = (model_s *)0x0;
LAB_000ab5ff:
  iVar9 = g_iUser2;
  v_frametime = pparams->frametime;
  if (pparams->nextView == 0) {
    switch(g_iUser1) {
    case 1:
      V_GetChasePos(g_iUser2,(float *)0x0,pfVar10,pfVar7);
      break;
    case 2:
      V_GetChasePos(g_iUser2,&v_cl_angles.x,pfVar10,pfVar7);
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
      pparams->onlyClientDraw = 1;
      V_GetMapFreePosition(pfVar7,in_stack_ffffffb8,in_stack_ffffffbc);
      break;
    case 6:
      pparams->onlyClientDraw = 1;
      V_GetMapChasePosition(iVar9,(float *)0x1,pfVar10,pfVar7);
    }
    if ((gHUD.m_Spectator.m_pip)->value != 0.0) {
      pparams->nextView = 1;
    }
    gHUD.m_Spectator.m_iDrawCycle = 0;
  }
  else {
    pparams->viewport[0] =
         (int)((float)gHUD.m_Spectator.m_OverviewData.insetWindowX *
              ((float)gHUD.m_scrinfo.iWidth / 640.0));
    pparams->viewport[1] =
         (int)((float)gHUD.m_Spectator.m_OverviewData.insetWindowY *
              ((float)gHUD.m_scrinfo.iHeight / 480.0));
    pparams->viewport[2] =
         (int)((float)gHUD.m_Spectator.m_OverviewData.insetWindowWidth *
              ((float)gHUD.m_scrinfo.iWidth / 640.0));
    pparams->viewport[3] =
         (int)((float)gHUD.m_Spectator.m_OverviewData.insetWindowHeight *
              ((float)gHUD.m_scrinfo.iHeight / 480.0));
    pparams->nextView = 0;
    iVar9 = (int)(gHUD.m_Spectator.m_pip)->value;
    if (iVar9 == 2) {
      V_CalcNormalRefdef(pparams);
    }
    else if (iVar9 < 3) {
      if (iVar9 == 1) {
        V_GetChasePos(g_iUser2,&v_cl_angles.x,pfVar10,pfVar7);
      }
    }
    else if (iVar9 == 3) {
      pparams->onlyClientDraw = 1;
      V_GetMapFreePosition(pfVar7,in_stack_ffffffb8,in_stack_ffffffbc);
    }
    else if (iVar9 == 4) {
      bVar11 = g_iUser1 == 3;
      pparams->onlyClientDraw = 1;
      if (bVar11) {
        V_GetMapChasePosition(0,cl_angles,pfVar10,pfVar7);
      }
      else {
        V_GetMapChasePosition(g_iUser2,cl_angles,pfVar10,pfVar7);
      }
    }
    gHUD.m_Spectator.m_iDrawCycle = 1;
  }
  pparams->cl_viewangles[0] = v_cl_angles.x;
  pparams->cl_viewangles[1] = v_cl_angles.y;
  pparams->cl_viewangles[2] = v_cl_angles.z;
  pparams->viewangles[0] = v_angles.x;
  pparams->viewangles[1] = v_angles.y;
  pparams->viewangles[2] = v_angles.z;
  pparams->vieworg[0] = v_origin.x;
  pparams->vieworg[1] = v_origin.y;
  pparams->vieworg[2] = v_origin.z;
  return;
}


// V_CalcViewRoll  @ 000a90c0
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
    fVar1 = pparams->movevars->rollspeed;
    fVar2 = pparams->movevars->rollangle;
    local_3c = (pcVar7->angles).x;
    fVar3 = pparams->simvel[0];
    fVar4 = pparams->simvel[1];
    fVar5 = pparams->simvel[2];
    local_38 = (pcVar7->angles).y;
    local_34 = (pcVar7->angles).z;
                    /* Unresolved local var: float sign@[???]
                       Unresolved local var: float side@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: float value@[???] */
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
      fVar2 = (fVar2 * fVar3) / fVar1;
    }
    iVar6 = pparams->health;
    pparams->viewangles[2] = fVar2 * fVar4 + pparams->viewangles[2];
    if ((iVar6 < 1) && (pparams->viewheight[2] != 0.0)) {
      pparams->viewangles[2] = 80.0;
      return;
    }
  }
  return;
}


// V_DriftPitch  @ 000a8cc0
void V_DriftPitch(ref_params_s *pparams)

{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  int iVar5;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: float delta@[???]
                       Unresolved local var: float move@[???] */
  iVar5 = (*gEngfuncs.IsNoClipping)();
  dVar4 = pd.laststop;
  if ((((iVar5 == 0) && (pparams->onground != 0)) && (pparams->demoplayback == 0)) &&
     (pparams->spectator == 0)) {
    if (pd.nodrift == 0) {
      fVar1 = pparams->cl_viewangles[0];
      fVar2 = pparams->idealpitch - fVar1;
      if (fVar2 == 0.0) {
        pd.pitchvel = 0.0;
        return;
      }
      fVar3 = pparams->frametime * pd.pitchvel;
      pd.pitchvel = (pparams->frametime * 0.25 + 1.0) * pd.pitchvel;
      if (fVar2 <= 0.0) {
        if (fVar2 < 0.0) {
          if (-fVar2 < fVar3) {
            pd.pitchvel = 0.0;
            fVar3 = -fVar2;
          }
          pparams->cl_viewangles[0] = fVar1 - fVar3;
        }
      }
      else {
        if (fVar2 < fVar3) {
          pd.pitchvel = 0.0;
          fVar3 = fVar2;
        }
        pparams->cl_viewangles[0] = fVar3 + fVar1;
      }
    }
    else if ((0.0 < v_centermove->value) && (((byte)in_mlook.state & 1) == 0)) {
      fVar1 = pparams->cmd->forwardmove;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      if (cl_forwardspeed->value <= fVar1) {
        pd.driftmove = pd.driftmove + pparams->frametime;
      }
      else {
        pd.driftmove = 0.0;
      }
      if (((v_centermove->value < pd.driftmove) &&
          ((*gEngfuncs.GetClientTime)(), (longdouble)dVar4 != extraout_ST0)) &&
         ((pd.nodrift != 0 || (pd.pitchvel == 0.0)))) {
        pd.nodrift = 0;
        pd.driftmove = 0.0;
        pd.pitchvel = v_centerspeed->value;
      }
    }
  }
  else {
    pd.driftmove = 0.0;
    pd.pitchvel = 0.0;
  }
  return;
}


// V_DropPunchAngle  @ 000abc20
void V_DropPunchAngle(float frametime,float *ev_punchangle)

{
  float fVar1;
  
                    /* Unresolved local var: float len@[???] */
  fVar1 = VectorNormalize(ev_punchangle);
  fVar1 = fVar1 - (fVar1 * 0.5 + 10.0) * frametime;
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  VectorScale(ev_punchangle,fVar1,ev_punchangle);
  return;
}


// V_FindViewModelByWeaponModel  @ 000ab4d0
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
      iVar1 = strncasecmp(__s->name,
                          V_FindViewModelByWeaponModel::lexical_block_0::modelmap[iVar2][0],__n);
      if (iVar1 == 0) break;
      iVar2 = iVar2 + 1;
    }
                    /* WARNING: Could not recover jumptable at 0x000ab535. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)
                      (V_FindViewModelByWeaponModel::lexical_block_0::modelmap[iVar2][1]);
    return iVar2;
  }
  return 0;
}


// V_GetChaseOrigin  @ 000a7810
void __regparm2 V_GetChaseOrigin(float *angles,float *origin,float distance,float *returnvec)

{
  pfnEngSrc_GetEntityByIndex_t p_Var1;
  pmtrace_s *ppVar2;
  int iVar3;
  cl_entity_s *pcVar4;
  float fVar5;
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
  ppVar2 = (*gEngfuncs.PM_TraceLine)(&local_28,local_40,0,2,-1);
  p_Var1 = gEngfuncs.GetEntityByIndex;
  if (0 < ppVar2->ent) {
    iVar3 = PM_GetPhysEntInfo(ppVar2->ent);
    pcVar4 = (*p_Var1)(iVar3);
    if ((pcVar4 != (cl_entity_s *)0x0) &&
       ((((pcVar4->curstate).solid != 4 || (pcVar4->player != 0)) &&
        (fVar5 = Distance(&(ppVar2->endpos).x,local_40), 1.0 <= fVar5)))) {
      local_28 = (ppVar2->endpos).x;
      local_24 = (ppVar2->endpos).y;
      local_20 = (ppVar2->endpos).z;
      ppVar2 = (*gEngfuncs.PM_TraceLine)(&local_28,local_40,0,2,ppVar2->ent);
      p_Var1 = gEngfuncs.GetEntityByIndex;
      if (0 < ppVar2->ent) {
        iVar3 = PM_GetPhysEntInfo(ppVar2->ent);
        pcVar4 = (*p_Var1)(iVar3);
        if (((pcVar4 != (cl_entity_s *)0x0) &&
            (((pcVar4->curstate).solid != 4 || (pcVar4->player != 0)))) &&
           (fVar5 = Distance(&(ppVar2->endpos).x,local_40), 1.0 <= fVar5)) {
          local_28 = (ppVar2->endpos).x;
          local_24 = (ppVar2->endpos).y;
          local_20 = (ppVar2->endpos).z;
          ppVar2 = (*gEngfuncs.PM_TraceLine)(&local_28,local_40,0,2,ppVar2->ent);
          p_Var1 = gEngfuncs.GetEntityByIndex;
          if (0 < ppVar2->ent) {
            iVar3 = PM_GetPhysEntInfo(ppVar2->ent);
            pcVar4 = (*p_Var1)(iVar3);
            if (((pcVar4 != (cl_entity_s *)0x0) &&
                (((pcVar4->curstate).solid != 4 || (pcVar4->player != 0)))) &&
               (fVar5 = Distance(&(ppVar2->endpos).x,local_40), 1.0 <= fVar5)) {
              local_28 = (ppVar2->endpos).x;
              local_24 = (ppVar2->endpos).y;
              local_20 = (ppVar2->endpos).z;
              ppVar2 = (*gEngfuncs.PM_TraceLine)(&local_28,local_40,0,2,ppVar2->ent);
              p_Var1 = gEngfuncs.GetEntityByIndex;
              if (0 < ppVar2->ent) {
                iVar3 = PM_GetPhysEntInfo(ppVar2->ent);
                pcVar4 = (*p_Var1)(iVar3);
                if ((pcVar4 != (cl_entity_s *)0x0) &&
                   ((((pcVar4->curstate).solid != 4 || (pcVar4->player != 0)) &&
                    (fVar5 = Distance(&(ppVar2->endpos).x,local_40), 1.0 <= fVar5)))) {
                  local_28 = (ppVar2->endpos).x;
                  local_24 = (ppVar2->endpos).y;
                  local_20 = (ppVar2->endpos).z;
                  ppVar2 = (*gEngfuncs.PM_TraceLine)(&local_28,local_40,0,2,ppVar2->ent);
                  p_Var1 = gEngfuncs.GetEntityByIndex;
                  if (0 < ppVar2->ent) {
                    iVar3 = PM_GetPhysEntInfo(ppVar2->ent);
                    pcVar4 = (*p_Var1)(iVar3);
                    if (((pcVar4 != (cl_entity_s *)0x0) &&
                        (((pcVar4->curstate).solid != 4 || (pcVar4->player != 0)))) &&
                       (fVar5 = Distance(&(ppVar2->endpos).x,local_40), 1.0 <= fVar5)) {
                      local_28 = (ppVar2->endpos).x;
                      local_24 = (ppVar2->endpos).y;
                      local_20 = (ppVar2->endpos).z;
                      ppVar2 = (*gEngfuncs.PM_TraceLine)(&local_28,local_40,0,2,ppVar2->ent);
                      p_Var1 = gEngfuncs.GetEntityByIndex;
                      if (0 < ppVar2->ent) {
                        iVar3 = PM_GetPhysEntInfo(ppVar2->ent);
                        pcVar4 = (*p_Var1)(iVar3);
                        if (((pcVar4 != (cl_entity_s *)0x0) &&
                            (((pcVar4->curstate).solid != 4 || (pcVar4->player != 0)))) &&
                           (fVar5 = Distance(&(ppVar2->endpos).x,local_40), 1.0 <= fVar5)) {
                          local_28 = (ppVar2->endpos).x;
                          local_24 = (ppVar2->endpos).y;
                          local_20 = (ppVar2->endpos).z;
                          ppVar2 = (*gEngfuncs.PM_TraceLine)(&local_28,local_40,0,2,ppVar2->ent);
                          p_Var1 = gEngfuncs.GetEntityByIndex;
                          if (0 < ppVar2->ent) {
                            iVar3 = PM_GetPhysEntInfo(ppVar2->ent);
                            pcVar4 = (*p_Var1)(iVar3);
                            if ((pcVar4 != (cl_entity_s *)0x0) &&
                               ((((pcVar4->curstate).solid != 4 || (pcVar4->player != 0)) &&
                                (fVar5 = Distance(&(ppVar2->endpos).x,local_40), 1.0 <= fVar5)))) {
                              local_28 = (ppVar2->endpos).x;
                              local_24 = (ppVar2->endpos).y;
                              local_20 = (ppVar2->endpos).z;
                              ppVar2 = (*gEngfuncs.PM_TraceLine)(&local_28,local_40,0,2,ppVar2->ent)
                              ;
                              p_Var1 = gEngfuncs.GetEntityByIndex;
                              if (0 < ppVar2->ent) {
                                iVar3 = PM_GetPhysEntInfo(ppVar2->ent);
                                pcVar4 = (*p_Var1)(iVar3);
                                if (((pcVar4 != (cl_entity_s *)0x0) &&
                                    (((pcVar4->curstate).solid != 4 || (pcVar4->player != 0)))) &&
                                   (fVar5 = Distance(&(ppVar2->endpos).x,local_40), 1.0 <= fVar5)) {
                                  local_28 = (ppVar2->endpos).x;
                                  local_24 = (ppVar2->endpos).y;
                                  local_20 = (ppVar2->endpos).z;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  VectorMA(&(ppVar2->endpos).x,4.0,(float *)&ppVar2->plane,&v_origin.x);
  v_lastDistance = Distance(&(ppVar2->endpos).x,origin);
  return;
}


// V_GetChaseOrigin  @ 000aa1f0
void V_GetChaseOrigin(float *angles,float *origin,float distance,float *returnvec)

{
  pfnEngSrc_GetEntityByIndex_t p_Var1;
  pmtrace_s *ppVar2;
  int iVar3;
  cl_entity_s *pcVar4;
  float fVar5;
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
  ppVar2 = (*gEngfuncs.PM_TraceLine)(&local_28,local_40,0,2,-1);
  p_Var1 = gEngfuncs.GetEntityByIndex;
  if (0 < ppVar2->ent) {
    iVar3 = PM_GetPhysEntInfo(ppVar2->ent);
    pcVar4 = (*p_Var1)(iVar3);
    if ((pcVar4 != (cl_entity_s *)0x0) &&
       ((((pcVar4->curstate).solid != 4 || (pcVar4->player != 0)) &&
        (fVar5 = Distance(&(ppVar2->endpos).x,local_40), 1.0 <= fVar5)))) {
      local_28 = (ppVar2->endpos).x;
      local_24 = (ppVar2->endpos).y;
      local_20 = (ppVar2->endpos).z;
      ppVar2 = (*gEngfuncs.PM_TraceLine)(&local_28,local_40,0,2,ppVar2->ent);
      p_Var1 = gEngfuncs.GetEntityByIndex;
      if (0 < ppVar2->ent) {
        iVar3 = PM_GetPhysEntInfo(ppVar2->ent);
        pcVar4 = (*p_Var1)(iVar3);
        if (((pcVar4 != (cl_entity_s *)0x0) &&
            (((pcVar4->curstate).solid != 4 || (pcVar4->player != 0)))) &&
           (fVar5 = Distance(&(ppVar2->endpos).x,local_40), 1.0 <= fVar5)) {
          local_28 = (ppVar2->endpos).x;
          local_24 = (ppVar2->endpos).y;
          local_20 = (ppVar2->endpos).z;
          ppVar2 = (*gEngfuncs.PM_TraceLine)(&local_28,local_40,0,2,ppVar2->ent);
          p_Var1 = gEngfuncs.GetEntityByIndex;
          if (0 < ppVar2->ent) {
            iVar3 = PM_GetPhysEntInfo(ppVar2->ent);
            pcVar4 = (*p_Var1)(iVar3);
            if (((pcVar4 != (cl_entity_s *)0x0) &&
                (((pcVar4->curstate).solid != 4 || (pcVar4->player != 0)))) &&
               (fVar5 = Distance(&(ppVar2->endpos).x,local_40), 1.0 <= fVar5)) {
              local_28 = (ppVar2->endpos).x;
              local_24 = (ppVar2->endpos).y;
              local_20 = (ppVar2->endpos).z;
              ppVar2 = (*gEngfuncs.PM_TraceLine)(&local_28,local_40,0,2,ppVar2->ent);
              p_Var1 = gEngfuncs.GetEntityByIndex;
              if (0 < ppVar2->ent) {
                iVar3 = PM_GetPhysEntInfo(ppVar2->ent);
                pcVar4 = (*p_Var1)(iVar3);
                if ((pcVar4 != (cl_entity_s *)0x0) &&
                   ((((pcVar4->curstate).solid != 4 || (pcVar4->player != 0)) &&
                    (fVar5 = Distance(&(ppVar2->endpos).x,local_40), 1.0 <= fVar5)))) {
                  local_28 = (ppVar2->endpos).x;
                  local_24 = (ppVar2->endpos).y;
                  local_20 = (ppVar2->endpos).z;
                  ppVar2 = (*gEngfuncs.PM_TraceLine)(&local_28,local_40,0,2,ppVar2->ent);
                  p_Var1 = gEngfuncs.GetEntityByIndex;
                  if (0 < ppVar2->ent) {
                    iVar3 = PM_GetPhysEntInfo(ppVar2->ent);
                    pcVar4 = (*p_Var1)(iVar3);
                    if (((pcVar4 != (cl_entity_s *)0x0) &&
                        (((pcVar4->curstate).solid != 4 || (pcVar4->player != 0)))) &&
                       (fVar5 = Distance(&(ppVar2->endpos).x,local_40), 1.0 <= fVar5)) {
                      local_28 = (ppVar2->endpos).x;
                      local_24 = (ppVar2->endpos).y;
                      local_20 = (ppVar2->endpos).z;
                      ppVar2 = (*gEngfuncs.PM_TraceLine)(&local_28,local_40,0,2,ppVar2->ent);
                      p_Var1 = gEngfuncs.GetEntityByIndex;
                      if (0 < ppVar2->ent) {
                        iVar3 = PM_GetPhysEntInfo(ppVar2->ent);
                        pcVar4 = (*p_Var1)(iVar3);
                        if (((pcVar4 != (cl_entity_s *)0x0) &&
                            (((pcVar4->curstate).solid != 4 || (pcVar4->player != 0)))) &&
                           (fVar5 = Distance(&(ppVar2->endpos).x,local_40), 1.0 <= fVar5)) {
                          local_28 = (ppVar2->endpos).x;
                          local_24 = (ppVar2->endpos).y;
                          local_20 = (ppVar2->endpos).z;
                          ppVar2 = (*gEngfuncs.PM_TraceLine)(&local_28,local_40,0,2,ppVar2->ent);
                          p_Var1 = gEngfuncs.GetEntityByIndex;
                          if (0 < ppVar2->ent) {
                            iVar3 = PM_GetPhysEntInfo(ppVar2->ent);
                            pcVar4 = (*p_Var1)(iVar3);
                            if ((pcVar4 != (cl_entity_s *)0x0) &&
                               ((((pcVar4->curstate).solid != 4 || (pcVar4->player != 0)) &&
                                (fVar5 = Distance(&(ppVar2->endpos).x,local_40), 1.0 <= fVar5)))) {
                              local_28 = (ppVar2->endpos).x;
                              local_24 = (ppVar2->endpos).y;
                              local_20 = (ppVar2->endpos).z;
                              ppVar2 = (*gEngfuncs.PM_TraceLine)(&local_28,local_40,0,2,ppVar2->ent)
                              ;
                              p_Var1 = gEngfuncs.GetEntityByIndex;
                              if (0 < ppVar2->ent) {
                                iVar3 = PM_GetPhysEntInfo(ppVar2->ent);
                                pcVar4 = (*p_Var1)(iVar3);
                                if (((pcVar4 != (cl_entity_s *)0x0) &&
                                    (((pcVar4->curstate).solid != 4 || (pcVar4->player != 0)))) &&
                                   (fVar5 = Distance(&(ppVar2->endpos).x,local_40), 1.0 <= fVar5)) {
                                  local_28 = (ppVar2->endpos).x;
                                  local_24 = (ppVar2->endpos).y;
                                  local_20 = (ppVar2->endpos).z;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  VectorMA(&(ppVar2->endpos).x,4.0,(float *)&ppVar2->plane,returnvec);
  v_lastDistance = Distance(&(ppVar2->endpos).x,origin);
  return;
}


// V_GetChasePos  @ 000a87b0
void __regparm3 V_GetChasePos(int target,float *cl_angles,float *origin,float *angles)

{
  cl_entity_s *ent1;
  cl_entity_s *ent2;
  float *angle;
  float *angle_00;
  float *origin_00;
  float *in_stack_ffffffd8;
  
                    /* Unresolved local var: cl_entity_t * ent@[???] */
  if ((target != 0) && (ent1 = (*gEngfuncs.GetEntityByIndex)(target), ent1 != (cl_entity_s *)0x0)) {
    if ((gHUD.m_Spectator.m_autoDirector)->value == 0.0) {
      if (cl_angles == (float *)0x0) {
        v_angles.y = (ent1->angles).y;
        v_angles.x = -(ent1->angles).x;
        v_angles.z = (ent1->angles).z;
      }
      else {
        v_angles.x = *cl_angles;
        v_angles.y = cl_angles[1];
        v_angles.z = cl_angles[2];
      }
      v_origin.x = (ent1->origin).x;
      v_origin.z = (ent1->origin).z + 28.0;
      v_origin.y = (ent1->origin).y;
      V_GetChaseOrigin(&v_angles.x,&v_origin.x,cl_chasedist->value,in_stack_ffffffd8);
    }
    else if (g_iUser3 == 0) {
      V_GetDirectedChasePosition(ent1,(cl_entity_t *)0xffffffff,angle,(float *)target);
    }
    else {
      origin_00 = (float *)g_iUser3;
      ent2 = (*gEngfuncs.GetEntityByIndex)(g_iUser3);
      V_GetDirectedChasePosition(ent1,ent2,angle_00,origin_00);
    }
    v_resetCamera = 0;
    return;
  }
  v_angles.x = vJumpAngles[0];
  v_angles.y = vJumpAngles[1];
  v_angles.z = vJumpAngles[2];
  v_origin.x = vJumpOrigin[0];
  v_origin.y = vJumpOrigin[1];
  v_origin.z = vJumpOrigin[2];
  return;
}


// V_GetChasePos  @ 000ab010
void V_GetChasePos(int target,float *cl_angles,float *origin,float *angles)

{
  float fVar1;
  vec_t vVar2;
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
        fVar1 = (ent1->angles).x;
        *angles = fVar1;
        angles[1] = (ent1->angles).y;
        vVar2 = (ent1->angles).z;
        *angles = -fVar1;
        angles[2] = vVar2;
      }
      else {
        *angles = *cl_angles;
        angles[1] = cl_angles[1];
        angles[2] = cl_angles[2];
      }
      *origin = (ent1->origin).x;
      origin[1] = (ent1->origin).y;
      pcVar3 = cl_chasedist;
      origin[2] = (ent1->origin).z + 28.0;
      V_GetChaseOrigin(angles,origin,pcVar3->value,origin);
    }
    else if (g_iUser3 == 0) {
      V_GetDirectedChasePosition(ent1,(cl_entity_t *)0xffffffff,angles,origin);
    }
    else {
      ent2 = (*gEngfuncs.GetEntityByIndex)(g_iUser3);
      V_GetDirectedChasePosition(ent1,ent2,angles,origin);
    }
    v_resetCamera = 0;
  }
  return;
}


// V_GetDirectedChasePosition  @ 000a80e0
void __regparm3
V_GetDirectedChasePosition(cl_entity_t *ent1,cl_entity_t *ent2,float *angle,float *origin)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float *in_stack_ffffff78;
  float *finalAngle;
  float in_stack_ffffff7c;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_3c;
  float local_38;
  float local_34;
  float local_28;
  float local_24;
  float local_20;
  
  iVar3 = gHUD.m_Spectator.m_iObserverFlags;
  if (v_resetCamera != 0) {
    v_lastDistance = 4096.0;
  }
  if (ent2 == (cl_entity_t *)0xffffffff) {
    iVar4 = ent1->player;
    if (iVar4 == 0) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
      if ((ent1->curstate).solid != 0) {
        bVar2 = false;
      }
    }
  }
  else {
    iVar4 = ent1->player;
    if ((iVar4 == 0) || ((ent1->curstate).solid != 0)) {
      if (ent2 != (cl_entity_t *)0x0) {
                    /* Unresolved local var: float[3] newAngle@[???]
                       Unresolved local var: float[3] newOrigin@[???]
                       Unresolved local var: float[3] tempVec@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: float dfactor@[???]
                       Unresolved local var: float distance@[???]
                       Unresolved local var: float d@[???] */
        if ((gHUD.m_Spectator.m_iObserverFlags & 0x20U) == 0) {
          local_50 = 256.0;
          fVar5 = 128.0;
          fVar1 = 1.0;
        }
        else {
          local_50 = 192.0;
          fVar5 = 96.0;
          fVar1 = -1.0;
        }
        if ((gHUD.m_Spectator.m_iObserverFlags & 0x200U) == 0) {
          local_50 = fVar5;
        }
        v_lastDistance = v_frametime * 32.0 + v_lastDistance;
        if (v_lastDistance < local_50) {
          local_50 = v_lastDistance;
        }
        local_4c = (ent1->origin).x;
        local_48 = (ent1->origin).y;
        local_34 = (ent1->origin).z;
        if (iVar4 == 0) {
          local_44 = local_34 + 8.0;
        }
        else {
          local_44 = local_34 + 17.0;
        }
        local_3c = (ent2->origin).x - local_4c;
        local_38 = (ent2->origin).y - local_48;
        local_34 = (ent2->origin).z - local_34;
        finalAngle = &local_3c;
        VectorAngles(&local_3c,&local_3c);
        local_3c = fVar1 * 12.5 - local_3c;
        if ((iVar3 & 0x10U) == 0) {
          local_38 = local_38 - 22.5;
        }
        else {
          local_38 = local_38 + 22.5;
        }
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: float maxd@[???] */
        NormalizeAngles(&v_lastAngles.x);
        NormalizeAngles(&local_3c);
                    /* Unresolved local var: int i@[???] */
        fVar1 = local_3c - v_lastAngles.x;
        if (180.0 < fVar1) {
          fVar1 = fVar1 - 360.0;
        }
        else if (fVar1 < -180.0) {
          fVar1 = fVar1 + 360.0;
        }
        fVar5 = fVar1;
        if ((fVar1 <= 0.0) && (fVar5 = 0.0 - fVar1, 0.0 - fVar1 <= 0.0)) {
          fVar5 = 0.0;
        }
        fVar1 = local_38 - v_lastAngles.y;
        if (180.0 < fVar1) {
          fVar1 = fVar1 - 360.0;
        }
        else if (fVar1 < -180.0) {
          fVar1 = fVar1 + 360.0;
        }
        if (fVar1 <= 0.0) {
          fVar1 = 0.0 - fVar1;
        }
        if (fVar1 <= fVar5) {
          fVar1 = fVar5;
        }
        fVar5 = local_34 - v_lastAngles.z;
        if (fVar5 <= 180.0) {
          if (fVar5 < -180.0) {
            fVar5 = fVar5 + 360.0;
          }
        }
        else {
          fVar5 = fVar5 - 360.0;
        }
        if (fVar5 <= 0.0) {
          fVar5 = 0.0 - fVar5;
        }
        if (fVar5 <= fVar1) {
          fVar5 = fVar1;
        }
        if ((v_cameraFocusAngle <= fVar5) || (v_cameraMode != 1)) {
          if ((v_cameraRelaxAngle <= fVar5) || (v_cameraMode != 2)) {
            iVar3 = 2;
            v_cameraMode = 2;
          }
          else {
            iVar3 = 1;
            v_cameraMode = 1;
          }
        }
        else {
          local_38 = v_lastAngles.y;
          local_3c = v_lastAngles.x;
          local_34 = v_lastAngles.z;
          iVar3 = 1;
        }
        if ((v_resetCamera == 0) && (iVar3 != 1)) {
          V_SmoothInterpolateAngles(&local_3c,(float *)0x43340000,finalAngle,in_stack_ffffff7c);
        }
        else {
          v_angles.x = local_3c;
          v_angles.y = local_38;
          v_angles.z = local_34;
        }
        V_GetChaseOrigin(&local_3c,&local_4c,local_50,finalAngle);
        if (v_lastDistance < 64.0) {
          v_origin.z = (1.0 - v_lastDistance * 0.015625) * 16.0 + v_origin.z;
        }
        local_28 = (ent2->origin).x - v_origin.x;
        local_24 = (ent2->origin).y - v_origin.y;
        local_20 = (ent2->origin).z - v_origin.z;
        VectorAngles(&local_28,&local_28);
        v_lastAngles.x = v_angles.x;
        v_lastAngles.y = v_angles.y;
        v_lastAngles.z = v_angles.z;
        return;
      }
                    /* Unresolved local var: float[3] newOrigin@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: float dfactor@[???]
                       Unresolved local var: float distance@[???] */
      if ((gHUD.m_Spectator.m_iObserverFlags & 0x20U) == 0) {
        local_50 = 256.0;
        fVar1 = 128.0;
      }
      else {
        local_50 = 192.0;
        fVar1 = 96.0;
      }
      if ((gHUD.m_Spectator.m_iObserverFlags & 0x200U) == 0) {
        local_50 = fVar1;
      }
      local_4c = (ent1->origin).x;
      local_48 = (ent1->origin).y;
      v_lastDistance = v_frametime * 32.0 + v_lastDistance;
      if (v_lastDistance < local_50) {
        local_50 = v_lastDistance;
      }
      fVar1 = (ent1->origin).z;
      if (iVar4 == 0) {
        local_44 = fVar1 + 8.0;
      }
      else {
        local_44 = fVar1 + 17.0;
      }
      V_GetChaseOrigin(&v_angles.x,&local_4c,local_50,in_stack_ffffff78);
      v_lastAngles.x = v_angles.x;
      v_lastAngles.y = v_angles.y;
      v_lastAngles.z = v_angles.z;
      return;
    }
                    /* Unresolved local var: float[3] newAngle@[???]
                       Unresolved local var: float[3] newOrigin@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: qboolean deadPlayer@[???]
                       Unresolved local var: float dfactor@[???]
                       Unresolved local var: float distance@[???] */
    bVar2 = true;
  }
  if ((gHUD.m_Spectator.m_iObserverFlags & 0x20U) == 0) {
    fVar1 = 256.0;
    fVar5 = 192.0;
    fVar6 = 128.0;
    local_4c = 12.5;
  }
  else {
    fVar1 = 192.0;
    fVar5 = 144.0;
    fVar6 = 96.0;
    local_4c = -12.5;
  }
  if (((gHUD.m_Spectator.m_iObserverFlags & 0x200U) == 0) && (fVar1 = fVar5, !bVar2)) {
    fVar1 = fVar6;
  }
  local_3c = (ent1->origin).x;
  local_38 = (ent1->origin).y;
  v_lastDistance = v_frametime * 32.0 + v_lastDistance;
  if (v_lastDistance < fVar1) {
    fVar1 = v_lastDistance;
  }
  local_34 = (ent1->origin).z;
  if (iVar4 == 0) {
    local_34 = local_34 + 8.0;
  }
  else if (bVar2) {
    local_34 = local_34 + 2.0;
  }
  else {
    local_34 = local_34 + 17.0;
  }
  local_48 = (ent1->angles).y;
  local_44 = (ent1->angles).z;
  if ((gHUD.m_Spectator.m_iObserverFlags & 0x80U) != 0) {
    local_48 = local_48 + 180.0;
  }
  local_4c = (ent1->angles).x + local_4c;
  if ((gHUD.m_Spectator.m_iObserverFlags & 0x200U) != 0) {
    local_4c = 22.5;
  }
  if ((gHUD.m_Spectator.m_iObserverFlags & 0x10U) == 0) {
    local_48 = local_48 - 22.5;
  }
  else {
    local_48 = local_48 + 22.5;
  }
  V_SmoothInterpolateAngles(&local_4c,(float *)0x42f00000,in_stack_ffffff78,in_stack_ffffff7c);
  V_GetChaseOrigin(&v_angles.x,&local_3c,fVar1,in_stack_ffffff78);
  v_lastAngles.x = v_angles.x;
  v_lastAngles.y = v_angles.y;
  v_lastAngles.z = v_angles.z;
  return;
}


// V_GetDirectedChasePosition  @ 000aaec0
void V_GetDirectedChasePosition(cl_entity_t *ent1,cl_entity_t *ent2,float *angle,float *origin)

{
  float fVar1;
  float local_20;
  vec_t local_1c;
  vec_t local_18;
  float local_14;
  
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
      local_20 = 256.0;
      fVar1 = 128.0;
    }
    else {
      local_20 = 192.0;
      fVar1 = 96.0;
    }
    if ((gHUD.m_Spectator.m_iObserverFlags & 0x200U) == 0) {
      local_20 = fVar1;
    }
    local_1c = (ent1->origin).x;
    local_18 = (ent1->origin).y;
    v_lastDistance = v_frametime * 32.0 + v_lastDistance;
    if (v_lastDistance < local_20) {
      local_20 = v_lastDistance;
    }
    local_14 = (ent1->origin).z;
    if (ent1->player == 0) {
      local_14 = local_14 + 8.0;
    }
    else {
      local_14 = local_14 + 17.0;
    }
    V_GetChaseOrigin(angle,&local_1c,local_20,origin);
  }
  else {
    V_GetDoubleTargetsCam(ent1,ent2,angle,origin);
  }
  v_lastAngles.x = *angle;
  v_lastAngles.y = angle[1];
  v_lastAngles.z = angle[2];
  return;
}


// V_GetDoubleTargetsCam  @ 000aaaa0
void V_GetDoubleTargetsCam(cl_entity_t *ent1,cl_entity_t *ent2,float *angle,float *origin)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_3c;
  float local_38;
  float local_34;
  float local_28;
  float local_24;
  float local_20;
  
  iVar3 = gHUD.m_Spectator.m_iObserverFlags;
                    /* Unresolved local var: float[3] newAngle@[???]
                       Unresolved local var: float[3] newOrigin@[???]
                       Unresolved local var: float[3] tempVec@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: float dfactor@[???]
                       Unresolved local var: float distance@[???]
                       Unresolved local var: float d@[???] */
  if ((gHUD.m_Spectator.m_iObserverFlags & 0x20U) == 0) {
    local_50 = 256.0;
    fVar2 = 128.0;
    fVar1 = 1.0;
  }
  else {
    local_50 = 192.0;
    fVar2 = 96.0;
    fVar1 = -1.0;
  }
  if ((gHUD.m_Spectator.m_iObserverFlags & 0x200U) == 0) {
    local_50 = fVar2;
  }
  v_lastDistance = v_frametime * 32.0 + v_lastDistance;
  if (v_lastDistance < local_50) {
    local_50 = v_lastDistance;
  }
  local_3c = (ent1->origin).x;
  local_38 = (ent1->origin).y;
  local_44 = (ent1->origin).z;
  if (ent1->player == 0) {
    local_34 = local_44 + 8.0;
  }
  else {
    local_34 = local_44 + 17.0;
  }
  local_4c = (ent2->origin).x - local_3c;
  local_48 = (ent2->origin).y - local_38;
  local_44 = (ent2->origin).z - local_44;
  VectorAngles(&local_4c,&local_4c);
  local_4c = fVar1 * 12.5 - local_4c;
  if ((iVar3 & 0x10U) == 0) {
    local_48 = local_48 - 22.5;
  }
  else {
    local_48 = local_48 + 22.5;
  }
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: float maxd@[???] */
  NormalizeAngles(&v_lastAngles.x);
  NormalizeAngles(&local_4c);
                    /* Unresolved local var: int i@[???] */
  fVar1 = local_4c - v_lastAngles.x;
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
  fVar1 = local_48 - v_lastAngles.y;
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
  fVar2 = local_44 - v_lastAngles.z;
  if (fVar2 <= 180.0) {
    if (fVar2 < -180.0) {
      fVar2 = fVar2 + 360.0;
    }
  }
  else {
    fVar2 = fVar2 - 360.0;
  }
  if (fVar2 <= 0.0) {
    fVar2 = 0.0 - fVar2;
  }
  if (fVar2 <= fVar1) {
    fVar2 = fVar1;
  }
  if ((v_cameraFocusAngle <= fVar2) || (v_cameraMode != 1)) {
    if ((v_cameraRelaxAngle <= fVar2) || (v_cameraMode != 2)) {
      v_cameraMode = 2;
      iVar3 = 2;
    }
    else {
      v_cameraMode = 1;
      iVar3 = 1;
    }
  }
  else {
    local_48 = v_lastAngles.y;
    local_4c = v_lastAngles.x;
    local_44 = v_lastAngles.z;
    iVar3 = 1;
  }
  if ((v_resetCamera == 0) && (iVar3 != 1)) {
    V_SmoothInterpolateAngles(&v_lastAngles.x,&local_4c,angle,180.0);
  }
  else {
    *angle = local_4c;
    angle[1] = local_48;
    angle[2] = local_44;
  }
  V_GetChaseOrigin(&local_4c,&local_3c,local_50,origin);
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


// V_GetInEyePos  @ 000ab1a0
void V_GetInEyePos(int target,float *origin,float *angles)

{
  float fVar1;
  vec_t vVar2;
  cl_entity_s *pcVar3;
  
                    /* Unresolved local var: cl_entity_t * ent@[DW_OP_reg0(EAX)] */
  if (target == 0) {
    *angles = vJumpAngles[0];
    angles[1] = vJumpAngles[1];
    angles[2] = vJumpAngles[2];
    *origin = vJumpOrigin[0];
    origin[1] = vJumpOrigin[1];
    origin[2] = vJumpOrigin[2];
  }
  else {
    pcVar3 = (*gEngfuncs.GetEntityByIndex)(target);
    if (pcVar3 != (cl_entity_s *)0x0) {
      *origin = (pcVar3->origin).x;
      origin[1] = (pcVar3->origin).y;
      origin[2] = (pcVar3->origin).z;
      fVar1 = (pcVar3->angles).x;
      *angles = fVar1;
      angles[1] = (pcVar3->angles).y;
      vVar2 = (pcVar3->angles).z;
      *angles = fVar1 * -3.0;
      angles[2] = vVar2;
      if ((pcVar3->curstate).solid == 0) {
        angles[2] = 80.0;
        origin[2] = origin[2] - 8.0;
        return;
      }
      if ((pcVar3->curstate).usehull != 1) {
        origin[2] = origin[2] + 28.0;
        return;
      }
      origin[2] = origin[2] + 12.0;
    }
  }
  return;
}


// V_GetMapChasePosition  @ 000a8910
void __regparm3 V_GetMapChasePosition(int target,float *cl_angles,float *origin,float *angles)

{
  cl_entity_s *pcVar1;
  float *origin_00;
  float *angles_00;
  float local_18 [4];
  
                    /* Unresolved local var: Vector forward@[???] */
  if (target == 0) {
    v_angles.y = v_cl_angles.y;
    v_angles.x = (v_cl_angles.x / 90.0) * 38.75 + 51.25;
  }
  else {
    angles_00 = (float *)target;
                    /* Unresolved local var: cl_entity_t * ent@[???] */
    pcVar1 = (*gEngfuncs.GetEntityByIndex)(target);
    if ((gHUD.m_Spectator.m_autoDirector)->value == 0.0) {
      v_origin.z = (pcVar1->origin).z;
      v_angles.y = v_cl_angles.y;
      v_origin.x = (pcVar1->origin).x;
      v_origin.y = (pcVar1->origin).y;
      v_angles.x = (v_cl_angles.x / 90.0) * 38.75 + 51.25;
    }
    else {
      V_GetChasePos(target,&v_cl_angles.x,origin_00,angles_00);
      v_origin.x = (pcVar1->origin).x;
      v_origin.y = (pcVar1->origin).y;
      v_origin.z = (pcVar1->origin).z;
      v_angles.x = 45.0;
    }
  }
  v_angles.z = 0.0;
  v_origin.z = v_origin.z * ((90.0 - v_angles.x) / 90.0);
  (*gEngfuncs.pfnAngleVectors)(&v_angles.x,local_18,(float *)0x0,(float *)0x0);
  VectorNormalize(local_18);
  VectorMA(&v_origin.x,-1536.0,local_18,&v_origin.x);
  return;
}


// V_GetMapChasePosition  @ 000ab350
void V_GetMapChasePosition(int target,float *cl_angles,float *origin,float *angles)

{
  float fVar1;
  cl_entity_s *pcVar2;
  float local_34;
  float local_28 [6];
  
                    /* Unresolved local var: Vector forward@[???] */
  if (target == 0) {
    fVar1 = *cl_angles;
    *angles = fVar1;
    angles[1] = cl_angles[1];
    angles[2] = cl_angles[2];
    local_34 = (fVar1 / 90.0) * 38.75 + 51.25;
    *angles = local_34;
  }
  else {
                    /* Unresolved local var: cl_entity_t * ent@[???] */
    pcVar2 = (*gEngfuncs.GetEntityByIndex)(target);
    if ((gHUD.m_Spectator.m_autoDirector)->value == 0.0) {
      *angles = *cl_angles;
      angles[1] = cl_angles[1];
      angles[2] = cl_angles[2];
      *origin = (pcVar2->origin).x;
      origin[1] = (pcVar2->origin).y;
      origin[2] = (pcVar2->origin).z;
      local_34 = (*angles / 90.0) * 38.75 + 51.25;
      *angles = local_34;
    }
    else {
      V_GetChasePos(target,cl_angles,origin,angles);
      *origin = (pcVar2->origin).x;
      origin[1] = (pcVar2->origin).y;
      origin[2] = (pcVar2->origin).z;
      *angles = 45.0;
      local_34 = 45.0;
    }
  }
  origin[2] = ((90.0 - local_34) / 90.0) * origin[2];
  angles[2] = 0.0;
  (*gEngfuncs.pfnAngleVectors)(angles,local_28,(float *)0x0,(float *)0x0);
  VectorNormalize(local_28);
  VectorMA(origin,-1536.0,local_28,origin);
  return;
}


// V_GetMapFreePosition  @ 000a7750
void V_GetMapFreePosition(float *cl_angles,float *origin,float *angles)

{
  float local_24 [3];
  vec_t local_18;
  vec_t local_14;
  float local_10;
  
                    /* Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector zScaledTarget@[???] */
  v_angles.y = v_cl_angles.y;
  v_angles.z = v_cl_angles.z;
  local_18 = gHUD.m_Spectator.m_mapOrigin.x;
  local_14 = gHUD.m_Spectator.m_mapOrigin.y;
  v_angles.x = (v_cl_angles.x / 90.0) * 38.75 + 51.25;
  local_10 = ((90.0 - v_angles.x) / 90.0) * gHUD.m_Spectator.m_mapOrigin.z;
  (*gEngfuncs.pfnAngleVectors)(&v_angles.x,local_24,(float *)0x0,(float *)0x0);
  VectorNormalize(local_24);
  VectorMA(&local_18,-(4096.0 / gHUD.m_Spectator.m_mapZoom),local_24,&v_origin.x);
  return;
}


// V_GetMapFreePosition  @ 000ab2a0
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


// V_GetSingleTargetCam  @ 000aa7c0
void V_GetSingleTargetCam(cl_entity_t *ent1,float *angle,float *origin)

{
  float distance;
  float fVar1;
  bool bVar2;
  float local_40;
  float local_3c;
  float local_38;
  vec_t local_34;
  vec_t local_2c;
  vec_t local_28;
  float local_24;
  
                    /* Unresolved local var: float[3] newAngle@[???]
                       Unresolved local var: float[3] newOrigin@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: qboolean deadPlayer@[???]
                       Unresolved local var: float dfactor@[???]
                       Unresolved local var: float distance@[???] */
  bVar2 = false;
  if (ent1->player != 0) {
    bVar2 = (ent1->curstate).solid == 0;
  }
  if ((gHUD.m_Spectator.m_iObserverFlags & 0x20U) == 0) {
    distance = 256.0;
    fVar1 = 192.0;
    local_3c = 12.5;
    local_40 = 128.0;
  }
  else {
    distance = 192.0;
    fVar1 = 144.0;
    local_3c = -12.5;
    local_40 = 96.0;
  }
  if (((gHUD.m_Spectator.m_iObserverFlags & 0x200U) == 0) && (distance = fVar1, !bVar2)) {
    distance = local_40;
  }
  local_2c = (ent1->origin).x;
  v_lastDistance = v_frametime * 32.0 + v_lastDistance;
  local_28 = (ent1->origin).y;
  if (v_lastDistance < distance) {
    distance = v_lastDistance;
  }
  local_24 = (ent1->origin).z;
  if (ent1->player == 0) {
    local_24 = local_24 + 8.0;
  }
  else if (bVar2) {
    local_24 = local_24 + 2.0;
  }
  else {
    local_24 = local_24 + 17.0;
  }
  local_38 = (ent1->angles).y;
  local_34 = (ent1->angles).z;
  if ((gHUD.m_Spectator.m_iObserverFlags & 0x80U) != 0) {
    local_38 = local_38 + 180.0;
  }
  local_3c = (ent1->angles).x + local_3c;
  if ((gHUD.m_Spectator.m_iObserverFlags & 0x200U) != 0) {
    local_3c = 22.5;
  }
  if ((gHUD.m_Spectator.m_iObserverFlags & 0x10U) == 0) {
    local_38 = local_38 - 22.5;
  }
  else {
    local_38 = local_38 + 22.5;
  }
  V_SmoothInterpolateAngles(&v_lastAngles.x,&local_3c,angle,120.0);
  V_GetChaseOrigin(angle,&local_2c,distance,origin);
  return;
}


// V_Init  @ 000abc80
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


// V_PunchAxis  @ 000abc70
void V_PunchAxis(int axis,float punch)

{
  (&ev_punchangle.x)[axis] = punch;
  return;
}


// V_ResetChaseCam  @ 000ab190
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void V_ResetChaseCam(void)

{
  v_resetCamera = 1;
  return;
}


// V_SmoothInterpolateAngles  @ 000a7de0
void __regparm1
V_SmoothInterpolateAngles(float *startAngle,float *endAngle,float *finalAngle,float degreesPerSec)

{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
                    /* Unresolved local var: float absd@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: float d@[???]
                       Unresolved local var: float threshhold@[???] */
  NormalizeAngles(&v_lastAngles.x);
  NormalizeAngles(startAngle);
                    /* Unresolved local var: int i@[???] */
  v_angles.x = *startAngle;
  fVar3 = v_angles.x - v_lastAngles.x;
  if (180.0 < fVar3) {
    fVar3 = fVar3 - 360.0;
  }
  else if (fVar3 < -180.0) {
    fVar3 = fVar3 + 360.0;
  }
  bVar1 = fVar3 <= 0.0;
  if (fVar3 <= 0.0) {
    fVar3 = 0.0 - fVar3;
  }
  if (0.01 < fVar3) {
    fVar2 = v_frametime * (float)endAngle;
    if (fVar3 < (float)endAngle * 0.25) {
                    /* Unresolved local var: float h@[???] */
      fVar4 = fVar3 / ((float)endAngle * 0.25);
      fVar2 = fVar4 * fVar4 * fVar2;
    }
    if (fVar2 <= fVar3) {
      if (bVar1) {
        v_angles.x = v_lastAngles.x - fVar2;
      }
      else {
        v_angles.x = fVar2 + v_lastAngles.x;
      }
    }
  }
  v_angles.y = startAngle[1];
  fVar3 = v_angles.y - v_lastAngles.y;
  if (180.0 < fVar3) {
    fVar3 = fVar3 - 360.0;
  }
  else if (fVar3 < -180.0) {
    fVar3 = fVar3 + 360.0;
  }
  bVar1 = fVar3 <= 0.0;
  if (fVar3 <= 0.0) {
    fVar3 = 0.0 - fVar3;
  }
  if (0.01 < fVar3) {
    fVar2 = v_frametime * (float)endAngle;
    if (fVar3 < (float)endAngle * 0.25) {
      fVar4 = fVar3 / ((float)endAngle * 0.25);
      fVar2 = fVar4 * fVar4 * fVar2;
    }
    if (fVar2 <= fVar3) {
      if (bVar1) {
        v_angles.y = v_lastAngles.y - fVar2;
      }
      else {
        v_angles.y = fVar2 + v_lastAngles.y;
      }
    }
  }
  v_angles.z = startAngle[2];
  fVar3 = v_angles.z - v_lastAngles.z;
  if (fVar3 <= 180.0) {
    if (fVar3 < -180.0) {
      fVar3 = fVar3 + 360.0;
    }
  }
  else {
    fVar3 = fVar3 - 360.0;
  }
  bVar1 = fVar3 <= 0.0;
  if (fVar3 <= 0.0) {
    fVar3 = 0.0 - fVar3;
  }
  if (0.01 < fVar3) {
    fVar2 = v_frametime * (float)endAngle;
    if (fVar3 < (float)endAngle * 0.25) {
      fVar4 = fVar3 / ((float)endAngle * 0.25);
      fVar2 = fVar4 * fVar4 * fVar2;
    }
    if (fVar2 <= fVar3) {
      if (bVar1) {
        v_angles.z = v_lastAngles.z - fVar2;
      }
      else {
        v_angles.z = v_lastAngles.z + fVar2;
      }
    }
  }
  NormalizeAngles(&v_angles.x);
  return;
}


// V_SmoothInterpolateAngles  @ 000a9ef0
void V_SmoothInterpolateAngles
               (float *startAngle,float *endAngle,float *finalAngle,float degreesPerSec)

{
  float fVar1;
  bool bVar2;
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
  fVar3 = *endAngle - fVar1;
  if (180.0 < fVar3) {
    fVar3 = fVar3 - 360.0;
    bVar2 = 0.0 < fVar3;
    if (bVar2) goto LAB_000a9f6a;
LAB_000aa070:
    fVar3 = 0.0 - fVar3;
    if (fVar3 <= 0.01) goto LAB_000a9fd6;
LAB_000a9f82:
    fVar5 = v_frametime * degreesPerSec;
    if (fVar3 < degreesPerSec * 0.25) {
                    /* Unresolved local var: float h@[???] */
      fVar4 = fVar3 / (degreesPerSec * 0.25);
      fVar5 = fVar4 * fVar4 * fVar5;
    }
    if (fVar3 < fVar5) goto LAB_000a9fd6;
    if (bVar2) {
      *finalAngle = fVar5 + fVar1;
    }
    else {
      *finalAngle = fVar1 - fVar5;
    }
  }
  else {
    if (fVar3 < -180.0) {
      fVar3 = fVar3 + 360.0;
    }
    bVar2 = 0.0 < fVar3;
    if (!bVar2) goto LAB_000aa070;
LAB_000a9f6a:
    if (0.01 < fVar3) goto LAB_000a9f82;
LAB_000a9fd6:
    *finalAngle = *endAngle;
  }
  fVar1 = startAngle[1];
  fVar3 = endAngle[1] - fVar1;
  if (180.0 < fVar3) {
    fVar3 = fVar3 - 360.0;
  }
  else if (fVar3 < -180.0) {
    fVar3 = fVar3 + 360.0;
  }
  bVar2 = fVar3 <= 0.0;
  if (bVar2) {
    fVar3 = 0.0 - fVar3;
  }
  if (0.01 < fVar3) {
    fVar5 = v_frametime * degreesPerSec;
    if (fVar3 < degreesPerSec * 0.25) {
      fVar4 = fVar3 / (degreesPerSec * 0.25);
      fVar5 = fVar4 * fVar4 * fVar5;
    }
    if (fVar5 <= fVar3) {
      if (bVar2) {
        finalAngle[1] = fVar1 - fVar5;
      }
      else {
        finalAngle[1] = fVar5 + fVar1;
      }
      goto LAB_000aa0a7;
    }
  }
  finalAngle[1] = endAngle[1];
LAB_000aa0a7:
  fVar1 = startAngle[2];
  fVar3 = endAngle[2] - fVar1;
  if (fVar3 <= 180.0) {
    if (fVar3 < -180.0) {
      fVar3 = fVar3 + 360.0;
    }
  }
  else {
    fVar3 = fVar3 - 360.0;
  }
  bVar2 = fVar3 <= 0.0;
  if (bVar2) {
    fVar3 = 0.0 - fVar3;
  }
  if (0.01 < fVar3) {
    fVar5 = v_frametime * degreesPerSec;
    if (fVar3 < degreesPerSec * 0.25) {
      fVar4 = fVar3 / (degreesPerSec * 0.25);
      fVar5 = fVar4 * fVar4 * fVar5;
    }
    if (fVar5 <= fVar3) {
      if (bVar2) {
        finalAngle[2] = fVar1 - fVar5;
        NormalizeAngles(finalAngle);
        return;
      }
      finalAngle[2] = fVar1 + fVar5;
      NormalizeAngles(finalAngle);
      return;
    }
  }
  finalAngle[2] = endAngle[2];
  NormalizeAngles(finalAngle);
  return;
}


// V_StartPitchDrift  @ 000a76d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void V_StartPitchDrift(void)

{
  double dVar1;
  longdouble extraout_ST0;
  
  dVar1 = pd.laststop;
  (*gEngfuncs.GetClientTime)();
  if ((longdouble)dVar1 == extraout_ST0) {
    return;
  }
  if (pd.nodrift == 0) {
    if (NAN(pd.pitchvel)) {
      return;
    }
    if (pd.pitchvel != 0.0) {
      return;
    }
  }
  pd.driftmove = 0.0;
  pd.nodrift = 0;
  pd.pitchvel = v_centerspeed->value;
  return;
}


// V_StopPitchDrift  @ 000a8c90
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


