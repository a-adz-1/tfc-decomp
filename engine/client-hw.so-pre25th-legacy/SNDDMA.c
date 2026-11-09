// SNDDMA_GetDMAPos  @ 00218480
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SNDDMA_GetDMAPos(void)

{
                    /* Unresolved local var: int s@[???] */
  return shm->samples - 1U & snd_sent_position >> ((byte)sample16 & 0x1f);
}


// SNDDMA_Init  @ 00218240
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean SNDDMA_Init(void)

{
  dma_t *pdVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  SDL_AudioDeviceID SVar5;
  uchar *__s;
  int iVar6;
  int local_4c;
  undefined2 local_48;
  undefined1 local_46;
  undefined2 local_44 [2];
  code *apcStack_40 [3];
  undefined1 local_34 [36];
  
                    /* Unresolved local var: char * appname@[???]
                       Unresolved local var: SDL_AudioSpec desired@[???]
                       Unresolved local var: SDL_AudioSpec obtained@[???]
                       Unresolved local var: int gSndBufSize@[???] */
  if (bInitialized != '\0') {
    return true;
  }
  sn.channels = 2;
  sn.samplebits = 0x10;
  sn.speed = 0x2b11;
  sn.dmaspeed = 0x5622;
  snd_sent_position = 0;
  bInitialized = '\x01';
  shm = &sn;
  setenv("PULSE_PROP_application.name","Half-Life 1",1);
  setenv("PULSE_PROP_media.role","game",1);
  iVar2 = SDL_WasInit(0x10);
  if ((iVar2 != 0) || (iVar2 = SDL_InitSubSystem(0x10), iVar2 != 0)) {
    uVar4 = 0;
    do {
      uVar3 = uVar4;
      *(undefined4 *)((int)&local_4c + uVar3) = 0;
      *(undefined4 *)((int)&local_48 + uVar3) = 0;
      *(undefined4 *)((int)local_44 + uVar3) = 0;
      *(undefined4 *)((int)apcStack_40 + uVar3) = 0;
      uVar4 = uVar3 + 0x10;
    } while (uVar4 < 0x10);
    *(undefined4 *)(uVar4 + (int)&local_4c) = 0;
    *(undefined4 *)((int)apcStack_40 + uVar3 + 8) = 0;
    local_48 = 0x8010;
    local_44[0] = 0x400;
    local_4c = shm->dmaspeed;
    local_46 = (undefined1)shm->channels;
    apcStack_40[1] = AudioCallbackEntry;
    SVar5 = SDL_OpenAudioDevice(0,0,&local_4c,local_34,7);
    m_devId = SVar5;
    if (SVar5 != 0) {
      __s = malloc(0x10000);
      sndBuffers = __s;
      memset(__s,0,0x10000);
      pdVar1 = shm;
      shm->soundalive = true;
      pdVar1->splitbuffer = false;
      iVar2 = pdVar1->samplebits;
      iVar6 = iVar2 + 7;
      if (-1 < iVar2) {
        iVar6 = iVar2;
      }
      pdVar1->samples = (int)(0x10000 / (longlong)(iVar6 >> 3));
      pdVar1->samplepos = 0;
      pdVar1->submission_chunk = 1;
      pdVar1->buffer = __s;
      iVar2 = pdVar1->samplebits;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 7;
      }
      sample16 = (iVar2 >> 3) + -1;
      SDL_PauseAudioDevice(SVar5,0);
      return true;
    }
  }
  puts("SDL_InitSubSystem(SDL_INIT_AUDIO) failed.");
  bInitialized = '\0';
  return false;
}


// SNDDMA_Shutdown  @ 002181e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SNDDMA_Shutdown(void)

{
  if (bInitialized != '\0') {
    bInitialized = '\0';
    if (m_devId != 0) {
      SDL_CloseAudioDevice(m_devId);
      m_devId = 0;
    }
    SDL_QuitSubSystem(0x10);
    free(sndBuffers);
    sndBuffers = (void *)0x0;
  }
  return;
}


// SNDDMA_Submit  @ 00218470
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SNDDMA_Submit(void)

{
  return;
}


