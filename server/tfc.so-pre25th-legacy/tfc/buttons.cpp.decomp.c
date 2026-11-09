// Ghidra decompilation of functions from tfc/buttons.cpp
// 64 functions, ordered by original source line

// CEnvGlobal::Restore  @ 000b26a0  (line 62)

/* DWARF original prototype: int Restore(CEnvGlobal * this, CRestore * restore) */

int __thiscall CEnvGlobal::Restore(CEnvGlobal *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore((CBaseEntity *)this,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CEnvGlobal",this,m_SaveData,3);
  }
  return iVar2;
}


// CEnvGlobal::Save  @ 000b27c0  (line 62)

/* DWARF original prototype: int Save(CEnvGlobal * this, CSave * save) */

int __thiscall CEnvGlobal::Save(CEnvGlobal *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save((CBaseEntity *)this,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CEnvGlobal",this,m_SaveData,3);
  }
  return iVar2;
}


// env_global  @ 000b3b80  (line 64)

void env_global(entvars_t *pev)

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
  *puVar1 = &PTR__CEnvGlobal_00179408;
  puVar1[1] = pev;
  return;
}


// CEnvGlobal::KeyValue  @ 000b30a0  (line 67)

/* DWARF original prototype: void KeyValue(CEnvGlobal * this, KeyValueData * pkvd) */

void __thiscall CEnvGlobal::KeyValue(CEnvGlobal *this,KeyValueData *pkvd)

{
  long lVar1;
  string_t sVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
  bVar7 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar3 = 0xc;
  pcVar5 = pkvd->szKeyName;
  pkvd->fHandled = 1;
  pcVar4 = pcVar5;
  pcVar6 = "globalstate";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar4 == *pcVar6;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    sVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    this->m_globalstate = sVar2;
  }
  else {
    iVar3 = 0xc;
    bVar7 = false;
    pcVar4 = pcVar5;
    pcVar6 = "triggermode";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
      this->m_triggermode = lVar1;
    }
    else {
      iVar3 = 0xd;
      bVar7 = false;
      pcVar4 = "initialstate";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar5 == *pcVar4;
        pcVar5 = pcVar5 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar7);
      if (!bVar7) {
        CBaseEntity::KeyValue((CBaseEntity *)this,pkvd);
        return;
      }
      lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
      this->m_initialstate = lVar1;
    }
  }
  return;
}


// CEnvGlobal::Spawn  @ 000b2c20  (line 81)

/* DWARF original prototype: void Spawn(CEnvGlobal * this) */

void __thiscall CEnvGlobal::Spawn(CEnvGlobal *this)

{
  globalentity_t *pgVar1;
  
  if (this->m_globalstate != 0) {
    if ((((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 1) != 0) {
      pgVar1 = CGlobalState::Find(&gGlobalState,this->m_globalstate);
      if (pgVar1 == (globalentity_t *)0x0) {
        CGlobalState::EntityAdd
                  (&gGlobalState,this->m_globalstate,gpGlobals->mapname,this->m_initialstate);
      }
    }
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000b2ca6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnRemoveEntity)
            (((this->super_CPointEntity).super_CBaseEntity.pev)->pContainingEntity);
  return;
}


// CEnvGlobal::Use  @ 000b23e0  (line 96)

/* DWARF original prototype: void Use(CEnvGlobal * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CEnvGlobal::Use(CEnvGlobal *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
               float value)

{
  int iVar1;
  GLOBALESTATE GVar2;
  globalentity_t *pgVar3;
  GLOBALESTATE state;
  
                    /* Unresolved local var: GLOBALESTATE oldState@[???]
                       Unresolved local var: GLOBALESTATE newState@[???] */
  GVar2 = CGlobalState::EntityGetState(&gGlobalState,this->m_globalstate);
  iVar1 = this->m_triggermode;
  state = GLOBAL_ON;
  if ((((iVar1 != 1) && (state = GLOBAL_DEAD, iVar1 != 2)) && (state = GLOBAL_OFF, iVar1 != 0)) &&
     ((GVar2 != GLOBAL_ON && (state = GLOBAL_ON, GVar2 != GLOBAL_OFF)))) {
    state = GVar2;
  }
  pgVar3 = CGlobalState::Find(&gGlobalState,this->m_globalstate);
  if (pgVar3 == (globalentity_t *)0x0) {
    CGlobalState::EntityAdd(&gGlobalState,this->m_globalstate,gpGlobals->mapname,state);
    return;
  }
  CGlobalState::EntitySetState(&gGlobalState,this->m_globalstate,state);
  return;
}


// CMultiSource::Restore  @ 000b2640  (line 141)

/* DWARF original prototype: int Restore(CMultiSource * this, CRestore * restore) */

int __thiscall CMultiSource::Restore(CMultiSource *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore((CBaseEntity *)this,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CMultiSource",this,m_SaveData,4);
  }
  return iVar2;
}


// CMultiSource::Save  @ 000b2760  (line 141)

/* DWARF original prototype: int Save(CMultiSource * this, CSave * save) */

int __thiscall CMultiSource::Save(CMultiSource *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save((CBaseEntity *)this,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CMultiSource",this,m_SaveData,4);
  }
  return iVar2;
}


// multisource  @ 000b3bf0  (line 143)

void multisource(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x5fc,pev);
  *puVar1 = &PTR__CMultiSource_00179528;
  puVar1[1] = pev;
  return;
}


// CMultiSource::KeyValue  @ 000b3480  (line 149)

/* DWARF original prototype: void KeyValue(CMultiSource * this, KeyValueData * pkvd) */

void __thiscall CMultiSource::KeyValue(CMultiSource *this,KeyValueData *pkvd)

{
  string_t sVar1;
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
      iVar2 = 0xb;
      pcVar3 = pcVar4;
      pcVar5 = "killtarget";
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
              iVar2 = 0xc;
              pcVar3 = "globalstate";
              do {
                if (iVar2 == 0) break;
                iVar2 = iVar2 + -1;
                bVar6 = *pcVar4 == *pcVar3;
                pcVar4 = pcVar4 + 1;
                pcVar3 = pcVar3 + 1;
              } while (bVar6);
              if (!bVar6) {
                CBaseEntity::KeyValue((CBaseEntity *)this,pkvd);
                return;
              }
              sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
              this->m_globalstate = sVar1;
            }
          }
        }
      }
    }
  }
  pkvd->fHandled = 1;
  return;
}


// CMultiSource::Spawn  @ 000b12a0  (line 169)

/* DWARF original prototype: void Spawn(CMultiSource * this) */

void __thiscall CMultiSource::Spawn(CMultiSource *this)

