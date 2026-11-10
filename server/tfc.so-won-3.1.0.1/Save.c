// Save__10CBaseDelayR5CSave  @ 000e6c4c
undefined4 Save__10CBaseDelayR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBaseDelay",param_1,_10CBaseDelay_m_SaveData,2);
  }
  return uVar2;
}


// Save__10CBreakableR5CSave  @ 0009d948
void Save__10CBreakableR5CSave(void)

{
  FUN_0009d950();
  return;
}


// Save__10CEnvGlobalR5CSave  @ 00082760
undefined4 Save__10CEnvGlobalR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CEnvGlobal",param_1,_10CEnvGlobal_m_SaveData,3);
  }
  return uVar2;
}


// Save__10CFuncTrainR5CSave  @ 000c3248
undefined4 Save__10CFuncTrainR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__14CBasePlatTrainR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncTrain",param_1,_10CFuncTrain_m_SaveData,3);
  }
  return uVar2;
}


// Save__10CGunTargetR5CSave  @ 000c6e94
undefined4 Save__10CGunTargetR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__12CBaseMonsterR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CGunTarget",param_1,_10CGunTarget_m_SaveData,1);
  }
  return uVar2;
}


// Save__10CLightningR5CSave  @ 000962dc
undefined4 Save__10CLightningR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CLightning",param_1,_10CLightning_m_SaveData,0xd);
  }
  return uVar2;
}


// Save__10CPathTrackR5CSave  @ 000c11d4
void Save__10CPathTrackR5CSave(void)

{
  FUN_000c11dc();
  return;
}


// Save__10CWeaponBoxR5CSave  @ 001113e8
undefined4 Save__10CWeaponBoxR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CWeaponBox",param_1,_10CWeaponBox_m_SaveData,4);
  }
  return uVar2;
}


// Save__10CXenPLightR5CSave  @ 0011439c
undefined4 Save__10CXenPLightR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__13CActAnimatingR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CXenPLight",param_1,_10CXenPLight_m_SaveData,1);
  }
  return uVar2;
}


// Save__11CBaseButtonR5CSave  @ 00083020
undefined4 Save__11CBaseButtonR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseToggleR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBaseButton",param_1,_11CBaseButton_m_SaveData,8);
  }
  return uVar2;
}


// Save__11CBaseEntityR5CSave  @ 00086cc0
undefined4 Save__11CBaseEntityR5CSave(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = WriteEntVars__5CSavePCcP9entvars_s(param_2,"ENTVARS",*param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,&DAT_0013284b,param_1,_11CBaseEntity_m_SaveData,5);
  }
  return uVar2;
}


// Save__11CBasePlayerR5CSave  @ 000cf744
undefined4 Save__11CBasePlayerR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__12CBaseMonsterR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"PLAYER",param_1,_11CBasePlayer_m_playerSaveData,0x26);
  }
  return uVar2;
}


// Save__11CBaseToggleR5CSave  @ 000e7390
undefined4 Save__11CBaseToggleR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__14CBaseAnimatingR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBaseToggle",param_1,_11CBaseToggle_m_SaveData,0x13);
  }
  return uVar2;
}


// Save__11CBaseTurretR5CSave  @ 001067b8
undefined4 Save__11CBaseTurretR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__12CBaseMonsterR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBaseTurret",param_1,_11CBaseTurret_m_SaveData,0x16);
  }
  return uVar2;
}


// Save__11CGibShooterR5CSave  @ 00099204
undefined4 Save__11CGibShooterR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__10CBaseDelayR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CGibShooter",param_1,_11CGibShooter_m_SaveData,7);
  }
  return uVar2;
}


// Save__11CPathCornerR5CSave  @ 000c10d0
undefined4 Save__11CPathCornerR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CPathCorner",param_1,_11CPathCorner_m_SaveData,1);
  }
  return uVar2;
}


// Save__11CWallHealthR5CSave  @ 000ab028
undefined4 Save__11CWallHealthR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CWallHealth",param_1,_11CWallHealth_m_SaveData,5);
  }
  return uVar2;
}


