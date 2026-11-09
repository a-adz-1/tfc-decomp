// Ghidra decompilation of functions from cl_dll/cdll_int.cpp
// 24 functions, ordered by original source line

// HUD_GetHullBounds  @ 0006ab80  (line 82)

int HUD_GetHullBounds(int hullnumber,float *mins,float *maxs)

{
                    /* Unresolved local var: int iret@[???] */
  return (uint)((uint)hullnumber < 3);
}


// HUD_ConnectionlessPacket  @ 0006ab90  (line 116)

int HUD_ConnectionlessPacket
              (netadr_s *net_from,char *args,char *response_buffer,int *response_buffer_size)

{
                    /* Unresolved local var: int max_buffer_size@[???] */
  *response_buffer_size = 0;
  return 0;
}


// HUD_PlayerMoveInit  @ 0006abb0  (line 127)

void HUD_PlayerMoveInit(playermove_s *ppmove)

{
  pmove = ppmove;
  PM_CreateStuckTable();
  PM_InitTextureTypes();
  return;
}


// HUD_PlayerMoveTexture  @ 0006abc0  (line 134)

char HUD_PlayerMoveTexture(char *name)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = gcTextures + -1;
  if (-1 < iVar3) {
    iVar4 = 0;
    do {
      while( true ) {
        iVar2 = (iVar3 + iVar4) / 2;
        iVar1 = strncasecmp(name,grgszTextureName[iVar2],0xc);
        if (iVar1 == 0) {
          return grgchTextureType[iVar2];
        }
        if (0 < iVar1) break;
        iVar3 = iVar2 + -1;
        if (iVar3 < iVar4) {
          return 'C';
        }
      }
      iVar4 = iVar2 + 1;
    } while (iVar4 <= iVar3);
  }
  return 'C';
}


// HUD_PlayerMove  @ 0006abd0  (line 141)

void HUD_PlayerMove(playermove_s *ppmove,int server)

{
  playermove_t *ppVar1;
  uint uVar2;
  
  pmove = ppmove;
  PM_PlayerMove((uint)(server != 0));
  ppVar1 = pmove;
  if (pmove->onground == -1) {
    uVar2 = pmove->flags & 0xfffffdff;
  }
  else {
    uVar2 = pmove->flags | 0x200;
  }
  pmove->flags = uVar2;
  if ((ppVar1->multiplayer == false) && (ppVar1->movetype == 3)) {
    ppVar1->friction = 1.0;
    return;
  }
  return;
}


// Initialize  @ 0006ae30  (line 145)

int Initialize(cl_enginefunc_t *pEnginefuncs,int iVersion)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  do {
    uVar3 = uVar2;
    uVar1 = *(undefined4 *)((int)&pEnginefuncs->pfnSPR_Load + uVar3);
    *(undefined4 *)((int)&gEngfuncs.pfnSPR_Frames + uVar3) =
         *(undefined4 *)((int)&pEnginefuncs->pfnSPR_Frames + uVar3);
    *(undefined4 *)((int)&gEngfuncs.pfnSPR_Load + uVar3) = uVar1;
    uVar2 = uVar3 + 8;
  } while (uVar3 + 8 < 0x218);
  *(undefined4 *)((int)&gEngfuncs.pfnSPR_Height + uVar3) =
       *(undefined4 *)((int)&pEnginefuncs->pfnSPR_Height + uVar3);
  uVar2 = 0;
  if (iVersion == 7) {
    do {
      uVar3 = uVar2;
      uVar1 = *(undefined4 *)((int)&pEnginefuncs->pfnSPR_Load + uVar3);
      *(undefined4 *)((int)&gEngfuncs.pfnSPR_Frames + uVar3) =
           *(undefined4 *)((int)&pEnginefuncs->pfnSPR_Frames + uVar3);
      *(undefined4 *)((int)&gEngfuncs.pfnSPR_Load + uVar3) = uVar1;
      uVar2 = uVar3 + 8;
    } while (uVar3 + 8 < 0x218);
    *(undefined4 *)((int)&gEngfuncs.pfnSPR_Height + uVar3) =
         *(undefined4 *)((int)&pEnginefuncs->pfnSPR_Height + uVar3);
    EV_HookEvents();
    CL_LoadParticleMan();
    uVar2 = 1;
  }
  return uVar2;
}


// HUD_VidInit  @ 0006ac00  (line 194)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int HUD_VidInit(void)

{
  CHud::VidInit(&gHUD);
  VGui_Startup();
  return 1;
}


// HUD_Init  @ 0006ac20  (line 214)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HUD_Init(void)

{
  InitInput();
  CHud::Init(&gHUD);
  Scheme_Init();
  return;
}


// HUD_Redraw  @ 0006ac40  (line 232)

int HUD_Redraw(float time,int intermission)

