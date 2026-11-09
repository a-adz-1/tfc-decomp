// CL_CheckForResend  @ 0808d300
void CL_CheckForResend(void)

{
  return;
}


// CL_CheckOrDownloadFile  @ 0808d310
void CL_CheckOrDownloadFile(void)

{
  return;
}


// CL_CheckResourceResend  @ 0808d320
void CL_CheckResourceResend(void)

{
  return;
}


// CL_ClearClientState  @ 0808d330
void CL_ClearClientState(void)

{
  return;
}


// CL_Connect_f  @ 0808d340
void CL_Connect_f(void)

{
  return;
}


// CL_CopyChunk  @ 08053220
void CL_CopyChunk(FILE *param_1,FILE *param_2,size_t param_3)

{
  undefined1 local_404 [1024];
  
  if (0x400 < (int)param_3) {
    do {
      fread(local_404,0x400,1,param_2);
      fwrite(local_404,0x400,1,param_1);
      param_3 = param_3 - 0x400;
    } while (0x400 < (int)param_3);
  }
  fread(local_404,param_3,1,param_2);
  fwrite(local_404,param_3,1,param_1);
  fflush(param_2);
  fflush(param_1);
  return;
}


// CL_DecayLights  @ 0808d350
void CL_DecayLights(void)

{
  return;
}


// CL_Disconnect  @ 0808d360
void CL_Disconnect(void)

{
  return;
}


// CL_Disconnect_f  @ 0808d370
void CL_Disconnect_f(void)

{
  return;
}


// CL_EmitEntities  @ 0808d380
void CL_EmitEntities(void)

{
  return;
}


// CL_FilterTime  @ 08058000
bool CL_FilterTime(float param_1)

{
  float fVar1;
  
  fVar1 = param_1 - sv_oldrealtime_133;
  if (0.033333335 <= fVar1) {
    sv_oldrealtime_133 = param_1;
  }
  return 0.033333335 <= fVar1;
}


// CL_Init  @ 0808d3b0
void CL_Init(void)

{
  return;
}


// CL_InitClosest  @ 0808d390
void CL_InitClosest(void)

{
  return;
}


// CL_InitInput  @ 0808d3a0
void CL_InitInput(void)

{
  return;
}


// CL_NextDemo  @ 0808d3c0
void CL_NextDemo(void)

{
  return;
}


// CL_ParseAuthenticationMessage  @ 08081cd0
void CL_ParseAuthenticationMessage(char param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int aiStack_20 [4];
  char *pcStack_10;
  
  if (param_1 == '4') {
    pcStack_10 = "S2C_AUTHCHALLENGE1\n";
    aiStack_20[3] = 0x8081d0a;
    Con_DPrintf();
    if (DAT_08178284 != 0x34) {
      DAT_08178284 = 0x34;
    }
    pcStack_10 = (char *)&clauthstate;
    aiStack_20[3] = net_message._16_4_ + -5;
    aiStack_20[2] = net_message._8_4_ + 5;
    aiStack_20[1] = 0x8081d34;
    iVar2 = (*Launcher_AuthChallenge2)();
    if (iVar2 == 2) {
      DAT_08178278 = realtime;
      DAT_08178280 = 3;
      DAT_08178284 = 0x36;
      return;
    }
    if (iVar2 == 1) {
      pcStack_10 = "Server challenge 1 invalid\n";
      aiStack_20[3] = 0x8081d6f;
      Con_Printf();
      goto LAB_08081e2d;
    }
    pcStack_10 = "S2C_AUTHCHALLENGE1:  Unable to parse Auth challenge 1.\n";
  }
  else {
    if (param_1 != '6') goto LAB_08081e2d;
    pcStack_10 = "S2C_AUTHCOMPLETE\n";
    aiStack_20[3] = 0x8081d9a;
    Con_DPrintf();
    if (DAT_08178284 != 0x36) {
      pcStack_10 = "S2C_AUTHCOMPLETE out of sequence\n";
      aiStack_20[3] = 0x8081dad;
      Con_DPrintf();
      return;
    }
    pcStack_10 = (char *)&clauthstate;
    aiStack_20[3] = net_message._16_4_ + -5;
    aiStack_20[2] = net_message._8_4_ + 5;
    aiStack_20[1] = 0x8081dda;
    iVar2 = (*Launcher_DecodeAuthComplete)();
    if (iVar2 == 2) {
      DAT_08178278 = realtime;
      DAT_08178280 = 3;
      DAT_08178284 = 0x37;
      return;
    }
    if (iVar2 == 1) {
      pcStack_10 = "Server auth complete invalid\n";
      aiStack_20[3] = 0x8081e0f;
      Con_Printf();
      goto LAB_08081e2d;
    }
    pcStack_10 = "S2C_AUTHCOMPLETE:  Unable to parse Auth complete.\n";
  }
  aiStack_20[3] = 0x8081e2a;
  Con_DPrintf();
LAB_08081e2d:
  puVar3 = &net_from;
  piVar4 = aiStack_20;
  for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    piVar4 = piVar4 + 1;
  }
  uVar1 = NET_AdrToString();
  Con_Printf("Authentication failure on %s\n",uVar1);
  return;
}


// CL_Particle  @ 0808d3d0
void CL_Particle(void)

{
  return;
}


// CL_PredictMove  @ 0808d3e0
void CL_PredictMove(void)

{
  return;
}


// CL_PrintEntity  @ 0808d3f0
void CL_PrintEntity(void)

{
  return;
}


// CL_PrintLogos  @ 0808d400
void CL_PrintLogos(void)

{
  return;
}


// CL_ReadPackets  @ 0808d410
void CL_ReadPackets(void)

{
  return;
}


// CL_RecordHUDCommand  @ 0808d2e0
void CL_RecordHUDCommand(void)

{
  return;
}


// CL_RequestMissingResources  @ 0808d420
undefined4 CL_RequestMissingResources(void)

{
  return 0;
}


// CL_Save  @ 0805c030
void CL_Save(void)

{
  return;
}


// CL_SendCmd  @ 0808d430
void CL_SendCmd(void)

{
  return;
}


// CL_SendConnectPacket  @ 0808d440
void CL_SendConnectPacket(void)

{
  return;
}


// CL_ShutDownClientStatic  @ 0808d550
void CL_ShutDownClientStatic(void)

{
  return;
}


// CL_ShutDownUsrMessages  @ 0808d540
void CL_ShutDownUsrMessages(void)

{
  return;
}


// CL_StartAuthentication  @ 08082190
void CL_StartAuthentication(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  WON_RemoveUser(&clauthstate);
  DAT_0817828c = 0;
  DAT_08178288 = 0;
  DAT_08178284 = 0x34;
  DAT_08178278 = realtime;
  DAT_08178280 = 3;
  puVar2 = &DAT_08178264;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  clauthstate = 1;
  iVar1 = (*Launcher_AuthRequest)(0,0,&clauthstate);
  if ((iVar1 != 2) && (iVar1 != 0)) {
    Con_Printf("Error constructing authentication request\n");
  }
  return;
}


// CL_StopPlayback  @ 0808d450
void CL_StopPlayback(void)

{
  return;
}


// CL_UpdateSoundFade  @ 0808d460
void CL_UpdateSoundFade(void)

{
  return;
}


