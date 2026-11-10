// ComputeStaticRoutingTables__6CGraph  @ 000ca37c
void ComputeStaticRoutingTables__6CGraph(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  ushort *puVar3;
  char *__src;
  uint uVar4;
  uint uVar5;
  void *pvVar6;
  size_t sVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined2 uVar13;
  ushort *puVar14;
  char *pcVar15;
  char *pcVar16;
  size_t __size;
  int iVar17;
  char *pcVar18;
  bool bVar19;
  char local_5c;
  int local_58;
  undefined4 *local_54;
  int local_50;
  ushort *puStack_4c;
  uint uStack_38;
  int iStack_34;
  uint uStack_30;
  int local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  iVar1 = __builtin_vec_new(*(int *)(param_1 + 0x18) * *(int *)(param_1 + 0x18) * 2);
  puVar2 = (undefined4 *)__builtin_vec_new(*(int *)(param_1 + 0x18) * 4);
  puVar3 = (ushort *)__builtin_vec_new(*(int *)(param_1 + 0x18) * 2);
  __src = (char *)__builtin_vec_new(*(int *)(param_1 + 0x18) * 2);
  if (iVar1 != 0) {
    if (((puVar2 != (undefined4 *)0x0) && (puVar3 != (ushort *)0x0)) && (__src != (char *)0x0)) {
      local_14 = 0;
      local_18 = 0;
      do {
        local_1c = 0;
        do {
          if (local_1c == 0) {
            local_20 = 0;
          }
          else if (local_1c == 1) {
            local_20 = 0x340;
          }
          local_24 = 0;
          if (0 < *(int *)(param_1 + 0x18)) {
            do {
              iVar8 = 0;
              if (0 < *(int *)(param_1 + 0x18)) {
                do {
                  *(undefined2 *)(iVar1 + (local_24 * *(int *)(param_1 + 0x18) + iVar8) * 2) =
                       0xffff;
                  iVar8 = iVar8 + 1;
                } while (iVar8 < *(int *)(param_1 + 0x18));
              }
              local_24 = local_24 + 1;
            } while (local_24 < *(int *)(param_1 + 0x18));
          }
          for (local_24 = 0; local_24 < *(int *)(param_1 + 0x18); local_24 = local_24 + 1) {
            iVar8 = *(int *)(param_1 + 0x18);
            while (iVar8 = iVar8 + -1, -1 < iVar8) {
              if (*(short *)(iVar1 + (local_24 * *(int *)(param_1 + 0x18) + iVar8) * 2) == -1) {
                iVar10 = FindShortestPath__6CGraphPiiiii
                                   (param_1,puVar2,local_24,iVar8,local_18,local_20);
                if (iVar10 < 2) {
                  *(short *)(iVar1 + (local_24 * *(int *)(param_1 + 0x18) + iVar8) * 2) =
                       (short)local_24;
                  *(short *)(iVar1 + (iVar8 * *(int *)(param_1 + 0x18) + local_24) * 2) =
                       (short)iVar8;
                }
                else {
                  iVar12 = 0;
                  local_54 = puVar2;
                  if (0 < iVar10 + -1) {
                    do {
                      local_54 = local_54 + 1;
                      iVar11 = puVar2[iVar12];
                      local_58 = iVar12 + 1;
                      if (local_58 < iVar10) {
                        piVar9 = puVar2 + local_58;
                        uVar4 = iVar10 - local_58 & 3;
                        uVar13 = (undefined2)*local_54;
                        if (uVar4 != 0) {
                          if (1 < uVar4) {
                            if (2 < uVar4) {
                              *(undefined2 *)
                               (iVar1 + (iVar11 * *(int *)(param_1 + 0x18) + *piVar9) * 2) = uVar13;
                              piVar9 = piVar9 + 1;
                              local_58 = iVar12 + 2;
                            }
                            *(undefined2 *)
                             (iVar1 + (iVar11 * *(int *)(param_1 + 0x18) + *piVar9) * 2) = uVar13;
                            piVar9 = piVar9 + 1;
                            local_58 = local_58 + 1;
                          }
                          *(undefined2 *)(iVar1 + (iVar11 * *(int *)(param_1 + 0x18) + *piVar9) * 2)
                               = uVar13;
                          piVar9 = piVar9 + 1;
                          local_58 = local_58 + 1;
                          if (iVar10 <= local_58) goto LAB_000ca635;
                        }
                        do {
                          *(undefined2 *)(iVar1 + (iVar11 * *(int *)(param_1 + 0x18) + *piVar9) * 2)
                               = uVar13;
                          *(undefined2 *)
                           (iVar1 + (iVar11 * *(int *)(param_1 + 0x18) + piVar9[1]) * 2) = uVar13;
                          *(undefined2 *)
                           (iVar1 + (iVar11 * *(int *)(param_1 + 0x18) + piVar9[2]) * 2) = uVar13;
                          *(undefined2 *)
                           (iVar1 + (iVar11 * *(int *)(param_1 + 0x18) + piVar9[3]) * 2) = uVar13;
                          piVar9 = piVar9 + 4;
                          local_58 = local_58 + 4;
                        } while (local_58 < iVar10);
                      }
LAB_000ca635:
                      iVar12 = iVar12 + 1;
                    } while (iVar12 < iVar10 + -1);
                  }
                }
              }
            }
          }
          local_24 = 0;
          if (0 < *(int *)(param_1 + 0x18)) {
            iVar8 = local_18 * 8 + local_1c * 4;
            local_50 = 0;
            do {
              iVar10 = 0;
              puVar14 = puVar3;
              if (0 < *(int *)(param_1 + 0x18)) {
                do {
                  *puVar14 = *(ushort *)(iVar1 + (local_24 * *(int *)(param_1 + 0x18) + iVar10) * 2)
                  ;
                  iVar10 = iVar10 + 1;
                  puVar14 = puVar14 + 1;
                } while (iVar10 < *(int *)(param_1 + 0x18));
              }
              uStack_30 = 9999999;
              iVar12 = 0;
              iVar10 = 0;
              iStack_34 = 0;
              uStack_38 = 0;
              pcVar16 = __src;
              puStack_4c = puVar3;
              if (0 < *(int *)(param_1 + 0x18)) {
                do {
                  bVar19 = *puStack_4c == uStack_38;
                  if (iVar10 == 0) {
                    if (iVar12 == 0) {
                      if (!bVar19) goto LAB_000ca878;
                    }
                    else if (!bVar19 || iVar12 >= 0x80) {
                      if ((iVar12 != 1) || (*puStack_4c != uStack_30)) {
                        iStack_34 = iStack_34 + 1;
                        *pcVar16 = -(char)iVar12;
                        pcVar16 = pcVar16 + 1;
                        iVar12 = 0;
                        goto LAB_000ca878;
                      }
                      iVar10 = 2;
                      iVar12 = 0;
                      goto LAB_000ca879;
                    }
LAB_000ca873:
                    iVar12 = iVar12 + 1;
                  }
                  else {
                    if (*puStack_4c != uStack_30 || 0x7e < iVar10) {
                      iStack_34 = iStack_34 + 2;
                      *pcVar16 = (char)iVar10 + -1;
                      pcVar15 = pcVar16 + 1;
                      iVar11 = uStack_30 - local_24;
                      iVar10 = *(int *)(param_1 + 0x18) + iVar11;
                      iVar17 = iVar11 - *(int *)(param_1 + 0x18);
                      if (iVar11 + 0x80U < 0x100) {
                        *pcVar15 = (char)iVar11;
                        pcVar16 = pcVar16 + 2;
                      }
                      else {
                        if (iVar10 + 0x80U < 0x100) {
                          local_58._0_1_ = (char)iVar10;
                        }
                        else {
                          if (0xff < iVar17 + 0x80U) {
                            (*DAT_001c1114)(2,"Nodes need sorting (%d,%d)!\n",uStack_30,local_24);
                            pcVar16 = pcVar15;
                            goto LAB_000ca830;
                          }
                          local_5c = (char)iVar17;
                          local_58._0_1_ = local_5c;
                        }
                        *pcVar15 = (char)local_58;
                        pcVar16 = pcVar16 + 2;
                      }
LAB_000ca830:
                      iVar10 = 0;
                      if (bVar19 && iVar12 < 0x80) goto LAB_000ca873;
                    }
LAB_000ca878:
                    iVar10 = iVar10 + 1;
                  }
LAB_000ca879:
                  uStack_30 = (uint)*puStack_4c;
                  uStack_38 = uStack_38 + 1;
                  puStack_4c = puStack_4c + 1;
                } while ((int)uStack_38 < *(int *)(param_1 + 0x18));
              }
              pcVar15 = pcVar16;
              if (iVar10 != 0) {
                iStack_34 = iStack_34 + 2;
                *pcVar16 = (char)iVar10 + -1;
                pcVar15 = pcVar16 + 1;
                iVar11 = uStack_30 - local_24;
                iVar10 = *(int *)(param_1 + 0x18) + iVar11;
                iVar17 = iVar11 - *(int *)(param_1 + 0x18);
                if (iVar11 + 0x80U < 0x100) {
                  *pcVar15 = (char)iVar11;
                  pcVar15 = pcVar16 + 2;
                }
                else {
                  if (iVar10 + 0x80U < 0x100) {
                    local_58._0_1_ = (char)iVar10;
                  }
                  else {
                    if (0xff < iVar17 + 0x80U) {
                      (*DAT_001c1114)(2,"Nodes need sorting (%d,%d)!\n",uStack_30,local_24);
                      goto LAB_000ca934;
                    }
                    local_5c = (char)iVar17;
                    local_58._0_1_ = local_5c;
                  }
                  *pcVar15 = (char)local_58;
                  pcVar15 = pcVar16 + 2;
                }
              }
LAB_000ca934:
              if (iVar12 != 0) {
                iStack_34 = iStack_34 + 1;
                *pcVar15 = -(char)iVar12;
                pcVar15 = pcVar15 + 1;
              }
              __size = (int)pcVar15 - (int)__src;
              if (*(int *)(param_1 + 0x14) == 0) {
                *(size_t *)(param_1 + 0x20) = __size;
                pvVar6 = calloc(1,__size);
                *(void **)(param_1 + 0x14) = pvVar6;
                memcpy(pvVar6,__src,__size);
                *(undefined4 *)(iVar8 + *(int *)(param_1 + 0xc) + 0x28 + local_50) = 0;
                local_14 = local_14 + iStack_34;
              }
              else {
                iVar10 = 0;
                uVar4 = *(int *)(param_1 + 0x20) - __size;
                if (0 < (int)uVar4) {
                  pcVar16 = *(char **)(param_1 + 0x14);
                  uVar5 = uVar4 & 3;
                  if (uVar5 == 0) goto LAB_000ca994;
                  if (uVar5 < 2) goto LAB_000ca9d0;
                  if (uVar5 < 3) {
LAB_000ca9bc:
                    do {
                      bVar19 = true;
                      sVar7 = __size;
                      pcVar15 = pcVar16 + iVar10;
                      pcVar18 = __src;
                      do {
                        if (sVar7 == 0) break;
                        sVar7 = sVar7 - 1;
                        bVar19 = *pcVar15 == *pcVar18;
                        pcVar15 = pcVar15 + 1;
                        pcVar18 = pcVar18 + 1;
                      } while (bVar19);
                      iVar12 = iVar10;
                      if (bVar19) goto LAB_000ca9ea;
                      iVar10 = iVar10 + 1;
LAB_000ca9d0:
                      bVar19 = true;
                      sVar7 = __size;
                      pcVar15 = pcVar16 + iVar10;
                      pcVar18 = __src;
                      do {
                        if (sVar7 == 0) break;
                        sVar7 = sVar7 - 1;
                        bVar19 = *pcVar15 == *pcVar18;
                        pcVar15 = pcVar15 + 1;
                        pcVar18 = pcVar18 + 1;
                      } while (bVar19);
                      iVar12 = iVar10;
                      if ((bVar19) || (iVar10 = iVar10 + 1, iVar12 = iVar10, (int)uVar4 <= iVar10))
                      goto LAB_000ca9ea;
LAB_000ca994:
                      bVar19 = true;
                      sVar7 = __size;
                      pcVar15 = pcVar16 + iVar10;
                      pcVar18 = __src;
                      do {
                        if (sVar7 == 0) break;
                        sVar7 = sVar7 - 1;
                        bVar19 = *pcVar15 == *pcVar18;
                        pcVar15 = pcVar15 + 1;
                        pcVar18 = pcVar18 + 1;
                      } while (bVar19);
                      iVar12 = iVar10;
                      if (bVar19) goto LAB_000ca9ea;
                      iVar12 = iVar10 + 1;
                      bVar19 = true;
                      sVar7 = __size;
                      pcVar15 = pcVar16 + iVar12;
                      pcVar18 = __src;
                      do {
                        if (sVar7 == 0) break;
                        sVar7 = sVar7 - 1;
                        bVar19 = *pcVar15 == *pcVar18;
                        pcVar15 = pcVar15 + 1;
                        pcVar18 = pcVar18 + 1;
                      } while (bVar19);
                      if (bVar19) goto LAB_000ca9ea;
                      iVar10 = iVar10 + 2;
                    } while( true );
                  }
                  bVar19 = true;
                  sVar7 = __size;
                  pcVar15 = pcVar16;
                  pcVar18 = __src;
                  do {
                    if (sVar7 == 0) break;
                    sVar7 = sVar7 - 1;
                    bVar19 = *pcVar15 == *pcVar18;
                    pcVar15 = pcVar15 + 1;
                    pcVar18 = pcVar18 + 1;
                  } while (bVar19);
                  iVar12 = iVar10;
                  if (!bVar19) {
                    iVar10 = 1;
                    goto LAB_000ca9bc;
                  }
LAB_000ca9ea:
                  if (iVar12 < (int)(*(int *)(param_1 + 0x20) - __size)) {
                    *(int *)(iVar8 + *(int *)(param_1 + 0xc) + 0x28 + local_50) = iVar12;
                    goto LAB_000caad7;
                  }
                }
                pvVar6 = calloc(1,__size + *(int *)(param_1 + 0x20));
                memcpy(pvVar6,*(void **)(param_1 + 0x14),*(size_t *)(param_1 + 0x20));
                free(*(void **)(param_1 + 0x14));
                *(void **)(param_1 + 0x14) = pvVar6;
                memcpy((void *)((int)pvVar6 + *(int *)(param_1 + 0x20)),__src,__size);
                *(undefined4 *)(iVar8 + *(int *)(param_1 + 0xc) + 0x28 + local_50) =
                     *(undefined4 *)(param_1 + 0x20);
                *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + __size;
                local_14 = local_14 + iStack_34;
              }
LAB_000caad7:
              local_50 = local_50 + 0x58;
              local_24 = local_24 + 1;
            } while (local_24 < *(int *)(param_1 + 0x18));
          }
          local_1c = local_1c + 1;
        } while (local_1c < 2);
        local_18 = local_18 + 1;
      } while (local_18 < 4);
      (*DAT_001c1114)(2,"Size of Routes = %d\n",local_14);
    }
    if (iVar1 != 0) {
      __builtin_delete(iVar1);
    }
  }
  if (puVar3 != (ushort *)0x0) {
    __builtin_delete(puVar3);
  }
  if (__src != (char *)0x0) {
    __builtin_delete(__src);
  }
  if (puVar2 != (undefined4 *)0x0) {
    __builtin_delete(puVar2);
  }
  *(undefined4 *)(param_1 + 8) = 1;
  return;
}


