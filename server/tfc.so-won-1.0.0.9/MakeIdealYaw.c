// MakeIdealYaw__12CBaseMonsterG6Vector  @ 000c51c0
void MakeIdealYaw__12CBaseMonsterG6Vector(int *param_1,float *param_2)

{
  int iVar1;
  longdouble lVar2;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if (param_1[0x165] == 0xb) {
    local_10 = -param_2[1];
  }
  else {
    if (param_1[0x165] != 0xc) {
      iVar1 = *param_1;
      local_1c = *param_2 - *(float *)(iVar1 + 8);
      local_18 = param_2[1] - *(float *)(iVar1 + 0xc);
      local_8 = param_2[2];
      goto LAB_000c5223;
    }
    local_10 = param_2[1];
  }
  local_c = *param_2;
  iVar1 = *param_1;
  local_1c = local_10 - *(float *)(iVar1 + 8);
  local_18 = local_c - *(float *)(iVar1 + 0xc);
LAB_000c5223:
  local_14 = local_8 - *(float *)(iVar1 + 0x10);
  lVar2 = (longdouble)UTIL_VecToYaw__FRC6Vector(&local_1c);
  *(float *)(*param_1 + 0x8c) = (float)lVar2;
  return;
}


