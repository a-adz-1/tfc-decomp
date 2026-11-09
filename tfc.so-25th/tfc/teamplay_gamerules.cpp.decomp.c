// Ghidra decompilation of functions from tfc/teamplay_gamerules.cpp
// 15 functions, ordered by original source line

// CHalfLifeTeamplay::CHalfLifeTeamplay  @ 000f6310  (line 22)

/* DWARF original prototype: void CHalfLifeTeamplay(CHalfLifeTeamplay * this) */

void __thiscall CHalfLifeTeamplay::CHalfLifeTeamplay(CHalfLifeTeamplay *this)

{
  CHalfLifeMultiplay::CHalfLifeMultiplay(&this->super_CHalfLifeMultiplay);
  (this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules =
       (_func_int_varargs **)&PTR_RefreshSkillData_0015c090;
  this->m_DisableDeathMessages = 0;
  this->m_DisableDeathPenalty = 0;
  return;
}


// CHalfLifeTeamplay::PlayerSpawn  @ 000f6340  (line 31)

/* DWARF original prototype: void PlayerSpawn(CHalfLifeTeamplay * this, CBasePlayer * pPlayer) */

void __thiscall CHalfLifeTeamplay::PlayerSpawn(CHalfLifeTeamplay *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  int iVar2;
  
  if (g_pGameRules->_vptr_CGameRules[8] != IsTeamplay) {
    iVar2 = (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
    if (iVar2 == 0) {
      CHalfLifeMultiplay::PlayerSpawn(&this->super_CHalfLifeMultiplay,pPlayer);
      return;
    }
  }
  piVar1 = &((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->weapons;
  *piVar1 = *piVar1 | 0x80000000;
  return;
}


// CHalfLifeTeamplay::ClientCommand  @ 000f63b0  (line 47)

/* DWARF original prototype: BOOL ClientCommand(CHalfLifeTeamplay * this, CBasePlayer * pPlayer,
   char * pcmd) */

BOOL __thiscall
CHalfLifeTeamplay::ClientCommand(CHalfLifeTeamplay *this,CBasePlayer *pPlayer,char *pcmd)

{
  BOOL BVar1;
  
  if (g_pGameRules->_vptr_CGameRules[8] != IsTeamplay) {
    (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
  }
  BVar1 = CHalfLifeMultiplay::ClientCommand(&this->super_CHalfLifeMultiplay,pPlayer,pcmd);
  return BVar1;
}


// CHalfLifeTeamplay::UpdateGameMode  @ 000f6410  (line 59)

/* DWARF original prototype: void UpdateGameMode(CHalfLifeTeamplay * this, CBasePlayer * pPlayer) */

void __thiscall CHalfLifeTeamplay::UpdateGameMode(CHalfLifeTeamplay *this,CBasePlayer *pPlayer)

{
  int iVar1;
  
  if (g_pGameRules->_vptr_CGameRules[8] != IsTeamplay) {
    iVar1 = (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
    if (iVar1 == 0) {
      CHalfLifeMultiplay::UpdateGameMode(&this->super_CHalfLifeMultiplay,pPlayer);
      return;
    }
  }
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgGameMode,(float *)0x0,
             ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(1);
                    /* WARNING: Could not recover jumptable at 0x000f6476. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CHalfLifeTeamplay::InitHUD  @ 000f64b0  (line 75)

/* DWARF original prototype: void InitHUD(CHalfLifeTeamplay * this, CBasePlayer * pl) */

void __thiscall CHalfLifeTeamplay::InitHUD(CHalfLifeTeamplay *this,CBasePlayer *pl)

{
  void *pvVar1;
  _func_void_int *p_Var2;
  _func_void_char_ptr *p_Var3;
  edict_t *peVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  
  if ((g_pGameRules->_vptr_CGameRules[8] != IsTeamplay) &&
     (iVar7 = (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules), iVar7 == 0)) {
    CHalfLifeMultiplay::InitHUD(&this->super_CHalfLifeMultiplay,pl);
    return;
  }
                    /* Unresolved local var: int i@[???] */
  iVar7 = 1;
  CHalfLifeMultiplay::InitHUD(&this->super_CHalfLifeMultiplay,pl);
  if (0 < gpGlobals->maxClients) {
    do {
                    /* Unresolved local var: edict_t * ed@[???]
                       Unresolved local var: CBasePlayer * plr@[???] */
      peVar4 = (*g_engfuncs.pfnPEntityOfEntIndex)(iVar7);
      if ((peVar4 != (edict_t *)0x0) && (pvVar1 = peVar4->pvPrivateData, pvVar1 != (void *)0x0)) {
        (*g_engfuncs.pfnMessageBegin)
                  (1,gmsgTeamInfo,(float *)0x0,
                   ((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                    .super_CBaseEntity.pev)->pContainingEntity);
        p_Var2 = g_engfuncs.pfnWriteByte;
        iVar5 = (*g_engfuncs.pfnIndexOfEdict)(*(edict_t **)(*(int *)((int)pvVar1 + 4) + 0x208));
        (*p_Var2)(iVar5);
        p_Var3 = g_engfuncs.pfnWriteString;
        pcVar6 = (char *)(*g_pGameRules->_vptr_CGameRules[0x31])(g_pGameRules,pvVar1);
        (*p_Var3)(pcVar6);
        (*g_engfuncs.pfnMessageEnd)();
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 <= gpGlobals->maxClients);
  }
  return;
}


// CHalfLifeTeamplay::ClientUserInfoChanged  @ 000f6100  (line 109)

/* DWARF original prototype: void ClientUserInfoChanged(CHalfLifeTeamplay * this, CBasePlayer *
   pPlayer, char * infobuffer) */

void __thiscall
CHalfLifeTeamplay::ClientUserInfoChanged
          (CHalfLifeTeamplay *this,CBasePlayer *pPlayer,char *infobuffer)

{
  return;
}


// CHalfLifeTeamplay::DeathNotice  @ 000f65d0  (line 122)

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
  void *pvVar11;
  int in_GS_OFFSET;
  char *local_64;
  char local_3e [30];
  int local_20;
  
                    /* Unresolved local var: char[30] weapon@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((g_pGameRules->_vptr_CGameRules[8] == IsTeamplay) ||
     (iVar5 = (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules), iVar5 != 0)) {
    if (this->m_DisableDeathMessages != 0) goto LAB_000f6694;
                    /* Unresolved local var: CBasePlayer * pk@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    if (((((pVictim != (CBasePlayer *)0x0) && (pKiller != (entvars_t *)0x0)) &&
         ((pKiller->flags & 8) != 0)) &&
        ((peVar9 = pKiller->pContainingEntity, peVar9 != (edict_t *)0x0 ||
         (peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar9 != (edict_t *)0x0)))) &&
       ((this_00 = peVar9->pvPrivateData, this_00 != (CBasePlayer *)0x0 &&
        ((pVictim != this_00 &&
         (iVar5 = (*(this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules[0x32])
                            (this,pVictim,this_00), iVar5 == 1)))))) {
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
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
      GetWeapon(pevInflictor,pKiller,local_3e);
      peVar9 = pKiller->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((peVar9 == (edict_t *)0x0) &&
         (peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar9 == (edict_t *)0x0)) {
        pvVar11 = (void *)0x0;
      }
      else {
        pvVar11 = peVar9->pvPrivateData;
      }
      iVar5 = (pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no;
      local_64 = "SPECTATOR";
      if (iVar5 != 0) {
        local_64 = GetTeamName(iVar5);
      }
      pcVar6 = (*g_engfuncs.pfnGetPlayerAuthId)
                         (((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      iVar5 = (*g_engfuncs.pfnGetPlayerUserId)
                        (((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      pcVar2 = gpGlobals->pStringBase;
      sVar3 = ((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.pev)->netname;
      pcVar10 = "SPECTATOR";
      if (*(int *)((int)pvVar11 + 0x138) != 0) {
        pcVar10 = GetTeamName(*(int *)((int)pvVar11 + 0x138));
      }
      pcVar7 = (*g_engfuncs.pfnGetPlayerAuthId)(pKiller->pContainingEntity);
      iVar8 = (*g_engfuncs.pfnGetPlayerUserId)(pKiller->pContainingEntity);
      UTIL_LogPrintf("\"%s<%i><%s><%s>\" killed \"%s<%i><%s><%s>\" with \"%s\"\n",
                     gpGlobals->pStringBase + pKiller->netname,iVar8,pcVar7,pcVar10,pcVar2 + sVar3,
                     iVar5,pcVar6,local_64,local_3e);
      if ((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.undercover_team == 0) {
        piVar1 = &(this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.teamkills;
        *piVar1 = *piVar1 + 1;
        CBasePlayer::CheckAutoKick(this_00);
      }
      goto LAB_000f6694;
    }
  }
  CHalfLifeMultiplay::DeathNotice(&this->super_CHalfLifeMultiplay,pVictim,pKiller,pevInflictor);
LAB_000f6694:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CHalfLifeTeamplay::PlayerKilled  @ 000f6920  (line 181)

/* DWARF original prototype: void PlayerKilled(CHalfLifeTeamplay * this, CBasePlayer * pVictim,
   entvars_t * pKiller, entvars_t * pInflictor) */

void __thiscall
CHalfLifeTeamplay::PlayerKilled
          (CHalfLifeTeamplay *this,CBasePlayer *pVictim,entvars_t *pKiller,entvars_t *pInflictor)

{
  int iVar1;
  
  if (g_pGameRules->_vptr_CGameRules[8] != IsTeamplay) {
    iVar1 = (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
    if (iVar1 == 0) goto LAB_000f6979;
  }
  if (this->m_DisableDeathPenalty != 0) {
    return;
  }
LAB_000f6979:
  CHalfLifeMultiplay::PlayerKilled(&this->super_CHalfLifeMultiplay,pVictim,pKiller,pInflictor);
  return;
}


// CHalfLifeTeamplay::IsTeamplay  @ 000f6110  (line 199)

/* DWARF original prototype: BOOL IsTeamplay(CHalfLifeTeamplay * this) */

BOOL __thiscall CHalfLifeTeamplay::IsTeamplay(CHalfLifeTeamplay *this)

{
  return 1;
}


// CHalfLifeTeamplay::FPlayerCanTakeDamage  @ 000f6bd0  (line 202)

/* DWARF original prototype: BOOL FPlayerCanTakeDamage(CHalfLifeTeamplay * this, CBasePlayer *
   pPlayer, CBaseEntity * pAttacker) */

BOOL __thiscall
CHalfLifeTeamplay::FPlayerCanTakeDamage
          (CHalfLifeTeamplay *this,CBasePlayer *pPlayer,CBaseEntity *pAttacker)

{
  _func_int_varargs *p_Var1;
  BOOL BVar2;
  int iVar3;
  longdouble extraout_ST0;
  CHalfLifeTeamplay *in_stack_ffffffe4;
  CBasePlayer *in_stack_ffffffe8;
  CBaseEntity *in_stack_ffffffec;
  
  if (((g_pGameRules->_vptr_CGameRules[8] == IsTeamplay) ||
      (in_stack_ffffffe4 = (CHalfLifeTeamplay *)g_pGameRules,
      iVar3 = (*g_pGameRules->_vptr_CGameRules[8])(), iVar3 != 0)) &&
     (pAttacker != (CBaseEntity *)0x0)) {
    p_Var1 = (this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules[0x32];
    if (p_Var1 == PlayerRelationship) {
      if ((g_pGameRules->_vptr_CGameRules[8] == IsTeamplay) ||
         (in_stack_ffffffe4 = (CHalfLifeTeamplay *)g_pGameRules,
         iVar3 = (*g_pGameRules->_vptr_CGameRules[8])(), iVar3 != 0)) {
        if ((pPlayer == (CBasePlayer *)0x0) || ((pAttacker->pev->flags & 8) == 0))
        goto LAB_000f6c36;
        iVar3 = PlayerRelationship(in_stack_ffffffe4,in_stack_ffffffe8,in_stack_ffffffec);
      }
      else {
        iVar3 = CHalfLifeMultiplay::PlayerRelationship
                          (&this->super_CHalfLifeMultiplay,pPlayer,pAttacker);
      }
    }
    else {
      iVar3 = (*p_Var1)(this,pPlayer,pAttacker);
    }
    if (((iVar3 == 1) &&
        ((*g_engfuncs.pfnCVarGetFloat)("mp_friendlyfire"), extraout_ST0 == (longdouble)0)) &&
       (pPlayer != (CBasePlayer *)pAttacker)) {
      return 0;
    }
  }
LAB_000f6c36:
  BVar2 = CHalfLifeMultiplay::CanHaveItem
                    (&this->super_CHalfLifeMultiplay,pPlayer,(CItem *)pAttacker);
  return BVar2;
}


// CHalfLifeTeamplay::PlayerRelationship  @ 000f6160  (line 221)

/* DWARF original prototype: int PlayerRelationship(CHalfLifeTeamplay * this, CBasePlayer * pPlayer,
   CBaseEntity * pTarget) */

int __thiscall
CHalfLifeTeamplay::PlayerRelationship
          (CHalfLifeTeamplay *this,CBasePlayer *pPlayer,CBaseEntity *pTarget)

{
  int *in_EAX;
  BOOL BVar1;
  int iVar2;
  code *pcVar3;
  CBaseEntity *in_ECX;
  CBaseEntity *in_EDX;
  char *__s1;
  char *pcVar4;
  
  if (*(code **)(*in_EAX + 0xc4) == GetTeamID) {
    pcVar4 = "";
    if (g_pGameRules->_vptr_CGameRules[8] != IsTeamplay) {
      (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
    }
  }
  else {
    pcVar4 = (char *)(**(code **)(*in_EAX + 0xc4))();
  }
  if (*pcVar4 == '\0') goto LAB_000f61ad;
  if (*(code **)(*in_EAX + 0xc4) == GetTeamID) {
    pcVar4 = "";
    if (g_pGameRules->_vptr_CGameRules[8] != IsTeamplay) {
      (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
    }
  }
  else {
    pcVar4 = (char *)(**(code **)(*in_EAX + 0xc4))();
  }
  if (*pcVar4 == '\0') goto LAB_000f61ad;
  if (*(code **)(*in_EAX + 0xc4) == GetTeamID) {
    pcVar4 = "";
    if (g_pGameRules->_vptr_CGameRules[8] != IsTeamplay) {
      (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
      pcVar3 = *(code **)(*in_EAX + 0xc4);
      goto LAB_000f62c3;
    }
LAB_000f623a:
    __s1 = "";
    if (g_pGameRules->_vptr_CGameRules[8] != IsTeamplay) {
      (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
    }
  }
  else {
    pcVar4 = (char *)(**(code **)(*in_EAX + 0xc4))();
    pcVar3 = *(code **)(*in_EAX + 0xc4);
LAB_000f62c3:
    if (pcVar3 == GetTeamID) goto LAB_000f623a;
    __s1 = (char *)(*pcVar3)();
  }
  iVar2 = strcasecmp(__s1,pcVar4);
  if (iVar2 == 0) {
    return 1;
  }
LAB_000f61ad:
  BVar1 = CBaseEntity::IsAlly(in_EDX,in_ECX);
  return (uint)(BVar1 != 0);
}


// CHalfLifeTeamplay::PlayerRelationship  @ 000f69b0  (line 222)

/* DWARF original prototype: int PlayerRelationship(CHalfLifeTeamplay * this, CBasePlayer * pPlayer,
   CBaseEntity * pTarget) */

int __thiscall
CHalfLifeTeamplay::PlayerRelationship
          (CHalfLifeTeamplay *this,CBasePlayer *pPlayer,CBaseEntity *pTarget)

{
  BOOL BVar1;
  int iVar2;
  _func_int_varargs *p_Var3;
  char *pcVar4;
  char *__s1;
  
  if ((g_pGameRules->_vptr_CGameRules[8] != IsTeamplay) &&
     (iVar2 = (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules), iVar2 == 0)) {
    iVar2 = CHalfLifeMultiplay::PlayerRelationship(&this->super_CHalfLifeMultiplay,pPlayer,pTarget);
    return iVar2;
  }
  if ((pPlayer == (CBasePlayer *)0x0) || (pTarget == (CBaseEntity *)0x0)) {
    return 0;
  }
  if ((pTarget->pev->flags & 8U) == 0) {
    return 0;
  }
  p_Var3 = (this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules[0x31];
  if (p_Var3 == GetTeamID) {
    pcVar4 = "";
    if (g_pGameRules->_vptr_CGameRules[8] != IsTeamplay) {
      (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
    }
  }
  else {
    pcVar4 = (char *)(*p_Var3)(this,pPlayer);
  }
  if (*pcVar4 == '\0') goto LAB_000f6a84;
  p_Var3 = (this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules[0x31];
  if (p_Var3 == GetTeamID) {
    pcVar4 = "";
    if (g_pGameRules->_vptr_CGameRules[8] != IsTeamplay) {
      (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
    }
  }
  else {
    pcVar4 = (char *)(*p_Var3)(this,pTarget);
  }
  if (*pcVar4 == '\0') goto LAB_000f6a84;
  p_Var3 = (this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules[0x31];
  if (p_Var3 == GetTeamID) {
    pcVar4 = "";
    if (g_pGameRules->_vptr_CGameRules[8] != IsTeamplay) {
      (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
      p_Var3 = (this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules[0x31];
      goto LAB_000f6b8a;
    }
LAB_000f6b02:
    __s1 = "";
    if (g_pGameRules->_vptr_CGameRules[8] != IsTeamplay) {
      (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
    }
  }
  else {
    pcVar4 = (char *)(*p_Var3)(this,pTarget);
    p_Var3 = (this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules[0x31];
LAB_000f6b8a:
    if (p_Var3 == GetTeamID) goto LAB_000f6b02;
    __s1 = (char *)(*p_Var3)(this,pPlayer);
  }
  iVar2 = strcasecmp(__s1,pcVar4);
  if (iVar2 == 0) {
    return 1;
  }
LAB_000f6a84:
  BVar1 = CBaseEntity::IsAlly((CBaseEntity *)pPlayer,pTarget);
  return (uint)(BVar1 != 0);
}


// CHalfLifeTeamplay::ShouldAutoAim  @ 000f6ce0  (line 246)

/* DWARF original prototype: BOOL ShouldAutoAim(CHalfLifeTeamplay * this, CBasePlayer * pPlayer,
   edict_t * target) */

BOOL __thiscall
CHalfLifeTeamplay::ShouldAutoAim(CHalfLifeTeamplay *this,CBasePlayer *pPlayer,edict_t *target)

{
  CBaseEntity *pTarget;
  _func_int_varargs *p_Var1;
  int iVar2;
  uint uVar3;
  CBaseEntity *this_00;
  CBasePlayer *in_stack_ffffffe8;
  CBaseEntity *in_stack_ffffffec;
  
                    /* Unresolved local var: CBaseEntity * pTgt@[???] */
                    /* Unresolved local var: CBaseEntity * pTgt@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((((g_pGameRules->_vptr_CGameRules[8] == IsTeamplay) ||
       (iVar2 = (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules), iVar2 != 0)) &&
      ((target != (edict_t *)0x0 ||
       (target = (*g_engfuncs.pfnPEntityOfEntOffset)(0), target != (edict_t *)0x0)))) &&
     ((pTarget = target->pvPrivateData, pTarget != (CBaseEntity *)0x0 &&
      (this_00 = pTarget, iVar2 = (*pTarget->_vptr_CBaseEntity[10])(), iVar2 == 2)))) {
                    /* Unresolved local var: CBasePlayer * pTarget@[???] */
    p_Var1 = (this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules[0x32];
    if (p_Var1 == PlayerRelationship) {
      if ((g_pGameRules->_vptr_CGameRules[8] == IsTeamplay) ||
         (this_00 = (CBaseEntity *)g_pGameRules, iVar2 = (*g_pGameRules->_vptr_CGameRules[8])(),
         iVar2 != 0)) {
        if ((pPlayer == (CBasePlayer *)0x0) || ((pTarget->pev->flags & 8) == 0)) goto LAB_000f6d16;
        iVar2 = PlayerRelationship((CHalfLifeTeamplay *)this_00,in_stack_ffffffe8,in_stack_ffffffec)
        ;
      }
      else {
        iVar2 = CHalfLifeMultiplay::PlayerRelationship
                          (&this->super_CHalfLifeMultiplay,pPlayer,pTarget);
      }
    }
    else {
      iVar2 = (*p_Var1)(this,pPlayer,pTarget);
    }
    uVar3 = (uint)(iVar2 != 1);
  }
  else {
LAB_000f6d16:
    uVar3 = 1;
  }
  return uVar3;
}


// CHalfLifeTeamplay::IPointsForKill  @ 000f6df0  (line 265)

/* DWARF original prototype: int IPointsForKill(CHalfLifeTeamplay * this, CBasePlayer * pAttacker,
   CBasePlayer * pKilled) */

int __thiscall
CHalfLifeTeamplay::IPointsForKill
          (CHalfLifeTeamplay *this,CBasePlayer *pAttacker,CBasePlayer *pKilled)

{
  _func_int_varargs *p_Var1;
  BOOL BVar2;
  int iVar3;
  CHalfLifeTeamplay *in_stack_ffffffe4;
  CBasePlayer *in_stack_ffffffe8;
  CBaseEntity *in_stack_ffffffec;
  
  if ((g_pGameRules->_vptr_CGameRules[8] != IsTeamplay) &&
     (in_stack_ffffffe4 = (CHalfLifeTeamplay *)g_pGameRules,
     iVar3 = (*g_pGameRules->_vptr_CGameRules[8])(), iVar3 == 0)) {
    BVar2 = CHalfLifeMultiplay::CanHaveItem
                      (&this->super_CHalfLifeMultiplay,pAttacker,(CItem *)pKilled);
    return BVar2;
  }
  if (pKilled == (CBasePlayer *)0x0) {
    return 0;
  }
  if ((pAttacker != (CBasePlayer *)0x0) && (pAttacker != pKilled)) {
    p_Var1 = (this->super_CHalfLifeMultiplay).super_CGameRules._vptr_CGameRules[0x32];
    if (p_Var1 == PlayerRelationship) {
      if ((g_pGameRules->_vptr_CGameRules[8] == IsTeamplay) ||
         (in_stack_ffffffe4 = (CHalfLifeTeamplay *)g_pGameRules,
         iVar3 = (*g_pGameRules->_vptr_CGameRules[8])(), iVar3 != 0)) {
        if ((((pKilled->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->flags & 8) == 0) {
          return 1;
        }
        iVar3 = PlayerRelationship(in_stack_ffffffe4,in_stack_ffffffe8,in_stack_ffffffec);
      }
      else {
        iVar3 = CHalfLifeMultiplay::PlayerRelationship
                          (&this->super_CHalfLifeMultiplay,pAttacker,(CBaseEntity *)pKilled);
      }
    }
    else {
      iVar3 = (*p_Var1)(this,pAttacker,pKilled);
    }
    if (iVar3 == 1) {
      return -1;
    }
  }
  return 1;
}


// CHalfLifeTeamplay::GetTeamID  @ 000f6120  (line 284)

/* DWARF original prototype: char * GetTeamID(CHalfLifeTeamplay * this, CBaseEntity * pEntity) */

char * __thiscall CHalfLifeTeamplay::GetTeamID(CHalfLifeTeamplay *this,CBaseEntity *pEntity)

{
  if (g_pGameRules->_vptr_CGameRules[8] == IsTeamplay) {
    return "";
  }
  (*g_pGameRules->_vptr_CGameRules[8])(g_pGameRules);
  return "";
}


