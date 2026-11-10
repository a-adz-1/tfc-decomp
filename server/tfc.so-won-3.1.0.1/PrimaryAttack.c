// PrimaryAttack__10CTFNailgun  @ 0011aa74
void PrimaryAttack__10CTFNailgun(int param_1)

{
  int *piVar1;
  int iVar2;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(int *)(*(int *)(param_1 + 0x3f4) + 0xd4) < 1) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x158))(param_1);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x628) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x630) = 0x200;
    (*DAT_001a802c)(1,*(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0x208),
                    *(undefined2 *)(param_1 + 0x450),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x3f4),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x3f4) + 0x74);
    piVar1 = *(int **)(param_1 + 0x3f4);
    iVar2 = *piVar1;
    local_24 = *(float *)(iVar2 + 8) + *(float *)(iVar2 + 0x174);
    local_20 = *(float *)(iVar2 + 0xc) + *(float *)(iVar2 + 0x178);
    local_1c = *(float *)(iVar2 + 0x10) + *(float *)(iVar2 + 0x17c);
    local_18 = local_24 + *(float *)(gpGlobals + 0x40) + *(float *)(gpGlobals + 0x40);
    local_14 = local_20 + *(float *)(gpGlobals + 0x44) + *(float *)(gpGlobals + 0x44);
    local_10 = local_1c + *(float *)(gpGlobals + 0x48) + *(float *)(gpGlobals + 0x48);
    local_3c = local_18 + *(float *)(gpGlobals + 0x34) * -4.0;
    local_38 = local_14 + *(float *)(gpGlobals + 0x38) * -4.0;
    local_34 = local_10 + *(float *)(gpGlobals + 0x3c) * -4.0;
    iVar2 = *piVar1;
    local_30 = *(undefined4 *)(iVar2 + 0x74);
    local_2c = *(undefined4 *)(iVar2 + 0x78);
    local_28 = *(undefined4 *)(iVar2 + 0x7c);
    local_c = local_3c;
    local_8 = local_38;
    local_4 = local_34;
    CreateNail__14CTFNailgunNailiG6VectorT2P11CBaseEntityT4i(0,&local_3c,&local_30,piVar1,param_1,1)
    ;
    piVar1 = (int *)(*(int *)(param_1 + 0x3f4) + 0xd4);
    *piVar1 = *piVar1 + -1;
    if (*(int *)(*(int *)(param_1 + 0x3f4) + 0xd4) < 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0xd4) = 0;
    }
    *(undefined4 *)(param_1 + 0x408) = 0x3dcccccd;
    *(undefined4 *)(param_1 + 0x410) = 0x41200000;
  }
  return;
}


// PrimaryAttack__10CTFRailgun  @ 0011b2d8
void PrimaryAttack__10CTFRailgun(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (*(int *)(*(int *)(param_1 + 0x3f4) + 0xd4) < 1) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x158))(param_1);
    *(undefined4 *)(param_1 + 0x408) = 0x3e4ccccd;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x628) = 600;
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x630) = 0x100;
    (*DAT_001a802c)(1,*(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0x208),
                    *(undefined2 *)(param_1 + 0x450),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    pbVar1 = (byte *)(**(int **)(param_1 + 0x3f4) + 0x118);
    *pbVar1 = *pbVar1 | 2;
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x3f4),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x3f4) + 0x74);
    piVar2 = *(int **)(param_1 + 0x3f4);
    iVar3 = *piVar2;
    local_24 = *(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x174);
    local_20 = *(float *)(iVar3 + 0xc) + *(float *)(iVar3 + 0x178);
    local_1c = *(float *)(iVar3 + 0x10) + *(float *)(iVar3 + 0x17c);
    local_18 = local_24 + *(float *)(gpGlobals + 0x40) + *(float *)(gpGlobals + 0x40);
    local_14 = local_20 + *(float *)(gpGlobals + 0x44) + *(float *)(gpGlobals + 0x44);
    local_10 = local_1c + *(float *)(gpGlobals + 0x48) + *(float *)(gpGlobals + 0x48);
    local_3c = local_18 + *(float *)(gpGlobals + 0x34) * -4.0;
    local_38 = local_14 + *(float *)(gpGlobals + 0x38) * -4.0;
    local_34 = local_10 + *(float *)(gpGlobals + 0x3c) * -4.0;
    iVar3 = *piVar2;
    local_30 = *(undefined4 *)(iVar3 + 0x74);
    local_2c = *(undefined4 *)(iVar3 + 0x78);
    local_28 = *(undefined4 *)(iVar3 + 0x7c);
    fStack_c = local_3c;
    fStack_8 = local_38;
    fStack_4 = local_34;
    CreateRailgunNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3
              (&local_3c,&local_30,piVar2,param_1);
    piVar2 = (int *)(*(int *)(param_1 + 0x3f4) + 0xd4);
    *piVar2 = *piVar2 + -1;
    *(undefined4 *)(param_1 + 0x408) = 0x3ecccccd;
    *(undefined4 *)(param_1 + 0x410) = 0x41480000;
  }
  return;
}


