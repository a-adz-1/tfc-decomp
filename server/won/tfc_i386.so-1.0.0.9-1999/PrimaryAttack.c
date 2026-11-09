// PrimaryAttack__10CTFNailgun  @ 00100640
void PrimaryAttack__10CTFNailgun(int param_1)

{
  int *piVar1;
  float *pfVar2;
  int iVar3;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if (*(int *)(*(int *)(param_1 + 1000) + 0xd4) < 1) {
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x154))(param_1);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0x618) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0x620) = 0x200;
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,5);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 1000),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 1000) + 0x74);
    piVar1 = *(int **)(param_1 + 1000);
    iVar3 = *piVar1;
    local_28 = *(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x154);
    local_24 = *(float *)(iVar3 + 0xc) + *(float *)(iVar3 + 0x158);
    local_20 = *(float *)(iVar3 + 0x10) + *(float *)(iVar3 + 0x15c);
    local_1c = local_28 + gpGlobals[0x10] + gpGlobals[0x10];
    local_18 = local_24 + gpGlobals[0x11] + gpGlobals[0x11];
    local_14 = local_20 + gpGlobals[0x12] + gpGlobals[0x12];
    local_40 = local_1c + gpGlobals[0xd] * -4.0;
    local_3c = local_18 + gpGlobals[0xe] * -4.0;
    local_38 = local_14 + gpGlobals[0xf] * -4.0;
    iVar3 = *piVar1;
    local_34 = *(undefined4 *)(iVar3 + 0x74);
    local_30 = *(undefined4 *)(iVar3 + 0x78);
    local_2c = *(undefined4 *)(iVar3 + 0x7c);
    local_10 = local_40;
    local_c = local_3c;
    local_8 = local_38;
    CreateNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3i(&local_40,&local_34,piVar1,param_1,1);
    iVar3 = (*DAT_00175628)(0,0xf);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),1,"weapons/airgun_1.wav",
               0x3f800000,0x3f4ccccd,0,iVar3 + 0x5e);
    piVar1 = (int *)(*(int *)(param_1 + 1000) + 0xd4);
    *piVar1 = *piVar1 + -1;
    if (*(int *)(*(int *)(param_1 + 1000) + 0xd4) < 0) {
      *(undefined4 *)(*(int *)(param_1 + 1000) + 0xd4) = 0;
    }
    pfVar2 = gpGlobals;
    *(float *)(param_1 + 0x3fc) = *gpGlobals + 0.1;
    *(float *)(param_1 + 0x404) = *pfVar2 + 10.0;
    *(float *)(**(int **)(param_1 + 1000) + 0x68) =
         *(float *)(**(int **)(param_1 + 1000) + 0x68) - 1.0;
  }
  return;
}


// PrimaryAttack__10CTFRailgun  @ 00100e20
void PrimaryAttack__10CTFRailgun(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  longdouble lVar4;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  if (*(int *)(*(int *)(param_1 + 1000) + 0xd4) < 1) {
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x154))(param_1);
    *(float *)(param_1 + 0x3fc) = *gpGlobals + 0.2;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0x618) = 600;
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0x620) = 0x100;
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,1);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 1000),5);
    pbVar1 = (byte *)(**(int **)(param_1 + 1000) + 0xf8);
    *pbVar1 = *pbVar1 | 2;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),1,"weapons/railgun.wav",
               0x3f666666,0x3f4ccccd,0,100);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 1000) + 0x74);
    piVar2 = *(int **)(param_1 + 1000);
    iVar3 = *piVar2;
    fStack_28 = *(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x154);
    fStack_24 = *(float *)(iVar3 + 0xc) + *(float *)(iVar3 + 0x158);
    fStack_20 = *(float *)(iVar3 + 0x10) + *(float *)(iVar3 + 0x15c);
    fStack_1c = fStack_28 + gpGlobals[0x10] + gpGlobals[0x10];
    fStack_18 = fStack_24 + gpGlobals[0x11] + gpGlobals[0x11];
    fStack_14 = fStack_20 + gpGlobals[0x12] + gpGlobals[0x12];
    fStack_40 = fStack_1c + gpGlobals[0xd] * -4.0;
    fStack_3c = fStack_18 + gpGlobals[0xe] * -4.0;
    fStack_38 = fStack_14 + gpGlobals[0xf] * -4.0;
    iVar3 = *piVar2;
    uStack_34 = *(undefined4 *)(iVar3 + 0x74);
    uStack_30 = *(undefined4 *)(iVar3 + 0x78);
    uStack_2c = *(undefined4 *)(iVar3 + 0x7c);
    fStack_10 = fStack_40;
    fStack_c = fStack_3c;
    fStack_8 = fStack_38;
    CreateRailgunNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3
              (&fStack_40,&uStack_34,piVar2,param_1);
    piVar2 = (int *)(*(int *)(param_1 + 1000) + 0xd4);
    *piVar2 = *piVar2 + -1;
    *(float *)(param_1 + 0x3fc) = *gpGlobals + 0.4;
    lVar4 = (longdouble)(*DAT_0017562c)(0x41200000,0x41700000);
    *(float *)(param_1 + 0x404) = (float)(lVar4 + (longdouble)*gpGlobals);
    *(float *)(**(int **)(param_1 + 1000) + 0x68) =
         *(float *)(**(int **)(param_1 + 1000) + 0x68) - 2.0;
  }
  return;
}


// PrimaryAttack__10CTFShotgun  @ 00102120
void PrimaryAttack__10CTFShotgun(int *param_1)

