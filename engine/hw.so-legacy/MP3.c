// MP3_Command_f  @ 0020da30
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
    iVar1 = 0;
    if (s1 != (char *)0x0) {
      pcVar2 = Q_strstr(s1,":");
      if ((pcVar2 == (char *)0x0) && (pcVar2 = Q_strstr(s1,".."), pcVar2 == (char *)0x0)) {
        iVar1 = MP3_GetTrack(s1);
      }
      else {
        iVar1 = 0;
      }
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
    iVar1 = 0;
    if (s1 != (char *)0x0) {
      pcVar2 = Q_strstr(s1,":");
      if ((pcVar2 == (char *)0x0) && (pcVar2 = Q_strstr(s1,".."), pcVar2 == (char *)0x0)) {
        iVar1 = MP3_GetTrack(s1);
      }
      else {
        iVar1 = 0;
      }
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


// MP3_GetTrack  @ 0020cf10
int __regparm3 MP3_GetTrack(char *pszTrack)

{
  char *pcVar1;
  int iVar2;
  char *__format;
  int iVar3;
  char local_100c [4095];
  undefined1 local_d;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iTrack@[???]
                       Unresolved local var: char * pszFormat@[???]
                       Unresolved local var: char[4096] szTemp@[???] */
  pcVar1 = Q_strstr(pszTrack,".mp3");
  __format = "%s";
  if (pcVar1 == (char *)0x0) {
    __format = "%s.mp3";
  }
  iVar3 = 0;
  snprintf(local_100c,0xfff,__format,pszTrack);
  local_d = 0;
  COM_FixSlashes(local_100c);
  while( true ) {
    if (g_pszMP3trackFileMap[iVar3] == (char *)0x0) {
      pcVar1 = Mem_Strdup(local_100c);
      g_pszMP3trackFileMap[iVar3] = pcVar1;
      g_iMP3NumTracks = iVar3 + 1;
      return iVar3;
    }
    iVar2 = strcmp(g_pszMP3trackFileMap[iVar3],local_100c);
    if (iVar2 == 0) break;
    iVar3 = iVar3 + 1;
    if (iVar3 == 200) {
      return 0;
    }
  }
  return iVar3;
}


// MP3_GetTrack  @ 0020d9e0
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


// MP3_Resume_Audio  @ 0020e320
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void MP3_Resume_Audio(void)

{
  (*cdaudio->_vptr_ICDAudio[7])(cdaudio);
  return;
}


// MP3_Suspend_Audio  @ 0020e340
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void MP3_Suspend_Audio(void)

{
  (*cdaudio->_vptr_ICDAudio[8])(cdaudio);
  return;
}


