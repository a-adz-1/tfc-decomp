// CheckExistence__11CBaseEntity  @ 00107330
undefined4 CheckExistence__11CBaseEntity(int param_1)

{
  undefined4 uVar1;
  
  if (((((*(int *)(param_1 + 0x2e0) == -1) && (g_iSkillLevel < 0)) ||
       ((*(int *)(param_1 + 0x2e4) == -1 && (0 < g_iSkillLevel)))) ||
      ((1 < *(int *)(param_1 + 0x2e0) + 1U && (g_iSkillLevel < *(int *)(param_1 + 0x2e0))))) ||
     ((1 < *(int *)(param_1 + 0x2e4) + 1U && (*(int *)(param_1 + 0x2e4) < g_iSkillLevel)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