{
  int *piVar1;
  
  ((this->super_CPointEntity).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  piVar1 = &((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags;
  *piVar1 = *piVar1 | 1;
  (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = Register;
  (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
  return;
}


// CMultiSource::Use  @ 000b29a0  (line 180)

/* DWARF original prototype: void Use(CMultiSource * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CMultiSource::Use(CMultiSource *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
                 float value)

{
  EHANDLE *this_00;
  CBaseEntity *pCVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar2 = 0;
  do {
    if (this->m_iTotal <= iVar2) {
      if (iVar2 <= this->m_iTotal) goto LAB_000b29e2;
      goto LAB_000b2a7e;
    }
    this_00 = this->m_rgEntities + iVar2;
    iVar2 = iVar2 + 1;
    pCVar1 = EHANDLE::operator_CBaseEntity_(this_00);
  } while (pCVar1 != pCaller);
  if (iVar2 <= this->m_iTotal) {
LAB_000b29e2:
    this->m_rgTriggered[iVar2 + -1] = this->m_rgTriggered[iVar2 + -1] ^ 1;
    iVar2 = (*(this->super_CPointEntity).super_CBaseEntity._vptr_CBaseEntity[0x12])(this);
    if (iVar2 == 0) {
      return;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: USE_TYPE useType@[???] */
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"Multisource %s enabled (%d inputs)\n",
               gpGlobals->pStringBase +
               ((this->super_CPointEntity).super_CBaseEntity.pev)->targetname,this->m_iTotal);
    CBaseEntity::SUB_UseTargets
              ((CBaseEntity *)this,(CBaseEntity *)0x0,
               (-(uint)(this->m_globalstate == 0) & 2) + USE_ON,0.0);
    return;
  }
LAB_000b2a7e:
                    /* WARNING: Could not recover jumptable at 0x000b2ab1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnAlertMessage)(at_console,"MultiSrc:Used by non member %s.\n");
  return;
}


// CMultiSource::IsTriggered  @ 000b2b90  (line 212)

/* DWARF original prototype: int IsTriggered(CMultiSource * this) */

int __thiscall CMultiSource::IsTriggered(CMultiSource *this)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  GLOBALESTATE GVar5;
  
                    /* Unresolved local var: int i@[???] */
  uVar3 = 0;
  if ((((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 1U) == 0) {
                    /* Unresolved local var: int i@[???] */
    iVar1 = this->m_iTotal;
    if (iVar1 < 1) {
      if (iVar1 != 0) {
        return 0;
      }
    }
    else {
      if (this->m_rgTriggered[0] == 0) {
        return 0;
      }
      iVar4 = 0;
      while (iVar4 + 1 != iVar1) {
        iVar2 = iVar4 + 1;
        iVar4 = iVar4 + 1;
        if (this->m_rgTriggered[iVar2] == 0) {
          return 0;
        }
      }
    }
    uVar3 = 1;
    if (this->m_globalstate != 0) {
      GVar5 = CGlobalState::EntityGetState(&gGlobalState,this->m_globalstate);
      uVar3 = (uint)(GVar5 == GLOBAL_ON);
    }
  }
  return uVar3;
}


// CMultiSource::Register  @ 000b2110  (line 237)

/* DWARF original prototype: void Register(CMultiSource * this) */

void __thiscall CMultiSource::Register(CMultiSource *this)

{
  int *piVar1;
  entvars_t *peVar2;
  CBaseEntity *pCVar3;
  globalvars_t *pgVar4;
  uint uVar5;
  uint uVar6;
  edict_t *peVar7;
  int iVar8;
  edict_t *peVar9;
  uint uVar10;
  EHANDLE *pEVar11;
  undefined4 *puVar12;
  bool bVar13;
  
                    /* Unresolved local var: edict_t * pentTarget@[???] */
  uVar10 = 0x100;
  pEVar11 = this->m_rgEntities;
  bVar13 = ((uint)pEVar11 & 1) != 0;
  this->m_iTotal = 0;
  if (bVar13) {
    pEVar11 = (EHANDLE *)((int)&this->m_rgEntities[0].m_pent + 1);
    uVar10 = 0xff;
    *(undefined1 *)&this->m_rgEntities[0].m_pent = 0;
  }
  if (((uint)pEVar11 & 2) != 0) {
    *(undefined2 *)&pEVar11->m_pent = 0;
    uVar10 = uVar10 - 2;
    pEVar11 = (EHANDLE *)((int)&pEVar11->m_pent + 2);
  }
  uVar5 = 0;
  do {
    uVar6 = uVar5;
    *(undefined4 *)((int)&pEVar11->m_serialnumber + uVar6) = 0;
    *(undefined4 *)((int)&pEVar11[1].m_pent + uVar6) = 0;
    *(undefined4 *)((int)&pEVar11->m_pent + uVar6) = 0;
    *(undefined4 *)((int)&pEVar11[1].m_serialnumber + uVar6) = 0;
    uVar5 = uVar6 + 0x10;
  } while (uVar6 + 0x10 < (uVar10 & 0xfffffff0));
  puVar12 = (undefined4 *)((int)&pEVar11[2].m_pent + uVar6);
  if ((uVar10 & 8) != 0) {
    *puVar12 = 0;
    puVar12[1] = 0;
    puVar12 = puVar12 + 2;
  }
  if ((uVar10 & 4) != 0) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  if ((uVar10 & 2) != 0) {
    *(undefined2 *)puVar12 = 0;
    puVar12 = (undefined4 *)((int)puVar12 + 2);
  }
  if (bVar13) {
    *(undefined1 *)puVar12 = 0;
  }
  pgVar4 = gpGlobals;
  peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
  (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_DoNothing;
  (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar7 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"target",pgVar4->pStringBase + peVar2->targetname);
  while (((peVar7 != (edict_t *)0x0 &&
          (iVar8 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar7), iVar8 != 0)) &&
         (this->m_iTotal < 0x20))) {
                    /* Unresolved local var: CBaseEntity * pTarget@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    peVar9 = peVar7;
    if (((peVar7 != (edict_t *)0x0) ||
        (peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar9 != (edict_t *)0x0)) &&
       (pCVar3 = peVar9->pvPrivateData, pCVar3 != (CBaseEntity *)0x0)) {
      iVar8 = this->m_iTotal;
      this->m_iTotal = iVar8 + 1;
      EHANDLE::operator=(this->m_rgEntities + iVar8,pCVar3);
    }
    peVar7 = (*g_engfuncs.pfnFindEntityByString)
                       (peVar7,"target",
                        gpGlobals->pStringBase +
                        ((this->super_CPointEntity).super_CBaseEntity.pev)->targetname);
  }
  peVar7 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"classname","multi_manager");
  while (((peVar7 != (edict_t *)0x0 &&
          (iVar8 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar7), iVar8 != 0)) &&
         (this->m_iTotal < 0x20))) {
                    /* Unresolved local var: CBaseEntity * pTarget@[DW_OP_reg7(EDI)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    peVar9 = peVar7;
    if ((((peVar7 != (edict_t *)0x0) ||
         (peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar9 != (edict_t *)0x0)) &&
        (pCVar3 = peVar9->pvPrivateData, pCVar3 != (CBaseEntity *)0x0)) &&
       (iVar8 = (*pCVar3->_vptr_CBaseEntity[0x25])
                          (pCVar3,((this->super_CPointEntity).super_CBaseEntity.pev)->targetname),
       iVar8 != 0)) {
      iVar8 = this->m_iTotal;
      this->m_iTotal = iVar8 + 1;
      EHANDLE::operator=(this->m_rgEntities + iVar8,pCVar3);
    }
    peVar7 = (*g_engfuncs.pfnFindEntityByString)(peVar7,"classname","multi_manager");
  }
  piVar1 = &((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags;
  *piVar1 = *piVar1 & 0xfffffffe;
  return;
}


// CBaseButton::Restore  @ 000b2880  (line 287)

/* DWARF original prototype: int Restore(CBaseButton * this, CRestore * restore) */

int __thiscall CBaseButton::Restore(CBaseButton *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Restore(&this->super_CBaseToggle,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CBaseButton",this,m_SaveData,8);
  }
  return iVar2;
}


// CBaseButton::Save  @ 000b2940  (line 287)

/* DWARF original prototype: int Save(CBaseButton * this, CSave * save) */

int __thiscall CBaseButton::Save(CBaseButton *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Save(&this->super_CBaseToggle,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CBaseButton",this,m_SaveData,8);
  }
  return iVar2;
}


// CBaseButton::Precache  @ 000b12f0  (line 290)

/* DWARF original prototype: void Precache(CBaseButton * this) */

void __thiscall CBaseButton::Precache(CBaseButton *this)

{
  byte bVar1;
  string_t sVar2;
  char *pcVar3;
  
                    /* Unresolved local var: char * pszSound@[???] */
  if ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
       spawnflags & 0x40) != 0) {
    (*g_engfuncs.pfnPrecacheSound)("buttons/spark1.wav");
    (*g_engfuncs.pfnPrecacheSound)("buttons/spark2.wav");
    (*g_engfuncs.pfnPrecacheSound)("buttons/spark3.wav");
    (*g_engfuncs.pfnPrecacheSound)("buttons/spark4.wav");
    (*g_engfuncs.pfnPrecacheSound)("buttons/spark5.wav");
    (*g_engfuncs.pfnPrecacheSound)("buttons/spark6.wav");
  }
  bVar1 = this->m_bLockedSound;
  if (bVar1 != 0) {
    pcVar3 = "buttons/button9.wav";
    if (bVar1 < 0x1a) {
      pcVar3 = *(char **)(CSWTCH_148 + (uint)bVar1 * 4);
    }
    (*g_engfuncs.pfnPrecacheSound)(pcVar3);
    sVar2 = (*g_engfuncs.pfnAllocString)(pcVar3);
    (this->m_ls).sLockedSound = sVar2;
  }
  bVar1 = this->m_bUnlockedSound;
  if (bVar1 != 0) {
    pcVar3 = "buttons/button9.wav";
    if (bVar1 < 0x1a) {
      pcVar3 = *(char **)(CSWTCH_148 + (uint)bVar1 * 4);
    }
    (*g_engfuncs.pfnPrecacheSound)(pcVar3);
    sVar2 = (*g_engfuncs.pfnAllocString)(pcVar3);
    (this->m_ls).sUnlockedSound = sVar2;
  }
  switch(this->m_bLockedSentence) {
  default:
    (this->m_ls).sLockedSentence = 0;
    break;
  case '\x01':
    (this->m_ls).sLockedSentence = (int)&DAT_00178e3e - (int)gpGlobals->pStringBase;
    break;
  case '\x02':
    (this->m_ls).sLockedSentence = (string_t)("ACT_LAND" + (6 - (int)gpGlobals->pStringBase));
    break;
  case '\x03':
    (this->m_ls).sLockedSentence = (int)&DAT_00178e41 - (int)gpGlobals->pStringBase;
    break;
  case '\x04':
    (this->m_ls).sLockedSentence = (int)"NFIRE" - (int)gpGlobals->pStringBase;
    break;
  case '\x05':
    (this->m_ls).sLockedSentence = (int)"NCHEM" - (int)gpGlobals->pStringBase;
    break;
  case '\x06':
    (this->m_ls).sLockedSentence = (int)&DAT_00178e50 - (int)gpGlobals->pStringBase;
    break;
  case '\a':
    (this->m_ls).sLockedSentence = (int)&DAT_00178e55 - (int)gpGlobals->pStringBase;
    break;
  case '\b':
    (this->m_ls).sLockedSentence = (int)&DAT_00178e5a - (int)gpGlobals->pStringBase;
    break;
  case '\t':
    (this->m_ls).sLockedSentence = (int)&DAT_00178e5d - (int)gpGlobals->pStringBase;
  }
  switch(this->m_bUnlockedSentence) {
  default:
    (this->m_ls).sUnlockedSentence = 0;
    return;
  case '\x01':
    (this->m_ls).sUnlockedSentence = (int)&DAT_00178e60 - (int)gpGlobals->pStringBase;
    return;
  case '\x02':
    (this->m_ls).sUnlockedSentence =
         (string_t)("ACT_WALK_SCARED" + (0xd - (int)gpGlobals->pStringBase));
    return;
  case '\x03':
    (this->m_ls).sUnlockedSentence = (int)&DAT_00178e63 - (int)gpGlobals->pStringBase;
    return;
  case '\x04':
    (this->m_ls).sUnlockedSentence = (int)"EFIRE" - (int)gpGlobals->pStringBase;
    return;
  case '\x05':
    (this->m_ls).sUnlockedSentence = (int)"ECHEM" - (int)gpGlobals->pStringBase;
    return;
  case '\x06':
    (this->m_ls).sUnlockedSentence = (int)&DAT_00178e72 - (int)gpGlobals->pStringBase;
    return;
  case '\a':
    (this->m_ls).sUnlockedSentence = (int)&DAT_00178e77 - (int)gpGlobals->pStringBase;
    return;
  case '\b':
    (this->m_ls).sUnlockedSentence = (int)&DAT_00178e7c - (int)gpGlobals->pStringBase;
    return;
  }
}


// CBaseButton::KeyValue  @ 000b31a0  (line 356)

/* DWARF original prototype: void KeyValue(CBaseButton * this, KeyValueData * pkvd) */

void __thiscall CBaseButton::KeyValue(CBaseButton *this,KeyValueData *pkvd)

{
  string_t sVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  double dVar8;
  
  bVar7 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar3 = 0xd;
  pcVar5 = pkvd->szKeyName;
  pcVar4 = pcVar5;
  pcVar6 = "changetarget";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar4 == *pcVar6;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    this->m_strChangeTarget = sVar1;
    pkvd->fHandled = 1;
  }
  else {
    iVar3 = 0xd;
    bVar7 = false;
    pcVar4 = pcVar5;
    pcVar6 = "locked_sound";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      dVar8 = strtod(pkvd->szValue,(char **)0x0);
      this->m_bLockedSound = (BYTE)(int)dVar8;
      pkvd->fHandled = 1;
    }
    else {
      iVar3 = 0x10;
      bVar7 = false;
      pcVar4 = pcVar5;
      pcVar6 = "locked_sentence";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar4 == *pcVar6;
        pcVar4 = pcVar4 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar7);
      if (bVar7) {
        dVar8 = strtod(pkvd->szValue,(char **)0x0);
        this->m_bLockedSentence = (BYTE)(int)dVar8;
        pkvd->fHandled = 1;
      }
      else {
        iVar3 = 0xf;
        bVar7 = false;
        pcVar4 = pcVar5;
        pcVar6 = "unlocked_sound";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar7 = *pcVar4 == *pcVar6;
          pcVar4 = pcVar4 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar7);
        if (bVar7) {
          dVar8 = strtod(pkvd->szValue,(char **)0x0);
          this->m_bUnlockedSound = (BYTE)(int)dVar8;
          pkvd->fHandled = 1;
        }
        else {
          iVar3 = 0x12;
          bVar7 = false;
          pcVar4 = pcVar5;
          pcVar6 = "unlocked_sentence";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar7 = *pcVar4 == *pcVar6;
            pcVar4 = pcVar4 + 1;
            pcVar6 = pcVar6 + 1;
          } while (bVar7);
          if (bVar7) {
            dVar8 = strtod(pkvd->szValue,(char **)0x0);
            this->m_bUnlockedSentence = (BYTE)(int)dVar8;
            pkvd->fHandled = 1;
          }
          else {
            iVar3 = 7;
            bVar7 = false;
            pcVar4 = "sounds";
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
            this->m_sounds = lVar2;
            pkvd->fHandled = 1;
          }
        }
      }
    }
  }
  return;
}


