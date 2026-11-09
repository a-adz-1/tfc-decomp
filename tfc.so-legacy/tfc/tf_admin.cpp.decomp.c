// Ghidra decompilation of functions from tfc/tf_admin.cpp
// 11 functions, ordered by original source line

// CBasePlayer::AdminAccess  @ 0012ac40  (line 20)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void AdminAccess(CBasePlayer * this, char * pPassword) */

void __thiscall CBasePlayer::AdminAccess(CBasePlayer *this,char *pPassword)

{
  int iVar1;
  
                    /* Unresolved local var: char * pServerPassword@[???] */
  if ((pPassword != (char *)0x0) && (*pPassword != '\0')) {
    if ((tfc_adminpwd.string == (char *)0x0) || (*tfc_adminpwd.string == '\0')) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Admin_nopassword",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      return;
    }
    iVar1 = strcmp(tfc_adminpwd.string,pPassword);
    if (iVar1 == 0) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_admin = 1;
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Admin_access",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      return;
    }
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Admin_badpassword",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
  }
  return;
}


// CBasePlayer::Admin_CountPlayers  @ 0012ad40  (line 46)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Admin_CountPlayers(CBasePlayer * this) */

void __thiscall CBasePlayer::Admin_CountPlayers(CBasePlayer *this)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
                    /* Unresolved local var: int iNumPlayers@[???] */
  iVar1 = TeamFortress_GetNoPlayers();
  pcVar2 = UTIL_dtos1(iVar1);
  ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,1,"#Admin_noplayers",pcVar2,(char *)0x0,(char *)0x0,(char *)0x0)
  ;
                    /* Unresolved local var: int i@[???] */
  if (0.0 < number_of_teams) {
    iVar1 = TeamFortress_TeamGetNoPlayers(1);
    pcVar2 = UTIL_dtos2(iVar1);
    pcVar3 = UTIL_dtos1(1);
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Admin_noteamplayers",pcVar3,pcVar2,(char *)0x0,(char *)0x0
               );
  }
  if (1.0 < number_of_teams) {
    iVar1 = TeamFortress_TeamGetNoPlayers(2);
    pcVar2 = UTIL_dtos2(iVar1);
    pcVar3 = UTIL_dtos1(2);
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Admin_noteamplayers",pcVar3,pcVar2,(char *)0x0,(char *)0x0
               );
  }
  if (2.0 < number_of_teams) {
    iVar1 = TeamFortress_TeamGetNoPlayers(3);
    pcVar2 = UTIL_dtos2(iVar1);
    pcVar3 = UTIL_dtos1(3);
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Admin_noteamplayers",pcVar3,pcVar2,(char *)0x0,(char *)0x0
               );
  }
  if (number_of_teams <= 3.0) {
    return;
  }
  iVar1 = TeamFortress_TeamGetNoPlayers(4);
  pcVar2 = UTIL_dtos2(iVar1);
  pcVar3 = UTIL_dtos1(4);
  ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,1,"#Admin_noteamplayers",pcVar3,pcVar2,(char *)0x0,(char *)0x0);
  return;
}


// CBasePlayer::Admin_ListIPs  @ 0012af90  (line 64)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Admin_ListIPs(CBasePlayer * this) */

void __thiscall CBasePlayer::Admin_ListIPs(CBasePlayer *this)

