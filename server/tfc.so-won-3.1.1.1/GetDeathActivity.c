// GetDeathActivity__12CBaseMonster  @ 000957f4
int GetDeathActivity__12CBaseMonster(int *param_1)

{
  bool bVar1;
  float fVar2;
  int iVar3;
  int iVar4;
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
  
  if (*(int *)(*param_1 + 0x170) != 0) {
    return param_1[0x15b];
  }
  (**(code **)(param_1[0x115] + 0xcc))(&local_54,param_1);
  local_48 = local_54;
  local_44 = local_50;
  local_40 = local_4c;
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  bVar1 = false;
  local_54 = -g_vecAttackDir;
  local_50 = -DAT_0019f670;
  local_4c = -DAT_0019f674;
  iVar4 = 0x24;
  iVar3 = param_1[0x15c];
  fVar2 = local_4c * *(float *)(gpGlobals + 0x30) +
          local_50 * *(float *)(gpGlobals + 0x2c) + local_54 * *(float *)(gpGlobals + 0x28);
  if (iVar3 == 1) {
    iVar4 = 0x42;
    goto LAB_0009593b;
  }
  if (iVar3 < 2) {
    if (iVar3 != 0) goto LAB_00095904;
    if ((byte)(0.3 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 0.3) << 0xe) >> 8)) != 1) goto LAB_00095924;
  }
  else {
    if (iVar3 == 3) {
      iVar4 = 0x44;
      goto LAB_0009593b;
    }
LAB_00095904:
    if (fVar2 <= 0.3) {
LAB_00095924:
      bVar1 = true;
      if ((byte)(-0.3 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == -0.3) << 0xe) >> 8)) != 1) {
        iVar4 = 0x25;
      }
      goto LAB_0009593b;
    }
  }
  bVar1 = true;
  iVar4 = 0x26;
LAB_0009593b:
  iVar3 = LookupActivity__14CBaseAnimatingi(param_1,iVar4);
  if (iVar3 == -1) {
    if (bVar1) {
      iVar4 = 0x24;
    }
    else if (fVar2 <= 0.3) {
      if ((byte)(-0.3 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == -0.3) << 0xe) >> 8)) != 1) {
        iVar4 = 0x25;
      }
    }
    else {
      iVar4 = 0x26;
    }
  }
  iVar3 = LookupActivity__14CBaseAnimatingi(param_1,iVar4);
  if (iVar3 == -1) {
    iVar4 = 0x24;
  }
  if (iVar4 == 0x26) {
    local_60 = *(float *)(gpGlobals + 0x28) * 64.0;
    local_5c = *(float *)(gpGlobals + 0x2c) * 64.0;
    local_58 = *(float *)(gpGlobals + 0x30) * 64.0;
    local_54 = local_60 + local_48;
    local_50 = local_5c + local_44;
    local_4c = local_58 + local_40;
    UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
              (&local_48,&local_54,0,3,*(undefined4 *)(*param_1 + 0x208),local_3c);
    if ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) != 0x40) {
      iVar4 = 0x24;
    }
  }
  if (iVar4 == 0x25) {
    local_54 = *(float *)(gpGlobals + 0x28) * 64.0;
    local_50 = *(float *)(gpGlobals + 0x2c) * 64.0;
    local_4c = *(float *)(gpGlobals + 0x30) * 64.0;
    local_60 = local_48 - local_54;
    local_5c = local_44 - local_50;
    local_58 = local_40 - local_4c;
    UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
              (&local_48,&local_60,0,3,*(undefined4 *)(*param_1 + 0x208),local_3c);
    if ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) != 0x40) {
      iVar4 = 0x24;
    }
  }
  return iVar4;
}


