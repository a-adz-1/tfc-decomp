// Ghidra decompilation of functions from tfc/items.cpp
// 30 functions, ordered by original source line

// world_items  @ 000e18a0  (line 37)

void world_items(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x478,pev);
  *puVar1 = &PTR__CWorldItem_00183408;
  puVar1[1] = pev;
  return;
}


// CWorldItem::KeyValue  @ 000e1810  (line 40)

/* DWARF original prototype: void KeyValue(CWorldItem * this, KeyValueData * pkvd) */

void __thiscall CWorldItem::KeyValue(CWorldItem *this,KeyValueData *pkvd)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar2 = 5;
  pcVar3 = pkvd->szKeyName;
  pcVar4 = "type";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (!bVar5) {
    CBaseEntity::KeyValue(&this->super_CBaseEntity,pkvd);
    return;
  }
  lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
  this->m_iType = lVar1;
  pkvd->fHandled = 1;
  return;
}


// CWorldItem::Spawn  @ 000e13d0  (line 51)

/* DWARF original prototype: void Spawn(CWorldItem * this) */

void __thiscall CWorldItem::Spawn(CWorldItem *this)

{
  entvars_t *peVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
  iVar2 = this->m_iType;
  if (iVar2 == 0x2b) {
    peVar1 = (this->super_CBaseEntity).pev;
    pCVar3 = CBaseEntity::Create("item_security",&peVar1->origin,&peVar1->angles,(edict_t *)0x0);
LAB_000e145d:
    if (pCVar3 != (CBaseEntity *)0x0) {
      pCVar3->pev->target = ((this->super_CBaseEntity).pev)->target;
      pCVar3->pev->targetname = ((this->super_CBaseEntity).pev)->targetname;
      pCVar3->pev->spawnflags = ((this->super_CBaseEntity).pev)->spawnflags;
      goto LAB_000e1410;
    }
    iVar2 = this->m_iType;
  }
  else {
    if (0x2b < iVar2) {
      if (iVar2 == 0x2c) {
        peVar1 = (this->super_CBaseEntity).pev;
        pCVar3 = CBaseEntity::Create("item_battery",&peVar1->origin,&peVar1->angles,(edict_t *)0x0);
      }
      else {
        if (iVar2 != 0x2d) goto LAB_000e13f2;
        peVar1 = (this->super_CBaseEntity).pev;
        pCVar3 = CBaseEntity::Create("item_suit",&peVar1->origin,&peVar1->angles,(edict_t *)0x0);
      }
      goto LAB_000e145d;
    }
    if (iVar2 == 0x2a) {
      peVar1 = (this->super_CBaseEntity).pev;
      pCVar3 = CBaseEntity::Create("item_antidote",&peVar1->origin,&peVar1->angles,(edict_t *)0x0);
      goto LAB_000e145d;
    }
  }
LAB_000e13f2:
  (*g_engfuncs.pfnAlertMessage)(at_console,"unable to create world_item %d\n",iVar2);
LAB_000e1410:
                    /* WARNING: Could not recover jumptable at 0x000e1426. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnRemoveEntity)(((this->super_CBaseEntity).pev)->pContainingEntity);
  return;
}


// CItem::Spawn  @ 000e1630  (line 85)

/* DWARF original prototype: void Spawn(CItem * this) */

void __thiscall CItem::Spawn(CItem *this)

{
  entvars_t *peVar1;
  CBaseEntity *in_EAX;
  int iVar2;
  Vector local_24;
  Vector local_18;
  
  in_EAX->pev->movetype = 6;
  in_EAX->pev->solid = 1;
  UTIL_SetOrigin(in_EAX->pev,&in_EAX->pev->origin);
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 16.0;
  local_24.x = -16.0;
  local_24.z = 0.0;
  local_24.y = -16.0;
  UTIL_SetSize(in_EAX->pev,&local_24,&local_18);
  (in_EAX->m_pfnTouch).__pfn = ItemTouch;
  (in_EAX->m_pfnTouch).__delta = 0;
  if ((float)in_EAX[1]._vptr_CBaseEntity == 0.0) {
    in_EAX[1]._vptr_CBaseEntity = (_func_int_varargs **)0x41a00000;
  }
  iVar2 = (*g_engfuncs.pfnDropToFloor)(in_EAX->pev->pContainingEntity);
  if (iVar2 == 0) {
    peVar1 = in_EAX->pev;
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"Item %s fell out of level at %f,%f,%f",
               gpGlobals->pStringBase + peVar1->classname,(double)(peVar1->origin).x,
               (double)(peVar1->origin).y,(double)(peVar1->origin).z);
    UTIL_Remove(in_EAX);
  }
  return;
}


// CItem::Spawn  @ 000e1750  (line 86)

/* DWARF original prototype: void Spawn(CItem * this) */

