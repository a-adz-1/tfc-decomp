// Ghidra decompilation of functions from tfc/triggers.cpp
// 159 functions, ordered by original source line

// CFrictionModifier::~CFrictionModifier  @ 0011d550  (line 41)

/* DWARF original prototype: void ~CFrictionModifier(CFrictionModifier * this, int __in_chrg) */

void __thiscall CFrictionModifier::~CFrictionModifier(CFrictionModifier *this,int __in_chrg)

{
  return;
}


// CFrictionModifier::ObjectCaps  @ 0011d360  (line 50)

/* DWARF original prototype: int ObjectCaps(CFrictionModifier * this) */

int __thiscall CFrictionModifier::ObjectCaps(CFrictionModifier *this)

{
  return 0;
}


// func_friction  @ 0011a510  (line 57)

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
  *puVar1 = &PTR__CFrictionModifier_00163f70;
  puVar1[1] = pev;
  return;
}


// CFrictionModifier::Restore  @ 00118b70  (line 65)

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


// CFrictionModifier::Save  @ 00118bd0  (line 65)

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


// CFrictionModifier::Spawn  @ 001163e0  (line 70)

/* DWARF original prototype: void Spawn(CFrictionModifier * this) */

void __thiscall CFrictionModifier::Spawn(CFrictionModifier *this)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  
  p1Var2 = gpGlobals;
  ((this->super_CBaseEntity).pev)->solid = 1;
  peVar1 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar1->pContainingEntity,p1Var2->pStringBase + peVar1->model);
  ((this->super_CBaseEntity).pev)->movetype = 0;
  (this->super_CBaseEntity).m_pfnTouch.__pfn = ChangeFriction;
  (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
  return;
}


// CFrictionModifier::ChangeFriction  @ 00116440  (line 81)

/* DWARF original prototype: void ChangeFriction(CFrictionModifier * this, CBaseEntity * pOther) */

void __thiscall CFrictionModifier::ChangeFriction(CFrictionModifier *this,CBaseEntity *pOther)

{
  if (1 < pOther->pev->movetype - 10U) {
    pOther->pev->friction = this->m_frictionFraction;
  }
  return;
}


// CFrictionModifier::KeyValue  @ 00117bf0  (line 89)

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


// CAutoTrigger::~CAutoTrigger  @ 0011d540  (line 105)

/* DWARF original prototype: void ~CAutoTrigger(CAutoTrigger * this, int __in_chrg) */

void __thiscall CAutoTrigger::~CAutoTrigger(CAutoTrigger *this,int __in_chrg)

{
  return;
}


// CAutoTrigger::ObjectCaps  @ 0011d370  (line 113)

/* DWARF original prototype: int ObjectCaps(CAutoTrigger * this) */

int __thiscall CAutoTrigger::ObjectCaps(CAutoTrigger *this)

{
  return 0;
}


// trigger_auto  @ 0011a580  (line 123)

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
  *puVar1 = &PTR__CAutoTrigger_0016407c;
  puVar1[1] = pev;
  return;
}


// CAutoTrigger::Restore  @ 00118990  (line 131)

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


// CAutoTrigger::Save  @ 00118b10  (line 131)

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


// CAutoTrigger::KeyValue  @ 00117e00  (line 134)

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
                    /* Unresolved local var: int type@[???] */
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


// CAutoTrigger::Spawn  @ 00118c30  (line 163)

/* DWARF original prototype: void Spawn(CAutoTrigger * this) */

void __thiscall CAutoTrigger::Spawn(CAutoTrigger *this)

{
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[3];
  if (UNRECOVERED_JUMPTABLE == Precache) {
    ((this->super_CBaseDelay).super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00118c67. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// CAutoTrigger::Precache  @ 00116470  (line 169)

/* DWARF original prototype: void Precache(CAutoTrigger * this) */

void __thiscall CAutoTrigger::Precache(CAutoTrigger *this)

{
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  return;
}


// CAutoTrigger::Think  @ 00118800  (line 175)

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


// CTriggerRelay::~CTriggerRelay  @ 0011d530  (line 188)

/* DWARF original prototype: void ~CTriggerRelay(CTriggerRelay * this, int __in_chrg) */

void __thiscall CTriggerRelay::~CTriggerRelay(CTriggerRelay *this,int __in_chrg)

{
  return;
}


// CTriggerRelay::ObjectCaps  @ 0011d380  (line 195)

/* DWARF original prototype: int ObjectCaps(CTriggerRelay * this) */

int __thiscall CTriggerRelay::ObjectCaps(CTriggerRelay *this)

{
  return 0;
}


// trigger_relay  @ 0011a5f0  (line 204)

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
  *puVar1 = &PTR__CTriggerRelay_00164188;
  puVar1[1] = pev;
  return;
}


// CTriggerRelay::Restore  @ 00118930  (line 211)

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


// CTriggerRelay::Save  @ 00118ab0  (line 211)

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


// CTriggerRelay::KeyValue  @ 00117b40  (line 214)

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
                    /* Unresolved local var: int type@[???] */
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


// CTriggerRelay::Use  @ 00116c90  (line 245)

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


// CMultiManager::~CMultiManager  @ 0011d520  (line 256)

/* DWARF original prototype: void ~CMultiManager(CMultiManager * this, int __in_chrg) */

void __thiscall CMultiManager::~CMultiManager(CMultiManager *this,int __in_chrg)

{
  return;
}


// CMultiManager::ObjectCaps  @ 0011d390  (line 267)

/* DWARF original prototype: int ObjectCaps(CMultiManager * this) */

int __thiscall CMultiManager::ObjectCaps(CMultiManager *this)

{
  return 0;
}


// multi_manager  @ 0011a660  (line 280)

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
  *puVar1 = &PTR__CMultiManager_00164294;
  puVar1[1] = pev;
  return;
}


// CMultiManager::Restore  @ 00118600  (line 292)

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


// CMultiManager::Save  @ 001186c0  (line 292)

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


// CMultiManager::KeyValue  @ 00118140  (line 295)

/* DWARF original prototype: void KeyValue(CMultiManager * this, KeyValueData * pkvd) */

void __thiscall CMultiManager::KeyValue(CMultiManager *this,KeyValueData *pkvd)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int in_GS_OFFSET;
  bool bVar5;
  double dVar6;
  char local_a0 [128];
  int local_20;
  
  iVar2 = 5;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar5 = true;
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
    UTIL_StripToken(pkvd->szKeyName,local_a0,0x80);
    iVar2 = this->m_cTargets;
    iVar1 = (*g_engfuncs.pfnAllocString)(local_a0);
    this->m_iTargetName[iVar2] = iVar1;
    iVar2 = this->m_cTargets;
    dVar6 = strtod(pkvd->szValue,(char **)0x0);
    this->m_flTargetDelay[iVar2] = (float)dVar6;
    this->m_cTargets = this->m_cTargets + 1;
    pkvd->fHandled = 1;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CMultiManager::Spawn  @ 001164a0  (line 324)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CMultiManager * this) */

void __thiscall CMultiManager::Spawn(CMultiManager *this)

