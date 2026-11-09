// HUD_AddEntity  @ 0008d0e0
int HUD_AddEntity(int type,cl_entity_s *ent,char *modelname)

{
  if (type == 0) {
    Bench_CheckEntity(0,(cl_entity_s_conflict *)ent,modelname);
  }
  if (g_iUser1 != 0) {
    CHudSpectator::AddOverviewEntity(&gHUD.m_Spectator,type,ent,modelname);
    if ((g_iUser1 != 4) && ((gHUD.m_Spectator.m_pip)->value != 2.0)) {
      return 1;
    }
    return (uint)(ent->index != g_iUser2);
  }
  return 1;
}


// HUD_ChatInputPosition  @ 000c1bc0
void HUD_ChatInputPosition(int *x,int *y)

{
  int iVar1;
  
  if ((g_iUser1 == 0) && (iVar1 = (*gEngfuncs.IsSpectateOnly)(), iVar1 == 0)) {
    return;
  }
  if ((gHUD.m_Spectator.m_pip)->value != 0.0) {
    *y = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 5.0 +
              (float)gHUD.m_Spectator.m_OverviewData.insetWindowHeight);
    return;
  }
  *y = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 64.0);
  return;
}


// HUD_ConnectionlessPacket  @ 0008e480
int HUD_ConnectionlessPacket
              (netadr_s *net_from,char *args,char *response_buffer,int *response_buffer_size)

{
                    /* Unresolved local var: int max_buffer_size@[???] */
  *response_buffer_size = 0;
  return 0;
}


// HUD_CreateBenchObjects  @ 00093730
void HUD_CreateBenchObjects(Vector origin)

