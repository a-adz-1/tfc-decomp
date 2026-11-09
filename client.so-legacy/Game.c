// Game_AddObjects  @ 00080490
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Game_AddObjects(void)

{
  Vector viewangles;
  Vector viewangles_00;
  Vector dot;
  char *__nptr;
  long lVar1;
  cl_entity_s *pcVar2;
  int iVar3;
  int iVar4;
  vec_t *pvVar5;
  float *buffer;
  Vector in_stack_fffffeb0;
  float local_144;
  int local_140;
  float local_13c;
  undefined4 local_138;
  undefined4 local_134;
  float local_130;
  undefined4 local_12c;
  undefined4 local_128;
  float local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  float local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  float local_64;
  undefined4 local_60;
  undefined4 local_5c;
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  vec_t local_40;
  vec_t local_3c;
  vec_t local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  int local_1c [6];
  
                    /* Unresolved local var: cl_entity_t * player@[???]
                       Unresolved local var: int damage@[???]
                       Unresolved local var: int tfc@[???] */
  __nptr = (*gEngfuncs.PhysInfo_ValueForKey)("tfc");
  buffer = (float *)0xa;
  pvVar5 = (vec_t *)0x0;
  lVar1 = strtol(__nptr,(char **)0x0,10);
  pcVar2 = (*gEngfuncs.GetLocalPlayer)();
  if ((pcVar2 != (cl_entity_s *)0x0) && (lVar1 != 0)) {
    if ((pcVar2->curstate).playerclass != 2) {
      iVar3 = Bench_InStage(3);
      if (iVar3 == 0) goto LAB_000804cf;
    }
    iVar3 = HUD_NeedSpot(local_1c);
    if (iVar3 == 0) {
      iVar3 = (*(gEngfuncs.pDemoAPI)->IsRecording)();
      if (iVar3 != 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uchar[100] buf@[???] */
        local_e0 = 0.0;
        buffer = &local_e0;
        pvVar5 = (vec_t *)0x4;
        Demo_WriteBuffer(0,4,(uchar *)buffer);
      }
    }
    else {
                    /* Unresolved local var: Vector viewangles@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector dot_origin@[???] */
      (*gEngfuncs.GetViewAngles)(&local_e0);
      HUD_GetLastOrg(&local_7c);
      local_58 = local_7c;
      local_54 = local_78;
      local_50 = local_74;
      local_64 = local_e0;
      local_60 = local_dc;
      local_5c = local_d8;
      iVar4 = Bench_InStage(3);
      iVar3 = 0xfa;
      if (iVar4 == 0) {
        iVar3 = local_1c[0];
      }
      viewangles_00.y = (vec_t)pvVar5;
      viewangles_00.x = (vec_t)&local_70;
      viewangles_00.z = (vec_t)buffer;
      iVar3 = HUD_CreateSniperDot(iVar3,viewangles_00,in_stack_fffffeb0,&local_64);
      if (iVar3 != 0) {
        local_40 = g_aimorg.x;
        local_3c = g_aimorg.y;
        local_38 = g_aimorg.z;
        local_4c = local_70;
        local_48 = local_6c;
        local_44 = local_68;
        pvVar5 = &local_40;
        dot.y = (vec_t)pvVar5;
        dot.x = (vec_t)&local_4c;
        dot.z = (vec_t)buffer;
        Bench_SpotPosition(dot,in_stack_fffffeb0);
      }
      iVar3 = (*(gEngfuncs.pDemoAPI)->IsRecording)();
      if (iVar3 != 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uchar[100] buf@[???] */
        local_144 = 1.4013e-45;
        local_140 = local_1c[0];
        local_13c = local_e0;
        local_138 = local_dc;
        local_134 = local_d8;
        local_130 = local_7c;
        local_12c = local_78;
        local_128 = local_74;
        buffer = &local_144;
        pvVar5 = (vec_t *)0x20;
        Demo_WriteBuffer(0,0x20,(uchar *)buffer);
      }
    }
  }
LAB_000804cf:
  iVar3 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)();
  if ((iVar3 != 0) && (g_demosniper != 0)) {
                    /* Unresolved local var: Vector dummy@[???] */
    local_28 = g_demosniperorg[0];
    local_24 = g_demosniperorg[1];
    local_20 = g_demosniperorg[2];
    local_34 = g_demosniperangles[0];
    local_30 = g_demosniperangles[1];
    local_2c = g_demosniperangles[2];
    viewangles.y = (vec_t)pvVar5;
    viewangles.x = (vec_t)&local_70;
    viewangles.z = (vec_t)buffer;
    HUD_CreateSniperDot(g_demosniperdamage,viewangles,in_stack_fffffeb0,&local_34);
  }
  return;
}


// Game_HookEvents  @ 0007f860
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Game_HookEvents(void)

