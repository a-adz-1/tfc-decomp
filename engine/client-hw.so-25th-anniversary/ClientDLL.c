// ClientDLL_ActivateMouse  @ 00168e30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_ActivateMouse(void)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pIN_ActivateMouse != (HUD_IN_ACTIVATEMOUSE_FUNC)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00168e42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pIN_ActivateMouse)();
    return;
  }
  return;
}


// ClientDLL_AddEntity  @ 00168a80
int ClientDLL_AddEntity(int type,cl_entity_s *ent)

{
  cl_entity_t **ppcVar1;
  model_s *pmVar2;
  int iVar3;
  mnode_t *pmVar4;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int i@[???] */
  if (cl_funcs.pAddEntity != (HUD_ADDENTITY_FUNC)0x0) {
    pmVar2 = ent->model;
    if (pmVar2 == (model_s *)0x0) {
      pmVar2 = (model_s *)&DAT_0027abd7;
    }
    iVar3 = (*cl_funcs.pAddEntity)(type,ent,pmVar2->name);
    if (iVar3 != 0) {
      iVar3 = CL_IsSpectateOnly();
      if ((((iVar3 != 0) && (iVar3 = CL_IsDevOverviewMode(), iVar3 == 0)) && (1 < type - 2U)) &&
         ((ent->curstate).movetype != 0xc)) {
        pmVar2 = ent->model;
                    /* Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???] */
        local_24 = pmVar2->mins[0] + ent->origin[0];
        local_18 = pmVar2->maxs[0] + ent->origin[0];
        local_20 = pmVar2->mins[1] + ent->origin[1];
        local_14 = pmVar2->maxs[1] + ent->origin[1];
        local_1c = pmVar2->mins[2] + ent->origin[2];
        local_10 = pmVar2->maxs[2] + ent->origin[2];
        pmVar4 = PVSNode((cl.worldmodel)->nodes,&local_24,&local_18);
        if (pmVar4 == (mnode_t *)0x0) {
          return 0;
        }
      }
      if (type == 3) {
        if (cl_numbeamentities < 0x40) {
          ppcVar1 = cl_beamentities + cl_numbeamentities;
          cl_numbeamentities = cl_numbeamentities + 1;
          *ppcVar1 = ent;
          return 1;
        }
      }
      else if (cl_numvisedicts < 0x200) {
        ppcVar1 = cl_visedicts + cl_numvisedicts;
        cl_numvisedicts = cl_numvisedicts + 1;
        *ppcVar1 = ent;
        return 1;
      }
    }
  }
  return 0;
}


// ClientDLL_CAM_Think  @ 00168c00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_CAM_Think(void)

{
  if ((ca_disconnected < cls.state) && (cl_funcs.pCamThink != (HUD_CAMTHINK_FUNC)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00168c12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pCamThink)();
    return;
  }
  return;
}


// ClientDLL_CalcRefdef  @ 00168be0
void ClientDLL_CalcRefdef(ref_params_s *pparams)

{
  if (cl_funcs.pCalcRefdef != (HUD_CALCREF_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00168be9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pCalcRefdef)(pparams);
    return;
  }
  return;
}


// ClientDLL_ChatInputPosition  @ 00168850
void ClientDLL_ChatInputPosition(int *x,int *y)

{
  if (cl_funcs.pChatInputPosition != (HUD_CHATINPUTPOSITION_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00168859. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pChatInputPosition)(x,y);
    return;
  }
  return;
}


// ClientDLL_CheckStudioInterface  @ 001693f0
void ClientDLL_CheckStudioInterface(HINSTANCE hClientDLL)

{
  int iVar1;
  
                    /* Unresolved local var: HUD_STUDIO_INTERFACE_FUNC studio_interface@[???] */
  R_ResetStudio();
  if (fClientLoaded != '\0') {
    dlsym(hClientDLL,"HUD_GetStudioModelInterface");
    if (cl_funcs.pStudioInterface != (HUD_STUDIO_INTERFACE_FUNC)0x0) {
      iVar1 = (*cl_funcs.pStudioInterface)(1,&pStudioAPI,&engine_studio_api);
      if (iVar1 == 0) {
                    /* Unresolved local var: HUD_STUDIO_INTERFACE_FUNC studio_interface@[???] */
        Con_DPrintf(
                   "Couldn\'t get client .dll studio model rendering interface.  Version mismatch?\n"
                   );
        R_ResetStudio();
        return;
      }
    }
  }
  return;
}


