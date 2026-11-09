// FLoadGraph__6CGraphPc  @ 000cd890
undefined4 FLoadGraph__6CGraphPc(int *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  void *pvVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  char *pcVar9;
  int local_808;
  char local_804 [1024];
  char local_404 [1024];
  
  (*DAT_0017564c)(local_804);
  strcat(local_804,"/maps");
  mkdir(local_804,0x1ff);
  strcat(local_804,"/graphs");
  mkdir(local_804,0x1ff);
  builtin_strncpy(local_404,"maps/graphs/",0xd);
  strcat(local_404,param_2);
  strcat(local_404,".nod");
  piVar3 = (int *)(*DAT_0017563c)(local_404,&local_808);
  if (piVar3 != (int *)0x0) {
    iVar6 = local_808 + -4;
    if (-1 < iVar6) {
      if (*piVar3 != 0x10) {
        local_808 = iVar6;
        (*DAT_001755b4)(2,"**ERROR** Graph version is %d, expected %d\n",*piVar3,0x10);
        uVar4 = FUN_000cdc50();
        return uVar4;
      }
      local_808 = local_808 + -0x20d0;
      iVar6 = local_808;
      if (-1 < local_808) {
        piVar8 = param_1;
        piVar7 = piVar3;
        for (iVar6 = 0x833; piVar7 = piVar7 + 1, iVar6 != 0; iVar6 = iVar6 + -1) {
          *piVar8 = *piVar7;
          piVar8 = piVar8 + 1;
        }
        piVar7 = piVar3 + 0x834;
        param_1[3] = 0;
        param_1[4] = 0;
        param_1[9] = 0;
        param_1[5] = 0;
        param_1[0x82f] = 0;
        pvVar5 = calloc(0x58,param_1[6]);
        param_1[3] = (int)pvVar5;
        if (pvVar5 == (void *)0x0) {
          iVar6 = param_1[6];
          pcVar9 = "**ERROR**\nCouldn\'t malloc %d nodes!\n";
LAB_000cdbb4:
          (*DAT_001755b4)(2,pcVar9,iVar6);
          uVar4 = FUN_000cdc50();
          return uVar4;
        }
        local_808 = local_808 + param_1[6] * -0x58;
        iVar6 = local_808;
        if (-1 < local_808) {
          memcpy((void *)param_1[3],piVar7,param_1[6] * 0x58);
          piVar7 = piVar7 + param_1[6] * 0x16;
          pvVar5 = calloc(0x18,param_1[7]);
          param_1[4] = (int)pvVar5;
          if (pvVar5 == (void *)0x0) {
            iVar6 = param_1[7];
            pcVar9 = "**ERROR**\nCouldn\'t malloc %d link!\n";
            goto LAB_000cdbb4;
          }
          local_808 = local_808 + param_1[7] * -0x18;
          iVar6 = local_808;
          if (-1 < local_808) {
            memcpy((void *)param_1[4],piVar7,param_1[7] * 0x18);
            piVar7 = piVar7 + param_1[7] * 6;
            pvVar5 = calloc(0x10,param_1[6]);
            param_1[9] = (int)pvVar5;
            if (pvVar5 == (void *)0x0) {
              iVar6 = param_1[6];
              pcVar9 = "***ERROR**\nCouldn\'t malloc %d entries sorting nodes!\n";
              goto LAB_000cdbb4;
            }
            local_808 = local_808 + param_1[6] * -0x10;
            iVar6 = local_808;
            if (-1 < local_808) {
              memcpy((void *)param_1[9],piVar7,param_1[6] << 4);
              iVar1 = param_1[6];
              param_1[2] = 0;
              pvVar5 = calloc(1,param_1[8]);
              param_1[5] = (int)pvVar5;
              if (pvVar5 == (void *)0x0) {
                iVar6 = param_1[8];
                pcVar9 = "***ERROR**\nCounldn\'t malloc %d route bytes!\n";
                goto LAB_000cdbb4;
              }
              param_1[0x618] = 0;
              iVar6 = 0;
              if (0 < param_1[6]) {
                do {
                  *(undefined4 *)(param_1[9] + 0xc + iVar6 * 0x10) = 0;
                  iVar6 = iVar6 + 1;
                } while (iVar6 < param_1[6]);
              }
              local_808 = local_808 - param_1[8];
              iVar6 = local_808;
              if (-1 < local_808) {
                memcpy((void *)param_1[5],piVar7 + iVar1 * 4,param_1[8]);
                iVar2 = param_1[8];
                param_1[2] = 1;
                pvVar5 = calloc(2,param_1[0x830]);
                param_1[0x82f] = (int)pvVar5;
                if (pvVar5 == (void *)0x0) {
                  iVar6 = param_1[0x830];
                  pcVar9 = "***ERROR**\nCounldn\'t malloc %d hash link bytes!\n";
                  goto LAB_000cdbb4;
                }
                local_808 = local_808 + param_1[0x830] * -2;
                iVar6 = local_808;
                if (-1 < local_808) {
                  memcpy((void *)param_1[0x82f],(void *)((int)(piVar7 + iVar1 * 4) + iVar2),
                         param_1[0x830] * 2);
                  *param_1 = 1;
                  param_1[1] = 0;
                  (*DAT_00175640)(piVar3);
                  if (local_808 != 0) {
                    (*DAT_001755b4)(2,
                                    "***WARNING***:Node graph was longer than expected by %d bytes.!\n"
                                    ,local_808);
                  }
                  return 1;
                }
              }
            }
          }
        }
      }
    }
    local_808 = iVar6;
    (*DAT_00175640)(piVar3);
  }
  return 0;
}


