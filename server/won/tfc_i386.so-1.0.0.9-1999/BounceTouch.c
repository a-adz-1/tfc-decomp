// BounceTouch__8CGrenadeP11CBaseEntity  @ 000b97b0
void BounceTouch__8CGrenadeP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(*param_2 + 0x1e8) != *(int *)(iVar1 + 0x178)) {
    if ((*(byte *)(iVar1 + 0x185) & 2) == 0) {
      (**(code **)(param_1[0xf2] + 0x224))(param_1);
    }
    else {
      *(float *)(iVar1 + 0x20) = *(float *)(iVar1 + 0x20) * 0.6;
      *(float *)(iVar1 + 0x24) = *(float *)(iVar1 + 0x24) * 0.6;
      *(float *)(iVar1 + 0x28) = *(float *)(iVar1 + 0x28) * 0.6;
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
  return;
}


