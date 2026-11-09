// ClientDLL_ActivateMouse  @ 001c05b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_ActivateMouse(void)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pIN_ActivateMouse != (HUD_IN_ACTIVATEMOUSE_FUNC)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001c05c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pIN_ActivateMouse)();
    return;
  }
  return;
}


// ClientDLL_AddEntity  @ 001c03a0
int ClientDLL_AddEntity(int type,cl_entity_s *ent)

{
  model_s *pmVar1;
  int iVar2;
  mnode_t *pmVar3;
  int iVar4;
  float local_2c;
  float local_28;
  float local_24;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: int i@[???] */
  iVar4 = 0;
  if (cl_funcs.pAddEntity != (HUD_ADDENTITY_FUNC)0x0) {
    pmVar1 = (model_s *)&DAT_0029c4a3;
    if (ent->model != (model_s *)0x0) {
      pmVar1 = ent->model;
    }
    iVar2 = (*cl_funcs.pAddEntity)(type,ent,pmVar1->name);
    if (iVar2 != 0) {
      iVar4 = CL_IsSpectateOnly();
      if ((((iVar4 != 0) && (iVar4 = CL_IsDevOverviewMode(), iVar4 == 0)) && (type != 3)) &&
         ((type != 2 && ((ent->curstate).movetype != 0xc)))) {
        pmVar1 = ent->model;
                    /* Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???] */
        local_2c = pmVar1->mins[0] + ent->origin[0];
        local_1c = ent->origin[0] + pmVar1->maxs[0];
        local_28 = pmVar1->mins[1] + ent->origin[1];
        local_18 = ent->origin[1] + pmVar1->maxs[1];
        local_24 = pmVar1->mins[2] + ent->origin[2];
        local_14 = ent->origin[2] + pmVar1->maxs[2];
        pmVar3 = PVSNode((cl.worldmodel)->nodes,&local_2c,&local_1c);
        if (pmVar3 == (mnode_t *)0x0) {
          return 0;
        }
      }
      if (type == 3) {
        iVar4 = 0;
        if (cl_numbeamentities < 0x40) {
          cl_beamentities[cl_numbeamentities] = ent;
          cl_numbeamentities = cl_numbeamentities + 1;
          iVar4 = 1;
        }
      }
      else {
        iVar4 = 0;
        if (cl_numvisedicts < 0x200) {
          cl_visedicts[cl_numvisedicts] = ent;
          cl_numvisedicts = cl_numvisedicts + 1;
          iVar4 = 1;
        }
      }
    }
  }
  return iVar4;
}


// ClientDLL_CAM_Think  @ 001c0510
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_CAM_Think(void)

{
  if ((ca_disconnected < cls.state) && (cl_funcs.pCamThink != (HUD_CAMTHINK_FUNC)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001c0522. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pCamThink)();
    return;
  }
  return;
}


// ClientDLL_CalcRefdef  @ 001c04f0
void ClientDLL_CalcRefdef(ref_params_s *pparams)

{
  if (cl_funcs.pCalcRefdef != (HUD_CALCREF_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c04f9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pCalcRefdef)(pparams);
    return;
  }
  return;
}


// ClientDLL_ChatInputPosition  @ 001c0150
void ClientDLL_ChatInputPosition(int *x,int *y)

{
  if (cl_funcs.pChatInputPosition != (HUD_CHATINPUTPOSITION_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c0159. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pChatInputPosition)(x,y);
    return;
  }
  return;
}


// ClientDLL_CheckStudioInterface  @ 001c0ad0
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


// ClientDLL_ClearStates  @ 001c0610
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_ClearStates(void)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pIN_ClearStates != (HUD_IN_CLEARSTATES_FUNC)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001c0622. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pIN_ClearStates)();
    return;
  }
  return;
}


// ClientDLL_ClientMoveInit  @ 001c0650
void ClientDLL_ClientMoveInit(playermove_s_conflict *ppmove)

{
  if (cl_funcs.pClientMoveInit != (HUD_CLIENTMOVEINIT_FUNC_conflict)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c0659. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pClientMoveInit)(ppmove);
    return;
  }
  return;
}


