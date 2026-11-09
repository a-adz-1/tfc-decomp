// Retire__11CBaseTurret  @ 00114dd0
void Retire__11CBaseTurret(int *param_1)

{
  int iVar1;
  
  param_1[0x19b] = 0;
  param_1[0x19c] = param_1[0x197];
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  (**(code **)(param_1[0xf2] + 0x224))(param_1);
  iVar1 = MoveTurret__11CBaseTurret(param_1);
  if (iVar1 == 0) {
    if (param_1[0x185] == 0) {
      if (*(int *)(*param_1 + 0x108) == 4) {
        if (param_1[0xf8] != 0) {
          param_1[0x18e] = 0;
          param_1[0x194] = 0;
          SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,0);
          *(float *)(*param_1 + 0xd0) = (float)param_1[0x189];
          *(float *)(*param_1 + 0xc4) = (float)-param_1[0x189];
          iVar1 = *param_1;
          UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar1,iVar1 + 0xbc,iVar1 + 200);
          if (param_1[400] == 0) {
            param_1[3] = -0x10000;
            param_1[4] = (int)SUB_DoNothing__11CBaseEntity;
          }
          else {
            param_1[3] = -0x10000;
            param_1[4] = (int)AutoSearchThink__11CBaseTurret;
            *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
          }
        }
      }
      else {
        SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,4);
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x1e8),4,"turret/tu_deploy.wav",0x3f000000,0x3f4ccccd,
                   0,0x78);
        SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,0,0);
      }
    }
    else {
      (**(code **)(param_1[0xf2] + 0x214))(param_1);
    }
  }
  else {
    SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,2);
  }
  return;
}


