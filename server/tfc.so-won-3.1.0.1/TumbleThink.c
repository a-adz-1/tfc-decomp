// TumbleThink__8CGrenade  @ 000a7314
void TumbleThink__8CGrenade(int *param_1)

{
  float fVar1;
  int iVar2;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar2 = (**(code **)(param_1[0xf5] + 0x98))(param_1);
  if (iVar2 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
    local_4 = *gpGlobals + 0.1;
    *(float *)(*param_1 + 0x104) = local_4;
    iVar2 = *param_1;
    if (*(float *)(iVar2 + 0x1e4) - 1.0 < *gpGlobals) {
      fVar1 = *(float *)(iVar2 + 0x1e4) - *gpGlobals;
      local_10 = *(float *)(iVar2 + 8) + fVar1 * *(float *)(iVar2 + 0x20);
      local_c = *(float *)(iVar2 + 0xc) + fVar1 * *(float *)(iVar2 + 0x24);
      local_8 = *(float *)(iVar2 + 0x10) + fVar1 * *(float *)(iVar2 + 0x28);
      InsertSound__9CSoundEntiRC6Vectorif(0x20,&local_10,400,0x3dcccccd);
    }
    if (*(float *)(*param_1 + 0x1e4) <= *gpGlobals) {
      param_1[3] = -0x10000;
      param_1[4] = (int)Detonate__8CGrenade;
    }
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x1c0) != 0) {
      *(float *)(iVar2 + 0x20) = *(float *)(iVar2 + 0x20) * 0.5;
      *(float *)(iVar2 + 0x24) = *(float *)(iVar2 + 0x24) * 0.5;
      *(float *)(iVar2 + 0x28) = *(float *)(iVar2 + 0x28) * 0.5;
      *(undefined4 *)(*param_1 + 0x138) = 0x3e4ccccd;
    }
  }
  return;
}


