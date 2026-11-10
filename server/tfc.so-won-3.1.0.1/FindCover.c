// FindCover__12CBaseMonsterG6VectorT1ff  @ 000b2acc
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
  int local_64;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  undefined1 auStack_44 [16];
  float fStack_34;
  float local_c;
  float local_8;
  float local_4;
  
  if ((byte)((byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_5 == 0.0) << 0xe) >> 8)) == 0x40) {
    param_5 = 784.0;
  }
  if (param_5 * 0.5 < param_4) {
    param_4 = param_5 * 0.5;
  }
  if ((WorldGraph == 0) || (DAT_001a82a4 == 0)) {
    (*DAT_001a7f34)(2,"Graph not ready for findcover!\n");
  }
  else {
    iVar4 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity(&WorldGraph,*param_1 + 8,param_1);
    local_64 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity(&WorldGraph,param_2,param_1);
    uVar5 = HullIndex__6CGraphPC11CBaseEntity(&WorldGraph,param_1);
    if (iVar4 == -1) {
      (*DAT_001a7f34)(2,"FindCover() - %s has no nearest node!\n",
                      *(int *)*param_1 + *(int *)(gpGlobals + 0x98));
    }
    else {
      if (local_64 == -1) {
        local_64 = iVar4;
      }
      local_c = *param_2 + *param_3;
      local_8 = param_2[1] + param_3[1];
      local_4 = param_2[2] + param_3[2];
      iVar8 = 0;
      if (0 < DAT_001a82b8) {
        do {
          iVar7 = (iVar8 + DAT_001aa368) % DAT_001a82b8;
          pfVar1 = (float *)(DAT_001a82ac + iVar7 * 0x58);
          DAT_001aa368 = iVar7 + 1;
          iVar6 = *param_1;
          fVar2 = *(float *)(iVar6 + 8) - *pfVar1;
          fVar3 = *(float *)(iVar6 + 0xc) - pfVar1[1];
          local_4c = *(float *)(iVar6 + 0x10) - pfVar1[2];
          fVar2 = SQRT(local_4c * local_4c + fVar3 * fVar3 + fVar2 * fVar2);
          if (((byte)(fVar2 < param_4 |
                      (byte)((ushort)((ushort)(NAN(fVar2) || NAN(param_4)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == param_4) << 0xe) >> 8)) != 1) &&
             (fVar2 < param_5)) {
            local_58 = *pfVar1 + *param_3;
            local_54 = pfVar1[1] + param_3[1];
            local_50 = pfVar1[2] + param_3[2];
            UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERS12IGNORE_GLASSP7edict_sP11TraceResult
                      (&local_58,&local_c,1,1,*(undefined4 *)(iVar6 + 0x208),auStack_44);
            if ((byte)(1.0 < fStack_34 | (byte)((ushort)((ushort)NAN(fStack_34) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fStack_34 == 1.0) << 0xe) >> 8)) != 0x40) {
              if (iVar4 != local_64) {
                lVar9 = (longdouble)
                        PathLength__6CGraphiiii(&WorldGraph,iVar4,iVar7,uVar5,param_1[0x175]);
                lVar10 = (longdouble)
                         PathLength__6CGraphiiii(&WorldGraph,local_64,iVar7,uVar5,param_1[0x175]);
                lVar9 = (longdouble)(float)lVar9;
                if ((byte)(lVar10 < lVar9 |
                           (byte)((ushort)((ushort)(NAN(lVar10) || NAN(lVar9)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(lVar10 == lVar9) << 0xe) >> 8)) == 1)
                goto LAB_000b2e66;
              }
              iVar6 = (**(code **)(param_1[0xf5] + 0x1ac))(param_1,pfVar1);
              if ((iVar6 != 0) &&
                 (iVar6 = MoveToLocation__12CBaseMonster8ActivityfRC6Vector(param_1,4,0,pfVar1),
                 iVar6 != 0)) {
                return 1;
              }
            }
          }
LAB_000b2e66:
          iVar8 = iVar8 + 1;
        } while (iVar8 < DAT_001a82b8);
      }
    }
  }
  return 0;
}


