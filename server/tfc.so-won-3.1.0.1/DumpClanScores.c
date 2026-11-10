// DumpClanScores__Fv  @ 000ebc34
void DumpClanScores__Fv(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int local_28 [6];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = TeamFortress_SortTeams__Fv();
  local_28[5] = TeamFortress_TeamGetNoPlayers__Fi(0);
  local_28[0] = 0;
  local_10 = TeamFortress_TeamGetNoPlayers__Fi(1);
  local_28[1] = 0;
  local_c = TeamFortress_TeamGetNoPlayers__Fi(2);
  local_28[2] = 0;
  local_8 = TeamFortress_TeamGetNoPlayers__Fi(3);
  local_28[3] = 0;
  local_4 = TeamFortress_TeamGetNoPlayers__Fi(4);
  local_28[4] = 0;
  for (iVar5 = 1; iVar5 <= *(int *)(gpGlobals + 0x90); iVar5 = iVar5 + 1) {
    iVar3 = UTIL_PlayerByIndex__Fi(iVar5);
    if (iVar3 != 0) {
      local_28[*(int *)(iVar3 + 0x120)] = local_28[*(int *)(iVar3 + 0x120)] + *(int *)(iVar3 + 300);
    }
  }
  local_28[0] = teamfrags - local_28[0];
  local_28[1] = DAT_001b4a38 - local_28[1];
  local_28[2] = DAT_001b4a3c - local_28[2];
  local_28[3] = DAT_001b4a40 - local_28[3];
  local_28[4] = DAT_001b4a44 - local_28[4];
  UTIL_ClientPrintAll__FiPCcN41(1,"#Match_results",0,0,0,0);
  LogMatchResults__FPiT0i(local_28 + 5,local_28,iVar2);
  if (iVar2 == 0) {
    uVar6 = GetTeamName__Fi(DAT_001b4a28,0,0);
    uVar6 = GetTeamName__Fi(DAT_001b4a24,uVar6);
    UTIL_ClientPrintAll__FiPCcN41(1,"#Match_winner",uVar6);
    if (3.0 < number_of_teams) {
      uVar6 = GetTeamName__Fi(DAT_001b4a2c,0,0,0);
      UTIL_ClientPrintAll__FiPCcN41(1,"#Match_losers4",uVar6);
      uVar6 = GetTeamName__Fi(DAT_001b4a30,0,0,0);
      UTIL_ClientPrintAll__FiPCcN41(1,"#Match_losers3",uVar6);
      goto LAB_000ebe83;
    }
    if (number_of_teams <= 2.0) goto LAB_000ebe83;
    uVar9 = 0;
    uVar8 = 0;
    uVar7 = 0;
    uVar6 = GetTeamName__Fi(DAT_001b4a2c,0,0,0);
    pcVar4 = "#Match_losers3";
  }
  else {
    uVar9 = 0;
    uVar8 = 0;
    uVar7 = 0;
    uVar6 = 0;
    pcVar4 = "#Match_draw";
  }
  UTIL_ClientPrintAll__FiPCcN41(1,pcVar4,uVar6,uVar7,uVar8,uVar9);
LAB_000ebe83:
  iVar2 = 1;
  fVar1 = 1.0;
  while ((byte)((fVar1 < number_of_teams |
                 (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8)) - 1) < 0x40) {
    uVar6 = TeamFortress_TeamGetNoPlayers__Fi(iVar2,0,0);
    uVar6 = UTIL_dtos2__Fi(uVar6);
    uVar6 = UTIL_dtos1__Fi(iVar2,uVar6);
    UTIL_ClientPrintAll__FiPCcN41(1,"#Match_team",uVar6);
    uVar6 = UTIL_dtos3__Fi(*(undefined4 *)(teamscores + iVar2 * 4),0);
    uVar6 = UTIL_dtos2__Fi(local_28[iVar2],uVar6);
    uVar6 = UTIL_dtos1__Fi((&teamfrags)[iVar2],uVar6);
    UTIL_ClientPrintAll__FiPCcN41(1,"#Match_teamdump",uVar6);
    iVar2 = iVar2 + 1;
    fVar1 = (float)iVar2;
  }
  return;
}


