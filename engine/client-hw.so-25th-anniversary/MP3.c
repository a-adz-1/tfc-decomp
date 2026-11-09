// MP3_Command_f  @ 001bdb30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void MP3_Command_f(void)

{
  int iVar1;
  char *__s1;
  char *s1;
  char *pcVar2;
  
                    /* Unresolved local var: char * pszCommand@[???]
                       Unresolved local var: char * pszTrack@[???] */
  iVar1 = Cmd_Argc();
  if (iVar1 < 2) {
    return;
  }
  __s1 = Cmd_Argv(1);
  s1 = Cmd_Argv(2);
  iVar1 = strcasecmp(__s1,"play");
  if (iVar1 == 0) {
    (*thread->_vptr_IThread[4])(thread,CCDAudio::_Stop,0,0,0);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iTrack@[???] */
    if (((s1 == (char *)0x0) || (pcVar2 = Q_strstr(s1,":"), pcVar2 != (char *)0x0)) ||
       (pcVar2 = Q_strstr(s1,".."), pcVar2 != (char *)0x0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = MP3_GetTrack(s1);
    }
    g_CDAudio.m_dFadeOutTime._0_4_ = 0;
    g_CDAudio.m_dFadeOutTime._4_4_ = 0;
    (*thread->_vptr_IThread[4])(thread,CCDAudio::_Play,0,iVar1,0);
  }
  iVar1 = strcasecmp(__s1,"playfile");
  if (iVar1 == 0) {
    (*thread->_vptr_IThread[4])(thread,CCDAudio::_Stop,0,0,0);
    g_CDAudio.m_dFadeOutTime._0_4_ = 0;
    g_CDAudio.m_dFadeOutTime._4_4_ = 0;
    strncpy(g_CDAudio.m_szPendingPlayFilename,s1,0x200);
    (*thread->_vptr_IThread[4])(thread,CCDAudio::_Play,0,0,0);
    usleep(0);
  }
  iVar1 = strcasecmp(__s1,"loop");
  if (iVar1 == 0) {
    (*thread->_vptr_IThread[4])(thread,CCDAudio::_Stop,0,0,0);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iTrack@[???] */
    if (((s1 == (char *)0x0) || (pcVar2 = Q_strstr(s1,":"), pcVar2 != (char *)0x0)) ||
       (pcVar2 = Q_strstr(s1,".."), pcVar2 != (char *)0x0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = MP3_GetTrack(s1);
    }
    g_CDAudio.m_dFadeOutTime._0_4_ = 0;
    g_CDAudio.m_dFadeOutTime._4_4_ = 0;
    (*thread->_vptr_IThread[4])(thread,CCDAudio::_Play,0,iVar1,1);
  }
  iVar1 = strcasecmp(__s1,"loopfile");
  if (iVar1 == 0) {
    (*thread->_vptr_IThread[4])(thread,CCDAudio::_Stop,0,0,0);
    g_CDAudio.m_dFadeOutTime._0_4_ = 0;
    g_CDAudio.m_dFadeOutTime._4_4_ = 0;
    strncpy(g_CDAudio.m_szPendingPlayFilename,s1,0x200);
    (*thread->_vptr_IThread[4])(thread,CCDAudio::_Play,0,0,1);
    usleep(0);
  }
  iVar1 = strcasecmp(__s1,"stop");
  if (iVar1 != 0) {
    return;
  }
  (*thread->_vptr_IThread[4])(thread,CCDAudio::_Stop,0,0,0);
  return;
}


// MP3_GetTrack  @ 001bcf20
int __regparm3 MP3_GetTrack(char *pszTrack)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int in_GS_OFFSET;
  char local_1010 [4095];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iTrack@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: char * pszFormat@[???]
                       Unresolved local var: char[4096] szTemp@[???] */
  pcVar1 = Q_strstr(pszTrack,".mp3");
  pcVar2 = "%s";
  if (pcVar1 == (char *)0x0) {
    pcVar2 = "%s.mp3";
  }
  iVar4 = 0;
  __snprintf_chk(local_1010,0xfff,1,0x1000,pcVar2,pszTrack);
  local_11 = 0;
  COM_FixSlashes(local_1010);
  do {
    if (g_pszMP3trackFileMap[iVar4] == (char *)0x0) {
      pcVar1 = Mem_Strdup(local_1010);
      g_pszMP3trackFileMap[iVar4] = pcVar1;
      g_iMP3NumTracks = iVar4 + 1;
      goto LAB_001bcfdb;
    }
    iVar3 = strcmp(g_pszMP3trackFileMap[iVar4],local_1010);
    if (iVar3 == 0) goto LAB_001bcfdb;
    iVar4 = iVar4 + 1;
  } while (iVar4 != 200);
  iVar4 = 0;
LAB_001bcfdb:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// MP3_GetTrack  @ 001bdae0
int MP3_GetTrack(char *pszTrack)

{
  char *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iTrack@[???] */
  if (pszTrack != (char *)0x0) {
    pcVar1 = Q_strstr(pszTrack,":");
    if (pcVar1 == (char *)0x0) {
      pcVar1 = Q_strstr(pszTrack,"..");
      if (pcVar1 == (char *)0x0) {
        iVar2 = MP3_GetTrack(pszTrack);
        return iVar2;
      }
    }
  }
  return 0;
}


// MP3_Resume_Audio  @ 001bfc10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void MP3_Resume_Audio(void)

{
  _func_int_varargs **pp_Var1;
  bool looping;
  _func_int_varargs **trackNum;
  ICDAudio *this;
  HSTREAM_conflict p_Var2;
  bool bVar3;
  char cVar4;
  
  this = cdaudio;
  if (cdaudio->_vptr_ICDAudio[7] == CCDAudio::MP3_Resume_Audio) {
    CCDAudio::MP3_Init((CCDAudio *)cdaudio);
    if ((*(char *)((int)&this[0xf4]._vptr_ICDAudio + 2) != '\0') &&
       (*(char *)((int)&this[0xf4]._vptr_ICDAudio + 1) != '\0')) {
      trackNum = this[0x175]._vptr_ICDAudio;
      if (trackNum == (_func_int_varargs **)0x0) {
        CCDAudio::MP3_PlayTrack
                  ((CCDAudio *)this,(char *)((int)&this[0xf4]._vptr_ICDAudio + 3),
                   *(bool *)&this[0x176]._vptr_ICDAudio);
      }
      else if (((1 < (int)trackNum) && ((int)trackNum < g_iMP3NumTracks)) &&
              ((looping = *(bool *)&this[0x176]._vptr_ICDAudio,
               *(char *)((int)&this[9]._vptr_ICDAudio + 2) != '\0' ||
               (bVar3 = CCDAudio::MP3_InitStream((CCDAudio *)this,(int)trackNum,looping), bVar3))))
      {
        p_Var2 = MP3stream;
        *(undefined1 *)((int)&this[9]._vptr_ICDAudio + 2) = 0;
        if (p_Var2 != (HSTREAM_conflict)0x0) {
          AIL_start_stream(p_Var2);
        }
        *(undefined1 *)&this[0xf4]._vptr_ICDAudio = 1;
        this[1]._vptr_ICDAudio = (_func_int_varargs **)0x0;
        pp_Var1 = this[0xb]._vptr_ICDAudio;
        *(undefined1 *)((int)&this[0xf4]._vptr_ICDAudio + 2) = 1;
        this[0x175]._vptr_ICDAudio = trackNum;
        *(bool *)&this[0x176]._vptr_ICDAudio = looping;
        this[2]._vptr_ICDAudio = (_func_int_varargs **)0x0;
        this[3]._vptr_ICDAudio = (_func_int_varargs **)0x0;
        this[4]._vptr_ICDAudio = (_func_int_varargs **)0x0;
        this[5]._vptr_ICDAudio = (_func_int_varargs **)0x0;
        *(bool *)((int)&this[9]._vptr_ICDAudio + 1) = looping;
        this[0xc]._vptr_ICDAudio = trackNum;
        *(undefined1 *)((int)&this[8]._vptr_ICDAudio + 1) = 1;
        if (((float)pp_Var1 == 0.0) && (cVar4 = *(char *)&this[9]._vptr_ICDAudio, cVar4 != '\0')) {
          if (MP3stream != (HSTREAM_conflict)0x0) {
            AIL_pause_stream(MP3stream,1);
            cVar4 = *(char *)((int)&this[8]._vptr_ICDAudio + 1);
          }
          *(char *)((int)&this[8]._vptr_ICDAudio + 2) = cVar4;
          *(double *)(this + 4) = realtime;
          *(undefined1 *)((int)&this[8]._vptr_ICDAudio + 1) = 0;
          *(undefined1 *)&this[0xd]._vptr_ICDAudio = 0;
        }
      }
    }
    return;
  }
  (*cdaudio->_vptr_ICDAudio[7])();
  return;
}


// MP3_Suspend_Audio  @ 001be4c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void MP3_Suspend_Audio(void)

{
  char cVar1;
  ICDAudio *pIVar2;
  HSTREAM_conflict p_Var3;
  HDIGDRIVER_conflict p_Var4;
  
  pIVar2 = cdaudio;
  if (cdaudio->_vptr_ICDAudio[8] != CCDAudio::MP3_Suspend_Audio) {
    (*cdaudio->_vptr_ICDAudio[8])(cdaudio);
    return;
  }
  cVar1 = *(char *)((int)&cdaudio[8]._vptr_ICDAudio + 1);
  *(char *)((int)&cdaudio[0xf4]._vptr_ICDAudio + 2) = cVar1;
  p_Var3 = MP3stream;
  if (cVar1 == '\0') {
    if (MP3stream == (HSTREAM_conflict)0x0) goto LAB_001be513;
  }
  else {
    if (MP3stream == (HSTREAM_conflict)0x0) goto LAB_001be513;
    *(undefined1 *)((int)&pIVar2[0xf4]._vptr_ICDAudio + 1) = 1;
  }
  AIL_pause_stream(p_Var3,1);
  AIL_close_stream(MP3stream);
  MP3stream = (HSTREAM_conflict)0x0;
LAB_001be513:
  p_Var4 = MP3digitalDriver;
  *(undefined1 *)((int)&pIVar2[9]._vptr_ICDAudio + 2) = 0;
  if (p_Var4 != (HDIGDRIVER_conflict)0x0) {
    AIL_close_digital_driver(p_Var4);
    MP3digitalDriver = (HDIGDRIVER_conflict)0x0;
  }
  return;
}


