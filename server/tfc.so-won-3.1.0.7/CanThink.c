// CanThink__9CItemSoda  @ 000a5644
void CanThink__9CItemSoda(int *param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),1,"weapons/g_bounce3.wav",0x3f800000,0x3f4ccccd,0,100
            );
  *(undefined4 *)(*param_1 + 0x10c) = 1;
  local_c = 0x41000000;
  local_18 = 0xc1000000;
  local_10 = 0;
  local_14 = local_18;
  local_8 = local_c;
  local_4 = local_c;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_18,&local_c);
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = -0x10000;
  param_1[6] = (int)CanTouch__9CItemSodaP11CBaseEntity;
  return;
}


