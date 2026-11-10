// TestRoutingTables__6CGraph  @ 000c9fa4
void TestRoutingTables__6CGraph(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iStack_2c;
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  int local_10;
  
  iVar6 = __builtin_vec_new(*(int *)(param_1 + 0x18) << 2);
  iVar7 = __builtin_vec_new(*(int *)(param_1 + 0x18) << 2);
  if (iVar6 != 0) {
    if (iVar7 != 0) {
      local_10 = 0;
      iVar8 = *(int *)(param_1 + 0x18);
      do {
        iStack_14 = 0;
        do {
          if (iStack_14 == 0) {
            uStack_18 = 0;
          }
          else if (iStack_14 == 1) {
            uStack_18 = 0x340;
          }
          for (iStack_1c = 0; iStack_1c < iVar8; iStack_1c = iStack_1c + 1) {
            iStack_20 = 0;
            if (0 < iVar8) {
LAB_000ca048:
              *(undefined4 *)(param_1 + 8) = 0;
              iVar8 = FindShortestPath__6CGraphPiiiii
                                (param_1,iVar6,iStack_1c,iStack_20,local_10,uStack_18);
              *(undefined4 *)(param_1 + 8) = 1;
              iVar9 = FindShortestPath__6CGraphPiiiii
                                (param_1,iVar7,iStack_1c,iStack_20,local_10,uStack_18);
              if (iVar9 == 10) goto LAB_000ca388;
              fVar4 = 0.0;
              iStack_2c = 0;
              if (0 < iVar8 + -1) {
                do {
                  iVar11 = *(int *)(iVar6 + iStack_2c * 4);
                  iVar1 = *(int *)(iVar6 + 4 + iStack_2c * 4);
                  if (iVar11 != iVar1) {
                    iVar10 = 0;
                    iVar11 = iVar11 * 0x58;
                    iVar2 = *(int *)(param_1 + 0xc);
                    iVar3 = *(int *)(iVar2 + 0x20 + iVar11);
                    if (0 < iVar3) {
                      do {
                        if (*(int *)(*(int *)(param_1 + 0x10) + 4 +
                                    (*(int *)(iVar11 + 0x24 + iVar2) + iVar10) * 0x18) == iVar1) {
                          fVar4 = fVar4 + *(float *)(*(int *)(param_1 + 0x10) + 0x14 +
                                                    (iVar10 + *(int *)(iVar2 + 0x24 + iVar11)) *
                                                    0x18);
                          goto LAB_000ca160;
                        }
                        iVar10 = iVar10 + 1;
                      } while (iVar10 < iVar3);
                    }
                    (*DAT_0019f794)(2,"No link.\n");
                  }
LAB_000ca160:
                  iStack_2c = iStack_2c + 1;
                } while (iStack_2c < iVar8 + -1);
              }
              fVar5 = 0.0;
              iStack_2c = 0;
              if (0 < iVar9 + -1) {
                do {
                  iVar11 = *(int *)(iVar7 + iStack_2c * 4);
                  iVar1 = *(int *)(iVar7 + 4 + iStack_2c * 4);
                  if (iVar11 != iVar1) {
                    iVar10 = 0;
                    iVar11 = iVar11 * 0x58;
                    iVar2 = *(int *)(param_1 + 0xc);
                    iVar3 = *(int *)(iVar2 + 0x20 + iVar11);
                    if (0 < iVar3) {
                      do {
                        if (*(int *)(*(int *)(param_1 + 0x10) + 4 +
                                    (*(int *)(iVar11 + 0x24 + iVar2) + iVar10) * 0x18) == iVar1) {
                          fVar5 = fVar5 + *(float *)(*(int *)(param_1 + 0x10) + 0x14 +
                                                    (iVar10 + *(int *)(iVar2 + 0x24 + iVar11)) *
                                                    0x18);
                          goto LAB_000ca22e;
                        }
                        iVar10 = iVar10 + 1;
                      } while (iVar10 < iVar3);
                    }
                    (*DAT_0019f794)(2,"No link.\n");
                  }
LAB_000ca22e:
                  iStack_2c = iStack_2c + 1;
                } while (iStack_2c < iVar9 + -1);
              }
              if (ABS(fVar4 - fVar5) <= 0.1) goto LAB_000ca388;
              (*DAT_0019f794)(2,"Routing is inconsistent!!!\n");
              (*DAT_0019f794)(2,"(%d to %d |%d/%d)1:",iStack_1c,iStack_20,local_10,iStack_14);
              iVar11 = 0;
              if (0 < iVar8) {
                do {
                  (*DAT_0019f794)(2,&UNK_0014f175,*(undefined4 *)(iVar6 + iVar11 * 4));
                  iVar11 = iVar11 + 1;
                } while (iVar11 < iVar8);
              }
              (*DAT_0019f794)(2,"\n(%d to %d |%d/%d)2:",iStack_1c,iStack_20,local_10,iStack_14);
              iVar8 = 0;
              if (0 < iVar9) {
                do {
                  (*DAT_0019f794)(2,&UNK_0014f175,*(undefined4 *)(iVar7 + iVar8 * 4));
                  iVar8 = iVar8 + 1;
                } while (iVar8 < iVar9);
              }
              (*DAT_0019f794)(2,&UNK_0014e6f0);
              *(undefined4 *)(param_1 + 8) = 0;
              FindShortestPath__6CGraphPiiiii(param_1,iVar6,iStack_1c,iStack_20,local_10,uStack_18);
              *(undefined4 *)(param_1 + 8) = 1;
              FindShortestPath__6CGraphPiiiii(param_1,iVar7,iStack_1c,iStack_20,local_10,uStack_18);
              goto LAB_000ca3c2;
            }
LAB_000ca39a:
          }
          iStack_14 = iStack_14 + 1;
        } while (iStack_14 < 2);
        local_10 = local_10 + 1;
      } while (local_10 < 4);
    }
LAB_000ca3c2:
    if (iVar6 != 0) {
      __builtin_delete(iVar6);
    }
  }
  if (iVar7 != 0) {
    __builtin_delete(iVar7);
  }
  return;
LAB_000ca388:
  iStack_20 = iStack_20 + 1;
  iVar8 = *(int *)(param_1 + 0x18);
  if (iVar8 <= iStack_20) goto LAB_000ca39a;
  goto LAB_000ca048;
}


