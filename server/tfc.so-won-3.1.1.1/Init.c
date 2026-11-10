// Init__13CVoiceGameMgrP19IVoiceGameMgrHelperi  @ 0013b248
undefined4
Init__13CVoiceGameMgrP19IVoiceGameMgrHelperi(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  param_1[2] = param_2;
  if (param_3 < 0x21) {
    param_1[3] = param_3;
  }
  else {
    param_1[3] = 0x20;
  }
  (*g_engfuncs)("sprites/voiceicon.spr");
  uVar1 = (*DAT_0019f7cc)("VoiceMask",8);
  *param_1 = uVar1;
  uVar1 = (*DAT_0019f7cc)("ReqState",0);
  param_1[1] = uVar1;
  iVar2 = (*DAT_0019f870)("voice_serverdebug");
  if (iVar2 == 0) {
    (*DAT_0019f780)(voice_serverdebug);
  }
  iVar2 = (*DAT_0019f870)("sv_alltalk");
  if (iVar2 == 0) {
    (*DAT_0019f780)(sv_alltalk);
  }
  return 1;
}


