// CL_AddVoiceToDatagram  @ 00045550
void CL_AddVoiceToDatagram(qboolean bFinal)

{
  return;
}


// CL_AdjustClock  @ 000453f0
void CL_AdjustClock(void)

{
  return;
}


// CL_CheckClientState  @ 000454f0
void CL_CheckClientState(void)

{
  return;
}


// CL_CheckFile  @ 000452d0
qboolean CL_CheckFile(sizebuf_t *msg,char *filename)

{
  return true;
}


// CL_CheckForResend  @ 000452c0
void CL_CheckForResend(void)

{
  return;
}


// CL_ClearClientState  @ 000452e0
void CL_ClearClientState(void)

{
  return;
}


// CL_Connect_f  @ 000452f0
void CL_Connect_f(void)

{
  return;
}


// CL_DecayLights  @ 00045300
void CL_DecayLights(void)

{
  return;
}


// CL_Disconnect  @ 00045310
void CL_Disconnect(void)

{
  return;
}


// CL_Disconnect_f  @ 00045320
void CL_Disconnect_f(void)

{
  return;
}


// CL_EmitEntities  @ 00045330
void CL_EmitEntities(void)

{
  return;
}


// CL_HTTPUpdate  @ 000b9c90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_HTTPUpdate(void)

{
  return;
}


// CL_Init  @ 00045350
void CL_Init(void)

{
  return;
}


// CL_InitClosest  @ 00045340
void CL_InitClosest(void)

{
  return;
}


// CL_InitEventSystem  @ 000454e0
void CL_InitEventSystem(void)

{
  return;
}


// CL_KeepConnectionActive  @ 00045580
void CL_KeepConnectionActive(void)

{
  return;
}


// CL_MapLocalizationString  @ 00059500
char * CL_MapLocalizationString(char *pszBSPName)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar2 = 0;
  do {
    iVar1 = Q_strlen(gTitleComments[iVar2].pBSPName);
    iVar1 = Q_strnicmp(pszBSPName,gTitleComments[iVar2].pBSPName,iVar1);
    if (iVar1 == 0) {
      return gTitleComments[iVar2].pTitleName;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x54);
  return pszBSPName;
}


// CL_Move  @ 000453b0
void CL_Move(void)

{
  return;
}


// CL_MoveSpectatorCamera  @ 00045540
void CL_MoveSpectatorCamera(void)

{
  return;
}


// CL_Particle  @ 00045360
void CL_Particle(vec_t *origin,int color,float life,int zpos,int zvel)

{
  return;
}


// CL_PredictMove  @ 00045370
void CL_PredictMove(void)

{
  return;
}


// CL_PrintLogos  @ 00045380
void CL_PrintLogos(void)

{
  return;
}


// CL_ReadPackets  @ 00045390
void CL_ReadPackets(void)

{
  return;
}


// CL_RecordHUDCommand  @ 000452a0
void CL_RecordHUDCommand(void)

{
  return;
}


// CL_RedoPrediction  @ 00045500
void CL_RedoPrediction(void)

{
  return;
}


// CL_RequestMissingResources  @ 000453a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean CL_RequestMissingResources(void)

{
  return false;
}


// CL_Save  @ 00059c70
void CL_Save(char *name)

{
  return;
}


// CL_SendConnectPacket  @ 000453c0
void CL_SendConnectPacket(void)

{
  return;
}


// CL_SetLastUpdate  @ 00045510
void CL_SetLastUpdate(void)

{
  return;
}


// CL_ShutDownClientStatic  @ 00045490
void CL_ShutDownClientStatic(void)

{
  return;
}


// CL_ShutDownUsrMessages  @ 00045480
void CL_ShutDownUsrMessages(void)

{
  return;
}


// CL_Shutdown  @ 000454b0
void CL_Shutdown(void)

{
  return;
}


// CL_StopPlayback  @ 000453d0
void CL_StopPlayback(void)

{
  return;
}


// CL_UpdateModuleC  @ 00045590
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_UpdateModuleC(void)

{
  return;
}


// CL_UpdateSoundFade  @ 000453e0
void CL_UpdateSoundFade(void)

{
  return;
}


// CL_VoiceIdle  @ 00045560
void CL_VoiceIdle(void)

{
  return;
}


// CL_WriteMessageHistory  @ 00045530
void CL_WriteMessageHistory(int starting_count,int cmd)

{
  return;
}


