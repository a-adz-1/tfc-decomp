// ComputeStaticRoutingTables__6CGraph  @ 000ceda0
void ComputeStaticRoutingTables__6CGraph(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *__src;
  int iVar5;
  void *pvVar6;
  size_t sVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  size_t __size;
  char *pcVar12;
  bool bVar13;
  bool bVar14;
  int local_54;
  int local_50;
  int local_4c;
  uint local_3c;
  int local_38;
  uint local_34;
  int local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  iVar2 = __builtin_vec_new(*(int *)(param_1 + 0x18) * *(int *)(param_1 + 0x18) * 2);
  iVar3 = __builtin_vec_new(*(int *)(param_1 + 0x18) * 4);
  iVar4 = __builtin_vec_new(*(int *)(param_1 + 0x18) * 2);
  __src = (char *)__builtin_vec_new(*(int *)(param_1 + 0x18) * 2);
  if (iVar2 != 0) {
    if (((iVar3 != 0) && (iVar4 != 0)) && (__src != (char *)0x0)) {
      local_18 = 0;
      local_1c = 0;
      do {
        local_20 = 0;
        do {
          if (local_20 == 0) {
            local_24 = 0;
          }
          else if (local_20 == 1) {
            local_24 = 0x340;
          }
          local_28 = 0;
          if (0 < *(int *)(param_1 + 0x18)) {
            do {
              iVar8 = 0;
              if (0 < *(int *)(param_1 + 0x18)) {
                do {
                  *(undefined2 *)(iVar2 + (local_28 * *(int *)(param_1 + 0x18) + iVar8) * 2) =
                       0xffff;
                  iVar8 = iVar8 + 1;
                } while (iVar8 < *(int *)(param_1 + 0x18));
              }
              local_28 = local_28 + 1;
            } while (local_28 < *(int *)(param_1 + 0x18));
          }
          local_28 = 0;
          if (0 < *(int *)(param_1 + 0x18)) {
            do {
              iVar8 = *(int *)(param_1 + 0x18);
              while (iVar8 = iVar8 + -1, -1 < iVar8) {
                if (*(short *)(iVar2 + (local_28 * *(int *)(param_1 + 0x18) + iVar8) * 2) == -1) {
                  iVar5 = FindShortestPath__6CGraphPiiiii
                                    (param_1,iVar3,local_28,iVar8,local_1c,local_24);
                  if (iVar5 < 2) {
                    *(short *)(iVar2 + (local_28 * *(int *)(param_1 + 0x18) + iVar8) * 2) =
                         (short)local_28;
                    *(short *)(iVar2 + (iVar8 * *(int *)(param_1 + 0x18) + local_28) * 2) =
                         (short)iVar8;
                  }
                  else {
                    local_54 = 0;
                    if (0 < iVar5 + -1) {
                      do {
                        iVar10 = *(int *)(iVar3 + local_54 * 4);
                        uVar1 = *(undefined4 *)(iVar3 + 4 + local_54 * 4);
                        iVar9 = local_54;
                        while (iVar9 = iVar9 + 1, iVar9 < iVar5) {
                          *(short *)(iVar2 + (iVar10 * *(int *)(param_1 + 0x18) +
                                             *(int *)(iVar3 + iVar9 * 4)) * 2) = (short)uVar1;
                        }
                        local_54 = local_54 + 1;
                      } while (local_54 < iVar5 + -1);
                    }
                  }
                }
              }
              local_28 = local_28 + 1;
            } while (local_28 < *(int *)(param_1 + 0x18));
          }
          local_28 = 0;
          if (0 < *(int *)(param_1 + 0x18)) {
            iVar8 = local_1c * 8 + local_20 * 4;
            do {
              iVar5 = 0;
              if (0 < *(int *)(param_1 + 0x18)) {
                do {
                  *(undefined2 *)(iVar4 + iVar5 * 2) =
                       *(undefined2 *)(iVar2 + (local_28 * *(int *)(param_1 + 0x18) + iVar5) * 2);
                  iVar5 = iVar5 + 1;
                } while (iVar5 < *(int *)(param_1 + 0x18));
              }
              local_34 = 9999999;
              local_50 = 0;
              iVar5 = 0;
              local_38 = 0;
              local_3c = 0;
              pcVar12 = __src;
              if (0 < *(int *)(param_1 + 0x18)) {
                do {
                  bVar13 = *(ushort *)(iVar4 + local_3c * 2) != local_34;
                  bVar14 = *(ushort *)(iVar4 + local_3c * 2) != local_3c;
                  if (iVar5 == 0) {
                    if (local_50 == 0) {
                      if (bVar14) goto code_r0x000cf1b0;
                    }
                    else if (bVar14 || 0x7f < local_50) {
                      if ((local_50 != 1) || (bVar13)) {
                        *pcVar12 = -(char)local_50;
                        FUN_000cf1b0();
                        return;
                      }
                      iVar5 = 2;
                      local_50 = 0;
                      goto LAB_000cf1b1;
                    }
LAB_000cf1a6:
                    local_50 = local_50 + 1;
                  }
                  else {
                    if (bVar13 || 0x7e < iVar5) {
                      local_38 = local_38 + 2;
                      *pcVar12 = (char)iVar5 + -1;
                      pcVar11 = pcVar12 + 1;
                      iVar10 = local_34 - local_28;
                      iVar9 = iVar10 + *(int *)(param_1 + 0x18);
                      iVar5 = iVar10 - *(int *)(param_1 + 0x18);
                      if (iVar10 + 0x80U < 0x100) {
                        *pcVar11 = (char)iVar10;
                        pcVar11 = pcVar12 + 2;
                      }
                      else if (iVar9 + 0x80U < 0x100) {
                        local_54._0_1_ = (char)iVar9;
                        *pcVar11 = (char)local_54;
                        pcVar11 = pcVar12 + 2;
                      }
                      else if (iVar5 + 0x80U < 0x100) {
                        local_4c._0_1_ = (char)iVar5;
                        *pcVar11 = (char)local_4c;
                        pcVar11 = pcVar12 + 2;
                      }
                      else {
                        (*DAT_001755b4)(2,"Nodes need sorting (%d,%d)!\n",local_34,local_28);
                      }
                      iVar5 = 0;
                      pcVar12 = pcVar11;
                      if (bVar14 || 0x7f < local_50) {
                        FUN_000cf1b0();
                        return;
                      }
                      goto LAB_000cf1a6;
                    }
code_r0x000cf1b0:
                    iVar5 = iVar5 + 1;
                  }
LAB_000cf1b1:
                  local_34 = (uint)*(ushort *)(iVar4 + local_3c * 2);
                  local_3c = local_3c + 1;
                } while ((int)local_3c < *(int *)(param_1 + 0x18));
              }
              pcVar11 = pcVar12;
              if (iVar5 != 0) {
                local_38 = local_38 + 2;
                *pcVar12 = (char)iVar5 + -1;
                pcVar11 = pcVar12 + 1;
                iVar5 = local_34 - local_28;
                iVar10 = iVar5 + *(int *)(param_1 + 0x18);
                iVar9 = iVar5 - *(int *)(param_1 + 0x18);
                if (iVar5 + 0x80U < 0x100) {
                  *pcVar11 = (char)iVar5;
                  pcVar11 = pcVar12 + 2;
                }
                else if (iVar10 + 0x80U < 0x100) {
                  local_54._0_1_ = (char)iVar10;
                  *pcVar11 = (char)local_54;
                  pcVar11 = pcVar12 + 2;
                }
                else if (iVar9 + 0x80U < 0x100) {
                  local_4c._0_1_ = (char)iVar9;
                  *pcVar11 = (char)local_4c;
                  pcVar11 = pcVar12 + 2;
                }
                else {
                  (*DAT_001755b4)(2,"Nodes need sorting (%d,%d)!\n",local_34,local_28);
                }
              }
              if (local_50 != 0) {
                local_38 = local_38 + 1;
                *pcVar11 = -(char)local_50;
                pcVar11 = pcVar11 + 1;
              }
              __size = (int)pcVar11 - (int)__src;
              if (*(int *)(param_1 + 0x14) == 0) {
                *(size_t *)(param_1 + 0x20) = __size;
                pvVar6 = calloc(1,__size);
                *(void **)(param_1 + 0x14) = pvVar6;
                memcpy(pvVar6,__src,__size);
                *(undefined4 *)(iVar8 + *(int *)(param_1 + 0xc) + 0x28 + local_28 * 0x58) = 0;
                local_18 = local_18 + local_38;
              }
              else {
                local_4c = 0;
                if (0 < (int)(*(int *)(param_1 + 0x20) - __size)) {
                  do {
                    bVar13 = true;
                    sVar7 = __size;
                    pcVar12 = (char *)(local_4c + *(int *)(param_1 + 0x14));
                    pcVar11 = __src;
                    do {
                      if (sVar7 == 0) break;
                      sVar7 = sVar7 - 1;
                      bVar13 = *pcVar12 == *pcVar11;
                      pcVar12 = pcVar12 + 1;
                      pcVar11 = pcVar11 + 1;
                    } while (bVar13);
                  } while ((!bVar13) &&
                          (local_4c = local_4c + 1,
                          local_4c < (int)(*(int *)(param_1 + 0x20) - __size)));
                  if (local_4c < (int)(*(int *)(param_1 + 0x20) - __size)) {
                    *(int *)(iVar8 + *(int *)(param_1 + 0xc) + 0x28 + local_28 * 0x58) = local_4c;
                    goto LAB_000cf3c8;
                  }
                }
                pvVar6 = calloc(1,__size + *(int *)(param_1 + 0x20));
                memcpy(pvVar6,*(void **)(param_1 + 0x14),*(size_t *)(param_1 + 0x20));
                free(*(void **)(param_1 + 0x14));
                *(void **)(param_1 + 0x14) = pvVar6;
                memcpy((void *)((int)pvVar6 + *(int *)(param_1 + 0x20)),__src,__size);
                *(undefined4 *)(iVar8 + *(int *)(param_1 + 0xc) + 0x28 + local_28 * 0x58) =
                     *(undefined4 *)(param_1 + 0x20);
                *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + __size;
                local_18 = local_18 + local_38;
              }
LAB_000cf3c8:
              local_28 = local_28 + 1;
            } while (local_28 < *(int *)(param_1 + 0x18));
          }
          local_20 = local_20 + 1;
        } while (local_20 < 2);
        local_1c = local_1c + 1;
      } while (local_1c < 4);
      (*DAT_001755b4)(2,"Size of Routes = %d\n",local_18);
    }
    if (iVar2 != 0) {
      __builtin_delete(iVar2);
    }
  }
  if (iVar4 != 0) {
    __builtin_delete(iVar4);
  }
  if (__src != (char *)0x0) {
    __builtin_delete(__src);
  }
  if (iVar3 != 0) {
    __builtin_delete(iVar3);
  }
  *(undefined4 *)(param_1 + 8) = 1;
  return;
}


