// GetDeathActivity__12CBaseMonster  @ 000a4820
int GetDeathActivity__12CBaseMonster(int *param_1)

{
  float fVar1;
  bool bVar2;
  byte bVar4;
  int iVar3;
  int iVar5;
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
  
  if (*(int *)(*param_1 + 0x150) != 0) {
    return param_1[0x138];
  }
  (**(code **)(param_1[0xf2] + 0xc4))(&local_54,param_1);
  local_48 = local_54;
  local_44 = local_50;
  local_40 = local_4c;
  bVar2 = false;
  iVar5 = 0x24;
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  local_54 = g_vecAttackDir * -1.0;
  local_50 = DAT_00175490 * -1.0;
  local_4c = DAT_00175494 * -1.0;
  fVar1 = *(float *)(gpGlobals + 0x30) * local_4c +
          *(float *)(gpGlobals + 0x2c) * local_50 + *(float *)(gpGlobals + 0x28) * local_54;
  iVar3 = param_1[0x139];
  if (iVar3 == 1) {
    iVar5 = 0x42;
    goto LAB_000a4975;
  }
  if (iVar3 < 2) {
    if (iVar3 != 0) goto LAB_000a4940;
    bVar4 = 0.3 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.3) << 0xe) >> 8);
  }
  else {
    if (iVar3 == 3) {
      iVar5 = 0x44;
      goto LAB_000a4975;
    }
LAB_000a4940:
    bVar4 = 0.3 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.3) << 0xe) >> 8);
  }
  if (bVar4 == 1) {
    bVar2 = true;
    iVar5 = 0x26;
  }
  else {
    bVar2 = true;
    if (fVar1 <= -0.3) {
      iVar5 = 0x25;
    }
  }
LAB_000a4975:
  iVar3 = LookupActivity__14CBaseAnimatingi(param_1,iVar5);
  if (iVar3 == -1) {
    if (bVar2) {
      iVar5 = 0x24;
    }
    else if ((byte)(0.3 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar1 == 0.3) << 0xe) >> 8)) == 1) {
      iVar5 = 0x26;
    }
    else if (fVar1 <= -0.3) {
      iVar5 = 0x25;
    }
  }
  iVar3 = LookupActivity__14CBaseAnimatingi(param_1,iVar5);
  if (iVar3 == -1) {
    iVar5 = 0x24;
  }
  if (iVar5 == 0x26) {
    local_60 = *(float *)(gpGlobals + 0x28) * 64.0;
    local_5c = *(float *)(gpGlobals + 0x2c) * 64.0;
    local_58 = *(float *)(gpGlobals + 0x30) * 64.0;
    local_54 = local_48 + local_60;
    local_50 = local_44 + local_5c;
    local_4c = local_40 + local_58;
    UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
              (&local_48,&local_54,0,3,*(undefined4 *)(*param_1 + 0x1e8),local_3c);
    if ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) != 0x40) {
      iVar5 = 0x24;
    }
  }
  if (iVar5 == 0x25) {
    local_54 = *(float *)(gpGlobals + 0x28) * 64.0;
    local_50 = *(float *)(gpGlobals + 0x2c) * 64.0;
    local_4c = *(float *)(gpGlobals + 0x30) * 64.0;
    local_60 = local_48 - local_54;
    local_5c = local_44 - local_50;
    local_58 = local_40 - local_4c;
    UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
              (&local_48,&local_60,0,3,*(undefined4 *)(*param_1 + 0x1e8),local_3c);
    if ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) != 0x40) {
      iVar5 = 0x24;
    }
  }
  return iVar5;
}


