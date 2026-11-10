// BodyTarget__10CGunTargetRC6Vector  @ 000d1894
undefined4 * BodyTarget__10CGunTargetRC6Vector(undefined4 *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  *param_1 = *(undefined4 *)(iVar1 + 8);
  param_1[1] = *(undefined4 *)(iVar1 + 0xc);
  param_1[2] = *(undefined4 *)(iVar1 + 0x10);
  return param_1;
}


// BodyTarget__11CBaseEntityRC6Vector  @ 00112874
undefined4 BodyTarget__11CBaseEntityRC6Vector(undefined4 param_1,int param_2)

{
  (**(code **)(*(int *)(param_2 + 0x454) + 0xcc))(param_1,param_2);
  return param_1;
}


// BodyTarget__11CBasePlayerRC6Vector  @ 000e6194
float * BodyTarget__11CBasePlayerRC6Vector(float *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  longdouble lVar4;
  float local_10;
  float local_c;
  float local_8;
  
  (**(code **)(param_2[0x115] + 0xcc))(&local_10,param_2);
  lVar4 = (longdouble)(*DAT_0019f80c)(0x3f000000,0x3f8ccccd);
  iVar3 = *param_2;
  fVar1 = *(float *)(iVar3 + 0x178);
  fVar2 = *(float *)(iVar3 + 0x17c);
  *param_1 = (float)((longdouble)*(float *)(iVar3 + 0x174) * lVar4 + (longdouble)local_10);
  param_1[1] = (float)((longdouble)fVar1 * lVar4 + (longdouble)local_c);
  param_1[2] = (float)(lVar4 * (longdouble)fVar2 + (longdouble)local_8);
  return param_1;
}


// BodyTarget__12CBaseMonsterRC6Vector  @ 000c2fa4
float * BodyTarget__12CBaseMonsterRC6Vector(float *param_1,int param_2)

{
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float local_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  (**(code **)(*(int *)(param_2 + 0x454) + 0xcc))(&local_1c,param_2);
  fStack_10 = local_1c * 0.75;
  fStack_c = fStack_18 * 0.75;
  fStack_8 = fStack_14 * 0.75;
  (**(code **)(*(int *)(param_2 + 0x454) + 0xd0))(&fStack_34,param_2);
  *param_1 = fStack_34 * 0.25 + fStack_10;
  param_1[1] = fStack_30 * 0.25 + fStack_c;
  param_1[2] = fStack_2c * 0.25 + fStack_8;
  return param_1;
}


