// Ghidra decompilation of functions from tfc/triggers.cpp
// 136 functions, ordered by original source line

// CFrictionModifier::ObjectCaps  @ 0014d6b0  (line 50)

/* DWARF original prototype: int ObjectCaps(CFrictionModifier * this) */

int __thiscall CFrictionModifier::ObjectCaps(CFrictionModifier *this)

{
  return 0;
}


// func_friction  @ 0014ad20  (line 57)

void func_friction(entvars_t *pev)

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
  *puVar1 = &PTR__CFrictionModifier_001952a8;
  puVar1[1] = pev;
  return;
}


// CFrictionModifier::Restore  @ 00148d30  (line 65)

/* DWARF original prototype: int Restore(CFrictionModifier * this, CRestore * restore) */

int __thiscall CFrictionModifier::Restore(CFrictionModifier *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore(&this->super_CBaseEntity,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CFrictionModifier",this,m_SaveData,1);
  }
  return iVar2;
}


// CFrictionModifier::Save  @ 00148fd0  (line 65)

/* DWARF original prototype: int Save(CFrictionModifier * this, CSave * save) */

int __thiscall CFrictionModifier::Save(CFrictionModifier *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save(&this->super_CBaseEntity,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CFrictionModifier",this,m_SaveData,1);
  }
  return iVar2;
}


// CFrictionModifier::Spawn  @ 00147f50  (line 70)

/* DWARF original prototype: void Spawn(CFrictionModifier * this) */

void __thiscall CFrictionModifier::Spawn(CFrictionModifier *this)

{
  entvars_t *peVar1;
  
  ((this->super_CBaseEntity).pev)->solid = 1;
  peVar1 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar1->pContainingEntity,gpGlobals->pStringBase + peVar1->model);
  ((this->super_CBaseEntity).pev)->movetype = 0;
  (this->super_CBaseEntity).m_pfnTouch.__pfn = ChangeFriction;
  (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
  return;
}


// CFrictionModifier::ChangeFriction  @ 00147fb0  (line 81)

/* DWARF original prototype: void ChangeFriction(CFrictionModifier * this, CBaseEntity * pOther) */

void __thiscall CFrictionModifier::ChangeFriction(CFrictionModifier *this,CBaseEntity *pOther)

{
  if (1 < pOther->pev->movetype - 10U) {
    pOther->pev->friction = this->m_frictionFraction;
  }
  return;
}


// CFrictionModifier::KeyValue  @ 00149ca0  (line 89)

/* DWARF original prototype: void KeyValue(CFrictionModifier * this, KeyValueData * pkvd) */

void __thiscall CFrictionModifier::KeyValue(CFrictionModifier *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  double dVar5;
  
  bVar4 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar1 = 9;
  pcVar2 = pkvd->szKeyName;
  pcVar3 = "modifier";
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
  this->m_frictionFraction = (float)dVar5 / 100.0;
  pkvd->fHandled = 1;
  return;
}


// CAutoTrigger::ObjectCaps  @ 0014d6c0  (line 113)

/* DWARF original prototype: int ObjectCaps(CAutoTrigger * this) */

int __thiscall CAutoTrigger::ObjectCaps(CAutoTrigger *this)

{
  return 0;
}


// trigger_auto  @ 0014ad90  (line 123)

void trigger_auto(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x484,pev);
  *puVar1 = &PTR__CAutoTrigger_001953c8;
  puVar1[1] = pev;
  return;
}


// CAutoTrigger::Restore  @ 00148cd0  (line 131)

/* DWARF original prototype: int Restore(CAutoTrigger * this, CRestore * restore) */

int __thiscall CAutoTrigger::Restore(CAutoTrigger *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseDelay::Restore(&this->super_CBaseDelay,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CAutoTrigger",this,m_SaveData,2);
  }
  return iVar2;
}


// CAutoTrigger::Save  @ 00148f70  (line 131)

/* DWARF original prototype: int Save(CAutoTrigger * this, CSave * save) */

int __thiscall CAutoTrigger::Save(CAutoTrigger *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseDelay::Save(&this->super_CBaseDelay,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CAutoTrigger",this,m_SaveData,2);
  }
  return iVar2;
}


// CAutoTrigger::KeyValue  @ 00149bc0  (line 134)

/* DWARF original prototype: void KeyValue(CAutoTrigger * this, KeyValueData * pkvd) */

void __thiscall CAutoTrigger::KeyValue(CAutoTrigger *this,KeyValueData *pkvd)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar2 = 0xc;
  pcVar3 = pkvd->szKeyName;
  pcVar4 = "globalstate";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    iVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    this->m_globalstate = iVar2;
    pkvd->fHandled = 1;
  }
  else {
    iVar2 = 0xd;
    bVar5 = false;
    pcVar3 = pkvd->szKeyName;
    pcVar4 = "triggerstate";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      CBaseDelay::KeyValue(&this->super_CBaseDelay,pkvd);
      return;
    }
                    /* Unresolved local var: int type@[DW_OP_reg0(EAX)] */
    lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
    if (lVar1 == 0) {
      this->triggerType = USE_OFF;
    }
    else {
      this->triggerType = (uint)(lVar1 == 2) * 2 + USE_ON;
    }
    pkvd->fHandled = 1;
  }
  return;
}


// CAutoTrigger::Spawn  @ 00147fe0  (line 163)

/* DWARF original prototype: void Spawn(CAutoTrigger * this) */

void __thiscall CAutoTrigger::Spawn(CAutoTrigger *this)

{
                    /* WARNING: Could not recover jumptable at 0x00147fe9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[3])();
  return;
}


// CAutoTrigger::Precache  @ 00147ff0  (line 169)

/* DWARF original prototype: void Precache(CAutoTrigger * this) */

void __thiscall CAutoTrigger::Precache(CAutoTrigger *this)

{
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  return;
}


// CAutoTrigger::Think  @ 00149320  (line 175)

/* DWARF original prototype: void Think(CAutoTrigger * this) */

void __thiscall CAutoTrigger::Think(CAutoTrigger *this)

{
  GLOBALESTATE GVar1;
  
  if (this->m_globalstate != 0) {
    GVar1 = CGlobalState::EntityGetState(&gGlobalState,this->m_globalstate);
    if (GVar1 != GLOBAL_ON) {
      return;
    }
  }
  CBaseDelay::SUB_UseTargets(&this->super_CBaseDelay,(CBaseEntity *)this,this->triggerType,0.0);
  if ((((this->super_CBaseDelay).super_CBaseEntity.pev)->spawnflags & 1) == 0) {
    return;
  }
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CTriggerRelay::ObjectCaps  @ 0014d6d0  (line 195)

/* DWARF original prototype: int ObjectCaps(CTriggerRelay * this) */

int __thiscall CTriggerRelay::ObjectCaps(CTriggerRelay *this)

{
  return 0;
}


// trigger_relay  @ 0014ae00  (line 204)

void trigger_relay(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x480,pev);
  *puVar1 = &PTR__CTriggerRelay_001954e8;
  puVar1[1] = pev;
  return;
}


// CTriggerRelay::Restore  @ 00148c70  (line 211)

/* DWARF original prototype: int Restore(CTriggerRelay * this, CRestore * restore) */

int __thiscall CTriggerRelay::Restore(CTriggerRelay *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseDelay::Restore(&this->super_CBaseDelay,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CTriggerRelay",this,m_SaveData,1);
  }
  return iVar2;
}


// CTriggerRelay::Save  @ 00148f10  (line 211)

/* DWARF original prototype: int Save(CTriggerRelay * this, CSave * save) */

int __thiscall CTriggerRelay::Save(CTriggerRelay *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseDelay::Save(&this->super_CBaseDelay,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CTriggerRelay",this,m_SaveData,1);
  }
  return iVar2;
}


// CTriggerRelay::KeyValue  @ 00149b10  (line 214)

/* DWARF original prototype: void KeyValue(CTriggerRelay * this, KeyValueData * pkvd) */

void __thiscall CTriggerRelay::KeyValue(CTriggerRelay *this,KeyValueData *pkvd)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar2 = 0xd;
  pcVar3 = pkvd->szKeyName;
  pcVar4 = "triggerstate";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
                    /* Unresolved local var: int type@[DW_OP_reg0(EAX)] */
    lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
    if (lVar1 == 0) {
      this->triggerType = USE_OFF;
    }
    else {
      this->triggerType = (uint)(lVar1 == 2) * 2 + USE_ON;
    }
    pkvd->fHandled = 1;
    return;
  }
  CBaseDelay::KeyValue(&this->super_CBaseDelay,pkvd);
  return;
}


// CTriggerRelay::Spawn  @ 00148020  (line 239)

/* DWARF original prototype: void Spawn(CTriggerRelay * this) */

void __thiscall CTriggerRelay::Spawn(CTriggerRelay *this)

{
  return;
}


// CTriggerRelay::Use  @ 00148750  (line 245)

/* DWARF original prototype: void Use(CTriggerRelay * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CTriggerRelay::Use(CTriggerRelay *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType
                  ,float value)

{
  CBaseDelay::SUB_UseTargets(&this->super_CBaseDelay,(CBaseEntity *)this,this->triggerType,0.0);
  if ((((this->super_CBaseDelay).super_CBaseEntity.pev)->spawnflags & 1) == 0) {
    return;
  }
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CMultiManager::ObjectCaps  @ 0014d6e0  (line 267)

/* DWARF original prototype: int ObjectCaps(CMultiManager * this) */

int __thiscall CMultiManager::ObjectCaps(CMultiManager *this)

{
  return 0;
}


// multi_manager  @ 0014ae70  (line 280)

void multi_manager(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x5a0,pev);
  *puVar1 = &PTR__CMultiManager_00195608;
  puVar1[1] = pev;
  return;
}


// CMultiManager::Restore  @ 00148c10  (line 292)

/* DWARF original prototype: int Restore(CMultiManager * this, CRestore * restore) */

int __thiscall CMultiManager::Restore(CMultiManager *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Restore(&this->super_CBaseToggle,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CMultiManager",this,m_SaveData,5);
  }
  return iVar2;
}


// CMultiManager::Save  @ 00148eb0  (line 292)

/* DWARF original prototype: int Save(CMultiManager * this, CSave * save) */

int __thiscall CMultiManager::Save(CMultiManager *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Save(&this->super_CBaseToggle,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CMultiManager",this,m_SaveData,5);
  }
  return iVar2;
}


// CMultiManager::KeyValue  @ 00149a00  (line 295)

/* DWARF original prototype: void KeyValue(CMultiManager * this, KeyValueData * pkvd) */

void __thiscall CMultiManager::KeyValue(CMultiManager *this,KeyValueData *pkvd)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  double dVar6;
  char local_9c [140];
  
  bVar5 = &stack0x00000000 == (undefined1 *)0xbc;
  iVar2 = 5;
  pcVar3 = pkvd->szKeyName;
  pcVar4 = "wait";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    dVar6 = strtod(pkvd->szValue,(char **)0x0);
    (this->super_CBaseToggle).m_flWait = (float)dVar6;
    pkvd->fHandled = 1;
  }
  else if (this->m_cTargets < 0x10) {
                    /* Unresolved local var: char[128] tmp@[???] */
    UTIL_StripToken(pkvd->szKeyName,local_9c);
    iVar2 = this->m_cTargets;
    iVar1 = (*g_engfuncs.pfnAllocString)(local_9c);
    this->m_iTargetName[iVar2] = iVar1;
    iVar2 = this->m_cTargets;
    dVar6 = strtod(pkvd->szValue,(char **)0x0);
    this->m_flTargetDelay[iVar2] = (float)dVar6;
    this->m_cTargets = this->m_cTargets + 1;
    pkvd->fHandled = 1;
  }
  return;
}


// CMultiManager::Spawn  @ 00148030  (line 324)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CMultiManager * this) */

void __thiscall CMultiManager::Spawn(CMultiManager *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  CMultiManager *pCVar6;
  int iVar7;
  
                    /* Unresolved local var: int swapped@[???] */
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 0
  ;
  iVar2 = this->m_cTargets;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.__pfn =
       ManagerUse;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.__delta
       = 0;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = ManagerThink;
                    /* Unresolved local var: int i@[???] */
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  if (1 < iVar2) {
    do {
      iVar7 = 1;
      bVar5 = false;
      pCVar6 = this;
      do {
        fVar1 = pCVar6->m_flTargetDelay[1];
        if (fVar1 < pCVar6->m_flTargetDelay[0]) {
                    /* Unresolved local var: int name@[???]
                       Unresolved local var: float delay@[???] */
          iVar3 = pCVar6->m_iTargetName[1];
          pCVar6->m_flTargetDelay[1] = pCVar6->m_flTargetDelay[0];
          iVar4 = pCVar6->m_iTargetName[0];
          pCVar6->m_flTargetDelay[0] = fVar1;
          pCVar6->m_iTargetName[0] = iVar3;
          bVar5 = true;
          pCVar6->m_iTargetName[1] = iVar4;
        }
        iVar7 = iVar7 + 1;
        pCVar6 = (CMultiManager *)
                 &(pCVar6->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev;
      } while (iVar7 != iVar2);
    } while (bVar5);
  }
  return;
}


// CMultiManager::HasTarget  @ 00149480  (line 355)

/* DWARF original prototype: BOOL HasTarget(CMultiManager * this, string_t targetname) */

BOOL __thiscall CMultiManager::HasTarget(CMultiManager *this,string_t targetname)

{
  int iVar1;
  char *pcVar2;
  BOOL BVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int i@[???] */
  BVar3 = 0;
  iVar1 = this->m_cTargets;
  if (0 < iVar1) {
    iVar5 = 0;
    pcVar2 = gpGlobals->pStringBase;
    while( true ) {
      iVar4 = strcmp(pcVar2 + targetname,pcVar2 + this->m_iTargetName[iVar5]);
      if (iVar4 == 0) break;
      iVar5 = iVar5 + 1;
      if (iVar5 == iVar1) {
        return 0;
      }
    }
    BVar3 = 1;
  }
  return BVar3;
}


// CMultiManager::ManagerThink  @ 00148480  (line 367)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ManagerThink(CMultiManager * this) */

void __thiscall CMultiManager::ManagerThink(CMultiManager *this)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  CBaseEntity *pActivator;
  
                    /* Unresolved local var: float time@[???] */
  fVar2 = this->m_startTime;
  if (this->m_index < this->m_cTargets) {
    fVar5 = gpGlobals->time - fVar2;
    fVar3 = this->m_flTargetDelay[this->m_index];
    if (fVar3 <= fVar5) {
      do {
        pActivator = EHANDLE::operator_CBaseEntity_(&(this->super_CBaseToggle).m_hActivator);
        FireTargets(gpGlobals->pStringBase + this->m_iTargetName[this->m_index],pActivator,
                    (CBaseEntity *)this,USE_TOGGLE,0.0);
        iVar4 = this->m_index;
        iVar1 = iVar4 + 1;
        this->m_index = iVar1;
        if (this->m_cTargets <= iVar1) goto LAB_00148534;
        fVar3 = this->m_flTargetDelay[iVar4 + 1];
      } while (fVar3 <= fVar5);
      fVar2 = this->m_startTime;
    }
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    nextthink = fVar2 + fVar3;
    return;
  }
LAB_00148534:
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.__pfn =
       ManagerUse;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.__delta
       = 0;
  return;
}


// CMultiManager::ManagerUse  @ 001485b0  (line 388)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ManagerUse(CMultiManager * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CMultiManager::ManagerUse
          (CMultiManager *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  float fVar1;
  entvars_t *peVar2;
  globalvars_t *pgVar3;
  
  EHANDLE::operator=(&(this->super_CBaseToggle).m_hActivator,pActivator);
  this->m_index = 0;
  pgVar3 = gpGlobals;
  fVar1 = gpGlobals->time;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *)0x0;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.__delta
       = 0;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = ManagerThink;
  this->m_startTime = fVar1;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  peVar2->nextthink = pgVar3->time;
  return;
}


// CMultiManager::ManagerReport  @ 0014aee0  (line 400)

/* DWARF original prototype: void ManagerReport(CMultiManager * this) */

void __thiscall CMultiManager::ManagerReport(CMultiManager *this)

{
  float *pfVar1;
  int *piVar2;
  int iVar3;
  
                    /* Unresolved local var: int cIndex@[???] */
  if (0 < this->m_cTargets) {
    iVar3 = 0;
    do {
      pfVar1 = this->m_flTargetDelay + iVar3;
      piVar2 = this->m_iTargetName + iVar3;
      iVar3 = iVar3 + 1;
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"%s %f\n",gpGlobals->pStringBase + *piVar2,(double)*pfVar1);
    } while (iVar3 < this->m_cTargets);
  }
  return;
}


// env_render  @ 0014af50  (line 432)

void env_render(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x474,pev);
  *puVar1 = &PTR__CRenderFxManager_00195728;
  puVar1[1] = pev;
  return;
}


// CRenderFxManager::Spawn  @ 001480d0  (line 437)

/* DWARF original prototype: void Spawn(CRenderFxManager * this) */

void __thiscall CRenderFxManager::Spawn(CRenderFxManager *this)

{
  ((this->super_CBaseEntity).pev)->solid = 0;
  return;
}


// CRenderFxManager::Use  @ 00149390  (line 441)

