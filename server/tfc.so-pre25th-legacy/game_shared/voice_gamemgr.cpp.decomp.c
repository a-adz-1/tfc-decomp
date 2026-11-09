// Ghidra decompilation of functions from game_shared/voice_gamemgr.cpp
// 11 functions, ordered by original source line

// VoiceServerDebug  @ 00176f10  (line 69)

void VoiceServerDebug(char *pFmt,...)

{
  char local_100c [4104];
  
                    /* Unresolved local var: char[4096] msg@[???]
                       Unresolved local var: va_list marker@[???] */
  if (voice_serverdebug.value != 0.0) {
    vsnprintf(local_100c,0x1000,pFmt,&stack0x00000008);
    (*g_engfuncs.pfnAlertMessage)(at_console,"%s",local_100c);
  }
  return;
}


// CVoiceGameMgr::CVoiceGameMgr  @ 00176f90  (line 89)

/* DWARF original prototype: void CVoiceGameMgr(CVoiceGameMgr * this) */

void __thiscall CVoiceGameMgr::CVoiceGameMgr(CVoiceGameMgr *this)

{
  this->_vptr_CVoiceGameMgr = (_func_int_varargs **)&PTR__CVoiceGameMgr_0019ced8;
  this->m_UpdateInterval = 0.0;
  this->m_nMaxPlayers = 0;
  return;
}


// CVoiceGameMgr::~CVoiceGameMgr  @ 00176f00  (line 96)

/* DWARF original prototype: void ~CVoiceGameMgr(CVoiceGameMgr * this, int __in_chrg) */

void __thiscall CVoiceGameMgr::~CVoiceGameMgr(CVoiceGameMgr *this,int __in_chrg)

{
  this->_vptr_CVoiceGameMgr = (_func_int_varargs **)&PTR__CVoiceGameMgr_0019ced8;
  return;
}


// CVoiceGameMgr::~CVoiceGameMgr  @ 00176f80  (line 96)

/* DWARF original prototype: void ~CVoiceGameMgr(CVoiceGameMgr * this, int __in_chrg) */

void __thiscall CVoiceGameMgr::~CVoiceGameMgr(CVoiceGameMgr *this,int __in_chrg)

{
  this->_vptr_CVoiceGameMgr = (_func_int_varargs **)&PTR__CVoiceGameMgr_0019ced8;
  operator_delete(this);
  return;
}


// CVoiceGameMgr::Init  @ 00176fb0  (line 104)

/* DWARF original prototype: bool Init(CVoiceGameMgr * this, IVoiceGameMgrHelper * pHelper, int
   maxClients) */

bool __thiscall CVoiceGameMgr::Init(CVoiceGameMgr *this,IVoiceGameMgrHelper *pHelper,int maxClients)

