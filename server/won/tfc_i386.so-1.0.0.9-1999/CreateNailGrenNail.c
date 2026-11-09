// CreateNailGrenNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3  @ 000ffda0
int * CreateNailGrenNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3
                (undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
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
  piVar2 = (int *)CreateNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3i
                            (&local_10,&local_1c,param_3,param_4,1);
  iVar1 = gpGlobals;
  *(int *)*piVar2 = (int)"tf_weapon_nailgrenadenail" - *(int *)(gpGlobals + 0x98);
  piVar2[0xdb] = (int)"nailgrenade" - *(int *)(iVar1 + 0x98);
  *(undefined4 *)(*piVar2 + 0x1c0) = 0x41900000;
  piVar2[0x48] = *(int *)(param_3 + 0x120);
  __as__7EHANDLEP11CBaseEntity(piVar2 + 0x51,param_3);
  *(undefined4 *)(*piVar2 + 0x178) = 0;
  return piVar2;
}


