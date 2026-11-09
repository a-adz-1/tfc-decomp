// CDAudio_Init  @ 001be340
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CDAudio_Init(void)

{
  (*thread->_vptr_IThread[2])(thread);
  return;
}


// CDAudio_Pause  @ 001be400
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CDAudio_Pause(void)

{
  if (cdaudio->_vptr_ICDAudio[4] != CCDAudio::Pause) {
    (*cdaudio->_vptr_ICDAudio[4])(cdaudio);
    return;
  }
  if (*(char *)((int)&cdaudio[8]._vptr_ICDAudio + 3) == '\0') {
    return;
  }
  (*thread->_vptr_IThread[4])(thread,CCDAudio::_Pause,0,0,0);
  return;
}


// CDAudio_Play  @ 001be380
void CDAudio_Play(int track,int looping)

{
  ICDAudio *pIVar1;
  
  pIVar1 = cdaudio;
  if (cdaudio->_vptr_ICDAudio[2] == CCDAudio::Play) {
    cdaudio[6]._vptr_ICDAudio = (_func_int_varargs **)0x0;
    pIVar1[7]._vptr_ICDAudio = (_func_int_varargs **)0x0;
    (*thread->_vptr_IThread[4])(thread,CCDAudio::_Play,0,track,(uint)(looping != 0));
    return;
  }
  (*cdaudio->_vptr_ICDAudio[2])(cdaudio,track,(uint)(looping != 0));
  return;
}


// CDAudio_Resume  @ 001be460
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CDAudio_Resume(void)

{
  if (cdaudio->_vptr_ICDAudio[5] != CCDAudio::Resume) {
    (*cdaudio->_vptr_ICDAudio[5])(cdaudio);
    return;
  }
  if (*(char *)((int)&cdaudio[8]._vptr_ICDAudio + 3) == '\0') {
    return;
  }
  (*thread->_vptr_IThread[4])(thread,CCDAudio::_Resume,0,0,0);
  return;
}


// CDAudio_Shutdown  @ 001be360
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CDAudio_Shutdown(void)

{
  (*thread->_vptr_IThread[3])(thread);
  return;
}