// ClientDLL_ClientTextureType  @ 001c0670
char ClientDLL_ClientTextureType(char *name)

{
  char cVar1;
  
  if (cl_funcs.pClientTextureType != (HUD_TEXTURETYPE_FUNC_conflict)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c0679. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    cVar1 = (*cl_funcs.pClientTextureType)(name);
    return cVar1;
  }
  return '\0';
}


// ClientDLL_ConnectionlessPacket  @ 001c0270
int ClientDLL_ConnectionlessPacket
              (netadr_s *net_from,char *args,char *response_buffer,int *response_buffer_size)

{
  int iVar1;
  
  if (cl_funcs.pConnectionlessPacket != (HUD_CONNECTIONLESS_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c028d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*cl_funcs.pConnectionlessPacket)(net_from,args,response_buffer,response_buffer_size);
    return iVar1;
  }
  return 0;
}


// ClientDLL_CreateEntities  @ 001c0380
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_CreateEntities(void)

{
  if (cl_funcs.pCreateEntities != (HUD_CREATEENTITIES_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c0389. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pCreateEntities)();
    return;
  }
  return;
}


// ClientDLL_CreateMove  @ 001c0590
void ClientDLL_CreateMove(float frametime,usercmd_s *cmd,int active)

{
  if (cl_funcs.pCL_CreateMove != (HUD_CL_CREATEMOVE_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c059b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pCL_CreateMove)(frametime,cmd,active);
    return;
  }
  return;
}


// ClientDLL_DeactivateMouse  @ 001c05d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_DeactivateMouse(void)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pIN_DeactivateMouse != (HUD_IN_DEACTIVATEMOUSE_FUNC)0x0))
  {
                    /* WARNING: Could not recover jumptable at 0x001c05e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pIN_DeactivateMouse)();
    return;
  }
  return;
}


// ClientDLL_DemoUpdateClientData  @ 001c09c0
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


// ClientDLL_DirectorMessage  @ 001c01a0
void ClientDLL_DirectorMessage(int iSize,void *pbuf)

{
  if (cl_funcs.pDirectorMessage != (HUD_DIRECTORMESSAGE_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c01a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pDirectorMessage)(iSize,pbuf);
    return;
  }
  return;
}


// ClientDLL_DrawNormalTriangles  @ 001c0340
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_DrawNormalTriangles(void)

{
  if (cl_funcs.pDrawNormalTriangles != (HUD_DRAWNORMALTRIS_FUNC)0x0) {
    (*cl_funcs.pDrawNormalTriangles)();
  }
  (*tri.RenderMode)(0);
  return;
}


// ClientDLL_DrawTransparentTriangles  @ 001c0360
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_DrawTransparentTriangles(void)

{
  if (cl_funcs.pDrawTransparentTriangles != (HUD_DRAWTRANSTRIS_FUNC)0x0) {
    (*cl_funcs.pDrawTransparentTriangles)();
  }
  (*tri.RenderMode)(0);
  return;
}


// ClientDLL_ExpandFileName  @ 001be270
int ClientDLL_ExpandFileName(char *fileName,char *nameOutBuffer,int nameOutBufferSize)

{
  int iVar1;
  char local_20c [511];
  undefined1 local_d;
  
                    /* Unresolved local var: char[512] buf@[???] */
  (*g_engdstAddrs.COM_ExpandFilename)(&fileName,&nameOutBuffer,&nameOutBufferSize);
  Q_strncpy(local_20c,fileName,0x1ff);
  local_d = 0;
  iVar1 = COM_ExpandFilename(local_20c);
  if (iVar1 != 0) {
    COM_FixSlashes(local_20c);
    Q_strncpy(nameOutBuffer,local_20c,nameOutBufferSize);
    nameOutBuffer[nameOutBufferSize + -1] = '\0';
  }
  return (uint)(iVar1 != 0);
}


// ClientDLL_FindKey  @ 001c0530
kbutton_s * ClientDLL_FindKey(char *name)

{
  kbutton_s *pkVar1;
  
  if (cl_funcs.pFindKey != (HUD_KB_FIND_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c0539. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pkVar1 = (*cl_funcs.pFindKey)(name);
    return pkVar1;
  }
  return (kbutton_s *)0x0;
}


// ClientDLL_Frame  @ 001c0880
void ClientDLL_Frame(double time)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pHudFrame != (HUD_FRAME_FUNC)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001c0892. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pHudFrame)(time);
    return;
  }
  return;
}


