// ClientDisconnect__FP7edict_s  @ 000a1de0
void ClientDisconnect__FP7edict_s(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  char local_104 [256];
  
  if (g_fGameOver == 0) {
    sprintf(local_104,"- %s has left the game\n",
            *(int *)(param_1 + 0x28c) + *(int *)(gpGlobals + 0x98));
    (*DAT_00175578)(2,gmsgSayText,0,0);
    uVar1 = (*DAT_001755dc)(param_1);
    (*DAT_00175580)(uVar1);
    (*DAT_00175598)(local_104);
    (*DAT_0017557c)();
    uVar1 = ClientSoundIndex__9CSoundEntP7edict_s(param_1);
    iVar2 = SoundPointerForIndex__9CSoundEnti(uVar1);
    if (iVar2 != 0) {
      Reset__6CSound(iVar2);
    }
    *(undefined4 *)(param_1 + 0x228) = 0;
    *(undefined4 *)(param_1 + 0x1c8) = 0;
    UTIL_SetOrigin__FP9entvars_tRC6Vector(param_1 + 0xdc,param_1 + 0xe4);
    EMIT_SOUND_DYN__FP7edict_siPCcffii(param_1,4,"player/gib.wav",0x3f800000,0,0,100);
    (**(code **)(*g_pGameRules + 0x3c))(g_pGameRules,param_1);
  }
  return;
}