/* DWARF original prototype: void Use(CRenderFxManager * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CRenderFxManager::Use
          (CRenderFxManager *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  string_t sVar1;
  int iVar2;
  entvars_t *peVar3;
  uint uVar4;
  edict_t *peVar5;
  
  peVar5 = (edict_t *)0x0;
  sVar1 = ((this->super_CBaseEntity).pev)->target;
  if (sVar1 != 0) {
                    /* Unresolved local var: edict_t * pentTarget@[???]
                       Unresolved local var: entvars_t * pevTarget@[???] */
    while ((peVar5 = (*g_engfuncs.pfnFindEntityByString)
                               (peVar5,"targetname",gpGlobals->pStringBase + sVar1),
           peVar5 != (edict_t *)0x0 &&
           (iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5), iVar2 != 0))) {
      peVar3 = (this->super_CBaseEntity).pev;
      uVar4 = peVar3->spawnflags;
      if ((uVar4 & 1) == 0) {
        (peVar5->v).renderfx = peVar3->renderfx;
        peVar3 = (this->super_CBaseEntity).pev;
        uVar4 = peVar3->spawnflags;
      }
      if ((uVar4 & 2) == 0) {
        (peVar5->v).renderamt = peVar3->renderamt;
        peVar3 = (this->super_CBaseEntity).pev;
        uVar4 = peVar3->spawnflags;
      }
      if ((uVar4 & 4) == 0) {
        (peVar5->v).rendermode = peVar3->rendermode;
        peVar3 = (this->super_CBaseEntity).pev;
        uVar4 = peVar3->spawnflags;
      }
      if ((uVar4 & 8) == 0) {
        (peVar5->v).rendercolor.x = (peVar3->rendercolor).x;
        (peVar5->v).rendercolor.y = (peVar3->rendercolor).y;
        (peVar5->v).rendercolor.z = (peVar3->rendercolor).z;
        peVar3 = (this->super_CBaseEntity).pev;
      }
      sVar1 = peVar3->target;
    }
  }
  return;
}


// CBaseTrigger::ObjectCaps  @ 0014d6f0  (line 480)

/* DWARF original prototype: int ObjectCaps(CBaseTrigger * this) */

int __thiscall CBaseTrigger::ObjectCaps(CBaseTrigger *this)

{
  return 0;
}


// trigger  @ 0014afc0  (line 483)

void trigger(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x514,pev);
  *puVar1 = &PTR__CBaseTrigger_00195848;
  puVar1[1] = pev;
  return;
}


// CBaseTrigger::InitTrigger  @ 0014b030  (line 491)

/* DWARF original prototype: void InitTrigger(CBaseTrigger * this) */

void __thiscall CBaseTrigger::InitTrigger(CBaseTrigger *this)

{
  int *piVar1;
  entvars_t *peVar2;
  longdouble lVar3;
  
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((((peVar2->angles).x != g_vecZero.x) || ((peVar2->angles).y != g_vecZero.y)) ||
     ((peVar2->angles).z != g_vecZero.z)) {
    SetMovedir(peVar2);
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  peVar2->solid = 1;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->movetype
       = 0;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + peVar2->model);
  lVar3 = (longdouble)(*g_engfuncs.pfnCVarGetFloat)("showtriggers");
  if (lVar3 == (longdouble)0) {
    piVar1 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
              )->effects;
    *piVar1 = *piVar1 | 0x80;
  }
  return;
}


// CBaseTrigger::KeyValue  @ 00149840  (line 509)

/* DWARF original prototype: void KeyValue(CBaseTrigger * this, KeyValueData * pkvd) */

void __thiscall CBaseTrigger::KeyValue(CBaseTrigger *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  double dVar8;
  
  bVar7 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar3 = 7;
  pcVar5 = pkvd->szKeyName;
  pcVar4 = pcVar5;
  pcVar6 = "damage";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar4 == *pcVar6;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    dVar8 = strtod(pkvd->szValue,(char **)0x0);
    peVar1->dmg = (float)dVar8;
    pkvd->fHandled = 1;
  }
  else {
    iVar3 = 6;
    bVar7 = false;
    pcVar4 = pcVar5;
    pcVar6 = "count";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      dVar8 = strtod(pkvd->szValue,(char **)0x0);
      (this->super_CBaseToggle).m_cTriggersLeft = (int)dVar8;
      pkvd->fHandled = 1;
    }
    else {
      iVar3 = 0xb;
      bVar7 = false;
      pcVar4 = "damagetype";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar5 == *pcVar4;
        pcVar5 = pcVar5 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar7);
      if (!bVar7) {
        CBaseToggle::KeyValue(&this->super_CBaseToggle,pkvd);
        return;
      }
      lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
      (this->super_CBaseToggle).m_bitsDamageInflict = lVar2;
      pkvd->fHandled = 1;
    }
  }
  return;
}


// trigger_hurt  @ 0014b5f0  (line 536)

void trigger_hurt(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x514,pev);
  *puVar1 = &PTR__CTriggerHurt_00195cc8;
  puVar1[1] = pev;
  return;
}


// trigger_monsterjump  @ 0014b660  (line 549)

void trigger_monsterjump(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x514,pev);
  *puVar1 = &PTR__CTriggerMonsterJump_00195968;
  puVar1[1] = pev;
  return;
}


// CTriggerMonsterJump::Spawn  @ 0014b500  (line 553)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTriggerMonsterJump * this) */

void __thiscall CTriggerMonsterJump::Spawn(CTriggerMonsterJump *this)

{
  entvars_t *peVar1;
  
  SetMovedir((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev);
  CBaseTrigger::InitTrigger(&this->super_CBaseTrigger);
  ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = 0.0;
  ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->speed = 200.0;
  peVar1 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseTrigger).super_CBaseToggle.m_flHeight = 150.0;
  if (peVar1->targetname != 0) {
    peVar1->solid = 0;
    peVar1 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    UTIL_SetOrigin(peVar1,&peVar1->origin);
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__pfn = CBaseTrigger::ToggleUse;
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__delta = 0;
  }
  return;
}


// CTriggerMonsterJump::Think  @ 00148660  (line 572)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Think(CTriggerMonsterJump * this) */

void __thiscall CTriggerMonsterJump::Think(CTriggerMonsterJump *this)

{
  entvars_t *pev;
  
  ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 0;
  pev = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev;
  UTIL_SetOrigin(pev,&pev->origin);
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  return;
}


// CTriggerMonsterJump::Touch  @ 001480e0  (line 580)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Touch(CTriggerMonsterJump * this, CBaseEntity * pOther) */

void __thiscall CTriggerMonsterJump::Touch(CTriggerMonsterJump *this,CBaseEntity *pOther)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  uint uVar4;
  entvars_t *peVar5;
  float fVar6;
  globalvars_t *pgVar7;
  
                    /* Unresolved local var: entvars_t * pevOther@[???] */
  peVar3 = pOther->pev;
  uVar4 = peVar3->flags;
  if ((uVar4 & 0x20) != 0) {
    (peVar3->origin).z = (peVar3->origin).z + 1.0;
    if ((uVar4 & 0x200) != 0) {
      peVar3->flags = uVar4 & 0xfffffdff;
    }
    pgVar7 = gpGlobals;
    peVar5 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar1 = peVar5->speed;
    fVar6 = (peVar5->movedir).z * fVar1;
    fVar2 = (peVar5->movedir).y;
    (peVar3->velocity).x = fVar1 * (peVar5->movedir).x;
    (peVar3->velocity).y = fVar2 * fVar1;
    (peVar3->velocity).z = fVar6;
    (peVar3->velocity).z = fVar6 + (this->super_CBaseTrigger).super_CBaseToggle.m_flHeight;
    ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->nextthink = pgVar7->time;
  }
  return;
}


// trigger_cdaudio  @ 0014b6d0  (line 615)

void trigger_cdaudio(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x514,pev);
  *puVar1 = &PTR__CTriggerCDAudio_00195a88;
  puVar1[1] = pev;
  return;
}


// CTriggerCDAudio::Touch  @ 0014aac0  (line 622)

/* DWARF original prototype: void Touch(CTriggerCDAudio * this, CBaseEntity * pOther) */

void __thiscall CTriggerCDAudio::Touch(CTriggerCDAudio *this,CBaseEntity *pOther)

