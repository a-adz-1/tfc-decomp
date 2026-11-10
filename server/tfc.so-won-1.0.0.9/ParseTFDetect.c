// ParseTFDetect__FP11CBaseEntity  @ 0010d750
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ParseTFDetect__FP11CBaseEntity(int *param_1)

{
  int iVar1;
  
  if (param_1[0xcb] != 0) {
    team_menu_string = param_1[0xcb];
  }
  if (*(int *)(*param_1 + 0x1b4) != 0) {
    (*DAT_0017555c)(*(int *)(*param_1 + 0x1b4) + *(int *)(gpGlobals + 0x98));
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
  teammaxplayers._8_4_ = param_1[0x31];
  teammaxplayers._12_4_ = param_1[0x2e];
  teammaxplayers._16_4_ = param_1[0x32];
  iVar1 = 1;
  do {
    if (*(int *)(teammaxplayers + iVar1 * 4) == 0) {
      *(undefined4 *)(teammaxplayers + iVar1 * 4) = 100;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  _illegalclasses = param_1[0xb];
  DAT_00182004 = param_1[0x30];
  DAT_00182008 = param_1[0x34];
  _DAT_0018200c = param_1[0x38];
  _DAT_00182010 = param_1[0x36];
  civilianteams = 0;
  iVar1 = 1;
  do {
    if (*(int *)(&illegalclasses + iVar1 * 4) == -1) {
      *(undefined4 *)(&illegalclasses + iVar1 * 4) = 0;
      civilianteams = civilianteams | 1 << ((char)iVar1 - 1U & 0x1f);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  return;
}


