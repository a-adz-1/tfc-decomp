// FUN_0005a6d0  @ 0005a6d0
void FUN_0005a6d0(void)

{
  (*(code *)(undefined *)0x0)();
  return;
}


// _DELTA_WriteDelta  @ 0006b740
int _DELTA_WriteDelta(uchar *from,uchar *to,qboolean force,delta_t *pFields,_func_void *callback,
                     int sendfields)

{
  byte *pbVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  uint32 data;
  uint32 uVar5;
  uint local_24 [5];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int bytecount@[???]
                       Unresolved local var: int fieldCount@[???]
                       Unresolved local var: int[2] bits@[???]
                       Unresolved local var: uchar * pdest@[???] */
  if ((sendfields == 0) && (force == false)) {
    return 1;
  }
                    /* Unresolved local var: delta_description_t * pTest@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int lastbit@[???]
                       Unresolved local var: int bitnumber@[???]
                       Unresolved local var: int fieldCount@[???]
                       Unresolved local var: int bytenumber@[???] */
  Q_memset(local_24,0,8);
  iVar2 = pFields->fieldCount + -1;
  if (iVar2 < 0) {
    data = 0;
  }
  else {
    iVar4 = -1;
    psVar3 = &pFields->pdd[iVar2].flags;
    do {
      if ((*psVar3 & 1) != 0) {
        if (iVar4 == -1) {
          iVar4 = iVar2;
        }
        local_24[0x1f < iVar2] = local_24[0x1f < iVar2] | 1 << ((byte)iVar2 & 0x1f);
      }
      iVar2 = iVar2 + -1;
      psVar3 = psVar3 + -0x22;
    } while (iVar2 != -1);
    data = (iVar4 >> 3) + 1;
  }
  if (callback != (_func_void *)0x0) {
    (*callback)();
  }
  MSG_WriteBits(data,3);
  if (0 < (int)data) {
    uVar5 = 0;
    do {
      pbVar1 = (byte *)((int)local_24 + uVar5);
      uVar5 = uVar5 + 1;
      MSG_WriteBits((uint)*pbVar1,8);
    } while (uVar5 != data);
  }
  DELTA_WriteMarkedFields(from,to,pFields);
  return 1;
}


// _DotProduct  @ 00080540
float _DotProduct(vec_t *v1,vec_t *v2)

{
  return v1[2] * v2[2] + v1[1] * v2[1] + *v1 * *v2;
}


// _GLOBAL__sub_I_CheckIP  @ 0005a970
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_CheckIP(void)

