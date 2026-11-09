// S_AlterChannel  @ 001a71c0
int S_AlterChannel(int entnum,int entchannel,sfx_t *sfx,int vol,int pitch,int flags)

{
  int *piVar1;
  int iVar2;
  
                    /* Unresolved local var: int ch_idx@[???] */
                    /* Unresolved local var: int ch_idx@[???] */
  if (sfx->name[0] == '!') {
    if (4 < total_channels) {
      piVar1 = &channels[4].entnum;
      iVar2 = 4;
      do {
        if ((((entnum == *piVar1) && (entchannel == piVar1[1])) &&
            (((channel_t *)(piVar1 + -6))->sfx != (sfx_t *)0x0)) && (-1 < piVar1[7]))
        goto LAB_001a7206;
        iVar2 = iVar2 + 1;
        piVar1 = piVar1 + 0x10;
      } while (iVar2 != total_channels);
    }
  }
  else {
    piVar1 = &channels[4].entnum;
    iVar2 = 4;
    if (4 < total_channels) {
      do {
        if (((entnum == *piVar1) && (entchannel == piVar1[1])) &&
           (sfx == ((channel_t *)(piVar1 + -6))->sfx)) {
LAB_001a7206:
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
  }
  return 0;
}


// S_AmbientOff  @ 001a6250
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_AmbientOff(void)

{
  snd_ambient = false;
  return;
}


// S_AmbientOn  @ 001a6260
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_AmbientOn(void)

{
  snd_ambient = true;
  return;
}


// S_BeginPrecaching  @ 001a9bd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_BeginPrecaching(void)

{
  cl.fPrecaching = 1;
  return;
}


// S_BlockSound  @ 001cca20
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


// S_CheckWavEnd  @ 001ae060
qboolean S_CheckWavEnd(channel_t *ch,sfxcache_t **psc,int ltime,int ichan)

{
  sfx_t *psVar1;
  sfxcache_t *psVar2;
  int *piVar3;
  int iVar4;
  byte *data;
  int iVar5;
  uint uVar6;
  int local_20 [4];
  
                    /* Unresolved local var: sfxcache_t * sc@[???] */
  psVar2 = *psc;
  if (psVar2->length != 0x40000000) {
    iVar4 = psVar2->loopstart;
    if (iVar4 < 0) {
      if (ch->entchannel == 5) {
        if (wavstreams[ichan].csamplesplayed < wavstreams[ichan].info.samples) {
          psVar1 = ch->sfx;
                    /* Unresolved local var: byte * data@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int cbread@[???]
                       Unresolved local var: int i@[???] */
          uVar6 = (uint)(ch + -0x4f242) >> 6;
          piVar3 = Cache_Check(&psVar1->cache);
          iVar4 = wavstreams[uVar6].info.dataofs + wavstreams[uVar6].csamplesplayed;
          wavstreams[uVar6].lastposloaded = iVar4;
          data = COM_LoadFileLimit((char *)0x0,iVar4,0x8000,local_20,&wavstreams[uVar6].hFile);
          iVar5 = wavstreams[uVar6].info.samples - wavstreams[uVar6].csamplesplayed;
          wavstreams[uVar6].csamplesinmem = local_20[0];
          iVar4 = local_20[0];
          if (iVar5 < local_20[0]) {
            wavstreams[uVar6].csamplesinmem = iVar5;
            iVar4 = iVar5;
          }
          *piVar3 = iVar4;
          ResampleSfx(psVar1,piVar3[2],piVar3[3],data,local_20[0]);
          ch->pos = 0;
          ch->end = ltime + psVar2->length;
          return false;
        }
      }
      else {
        iVar4 = ch->isentence;
        if (-1 < iVar4) {
                    /* Unresolved local var: sfx_t * sfx@[???] */
          iVar5 = ch->iword;
          psVar1 = rgrgvoxword[iVar4][iVar5].sfx;
          if ((psVar1 != (sfx_t *)0x0) && (rgrgvoxword[iVar4][iVar5].fKeepCached == 0)) {
            Cache_Free(&psVar1->cache);
            iVar4 = ch->isentence;
            iVar5 = ch->iword;
          }
          psVar1 = *(sfx_t **)(iVar4 * 0x480 + 0x13cd100 + (iVar5 * 9 + 9) * 4);
          ch->sfx = psVar1;
          if (psVar1 != (sfx_t *)0x0) {
            psVar2 = S_LoadSound(psVar1,ch);
            *psc = psVar2;
            if (psVar2 != (sfxcache_t *)0x0) {
              ch->pos = 0;
              iVar4 = psVar2->length;
              ch->iword = ch->iword + 1;
              ch->end = ltime + iVar4;
              VOX_TrimStartEndTimes(ch,psVar2);
              return false;
            }
          }
        }
      }
      S_FreeChannel(ch);
      return true;
    }
    ch->pos = iVar4;
    ch->end = (ltime + psVar2->length) - iVar4;
    if (-1 < ch->isentence) {
      *(undefined4 *)(ch->isentence * 0x480 + 0x13cd0f8 + ch->iword * 0x24) = 0;
      return false;
    }
  }
  return false;
}


// S_ClearBuffer  @ 001a8610
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_ClearBuffer(void)

{
  int iVar1;
  int fill;
  
                    /* Unresolved local var: int clear@[???] */
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


// S_ClearPrecache  @ 001a9bc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_ClearPrecache(void)

{
  return;
}


// S_EndPrecaching  @ 001a9be0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_EndPrecaching(void)

{
  cl.fPrecaching = 0;
  return;
}


// S_ExtraUpdate  @ 001a8f10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_ExtraUpdate(void)

{
  int iVar1;
  int iVar2;
  channel_t *ch;
  uint unaff_ESI;
  int fill;
  int local_30;
  uint local_2c;
  int local_24;
  
  iVar1 = VGuiWrap2_IsGameUIVisible();
  if (iVar1 == 0) {
    SDL_PumpEvents();
    ClientDLL_IN_Accumulate();
  }
                    /* Unresolved local var: uint endtime@[???]
                       Unresolved local var: int samps@[???] */
  if (((snd_noextraupdate.value == 0.0) && (sound_started != 0)) && (snd_blocked < 1)) {
                    /* Unresolved local var: int samplepos@[???]
                       Unresolved local var: int fullsamples@[???] */
    if (shm != (dma_t *)0x0) {
      local_24 = shm->samples / shm->channels;
    }
    iVar1 = SNDDMA_GetDMAPos();
    if ((iVar1 < GetSoundtime::oldsamplepos) &&
       (GetSoundtime::buffers = GetSoundtime::buffers + 1, 0x40000000 < paintedtime)) {
      GetSoundtime::buffers = 0;
      paintedtime = local_24;
                    /* Unresolved local var: int i@[???] */
      if (sound_started != 0) {
        ch = channels;
        total_channels = 0x24;
        do {
          if (ch->sfx != (sfx_t *)0x0) {
            S_FreeChannel(ch);
          }
          ch = ch + 1;
        } while (ch != (channel_t *)listener_up);
        Q_memset(channels,0,0x2000);
        Wavstream_Init();
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int clear@[???] */
                    /* Unresolved local var: int clear@[???] */
        if ((sound_started != 0) && (shm != (dma_t *)0x0)) {
          fill = 0;
          if (shm->samplebits == 8) {
            fill = 0x80;
          }
          iVar2 = shm->samplebits * shm->samples;
          if (iVar2 < 0) {
            iVar2 = iVar2 + 7;
          }
          Q_memset(shm->buffer,fill,iVar2 >> 3);
        }
      }
    }
    local_2c = unaff_ESI;
    if (shm != (dma_t *)0x0) {
      soundtime = iVar1 / shm->channels + local_24 * GetSoundtime::buffers;
      local_2c = (uint)(longlong)
                       ROUND((float)soundtime + (float)shm->dmaspeed * _snd_mixahead.value);
      local_30 = shm->samples >> ((char)shm->channels - 1U & 0x1f);
    }
    if (local_30 < (int)(local_2c - soundtime)) {
      local_2c = soundtime + local_30;
    }
    GetSoundtime::oldsamplepos = iVar1;
    S_PaintChannels(local_2c >> 1);
    SNDDMA_Submit();
    return;
  }
  return;
}


// S_FindName  @ 001a6810
sfx_t * S_FindName(char *name,int *pfInCache)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  sfx_t *psVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: sfx_t * sfx@[???] */
  if (name == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("S_FindName: NULL\n");
  }
  iVar1 = Q_strlen(name);
  if (0x3f < iVar1) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Sound name too long: %s",name);
  }
  if (num_sfx < 1) {
    iVar1 = 0;
  }
  else {
    iVar3 = 0;
    psVar5 = (sfx_t *)0x0;
    iVar1 = 0;
LAB_001a685d:
    do {
      iVar4 = iVar1;
      iVar1 = Q_strcasecmp(known_sfx->name + iVar3,name);
      if (iVar1 == 0) {
        if (pfInCache != (int *)0x0) {
          pvVar2 = Cache_Check((cache_user_t *)(known_sfx->name + iVar3 + 0x40));
          *pfInCache = (uint)(pvVar2 != (void *)0x0);
        }
        psVar5 = (sfx_t *)(known_sfx->name + iVar3);
        if (0 < psVar5->servercount) {
          psVar5->servercount = cl.servercount;
        }
        return psVar5;
      }
      if (psVar5 == (sfx_t *)0x0) {
        iVar1 = ((sfx_t *)(known_sfx->name + iVar3))->servercount;
        if (0 < iVar1) {
          if (iVar1 != cl.servercount) {
            psVar5 = (sfx_t *)(known_sfx->name + iVar3);
          }
          iVar3 = iVar3 + 0x48;
          iVar1 = iVar4 + 1;
          if (num_sfx <= iVar4 + 1) break;
          goto LAB_001a685d;
        }
      }
      iVar3 = iVar3 + 0x48;
      iVar1 = iVar4 + 1;
    } while (iVar4 + 1 < num_sfx);
    if (psVar5 != (sfx_t *)0x0) {
      pvVar2 = Cache_Check(&psVar5->cache);
      if (pvVar2 != (void *)0x0) {
        Cache_Free(&psVar5->cache);
      }
      goto LAB_001a68bf;
    }
    iVar1 = (iVar4 + 1) * 0x48;
    if (num_sfx == 0x400) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("S_FindName: out of sfx_t");
    }
  }
  num_sfx = num_sfx + 1;
  psVar5 = (sfx_t *)(known_sfx->name + iVar1);
LAB_001a68bf:
  Q_strncpy(psVar5->name,name,0x3f);
  psVar5->name[0x3f] = '\0';
  if (pfInCache != (int *)0x0) {
    *pfInCache = 0;
  }
  psVar5->servercount = cl.servercount;
  return psVar5;
}


// S_FlushSoundData  @ 001a69c0
void S_FlushSoundData(int fDumpLores,int fDumpHires)

{
  void *pvVar1;
  int iVar2;
  channel_t *pcVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: channel_t * ch@[???]
                       Unresolved local var: int fNoDiscard@[???] */
  if (0 < num_sfx) {
    pcVar3 = channels;
    iVar4 = 0;
    do {
      while (pvVar1 = Cache_Check(&known_sfx[iVar4].cache), pvVar1 == (void *)0x0) {
LAB_001a6a38:
        iVar4 = iVar4 + 1;
        if (num_sfx <= iVar4) {
          return;
        }
      }
      if (0 < total_channels) {
        iVar2 = 0;
        do {
          if (((pcVar3->sfx != (sfx_t *)0x0) && (pcVar3->entchannel == 5)) &&
             (pcVar3->sfx == known_sfx + iVar4)) goto LAB_001a6a38;
          iVar2 = iVar2 + 1;
          pcVar3 = pcVar3 + 1;
        } while (iVar2 != total_channels);
      }
      if ((fDumpLores != 0) && (*(int *)((int)pvVar1 + 8) <= shm->speed)) {
        Cache_Free(&known_sfx[iVar4].cache);
      }
      if ((fDumpHires == 0) || (*(int *)((int)pvVar1 + 8) <= shm->speed)) goto LAB_001a6a38;
      iVar2 = iVar4 + 1;
      Cache_Free(&known_sfx[iVar4].cache);
      iVar4 = iVar2;
    } while (iVar2 < num_sfx);
  }
  return;
}


// S_FreeChannel  @ 001a9e50
void S_FreeChannel(channel_t *ch)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = ch->entchannel;
  if (iVar1 == 5) {
                    /* Unresolved local var: int i@[???] */
    uVar2 = (uint)(ch + -0x4f242) >> 6;
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
  if ((0 < iVar1) && (((ch->entchannel == 2 || (ch->entchannel == 5)) && (iVar1 < cl.max_edicts))))
  {
    cl_entities[iVar1].mouth.mouthopen = '\0';
    return;
  }
  return;
}


// S_Init  @ 001a6420
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_Init(void)

{
  int iVar1;
  int iVar2;
  dma_t *pdVar3;
  uchar *puVar4;
  qboolean qVar5;
  int iVar6;
  channel_t *ch;
  
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
    qVar5 = SNDDMA_Init();
    if (qVar5 == false) {
                    /* Unresolved local var: int rc@[???] */
      Con_Printf("S_Startup: SNDDMA_Init failed.\n");
      sound_started = 0;
      goto LAB_001a65dd;
    }
  }
  sound_started = 1;
LAB_001a65dd:
  SND_InitScaletable();
  known_sfx = Hunk_AllocName(0x12000,"sfx_t");
  num_sfx = 0;
  if (fakedma != false) {
    pdVar3 = Hunk_AllocName(0x2c,"shm");
    pdVar3->splitbuffer = false;
    shm = pdVar3;
    pdVar3->samplebits = 0x10;
    pdVar3->speed = 0x5622;
    pdVar3->channels = 2;
    pdVar3->samples = 0x8000;
    pdVar3->samplepos = 0;
    pdVar3->soundalive = true;
    pdVar3->gamealive = true;
    pdVar3 = shm;
    shm->submission_chunk = 1;
    puVar4 = Hunk_AllocName(0x10000,"shmbuf");
    pdVar3->buffer = puVar4;
    Con_DPrintf("Sound sampling rate: %i\n",shm->speed);
  }
                    /* Unresolved local var: int i@[???] */
  if (sound_started != 0) {
    ch = channels;
    total_channels = 0x24;
    do {
      if (ch->sfx != (sfx_t *)0x0) {
        S_FreeChannel(ch);
      }
      ch = ch + 1;
    } while (ch != (channel_t *)listener_up);
    Q_memset(channels,0,0x2000);
    Wavstream_Init();
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int clear@[???] */
                    /* Unresolved local var: int clear@[???] */
    if ((sound_started != 0) && (shm != (dma_t *)0x0)) {
      iVar1 = 0x80;
      if (shm->samplebits != 8) {
        iVar1 = 0;
      }
      iVar6 = shm->samples * shm->samplebits;
      iVar2 = iVar6 + 7;
      if (-1 < iVar6) {
        iVar2 = iVar6;
      }
      Q_memset(shm->buffer,iVar1,iVar2 >> 3);
    }
  }
  SX_Init();
  Wavstream_Init();
  return;
}


// S_LoadSound  @ 001b1670
sfxcache_t * S_LoadSound(sfx_t *s,channel_t *ch)

{
  cache_user_t *c;
  float fVar1;
  sfxcache_t *psVar2;
  uint uVar3;
  uint uVar4;
  wavinfo_t *info;
  int iVar5;
  qboolean qVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  int in_GS_OFFSET;
  double dVar10;
  byte *local_558;
  FileHandle_t local_554;
  double local_54c;
  uint local_53c;
  int local_538;
  int local_534;
  int local_530;
  int local_52c;
  int local_528;
  int local_524;
  uint local_520 [63];
  undefined1 local_421 [1025];
  int local_20;
  
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
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (s->name[0] == '*') {
    psVar2 = S_LoadStreamSound(s,ch);
    goto LAB_001b16f5;
  }
  if (s->name[0] == '?') {
    psVar2 = VoiceSE_GetSFXCache(s);
    goto LAB_001b16f5;
  }
  c = &s->cache;
  psVar2 = Cache_Check(c);
  if (psVar2 != (sfxcache_t *)0x0) {
    if (((hisound.value != 0.0) || (shm == (dma_t *)0x0)) || (psVar2->speed <= shm->speed))
    goto LAB_001b16f5;
    Cache_Free(c);
  }
  if (fs_precache_timings.value != 0.0) {
    local_54c = Sys_FloatTime();
  }
  Q_strcpy((char *)local_520,"sound");
  puVar8 = local_520;
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
    __strncat_chk(local_520,0x25822f,
                  local_421 + -(int)((int)puVar8 + (-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4))));
    puVar8 = local_520;
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
  __strncat_chk(local_520,s,
                local_421 + -(int)((int)puVar8 + (-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4))));
  local_554 = FS_Open((char *)local_520,"rb");
  if (local_554 == (FileHandle_t)0x0) {
LAB_001b1980:
    local_520[0]._0_1_ = 0;
    puVar8 = local_520;
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
      __strncat_chk(local_520,0x25822f,
                    local_421 + -(int)((int)puVar8 + (-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4))));
      puVar8 = local_520;
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
    __strncat_chk(local_520,s,
                  local_421 + -(int)((int)puVar8 + (-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4))));
    local_421[0] = 0;
    local_558 = COM_LoadStackFile((char *)local_520,local_421 + 1,0x400,(int *)&local_53c);
    if (local_558 == (byte *)0x0) {
      Con_DPrintf("S_LoadSound: Couldn\'t load %s\n",local_520);
      psVar2 = (sfxcache_t *)0x0;
      goto LAB_001b16f5;
    }
