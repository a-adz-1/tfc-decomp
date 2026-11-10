// Fire__11CTFAssaultC  @ 000f7810
void Fire__11CTFAssaultC(int *param_1)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  float fVar5;
  longdouble lVar6;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float local_10;
  float local_c;
  float local_8;
  
  if ((float)param_1[0xff] <= *gpGlobals) {
    *(undefined4 *)(param_1[0xfa] + 0x618) = 600;
    *(undefined4 *)(param_1[0xfa] + 0x620) = 0x100;
    (**(code **)(param_1[0xf2] + 0x15c))(param_1,4);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0xfa],5);
    *(byte *)(*(int *)param_1[0xfa] + 0xf8) = *(byte *)(*(int *)param_1[0xfa] + 0xf8) | 2;
    if ((*(byte *)((int *)param_1[0xfa] + 0x33) & 1) != 0) {
      iVar2 = *(int *)param_1[0xfa];
      local_10 = *(float *)(iVar2 + 0x74) + *(float *)(iVar2 + 0x68);
      local_c = *(float *)(iVar2 + 0x78) + *(float *)(iVar2 + 0x6c);
      local_8 = *(float *)(iVar2 + 0x7c) + *(float *)(iVar2 + 0x70);
      UTIL_MakeVectors__FRC6Vector(&local_10);
      piVar3 = (int *)param_1[0xfa];
      lVar6 = (longdouble)(*DAT_0017562c)(0x42480000,0x428c0000);
      local_34 = (float)(lVar6 * (longdouble)gpGlobals[0x10]);
      local_30 = (float)(lVar6 * (longdouble)gpGlobals[0x11]);
      local_2c = (float)(lVar6 * (longdouble)gpGlobals[0x12]);
      iVar2 = *piVar3;
      local_20 = *(float *)(iVar2 + 0x28) + local_2c;
      local_28 = (float)((longdouble)*(float *)(iVar2 + 0x20) + lVar6 * (longdouble)gpGlobals[0x10])
      ;
      local_24 = (float)((longdouble)*(float *)(iVar2 + 0x24) + lVar6 * (longdouble)gpGlobals[0x11])
      ;
      lVar6 = (longdouble)(*DAT_0017562c)(0x42c80000,0x43160000);
      local_10 = (float)((longdouble)local_28 + lVar6 * (longdouble)gpGlobals[0xd]) +
                 gpGlobals[10] * 25.0;
      local_c = (float)((longdouble)local_24 + lVar6 * (longdouble)gpGlobals[0xe]) +
                gpGlobals[0xb] * 25.0;
      local_8 = local_20 + (float)(lVar6 * (longdouble)gpGlobals[0xf]) + gpGlobals[0xc] * 25.0;
      iVar2 = *(int *)param_1[0xfa];
      local_28 = *(float *)(*param_1 + 8) + *(float *)(iVar2 + 0x154);
      local_24 = *(float *)(*param_1 + 0xc) + *(float *)(iVar2 + 0x158);
      local_20 = *(float *)(*param_1 + 0x10) + *(float *)(iVar2 + 0x15c);
      fStack_1c = gpGlobals[0xd] * -12.0;
      fStack_18 = gpGlobals[0xe] * -12.0;
      fStack_14 = gpGlobals[0xf] * -12.0;
      local_34 = local_28 + fStack_1c;
      local_30 = local_24 + fStack_18;
      local_2c = local_20 + fStack_14;
      fStack_58 = gpGlobals[10] * 20.0;
      fStack_54 = gpGlobals[0xb] * 20.0;
      fStack_50 = gpGlobals[0xc] * 20.0;
      fStack_40 = local_34 + fStack_58;
      fStack_3c = local_30 + fStack_54;
      fStack_38 = local_2c + fStack_50;
      fStack_4c = fStack_40 + gpGlobals[0x10] * 4.0;
      fStack_48 = fStack_3c + gpGlobals[0x11] * 4.0;
      fStack_44 = fStack_38 + gpGlobals[0x12] * 4.0;
      EjectBrass__FRC6VectorT0fii
                (&fStack_4c,&local_10,*(undefined4 *)(*param_1 + 0x54),param_1[0x10a],1);
    }
    UTIL_MakeVectors__FRC6Vector(*(int *)param_1[0xfa] + 0x74);
    piVar3 = (int *)param_1[0xfa];
    iVar2 = *piVar3;
    fStack_4c = *(float *)(iVar2 + 8) + *(float *)(iVar2 + 0x154);
    fStack_48 = *(float *)(*piVar3 + 0xc) + *(float *)(iVar2 + 0x158);
    fStack_44 = *(float *)(*piVar3 + 0x10) + *(float *)(iVar2 + 0x15c);
    fStack_40 = gpGlobals[0x10] + gpGlobals[0x10];
    fStack_3c = gpGlobals[0x11] + gpGlobals[0x11];
    fStack_38 = gpGlobals[0x12] + gpGlobals[0x12];
    fStack_58 = fStack_4c + fStack_40;
    fStack_54 = fStack_48 + fStack_3c;
    fStack_50 = fStack_44 + fStack_38;
    local_34 = gpGlobals[0xd] * -4.0;
    local_30 = gpGlobals[0xe] * -4.0;
    local_2c = gpGlobals[0xf] * -4.0;
    fVar4 = fStack_58 + local_34;
    fVar1 = fStack_54 + local_30;
    fVar5 = fStack_50 + local_2c;
    GetAutoaimVector__11CBasePlayerf(&fStack_58,piVar3,0x3db27eb6);
    fStack_40 = fStack_58;
    fStack_3c = fStack_54;
    fStack_38 = fStack_50;
    local_34 = 0.1;
    local_30 = 0.1;
    local_2c = 0.0;
    fStack_4c = fVar4;
    fStack_48 = fVar1;
    fStack_44 = fVar5;
    FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_t
              (param_1[0xfa],5,&fStack_4c,&fStack_40,&local_34,0x46000000,7,8,8,0);
    param_1[0x10c] = (int)ROUND((float)param_1[0x10c] + 0.1);
    *(int *)(param_1[0xfa] + 0xcc) = *(int *)(param_1[0xfa] + 0xcc) + -1;
    fVar1 = *gpGlobals;
    param_1[0x101] = (int)(fVar1 + 0.1);
    param_1[0xff] = (int)(fVar1 + 0.1);
    lVar6 = (longdouble)(*DAT_0017562c)((float)-param_1[0x10c],(float)param_1[0x10c]);
    *(float *)(*(int *)param_1[0xfa] + 0x68) = (float)lVar6;
    lVar6 = (longdouble)(*DAT_0017562c)((float)-param_1[0x10c],(float)param_1[0x10c]);
    *(float *)(*(int *)param_1[0xfa] + 0x6c) = (float)lVar6;
    lVar6 = (longdouble)(*DAT_0017562c)((float)-param_1[0x10c],(float)param_1[0x10c]);
    *(float *)(*(int *)param_1[0xfa] + 0x70) = (float)lVar6;
  }
  return;
}


