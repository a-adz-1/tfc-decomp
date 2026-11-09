// FUN_00098d90  @ 00098d90
void FUN_00098d90(void)

{
  (*(code *)(undefined *)0x0)();
  return;
}


// FUN_001ebbaf  @ 001ebbaf
undefined4 FUN_001ebbaf(void)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  char cVar4;
  undefined4 in_EAX;
  int iVar6;
  undefined4 *in_EDX;
  int unaff_EBX;
  int unaff_EBP;
  int *piVar5;
  
  cVar4 = (char)in_EAX + *(char *)(unaff_EBP + 0x3b840fc0);
  piVar5 = (int *)CONCAT31((int3)((uint)in_EAX >> 8),cVar4);
  *piVar5 = *piVar5 + (int)piVar5;
  *(char *)(unaff_EBX + 0x178b0cec) = *(char *)(unaff_EBX + 0x178b0cec) + cVar4;
  iVar6 = (*(code *)*in_EDX)();
  if (iVar6 == 0) {
    uVar2 = *(uint *)(unaff_EBP + -0x40);
    puVar3 = *(uint **)(unaff_EBP + 0xc);
    iVar6 = *(int *)(unaff_EBP + -0x3c);
    **(uint **)(unaff_EBP + 0x18) = uVar2;
    uVar1 = *puVar3;
    *puVar3 = *puVar3 + uVar2;
    puVar3[1] = puVar3[1] + iVar6 + (uint)CARRY4(uVar1,uVar2);
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("status == 0","mkvparser.cpp",0x1c3,
                "bool mkvparser::Match(mkvparser::IMkvReader*, long long int&, long unsigned int, unsigned char*&, size_t&)"
               );
}


// FUN_0021d101  @ 0021d101
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */

void FUN_0021d101(undefined4 param_1,RichText *param_2,wchar_t *param_3)

{
  wchar_t wVar1;
  int iVar2;
  _func_int_varargs **pp_Var3;
  size_t __size;
  wchar_t *pwVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  int local_1c;
  
                    /* Unresolved local var: wchar_t * ch@[???] */
  wVar1 = *param_3;
  do {
    if (wVar1 == L'\0') {
      (*(param_2->super_Panel).super_IClientPanel._vptr_IClientPanel[0x3b])(param_2,0,0);
      pp_Var3 = (param_2->super_Panel).super_IClientPanel._vptr_IClientPanel;
      param_2->m_bRecalcLineBreaks = true;
                    /* WARNING: Could not recover jumptable at 0x0021d2be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*pp_Var3[4])();
      return;
    }
    if ((char)wVar1 != '\r') {
      iVar6 = (param_2->m_TextStream).m_Size;
                    /* try { // try from 0021d1d7 to 0022d1db has its CatchHandler @ 0021cef0 */
      if ((0 < param_2->_maxCharCount) && (param_2->_maxCharCount < iVar6)) {
                    /* catch() { ... } // from try @ 0021d0d5 with catch @ 0021d1dc */
                    /* catch() { ... } // from try @ 0021d04c with catch @ 0021d1e0 */
        vgui2::RichText::TruncateTextStream(param_2);
        iVar6 = (param_2->m_TextStream).m_Size;
      }
      iVar2 = (param_2->m_TextStream).m_Memory.m_NumAllocated;
      iVar7 = iVar6 + 1;
                    /* catch() { ... } // from try @ 0021d268 with catch @ 0021d200 */
      if (iVar2 < iVar7) {
                    /* Unresolved local var: int nNeed@[???]
                       Unresolved local var: int nGrowSize@[???] */
        local_1c = (param_2->m_TextStream).m_Memory.m_GrowSize;
        if (local_1c <= iVar7 - iVar2) {
          bVar8 = -1 < local_1c;
          local_1c = iVar7 - iVar2;
          if (bVar8) goto LAB_0021d244;
          goto LAB_0021d202;
        }
                    /* Unresolved local var: int growSize@[???] */
        if ((local_1c < 1) && (local_1c == 0)) {
          iVar5 = 1;
          if (iVar2 != 0) {
            iVar5 = iVar2;
          }
                    /* Unresolved local var: int growSize@[???] */
          pwVar4 = (param_2->m_TextStream).m_Memory.m_pMemory;
          (param_2->m_TextStream).m_Memory.m_NumAllocated = iVar2 + iVar5;
          __size = (iVar2 + iVar5) * 4;
          if (pwVar4 == (wchar_t *)0x0) goto LAB_0021d262;
LAB_0021d16b:
          pwVar4 = realloc(pwVar4,__size);
          iVar7 = (param_2->m_TextStream).m_Size + 1;
          (param_2->m_TextStream).m_Memory.m_pMemory = pwVar4;
        }
        else {
LAB_0021d244:
          pwVar4 = (param_2->m_TextStream).m_Memory.m_pMemory;
          (param_2->m_TextStream).m_Memory.m_NumAllocated = iVar2 + local_1c;
                    /* catch() { ... } // from try @ 0021d237 with catch @ 0021d257 */
          __size = (iVar2 + local_1c) * 4;
          if (pwVar4 != (wchar_t *)0x0) goto LAB_0021d16b;
LAB_0021d262:
                    /* try { // try from 0021d268 to 0022d26c has its CatchHandler @ 0021d200 */
          pwVar4 = malloc(__size);
          (param_2->m_TextStream).m_Memory.m_pMemory = pwVar4;
        }
        (param_2->m_TextStream).m_Size = iVar7;
                    /* Unresolved local var: int numToMove@[???] */
        iVar7 = iVar7 - iVar6;
      }
      else {
LAB_0021d202:
        (param_2->m_TextStream).m_Size = iVar7;
        iVar7 = iVar7 - iVar6;
        pwVar4 = (param_2->m_TextStream).m_Memory.m_pMemory;
      }
      if (0 < iVar7 + -1) {
        memmove(pwVar4 + iVar6 + 1,pwVar4 + iVar6,(iVar7 + -1) * 4);
        pwVar4 = (param_2->m_TextStream).m_Memory.m_pMemory;
      }
      if (pwVar4 + iVar6 != (wchar_t *)0x0) {
        pwVar4[iVar6] = wVar1;
      }
      param_2->_recalculateBreaksIndex = (param_2->m_LineBreaks).m_Size + -2;
      (*(param_2->super_Panel).super_IClientPanel._vptr_IClientPanel[4])(param_2);
    }
    param_3 = param_3 + 1;
    wVar1 = *param_3;
                    /* catch() { ... } // from try @ 0021d0be with catch @ 0021d1c0 */
  } while( true );
}


