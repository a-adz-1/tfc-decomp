// Restore__10CBaseDelayR8CRestore  @ 000f6770
undefined4 Restore__10CBaseDelayR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBaseDelay",param_1,_10CBaseDelay_m_SaveData,2);
  }
  return uVar2;
}


// Restore__10CBreakableR8CRestore  @ 000a9ae8
undefined4 Restore__10CBreakableR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBreakable",param_1,_10CBreakable_m_SaveData,5);
  }
  return uVar2;
}


// Restore__10CEnvGlobalR8CRestore  @ 0008d424
undefined4 Restore__10CEnvGlobalR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CEnvGlobal",param_1,_10CEnvGlobal_m_SaveData,3);
  }
  return uVar2;
}


// Restore__10CFuncTrainR8CRestore  @ 000d25f4
undefined4 Restore__10CFuncTrainR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseToggleR8CRestore(param_1,param_2);
  if ((iVar1 != 0) &&
     (iVar1 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                        (param_2,"CBasePlatTrain",param_1,_14CBasePlatTrain_m_SaveData,3),
     iVar1 != 0)) {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncTrain",param_1,_10CFuncTrain_m_SaveData,3);
    return uVar2;
  }
  return 0;
}


// Restore__10CGunTargetR8CRestore  @ 000d17d0
undefined4 Restore__10CGunTargetR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__12CBaseMonsterR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CGunTarget",param_1,_10CGunTarget_m_SaveData,1);
  }
  return uVar2;
}


// Restore__10CLightningR8CRestore  @ 000a5034
undefined4 Restore__10CLightningR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CLightning",param_1,_10CLightning_m_SaveData,0xd);
  }
  return uVar2;
}


// Restore__10CPathTrackR8CRestore  @ 000ccd78
undefined4 Restore__10CPathTrackR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CPathTrack",param_1,_10CPathTrack_m_SaveData,5);
  }
  return uVar2;
}


// Restore__10CWeaponBoxR8CRestore  @ 00125160
undefined4 Restore__10CWeaponBoxR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CWeaponBox",param_1,_10CWeaponBox_m_SaveData,4);
  }
  return uVar2;
}


// Restore__10CXenPLightR8CRestore  @ 00129b84
undefined4 Restore__10CXenPLightR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__14CBaseAnimatingR8CRestore(param_1,param_2);
  if ((iVar1 != 0) &&
     (iVar1 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                        (param_2,"CActAnimating",param_1,_13CActAnimating_m_SaveData,1), iVar1 != 0)
     ) {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CXenPLight",param_1,_10CXenPLight_m_SaveData,1);
    return uVar2;
  }
  return 0;
}


// Restore__11CBaseButtonR8CRestore  @ 0008cf80
undefined4 Restore__11CBaseButtonR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseToggleR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBaseButton",param_1,_11CBaseButton_m_SaveData,8);
  }
  return uVar2;
}


// Restore__11CBaseEntityR8CRestore  @ 0008e2a0
int Restore__11CBaseEntityR8CRestore(int *param_1,undefined4 param_2)

{
  int iVar1;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_20 = ReadEntVars__8CRestorePCcP9entvars_s(param_2,"ENTVARS",*param_1);
  if (local_20 != 0) {
    local_20 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                         (param_2,&DAT_00147d83,param_1,_11CBaseEntity_m_SaveData,5);
  }
  iVar1 = *param_1;
  if ((*(int *)(iVar1 + 0xb4) != 0) && (*(int *)(iVar1 + 0xb8) != 0)) {
    local_10 = *(undefined4 *)(iVar1 + 0xdc);
    local_c = *(undefined4 *)(iVar1 + 0xe0);
    local_8 = *(undefined4 *)(iVar1 + 0xe4);
    local_1c = *(undefined4 *)(iVar1 + 0xe8);
    local_18 = *(undefined4 *)(iVar1 + 0xec);
    local_14 = *(undefined4 *)(iVar1 + 0xf0);
    (*g_engfuncs)(*(int *)(iVar1 + 0xb8) + *(int *)(gpGlobals + 0x98));
    (*DAT_0019f6a8)(*(undefined4 *)(*param_1 + 0x208),
                    *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_10,&local_1c);
  }
  return local_20;
}


