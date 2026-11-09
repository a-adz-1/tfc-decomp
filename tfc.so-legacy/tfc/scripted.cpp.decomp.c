// Ghidra decompilation of functions from tfc/scripted.cpp
// 51 functions, ordered by original source line

// CCineMonster::KeyValue  @ 001179d0  (line 54)

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


// CCineMonster::Restore  @ 00117770  (line 116)

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


// CCineMonster::Save  @ 00117830  (line 116)

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


// scripted_sequence  @ 001183b0  (line 118)

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
  *puVar1 = &PTR__CCineMonster_0018a648;
  puVar1[1] = pev;
  return;
}


// aiscripted_sequence  @ 00118420  (line 121)

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
  *puVar1 = &PTR__CCineAI_0018a888;
  puVar1[1] = pev;
  return;
}


// CCineMonster::Spawn  @ 00117160  (line 125)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CCineMonster * this) */

void __thiscall CCineMonster::Spawn(CCineMonster *this)

{
  globalvars_t *pgVar1;
  entvars_t *peVar2;
  
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 0;
  pgVar1 = gpGlobals;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar2->targetname == 0) || (this->m_iszIdle != 0)) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CineThink;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar2->nextthink = pgVar1->time + 1.0;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar2->targetname != 0) {
      this->m_startTime = pgVar1->time + 1e+06;
    }
  }
  this->m_interruptable = (uint)((peVar2->spawnflags & 0x20) == 0);
  return;
}


// CCineMonster::FCanOverrideState  @ 001171e0  (line 158)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL FCanOverrideState(CCineMonster * this) */

BOOL __thiscall CCineMonster::FCanOverrideState(CCineMonster *this)

{
  return (uint)((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->spawnflags & 0x40) != 0);
}


// CCineAI::FCanOverrideState  @ 00117200  (line 170)

/* DWARF original prototype: BOOL FCanOverrideState(CCineAI * this) */

BOOL __thiscall CCineAI::FCanOverrideState(CCineAI *this)

{
  return 1;
}


// CCineMonster::Use  @ 00117890  (line 177)

/* DWARF original prototype: void Use(CCineMonster * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CCineMonster::Use(CCineMonster *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
                 float value)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  CBaseEntity *pCVar3;
  int iVar4;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseMonster * pTarget@[???] */
  pCVar3 = EHANDLE::operator_CBaseEntity_(&(this->super_CBaseMonster).m_hTargetEnt);
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
  pgVar2 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CineThink;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar1->nextthink = pgVar2->time;
  return;
}


// CCineMonster::Blocked  @ 00117210  (line 206)

/* DWARF original prototype: void Blocked(CCineMonster * this, CBaseEntity * pOther) */

void __thiscall CCineMonster::Blocked(CCineMonster *this,CBaseEntity *pOther)

{
  return;
}


// CCineMonster::Touch  @ 00117220  (line 218)

/* DWARF original prototype: void Touch(CCineMonster * this, CBaseEntity * pOther) */

void __thiscall CCineMonster::Touch(CCineMonster *this,CBaseEntity *pOther)

{
  return;
}


// CCineMonster::Die  @ 00118490  (line 250)

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


// CCineMonster::Pain  @ 001184b0  (line 260)

/* DWARF original prototype: void Pain(CCineMonster * this) */

void __thiscall CCineMonster::Pain(CCineMonster *this)

{
  return;
}


// CCineMonster::FindEntity  @ 001184c0  (line 268)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int FindEntity(CCineMonster * this) */

int __thiscall CCineMonster::FindEntity(CCineMonster *this)

{
  EHANDLE *this_00;
  int *piVar1;
  _func_int_varargs *p_Var2;
  edict_t *peVar3;
  int iVar4;
  entvars_t *peVar5;
  CBaseEntity *pEntity;
  edict_t *peVar6;
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: edict_t * pentTarget@[???]
                       Unresolved local var: CBaseMonster * pTarget@[???] */
  peVar3 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_iszEntity);
  this_00 = &(this->super_CBaseMonster).m_hTargetEnt;
  EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  while ((peVar3 != (edict_t *)0x0 &&
         (iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3), iVar4 != 0))) {
    peVar5 = &peVar3->v;
    if (peVar3 == (edict_t *)0x0) {
      peVar5 = (entvars_t *)0x0;
    }
    if ((peVar5->flags & 0x20) != 0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      peVar6 = peVar3;
      if ((((peVar3 != (edict_t *)0x0) ||
           (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 != (edict_t *)0x0)) &&
          (piVar1 = peVar6->pvPrivateData, piVar1 != (int *)0x0)) &&
         (pEntity = (CBaseEntity *)(**(code **)(*piVar1 + 0x4c))(piVar1),
         pEntity != (CBaseEntity *)0x0)) {
        p_Var2 = pEntity->_vptr_CBaseEntity[0x5f];
        iVar4 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity._vptr_CBaseEntity[0x88])(this);
        iVar4 = (*p_Var2)(pEntity,iVar4,1);
        if (iVar4 != 0) goto LAB_00118592;
      }
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"Found %s, but can\'t play!\n",
                 gpGlobals->pStringBase + this->m_iszEntity);
    }
    peVar3 = (*g_engfuncs.pfnFindEntityByString)
                       (peVar3,"targetname",gpGlobals->pStringBase + this->m_iszEntity);
  }
  pStartEntity = (CBaseEntity *)0x0;
  do {
    do {
      pStartEntity = UTIL_FindEntityInSphere
                               (pStartEntity,
                                &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.pev)->origin,this->m_flRadius);
      if (pStartEntity == (CBaseEntity *)0x0) {
        EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
        return 0;
      }
      peVar5 = pStartEntity->pev;
      iVar4 = strcmp(gpGlobals->pStringBase + peVar5->classname,
                     gpGlobals->pStringBase + this->m_iszEntity);
    } while (((iVar4 != 0) || ((peVar5->flags & 0x20) == 0)) ||
            (pEntity = (CBaseEntity *)(*pStartEntity->_vptr_CBaseEntity[0x13])(pStartEntity),
            pEntity == (CBaseEntity *)0x0));
    p_Var2 = pEntity->_vptr_CBaseEntity[0x5f];
    iVar4 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0x88])(this);
    iVar4 = (*p_Var2)(pEntity,iVar4,0);
  } while (iVar4 == 0);
