// BBoxFlat__12CBaseMonster  @ 000b6c40
undefined4 BBoxFlat__12CBaseMonster(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  undefined1 local_38 [20];
  float local_24;
  float local_20;
  float local_1c;
  
  iVar1 = *param_1;
  fVar2 = *(float *)(iVar1 + 0xf4) * 0.5;
  fVar3 = *(float *)(iVar1 + 0xf8) * 0.5;
  local_50 = fVar2 + *(float *)(iVar1 + 8);
  local_4c = fVar3 + *(float *)(iVar1 + 0xc);
  local_3c = *(float *)(iVar1 + 0x10);
  local_5c = 0.0;
  local_58 = 0.0;
  local_54 = 100.0;
  local_48 = local_3c - 100.0;
  local_44 = local_50;
  local_40 = local_4c;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_44,&local_50,1,*(undefined4 *)(iVar1 + 0x208),local_38);
  fVar4 = local_44 - local_24;
  fVar6 = local_40 - local_20;
  fVar5 = local_3c - local_1c;
  iVar1 = *param_1;
  local_5c = *(float *)(iVar1 + 8) - fVar2;
  local_58 = *(float *)(iVar1 + 0xc) - fVar3;
  local_50 = 0.0;
  local_4c = 0.0;
  local_48 = 100.0;
  local_54 = local_3c - 100.0;
  local_44 = local_5c;
  local_40 = local_58;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_44,&local_5c,1,*(undefined4 *)(iVar1 + 0x208),local_38);
  fVar7 = SQRT((local_3c - local_1c) * (local_3c - local_1c) +
               (local_40 - local_20) * (local_40 - local_20) +
               (local_44 - local_24) * (local_44 - local_24));
  if (fVar7 <= SQRT(fVar5 * fVar5 + fVar6 * fVar6 + fVar4 * fVar4)) {
    iVar1 = *param_1;
    local_5c = *(float *)(iVar1 + 8) - fVar2;
    local_58 = fVar3 + *(float *)(iVar1 + 0xc);
    local_48 = 100.0;
    local_50 = 0.0;
    local_4c = 0.0;
    local_54 = local_3c - 100.0;
    local_44 = local_5c;
    local_40 = local_58;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_44,&local_5c,1,*(undefined4 *)(iVar1 + 0x208),local_38);
    fVar4 = SQRT((local_3c - local_1c) * (local_3c - local_1c) +
                 (local_40 - local_20) * (local_40 - local_20) +
                 (local_44 - local_24) * (local_44 - local_24));
    if (fVar4 <= fVar7) {
      iVar1 = *param_1;
      local_5c = fVar2 + *(float *)(iVar1 + 8);
      local_58 = *(float *)(iVar1 + 0xc) - fVar3;
      local_48 = 100.0;
      local_50 = 0.0;
      local_4c = 0.0;
      local_54 = local_3c - 100.0;
      local_44 = local_5c;
      local_40 = local_58;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (&local_44,&local_5c,1,*(undefined4 *)(iVar1 + 0x208),local_38);
      if (SQRT((local_3c - local_1c) * (local_3c - local_1c) +
               (local_40 - local_20) * (local_40 - local_20) +
               (local_44 - local_24) * (local_44 - local_24)) <= fVar4) {
        return 1;
      }
    }
  }
  return 0;
}