// PrimaryAttack__10CTFShotgun  @ 0011c154
void PrimaryAttack__10CTFShotgun(int param_1)

{
  byte *pbVar1;
  undefined4 local_38;
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
  undefined4 local_c [3];
  
  if (*(int *)(param_1 + 0x440) < 1) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x170))(param_1);
    if (*(int *)(param_1 + 0x440) == 0) {
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x158))(param_1);
    }
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x628) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x630) = 0x100;
    (*DAT_001a802c)(1,*(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0x208),
                    *(undefined2 *)(param_1 + 0x460),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x3f4),5);
    GetGunPosition__12CBaseMonster(local_c,*(undefined4 *)(param_1 + 0x3f4));
    GetAutoaimVector__11CBasePlayerf(&local_1c,*(undefined4 *)(param_1 + 0x3f4),0x3db27eb6);
    local_2c = local_14;
    local_28 = local_10;
    local_24 = local_c[0];
    local_38 = local_20;
    local_34 = local_1c;
    local_30 = local_18;
    FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_s
              (*(undefined4 *)(param_1 + 0x3f4),6,&local_2c,&local_38,&stack0xffffffbc,0x45000000,6,
               0,4,0);
    if ((*(int *)(param_1 + 0x440) == 0) && (*(int *)(*(int *)(param_1 + 0x3f4) + 0xcc) < 1)) {
      SetSuitUpdate__11CBasePlayerPcii(*(int *)(param_1 + 0x3f4),"!HEV_AMO0",0,0);
    }
    *(int *)(param_1 + 0x440) = *(int *)(param_1 + 0x440) + -1;
    pbVar1 = (byte *)(**(int **)(param_1 + 0x3f4) + 0x118);
    *pbVar1 = *pbVar1 | 2;
    *(undefined4 *)(param_1 + 0x410) = 0x40a00000;
    *(undefined4 *)(param_1 + 0x434) = 0;
    pbVar1 = (byte *)(*(int *)(param_1 + 0x3f4) + 0x84);
    *pbVar1 = *pbVar1 & 0xfd;
    if (*(int *)(param_1 + 0x440) != 0) {
      *(undefined4 *)(param_1 + 0x418) = 0x3f000000;
    }
    *(undefined4 *)(param_1 + 0x408) = 0x3f000000;
  }
  return;
}


// PrimaryAttack__11CTFAssaultC  @ 001165a0
void PrimaryAttack__11CTFAssaultC(int param_1)

{
  float fVar1;
  
  switch(*(undefined4 *)(param_1 + 0x42c)) {
  default:
    WindUp__11CTFAssaultC(param_1);
    *(undefined4 *)(param_1 + 0x408) = 0x3f000000;
    *(undefined4 *)(param_1 + 0x410) = 0x3f19999a;
    FUN_0011669e();
    return;
  case 1:
    fVar1 = *(float *)(param_1 + 0x408);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
      (*DAT_001a802c)(3,*(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0x208),
                      *(undefined2 *)(param_1 + 0x460),0,**(int **)(param_1 + 0x3f4) + 8,&g_vecZero,
                      0,0,0,0,0,0);
      *(undefined4 *)(param_1 + 0x42c) = 2;
      FUN_0011669e();
      return;
    }
    break;
  case 2:
    if (0 < *(int *)(*(int *)(param_1 + 0x3f4) + 0xcc)) {
      Fire__11CTFAssaultC(param_1);
      FUN_0011669e();
      return;
    }
    Spin__11CTFAssaultC(param_1);
    FUN_0011669e();
    return;
  case 3:
    *(undefined4 *)(param_1 + 0x410) = 0x3dcccccd;
  }
  return;
}


// PrimaryAttack__12CHandGrenade  @ 000aa8c8
void PrimaryAttack__12CHandGrenade(int param_1)

{
  if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x450)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(param_1 + 0x450) == 0.0) << 0xe) >> 8)) == 0x40) &&
     (0 < *(int *)(*(int *)(param_1 + 0x438) * 4 + *(int *)(param_1 + 0x3f4) + 0x850))) {
    *(undefined4 *)(param_1 + 0x450) = *gpGlobals;
    *(undefined4 *)(param_1 + 0x454) = 0;
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,2,0);
    *(undefined4 *)(param_1 + 0x410) = 0x3f000000;
  }
  return;
}


// PrimaryAttack__12CTFAutoRifle  @ 00116a30
void PrimaryAttack__12CTFAutoRifle(undefined4 *param_1)

