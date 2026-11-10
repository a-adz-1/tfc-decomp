// FindTeamSpawnPoint__11CBaseEntity  @ 001068c0
int * FindTeamSpawnPoint__11CBaseEntity(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)(&g_pLastSpawns)[*(int *)(param_1 + 0x120)];
  iVar3 = 0;
  do {
    piVar1 = (int *)UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                              (piVar1,"classname",
                               *(undefined4 *)(sTeamSpawnNames + *(int *)(param_1 + 0x120) * 4));
    if ((piVar1 == (int *)0x0) &&
       (piVar1 = (int *)UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                                  (0,"classname",
                                   *(undefined4 *)(sTeamSpawnNames + *(int *)(param_1 + 0x120) * 4))
       , piVar1 == (int *)0x0)) {
      piVar1 = (int *)FUN_001069a0();
      return piVar1;
    }
    if (0x1f < iVar3) {
      return piVar1;
    }
    iVar2 = IsSpawnPointValid__FR6Vector(*piVar1 + 8);
    if (iVar2 != 0) {
      if (*gpGlobals < cb_prematch_time) {
        return piVar1;
      }
      iVar2 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(piVar1,param_1,0);
      if (iVar2 != 0) {
        (&g_pLastSpawns)[*(int *)(param_1 + 0x120)] = piVar1;
        return piVar1;
      }
    }
    iVar3 = iVar3 + 1;
  } while( true );
}