LAB_001b1a6c:
    local_554 = (FileHandle_t)0x0;
  }
  else {
    local_558 = FS_GetReadBuffer(local_554,(int *)&local_53c);
    if (local_558 == (byte *)0x0) {
      local_53c = FS_Size(local_554);
      local_558 = Hunk_TempAlloc(local_53c + 1);
      FS_Read(local_558,local_53c,1,local_554);
      FS_Close(local_554);
      if (local_558 == (byte *)0x0) goto LAB_001b1980;
      goto LAB_001b1a6c;
    }
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int format@[???]
                       Unresolved local var: int samples@[???] */
  uVar4 = local_53c;
  Q_memset(&local_538,0,0x18);
  iff_end = local_558 + uVar4;
  iff_data = local_558;
  last_chunk = local_558;
  FindNextChunk("RIFF");
  if (data_p == (byte *)0x0) {
LAB_001b18c1:
    Con_Printf("Missing RIFF/WAVE chunks\n");
  }
  else {
    info = (wavinfo_t *)(data_p + 8);
    iVar5 = Q_strncmp((char *)info,"WAVE",4);
    if (iVar5 != 0) goto LAB_001b18c1;
    qVar6 = GetWavinfo(s->name,local_558,(int)&local_538,info);
    if (qVar6 != false) {
      if (local_530 == 1) {
        if (local_538 == 0) {
          Con_DPrintf("Invalid rate: %s\n",s);
          psVar2 = (sfxcache_t *)0x0;
        }
        else if (local_524 < (int)local_53c) {
          if ((shm == (dma_t *)0x0) || (local_538 == shm->speed)) {
            fVar1 = 1.0;
          }
          else if (((local_538 != shm->speed * 2) || (fVar1 = 1.0, hisound.value <= 0.0)) &&
                  (fVar1 = (float)local_538 / (float)shm->speed, fVar1 == 0.0)) {
            Con_DPrintf("Invalid stepscale: %s\n",s);
            psVar2 = (sfxcache_t *)0x0;
            goto LAB_001b16f5;
          }
          iVar9 = (int)((float)local_528 / fVar1);
          iVar5 = 0;
          if (iVar9 != 0) {
            iVar5 = (int)(0x7fffffff / (longlong)iVar9);
            if (iVar5 < 1) {
              Con_DPrintf("Invalid length (s/c): %s\n",s);
              psVar2 = (sfxcache_t *)0x0;
              goto LAB_001b16f5;
            }
            if (iVar5 < local_534) {
              Con_DPrintf("Invalid length (s/c/w): %s\n",s);
              psVar2 = (sfxcache_t *)0x0;
              goto LAB_001b16f5;
            }
            iVar5 = iVar9 * local_534;
            if (0x7fffffffU - iVar5 < 0x18) {
              Con_DPrintf("Invalid length (s/c/w/sfx): %s\n",s);
            }
          }
          psVar2 = Cache_Alloc(c,iVar5 + 0x18,s->name);
          if (psVar2 == (sfxcache_t *)0x0) {
            psVar2 = (sfxcache_t *)0x0;
          }
          else {
            psVar2->length = local_528;
            psVar2->loopstart = local_52c;
            psVar2->speed = local_538;
            psVar2->width = local_534;
            psVar2->stereo = local_530;
            ResampleSfx(s,local_538,local_534,local_558 + local_524,local_53c - local_524);
            if (local_554 != (FileHandle_t)0x0) {
              FS_ReleaseReadBuffer(local_554,local_558);
              FS_Close(local_554);
            }
            if (fs_precache_timings.value != 0.0) {
              dVar10 = Sys_FloatTime();
              Con_DPrintf("fs_precache_timings: loaded sound %s in time %.3f sec\n",local_520,
                          (double)(float)((longdouble)dVar10 - (longdouble)local_54c));
            }
          }
        }
        else {
          Con_DPrintf("%s has invalid data offset\n",s);
          psVar2 = (sfxcache_t *)0x0;
        }
      }
      else {
        Con_DPrintf("%s is a stereo sample\n",s);
        psVar2 = (sfxcache_t *)0x0;
      }
      goto LAB_001b16f5;
    }
  }
  Con_DPrintf("Failed loading %s\n",s);
  psVar2 = (sfxcache_t *)0x0;
LAB_001b16f5:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return psVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// S_LoadStreamSound  @ 001b11b0
sfxcache_t * S_LoadStreamSound(sfx_t *s,channel_t *ch)

{
  bool bVar1;
  sfxcache_t *psVar2;
  uint uVar3;
  uint uVar4;
  wavinfo_t *info;
  int iVar5;
  qboolean qVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  int in_GS_OFFSET;
  byte *local_188;
  int local_184;
  int local_17c;
  int local_178 [6];
  char local_160 [63];
  undefined1 local_121;
  uint local_120 [63];
  undefined1 uStack_21;
  int local_20;
  
                    /* Unresolved local var: char[256] namebuffer@[???]
                       Unresolved local var: char[64] wavname@[???]
                       Unresolved local var: byte * data@[???]
                       Unresolved local var: wavinfo_t info@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int cbread@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int ffirstload@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cl.fPrecaching == 0) {
    uVar9 = (uint)(ch + -0x4f242) >> 6;
    Q_strncpy(local_160,s->name + 1,0x3f);
    local_121 = 0;
    psVar2 = Cache_Check(&s->cache);
    if ((psVar2 != (sfxcache_t *)0x0) && (wavstreams[uVar9].hFile != (FileHandle_t)0x0))
    goto LAB_001b124d;
    Q_strcpy((char *)local_120,"sound");
    puVar8 = local_120;
    if (local_160[0] != '/') {
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
      __strncat_chk(local_120,0x25822f,
                    &uStack_21 + -(int)((int)puVar8 + (-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4))),
                    0x100);
      puVar8 = local_120;
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
    __strncat_chk(local_120,local_160,
                  &uStack_21 + -(int)((int)puVar8 + (-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4))),
                  0x100);
    if (wavstreams[uVar9].hFile == (FileHandle_t)0x0) {
      local_188 = COM_LoadFileLimit((char *)local_120,wavstreams[uVar9].lastposloaded,0x8000,
                                    &local_17c,&wavstreams[uVar9].hFile);
      iVar5 = local_17c;
      if (local_188 != (byte *)0x0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int format@[???]
                       Unresolved local var: int samples@[???] */
        Q_memset(local_178,0,0x18);
        iff_end = local_188 + iVar5;
        iff_data = local_188;
        last_chunk = local_188;
        FindNextChunk("RIFF");
        if (data_p == (byte *)0x0) {
LAB_001b155b:
          Con_Printf("Missing RIFF/WAVE chunks\n");
        }
        else {
          info = (wavinfo_t *)(data_p + 8);
          iVar5 = Q_strncmp((char *)info,"WAVE",4);
          if (iVar5 != 0) goto LAB_001b155b;
          qVar6 = GetWavinfo(s->name,local_188,(int)local_178,info);
          if (qVar6 != false) {
            if (local_178[2] != 1) {
              Con_DPrintf("%s is a stereo sample\n",local_160);
              psVar2 = (sfxcache_t *)0x0;
              goto LAB_001b124d;
            }
            if (local_178[1] != 1) {
              Con_DPrintf("%s is a 16 bit sample\n",local_160);
              psVar2 = (sfxcache_t *)0x0;
              goto LAB_001b124d;
            }
            if ((shm != (dma_t *)0x0) && (local_178[0] != shm->speed)) {
              Con_DPrintf("%s ignored, not stored at playback sample rate!\n",local_160);
              psVar2 = (sfxcache_t *)0x0;
              goto LAB_001b124d;
            }
            bVar1 = true;
            local_184 = local_17c - local_178[5];
            wavstreams[uVar9].csamplesinmem = local_184;
            goto LAB_001b13ee;
          }
        }
        Con_DPrintf("Failed loading %s\n",local_160);
        psVar2 = (sfxcache_t *)0x0;
        goto LAB_001b124d;
      }
    }
    else {
      local_188 = COM_LoadFileLimit((char *)local_120,wavstreams[uVar9].lastposloaded,0x8000,
                                    &local_17c,&wavstreams[uVar9].hFile);
      if (local_188 != (byte *)0x0) {
        uVar4 = 0;
        do {
          *(undefined4 *)((int)local_178 + uVar4) =
               *(undefined4 *)(uVar9 * 0x28 + 0x13c7c6c + uVar4);
          uVar4 = uVar4 + 4;
        } while (uVar4 < 0x18);
        bVar1 = false;
        wavstreams[uVar9].csamplesinmem = local_17c;
        local_184 = local_17c;
LAB_001b13ee:
        local_178[4] = local_178[4] - wavstreams[uVar9].csamplesplayed;
        if (local_178[4] < local_184) {
          wavstreams[uVar9].csamplesinmem = local_178[4];
        }
        uVar4 = 0;
        do {
          *(undefined4 *)(uVar9 * 0x28 + 0x13c7c6c + uVar4) =
               *(undefined4 *)((int)local_178 + uVar4);
          uVar4 = uVar4 + 4;
        } while (uVar4 < 0x18);
        if (psVar2 == (sfxcache_t *)0x0) {
          iVar5 = 0x8000;
          if (local_17c < 0x8001) {
            iVar5 = local_17c;
          }
          psVar2 = Cache_Alloc(&s->cache,iVar5 + 0x18,local_160);
          if (psVar2 == (sfxcache_t *)0x0) {
            psVar2 = (sfxcache_t *)0x0;
            goto LAB_001b124d;
          }
        }
        psVar2->length = wavstreams[uVar9].csamplesinmem;
        psVar2->loopstart = local_178[3];
        psVar2->speed = local_178[0];
        psVar2->width = local_178[1];
        psVar2->stereo = local_178[2];
        if (bVar1) {
          local_17c = local_17c - local_178[5];
          local_188 = local_188 + local_178[5];
        }
        ResampleSfx(s,local_178[0],local_178[1],local_188,local_17c);
        goto LAB_001b124d;
      }
    }
    Con_DPrintf("S_LoadStreamSound: Couldn\'t load %s\n",local_120);
  }
  psVar2 = (sfxcache_t *)0x0;
LAB_001b124d:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return psVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// S_LocalSound  @ 001a9a80
void S_LocalSound(char *sound)

{
  int iVar1;
  sfx_t *s;
  
                    /* Unresolved local var: sfx_t * sfx@[???] */
  if ((nosound.value != 0.0) || (sound_started == 0)) {
    return;
  }
                    /* Unresolved local var: sfx_t * sfx@[???] */
  iVar1 = Q_strlen(sound);
  if (iVar1 < 0x40) {
    if ((*sound == '*') || (*sound == '!')) {
                    /* Unresolved local var: sfx_t * sfx@[???] */
      s = S_FindName(sound,(int *)0x0);
    }
    else {
      s = S_FindName(sound,(int *)0x0);
      if (fs_lazy_precache.value == 0.0) {
        S_LoadSound(s,(channel_t *)0x0);
      }
    }
    if (s != (sfx_t *)0x0) {
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
      if (nosound.value != 0.0) {
        return;
      }
      S_StartDynamicSound(cl.viewentity,-1,s,vec3_origin,1.0,1.0,0,100);
      return;
    }
  }
  Con_Printf("S_LocalSound: can\'t cache %s\n",sound);
  return;
}


// S_MixChannelsToPaintbuffer  @ 001ae2a0
void S_MixChannelsToPaintbuffer(int end,int fPaintHiresSounds,int voiceOnly)

