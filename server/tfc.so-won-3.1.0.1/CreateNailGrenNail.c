// CreateNailGrenNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3  @ 000f2ab0
int * CreateNailGrenNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3
                (undefined4 *param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *(int *)(*param_3 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001a7f54)(0);
    if (iVar1 == 0) {
      uVar3 = 0;
      goto LAB_000f2afa;
    }
  }
  uVar3 = *(undefined4 *)(iVar1 + 0x7c);
LAB_000f2afa:
  local_c = *param_1;
  local_8 = param_1[1];
  local_4 = param_1[2];
  local_18 = *param_2;
  local_14 = param_2[1];
  local_10 = param_2[2];
  piVar2 = (int *)CreateNail__14CTFNailgunNailiG6VectorT2P11CBaseEntityT4i
                            (0,&local_c,&local_18,uVar3,param_4,1);
  __as__7EHANDLEP11CBaseEntity(piVar2 + 0x51,uVar3);
  *(undefined4 *)(*piVar2 + 0x198) = *(undefined4 *)(*param_3 + 0x208);
  *(int *)*piVar2 = (int)"tf_weapon_nailgrenadenail" - *(int *)(gpGlobals + 0x98);
  piVar2[0xde] = (int)"nailgrenade" - *(int *)(gpGlobals + 0x98);
  *(undefined4 *)(*piVar2 + 0x1e0) = 0x41900000;
  piVar2[0x48] = param_3[0x48];
  return piVar2;
}