// Restore__11CBasePlayerR8CRestore  @ 000da498
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Restore__11CBasePlayerR8CRestore(int *param_1,undefined4 param_2)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar3 = Restore__12CBaseMonsterR8CRestore(param_1,param_2);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"PLAYER",param_1,_11CBasePlayer_m_playerSaveData,0x26);
    if (*(int *)(*(int *)(gpGlobals + 0x9c) + 0x52c) == 0) {
      (*DAT_0019f794)(1,"No Landmark:%s\n",*(int *)(gpGlobals + 0x9c) + 0x530);
      iVar5 = EntSelectSpawnPoint__FP7edict_s(*(undefined4 *)(*param_1 + 0x208));
      iVar3 = *param_1;
      iVar7 = iVar5 + 0x80;
      iVar6 = iVar7;
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      fVar1 = *(float *)(iVar6 + 0x10);
      uVar2 = *(undefined4 *)(iVar6 + 0xc);
      *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar6 + 8);
      *(undefined4 *)(iVar3 + 0xc) = uVar2;
      *(float *)(iVar3 + 0x10) = fVar1 + 1.0;
      if (iVar5 == 0) {
        iVar7 = 0;
      }
      iVar3 = *param_1;
      *(undefined4 *)(iVar3 + 0x50) = *(undefined4 *)(iVar7 + 0x50);
      *(undefined4 *)(iVar3 + 0x54) = *(undefined4 *)(iVar7 + 0x54);
      *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(iVar7 + 0x58);
    }
    *(undefined4 *)(*param_1 + 0x7c) = 0;
    iVar3 = *param_1;
    *(undefined4 *)(iVar3 + 0x50) = *(undefined4 *)(iVar3 + 0x74);
    *(undefined4 *)(iVar3 + 0x54) = *(undefined4 *)(iVar3 + 0x78);
    *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(iVar3 + 0x7c);
    *(undefined4 *)(*param_1 + 0xa0) = 1;
    param_1[0x19b] = 0xf7;
    g_ulModelIndexPlayer = *(undefined4 *)(*param_1 + 0xb4);
    if ((*(byte *)(*param_1 + 0x1a5) & 0x40) == 0) {
      local_14 = 0x42100000;
      local_8 = 0xc2100000;
    }
    else {
      local_14 = 0x41900000;
      local_8 = 0xc1900000;
    }
    local_18 = _FUN_00150a10;
    local_10 = 0xc1800000;
    local_1c = local_18;
    local_c = local_10;
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_10,&local_1c);
  }
  return uVar4;
}


// Restore__11CBaseToggleR8CRestore  @ 000f6584
undefined4 Restore__11CBaseToggleR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__14CBaseAnimatingR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBaseToggle",param_1,_11CBaseToggle_m_SaveData,0x13);
  }
  return uVar2;
}


// Restore__11CBaseTurretR8CRestore  @ 0011d498
undefined4 Restore__11CBaseTurretR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__12CBaseMonsterR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBaseTurret",param_1,_11CBaseTurret_m_SaveData,0x16);
  }
  return uVar2;
}


// Restore__11CGibShooterR8CRestore  @ 000a41a0
undefined4 Restore__11CGibShooterR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__10CBaseDelayR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CGibShooter",param_1,_11CGibShooter_m_SaveData,7);
  }
  return uVar2;
}


// Restore__11CPathCornerR8CRestore  @ 000cce80
undefined4 Restore__11CPathCornerR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CPathCorner",param_1,_11CPathCorner_m_SaveData,1);
  }
  return uVar2;
}


// Restore__11CWallHealthR8CRestore  @ 000b58ec
undefined4 Restore__11CWallHealthR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CWallHealth",param_1,_11CWallHealth_m_SaveData,5);
  }
  return uVar2;
}


