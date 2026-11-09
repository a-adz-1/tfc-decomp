// Voice_AddIncomingData  @ 001b3b30
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

int Voice_AddIncomingData(int nChannel,char *pchData,int nCount,int iSequenceNumber)

{
  char cVar1;
  IVoiceCodec *pIVar2;
  undefined4 uVar3;
  bool bVar4;
  int iVar5;
  ulonglong uVar6;
  undefined1 auVar7 [12];
  uint nSamples;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  int iVar12;
  short *psVar13;
  short *psVar14;
  short *psVar15;
  int in_GS_OFFSET;
  byte bVar16;
  undefined2 in_FPUControlWord;
  uint uVar17;
  uint uVar20;
  undefined1 auVar18 [12];
  uint uVar21;
  undefined1 auVar19 [16];
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  undefined1 auVar25 [16];
  undefined1 auVar28 [16];
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  undefined1 auVar39 [14];
  undefined1 auVar38 [16];
  undefined1 auVar41 [16];
  double dVar42;
  short *local_2058;
  double local_2054;
  undefined4 local_2030;
  undefined1 local_202c [2];
  short asStack_202a [4101];
  int local_20;
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  short sVar40;
  
                    /* Unresolved local var: CVoiceChannel * pChannel@[???]
                       Unresolved local var: CVoiceTimer timer@[???]
                       Unresolved local var: char[8192] decompressed@[???]
                       Unresolved local var: int nDecompressed@[???] */
  bVar16 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (g_bInTweakMode) {
    g_VoiceVolume = 0;
    if ((nChannel == -100) && (nChannel = 0, nCount != 0)) {
LAB_001b3b85:
      bVar4 = voice_profile.value != 0.0;
      g_VoiceChannels[nChannel].m_bStarved = false;
      if (bVar4) {
        local_2054 = Sys_FloatTime();
      }
      if (g_bUsingSteamVoice == false) {
        pIVar2 = g_VoiceChannels[nChannel].m_pVoiceCodec;
        if (pIVar2 == (IVoiceCodec *)0x0) {
          if (g_bInTweakMode != false) {
            nSamples = 0;
            uVar9 = 0xffffffff;
            goto LAB_001b3db0;
          }
          uVar9 = 0xffffffff;
          nSamples = 0;
        }
        else {
          nSamples = (*(pIVar2->super_IBaseInterface)._vptr_IBaseInterface[5])
                               (pIVar2,pchData,nCount,local_202c,0x2000);
LAB_001b3bf4:
          if (g_bInTweakMode == false) {
            uVar9 = nSamples - 1;
          }
          else {
                    /* Unresolved local var: short * data@[???]
                       Unresolved local var: int i@[???] */
            if ((int)nSamples < 1) {
              uVar9 = nSamples - 1;
            }
            else {
              uVar9 = nSamples - 1;
              uVar11 = (nSamples - 8 >> 3) + 1;
              iVar12 = uVar11 * 8;
              if (uVar9 < 7) {
                iVar12 = 0;
              }
              else {
                uVar17 = 0;
                uVar35 = g_VoiceVolume;
                uVar36 = g_VoiceVolume;
                uVar37 = g_VoiceVolume;
                do {
                  uVar8 = uVar17 + 1;
                  auVar38 = *(undefined1 (*) [16])(local_202c + uVar17 * 0x10);
                  auVar28._0_2_ = auVar38._0_2_;
                  auVar39 = SUB1614((undefined1  [16])0x0,2);
                  sVar40 = -(ushort)(auVar38._8_2_ < 0);
                  auVar27._0_12_ = auVar38._0_12_;
                  auVar27._12_2_ = auVar38._6_2_;
                  auVar27._14_2_ = -(ushort)(auVar38._6_2_ < 0);
                  auVar26._12_4_ = auVar27._12_4_;
                  auVar26._0_10_ = auVar38._0_10_;
                  auVar26._10_2_ = -(ushort)(auVar38._4_2_ < 0);
                  auVar25._10_6_ = auVar26._10_6_;
                  auVar25._0_8_ = auVar38._0_8_;
                  auVar25._8_2_ = auVar38._4_2_;
                  auVar7._4_8_ = auVar25._8_8_;
                  auVar7._2_2_ = -(ushort)(auVar38._2_2_ < 0);
                  auVar7._0_2_ = auVar38._2_2_;
                  auVar28._2_2_ = -(ushort)(auVar28._0_2_ < 0);
                  auVar28._4_12_ = auVar7;
                  auVar18._0_8_ =
                       CONCAT26(-(ushort)(auVar38._10_2_ < auVar39._8_2_),
                                CONCAT24(auVar38._10_2_,CONCAT22(sVar40,auVar38._8_2_)));
                  auVar18._8_2_ = auVar38._12_2_;
                  auVar18._10_2_ = -(ushort)(auVar38._12_2_ < auVar39._10_2_);
                  auVar19._12_2_ = auVar38._14_2_;
                  auVar19._0_12_ = auVar18;
                  auVar19._14_2_ = -(ushort)(auVar38._14_2_ < auVar39._12_2_);
                  auVar38._0_4_ = (int)(short)-(ushort)(auVar28._0_2_ < 0) >> 0xf;
                  auVar38._4_4_ = auVar7._0_4_ >> 0x1f;
                  auVar38._8_4_ = auVar25._8_4_ >> 0x1f;
                  auVar38._12_4_ = auVar26._12_4_ >> 0x1f;
                  auVar41._0_4_ = (int)sVar40 >> 0xf;
                  auVar41._4_4_ = (int)((longlong)auVar18._0_8_ >> 0x3f);
                  auVar41._8_4_ = auVar18._8_4_ >> 0x1f;
                  auVar41._12_4_ = auVar19._12_4_ >> 0x1f;
                  auVar28 = auVar28 ^ auVar38;
                  auVar19 = auVar19 ^ auVar41;
                  uVar23 = auVar28._0_4_ - auVar38._0_4_;
                  uVar29 = auVar28._4_4_ - auVar38._4_4_;
                  uVar31 = auVar28._8_4_ - auVar38._8_4_;
                  uVar33 = auVar28._12_4_ - auVar38._12_4_;
                  uVar17 = auVar19._0_4_ - auVar41._0_4_;
                  uVar20 = auVar19._4_4_ - auVar41._4_4_;
                  uVar21 = auVar19._8_4_ - auVar41._8_4_;
                  uVar22 = auVar19._12_4_ - auVar41._12_4_;
                  uVar24 = -(uint)((int)uVar23 < (int)uVar17);
                  uVar30 = -(uint)((int)uVar29 < (int)uVar20);
                  uVar32 = -(uint)((int)uVar31 < (int)uVar21);
                  uVar34 = -(uint)((int)uVar33 < (int)uVar22);
                  uVar17 = uVar17 & uVar24 | ~uVar24 & uVar23;
                  uVar20 = uVar20 & uVar30 | ~uVar30 & uVar29;
                  uVar21 = uVar21 & uVar32 | ~uVar32 & uVar31;
                  uVar22 = uVar22 & uVar34 | ~uVar34 & uVar33;
                  uVar23 = -(uint)(g_VoiceVolume < (int)uVar17);
                  uVar24 = -(uint)((int)uVar35 < (int)uVar20);
                  uVar29 = -(uint)((int)uVar36 < (int)uVar21);
                  uVar30 = -(uint)((int)uVar37 < (int)uVar22);
                  g_VoiceVolume = ~uVar23 & g_VoiceVolume | uVar17 & uVar23;
                  uVar35 = ~uVar24 & uVar35 | uVar20 & uVar24;
                  uVar36 = ~uVar29 & uVar36 | uVar21 & uVar29;
                  uVar37 = ~uVar30 & uVar37 | uVar22 & uVar30;
                  uVar17 = uVar8;
                } while (uVar8 < uVar11);
                uVar11 = uVar36 & -(uint)(g_VoiceVolume < (int)uVar36) |
                         ~-(uint)(g_VoiceVolume < (int)uVar36) & g_VoiceVolume;
                uVar17 = uVar37 & -(uint)((int)uVar35 < (int)uVar37) |
                         ~-(uint)((int)uVar35 < (int)uVar37) & uVar35;
                uVar35 = -(uint)((int)uVar11 < (int)uVar17);
                g_VoiceVolume = uVar17 & uVar35 | ~uVar35 & uVar11;
                if (iVar12 - nSamples == 0) goto LAB_001b3db0;
              }
              iVar5 = iVar12 * 2;
              uVar11 = (int)*(short *)(local_202c + iVar5) >> 0x1f;
              uVar11 = ((int)*(short *)(local_202c + iVar5) ^ uVar11) - uVar11;
              if (g_VoiceVolume < (int)uVar11) {
                g_VoiceVolume = uVar11;
              }
              if (iVar12 + 1 < (int)nSamples) {
                uVar11 = (int)*(short *)(local_202c + iVar5 + 2) >> 0x1f;
                uVar11 = ((int)*(short *)(local_202c + iVar5 + 2) ^ uVar11) - uVar11;
                if (g_VoiceVolume < (int)uVar11) {
                  g_VoiceVolume = uVar11;
                }
                if (iVar12 + 2 < (int)nSamples) {
                  uVar11 = (int)*(short *)(local_202c + iVar5 + 4) >> 0x1f;
                  uVar11 = ((int)*(short *)(local_202c + iVar5 + 4) ^ uVar11) - uVar11;
                  if (g_VoiceVolume < (int)uVar11) {
                    g_VoiceVolume = uVar11;
                  }
                  if (iVar12 + 3 < (int)nSamples) {
                    uVar11 = (int)*(short *)(local_202c + iVar5 + 6) >> 0x1f;
                    uVar11 = ((int)*(short *)(local_202c + iVar5 + 6) ^ uVar11) - uVar11;
                    if (g_VoiceVolume < (int)uVar11) {
                      g_VoiceVolume = uVar11;
                    }
                    if (iVar12 + 4 < (int)nSamples) {
                      uVar11 = (int)*(short *)(local_202c + iVar5 + 8) >> 0x1f;
                      uVar11 = ((int)*(short *)(local_202c + iVar5 + 8) ^ uVar11) - uVar11;
                      if (g_VoiceVolume < (int)uVar11) {
                        g_VoiceVolume = uVar11;
                      }
                      if (iVar12 + 5 < (int)nSamples) {
                        uVar11 = (int)*(short *)(local_202c + iVar5 + 10) >> 0x1f;
                        uVar11 = ((int)*(short *)(local_202c + iVar5 + 10) ^ uVar11) - uVar11;
                        if (g_VoiceVolume < (int)uVar11) {
                          g_VoiceVolume = uVar11;
                        }
                        if ((iVar12 + 6 < (int)nSamples) &&
                           (uVar11 = (int)*(short *)(local_202c + iVar5 + 0xc) >> 0x1f,
                           uVar11 = ((int)*(short *)(local_202c + iVar5 + 0xc) ^ uVar11) - uVar11,
                           g_VoiceVolume < (int)uVar11)) {
                          g_VoiceVolume = uVar11;
                        }
                      }
                    }
                  }
                }
              }
            }
LAB_001b3db0:
            g_VoiceVolume = g_VoiceVolume & 0xfe00;
          }
        }
        local_2058 = (short *)local_202c;
        if (voice_profile.value != 0.0) {
          dVar42 = Sys_FloatTime();
          g_DecompressTime = (dVar42 - local_2054) + g_DecompressTime;
          if (voice_profile.value != 0.0) {
            local_2054 = Sys_FloatTime();
          }
        }
        CAutoGain::ProcessSamples(&g_VoiceChannels[nChannel].m_AutoGain,local_2058,nSamples);
        if (voice_profile.value != 0.0) {
          dVar42 = Sys_FloatTime();
          g_GainTime = (dVar42 - local_2054) + g_GainTime;
          if (voice_profile.value != 0.0) {
            local_2054 = Sys_FloatTime();
          }
        }
        uVar6 = (ulonglong)g_VoiceSampleFormat.nSamplesPerSec;
        dVar42 = g_VoiceChannels[nChannel].m_LastFraction;
                    /* Unresolved local var: double maxFraction@[???] */
                    /* Unresolved local var: int iSample@[???]
                       Unresolved local var: double frac@[???]
                       Unresolved local var: double val1@[???]
                       Unresolved local var: double val2@[???]
                       Unresolved local var: short newSample@[???] */
        if (dVar42 < (double)(int)uVar9) {
          do {
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
            local_2030 = CONCAT22((short)(local_2030 >> 0x10),
                                  (short)(int)((double)*(short *)(local_202c + (int)dVar42 * 2) +
                                              (dVar42 - ROUND(dVar42)) *
                                              ((double)*(short *)(local_202c + (int)dVar42 * 2 + 2)
                                              - (double)*(short *)(local_202c + (int)dVar42 * 2))));
            CCircularBuffer::Write
                      (&g_VoiceChannels[nChannel].m_Buffer.super_CCircularBuffer,&local_2030,2);
            dVar42 = dVar42 + (double)((float)uVar6 / 11025.0);
          } while (dVar42 < (double)(int)uVar9);
        }
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
        local_2030 = CONCAT22(local_2030._2_2_,in_FPUControlWord) & 0xfffff3ff | 0x400;
        cVar1 = local_202c[nSamples];
        g_VoiceChannels[nChannel].m_LastFraction = dVar42 - ROUND(dVar42);
        bVar4 = voice_profile.value != 0.0;
        g_VoiceChannels[nChannel].m_LastSample = (short)cVar1;
        if (bVar4) {
          dVar42 = Sys_FloatTime();
          g_UpsampleTime = (dVar42 - local_2054) + g_UpsampleTime;
        }
        if (g_pDecompressedFileData != (char *)0x0) {
                    /* Unresolved local var: int nToWrite@[???] */
          uVar9 = 0x100000U - g_nDecompressedDataBytes;
          if ((int)(nSamples * 2) < (int)(0x100000U - g_nDecompressedDataBytes)) {
            uVar9 = nSamples * 2;
          }
          psVar13 = (short *)(g_pDecompressedFileData + g_nDecompressedDataBytes);
          uVar11 = uVar9;
          if (7 < uVar9) {
            psVar15 = psVar13;
            if (((uint)psVar13 & 1) != 0) {
              psVar15 = (short *)((int)psVar13 + 1);
              local_2058 = (short *)(local_202c + 1);
              uVar11 = uVar9 - 1;
              *(char *)psVar13 = local_202c[0];
            }
            psVar14 = psVar15;
            if (((uint)psVar15 & 2) != 0) {
              sVar40 = *local_2058;
              psVar14 = psVar15 + 1;
              local_2058 = local_2058 + 1;
              uVar11 = uVar11 - 2;
              *psVar15 = sVar40;
            }
            psVar13 = psVar14;
            if (((uint)psVar14 & 4) != 0) {
              uVar3 = *(undefined4 *)local_2058;
              psVar13 = psVar14 + 2;
              local_2058 = local_2058 + 2;
              uVar11 = uVar11 - 4;
              *(undefined4 *)psVar14 = uVar3;
            }
          }
          for (; uVar11 != 0; uVar11 = uVar11 - 1) {
            *(char *)psVar13 = (char)*local_2058;
            local_2058 = (short *)((int)local_2058 + (uint)bVar16 * -2 + 1);
            psVar13 = (short *)((int)psVar13 + (uint)bVar16 * -2 + 1);
          }
          g_nDecompressedDataBytes = g_nDecompressedDataBytes + uVar9;
        }
        if (voice_showincoming.value != 0.0) {
          Con_Printf("Voice - %d incoming samples added to channel %d\n",nSamples,nChannel);
        }
        goto LAB_001b3dcf;
      }
      local_2030 = 0;
      puVar10 = (undefined4 *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
      iVar12 = (**(code **)(*(int *)*puVar10 + 0x2c))
                         ((int *)*puVar10,pchData,nCount,local_202c,0x2000,&local_2030,0x2b11);
      if ((iVar12 == 0) && (local_2030 != 0)) {
        nSamples = local_2030 >> 1;
        goto LAB_001b3bf4;
      }
    }
  }
  else if ((nCount != 0) && ((uint)nChannel < 5)) goto LAB_001b3b85;
                    /* Unresolved local var: uint32 nBytesWritten@[???]
                       Unresolved local var: EVoiceResult result@[???] */
  nChannel = 0;
LAB_001b3dcf:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return nChannel;
}


// Voice_AssignChannel  @ 001b37d0
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

int Voice_AssignChannel(int nEntity)

{
  IVoiceCodec *pIVar1;
  float scale;
  float maxGain;
  float avgToMaxVal;
  int iVar2;
  
                    /* Unresolved local var: int iFree@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
  if (g_bInTweakMode) {
    iVar2 = -2;
  }
  else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
    if (g_VoiceChannels[0].m_iEntity == nEntity) {
      iVar2 = 0;
    }
    else {
      if (g_VoiceChannels[0].m_iEntity == -1) {
        iVar2 = 0;
      }
      else {
        if (nEntity == g_VoiceChannels[1].m_iEntity) {
          return 1;
        }
        if (g_VoiceChannels[1].m_iEntity == -1) {
          iVar2 = 1;
        }
        else {
          if (nEntity == g_VoiceChannels[2].m_iEntity) {
            return 2;
          }
          if (g_VoiceChannels[2].m_iEntity == -1) {
            iVar2 = 2;
          }
          else {
            if (nEntity == g_VoiceChannels[3].m_iEntity) {
              return 3;
            }
            if (g_VoiceChannels[3].m_iEntity == -1) {
              iVar2 = 3;
            }
            else {
              if (g_VoiceChannels[4].m_iEntity == nEntity) {
                return 4;
              }
              iVar2 = 4;
              if (g_VoiceChannels[4].m_iEntity != -1) {
                return -1;
              }
            }
          }
        }
      }
      pIVar1 = g_VoiceChannels[iVar2].m_pVoiceCodec;
      if (pIVar1 != (IVoiceCodec *)0x0) {
        (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[6])(pIVar1);
      }
      g_VoiceChannels[iVar2].m_iEntity = nEntity;
      g_VoiceChannels[iVar2].m_bStarved = false;
      CCircularBuffer::Flush(&g_VoiceChannels[iVar2].m_Buffer.super_CCircularBuffer);
      avgToMaxVal = voice_avggain.value;
      maxGain = voice_maxgain.value;
      scale = voice_scale.value;
      g_VoiceChannels[iVar2].m_LastSample = 0;
      *(undefined4 *)&g_VoiceChannels[iVar2].m_LastFraction = 0xd916872b;
      *(undefined4 *)((int)&g_VoiceChannels[iVar2].m_LastFraction + 4) = 0x3feff7ce;
      g_VoiceChannels[iVar2].m_TimePad = 0.2;
      CAutoGain::Reset(&g_VoiceChannels[iVar2].m_AutoGain,0x80,maxGain,avgToMaxVal,scale);
      VoiceSE_StartOverdrive();
    }
  }
  return iVar2;
}


// Voice_Deinit  @ 001b2c30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

void Voice_Deinit(void)

{
  IVoiceCodec *pIVar1;
  CVoiceChannel *pCVar2;
  CVoiceChannel *pCVar3;
  int iChannel;
  
  iChannel = 0;
  pCVar2 = g_VoiceChannels;
  pCVar3 = g_VoiceChannels;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
    VoiceSE_EndChannel(iChannel);
    if (-1 < pCVar3->m_iEntity) {
      ClientDLL_VoiceStatus(pCVar3->m_iEntity,false);
      VoiceSE_CloseMouth(pCVar3->m_iEntity);
    }
    iChannel = iChannel + 1;
    pCVar3->m_iEntity = -1;
    pCVar3 = pCVar3 + 1;
  } while (iChannel != 5);
  Voice_RecordStop();
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
    pIVar1 = pCVar2->m_pVoiceCodec;
    if (pIVar1 != (IVoiceCodec *)0x0) {
      (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[3])(pIVar1);
      pCVar2->m_pVoiceCodec = (IVoiceCodec *)0x0;
    }
    pCVar2 = pCVar2 + 1;
  } while (pCVar2 != (CVoiceChannel *)&g_hVoiceCodecDLL);
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


// Voice_Deinit  @ 001b2d20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Voice_Deinit(void)

{
  if (g_bVoiceAtLeastPartiallyInitted) {
    Voice_Deinit();
    return;
  }
  return;
}


// Voice_EndAllChannels  @ 001b2a10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

void Voice_EndAllChannels(void)

{
  CVoiceChannel *pCVar1;
  int iChannel;
  
                    /* Unresolved local var: int i@[???] */
  iChannel = 0;
  pCVar1 = g_VoiceChannels;
  do {
                    /* Unresolved local var: CVoiceChannel * pChannel@[???] */
    VoiceSE_EndChannel(iChannel);
    if (-1 < pCVar1->m_iEntity) {
      ClientDLL_VoiceStatus(pCVar1->m_iEntity,false);
      VoiceSE_CloseMouth(pCVar1->m_iEntity);
    }
    iChannel = iChannel + 1;
    pCVar1->m_iEntity = -1;
    pCVar1 = pCVar1 + 1;
  } while (iChannel != 5);
  return;
}


// Voice_EndChannel  @ 001b2940
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


// Voice_FlushChannel  @ 001b4c10
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

void Voice_FlushChannel(int nChannel)

{
  if (4 < (uint)nChannel) {
    return;
  }
  CCircularBuffer::Flush(&g_VoiceChannels[nChannel].m_Buffer.super_CCircularBuffer);
  return;
}


// Voice_GetChannel  @ 001b39b0
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

int Voice_GetChannel(int nEntity)

{
                    /* Unresolved local var: int i@[???] */
  if (nEntity == g_VoiceChannels[0].m_iEntity) {
    return 0;
  }
  if (nEntity == g_VoiceChannels[1].m_iEntity) {
    return 1;
  }
  if (nEntity == g_VoiceChannels[2].m_iEntity) {
    return 2;
  }
  if (nEntity != g_VoiceChannels[3].m_iEntity) {
    if (g_VoiceChannels[4].m_iEntity != nEntity) {
      return -1;
    }
    return 4;
  }
  return 3;
}


// Voice_GetClientListening  @ 000e3f20
qboolean Voice_GetClientListening(int iReceiver,int iSender)

{
  int iVar1;
  int iVar2;
  
  iVar1 = iSender + -1;
  iVar2 = iReceiver + -1;
  if (((-1 < iVar2) && (iVar2 < svs.maxclients && -1 < iVar1)) && (iVar1 < svs.maxclients)) {
    return (uint)(svs.clients[iVar1].m_VoiceStreams[iVar2 >> 5] != 0) & 1 << ((byte)iVar2 & 0x1f);
  }
  return false;
}


// Voice_GetCompressedData  @ 001b3430
/* WARNING: Type propagation algorithm not settling */

int Voice_GetCompressedData(char *pchDest,int nCount,qboolean bFinal)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  byte bVar13;
  double dVar14;
  double local_403c;
  int local_4028;
  int local_4024 [2];
  char local_401c [16396];
  
  bVar13 = 0;
  if (g_bUsingSteamVoice) {
                    /* Unresolved local var: uint32 cbCompressedWritten@[???]
                       Unresolved local var: uint32 cbUncompressedWritten@[???]
                       Unresolved local var: uint32 cbCompressed@[???]
                       Unresolved local var: uint32 cbUncompressed@[???]
                       Unresolved local var: EVoiceResult result@[???] */
    local_4028 = 0;
    local_4024[0] = 0;
    local_4024[1] = 0;
    local_401c[0] = '\0';
    local_401c[1] = '\0';
    local_401c[2] = '\0';
    local_401c[3] = '\0';
    puVar4 = (undefined4 *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
    iVar3 = (**(code **)(*(int *)*puVar4 + 0x24))
                      ((int *)*puVar4,local_4024 + 1,local_401c,
                       ~-(uint)(g_pUncompressedFileData == (char *)0x0) & 0x2b11);
    if (iVar3 == 0) {
      puVar4 = (undefined4 *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
      (**(code **)(*(int *)*puVar4 + 0x28))
                ((int *)*puVar4,1,pchDest,nCount,&local_4028,g_pUncompressedFileData != (char *)0x0,
                 g_pUncompressedFileData,0x100000 - g_nUncompressedDataBytes,local_4024,0x2b11);
      if (g_pUncompressedFileData != (char *)0x0) {
        g_nUncompressedDataBytes = g_nUncompressedDataBytes + local_4024[0];
      }
    }
    return local_4028;
  }
  if ((g_pVoiceRecord != (IVoiceRecord *)0x0) && (g_pEncodeCodec != (IVoiceCodec *)0x0)) {
                    /* Unresolved local var: short[8192] tempData@[???]
                       Unresolved local var: int gotten@[???]
                       Unresolved local var: CVoiceTimer timer@[???]
                       Unresolved local var: int nCompressedBytes@[???] */
    pcVar9 = local_401c;
    iVar3 = nCount / 2;
    if (0x2000 < iVar3) {
      iVar3 = 0x2000;
    }
    iVar3 = (*g_pVoiceRecord->_vptr_IVoiceRecord[6])(g_pVoiceRecord,pcVar9,iVar3);
    if (g_pMicInputFileData != (char *)0x0) {
                    /* Unresolved local var: double curtime@[???]
                       Unresolved local var: int nShouldGet@[???] */
      dVar14 = Sys_FloatTime();
      iVar3 = (g_nMicInputFileBytes - g_CurMicInputFileByte) / 2;
      iVar6 = (int)((double)g_VoiceSampleFormat.nSamplesPerSec * (dVar14 - g_MicStartTime));
      if (iVar6 <= iVar3) {
        iVar3 = iVar6;
      }
      if (iVar3 < 0x2000) {
        iVar6 = iVar3 * 2;
      }
      else {
        iVar6 = 0x4000;
        iVar3 = 0x2000;
      }
      iVar8 = g_CurMicInputFileByte + iVar6;
      __memcpy_chk(pcVar9,g_pMicInputFileData + g_CurMicInputFileByte,iVar6,0x4000);
      g_MicStartTime = dVar14;
      g_CurMicInputFileByte = iVar8;
    }
    if (voice_profile.value != 0.0) {
      local_403c = Sys_FloatTime();
    }
    iVar6 = (*(g_pEncodeCodec->super_IBaseInterface)._vptr_IBaseInterface[4])
                      (g_pEncodeCodec,pcVar9,iVar3,pchDest,nCount,(uint)(bFinal != 0));
    if (voice_profile.value != 0.0) {
      dVar14 = Sys_FloatTime();
      g_CompressTime = (dVar14 - local_403c) + g_CompressTime;
    }
    if (g_pUncompressedFileData != (char *)0x0) {
                    /* Unresolved local var: int nToWrite@[???] */
      uVar7 = iVar3 * 2;
      if ((int)(0x100000U - g_nUncompressedDataBytes) <= iVar3 * 2) {
        uVar7 = 0x100000U - g_nUncompressedDataBytes;
      }
      pcVar10 = g_pUncompressedFileData + g_nUncompressedDataBytes;
      uVar5 = uVar7;
      if (7 < uVar7) {
        pcVar12 = pcVar10;
        if (((uint)pcVar10 & 1) != 0) {
          pcVar12 = pcVar10 + 1;
          pcVar9 = local_401c + 1;
          uVar5 = uVar7 - 1;
          *pcVar10 = local_401c[0];
        }
        pcVar11 = pcVar12;
        if (((uint)pcVar12 & 2) != 0) {
          uVar1 = *(undefined2 *)pcVar9;
          pcVar11 = pcVar12 + 2;
          pcVar9 = pcVar9 + 2;
          uVar5 = uVar5 - 2;
          *(undefined2 *)pcVar12 = uVar1;
        }
        pcVar10 = pcVar11;
        if (((uint)pcVar11 & 4) != 0) {
          uVar2 = *(undefined4 *)pcVar9;
          pcVar10 = pcVar11 + 4;
          pcVar9 = pcVar9 + 4;
          uVar5 = uVar5 - 4;
          *(undefined4 *)pcVar11 = uVar2;
        }
      }
      for (; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar10 = *pcVar9;
        pcVar9 = pcVar9 + (uint)bVar13 * -2 + 1;
        pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
      }
      g_nUncompressedDataBytes = g_nUncompressedDataBytes + uVar7;
    }
    return iVar6;
  }
  return 0;
}


// Voice_GetLoopback  @ 001b2a60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Voice_GetLoopback(void)

{
  uint uVar1;
  
  uVar1 = (uint)NAN(voice_loopback.value);
  if (voice_loopback.value != 0.0) {
    uVar1 = 1;
  }
  return uVar1;
}


// Voice_GetOutputData  @ 001b20c0
/* WARNING: Removing unreachable block (ram,0x001b27d0) */
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

int Voice_GetOutputData(int iChannel,char *copyBufBytes,int copyBufSize,int samplePosition,
                       int sampleCount)

{
  short *psVar1;
  int iVar2;
  undefined1 auVar3 [12];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  float fVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined1 (*pauVar11) [16];
  int iVar12;
  undefined1 (*pauVar13) [16];
  int iVar14;
  int iVar15;
  int iVar16;
  CSizedCircularBuffer<22050> *this;
  uint uVar17;
  uint uVar18;
  char *pcVar19;
  byte bVar20;
  int iVar21;
  undefined1 auVar22 [12];
  int iVar38;
  int iVar39;
  int iVar40;
  undefined1 auVar23 [16];
  undefined1 auVar26 [16];
  undefined1 auVar30 [16];
  undefined1 auVar34 [16];
  undefined2 uVar43;
  undefined2 uVar44;
  int iVar45;
  undefined2 uVar46;
  undefined1 auVar41 [12];
  int iVar47;
  int iVar48;
  int iVar49;
  int iVar50;
  int iVar51;
  int iVar52;
  int iVar53;
  undefined1 auVar54 [14];
  int local_34;
  undefined1 auVar27 [16];
  undefined1 auVar31 [16];
  undefined1 auVar35 [16];
  undefined1 auVar24 [16];
  undefined1 auVar28 [16];
  undefined1 auVar32 [16];
  undefined1 auVar36 [16];
  undefined1 auVar25 [16];
  undefined1 auVar29 [16];
  undefined1 auVar33 [16];
  undefined1 auVar37 [16];
  undefined1 auVar42 [16];
  
                    /* Unresolved local var: CVoiceChannel * pChannel@[???]
                       Unresolved local var: short * pCopyBuf@[???]
                       Unresolved local var: int maxOutSamples@[???]
                       Unresolved local var: CCircularBuffer * pBuffer@[???]
                       Unresolved local var: int nBytesToRead@[???]
                       Unresolved local var: int nSamplesGotten@[???]
                       Unresolved local var: int readSamplesAvail@[???] */
  bVar20 = 0;
  this = &g_VoiceChannels[iChannel].m_Buffer;
  iVar14 = copyBufSize / 2;
  iVar7 = CCircularBuffer::GetReadAvailable(&this->super_CCircularBuffer);
  iVar8 = sampleCount * 2;
  if (iVar14 < sampleCount * 2) {
    iVar8 = iVar14;
  }
  if (iVar8 <= iVar7) {
    iVar7 = iVar8;
  }
  iVar7 = CCircularBuffer::Read(&this->super_CCircularBuffer,copyBufBytes,iVar7);
  iVar7 = iVar7 / 2;
  iVar8 = CCircularBuffer::GetReadAvailable(&this->super_CCircularBuffer);
  fVar6 = g_VoiceFadeMul;
  if (iVar8 / 2 < g_nVoiceFadeSamples) {
                    /* Unresolved local var: int bufferFadeOffset@[???]
                       Unresolved local var: int globalFadeOffset@[???] */
    iVar8 = iVar8 / 2 + iVar7;
    iVar12 = iVar8 - g_nVoiceFadeSamples;
    if (iVar12 < 0) {
      iVar12 = 0;
    }
    iVar8 = g_nVoiceFadeSamples - iVar8;
    iVar15 = 0;
    if (-1 < iVar8) {
      iVar15 = iVar8;
    }
    uVar9 = iVar7 - iVar12;
                    /* Unresolved local var: int i@[???] */
    iVar8 = iVar12 * 2;
    if (0 < (int)uVar9) {
      psVar1 = (short *)(copyBufBytes + iVar8);
      uVar10 = -(((uint)psVar1 & 0xf) >> 1) & 7;
      if (uVar9 < uVar10) {
        uVar10 = uVar9;
      }
      uVar17 = uVar9;
      if (((int)uVar9 < 9) || (uVar17 = uVar10, uVar10 != 0)) {
                    /* Unresolved local var: float percent@[???] */
        *psVar1 = (short)(int)((float)*psVar1 * (1.0 - (float)iVar15 * g_VoiceFadeMul));
        if (uVar17 == 1) {
          iVar16 = 1;
        }
        else {
          *(short *)(copyBufBytes + iVar8 + 2) =
               (short)(int)((float)*(short *)(copyBufBytes + iVar8 + 2) *
                           (1.0 - (float)(iVar15 + 1) * fVar6));
          if (uVar17 == 2) {
            iVar16 = 2;
          }
          else {
            *(short *)(copyBufBytes + iVar8 + 4) =
                 (short)(int)((float)*(short *)(copyBufBytes + iVar8 + 4) *
                             (1.0 - (float)(iVar15 + 2) * fVar6));
            if (uVar17 == 3) {
              iVar16 = 3;
            }
            else {
              *(short *)(copyBufBytes + iVar8 + 6) =
                   (short)(int)((float)*(short *)(copyBufBytes + iVar8 + 6) *
                               (1.0 - (float)(iVar15 + 3) * fVar6));
              if (uVar17 == 4) {
                iVar16 = 4;
              }
              else {
                *(short *)(copyBufBytes + iVar8 + 8) =
                     (short)(int)((float)*(short *)(copyBufBytes + iVar8 + 8) *
                                 (1.0 - (float)(iVar15 + 4) * fVar6));
                if (uVar17 == 5) {
                  iVar16 = 5;
                }
                else {
                  *(short *)(copyBufBytes + iVar8 + 10) =
                       (short)(int)((float)*(short *)(copyBufBytes + iVar8 + 10) *
                                   (1.0 - (float)(iVar15 + 5) * fVar6));
                  if (uVar17 == 6) {
                    iVar16 = 6;
                  }
                  else {
                    *(short *)(copyBufBytes + iVar8 + 0xc) =
                         (short)(int)((float)*(short *)(copyBufBytes + iVar8 + 0xc) *
                                     (1.0 - (float)(iVar15 + 6) * fVar6));
                    if (uVar17 == 7) {
                      iVar16 = 7;
                    }
                    else {
                      *(short *)(copyBufBytes + iVar8 + 0xe) =
                           (short)(int)((float)*(short *)(copyBufBytes + iVar8 + 0xe) *
                                       (1.0 - (float)(iVar15 + 7) * fVar6));
                      iVar16 = 8;
                    }
                  }
                }
              }
            }
          }
        }
        uVar10 = uVar17;
        if (uVar9 == uVar17) goto LAB_001b2690;
      }
      else {
        iVar16 = 0;
      }
      uVar17 = ((uVar9 - uVar10) - 8 >> 3) + 1;
      iVar2 = uVar17 * 8;
      if (6 < (uVar9 - 1) - uVar10) {
        pauVar11 = (undefined1 (*) [16])(copyBufBytes + (uVar10 + iVar12) * 2);
        iVar51 = iVar16 + 1;
        iVar52 = iVar16 + 2;
        iVar53 = iVar16 + 3;
        uVar18 = 0;
        pauVar13 = pauVar11;
        iVar12 = iVar16;
        do {
          iVar21 = iVar12 + iVar15;
          iVar38 = iVar51 + iVar15;
          iVar39 = iVar52 + iVar15;
          iVar40 = iVar53 + iVar15;
          auVar26 = *pauVar11;
          auVar54 = SUB1614((undefined1  [16])0x0,2);
          uVar18 = uVar18 + 1;
          pauVar11 = pauVar11 + 1;
          auVar25._0_12_ = auVar26._0_12_;
          auVar25._12_2_ = auVar26._6_2_;
          auVar25._14_2_ = -(ushort)(auVar26._6_2_ < 0);
          auVar24._12_4_ = auVar25._12_4_;
          auVar24._0_10_ = auVar26._0_10_;
          auVar24._10_2_ = -(ushort)(auVar26._4_2_ < 0);
          auVar23._10_6_ = auVar24._10_6_;
          auVar23._0_8_ = auVar26._0_8_;
          auVar23._8_2_ = auVar26._4_2_;
          auVar3._4_8_ = auVar23._8_8_;
          auVar3._2_2_ = -(ushort)(auVar26._2_2_ < 0);
          auVar3._0_2_ = auVar26._2_2_;
          iVar45 = CONCAT22(-(ushort)(auVar26._8_2_ < 0),auVar26._8_2_);
          auVar41._0_8_ =
               CONCAT26(-(ushort)(auVar26._10_2_ < auVar54._8_2_),CONCAT24(auVar26._10_2_,iVar45));
          auVar41._8_2_ = auVar26._12_2_;
          auVar41._10_2_ = -(ushort)(auVar26._12_2_ < auVar54._10_2_);
          auVar42._12_2_ = auVar26._14_2_;
          auVar42._0_12_ = auVar41;
          auVar42._14_2_ = -(ushort)(auVar26._14_2_ < auVar54._12_2_);
          iVar47 = iVar12 + 4;
          iVar48 = iVar51 + 4;
          iVar49 = iVar52 + 4;
          iVar50 = iVar53 + 4;
          iVar12 = iVar12 + 8;
          iVar51 = iVar51 + 8;
          iVar52 = iVar52 + 8;
          iVar53 = iVar53 + 8;
          iVar21 = (int)((float)CONCAT22(-(ushort)(auVar26._0_2_ < 0),auVar26._0_2_) *
                        (1.0 - (float)iVar21 * fVar6));
          iVar38 = (int)((float)auVar3._0_4_ * (1.0 - (float)iVar38 * fVar6));
          auVar22._0_8_ = CONCAT44(iVar38,iVar21);
          auVar22._8_4_ = (int)((float)auVar23._8_4_ * (1.0 - (float)iVar39 * fVar6));
          iVar39 = (int)((float)iVar45 * (1.0 - (float)(iVar47 + iVar15) * fVar6));
          iVar45 = (int)((float)(int)((ulonglong)auVar41._0_8_ >> 0x20) *
                        (1.0 - (float)(iVar48 + iVar15) * fVar6));
          iVar47 = (int)((float)auVar41._8_4_ * (1.0 - (float)(iVar49 + iVar15) * fVar6));
          uVar46 = (undefined2)iVar47;
          auVar29._12_2_ = (short)((uint)iVar38 >> 0x10);
          auVar29._0_12_ = auVar22;
          auVar29._14_2_ = (short)((uint)iVar45 >> 0x10);
          auVar28._12_4_ = auVar29._12_4_;
          auVar28._0_10_ = auVar22._0_10_;
          uVar44 = (undefined2)iVar45;
          auVar28._10_2_ = uVar44;
          auVar27._10_6_ = auVar28._10_6_;
          auVar27._8_2_ = (short)iVar38;
          auVar27._0_8_ = auVar22._0_8_;
          uVar43 = (undefined2)((uint)iVar39 >> 0x10);
          auVar4._2_8_ = auVar27._8_8_;
          auVar4._0_2_ = uVar43;
          auVar4._10_6_ = 0;
          auVar34._0_2_ = (undefined2)iVar21;
          auVar26._12_4_ = 0;
          auVar26._0_12_ = SUB1612(auVar4 << 0x30,4);
          auVar26 = auVar26 << 0x20;
          auVar33._0_12_ = auVar26._0_12_;
          auVar33._12_2_ = uVar43;
          auVar33._14_2_ = (short)((uint)iVar47 >> 0x10);
          auVar32._12_4_ = auVar33._12_4_;
          auVar32._0_10_ = auVar26._0_10_;
          auVar32._10_2_ = (short)((uint)auVar22._8_4_ >> 0x10);
          auVar31._10_6_ = auVar32._10_6_;
          auVar31._0_8_ = auVar26._0_8_;
          auVar31._8_2_ = (short)((uint)iVar21 >> 0x10);
          auVar5._2_8_ = auVar31._8_8_;
          auVar5._0_2_ = uVar46;
          auVar5._10_6_ = 0;
          auVar30._12_4_ = 0;
          auVar30._0_12_ = SUB1612(auVar5 << 0x30,4);
          auVar30 = auVar30 << 0x20;
          auVar37._0_12_ = auVar30._0_12_;
          auVar37._12_2_ = uVar46;
          auVar37._14_2_ =
               (short)(int)((float)auVar42._12_4_ * (1.0 - (float)(iVar50 + iVar15) * fVar6));
          auVar36._12_4_ = auVar37._12_4_;
          auVar36._0_10_ = auVar30._0_10_;
          auVar36._10_2_ = uVar44;
          auVar35._10_6_ = auVar36._10_6_;
          auVar35._0_8_ = auVar30._0_8_;
          auVar35._8_2_ = (short)iVar39;
          auVar34._8_8_ = auVar35._8_8_;
          auVar34._6_2_ = (short)(int)((float)auVar24._12_4_ * (1.0 - (float)iVar40 * fVar6));
          auVar34._4_2_ = (short)auVar22._8_4_;
          auVar34._2_2_ = (short)iVar38;
          *pauVar13 = auVar34;
          pauVar13 = pauVar13 + 1;
        } while (uVar18 < uVar17);
        iVar16 = iVar16 + iVar2;
        if (uVar9 - uVar10 == iVar2) goto LAB_001b2690;
      }
      iVar12 = iVar16 * 2;
      *(short *)(copyBufBytes + iVar8 + iVar12) =
           (short)(int)((float)*(short *)(copyBufBytes + iVar8 + iVar12) *
                       (1.0 - (float)(iVar15 + iVar16) * fVar6));
      if (iVar16 + 1 < (int)uVar9) {
        *(short *)(copyBufBytes + iVar8 + 2 + iVar12) =
             (short)(int)((float)*(short *)(copyBufBytes + iVar8 + 2 + iVar12) *
                         (1.0 - (float)(iVar15 + iVar16 + 1) * fVar6));
        if (iVar16 + 2 < (int)uVar9) {
          *(short *)(copyBufBytes + iVar8 + 4 + iVar12) =
               (short)(int)((float)*(short *)(copyBufBytes + iVar8 + 4 + iVar12) *
                           (1.0 - (float)(iVar15 + iVar16 + 2) * fVar6));
          if (iVar16 + 3 < (int)uVar9) {
            *(short *)(copyBufBytes + iVar8 + 6 + iVar12) =
                 (short)(int)((float)*(short *)(copyBufBytes + iVar8 + 6 + iVar12) *
                             (1.0 - (float)(iVar15 + iVar16 + 3) * fVar6));
            if (iVar16 + 4 < (int)uVar9) {
              *(short *)(copyBufBytes + iVar8 + 8 + iVar12) =
                   (short)(int)((float)*(short *)(copyBufBytes + iVar8 + 8 + iVar12) *
                               (1.0 - (float)(iVar15 + iVar16 + 4) * fVar6));
              if (iVar16 + 5 < (int)uVar9) {
                *(short *)(copyBufBytes + iVar8 + 10 + iVar12) =
                     (short)(int)((float)*(short *)(copyBufBytes + iVar8 + 10 + iVar12) *
                                 (1.0 - (float)(iVar15 + iVar16 + 5) * fVar6));
                if (iVar16 + 6 < (int)uVar9) {
                  *(short *)(copyBufBytes + iVar8 + 0xc + iVar12) =
                       (short)(int)((float)*(short *)(copyBufBytes + iVar8 + 0xc + iVar12) *
                                   (1.0 - (float)(iVar16 + 6 + iVar15) * fVar6));
                }
              }
            }
          }
        }
      }
    }
  }
LAB_001b2690:
  local_34 = iVar7;
  if (iVar7 < sampleCount) {
                    /* Unresolved local var: int wantedSampleCount@[???] */
    local_34 = iVar14;
    if (sampleCount < iVar14) {
      local_34 = sampleCount;
    }
    uVar9 = (local_34 - iVar7) * 2;
    pcVar19 = copyBufBytes + iVar7 * 2;
    if (uVar9 < 8) {
      uVar10 = uVar9;
      if ((uVar9 & 4) != 0) {
        pcVar19[0] = '\0';
        pcVar19[1] = '\0';
        pcVar19[2] = '\0';
        pcVar19[3] = '\0';
        pcVar19 = pcVar19 + 4;
      }
    }
    else {
      if (((uint)pcVar19 & 1) != 0) {
        *pcVar19 = '\0';
        uVar9 = uVar9 - 1;
        pcVar19 = pcVar19 + 1;
      }
      if (((uint)pcVar19 & 2) != 0) {
        pcVar19[0] = '\0';
        pcVar19[1] = '\0';
        uVar9 = uVar9 - 2;
        pcVar19 = pcVar19 + 2;
      }
      if (((uint)pcVar19 & 4) != 0) {
        pcVar19[0] = '\0';
        pcVar19[1] = '\0';
        pcVar19[2] = '\0';
        pcVar19[3] = '\0';
        uVar9 = uVar9 - 4;
        pcVar19 = pcVar19 + 4;
      }
      uVar10 = uVar9 & 3;
      for (uVar9 = uVar9 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        pcVar19[0] = '\0';
        pcVar19[1] = '\0';
        pcVar19[2] = '\0';
        pcVar19[3] = '\0';
        pcVar19 = pcVar19 + (uint)bVar20 * -8 + 4;
      }
    }
    if ((uVar10 & 2) != 0) {
      pcVar19[0] = '\0';
      pcVar19[1] = '\0';
      pcVar19 = pcVar19 + 2;
    }
    if ((uVar10 & 1) != 0) {
      *pcVar19 = '\0';
    }
  }
  iVar7 = CCircularBuffer::GetReadAvailable(&this->super_CCircularBuffer);
  if (iVar7 == 0) {
    g_VoiceChannels[iChannel].m_bStarved = true;
  }
  if (2.0 <= voice_showchannels.value) {
    Con_Printf("Voice - mixed %d samples from channel %d\n",local_34,iChannel);
  }
  VoiceSE_MoveMouth(g_VoiceChannels[iChannel].m_iEntity,(short *)copyBufBytes,local_34);
  return local_34;
}


// Voice_Idle  @ 001b45a0
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

void Voice_Idle(float frametime)

{
  bool bVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  CCircularBuffer *this;
  
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
    g_VoiceFadeMul = 1.0;
    g_nVoiceFadeSamples = 2;
  }
  else {
    g_VoiceFadeMul = 1.0 / (float)(g_nVoiceFadeSamples + -1);
  }
  if (g_pVoiceRecord != (IVoiceRecord *)0x0) {
    (*g_pVoiceRecord->_vptr_IVoiceRecord[5])(g_pVoiceRecord);
  }
                    /* Unresolved local var: char[2048] uchVoiceData@[???]
                       Unresolved local var: bool bFinal@[???]
                       Unresolved local var: int nDataLength@[???] */
  if (g_bInTweakMode == false) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
    if (g_VoiceChannels[0].m_iEntity == -1) goto LAB_001b4b22;
LAB_001b4669:
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
      iVar4 = 1;
    }
    else {
                    /* Unresolved local var: CVoiceChannel * pChannel@[???] */
      VoiceSE_EndChannel(0);
      if (-1 < g_VoiceChannels[0].m_iEntity) {
        ClientDLL_VoiceStatus(g_VoiceChannels[0].m_iEntity,false);
        VoiceSE_CloseMouth(g_VoiceChannels[0].m_iEntity);
      }
      iVar4 = 0;
      g_VoiceChannels[0].m_iEntity = -1;
    }
  }
  else {
    Voice_UpdateVoiceTweakMode();
    if (g_VoiceChannels[0].m_iEntity != -1) goto LAB_001b4669;
LAB_001b4b22:
    iVar4 = 0;
  }
  if (g_VoiceChannels[1].m_iEntity != -1) {
    if ((g_VoiceChannels[1].m_bStarved == false) || (g_bInTweakMode != false)) {
      fVar2 = g_VoiceChannels[1].m_TimePad - frametime;
      bVar1 = 0.0 < g_VoiceChannels[1].m_TimePad;
      g_VoiceChannels[1].m_TimePad = fVar2;
      if ((bVar1) && (fVar2 <= 0.0)) {
        VoiceSE_StartChannel(1);
        ClientDLL_VoiceStatus(g_VoiceChannels[1].m_iEntity,true);
        VoiceSE_InitMouth(g_VoiceChannels[1].m_iEntity);
      }
      iVar4 = iVar4 + 1;
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
      bVar1 = 0.0 < g_VoiceChannels[2].m_TimePad;
      g_VoiceChannels[2].m_TimePad = fVar2;
      if ((bVar1) && (fVar2 <= 0.0)) {
        VoiceSE_StartChannel(2);
        ClientDLL_VoiceStatus(g_VoiceChannels[2].m_iEntity,true);
        VoiceSE_InitMouth(g_VoiceChannels[2].m_iEntity);
      }
      iVar4 = iVar4 + 1;
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
  if (g_VoiceChannels[3].m_iEntity == -1) {
LAB_001b4881:
    if (g_VoiceChannels[4].m_iEntity != -1) goto LAB_001b4a10;
  }
  else {
    if ((g_VoiceChannels[3].m_bStarved != false) && (g_bInTweakMode == false)) {
      VoiceSE_EndChannel(3);
      if (-1 < g_VoiceChannels[3].m_iEntity) {
        ClientDLL_VoiceStatus(g_VoiceChannels[3].m_iEntity,false);
        VoiceSE_CloseMouth(g_VoiceChannels[3].m_iEntity);
      }
      g_VoiceChannels[3].m_iEntity = -1;
      goto LAB_001b4881;
    }
    fVar2 = g_VoiceChannels[3].m_TimePad - frametime;
    bVar1 = 0.0 < g_VoiceChannels[3].m_TimePad;
    g_VoiceChannels[3].m_TimePad = fVar2;
    if ((bVar1) && (fVar2 <= 0.0)) {
      VoiceSE_StartChannel(3);
      ClientDLL_VoiceStatus(g_VoiceChannels[3].m_iEntity,true);
      VoiceSE_InitMouth(g_VoiceChannels[3].m_iEntity);
    }
    iVar4 = iVar4 + 1;
    if (g_VoiceChannels[4].m_iEntity == -1) goto LAB_001b48b0;
LAB_001b4a10:
    if ((g_VoiceChannels[4].m_bStarved == false) || (g_bInTweakMode != false)) {
      fVar2 = g_VoiceChannels[4].m_TimePad - frametime;
      bVar1 = 0.0 < g_VoiceChannels[4].m_TimePad;
      g_VoiceChannels[4].m_TimePad = fVar2;
      if ((bVar1) && (fVar2 <= 0.0)) {
        VoiceSE_StartChannel(4);
        ClientDLL_VoiceStatus(g_VoiceChannels[4].m_iEntity,true);
        VoiceSE_InitMouth(g_VoiceChannels[4].m_iEntity);
      }
      goto LAB_001b48b0;
    }
    VoiceSE_EndChannel(4);
    if (-1 < g_VoiceChannels[4].m_iEntity) {
      ClientDLL_VoiceStatus(g_VoiceChannels[4].m_iEntity,false);
      VoiceSE_CloseMouth(g_VoiceChannels[4].m_iEntity);
    }
    g_VoiceChannels[4].m_iEntity = -1;
  }
  if ((iVar4 == 0) && (g_bInTweakMode == false)) {
    VoiceSE_EndOverdrive();
  }
LAB_001b48b0:
  VoiceSE_Idle(frametime);
  if (1.0 <= voice_showchannels.value) {
    this = &g_VoiceChannels[0].m_Buffer.super_CCircularBuffer;
    iVar4 = 0;
    do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
      if (*(int *)this[-1].m_chData != -1) {
        iVar3 = CCircularBuffer::GetReadAvailable(this);
        Con_Printf("Voice - chan %d, ent %d, bufsize: %d\n",iVar4,*(undefined4 *)this[-1].m_chData,
                   iVar3);
      }
      this = this + 0x453;
      iVar4 = iVar4 + 1;
    } while (this != (CCircularBuffer *)&g_pMixerControls);
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
  g_DecompressTime._4_4_ = 0;
  g_CompressTime._0_4_ = 0;
  g_GainTime._4_4_ = 0;
  g_DecompressTime._0_4_ = 0;
  g_UpsampleTime._4_4_ = 0;
  g_GainTime._0_4_ = 0;
  g_CompressTime._4_4_ = 0;
  return;
}


// Voice_Init  @ 001b2d40
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

qboolean Voice_Init(char *pCodecName,int quality)

{
  bool bVar1;
  qboolean qVar2;
  int *piVar3;
  CreateInterfaceFn p_Var4;
  int iVar5;
  IVoiceCodec *pIVar6;
  int iVar7;
  CVoiceChannel *pCVar8;
  int in_GS_OFFSET;
  char local_120 [256];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (voice_enable.value != 0.0) {
    if (g_bVoiceAtLeastPartiallyInitted) {
      Voice_Deinit();
      g_bVoiceAtLeastPartiallyInitted = true;
      bVar1 = VoiceSE_Init();
      if (bVar1) goto LAB_001b2de0;
    }
    else {
      g_bVoiceAtLeastPartiallyInitted = true;
      bVar1 = VoiceSE_Init();
      if (bVar1) {
LAB_001b2de0:
        piVar3 = (int *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
        g_bUsingSteamVoice = *piVar3 != 0;
        if ((g_bUsingSteamVoice) || (*pCodecName == '\0')) {
LAB_001b2dfe:
          g_pMixerControls = GetMixerControls();
          if ((voice_forcemicrecord.value == 0.0) || (g_pMixerControls == (IMixerControls *)0x0)) {
            qVar2 = 1;
          }
          else {
            (*g_pMixerControls->_vptr_IMixerControls[5])(g_pMixerControls);
            qVar2 = 1;
          }
          goto LAB_001b2da9;
        }
        g_pVoiceRecord = CreateVoiceRecord(g_VoiceSampleFormat.nSamplesPerSec);
        if (g_pVoiceRecord == (IVoiceRecord *)0x0) {
          Con_Printf(
                    "Unable to initialize wave input. You won\'t be able to speak to other players through a microphone.\n"
                    );
        }
        __snprintf_chk(local_120,0x100,1,0x100,"%s.so",pCodecName);
        if (g_hVoiceCodecDLL == (CSysModule *)0x0) {
          FS_GetLocalCopy(local_120);
          g_hVoiceCodecDLL = Sys_LoadModule(local_120);
          if (g_hVoiceCodecDLL != (CSysModule *)0x0) goto LAB_001b2ebb;
          Con_Printf("Unable to load voice codec DLL %s.  Voice disabled.\n",local_120);
        }
        else {
LAB_001b2ebb:
          p_Var4 = Sys_GetFactory(g_hVoiceCodecDLL);
          if (p_Var4 == (CreateInterfaceFn)0x0) {
            Con_Printf("Unable to get a factory for voice codec %s.  Voice disabled.\n",pCodecName);
          }
          else {
            g_pEncodeCodec = (*p_Var4)(pCodecName,(int *)0x0);
            if (g_pEncodeCodec == (IVoiceCodec *)0x0) {
              Con_Printf("Unable to create interface for voice codec %s.  Voice disabled.\n",
                         pCodecName);
            }
            else {
              iVar5 = (*(g_pEncodeCodec->super_IBaseInterface)._vptr_IBaseInterface[2])
                                (g_pEncodeCodec,quality);
              if ((char)iVar5 != '\0') {
                pCVar8 = g_VoiceChannels;
                iVar5 = 0;
                do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CVoiceChannel * pChannel@[???] */
                  pIVar6 = (*p_Var4)(pCodecName,(int *)0x0);
                  pCVar8->m_pVoiceCodec = pIVar6;
                  if ((pIVar6 == (IVoiceCodec *)0x0) ||
                     (iVar7 = (*(pIVar6->super_IBaseInterface)._vptr_IBaseInterface[2])
                                        (pIVar6,quality), (char)iVar7 == '\0')) {
                    Con_Printf("Unable to get voice codec (%s) interface for channel %d.  Voice disabled.\n"
                               ,pCodecName,iVar5);
                    goto joined_r0x001b3002;
                  }
                  iVar5 = iVar5 + 1;
                  pCVar8 = pCVar8 + 1;
                } while (iVar5 != 5);
                goto LAB_001b2dfe;
              }
              Con_Printf("Unable to initialize voice codec %s.  Voice disabled.\n",pCodecName);
            }
          }
        }
joined_r0x001b3002:
        if (g_bVoiceAtLeastPartiallyInitted != false) {
          Voice_Deinit();
        }
      }
    }
  }
                    /* Unresolved local var: int rate@[???]
                       Unresolved local var: char[256] dllName@[???]
                       Unresolved local var: CreateInterfaceFn createCodecFn@[???] */
  qVar2 = 0;
LAB_001b2da9:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return qVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Voice_IsRecording  @ 001b2ac0
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


// Voice_LocalPlayerTalkingAck  @ 001b2a80
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


// Voice_NotifyFreeChannel  @ 001b29b0
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


// Voice_RecordStart  @ 001b3030
qboolean Voice_RecordStart(char *pUncompressedFile,char *pDecompressedFile,char *pMicInputFile)

{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
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
    piVar2 = (int *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
    if (*piVar2 != 0) {
      puVar3 = (undefined4 *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
      (**(code **)(*(int *)*puVar3 + 0x1c))((int *)*puVar3);
      g_bVoiceRecording = 1;
      goto LAB_001b3153;
    }
  }
  if (g_pVoiceRecord == (IVoiceRecord *)0x0) {
    g_bVoiceRecording = 0;
    return 0;
  }
  uVar1 = (*g_pVoiceRecord->_vptr_IVoiceRecord[3])(g_pVoiceRecord);
  g_bVoiceRecording = uVar1 & 0xff;
  if ((char)uVar1 == '\0') {
    return g_bVoiceRecording;
  }
LAB_001b3153:
  ClientDLL_VoiceStatus(-1,true);
  return g_bVoiceRecording;
}


// Voice_RecordStop  @ 001b2ae0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Voice_RecordStop(void)

{
  int *piVar1;
  undefined4 *puVar2;
  
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
    piVar1 = (int *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
    if (*piVar1 != 0) {
      puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
      (**(code **)(*(int *)*puVar2 + 0x20))((int *)*puVar2);
      goto LAB_001b2bcd;
    }
  }
  if (g_pVoiceRecord != (IVoiceRecord *)0x0) {
    (*g_pVoiceRecord->_vptr_IVoiceRecord[4])(g_pVoiceRecord);
  }
LAB_001b2bcd:
  if (g_bVoiceRecording != 0) {
    ClientDLL_VoiceStatus(-1,false);
  }
  g_bVoiceRecording = 0;
  return 1;
}


// Voice_RegisterCvars  @ 001b28b0
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


// Voice_SetClientListening  @ 000e3fa0
qboolean Voice_SetClientListening(int iReceiver,int iSender,qboolean bListen)

{
  int iVar1;
  qboolean qVar2;
  int iVar3;
  uint uVar4;
  
                    /* Unresolved local var: uint32 * pDest@[???] */
  iVar1 = iSender + -1;
  iVar3 = iReceiver + -1;
  if (((iVar3 < 0) || (svs.maxclients <= iVar3 || iVar1 < 0)) || (svs.maxclients <= iVar1)) {
    qVar2 = false;
  }
  else {
    uVar4 = 1 << ((byte)iVar3 & 0x1f);
    if (bListen == false) {
      svs.clients[iVar1].m_VoiceStreams[iVar3 >> 5] =
           svs.clients[iVar1].m_VoiceStreams[iVar3 >> 5] & ~uVar4;
      return true;
    }
    svs.clients[iVar1].m_VoiceStreams[iVar3 >> 5] =
         svs.clients[iVar1].m_VoiceStreams[iVar3 >> 5] | uVar4;
    qVar2 = true;
  }
  return qVar2;
}


// Voice_UpdateVoiceTweakMode  @ 001b41e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Voice_UpdateVoiceTweakMode(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  int in_GS_OFFSET;
  byte bVar13;
  double dVar14;
  double local_483c;
  int local_482c;
  int local_4828;
  undefined4 local_4824;
  undefined4 local_4820;
  char local_820 [2048];
  int local_20;
  
                    /* Unresolved local var: char[2048] uchVoiceData@[???]
                       Unresolved local var: bool bFinal@[???]
                       Unresolved local var: int nDataLength@[???] */
  bVar13 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (g_bUsingSteamVoice) {
                    /* Unresolved local var: uint32 cbCompressedWritten@[???]
                       Unresolved local var: uint32 cbUncompressedWritten@[???]
                       Unresolved local var: uint32 cbCompressed@[???]
                       Unresolved local var: uint32 cbUncompressed@[???]
                       Unresolved local var: EVoiceResult result@[???] */
    local_482c = 0;
    local_4828 = 0;
    local_4820 = 0;
    local_4824 = 0;
    puVar5 = (undefined4 *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
    iVar3 = (**(code **)(*(int *)*puVar5 + 0x24))
                      ((int *)*puVar5,&local_4824,&local_4820,
                       ~-(uint)(g_pUncompressedFileData == (char *)0x0) & 0x2b11);
    iVar7 = local_482c;
    if (iVar3 == 0) {
      puVar5 = (undefined4 *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
      (**(code **)(*(int *)*puVar5 + 0x28))
                ((int *)*puVar5,1,local_820,0x800,&local_482c,g_pUncompressedFileData != (char *)0x0
                 ,g_pUncompressedFileData,0x100000 - g_nUncompressedDataBytes,&local_4828,0x2b11);
      iVar7 = local_482c;
      if (g_pUncompressedFileData != (char *)0x0) {
        g_nUncompressedDataBytes = g_nUncompressedDataBytes + local_4828;
      }
    }
  }
  else if ((g_pVoiceRecord == (IVoiceRecord *)0x0) || (g_pEncodeCodec == (IVoiceCodec *)0x0)) {
    iVar7 = 0;
  }
  else {
                    /* Unresolved local var: short[8192] tempData@[???]
                       Unresolved local var: int gotten@[???]
                       Unresolved local var: CVoiceTimer timer@[???]
                       Unresolved local var: int nCompressedBytes@[???] */
    pcVar9 = (char *)&local_4820;
    iVar3 = (*g_pVoiceRecord->_vptr_IVoiceRecord[6])(g_pVoiceRecord,pcVar9,0x400);
    if (g_pMicInputFileData != (char *)0x0) {
                    /* Unresolved local var: double curtime@[???]
                       Unresolved local var: int nShouldGet@[???] */
      dVar14 = Sys_FloatTime();
      iVar3 = (g_nMicInputFileBytes - g_CurMicInputFileByte) / 2;
      iVar7 = (int)((double)g_VoiceSampleFormat.nSamplesPerSec * (dVar14 - g_MicStartTime));
      if (iVar7 <= iVar3) {
        iVar3 = iVar7;
      }
      if (iVar3 < 0x2000) {
        iVar7 = iVar3 * 2;
      }
      else {
        iVar7 = 0x4000;
        iVar3 = 0x2000;
      }
      iVar8 = g_CurMicInputFileByte + iVar7;
      __memcpy_chk(pcVar9,g_pMicInputFileData + g_CurMicInputFileByte,iVar7,0x4000);
      g_MicStartTime = dVar14;
      g_CurMicInputFileByte = iVar8;
    }
    if (voice_profile.value != 0.0) {
      local_483c = Sys_FloatTime();
    }
    iVar7 = (*(g_pEncodeCodec->super_IBaseInterface)._vptr_IBaseInterface[4])
                      (g_pEncodeCodec,pcVar9,iVar3,local_820,0x800,0);
    if (voice_profile.value != 0.0) {
      dVar14 = Sys_FloatTime();
      g_CompressTime = (dVar14 - local_483c) + g_CompressTime;
    }
    if (g_pUncompressedFileData != (char *)0x0) {
      uVar4 = 0x100000U - g_nUncompressedDataBytes;
      if (iVar3 * 2 < (int)(0x100000U - g_nUncompressedDataBytes)) {
        uVar4 = iVar3 * 2;
      }
                    /* Unresolved local var: int nToWrite@[???] */
      pcVar10 = g_pUncompressedFileData + g_nUncompressedDataBytes;
      uVar6 = uVar4;
      if (7 < uVar4) {
        pcVar12 = pcVar10;
        if (((uint)pcVar10 & 1) != 0) {
          pcVar12 = pcVar10 + 1;
          pcVar9 = (char *)((int)&local_4820 + 1);
          uVar6 = uVar4 - 1;
          *pcVar10 = (char)local_4820;
        }
        pcVar11 = pcVar12;
        if (((uint)pcVar12 & 2) != 0) {
          uVar1 = *(undefined2 *)pcVar9;
          pcVar11 = pcVar12 + 2;
          pcVar9 = pcVar9 + 2;
          uVar6 = uVar6 - 2;
          *(undefined2 *)pcVar12 = uVar1;
        }
        pcVar10 = pcVar11;
        if (((uint)pcVar11 & 4) != 0) {
          uVar2 = *(undefined4 *)pcVar9;
          pcVar10 = pcVar11 + 4;
          pcVar9 = pcVar9 + 4;
          uVar6 = uVar6 - 4;
          *(undefined4 *)pcVar11 = uVar2;
        }
      }
      for (; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar10 = *pcVar9;
        pcVar9 = pcVar9 + (uint)bVar13 * -2 + 1;
        pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
      }
      g_nUncompressedDataBytes = g_nUncompressedDataBytes + uVar4;
    }
  }
  Voice_AddIncomingData(-100,local_820,iVar7,0);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Voice_UpdateVoiceTweakMode  @ 001b4580
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Voice_UpdateVoiceTweakMode(void)

{
                    /* Unresolved local var: char[2048] uchVoiceData@[???]
                       Unresolved local var: bool bFinal@[???]
                       Unresolved local var: int nDataLength@[???] */
  if (!g_bInTweakMode) {
    return;
  }
  Voice_UpdateVoiceTweakMode();
  return;
}


