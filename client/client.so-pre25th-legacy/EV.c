// EV_Benchmark  @ 00076f00
void EV_Benchmark(event_args_t *args)

{
  _func_int_int *p_Var1;
  _func_void_int_int_int_float_ptr_int *p_Var2;
  physent_s_conflict *ppVar3;
  int iVar4;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  pmtrace_s local_cc;
  float local_7c [3];
  float local_70;
  undefined4 local_6c;
  undefined4 local_68;
  float local_64 [3];
  float local_58 [3];
  float local_4c [3];
  float local_40;
  undefined4 local_3c;
  undefined4 local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int iDamage@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_34 = args->origin[0];
  iVar4 = args->entindex;
  local_30 = args->origin[1];
  local_2c = args->origin[2];
  local_28 = args->angles[0];
  local_24 = args->angles[1];
  local_20 = args->angles[2];
  (*gEngfuncs.pfnAngleVectors)(&local_28,&local_40,local_4c,local_58);
  EV_IsLocal(iVar4);
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(iVar4,&local_34,1,"common/wpn_select.wav",0.9,0.8,0,100);
  EV_GetGunPosition(args,local_7c,&local_34);
  local_70 = local_40;
  local_6c = local_3c;
  local_68 = local_38;
  VectorMA(local_7c,2.0,local_58,local_7c);
  VectorMA(local_7c,8192.0,&local_70,local_64);
  (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(iVar4 + -1);
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(local_7c,local_64,2,-1,&local_cc);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  if ((local_cc.fraction != 1.0) &&
     ((*gEngfuncs.GetClientTime)(), (longdouble)g_nTime < extraout_ST0)) {
                    /* Unresolved local var: physent_t * pe@[???] */
    ppVar3 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(local_cc.ent);
    if ((ppVar3 != (physent_s_conflict *)0x0) &&
       (((ppVar3->solid == 4 || (ppVar3->movetype == 0xd)) && (local_cc.fraction != 1.0)))) {
      local_cc.endpos.z = local_cc.endpos.z + g_fZAdjust;
      (*gEngfuncs.pfnGetCvarFloat)("r_decals");
      if (extraout_ST0_01 != (longdouble)0) {
        p_Var1 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
        p_Var2 = (gEngfuncs.pEfxAPI)->R_DecalShoot;
        iVar4 = (*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)("{dot");
        iVar4 = (*p_Var1)(iVar4);
        (*p_Var2)(iVar4,0,0,&local_cc.endpos.x,0);
      }
    }
    (*gEngfuncs.GetClientTime)();
    g_nTime = (float)((longdouble)0.05 + extraout_ST0_00);
    return;
  }
  return;
}


// EV_CreateTracer  @ 0008ea80
void EV_CreateTracer(float *start,float *end)

{
                    /* WARNING: Could not recover jumptable at 0x0008ea8b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(gEngfuncs.pEfxAPI)->R_TracerEffect)(start,end);
  return;
}


// EV_EjectBrass  @ 0008ec70
void EV_EjectBrass(float *origin,float *velocity,float rotation,int model,int soundtype)

{
  float local_18;
  float local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: Vector endpos@[???] */
  local_18 = 0.0;
  local_10 = 0;
  local_14 = rotation;
  (*(gEngfuncs.pEfxAPI)->R_TempModel)(origin,velocity,&local_18,2.5,model,soundtype);
  return;
}


// EV_FireTFCAutoRifle  @ 000717d0
void EV_FireTFCAutoRifle(event_args_t *args)

{
  int idx;
  qboolean qVar1;
  physent_s_conflict *ppVar2;
  float *bitsDamageType;
  pmtrace_t local_c0;
  float local_7c [3];
  float local_70;
  undefined4 local_6c;
  undefined4 local_68;
  float local_64 [3];
  float local_58 [3];
  float local_4c [3];
  float local_40;
  undefined4 local_3c;
  undefined4 local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAiming@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: float flSpread@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_34 = args->origin[0];
  idx = args->entindex;
  local_30 = args->origin[1];
  local_2c = args->origin[2];
  local_28 = args->angles[0];
  local_24 = args->angles[1];
  local_20 = args->angles[2];
  (*gEngfuncs.pfnAngleVectors)(&local_28,&local_40,local_4c,local_58);
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(6,2);
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_34,1,"weapons/sniper.wav",0.9,0.8,0,100);
  EV_GetGunPosition(args,local_7c,&local_34);
  local_70 = local_40;
  local_6c = local_3c;
  local_68 = local_38;
  VectorMA(local_7c,8192.0,&local_70,local_64);
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(idx + -1);
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  bitsDamageType = local_64;
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(local_7c,local_64,2,-1,&local_c0);
  if (local_c0.fraction != 1.0) {
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
    if ((cl_localblood == (cvar_t *)0x0) || (cl_localblood->value != 0.0)) {
      EV_TFC_TraceAttack(idx,(float)&local_70,(float *)&local_c0,(pmtrace_t *)0x41000000,
                         (int)bitsDamageType);
    }
    EV_TFC_PlayTextureSound(idx,&local_c0,local_7c,local_64,3);
                    /* Unresolved local var: physent_t * pe@[???] */
    ppVar2 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(local_c0.ent);
    if ((ppVar2 != (physent_s_conflict *)0x0) && ((ppVar2->solid == 4 || (ppVar2->movetype == 0xd)))
       ) {
      EV_TFC_DecalGunshot(&local_c0,3);
    }
  }
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  return;
}


// EV_FireTFCNailgun  @ 000715e0
void EV_FireTFCNailgun(event_args_t *args)

{
  int idx;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var1;
  int iVar2;
  qboolean qVar3;
  int32 iVar4;
  longdouble lVar5;
  float local_70 [3];
  float local_64 [3];
  float local_58 [3];
  float local_4c [3];
  float local_40 [3];
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: Vector ShellOrigin@[???]
                       Unresolved local var: int shell@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: float flSpread@[???]
                       Unresolved local var: Vector vecVelocity@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_34 = args->origin[0];
  idx = args->entindex;
  local_30 = args->origin[1];
  local_2c = args->origin[2];
  local_28 = args->angles[0];
  local_24 = args->angles[1];
  local_20 = args->angles[2];
  (*gEngfuncs.pfnAngleVectors)(&local_28,local_4c,local_58,local_64);
  iVar2 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("models/nail.mdl");
  qVar3 = EV_IsLocal(idx);
  if (qVar3 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(5,2);
  }
  EV_GetGunPosition(args,local_70,&local_34);
  VectorMA(local_70,-4.0,local_64,local_70);
  VectorMA(local_70,2.0,local_58,local_70);
  p_Var1 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  iVar4 = (*gEngfuncs.pfnRandomLong)(0,0x1f);
  lVar5 = (longdouble)(*gEngfuncs.pfnRandomFloat)(0.95,1.0);
  (*p_Var1)(idx,&local_34,1,"weapons/airgun_1.wav",(float)lVar5,0.8,0,iVar4 + 0x5d);
  VectorScale(local_4c,1000.0,local_40);
  (*(gEngfuncs.pEfxAPI)->R_Projectile)(local_70,local_40,(int)(short)iVar2,6,idx,EV_TFC_NailTouch);
  qVar3 = EV_IsLocal(idx);
  if (qVar3 != 0) {
    V_PunchAxis(0,-1.0);
  }
  return;
}


// EV_FireTFCShotgun  @ 00070f10
void EV_FireTFCShotgun(event_args_t *args)

{
  int idx;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var1;
  int model;
  qboolean qVar2;
  int32 iVar3;
  longdouble lVar4;
  float local_a0 [3];
  float local_94 [3];
  float local_88 [3];
  float local_7c;
  undefined4 local_78;
  undefined4 local_74;
  float local_70 [3];
  float local_64 [3];
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28 [6];
  
                    /* Unresolved local var: Vector ShellVelocity@[???]
                       Unresolved local var: Vector ShellOrigin@[???]
                       Unresolved local var: int shell@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAiming@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: float flSpread@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_4c = args->origin[0];
  idx = args->entindex;
  local_48 = args->origin[1];
  local_44 = args->origin[2];
  local_40 = args->angles[0];
  local_3c = args->angles[1];
  local_38 = args->angles[2];
  local_34 = args->velocity[0];
  local_30 = args->velocity[1];
  local_2c = args->velocity[2];
  (*gEngfuncs.pfnAngleVectors)(&local_40,&local_58,local_64,local_70);
  model = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("models/shotgunshell.mdl");
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    EV_MuzzleFlash();
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(1,2);
  }
  EV_GetDefaultShellInfo
            (args,&local_4c,&local_34,local_a0,local_94,&local_58,local_64,local_70,20.0,-12.0,4.0);
  EV_EjectBrass(local_94,local_a0,local_3c,model,2);
  p_Var1 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  iVar3 = (*gEngfuncs.pfnRandomLong)(0,0x1f);
  lVar4 = (longdouble)(*gEngfuncs.pfnRandomFloat)(0.95,1.0);
  (*p_Var1)(idx,&local_4c,1,"weapons/sbarrel1.wav",(float)lVar4,0.8,0,iVar3 + 0x5d);
  EV_GetGunPosition(args,local_88,&local_4c);
  local_7c = local_58;
  local_28[0] = 0.04;
  local_78 = local_54;
  local_28[1] = 0.04;
  local_28[2] = 0.0;
  local_74 = local_50;
  EV_TFC_FireBullets(idx,&local_58,local_64,local_70,6,local_88,&local_7c,local_28,2048.0,6,0,
                     (int *)(EV_TFC_DamageDecal::lexical_block_0::decalname + idx * 4 + 0x1c),4);
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    V_PunchAxis(0,-2.0);
  }
  return;
}


// EV_FireTFCSniper  @ 00075420
void EV_FireTFCSniper(event_args_t *args)

{
  int iVar1;
  int idx;
  qboolean qVar2;
  int idx_00;
  physent_s_conflict *ppVar3;
  float *bitsDamageType;
  pmtrace_t local_c0;
  float local_7c [3];
  float local_70;
  undefined4 local_6c;
  undefined4 local_68;
  float local_64 [3];
  float local_58 [3];
  float local_4c [3];
  float local_40;
  undefined4 local_3c;
  undefined4 local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int iDamage@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  iVar1 = args->iparam1;
  idx = args->entindex;
  local_34 = args->origin[0];
  local_30 = args->origin[1];
  local_2c = args->origin[2];
  local_28 = args->angles[0];
  local_24 = args->angles[1];
  local_20 = args->angles[2];
  (*gEngfuncs.pfnAngleVectors)(&local_28,&local_40,local_4c,local_58);
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(2,2);
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_34,1,"ambience/rifle1.wav",0.9,0.8,0,100);
  EV_GetGunPosition(args,local_7c,&local_34);
  local_70 = local_40;
  local_6c = local_3c;
  local_68 = local_38;
  VectorMA(local_7c,2.0,local_58,local_7c);
  VectorMA(local_7c,8192.0,&local_70,local_64);
  (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(idx + -1);
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  bitsDamageType = local_64;
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(local_7c,local_64,2,-1,&local_c0);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  if (local_c0.fraction != 1.0) {
    idx_00 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(&local_c0);
    qVar2 = EV_IsPlayer(idx_00);
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
    if ((qVar2 != 0) && ((cl_localblood == (cvar_t *)0x0 || (cl_localblood->value != 0.0)))) {
      EV_TFC_TraceAttack(idx,(float)&local_70,(float *)&local_c0,(pmtrace_t *)(float)iVar1,
                         (int)bitsDamageType);
    }
    EV_TFC_PlayTextureSound(idx,&local_c0,local_7c,local_64,3);
                    /* Unresolved local var: physent_t * pe@[???] */
    ppVar3 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(local_c0.ent);
    if ((ppVar3 != (physent_s_conflict *)0x0) && ((ppVar3->solid == 4 || (ppVar3->movetype == 0xd)))
       ) {
      EV_TFC_DecalGunshot(&local_c0,3);
      return;
    }
  }
  return;
}


// EV_FireTFCSuperNailgun  @ 00071d40
void EV_FireTFCSuperNailgun(event_args_t *args)

{
  int idx;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var1;
  int iVar2;
  qboolean qVar3;
  int32 iVar4;
  float local_70 [3];
  float local_64 [3];
  float local_58 [3];
  float local_4c [3];
  float local_40 [3];
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: Vector ShellOrigin@[???]
                       Unresolved local var: int shell@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: float flSpread@[???]
                       Unresolved local var: Vector vecVelocity@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_34 = args->origin[0];
  idx = args->entindex;
  local_30 = args->origin[1];
  local_2c = args->origin[2];
  local_28 = args->angles[0];
  local_24 = args->angles[1];
  local_20 = args->angles[2];
  (*gEngfuncs.pfnAngleVectors)(&local_28,local_4c,local_58,local_64);
  iVar2 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("models/nail.mdl");
  qVar3 = EV_IsLocal(idx);
  if (qVar3 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(5,2);
  }
  EV_GetGunPosition(args,local_70,&local_34);
  VectorMA(local_70,-4.0,local_64,local_70);
  VectorMA(local_70,2.0,local_58,local_70);
  p_Var1 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  iVar4 = (*gEngfuncs.pfnRandomLong)(0,0xf);
  (*p_Var1)(idx,&local_34,1,"weapons/spike2.wav",1.0,0.8,0,iVar4 + 0x5e);
  VectorScale(local_4c,1000.0,local_40);
  (*(gEngfuncs.pEfxAPI)->R_Projectile)(local_70,local_40,(int)(short)iVar2,6,idx,EV_TFC_NailTouch);
  qVar3 = EV_IsLocal(idx);
  if (qVar3 != 0) {
    V_PunchAxis(0,-1.0);
  }
  return;
}


// EV_FireTFCSuperShotgun  @ 00071a40
void EV_FireTFCSuperShotgun(event_args_t *args)

{
  int idx;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var1;
  int model;
  qboolean qVar2;
  int32 iVar3;
  longdouble lVar4;
  float local_a0 [3];
  float local_94 [3];
  float local_88 [3];
  float local_7c;
  undefined4 local_78;
  undefined4 local_74;
  float local_70 [3];
  float local_64 [3];
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28 [6];
  
                    /* Unresolved local var: Vector ShellVelocity@[???]
                       Unresolved local var: Vector ShellOrigin@[???]
                       Unresolved local var: int shell@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAiming@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: float flSpread@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_4c = args->origin[0];
  idx = args->entindex;
  local_48 = args->origin[1];
  local_44 = args->origin[2];
  local_40 = args->angles[0];
  local_3c = args->angles[1];
  local_38 = args->angles[2];
  local_34 = args->velocity[0];
  local_30 = args->velocity[1];
  local_2c = args->velocity[2];
  (*gEngfuncs.pfnAngleVectors)(&local_40,&local_58,local_64,local_70);
  model = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("models/shotgunshell.mdl");
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    EV_MuzzleFlash();
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(1,2);
  }
  EV_GetDefaultShellInfo
            (args,&local_4c,&local_34,local_a0,local_94,&local_58,local_64,local_70,20.0,-12.0,4.0);
  EV_EjectBrass(local_94,local_a0,local_3c,model,2);
  p_Var1 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  iVar3 = (*gEngfuncs.pfnRandomLong)(0,0x1f);
  lVar4 = (longdouble)(*gEngfuncs.pfnRandomFloat)(0.95,1.0);
  (*p_Var1)(idx,&local_4c,1,"weapons/shotgn2.wav",(float)lVar4,0.8,0,iVar3 + 0x5d);
  EV_GetGunPosition(args,local_88,&local_4c);
  local_28[0] = 0.04;
  local_7c = local_58;
  local_78 = local_54;
  local_28[1] = 0.04;
  local_28[2] = 0.0;
  local_74 = local_50;
  EV_TFC_FireBullets(idx,&local_58,local_64,local_70,0xe,local_88,&local_7c,local_28,2048.0,6,4,
                     (int *)(EV_TFC_DamageDecal::lexical_block_0::decalname + idx * 4 + 0x1c),4);
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    V_PunchAxis(0,-4.0);
  }
  return;
}


// EV_GetDefaultShellInfo  @ 0008ecd0
void EV_GetDefaultShellInfo
               (event_args_t *args,float *origin,float *velocity,float *ShellVelocity,
               float *ShellOrigin,float *forward,float *right,float *up,float forwardScale,
               float upScale,float rightScale)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble lVar4;
  longdouble lVar5;
  float local_2c;
  float local_28;
  float local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector view_ofs@[???]
                       Unresolved local var: float fR@[???]
                       Unresolved local var: float fU@[???]
                       Unresolved local var: int idx@[???] */
  iVar2 = args->entindex;
  local_2c = 0.0;
  local_28 = 0.0;
  local_24 = 28.0;
  if ((0 < iVar2) && (iVar1 = (*gEngfuncs.GetMaxClients)(), iVar2 <= iVar1)) {
    if ((g_iUser1 == 4) || ((g_iUser1 != 0 && ((gHUD.m_Spectator.m_pip)->value == 2.0)))) {
      bVar3 = iVar2 == g_iUser2;
    }
    else {
      iVar2 = (*(gEngfuncs.pEventAPI)->EV_IsLocal)(iVar2 + -1);
      bVar3 = iVar2 != 0;
    }
    if (bVar3) {
      (*(gEngfuncs.pEventAPI)->EV_LocalPlayerViewheight)(&local_2c);
    }
    else if (args->ducking == 1) {
      local_24 = 12.0;
    }
  }
  (*gEngfuncs.pfnRandomFloat)(50.0,70.0);
  (*gEngfuncs.pfnRandomFloat)(100.0,150.0);
  lVar4 = (longdouble)(float)extraout_ST0;
  lVar5 = (longdouble)25.0;
  *ShellVelocity =
       (float)((longdouble)*forward * lVar5 +
              (longdouble)*up * extraout_ST0_00 + (longdouble)*right * lVar4 + (longdouble)*velocity
              );
  *ShellOrigin = rightScale * *right + forwardScale * *forward + upScale * *up + *origin + local_2c;
  ShellVelocity[1] =
       (float)((longdouble)forward[1] * lVar5 +
              (longdouble)up[1] * extraout_ST0_00 +
              (longdouble)right[1] * lVar4 + (longdouble)velocity[1]);
  ShellOrigin[1] =
       rightScale * right[1] + forwardScale * forward[1] + upScale * up[1] + origin[1] + local_28;
  ShellVelocity[2] =
       (float)(lVar5 * (longdouble)forward[2] +
              extraout_ST0_00 * (longdouble)up[2] +
              lVar4 * (longdouble)right[2] + (longdouble)velocity[2]);
  ShellOrigin[2] =
       rightScale * right[2] + forwardScale * forward[2] + upScale * up[2] + origin[2] + local_24;
  return;
}


// EV_GetGunPosition  @ 0008eb20
void EV_GetGunPosition(event_args_t *args,float *pos,float *origin)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  float local_2c;
  float local_28;
  float local_24;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector view_ofs@[???] */
  iVar2 = args->entindex;
  local_2c = 0.0;
  local_28 = 0.0;
  local_24 = 28.0;
  if (iVar2 < 1) {
    local_24 = 28.0;
    local_2c = 0.0;
    local_28 = local_2c;
  }
  else {
    iVar1 = (*gEngfuncs.GetMaxClients)();
    if (iVar2 <= iVar1) {
      if ((g_iUser1 == 4) || ((g_iUser1 != 0 && ((gHUD.m_Spectator.m_pip)->value == 2.0)))) {
        bVar3 = iVar2 == g_iUser2;
      }
      else {
        iVar2 = (*(gEngfuncs.pEventAPI)->EV_IsLocal)(iVar2 + -1);
        bVar3 = iVar2 != 0;
      }
      if (((bVar3) && (g_iUser1 != 4)) &&
         ((g_iUser1 == 0 || ((gHUD.m_Spectator.m_pip)->value != 2.0)))) {
        (*(gEngfuncs.pEventAPI)->EV_LocalPlayerViewheight)(&local_2c);
      }
      else if (args->ducking == 1) {
        local_24 = 12.0;
      }
    }
  }
  *pos = local_2c + *origin;
  pos[1] = local_28 + origin[1];
  pos[2] = local_24 + origin[2];
  return;
}


// EV_HookEvents  @ 0008eef0
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


// EV_IsLocal  @ 0008eac0
qboolean EV_IsLocal(int idx)