{
  int iVar1;
  CBasePlayer *pCVar2;
  
  iVar1 = TeamFortress_GetNoPlayers();
  if (iVar1 < 2) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Admin_gameempty",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
  }
  else {
                    /* Unresolved local var: int i@[???] */
    iVar1 = 1;
    if (0 < gpGlobals->maxClients) {
      do {
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
        pCVar2 = UTIL_PlayerByIndex(iVar1);
        if (pCVar2 != (CBasePlayer *)0x0) {
          ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,1,"#Admin_listip",
                      gpGlobals->pStringBase +
                      ((pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->netname,
                      gpGlobals->pStringBase +
                      (pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.ip,(char *)0x0,(char *)0x0);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 <= gpGlobals->maxClients);
    }
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Admin_endlist",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
  }
  return;
}


// CBasePlayer::Admin_CycleDeal  @ 0012b0a0  (line 88)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Admin_CycleDeal(CBasePlayer * this) */

void __thiscall CBasePlayer::Admin_CycleDeal(CBasePlayer *this)

{
  EHANDLE *this_00;
  char *pcVar1;
  char *pcVar2;
  globalvars_t *pgVar3;
  int iVar4;
  int iVar5;
  CBasePlayer *pCVar6;
  CBaseEntity *pCVar7;
  
                    /* Unresolved local var: int iStart@[???] */
  iVar4 = TeamFortress_GetNoPlayers();
  if (iVar4 < 2) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Admin_gameempty",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
    EHANDLE::operator=(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.admin_use,(CBaseEntity *)0x0);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.admin_mode = 0;
    return;
  }
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.admin_use;
  iVar4 = 0;
  iVar5 = EHANDLE::operator_int(this_00);
  if (iVar5 != 0) {
    pCVar7 = EHANDLE::operator->(this_00);
    iVar4 = (*g_engfuncs.pfnIndexOfEdict)(pCVar7->pev->pContainingEntity);
    iVar4 = iVar4 + 1;
  }
                    /* Unresolved local var: int i@[???] */
  if (iVar4 <= gpGlobals->maxClients) {
    do {
      pCVar6 = UTIL_PlayerByIndex(iVar4);
      EHANDLE::operator=(this_00,(CBaseEntity *)pCVar6);
      iVar5 = EHANDLE::operator_int(this_00);
      if (iVar5 != 0) {
        pCVar6 = (CBasePlayer *)EHANDLE::operator_CBaseEntity_(this_00);
        pgVar3 = gpGlobals;
        if (pCVar6 != this) {
          (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.admin_mode = 1;
          pcVar1 = pgVar3->pStringBase;
          pCVar7 = EHANDLE::operator->(this_00);
          iVar4 = pCVar7->ip;
          pcVar2 = gpGlobals->pStringBase;
          pCVar7 = EHANDLE::operator->(this_00);
          ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,1,"#Admin_kickban",
                      pcVar2 + pCVar7->pev->netname,pcVar1 + iVar4,(char *)0x0,(char *)0x0);
          return;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= gpGlobals->maxClients);
  }
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.admin_mode = 0;
  ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,1,"#Admin_endlist",(char *)0x0,(char *)0x0,(char *)0x0,
              (char *)0x0);
  return;
}


// CBasePlayer::Admin_DoKick  @ 0012b270  (line 127)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Admin_DoKick(CBasePlayer * this) */

void __thiscall CBasePlayer::Admin_DoKick(CBasePlayer *this)

{
  EHANDLE *this_00;
  string_t sVar1;
  _func_void_char_ptr *p_Var2;
  _func_int_edict_t_ptr *p_Var3;
  _func_char_ptr_edict_t_ptr *p_Var4;
  int iVar5;
  CBaseEntity *pCVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *local_28;
  
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.admin_use;
  iVar5 = EHANDLE::operator_int(this_00);
  if (iVar5 != 0) {
    pcVar10 = gpGlobals->pStringBase;
    sVar1 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->netname;
    pCVar6 = EHANDLE::operator->(this_00);
    UTIL_ClientPrintAll(1,"#Admin_kick",pcVar10 + pCVar6->pev->netname,pcVar10 + sVar1,(char *)0x0,
                        (char *)0x0);
    pCVar6 = EHANDLE::operator->(this_00);
    local_28 = "SPECTATOR";
    if (pCVar6->team_no != 0) {
      pCVar6 = EHANDLE::operator->(this_00);
      local_28 = GetTeamName(pCVar6->team_no);
    }
    p_Var4 = g_engfuncs.pfnGetPlayerAuthId;
    pCVar6 = EHANDLE::operator->(this_00);
    pcVar7 = (*p_Var4)(pCVar6->pev->pContainingEntity);
    p_Var3 = g_engfuncs.pfnGetPlayerUserId;
    pCVar6 = EHANDLE::operator->(this_00);
    iVar8 = (*p_Var3)(pCVar6->pev->pContainingEntity);
    pcVar10 = gpGlobals->pStringBase;
    pCVar6 = EHANDLE::operator->(this_00);
    sVar1 = pCVar6->pev->netname;
    iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
    pcVar11 = "SPECTATOR";
    if (iVar5 != 0) {
      pcVar11 = GetTeamName(iVar5);
    }
    pcVar9 = (*g_engfuncs.pfnGetPlayerAuthId)
                       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar5 = (*g_engfuncs.pfnGetPlayerUserId)
                      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Admin_Kick\" against \"%s<%i><%s><%s>\"\n",
                   gpGlobals->pStringBase +
                   ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar5,pcVar9,pcVar11,
                   pcVar10 + sVar1,iVar8,pcVar7,local_28);
    pCVar6 = EHANDLE::operator_CBaseEntity_(this_00);
                    /* Unresolved local var: int iUserID@[???] */
    iVar5 = (*g_engfuncs.pfnGetPlayerUserId)(pCVar6->pev->pContainingEntity);
    p_Var2 = g_engfuncs.pfnServerCommand;
    if (iVar5 != -1) {
      pcVar10 = UTIL_VarArgs("kick # %d\n",iVar5);
      (*p_Var2)(pcVar10);
    }
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.admin_mode = 0;
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  }
  return;
}


// CBasePlayer::Admin_DoBan  @ 0012b980  (line 152)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Admin_DoBan(CBasePlayer * this) */

void __thiscall CBasePlayer::Admin_DoBan(CBasePlayer *this)

{
  EHANDLE *this_00;
  char *pcVar1;
  string_t sVar2;
  _func_int_edict_t_ptr *p_Var3;
  _func_char_ptr_edict_t_ptr *p_Var4;
  int iVar5;
  CBaseEntity *pCVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  char *local_28;
  
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.admin_use;
  iVar5 = EHANDLE::operator_int(this_00);
  if (iVar5 != 0) {
    pcVar1 = gpGlobals->pStringBase;
    sVar2 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->netname;
    pCVar6 = EHANDLE::operator->(this_00);
    UTIL_ClientPrintAll(1,"#Admin_ban",pcVar1 + pCVar6->pev->netname,pcVar1 + sVar2,(char *)0x0,
                        (char *)0x0);
    pCVar6 = EHANDLE::operator->(this_00);
    local_28 = "SPECTATOR";
    if (pCVar6->team_no != 0) {
      pCVar6 = EHANDLE::operator->(this_00);
      local_28 = GetTeamName(pCVar6->team_no);
    }
    p_Var4 = g_engfuncs.pfnGetPlayerAuthId;
    pcVar10 = "SPECTATOR";
    pCVar6 = EHANDLE::operator->(this_00);
    pcVar7 = (*p_Var4)(pCVar6->pev->pContainingEntity);
    p_Var3 = g_engfuncs.pfnGetPlayerUserId;
    pCVar6 = EHANDLE::operator->(this_00);
    iVar8 = (*p_Var3)(pCVar6->pev->pContainingEntity);
    pcVar1 = gpGlobals->pStringBase;
    pCVar6 = EHANDLE::operator->(this_00);
    sVar2 = pCVar6->pev->netname;
    iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
    if (iVar5 != 0) {
      pcVar10 = GetTeamName(iVar5);
    }
    pcVar9 = (*g_engfuncs.pfnGetPlayerAuthId)
                       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar5 = (*g_engfuncs.pfnGetPlayerUserId)
                      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Admin_Ban\" against \"%s<%i><%s><%s>\"\n",
                   gpGlobals->pStringBase +
                   ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar5,pcVar9,pcVar10,
                   pcVar1 + sVar2,iVar8,pcVar7,local_28);
    pCVar6 = EHANDLE::operator_CBaseEntity_(this_00);
    BanPlayer(pCVar6);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.admin_mode = 0;
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  }
  return;
}