LAB_00118592:
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
  EHANDLE::operator=(this_00,pEntity);
  return 1;
}


// CCineMonster::PossessEntity  @ 00118190  (line 317)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PossessEntity(CCineMonster * this) */

void __thiscall CCineMonster::PossessEntity(CCineMonster *this)

{
  uint *puVar1;
  entvars_t *peVar2;
  CBaseEntity *pCVar3;
  int iVar4;
  int iVar5;
  CCineMonster *this_00;
  CCineMonster *state;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseMonster * pTarget@[???] */
  pCVar3 = EHANDLE::operator_CBaseEntity_(&(this->super_CBaseMonster).m_hTargetEnt);
  if (pCVar3 != (CBaseEntity *)0x0) {
    iVar4 = (*pCVar3->_vptr_CBaseEntity[0x13])(pCVar3);
    if (iVar4 != 0) {
      *(CCineMonster **)(iVar4 + 8) = this;
      *(CCineMonster **)(iVar4 + 0x6b4) = this;
      this_00 = (CCineMonster *)(iVar4 + 0x520);
      state = this;
      EHANDLE::operator=((EHANDLE *)this_00,(CBaseEntity *)this);
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
        DelayStart(this_00,(int)state);
      }
      else if (iVar5 < 2) {
        if (iVar5 == 0) {
          *(undefined4 *)(iVar4 + 0x6b0) = 1;
        }
      }
      else if (iVar5 == 2) {
        *(undefined4 *)(iVar4 + 0x6b0) = 4;
        DelayStart(this_00,(int)state);
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


// CCineAI::PossessEntity  @ 00117450  (line 390)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PossessEntity(CCineAI * this) */

void __thiscall CCineAI::PossessEntity(CCineAI *this)

{
  int *piVar1;
  _func_int_varargs *p_Var2;
  entvars_t *peVar3;
  CBaseEntity *pCVar4;
  CBaseMonster *this_00;
  undefined4 uVar5;
  int iVar6;
  globalvars_t *pgVar7;
  Schedule_t *pNewSchedule;
  
                    /* Unresolved local var: Schedule_t * pNewSchedule@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseMonster * pTarget@[???] */
  pCVar4 = EHANDLE::operator_CBaseEntity_
                     (&(this->super_CCineMonster).super_CBaseMonster.m_hTargetEnt);
  if ((pCVar4 != (CBaseEntity *)0x0) &&
     (this_00 = (CBaseMonster *)(*pCVar4->_vptr_CBaseEntity[0x13])(pCVar4),
     this_00 != (CBaseMonster *)0x0)) {
    p_Var2 = (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             _vptr_CBaseEntity[0x5f];
    uVar5 = (**(code **)((int)(this->super_CCineMonster).super_CBaseMonster.super_CBaseToggle.
                              super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                              _vptr_CBaseEntity + 0x220))(this);
    iVar6 = (*p_Var2)(this_00,uVar5,2);
    if (iVar6 == 0) {
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
    peVar3 = (this->super_CCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
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
    *piVar1 = *piVar1 | peVar3->effects;
    pgVar7 = gpGlobals;
    switch((this->super_CCineMonster).m_fMoveTo) {
    case 0:
    case 5:
      this_00->m_scriptState = SCRIPT_WAIT;
      break;
    case 1:
      this_00->m_scriptState = SCRIPT_WALK_TO_MARK;
      pgVar7 = gpGlobals;
      break;
    case 2:
      this_00->m_scriptState = SCRIPT_RUN_TO_MARK;
      pgVar7 = gpGlobals;
      break;
    default:
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"aiscript:  invalid Move To Position value!");
      pgVar7 = gpGlobals;
      break;
    case 4:
      UTIL_SetOrigin((this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev,
                     &((this->super_CCineMonster).super_CBaseMonster.super_CBaseToggle.
                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->origin);
      ((this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      ideal_yaw = (((this->super_CCineMonster).super_CBaseMonster.super_CBaseToggle.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles).y;
      peVar3 = (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev;
      (peVar3->avelocity).x = 0.0;
      (peVar3->avelocity).y = 0.0;
      (peVar3->avelocity).z = 0.0;
      peVar3 = (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev;
      (peVar3->velocity).x = 0.0;
      (peVar3->velocity).y = 0.0;
      (peVar3->velocity).z = 0.0;
      piVar1 = &((this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 | 0x20;
      (((this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      angles).y = (((this->super_CCineMonster).super_CBaseMonster.super_CBaseToggle.
                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->angles).y;
      this_00->m_scriptState = SCRIPT_WAIT;
      pgVar7 = gpGlobals;
      (this->super_CCineMonster).m_startTime = gpGlobals->time + 1e+06;
      piVar1 = &((this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->flags;
      *piVar1 = *piVar1 & 0xfffffdff;
    }
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"\"%s\" found and used\n",
               pgVar7->pStringBase +
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


// CCineMonster::CineThink  @ 00119170  (line 472)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CineThink(CCineMonster * this) */

void __thiscall CCineMonster::CineThink(CCineMonster *this)

{
  edict_t *pentCine;
  int iVar1;
  char *pcVar2;
  entvars_t *peVar3;
  byte *pbVar4;
  string_t sVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  byte bVar9;
  CCineMonster *this_00;
  
  bVar9 = 0;
  iVar1 = FindEntity(this);
  if (iVar1 == 0) {
                    /* Unresolved local var: edict_t * pentCineTarget@[???] */
    this_00 = (CCineMonster *)0x2;
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"Cancelling script: %s\n",gpGlobals->pStringBase + this->m_iszPlay);
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (peVar3->targetname == 0) {
      pentCine = peVar3->pContainingEntity;
      iVar1 = 0x12;
      pcVar2 = gpGlobals->pStringBase;
      peVar3 = (entvars_t *)0x0;
      if (pentCine != (edict_t *)0x0) {
        peVar3 = &pentCine->v;
      }
      bVar7 = CARRY4(peVar3->classname,(uint)pcVar2);
      bVar8 = (byte *)(pcVar2 + peVar3->classname) == (byte *)0x0;
      pbVar4 = (byte *)(pcVar2 + peVar3->classname);
      pbVar6 = (byte *)"scripted_sequence";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar7 = *pbVar4 < *pbVar6;
        bVar8 = *pbVar4 == *pbVar6;
        pbVar4 = pbVar4 + (uint)bVar9 * -2 + 1;
        pbVar6 = pbVar6 + (uint)bVar9 * -2 + 1;
      } while (bVar8);
      sVar5 = 0;
      if ((!bVar7 && !bVar8) == bVar7) {
        ScriptEntityCancel(pentCine);
        pcVar2 = gpGlobals->pStringBase;
        sVar5 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->targetname;
      }
    }
    else {
      CancelScript(this_00);
      pcVar2 = gpGlobals->pStringBase;
      sVar5 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->targetname;
    }
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"script \"%s\" can\'t find monster \"%s\"\n",pcVar2 + sVar5,
               pcVar2 + this->m_iszEntity);
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->nextthink = gpGlobals->time + 1.0;
  }
  else {
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x86])(this);
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"script \"%s\" using monster \"%s\"\n",
               gpGlobals->pStringBase +
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->targetname,gpGlobals->pStringBase + this->m_iszEntity);
  }
  return;
}


// CCineMonster::StartSequence  @ 001192f0  (line 489)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL StartSequence(CCineMonster * this, CBaseMonster * pTarget, int
   iszSeq, BOOL completeOnEmpty) */

BOOL __thiscall
CCineMonster::StartSequence
          (CCineMonster *this,CBaseMonster *pTarget,int iszSeq,BOOL completeOnEmpty)

{
  globalvars_t *pgVar1;
  int iVar2;
  entvars_t *peVar3;
  
  pgVar1 = gpGlobals;
  if ((completeOnEmpty != 0) && (iszSeq == 0)) {
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((peVar3->spawnflags & 4) == 0) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_pfnThink.__delta = 0;
      peVar3->nextthink = pgVar1->time + 0.1;
    }
    CBaseMonster::CineCleanup(pTarget);
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x89])(this,pTarget);
    CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)0x0,USE_TOGGLE,0.0);
    return 0;
  }
  peVar3 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  iVar2 = CBaseAnimating::LookupSequence((CBaseAnimating *)pTarget,gpGlobals->pStringBase + iszSeq);
  peVar3->sequence = iVar2;
  peVar3 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar3->sequence == -1) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"%s: unknown scripted sequence \"%s\"\n",
               gpGlobals->pStringBase + peVar3->targetname,gpGlobals->pStringBase + iszSeq);
    ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    sequence = 0;
    peVar3 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             pev;
  }
  peVar3->frame = 0.0;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)pTarget);
  return 1;
}


// CCineAI::StartSequence  @ 00119440  (line 523)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL StartSequence(CCineAI * this, CBaseMonster * pTarget, int iszSeq,
   BOOL completeOnEmpty) */

BOOL __thiscall
CCineAI::StartSequence(CCineAI *this,CBaseMonster *pTarget,int iszSeq,BOOL completeOnEmpty)

{
  globalvars_t *pgVar1;
  int iVar2;
  entvars_t *peVar3;
  
  pgVar1 = gpGlobals;
  if ((completeOnEmpty == 0) || (iszSeq != 0)) {
    peVar3 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             pev;
    iVar2 = CBaseAnimating::LookupSequence
                      ((CBaseAnimating *)pTarget,gpGlobals->pStringBase + iszSeq);
    peVar3->sequence = iVar2;
    peVar3 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
             pev;
    if (peVar3->sequence == -1) {
      (*g_engfuncs.pfnAlertMessage)
                (at_error,"%s: unknown aiscripted sequence \"%s\"\n",
                 gpGlobals->pStringBase + peVar3->targetname,gpGlobals->pStringBase + iszSeq);
      ((pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      sequence = 0;
      peVar3 = (pTarget->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev;
    }
    peVar3->frame = 0.0;
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)pTarget);
  }
  else {
    peVar3 = (this->super_CCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    if ((peVar3->spawnflags & 4) == 0) {
      (this->super_CCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
      (this->super_CCineMonster).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
      peVar3->nextthink = pgVar1->time + 0.1;
    }
    CBaseMonster::CineCleanup(pTarget);
    (**(code **)((int)(this->super_CCineMonster).super_CBaseMonster.super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity +
                0x224))(this,pTarget);
    CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)0x0,USE_TOGGLE,0.0);
  }
  return 1;
}


// CCineMonster::SequenceDone  @ 00118cd0  (line 557)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SequenceDone(CCineMonster * this, CBaseMonster * pMonster) */

void __thiscall CCineMonster::SequenceDone(CCineMonster *this,CBaseMonster *pMonster)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  
  pgVar2 = gpGlobals;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar1->spawnflags & 4) == 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar1->nextthink = pgVar2->time + 0.1;
  }
  CBaseMonster::CineCleanup(pMonster);
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x89])(this,pMonster);
  CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)0x0,USE_TOGGLE,0.0);
  return;
}


