// TestRoutingTables__6CGraph  @ 000bf8b4
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
  int *piStack_44;
  int *piStack_3c;
  int *piStack_38;
  int *piStack_34;
  int *piStack_30;
  float fStack_2c;
  float fStack_28;
  int iStack_1c;
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
            iStack_1c = 0;
LAB_000bfff4:
            if (iStack_1c < *(int *)(param_1 + 0x18)) {
              *(undefined4 *)(param_1 + 8) = 0;
              uVar3 = FindShortestPath__6CGraphPiiiii
                                (param_1,piVar1,local_18,iStack_1c,local_c,local_14);
              *(undefined4 *)(param_1 + 8) = 1;
              uVar4 = FindShortestPath__6CGraphPiiiii
                                (param_1,piVar2,local_18,iStack_1c,local_c,local_14);
              if (uVar4 == 10) goto LAB_000bfff0;
              fStack_28 = 0.0;
              iVar8 = 0;
              piStack_38 = piVar1;
              piStack_3c = piVar1;
              if (0 < (int)(uVar3 - 1)) {
                do {
                  piStack_3c = piStack_3c + 1;
                  iVar6 = *piStack_38;
                  if (iVar6 != *piStack_3c) {
                    iVar5 = 0;
                    iVar9 = *(int *)(param_1 + 0xc);
                    if (0 < *(int *)(iVar9 + 0x20 + iVar6 * 0x58)) {
                      do {
                        if (*(int *)(*(int *)(param_1 + 0x10) + 4 +
                                    (*(int *)(iVar9 + 0x24 + iVar6 * 0x58) + iVar5) * 0x18) ==
                            *piStack_3c) {
                          fStack_28 = fStack_28 +
                                      *(float *)(*(int *)(param_1 + 0x10) + 0x14 +
                                                (iVar5 + *(int *)(iVar9 + 0x24 + iVar6 * 0x58)) *
                                                0x18);
                          goto LAB_000bfadd;
                        }
                        iVar5 = iVar5 + 1;
                        iVar6 = *piStack_38;
                        iVar9 = *(int *)(param_1 + 0xc);
                      } while (iVar5 < *(int *)(iVar9 + 0x20 + iVar6 * 0x58));
                    }
                    (*DAT_001a7f34)(2,"No link.\n");
                  }
LAB_000bfadd:
                  iVar8 = iVar8 + 1;
                  piStack_38 = piStack_38 + 1;
                } while (iVar8 < (int)(uVar3 - 1));
              }
              fStack_2c = 0.0;
              iVar8 = 0;
              piStack_30 = piVar2;
              piStack_34 = piVar2;
              if (0 < (int)(uVar4 - 1)) {
                do {
                  piStack_34 = piStack_34 + 1;
                  iVar6 = *piStack_30;
                  if (iVar6 != *piStack_34) {
                    iVar5 = 0;
                    iVar9 = *(int *)(param_1 + 0xc);
                    if (0 < *(int *)(iVar9 + 0x20 + iVar6 * 0x58)) {
                      do {
                        if (*(int *)(*(int *)(param_1 + 0x10) + 4 +
                                    (*(int *)(iVar9 + 0x24 + iVar6 * 0x58) + iVar5) * 0x18) ==
                            *piStack_34) {
                          fStack_2c = fStack_2c +
                                      *(float *)(*(int *)(param_1 + 0x10) + 0x14 +
                                                (iVar5 + *(int *)(iVar9 + 0x24 + iVar6 * 0x58)) *
                                                0x18);
                          goto LAB_000bfbd1;
                        }
                        iVar5 = iVar5 + 1;
                        iVar6 = *piStack_30;
                        iVar9 = *(int *)(param_1 + 0xc);
                      } while (iVar5 < *(int *)(iVar9 + 0x20 + iVar6 * 0x58));
                    }
                    (*DAT_001a7f34)(2,"No link.\n");
                  }
LAB_000bfbd1:
                  iVar8 = iVar8 + 1;
                  piStack_30 = piStack_30 + 1;
                } while (iVar8 < (int)(uVar4 - 1));
              }
              if (ABS(fStack_28 - fStack_2c) <= 0.1) goto LAB_000bfff0;
              (*DAT_001a7f34)(2,"Routing is inconsistent!!!\n");
              (*DAT_001a7f34)(2,"(%d to %d |%d/%d)1:",local_18,iStack_1c,local_c,local_10);
              iVar8 = 0;
              if (0 < (int)uVar3) {
                uVar7 = uVar3 & 3;
                piStack_44 = piVar1;
                if (uVar7 == 0) goto LAB_000bfd14;
                if (1 < uVar7) {
                  if (2 < uVar7) {
                    (*DAT_001a7f34)(2,&UNK_00139435,*piVar1);
                    piStack_44 = piVar1 + 1;
                  }
                  (*DAT_001a7f34)(2,&UNK_00139435,*piStack_44);
                  piStack_44 = piStack_44 + 1;
                  iVar8 = (2 < uVar7) + 1;
                }
                (*DAT_001a7f34)(2,&UNK_00139435,*piStack_44);
                piStack_44 = piStack_44 + 1;
                for (iVar8 = iVar8 + 1; iVar8 < (int)uVar3; iVar8 = iVar8 + 4) {
LAB_000bfd14:
                  (*DAT_001a7f34)(2,&UNK_00139435,*piStack_44);
                  (*DAT_001a7f34)(2,&UNK_00139435,piStack_44[1]);
                  (*DAT_001a7f34)(2,&UNK_00139435,piStack_44[2]);
                  (*DAT_001a7f34)(2,&UNK_00139435,piStack_44[3]);
                  piStack_44 = piStack_44 + 4;
                }
              }
              (*DAT_001a7f34)(2,"\n(%d to %d |%d/%d)2:",local_18,iStack_1c,local_c,local_10);
              iVar8 = 0;
              if (0 < (int)uVar4) {
                uVar3 = uVar4 & 3;
                piStack_44 = piVar2;
                if (uVar3 != 0) {
                  if (1 < uVar3) {
                    if (2 < uVar3) {
                      (*DAT_001a7f34)(2,&UNK_00139435,*piVar2);
                      piStack_44 = piVar2 + 1;
                    }
                    (*DAT_001a7f34)(2,&UNK_00139435,*piStack_44);
                    piStack_44 = piStack_44 + 1;
                    iVar8 = (2 < uVar3) + 1;
                  }
                  (*DAT_001a7f34)(2,&UNK_00139435,*piStack_44);
                  piStack_44 = piStack_44 + 1;
                  iVar8 = iVar8 + 1;
                  if ((int)uVar4 <= iVar8) goto LAB_000bff57;
                }
                do {
                  (*DAT_001a7f34)(2,&UNK_00139435,*piStack_44);
                  (*DAT_001a7f34)(2,&UNK_00139435,piStack_44[1]);
                  (*DAT_001a7f34)(2,&UNK_00139435,piStack_44[2]);
                  (*DAT_001a7f34)(2,&UNK_00139435,piStack_44[3]);
                  iVar8 = iVar8 + 4;
                  piStack_44 = piStack_44 + 4;
                } while (iVar8 < (int)uVar4);
              }
LAB_000bff57:
              (*DAT_001a7f34)(2,&DAT_00138990);
              *(undefined4 *)(param_1 + 8) = 0;
              FindShortestPath__6CGraphPiiiii(param_1,piVar1,local_18,iStack_1c,local_c,local_14);
              *(undefined4 *)(param_1 + 8) = 1;
              FindShortestPath__6CGraphPiiiii(param_1,piVar2,local_18,iStack_1c,local_c,local_14);
              goto LAB_000c003e;
            }
          }
          local_10 = local_10 + 1;
        } while (local_10 < 2);
        local_c = local_c + 1;
      } while (local_c < 4);
    }
LAB_000c003e:
    if (piVar1 != (int *)0x0) {
      __builtin_delete(piVar1);
    }
  }
  if (piVar2 != (int *)0x0) {
    __builtin_delete(piVar2);
  }
  return;
LAB_000bfff0:
  iStack_1c = iStack_1c + 1;
  goto LAB_000bfff4;
}


