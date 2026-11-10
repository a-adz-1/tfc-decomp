// FlashlightTurnOff__11CBasePlayer  @ 000e56ac
void FlashlightTurnOff__11CBasePlayer(int *param_1)

{
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),1,"items/flashlight1.wav",0x3f800000,0x3f4ccccd,0,100
            );
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0xf7;
  (*DAT_0019f758)(1,gmsgFlashlight,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_0019f760)(0);
  (*DAT_0019f760)(param_1[0x1b4]);
  (*DAT_0019f75c)();
  param_1[0x1b3] = (int)(*gpGlobals + 0.2);
  return;
}


