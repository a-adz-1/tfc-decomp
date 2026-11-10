// Fire__11CTFAssaultC  @ 00125efc
void Fire__11CTFAssaultC(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  float fVar3;
  int iVar4;
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
  float fStack_4;
  
  fVar3 = *(float *)(param_1 + 0x478);
  if ((byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 1) {
    (*DAT_001c120c)(9,*(undefined4 *)(**(int **)(param_1 + 0x464) + 0x208),
                    *(undefined2 *)(param_1 + 0x4cc),0,&g_vecZero,&g_vecZero,0,0,0,0,
                    *(byte *)(*(int **)(param_1 + 0x464) + 0x33) & 1,0);
    *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x698) = 600;
    *(undefined4 *)(*(int *)(param_1 + 0x464) + 0x6a0) = 0x100;
    pbVar1 = (byte *)(**(int **)(param_1 + 0x464) + 0x118);
    *pbVar1 = *pbVar1 | 2;
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x464),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x464) + 0x74);
    iVar4 = **(int **)(param_1 + 0x464);
    fStack_24 = *(float *)(iVar4 + 8) + *(float *)(iVar4 + 0x174);
    fStack_20 = *(float *)(iVar4 + 0xc) + *(float *)(iVar4 + 0x178);
    fStack_1c = *(float *)(iVar4 + 0x10) + *(float *)(iVar4 + 0x17c);
    fStack_30 = *(float *)(gpGlobals + 0x40) + *(float *)(gpGlobals + 0x40);
    fStack_2c = *(float *)(gpGlobals + 0x44) + *(float *)(gpGlobals + 0x44);
    fStack_28 = *(float *)(gpGlobals + 0x48) + *(float *)(gpGlobals + 0x48);
    fStack_18 = fStack_24 + fStack_30;
    fStack_14 = fStack_20 + fStack_2c;
    fStack_10 = fStack_1c + fStack_28;
    fStack_3c = *(float *)(gpGlobals + 0x34) * -4.0;
    fStack_38 = *(float *)(gpGlobals + 0x38) * -4.0;
    fStack_34 = *(float *)(gpGlobals + 0x3c) * -4.0;
    fStack_c = fStack_18 + fStack_3c;
    fStack_8 = fStack_14 + fStack_38;
    fStack_4 = fStack_10 + fStack_34;
    GetAutoaimVector__11CBasePlayerf(&fStack_3c,*(int **)(param_1 + 0x464),0x3db27eb6);
    fStack_34 = fStack_10;
    fStack_30 = fStack_c;
    fStack_2c = fStack_8;
    fStack_24 = fStack_3c;
    fStack_20 = fStack_38;
    fStack_1c = 0.1;
    fStack_18 = 0.1;
    fStack_14 = 0.0;
    FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_s
              (*(undefined4 *)(param_1 + 0x464),5,&fStack_34,&fStack_28,&fStack_1c,0x46000000,7,8,7,
               0);
    DB_LogShots__17CBasePlayerWeaponl(param_1,1);
    piVar2 = (int *)(*(int *)(param_1 + 0x464) + 0xcc);
    *piVar2 = *piVar2 + -1;
    *(undefined4 *)(param_1 + 0x480) = 0x3dcccccd;
    *(undefined4 *)(param_1 + 0x478) = 0x3dcccccd;
  }
  return;
}