{
  int iVar1;
  
  if ((g_iUser1 != 4) && ((g_iUser1 == 0 || ((gHUD.m_Spectator.m_pip)->value != 2.0)))) {
    iVar1 = (*(gEngfuncs.pEventAPI)->EV_IsLocal)(idx + -1);
    return (uint)(iVar1 != 0);
  }
  return (uint)(g_iUser2 == idx);
}


// EV_IsPlayer  @ 0008ea90
qboolean EV_IsPlayer(int idx)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (0 < idx) {
    iVar2 = (*gEngfuncs.GetMaxClients)();
    uVar1 = (uint)(idx <= iVar2);
  }
  return uVar1;
}


// EV_MuzzleFlash  @ 0008eed0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void EV_MuzzleFlash(void)

{
  int *piVar1;
  cl_entity_s *pcVar2;
  
                    /* Unresolved local var: cl_entity_t * ent@[DW_OP_reg0(EAX)] */
  pcVar2 = (*gEngfuncs.GetViewModel)();
  if (pcVar2 != (cl_entity_s *)0x0) {
    piVar1 = &(pcVar2->curstate).effects;
    *piVar1 = *piVar1 | 2;
  }
  return;
}


// EV_PumpTFCShotgun  @ 00071310
void EV_PumpTFCShotgun(event_args_t *args)

{
  int idx;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var1;
  int32 iVar2;
  qboolean qVar3;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: int resetanim@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_1c = args->origin[0];
  idx = args->entindex;
  local_18 = args->origin[1];
  local_14 = args->origin[2];
  if (args->bparam1 != 0) {
    qVar3 = EV_IsLocal(idx);
    if (qVar3 != 0) {
      (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(4,2);
    }
  }
  p_Var1 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  iVar2 = (*gEngfuncs.pfnRandomLong)(0,0x1f);
  (*p_Var1)(idx,&local_1c,3,"weapons/scock1.wav",1.0,0.8,0,iVar2 + 0x5f);
  return;
}


// EV_ReloadTFCShotgun  @ 00071210
void EV_ReloadTFCShotgun(event_args_t *args)

{
  int idx;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var1;
  qboolean qVar2;
  int32 iVar3;
  int iVar4;
  char *pcVar5;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_18 = args->origin[0];
  idx = args->entindex;
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(3,2);
  }
  iVar3 = (*gEngfuncs.pfnRandomLong)(0,1);
  p_Var1 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  if (iVar3 == 0) {
    iVar4 = (*gEngfuncs.pfnRandomLong)(0,0x1f);
    pcVar5 = "weapons/reload3.wav";
  }
  else {
    iVar4 = (*gEngfuncs.pfnRandomLong)(0,0x1f);
    pcVar5 = "weapons/reload1.wav";
  }
  (*p_Var1)(idx,&local_18,3,pcVar5,1.0,0.8,0,iVar4 + 0x55);
  return;
}


// EV_TFC_Assault_Fire  @ 00072230
void EV_TFC_Assault_Fire(event_args_t *args)

{
  int iVar1;
  int idx;
  int model;
  qboolean qVar2;
  float local_a0 [3];
  float local_94 [3];
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  undefined4 local_6c;
  undefined4 local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28 [6];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector ShellOrigin@[???]
                       Unresolved local var: Vector ShellVelocity@[???]
                       Unresolved local var: int shell@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAiming@[???]
                       Unresolved local var: float flSpread@[???]
                       Unresolved local var: int oddammo@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_4c = args->origin[0];
  iVar1 = args->bparam1;
  idx = args->entindex;
  local_48 = args->origin[1];
  local_44 = args->origin[2];
  local_40 = args->angles[0];
  local_3c = args->angles[1];
  local_38 = args->angles[2];
  local_34 = args->velocity[0];
  local_30 = args->velocity[1];
  local_2c = args->velocity[2];
  model = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("models/shell.mdl");
  (*gEngfuncs.pfnAngleVectors)(&local_40,&local_70,&local_7c,&local_88);
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    EV_MuzzleFlash();
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(4,2);
  }
  g_bACSpinning[idx + -1] = 0;
  if (iVar1 != 0) {
    EV_GetDefaultShellInfo
              (args,&local_4c,&local_34,local_94,local_a0,&local_70,&local_7c,&local_88,15.0,-25.0,
               6.0);
    EV_EjectBrass(local_a0,local_94,local_3c,model,1);
  }
  EV_GetGunPosition(args,&local_64,&local_4c);
  local_58 = local_70;
  local_54 = local_6c;
  local_50 = local_68;
  local_64 = local_88 * -4.0 + local_7c + local_7c + local_64;
  local_28[0] = 0.1;
  local_28[1] = 0.1;
  local_28[2] = 0.0;
  local_60 = local_84 * -4.0 + local_78 + local_78 + local_60;
  local_5c = local_80 * -4.0 + local_74 + local_74 + local_5c;
  EV_TFC_FireBullets(idx,&local_70,&local_7c,&local_88,5,&local_64,&local_58,local_28,8192.0,7,8,
                     tracerCount + idx + -1,8);
  return;
}


// EV_TFC_Assault_Spin  @ 000725e0
void EV_TFC_Assault_Spin(event_args_t *args)

{
  int idx;
  qboolean qVar1;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  idx = args->entindex;
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(4,2);
  }
  *(undefined4 *)(&DAT_0010947c + idx * 4) = 1;
  return;
}


// EV_TFC_Assault_Start  @ 00072170
void EV_TFC_Assault_Start(event_args_t *args)

{
  int iVar1;
  int iVar2;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_18 = args->origin[0];
  iVar2 = args->entindex;
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  iVar1 = iVar2 + -1;
  g_flSpinDownTime[iVar1] = 0.0;
  g_flSpinUpTime[iVar1] = 0.0;
  g_bACSpinning[iVar1] = 0;
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(iVar2,6,"weapons/asscan2.wav");
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(iVar2,6,"weapons/asscan4.wav");
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(iVar2,&local_18,6,"weapons/asscan2.wav",0.98,0.8,0,0x7d);
  return;
}


// EV_TFC_Assault_StartSpin  @ 00072530
void EV_TFC_Assault_StartSpin(event_args_t *args)

{
  int iVar1;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_18 = args->origin[0];
  iVar1 = args->entindex;
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  *(undefined4 *)(&DAT_0010947c + iVar1 * 4) = 1;
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(iVar1,6,"weapons/asscan2.wav");
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(iVar1,6,"weapons/asscan4.wav");
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(iVar1,&local_18,6,"weapons/asscan4.wav",0.98,0.8,0,0x7d);
  return;
}


// EV_TFC_Assault_WindDown  @ 00072030
void EV_TFC_Assault_WindDown(event_args_t *args)

{
  int iVar1;
  int idx;
  int iVar2;
  longdouble extraout_ST0;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???] */
  local_18 = args->origin[0];
  idx = args->entindex;
  local_14 = args->origin[1];
  iVar1 = idx + -1;
  local_10 = args->origin[2];
  if (g_flSpinUpTime[iVar1] == 0.0) {
    (*gEngfuncs.GetClientTime)();
    g_flSpinDownTime[iVar1] = (float)(extraout_ST0 + (longdouble)3.0);
    iVar2 = EV_IsLocal(idx);
  }
  else {
    iVar2 = EV_IsLocal(idx);
  }
  if (iVar2 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(3,2);
  }
  g_bACSpinning[iVar1] = 0;
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(idx,6,"weapons/asscan2.wav");
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(idx,6,"weapons/asscan4.wav");
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(idx,1,"weapons/asscan1.wav");
  if (args->bparam1 == 0) {
    (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_18,1,"weapons/asscan3.wav",0.98,0.8,0,0x7d);
  }
  return;
}


// EV_TFC_Assault_WindUp  @ 00071f20
void EV_TFC_Assault_WindUp(event_args_t *args)

{
  int iVar1;
  int idx;
  qboolean qVar2;
  longdouble extraout_ST0;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???] */
  local_18 = args->origin[0];
  idx = args->entindex;
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  iVar1 = idx + -1;
  g_flSpinDownTime[iVar1] = 0.0;
  (*gEngfuncs.GetClientTime)();
  g_flSpinUpTime[iVar1] = (float)(extraout_ST0 + (longdouble)3.5);
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(2,2);
  }
  g_bACSpinning[iVar1] = 0;
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(idx,6,"weapons/asscan2.wav");
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(idx,6,"weapons/asscan4.wav");
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(idx,1,"weapons/asscan3.wav");
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_18,1,"weapons/asscan1.wav",0.98,0.8,0,0x7d);
  return;
}


// EV_TFC_Axe  @ 00076030
void EV_TFC_Axe(event_args_t *args)

