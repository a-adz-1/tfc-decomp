// ShowBadNode__9CTestHull  @ 000cbe50
void ShowBadNode__9CTestHull(int *param_1)

{
  int iVar1;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  *(undefined4 *)(*param_1 + 0xe8) = 5;
  *(float *)(*param_1 + 0x54) = *(float *)(*param_1 + 0x54) + 4.0;
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  UTIL_ParticleEffect__FRC6VectorT0UlUl(*param_1 + 8,&g_vecZero,0xff,0x19);
  fStack_1c = gpGlobals[10] * 64.0;
  fStack_18 = gpGlobals[0xb] * 64.0;
  fStack_14 = gpGlobals[0xc] * 64.0;
  iVar1 = *param_1;
  fStack_10 = *(float *)(iVar1 + 8) + fStack_1c;
  fStack_c = *(float *)(iVar1 + 0xc) + fStack_18;
  fStack_8 = *(float *)(iVar1 + 0x10) + fStack_14;
  UTIL_ParticleEffect__FRC6VectorT0UlUl(&fStack_10,&g_vecZero,0xff,0x19);
  fStack_10 = gpGlobals[10] * 64.0;
  fStack_c = gpGlobals[0xb] * 64.0;
  fStack_8 = gpGlobals[0xc] * 64.0;
  iVar1 = *param_1;
  fStack_1c = *(float *)(iVar1 + 8) - fStack_10;
  fStack_18 = *(float *)(iVar1 + 0xc) - fStack_c;
  fStack_14 = *(float *)(iVar1 + 0x10) - fStack_8;
  UTIL_ParticleEffect__FRC6VectorT0UlUl(&fStack_1c,&g_vecZero,0xff,0x19);
  fStack_10 = gpGlobals[0x10] * 64.0;
  fStack_c = gpGlobals[0x11] * 64.0;
  fStack_8 = gpGlobals[0x12] * 64.0;
  iVar1 = *param_1;
  fStack_1c = *(float *)(iVar1 + 8) + fStack_10;
  fStack_18 = *(float *)(iVar1 + 0xc) + fStack_c;
  fStack_14 = *(float *)(iVar1 + 0x10) + fStack_8;
  UTIL_ParticleEffect__FRC6VectorT0UlUl(&fStack_1c,&g_vecZero,0xff,0x19);
  fStack_10 = gpGlobals[0x10] * 64.0;
  fStack_c = gpGlobals[0x11] * 64.0;
  fStack_8 = gpGlobals[0x12] * 64.0;
  iVar1 = *param_1;
  fStack_1c = *(float *)(iVar1 + 8) - fStack_10;
  fStack_18 = *(float *)(iVar1 + 0xc) - fStack_c;
  fStack_14 = *(float *)(iVar1 + 0x10) - fStack_8;
  UTIL_ParticleEffect__FRC6VectorT0UlUl(&fStack_1c,&g_vecZero,0xff,0x19);
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  return;
}


