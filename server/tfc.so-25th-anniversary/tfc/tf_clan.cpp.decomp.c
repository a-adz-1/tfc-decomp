// Ghidra decompilation of functions from tfc/tf_clan.cpp
// 12 functions, ordered by original source line

// CGhost::~CGhost  @ 000f8f30  (line 26)

/* DWARF original prototype: void ~CGhost(CGhost * this, int __in_chrg) */

void __thiscall CGhost::~CGhost(CGhost *this,int __in_chrg)

{
  return;
}


// ghost  @ 000f8010  (line 29)

void ghost(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x474,pev);
  *puVar1 = &PTR__CGhost_0015c50c;
  puVar1[1] = pev;
  return;
}


// CBasePlayer::CreateGhost  @ 000f8080  (line 33)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CreateGhost(CBasePlayer * this) */

void __thiscall CBasePlayer::CreateGhost(CBasePlayer *this)

{
  CBaseEntity *pCVar1;
  
                    /* Unresolved local var: CBaseEntity * pGhost@[DW_OP_reg0(EAX)] */
  pCVar1 = CBaseEntity::Create("ghost",&g_vecZero,&g_vecZero,
                               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  pCVar1->tf_id =
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.tf_id;
  pCVar1->team_no =
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.team_no;
  pCVar1->pev->frags =
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->frags;
  pCVar1->real_frags =
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.real_frags;
  pCVar1->pev->netname =
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->netname;
  pCVar1->pev->playerclass =
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->playerclass;
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.tfstate & 8) != 0) {
    pCVar1->tfstate = 8;
  }
  return;
}


// FindGhost  @ 000f8130  (line 48)

CGhost * FindGhost(int iGhostID)

{
  int iVar1;
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: CBaseEntity * pGhost@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"ghost");
  if (pStartEntity == (CBaseEntity *)0x0) {
LAB_000f817d:
    pStartEntity = (CBaseEntity *)0x0;
  }
  else {
    iVar1 = pStartEntity->tf_id;
    while (iGhostID != iVar1) {
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"ghost");
      if (pStartEntity == (CBaseEntity *)0x0) goto LAB_000f817d;
      iVar1 = pStartEntity->tf_id;
    }
  }
  return (CGhost *)pStartEntity;
}


// GetBattleID  @ 000f8190  (line 63)

int GetBattleID(edict_t *pEntity)

{
  char *pcVar1;
  int local_10 [4];
  
                    /* Unresolved local var: int iGhostID@[???]
                       Unresolved local var: char * infobuffer@[???]
                       Unresolved local var: char * st@[???] */
  local_10[0] = 0;
  pcVar1 = (*g_engfuncs.pfnGetInfoKeyBuffer)(pEntity);
  pcVar1 = (*g_engfuncs.pfnInfoKeyValue)(pcVar1,"tf_id");
  if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
    sscanf(pcVar1,"%d",local_10);
  }
  return local_10[0];
}


// CBasePlayer::ConnectDuringBattle  @ 000f81f0  (line 76)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ConnectDuringBattle(CBasePlayer * this) */

void __thiscall CBasePlayer::ConnectDuringBattle(CBasePlayer *this)

