// TankTouch__8CAirtankP11CBaseEntity  @ 0007f3ec
void TankTouch__8CAirtankP11CBaseEntity(int *param_1,int *param_2)

{
  if ((*(byte *)(*param_2 + 0x1a4) & 8) != 0) {
    if (param_1[0x18e] == 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),4,"player/pl_swim2.wav",0x3f800000,0x3f4ccccd,0,
                 100);
    }
    else {
      *(float *)(*param_2 + 0x1fc) = *gpGlobals + 12.0;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),2,"doors/aliendoor3.wav",0x3f800000,0x3f4ccccd,0,
                 100);
      *(float *)(*param_1 + 0x104) = *gpGlobals + 30.0;
      param_1[0x18e] = 0;
      SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0x3f800000);
    }
  }
  return;
}


