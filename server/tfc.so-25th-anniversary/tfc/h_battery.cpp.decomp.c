// Ghidra decompilation of functions from tfc/h_battery.cpp
// 11 functions, ordered by original source line

// CRecharge::~CRecharge  @ 000a1070  (line 25)

/* DWARF original prototype: void ~CRecharge(CRecharge * this, int __in_chrg) */

void __thiscall CRecharge::~CRecharge(CRecharge *this,int __in_chrg)

{
  return;
}


// CRecharge::ObjectCaps  @ 000a1060  (line 34)

/* DWARF original prototype: int ObjectCaps(CRecharge * this) */

int __thiscall CRecharge::ObjectCaps(CRecharge *this)

{
  return 0x10;
}


// CRecharge::Restore  @ 000a0a00  (line 56)

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


// CRecharge::Save  @ 000a0a60  (line 56)

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


// func_recharge  @ 000a0ff0  (line 58)

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
  *puVar1 = &PTR__CRecharge_0014fc34;
  puVar1[1] = pev;
  return;
}


// CRecharge::KeyValue  @ 000a0840  (line 62)

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
            if (bVar6) {
              lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
              this->m_iReactivate = lVar1;
              pkvd->fHandled = 1;
              return;
            }
            CBaseToggle::KeyValue(&this->super_CBaseToggle,pkvd);
            return;
          }
        }
      }
    }
  }
  pkvd->fHandled = 1;
  return;
}


// CRecharge::Spawn  @ 000a0ac0  (line 81)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CRecharge * this) */

void __thiscall CRecharge::Spawn(CRecharge *this)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  
  p_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           _vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheSound)("items/suitcharge1.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/suitchargeno1.wav");
    (*g_engfuncs.pfnPrecacheSound)("items/suitchargeok1.wav");
  }
  else {
    (*p_Var1)(this);
  }
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 4
  ;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->movetype
       = 7;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar2,&peVar2->origin);
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetSize(peVar2,&peVar2->mins,&peVar2->maxs);
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + peVar2->model);
  this->m_iJuice = (int)gSkillData.suitchargerCapacity;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->frame =
       0.0;
  return;
}


// CRecharge::Precache  @ 000a07e0  (line 95)

/* DWARF original prototype: void Precache(CRecharge * this) */

void __thiscall CRecharge::Precache(CRecharge *this)

