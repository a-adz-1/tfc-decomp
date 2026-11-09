// VoiceSE_CloseMouth  @ 00209a80
void VoiceSE_CloseMouth(int entnum)

{
  if ((-1 < entnum) && (entnum < cl.max_edicts)) {
    cl_entities[entnum].mouth.mouthopen = '\0';
  }
  return;
}


// VoiceSE_EndChannel  @ 002099b0
void VoiceSE_EndChannel(int iChannel)

{
  S_StopSound(cl.viewentity,iChannel + 7);
  return;
}


// VoiceSE_EndOverdrive  @ 00209a60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VoiceSE_EndOverdrive(void)

{
  g_bVoiceOverdriveOn = false;
  return;
}


// VoiceSE_GetSFXCache  @ 002099d0
sfxcache_t * VoiceSE_GetSFXCache(sfx_t *pSFX)

{
  VoiceSE_SFX *pVVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: VoiceSE_SFX * pChannel@[???] */
  if ((VoiceSE_SFX *)pSFX == g_VoiceSE_SFX) {
    pVVar1 = g_VoiceSE_SFX;
  }
  else if ((VoiceSE_SFX *)pSFX == g_VoiceSE_SFX + 1) {
    pVVar1 = (VoiceSE_SFX *)0x8687c4;
  }
  else if ((VoiceSE_SFX *)pSFX == g_VoiceSE_SFX + 2) {
    pVVar1 = (VoiceSE_SFX *)0x868828;
  }
  else if ((VoiceSE_SFX *)pSFX == g_VoiceSE_SFX + 3) {
    pVVar1 = (VoiceSE_SFX *)0x86888c;
  }
  else {
    if ((VoiceSE_SFX *)pSFX != g_VoiceSE_SFX + 4) {
      return (sfxcache_t *)0x0;
    }
    pVVar1 = (VoiceSE_SFX *)0x8688f0;
  }
  return &pVVar1->m_SFXCache;
}


