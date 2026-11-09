// GetAnimationEvent__FPvP9entvars_tP14MonsterEvent_tffi  @ 0009aee0
int GetAnimationEvent__FPvP9entvars_tP14MonsterEvent_tffi
              (int param_1,int param_2,undefined4 *param_3,float param_4,float param_5,int param_6)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  if (((param_1 != 0) && (*(int *)(param_2 + 0x108) < *(int *)(param_1 + 0xa4))) &&
     (param_3 != (undefined4 *)0x0)) {
    iVar3 = param_1 + *(int *)(param_1 + 0xa8) + *(int *)(param_2 + 0x108) * 0xb0;
    param_1 = param_1 + *(int *)(iVar3 + 0x34);
    if ((*(int *)(iVar3 + 0x30) != 0) && (param_6 <= *(int *)(iVar3 + 0x30))) {
      if (*(int *)(iVar3 + 0x38) < 2) {
        param_4 = 0.0;
        fVar1 = 1.0;
      }
      else {
        fVar1 = (float)(*(int *)(iVar3 + 0x38) + -1) * 0.00390625;
        param_4 = fVar1 * param_4;
        fVar1 = fVar1 * param_5;
      }
      for (; param_6 < *(int *)(iVar3 + 0x30); param_6 = param_6 + 1) {
        if ((*(int *)(param_1 + 4 + param_6 * 0x4c) < 5000) &&
           (((fVar2 = (float)*(int *)(param_1 + param_6 * 0x4c), param_4 <= fVar2 &&
             ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1)) ||
            (((*(byte *)(iVar3 + 0x24) & 1) != 0 &&
             (((float)(*(int *)(iVar3 + 0x38) + -1) <= fVar1 &&
              ((float)*(int *)(param_1 + param_6 * 0x4c) <
               (fVar1 - (float)*(int *)(iVar3 + 0x38)) + 1.0)))))))) {
          *param_3 = *(undefined4 *)(param_1 + 4 + param_6 * 0x4c);
          param_3[1] = param_6 * 0x4c + 0xc + param_1;
          return param_6 + 1;
        }
      }
    }
  }
  return 0;
}


