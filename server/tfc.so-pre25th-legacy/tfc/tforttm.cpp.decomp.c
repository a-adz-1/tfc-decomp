// Ghidra decompilation of functions from tfc/tforttm.cpp
// 13 functions, ordered by original source line

// TeamFortress_TeamShowScores  @ 00146b90  (line 25)

/* WARNING: Type propagation algorithm not settling */

void TeamFortress_TeamShowScores(BOOL bLong,CBasePlayer *pPlayer)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  iVar3 = 1;
  if (1.0 <= number_of_teams) {
    do {
      iVar1 = teamscores[iVar3];
      if (bLong == 0) {
        pcVar2 = UTIL_VarArgs("%s: %d\n",g_szTeamColors[iVar3],iVar1);
LAB_00146c4b:
        UTIL_ClientPrintAll(1,pcVar2,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      }
      else {
        if (pPlayer == (CBasePlayer *)0x0) {
          pcVar2 = UTIL_VarArgs("Team %d (%s): %d\n",iVar3,g_szTeamColors[iVar3],iVar1);
          goto LAB_00146c4b;
        }
        pcVar2 = UTIL_VarArgs("Team %d (%s): %d\n",iVar3,g_szTeamColors[iVar3],iVar1);
        ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,1,pcVar2,(char *)0x0,(char *)0x0,
                    (char *)0x0,(char *)0x0);
      }
      iVar3 = iVar3 + 1;
    } while ((float)iVar3 <= number_of_teams);
  }
  return;
}


// TeamFortress_TeamSetColor  @ 00146c90  (line 49)

void TeamFortress_TeamSetColor(int tno)