// _DELTA_WriteDelta  @ 000ac400
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
      goto LAB_000ac4da;
    }
    data = 0;
LAB_000ac4a1:
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
    if (callback != (_func_void *)0x0) goto LAB_000ac4a1;
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
LAB_000ac4da:
  DELTA_WriteMarkedFields(from,to,pFields);
  return 1;
}


// _DotProduct  @ 000c5d60
vec_t _DotProduct(vec_t *v1,vec_t *v2)

{
  return v1[2] * v2[2] + v1[1] * v2[1] + *v1 * *v2;
}


// _GLOBAL__sub_I_CheckIP  @ 00099570
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_CheckIP(void)

{
  CIPRateLimit::CIPRateLimit(&rateChecker);
  __cxa_atexit(CIPRateLimit::~CIPRateLimit,&rateChecker,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_D_SurfaceCacheForRes  @ 00099280
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_D_SurfaceCacheForRes(void)

{
  __cxa_atexit(CEngineAPI::~CEngineAPI,&__g_CEngineAPI_singleton,&__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateCEngineAPIIEngineAPI_reg,__CreateCEngineAPIIEngineAPI_interface,
             "VENGINE_LAUNCHER_API_VERSION002");
  __g_CDedicatedServerAPI_singleton.super_IDedicatedServerAPI.super_IBaseInterface.
  _vptr_IBaseInterface = (IBaseInterface)&PTR__CDedicatedServerAPI_0025c714;
  __cxa_atexit(CDedicatedServerAPI::~CDedicatedServerAPI,&__g_CDedicatedServerAPI_singleton,
               &__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateCDedicatedServerAPIIDedicatedServerAPI_reg,
             __CreateCDedicatedServerAPIIDedicatedServerAPI_interface,"VENGINE_HLDS_API_VERSION002")
  ;
  __cxa_atexit(CGameUIFuncs::~CGameUIFuncs,&__g_CGameUIFuncs_singleton,&__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateCGameUIFuncsIGameUIFuncs_reg,__CreateCGameUIFuncsIGameUIFuncs_interface,
             "VENGINE_GAMEUIFUNCS_VERSION001");
  return;
}


// _GLOBAL__sub_I_MP3digitalDriver  @ 00099a10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_MP3digitalDriver(void)

{
  CCDAudio::CCDAudio(&g_CDAudio);
  __cxa_atexit(CCDAudio::~CCDAudio,&g_CDAudio,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_VGUI2_Draw_Init  @ 00099ba0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_VGUI2_Draw_Init(void)

{
  _col._color[0] = 0xff;
  _col._color[1] = 0xff;
  _col._color[2] = 0xff;
  _col._color[3] = 0xff;
  return;
}


// _GLOBAL__sub_I__Z11FontManagerv  @ 00099d80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Enum "FT_Encoding_": Some values do not have unique names */

void _GLOBAL__sub_I__Z11FontManagerv(void)

{
  CFontManager::CFontManager(&s_FontManager);
  __cxa_atexit(CFontManager::~CFontManager,&s_FontManager,&__dso_handle);
  return;
}


// _GLOBAL__sub_I__Z15COM_BuildNumberv  @ 00099350
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__Z15COM_BuildNumberv(void)

{
  int in_stack_ffffffe8;
  void **in_stack_ffffffec;
  
  SystemWrapper::SystemWrapper(&gSystemWrapper,in_stack_ffffffe8,in_stack_ffffffec);
  __cxa_atexit(SystemWrapper::~SystemWrapper,&gSystemWrapper,&__dso_handle);
  return;
}


// _GLOBAL__sub_I__ZN10CUtlSymbol14s_pSymbolTableE  @ 00099e30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN10CUtlSymbol14s_pSymbolTableE(void)

{
  g_LessCtx.m_pUserString = (char *)0x0;
  g_LessCtx.m_pTable = (CUtlSymbolTable *)0x0;
  return;
}


// _GLOBAL__sub_I__ZN10EngineFont11GetTextSizeEPKcRiS2_  @ 00099d40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN10EngineFont11GetTextSizeEPKcRiS2_(void)

{
  staticFontPlatDar._count = 0;
  staticFontPlatDar._capacity = 0;
  staticFontPlatDar._data = (BaseFontPlat **)0x0;
  __cxa_atexit(vgui2::Dar<BaseFontPlat*>::~Dar,&staticFontPlatDar,&__dso_handle);
  return;
}


// _GLOBAL__sub_I__ZN12CInitTrackerC2Ev  @ 00099400
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


// _GLOBAL__sub_I__ZN13EngineSurface17freeEngineSurfaceEv  @ 000999c0
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


// _GLOBAL__sub_I__ZN15DownloadManagerC2Ev  @ 000995b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN15DownloadManagerC2Ev(void)

{
  DownloadManager::DownloadManager(&TheDownloadManager);
  __cxa_atexit(DownloadManager::~DownloadManager,&TheDownloadManager,&__dso_handle);
  return;
}


// _GLOBAL__sub_I__ZN17EngineSurfaceWrapC2EPN4vgui5PanelEP14IEngineSurface  @ 00099920
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN17EngineSurfaceWrapC2EPN4vgui5PanelEP14IEngineSurface(void)

{
  int iVar1;
  FontInfoVGUI **ppFVar2;
  FontInfoVGUI **ppFVar3;
  int iVar4;
  int iVar5;
  FontInfoVGUI **ppFVar6;
  byte bVar7;
  
  bVar7 = 0;
                    /* Unresolved local var: int newCapacity@[???]
                       Unresolved local var: FontInfoVGUI * * newData@[???] */
  staticFontInfoVGUIDar._count = 0;
  staticFontInfoVGUIDar._capacity = 0;
  staticFontInfoVGUIDar._data = (FontInfoVGUI **)0x0;
  ppFVar3 = operator_new__(0x10);
  iVar4 = staticFontInfoVGUIDar._count;
  if (ppFVar3 != (FontInfoVGUI **)0x0) {
    ppFVar6 = ppFVar3;
                    /* Unresolved local var: int i@[???] */
    for (iVar5 = 4; ppFVar2 = staticFontInfoVGUIDar._data, iVar1 = staticFontInfoVGUIDar._count,
        iVar5 != 0; iVar5 = iVar5 + -1) {
      *ppFVar6 = (FontInfoVGUI *)0x0;
      ppFVar6 = ppFVar6 + (uint)bVar7 * -2 + 1;
    }
    staticFontInfoVGUIDar._capacity = 4;
    if (0 < iVar4) {
      iVar4 = 0;
      do {
        ppFVar3[iVar4] = ppFVar2[iVar4];
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
    if (staticFontInfoVGUIDar._data != (FontInfoVGUI **)0x0) {
      operator_delete__(staticFontInfoVGUIDar._data);
    }
    staticFontInfoVGUIDar._data = ppFVar3;
    return;
  }
                    /* WARNING: Subroutine does not return */
  exit(0);
}


// _GLOBAL__sub_I__ZN5vgui210g_pSurfaceE  @ 00099bc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN5vgui210g_pSurfaceE(void)

{
  g_BaseUI.super_IBaseUI.super_IBaseInterface._vptr_IBaseInterface =
       (IBaseInterface)&PTR__CBaseUI_00271e8c;
  g_BaseUI.m_hStaticGameUIModule = (CSysModule *)0x0;
  g_pBaseUI = &g_BaseUI;
  g_BaseUI.m_hVGuiModule = (CSysModule *)0x0;
  m_bConsoleShowing = false;
  g_BaseUI.m_bHidingGameUI = false;
  __cxa_atexit(CBaseUI::~CBaseUI,&g_BaseUI,&__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateCBaseUIIBaseUI_reg,__CreateCBaseUIIBaseUI_interface,"BaseUI001");
  __g_CEngineVGui_singleton.super_IEngineVGui.super_IBaseInterface._vptr_IBaseInterface =
       (IBaseInterface)&PTR__CEngineVGui_00271ec4;
  __g_CEngineVGui_singleton.m_hRefreshLoginHandle = 0;
  __g_CEngineVGui_singleton.m_bVisible = true;
  __cxa_atexit(CEngineVGui::~CEngineVGui,&__g_CEngineVGui_singleton,&__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateCEngineVGuiIEngineVGui_reg,__CreateCEngineVGuiIEngineVGui_interface,
             "VEngineVGui001");
  return;
}


// _GLOBAL__sub_I_eng  @ 00099390
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_eng(void)

{
  g_Engine.super_IEngine._vptr_IEngine = (_func_int_varargs **)&PTR__CEngine_0025d1f8;
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


// _GLOBAL__sub_I_g_BaseUISurface  @ 00099c90
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


// _GLOBAL__sub_I_g_ButtonSoundNames  @ 00099e40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_ButtonSoundNames(void)

{
  CUtlSymbolTable::CUtlSymbolTable(&g_ButtonSoundNames,0,0x20,false);
  __cxa_atexit(CUtlSymbolTable::~CUtlSymbolTable,&g_ButtonSoundNames,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_g_FileSystemFactory  @ 00099230
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_FileSystemFactory(void)

{
  g_fallbackLocalizationFiles.m_Memory.m_pMemory = (char **)0x0;
  g_fallbackLocalizationFiles.m_Size = 0;
  g_fallbackLocalizationFiles.m_Memory.m_NumAllocated = 0;
  g_fallbackLocalizationFiles.m_Memory.m_GrowSize = 0;
  __cxa_atexit(CUtlVector<char*>::~CUtlVector,&g_fallbackLocalizationFiles,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_g_ScissorRect  @ 00099660
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_ScissorRect(void)

{
  g_VGuiSurfaceTextures.m_Elements.m_NumAllocated = 0x80;
  g_VGuiSurfaceTextures.m_Elements.m_GrowSize = 0;
  g_VGuiSurfaceTextures.m_LessFunc = VguiSurfaceTexturesLessFunc;
  g_VGuiSurfaceTextures.m_Elements.m_pMemory = malloc(0x1600);
  g_VGuiSurfaceTextures.m_Root = -1;
  g_VGuiSurfaceTextures.m_NumElements = 0;
  g_VGuiSurfaceTextures.m_FirstFree = -1;
  g_VGuiSurfaceTextures.m_TotalElements = 0;
  __cxa_atexit(CUtlRBTree<(anonymous_namespace)::Texture,_int>::~CUtlRBTree,&g_VGuiSurfaceTextures,
               &__dso_handle);
  return;
}


// _GLOBAL__sub_I_g_ServerRemoteAccess  @ 000994c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_ServerRemoteAccess(void)

{
  g_ServerRemoteAccess.super_IGameServerData.super_IBaseInterface._vptr_IBaseInterface =
       (IBaseInterface)&PTR__CServerRemoteAccess_002619ac;
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


// _GLOBAL__sub_I_g_TempConsoleBuffer  @ 00099850
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_TempConsoleBuffer(void)

{
  g_TempConsoleBuffer.m_Memory.m_GrowSize = 0;
  g_TempConsoleBuffer.m_Memory.m_NumAllocated = 0x400;
  g_TempConsoleBuffer.m_Memory.m_pMemory = malloc(0x400);
  g_TempConsoleBuffer.m_Size = 0;
  __cxa_atexit(CUtlVector<char>::~CUtlVector,&g_TempConsoleBuffer,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_g_VoiceSampleFormat  @ 000998d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Struct "CSizedCircularBuffer<22050>": ignoring overlapping field "myData" */

void _GLOBAL__sub_I_g_VoiceSampleFormat(void)

{
  CCircularBuffer *this;
  CCircularBuffer *pCVar1;
  
  this = &g_VoiceChannels[0].m_Buffer.super_CCircularBuffer;
  do {
    CCircularBuffer::CCircularBuffer(this,0x5622);
    pCVar1 = this + 0x453;
    CAutoGain::CAutoGain((CAutoGain *)&this[0x450].m_nWrite);
    *(undefined4 *)this[-1].m_chData = 0xffffffff;
    this[0x450].m_nRead = 0;
    this = pCVar1;
  } while (pCVar1 != (CCircularBuffer *)&g_pMixerControls);
  return;
}


// _GLOBAL__sub_I_g_nFakeIP  @ 000995f0
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


// _GLOBAL__sub_I_game  @ 00099aa0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_game(void)

{
  g_Game.super_IGame._vptr_IGame = (_func_int_varargs **)&PTR__CGame_00270530;
  g_Game.m_height = 0;
  g_Game.m_width = 0;
  g_Game.m_nMouseTargetX = 0;
  g_Game.m_nMouseTargetY = 0;
  g_Game.m_y = 0;
  g_Game.m_nWarpDelta = 0;
  g_Game.m_x = 0;
  g_Game.m_bActiveApp = true;
  g_Game.m_bMultiplayer = false;
  g_Game.m_bExpectSyntheticMouseMotion = false;
  g_Game.m_bCursorVisible = true;
  g_Game.m_bLegacyRender = false;
  __cxa_atexit(CGame::~CGame,&g_Game,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_pmainwindow  @ 000998b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_pmainwindow(void)

{
  vgui::App::App(&theApp.super_App);
  theApp._0_4_ = &PTR_start_0026de54;
  return;
}


// _GLOBAL__sub_I_r_detailtextures  @ 000996e0
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
  g_idMap._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  g_idMap._M_t._M_impl._M_node_count = 0;
  g_idMap._M_t._M_impl._M_header._M_left = &g_idMap._M_t._M_impl._M_header;
  g_idMap._M_t._M_impl._M_header._M_right = &g_idMap._M_t._M_impl._M_header;
  __cxa_atexit(std::
               map<int,_DetailMap*,_std::less<int>,_std::allocator<std::pair<int_const,_DetailMap*>_>_>
               ::~map,&g_idMap,&__dso_handle);
  g_detailNameToIdMap._M_t._M_impl._M_header._M_color = _S_red;
  g_detailNameToIdMap._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  g_detailNameToIdMap._M_t._M_impl._M_node_count = 0;
  g_detailNameToIdMap._M_t._M_impl._M_header._M_left = &g_detailNameToIdMap._M_t._M_impl._M_header;
  g_detailNameToIdMap._M_t._M_impl._M_header._M_right = &g_detailNameToIdMap._M_t._M_impl._M_header;
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
  g_levelName._M_dataplus._M_p = (_Alloc_hider)&std::nothrow;
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


// _GLOBAL__sub_I_registry  @ 00099b30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_registry(void)

{
  g_Registry.super_IRegistry._vptr_IRegistry = (_func_int_varargs **)&PTR_Init_0027173c;
  g_Registry.m_vecValues.m_Memory.m_GrowSize = 0;
  g_Registry.m_vecValues.m_Size = 0;
  g_Registry.m_hKey = 0;
  g_Registry.m_fConfig = (FILE *)0x0;
  g_Registry.m_vecValues.m_Memory.m_pMemory = (KV *)0x0;
  g_Registry.m_vecValues.m_Memory.m_NumAllocated = 0;
  g_Registry.m_bValid = false;
  __cxa_atexit(CRegistry::~CRegistry,&g_Registry,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_s_bSupportsUnicode  @ 00099dc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_s_bSupportsUnicode(void)

{
  CLinuxFont::m_FriendlyNameCache.m_LessFunc = (LessFunc_t)0x0;
  CLinuxFont::m_FriendlyNameCache.m_Elements.m_GrowSize = 0;
  CLinuxFont::m_FriendlyNameCache.m_Root = -1;
  CLinuxFont::m_FriendlyNameCache.m_NumElements = 0;
  CLinuxFont::m_FriendlyNameCache.m_FirstFree = -1;
  CLinuxFont::m_FriendlyNameCache.m_Elements.m_pMemory = (Node_t *)0x0;
  CLinuxFont::m_FriendlyNameCache.m_TotalElements = 0;
  CLinuxFont::m_FriendlyNameCache.m_Elements.m_NumAllocated = 0;
  __cxa_atexit(CUtlRBTree<CLinuxFont::font_name_entry,_int>::~CUtlRBTree,
               &CLinuxFont::m_FriendlyNameCache,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_thread  @ 00099a50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_thread(void)

{
  g_Thread.super_IThread._vptr_IThread = (_func_int_varargs **)&PTR__CThread_0026ff10;
  g_Thread.m_bThreadRunning = false;
  g_Thread.m_dwThreadID = 0;
  g_Thread.m_cSet = 0;
  g_Thread.m_bThreadStopped = false;
  __cxa_atexit(CThread::~CThread,&g_Thread,&__dso_handle);
  return;
}


// _Host_Frame  @ 000b8f20
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
    if (bVar1) goto LAB_000b9065;
    giActive = 2;
  }
  Host_CheckConnectionFailure::frames = 5;
LAB_000b9065:
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


// _PM_PlayerTrace  @ 000cc560
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
LAB_000cca90:
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
  if (pfnIgnore == (_func_int_physent_t_ptr *)0x0) goto LAB_000cc9d1;
LAB_000cc630:
  iVar10 = (*pfnIgnore)(physents);
  if (iVar10 != 0) goto LAB_000cc990;
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
LAB_000ccc74:
          iVar10 = pmove->usehull;
LAB_000ccc7a:
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
          if ((traceFlags & 1U) != 0) goto LAB_000cc990;
          if (pModel->type != mod_studio) goto LAB_000ccc74;
          iVar10 = pmove->usehull;
          if (((pModel->flags & 0x200) == 0) && ((iVar10 != 2 || ((traceFlags & 2U) != 0))))
          goto LAB_000ccc7a;
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
        goto LAB_000cc6e4;
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
          if (angles[5] != 0.0) goto LAB_000cc990;
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
LAB_000cc6e4:
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
LAB_000ccd01:
          local_e8.allsolid = false;
          if (local_e8.startsolid != false) {
LAB_000cc8ec:
            local_e8.fraction = 0.0;
            goto LAB_000cc8f9;
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
                goto LAB_000cce78;
              }
              PM_RecursiveHullCheck
                        (hull,iVar10,(float)&local_118,0.0,(vec_t *)0x3f800000,&local_10c,&local_e8)
              ;
              goto LAB_000cc8d1;
            }
            if (iVar10 != -2) {
              local_e8.allsolid = false;
              if (iVar10 != -1) {
                local_e8.inwater = true;
                goto LAB_000ccd01;
              }
LAB_000cce78:
              local_e8.inopen = true;
              goto LAB_000ccd01;
            }
LAB_000cc8e0:
            local_e8.startsolid = true;
            goto LAB_000cc8ec;
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
                if (num == -1) goto LAB_000cca01;
                local_60.inwater = true;
                goto LAB_000cca0d;
              }
              local_60.startsolid = true;
LAB_000cc862:
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
                if ((iVar14 == 0) || ((float)local_60.allsolid != 0.0)) goto LAB_000cc862;
              }
              else {
                local_60.allsolid = false;
LAB_000cca01:
                local_60.inopen = true;
LAB_000cca0d:
                local_60.allsolid = false;
                if (iVar14 == 0) goto LAB_000cc862;
              }
              if (((float)local_60.startsolid != 0.0) || (local_60.fraction < local_e8.fraction))
              goto LAB_000cc862;
            }
            iVar14 = iVar14 + 1;
            hull = hull + 1;
            local_e8.hitgroup = SV_HitgroupForStudioHull(iVar10);
          } while (iVar14 < local_11c);
LAB_000cc8d1:
          if (local_e8.allsolid != false) goto LAB_000cc8e0;
          if (local_e8.startsolid != false) goto LAB_000cc8ec;
          if (local_e8.fraction == 1.0) goto LAB_000cc947;
LAB_000cc8f9:
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
LAB_000cc947:
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
LAB_000cc990:
    do {
      local_138 = local_138 + 1;
      if ((numphysent == local_138) || ((local_138 != 0 && ((traceFlags & 8U) != 0))))
      goto LAB_000cca90;
      pvVar13 = angles + 0x38;
      physents = (physent_t *)(angles + 0x23);
      angles = pvVar13;
      if (pfnIgnore != (_func_int_physent_t_ptr *)0x0) goto LAB_000cc630;
LAB_000cc9d1:
    } while ((ignore_pe != -1) && (ignore_pe == local_138));
  } while( true );
}


// _PM_TestPlayerPosition  @ 000ccfb0
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
  playermove_t_conflict *ppVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  hull_t *phVar14;
  playermove_t_conflict *ppVar15;
  int iVar16;
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
  iVar12 = 0;
  ppVar15 = pmove;
  if (0 < pmove->numphysent) {
    do {
      ppVar10 = ppVar15;
      if ((pfnIgnore == (_func_int_physent_t_ptr *)0x0) ||
         (iVar9 = (*pfnIgnore)(ppVar15->physents + iVar12), ppVar10 = pmove, iVar9 == 0)) {
        pmVar7 = ppVar15->physents[iVar12].model;
        if (pmVar7 == (model_s *)0x0) {
          pModel = ppVar15->physents[iVar12].studiomodel;
          fVar3 = ppVar15->physents[iVar12].origin[0];
          fVar4 = ppVar15->physents[iVar12].origin[1];
          fVar5 = ppVar15->physents[iVar12].origin[2];
          local_cc = 1;
          if ((pModel == (model_t *)0x0) || (pModel->type != mod_studio)) {
            iVar9 = ppVar10->usehull;
          }
          else {
            iVar9 = ppVar10->usehull;
            if (((pModel->flags & 0x200) != 0) || (iVar9 == 2)) {
                    /* Unresolved local var: vec3_t size@[???] */
              local_60.allsolid = (qboolean)(player_maxs[iVar9][0] - player_mins[iVar9][0]);
              iVar11 = ppVar15->physents[iVar12].sequence;
              fVar3 = ppVar15->physents[iVar12].frame;
              local_60.startsolid = (qboolean)(player_maxs[iVar9][1] - player_mins[iVar9][1]);
              local_60.inopen = (qboolean)(player_maxs[iVar9][2] - player_mins[iVar9][2]);
              VectorScale((vec_t *)&local_60,0.5,(vec_t *)&local_60);
              phVar14 = R_StudioHull(pModel,fVar3,iVar11,ppVar15->physents[iVar12].angles,
                                     ppVar15->physents[iVar12].origin,(vec_t *)&local_60,
                                     ppVar15->physents[iVar12].controller,
                                     ppVar15->physents[iVar12].blending,&local_cc,(edict_t *)0x0,0);
              iVar11 = ppVar15->physents[iVar12].solid;
              fVar5 = 0.0;
              fVar4 = 0.0;
              fVar3 = 0.0;
              goto LAB_000cd157;
            }
          }
          phVar14 = &box_hull;
          iVar11 = ppVar15->physents[iVar12].solid;
          box_planes[1].dist = ppVar15->physents[iVar12].mins[0] - player_maxs[iVar9][0];
          box_planes[3].dist = ppVar15->physents[iVar12].mins[1] - player_maxs[iVar9][1];
          box_planes[5].dist = ppVar15->physents[iVar12].mins[2] - player_maxs[iVar9][2];
          box_planes[2].dist = ppVar15->physents[iVar12].maxs[1] - player_mins[iVar9][1];
          box_planes[4].dist = ppVar15->physents[iVar12].maxs[2] - player_mins[iVar9][2];
          box_planes[0].dist = ppVar15->physents[iVar12].maxs[0] - player_mins[iVar9][0];
        }
        else {
          iVar11 = ppVar15->physents[iVar12].solid;
          if ((iVar11 == 0) && (ppVar15->physents[iVar12].skin != 0)) goto LAB_000cd0b0;
          local_cc = 1;
                    /* Unresolved local var: hull_t * hull@[???] */
          iVar9 = ppVar10->usehull;
          if (iVar9 == 2) {
            phVar14 = pmVar7->hulls;
          }
          else if (iVar9 == 3) {
            phVar14 = pmVar7->hulls + 2;
          }
          else {
            phVar14 = pmVar7->hulls + 1;
            if (iVar9 == 1) {
              phVar14 = pmVar7->hulls + 3;
            }
          }
          fVar3 = (phVar14->clip_mins[0] - player_mins[iVar9][0]) +
                  ppVar15->physents[iVar12].origin[0];
          fVar4 = (phVar14->clip_mins[1] - player_mins[iVar9][1]) +
                  ppVar15->physents[iVar12].origin[1];
          fVar5 = (phVar14->clip_mins[2] - player_mins[iVar9][2]) +
                  ppVar15->physents[iVar12].origin[2];
        }
LAB_000cd157:
        fVar3 = *pos - fVar3;
        fVar4 = pos[1] - fVar4;
        local_c8[0] = fVar3;
        fVar5 = pos[2] - fVar5;
        local_c8[1] = fVar4;
        local_c8[2] = fVar5;
        ppVar10 = pmove;
        if ((iVar11 == 4) &&
           (((ppVar15->physents[iVar12].angles[0] != 0.0 ||
             (ppVar15->physents[iVar12].angles[1] != 0.0)) ||
            (ppVar15->physents[iVar12].angles[2] != 0.0)))) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t temp@[???] */
          AngleVectors(ppVar15->physents[iVar12].angles,local_c8 + 3,&local_b0,(vec_t *)&local_60);
          local_c8[0] = local_b4 * fVar5 + local_b8 * fVar4 + local_c8[3] * fVar3;
          local_c8[1] = -(fStack_a8 * fVar5 + local_ac * fVar4 + local_b0 * fVar3);
          local_c8[2] = fVar3 * (float)local_60.allsolid + (float)local_60.startsolid * fVar4 +
                        (float)local_60.inopen * fVar5;
          ppVar10 = pmove;
        }
        pmove = ppVar10;
        if (local_cc == 1) {
          iVar9 = phVar14->firstclipnode;
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???] */
          if (iVar9 < phVar14->lastclipnode) {
            iVar11 = iVar9;
            if (-1 < iVar9) {
              do {
                if ((iVar11 < iVar9) || (phVar14->lastclipnode < iVar11)) {
                    /* WARNING: Subroutine does not return */
                  Sys_Error("PM_HullPointContents: bad node number");
                }
                pdVar1 = phVar14->clipnodes + iVar11;
                pmVar2 = phVar14->planes + pdVar1->planenum;
                if (pmVar2->type < 3) {
                  if (0.0 <= local_c8[pmVar2->type] - pmVar2->dist) goto LAB_000cd495;
LAB_000cd4f5:
                  sVar6 = pdVar1->children[1];
                }
                else {
                  if ((local_c8[2] * pmVar2->normal[2] +
                      local_c8[1] * pmVar2->normal[1] + local_c8[0] * pmVar2->normal[0]) -
                      pmVar2->dist < 0.0) goto LAB_000cd4f5;
LAB_000cd495:
                  sVar6 = pdVar1->children[0];
                }
                iVar11 = (int)sVar6;
                if (iVar11 < 0) break;
                iVar9 = phVar14->firstclipnode;
              } while( true );
            }
            if (iVar11 == -2) {
              return iVar12;
            }
          }
        }
        else {
          piVar13 = &phVar14->firstclipnode;
          iVar9 = 0;
          if (0 < local_cc) {
            do {
              iVar11 = *piVar13;
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???] */
              if (iVar11 < piVar13[1]) {
                iVar16 = iVar11;
                if (-1 < iVar11) {
                  do {
                    if ((iVar16 < iVar11) || (piVar13[1] < iVar16)) {
                    /* WARNING: Subroutine does not return */
                      Sys_Error("PM_HullPointContents: bad node number");
                    }
                    pdVar1 = ((hull_t *)(piVar13 + -2))->clipnodes + iVar16;
                    pmVar2 = (mplane_t *)piVar13[-1] + pdVar1->planenum;
                    if (pmVar2->type < 3) {
                      if (0.0 <= local_c8[pmVar2->type] - pmVar2->dist) goto LAB_000cd1e7;
LAB_000cd243:
                      sVar6 = pdVar1->children[1];
                    }
                    else {
                      if ((local_c8[2] * pmVar2->normal[2] +
                          local_c8[1] * pmVar2->normal[1] + local_c8[0] * pmVar2->normal[0]) -
                          pmVar2->dist < 0.0) goto LAB_000cd243;
LAB_000cd1e7:
                      sVar6 = pdVar1->children[0];
                    }
                    iVar16 = (int)sVar6;
                    if (iVar16 < 0) break;
                    iVar11 = *piVar13;
                  } while( true );
                }
                if (iVar16 == -2) {
                  return iVar12;
                }
              }
              iVar9 = iVar9 + 1;
              piVar13 = piVar13 + 10;
            } while (iVar9 < local_cc);
          }
        }
      }
LAB_000cd0b0:
      iVar12 = iVar12 + 1;
      ppVar15 = ppVar10;
    } while (iVar12 < ppVar10->numphysent);
  }
  return -1;
}


// _VectorAdd  @ 000c5db0
void _VectorAdd(vec_t *veca,vec_t *vecb,vec_t *out)

{
  *out = *veca + *vecb;
  out[1] = veca[1] + vecb[1];
  out[2] = veca[2] + vecb[2];
  return;
}


// _VectorCopy  @ 000c5de0
void _VectorCopy(vec_t *in,vec_t *out)

{
  *out = *in;
  out[1] = in[1];
  out[2] = in[2];
  return;
}


// _VectorSubtract  @ 000c5d80
void _VectorSubtract(vec_t *veca,vec_t *vecb,vec_t *out)

{
  *out = *veca - *vecb;
  out[1] = veca[1] - vecb[1];
  out[2] = veca[2] - vecb[2];
  return;
}


// __CreateBaseUISurfaceISurface_interface  @ 001d2b00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * __CreateBaseUISurfaceISurface_interface(void)

{
  return &g_BaseUISurface;
}


// __CreateCBaseUIIBaseUI_interface  @ 001d1790
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * __CreateCBaseUIIBaseUI_interface(void)

{
  return &g_BaseUI;
}


// __CreateCDedicatedServerAPIIDedicatedServerAPI_interface  @ 000e5fd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * __CreateCDedicatedServerAPIIDedicatedServerAPI_interface(void)

{
  return &__g_CDedicatedServerAPI_singleton;
}


// __CreateCEngineAPIIEngineAPI_interface  @ 000e5fc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * __CreateCEngineAPIIEngineAPI_interface(void)

{
  return &__g_CEngineAPI_singleton;
}


// __CreateCEngineVGuiIEngineVGui_interface  @ 001d18b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * __CreateCEngineVGuiIEngineVGui_interface(void)

{
  return &__g_CEngineVGui_singleton;
}


// __CreateCGameUIFuncsIGameUIFuncs_interface  @ 000e5fe0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * __CreateCGameUIFuncsIGameUIFuncs_interface(void)

{
  return &__g_CGameUIFuncs_singleton;
}


// __CreateCServerRemoteAccessIGameServerData_interface  @ 00120780
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * __CreateCServerRemoteAccessIGameServerData_interface(void)

{
  return &g_ServerRemoteAccess;
}


// __CreateEngineSurfaceIEngineSurface_interface  @ 001bca50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * __CreateEngineSurfaceIEngineSurface_interface(void)

{
  return &__g_EngineSurface_singleton;
}


// __divdi3  @ 00255110
undefined8 __divdi3(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  byte bVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  local_24 = 0;
  if ((int)param_2 < 0) {
    bVar10 = param_1 != 0;
    param_1 = -param_1;
    local_24 = 0xffffffff;
    param_2 = -(param_2 + bVar10);
  }
  local_2c = param_3;
  local_28 = param_4;
  if ((int)param_4 < 0) {
    local_2c = -param_3;
    local_24 = ~local_24;
    local_28 = -(param_4 + (param_3 != 0));
  }
  if (local_28 == 0) {
    if (param_2 < local_2c) {
      iVar6 = (int)(CONCAT44(param_2,param_1) / (ulonglong)local_2c);
      uVar9 = 0;
    }
    else {
      if (local_2c == 0) {
        local_2c = 1 / 0;
      }
      uVar9 = param_2 / local_2c;
      iVar6 = (int)(((ulonglong)param_2 % (ulonglong)local_2c << 0x20 | (ulonglong)param_1) /
                   (ulonglong)local_2c);
    }
  }
  else if (param_2 < local_28) {
    uVar9 = 0;
    iVar6 = 0;
  }
  else {
    uVar9 = 0x1f;
    if (local_28 != 0) {
      for (; local_28 >> uVar9 == 0; uVar9 = uVar9 - 1) {
      }
    }
    if ((uVar9 ^ 0x1f) == 0) {
      uVar9 = 0;
      if ((local_28 < param_2) || (iVar6 = 0, local_2c <= param_1)) {
        iVar6 = 1;
      }
    }
    else {
      bVar5 = (byte)(uVar9 ^ 0x1f);
      bVar7 = 0x20 - bVar5;
      uVar1 = (ulonglong)(local_2c >> (bVar7 & 0x1f) | local_28 << (bVar5 & 0x1f));
      uVar2 = CONCAT44(param_2 >> (bVar7 & 0x1f),
                       param_2 << (bVar5 & 0x1f) | param_1 >> (bVar7 & 0x1f));
      uVar3 = uVar2 / uVar1;
      iVar6 = (int)uVar3;
      uVar9 = (uint)(uVar2 % uVar1);
      lVar4 = (uVar3 & 0xffffffff) * (ulonglong)(local_2c << (bVar5 & 0x1f));
      uVar8 = (uint)((ulonglong)lVar4 >> 0x20);
      if ((uVar9 < uVar8) || ((param_1 << (bVar5 & 0x1f) < (uint)lVar4 && (uVar9 == uVar8)))) {
        iVar6 = iVar6 + -1;
        uVar9 = 0;
      }
      else {
        uVar9 = 0;
      }
    }
  }
  if (local_24 != 0) {
    bVar10 = iVar6 != 0;
    iVar6 = -iVar6;
    uVar9 = -(uVar9 + bVar10);
  }
  return CONCAT44(uVar9,iVar6);
}


// __do_global_dtors_aux  @ 00099f20
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


// __moddi3  @ 00255280
/* WARNING: Removing unreachable block (ram,0x002553ee) */

undefined8 __moddi3(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  uint local_34;
  uint local_30;
  
  iVar6 = 0;
  local_30 = param_2;
  local_34 = param_1;
  if ((int)param_2 < 0) {
    local_34 = -param_1;
    iVar6 = -1;
    local_30 = -(param_2 + (param_1 != 0));
  }
  if ((int)param_4 < 0) {
    bVar8 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(param_4 + bVar8);
  }
  if (param_4 == 0) {
    if (local_30 < param_3) {
      local_34 = (uint)(CONCAT44(local_30,local_34) % (ulonglong)param_3);
    }
    else {
      if (param_3 == 0) {
        param_3 = 1 / 0;
      }
      local_34 = (uint)(((ulonglong)local_30 % (ulonglong)param_3 << 0x20 | (ulonglong)local_34) %
                       (ulonglong)param_3);
    }
    local_30 = 0;
  }
  else if (param_4 <= local_30) {
    uVar3 = 0x1f;
    if (param_4 != 0) {
      for (; param_4 >> uVar3 == 0; uVar3 = uVar3 - 1) {
      }
    }
    if ((uVar3 ^ 0x1f) == 0) {
      if ((param_4 < local_30) || (param_3 <= local_34)) {
        bVar8 = local_34 < param_3;
        local_34 = local_34 - param_3;
        local_30 = (local_30 - param_4) - (uint)bVar8;
      }
    }
    else {
      bVar2 = (byte)(uVar3 ^ 0x1f);
      bVar4 = 0x20 - bVar2;
      uVar7 = param_4 << (bVar2 & 0x1f) | param_3 >> (bVar4 & 0x1f);
      param_3 = param_3 << (bVar2 & 0x1f);
      uVar3 = local_34 << (bVar2 & 0x1f);
      uVar1 = CONCAT44(local_30 >> (bVar4 & 0x1f),
                       local_30 << (bVar2 & 0x1f) | local_34 >> (bVar4 & 0x1f));
      iVar5 = (int)(uVar1 % (ulonglong)uVar7);
                    /* catch() { ... } // from try @ 00255448 with catch @ 002553e0 */
      uVar1 = (uVar1 / uVar7 & 0xffffffff) * (ulonglong)param_3;
      if (CONCAT44(iVar5,uVar3) < uVar1) {
        uVar1 = uVar1 - CONCAT44(uVar7,param_3);
      }
      local_30 = (iVar5 - (int)(uVar1 >> 0x20)) - (uint)(uVar3 < (uint)uVar1);
                    /* try { // try from 00255417 to 0026541b has its CatchHandler @ 00255437 */
      local_34 = local_30 << (bVar4 & 0x1f) | uVar3 - (uint)uVar1 >> (bVar2 & 0x1f);
      local_30 = local_30 >> (bVar2 & 0x1f);
    }
  }
  if (iVar6 != 0) {
    bVar8 = local_34 != 0;
    local_34 = -local_34;
    local_30 = -(local_30 + bVar8);
  }
  return CONCAT44(local_30,local_34);
}


// __x86.get_pc_thunk.bx  @ 00099fb0
/* WARNING: This is an inlined function */

void __x86_get_pc_thunk_bx(void)

{
  return;
}


// __x86.get_pc_thunk.dx  @ 00099fac
/* WARNING: This is an inlined function */

void __x86_get_pc_thunk_dx(void)

{
  return;
}


// _fini  @ 00255440
void _fini(void)

{
  return;
}


// _init  @ 00098d68
int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = __gmon_start__();
  return iVar1;
}