{
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_sniperhit.sc",EV_TFC_SniperHit);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_sg.sc",EV_FireTFCShotgun);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_sgreload.sc",EV_ReloadTFCShotgun);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_sgpump.sc",EV_PumpTFCShotgun);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_sniper.sc",EV_FireTFCSniper);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_ssg.sc",EV_FireTFCSuperShotgun);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_nail.sc",EV_FireTFCNailgun);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_snail.sc",EV_FireTFCSuperNailgun);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_rpg.sc",EV_TFC_FireRPG);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_ic.sc",EV_TFC_FireIC);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_ar.sc",EV_FireTFCAutoRifle);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_acwu.sc",EV_TFC_Assault_WindUp);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_acwd.sc",EV_TFC_Assault_WindDown);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_acstart.sc",EV_TFC_Assault_Start);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_acfire.sc",EV_TFC_Assault_Fire);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_acspin.sc",EV_TFC_Assault_Spin);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_acsspin.sc",EV_TFC_Assault_StartSpin);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_flame.sc",EV_TFC_Flame_Fire);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_knife.sc",EV_TFC_Knife);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_rail.sc",EV_TFC_Railgun);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_tranq.sc",EV_TFC_Tranquilizer);
  (*gEngfuncs.pfnHookEvent)("events/explode/tf_nailgren.sc",EV_TFC_NailgrenadeNail);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_gl.sc",EV_TFC_GrenadeLauncher);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_pipel.sc",EV_TFC_PipeLauncher);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_axe.sc",EV_TFC_Axe);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_mednormal.sc",EV_TFC_NormalShot);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_medsuper.sc",EV_TFC_SuperShot);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_medsteam.sc",EV_TFC_SteamShot);
  (*gEngfuncs.pfnHookEvent)("events/wpn/tf_axedecal.sc",EV_TFC_AxeDecal);
  (*gEngfuncs.pfnHookEvent)("events/misc/tf_buildingevent.sc",EV_TFC_BuildingEvent);
  (*gEngfuncs.pfnHookEvent)("events/explode/tf_pipe.sc",EV_TFC_Explosion);
  (*gEngfuncs.pfnHookEvent)("events/explode/tf_gren.sc",EV_TFC_Grenade);
  (*gEngfuncs.pfnHookEvent)("events/explode/tf_engrgren.sc",EV_TFC_EngineerGrenade);
  (*gEngfuncs.pfnHookEvent)("events/explode/tf_concuss.sc",EV_TFC_Concussion);
  (*gEngfuncs.pfnHookEvent)("events/explode/tf_normalgren.sc",EV_TFC_NormalGrenade);
  (*gEngfuncs.pfnHookEvent)("events/explode/tf_mirvmain.sc",EV_TFC_MirvGrenadeMain);
  (*gEngfuncs.pfnHookEvent)("events/explode/tf_mirv.sc",EV_TFC_MirvGrenade);
  (*gEngfuncs.pfnHookEvent)("events/explode/tf_fire.sc",EV_TFC_NapalmFire);
  (*gEngfuncs.pfnHookEvent)("events/explode/tf_burn.sc",EV_TFC_NapalmBurn);
  (*gEngfuncs.pfnHookEvent)("events/explode/tf_gas.sc",EV_TFC_Gas);
  (*gEngfuncs.pfnHookEvent)("events/explode/tf_emp.sc",EV_TFC_EMP);
  (*gEngfuncs.pfnHookEvent)("events/explode/tf_ng.sc",EV_TFC_NailGrenade);
  (*gEngfuncs.pfnHookEvent)("events/door/doorgoup.sc",EV_TFC_DoorGoUp);
  (*gEngfuncs.pfnHookEvent)("events/door/doorgodown.sc",EV_TFC_DoorGoDown);
  (*gEngfuncs.pfnHookEvent)("events/door/doorhittop.sc",EV_TFC_DoorHitTop);
  (*gEngfuncs.pfnHookEvent)("events/door/doorhitbottom.sc",EV_TFC_DoorHitBottom);
  (*gEngfuncs.pfnHookEvent)("events/misc/gibs.sc",EV_TFC_Gibs);
  (*gEngfuncs.pfnHookEvent)("events/misc/benchmark.sc",EV_Benchmark);
  (*gEngfuncs.pfnHookEvent)("events/train.sc",EV_TrainPitchAdjust);
  cl_gibcount = (*gEngfuncs.pfnRegisterVariable)("cl_gibcount","4",1);
  cl_giblife = (*gEngfuncs.pfnRegisterVariable)("cl_giblife","25",1);
  cl_gibvelscale = (*gEngfuncs.pfnRegisterVariable)("cl_gibvelscale","1.0",1);
  cl_localblood = (*gEngfuncs.pfnRegisterVariable)("cl_lb","0.0",3);
  return;
}