{
  int iVar1;
  cvar_t *pcVar2;
  
  this->m_pHelper = pHelper;
  iVar1 = 0x20;
  if (maxClients < 0x21) {
    iVar1 = maxClients;
  }
  this->m_nMaxPlayers = iVar1;
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


// CVoiceGameMgr::SetHelper  @ 00177070  (line 125)

/* DWARF original prototype: void SetHelper(CVoiceGameMgr * this, IVoiceGameMgrHelper * pHelper) */

void __thiscall CVoiceGameMgr::SetHelper(CVoiceGameMgr *this,IVoiceGameMgrHelper *pHelper)

{
  this->m_pHelper = pHelper;
  return;
}


// CVoiceGameMgr::Update  @ 00177660  (line 130)

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


// CVoiceGameMgr::ClientConnected  @ 00177080  (line 141)

/* DWARF original prototype: void ClientConnected(CVoiceGameMgr * this, edict_t * pEdict) */

void __thiscall CVoiceGameMgr::ClientConnected(CVoiceGameMgr *this,edict_t *pEdict)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  
                    /* Unresolved local var: int index@[???] */
  iVar1 = (*g_engfuncs.pfnIndexOfEdict)(pEdict);
  iVar1 = iVar1 + -1;
  iVar4 = 0;
  (&g_bWantModEnable)[iVar1 >> 5].m_DWords[0] =
       (&g_bWantModEnable)[iVar1 >> 5].m_DWords[0] | 1 << ((byte)iVar1 & 0x1f);
                    /* Unresolved local var: int i@[???] */
  uVar5 = g_SentGameRulesMasks[iVar1].m_DWords[0];
  do {
    bVar3 = (byte)iVar4;
    iVar4 = iVar4 + 1;
    uVar5 = uVar5 & ~(1 << (bVar3 & 0x1f));
  } while (iVar4 != 0x20);
  iVar4 = 0;
  uVar2 = g_SentBanMasks[iVar1].m_DWords[0];
  g_SentGameRulesMasks[iVar1].m_DWords[0] = uVar5;
                    /* Unresolved local var: int i@[???] */
  do {
    bVar3 = (byte)iVar4;
    iVar4 = iVar4 + 1;
    uVar2 = uVar2 & ~(1 << (bVar3 & 0x1f));
  } while (iVar4 != 0x20);
  g_SentBanMasks[iVar1].m_DWords[0] = uVar2;
  return;
}


