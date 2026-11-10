// LookAhead__10CPathTrackP6Vectorfi  @ 000c17a4
int * LookAhead__10CPathTrackP6Vectorfi(int *param_1,float *param_2,float param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  float local_c;
  float local_8;
  float local_4;
  
  fVar1 = param_3;
  local_c = *param_2;
  local_8 = param_2[1];
  local_4 = param_2[2];
  piVar8 = param_1;
  if ((byte)((0.0 < param_3 | (byte)((ushort)((ushort)NAN(param_3) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_3 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    while ((byte)(0.0 < param_3 | (byte)((ushort)((ushort)NAN(param_3) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_3 == 0.0) << 0xe) >> 8)) == 1) {
      uVar6 = GetNext__10CPathTrack(piVar8,param_4);
      iVar7 = ValidPath__10CPathTrackP10CPathTracki(param_1,uVar6);
      if (iVar7 == 0) {
        if (param_4 != 0) {
          return (int *)0x0;
        }
        uVar6 = GetPrevious__10CPathTrack(piVar8,piVar8,param_2,param_3);
        goto LAB_000c1a03;
      }
      piVar9 = (int *)GetNext__10CPathTrack(piVar8);
      iVar7 = *piVar9;
      fVar2 = *(float *)(iVar7 + 8) - local_c;
      fVar5 = *(float *)(iVar7 + 0xc) - local_8;
      fVar4 = *(float *)(iVar7 + 0x10) - local_4;
      fVar3 = SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar2 * fVar2);
      if ((byte)((byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) == 0x40) {
        uVar6 = GetNext__10CPathTrack(piVar8,param_4);
        uVar6 = GetNext__10CPathTrack(uVar6);
        iVar7 = ValidPath__10CPathTrackP10CPathTracki(param_1,uVar6);
        if (iVar7 == 0) {
          if ((byte)(fVar1 < param_3 |
                     (byte)((ushort)((ushort)(NAN(fVar1) || NAN(param_3)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == param_3) << 0xe) >> 8)) == 0x40) {
            return (int *)0x0;
          }
          return piVar8;
        }
      }
      if (param_3 < fVar3) {
        param_3 = param_3 / fVar3;
        local_c = local_c + param_3 * fVar2;
        local_8 = local_8 + param_3 * fVar5;
        local_4 = local_4 + param_3 * fVar4;
        goto LAB_000c19aa;
      }
      param_3 = param_3 - fVar3;
      piVar9 = (int *)GetNext__10CPathTrack(piVar8);
      iVar7 = *piVar9;
      local_c = *(float *)(iVar7 + 8);
      local_8 = *(float *)(iVar7 + 0xc);
      local_4 = *(float *)(iVar7 + 0x10);
      piVar8 = (int *)GetNext__10CPathTrack(piVar8);
      *param_2 = local_c;
      param_2[1] = local_8;
      param_2[2] = local_4;
    }
  }
  else {
    param_3 = -param_3;
    if (0x3f < (byte)((param_3 < 0.0 | (byte)((ushort)((ushort)NAN(param_3) << 10) >> 8) |
                      (byte)((ushort)((ushort)(param_3 == 0.0) << 0xe) >> 8)) - 1)) {
      do {
        fVar1 = *(float *)(*piVar8 + 8) - local_c;
        fVar4 = *(float *)(*piVar8 + 0xc) - local_8;
        fVar3 = *(float *)(*piVar8 + 0x10) - local_4;
        fVar2 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar1 * fVar1);
        if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
          uVar6 = GetPrevious__10CPathTrack(piVar8,param_4);
          iVar7 = ValidPath__10CPathTrackP10CPathTracki(param_1,uVar6);
          if (iVar7 == 0) {
            if (param_4 == 0) {
              uVar6 = GetNext__10CPathTrack(piVar8,piVar8,param_2,param_3);
LAB_000c1a03:
              Project__10CPathTrackP10CPathTrackT1P6Vectorf(param_1,uVar6);
            }
            return (int *)0x0;
          }
        }
        else {
          if (param_3 < fVar2) {
            param_3 = param_3 / fVar2;
            local_c = local_c + param_3 * fVar1;
            local_8 = local_8 + param_3 * fVar4;
            local_4 = local_4 + param_3 * fVar3;
LAB_000c19aa:
            *param_2 = local_c;
            param_2[1] = local_8;
            goto LAB_000c1b56;
          }
          param_3 = param_3 - fVar2;
          iVar7 = *piVar8;
          local_c = *(float *)(iVar7 + 8);
          local_8 = *(float *)(iVar7 + 0xc);
          local_4 = *(float *)(iVar7 + 0x10);
          param_2[2] = local_4;
          *param_2 = local_c;
          param_2[1] = local_8;
          uVar6 = GetPrevious__10CPathTrack(piVar8,param_4);
          iVar7 = ValidPath__10CPathTrackP10CPathTracki(param_1,uVar6);
          if (iVar7 == 0) {
            return (int *)0x0;
          }
        }
        piVar8 = (int *)GetPrevious__10CPathTrack(piVar8);
      } while ((byte)(0.0 < param_3 | (byte)((ushort)((ushort)NAN(param_3) << 10) >> 8) |
                     (byte)((ushort)((ushort)(param_3 == 0.0) << 0xe) >> 8)) == 1);
    }
  }
  *param_2 = local_c;
  param_2[1] = local_8;
LAB_000c1b56:
  param_2[2] = local_4;
  return piVar8;
}


