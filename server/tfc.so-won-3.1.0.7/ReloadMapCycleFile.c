// ReloadMapCycleFile__FPcP10mapcycle_s  @ 000affd8
undefined4 ReloadMapCycleFile__FPcP10mapcycle_s(undefined4 param_1,int *param_2)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int *local_434;
  int local_428;
  int local_424;
  char acStack_420 [32];
  char local_400 [1024];
  
  iVar4 = (*DAT_001c119c)(param_1,&local_424);
  local_434 = (int *)0x0;
  if ((iVar4 != 0) && (local_424 != 0)) {
    local_428 = iVar4;
LAB_000b0044:
    bVar2 = false;
    memset(local_400,0,0x400);
    local_428 = COM_Parse__FPc(local_428);
    iVar8 = -1;
    pcVar6 = &com_token;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    if (iVar8 != -2) {
      strcpy(acStack_420,&com_token);
      iVar8 = COM_TokenWaiting__FPc(local_428);
      if (iVar8 != 0) {
        local_428 = COM_Parse__FPc(local_428);
        iVar8 = -1;
        pcVar6 = &com_token;
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        if (iVar8 != -2) {
          bVar2 = true;
          strcpy(local_400,&com_token);
        }
      }
      iVar8 = (*DAT_001c11d8)(acStack_420);
      if (iVar8 == 0) {
        (*DAT_001c1114)(1,"Skipping %s from mapcycle, not a valid map\n",acStack_420);
      }
      else {
        piVar5 = (int *)__builtin_new(0x42c);
        strcpy((char *)(piVar5 + 1),acStack_420);
        piVar5[9] = 0;
        piVar5[10] = 0;
        memset(piVar5 + 0xb,0,0x400);
        if (bVar2) {
          pcVar6 = (char *)(*DAT_001c11cc)(local_400,"minplayers");
          if ((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) {
            iVar8 = __strtol_internal(pcVar6,0,10,0);
            piVar5[9] = iVar8;
            if (iVar8 < 0) {
              iVar8 = 0;
            }
            piVar5[9] = iVar8;
            iVar9 = *(int *)(gpGlobals + 0x90);
            if (iVar8 < *(int *)(gpGlobals + 0x90)) {
              iVar9 = iVar8;
            }
            piVar5[9] = iVar9;
          }
          pcVar6 = (char *)(*DAT_001c11cc)(local_400,"maxplayers");
          if ((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) {
            iVar8 = __strtol_internal(pcVar6,0,10,0);
            piVar5[10] = iVar8;
            if (iVar8 < 0) {
              iVar8 = 0;
            }
            piVar5[10] = iVar8;
            iVar9 = *(int *)(gpGlobals + 0x90);
            if (iVar8 < *(int *)(gpGlobals + 0x90)) {
              iVar9 = iVar8;
            }
            piVar5[10] = iVar9;
          }
          (*pcRam001c11f8)(local_400,"minplayers");
          (*pcRam001c11f8)(local_400,"maxplayers");
          strcpy((char *)(piVar5 + 0xb),local_400);
        }
        *piVar5 = *param_2;
        *param_2 = (int)piVar5;
      }
      goto LAB_000b0044;
    }
    (*DAT_001c11a0)(iVar4);
  }
  piVar5 = (int *)*param_2;
  while (piVar3 = piVar5, piVar3 != (int *)0x0) {
    piVar5 = (int *)*piVar3;
    *piVar3 = (int)local_434;
    local_434 = piVar3;
  }
  *param_2 = (int)local_434;
  if (local_434 == (int *)0x0) {
    uVar7 = 0;
  }
  else {
    for (; *local_434 != 0; local_434 = (int *)*local_434) {
    }
    iVar4 = *param_2;
    *local_434 = iVar4;
    param_2[1] = iVar4;
    uVar7 = 1;
  }
  return uVar7;
}


