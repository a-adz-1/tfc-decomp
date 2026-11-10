// FindTeamSpawnPoint__11CBaseEntity  @ 0010547c
void FindTeamSpawnPoint__11CBaseEntity(int param_1)

{
  int *piVar1;
  int iVar2;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(g_pLastSpawns + *(int *)(param_1 + 0x120) * 4);
  local_4 = 0;
  local_8 = 0;
  do {
    while( true ) {
      while( true ) {
        do {
          piVar1 = (int *)UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                                    (piVar1,"classname","info_player_teamspawn");
          if (piVar1 == (int *)0x0) {
            piVar1 = (int *)UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                                      (0,"classname","info_player_teamspawn");
            if (piVar1 == (int *)0x0) {
              FUN_00105598();
              return;
            }
          }
          iVar2 = CheckTeam__8CTFSpawni(piVar1,*(undefined4 *)(param_1 + 0x120));
        } while (iVar2 == 0);
        if ((0x7f < local_4) || (0x1f < local_8)) goto LAB_00105587;
        if (piVar1[0x86] != 3) break;
        local_4 = local_4 + 1;
      }
      iVar2 = IsSpawnPointValid__FR6Vector(*piVar1 + 8);
      if (iVar2 != 0) break;
      local_8 = local_8 + 1;
    }
    if (*gpGlobals < cb_prematch_time) goto LAB_00105587;
    iVar2 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(piVar1,param_1,0);
  } while (iVar2 == 0);
  *(int **)(g_pLastSpawns + *(int *)(param_1 + 0x120) * 4) = piVar1;
LAB_00105587:
  FUN_00105598();
  return;
}


