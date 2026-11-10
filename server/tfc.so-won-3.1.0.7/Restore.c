// Restore__10CBaseDelayR8CRestore  @ 000f38ec
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


// Restore__10CBreakableR8CRestore  @ 000a836c
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


// Restore__10CEnvGlobalR8CRestore  @ 0008a7b0
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


// Restore__10CFuncTrainR8CRestore  @ 000ce5f4
undefined4 Restore__10CFuncTrainR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__14CBasePlatTrainR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncTrain",param_1,_10CFuncTrain_m_SaveData,3);
  }
  return uVar2;
}


// Restore__10CGunTargetR8CRestore  @ 000d2240
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


// Restore__10CLightningR8CRestore  @ 000a0888
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


// Restore__10CPathTrackR8CRestore  @ 000cc540
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


// Restore__10CWeaponBoxR8CRestore  @ 00120f84
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


// Restore__10CXenPLightR8CRestore  @ 00123fe0
undefined4 Restore__10CXenPLightR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__13CActAnimatingR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CXenPLight",param_1,_10CXenPLight_m_SaveData,1);
  }
  return uVar2;
}


// Restore__11CBaseButtonR8CRestore  @ 0008b070
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


// Restore__11CBaseEntityR8CRestore  @ 0008eeb8
undefined4 Restore__11CBaseEntityR8CRestore(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = ReadEntVars__8CRestorePCcP9entvars_s(param_2,"ENTVARS",*param_1);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,&DAT_001426eb,param_1,_11CBaseEntity_m_SaveData,5);
  }
  iVar1 = *param_1;
  if ((*(int *)(iVar1 + 0xb4) != 0) && (*(int *)(iVar1 + 0xb8) != 0)) {
    local_c = *(undefined4 *)(iVar1 + 0xdc);
    local_8 = *(undefined4 *)(iVar1 + 0xe0);
    local_4 = *(undefined4 *)(iVar1 + 0xe4);
    local_18 = *(undefined4 *)(iVar1 + 0xe8);
    local_14 = *(undefined4 *)(iVar1 + 0xec);
    local_10 = *(undefined4 *)(iVar1 + 0xf0);
    (*g_engfuncs)(*(int *)(iVar1 + 0xb8) + *(int *)(gpGlobals + 0x98));
    (*DAT_001c1028)(*(undefined4 *)(*param_1 + 0x208),
                    *(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,&local_c,&local_18);
  }
  return uVar2;
}


// Restore__11CBasePlayerR8CRestore  @ 000dae50
undefined4 Restore__11CBasePlayerR8CRestore(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar4 = Restore__12CBaseMonsterR8CRestore(param_1,param_2);
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"PLAYER",param_1,_11CBasePlayer_m_playerSaveData,0x26);
    if (*(int *)(*(int *)(gpGlobals + 0x9c) + 0x52c) == 0) {
      (*DAT_001c1114)(1,"No Landmark:%s\n",*(int *)(gpGlobals + 0x9c) + 0x530);
      iVar6 = EntSelectSpawnPoint__FP7edict_s(*(undefined4 *)(*param_1 + 0x208));
      iVar3 = *param_1;
      iVar4 = iVar6 + 0x80;
      if (iVar6 == 0) {
        iVar4 = 0;
      }
      uVar1 = *(undefined4 *)(iVar4 + 0xc);
      fVar2 = *(float *)(iVar4 + 0x10);
      *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar4 + 8);
      *(undefined4 *)(iVar3 + 0xc) = uVar1;
      *(float *)(iVar3 + 0x10) = fVar2 + 1.0;
      iVar4 = iVar6 + 0x80;
      if (iVar6 == 0) {
        iVar4 = 0;
      }
      iVar3 = *param_1;
      *(undefined4 *)(iVar3 + 0x50) = *(undefined4 *)(iVar4 + 0x50);
      *(undefined4 *)(iVar3 + 0x54) = *(undefined4 *)(iVar4 + 0x54);
      *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(iVar4 + 0x58);
    }
    *(undefined4 *)(*param_1 + 0x7c) = 0;
    iVar4 = *param_1;
    *(undefined4 *)(iVar4 + 0x50) = *(undefined4 *)(iVar4 + 0x74);
    *(undefined4 *)(iVar4 + 0x54) = *(undefined4 *)(iVar4 + 0x78);
    *(undefined4 *)(iVar4 + 0x58) = *(undefined4 *)(iVar4 + 0x7c);
    *(undefined4 *)(*param_1 + 0xa0) = 1;
    param_1[0x197] = 0xf7;
    g_ulModelIndexPlayer = *(undefined4 *)(*param_1 + 0xb4);
    iVar4 = *param_1;
    if ((*(byte *)(iVar4 + 0x1a5) & 0x40) == 0) {
      local_10 = 0x42100000;
      local_4 = 0xc2100000;
      iVar4 = *param_1;
    }
    else {
      local_10 = 0x41900000;
      local_4 = 0xc1900000;
    }
    local_8 = 0xc1800000;
    local_14 = 0x41800000;
    local_18 = local_14;
    local_c = local_8;
    UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar4,&local_c,&local_18);
    RenewItems__11CBasePlayer(param_1);
  }
  return uVar5;
}


