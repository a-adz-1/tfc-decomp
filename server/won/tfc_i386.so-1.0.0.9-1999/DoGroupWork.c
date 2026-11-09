// DoGroupWork__FP11CBaseEntityP11CBasePlayer  @ 0010b120
void DoGroupWork__FP11CBaseEntityP11CBasePlayer(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x370) != 0) {
    if (*(int *)(param_1 + 0x38) == 0) {
      (*DAT_001755b4)(1,"Goal %d has .all_active specified, but no .last_impulse\n",
                      *(undefined4 *)(param_1 + 0x210));
    }
    else {
      bVar1 = true;
      iVar2 = 0;
      while (iVar2 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar2,"info_tfgoal"), iVar2 != 0
            ) {
        if (!bVar1) goto LAB_0010b1cb;
        if ((*(int *)(iVar2 + 0x214) == *(int *)(param_1 + 0x370)) && (*(int *)(iVar2 + 0x218) != 1)
           ) {
          bVar1 = false;
        }
      }
      if ((bVar1) && (iVar2 = Findgoal__Fi(*(undefined4 *)(param_1 + 0x38)), iVar2 != 0)) {
        DoResults__FP11CBaseEntityP11CBasePlayeri(iVar2,param_2,*(uint *)(param_1 + 0x228) & 2);
      }
    }
  }
LAB_0010b1cb:
  if (*(int *)(param_1 + 0x264) != 0) {
    iVar2 = 0;
    while (iVar2 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar2,"info_tfgoal"), iVar2 != 0)
    {
      if (*(int *)(iVar2 + 0x214) == *(int *)(param_1 + 0x264)) {
        ActivateDoResults__FP11CBaseEntityP11CBasePlayerT0(iVar2,param_2,param_1);
      }
    }
  }
  if (*(int *)(param_1 + 0x268) != 0) {
    iVar2 = 0;
    while (iVar2 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar2,"info_tfgoal"), iVar2 != 0)
    {
      if (*(int *)(iVar2 + 0x214) == *(int *)(param_1 + 0x268)) {
        InactivateGoal__FP11CBaseEntity(iVar2);
      }
    }
  }
  if (*(int *)(param_1 + 0x26c) != 0) {
    iVar2 = 0;
    while (iVar2 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar2,"info_tfgoal"), iVar2 != 0)
    {
      if (*(int *)(iVar2 + 0x214) == *(int *)(param_1 + 0x26c)) {
        RemoveGoal__FP11CBaseEntity(iVar2);
      }
    }
  }
  if (*(int *)(param_1 + 0x270) != 0) {
    iVar2 = 0;
    while (iVar2 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar2,"info_tfgoal"), iVar2 != 0)
    {
      if (*(int *)(iVar2 + 0x214) == *(int *)(param_1 + 0x270)) {
        RestoreGoal__FP11CBaseEntity(iVar2);
      }
    }
  }
  return;
}