// Restore__12CAutoTriggerR8CRestore  @ 00119f24
undefined4 Restore__12CAutoTriggerR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__10CBaseDelayR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CAutoTrigger",param_1,_12CAutoTrigger_m_SaveData,2);
  }
  return uVar2;
}


// Restore__12CBaseMonsterR8CRestore  @ 000c2d78
undefined4 Restore__12CBaseMonsterR8CRestore(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseToggleR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBaseMonster",param_1,_12CBaseMonster_m_SaveData,0x25);
    RouteClear__12CBaseMonster(param_1);
    *(undefined4 *)(param_1 + 0x580) = 0;
    *(undefined4 *)(param_1 + 0x57c) = 0;
    *(undefined4 *)(param_1 + 0x568) = 0;
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4fc);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x4f8) = 0;
    }
  }
  return uVar2;
}


// Restore__12CChangeLevelR8CRestore  @ 0011898c
undefined4 Restore__12CChangeLevelR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseToggleR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CChangeLevel",param_1,_12CChangeLevel_m_SaveData,4);
  }
  return uVar2;
}


// Restore__12CCineMonsterR8CRestore  @ 000eb780
undefined4 Restore__12CCineMonsterR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__12CBaseMonsterR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CCineMonster",param_1,_12CCineMonster_m_SaveData,0xd);
  }
  return uVar2;
}


// Restore__12CFuncPlatRotR8CRestore  @ 000d28fc
undefined4 Restore__12CFuncPlatRotR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseToggleR8CRestore(param_1,param_2);
  if ((iVar1 != 0) &&
     (iVar1 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                        (param_2,"CBasePlatTrain",param_1,_14CBasePlatTrain_m_SaveData,3),
     iVar1 != 0)) {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncPlatRot",param_1,_12CFuncPlatRot_m_SaveData,2);
    return uVar2;
  }
  return 0;
}


// Restore__12CGlobalStateR8CRestore  @ 00126c44
undefined4 Restore__12CGlobalStateR8CRestore(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *__dest;
  int local_70;
  char local_6c [96];
  undefined4 local_c;
  
  ClearStates__12CGlobalState(param_1);
  iVar1 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                    (param_2,"GLOBAL",param_1,_12CGlobalState_m_SaveData,1);
  if (iVar1 == 0) {
LAB_00126c86:
    uVar2 = 0;
  }
  else {
    iVar1 = param_1[1];
    local_70 = 0;
    param_1[1] = 0;
    if (0 < iVar1) {
      do {
        iVar3 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                          (param_2,&DAT_00159b50,local_6c,gGlobalEntitySaveData,3);
        uVar2 = local_c;
        if (iVar3 == 0) goto LAB_00126c86;
        iVar3 = *(int *)(gpGlobals + 0x98);
        __dest = calloc(0x68,1);
        *(undefined4 *)(__dest + 100) = *param_1;
        *param_1 = __dest;
        strcpy(__dest,local_6c + (*(int *)(gpGlobals + 0x98) - iVar3));
        strcpy(__dest + 0x40,local_6c + (*(int *)(gpGlobals + 0x98) - (iVar3 + -0x40)));
        *(undefined4 *)(__dest + 0x60) = uVar2;
        param_1[1] = param_1[1] + 1;
        local_70 = local_70 + 1;
      } while (local_70 < iVar1);
    }
    uVar2 = 1;
  }
  return uVar2;
}


// Restore__12CMultiSourceR8CRestore  @ 0008d218
undefined4 Restore__12CMultiSourceR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CMultiSource",param_1,_12CMultiSource_m_SaveData,4);
  }
  return uVar2;
}


// Restore__12CRevertSavedR8CRestore  @ 000e49b4
undefined4 Restore__12CRevertSavedR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CRevertSaved",param_1,_12CRevertSaved_m_SaveData,2);
  }
  return uVar2;
}


