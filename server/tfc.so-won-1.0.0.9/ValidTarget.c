// ValidTarget__12CTFSentrygunP11CBaseEntity  @ 000e9ab0
undefined4 ValidTarget__12CTFSentrygunP11CBaseEntity(int param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  
  if (((((param_2 != (int *)0x0) &&
        (iVar2 = (**(code **)(param_2[0xf2] + 0x88))(param_2), iVar2 != 0)) && (param_2[0x1d] == 0))
      && (((fVar1 = *(float *)(gpGlobals + 0x1c),
           (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40 ||
           (*(int *)(param_1 + 0x120) == 0)) ||
          ((param_2[0x48] != *(int *)(param_1 + 0x120) &&
           (param_2[0x75] != *(int *)(param_1 + 0x120))))))) &&
     (((-1 < *(char *)(*param_2 + 0x184) && ((*(byte *)((int)param_2 + 0x8e) & 8) == 0)) &&
      (iVar2 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0xd8))(param_1,param_2), iVar2 != 0)))) {
    return 1;
  }
  return 0;
}


