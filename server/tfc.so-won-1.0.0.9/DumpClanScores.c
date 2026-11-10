// DumpClanScores__Fv  @ 000f4a40
void DumpClanScores__Fv(void)

{
  float fVar1;
  byte bVar6;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar7;
  char *__s;
  char acStack_2f4 [200];
  char acStack_22c [512];
  int local_2c [5];
  undefined4 local_18 [5];
  
  iVar2 = TeamFortress_SortTeams__Fv();
  iVar7 = 0;
  do {
    uVar3 = TeamFortress_TeamGetNoPlayers__Fi(iVar7);
    local_18[iVar7] = uVar3;
    local_2c[iVar7] = 0;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 5);
  iVar7 = 1;
  if (0 < *(int *)(gpGlobals + 0x90)) {
    do {
      iVar4 = UTIL_PlayerByIndex__Fi(iVar7);
      if (iVar4 != 0) {
        local_2c[*(int *)(iVar4 + 0x120)] =
             local_2c[*(int *)(iVar4 + 0x120)] + *(int *)(iVar4 + 300);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 <= *(int *)(gpGlobals + 0x90));
  }
  iVar7 = 0;
  do {
    local_2c[iVar7] = (&teamfrags)[iVar7] - local_2c[iVar7];
    iVar7 = iVar7 + 1;
  } while (iVar7 < 5);
  UTIL_ClientPrintAll__FiPCcN41(1,"#Match_results",0,0,0,0);
  UTIL_LogPrintf__FPce("=------= MATCH RESULTS =------=\n");
  if (iVar2 == 0) {
    uVar3 = GetTeamName__Fi(DAT_00182048,0,0);
    uVar3 = GetTeamName__Fi(DAT_00182044,uVar3);
    UTIL_ClientPrintAll__FiPCcN41(1,"#Match_winner",uVar3);
    uVar3 = GetTeamName__Fi(DAT_00182048);
    uVar3 = GetTeamName__Fi(DAT_00182044,uVar3);
    sprintf(acStack_22c,"\"%s\" defeated \"%s\"",uVar3);
    if ((byte)(3.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
              (byte)((ushort)((ushort)(number_of_teams == 3.0) << 0xe) >> 8)) == 1) {
      uVar3 = GetTeamName__Fi(DAT_0018204c,0,0,0);
      UTIL_ClientPrintAll__FiPCcN41(1,"#Match_losers4",uVar3);
      uVar3 = GetTeamName__Fi(DAT_00182050,0,0,0);
      UTIL_ClientPrintAll__FiPCcN41(1,"#Match_losers3",uVar3);
      uVar3 = GetTeamName__Fi(DAT_00182050);
      uVar3 = GetTeamName__Fi(DAT_0018204c,uVar3);
      sprintf(acStack_2f4,", \"%s\" and \"%s\"\n",uVar3);
      strcat(acStack_22c,acStack_2f4);
    }
    else {
      if ((byte)(2.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
                (byte)((ushort)((ushort)(number_of_teams == 2.0) << 0xe) >> 8)) == 1) {
        uVar3 = GetTeamName__Fi(DAT_0018204c,0,0,0);
        UTIL_ClientPrintAll__FiPCcN41(1,"#Match_losers3",uVar3);
        uVar3 = GetTeamName__Fi(DAT_0018204c);
        __s = acStack_2f4;
        sprintf(__s," and \"%s\"\n",uVar3);
      }
      else {
        __s = "\n";
      }
      strcat(acStack_22c,__s);
    }
    UTIL_LogPrintf__FPce(acStack_22c);
  }
  else {
    UTIL_ClientPrintAll__FiPCcN41(1,"#Match_draw",0,0,0,0);
    UTIL_LogPrintf__FPce("-> DRAW <-");
  }
  iVar2 = 1;
  bVar6 = 1.0 < number_of_teams | (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
          (byte)((ushort)((ushort)(number_of_teams == 1.0) << 0xe) >> 8);
  while ((byte)(bVar6 - 1) < 0x40) {
    uVar3 = TeamFortress_TeamGetNoPlayers__Fi(iVar2,0,0);
    uVar3 = UTIL_dtos2__Fi(uVar3);
    uVar3 = UTIL_dtos1__Fi(iVar2,uVar3);
    UTIL_ClientPrintAll__FiPCcN41(1,"#Match_team",uVar3);
    uVar3 = UTIL_dtos3__Fi(*(undefined4 *)(teamscores + iVar2 * 4),0);
    uVar3 = UTIL_dtos2__Fi(local_2c[iVar2],uVar3);
    uVar3 = UTIL_dtos1__Fi((&teamfrags)[iVar2],uVar3);
    UTIL_ClientPrintAll__FiPCcN41(1,"#Match_teamdump",uVar3);
    uVar3 = UTIL_dtos3__Fi(*(undefined4 *)(teamscores + iVar2 * 4));
    uVar3 = UTIL_dtos2__Fi(local_2c[iVar2],uVar3);
    uVar3 = UTIL_dtos1__Fi((&teamfrags)[iVar2],uVar3);
    uVar3 = TeamFortress_TeamGetNoPlayers__Fi(iVar2,uVar3);
    uVar3 = UTIL_dtos2__Fi(uVar3);
    uVar3 = GetTeamName__Fi(iVar2,uVar3);
    UTIL_LogPrintf__FPce
              ("\"%s\" RESULTS: \"%d\" players. \"%s\" frags, \"%s\" unaccounted for. \"%s\" team score.\n"
               ,uVar3);
    iVar2 = iVar2 + 1;
    fVar1 = (float)iVar2;
    bVar6 = fVar1 < number_of_teams |
            (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8);
  }
  for (iVar2 = 1; iVar2 <= *(int *)(gpGlobals + 0x90); iVar2 = iVar2 + 1) {
    piVar5 = (int *)UTIL_PlayerByIndex__Fi(iVar2);
    if ((piVar5 != (int *)0x0) && (piVar5[0x42] != 0)) {
      (*DAT_00175578)(1,9,0,*(undefined4 *)(*piVar5 + 0x1e8));
      (*DAT_00175598)("snapshot\n");
      (*DAT_0017557c)();
    }
  }
  return;
}


