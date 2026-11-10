// CL_AddVoiceToDatagram  @ 0005f280
void CL_AddVoiceToDatagram(void)

{
  return;
}


// CL_AdjustClock  @ 0005f1cc
void CL_AdjustClock(void)

{
  return;
}


// CL_CheckClientState  @ 0005f250
void CL_CheckClientState(void)

{
  return;
}


// CL_CheckFile  @ 0005f138
void CL_CheckFile(void)

{
  return;
}


// CL_CheckForResend  @ 0005f130
void CL_CheckForResend(void)

{
  return;
}


// CL_ClearClientState  @ 0005f140
void CL_ClearClientState(void)

{
  return;
}


// CL_Connect_f  @ 0005f148
void CL_Connect_f(void)

{
  return;
}


// CL_DecayLights  @ 0005f150
void CL_DecayLights(void)

{
  return;
}


// CL_DemoPlaySound__13EngineWrapperiPcffii  @ 00097ae0
undefined4 CL_DemoPlaySound__13EngineWrapperiPcffii(undefined4 param_1)

{
  return param_1;
}


// CL_Disconnect  @ 0005f158
void CL_Disconnect(void)

{
  return;
}


// CL_Disconnect_f  @ 0005f160
void CL_Disconnect_f(void)

{
  return;
}


// CL_EmitEntities  @ 0005f168
void CL_EmitEntities(void)

{
  return;
}


// CL_Init  @ 0005f178
void CL_Init(void)

{
  return;
}


// CL_InitClosest  @ 0005f170
void CL_InitClosest(void)

{
  return;
}


// CL_InitEventSystem  @ 0005f248
void CL_InitEventSystem(void)

{
  return;
}


// CL_KeepConnectionActive  @ 0005f298
void CL_KeepConnectionActive(void)

{
  return;
}


// CL_Move  @ 0005f1ac
void CL_Move(void)

{
  return;
}


// CL_MoveSpectatorCamera  @ 0005f278
void CL_MoveSpectatorCamera(void)

{
  return;
}


// CL_ParseAuthenticationMessage  @ 000ca000
void CL_ParseAuthenticationMessage(char param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStack_54 [5];
  undefined4 uStack_40;
  char *pcStack_3c;
  int iStack_38;
  undefined4 *puStack_34;
  undefined4 uStack_30;
  
  uStack_30 = 0xca00e;
  if ((crypt._40_4_ == 0) || (crypt._48_4_ == 0)) {
    pcStack_3c = "Cyrpt interface not initialized\n";
    uStack_40 = 0xca049;
    Con_DPrintf();
    return;
  }
  if (param_1 == '4') {
    pcStack_3c = "S2C_AUTHCHALLENGE1\n";
    uStack_40 = 0xca089;
    Con_DPrintf();
    if (DAT_0059f704 != 0x34) {
      DAT_0059f704 = 0x34;
    }
    iStack_38 = DAT_0059d8d0 + -5;
    pcStack_3c = (char *)(DAT_0059d8c8 + 5);
    uStack_40 = 0xca0cb;
    puStack_34 = &clauthstate;
    iVar1 = (*(code *)crypt._40_4_)();
    if (iVar1 == 2) {
      DAT_0059f6f8 = realtime;
      DAT_0059f700 = 3;
      DAT_0059f704 = 0x36;
      return;
    }
    if (iVar1 == 1) {
      pcStack_3c = "Server challenge 1 invalid\n";
      uStack_40 = 0xca11b;
      Con_Printf();
    }
    else {
      pcStack_3c = "S2C_AUTHCHALLENGE1:  Unable to parse Auth challenge 1.\n";
      uStack_40 = 0xca131;
      Con_DPrintf();
    }
  }
  else if (param_1 == '6') {
    pcStack_3c = "S2C_AUTHCOMPLETE\n";
    uStack_40 = 0xca14d;
    Con_DPrintf();
    if (DAT_0059f704 != 0x36) {
      pcStack_3c = "S2C_AUTHCOMPLETE out of sequence\n";
      uStack_40 = 0xca16a;
      Con_DPrintf();
      return;
    }
    iStack_38 = DAT_0059d8d0 + -5;
    pcStack_3c = (char *)(DAT_0059d8c8 + 5);
    uStack_40 = 0xca1a0;
    puStack_34 = &clauthstate;
    iVar1 = (*(code *)crypt._48_4_)();
    if (iVar1 == 2) {
      DAT_0059f6f8 = realtime;
      DAT_0059f700 = 3;
      DAT_0059f704 = 0x37;
      return;
    }
    if (iVar1 == 1) {
      pcStack_3c = "Server auth complete invalid\n";
      uStack_40 = 0xca1eb;
      Con_Printf();
    }
    else {
      pcStack_3c = "S2C_AUTHCOMPLETE:  Unable to parse Auth complete.\n";
      uStack_40 = 0xca201;
      Con_DPrintf();
    }
  }
  puVar2 = &net_from;
  puVar3 = auStack_54;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  iStack_38 = NET_AdrToString();
  pcStack_3c = "Authentication failure on %s\n";
  uStack_40 = 0xca23c;
  Con_Printf();
  return;
}