{
  float fVar1;
  edict_t *peVar2;
  int iVar3;
  char local_4c [64];
  
  if ((pOther->pev->flags & 8) == 0) {
    return;
  }
  fVar1 = ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->health;
                    /* Unresolved local var: edict_t * pClient@[???] */
  peVar2 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if (peVar2 != (edict_t *)0x0) {
    iVar3 = (int)fVar1;
    if (iVar3 + 1U < 0x20) {
      if (iVar3 == -1) {
        (*g_engfuncs.pfnClientCommand)(peVar2,"cd stop\n");
      }
      else {
                    /* Unresolved local var: char[64] string@[???] */
        sprintf(local_4c,"cd play %3d\n",iVar3);
        (*g_engfuncs.pfnClientCommand)(peVar2,local_4c);
      }
    }
    else {
                    /* Unresolved local var: edict_t * pClient@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_console,"TriggerCDAudio - Track %d out of range\n");
    }
  }
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CTriggerCDAudio::Spawn  @ 0014b4f0  (line 633)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTriggerCDAudio * this) */

void __thiscall CTriggerCDAudio::Spawn(CTriggerCDAudio *this)

{
  int *piVar1;
  entvars_t *peVar2;
  longdouble lVar3;
  
  peVar2 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((((peVar2->angles).x != g_vecZero.x) || ((peVar2->angles).y != g_vecZero.y)) ||
     ((peVar2->angles).z != g_vecZero.z)) {
    SetMovedir(peVar2);
    peVar2 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  peVar2->solid = 1;
  ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 0;
  peVar2 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + peVar2->model);
  lVar3 = (longdouble)(*g_engfuncs.pfnCVarGetFloat)("showtriggers");
  if (lVar3 == (longdouble)0) {
    piVar1 = &((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 0x80;
  }
  return;
}


// CTriggerCDAudio::Use  @ 0014a910  (line 637)

/* DWARF original prototype: void Use(CTriggerCDAudio * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CTriggerCDAudio::Use
          (CTriggerCDAudio *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  float fVar1;
  edict_t *peVar2;
  int iVar3;
  char local_4c [64];
  
  fVar1 = ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->health;
                    /* Unresolved local var: edict_t * pClient@[???] */
  peVar2 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if (peVar2 != (edict_t *)0x0) {
    iVar3 = (int)fVar1;
    if (iVar3 + 1U < 0x20) {
      if (iVar3 == -1) {
        (*g_engfuncs.pfnClientCommand)(peVar2,"cd stop\n");
      }
      else {
                    /* Unresolved local var: char[64] string@[???] */
        sprintf(local_4c,"cd play %3d\n",iVar3);
        (*g_engfuncs.pfnClientCommand)(peVar2,local_4c);
      }
    }
    else {
                    /* Unresolved local var: edict_t * pClient@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_console,"TriggerCDAudio - Track %d out of range\n");
    }
  }
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// PlayCDTrack  @ 0014b740  (line 642)

void PlayCDTrack(int iTrack)

{
  edict_t *peVar1;
  char local_4c [68];
  
                    /* Unresolved local var: edict_t * pClient@[???] */
  peVar1 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if (peVar1 != (edict_t *)0x0) {
    if (0x1f < iTrack + 1U) {
                    /* Unresolved local var: edict_t * pClient@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_console,"TriggerCDAudio - Track %d out of range\n");
      return;
    }
    if (iTrack == -1) {
      (*g_engfuncs.pfnClientCommand)(peVar1,"cd stop\n");
      return;
    }
                    /* Unresolved local var: char[64] string@[???] */
    sprintf(local_4c,"cd play %3d\n",iTrack);
    (*g_engfuncs.pfnClientCommand)(peVar1,local_4c);
  }
  return;
}


// CTriggerCDAudio::PlayTrack  @ 0014b7f0  (line 674)

/* DWARF original prototype: void PlayTrack(CTriggerCDAudio * this) */

void __thiscall CTriggerCDAudio::PlayTrack(CTriggerCDAudio *this)

{
  float fVar1;
  edict_t *peVar2;
  int iVar3;
  char local_4c [64];
  
  fVar1 = ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->health;
                    /* Unresolved local var: edict_t * pClient@[???] */
  peVar2 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if (peVar2 != (edict_t *)0x0) {
    iVar3 = (int)fVar1;
    if (iVar3 + 1U < 0x20) {
      if (iVar3 == -1) {
        (*g_engfuncs.pfnClientCommand)(peVar2,"cd stop\n");
      }
      else {
                    /* Unresolved local var: char[64] string@[???] */
        sprintf(local_4c,"cd play %3d\n",iVar3);
        (*g_engfuncs.pfnClientCommand)(peVar2,local_4c);
      }
    }
    else {
                    /* Unresolved local var: edict_t * pClient@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_console,"TriggerCDAudio - Track %d out of range\n");
    }
  }
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// target_cdaudio  @ 0014b8d0  (line 694)

void target_cdaudio(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x474,pev);
  *puVar1 = &PTR__CTargetCDAudio_00195ba8;
  puVar1[1] = pev;
  return;
}


// CTargetCDAudio::KeyValue  @ 001497c0  (line 697)

/* DWARF original prototype: void KeyValue(CTargetCDAudio * this, KeyValueData * pkvd) */

void __thiscall CTargetCDAudio::KeyValue(CTargetCDAudio *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  double dVar6;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar2 = 7;
  pcVar3 = pkvd->szKeyName;
  pcVar4 = "radius";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (!bVar5) {
    CBaseEntity::KeyValue((CBaseEntity *)this,pkvd);
    return;
  }
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  dVar6 = strtod(pkvd->szValue,(char **)0x0);
  peVar1->scale = (float)dVar6;
  pkvd->fHandled = 1;
  return;
}


// CTargetCDAudio::Spawn  @ 00148ab0  (line 708)

/* DWARF original prototype: void Spawn(CTargetCDAudio * this) */

void __thiscall CTargetCDAudio::Spawn(CTargetCDAudio *this)

{
  entvars_t *peVar1;
  
  ((this->super_CPointEntity).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0;
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if (0.0 < peVar1->scale) {
    peVar1->nextthink = gpGlobals->time + 1.0;
  }
  return;
}


// CTargetCDAudio::Use  @ 0014a9f0  (line 717)

/* DWARF original prototype: void Use(CTargetCDAudio * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CTargetCDAudio::Use(CTargetCDAudio *this,CBaseEntity *pActivator,CBaseEntity *pCaller,
                   USE_TYPE useType,float value)

{
  float fVar1;
  edict_t *peVar2;
  int iVar3;
  char local_4c [64];
  
  fVar1 = ((this->super_CPointEntity).super_CBaseEntity.pev)->health;
                    /* Unresolved local var: edict_t * pClient@[???] */
  peVar2 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if (peVar2 != (edict_t *)0x0) {
    iVar3 = (int)fVar1;
    if (iVar3 + 1U < 0x20) {
      if (iVar3 == -1) {
        (*g_engfuncs.pfnClientCommand)(peVar2,"cd stop\n");
      }
      else {
                    /* Unresolved local var: char[64] string@[???] */
        sprintf(local_4c,"cd play %3d\n",iVar3);
        (*g_engfuncs.pfnClientCommand)(peVar2,local_4c);
      }
    }
    else {
                    /* Unresolved local var: edict_t * pClient@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_console,"TriggerCDAudio - Track %d out of range\n");
    }
  }
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CTargetCDAudio::Think  @ 0014abc0  (line 723)

/* DWARF original prototype: void Think(CTargetCDAudio * this) */

void __thiscall CTargetCDAudio::Think(CTargetCDAudio *this)

{
  float fVar1;
  float fVar2;
  edict_t *peVar3;
  int iVar4;
  entvars_t *peVar5;
  float fVar6;
  char local_4c [64];
  
                    /* Unresolved local var: edict_t * pClient@[???] */
  peVar3 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if (peVar3 != (edict_t *)0x0) {
    ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.5;
    peVar5 = (this->super_CPointEntity).super_CBaseEntity.pev;
    fVar1 = (peVar3->v).origin.z - (peVar5->origin).z;
    fVar2 = (peVar3->v).origin.y - (peVar5->origin).y;
    fVar6 = (peVar3->v).origin.x - (peVar5->origin).x;
    fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar6 * fVar6;
    fVar6 = SQRT(fVar1);
    if (NAN(fVar6)) {
      fVar6 = sqrtf(fVar1);
      peVar5 = (this->super_CPointEntity).super_CBaseEntity.pev;
    }
    if (fVar6 <= peVar5->scale) {
      fVar1 = peVar5->health;
                    /* Unresolved local var: edict_t * pClient@[???] */
      peVar3 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
      if (peVar3 != (edict_t *)0x0) {
        iVar4 = (int)fVar1;
        if (iVar4 + 1U < 0x20) {
          if (iVar4 == -1) {
            (*g_engfuncs.pfnClientCommand)(peVar3,"cd stop\n");
          }
          else {
                    /* Unresolved local var: char[64] string@[???] */
            sprintf(local_4c,"cd play %3d\n",iVar4);
            (*g_engfuncs.pfnClientCommand)(peVar3,local_4c);
          }
        }
        else {
                    /* Unresolved local var: edict_t * pClient@[???] */
          (*g_engfuncs.pfnAlertMessage)(at_console,"TriggerCDAudio - Track %d out of range\n");
        }
      }
      UTIL_Remove((CBaseEntity *)this);
      return;
    }
  }
  return;
}


// CTargetCDAudio::Play  @ 0014b940  (line 741)

/* DWARF original prototype: void Play(CTargetCDAudio * this) */

void __thiscall CTargetCDAudio::Play(CTargetCDAudio *this)

{
  float fVar1;
  edict_t *peVar2;
  int iVar3;
  char local_4c [64];
  
  fVar1 = ((this->super_CPointEntity).super_CBaseEntity.pev)->health;
                    /* Unresolved local var: edict_t * pClient@[???] */
  peVar2 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if (peVar2 != (edict_t *)0x0) {
    iVar3 = (int)fVar1;
    if (iVar3 + 1U < 0x20) {
      if (iVar3 == -1) {
        (*g_engfuncs.pfnClientCommand)(peVar2,"cd stop\n");
      }
      else {
                    /* Unresolved local var: char[64] string@[???] */
        sprintf(local_4c,"cd play %3d\n",iVar3);
        (*g_engfuncs.pfnClientCommand)(peVar2,local_4c);
      }
    }
    else {
                    /* Unresolved local var: edict_t * pClient@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_console,"TriggerCDAudio - Track %d out of range\n");
    }
  }
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CTriggerHurt::Spawn  @ 0014b420  (line 754)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTriggerHurt * this) */

void __thiscall CTriggerHurt::Spawn(CTriggerHurt *this)

{
  float fVar1;
  byte bVar2;
  globalvars_t *pgVar3;
  entvars_t *pev;
  longdouble lVar4;
  
  CBaseTrigger::InitTrigger(&this->super_CBaseTrigger);
  pev = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBaseTrigger::HurtTouch;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  if (pev->targetname == 0) {
    bVar2 = *(byte *)((int)&(this->super_CBaseTrigger).super_CBaseToggle.m_bitsDamageInflict + 2);
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *)0x0
    ;
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__delta = 0;
    pgVar3 = gpGlobals;
  }
  else {
    bVar2 = *(byte *)((int)&(this->super_CBaseTrigger).super_CBaseToggle.m_bitsDamageInflict + 2);
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__pfn = CBaseTrigger::ToggleUse;
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__delta = 0;
    pgVar3 = gpGlobals;
  }
  gpGlobals = pgVar3;
  if ((bVar2 & 4) != 0) {
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = RadiationThink;
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    fVar1 = pgVar3->time;
    lVar4 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,0.5);
    pev->nextthink = (float)(lVar4 + (longdouble)fVar1);
    pev = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev;
  }
  if ((pev->spawnflags & 2) != 0) {
    pev->solid = 0;
    pev = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev;
  }
  UTIL_SetOrigin(pev,&pev->origin);
  return;
}


// CTriggerHurt::RadiationThink  @ 0014a420  (line 784)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RadiationThink(CTriggerHurt * this) */

void __thiscall CTriggerHurt::RadiationThink(CTriggerHurt *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  vec_t vVar5;
  vec_t vVar6;
  vec_t vVar7;
  vec_t vVar8;
  vec_t vVar9;
  vec_t vVar10;
  edict_t *peVar11;
  edict_t *peVar12;
  int iVar13;
  CBasePlayer *this_00;
  float fVar14;
  
                    /* Unresolved local var: edict_t * pentPlayer@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[???]
                       Unresolved local var: float flRange@[???]
                       Unresolved local var: entvars_t * pevTarget@[???]
                       Unresolved local var: Vector vecSpot1@[???]
                       Unresolved local var: Vector vecSpot2@[???]
                       Unresolved local var: Vector vecRange@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector view_ofs@[???] */
  peVar4 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = (peVar4->absmin).z;
  fVar14 = (peVar4->absmax).z;
  vVar5 = (peVar4->view_ofs).y;
  vVar6 = (peVar4->origin).x;
  vVar7 = (peVar4->origin).y;
  vVar8 = (peVar4->origin).z;
  vVar9 = (peVar4->view_ofs).x;
  vVar10 = (peVar4->view_ofs).z;
  fVar2 = (peVar4->absmin).y;
  fVar3 = (peVar4->absmax).y;
  (peVar4->origin).x = ((peVar4->absmin).x + (peVar4->absmax).x) * 0.5;
  (peVar4->origin).y = (fVar2 + fVar3) * 0.5;
  (peVar4->origin).z = (fVar1 + fVar14) * 0.5;
  peVar4 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar4->view_ofs).x = (peVar4->view_ofs).x * 0.0;
  (peVar4->view_ofs).y = (peVar4->view_ofs).y * 0.0;
  (peVar4->view_ofs).z = (peVar4->view_ofs).z * 0.0;
  peVar12 = (*g_engfuncs.pfnFindClientInPVS)
                      (((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  peVar4 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar4->origin).x = vVar6;
  (peVar4->origin).y = vVar7;
  (peVar4->origin).z = vVar8;
  peVar4 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar4->view_ofs).y = vVar5;
  (peVar4->view_ofs).x = vVar9;
  (peVar4->view_ofs).z = vVar10;
  if ((peVar12 != (edict_t *)0x0) &&
     (iVar13 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar12), iVar13 != 0)) {
    peVar11 = (peVar12->v).pContainingEntity;
                    /* Unresolved local var: entvars_t * pev@[???] */
    if ((peVar11 == (edict_t *)0x0) ||
       (this_00 = peVar11->pvPrivateData, this_00 == (CBasePlayer *)0x0)) {
      this_00 = CBaseEntity::operator_new(0xecc,&peVar12->v);
      CBasePlayer::CBasePlayer(this_00);
      (this_00->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev = &peVar12->v;
    }
    peVar4 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar1 = ((peVar4->absmin).z + (peVar4->absmax).z) * 0.5 -
            ((peVar12->v).absmin.z + (peVar12->v).absmax.z) * 0.5;
    fVar2 = ((peVar4->absmin).y + (peVar4->absmax).y) * 0.5 -
            ((peVar12->v).absmin.y + (peVar12->v).absmax.y) * 0.5;
    fVar14 = ((peVar4->absmin).x + (peVar4->absmax).x) * 0.5 -
             ((peVar12->v).absmin.x + (peVar12->v).absmax.x) * 0.5;
    fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar14 * fVar14;
    fVar14 = SQRT(fVar1);
    if (NAN(fVar14)) {
      fVar14 = sqrtf(fVar1);
    }
    if (fVar14 <= this_00->m_flgeigerRange) {
      this_00->m_flgeigerRange = fVar14;
    }
  }
  ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.25;
  return;
}


// CBaseTrigger::ToggleUse  @ 00148610  (line 843)

/* DWARF original prototype: void ToggleUse(CBaseTrigger * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CBaseTrigger::ToggleUse
          (CBaseTrigger *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar1->solid == 0) {
    peVar1->solid = 1;
    gpGlobals->force_retouch = gpGlobals->force_retouch + 1.0;
  }
  else {
    peVar1->solid = 0;
  }
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar1,&peVar1->origin);
  return;
}


// CBaseTrigger::HurtTouch  @ 00149190  (line 860)

/* DWARF original prototype: void HurtTouch(CBaseTrigger * this, CBaseEntity * pOther) */

void __thiscall CBaseTrigger::HurtTouch(CBaseTrigger *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  entvars_t *peVar2;
  float fVar3;
  globalvars_t *pgVar4;
  BOOL BVar5;
  
                    /* Unresolved local var: float fldmg@[???] */
  peVar1 = pOther->pev;
  if (peVar1->takedamage != 0.0) {
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if (((peVar2->spawnflags & 0x20U) != 0) && ((peVar1->flags & 8) == 0)) {
      return;
    }
                    /* Unresolved local var: float fldmg@[???] */
    if (((((peVar2->spawnflags & 8U) == 0) || ((peVar1->flags & 8) == 0)) &&
        ((peVar2->dmgtime <= gpGlobals->time || (gpGlobals->time == peVar2->pain_finished)))) &&
       (BVar5 = ActivationSucceeded((CBaseEntity *)this,(CBasePlayer *)pOther,(CBaseEntity *)0x0),
       BVar5 != 0)) {
      peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      fVar3 = peVar1->dmg * 0.5;
      if (0.0 <= fVar3) {
        (*pOther->_vptr_CBaseEntity[0xd])
                  (pOther,peVar1,peVar1,fVar3,(this->super_CBaseToggle).m_bitsDamageInflict);
      }
      else {
        (*pOther->_vptr_CBaseEntity[0xe])
                  (pOther,-fVar3,(this->super_CBaseToggle).m_bitsDamageInflict);
      }
      pgVar4 = gpGlobals;
      ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      pain_finished = gpGlobals->time;
      ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      dmgtime = pgVar4->time + 0.5;
      peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      if ((peVar1->target != 0) &&
         (((peVar1->spawnflags & 0x10) == 0 || ((pOther->pev->flags & 8) != 0)))) {
        CBaseDelay::SUB_UseTargets((CBaseDelay *)this,pOther,USE_TOGGLE,0.0);
        peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev;
        if ((peVar1->spawnflags & 1) != 0) {
          peVar1->target = 0;
        }
      }
    }
  }
  return;
}


// trigger_multiple  @ 0014ba10  (line 960)

void trigger_multiple(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x514,pev);
  *puVar1 = &PTR__CTriggerMultiple_00195de8;
  puVar1[1] = pev;
  return;
}


// CTriggerMultiple::Spawn  @ 0014b3c0  (line 964)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTriggerMultiple * this) */

void __thiscall CTriggerMultiple::Spawn(CTriggerMultiple *this)

{
  BOOL BVar1;
  
  BVar1 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar1 == 0) {
    dremove((CBaseEntity *)this);
    return;
  }
  if ((this->super_CBaseTrigger).super_CBaseToggle.m_flWait == 0.0) {
    (this->super_CBaseTrigger).super_CBaseToggle.m_flWait = 0.2;
  }
  CBaseTrigger::InitTrigger(&this->super_CBaseTrigger);
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBaseTrigger::MultiTouch;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// trigger_once  @ 0014ba80  (line 1015)

void trigger_once(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x514,pev);
  *puVar1 = &PTR__CTriggerOnce_00195f08;
  puVar1[1] = pev;
  return;
}


// CTriggerOnce::Spawn  @ 0014b580  (line 1017)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTriggerOnce * this) */

void __thiscall CTriggerOnce::Spawn(CTriggerOnce *this)

{
  BOOL BVar1;
  
  (this->super_CTriggerMultiple).super_CBaseTrigger.super_CBaseToggle.m_flWait = -1.0;
  BVar1 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar1 == 0) {
    dremove((CBaseEntity *)this);
    return;
  }
  if ((this->super_CTriggerMultiple).super_CBaseTrigger.super_CBaseToggle.m_flWait == 0.0) {
    (this->super_CTriggerMultiple).super_CBaseTrigger.super_CBaseToggle.m_flWait = 0.2;
  }
  CBaseTrigger::InitTrigger((CBaseTrigger *)this);
  (this->super_CTriggerMultiple).super_CBaseTrigger.super_CBaseToggle.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn = CBaseTrigger::MultiTouch;
  *(int *)((int)&(this->super_CTriggerMultiple).super_CBaseTrigger.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
  return;
}


// CBaseTrigger::MultiTouch  @ 0014a810  (line 1026)

/* DWARF original prototype: void MultiTouch(CBaseTrigger * this, CBaseEntity * pOther) */

void __thiscall CBaseTrigger::MultiTouch(CBaseTrigger *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  uint uVar2;
  entvars_t *peVar3;
  uint uVar4;
  BOOL BVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  byte bVar11;
  
  bVar11 = 0;
                    /* Unresolved local var: entvars_t * pevToucher@[???] */
  peVar1 = pOther->pev;
  BVar5 = ActivationSucceeded((CBaseEntity *)this,(CBasePlayer *)pOther,(CBaseEntity *)0x0);
  if (BVar5 == 0) {
    return;
  }
  uVar2 = peVar1->flags;
  peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  uVar4 = peVar3->spawnflags;
  if ((((uVar2 & 8) == 0) || ((uVar4 & 2) != 0)) && (((uVar2 & 0x20) == 0 || ((uVar4 & 1) == 0)))) {
    if ((uVar4 & 4) == 0) {
      return;
    }
    uVar2 = peVar1->classname;
    bVar9 = CARRY4((uint)gpGlobals->pStringBase,uVar2);
    pbVar7 = (byte *)(gpGlobals->pStringBase + uVar2);
    bVar10 = pbVar7 == (byte *)0x0;
    iVar6 = 0xe;
    pbVar8 = (byte *)"func_pushable";
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar9 = *pbVar7 < *pbVar8;
      bVar10 = *pbVar7 == *pbVar8;
      pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
      pbVar8 = pbVar8 + (uint)bVar11 * -2 + 1;
    } while (bVar10);
    if ((!bVar9 && !bVar10) != bVar9) {
      return;
    }
  }
  if ((peVar3->nextthink <= gpGlobals->time) &&
     (iVar6 = UTIL_IsMasterTriggered((this->super_CBaseToggle).m_sMaster), iVar6 != 0)) {
    ActivateMultiTrigger(this,pOther);
    return;
  }
  return;
}


// CBaseTrigger::ActivateMultiTrigger  @ 0014a220  (line 1060)

/* DWARF original prototype: void ActivateMultiTrigger(CBaseTrigger * this, CBaseEntity *
   pActivator) */

void __thiscall CBaseTrigger::ActivateMultiTrigger(CBaseTrigger *this,CBaseEntity *pActivator)

{
  BOOL *this_00;
  _func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *p_Var1;
  char *pcVar2;
  globalvars_t *pgVar3;
  CBaseDelay *in_EAX;
  entvars_t *peVar4;
  CBaseEntity *pActivator_00;
  int iVar5;
  CBaseEntity *in_EDX;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  
  iVar5 = 0xf;
  peVar4 = (in_EAX->super_CBaseEntity).pev;
  pcVar2 = gpGlobals->pStringBase;
  bVar8 = pcVar2 + peVar4->classname == (char *)0x0;
  pcVar6 = pcVar2 + peVar4->classname;
  pcVar7 = "trigger_secret";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar8 = *pcVar6 == *pcVar7;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar8);
  if (bVar8) {
    if (peVar4->enemy == (edict_t *)0x0) {
      return;
    }
    iVar5 = 7;
    bVar8 = pcVar2 + (peVar4->enemy->v).classname == (char *)0x0;
    pcVar6 = pcVar2 + (peVar4->enemy->v).classname;
    pcVar7 = "player";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar8 = *pcVar6 == *pcVar7;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar8);
    if (!bVar8) {
      return;
    }
    gpGlobals->found_secrets = gpGlobals->found_secrets + 1.0;
    peVar4 = (in_EAX->super_CBaseEntity).pev;
  }
  if (peVar4->noise != 0) {
    EMIT_SOUND_DYN(peVar4->pContainingEntity,2,pcVar2 + peVar4->noise,1.0,0.8,0,100);
  }
  this_00 = &in_EAX[1].super_CBaseEntity.is_undercover;
  EHANDLE::operator=((EHANDLE *)this_00,in_EDX);
  pActivator_00 = EHANDLE::operator_CBaseEntity_((EHANDLE *)this_00);
  CBaseDelay::SUB_UseTargets(in_EAX,pActivator_00,USE_TOGGLE,0.0);
  peVar4 = (in_EAX->super_CBaseEntity).pev;
  if ((peVar4->message == 0) || ((in_EDX->pev->flags & 8) == 0)) {
    p_Var1 = in_EAX[1].super_CBaseEntity.m_pfnUse.__pfn;
    pgVar3 = gpGlobals;
  }
  else {
    UTIL_ShowMessage(gpGlobals->pStringBase + peVar4->message,in_EDX->pev->pContainingEntity);
    peVar4 = (in_EAX->super_CBaseEntity).pev;
    p_Var1 = in_EAX[1].super_CBaseEntity.m_pfnUse.__pfn;
    pgVar3 = gpGlobals;
  }
  gpGlobals = pgVar3;
  if (0.0 < (float)p_Var1) {
    (in_EAX->super_CBaseEntity).m_pfnThink.__pfn = MultiWaitOver;
    (in_EAX->super_CBaseEntity).m_pfnThink.__delta = 0;
    peVar4->nextthink = (float)p_Var1 + pgVar3->time;
  }
  else {
    (in_EAX->super_CBaseEntity).m_pfnTouch.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
    (in_EAX->super_CBaseEntity).m_pfnTouch.__delta = 0;
    peVar4->nextthink = pgVar3->time + 0.1;
    (in_EAX->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (in_EAX->super_CBaseEntity).m_pfnThink.__delta = 0;
  }
  return;
}


// CBaseTrigger::ActivateMultiTrigger  @ 0014baf0  (line 1061)

/* DWARF original prototype: void ActivateMultiTrigger(CBaseTrigger * this, CBaseEntity *
   pActivator) */

void __thiscall CBaseTrigger::ActivateMultiTrigger(CBaseTrigger *this,CBaseEntity *pActivator)

{
  int iVar1;
  
  if (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      nextthink <= gpGlobals->time) {
    iVar1 = UTIL_IsMasterTriggered((this->super_CBaseToggle).m_sMaster);
    if (iVar1 != 0) {
      ActivateMultiTrigger(this,pActivator);
      return;
    }
  }
  return;
}


// CBaseTrigger::MultiWaitOver  @ 00148150  (line 1109)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void MultiWaitOver(CBaseTrigger * this) */

void __thiscall CBaseTrigger::MultiWaitOver(CBaseTrigger *this)

{
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  return;
}


// CBaseTrigger::CounterUse  @ 0014a640  (line 1126)

/* DWARF original prototype: void CounterUse(CBaseTrigger * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CBaseTrigger::CounterUse
          (CBaseTrigger *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  int *piVar1;
  EHANDLE *this_00;
  int iVar2;
  CBaseEntity *pCVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  bool bVar7;
  byte bVar8;
  
  bVar8 = 0;
  piVar1 = &(this->super_CBaseToggle).m_cTriggersLeft;
                    /* Unresolved local var: BOOL fTellActivator@[???] */
  *piVar1 = *piVar1 + -1;
  this_00 = &(this->super_CBaseToggle).m_hActivator;
  EHANDLE::operator=(this_00,pActivator);
  if (-1 < (this->super_CBaseToggle).m_cTriggersLeft) {
                    /* Unresolved local var: BOOL fTellActivator@[???] */
    iVar2 = EHANDLE::operator_int(this_00);
    bVar7 = false;
    if (iVar2 != 0) {
      bVar7 = false;
      pCVar3 = EHANDLE::operator->(this_00);
      iVar2 = 7;
      bVar6 = gpGlobals->pStringBase + pCVar3->pev->classname == (char *)0x0;
      pcVar4 = gpGlobals->pStringBase + pCVar3->pev->classname;
      pcVar5 = "player";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + (uint)bVar8 * -2 + 1;
        pcVar5 = pcVar5 + (uint)bVar8 * -2 + 1;
      } while (bVar6);
      if (bVar6) {
        bVar7 = (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev)->spawnflags & 1) == 0;
      }
    }
    iVar2 = (this->super_CBaseToggle).m_cTriggersLeft;
    if (iVar2 == 0) {
      if (bVar7) {
        (*g_engfuncs.pfnAlertMessage)(at_console,"Sequence completed!");
      }
      EHANDLE::operator_CBaseEntity_(this_00);
      if (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
          nextthink <= gpGlobals->time) {
        iVar2 = UTIL_IsMasterTriggered((this->super_CBaseToggle).m_sMaster);
        if (iVar2 != 0) {
          ActivateMultiTrigger(this,pActivator);
          return;
        }
      }
    }
    else if (bVar7) {
      if (iVar2 == 2) {
        pActivator = (CBaseEntity *)s_Only_2_more_to_go____00194c53;
      }
      else if (iVar2 == 3) {
        pActivator = (CBaseEntity *)s_Only_3_more_to_go____00194c68;
      }
      else if (iVar2 == 1) {
        pActivator = (CBaseEntity *)s_Only_1_more_to_go____00194c3e;
      }
      else {
        pActivator = (CBaseEntity *)s_There_are_more_to_go____00194c7d;
      }
                    /* WARNING: Could not recover jumptable at 0x0014a727. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*g_engfuncs.pfnAlertMessage)(at_console,(char *)pActivator);
      return;
    }
  }
  return;
}


// trigger_counter  @ 0014bb60  (line 1172)

void trigger_counter(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x514,pev);
  *puVar1 = &PTR__CTriggerCounter_00196028;
  puVar1[1] = pev;
  return;
}


// CTriggerCounter::Spawn  @ 00148170  (line 1175)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTriggerCounter * this) */

void __thiscall CTriggerCounter::Spawn(CTriggerCounter *this)

{
  int iVar1;
  
  iVar1 = (this->super_CBaseTrigger).super_CBaseToggle.m_cTriggersLeft;
  (this->super_CBaseTrigger).super_CBaseToggle.m_flWait = -1.0;
  if (iVar1 == 0) {
    (this->super_CBaseTrigger).super_CBaseToggle.m_cTriggersLeft = 2;
  }
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__pfn = CBaseTrigger::CounterUse;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__delta = 0;
  return;
}


// trigger_transition  @ 0014bbd0  (line 1193)

void trigger_transition(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x474,pev);
  *puVar1 = &PTR__CTriggerVolume_00196148;
  puVar1[1] = pev;
  return;
}


// CTriggerVolume::Spawn  @ 001481b0  (line 1197)

/* DWARF original prototype: void Spawn(CTriggerVolume * this) */

void __thiscall CTriggerVolume::Spawn(CTriggerVolume *this)

{
  entvars_t *peVar1;
  
  ((this->super_CPointEntity).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0;
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar1->pContainingEntity,gpGlobals->pStringBase + peVar1->model);
  ((this->super_CPointEntity).super_CBaseEntity.pev)->model = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->modelindex = 0;
  return;
}


// CFireAndDie::ObjectCaps  @ 0014d700  (line 1213)

/* DWARF original prototype: int ObjectCaps(CFireAndDie * this) */

int __thiscall CFireAndDie::ObjectCaps(CFireAndDie *this)

{
  return 0x82;
}


// fireanddie  @ 0014bc40  (line 1215)

void fireanddie(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x47c,pev);
  *puVar1 = &PTR__CFireAndDie_00196268;
  puVar1[1] = pev;
  return;
}


// CFireAndDie::Spawn  @ 00148220  (line 1219)

/* DWARF original prototype: void Spawn(CFireAndDie * this) */

void __thiscall CFireAndDie::Spawn(CFireAndDie *this)

{
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->classname =
       (string_t)("?fireanddie" + (1 - (int)gpGlobals->pStringBase));
  return;
}


// CFireAndDie::Precache  @ 00148240  (line 1227)

/* DWARF original prototype: void Precache(CFireAndDie * this) */

void __thiscall CFireAndDie::Precache(CFireAndDie *this)

{
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->nextthink =
       gpGlobals->time + (this->super_CBaseDelay).m_flDelay;
  return;
}


// CFireAndDie::Think  @ 00148710  (line 1232)

/* DWARF original prototype: void Think(CFireAndDie * this) */

void __thiscall CFireAndDie::Think(CFireAndDie *this)

{
  CBaseDelay::SUB_UseTargets(&this->super_CBaseDelay,(CBaseEntity *)this,USE_TOGGLE,0.0);
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// trigger_changelevel  @ 0014bcb0  (line 1265)

void trigger_changelevel(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x55c,pev);
  *puVar1 = &PTR__CChangeLevel_00196388;
  puVar1[1] = pev;
  return;
}


// CChangeLevel::Restore  @ 00148bb0  (line 1276)

/* DWARF original prototype: int Restore(CChangeLevel * this, CRestore * restore) */

int __thiscall CChangeLevel::Restore(CChangeLevel *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Restore((CBaseToggle *)this,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CChangeLevel",this,m_SaveData,4);
  }
  return iVar2;
}


// CChangeLevel::Save  @ 00148e50  (line 1276)

/* DWARF original prototype: int Save(CChangeLevel * this, CSave * save) */

int __thiscall CChangeLevel::Save(CChangeLevel *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Save((CBaseToggle *)this,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CChangeLevel",this,m_SaveData,4);
  }
  return iVar2;
}


// CChangeLevel::KeyValue  @ 0014a080  (line 1283)

/* DWARF original prototype: void KeyValue(CChangeLevel * this, KeyValueData * pkvd) */

void __thiscall CChangeLevel::KeyValue(CChangeLevel *this,KeyValueData *pkvd)

{
  size_t sVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  double dVar7;
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar2 = 4;
  pcVar4 = pkvd->szKeyName;
  pcVar3 = pcVar4;
  pcVar5 = "map";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar3 == *pcVar5;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    pcVar4 = pkvd->szValue;
    sVar1 = strlen(pcVar4);
    if (0x1f < sVar1) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Map name \'%s\' too long (32 chars)\n");
      pcVar4 = pkvd->szValue;
    }
    strcpy(this->m_szMapName,pcVar4);
    pkvd->fHandled = 1;
  }
  else {
    iVar2 = 9;
    pcVar3 = pcVar4;
    pcVar5 = "landmark";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar3 == *pcVar5;
      pcVar3 = pcVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      pcVar4 = pkvd->szValue;
      sVar1 = strlen(pcVar4);
      if (0x1f < sVar1) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Landmark name \'%s\' too long (32 chars)\n");
        pcVar4 = pkvd->szValue;
      }
      strcpy(this->m_szLandmarkName,pcVar4);
      pkvd->fHandled = 1;
    }
    else {
      iVar2 = 0xd;
      pcVar3 = pcVar4;
      pcVar5 = "changetarget";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        iVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
        this->m_changeTarget = iVar2;
        pkvd->fHandled = 1;
      }
      else {
        iVar2 = 0xc;
        bVar6 = false;
        pcVar3 = "changedelay";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar6 = *pcVar4 == *pcVar3;
          pcVar4 = pcVar4 + 1;
          pcVar3 = pcVar3 + 1;
        } while (bVar6);
        if (!bVar6) {
          CBaseTrigger::KeyValue(&this->super_CBaseTrigger,pkvd);
          return;
        }
        dVar7 = strtod(pkvd->szValue,(char **)0x0);
        this->m_changeTargetDelay = (float)dVar7;
        pkvd->fHandled = 1;
      }
    }
  }
  return;
}


// CChangeLevel::Spawn  @ 0014b310  (line 1318)

/* DWARF original prototype: void Spawn(CChangeLevel * this) */

void __thiscall CChangeLevel::Spawn(CChangeLevel *this)

{
  char cVar1;
  
  if (this->m_szMapName[0] == '\0') {
    (*g_engfuncs.pfnAlertMessage)(at_console,"a trigger_changelevel doesn\'t have a map");
    cVar1 = this->m_szLandmarkName[0];
  }
  else {
    cVar1 = this->m_szLandmarkName[0];
  }
  if (cVar1 == '\0') {
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"trigger_changelevel to %s doesn\'t have a landmark",this->m_szMapName);
  }
  if (((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->targetname != 0) {
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__pfn = UseChangeLevel;
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__delta = 0;
  }
  CBaseTrigger::InitTrigger(&this->super_CBaseTrigger);
  if ((((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->spawnflags & 2) == 0) {
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnTouch.__pfn = TouchChangeLevel;
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnTouch.__delta = 0;
  }
  return;
}


// CChangeLevel::ExecuteChangeLevel  @ 00148260  (line 1337)

/* DWARF original prototype: void ExecuteChangeLevel(CChangeLevel * this) */

void __thiscall CChangeLevel::ExecuteChangeLevel(CChangeLevel *this)

{
  (*g_engfuncs.pfnMessageBegin)(2,0x20,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(3);
  (*g_engfuncs.pfnWriteByte)(3);
  (*g_engfuncs.pfnMessageEnd)();
  (*g_engfuncs.pfnMessageBegin)(2,0x1e,(float *)0x0,(edict_t *)0x0);
                    /* WARNING: Could not recover jumptable at 0x001482cf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CChangeLevel::FindLandmark  @ 0014bd20  (line 1352)

edict_t * CChangeLevel::FindLandmark(char *pLandmarkName)

{
  edict_t *peVar1;
  int iVar2;
  entvars_t *peVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
                    /* Unresolved local var: edict_t * pentLandmark@[???] */
  peVar1 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"targetname",pLandmarkName);
  do {
    if ((peVar1 == (edict_t *)0x0) ||
       (iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1), iVar2 == 0)) {
                    /* Unresolved local var: edict_t * pentLandmark@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_error,"Can\'t find landmark %s\n",pLandmarkName);
      return (edict_t *)0x0;
    }
    iVar2 = 0xe;
    peVar3 = &peVar1->v;
    if (peVar1 == (edict_t *)0x0) {
      peVar3 = (entvars_t *)0x0;
    }
    bVar6 = gpGlobals->pStringBase + peVar3->classname == (char *)0x0;
    pcVar4 = gpGlobals->pStringBase + peVar3->classname;
    pcVar5 = "info_landmark";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
      pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
    } while (bVar6);
    if (bVar6) {
      return peVar1;
    }
    peVar1 = (*g_engfuncs.pfnFindEntityByString)(peVar1,"targetname",pLandmarkName);
  } while( true );
}


// CChangeLevel::UseChangeLevel  @ 0014c160  (line 1376)

/* DWARF original prototype: void UseChangeLevel(CChangeLevel * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CChangeLevel::UseChangeLevel
          (CChangeLevel *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  char *pcVar1;
  globalvars_t *pgVar2;
  char *pcVar3;
  edict_t *peVar4;
  uint uVar5;
  int iVar6;
  string_t sVar7;
  undefined4 *puVar8;
  entvars_t *peVar9;
  CBaseEntity *pEntity;
  
  pgVar2 = gpGlobals;
  if (gpGlobals->deathmatch != 0.0) {
    pcVar1 = this->m_szMapName;
    if (this->m_szMapName[0] == '\0') {
      sVar7 = (*g_engfuncs.pfnAllocString)("2fort");
      pgVar2->mapname = sVar7;
      builtin_strncpy(this->m_szMapName,"2for",4);
      this->m_szMapName[4] = 't';
      this->m_szMapName[5] = '\0';
    }
    pcVar3 = strstr(pcVar1,".bsp");
    if (pcVar3 == (char *)0x0) {
      strcpy(st_szNextMap,pcVar1);
    }
    else {
      strncpy(st_szNextMap,pcVar1,(int)pcVar3 - (int)pcVar1);
    }
LAB_0014be52:
                    /* WARNING: Could not recover jumptable at 0x0014be79. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnChangeLevel)(st_szNextMap,(char *)0x0);
    return;
  }
  peVar9 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (gpGlobals->time != peVar9->dmgtime) {
    peVar9->dmgtime = gpGlobals->time;
    peVar4 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
    if ((peVar4 == (edict_t *)0x0) &&
       (peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar4 == (edict_t *)0x0)) {
      pEntity = (CBaseEntity *)0x0;
    }
    else {
      pEntity = peVar4->pvPrivateData;
    }
    pcVar1 = this->m_szLandmarkName;
    uVar5 = (*pEntity->_vptr_CBaseEntity[7])(pEntity);
    if (((uVar5 & 0x80) != 0) || (iVar6 = InTransitionVolume(pEntity,pcVar1), iVar6 != 0)) {
      if (this->m_changeTarget != 0) {
        peVar4 = (*g_engfuncs.pfnCreateEntity)();
        peVar9 = (entvars_t *)0x0;
        if (peVar4 != (edict_t *)0x0) {
          peVar9 = &peVar4->v;
        }
        if ((peVar9->pContainingEntity == (edict_t *)0x0) ||
           (puVar8 = peVar9->pContainingEntity->pvPrivateData, puVar8 == (undefined4 *)0x0)) {
          puVar8 = CBaseEntity::operator_new(0x47c,peVar9);
          *puVar8 = &PTR__CFireAndDie_00196268;
          puVar8[1] = peVar9;
        }
        else {
          peVar9 = (entvars_t *)puVar8[1];
        }
        peVar9->target = this->m_changeTarget;
        puVar8[0x11d] = this->m_changeTargetDelay;
        iVar6 = puVar8[1];
        peVar9 = pEntity->pev;
        *(vec_t *)(iVar6 + 8) = (peVar9->origin).x;
        *(vec_t *)(iVar6 + 0xc) = (peVar9->origin).y;
        *(vec_t *)(iVar6 + 0x10) = (peVar9->origin).z;
        DispatchSpawn(*(edict_t **)(puVar8[1] + 0x208));
      }
      strcpy(st_szNextMap,this->m_szMapName);
      EHANDLE::operator=(&(this->super_CBaseTrigger).super_CBaseToggle.m_hActivator,pActivator);
      CBaseDelay::SUB_UseTargets((CBaseDelay *)this,pActivator,USE_TOGGLE,0.0);
      st_szNextSpot[0] = '\0';
      peVar4 = FindLandmark(pcVar1);
      if ((peVar4 != (edict_t *)0x0) &&
         (iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4), iVar6 != 0)) {
        strcpy(st_szNextSpot,pcVar1);
        pgVar2 = gpGlobals;
        (gpGlobals->vecLandmarkOffset).x = (peVar4->v).origin.x;
        (pgVar2->vecLandmarkOffset).y = (peVar4->v).origin.y;
        (pgVar2->vecLandmarkOffset).z = (peVar4->v).origin.z;
      }
      (*g_engfuncs.pfnAlertMessage)(at_console,"CHANGE LEVEL: %s %s\n",st_szNextMap,st_szNextSpot);
      goto LAB_0014be52;
    }
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"Player isn\'t in the transition volume %s, aborting\n",pcVar1);
  }
  return;
}


// CChangeLevel::ChangeLevelNow  @ 0014bde0  (line 1380)

/* DWARF original prototype: void ChangeLevelNow(CChangeLevel * this, CBaseEntity * pActivator) */

void __thiscall CChangeLevel::ChangeLevelNow(CChangeLevel *this,CBaseEntity *pActivator)

{
  char *pcVar1;
  globalvars_t *pgVar2;
  char *pcVar3;
  edict_t *peVar4;
  uint uVar5;
  int iVar6;
  string_t sVar7;
  undefined4 *puVar8;
  entvars_t *peVar9;
  CBaseEntity *pEntity;
  
  pgVar2 = gpGlobals;
                    /* Unresolved local var: edict_t * pentLandmark@[???]
                       Unresolved local var: LEVELLIST[16] levels@[???]
                       Unresolved local var: CBaseEntity * pPlayer@[DW_OP_reg7(EDI)] */
  if (gpGlobals->deathmatch != 0.0) {
                    /* Unresolved local var: char * pDot@[DW_OP_reg0(EAX)] */
    pcVar1 = this->m_szMapName;
    if (this->m_szMapName[0] == '\0') {
      sVar7 = (*g_engfuncs.pfnAllocString)("2fort");
      pgVar2->mapname = sVar7;
      builtin_strncpy(this->m_szMapName,"2for",4);
      this->m_szMapName[4] = 't';
      this->m_szMapName[5] = '\0';
    }
    pcVar3 = strstr(pcVar1,".bsp");
    if (pcVar3 == (char *)0x0) {
      strcpy(st_szNextMap,pcVar1);
    }
    else {
      strncpy(st_szNextMap,pcVar1,(int)pcVar3 - (int)pcVar1);
    }
LAB_0014be52:
                    /* WARNING: Could not recover jumptable at 0x0014be79. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnChangeLevel)(st_szNextMap,(char *)0x0);
    return;
  }
  peVar9 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (gpGlobals->time != peVar9->dmgtime) {
    peVar9->dmgtime = gpGlobals->time;
    peVar4 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar4 == (edict_t *)0x0) &&
       (peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar4 == (edict_t *)0x0)) {
      pEntity = (CBaseEntity *)0x0;
    }
    else {
      pEntity = peVar4->pvPrivateData;
    }
                    /* Unresolved local var: edict_t * pentVolume@[???]
                       Unresolved local var: int inVolume@[DW_OP_reg0(EAX)] */
    pcVar1 = this->m_szLandmarkName;
    uVar5 = (*pEntity->_vptr_CBaseEntity[7])(pEntity);
    if (((uVar5 & 0x80) != 0) || (iVar6 = InTransitionVolume(pEntity,pcVar1), iVar6 != 0)) {
      if (this->m_changeTarget != 0) {
                    /* Unresolved local var: CFireAndDie * pFireAndDie@[DW_OP_reg0(EAX)]
                       Unresolved local var: entvars_t * pev@[???] */
        peVar4 = (*g_engfuncs.pfnCreateEntity)();
        peVar9 = (entvars_t *)0x0;
        if (peVar4 != (edict_t *)0x0) {
          peVar9 = &peVar4->v;
        }
        if ((peVar9->pContainingEntity == (edict_t *)0x0) ||
           (puVar8 = peVar9->pContainingEntity->pvPrivateData, puVar8 == (undefined4 *)0x0)) {
          puVar8 = CBaseEntity::operator_new(0x47c,peVar9);
          *puVar8 = &PTR__CFireAndDie_00196268;
          puVar8[1] = peVar9;
        }
        else {
          peVar9 = (entvars_t *)puVar8[1];
        }
        peVar9->target = this->m_changeTarget;
        puVar8[0x11d] = this->m_changeTargetDelay;
        iVar6 = puVar8[1];
        peVar9 = pEntity->pev;
        *(vec_t *)(iVar6 + 8) = (peVar9->origin).x;
        *(vec_t *)(iVar6 + 0xc) = (peVar9->origin).y;
        *(vec_t *)(iVar6 + 0x10) = (peVar9->origin).z;
        DispatchSpawn(*(edict_t **)(puVar8[1] + 0x208));
      }
      strcpy(st_szNextMap,this->m_szMapName);
      EHANDLE::operator=(&(this->super_CBaseTrigger).super_CBaseToggle.m_hActivator,pActivator);
      CBaseDelay::SUB_UseTargets((CBaseDelay *)this,pActivator,USE_TOGGLE,0.0);
      st_szNextSpot[0] = '\0';
      peVar4 = FindLandmark(pcVar1);
      if ((peVar4 != (edict_t *)0x0) &&
         (iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4), iVar6 != 0)) {
        strcpy(st_szNextSpot,pcVar1);
        pgVar2 = gpGlobals;
        (gpGlobals->vecLandmarkOffset).x = (peVar4->v).origin.x;
        (pgVar2->vecLandmarkOffset).y = (peVar4->v).origin.y;
        (pgVar2->vecLandmarkOffset).z = (peVar4->v).origin.z;
      }
      (*g_engfuncs.pfnAlertMessage)(at_console,"CHANGE LEVEL: %s %s\n",st_szNextMap,st_szNextSpot);
      goto LAB_0014be52;
    }
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"Player isn\'t in the transition volume %s, aborting\n",pcVar1);
  }
  return;
}


// CChangeLevel::TouchChangeLevel  @ 0014c100  (line 1456)

/* DWARF original prototype: void TouchChangeLevel(CChangeLevel * this, CBaseEntity * pOther) */

void __thiscall CChangeLevel::TouchChangeLevel(CChangeLevel *this,CBaseEntity *pOther)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  iVar1 = 7;
  bVar4 = gpGlobals->pStringBase + pOther->pev->classname == (char *)0x0;
  pcVar2 = gpGlobals->pStringBase + pOther->pev->classname;
  pcVar3 = "player";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (!bVar4) {
    return;
  }
  ChangeLevelNow(this,pOther);
  return;
}


// CChangeLevel::AddTransitionToList  @ 0014c170  (line 1467)

int CChangeLevel::AddTransitionToList
              (LEVELLIST *pLevelList,int listCount,char *pMapName,char *pLandmarkName,
              edict_t *pentLandmark)

{
  int iVar1;
  LEVELLIST *pLVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if ((((pMapName != (char *)0x0) && (pLevelList != (LEVELLIST *)0x0)) &&
      (pentLandmark != (edict_t *)0x0)) && (pLandmarkName != (char *)0x0)) {
    if (0 < listCount) {
      iVar3 = 0;
      pLVar2 = pLevelList;
      do {
        if ((pLVar2->pentLandmark == pentLandmark) &&
           (iVar1 = strcmp(pLVar2->mapName,pMapName), iVar1 == 0)) {
          return 0;
        }
        iVar3 = iVar3 + 1;
        pLVar2 = pLVar2 + 1;
      } while (iVar3 != listCount);
    }
    pLVar2 = pLevelList + listCount;
    strcpy(pLVar2->mapName,pMapName);
    strcpy(pLVar2->landmarkName,pLandmarkName);
    pLVar2->pentLandmark = pentLandmark;
    (pLVar2->vecLandmarkOrigin).x = (pentLandmark->v).origin.x;
    (pLVar2->vecLandmarkOrigin).y = (pentLandmark->v).origin.y;
    (pLVar2->vecLandmarkOrigin).z = (pentLandmark->v).origin.z;
    return 1;
  }
  return 0;
}


// BuildChangeList  @ 0014c610  (line 1488)

int BuildChangeList(LEVELLIST *pLevelList,int maxList)

{
  CBaseEntity *pCVar1;
  edict_t *peVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *pdata;
  uint uVar7;
  edict_t *peVar8;
  undefined4 *puVar9;
  entvars_t *pev;
  LEVELLIST *pLStack_103c;
  int iStack_1034;
  int iStack_1030;
  uint auStack_102c [515];
  undefined4 auStack_820 [512];
  CSaveRestoreBuffer aCStack_20 [4];
  
  peVar2 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"classname","trigger_changelevel");
  iStack_1030 = 0;
  if ((peVar2 != (edict_t *)0x0) &&
     (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2), iVar3 != 0)) {
    iStack_1030 = 0;
    while (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2), iVar3 != 0) {
      pev = &peVar2->v;
      if (peVar2 == (edict_t *)0x0) {
        peVar8 = (*g_engfuncs.pfnCreateEntity)();
        pev = &peVar8->v;
        if (peVar8 == (edict_t *)0x0) {
          pev = (entvars_t *)0x0;
        }
      }
      if ((pev->pContainingEntity == (edict_t *)0x0) ||
         (puVar9 = pev->pContainingEntity->pvPrivateData, puVar9 == (undefined4 *)0x0)) {
        puVar9 = CBaseEntity::operator_new(0x55c,pev);
        *puVar9 = &PTR__CChangeLevel_00196388;
        puVar9[1] = pev;
      }
      peVar8 = CChangeLevel::FindLandmark((char *)(puVar9 + 0x14d));
      if ((((peVar8 != (edict_t *)0x0) &&
           (iVar3 = CChangeLevel::AddTransitionToList
                              (pLevelList,iStack_1030,(char *)(puVar9 + 0x145),
                               (char *)(puVar9 + 0x14d),peVar8), iVar3 != 0)) &&
          (iStack_1030 = iStack_1030 + 1, maxList <= iStack_1030)) ||
         (peVar2 = (*g_engfuncs.pfnFindEntityByString)(peVar2,"classname","trigger_changelevel"),
         peVar2 == (edict_t *)0x0)) break;
    }
    pdata = gpGlobals->pSaveData;
    if (((SAVERESTOREDATA *)pdata != (SAVERESTOREDATA *)0x0) &&
       (((SAVERESTOREDATA *)pdata)->pTable != (ENTITYTABLE *)0x0)) {
      CSaveRestoreBuffer::CSaveRestoreBuffer(aCStack_20,(SAVERESTOREDATA *)pdata);
      if (0 < iStack_1030) {
        pLStack_103c = pLevelList;
        iStack_1034 = 0;
        do {
          iVar3 = 0;
          peVar2 = (*g_engfuncs.pfnEntitiesInPVS)(pLStack_103c->pentLandmark);
          if (peVar2 != (edict_t *)0x0) {
            do {
              iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2);
              if (iVar4 == 0) break;
              peVar8 = peVar2;
              if (((peVar2 != (edict_t *)0x0) ||
                  (peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar8 != (edict_t *)0x0)) &&
                 ((pCVar1 = peVar8->pvPrivateData, pCVar1 != (CBaseEntity *)0x0 &&
                  (uVar7 = (*pCVar1->_vptr_CBaseEntity[7])(pCVar1), -1 < (int)uVar7)))) {
                uVar5 = ~-(uint)((uVar7 & 2) == 0) & 0x20000000;
                if (((pCVar1->pev->globalname != 0) &&
                    (iVar4 = CBaseEntity::IsDormant(pCVar1),
                    uVar7 = (-(uint)((uVar7 & 2) == 0) & 0xe0000000) + 0x30000000, iVar4 == 0)) ||
                   (uVar7 = uVar5, uVar5 != 0)) {
                  auStack_820[iVar3] = pCVar1;
                  auStack_102c[iVar3] = uVar7;
                  iVar3 = iVar3 + 1;
                  if (0x200 < iVar3) {
                    pdata = "Too many entities across a transition!";
                    (*g_engfuncs.pfnAlertMessage)(at_error,"Too many entities across a transition!")
                    ;
                  }
                }
              }
              peVar2 = (peVar2->v).chain;
            } while (peVar2 != (edict_t *)0x0);
            if (iVar3 != 0) {
              iVar4 = 0;
              do {
                while (uVar7 = auStack_102c[iVar4], uVar7 == 0) {
LAB_0014c3c0:
                  iVar4 = iVar4 + 1;
                  if (iVar4 == iVar3) goto LAB_0014c430;
                }
                pCVar1 = (CBaseEntity *)auStack_820[iVar4];
                uVar5 = (*pCVar1->_vptr_CBaseEntity[7])(pCVar1);
                if (((uVar5 & 0x80) == 0) &&
                   (iVar6 = CChangeLevel::InTransitionVolume(pCVar1,pLStack_103c->landmarkName),
                   iVar6 == 0)) goto LAB_0014c3c0;
                iVar4 = iVar4 + 1;
                pdata = (char *)CSaveRestoreBuffer::EntityIndex(aCStack_20,pCVar1);
                CSaveRestoreBuffer::EntityFlagsSet
                          (aCStack_20,(int)pdata,uVar7 | 1 << ((byte)iStack_1034 & 0x1f));
              } while (iVar4 != iVar3);
            }
          }
LAB_0014c430:
          iStack_1034 = iStack_1034 + 1;
          pLStack_103c = pLStack_103c + 1;
        } while (iStack_1034 != iStack_1030);
      }
      CSaveRestoreBuffer::~CSaveRestoreBuffer(aCStack_20,(int)pdata);
    }
  }
  return iStack_1030;
}