// CCineMonster::FixScriptMonsterSchedule  @ 00117420  (line 586)

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


// CCineAI::FixScriptMonsterSchedule  @ 00117910  (line 606)

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


// CBaseMonster::ExitScriptedSequence  @ 001190a0  (line 623)

/* DWARF original prototype: BOOL ExitScriptedSequence(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::ExitScriptedSequence(CBaseMonster *this)

{
  CCineMonster *pCVar1;
  edict_t *pentCine;
  int iVar2;
  entvars_t *peVar3;
  BOOL BVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  byte bVar8;
  CCineMonster *this_00;
  
  bVar8 = 0;
  if (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      deadflag == 1) {
    BVar4 = 0;
    this->m_IdealMonsterState = MONSTERSTATE_DEAD;
  }
  else {
    pCVar1 = this->m_pCine;
    BVar4 = 1;
    if (pCVar1 != (CCineMonster *)0x0) {
                    /* Unresolved local var: edict_t * pentCineTarget@[???] */
      this_00 = (CCineMonster *)0x2;
      (*g_engfuncs.pfnAlertMessage)
                (at_aiconsole,"Cancelling script: %s\n",gpGlobals->pStringBase + pCVar1->m_iszPlay);
      peVar3 = (pCVar1->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      if (peVar3->targetname == 0) {
        pentCine = peVar3->pContainingEntity;
        peVar3 = (entvars_t *)0x0;
        if (pentCine != (edict_t *)0x0) {
          peVar3 = &pentCine->v;
        }
        bVar7 = gpGlobals->pStringBase + peVar3->classname == (char *)0x0;
        iVar2 = 0x12;
        pcVar5 = gpGlobals->pStringBase + peVar3->classname;
        pcVar6 = "scripted_sequence";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar7 = *pcVar5 == *pcVar6;
          pcVar5 = pcVar5 + (uint)bVar8 * -2 + 1;
          pcVar6 = pcVar6 + (uint)bVar8 * -2 + 1;
        } while (bVar7);
        if (bVar7) {
          ScriptEntityCancel(pentCine);
        }
      }
      else {
        CCineMonster::CancelScript(this_00);
      }
    }
  }
  return BVar4;
}


