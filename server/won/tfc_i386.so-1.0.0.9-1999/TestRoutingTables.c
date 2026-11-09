// TestRoutingTables__6CGraph  @ 000cf470
void TestRoutingTables__6CGraph(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iStack_54;
  int iStack_48;
  int iStack_3c;
  float fStack_38;
  int iStack_30;
  float fStack_2c;
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  int local_10;
  
  iVar2 = __builtin_vec_new(*(int *)(param_1 + 0x18) << 2);
  iVar3 = __builtin_vec_new(*(int *)(param_1 + 0x18) << 2);
  if (iVar2 != 0) {
    if (iVar3 != 0) {
      local_10 = 0;
      do {
        iStack_14 = 0;
        do {
          if (iStack_14 == 0) {
            uStack_18 = 0;
          }
          else if (iStack_14 == 1) {
            uStack_18 = 0x340;
          }
          iStack_1c = 0;
          if (0 < *(int *)(param_1 + 0x18)) {
            do {
              iStack_20 = 0;
LAB_000cf883:
              if (iStack_20 < *(int *)(param_1 + 0x18)) {
                *(undefined4 *)(param_1 + 8) = 0;
                iVar4 = FindShortestPath__6CGraphPiiiii
                                  (param_1,iVar2,iStack_1c,iStack_20,local_10,uStack_18);
                *(undefined4 *)(param_1 + 8) = 1;
                iVar5 = FindShortestPath__6CGraphPiiiii
                                  (param_1,iVar3,iStack_1c,iStack_20,local_10,uStack_18);
                if (iVar5 == 10) goto LAB_000cf880;
                fStack_2c = 0.0;
                for (iStack_54 = 0; iStack_54 < iVar4 + -1; iStack_54 = iStack_54 + 1) {
                  iVar6 = *(int *)(iVar2 + iStack_54 * 4);
                  if (iVar6 != *(int *)(iVar2 + 4 + iStack_54 * 4)) {
                    iStack_48 = 0;
                    iStack_30 = *(int *)(param_1 + 0xc);
                    if (0 < *(int *)(iStack_30 + 0x20 + iVar6 * 0x58)) {
                      do {
                        if (*(int *)(*(int *)(param_1 + 0x10) + 4 +
                                    (iStack_48 + *(int *)(iStack_30 + 0x24 + iVar6 * 0x58)) * 0x18)
                            == *(int *)(iVar2 + 4 + iStack_54 * 4)) {
                          fStack_2c = fStack_2c +
                                      *(float *)(*(int *)(param_1 + 0x10) + 0x14 +
                                                (iStack_48 +
                                                *(int *)(iStack_30 + 0x24 + iVar6 * 0x58)) * 0x18);
                          goto LAB_000cf65b;
                        }
                        iStack_48 = iStack_48 + 1;
                        iVar6 = *(int *)(iVar2 + iStack_54 * 4);
                        iStack_30 = *(int *)(param_1 + 0xc);
                      } while (iStack_48 < *(int *)(iStack_30 + 0x20 + iVar6 * 0x58));
                    }
                    (*DAT_001755b4)(2,"No link.\n");
                  }
LAB_000cf65b:
                }
                fStack_38 = 0.0;
                for (iStack_54 = 0; iStack_54 < iVar5 + -1; iStack_54 = iStack_54 + 1) {
                  iVar6 = *(int *)(iVar3 + iStack_54 * 4);
                  if (iVar6 != *(int *)(iVar3 + 4 + iStack_54 * 4)) {
                    iStack_48 = 0;
                    iStack_3c = *(int *)(param_1 + 0xc);
                    if (0 < *(int *)(iStack_3c + 0x20 + iVar6 * 0x58)) {
                      do {
                        if (*(int *)(*(int *)(param_1 + 0x10) + 4 +
                                    (iStack_48 + *(int *)(iStack_3c + 0x24 + iVar6 * 0x58)) * 0x18)
                            == *(int *)(iVar3 + 4 + iStack_54 * 4)) {
                          fStack_38 = fStack_38 +
                                      *(float *)(*(int *)(param_1 + 0x10) + 0x14 +
                                                (iStack_48 +
                                                *(int *)(iStack_3c + 0x24 + iVar6 * 0x58)) * 0x18);
                          goto LAB_000cf74b;
                        }
                        iStack_48 = iStack_48 + 1;
                        iVar6 = *(int *)(iVar3 + iStack_54 * 4);
                        iStack_3c = *(int *)(param_1 + 0xc);
                      } while (iStack_48 < *(int *)(iStack_3c + 0x20 + iVar6 * 0x58));
                    }
                    (*DAT_001755b4)(2,"No link.\n");
                  }
LAB_000cf74b:
                }
                fVar1 = ABS(fStack_2c - fStack_38);
                if ((byte)(0.1 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == 0.1) << 0xe) >> 8)) != 1)
                goto LAB_000cf880;
                (*DAT_001755b4)(2,"Routing is inconsistent!!!\n");
                (*DAT_001755b4)(2,"(%d to %d |%d/%d)1:",iStack_1c,iStack_20,local_10,iStack_14);
                iVar6 = 0;
                if (0 < iVar4) {
                  do {
                    (*DAT_001755b4)(2,&DAT_00137755,*(undefined4 *)(iVar2 + iVar6 * 4));
                    iVar6 = iVar6 + 1;
                  } while (iVar6 < iVar4);
                }
                (*DAT_001755b4)(2,"\n(%d to %d |%d/%d)2:",iStack_1c,iStack_20,local_10,iStack_14);
                iVar4 = 0;
                if (0 < iVar5) {
                  do {
                    (*DAT_001755b4)(2,&DAT_00137755,*(undefined4 *)(iVar3 + iVar4 * 4));
                    iVar4 = iVar4 + 1;
                  } while (iVar4 < iVar5);
                }
                (*DAT_001755b4)(2,&DAT_00136cd0);
                *(undefined4 *)(param_1 + 8) = 0;
                FindShortestPath__6CGraphPiiiii
                          (param_1,iVar2,iStack_1c,iStack_20,local_10,uStack_18);
                *(undefined4 *)(param_1 + 8) = 1;
                FindShortestPath__6CGraphPiiiii
                          (param_1,iVar3,iStack_1c,iStack_20,local_10,uStack_18);
                goto LAB_000cf8be;
              }
              iStack_1c = iStack_1c + 1;
            } while (iStack_1c < *(int *)(param_1 + 0x18));
          }
          iStack_14 = iStack_14 + 1;
        } while (iStack_14 < 2);
        local_10 = local_10 + 1;
      } while (local_10 < 4);
    }
LAB_000cf8be:
    if (iVar2 != 0) {
      __builtin_delete(iVar2);
    }
  }
  if (iVar3 != 0) {
    __builtin_delete(iVar3);
  }
  return;
LAB_000cf880:
  iStack_20 = iStack_20 + 1;
  goto LAB_000cf883;
}


