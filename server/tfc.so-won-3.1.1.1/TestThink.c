// TestThink__11CTestEffect  @ 000a2310
void TestThink__11CTestEffect(int *param_1)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  longdouble lVar9;
  longdouble lVar10;
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
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  fVar1 = *gpGlobals - (float)param_1[0x14a];
  iVar4 = param_1[0x119];
  if (iVar4 < 0x18) {
    piVar3 = (int *)GetClassPtr__H1Z5CBeam_PX01_PX01(0);
    *(int *)*piVar3 = (int)&DAT_0014a798 - (int)gpGlobals[0x26];
    BeamInit__5CBeamPCci(piVar3,"sprites/lgtning.spr",100);
    iVar4 = *param_1;
    local_48 = *(float *)(iVar4 + 8);
    local_44 = *(float *)(iVar4 + 0xc);
    local_40 = *(float *)(iVar4 + 0x10);
    lVar6 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
    lVar7 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
    lVar8 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
    lVar9 = (longdouble)(float)lVar6;
    lVar10 = (longdouble)(float)SQRT(lVar8 * lVar8 + lVar7 * lVar7 + lVar9 * lVar9);
    lVar9 = (longdouble)0;
    if ((byte)((byte)((ushort)((ushort)(NAN(lVar9) || NAN(lVar10)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar9 == lVar10) << 0xe) >> 8)) == 0x40) {
      local_58 = 1.0;
      lVar7 = lVar9;
    }
    else {
      lVar10 = (longdouble)1 / lVar10;
      lVar9 = (longdouble)(float)lVar6 * lVar10;
      lVar7 = lVar7 * lVar10;
      local_58 = (float)(lVar8 * lVar10);
    }
    local_5c = (float)lVar7;
    local_60 = (float)lVar9;
    local_54 = local_60;
    local_64 = local_60 * 128.0 + local_48;
    local_50 = local_5c;
    local_60 = local_5c * 128.0 + local_44;
    local_4c = local_58;
    local_5c = local_58 * 128.0 + local_40;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_48,&local_64,1,*(undefined4 *)(*param_1 + 0x208),local_3c);
    *(uint *)(*piVar3 + 0x148) = *(uint *)(*piVar3 + 0x148) & 0xf0;
    iVar4 = *piVar3;
    *(float *)(iVar4 + 8) = local_48;
    *(float *)(iVar4 + 0xc) = local_44;
    *(float *)(iVar4 + 0x10) = local_40;
    iVar4 = *piVar3;
    *(undefined4 *)(iVar4 + 0x50) = local_28;
    *(undefined4 *)(iVar4 + 0x54) = local_24;
    *(undefined4 *)(iVar4 + 0x58) = local_20;
    *(uint *)(*piVar3 + 0x128) = *(uint *)(*piVar3 + 0x128) & 0xfff;
    *(uint *)(*piVar3 + 0x110) = *(uint *)(*piVar3 + 0x110) & 0xfff;
    RelinkBeam__5CBeam(piVar3);
    *(undefined4 *)(*piVar3 + 0x150) = 0x437f0000;
    *(undefined4 *)(*piVar3 + 0x154) = 0x43340000;
    *(undefined4 *)(*piVar3 + 0x158) = 0x42c80000;
    *(undefined4 *)(*piVar3 + 0x144) = 0x42c80000;
    *(undefined4 *)(*piVar3 + 0x134) = 0x41400000;
    param_1[param_1[0x119] + 0x132] = (int)*gpGlobals;
    param_1[param_1[0x119] + 0x11a] = (int)piVar3;
    iVar4 = param_1[0x119];
    param_1[0x119] = iVar4 + 1;
    iVar4 = iVar4 + 1;
  }
  if ((byte)((3.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 3.0) << 0xe) >> 8)) - 1) < 0x40) {
    iVar5 = 0;
    if (0 < iVar4) {
      do {
        UTIL_Remove__FP11CBaseEntity(param_1[iVar5 + 0x11a]);
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_1[0x119]);
    }
    fVar1 = *gpGlobals;
    param_1[0x119] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[0x14a] = (int)fVar1;
  }
  else {
    iVar5 = 0;
    if (0 < iVar4) {
      do {
        iVar4 = iVar5 + 0x132;
        iVar2 = iVar5 + 0x11a;
        iVar5 = iVar5 + 1;
        *(float *)(*(int *)param_1[iVar2] + 0x14c) =
             (float)(int)ROUND(((*gpGlobals - (float)param_1[iVar4]) /
                               (((float)param_1[0x14a] + 3.0) - (float)param_1[iVar4])) * 255.0);
      } while (iVar5 < param_1[0x119]);
    }
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


