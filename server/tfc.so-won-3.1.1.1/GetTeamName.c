// GetTeamName__Fi  @ 001142d4
undefined * GetTeamName__Fi(int param_1)

{
  undefined *puVar1;
  
  if (param_1 < 1) {
    puVar1 = &DAT_00157c9c;
  }
  else if ((&team_names)[param_1] == 0) {
    puVar1 = *(undefined **)(sTNameCvars + param_1 * 4 + 0x1c);
  }
  else {
    puVar1 = (undefined *)((&team_names)[param_1] + *(int *)(gpGlobals + 0x98));
  }
  return puVar1;
}


