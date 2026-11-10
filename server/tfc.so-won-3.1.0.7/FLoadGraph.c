// FLoadGraph__6CGraphPc  @ 000c88dc
undefined4 FLoadGraph__6CGraphPc(int *param_1,char *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvVar5;
  char *pcVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int local_2004;
  char local_2000 [4096];
  char local_1000 [4];
  char local_ffc [4];
  char local_ff8 [4];
  char local_ff4;
  
  (*DAT_001c11ac)(local_2000);
  strcat(local_2000,"/maps");
  mkdir(local_2000,0x1ff);
  strcat(local_2000,"/graphs");
  mkdir(local_2000,0x1ff);
  local_1000[0] = 'm';
  local_1000[1] = 'a';
  local_1000[2] = 'p';
  local_1000[3] = 's';
  local_ffc[0] = '/';
  local_ffc[1] = 'g';
  local_ffc[2] = 'r';
  local_ffc[3] = 'a';
  local_ff8[0] = 'p';
  local_ff8[1] = 'h';
  local_ff8[2] = 's';
  local_ff8[3] = '/';
  local_ff4 = '\0';
  strcat(local_1000,param_2);
  strcat(local_1000,".nod");
  piVar2 = (int *)(*DAT_001c119c)(local_1000,&local_2004);
  if (piVar2 != (int *)0x0) {
    iVar3 = local_2004 + -4;
    if (-1 < iVar3) {
      if (*piVar2 != 0x10) {
        local_2004 = iVar3;
        (*DAT_001c1114)(2,"**ERROR** Graph version is %d, expected %d\n",*piVar2,0x10);
        uVar4 = FUN_000c8d14();
        return uVar4;
      }
      local_2004 = local_2004 + -0x20d0;
      iVar3 = local_2004;
      if (-1 < local_2004) {
        piVar9 = param_1;
        piVar7 = piVar2;
        for (iVar3 = 0x833; piVar7 = piVar7 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar9 = *piVar7;
          piVar9 = piVar9 + 1;
        }
        piVar7 = piVar2 + 0x834;
        param_1[3] = 0;
        param_1[4] = 0;
        param_1[9] = 0;
        param_1[5] = 0;
        param_1[0x82f] = 0;
        pvVar5 = calloc(0x58,param_1[6]);
        param_1[3] = (int)pvVar5;
        if (pvVar5 == (void *)0x0) {
          iVar3 = param_1[6];
          pcVar6 = "**ERROR**\nCouldn\'t malloc %d nodes!\n";
LAB_000c8c7c:
          (*DAT_001c1114)(2,pcVar6,iVar3);
          uVar4 = FUN_000c8d14();
          return uVar4;
        }
        local_2004 = local_2004 + param_1[6] * -0x58;
        iVar3 = local_2004;
        if (-1 < local_2004) {
          memcpy((void *)param_1[3],piVar7,param_1[6] * 0x58);
          piVar7 = piVar7 + param_1[6] * 0x16;
          pvVar5 = calloc(0x18,param_1[7]);
          param_1[4] = (int)pvVar5;
          if (pvVar5 == (void *)0x0) {
            iVar3 = param_1[7];
            pcVar6 = "**ERROR**\nCouldn\'t malloc %d link!\n";
            goto LAB_000c8c7c;
          }
          local_2004 = local_2004 + param_1[7] * -0x18;
          iVar3 = local_2004;
          if (-1 < local_2004) {
            memcpy((void *)param_1[4],piVar7,param_1[7] * 0x18);
            piVar7 = piVar7 + param_1[7] * 6;
            pvVar5 = calloc(0x10,param_1[6]);
            param_1[9] = (int)pvVar5;
            if (pvVar5 == (void *)0x0) {
              iVar3 = param_1[6];
              pcVar6 = "***ERROR**\nCouldn\'t malloc %d entries sorting nodes!\n";
              goto LAB_000c8c7c;
            }
            local_2004 = local_2004 + param_1[6] * -0x10;
            iVar3 = local_2004;
            if (-1 < local_2004) {
              memcpy((void *)param_1[9],piVar7,param_1[6] * 0x10);
              iVar1 = param_1[6];
              param_1[2] = 0;
              pvVar5 = calloc(1,param_1[8]);
              param_1[5] = (int)pvVar5;
              if (pvVar5 == (void *)0x0) {
                iVar3 = param_1[8];
                pcVar6 = "***ERROR**\nCounldn\'t malloc %d route bytes!\n";
                goto LAB_000c8c7c;
              }
              param_1[0x618] = 0;
              iVar3 = 0;
              if (0 < param_1[6]) {
                iVar8 = 0;
                do {
                  *(undefined4 *)(param_1[9] + 0xc + iVar8) = 0;
                  iVar8 = iVar8 + 0x10;
                  iVar3 = iVar3 + 1;
                } while (iVar3 < param_1[6]);
              }
              local_2004 = local_2004 - param_1[8];
              iVar3 = local_2004;
              if (-1 < local_2004) {
                memcpy((void *)param_1[5],piVar7 + iVar1 * 4,param_1[8]);
                iVar8 = param_1[8];
                param_1[2] = 1;
                pvVar5 = calloc(2,param_1[0x830]);
                param_1[0x82f] = (int)pvVar5;
                if (pvVar5 == (void *)0x0) {
                  iVar3 = param_1[0x830];
                  pcVar6 = "***ERROR**\nCounldn\'t malloc %d hash link bytes!\n";
                  goto LAB_000c8c7c;
                }
                local_2004 = local_2004 + param_1[0x830] * -2;
                iVar3 = local_2004;
                if (-1 < local_2004) {
                  memcpy((void *)param_1[0x82f],(void *)((int)(piVar7 + iVar1 * 4) + iVar8),
                         param_1[0x830] * 2);
                  *param_1 = 1;
                  param_1[1] = 0;
                  (*DAT_001c11a0)(piVar2);
                  if (local_2004 != 0) {
                    (*DAT_001c1114)(2,
                                    "***WARNING***:Node graph was longer than expected by %d bytes.!\n"
                                    ,local_2004);
                  }
                  return 1;
                }
              }
            }
          }
        }
      }
    }
    local_2004 = iVar3;
    (*DAT_001c11a0)(piVar2);
  }
  return 0;
}


