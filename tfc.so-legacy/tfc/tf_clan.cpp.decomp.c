// Ghidra decompilation of functions from tfc/tf_clan.cpp
// 11 functions, ordered by original source line

// ghost  @ 0012bce0  (line 29)

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
  *puVar1 = &PTR__CGhost_0018d528;
  puVar1[1] = pev;
  return;
}


// CBasePlayer::CreateGhost  @ 0012bd50  (line 33)

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


// FindGhost  @ 0012be00  (line 48)

CGhost * FindGhost(int iGhostID)

{
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: CBaseEntity * pGhost@[???] */
  for (pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"ghost");
      (pStartEntity != (CBaseEntity *)0x0 && (pStartEntity->tf_id != iGhostID));
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"ghost")) {
  }
  return (CGhost *)pStartEntity;
}


// GetBattleID  @ 0012be50  (line 63)

int GetBattleID(edict_t *pEntity)

{
  char *pcVar1;
  int local_1c [7];
  
                    /* Unresolved local var: int iGhostID@[???]
                       Unresolved local var: char * infobuffer@[???]
                       Unresolved local var: char * st@[???] */
  local_1c[0] = 0;
  pcVar1 = (*g_engfuncs.pfnGetInfoKeyBuffer)(pEntity);
  pcVar1 = (*g_engfuncs.pfnInfoKeyValue)(pcVar1,"tf_id");
  if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
    sscanf(pcVar1,"%d",local_1c);
  }
  return local_1c[0];
}


// CBasePlayer::ConnectDuringBattle  @ 0012beb0  (line 76)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ConnectDuringBattle(CBasePlayer * this) */

void __thiscall CBasePlayer::ConnectDuringBattle(CBasePlayer *this)