{
  int iVar1;
  entvars_t *peVar2;
  CBasePlayer *this_00;
  CBasePlayer *pCVar3;
  CBasePlayer *pStartEntity;
  int local_10;
  
                    /* Unresolved local var: int iBattleID@[???] */
                    /* Unresolved local var: int iGhostID@[???]
                       Unresolved local var: char * infobuffer@[???]
                       Unresolved local var: char * st@[???] */
  local_10 = 0;
  this_00 = (CBasePlayer *)
            (*g_engfuncs.pfnGetInfoKeyBuffer)
                      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  pCVar3 = (CBasePlayer *)(*g_engfuncs.pfnInfoKeyValue)((char *)this_00,"tf_id");
  if ((pCVar3 != (CBasePlayer *)0x0) &&
     (*(char *)&(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity._vptr_CBaseEntity != '\0')) {
    sscanf((char *)pCVar3,"%d",&local_10);
    this_00 = pCVar3;
  }
  iVar1 = local_10;
  if (local_10 != 0) {
                    /* Unresolved local var: CGhost * pGhost@[???]
                       Unresolved local var: CBaseEntity * pGhost@[???] */
    this_00 = (CBasePlayer *)0x0;
    pCVar3 = (CBasePlayer *)UTIL_FindEntityByClassname((CBaseEntity *)0x0,"ghost");
    while (pStartEntity = pCVar3, pStartEntity != (CBasePlayer *)0x0) {
      if (iVar1 == (pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.tf_id) {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,"#Game_welcomeback",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.tf_id = iVar1;
        TeamFortress_TeamSet
                  (this,(pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.team_no);
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->frags =
             ((pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->frags;
        iVar1 = (pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.real_frags;
        peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.real_frags = iVar1;
        peVar2->frags = (float)iVar1;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->playerclass =
             ((pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->playerclass;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.tfstate =
             (pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.tfstate;
        ResetMenu(this);
        UTIL_Remove((CBaseEntity *)pStartEntity);
        return;
      }
      pCVar3 = (CBasePlayer *)UTIL_FindEntityByClassname((CBaseEntity *)pStartEntity,"ghost");
      this_00 = pStartEntity;
    }
  }
                    /* Unresolved local var: char * infobuffer@[???] */
  if (tfc_clanbattle.value != 0.0) {
    CreateBattleID(this_00);
    return;
  }
  return;
}


// CBasePlayer::CreateBattleID  @ 000f7f10  (line 107)

/* DWARF original prototype: void CreateBattleID(CBasePlayer * this) */

void __thiscall CBasePlayer::CreateBattleID(CBasePlayer *this)

{
  longdouble lVar1;
  _func_void_int_char_ptr_char_ptr_char_ptr *p_Var2;
  int in_EAX;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  longdouble lVar6;
  
                    /* Unresolved local var: char * infobuffer@[???] */
  lVar6 = (longdouble)(*g_engfuncs.pfnRandomFloat)(20.0,40.0);
  lVar1 = (longdouble)last_id;
  last_id = (float)(lVar6 + lVar1);
  *(int *)(in_EAX + 0x214) = (int)(lVar6 + lVar1);
  pcVar3 = (*g_engfuncs.pfnGetInfoKeyBuffer)(*(edict_t **)(*(int *)(in_EAX + 4) + 0x208));
  p_Var2 = g_engfuncs.pfnSetClientKeyValue;
  pcVar4 = UTIL_VarArgs("%d",*(undefined4 *)(in_EAX + 0x214));
  iVar5 = (*g_engfuncs.pfnIndexOfEdict)(*(edict_t **)(*(int *)(in_EAX + 4) + 0x208));
  (*p_Var2)(iVar5,pcVar3,"tf_id",pcVar4);
  pcVar3 = UTIL_dtos1(*(int *)(in_EAX + 0x214));
  ClientPrint(*(entvars_t **)(in_EAX + 4),1,"#Game_battleid",pcVar3,(char *)0x0,(char *)0x0,
              (char *)0x0);
  return;
}


// CBasePlayer::CreateBattleID  @ 000f8370  (line 108)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CreateBattleID(CBasePlayer * this) */

void __thiscall CBasePlayer::CreateBattleID(CBasePlayer *this)

{
  longdouble lVar1;
  _func_void_int_char_ptr_char_ptr_char_ptr *p_Var2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  longdouble lVar6;
  
                    /* Unresolved local var: char * infobuffer@[???] */
  if (tfc_clanbattle.value != 0.0) {
                    /* Unresolved local var: char * infobuffer@[???] */
    lVar6 = (longdouble)(*g_engfuncs.pfnRandomFloat)(20.0,40.0);
    lVar1 = (longdouble)last_id;
    last_id = (float)(lVar6 + lVar1);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tf_id = (int)(lVar6 + lVar1);
    pcVar3 = (*g_engfuncs.pfnGetInfoKeyBuffer)
                       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    p_Var2 = g_engfuncs.pfnSetClientKeyValue;
    pcVar4 = UTIL_VarArgs("%d",(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.tf_id);
    iVar5 = (*g_engfuncs.pfnIndexOfEdict)
                      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*p_Var2)(iVar5,pcVar3,"tf_id",pcVar4);
    pcVar3 = UTIL_dtos1((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.tf_id);
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Game_battleid",pcVar3,(char *)0x0,(char *)0x0,(char *)0x0)
    ;
  }
  return;
}


// Display_Prematch  @ 000f8490  (line 126)

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Display_Prematch(void)

{
  entvars_t *peVar1;
  int d;
  _2globalvars_t *p1Var2;
  CBasePlayer *this;
  CBaseEntity *pStartEntity;
  int d_00;
  CBasePlayer *playerIndex;
  float fVar3;
  CBasePlayer *this_00;
  char *msg_name;
  char *pcVar4;
  
                    /* Unresolved local var: int iTimeLeft@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: CBaseEntity * pGrenade@[???] */
  if (g_fNextPrematchAlert <= gpGlobals->time) {
    fVar3 = ceilf(cb_prematch_time - gpGlobals->time);
    d_00 = (int)fVar3;
    d = d_00 / 0x3c;
    if ((d_00 + d * 4 == d * 0x40) && (0x77 < d_00)) {
      pcVar4 = UTIL_dtos1(d);
      UTIL_ClientPrintAll(1,"#Game_minsleft",pcVar4,(char *)0x0,(char *)0x0,(char *)0x0);
      g_fNextPrematchAlert = (float)(d_00 + -0x3c) + gpGlobals->time;
    }
    else if (d_00 == 0x3c) {
      UTIL_ClientPrintAll(1,"#Game_oneminleft",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      g_fNextPrematchAlert = gpGlobals->time + 30.0;
    }
    else if (d_00 == 0x1e) {
      UTIL_ClientPrintAll(1,"#Game_thirtysecleft",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      g_fNextPrematchAlert = gpGlobals->time + 20.0;
    }
    else {
      if (d_00 - 2U < 9) {
        pcVar4 = UTIL_dtos1(d_00);
        msg_name = "#Game_secsleft";
      }
      else {
        if (d_00 != 1) {
          if (1 < d_00) {
            return;
          }
          UTIL_ClientPrintAll(1,"#Game_matchbegin",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
          UTIL_LogPrintf("World triggered \"Match_Begins_Now\"\n");
          if (tfc_clanbattle_locked.value != 0.0) {
            UTIL_ClientPrintAll(1,"#Game_matchlocked",(char *)0x0,(char *)0x0,(char *)0x0,
                                (char *)0x0);
          }
          teamscores[1] = 0;
          teamscores[2] = 0;
          teamfrags[3] = 0;
          teamfrags[4] = 0;
          teamfrags[2] = 0;
          playerIndex = (CBasePlayer *)0x1;
          teamscores[3] = 0;
          teamscores[4] = 0;
          teamfrags[1] = 0;
          cb_prematch_time = 0.0;
          if (0 < gpGlobals->maxClients) {
            do {
              this_00 = playerIndex;
              this = UTIL_PlayerByIndex((int)playerIndex);
              if (this != (CBasePlayer *)0x0) {
                    /* Unresolved local var: char * infobuffer@[???] */
                if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.tf_id == 0) && (tfc_clanbattle.value != 0.0)
                   ) {
                  CBasePlayer::CreateBattleID(this_00);
                }
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
                CBasePlayer::TeamFortress_RemoveTimers(this);
                peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev;
                (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity._vptr_CBaseEntity[0xd])
                          (this,peVar1,peVar1,0x461c4000,0x8001000);
                ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->frags = 0.0;
                (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.real_frags = 0;
                this->m_iDeaths = 0;
              }
              playerIndex = (CBasePlayer *)
                            ((int)&(playerIndex->super_CBaseMonster).super_CBaseToggle.
                                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                   _vptr_CBaseEntity + 1);
            } while ((int)playerIndex <= gpGlobals->maxClients);
          }
          pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"grenade");
          p1Var2 = gpGlobals;
          while (pStartEntity != (CBaseEntity *)0x0) {
            peVar1 = pStartEntity->pev;
            gpGlobals = p1Var2;
            (pStartEntity->m_pfnThink).__pfn = CBaseEntity::SUB_Remove;
            (pStartEntity->m_pfnThink).__delta = 0;
            peVar1->nextthink = p1Var2->time;
            pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"grenade");
            p1Var2 = gpGlobals;
          }
          gpGlobals = p1Var2;
          return;
        }
        pcVar4 = (char *)0x0;
        msg_name = "#Game_onesec";
      }
      UTIL_ClientPrintAll(1,msg_name,pcVar4,(char *)0x0,(char *)0x0,(char *)0x0);
      g_fNextPrematchAlert = gpGlobals->time + 1.0;
    }
  }
  return;
}


// Check_Ceasefire  @ 000f8870  (line 226)

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Check_Ceasefire(void)

{
  int *piVar1;
  float fVar2;
  CBasePlayer *this;
  int playerIndex;
  
  if ((gpGlobals->time <= cb_ceasefire_time) || (initial_cease_fire == 0)) {
    if (cease_fire != 0) {
      last_cease_fire = cease_fire;
      return;
    }
  }
  else if (cease_fire != 0) {
    initial_cease_fire = 0;
    cease_fire = 0;
  }
  if (no_cease_fire_text == 0) {
    UTIL_ClientPrintAll(1,"#Game_resumefire",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  }
                    /* Unresolved local var: int i@[???] */
  playerIndex = 1;
  UTIL_LogPrintf("World triggered \"Resume_Fire\"\n");
  if (0 < gpGlobals->maxClients) {
    do {
                    /* Unresolved local var: CBasePlayer * client@[???] */
      this = UTIL_PlayerByIndex(playerIndex);
      if (this != (CBasePlayer *)0x0) {
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->iuser4 = 0;
        fVar2 = gpGlobals->time;
        piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.tfstate;
        *piVar1 = *piVar1 & 0xfffeffff;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.immune_to_check = fVar2 + 10.0;
        CBasePlayer::TeamFortress_SetSpeed(this);
      }
      playerIndex = playerIndex + 1;
    } while (playerIndex <= gpGlobals->maxClients);
  }
  last_cease_fire = cease_fire;
  return;
}


// DumpClanScores  @ 000f8c50  (line 262)

/* WARNING: Variable defined which should be unmapped: bDraw */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DumpClanScores(void)

{
  int *piVar1;
  BOOL bDraw_00;
  int iVar2;
  CBasePlayer *pCVar3;
  char *pcVar4;
  char *pcVar5;
  char *param1;
  int iVar6;
  int local_4c [7];
  int local_30 [8];
  int bDraw;
  
                    /* Unresolved local var: int[5] iNoPlayers@[???]
                       Unresolved local var: int[5] iUnaccountedFrags@[???]
                       Unresolved local var: int i@[???] */
  iVar6 = 0;
  bDraw_00 = TeamFortress_SortTeams();
  do {
    iVar2 = TeamFortress_TeamGetNoPlayers(iVar6);
    local_4c[iVar6] = 0;
    local_30[iVar6] = iVar2;
    iVar6 = iVar6 + 1;
  } while (iVar6 != 5);
  iVar6 = 1;
  if (0 < gpGlobals->maxClients) {
    do {
                    /* Unresolved local var: CBaseEntity * pPlayer@[???] */
      pCVar3 = UTIL_PlayerByIndex(iVar6);
      if (pCVar3 != (CBasePlayer *)0x0) {
        local_4c[(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no] =
             local_4c[(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.team_no] +
             (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.real_frags;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 <= gpGlobals->maxClients);
  }
  local_4c[0] = teamfrags[0] - local_4c[0];
  local_4c[1] = teamfrags[1] - local_4c[1];
  local_4c[2] = teamfrags[2] - local_4c[2];
  local_4c[3] = teamfrags[3] - local_4c[3];
  local_4c[4] = teamfrags[4] - local_4c[4];
  UTIL_ClientPrintAll(1,"#Match_results",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  LogMatchResults(local_30,local_4c,bDraw_00);
  if (bDraw_00 == 0) {
    pcVar4 = GetTeamName(g_iOrderedTeams[2]);
    pcVar5 = GetTeamName(g_iOrderedTeams[1]);
    UTIL_ClientPrintAll(1,"#Match_winner",pcVar5,pcVar4,(char *)0x0,(char *)0x0);
    if (3.0 < number_of_teams) {
      pcVar4 = GetTeamName(g_iOrderedTeams[3]);
      UTIL_ClientPrintAll(1,"#Match_losers4",pcVar4,(char *)0x0,(char *)0x0,(char *)0x0);
      iVar6 = g_iOrderedTeams[4];
    }
    else {
      iVar6 = g_iOrderedTeams[3];
      if (number_of_teams <= 2.0) goto LAB_000f8d65;
    }
    pcVar4 = GetTeamName(iVar6);
    UTIL_ClientPrintAll(1,"#Match_losers3",pcVar4,(char *)0x0,(char *)0x0,(char *)0x0);
  }
  else {
    UTIL_ClientPrintAll(1,"#Match_draw",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  }
LAB_000f8d65:
  iVar6 = 1;
  if (1.0 <= number_of_teams) {
    do {
      iVar2 = TeamFortress_TeamGetNoPlayers(iVar6);
      pcVar4 = UTIL_dtos2(iVar2);
      pcVar5 = UTIL_dtos1(iVar6);
      UTIL_ClientPrintAll(1,"#Match_team",pcVar5,pcVar4,(char *)0x0,(char *)0x0);
      pcVar4 = UTIL_dtos3(teamscores[iVar6]);
      pcVar5 = UTIL_dtos2(local_4c[iVar6]);
      piVar1 = teamfrags + iVar6;
      iVar6 = iVar6 + 1;
      param1 = UTIL_dtos1(*piVar1);
      UTIL_ClientPrintAll(1,"#Match_teamdump",param1,pcVar5,pcVar4,(char *)0x0);
    } while ((float)iVar6 <= number_of_teams);
  }
  return;
}


// LogMatchResults  @ 000f89b0  (line 332)

void LogMatchResults(int *iNoPlayers,int *iUnaccountedFrags,int bDraw)

{
  float fVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  uint *puVar9;
  uint *puVar10;
  undefined2 *puVar11;
  uint uVar12;
  uint uVar13;
  int tno;
  char *pcVar14;
  int iVar15;
  int in_GS_OFFSET;
  undefined1 local_2b4 [32];
  undefined1 local_294 [128];
  uint local_214 [125];
  int local_20;
  
                    /* Unresolved local var: int i@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (1.0 <= number_of_teams) {
    tno = 1;
                    /* Unresolved local var: char[500] teamResults@[???]
                       Unresolved local var: char[128] tempBuf@[???]
                       Unresolved local var: int allyFound@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: char[32] teamName@[???] */
    do {
      pcVar14 = "players";
      local_294[0] = 0;
      pcVar3 = UTIL_dtos4(iUnaccountedFrags[tno]);
      pcVar4 = UTIL_dtos3(teamfrags[tno]);
      iVar5 = TeamFortress_TeamGetNoPlayers(tno);
      if (iVar5 == 1) {
        pcVar14 = "player";
      }
      iVar5 = TeamFortress_TeamGetNoPlayers(tno);
      pcVar6 = UTIL_dtos2(iVar5);
      pcVar7 = UTIL_dtos1(teamscores[tno]);
      pcVar8 = GetTeamName(tno);
      __sprintf_chk(local_214,1,500,
                    "Team \"%s\" scored \"%s\" with \"%s\" %s (kills \"%s\") (kills_unaccounted \"%s\")"
                    ,pcVar8,pcVar7,pcVar6,pcVar14,pcVar4,pcVar3);
      bVar2 = false;
      iVar5 = 1;
      fVar1 = number_of_teams;
      if (1.0 < number_of_teams) {
        do {
          while ((teamallies[tno] >> ((char)iVar5 - 1U & 0x1f) & 1U) != 0) {
            iVar15 = iVar5 + 1;
            pcVar8 = GetTeamName(iVar5);
            __sprintf_chk(local_2b4,1,0x20,&DAT_0015c417,pcVar8,pcVar7,pcVar6,pcVar14,pcVar4,pcVar3)
            ;
            __strcat_chk(local_294,local_2b4,0x80);
            bVar2 = true;
            iVar5 = iVar15;
            fVar1 = number_of_teams;
            if (number_of_teams <= (float)iVar15) goto LAB_000f8b6a;
          }
          iVar5 = iVar5 + 1;
        } while ((float)iVar5 < fVar1);
LAB_000f8b6a:
        puVar10 = local_214;
        if (bVar2) {
          do {
            puVar9 = puVar10;
            uVar12 = *puVar9 + 0xfefefeff & ~*puVar9;
            uVar13 = uVar12 & 0x80808080;
            puVar10 = puVar9 + 1;
          } while (uVar13 == 0);
          if ((uVar12 & 0x8080) == 0) {
            puVar10 = (uint *)((int)puVar9 + 6);
            uVar13 = uVar13 >> 0x10;
          }
          pcVar3 = (char *)((int)puVar10 + (-3 - (uint)CARRY1((byte)uVar13,(byte)uVar13)));
          builtin_strncpy(pcVar3," (allies \"",0xb);
          puVar11 = (undefined2 *)__stpcpy_chk(pcVar3 + 10,local_294,500);
          *puVar11 = 0x2922;
          *(undefined1 *)(puVar11 + 1) = 0;
        }
      }
      tno = tno + 1;
      __strcat_chk(local_214,"\n",500);
      UTIL_LogPrintf((char *)local_214);
    } while ((float)tno <= number_of_teams);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


