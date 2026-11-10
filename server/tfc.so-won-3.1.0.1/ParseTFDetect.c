// ParseTFDetect__FP11CBaseEntity  @ 000ff6e4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ParseTFDetect__FP11CBaseEntity(int *param_1)

{
  bool bVar1;
  
  if (param_1[0xcc] != 0) {
    team_menu_string = param_1[0xcc];
  }
  if (param_1[0xd4] != 0) {
    DAT_001b4a9c = param_1[0xd4];
  }
  if (param_1[0xd5] != 0) {
    DAT_001b4aa0 = param_1[0xd5];
  }
  if (param_1[0xd6] != 0) {
    DAT_001b4aa4 = param_1[0xd6];
  }
  if (param_1[0xd8] != 0) {
    DAT_001b4aa8 = param_1[0xd8];
  }
  if (*(int *)(*param_1 + 0x1d4) != 0) {
    (*DAT_001a7edc)(*(int *)(*param_1 + 0x1d4) + *(int *)(gpGlobals + 0x98));
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
  _illegalclasses = *(undefined4 *)(*param_1 + 0x20c);
  DAT_001b49e4 = param_1[0x30];
  DAT_001b49e8 = param_1[0x34];
  DAT_001b49ec = param_1[0x38];
  DAT_001b49f0 = param_1[0x36];
  bVar1 = DAT_001b49e4 == -1;
  if (bVar1) {
    DAT_001b49e4 = 0;
  }
  civilianteams = (uint)bVar1;
  if (DAT_001b49e8 == -1) {
    DAT_001b49e8 = 0;
    civilianteams = civilianteams | 2;
  }
  if (DAT_001b49ec == -1) {
    DAT_001b49ec = 0;
    civilianteams = civilianteams | 4;
  }
  if (DAT_001b49f0 == -1) {
    DAT_001b49f0 = 0;
    civilianteams = civilianteams | 8;
  }
  return;
}