// VoiceSE_GetSoundDataCallback  @ 00209560
int VoiceSE_GetSoundDataCallback
              (sfxcache_s *pCache,char *pCopyBuf,int maxOutDataSize,int samplePos,int sampleCount)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  VoiceSE_SFX *local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: VoiceSE_SFX * pChannel@[???] */
  if (pCache == &g_VoiceSE_SFX[0].m_SFXCache) {
    iVar3 = 0;
    local_20 = g_VoiceSE_SFX;
  }
  else if (pCache == &g_VoiceSE_SFX[1].m_SFXCache) {
    iVar3 = 1;
    local_20 = (VoiceSE_SFX *)0x8687c4;
  }
  else if (pCache == &g_VoiceSE_SFX[2].m_SFXCache) {
    iVar3 = 2;
    local_20 = (VoiceSE_SFX *)0x868828;
  }
  else if (pCache == &g_VoiceSE_SFX[3].m_SFXCache) {
    iVar3 = 3;
    local_20 = (VoiceSE_SFX *)0x86888c;
  }
  else {
    if (pCache != &g_VoiceSE_SFX[4].m_SFXCache) {
      return 0;
    }
    iVar3 = 4;
    local_20 = (VoiceSE_SFX *)0x8688f0;
  }
                    /* Unresolved local var: int count@[???]
                       Unresolved local var: short * pSamples@[???]
                       Unresolved local var: int count2x@[???] */
  iVar2 = Voice_GetOutputData(iVar3,pCopyBuf,maxOutDataSize,samplePos,sampleCount >> 1);
  iVar3 = iVar2 + -1;
  iVar1 = iVar2 * 2 + -1;
  if (0 < iVar3) {
    pcVar4 = pCopyBuf + iVar1 * 2;
    do {
      *(undefined2 *)pcVar4 = *(undefined2 *)(pCopyBuf + iVar3 * 2);
      *(short *)(pcVar4 + -2) =
           (short)((int)*(short *)(pCopyBuf + iVar3 * 2 + -2) +
                   (int)*(short *)(pCopyBuf + iVar3 * 2) >> 1);
      pcVar4 = pcVar4 + -4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if (1 < iVar2 * 2) {
    *(short *)(pCopyBuf + 2) = *(short *)pCopyBuf;
    *(short *)pCopyBuf = (short)((int)*(short *)pCopyBuf + (int)local_20->m_PrevUpsampleValue >> 1);
  }
  local_20->m_PrevUpsampleValue = *(short *)(pCopyBuf + iVar1 * 2);
  return iVar2 * 2;
}


// VoiceSE_Idle  @ 00209800
void VoiceSE_Idle(float frametime)

{
  double dVar1;
  
                    /* Unresolved local var: float percent@[???] */
  if (g_bVoiceOverdriveOn) {
    if (NAN(voice_overdrivefadetime.value) || NAN(g_VoiceOverdriveDuration)) {
      g_VoiceOverdriveDuration = g_VoiceOverdriveDuration + frametime;
      if (voice_overdrivefadetime.value <= g_VoiceOverdriveDuration) {
        g_VoiceOverdriveDuration = voice_overdrivefadetime.value;
      }
    }
    else {
      if (voice_overdrivefadetime.value == g_VoiceOverdriveDuration) {
        return;
      }
      g_VoiceOverdriveDuration = g_VoiceOverdriveDuration + frametime;
      if (voice_overdrivefadetime.value <= g_VoiceOverdriveDuration) {
        g_VoiceOverdriveDuration = voice_overdrivefadetime.value;
      }
    }
  }
  else {
    if (g_VoiceOverdriveDuration == 0.0) {
      return;
    }
    g_VoiceOverdriveDuration = g_VoiceOverdriveDuration - frametime;
    if (g_VoiceOverdriveDuration <= 0.0) {
      g_VoiceOverdriveDuration = 0.0;
    }
  }
  dVar1 = cos((double)((g_VoiceOverdriveDuration / voice_overdrivefadetime.value) * 3.1415927));
  g_SND_VoiceOverdrive = (0.5 - (float)dVar1 * 0.5) * (voice_overdrive.value - 1.0) + 1.0;
  return;
}


// VoiceSE_Init  @ 002096f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

bool VoiceSE_Init(void)

{
  bool bVar1;
  
  bVar1 = sound_started != 0;
  if (bVar1) {
    Q_memset(g_VoiceSE_SFX,0,500);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: VoiceSE_SFX * pChannel@[???] */
    g_VoiceSE_SFX[0].m_SFXCache.length = 0x40000000;
    g_VoiceSE_SFX[0].m_SFXCache.loopstart = (int)VoiceSE_GetSoundDataCallback;
    g_VoiceSE_SFX[0].m_SFXCache.speed = 0x5622;
    g_VoiceSE_SFX[0].m_SFXCache.width = 2;
    g_VoiceSE_SFX[1].m_SFXCache.speed = 0x5622;
    g_VoiceSE_SFX[1].m_SFXCache.width = 2;
    g_VoiceSE_SFX[2].m_SFXCache.length = 0x40000000;
    g_VoiceSE_SFX[2].m_SFXCache.loopstart = (int)VoiceSE_GetSoundDataCallback;
    g_VoiceSE_SFX[2].m_SFXCache.speed = 0x5622;
    g_VoiceSE_SFX[2].m_SFXCache.width = 2;
    g_VoiceSE_SFX[3].m_SFXCache.speed = 0x5622;
    g_VoiceSE_SFX[3].m_SFXCache.width = 2;
    g_VoiceSE_SFX[4].m_SFXCache.length = 0x40000000;
    g_VoiceSE_SFX[4].m_SFXCache.loopstart = (int)VoiceSE_GetSoundDataCallback;
    g_VoiceSE_SFX[1].m_SFXCache.length = 0x40000000;
    g_VoiceSE_SFX[1].m_SFXCache.loopstart = (int)VoiceSE_GetSoundDataCallback;
    g_VoiceSE_SFX[4].m_SFXCache.speed = 0x5622;
    g_VoiceSE_SFX[4].m_SFXCache.width = 2;
    g_VoiceSE_SFX[3].m_SFXCache.length = 0x40000000;
    g_VoiceSE_SFX[3].m_SFXCache.loopstart = (int)VoiceSE_GetSoundDataCallback;
  }
  return bVar1;
}


// VoiceSE_InitMouth  @ 00209a70
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


// VoiceSE_MoveMouth  @ 00209a90
void VoiceSE_MoveMouth(int entnum,short *pSamples,int nSamples)

{
  cl_entity_t *pcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  pcVar1 = cl_entities;
  if ((-1 < entnum) && (entnum < cl.max_edicts)) {
    uVar3 = (uint)cl_entities[entnum].mouth.sndcount;
    if ((nSamples < 1) || (9 < uVar3)) {
      iVar5 = 0;
    }
    else {
      iVar5 = 0;
      iVar4 = 0;
      do {
        uVar3 = uVar3 + 1;
        uVar2 = (uint)*(char *)((int)pSamples + iVar4 * 2 + 1);
        iVar4 = iVar4 + 0x50 + (uVar2 & 0x1f);
        iVar5 = iVar5 + (((int)uVar2 >> 0x1f ^ uVar2) - ((int)uVar2 >> 0x1f));
        if (nSamples <= iVar4) break;
      } while ((int)uVar3 < 10);
    }
    iVar5 = iVar5 + cl_entities[entnum].mouth.sndavg;
    cl_entities[entnum].mouth.sndavg = iVar5;
    pcVar1[entnum].mouth.sndcount = (byte)uVar3;
    if (9 < (byte)uVar3) {
      pcVar1[entnum].mouth.mouthopen = (byte)(iVar5 / 10);
      pcVar1[entnum].mouth.sndavg = 0;
      pcVar1[entnum].mouth.sndcount = '\0';
    }
  }
  return;
}


// VoiceSE_NotifyFreeChannel  @ 00209aa0
void VoiceSE_NotifyFreeChannel(int iChannel)

{
  Voice_NotifyFreeChannel(iChannel + -7);
  return;
}


// VoiceSE_RegisterCvars  @ 002096d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VoiceSE_RegisterCvars(void)

{
  Cvar_RegisterVariable(&voice_overdrive);
  Cvar_RegisterVariable(&voice_overdrivefadetime);
  return;
}


// VoiceSE_StartChannel  @ 00209900
void VoiceSE_StartChannel(int iChannel)

{
  VoiceSE_SFX *sfx;
  
                    /* Unresolved local var: VoiceSE_SFX * pChannel@[???]
                       Unresolved local var: sfx_t * sfx@[???] */
  if ((uint)iChannel < 5) {
    g_VoiceSE_SFX[iChannel].m_PrevUpsampleValue = 0;
    sfx = g_VoiceSE_SFX + iChannel;
    Q_memset(sfx,0,0x48);
    Q_strcpy((char *)sfx,"?VoiceData");
    S_StartDynamicSound(cl.viewentity,iChannel + 7,&sfx->m_SFX,vec3_origin,1.0,1.0,0,100);
  }
  return;
}


// VoiceSE_StartOverdrive  @ 00209a50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VoiceSE_StartOverdrive(void)

{
  g_bVoiceOverdriveOn = true;
  return;
}


// VoiceSE_Term  @ 002097f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VoiceSE_Term(void)

{
  return;
}