// Save__12CAutoTriggerR5CSave  @ 001017f4
undefined4 Save__12CAutoTriggerR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__10CBaseDelayR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CAutoTrigger",param_1,_12CAutoTrigger_m_SaveData,2);
  }
  return uVar2;
}


// Save__12CBaseMonsterR5CSave  @ 000ae808
undefined4 Save__12CBaseMonsterR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseToggleR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBaseMonster",param_1,_12CBaseMonster_m_SaveData,0x25);
  }
  return uVar2;
}


// Save__12CChangeLevelR5CSave  @ 0010358c
undefined4 Save__12CChangeLevelR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseToggleR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CChangeLevel",param_1,_12CChangeLevel_m_SaveData,4);
  }
  return uVar2;
}


// Save__12CCineMonsterR5CSave  @ 000dbe40
undefined4 Save__12CCineMonsterR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__12CBaseMonsterR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CCineMonster",param_1,_12CCineMonster_m_SaveData,0xd);
  }
  return uVar2;
}


// Save__12CFuncPlatRotR5CSave  @ 000c2e60
undefined4 Save__12CFuncPlatRotR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__14CBasePlatTrainR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncPlatRot",param_1,_12CFuncPlatRot_m_SaveData,2);
  }
  return uVar2;
}


// Save__12CGlobalStateR5CSave  @ 00112f04
undefined4 Save__12CGlobalStateR5CSave(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                    (param_2,"GLOBAL",param_1,_12CGlobalState_m_SaveData,1);
  if (iVar1 == 0) {
LAB_00112f3a:
    uVar2 = 0;
  }
  else {
    iVar1 = *param_1;
    iVar4 = 0;
    if (0 < param_1[1]) {
      do {
        if (iVar1 == 0) break;
        iVar3 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                          (param_2,&UNK_00143650,iVar1,gGlobalEntitySaveData,3);
        if (iVar3 == 0) goto LAB_00112f3a;
        iVar1 = *(int *)(iVar1 + 100);
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_1[1]);
    }
    uVar2 = 1;
  }
  return uVar2;
}


// Save__12CMultiSourceR5CSave  @ 00082a34
undefined4 Save__12CMultiSourceR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CMultiSource",param_1,_12CMultiSource_m_SaveData,4);
  }
  return uVar2;
}


// Save__12CRevertSavedR5CSave  @ 000d3c44
undefined4 Save__12CRevertSavedR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CRevertSaved",param_1,_12CRevertSaved_m_SaveData,2);
  }
  return uVar2;
}


// Save__12CTalkMonsterR5CSave  @ 000e7bcc
undefined4 Save__12CTalkMonsterR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__12CBaseMonsterR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CTalkMonster",param_1,_12CTalkMonster_m_SaveData,8);
  }
  return uVar2;
}


// Save__13CActAnimatingR5CSave  @ 00114298
undefined4 Save__13CActAnimatingR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__14CBaseAnimatingR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CActAnimating",param_1,_13CActAnimating_m_SaveData,1);
  }
  return uVar2;
}


// Save__13CCyclerSpriteR5CSave  @ 000a9a14
undefined4 Save__13CCyclerSpriteR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CCyclerSprite",param_1,_13CCyclerSprite_m_SaveData,3);
  }
  return uVar2;
}


// Save__13CEnvExplosionR5CSave  @ 0009cbd8
undefined4 Save__13CEnvExplosionR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__12CBaseMonsterR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CEnvExplosion",param_1,_13CEnvExplosion_m_SaveData,2);
  }
  return uVar2;
}


// Save__13CFuncRotatingR5CSave  @ 00080a4c
undefined4 Save__13CFuncRotatingR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncRotating",param_1,_13CFuncRotating_m_SaveData,5);
  }
  return uVar2;
}


// Save__13CMultiManagerR5CSave  @ 00101ba4
undefined4 Save__13CMultiManagerR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseToggleR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CMultiManager",param_1,_13CMultiManager_m_SaveData,5);
  }
  return uVar2;
}


// Save__13CSquadMonsterR5CSave  @ 000e556c
undefined4 Save__13CSquadMonsterR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__12CBaseMonsterR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CSquadMonster",param_1,_13CSquadMonster_m_SaveData,5);
  }
  return uVar2;
}