// Fire__12CFuncTankGunRC6VectorT1P9entvars_s  @ 000ac440
void Fire__12CFuncTankGunRC6VectorT1P9entvars_s
               (int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  float fVar2;
  undefined2 in_FPUControlWord;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 local_c;
  undefined2 local_4;
  undefined2 uStack_2;
  
  fVar2 = (float)param_1[0x11f];
  if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
    UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
    _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
    local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
    iVar1 = (int)ROUND((*gpGlobals - (float)param_1[0x11f]) * (float)param_1[0x120]);
    if (iVar1 < 1) {
      return;
    }
    local_34 = 0;
    if (0 < iVar1) {
      do {
        puVar3 = &local_30;
        switch(param_1[299]) {
        default:
          goto LAB_000ac6c0;
        case 1:
          uStack_18 = *param_2;
          uStack_14 = param_2[1];
          uStack_10 = param_2[2];
          uStack_24 = *param_3;
          uStack_20 = param_3[1];
          uStack_1c = param_3[2];
          iVar6 = param_1[0x130];
          local_30 = (&gTankSpread)[iVar6 * 3];
          uStack_2c = (&DAT_001c0784)[iVar6 * 3];
          uStack_28 = (&DAT_001c0788)[iVar6 * 3];
          iVar6 = param_1[300];
          uVar5 = 8;
          puVar3 = &uStack_18;
          puVar4 = &local_30;
          break;
        case 2:
          local_30 = *param_2;
          uStack_2c = param_2[1];
          uStack_28 = param_2[2];
          uStack_24 = *param_3;
          uStack_20 = param_3[1];
          uStack_1c = param_3[2];
          iVar6 = param_1[0x130];
          uStack_18 = (&gTankSpread)[iVar6 * 3];
          uStack_14 = (&DAT_001c0784)[iVar6 * 3];
          uStack_10 = (&DAT_001c0788)[iVar6 * 3];
          iVar6 = param_1[300];
          uVar5 = 9;
          puVar4 = &uStack_18;
          break;
        case 3:
          local_30 = *param_2;
          uStack_2c = param_2[1];
          uStack_28 = param_2[2];
          uStack_24 = *param_3;
          uStack_20 = param_3[1];
          uStack_1c = param_3[2];
          iVar6 = param_1[0x130];
          uStack_18 = (&gTankSpread)[iVar6 * 3];
          uStack_14 = (&DAT_001c0784)[iVar6 * 3];
          uStack_10 = (&DAT_001c0788)[iVar6 * 3];
          iVar6 = param_1[300];
          uVar5 = 10;
          puVar4 = &uStack_18;
        }
        FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_s
                  (param_1,1,puVar3,&uStack_24,puVar4,0x45800000,uVar5,1,iVar6,param_4);
LAB_000ac6c0:
        local_34 = local_34 + 1;
      } while (local_34 < iVar1);
    }
  }
  Fire__9CFuncTankRC6VectorT1P9entvars_s(param_1,param_2,param_3,param_4);
  return;
}


