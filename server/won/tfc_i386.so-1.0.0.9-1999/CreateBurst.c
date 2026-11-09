// CreateBurst__20CTFFlamethrowerBurstG6VectorT1P11CBaseEntityP15CTFFlamethrower  @ 000fa4b0
int * CreateBurst__20CTFFlamethrowerBurstG6VectorT1P11CBaseEntityP15CTFFlamethrower
                (undefined4 param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)GetClassPtr__H1Z20CTFFlamethrowerBurst_PX01_PX01(0);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*piVar2,param_1);
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x50) = *param_2;
  *(undefined4 *)(iVar1 + 0x54) = param_2[1];
  *(undefined4 *)(iVar1 + 0x58) = param_2[2];
  *(undefined4 *)(*piVar2 + 0x178) = *(undefined4 *)(*param_3 + 0x1e8);
  (**(code **)(piVar2[0xf2] + 8))(piVar2);
  piVar2[5] = -0x10000;
  piVar2[6] = (int)BurstTouch__20CTFFlamethrowerBurstP11CBaseEntity;
  return piVar2;
}


