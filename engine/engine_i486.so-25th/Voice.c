// Voice_Deinit  @ 00079520
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Voice_Deinit(void)

{
  return;
}


// Voice_GetClientListening  @ 000796c0
qboolean Voice_GetClientListening(int iReceiver,int iSender)

{
  int iVar1;
  int iVar2;
  
  iVar1 = iSender + -1;
  iVar2 = iReceiver + -1;
  if (((-1 < iVar2) && (iVar2 < svs.maxclients && -1 < iVar1)) && (iVar1 < svs.maxclients)) {
    return (uint)(svs.clients[iVar1].m_VoiceStreams[iVar2 >> 5] != 0) & 1 << ((byte)iVar2 & 0x1f);
  }
  return false;
}


// Voice_Idle  @ 00079530
void Voice_Idle(float frametime)

{
  return;
}


// Voice_IsRecording  @ 00079500
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Voice_IsRecording(void)

{
  return false;
}


// Voice_RecordStart  @ 000794f0
qboolean Voice_RecordStart(char *pUncompressedFile,char *pDecompressedFile,char *pMicInputFile)

{
  return false;
}


// Voice_RecordStop  @ 00079540
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Voice_RecordStop(void)

{
  return true;
}


// Voice_RegisterCvars  @ 00079510
void Voice_RegisterCvars(void)

{
  return;
}


// Voice_SetClientListening  @ 00079740
qboolean Voice_SetClientListening(int iReceiver,int iSender,qboolean bListen)

{
  int iVar1;
  qboolean qVar2;
  int iVar3;
  uint uVar4;
  
                    /* Unresolved local var: uint32 * pDest@[???] */
  iVar1 = iSender + -1;
  iVar3 = iReceiver + -1;
  if (((iVar3 < 0) || (svs.maxclients <= iVar3 || iVar1 < 0)) || (svs.maxclients <= iVar1)) {
    qVar2 = false;
  }
  else {
    uVar4 = 1 << ((byte)iVar3 & 0x1f);
    if (bListen == false) {
      svs.clients[iVar1].m_VoiceStreams[iVar3 >> 5] =
           svs.clients[iVar1].m_VoiceStreams[iVar3 >> 5] & ~uVar4;
      return true;
    }
    svs.clients[iVar1].m_VoiceStreams[iVar3 >> 5] =
         svs.clients[iVar1].m_VoiceStreams[iVar3 >> 5] | uVar4;
    qVar2 = true;
  }
  return qVar2;
}