{
  int *piVar1;
  float *pfVar2;
  int iVar3;
  longdouble lVar4;
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
  float local_10;
  float fStack_c;
  float fStack_8;
  
  if (param_1[0x104] < 1) {
    (**(code **)(param_1[0xf2] + 0x16c))(param_1);
    if (param_1[0x104] == 0) {
      (**(code **)(param_1[0xf2] + 0x154))(param_1);
    }
  }
  else {
    *(undefined4 *)(param_1[0xfa] + 0x618) = 1000;
    *(undefined4 *)(param_1[0xfa] + 0x620) = 0x100;
    (**(code **)(param_1[0xf2] + 0x15c))(param_1,1);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0xfa],5);
    iVar3 = *(int *)param_1[0xfa];
    local_10 = *(float *)(iVar3 + 0x74) + *(float *)(iVar3 + 0x68);
    fStack_c = *(float *)(iVar3 + 0x78) + *(float *)(iVar3 + 0x6c);
    fStack_8 = *(float *)(iVar3 + 0x7c) + *(float *)(iVar3 + 0x70);
    UTIL_MakeVectors__FRC6Vector(&local_10);
    piVar1 = (int *)param_1[0xfa];
    lVar4 = (longdouble)(*DAT_0017562c)(0x42480000,0x428c0000);
    fStack_34 = (float)(lVar4 * (longdouble)gpGlobals[0x10]);
    fStack_30 = (float)(lVar4 * (longdouble)gpGlobals[0x11]);
    fStack_2c = (float)(lVar4 * (longdouble)gpGlobals[0x12]);
    iVar3 = *piVar1;
    fStack_20 = *(float *)(iVar3 + 0x28) + fStack_2c;
    fStack_28 = (float)((longdouble)*(float *)(iVar3 + 0x20) + lVar4 * (longdouble)gpGlobals[0x10]);
    fStack_24 = (float)((longdouble)*(float *)(iVar3 + 0x24) + lVar4 * (longdouble)gpGlobals[0x11]);
    lVar4 = (longdouble)(*DAT_0017562c)(0x42c80000,0x43160000);
    local_10 = (float)((longdouble)fStack_28 + lVar4 * (longdouble)gpGlobals[0xd]) +
               gpGlobals[10] * 25.0;
    fStack_c = (float)((longdouble)fStack_24 + lVar4 * (longdouble)gpGlobals[0xe]) +
               gpGlobals[0xb] * 25.0;
    fStack_8 = fStack_20 + (float)(lVar4 * (longdouble)gpGlobals[0xf]) + gpGlobals[0xc] * 25.0;
    iVar3 = *(int *)param_1[0xfa];
    fStack_28 = *(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x154);
    fStack_24 = *(float *)(iVar3 + 0xc) + *(float *)(iVar3 + 0x158);
    fStack_20 = *(float *)(iVar3 + 0x10) + *(float *)(iVar3 + 0x15c);
    fStack_1c = gpGlobals[0xd] * -12.0;
    fStack_18 = gpGlobals[0xe] * -12.0;
    fStack_14 = gpGlobals[0xf] * -12.0;
    fStack_34 = fStack_28 + fStack_1c;
    fStack_30 = fStack_24 + fStack_18;
    fStack_2c = fStack_20 + fStack_14;
    fStack_58 = gpGlobals[10] * 20.0;
    fStack_54 = gpGlobals[0xb] * 20.0;
    fStack_50 = gpGlobals[0xc] * 20.0;
    fStack_40 = fStack_34 + fStack_58;
    fStack_3c = fStack_30 + fStack_54;
    fStack_38 = fStack_2c + fStack_50;
    fStack_64 = gpGlobals[0x10] * 4.0;
    fStack_60 = gpGlobals[0x11] * 4.0;
    fStack_5c = gpGlobals[0x12] * 4.0;
    fStack_4c = fStack_40 + fStack_64;
    fStack_48 = fStack_3c + fStack_60;
    fStack_44 = fStack_38 + fStack_5c;
    EjectBrass__FRC6VectorT0fii
              (&fStack_4c,&local_10,*(undefined4 *)(*param_1 + 0x54),param_1[0x10b],2);
    iVar3 = (*DAT_00175628)(0,0x1f);
    lVar4 = (longdouble)(*DAT_0017562c)(0x3f733333,0x3f800000,0x3f4ccccd,0,iVar3 + 0x5d);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),1,"weapons/sbarrel1.wav",(float)lVar4)
    ;
    GetGunPosition__12CBaseMonster(&fStack_64,param_1[0xfa]);
    GetAutoaimVector__11CBasePlayerf(&fStack_58,param_1[0xfa],0x3db27eb6);
    fStack_4c = fStack_64;
    fStack_48 = fStack_60;
    fStack_44 = fStack_5c;
    fStack_40 = fStack_58;
    fStack_3c = fStack_54;
    fStack_38 = fStack_50;
    fStack_34 = 0.04;
    fStack_30 = 0.04;
    fStack_2c = 0.0;
    FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_t
              (param_1[0xfa],6,&fStack_4c,&fStack_40,&fStack_34,0x45000000,6,0,4,0);
    if ((param_1[0x104] == 0) && (*(int *)(param_1[0xfa] + 0xcc) < 1)) {
      SetSuitUpdate__11CBasePlayerPcii(param_1[0xfa],"!HEV_AMO0",0,0);
    }
    param_1[0x104] = param_1[0x104] + -1;
    *(byte *)(*(int *)param_1[0xfa] + 0xf8) = *(byte *)(*(int *)param_1[0xfa] + 0xf8) | 2;
    pfVar2 = gpGlobals;
    param_1[0x101] = (int)(*gpGlobals + 5.0);
    param_1[0x109] = 0;
    *(byte *)(param_1[0xfa] + 0x88) = *(byte *)(param_1[0xfa] + 0x88) & 0xfd;
    if (param_1[0x104] != 0) {
      param_1[0x10c] = (int)(*pfVar2 + 0.5);
    }
    param_1[0xff] = (int)(*gpGlobals + 0.5);
    *(float *)(*(int *)param_1[0xfa] + 0x68) = *(float *)(*(int *)param_1[0xfa] + 0x68) - 2.0;
  }
  return;
}


// PrimaryAttack__11CTFAssaultC  @ 000f7f00
void PrimaryAttack__11CTFAssaultC(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x42c);
  if (iVar3 == 1) {
    fVar1 = *(float *)(param_1 + 0x3fc);
    fVar2 = *gpGlobals;
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      return;
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),6,"weapons/asscan2.wav",
               0x3f7ae148,0x3f4ccccd,0,0x7d);
    *(undefined4 *)(param_1 + 0x42c) = 2;
    return;
  }
  if (1 < iVar3) {
    if (iVar3 == 2) {
      if (0 < *(int *)(*(int *)(param_1 + 1000) + 0xcc)) {
        Fire__11CTFAssaultC(param_1);
        return;
      }
      Spin__11CTFAssaultC(param_1);
      return;
    }
    if (iVar3 == 3) {
      *(float *)(param_1 + 0x404) = *gpGlobals + 0.1;
      return;
    }
  }
  WindUp__11CTFAssaultC(param_1);
  fVar1 = *gpGlobals;
  *(float *)(param_1 + 0x404) = fVar1 + 0.5;
  *(float *)(param_1 + 0x3fc) = fVar1 + 0.5;
  return;
}


