// FlashlightTurnOn__11CBasePlayer  @ 000dba60
void FlashlightTurnOn__11CBasePlayer(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x14))(g_pGameRules);
  if ((iVar1 != 0) && (*(int *)(*param_1 + 0x168) < 0)) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),1,"items/flashlight1.wav",0x3f800000,0x3f4ccccd,0,
               100);
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 8;
    (*DAT_001c10d8)(1,gmsgFlashlight,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_001c10e0)(1);
    (*DAT_001c10e0)(param_1[0x1ab]);
    (*DAT_001c10dc)();
    param_1[0x1aa] = (int)(*gpGlobals + 1.2);
  }
  return;
}


