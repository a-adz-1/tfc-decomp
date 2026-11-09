// Ghidra decompilation of functions from tfc/tforttm.cpp
// 13 functions, ordered by original source line

// TeamFortress_TeamShowScores  @ 001141a0  (line 25)

/* WARNING: Type propagation algorithm not settling */

void TeamFortress_TeamShowScores(BOOL bLong,CBasePlayer *pPlayer)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if (1.0 <= number_of_teams) {
    iVar3 = 1;
    do {
      iVar1 = teamscores[iVar3];
      if (bLong == 0) {
        pcVar2 = UTIL_VarArgs("%s: %d\n",g_szTeamColors[iVar3],iVar1);
LAB_00114262:
        UTIL_ClientPrintAll(1,pcVar2,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      }
      else {
        if (pPlayer == (CBasePlayer *)0x0) {
          pcVar2 = UTIL_VarArgs("Team %d (%s): %d\n",iVar3,g_szTeamColors[iVar3],iVar1);
          goto LAB_00114262;
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


// TeamFortress_TeamSetColor  @ 001142b0  (line 49)

void TeamFortress_TeamSetColor(int tno)

{
  teamcolors[1][1].topColor = 0x99;
  teamcolors[1][2].bottomColor = 0x91;
  teamcolors[1][3].topColor = 0x99;
  teamcolors[1][3].bottomColor = 0x82;
  teamcolors[1][4].topColor = 0x99;
  teamcolors[1][4].bottomColor = 0x91;
  teamcolors[1][5].topColor = 0x99;
  teamcolors[1][6].bottomColor = 0x8a;
  teamcolors[1][7].topColor = 0x8c;
  teamcolors[1][7].bottomColor = 0x91;
  teamcolors[1][8].topColor = 0x96;
  teamcolors[1][8].bottomColor = 0x91;
  teamcolors[1][9].topColor = 0x8c;
  teamcolors[1][0xb].bottomColor = 0x8c;
  teamcolors[1][10].topColor = 0x96;
  teamcolors[1][10].bottomColor = 0;
  teamcolors[2][1].topColor = 0xff;
  teamcolors[2][1].bottomColor = 10;
  teamcolors[2][2].topColor = 0xff;
  teamcolors[2][3].bottomColor = 0x1c;
  teamcolors[2][4].topColor = 0xff;
  teamcolors[1][1].bottomColor = 0x8b;
  teamcolors[1][2].topColor = 0x99;
  teamcolors[2][4].bottomColor = 0x14;
  teamcolors[1][5].bottomColor = 0x8c;
  teamcolors[1][6].topColor = 0x94;
  teamcolors[2][5].topColor = 0xff;
  teamcolors[1][9].bottomColor = 0x94;
  teamcolors[1][0xb].topColor = 0x96;
  teamcolors[2][5].bottomColor = 0xfa;
  teamcolors[2][2].bottomColor = 10;
  teamcolors[2][3].topColor = 0xfa;
  teamcolors[2][6].topColor = 0xff;
  teamcolors[2][7].bottomColor = 0x19;
  teamcolors[2][8].topColor = 0xfa;
  teamcolors[2][8].bottomColor = 0xf0;
  teamcolors[2][9].topColor = 5;
  teamcolors[2][9].bottomColor = 0xfa;
  teamcolors[2][0xb].topColor = 0xfa;
  teamcolors[2][10].bottomColor = 0;
  teamcolors[3][1].topColor = 0x2d;
  teamcolors[3][1].bottomColor = 0x23;
  teamcolors[3][2].topColor = 0x2d;
  teamcolors[3][2].bottomColor = 0x23;
  teamcolors[3][3].topColor = 0x2d;
  teamcolors[3][4].bottomColor = 0x23;
  teamcolors[3][5].topColor = 0x2d;
  teamcolors[3][5].bottomColor = 0x23;
  teamcolors[3][6].topColor = 0x2d;
  teamcolors[3][6].bottomColor = 0x28;
  teamcolors[3][7].topColor = 0x2d;
  teamcolors[3][8].bottomColor = 0x23;
  teamcolors[3][9].topColor = 0x2d;
  teamcolors[2][6].bottomColor = 0x19;
  teamcolors[3][9].bottomColor = 0x2d;
  teamcolors[2][7].topColor = 0xfa;
  teamcolors[2][0xb].bottomColor = 0xf0;
  teamcolors[3][0xb].topColor = 0x2d;
  teamcolors[2][10].topColor = 0xfa;
  teamcolors[3][3].bottomColor = 0x23;
  teamcolors[3][0xb].bottomColor = 0x23;
  teamcolors[3][4].topColor = 0x2d;
  teamcolors[3][7].bottomColor = 0x23;
  teamcolors[3][10].topColor = 0x2d;
  teamcolors[3][8].topColor = 0x2d;
  teamcolors[3][10].bottomColor = 0;
  teamcolors[4][1].bottomColor = 0x5a;
  teamcolors[4][2].topColor = 0x50;
  teamcolors[4][2].bottomColor = 0x5a;
  teamcolors[4][3].topColor = 100;
  teamcolors[4][3].bottomColor = 0x28;
  teamcolors[4][4].topColor = 100;
  rgbcolors[0].x = 255.0;
  teamcolors[4][5].bottomColor = 0x5a;
  rgbcolors[0].y = 255.0;
  teamcolors[4][6].topColor = 100;
  rgbcolors[0].z = 255.0;
  teamcolors[4][6].bottomColor = 0x5a;
  teamcolors[4][7].topColor = 100;
  teamcolors[4][7].bottomColor = 0x32;
  rgbcolors[1].x = 0.0;
  teamcolors[4][8].topColor = 100;
  rgbcolors[1].y = 0.0;
  teamcolors[4][9].bottomColor = 0x5a;
  rgbcolors[1].z = 255.0;
  teamcolors[4][0xb].topColor = 100;
  rgbcolors[2].x = 255.0;
  teamcolors[4][1].topColor = 100;
  rgbcolors[2].y = 0.0;
  teamcolors[4][0xb].bottomColor = 0x5a;
  teamcolors[4][4].bottomColor = 0x5a;
  rgbcolors[2].z = 0.0;
  teamcolors[4][5].topColor = 100;
  teamcolors[4][10].topColor = 100;
  teamcolors[4][8].bottomColor = 0x5a;
  teamcolors[4][9].topColor = 100;
  teamcolors[4][10].bottomColor = 0;
  rgbcolors[3].x = 255.0;
  rgbcolors[3].y = 255.0;
  rgbcolors[4].x = 0.0;
  rgbcolors[4].y = 255.0;
  rgbcolors[3].z = 30.0;
  rgbcolors[4].z = 0.0;
  return;
}


// GetTeamName  @ 001146a0  (line 211)

char * GetTeamName(int tno)

{
  if (tno < 1) {
    return "";
  }
  if (team_names[tno] == 0) {
    return sTNameCvars[tno + 7];
  }
  return gpGlobals->pStringBase + team_names[tno];
}


// TeamFortress_TeamIncreaseScore  @ 001146e0  (line 225)

void TeamFortress_TeamIncreaseScore(int tno,int scoretoadd)

{
  char *pcVar1;
  
  if (tno == 0) {
    return;
  }
  teamscores[tno] = teamscores[tno] + scoretoadd;
  (*g_engfuncs.pfnMessageBegin)(2,gmsgTeamScore,(float *)0x0,(edict_t *)0x0);
  if (tno < 1) {
    pcVar1 = "";
  }
  else if (team_names[tno] == 0) {
    pcVar1 = sTNameCvars[tno + 7];
  }
  else {
    pcVar1 = gpGlobals->pStringBase + team_names[tno];
  }
  (*g_engfuncs.pfnWriteString)(pcVar1);
  (*g_engfuncs.pfnWriteShort)(teamscores[tno]);
  (*g_engfuncs.pfnWriteShort)(0);
                    /* WARNING: Could not recover jumptable at 0x00114763. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// TeamFortress_TeamGetScoreFrags  @ 00114790  (line 243)

int TeamFortress_TeamGetScoreFrags(int tno)

{
  return teamscores[tno];
}


// TeamFortress_TeamGetNoPlayers  @ 001147a0  (line 249)

/* WARNING: Type propagation algorithm not settling */

int TeamFortress_TeamGetNoPlayers(int tno)

{
  CBasePlayer *pCVar1;
  int playerIndex;
  int iVar2;
  
                    /* Unresolved local var: int num@[???] */
                    /* Unresolved local var: int i@[???] */
  if (gpGlobals->maxClients < 1) {
    iVar2 = 0;
  }
  else {
    playerIndex = 1;
    iVar2 = 0;
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


// TeamFortress_GetNoPlayers  @ 00114800  (line 268)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int TeamFortress_GetNoPlayers(void)

{
  CBasePlayer *pCVar1;
  int playerIndex;
  int iVar2;
  
                    /* Unresolved local var: int num@[???] */
                    /* Unresolved local var: int i@[???] */
  if (gpGlobals->maxClients < 1) {
    iVar2 = 0;
  }
  else {
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


// ClassIsRestricted  @ 00114850  (line 287)

/* WARNING: Type propagation algorithm not settling */

BOOL ClassIsRestricted(float tno,int pc)

{
  uint uVar1;
  CBasePlayer *pCVar2;
  int playerIndex;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int max@[???] */
  uVar1 = 0;
  if (tno != 0.0) {
    if (pc == 1) {
      iVar3 = (int)cr_scout.value;
    }
    else if (pc == 2) {
      iVar3 = (int)cr_sniper.value;
    }
    else if (pc == 3) {
      iVar3 = (int)cr_soldier.value;
    }
    else if (pc == 4) {
      iVar3 = (int)cr_demoman.value;
    }
    else if (pc == 5) {
      iVar3 = (int)cr_medic.value;
    }
    else if (pc == 6) {
      iVar3 = (int)cr_hwguy.value;
    }
    else if (pc == 7) {
      iVar3 = (int)cr_pyro.value;
    }
    else if (pc == 8) {
      iVar3 = (int)cr_spy.value;
    }
    else if (pc == 9) {
      iVar3 = (int)cr_engineer.value;
    }
    else {
      if (pc != 10) {
        return 0;
      }
      iVar3 = (int)cr_random.value;
    }
    if (iVar3 < 1) {
      return (uint)(iVar3 == -1);
    }
    if (gpGlobals->maxClients < 1) {
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
      uVar1 = (uint)(iVar3 < 1);
    }
    else {
      iVar4 = 0;
      playerIndex = 1;
      if (pc == 10) {
        do {
          pCVar2 = UTIL_PlayerByIndex(playerIndex);
          if ((pCVar2 != (CBasePlayer *)0x0) &&
             (tno == (float)(pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.team_no)) {
            iVar4 = (iVar4 + 1) -
                    (uint)(((pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.tfstate & 8U) == 0);
          }
          playerIndex = playerIndex + 1;
        } while (playerIndex <= gpGlobals->maxClients);
        uVar1 = (uint)(iVar3 <= iVar4);
      }
      else {
        iVar4 = 0;
        do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          pCVar2 = UTIL_PlayerByIndex(playerIndex);
          if (((pCVar2 != (CBasePlayer *)0x0) &&
              ((float)(pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.team_no == tno)) &&
             ((pc == ((pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->playerclass ||
              (pc == (pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.nextpc)))) {
            iVar4 = iVar4 + (uint)(((pCVar2->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tfstate
                                   & 8U) == 0);
          }
          playerIndex = playerIndex + 1;
        } while (playerIndex <= gpGlobals->maxClients);
        uVar1 = (uint)(iVar3 <= iVar4);
      }
    }
  }
  return uVar1;
}


// TeamFortress_TeamIsCivilian  @ 00114a80  (line 372)

BOOL TeamFortress_TeamIsCivilian(float tno)

{
  if (tno == 1.0) {
    return civilianteams & 1;
  }
  if (tno == 2.0) {
    return (uint)civilianteams >> 1 & 1;
  }
  if (tno == 3.0) {
    return (uint)civilianteams >> 2 & 1;
  }
  if (tno != 4.0) {
    if (tno != 0.0) {
      return 0;
    }
    return (uint)(illegalclasses[0] == -1);
  }
  return (uint)civilianteams >> 3 & 1;
}


// CalculateTeamEqualiser  @ 00114b30  (line 405)

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CalculateTeamEqualiser(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  CBasePlayer *pCVar8;
  int iVar9;
  int iVar10;
  float local_1c;
  float local_18;
  
  teamadvantage[1] = 1.0;
  teamadvantage[2] = 1.0;
                    /* Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: float t3@[???]
                       Unresolved local var: float t4@[???]
                       Unresolved local var: float t_ave@[???]
                       Unresolved local var: float calc@[???] */
                    /* Unresolved local var: int i@[???] */
  teamadvantage[3] = 1.0;
  teamadvantage[4] = 1.0;
  if (number_of_teams != 2.0) {
    teamadvantage[1] = 1.0;
    teamadvantage[2] = 1.0;
    teamadvantage[3] = 1.0;
    teamadvantage[4] = 1.0;
    return;
  }
  if (tfc_balance_teams.value == 0.0) {
    if (tfc_balance_scores.value == 0.0) {
      teamadvantage[1] = 1.0;
      teamadvantage[2] = 1.0;
      teamadvantage[3] = 1.0;
      teamadvantage[4] = 1.0;
      return;
    }
    fVar1 = (float)(teamscores[1] + 0x3c);
    local_1c = 1.0;
  }
  else {
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
    if (gpGlobals->maxClients < 1) {
      teamadvantage[1] = 1.0;
      teamadvantage[2] = 1.0;
      teamadvantage[3] = 1.0;
      teamadvantage[4] = 1.0;
      return;
    }
    iVar9 = 1;
    iVar10 = 0;
    do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      pCVar8 = UTIL_PlayerByIndex(iVar9);
      if (pCVar8 != (CBasePlayer *)0x0) {
        iVar10 = iVar10 + (uint)((pCVar8->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                 .super_CBaseDelay.super_CBaseEntity.team_no == 1);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 <= gpGlobals->maxClients);
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
    fVar1 = (float)iVar10;
    if (gpGlobals->maxClients < 1) {
      fVar7 = 0.0;
      local_1c = 0.0;
      local_18 = 0.0;
    }
    else {
      iVar9 = 1;
      iVar10 = 0;
      do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        pCVar8 = UTIL_PlayerByIndex(iVar9);
        if (pCVar8 != (CBasePlayer *)0x0) {
          iVar10 = iVar10 + (uint)((pCVar8->super_CBaseMonster).super_CBaseToggle.
                                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.team_no
                                  == 2);
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 <= gpGlobals->maxClients);
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
      local_18 = (float)iVar10;
      if (gpGlobals->maxClients < 1) {
        fVar7 = 0.0;
        local_1c = 0.0;
      }
      else {
        iVar9 = 1;
        iVar10 = 0;
        do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          pCVar8 = UTIL_PlayerByIndex(iVar9);
          if (pCVar8 != (CBasePlayer *)0x0) {
            iVar10 = iVar10 + (uint)((pCVar8->super_CBaseMonster).super_CBaseToggle.
                                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.team_no
                                    == 3);
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 <= gpGlobals->maxClients);
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
        local_1c = (float)iVar10;
        if (gpGlobals->maxClients < 1) {
          fVar7 = 0.0;
        }
        else {
          iVar9 = 1;
          iVar10 = 0;
          do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
            pCVar8 = UTIL_PlayerByIndex(iVar9);
            if (pCVar8 != (CBasePlayer *)0x0) {
              iVar10 = iVar10 + (uint)((pCVar8->super_CBaseMonster).super_CBaseToggle.
                                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                       team_no == 4);
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 <= gpGlobals->maxClients);
          fVar7 = (float)iVar10;
        }
      }
    }
    fVar5 = local_18 + fVar1 + local_1c + fVar7;
    if (fVar5 < 1.0) {
      return;
    }
    fVar5 = fVar5 / number_of_teams;
    if (0.0 < fVar1) {
      fVar1 = fVar5 / fVar1 - 1.0;
      if (fVar1 != 0.0) {
        fVar1 = fVar1 / 3.0;
      }
      teamadvantage[1] = fVar1 + 1.0;
    }
    if ((0.0 < local_18) && (2.0 <= number_of_teams)) {
      fVar1 = fVar5 / local_18 - 1.0;
      if (fVar1 != 0.0) {
        fVar1 = fVar1 / 3.0;
      }
      teamadvantage[2] = fVar1 + 1.0;
    }
    if ((0.0 < local_1c) && (3.0 <= number_of_teams)) {
      fVar1 = fVar5 / local_1c - 1.0;
      if (fVar1 != 0.0) {
        fVar1 = fVar1 / 3.0;
      }
      teamadvantage[3] = fVar1 + 1.0;
    }
    if ((0.0 < fVar7) && (4.0 <= number_of_teams)) {
      fVar1 = fVar5 / fVar7 - 1.0;
      if (fVar1 != 0.0) {
        fVar1 = fVar1 / 3.0;
      }
      teamadvantage[4] = fVar1 + 1.0;
    }
    if (tfc_balance_scores.value == 0.0) {
      return;
    }
    fVar1 = (float)(teamscores[1] + 0x3c);
    local_1c = teamadvantage[1];
    if (number_of_teams < 2.0) {
      fVar7 = 0.0;
      goto joined_r0x00114eb2;
    }
  }
  fVar7 = (float)(teamscores[2] + 0x3c);
joined_r0x00114eb2:
  teamadvantage[2] = (float)((ulonglong)teamadvantage._4_8_ >> 0x20);
  if (3.0 <= number_of_teams) {
    fVar5 = (float)(teamscores[3] + 0x3c);
  }
  else {
    fVar5 = 0.0;
  }
  if (number_of_teams < 4.0) {
    fVar3 = 0.0;
  }
  else {
    fVar3 = (float)(teamscores[4] + 0x3c);
  }
  fVar2 = number_of_teams - 1.0;
  fVar4 = ((fVar3 + fVar7 + fVar5) / fVar2) / fVar1 - 1.0;
  if (fVar4 != 0.0) {
    fVar4 = fVar4 / 3.0;
  }
  if (2.0 <= number_of_teams) {
    fVar6 = ((fVar5 + fVar1 + fVar3) / fVar2) / fVar7 - 1.0;
    if (fVar6 != 0.0) {
      fVar6 = fVar6 / 3.0;
    }
    teamadvantage[2] = (fVar6 + 1.0) * teamadvantage[2];
  }
  teamadvantage[1] = (fVar4 + 1.0) * local_1c;
  if (3.0 <= number_of_teams) {
    fVar4 = ((fVar7 + fVar1 + fVar3) / fVar2) / fVar5 - 1.0;
    if (fVar4 != 0.0) {
      fVar4 = fVar4 / 3.0;
    }
    teamadvantage[3] = (fVar4 + 1.0) * teamadvantage[3];
  }
  if (number_of_teams < 4.0) {
    return;
  }
  fVar1 = ((fVar7 + fVar5 + fVar1) / fVar2) / fVar3 - 1.0;
  if (fVar1 != 0.0) {
    fVar1 = fVar1 / 3.0;
  }
  teamadvantage[4] = (fVar1 + 1.0) * teamadvantage[4];
  return;
}


// TeamEqualiseDamage  @ 00115120  (line 563)

float TeamEqualiseDamage(CBaseEntity *targ,CBaseEntity *attacker,float damage)

{
  float fVar1;
  uint uVar2;
  float fVar3;
  BOOL BVar4;
  int iVar5;
  byte *pbVar6;
  char *pcVar7;
  byte *pbVar8;
  char *pcVar9;
  bool bVar10;
  bool bVar11;
  
                    /* Unresolved local var: float adv@[???]
                       Unresolved local var: float newdam@[???] */
  iVar5 = 7;
  pcVar7 = gpGlobals->pStringBase;
  uVar2 = targ->pev->classname;
  bVar10 = CARRY4(uVar2,(uint)pcVar7);
  bVar11 = (byte *)(pcVar7 + uVar2) == (byte *)0x0;
  pbVar6 = (byte *)(pcVar7 + uVar2);
  pbVar8 = (byte *)"player";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar10 = *pbVar6 < *pbVar8;
    bVar11 = *pbVar6 == *pbVar8;
    pbVar6 = pbVar6 + 1;
    pbVar8 = pbVar8 + 1;
  } while (bVar11);
  if ((!bVar10 && !bVar11) == bVar10) {
    iVar5 = 7;
    bVar10 = pcVar7 + attacker->pev->classname == (char *)0x0;
    pcVar7 = pcVar7 + attacker->pev->classname;
    pcVar9 = "player";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar10 = *pcVar7 == *pcVar9;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar10);
    if ((((bVar10) && (targ->team_no != 0)) && (attacker->team_no != 0)) &&
       (BVar4 = CBaseEntity::IsAlly(attacker,targ), BVar4 == 0)) {
      fVar1 = teamadvantage[attacker->team_no];
      if (fVar1 == 0.0) {
        (*g_engfuncs.pfnAlertMessage)(at_console,"There is a team with an advantage of 0\n");
        fVar1 = 0.1;
      }
      if (teamadvantage[targ->team_no] == 0.0) {
        (*g_engfuncs.pfnAlertMessage)(at_console,"There is a team with an advantage of 0\n");
        fVar3 = 10.0;
      }
      else {
        fVar3 = 1.0 / teamadvantage[targ->team_no];
      }
      fVar3 = fVar3 * fVar1 * damage;
      if (fVar3 < damage) {
        gfPrototypeLessDamage = (damage - fVar3) + gfPrototypeLessDamage;
        damage = fVar3;
      }
      else {
        gfPrototypeExtraDamage = (fVar3 - damage) + gfPrototypeExtraDamage;
        damage = fVar3;
      }
    }
  }
  return damage;
}


// TeamFortress_StatusQuery  @ 001152a0  (line 604)

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
                    /* Unresolved local var: int num@[???] */
  local_24 = 0;
                    /* Unresolved local var: int i@[???] */
  if (gpGlobals->maxClients < 1) {
    iVar5 = 0;
    iVar4 = 0;
    iVar3 = 0;
  }
  else {
    iVar3 = 1;
    do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      pCVar2 = UTIL_PlayerByIndex(iVar3);
      if (pCVar2 != (CBasePlayer *)0x0) {
        local_24 = local_24 +
                   (uint)((pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.team_no == 4);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= gpGlobals->maxClients);
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
    iVar5 = 0;
    if (gpGlobals->maxClients < 1) {
      iVar4 = 0;
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
      do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        pCVar2 = UTIL_PlayerByIndex(iVar3);
        if (pCVar2 != (CBasePlayer *)0x0) {
          iVar5 = iVar5 + (uint)((pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                 .super_CBaseDelay.super_CBaseEntity.team_no == 3);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= gpGlobals->maxClients);
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
      iVar4 = 0;
      if (gpGlobals->maxClients < 1) {
        iVar3 = 0;
      }
      else {
        iVar3 = 1;
        iVar4 = 0;
        do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          pCVar2 = UTIL_PlayerByIndex(iVar3);
          if (pCVar2 != (CBasePlayer *)0x0) {
            iVar4 = iVar4 + (uint)((pCVar2->super_CBaseMonster).super_CBaseToggle.
                                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.team_no
                                  == 2);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 <= gpGlobals->maxClients);
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
        iVar3 = 0;
        if (0 < gpGlobals->maxClients) {
          playerIndex = 1;
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
      }
    }
  }
  (*p_Var1)(at_console,"players per team: %d %d %d %d\n",iVar3,iVar4,iVar5,local_24);
  (*g_engfuncs.pfnAlertMessage)
            (at_console,"    equalisation: %0.1f %0.1f %0.1f %0.1f\n",(double)teamadvantage[1],
             (double)teamadvantage[2],(double)teamadvantage[3],(double)teamadvantage[4]);
  (*g_engfuncs.pfnAlertMessage)(at_console,"Teamplay is %d\n",(double)gpGlobals->teamplay);
  return;
}


// TeamFortress_SortTeams  @ 00115480  (line 613)

/* WARNING: Removing unreachable block (ram,0x00115dbc) */
/* WARNING: Removing unreachable block (ram,0x00115d88) */
/* WARNING: Removing unreachable block (ram,0x00115695) */
/* WARNING: Removing unreachable block (ram,0x00115651) */
/* WARNING: Removing unreachable block (ram,0x00116119) */
/* WARNING: Removing unreachable block (ram,0x0011615d) */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BOOL TeamFortress_SortTeams(void)

{
  int iVar1;
  int iVar2;
  float fVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int local_40;
  int local_3c;
  int local_38;
  int aiStack_24 [5];
  
  fVar3 = number_of_teams;
  iVar2 = teamscores[4];
  iVar1 = teamscores[3];
  iVar11 = teamscores[2];
                    /* Unresolved local var: int[5] bGotScore@[???]
                       Unresolved local var: int iHighestTeam@[???]
                       Unresolved local var: int iHighestScore@[???]
                       Unresolved local var: int iPrevScore@[???]
                       Unresolved local var: int iPrevTeam@[???]
                       Unresolved local var: BOOL bIsDraw@[???]
                       Unresolved local var: int i@[???] */
  iVar12 = teamscores[1];
                    /* Unresolved local var: int iTeam@[???] */
  g_iOrderedTeams[2] = 0;
  g_iOrderedTeams[3] = 0;
  aiStack_24[1] = 0;
  aiStack_24[2] = 0;
  aiStack_24[3] = 0;
  aiStack_24[4] = 0;
  g_iOrderedTeams[0] = 0;
  g_iOrderedTeams[1] = 0;
  g_iOrderedTeams[4] = 0;
  if (number_of_teams < 1.0) {
    g_iOrderedTeams[0] = 0;
    g_iOrderedTeams[1] = 0;
    g_iOrderedTeams[2] = 0;
    g_iOrderedTeams[3] = 0;
    g_iOrderedTeams[4] = 0;
    return 1;
  }
  bVar4 = (byte)teamallies[2];
  local_3c = teamscores[1];
  local_40 = teamscores[1];
  if (number_of_teams < 4.0) {
    if (2.0 <= number_of_teams) {
      if (-1 < teamscores[1]) {
        if (3.0 <= number_of_teams) {
          g_iOrderedTeams[1] = 1;
          if (teamscores[1] <= teamscores[2]) {
            g_iOrderedTeams[1] = 2;
            iVar12 = teamscores[2];
          }
          if (iVar12 <= teamscores[3]) {
            g_iOrderedTeams[1] = 3;
            iVar12 = teamscores[3];
          }
          g_iOrderedTeams[2] = 1;
          aiStack_24[g_iOrderedTeams[1]] = 1;
          if (aiStack_24[1] != 0) {
            g_iOrderedTeams[2] = g_iOrderedTeams[1];
            local_3c = 0;
          }
          if ((local_3c <= teamscores[2]) && (aiStack_24[2] == 0)) {
            g_iOrderedTeams[2] = 2;
            local_3c = teamscores[2];
          }
          if ((local_3c <= teamscores[3]) && (aiStack_24[3] == 0)) {
            g_iOrderedTeams[2] = 3;
            local_3c = teamscores[3];
          }
          aiStack_24[g_iOrderedTeams[2]] = 1;
          g_iOrderedTeams[3] = 1;
          local_38 = teamscores[1];
          if (aiStack_24[1] != 0) {
            g_iOrderedTeams[3] = g_iOrderedTeams[2];
            local_38 = 0;
          }
          if ((local_38 <= teamscores[2]) && (aiStack_24[2] == 0)) {
            g_iOrderedTeams[3] = 2;
            local_38 = teamscores[2];
          }
          if ((local_38 <= teamscores[3]) && (aiStack_24[3] == 0)) {
            g_iOrderedTeams[3] = 3;
            local_38 = teamscores[3];
          }
          bVar4 = 0;
          if ((local_3c != iVar12 &
              ((byte)(teamallies[2] >> ((char)g_iOrderedTeams[1] - 1U & 0x1f)) & 1 ^ 1)) != 1) {
            bVar4 = ((byte)(teamallies[3] >> ((char)g_iOrderedTeams[2] - 1U & 0x1f)) & 1 ^ 1) &
                    local_3c != local_38 ^ 1;
          }
          aiStack_24[g_iOrderedTeams[3]] = 1;
          if (number_of_teams < 4.0) {
            g_iOrderedTeams[0] = 0;
            g_iOrderedTeams[4] = 0;
            return (uint)bVar4;
          }
          g_iOrderedTeams[4] = 1;
          iVar12 = teamscores[1];
          if (aiStack_24[1] != 0) {
            iVar12 = 0;
            g_iOrderedTeams[4] = g_iOrderedTeams[3];
          }
          if ((iVar12 <= teamscores[2]) && (aiStack_24[2] == 0)) {
            g_iOrderedTeams[4] = 2;
            iVar12 = teamscores[2];
          }
          if ((iVar12 <= teamscores[3]) && (aiStack_24[3] == 0)) {
            g_iOrderedTeams[4] = 3;
            iVar12 = teamscores[3];
          }
          if (bVar4 == 0) {
            g_iOrderedTeams[0] = 0;
            return 0;
          }
          g_iOrderedTeams[0] = 0;
          return (uint)(byte)(iVar12 != local_38 &
                              ((byte)(teamallies[4] >> ((char)g_iOrderedTeams[3] - 1U & 0x1f)) & 1 ^
                              1) ^ 1);
        }
        g_iOrderedTeams[2] = 1;
        g_iOrderedTeams[1] = 1;
        if (teamscores[1] <= teamscores[2]) {
          g_iOrderedTeams[1] = 2;
        }
        aiStack_24[g_iOrderedTeams[1]] = 1;
        if (teamscores[1] <= teamscores[2]) {
          iVar12 = teamscores[2];
        }
        if (aiStack_24[1] != 0) {
          g_iOrderedTeams[2] = g_iOrderedTeams[1];
          local_40 = 0;
        }
        if ((local_40 <= teamscores[2]) && (aiStack_24[2] == 0)) {
          g_iOrderedTeams[2] = 2;
          local_40 = teamscores[2];
        }
        aiStack_24[g_iOrderedTeams[2]] = 1;
        bVar4 = local_40 != iVar12 &
                ((byte)(teamallies[2] >> ((char)g_iOrderedTeams[1] - 1U & 0x1f)) & 1 ^ 1) ^ 1;
        uVar5 = (uint)bVar4;
        if (number_of_teams < 3.0) {
          g_iOrderedTeams[0] = 0;
          g_iOrderedTeams[3] = 0;
          g_iOrderedTeams[4] = 0;
          return uVar5;
        }
        g_iOrderedTeams[3] = 1;
        if (aiStack_24[1] != 0) {
          g_iOrderedTeams[3] = g_iOrderedTeams[2];
          local_3c = 0;
        }
        if ((local_3c <= teamscores[2]) && (aiStack_24[2] == 0)) {
          g_iOrderedTeams[3] = 2;
          local_3c = teamscores[2];
        }
        if (bVar4 != 0) {
          uVar5 = (uint)(byte)(((byte)(teamallies[3] >> ((char)g_iOrderedTeams[2] - 1U & 0x1f)) & 1
                               ^ 1) & local_40 != local_3c ^ 1);
        }
        aiStack_24[g_iOrderedTeams[3]] = 1;
        if (number_of_teams < 4.0) {
          g_iOrderedTeams[0] = 0;
          g_iOrderedTeams[4] = 0;
          return uVar5;
        }
LAB_00115efe:
        g_iOrderedTeams[4] = 1;
        iVar12 = teamscores[1];
        if (aiStack_24[1] != 0) {
          iVar12 = 0;
          g_iOrderedTeams[4] = g_iOrderedTeams[3];
        }
        if ((iVar12 <= teamscores[2]) && (aiStack_24[2] == 0)) {
          g_iOrderedTeams[4] = 2;
          iVar12 = teamscores[2];
        }
        uVar6 = 0;
        if (uVar5 != 0) {
          uVar6 = (uint)(byte)(iVar12 != local_3c &
                               ((byte)(teamallies[4] >> ((char)g_iOrderedTeams[3] - 1U & 0x1f)) & 1
                               ^ 1) ^ 1);
        }
        return uVar6;
      }
      if (3.0 <= number_of_teams) {
        if (teamscores[2] < 0) {
          g_iOrderedTeams[1] = 0;
          iVar12 = 0;
        }
        else {
          g_iOrderedTeams[1] = 2;
          iVar12 = teamscores[2];
        }
        if (iVar12 <= teamscores[3]) {
          g_iOrderedTeams[1] = 3;
          iVar12 = teamscores[3];
        }
        aiStack_24[g_iOrderedTeams[1]] = 1;
        g_iOrderedTeams[2] = g_iOrderedTeams[1];
        if (teamscores[2] < 0) {
          iVar11 = 0;
        }
        else {
          iVar11 = 0;
          if (aiStack_24[2] == 0) {
            g_iOrderedTeams[2] = 2;
            iVar11 = teamscores[2];
          }
        }
        if ((iVar11 <= teamscores[3]) && (aiStack_24[3] == 0)) {
          g_iOrderedTeams[2] = 3;
          iVar11 = teamscores[3];
        }
        aiStack_24[g_iOrderedTeams[2]] = 1;
        if (teamscores[2] < 0) {
          local_3c = 0;
          g_iOrderedTeams[3] = g_iOrderedTeams[2];
        }
        else {
          g_iOrderedTeams[3] = 2;
          local_3c = teamscores[2];
          if (aiStack_24[2] != 0) {
            g_iOrderedTeams[3] = g_iOrderedTeams[2];
            local_3c = 0;
          }
        }
        if ((local_3c <= teamscores[3]) && (aiStack_24[3] == 0)) {
          g_iOrderedTeams[3] = 3;
          local_3c = teamscores[3];
        }
        bVar4 = 0;
        if ((iVar11 != iVar12 &
            ((byte)(teamallies[2] >> ((char)g_iOrderedTeams[1] - 1U & 0x1f)) & 1 ^ 1)) != 1) {
          bVar4 = ((byte)(teamallies[3] >> ((char)g_iOrderedTeams[2] - 1U & 0x1f)) & 1 ^ 1) &
                  iVar11 != local_3c ^ 1;
        }
        aiStack_24[g_iOrderedTeams[3]] = 1;
        if (number_of_teams < 4.0) {
          g_iOrderedTeams[0] = 0;
          g_iOrderedTeams[4] = 0;
          return (uint)bVar4;
        }
        if (teamscores[2] < 0) {
          iVar12 = 0;
          g_iOrderedTeams[4] = g_iOrderedTeams[3];
        }
        else {
          g_iOrderedTeams[4] = 2;
          iVar12 = teamscores[2];
          if (aiStack_24[2] != 0) {
            iVar12 = 0;
            g_iOrderedTeams[4] = g_iOrderedTeams[3];
          }
        }
        if ((iVar12 <= teamscores[3]) && (aiStack_24[3] == 0)) {
          g_iOrderedTeams[4] = 3;
          iVar12 = teamscores[3];
        }
        if (bVar4 == 0) {
          g_iOrderedTeams[0] = 0;
          return 0;
        }
        g_iOrderedTeams[0] = 0;
        return (uint)(byte)(iVar12 != local_3c &
                            ((byte)(teamallies[4] >> ((char)g_iOrderedTeams[3] - 1U & 0x1f)) & 1 ^ 1
                            ) ^ 1);
      }
      if (teamscores[2] < 0) {
        iVar12 = 0;
        g_iOrderedTeams[1] = 0;
      }
      else {
        g_iOrderedTeams[1] = 2;
        iVar12 = teamscores[2];
      }
      aiStack_24[g_iOrderedTeams[1]] = 1;
      if (teamscores[2] < 0) {
        g_iOrderedTeams[2] = g_iOrderedTeams[1];
        iVar11 = 0;
      }
      else {
        g_iOrderedTeams[2] = 2;
        if (aiStack_24[2] != 0) {
          g_iOrderedTeams[2] = g_iOrderedTeams[1];
          iVar11 = 0;
        }
      }
      aiStack_24[g_iOrderedTeams[2]] = 1;
      bVar4 = ((byte)(teamallies[2] >> ((char)g_iOrderedTeams[1] - 1U & 0x1f)) & 1 ^ 1) &
              iVar11 != iVar12 ^ 1;
      uVar5 = (uint)bVar4;
      if (number_of_teams < 3.0) {
        g_iOrderedTeams[0] = 0;
        g_iOrderedTeams[3] = 0;
        g_iOrderedTeams[4] = 0;
        return uVar5;
      }
      if (teamscores[2] < 0) {
        g_iOrderedTeams[3] = g_iOrderedTeams[2];
        iVar12 = 0;
      }
      else {
        g_iOrderedTeams[3] = 2;
        iVar12 = teamscores[2];
        if (aiStack_24[2] != 0) {
          g_iOrderedTeams[3] = g_iOrderedTeams[2];
          iVar12 = 0;
        }
      }
      if (bVar4 != 0) {
        uVar5 = (uint)(byte)(iVar11 != iVar12 &
                             ((byte)(teamallies[3] >> ((char)g_iOrderedTeams[2] - 1U & 0x1f)) & 1 ^
                             1) ^ 1);
      }
      aiStack_24[g_iOrderedTeams[3]] = 1;
      if (number_of_teams < 4.0) {
        g_iOrderedTeams[0] = 0;
        g_iOrderedTeams[4] = 0;
        return uVar5;
      }
LAB_00115b09:
      if (teamscores[2] < 0) {
        iVar11 = 0;
        g_iOrderedTeams[4] = g_iOrderedTeams[3];
      }
      else {
        g_iOrderedTeams[4] = 2;
        iVar11 = teamscores[2];
        if (aiStack_24[2] != 0) {
          iVar11 = 0;
          g_iOrderedTeams[4] = g_iOrderedTeams[3];
        }
      }
      uVar6 = 0;
      if (uVar5 != 0) {
        uVar6 = (uint)(byte)(iVar11 != iVar12 &
                             ((byte)(teamallies[4] >> ((char)g_iOrderedTeams[3] - 1U & 0x1f)) & 1 ^
                             1) ^ 1);
      }
      return uVar6;
    }
    if (-1 < teamscores[1]) {
      if (number_of_teams < 2.0) {
        g_iOrderedTeams[0] = 0;
        g_iOrderedTeams[1] = 1;
        g_iOrderedTeams[2] = 0;
        g_iOrderedTeams[3] = 0;
        g_iOrderedTeams[4] = 0;
        return 1;
      }
      bVar4 = (bVar4 & 1 ^ 1) & teamscores[1] != 0 ^ 1;
      uVar5 = (uint)bVar4;
      if (number_of_teams < 3.0) {
        g_iOrderedTeams[0] = 0;
        g_iOrderedTeams[1] = 1;
        g_iOrderedTeams[2] = 1;
        g_iOrderedTeams[3] = 0;
        g_iOrderedTeams[4] = 0;
        return uVar5;
      }
      if (bVar4 != 0) {
        uVar5 = 1;
      }
      if (number_of_teams < 4.0) {
        g_iOrderedTeams[0] = 0;
        g_iOrderedTeams[1] = 1;
        g_iOrderedTeams[2] = 1;
        g_iOrderedTeams[3] = 1;
        g_iOrderedTeams[4] = 0;
        return uVar5;
      }
LAB_001156cb:
      g_iOrderedTeams[4] = 1;
      g_iOrderedTeams[3] = 1;
      g_iOrderedTeams[2] = 1;
      g_iOrderedTeams[1] = 1;
      g_iOrderedTeams[0] = 0;
      return (uint)(uVar5 != 0);
    }
    if (number_of_teams < 2.0) {
      g_iOrderedTeams[0] = 0;
      g_iOrderedTeams[1] = 0;
      g_iOrderedTeams[2] = 0;
      g_iOrderedTeams[3] = 0;
      g_iOrderedTeams[4] = 0;
      return 1;
    }
    if (number_of_teams < 3.0) {
      g_iOrderedTeams[0] = 0;
      g_iOrderedTeams[1] = 0;
      g_iOrderedTeams[2] = 0;
      g_iOrderedTeams[3] = 0;
      g_iOrderedTeams[4] = 0;
      return 1;
    }
    if (number_of_teams < 4.0) {
      g_iOrderedTeams[0] = 0;
      g_iOrderedTeams[1] = 0;
      g_iOrderedTeams[2] = 0;
      g_iOrderedTeams[3] = 0;
      g_iOrderedTeams[4] = 0;
      return 1;
    }
  }
  else if (number_of_teams < 3.0) {
    if (2.0 <= number_of_teams) {
      if (-1 < teamscores[1]) {
        g_iOrderedTeams[1] = 1;
        if (teamscores[1] <= teamscores[2]) {
          g_iOrderedTeams[1] = 2;
        }
        aiStack_24[g_iOrderedTeams[1]] = 1;
        if (teamscores[1] <= teamscores[2]) {
          iVar12 = teamscores[2];
        }
        g_iOrderedTeams[2] = 1;
        if (aiStack_24[1] != 0) {
          g_iOrderedTeams[2] = g_iOrderedTeams[1];
          local_40 = 0;
        }
        if ((local_40 <= teamscores[2]) && (aiStack_24[2] == 0)) {
          g_iOrderedTeams[2] = 2;
          local_40 = teamscores[2];
        }
        aiStack_24[g_iOrderedTeams[2]] = 1;
        bVar4 = local_40 != iVar12 &
                ((byte)(teamallies[2] >> ((char)g_iOrderedTeams[1] - 1U & 0x1f)) & 1 ^ 1) ^ 1;
        uVar5 = (uint)bVar4;
        if (number_of_teams < 3.0) {
          g_iOrderedTeams[0] = 0;
          g_iOrderedTeams[3] = 0;
          g_iOrderedTeams[4] = 0;
          return uVar5;
        }
        g_iOrderedTeams[3] = 1;
        if (aiStack_24[1] != 0) {
          g_iOrderedTeams[3] = g_iOrderedTeams[2];
          local_3c = 0;
        }
        if ((local_3c <= teamscores[2]) && (aiStack_24[2] == 0)) {
          g_iOrderedTeams[3] = 2;
          local_3c = teamscores[2];
        }
        if (bVar4 != 0) {
          uVar5 = (uint)(byte)(((byte)(teamallies[3] >> ((char)g_iOrderedTeams[2] - 1U & 0x1f)) & 1
                               ^ 1) & local_40 != local_3c ^ 1);
        }
        aiStack_24[g_iOrderedTeams[3]] = 1;
        goto LAB_00115efe;
      }
      if (teamscores[2] < 0) {
        g_iOrderedTeams[1] = 0;
        iVar12 = 0;
      }
      else {
        g_iOrderedTeams[1] = 2;
        iVar12 = teamscores[2];
      }
      aiStack_24[g_iOrderedTeams[1]] = 1;
      g_iOrderedTeams[2] = g_iOrderedTeams[1];
      if (teamscores[2] < 0) {
        iVar11 = 0;
      }
      else {
        iVar11 = 0;
        if (aiStack_24[2] == 0) {
          g_iOrderedTeams[2] = 2;
          iVar11 = teamscores[2];
        }
      }
      bVar4 = ((byte)(teamallies[2] >> ((char)g_iOrderedTeams[1] - 1U & 0x1f)) & 1 ^ 1) &
              iVar11 != iVar12 ^ 1;
      uVar5 = (uint)bVar4;
      aiStack_24[g_iOrderedTeams[2]] = 1;
      if (number_of_teams < 3.0) {
        g_iOrderedTeams[0] = 0;
        g_iOrderedTeams[3] = 0;
        g_iOrderedTeams[4] = 0;
        return uVar5;
      }
      g_iOrderedTeams[3] = g_iOrderedTeams[2];
      if (teamscores[2] < 0) {
        iVar12 = 0;
      }
      else {
        iVar12 = 0;
        if (aiStack_24[2] == 0) {
          g_iOrderedTeams[3] = 2;
          iVar12 = teamscores[2];
        }
      }
      if (bVar4 != 0) {
        uVar5 = (uint)(byte)(iVar11 != iVar12 &
                             ((byte)(teamallies[3] >> ((char)g_iOrderedTeams[2] - 1U & 0x1f)) & 1 ^
                             1) ^ 1);
      }
      aiStack_24[g_iOrderedTeams[3]] = 1;
      goto LAB_00115b09;
    }
    if (-1 < teamscores[1]) {
      if (number_of_teams < 2.0) {
        g_iOrderedTeams[0] = 0;
        g_iOrderedTeams[1] = 1;
        g_iOrderedTeams[2] = 0;
        g_iOrderedTeams[3] = 0;
        g_iOrderedTeams[4] = 0;
        return 1;
      }
      bVar4 = (bVar4 & 1 ^ 1) & teamscores[1] != 0 ^ 1;
      uVar5 = (uint)bVar4;
      if (number_of_teams < 3.0) {
        g_iOrderedTeams[0] = 0;
        g_iOrderedTeams[1] = 1;
        g_iOrderedTeams[2] = 1;
        g_iOrderedTeams[3] = 0;
        g_iOrderedTeams[4] = 0;
        return uVar5;
      }
      if (bVar4 != 0) {
        uVar5 = 1;
      }
      goto LAB_001156cb;
    }
    if (number_of_teams < 2.0) {
      g_iOrderedTeams[0] = 0;
      g_iOrderedTeams[1] = 0;
      g_iOrderedTeams[2] = 0;
      g_iOrderedTeams[3] = 0;
      g_iOrderedTeams[4] = 0;
      return 1;
    }
    if (number_of_teams < 3.0) {
      g_iOrderedTeams[0] = 0;
      g_iOrderedTeams[1] = 0;
      g_iOrderedTeams[2] = 0;
      g_iOrderedTeams[3] = 0;
      g_iOrderedTeams[4] = 0;
      return 1;
    }
  }
  else {
    if (2.0 <= number_of_teams) {
      if (teamscores[1] < 0) {
        iVar7 = 1;
        local_38 = 0;
        uVar5 = 1;
        iVar12 = 0;
        do {
          if (iVar11 < 0) {
            iVar10 = 0;
            iVar9 = iVar12;
          }
          else {
            iVar9 = 2;
            iVar10 = iVar11;
            if (aiStack_24[2] != 0) {
              iVar10 = 0;
              iVar9 = iVar12;
            }
          }
          if ((iVar10 <= iVar1) && (aiStack_24[3] == 0)) {
            iVar9 = 3;
            iVar10 = iVar1;
          }
          if ((iVar10 <= iVar2) && (aiStack_24[4] == 0)) {
            iVar9 = 4;
            iVar10 = iVar2;
          }
          if ((1 < iVar7) && (uVar5 != 0)) {
            uVar5 = (uint)(byte)(local_38 != iVar10 &
                                 ((byte)(teamallies[iVar7] >> ((char)iVar12 - 1U & 0x1f)) & 1 ^ 1) ^
                                1);
          }
          g_iOrderedTeams[iVar7] = iVar9;
          iVar7 = iVar7 + 1;
          aiStack_24[iVar9] = 1;
          iVar12 = iVar9;
          local_38 = iVar10;
        } while ((float)iVar7 <= fVar3);
        return uVar5;
      }
      iVar10 = 1;
      uVar5 = 1;
      local_38 = 0;
      iVar7 = 0;
      do {
        iVar8 = 1;
        iVar9 = iVar12;
        if (aiStack_24[1] != 0) {
          iVar8 = iVar7;
          iVar9 = 0;
        }
        if ((iVar9 <= iVar11) && (aiStack_24[2] == 0)) {
          iVar8 = 2;
          iVar9 = iVar11;
        }
        if ((iVar9 <= iVar1) && (aiStack_24[3] == 0)) {
          iVar8 = 3;
          iVar9 = iVar1;
        }
        if ((iVar9 <= iVar2) && (aiStack_24[4] == 0)) {
          iVar8 = 4;
          iVar9 = iVar2;
        }
        if ((1 < iVar10) && (uVar5 != 0)) {
          uVar5 = (uint)(byte)(local_38 != iVar9 &
                               ((byte)(teamallies[iVar10] >> ((char)iVar7 - 1U & 0x1f)) & 1 ^ 1) ^ 1
                              );
        }
        g_iOrderedTeams[iVar10] = iVar8;
        iVar10 = iVar10 + 1;
        aiStack_24[iVar8] = 1;
        iVar7 = iVar8;
        local_38 = iVar9;
      } while ((float)iVar10 <= fVar3);
      return uVar5;
    }
    if (-1 < teamscores[1]) {
      if (number_of_teams < 2.0) {
        g_iOrderedTeams[0] = 0;
        g_iOrderedTeams[1] = 1;
        g_iOrderedTeams[2] = 0;
        g_iOrderedTeams[3] = 0;
        g_iOrderedTeams[4] = 0;
        return 1;
      }
      if (((bVar4 & 1 ^ 1) & teamscores[1] != 0) == 1) {
        g_iOrderedTeams[0] = 0;
        g_iOrderedTeams[1] = 1;
        g_iOrderedTeams[2] = 1;
        g_iOrderedTeams[3] = 1;
        g_iOrderedTeams[4] = 1;
        return 0;
      }
      g_iOrderedTeams[0] = 0;
      g_iOrderedTeams[1] = 1;
      g_iOrderedTeams[2] = 1;
      g_iOrderedTeams[3] = 1;
      g_iOrderedTeams[4] = 1;
      return 1;
    }
    if (number_of_teams < 2.0) {
      g_iOrderedTeams[0] = 0;
      g_iOrderedTeams[1] = 0;
      g_iOrderedTeams[2] = 0;
      g_iOrderedTeams[3] = 0;
      g_iOrderedTeams[4] = 0;
      return 1;
    }
  }
  g_iOrderedTeams[1] = 0;
  g_iOrderedTeams[4] = 0;
  g_iOrderedTeams[3] = 0;
  g_iOrderedTeams[2] = 0;
  return 1;
}


