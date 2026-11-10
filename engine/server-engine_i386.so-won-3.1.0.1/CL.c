// CL_AdjustClock  @ 00092114
void CL_AdjustClock(void)

{
  return;
}


// CL_CheckClientState  @ 000921a8
void CL_CheckClientState(void)

{
  return;
}


// CL_CheckFile  @ 00092080
void CL_CheckFile(void)

{
  return;
}


// CL_CheckForResend  @ 00092078
void CL_CheckForResend(void)

{
  return;
}


// CL_ClearClientState  @ 00092088
void CL_ClearClientState(void)

{
  return;
}


// CL_Connect_f  @ 00092090
void CL_Connect_f(void)

{
  return;
}


// CL_DecayLights  @ 00092098
void CL_DecayLights(void)

{
  return;
}


// CL_Disconnect  @ 000920a0
void CL_Disconnect(void)

{
  return;
}


// CL_Disconnect_f  @ 000920a8
void CL_Disconnect_f(void)

{
  return;
}


// CL_EmitEntities  @ 000920b0
void CL_EmitEntities(void)

{
  return;
}


// CL_Init  @ 000920c0
void CL_Init(void)

{
  return;
}


// CL_InitClosest  @ 000920b8
void CL_InitClosest(void)

{
  return;
}


// CL_InitEventSystem  @ 000921a0
void CL_InitEventSystem(void)

{
  return;
}


// CL_Move  @ 000920f4
void CL_Move(void)

{
  return;
}


// CL_ParseAuthenticationMessage  @ 0008a79c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CL_ParseAuthenticationMessage(char param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int aiStack_24 [4];
  char *pcStack_14;
  
  pcStack_14 = (char *)0x8a7a7;
  if (param_1 == '4') {
    pcStack_14 = "S2C_AUTHCHALLENGE1\n";
    aiStack_24[3] = 0x8a7d8;
    Con_DPrintf();
    if (DAT_00205ae4 != 0x34) {
      DAT_00205ae4 = 0x34;
    }
    aiStack_24[3] = DAT_00226fec + -5;
    aiStack_24[2] = DAT_00226fe4 + 5;
    aiStack_24[1] = 0x8a808;
    pcStack_14 = (char *)&clauthstate;
    iVar2 = (*_DAT_003861c8)();
    if (iVar2 == 2) {
      DAT_00205ad8 = realtime;
      DAT_00205ae0 = 3;
      DAT_00205ae4 = 0x36;
      return;
    }
    if (iVar2 != 1) {
      pcStack_14 = "S2C_AUTHCHALLENGE1:  Unable to parse Auth challenge 1.\n";
LAB_0008a8d2:
      aiStack_24[3] = 0x8a8d8;
      Con_DPrintf();
      goto LAB_0008a8db;
    }
    pcStack_14 = "Server challenge 1 invalid\n";
  }
  else {
    if (param_1 != '6') goto LAB_0008a8db;
    pcStack_14 = "S2C_AUTHCOMPLETE\n";
    aiStack_24[3] = 0x8a858;
    Con_DPrintf();
    if (DAT_00205ae4 != 0x36) {
      pcStack_14 = "S2C_AUTHCOMPLETE out of sequence\n";
      aiStack_24[3] = 0x8a86d;
      Con_DPrintf();
      return;
    }
    aiStack_24[3] = DAT_00226fec + -5;
    aiStack_24[2] = DAT_00226fe4 + 5;
    aiStack_24[1] = 0x8a894;
    pcStack_14 = (char *)&clauthstate;
    iVar2 = (*_DAT_003861d0)();
    if (iVar2 == 2) {
      DAT_00205ad8 = realtime;
      DAT_00205ae0 = 3;
      DAT_00205ae4 = 0x37;
      return;
    }
    if (iVar2 != 1) {
      pcStack_14 = "S2C_AUTHCOMPLETE:  Unable to parse Auth complete.\n";
      goto LAB_0008a8d2;
    }
    pcStack_14 = "Server auth complete invalid\n";
  }
  aiStack_24[3] = 0x8a8c9;
  Con_Printf();
LAB_0008a8db:
  puVar3 = &net_from;
  piVar4 = aiStack_24;
  for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    piVar4 = piVar4 + 1;
  }
  uVar1 = NET_AdrToString();
  Con_Printf("Authentication failure on %s\n",uVar1);
  return;
}


// CL_Particle  @ 000920c8
void CL_Particle(void)

{
  return;
}


// CL_PredictMove  @ 000920d0
void CL_PredictMove(void)

{
  return;
}


// CL_PrintLogos  @ 000920d8
void CL_PrintLogos(void)

{
  return;
}


// CL_ReadPackets  @ 000920e0
void CL_ReadPackets(void)

{
  return;
}


// CL_RecordHUDCommand  @ 00092068
void CL_RecordHUDCommand(void)

{
  return;
}


// CL_RedoPrediction  @ 000921b0
void CL_RedoPrediction(void)

{
  return;
}


// CL_RequestMissingResources  @ 000920e8
undefined4 CL_RequestMissingResources(void)

{
  return 0;
}


// CL_Save  @ 0005a440
void CL_Save(void)

{
  return;
}


// CL_SendConnectPacket  @ 000920fc
void CL_SendConnectPacket(void)

{
  return;
}


// CL_SetLastUpdate  @ 000921b8
void CL_SetLastUpdate(void)

{
  return;
}


// CL_ShutDownClientStatic  @ 00092178
void CL_ShutDownClientStatic(void)

{
  return;
}


// CL_ShutDownUsrMessages  @ 00092170
void CL_ShutDownUsrMessages(void)

{
  return;
}


// CL_Shutdown  @ 00092188
void CL_Shutdown(void)

{
  return;
}


// CL_StartAuthentication  @ 0008ad54
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CL_StartAuthentication(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  WON_RemoveUser(&clauthstate);
  puVar2 = &clauthstate;
  DAT_00205aec = 0;
  DAT_00205ae8 = 0;
  DAT_00205ae4 = 0x34;
  DAT_00205ad8 = realtime;
  DAT_00205ae0 = 3;
  for (iVar1 = 5; puVar2 = puVar2 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
  }
  clauthstate = 1;
  iVar1 = (*_DAT_003861c0)(0,0,&clauthstate);
  if ((iVar1 != 2) && (iVar1 != 0)) {
    Con_Printf("Error constructing authentication request\n");
  }
  return;
}


// CL_StopPlayback  @ 00092104
void CL_StopPlayback(void)

{
  return;
}


// CL_UpdateSoundFade  @ 0009210c
void CL_UpdateSoundFade(void)

{
  return;
}