// CCineMonster::AllowInterrupt  @ 001186f0  (line 642)

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


// CCineMonster::CanInterrupt  @ 00118710  (line 650)

/* DWARF original prototype: BOOL CanInterrupt(CCineMonster * this) */

BOOL __thiscall CCineMonster::CanInterrupt(CCineMonster *this)

{
  CBaseEntity *pCVar1;
  
                    /* Unresolved local var: CBaseEntity * pTarget@[???] */
  if (this->m_interruptable != 0) {
    pCVar1 = EHANDLE::operator_CBaseEntity_(&(this->super_CBaseMonster).m_hTargetEnt);
    if (pCVar1 != (CBaseEntity *)0x0) {
      return (uint)(pCVar1->pev->deadflag == 0);
    }
  }
  return 0;
}


// CCineMonster::IgnoreConditions  @ 00117980  (line 664)

/* DWARF original prototype: int IgnoreConditions(CCineMonster * this) */

int __thiscall CCineMonster::IgnoreConditions(CCineMonster *this)

{
  CBaseEntity *pCVar1;
  
                    /* Unresolved local var: CBaseEntity * pTarget@[???] */
  if (this->m_interruptable != 0) {
    pCVar1 = EHANDLE::operator_CBaseEntity_(&(this->super_CBaseMonster).m_hTargetEnt);
    if (pCVar1 != (CBaseEntity *)0x0) {
      return ~-(uint)(pCVar1->pev->deadflag == 0) & 0x300;
    }
  }
  return 0x300;
}


// ScriptEntityCancel  @ 00118d60  (line 671)

void __regparm3 ScriptEntityCancel(edict_t *pentCine)

{
  CBaseEntity *pCVar1;
  CBaseMonster *this;
  undefined4 *puVar2;
  edict_t *peVar3;
  entvars_t *pev;
  
                    /* Unresolved local var: CCineMonster * pCineTarget@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseMonster * pTarget@[???] */
  if (pentCine == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnCreateEntity)();
    pev = (entvars_t *)0x0;
    if (peVar3 != (edict_t *)0x0) {
      pev = &peVar3->v;
    }
  }
  else {
    pev = &pentCine->v;
  }
                    /* Unresolved local var: entvars_t * pev@[???] */
  if ((pev->pContainingEntity == (edict_t *)0x0) ||
     (puVar2 = pev->pContainingEntity->pvPrivateData, puVar2 == (undefined4 *)0x0)) {
    puVar2 = CBaseEntity::operator_new(0x6f0,pev);
    *puVar2 = &PTR__CCineMonster_0018a648;
    puVar2[1] = pev;
  }
  pCVar1 = EHANDLE::operator_CBaseEntity_((EHANDLE *)(puVar2 + 0x148));
  if (((pCVar1 != (CBaseEntity *)0x0) &&
      (this = (CBaseMonster *)(*pCVar1->_vptr_CBaseEntity[0x13])(pCVar1),
      this != (CBaseMonster *)0x0)) && (this->m_MonsterState == MONSTERSTATE_SCRIPT)) {
    this->m_scriptState = SCRIPT_CLEANUP;
    CBaseMonster::CineCleanup(this);
    return;
  }
  return;
}


// ScriptEntityCancel  @ 00118e10  (line 672)

void ScriptEntityCancel(edict_t *pentCine)

{
  int iVar1;
  entvars_t *peVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  peVar2 = (entvars_t *)0x0;
  if (pentCine != (edict_t *)0x0) {
    peVar2 = &pentCine->v;
  }
  bVar5 = gpGlobals->pStringBase + peVar2->classname == (char *)0x0;
  iVar1 = 0x12;
  pcVar3 = gpGlobals->pStringBase + peVar2->classname;
  pcVar4 = "scripted_sequence";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    ScriptEntityCancel(pentCine);
    return;
  }
  return;
}


// CCineMonster::CancelScript  @ 00118e70  (line 699)

/* DWARF original prototype: void CancelScript(CCineMonster * this) */

void __thiscall CCineMonster::CancelScript(CCineMonster *this)