// CBaseButton::TakeDamage  @ 000b3910  (line 395)

/* WARNING: Variable defined which should be unmapped: code */
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int TakeDamage(CBaseButton * this, entvars_t * pevInflictor, entvars_t
   * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CBaseButton::TakeDamage
          (CBaseButton *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  EHANDLE *this_00;
  TOGGLE_STATE TVar1;
  entvars_t *peVar2;
  BOOL BVar3;
  CBaseEntity *pCVar4;
  CBasePlayer *AP;
  edict_t *peVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  bool bVar10;
  CBaseButton *this_01;
  BUTTON_CODE code;
  
  TVar1 = (this->super_CBaseToggle).m_toggle_state;
  if (TVar1 - TS_GOING_UP < 2) {
    return 0;
  }
  iVar7 = 1;
  if (TVar1 == TS_AT_TOP) {
    if (this->m_fStayPushed != 0) {
      return 0;
    }
    if ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
         spawnflags & 0x20) == 0) {
      return 0;
    }
    iVar7 = 2;
  }
  if (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
       goal_activation & 8) != 0) {
    return 0;
  }
  bVar10 = gpGlobals->pStringBase + pevAttacker->classname == (char *)0x0;
  iVar6 = 7;
  pcVar8 = gpGlobals->pStringBase + pevAttacker->classname;
  pcVar9 = "player";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar10 = *pcVar8 == *pcVar9;
    pcVar8 = pcVar8 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar10);
  if (bVar10) {
                    /* Unresolved local var: CBaseEntity * pAttacker@[DW_OP_reg0(EAX)] */
    peVar5 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar5 == (edict_t *)0x0) &&
       (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 == (edict_t *)0x0)) {
      AP = (CBasePlayer *)0x0;
    }
    else {
      AP = peVar5->pvPrivateData;
    }
    BVar3 = ActivationSucceeded((CBaseEntity *)this,AP,(CBaseEntity *)0x0);
    if (BVar3 == 0) {
      return 0;
    }
  }
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  peVar2->health = peVar2->health - flDamage;
  if (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      health <= 0.0) {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __delta = 0;
    peVar5 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg0(EAX)] */
    if ((peVar5 == (edict_t *)0x0) &&
       (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 == (edict_t *)0x0)) {
      pCVar4 = (CBaseEntity *)0x0;
    }
    else {
      pCVar4 = peVar5->pvPrivateData;
    }
    this_00 = &(this->super_CBaseToggle).m_hActivator;
    EHANDLE::operator=(this_00,pCVar4);
    iVar6 = EHANDLE::operator_int(this_00);
    if (iVar6 != 0) {
      peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      peVar5 = peVar2->pContainingEntity;
      if (iVar7 == 2) {
        EMIT_SOUND_DYN(peVar5,2,gpGlobals->pStringBase + peVar2->noise,1.0,0.8,0,100);
        if ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
             ->spawnflags & 0x20) == 0) {
          pCVar4 = EHANDLE::operator_CBaseEntity_(this_00);
          CBaseDelay::SUB_UseTargets((CBaseDelay *)this,pCVar4,USE_TOGGLE,0.0);
        }
        ButtonReturn(this);
      }
      else {
        EMIT_SOUND_DYN(peVar5,2,gpGlobals->pStringBase + peVar2->noise,1.0,0.8,0,100);
        this_01 = (CBaseButton *)(this->super_CBaseToggle).m_sMaster;
        iVar7 = UTIL_IsMasterTriggered((string_t)this_01);
        if (iVar7 == 0) {
          PlayLockSounds((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                         super_CBaseEntity.pev,&this->m_ls,1,1);
        }
        else {
          ButtonActivate(this_01);
        }
      }
    }
    return 0;
  }
  return 0;
}


// func_button  @ 000b3c60  (line 457)

void func_button(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x54c,pev);
  *puVar1 = &PTR__CBaseButton_00179648;
  puVar1[1] = pev;
  return;
}


// CBaseButton::Spawn  @ 000b1e00  (line 461)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CBaseButton * this) */

