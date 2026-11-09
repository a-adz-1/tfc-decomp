// Ghidra decompilation of functions from tfc/healthkit.cpp
// 14 functions, ordered by original source line

// item_healthkit  @ 000e1150  (line 38)

void item_healthkit(entvars_t *pev)

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
  *puVar1 = &PTR__CHealthKit_00183068;
  puVar1[1] = pev;
  return;
}


// CHealthKit::Spawn  @ 000e0aa0  (line 51)

/* DWARF original prototype: void Spawn(CHealthKit * this) */

void __thiscall CHealthKit::Spawn(CHealthKit *this)

{
  (*(this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[3])(this);
  (*g_engfuncs.pfnSetModel)
            (((this->super_CItem).super_CBaseEntity.pev)->pContainingEntity,"models/w_medkit.mdl");
  CItem::Spawn(&this->super_CItem);
  return;
}


// CHealthKit::Precache  @ 000e0990  (line 59)

/* DWARF original prototype: void Precache(CHealthKit * this) */

void __thiscall CHealthKit::Precache(CHealthKit *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/w_medkit.mdl");
                    /* WARNING: Could not recover jumptable at 0x000e09b1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/smallmedkit1.wav");
  return;
}


// CHealthKit::MyTouch  @ 000e0cf0  (line 65)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL MyTouch(CHealthKit * this, CBasePlayer * pPlayer) */

BOOL __thiscall CHealthKit::MyTouch(CHealthKit *this,CBasePlayer *pPlayer)

{
  int iVar1;
  
  iVar1 = (*(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0xe])(pPlayer,gSkillData.healthkitCapacity,0);
  if (iVar1 == 0) {
    return 0;
  }
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgItemPickup,(float *)0x0,
             ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteString)
            (gpGlobals->pStringBase + ((this->super_CItem).super_CBaseEntity.pev)->classname);
  (*g_engfuncs.pfnMessageEnd)();
  EMIT_SOUND_DYN(((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                 "items/smallmedkit1.wav",1.0,0.8,0,100);
  iVar1 = (*g_pGameRules->_vptr_CGameRules[0x25])(g_pGameRules,this);
  if (iVar1 == 0) {
    UTIL_Remove((CBaseEntity *)this);
    return 1;
  }
  (*(this->super_CItem).super_CBaseEntity._vptr_CBaseEntity[0x2f])(this);
  return 1;
}


// CWallHealth::ObjectCaps  @ 000e1230  (line 103)

/* DWARF original prototype: int ObjectCaps(CWallHealth * this) */

int __thiscall CWallHealth::ObjectCaps(CWallHealth *this)

{
  return 0x10;
}


// CWallHealth::Restore  @ 000e0ae0  (line 125)

/* DWARF original prototype: int Restore(CWallHealth * this, CRestore * restore) */

int __thiscall CWallHealth::Restore(CWallHealth *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore((CBaseEntity *)this,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CWallHealth",this,m_SaveData,5);
  }
  return iVar2;
}


// CWallHealth::Save  @ 000e0b40  (line 125)

/* DWARF original prototype: int Save(CWallHealth * this, CSave * save) */

int __thiscall CWallHealth::Save(CWallHealth *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save((CBaseEntity *)this,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CWallHealth",this,m_SaveData,5);
  }
  return iVar2;
}


// func_healthcharger  @ 000e11c0  (line 127)

void func_healthcharger(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x528,pev);
  *puVar1 = &PTR__CWallHealth_00183188;
  puVar1[1] = pev;
  return;
}


// CWallHealth::KeyValue  @ 000e0e00  (line 131)

/* DWARF original prototype: void KeyValue(CWallHealth * this, KeyValueData * pkvd) */

void __thiscall CWallHealth::KeyValue(CWallHealth *this,KeyValueData *pkvd)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar2 = 6;
  pcVar4 = pkvd->szKeyName;
  pcVar3 = pcVar4;
  pcVar5 = "style";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar3 == *pcVar5;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (!bVar6) {
    iVar2 = 7;
    pcVar3 = pcVar4;
    pcVar5 = "height";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar3 == *pcVar5;
      pcVar3 = pcVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (!bVar6) {
      iVar2 = 7;
      pcVar3 = pcVar4;
      pcVar5 = "value1";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (!bVar6) {
        iVar2 = 7;
        pcVar3 = pcVar4;
        pcVar5 = "value2";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar6 = *pcVar3 == *pcVar5;
          pcVar3 = pcVar3 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (!bVar6) {
          iVar2 = 7;
          pcVar3 = pcVar4;
          pcVar5 = "value3";
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar6 = *pcVar3 == *pcVar5;
            pcVar3 = pcVar3 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar6);
          if (!bVar6) {
            iVar2 = 8;
            pcVar3 = "dmdelay";
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar6 = *pcVar4 == *pcVar3;
              pcVar4 = pcVar4 + 1;
              pcVar3 = pcVar3 + 1;
            } while (bVar6);
            if (!bVar6) {
              CBaseToggle::KeyValue(&this->super_CBaseToggle,pkvd);
              return;
            }
            lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
            this->m_iReactivate = lVar1;
          }
        }
      }
    }
  }
  pkvd->fHandled = 1;
  return;
}


