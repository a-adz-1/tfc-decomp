// FUN_000358f0  @ 000358f0
void FUN_000358f0(void)

{
  (*(code *)(undefined *)0x0)();
  return;
}


// _DELTA_WriteDelta  @ 00048870
int _DELTA_WriteDelta(uchar *from,uchar *to,qboolean force,delta_t *pFields,_func_void *callback,
                     int sendfields)

{
  uint *puVar1;
  short *psVar2;
  int iVar3;
  uint *dest;
  uint *puVar4;
  int iVar5;
  uint32 data;
  uint local_24 [5];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int bytecount@[???]
                       Unresolved local var: int fieldCount@[???]
                       Unresolved local var: int[2] bits@[???]
                       Unresolved local var: uchar * pdest@[???] */
  if ((sendfields == 0) && (force == false)) {
    return 1;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int bytecount@[???]
                       Unresolved local var: int fieldCount@[???]
                       Unresolved local var: int[2] bits@[???]
                       Unresolved local var: uchar * pdest@[???]
                       Unresolved local var: delta_description_t * pTest@[???]
                       Unresolved local var: int lastbit@[???]
                       Unresolved local var: int bytenumber@[???]
                       Unresolved local var: int bitnumber@[???] */
  dest = local_24;
  Q_memset(dest,0,8);
  iVar3 = pFields->fieldCount + -1;
  if (iVar3 < 0) {
    if (callback == (_func_void *)0x0) {
      MSG_WriteBits(0,3);
      goto LAB_0004894a;
    }
    data = 0;
LAB_00048911:
    (*callback)();
  }
  else {
    iVar5 = -1;
    psVar2 = &pFields->pdd[pFields->fieldCount + -1].flags;
    do {
      if ((*psVar2 & 1) != 0) {
        if (iVar5 == -1) {
          iVar5 = iVar3;
        }
        dest[0x1f < iVar3] = dest[0x1f < iVar3] | 1 << ((byte)iVar3 & 0x1f);
      }
      iVar3 = iVar3 + -1;
      psVar2 = psVar2 + -0x22;
    } while (iVar3 != -1);
    data = (iVar5 >> 3) + 1;
    if (callback != (_func_void *)0x0) goto LAB_00048911;
  }
  puVar1 = (uint *)((int)dest + data);
  MSG_WriteBits(data,3);
  if (data != 0) {
    do {
      puVar4 = (uint *)((int)dest + 1);
      MSG_WriteBits((uint)(byte)*dest,8);
      dest = puVar4;
    } while (puVar4 != puVar1);
  }
LAB_0004894a:
  DELTA_WriteMarkedFields(from,to,pFields);
  return 1;
}


// _DotProduct  @ 00060b20
vec_t _DotProduct(vec_t *v1,vec_t *v2)

{
  return v1[2] * v2[2] + v1[1] * v2[1] + *v1 * *v2;
}


// _GLOBAL__sub_I_CheckIP  @ 00035c60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_CheckIP(void)

{
  CIPRateLimit::CIPRateLimit(&rateChecker);
  __cxa_atexit(CIPRateLimit::~CIPRateLimit,&rateChecker,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_D_SurfaceCacheForRes  @ 00035970
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_D_SurfaceCacheForRes(void)

{
  __cxa_atexit(CEngineAPI::~CEngineAPI,&__g_CEngineAPI_singleton,&__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateCEngineAPIIEngineAPI_reg,__CreateCEngineAPIIEngineAPI_interface,
             "VENGINE_LAUNCHER_API_VERSION002");
  __g_CDedicatedServerAPI_singleton.super_IDedicatedServerAPI.super_IBaseInterface.
  _vptr_IBaseInterface = (IBaseInterface)&PTR__CDedicatedServerAPI_000d7dac;
  __cxa_atexit(CDedicatedServerAPI::~CDedicatedServerAPI,&__g_CDedicatedServerAPI_singleton,
               &__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateCDedicatedServerAPIIDedicatedServerAPI_reg,
             __CreateCDedicatedServerAPIIDedicatedServerAPI_interface,"VENGINE_HLDS_API_VERSION002")
  ;
  return;
}


// _GLOBAL__sub_I__Z15COM_BuildNumberv  @ 00035a00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__Z15COM_BuildNumberv(void)

{
  int in_stack_ffffffe8;
  void **in_stack_ffffffec;
  
  SystemWrapper::SystemWrapper(&gSystemWrapper,in_stack_ffffffe8,in_stack_ffffffec);
  __cxa_atexit(SystemWrapper::~SystemWrapper,&gSystemWrapper,&__dso_handle);
  return;
}


// _GLOBAL__sub_I__ZN12CInitTrackerC2Ev  @ 00035af0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN12CInitTrackerC2Ev(void)

{
  g_InitTracker.m_Funcs[0].m_Memory.m_pMemory = (InitFunc **)0x0;
  g_InitTracker.m_Funcs[0].m_Size = 0;
  g_InitTracker.m_Funcs[1].m_Memory.m_pMemory = (InitFunc **)0x0;
  g_InitTracker.m_Funcs[1].m_Memory.m_NumAllocated = 0;
  g_InitTracker.m_Funcs[1].m_Memory.m_GrowSize = 0;
  g_InitTracker.m_Funcs[1].m_Size = 0;
  g_InitTracker.m_Funcs[2].m_Memory.m_pMemory = (InitFunc **)0x0;
  g_InitTracker.m_Funcs[2].m_Size = 0;
  g_InitTracker.m_Funcs[3].m_Memory.m_pMemory = (InitFunc **)0x0;
  g_InitTracker.m_Funcs[3].m_Memory.m_NumAllocated = 0;
  g_InitTracker.m_Funcs[3].m_Memory.m_GrowSize = 0;
  g_InitTracker.m_Funcs[3].m_Size = 0;
                    /* Unresolved local var: int l@[???] */
  g_InitTracker.m_nNumFuncs[0] = 0;
  g_InitTracker.m_nNumFuncs[3] = 0;
  g_InitTracker.m_Funcs[0].m_Memory.m_NumAllocated = 0;
  g_InitTracker.m_Funcs[0].m_Memory.m_GrowSize = 0;
  g_InitTracker.m_Funcs[2].m_Memory.m_NumAllocated = 0;
  g_InitTracker.m_Funcs[2].m_Memory.m_GrowSize = 0;
  g_InitTracker.m_nNumFuncs[1] = 0;
  g_InitTracker.m_nNumFuncs[2] = 0;
  __cxa_atexit(CInitTracker::~CInitTracker,&g_InitTracker,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_eng  @ 00035a40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_eng(void)

{
  g_Engine.super_IEngine._vptr_IEngine = (_func_int_varargs **)&PTR__CEngine_000d885c;
  g_Engine.m_nTrapKey = 0;
  g_Engine.m_nTrapButtons = 0;
  g_Engine.m_fFrameTime = 0.0;
  g_Engine.m_nQuitting = 0;
  g_Engine.m_nSubState = 0;
  g_Engine.m_nDLLState = 0;
  g_Engine.m_fOldTime = 0.0;
  g_Engine.m_bTrapMode = false;
  g_Engine.m_bDoneTrapping = false;
  __cxa_atexit(CEngine::~CEngine,&g_Engine,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_g_FileSystemFactory  @ 00035920
void processEntry _GLOBAL__sub_I_g_FileSystemFactory(void)

{
  g_fallbackLocalizationFiles.m_Memory.m_pMemory = (char **)0x0;
  g_fallbackLocalizationFiles.m_Size = 0;
  g_fallbackLocalizationFiles.m_Memory.m_NumAllocated = 0;
  g_fallbackLocalizationFiles.m_Memory.m_GrowSize = 0;
  __cxa_atexit(CUtlVector<char*>::~CUtlVector,&g_fallbackLocalizationFiles,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_g_ServerRemoteAccess  @ 00035bb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_ServerRemoteAccess(void)

{
  g_ServerRemoteAccess.super_IGameServerData.super_IBaseInterface._vptr_IBaseInterface =
       (IBaseInterface)&PTR__CServerRemoteAccess_000dd08c;
  g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_GrowSize = 0;
  g_ServerRemoteAccess.m_ResponsePackets.m_Head = -1;
  g_ServerRemoteAccess.m_ResponsePackets.m_Tail = -1;
  g_ServerRemoteAccess.m_ResponsePackets.m_FirstFree = -1;
  g_ServerRemoteAccess.m_ResponsePackets.m_TotalElements = 0;
  g_ServerRemoteAccess.m_ResponsePackets.m_ElementCount = 0;
  g_ServerRemoteAccess.m_iBytesReceived = 0;
  g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_pMemory = (ListElem_t *)0x0;
  g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_NumAllocated = 0;
  g_ServerRemoteAccess.m_ResponsePackets.m_pElements = (ListElem_t *)0x0;
  g_ServerRemoteAccess.m_iBytesSent = 0;
  __cxa_atexit(CServerRemoteAccess::~CServerRemoteAccess,&g_ServerRemoteAccess,&__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateCServerRemoteAccessIGameServerData_reg,
             __CreateCServerRemoteAccessIGameServerData_interface,"GameServerData001");
  return;
}


// _GLOBAL__sub_I_g_nFakeIP  @ 00035ca0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_nFakeIP(void)

{
  g_SteamDebugOutputQueue.
  super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl._M_start =
       (pointer)0x0;
  g_SteamDebugOutputQueue.
  super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl._M_finish =
       (pointer)0x0;
  g_SteamDebugOutputQueue.
  super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl.
  _M_end_of_storage = (pointer)0x0;
  __cxa_atexit(std::vector<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>::~vector,
               &g_SteamDebugOutputQueue,&__dso_handle);
  CSteam3Client::CSteam3Client(&s_Steam3Client);
  __cxa_atexit(CSteam3Client::~CSteam3Client,&s_Steam3Client,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_game  @ 00035ab0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_game(void)

{
  g_Game.super_IGame._vptr_IGame = (_func_int_varargs **)&PTR__CGame_000d88d4;
  g_Game.m_bActiveApp = true;
  __cxa_atexit(CGame::~CGame,&g_Game,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_registry  @ 00035d10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_registry(void)

{
  g_Registry.super_IRegistry._vptr_IRegistry = (_func_int_varargs **)&PTR_Shutdown_000debe8;
  g_Registry.m_bValid = false;
  g_Registry.m_hKey = 0;
  __cxa_atexit(CRegistry::~CRegistry,&g_Registry,&__dso_handle);
  return;
}


// _Host_Frame  @ 00054c10
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
    if (bVar1) goto LAB_00054d35;
    giActive = 2;
  }
  Host_CheckConnectionFailure::frames = 5;
LAB_00054d35:
  CL_HTTPUpdate();
  Steam_ClientRunFrame();
  ClientDLL_CAM_Think();
  CL_MoveSpectatorCamera();
  _Host_Frame::host_times[3] = Sys_FloatTime();
  if (((gfBackground == false) && (SCR_UpdateScreen(), cl_inmovie != false)) &&
     (scr_con_current == 0.0)) {
    VID_WriteBuffer(0);
  }
  _Host_Frame::host_times[4] = Sys_FloatTime();
  CL_DecayLights();
  if (gfBackground == false) {
    S_PrintStats();
  }
  _Host_Frame::host_times[0] = _Host_Frame::host_times[5];
  _Host_Frame::host_times[5] = Sys_FloatTime();
  Host_Speeds(_Host_Frame::host_times);
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


// _PM_PlayerTrace  @ 0006c0e0
pmtrace_t *
_PM_PlayerTrace(pmtrace_t *__return_storage_ptr__,vec_t *start,vec_t *end,int traceFlags,
               int numphysent,physent_t *physents,int ignore_pe,_func_int_physent_t_ptr *pfnIgnore)

{
  float fVar1;
  float fVar2;
  float fVar3;
  model_s *pmVar4;
  int num;
  model_t *pModel;
  float fVar5;
  float fVar6;
  float fVar7;
  bool bVar8;
  vec_t vVar9;
  int iVar10;
  uint uVar11;
  vec_t vVar12;
  hull_t *hull;
  vec_t *angles;
  vec_t *pvVar13;
  int iVar14;
  int local_138;
  int local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  pmtrace_t local_e8;
  float local_a4 [5];
  vec_t local_90;
  vec_t local_8c;
  vec_t local_88;
  int local_74;
  pmtrace_t local_60;
  
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
  Q_memset(local_a4,0,0x44);
  local_a4[4] = 1.0;
  local_90 = *end;
  local_74 = -1;
  local_8c = end[1];
  local_88 = end[2];
  if (numphysent < 1) {
LAB_0006c610:
    uVar11 = 0;
    do {
      *(undefined4 *)((int)__return_storage_ptr__->endpos + (uVar11 - 0x14)) =
           *(undefined4 *)((int)local_a4 + uVar11);
      uVar11 = uVar11 + 4;
    } while (uVar11 < 0x44);
    return __return_storage_ptr__;
  }
  angles = physents->angles;
  local_138 = 0;
  if (pfnIgnore == (_func_int_physent_t_ptr *)0x0) goto LAB_0006c551;
LAB_0006c1b0:
  iVar10 = (*pfnIgnore)(physents);
  if (iVar10 != 0) goto LAB_0006c510;
  do {
    pmVar4 = (model_s *)angles[-9];
    if (pmVar4 == (model_s *)0x0) {
      if (((traceFlags & 4U) == 0) || (angles[5] == 0.0)) {
        pModel = (model_t *)angles[-8];
        fVar1 = angles[-0xc];
        fVar2 = angles[-0xb];
        fVar3 = angles[-10];
        local_11c = 1;
        if (pModel == (model_t *)0x0) {
LAB_0006c7f4:
          iVar10 = pmove->usehull;
LAB_0006c7fa:
          hull = &box_hull;
          box_planes[1].dist = angles[-7] - player_maxs[iVar10][0];
          box_planes[3].dist = angles[-6] - player_maxs[iVar10][1];
          box_planes[5].dist = angles[-5] - player_maxs[iVar10][2];
          box_planes[2].dist = angles[-3] - player_mins[iVar10][1];
          box_planes[4].dist = angles[-2] - player_mins[iVar10][2];
          box_planes[0].dist = angles[-4] - player_mins[iVar10][0];
          vVar12 = angles[3];
        }
        else {
          if ((traceFlags & 1U) != 0) goto LAB_0006c510;
          if (pModel->type != mod_studio) goto LAB_0006c7f4;
          iVar10 = pmove->usehull;
          if (((pModel->flags & 0x200) == 0) && ((iVar10 != 2 || ((traceFlags & 2U) != 0))))
          goto LAB_0006c7fa;
                    /* Unresolved local var: vec3_t size@[???] */
          vVar12 = angles[7];
          local_60.allsolid = (qboolean)(player_maxs[iVar10][0] - player_mins[iVar10][0]);
          fVar1 = angles[6];
          local_60.startsolid = (qboolean)(player_maxs[iVar10][1] - player_mins[iVar10][1]);
          local_60.inopen = (qboolean)(player_maxs[iVar10][2] - player_mins[iVar10][2]);
          VectorScale((vec_t *)&local_60,0.5,(vec_t *)&local_60);
          hull = R_StudioHull(pModel,fVar1,(int)vVar12,angles,angles + -0xc,(vec_t *)&local_60,
                              (byte *)(angles + 8),(byte *)(angles + 9),&local_11c,(edict_t *)0x0,0)
          ;
          vVar12 = angles[3];
          fVar1 = 0.0;
          fVar2 = 0.0;
          fVar3 = 0.0;
        }
        goto LAB_0006c264;
      }
    }
    else {
      vVar12 = angles[3];
      if ((vVar12 != 0.0) || (angles[4] == 0.0)) {
        if ((traceFlags & 4U) == 0) {
          fVar1 = angles[-0xc];
          fVar2 = angles[-0xb];
          fVar3 = angles[-10];
        }
        else {
          if (angles[5] != 0.0) goto LAB_0006c510;
          fVar1 = angles[-0xc];
          fVar2 = angles[-0xb];
          fVar3 = angles[-10];
        }
        local_11c = 1;
        iVar10 = pmove->usehull;
        if (iVar10 == 2) {
          hull = pmVar4->hulls;
        }
        else if (iVar10 == 3) {
          hull = pmVar4->hulls + 2;
        }
        else {
          hull = pmVar4->hulls + 1;
          if (iVar10 == 1) {
            hull = pmVar4->hulls + 3;
          }
        }
        fVar1 = (hull->clip_mins[0] - player_mins[iVar10][0]) + fVar1;
        fVar2 = (hull->clip_mins[1] - player_mins[iVar10][1]) + fVar2;
        fVar3 = (hull->clip_mins[2] - player_mins[iVar10][2]) + fVar3;
LAB_0006c264:
        local_118 = *start - fVar1;
        local_114 = start[1] - fVar2;
        local_110 = start[2] - fVar3;
        bVar8 = false;
        local_10c = *end - fVar1;
        local_108 = end[1] - fVar2;
        local_104 = end[2] - fVar3;
        if ((vVar12 == 5.60519e-45) &&
           (((*angles != 0.0 || (angles[1] != 0.0)) || (angles[2] != 0.0)))) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t temp@[???] */
          AngleVectors(angles,&local_100,&local_f4,(vec_t *)&local_60);
          fVar3 = local_f8 * local_110;
          fVar1 = local_f4 * local_118;
          fVar2 = local_ec * local_110;
          local_110 = local_110 * (float)local_60.inopen +
                      local_114 * (float)local_60.startsolid + local_118 * (float)local_60.allsolid;
          fVar7 = local_f8 * local_104;
          fVar5 = local_f4 * local_10c;
          fVar6 = local_ec * local_104;
          local_104 = (float)local_60.inopen * local_104 +
                      local_108 * (float)local_60.startsolid + (float)local_60.allsolid * local_10c;
          bVar8 = true;
          local_118 = fVar3 + local_fc * local_114 + local_100 * local_118;
          local_114 = -(fVar2 + local_f0 * local_114 + fVar1);
          local_10c = fVar7 + local_fc * local_108 + local_100 * local_10c;
          local_108 = -(fVar6 + local_f0 * local_108 + fVar5);
        }
        Q_memset(&local_e8,0,0x44);
        local_e8.allsolid = true;
        local_e8.fraction = 1.0;
        local_e8.endpos[0] = *end;
        local_e8.endpos[1] = end[1];
        local_e8.endpos[2] = end[2];
        if (local_11c < 1) {
          local_e8.allsolid = false;
LAB_0006c881:
          local_e8.allsolid = false;
          if (local_e8.startsolid != false) {
LAB_0006c46c:
            local_e8.fraction = 0.0;
            goto LAB_0006c479;
          }
        }
        else {
          if (local_11c == 1) {
            iVar10 = hull->firstclipnode;
                    /* Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t mid@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: int otherside@[???]
                       Unresolved local var: float midf@[???]
                       Unresolved local var: qboolean retval@[???] */
            if (-1 < iVar10) {
              if (hull->lastclipnode <= iVar10) {
                local_e8.allsolid = false;
                goto LAB_0006c9f8;
              }
              PM_RecursiveHullCheck
                        (hull,iVar10,(float)&local_118,0.0,(vec_t *)0x3f800000,&local_10c,&local_e8)
              ;
              goto LAB_0006c451;
            }
            if (iVar10 != -2) {
              local_e8.allsolid = false;
              if (iVar10 != -1) {
                local_e8.inwater = true;
                goto LAB_0006c881;
              }
LAB_0006c9f8:
              local_e8.inopen = true;
              goto LAB_0006c881;
            }
LAB_0006c460:
            local_e8.startsolid = true;
            goto LAB_0006c46c;
          }
                    /* Unresolved local var: int closest@[???]
                       Unresolved local var: pmtrace_t testtrace@[???]
                       Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t mid@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: int otherside@[???]
                       Unresolved local var: float midf@[???]
                       Unresolved local var: qboolean retval@[???] */
          iVar10 = 0;
          iVar14 = 0;
          do {
            Q_memset(&local_60,0,0x44);
            local_60.endpos[0] = *end;
            local_60.endpos[1] = end[1];
            local_60.endpos[2] = end[2];
            local_60.fraction = 1.0;
            local_60.allsolid = true;
            num = hull->firstclipnode;
            if (num < 0) {
              if (num != -2) {
                local_60.allsolid = false;
                if (num == -1) goto LAB_0006c581;
                local_60.inwater = true;
                goto LAB_0006c58d;
              }
              local_60.startsolid = true;
LAB_0006c3e2:
              uVar11 = 0;
              iVar10 = iVar14;
              if (local_e8.startsolid == false) {
                do {
                  *(undefined4 *)((int)local_e8.endpos + (uVar11 - 0x14)) =
                       *(undefined4 *)((int)local_60.endpos + (uVar11 - 0x14));
                  uVar11 = uVar11 + 4;
                } while (uVar11 < 0x44);
              }
              else {
                do {
                  *(undefined4 *)((int)local_e8.endpos + (uVar11 - 0x14)) =
                       *(undefined4 *)((int)local_60.endpos + (uVar11 - 0x14));
                  uVar11 = uVar11 + 4;
                } while (uVar11 < 0x44);
                local_e8.startsolid = true;
              }
            }
            else {
              if (num < hull->lastclipnode) {
                PM_RecursiveHullCheck
                          (hull,num,(float)&local_118,0.0,(vec_t *)0x3f800000,&local_10c,&local_60);
                if ((iVar14 == 0) || ((float)local_60.allsolid != 0.0)) goto LAB_0006c3e2;
              }
              else {
                local_60.allsolid = false;
LAB_0006c581:
                local_60.inopen = true;
LAB_0006c58d:
                local_60.allsolid = false;
                if (iVar14 == 0) goto LAB_0006c3e2;
              }
              if (((float)local_60.startsolid != 0.0) || (local_60.fraction < local_e8.fraction))
              goto LAB_0006c3e2;
            }
            iVar14 = iVar14 + 1;
            hull = hull + 1;
            local_e8.hitgroup = SV_HitgroupForStudioHull(iVar10);
          } while (iVar14 < local_11c);
LAB_0006c451:
          if (local_e8.allsolid != false) goto LAB_0006c460;
          if (local_e8.startsolid != false) goto LAB_0006c46c;
          if (local_e8.fraction == 1.0) goto LAB_0006c4c7;
LAB_0006c479:
          if (bVar8) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t temp@[???] */
            AngleVectorsTranspose(angles,&local_100,&local_f4,(vec_t *)&local_60);
            vVar9 = local_e8.plane.normal[1];
            vVar12 = local_e8.plane.normal[0];
            local_e8.plane.normal[0] =
                 local_f8 * local_e8.plane.normal[2] +
                 local_fc * local_e8.plane.normal[1] + local_100 * local_e8.plane.normal[0];
            local_e8.plane.normal[1] =
                 local_ec * local_e8.plane.normal[2] +
                 local_f0 * local_e8.plane.normal[1] + local_f4 * vVar12;
            local_e8.plane.normal[2] =
                 local_e8.plane.normal[2] * (float)local_60.inopen +
                 vVar9 * (float)local_60.startsolid + vVar12 * (float)local_60.allsolid;
          }
          local_e8.endpos[0] = (*end - *start) * local_e8.fraction + *start;
          local_e8.endpos[1] = (end[1] - start[1]) * local_e8.fraction + start[1];
          local_e8.endpos[2] = (end[2] - start[2]) * local_e8.fraction + start[2];
        }
LAB_0006c4c7:
        if (local_e8.fraction < local_a4[4]) {
          uVar11 = 0;
          do {
            *(undefined4 *)((int)local_a4 + uVar11) =
                 *(undefined4 *)((int)local_e8.endpos + (uVar11 - 0x14));
            uVar11 = uVar11 + 4;
          } while (uVar11 < 0x44);
          local_74 = local_138;
        }
      }
    }
LAB_0006c510:
    do {
      local_138 = local_138 + 1;
      if ((numphysent == local_138) || ((local_138 != 0 && ((traceFlags & 8U) != 0))))
      goto LAB_0006c610;
      pvVar13 = angles + 0x38;
      physents = (physent_t *)(angles + 0x23);
      angles = pvVar13;
      if (pfnIgnore != (_func_int_physent_t_ptr *)0x0) goto LAB_0006c1b0;
LAB_0006c551:
    } while ((ignore_pe != -1) && (ignore_pe == local_138));
  } while( true );
}


// _PM_TestPlayerPosition  @ 0006cb30
int _PM_TestPlayerPosition(vec_t *pos,pmtrace_t *ptrace,_func_int_physent_t_ptr *pfnIgnore)

{
  dclipnode_t *pdVar1;
  mplane_t *pmVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  short sVar6;
  model_s *pmVar7;
  model_t *pModel;
  uint uVar8;
  int iVar9;
  int iVar10;
  playermove_t *ppVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  hull_t *phVar15;
  playermove_t *ppVar16;
  int iVar17;
  int local_cc;
  float local_c8 [4];
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float fStack_a8;
  undefined4 auStack_a4 [17];
  pmtrace_t local_60;
  
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
  _PM_PlayerTrace(&local_60,pmove->origin,pmove->origin,0,pmove->numphysent,pmove->physents,-1,
                  (_func_int_physent_t_ptr *)0x0);
  uVar8 = 0;
  do {
    *(undefined4 *)((int)auStack_a4 + uVar8) =
         *(undefined4 *)((int)local_60.endpos + (uVar8 - 0x14));
    uVar8 = uVar8 + 4;
  } while (uVar8 < 0x44);
  if (ptrace != (pmtrace_t *)0x0) {
    uVar8 = 0;
    do {
      *(undefined4 *)((int)ptrace->endpos + (uVar8 - 0x14)) =
           *(undefined4 *)((int)auStack_a4 + uVar8);
      uVar8 = uVar8 + 4;
    } while (uVar8 < 0x44);
  }
  iVar13 = 0;
  ppVar16 = pmove;
  if (0 < pmove->numphysent) {
    do {
      ppVar11 = ppVar16;
      if ((pfnIgnore == (_func_int_physent_t_ptr *)0x0) ||
         (iVar9 = (*pfnIgnore)(ppVar16->physents + iVar13), ppVar11 = pmove, iVar9 == 0)) {
        pmVar7 = ppVar16->physents[iVar13].model;
        if (pmVar7 == (model_s *)0x0) {
          pModel = ppVar16->physents[iVar13].studiomodel;
          fVar3 = ppVar16->physents[iVar13].origin[0];
          fVar4 = ppVar16->physents[iVar13].origin[1];
          fVar5 = ppVar16->physents[iVar13].origin[2];
          local_cc = 1;
          if ((pModel == (model_t *)0x0) || (pModel->type != mod_studio)) {
            iVar9 = ppVar11->usehull;
          }
          else {
            iVar9 = ppVar11->usehull;
            if (((pModel->flags & 0x200) != 0) || (iVar9 == 2)) {
                    /* Unresolved local var: vec3_t size@[???] */
              local_60.allsolid = (qboolean)(player_maxs[iVar9][0] - player_mins[iVar9][0]);
              iVar12 = ppVar16->physents[iVar13].sequence;
              fVar3 = ppVar16->physents[iVar13].frame;
              local_60.startsolid = (qboolean)(player_maxs[iVar9][1] - player_mins[iVar9][1]);
              local_60.inopen = (qboolean)(player_maxs[iVar9][2] - player_mins[iVar9][2]);
              VectorScale((vec_t *)&local_60,0.5,(vec_t *)&local_60);
              phVar15 = R_StudioHull(pModel,fVar3,iVar12,ppVar16->physents[iVar13].angles,
                                     ppVar16->physents[iVar13].origin,(vec_t *)&local_60,
                                     ppVar16->physents[iVar13].controller,
                                     ppVar16->physents[iVar13].blending,&local_cc,(edict_t *)0x0,0);
              iVar12 = ppVar16->physents[iVar13].solid;
              fVar5 = 0.0;
              fVar4 = 0.0;
              fVar3 = 0.0;
              goto LAB_0006ccd7;
            }
          }
          phVar15 = &box_hull;
          iVar12 = ppVar16->physents[iVar13].solid;
          box_planes[1].dist = ppVar16->physents[iVar13].mins[0] - player_maxs[iVar9][0];
          box_planes[3].dist = ppVar16->physents[iVar13].mins[1] - player_maxs[iVar9][1];
          box_planes[5].dist = ppVar16->physents[iVar13].mins[2] - player_maxs[iVar9][2];
          box_planes[2].dist = ppVar16->physents[iVar13].maxs[1] - player_mins[iVar9][1];
          box_planes[4].dist = ppVar16->physents[iVar13].maxs[2] - player_mins[iVar9][2];
          box_planes[0].dist = ppVar16->physents[iVar13].maxs[0] - player_mins[iVar9][0];
        }
        else {
          iVar12 = ppVar16->physents[iVar13].solid;
          if ((iVar12 == 0) && (ppVar16->physents[iVar13].skin != 0)) goto LAB_0006cc30;
          local_cc = 1;
                    /* Unresolved local var: hull_t * hull@[???] */
          iVar9 = ppVar11->usehull;
          if (iVar9 == 2) {
            phVar15 = pmVar7->hulls;
          }
          else if (iVar9 == 3) {
            phVar15 = pmVar7->hulls + 2;
          }
          else {
            phVar15 = pmVar7->hulls + 1;
            if (iVar9 == 1) {
              phVar15 = pmVar7->hulls + 3;
            }
          }
          fVar3 = (phVar15->clip_mins[0] - player_mins[iVar9][0]) +
                  ppVar16->physents[iVar13].origin[0];
          fVar4 = (phVar15->clip_mins[1] - player_mins[iVar9][1]) +
                  ppVar16->physents[iVar13].origin[1];
          fVar5 = (phVar15->clip_mins[2] - player_mins[iVar9][2]) +
                  ppVar16->physents[iVar13].origin[2];
        }
LAB_0006ccd7:
        fVar3 = *pos - fVar3;
        fVar4 = pos[1] - fVar4;
        local_c8[0] = fVar3;
        fVar5 = pos[2] - fVar5;
        local_c8[1] = fVar4;
        local_c8[2] = fVar5;
        iVar9 = local_cc;
        if ((iVar12 == 4) &&
           (((ppVar16->physents[iVar13].angles[0] != 0.0 ||
             (ppVar16->physents[iVar13].angles[1] != 0.0)) ||
            (ppVar16->physents[iVar13].angles[2] != 0.0)))) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t temp@[???] */
          AngleVectors(ppVar16->physents[iVar13].angles,local_c8 + 3,&local_b0,(vec_t *)&local_60);
          local_c8[0] = local_b4 * fVar5 + local_b8 * fVar4 + local_c8[3] * fVar3;
          local_c8[1] = -(fStack_a8 * fVar5 + local_ac * fVar4 + local_b0 * fVar3);
          fVar5 = fVar3 * (float)local_60.allsolid + (float)local_60.startsolid * fVar4 +
                  (float)local_60.inopen * fVar5;
          local_c8[2] = fVar5;
          fVar4 = local_c8[1];
          fVar3 = local_c8[0];
          iVar9 = local_cc;
        }
        ppVar11 = pmove;
        local_cc = iVar9;
        local_c8[0] = fVar3;
        local_c8[1] = fVar4;
        local_c8[2] = fVar5;
        if (iVar9 == 1) {
          iVar9 = phVar15->firstclipnode;
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???] */
          if (iVar9 < phVar15->lastclipnode) {
            iVar12 = iVar9;
            if (-1 < iVar9) {
              do {
                if ((iVar12 < iVar9) || (phVar15->lastclipnode < iVar12)) {
                  Sys_Error("PM_HullPointContents: bad node number");
                }
                pdVar1 = phVar15->clipnodes + iVar12;
                pmVar2 = phVar15->planes + pdVar1->planenum;
                if (pmVar2->type < 3) {
                  if (0.0 <= local_c8[pmVar2->type] - pmVar2->dist) goto LAB_0006d015;
LAB_0006d075:
                  sVar6 = pdVar1->children[1];
                }
                else {
                  if ((fVar5 * pmVar2->normal[2] +
                      fVar4 * pmVar2->normal[1] + fVar3 * pmVar2->normal[0]) - pmVar2->dist < 0.0)
                  goto LAB_0006d075;
LAB_0006d015:
                  sVar6 = pdVar1->children[0];
                }
                iVar12 = (int)sVar6;
                if (iVar12 < 0) break;
                iVar9 = phVar15->firstclipnode;
              } while( true );
            }
            ppVar11 = pmove;
            if (iVar12 == -2) {
              return iVar13;
            }
          }
        }
        else {
          piVar14 = &phVar15->firstclipnode;
          iVar12 = 0;
          if (0 < iVar9) {
            do {
              iVar10 = *piVar14;
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???] */
              if (iVar10 < piVar14[1]) {
                iVar17 = iVar10;
                if (-1 < iVar10) {
                  do {
                    if ((iVar17 < iVar10) || (piVar14[1] < iVar17)) {
                      Sys_Error("PM_HullPointContents: bad node number");
                    }
                    pdVar1 = ((hull_t *)(piVar14 + -2))->clipnodes + iVar17;
                    pmVar2 = (mplane_t *)piVar14[-1] + pdVar1->planenum;
                    if (pmVar2->type < 3) {
                      if (0.0 <= local_c8[pmVar2->type] - pmVar2->dist) goto LAB_0006cd67;
LAB_0006cdc3:
                      sVar6 = pdVar1->children[1];
                    }
                    else {
                      if ((fVar5 * pmVar2->normal[2] +
                          fVar4 * pmVar2->normal[1] + fVar3 * pmVar2->normal[0]) - pmVar2->dist <
                          0.0) goto LAB_0006cdc3;
LAB_0006cd67:
                      sVar6 = pdVar1->children[0];
                    }
                    iVar17 = (int)sVar6;
                    if (iVar17 < 0) break;
                    iVar10 = *piVar14;
                  } while( true );
                }
                iVar9 = local_cc;
                if (iVar17 == -2) {
                  return iVar13;
                }
              }
              iVar12 = iVar12 + 1;
              piVar14 = piVar14 + 10;
              ppVar11 = pmove;
            } while (iVar12 < iVar9);
          }
        }
      }
LAB_0006cc30:
      iVar13 = iVar13 + 1;
      ppVar16 = ppVar11;
    } while (iVar13 < ppVar11->numphysent);
  }
  return -1;
}


// _VectorAdd  @ 00060b70
void _VectorAdd(vec_t *veca,vec_t *vecb,vec_t *out)

{
  *out = *veca + *vecb;
  out[1] = veca[1] + vecb[1];
  out[2] = veca[2] + vecb[2];
  return;
}


// _VectorCopy  @ 00060ba0
void _VectorCopy(vec_t *in,vec_t *out)

{
  *out = *in;
  out[1] = in[1];
  out[2] = in[2];
  return;
}


// _VectorSubtract  @ 00060b40
void _VectorSubtract(vec_t *veca,vec_t *vecb,vec_t *out)

{
  *out = *veca - *vecb;
  out[1] = veca[1] - vecb[1];
  out[2] = veca[2] - vecb[2];
  return;
}


// __CreateCDedicatedServerAPIIDedicatedServerAPI_interface  @ 0007b7e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * __CreateCDedicatedServerAPIIDedicatedServerAPI_interface(void)

{
  return &__g_CDedicatedServerAPI_singleton;
}


// __CreateCEngineAPIIEngineAPI_interface  @ 0007b7d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * __CreateCEngineAPIIEngineAPI_interface(void)

{
  return &__g_CEngineAPI_singleton;
}


// __CreateCServerRemoteAccessIGameServerData_interface  @ 000b3950
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * __CreateCServerRemoteAccessIGameServerData_interface(void)

{
  return &g_ServerRemoteAccess;
}


// __do_global_dtors_aux  @ 00035de0
/* WARNING: Function: __x86.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void __do_global_dtors_aux(void)

{
  if (completed_7155 == '\0') {
    __cxa_finalize(__dso_handle);
    deregister_tm_clones();
    completed_7155 = '\x01';
  }
  return;
}


// __x86.get_pc_thunk.bx  @ 00035e70
/* WARNING: This is an inlined function */

void __x86_get_pc_thunk_bx(void)

{
  return;
}


// __x86.get_pc_thunk.dx  @ 00035e6c
/* WARNING: This is an inlined function */

void __x86_get_pc_thunk_dx(void)

{
  return;
}


// _fini  @ 000d08d4
void _fini(void)

{
  return;
}


// _init  @ 000358c0
int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = __gmon_start__();
  return iVar1;
}