{
  undefined4 unaff_EBP;
  int iVar1;
  float *local_78;
  float local_74;
  float local_70;
  float *local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_44;
  float local_40;
  float local_3c [4];
  float local_2c;
  int local_c;
  
  if (0 < ((int *)param_1[0xfd])[0x33]) {
    local_78 = DAT_001a802c;
    (*(code *)DAT_001a802c)
              (1,*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),*(undefined2 *)(param_1 + 0x114),0,
               &g_vecZero,&g_vecZero,0,0,0,0,0,0);
    *(undefined4 *)(param_1[0xfd] + 0x628) = 600;
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0xfd],5);
    param_1[0x104] = 0x3e4ccccd;
    iVar1 = *(int *)param_1[0xfd];
    local_44 = *(float *)(iVar1 + 0x74) + *(float *)(iVar1 + 0x68);
    local_40 = *(float *)(iVar1 + 0x78) + *(float *)(iVar1 + 0x6c);
    local_3c[0] = *(float *)(iVar1 + 0x7c) + *(float *)(iVar1 + 0x70);
    local_78 = &local_44;
    UTIL_MakeVectors__FRC6Vector(local_78);
    GetGunPosition__12CBaseMonster(&local_5c,param_1[0xfd]);
    local_54 = local_60 - (*(float *)(gpGlobals + 0x34) + *(float *)(gpGlobals + 0x34));
    local_50 = local_5c - (*(float *)(gpGlobals + 0x38) + *(float *)(gpGlobals + 0x38));
    local_4c = local_58 - (*(float *)(gpGlobals + 0x3c) + *(float *)(gpGlobals + 0x3c));
    local_6c = *(float **)(gpGlobals + 0x28);
    local_68 = *(float *)(gpGlobals + 0x2c);
    local_64 = *(float *)(gpGlobals + 0x30);
    local_78 = (float *)((float)local_6c * 8192.0);
    local_74 = local_68 * 8192.0;
    local_70 = local_64 * 8192.0;
    local_60 = local_54 + (float)local_78;
    local_5c = local_50 + local_74;
    local_58 = local_4c + local_70;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&local_54,unaff_EBP,0,*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),local_3c);
    if ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) != 0x40) {
      if ((local_c == 0) && (local_c = (*DAT_001a7f54)(0), local_c == 0)) {
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
        (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x30))
                  (iVar1,*(undefined4 *)param_1[0xfd],0x41000000,&local_78,local_3c,2);
        ApplyMultiDamage__FP9entvars_sT0(*param_1,*(undefined4 *)param_1[0xfd]);
      }
    }
    *(int *)(param_1[0xfd] + 0xcc) = *(int *)(param_1[0xfd] + 0xcc) + -1;
    param_1[0x102] = 0x3dcccccd;
    return;
  }
  param_1[0x102] = 0x40a00000;
  param_1[0x104] = 0x3f800000;
  (**(code **)(param_1[0xf5] + 0x160))(param_1,0,1);
  (**(code **)(param_1[0xf5] + 0x158))(param_1);
  return;
}


// PrimaryAttack__13CWeaponCycler  @ 000a9edc
void PrimaryAttack__13CWeaponCycler(int *param_1)

{
  (**(code **)(param_1[0xf5] + 0x160))(param_1,*(undefined4 *)(*param_1 + 0x128),0);
  param_1[0x102] = 0x3e99999a;
  return;
}


// PrimaryAttack__14CTFIncendiaryC  @ 0011a420
void PrimaryAttack__14CTFIncendiaryC(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float local_30;
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
  
  if (*(int *)(*(int *)(param_1 + 0x3f4) + 0xe4) < 1) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x158))(param_1);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x628) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x630) = 0x200;
    (*DAT_001a802c)(1,*(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0x208),
                    *(undefined2 *)(param_1 + 0x450),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x3f4),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x3f4) + 0x74);
    GetGunPosition__12CBaseMonster(&local_30,*(undefined4 *)(param_1 + 0x3f4));
    fStack_40 = *(float *)(gpGlobals + 0x28) * 16.0;
    fStack_3c = *(float *)(gpGlobals + 0x2c) * 16.0;
    fStack_38 = *(float *)(gpGlobals + 0x30) * 16.0;
    fStack_28 = fStack_34 + fStack_40;
    fStack_24 = local_30 + fStack_3c;
    fStack_20 = fStack_2c + fStack_38;
    fStack_1c = fStack_28 + *(float *)(gpGlobals + 0x40) * 8.0;
    fStack_18 = fStack_24 + *(float *)(gpGlobals + 0x44) * 8.0;
    fStack_14 = fStack_20 + *(float *)(gpGlobals + 0x48) * 8.0;
    fStack_10 = fStack_1c + *(float *)(gpGlobals + 0x34) * -8.0;
    fStack_c = fStack_18 + *(float *)(gpGlobals + 0x38) * -8.0;
    fStack_8 = fStack_14 + *(float *)(gpGlobals + 0x3c) * -8.0;
    iVar2 = **(int **)(param_1 + 0x3f4);
    uStack_4c = *(undefined4 *)(iVar2 + 0x74);
    uStack_48 = *(undefined4 *)(iVar2 + 0x78);
    uStack_44 = *(undefined4 *)(iVar2 + 0x7c);
    CreateRpgRocket__20CTFIncendiaryCRocketG6VectorT1P11CBaseEntityP14CTFIncendiaryC
              (&stack0xffffffa8,&uStack_4c,*(int **)(param_1 + 0x3f4),param_1);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x3f4) + 0x74);
    piVar1 = (int *)(*(int *)(param_1 + 0x3f4) + 0xe4);
    *piVar1 = *piVar1 + -1;
    *(undefined4 *)(param_1 + 0x408) = 0x3f99999a;
    *(undefined4 *)(param_1 + 0x410) = 0x3f99999a;
  }
  return;
}


