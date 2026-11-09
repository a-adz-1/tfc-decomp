// Voice_AddIncomingData  @ 002047c0
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

int Voice_AddIncomingData(int nChannel,char *pchData,int nCount,int iSequenceNumber)

{
  short sVar1;
  IVoiceCodec *pIVar2;
  undefined4 uVar3;
  uint nSamples;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  short *pSamples;
  short *psVar9;
  bool bVar10;
  byte bVar11;
  double dVar12;
  double dVar13;
  double local_2044;
  undefined1 local_202c [8192];
  uint local_2c [7];
  
  bVar11 = 0;
                    /* Unresolved local var: CVoiceChannel * pChannel@[DW_OP_reg7(EDI)]
                       Unresolved local var: CVoiceTimer timer@[???]
                       Unresolved local var: char[8192] decompressed@[???]
                       Unresolved local var: int nDecompressed@[???] */
  if (g_bInTweakMode) {
    bVar10 = nChannel != -100;
    g_VoiceVolume = 0;
    nChannel = 0;
    if (bVar10) {
      g_VoiceVolume = 0;
      return 0;
    }
  }
  if ((nCount == 0) || (4 < (uint)nChannel)) {
    return 0;
  }
  bVar10 = voice_profile.value != 0.0;
  g_VoiceChannels[nChannel].m_bStarved = false;
  if (bVar10) {
    local_2044 = Sys_FloatTime();
  }
  if (g_bUsingSteamVoice == false) {
    pIVar2 = g_VoiceChannels[nChannel].m_pVoiceCodec;
    if (pIVar2 == (IVoiceCodec *)0x0) {
      nSamples = 0;
    }
    else {
      nSamples = (*(pIVar2->super_IBaseInterface)._vptr_IBaseInterface[5])
                           (pIVar2,pchData,nCount,local_202c,0x2000);
    }
  }
  else {
                    /* Unresolved local var: uint32 nBytesWritten@[???]
                       Unresolved local var: EVoiceResult result@[???] */
    local_2c[0] = 0;
    piVar4 = (int *)SteamUser();
    iVar5 = (**(code **)(*piVar4 + 0x2c))(piVar4,pchData,nCount,local_202c,0x2000,local_2c,0x2b11);
    if (iVar5 != 0) {
      return 0;
    }
    if (local_2c[0] == 0) {
      return 0;
    }
    nSamples = local_2c[0] >> 1;
  }
  dVar12 = g_DecompressTime;
  pSamples = (short *)local_202c;
  if (g_bInTweakMode != false) {
                    /* Unresolved local var: short * data@[???]
                       Unresolved local var: int i@[???] */
    uVar7 = 0;
    if (0 < (int)nSamples) {
      do {
        uVar8 = (int)pSamples[uVar7] >> 0x1f;
        uVar8 = ((int)pSamples[uVar7] ^ uVar8) - uVar8;
        if (g_VoiceVolume < (int)uVar8) {
          g_VoiceVolume = uVar8;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 != nSamples);
    }
    g_VoiceVolume = g_VoiceVolume & 0xfe00;
  }
  if (voice_profile.value != 0.0) {
    dVar13 = Sys_FloatTime();
    g_DecompressTime = (dVar13 - local_2044) + dVar12;
  }
  if (voice_profile.value != 0.0) {
    local_2044 = Sys_FloatTime();
  }
  CAutoGain::ProcessSamples(&g_VoiceChannels[nChannel].m_AutoGain,pSamples,nSamples);
  dVar12 = g_GainTime;
  if (voice_profile.value != 0.0) {
    dVar13 = Sys_FloatTime();
    g_GainTime = (dVar13 - local_2044) + dVar12;
  }
  if (voice_profile.value != 0.0) {
    local_2044 = Sys_FloatTime();
  }
  dVar12 = UpsampleIntoBuffer(pSamples,nSamples,
                              &g_VoiceChannels[nChannel].m_Buffer.super_CCircularBuffer,
                              g_VoiceChannels[nChannel].m_LastFraction,
                              (double)((float)g_VoiceSampleFormat.nSamplesPerSec / 11025.0));
  g_VoiceChannels[nChannel].m_LastSample = (short)(char)local_202c[nSamples];
  g_VoiceChannels[nChannel].m_LastFraction = dVar12;
  dVar12 = g_UpsampleTime;
  if (voice_profile.value != 0.0) {
    dVar13 = Sys_FloatTime();
    g_UpsampleTime = (dVar13 - local_2044) + dVar12;
  }
  if (g_pDecompressedFileData != (char *)0x0) {
                    /* Unresolved local var: int nToWrite@[???] */
    uVar7 = nSamples * 2;
    if ((int)(0x100000U - g_nDecompressedDataBytes) < (int)(nSamples * 2)) {
      uVar7 = 0x100000U - g_nDecompressedDataBytes;
    }
    psVar9 = (short *)(g_pDecompressedFileData + g_nDecompressedDataBytes);
    uVar8 = uVar7;
    if (7 < uVar7) {
      uVar6 = uVar7;
      if (((uint)psVar9 & 1) != 0) {
        pSamples = (short *)(local_202c + 1);
        *(char *)psVar9 = local_202c[0];
        psVar9 = (short *)((int)psVar9 + 1);
        uVar6 = uVar7 - 1;
      }
      if (((uint)psVar9 & 2) != 0) {
        sVar1 = *pSamples;
        uVar6 = uVar6 - 2;
        pSamples = pSamples + 1;
        *psVar9 = sVar1;
        psVar9 = psVar9 + 1;
      }
      if (((uint)psVar9 & 4) != 0) {
        uVar3 = *(undefined4 *)pSamples;
        uVar6 = uVar6 - 4;
        pSamples = pSamples + 2;
        *(undefined4 *)psVar9 = uVar3;
        psVar9 = psVar9 + 2;
      }
      uVar8 = uVar6 & 3;
      for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)psVar9 = *(undefined4 *)pSamples;
        pSamples = pSamples + (uint)bVar11 * -4 + 2;
        psVar9 = psVar9 + (uint)bVar11 * -4 + 2;
      }
    }
    iVar5 = 0;
    if ((uVar8 & 4) != 0) {
      *(undefined4 *)psVar9 = *(undefined4 *)pSamples;
      iVar5 = 4;
    }
    if ((uVar8 & 2) != 0) {
      *(undefined2 *)((int)psVar9 + iVar5) = *(undefined2 *)((int)pSamples + iVar5);
      iVar5 = iVar5 + 2;
    }
    if ((uVar8 & 1) != 0) {
      *(char *)((int)psVar9 + iVar5) = *(char *)((int)pSamples + iVar5);
    }
    g_nDecompressedDataBytes = g_nDecompressedDataBytes + uVar7;
  }
  if (voice_showincoming.value != 0.0) {
    Con_Printf("Voice - %d incoming samples added to channel %d\n",nSamples,nChannel);
  }
  return nChannel;
}


// Voice_AssignChannel  @ 00203600
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

int Voice_AssignChannel(int nEntity)

