// Detonate__8CGrenade  @ 000b1b8c
void Detonate__8CGrenade(int *param_1)

{
  int iVar1;
  undefined4 local_5c;
  undefined4 local_58;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  undefined1 local_38 [56];
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001c1134)(0);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_000b1bce;
    }
  }
  iVar1 = *(int *)(iVar1 + 0x7c);
LAB_000b1bce:
  if (((iVar1 == 0) || (*(int *)(iVar1 + 0x120) == param_1[0x48])) || (param_1[0x48] == 0)) {
    iVar1 = *param_1;
    local_5c = *(undefined4 *)(iVar1 + 8);
    local_58 = *(undefined4 *)(iVar1 + 0xc);
    local_3c = *(float *)(iVar1 + 0x10) + 8.0;
    local_48 = 0xc2000000;
    local_50 = 0;
    local_4c = 0;
    local_54 = local_3c + -32.0;
    local_44 = local_5c;
    local_40 = local_58;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_44,&local_5c,1,*(undefined4 *)(iVar1 + 0x208),local_38);
    (**(code **)(param_1[0x111] + 0x220))(param_1,local_38,0x40);
  }
  else {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


