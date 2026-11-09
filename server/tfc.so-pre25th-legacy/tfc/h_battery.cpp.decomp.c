// Ghidra decompilation of functions from tfc/h_battery.cpp
// 10 functions, ordered by original source line

// CRecharge::ObjectCaps  @ 000de280  (line 34)

/* DWARF original prototype: int ObjectCaps(CRecharge * this) */

int __thiscall CRecharge::ObjectCaps(CRecharge *this)

{
  return 0x10;
}


// CRecharge::Restore  @ 000ddc10  (line 56)

/* DWARF original prototype: int Restore(CRecharge * this, CRestore * restore) */

int __thiscall CRecharge::Restore(CRecharge *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore((CBaseEntity *)this,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CRecharge",this,m_SaveData,5);
  }
  return iVar2;
}


// CRecharge::Save  @ 000ddc70  (line 56)

/* DWARF original prototype: int Save(CRecharge * this, CSave * save) */

int __thiscall CRecharge::Save(CRecharge *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save((CBaseEntity *)this,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CRecharge",this,m_SaveData,5);
  }
  return iVar2;
}


// func_recharge  @ 000de210  (line 58)

void func_recharge(entvars_t *pev)

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
  *puVar1 = &PTR__CRecharge_001809e8;
  puVar1[1] = pev;
  return;
}


// CRecharge::KeyValue  @ 000de120  (line 62)

/* DWARF original prototype: void KeyValue(CRecharge * this, KeyValueData * pkvd) */

void __thiscall CRecharge::KeyValue(CRecharge *this,KeyValueData *pkvd)

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


// CRecharge::Spawn  @ 000ddb60  (line 81)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CRecharge * this) */

void __thiscall CRecharge::Spawn(CRecharge *this)

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
  this->m_iJuice = (int)gSkillData.suitchargerCapacity;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->frame =
       0.0;
  return;
}


// CRecharge::Precache  @ 000ddb00  (line 95)

/* DWARF original prototype: void Precache(CRecharge * this) */

void __thiscall CRecharge::Precache(CRecharge *this)

{
  (*g_engfuncs.pfnPrecacheSound)("items/suitcharge1.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/suitchargeno1.wav");
                    /* WARNING: Could not recover jumptable at 0x000ddb2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/suitchargeok1.wav");
  return;
}


// CRecharge::Use  @ 000ddda0  (line 103)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Use(CRecharge * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CRecharge::Use(CRecharge *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
              float value)

{
  EHANDLE *this_00;
  globalvars_t *pgVar1;
  CBaseEntity *pCVar2;
  float fVar3;
  int iVar4;
  entvars_t *peVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  
  iVar4 = 7;
  peVar5 = pActivator->pev;
  bVar8 = gpGlobals->pStringBase + peVar5->classname == (char *)0x0;
  pcVar6 = gpGlobals->pStringBase + peVar5->classname;
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
  if (this->m_iJuice < 1) {
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->frame =
         1.0;
    Off(this);
    if (this->m_iJuice < 1) goto LAB_000dddf8;
    peVar5 = pActivator->pev;
  }
  pgVar1 = gpGlobals;
  if (peVar5->weapons < 0) {
    peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    peVar5->nextthink = peVar5->ltime + 0.25;
    fVar3 = this->m_flNextCharge;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = Off;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
    if (pgVar1->time <= fVar3) {
      return;
    }
    this_00 = &(this->super_CBaseToggle).m_hActivator;
    EHANDLE::operator=(this_00,pActivator);
    pCVar2 = EHANDLE::operator->(this_00);
    if ((pCVar2->pev->flags & 8) == 0) {
      return;
    }
    iVar4 = this->m_iOn;
    if (iVar4 == 0) {
      this->m_iOn = 1;
      EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity,3,"items/suitchargeok1.wav",0.85,0.8
                     ,0,100);
      this->m_flSoundTime = gpGlobals->time + 0.56;
      iVar4 = this->m_iOn;
    }
    if ((iVar4 == 1) && (this->m_flSoundTime <= gpGlobals->time)) {
      this->m_iOn = 2;
      EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity,6,"items/suitcharge1.wav",0.85,0.8,0
                     ,100);
    }
    pCVar2 = EHANDLE::operator->(this_00);
    fVar3 = pCVar2->pev->armorvalue;
    pCVar2 = EHANDLE::operator->(this_00);
    if (fVar3 < pCVar2->maxarmor) {
      this->m_iJuice = this->m_iJuice + -1;
      pCVar2 = EHANDLE::operator->(this_00);
      pCVar2->pev->armorvalue = pCVar2->pev->armorvalue + 1.0;
      pCVar2 = EHANDLE::operator->(this_00);
      fVar3 = pCVar2->pev->armorvalue;
      pCVar2 = EHANDLE::operator->(this_00);
      if (pCVar2->maxarmor < fVar3) {
        pCVar2 = EHANDLE::operator->(this_00);
        peVar5 = pCVar2->pev;
        pCVar2 = EHANDLE::operator->(this_00);
        peVar5->armorvalue = pCVar2->maxarmor;
      }
      pCVar2 = EHANDLE::operator->(this_00);
      peVar5 = pCVar2->pev;
      pCVar2 = EHANDLE::operator->(this_00);
      fVar3 = 0.8;
      if (0.8 < pCVar2->pev->armortype) {
        pCVar2 = EHANDLE::operator->(this_00);
        fVar3 = pCVar2->pev->armortype;
      }
      peVar5->armortype = fVar3;
    }
    this->m_flNextCharge = gpGlobals->time + 0.1;
    return;
  }
LAB_000dddf8:
  if (this->m_flSoundTime <= gpGlobals->time) {
    this->m_flSoundTime = gpGlobals->time + 0.62;
    EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,3,"items/suitchargeno1.wav",0.85,0.8,0
                   ,100);
  }
  return;
}


// CRecharge::Recharge  @ 000ddb30  (line 176)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Recharge(CRecharge * this) */

void __thiscall CRecharge::Recharge(CRecharge *this)

{
  this->m_iJuice = (int)gSkillData.suitchargerCapacity;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->frame =
       0.0;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = CBaseEntity::SUB_DoNothing;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  return;
}


// CRecharge::Off  @ 000ddcd0  (line 183)

/* DWARF original prototype: void Off(CRecharge * this) */

void __thiscall CRecharge::Off(CRecharge *this)

{
  entvars_t *peVar1;
  int iVar2;
  longdouble extraout_ST0;
  
  if (1 < this->m_iOn) {
    EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,6,"items/suitcharge1.wav",0.0,0.0,0x20
                   ,100);
  }
  this->m_iOn = 0;
  if (this->m_iJuice == 0) {
    (*g_pGameRules->_vptr_CGameRules[0x2e])(g_pGameRules);
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


