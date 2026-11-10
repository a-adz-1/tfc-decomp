// FVisible__11CBaseEntityP11CBaseEntity  @ 000b35f8
undefined4 FVisible__11CBaseEntityP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  code *pcVar2;
  float local_5c;
  float local_58;
  code *local_54;
  float local_50;
  float local_4c;
  undefined1 local_48 [4];
  float local_44;
  float local_40;
  code *local_3c [4];
  float local_2c;
  
  if (*(char *)(*param_2 + 0x1a4) < '\0') {
    return 0;
  }
  if (*(int *)(*param_1 + 0x1c0) != 3) {
    if (*(int *)(*param_2 + 0x1c0) == 3) {
      return 0;
    }
    if (*(int *)(*param_1 + 0x1c0) != 3) goto LAB_000b3653;
  }
  if (*(int *)(*param_2 + 0x1c0) == 0) {
    return 0;
  }
LAB_000b3653:
  iVar1 = *param_1;
  local_5c = *(float *)(iVar1 + 8) + *(float *)(iVar1 + 0x174);
  local_58 = *(float *)(*param_1 + 0xc) + *(float *)(iVar1 + 0x178);
  local_54 = (code *)(*(float *)(*param_1 + 0x10) + *(float *)(iVar1 + 0x17c));
  pcVar2 = *(code **)(param_2[0xf5] + 200);
  local_44 = local_5c;
  local_40 = local_58;
  local_3c[0] = local_54;
  (*pcVar2)(&local_5c,param_2);
  local_50 = local_5c;
  local_4c = local_58;
  local_54 = pcVar2;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
            (local_48,&local_54,1,1,*(undefined4 *)(*param_1 + 0x208),local_3c);
  if ((byte)((byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) != 0x40) {
    return 0;
  }
  return 1;
}


// FVisible__11CBaseEntityRC6Vector  @ 000b373c
bool FVisible__11CBaseEntityRC6Vector(int *param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 local_50;
  undefined4 local_4c;
  code *local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 local_3c [16];
  float local_2c;
  
  pcVar1 = *(code **)(param_1[0xf5] + 200);
  (*pcVar1)(&local_50,param_1);
  local_44 = local_50;
  local_40 = local_4c;
  local_48 = pcVar1;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
            (&local_48,param_2,1,1,*(undefined4 *)(*param_1 + 0x208),local_3c);
  return (byte)((byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40;
}


