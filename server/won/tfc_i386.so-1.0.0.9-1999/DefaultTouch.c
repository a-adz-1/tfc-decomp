// DefaultTouch__15CBasePlayerAmmoP11CBaseEntity  @ 0011be40
void DefaultTouch__15CBasePlayerAmmoP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((*(byte *)(*param_2 + 0x184) & 8) != 0) {
    iVar1 = (**(code **)(param_1[0xf2] + 0x100))(param_1,param_2);
    if (iVar1 == 0) {
      if (gEvilImpulse101 == 0) {
        return;
      }
    }
    else {
      iVar1 = (**(code **)(*g_pGameRules + 0xb0))(g_pGameRules,param_1);
      if (iVar1 == 3) {
        (**(code **)(param_1[0xf2] + 0xb8))(param_1);
        return;
      }
    }
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  }
  return;
}


// DefaultTouch__15CBasePlayerItemP11CBaseEntity  @ 0011af70
void DefaultTouch__15CBasePlayerItemP11CBaseEntity(int param_1,int *param_2)

{
  int iVar1;
  
  if ((*(byte *)(*param_2 + 0x184) & 8) != 0) {
    iVar1 = (**(code **)(*g_pGameRules + 0x7c))(g_pGameRules,param_2,param_1);
    if (iVar1 == 0) {
      if (gEvilImpulse101 != 0) {
        UTIL_Remove__FP11CBaseEntity(param_1);
      }
    }
    else {
      iVar1 = (**(code **)(param_2[0xf2] + 0x58))(param_2,param_1);
      if (iVar1 != 0) {
        (**(code **)(*(int *)(param_1 + 0x3c8) + 0x138))(param_1,param_2);
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_2 + 0x1e8),3,"items/gunpickup2.wav",0x3f800000,0x3f4ccccd,
                   0,100);
      }
      SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_2,3,0);
    }
  }
  return;
}