// PrimaryAttack__14CTFSniperRifle  @ 0011d414
void PrimaryAttack__14CTFSniperRifle(undefined4 *param_1)

{
  float fVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 unaff_EBP;
  bool bVar5;
  undefined2 in_FPUControlWord;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
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
  float local_50;
  float local_4c;
  float local_48 [4];
  float local_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  int local_18;
  int iStack_10;
  undefined4 local_c;
  undefined2 uStack_8;
  undefined2 uStack_6;
  undefined2 local_4;
  undefined2 uStack_2;
  
  if (*(int *)(param_1[0xfd] + 0xcc) < 1) {
    (**(code **)(param_1[0xf5] + 0x158))(param_1);
    return;
  }
  *(undefined4 *)(param_1[0xfd] + 0x628) = 200;
  _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
  local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
  (*DAT_001a802c)(1,*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),*(undefined2 *)(param_1 + 0x116),
                  0,&g_vecZero,&g_vecZero,0,0,(int)ROUND((float)param_1[0x108]),0,0,0);
  SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0xfd],5);
  param_1[0x104] = 0x3f000000;
  iVar3 = *(int *)param_1[0xfd];
  local_50 = *(float *)(iVar3 + 0x74) + *(float *)(iVar3 + 0x68);
  local_4c = *(float *)(iVar3 + 0x78) + *(float *)(iVar3 + 0x6c);
  local_48[0] = *(float *)(iVar3 + 0x7c) + *(float *)(iVar3 + 0x70);
  UTIL_MakeVectors__FRC6Vector(&local_50);
  GetGunPosition__12CBaseMonster(&local_68,param_1[0xfd]);
  local_60 = local_6c - (*(float *)(gpGlobals + 0x34) + *(float *)(gpGlobals + 0x34));
  local_5c = local_68 - (*(float *)(gpGlobals + 0x38) + *(float *)(gpGlobals + 0x38));
  local_58 = local_64 - (*(float *)(gpGlobals + 0x3c) + *(float *)(gpGlobals + 0x3c));
  local_78 = *(float *)(gpGlobals + 0x28);
  local_74 = *(float *)(gpGlobals + 0x2c);
  local_70 = *(float *)(gpGlobals + 0x30);
  local_84 = local_78 * 8192.0;
  local_80 = local_74 * 8192.0;
  local_7c = local_70 * 8192.0;
  local_6c = local_60 + local_84;
  local_68 = local_5c + local_80;
  local_64 = local_58 + local_7c;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_60,unaff_EBP,0,*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),local_48);
  if ((byte)(1.0 < local_38 | (byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) == 0x40) {
    bVar5 = false;
    uVar8 = 0;
    iVar3 = 0x19;
LAB_0011d91a:
    uVar2 = *(undefined2 *)((int)param_1 + 0x45a);
    uVar7 = *(undefined4 *)(*(int *)param_1[0xfd] + 0x208);
    uVar6 = 0x30;
  }
  else {
    if ((local_18 == 0) && (local_18 = (*DAT_001a7f54)(0), local_18 == 0)) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = *(int **)(local_18 + 0x7c);
    }
    if (piVar4 == (int *)0x0) goto LAB_0011d94e;
    uVar8 = param_1[0xde];
    ClearMultiDamage__Fv();
    local_84 = local_78;
    local_80 = local_74;
    local_7c = local_70;
    (**(code **)(piVar4[0xf5] + 0x30))
              (piVar4,*(undefined4 *)param_1[0xfd],param_1[0x108],&local_84,local_48,0x10000002);
    if (*(int *)(param_1[0xfd] + 0x378) != 0) {
      param_1[0xde] = *(undefined4 *)(param_1[0xfd] + 0x378);
    }
    ApplyMultiDamage__FP9entvars_sT0(*param_1,*(undefined4 *)param_1[0xfd]);
    param_1[0xde] = uVar8;
    *(undefined4 *)(param_1[0xfd] + 0x378) = 0;
    iVar3 = strcmp((char *)(*(int *)*piVar4 + *(int *)(gpGlobals + 0x98)),"player");
    bVar5 = iVar3 == 0;
    iVar3 = 0x3c;
    if (bVar5) {
      iVar3 = 0x55;
    }
    iVar9 = 0x5a;
    if (bVar5) {
      iVar9 = 100;
    }
    local_84 = fStack_34 - local_60;
    local_80 = fStack_30 - local_5c;
    local_7c = fStack_2c - local_58;
    fVar1 = SQRT(local_7c * local_7c + local_80 * local_80 + local_84 * local_84);
    if ((byte)((fVar1 < 1024.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 1024.0) << 0xe) >> 8)) - 1) < 0x40) {
      _uStack_8 = CONCAT22(uStack_6,in_FPUControlWord);
      iStack_10 = (int)ROUND((1.0 - fVar1 / 1024.0) * (float)(iVar9 - iVar3) + (float)iVar3);
      iVar3 = iStack_10;
      if (iVar9 < iStack_10) {
        iVar3 = iVar9;
      }
    }
    if (bVar5) {
      fVar1 = *(float *)(*piVar4 + 0x160);
      bVar5 = 0x3f < (byte)((-40.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar1 == -40.0) << 0xe) >> 8)) - 1);
      if (bVar5) {
        iVar3 = 0;
      }
      uVar8 = 1;
      goto LAB_0011d91a;
    }
    bVar5 = false;
    uVar8 = 0;
    uVar2 = *(undefined2 *)((int)param_1 + 0x45a);
    uVar7 = *(undefined4 *)(*(int *)param_1[0xfd] + 0x208);
    uVar6 = 0x34;
  }
  (*DAT_001a802c)(uVar6,uVar7,uVar2,0,&g_vecZero,&g_vecZero,0,0,iVar3,0,uVar8,bVar5);