// PrimaryAttack__12CHandGrenade  @ 000bc760
void PrimaryAttack__12CHandGrenade(int param_1)

{
  if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x424)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(param_1 + 0x424) == 0.0) << 0xe) >> 8)) == 0x40) &&
     (0 < *(int *)(*(int *)(param_1 + 0x408) * 4 + *(int *)(param_1 + 1000) + 0x83c))) {
    *(float *)(param_1 + 0x424) = *gpGlobals;
    *(undefined4 *)(param_1 + 0x428) = 0;
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,2);
    *(float *)(param_1 + 0x404) = *gpGlobals + 0.5;
  }
  return;
}


// PrimaryAttack__12CTFAutoRifle  @ 000f8360
void PrimaryAttack__12CTFAutoRifle(undefined4 *param_1)

{
  float *pfVar1;
  int iVar2;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float local_7c;
  float local_78;
  float fStack_74;
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
  undefined1 auStack_40 [16];
  float fStack_30;
  int iStack_10;
  float local_8;
  
  pfVar1 = gpGlobals;
  if (0 < *(int *)(param_1[0xfa] + 0xcc)) {
    *(undefined4 *)(param_1[0xfa] + 0x618) = 600;
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0xfa],5);
    (**(code **)(param_1[0xf2] + 0x15c))(param_1,6);
    local_8 = *gpGlobals + 0.2;
    param_1[0x101] = local_8;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),1,"weapons/sniper.wav",0x3f666666,
               0x3f4ccccd,0,100);
    iVar2 = *(int *)param_1[0xfa];
    local_4c = *(float *)(iVar2 + 0x74) + *(float *)(iVar2 + 0x68);
    local_48 = *(float *)(iVar2 + 0x78) + *(float *)(iVar2 + 0x6c);
    local_44 = *(float *)(iVar2 + 0x7c) + *(float *)(iVar2 + 0x70);
    UTIL_MakeVectors__FRC6Vector(&local_4c);
    GetGunPosition__12CBaseMonster(&local_64,param_1[0xfa]);
    local_58 = local_64 - (gpGlobals[0xd] + gpGlobals[0xd]);
    local_54 = local_60 - (gpGlobals[0xe] + gpGlobals[0xe]);
    local_50 = local_5c - (gpGlobals[0xf] + gpGlobals[0xf]);
    local_70 = gpGlobals[10];
    local_6c = gpGlobals[0xb];
    local_68 = gpGlobals[0xc];
    local_7c = local_70 * 8192.0;
    local_78 = local_6c * 8192.0;
    fStack_74 = local_68 * 8192.0;
    local_64 = local_58 + local_7c;
    local_60 = local_54 + local_78;
    local_5c = local_50 + fStack_74;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_58,&local_64,0,*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),auStack_40);
    if ((byte)(1.0 < fStack_30 | (byte)((ushort)((ushort)NAN(fStack_30) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_30 == 1.0) << 0xe) >> 8)) != 0x40) {
      if ((iStack_10 == 0) && (iStack_10 = (*DAT_001755d4)(0), iStack_10 == 0)) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(iStack_10 + 0xd8);
      }
      if (iVar2 != 0) {
        ClearMultiDamage__Fv();
        local_7c = local_70;
        local_78 = local_6c;
        fStack_74 = local_68;
        (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x30))
                  (iVar2,*(undefined4 *)param_1[0xfa],0x41000000,&local_7c,auStack_40,2);
        ApplyMultiDamage__FP9entvars_tT0(*param_1,*(undefined4 *)param_1[0xfa]);
      }
      local_7c = local_58;
      local_78 = local_54;
      fStack_74 = local_50;
      fStack_88 = local_64;
      fStack_84 = local_60;
      fStack_80 = local_5c;
      TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i(auStack_40,&local_7c,&fStack_88,3);
      DecalGunshot__FP11TraceResulti(auStack_40,3);
    }
    *(int *)(param_1[0xfa] + 0xcc) = *(int *)(param_1[0xfa] + 0xcc) + -1;
    param_1[0xff] = *gpGlobals + 0.1;
    return;
  }
  param_1[0xff] = *gpGlobals + 5.0;
  param_1[0x101] = *pfVar1 + 1.0;
  (**(code **)(param_1[0xf2] + 0x15c))(param_1,0);
  (**(code **)(param_1[0xf2] + 0x154))(param_1);
  return;
}


// PrimaryAttack__13CWeaponCycler  @ 000bbf10
void PrimaryAttack__13CWeaponCycler(int *param_1)

{
  (**(code **)(param_1[0xf2] + 0x15c))(param_1,*(undefined4 *)(*param_1 + 0x108));
  param_1[0xff] = (int)(*gpGlobals + 0.3);
  return;
}


// PrimaryAttack__14CTFIncendiaryC  @ 000ff8c0
void PrimaryAttack__14CTFIncendiaryC(int param_1)

{
  int *piVar1;
  int iVar2;
  float *pfVar3;
  float local_58;
  float local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
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
  
  if (*(int *)(*(int *)(param_1 + 1000) + 0xe4) < 1) {
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x154))(param_1);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0x618) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0x620) = 0x200;
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,3);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 1000),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 1000) + 0x74);
    GetGunPosition__12CBaseMonster(&local_34,*(undefined4 *)(param_1 + 1000));
    local_40 = gpGlobals[10] * 16.0;
    local_3c = gpGlobals[0xb] * 16.0;
    local_38 = gpGlobals[0xc] * 16.0;
    local_28 = local_34 + local_40;
    local_24 = local_30 + local_3c;
    local_20 = local_2c + local_38;
    local_1c = local_28 + gpGlobals[0x10] * 8.0;
    local_18 = local_24 + gpGlobals[0x11] * 8.0;
    local_14 = local_20 + gpGlobals[0x12] * 8.0;
    local_58 = local_1c + gpGlobals[0xd] * -8.0;
    local_54 = local_18 + gpGlobals[0xe] * -8.0;
    local_50 = local_14 + gpGlobals[0xf] * -8.0;
    iVar2 = **(int **)(param_1 + 1000);
    local_4c = *(undefined4 *)(iVar2 + 0x74);
    local_48 = *(undefined4 *)(iVar2 + 0x78);
    local_44 = *(undefined4 *)(iVar2 + 0x7c);
    local_10 = local_58;
    local_c = local_54;
    local_8 = local_50;
    CreateRpgRocket__20CTFIncendiaryCRocketG6VectorT1P11CBaseEntityP14CTFIncendiaryC
              (&local_58,&local_4c,*(int **)(param_1 + 1000),param_1);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 1000) + 0x74);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),1,"weapons/sgun1.wav",0x3f666666,
               0x3f4ccccd,0,100);
    piVar1 = (int *)(*(int *)(param_1 + 1000) + 0xe4);
    *piVar1 = *piVar1 + -1;
    pfVar3 = gpGlobals;
    *(float *)(param_1 + 0x3fc) = *gpGlobals + 1.2;
    *(float *)(param_1 + 0x404) = *pfVar3 + 1.2;
    *(float *)(**(int **)(param_1 + 1000) + 0x68) =
         *(float *)(**(int **)(param_1 + 1000) + 0x68) - 5.0;
  }
  return;
}


