// CreateNail__14CTFNailgunNailiG6VectorT2P11CBaseEntityT4i  @ 00104b9c
int * CreateNail__14CTFNailgunNailiG6VectorT2P11CBaseEntityT4i
                (int param_1,undefined4 param_2,undefined4 *param_3,int *param_4,undefined4 param_5,
                int param_6)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar2 = (int *)GetClassPtr__H1Z14CTFNailgunNail_PX01_PX01(0);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar2,param_2);
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x50) = *param_3;
  *(undefined4 *)(iVar1 + 0x54) = param_3[1];
  *(undefined4 *)(iVar1 + 0x58) = param_3[2];
  *(undefined4 *)(*piVar2 + 0x198) = *(undefined4 *)(*param_4 + 0x208);
  (**(code **)(piVar2[0x115] + 0xc))(piVar2);
  piVar2[5] = -0x10000;
  piVar2[6] = (int)NailTouch__14CTFNailgunNailP11CBaseEntity;
  *(undefined4 *)(*piVar2 + 0x1e0) = 0x41100000;
  if (param_6 != 0) {
    *(byte *)(*piVar2 + 0x118) = *(byte *)(*piVar2 + 0x118) | 0x80;
    uVar3 = (*DAT_0019f7bc)(*(undefined4 *)(*piVar2 + 0x198));
    if (param_1 != 0) {
      UTIL_ClientProjectile__FRC6VectorT0sii
                (*piVar2 + 8,*piVar2 + 0x20,(int)g_sModelIndexNail,uVar3,6);
    }
  }
  return piVar2;
}


