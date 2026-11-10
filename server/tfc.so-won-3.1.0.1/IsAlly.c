// IsAlly__11CBaseEntityP11CBaseEntity  @ 000f8364
undefined4 IsAlly__11CBaseEntityP11CBaseEntity(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_2 + 0x120) == 0) || (*(int *)(param_1 + 0x120) == 0)) {
    uVar1 = 0;
  }
  else if (((int)(&teamallies)[*(int *)(param_1 + 0x120)] >>
            ((char)*(undefined4 *)(param_2 + 0x120) - 1U & 0x1f) & 1U) == 0) {
    uVar1 = IsTeammate__11CBaseEntityP11CBaseEntity(param_1,param_2);
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// IsAlly__11CBaseEntityi  @ 000f83d4
bool IsAlly__11CBaseEntityi(int param_1,int param_2)

{
  bool bVar1;
  
  if ((param_2 == 0) || (*(int *)(param_1 + 0x120) == 0)) {
    bVar1 = false;
  }
  else if (((int)(&teamallies)[*(int *)(param_1 + 0x120)] >> ((char)param_2 - 1U & 0x1f) & 1U) == 0)
  {
    bVar1 = param_2 == *(int *)(param_1 + 0x120);
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}


