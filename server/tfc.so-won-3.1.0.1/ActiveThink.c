// ActiveThink__11CBaseTurret  @ 00107478
void ActiveThink__11CBaseTurret(float *param_1)

{
  float fVar1;
  float fVar2;
  code *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  float **ppfVar6;
  float **ppfVar7;
  float **ppfVar8;
  longdouble lVar9;
  float *pfStack_a0;
  float *pfStack_9c;
  float *pfStack_98;
  float local_84;
  float local_80;
  float local_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float local_64;
  float fStack_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = *gpGlobals + 0.1;
  *(float *)((int)*param_1 + 0x104) = local_10;
  pfStack_98 = (float *)0x0;
  pfStack_9c = param_1;
  pfStack_a0 = (float *)0x1074c4;
  StudioFrameAdvance__14CBaseAnimatingf();
  ppfVar6 = (float **)&stack0xffffff6c;
  if (param_1[0x191] != 0.0) {
    pfStack_98 = param_1 + 0x11f;
    pfStack_9c = (float *)0x1074e2;
    iVar4 = __opP11CBaseEntity__7EHANDLE();
    ppfVar6 = (float **)&stack0xffffff6c;
    if (iVar4 != 0) {
      pfStack_9c = (float *)0x1074f9;
      pfStack_98 = param_1 + 0x11f;
      pfStack_9c = (float *)__rf__7EHANDLE();
      pfStack_a0 = (float *)0x10750a;
      iVar4 = (**(code **)((int)pfStack_9c[0xf5] + 0x88))();
      if (iVar4 == 0) {
        fVar1 = param_1[0x197];
        if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
          local_10 = *gpGlobals + 0.5;
          param_1[0x197] = local_10;
        }
        else {
          fVar1 = *gpGlobals;
          fVar2 = param_1[0x197];
          if (0x3f < (byte)((fVar1 < fVar2 |
                             (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
            pfStack_98 = (float *)0x0;
            ppfVar7 = &pfStack_9c;
            pfStack_9c = param_1 + 0x11f;
            goto LAB_001076ef;
          }
        }
      }
      fVar1 = *param_1;
      local_1c = *(float *)((int)fVar1 + 8) + *(float *)((int)fVar1 + 0x174);
      local_18 = *(float *)((int)fVar1 + 0xc) + *(float *)((int)fVar1 + 0x178);
      local_14 = *(float *)((int)fVar1 + 0x10) + *(float *)((int)fVar1 + 0x17c);
      pfStack_9c = (float *)0x1075b6;
      pfStack_98 = param_1 + 0x11f;
      pfStack_a0 = (float *)__rf__7EHANDLE();
      pfStack_9c = &local_1c;
      (**(code **)((int)pfStack_a0[0xf5] + 0xd0))(&local_28);
      puVar5 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x11f,&local_28,0);
      local_7c = (float)FBoxVisible__FP9entvars_sT0R6Vectorf(*param_1,*puVar5);
      local_38 = local_2c - local_20;
      local_34 = local_28 - local_1c;
      local_30 = local_24 - local_18;
      local_80 = SQRT(local_30 * local_30 + local_34 * local_34 + local_38 * local_38);
      pfStack_a0 = &local_38;
      local_44 = local_2c - local_20;
      local_40 = local_28 - local_1c;
      local_3c = local_24 - local_18;
      pfStack_9c = &local_44;
      local_10 = local_38;
      local_c = local_34;
      local_8 = local_30;
      UTIL_VecToAngles__FRC6Vector();
      ppfVar6 = &pfStack_9c;
      if ((local_80 == 0.0) || (1200.0 < local_84)) {
        fVar1 = param_1[0x197];
        if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
          local_18 = *gpGlobals + 0.5;
          param_1[0x197] = local_18;
        }
        else {
          fVar1 = *gpGlobals;
          fVar2 = param_1[0x197];
          if (0x3f < (byte)((fVar1 < fVar2 |
                             (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1))
          goto LAB_001076e6;
        }
        local_80 = 0.0;
      }
      else {
        param_1[0x194] = local_30;
        param_1[0x195] = local_2c;
        param_1[0x196] = local_28;
      }
      pfStack_a0 = param_1 + 0x19b;
      UTIL_MakeAimVectors__FRC6Vector();
      local_58 = SQRT(local_c * local_c + local_10 * local_10 + local_14 * local_14);
      if ((byte)((byte)((ushort)((ushort)NAN(local_58) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_58 == 0.0) << 0xe) >> 8)) == 0x40) {
        local_54 = 0.0;
        local_50 = 0.0;
        local_4c = 1.0;
      }
      else {
        local_4c = 1.0 / local_58;
        local_54 = local_4c * local_14;
        local_50 = local_4c * local_10;
        local_4c = local_4c * local_c;
      }
      local_48 = local_54;
      local_44 = local_50;
      local_40 = local_4c;
      fVar1 = local_4c * gpGlobals[0xc] + local_50 * gpGlobals[0xb] + local_54 * gpGlobals[10];
      if ((param_1[0x188] == 0.0) ||
         (((byte)(0.866 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.866) << 0xe) >> 8)) != 1 &&
          (param_1[0x192] == 0.0)))) {
        pfStack_a0 = (float *)0x2;
        SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1);
        ppfVar8 = &pfStack_9c;
      }
      else {
        pfStack_a0 = &local_64;
        GetAttachment__14CBaseAnimatingiR6VectorT2(param_1,0,&local_58);
        SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,1);
        fVar1 = gpGlobals[5];
        if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
          pfStack_a0 = gpGlobals + 10;
          (**(code **)((int)param_1[0xf5] + 0x228))(param_1,&local_58);
          ppfVar8 = &pfStack_9c;
        }
        else {
          pfStack_a0 = param_1 + 0x11f;
          iVar4 = __rf__7EHANDLE();
          pcVar3 = *(code **)(*(int *)(iVar4 + 0x3d4) + 0xc4);
          (*pcVar3)(&local_7c,iVar4);
          fStack_74 = local_80 - local_5c;
          fStack_70 = local_7c - local_58;
          fStack_6c = fStack_78 - local_54;
          fStack_68 = fStack_74;
          local_64 = fStack_70;
          fStack_60 = fStack_6c;
          UTIL_MakeVectors__FRC6Vector(&local_64);
          (**(code **)((int)param_1[0xf5] + 0x228))(param_1,pcVar3,&local_64);
          ppfVar8 = &pfStack_a0;
        }
      }
      if (param_1[0x192] != 0.0) {
        *(undefined4 *)((int)ppfVar8 + -4) = 9;
        *(undefined4 *)((int)ppfVar8 + -8) = 0;
        *(undefined4 *)((int)ppfVar8 + -0xc) = 0x1079c6;
        iVar4 = (*DAT_001a7fa8)();
        if (iVar4 == 0) {
          *(undefined4 *)((int)ppfVar8 + -4) = 0x43b40000;
          *(undefined4 *)((int)ppfVar8 + -8) = 0;
          *(undefined4 *)((int)ppfVar8 + -0xc) = 0x1079e6;
          lVar9 = (longdouble)(*DAT_001a7fac)();
          param_1[0x19f] = (float)lVar9;
          *(undefined4 *)((int)ppfVar8 + -0xc) = 0x42b40000;
          *(undefined4 *)((int)ppfVar8 + -0x10) = 0;
          *(undefined4 *)((int)ppfVar8 + -0x14) = 0x107a01;
          lVar9 = (longdouble)(*DAT_001a7fac)();
          *(int *)((int)ppfVar8 + -0x14) = (int)param_1[400] * 0x5a;
          param_1[0x19e] = (float)(lVar9 - (longdouble)*(int *)((int)ppfVar8 + -0x14));
          fVar1 = param_1[0xf5];
          *(undefined4 *)((int)ppfVar8 + -0x14) = 0;
          *(undefined4 *)((int)ppfVar8 + -0x18) = 0x3f800000;
          fVar2 = *param_1;
          *(float *)((int)ppfVar8 + -0x1c) = fVar2;
          *(float *)((int)ppfVar8 + -0x20) = fVar2;
          *(float **)((int)ppfVar8 + -0x24) = param_1;
          pcVar3 = *(code **)((int)fVar1 + 0x34);
          *(undefined4 *)((int)ppfVar8 + -0x28) = 0x107a38;
          (*pcVar3)();
          return;
        }
        goto LAB_00107b51;
      }
      if (*(int *)((int)ppfVar8 + 0x1c) == 0) goto LAB_00107b51;
      if (360.0 < *(float *)((int)ppfVar8 + 100)) {
        *(float *)((int)ppfVar8 + 100) = *(float *)((int)ppfVar8 + 100) - 360.0;
      }
      fVar1 = *(float *)((int)ppfVar8 + 100);
      if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
        *(float *)((int)ppfVar8 + 100) = *(float *)((int)ppfVar8 + 100) + 360.0;
      }
      fVar1 = *(float *)((int)ppfVar8 + 0x60);
      if (0x3f < (byte)((-180.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == -180.0) << 0xe) >> 8)) - 1)) {
        *(float *)((int)ppfVar8 + 0x60) = *(float *)((int)ppfVar8 + 0x60) + 360.0;
      }
      if (180.0 < *(float *)((int)ppfVar8 + 0x60)) {
        *(float *)((int)ppfVar8 + 0x60) = *(float *)((int)ppfVar8 + 0x60) - 360.0;
      }
      if (param_1[400] == 0.0) {
        fVar1 = 90.0;
        fVar2 = *(float *)((int)ppfVar8 + 0x60);
        if ((byte)(90.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 90.0) << 0xe) >> 8)) == 1) goto LAB_00107b35;
        fVar1 = (float)(int)param_1[0x18d];
        fVar2 = *(float *)((int)ppfVar8 + 0x60);
        if (0x3f < (byte)((fVar1 < fVar2 |
                           (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1))
        goto LAB_00107b35;
      }
      else {
        fVar1 = -90.0;
        if (-90.0 <= *(float *)((int)ppfVar8 + 0x60)) {
          *(int *)((int)ppfVar8 + -4) = -(int)param_1[0x18d];
          fVar1 = (float)*(int *)((int)ppfVar8 + -4);
          if (*(float *)((int)ppfVar8 + 0x60) <= fVar1) goto LAB_00107b3d;
        }
LAB_00107b35:
        *(float *)((int)ppfVar8 + 0x60) = fVar1;
      }
LAB_00107b3d:
      param_1[0x19f] = *(float *)((int)ppfVar8 + 100);
      param_1[0x19e] = *(float *)((int)ppfVar8 + 0x60);
LAB_00107b51:
      fVar1 = param_1[0xf5];
      *(float **)((int)ppfVar8 + -4) = param_1;
      pcVar3 = *(code **)((int)fVar1 + 0x218);
      *(undefined4 *)((int)ppfVar8 + -8) = 0x107b60;
      (*pcVar3)();
      *(float **)((int)ppfVar8 + -8) = param_1;
      *(undefined4 *)((int)ppfVar8 + -0xc) = 0x107b66;
      MoveTurret__11CBaseTurret();
      return;
    }
  }
LAB_001076e6:
  *(undefined4 *)((int)ppfVar6 + -4) = 0;
  ppfVar7 = (float **)((int)ppfVar6 + -8);
  *(float **)((int)ppfVar6 + -8) = param_1 + 0x11f;
LAB_001076ef:
  *(undefined4 *)((int)ppfVar7 + -4) = 0x1076f4;
  __as__7EHANDLEP11CBaseEntity();
  param_1[0x197] = *gpGlobals + param_1[0x198];
  param_1[3] = -NAN;
  param_1[4] = (float)SearchThink__11CBaseTurret;
  return;
}


