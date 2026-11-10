// IsAlly__11CBaseEntityP11CBaseEntity  @ 001082d8
undefined4 IsAlly__11CBaseEntityP11CBaseEntity(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_2 + 0x120) == 0) || (*(int *)(param_1 + 0x120) == 0)) {
    uVar1 = 0;
  }
  else if (((int)(&teamallies)[*(int *)(param_1 + 0x120)] >>
            ((char)*(int *)(param_2 + 0x120) - 1U & 0x1f) & 1U) == 0) {
    uVar1 = IsTeammate__11CBaseEntityP11CBaseEntity(param_1,param_2);
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// IsAlly__11CBaseEntityi  @ 0010827c
bool IsAlly__11CBaseEntityi(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  if ((param_2 == 0) || (iVar1 = *(int *)(param_1 + 0x120), iVar1 == 0)) {
    bVar2 = false;
  }
  else if (((int)(&teamallies)[iVar1] >> ((char)param_2 - 1U & 0x1f) & 1U) == 0) {
    bVar2 = param_2 == iVar1;
  }
  else {
    bVar2 = true;
  }
  return bVar2;
}


