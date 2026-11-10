// FindNearestNode__6CGraphRC6VectorP11CBaseEntity  @ 000ca8b0
void FindNearestNode__6CGraphRC6VectorP11CBaseEntity
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = NodeType__6CGraphPC11CBaseEntity(param_1,param_3);
  FindNearestNode__6CGraphRC6Vectori(param_1,param_2,uVar1);
  return;
}


// FindNearestNode__6CGraphRC6Vectori  @ 000ca8e0
int FindNearestNode__6CGraphRC6Vectori(int *param_1,float *param_2,uint param_3)

{
  int *piVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  undefined4 local_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  
  if ((*param_1 == 0) || (param_1[1] == 0)) {
    (*DAT_001755b4)(2,"Graph not ready!\n");
    iVar6 = -1;
  }
  else {
    (*DAT_00175618)(&local_4c);
    (*DAT_0017561c)(&local_4c,param_2,0xc);
    uVar7 = (*DAT_00175624)(local_4c);
    uVar7 = uVar7 & 0x7f;
    pfVar2 = (float *)(param_1 + uVar7 * 4 + 0x61f);
    bVar11 = false;
    if (((byte)((byte)((ushort)((ushort)(NAN(*param_2) || NAN(*pfVar2)) << 10) >> 8) |
               (byte)((ushort)((ushort)(*param_2 == *pfVar2) << 0xe) >> 8)) == 0x40) &&
       ((byte)((byte)((ushort)((ushort)(NAN(param_2[1]) || NAN(pfVar2[1])) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2[1] == pfVar2[1]) << 0xe) >> 8)) == 0x40)) {
      fVar3 = pfVar2[2];
      fVar4 = param_2[2];
      bVar11 = (byte)(fVar4 < fVar3 |
                      (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar3)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar4 == fVar3) << 0xe) >> 8)) == 0x40;
    }
    if (bVar11) {
      iVar6 = (int)(short)param_1[uVar7 * 4 + 0x622];
    }
    else {
      piVar1 = param_1 + 0x618;
      *piVar1 = *piVar1 + 1;
      if (*piVar1 == 0) {
        iVar6 = 0;
        if (0 < param_1[6]) {
          do {
            *(undefined4 *)(param_1[9] + 0xc + iVar6 * 0x10) = 0;
            iVar6 = iVar6 + 1;
          } while (iVar6 < param_1[6]);
        }
        param_1[0x618] = param_1[0x618] + 1;
      }
      param_1[0x60b] = -1;
      param_1[0x60a] = 0x497423f0;
      param_1[0x60c] = 0;
      param_1[0x60f] = 0xff;
      param_1[0x60d] = 0;
      param_1[0x610] = 0xff;
      param_1[0x60e] = 0;
      param_1[0x611] = 0xff;
      param_1[0x612] = 0;
      param_1[0x615] = 0xff;
      param_1[0x613] = 0;
      param_1[0x616] = 0xff;
      param_1[0x614] = 0;
      param_1[0x617] = 0xff;
      iVar6 = 0x7f;
      do {
        iVar10 = param_1[iVar6 + 10];
        if (iVar10 <= param_1[iVar6 + 0x30a]) {
          do {
            iVar5 = param_1[3];
            iVar9 = *(int *)(param_1[9] + iVar10 * 0x10) * 0x58;
            if ((param_3 & *(uint *)(iVar5 + 0x1c + iVar9)) != 0) {
              uVar8 = (uint)*(byte *)(iVar5 + 0x19 + iVar9);
              if (param_1[0x616] < (int)uVar8) break;
              if (((param_1[0x613] <= (int)uVar8) &&
                  (uVar8 = (uint)*(byte *)(iVar5 + 0x1a + iVar9), param_1[0x614] <= (int)uVar8)) &&
                 ((int)uVar8 <= param_1[0x617])) {
                fStack_48 = *param_2;
                fStack_44 = param_2[1];
                fStack_40 = param_2[2];
                CheckNode__6CGraphG6Vectori
                          (param_1,&fStack_48,*(undefined4 *)(param_1[9] + iVar10 * 0x10));
              }
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 <= param_1[iVar6 + 0x30a]);
        }
        iVar6 = iVar6 + -1;
      } while (param_1[0x60c] <= iVar6);
      iVar6 = 0x80;
      if (0x80 < param_1[0x60d]) {
        iVar6 = param_1[0x60d];
      }
      for (; iVar6 <= param_1[0x610]; iVar6 = iVar6 + 1) {
        iVar10 = param_1[iVar6 + 0x10a];
        if (iVar10 <= param_1[iVar6 + 0x40a]) {
          do {
            iVar5 = param_1[3];
            iVar9 = *(int *)(param_1[9] + 4 + iVar10 * 0x10) * 0x58;
            if ((param_3 & *(uint *)(iVar5 + 0x1c + iVar9)) != 0) {
              uVar8 = (uint)*(byte *)(iVar5 + 0x1a + iVar9);
              if (param_1[0x617] < (int)uVar8) break;
              if (((param_1[0x614] <= (int)uVar8) &&
                  (uVar8 = (uint)*(byte *)(iVar5 + 0x18 + iVar9), param_1[0x612] <= (int)uVar8)) &&
                 ((int)uVar8 <= param_1[0x615])) {
                fStack_48 = *param_2;
                fStack_44 = param_2[1];
                fStack_40 = param_2[2];
                CheckNode__6CGraphG6Vectori
                          (param_1,&fStack_48,*(undefined4 *)(param_1[9] + 4 + iVar10 * 0x10));
              }
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 <= param_1[iVar6 + 0x40a]);
        }
      }
      iVar6 = 0x7f;
      if (param_1[0x611] < 0x7f) {
        iVar6 = param_1[0x611];
      }
      for (; param_1[0x60e] <= iVar6; iVar6 = iVar6 + -1) {
        iVar10 = param_1[iVar6 + 0x20a];
        if (iVar10 <= param_1[iVar6 + 0x50a]) {
          do {
            iVar5 = param_1[3];
            iVar9 = *(int *)(param_1[9] + 8 + iVar10 * 0x10) * 0x58;
            if ((param_3 & *(uint *)(iVar5 + 0x1c + iVar9)) != 0) {
              uVar8 = (uint)*(byte *)(iVar5 + 0x18 + iVar9);
              if (param_1[0x615] < (int)uVar8) break;
              if (((param_1[0x612] <= (int)uVar8) &&
                  (uVar8 = (uint)*(byte *)(iVar5 + 0x19 + iVar9), param_1[0x613] <= (int)uVar8)) &&
                 ((int)uVar8 <= param_1[0x616])) {
                fStack_48 = *param_2;
                fStack_44 = param_2[1];
                fStack_40 = param_2[2];
                CheckNode__6CGraphG6Vectori
                          (param_1,&fStack_48,*(undefined4 *)(param_1[9] + 8 + iVar10 * 0x10));
              }
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 <= param_1[iVar6 + 0x50a]);
        }
      }
      iVar6 = 0x80;
      if (0x80 < param_1[0x60c]) {
        iVar6 = param_1[0x60c];
      }
      for (; iVar6 <= param_1[0x60f]; iVar6 = iVar6 + 1) {
        iVar10 = param_1[iVar6 + 10];
        if (iVar10 <= param_1[iVar6 + 0x30a]) {
          do {
            iVar5 = param_1[3];
            iVar9 = *(int *)(param_1[9] + iVar10 * 0x10) * 0x58;
            if ((param_3 & *(uint *)(iVar5 + 0x1c + iVar9)) != 0) {
              uVar8 = (uint)*(byte *)(iVar5 + 0x19 + iVar9);
              if (param_1[0x616] < (int)uVar8) break;
              if (((param_1[0x613] <= (int)uVar8) &&
                  (uVar8 = (uint)*(byte *)(iVar5 + 0x1a + iVar9), param_1[0x614] <= (int)uVar8)) &&
                 ((int)uVar8 <= param_1[0x617])) {
                fStack_48 = *param_2;
                fStack_44 = param_2[1];
                fStack_40 = param_2[2];
                CheckNode__6CGraphG6Vectori
                          (param_1,&fStack_48,*(undefined4 *)(param_1[9] + iVar10 * 0x10));
              }
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 <= param_1[iVar6 + 0x30a]);
        }
      }
      iVar6 = 0x7f;
      if (param_1[0x610] < 0x7f) {
        iVar6 = param_1[0x610];
      }
      for (; param_1[0x60d] <= iVar6; iVar6 = iVar6 + -1) {
        iVar10 = param_1[iVar6 + 0x10a];
        if (iVar10 <= param_1[iVar6 + 0x40a]) {
          do {
            iVar5 = param_1[3];
            iVar9 = *(int *)(param_1[9] + 4 + iVar10 * 0x10) * 0x58;
            if ((param_3 & *(uint *)(iVar5 + 0x1c + iVar9)) != 0) {
              uVar8 = (uint)*(byte *)(iVar5 + 0x1a + iVar9);
              if (param_1[0x617] < (int)uVar8) break;
              if (((param_1[0x614] <= (int)uVar8) &&
                  (uVar8 = (uint)*(byte *)(iVar5 + 0x18 + iVar9), param_1[0x612] <= (int)uVar8)) &&
                 ((int)uVar8 <= param_1[0x615])) {
                fStack_48 = *param_2;
                fStack_44 = param_2[1];
                fStack_40 = param_2[2];
                CheckNode__6CGraphG6Vectori
                          (param_1,&fStack_48,*(undefined4 *)(param_1[9] + 4 + iVar10 * 0x10));
              }
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 <= param_1[iVar6 + 0x40a]);
        }
      }
      iVar6 = 0x80;
      if (0x80 < param_1[0x60e]) {
        iVar6 = param_1[0x60e];
      }
      for (; iVar6 <= param_1[0x611]; iVar6 = iVar6 + 1) {
        iVar10 = param_1[iVar6 + 0x20a];
        if (iVar10 <= param_1[iVar6 + 0x50a]) {
          do {
            iVar5 = param_1[3];
            iVar9 = *(int *)(param_1[9] + 8 + iVar10 * 0x10) * 0x58;
            if ((param_3 & *(uint *)(iVar5 + 0x1c + iVar9)) != 0) {
              uVar8 = (uint)*(byte *)(iVar5 + 0x18 + iVar9);
              if (param_1[0x615] < (int)uVar8) break;
              if (((param_1[0x612] <= (int)uVar8) &&
                  (uVar8 = (uint)*(byte *)(iVar5 + 0x19 + iVar9), param_1[0x613] <= (int)uVar8)) &&
                 ((int)uVar8 <= param_1[0x616])) {
                fStack_48 = *param_2;
                fStack_44 = param_2[1];
                fStack_40 = param_2[2];
                CheckNode__6CGraphG6Vectori
                          (param_1,&fStack_48,*(undefined4 *)(param_1[9] + 8 + iVar10 * 0x10));
              }
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 <= param_1[iVar6 + 0x50a]);
        }
      }
      param_1[uVar7 * 4 + 0x61f] = (int)*param_2;
      param_1[uVar7 * 4 + 0x620] = (int)param_2[1];
      param_1[uVar7 * 4 + 0x621] = (int)param_2[2];
      *(short *)(param_1 + uVar7 * 4 + 0x622) = (short)param_1[0x60b];
      iVar6 = param_1[0x60b];
    }
  }
  return iVar6;
}


