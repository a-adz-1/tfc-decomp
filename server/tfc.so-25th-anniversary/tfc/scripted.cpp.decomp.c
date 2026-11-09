// Ghidra decompilation of functions from tfc/scripted.cpp
// 49 functions, ordered by original source line

// CCineMonster::KeyValue  @ 000e0c40  (line 54)

/* DWARF original prototype: void KeyValue(CCineMonster * this, KeyValueData * pkvd) */

void __thiscall CCineMonster::KeyValue(CCineMonster *this,KeyValueData *pkvd)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  double dVar7;
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar2 = 10;
  pcVar4 = pkvd->szKeyName;
  pcVar3 = pcVar4;
  pcVar5 = "m_iszIdle";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar3 == *pcVar5;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    iVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    this->m_iszIdle = iVar2;
    pkvd->fHandled = 1;
  }
  else {
    iVar2 = 10;
    bVar6 = false;
    pcVar3 = pcVar4;
    pcVar5 = "m_iszPlay";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar3 == *pcVar5;
      pcVar3 = pcVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      iVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
      this->m_iszPlay = iVar2;
      pkvd->fHandled = 1;
    }
    else {
      iVar2 = 0xc;
      bVar6 = false;
      pcVar3 = pcVar4;
      pcVar5 = "m_iszEntity";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        iVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
        this->m_iszEntity = iVar2;
        pkvd->fHandled = 1;
      }
      else {
        iVar2 = 10;
        bVar6 = false;
        pcVar3 = pcVar4;
        pcVar5 = "m_fMoveTo";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar6 = *pcVar3 == *pcVar5;
          pcVar3 = pcVar3 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (bVar6) {
          lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
          this->m_fMoveTo = lVar1;
          pkvd->fHandled = 1;
        }
        else {
          iVar2 = 0xb;
          bVar6 = false;
          pcVar3 = pcVar4;
          pcVar5 = "m_flRepeat";
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar6 = *pcVar3 == *pcVar5;
            pcVar3 = pcVar3 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar6);
          if (bVar6) {
            dVar7 = strtod(pkvd->szValue,(char **)0x0);
            this->m_flRepeat = (float)dVar7;
            pkvd->fHandled = 1;
          }
          else {
            iVar2 = 0xb;
            bVar6 = false;
            pcVar3 = pcVar4;
            pcVar5 = "m_flRadius";
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar6 = *pcVar3 == *pcVar5;
              pcVar3 = pcVar3 + 1;
              pcVar5 = pcVar5 + 1;
            } while (bVar6);
            if (bVar6) {
              dVar7 = strtod(pkvd->szValue,(char **)0x0);
              this->m_flRadius = (float)dVar7;
              pkvd->fHandled = 1;
            }
            else {
              iVar2 = 0x12;
              bVar6 = false;
              pcVar3 = "m_iFinishSchedule";
              do {
                if (iVar2 == 0) break;
                iVar2 = iVar2 + -1;
                bVar6 = *pcVar4 == *pcVar3;
                pcVar4 = pcVar4 + 1;
                pcVar3 = pcVar3 + 1;
              } while (bVar6);
              if (!bVar6) {
                CBaseMonster::KeyValue(&this->super_CBaseMonster,pkvd);
                return;
              }
              lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
              this->m_iFinishSchedule = lVar1;
              pkvd->fHandled = 1;
            }
          }
        }
      }
    }
  }
  return;
}


// CCineMonster::Restore  @ 000e1350  (line 116)

/* DWARF original prototype: int Restore(CCineMonster * this, CRestore * restore) */

int __thiscall CCineMonster::Restore(CCineMonster *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Restore(&this->super_CBaseMonster,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CCineMonster",this,m_SaveData,0xd);
  }
  return iVar2;
}


// CCineMonster::Save  @ 000e13b0  (line 116)

/* DWARF original prototype: int Save(CCineMonster * this, CSave * save) */

int __thiscall CCineMonster::Save(CCineMonster *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Save(&this->super_CBaseMonster,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CCineMonster",this,m_SaveData,0xd);
  }
  return iVar2;
}


// scripted_sequence  @ 000e2370  (line 118)

void scripted_sequence(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6f0,pev);
  *puVar1 = &PTR__CCineMonster_00159700;
  puVar1[1] = pev;
  return;
}


// aiscripted_sequence  @ 000e23e0  (line 121)

void aiscripted_sequence(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6f0,pev);
  *puVar1 = &PTR__CCineAI_00159930;
  puVar1[1] = pev;
  return;
}


// CCineMonster::Spawn  @ 000e0a60  (line 125)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CCineMonster * this) */

void __thiscall CCineMonster::Spawn(CCineMonster *this)

{
  _2globalvars_t *p1Var1;
  entvars_t *peVar2;
  
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 0;
  p1Var1 = gpGlobals;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar2->targetname == 0) || (this->m_iszIdle != 0)) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CineThink;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar2->nextthink = p1Var1->time + 1.0;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar2->targetname != 0) {
      this->m_startTime = p1Var1->time + 1e+06;
    }
  }
  this->m_interruptable = (uint)((peVar2->spawnflags & 0x20) == 0);
  return;
}


// CCineMonster::FCanOverrideState  @ 000e0ae0  (line 158)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL FCanOverrideState(CCineMonster * this) */

BOOL __thiscall CCineMonster::FCanOverrideState(CCineMonster *this)

{
  return (uint)((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->spawnflags >> 6 & 1;
}


// CCineAI::FCanOverrideState  @ 000e0b00  (line 170)

/* DWARF original prototype: BOOL FCanOverrideState(CCineAI * this) */

BOOL __thiscall CCineAI::FCanOverrideState(CCineAI *this)

{
  return 1;
}


// CCineMonster::Use  @ 000e12d0  (line 177)

/* DWARF original prototype: void Use(CCineMonster * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CCineMonster::Use(CCineMonster *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
                 float value)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  CBaseEntity *pCVar3;
  int iVar4;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseMonster * pTarget@[???] */
  pCVar3 = EHANDLE::operator_cast_to_CBaseEntity_(&(this->super_CBaseMonster).m_hTargetEnt);
  if (pCVar3 != (CBaseEntity *)0x0) {
    iVar4 = (*pCVar3->_vptr_CBaseEntity[0x13])(pCVar3);
    if (iVar4 != 0) {
      if (*(int *)(iVar4 + 0x6b0) == 0) {
        return;
      }
      this->m_startTime = gpGlobals->time + 0.05;
      return;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseMonster * pTarget@[???] */
  p1Var2 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CineThink;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar1->nextthink = p1Var2->time;
  return;
}


// CCineMonster::Touch  @ 000e0b10  (line 209)

/* DWARF original prototype: void Touch(CCineMonster * this, CBaseEntity * pOther) */

void __thiscall CCineMonster::Touch(CCineMonster *this,CBaseEntity *pOther)

{
  return;
}


// CCineMonster::Die  @ 000e2450  (line 250)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Die(CCineMonster * this) */

void __thiscall CCineMonster::Die(CCineMonster *this)

{
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  return;
}


// CCineMonster::Pain  @ 000e2470  (line 258)

/* DWARF original prototype: void Pain(CCineMonster * this) */

void __thiscall CCineMonster::Pain(CCineMonster *this)

{
  return;
}


// CCineMonster::FindEntity  @ 000e2480  (line 268)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int FindEntity(CCineMonster * this) */

int __thiscall CCineMonster::FindEntity(CCineMonster *this)

{
  EHANDLE *this_00;
  int *piVar1;
  _func_int_varargs *p_Var2;
  entvars_t *peVar3;
  edict_t *peVar4;
  int iVar5;
  CBaseEntity *pEntity;
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: edict_t * pentTarget@[???]
                       Unresolved local var: CBaseMonster * pTarget@[???] */
  peVar4 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_iszEntity);
  this_00 = &(this->super_CBaseMonster).m_hTargetEnt;
  EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  while ((peVar4 != (edict_t *)0x0 &&
         (iVar5 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4), iVar5 != 0))) {
    if (((peVar4->v).flags & 0x20) != 0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      piVar1 = peVar4->pvPrivateData;
      if ((piVar1 != (int *)0x0) &&
         (pEntity = (CBaseEntity *)(**(code **)(*piVar1 + 0x4c))(piVar1),
         pEntity != (CBaseEntity *)0x0)) {
        p_Var2 = pEntity->_vptr_CBaseEntity[0x5f];
        iVar5 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity._vptr_CBaseEntity[0x88])(this);
        iVar5 = (*p_Var2)(pEntity,iVar5,1);
        if (iVar5 != 0) goto LAB_000e263e;
      }
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"Found %s, but can\'t play!\n",
                 gpGlobals->pStringBase + this->m_iszEntity);
    }
    peVar4 = (*g_engfuncs.pfnFindEntityByString)
                       (peVar4,"targetname",gpGlobals->pStringBase + this->m_iszEntity);
  }
  pStartEntity = (CBaseEntity *)0x0;
  do {
    do {
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
      pStartEntity = UTIL_FindEntityInSphere
                               (pStartEntity,
                                &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.pev)->origin,this->m_flRadius);
      if (pStartEntity == (CBaseEntity *)0x0) {
        EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
        return 0;
      }
      peVar3 = pStartEntity->pev;
      iVar5 = strcmp(gpGlobals->pStringBase + peVar3->classname,
                     gpGlobals->pStringBase + this->m_iszEntity);
    } while (((iVar5 != 0) || ((peVar3->flags & 0x20) == 0)) ||
            (pEntity = (CBaseEntity *)(*pStartEntity->_vptr_CBaseEntity[0x13])(pStartEntity),
            pEntity == (CBaseEntity *)0x0));
    p_Var2 = pEntity->_vptr_CBaseEntity[0x5f];
    iVar5 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x88])(this);
    iVar5 = (*p_Var2)(pEntity,iVar5,0);
  } while (iVar5 == 0);
