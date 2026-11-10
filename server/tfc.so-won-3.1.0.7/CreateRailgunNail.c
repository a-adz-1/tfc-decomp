// CreateRailgunNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3  @ 0010042c
int * CreateRailgunNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3
                (undefined4 *param_1,float *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  
  local_44 = *param_1;
  uStack_40 = param_1[1];
  uStack_3c = param_1[2];
  fStack_50 = *param_2;
  fStack_4c = param_2[1];
  fStack_48 = param_2[2];
  piVar2 = (int *)CreateNail__14CTFNailgunNailiG6VectorT2P11CBaseEntityT4i
                            (0,&local_44,&fStack_50,param_3,param_4,0);
  piVar2[0xfa] = (int)("Drailgun" + (1 - *(int *)(gpGlobals + 0x98)));
  piVar2[5] = -0x10000;
  piVar2[6] = (int)RailgunNailTouch__14CTFNailgunNailP11CBaseEntity;
  UTIL_MakeVectors__FRC6Vector(param_2);
  iVar1 = *piVar2;
  fStack_50 = *(float *)(gpGlobals + 0x28) * 1500.0;
  fStack_4c = *(float *)(gpGlobals + 0x2c) * 1500.0;
  fStack_48 = *(float *)(gpGlobals + 0x30) * 1500.0;
  *(float *)(iVar1 + 0x20) = fStack_50;
  *(float *)(iVar1 + 0x24) = fStack_4c;
  *(float *)(iVar1 + 0x28) = fStack_48;
  iVar1 = *piVar2;
  piVar2[0x1aa] = *(int *)(iVar1 + 0x20);
  piVar2[0x1ab] = *(int *)(iVar1 + 0x24);
  piVar2[0x1ac] = *(int *)(iVar1 + 0x28);
  *(byte *)(iVar1 + 0x118) = *(byte *)(iVar1 + 0x118) | 0x80;
  (*DAT_001c113c)(*(undefined4 *)(*piVar2 + 0x198));
  return piVar2;
}


