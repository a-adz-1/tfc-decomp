// FUN_00103c0c  @ 00103c0c
void FUN_00103c0c(void)

{
  (*(code *)(undefined *)0x0)();
  return;
}


// _DELTA_WriteDelta  @ 00115590
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


// _DotProduct  @ 0012bb70
vec_t _DotProduct(vec_t *v1,vec_t *v2)

{
  return v1[2] * v2[2] + v1[1] * v2[1] + *v1 * *v2;
}


// _GLOBAL__sub_I_CheckIP  @ 00104310
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_CheckIP(void)

{
  CIPRateLimit::CIPRateLimit(&rateChecker);
  __cxa_atexit(CIPRateLimit::~CIPRateLimit,&rateChecker,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_D_SurfaceCacheForRes  @ 001040f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_D_SurfaceCacheForRes(void)

{
  __g_CEngineAPI_singleton.super_IEngineAPI.super_IBaseInterface._vptr_IBaseInterface =
       (IEngineAPI)&PTR__CEngineAPI_002827b0;
  __cxa_atexit(CEngineAPI::~CEngineAPI,&__g_CEngineAPI_singleton,&__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateCEngineAPIIEngineAPI_reg,__CreateCEngineAPIIEngineAPI_interface,
             "VENGINE_LAUNCHER_API_VERSION002");
  __g_CDedicatedServerAPI_singleton.super_IDedicatedServerAPI.super_IBaseInterface.
  _vptr_IBaseInterface = (IBaseInterface)&PTR__CDedicatedServerAPI_002827c8;
  __cxa_atexit(CDedicatedServerAPI::~CDedicatedServerAPI,&__g_CDedicatedServerAPI_singleton,
               &__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateCDedicatedServerAPIIDedicatedServerAPI_reg,
             __CreateCDedicatedServerAPIIDedicatedServerAPI_interface,"VENGINE_HLDS_API_VERSION002")
  ;
  __g_CGameUIFuncs_singleton.super_IGameUIFuncs.super_IBaseInterface._vptr_IBaseInterface =
       (IGameUIFuncs)&PTR__CGameUIFuncs_002828a8;
  __cxa_atexit(CGameUIFuncs::~CGameUIFuncs,&__g_CGameUIFuncs_singleton,&__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateCGameUIFuncsIGameUIFuncs_reg,__CreateCGameUIFuncsIGameUIFuncs_interface,
             "VENGINE_GAMEUIFUNCS_VERSION001");
  return;
}


// _GLOBAL__sub_I_MP3digitalDriver  @ 00104980
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_MP3digitalDriver(void)

{
  CCDAudio::CCDAudio(&g_CDAudio);
  __cxa_atexit(CCDAudio::~CCDAudio,&g_CDAudio,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_VGUI2_Draw_Init  @ 00104ad0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_VGUI2_Draw_Init(void)

{
  _col._color[0] = 0xff;
  _col._color[1] = 0xff;
  _col._color[2] = 0xff;
  _col._color[3] = 0xff;
  return;
}


// _GLOBAL__sub_I__Z11FontManagerv  @ 00104cb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Enum "FT_Encoding_": Some values do not have unique names */

void _GLOBAL__sub_I__Z11FontManagerv(void)

{
  CFontManager::CFontManager(&s_FontManager);
  __cxa_atexit(CFontManager::~CFontManager,&s_FontManager,&__dso_handle);
  return;
}


// _GLOBAL__sub_I__Z15COM_BuildNumberv  @ 001041d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__Z15COM_BuildNumberv(void)

{
  int in_stack_ffffffe8;
  void **in_stack_ffffffec;
  
  SystemWrapper::SystemWrapper(&gSystemWrapper,in_stack_ffffffe8,in_stack_ffffffec);
  __cxa_atexit(SystemWrapper::~SystemWrapper,&gSystemWrapper,&__dso_handle);
  return;
}


// _GLOBAL__sub_I__ZN10CUtlSymbol14s_pSymbolTableE  @ 00104d60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN10CUtlSymbol14s_pSymbolTableE(void)

{
  g_LessCtx.m_pUserString = (char *)0x0;
  g_LessCtx.m_pTable = (CUtlSymbolTable *)0x0;
  return;
}


// _GLOBAL__sub_I__ZN10EngineFont11GetTextSizeEPKcRiS2_  @ 00104c70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN10EngineFont11GetTextSizeEPKcRiS2_(void)

{
  staticFontPlatDar._count = 0;
  staticFontPlatDar._capacity = 0;
  staticFontPlatDar._data = (BaseFontPlat **)0x0;
  __cxa_atexit(vgui2::Dar<BaseFontPlat*>::~Dar,&staticFontPlatDar,&__dso_handle);
  return;
}


// _GLOBAL__sub_I__ZN12CInitTrackerC2Ev  @ 00104280
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN12CInitTrackerC2Ev(void)

{
  CInitTracker::CInitTracker(&g_InitTracker);
  __cxa_atexit(CInitTracker::~CInitTracker,&g_InitTracker,&__dso_handle);
  return;
}


// _GLOBAL__sub_I__ZN13CSteam3Server18OnGSPolicyResponseEP18GSPolicyResponse_t  @ 00104390
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN13CSteam3Server18OnGSPolicyResponseEP18GSPolicyResponse_t(void)

{
  s_Steam3Client.super_CSteam3._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3Client_00288720;
  s_Steam3Client.m_CallbackClientGameServerDeny.super_CCallbackBase.m_iCallback = 0;
  s_Steam3Client.m_CallbackClientGameServerDeny.super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR_Run_00288810;
  s_Steam3Client.m_CallbackClientGameServerDeny.m_pObj = &s_Steam3Client;
  s_Steam3Client.m_CallbackClientGameServerDeny.m_Func.__pfn = CSteam3Client::OnClientGameServerDeny
  ;
  s_Steam3Client.super_CSteam3.m_hSteamPipe = 0;
  s_Steam3Client.m_CallbackClientGameServerDeny.m_Func.__delta = 0;
  s_Steam3Client.super_CSteam3.m_bLoggedOn = false;
  s_Steam3Client.super_CSteam3.m_bLogOnResult = false;
  s_Steam3Client.m_CallbackClientGameServerDeny.super_CCallbackBase.m_nCallbackFlags = '\0';
  SteamAPI_RegisterCallback(0x3813cc,0x71);
  s_Steam3Client.m_CallbackGameServerChangeRequested.super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR_Run_002887f8;
  s_Steam3Client.m_CallbackGameServerChangeRequested.m_pObj = &s_Steam3Client;
  s_Steam3Client.m_CallbackGameServerChangeRequested.m_Func.__pfn =
       CSteam3Client::OnGameServerChangeRequested;
  s_Steam3Client.m_CallbackGameServerChangeRequested.m_Func.__delta = 0;
  s_Steam3Client.m_CallbackGameServerChangeRequested.super_CCallbackBase.m_iCallback = 0;
  s_Steam3Client.m_CallbackGameServerChangeRequested.super_CCallbackBase.m_nCallbackFlags = '\0';
  SteamAPI_RegisterCallback(0x3813e4,0x14c);
  s_Steam3Client.m_CallbackGameOverlayActivated.super_CCallbackBase.m_iCallback = 0;
  s_Steam3Client.m_CallbackGameOverlayActivated.m_Func.__pfn = CSteam3Client::OnGameOverlayActivated
  ;
  s_Steam3Client.m_CallbackGameOverlayActivated.m_Func.__delta = 0;
  s_Steam3Client.m_CallbackGameOverlayActivated.super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR_Run_002887e0;
  s_Steam3Client.m_CallbackGameOverlayActivated.m_pObj = &s_Steam3Client;
  s_Steam3Client.m_CallbackGameOverlayActivated.super_CCallbackBase.m_nCallbackFlags = '\0';
  SteamAPI_RegisterCallback(0x3813fc,0x14b);
  __cxa_atexit(CSteam3Client::~CSteam3Client,&s_Steam3Client,&__dso_handle);
  return;
}


// _GLOBAL__sub_I__ZN13EngineSurface17freeEngineSurfaceEv  @ 00104930
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN13EngineSurface17freeEngineSurfaceEv(void)

{
  EngineSurface::EngineSurface(&__g_EngineSurface_singleton);
  __cxa_atexit(EngineSurface::~EngineSurface,&__g_EngineSurface_singleton,&__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateEngineSurfaceIEngineSurface_reg,
             __CreateEngineSurfaceIEngineSurface_interface,"EngineSurface007");
  return;
}


// _GLOBAL__sub_I__ZN15DownloadManagerC2Ev  @ 00104350
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN15DownloadManagerC2Ev(void)

{
  DownloadManager::DownloadManager(&TheDownloadManager);
  __cxa_atexit(DownloadManager::~DownloadManager,&TheDownloadManager,&__dso_handle);
  return;
}


// _GLOBAL__sub_I__ZN17EngineSurfaceWrapC2EPN4vgui5PanelEP14IEngineSurface  @ 00104840
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN17EngineSurfaceWrapC2EPN4vgui5PanelEP14IEngineSurface(void)

{
  FontInfoVGUI **ppFVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  FontInfoVGUI **ppFVar5;
  FontInfoVGUI **ppFVar6;
  bool bVar7;
  byte bVar8;
  
  bVar8 = 0;
  staticFontInfoVGUIDar._capacity = 0;
  staticFontInfoVGUIDar._count = 0;
  staticFontInfoVGUIDar._data = (FontInfoVGUI **)0x0;
                    /* Unresolved local var: int newCapacity@[???]
                       Unresolved local var: FontInfoVGUI * * newData@[???] */
  ppFVar1 = operator_new__(0x10);
  if (ppFVar1 != (FontInfoVGUI **)0x0) {
    bVar7 = ((uint)ppFVar1 & 1) != 0;
    uVar4 = 0x10;
    ppFVar6 = ppFVar1;
    if (bVar7) {
      ppFVar6 = (FontInfoVGUI **)((int)ppFVar1 + (uint)bVar8 * -2 + 1);
      *(undefined1 *)ppFVar1 = 0;
      uVar4 = 0xf;
    }
    ppFVar5 = ppFVar6;
    if (((uint)ppFVar6 & 2) != 0) {
      ppFVar5 = (FontInfoVGUI **)((int)ppFVar6 + (uint)bVar8 * -4 + 2);
      *(undefined2 *)ppFVar6 = 0;
      uVar4 = uVar4 - 2;
    }
    ppFVar6 = ppFVar5;
    if (((uint)ppFVar5 & 4) != 0) {
      ppFVar6 = ppFVar5 + (uint)bVar8 * -2 + 1;
      *ppFVar5 = (FontInfoVGUI *)0x0;
      uVar4 = uVar4 - 4;
    }
    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *ppFVar6 = (FontInfoVGUI *)0x0;
      ppFVar6 = ppFVar6 + (uint)bVar8 * -2 + 1;
    }
    ppFVar5 = ppFVar6;
    if ((uVar4 & 2) != 0) {
      ppFVar5 = (FontInfoVGUI **)((int)ppFVar6 + (uint)bVar8 * -4 + 2);
      *(undefined2 *)ppFVar6 = 0;
    }
    if (bVar7) {
      *(undefined1 *)ppFVar5 = 0;
    }
                    /* Unresolved local var: int i@[???] */
    staticFontInfoVGUIDar._capacity = 4;
    if (0 < staticFontInfoVGUIDar._count) {
      iVar2 = 0;
      do {
        ppFVar1[iVar2] = staticFontInfoVGUIDar._data[iVar2];
        iVar2 = iVar2 + 1;
      } while (iVar2 < staticFontInfoVGUIDar._count);
    }
    if (staticFontInfoVGUIDar._data != (FontInfoVGUI **)0x0) {
      operator_delete__(staticFontInfoVGUIDar._data);
    }
    staticFontInfoVGUIDar._data = ppFVar1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  exit(0);
}


// _GLOBAL__sub_I__ZN5vgui210g_pSurfaceE  @ 00104af0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN5vgui210g_pSurfaceE(void)

{
  g_pBaseUI = &g_BaseUI;
  g_BaseUI.m_hVGuiModule = (CSysModule *)0x0;
  g_BaseUI.m_hStaticGameUIModule = (CSysModule *)0x0;
  g_BaseUI.super_IBaseUI.super_IBaseInterface._vptr_IBaseInterface =
       (IBaseInterface)&PTR__CBaseUI_00296208;
  m_bConsoleShowing = false;
  g_BaseUI.m_bHidingGameUI = false;
  __cxa_atexit(CBaseUI::~CBaseUI,&g_BaseUI,&__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateCBaseUIIBaseUI_reg,__CreateCBaseUIIBaseUI_interface,"BaseUI001");
  __g_CEngineVGui_singleton.m_hRefreshLoginHandle = 0;
  __g_CEngineVGui_singleton.super_IEngineVGui.super_IBaseInterface._vptr_IBaseInterface =
       (IBaseInterface)&PTR__CEngineVGui_00296240;
  __g_CEngineVGui_singleton.m_bVisible = true;
  __cxa_atexit(CEngineVGui::~CEngineVGui,&__g_CEngineVGui_singleton,&__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateCEngineVGuiIEngineVGui_reg,__CreateCEngineVGuiIEngineVGui_interface,
             "VEngineVGui001");
  return;
}


// _GLOBAL__sub_I_eng  @ 00104210
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_eng(void)

{
  g_Engine.super_IEngine._vptr_IEngine = (_func_int_varargs **)&PTR__CEngine_00283588;
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


// _GLOBAL__sub_I_g_BaseUISurface  @ 00104bc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_BaseUISurface(void)

{
  staticPopupList._count = 0;
  staticPopupList._capacity = 0;
  staticPopupList._data = (uint *)0x0;
  __cxa_atexit(vgui2::Dar<unsigned_int>::~Dar,&staticPopupList,&__dso_handle);
  CFontTextureCache::CFontTextureCache(&g_FontTextureCache);
  __cxa_atexit(CFontTextureCache::~CFontTextureCache,&g_FontTextureCache,&__dso_handle);
  BaseUISurface::BaseUISurface(&g_BaseUISurface);
  __cxa_atexit(BaseUISurface::~BaseUISurface,&g_BaseUISurface,&__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateBaseUISurfaceISurface_reg,__CreateBaseUISurfaceISurface_interface,
             "VGUI_Surface026");
  return;
}


// _GLOBAL__sub_I_g_ButtonSoundNames  @ 00104d80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_ButtonSoundNames(void)

{
  CUtlSymbolTable::CUtlSymbolTable(&g_ButtonSoundNames,0,0x20,false);
  __cxa_atexit(CUtlSymbolTable::~CUtlSymbolTable,&g_ButtonSoundNames,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_g_FileSystemFactory  @ 001040a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_FileSystemFactory(void)

{
  g_fallbackLocalizationFiles.m_Memory.m_pMemory = (char **)0x0;
  g_fallbackLocalizationFiles.m_Memory.m_NumAllocated = 0;
  g_fallbackLocalizationFiles.m_Memory.m_GrowSize = 0;
  g_fallbackLocalizationFiles.m_Size = 0;
  __cxa_atexit(CUtlVector<char*>::~CUtlVector,&g_fallbackLocalizationFiles,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_g_ScissorRect  @ 001044b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_ScissorRect(void)

{
  g_VGuiSurfaceTextures.m_LessFunc = VguiSurfaceTexturesLessFunc;
  g_VGuiSurfaceTextures.m_Elements.m_GrowSize = 0;
  g_VGuiSurfaceTextures.m_Elements.m_NumAllocated = 0x80;
  g_VGuiSurfaceTextures.m_Elements.m_pMemory = malloc(0x1600);
  g_VGuiSurfaceTextures.m_Root = -1;
  g_VGuiSurfaceTextures.m_NumElements = 0;
  g_VGuiSurfaceTextures.m_FirstFree = -1;
  g_VGuiSurfaceTextures.m_TotalElements = 0;
  __cxa_atexit(CUtlRBTree<{anonymous}::Texture,_int>::~CUtlRBTree,&g_VGuiSurfaceTextures,
               &__dso_handle);
  return;
}


// _GLOBAL__sub_I_g_ServerRemoteAccess  @ 001042c0
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


// _GLOBAL__sub_I_g_TempConsoleBuffer  @ 001046b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_TempConsoleBuffer(void)

{
  g_TempConsoleBuffer.m_Memory.m_NumAllocated = 0x400;
  g_TempConsoleBuffer.m_Memory.m_GrowSize = 0;
  g_TempConsoleBuffer.m_Memory.m_pMemory = malloc(0x400);
  g_TempConsoleBuffer.m_Size = 0;
  __cxa_atexit(CUtlVector<char>::~CUtlVector,&g_TempConsoleBuffer,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_g_VoiceSampleFormat  @ 00104730
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

void _GLOBAL__sub_I_g_VoiceSampleFormat(void)

{
  CCircularBuffer::CCircularBuffer(&g_VoiceChannels[0].m_Buffer.super_CCircularBuffer,0x5622);
  CAutoGain::CAutoGain(&g_VoiceChannels[0].m_AutoGain);
  g_VoiceChannels[0].m_iEntity = -1;
  g_VoiceChannels[0].m_pVoiceCodec = (IVoiceCodec *)0x0;
  CCircularBuffer::CCircularBuffer(&g_VoiceChannels[1].m_Buffer.super_CCircularBuffer,0x5622);
  CAutoGain::CAutoGain(&g_VoiceChannels[1].m_AutoGain);
  g_VoiceChannels[1].m_pVoiceCodec = (IVoiceCodec *)0x0;
  g_VoiceChannels[1].m_iEntity = -1;
  CCircularBuffer::CCircularBuffer(&g_VoiceChannels[2].m_Buffer.super_CCircularBuffer,0x5622);
  CAutoGain::CAutoGain(&g_VoiceChannels[2].m_AutoGain);
  g_VoiceChannels[2].m_iEntity = -1;
  g_VoiceChannels[2].m_pVoiceCodec = (IVoiceCodec *)0x0;
  CCircularBuffer::CCircularBuffer(&g_VoiceChannels[3].m_Buffer.super_CCircularBuffer,0x5622);
  CAutoGain::CAutoGain(&g_VoiceChannels[3].m_AutoGain);
  g_VoiceChannels[3].m_iEntity = -1;
  g_VoiceChannels[3].m_pVoiceCodec = (IVoiceCodec *)0x0;
  CCircularBuffer::CCircularBuffer(&g_VoiceChannels[4].m_Buffer.super_CCircularBuffer,0x5622);
  CAutoGain::CAutoGain(&g_VoiceChannels[4].m_AutoGain);
  g_VoiceChannels[4].m_iEntity = -1;
  g_VoiceChannels[4].m_pVoiceCodec = (IVoiceCodec *)0x0;
  return;
}


// _GLOBAL__sub_I_game  @ 00104a10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_game(void)

{
  g_Game.super_IGame._vptr_IGame = (_func_int_varargs **)&PTR__CGame_00295948;
  g_Game.m_y = 0;
  g_Game.m_x = 0;
  g_Game.m_height = 0;
  g_Game.m_width = 0;
  g_Game.m_nMouseTargetX = 0;
  g_Game.m_bActiveApp = true;
  g_Game.m_bMultiplayer = false;
  g_Game.m_bExpectSyntheticMouseMotion = false;
  g_Game.m_nMouseTargetY = 0;
  g_Game.m_nWarpDelta = 0;
  g_Game.m_bCursorVisible = true;
  __cxa_atexit(CGame::~CGame,&g_Game,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_pmainwindow  @ 00104710
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_pmainwindow(void)

{
  vgui::App::App(&theApp.super_App);
  theApp._0_4_ = &PTR_start_00292e08;
  return;
}


// _GLOBAL__sub_I_r_detailtextures  @ 00104530
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_r_detailtextures(void)

{
  g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl._M_start =
       (pointer)0x0;
  g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl._M_finish =
       (pointer)0x0;
  g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
  _M_end_of_storage = (pointer)0x0;
  __cxa_atexit(std::vector<DetailMap*,_std::allocator<DetailMap*>_>::~vector,&g_detailVector,
               &__dso_handle);
  g_idMap._M_t._M_impl._M_header._M_color = _S_red;
  g_idMap._M_t._M_impl._M_header._M_left = &g_idMap._M_t._M_impl._M_header;
  g_idMap._M_t._M_impl._M_header._M_right = &g_idMap._M_t._M_impl._M_header;
  g_idMap._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  g_idMap._M_t._M_impl._M_node_count = 0;
  __cxa_atexit(std::
               map<int,_DetailMap*,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_>
               ::~map,&g_idMap,&__dso_handle);
  g_detailNameToIdMap._M_t._M_impl._M_header._M_color = _S_red;
  g_detailNameToIdMap._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  g_detailNameToIdMap._M_t._M_impl._M_header._M_right = &g_detailNameToIdMap._M_t._M_impl._M_header;
  g_detailNameToIdMap._M_t._M_impl._M_node_count = 0;
  g_detailNameToIdMap._M_t._M_impl._M_header._M_left = &g_detailNameToIdMap._M_t._M_impl._M_header;
  __cxa_atexit(std::
               map<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
               ::~map,&g_detailNameToIdMap,&__dso_handle);
  g_detailLoadFailedMap._M_t._M_impl._M_header._M_color = _S_red;
  g_detailLoadFailedMap._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  g_detailLoadFailedMap._M_t._M_impl._M_node_count = 0;
  g_detailLoadFailedMap._M_t._M_impl._M_header._M_left =
       &g_detailLoadFailedMap._M_t._M_impl._M_header;
  g_detailLoadFailedMap._M_t._M_impl._M_header._M_right =
       &g_detailLoadFailedMap._M_t._M_impl._M_header;
  __cxa_atexit(std::
               map<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
               ::~map,&g_detailLoadFailedMap,&__dso_handle);
  g_levelName._M_dataplus._M_p = (_Alloc_hider)glViewport;
  __cxa_atexit(std::string::~string,&g_levelName,&__dso_handle);
  g_decalTexIDs.
  super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
  ._M_impl._M_start = (pointer)0x0;
  g_decalTexIDs.
  super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
  ._M_impl._M_finish = (pointer)0x0;
  g_decalTexIDs.
  super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
  ._M_impl._M_end_of_storage = (pointer)0x0;
  __cxa_atexit(std::
               vector<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
               ::~vector,&g_decalTexIDs,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_registry  @ 00104a90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_registry(void)

{
  CRegistry::CRegistry(&g_Registry);
  __cxa_atexit(CRegistry::~CRegistry,&g_Registry,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_s_bSupportsUnicode  @ 00104cf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_s_bSupportsUnicode(void)

{
  CLinuxFont::m_FriendlyNameCache.m_LessFunc = (LessFunc_t)0x0;
  CLinuxFont::m_FriendlyNameCache.m_Elements.m_pMemory = (Node_t *)0x0;
  CLinuxFont::m_FriendlyNameCache.m_Elements.m_NumAllocated = 0;
  CLinuxFont::m_FriendlyNameCache.m_NumElements = 0;
  CLinuxFont::m_FriendlyNameCache.m_FirstFree = -1;
  CLinuxFont::m_FriendlyNameCache.m_TotalElements = 0;
  CLinuxFont::m_FriendlyNameCache.m_Elements.m_GrowSize = 0;
  CLinuxFont::m_FriendlyNameCache.m_Root = -1;
  __cxa_atexit(CUtlRBTree<CLinuxFont::font_name_entry,_int>::~CUtlRBTree,
               &CLinuxFont::m_FriendlyNameCache,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_thread  @ 001049c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_thread(void)

{
  g_Thread.m_dwThreadID = 0;
  g_Thread.m_cSet = 0;
  g_Thread.m_bThreadRunning = false;
  g_Thread.super_IThread._vptr_IThread = (_func_int_varargs **)&PTR__CThread_00295320;
  g_Thread.m_bThreadStopped = false;
  __cxa_atexit(CThread::~CThread,&g_Thread,&__dso_handle);
  return;
}


// _Host_Frame  @ 0011f720
void _Host_Frame(float time)

{
  bool bVar1;
  int iVar2;
  qboolean qVar3;
  vec_t local_30 [3];
  vec_t local_24 [3];
  vec_t local_18 [3];
  
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
  Voice_Idle((float)host_frametime);
  CL_EmitEntities();
  CL_CheckForResend();
  do {
    qVar3 = CL_RequestMissingResources();
  } while (qVar3 != false);
  CL_UpdateSoundFade();
  if (((cls.state == ca_disconnected) && (*scr_connectmsg.string == '\0')) &&
     ((((byte)giSubState & 4) != 0 || (console.value == 0.0)))) {
    bVar1 = 0 < Host_CheckConnectionFailure::frames;
    Host_CheckConnectionFailure::frames = Host_CheckConnectionFailure::frames + -1;
    if (bVar1) goto LAB_0011f846;
    giActive = 2;
  }
  Host_CheckConnectionFailure::frames = 5;
LAB_0011f846:
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
    if (cls.signon == 2) {
                    /* Unresolved local var: vec3_t vSoundForward@[???]
                       Unresolved local var: vec3_t vSoundRight@[???]
                       Unresolved local var: vec3_t vSoundUp@[???] */
      AngleVectors(r_playerViewportAngles,local_30,local_24,local_18);
      S_Update(r_soundOrigin,local_30,local_24,local_18);
    }
    else {
      S_Update(vec3_origin,vec3_origin,vec3_origin,vec3_origin);
    }
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
  if (cl_gamegauge.value != 0.0) {
    CL_GGSpeeds((float)_Host_Frame::host_times[3]);
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


// _PM_PlayerTrace  @ 00130f40
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
        if ((local_170 != physents) || (physents == (physent_t *)0xffffffff)) goto LAB_00130ff5;
      }
      else {
        iVar11 = (*(code *)ignore_pe)(local_174);
        if (iVar11 == 0) {
LAB_00130ff5:
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
                                  (vec_t *)(local_174 + 0x24),(byte *)(local_174 + 0x74),
                                  (byte *)(local_174 + 0x78),local_2c);
                iVar13 = *(int *)(local_174 + 0x60);
                goto LAB_001310a6;
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
            if ((iVar13 == 0) && (*(int *)(local_174 + 100) != 0)) goto LAB_00131330;
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
LAB_001310a6:
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
LAB_00131400:
            if (local_15c.startsolid != false) goto LAB_001312ac;
            if (local_15c.fraction != 1.0) goto LAB_001312ba;
          }
          else {
            if (local_2c[0] == 1) {
              iVar11 = hull->firstclipnode;
              if (-1 < iVar11) {
                if (hull->lastclipnode <= iVar11) {
                  local_15c.allsolid = false;
                  goto LAB_001317df;
                }
                PM_RecursiveHullCheck
                          (hull,iVar11,(float)&local_5c,0.0,(vec_t *)0x3f800000,&local_50,&local_15c
                          );
                goto LAB_0013129b;
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
                  goto LAB_00131400;
                }
LAB_001317df:
                local_15c.allsolid = false;
                local_15c.inopen = true;
                goto LAB_00131400;
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
                    if (iVar13 == -1) goto LAB_00131381;
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
LAB_00131381:
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
LAB_0013129b:
              if (local_15c.allsolid == false) goto LAB_00131400;
            }
            local_15c.startsolid = true;
LAB_001312ac:
            local_15c.fraction = 0.0;
LAB_001312ba:
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
LAB_00131330:
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


// _PM_PlayerTrace  @ 00131f40
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
LAB_00132630:
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
  if (pfnIgnore == (_func_int_physent_t_ptr *)0x0) goto LAB_001323e8;
LAB_00132010:
  iVar11 = (*pfnIgnore)(local_180);
  if (iVar11 != 0) goto LAB_001323a0;
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
          if ((traceFlags & 1U) != 0) goto LAB_001323a0;
          if (pModel->type == mod_studio) {
            if (((pModel->flags & 0x200) != 0) ||
               ((iVar11 = pmove->usehull, iVar11 == 2 && ((traceFlags & 2U) == 0)))) {
              hull = PM_HullForStudioModel
                               (pModel,&local_6c,local_180->frame,local_180->sequence,
                                local_180->angles,local_180->origin,local_180->controller,
                                local_180->blending,local_2c);
              goto LAB_0013210b;
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
LAB_0013210b:
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
LAB_00132470:
        if (local_15c.startsolid != false) goto LAB_0013230c;
        if (local_15c.fraction != 1.0) goto LAB_0013231a;
      }
      else {
        if (local_2c[0] == 1) {
          iVar11 = hull->firstclipnode;
          if (-1 < iVar11) {
            if (hull->lastclipnode <= iVar11) {
              local_15c.allsolid = false;
              goto LAB_0013285a;
            }
            PM_RecursiveHullCheck
                      (hull,iVar11,(float)&local_5c,0.0,(vec_t *)0x3f800000,&local_50,&local_15c);
            goto LAB_001322fb;
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
              goto LAB_00132470;
            }
LAB_0013285a:
            local_15c.allsolid = false;
            local_15c.inopen = true;
            goto LAB_00132470;
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
                if (num == -1) goto LAB_00132411;
                local_bc.inwater = true;
              }
            }
            else if (num < hull->lastclipnode) {
              PM_RecursiveHullCheck
                        (hull,num,(float)&local_5c,0.0,(vec_t *)0x3f800000,&local_50,&local_bc);
            }
            else {
              local_bc.allsolid = false;
LAB_00132411:
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
LAB_001322fb:
          if (local_15c.allsolid == false) goto LAB_00132470;
        }
        local_15c.startsolid = true;
LAB_0013230c:
        local_15c.fraction = 0.0;
LAB_0013231a:
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
LAB_001323a0:
    do {
      local_17c = local_17c + 1;
      if (local_17c == numphysent) goto LAB_00132630;
      local_180 = local_178;
      if ((local_17c != 0) && ((traceFlags & 8U) != 0)) goto LAB_00132630;
      local_178 = local_178 + 1;
      if (pfnIgnore != (_func_int_physent_t_ptr *)0x0) goto LAB_00132010;
LAB_001323e8:
    } while ((local_17c == ignore_pe) && (ignore_pe != -1));
  } while( true );
}


// _PM_TestPlayerPosition  @ 00131a70
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
            goto LAB_00131bb9;
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
          if ((pe->solid == 0) && (pe->skin != 0)) goto LAB_00131c60;
          local_5c = pe->origin[0];
          local_2c[0] = 1;
          local_58 = pe->origin[1];
          local_54 = pe->origin[2];
          hull = PM_HullForBsp(pe,&local_5c);
        }
LAB_00131bb9:
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
LAB_00131c60:
      local_104 = local_104 + 1;
    } while (local_104 < pmove->numphysent);
  }
  return -1;
}


// _VectorAdd  @ 0012bbc0
void _VectorAdd(vec_t *veca,vec_t *vecb,vec_t *out)

{
  *out = *veca + *vecb;
  out[1] = veca[1] + vecb[1];
  out[2] = veca[2] + vecb[2];
  return;
}


// _VectorCopy  @ 0012bbf0
void _VectorCopy(vec_t *in,vec_t *out)

{
  *out = *in;
  out[1] = in[1];
  out[2] = in[2];
  return;
}


// _VectorSubtract  @ 0012bb90
void _VectorSubtract(vec_t *veca,vec_t *vecb,vec_t *out)

{
  *out = *veca - *vecb;
  out[1] = veca[1] - vecb[1];
  out[2] = veca[2] - vecb[2];
  return;
}


// __CreateBaseUISurfaceISurface_interface  @ 0021da00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

IBaseInterface * __CreateBaseUISurfaceISurface_interface(void)

{
  return (IBaseInterface *)&g_BaseUISurface;
}


// __CreateCBaseUIIBaseUI_interface  @ 0021c860
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

IBaseInterface * __CreateCBaseUIIBaseUI_interface(void)

{
  return (IBaseInterface *)&g_BaseUI;
}


// __CreateCDedicatedServerAPIIDedicatedServerAPI_interface  @ 00149410
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

IBaseInterface * __CreateCDedicatedServerAPIIDedicatedServerAPI_interface(void)

{
  return (IBaseInterface *)&__g_CDedicatedServerAPI_singleton;
}


// __CreateCEngineAPIIEngineAPI_interface  @ 00149400
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

IBaseInterface * __CreateCEngineAPIIEngineAPI_interface(void)

{
  return (IBaseInterface *)&__g_CEngineAPI_singleton;
}


// __CreateCEngineVGuiIEngineVGui_interface  @ 0021c990
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

IBaseInterface * __CreateCEngineVGuiIEngineVGui_interface(void)

{
  return (IBaseInterface *)&__g_CEngineVGui_singleton;
}


// __CreateCGameUIFuncsIGameUIFuncs_interface  @ 00149420
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

IBaseInterface * __CreateCGameUIFuncsIGameUIFuncs_interface(void)

{
  return (IBaseInterface *)&__g_CGameUIFuncs_singleton;
}


// __CreateCServerRemoteAccessIGameServerData_interface  @ 0017c7c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

IBaseInterface * __CreateCServerRemoteAccessIGameServerData_interface(void)

{
  return (IBaseInterface *)&g_ServerRemoteAccess;
}


// __CreateEngineSurfaceIEngineSurface_interface  @ 0020cb50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

IBaseInterface * __CreateEngineSurfaceIEngineSurface_interface(void)

{
  return (IBaseInterface *)&__g_EngineSurface_singleton;
}


// __do_global_ctors_aux  @ 0027b790
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void __do_global_ctors_aux(void)

{
  undefined **ppuVar1;
  
  for (ppuVar1 = &PTR__GLOBAL__sub_I_g_ButtonSoundNames_002e51e8;
      (code *)*ppuVar1 != (code *)0xffffffff; ppuVar1 = ppuVar1 + -1) {
    (*(code *)*ppuVar1)();
  }
  return;
}


// __do_global_dtors_aux  @ 00104dc8
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Removing unreachable block (ram,0x00104e11) */

void __do_global_dtors_aux(void)

{
  if (completed_5793 == '\0') {
    __cxa_finalize(__dso_handle);
    completed_5793 = '\x01';
  }
  return;
}


// __i686.get_pc_thunk.bx  @ 00104e6e
/* WARNING: This is an inlined function */

void __i686_get_pc_thunk_bx(void)

{
  return;
}


// _fini  @ 0027b7b8
void _fini(void)

{
  __do_global_dtors_aux();
  return;
}


// _init  @ 00103bdc
int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  __gmon_start__();
  frame_dummy();
  iVar1 = __do_global_ctors_aux();
  return iVar1;
}


