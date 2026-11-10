// GetAutoaimVector__11CBasePlayerf  @ 000e517c
undefined4 * GetAutoaimVector__11CBasePlayerf(undefined4 *param_1,int *param_2)

{
  int iVar1;
  float local_10;
  float local_c;
  float local_8;
  
  iVar1 = *param_2;
  local_10 = *(float *)(iVar1 + 0x74) + *(float *)(iVar1 + 0x68);
  local_c = *(float *)(iVar1 + 0x78) + *(float *)(iVar1 + 0x6c);
  local_8 = *(float *)(iVar1 + 0x7c) + *(float *)(iVar1 + 0x70);
  UTIL_MakeVectors__FRC6Vector(&local_10);
  iVar1 = gpGlobals;
  *param_1 = *(undefined4 *)(gpGlobals + 0x28);
  param_1[1] = *(undefined4 *)(iVar1 + 0x2c);
  param_1[2] = *(undefined4 *)(iVar1 + 0x30);
  return param_1;
}