{
  int classid;
  int idx;
  float fSoundData;
  ushort uVar1;
  uint uVar2;
  qboolean qVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  float fVar9;
  int iVar10;
  pmtrace_s local_f8;
  pmtrace_s local_b4;
  float local_70 [3];
  float local_64 [3];
  float local_58 [3];
  float local_4c [3];
  float local_40 [3];
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int fDidHit@[???]
                       Unresolved local var: int m_bHullHit@[???]
                       Unresolved local var: int classid@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  classid = args->iparam1;
  idx = args->entindex;
  local_34 = args->origin[0];
  local_30 = args->origin[1];
  local_2c = args->origin[2];
  local_28 = args->angles[0];
  local_24 = args->angles[1];
  local_20 = args->angles[2];
  (*gEngfuncs.pfnAngleVectors)(&local_28,local_40,local_4c,local_58);
  iVar10 = idx + -1;
  EV_GetGunPosition(args,local_70,&local_34);
  VectorMA(local_70,32.0,local_40,local_64);
  (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(iVar10);
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(local_70,local_64,0,-1,&local_f8);
  if (1.0 <= local_f8.fraction) {
                    /* Unresolved local var: pmtrace_t tr2@[???] */
    (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(1);
    (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(local_70,local_64,0,-1,&local_b4);
    uVar2 = 0;
    if (local_b4.fraction < 1.0) {
      do {
        *(undefined4 *)((int)&local_f8.allsolid + uVar2) =
             *(undefined4 *)((int)&local_b4.allsolid + uVar2);
        if (0x43 < uVar2 + 4) break;
        *(undefined4 *)((int)&local_f8.startsolid + uVar2) =
             *(undefined4 *)((int)&local_b4.startsolid + uVar2);
        uVar2 = uVar2 + 8;
      } while (uVar2 < 0x44);
    }
  }
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  gp_tr_decal[iVar10] = (pmtrace_t *)0x0;
  if (local_f8.fraction < 1.0) {
                    /* Unresolved local var: float flVol@[???]
                       Unresolved local var: int fHitWorld@[???]
                       Unresolved local var: int ent@[???]
                       Unresolved local var: ushort m_usAxeDecal@[???] */
    uVar2 = 0;
    do {
      *(undefined4 *)((int)&g_tr_decal[iVar10].allsolid + uVar2) =
           *(undefined4 *)((int)&local_f8.allsolid + uVar2);
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x44);
    gp_tr_decal[iVar10] = g_tr_decal + iVar10;
                    /* Unresolved local var: int anim@[???] */
    qVar3 = EV_IsLocal(idx);
    if (qVar3 != 0) {
                    /* Unresolved local var: int anim@[DW_OP_reg2(EDX)] */
      if (classid < 3) {
        iVar7 = 3;
        if ((0 < classid) || (iVar7 = 2, classid == 0)) {
LAB_000761ed:
          qVar3 = EV_IsLocal(idx);
          if (qVar3 != 0) {
            (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(iVar7,2);
          }
        }
      }
      else if (classid == 3) {
        iVar4 = EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing + 1;
        iVar5 = EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing % 2;
        iVar7 = 6;
        EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing = iVar4;
        if (iVar5 != 0) {
          iVar7 = (uint)(iVar5 == 1) * 5 + 3;
        }
        goto LAB_000761ed;
      }
    }
    iVar4 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(&local_f8);
    if (classid == 1) {
      iVar5 = iVar4;
      iVar6 = EV_TFC_IsAlly(idx,iVar4);
      iVar7 = 1;
      if (iVar6 == 0) {
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
        if ((cl_localblood == (cvar_t *)0x0) || (cl_localblood->value != 0.0)) {
          EV_TFC_TraceAttack(idx,(float)local_40,(float *)&local_f8,(pmtrace_t *)0x41a00000,iVar5);
          iVar7 = 1;
        }
        else {
          iVar7 = 1;
        }
      }
    }
    else if (classid < 2) {
      if (classid != 0) goto LAB_0007624b;
LAB_0007646f:
      iVar7 = EV_TFC_AxeHit(idx,&local_34,local_40,local_4c,iVar4,local_40,&local_f8);
    }
    else if (classid == 2) {
      gp_tr_decal[iVar10] = (pmtrace_t *)0x0;
      iVar7 = EV_TFC_Medkit(idx,&local_34,local_40,local_4c,iVar4,local_40,&local_f8);
    }
    else {
      if (classid == 3) goto LAB_0007646f;
LAB_0007624b:
      iVar7 = 0;
    }
    if (gp_tr_decal[iVar10] != (pmtrace_t *)0x0) {
      uVar1 = (*(gEngfuncs.pEventAPI)->EV_PrecacheEvent)(1,"events/wpn/tf_axedecal.sc");
      (*(gEngfuncs.pEventAPI)->EV_PlaybackEvent)
                (idx,(edict_s *)0x0,uVar1,0.2,&local_34,&local_28,0.0,0.0,0,0,0,0);
    }
    if (iVar7 == 0) {
      return;
    }
    qVar3 = EV_IsPlayer(iVar4);
    if (qVar3 == 0) {
                    /* Unresolved local var: float fvolbar@[???] */
      fVar9 = EV_TFC_PlayTextureSound(idx,&local_f8,local_70,local_70,5);
      iVar10 = (*gEngfuncs.GetMaxClients)();
      fSoundData = 1.0;
      if (iVar10 < 2) {
        fSoundData = fVar9;
      }
      EV_TFC_PlayAxeSound(idx,classid,&local_34,2,fSoundData);
      return;
    }
    iVar10 = 1;
    goto LAB_0007635e;
  }
                    /* Unresolved local var: int anim@[???] */
  qVar3 = EV_IsLocal(idx);
  if (qVar3 != 0) {
                    /* Unresolved local var: int anim@[???] */
    if (classid == 1) {
      iVar10 = 1;
      goto LAB_00076421;
    }
    if (classid < 2) {
      if (classid != 0) goto LAB_00076350;
LAB_0007641c:
      iVar10 = 2;
    }
    else {
      if (classid == 2) goto LAB_0007641c;
      if (classid != 3) goto LAB_00076350;
      iVar4 = EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing + 1;
      if (EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing % 3 == 1) {
        iVar10 = 5;
        EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing = iVar4;
      }
      else if (EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing % 3 == 2) {
        iVar10 = 7;
        EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing = iVar4;
      }
      else {
        bVar8 = EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing !=
                (EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing / 3) * 3;
        iVar10 = 4;
        EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing = iVar4;
        if (bVar8) goto LAB_00076350;
      }
    }
LAB_00076421:
    qVar3 = EV_IsLocal(idx);
    if (qVar3 != 0) {
      (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(iVar10,2);
    }
  }
LAB_00076350:
  iVar10 = 0;
LAB_0007635e:
  EV_TFC_PlayAxeSound(idx,classid,&local_34,iVar10,0.0);
  return;
}


// EV_TFC_AxeDecal  @ 000766d0
void EV_TFC_AxeDecal(event_args_t *args)

{
  pmtrace_t *pTrace;
  physent_s_conflict *ppVar1;
  int iVar2;
  
                    /* Unresolved local var: int idx@[???] */
  iVar2 = args->entindex + -1;
  pTrace = gp_tr_decal[iVar2];
  if (pTrace != (pmtrace_t *)0x0) {
                    /* Unresolved local var: physent_t * pe@[???] */
    ppVar1 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent);
    if ((ppVar1 != (physent_s_conflict *)0x0) && ((ppVar1->solid == 4 || (ppVar1->movetype == 0xd)))
       ) {
      EV_TFC_DecalGunshot(pTrace,5);
    }
    gp_tr_decal[iVar2] = (pmtrace_t *)0x0;
  }
  return;
}


// EV_TFC_AxeHit  @ 00075d60
int EV_TFC_AxeHit(int idx,float *origin,float *forward,float *right,int entity,float *vecDir,
                 pmtrace_t *ptr)

{
  int iVar1;
  cl_entity_s *pcVar2;
  qboolean qVar3;
  int in_stack_ffffffb8;
  float *bitsDamageType;
  float local_30 [3];
  float local_24 [3];
  float local_18;
  float local_14;
  
                    /* Unresolved local var: cl_entity_t * player@[???] */
  if ((((entity < 1) || (iVar1 = (*gEngfuncs.GetMaxClients)(), iVar1 < entity)) ||
      (pcVar2 = GetEntity(entity + -1), pcVar2 == (cl_entity_s *)0x0)) ||
     ((pcVar2->curstate).playerclass != 8)) {
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
    if ((cl_localblood == (cvar_t *)0x0) || (cl_localblood->value != 0.0)) {
      EV_TFC_TraceAttack(idx,(float)vecDir,(float *)ptr,(pmtrace_t *)0x41a00000,in_stack_ffffffb8);
    }
  }
  else {
                    /* Unresolved local var: Vector tf@[???]
                       Unresolved local var: Vector tu@[???]
                       Unresolved local var: Vector tr@[???]
                       Unresolved local var: int anim@[???]
                       Unresolved local var: float flResult@[???] */
    bitsDamageType = local_30;
    (*gEngfuncs.pfnAngleVectors)(&(pcVar2->curstate).angles.x,bitsDamageType,local_24,&local_18);
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
    if (local_18 * forward[1] - *forward * local_14 <= 0.0) {
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
      if ((cl_localblood == (cvar_t *)0x0) || (cl_localblood->value != 0.0)) {
        EV_TFC_TraceAttack(idx,(float)vecDir,(float *)ptr,(pmtrace_t *)0x42200000,
                           (int)bitsDamageType);
      }
      iVar1 = 2;
    }
    else {
      if ((cl_localblood == (cvar_t *)0x0) || (cl_localblood->value != 0.0)) {
        EV_TFC_TraceAttack(idx,(float)vecDir,(float *)ptr,(pmtrace_t *)0x42f00000,
                           (int)bitsDamageType);
      }
      iVar1 = 3;
    }
    qVar3 = EV_IsLocal(idx);
    if (qVar3 != 0) {
      (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(iVar1,2);
    }
  }
  return 1;
}


// EV_TFC_BenchMarkTrace  @ 00076eb0
void EV_TFC_BenchMarkTrace(pmtrace_t *pTrace)

{
  physent_s_conflict *ppVar1;
  
                    /* Unresolved local var: physent_t * pe@[???] */
  ppVar1 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent);
  if ((ppVar1 != (physent_s_conflict *)0x0) && ((ppVar1->solid == 4 || (ppVar1->movetype == 0xd))))
  {
    EV_TFC_BenchmarkWallMark(pTrace,"{dot");
    return;
  }
  return;
}


// EV_TFC_BenchmarkWallMark  @ 00076df0
void EV_TFC_BenchmarkWallMark(pmtrace_t *pTrace,char *name)

{
  _func_int_int *p_Var1;
  _func_void_int_int_int_float_ptr_int *p_Var2;
  int iVar3;
  longdouble lVar4;
  
  if (((name != (char *)0x0) && (*name != '\0')) && (pTrace->fraction != 1.0)) {
    (pTrace->endpos).z = (pTrace->endpos).z + g_fZAdjust;
    lVar4 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("r_decals");
    if (lVar4 != (longdouble)0) {
      p_Var1 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
      p_Var2 = (gEngfuncs.pEfxAPI)->R_DecalShoot;
      iVar3 = (*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)(name);
      iVar3 = (*p_Var1)(iVar3);
      (*p_Var2)(iVar3,0,0,&(pTrace->endpos).x,0);
    }
  }
  return;
}


// EV_TFC_BloodDecalTrace  @ 0006ff70
void EV_TFC_BloodDecalTrace(pmtrace_t *pTrace,int bloodColor)

{
  _func_void_int_int_int_float_ptr_int *p_Var1;
  _func_int_int *p_Var2;
  int32 iVar3;
  physent_s_conflict *ppVar4;
  int iVar5;
  int iVar6;
  longdouble lVar7;
  char *__format;
  char local_3c [44];
  
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: char[32] decalname@[???] */
  iVar3 = (*gEngfuncs.pfnRandomLong)(0,5);
  if (bloodColor != -1) {
    if (bloodColor == 0xf7) {
      lVar7 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("violence_hblood");
      if (lVar7 == (longdouble)0) {
        return;
      }
      __format = "{blood%i";
    }
    else {
      lVar7 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("violence_ablood");
      if (lVar7 == (longdouble)0) {
        return;
      }
      __format = "{yblood%i";
    }
    sprintf(local_3c,__format,iVar3 + 1);
                    /* Unresolved local var: physent_t * pe@[DW_OP_reg0(EAX)] */
                    /* Unresolved local var: physent_t * pe@[???] */
    if ((((local_3c[0] != '\0') &&
         (ppVar4 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent),
         ppVar4 != (physent_s_conflict *)0x0)) &&
        ((ppVar4->solid == 4 || (ppVar4->movetype == 0xd)))) &&
       (lVar7 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("r_decals"), lVar7 != (longdouble)0)) {
                    /* Unresolved local var: physent_t * pe@[???] */
      p_Var1 = (gEngfuncs.pEfxAPI)->R_DecalShoot;
      iVar5 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(pTrace);
      p_Var2 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
      iVar6 = (*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)(local_3c);
      iVar6 = (*p_Var2)(iVar6);
      (*p_Var1)(iVar6,iVar5,0,&(pTrace->endpos).x,0);
    }
  }
  return;
}


// EV_TFC_BloodDrips  @ 0006ec70
void __regparm3 EV_TFC_BloodDrips(float *origin,int color,int amount)

{
  float fVar1;
  int iVar2;
  int iVar3;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: int drop@[???]
                       Unresolved local var: int spray@[???]
                       Unresolved local var: float size@[???] */
  (*gEngfuncs.pfnGetCvarFloat)("violence_hblood");
  if ((extraout_ST0 != (longdouble)0) && (color != 0)) {
    iVar2 = (*gEngfuncs.GetMaxClients)();
    if (1 < iVar2) {
      color = color * 2;
    }
    if (color < 0x100) {
      iVar2 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/bloodspray.spr");
      iVar3 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/blood.spr");
      if (color < 0xa0) {
        fVar1 = 3.0;
        if (0x1d < color) {
          fVar1 = (float)(color / 10);
        }
      }
      else {
        fVar1 = 16.0;
      }
    }
    else {
      iVar2 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/bloodspray.spr");
      iVar3 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/blood.spr");
      fVar1 = 16.0;
    }
    (*(gEngfuncs.pEfxAPI)->R_BloodSprite)(origin,0xf7,iVar2,iVar3,fVar1);
    return;
  }
  return;
}


// EV_TFC_BloodDrips  @ 0006fdd0
void EV_TFC_BloodDrips(float *origin,int color,int amount)

{
  float fVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  
                    /* Unresolved local var: int drop@[???]
                       Unresolved local var: int spray@[???]
                       Unresolved local var: float size@[???] */
  if (color == -1) {
    return;
  }
  if (color == 0xf7) {
    (*gEngfuncs.pfnGetCvarFloat)("violence_hblood");
    bVar4 = extraout_ST0_00 == (longdouble)0;
    if (NAN(extraout_ST0_00) || NAN((longdouble)0)) goto LAB_0006fe40;
  }
  else {
    (*gEngfuncs.pfnGetCvarFloat)("violence_ablood");
    bVar4 = extraout_ST0 == (longdouble)0;
    if (NAN(extraout_ST0) || NAN((longdouble)0)) goto LAB_0006fe40;
  }
  if (bVar4) {
    return;
  }
LAB_0006fe40:
  if (amount == 0) {
    return;
  }
  iVar2 = (*gEngfuncs.GetMaxClients)();
  if (1 < iVar2) {
    amount = amount * 2;
  }
  if (amount < 0x100) {
    iVar2 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/bloodspray.spr");
    iVar3 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/blood.spr");
    if (amount < 0xa0) {
      fVar1 = 3.0;
      if (0x1d < amount) {
        fVar1 = (float)(amount / 10);
      }
    }
    else {
      fVar1 = 16.0;
    }
  }
  else {
    iVar2 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/bloodspray.spr");
    iVar3 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/blood.spr");
    fVar1 = 16.0;
  }
  (*(gEngfuncs.pEfxAPI)->R_BloodSprite)(origin,color,iVar2,iVar3,fVar1);
  return;
}


// EV_TFC_BubbleTrail  @ 000714d0
void EV_TFC_BubbleTrail(float *from,float *to,int count,int modelindex)

{
  int iVar1;
  float fVar2;
  
                    /* Unresolved local var: float flHeight@[???] */
  fVar2 = EV_TFC_WaterLevel(from,from[2],from[2] + 256.0);
  fVar2 = fVar2 - from[2];
  if (fVar2 < 8.0) {
    fVar2 = EV_TFC_WaterLevel(to,to[2],to[2] + 256.0);
    fVar2 = fVar2 - to[2];
    if (fVar2 < 8.0) {
      return;
    }
    fVar2 = (to[2] + fVar2) - from[2];
  }
  iVar1 = 0xff;
  if (count < 0x100) {
    iVar1 = count;
  }
  (*(gEngfuncs.pEfxAPI)->R_BubbleTrail)(from,to,fVar2,modelindex,iVar1,8.0);
  return;
}


// EV_TFC_BuildingEvent  @ 000772e0
void EV_TFC_BuildingEvent(event_args_t *args)

{
  int *piVar1;
  uint uVar2;
  eventnode_t *peVar3;
  eventnode_s *peVar4;
  event_args_t *peVar5;
  uint uVar6;
  event_args_t *peVar7;
  undefined2 *puVar8;
  undefined4 *puVar9;
  event_args_t *peVar10;
  undefined2 *puVar11;
  eventnode_t *peVar12;
  eventnode_s *peVar13;
  uint uVar14;
  int iVar15;
  bool bVar16;
  
  peVar3 = g_pEventListHead;
                    /* Unresolved local var: eventnode_t * temp@[???] */
  if (args != (event_args_t *)0x0) {
                    /* Unresolved local var: eventnode_t * node@[???] */
    if (g_pEventListHead == (eventnode_t *)0x0) {
LAB_0007731e:
                    /* Unresolved local var: eventnode_t * pEventNode@[???] */
      if ((args->bparam1 != 0) && (peVar4 = operator_new(0xc), peVar4 != (eventnode_s *)0x0)) {
                    /* Unresolved local var: event_args_t * pEventData@[???] */
        peVar4->data = (event_args_t *)0x0;
        peVar4->prev = (eventnode_s *)0x0;
        peVar4->next = (eventnode_s *)0x0;
        peVar5 = operator_new(0x48);
        if (peVar5 == (event_args_t *)0x0) {
          operator_delete(peVar4);
          return;
        }
        bVar16 = ((uint)peVar5 & 1) != 0;
        uVar14 = 0x48;
        peVar7 = peVar5;
        if (bVar16) {
          *(undefined1 *)&peVar5->flags = 0;
          peVar7 = (event_args_t *)((int)&peVar5->flags + 1);
          uVar14 = 0x47;
        }
        if (((uint)peVar7 & 2) != 0) {
          *(undefined2 *)&peVar7->flags = 0;
          uVar14 = uVar14 - 2;
          peVar7 = (event_args_t *)((int)&peVar7->flags + 2);
        }
        uVar2 = 0;
        do {
          uVar6 = uVar2;
          *(undefined4 *)((int)peVar7->origin + (uVar6 - 8)) = 0;
          *(undefined4 *)((int)peVar7->origin + (uVar6 - 4)) = 0;
          *(undefined4 *)((int)peVar7->origin + uVar6) = 0;
          *(undefined4 *)((int)peVar7->origin + uVar6 + 4) = 0;
          uVar2 = uVar6 + 0x10;
        } while (uVar6 + 0x10 < (uVar14 & 0xfffffff0));
        puVar9 = (undefined4 *)((int)peVar7->origin + uVar6 + 8);
        if ((uVar14 & 8) != 0) {
          *puVar9 = 0;
          puVar9[1] = 0;
          puVar9 = puVar9 + 2;
        }
        if ((uVar14 & 4) != 0) {
          *puVar9 = 0;
          puVar9 = puVar9 + 1;
        }
        if ((uVar14 & 2) != 0) {
          *(undefined2 *)puVar9 = 0;
          puVar9 = (undefined4 *)((int)puVar9 + 2);
        }
        if (bVar16) {
          *(undefined1 *)puVar9 = 0;
        }
        bVar16 = ((uint)peVar5 & 1) != 0;
        uVar14 = 0x48;
        peVar7 = args;
        peVar10 = peVar5;
        if (bVar16) {
          peVar7 = (event_args_t *)((int)&args->flags + 1);
          uVar14 = 0x47;
          *(char *)&peVar5->flags = (char)args->flags;
          peVar10 = (event_args_t *)((int)&peVar5->flags + 1);
        }
        if (((uint)peVar10 & 2) != 0) {
          piVar1 = &peVar7->flags;
          uVar14 = uVar14 - 2;
          peVar7 = (event_args_t *)((int)&peVar7->flags + 2);
          *(short *)&peVar10->flags = (short)*piVar1;
          peVar10 = (event_args_t *)((int)&peVar10->flags + 2);
        }
        uVar2 = 0;
        do {
          uVar6 = uVar2;
          *(undefined4 *)((int)peVar10->origin + (uVar6 - 8)) =
               *(undefined4 *)((int)peVar7->origin + (uVar6 - 8));
          uVar2 = uVar6 + 4;
        } while (uVar6 + 4 < (uVar14 & 0xfffffffc));
        puVar11 = (undefined2 *)((int)peVar10->origin + (uVar6 - 4));
        puVar8 = (undefined2 *)((int)peVar7->origin + (uVar6 - 4));
        iVar15 = 0;
        if ((uVar14 & 2) != 0) {
          *puVar11 = *puVar8;
          iVar15 = 2;
        }
        if (bVar16) {
          *(undefined1 *)((int)puVar11 + iVar15) = *(undefined1 *)((int)puVar8 + iVar15);
        }
        peVar4->data = peVar5;
        if ((args->iparam1 & 0x800) != 0) {
          peVar5->entindex = (int)args->fparam1;
          piVar1 = &peVar4->data->iparam1;
          *piVar1 = *piVar1 & 0xfffff7ff;
        }
        peVar3 = g_pEventListHead;
        if (g_pEventListHead == (eventnode_t *)0x0) {
          g_pEventListHead = peVar4;
          peVar4->next = (eventnode_s *)0x0;
          peVar4->prev = (eventnode_s *)0x0;
        }
        else {
          do {
            peVar12 = peVar3;
            peVar3 = peVar12->next;
          } while (peVar12->next != (eventnode_s *)0x0);
          peVar4->prev = peVar12;
          peVar4->next = (eventnode_s *)0x0;
          peVar12->next = peVar4;
        }
      }
    }
    else {
      peVar5 = g_pEventListHead->data;
      iVar15 = peVar5->entindex;
      peVar4 = g_pEventListHead;
      while (args->entindex != iVar15) {
        peVar4 = peVar4->next;
        if (peVar4 == (eventnode_s *)0x0) goto LAB_0007731e;
        peVar5 = peVar4->data;
        iVar15 = peVar5->entindex;
      }
      uVar14 = args->iparam1;
      if (args->bparam1 != 1) {
        if ((uVar14 & 0x100) != 0) {
          peVar5->origin[0] = args->origin[0];
          peVar4->data->origin[1] = args->origin[1];
          peVar4->data->origin[2] = args->origin[2];
          return;
        }
        if ((uVar14 & 0x400) == 0) {
          peVar5->iparam1 = peVar5->iparam1 & ~uVar14;
          if ((args->iparam1 & 0x200) != 0) {
            peVar4->data->bparam2 = 0;
          }
          if (peVar4->data->iparam1 != 0) {
            return;
          }
        }
        if (peVar3 == peVar4) {
          g_pEventListHead = (eventnode_t *)0x0;
          if (peVar4->next != (eventnode_s *)0x0) {
            peVar4->next->prev = (eventnode_s *)0x0;
            g_pEventListHead = peVar4->next;
          }
        }
        else {
          if (peVar4->next == (eventnode_s *)0x0) {
            peVar13 = peVar4->prev;
          }
          else {
            if (peVar4->prev != (eventnode_s *)0x0) {
              peVar4->next->prev = peVar4->prev;
              peVar4->prev->next = peVar4->next;
              goto LAB_00077396;
            }
            peVar13 = (eventnode_s *)0x0;
          }
          peVar13->next = (eventnode_s *)0x0;
        }
LAB_00077396:
        free(peVar4);
        return;
      }
      peVar5->iparam1 = peVar5->iparam1 | uVar14;
      peVar4->data->iparam2 = args->iparam2;
      uVar14 = args->iparam1;
      if ((uVar14 & 0x200) != 0) {
        peVar4->data->bparam2 = args->bparam2;
        uVar14 = args->iparam1;
      }
      if ((uVar14 & 0x800) != 0) {
        peVar4->data->entindex = (int)args->fparam1;
        piVar1 = &peVar4->data->iparam1;
        *piVar1 = *piVar1 & 0xfffff7ff;
        return;
      }
    }
  }
  return;
}


// EV_TFC_CheckTracer  @ 0006fc50
int EV_TFC_CheckTracer(int idx,float *vecSrc,float *end,float *forward,float *right,int iBulletType,
                      int iTracerFreq,int *tracerCount)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
                    /* Unresolved local var: int tracer@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: qboolean player@[???] */
  bVar1 = false;
  if (0 < idx) {
    iVar2 = (*gEngfuncs.GetMaxClients)();
    bVar1 = idx <= iVar2;
  }
  uVar3 = 0;
  if ((iTracerFreq != 0) &&
     (iVar2 = *tracerCount, *tracerCount = iVar2 + 1, iVar2 % iTracerFreq == 0)) {
                    /* Unresolved local var: Vector vecTracerSrc@[???] */
    if (bVar1) {
                    /* Unresolved local var: Vector offset@[???] */
      local_2c = 0;
      local_28 = 0;
      local_24 = 0xc0800000;
      local_3c = *forward * 16.0 + *right + *right + *vecSrc + 0.0;
      local_38 = forward[1] * 16.0 + right[1] + right[1] + vecSrc[1] + 0.0;
      local_34 = forward[2] * 16.0 + right[2] + right[2] + vecSrc[2] + -4.0;
    }
    else {
      local_3c = *vecSrc;
      local_38 = vecSrc[1];
      local_34 = vecSrc[2];
    }
    uVar3 = (uint)(iTracerFreq != 1);
    if (iBulletType != 6) {
      EV_CreateTracer(&local_3c,end);
    }
  }
  return uVar3;
}


// EV_TFC_ClientProjectile  @ 000715b0
void EV_TFC_ClientProjectile
               (float *vecOrigin,float *vecVelocity,short sModelIndex,int iOwnerIndex,int iLife,
               _func_void_tempent_s_ptr_pmtrace_t_ptr *hitcallback)

{
                    /* WARNING: Could not recover jumptable at 0x000715d1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(gEngfuncs.pEfxAPI)->R_Projectile)
            (vecOrigin,vecVelocity,(int)sModelIndex,iLife,iOwnerIndex,
             (_func_void_tempent_s_ptr_pmtrace_s_ptr *)hitcallback);
  return;
}


// EV_TFC_Concussion  @ 00073c40
void EV_TFC_Concussion(event_args_t *args)

{
  int iVar1;
  int32 iVar2;
  char *pcVar3;
  pmtrace_s local_74;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector upV@[???]
                       Unresolved local var: Vector downV@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int blast@[???]
                       Unresolved local var: Vector origin@[???] */
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  iVar1 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/shockwave.spr");
  local_24 = local_18 + 0.0;
  local_20 = local_14 + 0.0;
  local_1c = local_10 + 8.0;
  local_30 = local_24 + 0.0;
  local_2c = local_20 + 0.0;
  local_28 = local_1c - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_24,&local_30,2,-1,&local_74);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  iVar2 = (*gEngfuncs.pfnRandomLong)(0,2);
  if (iVar2 == 1) {
    pcVar3 = "weapons/concgren_blast2.wav";
  }
  else if (iVar2 == 2) {
    pcVar3 = "weapons/concgren_blast3.wav";
  }
  else {
    if (iVar2 != 0) goto LAB_00073da5;
    pcVar3 = "weapons/concgren_blast1.wav";
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(-1,&local_18,2,pcVar3,1.0,0.8,0,100);
LAB_00073da5:
  local_1c = local_10 + 16.0;
  local_20 = local_14;
  local_28 = local_1c + 600.0;
  local_2c = local_14;
  local_24 = local_18;
  local_30 = local_18;
  (*(gEngfuncs.pEfxAPI)->R_BeamCirclePoints)
            (0x15,&local_24,&local_30,iVar1,0.2,70.0,0.0,1.0,0.0,0,0.0,1.0,1.0,1.0);
  return;
}


// EV_TFC_CreateGib  @ 000768d0
tempent_s * EV_TFC_CreateGib(float *origin,float *attackdir,int multiplier,int ishead)

{
  float fVar1;
  vec_t vVar2;
  model_s *pmVar3;
  TEMPENTITY *pTVar4;
  int32 iVar5;
  Vector *v;
  longdouble lVar6;
  longdouble lVar7;
  float fVar8;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  int local_10 [2];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: TEMPENTITY * pGib@[???]
                       Unresolved local var: model_s * model@[???]
                       Unresolved local var: float[3] mins0@[???]
                       Unresolved local var: float[3] maxs0@[???]
                       Unresolved local var: float extent@[???]
                       Unresolved local var: int modelindex@[???]
                       Unresolved local var: float vmultiple@[???] */
  pmVar3 = (*gEngfuncs.CL_LoadModel)("models/hgibs.mdl",local_10);
  if (pmVar3 == (model_s *)0x0) {
    pTVar4 = (TEMPENTITY *)0x0;
  }
  else {
    fVar8 = 4.0;
    if (multiplier - 1U < 2) {
      fVar8 = *(float *)((int)&CSWTCH_208 + (multiplier - 1U) * 4);
    }
    fVar8 = fVar8 * cl_gibvelscale->value;
    (*(gEngfuncs.pEventAPI)->EV_LocalPlayerBounds)(0,&local_28,&local_1c);
    pTVar4 = (*(gEngfuncs.pEfxAPI)->CL_TentEntAllocCustom)(origin,pmVar3,0,EV_TFC_GibCallback);
    if (pTVar4 != (TEMPENTITY *)0x0) {
      if (ishead == 0) {
        iVar5 = (*gEngfuncs.pfnRandomLong)(1,5);
        (pTVar4->entity).curstate.body = iVar5;
      }
      else {
        (pTVar4->entity).curstate.body = 0;
      }
      fVar1 = (pTVar4->entity).origin.x;
      lVar6 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-1.0,1.0);
      (pTVar4->entity).origin.x =
           (float)((longdouble)0.5 * (longdouble)(local_1c - local_28) * lVar6 + (longdouble)fVar1);
      fVar1 = (pTVar4->entity).origin.y;
      lVar6 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-1.0,1.0);
      (pTVar4->entity).origin.y =
           (float)((longdouble)0.5 * (longdouble)(local_18 - local_24) * lVar6 + (longdouble)fVar1);
      fVar1 = (pTVar4->entity).origin.z;
      lVar6 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-1.0,1.0);
      (pTVar4->entity).origin.z =
           (float)((longdouble)0.5 * (longdouble)(local_14 - local_20) * lVar6 + (longdouble)fVar1);
      if (ishead == 0) {
        VectorScale(attackdir,-1.0,&(pTVar4->entity).curstate.velocity.x);
        fVar1 = (pTVar4->entity).curstate.velocity.x;
        lVar6 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-0.25,0.25);
        lVar6 = (longdouble)fVar1 + lVar6;
        (pTVar4->entity).curstate.velocity.x = (float)lVar6;
        lVar7 = (longdouble)(*gEngfuncs.pfnRandomFloat)(300.0,400.0);
        (pTVar4->entity).curstate.velocity.x =
             (float)((longdouble)(float)lVar6 * lVar7 * (longdouble)fVar8);
        fVar1 = (pTVar4->entity).curstate.velocity.y;
        lVar6 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-0.25,0.25);
        lVar6 = (longdouble)fVar1 + lVar6;
        (pTVar4->entity).curstate.velocity.y = (float)lVar6;
        lVar7 = (longdouble)(*gEngfuncs.pfnRandomFloat)(300.0,400.0);
        (pTVar4->entity).curstate.velocity.y =
             (float)((longdouble)(float)lVar6 * lVar7 * (longdouble)fVar8);
        fVar1 = (pTVar4->entity).curstate.velocity.z;
        lVar6 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-0.25,0.25);
        lVar6 = (longdouble)fVar1 + lVar6;
        (pTVar4->entity).curstate.velocity.z = (float)lVar6;
        lVar7 = (longdouble)(*gEngfuncs.pfnRandomFloat)(300.0,400.0);
        (pTVar4->entity).curstate.velocity.z =
             (float)((longdouble)(float)lVar6 * lVar7 * (longdouble)fVar8);
        lVar6 = (longdouble)(*gEngfuncs.pfnRandomFloat)(100.0,200.0);
        (pTVar4->entity).baseline.angles.x = (float)lVar6;
        lVar6 = (longdouble)(*gEngfuncs.pfnRandomFloat)(100.0,200.0);
        (pTVar4->entity).baseline.angles.y = (float)lVar6;
      }
      else {
        lVar6 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-100.0,100.0);
        (pTVar4->entity).curstate.velocity.x = (float)lVar6;
        lVar6 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-100.0,100.0);
        (pTVar4->entity).curstate.velocity.y = (float)lVar6;
        lVar6 = (longdouble)(*gEngfuncs.pfnRandomFloat)(200.0,300.0);
        (pTVar4->entity).curstate.velocity.z = (float)lVar6;
        lVar6 = (longdouble)(*gEngfuncs.pfnRandomFloat)(100.0,200.0);
        (pTVar4->entity).baseline.angles.x = (float)lVar6;
        lVar6 = (longdouble)(*gEngfuncs.pfnRandomFloat)(100.0,300.0);
        (pTVar4->entity).baseline.angles.y = (float)lVar6;
      }
                    /* Unresolved local var: float length@[???] */
      v = &(pTVar4->entity).curstate.velocity;
      fVar8 = Length(&v->x);
      if (1500.0 < fVar8) {
        VectorScale(&v->x,1500.0 / fVar8,&v->x);
      }
      vVar2 = (pTVar4->entity).curstate.velocity.x;
      fVar8 = pTVar4->die;
      pTVar4->flags = pTVar4->flags | 0x26;
      (pTVar4->entity).baseline.origin.x = vVar2;
      vVar2 = (pTVar4->entity).curstate.velocity.y;
      pTVar4->hitcallback = EV_TFC_GibTouchCallback;
      (pTVar4->entity).curstate.team = 5;
      pTVar4->die = fVar8 + 1.0;
      (pTVar4->entity).baseline.origin.y = vVar2;
      (pTVar4->entity).baseline.origin.z = (pTVar4->entity).curstate.velocity.z;
      (pTVar4->entity).curstate.solid = 0;
      (pTVar4->entity).curstate.playerclass = 0;
    }
  }
  return pTVar4;
}


