// FindTeamSpawnPoint__11CBaseEntity  @ 0010774c
int * FindTeamSpawnPoint__11CBaseEntity(int param_1)

{
  int *piVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  piVar1 = (int *)(&g_pLastSpawns)[*(int *)(param_1 + 0x120)];
  while( true ) {
    do {
      piVar1 = (int *)UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                                (piVar1,"classname","info_player_teamspawn");
      if ((piVar1 == (int *)0x0) &&
         (piVar1 = (int *)UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                                    (0,"classname","info_player_teamspawn"), piVar1 == (int *)0x0))
      {
        return (int *)0x0;
      }
      iVar2 = CheckTeam__8CTFSpawni(piVar1,*(undefined4 *)(param_1 + 0x120));
    } while (iVar2 == 0);
    if (0x7f < local_8) {
      return piVar1;
    }
    if (0x1f < local_c) break;
    if (piVar1[0x86] == 3) {
      local_8 = local_8 + 1;
    }
    else {
      iVar2 = IsSpawnPointValid__FR6Vector(*piVar1 + 8);
      if (iVar2 == 0) {
        local_c = local_c + 1;
      }
      else {
        if (*gpGlobals < cb_prematch_time) {
          return piVar1;
        }
        iVar2 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(piVar1,param_1,0);
        if (iVar2 != 0) {
          (&g_pLastSpawns)[*(int *)(param_1 + 0x120)] = piVar1;
          return piVar1;
        }
      }
    }
  }
  return piVar1;
}


