// GetTeamName__Fi  @ 00110014
undefined * GetTeamName__Fi(int param_1)

{
  undefined *puVar1;
  
  if (param_1 < 1) {
    puVar1 = &DAT_00152afc;
  }
  else if (*(int *)(team_names + param_1 * 4) == 0) {
    puVar1 = *(undefined **)(sTNameCvars + param_1 * 4 + 0x1c);
  }
  else {
    puVar1 = (undefined *)(*(int *)(team_names + param_1 * 4) + *(int *)(gpGlobals + 0x98));
  }
  return puVar1;
}


