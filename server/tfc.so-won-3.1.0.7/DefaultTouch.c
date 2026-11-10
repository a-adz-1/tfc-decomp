// DefaultTouch__15CBasePlayerAmmoP11CBaseEntity  @ 00120d00
void DefaultTouch__15CBasePlayerAmmoP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((*(byte *)(*param_2 + 0x1a4) & 8) != 0) {
    iVar1 = (**(code **)(param_1[0x111] + 0x108))(param_1,param_2);
    if (iVar1 == 0) {
      if (gEvilImpulse101 == 0) {
        return;
      }
    }
    else {
      iVar1 = (**(code **)(*g_pGameRules + 0xb0))(g_pGameRules,param_1);
      if (iVar1 == 3) {
        (**(code **)(param_1[0x111] + 0xc0))(param_1);
        return;
      }
    }
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


// DefaultTouch__15CBasePlayerItemP11CBaseEntity  @ 0011fd98
void DefaultTouch__15CBasePlayerItemP11CBaseEntity(int param_1,int *param_2)

{
  int iVar1;
  
  if ((*(byte *)(*param_2 + 0x1a4) & 8) != 0) {
    iVar1 = (**(code **)(*g_pGameRules + 0x7c))(g_pGameRules,param_2,param_1);
    if (iVar1 == 0) {
      if (gEvilImpulse101 != 0) {
        UTIL_Remove__FP11CBaseEntity(param_1);
      }
    }
    else {
      iVar1 = (**(code **)(param_2[0x111] + 0x5c))(param_2,param_1);
      if (iVar1 != 0) {
        (**(code **)(*(int *)(param_1 + 0x444) + 0x140))(param_1,param_2);
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_2 + 0x208),3,"items/gunpickup2.wav",0x3f800000,0x3f4ccccd,
                   0,100);
      }
      SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_2,3,0);
    }
  }
  return;
}