LAB_000e263e:
  EHANDLE::operator=(this_00,pEntity);
  return 1;
}


// CCineMonster::PossessEntity  @ 000e2cc0  (line 317)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PossessEntity(CCineMonster * this) */

void __thiscall CCineMonster::PossessEntity(CCineMonster *this)

{
  uint *puVar1;
  entvars_t *peVar2;
  CBaseEntity *pCVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseMonster * pTarget@[???] */
  pCVar3 = EHANDLE::operator_cast_to_CBaseEntity_(&(this->super_CBaseMonster).m_hTargetEnt);
  if (pCVar3 != (CBaseEntity *)0x0) {
    iVar4 = (*pCVar3->_vptr_CBaseEntity[0x13])(pCVar3);
    if (iVar4 != 0) {
      *(CCineMonster **)(iVar4 + 8) = this;
      *(CCineMonster **)(iVar4 + 0x6b4) = this;
      EHANDLE::operator=((EHANDLE *)(iVar4 + 0x520),(CBaseEntity *)this);
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      this->m_saved_movetype = *(int *)(*(int *)(iVar4 + 4) + 0x108);
      this->m_saved_solid = *(int *)(*(int *)(iVar4 + 4) + 0x10c);
      this->m_saved_effects = *(int *)(*(int *)(iVar4 + 4) + 0x118);
      puVar1 = (uint *)(*(int *)(iVar4 + 4) + 0x118);
      *puVar1 = *puVar1 | peVar2->effects;
      iVar5 = this->m_fMoveTo;
      if (iVar5 == 1) {
        *(undefined4 *)(iVar4 + 0x6b0) = 3;
        DelayStart(this,1);
      }
      else if (iVar5 < 2) {
        if (iVar5 == 0) {
          *(undefined4 *)(iVar4 + 0x6b0) = 1;
        }
      }
      else if (iVar5 == 2) {
        *(undefined4 *)(iVar4 + 0x6b0) = 4;
        DelayStart(this,1);
      }
      else if (iVar5 == 4) {
        UTIL_SetOrigin(*(entvars_t **)(iVar4 + 4),
                       &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->origin);
        *(vec_t *)(*(int *)(iVar4 + 4) + 0xac) =
             (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->angles).y;
        iVar5 = *(int *)(iVar4 + 4);
        *(undefined4 *)(iVar5 + 0x5c) = 0;
        *(undefined4 *)(iVar5 + 0x60) = 0;
        *(undefined4 *)(iVar5 + 100) = 0;
        iVar5 = *(int *)(iVar4 + 4);
        *(undefined4 *)(iVar5 + 0x20) = 0;
        *(undefined4 *)(iVar5 + 0x24) = 0;
        *(undefined4 *)(iVar5 + 0x28) = 0;
        puVar1 = (uint *)(*(int *)(iVar4 + 4) + 0x118);
        *puVar1 = *puVar1 | 0x20;
        *(vec_t *)(*(int *)(iVar4 + 4) + 0x54) =
             (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->angles).y;
        *(undefined4 *)(iVar4 + 0x6b0) = 1;
        this->m_startTime = gpGlobals->time + 1e+06;
      }
      *(undefined4 *)(iVar4 + 0x594) = 6;
      if (this->m_iszIdle != 0) {
        (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity._vptr_CBaseEntity[0x87])(this,iVar4,this->m_iszIdle,0);
        iVar5 = strcmp(gpGlobals->pStringBase + this->m_iszIdle,
                       gpGlobals->pStringBase + this->m_iszPlay);
        if (iVar5 == 0) {
          *(undefined4 *)(*(int *)(iVar4 + 4) + 0x138) = 0;
        }
      }
    }
  }
  return;
}


// CCineAI::PossessEntity  @ 000e1450  (line 390)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PossessEntity(CCineAI * this) */

void __thiscall CCineAI::PossessEntity(CCineAI *this)