// PrimaryAttack__14CTFSniperRifle  @ 00103980
void PrimaryAttack__14CTFSniperRifle(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
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
  undefined1 auStack_40 [16];
  float fStack_30;
  int iStack_10;
  float local_8;
  
  if (0 < *(int *)(param_1[0xfa] + 0xcc)) {
    *(undefined4 *)(param_1[0xfa] + 0x618) = 200;
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0xfa],5);
    (**(code **)(param_1[0xf2] + 0x15c))(param_1,2);
    local_8 = *gpGlobals + 0.5;
    param_1[0x101] = local_8;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),1,"ambience/rifle1.wav",0x3f666666,
               0x3f4ccccd,0,100);
    iVar2 = *(int *)param_1[0xfa];
    local_4c = *(float *)(iVar2 + 0x74) + *(float *)(iVar2 + 0x68);
    local_48 = *(float *)(iVar2 + 0x78) + *(float *)(iVar2 + 0x6c);
    local_44 = *(float *)(iVar2 + 0x7c) + *(float *)(iVar2 + 0x70);
    UTIL_MakeVectors__FRC6Vector(&local_4c);
    GetGunPosition__12CBaseMonster(&local_64,param_1[0xfa]);
    local_58 = local_64 - (gpGlobals[0xd] + gpGlobals[0xd]);
    local_54 = local_60 - (gpGlobals[0xe] + gpGlobals[0xe]);
    local_50 = local_5c - (gpGlobals[0xf] + gpGlobals[0xf]);
    local_70 = gpGlobals[10];
    local_6c = gpGlobals[0xb];
    local_68 = gpGlobals[0xc];
    fStack_7c = local_70 * 8192.0;
    fStack_78 = local_6c * 8192.0;
    fStack_74 = local_68 * 8192.0;
    local_64 = local_58 + fStack_7c;
    local_60 = local_54 + fStack_78;
    local_5c = local_50 + fStack_74;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_58,&local_64,0,*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),auStack_40);
    if ((byte)(1.0 < fStack_30 | (byte)((ushort)((ushort)NAN(fStack_30) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_30 == 1.0) << 0xe) >> 8)) != 0x40) {
      if ((iStack_10 == 0) && (iStack_10 = (*DAT_001755d4)(0), iStack_10 == 0)) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(iStack_10 + 0xd8);
      }
      if (iVar2 != 0) {
        uVar1 = param_1[0xdb];
        ClearMultiDamage__Fv();
        fStack_7c = local_70;
        fStack_78 = local_6c;
        fStack_74 = local_68;
        (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x30))
                  (iVar2,*(undefined4 *)param_1[0xfa],param_1[0x109],&fStack_7c,auStack_40,
                   0x10000002);
        if (*(int *)(param_1[0xfa] + 0x36c) != 0) {
          param_1[0xdb] = *(undefined4 *)(param_1[0xfa] + 0x36c);
        }
        ApplyMultiDamage__FP9entvars_tT0(*param_1,*(undefined4 *)param_1[0xfa]);
        param_1[0xdb] = uVar1;
        *(undefined4 *)(param_1[0xfa] + 0x36c) = 0;
      }
      fStack_7c = local_58;
      fStack_78 = local_54;
      fStack_74 = local_50;
      fStack_88 = local_64;
      fStack_84 = local_60;
      fStack_80 = local_5c;
      TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i(auStack_40,&fStack_7c,&fStack_88,3);
      DecalGunshot__FP11TraceResulti(auStack_40,3);
    }
    *(int *)(param_1[0xfa] + 0xcc) = *(int *)(param_1[0xfa] + 0xcc) + -1;
    param_1[0xff] = *gpGlobals + 1.5;
    return;
  }
  (**(code **)(param_1[0xf2] + 0x154))(param_1);
  return;
}


// PrimaryAttack__15CTFFlamethrower  @ 000faa20
void PrimaryAttack__15CTFFlamethrower(int param_1)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  float *pfVar4;
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
  
  if (*(int *)(*(int *)(param_1 + 1000) + 0xdc) < 1) {
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x154))(param_1);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0x618) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0x620) = 0x200;
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,5);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 1000),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 1000) + 0x74);
    GetGunPosition__12CBaseMonster(&local_34,*(undefined4 *)(param_1 + 1000));
    local_40 = gpGlobals[10] * 16.0;
    local_3c = gpGlobals[0xb] * 16.0;
    local_38 = gpGlobals[0xc] * 16.0;
    local_28 = local_34 + local_40;
    local_24 = local_30 + local_3c;
    local_20 = local_2c + local_38;
    local_1c = local_28 + gpGlobals[0x10] * 8.0;
    local_18 = local_24 + gpGlobals[0x11] * 8.0;
    local_14 = local_20 + gpGlobals[0x12] * 8.0;
    local_58 = local_1c + gpGlobals[0xd] * -8.0;
    local_54 = local_18 + gpGlobals[0xe] * -8.0;
    local_50 = local_14 + gpGlobals[0xf] * -8.0;
    local_10 = local_58;
    local_c = local_54;
    local_8 = local_50;
    if (*(int *)(**(int **)(param_1 + 1000) + 0x1a0) < 3) {
      iVar2 = **(int **)(param_1 + 1000);
      local_4c = *(float *)(iVar2 + 0x74);
      local_48 = *(float *)(iVar2 + 0x78);
      local_44 = *(float *)(iVar2 + 0x7c);
      CreateBurst__20CTFFlamethrowerBurstG6VectorT1P11CBaseEntityP15CTFFlamethrower
                (&local_58,&local_4c,*(int **)(param_1 + 1000),param_1);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),1,"weapons/flmfire2.wav",
                 0x3f666666,0x3f4ccccd,0,100);
      pfVar4 = gpGlobals;
      *(float *)(param_1 + 0x3fc) = *gpGlobals + 0.15;
      fVar3 = *pfVar4 + 0.15;
    }
    else {
      local_40 = gpGlobals[10] * 128.0;
      local_3c = gpGlobals[0xb] * 128.0;
      local_38 = gpGlobals[0xc] * 128.0;
      local_4c = local_58 + local_40;
      local_48 = local_54 + local_3c;
      local_44 = local_50 + local_38;
      UTIL_BubbleTrail__FG6VectorT0i(&local_58,&local_4c,4);
      pfVar4 = gpGlobals;
      *(float *)(param_1 + 0x3fc) = *gpGlobals + 1.0;
      fVar3 = *pfVar4 + 1.0;
    }
    *(float *)(param_1 + 0x404) = fVar3;
    piVar1 = (int *)(*(int *)(param_1 + 1000) + 0xdc);
    *piVar1 = *piVar1 + -1;
  }
  return;
}