{
  IVoiceCodec *pIVar1;
  float scale;
  CVoiceChannel *pCVar2;
  int iVar3;
  
                    /* Unresolved local var: int iFree@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
  iVar3 = -2;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
  if ((!g_bInTweakMode) && (iVar3 = 0, g_VoiceChannels[0].m_iEntity != nEntity)) {
    if (g_VoiceChannels[0].m_iEntity == -1) {
      pCVar2 = g_VoiceChannels;
    }
    else {
      iVar3 = 1;
      if (g_VoiceChannels[1].m_iEntity == nEntity) {
        return 1;
      }
      if (g_VoiceChannels[1].m_iEntity == -1) {
        pCVar2 = (CVoiceChannel *)0x852c3c;
      }
      else {
        iVar3 = 2;
        if (g_VoiceChannels[2].m_iEntity == nEntity) {
          return 2;
        }
        if (g_VoiceChannels[2].m_iEntity == -1) {
          pCVar2 = (CVoiceChannel *)0x8582b8;
        }
        else {
          iVar3 = 3;
          if (g_VoiceChannels[3].m_iEntity == nEntity) {
            return 3;
          }
          if (g_VoiceChannels[3].m_iEntity == -1) {
            pCVar2 = (CVoiceChannel *)0x85d934;
          }
          else {
            if (g_VoiceChannels[4].m_iEntity == nEntity) {
              return 4;
            }
            if (g_VoiceChannels[4].m_iEntity != -1) {
              return -1;
            }
            iVar3 = 4;
            pCVar2 = (CVoiceChannel *)0x862fb0;
          }
        }
      }
    }
    pIVar1 = pCVar2->m_pVoiceCodec;
    if (pIVar1 != (IVoiceCodec *)0x0) {
      (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[6])(pIVar1);
    }
    g_VoiceChannels[iVar3].m_iEntity = nEntity;
    g_VoiceChannels[iVar3].m_bStarved = false;
    CCircularBuffer::Flush(&g_VoiceChannels[iVar3].m_Buffer.super_CCircularBuffer);
    g_VoiceChannels[iVar3].m_LastSample = 0;
    scale = voice_scale.value;
    *(undefined4 *)&g_VoiceChannels[iVar3].m_LastFraction = 0xd916872b;
    *(undefined4 *)((int)&g_VoiceChannels[iVar3].m_LastFraction + 4) = 0x3feff7ce;
    g_VoiceChannels[iVar3].m_TimePad = 0.2;
    CAutoGain::Reset(&g_VoiceChannels[iVar3].m_AutoGain,0x80,voice_maxgain.value,voice_avggain.value
                     ,scale);
    VoiceSE_StartOverdrive();
  }
  return iVar3;
}


// Voice_Deinit  @ 00202950
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

void Voice_Deinit(void)

{
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
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
  if (g_VoiceChannels[0].m_pVoiceCodec != (IVoiceCodec *)0x0) {
    (*((g_VoiceChannels[0].m_pVoiceCodec)->super_IBaseInterface)._vptr_IBaseInterface[3])
              (g_VoiceChannels[0].m_pVoiceCodec);
    g_VoiceChannels[0].m_pVoiceCodec = (IVoiceCodec *)0x0;
  }
  if (g_VoiceChannels[1].m_pVoiceCodec != (IVoiceCodec *)0x0) {
    (*((g_VoiceChannels[1].m_pVoiceCodec)->super_IBaseInterface)._vptr_IBaseInterface[3])
              (g_VoiceChannels[1].m_pVoiceCodec);
    g_VoiceChannels[1].m_pVoiceCodec = (IVoiceCodec *)0x0;
  }
  if (g_VoiceChannels[2].m_pVoiceCodec != (IVoiceCodec *)0x0) {
    (*((g_VoiceChannels[2].m_pVoiceCodec)->super_IBaseInterface)._vptr_IBaseInterface[3])
              (g_VoiceChannels[2].m_pVoiceCodec);
    g_VoiceChannels[2].m_pVoiceCodec = (IVoiceCodec *)0x0;
  }
  if (g_VoiceChannels[3].m_pVoiceCodec != (IVoiceCodec *)0x0) {
    (*((g_VoiceChannels[3].m_pVoiceCodec)->super_IBaseInterface)._vptr_IBaseInterface[3])
              (g_VoiceChannels[3].m_pVoiceCodec);
    g_VoiceChannels[3].m_pVoiceCodec = (IVoiceCodec *)0x0;
  }
  if (g_VoiceChannels[4].m_pVoiceCodec != (IVoiceCodec *)0x0) {
    (*((g_VoiceChannels[4].m_pVoiceCodec)->super_IBaseInterface)._vptr_IBaseInterface[3])
              (g_VoiceChannels[4].m_pVoiceCodec);
    g_VoiceChannels[4].m_pVoiceCodec = (IVoiceCodec *)0x0;
  }
  if (g_pEncodeCodec != (IVoiceCodec *)0x0) {
    (*(g_pEncodeCodec->super_IBaseInterface)._vptr_IBaseInterface[3])(g_pEncodeCodec);
    g_pEncodeCodec = (IVoiceCodec *)0x0;
  }
  if (g_hVoiceCodecDLL != (CSysModule *)0x0) {
    Sys_UnloadModule(g_hVoiceCodecDLL);
    g_hVoiceCodecDLL = (CSysModule *)0x0;
  }
  if (g_pVoiceRecord != (IVoiceRecord *)0x0) {
    (*g_pVoiceRecord->_vptr_IVoiceRecord[2])(g_pVoiceRecord);
    g_pVoiceRecord = (IVoiceRecord *)0x0;
  }
  VoiceSE_Term();
  if (g_pMixerControls != (IMixerControls *)0x0) {
    (*g_pMixerControls->_vptr_IMixerControls[2])(g_pMixerControls);
    g_pMixerControls = (IMixerControls *)0x0;
  }
  g_bVoiceAtLeastPartiallyInitted = false;
  return;
}


// Voice_Deinit  @ 00202b70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Voice_Deinit(void)

{
  if (!g_bVoiceAtLeastPartiallyInitted) {
    return;
  }
  Voice_Deinit();
  return;
}


// Voice_EndAllChannels  @ 002024f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

void Voice_EndAllChannels(void)

{
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
  return;
}


// Voice_EndChannel  @ 00202440
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

void Voice_EndChannel(int iChannel,bool bTellVoiceSE)

{
                    /* Unresolved local var: CVoiceChannel * pChannel@[???] */
  if (bTellVoiceSE) {
    VoiceSE_EndChannel(iChannel);
  }
  if (-1 < g_VoiceChannels[iChannel].m_iEntity) {
    ClientDLL_VoiceStatus(g_VoiceChannels[iChannel].m_iEntity,false);
    VoiceSE_CloseMouth(g_VoiceChannels[iChannel].m_iEntity);
  }
  g_VoiceChannels[iChannel].m_iEntity = -1;
  return;
}


// Voice_FlushChannel  @ 00204c40
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

void Voice_FlushChannel(int nChannel)

{
  if (4 < (uint)nChannel) {
    return;
  }
  CCircularBuffer::Flush(&g_VoiceChannels[nChannel].m_Buffer.super_CCircularBuffer);
  return;
}


// Voice_GetChannel  @ 00203790
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

int Voice_GetChannel(int nEntity)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = 0;
  if ((((g_VoiceChannels[0].m_iEntity != nEntity) &&
       (iVar1 = 1, g_VoiceChannels[1].m_iEntity != nEntity)) &&
      (iVar1 = 2, g_VoiceChannels[2].m_iEntity != nEntity)) &&
     (iVar1 = 3, g_VoiceChannels[3].m_iEntity != nEntity)) {
    iVar1 = (uint)(g_VoiceChannels[4].m_iEntity == nEntity) * 5 + -1;
  }
  return iVar1;
}


// Voice_GetClientListening  @ 00147230
qboolean Voice_GetClientListening(int iReceiver,int iSender)

{
  qboolean qVar1;
  int iVar2;
  int iVar3;
  
  qVar1 = false;
  iVar2 = iReceiver + -1;
  if (-1 < iVar2) {
    iVar3 = iSender + -1;
    if ((iVar3 < 0) || (svs.maxclients <= iVar2)) {
      return false;
    }
    if (iVar3 < svs.maxclients) {
      qVar1 = (uint)(svs.clients[iVar3].m_VoiceStreams[iVar2 >> 5] != 0) & 1 << ((byte)iVar2 & 0x1f)
      ;
    }
  }
  return qVar1;
}