void __thiscall CBaseButton::Spawn(CBaseButton *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  globalvars_t *pgVar7;
  string_t sVar8;
  entvars_t *peVar9;
  uint uVar10;
  char *pcVar11;
  float fVar12;
  
                    /* Unresolved local var: char * pszSound@[DW_OP_reg6(ESI)] */
  pcVar11 = "buttons/button9.wav";
  if ((uint)this->m_sounds < 0x1a) {
    pcVar11 = *(char **)(CSWTCH_148 + this->m_sounds * 4);
  }
  (*g_engfuncs.pfnPrecacheSound)(pcVar11);
  peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  sVar8 = (*g_engfuncs.pfnAllocString)(pcVar11);
  peVar9->noise = sVar8;
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[3])(this);
  pgVar7 = gpGlobals;
  peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar9->spawnflags & 0x40) != 0) {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = ButtonSpark;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
    peVar9->nextthink = pgVar7->time + 0.5;
    peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  SetMovedir(peVar9);
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->movetype
       = 7;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 4
  ;
  peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar9->pContainingEntity,gpGlobals->pStringBase + peVar9->model);
  peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar9->speed == 0.0) {
    peVar9->speed = 40.0;
    peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  peVar9->max_health = 0.0;
  peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (0.0 < peVar9->health) {
    peVar9->takedamage = 1.0;
    peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    peVar9->max_health = peVar9->health;
    peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  if ((this->super_CBaseToggle).m_flWait == 0.0) {
    (this->super_CBaseToggle).m_flWait = 1.0;
  }
  if ((this->super_CBaseToggle).m_flLip == 0.0) {
    (this->super_CBaseToggle).m_flLip = 4.0;
  }
  (this->super_CBaseToggle).m_toggle_state = TS_AT_BOTTOM;
  (this->super_CBaseToggle).m_vecPosition1.x = (peVar9->origin).x;
  (this->super_CBaseToggle).m_vecPosition1.y = (peVar9->origin).y;
  (this->super_CBaseToggle).m_vecPosition1.z = (peVar9->origin).z;
  fVar1 = (peVar9->movedir).x;
  fVar12 = (peVar9->movedir).y;
  fVar2 = (peVar9->movedir).z;
  fVar6 = (ABS(((peVar9->size).z - 2.0) * fVar2) +
          ABS(((peVar9->size).y - 2.0) * fVar12) + ABS(((peVar9->size).x - 2.0) * fVar1)) -
          (this->super_CBaseToggle).m_flLip;
  fVar3 = (this->super_CBaseToggle).m_vecPosition1.z;
  fVar4 = fVar2 * fVar6 + fVar3;
  fVar2 = (this->super_CBaseToggle).m_vecPosition1.y;
  fVar5 = fVar12 * fVar6 + fVar2;
  fVar12 = (this->super_CBaseToggle).m_vecPosition1.x;
  fVar1 = fVar6 * fVar1 + fVar12;
  (this->super_CBaseToggle).m_vecPosition2.x = fVar1;
  (this->super_CBaseToggle).m_vecPosition2.y = fVar5;
  (this->super_CBaseToggle).m_vecPosition2.z = fVar4;
  fVar4 = fVar4 - fVar3;
  fVar5 = fVar5 - fVar2;
  fVar1 = fVar1 - fVar12;
  fVar1 = fVar4 * fVar4 + fVar5 * fVar5 + fVar1 * fVar1;
  fVar12 = SQRT(fVar1);
  if (NAN(fVar12)) {
    fVar12 = sqrtf(fVar1);
    peVar9 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  if ((fVar12 < 1.0) || ((peVar9->spawnflags & 1) != 0)) {
    (this->super_CBaseToggle).m_vecPosition2.x = (this->super_CBaseToggle).m_vecPosition1.x;
    (this->super_CBaseToggle).m_vecPosition2.y = (this->super_CBaseToggle).m_vecPosition1.y;
    (this->super_CBaseToggle).m_vecPosition2.z = (this->super_CBaseToggle).m_vecPosition1.z;
  }
  fVar1 = (this->super_CBaseToggle).m_flWait;
  uVar10 = 0;
  if (fVar1 == -1.0) {
    uVar10 = (uint)!NAN(fVar1);
  }
  this->m_fStayPushed = uVar10;
  this->m_fRotating = 0;
  if ((peVar9->spawnflags & 0x100) == 0) {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __delta = 0;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.__pfn
         = ButtonUse;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.
    __delta = 0;
    return;
  }
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn
       = ButtonTouch;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
  __delta = 0;
  return;
}


// ButtonSound  @ 000b3cd0  (line 532)

char * ButtonSound(int sound)

{
  char *pcVar1;
  
  pcVar1 = "buttons/button9.wav";
  if ((uint)sound < 0x1a) {
    pcVar1 = *(char **)(CSWTCH_148 + sound * 4);
  }
  return pcVar1;
}


// DoSpark  @ 000b3cf0  (line 572)

void DoSpark(entvars_t *pev,Vector *location)

{
  float volume;
  longdouble lVar1;
  Vector local_18;
  
                    /* Unresolved local var: Vector tmp@[???]
                       Unresolved local var: float flVolume@[???] */
  local_18.z = (pev->size).z * 0.5 + location->z;
  local_18.y = (pev->size).y * 0.5 + location->y;
  local_18.x = (pev->size).x * 0.5 + location->x;
  UTIL_Sparks(&local_18);
  lVar1 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.25,0.75);
  volume = (float)((longdouble)0.4 * lVar1);
  lVar1 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
  switch((int)(lVar1 * (longdouble)6.0)) {
  case 0:
    EMIT_SOUND_DYN(pev->pContainingEntity,2,"buttons/spark1.wav",volume,0.8,0,100);
    return;
  case 1:
    EMIT_SOUND_DYN(pev->pContainingEntity,2,"buttons/spark2.wav",volume,0.8,0,100);
    return;
  case 2:
    EMIT_SOUND_DYN(pev->pContainingEntity,2,"buttons/spark3.wav",volume,0.8,0,100);
    return;
  case 3:
    EMIT_SOUND_DYN(pev->pContainingEntity,2,"buttons/spark4.wav",volume,0.8,0,100);
    return;
  case 4:
    EMIT_SOUND_DYN(pev->pContainingEntity,2,"buttons/spark5.wav",volume,0.8,0,100);
    return;
  case 5:
    EMIT_SOUND_DYN(pev->pContainingEntity,2,"buttons/spark6.wav",volume,0.8,0,100);
  }
  return;
}


// CBaseButton::ButtonSpark  @ 000b3f10  (line 589)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ButtonSpark(CBaseButton * this) */

void __thiscall CBaseButton::ButtonSpark(CBaseButton *this)

{
  float fVar1;
  entvars_t *peVar2;
  globalvars_t *pgVar3;
  longdouble lVar4;
  
  pgVar3 = gpGlobals;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = ButtonSpark;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  fVar1 = pgVar3->time;
  lVar4 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.5);
  peVar2->nextthink = (float)((longdouble)0.1 + lVar4 + (longdouble)fVar1);
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  DoSpark(peVar2,&peVar2->mins);
  return;
}


// CBaseButton::ButtonUse  @ 000b3750  (line 601)

/* DWARF original prototype: void ButtonUse(CBaseButton * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CBaseButton::ButtonUse
          (CBaseButton *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  entvars_t *peVar1;
  int iVar2;
  BOOL BVar3;
  
  if (((1 < (this->super_CBaseToggle).m_toggle_state - TS_GOING_UP) &&
      ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
         goal_activation & 8) == 0 || (value == 8.0)))) &&
     (((pActivator != (CBaseEntity *)0x0 &&
       (iVar2 = (*pActivator->_vptr_CBaseEntity[10])(pActivator), iVar2 != 2)) ||
      (BVar3 = ActivationSucceeded((CBaseEntity *)this,(CBasePlayer *)pActivator,(CBaseEntity *)0x0)
      , BVar3 != 0)))) {
    EHANDLE::operator=(&(this->super_CBaseToggle).m_hActivator,pActivator);
    if ((this->super_CBaseToggle).m_toggle_state != TS_AT_TOP) {
      peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      EMIT_SOUND_DYN(peVar1->pContainingEntity,2,gpGlobals->pStringBase + peVar1->noise,1.0,0.8,0,
                     100);
      iVar2 = UTIL_IsMasterTriggered((this->super_CBaseToggle).m_sMaster);
      if (iVar2 != 0) {
        ButtonActivate(this);
        return;
      }
      PlayLockSounds((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev,&this->m_ls,1,1);
      return;
    }
    if ((this->m_fStayPushed == 0) &&
       (peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev, (peVar1->spawnflags & 0x20) != 0)) {
      EMIT_SOUND_DYN(peVar1->pContainingEntity,2,gpGlobals->pStringBase + peVar1->noise,1.0,0.8,0,
                     100);
      ButtonReturn(this);
      return;
    }
  }
  return;
}


// CBaseButton::ButtonResponseToTouch  @ 000b3f90  (line 635)

/* DWARF original prototype: BUTTON_CODE ButtonResponseToTouch(CBaseButton * this) */

BUTTON_CODE __thiscall CBaseButton::ButtonResponseToTouch(CBaseButton *this)

{
  TOGGLE_STATE TVar1;
  BUTTON_CODE BVar2;
  
  BVar2 = BUTTON_NOTHING;
  TVar1 = (this->super_CBaseToggle).m_toggle_state;
  if (((1 < TVar1 - TS_GOING_UP) && (BVar2 = BUTTON_ACTIVATE, TVar1 == TS_AT_TOP)) &&
     (BVar2 = BUTTON_NOTHING, this->m_fStayPushed == 0)) {
    BVar2 = (uint)((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                  .pev)->spawnflags >> 4 & BUTTON_RETURN;
  }
  return BVar2;
}


// CBaseButton::ButtonTouch  @ 000b3570  (line 660)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ButtonTouch(CBaseButton * this, CBaseEntity * pOther) */

void __thiscall CBaseButton::ButtonTouch(CBaseButton *this,CBaseEntity *pOther)

{
  EHANDLE *this_00;
  TOGGLE_STATE TVar1;
  entvars_t *peVar2;
  edict_t *entity;
  globalvars_t *pgVar3;
  BOOL BVar4;
  int iVar5;
  CBaseEntity *pActivator;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  
                    /* Unresolved local var: BUTTON_CODE code@[???] */
  iVar6 = 7;
  bVar9 = gpGlobals->pStringBase + pOther->pev->classname == (char *)0x0;
  pcVar7 = gpGlobals->pStringBase + pOther->pev->classname;
  pcVar8 = "player";
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    bVar9 = *pcVar7 == *pcVar8;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  } while (bVar9);
  if (((bVar9) &&
      (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        goal_activation & 8) == 0)) &&
     (BVar4 = ActivationSucceeded((CBaseEntity *)this,(CBasePlayer *)pOther,(CBaseEntity *)0x0),
     BVar4 != 0)) {
                    /* Unresolved local var: BUTTON_CODE code@[DW_OP_reg3(EBX)] */
    this_00 = &(this->super_CBaseToggle).m_hActivator;
    EHANDLE::operator=(this_00,pOther);
    TVar1 = (this->super_CBaseToggle).m_toggle_state;
    if (1 < TVar1 - TS_GOING_UP) {
      iVar6 = 1;
      if (TVar1 == TS_AT_TOP) {
        if (this->m_fStayPushed != 0) {
          return;
        }
        if ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
             ->spawnflags & 0x20) == 0) {
          return;
        }
        iVar6 = 2;
      }
      iVar5 = UTIL_IsMasterTriggered((this->super_CBaseToggle).m_sMaster);
      pgVar3 = gpGlobals;
      if (iVar5 != 0) {
        peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev;
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch
        .__pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch
        .__delta = 0;
        entity = peVar2->pContainingEntity;
        if (iVar6 == 2) {
          EMIT_SOUND_DYN(entity,2,pgVar3->pStringBase + peVar2->noise,1.0,0.8,0,100);
          pActivator = EHANDLE::operator_CBaseEntity_(this_00);
          CBaseDelay::SUB_UseTargets((CBaseDelay *)this,pActivator,USE_TOGGLE,0.0);
          ButtonReturn(this);
          return;
        }
        EMIT_SOUND_DYN(entity,2,pgVar3->pStringBase + peVar2->noise,1.0,0.8,0,100);
        iVar6 = UTIL_IsMasterTriggered((this->super_CBaseToggle).m_sMaster);
        if (iVar6 != 0) {
          ButtonActivate(this);
          return;
        }
      }
      PlayLockSounds((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev,&this->m_ls,1,1);
    }
  }
  return;
}


// CBaseButton::ButtonActivate  @ 000b2cb0  (line 703)

/* DWARF original prototype: void ButtonActivate(CBaseButton * this) */

void __thiscall CBaseButton::ButtonActivate(CBaseButton *this)

