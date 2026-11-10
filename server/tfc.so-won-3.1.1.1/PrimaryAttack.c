// PrimaryAttack__10CTFNailgun  @ 0012efe8
void PrimaryAttack__10CTFNailgun(int param_1)

{
  int *piVar1;
  int iVar2;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  if (*(int *)(*(int *)(param_1 + 0x474) + 0xd4) < 1) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x160))(param_1);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6bc) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6c4) = 0x200;
    (*DAT_0019f88c)(1,*(undefined4 *)(**(int **)(param_1 + 0x474) + 0x208),
                    *(undefined2 *)(param_1 + 0x4d0),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x474),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x474) + 0x74);
    piVar1 = *(int **)(param_1 + 0x474);
    iVar2 = *piVar1;
    local_28 = *(float *)(iVar2 + 8) + *(float *)(iVar2 + 0x174);
    local_24 = *(float *)(iVar2 + 0xc) + *(float *)(iVar2 + 0x178);
    local_20 = *(float *)(iVar2 + 0x10) + *(float *)(iVar2 + 0x17c);
    local_1c = local_28 + *(float *)(gpGlobals + 0x40) + *(float *)(gpGlobals + 0x40);
    local_18 = local_24 + *(float *)(gpGlobals + 0x44) + *(float *)(gpGlobals + 0x44);
    fStack_14 = local_20 + *(float *)(gpGlobals + 0x48) + *(float *)(gpGlobals + 0x48);
    fStack_40 = local_1c + *(float *)(gpGlobals + 0x34) * -4.0;
    fStack_3c = local_18 + *(float *)(gpGlobals + 0x38) * -4.0;
    fStack_38 = fStack_14 + *(float *)(gpGlobals + 0x3c) * -4.0;
    iVar2 = *piVar1;
    local_34 = *(undefined4 *)(iVar2 + 0x74);
    local_30 = *(undefined4 *)(iVar2 + 0x78);
    local_2c = *(undefined4 *)(iVar2 + 0x7c);
    fStack_10 = fStack_40;
    fStack_c = fStack_3c;
    fStack_8 = fStack_38;
    CreateNail__14CTFNailgunNailiG6VectorT2P11CBaseEntityT4i
              (0,&fStack_40,&local_34,piVar1,param_1,1);
    DB_LogShots__17CBasePlayerWeaponl(param_1,1);
    piVar1 = (int *)(*(int *)(param_1 + 0x474) + 0xd4);
    *piVar1 = *piVar1 + -1;
    if (*(int *)(*(int *)(param_1 + 0x474) + 0xd4) < 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x474) + 0xd4) = 0;
    }
    *(undefined4 *)(param_1 + 0x488) = 0x3dcccccd;
    *(undefined4 *)(param_1 + 0x490) = 0x41200000;
  }
  return;
}


// PrimaryAttack__10CTFRailgun  @ 0012f8c8
void PrimaryAttack__10CTFRailgun(int param_1)

{
  byte *pbVar1;
  int *piVar2;
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
  
  if (*(int *)(*(int *)(param_1 + 0x474) + 0xd4) < 1) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x160))(param_1);
    *(undefined4 *)(param_1 + 0x488) = 0x3e4ccccd;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6bc) = 600;
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6c4) = 0x100;
    (*DAT_0019f88c)(1,*(undefined4 *)(**(int **)(param_1 + 0x474) + 0x208),
                    *(undefined2 *)(param_1 + 0x4d0),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    pbVar1 = (byte *)(**(int **)(param_1 + 0x474) + 0x118);
    *pbVar1 = *pbVar1 | 2;
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x474),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x474) + 0x74);
    piVar2 = *(int **)(param_1 + 0x474);
    iVar3 = *piVar2;
    local_28 = *(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x174);
    local_24 = *(float *)(iVar3 + 0xc) + *(float *)(iVar3 + 0x178);
    local_20 = *(float *)(iVar3 + 0x10) + *(float *)(iVar3 + 0x17c);
    local_1c = local_28 + *(float *)(gpGlobals + 0x40) + *(float *)(gpGlobals + 0x40);
    local_18 = local_24 + *(float *)(gpGlobals + 0x44) + *(float *)(gpGlobals + 0x44);
    local_14 = local_20 + *(float *)(gpGlobals + 0x48) + *(float *)(gpGlobals + 0x48);
    local_40 = local_1c + *(float *)(gpGlobals + 0x34) * -4.0;
    local_3c = local_18 + *(float *)(gpGlobals + 0x38) * -4.0;
    local_38 = local_14 + *(float *)(gpGlobals + 0x3c) * -4.0;
    iVar3 = *piVar2;
    local_34 = *(undefined4 *)(iVar3 + 0x74);
    local_30 = *(undefined4 *)(iVar3 + 0x78);
    local_2c = *(undefined4 *)(iVar3 + 0x7c);
    local_10 = local_40;
    local_c = local_3c;
    local_8 = local_38;
    CreateRailgunNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3
              (&local_40,&local_34,piVar2,param_1);
    DB_LogShots__17CBasePlayerWeaponl(param_1,1);
    piVar2 = (int *)(*(int *)(param_1 + 0x474) + 0xd4);
    *piVar2 = *piVar2 + -1;
    *(undefined4 *)(param_1 + 0x488) = 0x3ecccccd;
    *(undefined4 *)(param_1 + 0x490) = 0x41480000;
  }
  return;
}


