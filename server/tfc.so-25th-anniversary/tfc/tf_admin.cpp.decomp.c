// Ghidra decompilation of functions from tfc/tf_admin.cpp
// 11 functions, ordered by original source line

// CBasePlayer::AdminAccess  @ 000f6f30  (line 20)

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


// CBasePlayer::Admin_CountPlayers  @ 000f7030  (line 46)

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


// CBasePlayer::Admin_ListIPs  @ 000f7280  (line 64)

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


// CBasePlayer::Admin_CycleDeal  @ 000f7390  (line 88)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Admin_CycleDeal(CBasePlayer * this) */

void __thiscall CBasePlayer::Admin_CycleDeal(CBasePlayer *this)

{
  EHANDLE *this_00;
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  CBasePlayer *pCVar5;
  CBaseEntity *pCVar6;
  
                    /* Unresolved local var: int iStart@[???] */
  iVar3 = TeamFortress_GetNoPlayers();
  if (iVar3 < 2) {
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
  iVar3 = 0;
  iVar4 = EHANDLE::operator_int(this_00);
  if (iVar4 != 0) {
    pCVar6 = EHANDLE::operator->(this_00);
    iVar3 = (*g_engfuncs.pfnIndexOfEdict)(pCVar6->pev->pContainingEntity);
    iVar3 = iVar3 + 1;
  }
                    /* Unresolved local var: int i@[???] */
  if (iVar3 <= gpGlobals->maxClients) {
    do {
      pCVar5 = UTIL_PlayerByIndex(iVar3);
      EHANDLE::operator=(this_00,(CBaseEntity *)pCVar5);
      iVar4 = EHANDLE::operator_int(this_00);
      if ((iVar4 != 0) &&
         (pCVar5 = (CBasePlayer *)EHANDLE::operator_cast_to_CBaseEntity_(this_00), pCVar5 != this))
      {
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.admin_mode = 1;
        pcVar1 = gpGlobals->pStringBase;
        pCVar6 = EHANDLE::operator->(this_00);
        iVar3 = pCVar6->ip;
        pcVar2 = gpGlobals->pStringBase;
        pCVar6 = EHANDLE::operator->(this_00);
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,1,"#Admin_kickban",
                    pcVar2 + pCVar6->pev->netname,pcVar1 + iVar3,(char *)0x0,(char *)0x0);
        return;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= gpGlobals->maxClients);
  }
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.admin_mode = 0;
  ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,1,"#Admin_endlist",(char *)0x0,(char *)0x0,(char *)0x0,
              (char *)0x0);
  return;
}


// CBasePlayer::Admin_DoKick  @ 000f7570  (line 127)

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
  char *pcVar12;
  
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.admin_use;
  iVar5 = EHANDLE::operator_int(this_00);
  if (iVar5 != 0) {
    pcVar10 = gpGlobals->pStringBase;
    sVar1 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->netname;
    pCVar6 = EHANDLE::operator->(this_00);
    pcVar12 = "SPECTATOR";
    UTIL_ClientPrintAll(1,"#Admin_kick",pcVar10 + pCVar6->pev->netname,pcVar10 + sVar1,(char *)0x0,
                        (char *)0x0);
    pCVar6 = EHANDLE::operator->(this_00);
    if (pCVar6->team_no != 0) {
      pCVar6 = EHANDLE::operator->(this_00);
      pcVar12 = GetTeamName(pCVar6->team_no);
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
                   pcVar10 + sVar1,iVar8,pcVar7,pcVar12);
    pCVar6 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
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


// CBasePlayer::Admin_DoBan  @ 000f7a10  (line 152)

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
  char *pcVar11;
  
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.admin_use;
  iVar5 = EHANDLE::operator_int(this_00);
  if (iVar5 != 0) {
    pcVar1 = gpGlobals->pStringBase;
    sVar2 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->netname;
    pCVar6 = EHANDLE::operator->(this_00);
    pcVar11 = "SPECTATOR";
    UTIL_ClientPrintAll(1,"#Admin_ban",pcVar1 + pCVar6->pev->netname,pcVar1 + sVar2,(char *)0x0,
                        (char *)0x0);
    pCVar6 = EHANDLE::operator->(this_00);
    if (pCVar6->team_no != 0) {
      pCVar6 = EHANDLE::operator->(this_00);
      pcVar11 = GetTeamName(pCVar6->team_no);
    }
    p_Var4 = g_engfuncs.pfnGetPlayerAuthId;
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
    pcVar10 = "SPECTATOR";
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
                   pcVar1 + sVar2,iVar8,pcVar7,pcVar11);
    pCVar6 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
    BanPlayer(pCVar6);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.admin_mode = 0;
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  }
  return;
}