{
  uint uVar1;
  undefined1 auVar2 [16];
  byte bVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  float fVar18;
  undefined1 auVar19 [12];
  cl_entity_t *pcVar20;
  int iVar21;
  qboolean qVar22;
  portable_samplepair_t *ppVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  int *piVar27;
  int *piVar28;
  int iVar29;
  int iVar30;
  uint uVar31;
  int iVar32;
  byte *pbVar33;
  int iVar34;
  channel_t *ch;
  int in_GS_OFFSET;
  bool bVar35;
  bool bVar36;
  uint6 uVar37;
  int iVar40;
  ulonglong uVar44;
  undefined1 auVar45 [14];
  ulonglong uVar46;
  int iVar47;
  int local_10e4;
  uint local_10e0;
  uint local_10d8;
  int local_10d4;
  int local_10d0;
  uint local_10c4;
  uint local_10c0;
  wavstream_t *local_105c;
  int local_1058;
  int local_1034;
  int local_1030;
  sfxcache_t *local_1024;
  byte local_1020 [4096];
  int local_20;
  undefined1 auVar38 [12];
  undefined1 auVar39 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  
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
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar35 = fPaintHiresSounds != 0;
  if (0 < total_channels) {
    local_105c = wavstreams;
    ch = channels;
    local_10d0 = 0;
    iVar21 = total_channels;
    do {
      if (ch->sfx != (sfx_t *)0x0) {
        local_1024 = S_LoadSound(ch->sfx,ch);
        iVar5 = local_1024->length;
        iVar21 = total_channels;
        if (iVar5 == 0x40000000) {
          if (voiceOnly != 0) {
            iVar34 = ch->leftvol;
joined_r0x001ae308:
            if ((iVar34 == 0) && (ch->rightvol == 0)) {
              if (local_1024->loopstart < 0) {
                S_FreeChannel(ch);
                iVar21 = total_channels;
              }
            }
            else if (local_1024 != (sfxcache_t *)0x0) {
              if (fPaintHiresSounds == 0) {
                if (local_1024->speed == shm->speed) goto LAB_001ae3a5;
              }
              else if (shm->speed < local_1024->speed) {
LAB_001ae3a5:
                local_10e4 = paintedtime;
                local_1034 = ch->pitch;
                iVar21 = ch->isentence;
                if (iVar21 < 0) {
                  local_1030 = 0;
                }
                else {
                  iVar34 = *(int *)(iVar21 * 0x480 + 0x13cd0e4 + ch->iword * 0x24);
                  iVar29 = local_1034 + -100 + iVar34;
                  if (iVar34 < 1) {
                    iVar29 = local_1034;
                  }
                  local_1030 = *(int *)(iVar21 * 0x480 + 0x13cd0fc + ch->iword * 0x24);
                  local_1034 = iVar29;
                }
                    /* Unresolved local var: int oldleft@[???]
                       Unresolved local var: int oldright@[???] */
                bVar3 = 0;
LAB_001ae430:
                iVar34 = paintedtime;
                pcVar20 = cl_entities;
                iVar21 = total_channels;
                if (((bool)(bVar3 ^ 1)) && (local_10e4 < end)) {
                  if (fPaintHiresSounds == 0) {
                    iVar21 = ch->end;
                  }
                  else {
                    iVar21 = (local_1024->length >> 1) + (ch->end - local_1024->length);
                  }
                  iVar29 = end - local_10e4;
                  if (iVar21 < end) {
                    iVar29 = iVar21 - local_10e4;
                  }
                  if (iVar5 == 0x40000000) goto LAB_001ae7b0;
                  if (iVar29 << bVar35 < 1) goto LAB_001ae7f0;
                  if (((local_1024->width != 1) || (iVar30 = ch->entnum, iVar30 < 1)) ||
                     ((ch->entchannel != 2 && (ch->entchannel != 5)))) goto LAB_001ae4ca;
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: char * pdata@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int savg@[???]
                       Unresolved local var: int scount@[???]
                       Unresolved local var: cl_entity_t.conflict1 * pent@[???] */
                  uVar24 = (uint)cl_entities[iVar30].mouth.sndcount;
                  if (uVar24 < 10) {
                    iVar32 = 0;
                    local_10e0 = 0;
                    do {
                      bVar3 = local_1024->data[iVar32 + ch->pos];
                      uVar24 = uVar24 + 1;
                      uVar25 = (int)(char)bVar3 >> 0x1f;
                      iVar32 = iVar32 + 0x50 + (uint)(bVar3 & 0x1f);
                      local_10e0 = local_10e0 + (((int)(char)bVar3 ^ uVar25) - uVar25);
                      if (iVar29 << bVar35 <= iVar32) break;
                    } while ((int)uVar24 < 10);
                    iVar32 = local_10e0 + cl_entities[iVar30].mouth.sndavg;
                    cl_entities[iVar30].mouth.sndavg = iVar32;
                    pcVar20[iVar30].mouth.sndcount = (byte)uVar24;
                    if (uVar24 != 10) goto LAB_001ae4ca;
                  }
                  else {
                    iVar32 = cl_entities[iVar30].mouth.sndavg;
                  }
                  pcVar20[iVar30].mouth.mouthopen = (byte)(iVar32 / 10);
                  pcVar20[iVar30].mouth.sndavg = 0;
                  pcVar20[iVar30].mouth.sndcount = '\0';
                  local_10d4 = local_10e4 - iVar34 << bVar35;
                  local_10c4 = ch->leftvol;
                  local_10c0 = ch->rightvol;
                  goto LAB_001ae4f9;
                }
              }
            }
          }
        }
        else if (voiceOnly == 0) {
          iVar34 = ch->leftvol;
          goto joined_r0x001ae308;
        }
      }
LAB_001ae326:
      local_10d0 = local_10d0 + 1;
      ch = ch + 1;
      local_105c = local_105c + 1;
    } while (local_10d0 < iVar21);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_001ae7b0:
  bVar3 = 1;
  if ((local_1024->width != 2) || (local_1024->stereo != 0)) goto LAB_001ae430;
  if (iVar29 << bVar35 < 1) {
LAB_001ae7f0:
    bVar36 = false;
    goto LAB_001ae7f2;
  }
LAB_001ae4ca:
  local_10d4 = local_10e4 - iVar34 << bVar35;
  local_10e0 = ch->leftvol;
  local_10c0 = ch->rightvol;
  local_10c4 = local_10e0;
  if (iVar5 == 0x40000000) {
    local_10d8 = local_10c0;
    if (local_1024->width != 1) {
      uVar24 = (*(code *)local_1024->loopstart)
                         (local_1024,local_1020,0x1000,ch->pos,iVar29 << bVar35);
      if (0 < (int)uVar24) {
        local_10d4 = local_10d4 * 8;
        local_10e0 = ch->leftvol;
        local_10d8 = ch->rightvol;
        local_1058 = ch->pos;
        pbVar33 = local_1020;
        goto LAB_001ae550;
      }
      local_1058 = ch->pos;
      goto LAB_001aebfc;
    }
LAB_001ae852:
    uVar24 = iVar29 << bVar35;
    if ((local_1034 == 100 && local_1030 == 0) || (ch->isentence < 0)) {
      iVar30 = (int)local_10e0 >> 3;
      iVar29 = (int)local_10d8 >> 3;
      if (local_10e4 == iVar34) {
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: int * lscale@[???]
                       Unresolved local var: int * rscale@[???]
                       Unresolved local var: uchar * sfx@[???]
                       Unresolved local var: int i@[???] */
        if (0xff < (int)local_10e0) {
          ch->leftvol = 0xff;
          iVar30 = 0x1f;
        }
        if (0xff < (int)local_10d8) {
          ch->rightvol = 0xff;
          iVar29 = 0x1f;
        }
        iVar34 = ch->pos;
        uVar25 = 0;
        do {
          iVar32 = snd_scaletable[iVar29][local_1024->data[uVar25 + iVar34]];
          paintbuffer[uVar25].left =
               paintbuffer[uVar25].left + snd_scaletable[iVar30][local_1024->data[uVar25 + iVar34]];
          paintbuffer[uVar25].right = paintbuffer[uVar25].right + iVar32;
          uVar25 = uVar25 + 1;
        } while (uVar25 != uVar24);
        ch->pos = iVar34 + uVar24;
        bVar36 = false;
      }
      else {
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: int * lscale@[???]
                       Unresolved local var: int * rscale@[???]
                       Unresolved local var: uchar * sfx@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: portable_samplepair_t * pbuffer@[???] */
        if (0xff < (int)local_10e0) {
          ch->leftvol = 0xff;
          iVar30 = 0x1f;
        }
        if (0xff < (int)local_10d8) {
          ch->rightvol = 0xff;
          iVar29 = 0x1f;
        }
        iVar34 = ch->pos;
        pbVar33 = local_1024->data + iVar34;
        ppVar23 = paintbuffer + local_10d4;
        do {
          bVar3 = *pbVar33;
          pbVar33 = pbVar33 + 1;
          iVar32 = snd_scaletable[iVar29][bVar3];
          ppVar23->left = ppVar23->left + snd_scaletable[iVar30][bVar3];
          ppVar23->right = ppVar23->right + iVar32;
          ppVar23 = ppVar23 + 1;
        } while (ppVar23 != paintbuffer + local_10d4 + uVar24);
        ch->pos = iVar34 + uVar24;
        bVar36 = false;
      }
    }
    else {
      iVar34 = VOX_FPaintPitchChannelFrom8Offs
                         (paintbuffer,ch,local_1024,uVar24,local_1034,local_1030,local_10d4);
      bVar36 = iVar34 != 0;
    }
  }
  else {
LAB_001ae4f9:
    uVar24 = iVar29 << bVar35;
    fVar18 = (float)(int)local_10c0 / g_SND_VoiceOverdrive;
    local_10e0 = (uint)((float)(int)local_10c4 / g_SND_VoiceOverdrive);
    ch->leftvol = local_10e0;
    local_10d8 = (uint)fVar18;
    ch->rightvol = local_10d8;
    if (local_1024->width == 1) goto LAB_001ae852;
                    /* Unresolved local var: char[4096] copyBuf@[???]
                       Unresolved local var: short * pSrcData@[???] */
    local_1058 = ch->pos;
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: int left@[???]
                       Unresolved local var: int right@[???]
                       Unresolved local var: int leftvol@[???]
                       Unresolved local var: int rightvol@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: portable_samplepair_t * pbuffer@[???] */
    local_10d4 = local_10d4 << 3;
    pbVar33 = local_1024->data + local_1058 * 2;
LAB_001ae550:
    uVar25 = 1;
    if (0 < (int)uVar24) {
      uVar25 = uVar24;
    }
    piVar28 = (int *)((int)&paintbuffer[0].left + local_10d4);
    if ((pbVar33 < (byte *)((int)&paintbuffer[uVar25].left + local_10d4) &&
         piVar28 < pbVar33 + uVar25 * 2) || (uVar25 < 8)) {
      iVar34 = 0;
      do {
        sVar4 = *(short *)(pbVar33 + iVar34 * 2);
        iVar34 = iVar34 + 1;
        *piVar28 = *piVar28 + ((int)(local_10e0 * (int)sVar4) >> 8);
        piVar28[1] = piVar28[1] + ((int)((int)sVar4 * local_10d8) >> 8);
        piVar28 = piVar28 + 2;
      } while (iVar34 < (int)uVar24);
    }
    else {
      uVar1 = (uVar25 - 8 >> 3) + 1;
      uVar26 = uVar1 * 8;
      if ((int)uVar24 < 8) {
        uVar26 = 0;
      }
      else {
        piVar27 = (int *)((int)&paintbuffer[2].left + local_10d4);
        uVar31 = 0;
        do {
          iVar6 = piVar27[4];
          iVar7 = piVar27[5];
          iVar8 = piVar27[6];
          iVar9 = piVar27[7];
          auVar2 = *(undefined1 (*) [16])(pbVar33 + uVar31 * 0x10);
          auVar45 = SUB1614((undefined1  [16])0x0,2);
          auVar43._0_12_ = auVar2._0_12_;
          auVar43._12_2_ = auVar2._6_2_;
          auVar43._14_2_ = -(ushort)(auVar2._6_2_ < 0);
          auVar42._12_4_ = auVar43._12_4_;
          auVar42._0_10_ = auVar2._0_10_;
          auVar42._10_2_ = -(ushort)(auVar2._4_2_ < 0);
          auVar41._10_6_ = auVar42._10_6_;
          auVar41._0_8_ = auVar2._0_8_;
          auVar41._8_2_ = auVar2._4_2_;
          uVar44 = auVar41._8_8_;
          auVar19._4_8_ = uVar44;
          auVar19._2_2_ = -(ushort)(auVar2._2_2_ < 0);
          auVar19._0_2_ = auVar2._2_2_;
          iVar40 = CONCAT22(-(ushort)(auVar2._0_2_ < 0),auVar2._0_2_);
          iVar10 = *piVar27;
          iVar11 = piVar27[1];
          iVar12 = piVar27[2];
          iVar13 = piVar27[3];
          uVar37 = CONCAT24(auVar2._10_2_,CONCAT22(-(ushort)(auVar2._8_2_ < 0),auVar2._8_2_));
          auVar38._0_8_ = CONCAT26(-(ushort)(auVar2._10_2_ < auVar45._8_2_),uVar37);
          auVar38._8_2_ = auVar2._12_2_;
          auVar38._10_2_ = -(ushort)(auVar2._12_2_ < auVar45._10_2_);
          auVar39._12_2_ = auVar2._14_2_;
          auVar39._0_12_ = auVar38;
          auVar39._14_2_ = -(ushort)(auVar2._14_2_ < auVar45._12_2_);
          iVar34 = piVar27[-4];
          iVar29 = piVar27[-3];
          iVar30 = piVar27[-2];
          iVar32 = piVar27[-1];
          iVar14 = piVar27[8];
          iVar15 = piVar27[9];
          iVar16 = piVar27[10];
          iVar17 = piVar27[0xb];
          uVar46 = auVar39._8_8_;
          iVar47 = (int)((ulonglong)auVar38._0_8_ >> 0x20);
          uVar31 = uVar31 + 1;
          piVar27 = piVar27 + 0x10;
          piVar28[4] = ((int)((ulonglong)local_10e0 * (uVar44 & 0xffffffff)) >> 8) + iVar10;
          piVar28[5] = iVar11 + ((int)((uVar44 & 0xffffffff) * (ulonglong)local_10d8) >> 8);
          piVar28[6] = ((int)((ulonglong)local_10e0 * (uVar44 >> 0x20)) >> 8) + iVar12;
          piVar28[7] = iVar13 + ((int)((uVar44 >> 0x20) * (ulonglong)local_10d8) >> 8);
          *(ulonglong *)piVar28 =
               CONCAT44(iVar29 + ((int)(iVar40 * local_10d8) >> 8),
                        ((int)(local_10e0 * iVar40) >> 8) + iVar34);
          piVar28[2] = ((int)(local_10e0 * auVar19._0_4_) >> 8) + iVar30;
          piVar28[3] = iVar32 + ((int)(auVar19._0_4_ * local_10d8) >> 8);
          piVar28[0xc] = iVar14 + ((int)(local_10e0 * auVar38._8_4_) >> 8);
          piVar28[0xd] = ((int)((uVar46 & 0xffffffff) * (ulonglong)local_10d8) >> 8) + iVar15;
          piVar28[0xe] = iVar16 + ((int)((ulonglong)local_10e0 * (uVar46 >> 0x20)) >> 8);
          piVar28[0xf] = ((int)((uVar46 >> 0x20) * (ulonglong)local_10d8) >> 8) + iVar17;
          *(ulonglong *)(piVar28 + 8) =
               CONCAT44(((int)(((ulonglong)uVar37 & 0xffffffff) * (ulonglong)local_10d8) >> 8) +
                        iVar7,iVar6 + ((int)((ulonglong)local_10e0 *
                                            ((ulonglong)uVar37 & 0xffffffff)) >> 8));
          piVar28[10] = iVar8 + ((int)(local_10e0 * iVar47) >> 8);
          piVar28[0xb] = ((int)(iVar47 * local_10d8) >> 8) + iVar9;
          piVar28 = piVar28 + 0x10;
        } while (uVar31 < uVar1);
        if (uVar26 == uVar25) goto LAB_001aebfc;
      }
      sVar4 = *(short *)(pbVar33 + uVar26 * 2);
      piVar28 = (int *)((int)&paintbuffer[uVar26].left + local_10d4);
      *piVar28 = *piVar28 + ((int)(local_10e0 * (int)sVar4) >> 8);
      piVar28[1] = piVar28[1] + ((int)((int)sVar4 * local_10d8) >> 8);
      iVar34 = uVar26 + 1;
      if (iVar34 < (int)uVar24) {
        sVar4 = *(short *)(pbVar33 + iVar34 * 2);
        piVar28 = (int *)((int)&paintbuffer[iVar34].left + local_10d4);
        *piVar28 = *piVar28 + ((int)(local_10e0 * (int)sVar4) >> 8);
        piVar28[1] = piVar28[1] + ((int)((int)sVar4 * local_10d8) >> 8);
        iVar34 = uVar26 + 2;
        if (iVar34 < (int)uVar24) {
          sVar4 = *(short *)(pbVar33 + iVar34 * 2);
          piVar28 = (int *)((int)&paintbuffer[iVar34].left + local_10d4);
          *piVar28 = *piVar28 + ((int)(local_10e0 * (int)sVar4) >> 8);
          piVar28[1] = piVar28[1] + ((int)((int)sVar4 * local_10d8) >> 8);
          iVar34 = uVar26 + 3;
          if (iVar34 < (int)uVar24) {
            sVar4 = *(short *)(pbVar33 + iVar34 * 2);
            piVar28 = (int *)((int)&paintbuffer[iVar34].left + local_10d4);
            *piVar28 = *piVar28 + ((int)(local_10e0 * (int)sVar4) >> 8);
            piVar28[1] = piVar28[1] + ((int)((int)sVar4 * local_10d8) >> 8);
            iVar34 = uVar26 + 4;
            if (iVar34 < (int)uVar24) {
              sVar4 = *(short *)(pbVar33 + iVar34 * 2);
              piVar28 = (int *)((int)&paintbuffer[iVar34].left + local_10d4);
              *piVar28 = *piVar28 + ((int)(local_10e0 * (int)sVar4) >> 8);
              piVar28[1] = piVar28[1] + ((int)((int)sVar4 * local_10d8) >> 8);
              iVar34 = uVar26 + 5;
              if (iVar34 < (int)uVar24) {
                iVar29 = uVar26 + 6;
                sVar4 = *(short *)(pbVar33 + iVar34 * 2);
                piVar28 = (int *)((int)&paintbuffer[iVar34].left + local_10d4);
                *piVar28 = *piVar28 + ((int)(local_10e0 * (int)sVar4) >> 8);
                piVar28[1] = piVar28[1] + ((int)((int)sVar4 * local_10d8) >> 8);
                if (iVar29 < (int)uVar24) {
                  sVar4 = *(short *)(pbVar33 + iVar29 * 2);
                  piVar28 = (int *)((int)&paintbuffer[iVar29].left + local_10d4);
                  *piVar28 = *piVar28 + ((int)(local_10e0 * (int)sVar4) >> 8);
                  piVar28[1] = piVar28[1] + ((int)((int)sVar4 * local_10d8) >> 8);
                }
              }
            }
          }
        }
      }
    }
LAB_001aebfc:
    ch->pos = local_1058 + uVar24;
    bVar36 = false;
  }
  ch->leftvol = local_10c4;
  local_10e4 = local_10e4 + ((int)uVar24 >> bVar35);
  ch->rightvol = local_10c0;
  if (ch->entchannel == 5) {
    local_105c->csamplesplayed = local_105c->csamplesplayed + uVar24;
  }
LAB_001ae7f2:
  if ((iVar21 <= local_10e4) || (bVar3 = 0, bVar36)) {
    qVar22 = S_CheckWavEnd(ch,&local_1024,local_10e4,local_10d0);
    iVar21 = total_channels;
    if (qVar22 != false) goto LAB_001ae326;
    bVar3 = 0;
  }
  goto LAB_001ae430;
}


// S_MixChannelsToPaintbuffer  @ 001aee10
void __regparm3 S_MixChannelsToPaintbuffer(int end,int fPaintHiresSounds,int voiceOnly)

{
  undefined1 auVar1 [16];
  byte bVar2;
  short sVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  float fVar18;
  undefined1 auVar19 [12];
  int *piVar20;
  cl_entity_t *pcVar21;
  uint count;
  int iVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  portable_samplepair_t *ppVar26;
  qboolean qVar27;
  int iVar28;
  portable_samplepair_t *ppVar29;
  portable_samplepair_t *ppVar30;
  byte *pbVar31;
  int iVar32;
  uint uVar33;
  uint uVar34;
  int iVar35;
  int iVar36;
  channel_t *ch;
  uint uVar37;
  int iVar38;
  int iVar39;
  bool bVar40;
  uint6 uVar41;
  int iVar44;
  portable_samplepair_t pVar45;
  portable_samplepair_t pVar46;
  ulonglong uVar50;
  undefined1 auVar51 [14];
  ulonglong uVar52;
  int iVar53;
  int local_e0;
  int local_dc;
  int local_bc;
  wavstream_t *local_48;
  int local_34;
  int local_30;
  sfxcache_t *local_20 [4];
  undefined1 auVar42 [12];
  undefined1 auVar43 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  
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
  if (0 < total_channels) {
    ch = channels;
    local_48 = wavstreams;
    local_bc = 0;
    iVar32 = total_channels;
    do {
      if ((ch->sfx != (sfx_t *)0x0) &&
         (local_20[0] = S_LoadSound(ch->sfx,ch), iVar32 = total_channels,
         local_20[0]->length != 0x40000000)) {
        if ((ch->leftvol == 0) && (ch->rightvol == 0)) {
          if (local_20[0]->loopstart < 0) {
            S_FreeChannel(ch);
            iVar32 = total_channels;
          }
        }
        else if ((local_20[0] != (sfxcache_t *)0x0) && (local_20[0]->speed == shm->speed)) {
          local_e0 = paintedtime;
          local_34 = ch->pitch;
          iVar32 = ch->isentence;
          if (iVar32 < 0) {
            local_30 = 0;
          }
          else {
            iVar28 = *(int *)(iVar32 * 0x480 + 0x13cd0e4 + ch->iword * 0x24);
            iVar35 = iVar28 + -100 + local_34;
            if (iVar28 < 1) {
              iVar35 = local_34;
            }
            local_30 = *(int *)(iVar32 * 0x480 + 0x13cd0fc + ch->iword * 0x24);
            local_34 = iVar35;
          }
                    /* Unresolved local var: int oldleft@[???]
                       Unresolved local var: int oldright@[???] */
          do {
            iVar28 = paintedtime;
            pcVar21 = cl_entities;
            iVar32 = total_channels;
            if (end <= local_e0) break;
            iVar32 = ch->end;
            count = iVar32 - local_e0;
            if (end <= iVar32) {
              count = end - local_e0;
            }
            if ((int)count < 1) {
              bVar40 = false;
            }
            else {
              if (((local_20[0]->width == 1) && (iVar35 = ch->entnum, 0 < iVar35)) &&
                 ((ch->entchannel == 2 || (ch->entchannel == 5)))) {
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: char * pdata@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int savg@[???]
                       Unresolved local var: int scount@[???]
                       Unresolved local var: cl_entity_t.conflict1 * pent@[???] */
                uVar33 = (uint)cl_entities[iVar35].mouth.sndcount;
                if (uVar33 < 10) {
                  local_dc = 0;
                  iVar38 = 0;
                  do {
                    bVar2 = local_20[0]->data[iVar38 + ch->pos];
                    uVar33 = uVar33 + 1;
                    uVar37 = (int)(char)bVar2 >> 0x1f;
                    iVar38 = iVar38 + 0x50 + (uint)(bVar2 & 0x1f);
                    local_dc = local_dc + (((int)(char)bVar2 ^ uVar37) - uVar37);
                    if ((int)count <= iVar38) break;
                  } while ((int)uVar33 < 10);
                  local_dc = local_dc + cl_entities[iVar35].mouth.sndavg;
                  cl_entities[iVar35].mouth.sndavg = local_dc;
                  pcVar21[iVar35].mouth.sndcount = (byte)uVar33;
                  if (uVar33 != 10) goto LAB_001aef89;
                }
                else {
                  local_dc = cl_entities[iVar35].mouth.sndavg;
                }
                pcVar21[iVar35].mouth.mouthopen = (byte)(local_dc / 10);
                pcVar21[iVar35].mouth.sndavg = 0;
                pcVar21[iVar35].mouth.sndcount = '\0';
              }
LAB_001aef89:
              iVar35 = ch->leftvol;
              iVar38 = ch->rightvol;
              iVar22 = local_e0 - iVar28;
              fVar18 = (float)iVar38 / g_SND_VoiceOverdrive;
              uVar37 = (uint)((float)iVar35 / g_SND_VoiceOverdrive);
              ch->leftvol = uVar37;
              uVar33 = (uint)fVar18;
              ch->rightvol = uVar33;
              if (local_20[0]->width == 1) {
                if ((local_34 == 100 && local_30 == 0) || (ch->isentence < 0)) {
                  iVar39 = (int)uVar37 >> 3;
                  iVar36 = (int)uVar33 >> 3;
                  if (local_e0 == iVar28) {
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: int * lscale@[???]
                       Unresolved local var: int * rscale@[???]
                       Unresolved local var: uchar * sfx@[???]
                       Unresolved local var: int i@[???] */
                    if (0xff < (int)uVar37) {
                      iVar39 = 0x1f;
                      ch->leftvol = 0xff;
                    }
                    if (0xff < (int)uVar33) {
                      ch->rightvol = 0xff;
                      iVar36 = 0x1f;
                    }
                    iVar28 = ch->pos;
                    uVar33 = 0;
                    do {
                      iVar22 = snd_scaletable[iVar36][local_20[0]->data[uVar33 + iVar28]];
                      paintbuffer[uVar33].left =
                           paintbuffer[uVar33].left +
                           snd_scaletable[iVar39][local_20[0]->data[uVar33 + iVar28]];
                      paintbuffer[uVar33].right = paintbuffer[uVar33].right + iVar22;
                      uVar33 = uVar33 + 1;
                    } while (count != uVar33);
                    ch->pos = iVar28 + count;
                    bVar40 = false;
                  }
                  else {
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: int * lscale@[???]
                       Unresolved local var: int * rscale@[???]
                       Unresolved local var: uchar * sfx@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: portable_samplepair_t * pbuffer@[???] */
                    if (0xff < (int)uVar37) {
                      ch->leftvol = 0xff;
                      iVar39 = 0x1f;
                    }
                    if (0xff < (int)uVar33) {
                      ch->rightvol = 0xff;
                      iVar36 = 0x1f;
                    }
                    iVar28 = ch->pos;
                    pbVar31 = local_20[0]->data + iVar28;
                    ppVar29 = paintbuffer + iVar22;
                    do {
                      bVar2 = *pbVar31;
                      pbVar31 = pbVar31 + 1;
                      iVar4 = snd_scaletable[iVar36][bVar2];
                      ppVar29->left = ppVar29->left + snd_scaletable[iVar39][bVar2];
                      ppVar29->right = ppVar29->right + iVar4;
                      ppVar29 = ppVar29 + 1;
                    } while (ppVar29 != paintbuffer + iVar22 + count);
                    ch->pos = iVar28 + count;
                    bVar40 = false;
                  }
                }
                else {
                  iVar28 = VOX_FPaintPitchChannelFrom8Offs
                                     (paintbuffer,ch,local_20[0],count,local_34,local_30,iVar22);
                  bVar40 = iVar28 != 0;
                }
              }
              else {
                    /* Unresolved local var: char[4096] copyBuf@[???]
                       Unresolved local var: short * pSrcData@[???] */
                iVar28 = ch->pos;
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: int left@[???]
                       Unresolved local var: int right@[???]
                       Unresolved local var: int leftvol@[???]
                       Unresolved local var: int rightvol@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: portable_samplepair_t * pbuffer@[???] */
                iVar39 = iVar28 * 2;
                ppVar30 = (portable_samplepair_t *)(local_20[0]->data + iVar39);
                ppVar29 = paintbuffer + iVar22;
                if ((ppVar29 < (portable_samplepair_t *)(local_20[0]->data + count * 2 + iVar28 * 2)
                     && ppVar30 < paintbuffer + iVar22 + count) || (count < 8)) {
                  pbVar31 = local_20[0]->data + iVar39;
                  do {
                    sVar3 = *(short *)pbVar31;
                    pbVar31 = pbVar31 + 2;
                    ppVar29->left = ppVar29->left + ((int)(uVar37 * (int)sVar3) >> 8);
                    ppVar29->right = ppVar29->right + ((int)((int)sVar3 * uVar33) >> 8);
                    ppVar29 = ppVar29 + 1;
                  } while (ppVar29 != paintbuffer + iVar22 + count);
                }
                else {
                  uVar23 = count - 8 >> 3;
                  uVar24 = uVar23 + 1;
                  uVar25 = uVar24 * 8;
                  uVar34 = 0;
                  ppVar26 = ppVar29;
                  do {
                    auVar1 = *(undefined1 (*) [16])ppVar30;
                    iVar6 = ppVar29[4].left;
                    iVar7 = ppVar29[4].right;
                    iVar8 = ppVar29[5].left;
                    iVar9 = ppVar29[5].right;
                    auVar51 = SUB1614((undefined1  [16])0x0,2);
                    auVar49._0_12_ = auVar1._0_12_;
                    auVar49._12_2_ = auVar1._6_2_;
                    auVar49._14_2_ = -(ushort)(auVar1._6_2_ < 0);
                    auVar48._12_4_ = auVar49._12_4_;
                    auVar48._0_10_ = auVar1._0_10_;
                    auVar48._10_2_ = -(ushort)(auVar1._4_2_ < 0);
                    auVar47._10_6_ = auVar48._10_6_;
                    auVar47._0_8_ = auVar1._0_8_;
                    auVar47._8_2_ = auVar1._4_2_;
                    uVar50 = auVar47._8_8_;
                    auVar19._4_8_ = uVar50;
                    auVar19._2_2_ = -(ushort)(auVar1._2_2_ < 0);
                    auVar19._0_2_ = auVar1._2_2_;
                    iVar44 = CONCAT22(-(ushort)(auVar1._0_2_ < 0),auVar1._0_2_);
                    iVar10 = ppVar29[2].left;
                    iVar11 = ppVar29[2].right;
                    iVar12 = ppVar29[3].left;
                    iVar13 = ppVar29[3].right;
                    uVar41 = CONCAT24(auVar1._10_2_,
                                      CONCAT22(-(ushort)(auVar1._8_2_ < 0),auVar1._8_2_));
                    auVar42._0_8_ = CONCAT26(-(ushort)(auVar1._10_2_ < auVar51._8_2_),uVar41);
                    auVar42._8_2_ = auVar1._12_2_;
                    auVar42._10_2_ = -(ushort)(auVar1._12_2_ < auVar51._10_2_);
                    auVar43._12_2_ = auVar1._14_2_;
                    auVar43._0_12_ = auVar42;
                    auVar43._14_2_ = -(ushort)(auVar1._14_2_ < auVar51._12_2_);
                    piVar20 = &ppVar29->left;
                    piVar5 = &ppVar29->right;
                    iVar36 = ppVar29[1].left;
                    iVar4 = ppVar29[1].right;
                    iVar14 = ppVar29[6].left;
                    iVar15 = ppVar29[6].right;
                    iVar16 = ppVar29[7].left;
                    iVar17 = ppVar29[7].right;
                    uVar52 = auVar43._8_8_;
                    iVar53 = (int)((ulonglong)auVar42._0_8_ >> 0x20);
                    uVar34 = uVar34 + 1;
                    ppVar29 = ppVar29 + 8;
                    ppVar30 = ppVar30 + 2;
                    pVar45.right = *piVar5 + ((int)(iVar44 * uVar33) >> 8);
                    pVar45.left = ((int)(uVar37 * iVar44) >> 8) + *piVar20;
                    *ppVar26 = pVar45;
                    ppVar26[1].left = ((int)(uVar37 * auVar19._0_4_) >> 8) + iVar36;
                    ppVar26[1].right = iVar4 + ((int)(auVar19._0_4_ * uVar33) >> 8);
                    ppVar26[2].left =
                         ((int)((ulonglong)uVar37 * (uVar50 & 0xffffffff)) >> 8) + iVar10;
                    ppVar26[2].right =
                         iVar11 + ((int)((uVar50 & 0xffffffff) * (ulonglong)uVar33) >> 8);
                    ppVar26[3].left = ((int)((ulonglong)uVar37 * (uVar50 >> 0x20)) >> 8) + iVar12;
                    ppVar26[3].right = iVar13 + ((int)((uVar50 >> 0x20) * (ulonglong)uVar33) >> 8);
                    pVar46.right = ((int)(((ulonglong)uVar41 & 0xffffffff) * (ulonglong)uVar33) >> 8
                                   ) + iVar7;
                    pVar46.left = iVar6 + ((int)((ulonglong)uVar37 *
                                                ((ulonglong)uVar41 & 0xffffffff)) >> 8);
                    ppVar26[6].left = iVar14 + ((int)(uVar37 * auVar42._8_4_) >> 8);
                    ppVar26[6].right =
                         ((int)((uVar52 & 0xffffffff) * (ulonglong)uVar33) >> 8) + iVar15;
                    ppVar26[7].left = iVar16 + ((int)((ulonglong)uVar37 * (uVar52 >> 0x20)) >> 8);
                    ppVar26[7].right = ((int)((uVar52 >> 0x20) * (ulonglong)uVar33) >> 8) + iVar17;
                    ppVar26[4] = pVar46;
                    ppVar26[5].left = iVar8 + ((int)(uVar37 * iVar53) >> 8);
                    ppVar26[5].right = ((int)(iVar53 * uVar33) >> 8) + iVar9;
                    ppVar26 = ppVar26 + 8;
                  } while (uVar34 < uVar24);
                  if (count != uVar25) {
                    sVar3 = *(short *)(local_20[0][1].data + iVar39 + uVar23 * 0x10 + -8);
                    ppVar29 = paintbuffer + iVar22 + uVar24 * 8;
                    ppVar29->left = ppVar29->left + ((int)(uVar37 * (int)sVar3) >> 8);
                    ppVar29->right = ppVar29->right + ((int)((int)sVar3 * uVar33) >> 8);
                    if ((int)(uVar25 + 1) < (int)count) {
                      sVar3 = *(short *)(local_20[0][1].data + iVar39 + uVar23 * 0x10 + -6);
                      ppVar29 = paintbuffer + iVar22 + uVar25 + 1;
                      ppVar29->left = ppVar29->left + ((int)(uVar37 * (int)sVar3) >> 8);
                      ppVar29->right = ppVar29->right + ((int)((int)sVar3 * uVar33) >> 8);
                      if ((int)(uVar25 + 2) < (int)count) {
                        sVar3 = *(short *)(local_20[0][1].data + iVar39 + uVar23 * 0x10 + -4);
                        ppVar29 = paintbuffer + iVar22 + uVar25 + 2;
                        ppVar29->left = ppVar29->left + ((int)(uVar37 * (int)sVar3) >> 8);
                        ppVar29->right = ppVar29->right + ((int)((int)sVar3 * uVar33) >> 8);
                        if ((int)(uVar25 + 3) < (int)count) {
                          sVar3 = *(short *)(local_20[0][1].data + iVar39 + uVar23 * 0x10 + -2);
                          ppVar29 = paintbuffer + iVar22 + uVar25 + 3;
                          ppVar29->left = ppVar29->left + ((int)(uVar37 * (int)sVar3) >> 8);
                          ppVar29->right = ppVar29->right + ((int)((int)sVar3 * uVar33) >> 8);
                          if ((int)(uVar25 + 4) < (int)count) {
                            sVar3 = *(short *)(local_20[0][1].data + iVar39 + uVar23 * 0x10);
                            ppVar29 = paintbuffer + iVar22 + uVar25 + 4;
                            ppVar29->left = ppVar29->left + ((int)(uVar37 * (int)sVar3) >> 8);
                            ppVar29->right = ppVar29->right + ((int)((int)sVar3 * uVar33) >> 8);
                            if ((int)(uVar25 + 5) < (int)count) {
                              sVar3 = *(short *)(local_20[0][1].data + iVar39 + uVar23 * 0x10 + 2);
                              ppVar29 = paintbuffer + iVar22 + uVar25 + 5;
                              ppVar29->left = ppVar29->left + ((int)(uVar37 * (int)sVar3) >> 8);
                              ppVar29->right = ppVar29->right + ((int)((int)sVar3 * uVar33) >> 8);
                              if ((int)(uVar25 + 6) < (int)count) {
                                ppVar29 = paintbuffer + iVar22 + uVar25 + 6;
                                sVar3 = *(short *)(local_20[0][2].data +
                                                  iVar39 + uVar23 * 0x10 + -0x14);
                                ppVar29->left = ppVar29->left + ((int)(uVar37 * (int)sVar3) >> 8);
                                ppVar29->right = ppVar29->right + ((int)((int)sVar3 * uVar33) >> 8);
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                ch->pos = iVar28 + count;
                bVar40 = false;
              }
              local_e0 = local_e0 + count;
              ch->leftvol = iVar35;
              ch->rightvol = iVar38;
              if (ch->entchannel == 5) {
                local_48->csamplesplayed = local_48->csamplesplayed + count;
              }
            }
          } while (((local_e0 < iVar32) && (!bVar40)) ||
                  (qVar27 = S_CheckWavEnd(ch,local_20,local_e0,local_bc), iVar32 = total_channels,
                  qVar27 == false));
        }
      }
      local_bc = local_bc + 1;
      ch = ch + 1;
      local_48 = local_48 + 1;
    } while (local_bc < iVar32);
  }
  return;
}


// S_MixChannelsToPaintbuffer  @ 001af800
/* WARNING: Removing unreachable block (ram,0x001afd1d) */

void __regparm3 S_MixChannelsToPaintbuffer(int end,int fPaintHiresSounds,int voiceOnly)

{
  undefined1 auVar1 [16];
  byte bVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  float fVar17;
  undefined1 auVar18 [12];
  cl_entity_t *pcVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  int *piVar24;
  qboolean qVar25;
  portable_samplepair_t *ppVar26;
  int iVar27;
  uint uVar28;
  int iVar29;
  uint uVar30;
  int *piVar31;
  uint uVar32;
  byte *pbVar33;
  int iVar34;
  channel_t *ch;
  int iVar35;
  int in_GS_OFFSET;
  bool bVar36;
  uint6 uVar37;
  int iVar40;
  ulonglong uVar44;
  undefined1 auVar45 [14];
  ulonglong uVar46;
  int iVar47;
  int local_10e8;
  uint local_10e4;
  uint local_10e0;
  int local_10d0;
  uint local_1098;
  uint local_1094;
  int local_1090;
  wavstream_t *local_104c;
  int local_1034;
  int local_1030;
  sfxcache_t *local_1024;
  byte local_1020 [4096];
  int local_20;
  undefined1 auVar38 [12];
  undefined1 auVar39 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  
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
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (0 < total_channels) {
    local_104c = wavstreams;
    ch = channels;
    local_10d0 = 0;
    iVar34 = total_channels;
    do {
      if (ch->sfx != (sfx_t *)0x0) {
        local_1024 = S_LoadSound(ch->sfx,ch);
        iVar4 = local_1024->length;
        iVar34 = total_channels;
        if (iVar4 == 0x40000000) {
          if (fPaintHiresSounds != 0) {
            iVar27 = ch->leftvol;
joined_r0x001af860:
            if ((iVar27 == 0) && (ch->rightvol == 0)) {
              if (local_1024->loopstart < 0) {
                S_FreeChannel(ch);
                iVar34 = total_channels;
              }
            }
            else if ((local_1024 != (sfxcache_t *)0x0) && (shm->speed < local_1024->speed)) {
              local_10e8 = paintedtime;
              local_1034 = ch->pitch;
              iVar34 = ch->isentence;
              if (iVar34 < 0) {
                local_1030 = 0;
              }
              else {
                iVar27 = *(int *)(iVar34 * 0x480 + 0x13cd0e4 + ch->iword * 0x24);
                iVar20 = iVar27 + -100 + local_1034;
                if (iVar27 < 1) {
                  iVar20 = local_1034;
                }
                local_1030 = *(int *)(iVar34 * 0x480 + 0x13cd0fc + ch->iword * 0x24);
                local_1034 = iVar20;
              }
                    /* Unresolved local var: int oldleft@[???]
                       Unresolved local var: int oldright@[???] */
              bVar2 = 0;
LAB_001af970:
              iVar34 = total_channels;
              if ((bool)(bVar2 ^ 1)) {
                do {
                  iVar27 = paintedtime;
                  pcVar19 = cl_entities;
                  iVar34 = total_channels;
                  if (end <= local_10e8) break;
                  iVar20 = (local_1024->length >> 1) + (ch->end - local_1024->length);
                  iVar34 = end - local_10e8;
                  if (iVar20 < end) {
                    iVar34 = iVar20 - local_10e8;
                  }
                  if (iVar4 == 0x40000000) {
                    bVar2 = 1;
                    if ((local_1024->width != 2) || (local_1024->stereo != 0)) goto LAB_001af970;
                    if (0 < iVar34 * 2) goto LAB_001af9e3;
LAB_001afcd0:
                    bVar36 = false;
                  }
                  else {
                    if (iVar34 * 2 < 1) goto LAB_001afcd0;
                    if (((local_1024->width == 1) && (iVar21 = ch->entnum, 0 < iVar21)) &&
                       ((ch->entchannel == 2 || (ch->entchannel == 5)))) {
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: char * pdata@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int savg@[???]
                       Unresolved local var: int scount@[???]
                       Unresolved local var: cl_entity_t.conflict1 * pent@[???] */
                      uVar28 = (uint)cl_entities[iVar21].mouth.sndcount;
                      if (uVar28 < 10) {
                        iVar29 = 0;
                        local_10e4 = 0;
                        do {
                          bVar2 = local_1024->data[iVar29 + ch->pos];
                          uVar28 = uVar28 + 1;
                          uVar30 = (int)(char)bVar2 >> 0x1f;
                          iVar29 = iVar29 + 0x50 + (uint)(bVar2 & 0x1f);
                          local_10e4 = local_10e4 + (((int)(char)bVar2 ^ uVar30) - uVar30);
                          if (iVar34 * 2 <= iVar29) break;
                        } while ((int)uVar28 < 10);
                        iVar29 = local_10e4 + cl_entities[iVar21].mouth.sndavg;
                        cl_entities[iVar21].mouth.sndavg = iVar29;
                        pcVar19[iVar21].mouth.sndcount = (byte)uVar28;
                        if (uVar28 != 10) goto LAB_001af9e3;
                      }
                      else {
                        iVar29 = cl_entities[iVar21].mouth.sndavg;
                      }
                      pcVar19[iVar21].mouth.sndcount = '\0';
                      pcVar19[iVar21].mouth.mouthopen = (byte)(iVar29 / 10);
                      pcVar19[iVar21].mouth.sndavg = 0;
                      local_1098 = ch->leftvol;
                      iVar21 = (local_10e8 - iVar27) * 2;
                      local_1094 = ch->rightvol;
LAB_001afa0c:
                      uVar28 = iVar34 * 2;
                      fVar17 = (float)(int)local_1094 / g_SND_VoiceOverdrive;
                      local_10e4 = (uint)((float)(int)local_1098 / g_SND_VoiceOverdrive);
                      ch->leftvol = local_10e4;
                      local_10e0 = (uint)fVar17;
                      ch->rightvol = local_10e0;
                      if (local_1024->width == 1) goto LAB_001afe52;
                    /* Unresolved local var: char[4096] copyBuf@[???]
                       Unresolved local var: short * pSrcData@[???] */
                      local_1090 = ch->pos;
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: int left@[???]
                       Unresolved local var: int right@[???]
                       Unresolved local var: int leftvol@[???]
                       Unresolved local var: int rightvol@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: portable_samplepair_t * pbuffer@[???] */
                      iVar21 = iVar21 << 3;
                      pbVar33 = local_1024->data + local_1090 * 2;
LAB_001afa60:
                      uVar30 = 1;
                      if (0 < (int)uVar28) {
                        uVar30 = uVar28;
                      }
                      piVar24 = (int *)((int)&paintbuffer[0].left + iVar21);
                      if ((pbVar33 < (byte *)((int)&paintbuffer[uVar30].left + iVar21) &&
                           piVar24 < pbVar33 + uVar30 * 2) || (uVar30 < 8)) {
                        iVar34 = 0;
                        do {
                          sVar3 = *(short *)(pbVar33 + iVar34 * 2);
                          iVar34 = iVar34 + 1;
                          *piVar24 = *piVar24 + ((int)(local_10e4 * (int)sVar3) >> 8);
                          piVar24[1] = piVar24[1] + ((int)((int)sVar3 * local_10e0) >> 8);
                          piVar24 = piVar24 + 2;
                        } while (iVar34 < (int)uVar28);
                      }
                      else {
                        uVar22 = (uVar30 - 8 >> 3) + 1;
                        uVar23 = uVar22 * 8;
                        if ((int)uVar28 < 8) {
                          uVar23 = 0;
                        }
                        else {
                          piVar31 = (int *)((int)&paintbuffer[2].left + iVar21);
                          uVar32 = 0;
                          do {
                            iVar5 = piVar31[4];
                            iVar6 = piVar31[5];
                            iVar7 = piVar31[6];
                            iVar8 = piVar31[7];
                            auVar1 = *(undefined1 (*) [16])(pbVar33 + uVar32 * 0x10);
                            auVar45 = SUB1614((undefined1  [16])0x0,2);
                            auVar43._0_12_ = auVar1._0_12_;
                            auVar43._12_2_ = auVar1._6_2_;
                            auVar43._14_2_ = -(ushort)(auVar1._6_2_ < 0);
                            auVar42._12_4_ = auVar43._12_4_;
                            auVar42._0_10_ = auVar1._0_10_;
                            auVar42._10_2_ = -(ushort)(auVar1._4_2_ < 0);
                            auVar41._10_6_ = auVar42._10_6_;
                            auVar41._0_8_ = auVar1._0_8_;
                            auVar41._8_2_ = auVar1._4_2_;
                            uVar44 = auVar41._8_8_;
                            auVar18._4_8_ = uVar44;
                            auVar18._2_2_ = -(ushort)(auVar1._2_2_ < 0);
                            auVar18._0_2_ = auVar1._2_2_;
                            iVar40 = CONCAT22(-(ushort)(auVar1._0_2_ < 0),auVar1._0_2_);
                            iVar9 = *piVar31;
                            iVar10 = piVar31[1];
                            iVar11 = piVar31[2];
                            iVar12 = piVar31[3];
                            uVar37 = CONCAT24(auVar1._10_2_,
                                              CONCAT22(-(ushort)(auVar1._8_2_ < 0),auVar1._8_2_));
                            auVar38._0_8_ =
                                 CONCAT26(-(ushort)(auVar1._10_2_ < auVar45._8_2_),uVar37);
                            auVar38._8_2_ = auVar1._12_2_;
                            auVar38._10_2_ = -(ushort)(auVar1._12_2_ < auVar45._10_2_);
                            auVar39._12_2_ = auVar1._14_2_;
                            auVar39._0_12_ = auVar38;
                            auVar39._14_2_ = -(ushort)(auVar1._14_2_ < auVar45._12_2_);
                            iVar34 = piVar31[-4];
                            iVar27 = piVar31[-3];
                            iVar29 = piVar31[-2];
                            iVar35 = piVar31[-1];
                            iVar13 = piVar31[8];
                            iVar14 = piVar31[9];
                            iVar15 = piVar31[10];
                            iVar16 = piVar31[0xb];
                            uVar46 = auVar39._8_8_;
                            iVar47 = (int)((ulonglong)auVar38._0_8_ >> 0x20);
                            uVar32 = uVar32 + 1;
                            piVar31 = piVar31 + 0x10;
                            piVar24[4] = ((int)((ulonglong)local_10e4 * (uVar44 & 0xffffffff)) >> 8)
                                         + iVar9;
                            piVar24[5] = iVar10 + ((int)((uVar44 & 0xffffffff) *
                                                        (ulonglong)local_10e0) >> 8);
                            piVar24[6] = ((int)((ulonglong)local_10e4 * (uVar44 >> 0x20)) >> 8) +
                                         iVar11;
                            piVar24[7] = iVar12 + ((int)((uVar44 >> 0x20) * (ulonglong)local_10e0)
                                                  >> 8);
                            *(ulonglong *)piVar24 =
                                 CONCAT44(iVar27 + ((int)(iVar40 * local_10e0) >> 8),
                                          ((int)(local_10e4 * iVar40) >> 8) + iVar34);
                            piVar24[2] = ((int)(local_10e4 * auVar18._0_4_) >> 8) + iVar29;
                            piVar24[3] = iVar35 + ((int)(auVar18._0_4_ * local_10e0) >> 8);
                            piVar24[0xc] = iVar13 + ((int)(local_10e4 * auVar38._8_4_) >> 8);
                            piVar24[0xd] = ((int)((uVar46 & 0xffffffff) * (ulonglong)local_10e0) >>
                                           8) + iVar14;
                            piVar24[0xe] = iVar15 + ((int)((ulonglong)local_10e4 * (uVar46 >> 0x20))
                                                    >> 8);
                            piVar24[0xf] = ((int)((uVar46 >> 0x20) * (ulonglong)local_10e0) >> 8) +
                                           iVar16;
                            *(ulonglong *)(piVar24 + 8) =
                                 CONCAT44(((int)(((ulonglong)uVar37 & 0xffffffff) *
                                                (ulonglong)local_10e0) >> 8) + iVar6,
                                          iVar5 + ((int)((ulonglong)local_10e4 *
                                                        ((ulonglong)uVar37 & 0xffffffff)) >> 8));
                            piVar24[10] = iVar7 + ((int)(local_10e4 * iVar47) >> 8);
                            piVar24[0xb] = ((int)(iVar47 * local_10e0) >> 8) + iVar8;
                            piVar24 = piVar24 + 0x10;
                          } while (uVar32 < uVar22);
                          if (uVar23 == uVar30) goto LAB_001b00cc;
                        }
                        sVar3 = *(short *)(pbVar33 + uVar23 * 2);
                        piVar24 = (int *)((int)&paintbuffer[uVar23].left + iVar21);
                        *piVar24 = *piVar24 + ((int)(local_10e4 * (int)sVar3) >> 8);
                        piVar24[1] = piVar24[1] + ((int)((int)sVar3 * local_10e0) >> 8);
                        iVar34 = uVar23 + 1;
                        if (iVar34 < (int)uVar28) {
                          sVar3 = *(short *)(pbVar33 + iVar34 * 2);
                          piVar24 = (int *)((int)&paintbuffer[iVar34].left + iVar21);
                          *piVar24 = *piVar24 + ((int)(local_10e4 * (int)sVar3) >> 8);
                          piVar24[1] = piVar24[1] + ((int)((int)sVar3 * local_10e0) >> 8);
                          iVar34 = uVar23 + 2;
                          if (iVar34 < (int)uVar28) {
                            sVar3 = *(short *)(pbVar33 + iVar34 * 2);
                            piVar24 = (int *)((int)&paintbuffer[iVar34].left + iVar21);
                            *piVar24 = *piVar24 + ((int)(local_10e4 * (int)sVar3) >> 8);
                            piVar24[1] = piVar24[1] + ((int)((int)sVar3 * local_10e0) >> 8);
                            iVar34 = uVar23 + 3;
                            if (iVar34 < (int)uVar28) {
                              sVar3 = *(short *)(pbVar33 + iVar34 * 2);
                              piVar24 = (int *)((int)&paintbuffer[iVar34].left + iVar21);
                              *piVar24 = *piVar24 + ((int)(local_10e4 * (int)sVar3) >> 8);
                              piVar24[1] = piVar24[1] + ((int)((int)sVar3 * local_10e0) >> 8);
                              iVar34 = uVar23 + 4;
                              if (iVar34 < (int)uVar28) {
                                sVar3 = *(short *)(pbVar33 + iVar34 * 2);
                                piVar24 = (int *)((int)&paintbuffer[iVar34].left + iVar21);
                                *piVar24 = *piVar24 + ((int)(local_10e4 * (int)sVar3) >> 8);
                                piVar24[1] = piVar24[1] + ((int)((int)sVar3 * local_10e0) >> 8);
                                iVar34 = uVar23 + 5;
                                if (iVar34 < (int)uVar28) {
                                  iVar27 = uVar23 + 6;
                                  sVar3 = *(short *)(pbVar33 + iVar34 * 2);
                                  piVar24 = (int *)((int)&paintbuffer[iVar34].left + iVar21);
                                  *piVar24 = *piVar24 + ((int)(local_10e4 * (int)sVar3) >> 8);
                                  piVar24[1] = piVar24[1] + ((int)((int)sVar3 * local_10e0) >> 8);
                                  if (iVar27 < (int)uVar28) {
                                    sVar3 = *(short *)(pbVar33 + iVar27 * 2);
                                    piVar24 = (int *)((int)&paintbuffer[iVar27].left + iVar21);
                                    *piVar24 = *piVar24 + ((int)(local_10e4 * (int)sVar3) >> 8);
                                    piVar24[1] = piVar24[1] + ((int)((int)sVar3 * local_10e0) >> 8);
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
LAB_001b00cc:
                      ch->pos = local_1090 + uVar28;
                      bVar36 = false;
                    }
                    else {
LAB_001af9e3:
                      local_1098 = ch->leftvol;
                      local_10e0 = ch->rightvol;
                      iVar21 = (local_10e8 - iVar27) * 2;
                      local_1094 = local_10e0;
                      if (iVar4 != 0x40000000) goto LAB_001afa0c;
                      local_10e4 = local_1098;
                      if (local_1024->width != 1) {
                        uVar28 = (*(code *)local_1024->loopstart)
                                           (local_1024,local_1020,0x1000,ch->pos,iVar34 * 2);
                        if (0 < (int)uVar28) {
                          local_10e4 = ch->leftvol;
                          iVar21 = (local_10e8 - iVar27) * 0x10;
                          pbVar33 = local_1020;
                          local_10e0 = ch->rightvol;
                          local_1090 = ch->pos;
                          goto LAB_001afa60;
                        }
                        local_1090 = ch->pos;
                        goto LAB_001b00cc;
                      }
LAB_001afe52:
                      uVar28 = iVar34 * 2;
                      if ((local_1034 == 100 && local_1030 == 0) || (ch->isentence < 0)) {
                        iVar35 = (int)local_10e0 >> 3;
                        iVar29 = (int)local_10e4 >> 3;
                        if (local_10e8 == iVar27) {
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: int * lscale@[???]
                       Unresolved local var: int * rscale@[???]
                       Unresolved local var: uchar * sfx@[???]
                       Unresolved local var: int i@[???] */
                          if (0xff < (int)local_10e4) {
                            iVar29 = 0x1f;
                            ch->leftvol = 0xff;
                          }
                          if (0xff < (int)local_10e0) {
                            ch->rightvol = 0xff;
                            iVar35 = 0x1f;
                          }
                          iVar34 = ch->pos;
                          uVar30 = 0;
                          do {
                            iVar27 = snd_scaletable[iVar35][local_1024->data[uVar30 + iVar34]];
                            paintbuffer[uVar30].left =
                                 paintbuffer[uVar30].left +
                                 snd_scaletable[iVar29][local_1024->data[uVar30 + iVar34]];
                            paintbuffer[uVar30].right = paintbuffer[uVar30].right + iVar27;
                            uVar30 = uVar30 + 1;
                          } while (uVar30 != uVar28);
                          ch->pos = iVar34 + uVar28;
                          bVar36 = false;
                        }
                        else {
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: int * lscale@[???]
                       Unresolved local var: int * rscale@[???]
                       Unresolved local var: uchar * sfx@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: portable_samplepair_t * pbuffer@[???] */
                          if (0xff < (int)local_10e4) {
                            ch->leftvol = 0xff;
                            iVar29 = 0x1f;
                          }
                          if (0xff < (int)local_10e0) {
                            ch->rightvol = 0xff;
                            iVar35 = 0x1f;
                          }
                          iVar27 = ch->pos;
                          pbVar33 = local_1024->data + iVar27;
                          ppVar26 = paintbuffer + iVar21;
                          do {
                            bVar2 = *pbVar33;
                            pbVar33 = pbVar33 + 1;
                            iVar5 = snd_scaletable[iVar35][bVar2];
                            ppVar26->left = ppVar26->left + snd_scaletable[iVar29][bVar2];
                            ppVar26->right = ppVar26->right + iVar5;
                            ppVar26 = ppVar26 + 1;
                          } while (ppVar26 != paintbuffer + iVar21 + iVar34 * 2);
                          ch->pos = iVar27 + uVar28;
                          bVar36 = false;
                        }
                      }
                      else {
                        iVar34 = VOX_FPaintPitchChannelFrom8Offs
                                           (paintbuffer,ch,local_1024,uVar28,local_1034,local_1030,
                                            iVar21);
                        bVar36 = iVar34 != 0;
                      }
                    }
                    local_10e8 = local_10e8 + ((int)uVar28 >> 1);
                    ch->leftvol = local_1098;
                    ch->rightvol = local_1094;
                    if (ch->entchannel == 5) {
                      local_104c->csamplesplayed = local_104c->csamplesplayed + uVar28;
                    }
                  }
                  if ((local_10e8 < iVar20) && (bVar2 = 0, !bVar36)) goto LAB_001af970;
                  qVar25 = S_CheckWavEnd(ch,&local_1024,local_10e8,local_10d0);
                  iVar34 = total_channels;
                  if (qVar25 != false) break;
                } while( true );
              }
            }
          }
        }
        else if (fPaintHiresSounds == 0) {
          iVar27 = ch->leftvol;
          goto joined_r0x001af860;
        }
      }
      local_10d0 = local_10d0 + 1;
      ch = ch + 1;
      local_104c = local_104c + 1;
    } while (local_10d0 < iVar34);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// S_PaintChannels  @ 001b02b0
void S_PaintChannels(int endtime)

{
  int iVar1;
  uchar *puVar2;
  float fVar3;
  portable_samplepair_t *ppVar4;
  int voiceOnly;
  portable_samplepair_t *ppVar5;
  uint uVar6;
  int fPaintHiresSounds;
  int iVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint local_24;
  
  uVar6 = paintedtime;
  do {
    paintedtime = uVar6;
    if (endtime <= paintedtime) {
      return;
    }
    iVar10 = endtime - paintedtime;
    local_24 = endtime;
    if (0x200 < iVar10) {
      local_24 = paintedtime + 0x200;
      iVar10 = 0x200;
    }
    Q_memset(paintbuffer,0,iVar10 * 8);
    if ((cl.paused == false) && (s_careerAudioPaused == 0)) {
      S_MixChannelsToPaintbuffer(local_24,fPaintHiresSounds,voiceOnly);
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int count2x@[???] */
                    /* Unresolved local var: int fReset@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float roomType@[???] */
    if ((hisound.value == 0.0) && (sxroom_off.value == 0.0)) {
      SX_RoomFX(iVar10,1,1);
    }
    fVar3 = hisound.value;
    iVar7 = iVar10 * 2 + -1;
    if (1 < iVar10) {
      ppVar5 = (portable_samplepair_t *)(iVar10 * 8 + 0x13cb0b8);
      piVar8 = (int *)(iVar10 * 0x10 + 0x13cb0b8);
      do {
        ppVar4 = ppVar5 + -1;
        iVar1 = ppVar5->right;
        *piVar8 = ppVar5->left;
        piVar8[1] = iVar1;
        piVar8[-2] = ppVar4->left + ppVar5->left >> 1;
        piVar8[-1] = ppVar5[-1].right + ppVar5->right >> 1;
        ppVar5 = ppVar4;
        piVar8 = piVar8 + -4;
      } while (ppVar4 != paintbuffer);
    }
    paintbuffer[1].left = paintbuffer[0].left;
    paintbuffer[1].right = paintbuffer[0].right;
    paintbuffer[0].left = paintbuffer[0].left + S_PaintChannels::paintprev.left >> 1;
    paintbuffer[0].right = paintbuffer[0].right + S_PaintChannels::paintprev.right >> 1;
    S_PaintChannels::paintprev.left = paintbuffer[iVar7].left;
    S_PaintChannels::paintprev.right = paintbuffer[iVar7].right;
    if (fVar3 <= 0.0) {
LAB_001b057d:
      if ((cl.paused == false) && (s_careerAudioPaused == 0)) {
        S_MixChannelsToPaintbuffer(local_24,1,0);
      }
    }
    else {
      if ((cl.paused == false) && (s_careerAudioPaused == 0)) {
        S_MixChannelsToPaintbuffer(local_24,0,iVar7);
        if (sxroom_off.value == 0.0) goto LAB_001b056c;
        goto LAB_001b057d;
      }
      if (sxroom_off.value == 0.0) {
LAB_001b056c:
        SX_RoomFX(iVar10 * 2,1,1);
        goto LAB_001b057d;
      }
    }
    iVar10 = paintedtime;
    if (paintedtime <= s_rawend) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int s@[???]
                       Unresolved local var: int stop@[???] */
      uVar6 = s_rawend;
      if ((int)local_24 <= s_rawend) {
        uVar6 = local_24;
      }
      if (paintedtime < (int)uVar6) {
        ppVar5 = paintbuffer;
        uVar11 = paintedtime;
        do {
          uVar9 = uVar11 + 1;
          ppVar5->left = ppVar5->left + s_rawsamples[uVar11 & 0x1fff].left / 2;
          ppVar5->right = ppVar5->right + s_rawsamples[uVar11 & 0x1fff].right / 2;
          ppVar5 = ppVar5 + 1;
          uVar11 = uVar9;
        } while (uVar6 != uVar9);
      }
    }
                    /* Unresolved local var: int lpos@[???]
                       Unresolved local var: int lpaintedtime@[???]
                       Unresolved local var: DWORD * pbuf@[???]
                       Unresolved local var: int endtime@[???] */
    puVar2 = shm->buffer;
    snd_vol = (int)(volume.value * 256.0);
    snd_p = &paintbuffer[0].left;
    for (uVar11 = iVar10 * 2; uVar6 = local_24, (int)uVar11 < (int)(local_24 * 2);
        uVar11 = uVar11 + (snd_linear_count >> 1)) {
      uVar6 = (shm->samples >> 1) - 1U & uVar11;
      snd_out = (short *)(puVar2 + uVar6 * 4);
      iVar7 = local_24 * 2 - uVar11;
      iVar10 = (shm->samples >> 1) - uVar6;
      if (iVar7 < iVar10) {
        iVar10 = iVar7;
      }
      snd_linear_count = iVar10 * 2;
      Snd_WriteLinearBlastStereo16();
      snd_p = snd_p + snd_linear_count;
    }
  } while( true );
}


// S_Play  @ 001a7610
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_Play(void)

{
  int iVar1;
  char *pcVar2;
  sfx_t *s;
  int arg;
  int in_GS_OFFSET;
  char local_110 [251];
  undefined1 local_15;
  int local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: sfx_t * sfx@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (speak_enable.value != 0.0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: sfx_t * sfx@[???] */
    iVar1 = Cmd_Argc();
    arg = 1;
    if (1 < iVar1) {
      do {
        pcVar2 = Cmd_Argv(arg);
        Q_strncpy(local_110,pcVar2,0xfb);
        local_15 = 0;
        pcVar2 = Cmd_Argv(arg);
        pcVar2 = Q_strrchr(pcVar2,'.');
        if (pcVar2 == (char *)0x0) {
          Q_strcat(local_110,".wav");
        }
                    /* Unresolved local var: sfx_t * sfx@[???] */
        if (((sound_started == 0) || (nosound.value != 0.0)) ||
           (iVar1 = Q_strlen(local_110), 0x3f < iVar1)) {
          S_Play::hash = S_Play::hash + 1;
        }
        else {
          if ((local_110[0] == '*') || (local_110[0] == '!')) {
                    /* Unresolved local var: sfx_t * sfx@[???] */
            s = S_FindName(local_110,(int *)0x0);
          }
          else {
            s = S_FindName(local_110,(int *)0x0);
            if (fs_lazy_precache.value == 0.0) {
              S_LoadSound(s,(channel_t *)0x0);
            }
          }
          iVar1 = S_Play::hash;
          S_Play::hash = S_Play::hash + 1;
                    /* Unresolved local var: channel_t * target_chan@[???]
                       Unresolved local var: channel_t * check@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int vol@[???]
                       Unresolved local var: int ch_idx@[???]
                       Unresolved local var: int skip@[???]
                       Unresolved local var: int fsentence@[???] */
          if (((sound_started != 0) && (s != (sfx_t *)0x0)) && (nosound.value == 0.0)) {
            S_StartDynamicSound(iVar1,0,s,listener_origin,1.0,1.0,0,100);
          }
        }
        arg = arg + 1;
        iVar1 = Cmd_Argc();
      } while (arg < iVar1);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// S_PlayVol  @ 001a7800
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_PlayVol(void)

{
  int iVar1;
  sfx_t *s;
  int iVar2;
  char *pcVar3;
  int arg;
  int in_GS_OFFSET;
  float fvol;
  char local_110 [251];
  undefined1 local_15;
  int local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float vol@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: sfx_t * sfx@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (speak_enable.value != 0.0) {
    arg = 2;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float vol@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: sfx_t * sfx@[???] */
    while( true ) {
      iVar2 = Cmd_Argc();
      iVar1 = arg + -1;
      if (iVar2 <= iVar1) break;
      pcVar3 = Cmd_Argv(iVar1);
      Q_strncpy(local_110,pcVar3,0xfb);
      local_15 = 0;
      pcVar3 = Cmd_Argv(iVar1);
      pcVar3 = Q_strrchr(pcVar3,'.');
      if (pcVar3 == (char *)0x0) {
        Q_strcat(local_110,".wav");
      }
                    /* Unresolved local var: sfx_t * sfx@[???] */
      if (((sound_started == 0) || (nosound.value != 0.0)) ||
         (iVar1 = Q_strlen(local_110), 0x3f < iVar1)) {
        pcVar3 = Cmd_Argv(arg);
        Q_atof(pcVar3);
        S_PlayVol::hash = S_PlayVol::hash + 1;
      }
      else {
        if ((local_110[0] == '*') || (local_110[0] == '!')) {
                    /* Unresolved local var: sfx_t * sfx@[???] */
          s = S_FindName(local_110,(int *)0x0);
        }
        else {
          s = S_FindName(local_110,(int *)0x0);
          if (fs_lazy_precache.value == 0.0) {
            S_LoadSound(s,(channel_t *)0x0);
          }
        }
        pcVar3 = Cmd_Argv(arg);
        fvol = Q_atof(pcVar3);
        iVar1 = S_PlayVol::hash;
        S_PlayVol::hash = S_PlayVol::hash + 1;
                    /* Unresolved local var: channel_t * target_chan@[???]
                       Unresolved local var: channel_t * check@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int vol@[???]
                       Unresolved local var: int ch_idx@[???]
                       Unresolved local var: int skip@[???]
                       Unresolved local var: int fsentence@[???] */
        if (((sound_started != 0) && (s != (sfx_t *)0x0)) && (nosound.value == 0.0)) {
          S_StartDynamicSound(iVar1,0,s,listener_origin,fvol,1.0,0,100);
        }
      }
      arg = arg + 2;
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// S_PrecacheSound  @ 001a6b10
sfx_t * S_PrecacheSound(char *name)

{
  int iVar1;
  sfx_t *psVar2;
  
                    /* Unresolved local var: sfx_t * sfx@[???] */
  if (((sound_started != 0) && (nosound.value == 0.0)) && (iVar1 = Q_strlen(name), iVar1 < 0x40)) {
    if ((*name != '*') && (*name != '!')) {
      psVar2 = S_FindName(name,(int *)0x0);
      if (fs_lazy_precache.value != 0.0) {
        return psVar2;
      }
      S_LoadSound(psVar2,(channel_t *)0x0);
      return psVar2;
    }
                    /* Unresolved local var: sfx_t * sfx@[???] */
    psVar2 = S_FindName(name,(int *)0x0);
    return psVar2;
  }
  return (sfx_t *)0x0;
}


// S_PrintStats  @ 001a8e40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_PrintStats(void)

{
  int iVar1;
  int iVar2;
  sfx_t *psVar3;
  char *pcVar4;
  vec_t *v;
  uint uVar5;
  uint uVar6;
  
                    /* Unresolved local var: channel_t * ch@[???]
                       Unresolved local var: int i@[???] */
  if (((s_show.value != 0.0) && (cl.maxclients < 3)) && (0 < total_channels)) {
    v = channels[0].origin;
    uVar5 = 0;
    do {
      while (psVar3 = ((channel_t *)(v + -8))->sfx, psVar3 == (sfx_t *)0x0) {
        uVar6 = uVar5 + 1;
        Con_NPrintf(uVar5 & 0x1f,"");
        v = v + 0x10;
        uVar5 = uVar6;
        if (total_channels <= (int)uVar6) {
          return;
        }
      }
      iVar1 = (int)v[-1];
      iVar2 = (int)v[-2];
      pcVar4 = vstr(v);
      uVar6 = uVar5 + 1;
      Con_NPrintf(uVar5 & 0x1f,"%s %03i %02i %20s",pcVar4,iVar2,iVar1,psVar3);
      v = v + 0x10;
      uVar5 = uVar6;
    } while ((int)uVar6 < total_channels);
  }
  return;
}


// S_QuerySoundSetting  @ 001a62d0
qboolean S_QuerySoundSetting(char *pszCvar,qboolean bDefault)

{
  byte *p;
  byte *data;
  int iVar1;
  char *data_00;
  long lVar2;
  int in_GS_OFFSET;
  char local_114 [260];
  int local_10;
  
                    /* Unresolved local var: char[260] szFile@[???]
                       Unresolved local var: char * pbuffer@[???]
                       Unresolved local var: char * pstart@[???]
                       Unresolved local var: qboolean bResult@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  builtin_strncpy(local_114,"config.cfg",0xb);
  p = COM_LoadFile(local_114,5,(int *)0x0);
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
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bDefault;
}


// S_RawSamples  @ 001a8a70
void S_RawSamples(int samples,int rate,int width,int channels,byte *data,float volume)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int src@[???]
                       Unresolved local var: int dst@[???]
                       Unresolved local var: float scale@[???]
                       Unresolved local var: int intVolume@[???] */
  if (s_rawend < paintedtime) {
    s_rawend = paintedtime;
  }
  iVar3 = s_rawend;
  fVar2 = (float)rate / (float)shm->speed;
  iVar4 = (int)(volume * 256.0);
  if ((channels != 2) || (width != 2)) {
    if ((width != 2) || (channels != 1)) {
      if ((channels != 2) || (width != 1)) {
        if ((channels == 1) && (width == 1)) {
          fVar1 = fVar2 * 0.0;
          uVar6 = s_rawend;
          while ((int)fVar1 < samples) {
            uVar5 = uVar6 + 1;
            s_rawend = uVar5;
            s_rawsamples[uVar6 & 0x1fff].left = (data[(int)fVar1] - 0x80) * iVar4 * 0x100;
            s_rawsamples[uVar6 & 0x1fff].right = (data[(int)fVar1] - 0x80) * iVar4 * 0x100;
            uVar6 = uVar5;
            fVar1 = (float)(int)(uVar5 - iVar3) * fVar2;
          }
        }
      }
      else {
        iVar7 = (int)(fVar2 * 0.0);
        uVar6 = s_rawend;
        if (iVar7 < samples) {
          do {
            uVar5 = uVar6 + 1;
            s_rawend = uVar5;
            s_rawsamples[uVar6 & 0x1fff].left = (data[iVar7 * 2] - 0x80) * iVar4 * 0x100;
            s_rawsamples[uVar6 & 0x1fff].right = (data[iVar7 * 2 + 1] - 0x80) * iVar4 * 0x100;
            iVar7 = (int)((float)(int)(uVar5 - iVar3) * fVar2);
            uVar6 = uVar5;
          } while (iVar7 < samples);
          return;
        }
      }
    }
    else {
      iVar7 = (int)(fVar2 * 0.0);
      uVar6 = s_rawend;
      if (iVar7 < samples) {
        do {
          uVar5 = uVar6 + 1;
          s_rawend = uVar5;
          s_rawsamples[uVar6 & 0x1fff].left = *(short *)(data + iVar7 * 2) * iVar4;
          s_rawsamples[uVar6 & 0x1fff].right = *(short *)(data + iVar7 * 2) * iVar4;
          iVar7 = (int)((float)(int)(uVar5 - iVar3) * fVar2);
          uVar6 = uVar5;
        } while (iVar7 < samples);
        return;
      }
    }
  }
  else {
    fVar1 = fVar2 * 0.0;
    uVar6 = s_rawend;
    while ((int)fVar1 < samples) {
      uVar5 = uVar6 + 1;
      iVar7 = (int)fVar1 * 4;
      s_rawend = uVar5;
      s_rawsamples[uVar6 & 0x1fff].left = *(short *)(data + iVar7) * iVar4;
      s_rawsamples[uVar6 & 0x1fff].right = *(short *)(data + iVar7 + 2) * iVar4;
      uVar6 = uVar5;
      fVar1 = (float)(int)(uVar5 - iVar3) * fVar2;
    }
  }
  return;
}


// S_Say  @ 001a7ab0
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
  portable_samplepair_t *ppVar8;
  portable_samplepair_t *ppVar9;
  int in_GS_OFFSET;
  char local_110 [8];
  undefined1 local_108;
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: char[256] sound@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((((nosound.value == 0.0) && (sound_started != 0)) && (iVar1 = Cmd_Argc(), 1 < iVar1)) &&
     (speak_enable.value != 0.0)) {
    pcVar2 = Cmd_Argv(1);
    Q_strncpy(local_110,pcVar2,0xff);
    local_11 = 0;
    iVar1 = Q_strcmp(local_110,"dsp");
    if (iVar1 == 0) {
      ppVar8 = paintbuffer;
      do {
                    /* Unresolved local var: DWORD time@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
        ppVar9 = ppVar8 + 1;
        iVar3 = RandomLong(0,2999);
        ppVar8->left = iVar3;
        iVar3 = RandomLong(0,2999);
        ppVar8->right = iVar3;
        ppVar8 = ppVar9;
      } while (ppVar9 != paintbuffer + 0x200);
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
      iVar6 = Q_strcmp(local_110,"paint");
      iVar1 = paintedtime;
      if (iVar6 == 0) {
                    /* Unresolved local var: DWORD time@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: int psav@[???] */
        Con_Printf("Start profiling S_PaintChannels\n");
                    /* Unresolved local var: sfx_t * sfx@[???] */
        if (((sound_started == 0) || (nosound.value != 0.0)) ||
           (iVar6 = Q_strlen("ambience/labdrone1.wav"), 0x3f < iVar6)) {
          S_Say::lexical_block_4::hash = S_Say::lexical_block_4::hash + 1;
        }
        else {
          psVar7 = S_FindName("ambience/labdrone1.wav",(int *)0x0);
          if (fs_lazy_precache.value == 0.0) {
            S_LoadSound(psVar7,(channel_t *)0x0);
          }
          iVar6 = S_Say::lexical_block_4::hash;
          S_Say::lexical_block_4::hash = S_Say::lexical_block_4::hash + 1;
                    /* Unresolved local var: channel_t * target_chan@[???]
                       Unresolved local var: channel_t * check@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int vol@[???]
                       Unresolved local var: int ch_idx@[???]
                       Unresolved local var: int skip@[???]
                       Unresolved local var: int fsentence@[???] */
          if (((sound_started != 0) && (psVar7 != (sfx_t *)0x0)) && (nosound.value == 0.0)) {
            S_StartDynamicSound(iVar6,0,psVar7,listener_origin,1.0,1.0,0,100);
          }
        }
        tVar4 = time((time_t *)0x0);
        S_PaintChannels(paintedtime + 0x4e2000);
        tVar5 = time((time_t *)0x0);
        Con_Printf("%d milliseconds \n",tVar5 - tVar4);
        paintedtime = iVar1;
      }
      else if (local_110[0] == '!') {
        psVar7 = S_FindName(local_110,(int *)0x0);
        if (psVar7 == (sfx_t *)0x0) {
          Con_Printf("S_Say: can\'t find sentence name %s\n",local_110);
        }
        else {
          S_StartDynamicSound(cl.viewentity,-1,psVar7,vec3_origin,1.0,1.0,0,100);
        }
      }
      else {
        pcVar2 = Cmd_Argv(1);
        __snprintf_chk(local_110,0x100,1,0x100,"xxtestxx %s",pcVar2);
        local_108 = 0;
        rgpszrawsentence[cszrawsentences] = local_110;
        cszrawsentences = cszrawsentences + 1;
                    /* Unresolved local var: sfx_t * sfx@[???] */
                    /* Unresolved local var: sfx_t * sfx@[DW_OP_reg0(EAX)] */
        if (((sound_started == 0) || (nosound.value != 0.0)) ||
           ((iVar1 = Q_strlen("!xxtestxx"), 0x3f < iVar1 ||
            (psVar7 = S_FindName("!xxtestxx",(int *)0x0), psVar7 == (sfx_t *)0x0)))) {
          Con_Printf("S_Say: can\'t cache %s\n",local_110);
        }
        else {
                    /* Unresolved local var: channel_t * target_chan@[???]
                       Unresolved local var: channel_t * check@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int vol@[???]
                       Unresolved local var: int ch_idx@[???]
                       Unresolved local var: int skip@[???]
                       Unresolved local var: int fsentence@[???] */
          if ((sound_started != 0) && (nosound.value == 0.0)) {
            S_StartDynamicSound(cl.viewentity,-1,psVar7,vec3_origin,1.0,1.0,0,100);
          }
          cszrawsentences = cszrawsentences + -1;
          rgpszrawsentence[cszrawsentences] = (char *)0x0;
        }
      }
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// S_Say_Reliable  @ 001a82b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_Say_Reliable(void)

{
  int iVar1;
  char *pcVar2;
  sfx_t *psVar3;
  int in_GS_OFFSET;
  char local_110 [8];
  undefined1 local_108;
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: char[256] sound@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((((nosound.value == 0.0) && (sound_started != 0)) && (iVar1 = Cmd_Argc(), 1 < iVar1)) &&
     (speak_enable.value != 0.0)) {
    pcVar2 = Cmd_Argv(1);
    Q_strncpy(local_110,pcVar2,0xff);
    local_11 = 0;
    if (local_110[0] == '!') {
      psVar3 = S_FindName(local_110,(int *)0x0);
      if (psVar3 == (sfx_t *)0x0) {
        Con_Printf("S_Say_Reliable: can\'t find sentence name %s\n",local_110);
      }
      else {
        S_StartStaticSound(cl.viewentity,6,psVar3,vec3_origin,1.0,1.0,0,100);
      }
    }
    else {
      pcVar2 = Cmd_Argv(1);
      __snprintf_chk(local_110,0x100,1,0x100,"xxtestxx %s",pcVar2);
      local_108 = 0;
      rgpszrawsentence[cszrawsentences] = local_110;
      cszrawsentences = cszrawsentences + 1;
                    /* Unresolved local var: sfx_t * sfx@[???] */
                    /* Unresolved local var: sfx_t * sfx@[DW_OP_reg0(EAX)] */
      if (((sound_started == 0) || (nosound.value != 0.0)) ||
         ((iVar1 = Q_strlen("!xxtestxx"), 0x3f < iVar1 ||
          (psVar3 = S_FindName("!xxtestxx",(int *)0x0), psVar3 == (sfx_t *)0x0)))) {
        Con_Printf("S_Say_Reliable: can\'t cache %s\n",local_110);
      }
      else {
        S_StartStaticSound(cl.viewentity,6,psVar3,vec3_origin,1.0,1.0,0,100);
        cszrawsentences = cszrawsentences + -1;
        rgpszrawsentence[cszrawsentences] = (char *)0x0;
      }
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// S_Shutdown  @ 001a67c0
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


// S_SoundInfo_f  @ 001a5fd0
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


// S_SoundList  @ 001a60c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_SoundList(void)

{
  int *piVar1;
  int iVar2;
  sfx_t *psVar3;
  int iVar4;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int total@[???] */
  local_20 = 0;
  if (0 < num_sfx) {
    iVar4 = 0;
    psVar3 = known_sfx;
    do {
      piVar1 = Cache_Check(&psVar3->cache);
      if (piVar1 != (int *)0x0) {
        iVar2 = *piVar1 * piVar1[3] * (piVar1[4] + 1);
        local_20 = local_20 + iVar2;
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
  Con_Printf("Total resident: %i\n",local_20);
  return;
}


// S_StartDynamicSound  @ 001a72a0
void __regparm3
S_StartDynamicSound(int entnum,int entchannel,sfx_t *sfx,vec_t *origin,float fvol,float attenuation,
                   int flags,int pitch)

{
  vec_t vVar1;
  byte bVar2;
  float fVar3;
  int iVar4;
  channel_t *ch;
  sfxcache_t *sc;
  channel_t *pcVar5;
  int32 iVar6;
  int vol;
  int iVar7;
  int in_GS_OFFSET;
  bool bVar8;
  char local_60 [63];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: channel_t * target_chan@[???]
                       Unresolved local var: channel_t * check@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int vol@[???]
                       Unresolved local var: int ch_idx@[???]
                       Unresolved local var: int skip@[???]
                       Unresolved local var: int fsentence@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar8 = sfx->name[0] == '*';
  iVar7 = entchannel;
  if (bVar8) {
    iVar7 = 5;
  }
  if ((pitch != 100) && (bVar8 || entchannel == 5)) {
    pitch = 100;
    Con_DPrintf("Warning: pitch shift ignored on stream sound %s\n",sfx);
  }
  vol = (int)(fvol * 255.0);
  if (0xff < vol) {
    Con_DPrintf("S_StartDynamicSound: %s volume > 255",sfx);
    vol = 0xff;
  }
  if (((flags & 0xe0U) != 0) &&
     ((iVar4 = S_AlterChannel(entnum,iVar7,sfx,vol,pitch,flags), iVar4 != 0 ||
      ((flags & 0x20U) != 0)))) goto LAB_001a740c;
  if (pitch == 0) {
    Con_DPrintf("Warning: S_StartDynamicSound Ignored, called with pitch 0");
    goto LAB_001a740c;
  }
  iVar4 = (int)((float)pitch * (sys_timescale.value + 1.0) * 0.5);
  ch = SND_PickDynamicChannel(entnum,iVar7,sfx);
  if (ch == (channel_t *)0x0) goto LAB_001a740c;
  bVar2 = sfx->name[0];
  Q_memset(ch,0,0x40);
  ch->origin[0] = *origin;
  fVar3 = attenuation / sound_nominal_clip_dist;
  ch->origin[1] = origin[1];
  vVar1 = origin[2];
  ch->pitch = iVar4;
  ch->master_vol = vol;
  ch->origin[2] = vVar1;
  ch->entnum = entnum;
  ch->entchannel = iVar7;
  ch->isentence = -1;
  ch->dist_mult = fVar3;
  SND_Spatialize(ch);
  if (((ch->leftvol != 0) || (ch->rightvol != 0)) || (iVar7 == 5)) {
    if ((bVar2 & 0xfd) == 0x21) {
                    /* Unresolved local var: char[64] name@[???] */
      Q_strncpy(local_60,sfx->name + 1,0x3f);
      local_21 = 0;
      sc = VOX_LoadSound(ch,local_60);
      if (sc != (sfxcache_t *)0x0) {
        ch->pos = 0;
        ch->end = paintedtime + sc->length;
        goto LAB_001a749e;
      }
    }
    else {
      sc = S_LoadSound(sfx,ch);
      ch->sfx = sfx;
      if (sc != (sfxcache_t *)0x0) {
        ch->pos = 0;
        ch->end = paintedtime + sc->length;
        if (iVar4 != 100) {
          VOX_MakeSingleWordSentence(ch,iVar4);
        }
LAB_001a749e:
        VOX_TrimStartEndTimes(ch,sc);
        SND_InitMouth(entnum,iVar7);
        pcVar5 = channels + 4;
        do {
          if (((ch != pcVar5) && (sfx == pcVar5->sfx)) && (pcVar5->pos == 0)) {
            iVar6 = RandomLong(0,(int)((double)shm->speed * 0.1));
            iVar7 = ch->end;
            if (iVar7 <= iVar6) {
              iVar6 = iVar7 + -1;
            }
            ch->pos = ch->pos + iVar6;
            ch->end = iVar7 - iVar6;
            break;
          }
          pcVar5 = pcVar5 + 1;
        } while (pcVar5 != channels + 0x24);
        goto LAB_001a740c;
      }
    }
  }
  ch->sfx = (sfx_t *)0x0;
LAB_001a740c:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// S_StartDynamicSound  @ 001a7a00
void S_StartDynamicSound(int entnum,int entchannel,sfx_t *sfx,vec_t *origin,float fvol,
                        float attenuation,int flags,int pitch)

{
                    /* Unresolved local var: channel_t * target_chan@[???]
                       Unresolved local var: channel_t * check@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int vol@[???]
                       Unresolved local var: int ch_idx@[???]
                       Unresolved local var: int skip@[???]
                       Unresolved local var: int fsentence@[???] */
  if (((sound_started != 0) && (sfx != (sfx_t *)0x0)) && (nosound.value == 0.0)) {
    S_StartDynamicSound(entnum,entchannel,sfx,origin,fvol,attenuation,flags,pitch);
    return;
  }
  return;
}


// S_StartStaticSound  @ 001a7f20
void S_StartStaticSound(int entnum,int entchannel,sfx_t *sfxin,vec_t *origin,float fvol,
                       float attenuation,int flags,int pitch)

{
  vec_t vVar1;
  sfx_t *psVar2;
  float fVar3;
  int iVar4;
  sfxcache_t *sc;
  int iVar5;
  int iVar6;
  int iVar7;
  channel_t *pchan;
  int in_GS_OFFSET;
  bool bVar8;
  char local_60 [63];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: channel_t * ch@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int fvox@[???]
                       Unresolved local var: sfx_t * sfx@[???]
                       Unresolved local var: int vol@[???] */
  iVar7 = entchannel;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (sfxin == (sfx_t *)0x0) goto LAB_001a8105;
  bVar8 = sfxin->name[0] == '*';
  if (bVar8) {
    entchannel = 5;
  }
  if ((pitch != 100) && (bVar8 || iVar7 == 5)) {
    pitch = 100;
    Con_DPrintf("Warning: pitch shift ignored on stream sound %s\n",sfxin);
  }
  iVar7 = (int)(fvol * 255.0);
  if (0xff < iVar7) {
    iVar7 = 0xff;
    Con_DPrintf("S_StartStaticSound: %s volume > 255",sfxin);
  }
  if (((flags & 0xe0U) != 0) &&
     ((iVar4 = S_AlterChannel(entnum,entchannel,sfxin,iVar7,pitch,flags), iVar4 != 0 ||
      ((flags & 0x20U) != 0)))) goto LAB_001a8105;
  if (pitch == 0) {
    Con_DPrintf("Warning: S_StartStaticSound Ignored, called with pitch 0");
    goto LAB_001a8105;
  }
  iVar4 = (int)((float)pitch * (sys_timescale.value + 1.0) * 0.5);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: channel_t * ch@[???] */
  if (sfxin->name[0] == 0x2a) {
                    /* Unresolved local var: int ch_idx@[???] */
    if (4 < total_channels) {
      if (sfxin != channels[4].sfx) {
        iVar6 = 4;
        do {
          iVar6 = iVar6 + 1;
          if (iVar6 == total_channels) goto LAB_001a7fe9;
        } while (sfxin != channels[iVar6].sfx);
      }
      goto LAB_001a8105;
    }
LAB_001a8029:
    iVar6 = total_channels + 1;
    pchan = channels + total_channels;
    total_channels = iVar6;
    if ((sfxin->name[0] & 0xfdU) != 0x21) goto LAB_001a820b;
LAB_001a8048:
                    /* Unresolved local var: char[64] name@[???] */
    Q_strncpy(local_60,sfxin->name + 1,0x3f);
    local_21 = 0;
    sc = VOX_LoadSound(pchan,local_60);
    bVar8 = false;
  }
  else {
LAB_001a7fe9:
    if (total_channels < 0x25) goto LAB_001a8029;
    iVar6 = 0x24;
    psVar2 = channels[0x24].sfx;
    while (psVar2 != (sfx_t *)0x0) {
      iVar5 = iVar6 + 1;
      if (iVar5 == total_channels) {
        if (iVar6 != 0x7f) goto LAB_001a8029;
        Con_DPrintf("total_channels == MAX_CHANNELS\n");
        goto LAB_001a8105;
      }
      iVar6 = iVar5;
      psVar2 = channels[iVar5].sfx;
    }
    pchan = channels + iVar6;
    if ((sfxin->name[0] & 0xfdU) == 0x21) goto LAB_001a8048;
LAB_001a820b:
    sc = S_LoadSound(sfxin,pchan);
    bVar8 = true;
    pchan->sfx = sfxin;
    pchan->isentence = -1;
  }
  if (sc == (sfxcache_t *)0x0) {
    pchan->sfx = (sfx_t *)0x0;
  }
  else {
    fVar3 = attenuation / sound_nominal_clip_dist;
    pchan->origin[0] = *origin;
    pchan->origin[1] = origin[1];
    vVar1 = origin[2];
    pchan->master_vol = iVar7;
    iVar6 = paintedtime;
    pchan->pos = 0;
    pchan->origin[2] = vVar1;
    pchan->dist_mult = fVar3;
    iVar7 = sc->length;
    pchan->pitch = iVar4;
    pchan->end = iVar6 + iVar7;
    pchan->entnum = entnum;
    pchan->entchannel = entchannel;
    if ((iVar4 != 100) && (bVar8)) {
      VOX_MakeSingleWordSentence(pchan,iVar4);
    }
    VOX_TrimStartEndTimes(pchan,sc);
    SND_Spatialize(pchan);
  }
LAB_001a8105:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// S_Startup  @ 001a6270
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_Startup(void)

{
  qboolean qVar1;
  
                    /* Unresolved local var: int rc@[???] */
  if (snd_initialized != false) {
    if (fakedma != false) {
      sound_started = 1;
      return;
    }
    qVar1 = SNDDMA_Init();
    if (qVar1 == false) {
                    /* Unresolved local var: int rc@[???] */
      Con_Printf("S_Startup: SNDDMA_Init failed.\n");
    }
    sound_started = (int)(qVar1 != false);
  }
  return;
}


// S_StopAllSounds  @ 001a8550
void S_StopAllSounds(qboolean clear)

{
  int iVar1;
  int iVar2;
  channel_t *ch;
  int fill;
  
                    /* Unresolved local var: int i@[???] */
  if (sound_started != 0) {
    ch = channels;
    total_channels = 0x24;
    do {
      if (ch->sfx != (sfx_t *)0x0) {
        S_FreeChannel(ch);
      }
      ch = ch + 1;
    } while (ch != (channel_t *)listener_up);
    Q_memset(channels,0,0x2000);
    Wavstream_Init();
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int clear@[???] */
                    /* Unresolved local var: int clear@[???] */
    if (((clear != false) && (sound_started != 0)) && (shm != (dma_t *)0x0)) {
      fill = 0x80;
      if (shm->samplebits != 8) {
        fill = 0;
      }
      iVar2 = shm->samples * shm->samplebits;
      iVar1 = iVar2 + 7;
      if (-1 < iVar2) {
        iVar1 = iVar2;
      }
      Q_memset(shm->buffer,fill,iVar1 >> 3);
    }
  }
  return;
}


// S_StopAllSoundsC  @ 001a6190
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_StopAllSoundsC(void)

{
  int iVar1;
  int iVar2;
  channel_t *ch;
  int fill;
  
                    /* Unresolved local var: int i@[???] */
  if (sound_started != 0) {
    ch = channels;
    total_channels = 0x24;
    do {
      if (ch->sfx != (sfx_t *)0x0) {
        S_FreeChannel(ch);
      }
      ch = ch + 1;
    } while (ch != (channel_t *)listener_up);
    Q_memset(channels,0,0x2000);
    Wavstream_Init();
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int clear@[???] */
                    /* Unresolved local var: int clear@[???] */
    if ((sound_started != 0) && (shm != (dma_t *)0x0)) {
      fill = 0x80;
      if (shm->samplebits != 8) {
        fill = 0;
      }
      iVar2 = shm->samples * shm->samplebits;
      iVar1 = iVar2 + 7;
      if (-1 < iVar2) {
        iVar1 = iVar2;
      }
      Q_memset(shm->buffer,fill,iVar1 >> 3);
    }
  }
  return;
}


// S_StopSound  @ 001a84f0
void S_StopSound(int entnum,int entchannel)

{
  int iVar1;
  channel_t *ch;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (4 < total_channels) {
    iVar2 = 4;
    iVar1 = total_channels;
    ch = channels + 4;
    do {
      while ((ch->entnum == entnum && (ch->entchannel == entchannel))) {
        iVar2 = iVar2 + 1;
        S_FreeChannel(ch);
        iVar1 = total_channels;
        ch = ch + 1;
        if (total_channels <= iVar2) {
          return;
        }
      }
      iVar2 = iVar2 + 1;
      ch = ch + 1;
    } while (iVar2 < iVar1);
  }
  return;
}


// S_TouchSound  @ 001a6ad0
void S_TouchSound(char *name)

{
  sfx_t *psVar1;
  
                    /* Unresolved local var: sfx_t * sfx@[???] */
  if (sound_started == 0) {
    return;
  }
  psVar1 = S_FindName(name,(int *)0x0);
  Cache_Check(&psVar1->cache);
  return;
}


// S_TransferPaintBuffer  @ 001a9da0
void S_TransferPaintBuffer(int endtime)

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
  snd_p = &paintbuffer[0].left;
  snd_vol = (int)(volume.value * 256.0);
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


// S_TransferStereo16  @ 001a9cf0
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
  snd_p = &paintbuffer[0].left;
  snd_vol = (int)(volume.value * 256.0);
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


// S_UnblockSound  @ 001cca50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_UnblockSound(void)

{
  snd_blocked = snd_blocked + -1;
  if (snd_blocked != 0) {
    return;
  }
  SDL_PauseAudioDevice(m_devId,0);
  return;
}


// S_Update  @ 001a9350
void S_Update(vec_t *origin,vec_t *forward,vec_t *right,vec_t *up)

{
  model_s *pmVar1;
  float fVar2;
  float fVar3;
  cl_entity_t *pcVar4;
  int iVar5;
  mleaf_t *pmVar6;
  channel_t *pcVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int total@[???]
                       Unresolved local var: channel_t * ch@[???]
                       Unresolved local var: channel_t * combine@[???] */
  if ((sound_started == 0) || (0 < snd_blocked)) {
    return;
  }
  listener_origin[0] = *origin;
                    /* Unresolved local var: mleaf_t * l@[???]
                       Unresolved local var: float vol@[???]
                       Unresolved local var: int ambient_channel@[???]
                       Unresolved local var: channel_t * chan@[???] */
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
                    /* Unresolved local var: mleaf_t * l@[???]
                       Unresolved local var: float vol@[???]
                       Unresolved local var: int ambient_channel@[???]
                       Unresolved local var: channel_t * chan@[???] */
  if ((snd_ambient == false) || (cl.worldmodel == (model_s *)0x0)) goto LAB_001a942e;
  pmVar6 = Mod_PointInLeaf(listener_origin,cl.worldmodel);
  if ((pmVar6 == (mleaf_t *)0x0) || (ambient_level.value == 0.0)) {
    channels[0].sfx = (sfx_t *)0x0;
    channels[1].sfx = (sfx_t *)0x0;
    channels[2].sfx = (sfx_t *)0x0;
    channels[3].sfx = (sfx_t *)0x0;
    goto LAB_001a942e;
  }
  fVar2 = (float)host_frametime;
  channels[0].sfx = ambient_sfx[0];
  fVar3 = (float)pmVar6->ambient_sound_level[0] * ambient_level.value;
  fVar10 = 0.0;
  if (8.0 <= fVar3) {
    fVar10 = fVar3;
  }
  if ((float)channels[0].master_vol < fVar10) {
    channels[0].master_vol = (int)(fVar2 * ambient_fade.value + (float)channels[0].master_vol);
    if (fVar10 < (float)channels[0].master_vol) goto LAB_001a96f1;
  }
  else if ((fVar10 < (float)channels[0].master_vol) &&
          (channels[0].master_vol =
                (int)((float)channels[0].master_vol - fVar2 * ambient_fade.value),
          (float)channels[0].master_vol < fVar10)) {
LAB_001a96f1:
    channels[0].master_vol = (int)fVar10;
  }
  channels[1].sfx = ambient_sfx[1];
  fVar3 = (float)pmVar6->ambient_sound_level[1] * ambient_level.value;
  fVar10 = 0.0;
  if (8.0 <= fVar3) {
    fVar10 = fVar3;
  }
  if ((float)channels[1].master_vol < fVar10) {
    channels[1].master_vol = (int)(fVar2 * ambient_fade.value + (float)channels[1].master_vol);
    if (fVar10 < (float)channels[1].master_vol) goto LAB_001a9783;
  }
  else if ((fVar10 < (float)channels[1].master_vol) &&
          (channels[1].master_vol =
                (int)((float)channels[1].master_vol - fVar2 * ambient_fade.value),
          (float)channels[1].master_vol < fVar10)) {
LAB_001a9783:
    channels[1].master_vol = (int)fVar10;
  }
  channels[2].sfx = ambient_sfx[2];
  fVar3 = (float)pmVar6->ambient_sound_level[2] * ambient_level.value;
  fVar10 = 0.0;
  if (8.0 <= fVar3) {
    fVar10 = fVar3;
  }
  if ((float)channels[2].master_vol < fVar10) {
    channels[2].master_vol = (int)(fVar2 * ambient_fade.value + (float)channels[2].master_vol);
    if (fVar10 < (float)channels[2].master_vol) goto LAB_001a9815;
  }
  else if ((fVar10 < (float)channels[2].master_vol) &&
          (channels[2].master_vol =
                (int)((float)channels[2].master_vol - fVar2 * ambient_fade.value),
          (float)channels[2].master_vol < fVar10)) {
LAB_001a9815:
    channels[2].master_vol = (int)fVar10;
  }
  channels[3].sfx = ambient_sfx[3];
  fVar3 = (float)pmVar6->ambient_sound_level[3] * ambient_level.value;
  fVar10 = 0.0;
  if (8.0 <= fVar3) {
    fVar10 = fVar3;
  }
  channels[0].leftvol = channels[0].master_vol;
  channels[0].rightvol = channels[0].master_vol;
  channels[1].leftvol = channels[1].master_vol;
  channels[1].rightvol = channels[1].master_vol;
  channels[2].leftvol = channels[2].master_vol;
  channels[2].rightvol = channels[2].master_vol;
  if (fVar10 <= (float)channels[3].master_vol) {
    channels[3].leftvol = channels[3].master_vol;
    channels[3].rightvol = channels[3].master_vol;
    if (((float)channels[3].master_vol <= fVar10) ||
       (channels[3].leftvol = (int)((float)channels[3].master_vol - fVar2 * ambient_fade.value),
       channels[3].rightvol = channels[3].leftvol, channels[3].master_vol = channels[3].leftvol,
       fVar10 <= (float)channels[3].leftvol)) goto LAB_001a942e;
  }
  else {
    channels[3].leftvol = (int)((float)channels[3].master_vol + fVar2 * ambient_fade.value);
    channels[3].rightvol = channels[3].leftvol;
    channels[3].master_vol = channels[3].leftvol;
    if ((float)channels[3].leftvol <= fVar10) goto LAB_001a942e;
  }
  channels[3].leftvol = (int)fVar10;
  channels[3].rightvol = channels[3].leftvol;
  channels[3].master_vol = channels[3].leftvol;
LAB_001a942e:
  pcVar7 = channels + 4;
  iVar8 = 4;
                    /* Unresolved local var: vec_t dot@[???]
                       Unresolved local var: vec_t dist@[???]
                       Unresolved local var: vec_t lscale@[???]
                       Unresolved local var: vec_t rscale@[???]
                       Unresolved local var: vec_t scale@[???]
                       Unresolved local var: vec3_t source_vec@[???]
                       Unresolved local var: sfx_t * snd@[???]
                       Unresolved local var: cl_entity_t.conflict * pent@[???] */
  iVar5 = total_channels;
  if (4 < total_channels) {
    do {
      if (pcVar7->sfx != (sfx_t *)0x0) {
        iVar5 = pcVar7->entnum;
        if (iVar5 == cl.viewentity) {
          pcVar7->leftvol = pcVar7->master_vol;
          pcVar7->rightvol = pcVar7->master_vol;
          VOX_SetChanVol(pcVar7);
          iVar5 = total_channels;
        }
        else {
          if ((((iVar5 < 1) || (cl.num_entities <= iVar5)) ||
              (pcVar4 = cl_entities + iVar5, pcVar4 == (cl_entity_t *)0x0)) ||
             ((pcVar4->model == (model_s *)0x0 || ((pcVar4->curstate).messagenum != cl.parsecount)))
             ) {
            local_28 = pcVar7->origin[0];
            local_24 = pcVar7->origin[1];
            local_20 = pcVar7->origin[2];
          }
          else {
            local_28 = pcVar4->origin[0];
            pcVar7->origin[0] = local_28;
            local_24 = pcVar4->origin[1];
            pcVar7->origin[1] = local_24;
            local_20 = pcVar4->origin[2];
            pcVar7->origin[2] = local_20;
            pmVar1 = pcVar4->model;
            if (pmVar1->type == mod_brush) {
              local_28 = local_28 + (pmVar1->mins[0] + pmVar1->maxs[0]) * 0.5;
              pcVar7->origin[0] = local_28;
              local_24 = (pcVar4->model->mins[1] + pcVar4->model->maxs[1]) * 0.5 + local_24;
              pcVar7->origin[1] = local_24;
              local_20 = local_20 + (pcVar4->model->mins[2] + pcVar4->model->maxs[2]) * 0.5;
              pcVar7->origin[2] = local_20;
            }
          }
          local_28 = local_28 - listener_origin[0];
          local_24 = local_24 - listener_origin[1];
          local_20 = local_20 - listener_origin[2];
          fVar10 = VectorNormalize(&local_28);
          fVar3 = listener_right[2] * local_20 +
                  listener_right[1] * local_24 + listener_right[0] * local_28;
          if ((shm == (dma_t *)0x0) || (shm->channels != 1)) {
            fVar2 = fVar3 + 1.0;
            fVar3 = 1.0 - fVar3;
          }
          else {
            fVar2 = 1.0;
            fVar3 = fVar2;
          }
          fVar10 = 1.0 - fVar10 * pcVar7->dist_mult;
          pcVar7->rightvol = (int)(fVar2 * fVar10 * (float)pcVar7->master_vol);
          pcVar7->leftvol = (int)(fVar10 * fVar3 * (float)pcVar7->master_vol);
          VOX_SetChanVol(pcVar7);
          if (pcVar7->rightvol < 0) {
            iVar9 = pcVar7->leftvol;
            pcVar7->rightvol = 0;
          }
          else {
            iVar9 = pcVar7->leftvol;
          }
          iVar5 = total_channels;
          if (iVar9 < 0) {
            pcVar7->leftvol = 0;
            iVar5 = total_channels;
          }
        }
      }
      iVar8 = iVar8 + 1;
      pcVar7 = pcVar7 + 1;
    } while (iVar8 < iVar5);
  }
  if (snd_show.value != 0.0) {
    if (iVar5 < 1) {
      iVar8 = 0;
    }
    else {
      pcVar7 = channels;
      iVar9 = 0;
      iVar8 = 0;
      do {
        if (pcVar7->sfx != (sfx_t *)0x0) {
          if ((pcVar7->leftvol != 0) || (pcVar7->rightvol != 0)) {
            iVar8 = iVar8 + 1;
            Con_Printf("%3i %3i %s\n",pcVar7->leftvol,pcVar7->rightvol,pcVar7->sfx);
            iVar5 = total_channels;
          }
        }
        iVar9 = iVar9 + 1;
        pcVar7 = pcVar7 + 1;
      } while (iVar9 < iVar5);
    }
    Con_Printf("----(%i)----\n",iVar8);
  }
  S_Update_();
  return;
}


// S_UpdateAmbientSounds  @ 001a8680
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
                    /* Unresolved local var: mleaf_t * l@[???]
                       Unresolved local var: float vol@[???]
                       Unresolved local var: int ambient_channel@[???]
                       Unresolved local var: channel_t * chan@[???] */
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
       (float)channels[0].master_vol < fVar2)) goto LAB_001a873d;
  }
  else {
    channels[0].master_vol = (int)(fVar3 * ambient_fade.value + (float)channels[0].master_vol);
    if (fVar2 < (float)channels[0].master_vol) {
LAB_001a873d:
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
    if (fVar2 < (float)channels[1].master_vol) goto LAB_001a89da;
  }
  else if ((fVar2 < (float)channels[1].master_vol) &&
          (channels[1].master_vol =
                (int)((float)channels[1].master_vol - fVar3 * ambient_fade.value),
          (float)channels[1].master_vol < fVar2)) {
LAB_001a89da:
    channels[1].master_vol = (int)fVar2;
  }
  fVar1 = (float)pmVar4->ambient_sound_level[2] * ambient_level.value;
  fVar2 = 0.0;
  if (8.0 <= fVar1) {
    fVar2 = fVar1;
  }
  if ((float)channels[2].master_vol < fVar2) {
    channels[2].master_vol = (int)(fVar3 * ambient_fade.value + (float)channels[2].master_vol);
    if ((float)channels[2].master_vol <= fVar2) goto LAB_001a8882;
  }
  else if (((float)channels[2].master_vol <= fVar2) ||
          (channels[2].master_vol =
                (int)((float)channels[2].master_vol - fVar3 * ambient_fade.value),
          fVar2 <= (float)channels[2].master_vol)) goto LAB_001a8882;
  channels[2].master_vol = (int)fVar2;
LAB_001a8882:
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


// S_Update_  @ 001a9150
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void S_Update_(void)

{
  int iVar1;
  int iVar2;
  channel_t *ch;
  uint unaff_ESI;
  int fill;
  int local_30;
  uint local_2c;
  int local_24;
  
                    /* Unresolved local var: uint endtime@[???]
                       Unresolved local var: int samps@[???] */
  if ((sound_started != 0) && (snd_blocked < 1)) {
                    /* Unresolved local var: int samplepos@[???]
                       Unresolved local var: int fullsamples@[???] */
    if (shm != (dma_t *)0x0) {
      local_24 = shm->samples / shm->channels;
    }
    iVar1 = SNDDMA_GetDMAPos();
    if ((iVar1 < GetSoundtime::oldsamplepos) &&
       (GetSoundtime::buffers = GetSoundtime::buffers + 1, 0x40000000 < paintedtime)) {
      GetSoundtime::buffers = 0;
      paintedtime = local_24;
                    /* Unresolved local var: int i@[???] */
      if (sound_started != 0) {
        ch = channels;
        total_channels = 0x24;
        do {
          if (ch->sfx != (sfx_t *)0x0) {
            S_FreeChannel(ch);
          }
          ch = ch + 1;
        } while (ch != (channel_t *)listener_up);
        Q_memset(channels,0,0x2000);
        Wavstream_Init();
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int clear@[???] */
                    /* Unresolved local var: int clear@[???] */
        if ((sound_started != 0) && (shm != (dma_t *)0x0)) {
          fill = 0;
          if (shm->samplebits == 8) {
            fill = 0x80;
          }
          iVar2 = shm->samplebits * shm->samples;
          if (iVar2 < 0) {
            iVar2 = iVar2 + 7;
          }
          Q_memset(shm->buffer,fill,iVar2 >> 3);
        }
      }
    }
    local_2c = unaff_ESI;
    if (shm != (dma_t *)0x0) {
      soundtime = iVar1 / shm->channels + local_24 * GetSoundtime::buffers;
      local_2c = (uint)(longlong)
                       ROUND((float)soundtime + (float)shm->dmaspeed * _snd_mixahead.value);
      local_30 = shm->samples >> ((char)shm->channels - 1U & 0x1f);
    }
    if (local_30 < (int)(local_2c - soundtime)) {
      local_2c = soundtime + local_30;
    }
    GetSoundtime::oldsamplepos = iVar1;
    S_PaintChannels(local_2c >> 1);
    SNDDMA_Submit();
    return;
  }
  return;
}