// Save__13CTriggerRelayR5CSave  @ 00101a28
undefined4 Save__13CTriggerRelayR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__10CBaseDelayR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CTriggerRelay",param_1,_13CTriggerRelay_m_SaveData,1);
  }
  return uVar2;
}


// Save__14CBaseAnimatingR5CSave  @ 000ae770
undefined4 Save__14CBaseAnimatingR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__10CBaseDelayR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBaseAnimating",param_1,_14CBaseAnimating_m_SaveData,5);
  }
  return uVar2;
}


// Save__14CBasePlatTrainR5CSave  @ 000c1eb8
undefined4 Save__14CBasePlatTrainR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseToggleR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBasePlatTrain",param_1,_14CBasePlatTrain_m_SaveData,3);
  }
  return uVar2;
}


// Save__14CFuncTankLaserR5CSave  @ 000a1ce8
undefined4 Save__14CFuncTankLaserR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__9CFuncTankR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncTankLaser",param_1,_14CFuncTankLaser_m_SaveData,2);
  }
  return uVar2;
}


// Save__14CMomentaryDoorR5CSave  @ 00094e84
undefined4 Save__14CMomentaryDoorR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseToggleR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CMomentaryDoor",param_1,_14CMomentaryDoor_m_SaveData,1);
  }
  return uVar2;
}


// Save__14CTriggerCameraR5CSave  @ 001051a0
undefined4 Save__14CTriggerCameraR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__10CBaseDelayR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CTriggerCamera",param_1,_14CTriggerCamera_m_SaveData,0xd);
  }
  return uVar2;
}


// Save__15CAmbientGenericR5CSave  @ 000e0a74
undefined4 Save__15CAmbientGenericR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CAmbientGeneric",param_1,_15CAmbientGeneric_m_SaveData,4);
  }
  return uVar2;
}


// Save__15CBasePlayerItemR5CSave  @ 0010fc60
undefined4 Save__15CBasePlayerItemR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__14CBaseAnimatingR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBasePlayerItem",param_1,_15CBasePlayerItem_m_SaveData,3);
  }
  return uVar2;
}


// Save__15CFuncTrackTrainR5CSave  @ 000c3e88
undefined4 Save__15CFuncTrackTrainR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncTrackTrain",param_1,_15CFuncTrackTrain_m_SaveData,0xc);
  }
  return uVar2;
}


// Save__16CFuncMortarFieldR5CSave  @ 000b7bcc
undefined4 Save__16CFuncMortarFieldR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseToggleR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncMortarField",param_1,_16CFuncMortarField_m_SaveData,6);
  }
  return uVar2;
}


// Save__16CFuncTrackChangeR5CSave  @ 000c5e0c
undefined4 Save__16CFuncTrackChangeR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__12CFuncPlatRotR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncTrackChange",param_1,_16CFuncTrackChange_m_SaveData,9);
  }
  return uVar2;
}


// Save__17CBasePlayerWeaponR5CSave  @ 0010fcf8
undefined4 Save__17CBasePlayerWeaponR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__15CBasePlayerItemR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBasePlayerWeapon",param_1,_17CBasePlayerWeapon_m_SaveData,7);
  }
  return uVar2;
}


// Save__17CFrictionModifierR5CSave  @ 00101638
undefined4 Save__17CFrictionModifierR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFrictionModifier",param_1,_17CFrictionModifier_m_SaveData,1);
  }
  return uVar2;
}


// Save__17CFuncTankControlsR5CSave  @ 000a26d4
undefined4 Save__17CFuncTankControlsR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncTankControls",param_1,_17CFuncTankControls_m_SaveData,1);
  }
  return uVar2;
}


// Save__17CScriptedSentenceR5CSave  @ 000dd4f0
undefined4 Save__17CScriptedSentenceR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseToggleR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CScriptedSentence",param_1,_17CScriptedSentence_m_SaveData,9);
  }
  return uVar2;
}


// Save__19CMomentaryRotButtonR5CSave  @ 00084814
undefined4 Save__19CMomentaryRotButtonR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseToggleR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CMomentaryRotButton",param_1,_19CMomentaryRotButton_m_SaveData,6);
  }
  return uVar2;
}


