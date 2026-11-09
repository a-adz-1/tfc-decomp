// BuildRegionTables__6CGraph  @ 000ce670
void BuildRegionTables__6CGraph(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  void *pvVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined1 uStack_60;
  int iStack_38;
  int iStack_30;
  int iStack_2c;
  
  if (*(int *)(param_1 + 0x24) != 0) {
    free(*(void **)(param_1 + 0x24));
  }
  pvVar5 = calloc(0x10,*(size_t *)(param_1 + 0x18));
  *(void **)(param_1 + 0x24) = pvVar5;
  if (pvVar5 == (void *)0x0) {
    (*DAT_001755b4)(2,"Couldn\'t allocated node ordering array.\n");
  }
  else {
    iVar12 = 0;
    do {
      *(undefined4 *)(iVar12 * 4 + param_1 + 0x1864) = 0x4e6e6b28;
      *(undefined4 *)(iVar12 * 4 + param_1 + 0x1870) = 0xce6e6b28;
      iVar12 = iVar12 + 1;
    } while (iVar12 < 3);
    iVar12 = 0;
    if (0 < *(int *)(param_1 + 0x18)) {
      do {
        fVar2 = *(float *)(*(int *)(param_1 + 0xc) + iVar12 * 0x58);
        fVar3 = *(float *)(param_1 + 0x1864);
        if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) == 1) {
          *(float *)(param_1 + 0x1864) = fVar2;
        }
        fVar2 = *(float *)(*(int *)(param_1 + 0xc) + 4 + iVar12 * 0x58);
        fVar3 = *(float *)(param_1 + 0x1868);
        if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) == 1) {
          *(float *)(param_1 + 0x1868) = fVar2;
        }
        fVar2 = *(float *)(*(int *)(param_1 + 0xc) + 8 + iVar12 * 0x58);
        fVar3 = *(float *)(param_1 + 0x186c);
        if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) == 1) {
          *(float *)(param_1 + 0x186c) = fVar2;
        }
        fVar2 = *(float *)(*(int *)(param_1 + 0xc) + iVar12 * 0x58);
        if (*(float *)(param_1 + 0x1870) < fVar2) {
          *(float *)(param_1 + 0x1870) = fVar2;
        }
        fVar2 = *(float *)(*(int *)(param_1 + 0xc) + 4 + iVar12 * 0x58);
        if (*(float *)(param_1 + 0x1874) < fVar2) {
          *(float *)(param_1 + 0x1874) = fVar2;
        }
        fVar2 = *(float *)(*(int *)(param_1 + 0xc) + 8 + iVar12 * 0x58);
        if (*(float *)(param_1 + 0x1878) < fVar2) {
          *(float *)(param_1 + 0x1878) = fVar2;
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 < *(int *)(param_1 + 0x18));
    }
    for (iVar12 = 0; iVar12 < *(int *)(param_1 + 0x18); iVar12 = iVar12 + 1) {
      iVar10 = iVar12 * 0x58;
      uStack_60 = (undefined1)
                  ((((int)ROUND(*(float *)(*(int *)(param_1 + 0xc) + iVar10)) -
                    (int)ROUND(*(float *)(param_1 + 0x1864))) * 0x100) /
                  (((int)ROUND(*(float *)(param_1 + 0x1870)) -
                   (int)ROUND(*(float *)(param_1 + 0x1864))) + 1));
      *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x18 + iVar10) = uStack_60;
      uStack_60 = (undefined1)
                  ((((int)ROUND(*(float *)(*(int *)(param_1 + 0xc) + 4 + iVar10)) -
                    (int)ROUND(*(float *)(param_1 + 0x1868))) * 0x100) /
                  (((int)ROUND(*(float *)(param_1 + 0x1874)) -
                   (int)ROUND(*(float *)(param_1 + 0x1868))) + 1));
      *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x19 + iVar10) = uStack_60;
      uStack_60 = (undefined1)
                  ((((int)ROUND(*(float *)(*(int *)(param_1 + 0xc) + 8 + iVar10)) -
                    (int)ROUND(*(float *)(param_1 + 0x186c))) * 0x100) /
                  (((int)ROUND(*(float *)(param_1 + 0x1878)) -
                   (int)ROUND(*(float *)(param_1 + 0x186c))) + 1));
      *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x1a + iVar10) = uStack_60;
    }
    iVar12 = 0;
    do {
      iVar10 = 0;
      do {
        iVar1 = iVar12 * 0x400 + iVar10 * 4;
        *(undefined4 *)(iVar1 + param_1 + 0x28) = 0xff;
        *(undefined4 *)(iVar1 + param_1 + 0xc28) = 0;
        iVar10 = iVar10 + 1;
      } while (iVar10 < 0x100);
      if (0 < *(int *)(param_1 + 0x18)) {
        iVar10 = 0;
        do {
          *(int *)(iVar12 * 4 + iVar10 * 0x10 + *(int *)(param_1 + 0x24)) = iVar10;
          iVar10 = iVar10 + 1;
        } while (iVar10 < *(int *)(param_1 + 0x18));
      }
      if (0 < *(int *)(param_1 + 0x18) + -1) {
        iVar10 = 0;
        do {
          iVar1 = *(int *)(param_1 + 0xc);
          iVar8 = *(int *)(iVar10 * 0x10 + *(int *)(param_1 + 0x24) + iVar12 * 4) * 0x58;
          uVar6 = (uint)*(byte *)(iVar1 + 0x18 + iVar8);
          uVar11 = (uint)*(byte *)(iVar1 + 0x19 + iVar8);
          uVar7 = (uint)*(byte *)(iVar1 + 0x1a + iVar8);
          if (iVar12 == 1) {
            iStack_2c = uVar11 * 0x10000 + uVar7 * 0x100 + uVar6;
          }
          else if (iVar12 < 2) {
            if (iVar12 == 0) {
              iStack_2c = uVar6 * 0x10000 + uVar11 * 0x100 + uVar7;
            }
          }
          else if (iVar12 == 2) {
            iStack_2c = uVar7 * 0x10000 + uVar6 * 0x100 + uVar11;
          }
          iStack_30 = iVar10 + 1;
          if (iStack_30 < *(int *)(param_1 + 0x18)) {
            iVar1 = iVar12 * 4;
            do {
              iVar8 = *(int *)(param_1 + 0xc);
              iVar9 = *(int *)(iVar1 + iStack_30 * 0x10 + *(int *)(param_1 + 0x24)) * 0x58;
              uVar7 = (uint)*(byte *)(iVar8 + 0x18 + iVar9);
              uVar6 = (uint)*(byte *)(iVar8 + 0x19 + iVar9);
              uVar11 = (uint)*(byte *)(iVar8 + 0x1a + iVar9);
              if (iVar12 == 1) {
                iStack_38 = uVar6 * 0x10000 + uVar11 * 0x100 + uVar7;
              }
              else if (iVar12 < 2) {
                if (iVar12 == 0) {
                  iStack_38 = uVar7 * 0x10000 + uVar6 * 0x100 + uVar11;
                }
              }
              else if (iVar12 == 2) {
                iStack_38 = uVar11 * 0x10000 + uVar7 * 0x100 + uVar6;
              }
              if (iStack_38 < iStack_2c) {
                iVar8 = iVar10 * 0x10 + *(int *)(param_1 + 0x24);
                uVar4 = *(undefined4 *)(iVar1 + iVar8);
                *(undefined4 *)(iVar1 + iVar8) =
                     *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x24) + iStack_30 * 0x10);
                *(undefined4 *)(iVar1 + iStack_30 * 0x10 + *(int *)(param_1 + 0x24)) = uVar4;
              }
              iStack_30 = iStack_30 + 1;
            } while (iStack_30 < *(int *)(param_1 + 0x18));
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < *(int *)(param_1 + 0x18) + -1);
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < 3);
    iVar12 = 0;
    if (0 < *(int *)(param_1 + 0x18)) {
      do {
        iVar10 = *(int *)(param_1 + 0x24);
        iVar8 = iVar12 * 0x10;
        iVar1 = *(int *)(param_1 + 0xc);
        uVar6 = (uint)*(byte *)(iVar1 + 0x18 + *(int *)(iVar10 + iVar8) * 0x58);
        uVar7 = (uint)*(byte *)(iVar1 + 0x19 + *(int *)(iVar10 + 4 + iVar8) * 0x58);
        uVar11 = (uint)*(byte *)(iVar1 + 0x1a + *(int *)(iVar10 + 8 + iVar8) * 0x58);
        iVar10 = uVar6 * 4;
        if (iVar12 < *(int *)(iVar10 + param_1 + 0x28)) {
          *(int *)(iVar10 + param_1 + 0x28) = iVar12;
        }
        iVar10 = uVar7 * 4;
        if (iVar12 < *(int *)(iVar10 + param_1 + 0x428)) {
          *(int *)(iVar10 + param_1 + 0x428) = iVar12;
        }
        iVar10 = uVar11 * 4;
        if (iVar12 < *(int *)(iVar10 + param_1 + 0x828)) {
          *(int *)(iVar10 + param_1 + 0x828) = iVar12;
        }
        iVar10 = uVar6 * 4;
        if (*(int *)(iVar10 + param_1 + 0xc28) < iVar12) {
          *(int *)(iVar10 + param_1 + 0xc28) = iVar12;
        }
        iVar10 = uVar7 * 4;
        if (*(int *)(iVar10 + param_1 + 0x1028) < iVar12) {
          *(int *)(iVar10 + param_1 + 0x1028) = iVar12;
        }
        iVar10 = uVar11 * 4;
        if (*(int *)(iVar10 + param_1 + 0x1428) < iVar12) {
          *(int *)(iVar10 + param_1 + 0x1428) = iVar12;
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 < *(int *)(param_1 + 0x18));
    }
    memset((void *)(param_1 + 0x187c),0,0x800);
  }
  return;
}