// PrimaryAttack__15CTFSuperNailgun  @ 001008d0
void PrimaryAttack__15CTFSuperNailgun(int param_1)

{
  int *piVar1;
  float *pfVar2;
  int iVar3;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if (*(int *)(*(int *)(param_1 + 1000) + 0xd4) < 1) {
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x154))(param_1);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0x618) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0x620) = 0x200;
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,5);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 1000),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 1000) + 0x74);
    piVar1 = *(int **)(param_1 + 1000);
    iVar3 = *piVar1;
    local_28 = *(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x154);
    local_24 = *(float *)(iVar3 + 0xc) + *(float *)(iVar3 + 0x158);
    local_20 = *(float *)(iVar3 + 0x10) + *(float *)(iVar3 + 0x15c);
    local_1c = local_28 + gpGlobals[0x10] + gpGlobals[0x10];
    local_18 = local_24 + gpGlobals[0x11] + gpGlobals[0x11];
    local_14 = local_20 + gpGlobals[0x12] + gpGlobals[0x12];
    local_40 = local_1c + gpGlobals[0xd] * -4.0;
    local_3c = local_18 + gpGlobals[0xe] * -4.0;
    local_38 = local_14 + gpGlobals[0xf] * -4.0;
    local_10 = local_40;
    local_c = local_3c;
    local_8 = local_38;
    if (piVar1[0x35] < 4) {
      iVar3 = *piVar1;
      local_34 = *(undefined4 *)(iVar3 + 0x74);
      local_30 = *(undefined4 *)(iVar3 + 0x78);
      local_2c = *(undefined4 *)(iVar3 + 0x7c);
      CreateNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3i(&local_40,&local_34,piVar1,param_1,1);
    }
    else {
      iVar3 = **(int **)(param_1 + 1000);
      local_34 = *(undefined4 *)(iVar3 + 0x74);
      local_30 = *(undefined4 *)(iVar3 + 0x78);
      local_2c = *(undefined4 *)(iVar3 + 0x7c);
      CreateSuperNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3
                (&local_40,&local_34,*(int **)(param_1 + 1000),param_1);
    }
    iVar3 = (*DAT_00175628)(0,0xf);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),1,"weapons/spike2.wav",0x3f800000
               ,0x3f4ccccd,0,iVar3 + 0x5e);
    piVar1 = (int *)(*(int *)(param_1 + 1000) + 0xd4);
    *piVar1 = *piVar1 + -2;
    if (*(int *)(*(int *)(param_1 + 1000) + 0xd4) < 0) {
      *(undefined4 *)(*(int *)(param_1 + 1000) + 0xd4) = 0;
    }
    pfVar2 = gpGlobals;
    *(float *)(param_1 + 0x3fc) = *gpGlobals + 0.1;
    *(float *)(param_1 + 0x404) = *pfVar2 + 10.0;
    *(float *)(**(int **)(param_1 + 1000) + 0x68) =
         *(float *)(**(int **)(param_1 + 1000) + 0x68) - 1.0;
  }
  return;
}


// PrimaryAttack__15CTFSuperShotgun  @ 00102b40
void PrimaryAttack__15CTFSuperShotgun(int *param_1)