{
  int in_EAX;
  edict_t *peVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  CBaseMonster *this_00;
  char *pcVar4;
  undefined4 *puVar5;
  edict_t *peVar6;
  entvars_t *peVar7;
  char *pcVar8;
  entvars_t *pev;
  char *pcVar9;
  bool bVar10;
  byte bVar11;
  
  bVar11 = 0;
                    /* Unresolved local var: edict_t * pentCineTarget@[???] */
  peVar1 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",
                      gpGlobals->pStringBase + *(int *)(*(int *)(in_EAX + 4) + 0x1cc));
  if (peVar1 != (edict_t *)0x0) {
    while (iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1), iVar2 != 0) {
      pev = &peVar1->v;
      peVar7 = (entvars_t *)0x0;
      if (peVar1 != (edict_t *)0x0) {
        peVar7 = pev;
      }
      iVar2 = 0x12;
      pcVar4 = gpGlobals->pStringBase;
      bVar10 = pcVar4 + peVar7->classname == (char *)0x0;
      pcVar8 = pcVar4 + peVar7->classname;
      pcVar9 = "scripted_sequence";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar10 = *pcVar8 == *pcVar9;
        pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
        pcVar9 = pcVar9 + (uint)bVar11 * -2 + 1;
      } while (bVar10);
      if (bVar10) {
                    /* Unresolved local var: CCineMonster * pCineTarget@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseMonster * pTarget@[???] */
        if (peVar1 == (edict_t *)0x0) {
          peVar6 = (*g_engfuncs.pfnCreateEntity)();
          pev = &peVar6->v;
          if (peVar6 == (edict_t *)0x0) {
            pev = (entvars_t *)0x0;
          }
        }
                    /* Unresolved local var: entvars_t * pev@[???] */
        if ((pev->pContainingEntity == (edict_t *)0x0) ||
           (puVar5 = pev->pContainingEntity->pvPrivateData, puVar5 == (undefined4 *)0x0)) {
          puVar5 = CBaseEntity::operator_new(0x6f0,pev);
          *puVar5 = &PTR__CCineMonster_0018a648;
          puVar5[1] = pev;
        }
        pCVar3 = EHANDLE::operator_CBaseEntity_((EHANDLE *)(puVar5 + 0x148));
        if (((pCVar3 != (CBaseEntity *)0x0) &&
            (this_00 = (CBaseMonster *)(*pCVar3->_vptr_CBaseEntity[0x13])(pCVar3),
            this_00 != (CBaseMonster *)0x0)) && (this_00->m_MonsterState == MONSTERSTATE_SCRIPT)) {
          this_00->m_scriptState = SCRIPT_CLEANUP;
          CBaseMonster::CineCleanup(this_00);
        }
        pcVar4 = gpGlobals->pStringBase;
      }
      peVar1 = (*g_engfuncs.pfnFindEntityByString)
                         (peVar1,"targetname",pcVar4 + *(int *)(*(int *)(in_EAX + 4) + 0x1cc));
      if (peVar1 == (edict_t *)0x0) {
        return;
      }
    }
  }
  return;
}


// CCineMonster::CancelScript  @ 00118fe0  (line 700)

/* DWARF original prototype: void CancelScript(CCineMonster * this) */

void __thiscall CCineMonster::CancelScript(CCineMonster *this)

{
  edict_t *pentCine;
  int iVar1;
  entvars_t *peVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  byte bVar6;
  
  bVar6 = 0;
                    /* Unresolved local var: edict_t * pentCineTarget@[???] */
  (*g_engfuncs.pfnAlertMessage)
            (at_aiconsole,"Cancelling script: %s\n",gpGlobals->pStringBase + this->m_iszPlay);
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar2->targetname != 0) {
    CancelScript(this);
    return;
  }
  pentCine = peVar2->pContainingEntity;
  peVar2 = (entvars_t *)0x0;
  if (pentCine != (edict_t *)0x0) {
    peVar2 = &pentCine->v;
  }
  iVar1 = 0x12;
  bVar5 = gpGlobals->pStringBase + peVar2->classname == (char *)0x0;
  pcVar3 = gpGlobals->pStringBase + peVar2->classname;
  pcVar4 = "scripted_sequence";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + (uint)bVar6 * -2 + 1;
    pcVar4 = pcVar4 + (uint)bVar6 * -2 + 1;
  } while (bVar5);
  if (bVar5) {
    ScriptEntityCancel(pentCine);
    return;
  }
  return;
}


// CCineMonster::DelayStart  @ 00118060  (line 720)

/* DWARF original prototype: void DelayStart(CCineMonster * this, int state) */

void __thiscall CCineMonster::DelayStart(CCineMonster *this,int state)

{
  int in_EAX;
  edict_t *peVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
  edict_t *peVar5;
  entvars_t *peVar6;
  char *pcVar7;
  entvars_t *pev;
  char *pcVar8;
  bool bVar9;
  byte bVar10;
  
  bVar10 = 0;
                    /* Unresolved local var: edict_t * pentCine@[???] */
  peVar1 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",
                      gpGlobals->pStringBase + *(int *)(*(int *)(in_EAX + 4) + 0x1cc));
  if (peVar1 != (edict_t *)0x0) {
    while (iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar1), iVar2 != 0) {
      pev = &peVar1->v;
      peVar6 = (entvars_t *)0x0;
      if (peVar1 != (edict_t *)0x0) {
        peVar6 = pev;
      }
      iVar2 = 0x12;
      pcVar3 = gpGlobals->pStringBase;
      bVar9 = pcVar3 + peVar6->classname == (char *)0x0;
      pcVar7 = pcVar3 + peVar6->classname;
      pcVar8 = "scripted_sequence";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar9 = *pcVar7 == *pcVar8;
        pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
        pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
      } while (bVar9);
      if (bVar9) {
                    /* Unresolved local var: CCineMonster * pTarget@[DW_OP_reg0(EAX)] */
        if (peVar1 == (edict_t *)0x0) {
          peVar5 = (*g_engfuncs.pfnCreateEntity)();
          pev = &peVar5->v;
          if (peVar5 == (edict_t *)0x0) {
            pev = (entvars_t *)0x0;
          }
        }
                    /* Unresolved local var: entvars_t * pev@[???] */
        if ((pev->pContainingEntity == (edict_t *)0x0) ||
           (puVar4 = pev->pContainingEntity->pvPrivateData, puVar4 == (undefined4 *)0x0)) {
          puVar4 = CBaseEntity::operator_new(0x6f0,pev);
          *puVar4 = &PTR__CCineMonster_0018a648;
          puVar4[1] = pev;
        }
        puVar4[0x1b6] = puVar4[0x1b6] + 1;
        pcVar3 = gpGlobals->pStringBase;
      }
      peVar1 = (*g_engfuncs.pfnFindEntityByString)
                         (peVar1,"targetname",pcVar3 + *(int *)(*(int *)(in_EAX + 4) + 0x1cc));
      if (peVar1 == (edict_t *)0x0) {
        return;
      }
    }
  }
  return;
}