// CL_Particle  @ 0005f180
void CL_Particle(void)

{
  return;
}


// CL_PredictMove  @ 0005f188
void CL_PredictMove(void)

{
  return;
}


// CL_PrintLogos  @ 0005f190
void CL_PrintLogos(void)

{
  return;
}


// CL_QueueEvent__13EngineWrapperiifP12event_args_s  @ 00097ac8
undefined4 CL_QueueEvent__13EngineWrapperiifP12event_args_s(undefined4 param_1)

{
  return param_1;
}


// CL_ReadPackets  @ 0005f198
void CL_ReadPackets(void)

{
  return;
}


// CL_RecordHUDCommand  @ 0005f120
void CL_RecordHUDCommand(void)

{
  return;
}


// CL_RedoPrediction  @ 0005f258
void CL_RedoPrediction(void)

{
  return;
}


// CL_RequestMissingResources  @ 0005f1a0
undefined4 CL_RequestMissingResources(void)

{
  return 0;
}


// CL_Save  @ 000726ec
void CL_Save(void)

{
  return;
}


// CL_SendConnectPacket  @ 0005f1b4
void CL_SendConnectPacket(void)

{
  return;
}


// CL_SetLastUpdate  @ 0005f260
void CL_SetLastUpdate(void)

{
  return;
}


// CL_ShutDownClientStatic  @ 0005f220
void CL_ShutDownClientStatic(void)

{
  return;
}


// CL_ShutDownUsrMessages  @ 0005f218
void CL_ShutDownUsrMessages(void)

{
  return;
}


// CL_Shutdown  @ 0005f230
void CL_Shutdown(void)

{
  return;
}


// CL_StartAuthentication  @ 000ca6c8
void CL_StartAuthentication(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  WON_RemoveUser(&clauthstate);
  DAT_0059f70c = 0;
  DAT_0059f708 = 0;
  DAT_0059f704 = 0x34;
  DAT_0059f6f8 = realtime;
  DAT_0059f700 = 3;
  puVar2 = &clauthstate;
  for (iVar1 = 5; puVar2 = puVar2 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
  }
  clauthstate = 1;
  if (((crypt._32_4_ != 0) && (iVar1 = (*(code *)crypt._32_4_)(0,0,&clauthstate), iVar1 != 2)) &&
     (iVar1 != 0)) {
    Con_Printf("Error constructing authentication request\n");
  }
  return;
}


// CL_StopPlayback  @ 0005f1bc
void CL_StopPlayback(void)

{
  return;
}


// CL_UpdateModuleC  @ 0005f2a0
void CL_UpdateModuleC(void)

{
  return;
}


// CL_UpdateSoundFade  @ 0005f1c4
void CL_UpdateSoundFade(void)

{
  return;
}


// CL_VoiceIdle  @ 0005f288
void CL_VoiceIdle(void)

{
  return;
}


// CL_WriteMessageHistory  @ 0005f270
void CL_WriteMessageHistory(void)

{
  return;
}


