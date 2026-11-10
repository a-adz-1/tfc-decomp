// CreateSuperNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3  @ 000ffd20
int * CreateSuperNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3
                (undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = *param_1;
  local_c = param_1[1];
  local_8 = param_1[2];
  local_1c = *param_2;
  local_18 = param_2[1];
  local_14 = param_2[2];
  piVar1 = (int *)CreateNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3i
                            (&local_10,&local_1c,param_3,param_4,1);
  piVar1[0xdb] = (int)"supernails" - *(int *)(gpGlobals + 0x98);
  *(undefined4 *)(*piVar1 + 0x1c0) = 0x41500000;
  return piVar1;
}


