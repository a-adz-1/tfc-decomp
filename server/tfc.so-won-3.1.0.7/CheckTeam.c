// CheckTeam__8CTFSpawni  @ 00108840
bool CheckTeam__8CTFSpawni(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  
  if (*(int *)(param_1 + 0x120) == 0) {
    iVar1 = __opi__7EHANDLE(param_1 + 0x448);
    if (iVar1 != 0) {
      uVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x448,param_2);
      iVar1 = TeamMatches__10CTeamChecki(uVar2);
      if (iVar1 != 0) {
        return true;
      }
    }
    bVar3 = false;
  }
  else {
    bVar3 = param_2 == *(int *)(param_1 + 0x120);
  }
  return bVar3;
}


