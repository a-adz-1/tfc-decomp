// FindTeamSpawnPoint__11CBaseEntity  @ 000f7918
void FindTeamSpawnPoint__11CBaseEntity(int param_1)

{
  float fVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int local_4;
  
  piVar2 = (int *)(&g_pLastSpawns)[*(int *)(param_1 + 0x120)];
  local_4 = 0;
  iVar5 = 0;
  while( true ) {
    piVar2 = (int *)UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                              (piVar2,"classname",
                               *(undefined4 *)(sTeamSpawnNames + *(int *)(param_1 + 0x120) * 4));
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                                (0,"classname",
                                 *(undefined4 *)(sTeamSpawnNames + *(int *)(param_1 + 0x120) * 4));
      if (piVar2 == (int *)0x0) {
        FUN_000f7a68();
        return;
      }
    }
    if (0x7f < local_4) break;
    if (0x1f < iVar5) {
      pcVar3 = "warning: spawning player at potential telefrag spot\n";
      goto LAB_000f79d3;
    }
    if (piVar2[0x86] == 3) {
      local_4 = local_4 + 1;
    }
    else {
      iVar4 = IsSpawnPointValid__FR6Vector(*piVar2 + 8);
      if (iVar4 == 0) {
        iVar5 = iVar5 + 1;
      }
      else {
        fVar1 = *gpGlobals;
        if (0x3f < (byte)((cb_prematch_time < fVar1 |
                           (byte)((ushort)((ushort)(NAN(cb_prematch_time) || NAN(fVar1)) << 10) >> 8
                                 ) |
                          (byte)((ushort)((ushort)(cb_prematch_time == fVar1) << 0xe) >> 8)) - 1)) {
          FUN_000f7a68();
          return;
        }
        iVar4 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(piVar2,param_1,0);
        if (iVar4 != 0) {
          (&g_pLastSpawns)[*(int *)(param_1 + 0x120)] = piVar2;
          FUN_000f7a68();
          return;
        }
      }
    }
  }
  pcVar3 = "warning: spawning player at removed spawnpoint\n";
LAB_000f79d3:
  UTIL_LogPrintf__FPce(pcVar3);
  FUN_000f7a68();
  return;
}


