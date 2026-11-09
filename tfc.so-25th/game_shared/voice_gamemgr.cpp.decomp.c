// Ghidra decompilation of functions from game_shared/voice_gamemgr.cpp
// 11 functions, ordered by original source line

// VoiceServerDebug  @ 001464d0  (line 69)

void VoiceServerDebug(char *pFmt,...)

{
  int in_GS_OFFSET;
  undefined1 local_1010 [4096];
  int local_10;
  
                    /* Unresolved local var: char[4096] msg@[???]
                       Unresolved local var: va_list marker@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (voice_serverdebug.value != 0.0) {
    __vsnprintf_chk(local_1010,0x1000,1,0x1000,pFmt,&stack0x00000008);
    (*g_engfuncs.pfnAlertMessage)(at_console,"%s",local_1010);
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CVoiceGameMgr::CVoiceGameMgr  @ 00146580  (line 89)

/* DWARF original prototype: void CVoiceGameMgr(CVoiceGameMgr * this) */

void __thiscall CVoiceGameMgr::CVoiceGameMgr(CVoiceGameMgr *this)

{
  this->_vptr_CVoiceGameMgr = (_func_int_varargs **)&PTR__CVoiceGameMgr_0016b7d4;
  this->m_UpdateInterval = 0.0;
  this->m_nMaxPlayers = 0;
  return;
}


// CVoiceGameMgr::~CVoiceGameMgr  @ 001464b0  (line 96)

/* DWARF original prototype: void ~CVoiceGameMgr(CVoiceGameMgr * this, int __in_chrg) */

void __thiscall CVoiceGameMgr::~CVoiceGameMgr(CVoiceGameMgr *this,int __in_chrg)

{
  return;
}


// CVoiceGameMgr::~CVoiceGameMgr  @ 001464c0  (line 98)

/* DWARF original prototype: void ~CVoiceGameMgr(CVoiceGameMgr * this, int __in_chrg) */

void __thiscall CVoiceGameMgr::~CVoiceGameMgr(CVoiceGameMgr *this,int __in_chrg)

{
  operator_delete(this);
  return;
}


// CVoiceGameMgr::Init  @ 001465a0  (line 104)

/* DWARF original prototype: bool Init(CVoiceGameMgr * this, IVoiceGameMgrHelper * pHelper, int
   maxClients) */

bool __thiscall CVoiceGameMgr::Init(CVoiceGameMgr *this,IVoiceGameMgrHelper *pHelper,int maxClients)

{
  int iVar1;
  cvar_t *pcVar2;
  
  this->m_pHelper = pHelper;
  if (0x20 < maxClients) {
    maxClients = 0x20;
  }
  this->m_nMaxPlayers = maxClients;
  (*g_engfuncs.pfnPrecacheModel)("sprites/voiceicon.spr");
  iVar1 = (*g_engfuncs.pfnRegUserMsg)("VoiceMask",8);
  this->m_msgPlayerVoiceMask = iVar1;
  iVar1 = (*g_engfuncs.pfnRegUserMsg)("ReqState",0);
  this->m_msgRequestState = iVar1;
  pcVar2 = (*g_engfuncs.pfnCVarGetPointer)("voice_serverdebug");
  if (pcVar2 == (cvar_t *)0x0) {
    (*g_engfuncs.pfnCVarRegister)(&voice_serverdebug);
  }
  pcVar2 = (*g_engfuncs.pfnCVarGetPointer)("sv_alltalk");
  if (pcVar2 != (cvar_t *)0x0) {
    return true;
  }
  (*g_engfuncs.pfnCVarRegister)(&sv_alltalk);
  return true;
}


// CVoiceGameMgr::SetHelper  @ 00146660  (line 125)

/* DWARF original prototype: void SetHelper(CVoiceGameMgr * this, IVoiceGameMgrHelper * pHelper) */

void __thiscall CVoiceGameMgr::SetHelper(CVoiceGameMgr *this,IVoiceGameMgrHelper *pHelper)

{
  this->m_pHelper = pHelper;
  return;
}


// CVoiceGameMgr::Update  @ 00146c40  (line 130)

/* DWARF original prototype: void Update(CVoiceGameMgr * this, double frametime) */

void __thiscall CVoiceGameMgr::Update(CVoiceGameMgr *this,double frametime)

{
  double dVar1;
  
  dVar1 = frametime + this->m_UpdateInterval;
  this->m_UpdateInterval = dVar1;
  if (dVar1 < 0.3) {
    return;
  }
  UpdateMasks(this);
  return;
}


// CVoiceGameMgr::ClientConnected  @ 00146670  (line 141)

/* DWARF original prototype: void ClientConnected(CVoiceGameMgr * this, edict_t * pEdict) */

void __thiscall CVoiceGameMgr::ClientConnected(CVoiceGameMgr *this,edict_t *pEdict)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  uint32 uVar5;
  uint uVar6;
  
                    /* Unresolved local var: int index@[???] */
  iVar2 = (*g_engfuncs.pfnIndexOfEdict)(pEdict);
  iVar1 = iVar2 + -1;
                    /* Unresolved local var: int i@[???] */
  iVar4 = 0;
  (&g_bWantModEnable)[iVar1 >> 5].m_DWords[0] =
       (&g_bWantModEnable)[iVar1 >> 5].m_DWords[0] | 1 << ((byte)iVar1 & 0x1f);
  uVar5 = g_SentBanMasks[iVar2 + 0x1f].m_DWords[0];
  do {
    bVar3 = (byte)iVar4;
    iVar4 = iVar4 + 1;
    uVar5 = uVar5 & ~(1 << (bVar3 & 0x1f));
    g_SentGameRulesMasks[iVar1].m_DWords[0] = uVar5;
  } while (iVar4 != 0x20);
  uVar6 = *(uint *)(&DAT_001a7fdc + iVar2 * 4);
  iVar2 = 0;
                    /* Unresolved local var: int i@[???] */
  do {
    bVar3 = (byte)iVar2;
    iVar2 = iVar2 + 1;
    uVar6 = uVar6 & ~(1 << (bVar3 & 0x1f));
    g_SentBanMasks[iVar1].m_DWords[0] = uVar6;
  } while (iVar2 != 0x20);
  return;
}


