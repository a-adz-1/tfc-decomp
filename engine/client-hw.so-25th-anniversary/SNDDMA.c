// SNDDMA_GetDMAPos  @ 001ccce0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SNDDMA_GetDMAPos(void)

{
  return shm->samples - 1U & SNDDMA_GetDMAPos::s >> ((byte)sample16 & 0x1f);
}


// SNDDMA_Init  @ 001ccae0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean SNDDMA_Init(void)

{
  dma_t *pdVar1;
  int iVar2;
  uint uVar3;
  SDL_AudioDeviceID SVar4;
  uchar *puVar5;
  int iVar6;
  int local_3c;
  undefined4 local_38;
  undefined2 local_34;
  code *local_2c;
  undefined1 local_24 [24];
  
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
  SNDDMA_GetDMAPos::s = 0;
  shm = &sn;
  bInitialized = '\x01';
  setenv("PULSE_PROP_application.name","Half-Life 1",1);
  setenv("PULSE_PROP_media.role","game",1);
  iVar2 = SDL_WasInit(0x10);
  if ((iVar2 != 0) || (iVar2 = SDL_InitSubSystem(0x10), iVar2 != 0)) {
    uVar3 = 0;
    do {
      *(undefined4 *)((int)&local_3c + uVar3) = 0;
      *(undefined4 *)((int)&local_38 + uVar3) = 0;
      uVar3 = uVar3 + 8;
    } while (uVar3 < 0x18);
    local_38._0_2_ = 0x8010;
    local_34 = 0x400;
    local_3c = shm->dmaspeed;
    local_38._2_1_ = (undefined1)shm->channels;
    local_2c = AudioCallbackEntry;
    SVar4 = SDL_OpenAudioDevice(0,0,&local_3c,local_24,0xf);
    m_devId = SVar4;
    if (SVar4 != 0) {
      puVar5 = calloc(0x10000,1);
      pdVar1 = shm;
      shm->soundalive = true;
      pdVar1->splitbuffer = false;
      iVar2 = pdVar1->samplebits;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 7;
      }
      sndBuffers = puVar5;
      pdVar1->samples = (int)(0x10000 / (longlong)(iVar2 >> 3));
      pdVar1->samplepos = 0;
      pdVar1->submission_chunk = 1;
      pdVar1->buffer = puVar5;
      iVar2 = pdVar1->samplebits;
      iVar6 = iVar2 + 7;
      if (-1 < iVar2) {
        iVar6 = iVar2;
      }
      sample16 = (iVar6 >> 3) + -1;
      SDL_PauseAudioDevice(SVar4,0);
      return true;
    }
  }
  puts("SDL_InitSubSystem(SDL_INIT_AUDIO) failed.");
  bInitialized = '\0';
  return false;
}


// SNDDMA_Shutdown  @ 001cca80
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


// SNDDMA_Submit  @ 001cccd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SNDDMA_Submit(void)

{
  return;
}