// Restore__11CBaseToggleR8CRestore  @ 000f4030
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


// Restore__11CBaseTurretR8CRestore  @ 001162d0
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


// Restore__11CGibShooterR8CRestore  @ 000a37d0
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


// Restore__11CPathCornerR8CRestore  @ 000cc43c
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


// Restore__11CWallHealthR8CRestore  @ 000b6114
void Restore__11CWallHealthR8CRestore(void)

{
  FUN_000b611c();
  return;
}


// Restore__12CAutoTriggerR8CRestore  @ 00110ef0
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


// Restore__12CBaseMonsterR8CRestore  @ 000b9ab4
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
    *(undefined4 *)(param_1 + 0x570) = 0;
    *(undefined4 *)(param_1 + 0x56c) = 0;
    *(undefined4 *)(param_1 + 0x558) = 0;
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4ec);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x4e8) = 0;
    }
  }
  return uVar2;
}


// Restore__12CChangeLevelR8CRestore  @ 00112c88
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


// Restore__12CCineMonsterR8CRestore  @ 000e7f28
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


// Restore__12CFuncPlatRotR8CRestore  @ 000ce20c
undefined4 Restore__12CFuncPlatRotR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__14CBasePlatTrainR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncPlatRot",param_1,_12CFuncPlatRot_m_SaveData,2);
  }
  return uVar2;
}


// Restore__12CGlobalStateR8CRestore  @ 00122b58
undefined4 Restore__12CGlobalStateR8CRestore(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_68 [96];
  undefined4 uStack_8;
  
  ClearStates__12CGlobalState(param_1);
  iVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                    (param_2,"GLOBAL",param_1,_12CGlobalState_m_SaveData,1);
  if (iVar2 == 0) {
LAB_00122ba4:
    uVar3 = 0;
  }
  else {
    uVar1 = *(uint *)(param_1 + 4);
    *(undefined4 *)(param_1 + 4) = 0;
    iVar2 = 0;
    if (0 < (int)uVar1) {
      if ((uVar1 & 1) != 0) {
        iVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                          (param_2,&UNK_00154b10,auStack_68,gGlobalEntitySaveData,3);
        if (iVar2 == 0) goto LAB_00122ba4;
        EntityAdd__12CGlobalStateii12GLOBALESTATE
                  (param_1,(int)auStack_68 - *(int *)(gpGlobals + 0x98),
                   (int)auStack_68 - (*(int *)(gpGlobals + 0x98) + -0x40),uStack_8);
        iVar2 = 1;
        if ((int)uVar1 < 2) goto LAB_00122d1d;
      }
      do {
        iVar4 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                          (param_2,&UNK_00154b10,auStack_68,gGlobalEntitySaveData,3);
        if (iVar4 == 0) goto LAB_00122ba4;
        EntityAdd__12CGlobalStateii12GLOBALESTATE
                  (param_1,(int)auStack_68 - *(int *)(gpGlobals + 0x98),
                   (int)auStack_68 - (*(int *)(gpGlobals + 0x98) + -0x40),uStack_8);
        iVar4 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                          (param_2,&UNK_00154b10,auStack_68,gGlobalEntitySaveData,3);
        if (iVar4 == 0) goto LAB_00122ba4;
        EntityAdd__12CGlobalStateii12GLOBALESTATE
                  (param_1,(int)auStack_68 - *(int *)(gpGlobals + 0x98),
                   (int)auStack_68 - (*(int *)(gpGlobals + 0x98) + -0x40),uStack_8);
        iVar2 = iVar2 + 2;
      } while (iVar2 < (int)uVar1);
    }
LAB_00122d1d:
    uVar3 = 1;
  }
  return uVar3;
}


// Restore__12CMultiSourceR8CRestore  @ 0008aa84
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


// Restore__12CRevertSavedR8CRestore  @ 000df394
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


// Restore__12CTalkMonsterR8CRestore  @ 000f48ec
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


// Restore__13CActAnimatingR8CRestore  @ 00123edc
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


// Restore__13CCyclerSpriteR8CRestore  @ 000b4a30
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