// Fire__12CTFSentrygun  @ 000eb3b0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Fire__12CTFSentrygun(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  char *pcVar6;
  float **ppfVar7;
  undefined1 *puVar8;
  longdouble lVar9;
  longdouble lVar10;
  undefined4 uVar11;
  float *pfStack_74;
  undefined4 uStack_54;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  float fStack_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  pfStack_74 = (float *)(param_1 + 0x1a8);
  UTIL_MakeAimVectors__FRC6Vector();
  piVar2 = (int *)__rf__7EHANDLE(param_1 + 0x13b);
  iVar1 = *piVar2;
  ppfVar7 = (float **)&stack0xffffff90;
  puVar8 = &stack0xffffff90;
  local_18 = *(float *)(iVar1 + 8) - *(float *)(*param_1 + 8);
  local_14 = *(float *)(iVar1 + 0xc) - *(float *)(*param_1 + 0xc);
  local_10 = *(float *)(iVar1 + 0x10) - *(float *)(*param_1 + 0x10);
  local_1c = SQRT(local_10 * local_10 + local_14 * local_14 + local_18 * local_18);
  if ((byte)((byte)((ushort)((ushort)NAN(local_1c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_1c == 0.0) << 0xe) >> 8)) == 0x40) {
    local_c = 0.0;
    local_8 = 0.0;
    local_4 = 1.0;
  }
  else {
    local_4 = _FUN_0014cea4 / local_1c;
    local_c = local_4 * local_18;
    local_8 = local_4 * local_14;
    local_4 = local_4 * local_10;
  }
  if (((param_1[0x23] != 3) || (param_1[0x39] < 1)) || (*gpGlobals <= (float)param_1[0x109])) {
    if (0 < param_1[0x33]) goto LAB_000eb739;
  }
  else {
    if ((*(byte *)(param_1 + 0x39) & 1) == 0) {
      uVar11 = 2;
    }
    else {
      uVar11 = 3;
    }
    pfStack_74 = &fStack_28;
    GetAttachment__14CBaseAnimatingiR6VectorT2(param_1,uVar11,&local_1c);
    pfStack_74 = &local_c;
    UTIL_VecToAngles__FRC6Vector(&fStack_34);
    fStack_3c = fStack_30;
    fStack_40 = fStack_34;
    fStack_28 = fStack_34;
    uStack_24 = fStack_30;
    fStack_44 = -fStack_38;
    fStack_38 = fStack_20;
    fStack_34 = local_1c;
    fStack_30 = local_18;
    piVar2 = param_1 + 0x51;
    fStack_2c = fStack_44;
    uVar11 = __opP11CBaseEntity__7EHANDLE(piVar2,0);
    piVar3 = (int *)CreateRpgRocket__12CTFRpgRocketG6VectorT1P11CBaseEntityP6CTFRpg
                              (uStack_54,&fStack_44,uVar11);
    piVar3[0xfa] = (int)"sentrygun" - (int)gpGlobals[0x26];
    iVar1 = *piVar3;
    *(float *)(iVar1 + 0x20) = local_10 * 800.0;
    *(float *)(iVar1 + 0x24) = local_8 * 800.0;
    *(float *)(iVar1 + 0x28) = local_4 * 800.0;
    fStack_44 = fStack_20;
    fStack_40 = local_1c;
    fStack_3c = local_18;
    fStack_38 = fStack_2c;
    fStack_34 = fStack_28;
    fStack_30 = (float)uStack_24;
    piVar4 = (int *)__rf__7EHANDLE(piVar2);
    UTIL_ParametricRocket__FP9entvars_sG6VectorT1P7edict_s
              (*piVar3,&fStack_44,uStack_54,*(undefined4 *)(*piVar4 + 0x208));
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"weapons/rocketfire1.wav",0x3f800000,0x3f4ccccd,0
               ,100);
    param_1[0x109] = (int)(*gpGlobals + 3.0);
    param_1[0x39] = param_1[0x39] + -1;
    if (param_1[0x39] == 10) {
      puVar5 = (undefined4 *)__rf__7EHANDLE(piVar2,1,"#Sentry_rocketslow",0,0,0,0);
      ClientPrint__FP9entvars_siPCcN42(*puVar5);
    }
    if (param_1[0x39] == 0) {
      puVar5 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x51,1,"#Sentry_rocketsout",0,0,0,0);
      ClientPrint__FP9entvars_siPCcN42(*puVar5);
    }
    ppfVar7 = &pfStack_74;
    if (param_1[0x33] < 1) {
      return 0;
    }
