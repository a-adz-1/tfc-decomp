// ShowBadNode__9CTestHull  @ 000bb7a8
void ShowBadNode__9CTestHull(int *param_1)

{
  int iVar1;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  *(undefined4 *)(*param_1 + 0x108) = 5;
  *(float *)(*param_1 + 0x54) = *(float *)(*param_1 + 0x54) + 4.0;
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  UTIL_ParticleEffect__FRC6VectorT0UlUl(*param_1 + 8,&g_vecZero,0xff,0x19);
  local_18 = gpGlobals[10] * 64.0;
  local_14 = gpGlobals[0xb] * 64.0;
  local_10 = gpGlobals[0xc] * 64.0;
  iVar1 = *param_1;
  local_c = *(float *)(iVar1 + 8) + local_18;
  local_8 = *(float *)(iVar1 + 0xc) + local_14;
  local_4 = *(float *)(iVar1 + 0x10) + local_10;
  UTIL_ParticleEffect__FRC6VectorT0UlUl(&local_c,&g_vecZero,0xff,0x19);
  local_c = gpGlobals[10] * 64.0;
  local_8 = gpGlobals[0xb] * 64.0;
  local_4 = gpGlobals[0xc] * 64.0;
  iVar1 = *param_1;
  local_18 = *(float *)(iVar1 + 8) - local_c;
  local_14 = *(float *)(iVar1 + 0xc) - local_8;
  local_10 = *(float *)(iVar1 + 0x10) - local_4;
  UTIL_ParticleEffect__FRC6VectorT0UlUl(&local_18,&g_vecZero,0xff,0x19);
  local_c = gpGlobals[0x10] * 64.0;
  local_8 = gpGlobals[0x11] * 64.0;
  local_4 = gpGlobals[0x12] * 64.0;
  iVar1 = *param_1;
  local_18 = *(float *)(iVar1 + 8) + local_c;
  local_14 = *(float *)(iVar1 + 0xc) + local_8;
  local_10 = *(float *)(iVar1 + 0x10) + local_4;
  UTIL_ParticleEffect__FRC6VectorT0UlUl(&local_18,&g_vecZero,0xff,0x19);
  local_c = gpGlobals[0x10] * 64.0;
  local_8 = gpGlobals[0x11] * 64.0;
  local_4 = gpGlobals[0x12] * 64.0;
  iVar1 = *param_1;
  local_18 = *(float *)(iVar1 + 8) - local_c;
  local_14 = *(float *)(iVar1 + 0xc) - local_8;
  local_10 = *(float *)(iVar1 + 0x10) - local_4;
  UTIL_ParticleEffect__FRC6VectorT0UlUl(&local_18,&g_vecZero,0xff,0x19);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


