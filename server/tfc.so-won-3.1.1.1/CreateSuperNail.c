// CreateSuperNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3  @ 001028b8
int * CreateSuperNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3
                (undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_10 = *param_1;
  uStack_c = param_1[1];
  uStack_8 = param_1[2];
  uVar1 = *param_2;
  uVar2 = param_2[1];
  uVar3 = param_2[2];
  piVar5 = (int *)GetClassPtr__H1Z14CTFNailgunNail_PX01_PX01(0);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar5,&uStack_10);
  iVar4 = *piVar5;
  *(undefined4 *)(iVar4 + 0x50) = uVar1;
  *(undefined4 *)(iVar4 + 0x54) = uVar2;
  *(undefined4 *)(iVar4 + 0x58) = uVar3;
  *(undefined4 *)(*piVar5 + 0x198) = *(undefined4 *)(*param_3 + 0x208);
  (**(code **)(piVar5[0x115] + 0xc))(piVar5);
  piVar5[5] = -0x10000;
  piVar5[6] = (int)NailTouch__14CTFNailgunNailP11CBaseEntity;
  *(undefined4 *)(*piVar5 + 0x1e0) = 0x41100000;
  *(byte *)(*piVar5 + 0x118) = *(byte *)(*piVar5 + 0x118) | 0x80;
  (*DAT_0019f7bc)(*(undefined4 *)(*piVar5 + 0x198));
  piVar5[0xfe] = (int)("Fsupernails" + (1 - *(int *)(gpGlobals + 0x98)));
  *(undefined4 *)(*piVar5 + 0x1e0) = 0x41500000;
  return piVar5;
}


