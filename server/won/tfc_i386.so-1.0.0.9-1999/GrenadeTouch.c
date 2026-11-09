// GrenadeTouch__10CTFGrenadeP11CBaseEntity  @ 000fb5d0
void GrenadeTouch__10CTFGrenadeP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((param_2 == (int *)0x0) ||
     ((byte)((byte)((ushort)((ushort)NAN(*(float *)(*param_2 + 0x14c)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(*param_2 + 0x14c) == 2.0) << 0xe) >> 8)) != 0x40)) {
    (**(code **)(param_1[0xf2] + 0x224))(param_1);
    iVar1 = *param_1;
    if ((*(byte *)(iVar1 + 0x185) & 2) != 0) {
      *(float *)(iVar1 + 0x20) = *(float *)(iVar1 + 0x20) * 0.75;
      *(float *)(iVar1 + 0x24) = *(float *)(iVar1 + 0x24) * 0.75;
      *(float *)(iVar1 + 0x28) = *(float *)(iVar1 + 0x28) * 0.75;
      iVar1 = *param_1;
      if (SQRT(*(float *)(iVar1 + 0x28) * *(float *)(iVar1 + 0x28) +
               *(float *)(iVar1 + 0x24) * *(float *)(iVar1 + 0x24) +
               *(float *)(iVar1 + 0x20) * *(float *)(iVar1 + 0x20)) <= 20.0) {
        *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
        *(undefined4 *)(iVar1 + 0x60) = DAT_00175484;
        *(undefined4 *)(iVar1 + 100) = DAT_00175488;
      }
    }
  }
  else {
    ExplodeTouch__8CGrenadeP11CBaseEntity(param_1,param_2);
  }
  return;
}