{
  float fVar1;
  int iVar2;
  float fVar3;
  bool bVar4;
  float *pfVar5;
  int iVar6;
  
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
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  do {
                    /* Unresolved local var: int i@[???] */
    if (iVar2 < 2) {
      return;
    }
    pfVar5 = this->m_flTargetDelay;
    iVar6 = 1;
    bVar4 = false;
    do {
      pfVar5 = pfVar5 + 1;
      fVar1 = *pfVar5;
      if (fVar1 < pfVar5[-1]) {
                    /* Unresolved local var: int name@[???]
                       Unresolved local var: float delay@[???] */
        *pfVar5 = pfVar5[-1];
        fVar3 = pfVar5[-0x11];
        pfVar5[-1] = fVar1;
        pfVar5[-0x11] = pfVar5[-0x10];
        bVar4 = true;
        pfVar5[-0x10] = fVar3;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 != iVar2);
  } while (bVar4);
  return;
}


// CMultiManager::HasTarget  @ 001168f0  (line 355)

/* DWARF original prototype: BOOL HasTarget(CMultiManager * this, string_t targetname) */

BOOL __thiscall CMultiManager::HasTarget(CMultiManager *this,string_t targetname)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char *__s1;
  
                    /* Unresolved local var: int i@[???] */
  iVar3 = this->m_cTargets;
  if (0 < iVar3) {
    pcVar1 = gpGlobals->pStringBase;
    __s1 = pcVar1 + targetname;
    iVar2 = strcmp(__s1,pcVar1 + this->m_iTargetName[0]);
    if (iVar2 == 0) {
      return 1;
    }
    if (iVar3 != 1) {
      iVar2 = strcmp(__s1,pcVar1 + this->m_iTargetName[1]);
      if (iVar2 == 0) {
        return 1;
      }
      if (iVar3 != 2) {
        iVar2 = strcmp(__s1,pcVar1 + this->m_iTargetName[2]);
        if (iVar2 == 0) {
          return 1;
        }
        if (iVar3 != 3) {
          iVar2 = strcmp(__s1,pcVar1 + this->m_iTargetName[3]);
          if (iVar2 == 0) {
            return 1;
          }
          if (iVar3 != 4) {
            iVar2 = strcmp(__s1,pcVar1 + this->m_iTargetName[4]);
            if (iVar2 == 0) {
              return 1;
            }
            if (iVar3 != 5) {
              iVar2 = strcmp(__s1,pcVar1 + this->m_iTargetName[5]);
              if (iVar2 == 0) {
                return 1;
              }
              if (iVar3 != 6) {
                iVar2 = strcmp(__s1,pcVar1 + this->m_iTargetName[6]);
                if (iVar2 == 0) {
                  return 1;
                }
                if (iVar3 != 7) {
                  iVar2 = strcmp(__s1,pcVar1 + this->m_iTargetName[7]);
                  if (iVar2 == 0) {
                    return 1;
                  }
                  if (iVar3 != 8) {
                    iVar2 = strcmp(__s1,pcVar1 + this->m_iTargetName[8]);
                    if (iVar2 == 0) {
                      return 1;
                    }
                    if (iVar3 != 9) {
                      iVar2 = strcmp(__s1,pcVar1 + this->m_iTargetName[9]);
                      if (iVar2 == 0) {
                        return 1;
                      }
                      if (iVar3 != 10) {
                        iVar2 = strcmp(__s1,pcVar1 + this->m_iTargetName[10]);
                        if (iVar2 == 0) {
                          return 1;
                        }
                        if (iVar3 != 0xb) {
                          iVar2 = strcmp(__s1,pcVar1 + this->m_iTargetName[0xb]);
                          if (iVar2 == 0) {
                            return 1;
                          }
                          if (iVar3 != 0xc) {
                            iVar2 = strcmp(__s1,pcVar1 + this->m_iTargetName[0xc]);
                            if (iVar2 == 0) {
                              return 1;
                            }
                            if (iVar3 != 0xd) {
                              iVar2 = strcmp(__s1,pcVar1 + this->m_iTargetName[0xd]);
                              if (iVar2 == 0) {
                                return 1;
                              }
                              if (iVar3 != 0xe) {
                                iVar2 = strcmp(__s1,pcVar1 + this->m_iTargetName[0xe]);
                                if (iVar2 == 0) {
                                  return 1;
                                }
                                if (iVar3 != 0xf) {
                                  iVar3 = strcmp(__s1,pcVar1 + this->m_iTargetName[0xf]);
                                  return (uint)(iVar3 == 0);
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}


// CMultiManager::ManagerThink  @ 00118470  (line 367)

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
  fVar5 = gpGlobals->time - fVar2;
  if (this->m_index < this->m_cTargets) {
    fVar3 = this->m_flTargetDelay[this->m_index];
    if (fVar3 <= fVar5) {
      do {
        pActivator = EHANDLE::operator_cast_to_CBaseEntity_(&(this->super_CBaseToggle).m_hActivator)
        ;
        FireTargets(gpGlobals->pStringBase + this->m_iTargetName[this->m_index],pActivator,
                    (CBaseEntity *)this,USE_TOGGLE,0.0);
        iVar4 = this->m_index;
        iVar1 = iVar4 + 1;
        this->m_index = iVar1;
        if (this->m_cTargets <= iVar1) goto LAB_00118555;
        fVar3 = this->m_flTargetDelay[iVar4 + 1];
      } while (fVar3 <= fVar5);
      fVar2 = this->m_startTime;
    }
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    nextthink = fVar2 + fVar3;
    return;
  }
LAB_00118555:
                    /* Unresolved local var: float time@[???] */
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


// CMultiManager::ManagerUse  @ 00116d20  (line 388)

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
  _2globalvars_t *p1Var3;
  
  EHANDLE::operator=(&(this->super_CBaseToggle).m_hActivator,pActivator);
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  this->m_index = 0;
  p1Var3 = gpGlobals;
  fVar1 = gpGlobals->time;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *)0x0;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.__delta
       = 0;
  this->m_startTime = fVar1;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = ManagerThink;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  peVar2->nextthink = p1Var3->time;
  return;
}


// CMultiManager::ManagerReport  @ 0011a6d0  (line 400)

/* DWARF original prototype: void ManagerReport(CMultiManager * this) */

void __thiscall CMultiManager::ManagerReport(CMultiManager *this)

{
  float *pfVar1;
  int iVar2;
  
                    /* Unresolved local var: int cIndex@[???] */
  if (0 < this->m_cTargets) {
    iVar2 = 0;
    pfVar1 = this->m_flTargetDelay;
    do {
      iVar2 = iVar2 + 1;
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"%s %f\n",gpGlobals->pStringBase + (int)pfVar1[-0x10],(double)*pfVar1);
      pfVar1 = pfVar1 + 1;
    } while (iVar2 < this->m_cTargets);
  }
  return;
}


// CRenderFxManager::~CRenderFxManager  @ 0011d510  (line 425)

/* DWARF original prototype: void ~CRenderFxManager(CRenderFxManager * this, int __in_chrg) */

void __thiscall CRenderFxManager::~CRenderFxManager(CRenderFxManager *this,int __in_chrg)

{
  return;
}


// env_render  @ 0011a740  (line 432)

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
  *puVar1 = &PTR__CRenderFxManager_001643a4;
  puVar1[1] = pev;
  return;
}


// CRenderFxManager::Spawn  @ 00116540  (line 437)

/* DWARF original prototype: void Spawn(CRenderFxManager * this) */

void __thiscall CRenderFxManager::Spawn(CRenderFxManager *this)

{
  ((this->super_CBaseEntity).pev)->solid = 0;
  return;
}


// CRenderFxManager::Use  @ 00117d00  (line 441)

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


// CBaseTrigger::~CBaseTrigger  @ 0011d3e0  (line 466)

/* DWARF original prototype: void ~CBaseTrigger(CBaseTrigger * this, int __in_chrg) */

void __thiscall CBaseTrigger::~CBaseTrigger(CBaseTrigger *this,int __in_chrg)

{
  return;
}


// CBaseTrigger::ObjectCaps  @ 0011d3a0  (line 480)

/* DWARF original prototype: int ObjectCaps(CBaseTrigger * this) */

int __thiscall CBaseTrigger::ObjectCaps(CBaseTrigger *this)

{
  return 0;
}


// trigger  @ 0011a7b0  (line 483)

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
  *puVar1 = &PTR__CBaseTrigger_001644b0;
  puVar1[1] = pev;
  return;
}


// CBaseTrigger::InitTrigger  @ 0011a820  (line 491)

/* DWARF original prototype: void InitTrigger(CBaseTrigger * this) */

void __thiscall CBaseTrigger::InitTrigger(CBaseTrigger *this)

{
  int *piVar1;
  entvars_t *peVar2;
  longdouble lVar3;
  
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (((g_vecZero.x != (peVar2->angles).x) || ((peVar2->angles).y != g_vecZero.y)) ||
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


// CBaseTrigger::KeyValue  @ 00116d90  (line 509)

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


// CTriggerHurt::~CTriggerHurt  @ 0011d4d0  (line 529)

/* DWARF original prototype: void ~CTriggerHurt(CTriggerHurt * this, int __in_chrg) */

void __thiscall CTriggerHurt::~CTriggerHurt(CTriggerHurt *this,int __in_chrg)

{
  return;
}


// trigger_hurt  @ 0011a900  (line 536)

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
  *puVar1 = &PTR__CTriggerHurt_001648ec;
  puVar1[1] = pev;
  return;
}


// CTriggerMonsterJump::~CTriggerMonsterJump  @ 0011d500  (line 541)

/* DWARF original prototype: void ~CTriggerMonsterJump(CTriggerMonsterJump * this, int __in_chrg) */

void __thiscall CTriggerMonsterJump::~CTriggerMonsterJump(CTriggerMonsterJump *this,int __in_chrg)

{
  return;
}


// trigger_monsterjump  @ 0011a970  (line 549)

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
  *puVar1 = &PTR__CTriggerMonsterJump_001645c0;
  puVar1[1] = pev;
  return;
}


// CTriggerMonsterJump::Spawn  @ 00119bc0  (line 553)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTriggerMonsterJump * this) */

void __thiscall CTriggerMonsterJump::Spawn(CTriggerMonsterJump *this)

{
  int *piVar1;
  entvars_t *peVar2;
  longdouble lVar3;
  
  SetMovedir((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev);
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
  ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = 0.0;
  ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->speed = 200.0;
  peVar2 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseTrigger).super_CBaseToggle.m_flHeight = 150.0;
  if (peVar2->targetname != 0) {
    peVar2->solid = 0;
    peVar2 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    UTIL_SetOrigin(peVar2,&peVar2->origin);
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__pfn = CBaseTrigger::ToggleUse;
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__delta = 0;
  }
  return;
}


// CTriggerMonsterJump::Think  @ 00116eb0  (line 572)

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


// CTriggerMonsterJump::Touch  @ 00116550  (line 580)

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
  _2globalvars_t *p1Var7;
  
                    /* Unresolved local var: entvars_t * pevOther@[???] */
  peVar3 = pOther->pev;
  uVar4 = peVar3->flags;
  if ((uVar4 & 0x20) != 0) {
    (peVar3->origin).z = (peVar3->origin).z + 1.0;
    if ((uVar4 & 0x200) != 0) {
      peVar3->flags = uVar4 & 0xfffffdff;
    }
    p1Var7 = gpGlobals;
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
     super_CBaseEntity.pev)->nextthink = p1Var7->time;
  }
  return;
}


// CTriggerCDAudio::~CTriggerCDAudio  @ 0011d4f0  (line 605)

/* DWARF original prototype: void ~CTriggerCDAudio(CTriggerCDAudio * this, int __in_chrg) */

void __thiscall CTriggerCDAudio::~CTriggerCDAudio(CTriggerCDAudio *this,int __in_chrg)

{
  return;
}


// trigger_cdaudio  @ 0011a9e0  (line 615)

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
  *puVar1 = &PTR__CTriggerCDAudio_001646d0;
  puVar1[1] = pev;
  return;
}


// CTriggerCDAudio::Touch  @ 001191a0  (line 622)

/* DWARF original prototype: void Touch(CTriggerCDAudio * this, CBaseEntity * pOther) */

void __thiscall CTriggerCDAudio::Touch(CTriggerCDAudio *this,CBaseEntity *pOther)

{
  edict_t *peVar1;
  int iVar2;
  int in_GS_OFFSET;
  char local_50 [64];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((pOther->pev->flags & 8) != 0) {
    iVar2 = (int)((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->health;
                    /* Unresolved local var: edict_t * pClient@[???] */
    peVar1 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
    if (peVar1 != (edict_t *)0x0) {
      if (iVar2 + 1U < 0x20) {
        if (iVar2 == -1) {
          (*g_engfuncs.pfnClientCommand)(peVar1,"cd stop\n");
        }
        else {
                    /* Unresolved local var: char[64] string@[???] */
          __sprintf_chk(local_50,1,0x40,"cd play %3d\n",iVar2);
          (*g_engfuncs.pfnClientCommand)(peVar1,local_50);
        }
      }
      else {
                    /* Unresolved local var: edict_t * pClient@[???] */
        (*g_engfuncs.pfnAlertMessage)(at_console,"TriggerCDAudio - Track %d out of range\n");
      }
    }
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnTouch.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnTouch.__delta = 0;
    UTIL_Remove((CBaseEntity *)this);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CTriggerCDAudio::Spawn  @ 001197c0  (line 632)

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


// CTriggerCDAudio::Use  @ 001190a0  (line 637)

/* DWARF original prototype: void Use(CTriggerCDAudio * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CTriggerCDAudio::Use
          (CTriggerCDAudio *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  edict_t *peVar1;
  int iVar2;
  int in_GS_OFFSET;
  char local_50 [64];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = (int)((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->health;
                    /* Unresolved local var: edict_t * pClient@[???] */
  peVar1 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if (peVar1 != (edict_t *)0x0) {
    if (iVar2 + 1U < 0x20) {
      if (iVar2 == -1) {
        (*g_engfuncs.pfnClientCommand)(peVar1,"cd stop\n");
      }
      else {
                    /* Unresolved local var: char[64] string@[???] */
        __sprintf_chk(local_50,1,0x40,"cd play %3d\n",iVar2);
        (*g_engfuncs.pfnClientCommand)(peVar1,local_50);
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
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// PlayCDTrack  @ 0011aa50  (line 642)

void PlayCDTrack(int iTrack)

{
  edict_t *peVar1;
  int in_GS_OFFSET;
  char local_50 [64];
  int local_10;
  
                    /* Unresolved local var: edict_t * pClient@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  peVar1 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if (peVar1 != (edict_t *)0x0) {
    if (iTrack + 1U < 0x20) {
      if (iTrack == -1) {
        (*g_engfuncs.pfnClientCommand)(peVar1,"cd stop\n");
      }
      else {
                    /* Unresolved local var: char[64] string@[???] */
        __sprintf_chk(local_50,1,0x40,"cd play %3d\n",iTrack);
        (*g_engfuncs.pfnClientCommand)(peVar1,local_50);
      }
    }
    else {
                    /* Unresolved local var: edict_t * pClient@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_console,"TriggerCDAudio - Track %d out of range\n");
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CTriggerCDAudio::PlayTrack  @ 0011ab10  (line 674)

/* DWARF original prototype: void PlayTrack(CTriggerCDAudio * this) */

void __thiscall CTriggerCDAudio::PlayTrack(CTriggerCDAudio *this)

{
  edict_t *peVar1;
  int iVar2;
  int in_GS_OFFSET;
  char local_50 [64];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = (int)((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->health;
                    /* Unresolved local var: edict_t * pClient@[???] */
  peVar1 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if (peVar1 != (edict_t *)0x0) {
    if (iVar2 + 1U < 0x20) {
      if (iVar2 == -1) {
        (*g_engfuncs.pfnClientCommand)(peVar1,"cd stop\n");
      }
      else {
                    /* Unresolved local var: char[64] string@[???] */
        __sprintf_chk(local_50,1,0x40,"cd play %3d\n",iVar2);
        (*g_engfuncs.pfnClientCommand)(peVar1,local_50);
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
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CTargetCDAudio::~CTargetCDAudio  @ 0011d4e0  (line 683)

/* DWARF original prototype: void ~CTargetCDAudio(CTargetCDAudio * this, int __in_chrg) */

void __thiscall CTargetCDAudio::~CTargetCDAudio(CTargetCDAudio *this,int __in_chrg)

{
  return;
}


// target_cdaudio  @ 0011ac10  (line 694)

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
  *puVar1 = &PTR__CTargetCDAudio_001647e0;
  puVar1[1] = pev;
  return;
}


// CTargetCDAudio::KeyValue  @ 00117ee0  (line 697)

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


// CTargetCDAudio::Spawn  @ 001165d0  (line 708)

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


// CTargetCDAudio::Use  @ 00118fb0  (line 717)

/* DWARF original prototype: void Use(CTargetCDAudio * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CTargetCDAudio::Use(CTargetCDAudio *this,CBaseEntity *pActivator,CBaseEntity *pCaller,
                   USE_TYPE useType,float value)

{
  edict_t *peVar1;
  int iVar2;
  int in_GS_OFFSET;
  char local_50 [64];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = (int)((this->super_CPointEntity).super_CBaseEntity.pev)->health;
                    /* Unresolved local var: edict_t * pClient@[???] */
  peVar1 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if (peVar1 != (edict_t *)0x0) {
    if (iVar2 + 1U < 0x20) {
      if (iVar2 == -1) {
        (*g_engfuncs.pfnClientCommand)(peVar1,"cd stop\n");
      }
      else {
                    /* Unresolved local var: char[64] string@[???] */
        __sprintf_chk(local_50,1,0x40,"cd play %3d\n",iVar2);
        (*g_engfuncs.pfnClientCommand)(peVar1,local_50);
      }
    }
    else {
                    /* Unresolved local var: edict_t * pClient@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_console,"TriggerCDAudio - Track %d out of range\n");
    }
  }
  UTIL_Remove((CBaseEntity *)this);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CTargetCDAudio::Think  @ 001192c0  (line 723)

/* DWARF original prototype: void Think(CTargetCDAudio * this) */

void __thiscall CTargetCDAudio::Think(CTargetCDAudio *this)

{
  float fVar1;
  float fVar2;
  edict_t *peVar3;
  entvars_t *peVar4;
  int iVar5;
  int in_GS_OFFSET;
  float fVar6;
  char local_50 [64];
  int local_10;
  
                    /* Unresolved local var: edict_t * pClient@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  peVar3 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if (peVar3 != (edict_t *)0x0) {
    ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.5;
    peVar4 = (this->super_CPointEntity).super_CBaseEntity.pev;
    fVar1 = (peVar3->v).origin.z - (peVar4->origin).z;
    fVar2 = (peVar3->v).origin.y - (peVar4->origin).y;
    fVar6 = (peVar3->v).origin.x - (peVar4->origin).x;
    fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar6 * fVar6;
    fVar6 = SQRT(fVar1);
    if (NAN(fVar6)) {
      fVar6 = sqrtf(fVar1);
      peVar4 = (this->super_CPointEntity).super_CBaseEntity.pev;
    }
    if (fVar6 <= peVar4->scale) {
      iVar5 = (int)peVar4->health;
                    /* Unresolved local var: edict_t * pClient@[???] */
      peVar3 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
      if (peVar3 != (edict_t *)0x0) {
        if (iVar5 + 1U < 0x20) {
          if (iVar5 == -1) {
            (*g_engfuncs.pfnClientCommand)(peVar3,"cd stop\n");
          }
          else {
                    /* Unresolved local var: char[64] string@[???] */
            __sprintf_chk(local_50,1,0x40,"cd play %3d\n",iVar5);
            (*g_engfuncs.pfnClientCommand)(peVar3,local_50);
          }
        }
        else {
                    /* Unresolved local var: edict_t * pClient@[???] */
          (*g_engfuncs.pfnAlertMessage)(at_console,"TriggerCDAudio - Track %d out of range\n");
        }
      }
      UTIL_Remove((CBaseEntity *)this);
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CTargetCDAudio::Play  @ 0011ac80  (line 741)

/* DWARF original prototype: void Play(CTargetCDAudio * this) */

void __thiscall CTargetCDAudio::Play(CTargetCDAudio *this)

{
  edict_t *peVar1;
  int iVar2;
  int in_GS_OFFSET;
  char local_50 [64];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = (int)((this->super_CPointEntity).super_CBaseEntity.pev)->health;
                    /* Unresolved local var: edict_t * pClient@[???] */
  peVar1 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  if (peVar1 != (edict_t *)0x0) {
    if (iVar2 + 1U < 0x20) {
      if (iVar2 == -1) {
        (*g_engfuncs.pfnClientCommand)(peVar1,"cd stop\n");
      }
      else {
                    /* Unresolved local var: char[64] string@[???] */
        __sprintf_chk(local_50,1,0x40,"cd play %3d\n",iVar2);
        (*g_engfuncs.pfnClientCommand)(peVar1,local_50);
      }
    }
    else {
                    /* Unresolved local var: edict_t * pClient@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_console,"TriggerCDAudio - Track %d out of range\n");
    }
  }
  UTIL_Remove((CBaseEntity *)this);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CTriggerHurt::Spawn  @ 0011a130  (line 754)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTriggerHurt * this) */

void __thiscall CTriggerHurt::Spawn(CTriggerHurt *this)

{
  int *piVar1;
  float fVar2;
  string_t sVar3;
  int iVar4;
  _2globalvars_t *p1Var5;
  entvars_t *peVar6;
  code *pcVar7;
  longdouble lVar8;
  
  peVar6 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((((peVar6->angles).x != g_vecZero.x) || ((peVar6->angles).y != g_vecZero.y)) ||
     ((peVar6->angles).z != g_vecZero.z)) {
    SetMovedir(peVar6);
    peVar6 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  peVar6->solid = 1;
  p1Var5 = gpGlobals;
  ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 0;
  peVar6 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar6->pContainingEntity,p1Var5->pStringBase + peVar6->model);
  lVar8 = (longdouble)(*g_engfuncs.pfnCVarGetFloat)("showtriggers");
  if (lVar8 == (longdouble)0) {
    piVar1 = &((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 0x80;
  }
  peVar6 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  pcVar7 = CBaseTrigger::ToggleUse;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBaseTrigger::HurtTouch;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  sVar3 = peVar6->targetname;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__delta = 0;
  if (sVar3 == 0) {
    pcVar7 = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *
             )0x0;
  }
  iVar4 = (this->super_CBaseTrigger).super_CBaseToggle.m_bitsDamageInflict;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__pfn = pcVar7;
  p1Var5 = gpGlobals;
  if ((iVar4 & 0x40000) != 0) {
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = RadiationThink;
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    fVar2 = p1Var5->time;
    lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,0.5);
    peVar6->nextthink = (float)(lVar8 + (longdouble)fVar2);
    peVar6 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if ((peVar6->spawnflags & 2) != 0) {
    peVar6->solid = 0;
    peVar6 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  UTIL_SetOrigin(peVar6,&peVar6->origin);
  return;
}


// CTriggerHurt::RadiationThink  @ 00116f40  (line 784)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RadiationThink(CTriggerHurt * this) */

void __thiscall CTriggerHurt::RadiationThink(CTriggerHurt *this)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  vec_t vVar5;
  vec_t vVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  entvars_t *peVar10;
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
  peVar10 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  fVar7 = (peVar10->absmin).z;
  fVar14 = (peVar10->absmax).z;
  vVar1 = (peVar10->origin).x;
  vVar2 = (peVar10->origin).y;
  vVar3 = (peVar10->origin).z;
  vVar4 = (peVar10->view_ofs).x;
  vVar5 = (peVar10->view_ofs).y;
  vVar6 = (peVar10->view_ofs).z;
  fVar8 = (peVar10->absmin).y;
  fVar9 = (peVar10->absmax).y;
  (peVar10->origin).x = ((peVar10->absmin).x + (peVar10->absmax).x) * 0.5;
  (peVar10->origin).y = (fVar8 + fVar9) * 0.5;
  (peVar10->origin).z = (fVar7 + fVar14) * 0.5;
  peVar10 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  (peVar10->view_ofs).x = (peVar10->view_ofs).x * 0.0;
  (peVar10->view_ofs).y = (peVar10->view_ofs).y * 0.0;
  (peVar10->view_ofs).z = (peVar10->view_ofs).z * 0.0;
  peVar12 = (*g_engfuncs.pfnFindClientInPVS)
                      (((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  peVar10 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  (peVar10->origin).x = vVar1;
  (peVar10->origin).y = vVar2;
  (peVar10->origin).z = vVar3;
  peVar10 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  (peVar10->view_ofs).x = vVar4;
  (peVar10->view_ofs).y = vVar5;
  (peVar10->view_ofs).z = vVar6;
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
    peVar10 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    fVar7 = ((peVar10->absmin).z + (peVar10->absmax).z) * 0.5 -
            ((peVar12->v).absmin.z + (peVar12->v).absmax.z) * 0.5;
    fVar8 = ((peVar10->absmin).y + (peVar10->absmax).y) * 0.5 -
            ((peVar12->v).absmin.y + (peVar12->v).absmax.y) * 0.5;
    fVar14 = ((peVar10->absmin).x + (peVar10->absmax).x) * 0.5 -
             ((peVar12->v).absmin.x + (peVar12->v).absmax.x) * 0.5;
    fVar7 = fVar7 * fVar7 + fVar8 * fVar8 + fVar14 * fVar14;
    fVar14 = SQRT(fVar7);
    if (NAN(fVar14)) {
      fVar14 = sqrtf(fVar7);
    }
    if (fVar14 <= this_00->m_flgeigerRange) {
      this_00->m_flgeigerRange = fVar14;
    }
  }
  ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.25;
  return;
}


// CBaseTrigger::ToggleUse  @ 00116ef0  (line 843)

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


// CBaseTrigger::HurtTouch  @ 001182e0  (line 860)

/* DWARF original prototype: void HurtTouch(CBaseTrigger * this, CBaseEntity * pOther) */

void __thiscall CBaseTrigger::HurtTouch(CBaseTrigger *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  entvars_t *peVar2;
  uint uVar3;
  float fVar4;
  _2globalvars_t *p1Var5;
  BOOL BVar6;
  
                    /* Unresolved local var: float fldmg@[???] */
  peVar1 = pOther->pev;
  if (peVar1->takedamage != 0.0) {
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    uVar3 = peVar2->spawnflags;
    if ((uVar3 & 0x20) == 0) {
      if (((uVar3 & 8) != 0) && ((peVar1->flags & 8) != 0)) {
        return;
      }
    }
    else {
      if ((peVar1->flags & 8) == 0) {
        return;
      }
      if ((uVar3 & 8) != 0) {
        return;
      }
    }
                    /* Unresolved local var: float fldmg@[???] */
    if (((peVar2->dmgtime <= gpGlobals->time) || (gpGlobals->time == peVar2->pain_finished)) &&
       (BVar6 = ActivationSucceeded((CBaseEntity *)this,(CBasePlayer *)pOther,(CBaseEntity *)0x0),
       BVar6 != 0)) {
      peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      fVar4 = peVar1->dmg * 0.5;
      if (fVar4 < 0.0) {
        (*pOther->_vptr_CBaseEntity[0xe])
                  (pOther,-fVar4,(this->super_CBaseToggle).m_bitsDamageInflict);
      }
      else {
        (*pOther->_vptr_CBaseEntity[0xd])
                  (pOther,peVar1,peVar1,fVar4,(this->super_CBaseToggle).m_bitsDamageInflict);
      }
      p1Var5 = gpGlobals;
      ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      pain_finished = gpGlobals->time;
      ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      dmgtime = p1Var5->time + 0.5;
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


// CTriggerMultiple::~CTriggerMultiple  @ 0011d3f0  (line 954)

/* DWARF original prototype: void ~CTriggerMultiple(CTriggerMultiple * this, int __in_chrg) */

void __thiscall CTriggerMultiple::~CTriggerMultiple(CTriggerMultiple *this,int __in_chrg)

{
  return;
}


// trigger_multiple  @ 0011ad70  (line 960)

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
  *puVar1 = &PTR__CTriggerMultiple_001649fc;
  puVar1[1] = pev;
  return;
}


// CTriggerMultiple::Spawn  @ 00119d00  (line 964)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTriggerMultiple * this) */

void __thiscall CTriggerMultiple::Spawn(CTriggerMultiple *this)

{
  int *piVar1;
  BOOL BVar2;
  entvars_t *peVar3;
  longdouble lVar4;
  
  BVar2 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar2 != 0) {
    if ((this->super_CBaseTrigger).super_CBaseToggle.m_flWait == 0.0) {
      (this->super_CBaseTrigger).super_CBaseToggle.m_flWait = 0.2;
    }
    peVar3 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((((peVar3->angles).x != g_vecZero.x) || ((peVar3->angles).y != g_vecZero.y)) ||
       ((peVar3->angles).z != g_vecZero.z)) {
      SetMovedir(peVar3);
      peVar3 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    peVar3->solid = 1;
    ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->movetype = 0;
    peVar3 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*g_engfuncs.pfnSetModel)(peVar3->pContainingEntity,gpGlobals->pStringBase + peVar3->model);
    lVar4 = (longdouble)(*g_engfuncs.pfnCVarGetFloat)("showtriggers");
    if (lVar4 == (longdouble)0) {
      piVar1 = &((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 | 0x80;
    }
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnTouch.__pfn = CBaseTrigger::MultiTouch;
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnTouch.__delta = 0;
    return;
  }
  dremove((CBaseEntity *)this);
  return;
}


// CTriggerOnce::~CTriggerOnce  @ 0011d4c0  (line 1009)

/* DWARF original prototype: void ~CTriggerOnce(CTriggerOnce * this, int __in_chrg) */

void __thiscall CTriggerOnce::~CTriggerOnce(CTriggerOnce *this,int __in_chrg)

{
  return;
}


// trigger_once  @ 0011ade0  (line 1015)

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
  *puVar1 = &PTR__CTriggerOnce_00164b0c;
  puVar1[1] = pev;
  return;
}


// CTriggerOnce::Spawn  @ 00119a80  (line 1017)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTriggerOnce * this) */

void __thiscall CTriggerOnce::Spawn(CTriggerOnce *this)

{
  int *piVar1;
  BOOL BVar2;
  entvars_t *peVar3;
  longdouble lVar4;
  
  (this->super_CTriggerMultiple).super_CBaseTrigger.super_CBaseToggle.m_flWait = -1.0;
  BVar2 = CBaseEntity::CheckExistence((CBaseEntity *)this);
  if (BVar2 != 0) {
    if ((this->super_CTriggerMultiple).super_CBaseTrigger.super_CBaseToggle.m_flWait == 0.0) {
      (this->super_CTriggerMultiple).super_CBaseTrigger.super_CBaseToggle.m_flWait = 0.2;
    }
    peVar3 = (this->super_CTriggerMultiple).super_CBaseTrigger.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if ((((peVar3->angles).x != g_vecZero.x) || ((peVar3->angles).y != g_vecZero.y)) ||
       ((peVar3->angles).z != g_vecZero.z)) {
      SetMovedir(peVar3);
      peVar3 = (this->super_CTriggerMultiple).super_CBaseTrigger.super_CBaseToggle.
               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    }
    peVar3->solid = 1;
    ((this->super_CTriggerMultiple).super_CBaseTrigger.super_CBaseToggle.super_CBaseAnimating.
     super_CBaseDelay.super_CBaseEntity.pev)->movetype = 0;
    peVar3 = (this->super_CTriggerMultiple).super_CBaseTrigger.super_CBaseToggle.
             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (*g_engfuncs.pfnSetModel)(peVar3->pContainingEntity,gpGlobals->pStringBase + peVar3->model);
    lVar4 = (longdouble)(*g_engfuncs.pfnCVarGetFloat)("showtriggers");
    if (lVar4 == (longdouble)0) {
      piVar1 = &((this->super_CTriggerMultiple).super_CBaseTrigger.super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 | 0x80;
    }
    (this->super_CTriggerMultiple).super_CBaseTrigger.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn = CBaseTrigger::MultiTouch;
    *(int *)((int)&(this->super_CTriggerMultiple).super_CBaseTrigger.super_CBaseToggle.
                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
    return;
  }
  dremove((CBaseEntity *)this);
  return;
}


// CBaseTrigger::MultiTouch  @ 00118d30  (line 1026)

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
  
                    /* Unresolved local var: entvars_t * pevToucher@[???] */
  bVar11 = 0;
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
    bVar9 = CARRY4(uVar2,(uint)gpGlobals->pStringBase);
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


// CBaseTrigger::ActivateMultiTrigger  @ 00117f60  (line 1060)

/* DWARF original prototype: void ActivateMultiTrigger(CBaseTrigger * this, CBaseEntity *
   pActivator) */

void __thiscall CBaseTrigger::ActivateMultiTrigger(CBaseTrigger *this,CBaseEntity *pActivator)

{
  BOOL *this_00;
  _func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *p_Var1;
  char *pcVar2;
  _2globalvars_t *p1Var3;
  CBaseDelay *in_EAX;
  CBaseEntity *pActivator_00;
  int iVar4;
  CBaseEntity *in_EDX;
  entvars_t *peVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  
  iVar4 = 0xf;
  peVar5 = (in_EAX->super_CBaseEntity).pev;
  pcVar2 = gpGlobals->pStringBase;
  bVar8 = pcVar2 + peVar5->classname == (char *)0x0;
  pcVar6 = pcVar2 + peVar5->classname;
  pcVar7 = "trigger_secret";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar6 == *pcVar7;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar8);
  if (bVar8) {
    if (peVar5->enemy == (edict_t *)0x0) {
      return;
    }
    bVar8 = pcVar2 + (peVar5->enemy->v).classname == (char *)0x0;
    iVar4 = 7;
    pcVar6 = pcVar2 + (peVar5->enemy->v).classname;
    pcVar7 = "player";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar8 = *pcVar6 == *pcVar7;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar8);
    if (!bVar8) {
      return;
    }
    gpGlobals->found_secrets = gpGlobals->found_secrets + 1.0;
    peVar5 = (in_EAX->super_CBaseEntity).pev;
  }
  if (peVar5->noise != 0) {
    EMIT_SOUND_DYN(peVar5->pContainingEntity,2,pcVar2 + peVar5->noise,1.0,0.8,0,100);
  }
  this_00 = &in_EAX[1].super_CBaseEntity.is_undercover;
  EHANDLE::operator=((EHANDLE *)this_00,in_EDX);
  pActivator_00 = EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)this_00);
  CBaseDelay::SUB_UseTargets(in_EAX,pActivator_00,USE_TOGGLE,0.0);
  peVar5 = (in_EAX->super_CBaseEntity).pev;
  if ((peVar5->message == 0) || ((in_EDX->pev->flags & 8) == 0)) {
    p_Var1 = in_EAX[1].super_CBaseEntity.m_pfnUse.__pfn;
    p1Var3 = gpGlobals;
  }
  else {
    UTIL_ShowMessage(gpGlobals->pStringBase + peVar5->message,in_EDX->pev->pContainingEntity);
    peVar5 = (in_EAX->super_CBaseEntity).pev;
    p_Var1 = in_EAX[1].super_CBaseEntity.m_pfnUse.__pfn;
    p1Var3 = gpGlobals;
  }
  gpGlobals = p1Var3;
  if ((float)p_Var1 <= 0.0) {
    (in_EAX->super_CBaseEntity).m_pfnTouch.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
    (in_EAX->super_CBaseEntity).m_pfnTouch.__delta = 0;
    peVar5->nextthink = p1Var3->time + 0.1;
    (in_EAX->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (in_EAX->super_CBaseEntity).m_pfnThink.__delta = 0;
  }
  else {
    (in_EAX->super_CBaseEntity).m_pfnThink.__pfn = MultiWaitOver;
    (in_EAX->super_CBaseEntity).m_pfnThink.__delta = 0;
    peVar5->nextthink = (float)p_Var1 + p1Var3->time;
  }
  return;
}


// CBaseTrigger::ActivateMultiTrigger  @ 0011ae50  (line 1061)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ActivateMultiTrigger(CBaseTrigger * this, CBaseEntity *
   pActivator) */

void __thiscall CBaseTrigger::ActivateMultiTrigger(CBaseTrigger *this,CBaseEntity *pActivator)

{
  EHANDLE *this_00;
  float fVar1;
  char *pcVar2;
  _2globalvars_t *p1Var3;
  int iVar4;
  entvars_t *peVar5;
  CBaseEntity *pActivator_00;
  byte *pbVar6;
  char *pcVar7;
  byte *pbVar8;
  char *pcVar9;
  bool bVar10;
  bool bVar11;
  byte bVar12;
  
  bVar12 = 0;
  if ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
       nextthink <= gpGlobals->time) &&
     (iVar4 = UTIL_IsMasterTriggered((this->super_CBaseToggle).m_sMaster), iVar4 != 0)) {
    peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    iVar4 = 0xf;
    pcVar2 = gpGlobals->pStringBase;
    bVar10 = CARRY4(peVar5->classname,(uint)pcVar2);
    bVar11 = (byte *)(pcVar2 + peVar5->classname) == (byte *)0x0;
    pbVar6 = (byte *)(pcVar2 + peVar5->classname);
    pbVar8 = (byte *)"trigger_secret";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar10 = *pbVar6 < *pbVar8;
      bVar11 = *pbVar6 == *pbVar8;
      pbVar6 = pbVar6 + (uint)bVar12 * -2 + 1;
      pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
    } while (bVar11);
    if ((!bVar10 && !bVar11) == bVar10) {
      if (peVar5->enemy == (edict_t *)0x0) {
        return;
      }
      iVar4 = 7;
      bVar10 = pcVar2 + (peVar5->enemy->v).classname == (char *)0x0;
      pcVar7 = pcVar2 + (peVar5->enemy->v).classname;
      pcVar9 = "player";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar10 = *pcVar7 == *pcVar9;
        pcVar7 = pcVar7 + (uint)bVar12 * -2 + 1;
        pcVar9 = pcVar9 + (uint)bVar12 * -2 + 1;
      } while (bVar10);
      if (!bVar10) {
        return;
      }
      gpGlobals->found_secrets = gpGlobals->found_secrets + 1.0;
      peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
    }
    if (peVar5->noise != 0) {
      EMIT_SOUND_DYN(peVar5->pContainingEntity,2,pcVar2 + peVar5->noise,1.0,0.8,0,100);
    }
    this_00 = &(this->super_CBaseToggle).m_hActivator;
    EHANDLE::operator=(this_00,pActivator);
    pActivator_00 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
    CBaseDelay::SUB_UseTargets((CBaseDelay *)this,pActivator_00,USE_TOGGLE,0.0);
    peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if ((peVar5->message != 0) && ((pActivator->pev->flags & 8) != 0)) {
      UTIL_ShowMessage(gpGlobals->pStringBase + peVar5->message,pActivator->pev->pContainingEntity);
      peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
    }
    p1Var3 = gpGlobals;
    fVar1 = (this->super_CBaseToggle).m_flWait;
    if (fVar1 <= 0.0) {
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
      __pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
      __delta = 0;
      peVar5->nextthink = p1Var3->time + 0.1;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __pfn = CBaseEntity::SUB_Remove;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __delta = 0;
    }
    else {
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __pfn = MultiWaitOver;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __delta = 0;
      peVar5->nextthink = fVar1 + p1Var3->time;
    }
  }
  return;
}


// CBaseTrigger::MultiWaitOver  @ 00116610  (line 1109)

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


// CBaseTrigger::CounterUse  @ 00118e20  (line 1126)

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
  byte bVar7;
  
                    /* Unresolved local var: BOOL fTellActivator@[???] */
  bVar7 = 0;
  piVar1 = &(this->super_CBaseToggle).m_cTriggersLeft;
  *piVar1 = *piVar1 + -1;
  this_00 = &(this->super_CBaseToggle).m_hActivator;
  EHANDLE::operator=(this_00,pActivator);
  if ((this->super_CBaseToggle).m_cTriggersLeft < 0) {
    return;
  }
  iVar2 = EHANDLE::operator_int(this_00);
  if (iVar2 != 0) {
    pCVar3 = EHANDLE::operator->(this_00);
    iVar2 = 7;
    bVar6 = gpGlobals->pStringBase + pCVar3->pev->classname == (char *)0x0;
    pcVar4 = gpGlobals->pStringBase + pCVar3->pev->classname;
    pcVar5 = "player";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
      pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
    } while (bVar6);
    if ((bVar6) &&
       ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
         spawnflags & 1) == 0)) {
      iVar2 = (this->super_CBaseToggle).m_cTriggersLeft;
      if (iVar2 != 0) {
        if (iVar2 == 2) {
          pActivator = (CBaseEntity *)s_Only_2_more_to_go____00163939;
        }
        else if (iVar2 == 3) {
          pActivator = (CBaseEntity *)s_Only_3_more_to_go____0016394e;
        }
        else if (iVar2 == 1) {
          pActivator = (CBaseEntity *)s_Only_1_more_to_go____00163924;
        }
        else {
          pActivator = (CBaseEntity *)s_There_are_more_to_go____00163963;
        }
                    /* WARNING: Could not recover jumptable at 0x00118f28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*g_engfuncs.pfnAlertMessage)(at_console,(char *)pActivator);
        return;
      }
      (*g_engfuncs.pfnAlertMessage)(at_console,"Sequence completed!");
      goto LAB_00118e73;
    }
  }
  if ((this->super_CBaseToggle).m_cTriggersLeft != 0) {
    return;
  }
LAB_00118e73:
  EHANDLE::operator_cast_to_CBaseEntity_(this_00);
  if ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
       nextthink <= gpGlobals->time) &&
     (iVar2 = UTIL_IsMasterTriggered((this->super_CBaseToggle).m_sMaster), iVar2 != 0)) {
    ActivateMultiTrigger(this,pActivator);
    return;
  }
  return;
}


// CTriggerCounter::~CTriggerCounter  @ 0011d4b0  (line 1167)

/* DWARF original prototype: void ~CTriggerCounter(CTriggerCounter * this, int __in_chrg) */

void __thiscall CTriggerCounter::~CTriggerCounter(CTriggerCounter *this,int __in_chrg)

{
  return;
}


// trigger_counter  @ 0011b070  (line 1172)

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
  *puVar1 = &PTR__CTriggerCounter_00164c1c;
  puVar1[1] = pev;
  return;
}


// CTriggerCounter::Spawn  @ 00116630  (line 1175)

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


// CTriggerVolume::~CTriggerVolume  @ 0011d4a0  (line 1187)

/* DWARF original prototype: void ~CTriggerVolume(CTriggerVolume * this, int __in_chrg) */

void __thiscall CTriggerVolume::~CTriggerVolume(CTriggerVolume *this,int __in_chrg)

{
  return;
}


// trigger_transition  @ 0011b0e0  (line 1193)

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
  *puVar1 = &PTR__CTriggerVolume_00164d2c;
  puVar1[1] = pev;
  return;
}


// CTriggerVolume::Spawn  @ 00116670  (line 1197)

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


// CFireAndDie::~CFireAndDie  @ 0011d490  (line 1207)

/* DWARF original prototype: void ~CFireAndDie(CFireAndDie * this, int __in_chrg) */

void __thiscall CFireAndDie::~CFireAndDie(CFireAndDie *this,int __in_chrg)

{
  return;
}


// CFireAndDie::ObjectCaps  @ 0011d3b0  (line 1213)

/* DWARF original prototype: int ObjectCaps(CFireAndDie * this) */

int __thiscall CFireAndDie::ObjectCaps(CFireAndDie *this)

{
  return 0x82;
}


// fireanddie  @ 0011b150  (line 1215)

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
  *puVar1 = &PTR__CFireAndDie_00164e38;
  puVar1[1] = pev;
  return;
}


// CFireAndDie::Spawn  @ 001166e0  (line 1218)

/* DWARF original prototype: void Spawn(CFireAndDie * this) */

void __thiscall CFireAndDie::Spawn(CFireAndDie *this)

{
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->classname =
       (string_t)("?fireanddie" + (1 - (int)gpGlobals->pStringBase));
  return;
}


// CFireAndDie::Precache  @ 00116720  (line 1227)

/* DWARF original prototype: void Precache(CFireAndDie * this) */

void __thiscall CFireAndDie::Precache(CFireAndDie *this)

{
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->nextthink =
       gpGlobals->time + (this->super_CBaseDelay).m_flDelay;
  return;
}


// CFireAndDie::Think  @ 00116ce0  (line 1232)

/* DWARF original prototype: void Think(CFireAndDie * this) */

void __thiscall CFireAndDie::Think(CFireAndDie *this)

{
  CBaseDelay::SUB_UseTargets(&this->super_CBaseDelay,(CBaseEntity *)this,USE_TOGGLE,0.0);
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CChangeLevel::~CChangeLevel  @ 0011d480  (line 1239)

/* DWARF original prototype: void ~CChangeLevel(CChangeLevel * this, int __in_chrg) */

void __thiscall CChangeLevel::~CChangeLevel(CChangeLevel *this,int __in_chrg)

{
  return;
}


// trigger_changelevel  @ 0011b1c0  (line 1265)

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
  *puVar1 = &PTR__CChangeLevel_00164f44;
  puVar1[1] = pev;
  return;
}


// CChangeLevel::Restore  @ 001185a0  (line 1276)

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


// CChangeLevel::Save  @ 00118660  (line 1276)

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


// CChangeLevel::KeyValue  @ 001174c0  (line 1283)

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
    sVar1 = strlen(pkvd->szValue);
    if (0x1f < sVar1) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Map name \'%s\' too long (32 chars)\n");
    }
    __strcpy_chk();
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
      sVar1 = strlen(pkvd->szValue);
      if (0x1f < sVar1) {
        (*g_engfuncs.pfnAlertMessage)(at_error,"Landmark name \'%s\' too long (32 chars)\n");
      }
      __strcpy_chk();
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


// CChangeLevel::Spawn  @ 00119e30  (line 1318)

/* DWARF original prototype: void Spawn(CChangeLevel * this) */

void __thiscall CChangeLevel::Spawn(CChangeLevel *this)

{
  int *piVar1;
  entvars_t *peVar2;
  longdouble extraout_ST0;
  
  if (this->m_szMapName[0] == '\0') {
    (*g_engfuncs.pfnAlertMessage)(at_console,"a trigger_changelevel doesn\'t have a map");
  }
  if (this->m_szLandmarkName[0] == '\0') {
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"trigger_changelevel to %s doesn\'t have a landmark",this->m_szMapName);
  }
  peVar2 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar2->targetname != 0) {
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__pfn = UseChangeLevel;
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__delta = 0;
  }
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
  (*g_engfuncs.pfnCVarGetFloat)("showtriggers");
  if (extraout_ST0 == (longdouble)0) {
    piVar1 = &((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 0x80;
  }
  if ((((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->spawnflags & 2) == 0) {
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnTouch.__pfn = TouchChangeLevel;
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnTouch.__delta = 0;
  }
  return;
}


// CChangeLevel::ExecuteChangeLevel  @ 00116740  (line 1337)

/* DWARF original prototype: void ExecuteChangeLevel(CChangeLevel * this) */

void __thiscall CChangeLevel::ExecuteChangeLevel(CChangeLevel *this)

{
  (*g_engfuncs.pfnMessageBegin)(2,0x20,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(3);
  (*g_engfuncs.pfnWriteByte)(3);
  (*g_engfuncs.pfnMessageEnd)();
  (*g_engfuncs.pfnMessageBegin)(2,0x1e,(float *)0x0,(edict_t *)0x0);
                    /* WARNING: Could not recover jumptable at 0x001167aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CChangeLevel::FindLandmark  @ 0011b230  (line 1352)

edict_t * CChangeLevel::FindLandmark(char *pLandmarkName)

{
  edict_t *peVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  byte bVar6;
  
                    /* Unresolved local var: edict_t * pentLandmark@[???] */
  bVar6 = 0;
  peVar1 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"targetname",pLandmarkName);
  do {
    if ((peVar1 == (edict_t *)0x0) ||
       (iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1), iVar2 == 0)) {
      (*g_engfuncs.pfnAlertMessage)(at_error,"Can\'t find landmark %s\n",pLandmarkName);
      return (edict_t *)0x0;
    }
    iVar2 = 0xe;
    bVar5 = gpGlobals->pStringBase + (peVar1->v).classname == (char *)0x0;
    pcVar3 = gpGlobals->pStringBase + (peVar1->v).classname;
    pcVar4 = "info_landmark";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + (uint)bVar6 * -2 + 1;
      pcVar4 = pcVar4 + (uint)bVar6 * -2 + 1;
    } while (bVar5);
    if (bVar5) {
      return peVar1;
    }
    peVar1 = (*g_engfuncs.pfnFindEntityByString)(peVar1,"targetname",pLandmarkName);
  } while( true );
}


// CChangeLevel::UseChangeLevel  @ 0011b2f0  (line 1375)

/* DWARF original prototype: void UseChangeLevel(CChangeLevel * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CChangeLevel::UseChangeLevel
          (CChangeLevel *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  _2globalvars_t *p1Var1;
  char *pcVar2;
  string_t sVar3;
  edict_t *peVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  entvars_t *peVar8;
  char *__haystack;
  CBaseEntity *pEntity;
  
  p1Var1 = gpGlobals;
                    /* Unresolved local var: edict_t * pentLandmark@[???]
                       Unresolved local var: LEVELLIST[16] levels@[???]
                       Unresolved local var: CBaseEntity * pPlayer@[???] */
  if (gpGlobals->deathmatch != 0.0) {
                    /* Unresolved local var: char * pDot@[???] */
    if (this->m_szMapName[0] == '\0') {
      sVar3 = (*g_engfuncs.pfnAllocString)("2fort");
      p1Var1->mapname = sVar3;
      builtin_strncpy(this->m_szMapName,"2for",4);
      this->m_szMapName[4] = 't';
      this->m_szMapName[5] = '\0';
    }
    __haystack = this->m_szMapName;
    pcVar2 = strstr(__haystack,".bsp");
    if (pcVar2 == (char *)0x0) {
      __strcpy_chk(st_szNextMap,__haystack,0x20);
    }
    else {
      __strncpy_chk(st_szNextMap,__haystack,(int)pcVar2 - (int)__haystack,0x20);
    }
    goto LAB_0011b36b;
  }
  peVar8 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (gpGlobals->time == peVar8->dmgtime) {
    return;
  }
  peVar8->dmgtime = gpGlobals->time;
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
                       Unresolved local var: int inVolume@[???] */
  pcVar2 = this->m_szLandmarkName;
  uVar5 = (*pEntity->_vptr_CBaseEntity[7])(pEntity);
  if (((uVar5 & 0x80) == 0) && (iVar6 = InTransitionVolume(pEntity,pcVar2), iVar6 == 0)) {
                    /* WARNING: Could not recover jumptable at 0x0011b539. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"Player isn\'t in the transition volume %s, aborting\n");
    return;
  }
  if (this->m_changeTarget != 0) {
                    /* Unresolved local var: CFireAndDie * pFireAndDie@[DW_OP_reg0(EAX)]
                       Unresolved local var: entvars_t * pev@[???] */
    peVar4 = (*g_engfuncs.pfnCreateEntity)();
    peVar8 = &peVar4->v;
    if (peVar4 == (edict_t *)0x0) {
      peVar8 = (entvars_t *)0x0;
    }
    if ((peVar8->pContainingEntity == (edict_t *)0x0) ||
       (puVar7 = peVar8->pContainingEntity->pvPrivateData, puVar7 == (undefined4 *)0x0)) {
      puVar7 = CBaseEntity::operator_new(0x47c,peVar8);
      *puVar7 = &PTR__CFireAndDie_00164e38;
      puVar7[1] = peVar8;
      if (puVar7 == (undefined4 *)0x0) goto LAB_0011b447;
    }
    *(int *)(puVar7[1] + 0x1c8) = this->m_changeTarget;
    iVar6 = puVar7[1];
    puVar7[0x11d] = this->m_changeTargetDelay;
    peVar8 = pEntity->pev;
    *(vec_t *)(iVar6 + 8) = (peVar8->origin).x;
    *(vec_t *)(iVar6 + 0xc) = (peVar8->origin).y;
    *(vec_t *)(iVar6 + 0x10) = (peVar8->origin).z;
    DispatchSpawn(*(edict_t **)(puVar7[1] + 0x208));
  }
LAB_0011b447:
  __strcpy_chk(st_szNextMap,this->m_szMapName,0x20);
  EHANDLE::operator=(&(this->super_CBaseTrigger).super_CBaseToggle.m_hActivator,pActivator);
  CBaseDelay::SUB_UseTargets((CBaseDelay *)this,pActivator,USE_TOGGLE,0.0);
  st_szNextSpot[0] = '\0';
  peVar4 = FindLandmark(pcVar2);
  if ((peVar4 != (edict_t *)0x0) &&
     (iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4), iVar6 != 0)) {
    __strcpy_chk(st_szNextSpot,pcVar2,0x20);
    p1Var1 = gpGlobals;
    (gpGlobals->vecLandmarkOffset).x = (peVar4->v).origin.x;
    (p1Var1->vecLandmarkOffset).y = (peVar4->v).origin.y;
    (p1Var1->vecLandmarkOffset).z = (peVar4->v).origin.z;
  }
  (*g_engfuncs.pfnAlertMessage)(at_console,"CHANGE LEVEL: %s %s\n",st_szNextMap,st_szNextSpot);
LAB_0011b36b:
                    /* WARNING: Could not recover jumptable at 0x0011b38d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnChangeLevel)(st_szNextMap,(char *)0x0);
  return;
}


// CChangeLevel::ChangeLevelNow  @ 0011b9e0  (line 1380)

/* DWARF original prototype: void ChangeLevelNow(CChangeLevel * this, CBaseEntity * pActivator) */

void __thiscall CChangeLevel::ChangeLevelNow(CChangeLevel *this,CBaseEntity *pActivator)

{
  _2globalvars_t *p1Var1;
  char *pcVar2;
  string_t sVar3;
  edict_t *peVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  entvars_t *peVar8;
  char *__haystack;
  CBaseEntity *pEntity;
  
                    /* Unresolved local var: edict_t * pentLandmark@[???]
                       Unresolved local var: LEVELLIST[16] levels@[???]
                       Unresolved local var: CBaseEntity * pPlayer@[???] */
  p1Var1 = gpGlobals;
  if (gpGlobals->deathmatch != 0.0) {
                    /* Unresolved local var: char * pDot@[???] */
    if (this->m_szMapName[0] == '\0') {
      sVar3 = (*g_engfuncs.pfnAllocString)("2fort");
      p1Var1->mapname = sVar3;
      builtin_strncpy(this->m_szMapName,"2for",4);
      this->m_szMapName[4] = 't';
      this->m_szMapName[5] = '\0';
    }
    __haystack = this->m_szMapName;
    pcVar2 = strstr(__haystack,".bsp");
    if (pcVar2 == (char *)0x0) {
      __strcpy_chk(st_szNextMap,__haystack,0x20);
    }
    else {
      __strncpy_chk(st_szNextMap,__haystack,(int)pcVar2 - (int)__haystack,0x20);
    }
    goto LAB_0011ba5b;
  }
  peVar8 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (gpGlobals->time == peVar8->dmgtime) {
    return;
  }
  peVar8->dmgtime = gpGlobals->time;
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
                       Unresolved local var: int inVolume@[???] */
  pcVar2 = this->m_szLandmarkName;
  uVar5 = (*pEntity->_vptr_CBaseEntity[7])(pEntity);
  if (((uVar5 & 0x80) == 0) && (iVar6 = InTransitionVolume(pEntity,pcVar2), iVar6 == 0)) {
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"Player isn\'t in the transition volume %s, aborting\n",pcVar2);
    return;
  }
  if (this->m_changeTarget != 0) {
                    /* Unresolved local var: CFireAndDie * pFireAndDie@[DW_OP_reg0(EAX)]
                       Unresolved local var: entvars_t * pev@[???] */
    peVar4 = (*g_engfuncs.pfnCreateEntity)();
    peVar8 = &peVar4->v;
    if (peVar4 == (edict_t *)0x0) {
      peVar8 = (entvars_t *)0x0;
    }
    if ((peVar8->pContainingEntity == (edict_t *)0x0) ||
       (puVar7 = peVar8->pContainingEntity->pvPrivateData, puVar7 == (undefined4 *)0x0)) {
      puVar7 = CBaseEntity::operator_new(0x47c,peVar8);
      *puVar7 = &PTR__CFireAndDie_00164e38;
      puVar7[1] = peVar8;
      if (puVar7 == (undefined4 *)0x0) goto LAB_0011bb37;
    }
    *(int *)(puVar7[1] + 0x1c8) = this->m_changeTarget;
    iVar6 = puVar7[1];
    puVar7[0x11d] = this->m_changeTargetDelay;
    peVar8 = pEntity->pev;
    *(vec_t *)(iVar6 + 8) = (peVar8->origin).x;
    *(vec_t *)(iVar6 + 0xc) = (peVar8->origin).y;
    *(vec_t *)(iVar6 + 0x10) = (peVar8->origin).z;
    DispatchSpawn(*(edict_t **)(puVar7[1] + 0x208));
  }
LAB_0011bb37:
  __strcpy_chk(st_szNextMap,this->m_szMapName,0x20);
  EHANDLE::operator=(&(this->super_CBaseTrigger).super_CBaseToggle.m_hActivator,pActivator);
  CBaseDelay::SUB_UseTargets((CBaseDelay *)this,pActivator,USE_TOGGLE,0.0);
  st_szNextSpot[0] = '\0';
  peVar4 = FindLandmark(pcVar2);
  if ((peVar4 != (edict_t *)0x0) &&
     (iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4), iVar6 != 0)) {
    __strcpy_chk(st_szNextSpot,pcVar2,0x20);
    p1Var1 = gpGlobals;
    (gpGlobals->vecLandmarkOffset).x = (peVar4->v).origin.x;
    (p1Var1->vecLandmarkOffset).y = (peVar4->v).origin.y;
    (p1Var1->vecLandmarkOffset).z = (peVar4->v).origin.z;
  }
  (*g_engfuncs.pfnAlertMessage)(at_console,"CHANGE LEVEL: %s %s\n",st_szNextMap,st_szNextSpot);
LAB_0011ba5b:
                    /* WARNING: Could not recover jumptable at 0x0011ba7d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnChangeLevel)(st_szNextMap,(char *)0x0);
  return;
}


// CChangeLevel::TouchChangeLevel  @ 0011b650  (line 1456)

/* DWARF original prototype: void TouchChangeLevel(CChangeLevel * this, CBaseEntity * pOther) */

void __thiscall CChangeLevel::TouchChangeLevel(CChangeLevel *this,CBaseEntity *pOther)

{
  _2globalvars_t *p1Var1;
  char *pcVar2;
  edict_t *peVar3;
  uint uVar4;
  string_t sVar5;
  undefined4 *puVar6;
  int iVar7;
  entvars_t *peVar8;
  CBaseEntity *pEntity;
  char *pcVar9;
  bool bVar10;
  
  p1Var1 = gpGlobals;
  iVar7 = 7;
  bVar10 = gpGlobals->pStringBase + pOther->pev->classname == (char *)0x0;
  pcVar2 = gpGlobals->pStringBase + pOther->pev->classname;
  pcVar9 = "player";
  do {
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    bVar10 = *pcVar2 == *pcVar9;
    pcVar2 = pcVar2 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar10);
  if (!bVar10) {
    return;
  }
                    /* Unresolved local var: edict_t * pentLandmark@[???]
                       Unresolved local var: LEVELLIST[16] levels@[???]
                       Unresolved local var: CBaseEntity * pPlayer@[???] */
  if (gpGlobals->deathmatch != 0.0) {
                    /* Unresolved local var: char * pDot@[???] */
    if (this->m_szMapName[0] == '\0') {
      sVar5 = (*g_engfuncs.pfnAllocString)("2fort");
      p1Var1->mapname = sVar5;
      builtin_strncpy(this->m_szMapName,"2for",4);
      this->m_szMapName[4] = 't';
      this->m_szMapName[5] = '\0';
    }
    pcVar9 = this->m_szMapName;
    pcVar2 = strstr(pcVar9,".bsp");
    if (pcVar2 == (char *)0x0) {
      __strcpy_chk(st_szNextMap,pcVar9,0x20);
    }
    else {
      __strncpy_chk(st_szNextMap,pcVar9,(int)pcVar2 - (int)pcVar9,0x20);
    }
    goto LAB_0011b714;
  }
  peVar8 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (gpGlobals->time == peVar8->dmgtime) {
    return;
  }
  peVar8->dmgtime = gpGlobals->time;
  peVar3 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar3 == (edict_t *)0x0) &&
     (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 == (edict_t *)0x0)) {
    pEntity = (CBaseEntity *)0x0;
  }
  else {
    pEntity = peVar3->pvPrivateData;
  }
  pcVar2 = this->m_szLandmarkName;
                    /* Unresolved local var: edict_t * pentVolume@[???]
                       Unresolved local var: int inVolume@[???] */
  uVar4 = (*pEntity->_vptr_CBaseEntity[7])(pEntity);
  if (((uVar4 & 0x80) == 0) && (iVar7 = InTransitionVolume(pEntity,pcVar2), iVar7 == 0)) {
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"Player isn\'t in the transition volume %s, aborting\n",pcVar2);
    return;
  }
  if (this->m_changeTarget != 0) {
                    /* Unresolved local var: CFireAndDie * pFireAndDie@[DW_OP_reg0(EAX)]
                       Unresolved local var: entvars_t * pev@[???] */
    peVar3 = (*g_engfuncs.pfnCreateEntity)();
    peVar8 = &peVar3->v;
    if (peVar3 == (edict_t *)0x0) {
      peVar8 = (entvars_t *)0x0;
    }
    if ((peVar8->pContainingEntity == (edict_t *)0x0) ||
       (puVar6 = peVar8->pContainingEntity->pvPrivateData, puVar6 == (undefined4 *)0x0)) {
      puVar6 = CBaseEntity::operator_new(0x47c,peVar8);
      *puVar6 = &PTR__CFireAndDie_00164e38;
      puVar6[1] = peVar8;
      if (puVar6 == (undefined4 *)0x0) goto LAB_0011b7b5;
    }
    *(int *)(puVar6[1] + 0x1c8) = this->m_changeTarget;
    iVar7 = puVar6[1];
    puVar6[0x11d] = this->m_changeTargetDelay;
    peVar8 = pEntity->pev;
    *(vec_t *)(iVar7 + 8) = (peVar8->origin).x;
    *(vec_t *)(iVar7 + 0xc) = (peVar8->origin).y;
    *(vec_t *)(iVar7 + 0x10) = (peVar8->origin).z;
    DispatchSpawn(*(edict_t **)(puVar6[1] + 0x208));
  }
LAB_0011b7b5:
  __strcpy_chk(st_szNextMap,this->m_szMapName,0x20);
  EHANDLE::operator=(&(this->super_CBaseTrigger).super_CBaseToggle.m_hActivator,pOther);
  CBaseDelay::SUB_UseTargets((CBaseDelay *)this,pOther,USE_TOGGLE,0.0);
  st_szNextSpot[0] = '\0';
  peVar3 = FindLandmark(pcVar2);
  if ((peVar3 != (edict_t *)0x0) &&
     (iVar7 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3), iVar7 != 0)) {
    __strcpy_chk(st_szNextSpot,pcVar2,0x20);
    p1Var1 = gpGlobals;
    (gpGlobals->vecLandmarkOffset).x = (peVar3->v).origin.x;
    (p1Var1->vecLandmarkOffset).y = (peVar3->v).origin.y;
    (p1Var1->vecLandmarkOffset).z = (peVar3->v).origin.z;
  }
  (*g_engfuncs.pfnAlertMessage)(at_console,"CHANGE LEVEL: %s %s\n",st_szNextMap,st_szNextSpot);
LAB_0011b714:
                    /* WARNING: Could not recover jumptable at 0x0011b736. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnChangeLevel)(st_szNextMap,(char *)0x0);
  return;
}


// CChangeLevel::AddTransitionToList  @ 0011bd30  (line 1467)

int CChangeLevel::AddTransitionToList
              (_LEVELLIST *pLevelList,int listCount,char *pMapName,char *pLandmarkName,
              edict_t *pentLandmark)

{
  int iVar1;
  _LEVELLIST *p9Var2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if ((((pLevelList == (_LEVELLIST *)0x0) || (pMapName == (char *)0x0)) ||
      (pLandmarkName == (char *)0x0)) || (pentLandmark == (edict_t *)0x0)) {
    return 0;
  }
  if (0 < listCount) {
    iVar3 = 0;
    p9Var2 = pLevelList;
    do {
      while (pentLandmark == p9Var2->pentLandmark) {
        iVar1 = strcmp(p9Var2->mapName,pMapName);
        if (iVar1 == 0) {
          return 0;
        }
        iVar3 = iVar3 + 1;
        p9Var2 = p9Var2 + 1;
        if (listCount == iVar3) goto LAB_0011bdad;
      }
      iVar3 = iVar3 + 1;
      p9Var2 = p9Var2 + 1;
    } while (listCount != iVar3);
  }
LAB_0011bdad:
                    /* Unresolved local var: int i@[???] */
  p9Var2 = pLevelList + listCount;
  __strcpy_chk(p9Var2,pMapName,0x20);
  __strcpy_chk(p9Var2->landmarkName,pLandmarkName,0x20);
  p9Var2->pentLandmark = pentLandmark;
  (p9Var2->vecLandmarkOrigin).x = (pentLandmark->v).origin.x;
  (p9Var2->vecLandmarkOrigin).y = (pentLandmark->v).origin.y;
  (p9Var2->vecLandmarkOrigin).z = (pentLandmark->v).origin.z;
  return 1;
}


// BuildChangeList  @ 0011c270  (line 1488)

int BuildChangeList(_LEVELLIST *pLevelList,int maxList)

{
  CBaseEntity *pCVar1;
  edict_t *peVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char *pdata;
  uint uVar8;
  edict_t *peVar9;
  undefined4 *puVar10;
  _LEVELLIST *p9Var11;
  uint uStack_103c;
  int iStack_1038;
  char *pcStack_1034;
  CSaveRestoreBuffer CStack_1020;
  undefined4 auStack_101c [512];
  uint auStack_81c [515];
  
  peVar2 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"classname","trigger_changelevel");
  if ((peVar2 == (edict_t *)0x0) ||
     (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2), iVar3 == 0)) {
    return 0;
  }
  iVar3 = 0;
  do {
    iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2);
    if (iVar4 == 0) break;
    peVar9 = (peVar2->v).pContainingEntity;
    if ((peVar9 == (edict_t *)0x0) ||
       (puVar10 = peVar9->pvPrivateData, puVar10 == (undefined4 *)0x0)) {
      puVar10 = CBaseEntity::operator_new(0x55c,&peVar2->v);
      *puVar10 = &PTR__CChangeLevel_00164f44;
      puVar10[1] = &peVar2->v;
      if (puVar10 != (undefined4 *)0x0) goto LAB_0011c0ff;
    }
    else {
LAB_0011c0ff:
      peVar9 = CChangeLevel::FindLandmark((char *)(puVar10 + 0x14d));
      if ((peVar9 != (edict_t *)0x0) && (pLevelList != (_LEVELLIST *)0x0)) {
        if (0 < iVar3) {
          iVar4 = 0;
          p9Var11 = pLevelList;
          do {
            if ((peVar9 == p9Var11->pentLandmark) &&
               (iVar5 = strcmp(p9Var11->mapName,(char *)(puVar10 + 0x145)), iVar5 == 0))
            goto LAB_0011c169;
            iVar4 = iVar4 + 1;
            p9Var11 = p9Var11 + 1;
          } while (iVar4 != iVar3);
        }
        iVar4 = iVar3 + 1;
        p9Var11 = pLevelList + iVar3;
        __strcpy_chk(p9Var11,puVar10 + 0x145,0x20);
        __strcpy_chk(p9Var11->landmarkName,puVar10 + 0x14d,0x20);
        p9Var11->pentLandmark = peVar9;
        (p9Var11->vecLandmarkOrigin).x = (peVar9->v).origin.x;
        (p9Var11->vecLandmarkOrigin).y = (peVar9->v).origin.y;
        (p9Var11->vecLandmarkOrigin).z = (peVar9->v).origin.z;
        iVar3 = iVar4;
        if (maxList <= iVar4) break;
      }
    }
LAB_0011c169:
    peVar2 = (*g_engfuncs.pfnFindEntityByString)(peVar2,"classname","trigger_changelevel");
  } while (peVar2 != (edict_t *)0x0);
  pdata = gpGlobals->pSaveData;
  if (((SAVERESTOREDATA *)pdata == (SAVERESTOREDATA *)0x0) ||
     (((SAVERESTOREDATA *)pdata)->pTable == (ENTITYTABLE *)0x0)) {
    return iVar3;
  }
  CSaveRestoreBuffer::CSaveRestoreBuffer(&CStack_1020,(SAVERESTOREDATA *)pdata);
  if (0 < iVar3) {
    pcStack_1034 = pLevelList->landmarkName;
    iStack_1038 = 0;
    do {
      peVar2 = (*g_engfuncs.pfnEntitiesInPVS)(*(edict_t **)(pcStack_1034 + 0x20));
      iVar4 = 0;
      if (peVar2 != (edict_t *)0x0) {
        do {
          iVar5 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2);
          if (iVar5 == 0) break;
          pCVar1 = peVar2->pvPrivateData;
          if ((pCVar1 != (CBaseEntity *)0x0) &&
             (uVar8 = (*pCVar1->_vptr_CBaseEntity[7])(pCVar1), -1 < (int)uVar8)) {
            if ((uVar8 & 2) == 0) {
              if (pCVar1->pev->globalname != 0) {
                uVar8 = 0x10000000;
                uStack_103c = 0;
                goto LAB_0011c057;
              }
            }
            else {
              if (pCVar1->pev->globalname == 0) {
                uVar8 = 0x20000000;
              }
              else {
                uVar8 = 0x30000000;
                uStack_103c = 0x20000000;
LAB_0011c057:
                iVar5 = CBaseEntity::IsDormant(pCVar1);
                if ((iVar5 != 0) && (uVar8 = uStack_103c, uStack_103c == 0)) goto LAB_0011c070;
              }
              auStack_101c[iVar4] = pCVar1;
              auStack_81c[iVar4] = uVar8;
              iVar4 = iVar4 + 1;
              if (0x200 < iVar4) {
                pdata = "Too many entities across a transition!";
                (*g_engfuncs.pfnAlertMessage)(at_error,"Too many entities across a transition!");
              }
            }
          }
LAB_0011c070:
          peVar2 = (peVar2->v).chain;
        } while (peVar2 != (edict_t *)0x0);
        if (iVar4 != 0) {
          iVar5 = 0;
          do {
            while (uVar8 = auStack_81c[iVar5], uVar8 == 0) {
LAB_0011bf80:
              iVar5 = iVar5 + 1;
              if (iVar5 == iVar4) goto LAB_0011bfe0;
            }
            pCVar1 = (CBaseEntity *)auStack_101c[iVar5];
            uVar6 = (*pCVar1->_vptr_CBaseEntity[7])(pCVar1);
            if (((uVar6 & 0x80) == 0) &&
               (iVar7 = CChangeLevel::InTransitionVolume(pCVar1,pcStack_1034), iVar7 == 0))
            goto LAB_0011bf80;
            pdata = (char *)CSaveRestoreBuffer::EntityIndex(&CStack_1020,pCVar1);
            CSaveRestoreBuffer::EntityFlagsSet
                      (&CStack_1020,(int)pdata,uVar8 | 1 << ((byte)iStack_1038 & 0x1f));
            iVar5 = iVar5 + 1;
          } while (iVar5 != iVar4);
        }
      }
LAB_0011bfe0:
      iStack_1038 = iStack_1038 + 1;
      pcStack_1034 = pcStack_1034 + 0x50;
    } while (iVar3 != iStack_1038);
  }
  CSaveRestoreBuffer::~CSaveRestoreBuffer(&CStack_1020,(int)pdata);
  return iVar3;
}


// CChangeLevel::InTransitionVolume  @ 00117a40  (line 1492)

int __regparm3 CChangeLevel::InTransitionVolume(CBaseEntity *pEntity,char *pVolumeName)

{
  CBaseEntity *this;
  edict_t *peVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  byte bVar6;
  int local_24;
  CBaseEntity *local_20;
  
                    /* Unresolved local var: edict_t * pentVolume@[???]
                       Unresolved local var: int inVolume@[???] */
  bVar6 = 0;
  local_20 = pEntity;
  if ((pEntity->pev->movetype == 0xc) && (peVar1 = pEntity->pev->aiment, peVar1 != (edict_t *)0x0))
  {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    local_20 = peVar1->pvPrivateData;
  }
  peVar1 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"targetname",pVolumeName);
  local_24 = 1;
  do {
    if ((peVar1 == (edict_t *)0x0) ||
       (iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1), iVar2 == 0)) {
                    /* Unresolved local var: CBaseEntity * pVolume@[???] */
      return local_24;
    }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    this = peVar1->pvPrivateData;
    if (this != (CBaseEntity *)0x0) {
      bVar5 = gpGlobals->pStringBase + this->pev->classname == (char *)0x0;
      iVar2 = 0x13;
      pcVar3 = gpGlobals->pStringBase + this->pev->classname;
      pcVar4 = "trigger_transition";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + (uint)bVar6 * -2 + 1;
        pcVar4 = pcVar4 + (uint)bVar6 * -2 + 1;
      } while (bVar5);
      if (bVar5) {
        iVar2 = CBaseEntity::Intersects(this,local_20);
        if (iVar2 != 0) {
          return 1;
        }
        local_24 = 0;
      }
    }
    peVar1 = (*g_engfuncs.pfnFindEntityByString)(peVar1,"targetname",pVolumeName);
  } while( true );
}


// CChangeLevel::InTransitionVolume  @ 0011be30  (line 1493)

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


// CChangeLevel::ChangeList  @ 0011be80  (line 1536)

int CChangeLevel::ChangeList(_LEVELLIST *pLevelList,int maxList)

{
  CBaseEntity *pCVar1;
  edict_t *peVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char *pdata;
  uint uVar8;
  edict_t *peVar9;
  undefined4 *puVar10;
  _LEVELLIST *p9Var11;
  uint local_103c;
  int local_1038;
  char *local_1034;
  CSaveRestoreBuffer local_1020;
  undefined4 auStack_101c [512];
  uint auStack_81c [515];
  
                    /* Unresolved local var: edict_t * pentChangelevel@[???]
                       Unresolved local var: edict_t * pentLandmark@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
  peVar2 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"classname","trigger_changelevel");
  if ((peVar2 == (edict_t *)0x0) ||
     (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2), iVar3 == 0)) {
    return 0;
  }
  iVar3 = 0;
  do {
    iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2);
    if (iVar4 == 0) break;
    peVar9 = (peVar2->v).pContainingEntity;
                    /* Unresolved local var: CChangeLevel * pTrigger@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: entvars_t * pev@[???] */
    if ((peVar9 == (edict_t *)0x0) ||
       (puVar10 = peVar9->pvPrivateData, puVar10 == (undefined4 *)0x0)) {
      puVar10 = CBaseEntity::operator_new(0x55c,&peVar2->v);
      *puVar10 = &PTR__CChangeLevel_00164f44;
      puVar10[1] = &peVar2->v;
      if (puVar10 != (undefined4 *)0x0) goto LAB_0011c0ff;
    }
    else {
LAB_0011c0ff:
      peVar9 = FindLandmark((char *)(puVar10 + 0x14d));
                    /* Unresolved local var: int i@[???] */
      if ((peVar9 != (edict_t *)0x0) && (pLevelList != (_LEVELLIST *)0x0)) {
        if (0 < iVar3) {
          iVar4 = 0;
          p9Var11 = pLevelList;
          do {
            if ((peVar9 == p9Var11->pentLandmark) &&
               (iVar5 = strcmp(p9Var11->mapName,(char *)(puVar10 + 0x145)), iVar5 == 0))
            goto LAB_0011c169;
            iVar4 = iVar4 + 1;
            p9Var11 = p9Var11 + 1;
          } while (iVar4 != iVar3);
        }
                    /* Unresolved local var: int i@[???] */
        iVar4 = iVar3 + 1;
        p9Var11 = pLevelList + iVar3;
        __strcpy_chk(p9Var11,puVar10 + 0x145,0x20);
        __strcpy_chk(p9Var11->landmarkName,puVar10 + 0x14d,0x20);
        p9Var11->pentLandmark = peVar9;
        (p9Var11->vecLandmarkOrigin).x = (peVar9->v).origin.x;
        (p9Var11->vecLandmarkOrigin).y = (peVar9->v).origin.y;
        (p9Var11->vecLandmarkOrigin).z = (peVar9->v).origin.z;
        iVar3 = iVar4;
        if (maxList <= iVar4) break;
      }
    }
LAB_0011c169:
    peVar2 = (*g_engfuncs.pfnFindEntityByString)(peVar2,"classname","trigger_changelevel");
  } while (peVar2 != (edict_t *)0x0);
  pdata = gpGlobals->pSaveData;
  if (((SAVERESTOREDATA *)pdata == (SAVERESTOREDATA *)0x0) ||
     (((SAVERESTOREDATA *)pdata)->pTable == (ENTITYTABLE *)0x0)) {
    return iVar3;
  }
                    /* Unresolved local var: CSave saveHelper@[???] */
  CSaveRestoreBuffer::CSaveRestoreBuffer(&local_1020,(SAVERESTOREDATA *)pdata);
  if (0 < iVar3) {
    local_1034 = pLevelList->landmarkName;
    local_1038 = 0;
    do {
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: int entityCount@[???]
                       Unresolved local var: CBaseEntity *[512] pEntList@[???]
                       Unresolved local var: int[512] entityFlags@[???]
                       Unresolved local var: edict_t * pent@[???] */
      peVar2 = (*g_engfuncs.pfnEntitiesInPVS)(*(edict_t **)(local_1034 + 0x20));
      iVar4 = 0;
      if (peVar2 != (edict_t *)0x0) {
        do {
          iVar5 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2);
          if (iVar5 == 0) break;
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
          pCVar1 = peVar2->pvPrivateData;
                    /* Unresolved local var: int caps@[???] */
          if ((pCVar1 != (CBaseEntity *)0x0) &&
             (uVar8 = (*pCVar1->_vptr_CBaseEntity[7])(pCVar1), -1 < (int)uVar8)) {
                    /* Unresolved local var: int flags@[???] */
            if ((uVar8 & 2) == 0) {
              if (pCVar1->pev->globalname != 0) {
                uVar8 = 0x10000000;
                local_103c = 0;
                goto LAB_0011c057;
              }
            }
            else {
              if (pCVar1->pev->globalname == 0) {
                uVar8 = 0x20000000;
              }
              else {
                uVar8 = 0x30000000;
                local_103c = 0x20000000;
LAB_0011c057:
                iVar5 = CBaseEntity::IsDormant(pCVar1);
                if ((iVar5 != 0) && (uVar8 = local_103c, local_103c == 0)) goto LAB_0011c070;
              }
              auStack_101c[iVar4] = pCVar1;
              auStack_81c[iVar4] = uVar8;
              iVar4 = iVar4 + 1;
              if (0x200 < iVar4) {
                pdata = "Too many entities across a transition!";
                (*g_engfuncs.pfnAlertMessage)(at_error,"Too many entities across a transition!");
              }
            }
          }
LAB_0011c070:
          peVar2 = (peVar2->v).chain;
        } while (peVar2 != (edict_t *)0x0);
        if (iVar4 != 0) {
                    /* Unresolved local var: int index@[???] */
          iVar5 = 0;
          do {
            while (uVar8 = auStack_81c[iVar5], uVar8 == 0) {
LAB_0011bf80:
              iVar5 = iVar5 + 1;
              if (iVar5 == iVar4) goto LAB_0011bfe0;
            }
            pCVar1 = (CBaseEntity *)auStack_101c[iVar5];
                    /* Unresolved local var: edict_t * pentVolume@[???]
                       Unresolved local var: int inVolume@[???] */
            uVar6 = (*pCVar1->_vptr_CBaseEntity[7])(pCVar1);
            if (((uVar6 & 0x80) == 0) && (iVar7 = InTransitionVolume(pCVar1,local_1034), iVar7 == 0)
               ) goto LAB_0011bf80;
            pdata = (char *)CSaveRestoreBuffer::EntityIndex(&local_1020,pCVar1);
            CSaveRestoreBuffer::EntityFlagsSet
                      (&local_1020,(int)pdata,uVar8 | 1 << ((byte)local_1038 & 0x1f));
            iVar5 = iVar5 + 1;
          } while (iVar5 != iVar4);
        }
      }
LAB_0011bfe0:
      local_1038 = local_1038 + 1;
      local_1034 = local_1034 + 0x50;
    } while (iVar3 != local_1038);
  }
  CSaveRestoreBuffer::~CSaveRestoreBuffer(&local_1020,(int)pdata);
  return iVar3;
}


// NextLevel  @ 0011c280  (line 1641)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NextLevel(void)

{
  edict_t *peVar1;
  _2globalvars_t *p1Var2;
  edict_t *peVar3;
  int iVar4;
  string_t sVar5;
  undefined4 *puVar6;
  entvars_t *pev;
  
                    /* Unresolved local var: edict_t * pent@[???]
                       Unresolved local var: CChangeLevel * pChange@[???] */
  peVar3 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"classname","trigger_changelevel");
  if ((peVar3 == (edict_t *)0x0) ||
     (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3), iVar4 == 0)) {
    p1Var2 = gpGlobals;
                    /* Unresolved local var: entvars_t * pev@[???] */
    sVar5 = (*g_engfuncs.pfnAllocString)("start");
    p1Var2->mapname = sVar5;
    peVar3 = (*g_engfuncs.pfnCreateEntity)();
    pev = (entvars_t *)0x0;
    if (peVar3 != (edict_t *)0x0) {
      pev = &peVar3->v;
    }
    if ((pev->pContainingEntity == (edict_t *)0x0) ||
       (puVar6 = pev->pContainingEntity->pvPrivateData, puVar6 == (undefined4 *)0x0)) {
      puVar6 = CBaseEntity::operator_new(0x55c,pev);
      *puVar6 = &PTR__CChangeLevel_00164f44;
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
      *puVar6 = &PTR__CChangeLevel_00164f44;
      puVar6[1] = &peVar3->v;
    }
  }
  __strcpy_chk(st_szNextMap,puVar6 + 0x145,0x20);
  p1Var2 = gpGlobals;
  g_fGameOver = 1;
  if (*(float *)(puVar6[1] + 0x104) < gpGlobals->time) {
    puVar6[4] = CChangeLevel::ExecuteChangeLevel;
    puVar6[5] = 0;
    *(float *)(puVar6[1] + 0x104) = p1Var2->time + 0.1;
  }
  return;
}


// CLadder::~CLadder  @ 0011d470  (line 1671)

/* DWARF original prototype: void ~CLadder(CLadder * this, int __in_chrg) */

void __thiscall CLadder::~CLadder(CLadder *this,int __in_chrg)

{
  return;
}


// func_ladder  @ 0011c3f0  (line 1678)

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
  *puVar1 = &PTR__CLadder_00165054;
  puVar1[1] = pev;
  return;
}


// CLadder::KeyValue  @ 00119430  (line 1682)

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


// CLadder::Precache  @ 001167b0  (line 1691)

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
     super_CBaseEntity.pev)->renderamt = 0.0;
  }
  piVar1 = &((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 & 0xffffff7f;
  return;
}


// CLadder::Spawn  @ 00118c70  (line 1705)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CLadder * this) */

void __thiscall CLadder::Spawn(CLadder *this)

{
  int *piVar1;
  _func_int_varargs *p_Var2;
  entvars_t *peVar3;
  longdouble extraout_ST0;
  
  p_Var2 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var2 == Precache) {
    ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->solid = 0;
    ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->skin = -0x10;
    (*g_engfuncs.pfnCVarGetFloat)("showtriggers");
    if (extraout_ST0 == (longdouble)0) {
      ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->rendermode = 2;
      ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->renderamt = 0.0;
    }
    piVar1 = &((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 & 0xffffff7f;
  }
  else {
    (*p_Var2)(this);
  }
  peVar3 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar3->pContainingEntity,gpGlobals->pStringBase + peVar3->model);
  ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 7;
  return;
}


// CTriggerPush::~CTriggerPush  @ 0011d460  (line 1715)

/* DWARF original prototype: void ~CTriggerPush(CTriggerPush * this, int __in_chrg) */

void __thiscall CTriggerPush::~CTriggerPush(CTriggerPush *this,int __in_chrg)

{
  return;
}


// trigger_push  @ 0011c460  (line 1722)

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
  *puVar1 = &PTR__CTriggerPush_00165164;
  puVar1[1] = pev;
  return;
}


// CTriggerPush::KeyValue  @ 00119550  (line 1726)

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


// CTriggerPush::Spawn  @ 00119fa0  (line 1736)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTriggerPush * this) */

void __thiscall CTriggerPush::Spawn(CTriggerPush *this)

{
  int *piVar1;
  vec_t vVar2;
  _2globalvars_t *p1Var3;
  entvars_t *peVar4;
  longdouble lVar5;
  
  vVar2 = g_vecZero.y;
  peVar4 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar4->angles).x == g_vecZero.x) {
    if (((peVar4->angles).y == g_vecZero.y) && ((peVar4->angles).z == g_vecZero.z)) {
      (peVar4->angles).y = 360.0;
      peVar4 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      if (g_vecZero.x != (peVar4->angles).x) goto LAB_00119fd0;
    }
    if (((peVar4->angles).y == vVar2) && ((peVar4->angles).z == g_vecZero.z)) goto LAB_00119fdb;
  }
