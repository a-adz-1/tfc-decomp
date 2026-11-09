// Ghidra decompilation of functions from cl_dll/entity.cpp
// 8 functions, ordered by original source line

// HUD_AddEntity  @ 00069860  (line 34)

int HUD_AddEntity(int type,cl_entity_s *ent,char *modelname)

{
  if (type == 0) {
    Bench_CheckEntity(0,(cl_entity_s_conflict *)ent,modelname);
  }
  if ((g_iUser1 != 0) &&
     ((CHudSpectator::AddOverviewEntity(&gHUD.m_Spectator,type,ent,modelname), g_iUser1 == 4 ||
      ((gHUD.m_Spectator.m_pip)->value == 2.0)))) {
    return (uint)(ent->index != g_iUser2);
  }
  return 1;
}


// HUD_TxferLocalOverrides  @ 00069910  (line 77)

void HUD_TxferLocalOverrides(entity_state_s *state,clientdata_s *client)

{
  (state->origin).x = (client->origin).x;
  (state->origin).y = (client->origin).y;
  (state->origin).z = (client->origin).z;
  state->iuser1 = client->iuser1;
  state->iuser2 = client->iuser2;
  state->iuser3 = client->iuser3;
  state->iuser4 = client->iuser4;
  return;
}


// HUD_ProcessPlayerState  @ 00069970  (line 102)

void HUD_ProcessPlayerState(entity_state_s *dst,entity_state_s *src)

{
  cl_entity_s *pcVar1;
  
                    /* Unresolved local var: cl_entity_t * player@[???] */
  (dst->origin).x = (src->origin).x;
  (dst->origin).y = (src->origin).y;
  (dst->origin).z = (src->origin).z;
  (dst->angles).x = (src->angles).x;
  (dst->angles).y = (src->angles).y;
  (dst->angles).z = (src->angles).z;
  (dst->velocity).x = (src->velocity).x;
  (dst->velocity).y = (src->velocity).y;
  (dst->velocity).z = (src->velocity).z;
  dst->frame = src->frame;
  dst->modelindex = src->modelindex;
  dst->skin = src->skin;
  dst->effects = src->effects;
  dst->weaponmodel = src->weaponmodel;
  dst->movetype = src->movetype;
  dst->sequence = src->sequence;
  dst->animtime = src->animtime;
  dst->solid = src->solid;
  dst->rendermode = src->rendermode;
  dst->renderamt = src->renderamt;
  (dst->rendercolor).r = (src->rendercolor).r;
  (dst->rendercolor).g = (src->rendercolor).g;
  (dst->rendercolor).b = (src->rendercolor).b;
  dst->renderfx = src->renderfx;
  dst->framerate = src->framerate;
  dst->body = src->body;
  *(undefined4 *)dst->controller = *(undefined4 *)src->controller;
  *(undefined2 *)dst->blending = *(undefined2 *)src->blending;
  (dst->basevelocity).x = (src->basevelocity).x;
  (dst->basevelocity).y = (src->basevelocity).y;
  (dst->basevelocity).z = (src->basevelocity).z;
  dst->friction = src->friction;
  dst->gravity = src->gravity;
  dst->gaitsequence = src->gaitsequence;
  dst->spectator = src->spectator;
  dst->usehull = src->usehull;
  dst->playerclass = src->playerclass;
  dst->team = src->team;
  dst->colormap = src->colormap;
  dst->fuser1 = src->fuser1;
  pcVar1 = (*gEngfuncs.GetLocalPlayer)();
  if (dst->number == pcVar1->index) {
    g_iPlayerClass = dst->playerclass;
    g_iTeamNumber = dst->team;
    g_iUser1 = src->iuser1;
    g_iUser2 = src->iuser2;
    g_iUser3 = src->iuser3;
  }
  return;
}


// HUD_TxferPredictionData  @ 00069b50  (line 174)

