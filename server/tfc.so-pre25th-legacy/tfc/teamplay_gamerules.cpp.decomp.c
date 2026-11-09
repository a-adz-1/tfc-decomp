// Ghidra decompilation of functions from tfc/teamplay_gamerules.cpp
// 14 functions, ordered by original source line

// CHalfLifeTeamplay::CHalfLifeTeamplay  @ 0012ac00  (line 22)

/* DWARF original prototype: void CHalfLifeTeamplay(CHalfLifeTeamplay * this) */

void __thiscall CHalfLifeTeamplay::CHalfLifeTeamplay(CHalfLifeTeamplay *this)

{
  CHalfLifeMultiplay::CHalfLifeMultiplay(&this->super_CHalfLifeMultiplay);
  (this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules =
       (_func_int_varargs **)&PTR_RefreshSkillData_0018d0a8;
  this->m_DisableDeathMessages = 0;
  this->m_DisableDeathPenalty = 0;
  return;
}


// CHalfLifeTeamplay::PlayerSpawn  @ 0012a440  (line 31)

/* DWARF original prototype: void PlayerSpawn(CHalfLifeTeamplay * this, CBasePlayer * pPlayer) */

void __thiscall CHalfLifeTeamplay::PlayerSpawn(CHalfLifeTeamplay *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
  if (iVar2 != 0) {
    piVar1 = &((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.pev)->weapons;
    *piVar1 = *piVar1 | 0x80000000;
    return;
  }
  CHalfLifeMultiplay::PlayerSpawn(&this->super_CHalfLifeMultiplay,pPlayer);
  return;
}


// CHalfLifeTeamplay::ClientCommand  @ 0012a650  (line 47)

/* DWARF original prototype: BOOL ClientCommand(CHalfLifeTeamplay * this, CBasePlayer * pPlayer,
   char * pcmd) */

BOOL __thiscall
CHalfLifeTeamplay::ClientCommand(CHalfLifeTeamplay *this,CBasePlayer *pPlayer,char *pcmd)

{
  BOOL BVar1;
  
  (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
  BVar1 = CHalfLifeMultiplay::ClientCommand(&this->super_CHalfLifeMultiplay,pPlayer,pcmd);
  return BVar1;
}


// CHalfLifeTeamplay::UpdateGameMode  @ 0012aad0  (line 59)

/* DWARF original prototype: void UpdateGameMode(CHalfLifeTeamplay * this, CBasePlayer * pPlayer) */

void __thiscall CHalfLifeTeamplay::UpdateGameMode(CHalfLifeTeamplay *this,CBasePlayer *pPlayer)

{
  int iVar1;
  
  iVar1 = (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
  if (iVar1 != 0) {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgGameMode,(float *)0x0,
               ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(1);
                    /* WARNING: Could not recover jumptable at 0x0012ab3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnMessageEnd)();
    return;
  }
  CHalfLifeMultiplay::UpdateGameMode(&this->super_CHalfLifeMultiplay,pPlayer);
  return;
}


// CHalfLifeTeamplay::InitHUD  @ 0012a9c0  (line 75)

/* DWARF original prototype: void InitHUD(CHalfLifeTeamplay * this, CBasePlayer * pl) */

void __thiscall CHalfLifeTeamplay::InitHUD(CHalfLifeTeamplay *this,CBasePlayer *pl)

{
  void *pvVar1;
  _func_void_int *p_Var2;
  _func_void_char_ptr *p_Var3;
  int iVar4;
  edict_t *peVar5;
  int iVar6;
  char *pcVar7;
  
  iVar4 = (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
  if (iVar4 != 0) {
    CHalfLifeMultiplay::InitHUD(&this->super_CHalfLifeMultiplay,pl);
                    /* Unresolved local var: int i@[???] */
    if (0 < gpGlobals->maxClients) {
      iVar4 = 1;
      do {
                    /* Unresolved local var: edict_t * ed@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBasePlayer * plr@[???] */
        peVar5 = (*g_engfuncs.pfnPEntityOfEntIndex)(iVar4);
        if ((peVar5 != (edict_t *)0x0) && (pvVar1 = peVar5->pvPrivateData, pvVar1 != (void *)0x0)) {
          (*g_engfuncs.pfnMessageBegin)
                    (1,gmsgTeamInfo,(float *)0x0,
                     ((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          p_Var2 = g_engfuncs.pfnWriteByte;
          iVar6 = (*g_engfuncs.pfnIndexOfEdict)(*(edict_t **)(*(int *)((int)pvVar1 + 4) + 0x208));
          (*p_Var2)(iVar6);
          p_Var3 = g_engfuncs.pfnWriteString;
          pcVar7 = (char *)(*g_pGameRules->_vptr_CGameRules[0x31])(g_pGameRules,pvVar1);
          (*p_Var3)(pcVar7);
          (*g_engfuncs.pfnMessageEnd)();
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 <= gpGlobals->maxClients);
    }
    return;
  }
  CHalfLifeMultiplay::InitHUD(&this->super_CHalfLifeMultiplay,pl);
  return;
}


// CHalfLifeTeamplay::ClientUserInfoChanged  @ 0012a2e0  (line 112)

/* DWARF original prototype: void ClientUserInfoChanged(CHalfLifeTeamplay * this, CBasePlayer *
   pPlayer, char * infobuffer) */

void __thiscall
CHalfLifeTeamplay::ClientUserInfoChanged
          (CHalfLifeTeamplay *this,CBasePlayer *pPlayer,char *infobuffer)

{
  return;
}


// CHalfLifeTeamplay::DeathNotice  @ 0012a6a0  (line 122)

/* DWARF original prototype: void DeathNotice(CHalfLifeTeamplay * this, CBasePlayer * pVictim,
   entvars_t * pKiller, entvars_t * pevInflictor) */

void __thiscall
CHalfLifeTeamplay::DeathNotice
          (CHalfLifeTeamplay *this,CBasePlayer *pVictim,entvars_t *pKiller,entvars_t *pevInflictor)

{
  int *piVar1;
  CBasePlayer *this_00;
  char *pcVar2;
  string_t sVar3;
  _func_void_int *p_Var4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  edict_t *peVar9;
  char *pcVar10;
  char *local_4c;
  void *local_40;
  char local_3a [42];
  
                    /* Unresolved local var: char[30] weapon@[???] */
  iVar5 = (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
  if (iVar5 == 0) {
    CHalfLifeMultiplay::DeathNotice(&this->super_CHalfLifeMultiplay,pVictim,pKiller,pevInflictor);
    return;
  }
  if (this->m_DisableDeathMessages != 0) {
    return;
  }
                    /* Unresolved local var: char[30] weapon@[???] */
                    /* Unresolved local var: CBasePlayer * pk@[DW_OP_reg7(EDI)] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((((pKiller == (entvars_t *)0x0) || (pVictim == (CBasePlayer *)0x0)) ||
       ((pKiller->flags & 8) == 0)) ||
      ((peVar9 = pKiller->pContainingEntity, peVar9 == (edict_t *)0x0 &&
       (peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar9 == (edict_t *)0x0)))) ||
     ((this_00 = peVar9->pvPrivateData, this_00 == (CBasePlayer *)0x0 ||
      ((pVictim == this_00 ||
       (iVar5 = (*(this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules[0x32])
                          (this,pVictim,this_00), iVar5 != 1)))))) {
    CHalfLifeMultiplay::DeathNotice(&this->super_CHalfLifeMultiplay,pVictim,pKiller,pevInflictor);
    return;
  }
                    /* Unresolved local var: CBasePlayer * pPlayer@[DW_OP_breg4(ESP): +76] */
  (*g_engfuncs.pfnMessageBegin)(2,gmsgDeathMsg,(float *)0x0,(edict_t *)0x0);
  p_Var4 = g_engfuncs.pfnWriteByte;
  iVar5 = (*g_engfuncs.pfnIndexOfEdict)(pKiller->pContainingEntity);
  (*p_Var4)(iVar5);
  p_Var4 = g_engfuncs.pfnWriteByte;
  iVar5 = (*g_engfuncs.pfnIndexOfEdict)
                    (((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var4)(iVar5);
  (*g_engfuncs.pfnWriteString)("teammate");
  (*g_engfuncs.pfnMessageEnd)();
  GetWeapon(pevInflictor,pKiller,local_3a);
  peVar9 = pKiller->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar9 == (edict_t *)0x0) {
    peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    local_40 = (void *)0x0;
    if (peVar9 == (edict_t *)0x0) goto LAB_0012a841;
  }
  local_40 = peVar9->pvPrivateData;
LAB_0012a841:
  iVar5 = (pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no;
  local_4c = "SPECTATOR";
  if (iVar5 != 0) {
    local_4c = GetTeamName(iVar5);
  }
  pcVar6 = (*g_engfuncs.pfnGetPlayerAuthId)
                     (((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  iVar5 = (*g_engfuncs.pfnGetPlayerUserId)
                    (((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  pcVar2 = gpGlobals->pStringBase;
  sVar3 = ((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->netname;
  pcVar10 = "SPECTATOR";
  if (*(int *)((int)local_40 + 0x138) != 0) {
    pcVar10 = GetTeamName(*(int *)((int)local_40 + 0x138));
  }
  pcVar7 = (*g_engfuncs.pfnGetPlayerAuthId)(pKiller->pContainingEntity);
  iVar8 = (*g_engfuncs.pfnGetPlayerUserId)(pKiller->pContainingEntity);
  UTIL_LogPrintf("\"%s<%i><%s><%s>\" killed \"%s<%i><%s><%s>\" with \"%s\"\n",
                 gpGlobals->pStringBase + pKiller->netname,iVar8,pcVar7,pcVar10,pcVar2 + sVar3,iVar5
                 ,pcVar6,local_4c,local_3a);
  if ((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.undercover_team == 0) {
    piVar1 = &(this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.teamkills;
    *piVar1 = *piVar1 + 1;
    CBasePlayer::CheckAutoKick(this_00);
  }
  return;
}


// CHalfLifeTeamplay::PlayerKilled  @ 0012a3c0  (line 181)

/* DWARF original prototype: void PlayerKilled(CHalfLifeTeamplay * this, CBasePlayer * pVictim,
   entvars_t * pKiller, entvars_t * pInflictor) */

void __thiscall
CHalfLifeTeamplay::PlayerKilled
          (CHalfLifeTeamplay *this,CBasePlayer *pVictim,entvars_t *pKiller,entvars_t *pInflictor)

{
  int iVar1;
  
  iVar1 = (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
  if ((iVar1 != 0) && (this->m_DisableDeathPenalty != 0)) {
    return;
  }
  CHalfLifeMultiplay::PlayerKilled(&this->super_CHalfLifeMultiplay,pVictim,pKiller,pInflictor);
  return;
}


// CHalfLifeTeamplay::IsTeamplay  @ 0012a2f0  (line 199)

/* DWARF original prototype: BOOL IsTeamplay(CHalfLifeTeamplay * this) */

BOOL __thiscall CHalfLifeTeamplay::IsTeamplay(CHalfLifeTeamplay *this)

{
  return 1;
}


// CHalfLifeTeamplay::FPlayerCanTakeDamage  @ 0012a320  (line 202)

/* DWARF original prototype: BOOL FPlayerCanTakeDamage(CHalfLifeTeamplay * this, CBasePlayer *
   pPlayer, CBaseEntity * pAttacker) */

BOOL __thiscall
CHalfLifeTeamplay::FPlayerCanTakeDamage
          (CHalfLifeTeamplay *this,CBasePlayer *pPlayer,CBaseEntity *pAttacker)

{
  int iVar1;
  BOOL BVar2;
  longdouble extraout_ST0;
  
  iVar1 = (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
  if ((((iVar1 != 0) && (pAttacker != (CBaseEntity *)0x0)) &&
      (iVar1 = (*(this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules[0x32])
                         (this,pPlayer,pAttacker), iVar1 == 1)) &&
     (((*g_engfuncs.pfnCVarGetFloat)("mp_friendlyfire"), extraout_ST0 == (longdouble)0 &&
      ((CBasePlayer *)pAttacker != pPlayer)))) {
    return 0;
  }
  BVar2 = CHalfLifeMultiplay::FPlayerCanTakeDamage
                    (&this->super_CHalfLifeMultiplay,pPlayer,pAttacker);
  return BVar2;
}


// CHalfLifeTeamplay::PlayerRelationship  @ 0012a530  (line 222)

/* DWARF original prototype: int PlayerRelationship(CHalfLifeTeamplay * this, CBasePlayer * pPlayer,
   CBaseEntity * pTarget) */

int __thiscall
CHalfLifeTeamplay::PlayerRelationship
          (CHalfLifeTeamplay *this,CBasePlayer *pPlayer,CBaseEntity *pTarget)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  BOOL BVar4;
  char *__s1;
  
  iVar1 = (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
  if (iVar1 == 0) {
    iVar1 = CHalfLifeMultiplay::PlayerRelationship(&this->super_CHalfLifeMultiplay,pPlayer,pTarget);
    return iVar1;
  }
  if ((pTarget == (CBaseEntity *)0x0) || (pPlayer == (CBasePlayer *)0x0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    if ((pTarget->pev->flags & 8) != 0) {
      pcVar3 = (char *)(*(this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules[0x31])
                                 (this,pPlayer);
      if ((*pcVar3 != '\0') &&
         (pcVar3 = (char *)(*(this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules
                             [0x31])(this,pTarget), *pcVar3 != '\0')) {
        pcVar3 = (char *)(*(this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules[0x31])
                                   (this,pTarget);
        __s1 = (char *)(*(this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules[0x31])
                                 (this,pPlayer);
        iVar1 = strcasecmp(__s1,pcVar3);
        if (iVar1 == 0) {
          return 1;
        }
      }
      BVar4 = CBaseEntity::IsAlly((CBaseEntity *)pPlayer,pTarget);
      uVar2 = (uint)(BVar4 != 0);
    }
  }
  return uVar2;
}


// CHalfLifeTeamplay::ShouldAutoAim  @ 0012ab60  (line 246)

/* DWARF original prototype: BOOL ShouldAutoAim(CHalfLifeTeamplay * this, CBasePlayer * pPlayer,
   edict_t * target) */

BOOL __thiscall
CHalfLifeTeamplay::ShouldAutoAim(CHalfLifeTeamplay *this,CBasePlayer *pPlayer,edict_t *target)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
                    /* Unresolved local var: CBaseEntity * pTgt@[???] */
  uVar3 = 1;
  iVar2 = (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
                    /* Unresolved local var: CBaseEntity * pTgt@[DW_OP_reg6(ESI)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((iVar2 != 0) &&
     ((target != (edict_t *)0x0 ||
      (target = (*g_engfuncs.pfnPEntityOfEntOffset)(0), target != (edict_t *)0x0)))) {
    piVar1 = target->pvPrivateData;
    uVar3 = 1;
    if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x28))(piVar1), iVar2 == 2)) {
                    /* Unresolved local var: CBasePlayer * pTarget@[???] */
      iVar2 = (*(this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules[0x32])
                        (this,pPlayer,piVar1);
      uVar3 = (uint)(iVar2 != 1);
    }
  }
  return uVar3;
}


// CHalfLifeTeamplay::IPointsForKill  @ 0012a4a0  (line 265)

/* DWARF original prototype: int IPointsForKill(CHalfLifeTeamplay * this, CBasePlayer * pAttacker,
   CBasePlayer * pKilled) */

int __thiscall
CHalfLifeTeamplay::IPointsForKill
          (CHalfLifeTeamplay *this,CBasePlayer *pAttacker,CBasePlayer *pKilled)

{
  int iVar1;
  
  iVar1 = (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
  if (iVar1 != 0) {
    iVar1 = 0;
    if (((pKilled != (CBasePlayer *)0x0) && (iVar1 = 1, pAttacker != (CBasePlayer *)0x0)) &&
       (pAttacker != pKilled)) {
      iVar1 = (*(this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules[0x32])
                        (this,pAttacker,pKilled);
      iVar1 = (uint)(iVar1 != 1) * 2 + -1;
    }
    return iVar1;
  }
  iVar1 = CHalfLifeMultiplay::IPointsForKill(&this->super_CHalfLifeMultiplay,pAttacker,pKilled);
  return iVar1;
}


// CHalfLifeTeamplay::GetTeamID  @ 0012a300  (line 283)

/* DWARF original prototype: char * GetTeamID(CHalfLifeTeamplay * this, CBaseEntity * pEntity) */

char * __thiscall CHalfLifeTeamplay::GetTeamID(CHalfLifeTeamplay *this,CBaseEntity *pEntity)

{
  (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
  return "";
}


