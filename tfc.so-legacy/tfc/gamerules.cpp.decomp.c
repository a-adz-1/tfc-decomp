// Ghidra decompilation of functions from tfc/gamerules.cpp
// 96 functions, ordered by original source line

// CGameRules::CanHaveAmmo  @ 000d9aa0  (line 48)

/* DWARF original prototype: BOOL CanHaveAmmo(CGameRules * this, CBasePlayer * pPlayer, char *
   pszAmmoName, int iMaxCarry) */

BOOL __thiscall
CGameRules::CanHaveAmmo(CGameRules *this,CBasePlayer *pPlayer,char *pszAmmoName,int iMaxCarry)

{
  int iVar1;
  uint uVar2;
  
                    /* Unresolved local var: int iAmmoIndex@[???] */
  uVar2 = 0;
  if (pszAmmoName != (char *)0x0) {
    iVar1 = CBasePlayer::GetAmmoIndex(pszAmmoName);
    if (-1 < iVar1) {
      iVar1 = CBasePlayer::AmmoInventory(pPlayer,iVar1);
      uVar2 = (uint)(iVar1 < iMaxCarry);
    }
  }
  return uVar2;
}


// CGameRules::GetPlayerSpawnSpot  @ 000d9620  (line 71)

/* WARNING: Variable defined which should be unmapped: pDeath */
/* DWARF original prototype: void GetPlayerSpawnSpot(CGameRules * this, CBasePlayer * pPlayer) */