// ClientDLL_GetCameraOffsets  @ 001c0550
void ClientDLL_GetCameraOffsets(float *ofs)

{
  if (cl_funcs.pCL_GetCameraOffsets != (HUD_CL_GETCAMERAOFFSETS_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c0559. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pCL_GetCameraOffsets)(ofs);
    return;
  }
  return;
}


// ClientDLL_GetHullBounds  @ 001c0250
int ClientDLL_GetHullBounds(int hullnumber,float *mins,float *maxs)

{
  int iVar1;
  
  if (cl_funcs.pGetHullBounds != (HUD_GETHULLBOUNDS_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c025b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*cl_funcs.pGetHullBounds)(hullnumber,mins,maxs);
    return iVar1;
  }
  return 0;
}


// ClientDLL_GetUserEntity  @ 001c0110
cl_entity_t * ClientDLL_GetUserEntity(int index)

{
  cl_entity_s *pcVar1;
  
  if (cl_funcs.pGetUserEntity != (HUD_GETUSERENTITY_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c0119. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar1 = (*cl_funcs.pGetUserEntity)(index);
    return pcVar1;
  }
  return (cl_entity_t *)0x0;
}


// ClientDLL_HudInit  @ 001c07a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_HudInit(void)

{
  HINSTANCE pvVar1;
  int iVar2;
  
  if (cl_funcs.pHudInitFunc == (HUD_INIT_FUNC)0x0) {
    Sys_Error("../engine/cdll_int.c, line %d: could not link client DLL for HUD initialization",
              0x433);
  }
  (*cl_funcs.pHudInitFunc)();
  pvVar1 = hClientDLL;
                    /* Unresolved local var: HUD_STUDIO_INTERFACE_FUNC studio_interface@[???] */
  R_ResetStudio();
  if (fClientLoaded != '\0') {
    dlsym(pvVar1,"HUD_GetStudioModelInterface");
    if (cl_funcs.pStudioInterface != (HUD_STUDIO_INTERFACE_FUNC)0x0) {
      iVar2 = (*cl_funcs.pStudioInterface)(1,&pStudioAPI,&engine_studio_api);
      if (iVar2 == 0) {
        Con_DPrintf(
                   "Couldn\'t get client .dll studio model rendering interface.  Version mismatch?\n"
                   );
        R_ResetStudio();
      }
    }
  }
  cl_righthand = Cvar_FindVar("cl_righthand");
  return;
}


// ClientDLL_HudRedraw  @ 001c0850
void ClientDLL_HudRedraw(int intermission)

{
  int iVar1;
  
  iVar1 = VGuiWrap2_IsGameUIVisible();
  if ((iVar1 == 0) && (cl_funcs.pHudRedrawFunc != (HUD_REDRAW_FUNC)0x0)) {
    (*cl_funcs.pHudRedrawFunc)((float)cl.time,intermission);
  }
  return;
}


// ClientDLL_HudVidInit  @ 001c0750
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_HudVidInit(void)

{
  if (cl_funcs.pHudVidInitFunc != (HUD_VIDINIT_FUNC)0x0) {
    SPR_Init();
                    /* WARNING: Could not recover jumptable at 0x001c0769. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pHudVidInitFunc)();
    return;
  }
  Sys_Error("../engine/cdll_int.c, line %d: could not link client DLL for HUD Vid initialization",
            0x420);
  SPR_Init();
                    /* WARNING: Could not recover jumptable at 0x001c0792. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*cl_funcs.pHudVidInitFunc)();
  return;
}


// ClientDLL_IN_Accumulate  @ 001c0630
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_IN_Accumulate(void)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pIN_Accumulate != (HUD_IN_ACCUMULATE_FUNC)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001c0642. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pIN_Accumulate)();
    return;
  }
  return;
}


// ClientDLL_Init  @ 001bebf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_Init(void)

{
  void *pvVar1;
  char local_20c [520];
  
                    /* Unresolved local var: char[512] szDllName@[???] */
  snprintf(local_20c,0x200,"cl_dlls/client.so");
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
  COM_FixSlashes(local_20c);
  strcpy(g_szfullClientName,local_20c);
  COM_ExpandFilename(g_szfullClientName);
  COM_FixSlashes(g_szfullClientName);
  cls.fSecureClient = false;
                    /* Unresolved local var: void * ret@[???] */
  cl_funcs.pInitFunc = (INITIALIZE_FUNC)&g_modfuncs;
  cl_funcs.pHudVidInitFunc = (HUD_VIDINIT_FUNC)&g_cldstAddrs;
  pvVar1 = NLoadBlobFile(g_szfullClientName,&g_blobfootprintClient,&cl_funcs,'\x01');
  if (pvVar1 == (void *)0x0) {
    if (fClientLoaded == '\0') {
      hClientDLL = FS_LoadLibrary(g_szfullClientName);
      if (hClientDLL == (void *)0x0) {
        Sys_Error("could not load library %s",g_szfullClientName);
      }
      fClientLoaded = '\x01';
      cl_funcs.pInitFunc = (INITIALIZE_FUNC)dlsym(hClientDLL,"Initialize");
      if (cl_funcs.pInitFunc == (INITIALIZE_FUNC)0x0) {
        Sys_Error("could not link client.dll function Initialize\n");
      }
      cl_funcs.pHudVidInitFunc = (HUD_VIDINIT_FUNC)dlsym(hClientDLL,"HUD_VidInit");
      if (cl_funcs.pHudVidInitFunc == (HUD_VIDINIT_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_VidInit\n");
      }
      cl_funcs.pHudInitFunc = (HUD_INIT_FUNC)dlsym(hClientDLL,"HUD_Init");
      if (cl_funcs.pHudInitFunc == (HUD_INIT_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_Init\n");
      }
      cl_funcs.pHudRedrawFunc = (HUD_REDRAW_FUNC)dlsym(hClientDLL,"HUD_Redraw");
      if (cl_funcs.pHudRedrawFunc == (HUD_REDRAW_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_Redraw\n");
      }
      cl_funcs.pHudUpdateClientDataFunc =
           (HUD_UPDATECLIENTDATA_FUNC)dlsym(hClientDLL,"HUD_UpdateClientData");
      if (cl_funcs.pHudUpdateClientDataFunc == (HUD_UPDATECLIENTDATA_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_UpdateClientData\n");
      }
      cl_funcs.pHudResetFunc = (HUD_RESET_FUNC)dlsym(hClientDLL,"HUD_Reset");
      if (cl_funcs.pHudResetFunc == (HUD_RESET_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_Reset\n");
      }
      cl_funcs.pClientMove = (HUD_CLIENTMOVE_FUNC_conflict1)dlsym(hClientDLL,"HUD_PlayerMove");
      if (cl_funcs.pClientMove == (HUD_CLIENTMOVE_FUNC_conflict1)0x0) {
        Sys_Error("could not link client.dll function HUD_PlayerMove\n");
      }
      cl_funcs.pClientMoveInit =
           (HUD_CLIENTMOVEINIT_FUNC_conflict)dlsym(hClientDLL,"HUD_PlayerMoveInit");
      if (cl_funcs.pClientMoveInit == (HUD_CLIENTMOVEINIT_FUNC_conflict)0x0) {
        Sys_Error("could not link client.dll function HUD_PlayerMoveInit\n");
      }
      cl_funcs.pClientTextureType =
           (HUD_TEXTURETYPE_FUNC_conflict)dlsym(hClientDLL,"HUD_PlayerMoveTexture");
      if (cl_funcs.pClientTextureType == (HUD_TEXTURETYPE_FUNC_conflict)0x0) {
        Sys_Error("could not link client.dll function HUD_PlayerMoveTexture\n");
      }
      cl_funcs.pIN_ActivateMouse = (HUD_IN_ACTIVATEMOUSE_FUNC)dlsym(hClientDLL,"IN_ActivateMouse");
      if (cl_funcs.pIN_ActivateMouse == (HUD_IN_ACTIVATEMOUSE_FUNC)0x0) {
        Sys_Error("could not link client.dll function IN_ActivateMouse\n");
      }
      cl_funcs.pIN_DeactivateMouse =
           (HUD_IN_DEACTIVATEMOUSE_FUNC)dlsym(hClientDLL,"IN_DeactivateMouse");
      if (cl_funcs.pIN_DeactivateMouse == (HUD_IN_DEACTIVATEMOUSE_FUNC)0x0) {
        Sys_Error("could not link client.dll function IN_DeactivateMouse\n");
      }
      cl_funcs.pIN_MouseEvent = (HUD_IN_MOUSEEVENT_FUNC)dlsym(hClientDLL,"IN_MouseEvent");
      if (cl_funcs.pIN_MouseEvent == (HUD_IN_MOUSEEVENT_FUNC)0x0) {
        Sys_Error("could not link client.dll function IN_MouseEvent\n");
      }
      cl_funcs.pIN_ClearStates = (HUD_IN_CLEARSTATES_FUNC)dlsym(hClientDLL,"IN_ClearStates");
      if (cl_funcs.pIN_ClearStates == (HUD_IN_CLEARSTATES_FUNC)0x0) {
        Sys_Error("could not link client.dll function IN_ClearStates\n");
      }
      cl_funcs.pIN_Accumulate = (HUD_IN_ACCUMULATE_FUNC)dlsym(hClientDLL,"IN_Accumulate");
      if (cl_funcs.pIN_Accumulate == (HUD_IN_ACCUMULATE_FUNC)0x0) {
        Sys_Error("could not link client.dll function IN_Accumulate\n");
      }
      cl_funcs.pCL_CreateMove = (HUD_CL_CREATEMOVE_FUNC)dlsym(hClientDLL,"CL_CreateMove");
      if (cl_funcs.pCL_CreateMove == (HUD_CL_CREATEMOVE_FUNC)0x0) {
        Sys_Error("could not link client.dll function CL_CreateMove\n");
      }
      cl_funcs.pCL_IsThirdPerson = (HUD_CL_ISTHIRDPERSON_FUNC)dlsym(hClientDLL,"CL_IsThirdPerson");
      if (cl_funcs.pCL_IsThirdPerson == (HUD_CL_ISTHIRDPERSON_FUNC)0x0) {
        Sys_Error("could not link client.dll function CL_IsThirdPerson\n");
      }
      cl_funcs.pCL_GetCameraOffsets =
           (HUD_CL_GETCAMERAOFFSETS_FUNC)dlsym(hClientDLL,"CL_CameraOffset");
      if (cl_funcs.pCL_GetCameraOffsets == (HUD_CL_GETCAMERAOFFSETS_FUNC)0x0) {
        Sys_Error("could not link client.dll function CL_CameraOffset\n");
      }
      cl_funcs.pCamThink = (HUD_CAMTHINK_FUNC)dlsym(hClientDLL,"CAM_Think");
      if (cl_funcs.pCamThink == (HUD_CAMTHINK_FUNC)0x0) {
        Sys_Error("could not link client.dll function CAM_Think\n");
      }
      cl_funcs.pFindKey = (HUD_KB_FIND_FUNC)dlsym(hClientDLL,"KB_Find");
      if (cl_funcs.pFindKey == (HUD_KB_FIND_FUNC)0x0) {
        Sys_Error("could not link client.dll function KB_Find\n");
      }
      cl_funcs.pCalcRefdef = (HUD_CALCREF_FUNC)dlsym(hClientDLL,"V_CalcRefdef");
      if (cl_funcs.pCalcRefdef == (HUD_CALCREF_FUNC)0x0) {
        Sys_Error("could not link client.dll function V_CalcRefdef\n");
      }
      cl_funcs.pAddEntity = (HUD_ADDENTITY_FUNC)dlsym(hClientDLL,"HUD_AddEntity");
      if (cl_funcs.pAddEntity == (HUD_ADDENTITY_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_AddEntity\n");
      }
      cl_funcs.pCreateEntities = (HUD_CREATEENTITIES_FUNC)dlsym(hClientDLL,"HUD_CreateEntities");
      if (cl_funcs.pCreateEntities == (HUD_CREATEENTITIES_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_CreateEntities\n");
      }
      cl_funcs.pDrawNormalTriangles =
           (HUD_DRAWNORMALTRIS_FUNC)dlsym(hClientDLL,"HUD_DrawNormalTriangles");
      if (cl_funcs.pDrawNormalTriangles == (HUD_DRAWNORMALTRIS_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_DrawNormalTriangles\n");
      }
      cl_funcs.pDrawTransparentTriangles =
           (HUD_DRAWTRANSTRIS_FUNC)dlsym(hClientDLL,"HUD_DrawTransparentTriangles");
      if (cl_funcs.pDrawTransparentTriangles == (HUD_DRAWTRANSTRIS_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_DrawTransparentTriangles\n");
      }
      cl_funcs.pStudioEvent = (HUD_STUDIOEVENT_FUNC)dlsym(hClientDLL,"HUD_StudioEvent");
      if (cl_funcs.pStudioEvent == (HUD_STUDIOEVENT_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_StudioEvent\n");
      }
      cl_funcs.pShutdown = (HUD_SHUTDOWN_FUNC)dlsym(hClientDLL,"HUD_Shutdown");
      if (cl_funcs.pShutdown == (HUD_SHUTDOWN_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_Shutdown\n");
      }
      cl_funcs.pTxferLocalOverrides =
           (HUD_TXFERLOCALOVERRIDES_FUNC)dlsym(hClientDLL,"HUD_TxferLocalOverrides");
      if (cl_funcs.pTxferLocalOverrides == (HUD_TXFERLOCALOVERRIDES_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_TxferLocalOverrides\n");
      }
      cl_funcs.pProcessPlayerState =
           (HUD_PROCESSPLAYERSTATE_FUNC)dlsym(hClientDLL,"HUD_ProcessPlayerState");
      if (cl_funcs.pProcessPlayerState == (HUD_PROCESSPLAYERSTATE_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_ProcessPlayerState\n");
      }
      cl_funcs.pTxferPredictionData =
           (HUD_TXFERPREDICTIONDATA_FUNC)dlsym(hClientDLL,"HUD_TxferPredictionData");
      if (cl_funcs.pTxferPredictionData == (HUD_TXFERPREDICTIONDATA_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_TxferPredictionData\n");
      }
      cl_funcs.pReadDemoBuffer = (HUD_DEMOREAD_FUNC)dlsym(hClientDLL,"Demo_ReadBuffer");
      if (cl_funcs.pReadDemoBuffer == (HUD_DEMOREAD_FUNC)0x0) {
        Sys_Error("could not link client.dll function Demo_ReadBuffer\n");
      }
      cl_funcs.pConnectionlessPacket =
           (HUD_CONNECTIONLESS_FUNC)dlsym(hClientDLL,"HUD_ConnectionlessPacket");
      if (cl_funcs.pConnectionlessPacket == (HUD_CONNECTIONLESS_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_ConnectionlessPacket\n");
      }
      cl_funcs.pGetHullBounds = (HUD_GETHULLBOUNDS_FUNC)dlsym(hClientDLL,"HUD_GetHullBounds");
      if (cl_funcs.pGetHullBounds == (HUD_GETHULLBOUNDS_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_GetHullBounds\n");
      }
      cl_funcs.pHudFrame = (HUD_FRAME_FUNC)dlsym(hClientDLL,"HUD_Frame");
      if (cl_funcs.pHudFrame == (HUD_FRAME_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_Frame\n");
      }
      cl_funcs.pKeyEvent = (HUD_KEY_EVENT_FUNC)dlsym(hClientDLL,"HUD_Key_Event");
      if (cl_funcs.pKeyEvent == (HUD_KEY_EVENT_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_Key_Event\n");
      }
      cl_funcs.pPostRunCmd = (HUD_POSTRUNCMD_FUNC)dlsym(hClientDLL,"HUD_PostRunCmd");
      if (cl_funcs.pPostRunCmd == (HUD_POSTRUNCMD_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_PostRunCmd\n");
      }
      cl_funcs.pTempEntUpdate = (HUD_TEMPENTUPDATE_FUNC)dlsym(hClientDLL,"HUD_TempEntUpdate");
      if (cl_funcs.pTempEntUpdate == (HUD_TEMPENTUPDATE_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_TempEntUpdate\n");
      }
      cl_funcs.pGetUserEntity = (HUD_GETUSERENTITY_FUNC)dlsym(hClientDLL,"HUD_GetUserEntity");
      if (cl_funcs.pGetUserEntity == (HUD_GETUSERENTITY_FUNC)0x0) {
        Sys_Error("could not link client.dll function HUD_GetUserEntity\n");
      }
      cl_funcs.pVoiceStatus = (HUD_VOICESTATUS_FUNC)dlsym(hClientDLL,"HUD_VoiceStatus");
      cl_funcs.pDirectorMessage = (HUD_DIRECTORMESSAGE_FUNC)dlsym(hClientDLL,"HUD_DirectorMessage");
      cl_funcs.pStudioInterface =
           (HUD_STUDIO_INTERFACE_FUNC)dlsym(hClientDLL,"HUD_GetStudioModelInterface");
      cl_funcs.pChatInputPosition =
           (HUD_CHATINPUTPOSITION_FUNC)dlsym(hClientDLL,"HUD_ChatInputPosition");
      cl_funcs.pClientFactory = (CLIENTFACTORY)dlsym(hClientDLL,"ClientFactory");
      cl_funcs.pGetPlayerTeam = (HUD_GETPLAYERTEAM)dlsym(hClientDLL,"HUD_GetPlayerTeam");
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
  return;
}


// ClientDLL_IsThirdPerson  @ 001c0570
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ClientDLL_IsThirdPerson(void)

{
  int iVar1;
  
  if (cl_funcs.pCL_IsThirdPerson != (HUD_CL_ISTHIRDPERSON_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c0579. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*cl_funcs.pCL_IsThirdPerson)();
    return iVar1;
  }
  return 0;
}


// ClientDLL_Key_Event  @ 001c01c0
int ClientDLL_Key_Event(int down,int keynum,char *pszCurrentBinding)

{
  int iVar1;
  
  iVar1 = VGui_Key_Event(down,keynum,pszCurrentBinding);
  if (iVar1 == 0) {
    return 0;
  }
  if (cl_funcs.pKeyEvent != (HUD_KEY_EVENT_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c0213. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*cl_funcs.pKeyEvent)(down,keynum,pszCurrentBinding);
    return iVar1;
  }
  return 1;
}


// ClientDLL_MouseEvent  @ 001c05f0
void ClientDLL_MouseEvent(int mstate)

{
  if ((fClientLoaded != '\0') && (cl_funcs.pIN_MouseEvent != (HUD_IN_MOUSEEVENT_FUNC)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001c0602. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pIN_MouseEvent)(mstate);
    return;
  }
  return;
}


// ClientDLL_MoveClient  @ 001c0690
void ClientDLL_MoveClient(playermove_s_conflict *ppmove)

{
  if (cl_funcs.pClientMove != (HUD_CLIENTMOVE_FUNC_conflict1)0x0) {
    (*cl_funcs.pClientMove)(ppmove,false);
  }
  return;
}


// ClientDLL_PostRunCmd  @ 001c02a0
void ClientDLL_PostRunCmd
               (local_state_s *from,local_state_s *to,usercmd_s *cmd,int runfuncs,double time,
               uint random_seed)

{
  if (cl_funcs.pPostRunCmd != (HUD_POSTRUNCMD_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c02c5. Too many branches */
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


// ClientDLL_ProcessPlayerState  @ 001c0a40
void ClientDLL_ProcessPlayerState(entity_state_s *dst,entity_state_s *src)

{
  if (cl_funcs.pProcessPlayerState != (HUD_PROCESSPLAYERSTATE_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c0a49. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pProcessPlayerState)(dst,src);
    return;
  }
  return;
}


// ClientDLL_ReadDemoBuffer  @ 001c0ab0
void ClientDLL_ReadDemoBuffer(int size,uchar *buffer)

{
  if (cl_funcs.pReadDemoBuffer != (HUD_DEMOREAD_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c0ab9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pReadDemoBuffer)(size,buffer);
    return;
  }
  return;
}


// ClientDLL_Shutdown  @ 001c06b0
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


// ClientDLL_StudioEvent  @ 001c0320
void ClientDLL_StudioEvent(mstudioevent_s *event,cl_entity_s *entity)

{
  if (cl_funcs.pStudioEvent != (HUD_STUDIOEVENT_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c0329. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pStudioEvent)(event,entity);
    return;
  }
  return;
}


// ClientDLL_TempEntUpdate  @ 001c0170
void ClientDLL_TempEntUpdate
               (double ft,double ct,double grav,tempent_s **ppFreeTE,tempent_s **ppActiveTE,
               _func_int_cl_entity_s_ptr *addTEntity,_func_void_tempent_s_ptr_float *playTESound)

{
  if (cl_funcs.pTempEntUpdate != (HUD_TEMPENTUPDATE_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c018d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pTempEntUpdate)(ft,ct,grav,ppFreeTE,ppActiveTE,addTEntity,playTESound);
    return;
  }
  return;
}


// ClientDLL_TxferLocalOverrides  @ 001c0a20
void ClientDLL_TxferLocalOverrides(entity_state_s *state,clientdata_s *client)

{
  if (cl_funcs.pTxferLocalOverrides != (HUD_TXFERLOCALOVERRIDES_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c0a29. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pTxferLocalOverrides)(state,client);
    return;
  }
  return;
}


// ClientDLL_TxferPredictionData  @ 001c0a60
void ClientDLL_TxferPredictionData
               (entity_state_s *ps,entity_state_s *pps,clientdata_s *pcd,clientdata_s *ppcd,
               weapon_data_s *wd,weapon_data_s *pwd)

{
  if (cl_funcs.pTxferPredictionData != (HUD_TXFERPREDICTIONDATA_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c0a8d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pTxferPredictionData)(ps,pps,pcd,ppcd,wd,pwd);
    return;
  }
  return;
}


// ClientDLL_UpdateClientData  @ 001c08a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientDLL_UpdateClientData(void)

{
  int iVar1;
  uint uVar2;
  client_data_s local_4c;
  client_data_t local_2c;
  
                    /* Unresolved local var: client_data_t cdat@[???]
                       Unresolved local var: client_data_t oldcdat@[???] */
  if ((cls.state == ca_active) && (cls.demoplayback == false)) {
    Q_memset(&local_4c,0,0x20);
    local_4c.viewangles[0] = cl.viewangles[0];
    local_4c.viewangles[1] = cl.viewangles[1];
    local_4c.viewangles[2] = cl.viewangles[2];
    local_4c.origin[0] = cl_entities[cl.viewentity].origin[0];
    local_4c.origin[1] = cl_entities[cl.viewentity].origin[1];
    local_4c.origin[2] = cl_entities[cl.viewentity].origin[2];
    local_4c.fov = scr_fov_value;
    local_4c.iWeaponBits = cl.weapons;
    if (cls.demorecording != false) {
      uVar2 = 0;
      do {
        *(undefined4 *)((int)local_2c.origin + uVar2) =
             *(undefined4 *)((int)local_4c.origin + uVar2);
        uVar2 = uVar2 + 4;
      } while (uVar2 < 0x20);
    }
    if ((cl_funcs.pHudUpdateClientDataFunc != (HUD_UPDATECLIENTDATA_FUNC)0x0) &&
       (iVar1 = (*cl_funcs.pHudUpdateClientDataFunc)(&local_4c,(float)cl.time), iVar1 != 0)) {
      cl.viewangles[0] = local_4c.viewangles[0];
      cl.viewangles[1] = local_4c.viewangles[1];
      cl.viewangles[2] = local_4c.viewangles[2];
      scr_fov_value = local_4c.fov;
    }
    if (cls.demorecording != false) {
      CL_WriteDLLUpdate(&local_2c);
    }
  }
  return;
}


// ClientDLL_VoiceStatus  @ 001c0130
void ClientDLL_VoiceStatus(int entindex,qboolean bTalking)

{
  if (cl_funcs.pVoiceStatus != (HUD_VOICESTATUS_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c0139. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*cl_funcs.pVoiceStatus)(entindex,bTalking);
    return;
  }
  return;
}


