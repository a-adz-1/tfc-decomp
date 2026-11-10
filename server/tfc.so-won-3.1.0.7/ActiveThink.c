// ActiveThink__11CBaseTurret  @ 00116f44
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
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
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
  pfStack_a0 = (float *)0x116f90;
  StudioFrameAdvance__14CBaseAnimatingf();
  ppfVar6 = (float **)&stack0xffffff6c;
  if (param_1[0x1ad] != 0.0) {
    pfStack_98 = param_1 + 0x13b;
    pfStack_9c = (float *)0x116fae;
    iVar4 = __opP11CBaseEntity__7EHANDLE();
    ppfVar6 = (float **)&stack0xffffff6c;
    if (iVar4 != 0) {
      pfStack_9c = (float *)0x116fc5;
      pfStack_98 = param_1 + 0x13b;
      pfStack_9c = (float *)__rf__7EHANDLE();
      pfStack_a0 = (float *)0x116fd6;
      iVar4 = (**(code **)((int)pfStack_9c[0x111] + 0x8c))();
      if (iVar4 == 0) {
        fVar1 = param_1[0x1b3];
        if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
          local_10 = *gpGlobals + 0.5;
          param_1[0x1b3] = local_10;
        }
        else {
          fVar1 = *gpGlobals;
          fVar2 = param_1[0x1b3];
          if (0x3f < (byte)((fVar1 < fVar2 |
                             (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
            pfStack_98 = (float *)0x0;
            ppfVar7 = &pfStack_9c;
            pfStack_9c = param_1 + 0x13b;
            goto LAB_001171bb;
          }
        }
      }
      fVar1 = *param_1;
      local_1c = *(float *)((int)fVar1 + 8) + *(float *)((int)fVar1 + 0x174);
      local_18 = *(float *)((int)fVar1 + 0xc) + *(float *)((int)fVar1 + 0x178);
      local_14 = *(float *)((int)fVar1 + 0x10) + *(float *)((int)fVar1 + 0x17c);
      pfStack_9c = (float *)0x117082;
      pfStack_98 = param_1 + 0x13b;
      pfStack_a0 = (float *)__rf__7EHANDLE();
      pfStack_9c = &local_1c;
      (**(code **)((int)pfStack_a0[0x111] + 0xd8))(&local_28);
      puVar5 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x13b,&local_28,0);
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
        fVar1 = param_1[0x1b3];
        if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
          local_18 = *gpGlobals + 0.5;
          param_1[0x1b3] = local_18;
        }
        else {
          fVar1 = *gpGlobals;
          fVar2 = param_1[0x1b3];
          if (0x3f < (byte)((fVar1 < fVar2 |
                             (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1))
          goto LAB_001171b2;
        }
        local_80 = 0.0;
      }
      else {
        param_1[0x1b0] = local_30;
        param_1[0x1b1] = local_2c;
        param_1[0x1b2] = local_28;
      }
      pfStack_a0 = param_1 + 0x1b7;
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
      if ((param_1[0x1a4] == 0.0) ||
         (((byte)(0.866 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.866) << 0xe) >> 8)) != 1 &&
          (param_1[0x1ae] == 0.0)))) {
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
          (**(code **)((int)param_1[0x111] + 0x230))(param_1,&local_58);
          ppfVar8 = &pfStack_9c;
        }
        else {
          pfStack_a0 = param_1 + 0x13b;
          iVar4 = __rf__7EHANDLE();
          pcVar3 = *(code **)(*(int *)(iVar4 + 0x444) + 0xcc);
          (*pcVar3)(&local_7c,iVar4);
          local_74 = local_80 - local_5c;
          local_70 = local_7c - local_58;
          local_6c = local_78 - local_54;
          local_68 = local_74;
          local_64 = local_70;
          local_60 = local_6c;
          UTIL_MakeVectors__FRC6Vector(&local_64);
          (**(code **)((int)param_1[0x111] + 0x230))(param_1,pcVar3,&local_64);
          ppfVar8 = &pfStack_a0;
        }
      }
      if (param_1[0x1ae] != 0.0) {
        *(undefined4 *)((int)ppfVar8 + -4) = 9;
        *(undefined4 *)((int)ppfVar8 + -8) = 0;
        *(undefined4 *)((int)ppfVar8 + -0xc) = 0x117492;
        iVar4 = (*DAT_001c1188)();
        if (iVar4 == 0) {
          *(undefined4 *)((int)ppfVar8 + -4) = 0x43b40000;
          *(undefined4 *)((int)ppfVar8 + -8) = 0;
          *(undefined4 *)((int)ppfVar8 + -0xc) = 0x1174b2;
          lVar9 = (longdouble)(*DAT_001c118c)();
          param_1[0x1bb] = (float)lVar9;
          *(undefined4 *)((int)ppfVar8 + -0xc) = 0x42b40000;
          *(undefined4 *)((int)ppfVar8 + -0x10) = 0;
          *(undefined4 *)((int)ppfVar8 + -0x14) = 0x1174cd;
          lVar9 = (longdouble)(*DAT_001c118c)();
          *(int *)((int)ppfVar8 + -0x14) = (int)param_1[0x1ac] * 0x5a;
          param_1[0x1ba] = (float)(lVar9 - (longdouble)*(int *)((int)ppfVar8 + -0x14));
          fVar1 = param_1[0x111];
          *(undefined4 *)((int)ppfVar8 + -0x14) = 0;
          *(undefined4 *)((int)ppfVar8 + -0x18) = 0x3f800000;
          fVar2 = *param_1;
          *(float *)((int)ppfVar8 + -0x1c) = fVar2;
          *(float *)((int)ppfVar8 + -0x20) = fVar2;
          *(float **)((int)ppfVar8 + -0x24) = param_1;
          pcVar3 = *(code **)((int)fVar1 + 0x38);
          *(undefined4 *)((int)ppfVar8 + -0x28) = 0x117504;
          (*pcVar3)();
          return;
        }
        goto LAB_0011761d;
      }
      if (*(int *)((int)ppfVar8 + 0x1c) == 0) goto LAB_0011761d;
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
      if (param_1[0x1ac] == 0.0) {
        fVar1 = 90.0;
        fVar2 = *(float *)((int)ppfVar8 + 0x60);
        if ((byte)(90.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 90.0) << 0xe) >> 8)) == 1) goto LAB_00117601;
        fVar1 = (float)(int)param_1[0x1a9];
        fVar2 = *(float *)((int)ppfVar8 + 0x60);
        if (0x3f < (byte)((fVar1 < fVar2 |
                           (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1))
        goto LAB_00117601;
      }
      else {
        fVar1 = -90.0;
        if (-90.0 <= *(float *)((int)ppfVar8 + 0x60)) {
          *(int *)((int)ppfVar8 + -4) = -(int)param_1[0x1a9];
          fVar1 = (float)*(int *)((int)ppfVar8 + -4);
          if (*(float *)((int)ppfVar8 + 0x60) <= fVar1) goto LAB_00117609;
        }
LAB_00117601:
        *(float *)((int)ppfVar8 + 0x60) = fVar1;
      }
LAB_00117609:
      param_1[0x1bb] = *(float *)((int)ppfVar8 + 100);
      param_1[0x1ba] = *(float *)((int)ppfVar8 + 0x60);
LAB_0011761d:
      fVar1 = param_1[0x111];
      *(float **)((int)ppfVar8 + -4) = param_1;
      pcVar3 = *(code **)((int)fVar1 + 0x220);
      *(undefined4 *)((int)ppfVar8 + -8) = 0x11762c;
      (*pcVar3)();
      *(float **)((int)ppfVar8 + -8) = param_1;
      *(undefined4 *)((int)ppfVar8 + -0xc) = 0x117632;
      MoveTurret__11CBaseTurret();
      return;
    }
  }
LAB_001171b2:
  *(undefined4 *)((int)ppfVar6 + -4) = 0;
  ppfVar7 = (float **)((int)ppfVar6 + -8);
  *(float **)((int)ppfVar6 + -8) = param_1 + 0x13b;
LAB_001171bb:
  *(undefined4 *)((int)ppfVar7 + -4) = 0x1171c0;
  __as__7EHANDLEP11CBaseEntity();
  param_1[0x1b3] = *gpGlobals + param_1[0x1b4];
  param_1[3] = -NAN;
  param_1[4] = (float)SearchThink__11CBaseTurret;
  return;
}