LAB_00119fd0:
  SetMovedir(peVar4);
  peVar4 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
LAB_00119fdb:
  peVar4->solid = 1;
  p1Var3 = gpGlobals;
  ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 0;
  peVar4 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar4->pContainingEntity,p1Var3->pStringBase + peVar4->model);
  lVar5 = (longdouble)(*g_engfuncs.pfnCVarGetFloat)("showtriggers");
  if (lVar5 == (longdouble)0) {
    piVar1 = &((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 0x80;
  }
  peVar4 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar4->speed == 0.0) {
    peVar4->speed = 100.0;
    peVar4 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if ((peVar4->spawnflags & 2) != 0) {
    peVar4->solid = 0;
    peVar4 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__pfn = CBaseTrigger::ToggleUse;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__delta = 0;
  UTIL_SetOrigin(peVar4,&peVar4->origin);
  return;
}


// CTriggerPush::Touch  @ 00117190  (line 1754)

/* DWARF original prototype: void Touch(CTriggerPush * this, CBaseEntity * pOther) */

void __thiscall CTriggerPush::Touch(CTriggerPush *this,CBaseEntity *pOther)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  entvars_t *peVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  BOOL BVar9;
  
                    /* Unresolved local var: entvars_t * pevToucher@[???] */
  peVar3 = pOther->pev;
  if ((((0xc < (uint)peVar3->movetype) || ((1 << ((byte)peVar3->movetype & 0x1f) & 0x1181U) == 0))
      && ((peVar3->solid & 0xfffffffbU) != 0)) &&
     ((iVar8 = (*pOther->_vptr_CBaseEntity[10])(pOther), iVar8 != 2 ||
      (BVar9 = ActivationSucceeded((CBaseEntity *)this,(CBasePlayer *)pOther,(CBaseEntity *)0x0),
      BVar9 != 0)))) {
    peVar4 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((peVar4->spawnflags & 1) == 0) {
                    /* Unresolved local var: Vector vecPush@[???] */
      fVar2 = 1.0;
      if (gpGlobals->frametime != 0.0) {
        fVar2 = gpGlobals->frametime;
      }
      fVar1 = peVar4->speed;
      fVar6 = ((peVar4->movedir).z * fVar1) / fVar2;
      fVar7 = ((peVar4->movedir).y * fVar1) / fVar2;
      uVar5 = peVar3->flags;
      fVar2 = (fVar1 * (peVar4->movedir).x) / fVar2;
      if ((uVar5 & 0x400000) != 0) {
        fVar6 = fVar6 + (peVar3->basevelocity).z;
        fVar7 = fVar7 + (peVar3->basevelocity).y;
        fVar2 = fVar2 + (peVar3->basevelocity).x;
      }
      (peVar3->basevelocity).x = fVar2;
      (peVar3->basevelocity).y = fVar7;
      (peVar3->basevelocity).z = fVar6;
      peVar3->flags = uVar5 | 0x400000;
      return;
    }
    fVar2 = peVar4->speed;
    fVar6 = (peVar4->movedir).z * fVar2 + (peVar3->velocity).z;
    fVar1 = (peVar4->movedir).y;
    (peVar3->velocity).x = fVar2 * (peVar4->movedir).x + (peVar3->velocity).x;
    (peVar3->velocity).y = fVar1 * fVar2 + (peVar3->velocity).y;
    (peVar3->velocity).z = fVar6;
    if (0.0 < fVar6) {
      peVar3->flags = peVar3->flags & 0xfffffdff;
    }
    UTIL_Remove((CBaseEntity *)this);
    return;
  }
  return;
}


// CBaseTrigger::TeleportTouch  @ 00117310  (line 1808)

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
  Vector local_18;
  
                    /* Unresolved local var: entvars_t * pevToucher@[???]
                       Unresolved local var: edict_t * pentTarget@[???]
                       Unresolved local var: Vector tmp@[???] */
  pev = pOther->pev;
  if ((pev->flags & 0x28) != 0) {
    iVar6 = UTIL_IsMasterTriggered((this->super_CBaseToggle).m_sMaster);
    if (iVar6 != 0) {
      peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      uVar2 = peVar1->spawnflags;
      if ((((uVar2 & 1) != 0) || ((pev->flags & 0x20) == 0)) &&
         (((uVar2 & 2) == 0 || ((pev->flags & 8) == 0)))) {
        peVar7 = (*g_engfuncs.pfnFindEntityByString)
                           ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + peVar1->target);
        if (peVar7 != (edict_t *)0x0) {
          iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar7);
          if (iVar6 != 0) {
            BVar8 = ActivationSucceeded((CBaseEntity *)this,(CBasePlayer *)pOther,(CBaseEntity *)0x0
                                       );
            if (BVar8 != 0) {
              local_18.x = (peVar7->v).origin.x;
              local_18.y = (peVar7->v).origin.y;
              local_18.z = (peVar7->v).origin.z;
              if ((pOther->pev->flags & 8) != 0) {
                local_18.z = local_18.z - (pOther->pev->mins).z;
              }
              pev->flags = pev->flags & 0xfffffdff;
              local_18.z = local_18.z + 1.0;
              UTIL_SetOrigin(pev,&local_18);
              iVar6 = pev->flags;
              (pev->angles).x = (peVar7->v).angles.x;
              (pev->angles).y = (peVar7->v).angles.y;
              (pev->angles).z = (peVar7->v).angles.z;
              if ((iVar6 & 8) != 0) {
                (pev->v_angle).x = (peVar7->v).angles.x;
                (pev->v_angle).y = (peVar7->v).angles.y;
                (pev->v_angle).z = (peVar7->v).angles.z;
              }
              vVar5 = g_vecZero.z;
              vVar3 = g_vecZero.x;
              pev->fixangle = 1;
              vVar4 = g_vecZero.y;
              (pev->basevelocity).x = vVar3;
              (pev->basevelocity).z = vVar5;
              (pev->basevelocity).y = vVar4;
              (pev->velocity).x = vVar3;
              (pev->velocity).y = vVar4;
              (pev->velocity).z = vVar5;
            }
          }
        }
      }
    }
  }
  return;
}