// Restore__12CTalkMonsterR8CRestore  @ 000f9254
undefined4 Restore__12CTalkMonsterR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__12CBaseMonsterR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CTalkMonster",param_1,_12CTalkMonster_m_SaveData,8);
  }
  return uVar2;
}


// Restore__13CActAnimatingR8CRestore  @ 00129d40
undefined4 Restore__13CActAnimatingR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__14CBaseAnimatingR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CActAnimating",param_1,_13CActAnimating_m_SaveData,1);
  }
  return uVar2;
}


// Restore__13CCyclerSpriteR8CRestore  @ 000b4354
undefined4 Restore__13CCyclerSpriteR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CCyclerSprite",param_1,_13CCyclerSprite_m_SaveData,3);
  }
  return uVar2;
}


// Restore__13CEnvExplosionR8CRestore  @ 000a76c8
undefined4 Restore__13CEnvExplosionR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__12CBaseMonsterR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CEnvExplosion",param_1,_13CEnvExplosion_m_SaveData,2);
  }
  return uVar2;
}


// Restore__13CFuncRotatingR8CRestore  @ 000897f4
undefined4 Restore__13CFuncRotatingR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncRotating",param_1,_13CFuncRotating_m_SaveData,5);
  }
  return uVar2;
}


// Restore__13CMultiManagerR8CRestore  @ 00119a64
undefined4 Restore__13CMultiManagerR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseToggleR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CMultiManager",param_1,_13CMultiManager_m_SaveData,5);
  }
  return uVar2;
}


// Restore__13CSquadMonsterR8CRestore  @ 000f56f0
undefined4 Restore__13CSquadMonsterR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__12CBaseMonsterR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CSquadMonster",param_1,_13CSquadMonster_m_SaveData,5);
  }
  return uVar2;
}


// Restore__13CTriggerRelayR8CRestore  @ 00119c70
undefined4 Restore__13CTriggerRelayR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__10CBaseDelayR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CTriggerRelay",param_1,_13CTriggerRelay_m_SaveData,1);
  }
  return uVar2;
}


// Restore__14CBaseAnimatingR8CRestore  @ 000c2e54
undefined4 Restore__14CBaseAnimatingR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__10CBaseDelayR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBaseAnimating",param_1,_14CBaseAnimating_m_SaveData,5);
  }
  return uVar2;
}


// Restore__14CBasePlatTrainR8CRestore  @ 000d3044
void Restore__14CBasePlatTrainR8CRestore(void)

{
  FUN_000d304f();
  return;
}


// Restore__14CFuncTankLaserR8CRestore  @ 000ac478
undefined4 Restore__14CFuncTankLaserR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if ((iVar1 != 0) &&
     (iVar1 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                        (param_2,"CFuncTank",param_1,_9CFuncTank_m_SaveData,0x19), iVar1 != 0)) {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncTankLaser",param_1,_14CFuncTankLaser_m_SaveData,2);
    return uVar2;
  }
  return 0;
}


// Restore__14CMomentaryDoorR8CRestore  @ 0009eed0
undefined4 Restore__14CMomentaryDoorR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseToggleR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CMomentaryDoor",param_1,_14CMomentaryDoor_m_SaveData,1);
  }
  return uVar2;
}


// Restore__14CTriggerCameraR8CRestore  @ 00117dec
undefined4 Restore__14CTriggerCameraR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__10CBaseDelayR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CTriggerCamera",param_1,_14CTriggerCamera_m_SaveData,0xd);
  }
  return uVar2;
}


// Restore__15CAmbientGenericR8CRestore  @ 000f29f8
undefined4 Restore__15CAmbientGenericR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CAmbientGeneric",param_1,_15CAmbientGeneric_m_SaveData,4);
  }
  return uVar2;
}


// Restore__15CBasePlayerItemR8CRestore  @ 001260ac
undefined4 Restore__15CBasePlayerItemR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__14CBaseAnimatingR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBasePlayerItem",param_1,_15CBasePlayerItem_m_SaveData,3);
  }
  return uVar2;
}


