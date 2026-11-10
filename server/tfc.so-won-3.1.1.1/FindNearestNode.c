// FindNearestNode__6CGraphRC6VectorP11CBaseEntity  @ 000cb6b0
void FindNearestNode__6CGraphRC6VectorP11CBaseEntity
               (undefined4 param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  
  if (*(int *)(*param_3 + 0x108) == 5) {
    uVar1 = 2;
    if (*(int *)(*param_3 + 0x1c0) != 0) {
      uVar1 = 4;
    }
  }
  else {
    uVar1 = 1;
  }
  FindNearestNode__6CGraphRC6Vectori(param_1,param_2,uVar1);
  return;
}


// FindNearestNode__6CGraphRC6Vectori  @ 000c527c
int FindNearestNode__6CGraphRC6Vectori(int *param_1,float *param_2,uint param_3)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  int local_c8;
  int local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  float local_40;
  
  if ((*param_1 == 0) || (param_1[1] == 0)) {
    (*DAT_0019f794)(2,"Graph not ready!\n");
    iVar4 = -1;
  }
  else {
    (*DAT_0019f7f8)(&local_4c);
    (*DAT_0019f7fc)(&local_4c,param_2,0xc);
    uVar5 = (*DAT_0019f804)(local_4c);
    uVar5 = uVar5 & 0x7f;
    pfVar1 = (float *)(param_1 + uVar5 * 4 + 0x61f);
    bVar8 = false;
    if (((byte)((byte)((ushort)((ushort)(NAN(*param_2) || NAN(*pfVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(*param_2 == *pfVar1) << 0xe) >> 8)) == 0x40) &&
       ((byte)((byte)((ushort)((ushort)(NAN(param_2[1]) || NAN(pfVar1[1])) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2[1] == pfVar1[1]) << 0xe) >> 8)) == 0x40)) {
      fVar2 = pfVar1[2];
      fVar3 = param_2[2];
      bVar8 = (byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) == 0x40;
    }
    if (bVar8) {
      iVar4 = (int)(short)param_1[uVar5 * 4 + 0x622];
    }
    else {
      iVar4 = param_1[0x618];
      param_1[0x618] = iVar4 + 1;
      if (iVar4 == -1) {
        local_c8 = 0;
        if (0 < param_1[6]) {
          do {
            iVar4 = local_c8 * 0x10;
            local_c8 = local_c8 + 1;
            *(undefined4 *)(param_1[9] + 0xc + iVar4) = 0;
          } while (local_c8 < param_1[6]);
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
      local_50 = 0x7f;
      do {
        local_c8 = param_1[local_50 + 10];
        if (local_c8 <= param_1[local_50 + 0x30a]) {
          do {
            iVar4 = param_1[3];
            iVar6 = *(int *)(param_1[9] + local_c8 * 0x10) * 0x58;
            if ((*(uint *)(iVar4 + 0x1c + iVar6) & param_3) != 0) {
              uVar7 = (uint)*(byte *)(iVar4 + 0x19 + iVar6);
              if (param_1[0x616] < (int)uVar7) break;
              if (((param_1[0x613] <= (int)uVar7) &&
                  (uVar7 = (uint)*(byte *)(iVar4 + 0x1a + iVar6), param_1[0x614] <= (int)uVar7)) &&
                 ((int)uVar7 <= param_1[0x617])) {
                local_48 = *param_2;
                local_44 = param_2[1];
                local_40 = param_2[2];
                CheckNode__6CGraphG6Vectori
                          (param_1,&local_48,*(undefined4 *)(param_1[9] + local_c8 * 0x10));
              }
            }
            local_c8 = local_c8 + 1;
          } while (local_c8 <= param_1[local_50 + 0x30a]);
        }
        local_50 = local_50 + -1;
      } while (param_1[0x60c] <= local_50);
      local_50 = 0x80;
      if (0x80 < param_1[0x60d]) {
        local_50 = param_1[0x60d];
      }
      if (local_50 <= param_1[0x610]) {
        do {
          local_c8 = param_1[local_50 + 0x10a];
          if (local_c8 <= param_1[local_50 + 0x40a]) {
            do {
              iVar4 = param_1[3];
              iVar6 = *(int *)(param_1[9] + 4 + local_c8 * 0x10) * 0x58;
              if ((*(uint *)(iVar4 + 0x1c + iVar6) & param_3) != 0) {
                uVar7 = (uint)*(byte *)(iVar4 + 0x1a + iVar6);
                if (param_1[0x617] < (int)uVar7) break;
                if (((param_1[0x614] <= (int)uVar7) &&
                    (uVar7 = (uint)*(byte *)(iVar4 + 0x18 + iVar6), param_1[0x612] <= (int)uVar7))
                   && ((int)uVar7 <= param_1[0x615])) {
                  local_48 = *param_2;
                  local_44 = param_2[1];
                  local_40 = param_2[2];
                  CheckNode__6CGraphG6Vectori
                            (param_1,&local_48,*(undefined4 *)(param_1[9] + 4 + local_c8 * 0x10));
                }
              }
              local_c8 = local_c8 + 1;
            } while (local_c8 <= param_1[local_50 + 0x40a]);
          }
          local_50 = local_50 + 1;
        } while (local_50 <= param_1[0x610]);
      }
      local_50 = 0x7f;
      if (param_1[0x611] < 0x7f) {
        local_50 = param_1[0x611];
      }
      if (param_1[0x60e] <= local_50) {
        do {
          local_c8 = param_1[local_50 + 0x20a];
          if (local_c8 <= param_1[local_50 + 0x50a]) {
            do {
              iVar4 = param_1[3];
              iVar6 = *(int *)(param_1[9] + 8 + local_c8 * 0x10) * 0x58;
              if ((*(uint *)(iVar4 + 0x1c + iVar6) & param_3) != 0) {
                uVar7 = (uint)*(byte *)(iVar4 + 0x18 + iVar6);
                if (param_1[0x615] < (int)uVar7) break;
                if (((param_1[0x612] <= (int)uVar7) &&
                    (uVar7 = (uint)*(byte *)(iVar4 + 0x19 + iVar6), param_1[0x613] <= (int)uVar7))
                   && ((int)uVar7 <= param_1[0x616])) {
                  local_48 = *param_2;
                  local_44 = param_2[1];
                  local_40 = param_2[2];
                  CheckNode__6CGraphG6Vectori
                            (param_1,&local_48,*(undefined4 *)(param_1[9] + 8 + local_c8 * 0x10));
                }
              }
              local_c8 = local_c8 + 1;
            } while (local_c8 <= param_1[local_50 + 0x50a]);
          }
          local_50 = local_50 + -1;
        } while (param_1[0x60e] <= local_50);
      }
      local_50 = 0x80;
      if (0x80 < param_1[0x60c]) {
        local_50 = param_1[0x60c];
      }
      if (local_50 <= param_1[0x60f]) {
        do {
          local_c8 = param_1[local_50 + 10];
          if (local_c8 <= param_1[local_50 + 0x30a]) {
            do {
              iVar4 = param_1[3];
              iVar6 = *(int *)(param_1[9] + local_c8 * 0x10) * 0x58;
              if ((*(uint *)(iVar4 + 0x1c + iVar6) & param_3) != 0) {
                uVar7 = (uint)*(byte *)(iVar4 + 0x19 + iVar6);
                if (param_1[0x616] < (int)uVar7) break;
                if (((param_1[0x613] <= (int)uVar7) &&
                    (uVar7 = (uint)*(byte *)(iVar4 + 0x1a + iVar6), param_1[0x614] <= (int)uVar7))
                   && ((int)uVar7 <= param_1[0x617])) {
                  local_48 = *param_2;
                  local_44 = param_2[1];
                  local_40 = param_2[2];
                  CheckNode__6CGraphG6Vectori
                            (param_1,&local_48,*(undefined4 *)(param_1[9] + local_c8 * 0x10));
                }
              }
              local_c8 = local_c8 + 1;
            } while (local_c8 <= param_1[local_50 + 0x30a]);
          }
          local_50 = local_50 + 1;
        } while (local_50 <= param_1[0x60f]);
      }
      local_50 = 0x7f;
      if (param_1[0x610] < 0x7f) {
        local_50 = param_1[0x610];
      }
      if (param_1[0x60d] <= local_50) {
        do {
          local_c8 = param_1[local_50 + 0x10a];
          if (local_c8 <= param_1[local_50 + 0x40a]) {
            do {
              iVar4 = param_1[3];
              iVar6 = *(int *)(param_1[9] + 4 + local_c8 * 0x10) * 0x58;
              if ((*(uint *)(iVar4 + 0x1c + iVar6) & param_3) != 0) {
                uVar7 = (uint)*(byte *)(iVar4 + 0x1a + iVar6);
                if (param_1[0x617] < (int)uVar7) break;
                if (((param_1[0x614] <= (int)uVar7) &&
                    (uVar7 = (uint)*(byte *)(iVar4 + 0x18 + iVar6), param_1[0x612] <= (int)uVar7))
                   && ((int)uVar7 <= param_1[0x615])) {
                  local_48 = *param_2;
                  local_44 = param_2[1];
                  local_40 = param_2[2];
                  CheckNode__6CGraphG6Vectori
                            (param_1,&local_48,*(undefined4 *)(param_1[9] + 4 + local_c8 * 0x10));
                }
              }
              local_c8 = local_c8 + 1;
            } while (local_c8 <= param_1[local_50 + 0x40a]);
          }
          local_50 = local_50 + -1;
        } while (param_1[0x60d] <= local_50);
      }
      local_50 = 0x80;
      if (0x80 < param_1[0x60e]) {
        local_50 = param_1[0x60e];
      }
      if (local_50 <= param_1[0x611]) {
        do {
          local_c8 = param_1[local_50 + 0x20a];
          if (local_c8 <= param_1[local_50 + 0x50a]) {
            do {
              iVar4 = param_1[3];
              iVar6 = *(int *)(param_1[9] + 8 + local_c8 * 0x10) * 0x58;
              if ((*(uint *)(iVar4 + 0x1c + iVar6) & param_3) != 0) {
                uVar7 = (uint)*(byte *)(iVar4 + 0x18 + iVar6);
                if (param_1[0x615] < (int)uVar7) break;
                if (((param_1[0x612] <= (int)uVar7) &&
                    (uVar7 = (uint)*(byte *)(iVar4 + 0x19 + iVar6), param_1[0x613] <= (int)uVar7))
                   && ((int)uVar7 <= param_1[0x616])) {
                  local_48 = *param_2;
                  local_44 = param_2[1];
                  local_40 = param_2[2];
                  CheckNode__6CGraphG6Vectori
                            (param_1,&local_48,*(undefined4 *)(param_1[9] + 8 + local_c8 * 0x10));
                }
              }
              local_c8 = local_c8 + 1;
            } while (local_c8 <= param_1[local_50 + 0x50a]);
          }
          local_50 = local_50 + 1;
        } while (local_50 <= param_1[0x611]);
      }
      param_1[uVar5 * 4 + 0x61f] = (int)*param_2;
      param_1[uVar5 * 4 + 0x620] = (int)param_2[1];
      param_1[uVar5 * 4 + 0x621] = (int)param_2[2];
      *(short *)(param_1 + uVar5 * 4 + 0x622) = (short)param_1[0x60b];
      iVar4 = param_1[0x60b];
    }
  }
  return iVar4;
}


