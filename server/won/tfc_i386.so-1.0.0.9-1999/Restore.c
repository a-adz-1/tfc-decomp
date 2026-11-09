// Restore__10CBaseDelayR8CRestore  @ 000f0430
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


// Restore__10CBreakableR8CRestore  @ 000b2220
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


// Restore__10CEnvGlobalR8CRestore  @ 0009d510
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


// Restore__10CFuncTrainR8CRestore  @ 000d2090
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


// Restore__10CGunTargetR8CRestore  @ 000d5670
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


// Restore__10CLightningR8CRestore  @ 000abdc0
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


// Restore__10CPathTrackR8CRestore  @ 000d0200
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


// Restore__10CWeaponBoxR8CRestore  @ 0011c070
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


// Restore__10CXenPLightR8CRestore  @ 0011e240
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


// Restore__11CBaseButtonR8CRestore  @ 0009dcc0
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


// Restore__11CBaseEntityR8CRestore  @ 000a14e0
undefined4 Restore__11CBaseEntityR8CRestore(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = ReadEntVars__8CRestorePCcP9entvars_t(param_2,"ENTVARS",*param_1);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,&DAT_0012c463,param_1,_11CBaseEntity_m_SaveData,5);
  }
  iVar1 = *param_1;
  if ((*(int *)(iVar1 + 0x94) != 0) && (*(int *)(iVar1 + 0x98) != 0)) {
    local_10 = *(undefined4 *)(iVar1 + 0xbc);
    local_c = *(undefined4 *)(iVar1 + 0xc0);
    local_8 = *(undefined4 *)(iVar1 + 0xc4);
    local_1c = *(undefined4 *)(iVar1 + 200);
    local_18 = *(undefined4 *)(iVar1 + 0xcc);
    local_14 = *(undefined4 *)(iVar1 + 0xd0);
    (*g_engfuncs)(*(int *)(iVar1 + 0x98) + *(int *)(gpGlobals + 0x98));
    (*DAT_001754c8)(*(undefined4 *)(*param_1 + 0x1e8),
                    *(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
    UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_10,&local_1c);
  }
  return uVar2;
}


// Restore__11CBasePlayerR8CRestore  @ 000dce00
undefined4 Restore__11CBasePlayerR8CRestore(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar1 = Restore__12CBaseMonsterR8CRestore(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"PLAYER",param_1,_11CBasePlayer_m_playerSaveData,0x26);
    if (*(int *)(*(int *)(gpGlobals + 0x9c) + 0x52c) == 0) {
      (*DAT_001755b4)(1,"No Landmark:%s\n",*(int *)(gpGlobals + 0x9c) + 0x530);
      iVar3 = EntSelectSpawnPoint__FP7edict_s(*(undefined4 *)(*param_1 + 0x1e8));
      iVar1 = *param_1;
      if (iVar3 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = iVar3 + 0xdc;
      }
      local_1c = 0;
      local_18 = 0;
      local_14 = 0x3f800000;
      local_10 = *(float *)(iVar4 + 8) + 0.0;
      local_c = *(float *)(iVar4 + 0xc) + 0.0;
      local_8 = *(float *)(iVar4 + 0x10) + 1.0;
      *(float *)(iVar1 + 8) = local_10;
      *(float *)(iVar1 + 0xc) = local_c;
      *(float *)(iVar1 + 0x10) = local_8;
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = iVar3 + 0xdc;
      }
      iVar1 = *param_1;
      *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(iVar3 + 0x50);
      *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(iVar3 + 0x54);
      *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(iVar3 + 0x58);
    }
    *(undefined4 *)(*param_1 + 0x7c) = 0;
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(iVar1 + 0x74);
    *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(iVar1 + 0x78);
    *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(iVar1 + 0x7c);
    *(undefined4 *)(*param_1 + 0x80) = 1;
    param_1[0x178] = 0xf7;
    iVar1 = *param_1;
    g_ulModelIndexPlayer = *(undefined4 *)(iVar1 + 0x94);
    if ((*(byte *)(iVar1 + 0x185) & 0x40) == 0) {
      local_14 = 0x42100000;
      local_8 = -36.0;
    }
    else {
      FixPlayerCrouchStuck__FP7edict_s(*(undefined4 *)(iVar1 + 0x1e8));
      local_14 = 0x41900000;
      local_8 = -18.0;
    }
    local_18 = 0x41800000;
    local_1c = 0x41800000;
    local_10 = -16.0;
    local_c = -16.0;
    UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_10,&local_1c);
    RenewItems__11CBasePlayer(param_1);
  }
  return uVar2;
}


// Restore__11CBaseToggleR8CRestore  @ 000f0a70
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


// Restore__11CBaseTurretR8CRestore  @ 00113890
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


// Restore__11CGibShooterR8CRestore  @ 000ae550
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


// Restore__11CPathCornerR8CRestore  @ 000d0110
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


// Restore__11CWallHealthR8CRestore  @ 000bce30
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


// Restore__12CAutoTriggerR8CRestore  @ 0010f470
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


