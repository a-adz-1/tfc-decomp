// ActiveThink__11CBaseTurret  @ 0011ab68
void ActiveThink__11CBaseTurret(float *param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  code *pcVar4;
  float fVar5;
  int iVar6;
  undefined4 *puVar7;
  float **ppfVar8;
  float **ppfVar9;
  longdouble lVar10;
  float *pfStack_b8;
  float *pfStack_b4;
  float *pfStack_b0;
  int iStack_80;
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
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  fStack_14 = *gpGlobals + 0.1;
  *(float *)((int)*param_1 + 0x104) = fStack_14;
  pfStack_b0 = (float *)0x0;
  pfStack_b4 = param_1;
  pfStack_b8 = (float *)0x11aba9;
  StudioFrameAdvance__14CBaseAnimatingf();
  if (param_1[0x1b1] == 0.0) {
LAB_0011abd5:
    pfStack_b0 = (float *)0x0;
    pfStack_b4 = param_1 + 0x13f;
    pfStack_b8 = (float *)0x11abe3;
    __as__7EHANDLEP11CBaseEntity();
    param_1[0x1b7] = *gpGlobals + param_1[0x1b8];
    param_1[3] = -NAN;
    param_1[4] = (float)SearchThink__11CBaseTurret;
    return;
  }
  pfVar1 = param_1 + 0x13f;
  pfStack_b4 = (float *)0x11abcc;
  pfStack_b0 = pfVar1;
  iVar6 = __opP11CBaseEntity__7EHANDLE();
  if (iVar6 == 0) goto LAB_0011abd5;
  ppfVar8 = &pfStack_b0;
  pfStack_b4 = (float *)0x11ac1d;
  pfStack_b0 = pfVar1;
  pfStack_b4 = (float *)__rf__7EHANDLE();
  pfStack_b8 = (float *)0x11ac2e;
  iVar6 = (**(code **)((int)pfStack_b4[0x115] + 0x8c))();
  if (iVar6 == 0) {
    fVar2 = param_1[0x1b7];
    if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
      fStack_14 = *gpGlobals + 0.5;
      param_1[0x1b7] = fStack_14;
    }
    else if (fVar2 < *gpGlobals) {
      pfStack_b0 = (float *)0x0;
      goto LAB_0011ada4;
    }
  }
  fVar2 = *param_1;
  fStack_20 = *(float *)((int)fVar2 + 8) + *(float *)((int)fVar2 + 0x174);
  fStack_1c = *(float *)((int)*param_1 + 0xc) + *(float *)((int)fVar2 + 0x178);
  fStack_18 = *(float *)((int)*param_1 + 0x10) + *(float *)((int)fVar2 + 0x17c);
  pfStack_b4 = (float *)0x11acba;
  pfStack_b0 = pfVar1;
  pfStack_b8 = (float *)__rf__7EHANDLE();
  pfStack_b4 = &fStack_20;
  (**(code **)((int)pfStack_b8[0x115] + 0xd8))(&fStack_2c);
  puVar7 = (undefined4 *)__rf__7EHANDLE(pfVar1,&fStack_2c,0);
  iStack_80 = FBoxVisible__FP9entvars_sT0R6Vectorf(*param_1,*puVar7);
  fStack_44 = fStack_2c - fStack_20;
  fStack_40 = fStack_28 - fStack_1c;
  fStack_3c = fStack_24 - fStack_18;
  fVar2 = fStack_44 * fStack_44;
  fVar5 = fStack_40 * fStack_40;
  fVar3 = fStack_3c * fStack_3c;
  pfStack_b4 = &fStack_44;
  pfStack_b8 = &fStack_38;
  fStack_38 = fStack_44;
  fStack_34 = fStack_40;
  fStack_30 = fStack_3c;
  fStack_10 = fStack_44;
  fStack_c = fStack_40;
  fStack_8 = fStack_3c;
  UTIL_VecToAngles__FRC6Vector();
  if ((iStack_80 == 0) || (1200.0 < SQRT(fVar3 + fVar5 + fVar2))) {
    fVar2 = param_1[0x1b7];
    if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
      fStack_14 = *gpGlobals + 0.5;
      param_1[0x1b7] = fStack_14;
    }
    else if (fVar2 < *gpGlobals) {
      ppfVar8 = &pfStack_b8;
      pfStack_b8 = (float *)0x0;
LAB_0011ada4:
      *(float **)((int)ppfVar8 + -4) = pfVar1;
      *(undefined4 *)((int)ppfVar8 + -8) = 0x11adaa;
      __as__7EHANDLEP11CBaseEntity();
      param_1[0x1b7] = *gpGlobals + param_1[0x1b8];
      param_1[3] = -NAN;
      param_1[4] = (float)SearchThink__11CBaseTurret;
      return;
    }
    iStack_80 = 0;
  }
  else {
    param_1[0x1b4] = fStack_2c;
    param_1[0x1b5] = fStack_28;
    param_1[0x1b6] = fStack_24;
  }
  pfStack_b8 = param_1 + 0x1bb;
  UTIL_MakeAimVectors__FRC6Vector();
  fStack_54 = SQRT(fStack_8 * fStack_8 + fStack_c * fStack_c + fStack_10 * fStack_10);
  if ((byte)((byte)((ushort)((ushort)NAN(fStack_54) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_54 == 0.0) << 0xe) >> 8)) == 0x40) {
    fStack_50 = 0.0;
    fStack_4c = 0.0;
    fStack_48 = 1.0;
  }
  else {
    fStack_48 = 1.0 / fStack_54;
    fStack_50 = fStack_10 * fStack_48;
    fStack_4c = fStack_c * fStack_48;
    fStack_48 = fStack_48 * fStack_8;
  }
  fStack_44 = fStack_50;
  fStack_40 = fStack_4c;
  fStack_3c = fStack_48;
  fVar2 = fStack_48 * gpGlobals[0xc] + fStack_4c * gpGlobals[0xb] + fStack_50 * gpGlobals[10];
  if ((param_1[0x1a8] == 0.0) ||
     (((byte)(0.866 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 0.866) << 0xe) >> 8)) != 1 && (param_1[0x1b2] == 0.0)
      ))) {
    pfStack_b8 = (float *)0x2;
    SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1);
    ppfVar9 = &pfStack_b4;
  }
  else {
    pfStack_b8 = &fStack_60;
    GetAttachment__14CBaseAnimatingiR6VectorT2(param_1,0,&fStack_54);
    SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,1);
    fVar2 = gpGlobals[5];
    if ((byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
      pfStack_b8 = gpGlobals + 10;
      (**(code **)((int)param_1[0x115] + 0x230))(param_1,&fStack_54);
      ppfVar9 = &pfStack_b4;
    }
    else {
      pfStack_b8 = pfVar1;
      iVar6 = __rf__7EHANDLE();
      (**(code **)(*(int *)(iVar6 + 0x454) + 0xcc))(&fStack_78,iVar6);
      fStack_6c = fStack_78 - fStack_54;
      fStack_68 = fStack_74 - fStack_50;
      fStack_64 = fStack_70 - fStack_4c;
      fStack_60 = fStack_6c;
      fStack_5c = fStack_68;
      fStack_58 = fStack_64;
      UTIL_MakeVectors__FRC6Vector(&fStack_60);
      (**(code **)((int)param_1[0x115] + 0x230))(param_1,&fStack_54,&fStack_60);
      ppfVar9 = &pfStack_b8;
    }
  }
  if (param_1[0x1b2] != 0.0) {
    *(undefined4 *)((int)ppfVar9 + -4) = 9;
    *(undefined4 *)((int)ppfVar9 + -8) = 0;
    *(undefined4 *)((int)ppfVar9 + -0xc) = 0x11b03e;
    iVar6 = (*DAT_0019f808)();
    if (iVar6 == 0) {
      *(undefined4 *)((int)ppfVar9 + -4) = 0x43b40000;
      *(undefined4 *)((int)ppfVar9 + -8) = 0;
      *(undefined4 *)((int)ppfVar9 + -0xc) = 0x11b05e;
      lVar10 = (longdouble)(*DAT_0019f80c)();
      param_1[0x1bf] = (float)lVar10;
      *(undefined4 *)((int)ppfVar9 + -0xc) = 0x42b40000;
      *(undefined4 *)((int)ppfVar9 + -0x10) = 0;
      *(undefined4 *)((int)ppfVar9 + -0x14) = 0x11b079;
      lVar10 = (longdouble)(*DAT_0019f80c)();
      *(int *)((int)ppfVar9 + -0x14) = (int)param_1[0x1b0] * 0x5a;
      fVar2 = param_1[0x115];
      param_1[0x1be] = (float)(lVar10 - (longdouble)*(int *)((int)ppfVar9 + -0x14));
      *(undefined4 *)((int)ppfVar9 + -0x14) = 0;
      *(undefined4 *)((int)ppfVar9 + -0x18) = 0x3f800000;
      fVar3 = *param_1;
      *(float *)((int)ppfVar9 + -0x1c) = fVar3;
      *(float *)((int)ppfVar9 + -0x20) = fVar3;
      *(float **)((int)ppfVar9 + -0x24) = param_1;
      pcVar4 = *(code **)((int)fVar2 + 0x38);
      *(undefined4 *)((int)ppfVar9 + -0x28) = 0x11b0af;
      (*pcVar4)();
      return;
    }
    goto LAB_0011b1a8;
  }
  if (iStack_80 == 0) goto LAB_0011b1a8;
  if (360.0 < fStack_34) {
    fStack_34 = fStack_34 - 360.0;
  }
  if (0x3f < (byte)((0.0 < fStack_34 | (byte)((ushort)((ushort)NAN(fStack_34) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fStack_34 == 0.0) << 0xe) >> 8)) - 1)) {
    fStack_34 = fStack_34 + 360.0;
  }
  if (0x3f < (byte)((-180.0 < fStack_38 | (byte)((ushort)((ushort)NAN(fStack_38) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fStack_38 == -180.0) << 0xe) >> 8)) - 1)) {
    fStack_38 = fStack_38 + 360.0;
  }
  if (180.0 < fStack_38) {
    fStack_38 = fStack_38 - 360.0;
  }
  if (param_1[0x1b0] == 0.0) {
    fVar2 = 90.0;
    if (((byte)(90.0 < fStack_38 | (byte)((ushort)((ushort)NAN(fStack_38) << 10) >> 8) |
               (byte)((ushort)((ushort)(fStack_38 == 90.0) << 0xe) >> 8)) != 1) &&
       (fVar2 = (float)(int)param_1[0x1ad],
       (byte)((fVar2 < fStack_38 |
               (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fStack_38)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fStack_38) << 0xe) >> 8)) - 1) < 0x40)) {
LAB_0011b194:
      fVar2 = fStack_38;
    }
  }
  else {
    fVar2 = -90.0;
    if (-90.0 <= fStack_38) {
      *(int *)((int)ppfVar9 + -4) = -(int)param_1[0x1ad];
      fVar2 = (float)*(int *)((int)ppfVar9 + -4);
      if (fStack_38 <= (float)*(int *)((int)ppfVar9 + -4)) goto LAB_0011b194;
    }
  }
  fStack_38 = fVar2;
  param_1[0x1bf] = fStack_34;
  param_1[0x1be] = fStack_38;
LAB_0011b1a8:
  fVar2 = param_1[0x115];
  *(float **)((int)ppfVar9 + -4) = param_1;
  pcVar4 = *(code **)((int)fVar2 + 0x220);
  *(undefined4 *)((int)ppfVar9 + -8) = 0x11b1b7;
  (*pcVar4)();
  *(float **)((int)ppfVar9 + -8) = param_1;
  *(undefined4 *)((int)ppfVar9 + -0xc) = 0x11b1bd;
  MoveTurret__11CBaseTurret();
  return;
}