LAB_0011d94e:
  *(int *)(param_1[0xfd] + 0xcc) = *(int *)(param_1[0xfd] + 0xcc) + -1;
  param_1[0x102] = 0x3fc00000;
  return;
}


// PrimaryAttack__15CTFFlamethrower  @ 00119154
void PrimaryAttack__15CTFFlamethrower(void)

{
  FUN_0011915e();
  return;
}


// PrimaryAttack__15CTFSuperNailgun  @ 0011acf4
void PrimaryAttack__15CTFSuperNailgun(int param_1)

{
  int *piVar1;
  int iVar2;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (*(int *)(*(int *)(param_1 + 0x3f4) + 0xd4) < 1) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x158))(param_1);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x628) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x630) = 0x200;
    (*DAT_001a802c)(1,*(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0x208),
                    *(undefined2 *)(param_1 + 0x454),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x3f4),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x3f4) + 0x74);
    piVar1 = *(int **)(param_1 + 0x3f4);
    iVar2 = *piVar1;
    local_24 = *(float *)(iVar2 + 8) + *(float *)(iVar2 + 0x174);
    local_20 = *(float *)(iVar2 + 0xc) + *(float *)(iVar2 + 0x178);
    local_1c = *(float *)(iVar2 + 0x10) + *(float *)(iVar2 + 0x17c);
    local_18 = local_24 + *(float *)(gpGlobals + 0x40) + *(float *)(gpGlobals + 0x40);
    local_14 = local_20 + *(float *)(gpGlobals + 0x44) + *(float *)(gpGlobals + 0x44);
    local_10 = local_1c + *(float *)(gpGlobals + 0x48) + *(float *)(gpGlobals + 0x48);
    fStack_3c = local_18 + *(float *)(gpGlobals + 0x34) * -4.0;
    fStack_38 = local_14 + *(float *)(gpGlobals + 0x38) * -4.0;
    fStack_34 = local_10 + *(float *)(gpGlobals + 0x3c) * -4.0;
    fStack_c = fStack_3c;
    fStack_8 = fStack_38;
    fStack_4 = fStack_34;
    if (piVar1[0x35] < 4) {
      iVar2 = *piVar1;
      local_30 = *(undefined4 *)(iVar2 + 0x74);
      local_2c = *(undefined4 *)(iVar2 + 0x78);
      local_28 = *(undefined4 *)(iVar2 + 0x7c);
      CreateNail__14CTFNailgunNailiG6VectorT2P11CBaseEntityT4i
                (0,&fStack_3c,&local_30,piVar1,param_1,1);
    }
    else {
      iVar2 = **(int **)(param_1 + 0x3f4);
      local_30 = *(undefined4 *)(iVar2 + 0x74);
      local_2c = *(undefined4 *)(iVar2 + 0x78);
      local_28 = *(undefined4 *)(iVar2 + 0x7c);
      CreateSuperNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3
                (&fStack_3c,&local_30,*(int **)(param_1 + 0x3f4),param_1);
    }
    piVar1 = (int *)(*(int *)(param_1 + 0x3f4) + 0xd4);
    *piVar1 = *piVar1 + -2;
    if (*(int *)(*(int *)(param_1 + 0x3f4) + 0xd4) < 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0xd4) = 0;
    }
    *(undefined4 *)(param_1 + 0x408) = 0x3dcccccd;
    *(undefined4 *)(param_1 + 0x410) = 0x41200000;
  }
  return;
}


// PrimaryAttack__15CTFSuperShotgun  @ 0011c920
void PrimaryAttack__15CTFSuperShotgun(int param_1)