// PrimaryAttack__10CTFShotgun  @ 00130770
void PrimaryAttack__10CTFShotgun(int param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if (*(int *)(param_1 + 0x4c0) < 1) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x178))(param_1);
    if (*(int *)(param_1 + 0x4c0) == 0) {
      (**(code **)(*(int *)(param_1 + 0x454) + 0x160))(param_1);
    }
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6bc) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6c4) = 0x100;
    (*DAT_0019f88c)(1,*(undefined4 *)(**(int **)(param_1 + 0x474) + 0x208),
                    *(undefined2 *)(param_1 + 0x4e0),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x474),5);
    GetGunPosition__12CBaseMonster(&uStack_10,*(undefined4 *)(param_1 + 0x474));
    GetAutoaimVector__11CBasePlayerf(&uStack_1c,*(undefined4 *)(param_1 + 0x474),0x3db27eb6);
    uStack_28 = uStack_10;
    uStack_24 = uStack_c;
    uStack_20 = uStack_8;
    uStack_34 = uStack_1c;
    uStack_30 = uStack_18;
    uStack_2c = uStack_14;
    uStack_40 = 0x3d23d70a;
    uStack_38 = 0;
    uStack_3c = uStack_40;
    FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_s
              (*(undefined4 *)(param_1 + 0x474),6,&uStack_28,&uStack_34,&uStack_40,0x45000000,6,0,4,
               0);
    DB_LogShots__17CBasePlayerWeaponl(param_1,1);
    iVar2 = *(int *)(param_1 + 0x4c0);
    if ((iVar2 == 0) && (*(int *)(*(int *)(param_1 + 0x474) + 0xcc) < 1)) {
      SetSuitUpdate__11CBasePlayerPcii(*(int *)(param_1 + 0x474),&UNK_0015b4fa,0,0);
      iVar2 = *(int *)(param_1 + 0x4c0);
    }
    *(int *)(param_1 + 0x4c0) = iVar2 + -1;
    pbVar1 = (byte *)(**(int **)(param_1 + 0x474) + 0x118);
    *pbVar1 = *pbVar1 | 2;
    *(undefined4 *)(param_1 + 0x490) = 0x40a00000;
    *(undefined4 *)(param_1 + 0x4b4) = 0;
    pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x84);
    *pbVar1 = *pbVar1 & 0xfd;
    if (*(int *)(param_1 + 0x4c0) != 0) {
      *(undefined4 *)(param_1 + 0x498) = 0x3f000000;
    }
    *(undefined4 *)(param_1 + 0x488) = 0x3f000000;
  }
  return;
}


// PrimaryAttack__11CTFAssaultC  @ 0012a1f8
void PrimaryAttack__11CTFAssaultC(void)

{
  FUN_0012a202();
  return;
}


// PrimaryAttack__12CHandGrenade  @ 000b4e98
void PrimaryAttack__12CHandGrenade(int param_1)

{
  if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x4d0)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(param_1 + 0x4d0) == 0.0) << 0xe) >> 8)) == 0x40) &&
     (0 < *(int *)(*(int *)(param_1 + 0x4b8) * 4 + *(int *)(param_1 + 0x474) + 0x8ec))) {
    *(undefined4 *)(param_1 + 0x4d0) = *gpGlobals;
    *(undefined4 *)(param_1 + 0x4d4) = 0;
    (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,2,0);
    *(undefined4 *)(param_1 + 0x490) = 0x3f000000;
  }
  return;
}


// PrimaryAttack__12CTFAutoRifle  @ 0012a938
void PrimaryAttack__12CTFAutoRifle(undefined4 *param_1)

