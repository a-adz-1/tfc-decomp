// BBoxFlat__12CBaseMonster  @ 000c7e60
undefined4 BBoxFlat__12CBaseMonster(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [20];
  float local_28;
  float local_24;
  float local_20;
  
  iVar1 = *param_1;
  fVar2 = *(float *)(iVar1 + 0xd4) * 0.5;
  fVar3 = *(float *)(iVar1 + 0xd8) * 0.5;
  local_48 = fVar2 + *(float *)(iVar1 + 8);
  local_44 = fVar3 + *(float *)(iVar1 + 0xc);
  local_40 = *(float *)(iVar1 + 0x10);
  local_60 = 0.0;
  local_5c = 0.0;
  local_58 = 100.0;
  local_54 = local_48 - 0.0;
  local_50 = local_44 - 0.0;
  local_4c = local_40 - 100.0;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_48,&local_54,1,*(undefined4 *)(iVar1 + 0x1e8),local_3c);
  fVar4 = local_48 - local_28;
  fVar6 = local_44 - local_24;
  fVar5 = local_40 - local_20;
  iVar1 = *param_1;
  local_48 = *(float *)(iVar1 + 8) - fVar2;
  local_44 = *(float *)(iVar1 + 0xc) - fVar3;
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 100.0;
  local_60 = local_48 - 0.0;
  local_5c = local_44 - 0.0;
  local_58 = local_40 - 100.0;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_48,&local_60,1,*(undefined4 *)(iVar1 + 0x1e8),local_3c);
  fVar7 = SQRT((local_40 - local_20) * (local_40 - local_20) +
               (local_44 - local_24) * (local_44 - local_24) +
               (local_48 - local_28) * (local_48 - local_28));
  if (fVar7 <= SQRT(fVar5 * fVar5 + fVar6 * fVar6 + fVar4 * fVar4)) {
    iVar1 = *param_1;
    local_48 = *(float *)(iVar1 + 8) - fVar2;
    local_44 = fVar3 + *(float *)(iVar1 + 0xc);
    local_54 = 0.0;
    local_50 = 0.0;
    local_4c = 100.0;
    local_60 = local_48 - 0.0;
    local_5c = local_44 - 0.0;
    local_58 = local_40 - 100.0;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_48,&local_60,1,*(undefined4 *)(iVar1 + 0x1e8),local_3c);
    fVar4 = SQRT((local_40 - local_20) * (local_40 - local_20) +
                 (local_44 - local_24) * (local_44 - local_24) +
                 (local_48 - local_28) * (local_48 - local_28));
    if (fVar4 <= fVar7) {
      iVar1 = *param_1;
      local_48 = fVar2 + *(float *)(iVar1 + 8);
      local_44 = *(float *)(iVar1 + 0xc) - fVar3;
      local_54 = 0.0;
      local_50 = 0.0;
      local_4c = 100.0;
      local_60 = local_48 - 0.0;
      local_5c = local_44 - 0.0;
      local_58 = local_40 - 100.0;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (&local_48,&local_60,1,*(undefined4 *)(iVar1 + 0x1e8),local_3c);
      if (SQRT((local_40 - local_20) * (local_40 - local_20) +
               (local_44 - local_24) * (local_44 - local_24) +
               (local_48 - local_28) * (local_48 - local_28)) <= fVar4) {
        return 1;
      }
    }
  }
  return 0;
}