// CCineMonster::DelayStart  @ 00118760  (line 721)

/* DWARF original prototype: void DelayStart(CCineMonster * this, int state) */

void __thiscall CCineMonster::DelayStart(CCineMonster *this,int state)

{
  globalvars_t *pgVar1;
  edict_t *peVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  edict_t *peVar6;
  entvars_t *peVar7;
  char *pcVar8;
  entvars_t *pev;
  char *pcVar9;
  bool bVar10;
  byte bVar11;
  
  bVar11 = 0;
                    /* Unresolved local var: edict_t * pentCine@[???] */
  peVar2 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",
                      gpGlobals->pStringBase +
                      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->targetname);
  if (peVar2 != (edict_t *)0x0) {
    while (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2), iVar3 != 0) {
      pev = &peVar2->v;
      peVar7 = (entvars_t *)0x0;
      if (peVar2 != (edict_t *)0x0) {
        peVar7 = pev;
      }
      iVar3 = 0x12;
      pcVar4 = gpGlobals->pStringBase;
      bVar10 = pcVar4 + peVar7->classname == (char *)0x0;
      pcVar8 = pcVar4 + peVar7->classname;
      pcVar9 = "scripted_sequence";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar10 = *pcVar8 == *pcVar9;
        pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
        pcVar9 = pcVar9 + (uint)bVar11 * -2 + 1;
      } while (bVar10);
      if (bVar10) {
                    /* Unresolved local var: CCineMonster * pTarget@[DW_OP_reg0(EAX)] */
        if (peVar2 == (edict_t *)0x0) {
          peVar6 = (*g_engfuncs.pfnCreateEntity)();
          pev = &peVar6->v;
          if (peVar6 == (edict_t *)0x0) {
            pev = (entvars_t *)0x0;
          }
        }
                    /* Unresolved local var: entvars_t * pev@[???] */
        if ((pev->pContainingEntity == (edict_t *)0x0) ||
           (puVar5 = pev->pContainingEntity->pvPrivateData, puVar5 == (undefined4 *)0x0)) {
          puVar5 = CBaseEntity::operator_new(0x6f0,pev);
          *puVar5 = &PTR__CCineMonster_0018a648;
          puVar5[1] = pev;
        }
        if (state == 0) {
          iVar3 = puVar5[0x1b6];
          puVar5[0x1b6] = iVar3 + -1;
          pgVar1 = gpGlobals;
          if (iVar3 + -1 < 1) {
            puVar5[0x1b7] = gpGlobals->time + 0.05;
            pcVar4 = pgVar1->pStringBase;
          }
          else {
            pcVar4 = gpGlobals->pStringBase;
          }
        }
        else {
          puVar5[0x1b6] = puVar5[0x1b6] + 1;
          pcVar4 = gpGlobals->pStringBase;
        }
      }
      peVar2 = (*g_engfuncs.pfnFindEntityByString)
                         (peVar2,"targetname",
                          pcVar4 + ((this->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                   targetname);
      if (peVar2 == (edict_t *)0x0) {
        return;
      }
    }
  }
  return;
}


// CCineMonster::Activate  @ 00117de0  (line 748)

/* DWARF original prototype: void Activate(CCineMonster * this) */

void __thiscall CCineMonster::Activate(CCineMonster *this)

{
  int *piVar1;
  edict_t *peVar2;
  int iVar3;
  entvars_t *peVar4;
  void *pmodel;
  edict_t *peVar5;
  
                    /* Unresolved local var: edict_t * pentTarget@[???]
                       Unresolved local var: CBaseMonster * pTarget@[???] */
  peVar2 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_iszEntity);
joined_r0x00117e1e:
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
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
          peVar5 = peVar2;
          if (((peVar2 != (edict_t *)0x0) ||
              (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 != (edict_t *)0x0)) &&
             (piVar1 = peVar5->pvPrivateData, piVar1 != (int *)0x0)) break;
          peVar2 = (*g_engfuncs.pfnFindEntityByString)
                             (peVar2,"targetname",gpGlobals->pStringBase + this->m_iszEntity);
        }
        iVar3 = (**(code **)(*piVar1 + 0x4c))(piVar1);
        peVar2 = (*g_engfuncs.pfnFindEntityByString)
                           (peVar2,"targetname",gpGlobals->pStringBase + this->m_iszEntity);
      } while (iVar3 == 0);
LAB_00117f8f:
                    /* Unresolved local var: void * pmodel@[???] */
      pmodel = (*g_engfuncs.pfnGetModelPtr)(*(edict_t **)(*(int *)(iVar3 + 4) + 0x208));
      if (pmodel == (void *)0x0) {
        return;
      }
      SequencePrecache(pmodel,gpGlobals->pStringBase + this->m_iszIdle);
      SequencePrecache(pmodel,gpGlobals->pStringBase + this->m_iszPlay);
      return;
    }
    peVar4 = &peVar2->v;
    if (peVar2 == (edict_t *)0x0) {
      peVar4 = (entvars_t *)0x0;
    }
    if ((peVar4->flags & 0x20) == 0) {
      peVar2 = (*g_engfuncs.pfnFindEntityByString)
                         (peVar2,"targetname",gpGlobals->pStringBase + this->m_iszEntity);
      goto joined_r0x00117e1e;
    }
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    peVar5 = peVar2;
    if (((peVar2 == (edict_t *)0x0) &&
        (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 == (edict_t *)0x0)) ||
       (piVar1 = peVar5->pvPrivateData, piVar1 == (int *)0x0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = (**(code **)(*piVar1 + 0x4c))(piVar1);
    }
    peVar2 = (*g_engfuncs.pfnFindEntityByString)
                       (peVar2,"targetname",gpGlobals->pStringBase + this->m_iszEntity);
    if (iVar3 != 0) goto LAB_00117f8f;
  } while( true );
}