// Voice_GetCompressedData  @ 00203260
int Voice_GetCompressedData(char *pchDest,int nCount,qboolean bFinal)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  byte bVar12;
  double dVar13;
  double dVar14;
  double local_404c;
  char local_403c;
  char acStack_403b [16383];
  int local_3c [4];
  int local_2c [2];
  undefined4 local_24;
  undefined4 local_20 [4];
  
  bVar12 = 0;
  if (g_bUsingSteamVoice) {
                    /* Unresolved local var: uint32 cbCompressedWritten@[???]
                       Unresolved local var: uint32 cbUncompressedWritten@[???]
                       Unresolved local var: uint32 cbCompressed@[???]
                       Unresolved local var: uint32 cbUncompressed@[???]
                       Unresolved local var: EVoiceResult result@[???] */
    local_3c[0] = 0;
    local_2c[0] = 0;
    local_24 = 0;
    local_20[0] = 0;
    piVar5 = (int *)SteamUser();
    iVar3 = (**(code **)(*piVar5 + 0x24))
                      (piVar5,&local_24,local_20,
                       ~-(uint)(g_pUncompressedFileData == (char *)0x0) & 0x2b11);
    if (iVar3 == 0) {
      piVar5 = (int *)SteamUser();
      (**(code **)(*piVar5 + 0x28))
                (piVar5,1,pchDest,nCount,local_3c,g_pUncompressedFileData != (char *)0x0,
                 g_pUncompressedFileData,0x100000 - g_nUncompressedDataBytes,local_2c,0x2b11);
      if (g_pUncompressedFileData != (char *)0x0) {
        g_nUncompressedDataBytes = g_nUncompressedDataBytes + local_2c[0];
      }
    }
    return local_3c[0];
  }
  iVar3 = 0;
  if ((g_pVoiceRecord != (IVoiceRecord *)0x0) && (g_pEncodeCodec != (IVoiceCodec *)0x0)) {
                    /* Unresolved local var: short[8192] tempData@[???]
                       Unresolved local var: int gotten@[???]
                       Unresolved local var: CVoiceTimer timer@[???]
                       Unresolved local var: int nCompressedBytes@[???] */
    iVar3 = 0x2000;
    if (nCount < 0x4000) {
      iVar3 = nCount / 2;
    }
    pcVar9 = &local_403c;
    uVar4 = (*g_pVoiceRecord->_vptr_IVoiceRecord[6])(g_pVoiceRecord,pcVar9,iVar3);
    if (g_pMicInputFileData != (char *)0x0) {
                    /* Unresolved local var: double curtime@[???]
                       Unresolved local var: int nShouldGet@[???] */
      dVar13 = Sys_FloatTime();
      uVar4 = (g_nMicInputFileBytes - g_CurMicInputFileByte) / 2;
      uVar6 = (uint)((double)g_VoiceSampleFormat.nSamplesPerSec * (dVar13 - g_MicStartTime));
      if ((int)uVar6 <= (int)uVar4) {
        uVar4 = uVar6;
      }
      if (0x2000 < uVar4) {
        uVar4 = 0x2000;
      }
      pcVar10 = g_pMicInputFileData + g_CurMicInputFileByte;
      uVar6 = uVar4 * 2;
      pcVar11 = pcVar9;
      if (3 < uVar6) {
        for (uVar7 = (uVar4 & 0x7fffffff) >> 1; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + (uint)bVar12 * -8 + 4;
          pcVar11 = pcVar11 + ((uint)bVar12 * -2 + 1) * 4;
        }
      }
      if ((uVar6 & 2) != 0) {
        *(undefined2 *)pcVar11 = *(undefined2 *)pcVar10;
      }
      g_CurMicInputFileByte = uVar6 + g_CurMicInputFileByte;
      g_MicStartTime = dVar13;
    }
    if (voice_profile.value != 0.0) {
      local_404c = Sys_FloatTime();
    }
    iVar3 = (*(g_pEncodeCodec->super_IBaseInterface)._vptr_IBaseInterface[4])
                      (g_pEncodeCodec,pcVar9,uVar4,pchDest,nCount,(uint)(bFinal != 0));
    dVar13 = g_CompressTime;
    if (voice_profile.value != 0.0) {
      dVar14 = Sys_FloatTime();
      g_CompressTime = (dVar14 - local_404c) + dVar13;
    }
    if (g_pUncompressedFileData != (char *)0x0) {
                    /* Unresolved local var: int nToWrite@[???] */
      uVar6 = uVar4 * 2;
      if ((int)(0x100000U - g_nUncompressedDataBytes) < (int)(uVar4 * 2)) {
        uVar6 = 0x100000U - g_nUncompressedDataBytes;
      }
      pcVar10 = g_pUncompressedFileData + g_nUncompressedDataBytes;
      uVar4 = uVar6;
      if (7 < uVar6) {
        uVar7 = uVar6;
        if (((uint)pcVar10 & 1) != 0) {
          pcVar9 = acStack_403b;
          *pcVar10 = local_403c;
          pcVar10 = pcVar10 + 1;
          uVar7 = uVar6 - 1;
        }
        if (((uint)pcVar10 & 2) != 0) {
          uVar1 = *(undefined2 *)pcVar9;
          uVar7 = uVar7 - 2;
          pcVar9 = pcVar9 + 2;
          *(undefined2 *)pcVar10 = uVar1;
          pcVar10 = pcVar10 + 2;
        }
        if (((uint)pcVar10 & 4) != 0) {
          uVar2 = *(undefined4 *)pcVar9;
          uVar7 = uVar7 - 4;
          pcVar9 = pcVar9 + 4;
          *(undefined4 *)pcVar10 = uVar2;
          pcVar10 = pcVar10 + 4;
        }
        uVar4 = uVar7 & 3;
        for (uVar7 = uVar7 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
          pcVar9 = pcVar9 + ((uint)bVar12 * -2 + 1) * 4;
          pcVar10 = pcVar10 + (uint)bVar12 * -8 + 4;
        }
      }
      iVar8 = 0;
      if ((uVar4 & 4) != 0) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
        iVar8 = 4;
      }
      if ((uVar4 & 2) != 0) {
        *(undefined2 *)(pcVar10 + iVar8) = *(undefined2 *)(pcVar9 + iVar8);
        iVar8 = iVar8 + 2;
      }
      if ((uVar4 & 1) != 0) {
        pcVar10[iVar8] = pcVar9[iVar8];
      }
      g_nUncompressedDataBytes = g_nUncompressedDataBytes + uVar6;
    }
  }
  return iVar3;
}


// Voice_GetLoopback  @ 00202620
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Voice_GetLoopback(void)

{
  uint uVar1;
  
  uVar1 = 1;
  if (voice_loopback.value == 0.0) {
    uVar1 = (uint)NAN(voice_loopback.value);
  }
  return uVar1;
}


// Voice_GetOutputData  @ 00202140
/* WARNING: Removing unreachable block (ram,0x0020235d) */
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

