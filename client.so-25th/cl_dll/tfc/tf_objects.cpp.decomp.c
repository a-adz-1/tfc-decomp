// Ghidra decompilation of functions from cl_dll/tfc/tf_objects.cpp
// 2 functions, ordered by original source line

// HUD_CreateSniperDot  @ 0005a880  (line 25)

int HUD_CreateSniperDot(int damage,Vector viewangles,Vector origin,float *dotorigin)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  pfnEngSrc_CL_LoadModel_t p_Var4;
  uint uVar5;
  float fVar6;
  char *pcVar7;
  cl_entity_s *pcVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  cl_entity_t *pcVar12;
  byte bVar13;
  longdouble extraout_ST0;
  longdouble lVar14;
  float local_9c;
  float local_98;
  int local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74 [3];
  float local_68 [3];
  float local_5c;
  float local_58;
  float local_54;
  pmtrace_s local_50;
  
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
  bVar13 = 0;
  if ((HUD_CreateSniperDot(int,Vector,Vector,float*)::dot == '\0') &&
     (iVar11 = __cxa_guard_acquire(&HUD_CreateSniperDot(int,Vector,Vector,float*)::dot), iVar11 != 0
     )) {
    __cxa_guard_release(&HUD_CreateSniperDot(int,Vector,Vector,float*)::dot);
  }
  p_Var4 = gEngfuncs.CL_LoadModel;
  pcVar12 = &HUD_CreateSniperDot::dot;
  for (iVar11 = 0x2ee; iVar11 != 0; iVar11 = iVar11 + -1) {
    pcVar12->index = 0;
    pcVar12 = (cl_entity_t *)((int)pcVar12 + ((uint)bVar13 * -2 + 1) * 4);
  }
  iVar11 = Bench_Active();
  pcVar7 = "sprites/laserdot.spr";
  if (iVar11 != 0) {
    pcVar7 = "sprites/ppdemodot.spr";
  }
  HUD_CreateSniperDot::dot.model = (*p_Var4)(pcVar7,&local_84);
  if ((HUD_CreateSniperDot::dot.model != (model_s *)0x0) &&
     (pcVar8 = (*gEngfuncs.GetLocalPlayer)(), pcVar8 != (cl_entity_s *)0x0)) {
    HUD_CreateSniperDot::dot.curstate.movetype = 0;
    HUD_CreateSniperDot::dot.curstate.solid = 0;
    HUD_CreateSniperDot::dot.curstate.modelindex = local_84;
    HUD_CreateSniperDot::dot.curstate.rendermode = 3;
    HUD_CreateSniperDot::dot.curstate.renderfx = 0xe;
    HUD_CreateSniperDot::dot.curstate.renderamt = damage;
    (*gEngfuncs.pfnAngleVectors)((float *)viewangles.x,&local_80,local_74,local_68);
    local_54 = local_78 * 8192.0 + *(float *)((int)viewangles.y + 8);
    local_58 = local_7c * 8192.0 + *(float *)((int)viewangles.y + 4);
    local_5c = local_80 * 8192.0 + *(float *)viewangles.y;
    (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
    (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
    (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(pcVar8->index + -1);
    (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
    (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)((float *)viewangles.y,&local_5c,2,-1,&local_50);
                    /* Unresolved local var: int inwater1@[???]
                       Unresolved local var: int inwater2@[DW_OP_breg6(ESI): 0; DW_OP_const1s: -3;
                       DW_OP_eq; DW_OP_const1u: 255; DW_OP_and; DW_OP_stack_value] */
    if ((local_50.fraction == 1.0) ||
       ((iVar11 = (*gEngfuncs.PM_PointContents)(&local_50.endpos.x,(int *)0x0), iVar11 == -6 ||
        (iVar9 = (*gEngfuncs.PM_PointContents)((float *)viewangles.y,(int *)0x0),
        (iVar9 == -3) != (iVar11 == -3))))) {
      iVar11 = 0;
    }
    else {
      iVar11 = Bench_Active();
      fVar6 = HUD_CreateSniperDot::lexical_block_2::lexical_block_2_0::fLastTime;
      if ((iVar11 != 0) &&
         (iVar11 = Bench_InStage(3),
         fVar6 = HUD_CreateSniperDot::lexical_block_2::lexical_block_2_0::fLastTime, iVar11 != 0)) {
                    /* Unresolved local var: float g_fZAdjust@[???]
                       Unresolved local var: float dt@[???]
                       Unresolved local var: float fRate@[???]
                       Unresolved local var: float fBounds@[???] */
        iVar11 = Bench_GetPowerPlay();
        if (iVar11 == 0) {
          local_98 = -8.0;
          local_9c = 8.0;
        }
        else {
          local_98 = -4.0;
          local_9c = 4.0;
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
                   HUD_CreateSniperDot::lexical_block_2::lexical_block_2_0::fLastTime) &&
           (fVar6 = gHUD.m_flTime,
           gHUD.m_flTime - HUD_CreateSniperDot::lexical_block_2::lexical_block_2_0::fLastTime < 1.0)
           ) {
          (*gEngfuncs.pfnRandomFloat)(local_98,local_9c);
          lVar14 = (longdouble)fVar3;
          if (extraout_ST0 +
              (longdouble)HUD_CreateSniperDot::lexical_block_2::lexical_block_2_0::fZAdjust <
              (longdouble)fVar3) {
            lVar14 = extraout_ST0 +
                     (longdouble)HUD_CreateSniperDot::lexical_block_2::lexical_block_2_0::fZAdjust;
          }
          if (lVar14 <= (longdouble)fVar2) {
            lVar14 = (longdouble)fVar2;
          }
          HUD_CreateSniperDot::lexical_block_2::lexical_block_2_0::fZAdjust = (float)lVar14;
          local_50.endpos.z = (vec_t)((longdouble)local_50.endpos.z + lVar14);
          g_fZAdjust = (float)lVar14;
          fVar6 = gHUD.m_flTime;
        }
      }
      HUD_CreateSniperDot::lexical_block_2::lexical_block_2_0::fLastTime = fVar6;
      HUD_CreateSniperDot::dot.origin.z = local_50.endpos.z;
      HUD_CreateSniperDot::dot.curstate.origin.z = local_50.endpos.z;
      HUD_CreateSniperDot::dot.origin.x = local_50.endpos.x;
      HUD_CreateSniperDot::dot.origin.y = local_50.endpos.y;
      HUD_CreateSniperDot::dot.curstate.origin.x = local_50.endpos.x;
      HUD_CreateSniperDot::dot.curstate.origin.y = local_50.endpos.y;
      uVar5 = 0;
      do {
        uVar10 = uVar5;
        uVar1 = *(undefined4 *)(HUD_CreateSniperDot::dot.curstate.controller + (uVar10 - 100));
        *(undefined4 *)(HUD_CreateSniperDot::dot.prevstate.controller + (uVar10 - 0x68)) =
             *(undefined4 *)(HUD_CreateSniperDot::dot.curstate.controller + (uVar10 - 0x68));
        *(undefined4 *)(HUD_CreateSniperDot::dot.prevstate.controller + (uVar10 - 100)) = uVar1;
        uVar5 = uVar10 + 8;
      } while (uVar10 + 8 < 0x150);
      iVar11 = 1;
      *(undefined4 *)(HUD_CreateSniperDot::dot.prevstate.controller + (uVar10 - 0x60)) =
           *(undefined4 *)(HUD_CreateSniperDot::dot.curstate.controller + (uVar10 - 0x60));
      (*gEngfuncs.CL_CreateVisibleEntity)(0,&HUD_CreateSniperDot::dot);
      *(vec_t *)viewangles.z = HUD_CreateSniperDot::dot.origin.x;
      *(vec_t *)((int)viewangles.z + 4) = HUD_CreateSniperDot::dot.origin.y;
      *(vec_t *)((int)viewangles.z + 8) = HUD_CreateSniperDot::dot.origin.z;
    }
    (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
    return iVar11;
  }
  return 0;
}


// Game_AddObjects  @ 0005ac70  (line 135)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Game_AddObjects(void)

{
  Vector dot;
  Vector viewangles;
  Vector viewangles_00;
  Vector target;
  Vector origin;
  Vector origin_00;
  char *__nptr;
  long lVar1;
  cl_entity_s *pcVar2;
  int iVar3;
  vec_t damage;
  int in_GS_OFFSET;
  float *pfVar4;
  float **ppfVar5;
  undefined8 in_stack_ffffff44;
  vec_t in_stack_ffffff4c;
  float *in_stack_ffffff50;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float *local_98;
  float local_94;
  float local_90;
  float *local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  uchar local_74 [20];
  float local_60;
  float local_5c;
  float local_58;
  int local_10;
  
                    /* Unresolved local var: cl_entity_t * player@[???]
                       Unresolved local var: int damage@[???]
                       Unresolved local var: int tfc@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __nptr = (*gEngfuncs.PhysInfo_ValueForKey)("tfc");
  lVar1 = strtol(__nptr,(char **)0x0,10);
  pcVar2 = (*gEngfuncs.GetLocalPlayer)();
  if (((lVar1 != 0) && (pcVar2 != (cl_entity_s *)0x0)) &&
     (((pcVar2->curstate).playerclass == 2 || (iVar3 = Bench_InStage(3), iVar3 != 0)))) {
    iVar3 = HUD_NeedSpot((int *)&stack0xffffff4c);
    if (iVar3 == 0) {
      iVar3 = (*(gEngfuncs.pDemoAPI)->IsRecording)();
      if (iVar3 != 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uchar[100] buf@[???] */
        local_74[0] = '\0';
        local_74[1] = '\0';
        local_74[2] = '\0';
        local_74[3] = '\0';
        Demo_WriteBuffer(0,4,local_74);
      }
    }
    else {
                    /* Unresolved local var: Vector viewangles@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector dot_origin@[???] */
      (*gEngfuncs.GetViewAngles)((float *)&stack0xffffff50);
      HUD_GetLastOrg(&local_a4);
      local_80 = local_a4;
      local_7c = local_a0;
      local_78 = local_9c;
      local_88 = local_ac;
      local_84 = local_a8;
      local_8c = in_stack_ffffff50;
      iVar3 = Bench_InStage(3);
      damage = 3.50325e-43;
      if (iVar3 == 0) {
        damage = in_stack_ffffff4c;
      }
      ppfVar5 = &local_98;
      viewangles.y = (vec_t)&local_80;
      viewangles.x = (vec_t)&local_8c;
      viewangles.z = (vec_t)ppfVar5;
      origin.z = in_stack_ffffff4c;
      origin.x = (vec_t)(int)in_stack_ffffff44;
      origin.y = (vec_t)(int)((ulonglong)in_stack_ffffff44 >> 0x20);
      pfVar4 = &local_80;
      iVar3 = HUD_CreateSniperDot((int)damage,viewangles,origin,in_stack_ffffff50);
      if (iVar3 != 0) {
        local_80 = g_aimorg.x;
        local_7c = g_aimorg.y;
        local_78 = g_aimorg.z;
        local_8c = local_98;
        local_88 = local_94;
        local_84 = local_90;
        dot.y = (vec_t)&local_80;
        dot.x = (vec_t)&local_8c;
        dot.z = (vec_t)pfVar4;
        target.y = (vec_t)(int)in_stack_ffffff44;
        target.z = (vec_t)(int)((ulonglong)in_stack_ffffff44 >> 0x20);
        target.x = (vec_t)ppfVar5;
        Bench_SpotPosition(dot,target);
      }
      iVar3 = (*(gEngfuncs.pDemoAPI)->IsRecording)();
      if (iVar3 != 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uchar[100] buf@[???] */
        local_74[0] = '\x01';
        local_74[1] = '\0';
        local_74[2] = '\0';
        local_74[3] = '\0';
        local_60 = local_a4;
        local_5c = local_a0;
        local_58 = local_9c;
        Demo_WriteBuffer(0,0x20,local_74);
      }
    }
  }
  iVar3 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)();
  if ((iVar3 != 0) && (g_demosniper != 0)) {
                    /* Unresolved local var: Vector dummy@[???] */
    local_80 = g_demosniperorg[0];
    local_7c = g_demosniperorg[1];
    local_78 = g_demosniperorg[2];
    local_8c = (float *)g_demosniperangles[0];
    local_88 = g_demosniperangles[1];
    local_84 = g_demosniperangles[2];
    viewangles_00.y = (vec_t)&local_80;
    viewangles_00.x = (vec_t)&local_8c;
    viewangles_00.z = (vec_t)&local_98;
    origin_00.z = in_stack_ffffff4c;
    origin_00.x = (vec_t)(int)in_stack_ffffff44;
    origin_00.y = (vec_t)(int)((ulonglong)in_stack_ffffff44 >> 0x20);
    HUD_CreateSniperDot(g_demosniperdamage,viewangles_00,origin_00,in_stack_ffffff50);
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