{
  int iVar1;
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
  undefined1 local_3c [16];
  float local_2c;
  int local_c;
  
  if (0 < ((int *)param_1[0x11d])[0x33]) {
    (*DAT_0019f88c)(1,*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),
                    *(undefined2 *)(param_1 + 0x134),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    *(undefined4 *)(param_1[0x11d] + 0x6bc) = 600;
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0x11d],5);
    param_1[0x124] = 0x3e4ccccd;
    iVar1 = *(int *)param_1[0x11d];
    local_48 = *(float *)(iVar1 + 0x74) + *(float *)(iVar1 + 0x68);
    local_44 = *(float *)(iVar1 + 0x78) + *(float *)(iVar1 + 0x6c);
    local_40 = *(float *)(iVar1 + 0x7c) + *(float *)(iVar1 + 0x70);
    UTIL_MakeVectors__FRC6Vector(&local_48);
    GetGunPosition__12CBaseMonster(&local_60,param_1[0x11d]);
    local_54 = local_60 - (*(float *)(gpGlobals + 0x34) + *(float *)(gpGlobals + 0x34));
    local_50 = local_5c - (*(float *)(gpGlobals + 0x38) + *(float *)(gpGlobals + 0x38));
    local_4c = local_58 - (*(float *)(gpGlobals + 0x3c) + *(float *)(gpGlobals + 0x3c));
    local_6c = *(float *)(gpGlobals + 0x28);
    local_78 = local_6c * 8192.0;
    local_60 = local_54 + local_78;
    local_68 = *(float *)(gpGlobals + 0x2c);
    local_74 = local_68 * 8192.0;
    local_5c = local_50 + local_74;
    local_64 = *(float *)(gpGlobals + 0x30);
    local_70 = local_64 * 8192.0;
    local_58 = local_4c + local_70;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_54,&local_60,0,*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),local_3c);
    DB_LogShots__17CBasePlayerWeaponl(param_1,1);
    if ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) != 0x40) {
      if ((local_c == 0) && (local_c = (*DAT_0019f7b4)(0), local_c == 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(local_c + 0x7c);
      }
      if (iVar1 != 0) {
        ClearMultiDamage__Fv();
        local_78 = local_6c;
        local_74 = local_68;
        local_70 = local_64;
        (**(code **)(*(int *)(iVar1 + 0x454) + 0x34))
                  (iVar1,*(undefined4 *)param_1[0x11d],0x41000000,&local_78,local_3c,2);
        ApplyMultiDamage__FP9entvars_sT0(*param_1,*(undefined4 *)param_1[0x11d]);
      }
    }
    *(int *)(param_1[0x11d] + 0xcc) = *(int *)(param_1[0x11d] + 0xcc) + -1;
    param_1[0x122] = 0x3dcccccd;
    return;
  }
  param_1[0x122] = 0x40a00000;
  param_1[0x124] = 0x3f800000;
  (**(code **)(param_1[0x115] + 0x168))(param_1,0,1);
  (**(code **)(param_1[0x115] + 0x160))(param_1);
  return;
}


// PrimaryAttack__13CWeaponCycler  @ 000b3f58
void PrimaryAttack__13CWeaponCycler(int *param_1)

{
  (**(code **)(param_1[0x115] + 0x168))(param_1,*(undefined4 *)(*param_1 + 0x128),0);
  param_1[0x122] = 0x3e99999a;
  return;
}


// PrimaryAttack__14CTFIncendiaryC  @ 0012e84c
void PrimaryAttack__14CTFIncendiaryC(int param_1)

{
  int *piVar1;
  int iVar2;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  if (*(int *)(*(int *)(param_1 + 0x474) + 0xe4) < 1) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x160))(param_1);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6bc) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6c4) = 0x200;
    (*DAT_0019f88c)(1,*(undefined4 *)(**(int **)(param_1 + 0x474) + 0x208),
                    *(undefined2 *)(param_1 + 0x4d0),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x474),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x474) + 0x74);
    GetGunPosition__12CBaseMonster(&local_34,*(undefined4 *)(param_1 + 0x474));
    local_40 = *(float *)(gpGlobals + 0x28) * 16.0;
    local_3c = *(float *)(gpGlobals + 0x2c) * 16.0;
    local_38 = *(float *)(gpGlobals + 0x30) * 16.0;
    local_28 = local_40 + local_34;
    local_24 = local_3c + local_30;
    local_20 = local_38 + local_2c;
    fStack_1c = local_28 + *(float *)(gpGlobals + 0x40) * 8.0;
    fStack_18 = local_24 + *(float *)(gpGlobals + 0x44) * 8.0;
    fStack_14 = local_20 + *(float *)(gpGlobals + 0x48) * 8.0;
    fStack_58 = fStack_1c + *(float *)(gpGlobals + 0x34) * -8.0;
    fStack_54 = fStack_18 + *(float *)(gpGlobals + 0x38) * -8.0;
    fStack_50 = fStack_14 + *(float *)(gpGlobals + 0x3c) * -8.0;
    iVar2 = **(int **)(param_1 + 0x474);
    uStack_4c = *(undefined4 *)(iVar2 + 0x74);
    uStack_48 = *(undefined4 *)(iVar2 + 0x78);
    uStack_44 = *(undefined4 *)(iVar2 + 0x7c);
    fStack_10 = fStack_58;
    fStack_c = fStack_54;
    fStack_8 = fStack_50;
    CreateRpgRocket__20CTFIncendiaryCRocketG6VectorT1P11CBaseEntityP14CTFIncendiaryC
              (&fStack_58,&uStack_4c,*(int **)(param_1 + 0x474),param_1);
    DB_LogShots__17CBasePlayerWeaponl(param_1,1);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x474) + 0x74);
    piVar1 = (int *)(*(int *)(param_1 + 0x474) + 0xe4);
    *piVar1 = *piVar1 + -1;
    *(undefined4 *)(param_1 + 0x488) = 0x3f99999a;
    *(undefined4 *)(param_1 + 0x490) = 0x3f99999a;
  }
  return;
}


// PrimaryAttack__14CTFSniperRifle  @ 001319a8
void PrimaryAttack__14CTFSniperRifle(undefined4 *param_1)

