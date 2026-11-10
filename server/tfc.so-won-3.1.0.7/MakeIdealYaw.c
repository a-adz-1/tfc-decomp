// MakeIdealYaw__12CBaseMonsterG6Vector  @ 000bea50
void MakeIdealYaw__12CBaseMonsterG6Vector(int *param_1,float *param_2)

{
  int iVar1;
  longdouble lVar2;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (param_1[0x184] == 0xb) {
    local_c = -param_2[1];
  }
  else {
    if (param_1[0x184] != 0xc) {
      iVar1 = *param_1;
      local_18 = *param_2 - *(float *)(iVar1 + 8);
      local_14 = param_2[1] - *(float *)(iVar1 + 0xc);
      local_4 = param_2[2];
      goto LAB_000beabf;
    }
    local_c = param_2[1];
  }
  local_8 = *param_2;
  iVar1 = *param_1;
  local_18 = local_c - *(float *)(iVar1 + 8);
  local_14 = local_8 - *(float *)(iVar1 + 0xc);
LAB_000beabf:
  local_10 = local_4 - *(float *)(iVar1 + 0x10);
  lVar2 = (longdouble)UTIL_VecToYaw__FRC6Vector(&local_18);
  *(float *)(*param_1 + 0xac) = (float)lVar2;
  return;
}


