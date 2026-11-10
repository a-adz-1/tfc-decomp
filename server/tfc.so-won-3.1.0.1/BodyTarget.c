// BodyTarget__10CGunTargetRC6Vector  @ 000c7514
undefined4 * BodyTarget__10CGunTargetRC6Vector(undefined4 *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  *param_1 = *(undefined4 *)(iVar1 + 8);
  param_1[1] = *(undefined4 *)(iVar1 + 0xc);
  param_1[2] = *(undefined4 *)(iVar1 + 0x10);
  return param_1;
}


// BodyTarget__11CBaseEntityRC6Vector  @ 001000c4
undefined4 BodyTarget__11CBaseEntityRC6Vector(undefined4 param_1,int param_2)

{
  (**(code **)(*(int *)(param_2 + 0x3d4) + 0xc4))(param_1,param_2);
  return param_1;
}


// BodyTarget__11CBasePlayerRC6Vector  @ 000d8d68
float * BodyTarget__11CBasePlayerRC6Vector(float *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  longdouble lVar4;
  float local_10;
  float local_c;
  float local_8;
  
  (**(code **)(param_2[0xf5] + 0xc4))(&local_c,param_2);
  lVar4 = (longdouble)(*DAT_001a7fac)(0x3f000000,0x3f8ccccd);
  iVar3 = *param_2;
  fVar1 = *(float *)(iVar3 + 0x178);
  fVar2 = *(float *)(iVar3 + 0x17c);
  *param_1 = (float)((longdouble)local_10 + lVar4 * (longdouble)*(float *)(iVar3 + 0x174));
  param_1[1] = (float)((longdouble)local_c + lVar4 * (longdouble)fVar1);
  param_1[2] = local_8 + (float)(lVar4 * (longdouble)fVar2);
  return param_1;
}


// BodyTarget__12CBaseMonsterRC6Vector  @ 000b7464
float * BodyTarget__12CBaseMonsterRC6Vector(float *param_1,int param_2)

{
  float unaff_EDI;
  float local_30;
  float local_2c;
  float local_1c;
  undefined1 local_18 [4];
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  (**(code **)(*(int *)(param_2 + 0x3d4) + 0xc4))(local_18,param_2);
  local_c = local_14 * 0.75;
  local_8 = local_10 * 0.75;
  local_10 = local_1c * 0.75;
  (**(code **)(*(int *)(param_2 + 0x3d4) + 200))(&stack0xffffffcc,param_2);
  *param_1 = local_14 + unaff_EDI * 0.25;
  param_1[1] = local_10 + local_30 * 0.25;
  param_1[2] = local_c + local_2c * 0.25;
  return param_1;
}


