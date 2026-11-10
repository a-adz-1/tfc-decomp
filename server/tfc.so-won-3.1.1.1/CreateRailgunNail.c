// CreateRailgunNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3  @ 00102c78
int * CreateRailgunNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3
                (undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int *piVar7;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  
  local_48 = *param_1;
  local_44 = param_1[1];
  local_40 = param_1[2];
  uVar1 = *param_2;
  uVar2 = param_2[1];
  uVar3 = param_2[2];
  piVar7 = (int *)GetClassPtr__H1Z14CTFNailgunNail_PX01_PX01(0);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar7,&local_48);
  iVar6 = *piVar7;
  *(undefined4 *)(iVar6 + 0x50) = uVar1;
  *(undefined4 *)(iVar6 + 0x54) = uVar2;
  *(undefined4 *)(iVar6 + 0x58) = uVar3;
  *(undefined4 *)(*piVar7 + 0x198) = *(undefined4 *)(*param_3 + 0x208);
  (**(code **)(piVar7[0x115] + 0xc))(piVar7);
  piVar7[5] = -0x10000;
  piVar7[6] = (int)NailTouch__14CTFNailgunNailP11CBaseEntity;
  *(undefined4 *)(*piVar7 + 0x1e0) = 0x41100000;
  piVar7[0xfe] = (int)("Drailgun" + (1 - *(int *)(gpGlobals + 0x98)));
  piVar7[5] = -0x10000;
  piVar7[6] = (int)RailgunNailTouch__14CTFNailgunNailP11CBaseEntity;
  UTIL_MakeVectors__FRC6Vector(param_2);
  iVar6 = *piVar7;
  fVar4 = *(float *)(gpGlobals + 0x2c);
  fVar5 = *(float *)(gpGlobals + 0x30);
  *(float *)(iVar6 + 0x20) = *(float *)(gpGlobals + 0x28) * 1500.0;
  *(float *)(iVar6 + 0x24) = fVar4 * 1500.0;
  *(float *)(iVar6 + 0x28) = fVar5 * 1500.0;
  iVar6 = *piVar7;
  piVar7[0x1ae] = *(int *)(iVar6 + 0x20);
  piVar7[0x1af] = *(int *)(iVar6 + 0x24);
  piVar7[0x1b0] = *(int *)(iVar6 + 0x28);
  *(byte *)(iVar6 + 0x118) = *(byte *)(iVar6 + 0x118) | 0x80;
  (*DAT_0019f7bc)(*(undefined4 *)(*piVar7 + 0x198));
  return piVar7;
}


