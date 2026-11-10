// CheckExistence__11CBaseEntity  @ 001061b8
undefined4 CheckExistence__11CBaseEntity(int param_1)

{
  undefined4 uVar1;
  
  if (((((*(int *)(param_1 + 0x2e8) == -1) && (g_iSkillLevel < 0)) ||
       ((*(int *)(param_1 + 0x2ec) == -1 && (0 < g_iSkillLevel)))) ||
      ((1 < *(int *)(param_1 + 0x2e8) + 1U && (g_iSkillLevel < *(int *)(param_1 + 0x2e8))))) ||
     ((1 < *(int *)(param_1 + 0x2ec) + 1U && (*(int *)(param_1 + 0x2ec) < g_iSkillLevel)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


