// VoiceTweak_EndVoiceTweakMode  @ 001b31a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VoiceTweak_EndVoiceTweakMode(void)

{
  if (!g_bInTweakMode) {
    return;
  }
  g_bInTweakMode = false;
  Voice_RecordStop();
  return;
}


// VoiceTweak_GetControlFloat  @ 001b1f50
float VoiceTweak_GetControlFloat(VoiceTweakControl_conflict iControl)

{
  float local_10 [4];
  
  if (g_pMixerControls == (IMixerControls *)0x0) {
    return 0.0;
  }
  if (iControl == MicrophoneVolume) {
                    /* Unresolved local var: float value@[???] */
    local_10[0] = 1.0;
    (*g_pMixerControls->_vptr_IMixerControls[3])(g_pMixerControls,1,local_10);
    return local_10[0];
  }
  if (iControl == OtherSpeakerScale) {
    return voice_scale.value;
  }
  if (iControl != MicBoost) {
    return 1.0;
  }
                    /* Unresolved local var: float value@[???] */
  local_10[0] = 1.0;
  (*g_pMixerControls->_vptr_IMixerControls[3])(g_pMixerControls,0,local_10);
  return local_10[0];
}


// VoiceTweak_GetSpeakingVolume  @ 001b1eb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VoiceTweak_GetSpeakingVolume(void)

{
  return g_VoiceVolume;
}


// VoiceTweak_SetControlFloat  @ 001b1ec0
void VoiceTweak_SetControlFloat(VoiceTweakControl_conflict iControl,float value)

{
  if (g_pMixerControls != (IMixerControls *)0x0) {
    if (iControl == MicrophoneVolume) {
      (*g_pMixerControls->_vptr_IMixerControls[4])(g_pMixerControls,1,value);
      return;
    }
    if (iControl == OtherSpeakerScale) {
      voice_scale.value = value;
      return;
    }
    if (iControl == MicBoost) {
      (*g_pMixerControls->_vptr_IMixerControls[4])(g_pMixerControls,0,value);
      return;
    }
  }
  return;
}


// VoiceTweak_StartVoiceTweakMode  @ 001b31c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

int VoiceTweak_StartVoiceTweakMode(void)

{
  IVoiceCodec *pIVar1;
  float scale;
  float maxGain;
  float avgToMaxVal;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  CVoiceChannel *pCVar5;
  int iVar6;
  
  if (g_bInTweakMode) {
    return 0;
  }
  if (g_pMixerControls == (IMixerControls *)0x0) {
    return 0;
  }
  iVar6 = 0;
  pCVar5 = g_VoiceChannels;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
    VoiceSE_EndChannel(iVar6);
    if (-1 < pCVar5->m_iEntity) {
      ClientDLL_VoiceStatus(pCVar5->m_iEntity,false);
      VoiceSE_CloseMouth(pCVar5->m_iEntity);
    }
    iVar6 = iVar6 + 1;
    pCVar5->m_iEntity = -1;
    pCVar5 = pCVar5 + 1;
  } while (iVar6 != 5);
  Voice_RecordStop();
  if (g_pEncodeCodec != (IVoiceCodec *)0x0) {
    (*(g_pEncodeCodec->super_IBaseInterface)._vptr_IBaseInterface[6])(g_pEncodeCodec);
  }
  if ((g_bUsingSteamVoice == false) ||
     (piVar3 = (int *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext),
     *piVar3 == 0)) {
    if (g_pVoiceRecord == (IVoiceRecord *)0x0) {
      g_bVoiceRecording = 0;
      goto LAB_001b326e;
    }
    uVar2 = (*g_pVoiceRecord->_vptr_IVoiceRecord[3])(g_pVoiceRecord);
    g_bVoiceRecording = uVar2 & 0xff;
    if ((char)uVar2 == '\0') goto LAB_001b326e;
  }
  else {
    puVar4 = (undefined4 *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
    (**(code **)(*(int *)*puVar4 + 0x1c))((int *)*puVar4);
    g_bVoiceRecording = 1;
  }
  ClientDLL_VoiceStatus(-1,true);
LAB_001b326e:
                    /* Unresolved local var: int iFree@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
  if ((g_bInTweakMode == false) && (g_VoiceChannels[0].m_iEntity != -500)) {
    if (g_VoiceChannels[0].m_iEntity == -1) {
      iVar6 = 0;
    }
    else {
      if (g_VoiceChannels[1].m_iEntity == -500) {
        g_bInTweakMode = true;
        return 1;
      }
      if (g_VoiceChannels[1].m_iEntity == -1) {
        iVar6 = 1;
      }
      else {
        if (g_VoiceChannels[2].m_iEntity == -500) {
          g_bInTweakMode = true;
          return 1;
        }
        if (g_VoiceChannels[2].m_iEntity == -1) {
          iVar6 = 2;
        }
        else {
          if (g_VoiceChannels[3].m_iEntity == -500) {
            g_bInTweakMode = true;
            return 1;
          }
          if (g_VoiceChannels[3].m_iEntity == -1) {
            iVar6 = 3;
          }
          else {
            if (g_VoiceChannels[4].m_iEntity == -500) {
              g_bInTweakMode = true;
              return 1;
            }
            iVar6 = 4;
            if (g_VoiceChannels[4].m_iEntity != -1) {
              g_bInTweakMode = true;
              return 1;
            }
          }
        }
      }
    }
    pIVar1 = g_VoiceChannels[iVar6].m_pVoiceCodec;
    if (pIVar1 != (IVoiceCodec *)0x0) {
      (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[6])(pIVar1);
    }
    g_VoiceChannels[iVar6].m_iEntity = -500;
    g_VoiceChannels[iVar6].m_bStarved = false;
    CCircularBuffer::Flush(&g_VoiceChannels[iVar6].m_Buffer.super_CCircularBuffer);
    avgToMaxVal = voice_avggain.value;
    maxGain = voice_maxgain.value;
    scale = voice_scale.value;
    g_VoiceChannels[iVar6].m_LastSample = 0;
    *(undefined4 *)&g_VoiceChannels[iVar6].m_LastFraction = 0xd916872b;
    *(undefined4 *)((int)&g_VoiceChannels[iVar6].m_LastFraction + 4) = 0x3feff7ce;
    g_VoiceChannels[iVar6].m_TimePad = 0.2;
    CAutoGain::Reset(&g_VoiceChannels[iVar6].m_AutoGain,0x80,maxGain,avgToMaxVal,scale);
    VoiceSE_StartOverdrive();
  }
  g_bInTweakMode = true;
  return 1;
}


