// FlashlightTurnOn__11CBasePlayer  @ 000dd8a0
void FlashlightTurnOn__11CBasePlayer(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x14))(g_pGameRules);
  if ((iVar1 != 0) && (*(int *)(*param_1 + 0x148) < 0)) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),1,"items/flashlight1.wav",0x3f800000,0x3f4ccccd,0,
               100);
    *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 8;
    (*DAT_00175578)(1,gmsgFlashlight,0,*(undefined4 *)(*param_1 + 0x1e8));
    (*DAT_00175580)(1);
    (*DAT_00175580)(param_1[0x18b]);
    (*DAT_0017557c)();
    param_1[0x18a] = (int)(*gpGlobals + 1.2);
  }
  return;
}


