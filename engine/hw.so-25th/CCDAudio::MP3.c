// CCDAudio::MP3_Init  @ 001be630
/* DWARF original prototype: bool MP3_Init(CCDAudio * this) */

bool __thiscall CCDAudio::MP3_Init(CCDAudio *this)

{
  __sighandler_t __handler;
  int iVar1;
  undefined4 uVar2;
  
                    /* Unresolved local var: __sighandler_t curfilter@[???] */
  if (MP3digitalDriver != (HDIGDRIVER_conflict)0x0) {
    AIL_close_digital_driver(MP3digitalDriver);
    MP3digitalDriver = (HDIGDRIVER_conflict)0x0;
  }
  AIL_set_redist_directory("redist");
  __handler = signal(0xb,linux_handler);
  iVar1 = __sigsetjmp(g_mark,1);
  if (iVar1 != 0) {
    Con_Printf("MP3 startup failed due, mp3 playback will not be available.\n");
    return false;
  }
  AIL_startup();
  signal(0xb,__handler);
  AIL_set_preference(6,10);
  uVar2 = RADSS_OalInstallDriver(0,0);
  MP3digitalDriver = (HDIGDRIVER_conflict)AIL_open_generic_digital_driver(0x5622,0x10,2,1,uVar2);
  return MP3digitalDriver != (HDIGDRIVER_conflict)0x0;
}


// CCDAudio::MP3_InitStream  @ 001beb30
/* DWARF original prototype: bool MP3_InitStream(CCDAudio * this, int trackNum, bool looping) */

bool __thiscall CCDAudio::MP3_InitStream(CCDAudio *this,int trackNum,bool looping)

