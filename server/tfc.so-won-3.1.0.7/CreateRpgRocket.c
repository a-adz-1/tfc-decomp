// CreateRpgRocket__12CTFRpgRocketG6VectorT1P11CBaseEntityP6CTFRpg  @ 001011d0
int * CreateRpgRocket__12CTFRpgRocketG6VectorT1P11CBaseEntityP6CTFRpg
                (undefined4 *param_1,undefined4 *param_2,int *param_3)

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
  
  piVar2 = (int *)GetClassPtr__H1Z12CTFRpgRocket_PX01_PX01(0);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar2,param_1);
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x50) = *param_2;
  *(undefined4 *)(iVar1 + 0x54) = param_2[1];
  *(undefined4 *)(iVar1 + 0x58) = param_2[2];
  (**(code **)(piVar2[0x111] + 0xc))(piVar2);
  piVar2[5] = -0x10000;
  piVar2[6] = (int)RocketTouch__12CTFRpgRocketP11CBaseEntity;
  *(undefined4 *)(*piVar2 + 0x198) = *(undefined4 *)(*param_3 + 0x208);
  *(byte *)(*piVar2 + 0x118) = *(byte *)(*piVar2 + 0x118) | 0x40;
  (*DAT_001c10d8)(0,0x17,0,0);
  (*DAT_001c10e0)(0x16);
  uVar3 = (*DAT_001c113c)(*(undefined4 *)(*piVar2 + 0x208));
  (*DAT_001c10e8)(uVar3);
  (*DAT_001c10e8)(piVar2[0x1aa]);
  (*DAT_001c10e0)(10);
  (*DAT_001c10e0)(5);
  (*DAT_001c10e0)(0xe0);
  (*DAT_001c10e0)(0xe0);
  (*DAT_001c10e0)(0xff);
  (*DAT_001c10e0)(0x80);
  (*DAT_001c10dc)();
  local_c = *param_1;
  local_8 = param_1[1];
  local_4 = param_1[2];
  local_18 = *param_2;
  local_14 = param_2[1];
  local_10 = param_2[2];
  UTIL_ParametricRocket__FP9entvars_sG6VectorT1P7edict_s
            (*piVar2,&local_c,&local_18,*(undefined4 *)(*param_3 + 0x208));
  return piVar2;
}


// CreateRpgRocket__20CTFIncendiaryCRocketG6VectorT1P11CBaseEntityP14CTFIncendiaryC  @ 00100cac
int * CreateRpgRocket__20CTFIncendiaryCRocketG6VectorT1P11CBaseEntityP14CTFIncendiaryC
                (undefined4 *param_1,undefined4 *param_2,int *param_3)

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
  
  piVar2 = (int *)GetClassPtr__H1Z20CTFIncendiaryCRocket_PX01_PX01(0);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar2,param_1);
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x50) = *param_2;
  *(undefined4 *)(iVar1 + 0x54) = param_2[1];
  *(undefined4 *)(iVar1 + 0x58) = param_2[2];
  (**(code **)(piVar2[0x111] + 0xc))(piVar2);
  piVar2[5] = -0x10000;
  piVar2[6] = (int)RocketTouch__20CTFIncendiaryCRocketP11CBaseEntity;
  *(undefined4 *)(*piVar2 + 0x198) = *(undefined4 *)(*param_3 + 0x208);
  *(byte *)(*piVar2 + 0x118) = *(byte *)(*piVar2 + 0x118) | 0x40;
  (*DAT_001c10d8)(0,0x17,0,0);
  (*DAT_001c10e0)(0x16);
  uVar3 = (*DAT_001c113c)(*(undefined4 *)(*piVar2 + 0x208));
  (*DAT_001c10e8)(uVar3);
  (*DAT_001c10e8)(piVar2[0x1aa]);
  (*DAT_001c10e0)(0x1e);
  (*DAT_001c10e0)(5);
  (*DAT_001c10e0)(0xe0);
  (*DAT_001c10e0)(0x20);
  (*DAT_001c10e0)(0x20);
  (*DAT_001c10e0)(200);
  (*DAT_001c10dc)();
  local_c = *param_1;
  local_8 = param_1[1];
  local_4 = param_1[2];
  local_18 = *param_2;
  local_14 = param_2[1];
  local_10 = param_2[2];
  UTIL_ParametricRocket__FP9entvars_sG6VectorT1P7edict_s
            (*piVar2,&local_c,&local_18,*(undefined4 *)(*param_3 + 0x208));
  return piVar2;
}


