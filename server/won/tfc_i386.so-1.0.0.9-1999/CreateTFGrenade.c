// CreateTFGrenade__10CTFGrenadeG6VectorT1P11CBaseEntityP18CTFGrenadeLauncher  @ 000faec0
int * CreateTFGrenade__10CTFGrenadeG6VectorT1P11CBaseEntityP18CTFGrenadeLauncher
                (undefined4 param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar2 = (int *)GetClassPtr__H1Z10CTFGrenade_PX01_PX01(0);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*piVar2,param_1);
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x50) = *param_2;
  *(undefined4 *)(iVar1 + 0x54) = param_2[1];
  *(undefined4 *)(iVar1 + 0x58) = param_2[2];
  (**(code **)(piVar2[0xf2] + 8))(piVar2);
  piVar2[5] = -0x10000;
  piVar2[6] = (int)GrenadeTouch__10CTFGrenadeP11CBaseEntity;
  *(undefined4 *)(*piVar2 + 0x178) = *(undefined4 *)(*param_3 + 0x1e8);
  piVar2[0x48] = param_3[0x48];
  iVar1 = gpGlobals;
  *(int *)*piVar2 = (int)"tf_gl_grenade" - *(int *)(gpGlobals + 0x98);
  piVar2[0xdb] = (int)"gl_grenade" - *(int *)(iVar1 + 0x98);
  (*DAT_00175578)(0,0x17,0,0);
  (*DAT_00175580)(0x16);
  uVar3 = (*DAT_001755dc)(*(undefined4 *)(*piVar2 + 0x1e8));
  (*DAT_00175588)(uVar3);
  (*DAT_00175588)(piVar2[0x189]);
  (*DAT_00175580)(0xf);
  (*DAT_00175580)(5);
  (*DAT_00175580)(0xe0);
  (*DAT_00175580)(0xe0);
  (*DAT_00175580)(0xff);
  (*DAT_00175580)(0x50);
  (*DAT_0017557c)();
  return piVar2;
}