// Restore__15CFuncTrackTrainR8CRestore  @ 000d23a4
undefined4 Restore__15CFuncTrackTrainR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncTrackTrain",param_1,_15CFuncTrackTrain_m_SaveData,0xc);
  }
  return uVar2;
}


// Restore__16CFuncMortarFieldR8CRestore  @ 000c4018
undefined4 Restore__16CFuncMortarFieldR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseToggleR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncMortarField",param_1,_16CFuncMortarField_m_SaveData,6);
  }
  return uVar2;
}


// Restore__16CFuncTrackChangeR8CRestore  @ 000d1e00
undefined4 Restore__16CFuncTrackChangeR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseToggleR8CRestore(param_1,param_2);
  if (((iVar1 != 0) &&
      (iVar1 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                         (param_2,"CBasePlatTrain",param_1,_14CBasePlatTrain_m_SaveData,3),
      iVar1 != 0)) &&
     (iVar1 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                        (param_2,"CFuncPlatRot",param_1,_12CFuncPlatRot_m_SaveData,2), iVar1 != 0))
  {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncTrackChange",param_1,_16CFuncTrackChange_m_SaveData,9);
    return uVar2;
  }
  return 0;
}


// Restore__17CBasePlayerWeaponR8CRestore  @ 00125fd4
undefined4 Restore__17CBasePlayerWeaponR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__14CBaseAnimatingR8CRestore(param_1,param_2);
  if ((iVar1 != 0) &&
     (iVar1 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                        (param_2,"CBasePlayerItem",param_1,_15CBasePlayerItem_m_SaveData,3),
     iVar1 != 0)) {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBasePlayerWeapon",param_1,_17CBasePlayerWeapon_m_SaveData,7);
    return uVar2;
  }
  return 0;
}


// Restore__17CFrictionModifierR8CRestore  @ 0011a168
undefined4 Restore__17CFrictionModifierR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFrictionModifier",param_1,_17CFrictionModifier_m_SaveData,1);
  }
  return uVar2;
}


// Restore__17CFuncTankControlsR8CRestore  @ 000abe40
undefined4 Restore__17CFuncTankControlsR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncTankControls",param_1,_17CFuncTankControls_m_SaveData,1);
  }
  return uVar2;
}


// Restore__17CScriptedSentenceR8CRestore  @ 000eafe4
undefined4 Restore__17CScriptedSentenceR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseToggleR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CScriptedSentence",param_1,_17CScriptedSentence_m_SaveData,9);
  }
  return uVar2;
}


// Restore__19CMomentaryRotButtonR8CRestore  @ 0008ca18
undefined4 Restore__19CMomentaryRotButtonR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseToggleR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CMomentaryRotButton",param_1,_19CMomentaryRotButton_m_SaveData,6);
  }
  return uVar2;
}


// Restore__20CTriggerChangeTargetR8CRestore  @ 00117ffc
undefined4 Restore__20CTriggerChangeTargetR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__10CBaseDelayR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CTriggerChangeTarget",param_1,_20CTriggerChangeTarget_m_SaveData,1);
  }
  return uVar2;
}


// Restore__5CGlowR8CRestore  @ 000a4a28
void Restore__5CGlowR8CRestore(void)

{
  FUN_000a4a33();
  return;
}


// Restore__6CLaserR8CRestore  @ 000a4dfc
undefined4 Restore__6CLaserR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CLaser",param_1,_6CLaser_m_SaveData,3);
  }
  return uVar2;
}


// Restore__6CLightR8CRestore  @ 000b6a2c
undefined4 Restore__6CLightR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CLight",param_1,_6CLight_m_SaveData,2);
  }
  return uVar2;
}


// Restore__7CCyclerR8CRestore  @ 000b48ec
undefined4 Restore__7CCyclerR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__12CBaseMonsterR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CCycler",param_1,_7CCycler_m_SaveData,1);
  }
  return uVar2;
}