{
  entvars_t *peVar1;
  Vector vecDestAngle;
  Vector vecDest;
  CBaseToggle *in_EAX;
  entvars_t *peVar2;
  vec_t vVar3;
  float in_stack_ffffffd4;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  vVar3 = 1.4013e-45;
  PlayLockSounds((in_EAX->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev,
                 (locksound_t *)
                 &in_EAX[1].super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pLink,0,1);
  in_EAX->m_toggle_state = TS_GOING_UP;
  peVar2 = (in_EAX->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar2->max_health != 0.0) {
    peVar2->health = peVar2->max_health;
    peVar2 = (in_EAX->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  }
  (in_EAX->m_pfnCallWhenMoveDone).__pfn = TriggerAndWait;
  peVar1 = in_EAX[1].super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (in_EAX->m_pfnCallWhenMoveDone).__delta = 0;
  if (peVar1 != (entvars_t *)0x0) {
    local_24 = (in_EAX->m_vecAngle2).x;
    local_20 = (in_EAX->m_vecAngle2).y;
    local_1c = (in_EAX->m_vecAngle2).z;
    vecDestAngle.y = peVar2->speed;
    vecDestAngle.x = (vec_t)&local_24;
    vecDestAngle.z = vVar3;
    CBaseToggle::AngularMove(in_EAX,vecDestAngle,in_stack_ffffffd4);
    return;
  }
  local_18 = (in_EAX->m_vecPosition2).x;
  local_14 = (in_EAX->m_vecPosition2).y;
  local_10 = (in_EAX->m_vecPosition2).z;
  vecDest.y = peVar2->speed;
  vecDest.x = (vec_t)&local_18;
  vecDest.z = vVar3;
  CBaseToggle::LinearMove(in_EAX,vecDest,in_stack_ffffffd4);
  return;
}


// CBaseButton::ButtonActivate  @ 000b3fd0  (line 704)

/* DWARF original prototype: void ButtonActivate(CBaseButton * this) */

void __thiscall CBaseButton::ButtonActivate(CBaseButton *this)

{
  entvars_t *peVar1;
  int iVar2;
  
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  EMIT_SOUND_DYN(peVar1->pContainingEntity,2,gpGlobals->pStringBase + peVar1->noise,1.0,0.8,0,100);
  iVar2 = UTIL_IsMasterTriggered((this->super_CBaseToggle).m_sMaster);
  if (iVar2 != 0) {
    ButtonActivate(this);
    return;
  }
  PlayLockSounds((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev,&this->m_ls,1,1);
  return;
}


// CBaseButton::TriggerAndWait  @ 000b2ac0  (line 737)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TriggerAndWait(CBaseButton * this) */

void __thiscall CBaseButton::TriggerAndWait(CBaseButton *this)

{
  int iVar1;
  entvars_t *peVar2;
  CBaseEntity *pActivator;
  
  iVar1 = UTIL_IsMasterTriggered((this->super_CBaseToggle).m_sMaster);
  if (iVar1 != 0) {
    iVar1 = this->m_fStayPushed;
    (this->super_CBaseToggle).m_toggle_state = TS_AT_TOP;
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    if ((iVar1 == 0) && ((peVar2->spawnflags & 0x20U) == 0)) {
      peVar2->nextthink = peVar2->ltime + (this->super_CBaseToggle).m_flWait;
      peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __pfn = ButtonReturn;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __delta = 0;
    }
    else if ((peVar2->spawnflags & 0x100U) == 0) {
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
      __pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
      __delta = 0;
    }
    else {
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
      __pfn = ButtonTouch;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
      __delta = 0;
    }
    peVar2->frame = 1.0;
    pActivator = EHANDLE::operator_CBaseEntity_(&(this->super_CBaseToggle).m_hActivator);
    CBaseDelay::SUB_UseTargets((CBaseDelay *)this,pActivator,USE_TOGGLE,0.0);
  }
  return;
}


// CBaseButton::ButtonReturn  @ 000b1d10  (line 774)

/* DWARF original prototype: void ButtonReturn(CBaseButton * this) */

void __thiscall CBaseButton::ButtonReturn(CBaseButton *this)

{
  int iVar1;
  Vector vecDestAngle;
  Vector vecDest;
  entvars_t *peVar2;
  vec_t in_stack_ffffffd0;
  float in_stack_ffffffd4;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar2->max_health != 0.0) {
    peVar2->health = peVar2->max_health;
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__pfn = ButtonBackHome;
  iVar1 = this->m_fRotating;
  (this->super_CBaseToggle).m_toggle_state = TS_GOING_DOWN;
  (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__delta = 0;
  if (iVar1 == 0) {
    local_24 = (this->super_CBaseToggle).m_vecPosition1.x;
    local_20 = (this->super_CBaseToggle).m_vecPosition1.y;
    local_1c = (this->super_CBaseToggle).m_vecPosition1.z;
    vecDest.y = peVar2->speed;
    vecDest.x = (vec_t)&local_24;
    vecDest.z = in_stack_ffffffd0;
    CBaseToggle::LinearMove(&this->super_CBaseToggle,vecDest,in_stack_ffffffd4);
  }
  else {
    local_18 = (this->super_CBaseToggle).m_vecAngle1.x;
    local_14 = (this->super_CBaseToggle).m_vecAngle1.y;
    local_10 = (this->super_CBaseToggle).m_vecAngle1.z;
    vecDestAngle.y = peVar2->speed;
    vecDestAngle.x = (vec_t)&local_18;
    vecDestAngle.z = in_stack_ffffffd0;
    CBaseToggle::AngularMove(&this->super_CBaseToggle,vecDestAngle,in_stack_ffffffd4);
  }
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->frame =
       0.0;
  return;
}


// CBaseButton::ButtonBackHome  @ 000b2e40  (line 796)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ButtonBackHome(CBaseButton * this) */

void __thiscall CBaseButton::ButtonBackHome(CBaseButton *this)

{
  int *piVar1;
  code *pcVar2;
  globalvars_t *pgVar3;
  int iVar4;
  entvars_t *peVar5;
  CBaseEntity *pCVar6;
  char *pcVar7;
  string_t sVar8;
  edict_t *peVar9;
  char *pcVar10;
  char *pcVar11;
  bool bVar12;
  byte bVar13;
  
  bVar13 = 0;
  peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).m_toggle_state = TS_AT_BOTTOM;
  if ((peVar5->spawnflags & 0x20) != 0) {
    pCVar6 = EHANDLE::operator_CBaseEntity_(&(this->super_CBaseToggle).m_hActivator);
    CBaseDelay::SUB_UseTargets((CBaseDelay *)this,pCVar6,USE_TOGGLE,0.0);
    peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  sVar8 = peVar5->target;
  if (sVar8 != 0) {
                    /* Unresolved local var: edict_t * pentTarget@[???]
                       Unresolved local var: CBaseEntity * pTarget@[DW_OP_reg6(ESI)] */
    peVar9 = (edict_t *)0x0;
    pcVar7 = gpGlobals->pStringBase;
    while( true ) {
      peVar9 = (*g_engfuncs.pfnFindEntityByString)(peVar9,"targetname",pcVar7 + sVar8);
      if (peVar9 == (edict_t *)0x0) break;
      iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar9);
      if (iVar4 == 0) break;
      iVar4 = 0xc;
      pcVar7 = gpGlobals->pStringBase;
      bVar12 = pcVar7 + (peVar9->v).classname == (char *)0x0;
      pcVar10 = pcVar7 + (peVar9->v).classname;
      pcVar11 = "multisource";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar12 = *pcVar10 == *pcVar11;
        pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
        pcVar11 = pcVar11 + (uint)bVar13 * -2 + 1;
      } while (bVar12);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((bVar12) && (piVar1 = peVar9->pvPrivateData, piVar1 != (int *)0x0)) {
        pcVar2 = *(code **)(*piVar1 + 0xb4);
        pCVar6 = EHANDLE::operator_CBaseEntity_(&(this->super_CBaseToggle).m_hActivator);
        (*pcVar2)(piVar1,pCVar6,this,3,0);
        pcVar7 = gpGlobals->pStringBase;
      }
      sVar8 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
              )->target;
    }
    peVar5 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  if ((peVar5->spawnflags & 0x100) == 0) {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __delta = 0;
  }
  else {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __pfn = ButtonTouch;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
    __delta = 0;
  }
  pgVar3 = gpGlobals;
  if ((peVar5->spawnflags & 0x40) != 0) {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = ButtonSpark;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
    peVar5->nextthink = pgVar3->time + 0.5;
  }
  return;
}


// func_rot_button  @ 000b4080  (line 855)

void func_rot_button(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x54c,pev);
  *puVar1 = &PTR__CRotButton_00179768;
  puVar1[1] = pev;
  return;
}


// CRotButton::Spawn  @ 000b1950  (line 858)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CRotButton * this) */

void __thiscall CRotButton::Spawn(CRotButton *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  string_t sVar8;
  entvars_t *peVar9;
  uint uVar10;
  char *pcVar11;
  float local_10;
  
                    /* Unresolved local var: char * pszSound@[DW_OP_reg6(ESI)] */
  pcVar11 = "buttons/button9.wav";
  uVar10 = (this->super_CBaseButton).m_sounds;
  if (uVar10 < 0x1a) {
    pcVar11 = *(char **)(CSWTCH_148 + uVar10 * 4);
  }
  (*g_engfuncs.pfnPrecacheSound)(pcVar11);
  peVar9 = (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  sVar8 = (*g_engfuncs.pfnAllocString)(pcVar11);
  peVar9->noise = sVar8;
  CBaseToggle::AxisDir
            ((this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev);
  peVar9 = (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar9->spawnflags & 2) != 0) {
    (peVar9->movedir).x = -(peVar9->movedir).x;
    (peVar9->movedir).y = -(peVar9->movedir).y;
    (peVar9->movedir).z = -(peVar9->movedir).z;
    peVar9 = (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  peVar9->movetype = 7;
  peVar9 = (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar9->solid = -(uint)((peVar9->spawnflags & 1U) == 0) & 4;
  peVar9 = (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar9->pContainingEntity,gpGlobals->pStringBase + peVar9->model);
  peVar9 = (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar9->speed == 0.0) {
    peVar9->speed = 40.0;
    peVar9 = (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  local_10 = (this->super_CBaseButton).super_CBaseToggle.m_flWait;
  if (local_10 == 0.0) {
    (this->super_CBaseButton).super_CBaseToggle.m_flWait = 1.0;
    local_10 = 1.0;
  }
  if (0.0 < peVar9->health) {
    peVar9->takedamage = 1.0;
    peVar9 = (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_10 = (this->super_CBaseButton).super_CBaseToggle.m_flWait;
  }
  fVar1 = (this->super_CBaseButton).super_CBaseToggle.m_flMoveDistance;
  (this->super_CBaseButton).super_CBaseToggle.m_toggle_state = TS_AT_BOTTOM;
  (this->super_CBaseButton).super_CBaseToggle.m_vecAngle1.x = (peVar9->angles).x;
  (this->super_CBaseButton).super_CBaseToggle.m_vecAngle1.y = (peVar9->angles).y;
  (this->super_CBaseButton).super_CBaseToggle.m_vecAngle1.z = (peVar9->angles).z;
  fVar2 = (peVar9->movedir).z;
  fVar3 = (peVar9->angles).z;
  fVar4 = (peVar9->movedir).y;
  fVar5 = (peVar9->angles).y;
  fVar6 = (peVar9->movedir).x;
  fVar7 = (peVar9->angles).x;
  (this->super_CBaseButton).m_fRotating = 1;
  (this->super_CBaseButton).super_CBaseToggle.m_vecAngle2.x = fVar1 * fVar6 + fVar7;
  (this->super_CBaseButton).super_CBaseToggle.m_vecAngle2.y = fVar4 * fVar1 + fVar5;
  (this->super_CBaseButton).super_CBaseToggle.m_vecAngle2.z = fVar2 * fVar1 + fVar3;
  uVar10 = 0;
  if (local_10 == -1.0) {
    uVar10 = (uint)!NAN(local_10);
  }
  (this->super_CBaseButton).m_fStayPushed = uVar10;
  if ((peVar9->spawnflags & 0x100) == 0) {
    (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnTouch.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
    (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnTouch.__delta = 0;
    (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__pfn = CBaseButton::ButtonUse;
    (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__delta = 0;
    return;
  }
  (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBaseButton::ButtonTouch;
  (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CMomentaryRotButton::ObjectCaps  @ 000b48c0  (line 930)

/* DWARF original prototype: int ObjectCaps(CMomentaryRotButton * this) */

int __thiscall CMomentaryRotButton::ObjectCaps(CMomentaryRotButton *this)

{
                    /* Unresolved local var: int flags@[???] */
  return -(uint)((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                  .pev)->spawnflags & 1U) == 0) & 0x10;
}


// CMomentaryRotButton::Restore  @ 000b2820  (line 967)

/* DWARF original prototype: int Restore(CMomentaryRotButton * this, CRestore * restore) */

int __thiscall CMomentaryRotButton::Restore(CMomentaryRotButton *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Restore(&this->super_CBaseToggle,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CMomentaryRotButton",this,m_SaveData,6);
  }
  return iVar2;
}


// CMomentaryRotButton::Save  @ 000b28e0  (line 967)

/* DWARF original prototype: int Save(CMomentaryRotButton * this, CSave * save) */

int __thiscall CMomentaryRotButton::Save(CMomentaryRotButton *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseToggle::Save(&this->super_CBaseToggle,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CMomentaryRotButton",this,m_SaveData,6);
  }
  return iVar2;
}


// momentary_rot_button  @ 000b40f0  (line 969)

void momentary_rot_button(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x53c,pev);
  *puVar1 = &PTR__CMomentaryRotButton_00179888;
  puVar1[1] = pev;
  return;
}


// CMomentaryRotButton::Spawn  @ 000b1b60  (line 972)

/* DWARF original prototype: void Spawn(CMomentaryRotButton * this) */

void __thiscall CMomentaryRotButton::Spawn(CMomentaryRotButton *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  entvars_t *peVar8;
  vec_t vVar9;
  string_t sVar10;
  char *pcVar11;
  
                    /* Unresolved local var: char * pszSound@[DW_OP_reg6(ESI)] */
  CBaseToggle::AxisDir
            ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev);
  peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar8->speed == 0.0) {
    peVar8->speed = 100.0;
    fVar1 = (this->super_CBaseToggle).m_flMoveDistance;
    peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  else {
    fVar1 = (this->super_CBaseToggle).m_flMoveDistance;
  }
  if (0.0 <= fVar1) {
    (this->m_start).x = (peVar8->angles).x;
    (this->m_start).y = (peVar8->angles).y;
    (this->m_start).z = (peVar8->angles).z;
    fVar2 = (peVar8->movedir).z;
    fVar3 = (peVar8->angles).z;
    fVar4 = (peVar8->movedir).y;
    fVar5 = (peVar8->angles).y;
    fVar6 = (peVar8->movedir).x;
    fVar7 = (peVar8->angles).x;
    this->m_direction = -1;
    (this->m_end).x = fVar1 * fVar6 + fVar7;
    (this->m_end).y = fVar4 * fVar1 + fVar5;
    (this->m_end).z = fVar2 * fVar1 + fVar3;
  }
  else {
    fVar2 = (peVar8->movedir).z;
    fVar3 = (peVar8->angles).z;
    fVar4 = (peVar8->movedir).y;
    fVar5 = (peVar8->angles).y;
    (this->m_start).x = (peVar8->movedir).x * fVar1 + (peVar8->angles).x;
    (this->m_start).y = fVar4 * fVar1 + fVar5;
    (this->m_start).z = fVar2 * fVar1 + fVar3;
    (this->m_end).x = (peVar8->angles).x;
    (this->m_end).y = (peVar8->angles).y;
    vVar9 = (peVar8->angles).z;
    (this->super_CBaseToggle).m_flMoveDistance = -fVar1;
    this->m_direction = 1;
    (this->m_end).z = vVar9;
  }
  pcVar11 = "buttons/button9.wav";
  peVar8->solid = -(peVar8->spawnflags & 1U) & 4;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->movetype
       = 7;
  peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar8,&peVar8->origin);
  peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar8->pContainingEntity,gpGlobals->pStringBase + peVar8->model);
  if ((uint)this->m_sounds < 0x1a) {
    pcVar11 = *(char **)(CSWTCH_148 + this->m_sounds * 4);
  }
  (*g_engfuncs.pfnPrecacheSound)(pcVar11);
  peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  sVar10 = (*g_engfuncs.pfnAllocString)(pcVar11);
  peVar8->noise = sVar10;
  this->m_lastUsed = 0;
  return;
}


// CMomentaryRotButton::KeyValue  @ 000b2fe0  (line 1008)

/* DWARF original prototype: void KeyValue(CMomentaryRotButton * this, KeyValueData * pkvd) */

void __thiscall CMomentaryRotButton::KeyValue(CMomentaryRotButton *this,KeyValueData *pkvd)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  double dVar6;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar2 = 0xc;
  pcVar3 = pkvd->szKeyName;
  pcVar4 = "returnspeed";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    dVar6 = strtod(pkvd->szValue,(char **)0x0);
    this->m_returnSpeed = (float)dVar6;
    pkvd->fHandled = 1;
  }
  else {
    iVar2 = 7;
    bVar5 = false;
    pcVar3 = pkvd->szKeyName;
    pcVar4 = "sounds";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      CBaseToggle::KeyValue(&this->super_CBaseToggle,pkvd);
      return;
    }
    lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
    this->m_sounds = lVar1;
    pkvd->fHandled = 1;
  }
  return;
}


// CMomentaryRotButton::PlaySound  @ 000b4160  (line 1024)

/* DWARF original prototype: void PlaySound(CMomentaryRotButton * this) */

void __thiscall CMomentaryRotButton::PlaySound(CMomentaryRotButton *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  EMIT_SOUND_DYN(peVar1->pContainingEntity,2,gpGlobals->pStringBase + peVar1->noise,1.0,0.8,0,100);
  return;
}


// CMomentaryRotButton::Use  @ 000b4650  (line 1032)

/* DWARF original prototype: void Use(CMomentaryRotButton * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CMomentaryRotButton::Use
          (CMomentaryRotButton *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  entvars_t *peVar1;
  float fVar2;
  Vector *angle1;
  Vector local_18;
  
                    /* Unresolved local var: Vector dest@[???]
                       Unresolved local var: float value1@[???] */
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar2 = CBaseToggle::AxisDelta(peVar1->spawnflags,&peVar1->angles,&this->m_start);
  peVar1->ideal_yaw = fVar2 / (this->super_CBaseToggle).m_flMoveDistance;
  UpdateAllButtons(this,((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                         super_CBaseEntity.pev)->ideal_yaw,1);
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  angle1 = &local_18;
  fVar2 = peVar1->nextthink - peVar1->ltime;
  local_18.z = (peVar1->avelocity).z * fVar2 + (peVar1->angles).z;
  local_18.y = (peVar1->avelocity).y * fVar2 + (peVar1->angles).y;
  local_18.x = fVar2 * (peVar1->avelocity).x + (peVar1->angles).x;
  fVar2 = CBaseToggle::AxisDelta(peVar1->spawnflags,angle1,&this->m_start);
  if (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      target != 0) {
    UpdateTarget((CMomentaryRotButton *)(fVar2 / (this->super_CBaseToggle).m_flMoveDistance),
                 (float)angle1);
  }
  return;
}


// CMomentaryRotButton::UpdateAllButtons  @ 000b4480  (line 1045)

/* DWARF original prototype: void UpdateAllButtons(CMomentaryRotButton * this, float value, int
   start) */

void __thiscall
CMomentaryRotButton::UpdateAllButtons(CMomentaryRotButton *this,float value,int start)

{
  char *pcVar1;
  int iVar2;
  edict_t *peVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
  peVar3 = (edict_t *)0x0;
  pcVar1 = gpGlobals->pStringBase;
  if (start == 0) {
                    /* Unresolved local var: edict_t * pentTarget@[???] */
    while (peVar3 = (*g_engfuncs.pfnFindEntityByString)
                              (peVar3,"target",
                               pcVar1 + ((this->super_CBaseToggle).super_CBaseAnimating.
                                         super_CBaseDelay.super_CBaseEntity.pev)->target),
          peVar3 != (edict_t *)0x0) {
      iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3);
      if (iVar2 == 0) {
        return;
      }
      iVar2 = 0x15;
      pcVar1 = gpGlobals->pStringBase;
      bVar6 = pcVar1 + (peVar3->v).classname == (char *)0x0;
      pcVar4 = pcVar1 + (peVar3->v).classname;
      pcVar5 = "momentary_rot_button";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
        pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
      } while (bVar6);
      if ((bVar6) && (peVar3->pvPrivateData != (CMomentaryRotButton *)0x0)) {
        UpdateSelfReturn(peVar3->pvPrivateData,value);
        pcVar1 = gpGlobals->pStringBase;
      }
    }
  }
  else {
    while (peVar3 = (*g_engfuncs.pfnFindEntityByString)
                              (peVar3,"target",
                               pcVar1 + ((this->super_CBaseToggle).super_CBaseAnimating.
                                         super_CBaseDelay.super_CBaseEntity.pev)->target),
          peVar3 != (edict_t *)0x0) {
      iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3);
      if (iVar2 == 0) {
        return;
      }
      iVar2 = 0x15;
      pcVar1 = gpGlobals->pStringBase;
      bVar6 = pcVar1 + (peVar3->v).classname == (char *)0x0;
      pcVar4 = pcVar1 + (peVar3->v).classname;
      pcVar5 = "momentary_rot_button";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
        pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
      } while (bVar6);
                    /* Unresolved local var: CMomentaryRotButton * pEntity@[???] */
      if ((bVar6) && (peVar3->pvPrivateData != (CMomentaryRotButton *)0x0)) {
        UpdateSelf(peVar3->pvPrivateData,value);
        pcVar1 = gpGlobals->pStringBase;
      }
    }
  }
  return;
}


// CMomentaryRotButton::UpdateSelf  @ 000b41c0  (line 1070)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void UpdateSelf(CMomentaryRotButton * this, float value) */

void __thiscall CMomentaryRotButton::UpdateSelf(CMomentaryRotButton *this,float value)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  float fVar4;
  bool bVar5;
  
                    /* Unresolved local var: BOOL fplaysound@[???] */
  bVar5 = this->m_lastUsed == 0;
  if (bVar5) {
    this->m_direction = -this->m_direction;
  }
  this->m_lastUsed = 1;
  peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  peVar3->nextthink = peVar3->ltime + 0.1;
  if (this->m_direction < 1) {
    if ((this->m_direction != 0) && (value <= 0.0)) {
      peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      (peVar3->avelocity).x = g_vecZero.x;
      (peVar3->avelocity).y = g_vecZero.y;
      (peVar3->avelocity).z = g_vecZero.z;
      peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      (peVar3->angles).x = (this->m_start).x;
      (peVar3->angles).y = (this->m_start).y;
      (peVar3->angles).z = (this->m_start).z;
      return;
    }
  }
  else if (1.0 <= value) {
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (peVar3->avelocity).x = g_vecZero.x;
    (peVar3->avelocity).y = g_vecZero.y;
    (peVar3->avelocity).z = g_vecZero.z;
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (peVar3->angles).x = (this->m_end).x;
    (peVar3->angles).y = (this->m_end).y;
    (peVar3->angles).z = (this->m_end).z;
    return;
  }
  if (bVar5) {
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    EMIT_SOUND_DYN(peVar3->pContainingEntity,2,gpGlobals->pStringBase + peVar3->noise,1.0,0.8,0,100)
    ;
  }
  peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar3->nextthink < peVar3->ltime) {
    peVar3->nextthink = peVar3->ltime + 0.1;
  }
  else {
    peVar3->nextthink = peVar3->nextthink + 0.1;
  }
  peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar4 = (float)this->m_direction * peVar3->speed;
  fVar1 = (peVar3->movedir).z;
  fVar2 = (peVar3->movedir).y;
  (peVar3->avelocity).x = fVar4 * (peVar3->movedir).x;
  (peVar3->avelocity).y = fVar2 * fVar4;
  (peVar3->avelocity).z = fVar1 * fVar4;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = Off;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  return;
}


// CMomentaryRotButton::UpdateTarget  @ 000b2db0  (line 1107)

/* DWARF original prototype: void UpdateTarget(CMomentaryRotButton * this, float value) */

void __thiscall CMomentaryRotButton::UpdateTarget(CMomentaryRotButton *this,float value)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  edict_t *peVar3;
  
  peVar3 = (edict_t *)0x0;
  while( true ) {
                    /* Unresolved local var: edict_t * pentTarget@[???]
                       Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)] */
    peVar3 = (*g_engfuncs.pfnFindEntityByString)
                       (peVar3,"targetname",
                        gpGlobals->pStringBase + *(int *)(*(int *)(in_EAX + 4) + 0x1c8));
    if (peVar3 == (edict_t *)0x0) {
      return;
    }
    iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3);
    if (iVar2 == 0) break;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    piVar1 = peVar3->pvPrivateData;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xb4))(piVar1);
    }
  }
  return;
}