{
  CIPRateLimit::CIPRateLimit(&rateChecker);
  __cxa_atexit(CIPRateLimit::~CIPRateLimit,&rateChecker,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_D_SurfaceCacheForRes  @ 0005a750
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_D_SurfaceCacheForRes(void)

{
  __g_CEngineAPI_singleton.super_IEngineAPI.super_IBaseInterface._vptr_IBaseInterface =
       (IEngineAPI)&PTR__CEngineAPI_000e7c70;
  __cxa_atexit(CEngineAPI::~CEngineAPI,&__g_CEngineAPI_singleton,&__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateCEngineAPIIEngineAPI_reg,__CreateCEngineAPIIEngineAPI_interface,
             "VENGINE_LAUNCHER_API_VERSION002");
  __g_CDedicatedServerAPI_singleton.super_IDedicatedServerAPI.super_IBaseInterface.
  _vptr_IBaseInterface = (IBaseInterface)&PTR__CDedicatedServerAPI_000e7c88;
  __cxa_atexit(CDedicatedServerAPI::~CDedicatedServerAPI,&__g_CDedicatedServerAPI_singleton,
               &__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateCDedicatedServerAPIIDedicatedServerAPI_reg,
             __CreateCDedicatedServerAPIIDedicatedServerAPI_interface,"VENGINE_HLDS_API_VERSION002")
  ;
  return;
}


// _GLOBAL__sub_I__Z15COM_BuildNumberv  @ 0005a7f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__Z15COM_BuildNumberv(void)

{
  int in_stack_ffffffe8;
  void **in_stack_ffffffec;
  
  SystemWrapper::SystemWrapper(&gSystemWrapper,in_stack_ffffffe8,in_stack_ffffffec);
  __cxa_atexit(SystemWrapper::~SystemWrapper,&gSystemWrapper,&__dso_handle);
  return;
}


// _GLOBAL__sub_I__ZN12CInitTrackerC2Ev  @ 0005a8e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN12CInitTrackerC2Ev(void)

{
  CInitTracker::CInitTracker(&g_InitTracker);
  __cxa_atexit(CInitTracker::~CInitTracker,&g_InitTracker,&__dso_handle);
  return;
}


// _GLOBAL__sub_I__ZN13CSteam3Server18OnGSPolicyResponseEP18GSPolicyResponse_t  @ 0005a9b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN13CSteam3Server18OnGSPolicyResponseEP18GSPolicyResponse_t(void)

{
  s_Steam3Client.super_CSteam3._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3Client_000eda90;
  s_Steam3Client.m_CallbackClientGameServerDeny.super_CCallbackBase.m_iCallback = 0;
  s_Steam3Client.m_CallbackClientGameServerDeny.super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR_Run_000edb80;
  s_Steam3Client.m_CallbackClientGameServerDeny.m_pObj = &s_Steam3Client;
  s_Steam3Client.m_CallbackClientGameServerDeny.m_Func.__pfn = CSteam3Client::OnClientGameServerDeny
  ;
  s_Steam3Client.super_CSteam3.m_hSteamPipe = 0;
  s_Steam3Client.m_CallbackClientGameServerDeny.m_Func.__delta = 0;
  s_Steam3Client.super_CSteam3.m_bLoggedOn = false;
  s_Steam3Client.super_CSteam3.m_bLogOnResult = false;
  s_Steam3Client.m_CallbackClientGameServerDeny.super_CCallbackBase.m_nCallbackFlags = '\0';
  SteamAPI_RegisterCallback(0x1434ac,0x71);
  s_Steam3Client.m_CallbackGameServerChangeRequested.super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR_Run_000edb68;
  s_Steam3Client.m_CallbackGameServerChangeRequested.m_pObj = &s_Steam3Client;
  s_Steam3Client.m_CallbackGameServerChangeRequested.m_Func.__pfn =
       CSteam3Client::OnGameServerChangeRequested;
  s_Steam3Client.m_CallbackGameServerChangeRequested.m_Func.__delta = 0;
  s_Steam3Client.m_CallbackGameServerChangeRequested.super_CCallbackBase.m_iCallback = 0;
  s_Steam3Client.m_CallbackGameServerChangeRequested.super_CCallbackBase.m_nCallbackFlags = '\0';
  SteamAPI_RegisterCallback(0x1434c4,0x14c);
  s_Steam3Client.m_CallbackGameOverlayActivated.super_CCallbackBase.m_iCallback = 0;
  s_Steam3Client.m_CallbackGameOverlayActivated.m_Func.__pfn = CSteam3Client::OnGameOverlayActivated
  ;
  s_Steam3Client.m_CallbackGameOverlayActivated.m_Func.__delta = 0;
  s_Steam3Client.m_CallbackGameOverlayActivated.super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR_Run_000edb50;
  s_Steam3Client.m_CallbackGameOverlayActivated.m_pObj = &s_Steam3Client;
  s_Steam3Client.m_CallbackGameOverlayActivated.super_CCallbackBase.m_nCallbackFlags = '\0';
  SteamAPI_RegisterCallback(0x1434dc,0x14b);
  __cxa_atexit(CSteam3Client::~CSteam3Client,&s_Steam3Client,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_eng  @ 0005a830
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_eng(void)

{
  g_Engine.super_IEngine._vptr_IEngine = (_func_int_varargs **)&PTR__CEngine_000e8988;
  g_Engine.m_nSubState = 0;
  g_Engine.m_nDLLState = 0;
  g_Engine.m_fFrameTime = 0.0;
  g_Engine.m_nTrapKey = 0;
  g_Engine.m_nTrapButtons = 0;
  g_Engine.m_fOldTime = 0.0;
  g_Engine.m_bTrapMode = false;
  g_Engine.m_bDoneTrapping = false;
  g_Engine.m_nQuitting = 0;
  __cxa_atexit(CEngine::~CEngine,&g_Engine,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_g_FileSystemFactory  @ 0005a700
void processEntry _GLOBAL__sub_I_g_FileSystemFactory(void)

{
  g_fallbackLocalizationFiles.m_Memory.m_pMemory = (char **)0x0;
  g_fallbackLocalizationFiles.m_Memory.m_NumAllocated = 0;
  g_fallbackLocalizationFiles.m_Memory.m_GrowSize = 0;
  g_fallbackLocalizationFiles.m_Size = 0;
  __cxa_atexit(CUtlVector<char*>::~CUtlVector,&g_fallbackLocalizationFiles,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_g_ServerRemoteAccess  @ 0005a920
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_ServerRemoteAccess(void)

{
  CServerRemoteAccess::CServerRemoteAccess(&g_ServerRemoteAccess);
  __cxa_atexit(CServerRemoteAccess::~CServerRemoteAccess,&g_ServerRemoteAccess,&__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateCServerRemoteAccessIGameServerData_reg,
             __CreateCServerRemoteAccessIGameServerData_interface,"GameServerData001");
  return;
}


// _GLOBAL__sub_I_game  @ 0005a8a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_game(void)

{
  g_Game.super_IGame._vptr_IGame = (_func_int_varargs **)&PTR__CGame_000e8a68;
  g_Game.m_bActiveApp = true;
  __cxa_atexit(CGame::~CGame,&g_Game,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_registry  @ 0005aad0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_registry(void)

{
  g_Registry.super_IRegistry._vptr_IRegistry = (_func_int_varargs **)&PTR_Init_000ee2c8;
  g_Registry.m_bValid = false;
  g_Registry.m_hKey = 0;
  __cxa_atexit(CRegistry::~CRegistry,&g_Registry,&__dso_handle);
  return;
}


// _Host_Frame  @ 00075240
void _Host_Frame(float time)

{
  bool bVar1;
  int iVar2;
  qboolean qVar3;
  
  iVar2 = _setjmp((__jmp_buf_tag *)host_enddemo);
  if (iVar2 != 0) {
    return;
  }
  qVar3 = Host_FilterTime(time);
  if (qVar3 == false) {
    return;
  }
  SystemWrapper_RunFrame(host_frametime);
  if (g_modfuncs.m_pfnFrameBegin != (PFN_FRAMEBEGIN)0x0) {
    (*g_modfuncs.m_pfnFrameBegin)();
  }
  rolling_fps = host_frametime * 0.4 + rolling_fps * 0.6;
  R_SetStackBase();
  CL_CheckClientState();
  Cbuf_Execute();
  ClientDLL_UpdateClientData();
  if (sv.active != false) {
    CL_Move();
  }
  _Host_Frame::host_times[1] = Sys_FloatTime();
  SV_Frame();
  _Host_Frame::host_times[2] = Sys_FloatTime();
  SV_CheckForRcon();
  if (sv.active == false) {
    CL_Move();
  }
  ClientDLL_Frame(host_frametime);
  CL_SetLastUpdate();
  CL_ReadPackets();
  CL_RedoPrediction();
  CL_VoiceIdle();
  CL_EmitEntities();
  CL_CheckForResend();
  do {
    qVar3 = CL_RequestMissingResources();
  } while (qVar3 != false);
  CL_UpdateSoundFade();
  if ((cls.state == ca_disconnected) && ((((byte)giSubState & 4) != 0 || (console.value == 0.0)))) {
    bVar1 = 0 < Host_CheckConnectionFailure::frames;
    Host_CheckConnectionFailure::frames = Host_CheckConnectionFailure::frames + -1;
    if (bVar1) goto LAB_00075366;
    giActive = 2;
  }
  Host_CheckConnectionFailure::frames = 5;
LAB_00075366:
  CL_HTTPUpdate();
  Steam_ClientRunFrame();
  ClientDLL_CAM_Think();
  CL_MoveSpectatorCamera();
  _Host_Frame::host_times[3] = Sys_FloatTime();
  if (((gfBackground == false) && (SCR_UpdateScreen(), cl_inmovie != false)) &&
     (scr_con_current == 0.0)) {
    VID_WriteBuffer((char *)0x0);
  }
  _Host_Frame::host_times[4] = Sys_FloatTime();
  CL_DecayLights();
  if (gfBackground == false) {
    S_PrintStats();
  }
  _Host_Frame::host_times[0] = _Host_Frame::host_times[5];
  _Host_Frame::host_times[5] = Sys_FloatTime();
                    /* Unresolved local var: float pass1@[???]
                       Unresolved local var: float pass2@[???]
                       Unresolved local var: float pass3@[???]
                       Unresolved local var: float pass4@[???]
                       Unresolved local var: float pass5@[???]
                       Unresolved local var: double frameTime@[???]
                       Unresolved local var: double fps@[???] */
  if (host_speeds.value != 0.0) {
                    /* Unresolved local var: int ent_count@[???]
                       Unresolved local var: int i@[???] */
    if (0 < sv.num_edicts) {
      iVar2 = 0;
      do {
        iVar2 = iVar2 + 1;
      } while (iVar2 != sv.num_edicts);
    }
    Con_Printf("%3i fps -- host(%3.0f) sv(%3.0f) cl(%3.0f) gfx(%3.0f) snd(%3.0f) ents(%d)\n");
  }
  host_framecount = host_framecount + 1;
  CL_AdjustClock();
  if (sv_stats.value == 1.0) {
    Host_UpdateStats();
  }
  if ((host_killtime.value != 0.0) && (host_killtime.value < (float)sv.time)) {
    Host_Quit_f();
  }
  return;
}


// _PM_PlayerTrace  @ 00089c80
pmtrace_t * __regparm3
_PM_PlayerTrace(pmtrace_t *__return_storage_ptr__,vec_t *start,vec_t *end,int traceFlags,
               int numphysent,physent_t *physents,int ignore_pe,_func_int_physent_t_ptr *pfnIgnore)

{
  int iVar1;
  model_t *pModel;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  bool bVar8;
  vec_t vVar9;
  vec_t vVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  hull_t *hull;
  int local_174;
  physent_t *local_170;
  int local_16c;
  pmtrace_t local_15c;
  float local_10c [5];
  vec_t local_f8;
  vec_t local_f4;
  vec_t local_f0;
  physent_t *local_dc;
  pmtrace_t local_bc;
  float local_6c;
  float local_68;
  float local_64;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  int local_2c [7];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: pmtrace_t trace@[???]
                       Unresolved local var: pmtrace_t total@[???]
                       Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: vec3_t start_l@[???]
                       Unresolved local var: vec3_t end_l@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: physent_t * pe@[???]
                       Unresolved local var: qboolean rotated@[???]
                       Unresolved local var: int numhulls@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???] */
  Q_memset(local_10c,0,0x44);
  local_dc = (physent_t *)0xffffffff;
  local_10c[4] = 1.0;
  local_f8 = *end;
  local_f4 = end[1];
  local_f0 = end[2];
  if (0 < traceFlags) {
    local_170 = (physent_t *)0x0;
    local_174 = numphysent;
    do {
      if (ignore_pe == 0) {
        if ((local_170 != physents) || (physents == (physent_t *)0xffffffff)) goto LAB_00089d35;
      }
      else {
        iVar11 = (*(code *)ignore_pe)(local_174);
        if (iVar11 == 0) {
LAB_00089d35:
          iVar11 = *(int *)(local_174 + 0x30);
          if (iVar11 == 0) {
            local_6c = *(float *)(local_174 + 0x24);
            local_2c[0] = 1;
            local_68 = *(float *)(local_174 + 0x28);
            local_64 = *(float *)(local_174 + 0x2c);
            pModel = *(model_t **)(local_174 + 0x34);
            if (pModel == (model_t *)0x0) {
              iVar11 = pmove->usehull;
            }
            else if (pModel->type == mod_studio) {
              if (((pModel->flags & 0x200) != 0) || (iVar11 = pmove->usehull, iVar11 == 2)) {
                hull = PM_HullForStudioModel
                                 (pModel,&local_6c,*(float *)(local_174 + 0x6c),
                                  *(int *)(local_174 + 0x70),(vec_t *)(local_174 + 0x54),
                                  (vec_t *)(local_174 + 0x24),(uchar *)(local_174 + 0x74),
                                  (uchar *)(local_174 + 0x78),local_2c);
                iVar13 = *(int *)(local_174 + 0x60);
                goto LAB_00089de6;
              }
            }
            else {
              iVar11 = pmove->usehull;
            }
            hull = &box_hull;
            box_planes[1].dist = *(float *)(local_174 + 0x38) - player_maxs[iVar11][0];
            box_planes[3].dist = *(float *)(local_174 + 0x3c) - player_maxs[iVar11][1];
            box_planes[5].dist = *(float *)(local_174 + 0x40) - player_maxs[iVar11][2];
            box_planes[2].dist = *(float *)(local_174 + 0x48) - player_mins[iVar11][1];
            box_planes[4].dist = *(float *)(local_174 + 0x4c) - player_mins[iVar11][2];
            box_planes[0].dist = *(float *)(local_174 + 0x44) - player_mins[iVar11][0];
            iVar13 = *(int *)(local_174 + 0x60);
          }
          else {
            iVar13 = *(int *)(local_174 + 0x60);
            if ((iVar13 == 0) && (*(int *)(local_174 + 100) != 0)) goto LAB_0008a070;
            local_2c[0] = 1;
            iVar1 = pmove->usehull;
            hull = (hull_t *)(iVar11 + 0xd0);
            if ((iVar1 != 2) && (hull = (hull_t *)(iVar11 + 0x120), iVar1 != 3)) {
              hull = (hull_t *)(iVar11 + 0xf8);
              if (iVar1 == 1) {
                hull = (hull_t *)(iVar11 + 0x148);
              }
            }
            local_6c = (hull->clip_mins[0] - player_mins[iVar1][0]) + *(float *)(local_174 + 0x24);
            local_68 = (hull->clip_mins[1] - player_mins[iVar1][1]) + *(float *)(local_174 + 0x28);
            local_64 = (hull->clip_mins[2] - player_mins[iVar1][2]) + *(float *)(local_174 + 0x2c);
          }
LAB_00089de6:
          bVar8 = false;
          local_5c = *start - local_6c;
          local_58 = start[1] - local_68;
          local_54 = start[2] - local_64;
          local_50 = *end - local_6c;
          local_4c = end[1] - local_68;
          local_48 = end[2] - local_64;
          if ((iVar13 == 4) &&
             (((*(float *)(local_174 + 0x54) != 0.0 || (*(float *)(local_174 + 0x58) != 0.0)) ||
              (*(float *)(local_174 + 0x5c) != 0.0)))) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t temp@[???] */
            AngleVectors((vec_t *)(local_174 + 0x54),(vec_t *)&local_bc,&local_44,&local_38);
            bVar8 = true;
            fVar4 = local_54 * (float)local_bc.inopen;
            fVar2 = local_44 * local_5c;
            fVar3 = local_3c * local_54;
            local_54 = local_54 * local_30 + local_58 * local_34 + local_5c * local_38;
            fVar5 = (float)local_bc.inopen * local_48;
            fVar6 = local_44 * local_50;
            fVar7 = local_3c * local_48;
            local_48 = local_48 * local_30 + local_4c * local_34 + local_50 * local_38;
            local_5c = fVar4 + local_58 * (float)local_bc.startsolid +
                               local_5c * (float)local_bc.allsolid;
            local_58 = -(fVar3 + local_40 * local_58 + fVar2);
            local_50 = fVar5 + (float)local_bc.startsolid * local_4c +
                               (float)local_bc.allsolid * local_50;
            local_4c = -(fVar7 + local_40 * local_4c + fVar6);
          }
          Q_memset(&local_15c,0,0x44);
          local_15c.fraction = 1.0;
          local_15c.allsolid = true;
          local_15c.endpos[0] = *end;
          local_15c.endpos[1] = end[1];
          local_15c.endpos[2] = end[2];
          if (local_2c[0] < 1) {
            local_15c.allsolid = false;
LAB_0008a140:
            if (local_15c.startsolid != false) goto LAB_00089fec;
            if (local_15c.fraction != 1.0) goto LAB_00089ffa;
          }
          else {
            if (local_2c[0] == 1) {
              iVar11 = hull->firstclipnode;
              if (-1 < iVar11) {
                if (hull->lastclipnode <= iVar11) {
                  local_15c.allsolid = false;
                  goto LAB_0008a51f;
                }
                PM_RecursiveHullCheck
                          (hull,iVar11,(float)&local_5c,0.0,(vec_t *)0x3f800000,&local_50,&local_15c
                          );
                goto LAB_00089fdb;
              }
                    /* Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: vec3_t mid@[???]
                       Unresolved local var: qboolean retval@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: int otherside@[???]
                       Unresolved local var: float midf@[???] */
              if (iVar11 != -2) {
                local_15c.allsolid = false;
                if (iVar11 != -1) {
                  local_15c.inwater = true;
                  goto LAB_0008a140;
                }
LAB_0008a51f:
                local_15c.allsolid = false;
                local_15c.inopen = true;
                goto LAB_0008a140;
              }
            }
            else {
              iVar11 = 0;
              local_16c = 0;
              do {
                    /* Unresolved local var: int closest@[???]
                       Unresolved local var: pmtrace_t testtrace@[???] */
                Q_memset(&local_bc,0,0x44);
                local_bc.allsolid = true;
                local_bc.fraction = 1.0;
                local_bc.endpos[0] = *end;
                local_bc.endpos[1] = end[1];
                local_bc.endpos[2] = end[2];
                iVar13 = hull->firstclipnode;
                    /* Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: vec3_t mid@[???]
                       Unresolved local var: qboolean retval@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: int otherside@[???]
                       Unresolved local var: float midf@[???] */
                if (iVar13 < 0) {
                  if (iVar13 == -2) {
                    local_bc.startsolid = true;
                  }
                  else {
                    local_bc.allsolid = false;
                    if (iVar13 == -1) goto LAB_0008a0c1;
                    local_bc.inwater = true;
                  }
                }
                else if (iVar13 < hull->lastclipnode) {
                  PM_RecursiveHullCheck
                            (hull,iVar13,(float)&local_5c,0.0,(vec_t *)0x3f800000,&local_50,
                             &local_bc);
                }
                else {
                  local_bc.allsolid = false;
LAB_0008a0c1:
                  local_bc.allsolid = false;
                  local_bc.inopen = true;
                }
                if (((iVar11 == 0) || ((float)local_bc.allsolid != 0.0)) ||
                   (((float)local_bc.startsolid != 0.0 || (local_bc.fraction < local_15c.fraction)))
                   ) {
                  uVar12 = 0;
                  local_16c = iVar11;
                  if (local_15c.startsolid == false) {
                    do {
                      *(undefined4 *)((int)local_15c.endpos + (uVar12 - 0x14)) =
                           *(undefined4 *)((int)local_bc.endpos + (uVar12 - 0x14));
                      uVar12 = uVar12 + 4;
                    } while (uVar12 < 0x44);
                  }
                  else {
                    do {
                      *(undefined4 *)((int)local_15c.endpos + (uVar12 - 0x14)) =
                           *(undefined4 *)((int)local_bc.endpos + (uVar12 - 0x14));
                      uVar12 = uVar12 + 4;
                    } while (uVar12 < 0x44);
                    local_15c.startsolid = true;
                  }
                }
                iVar11 = iVar11 + 1;
                hull = hull + 1;
                local_15c.hitgroup = SV_HitgroupForStudioHull(local_16c);
              } while (iVar11 < local_2c[0]);
LAB_00089fdb:
              if (local_15c.allsolid == false) goto LAB_0008a140;
            }
            local_15c.startsolid = true;
LAB_00089fec:
            local_15c.fraction = 0.0;
LAB_00089ffa:
            if (bVar8) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t temp@[???] */
              AngleVectorsTranspose
                        ((vec_t *)(local_174 + 0x54),&local_38,&local_44,(vec_t *)&local_bc);
              vVar10 = local_15c.plane.normal[1];
              vVar9 = local_15c.plane.normal[0];
              local_15c.plane.normal[0] =
                   local_30 * local_15c.plane.normal[2] +
                   local_34 * local_15c.plane.normal[1] + local_38 * local_15c.plane.normal[0];
              local_15c.plane.normal[1] =
                   local_3c * local_15c.plane.normal[2] +
                   local_40 * local_15c.plane.normal[1] + local_44 * vVar9;
              local_15c.plane.normal[2] =
                   local_15c.plane.normal[2] * (float)local_bc.inopen +
                   vVar10 * (float)local_bc.startsolid + vVar9 * (float)local_bc.allsolid;
            }
            local_15c.endpos[0] = (*end - *start) * local_15c.fraction + *start;
            local_15c.endpos[1] = (end[1] - start[1]) * local_15c.fraction + start[1];
            local_15c.endpos[2] = (end[2] - start[2]) * local_15c.fraction + start[2];
          }
          uVar12 = 0;
          if (local_15c.fraction < local_10c[4]) {
            do {
              *(undefined4 *)((int)local_10c + uVar12) =
                   *(undefined4 *)((int)local_15c.endpos + (uVar12 - 0x14));
              uVar12 = uVar12 + 4;
            } while (uVar12 < 0x44);
            local_dc = local_170;
          }
        }
      }
LAB_0008a070:
      local_170 = (physent_t *)(local_170->name + 1);
      local_174 = local_174 + 0xe0;
    } while (local_170 != (physent_t *)traceFlags);
  }
  uVar12 = 0;
  do {
    *(undefined4 *)((int)__return_storage_ptr__->endpos + (uVar12 - 0x14)) =
         *(undefined4 *)((int)local_10c + uVar12);
    uVar12 = uVar12 + 4;
  } while (uVar12 < 0x44);
  return __return_storage_ptr__;
}


// _PM_PlayerTrace  @ 0008ac80
pmtrace_t *
_PM_PlayerTrace(pmtrace_t *__return_storage_ptr__,vec_t *start,vec_t *end,int traceFlags,
               int numphysent,physent_t *physents,int ignore_pe,_func_int_physent_t_ptr *pfnIgnore)

{
  model_s *pmVar1;
  int num;
  model_t *pModel;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  bool bVar8;
  vec_t vVar9;
  vec_t vVar10;
  int iVar11;
  uint uVar12;
  hull_t *hull;
  physent_t *local_180;
  int local_17c;
  physent_t *local_178;
  int local_174;
  pmtrace_t local_15c;
  float local_10c [5];
  vec_t local_f8;
  vec_t local_f4;
  vec_t local_f0;
  int local_dc;
  pmtrace_t local_bc;
  float local_6c;
  float local_68;
  float local_64;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  int local_2c [7];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: pmtrace_t trace@[???]
                       Unresolved local var: pmtrace_t total@[???]
                       Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: vec3_t start_l@[???]
                       Unresolved local var: vec3_t end_l@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: physent_t * pe@[???]
                       Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: qboolean rotated@[???]
                       Unresolved local var: int numhulls@[???]
                       Unresolved local var: int j@[???] */
  Q_memset(local_10c,0,0x44);
  local_10c[4] = 1.0;
  local_dc = -1;
  local_f8 = *end;
  local_f4 = end[1];
  local_f0 = end[2];
  if (numphysent < 1) {
LAB_0008b370:
    uVar12 = 0;
    do {
      *(undefined4 *)((int)__return_storage_ptr__->endpos + (uVar12 - 0x14)) =
           *(undefined4 *)((int)local_10c + uVar12);
      uVar12 = uVar12 + 4;
    } while (uVar12 < 0x44);
    return __return_storage_ptr__;
  }
  local_17c = 0;
  local_178 = physents + 1;
  local_180 = physents;
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t temp@[???] */
  if (pfnIgnore == (_func_int_physent_t_ptr *)0x0) goto LAB_0008b128;
LAB_0008ad50:
  iVar11 = (*pfnIgnore)(local_180);
  if (iVar11 != 0) goto LAB_0008b0e0;
  do {
    pmVar1 = local_180->model;
    if ((((pmVar1 == (model_s *)0x0) || (local_180->solid != 0)) || (local_180->skin == 0)) &&
       (((traceFlags & 4U) == 0 || (local_180->rendermode == 0)))) {
      local_2c[0] = 1;
      local_6c = local_180->origin[0];
      local_68 = local_180->origin[1];
      local_64 = local_180->origin[2];
      if (pmVar1 == (model_s *)0x0) {
        pModel = local_180->studiomodel;
        if (pModel == (model_t *)0x0) {
          iVar11 = pmove->usehull;
        }
        else {
          if ((traceFlags & 1U) != 0) goto LAB_0008b0e0;
          if (pModel->type == mod_studio) {
            if (((pModel->flags & 0x200) != 0) ||
               ((iVar11 = pmove->usehull, iVar11 == 2 && ((traceFlags & 2U) == 0)))) {
              hull = PM_HullForStudioModel
                               (pModel,&local_6c,local_180->frame,local_180->sequence,
                                local_180->angles,local_180->origin,local_180->controller,
                                local_180->blending,local_2c);
              goto LAB_0008ae4b;
            }
          }
          else {
            iVar11 = pmove->usehull;
          }
        }
        hull = &box_hull;
        box_planes[1].dist = local_180->mins[0] - player_maxs[iVar11][0];
        box_planes[3].dist = local_180->mins[1] - player_maxs[iVar11][1];
        box_planes[5].dist = local_180->mins[2] - player_maxs[iVar11][2];
        box_planes[2].dist = local_180->maxs[1] - player_mins[iVar11][1];
        box_planes[4].dist = local_180->maxs[2] - player_mins[iVar11][2];
        box_planes[0].dist = local_180->maxs[0] - player_mins[iVar11][0];
      }
      else {
        iVar11 = pmove->usehull;
        hull = pmVar1->hulls;
        if ((iVar11 != 2) && (hull = pmVar1->hulls + 2, iVar11 != 3)) {
          hull = pmVar1->hulls + 1;
          if (iVar11 == 1) {
            hull = pmVar1->hulls + 3;
          }
        }
        local_6c = (hull->clip_mins[0] - player_mins[iVar11][0]) + local_6c;
        local_68 = local_68 + (hull->clip_mins[1] - player_mins[iVar11][1]);
        local_64 = local_64 + (hull->clip_mins[2] - player_mins[iVar11][2]);
      }
LAB_0008ae4b:
      local_5c = *start - local_6c;
      local_58 = start[1] - local_68;
      local_54 = start[2] - local_64;
      bVar8 = false;
      local_50 = *end - local_6c;
      local_4c = end[1] - local_68;
      local_48 = end[2] - local_64;
      if ((local_180->solid == 4) &&
         (((local_180->angles[0] != 0.0 || (local_180->angles[1] != 0.0)) ||
          (local_180->angles[2] != 0.0)))) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t temp@[???] */
        AngleVectors(local_180->angles,(vec_t *)&local_bc,&local_44,&local_38);
        bVar8 = true;
        fVar4 = local_54 * (float)local_bc.inopen;
        fVar2 = local_44 * local_5c;
        fVar3 = local_3c * local_54;
        local_54 = local_54 * local_30 + local_58 * local_34 + local_5c * local_38;
        fVar5 = (float)local_bc.inopen * local_48;
        fVar6 = local_44 * local_50;
        fVar7 = local_3c * local_48;
        local_48 = local_48 * local_30 + local_4c * local_34 + local_50 * local_38;
        local_5c = fVar4 + local_58 * (float)local_bc.startsolid +
                           local_5c * (float)local_bc.allsolid;
        local_58 = -(fVar3 + local_40 * local_58 + fVar2);
        local_50 = fVar5 + (float)local_bc.startsolid * local_4c +
                           (float)local_bc.allsolid * local_50;
        local_4c = -(fVar7 + local_40 * local_4c + fVar6);
      }
      Q_memset(&local_15c,0,0x44);
      local_15c.allsolid = true;
      local_15c.fraction = 1.0;
      local_15c.endpos[0] = *end;
      local_15c.endpos[1] = end[1];
      local_15c.endpos[2] = end[2];
      if (local_2c[0] < 1) {
        local_15c.allsolid = false;
LAB_0008b1b0:
        if (local_15c.startsolid != false) goto LAB_0008b04c;
        if (local_15c.fraction != 1.0) goto LAB_0008b05a;
      }
      else {
        if (local_2c[0] == 1) {
          iVar11 = hull->firstclipnode;
          if (-1 < iVar11) {
            if (hull->lastclipnode <= iVar11) {
              local_15c.allsolid = false;
              goto LAB_0008b59a;
            }
            PM_RecursiveHullCheck
                      (hull,iVar11,(float)&local_5c,0.0,(vec_t *)0x3f800000,&local_50,&local_15c);
            goto LAB_0008b03b;
          }
                    /* Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: vec3_t mid@[???]
                       Unresolved local var: qboolean retval@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: int otherside@[???]
                       Unresolved local var: float midf@[???] */
          if (iVar11 != -2) {
            local_15c.allsolid = false;
            if (iVar11 != -1) {
              local_15c.inwater = true;
              goto LAB_0008b1b0;
            }
LAB_0008b59a:
            local_15c.allsolid = false;
            local_15c.inopen = true;
            goto LAB_0008b1b0;
          }
        }
        else {
          iVar11 = 0;
          local_174 = 0;
          do {
                    /* Unresolved local var: int closest@[???]
                       Unresolved local var: pmtrace_t testtrace@[???] */
            Q_memset(&local_bc,0,0x44);
            local_bc.allsolid = true;
            local_bc.fraction = 1.0;
            local_bc.endpos[0] = *end;
            local_bc.endpos[1] = end[1];
            local_bc.endpos[2] = end[2];
            num = hull->firstclipnode;
                    /* Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: vec3_t mid@[???]
                       Unresolved local var: qboolean retval@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: int otherside@[???]
                       Unresolved local var: float midf@[???] */
            if (num < 0) {
              if (num == -2) {
                local_bc.startsolid = true;
              }
              else {
                local_bc.allsolid = false;
                if (num == -1) goto LAB_0008b151;
                local_bc.inwater = true;
              }
            }
            else if (num < hull->lastclipnode) {
              PM_RecursiveHullCheck
                        (hull,num,(float)&local_5c,0.0,(vec_t *)0x3f800000,&local_50,&local_bc);
            }
            else {
              local_bc.allsolid = false;
LAB_0008b151:
              local_bc.allsolid = false;
              local_bc.inopen = true;
            }
            if (((iVar11 == 0) || ((float)local_bc.allsolid != 0.0)) ||
               (((float)local_bc.startsolid != 0.0 || (local_bc.fraction < local_15c.fraction)))) {
              uVar12 = 0;
              local_174 = iVar11;
              if (local_15c.startsolid == false) {
                do {
                  *(undefined4 *)((int)local_15c.endpos + (uVar12 - 0x14)) =
                       *(undefined4 *)((int)local_bc.endpos + (uVar12 - 0x14));
                  uVar12 = uVar12 + 4;
                } while (uVar12 < 0x44);
              }
              else {
                do {
                  *(undefined4 *)((int)local_15c.endpos + (uVar12 - 0x14)) =
                       *(undefined4 *)((int)local_bc.endpos + (uVar12 - 0x14));
                  uVar12 = uVar12 + 4;
                } while (uVar12 < 0x44);
                local_15c.startsolid = true;
              }
            }
            iVar11 = iVar11 + 1;
            hull = hull + 1;
            local_15c.hitgroup = SV_HitgroupForStudioHull(local_174);
          } while (iVar11 < local_2c[0]);
LAB_0008b03b:
          if (local_15c.allsolid == false) goto LAB_0008b1b0;
        }
        local_15c.startsolid = true;
LAB_0008b04c:
        local_15c.fraction = 0.0;
LAB_0008b05a:
        if (bVar8) {
          AngleVectorsTranspose(local_180->angles,&local_38,&local_44,(vec_t *)&local_bc);
          vVar10 = local_15c.plane.normal[1];
          vVar9 = local_15c.plane.normal[0];
          local_15c.plane.normal[0] =
               local_30 * local_15c.plane.normal[2] +
               local_34 * local_15c.plane.normal[1] + local_38 * local_15c.plane.normal[0];
          local_15c.plane.normal[1] =
               local_3c * local_15c.plane.normal[2] +
               local_40 * local_15c.plane.normal[1] + local_44 * vVar9;
          local_15c.plane.normal[2] =
               local_15c.plane.normal[2] * (float)local_bc.inopen +
               vVar10 * (float)local_bc.startsolid + vVar9 * (float)local_bc.allsolid;
        }
        local_15c.endpos[0] = (*end - *start) * local_15c.fraction + *start;
        local_15c.endpos[1] = (end[1] - start[1]) * local_15c.fraction + start[1];
        local_15c.endpos[2] = (end[2] - start[2]) * local_15c.fraction + start[2];
      }
      uVar12 = 0;
      if (local_15c.fraction < local_10c[4]) {
        do {
          *(undefined4 *)((int)local_10c + uVar12) =
               *(undefined4 *)((int)local_15c.endpos + (uVar12 - 0x14));
          uVar12 = uVar12 + 4;
        } while (uVar12 < 0x44);
        local_dc = local_17c;
      }
    }
LAB_0008b0e0:
    do {
      local_17c = local_17c + 1;
      if (local_17c == numphysent) goto LAB_0008b370;
      local_180 = local_178;
      if ((local_17c != 0) && ((traceFlags & 8U) != 0)) goto LAB_0008b370;
      local_178 = local_178 + 1;
      if (pfnIgnore != (_func_int_physent_t_ptr *)0x0) goto LAB_0008ad50;
LAB_0008b128:
    } while ((local_17c == ignore_pe) && (ignore_pe != -1));
  } while( true );
}


// _PM_TestPlayerPosition  @ 0008a7b0
int _PM_TestPlayerPosition(vec_t *pos,pmtrace_t *ptrace,_func_int_physent_t_ptr *pfnIgnore)

{
  physent_t *pe;
  model_t *pModel;
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  hull_t *hull;
  _func_int_physent_t_ptr *in_stack_fffffed4;
  int local_104;
  undefined4 auStack_f4 [17];
  pmtrace_t local_b0;
  float local_6c;
  float local_68;
  float local_64;
  vec_t local_5c;
  vec_t local_58;
  vec_t local_54;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  int local_2c [7];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: physent_t * pe@[???]
                       Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: vec3_t test@[???]
                       Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: qboolean rotated@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int numhulls@[???]
                       Unresolved local var: pmtrace_t tr@[???] */
                    /* Unresolved local var: pmtrace_t tr@[???] */
  _PM_PlayerTrace(&local_b0,pmove->origin,pmove->origin,pmove->numphysent,(int)pmove->physents,
                  (physent_t *)0xffffffff,0,in_stack_fffffed4);
  uVar4 = 0;
  do {
    *(undefined4 *)((int)auStack_f4 + uVar4) =
         *(undefined4 *)((int)local_b0.endpos + (uVar4 - 0x14));
    uVar4 = uVar4 + 4;
  } while (uVar4 < 0x44);
  if (ptrace != (pmtrace_t *)0x0) {
    uVar4 = 0;
    do {
      *(undefined4 *)((int)ptrace->endpos + (uVar4 - 0x14)) =
           *(undefined4 *)((int)auStack_f4 + uVar4);
      uVar4 = uVar4 + 4;
    } while (uVar4 < 0x44);
  }
  if (0 < pmove->numphysent) {
    local_104 = 0;
    do {
      pe = pmove->physents + local_104;
      if ((pfnIgnore == (_func_int_physent_t_ptr *)0x0) || (iVar5 = (*pfnIgnore)(pe), iVar5 == 0)) {
        if (pe->model == (model_s *)0x0) {
          local_5c = pe->origin[0];
          pModel = pe->studiomodel;
          local_58 = pe->origin[1];
          local_2c[0] = 1;
          local_54 = pe->origin[2];
          if ((pModel == (model_t *)0x0) || (pModel->type != mod_studio)) {
            iVar5 = pmove->usehull;
          }
          else if (((pModel->flags & 0x200) != 0) || (iVar5 = pmove->usehull, iVar5 == 2)) {
            hull = PM_HullForStudioModel
                             (pModel,&local_5c,pe->frame,pe->sequence,pe->angles,pe->origin,
                              pe->controller,pe->blending,local_2c);
            goto LAB_0008a8f9;
          }
          box_planes[1].dist = pe->mins[0] - player_maxs[iVar5][0];
          box_planes[3].dist = pe->mins[1] - player_maxs[iVar5][1];
          box_planes[5].dist = pe->mins[2] - player_maxs[iVar5][2];
          box_planes[2].dist = pe->maxs[1] - player_mins[iVar5][1];
          box_planes[4].dist = pe->maxs[2] - player_mins[iVar5][2];
          box_planes[0].dist = pe->maxs[0] - player_mins[iVar5][0];
          hull = &box_hull;
        }
        else {
          if ((pe->solid == 0) && (pe->skin != 0)) goto LAB_0008a9a0;
          local_5c = pe->origin[0];
          local_2c[0] = 1;
          local_58 = pe->origin[1];
          local_54 = pe->origin[2];
          hull = PM_HullForBsp(pe,&local_5c);
        }
LAB_0008a8f9:
        local_6c = *pos - local_5c;
        local_68 = pos[1] - local_58;
        local_64 = pos[2] - local_54;
        if ((pe->solid == 4) &&
           (((pe->angles[0] != 0.0 || (pe->angles[1] != 0.0)) || (pe->angles[2] != 0.0)))) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t temp@[???] */
          AngleVectors(pe->angles,(vec_t *)&local_b0,&local_44,&local_38);
          fVar3 = (float)local_b0.inopen * local_64;
          fVar1 = local_44 * local_6c;
          fVar2 = local_3c * local_64;
          local_64 = local_64 * local_30 + local_68 * local_34 + local_38 * local_6c;
          local_6c = fVar3 + (float)local_b0.startsolid * local_68 +
                             (float)local_b0.allsolid * local_6c;
          local_68 = -(fVar2 + local_40 * local_68 + fVar1);
        }
        if (local_2c[0] == 1) {
          g_contentsresult = PM_HullPointContents(hull,hull->firstclipnode,&local_6c);
          if (g_contentsresult == -2) {
            return local_104;
          }
        }
        else if (0 < local_2c[0]) {
          iVar5 = 0;
          do {
            g_contentsresult = PM_HullPointContents(hull,hull->firstclipnode,&local_6c);
            if (g_contentsresult == -2) {
              return local_104;
            }
            iVar5 = iVar5 + 1;
            hull = hull + 1;
          } while (iVar5 < local_2c[0]);
        }
      }
LAB_0008a9a0:
      local_104 = local_104 + 1;
    } while (local_104 < pmove->numphysent);
  }
  return -1;
}


// _VectorAdd  @ 00080590
void _VectorAdd(vec_t *veca,vec_t *vecb,vec_t *out)

{
  *out = *veca + *vecb;
  out[1] = veca[1] + vecb[1];
  out[2] = veca[2] + vecb[2];
  return;
}


// _VectorCopy  @ 000805c0
void _VectorCopy(vec_t *in,vec_t *out)

{
  *out = *in;
  out[1] = in[1];
  out[2] = in[2];
  return;
}


// _VectorSubtract  @ 00080560
void _VectorSubtract(vec_t *veca,vec_t *vecb,vec_t *out)

{
  *out = *veca - *vecb;
  out[1] = veca[1] - vecb[1];
  out[2] = veca[2] - vecb[2];
  return;
}


// __CreateCDedicatedServerAPIIDedicatedServerAPI_interface  @ 00097aa0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

IBaseInterface * __CreateCDedicatedServerAPIIDedicatedServerAPI_interface(void)

{
  return (IBaseInterface *)&__g_CDedicatedServerAPI_singleton;
}


// __CreateCEngineAPIIEngineAPI_interface  @ 00097a90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

IBaseInterface * __CreateCEngineAPIIEngineAPI_interface(void)

{
  return (IBaseInterface *)&__g_CEngineAPI_singleton;
}


// __CreateCServerRemoteAccessIGameServerData_interface  @ 000c8050
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

IBaseInterface * __CreateCServerRemoteAccessIGameServerData_interface(void)

{
  return (IBaseInterface *)&g_ServerRemoteAccess;
}


// __do_global_ctors_aux  @ 000e0a14
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void __do_global_ctors_aux(void)

{
  undefined **ppuVar1;
  
  for (ppuVar1 = &PTR__GLOBAL__sub_I_registry_00107230; (code *)*ppuVar1 != (code *)0xffffffff;
      ppuVar1 = ppuVar1 + -1) {
    (*(code *)*ppuVar1)();
  }
  return;
}


// __do_global_dtors_aux  @ 0005ab10
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Removing unreachable block (ram,0x0005ab59) */

void __do_global_dtors_aux(void)

{
  if (completed_5793 == '\0') {
    __cxa_finalize(__dso_handle);
    completed_5793 = '\x01';
  }
  return;
}


// __i686.get_pc_thunk.bx  @ 0005abb6
/* WARNING: This is an inlined function */

void __i686_get_pc_thunk_bx(void)

{
  return;
}


// _fini  @ 000e0a3c
void _fini(void)

{
  __do_global_dtors_aux();
  return;
}


// _init  @ 0005a6a0
int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  __gmon_start__();
  frame_dummy();
  iVar1 = __do_global_ctors_aux();
  return iVar1;
}