LAB_000eb739:
    *(undefined4 *)((int)ppfVar7 + -4) = 1;
    *(int **)((int)ppfVar7 + -8) = param_1;
    *(undefined4 *)((int)ppfVar7 + -0xc) = 0xeb741;
    SetSentryAnim__12CTFSentrygun13TFTURRET_ANIM();
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 2;
    if ((param_1[0x23] == 3) && ((*(byte *)(param_1 + 0x33) & 1) != 0)) {
      *(undefined1 **)((int)ppfVar7 + -4) = (undefined1 *)((int)ppfVar7 + 0x3c);
      *(undefined1 **)((int)ppfVar7 + -8) = (undefined1 *)((int)ppfVar7 + 0x30);
      *(undefined4 *)((int)ppfVar7 + -0xc) = 1;
    }
    else {
      *(undefined1 **)((int)ppfVar7 + -4) = (undefined1 *)((int)ppfVar7 + 0x3c);
      *(undefined1 **)((int)ppfVar7 + -8) = (undefined1 *)((int)ppfVar7 + 0x30);
      *(undefined4 *)((int)ppfVar7 + -0xc) = 0;
    }
    *(int **)((int)ppfVar7 + -0x10) = param_1;
    *(undefined4 *)((int)ppfVar7 + -0x14) = 0xeb782;
    GetAttachment__14CBaseAnimatingiR6VectorT2();
    *(undefined4 *)((int)ppfVar7 + 0x48) = *(undefined4 *)((int)ppfVar7 + 0x30);
    *(undefined4 *)((int)ppfVar7 + 0x4c) = *(undefined4 *)((int)ppfVar7 + 0x34);
    *(undefined4 *)((int)ppfVar7 + 0x50) = *(undefined4 *)((int)ppfVar7 + 0x38);
    *(undefined4 *)((int)ppfVar7 + 0x54) = *(undefined4 *)((int)ppfVar7 + 100);
    *(undefined4 *)((int)ppfVar7 + 0x58) = *(undefined4 *)((int)ppfVar7 + 0x68);
    *(undefined4 *)((int)ppfVar7 + 0x5c) = *(undefined4 *)((int)ppfVar7 + 0x6c);
    *(undefined4 *)((int)ppfVar7 + 0x24) = g_vecZero;
    *(undefined4 *)((int)ppfVar7 + 0x28) = DAT_001c0fe4;
    *(undefined4 *)((int)ppfVar7 + 0x2c) = DAT_001c0fe8;
    *(int **)((int)ppfVar7 + -4) = param_1 + 0x51;
    *(undefined4 *)((int)ppfVar7 + -8) = 0xeb7db;
    puVar5 = (undefined4 *)__rf__7EHANDLE();
    *(undefined4 *)((int)ppfVar7 + -8) = *puVar5;
    *(undefined4 *)((int)ppfVar7 + -0xc) = 0x10;
    *(undefined4 *)((int)ppfVar7 + -0x10) = 4;
    *(undefined4 *)((int)ppfVar7 + -0x14) = 8;
    *(undefined4 *)((int)ppfVar7 + -0x18) = 0x45000000;
    *(undefined1 **)((int)ppfVar7 + -0x1c) = (undefined1 *)((int)ppfVar7 + 0x24);
    *(undefined1 **)((int)ppfVar7 + -0x20) = (undefined1 *)((int)ppfVar7 + 0x54);
    *(undefined1 **)((int)ppfVar7 + -0x24) = (undefined1 *)((int)ppfVar7 + 0x48);
    *(undefined4 *)((int)ppfVar7 + -0x28) = 1;
    *(int **)((int)ppfVar7 + -0x2c) = param_1;
    *(undefined4 *)((int)ppfVar7 + -0x30) = 0xeb800;
    FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_s();
    uVar11 = *(undefined4 *)(*param_1 + 0x208);
    *(undefined4 *)((int)ppfVar7 + -4) = 100;
    *(undefined4 *)((int)ppfVar7 + -8) = 0;
    *(undefined4 *)((int)ppfVar7 + -0xc) = 0x3f4ccccd;
    *(undefined4 *)((int)ppfVar7 + -0x10) = 0x3f800000;
    *(char **)((int)ppfVar7 + -0x14) = "weapons/pl_gun3.wav";
    *(undefined4 *)((int)ppfVar7 + -0x18) = 3;
    *(undefined4 *)((int)ppfVar7 + -0x1c) = uVar11;
    *(undefined4 *)((int)ppfVar7 + -0x20) = 0xeb829;
    EMIT_SOUND_DYN__FP7edict_siPCcffii();
    param_1[0x33] = param_1[0x33] + -1;
    puVar8 = (undefined1 *)ppfVar7;
  }
  if (param_1[0x33] == 0) {
    *(undefined4 *)(puVar8 + -4) = 0x3f800000;
    *(undefined4 *)(puVar8 + -8) = 0;
    *(code **)(puVar8 + 0x14) = DAT_001c118c;
    *(undefined4 *)(puVar8 + -0xc) = 0xeb856;
    lVar9 = (longdouble)(*DAT_001c118c)();
    lVar10 = (longdouble)0.1;
    if (0x3f < (byte)((lVar10 < lVar9 |
                       (byte)((ushort)((ushort)(NAN(lVar10) || NAN(lVar9)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar10 == lVar9) << 0xe) >> 8)) - 1)) {
      *(undefined4 *)(puVar8 + -4) = 0;
      *(undefined4 *)(puVar8 + -8) = 0;
      *(undefined4 *)(puVar8 + -0xc) = 0;
      *(undefined4 *)(puVar8 + -0x10) = 0;
      pcVar6 = "#Sentry_shellsout";
      goto LAB_000eb897;
    }
  }
  if (param_1[0x33] != 0x14) {
    return 1;
  }
  *(undefined4 *)(puVar8 + -4) = 0;
  *(undefined4 *)(puVar8 + -8) = 0;
  *(undefined4 *)(puVar8 + -0xc) = 0;
  *(undefined4 *)(puVar8 + -0x10) = 0;
  pcVar6 = "#Sentry_shellslow";
