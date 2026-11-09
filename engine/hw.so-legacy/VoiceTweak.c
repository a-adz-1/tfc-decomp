// VoiceTweak_EndVoiceTweakMode  @ 002027e0
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


// VoiceTweak_GetControlFloat  @ 00201fe0
float VoiceTweak_GetControlFloat(VoiceTweakControl_conflict iControl)

{
  float fVar1;
  float local_10 [4];
  
  fVar1 = 0.0;
  if (g_pMixerControls != (IMixerControls *)0x0) {
    if (iControl == MicrophoneVolume) {
                    /* Unresolved local var: float value@[???] */
      local_10[0] = 1.0;
      (*g_pMixerControls->_vptr_IMixerControls[3])(g_pMixerControls,1,local_10);
      return local_10[0];
    }
    if (iControl == OtherSpeakerScale) {
      return voice_scale.value;
    }
    fVar1 = 1.0;
    if (iControl == MicBoost) {
                    /* Unresolved local var: float value@[???] */
      local_10[0] = 1.0;
      (*g_pMixerControls->_vptr_IMixerControls[3])(g_pMixerControls,0,local_10);
      return local_10[0];
    }
  }
  return fVar1;
}


// VoiceTweak_GetSpeakingVolume  @ 00201f50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VoiceTweak_GetSpeakingVolume(void)

{
  return g_VoiceVolume;
}


// VoiceTweak_SetControlFloat  @ 00201f60
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


// VoiceTweak_StartVoiceTweakMode  @ 00202f00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

int VoiceTweak_StartVoiceTweakMode(void)

{
  IVoiceCodec *pIVar1;
  float scale;
  uint uVar2;
  int *piVar3;
  CVoiceChannel *pCVar4;
  int iVar5;
  
  if (g_bInTweakMode) {
    return 0;
  }
  if (g_pMixerControls == (IMixerControls *)0x0) {
    return 0;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
  VoiceSE_EndChannel(0);
  if (-1 < g_VoiceChannels[0].m_iEntity) {
    ClientDLL_VoiceStatus(g_VoiceChannels[0].m_iEntity,false);
    VoiceSE_CloseMouth(g_VoiceChannels[0].m_iEntity);
  }
  g_VoiceChannels[0].m_iEntity = -1;
  VoiceSE_EndChannel(1);
  if (-1 < g_VoiceChannels[1].m_iEntity) {
    ClientDLL_VoiceStatus(g_VoiceChannels[1].m_iEntity,false);
    VoiceSE_CloseMouth(g_VoiceChannels[1].m_iEntity);
  }
  g_VoiceChannels[1].m_iEntity = -1;
  VoiceSE_EndChannel(2);
  if (-1 < g_VoiceChannels[2].m_iEntity) {
    ClientDLL_VoiceStatus(g_VoiceChannels[2].m_iEntity,false);
    VoiceSE_CloseMouth(g_VoiceChannels[2].m_iEntity);
  }
  g_VoiceChannels[2].m_iEntity = -1;
  VoiceSE_EndChannel(3);
  if (-1 < g_VoiceChannels[3].m_iEntity) {
    ClientDLL_VoiceStatus(g_VoiceChannels[3].m_iEntity,false);
    VoiceSE_CloseMouth(g_VoiceChannels[3].m_iEntity);
  }
  g_VoiceChannels[3].m_iEntity = -1;
  VoiceSE_EndChannel(4);
  if (-1 < g_VoiceChannels[4].m_iEntity) {
    ClientDLL_VoiceStatus(g_VoiceChannels[4].m_iEntity,false);
    VoiceSE_CloseMouth(g_VoiceChannels[4].m_iEntity);
  }
  g_VoiceChannels[4].m_iEntity = -1;
  Voice_RecordStop();
  if (g_pEncodeCodec != (IVoiceCodec *)0x0) {
    (*(g_pEncodeCodec->super_IBaseInterface)._vptr_IBaseInterface[6])(g_pEncodeCodec);
  }
  if ((g_bUsingSteamVoice == false) || (iVar5 = SteamUser(), iVar5 == 0)) {
    if (g_pVoiceRecord == (IVoiceRecord *)0x0) {
      g_bVoiceRecording = 0;
      goto LAB_0020308d;
    }
    uVar2 = (*g_pVoiceRecord->_vptr_IVoiceRecord[3])(g_pVoiceRecord);
    g_bVoiceRecording = uVar2 & 0xff;
    if (g_bVoiceRecording == 0) goto LAB_0020308d;
  }
  else {
    piVar3 = (int *)SteamUser();
    (**(code **)(*piVar3 + 0x1c))(piVar3);
    g_bVoiceRecording = 1;
  }
  ClientDLL_VoiceStatus(-1,true);
LAB_0020308d:
                    /* Unresolved local var: int iFree@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
  if ((g_bInTweakMode == false) && (g_VoiceChannels[0].m_iEntity != -500)) {
    if (g_VoiceChannels[0].m_iEntity == -1) {
      iVar5 = 0;
      pCVar4 = g_VoiceChannels;
    }
    else {
      if (g_VoiceChannels[1].m_iEntity == -500) {
        g_bInTweakMode = true;
        return 1;
      }
      if (g_VoiceChannels[1].m_iEntity == -1) {
        iVar5 = 1;
        pCVar4 = (CVoiceChannel *)0x852c3c;
      }
      else {
        if (g_VoiceChannels[2].m_iEntity == -500) {
          g_bInTweakMode = true;
          return 1;
        }
        if (g_VoiceChannels[2].m_iEntity == -1) {
          iVar5 = 2;
          pCVar4 = (CVoiceChannel *)0x8582b8;
        }
        else {
          if (g_VoiceChannels[3].m_iEntity == -500) {
            g_bInTweakMode = true;
            return 1;
          }
          if (g_VoiceChannels[3].m_iEntity == -1) {
            iVar5 = 3;
            pCVar4 = (CVoiceChannel *)0x85d934;
          }
          else {
            if (g_VoiceChannels[4].m_iEntity == -500) {
              g_bInTweakMode = true;
              return 1;
            }
            if (g_VoiceChannels[4].m_iEntity != -1) {
              g_bInTweakMode = true;
              return 1;
            }
            iVar5 = 4;
            pCVar4 = (CVoiceChannel *)0x862fb0;
          }
        }
      }
    }
    pIVar1 = pCVar4->m_pVoiceCodec;
    if (pIVar1 != (IVoiceCodec *)0x0) {
      (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[6])(pIVar1);
    }
    g_VoiceChannels[iVar5].m_iEntity = -500;
    g_VoiceChannels[iVar5].m_bStarved = false;
    CCircularBuffer::Flush(&g_VoiceChannels[iVar5].m_Buffer.super_CCircularBuffer);
    g_VoiceChannels[iVar5].m_LastSample = 0;
    *(undefined4 *)&g_VoiceChannels[iVar5].m_LastFraction = 0xd916872b;
    *(undefined4 *)((int)&g_VoiceChannels[iVar5].m_LastFraction + 4) = 0x3feff7ce;
    scale = voice_scale.value;
    g_VoiceChannels[iVar5].m_TimePad = 0.2;
    CAutoGain::Reset(&g_VoiceChannels[iVar5].m_AutoGain,0x80,voice_maxgain.value,voice_avggain.value
                     ,scale);
    VoiceSE_StartOverdrive();
  }
  g_bInTweakMode = true;
  return 1;
}


