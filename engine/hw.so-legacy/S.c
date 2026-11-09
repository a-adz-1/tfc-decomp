// S_AlterChannel  @ 001f5720
int __regparm3 S_AlterChannel(int entnum,int entchannel,sfx_t *sfx,int vol,int pitch,int flags)

{
  int *piVar1;
  int iVar2;
  
                    /* Unresolved local var: int ch_idx@[???] */
  if (sfx->name[0] == '!') {
    if (total_channels < 5) {
      return 0;
    }
    piVar1 = &channels[4].entnum;
    iVar2 = 4;
    do {
      if ((((entnum == *piVar1) && (entchannel == piVar1[1])) &&
          (((channel_t *)(piVar1 + -6))->sfx != (sfx_t *)0x0)) && (-1 < piVar1[7])) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0x10;
    } while (iVar2 != total_channels);
  }
  else if (4 < total_channels) {
                    /* Unresolved local var: int ch_idx@[???] */
    piVar1 = &channels[4].entnum;
    iVar2 = 4;
    do {
      if (((entnum == *piVar1) && (entchannel == piVar1[1])) &&
         (sfx == ((channel_t *)(piVar1 + -6))->sfx)) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0x10;
    } while (iVar2 != total_channels);
  }
  return 0;
}


// S_AlterChannel  @ 001f81a0
int S_AlterChannel(int entnum,int entchannel,sfx_t *sfx,int vol,int pitch,int flags)

{
  int *piVar1;
  int iVar2;
  
                    /* Unresolved local var: int ch_idx@[???] */
                    /* Unresolved local var: int ch_idx@[???] */
  if (sfx->name[0] == '!') {
    if (total_channels < 5) {
      return 0;
    }
    piVar1 = &channels[4].entnum;
    iVar2 = 4;
    do {
      if ((((entnum == *piVar1) && (entchannel == piVar1[1])) &&
          (((channel_t *)(piVar1 + -6))->sfx != (sfx_t *)0x0)) && (-1 < piVar1[7]))
      goto LAB_001f81f6;
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0x10;
    } while (iVar2 != total_channels);
  }
  else if (4 < total_channels) {
    piVar1 = &channels[4].entnum;
    iVar2 = 4;
    do {
      if (((*piVar1 == entnum) && (piVar1[1] == entchannel)) &&
         (((channel_t *)(piVar1 + -6))->sfx == sfx)) {
LAB_001f81f6:
        if ((flags & 0x80U) != 0) {
          channels[iVar2].pitch = pitch;
        }
        if ((flags & 0x40U) != 0) {
          channels[iVar2].master_vol = vol;
        }
        if ((flags & 0x20U) != 0) {
          S_FreeChannel(channels + iVar2);
        }
        return 1;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0x10;
    } while (iVar2 != total_channels);
  }
  return 0;
}


// S_AmbientOff  @ 001f58a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_AmbientOff(void)

{
  snd_ambient = false;
  return;
}


// S_AmbientOn  @ 001f58b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_AmbientOn(void)

{
  snd_ambient = true;
  return;
}


// S_BeginPrecaching  @ 001f97e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_BeginPrecaching(void)

{
  cl.fPrecaching = 1;
  return;
}


// S_BlockSound  @ 00218170
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_BlockSound(void)

{
  snd_blocked = snd_blocked + 1;
  if (snd_blocked != 1) {
    return;
  }
  SDL_PauseAudioDevice(m_devId,1);
  return;
}


// S_CheckWavEnd  @ 001ff8b0
qboolean S_CheckWavEnd(channel_t *ch,sfxcache_t **psc,int ltime,int ichan)

{
  sfx_t *psVar1;
  qboolean qVar2;
  int iVar3;
  sfxcache_t *psVar4;
  int iVar5;
  
                    /* Unresolved local var: sfxcache_t * sc@[???] */
  qVar2 = false;
  psVar4 = *psc;
  if (psVar4->length != 0x40000000) {
    iVar3 = psVar4->loopstart;
    if (iVar3 < 0) {
      if (ch->entchannel == 5) {
        if (wavstreams[ichan].csamplesplayed < wavstreams[ichan].info.samples) {
          Wavstream_GetNextChunk(ch,ch->sfx);
          ch->pos = 0;
          ch->end = ltime + psVar4->length;
          return false;
        }
      }
      else {
        iVar3 = ch->isentence;
        if (-1 < iVar3) {
                    /* Unresolved local var: sfx_t * sfx@[???] */
          iVar5 = ch->iword;
          psVar1 = rgrgvoxword[iVar3][iVar5].sfx;
          if ((psVar1 != (sfx_t *)0x0) && (rgrgvoxword[iVar3][iVar5].fKeepCached == 0)) {
            Cache_Free(&psVar1->cache);
            iVar3 = ch->isentence;
            iVar5 = ch->iword;
          }
          psVar1 = *(sfx_t **)(iVar3 * 0x480 + 0x1365220 + (iVar5 * 9 + 9) * 4);
          ch->sfx = psVar1;
          if (psVar1 != (sfx_t *)0x0) {
            psVar4 = S_LoadSound(psVar1,ch);
            *psc = psVar4;
            if (psVar4 != (sfxcache_t *)0x0) {
              ch->pos = 0;
              iVar3 = psVar4->length;
              ch->iword = ch->iword + 1;
              ch->end = ltime + iVar3;
              VOX_TrimStartEndTimes(ch,psVar4);
              return false;
            }
          }
        }
      }
      S_FreeChannel(ch);
      qVar2 = true;
    }
    else {
      ch->pos = iVar3;
      ch->end = (ltime + psVar4->length) - iVar3;
      if (-1 < ch->isentence) {
        *(undefined4 *)(ch->isentence * 0x480 + 0x1365218 + ch->iword * 0x24) = 0;
      }
    }
  }
  return qVar2;
}


// S_ClearBuffer  @ 001f8c80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_ClearBuffer(void)

{
  int fill;
  int iVar1;
  
                    /* Unresolved local var: int clear@[???] */
  if ((sound_started != 0) && (shm != (dma_t *)0x0)) {
    fill = 0x80;
    if (shm->samplebits != 8) {
      fill = 0;
    }
    iVar1 = shm->samples * shm->samplebits;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 7;
    }
    Q_memset(shm->buffer,fill,iVar1 >> 3);
  }
  return;
}


// S_ClearPrecache  @ 001f97d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_ClearPrecache(void)

{
  return;
}


// S_EndPrecaching  @ 001f97f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_EndPrecaching(void)

{
  cl.fPrecaching = 0;
  return;
}


// S_ExtraUpdate  @ 001f9490
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_ExtraUpdate(void)

{
  int iVar1;
  int unaff_EBX;
  uint unaff_ESI;
  uint local_1c;
  
  iVar1 = VGuiWrap2_IsGameUIVisible();
  if (iVar1 == 0) {
    SDL_PumpEvents();
    ClientDLL_IN_Accumulate();
  }
                    /* Unresolved local var: uint endtime@[???]
                       Unresolved local var: int samps@[???] */
  if (((snd_noextraupdate.value == 0.0) && (sound_started != 0)) && (snd_blocked < 1)) {
    GetSoundtime();
    if (shm != (dma_t *)0x0) {
      local_1c = (uint)(longlong)
                       ROUND((float)shm->dmaspeed * _snd_mixahead.value + (float)soundtime);
      unaff_EBX = shm->samples >> ((char)shm->channels - 1U & 0x1f);
      unaff_ESI = local_1c;
    }
    if (unaff_EBX < (int)(unaff_ESI - soundtime)) {
      unaff_ESI = soundtime + unaff_EBX;
    }
    S_PaintChannels(unaff_ESI >> 1);
    SNDDMA_Submit();
    return;
  }
  return;
}


// S_FindName  @ 001f55c0
sfx_t * __regparm3 S_FindName(char *name,int *pfInCache)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  sfx_t *dest;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: sfx_t * sfx@[???] */
  if (name == (char *)0x0) {
    Sys_Error("S_FindName: NULL\n");
  }
  iVar1 = Q_strlen(name);
  if (0x3f < iVar1) {
    Sys_Error("Sound name too long: %s",name);
  }
  if (num_sfx < 1) {
    iVar1 = 0;
  }
  else {
    iVar3 = 0;
    dest = (sfx_t *)0x0;
    iVar1 = 0;
    do {
      while( true ) {
        iVar4 = iVar1;
        iVar1 = Q_strcasecmp(known_sfx->name + iVar3,name);
        if (iVar1 == 0) {
          dest = (sfx_t *)(known_sfx->name + iVar3);
          if (dest->servercount < 1) {
            return dest;
          }
          goto LAB_001f569f;
        }
        if (dest == (sfx_t *)0x0) break;
LAB_001f5600:
        iVar3 = iVar3 + 0x48;
        iVar1 = iVar4 + 1;
        if (num_sfx <= iVar4 + 1) goto LAB_001f5650;
      }
      iVar1 = ((sfx_t *)(known_sfx->name + iVar3))->servercount;
      if (iVar1 < 1) goto LAB_001f5600;
      if (iVar1 != cl.servercount) {
        dest = (sfx_t *)(known_sfx->name + iVar3);
      }
      iVar3 = iVar3 + 0x48;
      iVar1 = iVar4 + 1;
    } while (iVar4 + 1 < num_sfx);
LAB_001f5650:
    if (dest != (sfx_t *)0x0) {
      pvVar2 = Cache_Check(&dest->cache);
      if (pvVar2 != (void *)0x0) {
        Cache_Free(&dest->cache);
      }
      goto LAB_001f566b;
    }
    iVar1 = (iVar4 + 1) * 0x48;
    if (num_sfx == 0x400) {
      Sys_Error("S_FindName: out of sfx_t");
    }
  }
  num_sfx = num_sfx + 1;
  dest = (sfx_t *)(known_sfx->name + iVar1);
LAB_001f566b:
  Q_strncpy(dest->name,name,0x3f);
  dest->name[0x3f] = '\0';
LAB_001f569f:
  dest->servercount = cl.servercount;
  return dest;
}


// S_FindName  @ 001f5d90
sfx_t * S_FindName(char *name,int *pfInCache)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  sfx_t *dest;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: sfx_t * sfx@[???] */
  if (name == (char *)0x0) {
    Sys_Error("S_FindName: NULL\n");
  }
  iVar1 = Q_strlen(name);
  if (0x3f < iVar1) {
    Sys_Error("Sound name too long: %s",name);
  }
  if (num_sfx < 1) {
    iVar1 = 0;
  }
  else {
    iVar3 = 0;
    dest = (sfx_t *)0x0;
    iVar1 = 0;
    do {
      while( true ) {
        iVar4 = iVar1;
        iVar1 = Q_strcasecmp(known_sfx->name + iVar3,name);
        if (iVar1 == 0) {
          if (pfInCache != (int *)0x0) {
            pvVar2 = Cache_Check((cache_user_t *)(known_sfx->name + iVar3 + 0x40));
            *pfInCache = (uint)(pvVar2 != (void *)0x0);
          }
          dest = (sfx_t *)(known_sfx->name + iVar3);
          if (dest->servercount < 1) {
            return dest;
          }
          goto LAB_001f5eb0;
        }
        if (dest == (sfx_t *)0x0) break;
LAB_001f5dd8:
        iVar3 = iVar3 + 0x48;
        iVar1 = iVar4 + 1;
        if (num_sfx <= iVar4 + 1) goto LAB_001f5e30;
      }
      iVar1 = ((sfx_t *)(known_sfx->name + iVar3))->servercount;
      if (iVar1 < 1) goto LAB_001f5dd8;
      if (iVar1 != cl.servercount) {
        dest = (sfx_t *)(known_sfx->name + iVar3);
      }
      iVar3 = iVar3 + 0x48;
      iVar1 = iVar4 + 1;
    } while (iVar4 + 1 < num_sfx);
LAB_001f5e30:
    if (dest != (sfx_t *)0x0) {
      pvVar2 = Cache_Check(&dest->cache);
      if (pvVar2 != (void *)0x0) {
        Cache_Free(&dest->cache);
      }
      goto LAB_001f5e4f;
    }
    iVar1 = (iVar4 + 1) * 0x48;
    if (num_sfx == 0x400) {
      Sys_Error("S_FindName: out of sfx_t");
    }
  }
  num_sfx = num_sfx + 1;
  dest = (sfx_t *)(known_sfx->name + iVar1);
LAB_001f5e4f:
  Q_strncpy(dest->name,name,0x3f);
  dest->name[0x3f] = '\0';
  if (pfInCache != (int *)0x0) {
    *pfInCache = 0;
  }
LAB_001f5eb0:
  dest->servercount = cl.servercount;
  return dest;
}


// S_FlushSoundData  @ 001f5f30
void S_FlushSoundData(int fDumpLores,int fDumpHires)

{
  void *pvVar1;
  int iVar2;
  channel_t *pcVar3;
  int iVar4;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: channel_t * ch@[???]
                       Unresolved local var: int fNoDiscard@[???] */
  if (0 < num_sfx) {
    pcVar3 = channels;
    local_20 = 0;
    iVar4 = 0;
    do {
      pvVar1 = Cache_Check((cache_user_t *)(known_sfx->name + iVar4 + 0x40));
      if (pvVar1 != (void *)0x0) {
        if (0 < total_channels) {
          iVar2 = 0;
          do {
            if (((pcVar3->sfx != (sfx_t *)0x0) && (pcVar3->entchannel == 5)) &&
               (pcVar3->sfx == (sfx_t *)(known_sfx->name + iVar4))) goto LAB_001f5f98;
            iVar2 = iVar2 + 1;
            pcVar3 = pcVar3 + 1;
          } while (iVar2 != total_channels);
        }
        if ((fDumpLores != 0) && (*(int *)((int)pvVar1 + 8) <= shm->speed)) {
          Cache_Free((cache_user_t *)(known_sfx->name + iVar4 + 0x40));
        }
        if ((fDumpHires != 0) && (shm->speed < *(int *)((int)pvVar1 + 8))) {
          Cache_Free((cache_user_t *)(known_sfx->name + iVar4 + 0x40));
        }
      }
LAB_001f5f98:
      local_20 = local_20 + 1;
      iVar4 = iVar4 + 0x48;
    } while (local_20 < num_sfx);
  }
  return;
}


