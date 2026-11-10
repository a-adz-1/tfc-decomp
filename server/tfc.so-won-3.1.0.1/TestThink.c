// TestThink__11CTestEffect  @ 00099d68
void TestThink__11CTestEffect(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  longdouble lVar6;
  float *pfStack_90;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  undefined1 auStack_38 [20];
  undefined1 auStack_24 [36];
  
  fVar3 = *gpGlobals - (float)param_1[0x12a];
  if (param_1[0xf9] < 0x18) {
    piVar4 = (int *)BeamCreate__5CBeamPCci("sprites/lgtning.spr",100);
    fStack_44 = *(float *)(*param_1 + 8);
    fStack_40 = *(float *)(*param_1 + 0xc);
    fStack_3c = *(float *)(*param_1 + 0x10);
    lVar6 = (longdouble)(*DAT_001a7fac)(0xbf800000,0x3f800000);
    fVar1 = (float)lVar6;
    lVar6 = (longdouble)(*DAT_001a7fac)(0xbf800000,0x3f800000);
    fVar2 = (float)lVar6;
    lVar6 = (longdouble)(*DAT_001a7fac)(0xbf800000,0x3f800000);
    fStack_54 = (float)SQRT(lVar6 * lVar6 +
                            (longdouble)(fVar1 * fVar1) + (longdouble)(fVar2 * fVar2));
    if ((byte)((byte)((ushort)((ushort)NAN(fStack_54) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_54 == 0.0) << 0xe) >> 8)) == 0x40) {
      fStack_5c = 0.0;
      fStack_58 = 0.0;
      fStack_54 = 1.0;
    }
    else {
      fStack_54 = 1.0 / fStack_54;
      fStack_5c = fStack_54 * fVar1;
      fStack_58 = fStack_54 * fVar2;
      fStack_54 = fStack_54 * (float)lVar6;
    }
    fStack_50 = fStack_5c;
    fStack_4c = fStack_58;
    fStack_48 = fStack_54;
    fStack_60 = fStack_44 + fStack_5c * 128.0;
    fStack_5c = fStack_40 + fStack_58 * 128.0;
    fStack_58 = fStack_3c + fStack_54 * 128.0;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&fStack_44,&fStack_60,1,*(undefined4 *)(*param_1 + 0x208),auStack_38);
    PointsInit__5CBeamRC6VectorT1(piVar4,&fStack_44,auStack_24);
    *(undefined4 *)(*piVar4 + 0x150) = 0x437f0000;
    *(undefined4 *)(*piVar4 + 0x154) = 0x43340000;
    *(undefined4 *)(*piVar4 + 0x158) = 0x42c80000;
    *(undefined4 *)(*piVar4 + 0x144) = 0x42c80000;
    *(undefined4 *)(*piVar4 + 0x134) = 0x41400000;
    param_1[param_1[0xf9] + 0x112] = (int)*gpGlobals;
    param_1[param_1[0xf9] + 0xfa] = (int)piVar4;
    param_1[0xf9] = param_1[0xf9] + 1;
  }
  if ((byte)((3.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar3 == 3.0) << 0xe) >> 8)) - 1) < 0x40) {
    iVar5 = 0;
    if (0 < param_1[0xf9]) {
      do {
        UTIL_Remove__FP11CBaseEntity(param_1[iVar5 + 0xfa]);
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_1[0xf9]);
    }
    param_1[0x12a] = (int)*gpGlobals;
    param_1[0xf9] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
  }
  else {
    if (0 < param_1[0xf9]) {
      pfStack_90 = (float *)(param_1 + 0x112);
      iVar5 = 0;
      do {
        *(float *)(*(int *)param_1[iVar5 + 0xfa] + 0x14c) =
             (float)(int)ROUND(((*gpGlobals - *pfStack_90) /
                               (((float)param_1[0x12a] + 3.0) - *pfStack_90)) * 255.0);
        pfStack_90 = pfStack_90 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_1[0xf9]);
    }
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