// EV_TFC_DamageDecal  @ 0006fa50
char * EV_TFC_DamageDecal(int entity,int bitsDamageType)

{
  physent_s_conflict *ppVar1;
  int32 iVar2;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
  EV_TFC_DamageDecal::lexical_block_0::decalname._0_4_ =
       EV_TFC_DamageDecal::lexical_block_0::decalname._0_4_ & 0xffffff00;
  ppVar1 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(entity);
  if ((ppVar1 != (physent_s_conflict *)0x0) && (ppVar1->rendermode != 4)) {
    if (ppVar1->rendermode != 0) {
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
      builtin_strncpy(EV_TFC_DamageDecal::lexical_block_0::decalname,"{bproof1",9);
      return EV_TFC_DamageDecal::lexical_block_0::decalname;
    }
    iVar2 = (*gEngfuncs.pfnRandomLong)(0,4);
    sprintf(EV_TFC_DamageDecal::lexical_block_0::decalname,"{shot%i",iVar2 + 1);
  }
  return EV_TFC_DamageDecal::lexical_block_0::decalname;
}


// EV_TFC_DecalGunshot  @ 0006ef60
/* WARNING: Removing unreachable block (ram,0x0006f170) */

void __regparm3 EV_TFC_DecalGunshot(pmtrace_t *pTrace,int iBulletType)

{
  _func_void_int_int_int_float_ptr_int *p_Var1;
  _func_int_int *p_Var2;
  physent_s_conflict *ppVar3;
  int32 iVar4;
  int iVar5;
  int iVar6;
  char *name;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: physent_t * pe@[???] */
  if (iBulletType == 7) {
    if (pTrace->fraction == 1.0) {
      return;
    }
    name = "hwshot1";
    goto LAB_0006f00a;
  }
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
  EV_TFC_DamageDecal::lexical_block_0::decalname._0_4_ =
       EV_TFC_DamageDecal::lexical_block_0::decalname._0_4_ & 0xffffff00;
  if ((iBulletType != 10) && (iBulletType == 5)) {
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
    ppVar3 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent);
    if ((ppVar3 != (physent_s_conflict *)0x0) && (ppVar3->rendermode != 4)) {
      if (ppVar3->rendermode == 0) {
        iVar4 = (*gEngfuncs.pfnRandomLong)(0,4);
        sprintf(EV_TFC_DamageDecal::lexical_block_0::decalname,"{shot%i",iVar4 + 1);
      }
      else {
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
        builtin_strncpy(EV_TFC_DamageDecal::lexical_block_0::decalname,"{bproof1",9);
      }
    }
                    /* Unresolved local var: physent_t * pe@[???] */
    if (EV_TFC_DamageDecal::lexical_block_0::decalname[0] == '\0') {
      return;
    }
    ppVar3 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent);
    if (ppVar3 == (physent_s_conflict *)0x0) {
      return;
    }
    if ((ppVar3->solid != 4) && (ppVar3->movetype != 0xd)) {
      return;
    }
    (*gEngfuncs.pfnGetCvarFloat)("r_decals");
    if (extraout_ST0 == (longdouble)0) {
      return;
    }
                    /* Unresolved local var: physent_t * pe@[???] */
    p_Var1 = (gEngfuncs.pEfxAPI)->R_DecalShoot;
    iVar5 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(pTrace);
    p_Var2 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
    iVar6 = (*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)
                      (EV_TFC_DamageDecal::lexical_block_0::decalname);
    iVar6 = (*p_Var2)(iVar6);
    (*p_Var1)(iVar6,iVar5,0,&(pTrace->endpos).x,0);
    return;
  }
  ppVar3 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent);
  if ((ppVar3 == (physent_s_conflict *)0x0) || (ppVar3->rendermode == 4)) {
LAB_0006efe5:
                    /* Unresolved local var: int iRand@[???]
                       Unresolved local var: physent_t * pe@[???] */
    if (EV_TFC_DamageDecal::lexical_block_0::decalname[0] == '\0') {
      return;
    }
  }
  else {
    if (ppVar3->rendermode == 0) {
      iVar4 = (*gEngfuncs.pfnRandomLong)(0,4);
      sprintf(EV_TFC_DamageDecal::lexical_block_0::decalname,"{shot%i",iVar4 + 1);
      goto LAB_0006efe5;
    }
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
    builtin_strncpy(EV_TFC_DamageDecal::lexical_block_0::decalname,"{bproof1",9);
  }
  if (pTrace->fraction == 1.0) {
    return;
  }
  name = EV_TFC_DamageDecal::lexical_block_0::decalname;
LAB_0006f00a:
                    /* Unresolved local var: int iRand@[???]
                       Unresolved local var: physent_t * pe@[???] */
  EV_TFC_GunshotDecalTrace(pTrace,name);
  return;
}


// EV_TFC_DecalGunshot  @ 0006fbf0
void EV_TFC_DecalGunshot(pmtrace_t *pTrace,int iBulletType)

{
  physent_s_conflict *ppVar1;
  
                    /* Unresolved local var: physent_t * pe@[???] */
  ppVar1 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent);
  if ((ppVar1 != (physent_s_conflict *)0x0) && ((ppVar1->solid == 4 || (ppVar1->movetype == 0xd))))
  {
    EV_TFC_DecalGunshot(pTrace,iBulletType);
    return;
  }
  return;
}


// EV_TFC_DecalTrace  @ 0006fb20
void EV_TFC_DecalTrace(pmtrace_t *pTrace,char *name)

{
  _func_void_int_int_int_float_ptr_int *p_Var1;
  _func_int_int *p_Var2;
  physent_s_conflict *ppVar3;
  int iVar4;
  int iVar5;
  longdouble lVar6;
  
                    /* Unresolved local var: physent_t * pe@[???] */
  if ((((name != (char *)0x0) && (*name != '\0')) &&
      (ppVar3 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent),
      ppVar3 != (physent_s_conflict *)0x0)) &&
     (((ppVar3->solid == 4 || (ppVar3->movetype == 0xd)) &&
      (lVar6 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("r_decals"), lVar6 != (longdouble)0)))) {
                    /* Unresolved local var: physent_t * pe@[???] */
    p_Var1 = (gEngfuncs.pEfxAPI)->R_DecalShoot;
    iVar4 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(pTrace);
    p_Var2 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
    iVar5 = (*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)(name);
    iVar5 = (*p_Var2)(iVar5);
    (*p_Var1)(iVar5,iVar4,0,&(pTrace->endpos).x,0);
  }
  return;
}


// EV_TFC_DoorGoDown  @ 00073390
void EV_TFC_DoorGoDown(event_args_t *args)

{
  int index;
  _func_void_int_int_char_ptr *p_Var1;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var2;
  char *pcVar3;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: int soundindex@[???] */
  index = args->iparam1;
  p_Var1 = (gEngfuncs.pEventAPI)->EV_StopSound;
  pcVar3 = EV_TFC_LookupDoorSound(0,index);
  (*p_Var1)(-1,6,pcVar3);
  p_Var2 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  pcVar3 = EV_TFC_LookupDoorSound(0,index);
  (*p_Var2)(-1,args->origin,6,pcVar3,1.0,0.8,0,100);
  return;
}


// EV_TFC_DoorGoUp  @ 000732e0
void EV_TFC_DoorGoUp(event_args_t *args)

{
  int index;
  _func_void_int_int_char_ptr *p_Var1;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var2;
  char *pcVar3;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: int soundindex@[???] */
  index = args->iparam1;
  p_Var1 = (gEngfuncs.pEventAPI)->EV_StopSound;
  pcVar3 = EV_TFC_LookupDoorSound(0,index);
  (*p_Var1)(-1,6,pcVar3);
  p_Var2 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  pcVar3 = EV_TFC_LookupDoorSound(0,index);
  (*p_Var2)(-1,args->origin,6,pcVar3,1.0,0.8,0,100);
  return;
}


// EV_TFC_DoorHitBottom  @ 000734f0
void EV_TFC_DoorHitBottom(event_args_t *args)

{
  int index;
  _func_void_int_int_char_ptr *p_Var1;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var2;
  char *pcVar3;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: int soundindex@[???] */
  index = args->iparam1;
  p_Var1 = (gEngfuncs.pEventAPI)->EV_StopSound;
  pcVar3 = EV_TFC_LookupDoorSound(0,index);
  (*p_Var1)(-1,6,pcVar3);
  p_Var2 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  pcVar3 = EV_TFC_LookupDoorSound(1,index);
  (*p_Var2)(-1,args->origin,6,pcVar3,1.0,0.8,0,100);
  return;
}


// EV_TFC_DoorHitTop  @ 00073440
void EV_TFC_DoorHitTop(event_args_t *args)

{
  int index;
  _func_void_int_int_char_ptr *p_Var1;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var2;
  char *pcVar3;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: int soundindex@[???] */
  index = args->iparam1;
  p_Var1 = (gEngfuncs.pEventAPI)->EV_StopSound;
  pcVar3 = EV_TFC_LookupDoorSound(0,index);
  (*p_Var1)(-1,6,pcVar3);
  p_Var2 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  pcVar3 = EV_TFC_LookupDoorSound(1,index);
  (*p_Var2)(-1,args->origin,6,pcVar3,1.0,0.8,0,100);
  return;
}


// EV_TFC_EMP  @ 000747e0
void EV_TFC_EMP(event_args_t *args)

{
  int iVar1;
  pmtrace_s local_84;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector upV@[???]
                       Unresolved local var: Vector downV@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int blast@[???]
                       Unresolved local var: Vector origin@[???] */
  local_28 = args->origin[0];
  local_24 = args->origin[1];
  local_20 = args->origin[2];
  iVar1 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/shockwave.spr");
  local_34 = local_28 + 0.0;
  local_30 = local_24 + 0.0;
  local_2c = local_20 + 8.0;
  local_40 = local_34 + 0.0;
  local_3c = local_30 + 0.0;
  local_38 = local_2c - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_34,&local_40,2,-1,&local_84);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(-1,&local_28,2,"weapons/emp_1.wav",1.0,0.8,0,100);
  local_2c = local_20 + 16.0;
  local_34 = local_28;
  local_38 = local_2c + 600.0;
  local_30 = local_24;
  local_40 = local_28;
  local_3c = local_24;
  (*(gEngfuncs.pEfxAPI)->R_BeamCirclePoints)
            (0x15,&local_34,&local_40,iVar1,0.2,70.0,0.0,1.0,0.0,0,0.0,1.0,1.0,0.0);
  return;
}


// EV_TFC_EngineerGrenade  @ 00073b60
void EV_TFC_EngineerGrenade(event_args_t *args)

{
  pmtrace_t *pTrace;
  int bitsDamageType;
  pmtrace_s local_74;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector upV@[???]
                       Unresolved local var: Vector downV@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: Vector origin@[???] */
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  local_24 = local_18 + 0.0;
  local_20 = local_14 + 0.0;
  local_1c = local_10 + 8.0;
  local_30 = local_24 + 0.0;
  local_2c = local_20 + 0.0;
  local_28 = local_1c - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  bitsDamageType = 2;
  pTrace = (pmtrace_t *)&local_30;
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_24,(float *)pTrace,2,-1,&local_74);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  EV_TFC_Explode(&local_18,0xb4,(float)&local_74,0x429c0000,pTrace,bitsDamageType);
  return;
}


// EV_TFC_Explode  @ 0006f1a0
void __regparm3
EV_TFC_Explode(float *org,int dmg,float fExplosionScale,qboolean bDontSpark,pmtrace_t *pTrace,
              int bitsDamageType)

{
  int iVar1;
  int32 iVar2;
  physent_s_conflict *ppVar3;
  int iVar4;
  _func_void_int_int_int_float_ptr_int *p_Var5;
  bool bVar6;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  char *pcVar7;
  _func_int_int *local_38;
  int local_34;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float flRndSound@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: int iContents@[???]
                       Unresolved local var: int fireball@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int explosion_outside@[???] */
  local_28 = *org;
  local_24 = org[1];
  local_20 = org[2];
  if (*(float *)((int)fExplosionScale + 0x10) != 1.0) {
    local_34 = dmg;
    if (0x17 < dmg) {
      local_34 = dmg + -0x18;
    }
    VectorMA((float *)((int)fExplosionScale + 0x14),(float)local_34 * 0.6,
             (float *)((int)fExplosionScale + 0x20),&local_28);
  }
  iVar1 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
  bVar6 = false;
  if (iVar1 == -2) {
    iVar1 = (*gEngfuncs.PM_PointContents)(org,(int *)0x0);
    bVar6 = iVar1 == -2;
  }
  if ((float)bDontSpark == 0.0) {
    bDontSpark = (qboolean)((float)(dmg + -0x32) * 0.6);
  }
  iVar1 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/explode01.spr");
  (*(gEngfuncs.pEfxAPI)->R_Explosion)(&local_28,iVar1,(float)bDontSpark * 0.1,15.0,3);
  if (!bVar6) {
    (*gEngfuncs.pfnRandomFloat)(0.0,1.0);
                    /* Unresolved local var: physent_t * pe@[???] */
    if ((longdouble)0.5 <= extraout_ST0) {
                    /* Unresolved local var: physent_t * pe@[???] */
      ppVar3 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(*(int *)((int)fExplosionScale + 0x30));
      if ((ppVar3 == (physent_s_conflict *)0x0) ||
         (((ppVar3->solid != 4 && (ppVar3->movetype != 0xd)) ||
          ((*gEngfuncs.pfnGetCvarFloat)("r_decals"), extraout_ST0_01 == (longdouble)0))))
      goto LAB_0006f255;
      p_Var5 = (gEngfuncs.pEfxAPI)->R_DecalShoot;
      iVar1 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)((pmtrace_s *)fExplosionScale);
      local_38 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
      pcVar7 = "{scorch2";
    }
    else {
      ppVar3 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(*(int *)((int)fExplosionScale + 0x30));
      if (((ppVar3 == (physent_s_conflict *)0x0) ||
          ((ppVar3->solid != 4 && (ppVar3->movetype != 0xd)))) ||
         ((*gEngfuncs.pfnGetCvarFloat)("r_decals"), extraout_ST0_00 == (longdouble)0))
      goto LAB_0006f255;
                    /* Unresolved local var: physent_t * pe@[???] */
      p_Var5 = (gEngfuncs.pEfxAPI)->R_DecalShoot;
      iVar1 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)((pmtrace_s *)fExplosionScale);
      local_38 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
      pcVar7 = "{scorch1";
    }
                    /* Unresolved local var: physent_t * pe@[???] */
    iVar4 = (*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)(pcVar7);
    iVar4 = (*local_38)(iVar4);
    (*p_Var5)(iVar4,iVar1,0,(float *)((int)fExplosionScale + 0x14),0);
  }
LAB_0006f255:
  (*gEngfuncs.pfnRandomFloat)(0.0,1.0);
  iVar2 = (*gEngfuncs.pfnRandomLong)(0,2);
  if (iVar2 == 1) {
    pcVar7 = "weapons/debris2.wav";
  }
  else if (iVar2 == 2) {
    pcVar7 = "weapons/debris3.wav";
  }
  else {
    if (iVar2 != 0) {
      return;
    }
    pcVar7 = "weapons/debris1.wav";
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(-1,&local_28,2,pcVar7,0.55,0.8,0,100);
  return;
}


// EV_TFC_Explode  @ 000735a0
void EV_TFC_Explode(float *org,int dmg,float fExplosionScale,qboolean bDontSpark,pmtrace_t *pTrace,
                   int bitsDamageType)

