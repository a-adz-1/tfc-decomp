// Fire__11CTFAssaultC  @ 00129fc4
void Fire__11CTFAssaultC(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  float fVar3;
  int iVar4;
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
  
  fVar3 = *(float *)(param_1 + 0x488);
  if ((byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 1) {
    (*DAT_0019f88c)(9,*(undefined4 *)(**(int **)(param_1 + 0x474) + 0x208),
                    *(undefined2 *)(param_1 + 0x4dc),0,&g_vecZero,&g_vecZero,0,0,0,0,
                    *(byte *)(*(int **)(param_1 + 0x474) + 0x33) & 1,0);
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6bc) = 600;
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6c4) = 0x100;
    pbVar1 = (byte *)(**(int **)(param_1 + 0x474) + 0x118);
    *pbVar1 = *pbVar1 | 2;
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x474),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x474) + 0x74);
    iVar4 = **(int **)(param_1 + 0x474);
    fStack_28 = *(float *)(iVar4 + 8) + *(float *)(iVar4 + 0x174);
    fStack_24 = *(float *)(iVar4 + 0xc) + *(float *)(iVar4 + 0x178);
    fStack_20 = *(float *)(iVar4 + 0x10) + *(float *)(iVar4 + 0x17c);
    fStack_34 = *(float *)(gpGlobals + 0x40) + *(float *)(gpGlobals + 0x40);
    fStack_30 = *(float *)(gpGlobals + 0x44) + *(float *)(gpGlobals + 0x44);
    fStack_2c = *(float *)(gpGlobals + 0x48) + *(float *)(gpGlobals + 0x48);
    fStack_1c = fStack_28 + fStack_34;
    fStack_18 = fStack_24 + fStack_30;
    fStack_14 = fStack_20 + fStack_2c;
    fStack_40 = *(float *)(gpGlobals + 0x34) * -4.0;
    fStack_10 = fStack_1c + fStack_40;
    fStack_3c = *(float *)(gpGlobals + 0x38) * -4.0;
    fStack_c = fStack_18 + fStack_3c;
    fStack_38 = *(float *)(gpGlobals + 0x3c) * -4.0;
    fStack_8 = fStack_14 + fStack_38;
    GetAutoaimVector__11CBasePlayerf(&fStack_40,*(int **)(param_1 + 0x474),0x3db27eb6);
    fStack_34 = fStack_10;
    fStack_30 = fStack_c;
    fStack_2c = fStack_8;
    fStack_28 = fStack_40;
    fStack_24 = fStack_3c;
    fStack_20 = fStack_38;
    fStack_1c = 0.1;
    fStack_18 = 0.1;
    fStack_14 = 0.0;
    FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_s
              (*(undefined4 *)(param_1 + 0x474),5,&fStack_34,&fStack_28,&fStack_1c,0x46000000,7,8,7,
               0);
    DB_LogShots__17CBasePlayerWeaponl(param_1,1);
    piVar2 = (int *)(*(int *)(param_1 + 0x474) + 0xcc);
    *piVar2 = *piVar2 + -1;
    *(undefined4 *)(param_1 + 0x490) = 0x3dcccccd;
    *(undefined4 *)(param_1 + 0x488) = 0x3dcccccd;
  }
  return;
}


