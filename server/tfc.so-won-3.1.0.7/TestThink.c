// TestThink__11CTestEffect  @ 000a42e8
void TestThink__11CTestEffect(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  longdouble lVar6;
  float *pfStack_90;
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
  undefined1 local_38 [20];
  undefined1 auStack_24 [36];
  
  fVar3 = *gpGlobals - (float)param_1[0x146];
  if (param_1[0x115] < 0x18) {
    piVar4 = (int *)BeamCreate__5CBeamPCci("sprites/lgtning.spr",100);
    local_44 = *(float *)(*param_1 + 8);
    local_40 = *(float *)(*param_1 + 0xc);
    local_3c = *(float *)(*param_1 + 0x10);
    lVar6 = (longdouble)(*DAT_001c118c)(0xbf800000,0x3f800000);
    fVar1 = (float)lVar6;
    lVar6 = (longdouble)(*DAT_001c118c)(0xbf800000,0x3f800000);
    fVar2 = (float)lVar6;
    lVar6 = (longdouble)(*DAT_001c118c)(0xbf800000,0x3f800000);
    local_54 = (float)SQRT(lVar6 * lVar6 + (longdouble)(fVar1 * fVar1) + (longdouble)(fVar2 * fVar2)
                          );
    if ((byte)((byte)((ushort)((ushort)NAN(local_54) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_54 == 0.0) << 0xe) >> 8)) == 0x40) {
      local_5c = 0.0;
      local_58 = 0.0;
      local_54 = 1.0;
    }
    else {
      local_54 = 1.0 / local_54;
      local_5c = local_54 * fVar1;
      local_58 = local_54 * fVar2;
      local_54 = local_54 * (float)lVar6;
    }
    local_50 = local_5c;
    local_4c = local_58;
    local_48 = local_54;
    local_60 = local_44 + local_5c * 128.0;
    local_5c = local_40 + local_58 * 128.0;
    local_58 = local_3c + local_54 * 128.0;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_44,&local_60,1,*(undefined4 *)(*param_1 + 0x208),local_38);
    PointsInit__5CBeamRC6VectorT1(piVar4,&local_44,auStack_24);
    *(undefined4 *)(*piVar4 + 0x150) = 0x437f0000;
    *(undefined4 *)(*piVar4 + 0x154) = 0x43340000;
    *(undefined4 *)(*piVar4 + 0x158) = 0x42c80000;
    *(undefined4 *)(*piVar4 + 0x144) = 0x42c80000;
    *(undefined4 *)(*piVar4 + 0x134) = 0x41400000;
    param_1[param_1[0x115] + 0x12e] = (int)*gpGlobals;
    param_1[param_1[0x115] + 0x116] = (int)piVar4;
    param_1[0x115] = param_1[0x115] + 1;
  }
  if ((byte)((3.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar3 == 3.0) << 0xe) >> 8)) - 1) < 0x40) {
    iVar5 = 0;
    if (0 < param_1[0x115]) {
      do {
        UTIL_Remove__FP11CBaseEntity(param_1[iVar5 + 0x116]);
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_1[0x115]);
    }
    param_1[0x146] = (int)*gpGlobals;
    param_1[0x115] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
  }
  else {
    if (0 < param_1[0x115]) {
      pfStack_90 = (float *)(param_1 + 0x12e);
      iVar5 = 0;
      do {
        *(float *)(*(int *)param_1[iVar5 + 0x116] + 0x14c) =
             (float)(int)ROUND(((*gpGlobals - *pfStack_90) /
                               (((float)param_1[0x146] + 3.0) - *pfStack_90)) * 255.0);
        pfStack_90 = pfStack_90 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_1[0x115]);
    }
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


