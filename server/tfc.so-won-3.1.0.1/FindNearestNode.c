// FindNearestNode__6CGraphRC6VectorP11CBaseEntity  @ 000b9b80
void FindNearestNode__6CGraphRC6VectorP11CBaseEntity
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = NodeType__6CGraphPC11CBaseEntity(param_1,param_3);
  FindNearestNode__6CGraphRC6Vectori(param_1,param_2,uVar1);
  return;
}


// FindNearestNode__6CGraphRC6Vectori  @ 000b9bb4
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
  int iStack_ac;
  int *piStack_a8;
  int iStack_a4;
  int iStack_a0;
  int *piStack_9c;
  int iStack_98;
  int iStack_94;
  int *piStack_90;
  int iStack_8c;
  int iStack_88;
  int *piStack_84;
  int iStack_80;
  int iStack_7c;
  int *piStack_78;
  int iStack_74;
  int iStack_70;
  int *piStack_6c;
  int iStack_68;
  undefined4 local_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  
  if ((*param_1 == 0) || (param_1[1] == 0)) {
    (*DAT_001a7f34)(2,"Graph not ready!\n");
    iVar6 = -1;
  }
  else {
    (*DAT_001a7f98)(&local_48);
    (*DAT_001a7f9c)(&local_48,param_2,0xc);
    uVar7 = (*DAT_001a7fa4)(local_48);
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
          iVar10 = 0;
          do {
            *(undefined4 *)(param_1[9] + 0xc + iVar10) = 0;
            iVar10 = iVar10 + 0x10;
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
      piStack_a8 = param_1 + 0x389;
      iStack_ac = 0x1fc;
      do {
        iVar10 = *(int *)(iStack_ac + 0x28 + (int)param_1);
        if (iVar10 <= *piStack_a8) {
          iStack_a4 = iVar10 << 4;
          do {
            iVar5 = param_1[3];
            iVar9 = *(int *)(param_1[9] + iStack_a4) * 0x58;
            if ((param_3 & *(uint *)(iVar5 + 0x1c + iVar9)) != 0) {
              uVar8 = (uint)*(byte *)(iVar5 + 0x19 + iVar9);
              if (param_1[0x616] < (int)uVar8) break;
              if (((param_1[0x613] <= (int)uVar8) &&
                  (uVar8 = (uint)*(byte *)(iVar5 + 0x1a + iVar9), param_1[0x614] <= (int)uVar8)) &&
                 ((int)uVar8 <= param_1[0x617])) {
                fStack_44 = *param_2;
                fStack_40 = param_2[1];
                fStack_3c = param_2[2];
                CheckNode__6CGraphG6Vectori
                          (param_1,&fStack_44,*(undefined4 *)(param_1[9] + iStack_a4));
              }
            }
            iStack_a4 = iStack_a4 + 0x10;
            iVar10 = iVar10 + 1;
          } while (iVar10 <= *piStack_a8);
        }
        piStack_a8 = piStack_a8 + -1;
        iStack_ac = iStack_ac + -4;
        iVar6 = iVar6 + -1;
      } while (param_1[0x60c] <= iVar6);
      iVar6 = 0x80;
      if (0x80 < param_1[0x60d]) {
        iVar6 = param_1[0x60d];
      }
      if (iVar6 <= param_1[0x610]) {
        piStack_9c = param_1 + iVar6 + 0x40a;
        iStack_a0 = iVar6 * 4;
        do {
          iVar10 = *(int *)(iStack_a0 + 0x428 + (int)param_1);
          if (iVar10 <= *piStack_9c) {
            iStack_98 = iVar10 << 4;
            do {
              iVar5 = param_1[3];
              iVar9 = *(int *)(param_1[9] + 4 + iStack_98) * 0x58;
              if ((param_3 & *(uint *)(iVar5 + 0x1c + iVar9)) != 0) {
                uVar8 = (uint)*(byte *)(iVar5 + 0x1a + iVar9);
                if (param_1[0x617] < (int)uVar8) break;
                if (((param_1[0x614] <= (int)uVar8) &&
                    (uVar8 = (uint)*(byte *)(iVar5 + 0x18 + iVar9), param_1[0x612] <= (int)uVar8))
                   && ((int)uVar8 <= param_1[0x615])) {
                  fStack_44 = *param_2;
                  fStack_40 = param_2[1];
                  fStack_3c = param_2[2];
                  CheckNode__6CGraphG6Vectori
                            (param_1,&fStack_44,*(undefined4 *)(param_1[9] + 4 + iStack_98));
                }
              }
              iStack_98 = iStack_98 + 0x10;
              iVar10 = iVar10 + 1;
            } while (iVar10 <= *piStack_9c);
          }
          piStack_9c = piStack_9c + 1;
          iStack_a0 = iStack_a0 + 4;
          iVar6 = iVar6 + 1;
        } while (iVar6 <= param_1[0x610]);
      }
      iVar6 = 0x7f;
      if (param_1[0x611] < 0x7f) {
        iVar6 = param_1[0x611];
      }
      if (param_1[0x60e] <= iVar6) {
        piStack_90 = param_1 + iVar6 + 0x50a;
        iStack_94 = iVar6 * 4;
        do {
          iVar10 = *(int *)(iStack_94 + 0x828 + (int)param_1);
          if (iVar10 <= *piStack_90) {
            iStack_8c = iVar10 << 4;
            do {
              iVar5 = param_1[3];
              iVar9 = *(int *)(param_1[9] + 8 + iStack_8c) * 0x58;
              if ((param_3 & *(uint *)(iVar5 + 0x1c + iVar9)) != 0) {
                uVar8 = (uint)*(byte *)(iVar5 + 0x18 + iVar9);
                if (param_1[0x615] < (int)uVar8) break;
                if (((param_1[0x612] <= (int)uVar8) &&
                    (uVar8 = (uint)*(byte *)(iVar5 + 0x19 + iVar9), param_1[0x613] <= (int)uVar8))
                   && ((int)uVar8 <= param_1[0x616])) {
                  fStack_44 = *param_2;
                  fStack_40 = param_2[1];
                  fStack_3c = param_2[2];
                  CheckNode__6CGraphG6Vectori
                            (param_1,&fStack_44,*(undefined4 *)(param_1[9] + 8 + iStack_8c));
                }
              }
              iStack_8c = iStack_8c + 0x10;
              iVar10 = iVar10 + 1;
            } while (iVar10 <= *piStack_90);
          }
          piStack_90 = piStack_90 + -1;
          iStack_94 = iStack_94 + -4;
          iVar6 = iVar6 + -1;
        } while (param_1[0x60e] <= iVar6);
      }
      iVar6 = 0x80;
      if (0x80 < param_1[0x60c]) {
        iVar6 = param_1[0x60c];
      }
      if (iVar6 <= param_1[0x60f]) {
        piStack_84 = param_1 + iVar6 + 0x30a;
        iStack_88 = iVar6 * 4;
        do {
          iVar10 = *(int *)(iStack_88 + 0x28 + (int)param_1);
          if (iVar10 <= *piStack_84) {
            iStack_80 = iVar10 << 4;
            do {
              iVar5 = param_1[3];
              iVar9 = *(int *)(param_1[9] + iStack_80) * 0x58;
              if ((param_3 & *(uint *)(iVar5 + 0x1c + iVar9)) != 0) {
                uVar8 = (uint)*(byte *)(iVar5 + 0x19 + iVar9);
                if (param_1[0x616] < (int)uVar8) break;
                if (((param_1[0x613] <= (int)uVar8) &&
                    (uVar8 = (uint)*(byte *)(iVar5 + 0x1a + iVar9), param_1[0x614] <= (int)uVar8))
                   && ((int)uVar8 <= param_1[0x617])) {
                  fStack_44 = *param_2;
                  fStack_40 = param_2[1];
                  fStack_3c = param_2[2];
                  CheckNode__6CGraphG6Vectori
                            (param_1,&fStack_44,*(undefined4 *)(param_1[9] + iStack_80));
                }
              }
              iStack_80 = iStack_80 + 0x10;
              iVar10 = iVar10 + 1;
            } while (iVar10 <= *piStack_84);
          }
          piStack_84 = piStack_84 + 1;
          iStack_88 = iStack_88 + 4;
          iVar6 = iVar6 + 1;
        } while (iVar6 <= param_1[0x60f]);
      }
      iVar6 = 0x7f;
      if (param_1[0x610] < 0x7f) {
        iVar6 = param_1[0x610];
      }
      if (param_1[0x60d] <= iVar6) {
        piStack_78 = param_1 + iVar6 + 0x40a;
        iStack_7c = iVar6 * 4;
        do {
          iVar10 = *(int *)(iStack_7c + 0x428 + (int)param_1);
          if (iVar10 <= *piStack_78) {
            iStack_74 = iVar10 << 4;
            do {
              iVar5 = param_1[3];
              iVar9 = *(int *)(param_1[9] + 4 + iStack_74) * 0x58;
              if ((param_3 & *(uint *)(iVar5 + 0x1c + iVar9)) != 0) {
                uVar8 = (uint)*(byte *)(iVar5 + 0x1a + iVar9);
                if (param_1[0x617] < (int)uVar8) break;
                if (((param_1[0x614] <= (int)uVar8) &&
                    (uVar8 = (uint)*(byte *)(iVar5 + 0x18 + iVar9), param_1[0x612] <= (int)uVar8))
                   && ((int)uVar8 <= param_1[0x615])) {
                  fStack_44 = *param_2;
                  fStack_40 = param_2[1];
                  fStack_3c = param_2[2];
                  CheckNode__6CGraphG6Vectori
                            (param_1,&fStack_44,*(undefined4 *)(param_1[9] + 4 + iStack_74));
                }
              }
              iStack_74 = iStack_74 + 0x10;
              iVar10 = iVar10 + 1;
            } while (iVar10 <= *piStack_78);
          }
          piStack_78 = piStack_78 + -1;
          iStack_7c = iStack_7c + -4;
          iVar6 = iVar6 + -1;
        } while (param_1[0x60d] <= iVar6);
      }
      iVar6 = 0x80;
      if (0x80 < param_1[0x60e]) {
        iVar6 = param_1[0x60e];
      }
      if (iVar6 <= param_1[0x611]) {
        piStack_6c = param_1 + iVar6 + 0x50a;
        iStack_70 = iVar6 * 4;
        do {
          iVar10 = *(int *)(iStack_70 + 0x828 + (int)param_1);
          if (iVar10 <= *piStack_6c) {
            iStack_68 = iVar10 << 4;
            do {
              iVar5 = param_1[3];
              iVar9 = *(int *)(param_1[9] + 8 + iStack_68) * 0x58;
              if ((param_3 & *(uint *)(iVar5 + 0x1c + iVar9)) != 0) {
                uVar8 = (uint)*(byte *)(iVar5 + 0x18 + iVar9);
                if (param_1[0x615] < (int)uVar8) break;
                if (((param_1[0x612] <= (int)uVar8) &&
                    (uVar8 = (uint)*(byte *)(iVar5 + 0x19 + iVar9), param_1[0x613] <= (int)uVar8))
                   && ((int)uVar8 <= param_1[0x616])) {
                  fStack_44 = *param_2;
                  fStack_40 = param_2[1];
                  fStack_3c = param_2[2];
                  CheckNode__6CGraphG6Vectori
                            (param_1,&fStack_44,*(undefined4 *)(param_1[9] + 8 + iStack_68));
                }
              }
              iStack_68 = iStack_68 + 0x10;
              iVar10 = iVar10 + 1;
            } while (iVar10 <= *piStack_6c);
          }
          piStack_6c = piStack_6c + 1;
          iStack_70 = iStack_70 + 4;
          iVar6 = iVar6 + 1;
        } while (iVar6 <= param_1[0x611]);
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


