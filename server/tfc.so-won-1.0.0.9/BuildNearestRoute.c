// BuildNearestRoute__12CBaseMonsterG6VectorT1ff  @ 000c4a30
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
BuildNearestRoute__12CBaseMonsterG6VectorT1ff
          (int *param_1,float *param_2,float *param_3,float param_4,float param_5)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  undefined1 auStack_48 [16];
  float fStack_38;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  if ((byte)((byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_5 == 0.0) << 0xe) >> 8)) == 0x40) {
    param_5 = 784.0;
  }
  fVar2 = param_5 * 0.5;
  if ((byte)(fVar2 < param_4 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(param_4)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == param_4) << 0xe) >> 8)) == 1) {
    param_4 = fVar2;
  }
  if ((WorldGraph == 0) || (DAT_001758c4 == 0)) {
    (*DAT_001755b4)(2,"Graph not ready for BuildNearestRoute!\n");
  }
  else {
    iVar3 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity(&WorldGraph,*param_1 + 8,param_1);
    uVar4 = HullIndex__6CGraphPC11CBaseEntity(&WorldGraph,param_1);
    if (iVar3 == -1) {
      (*DAT_001755b4)(2,"BuildNearestRoute() - %s has no nearest node!\n",
                      *(int *)*param_1 + *(int *)(gpGlobals + 0x98));
    }
    else {
      fStack_58 = *param_2 + *param_3;
      fStack_54 = param_2[1] + param_3[1];
      fStack_50 = param_2[2] + param_3[2];
      if (0 < DAT_001758d8) {
        iVar6 = 0;
        fStack_10 = fStack_58;
        fStack_c = fStack_54;
        fStack_8 = fStack_50;
        do {
          iVar5 = (iVar6 + _DAT_00177988) % DAT_001758d8;
          pfVar1 = (float *)(DAT_001758cc + iVar5 * 0x58);
          _DAT_00177988 = iVar5 + 1;
          iVar5 = NextNodeInRoute__6CGraphiiii(&WorldGraph,iVar3,iVar5,uVar4,0);
          if (iVar5 != iVar3) {
            fStack_58 = *param_2 - *pfVar1;
            fStack_54 = param_2[1] - pfVar1[1];
            fStack_50 = param_2[2] - pfVar1[2];
            fStack_5c = SQRT(fStack_50 * fStack_50 + fStack_54 * fStack_54 + fStack_58 * fStack_58);
            if ((param_4 < fStack_5c) &&
               ((byte)(fStack_5c < param_5 |
                       (byte)((ushort)((ushort)(NAN(fStack_5c) || NAN(param_5)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fStack_5c == param_5) << 0xe) >> 8)) == 1)) {
              iVar5 = *param_1;
              fStack_5c = *pfVar1 + *(float *)(iVar5 + 0x154);
              fStack_58 = pfVar1[1] + *(float *)(iVar5 + 0x158);
              fStack_54 = pfVar1[2] + *(float *)(iVar5 + 0x15c);
              UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                        (&fStack_5c,&fStack_10,1,*(undefined4 *)(iVar5 + 0x1e8),auStack_48);
              if (((byte)((byte)((ushort)((ushort)NAN(fStack_38) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fStack_38 == 1.0) << 0xe) >> 8)) == 0x40) &&
                 (iVar5 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity(param_1,pfVar1,0x40,0),
                 iVar5 != 0)) {
                param_1[0x162] = (int)*pfVar1;
                param_1[0x163] = (int)pfVar1[1];
                param_1[0x164] = (int)pfVar1[2];
                return 1;
              }
            }
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < DAT_001758d8);
      }
    }
  }
  return 0;
}