{
  Vector *veca;
  float fVar1;
  float fVar2;
  vec_t vVar3;
  undefined4 uVar4;
  Vector origin_00;
  float scale;
  float fVar5;
  float fVar6;
  vec_t vVar7;
  uint uVar8;
  cl_entity_s *pcVar9;
  int iVar10;
  float *pfVar11;
  uint uVar12;
  int iVar13;
  int *piVar14;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  char *in_stack_fffffe84;
  undefined4 in_stack_fffffe88;
  vec_t in_stack_fffffe8c;
  double local_104;
  double local_fc;
  float local_f0;
  pmtrace_s local_e0;
  float local_9c;
  float local_98;
  undefined4 local_94;
  float local_8c [4];
  vec_t local_7c [3];
  float local_70 [3];
  float local_64;
  float local_60;
  float local_5c;
  float local_58 [3];
  float local_4c [3];
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
                    /* Unresolved local var: cl_entity_t.conflict * player@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector farpoint@[???]
                       Unresolved local var: Vector centerspot@[???]
                       Unresolved local var: float frametime@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: float frac2@[???]
                       Unresolved local var: float dt@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int i@[???] */
  if (HUD_CreateBenchObjects(Vector)::bench == '\0') {
    in_stack_fffffe84 = &HUD_CreateBenchObjects(Vector)::bench;
    iVar10 = __cxa_guard_acquire();
    if (iVar10 != 0) {
      in_stack_fffffe84 = &HUD_CreateBenchObjects(Vector)::bench;
      __cxa_guard_release();
    }
  }
  if (gHUD.m_flTime == HUD_CreateBenchObjects::lexical_block_0::last_time) {
    return;
  }
  scale = gHUD.m_flTime - HUD_CreateBenchObjects::lexical_block_0::last_time;
  HUD_CreateBenchObjects::lexical_block_0::last_time = gHUD.m_flTime;
  if (scale <= 0.0) {
    HUD_CreateBenchObjects::lexical_block_0::last_time = gHUD.m_flTime;
    return;
  }
  if (HUD_CreateBenchObjects::lexical_block_0::failed != 0) {
    HUD_CreateBenchObjects::lexical_block_0::last_time = gHUD.m_flTime;
    return;
  }
  pcVar9 = (*gEngfuncs.GetLocalPlayer)();
  if (pcVar9 == (cl_entity_s *)0x0) {
LAB_00093ea1:
    HUD_CreateBenchObjects::lexical_block_0::failed = 1;
  }
  else {
    if (HUD_CreateBenchObjects::lexical_block_0::first != 0) {
      local_28 = *(undefined4 *)origin.x;
      HUD_CreateBenchObjects::lexical_block_0::first = 0;
      local_24 = *(undefined4 *)((int)origin.x + 4);
      local_20 = *(undefined4 *)((int)origin.x + 8);
      origin_00.y = (vec_t)in_stack_fffffe88;
      origin_00.x = (vec_t)in_stack_fffffe84;
      origin_00.z = in_stack_fffffe8c;
      iVar10 = HUD_SetupBenchObjects
                         ((cl_entity_t_conflict *)(pcVar9->index + -1),(int)&local_28,origin_00);
      if (iVar10 == 0) goto LAB_00093ea1;
    }
    (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
    (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
    (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(pcVar9->index + -1);
    (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
    fVar5 = gHUD.m_flTime - g_flStartTime;
    if (0.0 <= fVar5) {
      fVar6 = fVar5 / 10.0;
      if (1.0 < fVar6) {
        fVar6 = fVar6 - (float)(int)fVar6;
      }
      fVar5 = fVar5 * 0.25;
      if (1.0 < fVar5) {
        fVar5 = fVar5 - (float)(int)fVar5;
      }
      (*gEngfuncs.pfnAngleVectors)(&vec3_origin.x,&local_64,local_58,local_4c);
      local_34 = *(float *)origin.x;
      local_30 = *(float *)((int)origin.x + 4);
      piVar14 = &HUD_CreateBenchObjects::lexical_block_0::bench[0].curstate.rendermode;
      local_2c = *(float *)((int)origin.x + 8) - 512.0;
      (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)((float *)origin.x,&local_34,0,-1,&local_e0);
      local_34 = local_64 * 250.0 + local_e0.endpos.x;
      local_30 = local_60 * 250.0 + local_e0.endpos.y;
      local_2c = local_5c * 250.0 + local_e0.endpos.z + 72.0;
      iVar10 = 0;
      do {
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: float jitter@[???]
                       Unresolved local var: float jfrac@[???]
                       Unresolved local var: float offset@[???]
                       Unresolved local var: float ofs_radius@[???]
                       Unresolved local var: Vector ang@[???] */
        pfVar11 = local_8c;
        local_9c = 0.0;
        local_94 = 0;
        local_8c[0] = 0.0;
        local_8c[2] = 0.0;
        fVar2 = ((float)iVar10 / 11.0) * 360.0;
        local_f0 = fVar6 * 360.0 + fVar2;
        local_8c[1] = local_f0;
        do {
                    /* Unresolved local var: int i@[???] */
          fVar1 = *pfVar11;
          if (fVar1 < -180.0) {
            do {
              fVar1 = fVar1 + 360.0;
            } while (fVar1 < -180.0);
            *pfVar11 = fVar1;
          }
          if (180.0 < fVar1) {
            do {
              fVar1 = fVar1 - 360.0;
            } while (180.0 < fVar1);
            *pfVar11 = fVar1;
          }
          pfVar11 = pfVar11 + 1;
        } while (pfVar11 != local_8c + 3);
        local_98 = local_f0;
        (*gEngfuncs.pfnAngleVectors)(&local_9c,&local_64,local_58,local_4c);
        sincos((double)fVar2 + (double)(fVar5 + fVar5) * 3.141592653589793,&local_fc,&local_104);
        local_f0 = (float)local_fc * 5.0 + 80.0;
        local_3c = local_60 * local_f0 + local_30;
        local_40 = local_f0 * local_64 + local_34;
        local_38 = (float)local_104 * 10.0 + local_5c * local_f0 + local_2c;
        (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_34,&local_40,0,-1,&local_e0);
        veca = &HUD_CreateBenchObjects::lexical_block_0::bench[iVar10].curstate.angles;
        VectorMA(&veca->x,scale,
                 &HUD_CreateBenchObjects::lexical_block_0::bench[iVar10].baseline.angles.x,&veca->x)
        ;
        vVar3 = local_e0.endpos.x;
                    /* Unresolved local var: int i@[???] */
        local_7c[0] = HUD_CreateBenchObjects::lexical_block_0::bench[iVar10].curstate.angles.x;
        local_7c[1] = HUD_CreateBenchObjects::lexical_block_0::bench[iVar10].curstate.angles.y;
        local_7c[2] = HUD_CreateBenchObjects::lexical_block_0::bench[iVar10].curstate.angles.z;
        pfVar11 = local_7c;
        do {
          fVar2 = *pfVar11;
          if (fVar2 < -180.0) {
            do {
              fVar2 = fVar2 + 360.0;
            } while (fVar2 < -180.0);
            *pfVar11 = fVar2;
          }
          if (180.0 < fVar2) {
            do {
              fVar2 = fVar2 - 360.0;
            } while (180.0 < fVar2);
            *pfVar11 = fVar2;
          }
          pfVar11 = pfVar11 + 1;
        } while (pfVar11 != local_70);
        if (iVar10 == 0xb) {
          g_aimorg.x = local_e0.endpos.x;
          g_aimorg.y = local_e0.endpos.y;
          g_aimorg.z = local_e0.endpos.z;
        }
        fVar2 = 0.5;
        if (g_isPowerPlay == 0) {
          fVar2 = 8.0;
        }
        fVar2 = fVar2 * ((float)gHUD.m_Benchmark.m_nObjects / 12.0);
        (*gEngfuncs.pfnRandomFloat)(-fVar2,fVar2);
        vVar7 = local_e0.endpos.y;
        local_e0.endpos.x = (vec_t)(extraout_ST0 + (longdouble)vVar3);
        (*gEngfuncs.pfnRandomFloat)(-fVar2,fVar2);
        piVar14[0x216] = (int)local_e0.endpos.z;
        piVar14[-0xc] = (int)local_e0.endpos.z;
        vVar3 = ((Vector *)(piVar14 + -0xb))->x;
        piVar14[0x214] = (int)local_e0.endpos.x;
        ((Vector *)(piVar14 + -0xe))->x = local_e0.endpos.x;
        piVar14[0x217] = (int)vVar3;
        local_e0.endpos.y = (vec_t)(extraout_ST0_00 + (longdouble)vVar7);
        piVar14[0x218] = piVar14[-10];
        piVar14[0x215] = (int)local_e0.endpos.y;
        piVar14[-0xd] = (int)local_e0.endpos.y;
        piVar14[0x219] = piVar14[-9];
        uVar8 = 0;
        do {
          uVar12 = uVar8;
          uVar4 = *(undefined4 *)((int)piVar14 + (uVar12 - 0x48));
          *(undefined4 *)((int)piVar14 + (uVar12 - 0x198)) =
               *(undefined4 *)((int)piVar14 + (uVar12 - 0x44));
          *(undefined4 *)((int)piVar14 + (uVar12 - 0x19c)) = uVar4;
          uVar8 = uVar12 + 8;
        } while (uVar12 + 8 < 0x150);
        *(undefined4 *)((int)piVar14 + (uVar12 - 0x194)) =
             *(undefined4 *)((int)piVar14 + (uVar12 - 0x40));
        if (0xb - iVar10 < gHUD.m_Benchmark.m_nObjects) {
          if (piVar14[1] == 0xff) {
            *piVar14 = 0;
          }
          else {
            iVar13 = (int)(scale * 150.0 + (float)piVar14[1]);
            if (0xff < iVar13) {
              iVar13 = 0xff;
            }
            piVar14[1] = iVar13;
            *piVar14 = 4;
          }
          (*gEngfuncs.CL_CreateVisibleEntity)
                    (0,(cl_entity_s *)(HUD_CreateBenchObjects::lexical_block_0::bench + iVar10));
        }
        iVar10 = iVar10 + 1;
        piVar14 = piVar14 + 0x2ee;
      } while (iVar10 != 0xc);
      (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
    }
  }
  return;
}


// HUD_CreateEntities  @ 0008d5f0
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


// HUD_CreateSniperDot  @ 0007fd30
int __regparm3 HUD_CreateSniperDot(int damage,Vector viewangles,Vector origin,float *dotorigin)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  pfnEngSrc_CL_LoadModel_t p_Var4;
  uint uVar5;
  float fVar6;
  cl_entity_s *pcVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  float *in_ECX;
  int iVar11;
  char *pcVar12;
  float fVar13;
  float fVar14;
  cl_entity_t *pcVar15;
  byte bVar16;
  longdouble extraout_ST0;
  longdouble lVar17;
  longdouble lVar18;
  pmtrace_s local_9c;
  float local_50;
  float local_4c;
  float local_48;
  float local_44 [3];
  float local_38 [3];
  float local_2c;
  float local_28;
  float local_24;
  int local_20 [4];
  
  bVar16 = 0;
                    /* Unresolved local var: int iret@[???]
                       Unresolved local var: cl_entity_t * player@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector farpoint@[???]
                       Unresolved local var: int end_contents@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: pmtrace_t tr2@[???] */
  if ((HUD_CreateSniperDot(int,Vector,Vector,float*)::dot == '\0') &&
     (iVar11 = __cxa_guard_acquire(&HUD_CreateSniperDot(int,Vector,Vector,float*)::dot), iVar11 != 0
     )) {
    __cxa_guard_release(&HUD_CreateSniperDot(int,Vector,Vector,float*)::dot);
  }
  pcVar15 = &HUD_CreateSniperDot::lexical_block_0::dot;
  for (iVar11 = 0x2ee; p_Var4 = gEngfuncs.CL_LoadModel, iVar11 != 0; iVar11 = iVar11 + -1) {
    pcVar15->index = 0;
    pcVar15 = (cl_entity_t *)((int)pcVar15 + ((uint)bVar16 * -2 + 1) * 4);
  }
  iVar11 = Bench_Active();
  pcVar12 = "sprites/ppdemodot.spr";
  if (iVar11 == 0) {
    pcVar12 = "sprites/laserdot.spr";
  }
  HUD_CreateSniperDot::lexical_block_0::dot.model = (*p_Var4)(pcVar12,local_20);
  iVar11 = 0;
  if ((HUD_CreateSniperDot::lexical_block_0::dot.model != (model_s *)0x0) &&
     (pcVar7 = (*gEngfuncs.GetLocalPlayer)(), pcVar7 != (cl_entity_s *)0x0)) {
    HUD_CreateSniperDot::lexical_block_0::dot.curstate.movetype = 0;
    HUD_CreateSniperDot::lexical_block_0::dot.curstate.rendermode = 3;
    HUD_CreateSniperDot::lexical_block_0::dot.curstate.modelindex = local_20[0];
    HUD_CreateSniperDot::lexical_block_0::dot.curstate.solid = 0;
    HUD_CreateSniperDot::lexical_block_0::dot.curstate.renderfx = 0xe;
    HUD_CreateSniperDot::lexical_block_0::dot.curstate.renderamt = damage;
    (*gEngfuncs.pfnAngleVectors)(dotorigin,&local_50,local_44,local_38);
    local_24 = local_48 * 8192.0 + in_ECX[2];
    local_28 = local_4c * 8192.0 + in_ECX[1];
    local_2c = local_50 * 8192.0 + *in_ECX;
    (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
    (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
    (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(pcVar7->index + -1);
    (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
    (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(in_ECX,&local_2c,2,-1,&local_9c);
    if (local_9c.fraction != 1.0) {
                    /* Unresolved local var: int inwater1@[???]
                       Unresolved local var: int inwater2@[???] */
      iVar11 = 0;
      iVar8 = (*gEngfuncs.PM_PointContents)(&local_9c.endpos.x,(int *)0x0);
      if ((iVar8 != -6) &&
         (iVar9 = (*gEngfuncs.PM_PointContents)(in_ECX,(int *)0x0), (iVar8 == -3) == (iVar9 == -3)))
      {
        iVar11 = Bench_Active();
        fVar6 = HUD_CreateSniperDot::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::
                fLastTime;
        if ((iVar11 != 0) &&
           (iVar11 = Bench_InStage(3),
           fVar6 = HUD_CreateSniperDot::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::
                   fLastTime, iVar11 != 0)) {
                    /* Unresolved local var: float dt@[???]
                       Unresolved local var: float fRate@[???]
                       Unresolved local var: float fBounds@[???]
                       Unresolved local var: float g_fZAdjust@[???] */
          iVar11 = Bench_GetPowerPlay();
          if (iVar11 == 0) {
            fVar14 = -8.0;
            fVar13 = 8.0;
          }
          else {
            fVar14 = -4.0;
            fVar13 = 4.0;
          }
          iVar11 = Bench_GetPowerPlay();
          if (iVar11 == 0) {
            fVar2 = -15.0;
            fVar3 = 15.0;
          }
          else {
            fVar2 = -8.0;
            fVar3 = 8.0;
          }
          fVar6 = gHUD.m_flTime;
          if ((0.0 < gHUD.m_flTime -
                     HUD_CreateSniperDot::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::
                     fLastTime) &&
             (fVar6 = gHUD.m_flTime,
             gHUD.m_flTime -
             HUD_CreateSniperDot::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::fLastTime
             < 1.0)) {
            (*gEngfuncs.pfnRandomFloat)(fVar14,fVar13);
            lVar17 = extraout_ST0 +
                     (longdouble)
                     HUD_CreateSniperDot::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::
                     fZAdjust;
            if ((longdouble)fVar3 <
                extraout_ST0 +
                (longdouble)
                HUD_CreateSniperDot::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::
                fZAdjust) {
              lVar17 = (longdouble)fVar3;
            }
            lVar18 = (longdouble)fVar2;
            if ((longdouble)fVar2 <= lVar17) {
              lVar18 = lVar17;
            }
            HUD_CreateSniperDot::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::fZAdjust =
                 (float)lVar18;
            local_9c.endpos.z = (vec_t)((longdouble)local_9c.endpos.z + lVar18);
            g_fZAdjust = (float)lVar18;
            fVar6 = gHUD.m_flTime;
          }
        }
        HUD_CreateSniperDot::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::fLastTime =
             fVar6;
        HUD_CreateSniperDot::lexical_block_0::dot.origin.y = local_9c.endpos.y;
        HUD_CreateSniperDot::lexical_block_0::dot.origin.z = local_9c.endpos.z;
        HUD_CreateSniperDot::lexical_block_0::dot.curstate.origin.y = local_9c.endpos.y;
        HUD_CreateSniperDot::lexical_block_0::dot.curstate.origin.z = local_9c.endpos.z;
        HUD_CreateSniperDot::lexical_block_0::dot.origin.x = local_9c.endpos.x;
        HUD_CreateSniperDot::lexical_block_0::dot.curstate.origin.x = local_9c.endpos.x;
        uVar5 = 0;
        do {
          uVar10 = uVar5;
          uVar1 = *(undefined4 *)
                   (HUD_CreateSniperDot::lexical_block_0::dot.curstate.controller + (uVar10 - 100));
          *(undefined4 *)
           (HUD_CreateSniperDot::lexical_block_0::dot.prevstate.controller + (uVar10 - 0x68)) =
               *(undefined4 *)
                (HUD_CreateSniperDot::lexical_block_0::dot.curstate.controller + (uVar10 - 0x68));
          *(undefined4 *)
           (HUD_CreateSniperDot::lexical_block_0::dot.prevstate.controller + (uVar10 - 100)) = uVar1
          ;
          uVar5 = uVar10 + 8;
        } while (uVar10 + 8 < 0x150);
        iVar11 = 1;
        *(undefined4 *)
         (HUD_CreateSniperDot::lexical_block_0::dot.prevstate.controller + (uVar10 - 0x60)) =
             *(undefined4 *)
              (HUD_CreateSniperDot::lexical_block_0::dot.curstate.controller + (uVar10 - 0x60));
        (*gEngfuncs.CL_CreateVisibleEntity)(0,&HUD_CreateSniperDot::lexical_block_0::dot);
        *(vec_t *)viewangles.x = HUD_CreateSniperDot::lexical_block_0::dot.origin.x;
        *(vec_t *)((int)viewangles.x + 4) = HUD_CreateSniperDot::lexical_block_0::dot.origin.y;
        *(vec_t *)((int)viewangles.x + 8) = HUD_CreateSniperDot::lexical_block_0::dot.origin.z;
      }
    }
    (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  }
  return iVar11;
}


// HUD_CreateSniperDot  @ 000800e0
int HUD_CreateSniperDot(int damage,Vector viewangles,Vector origin,float *dotorigin)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  pfnEngSrc_CL_LoadModel_t p_Var4;
  uint uVar5;
  float fVar6;
  cl_entity_s *pcVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  char *pcVar12;
  float fVar13;
  cl_entity_t *pcVar14;
  float fVar15;
  byte bVar16;
  longdouble extraout_ST0;
  longdouble lVar17;
  longdouble lVar18;
  pmtrace_s local_9c;
  float local_50;
  float local_4c;
  float local_48;
  float local_44 [3];
  float local_38 [3];
  float local_2c;
  float local_28;
  float local_24;
  int local_20 [4];
  
  bVar16 = 0;
                    /* Unresolved local var: int iret@[???]
                       Unresolved local var: cl_entity_t * player@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector farpoint@[???]
                       Unresolved local var: int end_contents@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: pmtrace_t tr2@[???]
                       Unresolved local var: int index@[???] */
  if ((HUD_CreateSniperDot(int,Vector,Vector,float*)::dot == '\0') &&
     (iVar11 = __cxa_guard_acquire(&HUD_CreateSniperDot(int,Vector,Vector,float*)::dot), iVar11 != 0
     )) {
    __cxa_guard_release(&HUD_CreateSniperDot(int,Vector,Vector,float*)::dot);
  }
  pcVar14 = &HUD_CreateSniperDot::lexical_block_0::dot;
  for (iVar11 = 0x2ee; p_Var4 = gEngfuncs.CL_LoadModel, iVar11 != 0; iVar11 = iVar11 + -1) {
    pcVar14->index = 0;
    pcVar14 = (cl_entity_t *)((int)pcVar14 + ((uint)bVar16 * -2 + 1) * 4);
  }
  iVar11 = Bench_Active();
  pcVar12 = "sprites/ppdemodot.spr";
  if (iVar11 == 0) {
    pcVar12 = "sprites/laserdot.spr";
  }
  HUD_CreateSniperDot::lexical_block_0::dot.model = (*p_Var4)(pcVar12,local_20);
  iVar11 = 0;
  if ((HUD_CreateSniperDot::lexical_block_0::dot.model != (model_s *)0x0) &&
     (pcVar7 = (*gEngfuncs.GetLocalPlayer)(), pcVar7 != (cl_entity_s *)0x0)) {
    HUD_CreateSniperDot::lexical_block_0::dot.curstate.modelindex = local_20[0];
    HUD_CreateSniperDot::lexical_block_0::dot.curstate.movetype = 0;
    HUD_CreateSniperDot::lexical_block_0::dot.curstate.solid = 0;
    HUD_CreateSniperDot::lexical_block_0::dot.curstate.rendermode = 3;
    HUD_CreateSniperDot::lexical_block_0::dot.curstate.renderfx = 0xe;
    HUD_CreateSniperDot::lexical_block_0::dot.curstate.renderamt = damage;
    (*gEngfuncs.pfnAngleVectors)((float *)viewangles.x,&local_50,local_44,local_38);
    local_24 = local_48 * 8192.0 + *(float *)((int)viewangles.y + 8);
    local_28 = local_4c * 8192.0 + *(float *)((int)viewangles.y + 4);
    local_2c = local_50 * 8192.0 + *(float *)viewangles.y;
    (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
    (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
    (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(pcVar7->index + -1);
    (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
    (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)((float *)viewangles.y,&local_2c,2,-1,&local_9c);
    if (local_9c.fraction != 1.0) {
                    /* Unresolved local var: int inwater1@[???]
                       Unresolved local var: int inwater2@[???] */
      iVar11 = 0;
      iVar8 = (*gEngfuncs.PM_PointContents)(&local_9c.endpos.x,(int *)0x0);
      if ((iVar8 != -6) &&
         (iVar9 = (*gEngfuncs.PM_PointContents)((float *)viewangles.y,(int *)0x0),
         (iVar8 == -3) == (iVar9 == -3))) {
        iVar11 = Bench_Active();
        fVar6 = HUD_CreateSniperDot::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::
                fLastTime;
        if ((iVar11 != 0) &&
           (iVar11 = Bench_InStage(3),
           fVar6 = HUD_CreateSniperDot::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::
                   fLastTime, iVar11 != 0)) {
                    /* Unresolved local var: float g_fZAdjust@[???]
                       Unresolved local var: float dt@[???]
                       Unresolved local var: float fRate@[???]
                       Unresolved local var: float fBounds@[???] */
          iVar11 = Bench_GetPowerPlay();
          if (iVar11 == 0) {
            fVar13 = -8.0;
            fVar15 = 8.0;
          }
          else {
            fVar13 = -4.0;
            fVar15 = 4.0;
          }
          iVar11 = Bench_GetPowerPlay();
          if (iVar11 == 0) {
            fVar2 = -15.0;
            fVar3 = 15.0;
          }
          else {
            fVar2 = -8.0;
            fVar3 = 8.0;
          }
          fVar6 = gHUD.m_flTime;
          if ((0.0 < gHUD.m_flTime -
                     HUD_CreateSniperDot::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::
                     fLastTime) &&
             (fVar6 = gHUD.m_flTime,
             gHUD.m_flTime -
             HUD_CreateSniperDot::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::fLastTime
             < 1.0)) {
            (*gEngfuncs.pfnRandomFloat)(fVar13,fVar15);
            lVar17 = extraout_ST0 +
                     (longdouble)
                     HUD_CreateSniperDot::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::
                     fZAdjust;
            if ((longdouble)fVar3 <
                extraout_ST0 +
                (longdouble)
                HUD_CreateSniperDot::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::
                fZAdjust) {
              lVar17 = (longdouble)fVar3;
            }
            lVar18 = (longdouble)fVar2;
            if ((longdouble)fVar2 <= lVar17) {
              lVar18 = lVar17;
            }
            HUD_CreateSniperDot::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::fZAdjust =
                 (float)lVar18;
            local_9c.endpos.z = (vec_t)((longdouble)local_9c.endpos.z + lVar18);
            g_fZAdjust = (float)lVar18;
            fVar6 = gHUD.m_flTime;
          }
        }
        HUD_CreateSniperDot::lexical_block_0::lexical_block_0_0::lexical_block_0_0_0::fLastTime =
             fVar6;
        HUD_CreateSniperDot::lexical_block_0::dot.origin.y = local_9c.endpos.y;
        HUD_CreateSniperDot::lexical_block_0::dot.origin.z = local_9c.endpos.z;
        HUD_CreateSniperDot::lexical_block_0::dot.curstate.origin.y = local_9c.endpos.y;
        HUD_CreateSniperDot::lexical_block_0::dot.curstate.origin.z = local_9c.endpos.z;
        HUD_CreateSniperDot::lexical_block_0::dot.origin.x = local_9c.endpos.x;
        HUD_CreateSniperDot::lexical_block_0::dot.curstate.origin.x = local_9c.endpos.x;
        uVar5 = 0;
        do {
          uVar10 = uVar5;
          uVar1 = *(undefined4 *)
                   (HUD_CreateSniperDot::lexical_block_0::dot.curstate.controller + (uVar10 - 100));
          *(undefined4 *)
           (HUD_CreateSniperDot::lexical_block_0::dot.prevstate.controller + (uVar10 - 0x68)) =
               *(undefined4 *)
                (HUD_CreateSniperDot::lexical_block_0::dot.curstate.controller + (uVar10 - 0x68));
          *(undefined4 *)
           (HUD_CreateSniperDot::lexical_block_0::dot.prevstate.controller + (uVar10 - 100)) = uVar1
          ;
          uVar5 = uVar10 + 8;
        } while (uVar10 + 8 < 0x150);
        iVar11 = 1;
        *(undefined4 *)
         (HUD_CreateSniperDot::lexical_block_0::dot.prevstate.controller + (uVar10 - 0x60)) =
             *(undefined4 *)
              (HUD_CreateSniperDot::lexical_block_0::dot.curstate.controller + (uVar10 - 0x60));
        (*gEngfuncs.CL_CreateVisibleEntity)(0,&HUD_CreateSniperDot::lexical_block_0::dot);
        *(vec_t *)viewangles.z = HUD_CreateSniperDot::lexical_block_0::dot.origin.x;
        *(vec_t *)((int)viewangles.z + 4) = HUD_CreateSniperDot::lexical_block_0::dot.origin.y;
        *(vec_t *)((int)viewangles.z + 8) = HUD_CreateSniperDot::lexical_block_0::dot.origin.z;
      }
    }
    (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  }
  return iVar11;
}


// HUD_DirectorMessage  @ 0008e4a0
void HUD_DirectorMessage(int iSize,void *pbuf)

{
  CHudSpectator::DirectorMessage(&gHUD.m_Spectator,iSize,pbuf);
  return;
}


// HUD_DrawNormalTriangles  @ 000a73b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HUD_DrawNormalTriangles(void)

{
  CHudSpectator::DrawOverview(&gHUD.m_Spectator);
  return;
}


// HUD_DrawTransparentTriangles  @ 000a73d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HUD_DrawTransparentTriangles(void)

{
  RunEventList();
  if (g_pParticleMan != (IParticleMan *)0x0) {
    (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[3])(g_pParticleMan);
  }
  return;
}


// HUD_Frame  @ 0008e500
void HUD_Frame(double time)

{
  CVoiceStatus *this;
  
  ServersThink(time);
  this = GetClientVoiceMgr();
  CVoiceStatus::Frame(this,time);
  return;
}


// HUD_GetFOV  @ 00083610
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float HUD_GetFOV(void)

{
  int iVar1;
  float local_70 [28];
  
  iVar1 = (*(gEngfuncs.pDemoAPI)->IsRecording)();
  if (iVar1 != 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uchar[100] buf@[???] */
    local_70[0] = g_lastFOV;
    Demo_WriteBuffer(1,4,(uchar *)local_70);
  }
  iVar1 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)();
  if (iVar1 != 0) {
    g_lastFOV = g_demozoom;
    return g_demozoom;
  }
  return g_lastFOV;
}


// HUD_GetHullBounds  @ 0008e470
int HUD_GetHullBounds(int hullnumber,float *mins,float *maxs)

{
                    /* Unresolved local var: int iret@[???] */
  return (uint)((uint)hullnumber < 3);
}


// HUD_GetLastOrg  @ 00080980
void HUD_GetLastOrg(float *org)

{
                    /* Unresolved local var: int i@[???] */
  *org = g_laserdot.previousorigin.x;
  org[1] = g_laserdot.previousorigin.y;
  org[2] = g_laserdot.previousorigin.z;
  return;
}


// HUD_GetStudioModelInterface  @ 0008f470
int HUD_GetStudioModelInterface
              (int version,r_studio_interface_s **ppinterface,engine_studio_api_s *pstudio)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  if (version == 1) {
    *ppinterface = &studio;
    uVar3 = 0;
    do {
      uVar1 = *(undefined4 *)((int)&pstudio->Cache_Check + uVar3);
      *(undefined4 *)((int)&IEngineStudio.Mem_Calloc + uVar3) =
           *(undefined4 *)((int)&pstudio->Mem_Calloc + uVar3);
      *(undefined4 *)((int)&IEngineStudio.Cache_Check + uVar3) = uVar1;
      uVar3 = uVar3 + 8;
    } while (uVar3 < 0xb8);
    CStudioModelRenderer::Init(&g_StudioRenderer.super_CStudioModelRenderer);
    iVar2 = 1;
  }
  return iVar2;
}


// HUD_GetUserEntity  @ 0008e460
cl_entity_t * HUD_GetUserEntity(int index)

{
  return (cl_entity_t *)0x0;
}


// HUD_GetWeaponAnim  @ 0008be90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int HUD_GetWeaponAnim(void)

{
  return g_currentanim;
}


// HUD_Init  @ 0008e5b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HUD_Init(void)

{
  InitInput();
  CHud::Init(&gHUD);
  Scheme_Init();
  return;
}


// HUD_InitClientWeapons  @ 000813b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Struct "CTFSuperNailgun": ignoring overlapping field "m_usFireSuperNailGun" */
/* WARNING: Struct "CTFSuperShotgun": ignoring overlapping field "m_usFireSuperShotgun" */

void HUD_InitClientWeapons(void)

{
  longdouble extraout_ST0;
  
  if (HUD_InitClientWeapons::lexical_block_0::initialized == 0) {
    HUD_InitClientWeapons::lexical_block_0::initialized = 1;
    g_engfuncs.pfnPrecacheModel = stub_PrecacheModel;
    g_engfuncs.pfnPrecacheSound = stub_PrecacheSound;
    g_engfuncs.pfnNameForFunction = stub_NameForFunction;
    g_engfuncs.pfnSetModel = stub_SetModel;
    g_engfuncs.pfnPlaybackEvent = HUD_PlaybackEvent;
    g_engfuncs.pfnPrecacheEvent = gEngfuncs.pfnPrecacheEvent;
    g_engfuncs.pfnRandomFloat = gEngfuncs.pfnRandomFloat;
    g_engfuncs.pfnRandomLong = gEngfuncs.pfnRandomLong;
    g_engfuncs.pfnAlertMessage = AlertMessage;
    g_engfuncs.pfnSetClientMaxspeed = HUD_SetMaxSpeed;
    gpGlobals = &Globals;
    (*gEngfuncs.GetClientTime)();
    Globals.time = (float)extraout_ST0;
    HUD_PrepEntity((CBaseEntity *)&player,(CBasePlayer *)0x0,0);
    player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = 0;
    HUD_PrepEntity((CBaseEntity *)&g_Gun,&player,1);
    HUD_PrepEntity((CBaseEntity *)&g_Super,&player,1);
    HUD_PrepEntity((CBaseEntity *)&g_NG,&player,3);
    HUD_PrepEntity((CBaseEntity *)&g_SNG,&player,3);
    HUD_PrepEntity((CBaseEntity *)&g_Tranq,&player,3);
    (g_Tranq.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->body = 1;
    HUD_PrepEntity((CBaseEntity *)&g_Flame,&player,2);
    HUD_PrepEntity((CBaseEntity *)&g_IC,&player,4);
    HUD_PrepEntity((CBaseEntity *)&g_Rail,&player,3);
    HUD_PrepEntity((CBaseEntity *)&g_RPG,&player,4);
    HUD_PrepEntity((CBaseEntity *)&g_AR,&player,1);
    HUD_PrepEntity((CBaseEntity *)&g_AC,&player,1);
    HUD_PrepEntity((CBaseEntity *)&g_GL,&player,4);
    HUD_PrepEntity((CBaseEntity *)&g_PL,&player,4);
    HUD_PrepEntity((CBaseEntity *)&g_Sniper,&player,0);
    HUD_PrepEntity((CBaseEntity *)&g_Knife,&player,0);
    HUD_PrepEntity((CBaseEntity *)&g_Spanner,&player,0);
    HUD_PrepEntity((CBaseEntity *)&g_Medkit,&player,0);
    HUD_PrepEntity((CBaseEntity *)&g_Crowbar,&player,0);
    HUD_PrepEntity(&g_Spot.super_CBaseEntity,(CBasePlayer *)0x0,0);
    g_Sniper.super_CBasePlayerWeapon.m_fInZoom = 0;
    g_Sniper.m_iSpotActive = 0;
    g_Sniper.m_pSpot = (CLaserSpot *)0x0;
    g_Sniper.super_CBasePlayerWeapon.m_fAimedDamage = 0.0;
    g_Sniper.super_CBasePlayerWeapon.m_fNextAimBonus = 0.0;
    (g_Spot.super_CBaseEntity.pev)->effects = (g_Spot.super_CBaseEntity.pev)->effects | 0x80;
  }
  return;
}


// HUD_IsGame  @ 000835b0
int HUD_IsGame(char *game)

{
  char *in;
  int iVar1;
  char local_40c [1032];
  
                    /* Unresolved local var: char * gamedir@[???]
                       Unresolved local var: char[1024] gd@[???] */
  in = (*gEngfuncs.pfnGetGameDirectory)();
  if ((in != (char *)0x0) && (*in != '\0')) {
    COM_FileBase(in,local_40c);
    iVar1 = strcasecmp(local_40c,game);
    return (uint)(iVar1 == 0);
  }
  return 0;
}


// HUD_Key_Event  @ 00097380
int HUD_Key_Event(int down,int keynum,char *pszCurrentBinding)

{
  int iVar1;
  
  iVar1 = 1;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::KeyInput(gViewPort,down,keynum,pszCurrentBinding);
  }
  return iVar1;
}


// HUD_NeedSpot  @ 000809e0
int HUD_NeedSpot(int *damage)

{
  *damage = g_laserdot.laserdotintensity;
  return g_laserdot.laserdotactive;
}


// HUD_PlaySound  @ 0008bea0
void HUD_PlaySound(char *sound,float volume)

{
  if ((g_runfuncs != 0) && (g_finalstate != (local_state_s *)0x0)) {
    (*gEngfuncs.pfnPlaySoundByNameAtLocation)(sound,volume,&(g_finalstate->playerstate).origin.x);
  }
  return;
}


// HUD_PlaybackEvent  @ 0008bee0
void HUD_PlaybackEvent(int flags,edict_t *pInvoker,ushort eventindex,float delay,float *origin,
                      float *angles,float fparam1,float fparam2,int iparam1,int iparam2,int bparam1,
                      int bparam2)

{
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: Vector org@[???]
                       Unresolved local var: Vector ang@[???] */
  if ((g_runfuncs != 0) && (g_finalstate != (local_state_s *)0x0)) {
    local_24 = (g_finalstate->playerstate).origin.x;
    local_20 = (g_finalstate->playerstate).origin.y;
    local_1c = (g_finalstate->playerstate).origin.z;
    local_18 = v_angles.x;
    local_14 = v_angles.y;
    local_10 = v_angles.z;
    (*gEngfuncs.pfnPlaybackEvent)
              (flags,pInvoker,eventindex,delay,&local_24,&local_18,fparam1,fparam2,iparam1,iparam2,
               bparam1,bparam2);
  }
  return;
}


// HUD_PlayerMove  @ 0008e5f0
void HUD_PlayerMove(playermove_s *ppmove,int server)

{
  playermove_t *ppVar1;
  
  pmove = ppmove;
  PM_PlayerMove((uint)(server != 0));
  ppVar1 = pmove;
  if (pmove->onground == -1) {
    pmove->flags = pmove->flags & 0xfffffdff;
  }
  else {
    pmove->flags = pmove->flags | 0x200;
  }
  if ((ppVar1->multiplayer == false) && (ppVar1->movetype == 3)) {
    ppVar1->friction = 1.0;
    return;
  }
  return;
}


// HUD_PlayerMoveInit  @ 0008e610
void HUD_PlayerMoveInit(playermove_s *ppmove)

{
  pmove = ppmove;
  PM_CreateStuckTable();
  PM_InitTextureTypes();
  pm_shared_initialized = 1;
  return;
}


// HUD_PlayerMoveTexture  @ 0008e600
char HUD_PlayerMoveTexture(char *name)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = gcTextures + -1;
  if (-1 < iVar4) {
    iVar3 = 0;
    do {
      while( true ) {
        iVar2 = (iVar3 + iVar4) / 2;
        iVar1 = strncasecmp(name,grgszTextureName[iVar2],0xc);
        if (iVar1 == 0) {
          return grgchTextureType[iVar2];
        }
        if (0 < iVar1) break;
        iVar4 = iVar2 + -1;
        if (iVar4 < iVar3) {
          return 'C';
        }
      }
      iVar3 = iVar2 + 1;
    } while (iVar3 <= iVar4);
  }
  return 'C';
}


// HUD_PostRunCmd  @ 000820d0
void HUD_PostRunCmd(local_state_s *from,local_state_s *to,usercmd_s *cmd,int runfuncs,double time,
                   uint random_seed)

{
  g_runfuncs = runfuncs;
  if ((cl_lw != (cvar_t *)0x0) && (cl_lw->value != 0.0)) {
    if ((to->client).iuser4 == 0) {
      HUD_WeaponsPostThink(from,to,cmd,time,random_seed);
    }
    g_lastFOV = (to->client).fov;
    return;
  }
  (to->client).fov = g_lastFOV;
  g_laserdot.laserdotactive = 0;
  return;
}


// HUD_PrepEntity  @ 000807c0
/* WARNING: Removing unreachable block (ram,0x00080908) */
/* WARNING: Removing unreachable block (ram,0x00080920) */
/* WARNING: Removing unreachable block (ram,0x00080862) */
/* WARNING: Removing unreachable block (ram,0x00080839) */
/* WARNING: Removing unreachable block (ram,0x0008086f) */

void HUD_PrepEntity(CBaseEntity *pEntity,CBasePlayer *pWeaponOwner,int ammotype)

{
  entvars_s *peVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 local_48 [32];
  int local_28;
  
  iVar3 = num_ents * 0x2a4;
  peVar1 = ev + num_ents;
  uVar2 = 0;
  do {
    uVar4 = uVar2;
    *(undefined4 *)((int)&peVar1->classname + uVar4) = 0;
    *(undefined4 *)(iVar3 + 0x111384 + uVar4) = 0;
    *(undefined4 *)(iVar3 + 0x111388 + uVar4) = 0;
    *(undefined4 *)(iVar3 + 0x11138c + uVar4) = 0;
    uVar2 = uVar4 + 0x10;
  } while (uVar4 + 0x10 < 0x2a0);
  *(undefined4 *)((int)&(peVar1->origin).z + uVar4) = 0;
  num_ents = num_ents + 1;
  pEntity->pev = peVar1;
  (*pEntity->_vptr_CBaseEntity[3])(pEntity);
  (*pEntity->_vptr_CBaseEntity[2])(pEntity);
  if (pWeaponOwner != (CBasePlayer *)0x0) {
                    /* Unresolved local var: ItemInfo info@[???] */
    pEntity[1].m_pfnTouch.__delta = (int)pWeaponOwner;
    if (ammotype == 2) {
      pEntity->current_ammo =
           &(pWeaponOwner->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.ammo_cells;
    }
    else if (ammotype < 3) {
      if (ammotype == 1) {
        pEntity->current_ammo =
             &(pWeaponOwner->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.ammo_shells;
      }
    }
    else if (ammotype == 3) {
      pEntity->current_ammo =
           &(pWeaponOwner->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.ammo_nails;
    }
    else if (ammotype == 4) {
      pEntity->current_ammo =
           &(pWeaponOwner->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.ammo_rockets;
    }
    (*pEntity->_vptr_CBaseEntity[0x45])(pEntity,local_48);
    g_pWpns[local_28] = (CBasePlayerWeapon *)pEntity;
  }
  return;
}


// HUD_ProcessPlayerState  @ 0008d200
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


// HUD_Redraw  @ 0008e580
int HUD_Redraw(float time,int intermission)

{
  CHud::Redraw(&gHUD,time,intermission);
  return 1;
}


// HUD_Reset  @ 0008e530
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HUD_Reset(void)

{
  CHud::VidInit(&gHUD);
  return;
}


// HUD_SendWeaponAnim  @ 0008be60
void HUD_SendWeaponAnim(int iAnim,int body,int force)

{
  if (force == 0 && g_runfuncs == 0) {
    return;
  }
  g_currentanim = iAnim;
                    /* WARNING: Could not recover jumptable at 0x0008be83. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEngfuncs.pfnWeaponAnim)(iAnim,body);
  return;
}


// HUD_SetLastOrg  @ 000809a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HUD_SetLastOrg(void)

{
                    /* Unresolved local var: int i@[???] */
  g_laserdot.previousorigin.x =
       (g_finalstate->playerstate).origin.x + (g_finalstate->client).view_ofs.x;
  g_laserdot.previousorigin.y =
       (g_finalstate->playerstate).origin.y + (g_finalstate->client).view_ofs.y;
  g_laserdot.previousorigin.z =
       (g_finalstate->playerstate).origin.z + (g_finalstate->client).view_ofs.z;
  return;
}


// HUD_SetMaxSpeed  @ 0008bfb0
void HUD_SetMaxSpeed(edict_t *ed,float speed)

{
  return;
}


// HUD_SetupBenchObjects  @ 00091bb0
int __regparm3 HUD_SetupBenchObjects(cl_entity_t_conflict *bench,int plindex,Vector origin)

{
  float fVar1;
  vec_t vVar2;
  model_s *pmVar3;
  int iVar4;
  float *pfVar5;
  int32 iVar6;
  uint uVar7;
  int iVar8;
  pmtrace_s local_c0;
  float local_7c;
  vec_t local_78;
  vec_t local_74;
  float local_6c [4];
  float local_5c;
  float local_58;
  float local_54;
  float local_50 [3];
  float local_44 [3];
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: Vector ang@[???]
                       Unresolved local var: float offset@[???]
                       Unresolved local var: model_s.conflict * mdl@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector farpoint@[???]
                       Unresolved local var: Vector centerspot@[???]
                       Unresolved local var: pmtrace_t tr@[???] */
  local_7c = vec3_origin.x;
  local_78 = vec3_origin.y;
  local_74 = vec3_origin.z;
  (*gEngfuncs.pfnAngleVectors)(&local_7c,&local_5c,local_50,local_44);
  pmVar3 = (*gEngfuncs.CL_LoadModel)("models/spikeball.mdl",local_20);
  iVar4 = 0;
  if (pmVar3 != (model_s *)0x0) {
    iVar4 = 0;
    (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
    (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
    (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)((int)bench);
    (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
    local_2c = *(float *)plindex;
    local_28 = *(float *)(plindex + 4);
    local_24 = *(float *)(plindex + 8) - 512.0;
    (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)((float *)plindex,&local_2c,0,-1,&local_c0);
    g_flStartTime = gHUD.m_flTime;
    local_24 = local_54 * 250.0 + local_c0.endpos.z + 72.0;
    local_28 = local_58 * 250.0 + local_c0.endpos.y;
    local_2c = local_5c * 250.0 + local_c0.endpos.x;
    do {
      pfVar5 = local_6c;
      local_7c = 0.0;
      local_74 = 0.0;
      local_6c[0] = 0.0;
      local_6c[2] = 0.0;
      local_78 = ((float)iVar4 / 11.0) * 360.0;
      local_6c[1] = local_78;
      do {
                    /* Unresolved local var: int i@[???] */
        fVar1 = *pfVar5;
        if (fVar1 < -180.0) {
          do {
            fVar1 = fVar1 + 360.0;
          } while (fVar1 < -180.0);
          *pfVar5 = fVar1;
        }
        if (180.0 < fVar1) {
          do {
            fVar1 = fVar1 - 360.0;
          } while (180.0 < fVar1);
          *pfVar5 = fVar1;
        }
        pfVar5 = pfVar5 + 1;
      } while (pfVar5 != local_6c + 3);
      iVar8 = iVar4 * 3000;
      (*gEngfuncs.pfnAngleVectors)(&local_7c,&local_5c,local_50,local_44);
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].model = (model_s_conflict *)pmVar3;
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].curstate.modelindex = local_20[0];
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].curstate.movetype = 0;
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].curstate.solid = 0;
      local_30 = local_54 * 80.0 + local_24;
      local_34 = local_58 * 80.0 + local_28;
      local_38 = local_5c * 80.0 + local_2c;
      (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_2c,&local_38,0,-1,&local_c0);
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].curstate.angles.z = 0.0;
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].origin.z = local_c0.endpos.z;
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].curstate.origin.z = local_c0.endpos.z;
      vVar2 = vec3_origin.x;
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].origin.y = local_c0.endpos.y;
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].curstate.origin.y = local_c0.endpos.y;
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].origin.x = local_c0.endpos.x;
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].curstate.velocity.x = vVar2;
      vVar2 = vec3_origin.y;
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].curstate.origin.x = local_c0.endpos.x;
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].curstate.angles.x = 0.0;
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].curstate.angles.y = 0.0;
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].curstate.velocity.y = vVar2;
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].curstate.velocity.z = vec3_origin.z;
      iVar6 = (*gEngfuncs.pfnRandomLong)(-300,300);
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].baseline.angles.z = 0.0;
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].baseline.angles.x = (float)iVar6;
      iVar6 = (*gEngfuncs.pfnRandomLong)(-300,300);
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].baseline.angles.y = (float)iVar6;
      iVar6 = (*gEngfuncs.pfnRandomLong)(-300,300);
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].baseline.angles.z = 0.0;
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].baseline.angles.x = (float)iVar6;
      iVar6 = (*gEngfuncs.pfnRandomLong)(-300,300);
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].baseline.angles.y = (float)iVar6;
      iVar6 = (*gEngfuncs.pfnRandomLong)(-300,300);
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].baseline.angles.z = 0.0;
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].baseline.angles.x = (float)iVar6;
      iVar6 = (*gEngfuncs.pfnRandomLong)(-300,300);
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].curstate.renderamt = 0;
      uVar7 = 0;
      HUD_CreateBenchObjects::lexical_block_0::bench[iVar4].baseline.angles.y = (float)iVar6;
      do {
        *(undefined4 *)(iVar8 + 0x121fe0 + uVar7) = *(undefined4 *)(iVar8 + 0x122134 + uVar7);
        *(undefined4 *)(iVar8 + 0x121fdc + uVar7) = *(undefined4 *)(iVar8 + 0x122130 + uVar7);
        uVar7 = uVar7 + 8;
      } while (uVar7 < 0x150);
      iVar4 = iVar4 + 1;
      *(undefined4 *)(iVar8 + 0x121fdc + uVar7) = *(undefined4 *)(iVar8 + 0x122130 + uVar7);
    } while (iVar4 != 0xc);
    (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
    iVar4 = 1;
  }
  return iVar4;
}


