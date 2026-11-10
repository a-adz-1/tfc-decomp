// ReloadMapCycleFile__FPcP10mapcycle_s  @ 000aeaac
/* WARNING: Removing unreachable block (ram,0x000aeb59) */
/* WARNING: Removing unreachable block (ram,0x000aeb5b) */
/* WARNING: Removing unreachable block (ram,0x000aeb60) */
/* WARNING: Removing unreachable block (ram,0x000aeb64) */
/* WARNING: Removing unreachable block (ram,0x000aeb65) */
/* WARNING: Removing unreachable block (ram,0x000aeb69) */
/* WARNING: Removing unreachable block (ram,0x000aeb6a) */
/* WARNING: Removing unreachable block (ram,0x000aeb6e) */
/* WARNING: Removing unreachable block (ram,0x000aec1c) */
/* WARNING: Removing unreachable block (ram,0x000aec1e) */
/* WARNING: Removing unreachable block (ram,0x000aec23) */
/* WARNING: Removing unreachable block (ram,0x000aec27) */
/* WARNING: Removing unreachable block (ram,0x000aec28) */
/* WARNING: Removing unreachable block (ram,0x000aec2c) */
/* WARNING: Removing unreachable block (ram,0x000aec2d) */
/* WARNING: Removing unreachable block (ram,0x000aec31) */

undefined4 ReloadMapCycleFile__FPcP10mapcycle_s(undefined4 param_1,int *param_2)

{
  char cVar1;
  uint uVar2;
  bool bVar3;
  int *piVar4;
  uint *puVar5;
  char *pcVar6;
  uint *puVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  undefined4 uVar11;
  char *pcVar12;
  int *local_438;
  char *local_42c;
  int local_428;
  char local_424 [32];
  char local_404 [1024];
  
  pcVar6 = (char *)(*DAT_0019f81c)(param_1,&local_428);
  local_438 = (int *)0x0;
  if ((pcVar6 != (char *)0x0) && (local_428 != 0)) {
    local_42c = pcVar6;
LAB_000aeb18:
    bVar3 = false;
    memset(local_404,0,0x400);
    local_42c = (char *)COM_Parse__FPc(local_42c);
    puVar5 = (uint *)&com_token;
    do {
      puVar7 = puVar5;
      uVar2 = *puVar7;
      if ((char)uVar2 == '\0') goto LAB_000aeb91;
      if ((char)(uVar2 >> 8) == '\0') goto LAB_000aeb90;
      if ((uVar2 & 0xff0000) == 0) goto LAB_000aeb8f;
      puVar5 = puVar7 + 1;
    } while ((uVar2 & 0xff000000) != 0);
    puVar7 = (uint *)((int)puVar7 + 1);
LAB_000aeb8f:
    puVar7 = (uint *)((int)puVar7 + 1);
LAB_000aeb90:
    puVar7 = (uint *)((int)puVar7 + 1);
LAB_000aeb91:
    if (puVar7 != (uint *)&com_token) {
      strcpy(local_424,&com_token);
      cVar1 = *local_42c;
      pcVar12 = local_42c;
      while ((cVar1 != '\0' && (*pcVar12 != '\n'))) {
        iVar8 = isspace((int)*pcVar12);
        if ((iVar8 == 0) || (iVar8 = isalnum((int)*pcVar12), iVar8 != 0)) {
          local_42c = (char *)COM_Parse__FPc(local_42c);
          puVar5 = (uint *)&com_token;
          goto LAB_000aec32;
        }
        pcVar12 = pcVar12 + 1;
        cVar1 = *pcVar12;
      }
      goto LAB_000aec72;
    }
    (*DAT_0019f820)(pcVar6);
  }
  piVar9 = (int *)*param_2;
  while (piVar4 = piVar9, piVar4 != (int *)0x0) {
    piVar9 = (int *)*piVar4;
    *piVar4 = (int)local_438;
    local_438 = piVar4;
  }
  *param_2 = (int)local_438;
  if (local_438 == (int *)0x0) {
    uVar11 = 0;
  }
  else {
    for (; *local_438 != 0; local_438 = (int *)*local_438) {
    }
    iVar8 = *param_2;
    *local_438 = iVar8;
    param_2[1] = iVar8;
    uVar11 = 1;
  }
  return uVar11;
  while( true ) {
    if ((char)(uVar2 >> 8) == '\0') goto LAB_000aec53;
    if ((uVar2 & 0xff0000) == 0) goto LAB_000aec52;
    puVar5 = puVar7 + 1;
    if ((uVar2 & 0xff000000) == 0) break;
LAB_000aec32:
    puVar7 = puVar5;
    uVar2 = *puVar7;
    if ((char)uVar2 == '\0') goto LAB_000aec54;
  }
  puVar7 = (uint *)((int)puVar7 + 1);
LAB_000aec52:
  puVar7 = (uint *)((int)puVar7 + 1);
LAB_000aec53:
  puVar7 = (uint *)((int)puVar7 + 1);
LAB_000aec54:
  if (puVar7 != (uint *)&com_token) {
    bVar3 = true;
    strcpy(local_404,&com_token);
  }
LAB_000aec72:
  iVar8 = (*DAT_0019f858)(local_424);
  if (iVar8 == 0) {
    (*DAT_0019f794)(1,"Skipping %s from mapcycle, not a valid map\n",local_424);
  }
  else {
    piVar9 = (int *)__builtin_new(0x42c);
    strcpy((char *)(piVar9 + 1),local_424);
    piVar9[9] = 0;
    piVar9[10] = 0;
    memset(piVar9 + 0xb,0,0x400);
    if (bVar3) {
      pcVar12 = (char *)(*DAT_0019f84c)(local_404,"minplayers");
      if ((pcVar12 != (char *)0x0) && (*pcVar12 != '\0')) {
        iVar8 = __strtol_internal(pcVar12,0,10,0);
        piVar9[9] = iVar8;
        if (iVar8 < 0) {
          iVar8 = 0;
        }
        piVar9[9] = iVar8;
        iVar10 = *(int *)(gpGlobals + 0x90);
        if (iVar8 < *(int *)(gpGlobals + 0x90)) {
          iVar10 = iVar8;
        }
        piVar9[9] = iVar10;
      }
      pcVar12 = (char *)(*DAT_0019f84c)(local_404,"maxplayers");
      if ((pcVar12 != (char *)0x0) && (*pcVar12 != '\0')) {
        iVar8 = __strtol_internal(pcVar12,0,10,0);
        piVar9[10] = iVar8;
        if (iVar8 < 0) {
          iVar8 = 0;
        }
        piVar9[10] = iVar8;
        iVar10 = *(int *)(gpGlobals + 0x90);
        if (iVar8 < *(int *)(gpGlobals + 0x90)) {
          iVar10 = iVar8;
        }
        piVar9[10] = iVar10;
      }
      (*DAT_0019f878)(local_404,"minplayers");
      (*DAT_0019f878)(local_404,"maxplayers");
      strcpy((char *)(piVar9 + 0xb),local_404);
    }
    *piVar9 = *param_2;
    *param_2 = (int)piVar9;
  }
  goto LAB_000aeb18;
}