// CMomentaryRotButton::UpdateTarget  @ 000b43a0  (line 1108)

/* DWARF original prototype: void UpdateTarget(CMomentaryRotButton * this, float value) */

void __thiscall CMomentaryRotButton::UpdateTarget(CMomentaryRotButton *this,float value)

{
  if (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      target != 0) {
    UpdateTarget((CMomentaryRotButton *)value,value);
    return;
  }
  return;
}


// CMomentaryRotButton::Off  @ 000b24b0  (line 1127)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Off(CMomentaryRotButton * this) */

void __thiscall CMomentaryRotButton::Off(CMomentaryRotButton *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->avelocity).x = g_vecZero.x;
  (peVar1->avelocity).y = g_vecZero.y;
  (peVar1->avelocity).z = g_vecZero.z;
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  this->m_lastUsed = 0;
  if (((peVar1->spawnflags & 0x10) != 0) && (0.0 < this->m_returnSpeed)) {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = Return;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
    peVar1->nextthink = peVar1->ltime + 0.1;
    this->m_direction = -1;
    return;
  }
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  return;
}


// CMomentaryRotButton::Return  @ 000b45b0  (line 1141)

/* DWARF original prototype: void Return(CMomentaryRotButton * this) */

void __thiscall CMomentaryRotButton::Return(CMomentaryRotButton *this)