// ClientDLL_ClearStates  @ 00168e90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_ClearStates(void)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pIN_ClearStates != (HUD_IN_CLEARSTATES_FUNC)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00168ea2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pIN_ClearStates)();
    return;
  }
  return;
}


// ClientDLL_ClientMoveInit  @ 00168ed0
void ClientDLL_ClientMoveInit(playermove_s_conflict *ppmove)

{
  if (cl_funcs.pClientMoveInit != (HUD_CLIENTMOVEINIT_FUNC_conflict)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00168ed9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pClientMoveInit)(ppmove);
    return;
  }
  return;
}


// ClientDLL_ClientTextureType  @ 00168ef0
char ClientDLL_ClientTextureType(char *name)

{
  char cVar1;
  
  if (cl_funcs.pClientTextureType != (HUD_TEXTURETYPE_FUNC_conflict)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00168ef9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    cVar1 = (*cl_funcs.pClientTextureType)(name);
    return cVar1;
  }
  return '\0';
}


// ClientDLL_ConnectionlessPacket  @ 00168950
int ClientDLL_ConnectionlessPacket
              (netadr_s *net_from,char *args,char *response_buffer,int *response_buffer_size)

{
  int iVar1;
  
  if (cl_funcs.pConnectionlessPacket != (HUD_CONNECTIONLESS_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0016896d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*cl_funcs.pConnectionlessPacket)(net_from,args,response_buffer,response_buffer_size);
    return iVar1;
  }
  return 0;
}


// ClientDLL_CreateEntities  @ 00168a60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_CreateEntities(void)

{
  if (cl_funcs.pCreateEntities != (HUD_CREATEENTITIES_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00168a69. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pCreateEntities)();
    return;
  }
  return;
}


// ClientDLL_CreateMove  @ 00168c80
void ClientDLL_CreateMove(float frametime,usercmd_s *cmd,int active)

{
  if ((joy_supported == (cvar_t *)0x0) || (joy_supported->value == 0.0)) {
    if ((joy_forwardsensitivity != (cvar_t *)0x0) && (joy_forwardsensitivity->value != 0.0)) {
      Cvar_Set("joyforwardsensitivity","0");
    }
    if ((joy_sidesensitivity != (cvar_t *)0x0) && (joy_sidesensitivity->value != 0.0)) {
      Cvar_Set("joysidesensitivity","0");
    }
    if ((joy_pitchsensitivity != (cvar_t *)0x0) && (joy_pitchsensitivity->value != 0.0)) {
      Cvar_Set("joypitchsensitivity","0");
    }
    if ((joy_yawsensitivity != (cvar_t *)0x0) && (joy_yawsensitivity->value != 0.0)) {
      Cvar_Set("joyyawsensitivity","0");
    }
  }
  if (cl_funcs.pCL_CreateMove == (HUD_CL_CREATEMOVE_FUNC)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00168ccb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*cl_funcs.pCL_CreateMove)(frametime,cmd,active);
  return;
}


