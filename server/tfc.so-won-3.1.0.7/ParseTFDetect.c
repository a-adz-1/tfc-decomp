// ParseTFDetect__FP11CBaseEntity  @ 0010e21c
void ParseTFDetect__FP11CBaseEntity(int *param_1)

{
  bool bVar1;
  
  if (param_1[0xde] != 0) {
    team_menu_string = param_1[0xde];
  }
  if (param_1[0xd] != 0) {
    number_of_teams = (float)param_1[0xd];
  }
  if (param_1[0xf4] != 0) {
    team_names._4_4_ = param_1[0xf4];
  }
  if (param_1[0xf5] != 0) {
    team_names._8_4_ = param_1[0xf5];
  }
  if (param_1[0xf6] != 0) {
    team_names._12_4_ = param_1[0xf6];
  }
  if (param_1[0xf8] != 0) {
    team_names._16_4_ = param_1[0xf8];
  }
  if (*(int *)(*param_1 + 0x1d4) != 0) {
    (*DAT_001c10bc)(*(int *)(*param_1 + 0x1d4) + *(int *)(gpGlobals + 0x98));
  }
  teamlives._4_4_ = param_1[0x33];
  teamlives._8_4_ = param_1[0x35];
  teamlives._12_4_ = param_1[0x39];
  teamlives._16_4_ = param_1[0x37];
  if (teamlives._4_4_ == 0) {
    teamlives._4_4_ = 0xffffffff;
  }
  if (teamlives._8_4_ == 0) {
    teamlives._8_4_ = 0xffffffff;
  }
  if (teamlives._12_4_ == 0) {
    teamlives._12_4_ = 0xffffffff;
  }
  if (teamlives._16_4_ == 0) {
    teamlives._16_4_ = 0xffffffff;
  }
  teammaxplayers._4_4_ = param_1[0x2f];
  teammaxplayers._8_4_ = param_1[0x31];
  teammaxplayers._12_4_ = param_1[0x2e];
  teammaxplayers._16_4_ = param_1[0x32];
  if (teammaxplayers._4_4_ == 0) {
    teammaxplayers._4_4_ = 100;
  }
  if (teammaxplayers._8_4_ == 0) {
    teammaxplayers._8_4_ = 100;
  }
  if (teammaxplayers._12_4_ == 0) {
    teammaxplayers._12_4_ = 100;
  }
  if (teammaxplayers._16_4_ == 0) {
    teammaxplayers._16_4_ = 100;
  }
  illegalclasses = *(undefined4 *)(*param_1 + 0x20c);
  DAT_001cdbc4 = param_1[0x30];
  DAT_001cdbc8 = param_1[0x34];
  DAT_001cdbcc = param_1[0x38];
  DAT_001cdbd0 = param_1[0x36];
  bVar1 = DAT_001cdbc4 == -1;
  if (bVar1) {
    DAT_001cdbc4 = 0;
  }
  civilianteams = (uint)bVar1;
  if (DAT_001cdbc8 == -1) {
    DAT_001cdbc8 = 0;
    civilianteams = civilianteams | 2;
  }
  if (DAT_001cdbcc == -1) {
    DAT_001cdbcc = 0;
    civilianteams = civilianteams | 4;
  }
  if (DAT_001cdbd0 == -1) {
    DAT_001cdbd0 = 0;
    civilianteams = civilianteams | 8;
  }
  return;
}


