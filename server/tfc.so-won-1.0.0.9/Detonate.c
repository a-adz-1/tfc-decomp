// Detonate__8CGrenade  @ 000b93d0
void Detonate__8CGrenade(int *param_1)

{
  int iVar1;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [56];
  
  iVar1 = *param_1;
  local_48 = *(float *)(iVar1 + 8) + 0.0;
  local_44 = *(float *)(iVar1 + 0xc) + 0.0;
  local_40 = *(float *)(iVar1 + 0x10) + 8.0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0xc2200000;
  local_60 = local_48 + 0.0;
  local_5c = local_44 + 0.0;
  local_58 = local_40 + -40.0;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_48,&local_60,1,*(undefined4 *)(iVar1 + 0x1e8),local_3c);
  (**(code **)(param_1[0xf2] + 0x218))(param_1,local_3c,0x40);
  return;
}


