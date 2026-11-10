// LookAhead__10CPathTrackP6Vectorfi  @ 000cc3c8
int * LookAhead__10CPathTrackP6Vectorfi(int *param_1,float *param_2,float param_3,int param_4)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  float fVar9;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = *param_2;
  local_c = param_2[1];
  local_8 = param_2[2];
  piVar8 = param_1;
  fVar9 = param_3;
  if ((byte)((0.0 < param_3 | (byte)((ushort)((ushort)NAN(param_3) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_3 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    while (piVar6 = piVar8,
          (byte)(0.0 < fVar9 | (byte)((ushort)((ushort)NAN(fVar9) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar9 == 0.0) << 0xe) >> 8)) == 1) {
      piVar6 = (int *)piVar8[0x11a];
      if ((piVar6 == (int *)0x0) ||
         (piVar7 = piVar6, (*(uint *)(*piVar8 + 0x1a0) & 0x8004) != 0x8000)) {
        piVar7 = (int *)piVar8[0x118];
      }
      if (piVar7 == (int *)0x0) {
LAB_000cc6c3:
        if (param_4 != 0) {
          return (int *)0x0;
        }
        if ((piVar6 == (int *)0x0) || ((*(uint *)(*piVar8 + 0x1a0) & 0x8004) != 0x8004)) {
          piVar6 = (int *)piVar8[0x119];
        }
        goto LAB_000cc6fb;
      }
      if ((param_4 != 0) && ((*(byte *)(*piVar7 + 0x1a0) & 1) != 0)) {
        piVar7 = (int *)0x0;
      }
      if (piVar7 == (int *)0x0) goto LAB_000cc6c3;
      if ((piVar6 == (int *)0x0) || ((*(uint *)(*piVar8 + 0x1a0) & 0x8004) != 0x8000)) {
        piVar6 = (int *)piVar8[0x118];
      }
      iVar1 = *piVar6;
      fVar2 = *(float *)(iVar1 + 8) - local_10;
      fVar5 = *(float *)(iVar1 + 0xc) - local_c;
      fVar4 = *(float *)(iVar1 + 0x10) - local_8;
      fVar3 = SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar2 * fVar2);
      if ((byte)((byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) == 0x40) {
        piVar6 = (int *)piVar8[0x11a];
        if ((piVar6 == (int *)0x0) || ((*(uint *)(*piVar8 + 0x1a0) & 0x8004) != 0x8000)) {
          piVar6 = (int *)piVar8[0x118];
        }
        piVar7 = (int *)piVar6[0x11a];
        if ((piVar7 == (int *)0x0) || ((*(uint *)(*piVar6 + 0x1a0) & 0x8004) != 0x8000)) {
          piVar7 = (int *)piVar6[0x118];
        }
        if (piVar7 == (int *)0x0) {
LAB_000cc7ec:
          if ((byte)(param_3 < fVar9 |
                     (byte)((ushort)((ushort)(NAN(param_3) || NAN(fVar9)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(param_3 == fVar9) << 0xe) >> 8)) == 0x40) {
            return (int *)0x0;
          }
          return piVar8;
        }
        if ((param_4 != 0) && ((*(byte *)(*piVar7 + 0x1a0) & 1) != 0)) {
          piVar7 = (int *)0x0;
        }
        if (piVar7 == (int *)0x0) goto LAB_000cc7ec;
      }
      if (fVar9 < fVar3) {
        fVar9 = fVar9 / fVar3;
        local_8 = fVar9 * fVar4 + local_8;
        *param_2 = fVar2 * fVar9 + local_10;
        param_2[1] = fVar5 * fVar9 + local_c;
        goto LAB_000cc8b8;
      }
      fVar9 = fVar9 - fVar3;
      piVar6 = (int *)piVar8[0x11a];
      if ((piVar6 == (int *)0x0) || ((*(uint *)(*piVar8 + 0x1a0) & 0x8004) != 0x8000)) {
        piVar6 = (int *)piVar8[0x118];
      }
      iVar1 = *piVar6;
      local_10 = *(float *)(iVar1 + 8);
      local_c = *(float *)(iVar1 + 0xc);
      local_8 = *(float *)(iVar1 + 0x10);
      piVar6 = (int *)piVar8[0x11a];
      if ((piVar6 == (int *)0x0) || ((*(uint *)(*piVar8 + 0x1a0) & 0x8004) != 0x8000)) {
        piVar6 = (int *)piVar8[0x118];
      }
      *param_2 = local_10;
      param_2[1] = local_c;
      param_2[2] = local_8;
      piVar8 = piVar6;
    }
  }
  else {
    fVar9 = -param_3;
    piVar6 = param_1;
    if (0x3f < (byte)((fVar9 < 0.0 | (byte)((ushort)((ushort)NAN(fVar9) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar9 == 0.0) << 0xe) >> 8)) - 1)) {
      do {
        fVar4 = *(float *)(*piVar8 + 8) - local_10;
        fVar5 = *(float *)(*piVar8 + 0xc) - local_c;
        fVar2 = *(float *)(*piVar8 + 0x10) - local_8;
        fVar3 = SQRT(fVar2 * fVar2 + fVar5 * fVar5 + fVar4 * fVar4);
        if ((byte)((byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) == 0x40) {
          piVar6 = (int *)piVar8[0x11a];
          if ((piVar6 == (int *)0x0) ||
             (piVar7 = piVar6, (*(uint *)(*piVar8 + 0x1a0) & 0x8004) != 0x8004)) {
            piVar7 = (int *)piVar8[0x119];
          }
          if (piVar7 == (int *)0x0) {
LAB_000cc4e1:
            if (param_4 == 0) {
              if ((piVar6 == (int *)0x0) || ((*(uint *)(*piVar8 + 0x1a0) & 0x8004) != 0x8000)) {
                piVar6 = (int *)piVar8[0x118];
              }
LAB_000cc6fb:
              Project__10CPathTrackP10CPathTrackT1P6Vectorf(param_1,piVar6,piVar8,param_2,fVar9);
            }
            return (int *)0x0;
          }
          if ((param_4 != 0) && ((*(byte *)(*piVar7 + 0x1a0) & 1) != 0)) {
            piVar7 = (int *)0x0;
          }
          if (piVar7 == (int *)0x0) goto LAB_000cc4e1;
        }
        else {
          if (fVar9 < fVar3) {
            fVar9 = fVar9 / fVar3;
            *param_2 = fVar4 * fVar9 + local_10;
            param_2[1] = local_c + fVar5 * fVar9;
            param_2[2] = local_8 + fVar9 * fVar2;
            return piVar8;
          }
          iVar1 = *piVar8;
          fVar9 = fVar9 - fVar3;
          local_10 = *(float *)(iVar1 + 8);
          local_c = *(float *)(iVar1 + 0xc);
          local_8 = *(float *)(iVar1 + 0x10);
          *param_2 = local_10;
          param_2[1] = local_c;
          param_2[2] = local_8;
          piVar6 = (int *)piVar8[0x11a];
          if ((piVar6 == (int *)0x0) ||
             (piVar7 = piVar6, (*(uint *)(*piVar8 + 0x1a0) & 0x8004) != 0x8004)) {
            piVar7 = (int *)piVar8[0x119];
          }
          if (piVar7 == (int *)0x0) {
            return (int *)0x0;
          }
          if ((param_4 != 0) && ((*(byte *)(*piVar7 + 0x1a0) & 1) != 0)) {
            piVar7 = (int *)0x0;
          }
          if (piVar7 == (int *)0x0) {
            return (int *)0x0;
          }
        }
        if ((piVar6 == (int *)0x0) || ((*(uint *)(*piVar8 + 0x1a0) & 0x8004) != 0x8004)) {
          piVar6 = (int *)piVar8[0x119];
        }
        piVar8 = piVar6;
      } while ((byte)(0.0 < fVar9 | (byte)((ushort)((ushort)NAN(fVar9) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar9 == 0.0) << 0xe) >> 8)) == 1);
    }
  }
  *param_2 = local_10;
  param_2[1] = local_c;
  piVar8 = piVar6;
LAB_000cc8b8:
  param_2[2] = local_8;
  return piVar8;
}


