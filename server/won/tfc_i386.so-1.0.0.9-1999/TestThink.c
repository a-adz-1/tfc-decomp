// TestThink__11CTestEffect  @ 000aeeb0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TestThink__11CTestEffect(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int *piVar5;
  int iVar6;
  longdouble lVar7;
  longdouble lVar8;
  longdouble lVar9;
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
  undefined1 local_3c [20];
  undefined1 local_28 [36];
  
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0x127];
  if (param_1[0xf6] < 0x18) {
    piVar5 = (int *)BeamCreate__5CBeamPCci("sprites/lgtning.spr",100);
    local_48 = *(float *)(*param_1 + 8);
    local_44 = *(float *)(*param_1 + 0xc);
    local_40 = *(float *)(*param_1 + 0x10);
    lVar7 = (longdouble)(*DAT_0017562c)(0xbf800000,0x3f800000);
    fVar3 = (float)lVar7;
    lVar7 = (longdouble)(*DAT_0017562c)(0xbf800000,0x3f800000);
    lVar8 = (longdouble)(*DAT_0017562c)(0xbf800000,0x3f800000);
    lVar9 = (longdouble)(float)lVar7;
    local_58 = (float)SQRT(lVar8 * lVar8 + lVar9 * lVar9 + (longdouble)fVar3 * (longdouble)fVar3);
    if ((byte)((byte)((ushort)((ushort)NAN(local_58) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_58 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_60 = 0.0;
      local_5c = 0.0;
      local_58 = 1.0;
    }
    else {
      local_58 = 1.0 / local_58;
      local_60 = local_58 * fVar3;
      local_5c = local_58 * (float)lVar7;
      local_58 = local_58 * (float)lVar8;
    }
    local_54 = local_60;
    local_50 = local_5c;
    local_4c = local_58;
    local_64 = local_48 + local_60 * 128.0;
    local_60 = local_44 + local_5c * 128.0;
    local_5c = local_40 + local_58 * 128.0;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_48,&local_64,1,*(undefined4 *)(*param_1 + 0x1e8),local_3c);
    PointsInit__5CBeamRC6VectorT1(piVar5,&local_48,local_28);
    *(undefined4 *)(*piVar5 + 0x130) = 0x437f0000;
    *(undefined4 *)(*piVar5 + 0x134) = 0x43340000;
    *(undefined4 *)(*piVar5 + 0x138) = 0x42c80000;
    *(undefined4 *)(*piVar5 + 0x124) = 0x42c80000;
    *(undefined4 *)(*piVar5 + 0x114) = 0x41400000;
    param_1[param_1[0xf6] + 0x10f] = (int)*gpGlobals;
    param_1[param_1[0xf6] + 0xf7] = (int)piVar5;
    param_1[0xf6] = param_1[0xf6] + 1;
  }
  pfVar4 = gpGlobals;
  fVar3 = _FUN_0012ee50;
  if (3.0 <= fVar1 - fVar2) {
    iVar6 = 0;
    if (0 < param_1[0xf6]) {
      do {
        UTIL_Remove__FP11CBaseEntity(param_1[iVar6 + 0xf7]);
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_1[0xf6]);
    }
    param_1[0x127] = (int)*gpGlobals;
    param_1[0xf6] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
  }
  else {
    iVar6 = 0;
    if (0 < param_1[0xf6]) {
      do {
        *(float *)(*(int *)param_1[iVar6 + 0xf7] + 300) =
             (float)(int)ROUND(((*pfVar4 - (float)param_1[iVar6 + 0x10f]) /
                               (((float)param_1[0x127] + fVar3) - (float)param_1[iVar6 + 0x10f])) *
                               255.0);
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_1[0xf6]);
    }
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  }
  return;
}


