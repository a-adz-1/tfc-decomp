// CreateRpgRocket__12CTFRpgRocketG6VectorT1P11CBaseEntityP6CTFRpg  @ 001012c0
int * CreateRpgRocket__12CTFRpgRocketG6VectorT1P11CBaseEntityP6CTFRpg
                (undefined4 param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar2 = (int *)GetClassPtr__H1Z12CTFRpgRocket_PX01_PX01(0);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*piVar2,param_1);
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x50) = *param_2;
  *(undefined4 *)(iVar1 + 0x54) = param_2[1];
  *(undefined4 *)(iVar1 + 0x58) = param_2[2];
  (**(code **)(piVar2[0xf2] + 8))(piVar2);
  piVar2[5] = -0x10000;
  piVar2[6] = (int)RocketTouch__12CTFRpgRocketP11CBaseEntity;
  *(undefined4 *)(*piVar2 + 0x178) = *(undefined4 *)(*param_3 + 0x1e8);
  *(byte *)(*piVar2 + 0xf8) = *(byte *)(*piVar2 + 0xf8) | 0x40;
  (*DAT_00175578)(0,0x17,0,0);
  (*DAT_00175580)(0x16);
  uVar3 = (*DAT_001755dc)(*(undefined4 *)(*piVar2 + 0x1e8));
  (*DAT_00175588)(uVar3);
  (*DAT_00175588)(piVar2[0x189]);
  (*DAT_00175580)(10);
  (*DAT_00175580)(5);
  (*DAT_00175580)(0xe0);
  (*DAT_00175580)(0xe0);
  (*DAT_00175580)(0xff);
  (*DAT_00175580)(0x80);
  (*DAT_0017557c)();
  return piVar2;
}


// CreateRpgRocket__20CTFIncendiaryCRocketG6VectorT1P11CBaseEntityP14CTFIncendiaryC  @ 000ff200
int * CreateRpgRocket__20CTFIncendiaryCRocketG6VectorT1P11CBaseEntityP14CTFIncendiaryC
                (undefined4 param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar2 = (int *)GetClassPtr__H1Z20CTFIncendiaryCRocket_PX01_PX01(0);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*piVar2,param_1);
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x50) = *param_2;
  *(undefined4 *)(iVar1 + 0x54) = param_2[1];
  *(undefined4 *)(iVar1 + 0x58) = param_2[2];
  (**(code **)(piVar2[0xf2] + 8))(piVar2);
  piVar2[5] = -0x10000;
  piVar2[6] = (int)RocketTouch__20CTFIncendiaryCRocketP11CBaseEntity;
  *(undefined4 *)(*piVar2 + 0x178) = *(undefined4 *)(*param_3 + 0x1e8);
  *(byte *)(*piVar2 + 0xf8) = *(byte *)(*piVar2 + 0xf8) | 0x40;
  (*DAT_00175578)(0,0x17,0,0);
  (*DAT_00175580)(0x16);
  uVar3 = (*DAT_001755dc)(*(undefined4 *)(*piVar2 + 0x1e8));
  (*DAT_00175588)(uVar3);
  (*DAT_00175588)(piVar2[0x189]);
  (*DAT_00175580)(0x1e);
  (*DAT_00175580)(5);
  (*DAT_00175580)(0xe0);
  (*DAT_00175580)(0x20);
  (*DAT_00175580)(0x20);
  (*DAT_00175580)(200);
  (*DAT_0017557c)();
  return piVar2;
}


