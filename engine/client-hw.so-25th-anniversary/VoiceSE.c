// VoiceSE_CloseMouth  @ 001b9d00
void VoiceSE_CloseMouth(int entnum)

{
  if ((-1 < entnum) && (entnum < cl.max_edicts)) {
    cl_entities[entnum].mouth.mouthopen = '\0';
  }
  return;
}


// VoiceSE_EndChannel  @ 001b9c30
void VoiceSE_EndChannel(int iChannel)

{
  S_StopSound(cl.viewentity,iChannel + 7);
  return;
}


// VoiceSE_EndOverdrive  @ 001b9ce0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VoiceSE_EndOverdrive(void)

{
  g_bVoiceOverdriveOn = false;
  return;
}


// VoiceSE_GetSFXCache  @ 001b9c50
sfxcache_t * VoiceSE_GetSFXCache(sfx_t *pSFX)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: VoiceSE_SFX * pChannel@[???] */
  if ((VoiceSE_SFX *)pSFX == g_VoiceSE_SFX) {
    iVar1 = 0;
  }
  else if ((VoiceSE_SFX *)pSFX == g_VoiceSE_SFX + 1) {
    iVar1 = 1;
  }
  else if ((VoiceSE_SFX *)pSFX == g_VoiceSE_SFX + 2) {
    iVar1 = 2;
  }
  else if ((VoiceSE_SFX *)pSFX == g_VoiceSE_SFX + 3) {
    iVar1 = 3;
  }
  else {
    if ((VoiceSE_SFX *)pSFX != g_VoiceSE_SFX + 4) {
      return (sfxcache_t *)0x0;
    }
    iVar1 = 4;
  }
  return &g_VoiceSE_SFX[iVar1].m_SFXCache;
}


// VoiceSE_GetSoundDataCallback  @ 001b9800
int VoiceSE_GetSoundDataCallback
              (sfxcache_s *pCache,char *pCopyBuf,int maxOutDataSize,int samplePos,int sampleCount)

{
  int iVar1;
  short *psVar2;
  short *psVar3;
  char *pcVar4;
  int iChannel;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
                    /* Unresolved local var: VoiceSE_SFX * pChannel@[???] */
  if (pCache == &g_VoiceSE_SFX[0].m_SFXCache) {
    iChannel = 0;
  }
  else if (pCache == &g_VoiceSE_SFX[1].m_SFXCache) {
    iChannel = 1;
  }
  else if (pCache == &g_VoiceSE_SFX[2].m_SFXCache) {
    iChannel = 2;
  }
  else if (pCache == &g_VoiceSE_SFX[3].m_SFXCache) {
    iChannel = 3;
  }
  else {
    iChannel = 4;
    if (pCache != &g_VoiceSE_SFX[4].m_SFXCache) {
      return 0;
    }
  }
                    /* Unresolved local var: int count@[???]
                       Unresolved local var: short * pSamples@[???]
                       Unresolved local var: int count2x@[???] */
  iVar1 = Voice_GetOutputData(iChannel,pCopyBuf,maxOutDataSize,samplePos,sampleCount >> 1);
  if (1 < iVar1) {
    psVar2 = (short *)(pCopyBuf + iVar1 * 2);
    pcVar4 = pCopyBuf + iVar1 * 4;
    do {
      psVar3 = psVar2 + -1;
      *(short *)(pcVar4 + -2) = psVar2[-1];
      *(short *)(pcVar4 + -4) = (short)((int)psVar2[-2] + (int)*psVar3 >> 1);
      psVar2 = psVar3;
      pcVar4 = pcVar4 + -4;
    } while (psVar3 != (short *)(pCopyBuf + 2));
  }
  if (1 < iVar1 * 2) {
    *(short *)(pCopyBuf + 2) = *(short *)pCopyBuf;
    *(short *)pCopyBuf =
         (short)((int)*(short *)pCopyBuf + (int)g_VoiceSE_SFX[iChannel].m_PrevUpsampleValue >> 1);
  }
  g_VoiceSE_SFX[iChannel].m_PrevUpsampleValue = *(short *)(pCopyBuf + iVar1 * 4 + -2);
  return iVar1 * 2;
}


// VoiceSE_Idle  @ 001b9ac0
void VoiceSE_Idle(float frametime)

{
  float fVar1;
  double dVar2;
  
                    /* Unresolved local var: float percent@[???] */
  if (g_bVoiceOverdriveOn) {
    if (voice_overdrivefadetime.value == g_VoiceOverdriveDuration) {
      return;
    }
    g_VoiceOverdriveDuration = g_VoiceOverdriveDuration + frametime;
    if (voice_overdrivefadetime.value < g_VoiceOverdriveDuration) {
      g_VoiceOverdriveDuration = voice_overdrivefadetime.value;
    }
  }
  else {
    if (g_VoiceOverdriveDuration == 0.0) {
      return;
    }
    fVar1 = g_VoiceOverdriveDuration - frametime;
    g_VoiceOverdriveDuration = 0.0;
    if (0.0 <= fVar1) {
      g_VoiceOverdriveDuration = fVar1;
    }
  }
  dVar2 = cos((double)((g_VoiceOverdriveDuration / voice_overdrivefadetime.value) * 3.1415927));
  g_SND_VoiceOverdrive = (voice_overdrive.value - 1.0) * (0.5 - (float)dVar2 * 0.5) + 1.0;
  return;
}


// VoiceSE_Init  @ 001b99a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

bool VoiceSE_Init(void)