// CTriggerTeleport::~CTriggerTeleport  @ 0011d450  (line 1868)

/* DWARF original prototype: void ~CTriggerTeleport(CTriggerTeleport * this, int __in_chrg) */

void __thiscall CTriggerTeleport::~CTriggerTeleport(CTriggerTeleport *this,int __in_chrg)

{
  return;
}


// trigger_teleport  @ 0011c4d0  (line 1873)

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
  *puVar1 = &PTR__CTriggerTeleport_00165274;
  puVar1[1] = pev;
  return;
}


// CTriggerTeleport::Spawn  @ 001198a0  (line 1876)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTriggerTeleport * this) */

void __thiscall CTriggerTeleport::Spawn(CTriggerTeleport *this)

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
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBaseTrigger::TeleportTouch;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// info_teleport_destination  @ 0011c540  (line 1883)

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
  *puVar1 = &PTR__CPointEntity_0015b6d8;
  puVar1[1] = pev;
  return;
}


// CTriggerSave::~CTriggerSave  @ 0011d440  (line 1887)

/* DWARF original prototype: void ~CTriggerSave(CTriggerSave * this, int __in_chrg) */

void __thiscall CTriggerSave::~CTriggerSave(CTriggerSave *this,int __in_chrg)

{
  return;
}


// trigger_autosave  @ 0011c5b0  (line 1893)

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
  *puVar1 = &PTR__CTriggerSave_00165384;
  puVar1[1] = pev;
  return;
}