int Voice_GetOutputData(int iChannel,char *copyBufBytes,int copyBufSize,int samplePosition,
                       int sampleCount)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  CSizedCircularBuffer<22050> *this;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  byte bVar10;
  int local_2c;
  
  bVar10 = 0;
                    /* Unresolved local var: CVoiceChannel * pChannel@[???]
                       Unresolved local var: short * pCopyBuf@[???]
                       Unresolved local var: int maxOutSamples@[???]
                       Unresolved local var: CCircularBuffer * pBuffer@[???]
                       Unresolved local var: int nBytesToRead@[???]
                       Unresolved local var: int nSamplesGotten@[???]
                       Unresolved local var: int readSamplesAvail@[???] */
  this = &g_VoiceChannels[iChannel].m_Buffer;
  iVar8 = copyBufSize / 2;
  iVar2 = CCircularBuffer::GetReadAvailable(&this->super_CCircularBuffer);
  iVar3 = sampleCount * 2;
  if (iVar8 < sampleCount * 2) {
    iVar3 = iVar8;
  }
  if (iVar3 <= iVar2) {
    iVar2 = iVar3;
  }
  iVar2 = CCircularBuffer::Read(&this->super_CCircularBuffer,copyBufBytes,iVar2);
  iVar2 = iVar2 / 2;
  iVar3 = CCircularBuffer::GetReadAvailable(&this->super_CCircularBuffer);
  fVar1 = g_VoiceFadeMul;
  if (iVar3 / 2 < g_nVoiceFadeSamples) {
                    /* Unresolved local var: int bufferFadeOffset@[???]
                       Unresolved local var: int globalFadeOffset@[???] */
    iVar3 = iVar3 / 2 + iVar2;
    iVar4 = iVar3 - g_nVoiceFadeSamples;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    iVar3 = g_nVoiceFadeSamples - iVar3;
    if (iVar3 < 0) {
      iVar3 = 0;
    }
                    /* Unresolved local var: int i@[???] */
    if (0 < iVar2 - iVar4) {
      iVar5 = 0;
                    /* Unresolved local var: float percent@[???] */
      do {
        *(short *)(copyBufBytes + iVar5 * 2 + iVar4 * 2) =
             (short)(int)((1.0 - (float)(iVar5 + iVar3) * fVar1) *
                         (float)*(short *)(copyBufBytes + iVar5 * 2 + iVar4 * 2));
        iVar5 = iVar5 + 1;
      } while (iVar5 != iVar2 - iVar4);
    }
  }
  local_2c = iVar2;
  if (iVar2 < sampleCount) {
                    /* Unresolved local var: int wantedSampleCount@[???] */
    local_2c = iVar8;
    if (sampleCount <= iVar8) {
      local_2c = sampleCount;
    }
    uVar6 = (local_2c - iVar2) * 2;
    pcVar9 = copyBufBytes + iVar2 * 2;
    if (uVar6 < 8) {
      uVar7 = uVar6;
      if ((uVar6 & 4) != 0) {
        pcVar9[0] = '\0';
        pcVar9[1] = '\0';
        pcVar9[2] = '\0';
        pcVar9[3] = '\0';
        pcVar9 = pcVar9 + 4;
      }
    }
    else {
      if (((uint)pcVar9 & 1) != 0) {
        *pcVar9 = '\0';
        uVar6 = uVar6 - 1;
        pcVar9 = pcVar9 + 1;
      }
      if (((uint)pcVar9 & 2) != 0) {
        pcVar9[0] = '\0';
        pcVar9[1] = '\0';
        uVar6 = uVar6 - 2;
        pcVar9 = pcVar9 + 2;
      }
      if (((uint)pcVar9 & 4) != 0) {
        pcVar9[0] = '\0';
        pcVar9[1] = '\0';
        pcVar9[2] = '\0';
        pcVar9[3] = '\0';
        uVar6 = uVar6 - 4;
        pcVar9 = pcVar9 + 4;
      }
      uVar7 = uVar6 & 3;
      for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        pcVar9[0] = '\0';
        pcVar9[1] = '\0';
        pcVar9[2] = '\0';
        pcVar9[3] = '\0';
        pcVar9 = pcVar9 + (uint)bVar10 * -8 + 4;
      }
    }
    if ((uVar7 & 2) != 0) {
      pcVar9[0] = '\0';
      pcVar9[1] = '\0';
      pcVar9 = pcVar9 + 2;
    }
    if ((uVar7 & 1) != 0) {
      *pcVar9 = '\0';
    }
  }
  iVar2 = CCircularBuffer::GetReadAvailable(&this->super_CCircularBuffer);
  if (iVar2 == 0) {
    g_VoiceChannels[iChannel].m_bStarved = true;
  }
  if (2.0 <= voice_showchannels.value) {
    Con_Printf("Voice - mixed %d samples from channel %d\n",local_2c,iChannel);
  }
  VoiceSE_MoveMouth(g_VoiceChannels[iChannel].m_iEntity,(short *)copyBufBytes,local_2c);
  return local_2c;
}


// Voice_Idle  @ 002040b0
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

void Voice_Idle(float frametime)