// CWallHealth::Spawn  @ 000e09f0  (line 150)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CWallHealth * this) */

void __thiscall CWallHealth::Spawn(CWallHealth *this)

{
  entvars_t *peVar1;
  
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[3])(this);
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 4
  ;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->movetype
       = 7;
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar1,&peVar1->origin);
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetSize(peVar1,&peVar1->mins,&peVar1->maxs);
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar1->pContainingEntity,gpGlobals->pStringBase + peVar1->model);
  this->m_iJuice = (int)gSkillData.healthchargerCapacity;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->frame =
       0.0;
  return;
}


// CWallHealth::Precache  @ 000e09c0  (line 165)

/* DWARF original prototype: void Precache(CWallHealth * this) */

void __thiscall CWallHealth::Precache(CWallHealth *this)

{
  (*g_engfuncs.pfnPrecacheSound)("items/medshot4.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/medshotno1.wav");
                    /* WARNING: Could not recover jumptable at 0x000e09ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/medcharge4.wav");
  return;
}


// CWallHealth::Use  @ 000e0ef0  (line 173)

/* DWARF original prototype: void Use(CWallHealth * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CWallHealth::Use(CWallHealth *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
                float value)

{
  float fVar1;
  entvars_t *peVar2;
  globalvars_t *pgVar3;
  int iVar4;
  
  if (pActivator == (CBaseEntity *)0x0) {
    return;
  }
  peVar2 = pActivator->pev;
  if ((peVar2->flags & 8) == 0) {
    return;
  }
  if (this->m_iJuice < 1) {
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->frame =
         1.0;
    Off(this);
    if (this->m_iJuice < 1) goto LAB_000e0f2f;
    peVar2 = pActivator->pev;
  }
  if (peVar2->weapons < 0) {
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    peVar2->nextthink = peVar2->ltime + 0.25;
    pgVar3 = gpGlobals;
    fVar1 = this->m_flNextCharge;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = Off;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
    if (pgVar3->time <= fVar1) {
      return;
    }
    iVar4 = this->m_iOn;
    if (iVar4 == 0) {
      this->m_iOn = 1;
      EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity,3,"items/medshot4.wav",1.0,0.8,0,100
                    );
      pgVar3 = gpGlobals;
      this->m_flSoundTime = gpGlobals->time + 0.56;
      iVar4 = this->m_iOn;
    }
    if ((iVar4 == 1) && (this->m_flSoundTime <= pgVar3->time)) {
      this->m_iOn = 2;
      EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity,6,"items/medcharge4.wav",1.0,0.8,0,
                     100);
    }
    iVar4 = (*pActivator->_vptr_CBaseEntity[0xe])(pActivator,0x3f800000,0);
    if (iVar4 != 0) {
      this->m_iJuice = this->m_iJuice + -1;
    }
    this->m_flNextCharge = gpGlobals->time + 0.1;
    return;
  }
LAB_000e0f2f:
  if (gpGlobals->time < this->m_flSoundTime) {
    return;
  }
  this->m_flSoundTime = gpGlobals->time + 0.62;
  EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev)->pContainingEntity,3,"items/medshotno1.wav",1.0,0.8,0,100);
  return;
}


// CWallHealth::Recharge  @ 000e0c70  (line 232)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Recharge(CWallHealth * this) */

void __thiscall CWallHealth::Recharge(CWallHealth *this)

{
  EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev)->pContainingEntity,3,"items/medshot4.wav",1.0,0.8,0,100);
  this->m_iJuice = (int)gSkillData.healthchargerCapacity;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->frame =
       0.0;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = CBaseEntity::SUB_DoNothing;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  return;
}


// CWallHealth::Off  @ 000e0ba0  (line 240)

/* DWARF original prototype: void Off(CWallHealth * this) */

void __thiscall CWallHealth::Off(CWallHealth *this)

{
  entvars_t *peVar1;
  int iVar2;
  longdouble extraout_ST0;
  
  if (1 < this->m_iOn) {
    EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,6,"items/medcharge4.wav",0.0,0.0,0x20,
                   100);
  }
  this->m_iOn = 0;
  if (this->m_iJuice == 0) {
    (*g_pGameRules->_vptr_CGameRules[0x2d])(g_pGameRules);
    iVar2 = (int)extraout_ST0;
    this->m_iReactivate = iVar2;
    if (0 < iVar2) {
      peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      peVar1->nextthink = (float)iVar2 + peVar1->ltime;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __pfn = Recharge;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __delta = 0;
      return;
    }
  }
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = CBaseEntity::SUB_DoNothing;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  return;
}