{
  (*g_engfuncs.pfnPrecacheSound)("items/suitcharge1.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/suitchargeno1.wav");
                    /* WARNING: Could not recover jumptable at 0x000a0809. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("items/suitchargeok1.wav");
  return;
}


// CRecharge::Use  @ 000a0bb0  (line 103)

/* DWARF original prototype: void Use(CRecharge * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CRecharge::Use(CRecharge *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
              float value)

{
  EHANDLE *this_00;
  float fVar1;
  float fVar2;
  _2globalvars_t *p1Var3;
  entvars_t *peVar4;
  CBaseEntity *pCVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  longdouble extraout_ST0;
  
  iVar6 = 7;
  peVar4 = pActivator->pev;
  bVar9 = CARRY4(peVar4->classname,(uint)gpGlobals->pStringBase);
  pbVar7 = (byte *)(gpGlobals->pStringBase + peVar4->classname);
  bVar10 = pbVar7 == (byte *)0x0;
  pbVar8 = (byte *)"player";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pbVar7 < *pbVar8;
    bVar10 = *pbVar7 == *pbVar8;
    pbVar7 = pbVar7 + 1;
    pbVar8 = pbVar8 + 1;
  } while (bVar10);
  if ((!bVar9 && !bVar10) != bVar9) {
    return;
  }
  if (this->m_iJuice < 1) {
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->frame =
         1.0;
    if (1 < this->m_iOn) {
      EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity,6,"items/suitcharge1.wav",0.0,0.0,
                     0x20,100);
    }
    this->m_iOn = 0;
    iVar6 = this->m_iJuice;
    if (iVar6 == 0) {
      (*g_pGameRules->_vptr_CGameRules[0x2e])(g_pGameRules);
      iVar6 = (int)extraout_ST0;
      this->m_iReactivate = iVar6;
      if (iVar6 < 1) {
        iVar6 = this->m_iJuice;
        goto LAB_000a0dcd;
      }
      peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      peVar4->nextthink = (float)iVar6 + peVar4->ltime;
      iVar6 = this->m_iJuice;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __pfn = Recharge;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __delta = 0;
    }
    else {
LAB_000a0dcd:
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __pfn = CBaseEntity::SUB_DoNothing;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __delta = 0;
    }
    if (iVar6 < 1) goto LAB_000a0c14;
    peVar4 = pActivator->pev;
  }
  p1Var3 = gpGlobals;
  if (peVar4->weapons < 0) {
    peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    peVar4->nextthink = peVar4->ltime + 0.25;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = Off;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
    if (p1Var3->time <= this->m_flNextCharge) {
      return;
    }
    if (pActivator == (CBaseEntity *)0x0) {
      return;
    }
    this_00 = &(this->super_CBaseToggle).m_hActivator;
    EHANDLE::operator=(this_00,pActivator);
    pCVar5 = EHANDLE::operator->(this_00);
    if ((pCVar5->pev->flags & 8) == 0) {
      return;
    }
    iVar6 = this->m_iOn;
    if (iVar6 == 0) {
      this->m_iOn = 1;
      EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity,3,"items/suitchargeok1.wav",0.85,0.8
                     ,0,100);
      this->m_flSoundTime = gpGlobals->time + 0.56;
      iVar6 = this->m_iOn;
    }
    if ((iVar6 == 1) && (this->m_flSoundTime <= gpGlobals->time)) {
      this->m_iOn = 2;
      EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                      super_CBaseEntity.pev)->pContainingEntity,6,"items/suitcharge1.wav",0.85,0.8,0
                     ,100);
    }
    pCVar5 = EHANDLE::operator->(this_00);
    fVar1 = pCVar5->pev->armorvalue;
    pCVar5 = EHANDLE::operator->(this_00);
    if (fVar1 < pCVar5->maxarmor) {
      this->m_iJuice = this->m_iJuice + -1;
      pCVar5 = EHANDLE::operator->(this_00);
      pCVar5->pev->armorvalue = pCVar5->pev->armorvalue + 1.0;
      pCVar5 = EHANDLE::operator->(this_00);
      fVar1 = pCVar5->pev->armorvalue;
      pCVar5 = EHANDLE::operator->(this_00);
      if (pCVar5->maxarmor < fVar1) {
        pCVar5 = EHANDLE::operator->(this_00);
        peVar4 = pCVar5->pev;
        pCVar5 = EHANDLE::operator->(this_00);
        peVar4->armorvalue = pCVar5->maxarmor;
      }
      pCVar5 = EHANDLE::operator->(this_00);
      peVar4 = pCVar5->pev;
      pCVar5 = EHANDLE::operator->(this_00);
      fVar1 = pCVar5->pev->armortype;
      fVar2 = 0.8;
      if (0.8 <= fVar1) {
        fVar2 = fVar1;
      }
      peVar4->armortype = fVar2;
    }
    this->m_flNextCharge = gpGlobals->time + 0.1;
    return;
  }
LAB_000a0c14:
  if (this->m_flSoundTime <= gpGlobals->time) {
    this->m_flSoundTime = gpGlobals->time + 0.62;
    EMIT_SOUND_DYN(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->pContainingEntity,3,"items/suitchargeno1.wav",0.85,0.8,0
                   ,100);
  }
  return;
}


// CRecharge::Recharge  @ 000a0810  (line 176)

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


// CRecharge::Off  @ 000a0930  (line 183)

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


