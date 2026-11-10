// PlaySentence__12CBaseMonsterPCcfff  @ 000b6708
void PlaySentence__12CBaseMonsterPCcfff
               (int *param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  if (param_2 != (char *)0x0) {
    iVar1 = (**(code **)(param_1[0xf5] + 0x88))(param_1);
    if (iVar1 != 0) {
      if (*param_2 == '!') {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x208),2,param_2,param_4,param_5,0,100);
      }
      else {
        SENTENCEG_PlayRndSz__FP7edict_sPCcffii
                  (*(undefined4 *)(*param_1 + 0x208),param_2,param_4,param_5,0,100);
      }
    }
  }
  return;
}


// PlaySentence__12CTalkMonsterPCcfff  @ 000e9670
void PlaySentence__12CTalkMonsterPCcfff
               (int *param_1,char *param_2,float param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if (param_2 != (char *)0x0) {
    Talk__12CTalkMonsterf(param_1,param_3);
    _12CTalkMonster_g_talkWaitTime = param_3 + *gpGlobals + 2.0;
    if (*param_2 == '!') {
      uVar1 = GetVoicePitch__12CTalkMonster(param_1);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),2,param_2,param_4,param_5,0,uVar1);
    }
    else {
      uVar1 = GetVoicePitch__12CTalkMonster(param_1);
      SENTENCEG_PlayRndSz__FP7edict_sPCcffii
                (*(undefined4 *)(*param_1 + 0x208),param_2,param_4,param_5,0,uVar1);
    }
    *(byte *)(param_1 + 0x187) = *(byte *)(param_1 + 0x187) | 8;
  }
  return;
}


