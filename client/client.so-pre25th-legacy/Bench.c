// Bench_Active  @ 00092130
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Bench_Active(void)

{
  return (uint)(g_currentstage != 0);
}


// Bench_AddObjects  @ 00093ec0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Bench_AddObjects(void)

{
  Vector *veca;
  float fVar1;
  float fVar2;
  vec_t vVar3;
  undefined4 uVar4;
  Vector origin;
  float fVar5;
  float fVar6;
  vec_t vVar7;
  uint uVar8;
  cl_entity_s *pcVar9;
  float *pfVar10;
  uint uVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  float fVar15;
  char *in_stack_fffffe74;
  char *__x;
  undefined4 in_stack_fffffe78;
  vec_t in_stack_fffffe7c;
  double local_114;
  double local_10c;
  float local_100;
  pmtrace_s local_f0;
  vec_t local_ac;
  vec_t local_a8;
  vec_t local_a4;
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
  vec_t local_34;
  vec_t local_30;
  float local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
  if (g_renderedBenchmarkDot != 0) {
                    /* Unresolved local var: Vector delta@[???] */
    __x = (char *)((g_aimorg.z - g_dotorg.z) * (g_aimorg.z - g_dotorg.z) +
                  (g_aimorg.y - g_dotorg.y) * (g_aimorg.y - g_dotorg.y) +
                  (g_aimorg.x - g_dotorg.x) * (g_aimorg.x - g_dotorg.x));
    fVar15 = SQRT((float)__x);
    if (NAN(fVar15)) {
      fVar15 = sqrtf((float)__x);
      in_stack_fffffe74 = __x;
    }
    if (gHUD.m_Benchmark.m_nSentFinish == 0) {
      gHUD.m_Benchmark.m_fDrawTime = gHUD.m_flTime + 10.0;
      gHUD.m_Benchmark.m_fAvgScore = gHUD.m_Benchmark.m_fAvgScore * 0.9 + fVar15 * 0.1;
      gHUD.m_Benchmark.m_fDrawScore = fVar15;
    }
  }
  if (g_currentstage != 2) {
    g_renderedBenchmarkDot = 0;
    return;
  }
  g_renderedBenchmarkDot = 0;
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
  local_ac = v_origin.x;
  local_a8 = v_origin.y;
  local_a4 = v_origin.z;
  if (HUD_CreateBenchObjects(Vector)::bench == '\0') {
    in_stack_fffffe74 = &HUD_CreateBenchObjects(Vector)::bench;
    iVar14 = __cxa_guard_acquire();
    if (iVar14 != 0) {
      in_stack_fffffe74 = &HUD_CreateBenchObjects(Vector)::bench;
      __cxa_guard_release();
    }
  }
  if (gHUD.m_flTime == HUD_CreateBenchObjects::lexical_block_0::last_time) {
    return;
  }
  fVar15 = gHUD.m_flTime - HUD_CreateBenchObjects::lexical_block_0::last_time;
  HUD_CreateBenchObjects::lexical_block_0::last_time = gHUD.m_flTime;
  if (fVar15 <= 0.0) {
    HUD_CreateBenchObjects::lexical_block_0::last_time = gHUD.m_flTime;
    return;
  }
  if (HUD_CreateBenchObjects::lexical_block_0::failed != 0) {
    HUD_CreateBenchObjects::lexical_block_0::last_time = gHUD.m_flTime;
    return;
  }
  pcVar9 = (*gEngfuncs.GetLocalPlayer)();
  if (pcVar9 == (cl_entity_s *)0x0) {
LAB_00094703:
    HUD_CreateBenchObjects::lexical_block_0::failed = 1;
  }
  else {
    if (HUD_CreateBenchObjects::lexical_block_0::first != 0) {
      HUD_CreateBenchObjects::lexical_block_0::first = 0;
      local_28 = local_ac;
      local_24 = local_a8;
      local_20 = local_a4;
      origin.y = (vec_t)in_stack_fffffe78;
      origin.x = (vec_t)in_stack_fffffe74;
      origin.z = in_stack_fffffe7c;
      iVar14 = HUD_SetupBenchObjects
                         ((cl_entity_t_conflict *)(pcVar9->index + -1),(int)&local_28,origin);
      if (iVar14 == 0) goto LAB_00094703;
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
      piVar13 = &HUD_CreateBenchObjects::lexical_block_0::bench[0].curstate.rendermode;
      (*gEngfuncs.pfnAngleVectors)(&vec3_origin.x,&local_64,local_58,local_4c);
      local_34 = local_ac;
      local_30 = local_a8;
      local_2c = local_a4 - 512.0;
      (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_ac,&local_34,0,-1,&local_f0);
      local_34 = local_64 * 250.0 + local_f0.endpos.x;
      local_30 = local_60 * 250.0 + local_f0.endpos.y;
      local_2c = local_5c * 250.0 + local_f0.endpos.z + 72.0;
      iVar14 = 0;
      do {
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: float jitter@[???]
                       Unresolved local var: float jfrac@[???]
                       Unresolved local var: float offset@[???]
                       Unresolved local var: Vector ang@[???]
                       Unresolved local var: float ofs_radius@[???] */
        pfVar10 = local_8c;
        local_9c = 0.0;
        local_94 = 0;
        local_8c[0] = 0.0;
        local_8c[2] = 0.0;
        fVar2 = ((float)iVar14 / 11.0) * 360.0;
        local_100 = fVar6 * 360.0 + fVar2;
        local_8c[1] = local_100;
        do {
                    /* Unresolved local var: int i@[???] */
          fVar1 = *pfVar10;
          if (fVar1 < -180.0) {
            do {
              fVar1 = fVar1 + 360.0;
            } while (fVar1 < -180.0);
            *pfVar10 = fVar1;
          }
          if (180.0 < fVar1) {
            do {
              fVar1 = fVar1 - 360.0;
            } while (180.0 < fVar1);
            *pfVar10 = fVar1;
          }
          pfVar10 = pfVar10 + 1;
        } while (pfVar10 != local_8c + 3);
        local_98 = local_100;
        (*gEngfuncs.pfnAngleVectors)(&local_9c,&local_64,local_58,local_4c);
        sincos((double)fVar2 + (double)(fVar5 + fVar5) * 3.141592653589793,&local_10c,&local_114);
        local_100 = (float)local_10c * 5.0 + 80.0;
        local_3c = local_60 * local_100 + local_30;
        local_40 = local_100 * local_64 + local_34;
        local_38 = (float)local_114 * 10.0 + local_5c * local_100 + local_2c;
        (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_34,&local_40,0,-1,&local_f0);
        veca = &HUD_CreateBenchObjects::lexical_block_0::bench[iVar14].curstate.angles;
        VectorMA(&veca->x,fVar15,
                 &HUD_CreateBenchObjects::lexical_block_0::bench[iVar14].baseline.angles.x,&veca->x)
        ;
        vVar3 = local_f0.endpos.x;
                    /* Unresolved local var: int i@[???] */
        local_7c[0] = HUD_CreateBenchObjects::lexical_block_0::bench[iVar14].curstate.angles.x;
        local_7c[1] = HUD_CreateBenchObjects::lexical_block_0::bench[iVar14].curstate.angles.y;
        local_7c[2] = HUD_CreateBenchObjects::lexical_block_0::bench[iVar14].curstate.angles.z;
        pfVar10 = local_7c;
        do {
          fVar2 = *pfVar10;
          if (fVar2 < -180.0) {
            do {
              fVar2 = fVar2 + 360.0;
            } while (fVar2 < -180.0);
            *pfVar10 = fVar2;
          }
          if (180.0 < fVar2) {
            do {
              fVar2 = fVar2 - 360.0;
            } while (180.0 < fVar2);
            *pfVar10 = fVar2;
          }
          pfVar10 = pfVar10 + 1;
        } while (pfVar10 != local_70);
        if (iVar14 == 0xb) {
          g_aimorg.x = local_f0.endpos.x;
          g_aimorg.y = local_f0.endpos.y;
          g_aimorg.z = local_f0.endpos.z;
        }
        fVar2 = 0.5;
        if (g_isPowerPlay == 0) {
          fVar2 = 8.0;
        }
        fVar2 = fVar2 * ((float)gHUD.m_Benchmark.m_nObjects / 12.0);
        (*gEngfuncs.pfnRandomFloat)(-fVar2,fVar2);
        vVar7 = local_f0.endpos.y;
        local_f0.endpos.x = (vec_t)(extraout_ST0 + (longdouble)vVar3);
        (*gEngfuncs.pfnRandomFloat)(-fVar2,fVar2);
        piVar13[0x216] = (int)local_f0.endpos.z;
        piVar13[-0xc] = (int)local_f0.endpos.z;
        vVar3 = ((Vector *)(piVar13 + -0xb))->x;
        piVar13[0x214] = (int)local_f0.endpos.x;
        ((Vector *)(piVar13 + -0xe))->x = local_f0.endpos.x;
        piVar13[0x217] = (int)vVar3;
        local_f0.endpos.y = (vec_t)(extraout_ST0_00 + (longdouble)vVar7);
        piVar13[0x218] = piVar13[-10];
        piVar13[0x215] = (int)local_f0.endpos.y;
        piVar13[-0xd] = (int)local_f0.endpos.y;
        piVar13[0x219] = piVar13[-9];
        uVar8 = 0;
        do {
          uVar11 = uVar8;
          uVar4 = *(undefined4 *)((int)piVar13 + (uVar11 - 0x48));
          *(undefined4 *)((int)piVar13 + (uVar11 - 0x198)) =
               *(undefined4 *)((int)piVar13 + (uVar11 - 0x44));
          *(undefined4 *)((int)piVar13 + (uVar11 - 0x19c)) = uVar4;
          uVar8 = uVar11 + 8;
        } while (uVar11 + 8 < 0x150);
        *(undefined4 *)((int)piVar13 + (uVar11 - 0x194)) =
             *(undefined4 *)((int)piVar13 + (uVar11 - 0x40));
        if (0xb - iVar14 < gHUD.m_Benchmark.m_nObjects) {
          if (piVar13[1] == 0xff) {
            *piVar13 = 0;
          }
          else {
            iVar12 = (int)(fVar15 * 150.0 + (float)piVar13[1]);
            if (0xff < iVar12) {
              iVar12 = 0xff;
            }
            piVar13[1] = iVar12;
            *piVar13 = 4;
          }
          (*gEngfuncs.CL_CreateVisibleEntity)
                    (0,(cl_entity_s *)(HUD_CreateBenchObjects::lexical_block_0::bench + iVar14));
        }
        iVar14 = iVar14 + 1;
        piVar13 = piVar13 + 0x2ee;
      } while (iVar14 != 0xc);
      (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
    }
  }
  return;
}


// Bench_CheckEntity  @ 00092fc0
void Bench_CheckEntity(int type,cl_entity_s_conflict *ent,char *modelname)

{
  model_s_conflict *pmVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  char *pcVar5;
  float fVar6;
  float fVar7;
  longdouble lVar8;
  longdouble lVar9;
  float local_18;
  float local_14;
  float local_10;
  
  if (g_currentstage == 3) {
    iVar4 = strcasecmp(modelname,"*3");
    if (iVar4 == 0) {
                    /* Unresolved local var: model_t.conflict * pmod@[???]
                       Unresolved local var: Vector v@[???] */
      pmVar1 = ent->model;
      local_18 = (pmVar1->mins).x + (pmVar1->maxs).x;
      local_14 = (pmVar1->mins).y + (pmVar1->maxs).y;
      local_10 = (pmVar1->mins).z + (pmVar1->maxs).z;
      VectorScale(&local_18,0.5,&local_18);
      g_aimorg.x = local_18 + (ent->origin).x;
      g_aimorg.y = local_14 + (ent->origin).y;
      g_aimorg.z = local_10 + (ent->origin).z;
      if (g_currentstage != 3) {
        return;
      }
    }
    pcVar5 = strstr(modelname,"ppdemodot");
    if (pcVar5 != (char *)0x0) {
      g_dotorg.x = (ent->origin).x;
      g_renderedBenchmarkDot = 1;
      g_dotorg.y = (ent->origin).y;
      g_dotorg.z = (ent->origin).z;
                    /* Unresolved local var: float dt@[???]
                       Unresolved local var: float fRate@[DW_OP_reg2(EDX)]
                       Unresolved local var: float fBounds@[???] */
      if (g_isPowerPlay == 0) {
        fVar2 = -15.0;
        fVar6 = -8.0;
        fVar7 = 8.0;
        fVar3 = 15.0;
      }
      else {
        fVar6 = -4.0;
        fVar7 = 4.0;
        fVar2 = -8.0;
        fVar3 = 8.0;
      }
      if ((0.0 < gHUD.m_flTime - Bench_CheckEntity::lexical_block_4::fLastTime) &&
         (gHUD.m_flTime - Bench_CheckEntity::lexical_block_4::fLastTime < 1.0)) {
        lVar8 = (longdouble)(*gEngfuncs.pfnRandomFloat)(fVar6,fVar7);
        lVar8 = lVar8 + (longdouble)Bench_CheckEntity::lexical_block_4::fZAdjust;
        lVar9 = (longdouble)fVar3;
        if ((lVar8 <= lVar9) && (lVar9 = (longdouble)fVar2, (longdouble)fVar2 <= lVar8)) {
          lVar9 = lVar8;
        }
        Bench_CheckEntity::lexical_block_4::fZAdjust = (float)lVar9;
        (ent->origin).z = (float)((longdouble)(ent->origin).z + lVar9);
        g_fZAdjust = (float)lVar9;
      }
      Bench_CheckEntity::lexical_block_4::fLastTime = gHUD.m_flTime;
      return;
    }
  }
  return;
}


// Bench_CheckStart  @ 00092460
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Bench_CheckStart(void)

{
  char *__s1;
  int iVar1;
  
                    /* Unresolved local var: char * level@[???] */
  if ((((started == 0) && (g_currentstage == 0)) &&
      (__s1 = (*gEngfuncs.pfnGetLevelName)(), __s1 != (char *)0x0)) &&
     ((*__s1 != '\0' && (iVar1 = strcasecmp(__s1,"maps/ppdemo.bsp"), iVar1 == 0)))) {
    started = 1;
    (*gEngfuncs.pfnClientCmd)("ppdemostart\n");
  }
  return;
}


// Bench_GetDotAdded  @ 00092f20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Bench_GetDotAdded(void)

{
  return g_renderedBenchmarkDot;
}


// Bench_GetPowerPlay  @ 00092120
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Bench_GetPowerPlay(void)

{
  return g_isPowerPlay;
}


// Bench_GetStage  @ 000920c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Bench_GetStage(void)

{
  return g_currentstage;
}


// Bench_GetSwitchTime  @ 000920d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float Bench_GetSwitchTime(void)

{
  int iVar1;
  
  iVar1 = g_currentstage;
  if (3 < g_currentstage) {
    iVar1 = 4;
  }
  return g_benchSwitchTimes[iVar1];
}


// Bench_InStage  @ 000920f0
int Bench_InStage(int stage)

{
  return (uint)(stage == g_currentstage);
}


// Bench_SetDotAdded  @ 00092f10
void Bench_SetDotAdded(int dot)

{
  g_renderedBenchmarkDot = dot;
  return;
}


// Bench_SetPowerPlay  @ 00092100
void Bench_SetPowerPlay(int set)

{
  g_isPowerPlay = (uint)(set != 0);
  return;
}


// Bench_SetStage  @ 000920b0
void Bench_SetStage(int stage)

{
  g_currentstage = stage;
  return;
}


// Bench_SetViewAngles  @ 00094760
void Bench_SetViewAngles(int recalc_wander,float *viewangles,float frametime,usercmd_s *cmd)

{
  float fVar1;
  float fVar2;
  float fVar3;
  vec_t vVar4;
  vec_t vVar5;
  float local_18;
  float local_14;
  float local_10;
  
  vVar5 = vec3_origin.z;
  vVar4 = vec3_origin.x;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector lookdir@[???] */
  if (g_currentstage != 0) {
    if (g_currentstage == 1) {
      v_stochastic.y = vec3_origin.y;
      *viewangles = vec3_origin.x;
      v_stochastic.x = vVar4;
      v_stochastic.z = vVar5;
      viewangles[1] = vec3_origin.y;
      vVar4 = vec3_origin.z;
      viewangles[1] = -90.0;
      viewangles[2] = vVar4;
    }
    else if ((g_currentstage == 2) || (g_currentstage == 3)) {
      local_18 = g_aimorg.x - v_origin.x;
      local_14 = g_aimorg.y - v_origin.y;
      local_10 = g_aimorg.z - v_origin.z;
      VectorNormalize(&local_18);
      VectorAngles(&local_18,viewangles);
      fVar1 = v_stochastic.x - *viewangles;
      *viewangles = fVar1;
      fVar2 = viewangles[1] + v_stochastic.y;
      viewangles[1] = fVar2;
      fVar3 = viewangles[2] + v_stochastic.z;
      viewangles[2] = fVar3;
      if (180.0 < fVar1) {
        fVar1 = fVar1 - 360.0;
        *viewangles = fVar1;
      }
      if (fVar1 < -180.0) {
        *viewangles = fVar1 + 360.0;
      }
      if (180.0 < fVar2) {
        fVar2 = fVar2 - 360.0;
        viewangles[1] = fVar2;
      }
      if (fVar2 < -180.0) {
        viewangles[1] = fVar2 + 360.0;
      }
      if (180.0 < fVar3) {
        fVar3 = fVar3 - 360.0;
        viewangles[2] = fVar3;
      }
      if (fVar3 < -180.0) {
        viewangles[2] = fVar3 + 360.0;
      }
    }
    else {
      *viewangles = vec3_origin.x;
      viewangles[1] = vec3_origin.y;
      viewangles[2] = vec3_origin.z;
    }
    if (cmd != (usercmd_s *)0x0) {
      cmd->buttons = (ushort)(g_currentstage == 3);
    }
  }
  return;
}


// Bench_SetViewOrigin  @ 00094950
void Bench_SetViewOrigin(float *vieworigin,float frametime)

{
  float fVar1;
  double dVar2;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: float dt@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: float offset_amt@[???]
                       Unresolved local var: float drift@[???]
                       Unresolved local var: Vector ang@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector move@[???] */
  if ((g_currentstage == 2) && (0.0 <= gHUD.m_flTime - g_flStartTime)) {
    dVar2 = sin((double)(((gHUD.m_flTime - g_flStartTime) / 7.1) * 6.2831855));
    local_24 = vec3_origin.x;
    fVar1 = (float)dVar2 * 60.0;
    local_20 = vec3_origin.y;
    local_1c = vec3_origin.z;
    (*gEngfuncs.pfnAngleVectors)(&local_24,(float *)0x0,&local_18,(float *)0x0);
    *vieworigin = fVar1 * local_18 + *vieworigin;
    vieworigin[1] = local_14 * fVar1 + vieworigin[1];
    vieworigin[2] = local_10 * fVar1 + vieworigin[2];
    return;
  }
  return;
}


// Bench_SpotPosition  @ 00092f30
void Bench_SpotPosition(Vector dot,Vector target)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: Vector delta@[???] */
  fVar2 = *(float *)((int)dot.y + 4) - *(float *)((int)dot.x + 4);
  fVar1 = *(float *)((int)dot.y + 8) - *(float *)((int)dot.x + 8);
  fVar1 = fVar1 * fVar1 +
          fVar2 * fVar2 + (*(float *)dot.y - *(float *)dot.x) * (*(float *)dot.y - *(float *)dot.x);
  fVar2 = SQRT(fVar1);
  if (NAN(fVar2)) {
    fVar2 = sqrtf(fVar1);
  }
  if (gHUD.m_Benchmark.m_nSentFinish == 0) {
    gHUD.m_Benchmark.m_fDrawTime = gHUD.m_flTime + 10.0;
    gHUD.m_Benchmark.m_fAvgScore = gHUD.m_Benchmark.m_fAvgScore * 0.9 + fVar2 * 0.1;
    gHUD.m_Benchmark.m_fDrawScore = fVar2;
  }
  return;
}