// Admin_CeaseFire  @ 0012b4a0  (line 177)

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Admin_CeaseFire(void)

{
  int *piVar1;
  float fVar2;
  CBasePlayer *pCVar3;
  int iVar4;
  
  if (cease_fire == 0) {
    cease_fire = 1;
    UTIL_ClientPrintAll(1,"#Admin_ceasefire",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
                    /* Unresolved local var: int i@[???] */
    if (0 < gpGlobals->maxClients) {
      iVar4 = 1;
      do {
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
        pCVar3 = UTIL_PlayerByIndex(iVar4);
        if (pCVar3 != (CBasePlayer *)0x0) {
          ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->iuser4 = 1;
          fVar2 = gpGlobals->time;
          piVar1 = &(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.tfstate;
          *piVar1 = *piVar1 | 0x10000;
          (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.immune_to_check = fVar2 + 10.0;
          CBasePlayer::TeamFortress_SetSpeed(pCVar3);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 <= gpGlobals->maxClients);
    }
  }
  else {
    cease_fire = 0;
    UTIL_ClientPrintAll(1,"#Game_resumefire",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    UTIL_LogPrintf("World triggered \"Resume_Fire\"\n");
                    /* Unresolved local var: int i@[???] */
    if (0 < gpGlobals->maxClients) {
      iVar4 = 1;
      do {
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
        pCVar3 = UTIL_PlayerByIndex(iVar4);
        if (pCVar3 != (CBasePlayer *)0x0) {
          ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->iuser4 = 0;
          fVar2 = gpGlobals->time;
          piVar1 = &(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.tfstate;
          *piVar1 = *piVar1 & 0xfffeffff;
          (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.immune_to_check = fVar2 + 10.0;
          CBasePlayer::TeamFortress_SetSpeed(pCVar3);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 <= gpGlobals->maxClients);
      return;
    }
  }
  return;
}


// CBasePlayer::CheckAutoKick  @ 0012b700  (line 223)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CheckAutoKick(CBasePlayer * this) */

void __thiscall CBasePlayer::CheckAutoKick(CBasePlayer *this)

{
  float fVar1;
  globalvars_t *pgVar2;
  CBaseEntity *pCVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  bool bVar7;
  
  fVar1 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.teamkills;
  if ((autokick_kills <= fVar1) && (autokick_kills != 0.0)) {
    pcVar6 = "SPECTATOR";
    UTIL_ClientPrintAll(1,"#AKick_kicked",
                        gpGlobals->pStringBase +
                        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->netname,(char *)0x0,(char *)0x0,
                        (char *)0x0);
    iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
    if (iVar5 != 0) {
      pcVar6 = GetTeamName(iVar5);
    }
    pcVar4 = (*g_engfuncs.pfnGetPlayerAuthId)
                       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar5 = (*g_engfuncs.pfnGetPlayerUserId)
                      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    UTIL_LogPrintf("\"<-1><><>\" triggered \"Auto_Kick_For_TK\" against \"%s<%i><%s><%s>\"\n",
                   gpGlobals->pStringBase +
                   ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar5,pcVar4,pcVar6);
    BanPlayer((CBaseEntity *)this);
    return;
  }
  if (autokick_kills == 0.0) {
    return;
  }
                    /* Unresolved local var: BOOL bFoundOne@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  if (fVar1 == autokick_kills - 1.0) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,4,"#AKick_warn",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#AKick_warn",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
  }
  pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"ak_timer");
  if (pCVar3 != (CBaseEntity *)0x0) {
    do {
      bVar7 = pCVar3->pev->owner ==
              ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->pContainingEntity;
      pCVar3 = UTIL_FindEntityByClassname(pCVar3,"ak_timer");
      if (pCVar3 == (CBaseEntity *)0x0) break;
    } while (!bVar7);
    if (bVar7) {
      return;
    }
  }
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
  pCVar3 = CBaseEntity::CreateTimer((CBaseEntity *)this,0);
  pCVar3->pev->classname = (int)"ak_timer" - (int)gpGlobals->pStringBase;
  pgVar2 = gpGlobals;
  (pCVar3->m_pfnThink).__pfn = CBaseEntity::Timer_AutokickThink;
  (pCVar3->m_pfnThink).__delta = 0;
  pCVar3->pev->nextthink = pgVar2->time + tfc_autokick_time.value;
  return;
}


// KickPlayer  @ 0012b600  (line 272)

void KickPlayer(CBaseEntity *pTarget)

{
  _func_void_char_ptr *UNRECOVERED_JUMPTABLE;
  int iVar1;
  char *pcVar2;
  
                    /* Unresolved local var: int iUserID@[???] */
  iVar1 = (*g_engfuncs.pfnGetPlayerUserId)(pTarget->pev->pContainingEntity);
  UNRECOVERED_JUMPTABLE = g_engfuncs.pfnServerCommand;
  if (iVar1 != -1) {
    pcVar2 = UTIL_VarArgs("kick # %d\n",iVar1);
                    /* WARNING: Could not recover jumptable at 0x0012b63f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(pcVar2);
    return;
  }
  return;
}


// BanPlayer  @ 0012b650  (line 286)

void BanPlayer(CBaseEntity *pTarget)

{
  _func_void_char_ptr *UNRECOVERED_JUMPTABLE;
  char *pcVar1;
  int iVar2;
  
  UNRECOVERED_JUMPTABLE = g_engfuncs.pfnServerCommand;
  pcVar1 = (*g_engfuncs.pfnGetPlayerAuthId)(pTarget->pev->pContainingEntity);
  pcVar1 = UTIL_VarArgs("banid 30 %s kick\n",pcVar1);
  (*UNRECOVERED_JUMPTABLE)(pcVar1);
  UNRECOVERED_JUMPTABLE = g_engfuncs.pfnServerCommand;
  pcVar1 = UTIL_VarArgs("addip 30 %s\n",gpGlobals->pStringBase + pTarget->ip);
  (*UNRECOVERED_JUMPTABLE)(pcVar1);
                    /* Unresolved local var: int iUserID@[???] */
  iVar2 = (*g_engfuncs.pfnGetPlayerUserId)(pTarget->pev->pContainingEntity);
  UNRECOVERED_JUMPTABLE = g_engfuncs.pfnServerCommand;
  if (iVar2 != -1) {
    pcVar1 = UTIL_VarArgs("kick # %d\n",iVar2);
                    /* WARNING: Could not recover jumptable at 0x0012b6ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(pcVar1);
    return;
  }
  return;
}


// CBasePlayer::Admin_Changelevel  @ 0012bb80  (line 298)

/* DWARF original prototype: void Admin_Changelevel(CBasePlayer * this) */

void __thiscall CBasePlayer::Admin_Changelevel(CBasePlayer *this)

{
  int iVar1;
  char *pcVar2;
  char local_10c [264];
  
                    /* Unresolved local var: char[256] sz@[???] */
  iVar1 = (*g_engfuncs.pfnCmd_Argc)();
  if (iVar1 != 2) {
    return;
  }
  pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
  sprintf(local_10c,"changelevel %s\n",pcVar2);
  (*g_engfuncs.pfnServerCommand)(local_10c);
  return;
}