{
  int *piVar1;
  float *pfVar2;
  int iVar3;
  longdouble lVar4;
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
  
  if (param_1[0x104] < 1) {
    (**(code **)(param_1[0xf2] + 0x16c))(param_1);
    if (param_1[0x104] == 0) {
      (**(code **)(param_1[0xf2] + 0x154))(param_1);
    }
  }
  else if (param_1[0x104] == 1) {
    PrimaryAttack__10CTFShotgun(param_1);
  }
  else {
    *(undefined4 *)(param_1[0xfa] + 0x618) = 1000;
    *(undefined4 *)(param_1[0xfa] + 0x620) = 0x100;
    (**(code **)(param_1[0xf2] + 0x15c))(param_1,1);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0xfa],5);
    iVar3 = *(int *)param_1[0xfa];
    local_10 = *(float *)(iVar3 + 0x74) + *(float *)(iVar3 + 0x68);
    local_c = *(float *)(iVar3 + 0x78) + *(float *)(iVar3 + 0x6c);
    local_8 = *(float *)(iVar3 + 0x7c) + *(float *)(iVar3 + 0x70);
    UTIL_MakeVectors__FRC6Vector(&local_10);
    piVar1 = (int *)param_1[0xfa];
    lVar4 = (longdouble)(*DAT_0017562c)(0x42480000,0x428c0000);
    local_34 = (float)(lVar4 * (longdouble)gpGlobals[0x10]);
    local_30 = (float)(lVar4 * (longdouble)gpGlobals[0x11]);
    local_2c = (float)(lVar4 * (longdouble)gpGlobals[0x12]);
    iVar3 = *piVar1;
    local_20 = *(float *)(iVar3 + 0x28) + local_2c;
    local_28 = (float)((longdouble)*(float *)(iVar3 + 0x20) + lVar4 * (longdouble)gpGlobals[0x10]);
    local_24 = (float)((longdouble)*(float *)(iVar3 + 0x24) + lVar4 * (longdouble)gpGlobals[0x11]);
    lVar4 = (longdouble)(*DAT_0017562c)(0x42c80000,0x43160000);
    local_10 = (float)((longdouble)local_28 + lVar4 * (longdouble)gpGlobals[0xd]) +
               gpGlobals[10] * 25.0;
    local_c = (float)((longdouble)local_24 + lVar4 * (longdouble)gpGlobals[0xe]) +
              gpGlobals[0xb] * 25.0;
    local_8 = local_20 + (float)(lVar4 * (longdouble)gpGlobals[0xf]) + gpGlobals[0xc] * 25.0;
    iVar3 = *(int *)param_1[0xfa];
    local_28 = *(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x154);
    local_24 = *(float *)(iVar3 + 0xc) + *(float *)(iVar3 + 0x158);
    local_20 = *(float *)(iVar3 + 0x10) + *(float *)(iVar3 + 0x15c);
    local_1c = gpGlobals[0xd] * -12.0;
    local_18 = gpGlobals[0xe] * -12.0;
    local_14 = gpGlobals[0xf] * -12.0;
    local_34 = local_28 + local_1c;
    local_30 = local_24 + local_18;
    local_2c = local_20 + local_14;
    local_58 = gpGlobals[10] * 20.0;
    local_54 = gpGlobals[0xb] * 20.0;
    local_50 = gpGlobals[0xc] * 20.0;
    local_40 = local_34 + local_58;
    local_3c = local_30 + local_54;
    local_38 = local_2c + local_50;
    local_64 = gpGlobals[0x10] * 4.0;
    local_60 = gpGlobals[0x11] * 4.0;
    local_5c = gpGlobals[0x12] * 4.0;
    local_4c = local_40 + local_64;
    local_48 = local_3c + local_60;
    local_44 = local_38 + local_5c;
    EjectBrass__FRC6VectorT0fii
              (&local_4c,&local_10,*(undefined4 *)(*param_1 + 0x54),param_1[0x10b],2);
    iVar3 = (*DAT_00175628)(0,0x1f);
    lVar4 = (longdouble)(*DAT_0017562c)(0x3f733333,0x3f800000,0x3f4ccccd,0,iVar3 + 0x5d);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),1,"weapons/shotgn2.wav",(float)lVar4);
    GetGunPosition__12CBaseMonster(&local_64,param_1[0xfa]);
    GetAutoaimVector__11CBasePlayerf(&local_58,param_1[0xfa],0x3db27eb6);
    local_4c = local_64;
    local_48 = local_60;
    local_44 = local_5c;
    local_40 = local_58;
    local_3c = local_54;
    local_38 = local_50;
    local_34 = 0.04;
    local_30 = 0.04;
    local_2c = 0.0;
    FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_t
              (param_1[0xfa],0xe,&local_4c,&local_40,&local_34,0x45000000,6,4,4,0);
    if ((param_1[0x104] == 0) && (*(int *)(param_1[0xfa] + 0xcc) < 1)) {
      SetSuitUpdate__11CBasePlayerPcii(param_1[0xfa],"!HEV_AMO0",0,0);
    }
    param_1[0x104] = param_1[0x104] + -2;
    *(byte *)(*(int *)param_1[0xfa] + 0xf8) = *(byte *)(*(int *)param_1[0xfa] + 0xf8) | 2;
    pfVar2 = gpGlobals;
    param_1[0x101] = (int)(*gpGlobals + 5.0);
    param_1[0x109] = 0;
    if (param_1[0x104] != 0) {
      param_1[0x10c] = (int)(*pfVar2 + 0.7);
    }
    param_1[0xff] = (int)(*gpGlobals + 0.7);
    *(float *)(*(int *)param_1[0xfa] + 0x68) = *(float *)(*(int *)param_1[0xfa] + 0x68) - 4.0;
  }
  return;
}


// PrimaryAttack__17CBasePlayerWeapon  @ 0011cb70
void PrimaryAttack__17CBasePlayerWeapon(void)

{
  return;
}


// PrimaryAttack__18CTFGrenadeLauncher  @ 000fba80
void PrimaryAttack__18CTFGrenadeLauncher(int param_1)

{
  byte *pbVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  float local_58;
  float local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
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
  
  if (*(int *)(param_1 + 0x410) == 0) {
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,0);
    *(float *)(param_1 + 0x3fc) = *gpGlobals + 1.0;
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x154))(param_1);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0x618) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0x620) = 0x200;
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,2);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 1000),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 1000) + 0x74);
    GetGunPosition__12CBaseMonster(&local_34,*(undefined4 *)(param_1 + 1000));
    local_40 = gpGlobals[10] * 16.0;
    local_3c = gpGlobals[0xb] * 16.0;
    local_38 = gpGlobals[0xc] * 16.0;
    local_28 = local_34 + local_40;
    local_24 = local_30 + local_3c;
    local_20 = local_2c + local_38;
    local_1c = local_28 + gpGlobals[0x10] * 8.0;
    local_18 = local_24 + gpGlobals[0x11] * 8.0;
    local_14 = local_20 + gpGlobals[0x12] * 8.0;
    local_58 = local_1c + gpGlobals[0xd] * -16.0;
    local_54 = local_18 + gpGlobals[0xe] * -16.0;
    local_50 = local_14 + gpGlobals[0xf] * -16.0;
    iVar3 = **(int **)(param_1 + 1000);
    local_4c = *(undefined4 *)(iVar3 + 0x74);
    local_48 = *(undefined4 *)(iVar3 + 0x78);
    local_44 = *(undefined4 *)(iVar3 + 0x7c);
    local_10 = local_58;
    local_c = local_54;
    local_8 = local_50;
    CreateTFGrenade__10CTFGrenadeG6VectorT1P11CBaseEntityP18CTFGrenadeLauncher
              (&local_58,&local_4c,*(int **)(param_1 + 1000),param_1);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),3,"weapons/glauncher.wav",
               0x3f333333,0x3f4ccccd,0,100);
    *(undefined4 *)(param_1 + 0x424) = 0;
    pbVar1 = (byte *)(*(int *)(param_1 + 1000) + 0x88);
    *pbVar1 = *pbVar1 & 0xfd;
    *(int *)(param_1 + 0x410) = *(int *)(param_1 + 0x410) + -1;
    pfVar4 = gpGlobals;
    fVar2 = *gpGlobals;
    *(float *)(param_1 + 0x400) = fVar2 + 0.6;
    *(float *)(param_1 + 0x3fc) = fVar2 + 0.6;
    *(float *)(param_1 + 0x404) = *pfVar4 + 0.6;
    *(float *)(**(int **)(param_1 + 1000) + 0x68) =
         *(float *)(**(int **)(param_1 + 1000) + 0x68) - 2.0;
  }
  return;
}


// PrimaryAttack__19CTFPipebombLauncher  @ 000fbfc0
void PrimaryAttack__19CTFPipebombLauncher(int param_1)