// HUD_SetupBenchObjects  @ 00093220
int HUD_SetupBenchObjects(cl_entity_t_conflict *bench,int plindex,Vector origin)

{
  float fVar1;
  undefined4 uVar2;
  vec_t vVar3;
  uint uVar4;
  model_s *pmVar5;
  int iVar6;
  float *pfVar7;
  int32 iVar8;
  uint uVar9;
  int local_d4;
  pmtrace_s local_c0;
  float local_7c;
  vec_t local_78;
  vec_t local_74;
  float local_6c [4];
  float local_5c;
  float local_58;
  float local_54;
  float local_50 [3];
  float local_44 [3];
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: Vector ang@[???]
                       Unresolved local var: float offset@[???]
                       Unresolved local var: model_s.conflict * mdl@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector farpoint@[???]
                       Unresolved local var: Vector centerspot@[???]
                       Unresolved local var: pmtrace_t tr@[???] */
  local_7c = vec3_origin.x;
  local_78 = vec3_origin.y;
  local_74 = vec3_origin.z;
  (*gEngfuncs.pfnAngleVectors)(&local_7c,&local_5c,local_50,local_44);
  pmVar5 = (*gEngfuncs.CL_LoadModel)("models/spikeball.mdl",local_20);
  iVar6 = 0;
  if (pmVar5 != (model_s *)0x0) {
    (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
    (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
    (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(plindex);
    (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
    local_2c = *(float *)origin.x;
    local_28 = *(float *)((int)origin.x + 4);
    local_24 = *(float *)((int)origin.x + 8) - 512.0;
    (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)((float *)origin.x,&local_2c,0,-1,&local_c0);
    local_d4 = 0;
    g_flStartTime = gHUD.m_flTime;
    local_24 = local_54 * 250.0 + local_c0.endpos.z + 72.0;
    local_28 = local_58 * 250.0 + local_c0.endpos.y;
    local_2c = local_5c * 250.0 + local_c0.endpos.x;
    do {
      pfVar7 = local_6c;
      local_7c = 0.0;
      local_74 = 0.0;
      local_6c[0] = 0.0;
      local_6c[2] = 0.0;
      local_78 = ((float)local_d4 / 11.0) * 360.0;
      local_6c[1] = local_78;
      do {
                    /* Unresolved local var: int i@[???] */
        fVar1 = *pfVar7;
        if (fVar1 < -180.0) {
          do {
            fVar1 = fVar1 + 360.0;
          } while (fVar1 < -180.0);
          *pfVar7 = fVar1;
        }
        if (180.0 < fVar1) {
          do {
            fVar1 = fVar1 - 360.0;
          } while (180.0 < fVar1);
          *pfVar7 = fVar1;
        }
        pfVar7 = pfVar7 + 1;
      } while (pfVar7 != local_6c + 3);
      (*gEngfuncs.pfnAngleVectors)(&local_7c,&local_5c,local_50,local_44);
      bench->model = (model_s_conflict *)pmVar5;
      (bench->curstate).modelindex = local_20[0];
      (bench->curstate).movetype = 0;
      (bench->curstate).solid = 0;
      local_30 = local_54 * 80.0 + local_24;
      local_34 = local_58 * 80.0 + local_28;
      local_38 = local_5c * 80.0 + local_2c;
      (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_2c,&local_38,0,-1,&local_c0);
      (bench->origin).y = local_c0.endpos.y;
      (bench->curstate).origin.y = local_c0.endpos.y;
      (bench->origin).x = local_c0.endpos.x;
      (bench->curstate).origin.x = local_c0.endpos.x;
      (bench->origin).z = local_c0.endpos.z;
      (bench->curstate).origin.z = local_c0.endpos.z;
      (bench->curstate).velocity.x = vec3_origin.x;
      (bench->curstate).velocity.y = vec3_origin.y;
      vVar3 = vec3_origin.z;
      (bench->curstate).angles.z = 0.0;
      (bench->curstate).angles.x = 0.0;
      (bench->curstate).angles.y = 0.0;
      (bench->curstate).velocity.z = vVar3;
      iVar8 = (*gEngfuncs.pfnRandomLong)(-300,300);
      (bench->baseline).angles.z = 0.0;
      (bench->baseline).angles.x = (float)iVar8;
      iVar8 = (*gEngfuncs.pfnRandomLong)(-300,300);
      (bench->baseline).angles.y = (float)iVar8;
      iVar8 = (*gEngfuncs.pfnRandomLong)(-300,300);
      (bench->baseline).angles.z = 0.0;
      (bench->baseline).angles.x = (float)iVar8;
      iVar8 = (*gEngfuncs.pfnRandomLong)(-300,300);
      (bench->baseline).angles.y = (float)iVar8;
      iVar8 = (*gEngfuncs.pfnRandomLong)(-300,300);
      (bench->baseline).angles.z = 0.0;
      (bench->baseline).angles.x = (float)iVar8;
      iVar8 = (*gEngfuncs.pfnRandomLong)(-300,300);
      (bench->curstate).renderamt = 0;
      (bench->baseline).angles.y = (float)iVar8;
      uVar4 = 0;
      do {
        uVar9 = uVar4;
        uVar2 = *(undefined4 *)((bench->curstate).controller + (uVar9 - 0x68));
        *(undefined4 *)((bench->prevstate).controller + (uVar9 - 100)) =
             *(undefined4 *)((bench->curstate).controller + (uVar9 - 100));
        *(undefined4 *)((bench->prevstate).controller + (uVar9 - 0x68)) = uVar2;
        uVar4 = uVar9 + 8;
      } while (uVar9 + 8 < 0x150);
      local_d4 = local_d4 + 1;
      *(undefined4 *)((bench->prevstate).controller + (uVar9 - 0x60)) =
           *(undefined4 *)((bench->curstate).controller + (uVar9 - 0x60));
      bench = bench + 1;
    } while (local_d4 != 0xc);
    (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
    iVar6 = 1;
  }
  return iVar6;
}


// HUD_Shutdown  @ 00098be0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HUD_Shutdown(void)

{
  kblist_s *pkVar1;
  kblist_t *__ptr;
  
                    /* Unresolved local var: CSysModule * g_hTrackerModule@[???] */
  IN_Shutdown();
  __ptr = g_kbkeys;
                    /* Unresolved local var: kblist_t * p@[???]
                       Unresolved local var: kblist_t * n@[???] */
  while (__ptr != (kblist_t *)0x0) {
    pkVar1 = __ptr->next;
    free(__ptr);
    __ptr = pkVar1;
  }
  g_kbkeys = (kblist_t *)0x0;
  ClearEventList();
  CL_UnloadParticleMan();
  if (g_hTrackerModule != (CSysModule *)0x0) {
    Sys_UnloadModule(g_hTrackerModule);
  }
  return;
}


// HUD_SpotActive  @ 00080a00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int HUD_SpotActive(void)

{
  return (uint)(((g_Spot.super_CBaseEntity.pev)->effects & 0x80) == 0);
}


// HUD_StudioEvent  @ 0008d610
void HUD_StudioEvent(mstudioevent_s *event,cl_entity_s *entity)

{
  _func_void_float_ptr_int_int_int *p_Var1;
  long lVar2;
  Vector *pVVar3;
  _func_void_float_ptr_int *UNRECOVERED_JUMPTABLE;
  bool bVar4;
  
                    /* Unresolved local var: int iMuzzleFlash@[???] */
  bVar4 = *(int *)(&DAT_0010947c + entity->index * 4) == 0;
  switch(event->event) {
  case 0x1389:
    if (bVar4) {
      pVVar3 = entity->attachment;
      UNRECOVERED_JUMPTABLE = (gEngfuncs.pEfxAPI)->R_MuzzleFlash;
      entity = (cl_entity_s *)strtol(event->options,(char **)0x0,10);
LAB_0008d7b4:
                    /* WARNING: Could not recover jumptable at 0x0008d7c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(&pVVar3->x,(int)entity);
      return;
    }
    break;
  case 0x138a:
    p_Var1 = (gEngfuncs.pEfxAPI)->R_SparkEffect;
    lVar2 = strtol(event->options,(char **)0x0,10);
    (*p_Var1)(&entity->attachment[0].x,lVar2,-100,100);
    return;
  case 0x138c:
    (*gEngfuncs.pfnPlaySoundByNameAtLocation)(event->options,1.0,&entity->attachment[0].x);
    break;
  case 0x1393:
    if (bVar4) {
      pVVar3 = entity->attachment + 1;
      UNRECOVERED_JUMPTABLE = (gEngfuncs.pEfxAPI)->R_MuzzleFlash;
      entity = (cl_entity_s *)strtol(event->options,(char **)0x0,10);
      goto LAB_0008d7b4;
    }
    break;
  case 0x139d:
    if (bVar4) {
      pVVar3 = entity->attachment + 2;
      UNRECOVERED_JUMPTABLE = (gEngfuncs.pEfxAPI)->R_MuzzleFlash;
      entity = (cl_entity_s *)strtol(event->options,(char **)0x0,10);
      goto LAB_0008d7b4;
    }
    break;
  case 0x13a7:
    if (bVar4) {
      pVVar3 = entity->attachment + 3;
      UNRECOVERED_JUMPTABLE = (gEngfuncs.pEfxAPI)->R_MuzzleFlash;
      entity = (cl_entity_s *)strtol(event->options,(char **)0x0,10);
      goto LAB_0008d7b4;
    }
  }
  return;
}


// HUD_TempEntUpdate  @ 0008d7d0
void HUD_TempEntUpdate(double frametime,double client_time,double cl_gravity,
                      TEMPENTITY **ppTempEntFree,TEMPENTITY **ppTempEntActive,
                      _func_int_cl_entity_t_ptr *Callback_AddVisibleEntity,
                      _func_void_TEMPENTITY_ptr_float *Callback_TempEntPlaySound)

{
  Vector *pVVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  tempent_s *ptVar5;
  vec_t vVar6;
  float fVar7;
  float fVar8;
  tempent_s *ptVar9;
  tempent_s *ptVar10;
  cl_entity_s *pcVar11;
  physent_s_conflict *ppVar12;
  uint uVar13;
  dlight_t *pdVar14;
  int iVar15;
  float fVar16;
  double dVar17;
  Vector *local_b4;
  Vector *local_a8;
  pmtrace_s local_9c;
  float local_4c;
  float local_48;
  float local_44;
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  
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
  (*gEngfuncs.GetViewAngles)(&local_34);
  if (g_pParticleMan != (IParticleMan *)0x0) {
    local_28 = local_34;
    local_24 = local_30;
    local_20 = local_2c;
    (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[4])
              (g_pParticleMan,(float)cl_gravity,&local_28);
  }
  if (*ppTempEntActive != (TEMPENTITY *)0x0) {
    (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
    (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
    (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(-1);
    HUD_TempEntUpdate::lexical_block_0::gTempEntFrame =
         HUD_TempEntUpdate::lexical_block_0::gTempEntFrame + 1U & 0x1f;
    ptVar5 = *ppTempEntActive;
    if (frametime <= 0.0) {
      for (; ptVar5 != (tempent_s *)0x0; ptVar5 = ptVar5->next) {
        if ((ptVar5->flags & 0x40000U) == 0) {
          (*Callback_AddVisibleEntity)(&ptVar5->entity);
        }
      }
    }
    else {
      fVar2 = (float)(-(longdouble)frametime * (longdouble)cl_gravity);
      ptVar10 = (tempent_s *)0x0;
      while (ptVar9 = ptVar5, ptVar9 != (tempent_s *)0x0) {
        fVar3 = ptVar9->die - (float)client_time;
        ptVar5 = ptVar9->next;
        uVar13 = ptVar9->flags;
        if (0.0 <= fVar3) {
LAB_0008d97a:
          fVar3 = (ptVar9->entity).origin.x;
          (ptVar9->entity).prevstate.origin.x = fVar3;
          fVar16 = (ptVar9->entity).origin.y;
          (ptVar9->entity).prevstate.origin.y = fVar16;
          fVar4 = (ptVar9->entity).origin.z;
          (ptVar9->entity).prevstate.origin.z = fVar4;
          if ((uVar13 & 0x20000) == 0) {
            if ((uVar13 & 0x8000) == 0) {
              if ((uVar13 & 1) == 0) {
                if ((uVar13 & 0x400) == 0) {
                  (ptVar9->entity).origin.x =
                       (float)frametime * (ptVar9->entity).baseline.origin.x + fVar3;
                  (ptVar9->entity).origin.y =
                       (float)frametime * (ptVar9->entity).baseline.origin.y + fVar16;
                  (ptVar9->entity).origin.z =
                       (float)frametime * (ptVar9->entity).baseline.origin.z + fVar4;
                }
                else {
                    /* Unresolved local var: float s@[???]
                       Unresolved local var: float c@[???] */
                  dVar17 = sin(client_time * 20.0 + (double)(int)ptVar9);
                  (ptVar9->entity).origin.x =
                       fVar3 + (float)dVar17 * 8.0 +
                               (float)frametime * (ptVar9->entity).baseline.origin.x;
                  dVar17 = sin((double)(int)ptVar9 + client_time * 30.0);
                  (ptVar9->entity).origin.y =
                       fVar16 + (float)dVar17 * 4.0 +
                                (float)frametime * (ptVar9->entity).baseline.origin.y;
                  (ptVar9->entity).origin.z =
                       fVar4 + (float)frametime * (ptVar9->entity).baseline.origin.z;
                }
              }
              else {
                fVar7 = (float)frametime * (ptVar9->entity).baseline.origin.x + ptVar9->x;
                ptVar9->x = fVar7;
                fVar8 = (float)frametime * (ptVar9->entity).baseline.origin.y + ptVar9->y;
                ptVar9->y = fVar8;
                fVar3 = (ptVar9->entity).baseline.origin.z;
                dVar17 = sin((double)((float)client_time * (ptVar9->entity).prevstate.frame + fVar3)
                            );
                fVar16 = (ptVar9->entity).curstate.framerate;
                (ptVar9->entity).origin.x = fVar7 + fVar16 * 10.0 * (float)dVar17;
                dVar17 = sin((double)(fVar3 + (float)client_time * 5.5 + 0.7));
                (ptVar9->entity).origin.y = fVar8 + fVar16 * 8.0 * (float)dVar17;
                (ptVar9->entity).origin.z = fVar4 + fVar3 * (float)frametime;
              }
            }
            else {
                    /* Unresolved local var: cl_entity_t * pClient@[???] */
              pcVar11 = (*gEngfuncs.GetEntityByIndex)((int)ptVar9->clientIndex);
              (ptVar9->entity).origin.x = (pcVar11->origin).x + (ptVar9->tentOffset).x;
              (ptVar9->entity).origin.y = (pcVar11->origin).y + (ptVar9->tentOffset).y;
              uVar13 = ptVar9->flags;
              (ptVar9->entity).origin.z = (pcVar11->origin).z + (ptVar9->tentOffset).z;
            }
          }
          else if ((ptVar9->entity).baseline.scale < (float)client_time) {
            (*(gEngfuncs.pEfxAPI)->R_SparkEffect)(&(ptVar9->entity).origin.x,8,-200,200);
            fVar3 = (float)((longdouble)(ptVar9->entity).baseline.framerate - (longdouble)0.1);
            (ptVar9->entity).baseline.framerate = fVar3;
            if (0.0 < fVar3) {
              ptVar9->die = (float)client_time + 0.5;
              (ptVar9->entity).baseline.scale = (float)((longdouble)0.1 + (longdouble)client_time);
              uVar13 = ptVar9->flags;
            }
            else {
              ptVar9->die = (float)client_time;
              uVar13 = ptVar9->flags;
            }
          }
          ptVar10 = ptVar9;
          if ((uVar13 & 0x100) == 0) {
            if ((uVar13 & 0x800) != 0) {
              fVar3 = (float)frametime * 10.0 + (ptVar9->entity).curstate.frame;
              (ptVar9->entity).curstate.frame = fVar3;
              if (ptVar9->frameMax <= fVar3) {
                (ptVar9->entity).curstate.frame = fVar3 - (float)(int)fVar3;
              }
            }
LAB_0008db50:
            if ((uVar13 & 4) != 0) {
              fVar3 = (float)frametime * (ptVar9->entity).baseline.angles.x +
                      (ptVar9->entity).angles.x;
              (ptVar9->entity).angles.x = fVar3;
              fVar16 = (float)frametime * (ptVar9->entity).baseline.angles.y +
                       (ptVar9->entity).angles.y;
              (ptVar9->entity).angles.y = fVar16;
              fVar4 = (float)frametime * (ptVar9->entity).baseline.angles.z +
                      (ptVar9->entity).angles.z;
              (ptVar9->entity).angles.z = fVar4;
              (ptVar9->entity).latched.prevangles.x = fVar3;
              (ptVar9->entity).latched.prevangles.y = fVar16;
              (ptVar9->entity).latched.prevangles.z = fVar4;
            }
            if ((uVar13 & 0x1020) != 0) {
                    /* Unresolved local var: Vector traceNormal@[???]
                       Unresolved local var: float traceFraction@[???] */
              if ((uVar13 & 0x1000) == 0) {
                if ((uVar13 & 0x20) != 0) {
                    /* Unresolved local var: pmtrace_t pmtrace@[???] */
                  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
                  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)
                            (&(ptVar9->entity).prevstate.origin.x,&(ptVar9->entity).origin.x,10,-1,
                             &local_9c);
                  fVar3 = local_9c.fraction;
                  if (local_9c.fraction == 1.0) {
LAB_0008e00a:
                    /* Unresolved local var: float proj@[???]
                       Unresolved local var: float damp@[???] */
                    uVar13 = ptVar9->flags;
                  }
                  else {
                    pVVar1 = &(ptVar9->entity).baseline.origin;
                    local_4c = local_9c.plane.normal.x;
                    local_48 = local_9c.plane.normal.y;
                    local_44 = local_9c.plane.normal.z;
                    if ((ptVar9->flags & 0x20000U) != 0) {
                      VectorScale(&pVVar1->x,0.6,&pVVar1->x);
                      fVar16 = Length(&pVVar1->x);
                      if (fVar16 < 10.0) {
                        (ptVar9->entity).baseline.framerate = 0.0;
                      }
                    }
                    if (ptVar9->hitcallback != (_func_void_tempent_s_ptr_pmtrace_s_ptr *)0x0) {
                      (*ptVar9->hitcallback)(ptVar9,&local_9c);
                    }
LAB_0008e109:
                    local_a8 = &(ptVar9->entity).baseline.origin;
                    local_b4 = &(ptVar9->entity).origin;
                    VectorMA(&(ptVar9->entity).prevstate.origin.x,(float)frametime * fVar3,
                             &local_a8->x,&local_b4->x);
                    uVar13 = ptVar9->flags;
                    fVar3 = ptVar9->bounceFactor;
                    if (((((uVar13 & 10) != 0) && (fVar3 = fVar3 * 0.5, 0.9 < local_44)) &&
                        (fVar16 = (ptVar9->entity).baseline.origin.z, fVar16 <= 0.0)) &&
                       (fVar2 * 3.0 <= fVar16)) {
                      fVar3 = 0.0;
                      (ptVar9->entity).angles.x = 0.0;
                      uVar13 = uVar13 & 0xffffffc1;
                      (ptVar9->entity).angles.z = 0.0;
                      ptVar9->flags = uVar13;
                    }
                    if (ptVar9->hitSound != 0) {
                      (*Callback_TempEntPlaySound)(ptVar9,fVar3);
                      uVar13 = ptVar9->flags;
                    }
                    if ((uVar13 & 0x4000) == 0) {
                      if (fVar3 != 0.0) {
                        fVar16 = -((ptVar9->entity).baseline.origin.z * local_44 +
                                  (ptVar9->entity).baseline.origin.y * local_48 +
                                  (ptVar9->entity).baseline.origin.x * local_4c);
                        VectorMA(&local_a8->x,fVar16 + fVar16,&local_4c,&local_a8->x);
                        (ptVar9->entity).angles.y = -(ptVar9->entity).angles.y;
                      }
                      if (fVar3 == 1.0) goto LAB_0008e00a;
                      VectorScale(&local_a8->x,fVar3,&local_a8->x);
                      pVVar1 = &(ptVar9->entity).angles;
                      VectorScale(&pVVar1->x,0.9,&pVVar1->x);
                      uVar13 = ptVar9->flags;
                    }
                    else {
                      uVar13 = uVar13 & 0xffffff7f;
                      ptVar9->flags = uVar13;
                      ptVar9->die = (float)client_time;
                    }
                  }
                }
              }
              else {
                    /* Unresolved local var: pmtrace_t pmtrace@[???]
                       Unresolved local var: physent_t * pe@[???] */
                (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
                (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)
                          (&(ptVar9->entity).prevstate.origin.x,&(ptVar9->entity).origin.x,2,-1,
                           &local_9c);
                if ((local_9c.fraction == 1.0) ||
                   ((ppVar12 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(local_9c.ent),
                    fVar3 = local_9c.fraction, local_9c.ent != 0 &&
                    (ppVar12->info == (int)ptVar9->clientIndex)))) goto LAB_0008e00a;
                local_4c = local_9c.plane.normal.x;
                local_48 = local_9c.plane.normal.y;
                local_44 = local_9c.plane.normal.z;
                if (ptVar9->hitcallback != (_func_void_tempent_s_ptr_pmtrace_s_ptr *)0x0) {
                  (*ptVar9->hitcallback)(ptVar9,&local_9c);
                }
                if (fVar3 != 1.0) goto LAB_0008e109;
                uVar13 = ptVar9->flags;
              }
            }
            if (((uVar13 & 0x40) != 0) &&
               ((ptVar9->entity).curstate.effects ==
                HUD_TempEntUpdate::lexical_block_0::gTempEntFrame)) {
                    /* Unresolved local var: dlight_t * dl@[???] */
              pdVar14 = (*(gEngfuncs.pEfxAPI)->CL_AllocDlight)(0);
              (pdVar14->origin).x = (ptVar9->entity).origin.x;
              (pdVar14->origin).y = (ptVar9->entity).origin.y;
              vVar6 = (ptVar9->entity).origin.z;
              pdVar14->radius = 60.0;
              (pdVar14->color).r = 0xff;
              (pdVar14->color).g = 'x';
              (pdVar14->origin).z = vVar6;
              (pdVar14->color).b = '\0';
              pdVar14->die = (float)((longdouble)client_time + (longdouble)0.01);
              uVar13 = ptVar9->flags;
            }
            if ((uVar13 & 0x10) != 0) {
              (*(gEngfuncs.pEfxAPI)->R_RocketTrail)
                        (&(ptVar9->entity).prevstate.origin.x,&(ptVar9->entity).origin.x,1);
              uVar13 = ptVar9->flags;
            }
            if ((uVar13 & 2) == 0) {
              if ((uVar13 & 8) != 0) {
                (ptVar9->entity).baseline.origin.z =
                     fVar2 * 0.5 + (ptVar9->entity).baseline.origin.z;
              }
            }
            else {
              (ptVar9->entity).baseline.origin.z = fVar2 + (ptVar9->entity).baseline.origin.z;
            }
            if (((uVar13 & 0x80000) != 0) &&
               (ptVar9->callback != (_func_void_tempent_s_ptr_float_float *)0x0)) {
              (*ptVar9->callback)(ptVar9,(float)frametime,(float)client_time);
              uVar13 = ptVar9->flags;
            }
            if ((((uVar13 & 0x40000) == 0) &&
                (iVar15 = (*Callback_AddVisibleEntity)(&ptVar9->entity), iVar15 == 0)) &&
               ((ptVar9->flags & 0x2000U) == 0)) {
              ptVar9->die = (float)client_time;
              ptVar9->flags = ptVar9->flags & 0xffffff7f;
            }
          }
          else {
            fVar3 = (float)frametime * (ptVar9->entity).curstate.framerate +
                    (ptVar9->entity).curstate.frame;
            (ptVar9->entity).curstate.frame = fVar3;
            if ((fVar3 < ptVar9->frameMax) ||
               ((ptVar9->entity).curstate.frame = fVar3 - (float)(int)fVar3, (uVar13 & 0x10000) != 0
               )) goto LAB_0008db50;
            ptVar9->die = (float)client_time;
          }
        }
        else {
          if ((uVar13 & 0x80) != 0) {
                    /* Unresolved local var: int active@[???] */
            if ((ptVar9->entity).curstate.rendermode == 0) {
              (ptVar9->entity).curstate.rendermode = 2;
            }
            iVar15 = (int)((fVar3 * ptVar9->fadeSpeed + 1.0) *
                          (float)(ptVar9->entity).baseline.renderamt);
            (ptVar9->entity).curstate.renderamt = iVar15;
            if (0 < iVar15) goto LAB_0008d97a;
          }
          ptVar9->next = *ppTempEntFree;
          *ppTempEntFree = ptVar9;
          if (ptVar10 == (tempent_s *)0x0) {
            *ppTempEntActive = ptVar5;
          }
          else {
            ptVar10->next = ptVar5;
          }
        }
      }
    }
    (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  }
  return;
}