LAB_000eb897:
  *(char **)(puVar8 + -0x14) = pcVar6;
  *(undefined4 *)(puVar8 + -0x18) = 1;
  *(int **)(puVar8 + -0x1c) = param_1 + 0x51;
  *(undefined4 *)(puVar8 + -0x20) = 0xeb8a6;
  puVar5 = (undefined4 *)__rf__7EHANDLE();
  *(undefined4 *)(puVar8 + -0x1c) = *puVar5;
  *(undefined4 *)(puVar8 + -0x20) = 0xeb8b1;
  ClientPrint__FP9entvars_siPCcN42();
  return 1;
}


// Fire__14CFuncTankLaserRC6VectorT1P9entvars_s  @ 000ac9d4
void Fire__14CFuncTankLaserRC6VectorT1P9entvars_s
               (int *param_1,undefined4 *param_2,undefined4 param_3)

{
  uint uVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined1 local_38 [56];
  
  fVar2 = (float)param_1[0x11f];
  if (((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) ||
     (iVar4 = GetLaser__14CFuncTankLaser(param_1), iVar4 == 0)) {
    iVar4 = *param_1;
    goto LAB_000acd73;
  }
  UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
  uVar1 = (uint)ROUND((*gpGlobals - (float)param_1[0x11f]) * (float)param_1[0x120]);
  if (uVar1 == 0) {
    return;
  }
  iVar4 = 0;
  if (0 < (int)uVar1) {
    if ((uVar1 & 1) != 0) {
      iVar4 = *(int *)param_1[0x131];
      *(undefined4 *)(iVar4 + 8) = *param_2;
      *(undefined4 *)(iVar4 + 0xc) = param_2[1];
      *(undefined4 *)(iVar4 + 0x10) = param_2[2];
      TankTrace__9CFuncTankRC6VectorN21R11TraceResult
                (param_1,param_2,param_3,&gTankSpread + param_1[0x130] * 3,local_38);
      param_1[0x132] = (int)*gpGlobals;
      TurnOn__6CLaser(param_1[0x131]);
      *(float *)(*(int *)param_1[0x131] + 0x1e4) = *gpGlobals - 1.0;
      FireAtPoint__6CLaserR11TraceResult(param_1[0x131],local_38);
      *(undefined4 *)(*(int *)param_1[0x131] + 0x104) = 0;
      iVar4 = 1;
      if ((int)uVar1 < 2) goto LAB_000acd4b;
    }
    do {
      iVar3 = *(int *)param_1[0x131];
      *(undefined4 *)(iVar3 + 8) = *param_2;
      *(undefined4 *)(iVar3 + 0xc) = param_2[1];
      *(undefined4 *)(iVar3 + 0x10) = param_2[2];
      TankTrace__9CFuncTankRC6VectorN21R11TraceResult
                (param_1,param_2,param_3,&gTankSpread + param_1[0x130] * 3,local_38);
      param_1[0x132] = (int)*gpGlobals;
      TurnOn__6CLaser(param_1[0x131]);
      *(float *)(*(int *)param_1[0x131] + 0x1e4) = *gpGlobals - 1.0;
      FireAtPoint__6CLaserR11TraceResult(param_1[0x131],local_38);
      *(undefined4 *)(*(int *)param_1[0x131] + 0x104) = 0;
      iVar3 = *(int *)param_1[0x131];
      *(undefined4 *)(iVar3 + 8) = *param_2;
      *(undefined4 *)(iVar3 + 0xc) = param_2[1];
      *(undefined4 *)(iVar3 + 0x10) = param_2[2];
      TankTrace__9CFuncTankRC6VectorN21R11TraceResult
                (param_1,param_2,param_3,&gTankSpread + param_1[0x130] * 3,local_38);
      param_1[0x132] = (int)*gpGlobals;
      TurnOn__6CLaser(param_1[0x131]);
      *(float *)(*(int *)param_1[0x131] + 0x1e4) = *gpGlobals - 1.0;
      FireAtPoint__6CLaserR11TraceResult(param_1[0x131],local_38);
      *(undefined4 *)(*(int *)param_1[0x131] + 0x104) = 0;
      iVar4 = iVar4 + 2;
    } while (iVar4 < (int)uVar1);
  }
LAB_000acd4b:
  iVar4 = *param_1;
LAB_000acd73:
  Fire__9CFuncTankRC6VectorT1P9entvars_s(param_1,param_2,param_3,iVar4);
  return;
}


// Fire__15CFuncTankMortarRC6VectorT1P9entvars_s  @ 000ad008
void Fire__15CFuncTankMortarRC6VectorT1P9entvars_s
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  float fVar1;
  int iVar2;
  undefined2 in_FPUControlWord;
  undefined1 local_44 [20];
  undefined1 local_30 [36];
  undefined4 local_c;
  undefined2 local_4;
  undefined2 uStack_2;
  
  fVar1 = (float)param_1[0x11f];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
    local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
    if ((int)ROUND((*gpGlobals - (float)param_1[0x11f]) * (float)param_1[0x120]) < 1) {
      return;
    }
    UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
    TankTrace__9CFuncTankRC6VectorN21R11TraceResult
              (param_1,param_2,param_3,&gTankSpread + param_1[0x130] * 3,local_44);
    iVar2 = *param_1;
    ExplosionCreate__FRC6VectorT0P7edict_sii
              (local_30,iVar2 + 0x50,*(undefined4 *)(iVar2 + 0x208),*(undefined4 *)(iVar2 + 0x184),1
              );
  }
  Fire__9CFuncTankRC6VectorT1P9entvars_s(param_1,param_2,param_3,*param_1);
  return;
}


