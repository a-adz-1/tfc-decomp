// FlashlightTurnOn__11CBasePlayer  @ 000dac00
void FlashlightTurnOn__11CBasePlayer(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x14))(g_pGameRules);
  if ((iVar1 != 0) && (*(int *)(*param_1 + 0x168) < 0)) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),1,"items/flashlight1.wav",0x3f800000,0x3f4ccccd,0,
               100);
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 8;
    (*DAT_0019f758)(1,gmsgFlashlight,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f760)(1);
    (*DAT_0019f760)(param_1[0x1b4]);
    (*DAT_0019f75c)();
    param_1[0x1b3] = (int)(*gpGlobals + 1.2);
  }
  return;
}