void HUD_TxferPredictionData
               (entity_state_s *ps,entity_state_s *pps,clientdata_s *pcd,clientdata_s *ppcd,
               weapon_data_s *wd,weapon_data_s *pwd)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  weapon_data_s *pwVar6;
  bool bVar7;
  byte bVar8;
  
  bVar8 = 0;
  ps->oldbuttons = pps->oldbuttons;
  ps->flFallVelocity = pps->flFallVelocity;
  ps->iStepLeft = pps->iStepLeft;
  ps->playerclass = pps->playerclass;
  pcd->viewmodel = ppcd->viewmodel;
  pcd->m_iId = ppcd->m_iId;
  pcd->ammo_shells = ppcd->ammo_shells;
  pcd->ammo_nails = ppcd->ammo_nails;
  pcd->ammo_cells = ppcd->ammo_cells;
  pcd->ammo_rockets = ppcd->ammo_rockets;
  pcd->m_flNextAttack = ppcd->m_flNextAttack;
  pcd->fov = ppcd->fov;
  pcd->weaponanim = ppcd->weaponanim;
  pcd->tfstate = ppcd->tfstate;
  pcd->maxspeed = ppcd->maxspeed;
  iVar3 = ppcd->deadflag;
  pcd->deadflag = iVar3;
  iVar1 = ppcd->iuser1;
  pcd->iuser1 = iVar1;
  g_iAlive = (int)(iVar1 != 0 || iVar3 == 0);
  pcd->iuser2 = ppcd->iuser2;
  pcd->iuser3 = ppcd->iuser3;
  iVar3 = (*gEngfuncs.IsSpectateOnly)();
  if (iVar3 != 0) {
    pcd->iuser1 = g_iUser1;
    pcd->iuser2 = g_iUser2;
    pcd->iuser3 = g_iUser3;
  }
  pcd->iuser4 = ppcd->iuser4;
  uVar4 = 0xb00;
  bVar7 = ((uint)wd & 1) != 0;
  pcd->fuser2 = ppcd->fuser2;
  pcd->fuser3 = ppcd->fuser3;
  (pcd->vuser1).x = (ppcd->vuser1).x;
  (pcd->vuser1).y = (ppcd->vuser1).y;
  (pcd->vuser1).z = (ppcd->vuser1).z;
  (pcd->vuser2).x = (ppcd->vuser2).x;
  (pcd->vuser2).y = (ppcd->vuser2).y;
  (pcd->vuser2).z = (ppcd->vuser2).z;
  (pcd->vuser3).x = (ppcd->vuser3).x;
  (pcd->vuser3).y = (ppcd->vuser3).y;
  (pcd->vuser3).z = (ppcd->vuser3).z;
  (pcd->vuser4).x = (ppcd->vuser4).x;
  (pcd->vuser4).y = (ppcd->vuser4).y;
  (pcd->vuser4).z = (ppcd->vuser4).z;
  if (bVar7) {
    piVar2 = &pwd->m_iId;
    pwd = (weapon_data_s *)((int)&pwd->m_iId + 1);
    *(char *)&wd->m_iId = (char)*piVar2;
    uVar4 = 0xaff;
    wd = (weapon_data_s *)((int)&wd->m_iId + 1);
  }
  if (((uint)wd & 2) != 0) {
    piVar2 = &pwd->m_iId;
    pwd = (weapon_data_s *)((int)&pwd->m_iId + 2);
    uVar4 = uVar4 - 2;
    *(short *)&wd->m_iId = (short)*piVar2;
    wd = (weapon_data_s *)((int)&wd->m_iId + 2);
  }
  pwVar6 = wd;
  if (((uint)wd & 4) != 0) {
    piVar2 = &pwd->m_iId;
    pwVar6 = (weapon_data_s *)&wd->m_iClip;
    pwd = (weapon_data_s *)&pwd->m_iClip;
    uVar4 = uVar4 - 4;
    wd->m_iId = *piVar2;
  }
  iVar3 = 0;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    pwVar6->m_iId = pwd->m_iId;
    pwd = (weapon_data_s *)((int)pwd + (uint)bVar8 * -8 + 4);
    pwVar6 = (weapon_data_s *)((int)pwVar6 + (uint)bVar8 * -8 + 4);
  }
  if ((uVar4 & 2) != 0) {
    *(short *)&pwVar6->m_iId = (short)pwd->m_iId;
    iVar3 = 2;
  }
  if (bVar7) {
    *(undefined1 *)((int)&pwVar6->m_iId + iVar3) = *(undefined1 *)((int)&pwd->m_iId + iVar3);
  }
  return;
}


