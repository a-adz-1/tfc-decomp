// ParseTFDetect__FP11CBaseEntity  @ 00110df0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ParseTFDetect__FP11CBaseEntity(int *param_1)

{
  int iVar1;
  
  if (param_1[0xe2] != 0) {
    team_menu_string = param_1[0xe2];
  }
  if (param_1[0xd] != 0) {
    number_of_teams = (float)param_1[0xd];
  }
  if (param_1[0xf8] != 0) {
    DAT_001ac4f0 = param_1[0xf8];
  }
  if (param_1[0xf9] != 0) {
    _DAT_001ac4f4 = param_1[0xf9];
  }
  if (param_1[0xfa] != 0) {
    _DAT_001ac4f8 = param_1[0xfa];
  }
  if (param_1[0xfc] != 0) {
    _DAT_001ac4fc = param_1[0xfc];
  }
  if (*(int *)(*param_1 + 0x1d4) != 0) {
    (*DAT_0019f73c)(*(int *)(*param_1 + 0x1d4) + *(int *)(gpGlobals + 0x98));
  }
  teamlives._4_4_ = param_1[0x33];
  teamlives._8_4_ = param_1[0x35];
  teamlives._12_4_ = param_1[0x39];
  teamlives._16_4_ = param_1[0x37];
  iVar1 = 1;
  do {
    if (*(int *)(teamlives + iVar1 * 4) == 0) {
      *(undefined4 *)(teamlives + iVar1 * 4) = 0xffffffff;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  teammaxplayers._4_4_ = param_1[0x2f];
  iVar1 = 1;
  teammaxplayers._8_4_ = param_1[0x31];
  teammaxplayers._12_4_ = param_1[0x2e];
  teammaxplayers._16_4_ = param_1[0x32];
  do {
    if (*(int *)(teammaxplayers + iVar1 * 4) == 0) {
      *(undefined4 *)(teammaxplayers + iVar1 * 4) = 100;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  illegalclasses = *(undefined4 *)(*param_1 + 0x20c);
  DAT_001ac264 = param_1[0x30];
  DAT_001ac268 = param_1[0x34];
  DAT_001ac26c = param_1[0x38];
  DAT_001ac270 = param_1[0x36];
  _civilianteams = 0;
  iVar1 = 1;
  do {
    if ((&illegalclasses)[iVar1] == -1) {
      (&illegalclasses)[iVar1] = 0;
      _civilianteams = _civilianteams | 1 << ((char)iVar1 - 1U & 0x1f);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  return;
}