// CVoiceGameMgr::PlayerHasBlockedPlayer  @ 00146710  (line 153)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: bool PlayerHasBlockedPlayer(CVoiceGameMgr * this, CBasePlayer *
   pReceiver, CBasePlayer * pSender) */

bool __thiscall
CVoiceGameMgr::PlayerHasBlockedPlayer
          (CVoiceGameMgr *this,CBasePlayer *pReceiver,CBasePlayer *pSender)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int iReceiverIndex@[???]
                       Unresolved local var: int iSenderIndex@[???] */
  if ((pReceiver != (CBasePlayer *)0x0) && (pSender != (CBasePlayer *)0x0)) {
    iVar1 = (*g_engfuncs.pfnIndexOfEdict)
                      (((pReceiver->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar1 = iVar1 + -1;
    iVar2 = (*g_engfuncs.pfnIndexOfEdict)
                      (((pSender->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar2 = iVar2 + -1;
    if ((-1 < iVar1) &&
       ((iVar1 < this->m_nMaxPlayers && -1 < iVar2 && (iVar2 < this->m_nMaxPlayers)))) {
      return (g_BanMasks[iVar1 + (iVar2 >> 5)].m_DWords[0] & 1 << ((byte)iVar2 & 0x1f)) != 0;
    }
  }
  return false;
}


// CVoiceGameMgr::ClientCommand  @ 001467a0  (line 169)

/* DWARF original prototype: bool ClientCommand(CVoiceGameMgr * this, CBasePlayer * pPlayer, char *
   cmd) */

bool __thiscall CVoiceGameMgr::ClientCommand(CVoiceGameMgr *this,CBasePlayer *pPlayer,char *cmd)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  CPlayerBitVec local_10;
  
                    /* Unresolved local var: int playerClientIndex@[???]
                       Unresolved local var: bool bBan@[???] */
  iVar1 = (*g_engfuncs.pfnIndexOfEdict)
                    (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  iVar1 = iVar1 + -1;
  if ((iVar1 < 0) || (this->m_nMaxPlayers <= iVar1)) {
    VoiceServerDebug("CVoiceGameMgr::ClientCommand: cmd %s from invalid client (%d)\n",cmd,iVar1);
    return true;
  }
  iVar2 = strcasecmp(cmd,"vban");
  if ((iVar2 == 0) && (iVar2 = (*g_engfuncs.pfnCmd_Argc)(), 1 < iVar2)) {
                    /* Unresolved local var: int i@[???] */
    iVar2 = (*g_engfuncs.pfnCmd_Argc)();
    iVar6 = 1;
                    /* Unresolved local var: uint32 mask@[???] */
    if (1 < iVar2) {
      do {
        local_10.m_DWords[0] = (uint32  [1])0;
        pcVar3 = (*g_engfuncs.pfnCmd_Argv)(iVar6);
        sscanf(pcVar3,"%x",&local_10);
        if (iVar6 < 2) {
          VoiceServerDebug("CVoiceGameMgr::ClientCommand: vban (0x%x) from %d\n",
                           local_10.m_DWords[0],iVar1);
          g_SentGameRulesMasks[iVar6 + iVar1 + 0x1f].m_DWords[0] = (uint32)local_10.m_DWords[0];
        }
        else {
          VoiceServerDebug("CVoiceGameMgr::ClientCommand: invalid index (%d)\n",iVar6);
        }
        iVar6 = iVar6 + 1;
        iVar2 = (*g_engfuncs.pfnCmd_Argc)();
      } while (iVar6 < iVar2);
    }
    return true;
  }
  iVar2 = strcasecmp(cmd,"VModEnable");
  if ((iVar2 == 0) && (iVar2 = (*g_engfuncs.pfnCmd_Argc)(), 1 < iVar2)) {
    pcVar3 = (*g_engfuncs.pfnCmd_Argv)(1);
    lVar4 = strtol(pcVar3,(char **)0x0,10);
    VoiceServerDebug("CVoiceGameMgr::ClientCommand: VModEnable (%d)\n",(uint)(lVar4 != 0));
    pcVar3 = (*g_engfuncs.pfnCmd_Argv)(1);
    lVar4 = strtol(pcVar3,(char **)0x0,10);
    iVar2 = iVar1 >> 5;
    if (lVar4 == 0) {
      uVar5 = ~(1 << ((byte)iVar1 & 0x1f));
      (&g_PlayerModEnable)[iVar2].m_DWords[0] = (&g_PlayerModEnable)[iVar2].m_DWords[0] & uVar5;
    }
    else {
      uVar5 = 1 << ((byte)iVar1 & 0x1f);
      (&g_PlayerModEnable)[iVar2].m_DWords[0] = (&g_PlayerModEnable)[iVar2].m_DWords[0] | uVar5;
      uVar5 = ~uVar5;
    }
    (&g_bWantModEnable)[iVar2].m_DWords[0] = (&g_bWantModEnable)[iVar2].m_DWords[0] & uVar5;
    return true;
  }
  return false;
}


// CVoiceGameMgr::UpdateMasks  @ 001469a0  (line 216)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void UpdateMasks(CVoiceGameMgr * this) */

void __thiscall CVoiceGameMgr::UpdateMasks(CVoiceGameMgr *this)

{
  int playerIndex;
  _func_int_varargs *p_Var1;
  float fVar2;
  CBasePlayer *pCVar3;
  uint uVar4;
  CBasePlayer *pCVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  CPlayerBitVec CVar11;
  CPlayerBitVec *local_38;
  CPlayerBitVec local_20 [4];
  
                    /* Unresolved local var: bool bAllTalk@[???] */
  fVar2 = sv_alltalk.value;
                    /* Unresolved local var: int iClient@[???] */
  local_38 = g_BanMasks;
  iVar9 = this->m_nMaxPlayers;
  *(undefined4 *)&this->m_UpdateInterval = 0;
  *(undefined4 *)((int)&this->m_UpdateInterval + 4) = 0;
  if (0 < iVar9) {
    iVar9 = 0;
    do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[???]
                       Unresolved local var: CPlayerBitVec gameRulesMask@[???] */
      playerIndex = iVar9 + 1;
      pCVar3 = UTIL_PlayerByIndex(playerIndex);
      if ((pCVar3 == (CBasePlayer *)0x0) ||
         ((p_Var1 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x27],
          p_Var1 != CBasePlayer::IsPlayer && (iVar8 = (*p_Var1)(pCVar3), iVar8 == 0)))) {
        iVar8 = this->m_nMaxPlayers;
      }
      else {
        uVar4 = 1 << ((byte)iVar9 & 0x1f);
        if (((&g_bWantModEnable)[iVar9 >> 5].m_DWords[0] & uVar4) != 0) {
          (*g_engfuncs.pfnMessageBegin)
                    (1,this->m_msgRequestState,(float *)0x0,
                     ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          (*g_engfuncs.pfnMessageEnd)();
        }
                    /* Unresolved local var: int i@[???] */
        local_20[0].m_DWords[0] = (uint32  [1])0;
        if ((uVar4 & (&g_PlayerModEnable)[iVar9 >> 5].m_DWords[0]) != 0) {
          if (fVar2 == 0.0) {
            iVar8 = 0;
            while (iVar10 = iVar8, iVar10 < this->m_nMaxPlayers) {
              iVar8 = iVar10 + 1;
              pCVar5 = UTIL_PlayerByIndex(iVar8);
              if ((pCVar5 != (CBasePlayer *)0x0) &&
                 (iVar7 = (*this->m_pHelper->_vptr_IVoiceGameMgrHelper[2])
                                    (this->m_pHelper,pCVar3,pCVar5), (char)iVar7 != '\0')) {
                local_20[iVar10 >> 5].m_DWords[0] =
                     local_20[iVar10 >> 5].m_DWords[0] | 1 << ((byte)iVar10 & 0x1f);
              }
            }
          }
          else {
                    /* Unresolved local var: int iOtherClient@[???] */
            if (0 < this->m_nMaxPlayers) {
              iVar8 = 0;
              do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
                iVar10 = iVar8 + 1;
                pCVar5 = UTIL_PlayerByIndex(iVar10);
                if (pCVar5 != (CBasePlayer *)0x0) {
                  local_20[iVar8 >> 5].m_DWords[0] =
                       local_20[iVar8 >> 5].m_DWords[0] | 1 << ((byte)iVar8 & 0x1f);
                }
                iVar8 = iVar10;
              } while (iVar10 < this->m_nMaxPlayers);
            }
          }
        }
        CVar11.m_DWords[0] = local_20[0].m_DWords[0];
                    /* Unresolved local var: int i@[???] */
        if ((local_20[0].m_DWords[0] != (uint32  [1])g_SentBanMasks[iVar9 + 0x20].m_DWords[0]) ||
           (local_38->m_DWords[0] != *(uint32 *)(&DAT_001a7fdc + playerIndex * 4))) {
                    /* Unresolved local var: int dw@[???] */
          g_SentBanMasks[iVar9 + 0x20].m_DWords[0] = (uint32)local_20[0].m_DWords[0];
          *(uint32 *)(&DAT_001a7fdc + playerIndex * 4) = local_38->m_DWords[0];
          (*g_engfuncs.pfnMessageBegin)
                    (1,this->m_msgPlayerVoiceMask,(float *)0x0,
                     ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          (*g_engfuncs.pfnWriteLong)((int)CVar11.m_DWords[0]);
          (*g_engfuncs.pfnWriteLong)(local_38->m_DWords[0]);
          (*g_engfuncs.pfnMessageEnd)();
        }
                    /* Unresolved local var: int iOtherClient@[???] */
        iVar8 = this->m_nMaxPlayers;
        if (0 < iVar8) {
          iVar9 = 0;
          while( true ) {
                    /* Unresolved local var: bool bCanHear@[???] */
            uVar4 = 1 << ((byte)iVar9 & 0x1f);
            uVar6 = 0;
            if (((uint)CVar11.m_DWords[0] & uVar4) != 0) {
              uVar6 = (uint)((local_38[iVar9 >> 5].m_DWords[0] & uVar4) == 0);
            }
            iVar9 = iVar9 + 1;
            (*g_engfuncs.pfnVoice_SetClientListening)(playerIndex,iVar9,uVar6);
            iVar8 = this->m_nMaxPlayers;
            if (iVar8 <= iVar9) break;
            CVar11.m_DWords[0] = (uint32  [1])local_20[iVar9 >> 5].m_DWords[0];
          }
        }
      }
      local_38 = local_38 + 1;
      iVar9 = playerIndex;
    } while (playerIndex < iVar8);
  }
  return;
}


