// BuildRegionTables__6CGraph  @ 000be698
void BuildRegionTables__6CGraph(int param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  void *pvVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  uint uVar12;
  int iStack_84;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_14;
  int local_10;
  
  if (*(int *)(param_1 + 0x24) != 0) {
    free(*(void **)(param_1 + 0x24));
  }
  pvVar4 = calloc(0x10,*(size_t *)(param_1 + 0x18));
  *(void **)(param_1 + 0x24) = pvVar4;
  if (pvVar4 == (void *)0x0) {
    (*DAT_001a7f34)(2,"Couldn\'t allocated node ordering array.\n");
  }
  else {
    *(undefined4 *)(param_1 + 0x1864) = 0x4e6e6b28;
    *(undefined4 *)(param_1 + 0x1870) = 0xce6e6b28;
    *(undefined4 *)(param_1 + 0x1868) = 0x4e6e6b28;
    *(undefined4 *)(param_1 + 0x1874) = 0xce6e6b28;
    *(undefined4 *)(param_1 + 0x186c) = 0x4e6e6b28;
    *(undefined4 *)(param_1 + 0x1878) = 0xce6e6b28;
    local_10 = 0;
    if (0 < *(int *)(param_1 + 0x18)) {
      iVar6 = 0;
      do {
        fVar1 = *(float *)(*(int *)(param_1 + 0xc) + iVar6);
        if (fVar1 < *(float *)(param_1 + 0x1864)) {
          *(float *)(param_1 + 0x1864) = fVar1;
        }
        fVar1 = *(float *)(*(int *)(param_1 + 0xc) + 4 + iVar6);
        if (fVar1 < *(float *)(param_1 + 0x1868)) {
          *(float *)(param_1 + 0x1868) = fVar1;
        }
        fVar1 = *(float *)(*(int *)(param_1 + 0xc) + 8 + iVar6);
        if (fVar1 < *(float *)(param_1 + 0x186c)) {
          *(float *)(param_1 + 0x186c) = fVar1;
        }
        fVar1 = *(float *)(*(int *)(param_1 + 0xc) + iVar6);
        fVar2 = *(float *)(param_1 + 0x1870);
        if (0x3f < (byte)((fVar1 < fVar2 |
                           (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
          *(float *)(param_1 + 0x1870) = fVar1;
        }
        fVar1 = *(float *)(*(int *)(param_1 + 0xc) + 4 + iVar6);
        fVar2 = *(float *)(param_1 + 0x1874);
        if (0x3f < (byte)((fVar1 < fVar2 |
                           (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
          *(float *)(param_1 + 0x1874) = fVar1;
        }
        fVar1 = *(float *)(*(int *)(param_1 + 0xc) + 8 + iVar6);
        fVar2 = *(float *)(param_1 + 0x1878);
        if (0x3f < (byte)((fVar1 < fVar2 |
                           (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
          *(float *)(param_1 + 0x1878) = fVar1;
        }
        iVar6 = iVar6 + 0x58;
        local_10 = local_10 + 1;
      } while (local_10 < *(int *)(param_1 + 0x18));
    }
    local_10 = 0;
    if (0 < *(int *)(param_1 + 0x18)) {
      iVar6 = 0;
      do {
        *(char *)(*(int *)(param_1 + 0xc) + 0x18 + iVar6) =
             (char)((((int)ROUND(*(float *)(*(int *)(param_1 + 0xc) + iVar6)) -
                     (int)ROUND(*(float *)(param_1 + 0x1864))) * 0x100) /
                   (((int)ROUND(*(float *)(param_1 + 0x1870)) -
                    (int)ROUND(*(float *)(param_1 + 0x1864))) + 1));
        *(char *)(*(int *)(param_1 + 0xc) + 0x19 + iVar6) =
             (char)((((int)ROUND(*(float *)(*(int *)(param_1 + 0xc) + 4 + iVar6)) -
                     (int)ROUND(*(float *)(param_1 + 0x1868))) * 0x100) /
                   (((int)ROUND(*(float *)(param_1 + 0x1874)) -
                    (int)ROUND(*(float *)(param_1 + 0x1868))) + 1));
        *(char *)(*(int *)(param_1 + 0xc) + 0x1a + iVar6) =
             (char)((((int)ROUND(*(float *)(*(int *)(param_1 + 0xc) + 8 + iVar6)) -
                     (int)ROUND(*(float *)(param_1 + 0x186c))) * 0x100) /
                   (((int)ROUND(*(float *)(param_1 + 0x1878)) -
                    (int)ROUND(*(float *)(param_1 + 0x186c))) + 1));
        iVar6 = iVar6 + 0x58;
        local_10 = local_10 + 1;
      } while (local_10 < *(int *)(param_1 + 0x18));
    }
    local_10 = 0;
    iStack_38 = 0;
    iStack_3c = 0;
    do {
      iStack_14 = 0;
      puVar7 = (undefined4 *)(iStack_3c + 0xc28 + param_1);
      puVar11 = (undefined4 *)(param_1 + 0x28 + iStack_3c);
      do {
        *puVar11 = 0xff;
        *puVar7 = 0;
        puVar11[1] = 0xff;
        puVar7[1] = 0;
        puVar11[2] = 0xff;
        puVar7[2] = 0;
        puVar11[3] = 0xff;
        puVar7[3] = 0;
        puVar11[4] = 0xff;
        puVar7[4] = 0;
        puVar11[5] = 0xff;
        puVar7[5] = 0;
        puVar11[6] = 0xff;
        puVar7[6] = 0;
        puVar11[7] = 0xff;
        puVar7[7] = 0;
        puVar7 = puVar7 + 8;
        puVar11 = puVar11 + 8;
        iStack_14 = iStack_14 + 8;
      } while (iStack_14 < 0x100);
      iStack_14 = 0;
      if (0 < *(int *)(param_1 + 0x18)) {
        iVar6 = 0;
        do {
          *(int *)(iStack_38 + *(int *)(param_1 + 0x24) + iVar6) = iStack_14;
          iVar6 = iVar6 + 0x10;
          iStack_14 = iStack_14 + 1;
        } while (iStack_14 < *(int *)(param_1 + 0x18));
      }
      iStack_14 = 0;
      if (0 < *(int *)(param_1 + 0x18) + -1) {
        iStack_34 = 0;
        do {
          iVar6 = *(int *)(param_1 + 0xc);
          iVar8 = *(int *)(iStack_38 + iStack_34 + *(int *)(param_1 + 0x24)) * 0x58;
          uVar10 = (uint)*(byte *)(iVar6 + 0x18 + iVar8);
          uVar12 = (uint)*(byte *)(iVar6 + 0x19 + iVar8);
          uVar5 = (uint)*(byte *)(iVar6 + 0x1a + iVar8);
          if (local_10 == 1) {
            iStack_1c = uVar5 * 0x100 + uVar12 * 0x10000 + uVar10;
          }
          else if (local_10 < 2) {
            if (local_10 == 0) {
              iStack_1c = uVar12 * 0x100 + uVar10 * 0x10000 + uVar5;
            }
          }
          else if (local_10 == 2) {
            iStack_1c = uVar10 * 0x100 + uVar5 * 0x10000 + uVar12;
          }
          iStack_20 = iStack_14 + 1;
          if (iStack_20 < *(int *)(param_1 + 0x18)) {
            iVar6 = iStack_20 * 0x10;
            do {
              iVar8 = *(int *)(param_1 + 0xc);
              iVar9 = *(int *)(iStack_38 + *(int *)(param_1 + 0x24) + iVar6) * 0x58;
              uVar12 = (uint)*(byte *)(iVar8 + 0x18 + iVar9);
              uVar5 = (uint)*(byte *)(iVar8 + 0x19 + iVar9);
              uVar10 = (uint)*(byte *)(iVar8 + 0x1a + iVar9);
              if (local_10 == 1) {
                iStack_24 = uVar5 * 0x10000 + uVar10 * 0x100 + uVar12;
              }
              else if (local_10 < 2) {
                if (local_10 == 0) {
                  iStack_24 = uVar10 + uVar12 * 0x10000 + uVar5 * 0x100;
                }
              }
              else if (local_10 == 2) {
                iStack_24 = uVar12 * 0x100 + uVar10 * 0x10000 + uVar5;
              }
              if (iStack_24 < iStack_1c) {
                iVar8 = iStack_34 + *(int *)(param_1 + 0x24);
                uVar3 = *(undefined4 *)(iStack_38 + iVar8);
                *(undefined4 *)(iStack_38 + iVar8) =
                     *(undefined4 *)(iStack_38 + *(int *)(param_1 + 0x24) + iVar6);
                *(undefined4 *)(iStack_38 + *(int *)(param_1 + 0x24) + iVar6) = uVar3;
              }
              iVar6 = iVar6 + 0x10;
              iStack_20 = iStack_20 + 1;
            } while (iStack_20 < *(int *)(param_1 + 0x18));
          }
          iStack_34 = iStack_34 + 0x10;
          iStack_14 = iStack_14 + 1;
        } while (iStack_14 < *(int *)(param_1 + 0x18) + -1);
      }
      iStack_38 = iStack_38 + 4;
      iStack_3c = iStack_3c + 0x400;
      local_10 = local_10 + 1;
    } while (local_10 < 3);
    local_10 = 0;
    if (0 < *(int *)(param_1 + 0x18)) {
      iStack_84 = 0;
      do {
        iVar6 = *(int *)(param_1 + 0x24);
        iVar8 = *(int *)(param_1 + 0xc);
        uVar5 = (uint)*(byte *)(iVar8 + 0x18 + *(int *)(iVar6 + iStack_84) * 0x58);
        uVar12 = (uint)*(byte *)(iVar8 + 0x19 + *(int *)(iVar6 + 4 + iStack_84) * 0x58);
        uVar10 = (uint)*(byte *)(iVar8 + 0x1a + *(int *)(iVar6 + 8 + iStack_84) * 0x58);
        iVar6 = uVar5 * 4;
        if (local_10 < *(int *)(iVar6 + param_1 + 0x28)) {
          *(int *)(iVar6 + param_1 + 0x28) = local_10;
        }
        iVar6 = uVar12 * 4;
        if (local_10 < *(int *)(iVar6 + param_1 + 0x428)) {
          *(int *)(iVar6 + param_1 + 0x428) = local_10;
        }
        iVar6 = uVar10 * 4;
        if (local_10 < *(int *)(iVar6 + param_1 + 0x828)) {
          *(int *)(iVar6 + param_1 + 0x828) = local_10;
        }
        iVar6 = uVar5 * 4;
        if (*(int *)(iVar6 + param_1 + 0xc28) < local_10) {
          *(int *)(iVar6 + param_1 + 0xc28) = local_10;
        }
        iVar6 = uVar12 * 4;
        if (*(int *)(iVar6 + param_1 + 0x1028) < local_10) {
          *(int *)(iVar6 + param_1 + 0x1028) = local_10;
        }
        iVar6 = uVar10 * 4;
        if (*(int *)(iVar6 + param_1 + 0x1428) < local_10) {
          *(int *)(iVar6 + param_1 + 0x1428) = local_10;
        }
        iStack_84 = iStack_84 + 0x10;
        local_10 = local_10 + 1;
      } while (local_10 < *(int *)(param_1 + 0x18));
    }
    memset((void *)(param_1 + 0x187c),0,0x800);
  }
  return;
}


