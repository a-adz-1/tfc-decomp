// Recharge__11CWallHealth  @ 000b5720
void Recharge__11CWallHealth(int *param_1)

{
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),3,"items/medshot4.wav",0x3f800000,0x3f4ccccd,0,100);
  param_1[0x140] = (int)ROUND(DAT_001a1d20);
  *(undefined4 *)(*param_1 + 0x130) = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_DoNothing__11CBaseEntity;
  return;
}


// Recharge__9CRecharge  @ 000b2de0
void Recharge__9CRecharge(int *param_1)

{
  param_1[0x140] = (int)ROUND(DAT_001a1d18);
  *(undefined4 *)(*param_1 + 0x130) = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_DoNothing__11CBaseEntity;
  return;
}