{
  byte *pbVar1;
  int iVar2;
  float *pfVar3;
  float local_58;
  float local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
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
  
  if (*(int *)(param_1 + 0x410) == 0) {
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x16c))(param_1);
    if (**(int **)(param_1 + 0xb0) == 0) {
      (**(code **)(*(int *)(param_1 + 0x3c8) + 0x154))(param_1);
      (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,1);
      *(float *)(param_1 + 0x3fc) = *gpGlobals + 1.0;
    }
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0x618) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0x620) = 0x200;
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,3);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 1000),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 1000) + 0x74);
    GetGunPosition__12CBaseMonster(&local_34,*(undefined4 *)(param_1 + 1000));
    local_40 = gpGlobals[10] * 16.0;
    local_3c = gpGlobals[0xb] * 16.0;
    local_38 = gpGlobals[0xc] * 16.0;
    local_28 = local_34 + local_40;
    local_24 = local_30 + local_3c;
    local_20 = local_2c + local_38;
    local_1c = local_28 + gpGlobals[0x10] * 8.0;
    local_18 = local_24 + gpGlobals[0x11] * 8.0;
    local_14 = local_20 + gpGlobals[0x12] * 8.0;
    local_58 = local_1c + gpGlobals[0xd] * -16.0;
    local_54 = local_18 + gpGlobals[0xe] * -16.0;
    local_50 = local_14 + gpGlobals[0xf] * -16.0;
    iVar2 = **(int **)(param_1 + 1000);
    local_4c = *(undefined4 *)(iVar2 + 0x74);
    local_48 = *(undefined4 *)(iVar2 + 0x78);
    local_44 = *(undefined4 *)(iVar2 + 0x7c);
    local_10 = local_58;
    local_c = local_54;
    local_8 = local_50;
    CreateTFPipebomb__10CTFGrenadeG6VectorT1P11CBaseEntityP18CTFGrenadeLauncher
              (&local_58,&local_4c,*(int **)(param_1 + 1000),param_1);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),3,"weapons/glauncher.wav",
               0x3f333333,0x3f4ccccd,0,100);
    *(undefined4 *)(param_1 + 0x424) = 0;
    pbVar1 = (byte *)(*(int *)(param_1 + 1000) + 0x88);
    *pbVar1 = *pbVar1 & 0xfd;
    *(int *)(param_1 + 0x410) = *(int *)(param_1 + 0x410) + -1;
    pfVar3 = gpGlobals;
    *(float *)(param_1 + 0x3fc) = *gpGlobals + 0.6;
    *(float *)(param_1 + 0x404) = *pfVar3 + 0.6;
    *(float *)(**(int **)(param_1 + 1000) + 0x68) =
         *(float *)(**(int **)(param_1 + 1000) + 0x68) - 2.0;
  }
  return;
}


// PrimaryAttack__6CTFAxe  @ 000f8c40
void PrimaryAttack__6CTFAxe(int *param_1)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  longdouble lVar7;
  float fStack_a0;
  float fStack_9c;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float local_60;
  float local_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float local_48;
  float fStack_44;
  float fStack_40;
  int aiStack_3c [4];
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  int iStack_c;
  
  param_1[0x127] = 0;
  UTIL_MakeVectors__FRC6Vector(*(int *)param_1[0xfa] + 0x74);
  GetGunPosition__12CBaseMonster(&local_48,param_1[0xfa]);
  local_60 = gpGlobals[10] * 32.0;
  local_5c = gpGlobals[0xb] * 32.0;
  fStack_58 = gpGlobals[0xc] * 32.0;
  fStack_54 = local_48 + local_60;
  fStack_50 = fStack_44 + local_5c;
  fStack_4c = fStack_40 + fStack_58;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_48,&fStack_54,0,*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),aiStack_3c);
  if ((byte)((1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
             (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) - 1) < 0x40) {
    param_1[0x127] = 1;
    UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
              (&local_48,&fStack_54,0,3,*(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8),aiStack_3c);
    if (fStack_2c < 1.0) {
      iVar2 = iStack_c;
      if ((iStack_c == 0) && (iVar2 = (*DAT_001755d4)(0), iVar2 == 0)) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(iVar2 + 0xd8);
      }
      if ((iVar2 == 0) || (iVar2 = (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x8c))(iVar2), iVar2 != 0)
         ) {
        local_60 = 16.0;
        local_5c = 16.0;
        fStack_58 = 18.0;
        fStack_6c = -16.0;
        fStack_68 = -16.0;
        fStack_64 = -18.0;
        FindHullIntersection__FRC6VectorR11TraceResultPfT2P7edict_s
                  (&local_48,aiStack_3c,&fStack_6c,&local_60,
                   *(undefined4 *)(*(int *)param_1[0xfa] + 0x1e8));
      }
      fStack_54 = fStack_28;
      fStack_50 = fStack_24;
      fStack_4c = fStack_20;
    }
  }
  if (0x3f < (byte)((1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) - 1)) {
    if ((iStack_c == 0) && (iStack_c = (*DAT_001755d4)(0), iStack_c == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iStack_c + 0xd8);
    }
    (**(code **)(param_1[0xf2] + 0x180))(param_1,1);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0xfa],5);
    fStack_9c = 1.0;
    fStack_6c = gpGlobals[10];
    fStack_68 = gpGlobals[0xb];
    fStack_64 = gpGlobals[0xc];
    iVar3 = (**(code **)(param_1[0xf2] + 0x17c))(param_1,iVar2,&fStack_6c,aiStack_3c);
    pfVar1 = gpGlobals;
    param_1[0xff] = (int)(*gpGlobals + 0.4);
    param_1[0x101] = (int)(*pfVar1 + 5.0);
    if (iVar3 != 0) {
      if (((iVar2 != 0) &&
          (iVar4 = (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x28))(iVar2), iVar4 != 0)) &&
         (iVar4 = (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x28))(iVar2), iVar4 != 1)) {
        (**(code **)(param_1[0xf2] + 0x184))(param_1,1,0);
        *(undefined4 *)(param_1[0xfa] + 0x618) = 0x80;
        iVar2 = (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x88))(iVar2);
        if (iVar2 == 0) {
          return;
        }
        fStack_9c = 0.1;
        iVar3 = 0;
      }
      if (iVar3 != 0) {
        fStack_6c = local_48;
        fStack_68 = fStack_44;
        fStack_64 = fStack_40;
        local_60 = local_48 + (fStack_54 - local_48) + (fStack_54 - local_48);
        local_5c = fStack_44 + (fStack_50 - fStack_44) + (fStack_50 - fStack_44);
        fStack_58 = fStack_40 + (fStack_4c - fStack_40) + (fStack_4c - fStack_40);
        lVar7 = (longdouble)
                TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i(aiStack_3c,&fStack_6c,&local_60,5)
        ;
        fStack_a0 = (float)lVar7;
        iVar2 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules);
        if (iVar2 != 0) {
          fStack_a0 = 1.0;
        }
        (**(code **)(param_1[0xf2] + 0x184))(param_1,2,fStack_a0);
      }
    }
    piVar5 = aiStack_3c;
    piVar6 = param_1 + 0x119;
    for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar6 = *piVar5;
      piVar5 = piVar5 + 1;
      piVar6 = piVar6 + 1;
    }
    param_1[3] = -0x10000;
    param_1[4] = (int)Smack__6CTFAxe;
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.2;
    *(int *)(param_1[0xfa] + 0x618) = (int)ROUND(fStack_9c * 512.0);
    return;
  }
  (**(code **)(param_1[0xf2] + 0x180))(param_1,0);
  (**(code **)(param_1[0xf2] + 0x184))(param_1,0,0);
  pfVar1 = gpGlobals;
  param_1[0xff] = (int)(*gpGlobals + 0.4);
  param_1[0x101] = (int)(*pfVar1 + 5.0);
  SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0xfa],5);
  return;
}


