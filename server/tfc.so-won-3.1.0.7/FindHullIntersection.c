// FindHullIntersection__FRC6VectorR11TraceResultPfT2P7edict_s  @ 00097eb4
void FindHullIntersection__FRC6VectorR11TraceResultPfT2P7edict_s
               (float *param_1,undefined4 *param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float local_88;
  int local_84;
  int local_80;
  int local_7c [2];
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  undefined4 local_38 [4];
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  
  local_7c[0] = param_3;
  local_7c[1] = param_4;
  local_88 = 1e+06;
  local_74 = (float)param_2[5] - *param_1;
  local_70 = (float)param_2[6] - param_1[1];
  local_6c = (float)param_2[7] - param_1[2];
  local_68 = local_74 + local_74;
  local_64 = local_70 + local_70;
  local_60 = local_6c + local_6c;
  local_5c = *param_1 + local_68;
  local_58 = param_1[1] + local_64;
  local_54 = param_1[2] + local_60;
  local_44 = local_5c;
  local_40 = local_58;
  local_3c = local_54;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (param_1,&local_44,0,param_5,local_38);
  if ((byte)((1.0 < local_28 | (byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_28 == 1.0) << 0xe) >> 8)) - 1) < 0x40) {
    local_80 = 0;
    do {
      local_84 = 0;
      do {
        local_50 = local_44 + *(float *)local_7c[local_80];
        local_4c = local_40 + *(float *)(local_7c[local_84] + 4);
        local_48 = local_3c + *(float *)(local_7c[0] + 8);
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (param_1,&local_50,0,param_5,local_38);
        if (0x3f < (byte)((1.0 < local_28 | (byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
                          (byte)((ushort)((ushort)(local_28 == 1.0) << 0xe) >> 8)) - 1)) {
          local_74 = local_24 - *param_1;
          local_70 = local_20 - param_1[1];
          local_6c = local_1c - param_1[2];
          local_68 = SQRT(local_6c * local_6c + local_70 * local_70 + local_74 * local_74);
          if (local_68 < local_88) {
            puVar2 = local_38;
            puVar3 = param_2;
            for (iVar1 = 0xe; local_88 = local_68, iVar1 != 0; iVar1 = iVar1 + -1) {
              *puVar3 = *puVar2;
              puVar2 = puVar2 + 1;
              puVar3 = puVar3 + 1;
            }
          }
        }
        local_50 = local_44 + *(float *)local_7c[local_80];
        local_4c = local_40 + *(float *)(local_7c[local_84] + 4);
        local_48 = local_3c + *(float *)(local_7c[1] + 8);
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (param_1,&local_50,0,param_5,local_38);
        if (0x3f < (byte)((1.0 < local_28 | (byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
                          (byte)((ushort)((ushort)(local_28 == 1.0) << 0xe) >> 8)) - 1)) {
          local_74 = local_24 - *param_1;
          local_70 = local_20 - param_1[1];
          local_6c = local_1c - param_1[2];
          local_68 = SQRT(local_6c * local_6c + local_70 * local_70 + local_74 * local_74);
          if (local_68 < local_88) {
            puVar2 = local_38;
            puVar3 = param_2;
            for (iVar1 = 0xe; local_88 = local_68, iVar1 != 0; iVar1 = iVar1 + -1) {
              *puVar3 = *puVar2;
              puVar2 = puVar2 + 1;
              puVar3 = puVar3 + 1;
            }
          }
        }
        local_84 = local_84 + 1;
      } while (local_84 < 2);
      local_80 = local_80 + 1;
    } while (local_80 < 2);
  }
  else {
    puVar2 = local_38;
    for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_2 = *puVar2;
      puVar2 = puVar2 + 1;
      param_2 = param_2 + 1;
    }
  }
  return;
}