// ClientDLL_DeactivateMouse  @ 00168e50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_DeactivateMouse(void)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pIN_DeactivateMouse != (HUD_IN_DEACTIVATEMOUSE_FUNC)0x0))
  {
                    /* WARNING: Could not recover jumptable at 0x00168e62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pIN_DeactivateMouse)();
    return;
  }
  return;
}


// ClientDLL_DemoUpdateClientData  @ 001692d0
void ClientDLL_DemoUpdateClientData(client_data_t *cdat)

{
  int iVar1;
  
  if (cl_funcs.pHudUpdateClientDataFunc != (HUD_UPDATECLIENTDATA_FUNC)0x0) {
    iVar1 = (*cl_funcs.pHudUpdateClientDataFunc)(cdat,(float)cl.time);
    if ((iVar1 != 0) && (cls.spectator == false)) {
      cl.viewangles[0] = cdat->viewangles[0];
      cl.viewangles[1] = cdat->viewangles[1];
      cl.viewangles[2] = cdat->viewangles[2];
      scr_fov_value = cdat->fov;
    }
  }
  return;
}


// ClientDLL_DirectorMessage  @ 001688a0
void ClientDLL_DirectorMessage(int iSize,void *pbuf)

{
  if (cl_funcs.pDirectorMessage != (HUD_DIRECTORMESSAGE_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001688a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pDirectorMessage)(iSize,pbuf);
    return;
  }
  return;
}


// ClientDLL_DrawNormalTriangles  @ 00168a20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_DrawNormalTriangles(void)

{
  if (cl_funcs.pDrawNormalTriangles != (HUD_DRAWNORMALTRIS_FUNC)0x0) {
    (*cl_funcs.pDrawNormalTriangles)();
  }
  (*tri.RenderMode)(0);
  return;
}


// ClientDLL_DrawTransparentTriangles  @ 00168a40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_DrawTransparentTriangles(void)

{
  if (cl_funcs.pDrawTransparentTriangles != (HUD_DRAWTRANSTRIS_FUNC)0x0) {
    (*cl_funcs.pDrawTransparentTriangles)();
  }
  (*tri.RenderMode)(0);
  return;
}


// ClientDLL_ExpandFileName  @ 00167050
int ClientDLL_ExpandFileName(char *fileName,char *nameOutBuffer,int nameOutBufferSize)

{
  int iVar1;
  int in_GS_OFFSET;
  char *local_224;
  char *local_220 [4];
  char local_210 [511];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: char[512] buf@[???] */
  local_220[0] = fileName;
  local_224 = nameOutBuffer;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  (*g_engdstAddrs.COM_ExpandFilename)(local_220,&local_224,&nameOutBufferSize);
  Q_strncpy(local_210,local_220[0],0x1ff);
  local_11 = 0;
  iVar1 = COM_ExpandFilename(local_210);
  if (iVar1 != 0) {
    COM_FixSlashes(local_210);
    Q_strncpy(local_224,local_210,nameOutBufferSize);
    local_224[nameOutBufferSize + -1] = '\0';
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (uint)(iVar1 != 0);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ClientDLL_FindKey  @ 00168c20
kbutton_s * ClientDLL_FindKey(char *name)

{
  kbutton_s *pkVar1;
  
  if (cl_funcs.pFindKey != (HUD_KB_FIND_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00168c29. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pkVar1 = (*cl_funcs.pFindKey)(name);
    return pkVar1;
  }
  return (kbutton_s *)0x0;
}


// ClientDLL_Frame  @ 00169160
void ClientDLL_Frame(double time)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pHudFrame != (HUD_FRAME_FUNC)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00169172. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pHudFrame)(time);
    return;
  }
  return;
}


// ClientDLL_GetCameraOffsets  @ 00168c40
void ClientDLL_GetCameraOffsets(float *ofs)

{
  if (cl_funcs.pCL_GetCameraOffsets != (HUD_CL_GETCAMERAOFFSETS_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00168c49. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pCL_GetCameraOffsets)(ofs);
    return;
  }
  return;
}


// ClientDLL_GetHullBounds  @ 00168930
int ClientDLL_GetHullBounds(int hullnumber,float *mins,float *maxs)

{
  int iVar1;
  
  if (cl_funcs.pGetHullBounds != (HUD_GETHULLBOUNDS_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0016893b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*cl_funcs.pGetHullBounds)(hullnumber,mins,maxs);
    return iVar1;
  }
  return 0;
}


// ClientDLL_GetUserEntity  @ 00168810
cl_entity_t * ClientDLL_GetUserEntity(int index)