{
  bool bVar1;
  float fVar2;
  int iVar3;
  
                    /* Unresolved local var: int nActive@[???] */
  if (voice_enable.value == 0.0) {
    if (!g_bVoiceAtLeastPartiallyInitted) {
      return;
    }
    Voice_Deinit();
    return;
  }
  if ((g_bLocalPlayerTalkingAck != 0) &&
     (g_LocalPlayerTalkingTimeout = frametime + g_LocalPlayerTalkingTimeout,
     0.2 < g_LocalPlayerTalkingTimeout)) {
    g_bLocalPlayerTalkingAck = 0;
    ClientDLL_VoiceStatus(-2,false);
  }
  g_nVoiceFadeSamples = (int)(voice_fadeouttime.value * 11025.0);
  if (g_nVoiceFadeSamples < 2) {
    g_nVoiceFadeSamples = 2;
  }
  g_VoiceFadeMul = 1.0 / (float)(g_nVoiceFadeSamples + -1);
  if (g_pVoiceRecord != (IVoiceRecord *)0x0) {
    (*g_pVoiceRecord->_vptr_IVoiceRecord[5])(g_pVoiceRecord);
  }
  Voice_UpdateVoiceTweakMode();
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
  iVar3 = 0;
  if (g_VoiceChannels[0].m_iEntity != -1) {
    if ((g_VoiceChannels[0].m_bStarved == false) || (g_bInTweakMode != false)) {
                    /* Unresolved local var: float oldpad@[???] */
      fVar2 = g_VoiceChannels[0].m_TimePad - frametime;
      bVar1 = 0.0 < g_VoiceChannels[0].m_TimePad;
      g_VoiceChannels[0].m_TimePad = fVar2;
      if ((bVar1) && (fVar2 <= 0.0)) {
        VoiceSE_StartChannel(0);
        ClientDLL_VoiceStatus(g_VoiceChannels[0].m_iEntity,true);
        VoiceSE_InitMouth(g_VoiceChannels[0].m_iEntity);
      }
      iVar3 = 1;
    }
    else {
      VoiceSE_EndChannel(0);
      if (-1 < g_VoiceChannels[0].m_iEntity) {
        ClientDLL_VoiceStatus(g_VoiceChannels[0].m_iEntity,false);
        VoiceSE_CloseMouth(g_VoiceChannels[0].m_iEntity);
      }
      iVar3 = 0;
      g_VoiceChannels[0].m_iEntity = -1;
    }
  }
  if (g_VoiceChannels[1].m_iEntity != -1) {
    if ((g_VoiceChannels[1].m_bStarved == false) || (g_bInTweakMode != false)) {
      fVar2 = g_VoiceChannels[1].m_TimePad - frametime;
      if ((g_VoiceChannels[1].m_TimePad <= 0.0) || (0.0 < fVar2)) {
        iVar3 = iVar3 + 1;
        g_VoiceChannels[1].m_TimePad = fVar2;
      }
      else {
        iVar3 = iVar3 + 1;
        g_VoiceChannels[1].m_TimePad = fVar2;
        VoiceSE_StartChannel(1);
        ClientDLL_VoiceStatus(g_VoiceChannels[1].m_iEntity,true);
        VoiceSE_InitMouth(g_VoiceChannels[1].m_iEntity);
      }
    }
    else {
      VoiceSE_EndChannel(1);
      if (-1 < g_VoiceChannels[1].m_iEntity) {
        ClientDLL_VoiceStatus(g_VoiceChannels[1].m_iEntity,false);
        VoiceSE_CloseMouth(g_VoiceChannels[1].m_iEntity);
      }
      g_VoiceChannels[1].m_iEntity = -1;
    }
  }
  if (g_VoiceChannels[2].m_iEntity != -1) {
    if ((g_VoiceChannels[2].m_bStarved == false) || (g_bInTweakMode != false)) {
      fVar2 = g_VoiceChannels[2].m_TimePad - frametime;
      if ((g_VoiceChannels[2].m_TimePad <= 0.0) || (0.0 < fVar2)) {
        iVar3 = iVar3 + 1;
        g_VoiceChannels[2].m_TimePad = fVar2;
      }
      else {
        iVar3 = iVar3 + 1;
        g_VoiceChannels[2].m_TimePad = fVar2;
        VoiceSE_StartChannel(2);
        ClientDLL_VoiceStatus(g_VoiceChannels[2].m_iEntity,true);
        VoiceSE_InitMouth(g_VoiceChannels[2].m_iEntity);
      }
    }
    else {
      VoiceSE_EndChannel(2);
      if (-1 < g_VoiceChannels[2].m_iEntity) {
        ClientDLL_VoiceStatus(g_VoiceChannels[2].m_iEntity,false);
        VoiceSE_CloseMouth(g_VoiceChannels[2].m_iEntity);
      }
      g_VoiceChannels[2].m_iEntity = -1;
    }
  }
  if (g_VoiceChannels[3].m_iEntity != -1) {
    if ((g_VoiceChannels[3].m_bStarved == false) || (g_bInTweakMode != false)) {
      fVar2 = g_VoiceChannels[3].m_TimePad - frametime;
      if ((g_VoiceChannels[3].m_TimePad <= 0.0) || (0.0 < fVar2)) {
        iVar3 = iVar3 + 1;
        g_VoiceChannels[3].m_TimePad = fVar2;
      }
      else {
        iVar3 = iVar3 + 1;
        g_VoiceChannels[3].m_TimePad = fVar2;
        VoiceSE_StartChannel(3);
        ClientDLL_VoiceStatus(g_VoiceChannels[3].m_iEntity,true);
        VoiceSE_InitMouth(g_VoiceChannels[3].m_iEntity);
      }
    }
    else {
      VoiceSE_EndChannel(3);
      if (-1 < g_VoiceChannels[3].m_iEntity) {
        ClientDLL_VoiceStatus(g_VoiceChannels[3].m_iEntity,false);
        VoiceSE_CloseMouth(g_VoiceChannels[3].m_iEntity);
      }
      g_VoiceChannels[3].m_iEntity = -1;
    }
  }
  if (g_VoiceChannels[4].m_iEntity != -1) {
    if ((g_VoiceChannels[4].m_bStarved == false) || (g_bInTweakMode != false)) {
      fVar2 = g_VoiceChannels[4].m_TimePad - frametime;
      bVar1 = 0.0 < g_VoiceChannels[4].m_TimePad;
      g_VoiceChannels[4].m_TimePad = fVar2;
      if ((bVar1) && (fVar2 <= 0.0)) {
        VoiceSE_StartChannel(4);
        ClientDLL_VoiceStatus(g_VoiceChannels[4].m_iEntity,true);
        VoiceSE_InitMouth(g_VoiceChannels[4].m_iEntity);
      }
      goto LAB_002042a4;
    }
                    /* Unresolved local var: CVoiceChannel * pChannel@[???] */
    VoiceSE_EndChannel(4);
    if (-1 < g_VoiceChannels[4].m_iEntity) {
      ClientDLL_VoiceStatus(g_VoiceChannels[4].m_iEntity,false);
      VoiceSE_CloseMouth(g_VoiceChannels[4].m_iEntity);
    }
    g_VoiceChannels[4].m_iEntity = -1;
  }
  if ((iVar3 == 0) && (g_bInTweakMode == false)) {
    VoiceSE_EndOverdrive();
  }
LAB_002042a4:
  VoiceSE_Idle(frametime);
  if (1.0 <= voice_showchannels.value) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
    if (g_VoiceChannels[0].m_iEntity != -1) {
      iVar3 = CCircularBuffer::GetReadAvailable(&g_VoiceChannels[0].m_Buffer.super_CCircularBuffer);
      Con_Printf("Voice - chan %d, ent %d, bufsize: %d\n",0,g_VoiceChannels[0].m_iEntity,iVar3);
    }
    if (g_VoiceChannels[1].m_iEntity != -1) {
      iVar3 = CCircularBuffer::GetReadAvailable(&g_VoiceChannels[1].m_Buffer.super_CCircularBuffer);
      Con_Printf("Voice - chan %d, ent %d, bufsize: %d\n",1,g_VoiceChannels[1].m_iEntity,iVar3);
    }
    if (g_VoiceChannels[2].m_iEntity != -1) {
      iVar3 = CCircularBuffer::GetReadAvailable(&g_VoiceChannels[2].m_Buffer.super_CCircularBuffer);
      Con_Printf("Voice - chan %d, ent %d, bufsize: %d\n",2,g_VoiceChannels[2].m_iEntity,iVar3);
    }
    if (g_VoiceChannels[3].m_iEntity != -1) {
      iVar3 = CCircularBuffer::GetReadAvailable(&g_VoiceChannels[3].m_Buffer.super_CCircularBuffer);
      Con_Printf("Voice - chan %d, ent %d, bufsize: %d\n",3,g_VoiceChannels[3].m_iEntity,iVar3);
    }
    if (g_VoiceChannels[4].m_iEntity != -1) {
      iVar3 = CCircularBuffer::GetReadAvailable(&g_VoiceChannels[4].m_Buffer.super_CCircularBuffer);
      Con_Printf("Voice - chan %d, ent %d, bufsize: %d\n",4,g_VoiceChannels[4].m_iEntity,iVar3);
    }
  }
  if (voice_profile.value == 0.0) {
    return;
  }
  Con_Printf("Voice - compress: %7.2fu, decompress: %7.2fu, gain: %7.2fu, upsample: %7.2fu, total: %7.2fu\n"
             ,(double)CONCAT44(g_CompressTime._4_4_,g_CompressTime._0_4_) * 1000000.0,
             (double)CONCAT44(g_DecompressTime._4_4_,g_DecompressTime._0_4_) * 1000000.0,
             (double)CONCAT44(g_GainTime._4_4_,g_GainTime._0_4_) * 1000000.0,
             (double)CONCAT44(g_UpsampleTime._4_4_,g_UpsampleTime._0_4_) * 1000000.0,
             ((double)CONCAT44(g_CompressTime._4_4_,g_CompressTime._0_4_) +
              (double)CONCAT44(g_DecompressTime._4_4_,g_DecompressTime._0_4_) +
              (double)CONCAT44(g_GainTime._4_4_,g_GainTime._0_4_) +
             (double)CONCAT44(g_UpsampleTime._4_4_,g_UpsampleTime._0_4_)) * 1000000.0);
  g_UpsampleTime._0_4_ = 0;
  g_DecompressTime._0_4_ = 0;
  g_DecompressTime._4_4_ = 0;
  g_CompressTime._0_4_ = 0;
  g_GainTime._4_4_ = 0;
  g_UpsampleTime._4_4_ = 0;
  g_GainTime._0_4_ = 0;
  g_CompressTime._4_4_ = 0;
  return;
}


// Voice_Init  @ 00202b90
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

qboolean Voice_Init(char *pCodecName,int quality)

