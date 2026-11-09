// ActiveThink__11CBaseTurret  @ 00114370
void ActiveThink__11CBaseTurret(float *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  float **ppfVar6;
  float **ppfVar7;
  longdouble lVar8;
  float *pfStack_a0;
  float *pfStack_9c;
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
  float local_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  local_14 = *gpGlobals + 0.1;
  *(float *)((int)*param_1 + 0xe4) = local_14;
  pfStack_9c = (float *)0x0;
  pfStack_a0 = param_1;
  StudioFrameAdvance__14CBaseAnimatingf();
  ppfVar6 = (float **)&stack0xffffff68;
  if (param_1[0x18e] != 0.0) {
    pfStack_9c = param_1 + 0x11c;
    pfStack_a0 = (float *)FUN_001143c0;
    iVar2 = __opP11CBaseEntity__7EHANDLE();
    ppfVar6 = (float **)&stack0xffffff68;
    if (iVar2 != 0) {
      pfStack_a0 = (float *)0x1143d7;
      pfStack_9c = param_1 + 0x11c;
      pfStack_a0 = (float *)__rf__7EHANDLE();
      iVar2 = (**(code **)((int)pfStack_a0[0xf2] + 0x88))();
      if (iVar2 == 0) {
        fVar1 = param_1[0x194];
        if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
          local_14 = *gpGlobals + 0.5;
          param_1[0x194] = local_14;
        }
        else if (param_1[0x194] < *gpGlobals) {
          pfStack_9c = (float *)0x0;
          ppfVar7 = &pfStack_a0;
          pfStack_a0 = param_1 + 0x11c;
          goto LAB_0011456b;
        }
      }
      fVar1 = *param_1;
      fStack_20 = *(float *)((int)fVar1 + 8) + *(float *)((int)fVar1 + 0x154);
      fStack_1c = *(float *)((int)fVar1 + 0xc) + *(float *)((int)fVar1 + 0x158);
      fStack_18 = *(float *)((int)fVar1 + 0x10) + *(float *)((int)fVar1 + 0x15c);
      pfStack_a0 = (float *)0x114473;
      pfStack_9c = param_1 + 0x11c;
      iVar2 = __rf__7EHANDLE();
      pfStack_a0 = &fStack_20;
      (**(code **)(*(int *)(iVar2 + 0x3c8) + 0xd0))(&fStack_2c,iVar2);
      puVar3 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x11c,&fStack_2c,0);
      iVar2 = FBoxVisible__FP9entvars_tT0R6Vectorf(*param_1,*puVar3);
      fStack_38 = fStack_2c - fStack_20;
      fStack_34 = fStack_28 - fStack_1c;
      fStack_30 = fStack_24 - fStack_18;
      fVar1 = SQRT(fStack_30 * fStack_30 + fStack_34 * fStack_34 + fStack_38 * fStack_38);
      fStack_44 = fStack_2c - fStack_20;
      fStack_40 = fStack_28 - fStack_1c;
      fStack_3c = fStack_24 - fStack_18;
      pfStack_a0 = &fStack_44;
      fStack_10 = fStack_38;
      fStack_c = fStack_34;
      fStack_8 = fStack_30;
      UTIL_VecToAngles__FRC6Vector(&fStack_38);
      ppfVar6 = &pfStack_a0;
      if ((iVar2 == 0) ||
         ((byte)(1200.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 1200.0) << 0xe) >> 8)) == 1)) {
        fVar1 = param_1[0x194];
        if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
          local_14 = *gpGlobals + 0.5;
          param_1[0x194] = local_14;
        }
        else if (param_1[0x194] < *gpGlobals) goto LAB_00114562;
        iVar2 = 0;
      }
      else {
        param_1[0x191] = fStack_2c;
        param_1[0x192] = fStack_28;
        param_1[0x193] = fStack_24;
      }
      UTIL_MakeAimVectors__FRC6Vector(param_1 + 0x198);
      fStack_54 = SQRT(fStack_8 * fStack_8 + fStack_c * fStack_c + fStack_10 * fStack_10);
      if ((byte)((byte)((ushort)((ushort)NAN(fStack_54) << 10) >> 8) |
                (byte)((ushort)((ushort)(fStack_54 == 0.0) << 0xe) >> 8)) == 0x40) {
        fStack_50 = 0.0;
        fStack_4c = 0.0;
        fStack_48 = 1.0;
      }
      else {
        fStack_48 = 1.0 / fStack_54;
        fStack_50 = fStack_48 * fStack_10;
        fStack_4c = fStack_48 * fStack_c;
        fStack_48 = fStack_48 * fStack_8;
      }
      fStack_44 = fStack_50;
      fStack_40 = fStack_4c;
      fStack_3c = fStack_48;
      if ((param_1[0x185] == 0.0) ||
         ((fStack_48 * gpGlobals[0xc] + fStack_4c * gpGlobals[0xb] + fStack_50 * gpGlobals[10] <=
           0.866 && (param_1[399] == 0.0)))) {
        SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,2);
      }
      else {
        GetAttachment__14CBaseAnimatingiR6VectorT2(param_1,0,&fStack_54,&fStack_60);
        SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,1);
        fVar1 = gpGlobals[5];
        if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
          (**(code **)((int)param_1[0xf2] + 0x228))(param_1,&fStack_54,gpGlobals + 10);
        }
        else {
          iVar4 = __rf__7EHANDLE(param_1 + 0x11c);
          if (*(int *)(iVar4 + 0x74) == 0) {
            piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x11c);
            iVar4 = *piVar5;
            fStack_60 = *(float *)(iVar4 + 8) - fStack_54;
            fStack_5c = *(float *)(iVar4 + 0xc) - fStack_50;
            fStack_58 = *(float *)(iVar4 + 0x10) - fStack_4c;
          }
          else {
            piVar5 = (int *)__rf__7EHANDLE(param_1 + 0x11c);
            iVar4 = *piVar5;
            fStack_60 = (*(float *)(iVar4 + 8) + 0.0) - fStack_54;
            fStack_5c = (*(float *)(iVar4 + 0xc) + 0.0) - fStack_50;
            fStack_58 = (*(float *)(iVar4 + 0x10) + -36.0) - fStack_4c;
          }
          UTIL_MakeVectors__FRC6Vector(&fStack_60);
          (**(code **)((int)param_1[0xf2] + 0x228))(param_1,&fStack_54,&fStack_60);
        }
      }
      if (param_1[399] != 0.0) {
        iVar2 = (*DAT_00175628)(0,9);
        if (iVar2 == 0) {
          lVar8 = (longdouble)(*DAT_0017562c)(0,0x43b40000);
          param_1[0x19c] = (float)lVar8;
          lVar8 = (longdouble)(*DAT_0017562c)(0,0x42b40000);
          param_1[0x19b] = (float)(lVar8 - (longdouble)((int)param_1[0x18d] * 0x5a));
          (**(code **)((int)param_1[0xf2] + 0x34))(param_1,*param_1,*param_1,0x3f800000,0);
          return;
        }
        goto LAB_001149a7;
      }
      if (iVar2 == 0) goto LAB_001149a7;
      if ((byte)(360.0 < fStack_34 | (byte)((ushort)((ushort)NAN(fStack_34) << 10) >> 8) |
                (byte)((ushort)((ushort)(fStack_34 == 360.0) << 0xe) >> 8)) == 1) {
        fStack_34 = fStack_34 - 360.0;
      }
      if (fStack_34 < 0.0) {
        fStack_34 = fStack_34 + 360.0;
      }
      if (fStack_38 < -180.0) {
        fStack_38 = fStack_38 + 360.0;
      }
      if ((byte)(180.0 < fStack_38 | (byte)((ushort)((ushort)NAN(fStack_38) << 10) >> 8) |
                (byte)((ushort)((ushort)(fStack_38 == 180.0) << 0xe) >> 8)) == 1) {
        fStack_38 = fStack_38 - 360.0;
      }
      if (param_1[0x18d] == 0.0) {
        fVar1 = 90.0;
        if (((byte)(90.0 < fStack_38 | (byte)((ushort)((ushort)NAN(fStack_38) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fStack_38 == 90.0) << 0xe) >> 8)) != 1) &&
           (fVar1 = (float)(int)param_1[0x18a], (float)(int)param_1[0x18a] <= fStack_38)) {
LAB_00114993:
          fVar1 = fStack_38;
        }
      }
      else {
        fVar1 = -90.0;
        if ((-90.0 <= fStack_38) &&
           (fVar1 = (float)-(int)param_1[0x18a],
           (byte)(fVar1 < fStack_38 |
                  (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fStack_38)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fStack_38) << 0xe) >> 8)) != 1))
        goto LAB_00114993;
      }
      fStack_38 = fVar1;
      param_1[0x19c] = fStack_34;
      param_1[0x19b] = fStack_38;
LAB_001149a7:
      (**(code **)((int)param_1[0xf2] + 0x218))(param_1);
      MoveTurret__11CBaseTurret(param_1);
      return;
    }
  }
LAB_00114562:
  *(undefined4 *)((int)ppfVar6 + -4) = 0;
  ppfVar7 = (float **)((int)ppfVar6 + -8);
  *(float **)((int)ppfVar6 + -8) = param_1 + 0x11c;
LAB_0011456b:
  *(code **)((int)ppfVar7 + -4) = FUN_00114570;
  __as__7EHANDLEP11CBaseEntity();
  param_1[0x194] = *gpGlobals + param_1[0x195];
  param_1[3] = -NAN;
  param_1[4] = (float)SearchThink__11CBaseTurret;
  return;
}


