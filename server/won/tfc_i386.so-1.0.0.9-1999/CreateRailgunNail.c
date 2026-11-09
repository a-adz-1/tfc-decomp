// CreateRailgunNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3  @ 000fff40
int * CreateRailgunNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3
                (float *param_1,float *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 auStack_3c [20];
  float fStack_28;
  float fStack_24;
  float fStack_20;
  
  local_48 = *param_1;
  local_44 = param_1[1];
  local_40 = param_1[2];
  local_54 = *param_2;
  local_50 = param_2[1];
  local_4c = param_2[2];
  piVar2 = (int *)CreateNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3i
                            (&local_48,&local_54,param_3,param_4,0);
  piVar2[0xdb] = (int)("Drailgun" + (1 - *(int *)(gpGlobals + 0x98)));
  piVar2[5] = -0x10000;
  piVar2[6] = (int)RailgunNailTouch__14CTFNailgunNailP11CBaseEntity;
  UTIL_MakeVectors__FRC6Vector(param_2);
  iVar1 = *piVar2;
  local_54 = *(float *)(gpGlobals + 0x28) * 1500.0;
  local_50 = *(float *)(gpGlobals + 0x2c) * 1500.0;
  local_4c = *(float *)(gpGlobals + 0x30) * 1500.0;
  *(float *)(iVar1 + 0x20) = local_54;
  *(float *)(iVar1 + 0x24) = local_50;
  *(float *)(iVar1 + 0x28) = local_4c;
  iVar1 = *piVar2;
  piVar2[0x189] = *(int *)(iVar1 + 0x20);
  piVar2[0x18a] = *(int *)(iVar1 + 0x24);
  piVar2[0x18b] = *(int *)(iVar1 + 0x28);
  *(byte *)(iVar1 + 0xf8) = *(byte *)(iVar1 + 0xf8) | 0x80;
  uVar3 = (*DAT_001755dc)(*(undefined4 *)(*piVar2 + 0x178));
  local_48 = *(float *)(gpGlobals + 0x28) * 4096.0;
  local_44 = *(float *)(gpGlobals + 0x2c) * 4096.0;
  local_40 = *(float *)(gpGlobals + 0x30) * 4096.0;
  iVar1 = *piVar2;
  local_54 = *(float *)(iVar1 + 8) + local_48;
  local_50 = *(float *)(iVar1 + 0xc) + local_44;
  local_4c = *(float *)(iVar1 + 0x10) + local_40;
  uVar3 = (*DAT_001755d4)(uVar3,auStack_3c);
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (*piVar2 + 8,&local_54,1,uVar3);
  iVar1 = *piVar2;
  local_54 = *(float *)(iVar1 + 8) - fStack_28;
  local_50 = *(float *)(iVar1 + 0xc) - fStack_24;
  local_4c = *(float *)(iVar1 + 0x10) - fStack_20;
  local_48 = SQRT(local_4c * local_4c + local_50 * local_50 + local_54 * local_54);
  UTIL_UserTracer__FRC6VectorT0fif(*piVar2 + 8,*piVar2 + 0x20,local_48 / 1500.0,2,0x3f800000);
  return piVar2;
}