// Save__20CTriggerChangeTargetR5CSave  @ 00105018
undefined4 Save__20CTriggerChangeTargetR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__10CBaseDelayR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CTriggerChangeTarget",param_1,_20CTriggerChangeTarget_m_SaveData,1);
  }
  return uVar2;
}


// Save__5CGlowR5CSave  @ 00098870
undefined4 Save__5CGlowR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CGlow",param_1,_5CGlow_m_SaveData,2);
  }
  return uVar2;
}


// Save__6CLaserR5CSave  @ 000980f4
undefined4 Save__6CLaserR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CLaser",param_1,_6CLaser_m_SaveData,3);
  }
  return uVar2;
}


// Save__6CLightR5CSave  @ 000abd84
undefined4 Save__6CLightR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CLight",param_1,_6CLight_m_SaveData,2);
  }
  return uVar2;
}


// Save__7CCyclerR5CSave  @ 000a94fc
undefined4 Save__7CCyclerR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__12CBaseMonsterR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CCycler",param_1,_7CCycler_m_SaveData,1);
  }
  return uVar2;
}


// Save__7CSpriteR5CSave  @ 00098b40
undefined4 Save__7CSpriteR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CSprite",param_1,_7CSprite_m_SaveData,2);
  }
  return uVar2;
}


// Save__7CTurretR5CSave  @ 00106850
undefined4 Save__7CTurretR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseTurretR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CTurret",param_1,_7CTurret_m_SaveData,1);
  }
  return uVar2;
}


// Save__8CAirtankR5CSave  @ 0007f164
undefined4 Save__8CAirtankR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__12CBaseMonsterR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CAirtank",param_1,_8CAirtank_m_SaveData,1);
  }
  return uVar2;
}


// Save__8CSpeakerR5CSave  @ 000e3814
undefined4 Save__8CSpeakerR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CSpeaker",param_1,_8CSpeaker_m_SaveData,1);
  }
  return uVar2;
}


// Save__8CXenTreeR5CSave  @ 00114ba8
undefined4 Save__8CXenTreeR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__13CActAnimatingR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CXenTree",param_1,_8CXenTree_m_SaveData,1);
  }
  return uVar2;
}


// Save__9CBaseDoorR5CSave  @ 00092f18
undefined4 Save__9CBaseDoorR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseToggleR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBaseDoor",param_1,_9CBaseDoor_m_SaveData,7);
  }
  return uVar2;
}


// Save__9CBubblingR5CSave  @ 0009561c
undefined4 Save__9CBubblingR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CBubbling",param_1,_9CBubbling_m_SaveData,3);
  }
  return uVar2;
}


// Save__9CEnvSoundR5CSave  @ 000e1d38
undefined4 Save__9CEnvSoundR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CEnvSound",param_1,_9CEnvSound_m_SaveData,2);
  }
  return uVar2;
}


// Save__9CEnvSparkR5CSave  @ 000851e0
undefined4 Save__9CEnvSparkR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CEnvSpark",param_1,_9CEnvSpark_m_SaveData,1);
  }
  return uVar2;
}


// Save__9CFuncTankR5CSave  @ 0009f934
undefined4 Save__9CFuncTankR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CFuncTank",param_1,_9CFuncTank_m_SaveData,0x19);
  }
  return uVar2;
}


// Save__9CPendulumR5CSave  @ 00081bc0
undefined4 Save__9CPendulumR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CPendulum",param_1,_9CPendulum_m_SaveData,8);
  }
  return uVar2;
}


// Save__9CPushableR5CSave  @ 0009f078
undefined4 Save__9CPushableR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__10CBreakableR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CPushable",param_1,_9CPushable_m_SaveData,2);
  }
  return uVar2;
}


// Save__9CRechargeR5CSave  @ 000a8584
undefined4 Save__9CRechargeR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__11CBaseEntityR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CRecharge",param_1,_9CRecharge_m_SaveData,5);
  }
  return uVar2;
}


// Save__9CWreckageR5CSave  @ 000a9ffc
undefined4 Save__9CWreckageR5CSave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Save__12CBaseMonsterR5CSave(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
                      (param_2,"CWreckage",param_1,_9CWreckage_m_SaveData,1);
  }
  return uVar2;
}


