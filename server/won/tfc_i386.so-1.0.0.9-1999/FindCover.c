// FindCover__12CBaseMonsterG6VectorT1ff  @ 000c4760
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  int iVar8;
  longdouble lVar9;
  longdouble lVar10;
  int local_68;
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
  fVar2 = (float)_FUN_00135d30 * param_5;
  if ((byte)(fVar2 < param_4 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(param_4)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == param_4) << 0xe) >> 8)) == 1) {
    param_4 = fVar2;
  }
  if ((WorldGraph == 0) || (DAT_001758c4 == 0)) {
    (*DAT_001755b4)(2,"Graph not ready for findcover!\n");
  }
  else {
    iVar4 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity(&WorldGraph,*param_1 + 8,param_1);
    local_68 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity(&WorldGraph,param_2,param_1);
    uVar5 = HullIndex__6CGraphPC11CBaseEntity(&WorldGraph,param_1);
    if (iVar4 == -1) {
      (*DAT_001755b4)(2,"FindCover() - %s has no nearest node!\n",
                      *(int *)*param_1 + *(int *)(gpGlobals + 0x98));
    }
    else {
      if (local_68 == -1) {
        local_68 = iVar4;
      }
      local_10 = *param_2 + *param_3;
      local_c = param_2[1] + param_3[1];
      local_8 = param_2[2] + param_3[2];
      iVar8 = 0;
      if (0 < DAT_001758d8) {
        do {
          iVar7 = (iVar8 + _DAT_00177988) % DAT_001758d8;
          pfVar1 = (float *)(DAT_001758cc + iVar7 * 0x58);
          _DAT_00177988 = iVar7 + 1;
          iVar6 = *param_1;
          fVar2 = *(float *)(iVar6 + 8) - *pfVar1;
          fVar3 = *(float *)(iVar6 + 0xc) - pfVar1[1];
          local_50 = *(float *)(iVar6 + 0x10) - pfVar1[2];
          fVar2 = SQRT(local_50 * local_50 + fVar3 * fVar3 + fVar2 * fVar2);
          if ((param_4 <= fVar2) &&
             ((byte)(fVar2 < param_5 |
                     (byte)((ushort)((ushort)(NAN(fVar2) || NAN(param_5)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar2 == param_5) << 0xe) >> 8)) == 1)) {
            local_5c = *pfVar1 + *param_3;
            local_58 = pfVar1[1] + param_3[1];
            local_54 = pfVar1[2] + param_3[2];
            UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
                      (&local_5c,&local_10,1,1,*(undefined4 *)(iVar6 + 0x1e8),local_48);
            if ((byte)(1.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
                      (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) != 0x40) {
              if (iVar4 != local_68) {
                lVar9 = (longdouble)
                        PathLength__6CGraphiiii(&WorldGraph,iVar4,iVar7,uVar5,param_1[0x172]);
                lVar10 = (longdouble)
                         PathLength__6CGraphiiii(&WorldGraph,local_68,iVar7,uVar5,param_1[0x172]);
                if (lVar10 < (longdouble)(float)lVar9) goto LAB_000c4a0d;
              }
              iVar6 = (**(code **)(param_1[0xf2] + 0x1ac))(param_1,pfVar1);
              if ((iVar6 != 0) &&
                 (iVar6 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector(param_1,4,0,pfVar1),
                 iVar6 != 0)) {
                return 1;
              }
            }
          }
LAB_000c4a0d:
          iVar8 = iVar8 + 1;
        } while (iVar8 < DAT_001758d8);
      }
    }
  }
  return 0;
}


