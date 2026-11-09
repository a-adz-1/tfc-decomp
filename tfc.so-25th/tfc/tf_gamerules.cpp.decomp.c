// Ghidra decompilation of functions from tfc/tf_gamerules.cpp
// 18 functions, ordered by original source line

// TFGameMgrHelper::~TFGameMgrHelper  @ 000f97b0  (line 27)

/* DWARF original prototype: void ~TFGameMgrHelper(TFGameMgrHelper * this, int __in_chrg) */

void __thiscall TFGameMgrHelper::~TFGameMgrHelper(TFGameMgrHelper *this,int __in_chrg)

{
  return;
}


// TFGameMgrHelper::~TFGameMgrHelper  @ 000f97c0  (line 27)

/* DWARF original prototype: void ~TFGameMgrHelper(TFGameMgrHelper * this, int __in_chrg) */

void __thiscall TFGameMgrHelper::~TFGameMgrHelper(TFGameMgrHelper *this,int __in_chrg)

{
  operator_delete(this);
  return;
}


// TFGameMgrHelper::CanPlayerHearPlayer  @ 000f9780  (line 32)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: bool CanPlayerHearPlayer(TFGameMgrHelper * this, CBasePlayer *
   pPlayer1, CBasePlayer * pPlayer2) */

bool __thiscall
TFGameMgrHelper::CanPlayerHearPlayer
          (TFGameMgrHelper *this,CBasePlayer *pPlayer1,CBasePlayer *pPlayer2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (pPlayer1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no;
  iVar2 = (pPlayer2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no;
  if (iVar1 != iVar2) {
    return (bool)((byte)(teamallies[iVar1] >> ((char)iVar2 - 1U & 0x1f)) & 1);
  }
  return true;
}


// CTeamFortress::CTeamFortress  @ 000f93b0  (line 39)

/* DWARF original prototype: void CTeamFortress(CTeamFortress * this) */

void __thiscall CTeamFortress::CTeamFortress(CTeamFortress *this)

{
  CHalfLifeTeamplay::CHalfLifeTeamplay(&this->super_CHalfLifeTeamplay);
  (this->super_CHalfLifeTeamplay).super_CHalfLifeMultiplay.super_CGameRules._vptr_CGameRules =
       (_func_int_varargs **)&PTR_RefreshSkillData_0015c738;
  CVoiceGameMgr::CVoiceGameMgr(&this->m_VoiceGameMgr);
  CVoiceGameMgr::Init(&this->m_VoiceGameMgr,&g_GameMgrHelper.super_IVoiceGameMgrHelper,
                      gpGlobals->maxClients);
  return;
}


// CTeamFortress::Think  @ 000f9420  (line 46)

/* DWARF original prototype: void Think(CTeamFortress * this) */

void __thiscall CTeamFortress::Think(CTeamFortress *this)

{
  CVoiceGameMgr::Update(&this->m_VoiceGameMgr,(double)gpGlobals->frametime);
  CHalfLifeMultiplay::Think((CHalfLifeMultiplay *)this);
  return;
}


// CTeamFortress::IsTeamplay  @ 000f8f40  (line 58)

/* DWARF original prototype: BOOL IsTeamplay(CTeamFortress * this) */

BOOL __thiscall CTeamFortress::IsTeamplay(CTeamFortress *this)

{
  return (uint)(0.0 < gpGlobals->teamplay);
}


// CTeamFortress::PlayerSpawn  @ 000f8f60  (line 66)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlayerSpawn(CTeamFortress * this, CBasePlayer * pPlayer) */

void __thiscall CTeamFortress::PlayerSpawn(CTeamFortress *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  
  piVar1 = &((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->weapons;
  *piVar1 = *piVar1 | 0x80000000;
  return;
}


// CTeamFortress::ClientConnected  @ 000f9450  (line 72)

/* DWARF original prototype: BOOL ClientConnected(CTeamFortress * this, edict_t * pEntity, char *
   pszName, char * pszAddress, char * szRejectReason) */

BOOL __thiscall
CTeamFortress::ClientConnected
          (CTeamFortress *this,edict_t *pEntity,char *pszName,char *pszAddress,char *szRejectReason)

{
  _func_void_int *p_Var1;
  _func_void_char_ptr *p_Var2;
  int iVar3;
  char *pcVar4;
  BOOL BVar5;
  
  CVoiceGameMgr::ClientConnected(&this->m_VoiceGameMgr,pEntity);
  if (g_bFirstClient == 0) {
    g_bFirstClient = 1;
    ParseTFServerSettings();
  }
  (*g_engfuncs.pfnMessageBegin)(2,gmsgTeamInfo,(float *)0x0,(edict_t *)0x0);
  p_Var1 = g_engfuncs.pfnWriteByte;
  iVar3 = (*g_engfuncs.pfnIndexOfEdict)(pEntity);
  (*p_Var1)(iVar3);
  (*g_engfuncs.pfnWriteString)("");
  (*g_engfuncs.pfnMessageEnd)();
  (*g_engfuncs.pfnMessageBegin)(1,9,(float *)0x0,pEntity);
  p_Var2 = g_engfuncs.pfnWriteString;
  pcVar4 = UTIL_VarArgs("cl_forwardspeed %d\ncl_backspeed %d\ncl_sidespeed %d\n",400,400,400);
  (*p_Var2)(pcVar4);
  (*g_engfuncs.pfnMessageEnd)();
  BVar5 = CHalfLifeMultiplay::ClientConnected
                    ((CHalfLifeMultiplay *)this,pEntity,pszName,pszAddress,szRejectReason);
  return BVar5;
}


// CTeamFortress::ClientCommand  @ 000f9590  (line 102)

/* DWARF original prototype: BOOL ClientCommand(CTeamFortress * this, CBasePlayer * pPlayer, char *
   pcmd) */

BOOL __thiscall CTeamFortress::ClientCommand(CTeamFortress *this,CBasePlayer *pPlayer,char *pcmd)

{
  bool bVar1;
  BOOL BVar2;
  
  bVar1 = CVoiceGameMgr::ClientCommand(&this->m_VoiceGameMgr,pPlayer,pcmd);
  if (bVar1) {
    return 1;
  }
  BVar2 = CHalfLifeTeamplay::ClientCommand(&this->super_CHalfLifeTeamplay,pPlayer,pcmd);
  return BVar2;
}


// CTeamFortress::InitHUD  @ 000f9600  (line 113)

/* DWARF original prototype: void InitHUD(CTeamFortress * this, CBasePlayer * pl) */

void __thiscall CTeamFortress::InitHUD(CTeamFortress *this,CBasePlayer *pl)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  longdouble extraout_ST0;
  
  CHalfLifeTeamplay::InitHUD(&this->super_CHalfLifeTeamplay,pl);
  pcVar1 = (*g_engfuncs.pfnGetPlayerAuthId)
                     (((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  iVar2 = (*g_engfuncs.pfnGetPlayerUserId)
                    (((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  UTIL_LogPrintf("\"%s<%i><%s><>\" entered the game\n",
                 gpGlobals->pStringBase +
                 ((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->netname,iVar2,pcVar1);
  pcVar1 = (*g_engfuncs.pfnGetPlayerAuthId)
                     (((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  iVar3 = (*g_engfuncs.pfnGetPlayerUserId)
                    (((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  iVar2 = 1;
  UTIL_LogPrintf("\"%s<%i><%s><>\" joined team \"SPECTATOR\"\n",
                 gpGlobals->pStringBase +
                 ((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->netname,iVar3,pcVar1);
                    /* Unresolved local var: int i@[???] */
  if (1.0 <= number_of_teams) {
    do {
      iVar3 = iVar2 + 1;
      TeamFortress_TeamIncreaseScore(iVar2,0);
      iVar2 = iVar3;
    } while ((float)iVar3 <= number_of_teams);
  }
  CBasePlayer::TeamFortress_ExecMapScript(pl);
  pl->m_bDisplayedMOTD = 0;
  (*g_engfuncs.pfnCVarGetFloat)("sv_cheats");
  if (extraout_ST0 == (longdouble)0) {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgViewMode,(float *)0x0,
               ((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
                    /* WARNING: Could not recover jumptable at 0x000f9766. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnMessageEnd)();
    return;
  }
  return;
}


// CTeamFortress::ClientUserInfoChanged  @ 000f8fc0  (line 147)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ClientUserInfoChanged(CTeamFortress * this, CBasePlayer * pPlayer,
   char * infobuffer) */

void __thiscall
CTeamFortress::ClientUserInfoChanged(CTeamFortress *this,CBasePlayer *pPlayer,char *infobuffer)

{
  char *pcVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  byte bVar7;
  
                    /* Unresolved local var: char * st@[???] */
  bVar7 = 0;
  CBasePlayer::TeamFortress_SetSkin(pPlayer);
  (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.exec_scripts = 0;
  pcVar1 = (*g_engfuncs.pfnInfoKeyValue)(infobuffer,"ec");
  if (((pcVar1 != (char *)0x0) && (bVar6 = false, *pcVar1 != '\0')) ||
     ((pcVar1 = (*g_engfuncs.pfnInfoKeyValue)(infobuffer,"exec_class"), pcVar1 != (char *)0x0 &&
      (bVar6 = *pcVar1 == '\0', !bVar6)))) {
    iVar3 = 2;
    pcVar4 = pcVar1;
    pcVar5 = "1";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
      pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
    } while (bVar6);
    if (!bVar6) {
      iVar3 = 3;
      pcVar4 = "on";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pcVar1 == *pcVar4;
        pcVar1 = pcVar1 + (uint)bVar7 * -2 + 1;
        pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
      } while (bVar6);
      if (!bVar6) goto LAB_000f9030;
    }
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.exec_scripts = 1;
  }
LAB_000f9030:
  (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.exec_map_scripts = 0;
  pcVar1 = (*g_engfuncs.pfnInfoKeyValue)(infobuffer,"em");
  if (pcVar1 == (char *)0x0) {
    (*g_engfuncs.pfnInfoKeyValue)(infobuffer,"exec_map");
  }
  else if ((*pcVar1 != '\0') ||
          ((*g_engfuncs.pfnInfoKeyValue)(infobuffer,"exec_map"), *pcVar1 != '\0')) {
    bVar6 = false;
    iVar3 = 2;
    pcVar4 = pcVar1;
    pcVar5 = "1";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
      pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
    } while (bVar6);
    if (!bVar6) {
      iVar3 = 3;
      pcVar4 = "on";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pcVar1 == *pcVar4;
        pcVar1 = pcVar1 + (uint)bVar7 * -2 + 1;
        pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
      } while (bVar6);
      if (!bVar6) goto LAB_000f9080;
    }
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.exec_map_scripts = 1;
  }
LAB_000f9080:
  (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.display_class_briefing = 0;
  (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.take_screenshots = 0;
  pcVar1 = (*g_engfuncs.pfnInfoKeyValue)(infobuffer,"take_sshot");
  if (((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) ||
     ((pcVar1 = (*g_engfuncs.pfnInfoKeyValue)(infobuffer,"ts"), pcVar1 != (char *)0x0 &&
      (*pcVar1 != '\0')))) {
    bVar6 = false;
    iVar3 = 2;
    pcVar4 = pcVar1;
    pcVar5 = "1";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
      pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
    } while (bVar6);
    if (!bVar6) {
      iVar3 = 3;
      pcVar4 = "on";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pcVar1 == *pcVar4;
        pcVar1 = pcVar1 + (uint)bVar7 * -2 + 1;
        pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
      } while (bVar6);
      if (!bVar6) goto LAB_000f90e0;
    }
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.take_screenshots = 1;
  }
LAB_000f90e0:
  (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.local_blood = 1;
  pcVar1 = (*g_engfuncs.pfnInfoKeyValue)(infobuffer,"cl_lb");
  if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
    lVar2 = strtol(pcVar1,(char **)0x0,10);
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.local_blood = (uint)(lVar2 != 0);
  }
  return;
}


// CTeamFortress::DeadPlayerWeapons  @ 000f8f80  (line 210)

/* DWARF original prototype: int DeadPlayerWeapons(CTeamFortress * this, CBasePlayer * pPlayer) */

int __thiscall CTeamFortress::DeadPlayerWeapons(CTeamFortress *this,CBasePlayer *pPlayer)

{
  return 9;
}


// CTeamFortress::DeadPlayerAmmo  @ 000f8f90  (line 217)

/* DWARF original prototype: int DeadPlayerAmmo(CTeamFortress * this, CBasePlayer * pPlayer) */

int __thiscall CTeamFortress::DeadPlayerAmmo(CTeamFortress *this,CBasePlayer *pPlayer)

{
  return 10;
}


// CTeamFortress::FlItemRespawnTime  @ 000f8fa0  (line 223)

/* DWARF original prototype: float FlItemRespawnTime(CTeamFortress * this, CItem * pItem) */

float __thiscall CTeamFortress::FlItemRespawnTime(CTeamFortress *this,CItem *pItem)

{
  return gpGlobals->time + pItem->m_flRespawnTime;
}


// CTeamFortress::CanHaveItem  @ 000f9230  (line 229)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL CanHaveItem(CTeamFortress * this, CBasePlayer * pPlayer, CItem *
   pItem) */

BOOL __thiscall CTeamFortress::CanHaveItem(CTeamFortress *this,CBasePlayer *pPlayer,CItem *pItem)

{
  BOOL BVar1;
  
  if ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_feigning != 0) {
    return 0;
  }
  if ((((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.tfstate & 0x10800U) == 0) && (cb_prematch_time <= gpGlobals->time)) {
    BVar1 = ActivationSucceeded(&pItem->super_CBaseEntity,pPlayer,(CBaseEntity *)0x0);
    return (uint)(BVar1 != 0);
  }
  return 0;
}


// CTeamFortress::GetTeamID  @ 000f9210  (line 248)

/* DWARF original prototype: char * GetTeamID(CTeamFortress * this, CBaseEntity * pEntity) */

char * __thiscall CTeamFortress::GetTeamID(CTeamFortress *this,CBaseEntity *pEntity)

{
  char *pcVar1;
  
  pcVar1 = GetTeamName(pEntity->team_no);
  return pcVar1;
}


// CTeamFortress::GoToIntermission  @ 000f92a0  (line 258)

/* DWARF original prototype: void GoToIntermission(CTeamFortress * this) */

void __thiscall CTeamFortress::GoToIntermission(CTeamFortress *this)

{
  float fVar1;
  _2globalvars_t *p1Var2;
  _func_void_char_ptr_char_ptr *p_Var3;
  char *pcVar4;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: int time@[???] */
  if (g_fGameOver != 0) {
    return;
  }
                    /* Unresolved local var: int time@[???] */
  (*g_engfuncs.pfnMessageBegin)(2,0x1e,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnMessageEnd)();
  DumpClanScores();
  clan_scores_dumped = 1.0;
  (*g_engfuncs.pfnCVarGetFloat)("mp_chattime");
  p_Var3 = g_engfuncs.pfnCVarSetString;
  if ((int)extraout_ST0 < 1) {
    (*g_engfuncs.pfnCVarSetString)("mp_chattime","1");
  }
  else if (0x78 < (int)extraout_ST0) {
    pcVar4 = UTIL_dtos1(0x78);
    (*p_Var3)("mp_chattime",pcVar4);
  }
  p1Var2 = gpGlobals;
  (this->super_CHalfLifeTeamplay).super_CHalfLifeMultiplay.m_flIntermissionEndTime =
       (float)(int)mp_chattime.value + gpGlobals->time;
  fVar1 = p1Var2->time;
  (this->super_CHalfLifeTeamplay).super_CHalfLifeMultiplay.m_iEndIntermissionButtonHit = 0;
  g_fGameOver = 1;
  (this->super_CHalfLifeTeamplay).super_CHalfLifeMultiplay.m_flIntermissionStartTime = fVar1;
  return;
}


// _GLOBAL__sub_I__ZN13CTeamFortressC2Ev  @ 0006c400  (line 286)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN13CTeamFortressC2Ev(void)

{
  __cxa_atexit(TFGameMgrHelper::~TFGameMgrHelper,&g_GameMgrHelper,&__dso_handle);
  return;
}


