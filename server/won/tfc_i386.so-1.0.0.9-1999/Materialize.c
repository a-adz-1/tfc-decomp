// Materialize__15CBasePlayerAmmo  @ 0011bdd0
void Materialize__15CBasePlayerAmmo(int *param_1)

{
  if (*(char *)(*param_1 + 0xf8) < '\0') {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),1,"items/suitchargeok1.wav",0x3f800000,0x3f4ccccd,0
               ,0x96);
    *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) & 0x7f;
    *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 2;
  }
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerAmmoP11CBaseEntity;
  return;
}


// Materialize__15CBasePlayerItem  @ 0011ad70
void Materialize__15CBasePlayerItem(int *param_1)

{
  if (*(char *)(*param_1 + 0xf8) < '\0') {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),1,"items/suitchargeok1.wav",0x3f800000,0x3f4ccccd,0
               ,0x96);
    *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) & 0x7f;
    *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 2;
  }
  *(undefined4 *)(*param_1 + 0xec) = 1;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  param_1[5] = -0x10000;
  param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}


// Materialize__5CItem  @ 000bd820
void Materialize__5CItem(int *param_1)

{
  if (*(char *)(*param_1 + 0xf8) < '\0') {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),1,"items/suitchargeok1.wav",0x3f800000,0x3f4ccccd,0
               ,0x96);
    *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) & 0x7f;
    *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 2;
  }
  else {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),1,"items/itembk2.wav",0x3f800000,0x3f4ccccd,0,0x96)
    ;
  }
  param_1[5] = -0x10000;
  param_1[6] = (int)ItemTouch__5CItemP11CBaseEntity;
  return;
}