{
  int iVar1;
  entvars_t *peVar2;
  CBasePlayer *this_00;
  CBasePlayer *pCVar3;
  CBasePlayer *pStartEntity;
  int local_1c [4];
  
                    /* Unresolved local var: int iBattleID@[DW_OP_reg6(ESI)]
                       Unresolved local var: int iGhostID@[???]
                       Unresolved local var: char * infobuffer@[???]
                       Unresolved local var: char * st@[???] */
  local_1c[0] = 0;
  this_00 = (CBasePlayer *)
            (*g_engfuncs.pfnGetInfoKeyBuffer)
                      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  pCVar3 = (CBasePlayer *)(*g_engfuncs.pfnInfoKeyValue)((char *)this_00,"tf_id");
  if ((pCVar3 != (CBasePlayer *)0x0) &&
     (*(char *)&(pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity._vptr_CBaseEntity != '\0')) {
    sscanf((char *)pCVar3,"%d",local_1c);
    this_00 = pCVar3;
  }
  iVar1 = local_1c[0];
  if (local_1c[0] != 0) {
                    /* Unresolved local var: CGhost * pGhost@[DW_OP_reg3(EBX)]
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
  }
  return;
}


// CBasePlayer::CreateBattleID  @ 0012bbe0  (line 107)

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


// CBasePlayer::CreateBattleID  @ 0012c020  (line 109)

/* DWARF original prototype: void CreateBattleID(CBasePlayer * this) */

void __thiscall CBasePlayer::CreateBattleID(CBasePlayer *this)

{
                    /* Unresolved local var: char * infobuffer@[???] */
  if (tfc_clanbattle.value != 0.0) {
    CreateBattleID(this);
    return;
  }
  return;
}


// Display_Prematch  @ 0012c050  (line 124)

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Display_Prematch(void)

{
  entvars_t *peVar1;
  int d;
  globalvars_t *pgVar2;
  CBasePlayer *this;
  CBaseEntity *pStartEntity;
  int d_00;
  CBasePlayer *playerIndex;
  CBasePlayer *this_00;
  char *msg_name;
  char *pcVar3;
  
                    /* Unresolved local var: int iTimeLeft@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: CBaseEntity * pGrenade@[???] */
  if (g_fNextPrematchAlert <= gpGlobals->time) {
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
    d_00 = (int)ROUND(cb_prematch_time - gpGlobals->time);
    d = d_00 / 0x3c;
    if ((d_00 + d * 4 == d * 0x40) && (0x77 < d_00)) {
      pcVar3 = UTIL_dtos1(d);
      UTIL_ClientPrintAll(1,"#Game_minsleft",pcVar3,(char *)0x0,(char *)0x0,(char *)0x0);
      g_fNextPrematchAlert = (float)(d_00 + -0x3c) + gpGlobals->time;
      return;
    }
    if (d_00 == 0x3c) {
      UTIL_ClientPrintAll(1,"#Game_oneminleft",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      g_fNextPrematchAlert = gpGlobals->time + 30.0;
    }
    else {
      if (d_00 != 0x1e) {
        if (d_00 - 2U < 9) {
          pcVar3 = UTIL_dtos1(d_00);
          msg_name = "#Game_secsleft";
        }
        else {
          if (d_00 != 1) {
            if (1 < d_00) {
              return;
            }
            UTIL_ClientPrintAll(1,"#Game_matchbegin",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0
                               );
            UTIL_LogPrintf("World triggered \"Match_Begins_Now\"\n");
            if (tfc_clanbattle_locked.value != 0.0) {
              UTIL_ClientPrintAll(1,"#Game_matchlocked",(char *)0x0,(char *)0x0,(char *)0x0,
                                  (char *)0x0);
            }
            teamscores[1] = 0;
            teamscores[2] = 0;
            teamscores[3] = 0;
            teamscores[4] = 0;
            teamfrags[1] = 0;
            teamfrags[2] = 0;
            teamfrags[3] = 0;
            teamfrags[4] = 0;
            cb_prematch_time = 0.0;
            if (0 < gpGlobals->maxClients) {
              playerIndex = (CBasePlayer *)0x1;
              do {
                this_00 = playerIndex;
                this = UTIL_PlayerByIndex((int)playerIndex);
                if (this != (CBasePlayer *)0x0) {
                    /* Unresolved local var: char * infobuffer@[???] */
                  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.tf_id == 0) &&
                     (tfc_clanbattle.value != 0.0)) {
                    CBasePlayer::CreateBattleID(this_00);
                  }
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
                  CBasePlayer::TeamFortress_RemoveTimers(this);
                  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev;
                  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0xd])
                            (this,peVar1,peVar1,0x461c4000,0x8001000);
                  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev)->frags = 0.0;
                  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.real_frags = 0;
                  this->m_iDeaths = 0;
                }
                playerIndex = (CBasePlayer *)
                              ((int)&(playerIndex->super_CBaseMonster).super_CBaseToggle.
                                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                     _vptr_CBaseEntity + 1);
              } while ((int)playerIndex <= gpGlobals->maxClients);
            }
            pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"grenade");
            pgVar2 = gpGlobals;
            while (pStartEntity != (CBaseEntity *)0x0) {
              gpGlobals = pgVar2;
              (pStartEntity->m_pfnThink).__pfn = CBaseEntity::SUB_Remove;
              (pStartEntity->m_pfnThink).__delta = 0;
              pStartEntity->pev->nextthink = pgVar2->time;
              pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"grenade");
              pgVar2 = gpGlobals;
            }
            gpGlobals = pgVar2;
            teamfrags[1] = teamfrags[1];
            teamfrags[2] = teamfrags[2];
            teamfrags[3] = teamfrags[3];
            teamfrags[4] = teamfrags[4];
            teamscores[1] = teamscores[1];
            teamscores[2] = teamscores[2];
            teamscores[3] = teamscores[3];
            teamscores[4] = teamscores[4];
            return;
          }
          pcVar3 = (char *)0x0;
          msg_name = "#Game_onesec";
        }
        UTIL_ClientPrintAll(1,msg_name,pcVar3,(char *)0x0,(char *)0x0,(char *)0x0);
        g_fNextPrematchAlert = gpGlobals->time + 1.0;
        return;
      }
      UTIL_ClientPrintAll(1,"#Game_thirtysecleft",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      g_fNextPrematchAlert = gpGlobals->time + 20.0;
    }
  }
  return;
}


// Check_Ceasefire  @ 0012c430  (line 226)

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


// DumpClanScores  @ 0012c810  (line 262)

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DumpClanScores(void)

