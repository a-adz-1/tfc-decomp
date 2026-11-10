// FVisible__11CBaseEntityP11CBaseEntity  @ 000be848
undefined4 FVisible__11CBaseEntityP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
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
  
  iVar1 = *param_2;
  if (-1 < *(char *)(iVar1 + 0x1a4)) {
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x1c0) == 3) {
      if (*(int *)(iVar1 + 0x1c0) == 0) {
        return 0;
      }
    }
    else if (*(int *)(iVar1 + 0x1c0) == 3) {
      return 0;
    }
    local_60 = *(float *)(iVar2 + 8) + *(float *)(iVar2 + 0x174);
    local_5c = *(float *)(iVar2 + 0xc) + *(float *)(iVar2 + 0x178);
    local_58 = *(float *)(iVar2 + 0x10) + *(float *)(iVar2 + 0x17c);
    local_48 = local_60;
    local_44 = local_5c;
    local_40 = local_58;
    (**(code **)(param_2[0x115] + 0xd0))(&local_60,param_2);
    local_54 = local_60;
    local_50 = local_5c;
    local_4c = local_58;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
              (&local_48,&local_54,1,1,*(undefined4 *)(*param_1 + 0x208),local_3c);
    if ((byte)((byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40) {
      return 1;
    }
  }
  return 0;
}


// FVisible__11CBaseEntityRC6Vector  @ 000c217c
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
  
  (**(code **)(param_1[0x115] + 0xd0))(&local_54,param_1);
  local_48 = local_54;
  local_44 = local_50;
  local_40 = local_4c;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
            (&local_48,param_2,1,1,*(undefined4 *)(*param_1 + 0x208),local_3c);
  return (byte)((byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
               (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40;
}