{
  float fVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined2 in_FPUControlWord;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *piStack_98;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
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
  undefined1 auStack_48 [16];
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  int iStack_18;
  int local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  if (*(int *)(param_1[0x11d] + 0xcc) < 1) {
    (**(code **)(param_1[0x115] + 0x160))(param_1);
    return;
  }
  *(undefined4 *)(param_1[0x11d] + 0x6bc) = 200;
  _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
  local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
  (*DAT_0019f88c)(1,*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),*(undefined2 *)(param_1 + 0x136)
                  ,0,&g_vecZero,&g_vecZero,0,0,(int)ROUND((float)param_1[0x128]),0,0,0);
  SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0x11d],5);
  param_1[0x124] = 0x3f000000;
  iVar3 = *(int *)param_1[0x11d];
  fStack_54 = *(float *)(iVar3 + 0x74) + *(float *)(iVar3 + 0x68);
  fStack_50 = *(float *)(iVar3 + 0x78) + *(float *)(iVar3 + 0x6c);
  fStack_4c = *(float *)(iVar3 + 0x7c) + *(float *)(iVar3 + 0x70);
  UTIL_MakeVectors__FRC6Vector(&fStack_54);
  GetGunPosition__12CBaseMonster(&fStack_6c,param_1[0x11d]);
  fStack_60 = fStack_6c - (*(float *)(gpGlobals + 0x34) + *(float *)(gpGlobals + 0x34));
  fStack_5c = fStack_68 - (*(float *)(gpGlobals + 0x38) + *(float *)(gpGlobals + 0x38));
  fStack_58 = fStack_64 - (*(float *)(gpGlobals + 0x3c) + *(float *)(gpGlobals + 0x3c));
  fStack_78 = *(float *)(gpGlobals + 0x28);
  fStack_84 = fStack_78 * 8192.0;
  fStack_6c = fStack_60 + fStack_84;
  fStack_74 = *(float *)(gpGlobals + 0x2c);
  fStack_80 = fStack_74 * 8192.0;
  fStack_68 = fStack_5c + fStack_80;
  fStack_70 = *(float *)(gpGlobals + 0x30);
  fStack_7c = fStack_70 * 8192.0;
  fStack_64 = fStack_58 + fStack_7c;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&fStack_60,&fStack_6c,0,*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),auStack_48);
  if ((byte)(1.0 < fStack_38 | (byte)((ushort)((ushort)NAN(fStack_38) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_38 == 1.0) << 0xe) >> 8)) == 0x40) {
    bVar5 = false;
    uVar8 = 0;
    iVar3 = 0x19;
LAB_00131df6:
    uVar2 = *(undefined2 *)((int)param_1 + 0x4da);
    uVar7 = *(undefined4 *)(*(int *)param_1[0x11d] + 0x208);
    uVar6 = 0x30;
  }
  else {
    if ((iStack_18 == 0) && (iStack_18 = (*DAT_0019f7b4)(0), iStack_18 == 0)) {
      piStack_98 = (int *)0x0;
    }
    else {
      piStack_98 = *(int **)(iStack_18 + 0x7c);
    }
    if (piStack_98 == (int *)0x0) goto LAB_00131e2a;
    uVar8 = param_1[0xfe];
    ClearMultiDamage__Fv();
    fStack_84 = fStack_78;
    fStack_80 = fStack_74;
    fStack_7c = fStack_70;
    (**(code **)(piStack_98[0x115] + 0x34))
              (piStack_98,*(undefined4 *)param_1[0x11d],param_1[0x128],&fStack_84,auStack_48,
               0x10000002);
    iVar3 = ((undefined4 *)param_1[0x11d])[0xfe];
    if (iVar3 != 0) {
      param_1[0xfe] = iVar3;
    }
    ApplyMultiDamage__FP9entvars_sT0(*param_1,*(undefined4 *)param_1[0x11d]);
    param_1[0xfe] = uVar8;
    *(undefined4 *)(param_1[0x11d] + 0x3f8) = 0;
    iVar3 = strcmp((char *)(*(int *)*piStack_98 + *(int *)(gpGlobals + 0x98)),"player");
    bVar5 = iVar3 == 0;
    iVar3 = 0x3c;
    if (bVar5) {
      iVar3 = 0x55;
    }
    iVar4 = 0x5a;
    if (bVar5) {
      iVar4 = 100;
    }
    fStack_84 = fStack_34 - fStack_60;
    fStack_80 = fStack_30 - fStack_5c;
    fStack_7c = fStack_2c - fStack_58;
    fVar1 = SQRT(fStack_7c * fStack_7c + fStack_80 * fStack_80 + fStack_84 * fStack_84);
    if ((byte)((fVar1 < 1024.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 1024.0) << 0xe) >> 8)) - 1) < 0x40) {
      _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
      local_10 = (int)ROUND((1.0 - fVar1 / 1024.0) * (float)(iVar4 - iVar3) + (float)iVar3);
      iVar3 = local_10;
      if (iVar4 < local_10) {
        iVar3 = iVar4;
      }
    }
    if (bVar5) {
      fVar1 = *(float *)(*piStack_98 + 0x160);
      bVar5 = 0x3f < (byte)((-40.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar1 == -40.0) << 0xe) >> 8)) - 1);
      if (bVar5) {
        iVar3 = 0;
      }
      uVar8 = 1;
      goto LAB_00131df6;
    }
    bVar5 = false;
    uVar8 = 0;
    uVar2 = *(undefined2 *)((int)param_1 + 0x4da);
    uVar7 = *(undefined4 *)(*(int *)param_1[0x11d] + 0x208);
    uVar6 = 0x34;
  }
  (*DAT_0019f88c)(uVar6,uVar7,uVar2,0,&g_vecZero,&g_vecZero,0,0,iVar3,0,uVar8,bVar5);
