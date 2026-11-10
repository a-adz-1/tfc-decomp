// Detonate__8CGrenade  @ 000b1004
void Detonate__8CGrenade(int *param_1)

{
  int iVar1;
  undefined4 local_60;
  undefined4 local_5c;
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  float local_40;
  undefined1 local_3c [56];
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7b4)(0);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_000b1046;
    }
  }
  iVar1 = *(int *)(iVar1 + 0x7c);
LAB_000b1046:
  if (((iVar1 == 0) || (*(int *)(iVar1 + 0x120) == param_1[0x48])) || (param_1[0x48] == 0)) {
    iVar1 = *param_1;
    local_40 = *(float *)(iVar1 + 0x10) + 8.0;
    local_60 = *(undefined4 *)(iVar1 + 8);
    local_5c = *(undefined4 *)(iVar1 + 0xc);
    local_4c = 0xc2000000;
    local_58 = local_40 + -32.0;
    local_54 = 0;
    local_50 = 0;
    local_48 = local_60;
    local_44 = local_5c;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_48,&local_60,1,*(undefined4 *)(iVar1 + 0x208),local_3c);
    (**(code **)(param_1[0x115] + 0x220))(param_1,local_3c,0x40);
  }
  else {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