// Fire__12CFuncTankGunRC6VectorT1P9entvars_t  @ 000b5980
void Fire__12CFuncTankGunRC6VectorT1P9entvars_t
               (int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined2 in_FPUControlWord;
  undefined4 *puVar5;
  undefined4 uVar6;
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
  
  fVar2 = (float)param_1[0x100];
  if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
    UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
    _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
    local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
    iVar1 = (int)ROUND((*gpGlobals - (float)param_1[0x100]) * (float)param_1[0x101]);
    if (iVar1 < 1) {
      return;
    }
    local_38 = 0;
    if (0 < iVar1) {
      do {
        iVar3 = param_1[0x10c];
        if (iVar3 == 1) {
          local_1c = *param_2;
          local_18 = param_2[1];
          local_14 = param_2[2];
          local_28 = *param_3;
          local_24 = param_3[1];
          local_20 = param_3[2];
          iVar3 = param_1[0x111] * 0xc;
          local_34 = *(undefined4 *)(gTankSpread + iVar3);
          local_30 = *(undefined4 *)(gTankSpread + iVar3 + 4);
          local_2c = *(undefined4 *)(gTankSpread + iVar3 + 8);
          iVar3 = param_1[0x10d];
          uVar6 = 8;
          puVar4 = &local_1c;
          puVar5 = &local_34;
LAB_000b5b6a:
          FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_t
                    (param_1,1,puVar4,&local_28,puVar5,0x45800000,uVar6,1,iVar3,param_4);
        }
        else if (1 < iVar3) {
          if (iVar3 == 2) {
            local_34 = *param_2;
            local_30 = param_2[1];
            local_2c = param_2[2];
            local_28 = *param_3;
            local_24 = param_3[1];
            local_20 = param_3[2];
            iVar3 = param_1[0x111] * 0xc;
            local_1c = *(undefined4 *)(gTankSpread + iVar3);
            local_18 = *(undefined4 *)(gTankSpread + iVar3 + 4);
            local_14 = *(undefined4 *)(gTankSpread + iVar3 + 8);
            iVar3 = param_1[0x10d];
            uVar6 = 9;
          }
          else {
            if (iVar3 != 3) goto LAB_000b5b76;
            local_34 = *param_2;
            local_30 = param_2[1];
            local_2c = param_2[2];
            local_28 = *param_3;
            local_24 = param_3[1];
            local_20 = param_3[2];
            iVar3 = param_1[0x111] * 0xc;
            local_1c = *(undefined4 *)(gTankSpread + iVar3);
            local_18 = *(undefined4 *)(gTankSpread + iVar3 + 4);
            local_14 = *(undefined4 *)(gTankSpread + iVar3 + 8);
            iVar3 = param_1[0x10d];
            uVar6 = 10;
          }
          puVar4 = &local_34;
          puVar5 = &local_1c;
          goto LAB_000b5b6a;
        }
LAB_000b5b76:
        local_38 = local_38 + 1;
      } while (local_38 < iVar1);
    }
  }
  Fire__9CFuncTankRC6VectorT1P9entvars_t(param_1,param_2,param_3,param_4);
  return;
}