LAB_00131e2a:
  *(int *)(param_1[0x11d] + 0xcc) = *(int *)(param_1[0x11d] + 0xcc) + -1;
  DB_LogShots__17CBasePlayerWeaponl(param_1,1);
  param_1[0x122] = 0x3fc00000;
  return;
}


// PrimaryAttack__15CTFFlamethrower  @ 0012d4d8
void PrimaryAttack__15CTFFlamethrower(void)

{
  FUN_0012d4e5();
  return;
}


// PrimaryAttack__15CTFSuperNailgun  @ 0012f1dc
void PrimaryAttack__15CTFSuperNailgun(int param_1)

{
  int *piVar1;
  int iVar2;
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
  
  if (*(int *)(*(int *)(param_1 + 0x474) + 0xd4) < 1) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x160))(param_1);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6bc) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6c4) = 0x200;
    (*DAT_0019f88c)(1,*(undefined4 *)(**(int **)(param_1 + 0x474) + 0x208),
                    *(undefined2 *)(param_1 + 0x4d4),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x474),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x474) + 0x74);
    piVar1 = *(int **)(param_1 + 0x474);
    iVar2 = *piVar1;
    local_28 = *(float *)(iVar2 + 8) + *(float *)(iVar2 + 0x174);
    local_24 = *(float *)(iVar2 + 0xc) + *(float *)(iVar2 + 0x178);
    local_20 = *(float *)(iVar2 + 0x10) + *(float *)(iVar2 + 0x17c);
    local_1c = local_28 + *(float *)(gpGlobals + 0x40) + *(float *)(gpGlobals + 0x40);
    local_18 = local_24 + *(float *)(gpGlobals + 0x44) + *(float *)(gpGlobals + 0x44);
    local_14 = local_20 + *(float *)(gpGlobals + 0x48) + *(float *)(gpGlobals + 0x48);
    local_40 = local_1c + *(float *)(gpGlobals + 0x34) * -4.0;
    local_3c = local_18 + *(float *)(gpGlobals + 0x38) * -4.0;
    local_38 = local_14 + *(float *)(gpGlobals + 0x3c) * -4.0;
    local_10 = local_40;
    local_c = local_3c;
    local_8 = local_38;
    if (piVar1[0x35] < 4) {
      iVar2 = *piVar1;
      local_34 = *(undefined4 *)(iVar2 + 0x74);
      local_30 = *(undefined4 *)(iVar2 + 0x78);
      local_2c = *(undefined4 *)(iVar2 + 0x7c);
      CreateNail__14CTFNailgunNailiG6VectorT2P11CBaseEntityT4i
                (0,&local_40,&local_34,piVar1,param_1,1);
    }
    else {
      iVar2 = *piVar1;
      local_34 = *(undefined4 *)(iVar2 + 0x74);
      local_30 = *(undefined4 *)(iVar2 + 0x78);
      local_2c = *(undefined4 *)(iVar2 + 0x7c);
      CreateSuperNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3
                (&local_40,&local_34,piVar1,param_1);
    }
    DB_LogShots__17CBasePlayerWeaponl(param_1,1);
    piVar1 = (int *)(*(int *)(param_1 + 0x474) + 0xd4);
    *piVar1 = *piVar1 + -2;
    if (*(int *)(*(int *)(param_1 + 0x474) + 0xd4) < 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x474) + 0xd4) = 0;
    }
    *(undefined4 *)(param_1 + 0x488) = 0x3dcccccd;
    *(undefined4 *)(param_1 + 0x490) = 0x41200000;
  }
  return;
}


