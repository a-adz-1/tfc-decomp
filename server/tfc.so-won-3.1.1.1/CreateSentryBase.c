// CreateSentryBase__16CTFSentrygunBaseG6VectorT1P11CBaseEntity  @ 000eef84
int * CreateSentryBase__16CTFSentrygunBaseG6VectorT1P11CBaseEntity
                (undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  longdouble lVar3;
  
  piVar2 = (int *)GetClassPtr__H1Z16CTFSentrygunBase_PX01_PX01(0);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar2,param_1);
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x50) = 0;
  *(undefined4 *)(iVar1 + 0x54) = 0;
  *(undefined4 *)(iVar1 + 0x58) = 0;
  lVar3 = (longdouble)UTIL_AngleMod__Ff(*(float *)(*param_3 + 0x54) + 180.0);
  *(float *)(*piVar2 + 0x54) = (float)lVar3;
  (**(code **)(piVar2[0x115] + 0xc))(piVar2);
  __as__7EHANDLEP11CBaseEntity(piVar2 + 0x51,param_3);
  piVar2[0x48] = param_3[0x48];
  return piVar2;
}


