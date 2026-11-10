// IsTeammate__11CBaseEntityP11CBaseEntity  @ 001071a0
undefined4 IsTeammate__11CBaseEntityP11CBaseEntity(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_2 + 0x120) == *(int *)(param_1 + 0x120)) || (*(int *)(param_1 + 0x120) == 0))
  {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