{
  teamcolors[1][1].topColor = 0x99;
  teamcolors[1][1].bottomColor = 0x8b;
  teamcolors[1][2].topColor = 0x99;
  teamcolors[1][2].bottomColor = 0x91;
  teamcolors[1][3].topColor = 0x99;
  teamcolors[1][3].bottomColor = 0x82;
  teamcolors[1][5].topColor = 0x99;
  teamcolors[1][5].bottomColor = 0x8c;
  teamcolors[1][6].topColor = 0x94;
  teamcolors[1][6].bottomColor = 0x8a;
  teamcolors[1][7].topColor = 0x8c;
  teamcolors[1][7].bottomColor = 0x91;
  teamcolors[1][9].topColor = 0x8c;
  teamcolors[1][9].bottomColor = 0x94;
  teamcolors[1][0xb].topColor = 0x96;
  teamcolors[1][0xb].bottomColor = 0x8c;
  teamcolors[1][10].topColor = 0x96;
  teamcolors[1][10].bottomColor = 0;
  teamcolors[2][2].topColor = 0xff;
  teamcolors[2][2].bottomColor = 10;
  teamcolors[2][3].topColor = 0xfa;
  teamcolors[2][3].bottomColor = 0x1c;
  teamcolors[1][4].topColor = 0x99;
  teamcolors[1][4].bottomColor = 0x91;
  teamcolors[2][4].topColor = 0xff;
  teamcolors[1][8].topColor = 0x96;
  teamcolors[1][8].bottomColor = 0x91;
  teamcolors[2][4].bottomColor = 0x14;
  teamcolors[2][1].topColor = 0xff;
  teamcolors[2][1].bottomColor = 10;
  teamcolors[2][6].topColor = 0xff;
  teamcolors[2][5].topColor = 0xff;
  teamcolors[2][5].bottomColor = 0xfa;
  teamcolors[2][6].bottomColor = 0x19;
  teamcolors[2][7].topColor = 0xfa;
  teamcolors[2][7].bottomColor = 0x19;
  teamcolors[2][8].topColor = 0xfa;
  teamcolors[2][8].bottomColor = 0xf0;
  teamcolors[2][0xb].topColor = 0xfa;
  teamcolors[2][0xb].bottomColor = 0xf0;
  teamcolors[2][10].topColor = 0xfa;
  teamcolors[2][10].bottomColor = 0;
  teamcolors[3][1].topColor = 0x2d;
  teamcolors[3][1].bottomColor = 0x23;
  teamcolors[3][3].topColor = 0x2d;
  teamcolors[3][3].bottomColor = 0x23;
  teamcolors[3][4].topColor = 0x2d;
  teamcolors[3][4].bottomColor = 0x23;
  teamcolors[3][5].topColor = 0x2d;
  teamcolors[3][5].bottomColor = 0x23;
  teamcolors[3][7].topColor = 0x2d;
  teamcolors[3][7].bottomColor = 0x23;
  teamcolors[3][8].topColor = 0x2d;
  teamcolors[3][8].bottomColor = 0x23;
  teamcolors[3][9].topColor = 0x2d;
  teamcolors[3][9].bottomColor = 0x2d;
  teamcolors[2][9].topColor = 5;
  teamcolors[2][9].bottomColor = 0xfa;
  teamcolors[3][10].topColor = 0x2d;
  teamcolors[3][2].topColor = 0x2d;
  teamcolors[3][2].bottomColor = 0x23;
  teamcolors[3][10].bottomColor = 0;
  teamcolors[3][6].topColor = 0x2d;
  teamcolors[3][6].bottomColor = 0x28;
  teamcolors[4][1].topColor = 100;
  teamcolors[3][0xb].topColor = 0x2d;
  teamcolors[3][0xb].bottomColor = 0x23;
  teamcolors[4][1].bottomColor = 0x5a;
  teamcolors[4][2].topColor = 0x50;
  teamcolors[4][2].bottomColor = 0x5a;
  teamcolors[4][4].topColor = 100;
  teamcolors[4][4].bottomColor = 0x5a;
  teamcolors[4][5].topColor = 100;
  teamcolors[4][5].bottomColor = 0x5a;
  teamcolors[4][6].topColor = 100;
  teamcolors[4][6].bottomColor = 0x5a;
  teamcolors[4][8].topColor = 100;
  teamcolors[4][8].bottomColor = 0x5a;
  teamcolors[4][9].topColor = 100;
  teamcolors[4][3].topColor = 100;
  teamcolors[4][9].bottomColor = 0x5a;
  teamcolors[4][3].bottomColor = 0x28;
  teamcolors[4][7].topColor = 100;
  teamcolors[4][0xb].topColor = 100;
  teamcolors[4][7].bottomColor = 0x32;
  teamcolors[4][0xb].bottomColor = 0x5a;
  teamcolors[4][10].topColor = 100;
  teamcolors[4][10].bottomColor = 0;
  rgbcolors[0].x = 255.0;
  rgbcolors[0].y = 255.0;
  rgbcolors[0].z = 255.0;
  rgbcolors[1].x = 0.0;
  rgbcolors[1].y = 0.0;
  rgbcolors[1].z = 255.0;
  rgbcolors[2].x = 255.0;
  rgbcolors[2].y = 0.0;
  rgbcolors[2].z = 0.0;
  rgbcolors[3].x = 255.0;
  rgbcolors[3].y = 255.0;
  rgbcolors[3].z = 30.0;
  rgbcolors[4].x = 0.0;
  rgbcolors[4].y = 255.0;
  rgbcolors[4].z = 0.0;
  return;
}


// GetTeamName  @ 00147070  (line 211)

char * GetTeamName(int tno)

{
  char *pcVar1;
  
  pcVar1 = "";
  if (0 < tno) {
    if (team_names[tno] != 0) {
      return gpGlobals->pStringBase + team_names[tno];
    }
    pcVar1 = sTNameCvars[tno + 7];
  }
  return pcVar1;
}


// TeamFortress_TeamIncreaseScore  @ 001470a0  (line 225)

void TeamFortress_TeamIncreaseScore(int tno,int scoretoadd)

