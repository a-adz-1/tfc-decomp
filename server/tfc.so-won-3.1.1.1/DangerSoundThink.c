// DangerSoundThink__8CGrenade  @ 000b1320
void DangerSoundThink__8CGrenade(int *param_1)

{
  int iVar1;
  float local_10;
  float local_c;
  float local_8;
  
  iVar1 = (**(code **)(param_1[0x115] + 0x9c))(param_1);
  if (iVar1 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    iVar1 = *param_1;
    local_10 = *(float *)(iVar1 + 0x20) * 0.5 + *(float *)(iVar1 + 8);
    local_c = *(float *)(iVar1 + 0x24) * 0.5 + *(float *)(iVar1 + 0xc);
    local_8 = *(float *)(iVar1 + 0x28) * 0.5 + *(float *)(iVar1 + 0x10);
    InsertSound__9CSoundEntiRC6Vectorif
              (0x20,&local_10,
               (int)ROUND(SQRT(*(float *)(iVar1 + 0x28) * *(float *)(iVar1 + 0x28) +
                               *(float *)(iVar1 + 0x24) * *(float *)(iVar1 + 0x24) +
                               *(float *)(iVar1 + 0x20) * *(float *)(iVar1 + 0x20))),0x3e4ccccd);
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
    iVar1 = *param_1;
    if (*(int *)(iVar1 + 0x1c0) != 0) {
      *(float *)(iVar1 + 0x20) = *(float *)(iVar1 + 0x20) * 0.5;
      *(float *)(iVar1 + 0x24) = *(float *)(iVar1 + 0x24) * 0.5;
      *(float *)(iVar1 + 0x28) = *(float *)(iVar1 + 0x28) * 0.5;
    }
  }
  return;
}