// S_FreeChannel  @ 001f99b0
void S_FreeChannel(channel_t *ch)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = ch->entchannel;
  if (iVar1 == 5) {
                    /* Unresolved local var: int i@[???] */
    uVar2 = (uint)ch[-0x4d847].origin >> 6;
    if (wavstreams[uVar2].hFile != (FileHandle_t)0x0) {
      FS_Close(wavstreams[uVar2].hFile);
    }
    Q_memset(wavstreams + uVar2,0,0x28);
    wavstreams[uVar2].hFile = (FileHandle_t)0x0;
    Cache_Free(&ch->sfx->cache);
  }
  else if (iVar1 - 7U < 0x1ee) {
    VoiceSE_NotifyFreeChannel(iVar1);
  }
  if (-1 < ch->isentence) {
    rgrgvoxword[ch->isentence][0].sfx = (sfx_t *)0x0;
  }
  iVar1 = ch->entnum;
  ch->isentence = -1;
  ch->sfx = (sfx_t *)0x0;
  if (0 < iVar1) {
    if ((ch->entchannel != 5) && (ch->entchannel != 2)) {
      return;
    }
    if (iVar1 < cl.max_edicts) {
      cl_entities[iVar1].mouth.mouthopen = '\0';
    }
  }
  return;
}


// S_Init  @ 001f5a30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_Init(void)

{
  int iVar1;
  dma_t *pdVar2;
  uchar *puVar3;
  qboolean qVar4;
  char *clear;
  
  Con_DPrintf("Sound Initialization\n");
  VOX_Init();
  iVar1 = COM_CheckParm("-nosound");
  if (iVar1 != 0) {
    return;
  }
  iVar1 = COM_CheckParm("-simsound");
  if (iVar1 != 0) {
    fakedma = true;
  }
  Cmd_AddCommand("play",S_Play);
  Cmd_AddCommand("playvol",S_PlayVol);
  Cmd_AddCommand("speak",S_Say);
  Cmd_AddCommand("spk",S_Say_Reliable);
  Cmd_AddCommand("stopsound",S_StopAllSoundsC);
  Cmd_AddCommand("soundlist",S_SoundList);
  Cmd_AddCommand("soundinfo",S_SoundInfo_f);
  Cvar_RegisterVariable(&s_show);
  Cvar_RegisterVariable(&nosound);
  Cvar_RegisterVariable(&volume);
  Cvar_RegisterVariable(&suitvolume);
  Cvar_RegisterVariable(&hisound);
  Cvar_RegisterVariable(&loadas8bit);
  Cvar_RegisterVariable(&bgmvolume);
  Cvar_RegisterVariable(&MP3Volume);
  Cvar_RegisterVariable(&MP3FadeTime);
  Cvar_RegisterVariable(&ambient_level);
  Cvar_RegisterVariable(&ambient_fade);
  Cvar_RegisterVariable(&snd_noextraupdate);
  Cvar_RegisterVariable(&snd_show);
  Cvar_RegisterVariable(&_snd_mixahead);
  Cvar_RegisterVariable(&speak_enable);
  if (host_parms.memsize < 0x800000) {
    Cvar_Set("loadas8bit","1");
    Con_DPrintf("loading all sounds as 8bit\n");
  }
  snd_initialized = true;
                    /* Unresolved local var: int rc@[???] */
  if (fakedma == false) {
    qVar4 = SNDDMA_Init();
    if (qVar4 == false) {
      Con_Printf("S_Startup: SNDDMA_Init failed.\n");
      sound_started = 0;
      goto LAB_001f5bec;
    }
  }
  sound_started = 1;
LAB_001f5bec:
  SND_InitScaletable();
  clear = "";
  known_sfx = Hunk_AllocName(0x12000,"sfx_t");
  num_sfx = 0;
  if (fakedma != false) {
    pdVar2 = Hunk_AllocName(0x2c,"shm");
    pdVar2->splitbuffer = false;
    shm = pdVar2;
    pdVar2->samplebits = 0x10;
    pdVar2->speed = 0x5622;
    pdVar2->channels = 2;
    pdVar2->samples = 0x8000;
    pdVar2->samplepos = 0;
    pdVar2->soundalive = true;
    pdVar2->gamealive = true;
    pdVar2 = shm;
    shm->submission_chunk = 1;
    puVar3 = Hunk_AllocName(0x10000,"shmbuf");
    pdVar2->buffer = puVar3;
    clear = "Sound sampling rate: %i\n";
    Con_DPrintf("Sound sampling rate: %i\n",shm->speed);
  }
                    /* Unresolved local var: int i@[???] */
  if (sound_started != 0) {
    S_StopAllSounds((qboolean)clear);
  }
  SX_Init();
  Wavstream_Init();
  return;
}


// S_LoadSound  @ 00201710
sfxcache_t * S_LoadSound(sfx_t *s,channel_t *ch)

{
  cache_user_t *c;
  float fVar1;
  sfxcache_t *psVar2;
  uint uVar3;
  uint uVar4;
  byte *wav;
  wavinfo_t *info;
  int iVar5;
  qboolean qVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  double dVar10;
  FileHandle_t local_560;
  double local_55c;
  undefined1 local_54c [1024];
  uint local_14c [63];
  undefined1 local_4d;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  uint local_2c [7];
  
                    /* Unresolved local var: char[256] namebuffer@[???]
                       Unresolved local var: byte * data@[???]
                       Unresolved local var: wavinfo_t info@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: int filesize@[???]
                       Unresolved local var: float stepscale@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: byte[1024] stackbuf@[???]
                       Unresolved local var: double startTime@[???]
                       Unresolved local var: FileHandle_t hFile@[???] */
  if (s->name[0] == '*') {
    psVar2 = S_LoadStreamSound(s,ch);
    return psVar2;
  }
  if (s->name[0] == '?') {
    psVar2 = VoiceSE_GetSFXCache(s);
    return psVar2;
  }
  c = &s->cache;
  psVar2 = Cache_Check(c);
  if (psVar2 != (sfxcache_t *)0x0) {
    if (hisound.value != 0.0) {
      return psVar2;
    }
    if (shm == (dma_t *)0x0) {
      return psVar2;
    }
    if (psVar2->speed <= shm->speed) {
      return psVar2;
    }
    Cache_Free(c);
  }
  if (fs_precache_timings.value != 0.0) {
    local_55c = Sys_FloatTime();
  }
  Q_strcpy((char *)local_14c,"sound");
  puVar8 = local_14c;
  if (s->name[0] != '/') {
    do {
      puVar7 = puVar8;
      uVar3 = *puVar7 + 0xfefefeff & ~*puVar7;
      uVar4 = uVar3 & 0x80808080;
      puVar8 = puVar7 + 1;
    } while (uVar4 == 0);
    if ((uVar3 & 0x8080) == 0) {
      puVar8 = (uint *)((int)puVar7 + 6);
      uVar4 = uVar4 >> 0x10;
    }
    strncat((char *)local_14c,"/",
            (size_t)(&local_4d + -(int)((int)puVar8 + (-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4))))
           );
    puVar8 = local_14c;
  }
  do {
    puVar7 = puVar8;
    uVar3 = *puVar7 + 0xfefefeff & ~*puVar7;
    uVar4 = uVar3 & 0x80808080;
    puVar8 = puVar7 + 1;
  } while (uVar4 == 0);
  if ((uVar3 & 0x8080) == 0) {
    puVar8 = (uint *)((int)puVar7 + 6);
    uVar4 = uVar4 >> 0x10;
  }
  strncat((char *)local_14c,s->name,
          (size_t)(&local_4d + -(int)((int)puVar8 + (-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4)))));
  local_560 = FS_Open((char *)local_14c,"rb");
  if (local_560 == (FileHandle_t)0x0) {
LAB_00201a00:
    local_14c[0]._0_1_ = 0;
    puVar8 = local_14c;
    if (s->name[0] != '/') {
      do {
        puVar7 = puVar8;
        uVar3 = *puVar7 + 0xfefefeff & ~*puVar7;
        uVar4 = uVar3 & 0x80808080;
        puVar8 = puVar7 + 1;
      } while (uVar4 == 0);
      if ((uVar3 & 0x8080) == 0) {
        puVar8 = (uint *)((int)puVar7 + 6);
        uVar4 = uVar4 >> 0x10;
      }
      strncat((char *)local_14c,"/",
              (size_t)(&local_4d +
                      -(int)((int)puVar8 + (-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4)))));
      puVar8 = local_14c;
    }
    do {
      puVar7 = puVar8;
      uVar3 = *puVar7 + 0xfefefeff & ~*puVar7;
      uVar4 = uVar3 & 0x80808080;
      puVar8 = puVar7 + 1;
    } while (uVar4 == 0);
    if ((uVar3 & 0x8080) == 0) {
      puVar8 = (uint *)((int)puVar7 + 6);
      uVar4 = uVar4 >> 0x10;
    }
    strncat((char *)local_14c,s->name,
            (size_t)(&local_4d + -(int)((int)puVar8 + (-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4))))
           );
    local_4d = 0;
    wav = COM_LoadStackFile((char *)local_14c,local_54c,0x400,(int *)local_2c);
    if (wav == (byte *)0x0) {
      Con_DPrintf("S_LoadSound: Couldn\'t load %s\n",local_14c);
      return (sfxcache_t *)0x0;
    }
LAB_00201ad9:
    local_560 = (FileHandle_t)0x0;
  }
  else {
    wav = FS_GetReadBuffer(local_560,(int *)local_2c);
    if (wav == (byte *)0x0) {
      local_2c[0] = FS_Size(local_560);
      wav = Hunk_TempAlloc(local_2c[0] + 1);
      FS_Read(wav,local_2c[0],1,local_560);
      FS_Close(local_560);
      if (wav == (byte *)0x0) goto LAB_00201a00;
      goto LAB_00201ad9;
    }
  }
  uVar4 = local_2c[0];
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int format@[???]
                       Unresolved local var: int samples@[???] */
  Q_memset(&local_4c,0,0x18);
  iff_end = wav + uVar4;
  iff_data = wav;
  last_chunk = wav;
  FindNextChunk("RIFF");
  if (data_p != (byte *)0x0) {
    info = (wavinfo_t *)(data_p + 8);
    iVar5 = Q_strncmp((char *)info,"WAVE",4);
    if (iVar5 == 0) {
      qVar6 = GetWavinfo(s->name,wav,(int)&local_4c,info);
      if (qVar6 != false) {
        if (local_44 != 1) {
          Con_DPrintf("%s is a stereo sample\n",s);
          return (sfxcache_t *)0x0;
        }
        if (local_4c == 0) {
          Con_DPrintf("Invalid rate: %s\n",s);
          return (sfxcache_t *)0x0;
        }
        if ((int)local_2c[0] <= local_38) {
          Con_DPrintf("%s has invalid data offset\n",s);
          return (sfxcache_t *)0x0;
        }
        if ((shm == (dma_t *)0x0) || (local_4c == shm->speed)) {
          fVar1 = 1.0;
        }
        else if (((local_4c != shm->speed * 2) || (fVar1 = 1.0, hisound.value <= 0.0)) &&
                (fVar1 = (float)local_4c / (float)shm->speed, fVar1 == 0.0)) {
          Con_DPrintf("Invalid stepscale: %s\n",s);
          return (sfxcache_t *)0x0;
        }
        iVar9 = 0x18;
        iVar5 = (int)((float)local_3c / fVar1);
        if (iVar5 != 0) {
          iVar9 = (int)(0x7fffffff / (longlong)iVar5);
          if (iVar9 < 1) {
            Con_DPrintf("Invalid length (s/c): %s\n",s);
            return (sfxcache_t *)0x0;
          }
          if (iVar9 < local_48) {
            Con_DPrintf("Invalid length (s/c/w): %s\n",s);
            return (sfxcache_t *)0x0;
          }
          iVar5 = local_48 * iVar5;
          if (0x7fffffffU - iVar5 < 0x18) {
            Con_DPrintf("Invalid length (s/c/w/sfx): %s\n",s);
          }
          iVar9 = iVar5 + 0x18;
        }
        psVar2 = Cache_Alloc(c,iVar9,s->name);
        if (psVar2 == (sfxcache_t *)0x0) {
          return (sfxcache_t *)0x0;
        }
        psVar2->length = local_3c;
        psVar2->loopstart = local_40;
        psVar2->speed = local_4c;
        psVar2->width = local_48;
        psVar2->stereo = local_44;
        ResampleSfx(s,local_4c,local_48,wav + local_38,local_2c[0] - local_38);
        if (local_560 != (FileHandle_t)0x0) {
          FS_ReleaseReadBuffer(local_560,wav);
          FS_Close(local_560);
        }
        if (fs_precache_timings.value == 0.0) {
          return psVar2;
        }
        dVar10 = Sys_FloatTime();
        Con_DPrintf("fs_precache_timings: loaded sound %s in time %.3f sec\n",local_14c,
                    (double)(float)((longdouble)dVar10 - (longdouble)local_55c));
        return psVar2;
      }
      goto LAB_00201940;
    }
  }
  Con_Printf("Missing RIFF/WAVE chunks\n");
LAB_00201940:
  Con_DPrintf("Failed loading %s\n",s);
  return (sfxcache_t *)0x0;
}


// S_LoadStreamSound  @ 00201230
sfxcache_t * S_LoadStreamSound(sfx_t *s,channel_t *ch)