// Restore__13CEnvExplosionR8CRestore  @ 000a75bc
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


// Restore__13CFuncRotatingR8CRestore  @ 000889bc
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


// Restore__13CMultiManagerR8CRestore  @ 001112a0
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


// Restore__13CSquadMonsterR8CRestore  @ 000f21e8
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


// Restore__13CTriggerRelayR8CRestore  @ 00111124
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


// Restore__14CBaseAnimatingR8CRestore  @ 000b9a1c
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


// Restore__14CBasePlatTrainR8CRestore  @ 000cd264
undefined4 Restore__14CBasePlatTrainR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseToggleR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBasePlatTrain",param_1,_14CBasePlatTrain_m_SaveData,3);
  }
  return uVar2;
}


// Restore__14CFuncTankLaserR8CRestore  @ 000ac75c
undefined4 Restore__14CFuncTankLaserR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__9CFuncTankR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncTankLaser",param_1,_14CFuncTankLaser_m_SaveData,2);
  }
  return uVar2;
}


// Restore__14CMomentaryDoorR8CRestore  @ 0009f3d0
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


// Restore__14CTriggerCameraR8CRestore  @ 0011489c
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


// Restore__15CAmbientGenericR8CRestore  @ 000ed4ec
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


// Restore__15CBasePlayerItemR8CRestore  @ 0011f7f8
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


// Restore__15CFuncTrackTrainR8CRestore  @ 000cf234
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


// Restore__16CFuncMortarFieldR8CRestore  @ 000c2eb8
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


// Restore__16CFuncTrackChangeR8CRestore  @ 000d11b8
undefined4 Restore__16CFuncTrackChangeR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__12CFuncPlatRotR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncTrackChange",param_1,_16CFuncTrackChange_m_SaveData,9);
  }
  return uVar2;
}


// Restore__17CBasePlayerWeaponR8CRestore  @ 0011f890
undefined4 Restore__17CBasePlayerWeaponR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__15CBasePlayerItemR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBasePlayerWeapon",param_1,_17CBasePlayerWeapon_m_SaveData,7);
  }
  return uVar2;
}


// Restore__17CFrictionModifierR8CRestore  @ 00110d34
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


// Restore__17CFuncTankControlsR8CRestore  @ 000ad148
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


// Restore__17CScriptedSentenceR8CRestore  @ 000e95d8
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


// Restore__19CMomentaryRotButtonR8CRestore  @ 0008c864
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


// Restore__20CTriggerChangeTargetR8CRestore  @ 00114714
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


// Restore__5CGlowR8CRestore  @ 000a2e3c
undefined4 Restore__5CGlowR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseEntityR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CGlow",param_1,_5CGlow_m_SaveData,2);
  }
  return uVar2;
}


// Restore__6CLaserR8CRestore  @ 000a26c0
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


// Restore__6CLightR8CRestore  @ 000b6ef0
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


// Restore__7CCyclerR8CRestore  @ 000b4518
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


// Restore__7CSpriteR8CRestore  @ 000a310c
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


// Restore__7CTurretR8CRestore  @ 00116368
undefined4 Restore__7CTurretR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__11CBaseTurretR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CTurret",param_1,_7CTurret_m_SaveData,1);
  }
  return uVar2;
}


// Restore__8CAirtankR8CRestore  @ 00086b60
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


// Restore__8CAreaDefR8CRestore  @ 00086f40
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


// Restore__8CSpeakerR8CRestore  @ 000f029c
void Restore__8CSpeakerR8CRestore(void)

{
  FUN_000f02a4();
  return;
}


// Restore__8CXenTreeR8CRestore  @ 001247ec
undefined4 Restore__8CXenTreeR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__13CActAnimatingR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CXenTree",param_1,_8CXenTree_m_SaveData,1);
  }
  return uVar2;
}


// Restore__9CBaseDoorR8CRestore  @ 0009d464
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


// Restore__9CBubblingR8CRestore  @ 0009fbc8
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


// Restore__9CEnvSoundR8CRestore  @ 000ee7b0
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


// Restore__9CEnvSparkR8CRestore  @ 0008d230
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


// Restore__9CFuncTankR8CRestore  @ 000aa3a8
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


// Restore__9CPendulumR8CRestore  @ 00089b30
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


// Restore__9CPushableR8CRestore  @ 000a9aac
undefined4 Restore__9CPushableR8CRestore(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Restore__10CBreakableR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CPushable",param_1,_9CPushable_m_SaveData,2);
  }
  return uVar2;
}


// Restore__9CRechargeR8CRestore  @ 000b3540
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


// Restore__9CWreckageR8CRestore  @ 000b5018
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


