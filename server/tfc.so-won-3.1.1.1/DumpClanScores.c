// DumpClanScores__Fv  @ 000faf60
void DumpClanScores__Fv(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int local_2c [5];
  undefined4 local_18 [5];
  
  iVar2 = TeamFortress_SortTeams__Fv();
  iVar6 = 0;
  do {
    uVar3 = TeamFortress_TeamGetNoPlayers__Fi(iVar6);
    local_18[iVar6] = uVar3;
    iVar5 = iVar6 + 1;
    local_2c[iVar6] = 0;
    iVar6 = iVar5;
  } while (iVar5 < 5);
  iVar6 = 1;
  if (0 < *(int *)(gpGlobals + 0x90)) {
    do {
      iVar5 = UTIL_PlayerByIndex__Fi(iVar6);
      if (iVar5 != 0) {
        piVar1 = local_2c + *(int *)(iVar5 + 0x120);
        *piVar1 = *piVar1 + *(int *)(iVar5 + 300);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 <= *(int *)(gpGlobals + 0x90));
  }
  iVar6 = 0;
  do {
    local_2c[iVar6] = (&teamfrags)[iVar6] - local_2c[iVar6];
    iVar6 = iVar6 + 1;
  } while (iVar6 < 5);
  UTIL_ClientPrintAll__FiPCcN41(1,"#Match_results",0,0,0,0);
  LogMatchResults__FPiT0i(local_18,local_2c,iVar2);
  if (iVar2 == 0) {
    uVar3 = GetTeamName__Fi(DAT_001ac47c,0,0);
    uVar3 = GetTeamName__Fi(DAT_001ac478,uVar3);
    UTIL_ClientPrintAll__FiPCcN41(1,"#Match_winner",uVar3);
    if (0x3f < (byte)((number_of_teams < 3.0 |
                       (byte)((ushort)((ushort)NAN(number_of_teams) << 10) >> 8) |
                      (byte)((ushort)((ushort)(number_of_teams == 3.0) << 0xe) >> 8)) - 1)) {
      uVar3 = GetTeamName__Fi(uRam001ac480,0,0,0);
      UTIL_ClientPrintAll__FiPCcN41(1,"#Match_losers4",uVar3);
      uVar3 = GetTeamName__Fi(uRam001ac484,0,0,0);
      UTIL_ClientPrintAll__FiPCcN41(1,"#Match_losers3",uVar3);
      goto LAB_000fb157;
    }
    if (number_of_teams <= 2.0) goto LAB_000fb157;
    uVar9 = 0;
    uVar8 = 0;
    uVar7 = 0;
    uVar3 = GetTeamName__Fi(uRam001ac480,0,0,0);
    pcVar4 = "#Match_losers3";
  }
  else {
    uVar9 = 0;
    uVar8 = 0;
    uVar7 = 0;
    uVar3 = 0;
    pcVar4 = "#Match_draw";
  }
  UTIL_ClientPrintAll__FiPCcN41(1,pcVar4,uVar3,uVar7,uVar8,uVar9);
LAB_000fb157:
  iVar6 = 1;
  if (1.0 <= number_of_teams) {
    do {
      uVar3 = TeamFortress_TeamGetNoPlayers__Fi(iVar6,0,0);
      uVar3 = UTIL_dtos2__Fi(uVar3);
      uVar3 = UTIL_dtos1__Fi(iVar6,uVar3);
      UTIL_ClientPrintAll__FiPCcN41(1,"#Match_team",uVar3);
      uVar3 = UTIL_dtos3__Fi(*(undefined4 *)(teamscores + iVar6 * 4),0);
      uVar3 = UTIL_dtos2__Fi(local_2c[iVar6],uVar3);
      uVar3 = UTIL_dtos1__Fi((&teamfrags)[iVar6],uVar3);
      UTIL_ClientPrintAll__FiPCcN41(1,"#Match_teamdump",uVar3);
      iVar6 = iVar6 + 1;
    } while ((float)iVar6 <= number_of_teams);
  }
  return;
}