{
  byte *pbVar1;
  int iVar2;
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
  undefined4 auStack_c [3];
  
  if (*(int *)(param_1 + 0x440) < 1) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x170))(param_1);
    if (*(int *)(param_1 + 0x440) == 0) {
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x158))(param_1);
    }
  }
  else if (*(int *)(param_1 + 0x440) == 1) {
    PrimaryAttack__10CTFShotgun(param_1);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x628) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x630) = 0x100;
    (*DAT_001a802c)(1,*(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0x208),
                    *(undefined2 *)(param_1 + 0x464),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    pbVar1 = (byte *)(**(int **)(param_1 + 0x3f4) + 0x118);
    *pbVar1 = *pbVar1 | 2;
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x3f4),5);
    GetGunPosition__12CBaseMonster(auStack_c,*(undefined4 *)(param_1 + 0x3f4));
    GetAutoaimVector__11CBasePlayerf(&uStack_1c,*(undefined4 *)(param_1 + 0x3f4),0x3db27eb6);
    uStack_2c = uStack_14;
    uStack_28 = uStack_10;
    uStack_24 = auStack_c[0];
    uStack_38 = uStack_20;
    uStack_34 = uStack_1c;
    uStack_30 = uStack_18;
    FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_s
              (*(undefined4 *)(param_1 + 0x3f4),0xe,&uStack_2c,&uStack_38,&stack0xffffffbc,
               0x45000000,6,4,4,0);
    if ((*(int *)(param_1 + 0x440) == 0) && (*(int *)(*(int *)(param_1 + 0x3f4) + 0xcc) < 1)) {
      SetSuitUpdate__11CBasePlayerPcii(*(int *)(param_1 + 0x3f4),"!HEV_AMO0",0,0);
    }
    iVar2 = *(int *)(param_1 + 0x440) + -2;
    *(int *)(param_1 + 0x440) = iVar2;
    *(undefined4 *)(param_1 + 0x410) = 0x40a00000;
    *(undefined4 *)(param_1 + 0x434) = 0;
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 0x418) = 0x3f333333;
    }
    *(undefined4 *)(param_1 + 0x408) = 0x3f333333;
  }
  return;
}


// PrimaryAttack__17CBasePlayerWeapon  @ 001123ac
void PrimaryAttack__17CBasePlayerWeapon(void)

{
  return;
}


// PrimaryAttack__18CTFGrenadeLauncher  @ 0011989c
void PrimaryAttack__18CTFGrenadeLauncher(int param_1)

{
  byte *pbVar1;
  int iVar2;
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
  
  if (*(int *)(param_1 + 0x440) == 0) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,*(undefined4 *)(param_1 + 0x458),1);
    *(undefined4 *)(param_1 + 0x408) = 0x3f800000;
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x158))(param_1);
    *(undefined4 *)(param_1 + 0x434) = 0;
    pbVar1 = (byte *)(*(int *)(param_1 + 0x3f4) + 0x84);
    *pbVar1 = *pbVar1 & 0xfd;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x628) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x630) = 0x200;
    (*DAT_001a802c)(1,*(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0x208),
                    *(undefined2 *)(param_1 + 0x464),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x3f4),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x3f4) + 0x74);
    GetGunPosition__12CBaseMonster(&local_24,*(undefined4 *)(param_1 + 0x3f4));
    local_1c = local_28 + *(float *)(gpGlobals + 0x40) * 8.0;
    local_18 = local_24 + *(float *)(gpGlobals + 0x44) * 8.0;
    local_14 = local_20 + *(float *)(gpGlobals + 0x48) * 8.0;
    local_10 = local_1c + *(float *)(gpGlobals + 0x34) * -16.0;
    local_c = local_18 + *(float *)(gpGlobals + 0x38) * -16.0;
    local_8 = local_14 + *(float *)(gpGlobals + 0x3c) * -16.0;
    iVar2 = **(int **)(param_1 + 0x3f4);
    local_34 = *(undefined4 *)(iVar2 + 0x74);
    local_30 = *(undefined4 *)(iVar2 + 0x78);
    local_2c = *(undefined4 *)(iVar2 + 0x7c);
    CreateTFGrenade__10CTFGrenadeG6VectorT1P11CBaseEntityP18CTFGrenadeLauncher
              (&stack0xffffffc0,&local_34,*(int **)(param_1 + 0x3f4),param_1);
    *(undefined4 *)(param_1 + 0x434) = 0;
    pbVar1 = (byte *)(*(int *)(param_1 + 0x3f4) + 0x84);
    *pbVar1 = *pbVar1 & 0xfd;
    *(int *)(param_1 + 0x440) = *(int *)(param_1 + 0x440) + -1;
    *(undefined4 *)(param_1 + 0x40c) = 0x3f19999a;
    *(undefined4 *)(param_1 + 0x408) = 0x3f19999a;
    *(undefined4 *)(param_1 + 0x410) = 0x3f19999a;
  }
  return;
}


// PrimaryAttack__19CTFPipebombLauncher  @ 00119d70
void PrimaryAttack__19CTFPipebombLauncher(int param_1)

