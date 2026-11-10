// FindHullIntersection__FRC6VectorR11TraceResultPfT2P7edict_s  @ 0008f37c
void FindHullIntersection__FRC6VectorR11TraceResultPfT2P7edict_s
               (float *param_1,undefined4 *param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float fStack_88;
  int iStack_84;
  int iStack_80;
  int local_7c [2];
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float local_44;
  float fStack_40;
  float fStack_3c;
  undefined4 auStack_38 [4];
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  
  local_7c[0] = param_3;
  local_7c[1] = param_4;
  fStack_88 = 1e+06;
  fStack_74 = (float)param_2[5] - *param_1;
  fStack_70 = (float)param_2[6] - param_1[1];
  fStack_6c = (float)param_2[7] - param_1[2];
  fStack_68 = fStack_74 + fStack_74;
  fStack_64 = fStack_70 + fStack_70;
  fStack_60 = fStack_6c + fStack_6c;
  fStack_5c = *param_1 + fStack_68;
  fStack_58 = param_1[1] + fStack_64;
  fStack_54 = param_1[2] + fStack_60;
  local_44 = fStack_5c;
  fStack_40 = fStack_58;
  fStack_3c = fStack_54;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (param_1,&local_44,0,param_5,auStack_38);
  if ((byte)((1.0 < fStack_28 | (byte)((ushort)((ushort)NAN(fStack_28) << 10) >> 8) |
             (byte)((ushort)((ushort)(fStack_28 == 1.0) << 0xe) >> 8)) - 1) < 0x40) {
    iStack_80 = 0;
    do {
      iStack_84 = 0;
      do {
        fStack_50 = local_44 + *(float *)local_7c[iStack_80];
        fStack_4c = fStack_40 + *(float *)(local_7c[iStack_84] + 4);
        fStack_48 = fStack_3c + *(float *)(local_7c[0] + 8);
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (param_1,&fStack_50,0,param_5,auStack_38);
        if (0x3f < (byte)((1.0 < fStack_28 | (byte)((ushort)((ushort)NAN(fStack_28) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fStack_28 == 1.0) << 0xe) >> 8)) - 1)) {
          fStack_74 = fStack_24 - *param_1;
          fStack_70 = fStack_20 - param_1[1];
          fStack_6c = fStack_1c - param_1[2];
          fStack_68 = SQRT(fStack_6c * fStack_6c + fStack_70 * fStack_70 + fStack_74 * fStack_74);
          if (fStack_68 < fStack_88) {
            puVar2 = auStack_38;
            puVar3 = param_2;
            for (iVar1 = 0xe; fStack_88 = fStack_68, iVar1 != 0; iVar1 = iVar1 + -1) {
              *puVar3 = *puVar2;
              puVar2 = puVar2 + 1;
              puVar3 = puVar3 + 1;
            }
          }
        }
        fStack_50 = local_44 + *(float *)local_7c[iStack_80];
        fStack_4c = fStack_40 + *(float *)(local_7c[iStack_84] + 4);
        fStack_48 = fStack_3c + *(float *)(local_7c[1] + 8);
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (param_1,&fStack_50,0,param_5,auStack_38);
        if (0x3f < (byte)((1.0 < fStack_28 | (byte)((ushort)((ushort)NAN(fStack_28) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fStack_28 == 1.0) << 0xe) >> 8)) - 1)) {
          fStack_74 = fStack_24 - *param_1;
          fStack_70 = fStack_20 - param_1[1];
          fStack_6c = fStack_1c - param_1[2];
          fStack_68 = SQRT(fStack_6c * fStack_6c + fStack_70 * fStack_70 + fStack_74 * fStack_74);
          if (fStack_68 < fStack_88) {
            puVar2 = auStack_38;
            puVar3 = param_2;
            for (iVar1 = 0xe; fStack_88 = fStack_68, iVar1 != 0; iVar1 = iVar1 + -1) {
              *puVar3 = *puVar2;
              puVar2 = puVar2 + 1;
              puVar3 = puVar3 + 1;
            }
          }
        }
        iStack_84 = iStack_84 + 1;
      } while (iStack_84 < 2);
      iStack_80 = iStack_80 + 1;
    } while (iStack_80 < 2);
  }
  else {
    puVar2 = auStack_38;
    for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_2 = *puVar2;
      puVar2 = puVar2 + 1;
      param_2 = param_2 + 1;
    }
  }
  return;
}