{
  CHud::Redraw(&gHUD,time,intermission);
  return 1;
}


// HUD_UpdateClientData  @ 0006ac70  (line 255)

int HUD_UpdateClientData(client_data_t *pcldata,float flTime)

{
  int iVar1;
  
  IN_Commands();
  iVar1 = CHud::UpdateClientData(&gHUD,pcldata,flTime);
  return iVar1;
}


// HUD_Reset  @ 0006abe0  (line 272)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HUD_Reset(void)

{
  CHud::VidInit(&gHUD);
  return;
}


// HUD_Frame  @ 0006aca0  (line 287)

void HUD_Frame(double time)

{
  CVoiceStatus *this;
  
  ServersThink(time);
  this = GetClientVoiceMgr();
  CVoiceStatus::Frame(this,time);
  return;
}


// HUD_VoiceStatus  @ 0006ace0  (line 305)

void HUD_VoiceStatus(int entindex,qboolean bTalking)

{
  CVoiceStatus *this;
  
  this = GetClientVoiceMgr();
  CVoiceStatus::UpdateSpeakerStatus(this,entindex,bTalking);
  return;
}


// HUD_DirectorMessage  @ 0006ad10  (line 320)

void HUD_DirectorMessage(int iSize,void *pbuf)

{
  CHudSpectator::DirectorMessage(&gHUD.m_Spectator,iSize,pbuf);
  return;
}


// CL_UnloadParticleMan  @ 0006ad40  (line 327)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_UnloadParticleMan(void)

{
  Sys_UnloadModule(g_hParticleManModule);
  g_pParticleMan = (IParticleMan *)0x0;
  g_hParticleManModule = (CSysModule *)0x0;
  return;
}


// CL_LoadParticleMan  @ 0006ad70  (line 335)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CL_LoadParticleMan(void)

{
  int iVar1;
  CreateInterfaceFn p_Var2;
  int in_GS_OFFSET;
  char local_210 [512];
  int local_10;
  
                    /* Unresolved local var: char[512] szPDir@[???]
                       Unresolved local var: CreateInterfaceFn particleManFactory@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = (*gEngfuncs.COM_ExpandFilename)("cl_dlls/particleman.so",local_210,0x200);
  if (iVar1 != 0) {
    g_hParticleManModule = Sys_LoadModule(local_210);
    p_Var2 = Sys_GetFactory(g_hParticleManModule);
    if (p_Var2 != (CreateInterfaceFn)0x0) {
      g_pParticleMan = (*p_Var2)("create_particleman",(int *)0x0);
      if (g_pParticleMan != (IParticleMan *)0x0) {
        (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[2])(g_pParticleMan,&gEngfuncs)
        ;
        (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[7])(g_pParticleMan,0x114);
      }
      goto LAB_0006adb8;
    }
  }
  g_pParticleMan = (IParticleMan *)0x0;
  g_hParticleManModule = (CSysModule *)0x0;
LAB_0006adb8:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// F  @ 0006aeb0  (line 369)

void F(void *pv)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  code *local_b0 [43];
  
                    /* Unresolved local var: cldll_func_t * pcldll_func@[DW_OP_reg2(EDX)]
                       Unresolved local var: cldll_func_t cldll_func@[???] */
  g_pcldstAddrs = *(cldll_func_dst_t **)((int)pv + 8);
  uVar3 = 0;
  do {
    uVar2 = uVar3;
    *(undefined4 *)((int)local_b0 + uVar2) = 0;
    *(undefined4 *)((int)local_b0 + uVar2 + 4) = 0;
    uVar3 = uVar2 + 8;
  } while (uVar2 + 8 < 0xa8);
  *(undefined4 *)((int)local_b0 + uVar2 + 8) = 0;
  local_b0[1] = HUD_Init;
  local_b0[2] = HUD_VidInit;
  local_b0[3] = HUD_Redraw;
  local_b0[4] = HUD_UpdateClientData;
  local_b0[5] = HUD_Reset;
  local_b0[6] = HUD_PlayerMove;
  local_b0[9] = IN_ActivateMouse;
  local_b0[10] = IN_DeactivateMouse;
  local_b0[0xb] = IN_MouseEvent;
  local_b0[0xc] = IN_ClearStates;
  local_b0[0xd] = IN_Accumulate;
  local_b0[0xe] = CL_CreateMove;
  local_b0[0x11] = KB_Find;
  local_b0[0x12] = CAM_Think;
  local_b0[0x13] = V_CalcRefdef;
  local_b0[0x14] = HUD_AddEntity;
  local_b0[0x15] = HUD_CreateEntities;
  local_b0[0x16] = HUD_DrawNormalTriangles;
  local_b0[0x19] = HUD_PostRunCmd;
  local_b0[0x1a] = HUD_Shutdown;
  local_b0[0x1b] = HUD_TxferLocalOverrides;
  local_b0[0] = Initialize;
  local_b0[7] = HUD_PlayerMoveInit;
  local_b0[0x1c] = HUD_ProcessPlayerState;
  local_b0[8] = HUD_PlayerMoveTexture;
  local_b0[0xf] = CL_IsThirdPerson;
  local_b0[0x1d] = HUD_TxferPredictionData;
  local_b0[0x10] = CL_CameraOffset;
  local_b0[0x17] = HUD_DrawTransparentTriangles;
  local_b0[0x1e] = Demo_ReadBuffer;
  local_b0[0x18] = HUD_StudioEvent;
  local_b0[0x1f] = HUD_ConnectionlessPacket;
  local_b0[0x21] = HUD_Frame;
  local_b0[0x22] = HUD_Key_Event;
  local_b0[0x23] = HUD_TempEntUpdate;
  local_b0[0x24] = HUD_GetUserEntity;
  local_b0[0x20] = HUD_GetHullBounds;
  local_b0[0x25] = HUD_VoiceStatus;
  local_b0[0x26] = HUD_DirectorMessage;
  local_b0[0x27] = HUD_GetStudioModelInterface;
  local_b0[0x28] = HUD_ChatInputPosition;
  uVar3 = 0;
  do {
    uVar2 = uVar3;
    uVar1 = *(undefined4 *)((int)local_b0 + uVar2);
    *(undefined4 *)((int)pv + uVar2 + 4) = *(undefined4 *)((int)local_b0 + uVar2 + 4);
    *(undefined4 *)((int)pv + uVar2) = uVar1;
    uVar3 = uVar2 + 8;
  } while (uVar3 < 0xa8);
  *(undefined4 *)((int)pv + uVar3) = *(undefined4 *)((int)local_b0 + uVar2 + 8);
  return;
}


