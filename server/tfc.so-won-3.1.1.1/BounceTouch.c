// BounceTouch__8CGrenadeP11CBaseEntity  @ 000b1454
void BounceTouch__8CGrenadeP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (*(int *)(*param_2 + 0x208) != *(int *)(iVar3 + 0x198)) {
    if ((*(byte *)(iVar3 + 0x1a5) & 2) == 0) {
      if (param_1[0x1a7] == 0) {
        (**(code **)(param_1[0x115] + 0x22c))(param_1);
      }
    }
    else {
      *(float *)(iVar3 + 0x20) = *(float *)(iVar3 + 0x20) * 0.6;
      *(float *)(iVar3 + 0x24) = *(float *)(iVar3 + 0x24) * 0.6;
      *(float *)(iVar3 + 0x28) = *(float *)(iVar3 + 0x28) * 0.6;
      fVar1 = *(float *)(*param_1 + 0x24);
      fVar2 = *(float *)(*param_1 + 0x28);
      fVar1 = SQRT(fVar2 * fVar2 +
                   fVar1 * fVar1 + *(float *)(*param_1 + 0x20) * *(float *)(*param_1 + 0x20));
      if ((byte)(30.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 30.0) << 0xe) >> 8)) != 1) {
        param_1[0x1a7] = 1;
      }
    }
  }
  return;
}