// Fire__12CTFSentrygun  @ 000e9ef0
undefined4 Fire__12CTFSentrygun(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  longdouble lVar6;
  char *pcVar7;
  undefined4 uVar8;
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
  
  SetSentryAnim__12CTFSentrygun13TFTURRET_ANIM(param_1,1);
  UTIL_MakeAimVectors__FRC6Vector(param_1 + 0x188);
  piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x11c);
  iVar3 = *piVar4;
  local_1c = *(float *)(iVar3 + 8) - *(float *)(*param_1 + 8);
  local_18 = *(float *)(iVar3 + 0xc) - *(float *)(*param_1 + 0xc);
  local_14 = *(float *)(iVar3 + 0x10) - *(float *)(*param_1 + 0x10);
  local_20 = SQRT(local_14 * local_14 + local_18 * local_18 + local_1c * local_1c);
  if ((byte)((byte)((ushort)((ushort)NAN(local_20) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_20 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_10 = 0.0;
    local_c = 0.0;
    local_8 = 1.0;
  }
  else {
    local_8 = 1.0 / local_20;
    local_10 = local_8 * local_1c;
    local_c = local_8 * local_18;
    local_8 = local_8 * local_14;
  }
  *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 2;
  if ((param_1[0x24] == 3) && (0 < param_1[0x39])) {
    fVar1 = (float)param_1[0xea];
    fVar2 = *gpGlobals;
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) goto LAB_000ea160;
    if ((*(byte *)(param_1 + 0x39) & 1) == 0) {
      uVar8 = 2;
    }
    else {
      uVar8 = 3;
    }
    GetAttachment__14CBaseAnimatingiR6VectorT2(param_1,uVar8,&local_20,&local_2c);
    local_38 = local_20;
    local_34 = local_1c;
    local_30 = local_18;
    local_44 = local_2c;
    local_40 = local_28;
    local_3c = local_24;
    uVar8 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x51,0);
    piVar4 = (int *)CreateRpgRocket__12CTFRpgRocketG6VectorT1P11CBaseEntityP6CTFRpg
                              (&local_38,&local_44,uVar8);
    piVar4[0xdb] = (int)"sentrygun" - (int)gpGlobals[0x26];
    iVar3 = *piVar4;
    local_44 = local_10 * 800.0;
    local_40 = local_c * 800.0;
    local_3c = local_8 * 800.0;
    *(float *)(iVar3 + 0x20) = local_44;
    *(float *)(iVar3 + 0x24) = local_40;
    *(float *)(iVar3 + 0x28) = local_3c;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),3,"weapons/rocketfire1.wav",0x3f800000,0x3f4ccccd,0
               ,100);
    param_1[0xea] = (int)(*gpGlobals + 3.0);
    param_1[0x39] = param_1[0x39] + -1;
    if (param_1[0x39] == 10) {
      puVar5 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x51,1,"#Sentry_rocketslow",0,0,0,0);
      ClientPrint__FP9entvars_tiPCcN42(*puVar5);
    }
    if (param_1[0x39] == 0) {
      puVar5 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x51,1,"#Sentry_rocketsout",0,0,0,0);
      ClientPrint__FP9entvars_tiPCcN42(*puVar5);
    }
    if (param_1[0x33] < 1) {
      return 0;
    }
  }
  else {
LAB_000ea160:
    if (param_1[0x33] < 1) goto LAB_000ea23f;
  }
  if ((param_1[0x24] == 3) && ((*(byte *)(param_1 + 0x33) & 1) != 0)) {
    uVar8 = 1;
  }
  else {
    uVar8 = 0;
  }
  GetAttachment__14CBaseAnimatingiR6VectorT2(param_1,uVar8,&local_44,&local_38);
  local_2c = local_44;
  local_28 = local_40;
  local_24 = local_3c;
  local_20 = local_10;
  local_1c = local_c;
  local_18 = local_8;
  local_50 = g_vecZero;
  local_4c = DAT_00175484;
  local_48 = DAT_00175488;
  puVar5 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x51);
  FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_t
            (param_1,1,&local_2c,&local_20,&local_50,0x45000000,8,4,0x10,*puVar5);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x1e8),3,"weapons/pl_gun3.wav",0x3f800000,0x3f4ccccd,0,100);
  param_1[0x33] = param_1[0x33] + -1;