// Fire__15CFuncTankRocketRC6VectorT1P9entvars_s  @ 000acdcc
void Fire__15CFuncTankRocketRC6VectorT1P9entvars_s
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  
  fVar2 = (float)param_1[0x11f];
  if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
    uVar1 = (uint)ROUND((*gpGlobals - (float)param_1[0x11f]) * (float)param_1[0x120]);
    if ((int)uVar1 < 1) {
      return;
    }
    iVar4 = 0;
    if (0 < (int)uVar1) {
      uVar3 = uVar1 & 3;
      if (uVar3 != 0) {
        if (1 < uVar3) {
          if (2 < uVar3) {
            Create__11CBaseEntityPcRC6VectorT2P7edict_s
                      ("rpg_rocket",param_2,*param_1 + 0x50,*(undefined4 *)(*param_1 + 0x208));
          }
          Create__11CBaseEntityPcRC6VectorT2P7edict_s
                    ("rpg_rocket",param_2,*param_1 + 0x50,*(undefined4 *)(*param_1 + 0x208));
          iVar4 = (2 < uVar3) + 1;
        }
        Create__11CBaseEntityPcRC6VectorT2P7edict_s
                  ("rpg_rocket",param_2,*param_1 + 0x50,*(undefined4 *)(*param_1 + 0x208));
        iVar4 = iVar4 + 1;
        if ((int)uVar1 <= iVar4) goto LAB_000acf67;
      }
      do {
        Create__11CBaseEntityPcRC6VectorT2P7edict_s
                  ("rpg_rocket",param_2,*param_1 + 0x50,*(undefined4 *)(*param_1 + 0x208));
        Create__11CBaseEntityPcRC6VectorT2P7edict_s
                  ("rpg_rocket",param_2,*param_1 + 0x50,*(undefined4 *)(*param_1 + 0x208));
        Create__11CBaseEntityPcRC6VectorT2P7edict_s
                  ("rpg_rocket",param_2,*param_1 + 0x50,*(undefined4 *)(*param_1 + 0x208));
        Create__11CBaseEntityPcRC6VectorT2P7edict_s
                  ("rpg_rocket",param_2,*param_1 + 0x50,*(undefined4 *)(*param_1 + 0x208));
        iVar4 = iVar4 + 4;
      } while (iVar4 < (int)uVar1);
    }
  }
