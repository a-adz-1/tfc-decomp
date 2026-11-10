// FlashlightTurnOff__11CBasePlayer  @ 000dbb50
void FlashlightTurnOff__11CBasePlayer(int *param_1)

{
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),1,"items/flashlight1.wav",0x3f800000,0x3f4ccccd,0,100
            );
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0xf7;
  (*DAT_001c10d8)(1,gmsgFlashlight,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001c10e0)(0);
  (*DAT_001c10e0)(param_1[0x1ab]);
  (*DAT_001c10dc)();
  param_1[0x1aa] = (int)(*gpGlobals + 0.2);
  return;
}