// PrimaryAttack__15CTFSuperShotgun  @ 00130e6c
void PrimaryAttack__15CTFSuperShotgun(int param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if (*(int *)(param_1 + 0x4c0) < 1) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x178))(param_1);
    if (*(int *)(param_1 + 0x4c0) == 0) {
      (**(code **)(*(int *)(param_1 + 0x454) + 0x160))(param_1);
    }
  }
  else if (*(int *)(param_1 + 0x4c0) == 1) {
    PrimaryAttack__10CTFShotgun(param_1);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6bc) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6c4) = 0x100;
    (*DAT_0019f88c)(1,*(undefined4 *)(**(int **)(param_1 + 0x474) + 0x208),
                    *(undefined2 *)(param_1 + 0x4e4),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    pbVar1 = (byte *)(**(int **)(param_1 + 0x474) + 0x118);
    *pbVar1 = *pbVar1 | 2;
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x474),5);
    GetGunPosition__12CBaseMonster(&uStack_10,*(undefined4 *)(param_1 + 0x474));
    GetAutoaimVector__11CBasePlayerf(&uStack_1c,*(undefined4 *)(param_1 + 0x474),0x3db27eb6);
    uStack_28 = uStack_10;
    uStack_24 = uStack_c;
    uStack_20 = uStack_8;
    uStack_34 = uStack_1c;
    uStack_30 = uStack_18;
    uStack_2c = uStack_14;
    uStack_40 = 0x3d23d70a;
    uStack_38 = 0;
    uStack_3c = uStack_40;
    FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_s
              (*(undefined4 *)(param_1 + 0x474),0xe,&uStack_28,&uStack_34,&uStack_40,0x45000000,6,4,
               4,0);
    DB_LogShots__17CBasePlayerWeaponl(param_1,1);
    iVar2 = *(int *)(param_1 + 0x4c0);
    if ((iVar2 == 0) && (*(int *)(*(int *)(param_1 + 0x474) + 0xcc) < 1)) {
      SetSuitUpdate__11CBasePlayerPcii(*(int *)(param_1 + 0x474),&UNK_0015b4fa,0,0);
      iVar2 = *(int *)(param_1 + 0x4c0);
    }
    *(int *)(param_1 + 0x4c0) = iVar2 + -2;
    *(undefined4 *)(param_1 + 0x490) = 0x40a00000;
    *(undefined4 *)(param_1 + 0x4b4) = 0;
    if (iVar2 + -2 != 0) {
      *(undefined4 *)(param_1 + 0x498) = 0x3f333333;
    }
    *(undefined4 *)(param_1 + 0x488) = 0x3f333333;
  }
  return;
}


// PrimaryAttack__17CBasePlayerWeapon  @ 0012659c
void PrimaryAttack__17CBasePlayerWeapon(void)

{
  return;
}


// PrimaryAttack__18CTFGrenadeLauncher  @ 0012dc98
void PrimaryAttack__18CTFGrenadeLauncher(int param_1)

{
  byte *pbVar1;
  int iVar2;
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
  
  if (*(int *)(param_1 + 0x4c0) == 0) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,*(undefined4 *)(param_1 + 0x4d8),1);
    *(undefined4 *)(param_1 + 0x488) = 0x3f800000;
    (**(code **)(*(int *)(param_1 + 0x454) + 0x160))(param_1);
    *(undefined4 *)(param_1 + 0x4b4) = 0;
    pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x84);
    *pbVar1 = *pbVar1 & 0xfd;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6bc) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6c4) = 0x200;
    (*DAT_0019f88c)(1,*(undefined4 *)(**(int **)(param_1 + 0x474) + 0x208),
                    *(undefined2 *)(param_1 + 0x4e4),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x474),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x474) + 0x74);
    GetGunPosition__12CBaseMonster(&local_28,*(undefined4 *)(param_1 + 0x474));
    local_1c = *(float *)(gpGlobals + 0x40) * 8.0 + local_28;
    local_18 = *(float *)(gpGlobals + 0x44) * 8.0 + local_24;
    local_14 = *(float *)(gpGlobals + 0x48) * 8.0 + local_20;
    local_40 = local_1c + *(float *)(gpGlobals + 0x34) * -16.0;
    local_3c = local_18 + *(float *)(gpGlobals + 0x38) * -16.0;
    local_38 = local_14 + *(float *)(gpGlobals + 0x3c) * -16.0;
    iVar2 = **(int **)(param_1 + 0x474);
    local_34 = *(undefined4 *)(iVar2 + 0x74);
    local_30 = *(undefined4 *)(iVar2 + 0x78);
    local_2c = *(undefined4 *)(iVar2 + 0x7c);
    local_10 = local_40;
    local_c = local_3c;
    local_8 = local_38;
    CreateTFGrenade__10CTFGrenadeG6VectorT1P11CBaseEntityP18CTFGrenadeLauncher
              (&local_40,&local_34,*(int **)(param_1 + 0x474),param_1);
    DB_LogShots__17CBasePlayerWeaponl(param_1,1);
    *(undefined4 *)(param_1 + 0x4b4) = 0;
    pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x84);
    *pbVar1 = *pbVar1 & 0xfd;
    *(int *)(param_1 + 0x4c0) = *(int *)(param_1 + 0x4c0) + -1;
    *(undefined4 *)(param_1 + 0x48c) = 0x3f19999a;
    *(undefined4 *)(param_1 + 0x488) = 0x3f19999a;
    *(undefined4 *)(param_1 + 0x490) = 0x3f19999a;
  }
  return;
}


// PrimaryAttack__19CTFPipebombLauncher  @ 0012dea0
void PrimaryAttack__19CTFPipebombLauncher(int param_1)

