// ClientDisconnect__FP7edict_s  @ 0008f8e8
void ClientDisconnect__FP7edict_s(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  char local_100 [256];
  
  if (g_fGameOver == 0) {
    sprintf(local_100,"- %s has left the game\n",
            *(int *)(param_1 + 0x250) + *(int *)(gpGlobals + 0x98));
    (*DAT_001c10d8)(2,gmsgSayText,0,0);
    uVar1 = (*DAT_001c113c)(param_1);
    (*DAT_001c10e0)(uVar1);
    (*DAT_001c10f8)(local_100);
    (*DAT_001c10dc)();
    uVar1 = ClientSoundIndex__9CSoundEntP7edict_s(param_1);
    iVar2 = SoundPointerForIndex__9CSoundEnti(uVar1);
    if (iVar2 != 0) {
      Reset__6CSound(iVar2);
    }
    *(undefined4 *)(param_1 + 0x1ec) = 0;
    *(undefined4 *)(param_1 + 0x18c) = 0;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(param_1 + 0x80,param_1 + 0x88);
    EMIT_SOUND_DYN__FP7edict_siPCcffii(param_1,4,"player/gib.wav",0x3f800000,0,0,100);
    (**(code **)(*g_pGameRules + 0x3c))(g_pGameRules,param_1);
  }
  return;
}