// CVoiceGameMgr::PlayerHasBlockedPlayer  @ 00177110  (line 153)

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
  if ((pSender != (CBasePlayer *)0x0) && (pReceiver != (CBasePlayer *)0x0)) {
    iVar1 = (*g_engfuncs.pfnIndexOfEdict)
                      (((pReceiver->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar1 = iVar1 + -1;
    iVar2 = (*g_engfuncs.pfnIndexOfEdict)
                      (((pSender->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    if (-1 < iVar1) {
      iVar2 = iVar2 + -1;
      if (((-1 < iVar2) && (iVar1 < this->m_nMaxPlayers)) && (iVar2 < this->m_nMaxPlayers)) {
        return (g_BanMasks[(iVar2 >> 5) + iVar1].m_DWords[0] & 1 << ((byte)iVar2 & 0x1f)) != 0;
      }
    }
  }
  return false;
}


// CVoiceGameMgr::ClientCommand  @ 001771b0  (line 169)

/* DWARF original prototype: bool ClientCommand(CVoiceGameMgr * this, CBasePlayer * pPlayer, char *
   cmd) */

bool __thiscall CVoiceGameMgr::ClientCommand(CVoiceGameMgr *this,CBasePlayer *pPlayer,char *cmd)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  long lVar5;
  uint uVar6;
  int iVar7;
  undefined4 local_20 [4];
  
                    /* Unresolved local var: int playerClientIndex@[???]
                       Unresolved local var: bool bBan@[???] */
  iVar2 = (*g_engfuncs.pfnIndexOfEdict)
                    (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  iVar2 = iVar2 + -1;
  if ((iVar2 < 0) || (this->m_nMaxPlayers <= iVar2)) {
    VoiceServerDebug("CVoiceGameMgr::ClientCommand: cmd %s from invalid client (%d)\n",cmd,iVar2);
    bVar1 = true;
  }
  else {
    iVar3 = strcasecmp(cmd,"vban");
    if (iVar3 == 0) {
      iVar3 = (*g_engfuncs.pfnCmd_Argc)();
      iVar7 = 1;
      if (1 < iVar3) {
                    /* Unresolved local var: int i@[???] */
        iVar3 = (*g_engfuncs.pfnCmd_Argc)();
                    /* Unresolved local var: uint32 mask@[???] */
        if (1 < iVar3) {
          do {
            local_20[0] = 0;
            pcVar4 = (*g_engfuncs.pfnCmd_Argv)(iVar7);
            sscanf(pcVar4,"%x",local_20);
            if (iVar7 < 2) {
              VoiceServerDebug("CVoiceGameMgr::ClientCommand: vban (0x%x) from %d\n",local_20[0],
                               iVar2);
              *(undefined4 *)(iVar2 * 4 + 0x1da99c + iVar7 * 4) = local_20[0];
            }
            else {
              VoiceServerDebug("CVoiceGameMgr::ClientCommand: invalid index (%d)\n",iVar7);
            }
            iVar7 = iVar7 + 1;
            iVar3 = (*g_engfuncs.pfnCmd_Argc)();
          } while (iVar7 < iVar3);
        }
        return true;
      }
    }
    iVar3 = strcasecmp(cmd,"VModEnable");
    if (iVar3 == 0) {
      iVar3 = (*g_engfuncs.pfnCmd_Argc)();
      bVar1 = false;
      if (1 < iVar3) {
        pcVar4 = (*g_engfuncs.pfnCmd_Argv)(1);
        lVar5 = strtol(pcVar4,(char **)0x0,10);
        VoiceServerDebug("CVoiceGameMgr::ClientCommand: VModEnable (%d)\n",(uint)(lVar5 != 0));
        pcVar4 = (*g_engfuncs.pfnCmd_Argv)(1);
        lVar5 = strtol(pcVar4,(char **)0x0,10);
        iVar3 = iVar2 >> 5;
        if (lVar5 == 0) {
          uVar6 = ~(1 << ((byte)iVar2 & 0x1f));
          (&g_PlayerModEnable)[iVar3].m_DWords[0] = (&g_PlayerModEnable)[iVar3].m_DWords[0] & uVar6;
        }
        else {
          uVar6 = 1 << ((byte)iVar2 & 0x1f);
          (&g_PlayerModEnable)[iVar3].m_DWords[0] = (&g_PlayerModEnable)[iVar3].m_DWords[0] | uVar6;
          uVar6 = ~uVar6;
        }
        (&g_bWantModEnable)[iVar3].m_DWords[0] = (&g_bWantModEnable)[iVar3].m_DWords[0] & uVar6;
        bVar1 = true;
      }
    }
    else {
      bVar1 = false;
    }
  }
  return bVar1;
}


// CVoiceGameMgr::UpdateMasks  @ 001773b0  (line 216)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void UpdateMasks(CVoiceGameMgr * this) */

void __thiscall CVoiceGameMgr::UpdateMasks(CVoiceGameMgr *this)

{
  float fVar1;
  CBasePlayer *pCVar2;
  int iVar3;
  CBasePlayer *pCVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int playerIndex;
  CBitVec<32> CVar9;
  int local_38;
  CBitVec<32> local_2c [7];
  
  fVar1 = sv_alltalk.value;
                    /* Unresolved local var: bool bAllTalk@[???]
                       Unresolved local var: int iClient@[???] */
  local_38 = 0;
  *(undefined4 *)&this->m_UpdateInterval = 0;
  iVar3 = this->m_nMaxPlayers;
  *(undefined4 *)((int)&this->m_UpdateInterval + 4) = 0;
  playerIndex = local_38;
  while (local_38 = playerIndex, local_38 < iVar3) {
    playerIndex = local_38 + 1;
    pCVar2 = UTIL_PlayerByIndex(playerIndex);
    if ((pCVar2 == (CBasePlayer *)0x0) ||
       (iVar3 = (*(pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x27])(pCVar2), iVar3 == 0))
    {
                    /* Unresolved local var: CBaseEntity * pEnt@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[???]
                       Unresolved local var: CPlayerBitVec gameRulesMask@[???] */
      iVar3 = this->m_nMaxPlayers;
    }
    else {
      uVar7 = 1 << ((byte)local_38 & 0x1f);
      if (((&g_bWantModEnable)[local_38 >> 5].m_DWords[0] & uVar7) != 0) {
        (*g_engfuncs.pfnMessageBegin)
                  (1,this->m_msgRequestState,(float *)0x0,
                   ((pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        (*g_engfuncs.pfnMessageEnd)();
      }
                    /* Unresolved local var: int i@[???] */
      local_2c[0].m_DWords[0] = (uint  [1])0;
      if (((&g_PlayerModEnable)[local_38 >> 5].m_DWords[0] & uVar7) != 0) {
        iVar3 = 0;
        if (fVar1 == 0.0) {
          if (0 < this->m_nMaxPlayers) {
            do {
              iVar6 = iVar3 + 1;
              pCVar4 = UTIL_PlayerByIndex(iVar6);
              if ((pCVar4 != (CBasePlayer *)0x0) &&
                 (iVar5 = (*this->m_pHelper->_vptr_IVoiceGameMgrHelper[2])
                                    (this->m_pHelper,pCVar2,pCVar4), (char)iVar5 != '\0')) {
                local_2c[iVar3 >> 5].m_DWords[0] =
                     local_2c[iVar3 >> 5].m_DWords[0] | 1 << ((byte)iVar3 & 0x1f);
              }
              iVar3 = iVar6;
            } while (iVar6 < this->m_nMaxPlayers);
          }
        }
        else {
                    /* Unresolved local var: int iOtherClient@[???] */
          if (0 < this->m_nMaxPlayers) {
            do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
              iVar6 = iVar3 + 1;
              pCVar4 = UTIL_PlayerByIndex(iVar6);
              if (pCVar4 != (CBasePlayer *)0x0) {
                local_2c[iVar3 >> 5].m_DWords[0] =
                     local_2c[iVar3 >> 5].m_DWords[0] | 1 << ((byte)iVar3 & 0x1f);
              }
              iVar3 = iVar6;
            } while (iVar6 < this->m_nMaxPlayers);
          }
        }
      }
      CVar9.m_DWords[0] = local_2c[0].m_DWords[0];
                    /* Unresolved local var: int i@[???] */
                    /* Unresolved local var: int i@[???] */
      if ((local_2c[0].m_DWords[0] != (uint  [1])g_SentGameRulesMasks[local_38].m_DWords[0]) ||
         (g_BanMasks[local_38].m_DWords[0] != g_SentBanMasks[local_38].m_DWords[0])) {
                    /* Unresolved local var: int dw@[???] */
        g_SentGameRulesMasks[local_38].m_DWords[0] = (uint)local_2c[0].m_DWords[0];
        g_SentBanMasks[local_38].m_DWords[0] = g_BanMasks[local_38].m_DWords[0];
        (*g_engfuncs.pfnMessageBegin)
                  (1,this->m_msgPlayerVoiceMask,(float *)0x0,
                   ((pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        (*g_engfuncs.pfnWriteLong)((int)CVar9.m_DWords[0]);
        (*g_engfuncs.pfnWriteLong)(g_BanMasks[local_38].m_DWords[0]);
        (*g_engfuncs.pfnMessageEnd)();
      }
                    /* Unresolved local var: int iOtherClient@[???] */
      iVar3 = this->m_nMaxPlayers;
      if (0 < iVar3) {
                    /* Unresolved local var: bool bCanHear@[???] */
        iVar6 = 0;
        while( true ) {
          uVar7 = 0;
          uVar8 = 1 << ((byte)iVar6 & 0x1f);
          if ((uVar8 & (uint)CVar9.m_DWords[0]) != 0) {
            uVar7 = (uint)((g_BanMasks[(iVar6 >> 5) + local_38].m_DWords[0] & uVar8) == 0);
          }
          iVar6 = iVar6 + 1;
          (*g_engfuncs.pfnVoice_SetClientListening)(playerIndex,iVar6,uVar7);
          iVar3 = this->m_nMaxPlayers;
          if (iVar3 <= iVar6) break;
          CVar9.m_DWords[0] = (uint  [1])local_2c[iVar6 >> 5].m_DWords[0];
        }
      }
    }
  }
  return;
}