{
  float fVar1;
  HSTREAM_conflict p_Var2;
  undefined4 uVar3;
  int in_GS_OFFSET;
  bool bVar4;
  char local_220 [512];
  int local_20;
  
                    /* Unresolved local var: char[512] fullPath@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar4 = MP3digitalDriver == (HDIGDRIVER_conflict)0x0;
  this->m_bIsPrimed = false;
  if (bVar4) {
    bVar4 = MP3_Init(this);
    if (bVar4) goto LAB_001beb70;
  }
  else {
LAB_001beb70:
    FS_GetLocalPath(g_pszMP3trackFileMap[trackNum],local_220,0x200);
    FS_GetLocalCopy(local_220);
    p_Var2 = MP3stream;
    if ((this->m_bEnabled != false) &&
       ((this->m_bIsPlaying != false || (this->m_bWasPlaying != false)))) {
      this->m_bIsPlaying = false;
      this->m_bWasPlaying = false;
      this->m_szPendingPlayFilename[0] = '\0';
      if (p_Var2 != (HSTREAM_conflict)0x0) {
        AIL_pause_stream(p_Var2,1);
        AIL_close_stream(MP3stream);
        MP3stream = (HSTREAM_conflict)0x0;
      }
      fVar1 = this->m_flMP3Volume;
      this->m_bIsPrimed = false;
      (this->m_MP3).inuse = false;
      (this->m_MP3).suspended = false;
      (this->m_MP3).playing = false;
      (this->m_MP3).trackname[0] = '\0';
      (this->m_MP3).tracknum = 0;
      (this->m_MP3).looping = false;
      (this->m_MP3).volume = fVar1;
      this->m_flPlayTime = 0.0;
      *(undefined4 *)&this->m_dStartTime = 0;
      *(undefined4 *)((int)&this->m_dStartTime + 4) = 0;
      *(undefined4 *)&this->m_dPauseTime = 0;
      *(undefined4 *)((int)&this->m_dPauseTime + 4) = 0;
    }
    *(undefined4 *)&this->m_dFadeOutTime = 0;
    *(undefined4 *)((int)&this->m_dFadeOutTime + 4) = 0;
    MP3stream = (HSTREAM_conflict)AIL_open_stream(MP3digitalDriver,local_220,0);
    if (MP3stream != (HSTREAM_conflict)0x0) {
      uVar3 = AIL_stream_sample_handle(MP3stream);
      uVar3 = AIL_sample_playback_rate(uVar3);
      AIL_set_stream_user_data(MP3stream,0,uVar3);
      fVar1 = (this->m_MP3).volume;
      uVar3 = AIL_stream_sample_handle(MP3stream);
      AIL_set_sample_volume_pan(uVar3,fVar1,0x3f000000);
      __strcpy_chk((this->m_MP3).trackname,g_pszMP3trackFileMap[trackNum],0x200);
      bVar4 = true;
      if ((looping) && (MP3stream != (HSTREAM_conflict)0x0)) {
        AIL_set_stream_loop_count(MP3stream,0);
        bVar4 = true;
      }
      goto LAB_001bec7b;
    }
  }
  bVar4 = false;
LAB_001bec7b:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return bVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CCDAudio::MP3_InitStream  @ 001bff00
/* DWARF original prototype: bool MP3_InitStream(CCDAudio * this, char * filename, bool looping) */

bool __thiscall CCDAudio::MP3_InitStream(CCDAudio *this,char *filename,bool looping)

{
  bool bVar1;
  char *pcVar2;
  int trackNum;
  
                    /* Unresolved local var: int iTrackNum@[???] */
  if ((filename == (char *)0x0) || (*filename == '\0')) {
    return false;
  }
                    /* Unresolved local var: int iTrackNum@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int iTrack@[???] */
  pcVar2 = Q_strstr(filename,":");
  if (pcVar2 == (char *)0x0) {
    pcVar2 = Q_strstr(filename,"..");
    if (pcVar2 == (char *)0x0) {
      trackNum = MP3_GetTrack(filename);
      goto LAB_001bff5a;
    }
  }
  trackNum = 0;
LAB_001bff5a:
  bVar1 = MP3_InitStream(this,trackNum,looping);
  return bVar1;
}


// CCDAudio::MP3_Loop  @ 001c0010
/* DWARF original prototype: void MP3_Loop(CCDAudio * this) */

void __thiscall CCDAudio::MP3_Loop(CCDAudio *this)

{
  if (MP3stream != (HSTREAM_conflict)0x0) {
    AIL_set_stream_loop_count(MP3stream,0);
  }
  return;
}


// CCDAudio::MP3_PlayTrack  @ 001bf790
/* DWARF original prototype: bool MP3_PlayTrack(CCDAudio * this, char * filename, bool looping) */

bool __thiscall CCDAudio::MP3_PlayTrack(CCDAudio *this,char *filename,bool looping)

{
  float fVar1;
  HSTREAM_conflict p_Var2;
  double dVar3;
  bool bVar4;
  char *pcVar5;
  int trackNum;
  char cVar6;
  
  if (this->m_bIsPrimed == false) {
                    /* Unresolved local var: int iTrackNum@[???] */
    if (filename == (char *)0x0) {
      return false;
    }
    if (*filename == '\0') {
      return false;
    }
                    /* Unresolved local var: int iTrackNum@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int iTrack@[???] */
    pcVar5 = Q_strstr(filename,":");
    if ((pcVar5 == (char *)0x0) && (pcVar5 = Q_strstr(filename,".."), pcVar5 == (char *)0x0)) {
      trackNum = MP3_GetTrack(filename);
    }
    else {
      trackNum = 0;
    }
    bVar4 = MP3_InitStream(this,trackNum,looping);
    if (!bVar4) {
      return false;
    }
  }
  p_Var2 = MP3stream;
  this->m_bIsPrimed = false;
  if (p_Var2 != (HSTREAM_conflict)0x0) {
    AIL_start_stream(p_Var2);
  }
  (this->m_MP3).inuse = true;
  this->m_flPlayTime = 0.0;
  fVar1 = this->m_flMP3Volume;
  (this->m_MP3).playing = true;
  (this->m_MP3).tracknum = 0;
  (this->m_MP3).looping = looping;
  *(undefined4 *)&this->m_dStartTime = 0;
  *(undefined4 *)((int)&this->m_dStartTime + 4) = 0;
  *(undefined4 *)&this->m_dPauseTime = 0;
  *(undefined4 *)((int)&this->m_dPauseTime + 4) = 0;
  this->m_bIsLooping = looping;
  this->m_nPlayTrack = 0;
  this->m_bIsPlaying = true;
  if ((fVar1 == 0.0) && (cVar6 = this->m_bEnabled, (bool)cVar6 != false)) {
    bVar4 = (bool)cVar6;
    if (MP3stream != (HSTREAM_conflict)0x0) {
      AIL_pause_stream(MP3stream,1);
      bVar4 = this->m_bIsPlaying;
    }
    dVar3 = realtime;
    this->m_bWasPlaying = bVar4;
    this->m_dPauseTime = dVar3;
    this->m_bIsPlaying = false;
    this->m_szPendingPlayFilename[0] = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  return (bool)cVar6;
}


// CCDAudio::MP3_PlayTrack  @ 001bf960
/* DWARF original prototype: bool MP3_PlayTrack(CCDAudio * this, int trackNum, bool looping) */

bool __thiscall CCDAudio::MP3_PlayTrack(CCDAudio *this,int trackNum,bool looping)

{
  float fVar1;
  HSTREAM_conflict p_Var2;
  double dVar3;
  bool bVar4;
  char cVar5;
  
  if (((trackNum < 2) || (g_iMP3NumTracks <= trackNum)) ||
     ((this->m_bIsPrimed == false && (bVar4 = MP3_InitStream(this,trackNum,looping), !bVar4)))) {
    cVar5 = '\0';
  }
  else {
    p_Var2 = MP3stream;
    this->m_bIsPrimed = false;
    if (p_Var2 != (HSTREAM_conflict)0x0) {
      AIL_start_stream(p_Var2);
    }
    (this->m_MP3).inuse = true;
    this->m_flPlayTime = 0.0;
    fVar1 = this->m_flMP3Volume;
    (this->m_MP3).playing = true;
    (this->m_MP3).tracknum = trackNum;
    (this->m_MP3).looping = looping;
    *(undefined4 *)&this->m_dStartTime = 0;
    *(undefined4 *)((int)&this->m_dStartTime + 4) = 0;
    *(undefined4 *)&this->m_dPauseTime = 0;
    *(undefined4 *)((int)&this->m_dPauseTime + 4) = 0;
    this->m_bIsLooping = looping;
    this->m_nPlayTrack = trackNum;
    this->m_bIsPlaying = true;
    if ((fVar1 != 0.0) || (cVar5 = this->m_bEnabled, (bool)cVar5 == false)) {
      return true;
    }
    bVar4 = (bool)cVar5;
    if (MP3stream != (HSTREAM_conflict)0x0) {
      AIL_pause_stream(MP3stream,1);
      bVar4 = this->m_bIsPlaying;
    }
    dVar3 = realtime;
    this->m_bWasPlaying = bVar4;
    this->m_dPauseTime = dVar3;
    this->m_bIsPlaying = false;
    this->m_szPendingPlayFilename[0] = '\0';
  }
  return (bool)cVar5;
}


// CCDAudio::MP3_PlayTrackFinalize  @ 001be560
/* DWARF original prototype: void MP3_PlayTrackFinalize(CCDAudio * this, int trackNum, bool looping)
    */

void __thiscall CCDAudio::MP3_PlayTrackFinalize(CCDAudio *this,int trackNum,bool looping)

{
  float fVar1;
  bool bVar2;
  
  if (MP3stream != (HSTREAM_conflict)0x0) {
    AIL_start_stream(MP3stream);
  }
  (this->m_MP3).inuse = true;
  this->m_flPlayTime = 0.0;
  fVar1 = this->m_flMP3Volume;
  (this->m_MP3).playing = true;
  (this->m_MP3).tracknum = trackNum;
  (this->m_MP3).looping = looping;
  *(undefined4 *)&this->m_dStartTime = 0;
  *(undefined4 *)((int)&this->m_dStartTime + 4) = 0;
  *(undefined4 *)&this->m_dPauseTime = 0;
  *(undefined4 *)((int)&this->m_dPauseTime + 4) = 0;
  this->m_bIsLooping = looping;
  this->m_nPlayTrack = trackNum;
  this->m_bIsPlaying = true;
  if ((fVar1 == 0.0) && (bVar2 = this->m_bEnabled, bVar2 != false)) {
    if (MP3stream != (HSTREAM_conflict)0x0) {
      AIL_pause_stream(MP3stream,1);
      bVar2 = this->m_bIsPlaying;
    }
    this->m_bWasPlaying = bVar2;
    this->m_dPauseTime = realtime;
    this->m_bIsPlaying = false;
    this->m_szPendingPlayFilename[0] = '\0';
    return;
  }
  return;
}


// CCDAudio::MP3_ReleaseDriver  @ 001bea70
/* DWARF original prototype: void MP3_ReleaseDriver(CCDAudio * this) */

void __thiscall CCDAudio::MP3_ReleaseDriver(CCDAudio *this)

{
  if (MP3digitalDriver != (HDIGDRIVER_conflict)0x0) {
    AIL_close_digital_driver(MP3digitalDriver);
    MP3digitalDriver = (HDIGDRIVER_conflict)0x0;
  }
  return;
}


// CCDAudio::MP3_Resume_Audio  @ 001bfd90
/* DWARF original prototype: void MP3_Resume_Audio(CCDAudio * this) */

void __thiscall CCDAudio::MP3_Resume_Audio(CCDAudio *this)

{
  float fVar1;
  int trackNum;
  HSTREAM_conflict p_Var2;
  double dVar3;
  bool bVar4;
  bool bVar5;
  
  MP3_Init(this);
  if (((this->m_MP3).playing != false) && ((this->m_MP3).suspended != false)) {
    trackNum = (this->m_MP3).tracknum;
    if (trackNum == 0) {
      MP3_PlayTrack(this,(this->m_MP3).trackname,(this->m_MP3).looping);
      return;
    }
    if (((1 < trackNum) && (trackNum < g_iMP3NumTracks)) &&
       ((bVar5 = (this->m_MP3).looping, this->m_bIsPrimed != false ||
        (bVar4 = MP3_InitStream(this,trackNum,bVar5), bVar4)))) {
      p_Var2 = MP3stream;
      this->m_bIsPrimed = false;
      if (p_Var2 != (HSTREAM_conflict)0x0) {
        AIL_start_stream(p_Var2);
      }
      (this->m_MP3).inuse = true;
      this->m_flPlayTime = 0.0;
      fVar1 = this->m_flMP3Volume;
      (this->m_MP3).playing = true;
      (this->m_MP3).tracknum = trackNum;
      (this->m_MP3).looping = bVar5;
      *(undefined4 *)&this->m_dStartTime = 0;
      *(undefined4 *)((int)&this->m_dStartTime + 4) = 0;
      *(undefined4 *)&this->m_dPauseTime = 0;
      *(undefined4 *)((int)&this->m_dPauseTime + 4) = 0;
      this->m_bIsLooping = bVar5;
      this->m_nPlayTrack = trackNum;
      this->m_bIsPlaying = true;
      if ((fVar1 == 0.0) && (bVar5 = this->m_bEnabled, bVar5 != false)) {
        if (MP3stream != (HSTREAM_conflict)0x0) {
          AIL_pause_stream(MP3stream,1);
          bVar5 = this->m_bIsPlaying;
        }
        dVar3 = realtime;
        this->m_bWasPlaying = bVar5;
        this->m_dPauseTime = dVar3;
        this->m_bIsPlaying = false;
        this->m_szPendingPlayFilename[0] = '\0';
      }
    }
  }
  return;
}


// CCDAudio::MP3_SetPause  @ 001c0030
/* DWARF original prototype: void MP3_SetPause(CCDAudio * this, bool OnOff) */

void __thiscall CCDAudio::MP3_SetPause(CCDAudio *this,bool OnOff)

{
  if (MP3stream != (HSTREAM_conflict)0x0) {
    AIL_pause_stream();
    return;
  }
  return;
}


// CCDAudio::MP3_SetVolume  @ 001bea90
/* DWARF original prototype: float MP3_SetVolume(CCDAudio * this, float NewVol) */

float __thiscall CCDAudio::MP3_SetVolume(CCDAudio *this,float NewVol)

{
  float fVar1;
  HSTREAM_conflict p_Var2;
  undefined4 uVar3;
  
  p_Var2 = MP3stream;
  if (NewVol < 0.0) {
    NewVol = 0.0;
  }
  else if (1.0 < NewVol) {
    NewVol = 1.0;
  }
  fVar1 = (this->m_MP3).volume;
  if (NewVol != fVar1) {
    (this->m_MP3).volume = NewVol;
    if (p_Var2 == (HSTREAM_conflict)0x0) {
      return NewVol;
    }
    uVar3 = AIL_stream_sample_handle(p_Var2);
    AIL_set_sample_volume_pan(uVar3,NewVol,0x3f000000);
    fVar1 = (this->m_MP3).volume;
  }
  return fVar1;
}


// CCDAudio::MP3_Shutdown  @ 001be9d0
/* DWARF original prototype: void MP3_Shutdown(CCDAudio * this) */

void __thiscall CCDAudio::MP3_Shutdown(CCDAudio *this)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???] */
  if (MP3stream != (HSTREAM_conflict)0x0) {
    AIL_pause_stream(MP3stream,1);
    AIL_close_stream(MP3stream);
    MP3stream = (HSTREAM_conflict)0x0;
  }
  this->m_bIsPrimed = false;
  if (MP3digitalDriver != (HDIGDRIVER_conflict)0x0) {
    AIL_close_digital_driver(MP3digitalDriver);
    MP3digitalDriver = (HDIGDRIVER_conflict)0x0;
  }
  AIL_shutdown();
  iVar1 = g_iMP3FirstMalloc;
  if (g_iMP3FirstMalloc < 200) {
    do {
      if (g_pszMP3trackFileMap[iVar1] != (char *)0x0) {
        Mem_Free(g_pszMP3trackFileMap[iVar1]);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 != 200);
  }
  return;
}


// CCDAudio::MP3_StartStream  @ 001bffb0
/* DWARF original prototype: void MP3_StartStream(CCDAudio * this) */

void __thiscall CCDAudio::MP3_StartStream(CCDAudio *this)

{
  if (MP3stream != (HSTREAM_conflict)0x0) {
    AIL_start_stream();
    return;
  }
  return;
}


// CCDAudio::MP3_StopStream  @ 001bffd0
/* DWARF original prototype: void MP3_StopStream(CCDAudio * this) */

void __thiscall CCDAudio::MP3_StopStream(CCDAudio *this)

{
  if (MP3stream != (HSTREAM_conflict)0x0) {
    AIL_pause_stream(MP3stream,1);
    AIL_close_stream(MP3stream);
    MP3stream = (HSTREAM_conflict)0x0;
  }
  this->m_bIsPrimed = false;
  return;
}


// CCDAudio::MP3_Suspend_Audio  @ 001bd250
/* DWARF original prototype: void MP3_Suspend_Audio(CCDAudio * this) */

void __thiscall CCDAudio::MP3_Suspend_Audio(CCDAudio *this)

{
  bool bVar1;
  HSTREAM_conflict p_Var2;
  HDIGDRIVER_conflict p_Var3;
  
  bVar1 = this->m_bIsPlaying;
  (this->m_MP3).playing = bVar1;
  p_Var2 = MP3stream;
  if (bVar1 == false) {
    if (MP3stream == (HSTREAM_conflict)0x0) goto LAB_001bd29c;
  }
  else {
    if (MP3stream == (HSTREAM_conflict)0x0) goto LAB_001bd29c;
    (this->m_MP3).suspended = true;
  }
  AIL_pause_stream(p_Var2,1);
  AIL_close_stream(MP3stream);
  MP3stream = (HSTREAM_conflict)0x0;
LAB_001bd29c:
  p_Var3 = MP3digitalDriver;
  this->m_bIsPrimed = false;
  if (p_Var3 != (HDIGDRIVER_conflict)0x0) {
    AIL_close_digital_driver(p_Var3);
    MP3digitalDriver = (HDIGDRIVER_conflict)0x0;
  }
  return;
}