{
  byte *pbVar1;
  int iVar2;
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
  
  if (*(int *)(param_1 + 0x440) == 0) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x170))(param_1);
    if (*(int *)(*(int *)(param_1 + 0x3f4) + 0xe4) == 0) {
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x158))(param_1);
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,*(undefined4 *)(param_1 + 0x458),1);
      *(undefined4 *)(param_1 + 0x408) = 0x3f800000;
    }
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x628) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x630) = 0x200;
    (*DAT_001a802c)(1,*(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0x208),
                    *(undefined2 *)(param_1 + 0x464),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x3f4),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x3f4) + 0x74);
    GetGunPosition__12CBaseMonster(&fStack_24,*(undefined4 *)(param_1 + 0x3f4));
    fStack_1c = fStack_28 + *(float *)(gpGlobals + 0x40) * 8.0;
    fStack_18 = fStack_24 + *(float *)(gpGlobals + 0x44) * 8.0;
    fStack_14 = fStack_20 + *(float *)(gpGlobals + 0x48) * 8.0;
    fStack_10 = fStack_1c + *(float *)(gpGlobals + 0x34) * -16.0;
    fStack_c = fStack_18 + *(float *)(gpGlobals + 0x38) * -16.0;
    fStack_8 = fStack_14 + *(float *)(gpGlobals + 0x3c) * -16.0;
    iVar2 = **(int **)(param_1 + 0x3f4);
    uStack_34 = *(undefined4 *)(iVar2 + 0x74);
    uStack_30 = *(undefined4 *)(iVar2 + 0x78);
    uStack_2c = *(undefined4 *)(iVar2 + 0x7c);
    CreateTFPipebomb__10CTFGrenadeG6VectorT1P11CBaseEntityP18CTFGrenadeLauncher
              (&stack0xffffffc0,&uStack_34,*(int **)(param_1 + 0x3f4),param_1);
    *(undefined4 *)(param_1 + 0x434) = 0;
    pbVar1 = (byte *)(*(int *)(param_1 + 0x3f4) + 0x84);
    *pbVar1 = *pbVar1 & 0xfd;
    *(int *)(param_1 + 0x440) = *(int *)(param_1 + 0x440) + -1;
    *(undefined4 *)(param_1 + 0x408) = 0x3f19999a;
    *(undefined4 *)(param_1 + 0x410) = 0x3f19999a;
  }
  return;
}


// PrimaryAttack__6CTFAxe  @ 001170fc
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
  float fStack_28;
  float fStack_24;
  float fStack_20;
  int local_c;
  
  param_1[0x132] = 0;
  UTIL_MakeVectors__FRC6Vector(*(int *)param_1[0xfd] + 0x74);
  GetGunPosition__12CBaseMonster(&local_44,param_1[0xfd]);
  local_60 = gpGlobals[10] * 32.0;
  local_5c = gpGlobals[0xb] * 32.0;
  local_58 = gpGlobals[0xc] * 32.0;
  local_54 = local_48 + local_60;
  local_50 = local_44 + local_5c;
  local_4c = local_40 + local_58;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_44,&local_54,0,*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),local_3c);
  (*DAT_001a802c)(1,*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),(short)param_1[0x133],0,
                  &g_vecZero,&g_vecZero,0,0,param_1[0x134],0,0,0);
  if (1.0 <= local_2c) {
    param_1[0x132] = 1;
    UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
              (&local_44,&local_54,0,3,*(undefined4 *)(*(int *)param_1[0xfd] + 0x208),local_3c);
    if (0x3f < (byte)((1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                      (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) - 1)) {
      iVar1 = local_c;
      if ((local_c == 0) && (iVar1 = (*DAT_001a7f54)(0), iVar1 == 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0x7c);
      }
      if ((iVar1 == 0) || (iVar1 = (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x8c))(iVar1), iVar1 != 0)
         ) {
        local_60 = 16.0;
        local_58 = 18.0;
        local_6c = -16.0;
        local_64 = -18.0;
        local_68 = local_6c;
        local_5c = local_60;
        FindHullIntersection__FRC6VectorR11TraceResultPfT2P7edict_s
                  (&local_48,local_3c,&local_6c,&local_60,
                   *(undefined4 *)(*(int *)param_1[0xfd] + 0x208));
      }
      local_54 = fStack_28;
      local_50 = fStack_24;
      local_4c = fStack_20;
    }
  }
  if (local_2c < 1.0) {
    if ((local_c == 0) && (local_c = (*DAT_001a7f54)(0), local_c == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(local_c + 0x7c);
    }
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0xfd],5);
    local_84 = 1.0;
    local_6c = gpGlobals[10];
    local_68 = gpGlobals[0xb];
    local_64 = gpGlobals[0xc];
    iVar2 = (**(code **)(param_1[0xf5] + 0x180))(param_1,iVar1,&local_6c,local_3c);
    param_1[0x102] = 0x3ecccccd;
    param_1[0x104] = 0x40a00000;
    if ((((iVar2 != 0) && (iVar1 != 0)) &&
        (iVar2 = (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x28))(iVar1), iVar2 != 0)) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x28))(iVar1), iVar2 != 1)) {
      *(undefined4 *)(param_1[0xfd] + 0x628) = 0x80;
      iVar1 = (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x88))(iVar1);
      if (iVar1 == 0) {
        return;
      }
      local_84 = 0.1;
    }
    piVar3 = local_3c;
    piVar4 = param_1 + 0x124;
    for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar4 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar4 = piVar4 + 1;
    }
    param_1[3] = -0x10000;
    param_1[4] = (int)Smack__6CTFAxe;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
    *(int *)(param_1[0xfd] + 0x628) = (int)ROUND(local_84 * 512.0);
    return;
  }
  param_1[0x102] = 0x3ecccccd;
  param_1[0x104] = 0x40a00000;
  SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1[0xfd],5);
  return;
}


