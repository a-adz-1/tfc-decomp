// CreateTFGrenade__10CTFGrenadeG6VectorT1P11CBaseEntityP18CTFGrenadeLauncher  @ 000f3ff4
int * CreateTFGrenade__10CTFGrenadeG6VectorT1P11CBaseEntityP18CTFGrenadeLauncher
                (undefined4 param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  undefined2 uVar2;
  int *piVar3;
  undefined4 uVar4;
  
  piVar3 = (int *)GetClassPtr__H1Z10CTFGrenade_PX01_PX01(0);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar3,param_1);
  iVar1 = *piVar3;
  *(undefined4 *)(iVar1 + 0x50) = *param_2;
  *(undefined4 *)(iVar1 + 0x54) = param_2[1];
  *(undefined4 *)(iVar1 + 0x58) = param_2[2];
  (**(code **)(piVar3[0xf5] + 8))(piVar3);
  piVar3[5] = -0x10000;
  piVar3[6] = (int)GrenadeTouch__10CTFGrenadeP11CBaseEntity;
  *(undefined4 *)(*piVar3 + 0x198) = *(undefined4 *)(*param_3 + 0x208);
  piVar3[0x48] = param_3[0x48];
  *(int *)*piVar3 = (int)"tf_gl_grenade" - *(int *)(gpGlobals + 0x98);
  piVar3[0xde] = (int)"gl_grenade" - *(int *)(gpGlobals + 0x98);
  uVar2 = (*DAT_001a8028)(1,"events/explode/tf_gren.sc");
  *(undefined2 *)(piVar3 + 0x18d) = uVar2;
  (*DAT_001a7ef8)(0,0x17,0,0);
  (*DAT_001a7f00)(0x16);
  uVar4 = (*DAT_001a7f5c)(*(undefined4 *)(*piVar3 + 0x208));
  (*DAT_001a7f08)(uVar4);
  (*DAT_001a7f08)(piVar3[0x18e]);
  (*DAT_001a7f00)(0xf);
  (*DAT_001a7f00)(5);
  (*DAT_001a7f00)(0xe0);
  (*DAT_001a7f00)(0xe0);
  (*DAT_001a7f00)(0xff);
  (*DAT_001a7f00)(0x50);
  (*DAT_001a7efc)();
  return piVar3;
}