LAB_000ea23f:
  if ((param_1[0x33] != 0) ||
     (lVar6 = (longdouble)(*DAT_0017562c)(0,0x3f800000), (longdouble)0.1 <= lVar6)) {
    if (param_1[0x33] != 0x14) {
      return 1;
    }
    pcVar7 = "#Sentry_shellslow";
  }
  else {
    pcVar7 = "#Sentry_shellsout";
  }
  puVar5 = (undefined4 *)__rf__7EHANDLE(param_1 + 0x51,1,pcVar7,0,0,0,0);
  ClientPrint__FP9entvars_tiPCcN42(*puVar5);
  return 1;
}


// Fire__14CFuncTankLaserRC6VectorT1P9entvars_t  @ 000b5e10
void Fire__14CFuncTankLaserRC6VectorT1P9entvars_t
               (int *param_1,undefined4 *param_2,undefined4 param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_3c [56];
  
  fVar1 = (float)param_1[0x100];
  if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
     (iVar3 = GetLaser__14CFuncTankLaser(param_1), iVar3 != 0)) {
    UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
    iVar3 = (int)ROUND((*gpGlobals - (float)param_1[0x100]) * (float)param_1[0x101]);
    if (iVar3 == 0) {
      return;
    }
    if (0 < iVar3) {
      iVar4 = 0;
      do {
        iVar2 = *(int *)param_1[0x112];
        *(undefined4 *)(iVar2 + 8) = *param_2;
        *(undefined4 *)(iVar2 + 0xc) = param_2[1];
        *(undefined4 *)(iVar2 + 0x10) = param_2[2];
        TankTrace__9CFuncTankRC6VectorN21R11TraceResult
                  (param_1,param_2,param_3,gTankSpread + param_1[0x111] * 0xc,local_3c);
        param_1[0x113] = (int)*gpGlobals;
        TurnOn__6CLaser(param_1[0x112]);
        *(float *)(*(int *)param_1[0x112] + 0x1c4) = *gpGlobals - 1.0;
        FireAtPoint__6CLaserR11TraceResult(param_1[0x112],local_3c);
        *(undefined4 *)(*(int *)param_1[0x112] + 0xe4) = 0;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar3);
    }
  }
  Fire__9CFuncTankRC6VectorT1P9entvars_t(param_1,param_2,param_3,*param_1);
  return;
}


// Fire__15CFuncTankMortarRC6VectorT1P9entvars_t  @ 000b60a0
void Fire__15CFuncTankMortarRC6VectorT1P9entvars_t
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
  
  fVar1 = (float)param_1[0x100];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
    local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
    if ((int)ROUND((*gpGlobals - (float)param_1[0x100]) * (float)param_1[0x101]) < 1) {
      return;
    }
    UTIL_MakeAimVectors__FRC6Vector(*param_1 + 0x50);
    TankTrace__9CFuncTankRC6VectorN21R11TraceResult
              (param_1,param_2,param_3,gTankSpread + param_1[0x111] * 0xc,local_48);
    iVar2 = *param_1;
    ExplosionCreate__FRC6VectorT0P7edict_sii
              (local_34,iVar2 + 0x50,*(undefined4 *)(iVar2 + 0x1e8),*(undefined4 *)(iVar2 + 0x164),1
              );
  }
  Fire__9CFuncTankRC6VectorT1P9entvars_t(param_1,param_2,param_3,*param_1);
  return;
}