{
  byte *pbVar1;
  int iVar2;
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
  
  if (*(int *)(param_1 + 0x4c0) == 0) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x178))(param_1);
    if (*(int *)(*(int *)(param_1 + 0x474) + 0xe4) == 0) {
      (**(code **)(*(int *)(param_1 + 0x454) + 0x160))(param_1);
      (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,*(undefined4 *)(param_1 + 0x4d8),1);
      *(undefined4 *)(param_1 + 0x488) = 0x3f800000;
    }
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6bc) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6c4) = 0x200;
    (*DAT_0019f88c)(1,*(undefined4 *)(**(int **)(param_1 + 0x474) + 0x208),
                    *(undefined2 *)(param_1 + 0x4e4),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x474),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x474) + 0x74);
    GetGunPosition__12CBaseMonster(&local_28,*(undefined4 *)(param_1 + 0x474));
    local_1c = *(float *)(gpGlobals + 0x40) * 8.0 + local_28;
    local_18 = *(float *)(gpGlobals + 0x44) * 8.0 + local_24;
    local_14 = *(float *)(gpGlobals + 0x48) * 8.0 + local_20;
    local_40 = local_1c + *(float *)(gpGlobals + 0x34) * -16.0;
    local_3c = local_18 + *(float *)(gpGlobals + 0x38) * -16.0;
    local_38 = local_14 + *(float *)(gpGlobals + 0x3c) * -16.0;
    iVar2 = **(int **)(param_1 + 0x474);
    local_34 = *(undefined4 *)(iVar2 + 0x74);
    local_30 = *(undefined4 *)(iVar2 + 0x78);
    local_2c = *(undefined4 *)(iVar2 + 0x7c);
    local_10 = local_40;
    local_c = local_3c;
    local_8 = local_38;
    CreateTFPipebomb__10CTFGrenadeG6VectorT1P11CBaseEntityP18CTFGrenadeLauncher
              (&local_40,&local_34,*(int **)(param_1 + 0x474),param_1);
    DB_LogShots__17CBasePlayerWeaponl(param_1,1);
    *(undefined4 *)(param_1 + 0x4b4) = 0;
    pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x84);
    *pbVar1 = *pbVar1 & 0xfd;
    *(int *)(param_1 + 0x4c0) = *(int *)(param_1 + 0x4c0) + -1;
    *(undefined4 *)(param_1 + 0x488) = 0x3f19999a;
    *(undefined4 *)(param_1 + 0x490) = 0x3f19999a;
  }
  return;
}


// PrimaryAttack__6CTFAxe  @ 0012b088
void PrimaryAttack__6CTFAxe(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  float local_84;
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
  int local_3c [4];
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  int local_c;
  
  param_1[0x152] = 0;
  UTIL_MakeVectors__FRC6Vector(*(int *)param_1[0x11d] + 0x74);
  GetGunPosition__12CBaseMonster(&local_48,param_1[0x11d]);
  local_60 = gpGlobals[10] * 32.0;
  local_5c = gpGlobals[0xb] * 32.0;
  local_58 = gpGlobals[0xc] * 32.0;
  local_54 = local_60 + local_48;
  local_50 = local_5c + local_44;
  local_4c = local_58 + local_40;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_48,&local_54,0,*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),local_3c);
  DB_LogShots__17CBasePlayerWeaponl(param_1,1);
  (*DAT_0019f88c)(1,*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),(short)param_1[0x153],0,
                  &g_vecZero,&g_vecZero,0,0,param_1[0x154],0,0,0);
  if (1.0 <= local_2c) {
    param_1[0x152] = 1;
    UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
              (&local_48,&local_54,0,3,*(undefined4 *)(*(int *)param_1[0x11d] + 0x208),local_3c);
    if (0x3f < (byte)((1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                      (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) - 1)) {
      iVar1 = local_c;
      if ((local_c == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0x7c);
      }
      if ((iVar1 == 0) || (iVar1 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x90))(iVar1), iVar1 != 0)
         ) {
        local_60 = 16.0;
        local_58 = 18.0;
        local_6c = -16.0;
        local_64 = -18.0;
        local_68 = local_6c;
        local_5c = local_60;
        FindHullIntersection__FRC6VectorR11TraceResultPfT2P7edict_s
                  (&local_48,local_3c,&local_6c,&local_60,
                   *(undefined4 *)(*(int *)param_1[0x11d] + 0x208));
      }
      local_54 = local_28;
      local_50 = local_24;
      local_4c = local_20;
    }
  }
  if (local_2c < 1.0) {
    if ((local_c == 0) && (local_c = (*DAT_0019f7b4)(0), local_c == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(local_c + 0x7c);
    }
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0x11d],5);
    local_84 = 1.0;
    local_6c = gpGlobals[10];
    local_68 = gpGlobals[0xb];
    local_64 = gpGlobals[0xc];
    iVar2 = (**(code **)(param_1[0x115] + 0x188))(param_1,iVar1,&local_6c,local_3c);
    param_1[0x122] = 0x3ecccccd;
    param_1[0x124] = 0x40a00000;
    if ((((iVar2 != 0) && (iVar1 != 0)) &&
        (iVar2 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x2c))(iVar1), iVar2 != 0)) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x2c))(iVar1), iVar2 != 1)) {
      *(undefined4 *)(param_1[0x11d] + 0x6bc) = 0x80;
      iVar1 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x8c))(iVar1);
      if (iVar1 == 0) {
        return;
      }
      local_84 = 0.1;
    }
    piVar3 = local_3c;
    piVar4 = param_1 + 0x144;
    for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar4 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar4 = piVar4 + 1;
    }
    param_1[3] = -0x10000;
    param_1[4] = (int)Smack__6CTFAxe;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
    *(int *)(param_1[0x11d] + 0x6bc) = (int)ROUND(local_84 * 512.0);
    return;
  }
  param_1[0x122] = 0x3ecccccd;
  param_1[0x124] = 0x40a00000;
  SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0x11d],5);
  return;
}


