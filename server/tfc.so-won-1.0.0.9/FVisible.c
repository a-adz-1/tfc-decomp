// FVisible__11CBaseEntityP11CBaseEntity  @ 000c5040
undefined4 FVisible__11CBaseEntityP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [16];
  float local_2c;
  
  if (*(char *)(*param_2 + 0x184) < '\0') {
    return 0;
  }
  if (*(int *)(*param_1 + 0x1a0) != 3) {
    if (*(int *)(*param_2 + 0x1a0) == 3) {
      return 0;
    }
    if (*(int *)(*param_1 + 0x1a0) != 3) goto LAB_000c508e;
  }
  if (*(int *)(*param_2 + 0x1a0) == 0) {
    return 0;
  }
LAB_000c508e:
  iVar1 = *param_1;
  local_60 = *(float *)(iVar1 + 8) + *(float *)(iVar1 + 0x154);
  local_5c = *(float *)(*param_1 + 0xc) + *(float *)(iVar1 + 0x158);
  local_58 = *(float *)(*param_1 + 0x10) + *(float *)(iVar1 + 0x15c);
  local_48 = local_60;
  local_44 = local_5c;
  local_40 = local_58;
  (**(code **)(param_2[0xf2] + 200))(&local_60,param_2);
  local_54 = local_60;
  local_50 = local_5c;
  local_4c = local_58;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
            (&local_48,&local_54,1,1,*(undefined4 *)(*param_1 + 0x1e8),local_3c);
  if ((byte)((byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) != 0x40) {
    return 0;
  }
  return 1;
}


// FVisible__11CBaseEntityRC6Vector  @ 000c5140
bool FVisible__11CBaseEntityRC6Vector(int *param_1,undefined4 param_2)

{
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 local_3c [16];
  float local_2c;
  
  (**(code **)(param_1[0xf2] + 200))(&local_54,param_1);
  local_48 = local_54;
  local_44 = local_50;
  local_40 = local_4c;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
            (&local_48,param_2,1,1,*(undefined4 *)(*param_1 + 0x1e8),local_3c);
  return (byte)((byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40;
}


