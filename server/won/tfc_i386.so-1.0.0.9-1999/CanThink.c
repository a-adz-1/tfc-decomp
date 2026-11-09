// CanThink__9CItemSoda  @ 000affb0
void CanThink__9CItemSoda(int *param_1)

{
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x1e8),1,"weapons/g_bounce3.wav",0x3f800000,0x3f4ccccd,0,100
            );
  *(undefined4 *)(*param_1 + 0xec) = 1;
  uStack_10 = 0x41000000;
  uStack_c = 0x41000000;
  uStack_8 = 0x41000000;
  uStack_1c = 0xc1000000;
  uStack_18 = 0xc1000000;
  uStack_14 = 0;
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&uStack_1c,&uStack_10);
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = -0x10000;
  param_1[6] = (int)CanTouch__9CItemSodaP11CBaseEntity;
  return;
}