void __thiscall CGameRules::GetPlayerSpawnSpot(CGameRules *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  string_t sVar5;
  vec_t vVar6;
  vec_t vVar7;
  vec_t vVar8;
  globalvars_t *pgVar9;
  edict_t *peVar10;
  int iVar11;
  int iVar12;
  CBasePlayer *pCVar13;
  edict_t *peVar14;
  CTelefragDeath *this_00;
  CBasePlayer *pStartEntity;
  CBaseEntity *Goal;
  entvars_t *peVar15;
  longdouble extraout_ST0;
  char *sample;
  CTelefragDeath *pDeath;
  
                    /* Unresolved local var: edict_t * pentSpawnSpot@[???]
                       Unresolved local var: CBaseEntity * Spot@[DW_OP_reg6(ESI)]
                       Unresolved local var: CBasePlayer * client@[???] */
  peVar10 = EntSelectSpawnPoint(((pPlayer->super_CBaseMonster).super_CBaseToggle.
                                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                pContainingEntity);
  peVar4 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar15 = &peVar10->v;
  if (peVar10 == (edict_t *)0x0) {
    peVar15 = (entvars_t *)0x0;
  }
  fVar2 = (peVar15->origin).z;
  fVar3 = (peVar15->origin).y;
  (peVar4->origin).x = (peVar15->origin).x + 0.0;
  (peVar4->origin).y = fVar3 + 0.0;
  (peVar4->origin).z = fVar2 + 1.0;
  peVar4 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar4,&peVar4->origin);
  vVar8 = g_vecZero.z;
  vVar7 = g_vecZero.y;
  vVar6 = g_vecZero.x;
  peVar4 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar4->v_angle).x = g_vecZero.x;
  (peVar4->v_angle).y = vVar7;
  (peVar4->v_angle).z = vVar8;
  peVar4 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar4->velocity).y = vVar7;
  (peVar4->velocity).x = vVar6;
  (peVar4->velocity).z = vVar8;
  peVar4 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar4->angles).x = (peVar15->angles).x;
  (peVar4->angles).y = (peVar15->angles).y;
  (peVar4->angles).z = (peVar15->angles).z;
  peVar15 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  (peVar15->punchangle).y = vVar7;
  vVar7 = g_vecZero.z;
  (peVar15->punchangle).x = vVar6;
  (peVar15->punchangle).z = vVar7;
  ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->fixangle = 1;
  if (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->playerclass != 0) {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar14 = (*g_engfuncs.pfnCreateEntity)();
    peVar15 = &peVar14->v;
    if (peVar14 == (edict_t *)0x0) {
      peVar15 = (entvars_t *)0x0;
    }
    if ((peVar15->pContainingEntity == (edict_t *)0x0) ||
       (this_00 = peVar15->pContainingEntity->pvPrivateData, this_00 == (CTelefragDeath *)0x0)) {
      this_00 = CBaseEntity::operator_new(0x478,peVar15);
      (this_00->super_CBaseEntity)._vptr_CBaseEntity =
           (_func_int_varargs **)&PTR__CTelefragDeath_00180268;
      (this_00->super_CBaseEntity).pev = peVar15;
    }
    else {
      peVar15 = (this_00->super_CBaseEntity).pev;
    }
    UTIL_SetOrigin(peVar15,&((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->origin);
    ((this_00->super_CBaseEntity).pev)->owner =
         ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->pContainingEntity;
    CTelefragDeath::Spawn(this_00,(CBaseEntity *)0x0);
  }
  (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
  if (extraout_ST0 <= (longdouble)0.5) {
    sample = "misc/r_tele4.wav";
  }
  else {
    sample = "misc/r_tele3.wav";
  }
  EMIT_SOUND_DYN(((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,sample,1.0,0.8,0,100)
  ;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar10 == (edict_t *)0x0) &&
     (peVar10 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar10 == (edict_t *)0x0)) {
    Goal = (CBaseEntity *)0x0;
  }
  else {
    Goal = peVar10->pvPrivateData;
  }
  iVar11 = (*Goal->_vptr_CBaseEntity[10])(Goal);
  pgVar9 = gpGlobals;
  if ((iVar11 == 0x83) && (cb_prematch_time < gpGlobals->time)) {
    sVar5 = Goal->pev->message;
    if ((sVar5 != 0) &&
       ((pPlayer->forced_spawn == 0 &&
        (pPlayer->delayed_spawn_message = sVar5, (Goal->goal_activation & 2) == 0)))) {
      Goal->pev->message = 0;
    }
    if (((Goal->org_message != 0) && (pPlayer->forced_spawn == 0)) &&
       (ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,pgVar9->pStringBase + Goal->org_message
                    ,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0),
       (Goal->goal_activation & 2) == 0)) {
      Goal->org_message = 0;
    }
    DoResults(Goal,pPlayer,1);
    if ((Goal->items != 0) && ((Goal->goal_activation & 1) == 0)) {
      Goal->items = 0;
    }
    if (Goal->goal_effects == 1) {
      Goal->goal_state = 3;
    }
  }
  pPlayer->forced_spawn = 0;
  if (cease_fire != 0) {
    if (no_cease_fire_text == 0) {
      ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,4,"#Game_ceasefire",(char *)0x0,(char *)0x0
                  ,(char *)0x0,(char *)0x0);
    }
    UTIL_LogPrintf("World triggered \"Cease_Fire\"\n");
    ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->iuser4 = 1;
    fVar2 = gpGlobals->time;
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 | 0x10000;
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.immune_to_check = fVar2 + 10.0;
    CBasePlayer::TeamFortress_SetSpeed(pPlayer);
  }
  pStartEntity = (CBasePlayer *)0x0;
  while ((pStartEntity = (CBasePlayer *)
                         UTIL_FindEntityByClassname((CBaseEntity *)pStartEntity,"player"),
         pStartEntity != (CBasePlayer *)0x0 &&
         (peVar10 = ((pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
         peVar10 != (edict_t *)0x0))) {
    iVar11 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar10);
    if (iVar11 == 0) {
      return;
    }
    peVar15 = (pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev;
    if ((((peVar15 != (entvars_t *)0x0) && (pStartEntity != pPlayer)) &&
        (iVar11 = peVar15->iuser2,
        iVar12 = (*g_engfuncs.pfnIndexOfEdict)
                           (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity),
        iVar11 == iVar12)) &&
       (pCVar13 = (CBasePlayer *)EHANDLE::operator_CBaseEntity_(&pStartEntity->m_hObserverTarget),
       pCVar13 == pPlayer)) {
      peVar15 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev;
      peVar4 = (pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev;
      (peVar4->origin).x = (peVar15->origin).x;
      (peVar4->origin).y = (peVar15->origin).y;
      (peVar4->origin).z = (peVar15->origin).z;
      peVar15 = (pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev;
      UTIL_SetOrigin(peVar15,&peVar15->origin);
    }
  }
  return;
}


// CGameRules::CanHavePlayerItem  @ 000d9580  (line 187)

/* DWARF original prototype: BOOL CanHavePlayerItem(CGameRules * this, CBasePlayer * pPlayer,
   CBasePlayerItem * pWeapon) */

BOOL __thiscall
CGameRules::CanHavePlayerItem(CGameRules *this,CBasePlayer *pPlayer,CBasePlayerItem *pWeapon)

{
  int iVar1;
  BOOL BVar2;
  uint uVar3;
  undefined1 local_4c [8];
  int local_44;
  undefined4 local_40;
  
                    /* Unresolved local var: ItemInfo info@[???] */
  uVar3 = 1;
  iVar1 = (*(pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
            [0x45])(pWeapon,local_4c);
  if (iVar1 != 0) {
    if ((local_44 != 0) &&
       (iVar1 = (*this->_vptr_CGameRules[0x28])(this,pPlayer,local_44,local_40), iVar1 != 0)) {
      return 1;
    }
    BVar2 = CBasePlayer::HasPlayerItem(pPlayer,pWeapon);
    uVar3 = (uint)(BVar2 == 0);
  }
  return uVar3;
}


// CGameRules::RefreshSkillData  @ 000d7da0  (line 226)

/* DWARF original prototype: void RefreshSkillData(CGameRules * this) */

void __thiscall CGameRules::RefreshSkillData(CGameRules *this)

{
  gSkillData.turretHealth = 1000.0;
  gSkillData.miniturretHealth = 1000.0;
  gSkillData.sentryHealth = 1000.0;
  gSkillData.plrDmg9MM = 12.0;
  gSkillData.plrDmgMP5 = 12.0;
  gSkillData.plrDmgBuckshot = 20.0;
  gSkillData.plrDmgCrossbowClient = 20.0;
  gSkillData.plrDmgEgonWide = 20.0;
  gSkillData.plrDmgEgonNarrow = 10.0;
  gSkillData.plrDmgHornet = 10.0;
  gSkillData.plrDmgRPG = 120.0;
  gSkillData.plrDmgSatchel = 120.0;
  gSkillData.batteryCapacity = 15.0;
  gSkillData.healthchargerCapacity = 15.0;
  gSkillData.plrDmgM203Grenade = 100.0;
  gSkillData.plrDmgHandGrenade = 100.0;
  gSkillData.plrDmgCrowbar = 25.0;
  gSkillData.plrDmg357 = 40.0;
  gSkillData.plrDmgTripmine = 150.0;
  gSkillData.monDmg12MM = 8.0;
  gSkillData.monDmgMP5 = 3.0;
  gSkillData.monDmg9MM = 5.0;
  gSkillData.suitchargerCapacity = 75.0;
  gSkillData.healthkitCapacity = 25.0;
  gSkillData.monHead = 3.0;
  gSkillData.monChest = 1.0;
  gSkillData.monStomach = 1.0;
  gSkillData.monLeg = 1.0;
  gSkillData.monArm = 1.0;
  gSkillData.plrHead = 3.0;
  gSkillData.plrChest = 1.0;
  gSkillData.plrStomach = 1.0;
  gSkillData.plrLeg = 1.0;
  gSkillData.plrArm = 1.0;
  return;
}


// CHalfLifeRules::CHalfLifeRules  @ 000da070  (line 308)

/* DWARF original prototype: void CHalfLifeRules(CHalfLifeRules * this) */

void __thiscall CHalfLifeRules::CHalfLifeRules(CHalfLifeRules *this)

{
  (this->super_CGameRules)._vptr_CGameRules = (_func_int_varargs **)&PTR_RefreshSkillData_00180088;
  gSkillData.turretHealth = 1000.0;
  gSkillData.miniturretHealth = 1000.0;
  gSkillData.sentryHealth = 1000.0;
  gSkillData.plrDmg9MM = 12.0;
  gSkillData.plrDmgMP5 = 12.0;
  gSkillData.plrDmgBuckshot = 20.0;
  gSkillData.plrDmgCrossbowClient = 20.0;
  gSkillData.plrDmgEgonWide = 20.0;
  gSkillData.plrDmgEgonNarrow = 10.0;
  gSkillData.plrDmgHornet = 10.0;
  gSkillData.plrDmgRPG = 120.0;
  gSkillData.plrDmgSatchel = 120.0;
  gSkillData.batteryCapacity = 15.0;
  gSkillData.healthchargerCapacity = 15.0;
  gSkillData.plrDmgM203Grenade = 100.0;
  gSkillData.plrDmgHandGrenade = 100.0;
  gSkillData.plrDmgCrowbar = 25.0;
  gSkillData.plrDmg357 = 40.0;
  gSkillData.plrDmgTripmine = 150.0;
  gSkillData.monDmg12MM = 8.0;
  gSkillData.monDmgMP5 = 3.0;
  gSkillData.monDmg9MM = 5.0;
  gSkillData.suitchargerCapacity = 75.0;
  gSkillData.healthkitCapacity = 25.0;
  gSkillData.monHead = 3.0;
  gSkillData.monChest = 1.0;
  gSkillData.monStomach = 1.0;
  gSkillData.monLeg = 1.0;
  gSkillData.monArm = 1.0;
  gSkillData.plrHead = 3.0;
  gSkillData.plrChest = 1.0;
  gSkillData.plrStomach = 1.0;
  gSkillData.plrLeg = 1.0;
  gSkillData.plrArm = 1.0;
  return;
}


// CHalfLifeRules::Think  @ 000d7eb0  (line 317)

/* DWARF original prototype: void Think(CHalfLifeRules * this) */

void __thiscall CHalfLifeRules::Think(CHalfLifeRules *this)

{
  return;
}


// CHalfLifeRules::IsMultiplayer  @ 000d7ec0  (line 324)

/* DWARF original prototype: BOOL IsMultiplayer(CHalfLifeRules * this) */

BOOL __thiscall CHalfLifeRules::IsMultiplayer(CHalfLifeRules *this)

{
  return 0;
}


// CHalfLifeRules::IsDeathmatch  @ 000d7ed0  (line 331)

/* DWARF original prototype: BOOL IsDeathmatch(CHalfLifeRules * this) */

BOOL __thiscall CHalfLifeRules::IsDeathmatch(CHalfLifeRules *this)

{
  return 0;
}


// CHalfLifeRules::IsCoOp  @ 000d7ee0  (line 338)

/* DWARF original prototype: BOOL IsCoOp(CHalfLifeRules * this) */

BOOL __thiscall CHalfLifeRules::IsCoOp(CHalfLifeRules *this)

{
  return 0;
}


// CHalfLifeRules::FShouldSwitchWeapon  @ 000d7ef0  (line 344)

/* DWARF original prototype: BOOL FShouldSwitchWeapon(CHalfLifeRules * this, CBasePlayer * pPlayer,
   CBasePlayerItem * pWeapon) */

BOOL __thiscall
CHalfLifeRules::FShouldSwitchWeapon
          (CHalfLifeRules *this,CBasePlayer *pPlayer,CBasePlayerItem *pWeapon)

{
  CBasePlayerItem *pCVar1;
  uint uVar2;
  int iVar3;
  
  pCVar1 = pPlayer->m_pActiveItem;
  uVar2 = 1;
  if (pCVar1 != (CBasePlayerItem *)0x0) {
    iVar3 = (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
              [0x48])(pCVar1);
    uVar2 = (uint)(iVar3 != 0);
  }
  return uVar2;
}


// CHalfLifeRules::GetNextBestWeapon  @ 000d7f20  (line 364)

/* DWARF original prototype: BOOL GetNextBestWeapon(CHalfLifeRules * this, CBasePlayer * pPlayer,
   CBasePlayerItem * pCurrentWeapon) */

BOOL __thiscall
CHalfLifeRules::GetNextBestWeapon
          (CHalfLifeRules *this,CBasePlayer *pPlayer,CBasePlayerItem *pCurrentWeapon)

{
  return 0;
}


// CHalfLifeRules::ClientConnected  @ 000d7f30  (line 371)

/* DWARF original prototype: BOOL ClientConnected(CHalfLifeRules * this, edict_t * pEntity, char *
   pszName, char * pszAddress, char * szRejectReason) */

BOOL __thiscall
CHalfLifeRules::ClientConnected
          (CHalfLifeRules *this,edict_t *pEntity,char *pszName,char *pszAddress,char *szRejectReason
          )

{
  return 1;
}


// CHalfLifeRules::InitHUD  @ 000d7f40  (line 375)

/* DWARF original prototype: void InitHUD(CHalfLifeRules * this, CBasePlayer * pl) */

void __thiscall CHalfLifeRules::InitHUD(CHalfLifeRules *this,CBasePlayer *pl)

{
  return;
}


// CHalfLifeRules::ClientDisconnected  @ 000d7f50  (line 381)

/* DWARF original prototype: void ClientDisconnected(CHalfLifeRules * this, edict_t * pClient) */

void __thiscall CHalfLifeRules::ClientDisconnected(CHalfLifeRules *this,edict_t *pClient)

{
  return;
}


// CHalfLifeRules::FlPlayerFallDamage  @ 000d7f60  (line 386)

/* DWARF original prototype: float FlPlayerFallDamage(CHalfLifeRules * this, CBasePlayer * pPlayer)
    */

float __thiscall CHalfLifeRules::FlPlayerFallDamage(CHalfLifeRules *this,CBasePlayer *pPlayer)

{
  float fVar1;
  
  fVar1 = pPlayer->m_flFallVelocity - 650.0;
  pPlayer->m_flFallVelocity = fVar1;
  return (fVar1 * 100.0) / 374.0;
}


// CHalfLifeRules::PlayerSpawn  @ 000d7f90  (line 397)

/* DWARF original prototype: void PlayerSpawn(CHalfLifeRules * this, CBasePlayer * pPlayer) */

void __thiscall CHalfLifeRules::PlayerSpawn(CHalfLifeRules *this,CBasePlayer *pPlayer)

{
  return;
}


// CHalfLifeRules::AllowAutoTargetCrosshair  @ 000d7fa0  (line 403)

/* DWARF original prototype: BOOL AllowAutoTargetCrosshair(CHalfLifeRules * this) */

BOOL __thiscall CHalfLifeRules::AllowAutoTargetCrosshair(CHalfLifeRules *this)

{
  return (uint)(g_iSkillLevel == 1);
}


// CHalfLifeRules::PlayerThink  @ 000d7fb0  (line 410)

/* DWARF original prototype: void PlayerThink(CHalfLifeRules * this, CBasePlayer * pPlayer) */

void __thiscall CHalfLifeRules::PlayerThink(CHalfLifeRules *this,CBasePlayer *pPlayer)

{
  return;
}


// CHalfLifeRules::FPlayerCanRespawn  @ 000d7fc0  (line 418)

/* DWARF original prototype: BOOL FPlayerCanRespawn(CHalfLifeRules * this, CBasePlayer * pPlayer) */

BOOL __thiscall CHalfLifeRules::FPlayerCanRespawn(CHalfLifeRules *this,CBasePlayer *pPlayer)

{
  return 1;
}


// CHalfLifeRules::FlPlayerSpawnTime  @ 000d7fd0  (line 424)

/* DWARF original prototype: float FlPlayerSpawnTime(CHalfLifeRules * this, CBasePlayer * pPlayer)
    */

float __thiscall CHalfLifeRules::FlPlayerSpawnTime(CHalfLifeRules *this,CBasePlayer *pPlayer)

{
  return gpGlobals->time;
}


// CHalfLifeRules::IPointsForKill  @ 000d7fe0  (line 434)

/* DWARF original prototype: int IPointsForKill(CHalfLifeRules * this, CBasePlayer * pAttacker,
   CBasePlayer * pKilled) */

int __thiscall
CHalfLifeRules::IPointsForKill(CHalfLifeRules *this,CBasePlayer *pAttacker,CBasePlayer *pKilled)

{
  return 1;
}


// CHalfLifeRules::PlayerKilled  @ 000d7ff0  (line 441)

/* DWARF original prototype: void PlayerKilled(CHalfLifeRules * this, CBasePlayer * pVictim,
   entvars_t * pKiller, entvars_t * pInflictor) */

void __thiscall
CHalfLifeRules::PlayerKilled
          (CHalfLifeRules *this,CBasePlayer *pVictim,entvars_t *pKiller,entvars_t *pInflictor)

{
  return;
}


// CHalfLifeRules::DeathNotice  @ 000d8000  (line 448)

/* DWARF original prototype: void DeathNotice(CHalfLifeRules * this, CBasePlayer * pVictim,
   entvars_t * pKiller, entvars_t * pInflictor) */

void __thiscall
CHalfLifeRules::DeathNotice
          (CHalfLifeRules *this,CBasePlayer *pVictim,entvars_t *pKiller,entvars_t *pInflictor)

{
  return;
}


// CHalfLifeRules::PlayerGotWeapon  @ 000d8010  (line 456)

/* DWARF original prototype: void PlayerGotWeapon(CHalfLifeRules * this, CBasePlayer * pPlayer,
   CBasePlayerItem * pWeapon) */

void __thiscall
CHalfLifeRules::PlayerGotWeapon(CHalfLifeRules *this,CBasePlayer *pPlayer,CBasePlayerItem *pWeapon)

{
  return;
}


// CHalfLifeRules::FlWeaponRespawnTime  @ 000d8020  (line 465)

/* DWARF original prototype: float FlWeaponRespawnTime(CHalfLifeRules * this, CBasePlayerItem *
   pWeapon) */

float __thiscall CHalfLifeRules::FlWeaponRespawnTime(CHalfLifeRules *this,CBasePlayerItem *pWeapon)

{
  return -1.0;
}


// CHalfLifeRules::FlWeaponTryRespawn  @ 000d8030  (line 475)

/* DWARF original prototype: float FlWeaponTryRespawn(CHalfLifeRules * this, CBasePlayerItem *
   pWeapon) */

float __thiscall CHalfLifeRules::FlWeaponTryRespawn(CHalfLifeRules *this,CBasePlayerItem *pWeapon)

{
  return 0.0;
}


// CHalfLifeRules::VecWeaponRespawnSpot  @ 000d8040  (line 483)

/* DWARF original prototype: Vector VecWeaponRespawnSpot(CHalfLifeRules * this, CBasePlayerItem *
   pWeapon) */

Vector * __thiscall
CHalfLifeRules::VecWeaponRespawnSpot
          (Vector *__return_storage_ptr__,CHalfLifeRules *this,CBasePlayerItem *pWeapon)

{
  entvars_t *peVar1;
  
  peVar1 = (pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  __return_storage_ptr__->x = (peVar1->origin).x;
  __return_storage_ptr__->y = (peVar1->origin).y;
  __return_storage_ptr__->z = (peVar1->origin).z;
  return __return_storage_ptr__;
}


// CHalfLifeRules::WeaponShouldRespawn  @ 000d8060  (line 493)

/* DWARF original prototype: int WeaponShouldRespawn(CHalfLifeRules * this, CBasePlayerItem *
   pWeapon) */

int __thiscall CHalfLifeRules::WeaponShouldRespawn(CHalfLifeRules *this,CBasePlayerItem *pWeapon)

{
  return 2;
}


// CHalfLifeRules::CanHaveItem  @ 000d8070  (line 500)

/* DWARF original prototype: BOOL CanHaveItem(CHalfLifeRules * this, CBasePlayer * pPlayer, CItem *
   pItem) */

BOOL __thiscall CHalfLifeRules::CanHaveItem(CHalfLifeRules *this,CBasePlayer *pPlayer,CItem *pItem)

{
  return 1;
}


// CHalfLifeRules::PlayerGotItem  @ 000d8080  (line 506)

/* DWARF original prototype: void PlayerGotItem(CHalfLifeRules * this, CBasePlayer * pPlayer, CItem
   * pItem) */

void __thiscall
CHalfLifeRules::PlayerGotItem(CHalfLifeRules *this,CBasePlayer *pPlayer,CItem *pItem)

{
  return;
}


// CHalfLifeRules::ItemShouldRespawn  @ 000d8090  (line 513)

/* DWARF original prototype: int ItemShouldRespawn(CHalfLifeRules * this, CItem * pItem) */

int __thiscall CHalfLifeRules::ItemShouldRespawn(CHalfLifeRules *this,CItem *pItem)

{
  return 6;
}


// CHalfLifeRules::FlItemRespawnTime  @ 000d80a0  (line 522)

/* DWARF original prototype: float FlItemRespawnTime(CHalfLifeRules * this, CItem * pItem) */

float __thiscall CHalfLifeRules::FlItemRespawnTime(CHalfLifeRules *this,CItem *pItem)

{
  return -1.0;
}


// CHalfLifeRules::VecItemRespawnSpot  @ 000d80b0  (line 530)

/* DWARF original prototype: Vector VecItemRespawnSpot(CHalfLifeRules * this, CItem * pItem) */

Vector * __thiscall
CHalfLifeRules::VecItemRespawnSpot(Vector *__return_storage_ptr__,CHalfLifeRules *this,CItem *pItem)

{
  entvars_t *peVar1;
  
  peVar1 = (pItem->super_CBaseEntity).pev;
  __return_storage_ptr__->x = (peVar1->origin).x;
  __return_storage_ptr__->y = (peVar1->origin).y;
  __return_storage_ptr__->z = (peVar1->origin).z;
  return __return_storage_ptr__;
}


// CHalfLifeRules::IsAllowedToSpawn  @ 000d80d0  (line 538)

/* DWARF original prototype: BOOL IsAllowedToSpawn(CHalfLifeRules * this, CBaseEntity * pEntity) */

BOOL __thiscall CHalfLifeRules::IsAllowedToSpawn(CHalfLifeRules *this,CBaseEntity *pEntity)

{
  return 1;
}


// CHalfLifeRules::PlayerGotAmmo  @ 000d80e0  (line 544)

/* DWARF original prototype: void PlayerGotAmmo(CHalfLifeRules * this, CBasePlayer * pPlayer, char *
   szName, int iCount) */

void __thiscall
CHalfLifeRules::PlayerGotAmmo(CHalfLifeRules *this,CBasePlayer *pPlayer,char *szName,int iCount)

{
  return;
}


// CHalfLifeRules::AmmoShouldRespawn  @ 000d80f0  (line 551)

/* DWARF original prototype: int AmmoShouldRespawn(CHalfLifeRules * this, CBasePlayerAmmo * pAmmo)
    */

int __thiscall CHalfLifeRules::AmmoShouldRespawn(CHalfLifeRules *this,CBasePlayerAmmo *pAmmo)

{
  return 4;
}


// CHalfLifeRules::FlAmmoRespawnTime  @ 000d8100  (line 558)

/* DWARF original prototype: float FlAmmoRespawnTime(CHalfLifeRules * this, CBasePlayerAmmo * pAmmo)
    */

float __thiscall CHalfLifeRules::FlAmmoRespawnTime(CHalfLifeRules *this,CBasePlayerAmmo *pAmmo)

{
  return -1.0;
}


// CHalfLifeRules::VecAmmoRespawnSpot  @ 000d8110  (line 564)

/* DWARF original prototype: Vector VecAmmoRespawnSpot(CHalfLifeRules * this, CBasePlayerAmmo *
   pAmmo) */

Vector * __thiscall
CHalfLifeRules::VecAmmoRespawnSpot
          (Vector *__return_storage_ptr__,CHalfLifeRules *this,CBasePlayerAmmo *pAmmo)

{
  entvars_t *peVar1;
  
  peVar1 = (pAmmo->super_CBaseEntity).pev;
  __return_storage_ptr__->x = (peVar1->origin).x;
  __return_storage_ptr__->y = (peVar1->origin).y;
  __return_storage_ptr__->z = (peVar1->origin).z;
  return __return_storage_ptr__;
}


// CHalfLifeRules::FlHealthChargerRechargeTime  @ 000d8130  (line 572)

/* DWARF original prototype: float FlHealthChargerRechargeTime(CHalfLifeRules * this) */

float __thiscall CHalfLifeRules::FlHealthChargerRechargeTime(CHalfLifeRules *this)

{
  return 0.0;
}


// CHalfLifeRules::DeadPlayerWeapons  @ 000d8140  (line 579)

/* DWARF original prototype: int DeadPlayerWeapons(CHalfLifeRules * this, CBasePlayer * pPlayer) */

int __thiscall CHalfLifeRules::DeadPlayerWeapons(CHalfLifeRules *this,CBasePlayer *pPlayer)

{
  return 9;
}


// CHalfLifeRules::DeadPlayerAmmo  @ 000d8150  (line 586)

/* DWARF original prototype: int DeadPlayerAmmo(CHalfLifeRules * this, CBasePlayer * pPlayer) */

int __thiscall CHalfLifeRules::DeadPlayerAmmo(CHalfLifeRules *this,CBasePlayer *pPlayer)

{
  return 0xc;
}


// CHalfLifeRules::PlayerRelationship  @ 000d8160  (line 594)

/* DWARF original prototype: int PlayerRelationship(CHalfLifeRules * this, CBasePlayer * pPlayer,
   CBaseEntity * pTarget) */

int __thiscall
CHalfLifeRules::PlayerRelationship(CHalfLifeRules *this,CBasePlayer *pPlayer,CBaseEntity *pTarget)

{
  return 0;
}


// CHalfLifeMultiplay::CHalfLifeMultiplay  @ 000da180  (line 601)

/* DWARF original prototype: void CHalfLifeMultiplay(CHalfLifeMultiplay * this) */

void __thiscall CHalfLifeMultiplay::CHalfLifeMultiplay(CHalfLifeMultiplay *this)

{
  int iVar1;
  char *pcVar2;
  char local_10c [264];
  
  (this->super_CGameRules)._vptr_CGameRules = (_func_int_varargs **)&PTR_RefreshSkillData_00180168;
  gSkillData.turretHealth = 1000.0;
  gSkillData.miniturretHealth = 1000.0;
  gSkillData.sentryHealth = 1000.0;
  gSkillData.plrDmgCrowbar = 25.0;
  gSkillData.plrDmg9MM = 12.0;
  gSkillData.plrDmg357 = 40.0;
  gSkillData.plrDmgMP5 = 12.0;
  gSkillData.plrDmgM203Grenade = 100.0;
  gSkillData.plrDmgBuckshot = 20.0;
  gSkillData.plrDmgCrossbowClient = 20.0;
  gSkillData.plrDmgRPG = 120.0;
  gSkillData.plrDmgEgonWide = 20.0;
  gSkillData.plrDmgEgonNarrow = 10.0;
  gSkillData.plrDmgHandGrenade = 100.0;
  gSkillData.plrDmgSatchel = 120.0;
  gSkillData.plrDmgTripmine = 150.0;
  gSkillData.plrDmgHornet = 10.0;
  gSkillData.monDmg12MM = 8.0;
  gSkillData.monDmgMP5 = 3.0;
  gSkillData.monDmg9MM = 5.0;
  gSkillData.suitchargerCapacity = 75.0;
  gSkillData.batteryCapacity = 15.0;
  gSkillData.healthchargerCapacity = 15.0;
  gSkillData.healthkitCapacity = 25.0;
  gSkillData.monHead = 3.0;
  gSkillData.monChest = 1.0;
  gSkillData.monStomach = 1.0;
  gSkillData.monLeg = 1.0;
  gSkillData.monArm = 1.0;
  gSkillData.plrHead = 3.0;
  gSkillData.plrChest = 1.0;
  gSkillData.plrStomach = 1.0;
  gSkillData.plrLeg = 1.0;
  gSkillData.plrArm = 1.0;
  this->m_flIntermissionEndTime = 0.0;
  this->m_flIntermissionStartTime = 0.0;
  iVar1 = (*g_engfuncs.pfnIsDedicatedServer)();
  if (iVar1 == 0) {
                    /* Unresolved local var: char * lservercfgfile@[???] */
    pcVar2 = (*g_engfuncs.pfnCVarGetString)("lservercfgfile");
    if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
                    /* Unresolved local var: char[256] szCommand@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_console,"Executing listen server config file\n");
      sprintf(local_10c,"exec %s\n",pcVar2);
      (*g_engfuncs.pfnServerCommand)(local_10c);
    }
  }
  (*g_engfuncs.pfnServerExecute)();
  pcVar2 = (*g_engfuncs.pfnCVarGetString)("hostname");
  UTIL_LogPrintf("Server name is \"%s\"\n",pcVar2);
  return;
}


// CHalfLifeMultiplay::Think  @ 000d92d0  (line 654)

/* WARNING: Removing unreachable block (ram,0x000d9565) */
/* DWARF original prototype: void Think(CHalfLifeMultiplay * this) */

void __thiscall CHalfLifeMultiplay::Think(CHalfLifeMultiplay *this)

{
  float fVar1;
  float fVar2;
  globalvars_t *pgVar3;
  _func_void_char_ptr_char_ptr *p_Var4;
  _func_void_cvar_s_ptr_char_ptr *p_Var5;
  char *pcVar6;
  int iVar7;
  edict_t *peVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  longdouble extraout_ST0;
  
  fVar2 = fraglimit.value;
                    /* Unresolved local var: int frags_remaining@[???]
                       Unresolved local var: int time_remaining@[???]
                       Unresolved local var: float flTimeLimit@[???]
                       Unresolved local var: float flFragLimit@[???] */
  if (g_fGameOver == 0) {
    fVar1 = timelimit.value * 60.0;
    if (fVar1 == 0.0) {
      iVar10 = 0;
    }
    else {
      iVar10 = (int)(fVar1 - gpGlobals->time);
      if (fVar1 <= gpGlobals->time) {
LAB_000d9456:
                    /* WARNING: Could not recover jumptable at 0x000d9469. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(this->super_CGameRules)._vptr_CGameRules[0x36])();
        return;
      }
    }
    if (fraglimit.value == 0.0) {
      iVar11 = 0;
    }
    else {
                    /* Unresolved local var: int bestfrags@[???]
                       Unresolved local var: int remain@[???]
                       Unresolved local var: int i@[???] */
      if (gpGlobals->maxClients < 1) {
        iVar11 = 9999;
      }
      else {
        iVar9 = 1;
        iVar11 = 9999;
        do {
          peVar8 = (*g_engfuncs.pfnPEntityOfEntIndex)(iVar9);
          if (peVar8 != (edict_t *)0x0) {
            fVar1 = (peVar8->v).frags;
            if (fVar2 <= fVar1) goto LAB_000d9456;
                    /* Unresolved local var: edict_t * cl@[DW_OP_reg0(EAX)] */
            iVar7 = (int)(fVar2 - fVar1);
            if (iVar7 < iVar11) {
              iVar11 = iVar7;
            }
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 <= gpGlobals->maxClients);
      }
    }
    p_Var5 = g_engfuncs.pfnCvar_DirectSet;
    if (iVar11 != Think::lexical_block_0::last_frags) {
      pcVar6 = UTIL_VarArgs("%i",iVar11);
      (*p_Var5)(&fragsleft,pcVar6);
    }
    p_Var5 = g_engfuncs.pfnCvar_DirectSet;
    if (timeleft.value != (float)Think::lexical_block_0::last_time) {
      pcVar6 = UTIL_VarArgs("%i",iVar10);
      (*p_Var5)(&timeleft,pcVar6);
    }
  }
  else {
                    /* Unresolved local var: int time@[???] */
    (*g_engfuncs.pfnCVarGetFloat)("mp_chattime");
    p_Var4 = g_engfuncs.pfnCVarSetString;
    if ((int)extraout_ST0 < 1) {
      (*g_engfuncs.pfnCVarSetString)("mp_chattime","1");
    }
    else if (0x78 < (int)extraout_ST0) {
      pcVar6 = UTIL_dtos1(0x78);
      (*p_Var4)("mp_chattime",pcVar6);
    }
    pgVar3 = gpGlobals;
    fVar2 = mp_chattime.value + this->m_flIntermissionStartTime;
    this->m_flIntermissionEndTime = fVar2;
    iVar11 = Think::lexical_block_0::last_frags;
    iVar10 = Think::lexical_block_0::last_time;
    if ((fVar2 < pgVar3->time) &&
       ((this->m_iEndIntermissionButtonHit != 0 ||
        (this->m_flIntermissionStartTime + 120.0 < pgVar3->time)))) {
                    /* WARNING: Could not recover jumptable at 0x000d94e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(this->super_CGameRules)._vptr_CGameRules[0x37])();
      return;
    }
  }
  Think::lexical_block_0::last_time = iVar10;
  Think::lexical_block_0::last_frags = iVar11;
  return;
}


// CHalfLifeMultiplay::IsMultiplayer  @ 000d8170  (line 744)

/* DWARF original prototype: BOOL IsMultiplayer(CHalfLifeMultiplay * this) */

BOOL __thiscall CHalfLifeMultiplay::IsMultiplayer(CHalfLifeMultiplay *this)

{
  return 1;
}


// CHalfLifeMultiplay::IsDeathmatch  @ 000d8180  (line 751)

/* DWARF original prototype: BOOL IsDeathmatch(CHalfLifeMultiplay * this) */

BOOL __thiscall CHalfLifeMultiplay::IsDeathmatch(CHalfLifeMultiplay *this)

{
  return 1;
}


// CHalfLifeMultiplay::IsCoOp  @ 000d8190  (line 758)

/* DWARF original prototype: BOOL IsCoOp(CHalfLifeMultiplay * this) */

BOOL __thiscall CHalfLifeMultiplay::IsCoOp(CHalfLifeMultiplay *this)

{
  return 0;
}


// CHalfLifeMultiplay::FShouldSwitchWeapon  @ 000d81a0  (line 798)

/* DWARF original prototype: BOOL FShouldSwitchWeapon(CHalfLifeMultiplay * this, CBasePlayer *
   pPlayer, CBasePlayerItem * pWeapon) */

BOOL __thiscall
CHalfLifeMultiplay::FShouldSwitchWeapon
          (CHalfLifeMultiplay *this,CBasePlayer *pPlayer,CBasePlayerItem *pWeapon)

{
  return 0;
}


// CHalfLifeMultiplay::ClientCommand  @ 000d9ef0  (line 801)

/* DWARF original prototype: BOOL ClientCommand(CHalfLifeMultiplay * this, CBasePlayer * pPlayer,
   char * pcmd) */

BOOL __thiscall
CHalfLifeMultiplay::ClientCommand(CHalfLifeMultiplay *this,CBasePlayer *pPlayer,char *pcmd)

{
  char *__nptr;
  long lVar1;
  int iVar2;
  BOOL BVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  
  bVar5 = &stack0x00000000 < (undefined1 *)0x2c;
  bVar6 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar2 = 0xb;
  pbVar4 = (byte *)"menuselect";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = (byte)*pcmd < *pbVar4;
    bVar6 = *pcmd == *pbVar4;
    pcmd = pcmd + 1;
    pbVar4 = pbVar4 + 1;
  } while (bVar6);
  BVar3 = 0;
  if ((!bVar5 && !bVar6) == bVar5) {
                    /* Unresolved local var: int slot@[???] */
    iVar2 = (*g_engfuncs.pfnCmd_Argc)();
    BVar3 = 1;
    if (1 < iVar2) {
                    /* Unresolved local var: int slot@[DW_OP_reg0(EAX)] */
      __nptr = (*g_engfuncs.pfnCmd_Argv)(1);
      lVar1 = strtol(__nptr,(char **)0x0,10);
      CBasePlayer::Menu_Input(pPlayer,(float)lVar1);
      return 1;
    }
  }
  return BVar3;
}


// CHalfLifeMultiplay::GetNextBestWeapon  @ 000d9c80  (line 819)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL GetNextBestWeapon(CHalfLifeMultiplay * this, CBasePlayer *
   pPlayer, CBasePlayerItem * pCurrentWeapon) */

BOOL __thiscall
CHalfLifeMultiplay::GetNextBestWeapon
          (CHalfLifeMultiplay *this,CBasePlayer *pPlayer,CBasePlayerItem *pCurrentWeapon)

{
  int iVar1;
  CBasePlayerItem *pCVar2;
  int iVar3;
  int iVar4;
  BOOL BVar5;
  CBasePlayerItem *pWeapon;
  CBasePlayer *local_58;
  CBasePlayerItem *local_54;
  undefined1 local_4c [40];
  int local_24;
  
                    /* Unresolved local var: CBasePlayerItem * pCheck@[???]
                       Unresolved local var: CBasePlayerItem * pBest@[???]
                       Unresolved local var: ItemInfo Info@[???]
                       Unresolved local var: int iBestWeight@[???]
                       Unresolved local var: int iCurrentWeight@[???]
                       Unresolved local var: int i@[???] */
  iVar3 = (*(pCurrentWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x48])(pCurrentWeapon);
  if (iVar3 == 0) {
    return 0;
  }
                    /* Unresolved local var: CBasePlayerItem * pCheck@[???]
                       Unresolved local var: CBasePlayerItem * pBest@[???]
                       Unresolved local var: ItemInfo Info@[???]
                       Unresolved local var: int iBestWeight@[???]
                       Unresolved local var: int iCurrentWeight@[???]
                       Unresolved local var: int i@[???] */
  iVar3 = -1;
  (*(pCurrentWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
    [0x45])(pCurrentWeapon,local_4c);
  iVar1 = local_24;
  local_54 = (CBasePlayerItem *)0x0;
  local_58 = pPlayer;
  do {
    pCVar2 = local_58->m_rgpPlayerItems[0];
joined_r0x000d9cf1:
    pWeapon = pCVar2;
    if (pWeapon != (CBasePlayerItem *)0x0) {
      do {
        (*(pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x45]
        )(pWeapon,local_4c);
        if (local_24 < 0) {
LAB_000d9d29:
          if (((pCurrentWeapon != pWeapon) && (iVar3 < local_24)) &&
             (iVar4 = (*(pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                        _vptr_CBaseEntity[0x46])(pWeapon), iVar4 != 0)) goto code_r0x000d9d40;
        }
        else if (pCurrentWeapon != pWeapon) {
          if (iVar1 != local_24) goto LAB_000d9d29;
          iVar4 = (*(pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                    _vptr_CBaseEntity[0x46])(pWeapon);
          if ((iVar4 != 0) && (BVar5 = CBasePlayer::SwitchWeapon(pPlayer,pWeapon), BVar5 != 0)) {
            return 1;
          }
        }
        pWeapon = pWeapon->m_pNext;
        if (pWeapon == (CBasePlayerItem *)0x0) break;
      } while( true );
    }
    local_58 = (CBasePlayer *)
               &(local_58->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev;
    if (local_58 ==
        (CBasePlayer *)
        &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.m_pfnTouch) {
      if (local_54 == (CBasePlayerItem *)0x0) {
        return 0;
      }
      CBasePlayer::SwitchWeapon(pPlayer,local_54);
      return 1;
    }
  } while( true );
code_r0x000d9d40:
  pCVar2 = pWeapon->m_pNext;
  iVar3 = local_24;
  local_54 = pWeapon;
  goto joined_r0x000d9cf1;
}


// CHalfLifeMultiplay::ClientConnected  @ 000d9190  (line 897)

/* WARNING: Variable defined which should be unmapped: pColon */
/* DWARF original prototype: BOOL ClientConnected(CHalfLifeMultiplay * this, edict_t * pEntity, char
   * pszName, char * pszAddress, char * szRejectReason) */

BOOL __thiscall
CHalfLifeMultiplay::ClientConnected
          (CHalfLifeMultiplay *this,edict_t *pEntity,char *pszName,char *pszAddress,
          char *szRejectReason)

{
  int iVar1;
  char *pcVar2;
  CGhost *pCVar3;
  int iVar4;
  char *pColon;
  
                    /* Unresolved local var: CGhost * pGhost@[???]
                       Unresolved local var: int iGhostID@[???] */
  iVar1 = GetBattleID(pEntity);
  pCVar3 = (CGhost *)0x0;
  if (iVar1 != 0) {
    pCVar3 = FindGhost(iVar1);
  }
  if (((tfc_clanbattle_locked.value != 0.0) && (pCVar3 == (CGhost *)0x0)) &&
     (cb_prematch_time < gpGlobals->time)) {
    builtin_strncpy(szRejectReason,"#Game_locked",0xd);
    return 0;
  }
                    /* Unresolved local var: int i@[???] */
  if (-1 < gpGlobals->maxClients) {
    iVar4 = 0;
    iVar1 = g_IpStorage[0].ip;
    while (iVar1 != 0) {
      iVar4 = iVar4 + 1;
      if (gpGlobals->maxClients < iVar4) {
        return 1;
      }
      iVar1 = g_IpStorage[iVar4].ip;
    }
    pcVar2 = strchr(pszAddress,0x3a);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '\0';
      iVar1 = (*g_engfuncs.pfnAllocString)(pszAddress);
      g_IpStorage[iVar4].pEdict = pEntity;
      g_IpStorage[iVar4].ip = iVar1;
      *pcVar2 = ':';
      return 1;
    }
    iVar1 = (*g_engfuncs.pfnAllocString)(pszAddress);
    g_IpStorage[iVar4].pEdict = pEntity;
    g_IpStorage[iVar4].ip = iVar1;
  }
  return 1;
}


// CHalfLifeMultiplay::UpdateGameMode  @ 000d81b0  (line 946)

/* DWARF original prototype: void UpdateGameMode(CHalfLifeMultiplay * this, CBasePlayer * pPlayer)
    */

void __thiscall CHalfLifeMultiplay::UpdateGameMode(CHalfLifeMultiplay *this,CBasePlayer *pPlayer)

{
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgGameMode,(float *)0x0,
             ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(0);
                    /* WARNING: Could not recover jumptable at 0x000d81f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CHalfLifeMultiplay::InitHUD  @ 000d8f10  (line 955)

/* DWARF original prototype: void InitHUD(CHalfLifeMultiplay * this, CBasePlayer * pl) */

void __thiscall CHalfLifeMultiplay::InitHUD(CHalfLifeMultiplay *this,CBasePlayer *pl)

{
  string_t sVar1;
  void *pvVar2;
  _func_void_int *p_Var3;
  char *param1;
  int iVar4;
  edict_t *peVar5;
  
  sVar1 = ((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->netname;
  param1 = "unconnected";
  if ((sVar1 != 0) && (param1 = gpGlobals->pStringBase + sVar1, *param1 == '\0')) {
    param1 = "unconnected";
  }
  UTIL_ClientPrintAll(1,"#Game_playerjoin",param1,(char *)0x0,(char *)0x0,(char *)0x0);
  (*(this->super_CGameRules)._vptr_CGameRules[0xe])(this,pl);
  pl->m_MenuUpdateTime = gpGlobals->time + 0.1;
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgScoreInfo,(float *)0x0,
             ((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  p_Var3 = g_engfuncs.pfnWriteByte;
  iVar4 = (*g_engfuncs.pfnIndexOfEdict)
                    (((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var3)(iVar4);
  (*g_engfuncs.pfnWriteShort)(0);
  (*g_engfuncs.pfnWriteShort)(0);
  (*g_engfuncs.pfnWriteShort)(0);
  (*g_engfuncs.pfnWriteShort)(0);
  (*g_engfuncs.pfnMessageEnd)();
                    /* Unresolved local var: int i@[???] */
  if (0 < gpGlobals->maxClients) {
    iVar4 = 1;
    do {
                    /* Unresolved local var: edict_t * ed@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBasePlayer * plr@[???] */
      peVar5 = (*g_engfuncs.pfnPEntityOfEntIndex)(iVar4);
      if ((peVar5 != (edict_t *)0x0) && (pvVar2 = peVar5->pvPrivateData, pvVar2 != (void *)0x0)) {
        (*g_engfuncs.pfnMessageBegin)
                  (1,gmsgScoreInfo,(float *)0x0,
                   ((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                    .super_CBaseEntity.pev)->pContainingEntity);
        (*g_engfuncs.pfnWriteByte)(iVar4);
        (*g_engfuncs.pfnWriteShort)((int)*(float *)(*(int *)((int)pvVar2 + 4) + 0x164));
        (*g_engfuncs.pfnWriteShort)(*(int *)((int)pvVar2 + 0xa1c));
        (*g_engfuncs.pfnWriteShort)(*(int *)(*(int *)((int)pvVar2 + 4) + 0x20c));
        (*g_engfuncs.pfnWriteShort)(*(int *)(*(int *)((int)pvVar2 + 4) + 0x1ac));
        (*g_engfuncs.pfnMessageEnd)();
        (*g_engfuncs.pfnMessageBegin)
                  (1,gmsgSpectator,(float *)0x0,
                   ((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                    .super_CBaseEntity.pev)->pContainingEntity);
        (*g_engfuncs.pfnWriteByte)(iVar4);
        (*g_engfuncs.pfnWriteByte)((uint)(*(int *)(*(int *)((int)pvVar2 + 4) + 0x244) != 0));
        (*g_engfuncs.pfnMessageEnd)();
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= gpGlobals->maxClients);
  }
  SendBuildingEventInfo(pl);
  if (g_fGameOver == 0) {
    return;
  }
  (*g_engfuncs.pfnMessageBegin)
            (1,0x1e,(float *)0x0,
             ((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
                    /* WARNING: Could not recover jumptable at 0x000d9184. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CHalfLifeMultiplay::ClientDisconnected  @ 000d8d80  (line 1014)

/* DWARF original prototype: void ClientDisconnected(CHalfLifeMultiplay * this, edict_t * pClient)
    */

void __thiscall CHalfLifeMultiplay::ClientDisconnected(CHalfLifeMultiplay *this,edict_t *pClient)

{
  CBasePlayer *this_00;
  _func_void_int *p_Var1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  
                    /* Unresolved local var: CBasePlayer * pPlayer@[DW_OP_reg3(EBX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((pClient != (edict_t *)0x0) &&
     (this_00 = pClient->pvPrivateData, this_00 != (CBasePlayer *)0x0)) {
    iVar3 = (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
    pcVar4 = "SPECTATOR";
    (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.has_disconnected = 1;
    if (iVar3 != 0) {
      pcVar4 = GetTeamName(iVar3);
    }
    pcVar2 = (*g_engfuncs.pfnGetPlayerAuthId)
                       (((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar3 = (*g_engfuncs.pfnGetPlayerUserId)
                      (((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" disconnected\n",
                   gpGlobals->pStringBase +
                   ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar3,pcVar2,pcVar4);
    CBasePlayer::CleanupOnPlayerDisconnection(this_00);
    if ((tfc_clanbattle.value != 0.0) &&
       ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.tf_id != 0)) {
      CBasePlayer::CreateGhost(this_00);
    }
    ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->playerclass = 0;
    ((this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->health = 0.0;
    CBasePlayer::RemoveAllItems(this_00,0);
    (*g_engfuncs.pfnMessageBegin)(2,gmsgSpectator,(float *)0x0,(edict_t *)0x0);
    p_Var1 = g_engfuncs.pfnWriteByte;
    iVar3 = (*g_engfuncs.pfnIndexOfEdict)(pClient);
    (*p_Var1)(iVar3);
    (*g_engfuncs.pfnWriteByte)(0);
                    /* WARNING: Could not recover jumptable at 0x000d8ec3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnMessageEnd)();
    return;
  }
  return;
}


// CHalfLifeMultiplay::FlPlayerFallDamage  @ 000d9ae0  (line 1053)

/* DWARF original prototype: float FlPlayerFallDamage(CHalfLifeMultiplay * this, CBasePlayer *
   pPlayer) */

float __thiscall
CHalfLifeMultiplay::FlPlayerFallDamage(CHalfLifeMultiplay *this,CBasePlayer *pPlayer)

{
  float fVar1;
  
                    /* Unresolved local var: int iFallDamage@[???] */
  if ((int)falldamage.value != 1) {
    return 10.0;
  }
                    /* Unresolved local var: int iFallDamage@[???] */
  fVar1 = pPlayer->m_flFallVelocity - 650.0;
  pPlayer->m_flFallVelocity = fVar1;
  return (fVar1 * 100.0) / 374.0;
}


// CHalfLifeMultiplay::FPlayerCanTakeDamage  @ 000d8200  (line 1073)

/* DWARF original prototype: BOOL FPlayerCanTakeDamage(CHalfLifeMultiplay * this, CBasePlayer *
   pPlayer, CBaseEntity * pAttacker) */

BOOL __thiscall
CHalfLifeMultiplay::FPlayerCanTakeDamage
          (CHalfLifeMultiplay *this,CBasePlayer *pPlayer,CBaseEntity *pAttacker)

{
  return 1;
}


// CHalfLifeMultiplay::PlayerThink  @ 000d9b20  (line 1079)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlayerThink(CHalfLifeMultiplay * this, CBasePlayer * pPlayer) */

void __thiscall CHalfLifeMultiplay::PlayerThink(CHalfLifeMultiplay *this,CBasePlayer *pPlayer)

{
  if (g_fGameOver != 0) {
    if ((pPlayer->m_afButtonPressed & 0x827U) != 0) {
      this->m_iEndIntermissionButtonHit = 1;
    }
    pPlayer->m_afButtonPressed = 0;
    ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->button = 0;
    pPlayer->m_afButtonReleased = 0;
  }
  return;
}


// CHalfLifeMultiplay::PlayerSpawn  @ 000d8d10  (line 1095)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlayerSpawn(CHalfLifeMultiplay * this, CBasePlayer * pPlayer) */

void __thiscall CHalfLifeMultiplay::PlayerSpawn(CHalfLifeMultiplay *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  
  piVar1 = &((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->weapons;
  *piVar1 = *piVar1 | 0x80000000;
  CBasePlayer::GiveNamedItem(pPlayer,"weapon_crowbar");
  CBasePlayer::GiveNamedItem(pPlayer,"weapon_9mmhandgun");
  (*(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x18])(pPlayer,0x44,&DAT_0017fd01,0xfa,0);
  return;
}


// CHalfLifeMultiplay::FPlayerCanRespawn  @ 000d8210  (line 1107)

/* DWARF original prototype: BOOL FPlayerCanRespawn(CHalfLifeMultiplay * this, CBasePlayer *
   pPlayer) */

BOOL __thiscall CHalfLifeMultiplay::FPlayerCanRespawn(CHalfLifeMultiplay *this,CBasePlayer *pPlayer)

{
  return 1;
}


// CHalfLifeMultiplay::FlPlayerSpawnTime  @ 000d8220  (line 1113)

/* DWARF original prototype: float FlPlayerSpawnTime(CHalfLifeMultiplay * this, CBasePlayer *
   pPlayer) */

float __thiscall
CHalfLifeMultiplay::FlPlayerSpawnTime(CHalfLifeMultiplay *this,CBasePlayer *pPlayer)

{
  return gpGlobals->time;
}


// CHalfLifeMultiplay::AllowAutoTargetCrosshair  @ 000d8230  (line 1118)

/* DWARF original prototype: BOOL AllowAutoTargetCrosshair(CHalfLifeMultiplay * this) */

BOOL __thiscall CHalfLifeMultiplay::AllowAutoTargetCrosshair(CHalfLifeMultiplay *this)

{
  uint uVar1;
  
  uVar1 = 1;
  if (aimcrosshair.value == 0.0) {
    uVar1 = (uint)NAN(aimcrosshair.value);
  }
  return uVar1;
}


// CHalfLifeMultiplay::IPointsForKill  @ 000d8250  (line 1128)

/* DWARF original prototype: int IPointsForKill(CHalfLifeMultiplay * this, CBasePlayer * pAttacker,
   CBasePlayer * pKilled) */

int __thiscall
CHalfLifeMultiplay::IPointsForKill
          (CHalfLifeMultiplay *this,CBasePlayer *pAttacker,CBasePlayer *pKilled)

{
  return 1;
}


// CHalfLifeMultiplay::PlayerKilled  @ 000d8be0  (line 1135)

/* WARNING: Variable defined which should be unmapped: ktmp */
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlayerKilled(CHalfLifeMultiplay * this, CBasePlayer * pVictim,
   entvars_t * pKiller, entvars_t * pInflictor) */

void __thiscall
CHalfLifeMultiplay::PlayerKilled
          (CHalfLifeMultiplay *this,CBasePlayer *pVictim,entvars_t *pKiller,entvars_t *pInflictor)

{
  int *piVar1;
  int iVar2;
  edict_t *peVar3;
  CBasePlayer *this_00;
  CBaseEntity *ktmp;
  
                    /* Unresolved local var: CBasePlayer * peKiller@[???]
                       Unresolved local var: CBaseEntity * ep@[DW_OP_reg3(EBX)] */
  (*(this->super_CGameRules)._vptr_CGameRules[0x1c])(this,pVictim,pKiller,pInflictor);
  pVictim->m_iDeaths = pVictim->m_iDeaths + 1;
  peVar3 = pKiller->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((((peVar3 == (edict_t *)0x0) &&
       (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 == (edict_t *)0x0)) ||
      (this_00 = peVar3->pvPrivateData, this_00 == (CBasePlayer *)0x0)) ||
     (iVar2 = (*(this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[10])(this_00), iVar2 != 2)) {
    this_00 = (CBasePlayer *)0x0;
  }
  if (((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev == pKiller) || ((pKiller->flags & 8) == 0)) {
    CBasePlayer::TF_AddFrags(pVictim,-1);
  }
  else {
    iVar2 = (*(this->super_CGameRules)._vptr_CGameRules[0x1a])(this,this_00,pVictim);
    CBasePlayer::TF_AddFrags(this_00,iVar2);
  }
  peVar3 = pKiller->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((peVar3 != (edict_t *)0x0) ||
      (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 != (edict_t *)0x0)) &&
     ((piVar1 = peVar3->pvPrivateData, piVar1 != (int *)0x0 &&
      (iVar2 = (**(code **)(*piVar1 + 0x28))(piVar1), iVar2 == 2)))) {
                    /* Unresolved local var: CBasePlayer * PK@[???] */
    piVar1[0x298] = (int)gpGlobals->time;
  }
  return;
}


// CHalfLifeMultiplay::DeathNotice  @ 000d8570  (line 1174)

/* DWARF original prototype: void DeathNotice(CHalfLifeMultiplay * this, CBasePlayer * pVictim,
   entvars_t * pKiller, entvars_t * pevInflictor) */

void __thiscall
CHalfLifeMultiplay::DeathNotice
          (CHalfLifeMultiplay *this,CBasePlayer *pVictim,entvars_t *pKiller,entvars_t *pevInflictor)

{
  string_t sVar1;
  uint uVar2;
  int *piVar3;
  _func_void_int *p_Var4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  entvars_t *peVar8;
  edict_t *peVar9;
  int iVar10;
  char *pcVar11;
  byte *pbVar12;
  char *pcVar13;
  void *pvVar14;
  byte *pbVar15;
  bool bVar16;
  bool bVar17;
  byte bVar18;
  byte *local_5c;
  char *local_58;
  undefined1 local_4c [24];
  byte *local_34;
  
  bVar18 = 0;
                    /* Unresolved local var: CBaseEntity * Killer@[???]
                       Unresolved local var: char * killer_weapon_name@[???]
                       Unresolved local var: int killer_index@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  if (pKiller->pContainingEntity == (edict_t *)0x0) {
    (*g_engfuncs.pfnPEntityOfEntOffset)(0);
  }
  iVar10 = 0;
  local_5c = (byte *)g_pszDeathType;
  pbVar12 = local_5c;
  if (g_pszDeathType != (char *)0x0) goto LAB_000d85a9;
  if ((pKiller->flags & 8) == 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg0(EAX)] */
    peVar9 = pevInflictor->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (((peVar9 == (edict_t *)0x0) &&
        (peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar9 == (edict_t *)0x0)) ||
       ((peVar9->pvPrivateData == (void *)0x0 ||
        (uVar2 = *(uint *)((int)peVar9->pvPrivateData + 0x418), uVar2 == 0)))) {
      local_5c = (byte *)(gpGlobals->pStringBase + pevInflictor->classname);
      bVar16 = false;
      iVar10 = 0;
      bVar17 = true;
    }
    else {
      iVar10 = 0;
      bVar16 = CARRY4(uVar2,(uint)gpGlobals->pStringBase);
      local_5c = (byte *)(gpGlobals->pStringBase + uVar2);
      bVar17 = local_5c == (byte *)0x0;
    }
    goto LAB_000d892d;
  }
  iVar10 = (*g_engfuncs.pfnIndexOfEdict)(pKiller->pContainingEntity);
  if (pevInflictor != (entvars_t *)0x0) {
                    /* Unresolved local var: CBasePlayer * pPlayer@[DW_OP_reg1(ECX)] */
    peVar9 = pevInflictor->pContainingEntity;
    if (pevInflictor != pKiller) {
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((((peVar9 == (edict_t *)0x0) &&
           (peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar9 == (edict_t *)0x0)) ||
          (peVar9->pvPrivateData == (void *)0x0)) ||
         (uVar2 = *(uint *)((int)peVar9->pvPrivateData + 0x418), uVar2 == 0)) {
        bVar16 = CARRY4((uint)gpGlobals->pStringBase,pevInflictor->classname);
        local_5c = (byte *)(gpGlobals->pStringBase + pevInflictor->classname);
        bVar17 = local_5c == (byte *)0x0;
      }
      else {
        bVar16 = CARRY4(uVar2,(uint)gpGlobals->pStringBase);
        local_5c = (byte *)(gpGlobals->pStringBase + uVar2);
        bVar17 = local_5c == (byte *)0x0;
      }
      goto LAB_000d892d;
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (peVar9 == (edict_t *)0x0) {
      peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
      pvVar14 = (void *)0x0;
      if (peVar9 != (edict_t *)0x0) goto LAB_000d8b5c;
    }
    else {
LAB_000d8b5c:
      pvVar14 = peVar9->pvPrivateData;
    }
    piVar3 = *(int **)((int)pvVar14 + 0x8fc);
    if (piVar3 != (int *)0x0) {
      uVar2 = piVar3[0x106];
      if (uVar2 == 0) {
                    /* Unresolved local var: ItemInfo II@[???] */
        iVar7 = (**(code **)(*piVar3 + 0x114))(piVar3,local_4c);
        bVar16 = false;
        if (iVar7 == 0) goto LAB_000d8b29;
        local_5c = local_34;
        bVar17 = false;
      }
      else {
        bVar16 = CARRY4(uVar2,(uint)gpGlobals->pStringBase);
        local_5c = (byte *)(gpGlobals->pStringBase + uVar2);
        bVar17 = local_5c == (byte *)0x0;
      }
LAB_000d892d:
      iVar7 = 7;
      pbVar12 = local_5c;
      pbVar15 = (byte *)0x17a02c;
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar16 = *pbVar12 < *pbVar15;
        bVar17 = *pbVar12 == *pbVar15;
        pbVar12 = pbVar12 + (uint)bVar18 * -2 + 1;
        pbVar15 = pbVar15 + (uint)bVar18 * -2 + 1;
      } while (bVar17);
      if (bVar17) {
        pbVar12 = local_5c + 7;
      }
      else {
        iVar7 = 10;
        pbVar12 = local_5c;
        pbVar15 = (byte *)"tf_weapon_";
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar16 = *pbVar12 < *pbVar15;
          bVar17 = *pbVar12 == *pbVar15;
          pbVar12 = pbVar12 + (uint)bVar18 * -2 + 1;
          pbVar15 = pbVar15 + (uint)bVar18 * -2 + 1;
        } while (bVar17);
        if (bVar17) {
          pbVar12 = local_5c + 10;
        }
        else {
          iVar7 = 8;
          pbVar12 = local_5c;
          pbVar15 = (byte *)"monster_";
          do {
            if (iVar7 == 0) break;
            iVar7 = iVar7 + -1;
            bVar16 = *pbVar12 < *pbVar15;
            bVar17 = *pbVar12 == *pbVar15;
            pbVar12 = pbVar12 + (uint)bVar18 * -2 + 1;
            pbVar15 = pbVar15 + (uint)bVar18 * -2 + 1;
          } while (bVar17);
          if (bVar17) {
            pbVar12 = local_5c + 8;
          }
          else {
            iVar7 = 5;
            pbVar12 = local_5c;
            pbVar15 = &DAT_0017bee8;
            do {
              if (iVar7 == 0) break;
              iVar7 = iVar7 + -1;
              bVar16 = *pbVar12 < *pbVar15;
              bVar17 = *pbVar12 == *pbVar15;
              pbVar12 = pbVar12 + (uint)bVar18 * -2 + 1;
              pbVar15 = pbVar15 + (uint)bVar18 * -2 + 1;
            } while (bVar17);
            pbVar12 = local_5c + 5;
            if ((!bVar16 && !bVar17) != bVar16) {
              pbVar12 = local_5c;
            }
          }
        }
      }
      goto LAB_000d85a9;
    }
  }
LAB_000d8b29:
  local_5c = (byte *)0x17bed9;
  pbVar12 = local_5c;
LAB_000d85a9:
  local_5c = pbVar12;
  (*g_engfuncs.pfnMessageBegin)(2,gmsgDeathMsg,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(iVar10);
  p_Var4 = g_engfuncs.pfnWriteByte;
  iVar10 = (*g_engfuncs.pfnIndexOfEdict)
                     (((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var4)(iVar10);
  (*g_engfuncs.pfnWriteString)((char *)local_5c);
  (*g_engfuncs.pfnMessageEnd)();
  peVar8 = (pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar8 == pKiller) {
    iVar10 = (pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no;
    pcVar11 = "SPECTATOR";
    if (iVar10 != 0) {
      pcVar11 = GetTeamName(iVar10);
      peVar8 = (pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.pev;
    }
    pcVar5 = (*g_engfuncs.pfnGetPlayerAuthId)(peVar8->pContainingEntity);
    iVar10 = (*g_engfuncs.pfnGetPlayerUserId)
                       (((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" committed suicide with \"%s\"\n",
                   gpGlobals->pStringBase +
                   ((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar10,pcVar5,pcVar11,local_5c)
    ;
  }
  else if ((pKiller->flags & 8) == 0) {
    iVar10 = (pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no;
    pcVar11 = "SPECTATOR";
    if (iVar10 != 0) {
      pcVar11 = GetTeamName(iVar10);
      peVar8 = (pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.pev;
    }
    pcVar5 = (*g_engfuncs.pfnGetPlayerAuthId)(peVar8->pContainingEntity);
    iVar10 = (*g_engfuncs.pfnGetPlayerUserId)
                       (((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" committed suicide with \"%s\" (world)\n",
                   gpGlobals->pStringBase +
                   ((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar10,pcVar5,pcVar11,local_5c)
    ;
  }
  else {
                    /* Unresolved local var: CBasePlayer * pPlayer@[DW_OP_reg7(EDI)] */
    peVar9 = pKiller->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar9 == (edict_t *)0x0) &&
       (peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar9 == (edict_t *)0x0)) {
      pvVar14 = (void *)0x0;
    }
    else {
      pvVar14 = peVar9->pvPrivateData;
    }
    iVar10 = (pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no;
    local_58 = "SPECTATOR";
    if (iVar10 != 0) {
      local_58 = GetTeamName(iVar10);
    }
    pcVar5 = (*g_engfuncs.pfnGetPlayerAuthId)
                       (((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar10 = (*g_engfuncs.pfnGetPlayerUserId)
                       (((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    pcVar11 = gpGlobals->pStringBase;
    sVar1 = ((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->netname;
    pcVar13 = "SPECTATOR";
    if (*(int *)((int)pvVar14 + 0x138) != 0) {
      pcVar13 = GetTeamName(*(int *)((int)pvVar14 + 0x138));
    }
    pcVar6 = (*g_engfuncs.pfnGetPlayerAuthId)(pKiller->pContainingEntity);
    iVar7 = (*g_engfuncs.pfnGetPlayerUserId)(pKiller->pContainingEntity);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" killed \"%s<%i><%s><%s>\" with \"%s\"\n",
                   gpGlobals->pStringBase + pKiller->netname,iVar7,pcVar6,pcVar13,pcVar11 + sVar1,
                   iVar10,pcVar5,local_58,local_5c);
  }
  g_pszDeathType = (char *)0x0;
  (*g_engfuncs.pfnMessageBegin)(9,0x33,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(9);
  (*g_engfuncs.pfnWriteByte)(2);
  p_Var4 = g_engfuncs.pfnWriteShort;
  iVar10 = (*g_engfuncs.pfnIndexOfEdict)
                     (((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var4)(iVar10);
  p_Var4 = g_engfuncs.pfnWriteShort;
  if (pevInflictor == (entvars_t *)0x0) {
    iVar10 = (*g_engfuncs.pfnIndexOfEdict)(pKiller->pContainingEntity);
    (*p_Var4)(iVar10);
  }
  else {
    iVar10 = (*g_engfuncs.pfnIndexOfEdict)(pevInflictor->pContainingEntity);
    (*p_Var4)(iVar10);
  }
  (*g_engfuncs.pfnWriteLong)(0x27);
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CHalfLifeMultiplay::PlayerGotWeapon  @ 000d8260  (line 1319)

/* DWARF original prototype: void PlayerGotWeapon(CHalfLifeMultiplay * this, CBasePlayer * pPlayer,
   CBasePlayerItem * pWeapon) */

void __thiscall
CHalfLifeMultiplay::PlayerGotWeapon
          (CHalfLifeMultiplay *this,CBasePlayer *pPlayer,CBasePlayerItem *pWeapon)

{
  return;
}


// CHalfLifeMultiplay::FlWeaponRespawnTime  @ 000d9b70  (line 1326)

/* DWARF original prototype: float FlWeaponRespawnTime(CHalfLifeMultiplay * this, CBasePlayerItem *
   pWeapon) */

float __thiscall
CHalfLifeMultiplay::FlWeaponRespawnTime(CHalfLifeMultiplay *this,CBasePlayerItem *pWeapon)

{
  undefined1 local_38 [36];
  uint local_14;
  
  if (0.0 < weaponstay.value) {
                    /* Unresolved local var: ItemInfo II@[???] */
    local_14 = 0;
    (*(pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x45])
              (pWeapon,local_38);
    if ((local_14 & 8) == 0) {
      return gpGlobals->time + 0.0;
    }
  }
  return gpGlobals->time + 20.0;
}


// CHalfLifeMultiplay::FlWeaponTryRespawn  @ 000d9bf0  (line 1353)

/* DWARF original prototype: float FlWeaponTryRespawn(CHalfLifeMultiplay * this, CBasePlayerItem *
   pWeapon) */

float __thiscall
CHalfLifeMultiplay::FlWeaponTryRespawn(CHalfLifeMultiplay *this,CBasePlayerItem *pWeapon)

{
  int iVar1;
  longdouble extraout_ST0;
  
  if ((pWeapon != (CBasePlayerItem *)0x0) && (pWeapon->m_iId != 0)) {
    if ((CBasePlayerItem::ItemInfoArray[pWeapon->m_iId].iFlags & 8) != 0) {
      iVar1 = (*g_engfuncs.pfnNumberOfEntities)();
      if (gpGlobals->maxEntities + -100 <= iVar1) {
                    /* WARNING: Could not recover jumptable at 0x000d9c6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(this->super_CGameRules)._vptr_CGameRules[0x20])();
        return (float)extraout_ST0;
      }
    }
    return 0.0;
  }
  return 0.0;
}


// CHalfLifeMultiplay::VecWeaponRespawnSpot  @ 000d8270  (line 1372)

/* DWARF original prototype: Vector VecWeaponRespawnSpot(CHalfLifeMultiplay * this, CBasePlayerItem
   * pWeapon) */

Vector * __thiscall
CHalfLifeMultiplay::VecWeaponRespawnSpot
          (Vector *__return_storage_ptr__,CHalfLifeMultiplay *this,CBasePlayerItem *pWeapon)

{
  entvars_t *peVar1;
  
  peVar1 = (pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  __return_storage_ptr__->x = (peVar1->origin).x;
  __return_storage_ptr__->y = (peVar1->origin).y;
  __return_storage_ptr__->z = (peVar1->origin).z;
  return __return_storage_ptr__;
}


// CHalfLifeMultiplay::WeaponShouldRespawn  @ 000d8290  (line 1381)

/* DWARF original prototype: int WeaponShouldRespawn(CHalfLifeMultiplay * this, CBasePlayerItem *
   pWeapon) */

int __thiscall
CHalfLifeMultiplay::WeaponShouldRespawn(CHalfLifeMultiplay *this,CBasePlayerItem *pWeapon)

{
  return 2 - (uint)((((pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->
                     spawnflags & 0x40000000U) == 0);
}


// CHalfLifeMultiplay::CanHavePlayerItem  @ 000d9f80  (line 1394)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL CanHavePlayerItem(CHalfLifeMultiplay * this, CBasePlayer *
   pPlayer, CBasePlayerItem * pItem) */

BOOL __thiscall
CHalfLifeMultiplay::CanHavePlayerItem
          (CHalfLifeMultiplay *this,CBasePlayer *pPlayer,CBasePlayerItem *pItem)

{
  CBasePlayerItem *pCVar1;
  BOOL BVar2;
  int iVar3;
  undefined1 local_4c [8];
  int local_44;
  undefined4 local_40;
  int local_2c;
  uint local_28;
  
  if (0.0 < weaponstay.value) {
                    /* Unresolved local var: ItemInfo II@[???] */
    local_28 = 0;
    (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x45])
              (pItem,local_4c);
    if ((local_28 & 8) == 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CBasePlayerItem * it@[???] */
      iVar3 = 0;
      do {
        for (pCVar1 = pPlayer->m_rgpPlayerItems[iVar3]; pCVar1 != (CBasePlayerItem *)0x0;
            pCVar1 = pCVar1->m_pNext) {
          if (pCVar1->m_iId == local_2c) {
            return 0;
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != 6);
    }
  }
                    /* Unresolved local var: ItemInfo info@[???] */
  iVar3 = (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x45]
          )(pItem,local_4c);
  if ((iVar3 != 0) &&
     ((local_44 == 0 ||
      (iVar3 = (*(this->super_CGameRules)._vptr_CGameRules[0x28])(this,pPlayer,local_44,local_40),
      iVar3 == 0)))) {
    BVar2 = CBasePlayer::HasPlayerItem(pPlayer,pItem);
    return (uint)(BVar2 == 0);
  }
  return 1;
}


// CHalfLifeMultiplay::CanHaveItem  @ 000d82b0  (line 1429)

/* DWARF original prototype: BOOL CanHaveItem(CHalfLifeMultiplay * this, CBasePlayer * pPlayer,
   CItem * pItem) */

BOOL __thiscall
CHalfLifeMultiplay::CanHaveItem(CHalfLifeMultiplay *this,CBasePlayer *pPlayer,CItem *pItem)

{
  return 1;
}


// CHalfLifeMultiplay::PlayerGotItem  @ 000d82c0  (line 1435)

/* DWARF original prototype: void PlayerGotItem(CHalfLifeMultiplay * this, CBasePlayer * pPlayer,
   CItem * pItem) */

void __thiscall
CHalfLifeMultiplay::PlayerGotItem(CHalfLifeMultiplay *this,CBasePlayer *pPlayer,CItem *pItem)

{
  return;
}


// CHalfLifeMultiplay::ItemShouldRespawn  @ 000d82d0  (line 1441)

/* DWARF original prototype: int ItemShouldRespawn(CHalfLifeMultiplay * this, CItem * pItem) */

int __thiscall CHalfLifeMultiplay::ItemShouldRespawn(CHalfLifeMultiplay *this,CItem *pItem)

{
  return 6 - (uint)((((pItem->super_CBaseEntity).pev)->spawnflags & 0x40000000U) == 0);
}


// CHalfLifeMultiplay::FlItemRespawnTime  @ 000d82f0  (line 1455)

/* DWARF original prototype: float FlItemRespawnTime(CHalfLifeMultiplay * this, CItem * pItem) */

float __thiscall CHalfLifeMultiplay::FlItemRespawnTime(CHalfLifeMultiplay *this,CItem *pItem)

{
  return gpGlobals->time + 30.0;
}


// CHalfLifeMultiplay::VecItemRespawnSpot  @ 000d8300  (line 1464)

/* DWARF original prototype: Vector VecItemRespawnSpot(CHalfLifeMultiplay * this, CItem * pItem) */

Vector * __thiscall
CHalfLifeMultiplay::VecItemRespawnSpot
          (Vector *__return_storage_ptr__,CHalfLifeMultiplay *this,CItem *pItem)

{
  entvars_t *peVar1;
  
  peVar1 = (pItem->super_CBaseEntity).pev;
  __return_storage_ptr__->x = (peVar1->origin).x;
  __return_storage_ptr__->y = (peVar1->origin).y;
  __return_storage_ptr__->z = (peVar1->origin).z;
  return __return_storage_ptr__;
}


// CHalfLifeMultiplay::PlayerGotAmmo  @ 000d8320  (line 1471)

/* DWARF original prototype: void PlayerGotAmmo(CHalfLifeMultiplay * this, CBasePlayer * pPlayer,
   char * szName, int iCount) */

void __thiscall
CHalfLifeMultiplay::PlayerGotAmmo
          (CHalfLifeMultiplay *this,CBasePlayer *pPlayer,char *szName,int iCount)

{
  return;
}


// CHalfLifeMultiplay::IsAllowedToSpawn  @ 000d8330  (line 1481)

/* DWARF original prototype: BOOL IsAllowedToSpawn(CHalfLifeMultiplay * this, CBaseEntity * pEntity)
    */

BOOL __thiscall CHalfLifeMultiplay::IsAllowedToSpawn(CHalfLifeMultiplay *this,CBaseEntity *pEntity)

{
  return 1;
}


// CHalfLifeMultiplay::AmmoShouldRespawn  @ 000d8340  (line 1487)

/* DWARF original prototype: int AmmoShouldRespawn(CHalfLifeMultiplay * this, CBasePlayerAmmo *
   pAmmo) */

int __thiscall
CHalfLifeMultiplay::AmmoShouldRespawn(CHalfLifeMultiplay *this,CBasePlayerAmmo *pAmmo)

{
  return 4 - (uint)((((pAmmo->super_CBaseEntity).pev)->spawnflags & 0x40000000U) == 0);
}


// CHalfLifeMultiplay::FlAmmoRespawnTime  @ 000d8360  (line 1499)

/* DWARF original prototype: float FlAmmoRespawnTime(CHalfLifeMultiplay * this, CBasePlayerAmmo *
   pAmmo) */

float __thiscall
CHalfLifeMultiplay::FlAmmoRespawnTime(CHalfLifeMultiplay *this,CBasePlayerAmmo *pAmmo)

{
  return gpGlobals->time + 20.0;
}


// CHalfLifeMultiplay::VecAmmoRespawnSpot  @ 000d8370  (line 1506)

/* DWARF original prototype: Vector VecAmmoRespawnSpot(CHalfLifeMultiplay * this, CBasePlayerAmmo *
   pAmmo) */

Vector * __thiscall
CHalfLifeMultiplay::VecAmmoRespawnSpot
          (Vector *__return_storage_ptr__,CHalfLifeMultiplay *this,CBasePlayerAmmo *pAmmo)

{
  entvars_t *peVar1;
  
  peVar1 = (pAmmo->super_CBaseEntity).pev;
  __return_storage_ptr__->x = (peVar1->origin).x;
  __return_storage_ptr__->y = (peVar1->origin).y;
  __return_storage_ptr__->z = (peVar1->origin).z;
  return __return_storage_ptr__;
}


// CHalfLifeMultiplay::FlHealthChargerRechargeTime  @ 000d8390  (line 1514)

/* DWARF original prototype: float FlHealthChargerRechargeTime(CHalfLifeMultiplay * this) */

float __thiscall CHalfLifeMultiplay::FlHealthChargerRechargeTime(CHalfLifeMultiplay *this)

{
  return 60.0;
}


// CHalfLifeMultiplay::FlHEVChargerRechargeTime  @ 000d83a0  (line 1520)

/* DWARF original prototype: float FlHEVChargerRechargeTime(CHalfLifeMultiplay * this) */

float __thiscall CHalfLifeMultiplay::FlHEVChargerRechargeTime(CHalfLifeMultiplay *this)

{
  return 30.0;
}


// CHalfLifeMultiplay::DeadPlayerWeapons  @ 000d83b0  (line 1527)

/* DWARF original prototype: int DeadPlayerWeapons(CHalfLifeMultiplay * this, CBasePlayer * pPlayer)
    */

int __thiscall CHalfLifeMultiplay::DeadPlayerWeapons(CHalfLifeMultiplay *this,CBasePlayer *pPlayer)

{
  return 8;
}


// CHalfLifeMultiplay::DeadPlayerAmmo  @ 000d83c0  (line 1534)

/* DWARF original prototype: int DeadPlayerAmmo(CHalfLifeMultiplay * this, CBasePlayer * pPlayer) */

int __thiscall CHalfLifeMultiplay::DeadPlayerAmmo(CHalfLifeMultiplay *this,CBasePlayer *pPlayer)

{
  return 0xb;
}


// CHalfLifeMultiplay::PlayerRelationship  @ 000d83d0  (line 1542)

/* DWARF original prototype: int PlayerRelationship(CHalfLifeMultiplay * this, CBasePlayer *
   pPlayer, CBaseEntity * pTarget) */

int __thiscall
CHalfLifeMultiplay::PlayerRelationship
          (CHalfLifeMultiplay *this,CBasePlayer *pPlayer,CBaseEntity *pTarget)

{
  return 0;
}


// CHalfLifeMultiplay::PlayFootstepSounds  @ 000d9df0  (line 1545)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL PlayFootstepSounds(CHalfLifeMultiplay * this, CBasePlayer * pl,
   float fvol) */

BOOL __thiscall
CHalfLifeMultiplay::PlayFootstepSounds(CHalfLifeMultiplay *this,CBasePlayer *pl,float fvol)

{
  float fVar1;
  entvars_t *peVar2;
  BOOL BVar3;
  BOOL BVar4;
  float fVar5;
  
  if ((g_footsteps == (cvar_t *)0x0) || (BVar4 = 0, g_footsteps->value != 0.0)) {
    BVar3 = CBasePlayer::IsOnLadder(pl);
    BVar4 = 1;
    if (BVar3 == 0) {
      peVar2 = (pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      fVar1 = (peVar2->velocity).x;
      fVar5 = (peVar2->velocity).y;
      fVar1 = fVar5 * fVar5 + fVar1 * fVar1;
      fVar5 = SQRT(fVar1);
      if (NAN(fVar5)) {
        fVar5 = sqrtf(fVar1);
      }
      return (uint)(220.0 < fVar5);
    }
  }
  return BVar4;
}


// CHalfLifeMultiplay::FAllowFlashlight  @ 000d83e0  (line 1557)

/* DWARF original prototype: BOOL FAllowFlashlight(CHalfLifeMultiplay * this) */

BOOL __thiscall CHalfLifeMultiplay::FAllowFlashlight(CHalfLifeMultiplay *this)

{
  uint uVar1;
  
  uVar1 = 1;
  if (flashlight.value == 0.0) {
    uVar1 = (uint)NAN(flashlight.value);
  }
  return uVar1;
}


// CHalfLifeMultiplay::GoToIntermission  @ 000d9e90  (line 1566)

/* DWARF original prototype: void GoToIntermission(CHalfLifeMultiplay * this) */

void __thiscall CHalfLifeMultiplay::GoToIntermission(CHalfLifeMultiplay *this)

{
  float fVar1;
  
  if (g_fGameOver == 0) {
    (*g_engfuncs.pfnMessageBegin)(2,0x1e,(float *)0x0,(edict_t *)0x0);
    (*g_engfuncs.pfnMessageEnd)();
    fVar1 = gpGlobals->time;
    g_fGameOver = 1;
    this->m_iEndIntermissionButtonHit = 0;
    this->m_flIntermissionEndTime = fVar1 + 6.0;
  }
  return;
}


// DestroyMapCycle  @ 000da390  (line 1604)

void DestroyMapCycle(mapcycle_t *cycle)

{
  mapcycle_item_s *pmVar1;
  mapcycle_item_s *pmVar2;
  mapcycle_item_s *pmVar3;
  
                    /* Unresolved local var: mapcycle_item_t * p@[???]
                       Unresolved local var: mapcycle_item_t * n@[???]
                       Unresolved local var: mapcycle_item_t * start@[???] */
  pmVar3 = cycle->items;
  if (pmVar3 != (mapcycle_item_s *)0x0) {
    pmVar2 = pmVar3->next;
    if (pmVar3 != pmVar3->next) {
      do {
        pmVar1 = pmVar2->next;
        operator_delete(pmVar2);
        pmVar2 = pmVar1;
      } while (pmVar3 != pmVar1);
      pmVar3 = cycle->items;
    }
    operator_delete(pmVar3);
  }
  cycle->items = (mapcycle_item_s *)0x0;
  cycle->next_item = (mapcycle_item_s *)0x0;
  return;
}


// COM_Parse  @ 000da3e0  (line 1634)

char * COM_Parse(char *data)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: int len@[???] */
  com_token[0] = '\0';
  if (data == (char *)0x0) {
    return (char *)0x0;
  }
  cVar5 = *data;
  cVar2 = cVar5;
  do {
    while (cVar5 < '!') {
      if (cVar5 == '\0') {
        com_token[0] = '\0';
        return (char *)0x0;
      }
      pcVar1 = data + 1;
      data = data + 1;
      cVar5 = *pcVar1;
      cVar2 = cVar5;
    }
    if (cVar5 != '/') {
      if (cVar5 == '\"') {
        iVar3 = 0;
        cVar5 = data[1];
        pcVar1 = data + 2;
        while ((cVar5 != '\0' && (cVar5 != '\"'))) {
          com_token[iVar3] = cVar5;
          iVar3 = iVar3 + 1;
          cVar5 = *pcVar1;
          pcVar1 = pcVar1 + 1;
        }
        com_token[iVar3] = '\0';
        return pcVar1;
      }
      if ((((cVar5 == '}') || (cVar5 == '{')) || (cVar5 == '(')) ||
         (((cVar5 == ')' || (cVar5 == ',')) || (cVar5 == '\'')))) {
        com_token[0] = cVar2;
        com_token[1] = '\0';
        return data + 1;
      }
LAB_000da4b6:
      iVar3 = 0;
      break;
    }
    if (data[1] != '/') goto LAB_000da4b6;
    if ((cVar2 != '\0') && (cVar2 != '\n')) {
      do {
        data = data + 1;
        cVar5 = *data;
        cVar2 = cVar5;
        if (cVar5 == '\n') break;
      } while (cVar5 != '\0');
    }
  } while( true );
LAB_000da4bb:
  iVar4 = iVar3;
  com_token[iVar4] = cVar5;
  cVar5 = data[iVar4 + 1];
  if ((cVar5 == '}') || (cVar5 == '{')) {
LAB_000da4ec:
    com_token[iVar4 + 1] = '\0';
    return data + iVar4 + 1;
  }
  if (((cVar5 == '(') || (((cVar5 == ')' || (cVar5 == ',')) || (cVar5 == '\'')))) ||
     (iVar3 = iVar4 + 1, cVar5 < '!')) goto LAB_000da4ec;
  goto LAB_000da4bb;
}


// COM_TokenWaiting  @ 000da500  (line 1711)

int COM_TokenWaiting(char *buffer)

{
  char cVar1;
  int iVar2;
  
                    /* Unresolved local var: char * p@[???] */
  cVar1 = *buffer;
  while( true ) {
    if ((cVar1 == '\n') || (cVar1 == '\0')) {
      return 0;
    }
    iVar2 = isspace((int)cVar1);
    if ((iVar2 == 0) || (iVar2 = isalnum((int)cVar1), iVar2 != 0)) break;
    buffer = buffer + 1;
    cVar1 = *buffer;
  }
  return 1;
}


// ReloadMapCycleFile  @ 000da560  (line 1735)

int ReloadMapCycleFile(char *filename,mapcycle_t *cycle)

{
  char *pcVar1;
  char *pcVar2;
  byte bVar3;
  bool bVar4;
  globalvars_t *pgVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  byte *data;
  mapcycle_item_s *pmVar9;
  long lVar10;
  int iVar11;
  mapcycle_item_s *pmVar12;
  char *pcVar13;
  mapcycle_item_s *pmVar14;
  byte *pbVar15;
  bool bVar16;
  uint local_45c;
  char local_44c [4];
  undefined4 auStack_448 [255];
  char local_4c [32];
  int local_2c [7];
  
                    /* Unresolved local var: char[1024] szBuffer@[???]
                       Unresolved local var: char[32] szMap@[???]
                       Unresolved local var: int length@[???]
                       Unresolved local var: char * pFileList@[???]
                       Unresolved local var: char * aFileList@[???]
                       Unresolved local var: int hasbuffer@[???]
                       Unresolved local var: mapcycle_item_s * item@[???]
                       Unresolved local var: mapcycle_item_s * newlist@[???]
                       Unresolved local var: mapcycle_item_s * next@[???] */
  pbVar6 = (*g_engfuncs.pfnLoadFileForMe)(filename,local_2c);
  if ((pbVar6 != (byte *)0x0) && (local_2c[0] != 0)) {
    data = pbVar6;
    while( true ) {
      uVar8 = 0;
      do {
        pcVar1 = local_44c + uVar8;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        *(undefined4 *)((int)auStack_448 + uVar8) = 0;
        *(undefined4 *)((int)auStack_448 + uVar8 + 4) = 0;
        *(undefined4 *)((int)auStack_448 + uVar8 + 8) = 0;
        uVar8 = uVar8 + 0x10;
      } while (uVar8 < 0x400);
      data = (byte *)COM_Parse((char *)data);
      if (com_token[0] == '\0') break;
      strcpy(local_4c,com_token);
                    /* Unresolved local var: char * p@[???] */
      bVar3 = *data;
      pbVar15 = data;
      if (bVar3 != '\n') {
        while (bVar3 != '\0') {
          iVar7 = isspace((int)(char)bVar3);
          if ((iVar7 == 0) || (iVar7 = isalnum((int)(char)bVar3), iVar7 != 0)) {
            data = (byte *)COM_Parse((char *)data);
            bVar4 = false;
            if (com_token[0] != '\0') {
              strcpy(local_44c,com_token);
              bVar4 = true;
            }
            goto LAB_000da6cc;
          }
          pbVar15 = pbVar15 + 1;
          bVar3 = *pbVar15;
          if (bVar3 == '\n') break;
        }
      }
      bVar4 = false;
LAB_000da6cc:
      iVar7 = (*g_engfuncs.pfnIsMapValid)(local_4c);
      if (iVar7 == 0) {
        (*g_engfuncs.pfnAlertMessage)
                  (at_console,"Skipping %s from mapcycle, not a valid map\n",local_4c);
      }
      else {
                    /* Unresolved local var: char * s@[???] */
        pmVar9 = operator_new(0x42c);
        strcpy(pmVar9->mapname,local_4c);
        pcVar1 = pmVar9->rulebuffer;
        bVar16 = ((uint)pcVar1 & 1) != 0;
        pmVar9->minplayers = 0;
        pmVar9->maxplayers = 0;
        local_45c = 0x400;
        pcVar13 = pcVar1;
        if (bVar16) {
          pmVar9->rulebuffer[0] = '\0';
          pcVar13 = pmVar9->rulebuffer + 1;
          local_45c = 0x3ff;
        }
        if (((uint)pcVar13 & 2) != 0) {
          pcVar13[0] = '\0';
          pcVar13[1] = '\0';
          pcVar13 = pcVar13 + 2;
          local_45c = local_45c - 2;
        }
        uVar8 = 0;
        do {
          pcVar2 = pcVar13 + uVar8;
          pcVar2[0] = '\0';
          pcVar2[1] = '\0';
          pcVar2[2] = '\0';
          pcVar2[3] = '\0';
          pcVar2 = pcVar13 + uVar8 + 4;
          pcVar2[0] = '\0';
          pcVar2[1] = '\0';
          pcVar2[2] = '\0';
          pcVar2[3] = '\0';
          pcVar2 = pcVar13 + uVar8 + 8;
          pcVar2[0] = '\0';
          pcVar2[1] = '\0';
          pcVar2[2] = '\0';
          pcVar2[3] = '\0';
          pcVar2 = pcVar13 + uVar8 + 0xc;
          pcVar2[0] = '\0';
          pcVar2[1] = '\0';
          pcVar2[2] = '\0';
          pcVar2[3] = '\0';
          uVar8 = uVar8 + 0x10;
        } while (uVar8 < (local_45c & 0xfffffff0));
        pcVar13 = pcVar13 + uVar8;
        if ((local_45c & 8) != 0) {
          pcVar13[0] = '\0';
          pcVar13[1] = '\0';
          pcVar13[2] = '\0';
          pcVar13[3] = '\0';
          pcVar13[4] = '\0';
          pcVar13[5] = '\0';
          pcVar13[6] = '\0';
          pcVar13[7] = '\0';
          pcVar13 = pcVar13 + 8;
        }
        if ((local_45c & 4) != 0) {
          pcVar13[0] = '\0';
          pcVar13[1] = '\0';
          pcVar13[2] = '\0';
          pcVar13[3] = '\0';
          pcVar13 = pcVar13 + 4;
        }
        if ((local_45c & 2) != 0) {
          pcVar13[0] = '\0';
          pcVar13[1] = '\0';
          pcVar13 = pcVar13 + 2;
        }
        if (bVar16) {
          *pcVar13 = '\0';
        }
        if (bVar4) {
          pcVar13 = (*g_engfuncs.pfnInfoKeyValue)(local_44c,"minplayers");
          if ((pcVar13 != (char *)0x0) && (*pcVar13 != '\0')) {
            lVar10 = strtol(pcVar13,(char **)0x0,10);
            pgVar5 = gpGlobals;
            iVar7 = 0;
            if (-1 < lVar10) {
              iVar7 = lVar10;
            }
            pmVar9->minplayers = iVar7;
            iVar11 = pgVar5->maxClients;
            if (iVar7 <= pgVar5->maxClients) {
              iVar11 = iVar7;
            }
            pmVar9->minplayers = iVar11;
          }
          pcVar13 = (*g_engfuncs.pfnInfoKeyValue)(local_44c,"maxplayers");
          if ((pcVar13 != (char *)0x0) && (*pcVar13 != '\0')) {
            lVar10 = strtol(pcVar13,(char **)0x0,10);
            pgVar5 = gpGlobals;
            iVar7 = 0;
            if (-1 < lVar10) {
              iVar7 = lVar10;
            }
            pmVar9->maxplayers = iVar7;
            iVar11 = pgVar5->maxClients;
            if (iVar7 <= pgVar5->maxClients) {
              iVar11 = iVar7;
            }
            pmVar9->maxplayers = iVar11;
          }
          (*g_engfuncs.pfnInfo_RemoveKey)(local_44c,"minplayers");
          (*g_engfuncs.pfnInfo_RemoveKey)(local_44c,"maxplayers");
          strcpy(pcVar1,local_44c);
        }
        pmVar9->next = cycle->items;
        cycle->items = pmVar9;
      }
    }
    (*g_engfuncs.pfnFreeFile)(pbVar6);
  }
  iVar7 = 0;
  pmVar12 = (mapcycle_item_s *)0x0;
  pmVar9 = cycle->items;
  if (cycle->items != (mapcycle_item_s *)0x0) {
    do {
      pmVar14 = pmVar9;
      pmVar9 = pmVar14->next;
      pmVar14->next = pmVar12;
      pmVar12 = pmVar14;
    } while (pmVar9 != (mapcycle_item_s *)0x0);
    cycle->items = pmVar14;
    pmVar9 = pmVar14;
    do {
      pmVar12 = pmVar9;
      pmVar9 = pmVar12->next;
    } while (pmVar9 != (mapcycle_item_s *)0x0);
    pmVar12->next = pmVar14;
    iVar7 = 1;
    cycle->next_item = pmVar14;
  }
  return iVar7;
}


// CountPlayers  @ 000da950  (line 1860)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CountPlayers(void)

{
  CBasePlayer *pCVar1;
  int playerIndex;
  int iVar2;
  
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
  iVar2 = 0;
  if (0 < gpGlobals->maxClients) {
    playerIndex = 1;
    iVar2 = 0;
    do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      pCVar1 = UTIL_PlayerByIndex(playerIndex);
      iVar2 = (iVar2 + 1) - (uint)(pCVar1 == (CBasePlayer *)0x0);
      playerIndex = playerIndex + 1;
    } while (playerIndex <= gpGlobals->maxClients);
  }
  return iVar2;
}


// ExtractCommandString  @ 000da9a0  (line 1885)

void ExtractCommandString(char *s,char *szCommand)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  char local_40c [512];
  char local_20c [516];
  
                    /* Unresolved local var: char[512] pkey@[???]
                       Unresolved local var: char[512] value@[???]
                       Unresolved local var: char * o@[???] */
  cVar1 = *s;
  if (cVar1 == '\\') {
    cVar1 = s[1];
    s = s + 1;
  }
  pcVar3 = local_20c;
  do {
    if (cVar1 == '\\') {
      cVar1 = s[1];
      s = s + 1;
      *pcVar3 = '\0';
      pcVar3 = local_40c;
      while ((cVar1 != '\0' && (cVar1 != '\\'))) {
        s = s + 1;
        *pcVar3 = cVar1;
        pcVar3 = pcVar3 + 1;
        cVar1 = *s;
      }
      *pcVar3 = '\0';
      strcat(szCommand,local_20c);
      if (local_40c[0] != '\0') {
        sVar2 = strlen(szCommand);
        (szCommand + sVar2)[0] = ' ';
        (szCommand + sVar2)[1] = '\0';
        strcat(szCommand,local_40c);
      }
      sVar2 = strlen(szCommand);
      (szCommand + sVar2)[0] = '\n';
      (szCommand + sVar2)[1] = '\0';
      if (*s == '\0') {
        return;
      }
      pcVar3 = local_20c;
    }
    else {
      if (cVar1 == '\0') {
        return;
      }
      *pcVar3 = cVar1;
      pcVar3 = pcVar3 + 1;
    }
    s = s + 1;
    cVar1 = *s;
  } while( true );
}


// CHalfLifeMultiplay::ChangeLevel  @ 000daa80  (line 1939)

/* DWARF original prototype: void ChangeLevel(CHalfLifeMultiplay * this) */

void __thiscall CHalfLifeMultiplay::ChangeLevel(CHalfLifeMultiplay *this)

{
  char *pcVar1;
  char *pcVar2;
  byte bVar3;
  bool bVar4;
  char *__s1;
  CBasePlayer *pCVar5;
  byte *pbVar6;
  mapcycle_item_s *pmVar7;
  uint uVar8;
  long lVar9;
  int iVar10;
  mapcycle_item_s *pmVar11;
  char *pcVar12;
  int iVar13;
  uint uVar14;
  byte *pbVar15;
  globalvars_t *pgVar16;
  mapcycle_item_s *pmVar17;
  int iVar18;
  bool bVar19;
  byte *local_1064;
  uint local_1060;
  char *local_105c;
  char local_104c [1508];
  char local_a68 [1500];
  char local_48c [4];
  undefined4 auStack_488 [255];
  char local_8c [32];
  undefined4 local_6c;
  undefined2 local_68;
  char local_4c [32];
  int local_2c [7];
  
                    /* Unresolved local var: char[32] szNextMap@[???]
                       Unresolved local var: char[32] szFirstMapInList@[???]
                       Unresolved local var: char[1500] szCommands@[???]
                       Unresolved local var: char[1500] szRules@[???]
                       Unresolved local var: int minplayers@[???]
                       Unresolved local var: int maxplayers@[???]
                       Unresolved local var: int curplayers@[DW_OP_reg6(ESI)]
                       Unresolved local var: BOOL do_cycle@[???]
                       Unresolved local var: char * mapcfile@[???] */
                    /* Unresolved local var: int num@[???]
                       Unresolved local var: int i@[???] */
  iVar18 = 0;
  local_6c = 0x6d646c68;
  local_68 = 0x31;
  __s1 = (*g_engfuncs.pfnCVarGetString)("mapcyclefile");
  local_104c[0] = '\0';
  local_a68[0] = '\0';
  if (0 < gpGlobals->maxClients) {
    iVar13 = 1;
    iVar18 = 0;
    do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      pCVar5 = UTIL_PlayerByIndex(iVar13);
      iVar18 = (iVar18 + 1) - (uint)(pCVar5 == (CBasePlayer *)0x0);
      iVar13 = iVar13 + 1;
    } while (iVar13 <= gpGlobals->maxClients);
  }
  pgVar16 = gpGlobals;
  iVar13 = strcasecmp(__s1,ChangeLevel::lexical_block_0::szPreviousMapCycleFile);
  if (iVar13 == 0) {
    if (ChangeLevel::lexical_block_0::mapcycle.items != (mapcycle_item_s *)0x0) {
LAB_000dab2d:
      pmVar11 = ChangeLevel::lexical_block_0::mapcycle.next_item;
                    /* Unresolved local var: BOOL keeplooking@[???]
                       Unresolved local var: BOOL found@[???]
                       Unresolved local var: mapcycle_item_s * item@[???] */
      strcpy(local_8c,pgVar16->pStringBase + pgVar16->mapname);
      strcpy((char *)&local_6c,pgVar16->pStringBase + pgVar16->mapname);
      local_1060 = 0;
      bVar4 = false;
      local_1064 = (byte *)0x0;
      pmVar7 = pmVar11;
LAB_000dab7d:
      do {
        pmVar17 = pmVar7;
        pmVar7 = pmVar17->next;
        if (pmVar7 == pmVar11) {
          if (!bVar4) {
            pmVar17 = pmVar11;
          }
          break;
        }
        uVar14 = pmVar17->minplayers;
        bVar19 = false;
        if (uVar14 != 0) {
          if ((int)uVar14 <= iVar18) {
            local_1064 = (byte *)uVar14;
          }
          bVar19 = true;
          if (iVar18 < (int)uVar14) {
            bVar19 = bVar4;
          }
          bVar4 = bVar19;
          bVar19 = iVar18 < (int)uVar14;
        }
        uVar14 = pmVar17->maxplayers;
        if (uVar14 != 0) {
          if ((int)uVar14 < iVar18) goto LAB_000dab7d;
          bVar4 = true;
          local_1060 = uVar14;
        }
      } while (bVar19);
      ChangeLevel::lexical_block_0::mapcycle.next_item = pmVar17->next;
      strcpy(local_8c,pmVar17->mapname);
      ExtractCommandString(pmVar17->rulebuffer,local_a68);
      strcpy(local_104c,pmVar17->rulebuffer);
      uVar14 = (uint)local_1064 | local_1060;
      iVar13 = (*g_engfuncs.pfnIsMapValid)(local_8c);
      goto joined_r0x000dad0f;
    }
  }
  else {
    strcpy(ChangeLevel::lexical_block_0::szPreviousMapCycleFile,__s1);
    pmVar7 = ChangeLevel::lexical_block_0::mapcycle.items;
                    /* Unresolved local var: mapcycle_item_t * p@[???]
                       Unresolved local var: mapcycle_item_t * n@[???]
                       Unresolved local var: mapcycle_item_t * start@[???] */
    if (ChangeLevel::lexical_block_0::mapcycle.items != (mapcycle_item_s *)0x0) {
      pmVar11 = (ChangeLevel::lexical_block_0::mapcycle.items)->next;
      while (pmVar7 != pmVar11) {
        pmVar17 = pmVar11->next;
        operator_delete(pmVar11);
        pmVar11 = pmVar17;
      }
      operator_delete(ChangeLevel::lexical_block_0::mapcycle.items);
    }
    ChangeLevel::lexical_block_0::mapcycle.next_item = (mapcycle_item_s *)0x0;
    ChangeLevel::lexical_block_0::mapcycle.items = (mapcycle_item_s *)0x0;
    pbVar6 = (*g_engfuncs.pfnLoadFileForMe)(__s1,local_2c);
    if ((pbVar6 != (byte *)0x0) && (local_2c[0] != 0)) {
      local_1064 = pbVar6;
      while( true ) {
        uVar14 = 0;
        do {
          pcVar1 = local_48c + uVar14;
          pcVar1[0] = '\0';
          pcVar1[1] = '\0';
          pcVar1[2] = '\0';
          pcVar1[3] = '\0';
          *(undefined4 *)((int)auStack_488 + uVar14) = 0;
          *(undefined4 *)((int)auStack_488 + uVar14 + 4) = 0;
          *(undefined4 *)((int)auStack_488 + uVar14 + 8) = 0;
          uVar14 = uVar14 + 0x10;
        } while (uVar14 < 0x400);
        local_1064 = (byte *)COM_Parse((char *)local_1064);
        if (com_token[0] == '\0') break;
        strcpy(local_4c,com_token);
                    /* Unresolved local var: char * p@[???] */
        bVar3 = *local_1064;
        if ((bVar3 != '\0') && (pbVar15 = local_1064, bVar3 != '\n')) {
          do {
            iVar13 = isspace((int)(char)bVar3);
            if ((iVar13 == 0) || (iVar13 = isalnum((int)(char)bVar3), iVar13 != 0)) {
              local_1064 = (byte *)COM_Parse((char *)local_1064);
              bVar4 = false;
              if (com_token[0] != '\0') {
                strcpy(local_48c,com_token);
                bVar4 = true;
              }
              goto LAB_000daf42;
            }
            bVar3 = pbVar15[1];
          } while ((bVar3 != '\n') && (pbVar15 = pbVar15 + 1, bVar3 != '\0'));
        }
        bVar4 = false;
LAB_000daf42:
        iVar13 = (*g_engfuncs.pfnIsMapValid)(local_4c);
        if (iVar13 == 0) {
          (*g_engfuncs.pfnAlertMessage)
                    (at_console,"Skipping %s from mapcycle, not a valid map\n",local_4c);
        }
        else {
                    /* Unresolved local var: char * s@[???] */
          pmVar7 = operator_new(0x42c);
          pcVar1 = pmVar7->rulebuffer;
          strcpy(pmVar7->mapname,local_4c);
          bVar19 = ((uint)pcVar1 & 1) != 0;
          pmVar7->minplayers = 0;
          uVar14 = 0x400;
          pmVar7->maxplayers = 0;
          pcVar12 = pcVar1;
          if (bVar19) {
            pmVar7->rulebuffer[0] = '\0';
            pcVar12 = pmVar7->rulebuffer + 1;
            uVar14 = 0x3ff;
          }
          if (((uint)pcVar12 & 2) != 0) {
            pcVar12[0] = '\0';
            pcVar12[1] = '\0';
            uVar14 = uVar14 - 2;
            pcVar12 = pcVar12 + 2;
          }
          uVar8 = 0;
          do {
            pcVar2 = pcVar12 + uVar8;
            pcVar2[0] = '\0';
            pcVar2[1] = '\0';
            pcVar2[2] = '\0';
            pcVar2[3] = '\0';
            pcVar2 = pcVar12 + uVar8 + 4;
            pcVar2[0] = '\0';
            pcVar2[1] = '\0';
            pcVar2[2] = '\0';
            pcVar2[3] = '\0';
            pcVar2 = pcVar12 + uVar8 + 8;
            pcVar2[0] = '\0';
            pcVar2[1] = '\0';
            pcVar2[2] = '\0';
            pcVar2[3] = '\0';
            pcVar2 = pcVar12 + uVar8 + 0xc;
            pcVar2[0] = '\0';
            pcVar2[1] = '\0';
            pcVar2[2] = '\0';
            pcVar2[3] = '\0';
            uVar8 = uVar8 + 0x10;
          } while (uVar8 < (uVar14 & 0xfffffff0));
          pcVar12 = pcVar12 + uVar8;
          if ((uVar14 & 8) != 0) {
            pcVar12[0] = '\0';
            pcVar12[1] = '\0';
            pcVar12[2] = '\0';
            pcVar12[3] = '\0';
            pcVar12[4] = '\0';
            pcVar12[5] = '\0';
            pcVar12[6] = '\0';
            pcVar12[7] = '\0';
            pcVar12 = pcVar12 + 8;
          }
          if ((uVar14 & 4) != 0) {
            pcVar12[0] = '\0';
            pcVar12[1] = '\0';
            pcVar12[2] = '\0';
            pcVar12[3] = '\0';
            pcVar12 = pcVar12 + 4;
          }
          if ((uVar14 & 2) != 0) {
            pcVar12[0] = '\0';
            pcVar12[1] = '\0';
            pcVar12 = pcVar12 + 2;
          }
          if (bVar19) {
            *pcVar12 = '\0';
          }
          if (bVar4) {
            pcVar12 = (*g_engfuncs.pfnInfoKeyValue)(local_48c,"minplayers");
            if ((pcVar12 != (char *)0x0) && (*pcVar12 != '\0')) {
              lVar9 = strtol(pcVar12,(char **)0x0,10);
              pgVar16 = gpGlobals;
              iVar13 = 0;
              if (-1 < lVar9) {
                iVar13 = lVar9;
              }
              pmVar7->minplayers = iVar13;
              iVar10 = pgVar16->maxClients;
              if (iVar13 <= pgVar16->maxClients) {
                iVar10 = iVar13;
              }
              pmVar7->minplayers = iVar10;
            }
            pcVar12 = (*g_engfuncs.pfnInfoKeyValue)(local_48c,"maxplayers");
            if ((pcVar12 != (char *)0x0) && (*pcVar12 != '\0')) {
              lVar9 = strtol(pcVar12,(char **)0x0,10);
              pgVar16 = gpGlobals;
              iVar13 = 0;
              if (-1 < lVar9) {
                iVar13 = lVar9;
              }
              pmVar7->maxplayers = iVar13;
              iVar10 = pgVar16->maxClients;
              if (iVar13 <= pgVar16->maxClients) {
                iVar10 = iVar13;
              }
              pmVar7->maxplayers = iVar10;
            }
            (*g_engfuncs.pfnInfo_RemoveKey)(local_48c,"minplayers");
            (*g_engfuncs.pfnInfo_RemoveKey)(local_48c,"maxplayers");
            strcpy(pcVar1,local_48c);
          }
          pmVar7->next = ChangeLevel::lexical_block_0::mapcycle.items;
          ChangeLevel::lexical_block_0::mapcycle.items = pmVar7;
        }
      }
                    /* Unresolved local var: char[1024] szBuffer@[???]
                       Unresolved local var: char[32] szMap@[???]
                       Unresolved local var: int length@[???]
                       Unresolved local var: char * pFileList@[???]
                       Unresolved local var: int hasbuffer@[???]
                       Unresolved local var: mapcycle_item_s * item@[???]
                       Unresolved local var: mapcycle_item_s * newlist@[???]
                       Unresolved local var: mapcycle_item_s * next@[???]
                       Unresolved local var: char * aFileList@[???] */
      (*g_engfuncs.pfnFreeFile)(pbVar6);
    }
    pmVar7 = (mapcycle_item_s *)0x0;
    if (ChangeLevel::lexical_block_0::mapcycle.items != (mapcycle_item_s *)0x0) {
      do {
        ChangeLevel::lexical_block_0::mapcycle.next_item =
             ChangeLevel::lexical_block_0::mapcycle.items;
        ChangeLevel::lexical_block_0::mapcycle.items =
             (ChangeLevel::lexical_block_0::mapcycle.next_item)->next;
        (ChangeLevel::lexical_block_0::mapcycle.next_item)->next = pmVar7;
        pmVar7 = ChangeLevel::lexical_block_0::mapcycle.next_item;
      } while (ChangeLevel::lexical_block_0::mapcycle.items != (mapcycle_item_s *)0x0);
      do {
        pmVar11 = pmVar7;
        pmVar7 = pmVar11->next;
      } while (pmVar7 != (mapcycle_item_s *)0x0);
      ChangeLevel::lexical_block_0::mapcycle.items =
           ChangeLevel::lexical_block_0::mapcycle.next_item;
      pmVar11->next = ChangeLevel::lexical_block_0::mapcycle.next_item;
      pgVar16 = gpGlobals;
      if (ChangeLevel::lexical_block_0::mapcycle.items != (mapcycle_item_s *)0x0) goto LAB_000dab2d;
    }
    (*g_engfuncs.pfnAlertMessage)(at_console,"Unable to load map cycle file %s\n",__s1);
  }
  local_1060 = 0;
  uVar14 = 0;
  local_1064 = (byte *)0x0;
  iVar13 = (*g_engfuncs.pfnIsMapValid)(local_8c);
joined_r0x000dad0f:
  if (iVar13 == 0) {
    strcpy(local_8c,(char *)&local_6c);
  }
  local_105c = local_104c;
  g_fGameOver = 1;
  (*g_engfuncs.pfnAlertMessage)(at_console,"CHANGE LEVEL: %s\n",local_8c);
  if (uVar14 != 0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"PLAYER COUNT:  min %i max %i current %i\n",local_1064,local_1060,iVar18);
  }
  if (local_104c[0] != '\0') {
    (*g_engfuncs.pfnAlertMessage)(at_console,"RULES:  %s\n",local_105c);
  }
  (*g_engfuncs.pfnChangeLevel)(local_8c,(char *)0x0);
  if (local_a68[0] != '\0') {
    (*g_engfuncs.pfnServerCommand)(local_a68);
  }
  return;
}


// CHalfLifeMultiplay::SendMOTDToClient  @ 000d8400  (line 2070)

/* DWARF original prototype: void SendMOTDToClient(CHalfLifeMultiplay * this, edict_t * client) */

void __thiscall CHalfLifeMultiplay::SendMOTDToClient(CHalfLifeMultiplay *this,edict_t *client)

{
  _func_void_char_ptr *p_Var1;
  _func_byte_ptr_char_ptr_int_ptr *p_Var2;
  char *pcVar3;
  byte *pbVar4;
  size_t sVar5;
  byte *__s;
  int iVar6;
  char local_5d [60];
  undefined1 local_21;
  int local_20 [4];
  
                    /* Unresolved local var: int length@[???]
                       Unresolved local var: int char_count@[???]
                       Unresolved local var: char * pFileList@[???]
                       Unresolved local var: char * aFileList@[???] */
  (*g_engfuncs.pfnMessageBegin)(1,gmsgServerName,(float *)0x0,client);
  p_Var1 = g_engfuncs.pfnWriteString;
  pcVar3 = (*g_engfuncs.pfnCVarGetString)("hostname");
  (*p_Var1)(pcVar3);
  (*g_engfuncs.pfnMessageEnd)();
  p_Var2 = g_engfuncs.pfnLoadFileForMe;
  pcVar3 = (*g_engfuncs.pfnCVarGetString)("motdfile");
  pbVar4 = (*p_Var2)(pcVar3,local_20);
  if ((pbVar4 != (byte *)0x0) && (*pbVar4 != '\0')) {
    iVar6 = 0;
    __s = pbVar4;
    do {
                    /* Unresolved local var: char[61] chunk@[???] */
      sVar5 = strlen((char *)__s);
      if (sVar5 < 0x3c) {
        strcpy(local_5d,(char *)__s);
      }
      else {
        strncpy(local_5d,(char *)__s,0x3c);
        local_21 = 0;
      }
      sVar5 = strlen(local_5d);
      iVar6 = sVar5 + iVar6;
      if (iVar6 < 0x600) {
        __s = pbVar4 + iVar6;
      }
      else {
        *__s = '\0';
      }
      (*g_engfuncs.pfnMessageBegin)(1,gmsgMOTD,(float *)0x0,client);
      (*g_engfuncs.pfnWriteByte)((uint)(*__s == '\0'));
      (*g_engfuncs.pfnWriteString)(local_5d);
      (*g_engfuncs.pfnMessageEnd)();
    } while ((*__s != '\0') && (iVar6 < 0x600));
  }
  (*g_engfuncs.pfnFreeFile)(pbVar4);
  return;
}