// Fire__15CFuncTankRocketRC6VectorT1P9entvars_t  @ 000b5f90
void Fire__15CFuncTankRocketRC6VectorT1P9entvars_t
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  float fVar2;
  int iVar3;
  
  fVar2 = (float)param_1[0x100];
  if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
    iVar1 = (int)ROUND((*gpGlobals - (float)param_1[0x100]) * (float)param_1[0x101]);
    if (iVar1 < 1) {
      return;
    }
    iVar3 = 0;
    if (0 < iVar1) {
      do {
        Create__11CBaseEntityPcRC6VectorT2P7edict_s
                  ("rpg_rocket",param_2,*param_1 + 0x50,*(undefined4 *)(*param_1 + 0x1e8));
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
    }
  }
  Fire__9CFuncTankRC6VectorT1P9entvars_t(param_1,param_2,param_3,*param_1);
  return;
}


// Fire__9CFuncTankRC6VectorT1P9entvars_t  @ 000b54c0
void Fire__9CFuncTankRC6VectorT1P9entvars_t(int *param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int *piVar5;
  longdouble lVar6;
  
  fVar1 = (float)param_1[0x100];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if (param_1[0x10a] != 0) {
      piVar5 = (int *)SpriteCreate__7CSpritePCcRC6Vectori
                                (param_1[0x10a] + (int)gpGlobals[0x26],param_2,1);
      lVar6 = (longdouble)(*DAT_0017562c)(0x41700000,0x41a00000);
      piVar5[3] = -0x10000;
      piVar5[4] = (int)AnimateUntilDead__7CSprite;
      *(float *)(*piVar5 + 0x118) = (float)lVar6;
      pfVar4 = gpGlobals;
      *(float *)(*piVar5 + 0x1c4) =
           (float)((longdouble)(float)piVar5[0xf4] / lVar6 + (longdouble)*gpGlobals);
      *(float *)(*piVar5 + 0xe4) = *pfVar4;
      fVar1 = *(float *)(*param_1 + 0x130);
      fVar2 = *(float *)(*param_1 + 0x134);
      fVar3 = *(float *)(*param_1 + 0x138);
      *(undefined4 *)(*piVar5 + 0x128) = 4;
      *(float *)(*piVar5 + 0x130) = (float)(int)ROUND(fVar1);
      *(float *)(*piVar5 + 0x134) = (float)(int)ROUND(fVar2);
      *(float *)(*piVar5 + 0x138) = (float)(int)ROUND(fVar3);
      *(undefined4 *)(*piVar5 + 300) = 0x437f0000;
      *(undefined4 *)(*piVar5 + 0x13c) = 0;
      lVar6 = (longdouble)(*DAT_0017562c)(0x42200000,0x42a00000);
      *(float *)(*piVar5 + 0x28) = (float)lVar6;
      *(int *)(*piVar5 + 0x124) = param_1[0x109];
    }
    if (param_1[0x10b] != 0) {
      piVar5 = (int *)SpriteCreate__7CSpritePCcRC6Vectori
                                (param_1[0x10b] + (int)gpGlobals[0x26],param_2,1);
      piVar5[3] = -0x10000;
      piVar5[4] = (int)AnimateUntilDead__7CSprite;
      *(undefined4 *)(*piVar5 + 0x118) = 0x42700000;
      pfVar4 = gpGlobals;
      *(float *)(*piVar5 + 0x1c4) = (float)piVar5[0xf4] / 60.0 + *gpGlobals;
      *(float *)(*piVar5 + 0xe4) = *pfVar4;
      *(undefined4 *)(*piVar5 + 0x128) = 5;
      *(undefined4 *)(*piVar5 + 0x130) = 0x437f0000;
      *(undefined4 *)(*piVar5 + 0x134) = 0x437f0000;
      *(undefined4 *)(*piVar5 + 0x138) = 0x437f0000;
      *(undefined4 *)(*piVar5 + 300) = 0x437f0000;
      *(undefined4 *)(*piVar5 + 0x13c) = 0xe;
      *(int *)(*piVar5 + 0x124) = param_1[0x109];
    }
    SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
  }
  param_1[0x100] = (int)*gpGlobals;
  return;
}