// Fire__12CFuncTankGunRC6VectorT1P9entvars_s  @ 000ab68c
void Fire__12CFuncTankGunRC6VectorT1P9entvars_s
               (int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  float fVar2;
  undefined4 *puVar3;
  undefined2 in_FPUControlWord;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  fVar2 = (float)param_1[0x123];
  if ((byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
    UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
    _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
    local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
    iVar1 = (int)ROUND((*gpGlobals - (float)param_1[0x123]) * (float)param_1[0x124]);
    if (iVar1 < 1) {
      return;
    }
    local_38 = 0;
    if (0 < iVar1) {
      do {
        switch(param_1[0x12f]) {
        default:
          goto switchD_000ab738_caseD_0;
        case 1:
          local_1c = *param_2;
          local_18 = param_2[1];
          local_14 = param_2[2];
          local_28 = *param_3;
          local_24 = param_3[1];
          local_20 = param_3[2];
          iVar6 = param_1[0x134];
          local_34 = (&gTankSpread)[iVar6 * 3];
          local_30 = (&DAT_0019ee04)[iVar6 * 3];
          local_2c = (&DAT_0019ee08)[iVar6 * 3];
          iVar6 = param_1[0x130];
          uVar5 = 8;
          puVar3 = &local_1c;
          puVar4 = &local_34;
          goto LAB_000ab88c;
        case 2:
          local_34 = *param_2;
          local_30 = param_2[1];
          local_2c = param_2[2];
          local_28 = *param_3;
          local_24 = param_3[1];
          local_20 = param_3[2];
          iVar6 = param_1[0x134];
          local_1c = (&gTankSpread)[iVar6 * 3];
          local_18 = (&DAT_0019ee04)[iVar6 * 3];
          local_14 = (&DAT_0019ee08)[iVar6 * 3];
          iVar6 = param_1[0x130];
          uVar5 = 9;
          break;
        case 3:
          local_34 = *param_2;
          local_30 = param_2[1];
          local_2c = param_2[2];
          local_28 = *param_3;
          local_24 = param_3[1];
          local_20 = param_3[2];
          iVar6 = param_1[0x134];
          local_1c = (&gTankSpread)[iVar6 * 3];
          local_18 = (&DAT_0019ee04)[iVar6 * 3];
          local_14 = (&DAT_0019ee08)[iVar6 * 3];
          iVar6 = param_1[0x130];
          uVar5 = 10;
        }
        puVar3 = &local_34;
        puVar4 = &local_1c;
LAB_000ab88c:
        FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_s
                  (param_1,1,puVar3,&local_28,puVar4,0x45800000,uVar5,1,iVar6,param_4);
switchD_000ab738_caseD_0:
        local_38 = local_38 + 1;
      } while (local_38 < iVar1);
    }
  }
  Fire__9CFuncTankRC6VectorT1P9entvars_s(param_1,param_2,param_3,param_4);
  return;
}


// Fire__12CTFSentrygun  @ 000ecef8
undefined4 Fire__12CTFSentrygun(int *param_1)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int iVar8;
  float **ppfVar9;
  undefined1 *puVar10;
  longdouble lVar11;
  longdouble lVar12;
  undefined4 uVar13;
  float *pfStack_74;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
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
  
  pfStack_74 = (float *)(param_1 + 0x1ac);
  UTIL_MakeAimVectors__FRC6Vector();
  piVar3 = (int *)__rf__7EHANDLE(param_1 + 0x13f);
  iVar8 = *piVar3;
  local_1c = *(float *)(iVar8 + 8) - *(float *)(*param_1 + 8);
  local_18 = *(float *)(iVar8 + 0xc) - *(float *)(*param_1 + 0xc);
  local_14 = *(float *)(iVar8 + 0x10) - *(float *)(*param_1 + 0x10);
  ppfVar9 = (float **)&stack0xffffff90;
  puVar10 = &stack0xffffff90;
  local_20 = SQRT(local_14 * local_14 + local_18 * local_18 + local_1c * local_1c);
  if ((byte)((byte)((ushort)((ushort)NAN(local_20) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_20 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_10 = 0.0;
    local_c = 0.0;
    local_8 = 1.0;
  }
  else {
    local_8 = 1.0 / local_20;
    local_10 = local_1c * local_8;
    local_c = local_18 * local_8;
    local_8 = local_8 * local_14;
  }
  if ((param_1[0x23] == 3) && (0 < param_1[0x39])) {
    fVar1 = *gpGlobals;
    fVar2 = (float)param_1[0x10d];
    if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40)
    goto LAB_000ed1ec;
    if ((param_1[0x39] & 1U) == 0) {
      uVar13 = 2;
    }
    else {
      uVar13 = 3;
    }
    pfStack_74 = &local_2c;
    GetAttachment__14CBaseAnimatingiR6VectorT2(param_1,uVar13,&local_20);
    pfStack_74 = &local_10;
    UTIL_VecToAngles__FRC6Vector(&local_38);
    local_3c = local_30;
    local_40 = local_34;
    local_28 = local_34;
    local_24 = local_30;
    local_44 = -local_38;
    piVar3 = param_1 + 0x51;
    local_38 = local_20;
    local_34 = local_1c;
    local_30 = local_18;
    local_2c = local_44;
    uVar13 = __opP11CBaseEntity__7EHANDLE(piVar3,0);
    piVar4 = (int *)CreateRpgRocket__12CTFRpgRocketG6VectorT1P11CBaseEntityP6CTFRpg
                              (&local_38,&local_44,uVar13);
    piVar4[0xfe] = (int)"sentrygun" - (int)gpGlobals[0x26];
    iVar8 = *piVar4;
    *(float *)(iVar8 + 0x20) = local_10 * 800.0;
    *(float *)(iVar8 + 0x24) = local_c * 800.0;
    *(float *)(iVar8 + 0x28) = local_8 * 800.0;
    local_44 = local_20;
    local_40 = local_1c;
    local_3c = local_18;
    local_38 = local_2c;
    local_34 = local_28;
    local_30 = local_24;
    piVar5 = (int *)__rf__7EHANDLE(piVar3);
    UTIL_ParametricRocket__FP9entvars_sG6VectorT1P7edict_s
              (*piVar4,&local_44,&local_38,*(undefined4 *)(*piVar5 + 0x208));
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"weapons/rocketfire1.wav",0x3f800000,0x3f4ccccd,0
               ,100);
    fVar1 = *gpGlobals;
    iVar8 = param_1[0x39];
    param_1[0x39] = iVar8 + -1;
    param_1[0x10d] = (int)(fVar1 + 3.0);
    if (iVar8 == 0xb) {
      puVar6 = (undefined4 *)__rf__7EHANDLE(piVar3,1,"#Sentry_rocketslow",0,0,0,0);
      ClientPrint__FP9entvars_siPCcN42(*puVar6);
    }
    if (param_1[0x39] == 0) {
      puVar6 = (undefined4 *)__rf__7EHANDLE(piVar3,1,"#Sentry_rocketsout",0,0,0,0);
      ClientPrint__FP9entvars_siPCcN42(*puVar6);
    }
    ppfVar9 = &pfStack_74;
    if (param_1[0x33] < 1) {
      return 0;
    }
LAB_000ed1fa:
    iVar8 = *param_1;
    if (*(int *)(iVar8 + 0x128) != 1) {
      if (1 < *(int *)(iVar8 + 0x128) - 1U) {
        *(undefined4 *)(iVar8 + 0x130) = 0;
        iVar8 = *param_1;
      }
      *(undefined4 *)(iVar8 + 0x128) = 1;
      *(int **)((int)ppfVar9 + -4) = param_1;
      *(undefined4 *)((int)ppfVar9 + -8) = 0xed249;
      ResetSequenceInfo__14CBaseAnimating();
      iVar8 = *param_1;
    }
    *(byte *)(iVar8 + 0x118) = *(byte *)(iVar8 + 0x118) | 2;
    if ((param_1[0x23] == 3) && ((*(byte *)(param_1 + 0x33) & 1) != 0)) {
      *(float **)((int)ppfVar9 + -4) = &local_38;
      *(float **)((int)ppfVar9 + -8) = &local_44;
      *(undefined4 *)((int)ppfVar9 + -0xc) = 1;
    }
    else {
      *(float **)((int)ppfVar9 + -4) = &local_38;
      *(float **)((int)ppfVar9 + -8) = &local_44;
      *(undefined4 *)((int)ppfVar9 + -0xc) = 0;
    }
    *(int **)((int)ppfVar9 + -0x10) = param_1;
    *(undefined4 *)((int)ppfVar9 + -0x14) = 0xed284;
    GetAttachment__14CBaseAnimatingiR6VectorT2();
    local_2c = local_44;
    local_28 = local_40;
    local_24 = local_3c;
    local_20 = local_10;
    local_1c = local_c;
    local_18 = local_8;
    local_50 = g_vecZero;
    local_4c = DAT_0019f664;
    local_48 = DAT_0019f668;
    *(int **)((int)ppfVar9 + -4) = param_1 + 0x51;
    *(undefined4 *)((int)ppfVar9 + -8) = 0xed2cb;
    puVar6 = (undefined4 *)__rf__7EHANDLE();
    *(undefined4 *)((int)ppfVar9 + -8) = *puVar6;
    *(undefined4 *)((int)ppfVar9 + -0xc) = 0x10;
    *(undefined4 *)((int)ppfVar9 + -0x10) = 4;
    *(undefined4 *)((int)ppfVar9 + -0x14) = 8;
    *(undefined4 *)((int)ppfVar9 + -0x18) = 0x45000000;
    *(undefined4 **)((int)ppfVar9 + -0x1c) = &local_50;
    *(float **)((int)ppfVar9 + -0x20) = &local_20;
    *(float **)((int)ppfVar9 + -0x24) = &local_2c;
    *(undefined4 *)((int)ppfVar9 + -0x28) = 1;
    *(int **)((int)ppfVar9 + -0x2c) = param_1;
    *(undefined4 *)((int)ppfVar9 + -0x30) = 0xed2ec;
    FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_s();
    uVar13 = *(undefined4 *)(*param_1 + 0x208);
    *(undefined4 *)((int)ppfVar9 + -4) = 100;
    *(undefined4 *)((int)ppfVar9 + -8) = 0;
    *(undefined4 *)((int)ppfVar9 + -0xc) = 0x3f4ccccd;
    *(undefined4 *)((int)ppfVar9 + -0x10) = 0x3f800000;
    *(char **)((int)ppfVar9 + -0x14) = "weapons/pl_gun3.wav";
    *(undefined4 *)((int)ppfVar9 + -0x18) = 3;
    *(undefined4 *)((int)ppfVar9 + -0x1c) = uVar13;
    *(undefined4 *)((int)ppfVar9 + -0x20) = 0xed314;
    EMIT_SOUND_DYN__FP7edict_siPCcffii();
    iVar8 = param_1[0x33];
    param_1[0x33] = iVar8 + -1;
    iVar8 = iVar8 + -1;
    puVar10 = (undefined1 *)ppfVar9;
  }
  else {
LAB_000ed1ec:
    iVar8 = param_1[0x33];
    if (0 < iVar8) goto LAB_000ed1fa;
  }
  if (iVar8 == 0) {
    *(undefined4 *)(puVar10 + -4) = 0x3f800000;
    *(undefined4 *)(puVar10 + -8) = 0;
    *(undefined4 *)(puVar10 + -0xc) = 0xed344;
    lVar11 = (longdouble)(*DAT_0019f80c)();
    lVar12 = (longdouble)0.1;
    if (0x3f < (byte)((lVar12 < lVar11 |
                       (byte)((ushort)((ushort)(NAN(lVar12) || NAN(lVar11)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar12 == lVar11) << 0xe) >> 8)) - 1)) {
      *(undefined4 *)(puVar10 + -4) = 0;
      *(undefined4 *)(puVar10 + -8) = 0;
      *(undefined4 *)(puVar10 + -0xc) = 0;
      *(undefined4 *)(puVar10 + -0x10) = 0;
      pcVar7 = "#Sentry_shellsout";
      goto LAB_000ed383;
    }
  }
  if (param_1[0x33] != 0x14) {
    return 1;
  }
  *(undefined4 *)(puVar10 + -4) = 0;
  *(undefined4 *)(puVar10 + -8) = 0;
  *(undefined4 *)(puVar10 + -0xc) = 0;
  *(undefined4 *)(puVar10 + -0x10) = 0;
  pcVar7 = "#Sentry_shellslow";
LAB_000ed383:
  *(char **)(puVar10 + -0x14) = pcVar7;
  *(undefined4 *)(puVar10 + -0x18) = 1;
  *(int **)(puVar10 + -0x1c) = param_1 + 0x51;
  *(undefined4 *)(puVar10 + -0x20) = 0xed392;
  puVar6 = (undefined4 *)__rf__7EHANDLE();
  *(undefined4 *)(puVar10 + -0x1c) = *puVar6;
  *(undefined4 *)(puVar10 + -0x20) = 0xed39d;
  ClientPrint__FP9entvars_siPCcN42();
  return 1;
}


// Fire__14CFuncTankLaserRC6VectorT1P9entvars_s  @ 000ab9f0
void Fire__14CFuncTankLaserRC6VectorT1P9entvars_s
               (int *param_1,undefined4 *param_2,undefined4 param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_3c [56];
  
  fVar1 = (float)param_1[0x123];
  if (((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
     (iVar3 = GetLaser__14CFuncTankLaser(param_1), iVar3 != 0)) {
    UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
    iVar3 = (int)ROUND((*gpGlobals - (float)param_1[0x123]) * (float)param_1[0x124]);
    if (iVar3 == 0) {
      return;
    }
    iVar4 = 0;
    if (0 < iVar3) {
      do {
        iVar2 = *(int *)param_1[0x135];
        *(undefined4 *)(iVar2 + 8) = *param_2;
        *(undefined4 *)(iVar2 + 0xc) = param_2[1];
        *(undefined4 *)(iVar2 + 0x10) = param_2[2];
        TankTrace__9CFuncTankRC6VectorN21R11TraceResult
                  (param_1,param_2,param_3,&gTankSpread + param_1[0x134] * 3,local_3c);
        param_1[0x136] = (int)*gpGlobals;
        TurnOn__6CLaser(param_1[0x135]);
        *(float *)(*(int *)param_1[0x135] + 0x1e4) = *gpGlobals - 1.0;
        FireAtPoint__6CLaserR11TraceResult(param_1[0x135],local_3c);
        iVar4 = iVar4 + 1;
        *(undefined4 *)(*(int *)param_1[0x135] + 0x104) = 0;
      } while (iVar4 < iVar3);
    }
  }
  Fire__9CFuncTankRC6VectorT1P9entvars_s(param_1,param_2,param_3,*param_1);
  return;
}


// Fire__15CFuncTankMortarRC6VectorT1P9entvars_s  @ 000abf68
void Fire__15CFuncTankMortarRC6VectorT1P9entvars_s
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  float fVar1;
  int iVar2;
  undefined2 in_FPUControlWord;
  undefined1 local_48 [20];
  undefined1 local_34 [36];
  undefined4 local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  fVar1 = (float)param_1[0x123];
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
    local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
    if ((int)ROUND((*gpGlobals - fVar1) * (float)param_1[0x124]) < 1) {
      return;
    }
    UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
    TankTrace__9CFuncTankRC6VectorN21R11TraceResult
              (param_1,param_2,param_3,&gTankSpread + param_1[0x134] * 3,local_48);
    iVar2 = *param_1;
    ExplosionCreate__FRC6VectorT0P7edict_sii
              (local_34,iVar2 + 0x50,*(undefined4 *)(iVar2 + 0x208),*(undefined4 *)(iVar2 + 0x184),1
              );
  }
  Fire__9CFuncTankRC6VectorT1P9entvars_s(param_1,param_2,param_3,*param_1);
  return;
}


// Fire__15CFuncTankRocketRC6VectorT1P9entvars_s  @ 000ac128
void Fire__15CFuncTankRocketRC6VectorT1P9entvars_s
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  float fVar2;
  int iVar3;
  
  fVar2 = (float)param_1[0x123];
  if ((byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
    iVar1 = (int)ROUND((*gpGlobals - fVar2) * (float)param_1[0x124]);
    if (iVar1 < 1) {
      return;
    }
    iVar3 = 0;
    if (0 < iVar1) {
      do {
        Create__11CBaseEntityPcRC6VectorT2P7edict_s
                  ("rpg_rocket",param_2,*param_1 + 0x50,*(undefined4 *)(*param_1 + 0x208));
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
    }
  }
  Fire__9CFuncTankRC6VectorT1P9entvars_s(param_1,param_2,param_3,*param_1);
  return;
}


// Fire__9CFuncTankRC6VectorT1P9entvars_s  @ 000ab224
void Fire__9CFuncTankRC6VectorT1P9entvars_s(int *param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int *piVar5;
  longdouble lVar6;
  
  fVar1 = (float)param_1[0x123];
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if (param_1[0x12d] != 0) {
      piVar5 = (int *)SpriteCreate__7CSpritePCcRC6Vectori
                                (param_1[0x12d] + (int)gpGlobals[0x26],param_2,1);
      lVar6 = (longdouble)(*DAT_0019f80c)(0x41700000,0x41a00000);
      piVar5[3] = -0x10000;
      piVar5[4] = (int)AnimateUntilDead__7CSprite;
      *(float *)(*piVar5 + 0x138) = (float)lVar6;
      *(float *)(*piVar5 + 0x1e4) =
           (float)((longdouble)(float)piVar5[0x117] / lVar6 + (longdouble)*gpGlobals);
      *(float *)(*piVar5 + 0x104) = *gpGlobals;
      iVar4 = *param_1;
      fVar1 = *(float *)(iVar4 + 0x150);
      fVar2 = *(float *)(iVar4 + 0x154);
      fVar3 = *(float *)(iVar4 + 0x158);
      *(undefined4 *)(*piVar5 + 0x148) = 4;
      *(float *)(*piVar5 + 0x150) = (float)(int)ROUND(fVar1);
      *(float *)(*piVar5 + 0x154) = (float)(int)ROUND(fVar2);
      *(float *)(*piVar5 + 0x158) = (float)(int)ROUND(fVar3);
      *(undefined4 *)(*piVar5 + 0x14c) = 0x437f0000;
      *(undefined4 *)(*piVar5 + 0x15c) = 0;
      lVar6 = (longdouble)(*DAT_0019f80c)(0x42200000,0x42a00000);
      *(float *)(*piVar5 + 0x28) = (float)lVar6;
      *(int *)(*piVar5 + 0x144) = param_1[300];
    }
    if (param_1[0x12e] != 0) {
      piVar5 = (int *)SpriteCreate__7CSpritePCcRC6Vectori
                                (param_1[0x12e] + (int)gpGlobals[0x26],param_2,1);
      piVar5[3] = -0x10000;
      piVar5[4] = (int)AnimateUntilDead__7CSprite;
      *(undefined4 *)(*piVar5 + 0x138) = 0x42700000;
      *(float *)(*piVar5 + 0x1e4) = (float)piVar5[0x117] / 60.0 + *gpGlobals;
      *(float *)(*piVar5 + 0x104) = *gpGlobals;
      *(undefined4 *)(*piVar5 + 0x148) = 5;
      *(undefined4 *)(*piVar5 + 0x150) = 0x437f0000;
      *(undefined4 *)(*piVar5 + 0x154) = 0x437f0000;
      *(undefined4 *)(*piVar5 + 0x158) = 0x437f0000;
      *(undefined4 *)(*piVar5 + 0x14c) = 0x437f0000;
      *(undefined4 *)(*piVar5 + 0x15c) = 0xe;
      *(int *)(*piVar5 + 0x144) = param_1[300];
    }
    SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  }
  param_1[0x123] = (int)*gpGlobals;
  return;
}


