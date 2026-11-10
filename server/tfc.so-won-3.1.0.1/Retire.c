// Retire__11CBaseTurret  @ 00107f94
void Retire__11CBaseTurret(int *param_1)

{
  int iVar1;
  
  param_1[0x19e] = 0;
  param_1[0x19f] = param_1[0x19a];
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  (**(code **)(param_1[0xf5] + 0x224))(param_1);
  iVar1 = MoveTurret__11CBaseTurret(param_1);
  if (iVar1 == 0) {
    if (param_1[0x188] == 0) {
      if (*(int *)(*param_1 + 0x128) == 4) {
        if (param_1[0xfb] != 0) {
          param_1[0x191] = 0;
          param_1[0x197] = 0;
          SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,0);
          *(float *)(*param_1 + 0xf0) = (float)param_1[0x18c];
          *(float *)(*param_1 + 0xe4) = (float)-param_1[0x18c];
          iVar1 = *param_1;
          UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar1,iVar1 + 0xdc,iVar1 + 0xe8);
          if (param_1[0x193] == 0) {
            param_1[3] = -0x10000;
            param_1[4] = (int)SUB_DoNothing__11CBaseEntity;
          }
          else {
            param_1[3] = -0x10000;
            param_1[4] = (int)AutoSearchThink__11CBaseTurret;
            *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
          }
        }
      }
      else {
        SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,4);
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x208),4,"turret/tu_deploy.wav",0x3f000000,0x3f4ccccd,
                   0,0x78);
        SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,0,0);
      }
    }
    else {
      (**(code **)(param_1[0xf5] + 0x214))(param_1);
    }
  }
  else {
    SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,2);
  }
  return;
}


