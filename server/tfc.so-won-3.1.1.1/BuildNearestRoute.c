// BuildNearestRoute__12CBaseMonsterG6VectorT1ff  @ 000be1f4
undefined4
BuildNearestRoute__12CBaseMonsterG6VectorT1ff
          (int *param_1,float *param_2,float *param_3,float param_4,float param_5)

{
  float *pfVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int local_80;
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
    (*DAT_0019f794)(2,FUN_0014de40);
  }
  else {
    iVar2 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity(&WorldGraph,*param_1 + 8,param_1);
    uVar3 = HullIndex__6CGraphPC11CBaseEntity(&WorldGraph,param_1);
    if (iVar2 == -1) {
      (*DAT_0019f794)(2,"BuildNearestRoute() - %s has no nearest node!\n",
                      *(int *)*param_1 + *(int *)(gpGlobals + 0x98));
    }
    else {
      local_58 = *param_2 + *param_3;
      local_54 = param_2[1] + param_3[1];
      local_50 = param_2[2] + param_3[2];
      local_80 = 0;
      if (0 < DAT_0019fb38) {
        local_10 = local_58;
        local_c = local_54;
        local_8 = local_50;
        do {
          iVar4 = (local_80 + DAT_001a1be8) % DAT_0019fb38;
          pfVar1 = (float *)(DAT_0019fb2c + iVar4 * 0x58);
          DAT_001a1be8 = iVar4 + 1;
          iVar4 = NextNodeInRoute__6CGraphiiii(&WorldGraph,iVar2,iVar4,uVar3,0);
          if (iVar4 != iVar2) {
            local_58 = *param_2 - *pfVar1;
            local_54 = param_2[1] - pfVar1[1];
            local_50 = param_2[2] - pfVar1[2];
            local_5c = SQRT(local_50 * local_50 + local_54 * local_54 + local_58 * local_58);
            if ((0x3f < (byte)((local_5c < param_4 |
                                (byte)((ushort)((ushort)(NAN(local_5c) || NAN(param_4)) << 10) >> 8)
                               | (byte)((ushort)((ushort)(local_5c == param_4) << 0xe) >> 8)) - 1))
               && (local_5c < param_5)) {
              iVar4 = *param_1;
              local_5c = *pfVar1 + *(float *)(iVar4 + 0x174);
              local_58 = pfVar1[1] + *(float *)(iVar4 + 0x178);
              local_54 = pfVar1[2] + *(float *)(iVar4 + 0x17c);
              UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                        (&local_5c,&local_10,1,*(undefined4 *)(iVar4 + 0x208),local_48);
              if (((byte)((byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
                         (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) == 0x40) &&
                 (iVar4 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,pfVar1,0x40,0),
                 iVar4 != 0)) {
                param_1[0x185] = (int)*pfVar1;
                param_1[0x186] = (int)pfVar1[1];
                param_1[0x187] = (int)pfVar1[2];
                return 1;
              }
            }
          }
          local_80 = local_80 + 1;
        } while (local_80 < DAT_0019fb38);
      }
    }
  }
  return 0;
}


