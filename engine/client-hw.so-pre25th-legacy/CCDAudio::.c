// CCDAudio::_CDReset  @ 0020ce50
/* DWARF original prototype: void _CDReset(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_CDReset(CCDAudio *this,int param_1,int param_2)

{
  (*(this->super_ICDAudio)._vptr_ICDAudio[1])(this);
  usleep(1000000);
                    /* WARNING: Could not recover jumptable at 0x0020ce78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(this->super_ICDAudio)._vptr_ICDAudio)();
  return;
}


// CCDAudio::_CDUpdate  @ 0020d5f0
/* DWARF original prototype: void _CDUpdate(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_CDUpdate(CCDAudio *this,int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  HSTREAM_conflict p_Var4;
  undefined4 uVar5;
  int iVar6;
  longdouble lVar7;
  double dVar8;
  
  fVar2 = MP3Volume.value;
                    /* Unresolved local var: double curVolume@[???]
                       Unresolved local var: double current@[???] */
  if (this->m_bIsPlaying != false) {
                    /* Unresolved local var: double curVolume@[???]
                       Unresolved local var: double current@[???] */
    if (this->m_dFadeOutTime != 0.0) {
                    /* Unresolved local var: double currentTime@[???] */
      dVar8 = Sys_FloatTime();
      p_Var4 = MP3stream;
      if ((longdouble)this->m_dFadeOutTime <= (longdouble)dVar8) {
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
      else {
        lVar7 = (((longdouble)this->m_dFadeOutTime - (longdouble)dVar8) /
                (longdouble)MP3FadeTime.value) * (longdouble)MP3Volume.value;
        fVar1 = (this->m_MP3).volume;
      }
      p_Var4 = MP3stream;
      fVar2 = (float)lVar7;
      fVar3 = 0.0;
      if ((0.0 <= fVar2) && (fVar3 = fVar2, 1.0 < fVar2)) {
        fVar3 = 1.0;
      }
      if ((fVar3 != fVar1) && ((this->m_MP3).volume = fVar3, p_Var4 != (HSTREAM_conflict)0x0)) {
        uVar5 = AIL_stream_sample_handle(p_Var4);
        AIL_set_sample_volume_pan(uVar5,fVar3,0x3f000000);
      }
      iVar6 = (*thread->_vptr_IThread[4])(thread,_CDUpdate,0,0,0);
      if ((char)iVar6 != '\0') {
        usleep(100);
      }
    }
    if ((this->m_MP3).inuse != false) {
      iVar6 = AIL_stream_status(MP3stream);
      this->m_bIsPlaying = iVar6 == 4;
      if (iVar6 != 4) {
        this->m_szPendingPlayFilename[0] = '\0';
      }
    }
    if ((((this->m_flPlayTime != 0.0) && ((longdouble)this->m_dStartTime != (longdouble)0)) &&
        (this->m_flPlayTime + 2.0 <= (float)((longdouble)realtime - (longdouble)this->m_dStartTime))
        ) && (this->m_bIsPlaying != false)) {
      this->m_bIsPlaying = false;
      this->m_szPendingPlayFilename[0] = '\0';
      if (this->m_bIsLooping != false) {
                    /* WARNING: Could not recover jumptable at 0x0020d8b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(this->super_ICDAudio)._vptr_ICDAudio[2])();
        return;
      }
    }
  }
  return;
}


// CCDAudio::_CloseDoor  @ 0020cd50
/* DWARF original prototype: void _CloseDoor(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_CloseDoor(CCDAudio *this,int param_1,int param_2)

{
  this->m_flPlayTime = 0.0;
  this->m_dStartTime = 0.0;
  this->m_dPauseTime = 0.0;
  return;
}


// CCDAudio::_Eject  @ 0020cd40
/* DWARF original prototype: void _Eject(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_Eject(CCDAudio *this,int param_1,int param_2)

{
  this->m_flPlayTime = 0.0;
  this->m_dStartTime = 0.0;
  this->m_dPauseTime = 0.0;
  return;
}


// CCDAudio::_GetAudioDiskInfo  @ 0020cd60
/* DWARF original prototype: void _GetAudioDiskInfo(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_GetAudioDiskInfo(CCDAudio *this,int param_1,int param_2)

{
  this->m_bIsCDValid = false;
  this->m_nMaxCDTrack = 0;
  return;
}


// CCDAudio::_Init  @ 0020d0c0
/* DWARF original prototype: void _Init(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_Init(CCDAudio *this,int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar2 = -(((uint)this & 0xf) >> 2) & 3;
  if (uVar2 == 0) {
    iVar4 = 100;
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
                    /* Unresolved local var: int n@[???] */
    do {
      this->m_rgRemapCD[uVar1] = uVar1;
      uVar1 = uVar1 + 1;
      iVar4 = 100 - uVar1;
    } while (uVar1 < uVar2);
  }
  uVar6 = 100 - uVar2 >> 2;
  if (uVar6 != 0) {
    uVar8 = uVar1 + 1;
    uVar9 = uVar1 + 2;
    uVar10 = uVar1 + 3;
    piVar5 = this->m_rgRemapCD + uVar2;
    uVar3 = 0;
    uVar7 = uVar1;
    do {
      uVar3 = uVar3 + 1;
      *piVar5 = uVar7;
      piVar5[1] = uVar8;
      piVar5[2] = uVar9;
      piVar5[3] = uVar10;
      piVar5 = piVar5 + 4;
      uVar7 = uVar7 + 4;
      uVar8 = uVar8 + 4;
      uVar9 = uVar9 + 4;
      uVar10 = uVar10 + 4;
    } while (uVar3 < uVar6);
    uVar1 = uVar1 + uVar6 * 4;
    iVar4 = iVar4 + uVar6 * -4;
    if (100 - uVar2 == uVar6 * 4) goto LAB_0020d1ab;
  }
  do {
    this->m_rgRemapCD[uVar1] = uVar1;
    uVar1 = uVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
LAB_0020d1ab:
  (*thread->_vptr_IThread[4])(thread,_GetAudioDiskInfo,0,0,0);
  return;
}


// CCDAudio::_Pause  @ 0020cfd0
/* DWARF original prototype: void _Pause(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_Pause(CCDAudio *this,int param_1,int param_2)

{
  bool bVar1;
  
  if ((this->m_bEnabled != false) && (this->m_bIsPlaying != false)) {
    bVar1 = true;
    if (((this->m_MP3).inuse != false) && (MP3stream != (HSTREAM_conflict)0x0)) {
      AIL_pause_stream(MP3stream,1);
      bVar1 = this->m_bIsPlaying;
    }
    this->m_bWasPlaying = bVar1;
    this->m_dPauseTime = realtime;
    this->m_bIsPlaying = false;
    this->m_szPendingPlayFilename[0] = '\0';
  }
  return;
}


// CCDAudio::_Play  @ 0020fb70
/* DWARF original prototype: void _Play(CCDAudio * this, int track, int looping) */

void __thiscall CCDAudio::_Play(CCDAudio *this,int track,int looping)

{
                    /* Unresolved local var: int mins@[???]
                       Unresolved local var: int secs@[???] */
  if (this->m_bEnabled != false) {
    if ((track != 0) || (this->m_szPendingPlayFilename[0] == '\0')) {
      this->m_szPendingPlayFilename[0] = '\0';
      this->m_bIsCDValid = false;
      this->m_nMaxCDTrack = 0;
      MP3_PlayTrack(this,track,looping != 0);
      return;
    }
    MP3_PlayTrack(this,this->m_szPendingPlayFilename,looping != 0);
    this->m_szPendingPlayFilename[0] = '\0';
  }
  return;
}


// CCDAudio::_PrimeTrack  @ 0020fbf0
/* DWARF original prototype: void _PrimeTrack(CCDAudio * this, int track, int looping) */

void __thiscall CCDAudio::_PrimeTrack(CCDAudio *this,int track,int looping)

{
  char *s1;
  char *pcVar1;
  int trackNum;
  
  this->m_bIsInMiddleOfPriming = true;
  if (track != 0) {
    if ((1 < track) && (track < g_iMP3NumTracks)) {
      MP3_InitStream(this,track,looping != 0);
      this->m_bIsPrimed = true;
    }
    goto LAB_0020fc19;
  }
  if (this->m_szPendingPlayFilename[0] == '\0') goto LAB_0020fc19;
                    /* Unresolved local var: int iTrackNum@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iTrack@[???] */
  s1 = this->m_szPendingPlayFilename;
  pcVar1 = Q_strstr(s1,":");
  if (pcVar1 == (char *)0x0) {
    pcVar1 = Q_strstr(s1,"..");
    if (pcVar1 != (char *)0x0) goto LAB_0020fc80;
    trackNum = MP3_GetTrack(s1);
  }
  else {
LAB_0020fc80:
    trackNum = 0;
  }
  MP3_InitStream(this,trackNum,looping != 0);
  this->m_bIsPrimed = true;
LAB_0020fc19:
  this->m_bIsInMiddleOfPriming = false;
  return;
}


// CCDAudio::_Resume  @ 0020d040
/* DWARF original prototype: void _Resume(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_Resume(CCDAudio *this,int param_1,int param_2)

{
  bool bVar1;
  double dVar2;
  
                    /* Unresolved local var: double curTime@[???] */
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


// CCDAudio::_Stop  @ 0020d270
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
    (this->m_MP3).tracknum = 0;
    fVar1 = this->m_flMP3Volume;
    this->m_bIsPrimed = false;
    (this->m_MP3).inuse = false;
    (this->m_MP3).suspended = false;
    (this->m_MP3).playing = false;
    (this->m_MP3).trackname[0] = '\0';
    (this->m_MP3).looping = false;
    (this->m_MP3).volume = fVar1;
    this->m_flPlayTime = 0.0;
    *(undefined4 *)&this->m_dStartTime = 0;
    *(undefined4 *)((int)&this->m_dStartTime + 4) = 0;
    *(undefined4 *)&this->m_dPauseTime = 0;
    *(undefined4 *)((int)&this->m_dPauseTime + 4) = 0;
  }
  return;
}


// CCDAudio::_SwitchToEngine  @ 0020d330
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


// CCDAudio::_SwitchToLauncher  @ 0020d3d0
/* DWARF original prototype: void _SwitchToLauncher(CCDAudio * this, int param_1, int param_2) */

void __thiscall CCDAudio::_SwitchToLauncher(CCDAudio *this,int param_1,int param_2)

{
  bool bVar1;
  double dVar2;
  bool bVar3;
  
  if ((this->m_bEnabled != false) && (this->m_bIsPlaying != false)) {
    bVar1 = (this->m_MP3).inuse;
    bVar3 = true;
    this->m_bResumeOnSwitch = true;
    if ((bVar1 != false) && (MP3stream != (HSTREAM_conflict)0x0)) {
      AIL_pause_stream(MP3stream,1);
      bVar3 = this->m_bIsPlaying;
    }
    dVar2 = realtime;
    this->m_bWasPlaying = bVar3;
    this->m_dPauseTime = dVar2;
    this->m_bIsPlaying = false;
    this->m_szPendingPlayFilename[0] = '\0';
  }
  return;
}


