// Ghidra decompilation of functions from tfc/gamerules.cpp
// 68 functions, ordered by original source line

// CGameRules::CanHaveAmmo  @ 0009b300  (line 48)

/* DWARF original prototype: BOOL CanHaveAmmo(CGameRules * this, CBasePlayer * pPlayer, char *
   pszAmmoName, int iMaxCarry) */

BOOL __thiscall
CGameRules::CanHaveAmmo(CGameRules *this,CBasePlayer *pPlayer,char *pszAmmoName,int iMaxCarry)

{
  int iVar1;
  
                    /* Unresolved local var: int iAmmoIndex@[???] */
  if (pszAmmoName != (char *)0x0) {
    iVar1 = CBasePlayer::GetAmmoIndex(pszAmmoName);
    if (-1 < iVar1) {
      iVar1 = CBasePlayer::AmmoInventory(pPlayer,iVar1);
      return (uint)(iVar1 < iMaxCarry);
    }
  }
  return 0;
}


// CGameRules::GetPlayerSpawnSpot  @ 0009b340  (line 71)

/* WARNING: Variable defined which should be unmapped: pDeath */
/* DWARF original prototype: void GetPlayerSpawnSpot(CGameRules * this, CBasePlayer * pPlayer) */

void __thiscall CGameRules::GetPlayerSpawnSpot(CGameRules *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  vec_t vVar5;
  vec_t vVar6;
  vec_t vVar7;
  _2globalvars_t *p1Var8;
  edict_t *peVar9;
  int iVar10;
  int iVar11;
  CBasePlayer *pCVar12;
  edict_t *peVar13;
  string_t sVar14;
  CTelefragDeath *this_00;
  entvars_t *peVar15;
  CBasePlayer *pStartEntity;
  CBaseEntity *Goal;
  longdouble extraout_ST0;
  char *sample;
  CTelefragDeath *pDeath;
  
                    /* Unresolved local var: edict_t * pentSpawnSpot@[???]
                       Unresolved local var: CBaseEntity * Spot@[???]
                       Unresolved local var: CBasePlayer * client@[???] */
  peVar9 = EntSelectSpawnPoint(((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating
                                .super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  peVar4 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar15 = &peVar9->v;
  if (peVar9 == (edict_t *)0x0) {
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
  vVar7 = g_vecZero.z;
  vVar6 = g_vecZero.y;
  vVar5 = g_vecZero.x;
  peVar4 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar4->v_angle).x = g_vecZero.x;
  (peVar4->v_angle).y = vVar6;
  (peVar4->v_angle).z = vVar7;
  peVar4 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar4->velocity).y = vVar6;
  (peVar4->velocity).x = vVar5;
  (peVar4->velocity).z = vVar7;
  peVar4 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar4->angles).x = (peVar15->angles).x;
  (peVar4->angles).y = (peVar15->angles).y;
  vVar7 = g_vecZero.z;
  (peVar4->angles).z = (peVar15->angles).z;
  peVar15 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  (peVar15->punchangle).y = vVar6;
  (peVar15->punchangle).x = vVar5;
  (peVar15->punchangle).z = vVar7;
  ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->fixangle = 1;
  if (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->playerclass != 0) {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar13 = (*g_engfuncs.pfnCreateEntity)();
    peVar15 = &peVar13->v;
    if (peVar13 == (edict_t *)0x0) {
      peVar15 = (entvars_t *)0x0;
    }
    if ((peVar15->pContainingEntity == (edict_t *)0x0) ||
       (this_00 = peVar15->pContainingEntity->pvPrivateData, this_00 == (CTelefragDeath *)0x0)) {
      this_00 = CBaseEntity::operator_new(0x478,peVar15);
      (this_00->super_CBaseEntity)._vptr_CBaseEntity =
           (_func_int_varargs **)&PTR__CTelefragDeath_0014f258;
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
  if ((peVar9 == (edict_t *)0x0) &&
     (peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar9 == (edict_t *)0x0)) {
    Goal = (CBaseEntity *)0x0;
  }
  else {
    Goal = peVar9->pvPrivateData;
  }
  iVar10 = (*Goal->_vptr_CBaseEntity[10])(Goal);
  p1Var8 = gpGlobals;
  if ((iVar10 != 0x83) || (gpGlobals->time <= cb_prematch_time)) goto LAB_0009b490;
  sVar14 = Goal->pev->message;
  if (sVar14 == 0) {
LAB_0009b670:
    sVar14 = Goal->org_message;
    if ((sVar14 != 0) && (pPlayer->forced_spawn == 0)) {
LAB_0009b6da:
      ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,4,p1Var8->pStringBase + sVar14,(char *)0x0,
                  (char *)0x0,(char *)0x0,(char *)0x0);
      if ((Goal->goal_activation & 2) == 0) {
        Goal->org_message = 0;
      }
    }
  }
  else if (pPlayer->forced_spawn == 0) {
    pPlayer->delayed_spawn_message = sVar14;
    if ((Goal->goal_activation & 2) == 0) {
      Goal->pev->message = 0;
      goto LAB_0009b670;
    }
    sVar14 = Goal->org_message;
    if (sVar14 == 0) goto LAB_0009b67a;
    goto LAB_0009b6da;
  }
LAB_0009b67a:
  DoResults(Goal,pPlayer,1);
  if ((Goal->items != 0) && ((Goal->goal_activation & 1) == 0)) {
    Goal->items = 0;
  }
  if (Goal->goal_effects == 1) {
    Goal->goal_state = 3;
  }
LAB_0009b490:
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
  while (((pStartEntity = (CBasePlayer *)
                          UTIL_FindEntityByClassname((CBaseEntity *)pStartEntity,"player"),
          pStartEntity != (CBasePlayer *)0x0 &&
          (peVar9 = ((pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
          peVar9 != (edict_t *)0x0)) &&
         (iVar10 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar9), iVar10 != 0))) {
    peVar15 = (pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev;
    if (((pPlayer != pStartEntity) && (peVar15 != (entvars_t *)0x0)) &&
       ((iVar10 = peVar15->iuser2,
        iVar11 = (*g_engfuncs.pfnIndexOfEdict)
                           (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity),
        iVar10 == iVar11 &&
        (pCVar12 = (CBasePlayer *)
                   EHANDLE::operator_cast_to_CBaseEntity_(&pStartEntity->m_hObserverTarget),
        pPlayer == pCVar12)))) {
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


// CGameRules::CanHavePlayerItem  @ 0009c860  (line 187)

/* DWARF original prototype: BOOL CanHavePlayerItem(CGameRules * this, CBasePlayer * pPlayer,
   CBasePlayerItem * pWeapon) */

BOOL __thiscall
CGameRules::CanHavePlayerItem(CGameRules *this,CBasePlayer *pPlayer,CBasePlayerItem *pWeapon)

{
  int iVar1;
  BOOL BVar2;
  undefined1 local_38 [8];
  char *local_30;
  int local_2c;
  
                    /* Unresolved local var: ItemInfo info@[???] */
  iVar1 = (*(pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
            [0x45])(pWeapon,local_38);
  if (iVar1 == 0) {
    return 1;
  }
  if (local_30 != (char *)0x0) {
    if (this->_vptr_CGameRules[0x28] == CanHaveAmmo) {
                    /* Unresolved local var: int iAmmoIndex@[???] */
      iVar1 = CBasePlayer::GetAmmoIndex(local_30);
      if ((-1 < iVar1) && (iVar1 = CBasePlayer::AmmoInventory(pPlayer,iVar1), iVar1 < local_2c)) {
        return 1;
      }
    }
    else {
      iVar1 = (*this->_vptr_CGameRules[0x28])(this,pPlayer,local_30,local_2c);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  BVar2 = CBasePlayer::HasPlayerItem(pPlayer,pWeapon);
  return (uint)(BVar2 == 0);
}


// CGameRules::RefreshSkillData  @ 0009ae30  (line 226)

/* DWARF original prototype: void RefreshSkillData(CGameRules * this) */

void __thiscall CGameRules::RefreshSkillData(CGameRules *this)

{
  gSkillData.plrDmg357 = 40.0;
  gSkillData.turretHealth = 1000.0;
  gSkillData.miniturretHealth = 1000.0;
  gSkillData.sentryHealth = 1000.0;
  gSkillData.plrDmgTripmine = 150.0;
  gSkillData.plrDmgCrowbar = 25.0;
  gSkillData.monDmg12MM = 8.0;
  gSkillData.plrDmg9MM = 12.0;
  gSkillData.plrDmgMP5 = 12.0;
  gSkillData.monDmg9MM = 5.0;
  gSkillData.plrDmgM203Grenade = 100.0;
  gSkillData.suitchargerCapacity = 75.0;
  gSkillData.plrDmgBuckshot = 20.0;
  gSkillData.plrDmgCrossbowClient = 20.0;
  gSkillData.plrDmgRPG = 120.0;
  gSkillData.plrDmgEgonWide = 20.0;
  gSkillData.plrDmgEgonNarrow = 10.0;
  gSkillData.plrDmgHandGrenade = 100.0;
  gSkillData.plrDmgSatchel = 120.0;
  gSkillData.plrDmgHornet = 10.0;
  gSkillData.monDmgMP5 = 3.0;
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
  return;
}


// CHalfLifeRules::CHalfLifeRules  @ 0009d070  (line 308)

/* DWARF original prototype: void CHalfLifeRules(CHalfLifeRules * this) */

void __thiscall CHalfLifeRules::CHalfLifeRules(CHalfLifeRules *this)

{
  (this->super_CGameRules)._vptr_CGameRules = (_func_int_varargs **)&PTR_RefreshSkillData_0014f444;
  gSkillData.turretHealth = 1000.0;
  gSkillData.miniturretHealth = 1000.0;
  gSkillData.sentryHealth = 1000.0;
  gSkillData.plrDmg357 = 40.0;
  gSkillData.plrDmgCrowbar = 25.0;
  gSkillData.plrDmgTripmine = 150.0;
  gSkillData.plrDmg9MM = 12.0;
  gSkillData.plrDmgMP5 = 12.0;
  gSkillData.monDmg12MM = 8.0;
  gSkillData.plrDmgM203Grenade = 100.0;
  gSkillData.monDmg9MM = 5.0;
  gSkillData.plrDmgBuckshot = 20.0;
  gSkillData.plrDmgCrossbowClient = 20.0;
  gSkillData.suitchargerCapacity = 75.0;
  gSkillData.plrDmgRPG = 120.0;
  gSkillData.plrDmgEgonWide = 20.0;
  gSkillData.plrDmgEgonNarrow = 10.0;
  gSkillData.plrDmgHandGrenade = 100.0;
  gSkillData.plrDmgSatchel = 120.0;
  gSkillData.plrDmgHornet = 10.0;
  gSkillData.monDmgMP5 = 3.0;
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
  return;
}


// CHalfLifeRules::Think  @ 0009af60  (line 316)

/* DWARF original prototype: void Think(CHalfLifeRules * this) */

void __thiscall CHalfLifeRules::Think(CHalfLifeRules *this)

{
  return;
}


// CHalfLifeRules::FShouldSwitchWeapon  @ 0009af70  (line 344)

/* DWARF original prototype: BOOL FShouldSwitchWeapon(CHalfLifeRules * this, CBasePlayer * pPlayer,
   CBasePlayerItem * pWeapon) */

BOOL __thiscall
CHalfLifeRules::FShouldSwitchWeapon
          (CHalfLifeRules *this,CBasePlayer *pPlayer,CBasePlayerItem *pWeapon)

{
  CBasePlayerItem *pCVar1;
  int iVar2;
  
  pCVar1 = pPlayer->m_pActiveItem;
  if (pCVar1 != (CBasePlayerItem *)0x0) {
    iVar2 = (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
              [0x48])(pCVar1);
    return (uint)(iVar2 != 0);
  }
  return 1;
}


// CHalfLifeRules::ClientConnected  @ 0009afb0  (line 371)

/* DWARF original prototype: BOOL ClientConnected(CHalfLifeRules * this, edict_t * pEntity, char *
   pszName, char * pszAddress, char * szRejectReason) */

BOOL __thiscall
CHalfLifeRules::ClientConnected
          (CHalfLifeRules *this,edict_t *pEntity,char *pszName,char *pszAddress,char *szRejectReason
          )

{
  return 1;
}


// CHalfLifeRules::FlPlayerFallDamage  @ 0009afc0  (line 386)

/* DWARF original prototype: float FlPlayerFallDamage(CHalfLifeRules * this, CBasePlayer * pPlayer)
    */

float __thiscall CHalfLifeRules::FlPlayerFallDamage(CHalfLifeRules *this,CBasePlayer *pPlayer)

{
  float fVar1;
  
  fVar1 = pPlayer->m_flFallVelocity - 650.0;
  pPlayer->m_flFallVelocity = fVar1;
  return (fVar1 * 100.0) / 374.0;
}


// CHalfLifeRules::AllowAutoTargetCrosshair  @ 0009aff0  (line 403)

/* DWARF original prototype: BOOL AllowAutoTargetCrosshair(CHalfLifeRules * this) */

BOOL __thiscall CHalfLifeRules::AllowAutoTargetCrosshair(CHalfLifeRules *this)

{
  return (uint)(g_iSkillLevel == 1);
}


// CHalfLifeRules::PlayerThink  @ 0009b000  (line 409)

/* DWARF original prototype: void PlayerThink(CHalfLifeRules * this, CBasePlayer * pPlayer) */

void __thiscall CHalfLifeRules::PlayerThink(CHalfLifeRules *this,CBasePlayer *pPlayer)

{
  return;
}


// CHalfLifeRules::DeathNotice  @ 0009b010  (line 447)

/* DWARF original prototype: void DeathNotice(CHalfLifeRules * this, CBasePlayer * pVictim,
   entvars_t * pKiller, entvars_t * pInflictor) */

void __thiscall
CHalfLifeRules::DeathNotice
          (CHalfLifeRules *this,CBasePlayer *pVictim,entvars_t *pKiller,entvars_t *pInflictor)

{
  return;
}


// CHalfLifeRules::FlWeaponTryRespawn  @ 0009b020  (line 475)

/* DWARF original prototype: float FlWeaponTryRespawn(CHalfLifeRules * this, CBasePlayerItem *
   pWeapon) */

float __thiscall CHalfLifeRules::FlWeaponTryRespawn(CHalfLifeRules *this,CBasePlayerItem *pWeapon)

{
  return 0.0;
}


// CHalfLifeRules::WeaponShouldRespawn  @ 0009b030  (line 493)

/* DWARF original prototype: int WeaponShouldRespawn(CHalfLifeRules * this, CBasePlayerItem *
   pWeapon) */

int __thiscall CHalfLifeRules::WeaponShouldRespawn(CHalfLifeRules *this,CBasePlayerItem *pWeapon)

{
  return 2;
}


// CHalfLifeRules::ItemShouldRespawn  @ 0009b040  (line 513)

/* DWARF original prototype: int ItemShouldRespawn(CHalfLifeRules * this, CItem * pItem) */

int __thiscall CHalfLifeRules::ItemShouldRespawn(CHalfLifeRules *this,CItem *pItem)

{
  return 6;
}


// CHalfLifeRules::AmmoShouldRespawn  @ 0009b050  (line 551)

/* DWARF original prototype: int AmmoShouldRespawn(CHalfLifeRules * this, CBasePlayerAmmo * pAmmo)
    */

int __thiscall CHalfLifeRules::AmmoShouldRespawn(CHalfLifeRules *this,CBasePlayerAmmo *pAmmo)

{
  return 4;
}


// CHalfLifeRules::FlAmmoRespawnTime  @ 0009b060  (line 558)

/* DWARF original prototype: float FlAmmoRespawnTime(CHalfLifeRules * this, CBasePlayerAmmo * pAmmo)
    */

float __thiscall CHalfLifeRules::FlAmmoRespawnTime(CHalfLifeRules *this,CBasePlayerAmmo *pAmmo)

{
  return -1.0;
}


// CHalfLifeRules::FlHealthChargerRechargeTime  @ 0009b070  (line 572)

/* DWARF original prototype: float FlHealthChargerRechargeTime(CHalfLifeRules * this) */

float __thiscall CHalfLifeRules::FlHealthChargerRechargeTime(CHalfLifeRules *this)

{
  return 0.0;
}


// CHalfLifeRules::DeadPlayerWeapons  @ 0009b080  (line 579)

/* DWARF original prototype: int DeadPlayerWeapons(CHalfLifeRules * this, CBasePlayer * pPlayer) */

int __thiscall CHalfLifeRules::DeadPlayerWeapons(CHalfLifeRules *this,CBasePlayer *pPlayer)

{
  return 9;
}


// CHalfLifeRules::DeadPlayerAmmo  @ 0009b090  (line 586)

/* DWARF original prototype: int DeadPlayerAmmo(CHalfLifeRules * this, CBasePlayer * pPlayer) */

int __thiscall CHalfLifeRules::DeadPlayerAmmo(CHalfLifeRules *this,CBasePlayer *pPlayer)

{
  return 0xc;
}


// CHalfLifeMultiplay::CHalfLifeMultiplay  @ 0009d1a0  (line 601)

/* DWARF original prototype: void CHalfLifeMultiplay(CHalfLifeMultiplay * this) */

void __thiscall CHalfLifeMultiplay::CHalfLifeMultiplay(CHalfLifeMultiplay *this)

{
  int iVar1;
  char *pcVar2;
  int in_GS_OFFSET;
  char local_110 [256];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  (this->super_CGameRules)._vptr_CGameRules = (_func_int_varargs **)&PTR_RefreshSkillData_0014f524;
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
      __sprintf_chk(local_110,1,0x100,"exec %s\n",pcVar2);
      (*g_engfuncs.pfnServerCommand)(local_110);
    }
  }
  (*g_engfuncs.pfnServerExecute)();
  pcVar2 = (*g_engfuncs.pfnCVarGetString)("hostname");
  UTIL_LogPrintf("Server name is \"%s\"\n",pcVar2);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CHalfLifeMultiplay::Think  @ 0009ccb0  (line 654)

/* DWARF original prototype: void Think(CHalfLifeMultiplay * this) */

void __thiscall CHalfLifeMultiplay::Think(CHalfLifeMultiplay *this)

{
  float fVar1;
  float fVar2;
  _2globalvars_t *p1Var3;
  _func_void_char_ptr_char_ptr *p_Var4;
  _func_void_cvar_s_ptr_char_ptr *p_Var5;
  edict_t *peVar6;
  int iVar7;
  char *pcVar8;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  int iVar9;
  int iVar10;
  int iVar11;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: int frags_remaining@[???]
                       Unresolved local var: int time_remaining@[???]
                       Unresolved local var: float flTimeLimit@[???]
                       Unresolved local var: float flFragLimit@[???] */
  fVar2 = fraglimit.value;
  if (g_fGameOver == 0) {
    fVar1 = timelimit.value * 60.0;
    if (fVar1 == 0.0) {
      iVar11 = 0;
    }
    else {
      iVar11 = (int)(fVar1 - gpGlobals->time);
      if (fVar1 <= gpGlobals->time) {
        UNRECOVERED_JUMPTABLE = (this->super_CGameRules)._vptr_CGameRules[0x36];
        if (UNRECOVERED_JUMPTABLE == GoToIntermission) {
LAB_0009ce12:
          (*g_engfuncs.pfnMessageBegin)(2,0x1e,(float *)0x0,(edict_t *)0x0);
          (*g_engfuncs.pfnMessageEnd)();
          fVar2 = gpGlobals->time;
          g_fGameOver = 1;
          this->m_iEndIntermissionButtonHit = 0;
          this->m_flIntermissionEndTime = fVar2 + 6.0;
          return;
        }
        goto LAB_0009cee0;
      }
    }
    if (fraglimit.value == 0.0) {
      iVar10 = 0;
    }
    else {
                    /* Unresolved local var: int bestfrags@[???]
                       Unresolved local var: int remain@[???]
                       Unresolved local var: int i@[???] */
      if (gpGlobals->maxClients < 1) {
        iVar10 = 9999;
      }
      else {
        iVar9 = 1;
        iVar10 = 9999;
        do {
                    /* Unresolved local var: edict_t * cl@[???] */
          peVar6 = (*g_engfuncs.pfnPEntityOfEntIndex)(iVar9);
          if (peVar6 != (edict_t *)0x0) {
            fVar1 = (peVar6->v).frags;
            if (fVar2 <= fVar1) {
              UNRECOVERED_JUMPTABLE = (this->super_CGameRules)._vptr_CGameRules[0x36];
              if (UNRECOVERED_JUMPTABLE != GoToIntermission) goto LAB_0009cee0;
              if (g_fGameOver != 0) {
                return;
              }
              goto LAB_0009ce12;
            }
            iVar7 = (int)(fVar2 - fVar1);
            if (iVar7 < iVar10) {
              iVar10 = iVar7;
            }
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 <= gpGlobals->maxClients);
      }
    }
    p_Var5 = g_engfuncs.pfnCvar_DirectSet;
    if (iVar10 != Think::last_frags) {
      pcVar8 = UTIL_VarArgs("%i",iVar10);
      (*p_Var5)(&fragsleft,pcVar8);
    }
    p_Var5 = g_engfuncs.pfnCvar_DirectSet;
    if (timeleft.value != (float)Think::last_time) {
      pcVar8 = UTIL_VarArgs("%i",iVar11);
      (*p_Var5)(&timeleft,pcVar8);
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
      pcVar8 = UTIL_dtos1(0x78);
      (*p_Var4)("mp_chattime",pcVar8);
    }
    p1Var3 = gpGlobals;
    fVar2 = mp_chattime.value + this->m_flIntermissionStartTime;
    this->m_flIntermissionEndTime = fVar2;
    iVar11 = Think::last_time;
    iVar10 = Think::last_frags;
    if ((fVar2 < p1Var3->time) &&
       ((this->m_iEndIntermissionButtonHit != 0 ||
        (this->m_flIntermissionStartTime + 120.0 < p1Var3->time)))) {
      UNRECOVERED_JUMPTABLE = (this->super_CGameRules)._vptr_CGameRules[0x37];
LAB_0009cee0:
                    /* WARNING: Could not recover jumptable at 0x0009cee7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
  }
  Think::last_frags = iVar10;
  Think::last_time = iVar11;
  return;
}


// CHalfLifeMultiplay::IsDeathmatch  @ 0009b0a0  (line 751)

/* DWARF original prototype: BOOL IsDeathmatch(CHalfLifeMultiplay * this) */

BOOL __thiscall CHalfLifeMultiplay::IsDeathmatch(CHalfLifeMultiplay *this)

{
  return 1;
}


// CHalfLifeMultiplay::IsCoOp  @ 0009b0b0  (line 758)

/* DWARF original prototype: BOOL IsCoOp(CHalfLifeMultiplay * this) */

BOOL __thiscall CHalfLifeMultiplay::IsCoOp(CHalfLifeMultiplay *this)

{
  return 0;
}


// CHalfLifeMultiplay::ClientCommand  @ 0009c370  (line 801)

/* DWARF original prototype: BOOL ClientCommand(CHalfLifeMultiplay * this, CBasePlayer * pPlayer,
   char * pcmd) */

BOOL __thiscall
CHalfLifeMultiplay::ClientCommand(CHalfLifeMultiplay *this,CBasePlayer *pPlayer,char *pcmd)

{
  char *__nptr;
  long lVar1;
  int iVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  
  bVar4 = &stack0x00000000 < (undefined1 *)0x2c;
  bVar5 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar2 = 0xb;
  pbVar3 = (byte *)"menuselect";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar4 = (byte)*pcmd < *pbVar3;
    bVar5 = *pcmd == *pbVar3;
    pcmd = pcmd + 1;
    pbVar3 = pbVar3 + 1;
  } while (bVar5);
  if ((!bVar4 && !bVar5) != bVar4) {
    return 0;
  }
                    /* Unresolved local var: int slot@[???] */
  iVar2 = (*g_engfuncs.pfnCmd_Argc)();
  if (1 < iVar2) {
                    /* Unresolved local var: int slot@[???] */
    __nptr = (*g_engfuncs.pfnCmd_Argv)(1);
    lVar1 = strtol(__nptr,(char **)0x0,10);
    CBasePlayer::Menu_Input(pPlayer,(float)lVar1);
    return 1;
  }
  return 1;
}


// CHalfLifeMultiplay::GetNextBestWeapon  @ 0009c510  (line 819)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL GetNextBestWeapon(CHalfLifeMultiplay * this, CBasePlayer *
   pPlayer, CBasePlayerItem * pCurrentWeapon) */

BOOL __thiscall
CHalfLifeMultiplay::GetNextBestWeapon
          (CHalfLifeMultiplay *this,CBasePlayer *pPlayer,CBasePlayerItem *pCurrentWeapon)

{
  CBasePlayerItem *pCVar1;
  int iVar2;
  int iVar3;
  BOOL BVar4;
  CBasePlayerItem *pWeapon;
  int local_5c;
  CBasePlayerItem **local_58;
  CBasePlayerItem *local_54;
  undefined1 local_48 [40];
  int local_20;
  
                    /* Unresolved local var: CBasePlayerItem * pCheck@[???]
                       Unresolved local var: CBasePlayerItem * pBest@[???]
                       Unresolved local var: ItemInfo Info@[???]
                       Unresolved local var: int iBestWeight@[???]
                       Unresolved local var: int iCurrentWeight@[???]
                       Unresolved local var: int i@[???] */
  iVar2 = (*(pCurrentWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x48])(pCurrentWeapon);
  if (iVar2 == 0) {
    return 0;
  }
                    /* Unresolved local var: CBasePlayerItem * pCheck@[???]
                       Unresolved local var: CBasePlayerItem * pBest@[???]
                       Unresolved local var: ItemInfo Info@[???]
                       Unresolved local var: int iBestWeight@[???]
                       Unresolved local var: int iCurrentWeight@[???]
                       Unresolved local var: int i@[???] */
  (*(pCurrentWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
    [0x45])(pCurrentWeapon,local_48);
  iVar2 = local_20;
  local_54 = (CBasePlayerItem *)0x0;
  local_58 = pPlayer->m_rgpPlayerItems;
  local_5c = -1;
  do {
    pCVar1 = *local_58;
joined_r0x0009c58a:
    pWeapon = pCVar1;
    if (pWeapon != (CBasePlayerItem *)0x0) {
      do {
        (*(pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x45]
        )(pWeapon,local_48);
        if (((iVar2 == local_20 & (byte)~(byte)((uint)local_20 >> 0x18) >> 7) == 0) ||
           (pCurrentWeapon == pWeapon)) {
          if ((local_5c < local_20) &&
             ((pCurrentWeapon != pWeapon &&
              (iVar3 = (*(pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                         _vptr_CBaseEntity[0x46])(pWeapon), iVar3 != 0)))) goto code_r0x0009c5fc;
        }
        else {
          iVar3 = (*(pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                    _vptr_CBaseEntity[0x46])(pWeapon);
          if ((iVar3 != 0) && (BVar4 = CBasePlayer::SwitchWeapon(pPlayer,pWeapon), BVar4 != 0)) {
            return 1;
          }
        }
        pWeapon = pWeapon->m_pNext;
        if (pWeapon == (CBasePlayerItem *)0x0) break;
      } while( true );
    }
    local_58 = local_58 + 1;
    if (local_58 == &pPlayer->m_pActiveItem) {
      if (local_54 == (CBasePlayerItem *)0x0) {
        return 0;
      }
      CBasePlayer::SwitchWeapon(pPlayer,local_54);
      return 1;
    }
  } while( true );
code_r0x0009c5fc:
  pCVar1 = pWeapon->m_pNext;
  local_5c = local_20;
  local_54 = pWeapon;
  goto joined_r0x0009c58a;
}


// CHalfLifeMultiplay::ClientConnected  @ 0009b7c0  (line 897)

/* DWARF original prototype: BOOL ClientConnected(CHalfLifeMultiplay * this, edict_t * pEntity, char
   * pszName, char * pszAddress, char * szRejectReason) */

BOOL __thiscall
CHalfLifeMultiplay::ClientConnected
          (CHalfLifeMultiplay *this,edict_t *pEntity,char *pszName,char *pszAddress,
          char *szRejectReason)

{
  int iVar1;
  BOOL BVar2;
  char *pcVar3;
  CGhost *pCVar4;
  int iVar5;
  
                    /* Unresolved local var: CGhost * pGhost@[???]
                       Unresolved local var: int iGhostID@[???] */
  iVar1 = GetBattleID(pEntity);
  pCVar4 = (CGhost *)0x0;
  if (iVar1 != 0) {
    pCVar4 = FindGhost(iVar1);
  }
  if (((tfc_clanbattle_locked.value == 0.0) || (gpGlobals->time <= cb_prematch_time)) ||
     (pCVar4 != (CGhost *)0x0)) {
                    /* Unresolved local var: int i@[???] */
    if (-1 < gpGlobals->maxClients) {
      iVar5 = 0;
      iVar1 = g_IpStorage[0].ip;
      while (iVar1 != 0) {
        iVar5 = iVar5 + 1;
        if (gpGlobals->maxClients < iVar5) goto LAB_0009b820;
        iVar1 = g_IpStorage[iVar5].ip;
      }
                    /* Unresolved local var: char * pColon@[???] */
      pcVar3 = strchr(pszAddress,0x3a);
      if (pcVar3 != (char *)0x0) {
        *pcVar3 = '\0';
        iVar1 = (*g_engfuncs.pfnAllocString)(pszAddress);
        g_IpStorage[iVar5].pEdict = pEntity;
        g_IpStorage[iVar5].ip = iVar1;
        *pcVar3 = ':';
        return 1;
      }
      iVar1 = (*g_engfuncs.pfnAllocString)(pszAddress);
      g_IpStorage[iVar5].pEdict = pEntity;
      g_IpStorage[iVar5].ip = iVar1;
    }
LAB_0009b820:
    BVar2 = 1;
  }
  else {
    builtin_strncpy(szRejectReason,"#Game_locked",0xd);
    BVar2 = 0;
  }
  return BVar2;
}


// CHalfLifeMultiplay::UpdateGameMode  @ 0009b0c0  (line 946)

/* DWARF original prototype: void UpdateGameMode(CHalfLifeMultiplay * this, CBasePlayer * pPlayer)
    */

void __thiscall CHalfLifeMultiplay::UpdateGameMode(CHalfLifeMultiplay *this,CBasePlayer *pPlayer)

{
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgGameMode,(float *)0x0,
             ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(0);
                    /* WARNING: Could not recover jumptable at 0x0009b100. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CHalfLifeMultiplay::InitHUD  @ 0009c9e0  (line 955)

/* DWARF original prototype: void InitHUD(CHalfLifeMultiplay * this, CBasePlayer * pl) */

void __thiscall CHalfLifeMultiplay::InitHUD(CHalfLifeMultiplay *this,CBasePlayer *pl)

{
  string_t sVar1;
  _func_int_varargs *p_Var2;
  void *pvVar3;
  _func_void_int *p_Var4;
  char *param1;
  int iVar5;
  edict_t *peVar6;
  
  sVar1 = ((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->netname;
  param1 = "unconnected";
  if ((sVar1 != 0) && (param1 = gpGlobals->pStringBase + sVar1, *param1 == '\0')) {
    param1 = "unconnected";
  }
  UTIL_ClientPrintAll(1,"#Game_playerjoin",param1,(char *)0x0,(char *)0x0,(char *)0x0);
  p_Var2 = (this->super_CGameRules)._vptr_CGameRules[0xe];
  if (p_Var2 == UpdateGameMode) {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgGameMode,(float *)0x0,
               ((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnMessageEnd)();
  }
  else {
    (*p_Var2)(this,pl);
  }
  pl->m_MenuUpdateTime = gpGlobals->time + 0.1;
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgScoreInfo,(float *)0x0,
             ((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  p_Var4 = g_engfuncs.pfnWriteByte;
  iVar5 = (*g_engfuncs.pfnIndexOfEdict)
                    (((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var4)(iVar5);
                    /* Unresolved local var: int i@[???] */
  iVar5 = 1;
  (*g_engfuncs.pfnWriteShort)(0);
  (*g_engfuncs.pfnWriteShort)(0);
  (*g_engfuncs.pfnWriteShort)(0);
  (*g_engfuncs.pfnWriteShort)(0);
  (*g_engfuncs.pfnMessageEnd)();
  if (0 < gpGlobals->maxClients) {
    do {
                    /* Unresolved local var: edict_t * ed@[???]
                       Unresolved local var: CBasePlayer * plr@[???] */
      peVar6 = (*g_engfuncs.pfnPEntityOfEntIndex)(iVar5);
      if ((peVar6 != (edict_t *)0x0) && (pvVar3 = peVar6->pvPrivateData, pvVar3 != (void *)0x0)) {
        (*g_engfuncs.pfnMessageBegin)
                  (1,gmsgScoreInfo,(float *)0x0,
                   ((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                    .super_CBaseEntity.pev)->pContainingEntity);
        (*g_engfuncs.pfnWriteByte)(iVar5);
        (*g_engfuncs.pfnWriteShort)((int)*(float *)(*(int *)((int)pvVar3 + 4) + 0x164));
        (*g_engfuncs.pfnWriteShort)(*(int *)((int)pvVar3 + 0xa1c));
        (*g_engfuncs.pfnWriteShort)(*(int *)(*(int *)((int)pvVar3 + 4) + 0x20c));
        (*g_engfuncs.pfnWriteShort)(*(int *)(*(int *)((int)pvVar3 + 4) + 0x1ac));
        (*g_engfuncs.pfnMessageEnd)();
        (*g_engfuncs.pfnMessageBegin)
                  (1,gmsgSpectator,(float *)0x0,
                   ((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                    .super_CBaseEntity.pev)->pContainingEntity);
        (*g_engfuncs.pfnWriteByte)(iVar5);
        (*g_engfuncs.pfnWriteByte)((uint)(*(int *)(*(int *)((int)pvVar3 + 4) + 0x244) != 0));
        (*g_engfuncs.pfnMessageEnd)();
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= gpGlobals->maxClients);
  }
  SendBuildingEventInfo(pl);
  if (g_fGameOver != 0) {
    (*g_engfuncs.pfnMessageBegin)
              (1,0x1e,(float *)0x0,
               ((pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
                    /* WARNING: Could not recover jumptable at 0x0009cc8f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnMessageEnd)();
    return;
  }
  return;
}


// CHalfLifeMultiplay::ClientDisconnected  @ 0009b8e0  (line 1014)

/* DWARF original prototype: void ClientDisconnected(CHalfLifeMultiplay * this, edict_t * pClient)
    */

void __thiscall CHalfLifeMultiplay::ClientDisconnected(CHalfLifeMultiplay *this,edict_t *pClient)

{
  CBasePlayer *this_00;
  _func_void_int *p_Var1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  
                    /* Unresolved local var: CBasePlayer * pPlayer@[???]
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
                    /* WARNING: Could not recover jumptable at 0x0009ba21. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnMessageEnd)();
    return;
  }
  return;
}


// CHalfLifeMultiplay::FlPlayerFallDamage  @ 0009c6e0  (line 1055)

/* DWARF original prototype: float FlPlayerFallDamage(CHalfLifeMultiplay * this, CBasePlayer *
   pPlayer) */

float __thiscall
CHalfLifeMultiplay::FlPlayerFallDamage(CHalfLifeMultiplay *this,CBasePlayer *pPlayer)

{
  float fVar1;
  
                    /* Unresolved local var: int iFallDamage@[???] */
  if ((int)falldamage.value == 1) {
                    /* Unresolved local var: int iFallDamage@[???] */
    fVar1 = pPlayer->m_flFallVelocity - 650.0;
    pPlayer->m_flFallVelocity = fVar1;
    return (fVar1 * 100.0) / 374.0;
  }
  return 10.0;
}


// CHalfLifeMultiplay::PlayerThink  @ 0009c690  (line 1079)

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


// CHalfLifeMultiplay::PlayerSpawn  @ 0009ba70  (line 1095)

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
    super_CBaseEntity._vptr_CBaseEntity[0x18])(pPlayer,0x44,&DAT_0014efc5,0xfa,0);
  return;
}


// CHalfLifeMultiplay::FlPlayerSpawnTime  @ 0009b110  (line 1113)

/* DWARF original prototype: float FlPlayerSpawnTime(CHalfLifeMultiplay * this, CBasePlayer *
   pPlayer) */

float __thiscall
CHalfLifeMultiplay::FlPlayerSpawnTime(CHalfLifeMultiplay *this,CBasePlayer *pPlayer)

{
  return gpGlobals->time;
}


// CHalfLifeMultiplay::AllowAutoTargetCrosshair  @ 0009b120  (line 1118)

/* DWARF original prototype: BOOL AllowAutoTargetCrosshair(CHalfLifeMultiplay * this) */

BOOL __thiscall CHalfLifeMultiplay::AllowAutoTargetCrosshair(CHalfLifeMultiplay *this)

{
  uint uVar1;
  
  uVar1 = (uint)NAN(aimcrosshair.value);
  if (aimcrosshair.value != 0.0) {
    uVar1 = 1;
  }
  return uVar1;
}


// CHalfLifeMultiplay::PlayerKilled  @ 0009c720  (line 1135)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PlayerKilled(CHalfLifeMultiplay * this, CBasePlayer * pVictim,
   entvars_t * pKiller, entvars_t * pInflictor) */

void __thiscall
CHalfLifeMultiplay::PlayerKilled
          (CHalfLifeMultiplay *this,CBasePlayer *pVictim,entvars_t *pKiller,entvars_t *pInflictor)

{
  int *piVar1;
  _func_int_varargs *p_Var2;
  int iVar3;
  edict_t *peVar4;
  CBasePlayer *this_00;
  
                    /* Unresolved local var: CBasePlayer * peKiller@[???]
                       Unresolved local var: CBaseEntity * ktmp@[???]
                       Unresolved local var: CBaseEntity * ep@[???] */
  (*(this->super_CGameRules)._vptr_CGameRules[0x1c])(this,pVictim,pKiller,pInflictor);
  pVictim->m_iDeaths = pVictim->m_iDeaths + 1;
  peVar4 = pKiller->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((((peVar4 == (edict_t *)0x0) &&
       (peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar4 == (edict_t *)0x0)) ||
      (this_00 = peVar4->pvPrivateData, this_00 == (CBasePlayer *)0x0)) ||
     (iVar3 = (*(this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[10])(this_00), iVar3 != 2)) {
    this_00 = (CBasePlayer *)0x0;
  }
  if ((pKiller ==
       (pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev) || ((pKiller->flags & 8) == 0)) {
    CBasePlayer::TF_AddFrags(pVictim,-1);
  }
  else {
    p_Var2 = (this->super_CGameRules)._vptr_CGameRules[0x1a];
    iVar3 = 1;
    if (p_Var2 != CanHaveItem) {
      iVar3 = (*p_Var2)(this,this_00,pVictim);
    }
    CBasePlayer::TF_AddFrags(this_00,iVar3);
  }
  peVar4 = pKiller->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((peVar4 != (edict_t *)0x0) ||
      (peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar4 != (edict_t *)0x0)) &&
     ((piVar1 = peVar4->pvPrivateData, piVar1 != (int *)0x0 &&
      (iVar3 = (**(code **)(*piVar1 + 0x28))(piVar1), iVar3 == 2)))) {
                    /* Unresolved local var: CBasePlayer * PK@[???] */
    piVar1[0x298] = (int)gpGlobals->time;
  }
  return;
}


// CHalfLifeMultiplay::DeathNotice  @ 0009bae0  (line 1174)

/* DWARF original prototype: void DeathNotice(CHalfLifeMultiplay * this, CBasePlayer * pVictim,
   entvars_t * pKiller, entvars_t * pevInflictor) */

void __thiscall
CHalfLifeMultiplay::DeathNotice
          (CHalfLifeMultiplay *this,CBasePlayer *pVictim,entvars_t *pKiller,entvars_t *pevInflictor)

{
  string_t sVar1;
  int *piVar2;
  _func_void_int *p_Var3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  entvars_t *peVar8;
  uint uVar9;
  edict_t *peVar10;
  char *pcVar11;
  byte *pbVar12;
  char *pcVar13;
  void *pvVar14;
  byte *pbVar15;
  bool bVar16;
  bool bVar17;
  byte bVar18;
  byte *local_60;
  char *local_5c;
  undefined1 local_48 [24];
  byte *local_30;
  
                    /* Unresolved local var: CBaseEntity * Killer@[???]
                       Unresolved local var: char * killer_weapon_name@[???]
                       Unresolved local var: int killer_index@[???] */
  bVar18 = 0;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (pKiller->pContainingEntity == (edict_t *)0x0) {
    (*g_engfuncs.pfnPEntityOfEntOffset)(0);
  }
  local_5c = (char *)0x0;
  local_60 = (byte *)g_pszDeathType;
  pbVar12 = local_60;
  if (g_pszDeathType != (char *)0x0) goto LAB_0009bb1d;
  if ((pKiller->flags & 8) == 0) {
    peVar10 = pevInflictor->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (((peVar10 == (edict_t *)0x0) &&
        (peVar10 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar10 == (edict_t *)0x0)) ||
       ((peVar10->pvPrivateData == (void *)0x0 ||
        (uVar9 = *(uint *)((int)peVar10->pvPrivateData + 0x418), uVar9 == 0)))) {
      uVar9 = pevInflictor->classname;
    }
    local_5c = (char *)0x0;
    bVar16 = CARRY4(uVar9,(uint)gpGlobals->pStringBase);
    local_60 = (byte *)(gpGlobals->pStringBase + uVar9);
    bVar17 = local_60 == (byte *)0x0;
LAB_0009be99:
    iVar4 = 7;
    pbVar12 = local_60;
    pbVar15 = (byte *)0x1494b6;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar16 = *pbVar12 < *pbVar15;
      bVar17 = *pbVar12 == *pbVar15;
      pbVar12 = pbVar12 + (uint)bVar18 * -2 + 1;
      pbVar15 = pbVar15 + (uint)bVar18 * -2 + 1;
    } while (bVar17);
    if (bVar17) {
      pbVar12 = local_60 + 7;
    }
    else {
      iVar4 = 10;
      pbVar12 = local_60;
      pbVar15 = (byte *)"tf_weapon_";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar16 = *pbVar12 < *pbVar15;
        bVar17 = *pbVar12 == *pbVar15;
        pbVar12 = pbVar12 + (uint)bVar18 * -2 + 1;
        pbVar15 = pbVar15 + (uint)bVar18 * -2 + 1;
      } while (bVar17);
      if (bVar17) {
        pbVar12 = local_60 + 10;
      }
      else {
        iVar4 = 8;
        pbVar12 = local_60;
        pbVar15 = (byte *)"monster_";
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar16 = *pbVar12 < *pbVar15;
          bVar17 = *pbVar12 == *pbVar15;
          pbVar12 = pbVar12 + (uint)bVar18 * -2 + 1;
          pbVar15 = pbVar15 + (uint)bVar18 * -2 + 1;
        } while (bVar17);
        if (bVar17) {
          pbVar12 = local_60 + 8;
        }
        else {
          iVar4 = 5;
          pbVar12 = local_60;
          pbVar15 = &DAT_0014b358;
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar16 = *pbVar12 < *pbVar15;
            bVar17 = *pbVar12 == *pbVar15;
            pbVar12 = pbVar12 + (uint)bVar18 * -2 + 1;
            pbVar15 = pbVar15 + (uint)bVar18 * -2 + 1;
          } while (bVar17);
          pbVar12 = local_60 + 5;
          if ((!bVar16 && !bVar17) != bVar16) {
            pbVar12 = local_60;
          }
        }
      }
    }
  }
  else {
    local_5c = (char *)(*g_engfuncs.pfnIndexOfEdict)(pKiller->pContainingEntity);
    if (pevInflictor != (entvars_t *)0x0) {
      if (pKiller != pevInflictor) {
        peVar10 = pevInflictor->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        if ((((peVar10 == (edict_t *)0x0) &&
             (peVar10 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar10 == (edict_t *)0x0)) ||
            (peVar10->pvPrivateData == (void *)0x0)) ||
           (uVar9 = *(uint *)((int)peVar10->pvPrivateData + 0x418), uVar9 == 0)) {
          uVar9 = pevInflictor->classname;
        }
        bVar16 = CARRY4(uVar9,(uint)gpGlobals->pStringBase);
        local_60 = (byte *)(gpGlobals->pStringBase + uVar9);
        bVar17 = local_60 == (byte *)0x0;
        goto LAB_0009be99;
      }
      peVar10 = pKiller->pContainingEntity;
                    /* Unresolved local var: CBasePlayer * pPlayer@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      if (peVar10 == (edict_t *)0x0) {
        peVar10 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
        pvVar14 = (void *)0x0;
        if (peVar10 != (edict_t *)0x0) goto LAB_0009c07b;
      }
      else {
LAB_0009c07b:
        pvVar14 = peVar10->pvPrivateData;
      }
      piVar2 = *(int **)((int)pvVar14 + 0x8fc);
      if (piVar2 != (int *)0x0) {
        uVar9 = piVar2[0x106];
        if (uVar9 == 0) {
                    /* Unresolved local var: ItemInfo II@[???] */
          iVar4 = (**(code **)(*piVar2 + 0x114))(piVar2,local_48);
          bVar16 = false;
          bVar17 = iVar4 == 0;
          local_60 = (byte *)0x14b349;
          if (!bVar17) {
            local_60 = local_30;
          }
        }
        else {
          bVar16 = CARRY4(uVar9,(uint)gpGlobals->pStringBase);
          local_60 = (byte *)(gpGlobals->pStringBase + uVar9);
          bVar17 = local_60 == (byte *)0x0;
        }
        goto LAB_0009be99;
      }
    }
    local_60 = (byte *)0x14b349;
    pbVar12 = local_60;
  }
LAB_0009bb1d:
  local_60 = pbVar12;
  (*g_engfuncs.pfnMessageBegin)(2,gmsgDeathMsg,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)((int)local_5c);
  p_Var3 = g_engfuncs.pfnWriteByte;
  iVar4 = (*g_engfuncs.pfnIndexOfEdict)
                    (((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var3)(iVar4);
  (*g_engfuncs.pfnWriteString)((char *)local_60);
  (*g_engfuncs.pfnMessageEnd)();
  peVar8 = (pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (pKiller == peVar8) {
    iVar4 = (pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
    if (iVar4 == 0) {
      pcVar11 = "SPECTATOR";
      peVar8 = pKiller;
    }
    else {
      pcVar11 = GetTeamName(iVar4);
      peVar8 = (pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.pev;
    }
    pcVar5 = (*g_engfuncs.pfnGetPlayerAuthId)(peVar8->pContainingEntity);
    iVar4 = (*g_engfuncs.pfnGetPlayerUserId)
                      (((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" committed suicide with \"%s\"\n",
                   gpGlobals->pStringBase +
                   ((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar4,pcVar5,pcVar11,local_60);
  }
  else if ((pKiller->flags & 8) == 0) {
    iVar4 = (pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
    pcVar11 = "SPECTATOR";
    if (iVar4 != 0) {
      pcVar11 = GetTeamName(iVar4);
      peVar8 = (pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.pev;
    }
    pcVar5 = (*g_engfuncs.pfnGetPlayerAuthId)(peVar8->pContainingEntity);
    iVar4 = (*g_engfuncs.pfnGetPlayerUserId)
                      (((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" committed suicide with \"%s\" (world)\n",
                   gpGlobals->pStringBase +
                   ((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar4,pcVar5,pcVar11,local_60);
  }
  else {
    peVar10 = pKiller->pContainingEntity;
                    /* Unresolved local var: CBasePlayer * pPlayer@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar10 == (edict_t *)0x0) &&
       (peVar10 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar10 == (edict_t *)0x0)) {
      pvVar14 = (void *)0x0;
    }
    else {
      pvVar14 = peVar10->pvPrivateData;
    }
    iVar4 = (pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
    local_5c = "SPECTATOR";
    if (iVar4 != 0) {
      local_5c = GetTeamName(iVar4);
    }
    pcVar5 = (*g_engfuncs.pfnGetPlayerAuthId)
                       (((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar4 = (*g_engfuncs.pfnGetPlayerUserId)
                      (((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    sVar1 = ((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->netname;
    pcVar11 = gpGlobals->pStringBase;
    pcVar13 = "SPECTATOR";
    if (*(int *)((int)pvVar14 + 0x138) != 0) {
      pcVar13 = GetTeamName(*(int *)((int)pvVar14 + 0x138));
    }
    pcVar6 = (*g_engfuncs.pfnGetPlayerAuthId)(pKiller->pContainingEntity);
    iVar7 = (*g_engfuncs.pfnGetPlayerUserId)(pKiller->pContainingEntity);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" killed \"%s<%i><%s><%s>\" with \"%s\"\n",
                   gpGlobals->pStringBase + pKiller->netname,iVar7,pcVar6,pcVar13,pcVar11 + sVar1,
                   iVar4,pcVar5,local_5c,local_60);
  }
  g_pszDeathType = (char *)0x0;
  (*g_engfuncs.pfnMessageBegin)(9,0x33,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(9);
  (*g_engfuncs.pfnWriteByte)(2);
  p_Var3 = g_engfuncs.pfnWriteShort;
  iVar4 = (*g_engfuncs.pfnIndexOfEdict)
                    (((pVictim->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var3)(iVar4);
  p_Var3 = g_engfuncs.pfnWriteShort;
  if (pevInflictor == (entvars_t *)0x0) {
    iVar4 = (*g_engfuncs.pfnIndexOfEdict)(pKiller->pContainingEntity);
    (*p_Var3)(iVar4);
  }
  else {
    iVar4 = (*g_engfuncs.pfnIndexOfEdict)(pevInflictor->pContainingEntity);
    (*p_Var3)(iVar4);
  }
  (*g_engfuncs.pfnWriteLong)(0x27);
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CHalfLifeMultiplay::FlWeaponRespawnTime  @ 0009c110  (line 1326)

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
                    /* Unresolved local var: ItemInfo II@[???] */
      return gpGlobals->time + 0.0;
    }
  }
  return gpGlobals->time + 20.0;
}


// CHalfLifeMultiplay::FlWeaponTryRespawn  @ 0009cfa0  (line 1353)

/* DWARF original prototype: float FlWeaponTryRespawn(CHalfLifeMultiplay * this, CBasePlayerItem *
   pWeapon) */

float __thiscall
CHalfLifeMultiplay::FlWeaponTryRespawn(CHalfLifeMultiplay *this,CBasePlayerItem *pWeapon)

{
  _func_int_varargs *p_Var1;
  int iVar2;
  longdouble lVar3;
  longdouble extraout_ST0;
  undefined1 local_38 [36];
  uint local_14;
  
  if (((pWeapon != (CBasePlayerItem *)0x0) && (pWeapon->m_iId != 0)) &&
     ((CBasePlayerItem::ItemInfoArray[pWeapon->m_iId].iFlags & 8) != 0)) {
    iVar2 = (*g_engfuncs.pfnNumberOfEntities)();
    if (gpGlobals->maxEntities + -100 <= iVar2) {
      p_Var1 = (this->super_CGameRules)._vptr_CGameRules[0x20];
      if (p_Var1 == FlWeaponRespawnTime) {
        if (0.0 < weaponstay.value) {
                    /* Unresolved local var: ItemInfo II@[???] */
          local_14 = 0;
          (*(pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
            [0x45])(pWeapon,local_38);
          if ((local_14 & 8) == 0) {
                    /* Unresolved local var: ItemInfo II@[???] */
            lVar3 = (longdouble)0 + (longdouble)gpGlobals->time;
            goto LAB_0009cfc8;
          }
        }
        lVar3 = (longdouble)20.0 + (longdouble)gpGlobals->time;
      }
      else {
        (*p_Var1)(this,pWeapon);
        lVar3 = extraout_ST0;
      }
      goto LAB_0009cfc8;
    }
  }
  lVar3 = (longdouble)0;
LAB_0009cfc8:
  return (float)lVar3;
}


// CHalfLifeMultiplay::VecWeaponRespawnSpot  @ 0009b140  (line 1372)

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


// CHalfLifeMultiplay::WeaponShouldRespawn  @ 0009b170  (line 1381)

/* DWARF original prototype: int WeaponShouldRespawn(CHalfLifeMultiplay * this, CBasePlayerItem *
   pWeapon) */

int __thiscall
CHalfLifeMultiplay::WeaponShouldRespawn(CHalfLifeMultiplay *this,CBasePlayerItem *pWeapon)

{
  return 2 - (uint)((((pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->
                     spawnflags & 0x40000000U) == 0);
}


// CHalfLifeMultiplay::CanHavePlayerItem  @ 0009c930  (line 1394)

/* DWARF original prototype: BOOL CanHavePlayerItem(CHalfLifeMultiplay * this, CBasePlayer *
   pPlayer, CBasePlayerItem * pItem) */

BOOL __thiscall
CHalfLifeMultiplay::CanHavePlayerItem
          (CHalfLifeMultiplay *this,CBasePlayer *pPlayer,CBasePlayerItem *pItem)

{
  CBasePlayerItem *pCVar1;
  BOOL BVar2;
  CBasePlayerItem **ppCVar3;
  undefined1 local_48 [32];
  int local_28;
  uint local_24;
  
  if (0.0 < weaponstay.value) {
                    /* Unresolved local var: ItemInfo II@[???] */
    local_24 = 0;
    (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x45])
              (pItem,local_48);
    if ((local_24 & 8) == 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CBasePlayerItem * it@[???] */
      ppCVar3 = pPlayer->m_rgpPlayerItems;
      do {
        for (pCVar1 = *ppCVar3; pCVar1 != (CBasePlayerItem *)0x0; pCVar1 = pCVar1->m_pNext) {
          if (pCVar1->m_iId == local_28) {
            return 0;
          }
        }
        ppCVar3 = ppCVar3 + 1;
      } while (ppCVar3 != &pPlayer->m_pActiveItem);
    }
  }
  BVar2 = CGameRules::CanHavePlayerItem(&this->super_CGameRules,pPlayer,pItem);
  return BVar2;
}


// CHalfLifeMultiplay::CanHaveItem  @ 0009b190  (line 1429)

/* DWARF original prototype: BOOL CanHaveItem(CHalfLifeMultiplay * this, CBasePlayer * pPlayer,
   CItem * pItem) */

BOOL __thiscall
CHalfLifeMultiplay::CanHaveItem(CHalfLifeMultiplay *this,CBasePlayer *pPlayer,CItem *pItem)

{
  return 1;
}


// CHalfLifeMultiplay::PlayerGotItem  @ 0009b1a0  (line 1434)

/* DWARF original prototype: void PlayerGotItem(CHalfLifeMultiplay * this, CBasePlayer * pPlayer,
   CItem * pItem) */

void __thiscall
CHalfLifeMultiplay::PlayerGotItem(CHalfLifeMultiplay *this,CBasePlayer *pPlayer,CItem *pItem)

{
  return;
}


// CHalfLifeMultiplay::ItemShouldRespawn  @ 0009b1b0  (line 1441)

/* DWARF original prototype: int ItemShouldRespawn(CHalfLifeMultiplay * this, CItem * pItem) */

int __thiscall CHalfLifeMultiplay::ItemShouldRespawn(CHalfLifeMultiplay *this,CItem *pItem)

{
  return 6 - (uint)((((pItem->super_CBaseEntity).pev)->spawnflags & 0x40000000U) == 0);
}


// CHalfLifeMultiplay::FlItemRespawnTime  @ 0009b1d0  (line 1455)

/* DWARF original prototype: float FlItemRespawnTime(CHalfLifeMultiplay * this, CItem * pItem) */

float __thiscall CHalfLifeMultiplay::FlItemRespawnTime(CHalfLifeMultiplay *this,CItem *pItem)

{
  return gpGlobals->time + 30.0;
}


// CHalfLifeMultiplay::VecItemRespawnSpot  @ 0009b1e0  (line 1464)

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


// CHalfLifeMultiplay::PlayerGotAmmo  @ 0009b210  (line 1470)

/* DWARF original prototype: void PlayerGotAmmo(CHalfLifeMultiplay * this, CBasePlayer * pPlayer,
   char * szName, int iCount) */

void __thiscall
CHalfLifeMultiplay::PlayerGotAmmo
          (CHalfLifeMultiplay *this,CBasePlayer *pPlayer,char *szName,int iCount)

{
  return;
}


// CHalfLifeMultiplay::IsAllowedToSpawn  @ 0009b220  (line 1481)

/* DWARF original prototype: BOOL IsAllowedToSpawn(CHalfLifeMultiplay * this, CBaseEntity * pEntity)
    */

BOOL __thiscall CHalfLifeMultiplay::IsAllowedToSpawn(CHalfLifeMultiplay *this,CBaseEntity *pEntity)

{
  return 1;
}


// CHalfLifeMultiplay::AmmoShouldRespawn  @ 0009b230  (line 1487)

/* DWARF original prototype: int AmmoShouldRespawn(CHalfLifeMultiplay * this, CBasePlayerAmmo *
   pAmmo) */

int __thiscall
CHalfLifeMultiplay::AmmoShouldRespawn(CHalfLifeMultiplay *this,CBasePlayerAmmo *pAmmo)

{
  return 4 - (uint)((((pAmmo->super_CBaseEntity).pev)->spawnflags & 0x40000000U) == 0);
}


// CHalfLifeMultiplay::FlAmmoRespawnTime  @ 0009b250  (line 1499)

/* DWARF original prototype: float FlAmmoRespawnTime(CHalfLifeMultiplay * this, CBasePlayerAmmo *
   pAmmo) */

float __thiscall
CHalfLifeMultiplay::FlAmmoRespawnTime(CHalfLifeMultiplay *this,CBasePlayerAmmo *pAmmo)

{
  return gpGlobals->time + 20.0;
}


// CHalfLifeMultiplay::VecAmmoRespawnSpot  @ 0009b260  (line 1506)

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


// CHalfLifeMultiplay::FlHealthChargerRechargeTime  @ 0009b290  (line 1514)

/* DWARF original prototype: float FlHealthChargerRechargeTime(CHalfLifeMultiplay * this) */

float __thiscall CHalfLifeMultiplay::FlHealthChargerRechargeTime(CHalfLifeMultiplay *this)

{
  return 60.0;
}


// CHalfLifeMultiplay::FlHEVChargerRechargeTime  @ 0009b2a0  (line 1520)

/* DWARF original prototype: float FlHEVChargerRechargeTime(CHalfLifeMultiplay * this) */

float __thiscall CHalfLifeMultiplay::FlHEVChargerRechargeTime(CHalfLifeMultiplay *this)

{
  return 30.0;
}


// CHalfLifeMultiplay::DeadPlayerWeapons  @ 0009b2b0  (line 1527)

/* DWARF original prototype: int DeadPlayerWeapons(CHalfLifeMultiplay * this, CBasePlayer * pPlayer)
    */

int __thiscall CHalfLifeMultiplay::DeadPlayerWeapons(CHalfLifeMultiplay *this,CBasePlayer *pPlayer)

{
  return 8;
}


// CHalfLifeMultiplay::DeadPlayerAmmo  @ 0009b2c0  (line 1534)

/* DWARF original prototype: int DeadPlayerAmmo(CHalfLifeMultiplay * this, CBasePlayer * pPlayer) */

int __thiscall CHalfLifeMultiplay::DeadPlayerAmmo(CHalfLifeMultiplay *this,CBasePlayer *pPlayer)

{
  return 0xb;
}


// CHalfLifeMultiplay::PlayerRelationship  @ 0009b2d0  (line 1542)

/* DWARF original prototype: int PlayerRelationship(CHalfLifeMultiplay * this, CBasePlayer *
   pPlayer, CBaseEntity * pTarget) */

int __thiscall
CHalfLifeMultiplay::PlayerRelationship
          (CHalfLifeMultiplay *this,CBasePlayer *pPlayer,CBaseEntity *pTarget)

{
  return 0;
}


// CHalfLifeMultiplay::PlayFootstepSounds  @ 0009c490  (line 1545)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL PlayFootstepSounds(CHalfLifeMultiplay * this, CBasePlayer * pl,
   float fvol) */

BOOL __thiscall
CHalfLifeMultiplay::PlayFootstepSounds(CHalfLifeMultiplay *this,CBasePlayer *pl,float fvol)

{
  float fVar1;
  entvars_t *peVar2;
  BOOL BVar3;
  float fVar4;
  
  if ((g_footsteps != (cvar_t *)0x0) && (g_footsteps->value == 0.0)) {
    return 0;
  }
  BVar3 = CBasePlayer::IsOnLadder(pl);
  if (BVar3 == 0) {
    peVar2 = (pl->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar1 = (peVar2->velocity).x;
    fVar4 = (peVar2->velocity).y;
    fVar1 = fVar4 * fVar4 + fVar1 * fVar1;
    fVar4 = SQRT(fVar1);
    if (NAN(fVar4)) {
      fVar4 = sqrtf(fVar1);
    }
    if (fVar4 <= 220.0) {
      return 0;
    }
  }
  return 1;
}


// CHalfLifeMultiplay::FAllowFlashlight  @ 0009b2e0  (line 1557)

/* DWARF original prototype: BOOL FAllowFlashlight(CHalfLifeMultiplay * this) */

BOOL __thiscall CHalfLifeMultiplay::FAllowFlashlight(CHalfLifeMultiplay *this)

{
  uint uVar1;
  
  uVar1 = (uint)NAN(flashlight.value);
  if (flashlight.value != 0.0) {
    uVar1 = 1;
  }
  return uVar1;
}


// CHalfLifeMultiplay::GoToIntermission  @ 0009c420  (line 1567)

/* DWARF original prototype: void GoToIntermission(CHalfLifeMultiplay * this) */

void __thiscall CHalfLifeMultiplay::GoToIntermission(CHalfLifeMultiplay *this)

{
  float fVar1;
  
  if (g_fGameOver != 0) {
    return;
  }
  (*g_engfuncs.pfnMessageBegin)(2,0x1e,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnMessageEnd)();
  fVar1 = gpGlobals->time;
  g_fGameOver = 1;
  this->m_iEndIntermissionButtonHit = 0;
  this->m_flIntermissionEndTime = fVar1 + 6.0;
  return;
}


// DestroyMapCycle  @ 0009d3f0  (line 1604)

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
    if (pmVar3 != pmVar2) {
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


// COM_Parse  @ 0009d440  (line 1634)

char * COM_Parse(char *data)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: int len@[???] */
  com_token[0] = '\0';
  if (data == (char *)0x0) {
    return (char *)0x0;
  }
  cVar5 = *data;
  while( true ) {
    while (iVar4 = (int)cVar5, iVar4 < 0x21) {
      if (iVar4 == 0) {
        com_token[0] = '\0';
        return (char *)0x0;
      }
      pcVar3 = data + 1;
      data = data + 1;
      cVar5 = *pcVar3;
    }
    if (iVar4 != 0x2f) break;
    cVar5 = data[1];
    pcVar3 = data;
    if (cVar5 != '/') goto LAB_0009d522;
    while ((data = pcVar3 + 1, cVar5 != '\0' && (cVar5 != '\n'))) {
      cVar5 = pcVar3[2];
      pcVar3 = data;
    }
  }
  if (iVar4 == 0x22) {
    cVar5 = data[1];
    pcVar3 = data + 2;
    if ((cVar5 == '\"') || (cVar5 == '\0')) {
      iVar4 = 0;
      goto LAB_0009d4e7;
    }
    iVar4 = 0;
    pcVar2 = pcVar3;
    goto LAB_0009d4d4;
  }
  if (((((cVar5 + 0x85U & 0xfd) == 0) || (iVar4 - 0x28U < 2)) || (iVar4 == 0x27)) || (iVar4 == 0x2c)
     ) {
    com_token[0] = cVar5;
    com_token[1] = '\0';
    return data + 1;
  }
LAB_0009d522:
  iVar1 = 0;
  do {
    iVar6 = iVar1;
    com_token[iVar6] = (char)iVar4;
    data = data + 1;
    cVar5 = *data;
    iVar4 = (int)cVar5;
    if (((cVar5 + 0x85U & 0xfd) == 0) || (iVar4 < 0x21 || iVar4 == 0x2c)) break;
    iVar1 = iVar6 + 1;
  } while (2 < (byte)(cVar5 - 0x27U));
  com_token[iVar6 + 1] = '\0';
  return data;
  while (pcVar2 = pcVar3, cVar5 != '\0') {
LAB_0009d4d4:
    com_token[iVar4] = cVar5;
    pcVar3 = pcVar2 + 1;
    iVar4 = iVar4 + 1;
    cVar5 = *pcVar2;
    if (cVar5 == '\"') break;
  }
LAB_0009d4e7:
  com_token[iVar4] = '\0';
  return pcVar3;
}


// COM_TokenWaiting  @ 0009d580  (line 1711)

int COM_TokenWaiting(char *buffer)

{
  int iVar1;
  char cVar2;
  
                    /* Unresolved local var: char * p@[???] */
  cVar2 = *buffer;
  if ((cVar2 == '\0') || (cVar2 == '\n')) {
    iVar1 = 0;
  }
  else {
    while( true ) {
      iVar1 = isspace((int)cVar2);
      if ((iVar1 == 0) || (iVar1 = isalnum((int)cVar2), iVar1 != 0)) break;
      buffer = buffer + 1;
      cVar2 = *buffer;
      if (cVar2 == '\0') {
        return 0;
      }
      if (cVar2 == '\n') {
        return 0;
      }
    }
    iVar1 = 1;
  }
  return iVar1;
}


// ReloadMapCycleFile  @ 0009d5e0  (line 1735)

int ReloadMapCycleFile(char *filename,mapcycle_t *cycle)

{
  char *pcVar1;
  _2globalvars_t *p1Var2;
  byte bVar3;
  byte *pbVar4;
  mapcycle_item_s *pmVar5;
  int iVar6;
  uint uVar7;
  mapcycle_item_s *pmVar8;
  uint uVar9;
  mapcycle_item_s *pmVar10;
  char *pcVar11;
  char *pcVar12;
  byte *pbVar13;
  int in_GS_OFFSET;
  bool bVar14;
  byte *local_45c;
  int local_444;
  char local_440 [32];
  char local_420 [4];
  int aiStack_41c [259];
  
                    /* Unresolved local var: char[1024] szBuffer@[???]
                       Unresolved local var: char[32] szMap@[???]
                       Unresolved local var: int length@[???]
                       Unresolved local var: char * pFileList@[???]
                       Unresolved local var: char * aFileList@[???]
                       Unresolved local var: int hasbuffer@[???]
                       Unresolved local var: mapcycle_item_s * item@[???]
                       Unresolved local var: mapcycle_item_s * newlist@[???]
                       Unresolved local var: mapcycle_item_s * next@[???] */
  aiStack_41c[0xff] = *(int *)(in_GS_OFFSET + 0x14);
  pbVar4 = (*g_engfuncs.pfnLoadFileForMe)(filename,&local_444);
  if ((pbVar4 != (byte *)0x0) && (local_444 != 0)) {
    local_45c = pbVar4;
LAB_0009d6a0:
    do {
      uVar7 = 0;
      do {
        pcVar11 = local_420 + uVar7;
        pcVar11[0] = '\0';
        pcVar11[1] = '\0';
        pcVar11[2] = '\0';
        pcVar11[3] = '\0';
        *(undefined4 *)((int)aiStack_41c + uVar7) = 0;
        uVar7 = uVar7 + 8;
      } while (uVar7 < 0x400);
      local_45c = (byte *)COM_Parse((char *)local_45c);
      if (com_token[0] == '\0') goto LAB_0009d8ef;
      __strcpy_chk(local_440,com_token,0x20);
                    /* Unresolved local var: char * p@[???] */
      bVar3 = *local_45c;
      if ((bVar3 == '\n') || (pbVar13 = local_45c, bVar3 == '\0')) {
LAB_0009d820:
        iVar6 = (*g_engfuncs.pfnIsMapValid)(local_440);
        if (iVar6 == 0) {
LAB_0009d8d0:
          (*g_engfuncs.pfnAlertMessage)
                    (at_console,"Skipping %s from mapcycle, not a valid map\n",local_440);
          goto LAB_0009d6a0;
        }
        pmVar8 = operator_new(0x42c);
        __strcpy_chk(pmVar8->mapname,local_440,0x20);
        pcVar11 = pmVar8->rulebuffer;
        uVar7 = 0x400;
        bVar14 = ((uint)pcVar11 & 1) != 0;
        pmVar8->minplayers = 0;
        pmVar8->maxplayers = 0;
        if (bVar14) {
          pmVar8->rulebuffer[0] = '\0';
          pcVar11 = pmVar8->rulebuffer + 1;
          uVar7 = 0x3ff;
        }
        if (((uint)pcVar11 & 2) != 0) {
          pcVar11[0] = '\0';
          pcVar11[1] = '\0';
          uVar7 = uVar7 - 2;
          pcVar11 = pcVar11 + 2;
        }
        uVar9 = 0;
        do {
          pcVar12 = pcVar11 + uVar9;
          pcVar12[0] = '\0';
          pcVar12[1] = '\0';
          pcVar12[2] = '\0';
          pcVar12[3] = '\0';
          pcVar12 = pcVar11 + uVar9 + 4;
          pcVar12[0] = '\0';
          pcVar12[1] = '\0';
          pcVar12[2] = '\0';
          pcVar12[3] = '\0';
          uVar9 = uVar9 + 8;
        } while (uVar9 < (uVar7 & 0xfffffff8));
        pcVar11 = pcVar11 + uVar9;
        if ((uVar7 & 4) != 0) {
          pcVar11[0] = '\0';
          pcVar11[1] = '\0';
          pcVar11[2] = '\0';
          pcVar11[3] = '\0';
          pcVar11 = pcVar11 + 4;
        }
        if ((uVar7 & 2) != 0) {
          pcVar11[0] = '\0';
          pcVar11[1] = '\0';
          pcVar11 = pcVar11 + 2;
        }
        if (bVar14) {
          *pcVar11 = '\0';
        }
      }
      else {
LAB_0009d728:
        iVar6 = isspace((int)(char)bVar3);
        if ((iVar6 != 0) && (iVar6 = isalnum((int)(char)bVar3), iVar6 == 0)) goto code_r0x0009d714;
        local_45c = (byte *)COM_Parse((char *)local_45c);
        if (com_token[0] != '\0') {
          __strcpy_chk(local_420,com_token,0x400);
          iVar6 = (*g_engfuncs.pfnIsMapValid)(local_440);
          if (iVar6 != 0) {
            pmVar8 = operator_new(0x42c);
            pcVar11 = pmVar8->rulebuffer;
            __strcpy_chk(pmVar8->mapname,local_440,0x20);
            bVar14 = ((uint)pcVar11 & 1) != 0;
            pmVar8->minplayers = 0;
            uVar7 = 0x400;
            pmVar8->maxplayers = 0;
            pcVar12 = pcVar11;
            if (bVar14) {
              pmVar8->rulebuffer[0] = '\0';
              pcVar12 = pmVar8->rulebuffer + 1;
              uVar7 = 0x3ff;
            }
            if (((uint)pcVar12 & 2) != 0) {
              pcVar12[0] = '\0';
              pcVar12[1] = '\0';
              uVar7 = uVar7 - 2;
              pcVar12 = pcVar12 + 2;
            }
            uVar9 = 0;
            do {
              pcVar1 = pcVar12 + uVar9;
              pcVar1[0] = '\0';
              pcVar1[1] = '\0';
              pcVar1[2] = '\0';
              pcVar1[3] = '\0';
              pcVar1 = pcVar12 + uVar9 + 4;
              pcVar1[0] = '\0';
              pcVar1[1] = '\0';
              pcVar1[2] = '\0';
              pcVar1[3] = '\0';
              uVar9 = uVar9 + 8;
            } while (uVar9 < (uVar7 & 0xfffffff8));
            pcVar12 = pcVar12 + uVar9;
            if ((uVar7 & 4) != 0) {
              pcVar12[0] = '\0';
              pcVar12[1] = '\0';
              pcVar12[2] = '\0';
              pcVar12[3] = '\0';
              pcVar12 = pcVar12 + 4;
            }
            if ((uVar7 & 2) != 0) {
              pcVar12[0] = '\0';
              pcVar12[1] = '\0';
              pcVar12 = pcVar12 + 2;
            }
            if (bVar14) {
              *pcVar12 = '\0';
            }
            pcVar12 = (*g_engfuncs.pfnInfoKeyValue)(local_420,"minplayers");
            if ((pcVar12 != (char *)0x0) && (*pcVar12 != '\0')) {
              iVar6 = strtol(pcVar12,(char **)0x0,10);
              p1Var2 = gpGlobals;
              if (iVar6 < 0) {
                iVar6 = 0;
              }
              pmVar8->minplayers = iVar6;
              if (p1Var2->maxClients <= iVar6) {
                iVar6 = p1Var2->maxClients;
              }
              pmVar8->minplayers = iVar6;
            }
            pcVar12 = (*g_engfuncs.pfnInfoKeyValue)(local_420,"maxplayers");
            if ((pcVar12 != (char *)0x0) && (*pcVar12 != '\0')) {
              iVar6 = strtol(pcVar12,(char **)0x0,10);
              p1Var2 = gpGlobals;
              if (iVar6 < 0) {
                iVar6 = 0;
              }
              pmVar8->maxplayers = iVar6;
              if (p1Var2->maxClients <= iVar6) {
                iVar6 = p1Var2->maxClients;
              }
              pmVar8->maxplayers = iVar6;
            }
            (*g_engfuncs.pfnInfo_RemoveKey)(local_420,"minplayers");
            (*g_engfuncs.pfnInfo_RemoveKey)(local_420,"maxplayers");
            __strcpy_chk(pcVar11,local_420,0x400);
            goto LAB_0009d800;
          }
          goto LAB_0009d8d0;
        }
        iVar6 = (*g_engfuncs.pfnIsMapValid)(local_440);
        if (iVar6 == 0) goto LAB_0009d8d0;
                    /* Unresolved local var: char * s@[???] */
        pmVar8 = operator_new(0x42c);
        __strcpy_chk(pmVar8->mapname,local_440,0x20);
        pcVar11 = pmVar8->rulebuffer;
        uVar7 = 0x400;
        bVar14 = ((uint)pcVar11 & 1) != 0;
        pmVar8->minplayers = 0;
        pmVar8->maxplayers = 0;
        if (bVar14) {
          pmVar8->rulebuffer[0] = '\0';
          pcVar11 = pmVar8->rulebuffer + 1;
          uVar7 = 0x3ff;
        }
        if (((uint)pcVar11 & 2) != 0) {
          pcVar11[0] = '\0';
          pcVar11[1] = '\0';
          uVar7 = uVar7 - 2;
          pcVar11 = pcVar11 + 2;
        }
        uVar9 = 0;
        do {
          pcVar12 = pcVar11 + uVar9;
          pcVar12[0] = '\0';
          pcVar12[1] = '\0';
          pcVar12[2] = '\0';
          pcVar12[3] = '\0';
          pcVar12 = pcVar11 + uVar9 + 4;
          pcVar12[0] = '\0';
          pcVar12[1] = '\0';
          pcVar12[2] = '\0';
          pcVar12[3] = '\0';
          uVar9 = uVar9 + 8;
        } while (uVar9 < (uVar7 & 0xfffffff8));
        pcVar11 = pcVar11 + uVar9;
        if ((uVar7 & 4) != 0) {
          pcVar11[0] = '\0';
          pcVar11[1] = '\0';
          pcVar11[2] = '\0';
          pcVar11[3] = '\0';
          pcVar11 = pcVar11 + 4;
        }
        if ((uVar7 & 2) != 0) {
          pcVar11[0] = '\0';
          pcVar11[1] = '\0';
          pcVar11 = pcVar11 + 2;
        }
        if (bVar14) {
          *pcVar11 = '\0';
        }
      }
LAB_0009d800:
      pmVar10 = cycle->items;
      cycle->items = pmVar8;
      pmVar8->next = pmVar10;
    } while( true );
  }
LAB_0009d62c:
  if (cycle->items == (mapcycle_item_s *)0x0) {
    iVar6 = 0;
  }
  else {
    pmVar8 = cycle->items;
    pmVar10 = (mapcycle_item_s *)0x0;
    do {
      pmVar5 = pmVar8;
      pmVar8 = pmVar5->next;
      pmVar5->next = pmVar10;
      pmVar10 = pmVar5;
    } while (pmVar8 != (mapcycle_item_s *)0x0);
    cycle->items = pmVar5;
    pmVar8 = pmVar5;
    do {
      pmVar10 = pmVar8;
      pmVar8 = pmVar10->next;
    } while (pmVar8 != (mapcycle_item_s *)0x0);
    pmVar10->next = pmVar5;
    cycle->next_item = pmVar5;
    iVar6 = 1;
  }
  if (aiStack_41c[0xff] != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
LAB_0009d8ef:
  (*g_engfuncs.pfnFreeFile)(pbVar4);
  goto LAB_0009d62c;
code_r0x0009d714:
  pbVar13 = pbVar13 + 1;
  bVar3 = *pbVar13;
  if ((bVar3 == '\0') || (bVar3 == '\n')) goto LAB_0009d820;
  goto LAB_0009d728;
}


// CountPlayers  @ 0009db30  (line 1860)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CountPlayers(void)

{
  CBasePlayer *pCVar1;
  int playerIndex;
  int iVar2;
  
                    /* Unresolved local var: int num@[???] */
                    /* Unresolved local var: int i@[???] */
  if (gpGlobals->maxClients < 1) {
    iVar2 = 0;
  }
  else {
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


// ExtractCommandString  @ 0009db80  (line 1885)

void ExtractCommandString(char *s,char *szCommand)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int in_GS_OFFSET;
  char local_410 [512];
  char local_210 [512];
  int local_10;
  
                    /* Unresolved local var: char[512] pkey@[???]
                       Unresolved local var: char[512] value@[???]
                       Unresolved local var: char * o@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  cVar1 = *s;
  if (cVar1 == '\\') {
    cVar1 = s[1];
    s = s + 1;
  }
  do {
    if (cVar1 == '\\') {
      pcVar3 = local_410;
    }
    else {
      if (cVar1 == '\0') {
LAB_0009dc60:
        if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return;
      }
      pcVar5 = local_410;
      while( true ) {
        pcVar3 = pcVar5 + 1;
        s = s + 1;
        *pcVar5 = cVar1;
        cVar1 = *s;
        if (cVar1 == '\\') break;
        pcVar5 = pcVar3;
        if (cVar1 == '\0') goto LAB_0009dc60;
      }
    }
    cVar1 = s[1];
    pcVar5 = s + 1;
    *pcVar3 = '\0';
    pcVar3 = local_210;
    if ((cVar1 != '\0') && (pcVar4 = pcVar3, cVar1 != '\\')) {
      do {
        pcVar3 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
        *pcVar4 = cVar1;
        cVar1 = *pcVar5;
        if (cVar1 == '\\') break;
        pcVar4 = pcVar3;
      } while (cVar1 != '\0');
    }
    *pcVar3 = '\0';
    sVar2 = strlen(szCommand);
    pcVar3 = stpcpy(szCommand + sVar2,local_410);
    if (local_210[0] != '\0') {
      *pcVar3 = ' ';
      strcpy(pcVar3 + 1,local_210);
    }
    sVar2 = strlen(szCommand);
    (szCommand + sVar2)[0] = '\n';
    (szCommand + sVar2)[1] = '\0';
    if (*pcVar5 == '\0') goto LAB_0009dc60;
    s = pcVar5 + 1;
    cVar1 = pcVar5[1];
  } while( true );
}


// CHalfLifeMultiplay::ChangeLevel  @ 0009dcc0  (line 1939)

/* DWARF original prototype: void ChangeLevel(CHalfLifeMultiplay * this) */

void __thiscall CHalfLifeMultiplay::ChangeLevel(CHalfLifeMultiplay *this)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  mapcycle_item_s *pmVar4;
  char *__s1;
  CBasePlayer *pCVar5;
  mapcycle_item_s *pmVar6;
  int iVar7;
  _2globalvars_t *p1Var8;
  uint uVar9;
  int iVar10;
  mapcycle_item_s *pmVar11;
  uint uVar12;
  int in_GS_OFFSET;
  uint local_c24;
  undefined4 *local_c20;
  char local_c18 [32];
  undefined4 local_bf8;
  undefined2 local_bf4;
  char local_bd8 [1500];
  char local_5fc [1500];
  int local_20;
  
                    /* Unresolved local var: char[32] szNextMap@[???]
                       Unresolved local var: char[32] szFirstMapInList@[???]
                       Unresolved local var: char[1500] szCommands@[???]
                       Unresolved local var: char[1500] szRules@[???]
                       Unresolved local var: int minplayers@[???]
                       Unresolved local var: int maxplayers@[???]
                       Unresolved local var: int curplayers@[DW_OP_reg3(EBX)]
                       Unresolved local var: BOOL do_cycle@[???]
                       Unresolved local var: char * mapcfile@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_bf8 = 0x6d646c68;
                    /* Unresolved local var: int num@[???] */
  iVar7 = 0;
  local_bf4 = 0x31;
  __s1 = (*g_engfuncs.pfnCVarGetString)("mapcyclefile");
                    /* Unresolved local var: int i@[???] */
  local_bd8[0] = '\0';
  local_5fc[0] = '\0';
  if (0 < gpGlobals->maxClients) {
    iVar10 = 1;
    do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      pCVar5 = UTIL_PlayerByIndex(iVar10);
      iVar7 = (iVar7 + 1) - (uint)(pCVar5 == (CBasePlayer *)0x0);
      iVar10 = iVar10 + 1;
    } while (iVar10 <= gpGlobals->maxClients);
  }
  p1Var8 = gpGlobals;
  iVar10 = strcasecmp(__s1,ChangeLevel::szPreviousMapCycleFile);
  if (iVar10 == 0) {
    if (ChangeLevel::mapcycle.items == (mapcycle_item_s *)0x0) goto LAB_0009df8f;
LAB_0009dd63:
                    /* Unresolved local var: BOOL keeplooking@[???]
                       Unresolved local var: BOOL found@[???]
                       Unresolved local var: mapcycle_item_s * item@[???] */
    __strcpy_chk(local_c18,p1Var8->pStringBase + p1Var8->mapname,0x20);
    __strcpy_chk(&local_bf8,p1Var8->pStringBase + p1Var8->mapname,0x20);
    local_c24 = 0;
    uVar9 = 0;
    pmVar4 = (ChangeLevel::mapcycle.next_item)->next;
    pmVar11 = ChangeLevel::mapcycle.next_item;
    bVar2 = false;
    while (pmVar6 = pmVar4, uVar12 = local_c24, ChangeLevel::mapcycle.next_item != pmVar6) {
      uVar1 = pmVar11->minplayers;
      if (uVar1 == 0) {
LAB_0009ddea:
        uVar1 = pmVar11->maxplayers;
        if ((uVar1 == 0) || (uVar12 = uVar1, bVar3 = bVar2, iVar7 <= (int)uVar1)) goto LAB_0009de11;
      }
      else {
        if ((int)uVar1 <= iVar7) {
          bVar2 = true;
          uVar9 = uVar1;
          goto LAB_0009ddea;
        }
        uVar12 = pmVar11->maxplayers;
        bVar3 = bVar2;
        if (uVar12 != 0) {
          if (iVar7 <= (int)uVar12) {
            local_c24 = uVar12;
          }
          bVar3 = true;
          if ((int)uVar12 < iVar7) {
            bVar3 = bVar2;
          }
        }
      }
      pmVar11 = pmVar6;
      bVar2 = bVar3;
      pmVar4 = pmVar6->next;
    }
    pmVar6 = ChangeLevel::mapcycle.next_item;
    if (!bVar2) {
      pmVar6 = (ChangeLevel::mapcycle.next_item)->next;
      pmVar11 = ChangeLevel::mapcycle.next_item;
    }
LAB_0009de11:
    local_c24 = uVar12;
    ChangeLevel::mapcycle.next_item = pmVar6;
    __strcpy_chk(local_c18,pmVar11->mapname,0x20);
    ExtractCommandString(pmVar11->rulebuffer,local_bd8);
    __strcpy_chk(local_5fc,pmVar11->rulebuffer,0x5dc);
    iVar10 = (*g_engfuncs.pfnIsMapValid)(local_c18);
    uVar12 = local_c24 | uVar9;
    if (iVar10 == 0) goto LAB_0009e062;
  }
  else {
    __strcpy_chk(ChangeLevel::szPreviousMapCycleFile,__s1,0x100);
    pmVar11 = ChangeLevel::mapcycle.items;
                    /* Unresolved local var: mapcycle_item_t * p@[???]
                       Unresolved local var: mapcycle_item_t * n@[???]
                       Unresolved local var: mapcycle_item_t * start@[???] */
    if (ChangeLevel::mapcycle.items != (mapcycle_item_s *)0x0) {
      pmVar4 = (ChangeLevel::mapcycle.items)->next;
      while (pmVar11 != pmVar4) {
        pmVar6 = pmVar4->next;
        operator_delete(pmVar4);
        pmVar4 = pmVar6;
      }
      operator_delete(ChangeLevel::mapcycle.items);
    }
    ChangeLevel::mapcycle.items = (mapcycle_item_s *)0x0;
    ChangeLevel::mapcycle.next_item = (mapcycle_item_s *)0x0;
    iVar10 = ReloadMapCycleFile(__s1,&ChangeLevel::mapcycle);
    if ((iVar10 != 0) && (p1Var8 = gpGlobals, ChangeLevel::mapcycle.items != (mapcycle_item_s *)0x0)
       ) goto LAB_0009dd63;
    (*g_engfuncs.pfnAlertMessage)(at_console,"Unable to load map cycle file %s\n",__s1);
LAB_0009df8f:
    iVar10 = (*g_engfuncs.pfnIsMapValid)(local_c18);
    if (iVar10 != 0) {
      g_fGameOver = 1;
      (*g_engfuncs.pfnAlertMessage)(at_console,"CHANGE LEVEL: %s\n",local_c18);
      goto joined_r0x0009dfd0;
    }
    uVar12 = 0;
    uVar9 = 0;
    local_c24 = 0;
LAB_0009e062:
    local_c20 = &local_bf8;
    __strcpy_chk(local_c18,local_c20,0x20);
  }
  g_fGameOver = 1;
  (*g_engfuncs.pfnAlertMessage)(at_console,"CHANGE LEVEL: %s\n",local_c18);
  if (uVar12 != 0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"PLAYER COUNT:  min %i max %i current %i\n",uVar9,local_c24,iVar7);
  }
joined_r0x0009dfd0:
  if (local_5fc[0] != '\0') {
    (*g_engfuncs.pfnAlertMessage)(at_console,"RULES:  %s\n",local_5fc);
  }
  (*g_engfuncs.pfnChangeLevel)(local_c18,(char *)0x0);
  if (local_bd8[0] != '\0') {
    (*g_engfuncs.pfnServerCommand)(local_bd8);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CHalfLifeMultiplay::SendMOTDToClient  @ 0009c170  (line 2070)

/* DWARF original prototype: void SendMOTDToClient(CHalfLifeMultiplay * this, edict_t * client) */

void __thiscall CHalfLifeMultiplay::SendMOTDToClient(CHalfLifeMultiplay *this,edict_t *client)

{
  byte bVar1;
  _func_void_char_ptr *p_Var2;
  _func_byte_ptr_char_ptr_int_ptr *p_Var3;
  char *pcVar4;
  byte *pbVar5;
  size_t sVar6;
  byte *__s;
  int iVar7;
  int in_GS_OFFSET;
  int local_64;
  char local_5d [60];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: int length@[???]
                       Unresolved local var: int char_count@[???]
                       Unresolved local var: char * pFileList@[???]
                       Unresolved local var: char * aFileList@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  (*g_engfuncs.pfnMessageBegin)(1,gmsgServerName,(float *)0x0,client);
  p_Var2 = g_engfuncs.pfnWriteString;
  pcVar4 = (*g_engfuncs.pfnCVarGetString)("hostname");
  (*p_Var2)(pcVar4);
  (*g_engfuncs.pfnMessageEnd)();
  p_Var3 = g_engfuncs.pfnLoadFileForMe;
  pcVar4 = (*g_engfuncs.pfnCVarGetString)("motdfile");
  pbVar5 = (*p_Var3)(pcVar4,&local_64);
  if ((pbVar5 != (byte *)0x0) && (*pbVar5 != '\0')) {
    iVar7 = 0;
    __s = pbVar5;
    do {
      sVar6 = strlen((char *)__s);
      if (sVar6 < 0x3c) {
                    /* Unresolved local var: char[61] chunk@[???] */
        __memcpy_chk(local_5d,__s,sVar6 + 1,0x3d);
      }
      else {
        strncpy(local_5d,(char *)__s,0x3c);
        local_21 = 0;
      }
      sVar6 = strlen(local_5d);
      iVar7 = iVar7 + sVar6;
      if (iVar7 < 0x600) {
        __s = pbVar5 + iVar7;
        (*g_engfuncs.pfnMessageBegin)(1,gmsgMOTD,(float *)0x0,client);
        (*g_engfuncs.pfnWriteByte)((uint)(*__s == '\0'));
        (*g_engfuncs.pfnWriteString)(local_5d);
        (*g_engfuncs.pfnMessageEnd)();
        if (__s == (byte *)0x0) break;
        bVar1 = *__s;
      }
      else {
        *__s = '\0';
        (*g_engfuncs.pfnMessageBegin)(1,gmsgMOTD,(float *)0x0,client);
        (*g_engfuncs.pfnWriteByte)((uint)(*__s == '\0'));
        (*g_engfuncs.pfnWriteString)(local_5d);
        (*g_engfuncs.pfnMessageEnd)();
        bVar1 = *__s;
      }
      if ((bVar1 == '\0') || (0x5ff < iVar7)) break;
    } while( true );
  }
  (*g_engfuncs.pfnFreeFile)(pbVar5);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