// CBaseMonster::CineCleanup  @ 001188f0  (line 792)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL CineCleanup(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::CineCleanup(CBaseMonster *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  CCineMonster *pCVar4;
  vec_t vVar5;
  float __x;
  vec_t vVar6;
  vec_t vVar7;
  vec_t vVar8;
  entvars_t *peVar9;
  int iVar10;
  float fVar11;
  Vector local_3c [2];
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: CCineMonster * pOldCine@[???] */
  pCVar4 = this->m_pCine;
  if (pCVar4 == (CCineMonster *)0x0) {
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    movetype = 4;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid =
         3;
  }
  else {
    EHANDLE::operator=(&(pCVar4->super_CBaseMonster).m_hTargetEnt,(CBaseEntity *)0x0);
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    movetype = this->m_pCine->m_saved_movetype;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid =
         this->m_pCine->m_saved_solid;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->effects
         = this->m_pCine->m_saved_effects;
  }
  this->m_pCine = (CCineMonster *)0x0;
  EHANDLE::operator=(&this->m_hTargetEnt,(CBaseEntity *)0x0);
  peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pGoalEnt =
       (CBaseEntity *)0x0;
  if (peVar9->deadflag == 1) {
    peVar9->health = 0.0;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    framerate = 0.0;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid =
         0;
    SetState(this,MONSTERSTATE_DEAD);
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    deadflag = 2;
    peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    local_24.y = (peVar9->maxs).y;
    local_24.z = (peVar9->mins).z + 2.0;
    local_24.x = (peVar9->maxs).x;
    UTIL_SetSize(peVar9,&peVar9->mins,&local_24);
    if ((pCVar4 == (CCineMonster *)0x0) ||
       ((((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->spawnflags & 8) == 0)) {
      CBaseEntity::SUB_StartFadeOut((CBaseEntity *)this);
    }
    else {
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.
      __pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float
               *)0x0;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.
      __delta = 0;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __delta = 0;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
      __pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
      __delta = 0;
    }
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    framerate = 0.0;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    movetype = 0;
    piVar1 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
              )->effects;
    *piVar1 = *piVar1 | 0x20;
    return 0;
  }
  if ((pCVar4 != (CCineMonster *)0x0) && (pCVar4->m_iszPlay != 0)) {
    if ((((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->spawnflags & 0x80) == 0) {
                    /* Unresolved local var: Vector new_origin@[???]
                       Unresolved local var: Vector new_angle@[???]
                       Unresolved local var: Vector oldOrigin@[???]
                       Unresolved local var: int drop@[???] */
      CBaseAnimating::GetBonePosition((CBaseAnimating *)this,0,local_3c,&local_18);
      peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      vVar5 = (peVar9->origin).z;
      fVar2 = (peVar9->origin).x;
      fVar3 = (peVar9->origin).y;
      __x = (fVar3 - local_3c[0].y) * (fVar3 - local_3c[0].y) +
            (fVar2 - local_3c[0].x) * (fVar2 - local_3c[0].x);
      fVar11 = SQRT(__x);
      if (NAN(fVar11)) {
        fVar11 = sqrtf(__x);
        peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev;
      }
      vVar6 = fVar2;
      vVar7 = fVar3;
      vVar8 = vVar5;
      if (8.0 <= fVar11) {
        vVar6 = local_3c[0].x;
        vVar7 = local_3c[0].y;
        vVar8 = local_3c[0].z;
      }
      local_3c[0].z = vVar8;
      local_3c[0].y = vVar7;
      local_3c[0].x = vVar6;
      (peVar9->origin).x = local_3c[0].x;
      (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      origin).y = local_3c[0].y;
      peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      (peVar9->origin).z = (peVar9->origin).z + 1.0;
      piVar1 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev)->flags;
      *piVar1 = *piVar1 | 0x200;
      iVar10 = (*g_engfuncs.pfnDropToFloor)
                         (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                           super_CBaseEntity.pev)->pContainingEntity);
      if (iVar10 < 0) {
        peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev;
        (peVar9->origin).x = fVar2;
        (peVar9->origin).y = fVar3;
        (peVar9->origin).z = vVar5;
      }
      else if (iVar10 == 0) {
        (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
        origin).z = local_3c[0].z;
        piVar1 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                  .pev)->flags;
        *piVar1 = *piVar1 & 0xfffffdff;
      }
      peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      UTIL_SetOrigin(peVar9,&peVar9->origin);
      piVar1 = &((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev)->effects;
      *piVar1 = *piVar1 | 0x20;
      peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
    }
    this->m_Activity = ACT_RESET;
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


// CScriptedSentence::ObjectCaps  @ 00119b00  (line 925)

/* DWARF original prototype: int ObjectCaps(CScriptedSentence * this) */

int __thiscall CScriptedSentence::ObjectCaps(CScriptedSentence *this)

{
  return 0;
}


// CScriptedSentence::Restore  @ 00117710  (line 968)

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


// CScriptedSentence::Save  @ 001177d0  (line 968)

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


// scripted_sentence  @ 00119580  (line 970)

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
  *puVar1 = &PTR__CScriptedSentence_0018aac8;
  puVar1[1] = pev;
  return;
}


// CScriptedSentence::KeyValue  @ 00117bc0  (line 973)

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


// CScriptedSentence::Use  @ 001176e0  (line 1020)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Use(CScriptedSentence * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CScriptedSentence::Use
          (CScriptedSentence *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  globalvars_t *pgVar1;
  
  pgVar1 = gpGlobals;
  if (this->m_active != 0) {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = FindThink;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
    ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
    nextthink = pgVar1->time;
  }
  return;
}


// CScriptedSentence::Spawn  @ 00117230  (line 1030)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CScriptedSentence * this) */

void __thiscall CScriptedSentence::Spawn(CScriptedSentence *this)