// PrimaryAttack__6CTFRpg  @ 00101a50
void PrimaryAttack__6CTFRpg(int param_1)

{
  byte *pbVar1;
  int iVar2;
  float *pfVar3;
  float local_58;
  float local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
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
  
  if (*(int *)(param_1 + 0x410) == 0) {
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x154))(param_1);
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x16c))(param_1);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0x618) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0x620) = 0x200;
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,2);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 1000),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 1000) + 0x74);
    GetGunPosition__12CBaseMonster(&local_34,*(undefined4 *)(param_1 + 1000));
    local_40 = gpGlobals[10] * 16.0;
    local_3c = gpGlobals[0xb] * 16.0;
    local_38 = gpGlobals[0xc] * 16.0;
    local_28 = local_34 + local_40;
    local_24 = local_30 + local_3c;
    local_20 = local_2c + local_38;
    local_1c = local_28 + gpGlobals[0x10] * 8.0;
    local_18 = local_24 + gpGlobals[0x11] * 8.0;
    local_14 = local_20 + gpGlobals[0x12] * 8.0;
    local_58 = local_1c + gpGlobals[0xd] * -8.0;
    local_54 = local_18 + gpGlobals[0xe] * -8.0;
    local_50 = local_14 + gpGlobals[0xf] * -8.0;
    iVar2 = **(int **)(param_1 + 1000);
    local_4c = *(undefined4 *)(iVar2 + 0x74);
    local_48 = *(undefined4 *)(iVar2 + 0x78);
    local_44 = *(undefined4 *)(iVar2 + 0x7c);
    local_10 = local_58;
    local_c = local_54;
    local_8 = local_50;
    CreateRpgRocket__12CTFRpgRocketG6VectorT1P11CBaseEntityP6CTFRpg
              (&local_58,&local_4c,*(int **)(param_1 + 1000),param_1);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 1000) + 0x74);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),1,"weapons/rocketfire1.wav",
               0x3f666666,0x3f4ccccd,0,100);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),3,"weapons/glauncher.wav",
               0x3f333333,0x3f4ccccd,0,100);
    *(undefined4 *)(param_1 + 0x424) = 0;
    pbVar1 = (byte *)(*(int *)(param_1 + 1000) + 0x88);
    *pbVar1 = *pbVar1 & 0xfd;
    *(int *)(param_1 + 0x410) = *(int *)(param_1 + 0x410) + -1;
    pfVar3 = gpGlobals;
    *(float *)(param_1 + 0x3fc) = *gpGlobals + 0.8;
    *(float *)(param_1 + 0x404) = *pfVar3 + 0.8;
    *(float *)(**(int **)(param_1 + 1000) + 0x68) =
         *(float *)(**(int **)(param_1 + 1000) + 0x68) - 5.0;
  }
  return;
}


// PrimaryAttack__8CCrowbar  @ 000a6860
void PrimaryAttack__8CCrowbar(int *param_1)

{
  int iVar1;
  
  iVar1 = Swing__8CCrowbari(param_1,1);
  if (iVar1 == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SwingAgain__8CCrowbar;
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  }
  return;
}


// PrimaryAttack__8CTFTranq  @ 00103fa0
void PrimaryAttack__8CTFTranq(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  longdouble lVar4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(*(int *)(param_1 + 1000) + 0xcc) < 1) {
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x154))(param_1);
    *(float *)(param_1 + 0x3fc) = *gpGlobals + 0.2;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0x618) = 600;
    *(undefined4 *)(*(int *)(param_1 + 1000) + 0x620) = 0x100;
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,3);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 1000),5);
    pbVar1 = (byte *)(**(int **)(param_1 + 1000) + 0xf8);
    *pbVar1 = *pbVar1 | 2;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),1,"weapons/dartgun.wav",
               0x3f666666,0x3f4ccccd,0,100);
    GetGunPosition__12CBaseMonster(&local_10,*(undefined4 *)(param_1 + 1000));
    local_1c = local_10;
    local_18 = local_c;
    local_14 = local_8;
    iVar3 = **(int **)(param_1 + 1000);
    local_28 = *(undefined4 *)(iVar3 + 0x74);
    local_24 = *(undefined4 *)(iVar3 + 0x78);
    local_20 = *(undefined4 *)(iVar3 + 0x7c);
    CreateTranqNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3
              (&local_1c,&local_28,*(int **)(param_1 + 1000),param_1);
    piVar2 = (int *)(*(int *)(param_1 + 1000) + 0xcc);
    *piVar2 = *piVar2 + -1;
    *(float *)(param_1 + 0x3fc) = *gpGlobals + 1.5;
    lVar4 = (longdouble)(*DAT_0017562c)(0x41200000,0x41700000);
    *(float *)(param_1 + 0x404) = (float)(lVar4 + (longdouble)*gpGlobals);
    *(float *)(**(int **)(param_1 + 1000) + 0x68) =
         *(float *)(**(int **)(param_1 + 1000) + 0x68) - 2.0;
  }
  return;
}


