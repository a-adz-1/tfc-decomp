// FlashlightTurnOff__11CBasePlayer  @ 000d0488
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FlashlightTurnOff__11CBasePlayer(int *param_1)

{
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),1,"items/flashlight1.wav",0x3f800000,0x3f4ccccd,0,100
            );
  *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0xf7;
  (*DAT_001a7ef8)(1,gmsgFlashlight,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001a7f00)(0);
  (*DAT_001a7f00)(param_1[399]);
  (*DAT_001a7efc)();
  param_1[0x18e] = (int)((float)_FUN_0013ae80 + *gpGlobals);
  return;
}