{
  int iVar1;
  globalvars_t *pgVar2;
  entvars_t *peVar3;
  float fVar4;
  
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 0
  ;
  peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  this->m_active = 1;
  pgVar2 = gpGlobals;
  if (peVar3->targetname == 0) {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = FindThink;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
    peVar3->nextthink = pgVar2->time + 1.0;
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  iVar1 = peVar3->impulse;
  if (iVar1 == 2) {
    this->m_flAttenuation = 0.8;
  }
  else if (iVar1 == 3) {
    this->m_flAttenuation = 0.0;
  }
  else {
    fVar4 = 2.0;
    if (iVar1 == 1) {
      fVar4 = 1.25;
    }
    this->m_flAttenuation = fVar4;
  }
  peVar3->impulse = 0;
  if (this->m_flVolume <= 0.0) {
    this->m_flVolume = 1.0;
  }
  return;
}


// CScriptedSentence::FindThink  @ 001199b0  (line 1069)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void FindThink(CScriptedSentence * this) */

void __thiscall CScriptedSentence::FindThink(CScriptedSentence *this)

{
  globalvars_t *pgVar1;
  CBaseMonster *pTarget;
  entvars_t *peVar2;
  
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
  pTarget = FindEntity(this);
  if (pTarget != (CBaseMonster *)0x0) {
    StartSentence(this,pTarget);
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if ((peVar2->spawnflags & 1) != 0) {
      UTIL_Remove((CBaseEntity *)this);
      peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
    }
    pgVar1 = gpGlobals;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = DelayThink;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
    peVar2->nextthink = pgVar1->time + this->m_flDuration + this->m_flRepeat;
    this->m_active = 0;
    return;
  }
                    /* Unresolved local var: CBaseMonster * pMonster@[???] */
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->nextthink
       = gpGlobals->time + this->m_flRepeat + 0.5;
  return;
}


// CScriptedSentence::DelayThink  @ 001172e0  (line 1090)

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


// CScriptedSentence::AcceptableSpeaker  @ 001195f0  (line 1099)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL AcceptableSpeaker(CScriptedSentence * this, CBaseMonster *
   pMonster) */

BOOL __thiscall CScriptedSentence::AcceptableSpeaker(CScriptedSentence *this,CBaseMonster *pMonster)

{
  uint uVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
  if (pMonster == (CBaseMonster *)0x0) {
    return 0;
  }
                    /* Unresolved local var: BOOL override@[???] */
  uVar1 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
          spawnflags;
  if ((uVar1 & 2) != 0) {
    iVar2 = EHANDLE::operator_int(&pMonster->m_hTargetEnt);
    if (iVar2 == 0) {
      return 0;
    }
    pCVar3 = EHANDLE::operator->(&pMonster->m_hTargetEnt);
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
    if (!bVar6) {
      return 0;
    }
    uVar1 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
            ->spawnflags;
  }
  iVar2 = (*(pMonster->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x60])(pMonster,(uint)((uVar1 & 4) != 0));
  return (uint)(iVar2 != 0);
}


// CScriptedSentence::FindEntity  @ 001196b0  (line 1120)

/* DWARF original prototype: CBaseMonster * FindEntity(CScriptedSentence * this) */

CBaseMonster * __thiscall CScriptedSentence::FindEntity(CScriptedSentence *this)

{
  int *piVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  int iVar4;
  CBaseMonster *pCVar5;
  BOOL BVar6;
  edict_t *peVar7;
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
          peVar2 = pStartEntity->pev;
          iVar4 = strcmp(gpGlobals->pStringBase + peVar2->classname,
                         gpGlobals->pStringBase + this->m_iszEntity);
        } while ((iVar4 != 0) || ((peVar2->flags & 0x20) == 0));
        pCVar5 = (CBaseMonster *)(*pStartEntity->_vptr_CBaseEntity[0x13])(pStartEntity);
        BVar6 = AcceptableSpeaker(this,pCVar5);
      } while (BVar6 == 0);
      return pCVar5;
    }
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    peVar7 = peVar3;
    if (((peVar3 != (edict_t *)0x0) ||
        (peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar7 != (edict_t *)0x0)) &&
       (((piVar1 = peVar7->pvPrivateData, piVar1 != (int *)0x0 &&
         (pCVar5 = (CBaseMonster *)(**(code **)(*piVar1 + 0x4c))(piVar1),
         pCVar5 != (CBaseMonster *)0x0)) && (BVar6 = AcceptableSpeaker(this,pCVar5), BVar6 != 0))))
    break;
    peVar3 = (*g_engfuncs.pfnFindEntityByString)
                       (peVar3,"targetname",gpGlobals->pStringBase + this->m_iszEntity);
  }
  return pCVar5;
}


// CScriptedSentence::StartSentence  @ 00119810  (line 1159)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL StartSentence(CScriptedSentence * this, CBaseMonster * pTarget) */

BOOL __thiscall CScriptedSentence::StartSentence(CScriptedSentence *this,CBaseMonster *pTarget)

{
  uint uVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  BOOL BVar4;
  byte *szWhatever;
  int iVar5;
  byte *pbVar6;
  float flRadius;
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
      flRadius = 4096.0;
      if ((!bVar8 && !bVar9) != bVar8) {
        flRadius = this->m_flRadius;
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


// CFurniture::ObjectCaps  @ 00119b10  (line 1205)

/* DWARF original prototype: int ObjectCaps(CFurniture * this) */

int __thiscall CFurniture::ObjectCaps(CFurniture *this)

{
  return 0;
}


// monster_furniture  @ 00119a50  (line 1209)

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
  *puVar1 = &PTR__CFurniture_0018abe8;
  puVar1[1] = pev;
  return;
}


// CFurniture::Die  @ 00119ac0  (line 1216)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Die(CFurniture * this) */

void __thiscall CFurniture::Die(CFurniture *this)

{
  globalvars_t *pgVar1;
  
  pgVar1 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = pgVar1->time;
  return;
}


// CFurniture::Spawn  @ 00117340  (line 1226)

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
                    /* WARNING: Could not recover jumptable at 0x00117410. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x48])();
  return;
}


// CFurniture::Classify  @ 00117330  (line 1253)

/* DWARF original prototype: int Classify(CFurniture * this) */

int __thiscall CFurniture::Classify(CFurniture *this)

{
  return 0;
}