// CTriggerSave::Spawn  @ 0011a2b0  (line 1896)

/* DWARF original prototype: void Spawn(CTriggerSave * this) */

void __thiscall CTriggerSave::Spawn(CTriggerSave *this)

{
  int *piVar1;
  _2globalvars_t *p1Var2;
  entvars_t *peVar3;
  longdouble extraout_ST0;
  
  peVar3 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (gpGlobals->deathmatch == 0.0) {
    if ((((peVar3->angles).x != g_vecZero.x) || ((peVar3->angles).y != g_vecZero.y)) ||
       ((peVar3->angles).z != g_vecZero.z)) {
      SetMovedir(peVar3);
      peVar3 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    p1Var2 = gpGlobals;
    peVar3->solid = 1;
    ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->movetype = 0;
    peVar3 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*g_engfuncs.pfnSetModel)(peVar3->pContainingEntity,p1Var2->pStringBase + peVar3->model);
    (*g_engfuncs.pfnCVarGetFloat)("showtriggers");
    if (extraout_ST0 == (longdouble)0) {
      piVar1 = &((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 | 0x80;
    }
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnTouch.__pfn = SaveTouch;
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnTouch.__delta = 0;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0011a3c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnRemoveEntity)(peVar3->pContainingEntity);
  return;
}


// CTriggerSave::SaveTouch  @ 00118270  (line 1908)

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
                    /* WARNING: Could not recover jumptable at 0x001182da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnServerCommand)("autosave\n");
    return;
  }
  return;
}


// CTriggerEndSection::~CTriggerEndSection  @ 0011d430  (line 1923)

/* DWARF original prototype: void ~CTriggerEndSection(CTriggerEndSection * this, int __in_chrg) */

void __thiscall CTriggerEndSection::~CTriggerEndSection(CTriggerEndSection *this,int __in_chrg)

{
  return;
}


// trigger_endsection  @ 0011c620  (line 1931)

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
  *puVar1 = &PTR__CTriggerEndSection_00165494;
  puVar1[1] = pev;
  return;
}


// CTriggerEndSection::EndSectionUse  @ 00118790  (line 1935)

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


// CTriggerEndSection::Spawn  @ 0011a3d0  (line 1950)

/* DWARF original prototype: void Spawn(CTriggerEndSection * this) */

void __thiscall CTriggerEndSection::Spawn(CTriggerEndSection *this)

{
  int *piVar1;
  _2globalvars_t *p1Var2;
  entvars_t *peVar3;
  longdouble extraout_ST0;
  
  peVar3 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (gpGlobals->deathmatch == 0.0) {
    if ((((peVar3->angles).x != g_vecZero.x) || ((peVar3->angles).y != g_vecZero.y)) ||
       ((peVar3->angles).z != g_vecZero.z)) {
      SetMovedir(peVar3);
      peVar3 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    p1Var2 = gpGlobals;
    peVar3->solid = 1;
    ((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->movetype = 0;
    peVar3 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*g_engfuncs.pfnSetModel)(peVar3->pContainingEntity,p1Var2->pStringBase + peVar3->model);
    (*g_engfuncs.pfnCVarGetFloat)("showtriggers");
    if (extraout_ST0 == (longdouble)0) {
      piVar1 = &((this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 | 0x80;
    }
    peVar3 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__pfn = EndSectionUse;
    (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__delta = 0;
    if ((peVar3->spawnflags & 1) == 0) {
      (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnTouch.__pfn = EndSectionTouch;
      (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnTouch.__delta = 0;
    }
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0011a4fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnRemoveEntity)(peVar3->pContainingEntity);
  return;
}


// CTriggerEndSection::EndSectionTouch  @ 00118720  (line 1966)

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


// CTriggerEndSection::KeyValue  @ 00119670  (line 1981)

/* DWARF original prototype: void KeyValue(CTriggerEndSection * this, KeyValueData * pkvd) */

void __thiscall CTriggerEndSection::KeyValue(CTriggerEndSection *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  string_t sVar2;
  long lVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  double dVar9;
  
  bVar8 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar4 = 8;
  pcVar6 = pkvd->szKeyName;
  pcVar5 = pcVar6;
  pcVar7 = "section";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar5 == *pcVar7;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar8);
  if (bVar8) {
    peVar1 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    sVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    peVar1->message = sVar2;
    pkvd->fHandled = 1;
  }
  else {
    iVar4 = 7;
    bVar8 = false;
    pcVar5 = pcVar6;
    pcVar7 = "damage";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar8 = *pcVar5 == *pcVar7;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar8);
    if (bVar8) {
      peVar1 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      dVar9 = strtod(pkvd->szValue,(char **)0x0);
      peVar1->dmg = (float)dVar9;
      pkvd->fHandled = 1;
    }
    else {
      iVar4 = 6;
      bVar8 = false;
      pcVar5 = pcVar6;
      pcVar7 = "count";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar8 = *pcVar5 == *pcVar7;
        pcVar5 = pcVar5 + 1;
        pcVar7 = pcVar7 + 1;
      } while (bVar8);
      if (bVar8) {
        dVar9 = strtod(pkvd->szValue,(char **)0x0);
        (this->super_CBaseTrigger).super_CBaseToggle.m_cTriggersLeft = (int)dVar9;
        pkvd->fHandled = 1;
      }
      else {
        iVar4 = 0xb;
        bVar8 = false;
        pcVar5 = "damagetype";
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar8 = *pcVar6 == *pcVar5;
          pcVar6 = pcVar6 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar8);
        if (!bVar8) {
          CBaseToggle::KeyValue((CBaseToggle *)this,pkvd);
          return;
        }
        lVar3 = strtol(pkvd->szValue,(char **)0x0,10);
        (this->super_CBaseTrigger).super_CBaseToggle.m_bitsDamageInflict = lVar3;
        pkvd->fHandled = 1;
      }
    }
  }
  return;
}


// CTriggerGravity::~CTriggerGravity  @ 0011d420  (line 1994)

/* DWARF original prototype: void ~CTriggerGravity(CTriggerGravity * this, int __in_chrg) */

void __thiscall CTriggerGravity::~CTriggerGravity(CTriggerGravity *this,int __in_chrg)

{
  return;
}


// trigger_gravity  @ 0011c690  (line 2000)

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
  *puVar1 = &PTR__CTriggerGravity_001655a4;
  puVar1[1] = pev;
  return;
}


// CTriggerGravity::Spawn  @ 00119990  (line 2003)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTriggerGravity * this) */

void __thiscall CTriggerGravity::Spawn(CTriggerGravity *this)

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
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = GravityTouch;
  (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CTriggerGravity::GravityTouch  @ 00116820  (line 2011)

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


// CTriggerChangeTarget::~CTriggerChangeTarget  @ 0011d410  (line 2024)

/* DWARF original prototype: void ~CTriggerChangeTarget(CTriggerChangeTarget * this, int __in_chrg)
    */

void __thiscall
CTriggerChangeTarget::~CTriggerChangeTarget(CTriggerChangeTarget *this,int __in_chrg)

{
  return;
}


// CTriggerChangeTarget::ObjectCaps  @ 0011d3c0  (line 2031)

/* DWARF original prototype: int ObjectCaps(CTriggerChangeTarget * this) */

int __thiscall CTriggerChangeTarget::ObjectCaps(CTriggerChangeTarget *this)

{
  return 0;
}


// trigger_changetarget  @ 0011c700  (line 2040)

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
  *puVar1 = &PTR__CTriggerChangeTarget_001656b4;
  puVar1[1] = pev;
  return;
}


// CTriggerChangeTarget::Restore  @ 001188d0  (line 2047)

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


// CTriggerChangeTarget::Save  @ 00118a50  (line 2047)

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


// CTriggerChangeTarget::KeyValue  @ 00117c80  (line 2050)

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


// CTriggerChangeTarget::Spawn  @ 00116850  (line 2061)

/* DWARF original prototype: void Spawn(CTriggerChangeTarget * this) */

void __thiscall CTriggerChangeTarget::Spawn(CTriggerChangeTarget *this)

{
  return;
}


// CTriggerChangeTarget::Use  @ 00117680  (line 2066)

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


// CTriggerCamera::~CTriggerCamera  @ 0011d400  (line 2087)

/* DWARF original prototype: void ~CTriggerCamera(CTriggerCamera * this, int __in_chrg) */

void __thiscall CTriggerCamera::~CTriggerCamera(CTriggerCamera *this,int __in_chrg)

{
  return;
}


// CTriggerCamera::ObjectCaps  @ 0011d3d0  (line 2098)

/* DWARF original prototype: int ObjectCaps(CTriggerCamera * this) */

int __thiscall CTriggerCamera::ObjectCaps(CTriggerCamera *this)

{
  return 0;
}


// trigger_camera  @ 0011c770  (line 2116)

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
  *puVar1 = &PTR__CTriggerCamera_001657c0;
  puVar1[1] = pev;
  return;
}


// CTriggerCamera::Restore  @ 00118870  (line 2136)

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


// CTriggerCamera::Save  @ 001189f0  (line 2136)

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


// CTriggerCamera::Spawn  @ 00116860  (line 2139)

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


// CTriggerCamera::KeyValue  @ 00116b70  (line 2154)

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


// CTriggerCamera::Use  @ 0011cb10  (line 2182)

/* DWARF original prototype: void Use(CTriggerCamera * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CTriggerCamera::Use(CTriggerCamera *this,CBaseEntity *pActivator,CBaseEntity *pCaller,
                   USE_TYPE useType,float value)

{
  float fVar1;
  entvars_t *peVar2;
  entvars_t *peVar3;
  _2globalvars_t *p1Var4;
  int iVar5;
  edict_t *peVar6;
  CBaseEntity *pCVar7;
  bool bVar8;
  longdouble extraout_ST0;
  Vector local_18;
  
  iVar5 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,this->m_state);
  if (iVar5 != 0) {
    bVar8 = this->m_state == 0;
    this->m_state = (uint)bVar8;
    if (!bVar8) {
      this->m_flReturnTime = gpGlobals->time;
      return;
    }
    if ((pActivator == (CBaseEntity *)0x0) || ((pActivator->pev->flags & 8) == 0)) {
      peVar6 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((peVar6 == (edict_t *)0x0) &&
         (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 == (edict_t *)0x0)) {
        pActivator = (CBaseEntity *)0x0;
      }
      else {
        pActivator = peVar6->pvPrivateData;
      }
    }
    EHANDLE::operator=(&this->m_hPlayer,pActivator);
    peVar2 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    this->m_flReturnTime = gpGlobals->time + this->m_flWait;
    peVar2->speed = this->m_initialSpeed;
    peVar2 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    this->m_targetSpeed = this->m_initialSpeed;
    if ((peVar2->spawnflags & 2) == 0) {
      pCVar7 = (CBaseEntity *)
               (*(this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[0x2a])(this);
      EHANDLE::operator=(&this->m_hTarget,pCVar7);
    }
    else {
      iVar5 = (this->m_hPlayer).m_serialnumber;
      (this->m_hTarget).m_pent = (this->m_hPlayer).m_pent;
      (this->m_hTarget).m_serialnumber = iVar5;
    }
    iVar5 = EHANDLE::operator_int(&this->m_hTarget);
    if (iVar5 != 0) {
      if ((((this->super_CBaseDelay).super_CBaseEntity.pev)->spawnflags & 4) != 0) {
        CBasePlayer::EnableControl((CBasePlayer *)pActivator,0);
      }
      p1Var4 = gpGlobals;
      if (this->m_sPath == 0) {
        this->m_pentPath = (CBaseEntity *)0x0;
        this->m_flStopTime = p1Var4->time;
      }
      else {
        peVar6 = (*g_engfuncs.pfnFindEntityByString)
                           ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_sPath);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        if ((peVar6 == (edict_t *)0x0) &&
           (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 == (edict_t *)0x0)) {
          pCVar7 = (CBaseEntity *)0x0;
        }
        else {
          pCVar7 = peVar6->pvPrivateData;
        }
        p1Var4 = gpGlobals;
        this->m_pentPath = pCVar7;
        this->m_flStopTime = p1Var4->time;
        if (pCVar7 != (CBaseEntity *)0x0) {
          fVar1 = pCVar7->pev->speed;
          if (fVar1 != 0.0) {
            this->m_targetSpeed = fVar1;
          }
          (*pCVar7->_vptr_CBaseEntity[0x19])(pCVar7);
          this->m_flStopTime = (float)(extraout_ST0 + (longdouble)this->m_flStopTime);
        }
      }
      peVar2 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      if ((peVar2->spawnflags & 1) == 0) {
        (peVar2->velocity).x = 0.0;
        (peVar2->velocity).y = 0.0;
        (peVar2->velocity).z = 0.0;
      }
      else {
        peVar3 = (((CBasePlayer *)pActivator)->super_CBaseMonster).super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
        local_18.z = (peVar3->origin).z + (peVar3->view_ofs).z;
        local_18.y = (peVar3->origin).y + (peVar3->view_ofs).y;
        local_18.x = (peVar3->origin).x + (peVar3->view_ofs).x;
        UTIL_SetOrigin(peVar2,&local_18);
        (((this->super_CBaseDelay).super_CBaseEntity.pev)->angles).x =
             -(((((CBasePlayer *)pActivator)->super_CBaseMonster).super_CBaseToggle.
                super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles).x;
        (((this->super_CBaseDelay).super_CBaseEntity.pev)->angles).y =
             (((((CBasePlayer *)pActivator)->super_CBaseMonster).super_CBaseToggle.
               super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles).y;
        (((this->super_CBaseDelay).super_CBaseEntity.pev)->angles).z = 0.0;
        peVar2 = (((CBasePlayer *)pActivator)->super_CBaseMonster).super_CBaseToggle.
                 super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
        peVar3 = (this->super_CBaseDelay).super_CBaseEntity.pev;
        (peVar3->velocity).x = (peVar2->velocity).x;
        (peVar3->velocity).y = (peVar2->velocity).y;
        (peVar3->velocity).z = (peVar2->velocity).z;
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
      p1Var4 = gpGlobals;
      peVar2 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__pfn = FollowTarget;
      (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__delta = 0;
      peVar2->nextthink = p1Var4->time;
      this->m_moveDistance = 0.0;
      Move(this);
    }
  }
  return;
}


// CTriggerCamera::FollowTarget  @ 0011ceb0  (line 2271)

/* DWARF original prototype: void FollowTarget(CTriggerCamera * this) */

void __thiscall CTriggerCamera::FollowTarget(CTriggerCamera *this)

{
  EHANDLE *this_00;
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  edict_t *peVar4;
  _func_void_edict_t_ptr_edict_t_ptr *p_Var5;
  int iVar6;
  CBaseEntity *pCVar7;
  entvars_t *peVar8;
  CBasePlayer *this_01;
  _2globalvars_t *p1Var9;
  float fVar10;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: Vector vecGoal@[???]
                       Unresolved local var: float dx@[???]
                       Unresolved local var: float dy@[???] */
  this_00 = &this->m_hPlayer;
  iVar6 = EHANDLE::operator_int(this_00);
  if (iVar6 != 0) {
    iVar6 = EHANDLE::operator_int(&this->m_hTarget);
    if ((iVar6 == 0) || (this->m_flReturnTime < gpGlobals->time)) {
      pCVar7 = EHANDLE::operator->(this_00);
      iVar6 = (*pCVar7->_vptr_CBaseEntity[0x22])(pCVar7);
      p_Var5 = g_engfuncs.pfnSetView;
      if (iVar6 != 0) {
        pCVar7 = EHANDLE::operator->(this_00);
        peVar4 = pCVar7->pev->pContainingEntity;
        pCVar7 = EHANDLE::operator->(this_00);
        (*p_Var5)(pCVar7->pev->pContainingEntity,peVar4);
        this_01 = (CBasePlayer *)EHANDLE::operator_cast_to_CBaseEntity_(this_00);
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
      peVar3 = pCVar7->pev;
      local_28[0].z = (peVar3->origin).z - (peVar8->origin).z;
      local_28[0].y = (peVar3->origin).y - (peVar8->origin).y;
      local_28[0].x = (peVar3->origin).x - (peVar8->origin).x;
      UTIL_VecToAngles(&local_34,local_28);
      peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
      local_34.x = -local_34.x;
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
      p1Var9 = gpGlobals;
      fVar10 = local_34.x - (peVar8->angles).x;
      fVar1 = local_34.y - fVar1;
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
           fVar1 * 40.0 * p1Var9->frametime;
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
          p1Var9 = gpGlobals;
        }
        if (fVar10 < 10.0) {
          (peVar8->velocity).x = g_vecZero.x;
          (peVar8->velocity).y = g_vecZero.y;
          (peVar8->velocity).z = g_vecZero.z;
          peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
        }
      }
      peVar8->nextthink = p1Var9->time;
      Move(this);
    }
  }
  return;
}


// CTriggerCamera::Move  @ 0011c7e0  (line 2327)

/* DWARF original prototype: void Move(CTriggerCamera * this) */

void __thiscall CTriggerCamera::Move(CTriggerCamera *this)

{
  float fVar1;
  float fVar2;
  string_t sVar3;
  float fVar4;
  float fVar5;
  _2globalvars_t *p1Var6;
  CBaseEntity *pCVar7;
  entvars_t *peVar8;
  entvars_t *peVar9;
  longdouble lVar10;
  longdouble extraout_ST0;
  float fVar11;
  float fVar12;
  
                    /* Unresolved local var: float fraction@[???] */
  p1Var6 = gpGlobals;
  pCVar7 = this->m_pentPath;
  if (pCVar7 != (CBaseEntity *)0x0) {
    peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    fVar11 = this->m_moveDistance - peVar8->speed * gpGlobals->frametime;
    this->m_moveDistance = fVar11;
    if (fVar11 <= 0.0) {
      sVar3 = pCVar7->pev->message;
      if (sVar3 != 0) {
        FireTargets(p1Var6->pStringBase + sVar3,(CBaseEntity *)this,(CBaseEntity *)this,USE_TOGGLE,
                    0.0);
        pCVar7 = this->m_pentPath;
        if ((pCVar7->pev->spawnflags & 4) != 0) {
          pCVar7->pev->message = 0;
          pCVar7 = this->m_pentPath;
        }
      }
      pCVar7 = (CBaseEntity *)(*pCVar7->_vptr_CBaseEntity[0x2a])(pCVar7);
      this->m_pentPath = pCVar7;
      if (pCVar7 == (CBaseEntity *)0x0) {
        peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
        (peVar8->velocity).x = g_vecZero.x;
        (peVar8->velocity).y = g_vecZero.y;
        (peVar8->velocity).z = g_vecZero.z;
        lVar10 = (longdouble)this->m_flStopTime;
        peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
        p1Var6 = gpGlobals;
      }
      else {
                    /* Unresolved local var: Vector delta@[???] */
        peVar8 = pCVar7->pev;
        if (peVar8->speed != 0.0) {
          this->m_targetSpeed = peVar8->speed;
          peVar8 = pCVar7->pev;
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
        p1Var6 = gpGlobals;
        if (fVar11 == 0.0) {
          fVar1 = 1.0;
          fVar2 = 0.0;
          fVar11 = fVar2;
        }
        else {
          fVar11 = 1.0 / fVar11;
          fVar1 = fVar1 * fVar11;
          fVar2 = fVar11 * fVar2;
          fVar11 = fVar5 * fVar11;
        }
        (peVar9->movedir).x = fVar2;
        (peVar9->movedir).y = fVar11;
        (peVar9->movedir).z = fVar1;
        fVar11 = p1Var6->time;
        (*this->m_pentPath->_vptr_CBaseEntity[0x19])(this->m_pentPath);
        p1Var6 = gpGlobals;
        peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
        lVar10 = extraout_ST0 + (longdouble)fVar11;
        this->m_flStopTime = (float)lVar10;
      }
    }
    else {
      lVar10 = (longdouble)this->m_flStopTime;
    }
    if ((longdouble)p1Var6->time < lVar10) {
      fVar11 = UTIL_Approach(0.0,peVar8->speed,this->m_deceleration * p1Var6->frametime);
      peVar8->speed = fVar11;
    }
    else {
      fVar11 = UTIL_Approach(this->m_targetSpeed,peVar8->speed,
                             this->m_acceleration * p1Var6->frametime);
      peVar8->speed = fVar11;
    }
    fVar4 = gpGlobals->frametime + gpGlobals->frametime;
    peVar8 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    fVar12 = 1.0 - fVar4;
    fVar11 = peVar8->speed;
    fVar1 = (peVar8->movedir).z;
    fVar2 = (peVar8->movedir).y;
    (peVar8->velocity).x = fVar12 * (peVar8->velocity).x + fVar11 * (peVar8->movedir).x * fVar4;
    (peVar8->velocity).y = (peVar8->velocity).y * fVar12 + fVar2 * fVar11 * fVar4;
    (peVar8->velocity).z = (peVar8->velocity).z * fVar12 + fVar1 * fVar11 * fVar4;
  }
  return;
}


// teledeath  @ 0011d1b0  (line 2377)

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
  *puVar1 = &PTR__CTelefragDeath_0014f258;
  puVar1[1] = pev;
  return;
}


// CTelefragDeath::Spawn  @ 0011d220  (line 2380)

/* DWARF original prototype: void Spawn(CTelefragDeath * this, CBaseEntity * pIgnore) */

void __thiscall CTelefragDeath::Spawn(CTelefragDeath *this,CBaseEntity *pIgnore)

{
  entvars_t *peVar1;
  void *pvVar2;
  int iVar3;
  _2globalvars_t *p1Var4;
  edict_t *peVar5;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???] */
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
    p1Var4 = gpGlobals;
    (this->super_CBaseEntity).m_pfnTouch.__pfn = DeathTouch;
    peVar1 = (this->super_CBaseEntity).pev;
    (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
    peVar1->nextthink = p1Var4->time + 0.2;
    (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    this->m_pIgnore = pIgnore;
    p1Var4->force_retouch = 2.0;
  }
  return;
}


// CTelefragDeath::DeathTouch  @ 001176f0  (line 2407)

/* DWARF original prototype: void DeathTouch(CTelefragDeath * this, CBaseEntity * pOther) */

void __thiscall CTelefragDeath::DeathTouch(CTelefragDeath *this,CBaseEntity *pOther)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  edict_t *peVar7;
  entvars_t *peVar8;
  CBaseEntity *pCVar9;
  char *pcVar10;
  char *pcVar11;
  void *pvVar12;
  bool bVar13;
  byte bVar14;
  longdouble extraout_ST0;
  char *local_2c;
  
                    /* Unresolved local var: CBaseEntity * pOwner@[???]
                       Unresolved local var: CBaseEntity * pBuildingOwner@[???]
                       Unresolved local var: char * message@[???] */
  bVar14 = 0;
  peVar7 = ((this->super_CBaseEntity).pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar7 == (edict_t *)0x0) &&
     (peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar7 == (edict_t *)0x0)) {
    pCVar9 = (CBaseEntity *)0x0;
  }
  else {
    pCVar9 = peVar7->pvPrivateData;
  }
  if ((pOther == pCVar9) || (pOther == this->m_pIgnore)) {
    return;
  }
  iVar2 = (*pOther->_vptr_CBaseEntity[10])(pOther);
  if ((iVar2 == 2) && (gpGlobals->time < pOther->invincible_finished)) {
    peVar8 = (this->super_CBaseEntity).pev;
    g_pszDeathType = "teledeath2";
    (*pCVar9->_vptr_CBaseEntity[0xd])(pCVar9,peVar8,peVar8,0x459c4000,0x2000);
    return;
  }
  peVar8 = pOther->pev;
  if (peVar8->takedamage != 0.0) {
    iVar2 = (*pOther->_vptr_CBaseEntity[10])(pOther);
    if (iVar2 == 2) {
      fVar1 = gpGlobals->time;
      (*g_engfuncs.pfnRandomFloat)(0.0,5.0);
      pOther[1].replacement_model_body = (int)(float)(extraout_ST0 + (longdouble)(fVar1 + 5.0));
    }
    peVar8 = (this->super_CBaseEntity).pev;
    g_pszDeathType = "teledeath";
    (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar8,peVar8,0x459c4000,0x2000);
    peVar8 = pOther->pev;
  }
  iVar2 = 8;
  local_2c = gpGlobals->pStringBase;
  bVar13 = local_2c + peVar8->classname == (char *)0x0;
  pcVar10 = local_2c + peVar8->classname;
  pcVar3 = "detpack";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar13 = *pcVar10 == *pcVar3;
    pcVar10 = pcVar10 + (uint)bVar14 * -2 + 1;
    pcVar3 = pcVar3 + (uint)bVar14 * -2 + 1;
  } while (bVar13);
  if (!bVar13) {
    return;
  }
  peVar7 = peVar8->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar7 == (edict_t *)0x0) {
    peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar7 == (edict_t *)0x0) {
      pvVar12 = (void *)0x0;
      peVar8 = pOther->pev;
      local_2c = gpGlobals->pStringBase;
      goto LAB_00117790;
    }
    local_2c = gpGlobals->pStringBase;
    peVar8 = pOther->pev;
  }
  pvVar12 = peVar7->pvPrivateData;
