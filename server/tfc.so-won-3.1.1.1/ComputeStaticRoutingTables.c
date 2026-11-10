// ComputeStaticRoutingTables__6CGraph  @ 000c98c4
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
  int iVar11;
  char *pcVar12;
  size_t __size;
  char *pcVar13;
  bool bVar14;
  char *local_68;
  int local_64;
  uint local_60;
  int local_54;
  uint local_44;
  int local_40;
  int local_3c;
  uint local_38;
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
      local_64 = *(int *)(param_1 + 0x18);
      do {
        local_20 = 0;
        do {
          if (local_20 == 0) {
            local_24 = 0;
          }
          else if (local_20 == 1) {
            local_24 = 0x340;
          }
          for (local_28 = 0; local_28 < local_64; local_28 = local_28 + 1) {
            iVar8 = 0;
            if (0 < local_64) {
              do {
                iVar10 = local_64 * local_28 + iVar8;
                iVar8 = iVar8 + 1;
                *(undefined2 *)(iVar2 + iVar10 * 2) = 0xffff;
                local_64 = *(int *)(param_1 + 0x18);
              } while (iVar8 < local_64);
            }
          }
          for (local_28 = 0; iVar8 = local_64, local_28 < local_64; local_28 = local_28 + 1) {
            while (iVar8 = iVar8 + -1, -1 < iVar8) {
              if (*(short *)(iVar2 + (local_64 * local_28 + iVar8) * 2) == -1) {
                iVar10 = FindShortestPath__6CGraphPiiiii
                                   (param_1,iVar3,local_28,iVar8,local_1c,local_24);
                if (iVar10 < 2) {
                  *(short *)(iVar2 + (local_28 * *(int *)(param_1 + 0x18) + iVar8) * 2) =
                       (short)local_28;
                  *(short *)(iVar2 + (iVar8 * *(int *)(param_1 + 0x18) + local_28) * 2) =
                       (short)iVar8;
                }
                else {
                  iVar5 = 0;
                  if (0 < iVar10 + -1) {
                    do {
                      iVar11 = *(int *)(iVar3 + iVar5 * 4);
                      uVar1 = *(undefined4 *)(iVar3 + 4 + iVar5 * 4);
                      iVar5 = iVar5 + 1;
                      for (iVar9 = iVar5; iVar9 < iVar10; iVar9 = iVar9 + 1) {
                        *(short *)(iVar2 + (iVar11 * *(int *)(param_1 + 0x18) +
                                           *(int *)(iVar3 + iVar9 * 4)) * 2) = (short)uVar1;
                      }
                    } while (iVar5 < iVar10 + -1);
                  }
                }
              }
              local_64 = *(int *)(param_1 + 0x18);
            }
          }
          local_28 = 0;
          if (0 < local_64) {
            iVar8 = local_1c * 8 + local_20 * 4;
            do {
              iVar10 = 0;
              if (0 < local_64) {
                do {
                  *(undefined2 *)(iVar4 + iVar10 * 2) =
                       *(undefined2 *)(iVar2 + (local_64 * local_28 + iVar10) * 2);
                  iVar10 = iVar10 + 1;
                  local_64 = *(int *)(param_1 + 0x18);
                } while (iVar10 < local_64);
              }
              local_38 = 9999999;
              local_3c = 0;
              iVar10 = 0;
              local_40 = 0;
              local_44 = 0;
              local_68 = __src;
              if (0 < local_64) {
                do {
                  local_60 = (uint)*(ushort *)(iVar4 + local_44 * 2);
                  bVar14 = local_60 != local_44;
                  if (iVar10 == 0) {
                    if (local_3c == 0) {
                      if (bVar14) {
                        iVar10 = 1;
                      }
                      else {
                        local_3c = 1;
                      }
                    }
                    else if (bVar14 || 0x7f < local_3c) {
                      if ((local_3c != 1) || (local_60 != local_38)) {
                        local_40 = local_40 + 1;
                        *local_68 = -(char)local_3c;
                        local_68 = local_68 + 1;
                        local_3c = 0;
                        local_64 = *(int *)(param_1 + 0x18);
                        goto LAB_000c9cdc;
                      }
                      iVar10 = 2;
                      local_3c = 0;
                    }
                    else {
                      local_3c = local_3c + 1;
                    }
                  }
                  else {
                    if (local_60 == local_38 && iVar10 < 0x7f) {
                      iVar10 = iVar10 + 1;
                      goto LAB_000c9cfd;
                    }
                    local_40 = local_40 + 2;
                    *local_68 = (char)iVar10 + -1;
                    pcVar12 = local_68 + 1;
                    iVar11 = local_38 - local_28;
                    iVar10 = *(int *)(param_1 + 0x18) + iVar11;
                    iVar5 = iVar11 - *(int *)(param_1 + 0x18);
                    if (iVar11 + 0x80U < 0x100) {
                      *pcVar12 = (char)iVar11;
LAB_000c9c19:
                      local_68 = local_68 + 2;
                    }
                    else {
                      if (iVar10 + 0x80U < 0x100) {
                        local_64._0_1_ = (char)iVar10;
LAB_000c9c14:
                        *pcVar12 = (char)local_64;
                        goto LAB_000c9c19;
                      }
                      if (iVar5 + 0x80U < 0x100) {
                        local_60._0_1_ = (char)iVar5;
                        local_64._0_1_ = (char)local_60;
                        goto LAB_000c9c14;
                      }
                      (*DAT_0019f794)(2,"Nodes need sorting (%d,%d)!\n",local_38,local_28);
                      local_68 = pcVar12;
                    }
                    iVar10 = 0;
                    if (bVar14 || 0x7f < local_3c) {
                      local_64 = *(int *)(param_1 + 0x18);
LAB_000c9cdc:
                      iVar10 = 1;
                      local_60 = (uint)*(ushort *)(iVar4 + local_44 * 2);
                    }
                    else {
                      local_3c = local_3c + 1;
                      local_64 = *(int *)(param_1 + 0x18);
                      local_60 = (uint)*(ushort *)(iVar4 + local_44 * 2);
                    }
                  }
LAB_000c9cfd:
                  local_38 = local_60;
                  local_44 = local_44 + 1;
                } while ((int)local_44 < local_64);
              }
              if (iVar10 != 0) {
                local_40 = local_40 + 2;
                *local_68 = (char)iVar10 + -1;
                pcVar12 = local_68 + 1;
                iVar11 = local_38 - local_28;
                iVar10 = *(int *)(param_1 + 0x18) + iVar11;
                iVar5 = iVar11 - *(int *)(param_1 + 0x18);
                if (iVar11 + 0x80U < 0x100) {
                  *pcVar12 = (char)iVar11;
                  local_68 = local_68 + 2;
                }
                else {
                  if (iVar10 + 0x80U < 0x100) {
                    local_64._0_1_ = (char)iVar10;
                  }
                  else {
                    if (0xff < iVar5 + 0x80U) {
                      (*DAT_0019f794)(2,"Nodes need sorting (%d,%d)!\n",local_38,local_28);
                      local_68 = pcVar12;
                      goto LAB_000c9daa;
                    }
                    local_60._0_1_ = (char)iVar5;
                    local_64._0_1_ = (char)local_60;
                  }
                  *pcVar12 = (char)local_64;
                  local_68 = local_68 + 2;
                }
              }
LAB_000c9daa:
              if (local_3c != 0) {
                local_40 = local_40 + 1;
                *local_68 = -(char)local_3c;
                local_68 = local_68 + 1;
              }
              __size = (int)local_68 - (int)__src;
              if (*(int *)(param_1 + 0x14) == 0) {
                *(size_t *)(param_1 + 0x20) = __size;
                pvVar6 = calloc(1,__size);
                *(void **)(param_1 + 0x14) = pvVar6;
                memcpy(pvVar6,__src,__size);
                *(undefined4 *)(iVar8 + *(int *)(param_1 + 0xc) + 0x28 + local_28 * 0x58) = 0;
LAB_000c9ef4:
                local_18 = local_18 + local_40;
              }
              else {
                local_54 = 0;
                iVar10 = *(int *)(param_1 + 0x20);
                if ((int)(iVar10 - __size) < 1) {
LAB_000c9e48:
                  pvVar6 = calloc(1,iVar10 + __size);
                  memcpy(pvVar6,*(void **)(param_1 + 0x14),*(size_t *)(param_1 + 0x20));
                  free(*(void **)(param_1 + 0x14));
                  *(void **)(param_1 + 0x14) = pvVar6;
                  memcpy((void *)((int)pvVar6 + *(int *)(param_1 + 0x20)),__src,__size);
                  *(undefined4 *)(iVar8 + *(int *)(param_1 + 0xc) + 0x28 + local_28 * 0x58) =
                       *(undefined4 *)(param_1 + 0x20);
                  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + __size;
                  goto LAB_000c9ef4;
                }
                do {
                  bVar14 = true;
                  sVar7 = __size;
                  pcVar12 = (char *)(local_54 + *(int *)(param_1 + 0x14));
                  pcVar13 = __src;
                  do {
                    if (sVar7 == 0) break;
                    sVar7 = sVar7 - 1;
                    bVar14 = *pcVar12 == *pcVar13;
                    pcVar12 = pcVar12 + 1;
                    pcVar13 = pcVar13 + 1;
                  } while (bVar14);
                } while ((!bVar14) && (local_54 = local_54 + 1, local_54 < (int)(iVar10 - __size)));
                if ((int)(iVar10 - __size) <= local_54) goto LAB_000c9e48;
                *(int *)(iVar8 + *(int *)(param_1 + 0xc) + 0x28 + local_28 * 0x58) = local_54;
              }
              local_28 = local_28 + 1;
              local_64 = *(int *)(param_1 + 0x18);
            } while (local_28 < local_64);
          }
          local_20 = local_20 + 1;
        } while (local_20 < 2);
        local_1c = local_1c + 1;
      } while (local_1c < 4);
      (*DAT_0019f794)(2,"Size of Routes = %d\n",local_18);
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