{
  int *piVar1;
  BOOL bDraw;
  CBasePlayer *pCVar2;
  int d;
  char *pcVar3;
  char *pcVar4;
  char *param1;
  int iVar5;
  int local_4c [7];
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
                    /* Unresolved local var: int[5] iNoPlayers@[???]
                       Unresolved local var: int[5] iUnaccountedFrags@[???]
                       Unresolved local var: int bDraw@[???]
                       Unresolved local var: int i@[???] */
  bDraw = TeamFortress_SortTeams();
  local_30 = TeamFortress_TeamGetNoPlayers(0);
  local_4c[0] = 0;
  local_2c = TeamFortress_TeamGetNoPlayers(1);
  local_4c[1] = 0;
  local_28 = TeamFortress_TeamGetNoPlayers(2);
  local_4c[2] = 0;
  local_24 = TeamFortress_TeamGetNoPlayers(3);
  local_4c[3] = 0;
  local_20 = TeamFortress_TeamGetNoPlayers(4);
  local_4c[4] = 0;
  if (0 < gpGlobals->maxClients) {
    iVar5 = 1;
    do {
                    /* Unresolved local var: CBaseEntity * pPlayer@[???] */
      pCVar2 = UTIL_PlayerByIndex(iVar5);
      if (pCVar2 != (CBasePlayer *)0x0) {
        local_4c[(pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.team_no] =
             local_4c[(pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.team_no] +
             (pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.real_frags;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= gpGlobals->maxClients);
  }
  local_4c[0] = teamfrags[0] - local_4c[0];
  local_4c[1] = teamfrags[1] - local_4c[1];
  local_4c[2] = teamfrags[2] - local_4c[2];
  local_4c[3] = teamfrags[3] - local_4c[3];
  local_4c[4] = teamfrags[4] - local_4c[4];
  UTIL_ClientPrintAll(1,"#Match_results",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  LogMatchResults(&local_30,local_4c,bDraw);
  if (bDraw == 0) {
    pcVar3 = GetTeamName(g_iOrderedTeams[2]);
    pcVar4 = GetTeamName(g_iOrderedTeams[1]);
    UTIL_ClientPrintAll(1,"#Match_winner",pcVar4,pcVar3,(char *)0x0,(char *)0x0);
    if (3.0 < number_of_teams) {
      pcVar3 = GetTeamName(g_iOrderedTeams[3]);
      UTIL_ClientPrintAll(1,"#Match_losers4",pcVar3,(char *)0x0,(char *)0x0,(char *)0x0);
      iVar5 = g_iOrderedTeams[4];
    }
    else {
      iVar5 = g_iOrderedTeams[3];
      if (number_of_teams <= 2.0) goto LAB_0012c96d;
    }
    pcVar3 = GetTeamName(iVar5);
    UTIL_ClientPrintAll(1,"#Match_losers3",pcVar3,(char *)0x0,(char *)0x0,(char *)0x0);
  }
  else {
    UTIL_ClientPrintAll(1,"#Match_draw",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  }
LAB_0012c96d:
  iVar5 = 1;
  if (1.0 <= number_of_teams) {
    do {
      d = TeamFortress_TeamGetNoPlayers(iVar5);
      pcVar3 = UTIL_dtos2(d);
      pcVar4 = UTIL_dtos1(iVar5);
      UTIL_ClientPrintAll(1,"#Match_team",pcVar4,pcVar3,(char *)0x0,(char *)0x0);
      pcVar3 = UTIL_dtos3(teamscores[iVar5]);
      pcVar4 = UTIL_dtos2(local_4c[iVar5]);
      piVar1 = teamfrags + iVar5;
      iVar5 = iVar5 + 1;
      param1 = UTIL_dtos1(*piVar1);
      UTIL_ClientPrintAll(1,"#Match_teamdump",param1,pcVar4,pcVar3,(char *)0x0);
    } while ((float)iVar5 <= number_of_teams);
  }
  return;
}


// LogMatchResults  @ 0012c570  (line 332)

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
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  undefined2 *puVar13;
  undefined4 *puVar14;
  char *pcVar15;
  int iVar16;
  int tno;
  uint local_2b0 [125];
  char local_bc [128];
  char local_3c [44];
  
                    /* Unresolved local var: int i@[???] */
  if (1.0 <= number_of_teams) {
    tno = 1;
                    /* Unresolved local var: char[500] teamResults@[???]
                       Unresolved local var: char[128] tempBuf@[???]
                       Unresolved local var: int allyFound@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: char[32] teamName@[???] */
    do {
      pcVar15 = "player";
      local_bc[0] = '\0';
      pcVar3 = UTIL_dtos4(iUnaccountedFrags[tno]);
      pcVar4 = UTIL_dtos3(teamfrags[tno]);
      iVar5 = TeamFortress_TeamGetNoPlayers(tno);
      if (iVar5 != 1) {
        pcVar15 = "players";
      }
      iVar5 = TeamFortress_TeamGetNoPlayers(tno);
      pcVar6 = UTIL_dtos2(iVar5);
      pcVar7 = UTIL_dtos1(teamscores[tno]);
      pcVar8 = GetTeamName(tno);
      sprintf((char *)local_2b0,
              "Team \"%s\" scored \"%s\" with \"%s\" %s (kills \"%s\") (kills_unaccounted \"%s\")",
              pcVar8,pcVar7,pcVar6,pcVar15,pcVar4,pcVar3);
      if (1.0 < number_of_teams) {
        bVar2 = false;
        iVar5 = 1;
        fVar1 = number_of_teams;
        do {
          while ((teamallies[tno] >> ((char)iVar5 - 1U & 0x1f) & 1U) != 0) {
            iVar16 = iVar5 + 1;
            pcVar8 = GetTeamName(iVar5);
            sprintf(local_3c,"<%s>",pcVar8,pcVar7,pcVar6,pcVar15,pcVar4,pcVar3);
            strcat(local_bc,local_3c);
            bVar2 = true;
            iVar5 = iVar16;
            fVar1 = number_of_teams;
            if (number_of_teams <= (float)iVar16) goto LAB_0012c6ea;
          }
          iVar5 = iVar5 + 1;
        } while ((float)iVar5 < fVar1);
LAB_0012c6ea:
        if (bVar2) {
          puVar12 = local_2b0;
          do {
            puVar11 = puVar12;
            uVar9 = *puVar11 + 0xfefefeff & ~*puVar11;
            uVar10 = uVar9 & 0x80808080;
            puVar12 = puVar11 + 1;
          } while (uVar10 == 0);
          if ((uVar9 & 0x8080) == 0) {
            puVar12 = (uint *)((int)puVar11 + 6);
            uVar10 = uVar10 >> 0x10;
          }
          puVar14 = (undefined4 *)((int)puVar12 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10)));
          *puVar14 = 0x6c612820;
          puVar14[1] = 0x7365696c;
          *(undefined2 *)(puVar14 + 2) = 0x2220;
          *(undefined1 *)((int)puVar14 + 10) = 0;
          strcat((char *)local_2b0,local_bc);
          puVar12 = local_2b0;
          do {
            puVar11 = puVar12;
            uVar9 = *puVar11 + 0xfefefeff & ~*puVar11;
            uVar10 = uVar9 & 0x80808080;
            puVar12 = puVar11 + 1;
          } while (uVar10 == 0);
          if ((uVar9 & 0x8080) == 0) {
            puVar12 = (uint *)((int)puVar11 + 6);
            uVar10 = uVar10 >> 0x10;
          }
          puVar13 = (undefined2 *)((int)puVar12 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10)));
          *puVar13 = 0x2922;
          *(undefined1 *)(puVar13 + 1) = 0;
        }
      }
      puVar12 = local_2b0;
      do {
        puVar11 = puVar12;
        uVar9 = *puVar11 + 0xfefefeff & ~*puVar11;
        uVar10 = uVar9 & 0x80808080;
        puVar12 = puVar11 + 1;
      } while (uVar10 == 0);
      if ((uVar9 & 0x8080) == 0) {
        puVar12 = (uint *)((int)puVar11 + 6);
        uVar10 = uVar10 >> 0x10;
      }
      tno = tno + 1;
      *(undefined2 *)((int)puVar12 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10))) = 10;
      UTIL_LogPrintf((char *)local_2b0);
    } while ((float)tno <= number_of_teams);
  }
  return;
}