{
  bool bVar1;
  int iVar2;
  int32 iVar3;
  physent_s_conflict *ppVar4;
  int iVar5;
  bool bVar6;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  char *pcVar7;
  _func_void_int_int_int_float_ptr_int *local_3c;
  _func_int_int *local_38;
  int local_34;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float flRndSound@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: int iContents@[???]
                       Unresolved local var: int fireball@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int explosion_outside@[???] */
  local_28 = *org;
  local_24 = org[1];
  local_20 = org[2];
  if (pTrace->fraction != 1.0) {
    if (dmg < 0x18) {
      local_34 = dmg;
    }
    else {
      local_34 = dmg + -0x18;
    }
    VectorMA(&(pTrace->endpos).x,(float)local_34 * 0.6,(float *)&pTrace->plane,&local_28);
  }
  iVar2 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
  if ((iVar2 == -2) && (iVar2 = (*gEngfuncs.PM_PointContents)(org,(int *)0x0), iVar2 == -2)) {
    bVar6 = true;
    bVar1 = true;
  }
  else {
    bVar6 = iVar2 != -3;
    bVar1 = false;
  }
  if (fExplosionScale == 0.0) {
    fExplosionScale = (float)(dmg + -0x32) * 0.6;
  }
  iVar2 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/explode01.spr");
  (*(gEngfuncs.pEfxAPI)->R_Explosion)(&local_28,iVar2,fExplosionScale * 0.1,15.0,3);
  if (!bVar1) {
    (*gEngfuncs.pfnRandomFloat)(0.0,1.0);
                    /* Unresolved local var: physent_t * pe@[???] */
    if ((longdouble)0.5 <= extraout_ST0) {
                    /* Unresolved local var: physent_t * pe@[???] */
      ppVar4 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent);
      if ((ppVar4 != (physent_s_conflict *)0x0) &&
         (((ppVar4->solid == 4 || (ppVar4->movetype == 0xd)) &&
          ((*gEngfuncs.pfnGetCvarFloat)("r_decals"), extraout_ST0_01 != (longdouble)0)))) {
        local_3c = (gEngfuncs.pEfxAPI)->R_DecalShoot;
        iVar2 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(pTrace);
        local_38 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
        pcVar7 = "{scorch2";
        goto LAB_0007384b;
      }
    }
    else {
      ppVar4 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent);
      if (((ppVar4 != (physent_s_conflict *)0x0) &&
          ((ppVar4->solid == 4 || (ppVar4->movetype == 0xd)))) &&
         ((*gEngfuncs.pfnGetCvarFloat)("r_decals"), extraout_ST0_00 != (longdouble)0)) {
                    /* Unresolved local var: physent_t * pe@[???] */
        local_3c = (gEngfuncs.pEfxAPI)->R_DecalShoot;
        iVar2 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(pTrace);
        local_38 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
        pcVar7 = "{scorch1";
LAB_0007384b:
                    /* Unresolved local var: physent_t * pe@[???] */
        iVar5 = (*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)(pcVar7);
        iVar5 = (*local_38)(iVar5);
        (*local_3c)(iVar5,iVar2,0,&(pTrace->endpos).x,0);
      }
    }
  }
  (*gEngfuncs.pfnRandomFloat)(0.0,1.0);
  iVar3 = (*gEngfuncs.pfnRandomLong)(0,2);
  if (iVar3 == 1) {
    pcVar7 = "weapons/debris2.wav";
  }
  else if (iVar3 == 2) {
    pcVar7 = "weapons/debris3.wav";
  }
  else {
    if (iVar3 != 0) goto LAB_000736e8;
    pcVar7 = "weapons/debris1.wav";
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(-1,&local_28,2,pcVar7,0.55,0.8,0,100);
LAB_000736e8:
  if ((bVar6) && (bDontSpark == 0)) {
                    /* Unresolved local var: int sparkCount@[???] */
    iVar3 = (*gEngfuncs.pfnRandomLong)(0,3);
    if (0 < iVar3) {
      iVar2 = 0;
      do {
        iVar2 = iVar2 + 1;
        (*(gEngfuncs.pEfxAPI)->R_SparkShower)(&local_28);
      } while (iVar2 != iVar3);
      return;
    }
  }
  return;
}


// EV_TFC_ExplodeFire  @ 00073fe0
void EV_TFC_ExplodeFire(float *org,int dmg,qboolean bDontSpark,pmtrace_t *pTrace,int bitsDamageType)

{
  int iVar1;
  int iVar2;
  physent_s_conflict *ppVar3;
  int32 iVar4;
  int iVar5;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  char *pcVar6;
  _func_void_int_int_int_float_ptr_int *local_3c;
  _func_int_int *local_38;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float flRndSound@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: int iContents@[???]
                       Unresolved local var: int fireball@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float fExplosionScale@[???] */
  local_28 = *org;
  local_24 = org[1];
  local_20 = org[2];
  if (pTrace->fraction != 1.0) {
    if (0x17 < dmg) {
      dmg = dmg + -0x18;
    }
    VectorMA(&(pTrace->endpos).x,(float)dmg * 0.6,(float *)&pTrace->plane,&local_28);
  }
  iVar1 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
  if ((iVar1 == -2) && (iVar1 = (*gEngfuncs.PM_PointContents)(org,(int *)0x0), iVar1 == -2)) {
    return;
  }
  iVar2 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/explode01.spr");
  (*(gEngfuncs.pEfxAPI)->R_Explosion)(&local_28,iVar2,3.0,15.0,3);
  (*gEngfuncs.pfnRandomFloat)(0.0,1.0);
                    /* Unresolved local var: physent_t * pe@[???] */
  if (extraout_ST0 < (longdouble)0.5) {
    ppVar3 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent);
    if ((ppVar3 != (physent_s_conflict *)0x0) &&
       (((ppVar3->solid == 4 || (ppVar3->movetype == 0xd)) &&
        ((*gEngfuncs.pfnGetCvarFloat)("r_decals"), extraout_ST0_00 != (longdouble)0)))) {
                    /* Unresolved local var: physent_t * pe@[???] */
      local_3c = (gEngfuncs.pEfxAPI)->R_DecalShoot;
      iVar2 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(pTrace);
      local_38 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
      pcVar6 = "{scorch1";
      goto LAB_0007431f;
    }
  }
  else {
                    /* Unresolved local var: physent_t * pe@[???] */
    ppVar3 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent);
    if (((ppVar3 != (physent_s_conflict *)0x0) &&
        ((ppVar3->solid == 4 || (ppVar3->movetype == 0xd)))) &&
       ((*gEngfuncs.pfnGetCvarFloat)("r_decals"), extraout_ST0_01 != (longdouble)0)) {
                    /* Unresolved local var: physent_t * pe@[???] */
      local_3c = (gEngfuncs.pEfxAPI)->R_DecalShoot;
      iVar2 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(pTrace);
      local_38 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
      pcVar6 = "{scorch2";
LAB_0007431f:
      iVar5 = (*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)(pcVar6);
      iVar5 = (*local_38)(iVar5);
      (*local_3c)(iVar5,iVar2,0,&(pTrace->endpos).x,0);
    }
  }
  (*gEngfuncs.pfnRandomFloat)(0.0,1.0);
  iVar4 = (*gEngfuncs.pfnRandomLong)(0,2);
  if (iVar4 == 1) {
    pcVar6 = "weapons/debris2.wav";
  }
  else if (iVar4 == 2) {
    pcVar6 = "weapons/debris3.wav";
  }
  else {
    if (iVar4 != 0) goto LAB_00074147;
    pcVar6 = "weapons/debris1.wav";
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(-1,&local_28,2,pcVar6,0.55,0.8,0,100);
LAB_00074147:
                    /* Unresolved local var: int sparkCount@[???] */
  if (((iVar1 != -3) && (bDontSpark == 0)) && (iVar4 = (*gEngfuncs.pfnRandomLong)(0,3), 0 < iVar4))
  {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      (*(gEngfuncs.pEfxAPI)->R_SparkShower)(&local_28);
    } while (iVar1 != iVar4);
  }
  return;
}


// EV_TFC_Explosion  @ 00073980
void EV_TFC_Explosion(event_args_t *args)

{
  pmtrace_t *pTrace;
  int bitsDamageType;
  pmtrace_s local_74;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector upV@[???]
                       Unresolved local var: Vector downV@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: Vector origin@[???] */
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  local_24 = local_18 + 0.0;
  local_20 = local_14 + 0.0;
  local_1c = local_10 + 8.0;
  local_30 = local_24 + 0.0;
  local_2c = local_20 + 0.0;
  local_28 = local_1c - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  pTrace = (pmtrace_t *)&local_30;
  bitsDamageType = 2;
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_24,(float *)pTrace,2,-1,&local_74);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  EV_TFC_Explode(&local_18,0x78,(float)&local_74,0,pTrace,bitsDamageType);
  return;
}


// EV_TFC_FireBullets  @ 00070840
void EV_TFC_FireBullets(int idx,float *forward,float *right,float *up,int cShots,float *vecSrc,
                       float *vecDirShooting,float *vecSpread,float flDistance,int iBulletType,
                       int iTracerFreq,int *tracerCount,int iDamage)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  physent_s_conflict *ppVar5;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  float *bitsDamageType;
  int local_c8;
  int local_b4;
  pmtrace_s local_a0;
  char local_5c [32];
  float local_3c;
  float local_38;
  float local_34;
  int local_30;
  int local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int iShot@[???]
                       Unresolved local var: Vector vecRight@[???]
                       Unresolved local var: Vector vecUp@[???]
                       Unresolved local var: int tracer@[???]
                       Unresolved local var: int cMultiGunShots@[???] */
  fVar1 = *right;
  fVar2 = right[1];
  fVar3 = right[2];
  if (0 < cShots) {
    local_b4 = 0;
    local_c8 = 1;
    do {
      do {
                    /* Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector spread@[???] */
        (*gEngfuncs.pfnRandomFloat)(-0.5,0.5);
        (*gEngfuncs.pfnRandomFloat)(-0.5,0.5);
        (*gEngfuncs.pfnRandomFloat)(-0.5,0.5);
        (*gEngfuncs.pfnRandomFloat)(-0.5,0.5);
        lVar6 = extraout_ST0_02 + (longdouble)(float)extraout_ST0_01;
        lVar7 = (longdouble)(float)(extraout_ST0_00 + (longdouble)(float)extraout_ST0);
      } while ((longdouble)1 < lVar6 * lVar6 + lVar7 * lVar7);
      lVar7 = (longdouble)(float)(extraout_ST0_00 + (longdouble)(float)extraout_ST0) *
              (longdouble)*vecSpread;
      lVar6 = lVar6 * (longdouble)vecSpread[1];
      lVar8 = (longdouble)*up * lVar6 + (longdouble)fVar1 * lVar7 + (longdouble)*vecDirShooting;
      local_3c = (float)lVar8;
      local_28 = (float)(lVar8 * (longdouble)flDistance + (longdouble)*vecSrc);
      lVar8 = (longdouble)up[1] * lVar6 + (longdouble)fVar2 * lVar7 + (longdouble)vecDirShooting[1];
      local_38 = (float)lVar8;
      local_24 = (float)(lVar8 * (longdouble)flDistance + (longdouble)vecSrc[1]);
      lVar7 = lVar6 * (longdouble)up[2] + lVar7 * (longdouble)fVar3 + (longdouble)vecDirShooting[2];
      local_34 = (float)lVar7;
      local_20 = (float)(lVar7 * (longdouble)flDistance + (longdouble)vecSrc[2]);
      (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
      (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
      (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(idx + -1);
      (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
      (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(vecSrc,&local_28,2,-1,&local_a0);
      bitsDamageType = vecSrc;
      iVar4 = EV_TFC_CheckTracer(idx,vecSrc,&local_a0.endpos.x,forward,right,iBulletType,iTracerFreq
                                 ,tracerCount);
      if (local_a0.fraction != (float)(longdouble)1) {
        if (iDamage == 0) {
          if (iBulletType == 3) {
            if (iVar4 == 0) {
              EV_TFC_PlayTextureSound(idx,&local_a0,vecSrc,&local_28,3);
                    /* Unresolved local var: physent_t * pe@[???] */
              ppVar5 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(local_a0.ent);
              if ((ppVar5 != (physent_s_conflict *)0x0) &&
                 ((ppVar5->solid == 4 || (ppVar5->movetype == 0xd)))) {
                EV_TFC_DecalGunshot(&local_a0,3);
              }
            }
          }
          else if (iBulletType == 4) {
                    /* Unresolved local var: physent_t * pe@[???] */
            if (((iVar4 == 0) &&
                (ppVar5 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(local_a0.ent),
                ppVar5 != (physent_s_conflict *)0x0)) &&
               ((ppVar5->solid == 4 || (ppVar5->movetype == 0xd)))) {
              EV_TFC_DecalGunshot(&local_a0,4);
            }
          }
          else if (iBulletType == 2) {
            if (iVar4 == 0) {
              EV_TFC_PlayTextureSound(idx,&local_a0,vecSrc,&local_28,2);
                    /* Unresolved local var: physent_t * pe@[???] */
              ppVar5 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(local_a0.ent);
              if ((ppVar5 != (physent_s_conflict *)0x0) &&
                 ((ppVar5->solid == 4 || (ppVar5->movetype == 0xd)))) {
                EV_TFC_DecalGunshot(&local_a0,2);
              }
            }
          }
          else if (iVar4 == 0) {
            EV_TFC_PlayTextureSound(idx,&local_a0,vecSrc,&local_28,iBulletType);
                    /* Unresolved local var: physent_t * pe@[???] */
            ppVar5 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(local_a0.ent);
            if ((ppVar5 != (physent_s_conflict *)0x0) &&
               ((ppVar5->solid == 4 || (ppVar5->movetype == 0xd)))) {
              EV_TFC_DecalGunshot(&local_a0,iBulletType);
            }
          }
        }
        else {
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
          if (cShots == 1) {
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
            if ((cl_localblood == (cvar_t *)0x0) || (cl_localblood->value != 0.0)) {
              EV_TFC_TraceAttack(idx,(float)&local_3c,(float *)&local_a0,(pmtrace_t *)(float)iDamage
                                 ,(int)bitsDamageType);
            }
            EV_TFC_PlayTextureSound(idx,&local_a0,vecSrc,&local_28,iBulletType);
                    /* Unresolved local var: physent_t * pe@[???] */
            ppVar5 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(local_a0.ent);
            if ((ppVar5 == (physent_s_conflict *)0x0) ||
               ((ppVar5->solid != 4 && (ppVar5->movetype != 0xd)))) {
              (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
            }
            else {
              EV_TFC_DecalGunshot(&local_a0,iBulletType);
              (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
            }
            break;
          }
          if ((cl_localblood == (cvar_t *)0x0) || (cl_localblood->value != 0.0)) {
            EV_TFC_TraceAttack(idx,(float)&local_3c,(float *)&local_a0,(pmtrace_t *)(float)iDamage,
                               (int)bitsDamageType);
          }
          local_b4 = local_b4 + 1;
        }
      }
      (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
      local_c8 = local_c8 + 1;
    } while (local_c8 <= cShots);
    if (local_b4 != 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int[5] decal_index@[???]
                       Unresolved local var: char[32] decalname@[???]
                       Unresolved local var: Vector size@[???] */
      sprintf(local_5c,"{shot%i",1);
      local_3c = (float)(*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)(local_5c);
      sprintf(local_5c,"{shot%i",2);
      local_38 = (float)(*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)(local_5c);
      sprintf(local_5c,"{shot%i",3);
      local_34 = (float)(*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)(local_5c);
      sprintf(local_5c,"{shot%i",4);
      local_30 = (*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)(local_5c);
      sprintf(local_5c,"{shot%i",5);
      local_2c = (*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)(local_5c);
      local_20 = 0.0;
      local_28 = *vecSpread;
      local_24 = vecSpread[1];
      (*(gEngfuncs.pEfxAPI)->R_MultiGunshot)
                (vecSrc,vecDirShooting,&local_28,local_b4,5,(int *)&local_3c);
    }
  }
  return;
}


// EV_TFC_FireIC  @ 00075250
void EV_TFC_FireIC(event_args_t *args)

{
  int idx;
  qboolean qVar1;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_18 = args->origin[0];
  idx = args->entindex;
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(3,2);
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_18,1,"weapons/sgun1.wav",0.9,0.8,0,100);
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    V_PunchAxis(0,-5.0);
  }
  return;
}


// EV_TFC_FireRPG  @ 00075150
void EV_TFC_FireRPG(event_args_t *args)

{
  int idx;
  qboolean qVar1;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_18 = args->origin[0];
  idx = args->entindex;
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(2,2);
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_18,1,"weapons/rocketfire1.wav",0.9,0.8,0,100);
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_18,3,"weapons/glauncher.wav",0.7,0.8,0,100);
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    V_PunchAxis(0,-5.0);
  }
  return;
}


// EV_TFC_Flame_Fire  @ 00072620
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void EV_TFC_Flame_Fire(event_args_t *args)

{
  int iVar1;
  int idx;
  int iVar2;
  int iVar3;
  qboolean qVar4;
  float fVar5;
  short local_84;
  float local_7c [2];
  float local_74;
  float local_70 [2];
  float local_68;
  float local_64 [3];
  float local_58 [3];
  float local_4c [3];
  float local_40 [3];
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: Vector ShellOrigin@[???]
                       Unresolved local var: Vector BubbleSpot@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: float flSpread@[???]
                       Unresolved local var: Vector vecVelocity@[???]
                       Unresolved local var: int shell@[???]
                       Unresolved local var: int bubble@[???]
                       Unresolved local var: int underwater@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_34 = args->origin[0];
  iVar1 = args->bparam1;
  idx = args->entindex;
  local_30 = args->origin[1];
  local_2c = args->origin[2];
  local_28 = args->angles[0];
  local_24 = args->angles[1];
  local_20 = args->angles[2];
  iVar2 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/fthrow.spr");
  iVar3 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/bubble.spr");
  (*gEngfuncs.pfnAngleVectors)(&local_28,local_4c,local_58,local_64);
  qVar4 = EV_IsLocal(idx);
  if (qVar4 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(5,2);
  }
  EV_GetGunPosition(args,local_7c,&local_34);
  VectorMA(local_7c,-8.0,local_64,local_7c);
  VectorMA(local_7c,8.0,local_58,local_7c);
  VectorMA(local_7c,16.0,local_4c,local_7c);
  if (iVar1 == 0) {
    VectorScale(local_4c,600.0,local_40);
    local_84 = (short)iVar2;
    (*(gEngfuncs.pEfxAPI)->R_Projectile)
              (local_7c,local_40,(int)local_84,1,idx,(_func_void_tempent_s_ptr_pmtrace_s_ptr *)0x0);
    (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_34,1,"weapons/flmfire2.wav",0.9,0.8,0,100);
    return;
  }
  VectorMA(local_7c,128.0,local_4c,local_70);
                    /* Unresolved local var: float flHeight@[???] */
  fVar5 = EV_TFC_WaterLevel(local_7c,local_74,local_74 + 256.0);
  fVar5 = fVar5 - local_74;
  if (fVar5 < 8.0) {
    fVar5 = EV_TFC_WaterLevel(local_70,local_68,local_68 + 256.0);
    if (fVar5 - local_68 < 8.0) {
      return;
    }
    fVar5 = (local_68 + (fVar5 - local_68)) - local_74;
  }
  (*(gEngfuncs.pEfxAPI)->R_BubbleTrail)(local_7c,local_70,fVar5,iVar3,4,8.0);
  return;
}


// EV_TFC_Gas  @ 00074790
void EV_TFC_Gas(event_args_t *args)

{
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: Vector origin@[???] */
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  (*(gEngfuncs.pEfxAPI)->R_ParticleBurst)(&local_18,0xf0,0xc3,2.0);
  return;
}


// EV_TFC_GetTeamIndex  @ 00070340
int EV_TFC_GetTeamIndex(int idx)

{
  int iVar1;
  cl_entity_s *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: cl_entity_t * ent@[???] */
  iVar3 = -1;
  if (0 < idx) {
    iVar1 = (*gEngfuncs.GetMaxClients)();
    if (idx <= iVar1) {
      pcVar2 = GetEntity(idx);
      if (pcVar2 != (cl_entity_s *)0x0) {
        iVar3 = (pcVar2->curstate).team;
      }
    }
  }
  return iVar3;
}


// EV_TFC_GibCallback  @ 0006e8a0
void EV_TFC_GibCallback(tempent_s *ent,float frametime,float currenttime)

{
  int iVar1;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  float fVar2;
  
                    /* Unresolved local var: float vel@[???] */
  fVar2 = Length(&(ent->entity).baseline.origin.x);
  iVar1 = (ent->entity).curstate.playerclass;
  if (iVar1 == 2) {
    (ent->entity).curstate.playerclass = 3;
    (*gEngfuncs.GetClientTime)();
    (ent->entity).curstate.renderamt = 0xff;
    (ent->entity).curstate.rendermode = 2;
    ent->die = (float)(extraout_ST0_01 + (longdouble)2.5);
    return;
  }
  if (iVar1 < 3) {
    if (iVar1 == 1) {
      fVar2 = (ent->entity).baseline.fuser1 - frametime;
      (ent->entity).baseline.fuser1 = fVar2;
      if (fVar2 <= 0.0) {
        (ent->entity).curstate.playerclass = 2;
      }
      goto LAB_0006e8e0;
    }
  }
  else {
    if (iVar1 == 3) {
      if (7 < (ent->entity).curstate.renderamt) {
        (*gEngfuncs.GetClientTime)();
        ent->die = (float)(extraout_ST0_00 + (longdouble)1.0);
        (ent->entity).curstate.renderamt =
             (int)((float)(ent->entity).curstate.renderamt - frametime * 70.0);
        return;
      }
      (ent->entity).curstate.renderamt = 0;
      (*gEngfuncs.GetClientTime)();
      ent->die = (float)((longdouble)0.2 + extraout_ST0_02);
      (ent->entity).curstate.playerclass = 4;
      return;
    }
    if (iVar1 == 4) {
      return;
    }
  }
  if (fVar2 == 0.0) {
    (ent->entity).curstate.playerclass = 1;
    (ent->entity).baseline.fuser1 = cl_giblife->value;
  }
LAB_0006e8e0:
  (*gEngfuncs.GetClientTime)();
  ent->die = (float)(extraout_ST0 + (longdouble)1.0);
  return;
}


// EV_TFC_GibTouchCallback  @ 000700d0
void EV_TFC_GibTouchCallback(tempent_s *ent,pmtrace_t *ptr)

{
  int *piVar1;
  float fVar2;
  
                    /* Unresolved local var: float vel@[???] */
  fVar2 = Length(&(ent->entity).baseline.origin.x);
  if ((0.0 < fVar2) && (0 < (ent->entity).curstate.team)) {
                    /* Unresolved local var: float vel@[???] */
    EV_TFC_BloodDecalTrace(ptr,0xf7);
    piVar1 = &(ent->entity).curstate.team;
    *piVar1 = *piVar1 + -1;
  }
  return;
}


// EV_TFC_GibVelocityCheck  @ 00076890
void EV_TFC_GibVelocityCheck(float *vel)

{
  float fVar1;
  
                    /* Unresolved local var: float length@[???] */
  fVar1 = Length(vel);
  if (1500.0 < fVar1) {
    VectorScale(vel,1500.0 / fVar1,vel);
  }
  return;
}


// EV_TFC_Gibs  @ 00076cf0
void EV_TFC_Gibs(event_args_t *args)

{
  int multiplier;
  int iVar1;
  int iVar2;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector attackdir@[???]
                       Unresolved local var: int cSplat@[???]
                       Unresolved local var: int cGibs@[???]
                       Unresolved local var: int multiplier@[???] */
  local_34 = args->origin[0];
  local_30 = args->origin[1];
  local_2c = args->origin[2];
  local_28 = args->angles[0];
  local_24 = args->angles[1];
  local_20 = args->angles[2];
  multiplier = args->iparam1;
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)
            (args->entindex,&local_34,1,"common/bodysplat.wav",1.0,0.8,0,100);
  iVar1 = 0;
  if (-1 < (int)cl_gibcount->value) {
    iVar1 = (int)cl_gibcount->value;
  }
  iVar2 = 0x40;
  if (iVar1 < 0x41) {
    iVar2 = iVar1;
  }
  if (iVar2 != 0) {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      EV_TFC_CreateGib(&local_34,&local_28,multiplier,0);
    } while (iVar1 != iVar2);
  }
  EV_TFC_CreateGib(&local_34,&local_28,multiplier,1);
  return;
}


