// GrenadeTouch__10CTFGrenadeP11CBaseEntity  @ 0010422c
void GrenadeTouch__10CTFGrenadeP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  float fVar2;
  
  if ((param_2 == (int *)0x0) ||
     ((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_2 + 0x16c)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(*param_2 + 0x16c) == 2.0) << 0xe) >> 8)) != 0x40)) {
    (**(code **)(param_1[0x115] + 0x22c))(param_1);
    iVar1 = *param_1;
    if ((*(byte *)(iVar1 + 0x1a5) & 2) != 0) {
      *(float *)(iVar1 + 0x20) = *(float *)(iVar1 + 0x20) * 0.75;
      *(float *)(iVar1 + 0x24) = *(float *)(iVar1 + 0x24) * 0.75;
      *(float *)(iVar1 + 0x28) = *(float *)(iVar1 + 0x28) * 0.75;
      iVar1 = *param_1;
      fVar2 = SQRT(*(float *)(iVar1 + 0x28) * *(float *)(iVar1 + 0x28) +
                   *(float *)(iVar1 + 0x24) * *(float *)(iVar1 + 0x24) +
                   *(float *)(iVar1 + 0x20) * *(float *)(iVar1 + 0x20));
      if ((byte)(20.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == 20.0) << 0xe) >> 8)) != 1) {
        *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
        *(undefined4 *)(iVar1 + 0x60) = DAT_0019f664;
        *(undefined4 *)(iVar1 + 100) = DAT_0019f668;
      }
    }
  }
  else {
    ExplodeTouch__8CGrenadeP11CBaseEntity(param_1,param_2);
  }
  return;
}