// CClientExports::~CClientExports  @ 0006b0c0  (line 428)

/* DWARF original prototype: void ~CClientExports(CClientExports * this, int __in_chrg) */

void __thiscall CClientExports::~CClientExports(CClientExports *this,int __in_chrg)

{
  return;
}


// CClientExports::~CClientExports  @ 0006b180  (line 428)

/* DWARF original prototype: void ~CClientExports(CClientExports * this, int __in_chrg) */

void __thiscall CClientExports::~CClientExports(CClientExports *this,int __in_chrg)

{
  operator_delete(this);
  return;
}


// CClientExports::GetServerHostName  @ 0006b0b0  (line 439)

/* DWARF original prototype: char * GetServerHostName(CClientExports * this) */

char * __thiscall CClientExports::GetServerHostName(CClientExports *this)

{
  return "";
}


// CClientExports::IsPlayerGameVoiceMuted  @ 0006b130  (line 442)

/* DWARF original prototype: bool IsPlayerGameVoiceMuted(CClientExports * this, int playerIndex) */

bool __thiscall CClientExports::IsPlayerGameVoiceMuted(CClientExports *this,int playerIndex)

{
  bool bVar1;
  CVoiceStatus *pCVar2;
  
  pCVar2 = GetClientVoiceMgr();
  if (pCVar2 != (CVoiceStatus *)0x0) {
    pCVar2 = GetClientVoiceMgr();
    bVar1 = CVoiceStatus::IsPlayerBlocked(pCVar2,playerIndex);
    return bVar1;
  }
  return false;
}


// CClientExports::MutePlayerGameVoice  @ 0006b100  (line 449)

/* DWARF original prototype: void MutePlayerGameVoice(CClientExports * this, int playerIndex) */

void __thiscall CClientExports::MutePlayerGameVoice(CClientExports *this,int playerIndex)

{
  CVoiceStatus *pCVar1;
  
  pCVar1 = GetClientVoiceMgr();
  if (pCVar1 != (CVoiceStatus *)0x0) {
    pCVar1 = GetClientVoiceMgr();
    CVoiceStatus::SetPlayerBlockedState(pCVar1,playerIndex,true);
  }
  return;
}


// CClientExports::UnmutePlayerGameVoice  @ 0006b0d0  (line 457)

/* DWARF original prototype: void UnmutePlayerGameVoice(CClientExports * this, int playerIndex) */

void __thiscall CClientExports::UnmutePlayerGameVoice(CClientExports *this,int playerIndex)

{
  CVoiceStatus *pCVar1;
  
  pCVar1 = GetClientVoiceMgr();
  if (pCVar1 != (CVoiceStatus *)0x0) {
    pCVar1 = GetClientVoiceMgr();
    CVoiceStatus::SetPlayerBlockedState(pCVar1,playerIndex,false);
  }
  return;
}


// __CreateCClientExportsIGameClientExports_interface  @ 0006aba0  (line 466)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * __CreateCClientExportsIGameClientExports_interface(void)

{
  return &__g_CClientExports_singleton;
}