{
  entvars_t *peVar1;
  CMomentaryRotButton *this_00;
  float fVar2;
  float in_stack_00000008;
  
                    /* Unresolved local var: float value@[???] */
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar2 = CBaseToggle::AxisDelta(peVar1->spawnflags,&peVar1->angles,&this->m_start);
  this_00 = (CMomentaryRotButton *)(fVar2 / (this->super_CBaseToggle).m_flMoveDistance);
  UpdateAllButtons(this,(float)this_00,0);
  if ((0.0 < (float)this_00) &&
     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      target != 0)) {
    UpdateTarget(this_00,in_stack_00000008);
    return;
  }
  return;
}


// CMomentaryRotButton::UpdateSelfReturn  @ 000b43d0  (line 1151)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void UpdateSelfReturn(CMomentaryRotButton * this, float value) */

void __thiscall CMomentaryRotButton::UpdateSelfReturn(CMomentaryRotButton *this,float value)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  float fVar4;
  
  peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (0.0 < value) {
    fVar4 = -this->m_returnSpeed;
    fVar1 = (peVar3->movedir).z;
    fVar2 = (peVar3->movedir).y;
    (peVar3->avelocity).x = fVar4 * (peVar3->movedir).x;
    (peVar3->avelocity).y = fVar2 * fVar4;
    (peVar3->avelocity).z = fVar1 * fVar4;
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    peVar3->nextthink = peVar3->ltime + 0.1;
    return;
  }
  (peVar3->avelocity).x = g_vecZero.x;
  (peVar3->avelocity).y = g_vecZero.y;
  (peVar3->avelocity).z = g_vecZero.z;
  peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (peVar3->angles).x = (this->m_start).x;
  (peVar3->angles).y = (this->m_start).y;
  (peVar3->angles).z = (this->m_start).z;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->nextthink
       = -1.0;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  return;
}


// CEnvSpark::Restore  @ 000b25e0  (line 1195)

/* DWARF original prototype: int Restore(CEnvSpark * this, CRestore * restore) */

int __thiscall CEnvSpark::Restore(CEnvSpark *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore(&this->super_CBaseEntity,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CEnvSpark",this,m_SaveData,1);
  }
  return iVar2;
}


// CEnvSpark::Save  @ 000b2700  (line 1195)

/* DWARF original prototype: int Save(CEnvSpark * this, CSave * save) */

int __thiscall CEnvSpark::Save(CEnvSpark *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save(&this->super_CBaseEntity,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CEnvSpark",this,m_SaveData,1);
  }
  return iVar2;
}


// env_spark  @ 000b4730  (line 1197)

void env_spark(entvars_t *pev)

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
  *puVar1 = &PTR__CEnvSpark_001799a8;
  puVar1[1] = pev;
  return;
}


// env_debris  @ 000b47a0  (line 1198)

