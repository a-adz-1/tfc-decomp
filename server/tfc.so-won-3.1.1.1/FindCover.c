// FindCover__12CBaseMonsterG6VectorT1ff  @ 000bded0
undefined4
FindCover__12CBaseMonsterG6VectorT1ff
          (int *param_1,float *param_2,float *param_3,float param_4,float param_5)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  longdouble lVar8;
  longdouble lVar9;
  int local_6c;
  int local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  undefined1 local_48 [16];
  float local_38;
  float local_10;
  float local_c;
  float local_8;
  
  if ((byte)((byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_5 == 0.0) << 0xe) >> 8)) == 0x40) {
    param_5 = 784.0;
  }
  if (param_5 * 0.5 < param_4) {
    param_4 = param_5 * 0.5;
  }
  if ((WorldGraph == 0) || (DAT_0019fb24 == 0)) {
    (*DAT_0019f794)(2,"Graph not ready for findcover!\n");
  }
  else {
    iVar4 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity(&WorldGraph,*param_1 + 8,param_1);
    local_6c = FindNearestNode__6CGraphRC6VectorP11CBaseEntity(&WorldGraph,param_2,param_1);
    uVar5 = HullIndex__6CGraphPC11CBaseEntity(&WorldGraph,param_1);
    if (iVar4 == -1) {
      (*DAT_0019f794)(2,"FindCover() - %s has no nearest node!\n",
                      *(int *)*param_1 + *(int *)(gpGlobals + 0x98));
    }
    else {
      if (local_6c == -1) {
        local_6c = iVar4;
      }
      local_10 = *param_2 + *param_3;
      local_c = param_2[1] + param_3[1];
      local_8 = param_2[2] + param_3[2];
      local_60 = 0;
      if (0 < DAT_0019fb38) {
        do {
          iVar7 = (local_60 + DAT_001a1be8) % DAT_0019fb38;
          pfVar1 = (float *)(DAT_0019fb2c + iVar7 * 0x58);
          DAT_001a1be8 = iVar7 + 1;
          iVar6 = *param_1;
          fVar2 = *(float *)(iVar6 + 8) - *pfVar1;
          fVar3 = *(float *)(iVar6 + 0xc) - pfVar1[1];
          local_50 = *(float *)(iVar6 + 0x10) - pfVar1[2];
          fVar2 = SQRT(local_50 * local_50 + fVar3 * fVar3 + fVar2 * fVar2);
          if (((byte)(fVar2 < param_4 |
                      (byte)((ushort)((ushort)(NAN(fVar2) || NAN(param_4)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == param_4) << 0xe) >> 8)) != 1) &&
             (fVar2 < param_5)) {
            local_5c = *pfVar1 + *param_3;
            local_58 = pfVar1[1] + param_3[1];
            local_54 = pfVar1[2] + param_3[2];
            UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
                      (&local_5c,&local_10,1,1,*(undefined4 *)(iVar6 + 0x208),local_48);
            if ((byte)(1.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
                      (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) != 0x40) {
              if (iVar4 != local_6c) {
                lVar8 = (longdouble)
                        PathLength__6CGraphiiii(&WorldGraph,iVar4,iVar7,uVar5,param_1[0x195]);
                lVar9 = (longdouble)
                        PathLength__6CGraphiiii(&WorldGraph,local_6c,iVar7,uVar5,param_1[0x195]);
                lVar8 = (longdouble)(float)lVar8;
                if ((byte)(lVar9 < lVar8 |
                           (byte)((ushort)((ushort)(NAN(lVar9) || NAN(lVar8)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(lVar9 == lVar8) << 0xe) >> 8)) == 1)
                goto LAB_000be1cf;
              }
              iVar6 = (**(code **)(param_1[0x115] + 0x1b4))(param_1,pfVar1);
              if (iVar6 != 0) {
                param_1[0x188] = 4;
                param_1[0x184] = 0;
                param_1[0x182] = 0x40;
                param_1[0x185] = (int)*pfVar1;
                param_1[0x186] = (int)pfVar1[1];
                param_1[0x187] = (int)pfVar1[2];
                iVar6 = FRefreshRoute__12CBaseMonster(param_1);
                if (iVar6 != 0) {
                  return 1;
                }
              }
            }
          }
LAB_000be1cf:
          local_60 = local_60 + 1;
        } while (local_60 < DAT_0019fb38);
      }
    }
  }
  return 0;
}


