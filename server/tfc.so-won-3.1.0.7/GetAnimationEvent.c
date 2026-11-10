// GetAnimationEvent__FPvP9entvars_sP14MonsterEvent_tffi  @ 00087a24
int GetAnimationEvent__FPvP9entvars_sP14MonsterEvent_tffi
              (int param_1,int param_2,int *param_3,float param_4,float param_5,int param_6)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int local_10;
  
  if (((param_1 != 0) && (*(int *)(param_2 + 0x128) < *(int *)(param_1 + 0xa4))) &&
     (param_3 != (int *)0x0)) {
    iVar1 = *(int *)(param_2 + 0x128) * 0xb0 + param_1 + *(int *)(param_1 + 0xa8);
    param_1 = param_1 + *(int *)(iVar1 + 0x34);
    if ((*(int *)(iVar1 + 0x30) != 0) && (param_6 <= *(int *)(iVar1 + 0x30))) {
      if (*(int *)(iVar1 + 0x38) < 2) {
        fVar2 = 0.0;
        fVar3 = 1.0;
      }
      else {
        fVar3 = (float)(*(int *)(iVar1 + 0x38) + -1);
        fVar2 = param_4 * 0.00390625 * fVar3;
        fVar3 = param_5 * 0.00390625 * fVar3;
      }
      if (param_6 < *(int *)(iVar1 + 0x30)) {
        iVar8 = param_6 * 0x4c;
        local_10 = param_1 + 0xc + iVar8;
        piVar6 = (int *)(iVar8 + param_1);
        piVar7 = (int *)(param_1 + 4 + iVar8);
        do {
          if (*piVar7 < 5000) {
            fVar4 = (float)*piVar6;
            if (((byte)(fVar4 < fVar2 |
                        (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar2)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar4 == fVar2) << 0xe) >> 8)) != 1) &&
               ((byte)(fVar4 < fVar3 |
                       (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar3)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar4 == fVar3) << 0xe) >> 8)) == 1)) {
LAB_00087b78:
              *param_3 = *piVar7;
              param_3[1] = local_10;
              return param_6 + 1;
            }
            if (((*(byte *)(iVar1 + 0x24) & 1) != 0) &&
               (fVar4 = (float)(*(int *)(iVar1 + 0x38) + -1),
               (byte)(fVar3 < fVar4 |
                      (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar4)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar3 == fVar4) << 0xe) >> 8)) != 1)) {
              fVar4 = (fVar3 - (float)*(int *)(iVar1 + 0x38)) + 1.0;
              fVar5 = (float)*piVar6;
              if (0x3f < (byte)((fVar4 < fVar5 |
                                 (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar5)) << 10) >> 8) |
                                (byte)((ushort)((ushort)(fVar4 == fVar5) << 0xe) >> 8)) - 1))
              goto LAB_00087b78;
            }
          }
          local_10 = local_10 + 0x4c;
          piVar6 = piVar6 + 0x13;
          piVar7 = piVar7 + 0x13;
          param_6 = param_6 + 1;
        } while (param_6 < *(int *)(iVar1 + 0x30));
      }
    }
  }
  return 0;
}