LAB_000acf67:
  Fire__9CFuncTankRC6VectorT1P9entvars_s(param_1,param_2,param_3,*param_1);
  return;
}


// Fire__9CFuncTankRC6VectorT1P9entvars_s  @ 000abe4c
void Fire__9CFuncTankRC6VectorT1P9entvars_s(int *param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  longdouble lVar5;
  
  fVar1 = (float)param_1[0x11f];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if (param_1[0x129] != 0) {
      piVar4 = (int *)SpriteCreate__7CSpritePCcRC6Vectori
                                (param_1[0x129] + (int)gpGlobals[0x26],param_2,1);
      lVar5 = (longdouble)(*DAT_001c118c)(0x41700000,0x41a00000);
      piVar4[3] = -0x10000;
      piVar4[4] = (int)AnimateUntilDead__7CSprite;
      *(float *)(*piVar4 + 0x138) = (float)lVar5;
      *(float *)(*piVar4 + 0x1e4) =
           (float)((longdouble)(float)piVar4[0x113] / lVar5 + (longdouble)*gpGlobals);
      *(float *)(*piVar4 + 0x104) = *gpGlobals;
      fVar1 = *(float *)(*param_1 + 0x150);
      fVar2 = *(float *)(*param_1 + 0x154);
      fVar3 = *(float *)(*param_1 + 0x158);
      *(undefined4 *)(*piVar4 + 0x148) = 4;
      *(float *)(*piVar4 + 0x150) = (float)(int)ROUND(fVar1);
      *(float *)(*piVar4 + 0x154) = (float)(int)ROUND(fVar2);
      *(float *)(*piVar4 + 0x158) = (float)(int)ROUND(fVar3);
      *(undefined4 *)(*piVar4 + 0x14c) = 0x437f0000;
      *(undefined4 *)(*piVar4 + 0x15c) = 0;
      lVar5 = (longdouble)(*DAT_001c118c)(0x42200000,0x42a00000);
      *(float *)(*piVar4 + 0x28) = (float)lVar5;
      *(int *)(*piVar4 + 0x144) = param_1[0x128];
    }
    if (param_1[0x12a] != 0) {
      piVar4 = (int *)SpriteCreate__7CSpritePCcRC6Vectori
                                (param_1[0x12a] + (int)gpGlobals[0x26],param_2,1);
      piVar4[3] = -0x10000;
      piVar4[4] = (int)AnimateUntilDead__7CSprite;
      *(undefined4 *)(*piVar4 + 0x138) = 0x42700000;
      *(float *)(*piVar4 + 0x1e4) = (float)piVar4[0x113] / 60.0 + *gpGlobals;
      *(float *)(*piVar4 + 0x104) = *gpGlobals;
      *(undefined4 *)(*piVar4 + 0x148) = 5;
      *(undefined4 *)(*piVar4 + 0x150) = 0x437f0000;
      *(undefined4 *)(*piVar4 + 0x154) = 0x437f0000;
      *(undefined4 *)(*piVar4 + 0x158) = 0x437f0000;
      *(undefined4 *)(*piVar4 + 0x14c) = 0x437f0000;
      *(undefined4 *)(*piVar4 + 0x15c) = 0xe;
      *(int *)(*piVar4 + 0x144) = param_1[0x128];
    }
    SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  }
  param_1[0x11f] = (int)*gpGlobals;
  return;
}


