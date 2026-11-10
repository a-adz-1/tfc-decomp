// LogMatchResults__FPiT0i  @ 000fb21c
void LogMatchResults__FPiT0i(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int local_29c;
  char acStack_298 [32];
  char acStack_278 [128];
  char acStack_1f8 [500];
  
  local_29c = 1;
  if (1.0 <= number_of_teams) {
    do {
      bVar1 = false;
      acStack_278[0] = '\0';
      uVar2 = UTIL_dtos4__Fi(*(undefined4 *)(param_2 + local_29c * 4));
      uVar2 = UTIL_dtos3__Fi((&teamfrags)[local_29c],uVar2);
      iVar3 = TeamFortress_TeamGetNoPlayers__Fi(local_29c,uVar2);
      pcVar4 = "players";
      if (iVar3 == 1) {
        pcVar4 = "player";
      }
      uVar2 = TeamFortress_TeamGetNoPlayers__Fi(local_29c,pcVar4);
      uVar2 = UTIL_dtos2__Fi(uVar2);
      uVar2 = UTIL_dtos1__Fi(*(undefined4 *)(teamscores + local_29c * 4),uVar2);
      uVar2 = GetTeamName__Fi(local_29c,uVar2);
      sprintf(acStack_1f8,
              "Team \"%s\" scored \"%s\" with \"%s\" %s (kills \"%s\") (kills_unaccounted \"%s\")",
              uVar2);
      iVar3 = 1;
      if (1.0 < number_of_teams) {
        do {
          if (((int)(&teamallies)[local_29c] >> ((char)iVar3 - 1U & 0x1f) & 1U) != 0) {
            bVar1 = true;
            uVar2 = GetTeamName__Fi(iVar3);
            sprintf(acStack_298,"<%s>",uVar2);
            strcat(acStack_278,acStack_298);
          }
          iVar3 = iVar3 + 1;
        } while ((float)iVar3 < number_of_teams);
      }
      if (bVar1) {
        strcat(acStack_1f8," (allies \"");
        strcat(acStack_1f8,acStack_278);
        strcat(acStack_1f8,"\")");
      }
      strcat(acStack_1f8,"\n");
      UTIL_LogPrintf__FPce(acStack_1f8);
      local_29c = local_29c + 1;
    } while ((float)local_29c <= number_of_teams);
  }
  return;
}


