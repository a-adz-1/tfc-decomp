// CDAudio_Init  @ 0020e270
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CDAudio_Init(void)

{
  (*thread->_vptr_IThread[2])(thread);
  return;
}


// CDAudio_Pause  @ 0020e2e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CDAudio_Pause(void)

{
  (*cdaudio->_vptr_ICDAudio[4])(cdaudio);
  return;
}


// CDAudio_Play  @ 0020e2b0
void CDAudio_Play(int track,int looping)

{
  (*cdaudio->_vptr_ICDAudio[2])(cdaudio,track,(uint)(looping != 0));
  return;
}


// CDAudio_Resume  @ 0020e300
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CDAudio_Resume(void)

{
  (*cdaudio->_vptr_ICDAudio[5])(cdaudio);
  return;
}


// CDAudio_Shutdown  @ 0020e290
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CDAudio_Shutdown(void)

{
  (*thread->_vptr_IThread[3])(thread);
  return;
}