// Restore__7CSpriteR8CRestore  @ 000a48b0
undefined4 Restore__7CSpriteR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CSprite",param_1,_7CSprite_m_SaveData,2);
  }
  return uVar2;
}


// Restore__7CTurretR8CRestore  @ 0011d350
undefined4 Restore__7CTurretR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__12CBaseMonsterR8CRestore(param_1,param_2);
  if ((iVar1 != 0) &&
     (iVar1 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                        (param_2,"CBaseTurret",param_1,_11CBaseTurret_m_SaveData,0x16), iVar1 != 0))
  {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CTurret",param_1,_7CTurret_m_SaveData,1);
    return uVar2;
  }
  return 0;
}


// Restore__8CAirtankR8CRestore  @ 00086af0
undefined4 Restore__8CAirtankR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__12CBaseMonsterR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CAirtank",param_1,_8CAirtank_m_SaveData,1);
  }
  return uVar2;
}


// Restore__8CAreaDefR8CRestore  @ 00087074
undefined4 Restore__8CAreaDefR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CAreaDef",param_1,_8CAreaDef_m_SaveData,1);
  }
  return uVar2;
}


// Restore__8CSpeakerR8CRestore  @ 000f1f94
undefined4 Restore__8CSpeakerR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CSpeaker",param_1,_8CSpeaker_m_SaveData,1);
  }
  return uVar2;
}


// Restore__8CXenTreeR8CRestore  @ 00129668
undefined4 Restore__8CXenTreeR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__14CBaseAnimatingR8CRestore(param_1,param_2);
  if ((iVar1 != 0) &&
     (iVar1 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                        (param_2,"CActAnimating",param_1,_13CActAnimating_m_SaveData,1), iVar1 != 0)
     ) {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CXenTree",param_1,_8CXenTree_m_SaveData,1);
    return uVar2;
  }
  return 0;
}


// Restore__9CBaseDoorR8CRestore  @ 0009f2b8
undefined4 Restore__9CBaseDoorR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseToggleR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBaseDoor",param_1,_9CBaseDoor_m_SaveData,7);
  }
  return uVar2;
}


// Restore__9CBubblingR8CRestore  @ 000a5980
undefined4 Restore__9CBubblingR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBubbling",param_1,_9CBubbling_m_SaveData,3);
  }
  return uVar2;
}


// Restore__9CEnvSoundR8CRestore  @ 000f28d0
undefined4 Restore__9CEnvSoundR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CEnvSound",param_1,_9CEnvSound_m_SaveData,2);
  }
  return uVar2;
}


// Restore__9CEnvSparkR8CRestore  @ 0008c5a0
undefined4 Restore__9CEnvSparkR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CEnvSpark",param_1,_9CEnvSpark_m_SaveData,1);
  }
  return uVar2;
}


// Restore__9CFuncTankR8CRestore  @ 000acad4
undefined4 Restore__9CFuncTankR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncTank",param_1,_9CFuncTank_m_SaveData,0x19);
  }
  return uVar2;
}


// Restore__9CPendulumR8CRestore  @ 00089634
undefined4 Restore__9CPendulumR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CPendulum",param_1,_9CPendulum_m_SaveData,8);
  }
  return uVar2;
}


// Restore__9CPushableR8CRestore  @ 000a9614
undefined4 Restore__9CPushableR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if ((iVar1 != 0) &&
     (iVar1 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                        (param_2,"CBreakable",param_1,_10CBreakable_m_SaveData,5), iVar1 != 0)) {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CPushable",param_1,_9CPushable_m_SaveData,2);
    return uVar2;
  }
  return 0;
}


// Restore__9CRechargeR8CRestore  @ 000b2f84
undefined4 Restore__9CRechargeR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CRecharge",param_1,_9CRecharge_m_SaveData,5);
  }
  return uVar2;
}


// Restore__9CWreckageR8CRestore  @ 000b3d80
undefined4 Restore__9CWreckageR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__12CBaseMonsterR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CWreckage",param_1,_9CWreckage_m_SaveData,1);
  }
  return uVar2;
}