// CChangeLevel::InTransitionVolume  @ 001494f0  (line 1492)

int __regparm3 CChangeLevel::InTransitionVolume(CBaseEntity *pEntity,char *pVolumeName)

{
  CBaseEntity *this;
  edict_t *peVar1;
  int iVar2;
  edict_t *peVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  byte bVar7;
  CBaseEntity *local_24;
  int local_20;
  
  bVar7 = 0;
                    /* Unresolved local var: edict_t * pentVolume@[???]
                       Unresolved local var: int inVolume@[???] */
  local_24 = pEntity;
  if ((pEntity->pev->movetype == 0xc) && (peVar1 = pEntity->pev->aiment, peVar1 != (edict_t *)0x0))
  {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    local_24 = peVar1->pvPrivateData;
  }
  peVar1 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"targetname",pVolumeName);
  local_20 = 1;
  if (peVar1 != (edict_t *)0x0) {
    while (iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1), iVar2 != 0) {
                    /* Unresolved local var: CBaseEntity * pVolume@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      peVar3 = peVar1;
      if (((peVar1 != (edict_t *)0x0) ||
          (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 != (edict_t *)0x0)) &&
         (this = peVar3->pvPrivateData, this != (CBaseEntity *)0x0)) {
        bVar6 = gpGlobals->pStringBase + this->pev->classname == (char *)0x0;
        iVar2 = 0x13;
        pcVar4 = gpGlobals->pStringBase + this->pev->classname;
        pcVar5 = "trigger_transition";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar6 = *pcVar4 == *pcVar5;
          pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
          pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
        } while (bVar6);
        if (bVar6) {
          iVar2 = CBaseEntity::Intersects(this,local_24);
          if (iVar2 != 0) {
            return 1;
          }
          local_20 = 0;
        }
      }
      peVar1 = (*g_engfuncs.pfnFindEntityByString)(peVar1,"targetname",pVolumeName);
      if (peVar1 == (edict_t *)0x0) {
        return local_20;
      }
    }
  }
  return local_20;
}


// CChangeLevel::InTransitionVolume  @ 0014c250  (line 1493)

int CChangeLevel::InTransitionVolume(CBaseEntity *pEntity,char *pVolumeName)

{
  uint uVar1;
  int iVar2;
  
                    /* Unresolved local var: edict_t * pentVolume@[???]
                       Unresolved local var: int inVolume@[???] */
  uVar1 = (*pEntity->_vptr_CBaseEntity[7])(pEntity);
  if ((uVar1 & 0x80) == 0) {
    iVar2 = InTransitionVolume(pEntity,pVolumeName);
    return iVar2;
  }
  return 1;
}


