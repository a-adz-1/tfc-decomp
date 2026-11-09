// Ghidra decompilation of functions from cl_dll/tfc/tf_events.cpp
// 2 functions, ordered by original source line

// EV_TrainPitchAdjust  @ 0005a160  (line 77)

void EV_TrainPitchAdjust(event_args_t *args)

{
  uint uVar1;
  int in_GS_OFFSET;
  uint local_124;
  float local_11c;
  float local_118;
  float local_114;
  char local_110 [256];
  int local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: ushort us_params@[???]
                       Unresolved local var: int noise@[???]
                       Unresolved local var: float m_flVolume@[???]
                       Unresolved local var: int pitch@[???]
                       Unresolved local var: int stop@[???]
                       Unresolved local var: char[256] sz@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_11c = args->origin[0];
  local_118 = args->origin[1];
  local_114 = args->origin[2];
  uVar1 = args->iparam1 & 0xffff;
  switch((int)uVar1 >> 0xc & 7) {
  default:
    goto switchD_0005a1b9_caseD_0;
  case 1:
    builtin_strncpy(local_110 + 0xc,"1.wa",4);
    if (args->bparam1 != 0) goto LAB_0005a1ef;
    goto LAB_0005a260;
  case 2:
    builtin_strncpy(local_110 + 0xc,"2.wa",4);
    break;
  case 3:
    builtin_strncpy(local_110 + 0xc,"3.wa",4);
    break;
  case 4:
    builtin_strncpy(local_110 + 0xc,"4.wa",4);
    break;
  case 5:
    builtin_strncpy(local_110 + 0xc,"6.wa",4);
    break;
  case 6:
    builtin_strncpy(local_110 + 0xc,"7.wa",4);
  }
  if (args->bparam1 == 0) {
LAB_0005a260:
    local_110[0x10] = 'v';
    local_110[0x11] = '\0';
    builtin_strncpy(local_110,"plats/ttrain",0xc);
    local_124 = args->iparam1 & 0x3f;
    (*(gEngfuncs.pEventAPI)->EV_PlaySound)
              (args->entindex,&local_11c,6,local_110,(float)local_124 / 40.0,0.8,0x80,
               (int)((float)((int)uVar1 >> 6 & 0x3f) * 10.0));
  }
  else {
LAB_0005a1ef:
    local_110[0x10] = 'v';
    local_110[0x11] = '\0';
    builtin_strncpy(local_110,"plats/ttrain",0xc);
    (*(gEngfuncs.pEventAPI)->EV_StopSound)(args->entindex,6,local_110);
  }
switchD_0005a1b9_caseD_0:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Game_HookEvents  @ 0005a3b0  (line 126)

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


