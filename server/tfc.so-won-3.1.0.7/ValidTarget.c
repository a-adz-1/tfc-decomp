// ValidTarget__12CTFSentrygunP11CBaseEntity  @ 000eaefc
undefined4 ValidTarget__12CTFSentrygunP11CBaseEntity(int param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  
  if (((((param_2 != (int *)0x0) &&
        (iVar2 = (**(code **)(param_2[0x111] + 0x8c))(param_2), iVar2 != 0)) && (param_2[0x1c] == 0)
       ) && (((fVar1 = *(float *)(gpGlobals + 0x1c),
              (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40 ||
              (*(int *)(param_1 + 0x120) == 0)) ||
             ((iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,param_2), iVar2 == 0 &&
              (param_2[0x75] != *(int *)(param_1 + 0x120))))))) &&
     (((-1 < *(char *)(*param_2 + 0x1a4) && ((*(byte *)((int)param_2 + 0x8a) & 8) == 0)) &&
      (iVar2 = (**(code **)(*(int *)(param_1 + 0x444) + 0xe0))(param_1,param_2), iVar2 != 0)))) {
    return 1;
  }
  return 0;
}


