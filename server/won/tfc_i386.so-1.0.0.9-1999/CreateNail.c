// CreateNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3i  @ 000ffc60
int * CreateNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3i
                (undefined4 param_1,undefined4 *param_2,int *param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar2 = (int *)GetClassPtr__H1Z14CTFNailgunNail_PX01_PX01(0);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*piVar2,param_1);
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x50) = *param_2;
  *(undefined4 *)(iVar1 + 0x54) = param_2[1];
  *(undefined4 *)(iVar1 + 0x58) = param_2[2];
  *(undefined4 *)(*piVar2 + 0x178) = *(undefined4 *)(*param_3 + 0x1e8);
  (**(code **)(piVar2[0xf2] + 8))(piVar2);
  piVar2[5] = -0x10000;
  piVar2[6] = (int)NailTouch__14CTFNailgunNailP11CBaseEntity;
  *(undefined4 *)(*piVar2 + 0x1c0) = 0x41100000;
  if (param_5 != 0) {
    *(byte *)(*piVar2 + 0xf8) = *(byte *)(*piVar2 + 0xf8) | 0x80;
    uVar3 = (*DAT_001755dc)(*(undefined4 *)(*piVar2 + 0x178));
    UTIL_ClientProjectile__FRC6VectorT0sii
              (*piVar2 + 8,*piVar2 + 0x20,(int)g_sModelIndexNail,uVar3,6);
  }
  return piVar2;
}