// Admin_CeaseFire  @ 000f77b0  (line 177)

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
                    /* Unresolved local var: int i@[???] */
    iVar4 = 1;
    UTIL_ClientPrintAll(1,"#Admin_ceasefire",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    if (0 < gpGlobals->maxClients) {
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


// CBasePlayer::CheckAutoKick  @ 000f7c20  (line 223)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CheckAutoKick(CBasePlayer * this) */

void __thiscall CBasePlayer::CheckAutoKick(CBasePlayer *this)

{
  edict_t *peVar1;
  edict_t *peVar2;
  float fVar3;
  _2globalvars_t *p1Var4;
  CBaseEntity *pCVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  
  fVar3 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.teamkills;
  if ((autokick_kills != 0.0) && (autokick_kills <= fVar3)) {
    pcVar8 = "SPECTATOR";
    UTIL_ClientPrintAll(1,"#AKick_kicked",
                        gpGlobals->pStringBase +
                        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->netname,(char *)0x0,(char *)0x0,
                        (char *)0x0);
    iVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
    if (iVar7 != 0) {
      pcVar8 = GetTeamName(iVar7);
    }
    pcVar6 = (*g_engfuncs.pfnGetPlayerAuthId)
                       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar7 = (*g_engfuncs.pfnGetPlayerUserId)
                      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    UTIL_LogPrintf("\"<-1><><>\" triggered \"Auto_Kick_For_TK\" against \"%s<%i><%s><%s>\"\n",
                   gpGlobals->pStringBase +
                   ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar7,pcVar6,pcVar8);
    BanPlayer((CBaseEntity *)this);
    return;
  }
  if (autokick_kills != 0.0) {
                    /* Unresolved local var: BOOL bFoundOne@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    if (fVar3 == autokick_kills - 1.0) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,4,"#AKick_warn",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#AKick_warn",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
    }
    pCVar5 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"ak_timer");
    if (pCVar5 != (CBaseEntity *)0x0) {
      do {
        peVar1 = pCVar5->pev->owner;
        peVar2 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity;
        pCVar5 = UTIL_FindEntityByClassname(pCVar5,"ak_timer");
        if (pCVar5 == (CBaseEntity *)0x0) break;
      } while (peVar1 != peVar2);
      if (peVar1 == peVar2) {
        return;
      }
    }
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
    pCVar5 = CBaseEntity::CreateTimer((CBaseEntity *)this,0);
    pCVar5->pev->classname = (int)"ak_timer" - (int)gpGlobals->pStringBase;
    p1Var4 = gpGlobals;
    (pCVar5->m_pfnThink).__pfn = CBaseEntity::Timer_AutokickThink;
    (pCVar5->m_pfnThink).__delta = 0;
    pCVar5->pev->nextthink = p1Var4->time + tfc_autokick_time.value;
  }
  return;
}


// KickPlayer  @ 000f7910  (line 272)

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
                    /* WARNING: Could not recover jumptable at 0x000f794f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(pcVar2);
    return;
  }
  return;
}


// BanPlayer  @ 000f7960  (line 286)

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
                    /* WARNING: Could not recover jumptable at 0x000f79fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(pcVar1);
    return;
  }
  return;
}


// CBasePlayer::Admin_Changelevel  @ 000f7e80  (line 298)

/* DWARF original prototype: void Admin_Changelevel(CBasePlayer * this) */

void __thiscall CBasePlayer::Admin_Changelevel(CBasePlayer *this)

{
  int iVar1;
  char *pcVar2;
  int in_GS_OFFSET;
  char local_110 [256];
  int local_10;
  
                    /* Unresolved local var: char[256] sz@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = (*g_engfuncs.pfnCmd_Argc)();
  if (iVar1 == 2) {
    pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
    __sprintf_chk(local_110,1,0x100,"changelevel %s\n",pcVar2);
    (*g_engfuncs.pfnServerCommand)(local_110);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


