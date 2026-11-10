// BodyTarget__10CGunTargetRC6Vector  @ 000d5c20
undefined4 * BodyTarget__10CGunTargetRC6Vector(undefined4 *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  *param_1 = *(undefined4 *)(iVar1 + 8);
  param_1[1] = *(undefined4 *)(iVar1 + 0xc);
  param_1[2] = *(undefined4 *)(iVar1 + 0x10);
  return param_1;
}


// BodyTarget__11CBaseEntityRC6Vector  @ 0010de10
undefined4 BodyTarget__11CBaseEntityRC6Vector(undefined4 param_1,int param_2)

{
  (**(code **)(*(int *)(param_2 + 0x3c8) + 0xc4))(param_1,param_2);
  return param_1;
}


// BodyTarget__11CBasePlayerRC6Vector  @ 000e4540
float * BodyTarget__11CBasePlayerRC6Vector(float *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  longdouble lVar4;
  float local_10;
  float local_c;
  float local_8;
  
  (**(code **)(param_2[0xf2] + 0xc4))(&local_10,param_2);
  lVar4 = (longdouble)(*DAT_0017562c)(0x3f000000,0x3f8ccccd);
  iVar3 = *param_2;
  fVar1 = *(float *)(iVar3 + 0x158);
  fVar2 = *(float *)(iVar3 + 0x15c);
  *param_1 = (float)((longdouble)local_10 + lVar4 * (longdouble)*(float *)(iVar3 + 0x154));
  param_1[1] = (float)((longdouble)local_c + lVar4 * (longdouble)fVar1);
  param_1[2] = local_8 + (float)(lVar4 * (longdouble)fVar2);
  return param_1;
}


// BodyTarget__12CBaseMonsterRC6Vector  @ 000c8610
float * BodyTarget__12CBaseMonsterRC6Vector(float *param_1,int param_2)

{
  float local_34;
  float local_30;
  float local_2c;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  (**(code **)(*(int *)(param_2 + 0x3c8) + 0xc4))(&local_1c,param_2);
  local_10 = local_1c * 0.75;
  local_c = local_18 * 0.75;
  local_8 = local_14 * 0.75;
  (**(code **)(*(int *)(param_2 + 0x3c8) + 200))(&local_34,param_2);
  *param_1 = local_10 + local_34 * 0.25;
  param_1[1] = local_c + local_30 * 0.25;
  param_1[2] = local_8 + local_2c * 0.25;
  return param_1;
}


