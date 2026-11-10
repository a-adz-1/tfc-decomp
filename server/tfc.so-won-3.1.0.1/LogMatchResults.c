// LogMatchResults__FPiT0i  @ 000ebf60
void LogMatchResults__FPiT0i(undefined4 param_1,int param_2,int param_3)

{
  float fVar1;
  bool bVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iStack_218;
  char local_214 [4];
  int aiStack_210 [4];
  char local_200 [480];
  char acStack_20 [32];
  
  UTIL_LogPrintf__FPce("=------= MATCH RESULTS =------=\n");
  iVar5 = DAT_001b4a24;
  if (param_3 == 0) {
    pcVar3 = local_214;
    for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      pcVar3 = pcVar3 + 4;
    }
    local_214[0] = '\x01';
    local_214[1] = '\0';
    local_214[2] = '\0';
    local_214[3] = '\0';
    uVar4 = GetTeamName__Fi(DAT_001b4a24);
    sprintf(local_200,"\"%s\" ",uVar4);
    aiStack_210[iVar5 + -1] = 1;
    iVar6 = 1;
    fVar1 = 1.0;
    while ((byte)((fVar1 < number_of_teams |
                   (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8)) - 1) < 0x40) {
      if (((int)(&teamallies)[iVar5] >> ((char)iVar6 - 1U & 0x1f) & 1U) != 0) {
        strcat(local_200,"and \"");
        pcVar3 = (char *)GetTeamName__Fi(iVar6);
        strcat(local_200,pcVar3);
        strcat(local_200,"\" ");
        aiStack_210[iVar6 + -1] = 1;
      }
      iVar6 = iVar6 + 1;
      fVar1 = (float)iVar6;
    }
    strcat(local_200,"defeated ");
    bVar2 = true;
    iVar5 = 1;
    if (1.0 <= number_of_teams) {
      piVar7 = aiStack_210;
      do {
        if (*piVar7 == 0) {
          if (bVar2) {
            pcVar3 = "\"";
          }
          else {
            pcVar3 = "and \"";
          }
          strcat(local_200,pcVar3);
          pcVar3 = (char *)GetTeamName__Fi(iVar5);
          strcat(local_200,pcVar3);
          strcat(local_200,"\" ");
          *piVar7 = 1;
          bVar2 = false;
        }
        piVar7 = piVar7 + 1;
        iVar5 = iVar5 + 1;
      } while ((float)iVar5 <= number_of_teams);
    }
    strcat(local_200,"\n");
    UTIL_LogPrintf__FPce(local_200);
  }
  else {
    UTIL_LogPrintf__FPce("-> DRAW <-\n");
  }
  iStack_218 = 1;
  if (1.0 <= number_of_teams) {
    iVar5 = 4;
    do {
      uVar4 = UTIL_dtos3__Fi(*(undefined4 *)(teamscores + iVar5));
      uVar4 = UTIL_dtos2__Fi(*(undefined4 *)(param_2 + iVar5),uVar4);
      uVar4 = UTIL_dtos1__Fi(*(undefined4 *)((int)&teamfrags + iVar5),uVar4);
      uVar4 = TeamFortress_TeamGetNoPlayers__Fi(iStack_218,uVar4);
      uVar4 = UTIL_dtos2__Fi(uVar4);
      uVar4 = GetTeamName__Fi(iStack_218,uVar4);
      sprintf(local_214,
              "\"%s\" RESULTS: \"%s\" players. \"%s\" frags, \"%s\" unaccounted for. \"%s\" team score. Allies:"
              ,uVar4);
      if (1.0 < number_of_teams) {
        iVar6 = 1;
        do {
          if ((*(int *)((int)&teamallies + iVar5) >> ((char)iVar6 - 1U & 0x1f) & 1U) != 0) {
            sprintf(acStack_20,"\"%i\"",iVar6);
            strcat(local_214,acStack_20);
          }
          iVar6 = iVar6 + 1;
          fVar1 = (float)iVar6;
        } while ((byte)(fVar1 < number_of_teams |
                        (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8)) == 1);
      }
      strcat(local_214,"\n");
      UTIL_LogPrintf__FPce(local_214);
      iVar5 = iVar5 + 4;
      iStack_218 = iStack_218 + 1;
      fVar1 = (float)iStack_218;
    } while ((byte)((fVar1 < number_of_teams |
                     (byte)((ushort)((ushort)(NAN(fVar1) || NAN(number_of_teams)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == number_of_teams) << 0xe) >> 8)) - 1) < 0x40);
  }
  return;
}