// HUD_CreateEntities  @ 00069de0  (line 308)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HUD_CreateEntities(void)

{
  CVoiceStatus *this;
  
  Bench_AddObjects();
  Game_AddObjects();
  this = GetClientVoiceMgr();
  CVoiceStatus::CreateEntities(this);
  return;
}


// HUD_StudioEvent  @ 00069e00  (line 336)

void HUD_StudioEvent(mstudioevent_s *event,cl_entity_s *entity)

{
  _func_void_float_ptr_int_int_int *p_Var1;
  long lVar2;
  Vector *pVVar3;
  _func_void_float_ptr_int *UNRECOVERED_JUMPTABLE;
  
                    /* Unresolved local var: int iMuzzleFlash@[???] */
  if (*(int *)(&DAT_000e6a7c + entity->index * 4) != 0) {
    if (event->event == 0x138a) {
switchD_00069e4e_caseD_138a:
      p_Var1 = (gEngfuncs.pEfxAPI)->R_SparkEffect;
      lVar2 = strtol(event->options,(char **)0x0,10);
      (*p_Var1)(&entity->attachment[0].x,lVar2,-100,100);
      return;
    }
    if (event->event == 0x138c) goto switchD_00069e4e_caseD_138c;
switchD_00069e4e_caseD_138b:
    return;
  }
  switch(event->event) {
  case 0x1389:
    pVVar3 = entity->attachment;
    UNRECOVERED_JUMPTABLE = (gEngfuncs.pEfxAPI)->R_MuzzleFlash;
    entity = (cl_entity_s *)strtol(event->options,(char **)0x0,10);
    break;
  case 0x138a:
    goto switchD_00069e4e_caseD_138a;
  default:
    goto switchD_00069e4e_caseD_138b;
  case 0x138c:
switchD_00069e4e_caseD_138c:
    (*gEngfuncs.pfnPlaySoundByNameAtLocation)(event->options,1.0,&entity->attachment[0].x);
    return;
  case 0x1393:
    pVVar3 = entity->attachment + 1;
    UNRECOVERED_JUMPTABLE = (gEngfuncs.pEfxAPI)->R_MuzzleFlash;
    entity = (cl_entity_s *)strtol(event->options,(char **)0x0,10);
    break;
  case 0x139d:
    pVVar3 = entity->attachment + 2;
    UNRECOVERED_JUMPTABLE = (gEngfuncs.pEfxAPI)->R_MuzzleFlash;
    entity = (cl_entity_s *)strtol(event->options,(char **)0x0,10);
    break;
  case 0x13a7:
    pVVar3 = entity->attachment + 3;
    UNRECOVERED_JUMPTABLE = (gEngfuncs.pEfxAPI)->R_MuzzleFlash;
    entity = (cl_entity_s *)strtol(event->options,(char **)0x0,10);
  }
                    /* WARNING: Could not recover jumptable at 0x00069f1e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(&pVVar3->x,(int)entity);
  return;
}


// HUD_TempEntUpdate  @ 00069fc0  (line 393)

void HUD_TempEntUpdate(double frametime,double client_time,double cl_gravity,
                      TEMPENTITY **ppTempEntFree,TEMPENTITY **ppTempEntActive,
                      _func_int_cl_entity_t_ptr *Callback_AddVisibleEntity,
                      _func_void_TEMPENTITY_ptr_float *Callback_TempEntPlaySound)

{
  Vector *pVVar1;
  vec_t vVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  tempent_s *ptVar7;
  _func_void_tempent_s_ptr_pmtrace_s_ptr *p_Var8;
  float fVar9;
  int iVar10;
  cl_entity_s *pcVar11;
  physent_s_conflict *ppVar12;
  dlight_t *pdVar13;
  uint uVar14;
  tempent_s *ptVar15;
  tempent_s *ptVar16;
  float fVar17;
  double dVar18;
  float local_78;
  qboolean local_74;
  qboolean local_70;
  float local_6c;
  float local_68;
  float local_64;
  pmtrace_s local_60;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: TEMPENTITY * pTemp@[???]
                       Unresolved local var: TEMPENTITY * pnext@[???]
                       Unresolved local var: TEMPENTITY * pprev@[???]
                       Unresolved local var: float freq@[???]
                       Unresolved local var: float gravity@[???]
                       Unresolved local var: float gravitySlow@[???]
                       Unresolved local var: float life@[???]
                       Unresolved local var: float fastFreq@[???]
                       Unresolved local var: Vector vAngles@[???] */
  (*gEngfuncs.GetViewAngles)(&local_78);
  if (g_pParticleMan != (IParticleMan *)0x0) {
    local_60.allsolid = (qboolean)local_78;
    local_60.startsolid = local_74;
    local_60.inopen = local_70;
    (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[4])
              (g_pParticleMan,(float)cl_gravity,&local_60);
  }
  if (*ppTempEntActive != (TEMPENTITY *)0x0) {
    (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
    (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
    (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(-1);
    HUD_TempEntUpdate::gTempEntFrame = HUD_TempEntUpdate::gTempEntFrame + 1U & 0x1f;
    ptVar7 = *ppTempEntActive;
    if (frametime <= 0.0) {
      for (; ptVar7 != (tempent_s *)0x0; ptVar7 = ptVar7->next) {
        if ((ptVar7->flags & 0x40000U) == 0) {
          (*Callback_AddVisibleEntity)(&ptVar7->entity);
        }
      }
    }
    else {
      fVar3 = (float)(-(longdouble)frametime * (longdouble)cl_gravity);
      if (ptVar7 != (tempent_s *)0x0) {
        ptVar16 = (tempent_s *)0x0;
        do {
          while( true ) {
            ptVar15 = ptVar7;
            fVar4 = ptVar15->die - (float)client_time;
            ptVar7 = ptVar15->next;
            uVar14 = ptVar15->flags;
            if (0.0 <= fVar4) break;
            if ((uVar14 & 0x80) != 0) {
              if ((ptVar15->entity).curstate.rendermode == 0) {
                (ptVar15->entity).curstate.rendermode = 2;
              }
              iVar10 = (int)((float)(ptVar15->entity).baseline.renderamt *
                            (fVar4 * ptVar15->fadeSpeed + 1.0));
              (ptVar15->entity).curstate.renderamt = iVar10;
              if (0 < iVar10) break;
            }
            ptVar15->next = *ppTempEntFree;
            *ppTempEntFree = ptVar15;
            if (ptVar16 == (tempent_s *)0x0) {
              *ppTempEntActive = ptVar7;
            }
            else {
              ptVar16->next = ptVar7;
            }
LAB_0006a180:
            if (ptVar7 == (tempent_s *)0x0) goto LAB_0006a470;
          }
          fVar4 = (ptVar15->entity).origin.x;
          (ptVar15->entity).prevstate.origin.x = fVar4;
          fVar17 = (ptVar15->entity).origin.y;
          (ptVar15->entity).prevstate.origin.y = fVar17;
          fVar5 = (ptVar15->entity).origin.z;
          (ptVar15->entity).prevstate.origin.z = fVar5;
          ptVar16 = ptVar15;
          if ((uVar14 & 0x20000) == 0) {
            if ((uVar14 & 0x8000) != 0) {
                    /* Unresolved local var: cl_entity_t * pClient@[???] */
              pcVar11 = (*gEngfuncs.GetEntityByIndex)((int)ptVar15->clientIndex);
              uVar14 = ptVar15->flags;
              (ptVar15->entity).origin.x = (pcVar11->origin).x + (ptVar15->tentOffset).x;
              (ptVar15->entity).origin.y = (pcVar11->origin).y + (ptVar15->tentOffset).y;
              (ptVar15->entity).origin.z = (pcVar11->origin).z + (ptVar15->tentOffset).z;
              goto LAB_0006a112;
            }
            if ((uVar14 & 1) == 0) {
              if ((uVar14 & 0x400) == 0) {
                fVar6 = (float)frametime;
                (ptVar15->entity).origin.x = fVar6 * (ptVar15->entity).baseline.origin.x + fVar4;
                (ptVar15->entity).origin.y = fVar6 * (ptVar15->entity).baseline.origin.y + fVar17;
                (ptVar15->entity).origin.z = fVar6 * (ptVar15->entity).baseline.origin.z + fVar5;
              }
              else {
                    /* Unresolved local var: float s@[???]
                       Unresolved local var: float c@[???] */
                fVar6 = (ptVar15->entity).baseline.origin.z;
                dVar18 = sin((double)(int)ptVar15 + client_time * 20.0);
                (ptVar15->entity).origin.x =
                     fVar4 + (float)dVar18 * 8.0 +
                             (float)frametime * (ptVar15->entity).baseline.origin.x;
                dVar18 = sin(client_time * 30.0 + (double)(int)ptVar15);
                (ptVar15->entity).origin.y =
                     fVar17 + (float)dVar18 * 4.0 +
                              (float)frametime * (ptVar15->entity).baseline.origin.y;
                (ptVar15->entity).origin.z = fVar5 + fVar6 * (float)frametime;
              }
              goto LAB_0006a112;
            }
            fVar6 = (float)frametime * (ptVar15->entity).baseline.origin.x + ptVar15->x;
            fVar4 = (ptVar15->entity).baseline.origin.y;
            ptVar15->x = fVar6;
            fVar9 = (float)frametime * fVar4 + ptVar15->y;
            fVar4 = (ptVar15->entity).baseline.origin.z;
            fVar17 = (ptVar15->entity).prevstate.frame;
            ptVar15->y = fVar9;
            dVar18 = sin((double)((float)client_time * fVar17 + fVar4));
            fVar17 = (ptVar15->entity).curstate.framerate;
            (ptVar15->entity).origin.x = fVar17 * 10.0 * (float)dVar18 + fVar6;
            dVar18 = sin((double)(fVar4 + (float)client_time * 5.5 + 0.7));
            (ptVar15->entity).origin.y = fVar17 * 8.0 * (float)dVar18 + fVar9;
            (ptVar15->entity).origin.z = fVar5 + fVar4 * (float)frametime;
            if ((uVar14 & 0x100) != 0) goto LAB_0006a11e;
LAB_0006a2c0:
            if ((uVar14 & 0x800) != 0) {
              fVar4 = (float)frametime * 10.0 + (ptVar15->entity).curstate.frame;
              (ptVar15->entity).curstate.frame = fVar4;
              if (ptVar15->frameMax <= fVar4) {
                (ptVar15->entity).curstate.frame = fVar4 - (float)(int)fVar4;
              }
            }
          }
          else {
                    /* Unresolved local var: int active@[???] */
            if ((ptVar15->entity).baseline.scale < (float)client_time) {
              (*(gEngfuncs.pEfxAPI)->R_SparkEffect)(&(ptVar15->entity).origin.x,8,-200,200);
              fVar4 = (ptVar15->entity).baseline.framerate - 0.1;
              (ptVar15->entity).baseline.framerate = fVar4;
              if (fVar4 <= 0.0) {
                ptVar15->die = (float)client_time;
                uVar14 = ptVar15->flags;
              }
              else {
                ptVar15->die = (float)((longdouble)client_time + (longdouble)0.5);
                (ptVar15->entity).baseline.scale =
                     (float)((longdouble)0.1 + (longdouble)client_time);
                uVar14 = ptVar15->flags;
              }
            }
LAB_0006a112:
            if ((uVar14 & 0x100) == 0) goto LAB_0006a2c0;
LAB_0006a11e:
            fVar4 = (float)frametime * (ptVar15->entity).curstate.framerate +
                    (ptVar15->entity).curstate.frame;
            (ptVar15->entity).curstate.frame = fVar4;
            if ((ptVar15->frameMax <= fVar4) &&
               ((ptVar15->entity).curstate.frame = fVar4 - (float)(int)fVar4,
               (uVar14 & 0x10000) == 0)) {
              ptVar15->die = (float)client_time;
              goto LAB_0006a180;
            }
          }
          if ((uVar14 & 4) != 0) {
            fVar17 = (float)frametime;
            fVar4 = fVar17 * (ptVar15->entity).baseline.angles.x + (ptVar15->entity).angles.x;
            (ptVar15->entity).angles.x = fVar4;
            fVar5 = fVar17 * (ptVar15->entity).baseline.angles.y + (ptVar15->entity).angles.y;
            (ptVar15->entity).angles.y = fVar5;
            fVar17 = fVar17 * (ptVar15->entity).baseline.angles.z + (ptVar15->entity).angles.z;
            (ptVar15->entity).angles.z = fVar17;
            (ptVar15->entity).latched.prevangles.x = fVar4;
            (ptVar15->entity).latched.prevangles.y = fVar5;
            (ptVar15->entity).latched.prevangles.z = fVar17;
          }
          if ((uVar14 & 0x1020) != 0) {
                    /* Unresolved local var: Vector traceNormal@[???]
                       Unresolved local var: float traceFraction@[???] */
            if ((uVar14 & 0x1000) == 0) {
              if ((uVar14 & 0x20) != 0) {
                    /* Unresolved local var: pmtrace_t pmtrace@[???] */
                (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
                (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)
                          (&(ptVar15->entity).prevstate.origin.x,&(ptVar15->entity).origin.x,10,-1,
                           &local_60);
                fVar4 = local_60.fraction;
                if (local_60.fraction != 1.0) {
                  local_6c = local_60.plane.normal.x;
                  local_68 = local_60.plane.normal.y;
                  local_64 = local_60.plane.normal.z;
                  if ((ptVar15->flags & 0x20000U) != 0) {
                    pVVar1 = &(ptVar15->entity).baseline.origin;
                    VectorScale(&pVVar1->x,0.6,&pVVar1->x);
                    fVar17 = Length(&pVVar1->x);
                    if (fVar17 < 10.0) {
                      (ptVar15->entity).baseline.framerate = 0.0;
                    }
                  }
                  p_Var8 = ptVar15->hitcallback;
                  goto joined_r0x0006a9a3;
                }
                goto LAB_0006a6d4;
              }
            }
            else {
                    /* Unresolved local var: pmtrace_t pmtrace@[???]
                       Unresolved local var: physent_t * pe@[???] */
              (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
              (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)
                        (&(ptVar15->entity).prevstate.origin.x,&(ptVar15->entity).origin.x,2,-1,
                         &local_60);
              if ((local_60.fraction == 1.0) ||
                 ((ppVar12 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(local_60.ent),
                  local_60.ent != 0 && (ppVar12->info == (int)ptVar15->clientIndex)))) {
                fVar4 = 1.0;
              }
              else {
                p_Var8 = ptVar15->hitcallback;
                local_6c = local_60.plane.normal.x;
                local_68 = local_60.plane.normal.y;
                local_64 = local_60.plane.normal.z;
                fVar4 = local_60.fraction;
joined_r0x0006a9a3:
                if (p_Var8 != (_func_void_tempent_s_ptr_pmtrace_s_ptr *)0x0) {
                  (*p_Var8)(ptVar15,&local_60);
                }
              }
LAB_0006a6d4:
              if (fVar4 != 1.0) {
                    /* Unresolved local var: float proj@[???]
                       Unresolved local var: float damp@[???] */
                pVVar1 = &(ptVar15->entity).baseline.origin;
                VectorMA(&(ptVar15->entity).prevstate.origin.x,(float)frametime * fVar4,&pVVar1->x,
                         &(ptVar15->entity).origin.x);
                uVar14 = ptVar15->flags;
                fVar4 = ptVar15->bounceFactor;
                if (((((uVar14 & 10) != 0) && (fVar4 = fVar4 * 0.5, 0.9 < local_64)) &&
                    (fVar17 = (ptVar15->entity).baseline.origin.z, fVar17 <= 0.0)) &&
                   (fVar3 * 3.0 <= fVar17)) {
                  fVar4 = 0.0;
                  (ptVar15->entity).angles.x = 0.0;
                  uVar14 = uVar14 & 0xffffffc1;
                  (ptVar15->entity).angles.z = 0.0;
                  ptVar15->flags = uVar14;
                }
                if (ptVar15->hitSound != 0) {
                  (*Callback_TempEntPlaySound)(ptVar15,fVar4);
                  uVar14 = ptVar15->flags;
                }
                if ((uVar14 & 0x4000) == 0) {
                  if (fVar4 != 0.0) {
                    fVar17 = -((ptVar15->entity).baseline.origin.z * local_64 +
                              (ptVar15->entity).baseline.origin.y * local_68 +
                              (ptVar15->entity).baseline.origin.x * local_6c);
                    VectorMA(&pVVar1->x,fVar17 + fVar17,&local_6c,&pVVar1->x);
                    (ptVar15->entity).angles.y = -(ptVar15->entity).angles.y;
                  }
                  if (fVar4 != 1.0) {
                    VectorScale(&pVVar1->x,fVar4,&pVVar1->x);
                    pVVar1 = &(ptVar15->entity).angles;
                    VectorScale(&pVVar1->x,0.9,&pVVar1->x);
                  }
                }
                else {
                  ptVar15->flags = uVar14 & 0xffffff7f;
                  ptVar15->die = (float)client_time;
                }
              }
            }
            uVar14 = ptVar15->flags;
          }
          if (((uVar14 & 0x40) != 0) &&
             ((ptVar15->entity).curstate.effects == HUD_TempEntUpdate::gTempEntFrame)) {
                    /* Unresolved local var: dlight_t * dl@[???] */
            pdVar13 = (*(gEngfuncs.pEfxAPI)->CL_AllocDlight)(0);
            (pdVar13->origin).x = (ptVar15->entity).origin.x;
            (pdVar13->origin).y = (ptVar15->entity).origin.y;
            vVar2 = (ptVar15->entity).origin.z;
            pdVar13->radius = 60.0;
            (pdVar13->color).r = 0xff;
            (pdVar13->origin).z = vVar2;
            (pdVar13->color).g = 'x';
            (pdVar13->color).b = '\0';
            pdVar13->die = (float)((longdouble)client_time + (longdouble)0.01);
            uVar14 = ptVar15->flags;
          }
          if ((uVar14 & 0x10) != 0) {
            (*(gEngfuncs.pEfxAPI)->R_RocketTrail)
                      (&(ptVar15->entity).prevstate.origin.x,&(ptVar15->entity).origin.x,1);
            uVar14 = ptVar15->flags;
          }
          if ((uVar14 & 2) == 0) {
            if ((uVar14 & 8) != 0) {
              (ptVar15->entity).baseline.origin.z =
                   fVar3 * 0.5 + (ptVar15->entity).baseline.origin.z;
            }
          }
          else {
            (ptVar15->entity).baseline.origin.z = fVar3 + (ptVar15->entity).baseline.origin.z;
          }
          if (((uVar14 & 0x80000) != 0) &&
             (ptVar15->callback != (_func_void_tempent_s_ptr_float_float *)0x0)) {
            (*ptVar15->callback)(ptVar15,(float)frametime,(float)client_time);
            uVar14 = ptVar15->flags;
          }
          if ((((uVar14 & 0x40000) != 0) ||
              (iVar10 = (*Callback_AddVisibleEntity)(&ptVar15->entity), iVar10 != 0)) ||
             ((ptVar15->flags & 0x2000U) != 0)) goto LAB_0006a180;
          ptVar15->die = (float)client_time;
          ptVar15->flags = ptVar15->flags & 0xffffff7f;
        } while (ptVar7 != (tempent_s *)0x0);
      }
    }
LAB_0006a470:
    (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  }
  return;
}


// HUD_GetUserEntity  @ 0006ab70  (line 784)

cl_entity_t * HUD_GetUserEntity(int index)

{
  return (cl_entity_t *)0x0;
}


