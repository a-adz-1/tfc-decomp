// BuildRegionTables__6CGraph  @ 000c9128
void BuildRegionTables__6CGraph(int param_1)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int local_5c;
  int local_48;
  int local_3c;
  int local_38;
  int local_24;
  int local_14;
  
  if (*(void **)(param_1 + 0x24) != (void *)0x0) {
    free(*(void **)(param_1 + 0x24));
  }
  pvVar7 = calloc(0x10,*(size_t *)(param_1 + 0x18));
  *(void **)(param_1 + 0x24) = pvVar7;
  if (pvVar7 == (void *)0x0) {
    (*DAT_0019f794)(2,"Couldn\'t allocated node ordering array.\n");
  }
  else {
    local_14 = 0;
    do {
      *(undefined4 *)(local_14 * 4 + param_1 + 0x1864) = 0x4e6e6b28;
      *(undefined4 *)(local_14 * 4 + param_1 + 0x1870) = 0xce6e6b28;
      local_14 = local_14 + 1;
    } while (local_14 < 3);
    local_14 = 0;
    iVar8 = *(int *)(param_1 + 0x18);
    if (0 < iVar8) {
      do {
        iVar15 = local_14 * 0x58;
        fVar1 = *(float *)(*(int *)(param_1 + 0xc) + iVar15);
        iVar11 = *(int *)(param_1 + 0xc);
        if (fVar1 < *(float *)(param_1 + 0x1864)) {
          *(float *)(param_1 + 0x1864) = fVar1;
          iVar11 = *(int *)(param_1 + 0xc);
        }
        fVar1 = *(float *)(iVar11 + 4 + iVar15);
        if (fVar1 < *(float *)(param_1 + 0x1868)) {
          *(float *)(param_1 + 0x1868) = fVar1;
          iVar11 = *(int *)(param_1 + 0xc);
        }
        fVar1 = *(float *)(iVar11 + 8 + iVar15);
        if (fVar1 < *(float *)(param_1 + 0x186c)) {
          *(float *)(param_1 + 0x186c) = fVar1;
          iVar11 = *(int *)(param_1 + 0xc);
        }
        fVar1 = *(float *)(iVar11 + iVar15);
        fVar2 = *(float *)(param_1 + 0x1870);
        if (0x3f < (byte)((fVar1 < fVar2 |
                           (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
          *(float *)(param_1 + 0x1870) = fVar1;
          iVar11 = *(int *)(param_1 + 0xc);
        }
        fVar1 = *(float *)(iVar11 + 4 + iVar15);
        fVar2 = *(float *)(param_1 + 0x1874);
        if (0x3f < (byte)((fVar1 < fVar2 |
                           (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
          *(float *)(param_1 + 0x1874) = fVar1;
          iVar11 = *(int *)(param_1 + 0xc);
        }
        fVar1 = *(float *)(iVar11 + 8 + iVar15);
        fVar2 = *(float *)(param_1 + 0x1878);
        if (0x3f < (byte)((fVar1 < fVar2 |
                           (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
          *(float *)(param_1 + 0x1878) = fVar1;
        }
        local_14 = local_14 + 1;
      } while (local_14 < iVar8);
    }
    local_14 = 0;
    if (0 < iVar8) {
      do {
        iVar8 = local_14 * 0x58;
        *(char *)(*(int *)(param_1 + 0xc) + 0x18 + iVar8) =
             (char)((((int)ROUND(*(float *)(*(int *)(param_1 + 0xc) + iVar8)) -
                     (int)ROUND(*(float *)(param_1 + 0x1864))) * 0x100) /
                   (((int)ROUND(*(float *)(param_1 + 0x1870)) -
                    (int)ROUND(*(float *)(param_1 + 0x1864))) + 1));
        *(char *)(*(int *)(param_1 + 0xc) + 0x19 + iVar8) =
             (char)((((int)ROUND(*(float *)(*(int *)(param_1 + 0xc) + 4 + iVar8)) -
                     (int)ROUND(*(float *)(param_1 + 0x1868))) * 0x100) /
                   (((int)ROUND(*(float *)(param_1 + 0x1874)) -
                    (int)ROUND(*(float *)(param_1 + 0x1868))) + 1));
        *(char *)(*(int *)(param_1 + 0xc) + 0x1a + iVar8) =
             (char)((((int)ROUND(*(float *)(*(int *)(param_1 + 0xc) + 8 + iVar8)) -
                     (int)ROUND(*(float *)(param_1 + 0x186c))) * 0x100) /
                   (((int)ROUND(*(float *)(param_1 + 0x1878)) -
                    (int)ROUND(*(float *)(param_1 + 0x186c))) + 1));
        local_14 = local_14 + 1;
      } while (local_14 < *(int *)(param_1 + 0x18));
    }
    local_14 = 0;
    iVar15 = param_1 + 0x28;
    iVar8 = param_1 + 0xc28;
    do {
      local_24 = 0;
      do {
        iVar11 = local_14 * 0x400 + local_24 * 4;
        *(undefined4 *)(iVar11 + iVar15) = 0xff;
        *(undefined4 *)(iVar11 + iVar8) = 0;
        local_24 = local_24 + 1;
      } while (local_24 < 0x100);
      local_24 = 0;
      local_5c = *(int *)(param_1 + 0x18);
      if (0 < local_5c) {
        do {
          *(int *)(local_14 * 4 + local_24 * 0x10 + *(int *)(param_1 + 0x24)) = local_24;
          local_24 = local_24 + 1;
          local_5c = *(int *)(param_1 + 0x18);
        } while (local_24 < local_5c);
      }
      local_24 = 0;
      if (0 < local_5c + -1) {
        iVar11 = local_14 * 4;
        do {
          iVar5 = local_24 * 0x10;
          iVar10 = *(int *)(param_1 + 0xc);
          iVar13 = *(int *)(iVar11 + iVar5 + *(int *)(param_1 + 0x24)) * 0x58;
          uVar16 = (uint)*(byte *)(iVar10 + 0x18 + iVar13);
          uVar9 = (uint)*(byte *)(iVar10 + 0x19 + iVar13);
          uVar12 = (uint)*(byte *)(iVar10 + 0x1a + iVar13);
          if (local_14 == 1) {
            local_38 = uVar9 * 0x10000 + uVar12 * 0x100 + uVar16;
          }
          else if (local_14 < 2) {
            if (local_14 == 0) {
              local_38 = uVar12 + uVar16 * 0x10000 + uVar9 * 0x100;
            }
          }
          else if (local_14 == 2) {
            local_38 = uVar16 * 0x100 + uVar12 * 0x10000 + uVar9;
          }
          local_24 = local_24 + 1;
          local_3c = local_24;
          if (local_24 < local_5c) {
            do {
              iVar17 = local_3c * 0x10;
              iVar10 = *(int *)(param_1 + 0x24);
              iVar13 = *(int *)(param_1 + 0xc);
              iVar14 = *(int *)(iVar11 + iVar10 + iVar17) * 0x58;
              uVar12 = (uint)*(byte *)(iVar13 + 0x18 + iVar14);
              uVar9 = (uint)*(byte *)(iVar13 + 0x19 + iVar14);
              uVar16 = (uint)*(byte *)(iVar13 + 0x1a + iVar14);
              if (local_14 == 1) {
                local_48 = uVar9 * 0x10000 + uVar16 * 0x100 + uVar12;
              }
              else if (local_14 < 2) {
                if (local_14 == 0) {
                  local_48 = uVar16 + uVar12 * 0x10000 + uVar9 * 0x100;
                }
              }
              else if (local_14 == 2) {
                local_48 = uVar16 * 0x10000 + uVar12 * 0x100 + uVar9;
              }
              if (local_48 < local_38) {
                iVar13 = iVar5 + iVar10;
                uVar6 = *(undefined4 *)(iVar11 + iVar13);
                *(undefined4 *)(iVar11 + iVar13) = *(undefined4 *)(iVar11 + iVar10 + iVar17);
                *(undefined4 *)(iVar11 + iVar17 + *(int *)(param_1 + 0x24)) = uVar6;
                local_5c = *(int *)(param_1 + 0x18);
              }
              local_3c = local_3c + 1;
            } while (local_3c < local_5c);
          }
        } while (local_24 < local_5c + -1);
      }
      local_14 = local_14 + 1;
    } while (local_14 < 3);
    local_14 = 0;
    if (0 < local_5c) {
      do {
        iVar11 = local_14 * 0x10;
        iVar5 = *(int *)(param_1 + 0x24);
        iVar10 = *(int *)(param_1 + 0xc);
        bVar3 = *(byte *)(iVar10 + 0x19 + *(int *)(iVar5 + 4 + iVar11) * 0x58);
        bVar4 = *(byte *)(iVar10 + 0x1a + *(int *)(iVar5 + 8 + iVar11) * 0x58);
        iVar11 = (uint)*(byte *)(iVar10 + 0x18 + *(int *)(iVar5 + iVar11) * 0x58) * 4;
        if (local_14 < *(int *)(iVar11 + iVar15)) {
          *(int *)(iVar11 + iVar15) = local_14;
        }
        iVar5 = (uint)bVar3 * 4;
        if (local_14 < *(int *)(iVar5 + param_1 + 0x428)) {
          *(int *)(iVar5 + param_1 + 0x428) = local_14;
        }
        iVar10 = (uint)bVar4 * 4;
        if (local_14 < *(int *)(iVar10 + param_1 + 0x828)) {
          *(int *)(iVar10 + param_1 + 0x828) = local_14;
        }
        if (*(int *)(iVar11 + iVar8) < local_14) {
          *(int *)(iVar11 + iVar8) = local_14;
        }
        if (*(int *)(iVar5 + param_1 + 0x1028) < local_14) {
          *(int *)(iVar5 + param_1 + 0x1028) = local_14;
        }
        if (*(int *)(iVar10 + param_1 + 0x1428) < local_14) {
          *(int *)(iVar10 + param_1 + 0x1428) = local_14;
        }
        local_14 = local_14 + 1;
      } while (local_14 < *(int *)(param_1 + 0x18));
    }
    memset((void *)(param_1 + 0x187c),0,0x800);
  }
  return;
}