// EV_TFC_Grenade  @ 00073a70
void EV_TFC_Grenade(event_args_t *args)

{
  pmtrace_t *pTrace;
  int bitsDamageType;
  pmtrace_s local_74;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector upV@[???]
                       Unresolved local var: Vector downV@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: Vector origin@[???] */
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  local_24 = local_18 + 0.0;
  local_20 = local_14 + 0.0;
  local_1c = local_10 + 8.0;
  local_30 = local_24 + 0.0;
  local_2c = local_20 + 0.0;
  local_28 = local_1c - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  bitsDamageType = 2;
  pTrace = (pmtrace_t *)&local_30;
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_24,(float *)pTrace,2,-1,&local_74);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  EV_TFC_Explode(&local_18,0x78,(float)&local_74,0,pTrace,bitsDamageType);
  return;
}


// EV_TFC_GrenadeLauncher  @ 000756e0
void EV_TFC_GrenadeLauncher(event_args_t *args)

{
  int idx;
  qboolean qVar1;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_18 = args->origin[0];
  idx = args->entindex;
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(2,2);
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_18,3,"weapons/glauncher.wav",0.7,0.8,0,100);
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    V_PunchAxis(0,-2.0);
  }
  return;
}


// EV_TFC_GunshotDecalTrace  @ 0006ea20
void __regparm3 EV_TFC_GunshotDecalTrace(pmtrace_t *pTrace,char *name)

{
  Vector *pVVar1;
  _func_void_int_int_int_float_ptr_int *p_Var2;
  _func_int_int *p_Var3;
  int32 iVar4;
  physent_s_conflict *ppVar5;
  int iVar6;
  int iVar7;
  longdouble lVar8;
  char *pcVar9;
  
  pVVar1 = &pTrace->endpos;
                    /* Unresolved local var: int iRand@[???]
                       Unresolved local var: physent_t * pe@[???] */
  (*(gEngfuncs.pEfxAPI)->R_BulletImpactParticles)(&pVVar1->x);
  iVar4 = (*gEngfuncs.pfnRandomLong)(0,0x7fff);
  if (iVar4 < 0x3fff) {
    switch(iVar4 % 5) {
    case 0:
      pcVar9 = "weapons/ric1.wav";
      break;
    case 1:
      pcVar9 = "weapons/ric2.wav";
      break;
    case 2:
      pcVar9 = "weapons/ric3.wav";
      break;
    case 3:
      pcVar9 = "weapons/ric4.wav";
      break;
    case 4:
      pcVar9 = "weapons/ric5.wav";
      break;
    default:
      goto switchD_0006eb4f_default;
    }
    (*(gEngfuncs.pEventAPI)->EV_PlaySound)(-1,&pVVar1->x,0,pcVar9,1.0,0.8,0,100);
  }
switchD_0006eb4f_default:
  ppVar5 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent);
  if ((ppVar5 != (physent_s_conflict *)0x0) &&
     (((ppVar5->solid == 4 || (ppVar5->movetype == 0xd)) &&
      (lVar8 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("r_decals"), lVar8 != (longdouble)0)))) {
    p_Var2 = (gEngfuncs.pEfxAPI)->R_DecalShoot;
    iVar6 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(pTrace);
    p_Var3 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
    iVar7 = (*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)(name);
    iVar7 = (*p_Var3)(iVar7);
    (*p_Var2)(iVar7,iVar6,0,&pVVar1->x,0);
  }
  return;
}


// EV_TFC_GunshotDecalTrace  @ 0006fae0
void EV_TFC_GunshotDecalTrace(pmtrace_t *pTrace,char *name)

{
                    /* Unresolved local var: int iRand@[???]
                       Unresolved local var: physent_t * pe@[???] */
  if (((name != (char *)0x0) && (*name != '\0')) && (pTrace->fraction != 1.0)) {
    EV_TFC_GunshotDecalTrace(pTrace,name);
    return;
  }
  return;
}


// EV_TFC_IsAlly  @ 00070420
int EV_TFC_IsAlly(int idx1,int idx2)

{
  int iVar1;
  int iVar2;
  cl_entity_s *pcVar3;
  char *__nptr;
  uint uVar4;
  bool bVar5;
  uint local_2c [4];
  uint local_1c;
  
                    /* Unresolved local var: cl_entity_t * player@[???]
                       Unresolved local var: int t1@[DW_OP_reg7(EDI)]
                       Unresolved local var: int t2@[DW_OP_reg6(ESI)]
                       Unresolved local var: cl_entity_t * ent@[???] */
  if (((idx1 < 1) || (iVar1 = (*gEngfuncs.GetMaxClients)(), iVar1 < idx1)) ||
     (pcVar3 = GetEntity(idx1), pcVar3 == (cl_entity_s *)0x0)) {
    bVar5 = true;
    iVar1 = -1;
  }
  else {
    iVar1 = (pcVar3->curstate).team;
    bVar5 = iVar1 == -1;
  }
                    /* Unresolved local var: cl_entity_t * ent@[???] */
  if (((((0 < idx2) && (iVar2 = (*gEngfuncs.GetMaxClients)(), idx2 <= iVar2)) &&
       ((pcVar3 = GetEntity(idx2), pcVar3 != (cl_entity_s *)0x0 &&
        ((iVar2 = (pcVar3->curstate).team, iVar2 != -1 && (!bVar5)))))) && (iVar2 != 0)) &&
     (iVar1 != 0)) {
    pcVar3 = (*gEngfuncs.GetLocalPlayer)();
    if (pcVar3 == (cl_entity_s *)0x0) {
      return 0;
    }
    if ((iVar2 < 5) && (iVar1 < 5)) {
                    /* Unresolved local var: int teamallies@[???]
                       Unresolved local var: int[5] team_ally@[???]
                       Unresolved local var: int i@[???] */
      __nptr = (*gEngfuncs.PhysInfo_ValueForKey)("ta");
      uVar4 = strtol(__nptr,(char **)0x0,10);
      local_2c[0] = uVar4 & 0x1f;
      local_2c[1] = (int)uVar4 >> 5 & 0x1f;
      local_2c[2] = (int)uVar4 >> 10 & 0x1f;
      local_1c = (int)uVar4 >> 0x14 & 0x1f;
      local_2c[3] = (int)uVar4 >> 0xf & 0x1f;
      if (((int)local_2c[iVar1] >> ((char)iVar2 - 1U & 0x1f) & 1U) != 0) {
        return 1;
      }
      return (uint)(iVar1 == iVar2);
    }
  }
  return 0;
}


// EV_TFC_IsAllyTeam  @ 00070390
int EV_TFC_IsAllyTeam(int iTeam1,int iTeam2)

{
  char *__nptr;
  uint uVar1;
  uint uVar2;
  uint local_2c [4];
  uint local_1c;
  
                    /* Unresolved local var: int teamallies@[???]
                       Unresolved local var: int[5] team_ally@[???]
                       Unresolved local var: int i@[???] */
  __nptr = (*gEngfuncs.PhysInfo_ValueForKey)("ta");
  uVar1 = strtol(__nptr,(char **)0x0,10);
  local_2c[0] = uVar1 & 0x1f;
  local_2c[1] = (int)uVar1 >> 5 & 0x1f;
  local_2c[2] = (int)uVar1 >> 10 & 0x1f;
  local_1c = (int)uVar1 >> 0x14 & 0x1f;
  uVar2 = 1;
  local_2c[3] = (int)uVar1 >> 0xf & 0x1f;
  if (((int)local_2c[iTeam1] >> ((char)iTeam2 - 1U & 0x1f) & 1U) == 0) {
    uVar2 = (uint)(iTeam1 == iTeam2);
  }
  return uVar2;
}


// EV_TFC_Knife  @ 000728f0
void EV_TFC_Knife(event_args_t *args)

{
  return;
}


// EV_TFC_LookupDoorSound  @ 00072de0
char * EV_TFC_LookupDoorSound(int type,int index)

{
  uint uVar1;
  uint uVar2;
  
                    /* Unresolved local var: int idx@[???] */
  builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"common/null.wav",0x10);
  if (type == 0) {
    switch((uint)index >> 8 & 0xff) {
    default:
switchD_00072e78_caseD_0:
      builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"common/null.wav",0x10);
      break;
    case 1:
      builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"doors/doormove1.wav",0x14);
      break;
    case 2:
      builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"doors/doormove2.wav",0x14);
      break;
    case 3:
      builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"doors/doormove3.wav",0x14);
      break;
    case 4:
      builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"doors/doormove4.wav",0x14);
      break;
    case 5:
      builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"doors/doormove5.wav",0x14);
      break;
    case 6:
      builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"doors/doormove6.wav",0x14);
      break;
    case 7:
      builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"doors/doormove7.wav",0x14);
      break;
    case 8:
      builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"doors/doormove8.wav",0x14);
      break;
    case 9:
      builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"doors/doormove9.wav",0x14);
      break;
    case 10:
      uVar1 = 0;
      do {
        uVar2 = uVar1;
        *(undefined4 *)(EV_TFC_LookupDoorSound::lexical_block_0::sound + uVar2) =
             *(undefined4 *)("doors/doormove10.wav" + uVar2);
        uVar1 = uVar2 + 4;
      } while (uVar2 + 4 < 0x14);
      EV_TFC_LookupDoorSound::lexical_block_0::sound[uVar2 + 4] = "doors/doormove10.wav"[uVar2 + 4];
    }
  }
  else {
    if (type != 1) goto LAB_00072e50;
    switch(index & 0xff) {
    default:
      goto switchD_00072e78_caseD_0;
    case 1:
      builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"doors/doorstop1.wav",0x14);
      break;
    case 2:
      builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"doors/doorstop2.wav",0x14);
      break;
    case 3:
      builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"doors/doorstop3.wav",0x14);
      break;
    case 4:
      builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"doors/doorstop4.wav",0x14);
      break;
    case 5:
      builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"doors/doorstop5.wav",0x14);
      break;
    case 6:
      builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"doors/doorstop6.wav",0x14);
      break;
    case 7:
      builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"doors/doorstop7.wav",0x14);
      break;
    case 8:
      builtin_strncpy(EV_TFC_LookupDoorSound::lexical_block_0::sound,"doors/doorstop8.wav",0x14);
    }
  }
LAB_00072e50:
  return EV_TFC_LookupDoorSound::lexical_block_0::sound;
}


// EV_TFC_Medkit  @ 00075f40
int EV_TFC_Medkit(int idx,float *origin,float *forward,float *right,int entity,float *vecDir,
                 pmtrace_t *ptr)

{
  int iVar1;
  cl_entity_s *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: cl_entity_t * state@[???] */
  iVar3 = 0;
  if ((0 < entity) && (iVar1 = (*gEngfuncs.GetMaxClients)(), entity <= iVar1)) {
    iVar3 = 1;
    pcVar2 = GetEntity(entity + -1);
    iVar1 = EV_TFC_IsAlly(idx,entity);
    if (iVar1 == 0) {
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
      if ((cl_localblood == (cvar_t *)0x0) || (cl_localblood->value != 0.0)) {
        EV_TFC_TraceAttack(idx,(float)vecDir,(float *)ptr,(pmtrace_t *)0x41200000,entity);
      }
      iVar3 = 1;
      if ((pcVar2->curstate).playerclass != 5) {
        (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,origin,2,"player/death2.wav",1.0,0.8,0,100);
      }
    }
  }
  return iVar3;
}


// EV_TFC_MirvGrenade  @ 00073fd0
void EV_TFC_MirvGrenade(event_args_t *args)

{
  pmtrace_t *pTrace;
  int bitsDamageType;
  pmtrace_s pStack_74;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  
  fStack_18 = args->origin[0];
  fStack_14 = args->origin[1];
  fStack_10 = args->origin[2];
  fStack_24 = fStack_18 + 0.0;
  fStack_20 = fStack_14 + 0.0;
  fStack_1c = fStack_10 + 8.0;
  fStack_30 = fStack_24 + 0.0;
  fStack_2c = fStack_20 + 0.0;
  fStack_28 = fStack_1c - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  bitsDamageType = 2;
  pTrace = (pmtrace_t *)&fStack_30;
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&fStack_24,(float *)pTrace,2,-1,&pStack_74);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  EV_TFC_Explode(&fStack_18,0xb4,(float)&pStack_74,0,pTrace,bitsDamageType);
  return;
}


// EV_TFC_MirvGrenadeMain  @ 00073fc0
void EV_TFC_MirvGrenadeMain(event_args_t *args)

{
  pmtrace_t *pTrace;
  int bitsDamageType;
  pmtrace_s pStack_74;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  
  fStack_18 = args->origin[0];
  fStack_14 = args->origin[1];
  fStack_10 = args->origin[2];
  fStack_24 = fStack_18 + 0.0;
  fStack_20 = fStack_14 + 0.0;
  fStack_1c = fStack_10 + 8.0;
  fStack_30 = fStack_24 + 0.0;
  fStack_2c = fStack_20 + 0.0;
  fStack_28 = fStack_1c - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  bitsDamageType = 2;
  pTrace = (pmtrace_t *)&fStack_30;
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&fStack_24,(float *)pTrace,2,-1,&pStack_74);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  EV_TFC_Explode(&fStack_18,0xb4,(float)&pStack_74,0,pTrace,bitsDamageType);
  return;
}


// EV_TFC_NailGrenade  @ 00075070
void EV_TFC_NailGrenade(event_args_t *args)

{
  pmtrace_t *pTrace;
  int bitsDamageType;
  pmtrace_s local_74;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector upV@[???]
                       Unresolved local var: Vector downV@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: Vector origin@[???] */
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  local_24 = local_18 + 0.0;
  local_20 = local_14 + 0.0;
  local_1c = local_10 + 8.0;
  local_30 = local_24 + 0.0;
  local_2c = local_20 + 0.0;
  local_28 = local_1c - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  bitsDamageType = 2;
  pTrace = (pmtrace_t *)&local_30;
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_24,(float *)pTrace,2,-1,&local_74);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  EV_TFC_Explode(&local_18,0xb4,(float)&local_74,0x429c0000,pTrace,bitsDamageType);
  return;
}


// EV_TFC_NailTouch  @ 0006ebd0
void EV_TFC_NailTouch(tempent_s *ent,pmtrace_t *ptr)

{
  physent_s_conflict *ppVar1;
  int32 iVar2;
  char local_2c [36];
  
                    /* Unresolved local var: char[32] decalname@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
  ppVar1 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(ptr->ent);
  if ((ppVar1 != (physent_s_conflict *)0x0) && ((ppVar1->solid == 4 || (ppVar1->movetype == 0xd))))
  {
                    /* Unresolved local var: char[32] decalname@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
    local_2c[0] = '\0';
    iVar2 = (*gEngfuncs.pfnRandomLong)(0,4);
    sprintf(local_2c,"{shot%i",iVar2 + 1);
                    /* Unresolved local var: int iRand@[???]
                       Unresolved local var: physent_t * pe@[???] */
    if ((local_2c[0] != '\0') && (ptr->fraction != 1.0)) {
      EV_TFC_GunshotDecalTrace(ptr,local_2c);
    }
  }
  return;
}


// EV_TFC_NailgrenadeNail  @ 000749e0
void EV_TFC_NailgrenadeNail(event_args_t *args)