{
  int *piVar1;
  _func_int_varargs *p_Var2;
  code *pcVar3;
  entvars_t *peVar4;
  CBaseEntity *pCVar5;
  CBaseMonster *this_00;
  undefined4 uVar6;
  int iVar7;
  Schedule_t *pNewSchedule;
  _2globalvars_t *p1Var8;
  
                    /* Unresolved local var: Schedule_t * pNewSchedule@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseMonster * pTarget@[???] */
  pCVar5 = EHANDLE::operator_cast_to_CBaseEntity_
                     (&(this->super_CCineMonster).super_CBaseMonster.m_hTargetEnt);
  if ((pCVar5 != (CBaseEntity *)0x0) &&
     (this_00 = (CBaseMonster *)(*pCVar5->_vptr_CBaseEntity[0x13])(pCVar5),
     this_00 != (CBaseMonster *)0x0)) {
    p_Var2 = (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x5f];
    pcVar3 = *(code **)((int)(this->super_CCineMonster).super_CBaseMonster.super_CBaseToggle.
                             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                             _vptr_CBaseEntity + 0x220);
    uVar6 = 1;
    if (pcVar3 != FCanOverrideState) {
      uVar6 = (*pcVar3)(this);
    }
    iVar7 = (*p_Var2)(this_00,uVar6,2);
    if (iVar7 == 0) {
      (*g_engfuncs.pfnAlertMessage)
                (at_aiconsole,"(AI)Can\'t possess entity %s\n",
                 gpGlobals->pStringBase +
                 ((this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev)->classname);
      return;
    }
    (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pGoalEnt
         = (CBaseEntity *)this;
    this_00->m_pCine = &this->super_CCineMonster;
    EHANDLE::operator=(&this_00->m_hTargetEnt,(CBaseEntity *)this);
    peVar4 = (this->super_CCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    (this->super_CCineMonster).m_saved_movetype =
         ((this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
         ->movetype;
    (this->super_CCineMonster).m_saved_solid =
         ((this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
         ->solid;
    (this->super_CCineMonster).m_saved_effects =
         ((this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
         ->effects;
    piVar1 = &((this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              pev)->effects;
    *piVar1 = *piVar1 | peVar4->effects;
    p1Var8 = gpGlobals;
    switch((this->super_CCineMonster).m_fMoveTo) {
    case 0:
    case 5:
      this_00->m_scriptState = SCRIPT_WAIT;
      break;
    case 1:
      this_00->m_scriptState = SCRIPT_WALK_TO_MARK;
      break;
    case 2:
      this_00->m_scriptState = SCRIPT_RUN_TO_MARK;
      break;
    default:
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"aiscript:  invalid Move To Position value!");
      p1Var8 = gpGlobals;
      break;
    case 4:
      UTIL_SetOrigin((this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev,
                     &((this->super_CCineMonster).super_CBaseMonster.super_CBaseToggle.
                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->origin);
      ((this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      ideal_yaw = (((this->super_CCineMonster).super_CBaseMonster.super_CBaseToggle.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles).y;
      peVar4 = (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev;
      (peVar4->avelocity).x = 0.0;
      (peVar4->avelocity).y = 0.0;
      (peVar4->avelocity).z = 0.0;
      peVar4 = (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev;
      (peVar4->velocity).x = 0.0;
      (peVar4->velocity).y = 0.0;
      (peVar4->velocity).z = 0.0;
      piVar1 = &((this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 | 0x20;
      p1Var8 = gpGlobals;
      (((this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      angles).y = (((this->super_CCineMonster).super_CBaseMonster.super_CBaseToggle.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles).y;
      this_00->m_scriptState = SCRIPT_WAIT;
      (this->super_CCineMonster).m_startTime = p1Var8->time + 1e+06;
      piVar1 = &((this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->flags;
      *piVar1 = *piVar1 & 0xfffffdff;
    }
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"\"%s\" found and used\n",
               p1Var8->pStringBase +
               ((this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
               .pev)->targetname);
    this_00->m_IdealMonsterState = MONSTERSTATE_SCRIPT;
    if (this_00->m_MonsterState == MONSTERSTATE_SCRIPT) {
      pNewSchedule = (Schedule_t *)
                     (*(this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity._vptr_CBaseEntity[0x5c])(this_00,0x28);
      CBaseMonster::ChangeSchedule(this_00,pNewSchedule);
    }
  }
  return;
}


// CCineMonster::CineThink  @ 000e35b0  (line 472)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CineThink(CCineMonster * this) */

void __thiscall CCineMonster::CineThink(CCineMonster *this)

{
  int iVar1;
  
  iVar1 = FindEntity(this);
  if (iVar1 == 0) {
    CancelScript(this);
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"script \"%s\" can\'t find monster \"%s\"\n",
               gpGlobals->pStringBase +
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->targetname,gpGlobals->pStringBase + this->m_iszEntity);
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->nextthink = gpGlobals->time + 1.0;
    return;
  }
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x86])(this);
  (*g_engfuncs.pfnAlertMessage)
            (at_aiconsole,"script \"%s\" using monster \"%s\"\n",
             gpGlobals->pStringBase +
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->targetname,gpGlobals->pStringBase + this->m_iszEntity);
  return;
}


// CCineMonster::StartSequence  @ 000e1e40  (line 489)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL StartSequence(CCineMonster * this, CBaseMonster * pTarget, int
   iszSeq, BOOL completeOnEmpty) */

BOOL __thiscall
CCineMonster::StartSequence
          (CCineMonster *this,CBaseMonster *pTarget,int iszSeq,BOOL completeOnEmpty)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  vec_t vVar4;
  CCineMonster *pCVar5;
  float __x;
  _2globalvars_t *p1Var6;
  vec_t vVar7;
  vec_t vVar8;
  vec_t vVar9;
  entvars_t *peVar10;
  int iVar11;
  float fVar12;
  Vector local_24;
  Vector local_18;
  
  p1Var6 = gpGlobals;
  if ((iszSeq != 0) || (completeOnEmpty == 0)) {
    peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              pev;
    iVar11 = CBaseAnimating::LookupSequence
                       ((CBaseAnimating *)pTarget,gpGlobals->pStringBase + iszSeq);
    peVar10->sequence = iVar11;
    peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              pev;
    if (peVar10->sequence == -1) {
      (*g_engfuncs.pfnAlertMessage)
                (at_error,"%s: unknown scripted sequence \"%s\"\n",
                 gpGlobals->pStringBase + peVar10->targetname,gpGlobals->pStringBase + iszSeq);
      ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      sequence = 0;
      peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                .pev;
    }
    peVar10->frame = 0.0;
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)pTarget);
    return 1;
  }
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  if ((peVar10->spawnflags & 4) == 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar10->nextthink = p1Var6->time + 0.1;
  }
                    /* Unresolved local var: CCineMonster * pOldCine@[???] */
  pCVar5 = pTarget->m_pCine;
  if (pCVar5 == (CCineMonster *)0x0) {
    ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    movetype = 4;
    ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    solid = 3;
    pTarget->m_pCine = (CCineMonster *)0x0;
    EHANDLE::operator=(&pTarget->m_hTargetEnt,(CBaseEntity *)0x0);
    peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              pev;
    (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pGoalEnt
         = (CBaseEntity *)0x0;
    if (peVar10->deadflag == 1) goto LAB_000e206f;
  }
  else {
    EHANDLE::operator=(&(pCVar5->super_CBaseMonster).m_hTargetEnt,(CBaseEntity *)0x0);
    ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    movetype = pTarget->m_pCine->m_saved_movetype;
    ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    solid = pTarget->m_pCine->m_saved_solid;
    ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    effects = pTarget->m_pCine->m_saved_effects;
    pTarget->m_pCine = (CCineMonster *)0x0;
    EHANDLE::operator=(&pTarget->m_hTargetEnt,(CBaseEntity *)0x0);
    peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              pev;
    (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pGoalEnt
         = (CBaseEntity *)0x0;
    if (peVar10->deadflag == 1) {
LAB_000e206f:
      peVar10->health = 0.0;
      ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      framerate = 0.0;
      ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      solid = 0;
      CBaseMonster::SetState(pTarget,MONSTERSTATE_DEAD);
      ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      deadflag = 2;
      peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                .pev;
      local_18.z = (peVar10->mins).z + 2.0;
      local_18.x = (peVar10->maxs).x;
      local_18.y = (peVar10->maxs).y;
      UTIL_SetSize(peVar10,&peVar10->mins,&local_18);
      if ((pCVar5 == (CCineMonster *)0x0) ||
         ((((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->spawnflags & 8) == 0)) {
        CBaseEntity::SUB_StartFadeOut((CBaseEntity *)pTarget);
      }
      else {
        (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        m_pfnUse.__pfn =
             (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *
             )0x0;
        (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        m_pfnUse.__delta = 0;
        (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
        (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        m_pfnThink.__delta = 0;
        (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        m_pfnTouch.__pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
        (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        m_pfnTouch.__delta = 0;
      }
      ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      framerate = 0.0;
      ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      movetype = 0;
      piVar1 = &((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 | 0x20;
      goto LAB_000e1f6a;
    }
    if (pCVar5->m_iszPlay != 0) {
      if ((((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->spawnflags & 0x80) == 0) {
                    /* Unresolved local var: Vector new_origin@[???]
                       Unresolved local var: Vector new_angle@[???]
                       Unresolved local var: Vector oldOrigin@[???]
                       Unresolved local var: int drop@[???] */
        CBaseAnimating::GetBonePosition((CBaseAnimating *)pTarget,0,&local_24,&local_18);
        peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev;
        fVar2 = (peVar10->origin).x;
        fVar3 = (peVar10->origin).y;
        vVar4 = (peVar10->origin).z;
        __x = (fVar3 - local_24.y) * (fVar3 - local_24.y) +
              (fVar2 - local_24.x) * (fVar2 - local_24.x);
        fVar12 = SQRT(__x);
        if (NAN(fVar12)) {
          fVar12 = sqrtf(__x);
          peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev;
        }
        vVar7 = fVar2;
        vVar8 = fVar3;
        vVar9 = vVar4;
        if (8.0 <= fVar12) {
          vVar7 = local_24.x;
          vVar8 = local_24.y;
          vVar9 = local_24.z;
        }
        local_24.z = vVar9;
        local_24.y = vVar8;
        local_24.x = vVar7;
        (peVar10->origin).x = local_24.x;
        (((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
        ->origin).y = local_24.y;
        peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev;
        (peVar10->origin).z = (peVar10->origin).z + 1.0;
        piVar1 = &((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity.pev)->flags;
        *piVar1 = *piVar1 | 0x200;
        iVar11 = (*g_engfuncs.pfnDropToFloor)
                           (((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->pContainingEntity);
        if (iVar11 < 0) {
          peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev;
          (peVar10->origin).x = fVar2;
          (peVar10->origin).y = fVar3;
          (peVar10->origin).z = vVar4;
        }
        else if (iVar11 == 0) {
          (((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
           )->origin).z = local_24.z;
          piVar1 = &((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->flags;
          *piVar1 = *piVar1 & 0xfffffdff;
        }
        peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev;
        UTIL_SetOrigin(peVar10,&peVar10->origin);
        piVar1 = &((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity.pev)->effects;
        *piVar1 = *piVar1 | 0x20;
        peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev;
      }
      pTarget->m_Activity = ACT_RESET;
    }
  }
  peVar10->enemy = (edict_t *)0x0;
  peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
  ;
  if (peVar10->health <= 0.0) {
    pTarget->m_afConditions = pTarget->m_afConditions | 0x100;
    pTarget->m_IdealMonsterState = MONSTERSTATE_DEAD;
    peVar10->deadflag = 1;
    CBaseMonster::FCheckAITrigger(pTarget);
    ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    deadflag = 0;
    peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              pev;
  }
  else {
    pTarget->m_IdealMonsterState = MONSTERSTATE_IDLE;
  }
  peVar10->spawnflags = peVar10->spawnflags & 0xffffff7f;
LAB_000e1f6a:
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x89])(this,pTarget);
  CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)0x0,USE_TOGGLE,0.0);
  return 0;
}


// CCineAI::StartSequence  @ 000e1910  (line 523)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL StartSequence(CCineAI * this, CBaseMonster * pTarget, int iszSeq,
   BOOL completeOnEmpty) */

BOOL __thiscall
CCineAI::StartSequence(CCineAI *this,CBaseMonster *pTarget,int iszSeq,BOOL completeOnEmpty)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  vec_t vVar4;
  CCineMonster *pCVar5;
  float __x;
  _2globalvars_t *p1Var6;
  vec_t vVar7;
  vec_t vVar8;
  vec_t vVar9;
  entvars_t *peVar10;
  int iVar11;
  float fVar12;
  Vector local_24;
  Vector local_18;
  
  p1Var6 = gpGlobals;
  if ((iszSeq != 0) || (completeOnEmpty == 0)) {
    peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              pev;
    iVar11 = CBaseAnimating::LookupSequence
                       ((CBaseAnimating *)pTarget,gpGlobals->pStringBase + iszSeq);
    peVar10->sequence = iVar11;
    peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              pev;
    if (peVar10->sequence == -1) {
      (*g_engfuncs.pfnAlertMessage)
                (at_error,"%s: unknown aiscripted sequence \"%s\"\n",
                 gpGlobals->pStringBase + peVar10->targetname,gpGlobals->pStringBase + iszSeq);
      ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      sequence = 0;
      peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                .pev;
    }
    peVar10->frame = 0.0;
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)pTarget);
    return 1;
  }
  peVar10 = (this->super_CCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar10->spawnflags & 4) == 0) {
    (this->super_CCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (this->super_CCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
    super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar10->nextthink = p1Var6->time + 0.1;
  }
                    /* Unresolved local var: CCineMonster * pOldCine@[???] */
  pCVar5 = pTarget->m_pCine;
  if (pCVar5 == (CCineMonster *)0x0) {
    ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    movetype = 4;
    ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    solid = 3;
    pTarget->m_pCine = (CCineMonster *)0x0;
    EHANDLE::operator=(&pTarget->m_hTargetEnt,(CBaseEntity *)0x0);
    peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              pev;
    (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pGoalEnt
         = (CBaseEntity *)0x0;
    if (peVar10->deadflag == 1) goto LAB_000e1b3f;
  }
  else {
    EHANDLE::operator=(&(pCVar5->super_CBaseMonster).m_hTargetEnt,(CBaseEntity *)0x0);
    ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    movetype = pTarget->m_pCine->m_saved_movetype;
    ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    solid = pTarget->m_pCine->m_saved_solid;
    ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    effects = pTarget->m_pCine->m_saved_effects;
    pTarget->m_pCine = (CCineMonster *)0x0;
    EHANDLE::operator=(&pTarget->m_hTargetEnt,(CBaseEntity *)0x0);
    peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              pev;
    (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pGoalEnt
         = (CBaseEntity *)0x0;
    if (peVar10->deadflag == 1) {
LAB_000e1b3f:
      peVar10->health = 0.0;
      ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      framerate = 0.0;
      ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      solid = 0;
      CBaseMonster::SetState(pTarget,MONSTERSTATE_DEAD);
      ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      deadflag = 2;
      peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                .pev;
      local_18.z = (peVar10->mins).z + 2.0;
      local_18.x = (peVar10->maxs).x;
      local_18.y = (peVar10->maxs).y;
      UTIL_SetSize(peVar10,&peVar10->mins,&local_18);
      if ((pCVar5 == (CCineMonster *)0x0) ||
         ((((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->spawnflags & 8) == 0)) {
        CBaseEntity::SUB_StartFadeOut((CBaseEntity *)pTarget);
      }
      else {
        (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        m_pfnUse.__pfn =
             (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *
             )0x0;
        (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        m_pfnUse.__delta = 0;
        (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
        (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        m_pfnThink.__delta = 0;
        (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        m_pfnTouch.__pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
        (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        m_pfnTouch.__delta = 0;
      }
      ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      framerate = 0.0;
      ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      movetype = 0;
      piVar1 = &((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 | 0x20;
      goto LAB_000e1a3a;
    }
    if (pCVar5->m_iszPlay != 0) {
      if ((((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->spawnflags & 0x80) == 0) {
                    /* Unresolved local var: Vector new_origin@[???]
                       Unresolved local var: Vector new_angle@[???]
                       Unresolved local var: Vector oldOrigin@[???]
                       Unresolved local var: int drop@[???] */
        CBaseAnimating::GetBonePosition((CBaseAnimating *)pTarget,0,&local_24,&local_18);
        peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev;
        fVar2 = (peVar10->origin).x;
        fVar3 = (peVar10->origin).y;
        vVar4 = (peVar10->origin).z;
        __x = (fVar3 - local_24.y) * (fVar3 - local_24.y) +
              (fVar2 - local_24.x) * (fVar2 - local_24.x);
        fVar12 = SQRT(__x);
        if (NAN(fVar12)) {
          fVar12 = sqrtf(__x);
          peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev;
        }
        vVar7 = fVar2;
        vVar8 = fVar3;
        vVar9 = vVar4;
        if (8.0 <= fVar12) {
          vVar7 = local_24.x;
          vVar8 = local_24.y;
          vVar9 = local_24.z;
        }
        local_24.z = vVar9;
        local_24.y = vVar8;
        local_24.x = vVar7;
        (peVar10->origin).x = local_24.x;
        (((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
        ->origin).y = local_24.y;
        peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev;
        (peVar10->origin).z = (peVar10->origin).z + 1.0;
        piVar1 = &((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity.pev)->flags;
        *piVar1 = *piVar1 | 0x200;
        iVar11 = (*g_engfuncs.pfnDropToFloor)
                           (((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->pContainingEntity);
        if (iVar11 < 0) {
          peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev;
          (peVar10->origin).x = fVar2;
          (peVar10->origin).y = fVar3;
          (peVar10->origin).z = vVar4;
        }
        else if (iVar11 == 0) {
          (((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
           )->origin).z = local_24.z;
          piVar1 = &((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->flags;
          *piVar1 = *piVar1 & 0xfffffdff;
        }
        peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev;
        UTIL_SetOrigin(peVar10,&peVar10->origin);
        piVar1 = &((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity.pev)->effects;
        *piVar1 = *piVar1 | 0x20;
        peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev;
      }
      pTarget->m_Activity = ACT_RESET;
    }
  }
  peVar10->enemy = (edict_t *)0x0;
  peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
  ;
  if (peVar10->health <= 0.0) {
    pTarget->m_afConditions = pTarget->m_afConditions | 0x100;
    pTarget->m_IdealMonsterState = MONSTERSTATE_DEAD;
    peVar10->deadflag = 1;
    CBaseMonster::FCheckAITrigger(pTarget);
    ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    deadflag = 0;
    peVar10 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              pev;
  }
  else {
    pTarget->m_IdealMonsterState = MONSTERSTATE_IDLE;
  }
  peVar10->spawnflags = peVar10->spawnflags & 0xffffff7f;
LAB_000e1a3a:
  (**(code **)((int)(this->super_CCineMonster).super_CBaseMonster.super_CBaseToggle.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity +
              0x224))(this,pTarget);
  CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)0x0,USE_TOGGLE,0.0);
  return 1;
}


// CCineMonster::SequenceDone  @ 000e2680  (line 557)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SequenceDone(CCineMonster * this, CBaseMonster * pMonster) */

void __thiscall CCineMonster::SequenceDone(CCineMonster *this,CBaseMonster *pMonster)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  vec_t vVar4;
  CCineMonster *pCVar5;
  float __x;
  _2globalvars_t *p1Var6;
  vec_t vVar7;
  vec_t vVar8;
  vec_t vVar9;
  entvars_t *peVar10;
  int iVar11;
  float fVar12;
  Vector local_24;
  Vector local_18;
  
  p1Var6 = gpGlobals;
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  if ((peVar10->spawnflags & 4) == 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar10->nextthink = p1Var6->time + 0.1;
  }
                    /* Unresolved local var: CCineMonster * pOldCine@[???] */
  pCVar5 = pMonster->m_pCine;
  if (pCVar5 == (CCineMonster *)0x0) {
    ((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    movetype = 4;
    ((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    solid = 3;
    pMonster->m_pCine = (CCineMonster *)0x0;
    EHANDLE::operator=(&pMonster->m_hTargetEnt,(CBaseEntity *)0x0);
    peVar10 = (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              pev;
    (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pGoalEnt
         = (CBaseEntity *)0x0;
    if (peVar10->deadflag == 1) goto LAB_000e2837;
  }
  else {
    EHANDLE::operator=(&(pCVar5->super_CBaseMonster).m_hTargetEnt,(CBaseEntity *)0x0);
    ((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    movetype = pMonster->m_pCine->m_saved_movetype;
    ((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    solid = pMonster->m_pCine->m_saved_solid;
    ((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    effects = pMonster->m_pCine->m_saved_effects;
    pMonster->m_pCine = (CCineMonster *)0x0;
    EHANDLE::operator=(&pMonster->m_hTargetEnt,(CBaseEntity *)0x0);
    peVar10 = (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              pev;
    (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pGoalEnt
         = (CBaseEntity *)0x0;
    if (peVar10->deadflag == 1) {
LAB_000e2837:
      peVar10->health = 0.0;
      ((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      framerate = 0.0;
      ((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      solid = 0;
      CBaseMonster::SetState(pMonster,MONSTERSTATE_DEAD);
      ((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      deadflag = 2;
      peVar10 = (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      local_18.z = (peVar10->mins).z + 2.0;
      local_18.x = (peVar10->maxs).x;
      local_18.y = (peVar10->maxs).y;
      UTIL_SetSize(peVar10,&peVar10->mins,&local_18);
      if ((pCVar5 == (CCineMonster *)0x0) ||
         ((((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->spawnflags & 8) == 0)) {
        CBaseEntity::SUB_StartFadeOut((CBaseEntity *)pMonster);
      }
      else {
        (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        m_pfnUse.__pfn =
             (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *
             )0x0;
        (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        m_pfnUse.__delta = 0;
        (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
        (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        m_pfnThink.__delta = 0;
        (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        m_pfnTouch.__pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
        (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        m_pfnTouch.__delta = 0;
      }
      ((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      framerate = 0.0;
      ((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      movetype = 0;
      piVar1 = &((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 | 0x20;
      goto LAB_000e278e;
    }
    if (pCVar5->m_iszPlay != 0) {
      if ((((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->spawnflags & 0x80) == 0) {
                    /* Unresolved local var: Vector new_origin@[???]
                       Unresolved local var: Vector new_angle@[???]
                       Unresolved local var: Vector oldOrigin@[???]
                       Unresolved local var: int drop@[???] */
        CBaseAnimating::GetBonePosition((CBaseAnimating *)pMonster,0,&local_24,&local_18);
        peVar10 = (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev;
        fVar2 = (peVar10->origin).x;
        fVar3 = (peVar10->origin).y;
        vVar4 = (peVar10->origin).z;
        __x = (fVar3 - local_24.y) * (fVar3 - local_24.y) +
              (fVar2 - local_24.x) * (fVar2 - local_24.x);
        fVar12 = SQRT(__x);
        if (NAN(fVar12)) {
          fVar12 = sqrtf(__x);
          peVar10 = (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev;
        }
        vVar7 = fVar2;
        vVar8 = fVar3;
        vVar9 = vVar4;
        if (8.0 <= fVar12) {
          vVar7 = local_24.x;
          vVar8 = local_24.y;
          vVar9 = local_24.z;
        }
        local_24.z = vVar9;
        local_24.y = vVar8;
        local_24.x = vVar7;
        (peVar10->origin).x = local_24.x;
        (((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
        ->origin).y = local_24.y;
        peVar10 = (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev;
        (peVar10->origin).z = (peVar10->origin).z + 1.0;
        piVar1 = &((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity.pev)->flags;
        *piVar1 = *piVar1 | 0x200;
        iVar11 = (*g_engfuncs.pfnDropToFloor)
                           (((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->pContainingEntity);
        if (iVar11 < 0) {
          peVar10 = (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev;
          (peVar10->origin).x = fVar2;
          (peVar10->origin).y = fVar3;
          (peVar10->origin).z = vVar4;
        }
        else if (iVar11 == 0) {
          (((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           pev)->origin).z = local_24.z;
          piVar1 = &((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->flags;
          *piVar1 = *piVar1 & 0xfffffdff;
        }
        peVar10 = (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev;
        UTIL_SetOrigin(peVar10,&peVar10->origin);
        piVar1 = &((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity.pev)->effects;
        *piVar1 = *piVar1 | 0x20;
        peVar10 = (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                  super_CBaseEntity.pev;
      }
      pMonster->m_Activity = ACT_RESET;
    }
  }
  peVar10->enemy = (edict_t *)0x0;
  peVar10 = (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            pev;
  if (peVar10->health <= 0.0) {
    pMonster->m_afConditions = pMonster->m_afConditions | 0x100;
    pMonster->m_IdealMonsterState = MONSTERSTATE_DEAD;
    peVar10->deadflag = 1;
    CBaseMonster::FCheckAITrigger(pMonster);
    ((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    deadflag = 0;
    peVar10 = (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              pev;
  }
  else {
    pMonster->m_IdealMonsterState = MONSTERSTATE_IDLE;
  }
  peVar10->spawnflags = peVar10->spawnflags & 0xffffff7f;
LAB_000e278e:
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x89])(this,pMonster);
  CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)0x0,USE_TOGGLE,0.0);
  return;
}


// CCineMonster::FixScriptMonsterSchedule  @ 000e0f10  (line 586)

/* DWARF original prototype: void FixScriptMonsterSchedule(CCineMonster * this, CBaseMonster *
   pMonster) */

void __thiscall CCineMonster::FixScriptMonsterSchedule(CCineMonster *this,CBaseMonster *pMonster)

{
  if (pMonster->m_IdealMonsterState != MONSTERSTATE_DEAD) {
    pMonster->m_IdealMonsterState = MONSTERSTATE_IDLE;
  }
  CBaseMonster::ClearSchedule(pMonster);
  return;
}


// CCineAI::FixScriptMonsterSchedule  @ 000e1260  (line 606)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void FixScriptMonsterSchedule(CCineAI * this, CBaseMonster * pMonster)
    */

void __thiscall CCineAI::FixScriptMonsterSchedule(CCineAI *this,CBaseMonster *pMonster)

{
  int iVar1;
  Schedule_t *pNewSchedule;
  
  iVar1 = (this->super_CCineMonster).m_iFinishSchedule;
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      pNewSchedule = (Schedule_t *)
                     (*(pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity._vptr_CBaseEntity[0x5c])(pMonster,0x20);
      CBaseMonster::ChangeSchedule(pMonster,pNewSchedule);
      return;
    }
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"FixScriptMonsterSchedule - no case!\n");
  }
  CBaseMonster::ClearSchedule(pMonster);
  return;
}


// CBaseMonster::ExitScriptedSequence  @ 000e3670  (line 623)

/* DWARF original prototype: BOOL ExitScriptedSequence(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::ExitScriptedSequence(CBaseMonster *this)

{
  if (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      deadflag == 1) {
    this->m_IdealMonsterState = MONSTERSTATE_DEAD;
    return 0;
  }
  if (this->m_pCine != (CCineMonster *)0x0) {
    CCineMonster::CancelScript(this->m_pCine);
    return 1;
  }
  return 1;
}


// CCineMonster::AllowInterrupt  @ 000e2af0  (line 642)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void AllowInterrupt(CCineMonster * this, BOOL fAllow) */

void __thiscall CCineMonster::AllowInterrupt(CCineMonster *this,BOOL fAllow)

{
  if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->spawnflags & 0x20) == 0) {
    this->m_interruptable = fAllow;
  }
  return;
}


// CCineMonster::CanInterrupt  @ 000e2b10  (line 650)

/* DWARF original prototype: BOOL CanInterrupt(CCineMonster * this) */

BOOL __thiscall CCineMonster::CanInterrupt(CCineMonster *this)

{
  CBaseEntity *pCVar1;
  
                    /* Unresolved local var: CBaseEntity * pTarget@[???] */
  if (this->m_interruptable != 0) {
    pCVar1 = EHANDLE::operator_cast_to_CBaseEntity_(&(this->super_CBaseMonster).m_hTargetEnt);
    if ((pCVar1 != (CBaseEntity *)0x0) && (pCVar1->pev->deadflag == 0)) {
      return 1;
    }
  }
                    /* Unresolved local var: CBaseEntity * pTarget@[???] */
  return 0;
}


// CCineMonster::IgnoreConditions  @ 000e1160  (line 664)

/* DWARF original prototype: int IgnoreConditions(CCineMonster * this) */

int __thiscall CCineMonster::IgnoreConditions(CCineMonster *this)

{
  CBaseEntity *pCVar1;
  
                    /* Unresolved local var: CBaseEntity * pTarget@[???] */
                    /* Unresolved local var: CBaseEntity * pTarget@[???] */
  if (((this->m_interruptable != 0) &&
      (pCVar1 = EHANDLE::operator_cast_to_CBaseEntity_(&(this->super_CBaseMonster).m_hTargetEnt),
      pCVar1 != (CBaseEntity *)0x0)) && (pCVar1->pev->deadflag == 0)) {
    return 0;
  }
  return 0x300;
}


// ScriptEntityCancel  @ 000e3300  (line 672)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ScriptEntityCancel(edict_t *pentCine)

{
  char *pcVar1;
  uint uVar2;
  CBaseEntity *pCVar3;
  CBaseMonster *this;
  edict_t *peVar4;
  undefined4 *puVar5;
  int iVar6;
  entvars_t *pev;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  
  pcVar1 = gpGlobals->pStringBase;
  if (pentCine == (edict_t *)0x0) {
    iVar6 = 0x12;
    bVar9 = CARRY4((uint)pcVar1,_DAT_00000000);
    bVar10 = (byte *)(pcVar1 + _DAT_00000000) == (byte *)0x0;
    pbVar7 = (byte *)(pcVar1 + _DAT_00000000);
    pbVar8 = (byte *)"scripted_sequence";
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
    peVar4 = (*g_engfuncs.pfnCreateEntity)();
    pev = (entvars_t *)0x0;
    if (peVar4 != (edict_t *)0x0) {
      pev = &peVar4->v;
    }
  }
  else {
    uVar2 = (pentCine->v).classname;
                    /* Unresolved local var: CCineMonster * pCineTarget@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseMonster * pTarget@[???] */
    bVar9 = CARRY4((uint)pcVar1,uVar2);
    bVar10 = (byte *)(pcVar1 + uVar2) == (byte *)0x0;
    iVar6 = 0x12;
    pbVar7 = (byte *)(pcVar1 + uVar2);
    pbVar8 = (byte *)"scripted_sequence";
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar9 = *pbVar7 < *pbVar8;
      bVar10 = *pbVar7 == *pbVar8;
      pbVar7 = pbVar7 + 1;
      pbVar8 = pbVar8 + 1;
    } while (bVar10);
    pev = &pentCine->v;
    if ((!bVar9 && !bVar10) != bVar9) {
      return;
    }
  }
                    /* Unresolved local var: entvars_t * pev@[???] */
  if ((pev->pContainingEntity == (edict_t *)0x0) ||
     (puVar5 = pev->pContainingEntity->pvPrivateData, puVar5 == (undefined4 *)0x0)) {
    puVar5 = CBaseEntity::operator_new(0x6f0,pev);
    *puVar5 = &PTR__CCineMonster_00159700;
    puVar5[1] = pev;
  }
  pCVar3 = EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)(puVar5 + 0x148));
  if (((pCVar3 != (CBaseEntity *)0x0) &&
      (this = (CBaseMonster *)(*pCVar3->_vptr_CBaseEntity[0x13])(pCVar3),
      this != (CBaseMonster *)0x0)) && (this->m_MonsterState == MONSTERSTATE_SCRIPT)) {
    this->m_scriptState = SCRIPT_CLEANUP;
    CBaseMonster::CineCleanup(this);
    return;
  }
  return;
}


// CCineMonster::CancelScript  @ 000e3420  (line 700)

/* DWARF original prototype: void CancelScript(CCineMonster * this) */

void __thiscall CCineMonster::CancelScript(CCineMonster *this)

{
  entvars_t *peVar1;
  string_t sVar2;
  edict_t *peVar3;
  edict_t *peVar4;
  int iVar5;
  CBaseEntity *pCVar6;
  CBaseMonster *this_00;
  char *pcVar7;
  undefined4 *puVar8;
  char *pcVar9;
  char *pcVar10;
  bool bVar11;
  byte bVar12;
  
                    /* Unresolved local var: edict_t * pentCineTarget@[???] */
  bVar12 = 0;
  (*g_engfuncs.pfnAlertMessage)
            (at_aiconsole,"Cancelling script: %s\n",gpGlobals->pStringBase + this->m_iszPlay);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  sVar2 = peVar1->targetname;
  if (sVar2 == 0) {
    ScriptEntityCancel(peVar1->pContainingEntity);
    return;
  }
  peVar4 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + sVar2);
  if (peVar4 != (edict_t *)0x0) {
    while (iVar5 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4), iVar5 != 0) {
      iVar5 = 0x12;
      pcVar7 = gpGlobals->pStringBase;
      bVar11 = pcVar7 + (peVar4->v).classname == (char *)0x0;
      pcVar9 = pcVar7 + (peVar4->v).classname;
      pcVar10 = "scripted_sequence";
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar11 = *pcVar9 == *pcVar10;
        pcVar9 = pcVar9 + (uint)bVar12 * -2 + 1;
        pcVar10 = pcVar10 + (uint)bVar12 * -2 + 1;
      } while (bVar11);
      if (bVar11) {
        peVar3 = (peVar4->v).pContainingEntity;
                    /* Unresolved local var: CCineMonster * pCineTarget@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseMonster * pTarget@[???] */
                    /* Unresolved local var: entvars_t * pev@[???] */
        if ((peVar3 == (edict_t *)0x0) ||
           (puVar8 = peVar3->pvPrivateData, puVar8 == (undefined4 *)0x0)) {
          puVar8 = CBaseEntity::operator_new(0x6f0,&peVar4->v);
          *puVar8 = &PTR__CCineMonster_00159700;
          puVar8[1] = &peVar4->v;
        }
        pCVar6 = EHANDLE::operator_cast_to_CBaseEntity_((EHANDLE *)(puVar8 + 0x148));
        if (((pCVar6 != (CBaseEntity *)0x0) &&
            (this_00 = (CBaseMonster *)(*pCVar6->_vptr_CBaseEntity[0x13])(pCVar6),
            this_00 != (CBaseMonster *)0x0)) && (this_00->m_MonsterState == MONSTERSTATE_SCRIPT)) {
          this_00->m_scriptState = SCRIPT_CLEANUP;
          CBaseMonster::CineCleanup(this_00);
        }
        pcVar7 = gpGlobals->pStringBase;
      }
      peVar4 = (*g_engfuncs.pfnFindEntityByString)
                         (peVar4,"targetname",
                          pcVar7 + ((this->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                   targetname);
      if (peVar4 == (edict_t *)0x0) {
        return;
      }
    }
  }
  return;
}


// CCineMonster::DelayStart  @ 000e2b60  (line 721)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DelayStart(CCineMonster * this, int state) */

void __thiscall CCineMonster::DelayStart(CCineMonster *this,int state)

{
  edict_t *peVar1;
  _2globalvars_t *p1Var2;
  edict_t *peVar3;
  int iVar4;
  char *pcVar5;
  undefined4 *puVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  byte bVar10;
  
                    /* Unresolved local var: edict_t * pentCine@[???] */
  bVar10 = 0;
  peVar3 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",
                      gpGlobals->pStringBase +
                      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->targetname);
  if (peVar3 != (edict_t *)0x0) {
    while (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3), iVar4 != 0) {
      iVar4 = 0x12;
      pcVar5 = gpGlobals->pStringBase;
      bVar9 = pcVar5 + (peVar3->v).classname == (char *)0x0;
      pcVar7 = pcVar5 + (peVar3->v).classname;
      pcVar8 = "scripted_sequence";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar9 = *pcVar7 == *pcVar8;
        pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
        pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
      } while (bVar9);
      if (bVar9) {
        peVar1 = (peVar3->v).pContainingEntity;
                    /* Unresolved local var: CCineMonster * pTarget@[DW_OP_reg0(EAX)] */
                    /* Unresolved local var: entvars_t * pev@[???] */
        if ((peVar1 == (edict_t *)0x0) ||
           (puVar6 = peVar1->pvPrivateData, puVar6 == (undefined4 *)0x0)) {
          puVar6 = CBaseEntity::operator_new(0x6f0,&peVar3->v);
          *puVar6 = &PTR__CCineMonster_00159700;
          puVar6[1] = &peVar3->v;
        }
        p1Var2 = gpGlobals;
        if (state == 0) {
          iVar4 = puVar6[0x1b6];
          puVar6[0x1b6] = iVar4 + -1;
          if (iVar4 + -1 < 1) {
            puVar6[0x1b7] = p1Var2->time + 0.05;
          }
          pcVar5 = p1Var2->pStringBase;
        }
        else {
          puVar6[0x1b6] = puVar6[0x1b6] + 1;
          pcVar5 = p1Var2->pStringBase;
        }
      }
      peVar3 = (*g_engfuncs.pfnFindEntityByString)
                         (peVar3,"targetname",
                          pcVar5 + ((this->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                   targetname);
      if (peVar3 == (edict_t *)0x0) {
        return;
      }
    }
  }
  return;
}


// CCineMonster::Activate  @ 000e1710  (line 748)

/* DWARF original prototype: void Activate(CCineMonster * this) */

void __thiscall CCineMonster::Activate(CCineMonster *this)

{
  int *piVar1;
  edict_t *peVar2;
  int iVar3;
  void *pmodel;
  
                    /* Unresolved local var: edict_t * pentTarget@[???]
                       Unresolved local var: CBaseMonster * pTarget@[???] */
  peVar2 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_iszEntity);
LAB_000e1750:
  do {
    if ((peVar2 == (edict_t *)0x0) ||
       (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2), iVar3 == 0)) {
      peVar2 = (*g_engfuncs.pfnFindEntityByString)
                         ((edict_t *)0x0,"classname",gpGlobals->pStringBase + this->m_iszEntity);
      do {
        while( true ) {
          if (peVar2 == (edict_t *)0x0) {
            return;
          }
          iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2);
          if (iVar3 == 0) {
            return;
          }
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
          piVar1 = peVar2->pvPrivateData;
          if (piVar1 != (int *)0x0) break;
          peVar2 = (*g_engfuncs.pfnFindEntityByString)
                             (peVar2,"targetname",gpGlobals->pStringBase + this->m_iszEntity);
        }
        iVar3 = (**(code **)(*piVar1 + 0x4c))(piVar1);
        peVar2 = (*g_engfuncs.pfnFindEntityByString)
                           (peVar2,"targetname",gpGlobals->pStringBase + this->m_iszEntity);
      } while (iVar3 == 0);
LAB_000e1841:
                    /* Unresolved local var: void * pmodel@[???] */
      pmodel = (*g_engfuncs.pfnGetModelPtr)(*(edict_t **)(*(int *)(iVar3 + 4) + 0x208));
      if (pmodel != (void *)0x0) {
        SequencePrecache(pmodel,gpGlobals->pStringBase + this->m_iszIdle);
        SequencePrecache(pmodel,gpGlobals->pStringBase + this->m_iszPlay);
      }
      return;
    }
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((((peVar2->v).flags & 0x20) == 0) || (piVar1 = peVar2->pvPrivateData, piVar1 == (int *)0x0))
    {
      peVar2 = (*g_engfuncs.pfnFindEntityByString)
                         (peVar2,"targetname",gpGlobals->pStringBase + this->m_iszEntity);
      goto LAB_000e1750;
    }
    iVar3 = (**(code **)(*piVar1 + 0x4c))(piVar1);
    peVar2 = (*g_engfuncs.pfnFindEntityByString)
                       (peVar2,"targetname",gpGlobals->pStringBase + this->m_iszEntity);
    if (iVar3 != 0) goto LAB_000e1841;
  } while( true );
}


// CBaseMonster::CineCleanup  @ 000e2ee0  (line 792)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL CineCleanup(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::CineCleanup(CBaseMonster *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  vec_t vVar4;
  CCineMonster *pCVar5;
  float __x;
  vec_t vVar6;
  vec_t vVar7;
  vec_t vVar8;
  entvars_t *peVar9;
  int iVar10;
  float fVar11;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: CCineMonster * pOldCine@[???] */
  pCVar5 = this->m_pCine;
  if (pCVar5 == (CCineMonster *)0x0) {
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    movetype = 4;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid =
         3;
    this->m_pCine = (CCineMonster *)0x0;
    EHANDLE::operator=(&this->m_hTargetEnt,(CBaseEntity *)0x0);
    peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pGoalEnt =
         (CBaseEntity *)0x0;
    if (peVar9->deadflag == 1) goto LAB_000e303f;
  }
  else {
    EHANDLE::operator=(&(pCVar5->super_CBaseMonster).m_hTargetEnt,(CBaseEntity *)0x0);
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    movetype = this->m_pCine->m_saved_movetype;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid =
         this->m_pCine->m_saved_solid;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->effects
         = this->m_pCine->m_saved_effects;
    this->m_pCine = (CCineMonster *)0x0;
    EHANDLE::operator=(&this->m_hTargetEnt,(CBaseEntity *)0x0);
    peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pGoalEnt =
         (CBaseEntity *)0x0;
    if (peVar9->deadflag == 1) {
LAB_000e303f:
      peVar9->health = 0.0;
      ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      framerate = 0.0;
      ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid
           = 0;
      SetState(this,MONSTERSTATE_DEAD);
      ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      deadflag = 2;
      peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      local_18.z = (peVar9->mins).z + 2.0;
      local_18.x = (peVar9->maxs).x;
      local_18.y = (peVar9->maxs).y;
      UTIL_SetSize(peVar9,&peVar9->mins,&local_18);
      if ((pCVar5 == (CCineMonster *)0x0) ||
         ((((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->spawnflags & 8) == 0)) {
        CBaseEntity::SUB_StartFadeOut((CBaseEntity *)this);
      }
      else {
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.
        __pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float
                 *)0x0;
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.
        __delta = 0;
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink
        .__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink
        .__delta = 0;
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch
        .__pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch
        .__delta = 0;
      }
      ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      framerate = 0.0;
      ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      movetype = 0;
      piVar1 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev)->effects;
      *piVar1 = *piVar1 | 0x20;
      return 0;
    }
    if (pCVar5->m_iszPlay != 0) {
      if ((((pCVar5->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->spawnflags & 0x80) == 0) {
                    /* Unresolved local var: Vector new_origin@[???]
                       Unresolved local var: Vector new_angle@[???]
                       Unresolved local var: Vector oldOrigin@[???]
                       Unresolved local var: int drop@[???] */
        CBaseAnimating::GetBonePosition((CBaseAnimating *)this,0,&local_24,&local_18);
        peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev;
        fVar2 = (peVar9->origin).x;
        fVar3 = (peVar9->origin).y;
        vVar4 = (peVar9->origin).z;
        __x = (fVar2 - local_24.x) * (fVar2 - local_24.x) +
              (fVar3 - local_24.y) * (fVar3 - local_24.y);
        fVar11 = SQRT(__x);
        if (NAN(fVar11)) {
          fVar11 = sqrtf(__x);
          peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   .pev;
        }
        vVar6 = fVar2;
        vVar7 = fVar3;
        vVar8 = vVar4;
        if (8.0 <= fVar11) {
          vVar6 = local_24.x;
          vVar7 = local_24.y;
          vVar8 = local_24.z;
        }
        local_24.z = vVar8;
        local_24.y = vVar7;
        local_24.x = vVar6;
        (peVar9->origin).x = local_24.x;
        (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        origin).y = local_24.y;
        peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev;
        (peVar9->origin).z = (peVar9->origin).z + 1.0;
        piVar1 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                  .pev)->flags;
        *piVar1 = *piVar1 | 0x200;
        iVar10 = (*g_engfuncs.pfnDropToFloor)
                           (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                             super_CBaseEntity.pev)->pContainingEntity);
        if (iVar10 < 0) {
          peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   .pev;
          (peVar9->origin).x = fVar2;
          (peVar9->origin).y = fVar3;
          (peVar9->origin).z = vVar4;
        }
        else if (iVar10 == 0) {
          (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
          origin).z = local_24.z;
          piVar1 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev)->flags;
          *piVar1 = *piVar1 & 0xfffffdff;
        }
        peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev;
        UTIL_SetOrigin(peVar9,&peVar9->origin);
        piVar1 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                  .pev)->effects;
        *piVar1 = *piVar1 | 0x20;
        peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev;
      }
      this->m_Activity = ACT_RESET;
    }
  }
  peVar9->enemy = (edict_t *)0x0;
  peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar9->health <= 0.0) {
    this->m_afConditions = this->m_afConditions | 0x100;
    this->m_IdealMonsterState = MONSTERSTATE_DEAD;
    peVar9->deadflag = 1;
    FCheckAITrigger(this);
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    deadflag = 0;
    peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  else {
    this->m_IdealMonsterState = MONSTERSTATE_IDLE;
  }
  peVar9->spawnflags = peVar9->spawnflags & 0xffffff7f;
  return 1;
}


// CScriptedSentence::~CScriptedSentence  @ 000e3e10  (line 917)

/* DWARF original prototype: void ~CScriptedSentence(CScriptedSentence * this, int __in_chrg) */

void __thiscall CScriptedSentence::~CScriptedSentence(CScriptedSentence *this,int __in_chrg)

{
  return;
}


// CScriptedSentence::ObjectCaps  @ 000e3dd0  (line 925)

/* DWARF original prototype: int ObjectCaps(CScriptedSentence * this) */

int __thiscall CScriptedSentence::ObjectCaps(CScriptedSentence *this)

{
  return 0;
}


// CScriptedSentence::Restore  @ 000e11a0  (line 968)

/* DWARF original prototype: int Restore(CScriptedSentence * this, CRestore * restore) */

int __thiscall CScriptedSentence::Restore(CScriptedSentence *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Restore(&this->super_CBaseToggle,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CScriptedSentence",this,m_SaveData,9);
  }
  return iVar2;
}


// CScriptedSentence::Save  @ 000e1200  (line 968)

/* DWARF original prototype: int Save(CScriptedSentence * this, CSave * save) */

int __thiscall CScriptedSentence::Save(CScriptedSentence *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Save(&this->super_CBaseToggle,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CScriptedSentence",this,m_SaveData,9);
  }
  return iVar2;
}


// scripted_sentence  @ 000e36d0  (line 970)

void scripted_sentence(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x538,pev);
  *puVar1 = &PTR__CScriptedSentence_00159b60;
  puVar1[1] = pev;
  return;
}


// CScriptedSentence::KeyValue  @ 000e0f40  (line 973)

/* DWARF original prototype: void KeyValue(CScriptedSentence * this, KeyValueData * pkvd) */

void __thiscall CScriptedSentence::KeyValue(CScriptedSentence *this,KeyValueData *pkvd)

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
  iVar3 = 9;
  pcVar5 = pkvd->szKeyName;
  pcVar4 = pcVar5;
  pcVar6 = "sentence";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar4 == *pcVar6;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    iVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    this->m_iszSentence = iVar3;
    pkvd->fHandled = 1;
  }
  else {
    iVar3 = 7;
    bVar7 = false;
    pcVar4 = pcVar5;
    pcVar6 = "entity";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      iVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
      this->m_iszEntity = iVar3;
      pkvd->fHandled = 1;
    }
    else {
      iVar3 = 9;
      bVar7 = false;
      pcVar4 = pcVar5;
      pcVar6 = "duration";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar4 == *pcVar6;
        pcVar4 = pcVar4 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar7);
      if (bVar7) {
        dVar8 = strtod(pkvd->szValue,(char **)0x0);
        this->m_flDuration = (float)dVar8;
        pkvd->fHandled = 1;
      }
      else {
        iVar3 = 7;
        bVar7 = false;
        pcVar4 = pcVar5;
        pcVar6 = "radius";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar7 = *pcVar4 == *pcVar6;
          pcVar4 = pcVar4 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar7);
        if (bVar7) {
          dVar8 = strtod(pkvd->szValue,(char **)0x0);
          this->m_flRadius = (float)dVar8;
          pkvd->fHandled = 1;
        }
        else {
          iVar3 = 7;
          bVar7 = false;
          pcVar4 = pcVar5;
          pcVar6 = "refire";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar7 = *pcVar4 == *pcVar6;
            pcVar4 = pcVar4 + 1;
            pcVar6 = pcVar6 + 1;
          } while (bVar7);
          if (bVar7) {
            dVar8 = strtod(pkvd->szValue,(char **)0x0);
            this->m_flRepeat = (float)dVar8;
            pkvd->fHandled = 1;
          }
          else {
            iVar3 = 0xc;
            bVar7 = false;
            pcVar4 = pcVar5;
            pcVar6 = "attenuation";
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar7 = *pcVar4 == *pcVar6;
              pcVar4 = pcVar4 + 1;
              pcVar6 = pcVar6 + 1;
            } while (bVar7);
            if (bVar7) {
              peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev;
              lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
              peVar1->impulse = lVar2;
              pkvd->fHandled = 1;
            }
            else {
              iVar3 = 7;
              bVar7 = false;
              pcVar4 = pcVar5;
              pcVar6 = "volume";
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar7 = *pcVar4 == *pcVar6;
                pcVar4 = pcVar4 + 1;
                pcVar6 = pcVar6 + 1;
              } while (bVar7);
              if (bVar7) {
                dVar8 = strtod(pkvd->szValue,(char **)0x0);
                this->m_flVolume = (float)((longdouble)dVar8 * (longdouble)0.1);
                pkvd->fHandled = 1;
              }
              else {
                iVar3 = 9;
                bVar7 = false;
                pcVar4 = "listener";
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
                iVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                this->m_iszListener = iVar3;
                pkvd->fHandled = 1;
              }
            }
          }
        }
      }
    }
  }
  return;
}


// CScriptedSentence::Use  @ 000e1410  (line 1020)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Use(CScriptedSentence * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CScriptedSentence::Use
          (CScriptedSentence *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  _2globalvars_t *p1Var1;
  
  p1Var1 = gpGlobals;
  if (this->m_active != 0) {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = FindThink;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    nextthink = p1Var1->time;
  }
  return;
}


// CScriptedSentence::Spawn  @ 000e0b20  (line 1030)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CScriptedSentence * this) */

void __thiscall CScriptedSentence::Spawn(CScriptedSentence *this)

{
  int iVar1;
  float fVar2;
  _2globalvars_t *p1Var3;
  entvars_t *peVar4;
  
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 0
  ;
  this->m_active = 1;
  p1Var3 = gpGlobals;
  peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar4->targetname == 0) {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = FindThink;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
    peVar4->nextthink = p1Var3->time + 1.0;
    peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  iVar1 = peVar4->impulse;
  if (iVar1 == 2) {
    this->m_flAttenuation = 0.8;
  }
  else if (iVar1 == 3) {
    this->m_flAttenuation = 0.0;
  }
  else {
    fVar2 = 1.25;
    if (iVar1 != 1) {
      fVar2 = 2.0;
    }
    this->m_flAttenuation = fVar2;
  }
  peVar4->impulse = 0;
  if (0.0 < this->m_flVolume) {
    return;
  }
  this->m_flVolume = 1.0;
  return;
}


// CScriptedSentence::FindThink  @ 000e39a0  (line 1069)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void FindThink(CScriptedSentence * this) */

void __thiscall CScriptedSentence::FindThink(CScriptedSentence *this)

{
  float flRadius;
  uint uVar1;
  int iVar2;
  _2globalvars_t *p1Var3;
  CBaseMonster *pCVar4;
  CBaseEntity *pCVar5;
  entvars_t *peVar6;
  byte *szWhatever;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  byte bVar12;
  
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
  bVar12 = 0;
  pCVar4 = FindEntity(this);
  if (pCVar4 == (CBaseMonster *)0x0) {
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    nextthink = gpGlobals->time + this->m_flRepeat + 0.5;
  }
  else {
                    /* Unresolved local var: BOOL bConcurrent@[???]
                       Unresolved local var: CBaseEntity * pListener@[???] */
    uVar1 = this->m_iszListener;
    iVar2 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
            ->spawnflags;
    pCVar5 = (CBaseEntity *)0x0;
    if (uVar1 != 0) {
                    /* Unresolved local var: float radius@[???] */
      flRadius = this->m_flRadius;
      bVar10 = CARRY4(uVar1,(uint)gpGlobals->pStringBase);
      szWhatever = (byte *)(gpGlobals->pStringBase + uVar1);
      bVar11 = szWhatever == (byte *)0x0;
      iVar7 = 7;
      pbVar8 = szWhatever;
      pbVar9 = (byte *)"player";
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar10 = *pbVar8 < *pbVar9;
        bVar11 = *pbVar8 == *pbVar9;
        pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
        pbVar9 = pbVar9 + (uint)bVar12 * -2 + 1;
      } while (bVar11);
      if ((!bVar10 && !bVar11) == bVar10) {
        flRadius = 4096.0;
      }
      pCVar5 = UTIL_FindEntityGeneric
                         ((char *)szWhatever,
                          &((pCVar4->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity.pev)->origin,flRadius);
    }
    (*(pCVar4->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x62])
              (pCVar4,gpGlobals->pStringBase + this->m_iszSentence,this->m_flDuration,
               this->m_flVolume,this->m_flAttenuation,(uint)((iVar2 & 8) == 0),pCVar5);
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"Playing sentence %s (%.1f)\n",
               gpGlobals->pStringBase + this->m_iszSentence,(double)this->m_flDuration);
    CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)0x0,USE_TOGGLE,0.0);
    peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if ((peVar6->spawnflags & 1) != 0) {
      UTIL_Remove((CBaseEntity *)this);
      peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
    }
    p1Var3 = gpGlobals;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = DelayThink;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
    peVar6->nextthink = p1Var3->time + this->m_flDuration + this->m_flRepeat;
    this->m_active = 0;
  }
  return;
}


// CScriptedSentence::DelayThink  @ 000e0be0  (line 1090)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DelayThink(CScriptedSentence * this) */

void __thiscall CScriptedSentence::DelayThink(CScriptedSentence *this)

{
  entvars_t *peVar1;
  
  this->m_active = 1;
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar1->targetname == 0) {
    peVar1->nextthink = gpGlobals->time + 0.1;
  }
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = FindThink;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  return;
}


// CScriptedSentence::AcceptableSpeaker  @ 000e3740  (line 1099)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL AcceptableSpeaker(CScriptedSentence * this, CBaseMonster *
   pMonster) */

BOOL __thiscall CScriptedSentence::AcceptableSpeaker(CScriptedSentence *this,CBaseMonster *pMonster)

{
  _func_int_varargs **pp_Var1;
  _func_int_varargs *p_Var2;
  uint uVar3;
  int iVar4;
  CBaseEntity *pCVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  byte bVar9;
  
  bVar9 = 0;
  if (pMonster != (CBaseMonster *)0x0) {
                    /* Unresolved local var: BOOL override@[???] */
    uVar3 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
            ->spawnflags;
    if ((uVar3 & 2) == 0) {
LAB_000e376c:
      pp_Var1 = (pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity._vptr_CBaseEntity;
      p_Var2 = pp_Var1[0x60];
      if (p_Var2 == CBaseMonster::CanPlaySentence) {
        p_Var2 = pp_Var1[0x22];
        if (p_Var2 == CBaseMonster::IsAlive) {
          uVar3 = (uint)(((pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                          super_CBaseEntity.pev)->deadflag != 2);
        }
        else {
          uVar3 = (*p_Var2)(pMonster);
        }
      }
      else {
        uVar3 = (*p_Var2)(pMonster,uVar3 >> 2 & 1);
      }
      return (uint)(uVar3 != 0);
    }
    iVar4 = EHANDLE::operator_int(&pMonster->m_hTargetEnt);
    if (iVar4 != 0) {
      pCVar5 = EHANDLE::operator->(&pMonster->m_hTargetEnt);
      iVar4 = 7;
      bVar8 = gpGlobals->pStringBase + pCVar5->pev->classname == (char *)0x0;
      pcVar6 = gpGlobals->pStringBase + pCVar5->pev->classname;
      pcVar7 = "player";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar8 = *pcVar6 == *pcVar7;
        pcVar6 = pcVar6 + (uint)bVar9 * -2 + 1;
        pcVar7 = pcVar7 + (uint)bVar9 * -2 + 1;
      } while (bVar8);
      if (bVar8) {
        uVar3 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev)->spawnflags;
        goto LAB_000e376c;
      }
    }
  }
  return 0;
}


// CScriptedSentence::FindEntity  @ 000e3850  (line 1120)

/* DWARF original prototype: CBaseMonster * FindEntity(CScriptedSentence * this) */

CBaseMonster * __thiscall CScriptedSentence::FindEntity(CScriptedSentence *this)

{
  entvars_t *peVar1;
  int *piVar2;
  edict_t *peVar3;
  int iVar4;
  CBaseMonster *pCVar5;
  BOOL BVar6;
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: edict_t * pentTarget@[???]
                       Unresolved local var: CBaseMonster * pMonster@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???] */
  peVar3 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_iszEntity);
  while( true ) {
    if ((peVar3 == (edict_t *)0x0) ||
       (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3), iVar4 == 0)) {
      pStartEntity = (CBaseEntity *)0x0;
      do {
        do {
          pStartEntity = UTIL_FindEntityInSphere
                                   (pStartEntity,
                                    &((this->super_CBaseToggle).super_CBaseAnimating.
                                      super_CBaseDelay.super_CBaseEntity.pev)->origin,
                                    this->m_flRadius);
          if (pStartEntity == (CBaseEntity *)0x0) {
            return (CBaseMonster *)0x0;
          }
          peVar1 = pStartEntity->pev;
          iVar4 = strcmp(gpGlobals->pStringBase + peVar1->classname,
                         gpGlobals->pStringBase + this->m_iszEntity);
        } while ((iVar4 != 0) || ((peVar1->flags & 0x20) == 0));
        pCVar5 = (CBaseMonster *)(*pStartEntity->_vptr_CBaseEntity[0x13])(pStartEntity);
        BVar6 = AcceptableSpeaker(this,pCVar5);
      } while (BVar6 == 0);
      return pCVar5;
    }
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    piVar2 = peVar3->pvPrivateData;
    if ((piVar2 != (int *)0x0) &&
       ((pCVar5 = (CBaseMonster *)(**(code **)(*piVar2 + 0x4c))(piVar2),
        pCVar5 != (CBaseMonster *)0x0 && (BVar6 = AcceptableSpeaker(this,pCVar5), BVar6 != 0))))
    break;
    peVar3 = (*g_engfuncs.pfnFindEntityByString)
                       (peVar3,"targetname",gpGlobals->pStringBase + this->m_iszEntity);
  }
  return pCVar5;
}


// CScriptedSentence::StartSentence  @ 000e3b70  (line 1159)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL StartSentence(CScriptedSentence * this, CBaseMonster * pTarget) */

BOOL __thiscall CScriptedSentence::StartSentence(CScriptedSentence *this,CBaseMonster *pTarget)

{
  float flRadius;
  uint uVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  BOOL BVar4;
  byte *szWhatever;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  
                    /* Unresolved local var: BOOL bConcurrent@[???]
                       Unresolved local var: CBaseEntity * pListener@[???] */
  if (pTarget == (CBaseMonster *)0x0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"Not Playing sentence %s\n",gpGlobals->pStringBase + this->m_iszSentence
              );
    BVar4 = 0;
  }
  else {
    uVar1 = this->m_iszListener;
    iVar2 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
            ->spawnflags;
    pCVar3 = (CBaseEntity *)0x0;
    if (uVar1 != 0) {
                    /* Unresolved local var: float radius@[???] */
      flRadius = this->m_flRadius;
      bVar8 = CARRY4(uVar1,(uint)gpGlobals->pStringBase);
      szWhatever = (byte *)(gpGlobals->pStringBase + uVar1);
      bVar9 = szWhatever == (byte *)0x0;
      iVar5 = 7;
      pbVar6 = szWhatever;
      pbVar7 = (byte *)"player";
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar8 = *pbVar6 < *pbVar7;
        bVar9 = *pbVar6 == *pbVar7;
        pbVar6 = pbVar6 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar9);
      if ((!bVar8 && !bVar9) == bVar8) {
        flRadius = 4096.0;
      }
      pCVar3 = UTIL_FindEntityGeneric
                         ((char *)szWhatever,
                          &((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                            super_CBaseEntity.pev)->origin,flRadius);
    }
    (*(pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x62])
              (pTarget,gpGlobals->pStringBase + this->m_iszSentence,this->m_flDuration,
               this->m_flVolume,this->m_flAttenuation,(uint)((iVar2 & 8) == 0),pCVar3);
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"Playing sentence %s (%.1f)\n",
               gpGlobals->pStringBase + this->m_iszSentence,(double)this->m_flDuration);
    CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)0x0,USE_TOGGLE,0.0);
    BVar4 = 1;
  }
  return BVar4;
}


// CFurniture::~CFurniture  @ 000e3e00  (line 1199)

/* DWARF original prototype: void ~CFurniture(CFurniture * this, int __in_chrg) */

void __thiscall CFurniture::~CFurniture(CFurniture *this,int __in_chrg)

{
  return;
}


// CFurniture::ObjectCaps  @ 000e3de0  (line 1205)

/* DWARF original prototype: int ObjectCaps(CFurniture * this) */

int __thiscall CFurniture::ObjectCaps(CFurniture *this)

{
  return 0;
}


// monster_furniture  @ 000e3d20  (line 1209)

void monster_furniture(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6bc,pev);
  *puVar1 = &PTR__CFurniture_00159c70;
  puVar1[1] = pev;
  return;
}


// CFurniture::Die  @ 000e3d90  (line 1216)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Die(CFurniture * this) */

void __thiscall CFurniture::Die(CFurniture *this)

{
  _2globalvars_t *p1Var1;
  
  p1Var1 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = p1Var1->time;
  return;
}


// CFurniture::Spawn  @ 000e0e30  (line 1226)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CFurniture * this) */

void __thiscall CFurniture::Spawn(CFurniture *this)

{
  entvars_t *peVar1;
  
  (*g_engfuncs.pfnPrecacheModel)
            (gpGlobals->pStringBase +
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->model);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar1->pContainingEntity,gpGlobals->pStringBase + peVar1->model);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 2;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->health = 80000.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 2.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->effects = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->yaw_speed = 0.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->sequence = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->frame = 0.0;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->frame = 0.0;
                    /* WARNING: Could not recover jumptable at 0x000e0f08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x48])();
  return;
}


// CFurniture::Classify  @ 000e0c30  (line 1253)

/* DWARF original prototype: int Classify(CFurniture * this) */

int __thiscall CFurniture::Classify(CFurniture *this)

{
  return 0;
}


