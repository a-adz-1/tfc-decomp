// TestRoutingTables__6CGraph  @ 000cab94
void TestRoutingTables__6CGraph(int param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *local_44;
  int *local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  float local_2c;
  float local_28;
  int local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  
  piVar1 = (int *)__builtin_vec_new(*(int *)(param_1 + 0x18) << 2);
  piVar2 = (int *)__builtin_vec_new(*(int *)(param_1 + 0x18) << 2);
  if (piVar1 != (int *)0x0) {
    if (piVar2 != (int *)0x0) {
      local_c = 0;
      do {
        local_10 = 0;
        do {
          if (local_10 == 0) {
            local_14 = 0;
          }
          else if (local_10 == 1) {
            local_14 = 0x340;
          }
          for (local_18 = 0; local_18 < *(int *)(param_1 + 0x18); local_18 = local_18 + 1) {
            local_1c = 0;
LAB_000cb2d4:
            if (local_1c < *(int *)(param_1 + 0x18)) {
              *(undefined4 *)(param_1 + 8) = 0;
              uVar3 = FindShortestPath__6CGraphPiiiii
                                (param_1,piVar1,local_18,local_1c,local_c,local_14);
              *(undefined4 *)(param_1 + 8) = 1;
              uVar4 = FindShortestPath__6CGraphPiiiii
                                (param_1,piVar2,local_18,local_1c,local_c,local_14);
              if (uVar4 == 10) goto LAB_000cb2d0;
              local_28 = 0.0;
              iVar8 = 0;
              local_38 = piVar1;
              local_3c = piVar1;
              if (0 < (int)(uVar3 - 1)) {
                do {
                  local_3c = local_3c + 1;
                  iVar6 = *local_38;
                  if (iVar6 != *local_3c) {
                    iVar5 = 0;
                    iVar9 = *(int *)(param_1 + 0xc);
                    if (0 < *(int *)(iVar9 + 0x20 + iVar6 * 0x58)) {
                      do {
                        if (*(int *)(*(int *)(param_1 + 0x10) + 4 +
                                    (*(int *)(iVar9 + 0x24 + iVar6 * 0x58) + iVar5) * 0x18) ==
                            *local_3c) {
                          local_28 = local_28 +
                                     *(float *)(*(int *)(param_1 + 0x10) + 0x14 +
                                               (iVar5 + *(int *)(iVar9 + 0x24 + iVar6 * 0x58)) *
                                               0x18);
                          goto LAB_000cadbd;
                        }
                        iVar5 = iVar5 + 1;
                        iVar6 = *local_38;
                        iVar9 = *(int *)(param_1 + 0xc);
                      } while (iVar5 < *(int *)(iVar9 + 0x20 + iVar6 * 0x58));
                    }
                    (*DAT_001c1114)(2,"No link.\n");
                  }
LAB_000cadbd:
                  iVar8 = iVar8 + 1;
                  local_38 = local_38 + 1;
                } while (iVar8 < (int)(uVar3 - 1));
              }
              local_2c = 0.0;
              iVar8 = 0;
              local_30 = piVar2;
              local_34 = piVar2;
              if (0 < (int)(uVar4 - 1)) {
                do {
                  local_34 = local_34 + 1;
                  iVar6 = *local_30;
                  if (iVar6 != *local_34) {
                    iVar5 = 0;
                    iVar9 = *(int *)(param_1 + 0xc);
                    if (0 < *(int *)(iVar9 + 0x20 + iVar6 * 0x58)) {
                      do {
                        if (*(int *)(*(int *)(param_1 + 0x10) + 4 +
                                    (*(int *)(iVar9 + 0x24 + iVar6 * 0x58) + iVar5) * 0x18) ==
                            *local_34) {
                          local_2c = local_2c +
                                     *(float *)(*(int *)(param_1 + 0x10) + 0x14 +
                                               (iVar5 + *(int *)(iVar9 + 0x24 + iVar6 * 0x58)) *
                                               0x18);
                          goto LAB_000caeb1;
                        }
                        iVar5 = iVar5 + 1;
                        iVar6 = *local_30;
                        iVar9 = *(int *)(param_1 + 0xc);
                      } while (iVar5 < *(int *)(iVar9 + 0x20 + iVar6 * 0x58));
                    }
                    (*DAT_001c1114)(2,"No link.\n");
                  }
LAB_000caeb1:
                  iVar8 = iVar8 + 1;
                  local_30 = local_30 + 1;
                } while (iVar8 < (int)(uVar4 - 1));
              }
              if (ABS(local_28 - local_2c) <= 0.1) goto LAB_000cb2d0;
              (*DAT_001c1114)(2,"Routing is inconsistent!!!\n");
              (*DAT_001c1114)(2,"(%d to %d |%d/%d)1:",local_18,local_1c,local_c,local_10);
              iVar8 = 0;
              if (0 < (int)uVar3) {
                uVar7 = uVar3 & 3;
                local_44 = piVar1;
                if (uVar7 == 0) goto LAB_000caff4;
                if (1 < uVar7) {
                  if (2 < uVar7) {
                    (*DAT_001c1114)(2,&DAT_00149d75,*piVar1);
                    local_44 = piVar1 + 1;
                  }
                  (*DAT_001c1114)(2,&DAT_00149d75,*local_44);
                  local_44 = local_44 + 1;
                  iVar8 = (2 < uVar7) + 1;
                }
                (*DAT_001c1114)(2,&DAT_00149d75,*local_44);
                local_44 = local_44 + 1;
                for (iVar8 = iVar8 + 1; iVar8 < (int)uVar3; iVar8 = iVar8 + 4) {
LAB_000caff4:
                  (*DAT_001c1114)(2,&DAT_00149d75,*local_44);
                  (*DAT_001c1114)(2,&DAT_00149d75,local_44[1]);
                  (*DAT_001c1114)(2,&DAT_00149d75,local_44[2]);
                  (*DAT_001c1114)(2,&DAT_00149d75,local_44[3]);
                  local_44 = local_44 + 4;
                }
              }
              (*DAT_001c1114)(2,"\n(%d to %d |%d/%d)2:",local_18,local_1c,local_c,local_10);
              iVar8 = 0;
              if (0 < (int)uVar4) {
                uVar3 = uVar4 & 3;
                local_44 = piVar2;
                if (uVar3 != 0) {
                  if (1 < uVar3) {
                    if (2 < uVar3) {
                      (*DAT_001c1114)(2,&DAT_00149d75,*piVar2);
                      local_44 = piVar2 + 1;
                    }
                    (*DAT_001c1114)(2,&DAT_00149d75,*local_44);
                    local_44 = local_44 + 1;
                    iVar8 = (2 < uVar3) + 1;
                  }
                  (*DAT_001c1114)(2,&DAT_00149d75,*local_44);
                  local_44 = local_44 + 1;
                  iVar8 = iVar8 + 1;
                  if ((int)uVar4 <= iVar8) goto LAB_000cb237;
                }
                do {
                  (*DAT_001c1114)(2,&DAT_00149d75,*local_44);
                  (*DAT_001c1114)(2,&DAT_00149d75,local_44[1]);
                  (*DAT_001c1114)(2,&DAT_00149d75,local_44[2]);
                  (*DAT_001c1114)(2,&DAT_00149d75,local_44[3]);
                  iVar8 = iVar8 + 4;
                  local_44 = local_44 + 4;
                } while (iVar8 < (int)uVar4);
              }
LAB_000cb237:
              (*DAT_001c1114)(2,&DAT_001492d0);
              *(undefined4 *)(param_1 + 8) = 0;
              FindShortestPath__6CGraphPiiiii(param_1,piVar1,local_18,local_1c,local_c,local_14);
              *(undefined4 *)(param_1 + 8) = 1;
              FindShortestPath__6CGraphPiiiii(param_1,piVar2,local_18,local_1c,local_c,local_14);
              goto FUN_000cb31e;
            }
          }
          local_10 = local_10 + 1;
        } while (local_10 < 2);
        local_c = local_c + 1;
      } while (local_c < 4);
    }
FUN_000cb31e:
    if (piVar1 != (int *)0x0) {
      __builtin_delete(piVar1);
    }
  }
  if (piVar2 != (int *)0x0) {
    __builtin_delete(piVar2);
  }
  return;
LAB_000cb2d0:
  local_1c = local_1c + 1;
  goto LAB_000cb2d4;
}