void __thiscall CItem::Spawn(CItem *this)

{
  BOOL BVar1;
  
  BVar1 = CBaseEntity::CheckExistence(&this->super_CBaseEntity);
  if (BVar1 != 0) {
    Spawn(this);
    return;
  }
  UTIL_Remove(&this->super_CBaseEntity);
  return;
}


// CItem::KeyValue  @ 000e1780  (line 111)

/* DWARF original prototype: void KeyValue(CItem * this, KeyValueData * pkvd) */

void __thiscall CItem::KeyValue(CItem *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  double dVar5;
  
  bVar4 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar1 = 0xe;
  pcVar2 = pkvd->szKeyName;
  pcVar3 = "respawn_delay";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (!bVar4) {
    CBaseEntity::KeyValue(&this->super_CBaseEntity,pkvd);
    return;
  }
  dVar5 = strtod(pkvd->szValue,(char **)0x0);
  this->m_flRespawnTime = (float)dVar5;
  pkvd->fHandled = 1;
  return;
}


// CItem::ItemTouch  @ 000e1530  (line 124)

/* DWARF original prototype: void ItemTouch(CItem * this, CBaseEntity * pOther) */

void __thiscall CItem::ItemTouch(CItem *this,CBaseEntity *pOther)

{
  CGameRules *pCVar1;
  int iVar2;
  
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
  if (((pOther->pev->flags & 8) != 0) &&
     (iVar2 = (*g_pGameRules->_vptr_CGameRules[0x23])(g_pGameRules,pOther,this), iVar2 != 0)) {
    iVar2 = (*(this->super_CBaseEntity)._vptr_CBaseEntity[0x41])(this,pOther);
    if (iVar2 == 0) {
      if (gEvilImpulse101 == 0) {
        return;
      }
    }
    else {
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
      CBaseEntity::SUB_UseTargets(&this->super_CBaseEntity,pOther,USE_TOGGLE,0.0);
      pCVar1 = g_pGameRules;
      (this->super_CBaseEntity).m_pfnTouch.__pfn =
           (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
      (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
      (*pCVar1->_vptr_CGameRules[0x24])(pCVar1,pOther,this);
      iVar2 = (*g_pGameRules->_vptr_CGameRules[0x25])(g_pGameRules,this);
      if (iVar2 == 5) {
                    /* WARNING: Could not recover jumptable at 0x000e1623. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(this->super_CBaseEntity)._vptr_CBaseEntity[0x2f])();
        return;
      }
    }
    UTIL_Remove(&this->super_CBaseEntity);
    return;
  }
  return;
}


// CItem::Respawn  @ 000e1340  (line 161)

/* DWARF original prototype: CBaseEntity * Respawn(CItem * this) */

CBaseEntity * __thiscall CItem::Respawn(CItem *this)

{
  int *piVar1;
  entvars_t *peVar2;
  CGameRules *pCVar3;
  longdouble extraout_ST0;
  Vector local_18;
  
  peVar2 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnTouch.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
  piVar1 = &peVar2->effects;
  *piVar1 = *piVar1 | 0x80;
  (*g_pGameRules->_vptr_CGameRules[0x27])(&local_18,g_pGameRules,this);
  UTIL_SetOrigin((this->super_CBaseEntity).pev,&local_18);
  pCVar3 = g_pGameRules;
  (this->super_CBaseEntity).m_pfnThink.__pfn = Materialize;
  peVar2 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  (*pCVar3->_vptr_CGameRules[0x26])(pCVar3,this);
  peVar2->nextthink = (float)extraout_ST0;
  return &this->super_CBaseEntity;
}


// CItem::Materialize  @ 000e1290  (line 173)

/* DWARF original prototype: void Materialize(CItem * this) */

void __thiscall CItem::Materialize(CItem *this)

{
  int *piVar1;
  entvars_t *peVar2;
  
  peVar2 = (this->super_CBaseEntity).pev;
  if ((peVar2->effects & 0x80) == 0) {
    EMIT_SOUND_DYN(peVar2->pContainingEntity,1,"items/itembk2.wav",1.0,0.8,0,0x96);
  }
  else {
    EMIT_SOUND_DYN(peVar2->pContainingEntity,1,"items/suitchargeok1.wav",1.0,0.8,0,0x96);
    piVar1 = &((this->super_CBaseEntity).pev)->effects;
    *piVar1 = *piVar1 & 0xffffff7f;
    piVar1 = &((this->super_CBaseEntity).pev)->effects;
    *piVar1 = *piVar1 | 2;
  }
  (this->super_CBaseEntity).m_pfnTouch.__pfn = ItemTouch;
  (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
  return;
}


// CItem::TeamFortress_EMPRemove  @ 000e1280  (line 190)

/* DWARF original prototype: void TeamFortress_EMPRemove(CItem * this) */

void __thiscall CItem::TeamFortress_EMPRemove(CItem *this)

{
                    /* WARNING: Could not recover jumptable at 0x000e128c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseEntity)._vptr_CBaseEntity[0x2f])();
  return;
}


// CItemSuit::Spawn  @ 000e2130  (line 198)

/* DWARF original prototype: void Spawn(CItemSuit * this) */

void __thiscall CItemSuit::Spawn(CItemSuit *this)

{
  BOOL BVar1;
  
  (*(this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[3])(this);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity,"models/w_suit.mdl");
  BVar1 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar1 != 0) {
    CItem::Spawn(&this->super_CItem);
    return;
  }
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CItemSuit::Precache  @ 000e1b50  (line 206)

/* DWARF original prototype: void Precache(CItemSuit * this) */

void __thiscall CItemSuit::Precache(CItemSuit *this)

{
                    /* WARNING: Could not recover jumptable at 0x000e1b5e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_suit.mdl");
  return;
}


// CItemSuit::MyTouch  @ 000e1cb0  (line 208)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL MyTouch(CItemSuit * this, CBasePlayer * pPlayer) */

BOOL __thiscall CItemSuit::MyTouch(CItemSuit *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  entvars_t *peVar2;
  BOOL BVar3;
  
  BVar3 = 0;
  peVar2 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (-1 < peVar2->weapons) {
    if ((((this->super_CItem).super_CBaseEntity.pev)->spawnflags & 1) == 0) {
      EMIT_SOUND_SUIT(peVar2->pContainingEntity,"!HEV_AAx");
    }
    else {
      EMIT_SOUND_SUIT(peVar2->pContainingEntity,"!HEV_A0");
    }
    piVar1 = &((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.pev)->weapons;
    *piVar1 = *piVar1 | 0x80000000;
    BVar3 = 1;
  }
  return BVar3;
}


// item_suit  @ 000e1910  (line 223)

void item_suit(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x478,pev);
  *puVar1 = &PTR__CItemSuit_00183648;
  puVar1[1] = pev;
  return;
}


// CItemBattery::Spawn  @ 000e1fb0  (line 229)

/* DWARF original prototype: void Spawn(CItemBattery * this) */

void __thiscall CItemBattery::Spawn(CItemBattery *this)

{
  BOOL BVar1;
  
  (*(this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[3])(this);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity,"models/w_battery.mdl");
  BVar1 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar1 != 0) {
    CItem::Spawn(&this->super_CItem);
    return;
  }
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CItemBattery::Precache  @ 000e1b60  (line 235)

/* DWARF original prototype: void Precache(CItemBattery * this) */

void __thiscall CItemBattery::Precache(CItemBattery *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/w_battery.mdl");
                    /* WARNING: Could not recover jumptable at 0x000e1b81. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/gunpickup2.wav");
  return;
}


// CItemBattery::MyTouch  @ 000e1e20  (line 240)

/* DWARF original prototype: BOOL MyTouch(CItemBattery * this, CBasePlayer * pPlayer) */

BOOL __thiscall CItemBattery::MyTouch(CItemBattery *this,CBasePlayer *pPlayer)

{
  float fVar1;
  entvars_t *peVar2;
  int iVar3;
  char local_4c [68];
  
  peVar2 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar2->armorvalue < 100.0) && (peVar2->weapons < 0)) {
                    /* Unresolved local var: int pct@[???]
                       Unresolved local var: char[64] szcharge@[???] */
    peVar2->armorvalue = peVar2->armorvalue + gSkillData.batteryCapacity;
    peVar2 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar1 = peVar2->armorvalue;
    if (100.0 <= fVar1) {
      fVar1 = 100.0;
    }
    peVar2->armorvalue = fVar1;
    EMIT_SOUND_DYN(((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                   "items/gunpickup2.wav",1.0,0.8,0,100);
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgItemPickup,(float *)0x0,
               ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteString)
              (gpGlobals->pStringBase + ((this->super_CItem).super_CBaseEntity.pev)->classname);
    (*g_engfuncs.pfnMessageEnd)();
    iVar3 = (int)(((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev)->armorvalue * 100.0 * 0.01 + 0.5) / 5;
    sprintf(local_4c,"!HEV_%1dP",iVar3 - (uint)(0 < iVar3));
    CBasePlayer::SetSuitUpdate(pPlayer,local_4c,0,0x1e);
    return 1;
  }
  return 0;
}


// item_battery  @ 000e1980  (line 275)

void item_battery(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x478,pev);
  *puVar1 = &PTR__CItemBattery_00183768;
  puVar1[1] = pev;
  return;
}


// CItemAntidote::Spawn  @ 000e20d0  (line 280)

/* DWARF original prototype: void Spawn(CItemAntidote * this) */

void __thiscall CItemAntidote::Spawn(CItemAntidote *this)

{
  BOOL BVar1;
  
  (*(this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[3])(this);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity,"models/w_antidote.mdl")
  ;
  BVar1 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar1 != 0) {
    CItem::Spawn(&this->super_CItem);
    return;
  }
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CItemAntidote::Precache  @ 000e1b90  (line 288)

/* DWARF original prototype: void Precache(CItemAntidote * this) */

void __thiscall CItemAntidote::Precache(CItemAntidote *this)

{
                    /* WARNING: Could not recover jumptable at 0x000e1b9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_antidote.mdl");
  return;
}


// CItemAntidote::MyTouch  @ 000e1d30  (line 290)

/* DWARF original prototype: BOOL MyTouch(CItemAntidote * this, CBasePlayer * pPlayer) */

BOOL __thiscall CItemAntidote::MyTouch(CItemAntidote *this,CBasePlayer *pPlayer)

{
  CBasePlayer::SetSuitUpdate(pPlayer,"!HEV_DET4",0,0x3c);
  pPlayer->m_rgItems[2] = pPlayer->m_rgItems[2] + 1;
  return 1;
}


// item_antidote  @ 000e19f0  (line 299)

void item_antidote(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x478,pev);
  *puVar1 = &PTR__CItemAntidote_00183888;
  puVar1[1] = pev;
  return;
}


// CItemSecurity::Spawn  @ 000e2070  (line 304)

/* DWARF original prototype: void Spawn(CItemSecurity * this) */

void __thiscall CItemSecurity::Spawn(CItemSecurity *this)

{
  BOOL BVar1;
  
  (*(this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[3])(this);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity,"models/w_security.mdl")
  ;
  BVar1 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar1 != 0) {
    CItem::Spawn(&this->super_CItem);
    return;
  }
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CItemSecurity::Precache  @ 000e1ba0  (line 312)

/* DWARF original prototype: void Precache(CItemSecurity * this) */

void __thiscall CItemSecurity::Precache(CItemSecurity *this)

{
                    /* WARNING: Could not recover jumptable at 0x000e1bae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_security.mdl");
  return;
}


// CItemSecurity::MyTouch  @ 000e1bb0  (line 314)

/* DWARF original prototype: BOOL MyTouch(CItemSecurity * this, CBasePlayer * pPlayer) */

BOOL __thiscall CItemSecurity::MyTouch(CItemSecurity *this,CBasePlayer *pPlayer)

{
  pPlayer->m_rgItems[3] = pPlayer->m_rgItems[3] + 1;
  return 1;
}


// item_security  @ 000e1a60  (line 321)

void item_security(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x478,pev);
  *puVar1 = &PTR__CItemSecurity_001839a8;
  puVar1[1] = pev;
  return;
}


// CItemLongJump::Spawn  @ 000e2010  (line 325)

/* DWARF original prototype: void Spawn(CItemLongJump * this) */

void __thiscall CItemLongJump::Spawn(CItemLongJump *this)

{
  BOOL BVar1;
  
  (*(this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[3])(this);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity,"models/w_longjump.mdl")
  ;
  BVar1 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar1 != 0) {
    CItem::Spawn(&this->super_CItem);
    return;
  }
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CItemLongJump::Precache  @ 000e1bc0  (line 333)

/* DWARF original prototype: void Precache(CItemLongJump * this) */

void __thiscall CItemLongJump::Precache(CItemLongJump *this)

{
                    /* WARNING: Could not recover jumptable at 0x000e1bce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_longjump.mdl");
  return;
}


// CItemLongJump::MyTouch  @ 000e1d70  (line 335)

/* DWARF original prototype: BOOL MyTouch(CItemLongJump * this, CBasePlayer * pPlayer) */

BOOL __thiscall CItemLongJump::MyTouch(CItemLongJump *this,CBasePlayer *pPlayer)

{
  entvars_t *peVar1;
  
  if ((pPlayer->m_fLongJump == 0) &&
     (peVar1 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.pev, peVar1->weapons < 0)) {
    pPlayer->m_fLongJump = 1;
    (*g_engfuncs.pfnMessageBegin)(1,gmsgItemPickup,(float *)0x0,peVar1->pContainingEntity);
    (*g_engfuncs.pfnWriteString)
              (gpGlobals->pStringBase + ((this->super_CItem).super_CBaseEntity.pev)->classname);
    (*g_engfuncs.pfnMessageEnd)();
    EMIT_SOUND_SUIT(((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"!HEV_A1");
    return 1;
  }
  return 0;
}


// item_longjump  @ 000e1ad0  (line 357)

void item_longjump(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x478,pev);
  *puVar1 = &PTR__CItemLongJump_00183ac8;
  puVar1[1] = pev;
  return;
}


