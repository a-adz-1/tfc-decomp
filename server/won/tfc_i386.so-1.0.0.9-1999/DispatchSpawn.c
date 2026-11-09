// DispatchSpawn__FP7edict_s  @ 000a0320
undefined4 DispatchSpawn__FP7edict_s(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if (param_1 == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = *(int **)(param_1 + 0xd8);
  }
  if (piVar5 != (int *)0x0) {
    iVar4 = *piVar5;
    iVar3 = *piVar5;
    fVar1 = *(float *)(iVar3 + 0xc);
    fVar2 = *(float *)(iVar3 + 0x10);
    *(float *)(iVar4 + 0xa4) = *(float *)(iVar3 + 8) - 1.0;
    *(float *)(iVar4 + 0xa8) = fVar1 - 1.0;
    *(float *)(iVar4 + 0xac) = fVar2 - 1.0;
    iVar4 = *piVar5;
    iVar3 = *piVar5;
    fVar1 = *(float *)(iVar3 + 0xc);
    fVar2 = *(float *)(iVar3 + 0x10);
    *(float *)(iVar4 + 0xb0) = *(float *)(iVar3 + 8) + 1.0;
    *(float *)(iVar4 + 0xb4) = fVar1 + 1.0;
    *(float *)(iVar4 + 0xb8) = fVar2 + 1.0;
    (**(code **)(piVar5[0xf2] + 8))(piVar5);
    if (param_1 == 0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = *(int **)(param_1 + 0xd8);
    }
    if (piVar5 != (int *)0x0) {
      if ((g_pGameRules != (int *)0x0) &&
         (iVar4 = (**(code **)(*g_pGameRules + 0x10))(g_pGameRules,piVar5), iVar4 == 0)) {
        return 0xffffffff;
      }
      if ((piVar5 != (int *)0x0) && (*(int *)(*piVar5 + 4) != 0)) {
        iVar4 = EntityFromTable__12CGlobalStatei(&gGlobalState,*(undefined4 *)(*piVar5 + 4));
        if (iVar4 == 0) {
          EntityAdd__12CGlobalStateii12GLOBALESTATE
                    (&gGlobalState,*(undefined4 *)(*piVar5 + 4),*(undefined4 *)(gpGlobals + 0xc),1);
        }
        else {
          if (*(int *)(iVar4 + 0x60) == 2) {
            return 0xffffffff;
          }
          iVar4 = strcmp((char *)(*(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98)),
                         (char *)(iVar4 + 0x40));
          if (iVar4 != 0) {
            MakeDormant__11CBaseEntity(piVar5);
          }
        }
      }
    }
  }
  return 0;
}