// Restore__12CBaseMonsterR8CRestore  @ 000c0de0
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
    *(undefined4 *)(param_1 + 0x4f4) = 0;
    *(undefined4 *)(param_1 + 0x4f0) = 0;
    *(undefined4 *)(param_1 + 0x4dc) = 0;
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x470);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x46c) = 0;
    }
  }
  return uVar2;
}


// Restore__12CChangeLevelR8CRestore  @ 00110f00
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


// Restore__12CCineMonsterR8CRestore  @ 000e6fc0
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


// Restore__12CFuncPlatRotR8CRestore  @ 000d1cf0
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


// Restore__12CGlobalStateR8CRestore  @ 0011d630
undefined4 Restore__12CGlobalStateR8CRestore(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 local_6c [96];
  undefined4 local_c;
  
  ClearStates__12CGlobalState(param_1);
  iVar1 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                    (param_2,"GLOBAL",param_1,_12CGlobalState_m_SaveData,1);
  if (iVar1 == 0) {
LAB_0011d662:
    uVar2 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 4);
    *(undefined4 *)(param_1 + 4) = 0;
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        iVar3 = ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
                          (param_2,&DAT_0014dfb0,local_6c,gGlobalEntitySaveData,3);
        if (iVar3 == 0) goto LAB_0011d662;
        EntityAdd__12CGlobalStateii12GLOBALESTATE
                  (param_1,(int)local_6c - *(int *)(gpGlobals + 0x98),
                   (int)local_6c - (*(int *)(gpGlobals + 0x98) + -0x40),local_c);
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
    uVar2 = 1;
  }
  return uVar2;
}


// Restore__12CMultiSourceR8CRestore  @ 0009d7a0
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


// Restore__12CRevertSavedR8CRestore  @ 000dff60
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


// Restore__12CTalkMonsterR8CRestore  @ 000f1240
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


// Restore__13CActAnimatingR8CRestore  @ 0011e160
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


// Restore__13CCyclerSpriteR8CRestore  @ 000bbb10
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


// Restore__13CEnvExplosionR8CRestore  @ 000b18f0
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


// Restore__13CFuncRotatingR8CRestore  @ 0009bb20
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


// Restore__13CMultiManagerR8CRestore  @ 0010f7d0
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


// Restore__13CSquadMonsterR8CRestore  @ 000ef2a0
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


// Restore__13CTriggerRelayR8CRestore  @ 0010f660
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


// Restore__14CBaseAnimatingR8CRestore  @ 000c0d60
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


// Restore__14CBasePlatTrainR8CRestore  @ 000d0dd0
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


// Restore__14CFuncTankLaserR8CRestore  @ 000b5bf0
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


// Restore__14CMomentaryDoorR8CRestore  @ 000aab40
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


// Restore__14CTriggerCameraR8CRestore  @ 00112540
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


// Restore__15CAmbientGenericR8CRestore  @ 000eb030
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


// Restore__15CBasePlayerItemR8CRestore  @ 0011aa80
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


// Restore__15CFuncTrackTrainR8CRestore  @ 000d2b50
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


// Restore__16CFuncMortarFieldR8CRestore  @ 000c8db0
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


// Restore__16CFuncTrackChangeR8CRestore  @ 000d46d0
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


// Restore__17CBasePlayerWeaponR8CRestore  @ 0011ab00
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


// Restore__17CFrictionModifierR8CRestore  @ 0010f2f0
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


// Restore__17CFuncTankControlsR8CRestore  @ 000b61b0
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


// Restore__17CScriptedSentenceR8CRestore  @ 000e8500
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


// Restore__19CMomentaryRotButtonR8CRestore  @ 0009f2a0
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


// Restore__20CTriggerChangeTargetR8CRestore  @ 001123f0
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


// Restore__5CGlowR8CRestore  @ 000add30
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


// Restore__6CLaserR8CRestore  @ 000ad5f0
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


// Restore__6CLightR8CRestore  @ 000bd9e0
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


// Restore__7CCyclerR8CRestore  @ 000bb680
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


// Restore__7CSpriteR8CRestore  @ 000adf60
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


// Restore__7CTurretR8CRestore  @ 00113910
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


// Restore__8CAirtankR8CRestore  @ 0009a750
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
                      (param_2,"CAirtank",param_1,force_to_data,1);
  }
  return uVar2;
}


// Restore__8CSpeakerR8CRestore  @ 000ed9f0
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


// Restore__8CXenTreeR8CRestore  @ 0011e910
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


// Restore__9CBaseDoorR8CRestore  @ 000a8f40
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


// Restore__9CBubblingR8CRestore  @ 000ab220
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


// Restore__9CEnvSoundR8CRestore  @ 000ec280
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


// Restore__9CEnvSparkR8CRestore  @ 0009fbd0
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


// Restore__9CFuncTankR8CRestore  @ 000b3d20
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


// Restore__9CPendulumR8CRestore  @ 0009cad0
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


// Restore__9CPushableR8CRestore  @ 000b34e0
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


// Restore__9CRechargeR8CRestore  @ 000ba990
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


// Restore__9CWreckageR8CRestore  @ 000bc070
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