// CChangeLevel::ChangeList  @ 0014c2a0  (line 1536)

int CChangeLevel::ChangeList(LEVELLIST *pLevelList,int maxList)

{
  CBaseEntity *pCVar1;
  edict_t *peVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *pdata;
  uint uVar7;
  edict_t *peVar8;
  undefined4 *puVar9;
  entvars_t *pev;
  LEVELLIST *local_103c;
  int local_1034;
  int local_1030;
  uint auStack_102c [515];
  undefined4 auStack_820 [512];
  CSaveRestoreBuffer local_20 [4];
  
                    /* Unresolved local var: edict_t * pentChangelevel@[???]
                       Unresolved local var: edict_t * pentLandmark@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
  peVar2 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"classname","trigger_changelevel");
  local_1030 = 0;
  if ((peVar2 != (edict_t *)0x0) &&
     (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2), iVar3 != 0)) {
    local_1030 = 0;
    while (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2), iVar3 != 0) {
                    /* Unresolved local var: CChangeLevel * pTrigger@[DW_OP_reg6(ESI)] */
      pev = &peVar2->v;
      if (peVar2 == (edict_t *)0x0) {
        peVar8 = (*g_engfuncs.pfnCreateEntity)();
        pev = &peVar8->v;
        if (peVar8 == (edict_t *)0x0) {
          pev = (entvars_t *)0x0;
        }
      }
                    /* Unresolved local var: entvars_t * pev@[???] */
      if ((pev->pContainingEntity == (edict_t *)0x0) ||
         (puVar9 = pev->pContainingEntity->pvPrivateData, puVar9 == (undefined4 *)0x0)) {
        puVar9 = CBaseEntity::operator_new(0x55c,pev);
        *puVar9 = &PTR__CChangeLevel_00196388;
        puVar9[1] = pev;
      }
      peVar8 = FindLandmark((char *)(puVar9 + 0x14d));
      if ((((peVar8 != (edict_t *)0x0) &&
           (iVar3 = AddTransitionToList(pLevelList,local_1030,(char *)(puVar9 + 0x145),
                                        (char *)(puVar9 + 0x14d),peVar8), iVar3 != 0)) &&
          (local_1030 = local_1030 + 1, maxList <= local_1030)) ||
         (peVar2 = (*g_engfuncs.pfnFindEntityByString)(peVar2,"classname","trigger_changelevel"),
         peVar2 == (edict_t *)0x0)) break;
    }
    pdata = gpGlobals->pSaveData;
    if (((SAVERESTOREDATA *)pdata != (SAVERESTOREDATA *)0x0) &&
       (((SAVERESTOREDATA *)pdata)->pTable != (ENTITYTABLE *)0x0)) {
                    /* Unresolved local var: CSave saveHelper@[???] */
      CSaveRestoreBuffer::CSaveRestoreBuffer(local_20,(SAVERESTOREDATA *)pdata);
      if (0 < local_1030) {
        local_103c = pLevelList;
        local_1034 = 0;
        do {
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: int entityCount@[???]
                       Unresolved local var: CBaseEntity *[512] pEntList@[???]
                       Unresolved local var: int[512] entityFlags@[???]
                       Unresolved local var: edict_t * pent@[???] */
          iVar3 = 0;
          peVar2 = (*g_engfuncs.pfnEntitiesInPVS)(local_103c->pentLandmark);
          if (peVar2 != (edict_t *)0x0) {
            do {
              iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2);
              if (iVar4 == 0) break;
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg6(ESI)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
              peVar8 = peVar2;
                    /* Unresolved local var: int caps@[???] */
              if (((peVar2 != (edict_t *)0x0) ||
                  (peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar8 != (edict_t *)0x0)) &&
                 ((pCVar1 = peVar8->pvPrivateData, pCVar1 != (CBaseEntity *)0x0 &&
                  (uVar7 = (*pCVar1->_vptr_CBaseEntity[7])(pCVar1), -1 < (int)uVar7)))) {
                    /* Unresolved local var: int flags@[???] */
                uVar5 = ~-(uint)((uVar7 & 2) == 0) & 0x20000000;
                if (((pCVar1->pev->globalname != 0) &&
                    (iVar4 = CBaseEntity::IsDormant(pCVar1),
                    uVar7 = (-(uint)((uVar7 & 2) == 0) & 0xe0000000) + 0x30000000, iVar4 == 0)) ||
                   (uVar7 = uVar5, uVar5 != 0)) {
                  auStack_820[iVar3] = pCVar1;
                  auStack_102c[iVar3] = uVar7;
                  iVar3 = iVar3 + 1;
                  if (0x200 < iVar3) {
                    pdata = "Too many entities across a transition!";
                    (*g_engfuncs.pfnAlertMessage)(at_error,"Too many entities across a transition!")
                    ;
                  }
                }
              }
              peVar2 = (peVar2->v).chain;
            } while (peVar2 != (edict_t *)0x0);
            if (iVar3 != 0) {
                    /* Unresolved local var: int index@[???] */
              iVar4 = 0;
              do {
                while (uVar7 = auStack_102c[iVar4], uVar7 == 0) {
LAB_0014c3c0:
                  iVar4 = iVar4 + 1;
                  if (iVar4 == iVar3) goto LAB_0014c430;
                }
                pCVar1 = (CBaseEntity *)auStack_820[iVar4];
                    /* Unresolved local var: edict_t * pentVolume@[???]
                       Unresolved local var: int inVolume@[DW_OP_reg0(EAX)] */
                uVar5 = (*pCVar1->_vptr_CBaseEntity[7])(pCVar1);
                if (((uVar5 & 0x80) == 0) &&
                   (iVar6 = InTransitionVolume(pCVar1,local_103c->landmarkName), iVar6 == 0))
                goto LAB_0014c3c0;
                iVar4 = iVar4 + 1;
                pdata = (char *)CSaveRestoreBuffer::EntityIndex(local_20,pCVar1);
                CSaveRestoreBuffer::EntityFlagsSet
                          (local_20,(int)pdata,uVar7 | 1 << ((byte)local_1034 & 0x1f));
              } while (iVar4 != iVar3);
            }
          }
LAB_0014c430:
          local_1034 = local_1034 + 1;
          local_103c = local_103c + 1;
        } while (local_1034 != local_1030);
      }
      CSaveRestoreBuffer::~CSaveRestoreBuffer(local_20,(int)pdata);
    }
  }
  return local_1030;
}