{
  float fVar1;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var2;
  int iVar3;
  int32 iVar4;
  uint uVar5;
  float local_58 [3];
  float local_4c;
  float local_48;
  undefined4 local_44;
  float local_40 [3];
  float local_34 [3];
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector velocity@[???]
                       Unresolved local var: float flYaw@[???]
                       Unresolved local var: int shell@[???]
                       Unresolved local var: int yaw@[???]
                       Unresolved local var: int owner@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float j@[???]
                       Unresolved local var: Vector org@[???] */
  local_4c = 0.0;
  local_44 = 0;
  local_28 = args->origin[0];
  fVar1 = args->fparam1;
  local_24 = args->origin[1];
  local_20 = args->origin[2];
  uVar5 = args->iparam1 >> 0xb & 0x1f;
  local_48 = (float)(args->iparam1 & 0x7ff) * 0.25;
  iVar3 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("models/nail.mdl");
  iVar3 = (int)(short)iVar3;
  local_48 = anglemod(fVar1 + local_48);
  (*gEngfuncs.pfnAngleVectors)(&local_4c,local_40,(float *)0x0,(float *)0x0);
  VectorMA(&local_28,12.0,local_40,local_58);
  VectorScale(local_40,1000.0,local_34);
  (*(gEngfuncs.pEfxAPI)->R_Projectile)(local_58,local_34,iVar3,6,uVar5,EV_TFC_NailTouch);
  iVar4 = (*gEngfuncs.pfnRandomLong)(0,5);
  if (iVar4 == 0) {
    iVar4 = (*gEngfuncs.pfnRandomLong)(0,1);
    p_Var2 = (gEngfuncs.pEventAPI)->EV_PlaySound;
    if (iVar4 == 0) {
      iVar4 = (*gEngfuncs.pfnRandomLong)(0,0xf);
      (*p_Var2)(-1,local_58,1,"weapons/airgun_1.wav",1.0,0.8,0,iVar4 + 0x5e);
    }
    else {
      iVar4 = (*gEngfuncs.pfnRandomLong)(0,0xf);
      (*p_Var2)(-1,local_58,1,"weapons/spike2.wav",1.0,0.8,0,iVar4 + 0x5e);
    }
  }
  local_48 = anglemod(fVar1 + local_48);
  (*gEngfuncs.pfnAngleVectors)(&local_4c,local_40,(float *)0x0,(float *)0x0);
  VectorMA(&local_28,12.0,local_40,local_58);
  VectorScale(local_40,1000.0,local_34);
  (*(gEngfuncs.pEfxAPI)->R_Projectile)(local_58,local_34,iVar3,6,uVar5,EV_TFC_NailTouch);
  iVar4 = (*gEngfuncs.pfnRandomLong)(0,5);
  if (iVar4 == 0) {
    iVar4 = (*gEngfuncs.pfnRandomLong)(0,1);
    p_Var2 = (gEngfuncs.pEventAPI)->EV_PlaySound;
    if (iVar4 == 0) {
      iVar4 = (*gEngfuncs.pfnRandomLong)(0,0xf);
      (*p_Var2)(-1,local_58,1,"weapons/airgun_1.wav",1.0,0.8,0,iVar4 + 0x5e);
    }
    else {
      iVar4 = (*gEngfuncs.pfnRandomLong)(0,0xf);
      (*p_Var2)(-1,local_58,1,"weapons/spike2.wav",1.0,0.8,0,iVar4 + 0x5e);
    }
  }
  local_48 = anglemod(fVar1 + local_48);
  (*gEngfuncs.pfnAngleVectors)(&local_4c,local_40,(float *)0x0,(float *)0x0);
  VectorMA(&local_28,12.0,local_40,local_58);
  VectorScale(local_40,1000.0,local_34);
  (*(gEngfuncs.pEfxAPI)->R_Projectile)(local_58,local_34,iVar3,6,uVar5,EV_TFC_NailTouch);
  iVar4 = (*gEngfuncs.pfnRandomLong)(0,5);
  if (iVar4 == 0) {
    iVar4 = (*gEngfuncs.pfnRandomLong)(0,1);
    p_Var2 = (gEngfuncs.pEventAPI)->EV_PlaySound;
    if (iVar4 == 0) {
      iVar4 = (*gEngfuncs.pfnRandomLong)(0,0xf);
      (*p_Var2)(-1,local_58,1,"weapons/airgun_1.wav",1.0,0.8,0,iVar4 + 0x5e);
    }
    else {
      iVar4 = (*gEngfuncs.pfnRandomLong)(0,0xf);
      (*p_Var2)(-1,local_58,1,"weapons/spike2.wav",1.0,0.8,0,iVar4 + 0x5e);
    }
  }
  local_48 = anglemod(fVar1 + local_48);
  (*gEngfuncs.pfnAngleVectors)(&local_4c,local_40,(float *)0x0,(float *)0x0);
  VectorMA(&local_28,12.0,local_40,local_58);
  VectorScale(local_40,1000.0,local_34);
  (*(gEngfuncs.pEfxAPI)->R_Projectile)(local_58,local_34,iVar3,6,uVar5,EV_TFC_NailTouch);
  iVar4 = (*gEngfuncs.pfnRandomLong)(0,5);
  if (iVar4 != 0) {
    return;
  }
  iVar4 = (*gEngfuncs.pfnRandomLong)(0,1);
  p_Var2 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  if (iVar4 == 0) {
    iVar4 = (*gEngfuncs.pfnRandomLong)(0,0xf);
    (*p_Var2)(-1,local_58,1,"weapons/airgun_1.wav",1.0,0.8,0,iVar4 + 0x5e);
    return;
  }
  iVar4 = (*gEngfuncs.pfnRandomLong)(0,0xf);
  (*p_Var2)(-1,local_58,1,"weapons/spike2.wav",1.0,0.8,0,iVar4 + 0x5e);
  return;
}


// EV_TFC_NapalmBurn  @ 00074720
void EV_TFC_NapalmBurn(event_args_t *args)

{
  int iVar1;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int firemodel@[???]
                       Unresolved local var: Vector origin@[???] */
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  iVar1 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/playerflame.spr");
  (*(gEngfuncs.pEfxAPI)->R_FireField)(&local_18,100,iVar1,0xc,0x12,0.8);
  return;
}


// EV_TFC_NapalmFire  @ 00074350
void EV_TFC_NapalmFire(event_args_t *args)

{
  int iVar1;
  physent_s_conflict *ppVar2;
  int32 iVar3;
  int iVar4;
  _func_int_int *p_Var5;
  _func_void_int_int_int_float_ptr_int *p_Var6;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  char *pcVar7;
  pmtrace_s local_90;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector upV@[???]
                       Unresolved local var: Vector downV@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: Vector origin@[???] */
                    /* Unresolved local var: float flRndSound@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: int iContents@[???]
                       Unresolved local var: int fireball@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float fExplosionScale@[???] */
  local_34 = args->origin[0];
  local_30 = args->origin[1];
  local_2c = args->origin[2];
  local_40 = local_34 + 0.0;
  local_3c = local_30 + 0.0;
  local_38 = local_2c + 8.0;
  local_4c = local_40 + 0.0;
  local_48 = local_3c + 0.0;
  local_44 = local_38 - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_40,&local_4c,2,-1,&local_90);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  local_28 = local_34;
  local_24 = local_30;
  local_20 = local_2c;
  if (local_90.fraction != 1.0) {
    VectorMA(&local_90.endpos.x,12.0,(float *)&local_90.plane,&local_28);
  }
  iVar1 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
  if ((iVar1 == -2) && (iVar1 = (*gEngfuncs.PM_PointContents)(&local_34,(int *)0x0), iVar1 == -2)) {
    return;
  }
  iVar1 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/explode01.spr");
  (*(gEngfuncs.pEfxAPI)->R_Explosion)(&local_28,iVar1,3.0,15.0,3);
  (*gEngfuncs.pfnRandomFloat)(0.0,1.0);
                    /* Unresolved local var: physent_t * pe@[???] */
  if (extraout_ST0 < (longdouble)0.5) {
    ppVar2 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(local_90.ent);
    if ((ppVar2 == (physent_s_conflict *)0x0) ||
       (((ppVar2->solid != 4 && (ppVar2->movetype != 0xd)) ||
        ((*gEngfuncs.pfnGetCvarFloat)("r_decals"), extraout_ST0_00 == (longdouble)0))))
    goto LAB_000744f0;
                    /* Unresolved local var: physent_t * pe@[???] */
    p_Var6 = (gEngfuncs.pEfxAPI)->R_DecalShoot;
    iVar1 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(&local_90);
    p_Var5 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
    pcVar7 = "{scorch1";
  }
  else {
                    /* Unresolved local var: physent_t * pe@[???] */
    ppVar2 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(local_90.ent);
    if (((ppVar2 == (physent_s_conflict *)0x0) ||
        ((ppVar2->solid != 4 && (ppVar2->movetype != 0xd)))) ||
       ((*gEngfuncs.pfnGetCvarFloat)("r_decals"), extraout_ST0_01 == (longdouble)0))
    goto LAB_000744f0;
                    /* Unresolved local var: physent_t * pe@[???] */
    p_Var6 = (gEngfuncs.pEfxAPI)->R_DecalShoot;
    iVar1 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(&local_90);
    p_Var5 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
    pcVar7 = "{scorch2";
  }
  iVar4 = (*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)(pcVar7);
  iVar4 = (*p_Var5)(iVar4);
  (*p_Var6)(iVar4,iVar1,0,&local_90.endpos.x,0);
LAB_000744f0:
  (*gEngfuncs.pfnRandomFloat)(0.0,1.0);
  iVar3 = (*gEngfuncs.pfnRandomLong)(0,2);
  if (iVar3 == 1) {
    pcVar7 = "weapons/debris2.wav";
  }
  else if (iVar3 == 2) {
    pcVar7 = "weapons/debris3.wav";
  }
  else {
    if (iVar3 != 0) {
      return;
    }
    pcVar7 = "weapons/debris1.wav";
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(-1,&local_28,2,pcVar7,0.55,0.8,0,100);
  return;
}


// EV_TFC_NormalGrenade  @ 00073ed0
void EV_TFC_NormalGrenade(event_args_t *args)

{
  pmtrace_t *pTrace;
  int bitsDamageType;
  pmtrace_s local_74;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector upV@[???]
                       Unresolved local var: Vector downV@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: Vector origin@[???] */
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  local_24 = local_18 + 0.0;
  local_20 = local_14 + 0.0;
  local_1c = local_10 + 8.0;
  local_30 = local_24 + 0.0;
  local_2c = local_20 + 0.0;
  local_28 = local_1c - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  bitsDamageType = 2;
  pTrace = (pmtrace_t *)&local_30;
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_24,(float *)pTrace,2,-1,&local_74);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  EV_TFC_Explode(&local_18,0xb4,(float)&local_74,0,pTrace,bitsDamageType);
  return;
}


// EV_TFC_NormalShot  @ 000767b0
void EV_TFC_NormalShot(event_args_t *args)

{
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???] */
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)
            (args->entindex,&local_18,3,"items/medshot4.wav",1.0,0.8,0,100);
  return;
}


// EV_TFC_PipeLauncher  @ 000757a0
void EV_TFC_PipeLauncher(event_args_t *args)

{
  int idx;
  qboolean qVar1;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_18 = args->origin[0];
  idx = args->entindex;
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(3,2);
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_18,3,"weapons/glauncher.wav",0.7,0.8,0,100);
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    V_PunchAxis(0,-2.0);
  }
  return;
}


// EV_TFC_PlayAxeAnim  @ 00075950
void EV_TFC_PlayAxeAnim(int idx,int classid,int iAnimType)

{
  int iVar1;
  qboolean qVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
                    /* Unresolved local var: int anim@[???] */
  qVar2 = EV_IsLocal(idx);
  if (qVar2 == 0) {
    return;
  }
                    /* Unresolved local var: int anim@[???] */
  if (classid == 1) {
    if (1 < (uint)iAnimType) {
      return;
    }
    iVar4 = *(int *)((int)&CSWTCH_206 + iAnimType * 4);
  }
  else {
    if (classid < 2) {
      if (classid != 0) {
        return;
      }
      if (1 < (uint)iAnimType) {
        return;
      }
      iVar4 = 2;
      goto LAB_00075a50;
    }
    if (classid != 2) {
      if (classid != 3) {
        return;
      }
      if (iAnimType == 0) {
        iVar1 = EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing + 1;
        if (EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing % 3 == 1) {
          iVar4 = 5;
          EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing = iVar1;
        }
        else if (EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing % 3 == 2) {
          iVar4 = 7;
          EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing = iVar1;
        }
        else {
          bVar5 = EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing !=
                  (EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing / 3) * 3;
          iVar4 = 4;
          EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing = iVar1;
          if (bVar5) {
            return;
          }
        }
      }
      else {
        if (iAnimType != 1) {
          return;
        }
        iVar4 = 6;
        iVar1 = EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing + 1;
        iVar3 = EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing % 2;
        EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing = iVar1;
        if (iVar3 != 0) {
          iVar4 = (uint)(iVar3 == 1) * 5 + 3;
        }
      }
      goto LAB_00075a50;
    }
    if (1 < (uint)iAnimType) {
      return;
    }
    iVar4 = *(int *)((int)&CSWTCH_204 + iAnimType * 4);
  }
  if (iVar4 == -1) {
    return;
  }
LAB_00075a50:
  qVar2 = EV_IsLocal(idx);
  if (qVar2 == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00075a84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(iVar4,2);
  return;
}


// EV_TFC_PlayAxeSound  @ 00075af0
void EV_TFC_PlayAxeSound(int idx,int classid,float *origin,int iSoundType,float fSoundData)

{
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var1;
  int32 iVar2;
  char *pcVar3;
  
  if (classid != 2) {
    if (iSoundType == 1) {
      iVar2 = (*gEngfuncs.pfnRandomLong)(0,2);
      if (iVar2 == 1) {
        pcVar3 = "weapons/cbar_hitbod2.wav";
      }
      else if (iVar2 == 2) {
        pcVar3 = "weapons/cbar_hitbod3.wav";
      }
      else {
        if (iVar2 != 0) {
          return;
        }
        pcVar3 = "weapons/cbar_hitbod1.wav";
      }
      (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,origin,1,pcVar3,1.0,0.8,0,100);
      return;
    }
    if (iSoundType == 2) {
      iVar2 = (*gEngfuncs.pfnRandomLong)(0,1);
      if (iVar2 == 0) {
        p_Var1 = (gEngfuncs.pEventAPI)->EV_PlaySound;
        iVar2 = (*gEngfuncs.pfnRandomLong)(0,3);
        (*p_Var1)(idx,origin,3,"weapons/cbar_hit1.wav",fSoundData,0.8,0,iVar2 + 0x62);
      }
      else if (iVar2 == 1) {
        p_Var1 = (gEngfuncs.pEventAPI)->EV_PlaySound;
        iVar2 = (*gEngfuncs.pfnRandomLong)(0,3);
        (*p_Var1)(idx,origin,3,"weapons/cbar_hit2.wav",fSoundData,0.8,0,iVar2 + 0x62);
      }
    }
    else if (iSoundType == 0) {
      p_Var1 = (gEngfuncs.pEventAPI)->EV_PlaySound;
      iVar2 = (*gEngfuncs.pfnRandomLong)(0,0xf);
      (*p_Var1)(idx,origin,1,"weapons/cbar_miss1.wav",1.0,0.8,0,iVar2 + 0x5e);
    }
  }
  return;
}


// EV_TFC_PlayCrowbarAnim  @ 000758b0
int EV_TFC_PlayCrowbarAnim(int iAnimType)

{
  int iVar1;
  int iVar2;
  
  iVar1 = EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing;
  if (iAnimType == 0) {
    EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing =
         EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing + 1;
    iVar2 = 5;
    if ((iVar1 % 3 != 1) && (iVar2 = 7, iVar1 % 3 != 2)) {
      return (-(uint)(iVar1 == (iVar1 / 3) * 3) & 5) - 1;
    }
  }
  else if (iAnimType == 1) {
    EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing =
         EV_TFC_PlayCrowbarAnim::lexical_block_0::m_iSwing + 1;
    iVar2 = 6;
    if (iVar1 % 2 != 0) {
      return (uint)(iVar1 % 2 == 1) * 5 + 3;
    }
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}


// EV_TFC_PlayKnifeAnim  @ 00075860
int EV_TFC_PlayKnifeAnim(int iAnimType)

{
  return (-(uint)((uint)iAnimType < 2) & 3) - 1;
}


// EV_TFC_PlayMedkitAnim  @ 00075870
int EV_TFC_PlayMedkitAnim(int iAnimType)

{
  if (1 < (uint)iAnimType) {
    return -1;
  }
  return *(int *)((int)&CSWTCH_204 + iAnimType * 4);
}


// EV_TFC_PlaySpannerAnim  @ 00075890
int EV_TFC_PlaySpannerAnim(int iAnimType)

{
  if (1 < (uint)iAnimType) {
    return -1;
  }
  return *(int *)((int)&CSWTCH_206 + iAnimType * 4);
}


// EV_TFC_PlayTextureSound  @ 0006f510
float EV_TFC_PlayTextureSound(int idx,pmtrace_t *ptr,float *vecSrc,float *vecEnd,int iBulletType)

{
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var1;
  char cVar2;
  int iVar3;
  int iVar4;
  int32 iVar5;
  float fVar6;
  char *__dest;
  int32 iVar7;
  float fVar8;
  longdouble extraout_ST0;
  char *pcVar9;
  float local_b8;
  char local_ac [2];
  char local_aa [62];
  char local_6c [12];
  undefined1 local_60;
  char *local_2c [7];
  
                    /* Unresolved local var: char chTextureType@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: float fvolbar@[???]
                       Unresolved local var: char *[4] rgsz@[???]
                       Unresolved local var: int cnt@[???]
                       Unresolved local var: float fattn@[???]
                       Unresolved local var: int entity@[???]
                       Unresolved local var: char * pTextureName@[???]
                       Unresolved local var: char[64] texname@[???]
                       Unresolved local var: char[64] szbuffer@[???] */
  iVar3 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(ptr);
  if (iVar3 < 1) {
    if ((iVar3 != 0) ||
       (pcVar9 = (*(gEngfuncs.pEventAPI)->EV_TraceTexture)(ptr->ent,vecSrc,vecEnd),
       pcVar9 == (char *)0x0)) goto LAB_0006f5d0;
    __dest = local_ac;
    strcpy(__dest,pcVar9);
    if ((local_ac[0] == '+') || (local_ac[0] == '-')) {
      __dest = local_aa;
      local_ac[0] = local_aa[0];
    }
    if ((((local_ac[0] == '!') || (local_ac[0] == '{')) || (local_ac[0] == '~')) ||
       (local_ac[0] == ' ')) {
      __dest = __dest + 1;
    }
    strcpy(local_6c,__dest);
    local_60 = 0;
    cVar2 = PM_FindTextureType(local_6c);
    switch(cVar2) {
    case 'D':
      iVar7 = 2;
      local_2c[0] = "player/pl_dirt1.wav";
      fVar6 = 0.8;
      local_2c[1] = "player/pl_dirt2.wav";
      fVar8 = 0.9;
      local_2c[2] = "player/pl_dirt3.wav";
      local_b8 = 0.1;
      goto LAB_0006f6b8;
    default:
      goto switchD_0006f7af_caseD_45;
    case 'F':
      goto switchD_0006f7af_caseD_46;
    case 'G':
      local_2c[0] = "player/pl_grate1.wav";
      fVar8 = 0.9;
      local_2c[1] = "player/pl_grate4.wav";
      local_b8 = 0.5;
      iVar7 = 1;
      break;
    case 'M':
      local_2c[0] = "player/pl_metal1.wav";
      iVar7 = 1;
      fVar8 = 0.9;
      local_2c[1] = "player/pl_metal2.wav";
      local_b8 = 0.3;
      break;
    case 'P':
    case 'Y':
      iVar7 = 2;
      local_2c[0] = "debris/glass1.wav";
      local_b8 = 0.2;
      fVar8 = 0.8;
      local_2c[1] = "debris/glass2.wav";
      local_2c[2] = "debris/glass3.wav";
      goto LAB_0006f5fe;
    case 'S':
      iVar7 = 3;
      local_2c[0] = "player/pl_slosh1.wav";
      fVar8 = 0.9;
      local_2c[1] = "player/pl_slosh3.wav";
      local_2c[2] = "player/pl_slosh2.wav";
      local_2c[3] = "player/pl_slosh4.wav";
      local_b8 = 0.0;
      break;
    case 'T':
      fVar8 = 0.8;
      iVar7 = 3;
      local_2c[3] = "player/pl_tile4.wav";
      local_b8 = 0.2;
      local_2c[0] = "player/pl_tile1.wav";
      local_2c[1] = "player/pl_tile3.wav";
      local_2c[2] = "player/pl_tile2.wav";
      break;
    case 'V':
      iVar7 = 1;
      local_2c[0] = "player/pl_duct1.wav";
      fVar8 = 0.5;
      local_2c[1] = "player/pl_duct1.wav";
      local_b8 = 0.3;
      break;
    case 'W':
      local_2c[0] = "debris/wood1.wav";
      local_b8 = 0.2;
      fVar8 = 0.9;
      local_2c[1] = "debris/wood2.wav";
      iVar7 = 2;
      local_2c[2] = "debris/wood3.wav";
    }
    fVar6 = 0.8;
  }
  else {
    iVar4 = (*gEngfuncs.GetMaxClients)();
    if (iVar3 <= iVar4) {
switchD_0006f7af_caseD_46:
      if (iBulletType == 5) {
        return 0.0;
      }
      fVar6 = 1.0;
      local_2c[0] = "weapons/bullet_hit1.wav";
      iVar7 = 1;
      local_2c[1] = "weapons/bullet_hit2.wav";
      local_b8 = 0.2;
      fVar8 = 1.0;
      goto LAB_0006f6b8;
    }
LAB_0006f5d0:
    cVar2 = '\0';
switchD_0006f7af_caseD_45:
    local_2c[0] = "player/pl_step1.wav";
    iVar7 = 1;
    fVar8 = 0.9;
    local_2c[1] = "player/pl_step2.wav";
    local_b8 = 0.6;
LAB_0006f5fe:
    if (((cVar2 == 'P') && (ptr->fraction != 1.0)) &&
       (iVar5 = (*gEngfuncs.pfnRandomLong)(0,1), iVar5 != 0)) {
                    /* Unresolved local var: float flVolume@[???] */
      (*(gEngfuncs.pEfxAPI)->R_SparkEffect)(&(ptr->endpos).x,8,-200,200);
      (*gEngfuncs.pfnRandomFloat)(0.7,1.0);
      iVar5 = (*gEngfuncs.pfnRandomLong)(0,1);
      if (iVar5 == 0) {
        pcVar9 = "buttons/spark5.wav";
      }
      else {
        if (iVar5 != 1) {
          fVar6 = 0.8;
          goto LAB_0006f6b8;
        }
        pcVar9 = "buttons/spark6.wav";
      }
      fVar6 = 0.8;
      (*(gEngfuncs.pEventAPI)->EV_PlaySound)
                (0,&(ptr->endpos).x,6,pcVar9,(float)extraout_ST0,0.8,0,100);
    }
    else {
      fVar6 = 0.8;
    }
  }
LAB_0006f6b8:
  p_Var1 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  iVar5 = (*gEngfuncs.pfnRandomLong)(0,0xf);
  iVar7 = (*gEngfuncs.pfnRandomLong)(0,iVar7);
  (*p_Var1)(0,&(ptr->endpos).x,6,local_2c[iVar7],fVar8,fVar6,0,iVar5 + 0x60);
  return local_b8;
}


// EV_TFC_RailDie  @ 00070560
void EV_TFC_RailDie(particle_s *particle)

{
  byte bVar1;
  physent_s_conflict *ppVar2;
  int iVar3;
  qboolean qVar4;
  int32 iVar5;
  int amount;
  pmtrace_t local_bc;
  char local_6c [32];
  vec_t local_4c;
  vec_t local_48;
  vec_t local_44;
  vec_t local_40;
  vec_t local_3c;
  vec_t local_38;
  float local_34 [3];
  float local_28 [6];
  
                    /* Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: Vector back@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: int context@[???] */
  if (particle == (particle_s *)0x0) {
    return;
  }
  local_40 = (particle->vel).x;
  bVar1 = particle->context;
  local_3c = (particle->vel).y;
  local_38 = (particle->vel).z;
  VectorNormalize(&local_40);
  local_4c = local_40;
  local_48 = local_3c;
  local_44 = local_38;
  VectorInverse(&local_4c);
  VectorMA((float *)particle,128.0,&local_4c,local_34);
  VectorMA(local_34,256.0,&local_40,local_28);
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(bVar1 - 1);
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(local_34,local_28,2,-1,&local_bc);
  if (local_bc.ent != -1) {
                    /* Unresolved local var: physent_t * pe@[???] */
    ppVar2 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(local_bc.ent);
    iVar3 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(&local_bc);
    qVar4 = EV_IsPlayer(iVar3);
    if (qVar4 != 0) {
      iVar3 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(&local_bc);
      iVar3 = EV_TFC_IsAlly(iVar3,(uint)bVar1);
      if (iVar3 == 0) {
        if ((cl_localblood != (cvar_t *)0x0) && (cl_localblood->value != 0.0)) {
          EV_TFC_BloodDrips(&local_bc.endpos.x,0x19,amount);
        }
        goto LAB_000706e0;
      }
    }
    if ((ppVar2 != (physent_s_conflict *)0x0) && ((ppVar2->solid == 4 || (ppVar2->movetype == 0xd)))
       ) {
                    /* Unresolved local var: char[32] decalname@[???]
                       Unresolved local var: int idx@[???] */
      local_6c[0] = '\0';
      iVar5 = (*gEngfuncs.pfnRandomLong)(0,4);
      sprintf(local_6c,"{shot%i",iVar5 + 1);
                    /* Unresolved local var: int iRand@[???]
                       Unresolved local var: physent_t * pe@[???] */
      if ((local_6c[0] != '\0') && (local_bc.fraction != 1.0)) {
        EV_TFC_GunshotDecalTrace(&local_bc,local_6c);
      }
    }
  }
LAB_000706e0:
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  return;
}


// EV_TFC_Railgun  @ 00072ae0
void EV_TFC_Railgun(event_args_t *args)

{
  int idx;
  qboolean qVar1;
  float fVar2;
  pmtrace_s local_d8;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c [3];
  float local_70 [3];
  float local_64 [3];
  float local_58 [3];
  float local_4c [3];
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: Vector ShellOrigin@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector tracerVelocity@[???]
                       Unresolved local var: int shell@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: float flSpread@[???]
                       Unresolved local var: float flTracerDist@[???]
                       Unresolved local var: Vector delta@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_34 = args->origin[0];
  idx = args->entindex;
  local_30 = args->origin[1];
  local_2c = args->origin[2];
  local_28 = args->angles[0];
  local_24 = args->angles[1];
  local_20 = args->angles[2];
  (*gEngfuncs.pfnAngleVectors)(&local_28,local_4c,local_58,local_64);
  (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("models/nail.mdl");
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    EV_MuzzleFlash();
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(1,2);
  }
  EV_GetGunPosition(args,&local_94,&local_34);
  VectorMA(&local_94,-4.0,local_64,&local_94);
  VectorMA(&local_94,2.0,local_58,&local_94);
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_34,1,"weapons/railgun.wav",0.9,0.8,0,100);
  local_88 = local_94;
  local_84 = local_90;
  local_80 = local_8c;
  VectorMA(&local_88,4096.0,local_4c,local_7c);
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(idx + -1);
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_88,local_7c,2,-1,&local_d8);
  local_40 = local_d8.endpos.x - local_88;
  local_3c = local_d8.endpos.y - local_84;
  local_38 = local_d8.endpos.z - local_80;
  fVar2 = Length(&local_40);
  VectorScale(local_4c,1500.0,local_70);
  (*(gEngfuncs.pEfxAPI)->R_UserTracerParticle)
            (&local_94,local_70,fVar2 / 1500.0,2,1.0,(uchar)idx,EV_TFC_RailDie);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    V_PunchAxis(0,-2.0);
  }
  return;
}