{
  char *dest;
  FileHandle_t pvVar1;
  sfxcache_t *psVar2;
  byte *wav;
  wavinfo_t *info;
  int iVar3;
  qboolean qVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  uint local_18c [63];
  char acStack_8d [64];
  undefined1 local_4d;
  int local_4c [4];
  int local_3c;
  int local_38;
  int local_2c [7];
  
                    /* Unresolved local var: char[256] namebuffer@[???]
                       Unresolved local var: char[64] wavname@[???]
                       Unresolved local var: byte * data@[???]
                       Unresolved local var: wavinfo_t info@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int cbread@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int ffirstload@[???] */
  if (cl.fPrecaching != 0) {
    return (sfxcache_t *)0x0;
  }
  dest = acStack_8d + 1;
  Q_strncpy(dest,s->name + 1,0x3f);
  local_4d = 0;
  uVar9 = (uint)ch[-0x4d847].origin >> 6;
  psVar2 = Cache_Check(&s->cache);
  if ((psVar2 != (sfxcache_t *)0x0) && (wavstreams[uVar9].hFile != (FileHandle_t)0x0)) {
    return psVar2;
  }
  Q_strcpy((char *)local_18c,"sound");
  if (acStack_8d[1] != '/') {
    puVar6 = local_18c;
    do {
      puVar5 = puVar6;
      uVar7 = *puVar5 + 0xfefefeff & ~*puVar5;
      uVar8 = uVar7 & 0x80808080;
      puVar6 = puVar5 + 1;
    } while (uVar8 == 0);
    if ((uVar7 & 0x8080) == 0) {
      puVar6 = (uint *)((int)puVar5 + 6);
      uVar8 = uVar8 >> 0x10;
    }
    strncat((char *)local_18c,"/",
            (size_t)(acStack_8d + -((int)puVar6 + (-3 - (uint)CARRY1((byte)uVar8,(byte)uVar8)))));
  }
  puVar6 = local_18c;
  do {
    puVar5 = puVar6;
    uVar7 = *puVar5 + 0xfefefeff & ~*puVar5;
    uVar8 = uVar7 & 0x80808080;
    puVar6 = puVar5 + 1;
  } while (uVar8 == 0);
  if ((uVar7 & 0x8080) == 0) {
    puVar6 = (uint *)((int)puVar5 + 6);
    uVar8 = uVar8 >> 0x10;
  }
  strncat((char *)local_18c,dest,
          (size_t)(acStack_8d + -((int)puVar6 + (-3 - (uint)CARRY1((byte)uVar8,(byte)uVar8)))));
  pvVar1 = wavstreams[uVar9].hFile;
  wav = COM_LoadFileLimit((char *)local_18c,wavstreams[uVar9].lastposloaded,0x8000,local_2c,
                          &wavstreams[uVar9].hFile);
  iVar3 = local_2c[0];
  if (wav == (byte *)0x0) {
    Con_DPrintf("S_LoadStreamSound: Couldn\'t load %s\n",local_18c);
    return (sfxcache_t *)0x0;
  }
  bVar10 = pvVar1 != (FileHandle_t)0x0;
  if (bVar10) {
    uVar8 = 0;
    do {
      *(undefined4 *)((int)local_4c + uVar8) = *(undefined4 *)(uVar9 * 0x28 + 0x135fd8c + uVar8);
      uVar8 = uVar8 + 4;
    } while (uVar8 < 0x18);
    wavstreams[uVar9].csamplesinmem = local_2c[0];
LAB_00201464:
    local_3c = local_3c - wavstreams[uVar9].csamplesplayed;
    if (local_3c < iVar3) {
      wavstreams[uVar9].csamplesinmem = local_3c;
    }
    uVar8 = 0;
    do {
      *(undefined4 *)(uVar9 * 0x28 + 0x135fd8c + uVar8) = *(undefined4 *)((int)local_4c + uVar8);
      uVar8 = uVar8 + 4;
    } while (uVar8 < 0x18);
    if (psVar2 == (sfxcache_t *)0x0) {
      iVar3 = 0x8000;
      if (local_2c[0] < 0x8001) {
        iVar3 = local_2c[0];
      }
      psVar2 = Cache_Alloc(&s->cache,iVar3 + 0x18,dest);
      if (psVar2 == (sfxcache_t *)0x0) {
        return (sfxcache_t *)0x0;
      }
    }
    psVar2->length = wavstreams[uVar9].csamplesinmem;
    psVar2->loopstart = local_4c[3];
    psVar2->speed = local_4c[0];
    psVar2->width = local_4c[1];
    psVar2->stereo = local_4c[2];
    if (bVar10) {
      ResampleSfx(s,local_4c[0],local_4c[1],wav,local_2c[0]);
      return psVar2;
    }
    ResampleSfx(s,local_4c[0],local_4c[1],wav + local_38,local_2c[0] - local_38);
    return psVar2;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int format@[???]
                       Unresolved local var: int samples@[???] */
  Q_memset(local_4c,0,0x18);
  iff_end = wav + iVar3;
  iff_data = wav;
  last_chunk = wav;
  FindNextChunk("RIFF");
  if (data_p != (byte *)0x0) {
    info = (wavinfo_t *)(data_p + 8);
    iVar3 = Q_strncmp((char *)info,"WAVE",4);
    if (iVar3 == 0) {
      qVar4 = GetWavinfo(s->name,wav,(int)local_4c,info);
      if (qVar4 != false) {
        if (local_4c[2] != 1) {
          Con_DPrintf("%s is a stereo sample\n",dest);
          return (sfxcache_t *)0x0;
        }
        if (local_4c[1] != 1) {
          Con_DPrintf("%s is a 16 bit sample\n",dest);
          return (sfxcache_t *)0x0;
        }
        if ((shm != (dma_t *)0x0) && (local_4c[0] != shm->speed)) {
          Con_DPrintf("%s ignored, not stored at playback sample rate!\n",dest);
          return (sfxcache_t *)0x0;
        }
        iVar3 = local_2c[0] - local_38;
        wavstreams[uVar9].csamplesinmem = iVar3;
        goto LAB_00201464;
      }
      goto LAB_002015ac;
    }
  }
  Con_Printf("Missing RIFF/WAVE chunks\n");
LAB_002015ac:
  Con_DPrintf("Failed loading %s\n",dest);
  return (sfxcache_t *)0x0;
}


// S_LocalSound  @ 001f9640
void S_LocalSound(char *sound)

{
  byte bVar1;
  int iVar2;
  sfx_t *s;
  float in_stack_ffffffdc;
  int in_stack_ffffffe0;
  float pitch;
  
                    /* Unresolved local var: sfx_t * sfx@[DW_OP_reg6(ESI)] */
  if ((nosound.value == 0.0) && (sound_started != 0)) {
                    /* Unresolved local var: sfx_t * sfx@[???] */
    if (nosound.value == 0.0) {
      pitch = 0.0;
      iVar2 = Q_strlen(sound);
      if (iVar2 < 0x40) {
        bVar1 = *sound;
        if ((bVar1 == 0x21) || (bVar1 == 0x2a)) {
                    /* Unresolved local var: sfx_t * sfx@[???] */
          s = S_FindName(sound,(int *)(uint)bVar1);
        }
        else {
          s = S_FindName(sound,(int *)(uint)bVar1);
          if (fs_lazy_precache.value == pitch) {
            S_LoadSound(s,(channel_t *)0x0);
          }
        }
        if (s != (sfx_t *)0x0) {
                    /* Unresolved local var: channel_t * target_chan@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: channel_t * check@[???]
                       Unresolved local var: int vol@[???]
                       Unresolved local var: int ch_idx@[???]
                       Unresolved local var: int skip@[???]
                       Unresolved local var: int fsentence@[???] */
          if (sound_started == 0) {
            return;
          }
          if (nosound.value != 0.0) {
            return;
          }
          S_StartDynamicSound(cl.viewentity,-1,s,vec3_origin,1.0,in_stack_ffffffdc,in_stack_ffffffe0
                              ,(int)pitch);
          return;
        }
      }
    }
    Con_Printf("S_LocalSound: can\'t cache %s\n",sound);
  }
  return;
}


// S_MixChannelsToPaintbuffer  @ 001ffa30
void S_MixChannelsToPaintbuffer(int end,int fPaintHiresSounds,int voiceOnly)

{
  int *piVar1;
  undefined1 auVar2 [16];
  int iVar3;
  bool bVar4;
  undefined1 auVar5 [16];
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  undefined1 auVar11 [12];
  float fVar12;
  float fVar13;
  cl_entity_t *pcVar14;
  sfxcache_t *psVar15;
  uint uVar16;
  portable_samplepair_t *ppVar17;
  qboolean qVar18;
  int iVar19;
  portable_samplepair_t *ppVar20;
  int iVar21;
  int iVar22;
  portable_samplepair_t *ppVar23;
  uint uVar24;
  uint uVar25;
  int iVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  uint uVar33;
  int iVar34;
  int iVar35;
  bool bVar36;
  bool bVar37;
  portable_samplepair_t pVar38;
  undefined1 auVar39 [14];
  uint6 uVar40;
  portable_samplepair_t pVar41;
  int iVar44;
  ulonglong uVar48;
  int iVar49;
  int iVar50;
  int local_10cc;
  int local_10bc;
  int iStack_10b4;
  uint local_1080;
  channel_t *local_107c;
  int local_1078;
  uint local_1074;
  int local_1070;
  int local_1064;
  int local_105c;
  wavstream_t *local_1058;
  int local_104c;
  int local_103c;
  int local_1038;
  portable_samplepair_t local_102c [512];
  sfxcache_t *local_2c [7];
  undefined1 auVar42 [12];
  undefined1 auVar43 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: channel_t * ch@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int ltime@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int pitch@[???]
                       Unresolved local var: int timecompress@[???]
                       Unresolved local var: int fhitend@[???]
                       Unresolved local var: int hires@[???]
                       Unresolved local var: int offset@[???]
                       Unresolved local var: int chend@[???]
                       Unresolved local var: int bVoice@[???]
                       Unresolved local var: portable_samplepair_t * pout@[???] */
  bVar36 = fPaintHiresSounds != 0;
  if (0 < total_channels) {
    local_1058 = wavstreams;
    local_107c = channels;
    local_105c = 0;
    iVar22 = total_channels;
    do {
      if (local_107c->sfx != (sfx_t *)0x0) {
        local_2c[0] = S_LoadSound(local_107c->sfx,local_107c);
        bVar37 = local_2c[0]->length == 0x40000000;
        iVar22 = total_channels;
        if (bVar37) {
          if (voiceOnly != 0) {
            iVar34 = local_107c->leftvol;
            goto joined_r0x001ffa97;
          }
        }
        else if (voiceOnly == 0) {
          iVar34 = local_107c->leftvol;
joined_r0x001ffa97:
          if ((iVar34 == 0) && (local_107c->rightvol == 0)) {
            if (local_2c[0]->loopstart < 0) {
              S_FreeChannel(local_107c);
              iVar22 = total_channels;
            }
          }
          else if (fPaintHiresSounds == 0) {
            if (local_2c[0]->speed == shm->speed) goto LAB_001ffb62;
          }
          else if (shm->speed < local_2c[0]->speed) {
LAB_001ffb62:
            local_1038 = 0;
            iVar22 = local_107c->isentence;
            iVar34 = local_107c->pitch;
            local_1070 = paintedtime;
            local_103c = iVar34;
            if (-1 < iVar22) {
              iVar32 = *(int *)(iVar22 * 0x480 + 0x1365204 + local_107c->iword * 0x24);
              local_103c = iVar34 + -100 + iVar32;
              if (iVar32 < 1) {
                local_103c = iVar34;
              }
              local_1038 = *(int *)(iVar22 * 0x480 + 0x136521c + local_107c->iword * 0x24);
            }
                    /* Unresolved local var: int oldleft@[???]
                       Unresolved local var: int oldright@[???] */
            bVar10 = false;
            while ((psVar15 = local_2c[0], iVar34 = paintedtime, pcVar14 = cl_entities,
                   iVar22 = total_channels, local_1070 < end && (!bVar10))) {
              if (bVar36) {
                iVar22 = (local_2c[0]->length >> 1) + (local_107c->end - local_2c[0]->length);
              }
              else {
                iVar22 = local_107c->end;
              }
              iVar32 = iVar22 - local_1070;
              if (end <= iVar22) {
                iVar32 = end - local_1070;
              }
              if ((!bVar37) ||
                 ((bVar10 = true, local_2c[0]->width == 2 && (local_2c[0]->stereo == 0)))) {
                local_1080 = iVar32 << bVar36;
                bVar4 = false;
                if (0 < (int)local_1080) {
                  if (((local_2c[0]->width == 1) && (iVar32 = local_107c->entnum, 0 < iVar32)) &&
                     ((local_107c->entchannel == 5 || (local_107c->entchannel == 2)))) {
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: char * pdata@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int savg@[???]
                       Unresolved local var: int scount@[???]
                       Unresolved local var: cl_entity_t * pent@[???] */
                    iVar19 = 0;
                    uVar24 = (uint)cl_entities[iVar32].mouth.sndcount;
                    if (uVar24 < 10) {
                      iVar35 = 0;
                      do {
                        uVar24 = uVar24 + 1;
                        uVar25 = (uint)(char)local_2c[0]->data[iVar35 + local_107c->pos];
                        iVar35 = iVar35 + 0x50 + (uVar25 & 0x1f);
                        iVar19 = iVar19 + (((int)uVar25 >> 0x1f ^ uVar25) - ((int)uVar25 >> 0x1f));
                        if (9 < (int)uVar24) break;
                      } while (iVar35 < (int)local_1080);
                    }
                    iVar35 = cl_entities[iVar32].mouth.sndavg;
                    cl_entities[iVar32].mouth.sndcount = (byte)uVar24;
                    iVar35 = iVar35 + iVar19;
                    pcVar14[iVar32].mouth.sndavg = iVar35;
                    if (9 < (byte)uVar24) {
                      pcVar14[iVar32].mouth.sndavg = 0;
                      pcVar14[iVar32].mouth.sndcount = '\0';
                      pcVar14[iVar32].mouth.mouthopen = (byte)(iVar35 / 10);
                    }
                  }
                  fVar13 = g_SND_VoiceOverdrive;
                  uVar24 = local_107c->leftvol;
                  uVar25 = local_107c->rightvol;
                  uVar27 = uVar24;
                  local_1074 = uVar25;
                  if (!bVar37) {
                    fVar12 = (float)(int)uVar24 / g_SND_VoiceOverdrive;
                    local_107c->leftvol = (int)fVar12;
                    local_107c->rightvol = (int)((float)(int)uVar25 / fVar13);
                    uVar27 = (int)fVar12;
                    local_1074 = (int)((float)(int)uVar25 / fVar13);
                  }
                  iVar32 = local_1070 - iVar34 << bVar36;
                  if (local_2c[0]->width == 1) {
                    if ((local_1038 == 0 && local_103c == 100) ||
                       (iVar19 = local_107c->isentence, iVar19 < 0)) {
                      if (local_1070 == iVar34) {
                        SND_PaintChannelFrom8(local_107c,local_2c[0],local_1080);
                        bVar4 = false;
                      }
                      else {
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: int * lscale@[???]
                       Unresolved local var: int * rscale@[???]
                       Unresolved local var: uchar * sfx@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: portable_samplepair_t * pbuffer@[???] */
                        if ((int)uVar27 < 0x100) {
                          iVar34 = ((int)uVar27 >> 3) << 10;
                        }
                        else {
                          iVar34 = 0x7c00;
                          local_107c->leftvol = 0xff;
                        }
                        if ((int)local_1074 < 0x100) {
                          iVar19 = ((int)local_1074 >> 3) << 10;
                        }
                        else {
                          iVar19 = 0x7c00;
                          local_107c->rightvol = 0xff;
                        }
                        iVar35 = local_107c->pos;
                        uVar27 = 0;
                        do {
                          iVar31 = (uint)local_2c[0]->data[uVar27 + iVar35] * 4;
                          iVar3 = *(int *)((int)snd_scaletable[0] + iVar31 + iVar19);
                          paintbuffer[iVar32 + uVar27].left =
                               paintbuffer[iVar32 + uVar27].left +
                               *(int *)((int)snd_scaletable[0] + iVar31 + iVar34);
                          piVar1 = (int *)(iVar32 * 8 + 0x13631e4 + uVar27 * 8);
                          *piVar1 = *piVar1 + iVar3;
                          uVar27 = uVar27 + 1;
                        } while (uVar27 != local_1080);
                        local_107c->pos = local_1080 + iVar35;
                        bVar4 = false;
                      }
                    }
                    else {
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: int * lscale@[???]
                       Unresolved local var: int * rscale@[???]
                       Unresolved local var: uchar * sfx@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int posold@[???]
                       Unresolved local var: int samplefrac@[???]
                       Unresolved local var: int fracstep@[???]
                       Unresolved local var: int srcsample@[???]
                       Unresolved local var: float stepscale@[???]
                       Unresolved local var: int cb@[???]
                       Unresolved local var: portable_samplepair_t * pbuffer@[???] */
                      ppVar23 = paintbuffer + iVar32;
                      if ((int)uVar27 < 0x100) {
                        iVar34 = ((int)uVar27 >> 3) << 10;
                        if (0xff < (int)local_1074) goto LAB_002004fd;
LAB_00200135:
                        iVar32 = ((int)local_1074 >> 3) << 10;
                      }
                      else {
                        iVar34 = 0x7c00;
                        local_107c->leftvol = 0xff;
                        if ((int)local_1074 < 0x100) goto LAB_00200135;
LAB_002004fd:
                        iVar32 = 0x7c00;
                        local_107c->rightvol = 0xff;
                      }
                      local_1078 = local_107c->iword;
                      iVar30 = (int)(((float)local_103c / 100.0) * 256.0);
                      iVar35 = rgrgvoxword[iVar19][local_1078].samplefrac;
                      iVar3 = rgrgvoxword[iVar19][local_1078].cbtrim;
                      iVar31 = iVar35 >> 8;
                      iVar35 = iVar35 + iVar30;
                      if (local_1038 == 0) {
                        iVar21 = 0;
                        if (iVar31 < iVar3) {
                          iVar21 = 0;
                          do {
                            iVar21 = iVar21 + 1;
                            iVar31 = (uint)local_2c[0]->data[iVar31] * 4;
                            ppVar23->left =
                                 ppVar23->left + *(int *)((int)snd_scaletable[0] + iVar31 + iVar34);
                            ppVar23->right =
                                 ppVar23->right + *(int *)((int)snd_scaletable[0] + iVar31 + iVar32)
                            ;
                            iVar31 = iVar35 >> 8;
                            ppVar23 = ppVar23 + 1;
                            iVar35 = iVar35 + iVar30;
                            if (iVar3 <= iVar31) break;
                          } while (iVar21 < (int)local_1080);
                        }
                      }
                      else {
                    /* Unresolved local var: int chunksize@[???]
                       Unresolved local var: int skipbytes@[???]
                       Unresolved local var: int lowsample@[???]
                       Unresolved local var: int playcount@[???]
                       Unresolved local var: int cdata@[???]
                       Unresolved local var: int j@[???] */
                        iVar19 = iVar3 + 7;
                        if (-1 < iVar3) {
                          iVar19 = iVar3;
                        }
                        iVar19 = iVar19 >> 3;
                        local_104c = 0;
                        iVar6 = (local_1038 * iVar19) / 100;
                        iVar21 = 0;
LAB_00200551:
                        if (iVar31 < iVar3) {
                          do {
                            if ((int)local_1080 <= iVar21) break;
                            iVar26 = iVar31 % iVar19;
                            if ((iVar26 < iVar6) && (iVar6 <= iVar31)) {
                              uVar27 = (uint)psVar15->data[iVar31];
                              if (4 < uVar27 + 2) {
                                ppVar20 = ppVar23 + iVar21;
                                local_10cc = 0xff;
                                do {
                                  iVar21 = iVar21 + 1;
                                  ppVar20->left =
                                       ppVar20->left +
                                       *(int *)((int)snd_scaletable[0] + uVar27 * 4 + iVar34);
                                  ppVar20->right =
                                       ppVar20->right +
                                       *(int *)((int)snd_scaletable[0] + uVar27 * 4 + iVar32);
                                  iVar31 = iVar35 >> 8;
                                  iVar35 = iVar35 + iVar30;
                                  if (((iVar3 <= iVar31) || ((int)local_1080 <= iVar21)) ||
                                     (local_10cc = local_10cc + -1, local_10cc == 0)) break;
                                  uVar27 = (uint)psVar15->data[iVar31];
                                  ppVar20 = ppVar20 + 1;
                                } while (4 < uVar27 + 2);
                              }
                              if (0x200 < iVar21) {
                                Con_DPrintf("timecompress scan forward: overwrote paintbuffer!");
                              }
                              if ((iVar3 <= iVar31) || ((int)local_1080 <= iVar21)) break;
                              do {
                                if (iVar31 % iVar19 < iVar6) {
                                  iVar26 = iVar6 - iVar31 % iVar19;
                                  iVar31 = iVar31 + iVar26;
                                  iVar35 = iVar35 + iVar26 * 0x100;
                                }
                                if (iVar31 < iVar3) {
                                  if (2 < psVar15->data[iVar31]) {
                                    iVar26 = 0;
                                    do {
                                      iVar26 = iVar26 + 1;
                                      iVar31 = iVar35 >> 8;
                                      iVar35 = iVar35 + iVar30;
                                      if ((0xfe < iVar26) || (iVar3 <= iVar31)) goto LAB_002006a5;
                                    } while (2 < psVar15->data[iVar31]);
                                  }
                                }
                                else {
LAB_002006a5:
                                  if (iVar3 <= iVar31) goto LAB_002006ce;
                                }
                                iVar26 = iVar31 % iVar19;
                              } while (iVar26 < iVar6);
                            }
                            local_104c = iVar19 - iVar26;
LAB_002006ce:
                            local_1078 = (local_104c << 8) / iVar30;
                            if ((int)local_1080 < local_1078 + iVar21) {
                              local_1078 = local_1080 - iVar21;
                            }
                            if (local_1078 == 0) {
                              local_1078 = 1;
                            }
                            else if (local_1078 < 1) goto LAB_00200551;
                            if (iVar3 <= iVar31) goto LAB_00200551;
                            ppVar20 = ppVar23 + iVar21;
                            iVar26 = 0;
                            do {
                              iVar26 = iVar26 + 1;
                              iVar21 = iVar21 + 1;
                              iVar31 = (uint)psVar15->data[iVar31] * 4;
                              ppVar20->left =
                                   ppVar20->left +
                                   *(int *)((int)snd_scaletable[0] + iVar31 + iVar34);
                              ppVar20->right =
                                   ppVar20->right +
                                   *(int *)((int)snd_scaletable[0] + iVar31 + iVar32);
                              iVar31 = iVar35 >> 8;
                              iVar35 = iVar35 + iVar30;
                              if ((local_1078 <= iVar26) || ((int)local_1080 <= iVar21)) break;
                              ppVar20 = ppVar20 + 1;
                            } while (iVar31 < iVar3);
                            if (iVar3 <= iVar31) break;
                          } while( true );
                        }
                        iVar19 = local_107c->isentence;
                        local_1078 = local_107c->iword;
                      }
                      *(int *)(iVar19 * 0x480 + 0x1365218 + local_1078 * 0x24) = iVar35 - iVar30;
                      iVar34 = local_107c->pos;
                      local_107c->pos = iVar35 >> 8;
                      local_107c->end = local_107c->end + (iVar34 - (iVar35 >> 8)) + iVar21;
                      bVar4 = iVar3 <= iVar31;
                    }
                  }
                  else {
                    /* Unresolved local var: char[4096] copyBuf@[???]
                       Unresolved local var: short * pSrcData@[???] */
                    if (bVar37) {
                      ppVar23 = local_102c;
                      local_1080 = (*(code *)local_2c[0]->loopstart)
                                             (local_2c[0],ppVar23,0x1000,local_107c->pos,local_1080)
                      ;
                      uVar27 = local_107c->leftvol;
                      local_1074 = local_107c->rightvol;
                      if (0 < (int)local_1080) {
                        local_1064 = local_107c->pos;
                        goto LAB_001ffd6a;
                      }
                      local_1064 = local_107c->pos;
                    }
                    else {
                      local_1064 = local_107c->pos;
                      ppVar23 = (portable_samplepair_t *)(local_2c[0]->data + local_1064 * 2);
LAB_001ffd6a:
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: int left@[???]
                       Unresolved local var: int right@[???]
                       Unresolved local var: int leftvol@[???]
                       Unresolved local var: int rightvol@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: portable_samplepair_t * pbuffer@[???] */
                      ppVar20 = paintbuffer + iVar32;
                      uVar29 = 1;
                      if (0 < (int)local_1080) {
                        uVar29 = local_1080;
                      }
                      uVar33 = uVar29 >> 3;
                      uVar16 = uVar33 << 3;
                      if ((uVar33 == 0) ||
                         (ppVar23 <= ppVar20 + uVar29 &&
                          ppVar20 <= (portable_samplepair_t *)((int)&ppVar23->left + uVar29 * 2) ||
                          uVar29 < 8)) {
                        uVar16 = 0;
                      }
                      else {
                        uVar28 = 0;
                        ppVar17 = ppVar20;
                        do {
                          iVar35 = ppVar17[3].left;
                          iVar3 = ppVar17[3].right;
                          iVar31 = ppVar17[6].left;
                          iVar30 = ppVar17[6].right;
                          iVar6 = ppVar17[7].left;
                          iVar21 = ppVar17[7].right;
                          auVar2 = *(undefined1 (*) [16])(ppVar23 + uVar28 * 2);
                          auVar39 = SUB1614((undefined1  [16])0x0,2);
                          auVar47._0_12_ = auVar2._0_12_;
                          auVar47._12_2_ = auVar2._6_2_;
                          auVar47._14_2_ = -(ushort)(auVar2._6_2_ < 0);
                          auVar46._12_4_ = auVar47._12_4_;
                          auVar46._0_10_ = auVar2._0_10_;
                          auVar46._10_2_ = -(ushort)(auVar2._4_2_ < 0);
                          auVar45._10_6_ = auVar46._10_6_;
                          auVar45._0_8_ = auVar2._0_8_;
                          auVar45._8_2_ = auVar2._4_2_;
                          uVar48 = auVar45._8_8_;
                          auVar11._4_8_ = uVar48;
                          auVar11._2_2_ = -(ushort)(auVar2._2_2_ < 0);
                          auVar11._0_2_ = auVar2._2_2_;
                          iVar44 = CONCAT22(-(ushort)(auVar2._0_2_ < 0),auVar2._0_2_);
                          local_10bc = CONCAT22(-(ushort)(auVar2._8_2_ < 0),auVar2._8_2_);
                          uVar40 = CONCAT24(auVar2._10_2_,local_10bc);
                          auVar42._0_8_ = CONCAT26(-(ushort)(auVar2._10_2_ < auVar39._8_2_),uVar40);
                          auVar42._8_2_ = auVar2._12_2_;
                          auVar42._10_2_ = -(ushort)(auVar2._12_2_ < auVar39._10_2_);
                          auVar43._12_2_ = auVar2._14_2_;
                          auVar43._0_12_ = auVar42;
                          auVar43._14_2_ = -(ushort)(auVar2._14_2_ < auVar39._12_2_);
                          iVar26 = ppVar17[4].left;
                          iVar7 = ppVar17[4].right;
                          iVar8 = ppVar17[5].left;
                          iVar9 = ppVar17[5].right;
                          auVar5._4_4_ = uVar27;
                          auVar5._0_4_ = uVar27;
                          auVar5._8_4_ = uVar27;
                          auVar5._12_4_ = uVar27;
                          iVar34 = ppVar17[1].left;
                          iVar19 = ppVar17[1].right;
                          local_10bc = uVar27 * local_10bc;
                          iStack_10b4 = uVar27 * auVar42._8_4_;
                          iVar49 = (int)((ulonglong)auVar42._0_8_ >> 0x20);
                          uVar28 = uVar28 + 1;
                          iVar50 = iStack_10b4 >> 8;
                          iStack_10b4 = local_1074 * auVar45._8_4_;
                          auVar2._4_4_ = local_1074;
                          auVar2._0_4_ = local_1074;
                          auVar2._8_4_ = local_1074;
                          auVar2._12_4_ = local_1074;
                          pVar41.right = ((int)(local_1074 * iVar44) >> 8) + ppVar17->right;
                          pVar41.left = ((int)(uVar27 * iVar44) >> 8) + ppVar17->left;
                          ppVar17[2].left =
                               ((int)((auVar5._8_8_ & 0xffffffff) * (uVar48 & 0xffffffff)) >> 8) +
                               ppVar17[2].left;
                          ppVar17[2].right = (iStack_10b4 >> 8) + ppVar17[2].right;
                          ppVar17[3].left =
                               ((int)((uVar48 >> 0x20) * (ulonglong)uVar27) >> 8) + iVar35;
                          ppVar17[3].right =
                               ((int)((uVar48 >> 0x20) * (ulonglong)local_1074) >> 8) + iVar3;
                          *ppVar17 = pVar41;
                          ppVar17[1].left = ((int)(auVar11._0_4_ * uVar27) >> 8) + iVar34;
                          ppVar17[1].right = ((int)(auVar11._0_4_ * local_1074) >> 8) + iVar19;
                          pVar38.right = ((int)((ulonglong)local_1074 *
                                               ((ulonglong)uVar40 & 0xffffffff)) >> 8) + iVar7;
                          pVar38.left = (local_10bc >> 8) + iVar26;
                          ppVar17[6].left = iVar50 + iVar31;
                          ppVar17[6].right =
                               ((int)((auVar2._8_8_ & 0xffffffff) * (ulonglong)auVar42._8_4_) >> 8)
                               + iVar30;
                          ppVar17[7].left = ((int)(uVar27 * auVar43._12_4_) >> 8) + iVar6;
                          ppVar17[7].right = ((int)(auVar43._12_4_ * local_1074) >> 8) + iVar21;
                          ppVar17[4] = pVar38;
                          ppVar17[5].left = ((int)(uVar27 * iVar49) >> 8) + iVar8;
                          ppVar17[5].right = ((int)(iVar49 * local_1074) >> 8) + iVar9;
                          ppVar17 = ppVar17 + 8;
                        } while (uVar28 < uVar33);
                        if (uVar16 == uVar29) goto LAB_001fffa0;
                      }
                      do {
                        iVar34 = (int)*(short *)((int)&ppVar23->left + uVar16 * 2);
                        ppVar20[uVar16].left = ppVar20[uVar16].left + ((int)(uVar27 * iVar34) >> 8);
                        piVar1 = (int *)(iVar32 * 8 + 0x13631e4 + uVar16 * 8);
                        *piVar1 = *piVar1 + ((int)(iVar34 * local_1074) >> 8);
                        uVar16 = uVar16 + 1;
                      } while ((int)uVar16 < (int)local_1080);
                    }
LAB_001fffa0:
                    local_107c->pos = local_1080 + local_1064;
                    bVar4 = false;
                  }
                  local_1070 = local_1070 + ((int)local_1080 >> bVar36);
                  local_107c->leftvol = uVar24;
                  local_107c->rightvol = uVar25;
                  if (local_107c->entchannel == 5) {
                    local_1058->csamplesplayed = local_1058->csamplesplayed + local_1080;
                  }
                }
                if ((iVar22 <= local_1070) || (bVar10 = false, bVar4)) {
                  qVar18 = S_CheckWavEnd(local_107c,local_2c,local_1070,local_105c);
                  iVar22 = total_channels;
                  if (qVar18 != false) break;
                  bVar10 = false;
                }
              }
            }
          }
        }
      }
      local_105c = local_105c + 1;
      local_107c = local_107c + 1;
      local_1058 = local_1058 + 1;
    } while (local_105c < iVar22);
  }
  return;
}


// S_PaintChannels  @ 00200850
void S_PaintChannels(int endtime)

{
  int *piVar1;
  portable_samplepair_t *ppVar2;
  float fVar3;
  portable_samplepair_t *ppVar4;
  int extraout_ECX;
  int iVar5;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_EDX;
  int iVar6;
  int *piVar7;
  qboolean fFilter;
  int extraout_EDX_00;
  qboolean extraout_EDX_01;
  int end;
  int count;
  
  while (paintedtime < endtime) {
    count = endtime - paintedtime;
    end = endtime;
    if (0x200 < count) {
      count = 0x200;
      end = paintedtime + 0x200;
    }
    Q_memset(paintbuffer,0,count * 8);
    iVar5 = extraout_ECX;
    iVar6 = extraout_EDX;
    if ((cl.paused == false) && (s_careerAudioPaused == 0)) {
      S_MixChannelsToPaintbuffer(end,0,0);
      iVar5 = extraout_ECX_00;
      iVar6 = extraout_EDX_00;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count2x@[???] */
                    /* Unresolved local var: float roomType@[???]
                       Unresolved local var: int fReset@[???]
                       Unresolved local var: int i@[???] */
    if ((hisound.value == 0.0) && (sxroom_off.value == 0.0)) {
      SX_RoomFX(count,iVar6,iVar5);
    }
    fVar3 = hisound.value;
    iVar5 = count * 2 + -1;
    if (0 < count + -1) {
      ppVar4 = paintbuffer + count + -1;
      piVar7 = (int *)(count * 0x10 + 0x13631d0);
      do {
        iVar6 = ppVar4->right;
        piVar7[2] = ppVar4->left;
        piVar7[3] = iVar6;
        *piVar7 = ppVar4->left + ppVar4[-1].left >> 1;
        piVar1 = &ppVar4->right;
        ppVar2 = ppVar4 + -1;
        ppVar4 = ppVar4 + -1;
        piVar7[1] = *piVar1 + ppVar2->right >> 1;
        piVar7 = piVar7 + -4;
      } while (ppVar4 != paintbuffer);
    }
    paintbuffer[1].left = paintbuffer[0].left;
    paintbuffer[1].right = paintbuffer[0].right;
    paintbuffer[0].left = S_PaintChannels::paintprev.left + paintbuffer[0].left >> 1;
    paintbuffer[0].right = S_PaintChannels::paintprev.right + paintbuffer[0].right >> 1;
    S_PaintChannels::paintprev.left = paintbuffer[iVar5].left;
    S_PaintChannels::paintprev.right = paintbuffer[iVar5].right;
    if (0.0 < fVar3) {
      fFilter = cl.paused;
      if ((cl.paused == false) && (s_careerAudioPaused == 0)) {
        S_MixChannelsToPaintbuffer(end,1,0);
        iVar5 = extraout_ECX_01;
        fFilter = extraout_EDX_01;
      }
                    /* Unresolved local var: float roomType@[???]
                       Unresolved local var: int fReset@[???]
                       Unresolved local var: int i@[???] */
      if (sxroom_off.value == 0.0) {
        SX_RoomFX(count * 2,fFilter,iVar5);
      }
    }
    if ((cl.paused == false) && (s_careerAudioPaused == 0)) {
      S_MixChannelsToPaintbuffer(end,1,1);
    }
    S_TransferStereo16(end);
    paintedtime = end;
  }
  return;
}


// S_Play  @ 001f79c0
/* WARNING: Variable defined which should be unmapped: sfx */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_Play(void)

{
  int iVar1;
  char *pcVar2;
  sfx_t *s;
  int *pfInCache;
  int arg;
  float attenuation;
  int in_stack_fffffee0;
  int in_stack_fffffee4;
  sfx_t *sfx;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: sfx_t * sfx@[???] */
  if (speak_enable.value != 0.0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[256] name@[???] */
    iVar1 = Cmd_Argc();
    arg = 1;
    if (1 < iVar1) {
      do {
        pcVar2 = Cmd_Argv(arg);
        attenuation = 3.51726e-43;
        Q_strncpy(&stack0xfffffee4,pcVar2,0xfb);
        pcVar2 = Cmd_Argv(arg);
        pcVar2 = Q_strrchr(pcVar2,'.');
        if (pcVar2 == (char *)0x0) {
          Q_strcat(&stack0xfffffee4,".wav");
        }
                    /* Unresolved local var: sfx_t * sfx@[???] */
        if ((sound_started == 0) || (nosound.value != 0.0)) {
          S_Play::hash = S_Play::hash + 1;
        }
        else {
          iVar1 = Q_strlen(&stack0xfffffee4);
          if (iVar1 < 0x40) {
            if (((char)in_stack_fffffee4 == '!') || ((char)in_stack_fffffee4 == '*')) {
                    /* Unresolved local var: sfx_t * sfx@[???] */
              s = S_FindName(&stack0xfffffee4,pfInCache);
            }
            else {
              s = S_FindName(&stack0xfffffee4,pfInCache);
              if (fs_lazy_precache.value == 0.0) {
                S_LoadSound(s,(channel_t *)0x0);
              }
            }
          }
          else {
            s = (sfx_t *)0x0;
          }
          iVar1 = S_Play::hash;
                    /* Unresolved local var: channel_t * target_chan@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: channel_t * check@[???]
                       Unresolved local var: int vol@[???]
                       Unresolved local var: int ch_idx@[???]
                       Unresolved local var: int skip@[???]
                       Unresolved local var: int fsentence@[???] */
          S_Play::hash = S_Play::hash + 1;
          if (((sound_started != 0) && (s != (sfx_t *)0x0)) && (nosound.value == 0.0)) {
            S_StartDynamicSound(iVar1,0,s,listener_origin,1.0,attenuation,in_stack_fffffee0,
                                in_stack_fffffee4);
          }
        }
        arg = arg + 1;
        iVar1 = Cmd_Argc();
      } while (arg < iVar1);
    }
  }
  return;
}


// S_PlayVol  @ 001f7b90
/* WARNING: Variable defined which should be unmapped: sfx */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_PlayVol(void)

{
  int iVar1;
  char *pcVar2;
  int *pfInCache;
  int arg;
  sfx_t *s;
  float fvol;
  float attenuation;
  int in_stack_fffffee0;
  int in_stack_fffffee4;
  sfx_t *sfx;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float vol@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: sfx_t * sfx@[???] */
  if (speak_enable.value != 0.0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float vol@[???]
                       Unresolved local var: char[256] name@[???] */
    for (arg = 1; iVar1 = Cmd_Argc(), arg < iVar1; arg = arg + 2) {
      pcVar2 = Cmd_Argv(arg);
      attenuation = 3.51726e-43;
      Q_strncpy(&stack0xfffffee4,pcVar2,0xfb);
      pcVar2 = Cmd_Argv(arg);
      pcVar2 = Q_strrchr(pcVar2,'.');
      if (pcVar2 == (char *)0x0) {
        Q_strcat(&stack0xfffffee4,".wav");
      }
      s = (sfx_t *)0x0;
      if (sound_started != 0) {
        if (nosound.value == 0.0) {
          iVar1 = Q_strlen(&stack0xfffffee4);
          if (iVar1 < 0x40) {
                    /* Unresolved local var: sfx_t * sfx@[???] */
            if (((char)in_stack_fffffee4 == '!') || ((char)in_stack_fffffee4 == '*')) {
                    /* Unresolved local var: sfx_t * sfx@[???] */
              s = S_FindName(&stack0xfffffee4,pfInCache);
            }
            else {
              s = S_FindName(&stack0xfffffee4,pfInCache);
              if (fs_lazy_precache.value == 0.0) {
                S_LoadSound(s,(channel_t *)0x0);
              }
            }
          }
        }
        else {
          s = (sfx_t *)0x0;
        }
      }
      pcVar2 = Cmd_Argv(arg + 1);
      fvol = Q_atof(pcVar2);
      iVar1 = S_PlayVol::hash;
                    /* Unresolved local var: channel_t * target_chan@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: channel_t * check@[???]
                       Unresolved local var: int vol@[???]
                       Unresolved local var: int ch_idx@[???]
                       Unresolved local var: int skip@[???]
                       Unresolved local var: int fsentence@[???] */
      S_PlayVol::hash = S_PlayVol::hash + 1;
      if (((sound_started != 0) && (s != (sfx_t *)0x0)) && (nosound.value == 0.0)) {
        S_StartDynamicSound(iVar1,0,s,listener_origin,fvol,attenuation,in_stack_fffffee0,
                            in_stack_fffffee4);
      }
    }
  }
  return;
}


// S_PrecacheSound  @ 001f6050
sfx_t * S_PrecacheSound(char *name)

{
  byte bVar1;
  int iVar2;
  sfx_t *psVar3;
  
                    /* Unresolved local var: sfx_t * sfx@[???] */
  if (((sound_started != 0) && (nosound.value == 0.0)) && (iVar2 = Q_strlen(name), iVar2 < 0x40)) {
    bVar1 = *name;
    if ((bVar1 != 0x21) && (bVar1 != 0x2a)) {
      psVar3 = S_FindName(name,(int *)(uint)bVar1);
      if (fs_lazy_precache.value != 0.0) {
        return psVar3;
      }
      S_LoadSound(psVar3,(channel_t *)0x0);
      return psVar3;
    }
                    /* Unresolved local var: sfx_t * sfx@[???] */
    psVar3 = S_FindName(name,(int *)(uint)bVar1);
    return psVar3;
  }
  return (sfx_t *)0x0;
}


// S_PrintStats  @ 001f93c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_PrintStats(void)

{
  vec_t *v;
  int iVar1;
  int iVar2;
  sfx_t *psVar3;
  char *pcVar4;
  channel_t *pcVar5;
  uint uVar6;
  uint uVar7;
  
                    /* Unresolved local var: channel_t * ch@[???]
                       Unresolved local var: int i@[???] */
  if (((s_show.value != 0.0) && (cl.maxclients < 3)) && (0 < total_channels)) {
    pcVar5 = channels;
    uVar6 = 0;
    do {
      while (psVar3 = pcVar5->sfx, psVar3 == (sfx_t *)0x0) {
        uVar7 = uVar6 + 1;
        pcVar5 = pcVar5 + 1;
        Con_NPrintf(uVar6 & 0x1f,"");
        uVar6 = uVar7;
        if (total_channels <= (int)uVar7) {
          return;
        }
      }
      iVar1 = pcVar5->entchannel;
      v = pcVar5->origin;
      iVar2 = pcVar5->entnum;
      pcVar5 = pcVar5 + 1;
      pcVar4 = vstr(v);
      uVar7 = uVar6 + 1;
      Con_NPrintf(uVar6 & 0x1f,"%s %03i %02i %20s",pcVar4,iVar2,iVar1,psVar3);
      uVar6 = uVar7;
    } while ((int)uVar7 < total_channels);
  }
  return;
}


// S_QuerySoundSetting  @ 001f5910
qboolean S_QuerySoundSetting(char *pszCvar,qboolean bDefault)

{
  byte *p;
  byte *data;
  int iVar1;
  char *data_00;
  long lVar2;
  char local_120 [272];
  
                    /* Unresolved local var: char[260] szFile@[???]
                       Unresolved local var: char * pbuffer@[???]
                       Unresolved local var: char * pstart@[???]
                       Unresolved local var: qboolean bResult@[???] */
  snprintf(local_120,0x104,"config.cfg");
  p = COM_LoadFile(local_120,5,(int *)0x0);
  data = p;
  if (p != (byte *)0x0) {
    while( true ) {
      data = (byte *)COM_Parse((char *)data);
      iVar1 = Q_strlen(com_token);
      if (iVar1 < 1) break;
      iVar1 = Q_stricmp(com_token,"bind");
      if (iVar1 == 0) {
        data_00 = COM_Parse((char *)data);
        data = (byte *)COM_Parse(data_00);
      }
      else if (com_token[0] != '+') {
        iVar1 = Q_stricmp(com_token,pszCvar);
        if (iVar1 == 0) {
          COM_Parse((char *)data);
          lVar2 = strtol(com_token,(char **)0x0,10);
          bDefault = (qboolean)(lVar2 != 0);
          break;
        }
        data = (byte *)COM_Parse((char *)data);
      }
    }
    Mem_Free(p);
  }
  return bDefault;
}


// S_Say  @ 001f7d60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_Say(void)

{
  int iVar1;
  char *pcVar2;
  int32 iVar3;
  time_t tVar4;
  time_t tVar5;
  int iVar6;
  sfx_t *psVar7;
  int *pfInCache;
  int *pfInCache_00;
  int *pfInCache_01;
  float attenuation;
  char *attenuation_00;
  int in_stack_fffffee0;
  float fVar8;
  char local_10c [8];
  undefined1 local_104;
  undefined1 local_d;
  
                    /* Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: char[256] sound@[???] */
  fVar8 = 0.0;
  if ((((nosound.value == 0.0) && (sound_started != 0)) && (iVar1 = Cmd_Argc(), 1 < iVar1)) &&
     (speak_enable.value != fVar8)) {
                    /* Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: char[256] sound@[???] */
    pcVar2 = Cmd_Argv(1);
    attenuation = 3.57331e-43;
    Q_strncpy(local_10c,pcVar2,0xff);
    local_d = 0;
    iVar1 = Q_strcmp(local_10c,"dsp");
    if (iVar1 == 0) {
      iVar1 = 0;
      do {
                    /* Unresolved local var: DWORD time@[DW_OP_reg3(EBX)]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
        iVar3 = RandomLong(0,2999);
        paintbuffer[iVar1].left = iVar3;
        iVar3 = RandomLong(0,2999);
        paintbuffer[iVar1].right = iVar3;
        iVar1 = iVar1 + 1;
      } while (iVar1 != 0x200);
      iVar1 = 10000;
      Con_Printf("Start profiling 10,000 calls to DSP\n");
      tVar4 = time((time_t *)0x0);
      do {
        SX_RoomFX(0x200,1,1);
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      tVar5 = time((time_t *)0x0);
      Con_Printf("%d milliseconds \n",tVar5 - tVar4);
    }
    else {
      iVar6 = Q_strcmp(local_10c,"paint");
      iVar1 = paintedtime;
      if (iVar6 == 0) {
                    /* Unresolved local var: DWORD time@[???]
                       Unresolved local var: sfx_t * sfx@[DW_OP_reg1(ECX)]
                       Unresolved local var: int psav@[???]
                       Unresolved local var: int count@[???] */
        Con_Printf("Start profiling S_PaintChannels\n");
                    /* Unresolved local var: sfx_t * sfx@[???] */
        if ((sound_started == 0) || (nosound.value != 0.0)) {
          S_Say::lexical_block_1::hash = S_Say::lexical_block_1::hash + 1;
        }
        else {
          iVar6 = Q_strlen("ambience/labdrone1.wav");
          if (iVar6 < 0x40) {
            psVar7 = S_FindName("ambience/labdrone1.wav",pfInCache_01);
            if (fs_lazy_precache.value == 0.0) {
              S_LoadSound(psVar7,(channel_t *)0x0);
            }
          }
          else {
            psVar7 = (sfx_t *)0x0;
          }
          iVar6 = S_Say::lexical_block_1::hash;
                    /* Unresolved local var: channel_t * target_chan@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: channel_t * check@[???]
                       Unresolved local var: int vol@[???]
                       Unresolved local var: int ch_idx@[???]
                       Unresolved local var: int skip@[???]
                       Unresolved local var: int fsentence@[???] */
          S_Say::lexical_block_1::hash = S_Say::lexical_block_1::hash + 1;
          if (((sound_started != 0) && (psVar7 != (sfx_t *)0x0)) && (nosound.value == 0.0)) {
            S_StartDynamicSound(iVar6,0,psVar7,listener_origin,1.0,attenuation,in_stack_fffffee0,
                                (int)fVar8);
          }
        }
        tVar4 = time((time_t *)0x0);
        S_PaintChannels(paintedtime + 0x4e2000);
        tVar5 = time((time_t *)0x0);
        Con_Printf("%d milliseconds \n",tVar5 - tVar4);
        paintedtime = iVar1;
      }
      else if (local_10c[0] == '!') {
        psVar7 = S_FindName(local_10c,pfInCache);
        if (psVar7 == (sfx_t *)0x0) {
          Con_Printf("S_Say: can\'t find sentence name %s\n",local_10c);
        }
        else {
                    /* Unresolved local var: channel_t * target_chan@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: channel_t * check@[???]
                       Unresolved local var: int vol@[???]
                       Unresolved local var: int ch_idx@[???]
                       Unresolved local var: int skip@[???]
                       Unresolved local var: int fsentence@[???] */
          if ((sound_started != 0) && (nosound.value == 0.0)) {
            S_StartDynamicSound(cl.viewentity,-1,psVar7,vec3_origin,1.0,attenuation,
                                in_stack_fffffee0,(int)fVar8);
          }
        }
      }
      else {
        pcVar2 = Cmd_Argv(1);
        attenuation_00 = "xxtestxx %s";
        snprintf(local_10c,0x100,"xxtestxx %s");
        local_104 = 0;
        rgpszrawsentence[cszrawsentences] = local_10c;
        cszrawsentences = cszrawsentences + 1;
                    /* Unresolved local var: sfx_t * sfx@[???] */
                    /* Unresolved local var: sfx_t * sfx@[???] */
        if ((((sound_started == 0) || (fVar8 = 0.0, nosound.value != 0.0)) ||
            (iVar1 = Q_strlen("!xxtestxx"), 0x3f < iVar1)) ||
           (psVar7 = S_FindName("!xxtestxx",pfInCache_00), psVar7 == (sfx_t *)0x0)) {
          Con_Printf("S_Say: can\'t cache %s\n",local_10c);
        }
        else {
                    /* Unresolved local var: channel_t * target_chan@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: channel_t * check@[???]
                       Unresolved local var: int vol@[???]
                       Unresolved local var: int ch_idx@[???]
                       Unresolved local var: int skip@[???]
                       Unresolved local var: int fsentence@[???] */
          if ((sound_started != 0) && (nosound.value == fVar8)) {
            S_StartDynamicSound(cl.viewentity,-1,psVar7,vec3_origin,1.0,(float)attenuation_00,
                                (int)pcVar2,(int)fVar8);
          }
          cszrawsentences = cszrawsentences + -1;
          rgpszrawsentence[cszrawsentences] = (char *)0x0;
        }
      }
    }
  }
  return;
}


// S_Say_Reliable  @ 001f7430
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_Say_Reliable(void)

{
  int iVar1;
  char *pcVar2;
  sfx_t *psVar3;
  sfx_t *sfxin;
  sfx_t *sfxin_00;
  int *pfInCache;
  int *pfInCache_00;
  vec_t *origin;
  char *origin_00;
  float fVar4;
  char *attenuation;
  int in_stack_fffffee0;
  float pitch;
  char local_10c [8];
  undefined1 local_104;
  undefined1 local_d;
  
                    /* Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: char[256] sound@[???] */
  pitch = 0.0;
  if ((((nosound.value == 0.0) && (sound_started != 0)) && (iVar1 = Cmd_Argc(), 1 < iVar1)) &&
     (speak_enable.value != pitch)) {
                    /* Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: char[256] sound@[???] */
    pcVar2 = Cmd_Argv(1);
    fVar4 = 3.57331e-43;
    origin = (vec_t *)local_10c;
    Q_strncpy(local_10c,pcVar2,0xff);
    local_d = 0;
    if (local_10c[0] == '!') {
      psVar3 = S_FindName(local_10c,pfInCache);
      if (psVar3 == (sfx_t *)0x0) {
        Con_Printf("S_Say_Reliable: can\'t find sentence name %s\n",local_10c);
      }
      else {
        S_StartStaticSound(cl.viewentity,(int)psVar3,sfxin_00,origin,(float)pcVar2,fVar4,
                           in_stack_fffffee0,(int)pitch);
      }
    }
    else {
      pcVar2 = Cmd_Argv(1);
      attenuation = "xxtestxx %s";
      fVar4 = 3.58732e-43;
      snprintf(local_10c,0x100,"xxtestxx %s");
      local_104 = 0;
      rgpszrawsentence[cszrawsentences] = local_10c;
      cszrawsentences = cszrawsentences + 1;
                    /* Unresolved local var: sfx_t * sfx@[???] */
      if ((sound_started != 0) && (nosound.value == 0.0)) {
        origin_00 = "!xxtestxx";
        iVar1 = Q_strlen("!xxtestxx");
                    /* Unresolved local var: sfx_t * sfx@[???] */
        if ((iVar1 < 0x40) &&
           (psVar3 = S_FindName("!xxtestxx",pfInCache_00), psVar3 != (sfx_t *)0x0)) {
          S_StartStaticSound(cl.viewentity,(int)psVar3,sfxin,(vec_t *)origin_00,fVar4,
                             (float)attenuation,(int)pcVar2,(int)pitch);
          cszrawsentences = cszrawsentences + -1;
          rgpszrawsentence[cszrawsentences] = (char *)0x0;
          return;
        }
      }
      Con_Printf("S_Say_Reliable: can\'t cache %s\n",local_10c);
    }
  }
  return;
}


// S_Shutdown  @ 001f5d40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_Shutdown(void)

{
  VOX_Shutdown();
  if (sound_started != 0) {
    if (shm != (dma_t *)0x0) {
      shm->gamealive = false;
    }
    shm = (dma_t *)0x0;
    sound_started = 0;
    if (fakedma == false) {
      SNDDMA_Shutdown();
      return;
    }
  }
  return;
}


// S_SoundInfo_f  @ 001f54d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_SoundInfo_f(void)

{
  if ((sound_started != 0) && (shm != (dma_t *)0x0)) {
    Con_Printf("%5d stereo\n",shm->channels + -1);
    Con_Printf("%5d samples\n",shm->samples);
    Con_Printf("%5d samplepos\n",shm->samplepos);
    Con_Printf("%5d samplebits\n",shm->samplebits);
    Con_Printf("%5d submission_chunk\n",shm->submission_chunk);
    Con_Printf("%5d speed\n",shm->speed);
    Con_Printf("0x%x dma buffer\n",shm->buffer);
    Con_Printf("%5d total_channels\n",total_channels);
    return;
  }
  Con_Printf("sound system not started\n");
  return;
}


// S_SoundList  @ 001f5410
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_SoundList(void)

{
  int *piVar1;
  int iVar2;
  sfx_t *psVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int total@[???] */
  iVar5 = 0;
  if (0 < num_sfx) {
    iVar4 = 0;
    psVar3 = known_sfx;
    do {
      piVar1 = Cache_Check(&psVar3->cache);
      if (piVar1 != (int *)0x0) {
        iVar2 = *piVar1 * piVar1[3] * (piVar1[4] + 1);
        iVar5 = iVar5 + iVar2;
        if (piVar1[1] < 0) {
          Con_Printf(" ");
        }
        else {
          Con_Printf("L");
        }
        Con_Printf("(%2db) %6i : %s\n",piVar1[3] << 3,iVar2,psVar3);
      }
      iVar4 = iVar4 + 1;
      psVar3 = psVar3 + 1;
    } while (iVar4 < num_sfx);
  }
  Con_Printf("Total resident: %i\n",iVar5);
  return;
}


// S_StartDynamicSound  @ 001f75d0
void __regparm3
S_StartDynamicSound(int entnum,int entchannel,sfx_t *sfx,vec_t *origin,float fvol,float attenuation,
                   int flags,int pitch)

{
  char cVar1;
  float fVar2;
  channel_t *ch;
  sfxcache_t *sc;
  int32 iVar3;
  int pitch_00;
  int iVar4;
  char local_5c [63];
  undefined1 local_1d;
  
                    /* Unresolved local var: channel_t * target_chan@[???]
                       Unresolved local var: channel_t * check@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int vol@[???]
                       Unresolved local var: int ch_idx@[???]
                       Unresolved local var: int skip@[???]
                       Unresolved local var: int fsentence@[???] */
  iVar4 = (int)(fvol * 255.0);
  if (sfx->name[0] == '*') {
    entchannel = 5;
  }
  if (0xff < iVar4) {
    iVar4 = 0xff;
    Con_DPrintf("S_StartDynamicSound: %s volume > 255",sfx);
  }
  fVar2 = sys_timescale.value;
  ch = SND_PickDynamicChannel(entnum,entchannel,sfx);
  if (ch == (channel_t *)0x0) {
    return;
  }
  pitch_00 = (int)((fVar2 + 1.0) * 0.5 * 100.0);
  cVar1 = sfx->name[0];
  Q_memset(ch,0,0x40);
  ch->origin[0] = *origin;
  ch->origin[1] = origin[1];
  ch->origin[2] = origin[2];
  fVar2 = 1.0 / sound_nominal_clip_dist;
  ch->master_vol = iVar4;
  ch->entnum = entnum;
  ch->entchannel = entchannel;
  ch->pitch = pitch_00;
  ch->isentence = -1;
  ch->dist_mult = fVar2;
  SND_Spatialize(ch);
  if (((ch->leftvol == 0) && (ch->rightvol == 0)) && (entchannel != 5)) {
LAB_001f76f4:
    ch->sfx = (sfx_t *)0x0;
    return;
  }
  if (cVar1 == '#' || cVar1 == '!') {
                    /* Unresolved local var: char[64] name@[???] */
    Q_strncpy(local_5c,sfx->name + 1,0x3f);
    local_1d = 0;
    sc = VOX_LoadSound(ch,local_5c);
  }
  else {
    sc = S_LoadSound(sfx,ch);
    ch->sfx = sfx;
  }
  if (sc == (sfxcache_t *)0x0) goto LAB_001f76f4;
  ch->pos = 0;
  ch->end = sc->length + paintedtime;
  if ((pitch_00 != 100) && (cVar1 != '#' && cVar1 != '!')) {
    VOX_MakeSingleWordSentence(ch,pitch_00);
  }
  VOX_TrimStartEndTimes(ch,sc);
  SND_InitMouth(entnum,entchannel);
  if (ch == channels + 4) {
LAB_001f77aa:
    if ((sfx == channels[5].sfx) && (channels[5].pos == 0)) goto LAB_001f7840;
    if (ch != channels + 6) goto LAB_001f77be;
LAB_001f77d2:
    if ((sfx == channels[7].sfx) && (channels[7].pos == 0)) goto LAB_001f7840;
    if (ch != channels + 8) goto LAB_001f77e6;
LAB_001f77fa:
    if ((sfx == channels[9].sfx) && (channels[9].pos == 0)) goto LAB_001f7840;
    if (ch != channels + 10) goto LAB_001f780e;
  }
  else {
    if ((sfx == channels[4].sfx) && (channels[4].pos == 0)) goto LAB_001f7840;
    if (ch != channels + 5) goto LAB_001f77aa;
LAB_001f77be:
    if ((sfx == channels[6].sfx) && (channels[6].pos == 0)) goto LAB_001f7840;
    if (ch != channels + 7) goto LAB_001f77d2;
LAB_001f77e6:
    if ((sfx == channels[8].sfx) && (channels[8].pos == 0)) goto LAB_001f7840;
    if (ch != channels + 9) goto LAB_001f77fa;
LAB_001f780e:
    if ((sfx == channels[10].sfx) && (channels[10].pos == 0)) goto LAB_001f7840;
    if (ch == channels + 0xb) {
      return;
    }
  }
  if (sfx != channels[0xb].sfx) {
    return;
  }
  if (channels[0xb].pos != 0) {
    return;
  }
LAB_001f7840:
  iVar3 = RandomLong(0,(int)((double)shm->speed * 0.1));
  iVar4 = ch->end;
  if (iVar4 <= iVar3) {
    iVar3 = iVar4 + -1;
  }
  ch->pos = ch->pos + iVar3;
  ch->end = iVar4 - iVar3;
  return;
}


// S_StartDynamicSound  @ 001f82a0
void S_StartDynamicSound(int entnum,int entchannel,sfx_t *sfx,vec_t *origin,float fvol,
                        float attenuation,int flags,int pitch)

{
  char cVar1;
  float fVar2;
  channel_t *ch;
  sfxcache_t *sc;
  int32 iVar3;
  int iVar4;
  int iVar5;
  char local_5c [63];
  undefined1 local_1d;
  
                    /* Unresolved local var: channel_t * target_chan@[???]
                       Unresolved local var: channel_t * check@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int vol@[???]
                       Unresolved local var: int ch_idx@[???]
                       Unresolved local var: int skip@[???]
                       Unresolved local var: int fsentence@[???] */
  if (sound_started == 0) {
    return;
  }
  if (sfx == (sfx_t *)0x0) {
    return;
  }
  if (nosound.value != 0.0) {
    return;
  }
                    /* Unresolved local var: channel_t * target_chan@[???]
                       Unresolved local var: channel_t * check@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int vol@[???]
                       Unresolved local var: int ch_idx@[???]
                       Unresolved local var: int skip@[???]
                       Unresolved local var: int fsentence@[???] */
  if (sfx->name[0] == '*') {
    entchannel = 5;
LAB_001f85cc:
    if (pitch != 100) {
      pitch = 100;
      Con_DPrintf("Warning: pitch shift ignored on stream sound %s\n",sfx);
    }
  }
  else if (entchannel == 5) goto LAB_001f85cc;
  iVar4 = (int)(fvol * 255.0);
  if (0xff < iVar4) {
    Con_DPrintf("S_StartDynamicSound: %s volume > 255",sfx);
    iVar4 = 0xff;
  }
  if ((flags & 0xe0U) != 0) {
    iVar5 = S_AlterChannel(entnum,entchannel,sfx,iVar4,pitch,flags);
    if (iVar5 != 0) {
      return;
    }
    if ((flags & 0x20U) != 0) {
      return;
    }
  }
  fVar2 = sys_timescale.value;
  if (pitch == 0) {
    Con_DPrintf("Warning: S_StartDynamicSound Ignored, called with pitch 0");
    return;
  }
  ch = SND_PickDynamicChannel(entnum,entchannel,sfx);
  if (ch == (channel_t *)0x0) {
    return;
  }
  cVar1 = sfx->name[0];
  iVar5 = (int)((fVar2 + 1.0) * 0.5 * (float)pitch);
  Q_memset(ch,0,0x40);
  ch->origin[0] = *origin;
  fVar2 = attenuation / sound_nominal_clip_dist;
  ch->origin[1] = origin[1];
  ch->origin[2] = origin[2];
  ch->dist_mult = fVar2;
  ch->pitch = iVar5;
  ch->isentence = -1;
  ch->master_vol = iVar4;
  ch->entnum = entnum;
  ch->entchannel = entchannel;
  SND_Spatialize(ch);
  if (((ch->leftvol == 0) && (ch->rightvol == 0)) && (entchannel != 5)) {
LAB_001f8686:
    ch->sfx = (sfx_t *)0x0;
    return;
  }
  if (cVar1 != '#' && cVar1 != '!') {
    sc = S_LoadSound(sfx,ch);
    ch->sfx = sfx;
  }
  else {
                    /* Unresolved local var: char[64] name@[???] */
    Q_strncpy(local_5c,sfx->name + 1,0x3f);
    local_1d = 0;
    sc = VOX_LoadSound(ch,local_5c);
  }
  if (sc == (sfxcache_t *)0x0) goto LAB_001f8686;
  ch->pos = 0;
  ch->end = sc->length + paintedtime;
  if ((iVar5 != 100) && (cVar1 != '#' && cVar1 != '!')) {
    VOX_MakeSingleWordSentence(ch,iVar5);
  }
  VOX_TrimStartEndTimes(ch,sc);
  SND_InitMouth(entnum,entchannel);
  if (ch == channels + 4) {
LAB_001f84ec:
    if ((sfx == channels[5].sfx) && (channels[5].pos == 0)) goto LAB_001f86a6;
    if (ch != channels + 6) goto LAB_001f8500;
LAB_001f8514:
    if ((sfx == channels[7].sfx) && (channels[7].pos == 0)) goto LAB_001f86a6;
    if (ch != channels + 8) goto LAB_001f8528;
LAB_001f853c:
    if ((sfx == channels[9].sfx) && (channels[9].pos == 0)) goto LAB_001f86a6;
    if (ch != channels + 10) goto LAB_001f8550;
  }
  else {
    if ((sfx == channels[4].sfx) && (channels[4].pos == 0)) goto LAB_001f86a6;
    if (ch != channels + 5) goto LAB_001f84ec;
LAB_001f8500:
    if ((sfx == channels[6].sfx) && (channels[6].pos == 0)) goto LAB_001f86a6;
    if (ch != channels + 7) goto LAB_001f8514;
LAB_001f8528:
    if ((sfx == channels[8].sfx) && (channels[8].pos == 0)) goto LAB_001f86a6;
    if (ch != channels + 9) goto LAB_001f853c;
LAB_001f8550:
    if ((sfx == channels[10].sfx) && (channels[10].pos == 0)) goto LAB_001f86a6;
    if (ch == channels + 0xb) {
      return;
    }
  }
  if (sfx != channels[0xb].sfx) {
    return;
  }
  if (channels[0xb].pos != 0) {
    return;
  }
LAB_001f86a6:
  iVar3 = RandomLong(0,(int)((double)shm->speed * 0.1));
  iVar4 = ch->end;
  if (iVar4 <= iVar3) {
    iVar3 = iVar4 + -1;
  }
  ch->pos = ch->pos + iVar3;
  ch->end = iVar4 - iVar3;
  return;
}


// S_StartStaticSound  @ 001f7200
void __regparm3
S_StartStaticSound(int entnum,int entchannel,sfx_t *sfxin,vec_t *origin,float fvol,float attenuation
                  ,int flags,int pitch)

{
  char cVar1;
  sfx_t *psVar2;
  float fVar3;
  bool bVar4;
  vec_t vVar5;
  sfxcache_t *sc;
  int iVar6;
  int iVar7;
  int iVar8;
  channel_t *pchan;
  int pitch_00;
  char local_5c [63];
  undefined1 local_1d;
  
                    /* Unresolved local var: channel_t * ch@[DW_OP_reg6(ESI)]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int fvox@[???]
                       Unresolved local var: int vol@[???]
                       Unresolved local var: sfx_t * sfx@[DW_OP_reg2(EDX)] */
  if (entchannel == 0) {
    return;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: channel_t * ch@[???]
                       Unresolved local var: int ch_idx@[???] */
  pitch_00 = (int)((sys_timescale.value + 1.0) * 0.5 * 100.0);
  if (*(char *)entchannel == '*') {
    if (4 < total_channels) {
      iVar7 = 4;
      psVar2 = channels[4].sfx;
      while( true ) {
        if ((sfx_t *)entchannel == psVar2) {
          return;
        }
        iVar7 = iVar7 + 1;
        if (iVar7 == total_channels) break;
        psVar2 = channels[iVar7].sfx;
      }
      iVar7 = 5;
      goto LAB_001f7242;
    }
    iVar7 = 5;
  }
  else {
    iVar7 = 6;
LAB_001f7242:
    if (0xc < total_channels) {
      iVar6 = 0xc;
      psVar2 = channels[0xc].sfx;
      while (psVar2 != (sfx_t *)0x0) {
        iVar8 = iVar6 + 1;
        if (iVar8 == total_channels) {
          if (iVar6 == 0x7f) {
            Con_DPrintf("total_channels == MAX_CHANNELS\n");
            return;
          }
          goto LAB_001f7281;
        }
        iVar6 = iVar8;
        psVar2 = channels[iVar8].sfx;
      }
      cVar1 = *(char *)entchannel;
      pchan = channels + iVar6;
      goto joined_r0x001f7298;
    }
  }
LAB_001f7281:
  cVar1 = *(char *)entchannel;
  pchan = channels + total_channels;
  total_channels = total_channels + 1;
joined_r0x001f7298:
  if ((cVar1 == '#') || (cVar1 == '!')) {
                    /* Unresolved local var: char[64] name@[???] */
    Q_strncpy(local_5c,(char *)(entchannel + 1),0x3f);
    local_1d = 0;
    sc = VOX_LoadSound(pchan,local_5c);
    bVar4 = false;
  }
  else {
    sc = S_LoadSound((sfx_t *)entchannel,pchan);
    pchan->isentence = -1;
    pchan->sfx = (sfx_t *)entchannel;
    bVar4 = true;
  }
  vVar5 = vec3_origin[0];
  if (sc == (sfxcache_t *)0x0) {
    pchan->sfx = (sfx_t *)0x0;
  }
  else {
    fVar3 = 1.0 / sound_nominal_clip_dist;
    pchan->master_vol = 0xff;
    pchan->pos = 0;
    pchan->origin[0] = vVar5;
    pchan->origin[1] = vec3_origin[1];
    pchan->origin[2] = vec3_origin[2];
    pchan->dist_mult = fVar3;
    iVar6 = sc->length + paintedtime;
    pchan->pitch = pitch_00;
    pchan->entnum = entnum;
    pchan->end = iVar6;
    pchan->entchannel = iVar7;
    if ((bVar4) && (pitch_00 != 100)) {
      VOX_MakeSingleWordSentence(pchan,pitch_00);
    }
    VOX_TrimStartEndTimes(pchan,sc);
    SND_Spatialize(pchan);
  }
  return;
}


// S_StartStaticSound  @ 001f87c0
void S_StartStaticSound(int entnum,int entchannel,sfx_t *sfxin,vec_t *origin,float fvol,
                       float attenuation,int flags,int pitch)

{
  char cVar1;
  sfx_t *psVar2;
  vec_t vVar3;
  float fVar4;
  bool bVar5;
  float fVar6;
  sfxcache_t *sc;
  int iVar7;
  int iVar8;
  channel_t *pchan;
  int iVar9;
  char local_5c [63];
  undefined1 local_1d;
  
                    /* Unresolved local var: channel_t * ch@[DW_OP_reg3(EBX)]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int fvox@[???]
                       Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: int vol@[???] */
  if (sfxin == (sfx_t *)0x0) {
    return;
  }
  if (sfxin->name[0] == '*') {
    entchannel = 5;
LAB_001f89cc:
    if (pitch != 100) {
      pitch = 100;
      Con_DPrintf("Warning: pitch shift ignored on stream sound %s\n",sfxin);
    }
  }
  else if (entchannel == 5) goto LAB_001f89cc;
  iVar9 = (int)(fvol * 255.0);
  if (0xff < iVar9) {
    iVar9 = 0xff;
    Con_DPrintf("S_StartStaticSound: %s volume > 255",sfxin);
  }
  if ((flags & 0xe0U) != 0) {
    iVar8 = S_AlterChannel(entnum,entchannel,sfxin,iVar9,pitch,flags);
    if (iVar8 != 0) {
      return;
    }
    if ((flags & 0x20U) != 0) {
      return;
    }
  }
  fVar6 = sys_timescale.value;
  if (pitch == 0) {
    Con_DPrintf("Warning: S_StartStaticSound Ignored, called with pitch 0");
    return;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: channel_t * ch@[???] */
                    /* Unresolved local var: int ch_idx@[???] */
  if (sfxin->name[0] == '*') {
    if (4 < total_channels) {
      iVar8 = 4;
      psVar2 = channels[4].sfx;
      while( true ) {
        if (sfxin == psVar2) {
          return;
        }
        iVar8 = iVar8 + 1;
        if (iVar8 == total_channels) break;
        psVar2 = channels[iVar8].sfx;
      }
      goto LAB_001f884d;
    }
  }
  else {
LAB_001f884d:
    if (0xc < total_channels) {
      iVar8 = 0xc;
      psVar2 = channels[0xc].sfx;
      while (psVar2 != (sfx_t *)0x0) {
        iVar7 = iVar8 + 1;
        if (iVar7 == total_channels) {
          if (iVar8 == 0x7f) {
            Con_DPrintf("total_channels == MAX_CHANNELS\n");
            return;
          }
          goto LAB_001f8891;
        }
        iVar8 = iVar7;
        psVar2 = channels[iVar7].sfx;
      }
      cVar1 = sfxin->name[0];
      pchan = channels + iVar8;
      goto joined_r0x001f88a7;
    }
  }
LAB_001f8891:
  cVar1 = sfxin->name[0];
  pchan = channels + total_channels;
  total_channels = total_channels + 1;
joined_r0x001f88a7:
  if ((cVar1 == '#') || (cVar1 == '!')) {
                    /* Unresolved local var: char[64] name@[???] */
    Q_strncpy(local_5c,sfxin->name + 1,0x3f);
    local_1d = 0;
    sc = VOX_LoadSound(pchan,local_5c);
    bVar5 = false;
  }
  else {
    sc = S_LoadSound(sfxin,pchan);
    pchan->isentence = -1;
    pchan->sfx = sfxin;
    bVar5 = true;
  }
  if (sc == (sfxcache_t *)0x0) {
    pchan->sfx = (sfx_t *)0x0;
  }
  else {
    fVar4 = attenuation / sound_nominal_clip_dist;
    iVar7 = (int)((fVar6 + 1.0) * 0.5 * (float)pitch);
    pchan->origin[0] = *origin;
    pchan->origin[1] = origin[1];
    vVar3 = origin[2];
    pchan->master_vol = iVar9;
    iVar8 = paintedtime;
    pchan->pos = 0;
    pchan->origin[2] = vVar3;
    pchan->dist_mult = fVar4;
    iVar9 = sc->length;
    pchan->pitch = iVar7;
    pchan->end = iVar9 + iVar8;
    pchan->entnum = entnum;
    pchan->entchannel = entchannel;
    if ((bVar5) && (iVar7 != 100)) {
      VOX_MakeSingleWordSentence(pchan,iVar7);
    }
    VOX_TrimStartEndTimes(pchan,sc);
    SND_Spatialize(pchan);
  }
  return;
}


// S_Startup  @ 001f58c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_Startup(void)

{
  qboolean qVar1;
  
                    /* Unresolved local var: int rc@[???] */
  if (snd_initialized != false) {
    if ((fakedma == false) && (qVar1 = SNDDMA_Init(), qVar1 == false)) {
      Con_Printf("S_Startup: SNDDMA_Init failed.\n");
      sound_started = 0;
      return;
    }
    sound_started = 1;
  }
  return;
}


// S_StopAllSounds  @ 001f57c0
void S_StopAllSounds(qboolean clear)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar2 = 0;
  total_channels = 0xc;
  do {
    if (channels[iVar2].sfx != (sfx_t *)0x0) {
      S_FreeChannel(channels + iVar2);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x80);
  Q_memset(channels,0,0x2000);
  Wavstream_Init();
                    /* Unresolved local var: int clear@[???] */
  if ((sound_started != 0) && (shm != (dma_t *)0x0)) {
    iVar2 = 0x80;
    if (shm->samplebits != 8) {
      iVar2 = 0;
    }
    iVar1 = shm->samples * shm->samplebits;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 7;
    }
    Q_memset(shm->buffer,iVar2,iVar1 >> 3);
  }
  return;
}


// S_StopAllSounds  @ 001f8bc0
void S_StopAllSounds(qboolean clear)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (sound_started != 0) {
                    /* Unresolved local var: int i@[???] */
    iVar2 = 0;
    total_channels = 0xc;
    do {
      if (channels[iVar2].sfx != (sfx_t *)0x0) {
        S_FreeChannel(channels + iVar2);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x80);
    Q_memset(channels,0,0x2000);
    Wavstream_Init();
                    /* Unresolved local var: int clear@[???] */
    if (((clear != false) && (sound_started != 0)) && (shm != (dma_t *)0x0)) {
      iVar2 = 0x80;
      if (shm->samplebits != 8) {
        iVar2 = 0;
      }
      iVar1 = shm->samples * shm->samplebits;
      if (iVar1 < 0) {
        iVar1 = iVar1 + 7;
      }
      Q_memset(shm->buffer,iVar2,iVar1 >> 3);
      return;
    }
  }
  return;
}


// S_StopAllSoundsC  @ 001f5880
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_StopAllSoundsC(void)

{
  qboolean in_stack_00000004;
  
                    /* Unresolved local var: int i@[???] */
  if (sound_started != 0) {
    S_StopAllSounds(in_stack_00000004);
    return;
  }
  return;
}


// S_StopSound  @ 001f8b50
void S_StopSound(int entnum,int entchannel)

{
  channel_t *ch;
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (4 < total_channels) {
    iVar2 = 4;
    iVar1 = total_channels;
    do {
      while ((channels[iVar2].entnum != entnum || (channels[iVar2].entchannel != entchannel))) {
        iVar2 = iVar2 + 1;
        if (iVar1 <= iVar2) {
          return;
        }
      }
      ch = channels + iVar2;
      iVar2 = iVar2 + 1;
      S_FreeChannel(ch);
      iVar1 = total_channels;
    } while (iVar2 < total_channels);
  }
  return;
}


// S_TouchSound  @ 001f6020
void S_TouchSound(char *name)

{
  sfx_t *psVar1;
  
                    /* Unresolved local var: sfx_t * sfx@[???] */
  if (sound_started == 0) {
    return;
  }
  psVar1 = S_FindName(name,(int *)sound_started);
  Cache_Check(&psVar1->cache);
  return;
}


// S_TransferPaintBuffer  @ 001f99a0
void S_TransferPaintBuffer(int endtime)

{
  uchar *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  snd_vol = (int)(volume.value * 256.0);
  snd_p = &paintbuffer[0].left;
  puVar1 = shm->buffer;
  for (uVar5 = paintedtime * 2; (int)uVar5 < endtime * 2; uVar5 = uVar5 + (snd_linear_count >> 1)) {
    uVar3 = (shm->samples >> 1) - 1U & uVar5;
    snd_out = (short *)(puVar1 + uVar3 * 4);
    iVar2 = (shm->samples >> 1) - uVar3;
    iVar4 = endtime * 2 - uVar5;
    if (iVar4 < iVar2) {
      iVar2 = iVar4;
    }
    snd_linear_count = iVar2 * 2;
    Snd_WriteLinearBlastStereo16();
    snd_p = snd_p + snd_linear_count;
  }
  return;
}


// S_TransferStereo16  @ 001f9900
void S_TransferStereo16(int end)

{
  uchar *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
                    /* Unresolved local var: int lpos@[???]
                       Unresolved local var: int lpaintedtime@[???]
                       Unresolved local var: DWORD * pbuf@[???]
                       Unresolved local var: int endtime@[???] */
  snd_vol = (int)(volume.value * 256.0);
  snd_p = &paintbuffer[0].left;
  puVar1 = shm->buffer;
  for (uVar5 = paintedtime * 2; (int)uVar5 < end * 2; uVar5 = uVar5 + (snd_linear_count >> 1)) {
    uVar3 = (shm->samples >> 1) - 1U & uVar5;
    snd_out = (short *)(puVar1 + uVar3 * 4);
    iVar2 = (shm->samples >> 1) - uVar3;
    iVar4 = end * 2 - uVar5;
    if (iVar4 < iVar2) {
      iVar2 = iVar4;
    }
    snd_linear_count = iVar2 * 2;
    Snd_WriteLinearBlastStereo16();
    snd_p = snd_p + snd_linear_count;
  }
  return;
}


// S_UnblockSound  @ 002181b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_UnblockSound(void)

{
  snd_blocked = snd_blocked + -1;
  if (snd_blocked == 0) {
    SDL_PauseAudioDevice(m_devId,0);
  }
  return;
}


// S_Update  @ 001f91a0
void S_Update(vec_t *origin,vec_t *forward,vec_t *right,vec_t *up)

{
  int iVar1;
  uint uVar2;
  channel_t *pcVar3;
  int iVar4;
  int iVar5;
  int local_34;
  uint local_30;
  uint local_2c;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int total@[???]
                       Unresolved local var: channel_t * ch@[???]
                       Unresolved local var: channel_t * combine@[???] */
  if ((sound_started != 0) && (snd_blocked < 1)) {
    listener_origin[0] = *origin;
    listener_origin[1] = origin[1];
    listener_origin[2] = origin[2];
    listener_forward[0] = *forward;
    listener_forward[1] = forward[1];
    listener_forward[2] = forward[2];
    listener_right[0] = *right;
    listener_right[1] = right[1];
    listener_right[2] = right[2];
    listener_up[0] = *up;
    listener_up[1] = up[1];
    listener_up[2] = up[2];
    S_UpdateAmbientSounds();
    iVar1 = total_channels;
    if (4 < total_channels) {
      pcVar3 = channels + 4;
      iVar4 = 4;
      do {
        if (pcVar3->sfx != (sfx_t *)0x0) {
          SND_Spatialize(pcVar3);
          iVar1 = total_channels;
        }
        iVar4 = iVar4 + 1;
        pcVar3 = pcVar3 + 1;
      } while (iVar4 < iVar1);
    }
    if (snd_show.value != 0.0) {
      iVar4 = 0;
      if (0 < iVar1) {
        pcVar3 = channels;
        iVar5 = 0;
        do {
          if (pcVar3->sfx != (sfx_t *)0x0) {
            if ((pcVar3->leftvol != 0) || (pcVar3->rightvol != 0)) {
              iVar4 = iVar4 + 1;
              Con_Printf("%3i %3i %s\n",pcVar3->leftvol,pcVar3->rightvol,pcVar3->sfx);
              iVar1 = total_channels;
            }
          }
          iVar5 = iVar5 + 1;
          pcVar3 = pcVar3 + 1;
        } while (iVar5 < iVar1);
      }
      Con_Printf("----(%i)----\n",iVar4);
    }
                    /* Unresolved local var: uint endtime@[???]
                       Unresolved local var: int samps@[???] */
    if ((sound_started != 0) && (snd_blocked < 1)) {
      GetSoundtime();
      if (shm != (dma_t *)0x0) {
        local_2c = (uint)(longlong)
                         ROUND((float)shm->dmaspeed * _snd_mixahead.value + (float)soundtime);
        local_30 = local_2c;
        local_34 = shm->samples >> ((char)shm->channels - 1U & 0x1f);
      }
      uVar2 = soundtime + local_34;
      if ((int)(local_30 - soundtime) <= local_34) {
        uVar2 = local_30;
      }
      S_PaintChannels(uVar2 >> 1);
      SNDDMA_Submit();
      return;
    }
  }
  return;
}


// S_UpdateAmbientSounds  @ 001f8ce0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_UpdateAmbientSounds(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  mleaf_t *pmVar4;
  
                    /* Unresolved local var: mleaf_t * l@[???]
                       Unresolved local var: float vol@[???]
                       Unresolved local var: int ambient_channel@[???]
                       Unresolved local var: channel_t * chan@[???] */
  if (snd_ambient == false) {
    return;
  }
  if (cl.worldmodel == (model_s *)0x0) {
    return;
  }
  pmVar4 = Mod_PointInLeaf(listener_origin,cl.worldmodel);
  if ((pmVar4 == (mleaf_t *)0x0) || (ambient_level.value == 0.0)) {
    channels[0].sfx = (sfx_t *)0x0;
    channels[1].sfx = (sfx_t *)0x0;
    channels[2].sfx = (sfx_t *)0x0;
    channels[3].sfx = (sfx_t *)0x0;
    return;
  }
  fVar3 = (float)host_frametime;
  fVar1 = (float)pmVar4->ambient_sound_level[0] * ambient_level.value;
  fVar2 = 0.0;
  if (8.0 <= fVar1) {
    fVar2 = fVar1;
  }
  if (fVar2 <= (float)channels[0].master_vol) {
    if ((fVar2 < (float)channels[0].master_vol) &&
       (channels[0].master_vol = (int)((float)channels[0].master_vol - fVar3 * ambient_fade.value),
       (float)channels[0].master_vol < fVar2)) goto LAB_001f8da3;
  }
  else {
    channels[0].master_vol = (int)(fVar3 * ambient_fade.value + (float)channels[0].master_vol);
    if (fVar2 < (float)channels[0].master_vol) {
LAB_001f8da3:
      channels[0].master_vol = (int)fVar2;
    }
  }
  fVar1 = (float)pmVar4->ambient_sound_level[1] * ambient_level.value;
  fVar2 = 0.0;
  if (8.0 <= fVar1) {
    fVar2 = fVar1;
  }
  if ((float)channels[1].master_vol < fVar2) {
    channels[1].master_vol = (int)(fVar3 * ambient_fade.value + (float)channels[1].master_vol);
    if (fVar2 < (float)channels[1].master_vol) goto LAB_001f90b8;
  }
  else if ((fVar2 < (float)channels[1].master_vol) &&
          (channels[1].master_vol =
                (int)((float)channels[1].master_vol - fVar3 * ambient_fade.value),
          (float)channels[1].master_vol < fVar2)) {
LAB_001f90b8:
    channels[1].master_vol = (int)fVar2;
  }
  fVar1 = (float)pmVar4->ambient_sound_level[2] * ambient_level.value;
  fVar2 = 0.0;
  if (8.0 <= fVar1) {
    fVar2 = fVar1;
  }
  if ((float)channels[2].master_vol < fVar2) {
    channels[2].master_vol = (int)(fVar3 * ambient_fade.value + (float)channels[2].master_vol);
    if ((float)channels[2].master_vol <= fVar2) goto LAB_001f8f02;
  }
  else if (((float)channels[2].master_vol <= fVar2) ||
          (channels[2].master_vol =
                (int)((float)channels[2].master_vol - fVar3 * ambient_fade.value),
          fVar2 <= (float)channels[2].master_vol)) goto LAB_001f8f02;
  channels[2].master_vol = (int)fVar2;
LAB_001f8f02:
  fVar1 = (float)pmVar4->ambient_sound_level[3] * ambient_level.value;
  fVar2 = 0.0;
  if (8.0 <= fVar1) {
    fVar2 = fVar1;
  }
  if (fVar2 <= (float)channels[3].master_vol) {
    if ((float)channels[3].master_vol <= fVar2) {
      channels[0].sfx = ambient_sfx[0];
      channels[0].leftvol = channels[0].master_vol;
      channels[0].rightvol = channels[0].master_vol;
      channels[1].sfx = ambient_sfx[1];
      channels[1].leftvol = channels[1].master_vol;
      channels[1].rightvol = channels[1].master_vol;
      channels[2].sfx = ambient_sfx[2];
      channels[2].leftvol = channels[2].master_vol;
      channels[2].rightvol = channels[2].master_vol;
      channels[3].sfx = ambient_sfx[3];
      channels[3].leftvol = channels[3].master_vol;
      channels[3].rightvol = channels[3].master_vol;
      return;
    }
    channels[3].leftvol = (int)((float)channels[3].master_vol - fVar3 * ambient_fade.value);
    if (fVar2 <= (float)channels[3].leftvol) {
      channels[0].sfx = ambient_sfx[0];
      channels[0].leftvol = channels[0].master_vol;
      channels[0].rightvol = channels[0].master_vol;
      channels[1].sfx = ambient_sfx[1];
      channels[1].leftvol = channels[1].master_vol;
      channels[1].rightvol = channels[1].master_vol;
      channels[2].sfx = ambient_sfx[2];
      channels[2].leftvol = channels[2].master_vol;
      channels[2].rightvol = channels[2].master_vol;
      channels[3].sfx = ambient_sfx[3];
      channels[3].rightvol = channels[3].leftvol;
      channels[3].master_vol = channels[3].leftvol;
      return;
    }
  }
  else {
    channels[3].leftvol = (int)((float)channels[3].master_vol + fVar3 * ambient_fade.value);
    if ((float)channels[3].leftvol <= fVar2) {
      channels[0].sfx = ambient_sfx[0];
      channels[0].leftvol = channels[0].master_vol;
      channels[0].rightvol = channels[0].master_vol;
      channels[1].sfx = ambient_sfx[1];
      channels[1].leftvol = channels[1].master_vol;
      channels[1].rightvol = channels[1].master_vol;
      channels[2].sfx = ambient_sfx[2];
      channels[2].leftvol = channels[2].master_vol;
      channels[2].rightvol = channels[2].master_vol;
      channels[3].sfx = ambient_sfx[3];
      channels[3].rightvol = channels[3].leftvol;
      channels[3].master_vol = channels[3].leftvol;
      return;
    }
  }
  channels[3].master_vol = (int)fVar2;
  channels[3].rightvol = channels[3].master_vol;
  channels[3].leftvol = channels[3].master_vol;
  channels[3].sfx = ambient_sfx[3];
  channels[2].rightvol = channels[2].master_vol;
  channels[2].leftvol = channels[2].master_vol;
  channels[2].sfx = ambient_sfx[2];
  channels[1].rightvol = channels[1].master_vol;
  channels[1].leftvol = channels[1].master_vol;
  channels[1].sfx = ambient_sfx[1];
  channels[0].rightvol = channels[0].master_vol;
  channels[0].leftvol = channels[0].master_vol;
  channels[0].sfx = ambient_sfx[0];
  return;
}


// S_Update_  @ 001f9580
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_Update_(void)

{
  int unaff_EBX;
  uint unaff_ESI;
  uint local_1c;
  
                    /* Unresolved local var: uint endtime@[???]
                       Unresolved local var: int samps@[???] */
  if ((sound_started != 0) && (snd_blocked < 1)) {
    GetSoundtime();
    if (shm != (dma_t *)0x0) {
      local_1c = (uint)(longlong)
                       ROUND((float)shm->dmaspeed * _snd_mixahead.value + (float)soundtime);
      unaff_EBX = shm->samples >> ((char)shm->channels - 1U & 0x1f);
      unaff_ESI = local_1c;
    }
    if (unaff_EBX < (int)(unaff_ESI - soundtime)) {
      unaff_ESI = soundtime + unaff_EBX;
    }
    S_PaintChannels(unaff_ESI >> 1);
    SNDDMA_Submit();
    return;
  }
  return;
}