// PrimaryAttack__6CTFRpg  @ 0011ba28
void PrimaryAttack__6CTFRpg(int param_1)

{
  byte *pbVar1;
  int iVar2;
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
  
  if (*(int *)(param_1 + 0x440) == 0) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x158))(param_1);
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x170))(param_1);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x628) = 1000;
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x630) = 0x200;
    (*DAT_001a802c)(1,*(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0x208),
                    *(undefined2 *)(param_1 + 0x450),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x3f4),5);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x3f4) + 0x74);
    GetGunPosition__12CBaseMonster(&local_30,*(undefined4 *)(param_1 + 0x3f4));
    local_40 = *(float *)(gpGlobals + 0x28) * 16.0;
    local_3c = *(float *)(gpGlobals + 0x2c) * 16.0;
    local_38 = *(float *)(gpGlobals + 0x30) * 16.0;
    local_28 = local_34 + local_40;
    local_24 = local_30 + local_3c;
    local_20 = local_2c + local_38;
    local_1c = local_28 + *(float *)(gpGlobals + 0x40) * 8.0;
    local_18 = local_24 + *(float *)(gpGlobals + 0x44) * 8.0;
    local_14 = local_20 + *(float *)(gpGlobals + 0x48) * 8.0;
    local_10 = local_1c + *(float *)(gpGlobals + 0x34) * -8.0;
    local_c = local_18 + *(float *)(gpGlobals + 0x38) * -8.0;
    local_8 = local_14 + *(float *)(gpGlobals + 0x3c) * -8.0;
    iVar2 = **(int **)(param_1 + 0x3f4);
    local_4c = *(undefined4 *)(iVar2 + 0x74);
    local_48 = *(undefined4 *)(iVar2 + 0x78);
    local_44 = *(undefined4 *)(iVar2 + 0x7c);
    CreateRpgRocket__12CTFRpgRocketG6VectorT1P11CBaseEntityP6CTFRpg
              (&stack0xffffffa8,&local_4c,*(int **)(param_1 + 0x3f4),param_1);
    UTIL_MakeVectors__FRC6Vector(**(int **)(param_1 + 0x3f4) + 0x74);
    *(undefined4 *)(param_1 + 0x434) = 0;
    pbVar1 = (byte *)(*(int *)(param_1 + 0x3f4) + 0x84);
    *pbVar1 = *pbVar1 & 0xfd;
    *(int *)(param_1 + 0x440) = *(int *)(param_1 + 0x440) + -1;
    *(undefined4 *)(param_1 + 0x408) = 0x3f4ccccd;
    *(undefined4 *)(param_1 + 0x410) = 0x3f4ccccd;
  }
  return;
}


// PrimaryAttack__8CCrowbar  @ 0008f6cc
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


// PrimaryAttack__8CTFTranq  @ 0011dcfc
void PrimaryAttack__8CTFTranq(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(*(int *)(param_1 + 0x3f4) + 0xcc) < 1) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x158))(param_1);
    *(undefined4 *)(param_1 + 0x408) = 0x3e4ccccd;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x628) = 600;
    *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x630) = 0x100;
    (*DAT_001a802c)(1,*(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0x208),
                    *(undefined2 *)(param_1 + 0x450),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    pbVar1 = (byte *)(**(int **)(param_1 + 0x3f4) + 0x118);
    *pbVar1 = *pbVar1 | 2;
    SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x3f4),5);
    GetGunPosition__12CBaseMonster(&local_c,*(undefined4 *)(param_1 + 0x3f4));
    local_1c = local_10;
    local_18 = local_c;
    local_14 = local_8;
    CreateTranqNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3
              (&local_1c,&stack0xffffffd8,*(undefined4 *)(param_1 + 0x3f4),param_1);
    piVar2 = (int *)(*(int *)(param_1 + 0x3f4) + 0xcc);
    *piVar2 = *piVar2 + -1;
    *(undefined4 *)(param_1 + 0x408) = 0x3fc00000;
    *(undefined4 *)(param_1 + 0x410) = 0x41480000;
  }
  return;
}