{
  cl_entity_s *pcVar1;
  
  if (cl_funcs.pGetUserEntity != (HUD_GETUSERENTITY_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00168819. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar1 = (*cl_funcs.pGetUserEntity)(index);
    return pcVar1;
  }
  return (cl_entity_t *)0x0;
}


// ClientDLL_HudInit  @ 00169020
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_HudInit(void)

{
  HINSTANCE pvVar1;
  int iVar2;
  
  if (cl_funcs.pHudInitFunc != (HUD_INIT_FUNC)0x0) {
    (*cl_funcs.pHudInitFunc)();
    pvVar1 = hClientDLL;
                    /* Unresolved local var: HUD_STUDIO_INTERFACE_FUNC studio_interface@[???] */
    R_ResetStudio();
    if (fClientLoaded != '\0') {
      dlsym(pvVar1,"HUD_GetStudioModelInterface");
      if (cl_funcs.pStudioInterface != (HUD_STUDIO_INTERFACE_FUNC)0x0) {
        iVar2 = (*cl_funcs.pStudioInterface)(1,&pStudioAPI,&engine_studio_api);
        if (iVar2 == 0) {
                    /* Unresolved local var: HUD_STUDIO_INTERFACE_FUNC studio_interface@[???] */
          Con_DPrintf(
                     "Couldn\'t get client .dll studio model rendering interface.  Version mismatch?\n"
                     );
          R_ResetStudio();
        }
      }
    }
    cl_righthand = Cvar_FindVar("cl_righthand");
    joy_supported = Cvar_FindVar("joysupported");
    joy_forwardsensitivity = Cvar_FindVar("joyforwardsensitivity");
    joy_sidesensitivity = Cvar_FindVar("joysidesensitivity");
    joy_pitchsensitivity = Cvar_FindVar("joypitchsensitivity");
    joy_yawsensitivity = Cvar_FindVar("joyyawsensitivity");
    return;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("../engine/cdll_int.c, line %d: could not link client DLL for HUD initialization",0x466)
  ;
}


// ClientDLL_HudRedraw  @ 00169130
void ClientDLL_HudRedraw(int intermission)

{
  int iVar1;
  
  iVar1 = VGuiWrap2_IsGameUIVisible();
  if ((iVar1 == 0) && (cl_funcs.pHudRedrawFunc != (HUD_REDRAW_FUNC)0x0)) {
    (*cl_funcs.pHudRedrawFunc)((float)cl.time,intermission);
  }
  return;
}


// ClientDLL_HudVidInit  @ 00168fd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_HudVidInit(void)

{
  if (cl_funcs.pHudVidInitFunc != (HUD_VIDINIT_FUNC)0x0) {
    SPR_Init();
                    /* WARNING: Could not recover jumptable at 0x00168fe5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pHudVidInitFunc)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("../engine/cdll_int.c, line %d: could not link client DLL for HUD Vid initialization",
            0x453);
}


// ClientDLL_IN_Accumulate  @ 00168eb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_IN_Accumulate(void)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pIN_Accumulate != (HUD_IN_ACCUMULATE_FUNC)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00168ec2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pIN_Accumulate)();
    return;
  }
  return;
}


// ClientDLL_Init  @ 001685e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_Init(void)

{
  void *pvVar1;
  int in_GS_OFFSET;
  char local_210 [512];
  int local_10;
  
                    /* Unresolved local var: char[512] szDllName@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  builtin_strncpy(local_210,"cl_dlls/client.so",0x12);
  if (fClientLoaded != '\0') {
    Net_APIShutDown();
    SPR_Shutdown();
    if (cl_funcs.pShutdown != (HUD_SHUTDOWN_FUNC)0x0) {
      (*cl_funcs.pShutdown)();
    }
    if (cls.fSecureClient == false) {
      dlclose(hClientDLL);
      hClientDLL = (HINSTANCE)0x0;
    }
    else {
      FreeBlob(&g_blobfootprintClient);
    }
    Q_memset(&cl_funcs,0,0xac);
    Cvar_RemoveHudCvars();
    Cmd_RemoveHudCmds();
    CL_ShutDownUsrMessages();
    fClientLoaded = '\0';
    if (hClientDLL != (HINSTANCE)0x0) {
      dlclose(hClientDLL);
    }
    hClientDLL = (HINSTANCE)0x0;
  }
  COM_FixSlashes(local_210);
  __strcpy_chk(g_szfullClientName,local_210,0x200);
  COM_ExpandFilename(g_szfullClientName);
  COM_FixSlashes(g_szfullClientName);
                    /* Unresolved local var: void * ret@[???] */
  cls.fSecureClient = false;
  cl_funcs.pInitFunc = (INITIALIZE_FUNC)&g_modfuncs;
  cl_funcs.pHudVidInitFunc = (HUD_VIDINIT_FUNC)&g_cldstAddrs;
  pvVar1 = NLoadBlobFile(g_szfullClientName,&g_blobfootprintClient,&cl_funcs,'\x01');
  if (pvVar1 == (void *)0x0) {
    if (fClientLoaded == '\0') {
      LoadInsecureClient(g_szfullClientName);
    }
  }
  else {
    fClientLoaded = '\x01';
    hClientDLL = pvVar1;
  }
  HookServerMsg("ScreenShake",V_ScreenShake);
  HookServerMsg("ScreenFade",V_ScreenFade);
  (*cl_funcs.pInitFunc)(&cl_enginefuncs,7);
  if (cl_funcs.pClientMoveInit != (HUD_CLIENTMOVEINIT_FUNC_conflict)0x0) {
    (*cl_funcs.pClientMoveInit)(&g_clmove);
  }
  CL_GetPlayerHulls();
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ClientDLL_IsThirdPerson  @ 00168c60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ClientDLL_IsThirdPerson(void)

{
  int iVar1;
  
  if (cl_funcs.pCL_IsThirdPerson != (HUD_CL_ISTHIRDPERSON_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00168c69. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*cl_funcs.pCL_IsThirdPerson)();
    return iVar1;
  }
  return 0;
}


// ClientDLL_Key_Event  @ 001688c0
int ClientDLL_Key_Event(int down,int keynum,char *pszCurrentBinding)

{
  int iVar1;
  int iVar2;
  
  iVar1 = VGui_Key_Event(down,keynum,pszCurrentBinding);
  iVar2 = 0;
  if (iVar1 != 0) {
    if (cl_funcs.pKeyEvent != (HUD_KEY_EVENT_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00168913. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*cl_funcs.pKeyEvent)(down,keynum,pszCurrentBinding);
      return iVar2;
    }
    iVar2 = 1;
  }
  return iVar2;
}


// ClientDLL_MouseEvent  @ 00168e70
void ClientDLL_MouseEvent(int mstate)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pIN_MouseEvent != (HUD_IN_MOUSEEVENT_FUNC)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00168e82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pIN_MouseEvent)(mstate);
    return;
  }
  return;
}


// ClientDLL_MoveClient  @ 00168f10
void ClientDLL_MoveClient(playermove_s_conflict *ppmove)

{
  if (cl_funcs.pClientMove != (HUD_CLIENTMOVE_FUNC_conflict1)0x0) {
    (*cl_funcs.pClientMove)(ppmove,false);
  }
  return;
}


// ClientDLL_PostRunCmd  @ 00168980
void ClientDLL_PostRunCmd
               (local_state_s *from,local_state_s *to,usercmd_s *cmd,int runfuncs,double time,
               uint random_seed)

{
  if (cl_funcs.pPostRunCmd != (HUD_POSTRUNCMD_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001689a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pPostRunCmd)(from,to,cmd,runfuncs,time,random_seed);
    return;
  }
                    /* Unresolved local var: cvar_t cl_lw@[???] */
  if (cl_lw.value != 0.0) {
    Cvar_SetValue("cl_lw",0.0);
    return;
  }
  return;
}


// ClientDLL_ProcessPlayerState  @ 00169360
void ClientDLL_ProcessPlayerState(entity_state_s *dst,entity_state_s *src)

{
  if (cl_funcs.pProcessPlayerState != (HUD_PROCESSPLAYERSTATE_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00169369. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pProcessPlayerState)(dst,src);
    return;
  }
  return;
}


// ClientDLL_ReadDemoBuffer  @ 001693d0
void ClientDLL_ReadDemoBuffer(int size,uchar *buffer)

{
  if (cl_funcs.pReadDemoBuffer != (HUD_DEMOREAD_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001693d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pReadDemoBuffer)(size,buffer);
    return;
  }
  return;
}


// ClientDLL_Shutdown  @ 00168f30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_Shutdown(void)

{
  Net_APIShutDown();
  SPR_Shutdown();
  if (cl_funcs.pShutdown != (HUD_SHUTDOWN_FUNC)0x0) {
    (*cl_funcs.pShutdown)();
  }
  if (cls.fSecureClient == false) {
    dlclose(hClientDLL);
    hClientDLL = (HINSTANCE)0x0;
  }
  else {
    FreeBlob(&g_blobfootprintClient);
  }
  Q_memset(&cl_funcs,0,0xac);
  Cvar_RemoveHudCvars();
  Cmd_RemoveHudCmds();
  CL_ShutDownUsrMessages();
  fClientLoaded = '\0';
  if (hClientDLL != (HINSTANCE)0x0) {
    dlclose(hClientDLL);
  }
  hClientDLL = (HINSTANCE)0x0;
  return;
}


// ClientDLL_StudioEvent  @ 00168a00
void ClientDLL_StudioEvent(mstudioevent_s *event,cl_entity_s *entity)

{
  if (cl_funcs.pStudioEvent != (HUD_STUDIOEVENT_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00168a09. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pStudioEvent)(event,entity);
    return;
  }
  return;
}


// ClientDLL_TempEntUpdate  @ 00168870
void ClientDLL_TempEntUpdate
               (double ft,double ct,double grav,tempent_s **ppFreeTE,tempent_s **ppActiveTE,
               _func_int_cl_entity_s_ptr *addTEntity,_func_void_tempent_s_ptr_float *playTESound)

{
  if (cl_funcs.pTempEntUpdate != (HUD_TEMPENTUPDATE_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0016888d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pTempEntUpdate)(ft,ct,grav,ppFreeTE,ppActiveTE,addTEntity,playTESound);
    return;
  }
  return;
}


// ClientDLL_TxferLocalOverrides  @ 00169340
void ClientDLL_TxferLocalOverrides(entity_state_s *state,clientdata_s *client)

{
  if (cl_funcs.pTxferLocalOverrides != (HUD_TXFERLOCALOVERRIDES_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00169349. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pTxferLocalOverrides)(state,client);
    return;
  }
  return;
}


// ClientDLL_TxferPredictionData  @ 00169380
void ClientDLL_TxferPredictionData
               (entity_state_s *ps,entity_state_s *pps,clientdata_s *pcd,clientdata_s *ppcd,
               weapon_data_s *wd,weapon_data_s *pwd)

{
  if (cl_funcs.pTxferPredictionData != (HUD_TXFERPREDICTIONDATA_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001693ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pTxferPredictionData)(ps,pps,pcd,ppcd,wd,pwd);
    return;
  }
  return;
}


// ClientDLL_UpdateClientData  @ 00169180
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_UpdateClientData(void)

{
  uint uVar1;
  int iVar2;
  client_data_s local_4c;
  client_data_t local_2c;
  
                    /* Unresolved local var: client_data_t cdat@[???]
                       Unresolved local var: client_data_t oldcdat@[???] */
  if ((cls.state != ca_active) || (cls.demoplayback != false)) {
    return;
  }
  Q_memset(&local_4c,0,0x20);
  local_4c.viewangles[0] = cl.viewangles[0];
  local_4c.viewangles[1] = cl.viewangles[1];
  local_4c.viewangles[2] = cl.viewangles[2];
  local_4c.origin[0] = cl_entities[cl.viewentity].origin[0];
  local_4c.origin[1] = cl_entities[cl.viewentity].origin[1];
  local_4c.origin[2] = cl_entities[cl.viewentity].origin[2];
  local_4c.fov = scr_fov_value;
  local_4c.iWeaponBits = cl.weapons;
  if (cls.demorecording == false) {
    if (cl_funcs.pHudUpdateClientDataFunc == (HUD_UPDATECLIENTDATA_FUNC)0x0) {
      return;
    }
  }
  else {
    uVar1 = 0;
    do {
      *(undefined4 *)((int)local_2c.origin + uVar1) = *(undefined4 *)((int)local_4c.origin + uVar1);
      uVar1 = uVar1 + 4;
    } while (uVar1 < 0x20);
    if (cl_funcs.pHudUpdateClientDataFunc == (HUD_UPDATECLIENTDATA_FUNC)0x0) goto LAB_001692b2;
  }
  iVar2 = (*cl_funcs.pHudUpdateClientDataFunc)(&local_4c,(float)cl.time);
  if (iVar2 != 0) {
    cl.viewangles[0] = local_4c.viewangles[0];
    scr_fov_value = local_4c.fov;
    cl.viewangles[1] = local_4c.viewangles[1];
    cl.viewangles[2] = local_4c.viewangles[2];
  }
  if (cls.demorecording == false) {
    return;
  }
LAB_001692b2:
  CL_WriteDLLUpdate(&local_2c);
  return;
}


// ClientDLL_VoiceStatus  @ 00168830
void ClientDLL_VoiceStatus(int entindex,qboolean bTalking)

{
  if (cl_funcs.pVoiceStatus != (HUD_VOICESTATUS_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00168839. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pVoiceStatus)(entindex,bTalking);
    return;
  }
  return;
}


