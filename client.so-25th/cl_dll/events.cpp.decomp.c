// Ghidra decompilation of functions from cl_dll/events.cpp
// 1 functions, ordered by original source line

// EV_HookEvents  @ 0006b600  (line 15)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void EV_HookEvents(void)

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