// HUD_TxferLocalOverrides  @ 0008d1b0
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


// HUD_TxferPredictionData  @ 0008d3a0
void HUD_TxferPredictionData
               (entity_state_s *ps,entity_state_s *pps,clientdata_s *pcd,clientdata_s *ppcd,
               weapon_data_s *wd,weapon_data_s *pwd)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  byte bVar6;
  
  bVar6 = 0;
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
  g_iAlive = 1;
  iVar2 = ppcd->deadflag;
  pcd->deadflag = iVar2;
  if (ppcd->iuser1 == 0) {
    g_iAlive = (int)(iVar2 == 0);
  }
  pcd->iuser1 = ppcd->iuser1;
  pcd->iuser2 = ppcd->iuser2;
  pcd->iuser3 = ppcd->iuser3;
  iVar2 = (*gEngfuncs.IsSpectateOnly)();
  if (iVar2 != 0) {
    pcd->iuser1 = g_iUser1;
    pcd->iuser2 = g_iUser2;
    pcd->iuser3 = g_iUser3;
  }
  pcd->iuser4 = ppcd->iuser4;
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
  uVar3 = 0xb00;
  bVar5 = ((uint)wd & 1) != 0;
  if (bVar5) {
    piVar1 = &pwd->m_iId;
    pwd = (weapon_data_s *)((int)&pwd->m_iId + 1);
    *(char *)&wd->m_iId = (char)*piVar1;
    wd = (weapon_data_s *)((int)&wd->m_iId + 1);
    uVar3 = 0xaff;
  }
  if (((uint)wd & 2) != 0) {
    piVar1 = &pwd->m_iId;
    uVar3 = uVar3 - 2;
    pwd = (weapon_data_s *)((int)&pwd->m_iId + 2);
    *(short *)&wd->m_iId = (short)*piVar1;
    wd = (weapon_data_s *)((int)&wd->m_iId + 2);
  }
  if (((uint)wd & 4) != 0) {
    piVar1 = &pwd->m_iId;
    uVar3 = uVar3 - 4;
    pwd = (weapon_data_s *)&pwd->m_iClip;
    wd->m_iId = *piVar1;
    wd = (weapon_data_s *)&wd->m_iClip;
  }
  iVar2 = 0;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    wd->m_iId = pwd->m_iId;
    pwd = (weapon_data_s *)((int)pwd + (uint)bVar6 * -8 + 4);
    wd = (weapon_data_s *)((int)wd + (uint)bVar6 * -8 + 4);
  }
  if ((uVar3 & 2) != 0) {
    *(short *)&wd->m_iId = (short)pwd->m_iId;
    iVar2 = 2;
  }
  if (bVar5) {
    *(undefined1 *)((int)&wd->m_iId + iVar2) = *(undefined1 *)((int)&pwd->m_iId + iVar2);
  }
  return;
}


