// GetAnimationEvent__FPvP9entvars_sP14MonsterEvent_tffi  @ 00087310
int GetAnimationEvent__FPvP9entvars_sP14MonsterEvent_tffi
              (int param_1,int param_2,undefined4 *param_3,float param_4,float param_5,int param_6)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  
  if (((param_1 != 0) && (*(int *)(param_2 + 0x128) < *(int *)(param_1 + 0xa4))) &&
     (param_3 != (undefined4 *)0x0)) {
    iVar6 = param_1 + *(int *)(param_1 + 0xa8) + *(int *)(param_2 + 0x128) * 0xb0;
    param_1 = param_1 + *(int *)(iVar6 + 0x34);
    iVar1 = *(int *)(iVar6 + 0x30);
    if ((iVar1 != 0) && (param_6 <= iVar1)) {
      if (*(int *)(iVar6 + 0x38) < 2) {
        fVar2 = 0.0;
        fVar3 = 1.0;
      }
      else {
        fVar3 = (float)(*(int *)(iVar6 + 0x38) + -1);
        fVar2 = param_4 * 0.00390625 * fVar3;
        fVar3 = param_5 * 0.00390625 * fVar3;
      }
      for (; param_6 < iVar1; param_6 = param_6 + 1) {
        if (*(int *)(param_1 + 4 + param_6 * 0x4c) < 5000) {
          fVar4 = (float)*(int *)(param_1 + param_6 * 0x4c);
          if (((byte)(fVar4 < fVar2 |
                      (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar2)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar4 == fVar2) << 0xe) >> 8)) != 1) &&
             ((byte)(fVar4 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar3)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar4 == fVar3) << 0xe) >> 8)) == 1)) {
LAB_00087453:
            *param_3 = *(undefined4 *)(param_1 + 4 + param_6 * 0x4c);
            param_3[1] = param_6 * 0x4c + 0xc + param_1;
            return param_6 + 1;
          }
          if ((*(byte *)(iVar6 + 0x24) & 1) != 0) {
            fVar5 = (float)(*(int *)(iVar6 + 0x38) + -1);
            if (((byte)(fVar3 < fVar5 |
                        (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar5)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar3 == fVar5) << 0xe) >> 8)) != 1) &&
               (fVar5 = (fVar3 - (float)*(int *)(iVar6 + 0x38)) + 1.0,
               0x3f < (byte)((fVar5 < fVar4 |
                              (byte)((ushort)((ushort)(NAN(fVar5) || NAN(fVar4)) << 10) >> 8) |
                             (byte)((ushort)((ushort)(fVar5 == fVar4) << 0xe) >> 8)) - 1)))
            goto LAB_00087453;
          }
        }
      }
    }
  }
  return 0;
}


