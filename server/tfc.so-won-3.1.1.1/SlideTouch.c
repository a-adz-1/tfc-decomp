// SlideTouch__8CGrenadeP11CBaseEntity  @ 000b1d48
void SlideTouch__8CGrenadeP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(*param_2 + 0x208) != *(int *)(iVar1 + 0x198)) {
    if ((*(byte *)(iVar1 + 0x1a5) & 2) == 0) {
      (**(code **)(param_1[0x115] + 0x22c))(param_1);
    }
    else {
      *(float *)(iVar1 + 0x20) = *(float *)(iVar1 + 0x20) * 0.95;
      *(float *)(iVar1 + 0x24) = *(float *)(iVar1 + 0x24) * 0.95;
      *(float *)(iVar1 + 0x28) = *(float *)(iVar1 + 0x28) * 0.95;
    }
  }
  return;
}


