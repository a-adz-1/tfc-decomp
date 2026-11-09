// Ghidra decompilation of functions from tfc/items.cpp
// 35 functions, ordered by original source line

// CWorldItem::~CWorldItem  @ 000a5570  (line 29)

/* DWARF original prototype: void ~CWorldItem(CWorldItem * this, int __in_chrg) */

void __thiscall CWorldItem::~CWorldItem(CWorldItem *this,int __in_chrg)

{
  return;
}


// world_items  @ 000a51e0  (line 37)

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
  *puVar1 = &PTR__CWorldItem_0015266c;
  puVar1[1] = pev;
  return;
}


// CWorldItem::KeyValue  @ 000a4ea0  (line 40)

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


// CWorldItem::Spawn  @ 000a4ad0  (line 51)

/* DWARF original prototype: void Spawn(CWorldItem * this) */

void __thiscall CWorldItem::Spawn(CWorldItem *this)

{
  entvars_t *peVar1;
  CBaseEntity *pCVar2;
  int iVar3;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
  iVar3 = this->m_iType;
  if (iVar3 == 0x2b) {
    peVar1 = (this->super_CBaseEntity).pev;
    pCVar2 = CBaseEntity::Create("item_security",&peVar1->origin,&peVar1->angles,(edict_t *)0x0);
LAB_000a4b22:
    if (pCVar2 != (CBaseEntity *)0x0) {
      pCVar2->pev->target = ((this->super_CBaseEntity).pev)->target;
      pCVar2->pev->targetname = ((this->super_CBaseEntity).pev)->targetname;
      pCVar2->pev->spawnflags = ((this->super_CBaseEntity).pev)->spawnflags;
      goto LAB_000a4b60;
    }
    iVar3 = this->m_iType;
  }
  else {
    if (0x2b < iVar3) {
      if (iVar3 == 0x2c) {
        peVar1 = (this->super_CBaseEntity).pev;
        pCVar2 = CBaseEntity::Create("item_battery",&peVar1->origin,&peVar1->angles,(edict_t *)0x0);
      }
      else {
        if (iVar3 != 0x2d) goto LAB_000a4c10;
        peVar1 = (this->super_CBaseEntity).pev;
        pCVar2 = CBaseEntity::Create("item_suit",&peVar1->origin,&peVar1->angles,(edict_t *)0x0);
      }
      goto LAB_000a4b22;
    }
    if (iVar3 == 0x2a) {
      peVar1 = (this->super_CBaseEntity).pev;
      pCVar2 = CBaseEntity::Create("item_antidote",&peVar1->origin,&peVar1->angles,(edict_t *)0x0);
      goto LAB_000a4b22;
    }
  }
LAB_000a4c10:
  (*g_engfuncs.pfnAlertMessage)(at_console,"unable to create world_item %d\n",iVar3);
LAB_000a4b60:
                    /* WARNING: Could not recover jumptable at 0x000a4b71. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnRemoveEntity)(((this->super_CBaseEntity).pev)->pContainingEntity);
  return;
}


// CItem::Spawn  @ 000a4cc0  (line 86)

/* DWARF original prototype: void Spawn(CItem * this) */

void __thiscall CItem::Spawn(CItem *this)

{
  entvars_t *peVar1;
  BOOL BVar2;
  int iVar3;
  Vector local_24;
  Vector local_18;
  
  BVar2 = CBaseEntity::CheckExistence(&this->super_CBaseEntity);
  if (BVar2 != 0) {
    ((this->super_CBaseEntity).pev)->movetype = 6;
    ((this->super_CBaseEntity).pev)->solid = 1;
    peVar1 = (this->super_CBaseEntity).pev;
    UTIL_SetOrigin(peVar1,&peVar1->origin);
    local_18.x = 16.0;
    local_18.y = 16.0;
    local_18.z = 16.0;
    local_24.x = -16.0;
    local_24.y = -16.0;
    local_24.z = 0.0;
    UTIL_SetSize((this->super_CBaseEntity).pev,&local_24,&local_18);
    (this->super_CBaseEntity).m_pfnTouch.__pfn = ItemTouch;
    (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
    if (this->m_flRespawnTime == 0.0) {
      this->m_flRespawnTime = 20.0;
    }
    iVar3 = (*g_engfuncs.pfnDropToFloor)(((this->super_CBaseEntity).pev)->pContainingEntity);
    if (iVar3 != 0) {
      return;
    }
    peVar1 = (this->super_CBaseEntity).pev;
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"Item %s fell out of level at %f,%f,%f",
               gpGlobals->pStringBase + peVar1->classname,(double)(peVar1->origin).x,
               (double)(peVar1->origin).y,(double)(peVar1->origin).z);
  }
  UTIL_Remove(&this->super_CBaseEntity);
  return;
}


// CItem::KeyValue  @ 000a4f30  (line 111)

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


// CItem::ItemTouch  @ 000a5070  (line 124)

/* DWARF original prototype: void ItemTouch(CItem * this, CBaseEntity * pOther) */

void __thiscall CItem::ItemTouch(CItem *this,CBaseEntity *pOther)

{
  int *piVar1;
  _func_int_varargs *p_Var2;
  entvars_t *peVar3;
  CGameRules *pCVar4;
  int iVar5;
  longdouble extraout_ST0;
  Vector local_18;
  
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
  if (((pOther->pev->flags & 8) != 0) &&
     (iVar5 = (*g_pGameRules->_vptr_CGameRules[0x23])(g_pGameRules,pOther,this), iVar5 != 0)) {
    iVar5 = (*(this->super_CBaseEntity)._vptr_CBaseEntity[0x41])(this,pOther);
    if (iVar5 == 0) {
      if (gEvilImpulse101 == 0) {
        return;
      }
    }
    else {
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
      CBaseEntity::SUB_UseTargets(&this->super_CBaseEntity,pOther,USE_TOGGLE,0.0);
      pCVar4 = g_pGameRules;
      (this->super_CBaseEntity).m_pfnTouch.__pfn =
           (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
      (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
      (*pCVar4->_vptr_CGameRules[0x24])(pCVar4,pOther,this);
      iVar5 = (*g_pGameRules->_vptr_CGameRules[0x25])(g_pGameRules,this);
      if (iVar5 == 5) {
        p_Var2 = (this->super_CBaseEntity)._vptr_CBaseEntity[0x2f];
        if (p_Var2 == Respawn) {
          peVar3 = (this->super_CBaseEntity).pev;
          (this->super_CBaseEntity).m_pfnTouch.__pfn =
               (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
          (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
          piVar1 = &peVar3->effects;
          *piVar1 = *piVar1 | 0x80;
          (*g_pGameRules->_vptr_CGameRules[0x27])(&local_18,g_pGameRules,this);
          UTIL_SetOrigin((this->super_CBaseEntity).pev,&local_18);
          pCVar4 = g_pGameRules;
          (this->super_CBaseEntity).m_pfnThink.__pfn = Materialize;
          peVar3 = (this->super_CBaseEntity).pev;
          (this->super_CBaseEntity).m_pfnThink.__delta = 0;
          (*pCVar4->_vptr_CGameRules[0x26])(pCVar4,this);
          peVar3->nextthink = (float)extraout_ST0;
          return;
        }
        (*p_Var2)(this);
        return;
      }
    }
    UTIL_Remove(&this->super_CBaseEntity);
  }
  return;
}


// CItem::Respawn  @ 000a4c30  (line 161)

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


// CItem::Materialize  @ 000a4df0  (line 173)

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


// CItem::TeamFortress_EMPRemove  @ 000a4fc0  (line 190)

/* DWARF original prototype: void TeamFortress_EMPRemove(CItem * this) */

void __thiscall CItem::TeamFortress_EMPRemove(CItem *this)

{
  int *piVar1;
  _func_int_varargs *p_Var2;
  entvars_t *peVar3;
  CGameRules *pCVar4;
  longdouble extraout_ST0;
  Vector local_18;
  
  p_Var2 = (this->super_CBaseEntity)._vptr_CBaseEntity[0x2f];
  if (p_Var2 == Respawn) {
    peVar3 = (this->super_CBaseEntity).pev;
    (this->super_CBaseEntity).m_pfnTouch.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
    (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
    piVar1 = &peVar3->effects;
    *piVar1 = *piVar1 | 0x80;
    (*g_pGameRules->_vptr_CGameRules[0x27])(&local_18,g_pGameRules,this);
    UTIL_SetOrigin((this->super_CBaseEntity).pev,&local_18);
    pCVar4 = g_pGameRules;
    (this->super_CBaseEntity).m_pfnThink.__pfn = Materialize;
    peVar3 = (this->super_CBaseEntity).pev;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    (*pCVar4->_vptr_CGameRules[0x26])(pCVar4,this);
    peVar3->nextthink = (float)extraout_ST0;
    return;
  }
  (*p_Var2)(this);
  return;
}


// CItemSuit::~CItemSuit  @ 000a5560  (line 196)

/* DWARF original prototype: void ~CItemSuit(CItemSuit * this, int __in_chrg) */

void __thiscall CItemSuit::~CItemSuit(CItemSuit *this,int __in_chrg)

{
  return;
}


// CItemSuit::Spawn  @ 000a5d10  (line 198)

/* DWARF original prototype: void Spawn(CItemSuit * this) */

void __thiscall CItemSuit::Spawn(CItemSuit *this)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  BOOL BVar3;
  int iVar4;
  Vector local_24;
  Vector local_18;
  
  p_Var1 = (this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/w_suit.mdl");
  }
  else {
    (*p_Var1)(this);
  }
  (*g_engfuncs.pfnSetModel)
            (((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity,"models/w_suit.mdl");
  BVar3 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar3 != 0) {
    ((this->super_CItem).super_CBaseEntity.pev)->movetype = 6;
    ((this->super_CItem).super_CBaseEntity.pev)->solid = 1;
    peVar2 = (this->super_CItem).super_CBaseEntity.pev;
    UTIL_SetOrigin(peVar2,&peVar2->origin);
    local_24.x = 16.0;
    local_24.y = 16.0;
    local_24.z = 16.0;
    local_18.x = -16.0;
    local_18.y = -16.0;
    local_18.z = 0.0;
    UTIL_SetSize((this->super_CItem).super_CBaseEntity.pev,&local_18,&local_24);
    (this->super_CItem).super_CBaseEntity.m_pfnTouch.__pfn = CItem::ItemTouch;
    (this->super_CItem).super_CBaseEntity.m_pfnTouch.__delta = 0;
    if ((this->super_CItem).m_flRespawnTime == 0.0) {
      (this->super_CItem).m_flRespawnTime = 20.0;
    }
    iVar4 = (*g_engfuncs.pfnDropToFloor)
                      (((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity);
    if (iVar4 != 0) {
      return;
    }
    peVar2 = (this->super_CItem).super_CBaseEntity.pev;
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"Item %s fell out of level at %f,%f,%f",
               gpGlobals->pStringBase + peVar2->classname,(double)(peVar2->origin).x,
               (double)(peVar2->origin).y,(double)(peVar2->origin).z);
  }
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CItemSuit::Precache  @ 000a5490  (line 206)

/* DWARF original prototype: void Precache(CItemSuit * this) */

void __thiscall CItemSuit::Precache(CItemSuit *this)

{
                    /* WARNING: Could not recover jumptable at 0x000a5499. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_suit.mdl");
  return;
}


// CItemSuit::MyTouch  @ 000a5580  (line 208)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL MyTouch(CItemSuit * this, CBasePlayer * pPlayer) */

BOOL __thiscall CItemSuit::MyTouch(CItemSuit *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  entvars_t *peVar2;
  
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
    return 1;
  }
  return 0;
}


// item_suit  @ 000a5250  (line 223)

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
  *puVar1 = &PTR__CItemSuit_00152888;
  puVar1[1] = pev;
  return;
}


// CItemBattery::~CItemBattery  @ 000a5550  (line 227)

/* DWARF original prototype: void ~CItemBattery(CItemBattery * this, int __in_chrg) */

void __thiscall CItemBattery::~CItemBattery(CItemBattery *this,int __in_chrg)

{
  return;
}


// CItemBattery::Spawn  @ 000a58b0  (line 229)

/* DWARF original prototype: void Spawn(CItemBattery * this) */

void __thiscall CItemBattery::Spawn(CItemBattery *this)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  BOOL BVar3;
  int iVar4;
  Vector local_24;
  Vector local_18;
  
  p_Var1 = (this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/w_battery.mdl");
    (*g_engfuncs.pfnPrecacheSound)("items/gunpickup2.wav");
  }
  else {
    (*p_Var1)(this);
  }
  (*g_engfuncs.pfnSetModel)
            (((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity,"models/w_battery.mdl");
  BVar3 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar3 != 0) {
    ((this->super_CItem).super_CBaseEntity.pev)->movetype = 6;
    ((this->super_CItem).super_CBaseEntity.pev)->solid = 1;
    peVar2 = (this->super_CItem).super_CBaseEntity.pev;
    UTIL_SetOrigin(peVar2,&peVar2->origin);
    local_24.x = 16.0;
    local_24.y = 16.0;
    local_24.z = 16.0;
    local_18.x = -16.0;
    local_18.y = -16.0;
    local_18.z = 0.0;
    UTIL_SetSize((this->super_CItem).super_CBaseEntity.pev,&local_18,&local_24);
    (this->super_CItem).super_CBaseEntity.m_pfnTouch.__pfn = CItem::ItemTouch;
    (this->super_CItem).super_CBaseEntity.m_pfnTouch.__delta = 0;
    if ((this->super_CItem).m_flRespawnTime == 0.0) {
      (this->super_CItem).m_flRespawnTime = 20.0;
    }
    iVar4 = (*g_engfuncs.pfnDropToFloor)
                      (((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity);
    if (iVar4 != 0) {
      return;
    }
    peVar2 = (this->super_CItem).super_CBaseEntity.pev;
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"Item %s fell out of level at %f,%f,%f",
               gpGlobals->pStringBase + peVar2->classname,(double)(peVar2->origin).x,
               (double)(peVar2->origin).y,(double)(peVar2->origin).z);
  }
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CItemBattery::Precache  @ 000a54a0  (line 235)

/* DWARF original prototype: void Precache(CItemBattery * this) */

void __thiscall CItemBattery::Precache(CItemBattery *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/w_battery.mdl");
                    /* WARNING: Could not recover jumptable at 0x000a54bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/gunpickup2.wav");
  return;
}


// CItemBattery::MyTouch  @ 000a5640  (line 240)

/* DWARF original prototype: BOOL MyTouch(CItemBattery * this, CBasePlayer * pPlayer) */

BOOL __thiscall CItemBattery::MyTouch(CItemBattery *this,CBasePlayer *pPlayer)

{
  float fVar1;
  entvars_t *peVar2;
  int iVar3;
  BOOL BVar4;
  int in_GS_OFFSET;
  char local_50 [64];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  BVar4 = 0;
  peVar2 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (100.0 <= peVar2->armorvalue) {
    BVar4 = 0;
  }
  else if (peVar2->weapons < 0) {
                    /* Unresolved local var: int pct@[???]
                       Unresolved local var: char[64] szcharge@[???] */
    peVar2->armorvalue = peVar2->armorvalue + gSkillData.batteryCapacity;
    peVar2 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar1 = peVar2->armorvalue;
    if (100.0 < fVar1) {
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
    __sprintf_chk(local_50,1,0x40,"!HEV_%1dP",iVar3 - (uint)(0 < iVar3));
    CBasePlayer::SetSuitUpdate(pPlayer,local_50,0,0x1e);
    BVar4 = 1;
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return BVar4;
}


// item_battery  @ 000a52c0  (line 275)

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
  *puVar1 = &PTR__CItemBattery_00152998;
  puVar1[1] = pev;
  return;
}


// CItemAntidote::~CItemAntidote  @ 000a5540  (line 278)

/* DWARF original prototype: void ~CItemAntidote(CItemAntidote * this, int __in_chrg) */

void __thiscall CItemAntidote::~CItemAntidote(CItemAntidote *this,int __in_chrg)

{
  return;
}


// CItemAntidote::Spawn  @ 000a5a30  (line 280)

/* DWARF original prototype: void Spawn(CItemAntidote * this) */

void __thiscall CItemAntidote::Spawn(CItemAntidote *this)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  BOOL BVar3;
  int iVar4;
  Vector local_24;
  Vector local_18;
  
  p_Var1 = (this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/w_antidote.mdl");
  }
  else {
    (*p_Var1)(this);
  }
  (*g_engfuncs.pfnSetModel)
            (((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity,"models/w_antidote.mdl")
  ;
  BVar3 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar3 != 0) {
    ((this->super_CItem).super_CBaseEntity.pev)->movetype = 6;
    ((this->super_CItem).super_CBaseEntity.pev)->solid = 1;
    peVar2 = (this->super_CItem).super_CBaseEntity.pev;
    UTIL_SetOrigin(peVar2,&peVar2->origin);
    local_24.x = 16.0;
    local_24.y = 16.0;
    local_24.z = 16.0;
    local_18.x = -16.0;
    local_18.y = -16.0;
    local_18.z = 0.0;
    UTIL_SetSize((this->super_CItem).super_CBaseEntity.pev,&local_18,&local_24);
    (this->super_CItem).super_CBaseEntity.m_pfnTouch.__pfn = CItem::ItemTouch;
    (this->super_CItem).super_CBaseEntity.m_pfnTouch.__delta = 0;
    if ((this->super_CItem).m_flRespawnTime == 0.0) {
      (this->super_CItem).m_flRespawnTime = 20.0;
    }
    iVar4 = (*g_engfuncs.pfnDropToFloor)
                      (((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity);
    if (iVar4 != 0) {
      return;
    }
    peVar2 = (this->super_CItem).super_CBaseEntity.pev;
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"Item %s fell out of level at %f,%f,%f",
               gpGlobals->pStringBase + peVar2->classname,(double)(peVar2->origin).x,
               (double)(peVar2->origin).y,(double)(peVar2->origin).z);
  }
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CItemAntidote::Precache  @ 000a54d0  (line 288)

/* DWARF original prototype: void Precache(CItemAntidote * this) */

void __thiscall CItemAntidote::Precache(CItemAntidote *this)

{
                    /* WARNING: Could not recover jumptable at 0x000a54d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_antidote.mdl");
  return;
}


// CItemAntidote::MyTouch  @ 000a5600  (line 290)

/* DWARF original prototype: BOOL MyTouch(CItemAntidote * this, CBasePlayer * pPlayer) */

BOOL __thiscall CItemAntidote::MyTouch(CItemAntidote *this,CBasePlayer *pPlayer)

{
  CBasePlayer::SetSuitUpdate(pPlayer,"!HEV_DET4",0,0x3c);
  pPlayer->m_rgItems[2] = pPlayer->m_rgItems[2] + 1;
  return 1;
}


// item_antidote  @ 000a5330  (line 299)

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
  *puVar1 = &PTR__CItemAntidote_00152aa8;
  puVar1[1] = pev;
  return;
}


// CItemSecurity::~CItemSecurity  @ 000a5530  (line 302)

/* DWARF original prototype: void ~CItemSecurity(CItemSecurity * this, int __in_chrg) */

void __thiscall CItemSecurity::~CItemSecurity(CItemSecurity *this,int __in_chrg)

{
  return;
}


// CItemSecurity::Spawn  @ 000a5ba0  (line 304)

/* DWARF original prototype: void Spawn(CItemSecurity * this) */

void __thiscall CItemSecurity::Spawn(CItemSecurity *this)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  BOOL BVar3;
  int iVar4;
  Vector local_24;
  Vector local_18;
  
  p_Var1 = (this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/w_security.mdl");
  }
  else {
    (*p_Var1)(this);
  }
  (*g_engfuncs.pfnSetModel)
            (((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity,"models/w_security.mdl")
  ;
  BVar3 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar3 != 0) {
    ((this->super_CItem).super_CBaseEntity.pev)->movetype = 6;
    ((this->super_CItem).super_CBaseEntity.pev)->solid = 1;
    peVar2 = (this->super_CItem).super_CBaseEntity.pev;
    UTIL_SetOrigin(peVar2,&peVar2->origin);
    local_24.x = 16.0;
    local_24.y = 16.0;
    local_24.z = 16.0;
    local_18.x = -16.0;
    local_18.y = -16.0;
    local_18.z = 0.0;
    UTIL_SetSize((this->super_CItem).super_CBaseEntity.pev,&local_18,&local_24);
    (this->super_CItem).super_CBaseEntity.m_pfnTouch.__pfn = CItem::ItemTouch;
    (this->super_CItem).super_CBaseEntity.m_pfnTouch.__delta = 0;
    if ((this->super_CItem).m_flRespawnTime == 0.0) {
      (this->super_CItem).m_flRespawnTime = 20.0;
    }
    iVar4 = (*g_engfuncs.pfnDropToFloor)
                      (((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity);
    if (iVar4 != 0) {
      return;
    }
    peVar2 = (this->super_CItem).super_CBaseEntity.pev;
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"Item %s fell out of level at %f,%f,%f",
               gpGlobals->pStringBase + peVar2->classname,(double)(peVar2->origin).x,
               (double)(peVar2->origin).y,(double)(peVar2->origin).z);
  }
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CItemSecurity::Precache  @ 000a54e0  (line 312)

/* DWARF original prototype: void Precache(CItemSecurity * this) */

void __thiscall CItemSecurity::Precache(CItemSecurity *this)

{
                    /* WARNING: Could not recover jumptable at 0x000a54e9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_security.mdl");
  return;
}


// CItemSecurity::MyTouch  @ 000a54f0  (line 314)

/* DWARF original prototype: BOOL MyTouch(CItemSecurity * this, CBasePlayer * pPlayer) */

BOOL __thiscall CItemSecurity::MyTouch(CItemSecurity *this,CBasePlayer *pPlayer)

{
  pPlayer->m_rgItems[3] = pPlayer->m_rgItems[3] + 1;
  return 1;
}


// item_security  @ 000a53a0  (line 321)

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
  *puVar1 = &PTR__CItemSecurity_00152bb8;
  puVar1[1] = pev;
  return;
}


// CItemLongJump::~CItemLongJump  @ 000a5520  (line 323)

/* DWARF original prototype: void ~CItemLongJump(CItemLongJump * this, int __in_chrg) */

void __thiscall CItemLongJump::~CItemLongJump(CItemLongJump *this,int __in_chrg)

{
  return;
}


// CItemLongJump::Spawn  @ 000a5e80  (line 325)

/* DWARF original prototype: void Spawn(CItemLongJump * this) */

void __thiscall CItemLongJump::Spawn(CItemLongJump *this)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  BOOL BVar3;
  int iVar4;
  Vector local_24;
  Vector local_18;
  
  p_Var1 = (this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/w_longjump.mdl");
  }
  else {
    (*p_Var1)(this);
  }
  (*g_engfuncs.pfnSetModel)
            (((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity,"models/w_longjump.mdl")
  ;
  BVar3 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar3 != 0) {
    ((this->super_CItem).super_CBaseEntity.pev)->movetype = 6;
    ((this->super_CItem).super_CBaseEntity.pev)->solid = 1;
    peVar2 = (this->super_CItem).super_CBaseEntity.pev;
    UTIL_SetOrigin(peVar2,&peVar2->origin);
    local_24.x = 16.0;
    local_24.y = 16.0;
    local_24.z = 16.0;
    local_18.x = -16.0;
    local_18.y = -16.0;
    local_18.z = 0.0;
    UTIL_SetSize((this->super_CItem).super_CBaseEntity.pev,&local_18,&local_24);
    (this->super_CItem).super_CBaseEntity.m_pfnTouch.__pfn = CItem::ItemTouch;
    (this->super_CItem).super_CBaseEntity.m_pfnTouch.__delta = 0;
    if ((this->super_CItem).m_flRespawnTime == 0.0) {
      (this->super_CItem).m_flRespawnTime = 20.0;
    }
    iVar4 = (*g_engfuncs.pfnDropToFloor)
                      (((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity);
    if (iVar4 != 0) {
      return;
    }
    peVar2 = (this->super_CItem).super_CBaseEntity.pev;
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"Item %s fell out of level at %f,%f,%f",
               gpGlobals->pStringBase + peVar2->classname,(double)(peVar2->origin).x,
               (double)(peVar2->origin).y,(double)(peVar2->origin).z);
  }
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CItemLongJump::Precache  @ 000a5500  (line 333)

/* DWARF original prototype: void Precache(CItemLongJump * this) */

void __thiscall CItemLongJump::Precache(CItemLongJump *this)

{
                    /* WARNING: Could not recover jumptable at 0x000a5509. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("models/w_longjump.mdl");
  return;
}


// CItemLongJump::MyTouch  @ 000a5800  (line 335)

/* DWARF original prototype: BOOL MyTouch(CItemLongJump * this, CBasePlayer * pPlayer) */

BOOL __thiscall CItemLongJump::MyTouch(CItemLongJump *this,CBasePlayer *pPlayer)

{
  entvars_t *peVar1;
  
  if (pPlayer->m_fLongJump != 0) {
    return 0;
  }
  peVar1 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (-1 < peVar1->weapons) {
    return 0;
  }
  pPlayer->m_fLongJump = 1;
  (*g_engfuncs.pfnMessageBegin)(1,gmsgItemPickup,(float *)0x0,peVar1->pContainingEntity);
  (*g_engfuncs.pfnWriteString)
            (gpGlobals->pStringBase + ((this->super_CItem).super_CBaseEntity.pev)->classname);
  (*g_engfuncs.pfnMessageEnd)();
  EMIT_SOUND_SUIT(((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"!HEV_A1");
  return 1;
}


// item_longjump  @ 000a5410  (line 357)

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
  *puVar1 = &PTR__CItemLongJump_00152cc8;
  puVar1[1] = pev;
  return;
}


