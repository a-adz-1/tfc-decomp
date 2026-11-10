// LogMatchResults__FPiT0i  @ 000f8ee8
void LogMatchResults__FPiT0i(undefined4 param_1,int param_2)

{
  float fVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  int local_2a4;
  int local_298;
  char local_294 [32];
  char local_274 [128];
  char local_1f4 [500];
  
  local_298 = 1;
  if (1.0 <= number_of_teams) {
    local_2a4 = 4;
    do {
      bVar2 = false;
      local_274[0] = '\0';
      uVar3 = UTIL_dtos4__Fi(*(undefined4 *)(param_2 + local_2a4));
      uVar3 = UTIL_dtos3__Fi(*(undefined4 *)((int)&teamfrags + local_2a4),uVar3);
      iVar4 = TeamFortress_TeamGetNoPlayers__Fi(local_298,uVar3);
      pcVar5 = "players";
      if (iVar4 == 1) {
        pcVar5 = "player";
      }
      uVar3 = TeamFortress_TeamGetNoPlayers__Fi(local_298,pcVar5);
      uVar3 = UTIL_dtos2__Fi(uVar3);
      uVar3 = UTIL_dtos1__Fi(*(undefined4 *)(teamscores + local_2a4),uVar3);
      uVar3 = GetTeamName__Fi(local_298,uVar3);
      sprintf(local_1f4,
              "Team \"%s\" scored \"%s\" with \"%s\" %s (kills \"%s\") (kills_unaccounted \"%s\")",
              uVar3);
      if (1.0 < number_of_teams) {
        iVar4 = 1;
        do {
          if ((*(int *)((int)&teamallies + local_2a4) >> ((char)iVar4 - 1U & 0x1f) & 1U) != 0) {
            bVar2 = true;
            uVar3 = GetTeamName__Fi(iVar4);
            sprintf(local_294,"<%s>",uVar3);
            strcat(local_274,local_294);
          }
          iVar4 = iVar4 + 1;
          fVar1 = (float)iVar4;
        } while ((byte)(fVar1 < number_of_teams |
                        (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8)) == 1);
      }
      if (bVar2) {
        strcat(local_1f4," (allies \"");
        strcat(local_1f4,local_274);
        strcat(local_1f4,"\")");
      }
      strcat(local_1f4,"\n");
      UTIL_LogPrintf__FPce(local_1f4);
      local_2a4 = local_2a4 + 4;
      local_298 = local_298 + 1;
      fVar1 = (float)local_298;
    } while ((byte)((fVar1 < number_of_teams |
                     (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8)) - 1) < 0x40);
  }
  return;
}