{
  char *pcVar1;
  
  if (tno == 0) {
    return;
  }
  teamscores[tno] = teamscores[tno] + scoretoadd;
  (*g_engfuncs.pfnMessageBegin)(2,gmsgTeamScore,(float *)0x0,(edict_t *)0x0);
  pcVar1 = "";
  if (0 < tno) {
    if (team_names[tno] == 0) {
      pcVar1 = sTNameCvars[tno + 7];
    }
    else {
      pcVar1 = gpGlobals->pStringBase + team_names[tno];
    }
  }
  (*g_engfuncs.pfnWriteString)(pcVar1);
  (*g_engfuncs.pfnWriteShort)(teamscores[tno]);
  (*g_engfuncs.pfnWriteShort)(0);
                    /* WARNING: Could not recover jumptable at 0x00147132. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// TeamFortress_TeamGetScoreFrags  @ 00147150  (line 243)

int TeamFortress_TeamGetScoreFrags(int tno)

{
  return teamscores[tno];
}


// TeamFortress_TeamGetNoPlayers  @ 00147160  (line 249)

/* WARNING: Type propagation algorithm not settling */

int TeamFortress_TeamGetNoPlayers(int tno)

{
  CBasePlayer *pCVar1;
  int playerIndex;
  int iVar2;
  
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
  iVar2 = 0;
  if (0 < gpGlobals->maxClients) {
    playerIndex = 1;
    do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      pCVar1 = UTIL_PlayerByIndex(playerIndex);
      if (pCVar1 != (CBasePlayer *)0x0) {
        iVar2 = iVar2 + (uint)((pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.team_no == tno);
      }
      playerIndex = playerIndex + 1;
    } while (playerIndex <= gpGlobals->maxClients);
  }
  return iVar2;
}


// TeamFortress_GetNoPlayers  @ 001471b0  (line 268)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int TeamFortress_GetNoPlayers(void)

{
  CBasePlayer *pCVar1;
  int playerIndex;
  int iVar2;
  
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
  iVar2 = 0;
  if (0 < gpGlobals->maxClients) {
    playerIndex = 1;
    iVar2 = 0;
    do {
      pCVar1 = UTIL_PlayerByIndex(playerIndex);
      iVar2 = (iVar2 + 1) - (uint)(pCVar1 == (CBasePlayer *)0x0);
      playerIndex = playerIndex + 1;
    } while (playerIndex <= gpGlobals->maxClients);
  }
  return iVar2;
}


// ClassIsRestricted  @ 00147200  (line 287)

/* WARNING: Type propagation algorithm not settling */

BOOL ClassIsRestricted(float tno,int pc)

{
  CBasePlayer *pCVar1;
  int playerIndex;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int max@[???] */
  if (tno != 0.0) {
    if (pc == 1) {
      iVar2 = (int)cr_scout.value;
    }
    else if (pc == 2) {
      iVar2 = (int)cr_sniper.value;
    }
    else if (pc == 3) {
      iVar2 = (int)cr_soldier.value;
    }
    else if (pc == 4) {
      iVar2 = (int)cr_demoman.value;
    }
    else if (pc == 5) {
      iVar2 = (int)cr_medic.value;
    }
    else if (pc == 6) {
      iVar2 = (int)cr_hwguy.value;
    }
    else if (pc == 7) {
      iVar2 = (int)cr_pyro.value;
    }
    else if (pc == 8) {
      iVar2 = (int)cr_spy.value;
    }
    else if (pc == 9) {
      iVar2 = (int)cr_engineer.value;
    }
    else {
      if (pc != 10) {
        return 0;
      }
      iVar2 = (int)cr_random.value;
    }
    if (iVar2 < 1) {
      return (uint)(iVar2 == -1);
    }
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
    if (0 < gpGlobals->maxClients) {
      iVar3 = 0;
      playerIndex = 1;
      if (pc == 10) {
        do {
          pCVar1 = UTIL_PlayerByIndex(playerIndex);
          if ((pCVar1 != (CBasePlayer *)0x0) &&
             ((float)(pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.team_no == tno)) {
            iVar3 = (iVar3 + 1) -
                    (uint)(((pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.tfstate & 8U) == 0);
          }
          playerIndex = playerIndex + 1;
        } while (playerIndex <= gpGlobals->maxClients);
      }
      else {
        do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          pCVar1 = UTIL_PlayerByIndex(playerIndex);
          if (((pCVar1 != (CBasePlayer *)0x0) &&
              ((float)(pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.team_no == tno)) &&
             ((((pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.pev)->playerclass == pc ||
              ((pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.nextpc == pc)))) {
            iVar3 = iVar3 + (uint)(((pCVar1->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tfstate
                                   & 8U) == 0);
          }
          playerIndex = playerIndex + 1;
        } while (playerIndex <= gpGlobals->maxClients);
      }
      return (uint)(iVar2 <= iVar3);
    }
  }
  return 0;
}


// TeamFortress_TeamIsCivilian  @ 00147420  (line 371)

BOOL TeamFortress_TeamIsCivilian(float tno)

{
  if (tno == 1.0) {
    return (uint)(((byte)civilianteams & 1) != 0);
  }
  if (tno == 2.0) {
    return (uint)(((byte)civilianteams & 2) != 0);
  }
  if (tno == 3.0) {
    return (uint)(((byte)civilianteams & 4) != 0);
  }
  if (tno != 4.0) {
    if (tno != 0.0) {
      return 0;
    }
    return (uint)(illegalclasses[0] == -1);
  }
  return (uint)(((byte)civilianteams & 8) != 0);
}


// CalculateTeamEqualiser  @ 001474e0  (line 405)

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CalculateTeamEqualiser(void)

{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  CBasePlayer *pCVar9;
  int iVar10;
  int iVar11;
  float local_1c;
  float local_18;
  float local_14;
  
  teamadvantage[1] = 1.0;
  teamadvantage[2] = 1.0;
                    /* Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: float t3@[???]
                       Unresolved local var: float t4@[???]
                       Unresolved local var: float t_ave@[???]
                       Unresolved local var: float calc@[???] */
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
  teamadvantage[3] = 1.0;
  teamadvantage[4] = 1.0;
  if (number_of_teams != 2.0) {
    teamadvantage[1] = 1.0;
    teamadvantage[2] = 1.0;
    teamadvantage[3] = 1.0;
    teamadvantage[4] = 1.0;
    return;
  }
  if (tfc_balance_teams.value == 0.0) goto LAB_00147550;
  if (gpGlobals->maxClients < 1) {
    fVar3 = 0.0;
    bVar1 = true;
    local_1c = 0.0;
LAB_00147a66:
    local_18 = 0.0;
LAB_00147a6c:
    fVar7 = 0.0;
    local_14 = 0.0;
  }
  else {
    iVar10 = 1;
    iVar11 = 0;
    do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      pCVar9 = UTIL_PlayerByIndex(iVar10);
      if (pCVar9 != (CBasePlayer *)0x0) {
        iVar11 = iVar11 + (uint)((pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                 .super_CBaseDelay.super_CBaseEntity.team_no == 1);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 <= gpGlobals->maxClients);
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
    local_1c = (float)iVar11;
    if (gpGlobals->maxClients < 1) {
      fVar3 = (float)iVar11 + 0.0 + 0.0 + 0.0;
      bVar1 = fVar3 < 1.0;
      goto LAB_00147a66;
    }
    iVar10 = 1;
    iVar11 = 0;
    do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      pCVar9 = UTIL_PlayerByIndex(iVar10);
      if (pCVar9 != (CBasePlayer *)0x0) {
        iVar11 = iVar11 + (uint)((pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                 .super_CBaseDelay.super_CBaseEntity.team_no == 2);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 <= gpGlobals->maxClients);
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
    local_18 = (float)iVar11;
    if (gpGlobals->maxClients < 1) {
      fVar3 = local_1c + (float)iVar11 + 0.0 + 0.0;
      bVar1 = fVar3 < 1.0;
      goto LAB_00147a6c;
    }
    iVar10 = 1;
    iVar11 = 0;
    do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      pCVar9 = UTIL_PlayerByIndex(iVar10);
      if (pCVar9 != (CBasePlayer *)0x0) {
        iVar11 = iVar11 + (uint)((pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                 .super_CBaseDelay.super_CBaseEntity.team_no == 3);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 <= gpGlobals->maxClients);
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
    local_14 = (float)iVar11;
    if (gpGlobals->maxClients < 1) {
      fVar7 = 0.0;
      fVar3 = local_1c + local_18 + (float)iVar11 + 0.0;
      bVar1 = fVar3 < 1.0;
    }
    else {
      iVar10 = 1;
      iVar11 = 0;
      do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        pCVar9 = UTIL_PlayerByIndex(iVar10);
        if (pCVar9 != (CBasePlayer *)0x0) {
          iVar11 = iVar11 + (uint)((pCVar9->super_CBaseMonster).super_CBaseToggle.
                                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.team_no
                                  == 4);
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 <= gpGlobals->maxClients);
      fVar7 = (float)iVar11;
      fVar3 = local_1c + local_18 + local_14 + fVar7;
      bVar1 = fVar3 < 1.0;
    }
  }
  if (bVar1) {
    return;
  }
  fVar3 = fVar3 / number_of_teams;
  if (0.0 < local_1c) {
    fVar5 = fVar3 / local_1c - 1.0;
    if (fVar5 != 0.0) {
      fVar5 = fVar5 / 3.0;
    }
    teamadvantage[1] = fVar5 + 1.0;
  }
  if ((0.0 < local_18) && (2.0 <= number_of_teams)) {
    fVar5 = fVar3 / local_18 - 1.0;
    if (fVar5 != 0.0) {
      fVar5 = fVar5 / 3.0;
    }
    teamadvantage[2] = fVar5 + 1.0;
  }
  if ((0.0 < local_14) && (3.0 <= number_of_teams)) {
    fVar5 = fVar3 / local_14 - 1.0;
    if (fVar5 != 0.0) {
      fVar5 = fVar5 / 3.0;
    }
    teamadvantage[3] = fVar5 + 1.0;
  }
  if ((0.0 < fVar7) && (4.0 <= number_of_teams)) {
    fVar3 = fVar3 / fVar7 - 1.0;
    if (fVar3 != 0.0) {
      fVar3 = fVar3 / 3.0;
    }
    teamadvantage[4] = fVar3 + 1.0;
  }
LAB_00147550:
  if (tfc_balance_scores.value != 0.0) {
    fVar3 = (float)(teamscores[1] + 0x3c);
    fVar7 = 0.0;
    if (2.0 <= number_of_teams) {
      fVar7 = (float)(teamscores[2] + 0x3c);
    }
    fVar5 = 0.0;
    if (3.0 <= number_of_teams) {
      fVar5 = (float)(teamscores[3] + 0x3c);
    }
    fVar4 = 0.0;
    if (4.0 <= number_of_teams) {
      fVar4 = (float)(teamscores[4] + 0x3c);
    }
    fVar2 = number_of_teams - 1.0;
    fVar6 = ((fVar7 + fVar5 + fVar4) / fVar2) / fVar3 - 1.0;
    if (fVar6 != 0.0) {
      fVar6 = fVar6 / 3.0;
    }
    if (2.0 <= number_of_teams) {
      fVar8 = ((fVar3 + fVar5 + fVar4) / fVar2) / fVar7 - 1.0;
      if (fVar8 != 0.0) {
        fVar8 = fVar8 / 3.0;
      }
      teamadvantage[2] = (fVar8 + 1.0) * teamadvantage[2];
    }
    teamadvantage[1] = (fVar6 + 1.0) * teamadvantage[1];
    if (3.0 <= number_of_teams) {
      fVar6 = ((fVar7 + fVar3 + fVar4) / fVar2) / fVar5 - 1.0;
      if (fVar6 != 0.0) {
        fVar6 = fVar6 / 3.0;
      }
      teamadvantage[3] = (fVar6 + 1.0) * teamadvantage[3];
    }
    if (4.0 <= number_of_teams) {
      fVar3 = ((fVar3 + fVar7 + fVar5) / fVar2) / fVar4 - 1.0;
      if (fVar3 != 0.0) {
        fVar3 = fVar3 / 3.0;
      }
      teamadvantage[4] = (fVar3 + 1.0) * teamadvantage[4];
    }
  }
  return;
}


// TeamEqualiseDamage  @ 00147ae0  (line 563)

float TeamEqualiseDamage(CBaseEntity *targ,CBaseEntity *attacker,float damage)

{
  float fVar1;
  float fVar2;
  BOOL BVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
                    /* Unresolved local var: float adv@[???]
                       Unresolved local var: float newdam@[???] */
  iVar4 = 7;
  pcVar5 = gpGlobals->pStringBase + targ->pev->classname;
  bVar7 = pcVar5 == (char *)0x0;
  pcVar6 = "player";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar7 = *pcVar5 == *pcVar6;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    iVar4 = 7;
    pcVar5 = gpGlobals->pStringBase + attacker->pev->classname;
    bVar7 = pcVar5 == (char *)0x0;
    pcVar6 = "player";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar7 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if ((((bVar7) && (targ->team_no != 0)) && (attacker->team_no != 0)) &&
       (BVar3 = CBaseEntity::IsAlly(attacker,targ), BVar3 == 0)) {
      fVar1 = teamadvantage[attacker->team_no];
      if (fVar1 == 0.0) {
        (*g_engfuncs.pfnAlertMessage)(at_console,"There is a team with an advantage of 0\n");
        fVar1 = 0.1;
      }
      if (teamadvantage[targ->team_no] == 0.0) {
        (*g_engfuncs.pfnAlertMessage)(at_console,"There is a team with an advantage of 0\n");
        fVar2 = 10.0;
      }
      else {
        fVar2 = 1.0 / teamadvantage[targ->team_no];
      }
      fVar2 = fVar2 * fVar1 * damage;
      if (fVar2 < damage) {
        gfPrototypeLessDamage = (damage - fVar2) + gfPrototypeLessDamage;
        damage = fVar2;
      }
      else {
        gfPrototypeExtraDamage = (fVar2 - damage) + gfPrototypeExtraDamage;
        damage = fVar2;
      }
    }
  }
  return damage;
}


// TeamFortress_StatusQuery  @ 00147c80  (line 604)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void TeamFortress_StatusQuery(void)

{
  _func_void_ALERT_TYPE_char_ptr_varargs *p_Var1;
  CBasePlayer *pCVar2;
  int iVar3;
  int playerIndex;
  int iVar4;
  int iVar5;
  int local_24;
  
  p_Var1 = g_engfuncs.pfnAlertMessage;
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
  iVar4 = 0;
  if (gpGlobals->maxClients < 1) {
LAB_00147e29:
    local_24 = 0;
  }
  else {
    iVar3 = 1;
    do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      pCVar2 = UTIL_PlayerByIndex(iVar3);
      if (pCVar2 != (CBasePlayer *)0x0) {
        iVar4 = iVar4 + (uint)((pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.team_no == 4);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= gpGlobals->maxClients);
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
    if (gpGlobals->maxClients < 1) goto LAB_00147e29;
    iVar3 = 1;
    local_24 = 0;
    do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      pCVar2 = UTIL_PlayerByIndex(iVar3);
      if (pCVar2 != (CBasePlayer *)0x0) {
        local_24 = local_24 +
                   (uint)((pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.team_no == 3);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= gpGlobals->maxClients);
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
    if (0 < gpGlobals->maxClients) {
      iVar5 = 0;
      iVar3 = 1;
      do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        pCVar2 = UTIL_PlayerByIndex(iVar3);
        if (pCVar2 != (CBasePlayer *)0x0) {
          iVar5 = iVar5 + (uint)((pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                 .super_CBaseDelay.super_CBaseEntity.team_no == 2);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= gpGlobals->maxClients);
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
      iVar3 = 0;
      if (0 < gpGlobals->maxClients) {
        playerIndex = 1;
        iVar3 = 0;
        do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          pCVar2 = UTIL_PlayerByIndex(playerIndex);
          if (pCVar2 != (CBasePlayer *)0x0) {
            iVar3 = iVar3 + (uint)((pCVar2->super_CBaseMonster).super_CBaseToggle.
                                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.team_no
                                  == 1);
          }
          playerIndex = playerIndex + 1;
        } while (playerIndex <= gpGlobals->maxClients);
      }
      goto LAB_00147d99;
    }
  }
  iVar5 = 0;
  iVar3 = 0;
LAB_00147d99:
  (*p_Var1)(at_console,"players per team: %d %d %d %d\n",iVar3,iVar5,local_24,iVar4);
  (*g_engfuncs.pfnAlertMessage)
            (at_console,"    equalisation: %0.1f %0.1f %0.1f %0.1f\n",(double)teamadvantage[1],
             (double)teamadvantage[2],(double)teamadvantage[3],(double)teamadvantage[4]);
  (*g_engfuncs.pfnAlertMessage)(at_console,"Teamplay is %d\n",(double)gpGlobals->teamplay);
  return;
}


// TeamFortress_SortTeams  @ 00147e40  (line 613)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BOOL TeamFortress_SortTeams(void)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_44;
  int local_3c [11];
  
  fVar1 = number_of_teams;
                    /* Unresolved local var: int[5] bGotScore@[???]
                       Unresolved local var: int iHighestTeam@[???]
                       Unresolved local var: int iHighestScore@[???]
                       Unresolved local var: int iPrevScore@[???]
                       Unresolved local var: int iPrevTeam@[???]
                       Unresolved local var: BOOL bIsDraw@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int iTeam@[???] */
  g_iOrderedTeams[2] = 0;
  g_iOrderedTeams[3] = 0;
  g_iOrderedTeams[4] = 0;
  uVar2 = 1;
  local_3c[1] = 0;
  local_3c[2] = 0;
  local_3c[3] = 0;
  local_3c[4] = 0;
  g_iOrderedTeams[0] = 0;
  g_iOrderedTeams[1] = 0;
  if (1.0 <= number_of_teams) {
    iVar7 = 1;
    uVar2 = 1;
    local_44 = 0;
    iVar3 = 0;
    do {
      iVar4 = 1;
      iVar5 = 0;
      iVar6 = iVar3;
      do {
        if ((iVar5 <= teamscores[iVar4]) && (local_3c[iVar4] == 0)) {
          iVar5 = teamscores[iVar4];
          iVar6 = iVar4;
        }
        iVar4 = iVar4 + 1;
      } while ((float)iVar4 <= fVar1);
      if ((((char)uVar2 != '\0') && (1 < iVar7)) &&
         (uVar2 = 1, (teamallies[iVar7] >> ((char)iVar3 - 1U & 0x1f) & 1U) == 0)) {
        uVar2 = (uint)(iVar5 == local_44);
      }
      g_iOrderedTeams[iVar7] = iVar6;
      iVar7 = iVar7 + 1;
      local_3c[iVar6] = 1;
      iVar3 = iVar6;
      local_44 = iVar5;
    } while ((float)iVar7 <= fVar1);
  }
  return uVar2;
}