// PrimaryAttack__6CTFRpg  @ 0012ff0c
void PrimaryAttack__6CTFRpg(int param_1)

{
  byte *pbVar1;
  int iVar2;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  if (*(int *)(param_1 + 0x4c0) == 0) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x160))(param_1);
    (**(code **)(*(int *)(param_1 + 0x454) + 0x178))(param_1);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6bc) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6c4) = 0x200;
    (*DAT_0019f88c)(1,*(undefined4 *)(**(int **)(param_1 + 0x474) + 0x208),
                    *(undefined2 *)(param_1 + 0x4d0),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x474),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x474) + 0x74);
    GetGunPosition__12CBaseMonster(&local_34,*(undefined4 *)(param_1 + 0x474));
    local_40 = *(float *)(gpGlobals + 0x28) * 16.0;
    local_3c = *(float *)(gpGlobals + 0x2c) * 16.0;
    local_38 = *(float *)(gpGlobals + 0x30) * 16.0;
    local_28 = local_40 + local_34;
    local_24 = local_3c + local_30;
    local_20 = local_38 + local_2c;
    fStack_1c = local_28 + *(float *)(gpGlobals + 0x40) * 8.0;
    fStack_18 = local_24 + *(float *)(gpGlobals + 0x44) * 8.0;
    fStack_14 = local_20 + *(float *)(gpGlobals + 0x48) * 8.0;
    fStack_58 = fStack_1c + *(float *)(gpGlobals + 0x34) * -8.0;
    fStack_54 = fStack_18 + *(float *)(gpGlobals + 0x38) * -8.0;
    fStack_50 = fStack_14 + *(float *)(gpGlobals + 0x3c) * -8.0;
    iVar2 = **(int **)(param_1 + 0x474);
    uStack_4c = *(undefined4 *)(iVar2 + 0x74);
    uStack_48 = *(undefined4 *)(iVar2 + 0x78);
    uStack_44 = *(undefined4 *)(iVar2 + 0x7c);
    fStack_10 = fStack_58;
    fStack_c = fStack_54;
    fStack_8 = fStack_50;
    CreateRpgRocket__12CTFRpgRocketG6VectorT1P11CBaseEntityP6CTFRpg
              (&fStack_58,&uStack_4c,*(int **)(param_1 + 0x474),param_1);
    DB_LogShots__17CBasePlayerWeaponl(param_1,1);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x474) + 0x74);
    *(undefined4 *)(param_1 + 0x4b4) = 0;
    pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x84);
    *pbVar1 = *pbVar1 & 0xfd;
    *(int *)(param_1 + 0x4c0) = *(int *)(param_1 + 0x4c0) + -1;
    *(undefined4 *)(param_1 + 0x488) = 0x3f4ccccd;
    *(undefined4 *)(param_1 + 0x490) = 0x3f4ccccd;
  }
  return;
}


// PrimaryAttack__8CCrowbar  @ 00098164
void PrimaryAttack__8CCrowbar(int *param_1)

{
  int iVar1;
  
  iVar1 = Swing__8CCrowbari(param_1,1);
  if (iVar1 == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SwingAgain__8CCrowbar;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


// PrimaryAttack__8CTFTranq  @ 00132394
void PrimaryAttack__8CTFTranq(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if (*(int *)(*(int *)(param_1 + 0x474) + 0xcc) < 1) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x160))(param_1);
    *(undefined4 *)(param_1 + 0x488) = 0x3e4ccccd;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6bc) = 600;
    *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6c4) = 0x100;
    (*DAT_0019f88c)(1,*(undefined4 *)(**(int **)(param_1 + 0x474) + 0x208),
                    *(undefined2 *)(param_1 + 0x4d0),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    pbVar1 = (byte *)(**(int **)(param_1 + 0x474) + 0x118);
    *pbVar1 = *pbVar1 | 2;
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x474),5);
    GetGunPosition__12CBaseMonster(&uStack_10,*(undefined4 *)(param_1 + 0x474));
    uStack_1c = uStack_10;
    uStack_18 = uStack_c;
    uStack_14 = uStack_8;
    iVar3 = **(int **)(param_1 + 0x474);
    uStack_28 = *(undefined4 *)(iVar3 + 0x74);
    uStack_24 = *(undefined4 *)(iVar3 + 0x78);
    uStack_20 = *(undefined4 *)(iVar3 + 0x7c);
    CreateTranqNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3
              (&uStack_1c,&uStack_28,*(int **)(param_1 + 0x474),param_1);
    DB_LogShots__17CBasePlayerWeaponl(param_1,1);
    piVar2 = (int *)(*(int *)(param_1 + 0x474) + 0xcc);
    *piVar2 = *piVar2 + -1;
    *(undefined4 *)(param_1 + 0x488) = 0x3fc00000;
    *(undefined4 *)(param_1 + 0x490) = 0x41480000;
  }
  return;
}


