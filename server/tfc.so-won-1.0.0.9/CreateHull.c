// CreateHull__8CXenHullP11CBaseEntityRC6VectorN22  @ 0011ee50
int * CreateHull__8CXenHullP11CBaseEntityRC6VectorN22
                (int *param_1,undefined4 param_2,undefined4 param_3,float *param_4)

{
  int iVar1;
  int *piVar2;
  float local_10;
  float local_c;
  float local_8;
  
  piVar2 = (int *)GetClassPtr__H1Z8CXenHull_PX01_PX01(0);
  iVar1 = *param_1;
  local_10 = *(float *)(iVar1 + 8) + *param_4;
  local_c = *(float *)(iVar1 + 0xc) + param_4[1];
  local_8 = *(float *)(iVar1 + 0x10) + param_4[2];
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*piVar2,&local_10);
  (*DAT_001754c8)(*(undefined4 *)(*piVar2 + 0x1e8),
                  *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*piVar2 + 0xec) = 2;
  *(char **)*piVar2 = "?xen_hull" + (1 - *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*piVar2 + 0xe8) = 0;
  *(undefined4 *)(*piVar2 + 0x178) = *(undefined4 *)(*param_1 + 0x1e8);
  UTIL_SetSize__FP9entvars_tRC6VectorT1(*piVar2,param_2,param_3);
  *(undefined4 *)(*piVar2 + 300) = 0;
  *(undefined4 *)(*piVar2 + 0x128) = 2;
  return piVar2;
}


