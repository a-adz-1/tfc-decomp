// Materialize__15CBasePlayerAmmo  @ 00120c90
void Materialize__15CBasePlayerAmmo(int *param_1)

{
  if (*(char *)(*param_1 + 0x118) < '\0') {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),1,"items/suitchargeok1.wav",0x3f800000,0x3f4ccccd,0
               ,0x96);
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0x7f;
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 2;
  }
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerAmmoP11CBaseEntity;
  return;
}


// Materialize__15CBasePlayerItem  @ 0011fb4c
void Materialize__15CBasePlayerItem(int *param_1)

{
  if (*(char *)(*param_1 + 0x118) < '\0') {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),1,"items/suitchargeok1.wav",0x3f800000,0x3f4ccccd,0
               ,0x96);
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0x7f;
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 2;
  }
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}


// Materialize__5CItem  @ 000b6c6c
void Materialize__5CItem(int *param_1)

{
  if (*(char *)(*param_1 + 0x118) < '\0') {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),1,"items/suitchargeok1.wav",0x3f800000,0x3f4ccccd,0
               ,0x96);
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0x7f;
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 2;
  }
  else {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),1,"items/itembk2.wav",0x3f800000,0x3f4ccccd,0,0x96)
    ;
  }
  param_1[5] = -0x10000;
  param_1[6] = (int)ItemTouch__5CItemP11CBaseEntity;
  return;
}