// NextLevel  @ 0014c620  (line 1641)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NextLevel(void)

{
  edict_t *peVar1;
  globalvars_t *pgVar2;
  edict_t *peVar3;
  int iVar4;
  string_t sVar5;
  undefined4 *puVar6;
  entvars_t *pev;
  
                    /* Unresolved local var: edict_t * pent@[DW_OP_reg3(EBX)]
                       Unresolved local var: CChangeLevel * pChange@[???] */
  peVar3 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"classname","trigger_changelevel");
  if ((peVar3 == (edict_t *)0x0) ||
     (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3), iVar4 == 0)) {
    pgVar2 = gpGlobals;
                    /* Unresolved local var: entvars_t * pev@[???] */
    sVar5 = (*g_engfuncs.pfnAllocString)("start");
    pgVar2->mapname = sVar5;
    peVar3 = (*g_engfuncs.pfnCreateEntity)();
    pev = (entvars_t *)0x0;
    if (peVar3 != (edict_t *)0x0) {
      pev = &peVar3->v;
    }
    if ((pev->pContainingEntity == (edict_t *)0x0) ||
       (puVar6 = pev->pContainingEntity->pvPrivateData, puVar6 == (undefined4 *)0x0)) {
      puVar6 = CBaseEntity::operator_new(0x55c,pev);
      *puVar6 = &PTR__CChangeLevel_00196388;
      puVar6[1] = pev;
    }
    puVar6[0x145] = 0x72617473;
    *(undefined2 *)(puVar6 + 0x146) = 0x74;
  }
  else {
    peVar1 = (peVar3->v).pContainingEntity;
                    /* Unresolved local var: entvars_t * pev@[???] */
    if ((peVar1 == (edict_t *)0x0) || (puVar6 = peVar1->pvPrivateData, puVar6 == (undefined4 *)0x0))
    {
      puVar6 = CBaseEntity::operator_new(0x55c,&peVar3->v);
      *puVar6 = &PTR__CChangeLevel_00196388;
      puVar6[1] = &peVar3->v;
    }
  }
  strcpy(st_szNextMap,(char *)(puVar6 + 0x145));
  pgVar2 = gpGlobals;
  g_fGameOver = 1;
  if (*(float *)(puVar6[1] + 0x104) < gpGlobals->time) {
    puVar6[4] = CChangeLevel::ExecuteChangeLevel;
    puVar6[5] = 0;
    *(float *)(puVar6[1] + 0x104) = pgVar2->time + 0.1;
  }
  return;
}


// func_ladder  @ 0014c770  (line 1678)

void func_ladder(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x514,pev);
  *puVar1 = &PTR__CLadder_001964a8;
  puVar1[1] = pev;
  return;
}


// CLadder::KeyValue  @ 00149970  (line 1683)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void KeyValue(CLadder * this, KeyValueData * pkvd) */

void __thiscall CLadder::KeyValue(CLadder *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  double dVar8;
  
  bVar7 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar3 = 7;
  pcVar5 = pkvd->szKeyName;
  pcVar4 = pcVar5;
  pcVar6 = "damage";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar4 == *pcVar6;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    peVar1 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    dVar8 = strtod(pkvd->szValue,(char **)0x0);
    peVar1->dmg = (float)dVar8;
    pkvd->fHandled = 1;
  }
  else {
    iVar3 = 6;
    bVar7 = false;
    pcVar4 = pcVar5;
    pcVar6 = "count";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      dVar8 = strtod(pkvd->szValue,(char **)0x0);
      (this->super_CBaseTrigger).super_CBaseToggle.m_cTriggersLeft = (int)dVar8;
      pkvd->fHandled = 1;
    }
    else {
      iVar3 = 0xb;
      bVar7 = false;
      pcVar4 = "damagetype";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar5 == *pcVar4;
        pcVar5 = pcVar5 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar7);
      if (!bVar7) {
        CBaseToggle::KeyValue((CBaseToggle *)this,pkvd);
        return;
      }
      lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
      (this->super_CBaseTrigger).super_CBaseToggle.m_bitsDamageInflict = lVar2;
      pkvd->fHandled = 1;
    }
  }
  return;
}


// CLadder::Precache  @ 001482e0  (line 1691)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Precache(CLadder * this) */

void __thiscall CLadder::Precache(CLadder *this)

{
  int *piVar1;
  longdouble lVar2;
  
  ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 0;
  ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->skin = -0x10;
  lVar2 = (longdouble)(*g_engfuncs.pfnCVarGetFloat)("showtriggers");
  if (lVar2 == (longdouble)0) {
    ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->rendermode = 2;
    ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->renderamt = (float)(longdouble)0;
  }
  piVar1 = &((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 & 0xffffff7f;
  return;
}


// CLadder::Spawn  @ 00148370  (line 1705)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CLadder * this) */

void __thiscall CLadder::Spawn(CLadder *this)

{
  entvars_t *peVar1;
  
  (*(this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  peVar1 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar1->pContainingEntity,gpGlobals->pStringBase + peVar1->model);
  ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 7;
  return;
}


// trigger_push  @ 0014c7e0  (line 1722)

void trigger_push(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x514,pev);
  *puVar1 = &PTR__CTriggerPush_001965c8;
  puVar1[1] = pev;
  return;
}


// CTriggerPush::KeyValue  @ 00149960  (line 1727)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void KeyValue(CTriggerPush * this, KeyValueData * pkvd) */

void __thiscall CTriggerPush::KeyValue(CTriggerPush *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  double dVar8;
  
  bVar7 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar3 = 7;
  pcVar5 = pkvd->szKeyName;
  pcVar4 = pcVar5;
  pcVar6 = "damage";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar4 == *pcVar6;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    peVar1 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    dVar8 = strtod(pkvd->szValue,(char **)0x0);
    peVar1->dmg = (float)dVar8;
    pkvd->fHandled = 1;
  }
  else {
    iVar3 = 6;
    bVar7 = false;
    pcVar4 = pcVar5;
    pcVar6 = "count";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      dVar8 = strtod(pkvd->szValue,(char **)0x0);
      (this->super_CBaseTrigger).super_CBaseToggle.m_cTriggersLeft = (int)dVar8;
      pkvd->fHandled = 1;
    }
    else {
      iVar3 = 0xb;
      bVar7 = false;
      pcVar4 = "damagetype";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar5 == *pcVar4;
        pcVar5 = pcVar5 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar7);
      if (!bVar7) {
        CBaseToggle::KeyValue((CBaseToggle *)this,pkvd);
        return;
      }
      lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
      (this->super_CBaseTrigger).super_CBaseToggle.m_bitsDamageInflict = lVar2;
      pkvd->fHandled = 1;
    }
  }
  return;
}


// CTriggerPush::Spawn  @ 0014b240  (line 1736)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTriggerPush * this) */

void __thiscall CTriggerPush::Spawn(CTriggerPush *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((((peVar1->angles).x == g_vecZero.x) && ((peVar1->angles).y == g_vecZero.y)) &&
     ((peVar1->angles).z == g_vecZero.z)) {
    (peVar1->angles).y = 360.0;
  }
  CBaseTrigger::InitTrigger(&this->super_CBaseTrigger);
  peVar1 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->speed == 0.0) {
    peVar1->speed = 100.0;
    peVar1 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if ((peVar1->spawnflags & 2) != 0) {
    peVar1->solid = 0;
    peVar1 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__pfn = CBaseTrigger::ToggleUse;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__delta = 0;
  UTIL_SetOrigin(peVar1,&peVar1->origin);
  return;
}


// CTriggerPush::Touch  @ 001487a0  (line 1754)

/* DWARF original prototype: void Touch(CTriggerPush * this, CBaseEntity * pOther) */

void __thiscall CTriggerPush::Touch(CTriggerPush *this,CBaseEntity *pOther)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  entvars_t *peVar4;
  uint uVar5;
  float fVar6;
  int iVar7;
  BOOL BVar8;
  
                    /* Unresolved local var: entvars_t * pevToucher@[???] */
  peVar3 = pOther->pev;
  if ((((0xc < (uint)peVar3->movetype) || ((1 << ((byte)peVar3->movetype & 0x1f) & 0x1181U) == 0))
      && (peVar3->solid != 4)) &&
     ((peVar3->solid != 0 &&
      ((iVar7 = (*pOther->_vptr_CBaseEntity[10])(pOther), iVar7 != 2 ||
       (BVar8 = ActivationSucceeded((CBaseEntity *)this,(CBasePlayer *)pOther,(CBaseEntity *)0x0),
       BVar8 != 0)))))) {
    peVar4 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((peVar4->spawnflags & 1) == 0) {
                    /* Unresolved local var: Vector vecPush@[???] */
      fVar1 = peVar4->speed;
      fVar2 = (peVar4->movedir).z * fVar1;
      fVar6 = (peVar4->movedir).y * fVar1;
      fVar1 = fVar1 * (peVar4->movedir).x;
      uVar5 = peVar3->flags;
      if ((uVar5 & 0x400000) != 0) {
        fVar2 = fVar2 + (peVar3->basevelocity).z;
        fVar6 = fVar6 + (peVar3->basevelocity).y;
        fVar1 = fVar1 + (peVar3->basevelocity).x;
      }
      (peVar3->basevelocity).x = fVar1;
      (peVar3->basevelocity).y = fVar6;
      (peVar3->basevelocity).z = fVar2;
      peVar3->flags = uVar5 | 0x400000;
      return;
    }
    fVar1 = peVar4->speed;
    fVar6 = (peVar4->movedir).z * fVar1 + (peVar3->velocity).z;
    fVar2 = (peVar4->movedir).y;
    (peVar3->velocity).x = fVar1 * (peVar4->movedir).x + (peVar3->velocity).x;
    (peVar3->velocity).y = fVar2 * fVar1 + (peVar3->velocity).y;
    (peVar3->velocity).z = fVar6;
    if (0.0 < fVar6) {
      peVar3->flags = peVar3->flags & 0xfffffdff;
    }
    UTIL_Remove((CBaseEntity *)this);
    return;
  }
  return;
}


// CBaseTrigger::TeleportTouch  @ 00148900  (line 1805)

/* DWARF original prototype: void TeleportTouch(CBaseTrigger * this, CBaseEntity * pOther) */

void __thiscall CBaseTrigger::TeleportTouch(CBaseTrigger *this,CBaseEntity *pOther)

{
  entvars_t *pev;
  entvars_t *peVar1;
  uint uVar2;
  vec_t vVar3;
  vec_t vVar4;
  vec_t vVar5;
  int iVar6;
  edict_t *peVar7;
  BOOL BVar8;
  Vector local_2c [2];
  
                    /* Unresolved local var: entvars_t * pevToucher@[???]
                       Unresolved local var: edict_t * pentTarget@[???]
                       Unresolved local var: Vector tmp@[???] */
  pev = pOther->pev;
  if (((pev->flags & 0x28) != 0) &&
     (iVar6 = UTIL_IsMasterTriggered((this->super_CBaseToggle).m_sMaster), iVar6 != 0)) {
    peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    uVar2 = peVar1->spawnflags;
    if ((((uVar2 & 1) != 0) || ((pev->flags & 0x20) == 0)) &&
       (((((uVar2 & 2) == 0 || ((pev->flags & 8) == 0)) &&
         (peVar7 = (*g_engfuncs.pfnFindEntityByString)
                             ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + peVar1->target),
         peVar7 != (edict_t *)0x0)) &&
        ((iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar7), iVar6 != 0 &&
         (BVar8 = ActivationSucceeded((CBaseEntity *)this,(CBasePlayer *)pOther,(CBaseEntity *)0x0),
         BVar8 != 0)))))) {
      local_2c[0].x = (peVar7->v).origin.x;
      local_2c[0].z = (peVar7->v).origin.z;
      local_2c[0].y = (peVar7->v).origin.y;
      if ((pOther->pev->flags & 8) != 0) {
        local_2c[0].z = local_2c[0].z - (pOther->pev->mins).z;
      }
      local_2c[0].z = local_2c[0].z + 1.0;
      pev->flags = pev->flags & 0xfffffdff;
      UTIL_SetOrigin(pev,local_2c);
      iVar6 = pev->flags;
      (pev->angles).x = (peVar7->v).angles.x;
      (pev->angles).y = (peVar7->v).angles.y;
      (pev->angles).z = (peVar7->v).angles.z;
      if ((iVar6 & 8) != 0) {
        (pev->v_angle).x = (peVar7->v).angles.x;
        (pev->v_angle).y = (peVar7->v).angles.y;
        (pev->v_angle).z = (peVar7->v).angles.z;
      }
      vVar4 = g_vecZero.y;
      vVar3 = g_vecZero.x;
      pev->fixangle = 1;
      vVar5 = g_vecZero.z;
      (pev->basevelocity).x = vVar3;
      (pev->basevelocity).y = vVar4;
      (pev->basevelocity).z = vVar5;
      (pev->velocity).x = vVar3;
      (pev->velocity).y = vVar4;
      (pev->velocity).z = vVar5;
    }
  }
  return;
}


// trigger_teleport  @ 0014c850  (line 1870)

void trigger_teleport(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x514,pev);
  *puVar1 = &PTR__CTriggerTeleport_001966e8;
  puVar1[1] = pev;
  return;
}


// CTriggerTeleport::Spawn  @ 0014b210  (line 1873)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTriggerTeleport * this) */

void __thiscall CTriggerTeleport::Spawn(CTriggerTeleport *this)

{
  CBaseTrigger::InitTrigger(&this->super_CBaseTrigger);
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBaseTrigger::TeleportTouch;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// info_teleport_destination  @ 0014c8c0  (line 1880)

void info_teleport_destination(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x474,pev);
  *puVar1 = &PTR__CPointEntity_0018c688;
  puVar1[1] = pev;
  return;
}


// trigger_autosave  @ 0014c930  (line 1890)

void trigger_autosave(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x514,pev);
  *puVar1 = &PTR__CTriggerSave_00196808;
  puVar1[1] = pev;
  return;
}


// CTriggerSave::Spawn  @ 0014b1b0  (line 1893)