{
  bool bVar1;
  int iVar2;
  CreateInterfaceFn p_Var3;
  undefined4 uVar4;
  qboolean qVar5;
  char local_10c [256];
  
  if (voice_enable.value == 0.0) {
    return 0;
  }
  if (g_bVoiceAtLeastPartiallyInitted) {
    Voice_Deinit();
  }
  g_bVoiceAtLeastPartiallyInitted = true;
  bVar1 = VoiceSE_Init();
  if (!bVar1) {
    return 0;
  }
  iVar2 = SteamUser();
  g_bUsingSteamVoice = iVar2 != 0;
  if ((g_bUsingSteamVoice) || (*pCodecName == '\0')) {
LAB_00202c28:
    g_pMixerControls = GetMixerControls();
    qVar5 = 1;
    if ((voice_forcemicrecord.value != 0.0) && (g_pMixerControls != (IMixerControls *)0x0)) {
      (*g_pMixerControls->_vptr_IMixerControls[5])(g_pMixerControls);
    }
  }
  else {
                    /* Unresolved local var: int rate@[???]
                       Unresolved local var: char[256] dllName@[???]
                       Unresolved local var: CreateInterfaceFn createCodecFn@[???] */
    g_pVoiceRecord = CreateVoiceRecord(g_VoiceSampleFormat.nSamplesPerSec);
    if (g_pVoiceRecord == (IVoiceRecord *)0x0) {
      Con_Printf(
                "Unable to initialize wave input. You won\'t be able to speak to other players through a microphone.\n"
                );
    }
    snprintf(local_10c,0x100,"%s.so",pCodecName);
    if (g_hVoiceCodecDLL == (CSysModule *)0x0) {
      FS_GetLocalCopy(local_10c);
      g_hVoiceCodecDLL = Sys_LoadModule(local_10c);
      if (g_hVoiceCodecDLL != (CSysModule *)0x0) goto LAB_00202cb9;
      Con_Printf("Unable to load voice codec DLL %s.  Voice disabled.\n",local_10c);
    }
    else {
LAB_00202cb9:
      p_Var3 = Sys_GetFactory(g_hVoiceCodecDLL);
      if (p_Var3 == (CreateInterfaceFn)0x0) {
        Con_Printf("Unable to get a factory for voice codec %s.  Voice disabled.\n",pCodecName);
      }
      else {
        g_pEncodeCodec = (IVoiceCodec *)(*p_Var3)(pCodecName,(int *)0x0);
        if ((IBaseInterface *)g_pEncodeCodec == (IBaseInterface *)0x0) {
          Con_Printf("Unable to create interface for voice codec %s.  Voice disabled.\n",pCodecName)
          ;
        }
        else {
          iVar2 = (*((IBaseInterface *)g_pEncodeCodec)->_vptr_IBaseInterface[2])
                            (g_pEncodeCodec,quality);
          if ((char)iVar2 == '\0') {
            Con_Printf("Unable to initialize voice codec %s.  Voice disabled.\n",pCodecName);
          }
          else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
            g_VoiceChannels[0].m_pVoiceCodec = (IVoiceCodec *)(*p_Var3)(pCodecName,(int *)0x0);
            if ((IBaseInterface *)g_VoiceChannels[0].m_pVoiceCodec == (IBaseInterface *)0x0) {
              uVar4 = 0;
            }
            else {
              iVar2 = (*((IBaseInterface *)g_VoiceChannels[0].m_pVoiceCodec)->_vptr_IBaseInterface
                        [2])(g_VoiceChannels[0].m_pVoiceCodec,quality);
              uVar4 = 0;
              if ((char)iVar2 != '\0') {
                g_VoiceChannels[1].m_pVoiceCodec = (IVoiceCodec *)(*p_Var3)(pCodecName,(int *)0x0);
                if ((IBaseInterface *)g_VoiceChannels[1].m_pVoiceCodec == (IBaseInterface *)0x0) {
                  uVar4 = 1;
                }
                else {
                  iVar2 = (*((IBaseInterface *)g_VoiceChannels[1].m_pVoiceCodec)->
                            _vptr_IBaseInterface[2])(g_VoiceChannels[1].m_pVoiceCodec,quality);
                  uVar4 = 1;
                  if ((char)iVar2 != '\0') {
                    g_VoiceChannels[2].m_pVoiceCodec =
                         (IVoiceCodec *)(*p_Var3)(pCodecName,(int *)0x0);
                    if ((IBaseInterface *)g_VoiceChannels[2].m_pVoiceCodec == (IBaseInterface *)0x0)
                    {
                      uVar4 = 2;
                    }
                    else {
                      iVar2 = (*((IBaseInterface *)g_VoiceChannels[2].m_pVoiceCodec)->
                                _vptr_IBaseInterface[2])(g_VoiceChannels[2].m_pVoiceCodec,quality);
                      uVar4 = 2;
                      if ((char)iVar2 != '\0') {
                        g_VoiceChannels[3].m_pVoiceCodec =
                             (IVoiceCodec *)(*p_Var3)(pCodecName,(int *)0x0);
                        if ((IBaseInterface *)g_VoiceChannels[3].m_pVoiceCodec ==
                            (IBaseInterface *)0x0) {
                          uVar4 = 3;
                        }
                        else {
                          iVar2 = (*((IBaseInterface *)g_VoiceChannels[3].m_pVoiceCodec)->
                                    _vptr_IBaseInterface[2])
                                            (g_VoiceChannels[3].m_pVoiceCodec,quality);
                          uVar4 = 3;
                          if ((char)iVar2 != '\0') {
                            g_VoiceChannels[4].m_pVoiceCodec =
                                 (IVoiceCodec *)(*p_Var3)(pCodecName,(int *)0x0);
                            if (((IBaseInterface *)g_VoiceChannels[4].m_pVoiceCodec !=
                                 (IBaseInterface *)0x0) &&
                               (iVar2 = (*((IBaseInterface *)g_VoiceChannels[4].m_pVoiceCodec)->
                                          _vptr_IBaseInterface[2])
                                                  (g_VoiceChannels[4].m_pVoiceCodec,quality),
                               (char)iVar2 != '\0')) goto LAB_00202c28;
                            uVar4 = 4;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            Con_Printf("Unable to get voice codec (%s) interface for channel %d.  Voice disabled.\n"
                       ,pCodecName,uVar4);
          }
        }
      }
    }
    qVar5 = 0;
    if (g_bVoiceAtLeastPartiallyInitted != false) {
      qVar5 = 0;
      Voice_Deinit();
    }
  }
  return qVar5;
}


// Voice_IsRecording  @ 00202680
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Voice_IsRecording(void)

{
  uint uVar1;
  
  uVar1 = 0;
  if (g_bVoiceRecording != 0) {
    uVar1 = (uint)!g_bInTweakMode;
  }
  return uVar1;
}


// Voice_LocalPlayerTalkingAck  @ 00202640
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Voice_LocalPlayerTalkingAck(void)

{
  if (g_bLocalPlayerTalkingAck == 0) {
    ClientDLL_VoiceStatus(-2,true);
  }
  g_bLocalPlayerTalkingAck = 1;
  g_LocalPlayerTalkingTimeout = 0.0;
  return;
}


// Voice_NotifyFreeChannel  @ 002024a0
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

void Voice_NotifyFreeChannel(int iChannel)

{
                    /* Unresolved local var: CVoiceChannel * pChannel@[???] */
  if (-1 < g_VoiceChannels[iChannel].m_iEntity) {
    ClientDLL_VoiceStatus(g_VoiceChannels[iChannel].m_iEntity,false);
    VoiceSE_CloseMouth(g_VoiceChannels[iChannel].m_iEntity);
  }
  g_VoiceChannels[iChannel].m_iEntity = -1;
  return;
}


// Voice_RecordStart  @ 00202800
qboolean Voice_RecordStart(char *pUncompressedFile,char *pDecompressedFile,char *pMicInputFile)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int local_18;
  int local_14;
  int local_10;
  
  Voice_RecordStop();
  if (g_pEncodeCodec != (IVoiceCodec *)0x0) {
    (*(g_pEncodeCodec->super_IBaseInterface)._vptr_IBaseInterface[6])(g_pEncodeCodec);
  }
  if (pMicInputFile != (char *)0x0) {
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
    ReadWaveFile(pMicInputFile,&g_pMicInputFileData,&g_nMicInputFileBytes,&local_18,&local_14,
                 &local_10);
    g_CurMicInputFileByte = 0;
    g_MicStartTime = Sys_FloatTime();
  }
  if (pUncompressedFile != (char *)0x0) {
    g_pUncompressedFileData = operator_new__(0x100000);
    g_nUncompressedDataBytes = 0;
    g_pUncompressedDataFilename = pUncompressedFile;
  }
  if (pDecompressedFile != (char *)0x0) {
    g_pDecompressedFileData = operator_new__(0x100000);
    g_nDecompressedDataBytes = 0;
    g_pDecompressedDataFilename = pDecompressedFile;
  }
  if (g_bUsingSteamVoice != false) {
    iVar2 = SteamUser();
    if (iVar2 != 0) {
      piVar3 = (int *)SteamUser();
      (**(code **)(*piVar3 + 0x1c))(piVar3);
      g_bVoiceRecording = 1;
      goto LAB_00202921;
    }
  }
  if (g_pVoiceRecord == (IVoiceRecord *)0x0) {
    g_bVoiceRecording = 0;
    return 0;
  }
  uVar1 = (*g_pVoiceRecord->_vptr_IVoiceRecord[3])(g_pVoiceRecord);
  g_bVoiceRecording = uVar1 & 0xff;
  if (g_bVoiceRecording == 0) {
    return 0;
  }
LAB_00202921:
  ClientDLL_VoiceStatus(-1,true);
  return g_bVoiceRecording;
}


// Voice_RecordStop  @ 002026a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Voice_RecordStop(void)

{
  int iVar1;
  int *piVar2;
  
  if (g_pMicInputFileData != (char *)0x0) {
    operator_delete__(g_pMicInputFileData);
    g_pMicInputFileData = (char *)0x0;
  }
  if (g_pUncompressedFileData != (char *)0x0) {
    WriteWaveFile(g_pUncompressedDataFilename,g_pUncompressedFileData,g_nUncompressedDataBytes,
                  (int)g_VoiceSampleFormat.wBitsPerSample,(int)g_VoiceSampleFormat.nChannels,
                  g_VoiceSampleFormat.nSamplesPerSec);
    if (g_pUncompressedFileData != (char *)0x0) {
      operator_delete__(g_pUncompressedFileData);
    }
    g_pUncompressedFileData = (char *)0x0;
  }
  if (g_pDecompressedFileData != (char *)0x0) {
    WriteWaveFile(g_pDecompressedDataFilename,g_pDecompressedFileData,g_nDecompressedDataBytes,
                  (int)g_VoiceSampleFormat.wBitsPerSample,(int)g_VoiceSampleFormat.nChannels,
                  g_VoiceSampleFormat.nSamplesPerSec);
    if (g_pDecompressedFileData != (char *)0x0) {
      operator_delete__(g_pDecompressedFileData);
    }
    g_pDecompressedFileData = (char *)0x0;
  }
  if (g_bUsingSteamVoice != false) {
    iVar1 = SteamUser();
    if (iVar1 != 0) {
      piVar2 = (int *)SteamUser();
      (**(code **)(*piVar2 + 0x20))(piVar2);
      goto LAB_0020278d;
    }
  }
  if (g_pVoiceRecord != (IVoiceRecord *)0x0) {
    (*g_pVoiceRecord->_vptr_IVoiceRecord[4])(g_pVoiceRecord);
  }
LAB_0020278d:
  if (g_bVoiceRecording != 0) {
    ClientDLL_VoiceStatus(-1,false);
  }
  g_bVoiceRecording = 0;
  return 1;
}


// Voice_RegisterCvars  @ 002023b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Voice_RegisterCvars(void)

{
  Cvar_RegisterVariable(&voice_loopback);
  Cvar_RegisterVariable(&voice_maxgain);
  Cvar_RegisterVariable(&voice_avggain);
  Cvar_RegisterVariable(&voice_scale);
  Cvar_RegisterVariable(&voice_fadeouttime);
  Cvar_RegisterVariable(&voice_profile);
  Cvar_RegisterVariable(&voice_showchannels);
  Cvar_RegisterVariable(&voice_showincoming);
  Cvar_RegisterVariable(&voice_enable);
  Cvar_RegisterVariable(&voice_dsound);
  Cvar_RegisterVariable(&voice_forcemicrecord);
  VoiceSE_RegisterCvars();
  return;
}


// Voice_SetClientListening  @ 001472b0
qboolean Voice_SetClientListening(int iReceiver,int iSender,qboolean bListen)

{
  qboolean qVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
                    /* Unresolved local var: uint32 * pDest@[???] */
  qVar1 = false;
  iVar2 = iReceiver + -1;
  if (-1 < iVar2) {
    iVar4 = iSender + -1;
    if ((iVar4 < 0) || (svs.maxclients <= iVar2)) {
      return false;
    }
    if (iVar4 < svs.maxclients) {
      uVar3 = 1 << ((byte)iVar2 & 0x1f);
      if (bListen != false) {
        svs.clients[iVar4].m_VoiceStreams[iVar2 >> 5] =
             svs.clients[iVar4].m_VoiceStreams[iVar2 >> 5] | uVar3;
        return true;
      }
      svs.clients[iVar4].m_VoiceStreams[iVar2 >> 5] =
           svs.clients[iVar4].m_VoiceStreams[iVar2 >> 5] & ~uVar3;
      qVar1 = true;
    }
  }
  return qVar1;
}


// Voice_UpdateVoiceTweakMode  @ 002038e0
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

void Voice_UpdateVoiceTweakMode(void)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  short *pSamples;
  undefined4 *puVar11;
  char *pcVar12;
  undefined4 *puVar13;
  short *psVar14;
  byte bVar15;
  double dVar16;
  double dVar17;
  undefined4 local_486c;
  double local_4864;
  double local_485c;
  undefined1 local_484c [16384];
  undefined1 local_84c [2048];
  int local_4c [4];
  int local_3c [4];
  uint local_2c [3];
  undefined4 local_20 [4];
  
  bVar15 = 0;
                    /* Unresolved local var: char[2048] uchVoiceData@[???]
                       Unresolved local var: bool bFinal@[???]
                       Unresolved local var: int nDataLength@[DW_OP_reg2(EDX)] */
  if (!g_bInTweakMode) {
    return;
  }
  if (g_bUsingSteamVoice) {
                    /* Unresolved local var: uint32 cbCompressedWritten@[???]
                       Unresolved local var: uint32 cbUncompressedWritten@[???]
                       Unresolved local var: uint32 cbCompressed@[???]
                       Unresolved local var: uint32 cbUncompressed@[???]
                       Unresolved local var: EVoiceResult result@[???] */
    local_4c[0] = 0;
    local_3c[0] = 0;
    local_2c[0] = 0;
    local_20[0] = 0;
    piVar6 = (int *)SteamUser();
    iVar9 = (**(code **)(*piVar6 + 0x24))
                      (piVar6,local_2c,local_20,
                       ~-(uint)(g_pUncompressedFileData == (char *)0x0) & 0x2b11);
    iVar5 = local_4c[0];
    if (iVar9 == 0) {
      piVar6 = (int *)SteamUser();
      (**(code **)(*piVar6 + 0x28))
                (piVar6,1,local_84c,0x800,local_4c,g_pUncompressedFileData != (char *)0x0,
                 g_pUncompressedFileData,0x100000 - g_nUncompressedDataBytes,local_3c,0x2b11);
      iVar5 = local_4c[0];
      if (g_pUncompressedFileData != (char *)0x0) {
        g_nUncompressedDataBytes = g_nUncompressedDataBytes + local_3c[0];
      }
    }
LAB_00203ac9:
                    /* Unresolved local var: CVoiceChannel * pChannel@[???]
                       Unresolved local var: CVoiceTimer timer@[???]
                       Unresolved local var: char[8192] decompressed@[???]
                       Unresolved local var: int nDecompressed@[???] */
    if (g_bInTweakMode == false) {
      uVar4 = 0xffffff9c;
      local_486c = 0xffffff9c;
      goto LAB_00203adf;
    }
  }
  else {
    if ((g_pVoiceRecord != (IVoiceRecord *)0x0) && (g_pEncodeCodec != (IVoiceCodec *)0x0)) {
                    /* Unresolved local var: short[8192] tempData@[???]
                       Unresolved local var: int gotten@[???]
                       Unresolved local var: CVoiceTimer timer@[???]
                       Unresolved local var: int nCompressedBytes@[???] */
      puVar11 = (undefined4 *)local_484c;
      uVar4 = (*g_pVoiceRecord->_vptr_IVoiceRecord[6])(g_pVoiceRecord,puVar11,0x400);
      if (g_pMicInputFileData != (char *)0x0) {
                    /* Unresolved local var: double curtime@[???]
                       Unresolved local var: int nShouldGet@[???] */
        dVar16 = Sys_FloatTime();
        uVar4 = (g_nMicInputFileBytes - g_CurMicInputFileByte) / 2;
        uVar7 = (uint)((double)g_VoiceSampleFormat.nSamplesPerSec * (dVar16 - g_MicStartTime));
        if ((int)uVar7 <= (int)uVar4) {
          uVar4 = uVar7;
        }
        if (0x2000 < uVar4) {
          uVar4 = 0x2000;
        }
        pcVar12 = g_pMicInputFileData + g_CurMicInputFileByte;
        uVar7 = uVar4 * 2;
        puVar13 = puVar11;
        if (3 < uVar7) {
          for (uVar8 = (uVar4 & 0x7fffffff) >> 1; uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar13 = *(undefined4 *)pcVar12;
            pcVar12 = pcVar12 + (uint)bVar15 * -8 + 4;
            puVar13 = puVar13 + (uint)bVar15 * -2 + 1;
          }
        }
        if ((uVar7 & 2) != 0) {
          *(undefined2 *)puVar13 = *(undefined2 *)pcVar12;
        }
        g_CurMicInputFileByte = uVar7 + g_CurMicInputFileByte;
        g_MicStartTime = dVar16;
      }
      if (voice_profile.value != 0.0) {
        local_4864 = Sys_FloatTime();
      }
      iVar5 = (*(g_pEncodeCodec->super_IBaseInterface)._vptr_IBaseInterface[4])
                        (g_pEncodeCodec,puVar11,uVar4,local_84c,0x800,0);
      dVar16 = g_CompressTime;
      if (voice_profile.value != 0.0) {
        dVar17 = Sys_FloatTime();
        g_CompressTime = (dVar17 - local_4864) + dVar16;
      }
      if (g_pUncompressedFileData != (char *)0x0) {
                    /* Unresolved local var: int nToWrite@[???] */
        uVar7 = uVar4 * 2;
        if ((int)(0x100000U - g_nUncompressedDataBytes) < (int)(uVar4 * 2)) {
          uVar7 = 0x100000U - g_nUncompressedDataBytes;
        }
        pcVar12 = g_pUncompressedFileData + g_nUncompressedDataBytes;
        uVar4 = uVar7;
        if (7 < uVar7) {
          uVar8 = uVar7;
          if (((uint)pcVar12 & 1) != 0) {
            puVar11 = (undefined4 *)(local_484c + 1);
            *pcVar12 = local_484c[0];
            pcVar12 = pcVar12 + 1;
            uVar8 = uVar7 - 1;
          }
          if (((uint)pcVar12 & 2) != 0) {
            uVar1 = *(undefined2 *)puVar11;
            uVar8 = uVar8 - 2;
            puVar11 = (undefined4 *)((int)puVar11 + 2);
            *(undefined2 *)pcVar12 = uVar1;
            pcVar12 = pcVar12 + 2;
          }
          if (((uint)pcVar12 & 4) != 0) {
            uVar3 = *puVar11;
            uVar8 = uVar8 - 4;
            puVar11 = puVar11 + 1;
            *(undefined4 *)pcVar12 = uVar3;
            pcVar12 = pcVar12 + 4;
          }
          uVar4 = uVar8 & 3;
          for (uVar8 = uVar8 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)pcVar12 = *puVar11;
            puVar11 = puVar11 + (uint)bVar15 * -2 + 1;
            pcVar12 = pcVar12 + (uint)bVar15 * -8 + 4;
          }
        }
        iVar9 = 0;
        if ((uVar4 & 4) != 0) {
          *(undefined4 *)pcVar12 = *puVar11;
          iVar9 = 4;
        }
        if ((uVar4 & 2) != 0) {
          *(undefined2 *)(pcVar12 + iVar9) = *(undefined2 *)((int)puVar11 + iVar9);
          iVar9 = iVar9 + 2;
        }
        if ((uVar4 & 1) != 0) {
          pcVar12[iVar9] = *(char *)((int)puVar11 + iVar9);
        }
        g_nUncompressedDataBytes = g_nUncompressedDataBytes + uVar7;
      }
      goto LAB_00203ac9;
    }
    iVar5 = 0;
  }
  g_VoiceVolume = 0;
  uVar4 = 0;
  local_486c = 0;
LAB_00203adf:
  if ((iVar5 != 0) && (uVar4 < 5)) {
    g_VoiceChannels[0].m_bStarved = false;
    if (voice_profile.value != 0.0) {
      local_485c = Sys_FloatTime();
    }
    if (g_bUsingSteamVoice == false) {
      if (g_VoiceChannels[0].m_pVoiceCodec == (IVoiceCodec *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = (*((g_VoiceChannels[0].m_pVoiceCodec)->super_IBaseInterface)._vptr_IBaseInterface[5]
                )(g_VoiceChannels[0].m_pVoiceCodec,local_84c,iVar5,local_484c,0x2000);
      }
    }
    else {
                    /* Unresolved local var: uint32 nBytesWritten@[???]
                       Unresolved local var: EVoiceResult result@[???] */
      local_2c[0] = 0;
      piVar6 = (int *)SteamUser();
      iVar5 = (**(code **)(*piVar6 + 0x2c))
                        (piVar6,local_84c,iVar5,local_484c,0x2000,local_2c,0x2b11);
      if (iVar5 != 0) {
        return;
      }
      if (local_2c[0] == 0) {
        return;
      }
      uVar4 = local_2c[0] >> 1;
    }
    dVar16 = g_DecompressTime;
    pSamples = (short *)local_484c;
    if (g_bInTweakMode != false) {
                    /* Unresolved local var: short * data@[???]
                       Unresolved local var: int i@[???] */
      uVar7 = 0;
      if (0 < (int)uVar4) {
        do {
          uVar8 = (int)pSamples[uVar7] >> 0x1f;
          uVar8 = ((int)pSamples[uVar7] ^ uVar8) - uVar8;
          if (g_VoiceVolume < (int)uVar8) {
            g_VoiceVolume = uVar8;
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 != uVar4);
      }
      g_VoiceVolume = g_VoiceVolume & 0xfe00;
    }
    if (voice_profile.value != 0.0) {
      dVar17 = Sys_FloatTime();
      g_DecompressTime = (dVar17 - local_485c) + dVar16;
    }
    if (voice_profile.value != 0.0) {
      local_485c = Sys_FloatTime();
    }
    CAutoGain::ProcessSamples(&g_VoiceChannels[0].m_AutoGain,pSamples,uVar4);
    dVar16 = g_GainTime;
    if (voice_profile.value != 0.0) {
      dVar17 = Sys_FloatTime();
      g_GainTime = (dVar17 - local_485c) + dVar16;
    }
    if (voice_profile.value != 0.0) {
      local_485c = Sys_FloatTime();
    }
    g_VoiceChannels[0].m_LastFraction =
         UpsampleIntoBuffer(pSamples,uVar4,&g_VoiceChannels[0].m_Buffer.super_CCircularBuffer,
                            g_VoiceChannels[0].m_LastFraction,
                            (double)((float)g_VoiceSampleFormat.nSamplesPerSec / 11025.0));
    dVar16 = g_UpsampleTime;
    g_VoiceChannels[0].m_LastSample = (short)*(char *)((int)local_484c + uVar4);
    if (voice_profile.value != 0.0) {
      dVar17 = Sys_FloatTime();
      g_UpsampleTime = (dVar17 - local_485c) + dVar16;
    }
    if (g_pDecompressedFileData != (char *)0x0) {
                    /* Unresolved local var: int nToWrite@[???] */
      uVar7 = uVar4 * 2;
      if ((int)(0x100000U - g_nDecompressedDataBytes) < (int)(uVar4 * 2)) {
        uVar7 = 0x100000U - g_nDecompressedDataBytes;
      }
      psVar14 = (short *)(g_pDecompressedFileData + g_nDecompressedDataBytes);
      uVar8 = uVar7;
      if (7 < uVar7) {
        uVar10 = uVar7;
        if (((uint)psVar14 & 1) != 0) {
          pSamples = (short *)(local_484c + 1);
          *(char *)psVar14 = local_484c[0];
          psVar14 = (short *)((int)psVar14 + 1);
          uVar10 = uVar7 - 1;
        }
        if (((uint)psVar14 & 2) != 0) {
          sVar2 = *pSamples;
          uVar10 = uVar10 - 2;
          pSamples = pSamples + 1;
          *psVar14 = sVar2;
          psVar14 = psVar14 + 1;
        }
        if (((uint)psVar14 & 4) != 0) {
          uVar3 = *(undefined4 *)pSamples;
          uVar10 = uVar10 - 4;
          pSamples = pSamples + 2;
          *(undefined4 *)psVar14 = uVar3;
          psVar14 = psVar14 + 2;
        }
        uVar8 = uVar10 & 3;
        for (uVar10 = uVar10 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *(undefined4 *)psVar14 = *(undefined4 *)pSamples;
          pSamples = pSamples + (uint)bVar15 * -4 + 2;
          psVar14 = psVar14 + (uint)bVar15 * -4 + 2;
        }
      }
      iVar5 = 0;
      if ((uVar8 & 4) != 0) {
        *(undefined4 *)psVar14 = *(undefined4 *)pSamples;
        iVar5 = 4;
      }
      if ((uVar8 & 2) != 0) {
        *(undefined2 *)((int)psVar14 + iVar5) = *(undefined2 *)((int)pSamples + iVar5);
        iVar5 = iVar5 + 2;
      }
      if ((uVar8 & 1) != 0) {
        *(char *)((int)psVar14 + iVar5) = *(char *)((int)pSamples + iVar5);
      }
      g_nDecompressedDataBytes = g_nDecompressedDataBytes + uVar7;
    }
    if (voice_showincoming.value != 0.0) {
      Con_Printf("Voice - %d incoming samples added to channel %d\n",uVar4,local_486c);
    }
  }
  return;
}


