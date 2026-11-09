// Voice_Deinit  @ 00095610
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Voice_Deinit(void)

{
  return;
}


// Voice_GetClientListening  @ 00095800
qboolean Voice_GetClientListening(int iReceiver,int iSender)

{
  qboolean qVar1;
  int iVar2;
  int iVar3;
  
  qVar1 = false;
  iVar2 = iReceiver + -1;
  if (-1 < iVar2) {
    iVar3 = iSender + -1;
    if ((iVar3 < 0) || (svs.maxclients <= iVar2)) {
      return false;
    }
    if (iVar3 < svs.maxclients) {
      qVar1 = (uint)(svs.clients[iVar3].m_VoiceStreams[iVar2 >> 5] != 0) & 1 << ((byte)iVar2 & 0x1f)
      ;
    }
  }
  return qVar1;
}


// Voice_Idle  @ 00095620
void Voice_Idle(float frametime)

{
  return;
}


// Voice_IsRecording  @ 000955f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Voice_IsRecording(void)

{
  return false;
}


// Voice_RecordStart  @ 000955e0
qboolean Voice_RecordStart(char *pUncompressedFile,char *pDecompressedFile,char *pMicInputFile)

{
  return false;
}


// Voice_RecordStop  @ 00095630
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Voice_RecordStop(void)

{
  return true;
}


// Voice_RegisterCvars  @ 00095600
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Voice_RegisterCvars(void)

{
  return;
}


// Voice_SetClientListening  @ 00095880
qboolean Voice_SetClientListening(int iReceiver,int iSender,qboolean bListen)

{
  qboolean qVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
                    /* Unresolved local var: uint32 * pDest@[???] */
  qVar1 = false;
  iVar2 = iReceiver + -1;
  if (-1 < iVar2) {
    iVar4 = iSender + -1;
    if ((iVar4 < 0) || (svs.maxclients <= iVar2)) {
      return false;
    }
    if (iVar4 < svs.maxclients) {
      uVar3 = 1 << ((byte)iVar2 & 0x1f);
      if (bListen != false) {
        svs.clients[iVar4].m_VoiceStreams[iVar2 >> 5] =
             svs.clients[iVar4].m_VoiceStreams[iVar2 >> 5] | uVar3;
        return true;
      }
      svs.clients[iVar4].m_VoiceStreams[iVar2 >> 5] =
           svs.clients[iVar4].m_VoiceStreams[iVar2 >> 5] & ~uVar3;
      qVar1 = true;
    }
  }
  return qVar1;
}