/* DWARF original prototype: void Spawn(CTriggerSave * this) */

void __thiscall CTriggerSave::Spawn(CTriggerSave *this)

{
  if (gpGlobals->deathmatch != 0.0) {
                    /* WARNING: Could not recover jumptable at 0x0014b206. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnRemoveEntity)
              (((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    return;
  }
  CBaseTrigger::InitTrigger(&this->super_CBaseTrigger);
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = SaveTouch;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CTriggerSave::SaveTouch  @ 00149110  (line 1905)

/* DWARF original prototype: void SaveTouch(CTriggerSave * this, CBaseEntity * pOther) */

void __thiscall CTriggerSave::SaveTouch(CTriggerSave *this,CBaseEntity *pOther)

{
  int iVar1;
  
  iVar1 = UTIL_IsMasterTriggered((this->super_CBaseTrigger).super_CBaseToggle.m_sMaster);
  if ((iVar1 != 0) && ((pOther->pev->flags & 8) != 0)) {
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnTouch.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnTouch.__delta = 0;
    UTIL_Remove((CBaseEntity *)this);
                    /* WARNING: Could not recover jumptable at 0x0014917f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnServerCommand)("autosave\n");
    return;
  }
  return;
}


// trigger_endsection  @ 0014c9a0  (line 1928)

void trigger_endsection(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x514,pev);
  *puVar1 = &PTR__CTriggerEndSection_00196928;
  puVar1[1] = pev;
  return;
}


// CTriggerEndSection::EndSectionUse  @ 001490a0  (line 1932)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void EndSectionUse(CTriggerEndSection * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CTriggerEndSection::EndSectionUse
          (CTriggerEndSection *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  entvars_t *peVar1;
  string_t sVar2;
  
  if ((pActivator->pev->flags & 8) == 0) {
    return;
  }
  peVar1 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *)0x0;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__delta = 0;
  sVar2 = peVar1->message;
  if (sVar2 == 0) {
    UTIL_Remove((CBaseEntity *)this);
    return;
  }
  (*g_engfuncs.pfnEndSection)(gpGlobals->pStringBase + sVar2);
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CTriggerEndSection::Spawn  @ 0014b140  (line 1947)

/* DWARF original prototype: void Spawn(CTriggerEndSection * this) */

void __thiscall CTriggerEndSection::Spawn(CTriggerEndSection *this)

{
  entvars_t *peVar1;
  
  if (gpGlobals->deathmatch != 0.0) {
                    /* WARNING: Could not recover jumptable at 0x0014b1ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnRemoveEntity)
              (((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    return;
  }
  CBaseTrigger::InitTrigger(&this->super_CBaseTrigger);
  peVar1 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__pfn = EndSectionUse;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__delta = 0;
  if ((peVar1->spawnflags & 1) == 0) {
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnTouch.__pfn = EndSectionTouch;
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnTouch.__delta = 0;
  }
  return;
}


// CTriggerEndSection::EndSectionTouch  @ 00149030  (line 1963)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void EndSectionTouch(CTriggerEndSection * this, CBaseEntity * pOther)
    */

void __thiscall CTriggerEndSection::EndSectionTouch(CTriggerEndSection *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  string_t sVar2;
  
  if ((pOther->pev->flags & 8) == 0) {
    return;
  }
  peVar1 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  sVar2 = peVar1->message;
  if (sVar2 == 0) {
    UTIL_Remove((CBaseEntity *)this);
    return;
  }
  (*g_engfuncs.pfnEndSection)(gpGlobals->pStringBase + sVar2);
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CTriggerEndSection::KeyValue  @ 00149980  (line 1978)

/* DWARF original prototype: void KeyValue(CTriggerEndSection * this, KeyValueData * pkvd) */

void __thiscall CTriggerEndSection::KeyValue(CTriggerEndSection *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  string_t sVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x1c;
  iVar3 = 8;
  pcVar4 = pkvd->szKeyName;
  pcVar5 = "section";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (!bVar6) {
    CBaseTrigger::KeyValue(&this->super_CBaseTrigger,pkvd);
    return;
  }
  peVar1 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  sVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
  peVar1->message = sVar2;
  pkvd->fHandled = 1;
  return;
}


// trigger_gravity  @ 0014ca10  (line 1997)

void trigger_gravity(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x514,pev);
  *puVar1 = &PTR__CTriggerGravity_00196a48;
  puVar1[1] = pev;
  return;
}


// CTriggerGravity::Spawn  @ 0014b110  (line 2000)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTriggerGravity * this) */

void __thiscall CTriggerGravity::Spawn(CTriggerGravity *this)

{
  CBaseTrigger::InitTrigger(&this->super_CBaseTrigger);
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = GravityTouch;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CTriggerGravity::GravityTouch  @ 001483c0  (line 2008)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GravityTouch(CTriggerGravity * this, CBaseEntity * pOther) */

void __thiscall CTriggerGravity::GravityTouch(CTriggerGravity *this,CBaseEntity *pOther)

{
  if ((pOther->pev->flags & 8) != 0) {
    pOther->pev->gravity =
         ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->gravity;
  }
  return;
}


// CTriggerChangeTarget::ObjectCaps  @ 0014d710  (line 2028)

/* DWARF original prototype: int ObjectCaps(CTriggerChangeTarget * this) */

int __thiscall CTriggerChangeTarget::ObjectCaps(CTriggerChangeTarget *this)

{
  return 0;
}


// trigger_changetarget  @ 0014ca80  (line 2037)

void trigger_changetarget(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x480,pev);
  *puVar1 = &PTR__CTriggerChangeTarget_00196b68;
  puVar1[1] = pev;
  return;
}


// CTriggerChangeTarget::Restore  @ 00148b50  (line 2044)

/* DWARF original prototype: int Restore(CTriggerChangeTarget * this, CRestore * restore) */

int __thiscall CTriggerChangeTarget::Restore(CTriggerChangeTarget *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseDelay::Restore(&this->super_CBaseDelay,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CTriggerChangeTarget",this,m_SaveData,1);
  }
  return iVar2;
}


// CTriggerChangeTarget::Save  @ 00148df0  (line 2044)

/* DWARF original prototype: int Save(CTriggerChangeTarget * this, CSave * save) */

int __thiscall CTriggerChangeTarget::Save(CTriggerChangeTarget *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseDelay::Save(&this->super_CBaseDelay,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CTriggerChangeTarget",this,m_SaveData,1);
  }
  return iVar2;
}


// CTriggerChangeTarget::KeyValue  @ 00149740  (line 2047)

/* DWARF original prototype: void KeyValue(CTriggerChangeTarget * this, KeyValueData * pkvd) */

void __thiscall CTriggerChangeTarget::KeyValue(CTriggerChangeTarget *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  bVar4 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar1 = 0xf;
  pcVar2 = pkvd->szKeyName;
  pcVar3 = "m_iszNewTarget";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (!bVar4) {
    CBaseDelay::KeyValue(&this->super_CBaseDelay,pkvd);
    return;
  }
  iVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
  this->m_iszNewTarget = iVar1;
  pkvd->fHandled = 1;
  return;
}


// CTriggerChangeTarget::Spawn  @ 001483f0  (line 2059)

/* DWARF original prototype: void Spawn(CTriggerChangeTarget * this) */

void __thiscall CTriggerChangeTarget::Spawn(CTriggerChangeTarget *this)

{
  return;
}


// CTriggerChangeTarget::Use  @ 001486a0  (line 2063)

/* DWARF original prototype: void Use(CTriggerChangeTarget * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CTriggerChangeTarget::Use
          (CTriggerChangeTarget *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  CBaseEntity *pCVar1;
  int iVar2;
  
                    /* Unresolved local var: CBaseEntity * pTarget@[???] */
  pCVar1 = UTIL_FindEntityByString
                     ((CBaseEntity *)0x0,"targetname",
                      gpGlobals->pStringBase +
                      ((this->super_CBaseDelay).super_CBaseEntity.pev)->target);
  if (pCVar1 != (CBaseEntity *)0x0) {
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
    pCVar1->pev->target = this->m_iszNewTarget;
    iVar2 = (*pCVar1->_vptr_CBaseEntity[0x13])(pCVar1);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 8) = 0;
    }
  }
  return;
}


// CTriggerCamera::ObjectCaps  @ 0014d720  (line 2095)

/* DWARF original prototype: int ObjectCaps(CTriggerCamera * this) */

int __thiscall CTriggerCamera::ObjectCaps(CTriggerCamera *this)

{
  return 0;
}


// trigger_camera  @ 0014caf0  (line 2113)

void trigger_camera(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x4b8,pev);
  *puVar1 = &PTR__CTriggerCamera_00196c88;
  puVar1[1] = pev;
  return;
}


// CTriggerCamera::Restore  @ 00148af0  (line 2133)

/* DWARF original prototype: int Restore(CTriggerCamera * this, CRestore * restore) */

int __thiscall CTriggerCamera::Restore(CTriggerCamera *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseDelay::Restore(&this->super_CBaseDelay,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CTriggerCamera",this,m_SaveData,0xd);
  }
  return iVar2;
}


// CTriggerCamera::Save  @ 00148d90  (line 2133)

/* DWARF original prototype: int Save(CTriggerCamera * this, CSave * save) */

int __thiscall CTriggerCamera::Save(CTriggerCamera *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseDelay::Save(&this->super_CBaseDelay,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CTriggerCamera",this,m_SaveData,0xd);
  }
  return iVar2;
}


// CTriggerCamera::Spawn  @ 00148400  (line 2136)

/* DWARF original prototype: void Spawn(CTriggerCamera * this) */

void __thiscall CTriggerCamera::Spawn(CTriggerCamera *this)

{
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->movetype = 8;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->renderamt = 0.0;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->rendermode = 2;
  this->m_initialSpeed = ((this->super_CBaseDelay).super_CBaseEntity.pev)->speed;
  if (this->m_acceleration == 0.0) {
    this->m_acceleration = 500.0;
  }
  if (this->m_deceleration == 0.0) {
    this->m_deceleration = 500.0;
  }
  return;
}


// CTriggerCamera::KeyValue  @ 00149620  (line 2151)

/* DWARF original prototype: void KeyValue(CTriggerCamera * this, KeyValueData * pkvd) */

void __thiscall CTriggerCamera::KeyValue(CTriggerCamera *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  double dVar6;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar1 = 5;
  pcVar3 = pkvd->szKeyName;
  pcVar2 = pcVar3;
  pcVar4 = "wait";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar5 = *pcVar2 == *pcVar4;
    pcVar2 = pcVar2 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    dVar6 = strtod(pkvd->szValue,(char **)0x0);
    this->m_flWait = (float)dVar6;
    pkvd->fHandled = 1;
  }
  else {
    iVar1 = 7;
    bVar5 = false;
    pcVar2 = pcVar3;
    pcVar4 = "moveto";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      iVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
      this->m_sPath = iVar1;
      pkvd->fHandled = 1;
    }
    else {
      iVar1 = 0xd;
      bVar5 = false;
      pcVar2 = pcVar3;
      pcVar4 = "acceleration";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pcVar2 == *pcVar4;
        pcVar2 = pcVar2 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        dVar6 = strtod(pkvd->szValue,(char **)0x0);
        this->m_acceleration = (float)dVar6;
        pkvd->fHandled = 1;
      }
      else {
        iVar1 = 0xd;
        bVar5 = false;
        pcVar2 = "deceleration";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar5 = *pcVar3 == *pcVar2;
          pcVar3 = pcVar3 + 1;
          pcVar2 = pcVar2 + 1;
        } while (bVar5);
        if (!bVar5) {
          CBaseDelay::KeyValue(&this->super_CBaseDelay,pkvd);
          return;
        }
        dVar6 = strtod(pkvd->szValue,(char **)0x0);
        this->m_deceleration = (float)dVar6;
        pkvd->fHandled = 1;
      }
    }
  }
  return;
}


// CTriggerCamera::Use  @ 0014d170  (line 2179)

