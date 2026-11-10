// CreateSuperNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3  @ 000f2a1c
int * CreateSuperNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3
                (undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = *param_1;
  local_8 = param_1[1];
  local_4 = param_1[2];
  local_18 = *param_2;
  local_14 = param_2[1];
  local_10 = param_2[2];
  piVar1 = (int *)CreateNail__14CTFNailgunNailiG6VectorT2P11CBaseEntityT4i
                            (0,&local_c,&local_18,param_3,param_4,1);
  piVar1[0xde] = (int)"supernails" - *(int *)(gpGlobals + 0x98);
  *(undefined4 *)(*piVar1 + 0x1e0) = 0x41500000;
  return piVar1;
}