// HUD_UpdateClientData  @ 0008e550
int HUD_UpdateClientData(client_data_t *pcldata,float flTime)

{
  int iVar1;
  
  IN_Commands();
  iVar1 = CHud::UpdateClientData(&gHUD,pcldata,flTime);
  return iVar1;
}


// HUD_VidInit  @ 0008e5d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int HUD_VidInit(void)

{
  CHud::VidInit(&gHUD);
  VGui_Startup();
  return 1;
}


// HUD_VoiceStatus  @ 0008e4d0
void HUD_VoiceStatus(int entindex,qboolean bTalking)

{
  CVoiceStatus *this;
  
  this = GetClientVoiceMgr();
  CVoiceStatus::UpdateSpeakerStatus(this,entindex,bTalking);
  return;
}


// HUD_WeaponsPostThink  @ 000816e0
/* WARNING: Type propagation algorithm not settling */

void HUD_WeaponsPostThink
               (local_state_s *from,local_state_s *to,usercmd_t *cmd,double time,uint random_seed)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  CBasePlayerWeapon *pCVar6;
  CTFTranq *pCVar7;
  entvars_t *peVar8;
  uint uVar9;
  uint uVar10;
  cl_entity_s *pcVar11;
  uint uVar12;
  int iVar13;
  float fVar14;
  int iVar15;
  int *piVar16;
  undefined4 *puVar17;
  CBasePlayerItem *pCVar18;
  bool bVar19;
  CTFTranq *local_88;
  undefined4 local_74 [25];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int buttonsChanged@[???]
                       Unresolved local var: CBasePlayerWeapon * pWeapon@[???]
                       Unresolved local var: CBasePlayerWeapon * pCurrent@[???]
                       Unresolved local var: weapon_data_t nulldata@[???]
                       Unresolved local var: weapon_data_t * pfrom@[???]
                       Unresolved local var: weapon_data_t * pto@[???] */
  uVar10 = 0;
  do {
    uVar9 = uVar10;
    *(undefined4 *)((int)local_74 + uVar9) = 0;
    *(undefined4 *)((int)local_74 + uVar9 + 4) = 0;
    *(undefined4 *)((int)local_74 + uVar9 + 8) = 0;
    *(undefined4 *)((int)local_74 + uVar9 + 0xc) = 0;
    uVar10 = uVar9 + 0x10;
  } while (uVar9 + 0x10 < 0x50);
  *(undefined4 *)((int)local_74 + uVar9 + 0x10) = 0;
  *(undefined4 *)((int)local_74 + uVar9 + 0x14) = 0;
  HUD_InitClientWeapons();
  local_88 = (CTFTranq *)0x0;
  gpGlobals->time = (float)time;
  uVar10 = (from->client).m_iId - 3;
  if (uVar10 < 0x15) {
    local_88 = *(CTFTranq **)(CSWTCH_92 + uVar10 * 4);
  }
  g_finalstate = to;
  if (g_runfuncs != 0) {
    fVar14 = (to->client).health;
    if ((0.0 < fVar14) || (HUD_WeaponsPostThink::lexical_block_0::lasthealth < 1)) {
      if ((0.0 < fVar14) &&
         ((HUD_WeaponsPostThink::lexical_block_0::lasthealth < 1 &&
          (player.m_pActiveItem != (CBasePlayerItem *)0x0)))) {
        (*((player.m_pActiveItem)->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
          _vptr_CBaseEntity[0x47])(player.m_pActiveItem);
        fVar14 = (to->client).health;
      }
    }
    else {
                    /* Unresolved local var: cl_entity_t * pthisplayer@[???] */
      if (player.m_pActiveItem != (CBasePlayerItem *)0x0) {
        (*((player.m_pActiveItem)->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
          _vptr_CBaseEntity[0x49])(player.m_pActiveItem,0);
      }
      peVar8 = player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
                    /* Unresolved local var: int playerclass@[???]
                       Unresolved local var: float maxfbspeed@[???] */
      iVar15 = (player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->playerclass;
      if (((player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate & 0x10000U) == 0) && (iVar15 != 0)) {
        fVar14 = 400.0;
        if ((((iVar15 != 1) && (fVar14 = 300.0, iVar15 != 2)) && (fVar14 = 240.0, iVar15 != 3)) &&
           (((fVar14 = 280.0, iVar15 != 4 && (fVar14 = 320.0, iVar15 != 5)) &&
            ((fVar14 = 230.0, iVar15 != 6 &&
             ((fVar14 = 300.0, iVar15 != 7 && (fVar14 = 240.0, iVar15 != 0xb)))))))) {
          fVar14 = 300.0;
        }
        player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.tfstate =
             player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.tfstate & 0xfffff7ffU;
        (player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->maxspeed = fVar14;
      }
      else {
        player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.tfstate =
             player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.tfstate & 0xfffff7ffU;
        ((player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->velocity).x = g_vecZero.x;
        (peVar8->velocity).y = g_vecZero.y;
        (peVar8->velocity).z = g_vecZero.z;
        (*g_engfuncs.pfnSetClientMaxspeed)(peVar8->pContainingEntity,1.0);
        (player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->maxspeed = 1.0;
      }
      pcVar11 = (*gEngfuncs.GetLocalPlayer)();
      (*(gEngfuncs.pEventAPI)->EV_StopSound)(pcVar11->index,6,"weapons/timer.wav");
      fVar14 = (to->client).health;
    }
    HUD_WeaponsPostThink::lexical_block_0::lasthealth = (int)fVar14;
  }
  if (local_88 != (CTFTranq *)0x0) {
    iVar15 = 0;
    do {
      pCVar6 = g_pWpns[iVar15];
      if (pCVar6 != (CBasePlayerWeapon *)0x0) {
        pCVar6->m_flNextReload = from->weapondata[iVar15].m_flNextReload;
        pCVar6->m_fInReload = from->weapondata[iVar15].m_fInReload;
        pCVar6->m_fInSpecialReload = from->weapondata[iVar15].m_fInSpecialReload;
        pCVar6->m_flPumpTime = from->weapondata[iVar15].m_flPumpTime;
        pCVar6->m_iWeaponState = from->weapondata[iVar15].m_iWeaponState;
        pCVar6->m_fAimedDamage = from->weapondata[iVar15].m_fAimedDamage;
        pCVar6->m_fNextAimBonus = from->weapondata[iVar15].m_fNextAimBonus;
        pCVar6->m_fInZoom = from->weapondata[iVar15].m_fInZoom;
        pCVar6->m_iClip = from->weapondata[iVar15].m_iClip;
        pCVar6->m_flNextPrimaryAttack = from->weapondata[iVar15].m_flNextPrimaryAttack;
        pCVar6->m_flNextSecondaryAttack = from->weapondata[iVar15].m_flNextSecondaryAttack;
        pCVar6->m_flTimeWeaponIdle = from->weapondata[iVar15].m_flTimeWeaponIdle;
      }
      peVar8 = player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      iVar15 = iVar15 + 1;
    } while (iVar15 != 0x20);
    player.random_seed = random_seed;
    player.m_afButtonLast = (from->playerstate).oldbuttons;
    uVar10 = player.m_afButtonLast ^ (uint)cmd->buttons;
    player.m_afButtonPressed = cmd->buttons & uVar10;
    player.m_afButtonReleased = ~(uint)cmd->buttons & uVar10;
    (player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->playerclass = (from->playerstate).playerclass;
    peVar8->button = (uint)cmd->buttons;
    (peVar8->velocity).x = (from->client).velocity.x;
    (peVar8->velocity).y = (from->client).velocity.y;
    (peVar8->velocity).z = (from->client).velocity.z;
    peVar8->flags = (from->client).flags;
    peVar8->deadflag = (from->client).deadflag;
    peVar8->waterlevel = (from->client).waterlevel;
    peVar8->maxspeed = (from->client).maxspeed;
    player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = (from->client).tfstate;
    peVar8->fov = (from->client).fov;
    peVar8->weaponanim = (from->client).weaponanim;
    peVar8->viewmodel = (from->client).viewmodel;
    player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = (from->client).ammo_shells;
    player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = (from->client).ammo_nails;
    player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = (from->client).ammo_cells;
    player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = (from->client).ammo_rockets;
    player.super_CBaseMonster.m_flNextAttack = (from->client).m_flNextAttack;
    iVar15 = (from->client).m_iId;
    if (iVar15 != 0) {
      player.m_pActiveItem = &g_pWpns[iVar15]->super_CBasePlayerItem;
    }
    if ((((peVar8->deadflag != 5) && (iVar15 = CL_IsDead(), iVar15 == 0)) &&
        ((player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->viewmodel != 0)) &&
       ((g_iUser1 == 0 && (player.super_CBaseMonster.m_flNextAttack <= 0.0)))) {
      (*(local_88->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
        super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4c])(local_88);
    }
    (to->client).m_iId = (from->client).m_iId;
    if (((cmd->weaponselect != 0) &&
        ((player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->deadflag != 5)) &&
       ((uVar10 = (uint)cmd->weaponselect, uVar10 == from->weapondata[uVar10].m_iId &&
        ((pCVar7 = (CTFTranq *)g_pWpns[uVar10], pCVar7 != local_88 && (pCVar7 != (CTFTranq *)0x0))))
       )) {
      pCVar18 = (CBasePlayerItem *)0x0;
      if (player.m_pActiveItem != (CBasePlayerItem *)0x0) {
        (*((player.m_pActiveItem)->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
          _vptr_CBaseEntity[0x49])(player.m_pActiveItem,0);
        pCVar18 = player.m_pActiveItem;
      }
      player.m_pActiveItem = (CBasePlayerItem *)pCVar7;
      player.m_pLastItem = pCVar18;
      (*(pCVar7->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
        super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x47])(pCVar7);
      (to->client).m_iId = (uint)cmd->weaponselect;
    }
                    /* Unresolved local var: CBasePlayerWeapon * pNew@[???] */
                    /* Unresolved local var: int i@[???] */
    g_laserdot.previousorigin.x =
         (g_finalstate->playerstate).origin.x + (g_finalstate->client).view_ofs.x;
    g_laserdot.previousorigin.y =
         (g_finalstate->playerstate).origin.y + (g_finalstate->client).view_ofs.y;
    g_laserdot.previousorigin.z =
         (g_finalstate->playerstate).origin.z + (g_finalstate->client).view_ofs.z;
    g_finalstate = (local_state_s *)0x0;
    if (g_runfuncs != 0) {
      g_laserdot.laserdotactive = 0;
      g_laserdot.laserdotintensity = 0;
      if ((to->client).m_iId == 6) {
        if (((((g_Spot.super_CBaseEntity.pev)->effects & 0x80) == 0) &&
            (iVar15 = CL_IsDead(), iVar15 == 0)) && ((cmd->buttons & 1) != 0)) {
          g_laserdot.laserdotactive = 1;
          g_laserdot.laserdotintensity =
               (int)((local_88->super_CBasePlayerWeapon).m_fAimedDamage * 0.25 + 150.0);
        }
        else {
          g_laserdot.laserdotactive = 0;
        }
      }
    }
    peVar8 = player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    bVar19 = g_runfuncs != 0;
    (to->playerstate).playerclass =
         (player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->playerclass;
    (to->client).viewmodel = peVar8->viewmodel;
    (to->client).fov = peVar8->fov;
    (to->client).weaponanim = peVar8->weaponanim;
    (to->client).ammo_shells =
         player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.ammo_shells;
    (to->client).ammo_nails =
         player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.ammo_nails;
    (to->client).ammo_cells =
         player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.ammo_cells;
    (to->client).ammo_rockets =
         player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.ammo_rockets;
    (to->client).m_flNextAttack = player.super_CBaseMonster.m_flNextAttack;
    (to->client).tfstate =
         player.super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.tfstate;
    (to->client).maxspeed = peVar8->maxspeed;
    if (bVar19) {
      iVar13 = HUD_GetWeaponAnim();
      iVar15 = (to->client).weaponanim;
      if (iVar13 != iVar15) {
        HUD_SendWeaponAnim(iVar15,(local_88 != &g_Tranq) + 1,1);
      }
    }
                    /* Unresolved local var: int body@[???] */
    iVar15 = 0;
    do {
      while( true ) {
        pCVar6 = g_pWpns[iVar15];
        piVar16 = &to->weapondata[iVar15].m_iId;
        if (pCVar6 == (CBasePlayerWeapon *)0x0) break;
        fVar14 = pCVar6->m_flNextReload;
        piVar16[7] = (int)fVar14;
        piVar16[5] = pCVar6->m_fInReload;
        piVar16[6] = pCVar6->m_fInSpecialReload;
        fVar1 = pCVar6->m_flPumpTime;
        piVar16[8] = (int)fVar1;
        piVar16[0xd] = pCVar6->m_iWeaponState;
        piVar16[10] = (int)pCVar6->m_fAimedDamage;
        fVar2 = pCVar6->m_fNextAimBonus;
        piVar16[0xb] = (int)fVar2;
        piVar16[0xc] = pCVar6->m_fInZoom;
        piVar16[1] = pCVar6->m_iClip;
        fVar3 = pCVar6->m_flNextPrimaryAttack;
        piVar16[2] = (int)fVar3;
        fVar4 = pCVar6->m_flNextSecondaryAttack;
        piVar16[3] = (int)fVar4;
        fVar5 = pCVar6->m_flTimeWeaponIdle;
        piVar16[4] = (int)fVar5;
        fVar14 = fVar14 - (float)cmd->msec / 1000.0;
        piVar16[7] = (int)fVar14;
        fVar2 = fVar2 - (float)cmd->msec / 1000.0;
        piVar16[0xb] = (int)fVar2;
        fVar3 = fVar3 - (float)cmd->msec / 1000.0;
        piVar16[2] = (int)fVar3;
        fVar4 = fVar4 - (float)cmd->msec / 1000.0;
        piVar16[3] = (int)fVar4;
        fVar5 = fVar5 - (float)cmd->msec / 1000.0;
        piVar16[4] = (int)fVar5;
        if ((fVar1 != -9999.0) &&
           (fVar1 = fVar1 - (float)cmd->msec / 1000.0, piVar16[8] = (int)fVar1, fVar1 < -0.001)) {
          piVar16[8] = -0x457ced91;
        }
        if (fVar2 < -1.0) {
          piVar16[0xb] = -0x40800000;
        }
        if (fVar3 < -1.0) {
          piVar16[2] = -0x40800000;
        }
        if (fVar4 < -0.001) {
          piVar16[3] = -0x457ced91;
        }
        if (fVar5 < -0.001) {
          piVar16[4] = -0x457ced91;
        }
        if (fVar14 < -0.001) {
          piVar16[7] = -0x457ced91;
        }
LAB_00081d7b:
        iVar15 = iVar15 + 1;
        if (iVar15 == 0x20) goto LAB_00081e30;
      }
      bVar19 = ((uint)piVar16 & 1) != 0;
      uVar10 = 0x58;
      if (bVar19) {
        *(undefined1 *)piVar16 = 0;
        piVar16 = (int *)((int)piVar16 + 1);
        uVar10 = 0x57;
      }
      if (((uint)piVar16 & 2) != 0) {
        *(undefined2 *)piVar16 = 0;
        uVar10 = uVar10 - 2;
        piVar16 = (int *)((int)piVar16 + 2);
      }
      uVar9 = 0;
      do {
        uVar12 = uVar9;
        *(undefined4 *)((int)piVar16 + uVar12) = 0;
        *(undefined4 *)((int)piVar16 + uVar12 + 4) = 0;
        *(undefined4 *)((int)piVar16 + uVar12 + 8) = 0;
        *(undefined4 *)((int)piVar16 + uVar12 + 0xc) = 0;
        uVar9 = uVar12 + 0x10;
      } while (uVar12 + 0x10 < (uVar10 & 0xfffffff0));
      puVar17 = (undefined4 *)((int)piVar16 + uVar12 + 0x10);
      if ((uVar10 & 8) != 0) {
        *puVar17 = 0;
        puVar17[1] = 0;
        puVar17 = puVar17 + 2;
      }
      if ((uVar10 & 4) != 0) {
        *puVar17 = 0;
        puVar17 = (undefined4 *)((int)puVar17 + 4);
      }
      if ((uVar10 & 2) != 0) {
        *(undefined2 *)puVar17 = 0;
        puVar17 = (undefined4 *)((int)puVar17 + 2);
      }
      if (!bVar19) goto LAB_00081d7b;
      iVar15 = iVar15 + 1;
      *(undefined1 *)puVar17 = 0;
    } while (iVar15 != 0x20);
LAB_00081e30:
    fVar14 = (to->client).m_flNextAttack - (float)cmd->msec / 1000.0;
    (to->client).m_flNextAttack = fVar14;
    if (fVar14 < -0.001) {
      (to->client).m_flNextAttack = -0.001;
    }
  }
  return;
}