LAB_00117790:
  UTIL_ClientPrintAll(1,"#Detpack_telefragged",local_2c + peVar8->netname,
                      local_2c + pCVar9->pev->netname,(char *)0x0,(char *)0x0);
  if (*(int *)((int)pvVar12 + 0x138) == 0) {
    local_2c = "SPECTATOR";
  }
  else {
    local_2c = GetTeamName(*(int *)((int)pvVar12 + 0x138));
  }
  pcVar3 = (*g_engfuncs.pfnGetPlayerAuthId)(*(edict_t **)(*(int *)((int)pvVar12 + 4) + 0x208));
  iVar4 = (*g_engfuncs.pfnGetPlayerUserId)(*(edict_t **)(*(int *)((int)pvVar12 + 4) + 0x208));
  pcVar10 = gpGlobals->pStringBase;
  iVar2 = *(int *)(*(int *)((int)pvVar12 + 4) + 0x1d0);
  pcVar11 = "SPECTATOR";
  if (pCVar9->team_no != 0) {
    pcVar11 = GetTeamName(pCVar9->team_no);
  }
  pcVar5 = (*g_engfuncs.pfnGetPlayerAuthId)(pCVar9->pev->pContainingEntity);
  iVar6 = (*g_engfuncs.pfnGetPlayerUserId)(pCVar9->pev->pContainingEntity);
  UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"%s\" against \"%s<%i><%s><%s>\"\n",
                 gpGlobals->pStringBase + pCVar9->pev->netname,iVar6,pcVar5,pcVar11,
                 "Detpack_telefragged",pcVar10 + iVar2,iVar4,pcVar3,local_2c);
  dremove(pOther);
  return;
}


