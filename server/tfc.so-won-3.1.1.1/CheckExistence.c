// CheckExistence__11CBaseEntity  @ 0011231c
undefined4 CheckExistence__11CBaseEntity(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x2f8);
  if (((((iVar1 == -1) && (g_iSkillLevel < 0)) ||
       ((iVar2 = *(int *)(param_1 + 0x2fc), iVar2 == -1 && (0 < g_iSkillLevel)))) ||
      ((1 < iVar1 + 1U && (g_iSkillLevel < iVar1)))) ||
     ((1 < iVar2 + 1U && (iVar2 < g_iSkillLevel)))) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