void env_debris(entvars_t *pev)

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
  *puVar1 = &PTR__CEnvSpark_001799a8;
  puVar1[1] = pev;
  return;
}


// CEnvSpark::Spawn  @ 000b1660  (line 1201)

/* DWARF original prototype: void Spawn(CEnvSpark * this) */

void __thiscall CEnvSpark::Spawn(CEnvSpark *this)

{
  float fVar1;
  entvars_t *peVar2;
  uint uVar3;
  longdouble extraout_ST0;
  
  peVar2 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  (this->super_CBaseEntity).m_pfnUse.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *)0x0;
  (this->super_CBaseEntity).m_pfnUse.__delta = 0;
  uVar3 = peVar2->spawnflags;
  if ((uVar3 & 0x20) == 0) {
    (this->super_CBaseEntity).m_pfnThink.__pfn = SparkThink;
  }
  else if ((uVar3 & 0x40) == 0) {
    (this->super_CBaseEntity).m_pfnUse.__pfn = SparkStart;
  }
  else {
    (this->super_CBaseEntity).m_pfnThink.__pfn = SparkThink;
    (this->super_CBaseEntity).m_pfnUse.__pfn = SparkStop;
  }
  fVar1 = gpGlobals->time;
  (*g_engfuncs.pfnRandomFloat)(0.0,1.5);
  peVar2->nextthink = (float)((longdouble)0.1 + extraout_ST0 + (longdouble)fVar1);
  if (this->m_flDelay <= 0.0) {
    this->m_flDelay = 1.5;
  }
                    /* WARNING: Could not recover jumptable at 0x000b1713. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseEntity)._vptr_CBaseEntity[3])();
  return;
}


// CEnvSpark::Precache  @ 000b1730  (line 1228)

/* DWARF original prototype: void Precache(CEnvSpark * this) */

void __thiscall CEnvSpark::Precache(CEnvSpark *this)

{
  (*g_engfuncs.pfnPrecacheSound)("buttons/spark1.wav");
  (*g_engfuncs.pfnPrecacheSound)("buttons/spark2.wav");
  (*g_engfuncs.pfnPrecacheSound)("buttons/spark3.wav");
  (*g_engfuncs.pfnPrecacheSound)("buttons/spark4.wav");
  (*g_engfuncs.pfnPrecacheSound)("buttons/spark5.wav");
                    /* WARNING: Could not recover jumptable at 0x000b1785. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("buttons/spark6.wav");
  return;
}


// CEnvSpark::KeyValue  @ 000b3380  (line 1238)

/* DWARF original prototype: void KeyValue(CEnvSpark * this, KeyValueData * pkvd) */

void __thiscall CEnvSpark::KeyValue(CEnvSpark *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  double dVar6;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar1 = 9;
  pcVar3 = pkvd->szKeyName;
  pcVar2 = pcVar3;
  pcVar4 = "MaxDelay";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar5 = *pcVar2 == *pcVar4;
    pcVar2 = pcVar2 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    dVar6 = strtod(pkvd->szValue,(char **)0x0);
    this->m_flDelay = (float)dVar6;
    pkvd->fHandled = 1;
  }
  else {
    iVar1 = 6;
    bVar5 = false;
    pcVar2 = pcVar3;
    pcVar4 = "style";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      iVar1 = 7;
      pcVar2 = pcVar3;
      pcVar4 = "height";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pcVar2 == *pcVar4;
        pcVar2 = pcVar2 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (!bVar5) {
        iVar1 = 0xb;
        pcVar2 = pcVar3;
        pcVar4 = "killtarget";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar5 = *pcVar2 == *pcVar4;
          pcVar2 = pcVar2 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (!bVar5) {
          iVar1 = 7;
          pcVar2 = pcVar3;
          pcVar4 = "value1";
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar5 = *pcVar2 == *pcVar4;
            pcVar2 = pcVar2 + 1;
            pcVar4 = pcVar4 + 1;
          } while (bVar5);
          if (!bVar5) {
            iVar1 = 7;
            pcVar2 = pcVar3;
            pcVar4 = "value2";
            do {
              if (iVar1 == 0) break;
              iVar1 = iVar1 + -1;
              bVar5 = *pcVar2 == *pcVar4;
              pcVar2 = pcVar2 + 1;
              pcVar4 = pcVar4 + 1;
            } while (bVar5);
            if (!bVar5) {
              iVar1 = 7;
              pcVar2 = "value3";
              do {
                if (iVar1 == 0) break;
                iVar1 = iVar1 + -1;
                bVar5 = *pcVar3 == *pcVar2;
                pcVar3 = pcVar3 + 1;
                pcVar2 = pcVar2 + 1;
              } while (bVar5);
              if (!bVar5) {
                CBaseEntity::KeyValue(&this->super_CBaseEntity,pkvd);
                return;
              }
            }
          }
        }
      }
    }
    pkvd->fHandled = 1;
  }
  return;
}


// CEnvSpark::SparkThink  @ 000b3ea0  (line 1256)

/* DWARF original prototype: void SparkThink(CEnvSpark * this) */

void __thiscall CEnvSpark::SparkThink(CEnvSpark *this)

{
  float fVar1;
  entvars_t *peVar2;
  longdouble lVar3;
  
  fVar1 = gpGlobals->time;
  peVar2 = (this->super_CBaseEntity).pev;
  lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,this->m_flDelay);
  peVar2->nextthink = (float)((longdouble)(fVar1 + 0.1) + lVar3);
  peVar2 = (this->super_CBaseEntity).pev;
  DoSpark(peVar2,&peVar2->origin);
  return;
}


// CEnvSpark::SparkStart  @ 000b1790  (line 1262)

/* DWARF original prototype: void SparkStart(CEnvSpark * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CEnvSpark::SparkStart
          (CEnvSpark *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,float value
          )

{
  float fVar1;
  entvars_t *peVar2;
  globalvars_t *pgVar3;
  longdouble lVar4;
  
  pgVar3 = gpGlobals;
  peVar2 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnUse.__pfn = SparkStop;
  (this->super_CBaseEntity).m_pfnUse.__delta = 0;
  (this->super_CBaseEntity).m_pfnThink.__pfn = SparkThink;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  fVar1 = pgVar3->time;
  lVar4 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,this->m_flDelay);
  peVar2->nextthink = (float)((longdouble)0.1 + lVar4 + (longdouble)fVar1);
  return;
}


// CEnvSpark::SparkStop  @ 000b1800  (line 1269)

/* DWARF original prototype: void SparkStop(CEnvSpark * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CEnvSpark::SparkStop
          (CEnvSpark *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,float value
          )

{
  (this->super_CBaseEntity).m_pfnUse.__pfn = SparkStart;
  (this->super_CBaseEntity).m_pfnUse.__delta = 0;
  (this->super_CBaseEntity).m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  return;
}


// button_target  @ 000b4810  (line 1287)

void button_target(entvars_t *pev)

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
  *puVar1 = &PTR__CButtonTarget_00179ac8;
  puVar1[1] = pev;
  return;
}


// CButtonTarget::Spawn  @ 000b1830  (line 1290)

/* DWARF original prototype: void Spawn(CButtonTarget * this) */

void __thiscall CButtonTarget::Spawn(CButtonTarget *this)

{
  entvars_t *peVar1;
  
  ((this->super_CBaseEntity).pev)->movetype = 7;
  ((this->super_CBaseEntity).pev)->solid = 4;
  peVar1 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar1->pContainingEntity,gpGlobals->pStringBase + peVar1->model);
  ((this->super_CBaseEntity).pev)->takedamage = 1.0;
  peVar1 = (this->super_CBaseEntity).pev;
  if ((peVar1->spawnflags & 2) != 0) {
    peVar1->frame = 1.0;
  }
  return;
}


// CButtonTarget::Use  @ 000b2540  (line 1301)

/* DWARF original prototype: void Use(CButtonTarget * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CButtonTarget::Use(CButtonTarget *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType
                  ,float value)

{
  entvars_t *peVar1;
  int iVar2;
  
  iVar2 = CBaseEntity::ShouldToggle
                    (&this->super_CBaseEntity,useType,(int)((this->super_CBaseEntity).pev)->frame);
  if (iVar2 == 0) {
    return;
  }
  peVar1 = (this->super_CBaseEntity).pev;
  peVar1->frame = 1.0 - peVar1->frame;
  pCaller = (CBaseEntity *)(uint)(((this->super_CBaseEntity).pev)->frame != 0.0);
  CBaseEntity::SUB_UseTargets(&this->super_CBaseEntity,pActivator,(USE_TYPE)pCaller,0.0);
  return;
}


// CButtonTarget::ObjectCaps  @ 000b18b0  (line 1316)

/* DWARF original prototype: int ObjectCaps(CButtonTarget * this) */

int __thiscall CButtonTarget::ObjectCaps(CButtonTarget *this)

{
                    /* Unresolved local var: int caps@[???] */
  return -(((this->super_CBaseEntity).pev)->spawnflags & 1U) & 8;
}


// CButtonTarget::TakeDamage  @ 000b18d0  (line 1324)

/* DWARF original prototype: int TakeDamage(CButtonTarget * this, entvars_t * pevInflictor,
   entvars_t * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CButtonTarget::TakeDamage
          (CButtonTarget *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  _func_int_varargs *p_Var1;
  edict_t *peVar2;
  void *pvVar3;
  
  p_Var1 = (this->super_CBaseEntity)._vptr_CBaseEntity[0x2d];
  peVar2 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg0(EAX)] */
  if (peVar2 == (edict_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar2 == (edict_t *)0x0) {
      pvVar3 = (void *)0x0;
      goto LAB_000b18f8;
    }
  }
  pvVar3 = peVar2->pvPrivateData;
LAB_000b18f8:
  (*p_Var1)(this,pvVar3,this,3,0);
  return 1;
}


