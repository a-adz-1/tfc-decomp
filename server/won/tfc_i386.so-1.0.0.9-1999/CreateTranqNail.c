// CreateTranqNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3  @ 000ffe50
int * CreateTranqNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3
                (undefined4 *param_1,float *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = *param_1;
  local_c = param_1[1];
  local_8 = param_1[2];
  local_1c = *param_2;
  local_18 = param_2[1];
  local_14 = param_2[2];
  piVar2 = (int *)CreateNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3i
                            (&local_10,&local_1c,param_3,param_4,0);
  UTIL_MakeVectors__FRC6Vector(*piVar2 + 0x50);
  iVar1 = *piVar2;
  local_1c = *(float *)(gpGlobals + 0x28) * 1500.0;
  local_18 = *(float *)(gpGlobals + 0x2c) * 1500.0;
  local_14 = *(float *)(gpGlobals + 0x30) * 1500.0;
  *(float *)(iVar1 + 0x20) = local_1c;
  *(float *)(iVar1 + 0x24) = local_18;
  *(float *)(iVar1 + 0x28) = local_14;
  *(byte *)(*piVar2 + 0xf8) = *(byte *)(*piVar2 + 0xf8) | 0x80;
  uVar3 = (*DAT_001755dc)(*(undefined4 *)(*piVar2 + 0x178));
  UTIL_ClientProjectile__FRC6VectorT0sii(*piVar2 + 8,*piVar2 + 0x20,(int)g_sModelIndexNail,uVar3,6);
  piVar2[5] = -0x10000;
  piVar2[6] = (int)TranqTouch__14CTFNailgunNailP11CBaseEntity;
  return piVar2;
}


