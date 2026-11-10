// FindHullIntersection__FRC6VectorR11TraceResultPfT2P7edict_s  @ 00097640
void FindHullIntersection__FRC6VectorR11TraceResultPfT2P7edict_s
               (float *param_1,undefined4 *param_2,int param_3,undefined4 param_4,undefined4 param_5
               )

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iStack_8c;
  int iStack_88;
  int iStack_84;
  int aiStack_80 [2];
  float fStack_78;
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
  float fStack_44;
  float fStack_40;
  undefined4 auStack_3c [4];
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  
  aiStack_80[0] = param_3;
  aiStack_80[1] = param_4;
  fStack_78 = (float)param_2[5] - *param_1;
  fStack_74 = (float)param_2[6] - param_1[1];
  fStack_70 = (float)param_2[7] - param_1[2];
  fStack_6c = fStack_78 + fStack_78;
  fStack_68 = fStack_74 + fStack_74;
  fStack_64 = fStack_70 + fStack_70;
  fStack_60 = *param_1 + fStack_6c;
  fStack_5c = param_1[1] + fStack_68;
  fStack_58 = param_1[2] + fStack_64;
  fVar1 = 1e+06;
  fStack_48 = fStack_60;
  fStack_44 = fStack_5c;
  fStack_40 = fStack_58;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (param_1,&fStack_48,0,param_5,auStack_3c);
  if ((byte)((1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
             (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) - 1) < 0x40) {
    iStack_84 = 0;
    do {
      iStack_88 = 0;
      do {
        iStack_8c = 0;
        do {
          fStack_54 = fStack_48 + *(float *)aiStack_80[iStack_84];
          fStack_50 = fStack_44 + *(float *)(aiStack_80[iStack_88] + 4);
          fStack_4c = fStack_40 + *(float *)(aiStack_80[iStack_8c] + 8);
          UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                    (param_1,&fStack_54,0,param_5,auStack_3c);
          if (0x3f < (byte)((1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) - 1)) {
            fStack_78 = fStack_28 - *param_1;
            fStack_74 = fStack_24 - param_1[1];
            fStack_70 = fStack_20 - param_1[2];
            fStack_6c = SQRT(fStack_70 * fStack_70 + fStack_74 * fStack_74 + fStack_78 * fStack_78);
            if (fStack_6c < fVar1) {
              puVar3 = auStack_3c;
              puVar4 = param_2;
              for (iVar2 = 0xe; fVar1 = fStack_6c, iVar2 != 0; iVar2 = iVar2 + -1) {
                *puVar4 = *puVar3;
                puVar3 = puVar3 + 1;
                puVar4 = puVar4 + 1;
              }
            }
          }
          iStack_8c = iStack_8c + 1;
        } while (iStack_8c < 2);
        iStack_88 = iStack_88 + 1;
      } while (iStack_88 < 2);
      iStack_84 = iStack_84 + 1;
    } while (iStack_84 < 2);
  }
  else {
    puVar3 = auStack_3c;
    for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_2 = *puVar3;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + 1;
    }
  }
  return;
}


