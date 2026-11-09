// CCDAudio::_CDReset  @ 001bd480
/* DWARF original prototype: void _CDReset(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_CDReset(CCDAudio *this,int param_1,int param_2)

{
  _func_int_varargs *p_Var1;
  HDIGDRIVER_conflict p_Var2;
  int iVar3;
  
  p_Var1 = (this->super_ICDAudio)._vptr_ICDAudio[1];
  if (p_Var1 != Shutdown) {
    (*p_Var1)(this);
    goto LAB_001bd555;
  }
  if ((this->m_MP3).inuse == false) {
LAB_001bd4ab:
    if (MP3stream != (HSTREAM_conflict)0x0) {
                    /* Unresolved local var: int i@[???] */
      AIL_pause_stream(MP3stream,1);
      AIL_close_stream(MP3stream);
      MP3stream = (HSTREAM_conflict)0x0;
    }
  }
  else if (MP3stream != (HSTREAM_conflict)0x0) {
    AIL_pause_stream(MP3stream,1);
    goto LAB_001bd4ab;
  }
  p_Var2 = MP3digitalDriver;
  this->m_bIsPrimed = false;
  if (p_Var2 != (HDIGDRIVER_conflict)0x0) {
    AIL_close_digital_driver(p_Var2);
    MP3digitalDriver = (HDIGDRIVER_conflict)0x0;
  }
  AIL_shutdown();
  iVar3 = g_iMP3FirstMalloc;
  if (g_iMP3FirstMalloc < 200) {
    do {
      if (g_pszMP3trackFileMap[iVar3] != (char *)0x0) {
        Mem_Free(g_pszMP3trackFileMap[iVar3]);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 200);
  }
  if (this->m_bInitialized != false) {
    this->m_flPlayTime = 0.0;
    *(undefined4 *)&this->m_dStartTime = 0;
    *(undefined4 *)((int)&this->m_dStartTime + 4) = 0;
    *(undefined4 *)&this->m_dPauseTime = 0;
    *(undefined4 *)((int)&this->m_dPauseTime + 4) = 0;
  }
LAB_001bd555:
  usleep(1000000);
                    /* WARNING: Could not recover jumptable at 0x001bd56e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(this->super_ICDAudio)._vptr_ICDAudio)();
  return;
}


// CCDAudio::_CDUpdate  @ 001bd7c0
/* DWARF original prototype: void _CDUpdate(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_CDUpdate(CCDAudio *this,int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  IThread *pIVar3;
  HSTREAM_conflict p_Var4;
  int iVar5;
  undefined4 uVar6;
  longdouble lVar7;
  double dVar8;
  
                    /* Unresolved local var: double curVolume@[???]
                       Unresolved local var: double current@[???] */
  fVar2 = MP3Volume.value;
  if (this->m_bIsPlaying != false) {
                    /* Unresolved local var: double curVolume@[???]
                       Unresolved local var: double current@[???] */
    if (this->m_dFadeOutTime != 0.0) {
                    /* Unresolved local var: double currentTime@[???] */
      dVar8 = Sys_FloatTime();
      p_Var4 = MP3stream;
      if ((longdouble)dVar8 < (longdouble)this->m_dFadeOutTime) {
        lVar7 = (((longdouble)this->m_dFadeOutTime - (longdouble)dVar8) /
                (longdouble)MP3FadeTime.value) * (longdouble)MP3Volume.value;
        fVar1 = (this->m_MP3).volume;
      }
      else {
        if ((this->m_bEnabled == false) ||
           ((this->m_bIsPlaying == false && (this->m_bWasPlaying == false)))) {
          fVar1 = (this->m_MP3).volume;
        }
        else {
          this->m_bIsPlaying = false;
          this->m_bWasPlaying = false;
          this->m_szPendingPlayFilename[0] = '\0';
          if (p_Var4 != (HSTREAM_conflict)0x0) {
            AIL_pause_stream(p_Var4,1);
            AIL_close_stream(MP3stream);
            MP3stream = (HSTREAM_conflict)0x0;
          }
          fVar1 = this->m_flMP3Volume;
          this->m_bIsPrimed = false;
          (this->m_MP3).inuse = false;
          (this->m_MP3).volume = fVar1;
          (this->m_MP3).suspended = false;
          (this->m_MP3).playing = false;
          (this->m_MP3).trackname[0] = '\0';
          (this->m_MP3).tracknum = 0;
          (this->m_MP3).looping = false;
          this->m_flPlayTime = 0.0;
          *(undefined4 *)&this->m_dStartTime = 0;
          *(undefined4 *)((int)&this->m_dStartTime + 4) = 0;
          *(undefined4 *)&this->m_dPauseTime = 0;
          *(undefined4 *)((int)&this->m_dPauseTime + 4) = 0;
        }
        lVar7 = (longdouble)fVar2;
        *(undefined4 *)&this->m_dFadeOutTime = 0;
        *(undefined4 *)((int)&this->m_dFadeOutTime + 4) = 0;
      }
      p_Var4 = MP3stream;
      fVar2 = (float)lVar7;
      if (fVar2 < 0.0) {
        fVar2 = 0.0;
      }
      else if (1.0 < fVar2) {
        fVar2 = 1.0;
      }
      if ((fVar2 != fVar1) && ((this->m_MP3).volume = fVar2, p_Var4 != (HSTREAM_conflict)0x0)) {
        uVar6 = AIL_stream_sample_handle(p_Var4);
        AIL_set_sample_volume_pan(uVar6,fVar2,0x3f000000);
      }
      iVar5 = (*thread->_vptr_IThread[4])(thread,_CDUpdate,0,0,0);
      if ((char)iVar5 != '\0') {
        usleep(100);
      }
    }
    if ((this->m_MP3).inuse != false) {
      iVar5 = AIL_stream_status(MP3stream);
      this->m_bIsPlaying = iVar5 == 4;
      if (iVar5 != 4) {
        this->m_szPendingPlayFilename[0] = '\0';
      }
    }
    if ((((this->m_flPlayTime != 0.0) && ((longdouble)this->m_dStartTime != (longdouble)0)) &&
        (this->m_flPlayTime + 2.0 <= (float)((longdouble)realtime - (longdouble)this->m_dStartTime))
        ) && (this->m_bIsPlaying != false)) {
      this->m_bIsPlaying = false;
      this->m_szPendingPlayFilename[0] = '\0';
      pIVar3 = thread;
      if (this->m_bIsLooping != false) {
        iVar5 = this->m_nPlayTrack;
        UNRECOVERED_JUMPTABLE = (this->super_ICDAudio)._vptr_ICDAudio[2];
        if (UNRECOVERED_JUMPTABLE != Play) {
                    /* WARNING: Could not recover jumptable at 0x001bdab6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*UNRECOVERED_JUMPTABLE)();
          return;
        }
        *(undefined4 *)&this->m_dFadeOutTime = 0;
        *(undefined4 *)((int)&this->m_dFadeOutTime + 4) = 0;
        (*pIVar3->_vptr_IThread[4])(pIVar3,_Play,0,iVar5,1);
      }
    }
  }
  return;
}


// CCDAudio::_CloseDoor  @ 001bcc20
/* DWARF original prototype: void _CloseDoor(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_CloseDoor(CCDAudio *this,int param_1,int param_2)

{
  this->m_flPlayTime = 0.0;
  this->m_dStartTime = 0.0;
  this->m_dPauseTime = 0.0;
  return;
}


// CCDAudio::_Eject  @ 001bd120
/* CCDAudio::_Eject(int, int) */

void CCDAudio::_Eject(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  return;
}


// CCDAudio::_GetAudioDiskInfo  @ 001bcc30
/* DWARF original prototype: void _GetAudioDiskInfo(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_GetAudioDiskInfo(CCDAudio *this,int param_1,int param_2)

{
  this->m_bIsCDValid = false;
  this->m_nMaxCDTrack = 0;
  return;
}


// CCDAudio::_Init  @ 001bcc50
/* DWARF original prototype: void _Init(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_Init(CCDAudio *this,int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_20;
  
                    /* Unresolved local var: int n@[???] */
  uVar1 = -(((uint)this & 0xf) >> 2) & 3;
  if (uVar1 == 0) {
    iVar4 = 100;
    uVar2 = 0x19;
    iVar6 = 100;
    iVar5 = 100;
    local_20 = 0;
  }
  else {
    this->m_rgRemapCD[0] = 0;
    if (uVar1 == 1) {
      iVar5 = 99;
      local_20 = 1;
    }
    else {
      this->m_rgRemapCD[1] = 1;
      if (uVar1 == 2) {
        iVar5 = 0x62;
        local_20 = 2;
      }
      else {
        this->m_rgRemapCD[2] = 2;
        iVar5 = 0x61;
        local_20 = 3;
      }
    }
    iVar4 = 0x60;
    iVar6 = 100 - uVar1;
    uVar2 = 0x18;
  }
  iVar8 = local_20 + 1;
  iVar9 = local_20 + 2;
  iVar10 = local_20 + 3;
  piVar3 = this->m_rgRemapCD + uVar1;
  uVar1 = 0;
  iVar7 = local_20;
  do {
    uVar1 = uVar1 + 1;
    *piVar3 = iVar7;
    piVar3[1] = iVar8;
    piVar3[2] = iVar9;
    piVar3[3] = iVar10;
    piVar3 = piVar3 + 4;
    iVar7 = iVar7 + 4;
    iVar8 = iVar8 + 4;
    iVar9 = iVar9 + 4;
    iVar10 = iVar10 + 4;
  } while (uVar1 < uVar2);
  local_20 = local_20 + iVar4;
  if (iVar6 != iVar4) {
    this->m_rgRemapCD[local_20] = local_20;
    if (iVar5 - iVar4 != 1) {
      this->m_rgRemapCD[local_20 + 1] = local_20 + 1;
      if (iVar5 - iVar4 != 2) {
        this->m_rgRemapCD[local_20 + 2] = local_20 + 2;
      }
    }
  }
  (*thread->_vptr_IThread[4])(thread,_GetAudioDiskInfo,0,0,0);
  return;
}


// CCDAudio::_Pause  @ 001bd130
/* DWARF original prototype: void _Pause(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_Pause(CCDAudio *this,int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  
  if ((this->m_bEnabled != false) && (this->m_bIsPlaying != false)) {
    bVar1 = (this->m_MP3).inuse;
    bVar2 = this->m_bIsPlaying;
    if ((bVar1 != false) && (bVar2 = bVar1, MP3stream != (HSTREAM_conflict)0x0)) {
      AIL_pause_stream(MP3stream,1);
      bVar2 = this->m_bIsPlaying;
    }
    this->m_bWasPlaying = bVar2;
    this->m_dPauseTime = realtime;
    this->m_bIsPlaying = false;
    this->m_szPendingPlayFilename[0] = '\0';
  }
  return;
}


// CCDAudio::_Play  @ 001bfa90
/* DWARF original prototype: void _Play(CCDAudio * this, int track, int looping) */

void __thiscall CCDAudio::_Play(CCDAudio *this,int track,int looping)

{
  float fVar1;
  HSTREAM_conflict p_Var2;
  double dVar3;
  bool bVar4;
  bool bVar5;
  
                    /* Unresolved local var: int mins@[???]
                       Unresolved local var: int secs@[???] */
  if (this->m_bEnabled != false) {
    if (track == 0) {
      if (this->m_szPendingPlayFilename[0] == '\0') {
        this->m_szPendingPlayFilename[0] = '\0';
        this->m_bIsCDValid = false;
        this->m_nMaxCDTrack = 0;
      }
      else {
                    /* Unresolved local var: int mins@[???]
                       Unresolved local var: int secs@[???] */
        MP3_PlayTrack(this,this->m_szPendingPlayFilename,looping != 0);
        this->m_szPendingPlayFilename[0] = '\0';
      }
    }
    else {
      this->m_szPendingPlayFilename[0] = '\0';
      this->m_bIsCDValid = false;
      this->m_nMaxCDTrack = 0;
      if (((1 < track) && (track < g_iMP3NumTracks)) &&
         ((bVar5 = looping != 0, this->m_bIsPrimed != false ||
          (bVar4 = MP3_InitStream(this,track,bVar5), bVar4)))) {
        p_Var2 = MP3stream;
        this->m_bIsPrimed = false;
        if (p_Var2 != (HSTREAM_conflict)0x0) {
          AIL_start_stream(p_Var2);
        }
        (this->m_MP3).inuse = true;
        this->m_flPlayTime = 0.0;
        fVar1 = this->m_flMP3Volume;
        (this->m_MP3).playing = true;
        (this->m_MP3).tracknum = track;
        (this->m_MP3).looping = bVar5;
        *(undefined4 *)&this->m_dStartTime = 0;
        *(undefined4 *)((int)&this->m_dStartTime + 4) = 0;
        *(undefined4 *)&this->m_dPauseTime = 0;
        *(undefined4 *)((int)&this->m_dPauseTime + 4) = 0;
        this->m_bIsLooping = bVar5;
        this->m_nPlayTrack = track;
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
  }
  return;
}


// CCDAudio::_PrimeTrack  @ 001bf6c0
/* DWARF original prototype: void _PrimeTrack(CCDAudio * this, int track, int looping) */

void __thiscall CCDAudio::_PrimeTrack(CCDAudio *this,int track,int looping)

{
  char *pcVar1;
  int trackNum;
  char *s1;
  
  this->m_bIsInMiddleOfPriming = true;
  if (track != 0) {
    if ((1 < track) && (track < g_iMP3NumTracks)) {
      MP3_InitStream(this,track,looping != 0);
      this->m_bIsPrimed = true;
    }
    goto LAB_001bf723;
  }
  if (this->m_szPendingPlayFilename[0] == '\0') goto LAB_001bf723;
  s1 = this->m_szPendingPlayFilename;
                    /* Unresolved local var: int iTrackNum@[???] */
  if (s1 != (char *)0x0) {
                    /* Unresolved local var: int iTrackNum@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iTrack@[???] */
    pcVar1 = Q_strstr(s1,":");
    if (pcVar1 == (char *)0x0) {
      pcVar1 = Q_strstr(s1,"..");
      if (pcVar1 != (char *)0x0) goto LAB_001bf70d;
      trackNum = MP3_GetTrack(s1);
    }
    else {
LAB_001bf70d:
      trackNum = 0;
    }
    MP3_InitStream(this,trackNum,looping != 0);
  }
  this->m_bIsPrimed = true;
LAB_001bf723:
  this->m_bIsInMiddleOfPriming = false;
  return;
}


// CCDAudio::_Resume  @ 001bd090
/* DWARF original prototype: void _Resume(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_Resume(CCDAudio *this,int param_1,int param_2)

{
  bool bVar1;
  double dVar2;
  
                    /* Unresolved local var: double curTime@[???] */
  if ((this->m_bEnabled != false) && (this->m_bWasPlaying != false)) {
    if ((this->m_MP3).inuse == false) {
      this->m_bIsPlaying = true;
LAB_001bd0e4:
                    /* Unresolved local var: double curTime@[???] */
      dVar2 = realtime - this->m_dPauseTime;
      *(undefined4 *)&this->m_dPauseTime = 0;
      *(undefined4 *)((int)&this->m_dPauseTime + 4) = 0;
      this->m_dStartTime = dVar2 + this->m_dStartTime;
      return;
    }
    if (MP3stream == (HSTREAM_conflict)0x0) {
      this->m_bIsPlaying = true;
    }
    else {
      AIL_pause_stream(MP3stream,0);
      bVar1 = (this->m_MP3).inuse;
      this->m_bIsPlaying = true;
      if (bVar1 == false) goto LAB_001bd0e4;
    }
  }
  return;
}


// CCDAudio::_Stop  @ 001bd2d0
/* DWARF original prototype: void _Stop(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_Stop(CCDAudio *this,int param_1,int param_2)

{
  float fVar1;
  HSTREAM_conflict p_Var2;
  
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
    (this->m_MP3).volume = fVar1;
    (this->m_MP3).suspended = false;
    (this->m_MP3).playing = false;
    (this->m_MP3).trackname[0] = '\0';
    (this->m_MP3).tracknum = 0;
    (this->m_MP3).looping = false;
    this->m_flPlayTime = 0.0;
    *(undefined4 *)&this->m_dStartTime = 0;
    *(undefined4 *)((int)&this->m_dStartTime + 4) = 0;
    *(undefined4 *)&this->m_dPauseTime = 0;
    *(undefined4 *)((int)&this->m_dPauseTime + 4) = 0;
  }
  return;
}


// CCDAudio::_SwitchToEngine  @ 001bd1a0
/* DWARF original prototype: void _SwitchToEngine(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_SwitchToEngine(CCDAudio *this,int param_1,int param_2)

{
  bool bVar1;
  double dVar2;
  
  if (this->m_bResumeOnSwitch == false) {
    return;
  }
                    /* Unresolved local var: double curTime@[???] */
  this->m_bResumeOnSwitch = false;
  if (this->m_bEnabled == false) {
    return;
  }
  if (this->m_bWasPlaying == false) {
    return;
  }
  if ((this->m_MP3).inuse == false) {
    this->m_bIsPlaying = true;
  }
  else {
    if (MP3stream == (HSTREAM_conflict)0x0) {
      this->m_bIsPlaying = true;
      return;
    }
    AIL_pause_stream(MP3stream,0);
    bVar1 = (this->m_MP3).inuse;
    this->m_bIsPlaying = true;
    if (bVar1 != false) {
      return;
    }
  }
                    /* Unresolved local var: double curTime@[???] */
  dVar2 = realtime - this->m_dPauseTime;
  *(undefined4 *)&this->m_dPauseTime = 0;
  *(undefined4 *)((int)&this->m_dPauseTime + 4) = 0;
  this->m_dStartTime = dVar2 + this->m_dStartTime;
  return;
}


// CCDAudio::_SwitchToLauncher  @ 001bd010
/* DWARF original prototype: void _SwitchToLauncher(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_SwitchToLauncher(CCDAudio *this,int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  
  if ((this->m_bEnabled != false) && (this->m_bIsPlaying != false)) {
    bVar1 = (this->m_MP3).inuse;
    this->m_bResumeOnSwitch = true;
    bVar2 = this->m_bIsPlaying;
    if ((bVar1 != false) && (bVar2 = bVar1, MP3stream != (HSTREAM_conflict)0x0)) {
      AIL_pause_stream(MP3stream,1);
      bVar2 = this->m_bIsPlaying;
    }
    this->m_bWasPlaying = bVar2;
    this->m_dPauseTime = realtime;
    this->m_bIsPlaying = false;
    this->m_szPendingPlayFilename[0] = '\0';
  }
  return;
}