{
  if (sound_started == 0) {
    return false;
  }
  Q_memset(g_VoiceSE_SFX,0,500);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: VoiceSE_SFX * pChannel@[???] */
  g_VoiceSE_SFX[0].m_SFXCache.loopstart = (int)VoiceSE_GetSoundDataCallback;
  g_VoiceSE_SFX[0].m_SFXCache.speed = 0x5622;
  g_VoiceSE_SFX[0].m_SFXCache.width = 2;
  g_VoiceSE_SFX[1].m_SFXCache.length = 0x40000000;
  g_VoiceSE_SFX[1].m_SFXCache.loopstart = (int)VoiceSE_GetSoundDataCallback;
  g_VoiceSE_SFX[1].m_SFXCache.speed = 0x5622;
  g_VoiceSE_SFX[2].m_SFXCache.loopstart = (int)VoiceSE_GetSoundDataCallback;
  g_VoiceSE_SFX[2].m_SFXCache.speed = 0x5622;
  g_VoiceSE_SFX[2].m_SFXCache.width = 2;
  g_VoiceSE_SFX[3].m_SFXCache.length = 0x40000000;
  g_VoiceSE_SFX[3].m_SFXCache.loopstart = (int)VoiceSE_GetSoundDataCallback;
  g_VoiceSE_SFX[3].m_SFXCache.speed = 0x5622;
  g_VoiceSE_SFX[0].m_SFXCache.length = 0x40000000;
  g_VoiceSE_SFX[4].m_SFXCache.loopstart = (int)VoiceSE_GetSoundDataCallback;
  g_VoiceSE_SFX[1].m_SFXCache.width = 2;
  g_VoiceSE_SFX[2].m_SFXCache.length = 0x40000000;
  g_VoiceSE_SFX[4].m_SFXCache.speed = 0x5622;
  g_VoiceSE_SFX[4].m_SFXCache.width = 2;
  g_VoiceSE_SFX[3].m_SFXCache.width = 2;
  g_VoiceSE_SFX[4].m_SFXCache.length = 0x40000000;
  return true;
}


// VoiceSE_InitMouth  @ 001b9cf0
void VoiceSE_InitMouth(int entnum)

{
  cl_entity_t *pcVar1;
  
  pcVar1 = cl_entities;
  if ((-1 < entnum) && (entnum < cl.max_edicts)) {
    cl_entities[entnum].mouth.mouthopen = '\0';
    pcVar1[entnum].mouth.sndavg = 0;
    pcVar1[entnum].mouth.sndcount = '\0';
  }
  return;
}


// VoiceSE_MoveMouth  @ 001b9d10
void VoiceSE_MoveMouth(int entnum,short *pSamples,int nSamples)

{
  cl_entity_t *pcVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  pcVar1 = cl_entities;
  if ((-1 < entnum) && (entnum < cl.max_edicts)) {
    iVar5 = 0;
    uVar4 = (uint)cl_entities[entnum].mouth.sndcount;
    if ((0 < nSamples) && (uVar4 < 10)) {
      iVar3 = 0;
      do {
        uVar2 = (uint)*(char *)((int)pSamples + iVar3 * 2 + 1);
        uVar4 = uVar4 + 1;
        iVar3 = iVar3 + 0x50 + (uVar2 & 0x1f);
        iVar5 = iVar5 + (((int)uVar2 >> 0x1f ^ uVar2) - ((int)uVar2 >> 0x1f));
        if (nSamples <= iVar3) break;
      } while ((int)uVar4 < 10);
    }
    iVar3 = cl_entities[entnum].mouth.sndavg;
    cl_entities[entnum].mouth.sndcount = (byte)uVar4;
    iVar5 = iVar5 + iVar3;
    pcVar1[entnum].mouth.sndavg = iVar5;
    if (9 < (int)uVar4) {
      pcVar1[entnum].mouth.sndcount = '\0';
      pcVar1[entnum].mouth.mouthopen = (byte)(iVar5 / 10);
      pcVar1[entnum].mouth.sndavg = 0;
    }
  }
  return;
}


// VoiceSE_NotifyFreeChannel  @ 001b9d20
void VoiceSE_NotifyFreeChannel(int iChannel)

{
  Voice_NotifyFreeChannel(iChannel + -7);
  return;
}


// VoiceSE_RegisterCvars  @ 001b9980
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VoiceSE_RegisterCvars(void)

{
  Cvar_RegisterVariable(&voice_overdrive);
  Cvar_RegisterVariable(&voice_overdrivefadetime);
  return;
}


// VoiceSE_StartChannel  @ 001b9b90
void VoiceSE_StartChannel(int iChannel)

{
  VoiceSE_SFX *sfx;
  
                    /* Unresolved local var: VoiceSE_SFX * pChannel@[???]
                       Unresolved local var: sfx_t * sfx@[???] */
  if ((uint)iChannel < 5) {
    sfx = g_VoiceSE_SFX + iChannel;
    g_VoiceSE_SFX[iChannel].m_PrevUpsampleValue = 0;
    Q_memset(sfx,0,0x48);
    Q_strcpy((char *)sfx,"?VoiceData");
    S_StartDynamicSound(cl.viewentity,iChannel + 7,&sfx->m_SFX,vec3_origin,1.0,1.0,0,100);
  }
  return;
}


// VoiceSE_StartOverdrive  @ 001b9cd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VoiceSE_StartOverdrive(void)

{
  g_bVoiceOverdriveOn = true;
  return;
}


// VoiceSE_Term  @ 001b9ab0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VoiceSE_Term(void)

{
  return;
}


