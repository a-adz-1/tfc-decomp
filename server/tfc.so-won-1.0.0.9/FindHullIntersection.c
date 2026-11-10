// FindHullIntersection__FRC6VectorR11TraceResultPfT2P7edict_s  @ 000a6650
void FindHullIntersection__FRC6VectorR11TraceResultPfT2P7edict_s
               (float *param_1,undefined4 *param_2,int param_3,undefined4 param_4,undefined4 param_5
               )

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float local_8c;
  int local_88;
  int local_84;
  int local_80 [2];
  float local_78;
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
  undefined4 local_3c [4];
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
  local_80[0] = param_3;
  local_80[1] = param_4;
  local_8c = 1e+06;
  local_78 = (float)param_2[5] - *param_1;
  local_74 = (float)param_2[6] - param_1[1];
  local_70 = (float)param_2[7] - param_1[2];
  local_6c = local_78 + local_78;
  local_68 = local_74 + local_74;
  local_64 = local_70 + local_70;
  local_60 = *param_1 + local_6c;
  local_5c = param_1[1] + local_68;
  local_58 = param_1[2] + local_64;
  local_48 = local_60;
  local_44 = local_5c;
  local_40 = local_58;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (param_1,&local_48,0,param_5,local_3c);
  if (1.0 <= local_2c) {
    local_84 = 0;
    do {
      local_88 = 0;
      do {
        iVar1 = 0;
        do {
          local_54 = local_48 + *(float *)local_80[local_84];
          local_50 = local_44 + *(float *)(local_80[local_88] + 4);
          local_4c = local_40 + *(float *)(local_80[iVar1] + 8);
          UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                    (param_1,&local_54,0,param_5,local_3c);
          if (local_2c < 1.0) {
            local_78 = local_28 - *param_1;
            local_74 = local_24 - param_1[1];
            local_70 = local_20 - param_1[2];
            local_6c = SQRT(local_70 * local_70 + local_74 * local_74 + local_78 * local_78);
            if ((byte)(local_6c < local_8c |
                       (byte)((ushort)((ushort)(NAN(local_6c) || NAN(local_8c)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(local_6c == local_8c) << 0xe) >> 8)) == 1) {
              puVar3 = local_3c;
              puVar4 = param_2;
              for (iVar2 = 0xe; local_8c = local_6c, iVar2 != 0; iVar2 = iVar2 + -1) {
                *puVar4 = *puVar3;
                puVar3 = puVar3 + 1;
                puVar4 = puVar4 + 1;
              }
            }
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < 2);
        local_88 = local_88 + 1;
      } while (local_88 < 2);
      local_84 = local_84 + 1;
    } while (local_84 < 2);
  }
  else {
    puVar3 = local_3c;
    for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_2 = *puVar3;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + 1;
    }
  }
  return;
}


