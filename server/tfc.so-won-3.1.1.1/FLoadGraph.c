// FLoadGraph__6CGraphPc  @ 000c835c
undefined4 FLoadGraph__6CGraphPc(int *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  void *pvVar6;
  char *pcVar7;
  int *piVar8;
  int *piVar9;
  int local_2010;
  int local_2008;
  char local_2004 [4096];
  char local_1004 [4];
  char local_1000 [4];
  char local_ffc [4];
  char local_ff8;
  
  (*DAT_0019f82c)(local_2004);
  strcat(local_2004,"/maps");
  mkdir(local_2004,0x1ff);
  strcat(local_2004,"/graphs");
  mkdir(local_2004,0x1ff);
  local_1004[0] = 'm';
  local_1004[1] = 'a';
  local_1004[2] = 'p';
  local_1004[3] = 's';
  local_1000[0] = '/';
  local_1000[1] = 'g';
  local_1000[2] = 'r';
  local_1000[3] = 'a';
  local_ffc[0] = 'p';
  local_ffc[1] = 'h';
  local_ffc[2] = 's';
  local_ffc[3] = '/';
  local_ff8 = '\0';
  strcat(local_1004,param_2);
  strcat(local_1004,".nod");
  piVar3 = (int *)(*DAT_0019f81c)(local_1004,&local_2008);
  if (piVar3 != (int *)0x0) {
    iVar4 = local_2008 + -4;
    if (-1 < iVar4) {
      if (*piVar3 != 0x10) {
        local_2008 = iVar4;
        (*DAT_0019f794)(2,"**ERROR** Graph version is %d, expected %d\n",*piVar3,0x10);
        uVar5 = FUN_000c8798();
        return uVar5;
      }
      local_2008 = local_2008 + -0x20d0;
      iVar4 = local_2008;
      if (-1 < local_2008) {
        piVar9 = param_1;
        piVar8 = piVar3;
        for (iVar4 = 0x833; piVar8 = piVar8 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
          *piVar9 = *piVar8;
          piVar9 = piVar9 + 1;
        }
        param_1[3] = 0;
        param_1[4] = 0;
        param_1[9] = 0;
        param_1[5] = 0;
        param_1[0x82f] = 0;
        piVar8 = piVar3 + 0x834;
        pvVar6 = calloc(0x58,param_1[6]);
        param_1[3] = (int)pvVar6;
        if (pvVar6 == (void *)0x0) {
          iVar4 = param_1[6];
          pcVar7 = "**ERROR**\nCouldn\'t malloc %d nodes!\n";
LAB_000c870a:
          (*DAT_0019f794)(2,pcVar7,iVar4);
          uVar5 = FUN_000c8798();
          return uVar5;
        }
        local_2008 = local_2008 + param_1[6] * -0x58;
        iVar4 = local_2008;
        if (-1 < local_2008) {
          memcpy(pvVar6,piVar8,param_1[6] * 0x58);
          piVar8 = piVar8 + param_1[6] * 0x16;
          pvVar6 = calloc(0x18,param_1[7]);
          param_1[4] = (int)pvVar6;
          if (pvVar6 == (void *)0x0) {
            iVar4 = param_1[7];
            pcVar7 = "**ERROR**\nCouldn\'t malloc %d link!\n";
            goto LAB_000c870a;
          }
          local_2008 = local_2008 + param_1[7] * -0x18;
          iVar4 = local_2008;
          if (-1 < local_2008) {
            memcpy(pvVar6,piVar8,param_1[7] * 0x18);
            piVar8 = piVar8 + param_1[7] * 6;
            pvVar6 = calloc(0x10,param_1[6]);
            param_1[9] = (int)pvVar6;
            if (pvVar6 == (void *)0x0) {
              iVar4 = param_1[6];
              pcVar7 = "***ERROR**\nCouldn\'t malloc %d entries sorting nodes!\n";
              goto LAB_000c870a;
            }
            local_2008 = local_2008 + param_1[6] * -0x10;
            iVar4 = local_2008;
            if (-1 < local_2008) {
              memcpy(pvVar6,piVar8,param_1[6] * 0x10);
              iVar1 = param_1[6];
              param_1[2] = 0;
              pvVar6 = calloc(1,param_1[8]);
              param_1[5] = (int)pvVar6;
              if (pvVar6 == (void *)0x0) {
                iVar4 = param_1[8];
                pcVar7 = "***ERROR**\nCounldn\'t malloc %d route bytes!\n";
                goto LAB_000c870a;
              }
              local_2010 = 0;
              param_1[0x618] = 0;
              for (; local_2010 < param_1[6]; local_2010 = local_2010 + 1) {
                *(undefined4 *)(param_1[9] + 0xc + local_2010 * 0x10) = 0;
              }
              local_2008 = local_2008 - param_1[8];
              iVar4 = local_2008;
              if (-1 < local_2008) {
                memcpy((void *)param_1[5],piVar8 + iVar1 * 4,param_1[8]);
                iVar2 = param_1[8];
                param_1[2] = 1;
                pvVar6 = calloc(2,param_1[0x830]);
                param_1[0x82f] = (int)pvVar6;
                if (pvVar6 == (void *)0x0) {
                  iVar4 = param_1[0x830];
                  pcVar7 = "***ERROR**\nCounldn\'t malloc %d hash link bytes!\n";
                  goto LAB_000c870a;
                }
                local_2008 = local_2008 + param_1[0x830] * -2;
                iVar4 = local_2008;
                if (-1 < local_2008) {
                  memcpy(pvVar6,(void *)((int)(piVar8 + iVar1 * 4) + iVar2),param_1[0x830] * 2);
                  *param_1 = 1;
                  param_1[1] = 0;
                  (*DAT_0019f820)(piVar3);
                  if (local_2008 != 0) {
                    (*DAT_0019f794)(2,
                                    "***WARNING***:Node graph was longer than expected by %d bytes.!\n"
                                    ,local_2008);
                  }
                  return 1;
                }
              }
            }
          }
        }
      }
    }
    local_2008 = iVar4;
    (*DAT_0019f820)(piVar3);
  }
  return 0;
}