/* DWARF original prototype: void Use(CTriggerCamera * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CTriggerCamera::Use(CTriggerCamera *this,CBaseEntity *pActivator,CBaseEntity *pCaller,
                   USE_TYPE useType,float value)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  entvars_t *peVar4;
  globalvars_t *pgVar5;
  int iVar6;
  uint uVar7;
  edict_t *peVar8;
  CBaseEntity *pCVar9;
  longdouble extraout_ST0;
  Vector local_18;
  
  iVar6 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,this->m_state);
  if (iVar6 != 0) {
    uVar7 = (uint)(this->m_state == 0);
    this->m_state = uVar7;
    if (uVar7 == 0) {
      this->m_flReturnTime = gpGlobals->time;
      return;
    }
    if ((pActivator == (CBaseEntity *)0x0) || ((pActivator->pev->flags & 8) == 0)) {
      peVar8 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((peVar8 == (edict_t *)0x0) &&
         (peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar8 == (edict_t *)0x0)) {
        pActivator = (CBaseEntity *)0x0;
      }
      else {
        pActivator = peVar8->pvPrivateData;
      }
    }
    EHANDLE::operator=(&this->m_hPlayer,pActivator);
    peVar3 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    this->m_flReturnTime = gpGlobals->time + this->m_flWait;
    peVar3->speed = this->m_initialSpeed;
    this->m_targetSpeed = this->m_initialSpeed;
    if ((((this->super_CBaseDelay).super_CBaseEntity.pev)->spawnflags & 2) == 0) {
      pCVar9 = (CBaseEntity *)
               (*(this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[0x2a])(this);
      EHANDLE::operator=(&this->m_hTarget,pCVar9);
    }
    else {
      iVar6 = (this->m_hPlayer).m_serialnumber;
      (this->m_hTarget).m_pent = (this->m_hPlayer).m_pent;
      (this->m_hTarget).m_serialnumber = iVar6;
    }
    iVar6 = EHANDLE::operator_int(&this->m_hTarget);
    if (iVar6 != 0) {
      if ((((this->super_CBaseDelay).super_CBaseEntity.pev)->spawnflags & 4) != 0) {
        CBasePlayer::EnableControl((CBasePlayer *)pActivator,0);
      }
      pgVar5 = gpGlobals;
      if (this->m_sPath == 0) {
        this->m_pentPath = (CBaseEntity *)0x0;
        this->m_flStopTime = pgVar5->time;
      }
      else {
        peVar8 = (*g_engfuncs.pfnFindEntityByString)
                           ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_sPath);
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg0(EAX)] */
        if ((peVar8 == (edict_t *)0x0) &&
           (peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar8 == (edict_t *)0x0)) {
          pCVar9 = (CBaseEntity *)0x0;
        }
        else {
          pCVar9 = peVar8->pvPrivateData;
        }
        pgVar5 = gpGlobals;
        this->m_pentPath = pCVar9;
        fVar1 = pgVar5->time;
        this->m_flStopTime = fVar1;
        if (pCVar9 != (CBaseEntity *)0x0) {
          fVar2 = pCVar9->pev->speed;
          if (fVar2 != 0.0) {
            this->m_targetSpeed = fVar2;
          }
          (*pCVar9->_vptr_CBaseEntity[0x19])(pCVar9);
          this->m_flStopTime = (float)(extraout_ST0 + (longdouble)fVar1);
        }
      }
      peVar3 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      if ((peVar3->spawnflags & 1) == 0) {
        (peVar3->velocity).x = 0.0;
        (peVar3->velocity).y = 0.0;
        (peVar3->velocity).z = 0.0;
      }
      else {
        peVar4 = (((CBasePlayer *)pActivator)->super_CBaseMonster).super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
        local_18.z = (peVar4->origin).z + (peVar4->view_ofs).z;
        local_18.y = (peVar4->origin).y + (peVar4->view_ofs).y;
        local_18.x = (peVar4->origin).x + (peVar4->view_ofs).x;
        UTIL_SetOrigin(peVar3,&local_18);
        (((this->super_CBaseDelay).super_CBaseEntity.pev)->angles).x =
             -(((((CBasePlayer *)pActivator)->super_CBaseMonster).super_CBaseToggle.
                super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles).x;
        (((this->super_CBaseDelay).super_CBaseEntity.pev)->angles).y =
             (((((CBasePlayer *)pActivator)->super_CBaseMonster).super_CBaseToggle.
               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles).y;
        (((this->super_CBaseDelay).super_CBaseEntity.pev)->angles).z = 0.0;
        peVar3 = (((CBasePlayer *)pActivator)->super_CBaseMonster).super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
        peVar4 = (this->super_CBaseDelay).super_CBaseEntity.pev;
        (peVar4->velocity).x = (peVar3->velocity).x;
        (peVar4->velocity).y = (peVar3->velocity).y;
        (peVar4->velocity).z = (peVar3->velocity).z;
      }
      (*g_engfuncs.pfnSetView)
                (((((CBasePlayer *)pActivator)->super_CBaseMonster).super_CBaseToggle.
                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
                 ((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity);
      (*g_engfuncs.pfnSetModel)
                (((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,
                 gpGlobals->pStringBase +
                 ((((CBasePlayer *)pActivator)->super_CBaseMonster).super_CBaseToggle.
                  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->model);
      pgVar5 = gpGlobals;
      (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__pfn = FollowTarget;
      peVar3 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__delta = 0;
      peVar3->nextthink = pgVar5->time;
      this->m_moveDistance = 0.0;
      Move(this);
    }
  }
  return;
}


// CTriggerCamera::FollowTarget  @ 0014ce90  (line 2268)

/* DWARF original prototype: void FollowTarget(CTriggerCamera * this) */

void __thiscall CTriggerCamera::FollowTarget(CTriggerCamera *this)

{
  EHANDLE *this_00;
  float fVar1;
  float fVar2;
  edict_t *peVar3;
  entvars_t *peVar4;
  _func_void_edict_t_ptr_edict_t_ptr *p_Var5;
  int iVar6;
  CBaseEntity *pCVar7;
  CBasePlayer *this_01;
  entvars_t *peVar8;
  globalvars_t *pgVar9;
  float fVar10;
  Vector local_3c;
  Vector local_28 [2];
  
                    /* Unresolved local var: Vector vecGoal@[???]
                       Unresolved local var: float dx@[???]
                       Unresolved local var: float dy@[???] */
  this_00 = &this->m_hPlayer;
  iVar6 = EHANDLE::operator_int(this_00);
  if (iVar6 != 0) {
                    /* Unresolved local var: Vector vecGoal@[???]
                       Unresolved local var: float dx@[???]
                       Unresolved local var: float dy@[???] */
    iVar6 = EHANDLE::operator_int(&this->m_hTarget);
    if ((iVar6 == 0) || (this->m_flReturnTime < gpGlobals->time)) {
      pCVar7 = EHANDLE::operator->(this_00);
      iVar6 = (*pCVar7->_vptr_CBaseEntity[0x22])(pCVar7);
      p_Var5 = g_engfuncs.pfnSetView;
      if (iVar6 != 0) {
        pCVar7 = EHANDLE::operator->(this_00);
        peVar3 = pCVar7->pev->pContainingEntity;
        pCVar7 = EHANDLE::operator->(this_00);
        (*p_Var5)(pCVar7->pev->pContainingEntity,peVar3);
        this_01 = (CBasePlayer *)EHANDLE::operator_CBaseEntity_(this_00);
        CBasePlayer::EnableControl(this_01,1);
      }
      CBaseDelay::SUB_UseTargets(&this->super_CBaseDelay,(CBaseEntity *)this,USE_TOGGLE,0.0);
      peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      (peVar8->avelocity).x = 0.0;
      (peVar8->avelocity).y = 0.0;
      (peVar8->avelocity).z = 0.0;
      this->m_state = 0;
    }
    else {
      peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      pCVar7 = EHANDLE::operator->(&this->m_hTarget);
      peVar4 = pCVar7->pev;
      local_28[0].z = (peVar4->origin).z - (peVar8->origin).z;
      local_28[0].y = (peVar4->origin).y - (peVar8->origin).y;
      local_28[0].x = (peVar4->origin).x - (peVar8->origin).x;
      UTIL_VecToAngles(&local_3c,local_28);
      peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      local_3c.x = -local_3c.x;
      fVar1 = (peVar8->angles).y;
      if (360.0 < fVar1) {
        (peVar8->angles).y = fVar1 - 360.0;
        peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
        fVar1 = (peVar8->angles).y;
      }
      if (fVar1 < 0.0) {
        (peVar8->angles).y = fVar1 + 360.0;
        peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
        fVar1 = (peVar8->angles).y;
      }
      pgVar9 = gpGlobals;
      fVar10 = local_3c.x - (peVar8->angles).x;
      fVar1 = local_3c.y - fVar1;
      if (fVar10 < -180.0) {
        fVar10 = fVar10 + 360.0;
      }
      if (180.0 < fVar10) {
        fVar10 = fVar10 - 360.0;
      }
      if (fVar1 < -180.0) {
        fVar1 = fVar1 + 360.0;
      }
      if (180.0 < fVar1) {
        fVar1 = fVar1 - 360.0;
      }
      (peVar8->avelocity).x = fVar10 * 40.0 * gpGlobals->frametime;
      (((this->super_CBaseDelay).super_CBaseEntity.pev)->avelocity).y =
           fVar1 * 40.0 * pgVar9->frametime;
      peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      if ((peVar8->spawnflags & 4) == 0) {
        (peVar8->velocity).x = (peVar8->velocity).x * 0.8;
        (peVar8->velocity).y = (peVar8->velocity).y * 0.8;
        (peVar8->velocity).z = (peVar8->velocity).z * 0.8;
        peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
        fVar1 = (peVar8->velocity).x;
        fVar10 = (peVar8->velocity).y;
        fVar2 = (peVar8->velocity).z;
        fVar1 = fVar2 * fVar2 + fVar10 * fVar10 + fVar1 * fVar1;
        fVar10 = SQRT(fVar1);
        if (NAN(fVar10)) {
          fVar10 = sqrtf(fVar1);
          peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
          pgVar9 = gpGlobals;
        }
        if (fVar10 < 10.0) {
          (peVar8->velocity).x = g_vecZero.x;
          (peVar8->velocity).y = g_vecZero.y;
          (peVar8->velocity).z = g_vecZero.z;
          peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
        }
      }
      peVar8->nextthink = pgVar9->time;
      Move(this);
    }
  }
  return;
}


// CTriggerCamera::Move  @ 0014cb60  (line 2324)

/* DWARF original prototype: void Move(CTriggerCamera * this) */

void __thiscall CTriggerCamera::Move(CTriggerCamera *this)

{
  float fVar1;
  float fVar2;
  string_t sVar3;
  float fVar4;
  float fVar5;
  CBaseEntity *pCVar6;
  globalvars_t *pgVar7;
  entvars_t *peVar8;
  entvars_t *peVar9;
  longdouble extraout_ST0;
  longdouble lVar10;
  float fVar11;
  float fVar12;
  
  pgVar7 = gpGlobals;
                    /* Unresolved local var: float fraction@[???] */
  pCVar6 = this->m_pentPath;
  if (pCVar6 == (CBaseEntity *)0x0) {
    return;
  }
  peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  fVar11 = this->m_moveDistance - peVar8->speed * gpGlobals->frametime;
  this->m_moveDistance = fVar11;
  if (fVar11 <= 0.0) {
    sVar3 = pCVar6->pev->message;
    if (sVar3 != 0) {
      FireTargets(pgVar7->pStringBase + sVar3,(CBaseEntity *)this,(CBaseEntity *)this,USE_TOGGLE,0.0
                 );
      pCVar6 = this->m_pentPath;
      if ((pCVar6->pev->spawnflags & 4) != 0) {
        pCVar6->pev->message = 0;
        pCVar6 = this->m_pentPath;
      }
    }
    pCVar6 = (CBaseEntity *)(*pCVar6->_vptr_CBaseEntity[0x2a])(pCVar6);
    this->m_pentPath = pCVar6;
    if (pCVar6 == (CBaseEntity *)0x0) {
      peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      (peVar8->velocity).x = g_vecZero.x;
      (peVar8->velocity).y = g_vecZero.y;
      (peVar8->velocity).z = g_vecZero.z;
      fVar11 = this->m_flStopTime;
      peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      pgVar7 = gpGlobals;
      goto LAB_0014cbab;
    }
                    /* Unresolved local var: Vector delta@[???] */
    peVar8 = pCVar6->pev;
    if (peVar8->speed != 0.0) {
      this->m_targetSpeed = peVar8->speed;
      peVar8 = pCVar6->pev;
    }
    peVar9 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    fVar1 = (peVar8->origin).z - (peVar9->origin).z;
    fVar5 = (peVar8->origin).y - (peVar9->origin).y;
    fVar2 = (peVar8->origin).x - (peVar9->origin).x;
    fVar4 = fVar1 * fVar1 + fVar5 * fVar5 + fVar2 * fVar2;
    fVar11 = SQRT(fVar4);
    fVar12 = fVar11;
    if (NAN(fVar11)) {
      fVar12 = sqrtf(fVar4);
      peVar9 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    }
    this->m_moveDistance = fVar12;
                    /* Unresolved local var: float flLen@[???] */
    if (NAN(fVar11)) {
      fVar11 = sqrtf(fVar4);
    }
    pgVar7 = gpGlobals;
    fVar4 = 0.0;
    if (fVar11 == 0.0) {
      fVar1 = 1.0;
      fVar11 = fVar4;
    }
    else {
      fVar11 = 1.0 / fVar11;
      fVar1 = fVar1 * fVar11;
      fVar4 = fVar11 * fVar2;
      fVar11 = fVar5 * fVar11;
    }
    (peVar9->movedir).x = fVar4;
    (peVar9->movedir).y = fVar11;
    (peVar9->movedir).z = fVar1;
    fVar11 = pgVar7->time;
    (*this->m_pentPath->_vptr_CBaseEntity[0x19])(this->m_pentPath);
    pgVar7 = gpGlobals;
    peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    lVar10 = extraout_ST0 + (longdouble)fVar11;
    this->m_flStopTime = (float)lVar10;
    if (lVar10 <= (longdouble)pgVar7->time) goto LAB_0014cd40;
  }
  else {
    fVar11 = this->m_flStopTime;
LAB_0014cbab:
    if (fVar11 <= pgVar7->time) {
LAB_0014cd40:
      fVar11 = UTIL_Approach(this->m_targetSpeed,peVar8->speed,
                             this->m_acceleration * pgVar7->frametime);
      peVar8->speed = fVar11;
      goto LAB_0014cbe2;
    }
  }
  fVar11 = UTIL_Approach(0.0,peVar8->speed,this->m_deceleration * pgVar7->frametime);
  peVar8->speed = fVar11;
LAB_0014cbe2:
  fVar4 = gpGlobals->frametime + gpGlobals->frametime;
  peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  fVar12 = 1.0 - fVar4;
  fVar11 = peVar8->speed;
  fVar1 = (peVar8->movedir).z;
  fVar2 = (peVar8->movedir).y;
  (peVar8->velocity).x = fVar12 * (peVar8->velocity).x + fVar11 * (peVar8->movedir).x * fVar4;
  (peVar8->velocity).y = fVar2 * fVar11 * fVar4 + (peVar8->velocity).y * fVar12;
  (peVar8->velocity).z = fVar1 * fVar11 * fVar4 + (peVar8->velocity).z * fVar12;
  return;
}


// teledeath  @ 0014d500  (line 2374)

void teledeath(entvars_t *pev)

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
  *puVar1 = &PTR__CTelefragDeath_00180268;
  puVar1[1] = pev;
  return;
}


// CTelefragDeath::Spawn  @ 0014d570  (line 2377)

/* DWARF original prototype: void Spawn(CTelefragDeath * this, CBaseEntity * pIgnore) */

void __thiscall CTelefragDeath::Spawn(CTelefragDeath *this,CBaseEntity *pIgnore)

{
  entvars_t *peVar1;
  void *pvVar2;
  int iVar3;
  globalvars_t *pgVar4;
  edict_t *peVar5;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg0(EAX)] */
  ((this->super_CBaseEntity).pev)->movetype = 0;
  ((this->super_CBaseEntity).pev)->solid = 1;
  ((this->super_CBaseEntity).pev)->effects = 0x80;
  peVar1 = (this->super_CBaseEntity).pev;
  (peVar1->angles).x = g_vecZero.x;
  (peVar1->angles).y = g_vecZero.y;
  (peVar1->angles).z = g_vecZero.z;
  peVar5 = ((this->super_CBaseEntity).pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((peVar5 != (edict_t *)0x0) ||
      (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 != (edict_t *)0x0)) &&
     (pvVar2 = peVar5->pvPrivateData, pvVar2 != (void *)0x0)) {
    iVar3 = *(int *)((int)pvVar2 + 4);
    local_18.z = *(float *)(iVar3 + 0xf0) + 4.0;
    local_18.y = *(float *)(iVar3 + 0xec) + 4.0;
    local_18.x = *(float *)(iVar3 + 0xe8) + 4.0;
    iVar3 = *(int *)((int)pvVar2 + 4);
    local_24.z = *(float *)(iVar3 + 0xe4) - 4.0;
    local_24.y = *(float *)(iVar3 + 0xe0) - 4.0;
    local_24.x = *(float *)(iVar3 + 0xdc) - 4.0;
    UTIL_SetSize((this->super_CBaseEntity).pev,&local_24,&local_18);
    pgVar4 = gpGlobals;
    (this->super_CBaseEntity).m_pfnTouch.__pfn = DeathTouch;
    peVar1 = (this->super_CBaseEntity).pev;
    (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
    peVar1->nextthink = pgVar4->time + 0.2;
    (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    this->m_pIgnore = pIgnore;
    pgVar4->force_retouch = 2.0;
  }
  return;
}


// CTelefragDeath::DeathTouch  @ 00149d30  (line 2404)

/* WARNING: Variable defined which should be unmapped: pOwner */
/* DWARF original prototype: void DeathTouch(CTelefragDeath * this, CBaseEntity * pOther) */

void __thiscall CTelefragDeath::DeathTouch(CTelefragDeath *this,CBaseEntity *pOther)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  edict_t *peVar8;
  entvars_t *peVar9;
  CBaseEntity *pCVar10;
  byte *pbVar11;
  void *pvVar12;
  byte *pbVar13;
  char *pcVar14;
  bool bVar15;
  bool bVar16;
  byte bVar17;
  longdouble extraout_ST0;
  char *local_20;
  CBaseEntity *pOwner;
  
  bVar17 = 0;
                    /* Unresolved local var: CBaseEntity * pBuildingOwner@[???]
                       Unresolved local var: char * message@[???] */
  peVar8 = ((this->super_CBaseEntity).pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar8 == (edict_t *)0x0) &&
     (peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar8 == (edict_t *)0x0)) {
    pCVar10 = (CBaseEntity *)0x0;
  }
  else {
    pCVar10 = peVar8->pvPrivateData;
  }
  if ((pOther == pCVar10) || (this->m_pIgnore == pOther)) {
    return;
  }
  iVar2 = (*pOther->_vptr_CBaseEntity[10])(pOther);
  if ((iVar2 == 2) && (gpGlobals->time < pOther->invincible_finished)) {
    peVar9 = (this->super_CBaseEntity).pev;
    g_pszDeathType = "teledeath2";
    (*pCVar10->_vptr_CBaseEntity[0xd])(pCVar10,peVar9,peVar9,0x459c4000,0x2000);
    return;
  }
  peVar9 = pOther->pev;
  if (peVar9->takedamage != 0.0) {
    iVar2 = (*pOther->_vptr_CBaseEntity[10])(pOther);
    if (iVar2 == 2) {
      fVar1 = gpGlobals->time;
      (*g_engfuncs.pfnRandomFloat)(0.0,5.0);
      pOther[1].replacement_model_body = (int)(float)(extraout_ST0 + (longdouble)(fVar1 + 5.0));
    }
    g_pszDeathType = "teledeath";
    peVar9 = (this->super_CBaseEntity).pev;
    (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar9,peVar9,0x459c4000,0x2000);
    peVar9 = pOther->pev;
  }
  iVar2 = 8;
  pcVar3 = gpGlobals->pStringBase;
  bVar15 = CARRY4(peVar9->classname,(uint)pcVar3);
  bVar16 = (byte *)(pcVar3 + peVar9->classname) == (byte *)0x0;
  pbVar11 = (byte *)(pcVar3 + peVar9->classname);
  pbVar13 = (byte *)0x193431;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar15 = *pbVar11 < *pbVar13;
    bVar16 = *pbVar11 == *pbVar13;
    pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
    pbVar13 = pbVar13 + (uint)bVar17 * -2 + 1;
  } while (bVar16);
  if ((!bVar15 && !bVar16) != bVar15) {
    return;
  }
  peVar8 = peVar9->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar8 == (edict_t *)0x0) {
    peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar9 = pOther->pev;
    pcVar3 = gpGlobals->pStringBase;
    if (peVar8 == (edict_t *)0x0) {
      pvVar12 = (void *)0x0;
      goto LAB_00149dd3;
    }
  }
  pvVar12 = peVar8->pvPrivateData;
LAB_00149dd3:
  UTIL_ClientPrintAll(1,"#Detpack_telefragged",pcVar3 + peVar9->netname,
                      pcVar3 + pCVar10->pev->netname,(char *)0x0,(char *)0x0);
  if (*(int *)((int)pvVar12 + 0x138) == 0) {
    local_20 = "SPECTATOR";
  }
  else {
    local_20 = GetTeamName(*(int *)((int)pvVar12 + 0x138));
  }
  pcVar4 = (*g_engfuncs.pfnGetPlayerAuthId)(*(edict_t **)(*(int *)((int)pvVar12 + 4) + 0x208));
  iVar5 = (*g_engfuncs.pfnGetPlayerUserId)(*(edict_t **)(*(int *)((int)pvVar12 + 4) + 0x208));
  pcVar3 = gpGlobals->pStringBase;
  iVar2 = *(int *)(*(int *)((int)pvVar12 + 4) + 0x1d0);
  pcVar14 = "SPECTATOR";
  if (pCVar10->team_no != 0) {
    pcVar14 = GetTeamName(pCVar10->team_no);
  }
  pcVar6 = (*g_engfuncs.pfnGetPlayerAuthId)(pCVar10->pev->pContainingEntity);
  iVar7 = (*g_engfuncs.pfnGetPlayerUserId)(pCVar10->pev->pContainingEntity);
  UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"%s\" against \"%s<%i><%s><%s>\"\n",
                 gpGlobals->pStringBase + pCVar10->pev->netname,iVar7,pcVar6,pcVar14,
                 "Detpack_telefragged",pcVar3 + iVar2,iVar5,pcVar4,local_20);
  dremove(pOther);
  return;
}