// EV_TFC_RandomBloodVector  @ 0006ff10
void EV_TFC_RandomBloodVector(float *direction)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-1.0,1.0);
  *direction = (float)lVar1;
  lVar1 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-1.0,1.0);
  direction[1] = (float)lVar1;
  lVar1 = (longdouble)(*gEngfuncs.pfnRandomFloat)(0.0,1.0);
  direction[2] = (float)lVar1;
  return;
}


// EV_TFC_ShouldShowBlood  @ 0006fd80
int EV_TFC_ShouldShowBlood(int color)

{
  uint uVar1;
  longdouble lVar2;
  char *pcVar3;
  
  uVar1 = 0;
  if (color != -1) {
    if (color == 0xf7) {
      pcVar3 = "violence_hblood";
    }
    else {
      pcVar3 = "violence_ablood";
    }
    lVar2 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)(pcVar3);
    uVar1 = 1;
    if ((longdouble)0 == lVar2) {
      uVar1 = (uint)(NAN((longdouble)0) || NAN(lVar2));
    }
  }
  return uVar1;
}


// EV_TFC_SniperHit  @ 00075310
void EV_TFC_SniperHit(event_args_s *args)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  char local_11c [256];
  float local_1c;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: int hit@[???]
                       Unresolved local var: int gib@[???]
                       Unresolved local var: float vol@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: char[256] sz@[???] */
  local_1c = args->origin[0];
  iVar1 = args->entindex;
  local_18 = args->origin[1];
  local_14 = args->origin[2];
  fVar2 = (float)args->iparam1 / 100.0;
  if (args->bparam2 == 0) {
    if (args->bparam1 == 0) {
      builtin_strncpy(local_11c,"weapons/ric3.wav",0x11);
    }
    else {
      uVar3 = 0;
      do {
        *(undefined4 *)(local_11c + uVar3) = *(undefined4 *)("weapons/bullet_hit2.wav" + uVar3);
        uVar3 = uVar3 + 4;
      } while (uVar3 < 0x18);
    }
  }
  else {
    uVar3 = 0;
    do {
      uVar4 = uVar3;
      *(undefined4 *)(local_11c + uVar4) = *(undefined4 *)("common/bodysplat.wav" + uVar4);
      uVar3 = uVar4 + 4;
    } while (uVar4 + 4 < 0x14);
    fVar2 = 1.0;
    local_11c[uVar4 + 4] = "common/bodysplat.wav"[uVar4 + 4];
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(iVar1,&local_1c,6,local_11c,fVar2,0.8,0,100);
  return;
}


// EV_TFC_Spanner  @ 00075ed0
int EV_TFC_Spanner(int idx,float *origin,float *forward,float *right,int entity,float *vecDir,
                  pmtrace_t *ptr)

{
  int iVar1;
  
  iVar1 = EV_TFC_IsAlly(idx,entity);
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
  if ((iVar1 == 0) && ((cl_localblood == (cvar_t *)0x0 || (cl_localblood->value != 0.0)))) {
    EV_TFC_TraceAttack(idx,(float)vecDir,(float *)ptr,(pmtrace_t *)0x41a00000,entity);
    return 1;
  }
  return 1;
}


// EV_TFC_SpawnBlood  @ 00070330
void EV_TFC_SpawnBlood(float *vecSpot,int bloodColor,float flDamage)

{
  EV_TFC_BloodDrips(vecSpot,bloodColor,(int)flDamage);
  return;
}


// EV_TFC_SteamShot  @ 00076740
void EV_TFC_SteamShot(event_args_t *args)

{
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???] */
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)
            (args->entindex,&local_18,3,"ambience/steamburst1.wav",1.0,0.8,0,100);
  return;
}


// EV_TFC_SuperShot  @ 00076820
void EV_TFC_SuperShot(event_args_t *args)

{
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???] */
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)
            (args->entindex,&local_18,3,"items/medshot5.wav",1.0,0.8,0,100);
  return;
}


// EV_TFC_TraceAttack  @ 0006ee80
void __regparm3
EV_TFC_TraceAttack(int idx,float flDamage,float *vecDir,pmtrace_t *ptr,int bitsDamageType)

{
  int iVar1;
  int iVar2;
  int iVar3;
  cl_entity_s *pcVar4;
  int extraout_ECX;
  int extraout_ECX_00;
  int amount;
  int extraout_ECX_01;
  int extraout_ECX_02;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
  VectorScale((float *)flDamage,-4.0,&local_24);
  local_18 = vecDir[5] - local_24;
  local_14 = vecDir[6] - local_20;
  local_10 = vecDir[7] - local_1c;
  iVar1 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)((pmtrace_s *)vecDir);
  if (iVar1 < 1) {
    return;
  }
  iVar2 = (*gEngfuncs.GetMaxClients)();
  if (iVar1 <= iVar2) {
                    /* Unresolved local var: int blood@[???]
                       Unresolved local var: cl_entity_t * ent@[???] */
    iVar3 = (*gEngfuncs.GetMaxClients)();
    iVar2 = -1;
    amount = extraout_ECX;
    if ((iVar1 <= iVar3) &&
       (pcVar4 = GetEntity(iVar1), amount = extraout_ECX_01, pcVar4 != (cl_entity_s *)0x0)) {
      iVar2 = (pcVar4->curstate).team;
    }
                    /* Unresolved local var: cl_entity_t * ent@[???] */
    if (((idx < 1) || (iVar1 = (*gEngfuncs.GetMaxClients)(), amount = extraout_ECX_00, iVar1 < idx))
       || (pcVar4 = GetEntity(idx), amount = extraout_ECX_02, pcVar4 == (cl_entity_s *)0x0)) {
      iVar1 = -1;
    }
    else {
      iVar1 = (pcVar4->curstate).team;
    }
    if (iVar2 != iVar1) {
      EV_TFC_BloodDrips(&local_18,(int)(float)ptr,amount);
    }
    return;
  }
  return;
}


// EV_TFC_TraceAttack  @ 000707e0
void EV_TFC_TraceAttack(int idx,float flDamage,float *vecDir,pmtrace_t *ptr,int bitsDamageType)

{
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
  if ((cl_localblood != (cvar_t *)0x0) && (cl_localblood->value == 0.0)) {
    return;
  }
  EV_TFC_TraceAttack(idx,(float)vecDir,(float *)ptr,(pmtrace_t *)flDamage,(int)flDamage);
  return;
}


// EV_TFC_TraceBleed  @ 00070120
void EV_TFC_TraceBleed(float flDamage,float *vecDir,pmtrace_t *ptr,int bitsDamageType,int bloodcolor
                      )

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  longdouble lVar6;
  int local_80;
  pmtrace_s local_78;
  float local_34;
  float local_30;
  float local_2c;
  float local_28 [6];
  
                    /* Unresolved local var: pmtrace_t Bloodtr@[???]
                       Unresolved local var: Vector vecTraceDir@[???]
                       Unresolved local var: float flNoise@[???]
                       Unresolved local var: int cCount@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: Vector trend@[???] */
  if (bloodcolor != -1) {
    if (flDamage == 0.0) {
      return;
    }
    if ((bitsDamageType & 0x8000c7U) != 0) {
      if (flDamage < 10.0) {
        fVar3 = -0.1;
        local_80 = 1;
        fVar5 = 0.1;
      }
      else if (25.0 <= flDamage) {
        fVar3 = -0.3;
        local_80 = 4;
        fVar5 = 0.3;
      }
      else {
        fVar3 = -0.2;
        local_80 = 2;
        fVar5 = 0.2;
      }
      iVar4 = 0;
      do {
        while( true ) {
          VectorScale(vecDir,-1.0,&local_34);
          fVar1 = local_34;
          lVar6 = (longdouble)(*gEngfuncs.pfnRandomFloat)(fVar3,fVar5);
          fVar2 = local_30;
          local_34 = (float)(lVar6 + (longdouble)fVar1);
          lVar6 = (longdouble)(*gEngfuncs.pfnRandomFloat)(fVar3,fVar5);
          fVar1 = local_2c;
          local_30 = (float)(lVar6 + (longdouble)fVar2);
          lVar6 = (longdouble)(*gEngfuncs.pfnRandomFloat)(fVar3,fVar5);
          local_2c = (float)(lVar6 + (longdouble)fVar1);
          VectorMA(&(ptr->endpos).x,-172.0,&local_34,local_28);
          (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&(ptr->endpos).x,local_28,2,-1,&local_78);
          if (local_78.fraction == 1.0) break;
          iVar4 = iVar4 + 1;
          EV_TFC_BloodDecalTrace(&local_78,bloodcolor);
          if (local_80 <= iVar4) {
            return;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < local_80);
    }
  }
  return;
}


// EV_TFC_TranqNailTouch  @ 0006ed80
void EV_TFC_TranqNailTouch(tempent_s *ent,pmtrace_t *ptr)

{
  int iVar1;
  int iVar2;
  int32 iVar3;
  physent_s_conflict *ppVar4;
  char local_2c [36];
  
                    /* Unresolved local var: char[32] decalname@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: qboolean player@[???] */
  iVar1 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(ptr);
  if (0 < iVar1) {
    iVar1 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(ptr);
    iVar2 = (*gEngfuncs.GetMaxClients)();
    if (iVar1 <= iVar2) {
      local_2c[0] = '\0';
      iVar3 = (*gEngfuncs.pfnRandomLong)(0,4);
      sprintf(local_2c,"{shot%i",iVar3 + 1);
      return;
    }
  }
  local_2c[0] = '\0';
  iVar3 = (*gEngfuncs.pfnRandomLong)(0,4);
  sprintf(local_2c,"{shot%i",iVar3 + 1);
                    /* Unresolved local var: physent_t * pe@[???] */
  ppVar4 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(ptr->ent);
                    /* Unresolved local var: int iRand@[???]
                       Unresolved local var: physent_t * pe@[???] */
  if (((ppVar4 != (physent_s_conflict *)0x0) &&
      (((ppVar4->solid == 4 || (ppVar4->movetype == 0xd)) && (local_2c[0] != '\0')))) &&
     (ptr->fraction != 1.0)) {
    EV_TFC_GunshotDecalTrace(ptr,local_2c);
  }
  return;
}


// EV_TFC_Tranquilizer  @ 00072900
void EV_TFC_Tranquilizer(event_args_t *args)

{
  int idx;
  int iVar1;
  qboolean qVar2;
  float local_70 [3];
  float local_64 [3];
  float local_58 [3];
  float local_4c [3];
  float local_40 [3];
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: Vector ShellOrigin@[???]
                       Unresolved local var: int shell@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: float flSpread@[???]
                       Unresolved local var: Vector vecVelocity@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_34 = args->origin[0];
  idx = args->entindex;
  local_30 = args->origin[1];
  local_2c = args->origin[2];
  local_28 = args->angles[0];
  local_24 = args->angles[1];
  local_20 = args->angles[2];
  (*gEngfuncs.pfnAngleVectors)(&local_28,local_4c,local_58,local_64);
  iVar1 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("models/nail.mdl");
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    EV_MuzzleFlash();
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(3,1);
  }
  EV_GetGunPosition(args,local_70,&local_34);
  VectorMA(local_70,-4.0,local_64,local_70);
  VectorMA(local_70,2.0,local_58,local_70);
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_34,1,"weapons/dartgun.wav",0.9,0.8,0,100);
  VectorScale(local_4c,1500.0,local_40);
  (*(gEngfuncs.pEfxAPI)->R_Projectile)
            (local_70,local_40,(int)(short)iVar1,6,idx,EV_TFC_TranqNailTouch);
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    V_PunchAxis(0,-2.0);
  }
  return;
}


// EV_TFC_WaterLevel  @ 000713d0
float EV_TFC_WaterLevel(float *position,float minz,float maxz)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float local_24;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: Vector midUp@[???]
                       Unresolved local var: float diff@[???] */
  local_14 = minz;
  local_1c = *position;
  local_18 = position[1];
  iVar3 = (*gEngfuncs.PM_PointContents)(&local_1c,(int *)0x0);
  fVar1 = minz;
  if (iVar3 == -3) {
    local_14 = maxz;
    iVar3 = (*gEngfuncs.PM_PointContents)(&local_1c,(int *)0x0);
    fVar1 = maxz;
    if (iVar3 != -3) {
      fVar2 = maxz - minz;
      local_24 = minz;
      fVar1 = local_14;
      while (1.0 < fVar2) {
        local_14 = fVar2 * 0.5 + local_24;
        iVar3 = (*gEngfuncs.PM_PointContents)(&local_1c,(int *)0x0);
        if (iVar3 == -3) {
          local_24 = local_14;
        }
        else {
          maxz = local_14;
        }
        fVar1 = local_14;
        fVar2 = maxz - local_24;
      }
    }
  }
  return fVar1;
}


// EV_TrainPitchAdjust  @ 0007f630
void EV_TrainPitchAdjust(event_args_t *args)

{
  uint uVar1;
  char local_11c [12];
  undefined4 local_110;
  undefined2 local_10c;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: ushort us_params@[???]
                       Unresolved local var: int noise@[???]
                       Unresolved local var: float m_flVolume@[???]
                       Unresolved local var: int pitch@[???]
                       Unresolved local var: int stop@[???]
                       Unresolved local var: char[256] sz@[???] */
  local_1c = args->origin[0];
  local_18 = args->origin[1];
  local_14 = args->origin[2];
  uVar1 = (uint)(ushort)args->iparam1;
  switch((int)uVar1 >> 0xc & 7) {
  default:
    goto switchD_0007f677_caseD_0;
  case 1:
    local_110 = 0x61772e31;
    break;
  case 2:
    local_110 = 0x61772e32;
    break;
  case 3:
    local_110 = 0x61772e33;
    break;
  case 4:
    local_110 = 0x61772e34;
    break;
  case 5:
    local_110 = 0x61772e36;
    break;
  case 6:
    local_110 = 0x61772e37;
  }
  if (args->bparam1 != 0) {
    local_10c = 0x76;
    builtin_strncpy(local_11c,"plats/ttrain",0xc);
    (*(gEngfuncs.pEventAPI)->EV_StopSound)(args->entindex,6,local_11c);
    return;
  }
  local_10c = 0x76;
  builtin_strncpy(local_11c,"plats/ttrain",0xc);
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)
            (args->entindex,&local_1c,6,local_11c,(float)(uVar1 & 0x3f) / 40.0,0.8,0x80,
             (int)((float)((int)uVar1 >> 6 & 0x3f) * 10.0));
switchD_0007f677_caseD_0:
  return;
}


