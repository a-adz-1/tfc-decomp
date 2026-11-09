// Ghidra decompilation of functions from tfc/buttons.cpp
// 68 functions, ordered by original source line

// CEnvGlobal::~CEnvGlobal  @ 00075070  (line 38)

/* DWARF original prototype: void ~CEnvGlobal(CEnvGlobal * this, int __in_chrg) */

void __thiscall CEnvGlobal::~CEnvGlobal(CEnvGlobal *this,int __in_chrg)

{
  return;
}


// CEnvGlobal::Restore  @ 00072bb0  (line 62)

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


// CEnvGlobal::Save  @ 00072cd0  (line 62)

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


// env_global  @ 00073a10  (line 64)

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
  *puVar1 = &PTR__CEnvGlobal_00148920;
  puVar1[1] = pev;
  return;
}


// CEnvGlobal::KeyValue  @ 00071750  (line 67)

/* DWARF original prototype: void KeyValue(CEnvGlobal * this, KeyValueData * pkvd) */

void __thiscall CEnvGlobal::KeyValue(CEnvGlobal *this,KeyValueData *pkvd)

{
  long lVar1;
  string_t sVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  
  bVar7 = &stack0x00000000 < (undefined1 *)0x2c;
  bVar9 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar3 = 0xc;
  pbVar5 = (byte *)pkvd->szKeyName;
  pkvd->fHandled = 1;
  pbVar4 = pbVar5;
  pbVar6 = (byte *)0x1486c8;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pbVar4 < *pbVar6;
    bVar9 = *pbVar4 == *pbVar6;
    pbVar4 = pbVar4 + 1;
    pbVar6 = pbVar6 + 1;
  } while (bVar9);
  bVar8 = (!bVar7 && !bVar9) < bVar7;
  if ((!bVar7 && !bVar9) == bVar7) {
    sVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    this->m_globalstate = sVar2;
    return;
  }
  iVar3 = 0xc;
  bVar7 = false;
  pbVar4 = pbVar5;
  pbVar6 = (byte *)0x1486d6;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar8 = *pbVar4 < *pbVar6;
    bVar7 = *pbVar4 == *pbVar6;
    pbVar4 = pbVar4 + 1;
    pbVar6 = pbVar6 + 1;
  } while (bVar7);
  if ((!bVar8 && !bVar7) == bVar8) {
    lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
    this->m_triggermode = lVar1;
    return;
  }
  iVar3 = 0xd;
  bVar7 = false;
  pbVar4 = (byte *)0x1486e4;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pbVar5 == *pbVar4;
    pbVar5 = pbVar5 + 1;
    pbVar4 = pbVar4 + 1;
  } while (bVar7);
  if (!bVar7) {
    CBaseEntity::KeyValue((CBaseEntity *)this,pkvd);
    return;
  }
  lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
  this->m_initialstate = lVar1;
  return;
}


// CEnvGlobal::Spawn  @ 000726d0  (line 81)

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
                    /* WARNING: Could not recover jumptable at 0x00072751. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnRemoveEntity)
            (((this->super_CPointEntity).super_CBaseEntity.pev)->pContainingEntity);
  return;
}


// CEnvGlobal::Use  @ 00071870  (line 96)

/* DWARF original prototype: void Use(CEnvGlobal * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CEnvGlobal::Use(CEnvGlobal *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
               float value)

{
  int iVar1;
  GLOBALESTATE state;
  globalentity_t *pgVar2;
  
                    /* Unresolved local var: GLOBALESTATE oldState@[???]
                       Unresolved local var: GLOBALESTATE newState@[???] */
  state = CGlobalState::EntityGetState(&gGlobalState,this->m_globalstate);
  iVar1 = this->m_triggermode;
  if (iVar1 == 1) {
    state = GLOBAL_ON;
  }
  else if (iVar1 == 2) {
    state = GLOBAL_DEAD;
  }
  else if ((iVar1 == 0) || (state == GLOBAL_ON)) {
    state = GLOBAL_OFF;
  }
  else if (state == GLOBAL_OFF) {
    state = GLOBAL_ON;
  }
  pgVar2 = CGlobalState::Find(&gGlobalState,this->m_globalstate);
  if (pgVar2 == (globalentity_t *)0x0) {
    CGlobalState::EntityAdd(&gGlobalState,this->m_globalstate,gpGlobals->mapname,state);
    return;
  }
  CGlobalState::EntitySetState(&gGlobalState,this->m_globalstate,state);
  return;
}


// CMultiSource::Restore  @ 00072b50  (line 141)

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


// CMultiSource::Save  @ 00072c70  (line 141)

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


// multisource  @ 00073a80  (line 143)

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
  *puVar1 = &PTR__CMultiSource_00148a2c;
  puVar1[1] = pev;
  return;
}


// CMultiSource::KeyValue  @ 00071660  (line 149)

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
              if (bVar6) {
                sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                this->m_globalstate = sVar1;
                pkvd->fHandled = 1;
                return;
              }
              CBaseEntity::KeyValue((CBaseEntity *)this,pkvd);
              return;
            }
          }
        }
      }
    }
  }
  pkvd->fHandled = 1;
  return;
}


// CMultiSource::Spawn  @ 00071160  (line 169)

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


// CMultiSource::Use  @ 00073170  (line 180)

/* DWARF original prototype: void Use(CMultiSource * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CMultiSource::Use(CMultiSource *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
                 float value)

{
  _func_int_varargs *p_Var1;
  int iVar2;
  CBaseEntity *pCVar3;
  int iVar4;
  GLOBALESTATE GVar5;
  entvars_t *peVar6;
  int iVar7;
  EHANDLE *this_00;
  
                    /* Unresolved local var: int i@[???] */
  iVar7 = 0;
  this_00 = this->m_rgEntities;
  do {
    iVar4 = this->m_iTotal;
    if (iVar4 <= iVar7) {
      if (iVar7 <= iVar4) goto LAB_000731b6;
      goto LAB_00073296;
    }
    iVar7 = iVar7 + 1;
    pCVar3 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
    this_00 = this_00 + 1;
  } while (pCVar3 != pCaller);
  iVar4 = this->m_iTotal;
  if (iVar4 < iVar7) {
LAB_00073296:
                    /* WARNING: Could not recover jumptable at 0x000732c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnAlertMessage)(at_console,"MultiSrc:Used by non member %s.\n");
    return;
  }
LAB_000731b6:
  this->m_rgTriggered[iVar7 + -1] = this->m_rgTriggered[iVar7 + -1] ^ 1;
  p_Var1 = (this->super_CPointEntity).super_CBaseEntity._vptr_CBaseEntity[0x12];
  if (p_Var1 == IsTriggered) {
                    /* Unresolved local var: int i@[???] */
    peVar6 = (this->super_CPointEntity).super_CBaseEntity.pev;
    if ((peVar6->spawnflags & 1) != 0) {
      return;
    }
    if (iVar4 < 1) {
      if (iVar4 != 0) {
        return;
      }
    }
    else {
      if (this->m_rgTriggered[0] == 0) {
        return;
      }
      iVar7 = 0;
      while (iVar7 + 1 != iVar4) {
        iVar2 = iVar7 + 1;
        iVar7 = iVar7 + 1;
        if (this->m_rgTriggered[iVar2] == 0) {
          return;
        }
      }
    }
                    /* Unresolved local var: int i@[???] */
    if (this->m_globalstate == 0) goto LAB_00073222;
    GVar5 = CGlobalState::EntityGetState(&gGlobalState,this->m_globalstate);
    if (GVar5 != GLOBAL_ON) {
      return;
    }
  }
  else {
    iVar7 = (*p_Var1)(this);
    if (iVar7 == 0) {
      return;
    }
  }
  iVar4 = this->m_iTotal;
  peVar6 = (this->super_CPointEntity).super_CBaseEntity.pev;
LAB_00073222:
                    /* Unresolved local var: USE_TYPE useType@[???] */
  (*g_engfuncs.pfnAlertMessage)
            (at_aiconsole,"Multisource %s enabled (%d inputs)\n",
             gpGlobals->pStringBase + peVar6->targetname,iVar4);
  CBaseEntity::SUB_UseTargets
            ((CBaseEntity *)this,(CBaseEntity *)0x0,(-(uint)(this->m_globalstate == 0) & 2) + USE_ON
             ,0.0);
  return;
}


// CMultiSource::IsTriggered  @ 00072a70  (line 212)

/* DWARF original prototype: int IsTriggered(CMultiSource * this) */

int __thiscall CMultiSource::IsTriggered(CMultiSource *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  GLOBALESTATE GVar4;
  
                    /* Unresolved local var: int i@[???] */
  if ((((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 1) == 0) {
    iVar1 = this->m_iTotal;
    if (iVar1 < 1) {
      if (iVar1 == 0) {
LAB_00072aaf:
                    /* Unresolved local var: int i@[???] */
        if ((this->m_globalstate == 0) ||
           (GVar4 = CGlobalState::EntityGetState(&gGlobalState,this->m_globalstate),
           GVar4 == GLOBAL_ON)) {
          return 1;
        }
      }
    }
    else if (this->m_rgTriggered[0] != 0) {
      iVar3 = 0;
      do {
        if (iVar1 == iVar3 + 1) goto LAB_00072aaf;
        iVar2 = iVar3 + 1;
        iVar3 = iVar3 + 1;
      } while (this->m_rgTriggered[iVar2] != 0);
    }
  }
  return 0;
}


// CMultiSource::Register  @ 00072d30  (line 237)

/* DWARF original prototype: void Register(CMultiSource * this) */

void __thiscall CMultiSource::Register(CMultiSource *this)

{
  int *piVar1;
  entvars_t *peVar2;
  CBaseEntity *pCVar3;
  string_t sVar4;
  _2globalvars_t *p1Var5;
  uint uVar6;
  uint uVar7;
  edict_t *peVar8;
  int iVar9;
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
  uVar6 = 0;
  do {
    uVar7 = uVar6;
    *(undefined4 *)((int)&pEVar11->m_pent + uVar7) = 0;
    *(undefined4 *)((int)&pEVar11->m_serialnumber + uVar7) = 0;
    uVar6 = uVar7 + 8;
  } while (uVar7 + 8 < (uVar10 & 0xfffffff8));
  puVar12 = (undefined4 *)((int)&pEVar11[1].m_pent + uVar7);
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
  p1Var5 = gpGlobals;
  peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
  (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_DoNothing;
  (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar8 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"target",p1Var5->pStringBase + peVar2->targetname);
  while (((peVar8 != (edict_t *)0x0 &&
          (iVar9 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar8), iVar9 != 0)) &&
         (this->m_iTotal < 0x20))) {
                    /* Unresolved local var: CBaseEntity * pTarget@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    pCVar3 = peVar8->pvPrivateData;
    if (pCVar3 != (CBaseEntity *)0x0) {
      iVar9 = this->m_iTotal;
      this->m_iTotal = iVar9 + 1;
      EHANDLE::operator=(this->m_rgEntities + iVar9,pCVar3);
    }
    peVar8 = (*g_engfuncs.pfnFindEntityByString)
                       (peVar8,"target",
                        gpGlobals->pStringBase +
                        ((this->super_CPointEntity).super_CBaseEntity.pev)->targetname);
  }
  peVar8 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"classname","multi_manager");
  while (((peVar8 != (edict_t *)0x0 &&
          (iVar9 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar8), iVar9 != 0)) &&
         (this->m_iTotal < 0x20))) {
                    /* Unresolved local var: CBaseEntity * pTarget@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    pCVar3 = peVar8->pvPrivateData;
    if (pCVar3 != (CBaseEntity *)0x0) {
      sVar4 = ((this->super_CPointEntity).super_CBaseEntity.pev)->targetname;
      if (pCVar3->_vptr_CBaseEntity[0x25] == CBaseEntity::HasTarget) {
        iVar9 = strcmp(gpGlobals->pStringBase + sVar4,
                       gpGlobals->pStringBase + pCVar3->pev->targetname);
        uVar10 = (uint)(iVar9 == 0);
      }
      else {
        uVar10 = (*pCVar3->_vptr_CBaseEntity[0x25])(pCVar3,sVar4);
      }
      if (uVar10 != 0) {
        iVar9 = this->m_iTotal;
        this->m_iTotal = iVar9 + 1;
        EHANDLE::operator=(this->m_rgEntities + iVar9,pCVar3);
      }
    }
    peVar8 = (*g_engfuncs.pfnFindEntityByString)(peVar8,"classname","multi_manager");
  }
  piVar1 = &((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags;
  *piVar1 = *piVar1 & 0xfffffffe;
  return;
}


// CBaseButton::Restore  @ 00072950  (line 287)

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


// CBaseButton::Save  @ 00072a10  (line 287)

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


// CBaseButton::Precache  @ 000711b0  (line 290)

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
      pcVar3 = *(char **)(CSWTCH_257 + (uint)bVar1 * 4);
    }
    (*g_engfuncs.pfnPrecacheSound)(pcVar3);
    sVar2 = (*g_engfuncs.pfnAllocString)(pcVar3);
    (this->m_ls).sLockedSound = sVar2;
  }
  bVar1 = this->m_bUnlockedSound;
  if (bVar1 != 0) {
    pcVar3 = "buttons/button9.wav";
    if (bVar1 < 0x1a) {
      pcVar3 = *(char **)(CSWTCH_257 + (uint)bVar1 * 4);
    }
    (*g_engfuncs.pfnPrecacheSound)(pcVar3);
    sVar2 = (*g_engfuncs.pfnAllocString)(pcVar3);
    (this->m_ls).sUnlockedSound = sVar2;
  }
  switch(this->m_bLockedSentence) {
  default:
    (this->m_ls).sLockedSentence = 0;
    goto LAB_000712d4;
  case '\x01':
    pcVar3 = "NA";
    break;
  case '\x02':
    pcVar3 = "ND";
    break;
  case '\x03':
    pcVar3 = "NF";
    break;
  case '\x04':
    pcVar3 = "NFIRE";
    break;
  case '\x05':
    pcVar3 = "NCHEM";
    break;
  case '\x06':
    pcVar3 = "NRAD";
    break;
  case '\a':
    pcVar3 = "NCON";
    break;
  case '\b':
    pcVar3 = "NH";
    break;
  case '\t':
    pcVar3 = "NG";
  }
  (this->m_ls).sLockedSentence = (int)pcVar3 - (int)gpGlobals->pStringBase;
LAB_000712d4:
  switch(this->m_bUnlockedSentence) {
  default:
    (this->m_ls).sUnlockedSentence = 0;
    return;
  case '\x01':
    pcVar3 = "EA";
    break;
  case '\x02':
    pcVar3 = "ED";
    break;
  case '\x03':
    pcVar3 = "EF";
    break;
  case '\x04':
    pcVar3 = "EFIRE";
    break;
  case '\x05':
    pcVar3 = "ECHEM";
    break;
  case '\x06':
    pcVar3 = "ERAD";
    break;
  case '\a':
    pcVar3 = "ECON";
    break;
  case '\b':
    pcVar3 = "EH";
  }
  (this->m_ls).sUnlockedSentence = (int)pcVar3 - (int)gpGlobals->pStringBase;
  return;
}


// CBaseButton::KeyValue  @ 00071950  (line 356)

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


// CBaseButton::TakeDamage  @ 00073f90  (line 395)

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
  Vector vecDestAngle;
  Vector vecDest;
  BOOL BVar2;
  CBaseEntity *pCVar3;
  entvars_t *peVar4;
  CBasePlayer *AP;
  edict_t *peVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  bool bVar10;
  vec_t vVar11;
  float flSpeed;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: BUTTON_CODE code@[???] */
  TVar1 = (this->super_CBaseToggle).m_toggle_state;
  if (1 < TVar1 - TS_GOING_UP) {
    if (TVar1 == TS_AT_TOP) {
      if (this->m_fStayPushed != 0) {
        return 0;
      }
      iVar7 = 2;
      if ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
           spawnflags & 0x20) == 0) {
        return 0;
      }
    }
    else {
      iVar7 = 1;
    }
    if (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
         goal_activation & 8) == 0) {
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
        peVar5 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pAttacker@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
        if ((peVar5 == (edict_t *)0x0) &&
           (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 == (edict_t *)0x0)) {
          AP = (CBasePlayer *)0x0;
        }
        else {
          AP = peVar5->pvPrivateData;
        }
        BVar2 = ActivationSucceeded((CBaseEntity *)this,AP,(CBaseEntity *)0x0);
        if (BVar2 == 0) {
          return 0;
        }
      }
      peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      peVar4->health = peVar4->health - flDamage;
      if (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
          health <= 0.0) {
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch
        .__pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
        (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch
        .__delta = 0;
        peVar5 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        if ((peVar5 == (edict_t *)0x0) &&
           (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 == (edict_t *)0x0)) {
          pCVar3 = (CBaseEntity *)0x0;
        }
        else {
          pCVar3 = peVar5->pvPrivateData;
        }
        this_00 = &(this->super_CBaseToggle).m_hActivator;
        EHANDLE::operator=(this_00,pCVar3);
        iVar6 = EHANDLE::operator_int(this_00);
        if (iVar6 != 0) {
          if (iVar7 == 2) {
            peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev;
            flSpeed = 0.8;
            vVar11 = 1.0;
            EMIT_SOUND_DYN(peVar4->pContainingEntity,2,gpGlobals->pStringBase + peVar4->noise,1.0,
                           0.8,0,100);
            peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev;
            if ((peVar4->spawnflags & 0x20) == 0) {
              pCVar3 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
              vVar11 = 0.0;
              CBaseDelay::SUB_UseTargets((CBaseDelay *)this,pCVar3,USE_TOGGLE,0.0);
              peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev;
            }
            if (peVar4->max_health != 0.0) {
              peVar4->health = peVar4->max_health;
              peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                       super_CBaseEntity.pev;
            }
            iVar7 = this->m_fRotating;
            (this->super_CBaseToggle).m_toggle_state = TS_GOING_DOWN;
            (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__pfn = ButtonBackHome;
            (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__delta = 0;
            if (iVar7 == 0) {
              local_28 = (this->super_CBaseToggle).m_vecPosition1.x;
              local_24 = (this->super_CBaseToggle).m_vecPosition1.y;
              local_20 = (this->super_CBaseToggle).m_vecPosition1.z;
              vecDest.y = peVar4->speed;
              vecDest.x = (vec_t)&local_28;
              vecDest.z = vVar11;
              CBaseToggle::LinearMove(&this->super_CBaseToggle,vecDest,flSpeed);
            }
            else {
              local_28 = (this->super_CBaseToggle).m_vecAngle1.x;
              local_24 = (this->super_CBaseToggle).m_vecAngle1.y;
              local_20 = (this->super_CBaseToggle).m_vecAngle1.z;
              vecDestAngle.y = peVar4->speed;
              vecDestAngle.x = (vec_t)&local_28;
              vecDestAngle.z = vVar11;
              CBaseToggle::AngularMove(&this->super_CBaseToggle,vecDestAngle,flSpeed);
            }
            ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
            ->frame = 0.0;
          }
          else {
            ButtonActivate(this);
          }
        }
      }
    }
  }
  return 0;
}


// func_button  @ 00073af0  (line 457)

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
  *puVar1 = &PTR__CBaseButton_00148b38;
  puVar1[1] = pev;
  return;
}


// CBaseButton::Spawn  @ 00071dc0  (line 461)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CBaseButton * this) */

void __thiscall CBaseButton::Spawn(CBaseButton *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  _2globalvars_t *p1Var4;
  string_t sVar5;
  entvars_t *peVar6;
  uint uVar7;
  code *pcVar8;
  char *pcVar9;
  float fVar10;
  
                    /* Unresolved local var: char * pszSound@[DW_OP_reg6(ESI)] */
  pcVar9 = "buttons/button9.wav";
  if ((uint)this->m_sounds < 0x1a) {
    pcVar9 = *(char **)(CSWTCH_257 + this->m_sounds * 4);
  }
  (*g_engfuncs.pfnPrecacheSound)(pcVar9);
  peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  sVar5 = (*g_engfuncs.pfnAllocString)(pcVar9);
  peVar6->noise = sVar5;
  (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[3])(this);
  p1Var4 = gpGlobals;
  peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar6->spawnflags & 0x40) != 0) {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = ButtonSpark;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
    peVar6->nextthink = p1Var4->time + 0.5;
    peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  SetMovedir(peVar6);
  p1Var4 = gpGlobals;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->movetype
       = 7;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 4
  ;
  peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar6->pContainingEntity,p1Var4->pStringBase + peVar6->model);
  peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar6->speed == 0.0) {
    peVar6->speed = 40.0;
    peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  peVar6->max_health = 0.0;
  peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (0.0 < peVar6->health) {
    peVar6->takedamage = 1.0;
    peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    peVar6->max_health = peVar6->health;
    peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  if ((this->super_CBaseToggle).m_flWait == 0.0) {
    (this->super_CBaseToggle).m_flWait = 1.0;
  }
  fVar1 = (this->super_CBaseToggle).m_flLip;
  if (fVar1 == 0.0) {
    (this->super_CBaseToggle).m_flLip = 4.0;
    fVar1 = 4.0;
  }
  (this->super_CBaseToggle).m_toggle_state = TS_AT_BOTTOM;
  (this->super_CBaseToggle).m_vecPosition1.x = (peVar6->origin).x;
  (this->super_CBaseToggle).m_vecPosition1.y = (peVar6->origin).y;
  (this->super_CBaseToggle).m_vecPosition1.z = (peVar6->origin).z;
  fVar10 = (peVar6->movedir).x;
  fVar2 = (peVar6->movedir).y;
  fVar3 = (peVar6->movedir).z;
  fVar1 = (ABS(((peVar6->size).z - 2.0) * fVar3) +
          ABS(((peVar6->size).y - 2.0) * fVar2) + ABS(((peVar6->size).x - 2.0) * fVar10)) - fVar1;
  fVar3 = fVar3 * fVar1 + (this->super_CBaseToggle).m_vecPosition1.z;
  fVar2 = fVar2 * fVar1 + (this->super_CBaseToggle).m_vecPosition1.y;
  fVar1 = fVar1 * fVar10 + (this->super_CBaseToggle).m_vecPosition1.x;
  (this->super_CBaseToggle).m_vecPosition2.x = fVar1;
  (this->super_CBaseToggle).m_vecPosition2.y = fVar2;
  (this->super_CBaseToggle).m_vecPosition2.z = fVar3;
  fVar3 = fVar3 - (this->super_CBaseToggle).m_vecPosition1.z;
  fVar2 = fVar2 - (this->super_CBaseToggle).m_vecPosition1.y;
  fVar1 = fVar1 - (this->super_CBaseToggle).m_vecPosition1.x;
  fVar1 = fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1;
  fVar10 = SQRT(fVar1);
  if (NAN(fVar10)) {
    fVar10 = sqrtf(fVar1);
    peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  if ((fVar10 < 1.0) || ((peVar6->spawnflags & 1) != 0)) {
    (this->super_CBaseToggle).m_vecPosition2.x = (this->super_CBaseToggle).m_vecPosition1.x;
    (this->super_CBaseToggle).m_vecPosition2.y = (this->super_CBaseToggle).m_vecPosition1.y;
    (this->super_CBaseToggle).m_vecPosition2.z = (this->super_CBaseToggle).m_vecPosition1.z;
  }
  fVar1 = (this->super_CBaseToggle).m_flWait;
  uVar7 = (uint)!NAN(fVar1);
  if (fVar1 != -1.0) {
    uVar7 = 0;
  }
  this->m_fStayPushed = uVar7;
  this->m_fRotating = 0;
  pcVar8 = ButtonTouch;
  if ((peVar6->spawnflags & 0x100) == 0) {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.__pfn
         = ButtonUse;
    pcVar8 = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnUse.
    __delta = 0;
  }
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
  __delta = 0;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn
       = pcVar8;
  return;
}


// ButtonSound  @ 00073b60  (line 532)

char * ButtonSound(int sound)

{
  char *pcVar1;
  
                    /* Unresolved local var: char * pszSound@[DW_OP_reg0(EAX)] */
  pcVar1 = "buttons/button9.wav";
  if ((uint)sound < 0x1a) {
    pcVar1 = *(char **)(CSWTCH_257 + sound * 4);
  }
  return pcVar1;
}


// DoSpark  @ 00073b80  (line 572)

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


// CBaseButton::ButtonSpark  @ 000737b0  (line 589)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ButtonSpark(CBaseButton * this) */

void __thiscall CBaseButton::ButtonSpark(CBaseButton *this)

{
  float fVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  longdouble lVar4;
  Vector local_18;
  
  p1Var3 = gpGlobals;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn
       = ButtonSpark;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
  __delta = 0;
  fVar1 = p1Var3->time;
  lVar4 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.5);
                    /* Unresolved local var: Vector tmp@[???]
                       Unresolved local var: float flVolume@[???] */
  peVar2->nextthink = (float)((longdouble)0.1 + lVar4 + (longdouble)fVar1);
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  local_18.z = (peVar2->size).z * 0.5 + (peVar2->mins).z;
  local_18.y = (peVar2->size).y * 0.5 + (peVar2->mins).y;
  local_18.x = (peVar2->size).x * 0.5 + (peVar2->mins).x;
  UTIL_Sparks(&local_18);
  lVar4 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.25,0.75);
  fVar1 = (float)((longdouble)0.4 * lVar4);
  lVar4 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
  switch((int)(lVar4 * (longdouble)6.0)) {
  case 0:
    EMIT_SOUND_DYN(peVar2->pContainingEntity,2,"buttons/spark1.wav",fVar1,0.8,0,100);
    return;
  case 1:
    EMIT_SOUND_DYN(peVar2->pContainingEntity,2,"buttons/spark2.wav",fVar1,0.8,0,100);
    return;
  case 2:
    EMIT_SOUND_DYN(peVar2->pContainingEntity,2,"buttons/spark3.wav",fVar1,0.8,0,100);
    return;
  case 3:
    EMIT_SOUND_DYN(peVar2->pContainingEntity,2,"buttons/spark4.wav",fVar1,0.8,0,100);
    return;
  case 4:
    EMIT_SOUND_DYN(peVar2->pContainingEntity,2,"buttons/spark5.wav",fVar1,0.8,0,100);
    return;
  case 5:
    EMIT_SOUND_DYN(peVar2->pContainingEntity,2,"buttons/spark6.wav",fVar1,0.8,0,100);
  }
  return;
}


// CBaseButton::ButtonUse  @ 00074550  (line 601)

/* DWARF original prototype: void ButtonUse(CBaseButton * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CBaseButton::ButtonUse
          (CBaseButton *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  Vector vecDestAngle;
  Vector vecDest;
  int iVar1;
  entvars_t *peVar2;
  BOOL BVar3;
  vec_t vVar4;
  float flSpeed;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  if (((1 < (this->super_CBaseToggle).m_toggle_state - TS_GOING_UP) &&
      ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
         goal_activation & 8) == 0 || (value == 8.0)))) &&
     (((pActivator != (CBaseEntity *)0x0 &&
       (iVar1 = (*pActivator->_vptr_CBaseEntity[10])(pActivator), iVar1 != 2)) ||
      (BVar3 = ActivationSucceeded((CBaseEntity *)this,(CBasePlayer *)pActivator,(CBaseEntity *)0x0)
      , BVar3 != 0)))) {
    EHANDLE::operator=(&(this->super_CBaseToggle).m_hActivator,pActivator);
    if ((this->super_CBaseToggle).m_toggle_state != TS_AT_TOP) {
      ButtonActivate(this);
      return;
    }
    if ((this->m_fStayPushed == 0) &&
       (peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev, (peVar2->spawnflags & 0x20) != 0)) {
      flSpeed = 0.8;
      vVar4 = 1.0;
      EMIT_SOUND_DYN(peVar2->pContainingEntity,2,gpGlobals->pStringBase + peVar2->noise,1.0,0.8,0,
                     100);
      peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      if (peVar2->max_health != 0.0) {
        peVar2->health = peVar2->max_health;
        peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev;
      }
      (this->super_CBaseToggle).m_toggle_state = TS_GOING_DOWN;
      iVar1 = this->m_fRotating;
      (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__pfn = ButtonBackHome;
      (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__delta = 0;
      if (iVar1 == 0) {
        local_18 = (this->super_CBaseToggle).m_vecPosition1.x;
        local_14 = (this->super_CBaseToggle).m_vecPosition1.y;
        local_10 = (this->super_CBaseToggle).m_vecPosition1.z;
        vecDest.y = peVar2->speed;
        vecDest.x = (vec_t)&local_18;
        vecDest.z = vVar4;
        CBaseToggle::LinearMove(&this->super_CBaseToggle,vecDest,flSpeed);
      }
      else {
        local_18 = (this->super_CBaseToggle).m_vecAngle1.x;
        local_14 = (this->super_CBaseToggle).m_vecAngle1.y;
        local_10 = (this->super_CBaseToggle).m_vecAngle1.z;
        vecDestAngle.y = peVar2->speed;
        vecDestAngle.x = (vec_t)&local_18;
        vecDestAngle.z = vVar4;
        CBaseToggle::AngularMove(&this->super_CBaseToggle,vecDestAngle,flSpeed);
      }
      ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->frame
           = 0.0;
    }
  }
  return;
}


// CBaseButton::ButtonResponseToTouch  @ 00073d90  (line 635)

/* DWARF original prototype: BUTTON_CODE ButtonResponseToTouch(CBaseButton * this) */

BUTTON_CODE __thiscall CBaseButton::ButtonResponseToTouch(CBaseButton *this)

{
  TOGGLE_STATE TVar1;
  BUTTON_CODE BVar2;
  
  TVar1 = (this->super_CBaseToggle).m_toggle_state;
  if (TVar1 - TS_GOING_UP < 2) {
    BVar2 = BUTTON_NOTHING;
  }
  else {
    BVar2 = BUTTON_ACTIVATE;
    if ((TVar1 == TS_AT_TOP) && (BVar2 = BUTTON_NOTHING, this->m_fStayPushed == 0)) {
      return (uint)((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                    super_CBaseEntity.pev)->spawnflags >> 4 & BUTTON_RETURN;
    }
  }
  return BVar2;
}


// CBaseButton::ButtonTouch  @ 000742a0  (line 660)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ButtonTouch(CBaseButton * this, CBaseEntity * pOther) */

void __thiscall CBaseButton::ButtonTouch(CBaseButton *this,CBaseEntity *pOther)

{
  EHANDLE *this_00;
  TOGGLE_STATE TVar1;
  Vector vecDestAngle;
  Vector vecDest;
  BOOL BVar2;
  CBaseEntity *pActivator;
  entvars_t *peVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  vec_t vVar8;
  float flSpeed;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: BUTTON_CODE code@[???] */
  iVar4 = 7;
  bVar7 = gpGlobals->pStringBase + pOther->pev->classname == (char *)0x0;
  pcVar5 = gpGlobals->pStringBase + pOther->pev->classname;
  pcVar6 = "player";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar7 = *pcVar5 == *pcVar6;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (((bVar7) &&
      (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
        goal_activation & 8) == 0)) &&
     (BVar2 = ActivationSucceeded((CBaseEntity *)this,(CBasePlayer *)pOther,(CBaseEntity *)0x0),
     BVar2 != 0)) {
                    /* Unresolved local var: BUTTON_CODE code@[???] */
    this_00 = &(this->super_CBaseToggle).m_hActivator;
    EHANDLE::operator=(this_00,pOther);
    TVar1 = (this->super_CBaseToggle).m_toggle_state;
    if (1 < TVar1 - TS_GOING_UP) {
      if (TVar1 == TS_AT_TOP) {
        if (this->m_fStayPushed != 0) {
          return;
        }
        if ((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
             ->spawnflags & 0x20) == 0) {
          return;
        }
        iVar4 = UTIL_IsMasterTriggered((this->super_CBaseToggle).m_sMaster);
        if (iVar4 != 0) {
          peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   .pev;
          (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
          m_pfnTouch.__pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
          (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
          m_pfnTouch.__delta = 0;
          flSpeed = 0.8;
          EMIT_SOUND_DYN(peVar3->pContainingEntity,2,gpGlobals->pStringBase + peVar3->noise,1.0,0.8,
                         0,100);
          pActivator = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
          vVar8 = 0.0;
          CBaseDelay::SUB_UseTargets((CBaseDelay *)this,pActivator,USE_TOGGLE,0.0);
          peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   .pev;
          if (peVar3->max_health != 0.0) {
            peVar3->health = peVar3->max_health;
            peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                     super_CBaseEntity.pev;
          }
          iVar4 = this->m_fRotating;
          (this->super_CBaseToggle).m_toggle_state = TS_GOING_DOWN;
          (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__pfn = ButtonBackHome;
          (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__delta = 0;
          if (iVar4 == 0) {
            local_28 = (this->super_CBaseToggle).m_vecPosition1.x;
            local_24 = (this->super_CBaseToggle).m_vecPosition1.y;
            local_20 = (this->super_CBaseToggle).m_vecPosition1.z;
            vecDest.y = peVar3->speed;
            vecDest.x = (vec_t)&local_28;
            vecDest.z = vVar8;
            CBaseToggle::LinearMove(&this->super_CBaseToggle,vecDest,flSpeed);
          }
          else {
            local_28 = (this->super_CBaseToggle).m_vecAngle1.x;
            local_24 = (this->super_CBaseToggle).m_vecAngle1.y;
            local_20 = (this->super_CBaseToggle).m_vecAngle1.z;
            vecDestAngle.y = peVar3->speed;
            vecDestAngle.x = (vec_t)&local_28;
            vecDestAngle.z = vVar8;
            CBaseToggle::AngularMove(&this->super_CBaseToggle,vecDestAngle,flSpeed);
          }
          ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
          frame = 0.0;
          return;
        }
      }
      else {
        iVar4 = UTIL_IsMasterTriggered((this->super_CBaseToggle).m_sMaster);
        if (iVar4 != 0) {
          (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
          m_pfnTouch.__pfn = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
          (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
          m_pfnTouch.__delta = 0;
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


// CBaseButton::ButtonActivate  @ 00073de0  (line 704)

/* DWARF original prototype: void ButtonActivate(CBaseButton * this) */

void __thiscall CBaseButton::ButtonActivate(CBaseButton *this)

{
  Vector vecDestAngle;
  Vector vecDest;
  int iVar1;
  entvars_t *peVar2;
  vec_t vVar3;
  float flSpeed;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  flSpeed = 0.8;
  EMIT_SOUND_DYN(peVar2->pContainingEntity,2,gpGlobals->pStringBase + peVar2->noise,1.0,0.8,0,100);
  iVar1 = UTIL_IsMasterTriggered((this->super_CBaseToggle).m_sMaster);
  vVar3 = 1.4013e-45;
  if (iVar1 == 0) {
    PlayLockSounds((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                   .pev,&this->m_ls,1,1);
    return;
  }
  PlayLockSounds((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev,&this->m_ls,0,1);
  (this->super_CBaseToggle).m_toggle_state = TS_GOING_UP;
  peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  if (peVar2->max_health != 0.0) {
    peVar2->health = peVar2->max_health;
    peVar2 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__pfn = TriggerAndWait;
  iVar1 = this->m_fRotating;
  (this->super_CBaseToggle).m_pfnCallWhenMoveDone.__delta = 0;
  if (iVar1 != 0) {
    local_18 = (this->super_CBaseToggle).m_vecAngle2.x;
    local_14 = (this->super_CBaseToggle).m_vecAngle2.y;
    local_10 = (this->super_CBaseToggle).m_vecAngle2.z;
    vecDestAngle.y = peVar2->speed;
    vecDestAngle.x = (vec_t)&local_18;
    vecDestAngle.z = vVar3;
    CBaseToggle::AngularMove(&this->super_CBaseToggle,vecDestAngle,flSpeed);
    return;
  }
  local_18 = (this->super_CBaseToggle).m_vecPosition2.x;
  local_14 = (this->super_CBaseToggle).m_vecPosition2.y;
  local_10 = (this->super_CBaseToggle).m_vecPosition2.z;
  vecDest.y = peVar2->speed;
  vecDest.x = (vec_t)&local_18;
  vecDest.z = vVar3;
  CBaseToggle::LinearMove(&this->super_CBaseToggle,vecDest,flSpeed);
  return;
}


// CBaseButton::TriggerAndWait  @ 00072820  (line 737)

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
    pActivator = EHANDLE::operator_cast_to_CBaseEntity_(&(this->super_CBaseToggle).m_hActivator);
    CBaseDelay::SUB_UseTargets((CBaseDelay *)this,pActivator,USE_TOGGLE,0.0);
  }
  return;
}


// CBaseButton::ButtonReturn  @ 000720d0  (line 774)

/* DWARF original prototype: void ButtonReturn(CBaseButton * this) */

void __thiscall CBaseButton::ButtonReturn(CBaseButton *this)

{
  int iVar1;
  Vector vecDestAngle;
  Vector vecDest;
  entvars_t *peVar2;
  vec_t in_stack_ffffffe0;
  float in_stack_ffffffe4;
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
    local_18 = (this->super_CBaseToggle).m_vecPosition1.x;
    local_14 = (this->super_CBaseToggle).m_vecPosition1.y;
    local_10 = (this->super_CBaseToggle).m_vecPosition1.z;
    vecDest.y = peVar2->speed;
    vecDest.x = (vec_t)&local_18;
    vecDest.z = in_stack_ffffffe0;
    CBaseToggle::LinearMove(&this->super_CBaseToggle,vecDest,in_stack_ffffffe4);
  }
  else {
    local_18 = (this->super_CBaseToggle).m_vecAngle1.x;
    local_14 = (this->super_CBaseToggle).m_vecAngle1.y;
    local_10 = (this->super_CBaseToggle).m_vecAngle1.z;
    vecDestAngle.y = peVar2->speed;
    vecDestAngle.x = (vec_t)&local_18;
    vecDestAngle.z = in_stack_ffffffe0;
    CBaseToggle::AngularMove(&this->super_CBaseToggle,vecDestAngle,in_stack_ffffffe4);
  }
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->frame =
       0.0;
  return;
}


// CBaseButton::ButtonBackHome  @ 00071c30  (line 796)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ButtonBackHome(CBaseButton * this) */

void __thiscall CBaseButton::ButtonBackHome(CBaseButton *this)

{
  int *piVar1;
  _2globalvars_t *p1Var2;
  int iVar3;
  entvars_t *peVar4;
  char *pcVar5;
  CBaseEntity *pCVar6;
  string_t sVar7;
  code *pcVar8;
  edict_t *peVar9;
  char *pcVar10;
  char *pcVar11;
  bool bVar12;
  byte bVar13;
  
  bVar13 = 0;
  peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseToggle).m_toggle_state = TS_AT_BOTTOM;
  if ((peVar4->spawnflags & 0x20) != 0) {
    pCVar6 = EHANDLE::operator_cast_to_CBaseEntity_(&(this->super_CBaseToggle).m_hActivator);
    CBaseDelay::SUB_UseTargets((CBaseDelay *)this,pCVar6,USE_TOGGLE,0.0);
    peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  sVar7 = peVar4->target;
  if (sVar7 != 0) {
                    /* Unresolved local var: edict_t * pentTarget@[???]
                       Unresolved local var: CBaseEntity * pTarget@[???] */
    peVar9 = (edict_t *)0x0;
    pcVar5 = gpGlobals->pStringBase;
    while( true ) {
      peVar9 = (*g_engfuncs.pfnFindEntityByString)(peVar9,"targetname",pcVar5 + sVar7);
      if (peVar9 == (edict_t *)0x0) break;
      iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar9);
      if (iVar3 == 0) break;
      iVar3 = 0xc;
      pcVar5 = gpGlobals->pStringBase;
      bVar12 = pcVar5 + (peVar9->v).classname == (char *)0x0;
      pcVar10 = pcVar5 + (peVar9->v).classname;
      pcVar11 = "multisource";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar12 = *pcVar10 == *pcVar11;
        pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
        pcVar11 = pcVar11 + (uint)bVar13 * -2 + 1;
      } while (bVar12);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((bVar12) && (piVar1 = peVar9->pvPrivateData, piVar1 != (int *)0x0)) {
        pcVar8 = *(code **)(*piVar1 + 0xb4);
        pCVar6 = EHANDLE::operator_cast_to_CBaseEntity_(&(this->super_CBaseToggle).m_hActivator);
        (*pcVar8)(piVar1,pCVar6,this,3,0);
        pcVar5 = gpGlobals->pStringBase;
      }
      sVar7 = ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
              )->target;
    }
    peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  iVar3 = peVar4->spawnflags;
  pcVar8 = ButtonTouch;
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.
  __delta = 0;
  if ((iVar3 & 0x100) == 0) {
    pcVar8 = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  }
  (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnTouch.__pfn
       = pcVar8;
  p1Var2 = gpGlobals;
  if ((peVar4->spawnflags & 0x40) != 0) {
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __pfn = ButtonSpark;
    (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
    __delta = 0;
    peVar4->nextthink = p1Var2->time + 0.5;
  }
  return;
}


// CRotButton::~CRotButton  @ 00075050  (line 849)

/* DWARF original prototype: void ~CRotButton(CRotButton * this, int __in_chrg) */

void __thiscall CRotButton::~CRotButton(CRotButton *this,int __in_chrg)

{
  return;
}


// func_rot_button  @ 00074760  (line 855)

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
  *puVar1 = &PTR__CRotButton_00148c48;
  puVar1[1] = pev;
  return;
}


// CRotButton::Spawn  @ 000721e0  (line 858)

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
  _2globalvars_t *p1Var7;
  string_t sVar8;
  entvars_t *peVar9;
  uint uVar10;
  code *pcVar11;
  char *pcVar12;
  
                    /* Unresolved local var: char * pszSound@[DW_OP_reg6(ESI)] */
  pcVar12 = "buttons/button9.wav";
  uVar10 = (this->super_CBaseButton).m_sounds;
  if (uVar10 < 0x1a) {
    pcVar12 = *(char **)(CSWTCH_257 + uVar10 * 4);
  }
  (*g_engfuncs.pfnPrecacheSound)(pcVar12);
  peVar9 = (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  sVar8 = (*g_engfuncs.pfnAllocString)(pcVar12);
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
  p1Var7 = gpGlobals;
  peVar9->movetype = 7;
  peVar9 = (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar9->solid = -(uint)((peVar9->spawnflags & 1U) == 0) & 4;
  peVar9 = (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar9->pContainingEntity,p1Var7->pStringBase + peVar9->model);
  peVar9 = (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar9->speed == 0.0) {
    peVar9->speed = 40.0;
    peVar9 = (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  fVar1 = (this->super_CBaseButton).super_CBaseToggle.m_flWait;
  if (fVar1 == 0.0) {
    (this->super_CBaseButton).super_CBaseToggle.m_flWait = 1.0;
    fVar1 = 1.0;
  }
  if (0.0 < peVar9->health) {
    peVar9->takedamage = 1.0;
    peVar9 = (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar1 = (this->super_CBaseButton).super_CBaseToggle.m_flWait;
  }
  fVar2 = (this->super_CBaseButton).super_CBaseToggle.m_flMoveDistance;
  (this->super_CBaseButton).super_CBaseToggle.m_toggle_state = TS_AT_BOTTOM;
  (this->super_CBaseButton).super_CBaseToggle.m_vecAngle1.x = (peVar9->angles).x;
  (this->super_CBaseButton).super_CBaseToggle.m_vecAngle1.y = (peVar9->angles).y;
  (this->super_CBaseButton).super_CBaseToggle.m_vecAngle1.z = (peVar9->angles).z;
  fVar3 = (peVar9->movedir).z;
  fVar4 = (peVar9->angles).z;
  fVar5 = (peVar9->movedir).y;
  fVar6 = (peVar9->angles).y;
  (this->super_CBaseButton).super_CBaseToggle.m_vecAngle2.x =
       fVar2 * (peVar9->movedir).x + (peVar9->angles).x;
  (this->super_CBaseButton).super_CBaseToggle.m_vecAngle2.y = fVar5 * fVar2 + fVar6;
  (this->super_CBaseButton).super_CBaseToggle.m_vecAngle2.z = fVar3 * fVar2 + fVar4;
  uVar10 = (uint)!NAN(fVar1);
  if (fVar1 != -1.0) {
    uVar10 = 0;
  }
  (this->super_CBaseButton).m_fStayPushed = uVar10;
  pcVar11 = CBaseButton::ButtonTouch;
  (this->super_CBaseButton).m_fRotating = 1;
  if ((peVar9->spawnflags & 0x100) == 0) {
    (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__pfn = CBaseButton::ButtonUse;
    pcVar11 = (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
    (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnUse.__delta = 0;
  }
  (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  (this->super_CBaseButton).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = pcVar11;
  return;
}


// CMomentaryRotButton::~CMomentaryRotButton  @ 00075040  (line 922)

/* DWARF original prototype: void ~CMomentaryRotButton(CMomentaryRotButton * this, int __in_chrg) */

void __thiscall CMomentaryRotButton::~CMomentaryRotButton(CMomentaryRotButton *this,int __in_chrg)

{
  return;
}


// CMomentaryRotButton::ObjectCaps  @ 00074ff0  (line 930)

/* DWARF original prototype: int ObjectCaps(CMomentaryRotButton * this) */

int __thiscall CMomentaryRotButton::ObjectCaps(CMomentaryRotButton *this)

{
                    /* Unresolved local var: int flags@[???] */
  return -(uint)((((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                  .pev)->spawnflags & 1U) == 0) & 0x10;
}


// CMomentaryRotButton::Restore  @ 000728f0  (line 967)

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


// CMomentaryRotButton::Save  @ 000729b0  (line 967)

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


// momentary_rot_button  @ 000747d0  (line 969)

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
  *puVar1 = &PTR__CMomentaryRotButton_00148d58;
  puVar1[1] = pev;
  return;
}


// CMomentaryRotButton::Spawn  @ 000723d0  (line 972)

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
  int iVar11;
  char *pcVar12;
  
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
  if (fVar1 < 0.0) {
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
    (this->m_end).z = vVar9;
    this->m_direction = 1;
  }
  else {
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
  iVar11 = 0;
  if ((peVar8->spawnflags & 1U) != 0) {
    iVar11 = 4;
  }
  peVar8->solid = iVar11;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->movetype
       = 7;
  peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar8,&peVar8->origin);
  peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  pcVar12 = "buttons/button9.wav";
  (*g_engfuncs.pfnSetModel)(peVar8->pContainingEntity,gpGlobals->pStringBase + peVar8->model);
  if ((uint)this->m_sounds < 0x1a) {
    pcVar12 = *(char **)(CSWTCH_257 + this->m_sounds * 4);
  }
  (*g_engfuncs.pfnPrecacheSound)(pcVar12);
  peVar8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  sVar10 = (*g_engfuncs.pfnAllocString)(pcVar12);
  peVar8->noise = sVar10;
  this->m_lastUsed = 0;
  return;
}


// CMomentaryRotButton::KeyValue  @ 00072760  (line 1008)

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


// CMomentaryRotButton::PlaySound  @ 00074840  (line 1024)

/* DWARF original prototype: void PlaySound(CMomentaryRotButton * this) */

void __thiscall CMomentaryRotButton::PlaySound(CMomentaryRotButton *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  EMIT_SOUND_DYN(peVar1->pContainingEntity,2,gpGlobals->pStringBase + peVar1->noise,1.0,0.8,0,100);
  return;
}


// CMomentaryRotButton::Use  @ 00074c10  (line 1032)

/* DWARF original prototype: void Use(CMomentaryRotButton * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CMomentaryRotButton::Use
          (CMomentaryRotButton *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  _2globalvars_t *p1Var1;
  int iVar2;
  char *pcVar3;
  entvars_t *peVar4;
  edict_t *peVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  byte bVar9;
  float fVar10;
  Vector *angle1;
  Vector local_28 [2];
  
                    /* Unresolved local var: Vector dest@[???]
                       Unresolved local var: float value1@[???] */
  bVar9 = 0;
  peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar10 = CBaseToggle::AxisDelta(peVar4->spawnflags,&peVar4->angles,&this->m_start);
  p1Var1 = gpGlobals;
  peVar4->ideal_yaw = fVar10 / (this->super_CBaseToggle).m_flMoveDistance;
                    /* Unresolved local var: edict_t * pentTarget@[???] */
  peVar5 = (edict_t *)0x0;
  peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  pcVar3 = p1Var1->pStringBase;
  fVar10 = peVar4->ideal_yaw;
  while( true ) {
    peVar5 = (*g_engfuncs.pfnFindEntityByString)(peVar5,"target",pcVar3 + peVar4->target);
    if (peVar5 == (edict_t *)0x0) break;
    iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5);
    if (iVar2 == 0) break;
    iVar2 = 0x15;
    pcVar3 = gpGlobals->pStringBase;
    bVar8 = pcVar3 + (peVar5->v).classname == (char *)0x0;
    pcVar6 = pcVar3 + (peVar5->v).classname;
    pcVar7 = "momentary_rot_button";
    do {
                    /* Unresolved local var: CMomentaryRotButton * pEntity@[???] */
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar8 = *pcVar6 == *pcVar7;
      pcVar6 = pcVar6 + (uint)bVar9 * -2 + 1;
      pcVar7 = pcVar7 + (uint)bVar9 * -2 + 1;
    } while (bVar8);
    if ((bVar8) && (peVar5->pvPrivateData != (CMomentaryRotButton *)0x0)) {
      UpdateSelf(peVar5->pvPrivateData,fVar10);
      pcVar3 = gpGlobals->pStringBase;
    }
    peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  }
  peVar4 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  angle1 = local_28;
  fVar10 = peVar4->nextthink - peVar4->ltime;
  local_28[0].z = (peVar4->avelocity).z * fVar10 + (peVar4->angles).z;
  local_28[0].y = (peVar4->avelocity).y * fVar10 + (peVar4->angles).y;
  local_28[0].x = fVar10 * (peVar4->avelocity).x + (peVar4->angles).x;
  fVar10 = CBaseToggle::AxisDelta(peVar4->spawnflags,angle1,&this->m_start);
  if (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      target == 0) {
    return;
  }
  UpdateTarget((CMomentaryRotButton *)(fVar10 / (this->super_CBaseToggle).m_flMoveDistance),
               (float)angle1);
  return;
}


// CMomentaryRotButton::UpdateAllButtons  @ 00074a80  (line 1045)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void UpdateAllButtons(CMomentaryRotButton * this, float value, int
   start) */

void __thiscall
CMomentaryRotButton::UpdateAllButtons(CMomentaryRotButton *this,float value,int start)

{
  float fVar1;
  float fVar2;
  CMomentaryRotButton *this_00;
  entvars_t *peVar3;
  float fVar4;
  vec_t vVar5;
  vec_t vVar6;
  _2globalvars_t *p1Var7;
  int iVar8;
  edict_t *peVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  bool bVar13;
  byte bVar14;
  
                    /* Unresolved local var: edict_t * pentTarget@[???] */
  bVar14 = 0;
  peVar9 = (edict_t *)0x0;
  pcVar10 = gpGlobals->pStringBase;
  do {
    peVar9 = (*g_engfuncs.pfnFindEntityByString)
                       (peVar9,"target",
                        pcVar10 + ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                   super_CBaseEntity.pev)->target);
    if (peVar9 == (edict_t *)0x0) {
      return;
    }
    iVar8 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar9);
    p1Var7 = gpGlobals;
    vVar6 = g_vecZero.z;
    if (iVar8 == 0) {
      return;
    }
    iVar8 = 0x15;
    pcVar10 = gpGlobals->pStringBase;
    bVar13 = pcVar10 + (peVar9->v).classname == (char *)0x0;
    pcVar11 = pcVar10 + (peVar9->v).classname;
    pcVar12 = "momentary_rot_button";
    do {
                    /* Unresolved local var: CMomentaryRotButton * pEntity@[???] */
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar13 = *pcVar11 == *pcVar12;
      pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
      pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
    } while (bVar13);
    if ((bVar13) && (this_00 = peVar9->pvPrivateData, this_00 != (CMomentaryRotButton *)0x0)) {
      if (start == 0) {
        peVar3 = (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if (value <= 0.0) {
          (peVar3->avelocity).x = g_vecZero.x;
          vVar5 = g_vecZero.y;
          (peVar3->avelocity).z = vVar6;
          (peVar3->avelocity).y = vVar5;
          peVar3 = (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity.pev;
          (peVar3->angles).x = (this_00->m_start).x;
          (peVar3->angles).y = (this_00->m_start).y;
          (peVar3->angles).z = (this_00->m_start).z;
          ((this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
          ->nextthink = -1.0;
          (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
          m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
          (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
          m_pfnThink.__delta = 0;
          pcVar10 = p1Var7->pStringBase;
        }
        else {
          fVar4 = -this_00->m_returnSpeed;
          fVar1 = (peVar3->movedir).z;
          fVar2 = (peVar3->movedir).y;
          (peVar3->avelocity).x = fVar4 * (peVar3->movedir).x;
          (peVar3->avelocity).y = fVar2 * fVar4;
          (peVar3->avelocity).z = fVar1 * fVar4;
          peVar3 = (this_00->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                   super_CBaseEntity.pev;
          peVar3->nextthink = peVar3->ltime + 0.1;
          pcVar10 = p1Var7->pStringBase;
        }
      }
      else {
        UpdateSelf(this_00,value);
        pcVar10 = gpGlobals->pStringBase;
      }
    }
  } while( true );
}


// CMomentaryRotButton::UpdateSelf  @ 000748a0  (line 1070)

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
  peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  this->m_lastUsed = 1;
  peVar3->nextthink = peVar3->ltime + 0.1;
  if (this->m_direction < 1) {
    if ((this->m_direction == 0) || (0.0 < value)) goto LAB_00074954;
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (peVar3->avelocity).x = g_vecZero.x;
    (peVar3->avelocity).y = g_vecZero.y;
    (peVar3->avelocity).z = g_vecZero.z;
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (peVar3->angles).x = (this->m_start).x;
    (peVar3->angles).y = (this->m_start).y;
    (peVar3->angles).z = (this->m_start).z;
  }
  else {
    if (value < 1.0) {
LAB_00074954:
      if (bVar5) {
        peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev;
        EMIT_SOUND_DYN(peVar3->pContainingEntity,2,gpGlobals->pStringBase + peVar3->noise,1.0,0.8,0,
                       100);
      }
      peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      fVar1 = peVar3->ltime;
      if (fVar1 <= peVar3->nextthink) {
        fVar1 = peVar3->nextthink;
      }
      peVar3->nextthink = fVar1 + 0.1;
      peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
      ;
      fVar4 = (float)this->m_direction * peVar3->speed;
      fVar1 = (peVar3->movedir).z;
      fVar2 = (peVar3->movedir).y;
      (peVar3->avelocity).x = fVar4 * (peVar3->movedir).x;
      (peVar3->avelocity).y = fVar2 * fVar4;
      (peVar3->avelocity).z = fVar1 * fVar4;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __pfn = Off;
      (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pfnThink.
      __delta = 0;
      return;
    }
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (peVar3->avelocity).x = g_vecZero.x;
    (peVar3->avelocity).y = g_vecZero.y;
    (peVar3->avelocity).z = g_vecZero.z;
    peVar3 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    (peVar3->angles).x = (this->m_end).x;
    (peVar3->angles).y = (this->m_end).y;
    (peVar3->angles).z = (this->m_end).z;
  }
  return;
}


// CMomentaryRotButton::UpdateTarget  @ 00072630  (line 1107)

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
                       Unresolved local var: CBaseEntity * pEntity@[???] */
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


// CMomentaryRotButton::UpdateTarget  @ 00074d80  (line 1108)

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


// CMomentaryRotButton::Off  @ 00071420  (line 1127)

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


// CMomentaryRotButton::Return  @ 00072fb0  (line 1141)

/* DWARF original prototype: void Return(CMomentaryRotButton * this) */

void __thiscall CMomentaryRotButton::Return(CMomentaryRotButton *this)

{
  entvars_t *peVar1;
  uint uVar2;
  void *pvVar3;
  CMomentaryRotButton *this_00;
  vec_t vVar4;
  vec_t vVar5;
  _2globalvars_t *p1Var6;
  char *pcVar7;
  int iVar8;
  edict_t *peVar9;
  byte *pbVar10;
  byte *pbVar11;
  bool bVar12;
  bool bVar13;
  byte bVar14;
  float fVar15;
  float in_stack_00000008;
  
                    /* Unresolved local var: float value@[???] */
  bVar14 = 0;
                    /* Unresolved local var: edict_t * pentTarget@[???] */
  peVar9 = (edict_t *)0x0;
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  fVar15 = CBaseToggle::AxisDelta(peVar1->spawnflags,&peVar1->angles,&this->m_start);
  pcVar7 = gpGlobals->pStringBase;
  this_00 = (CMomentaryRotButton *)(fVar15 / (this->super_CBaseToggle).m_flMoveDistance);
  while( true ) {
    peVar9 = (*g_engfuncs.pfnFindEntityByString)
                       (peVar9,"target",
                        pcVar7 + ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.
                                  super_CBaseEntity.pev)->target);
    if (peVar9 == (edict_t *)0x0) break;
    iVar8 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar9);
    p1Var6 = gpGlobals;
    vVar5 = g_vecZero.z;
    if (iVar8 == 0) break;
    iVar8 = 0x15;
    uVar2 = (peVar9->v).classname;
    pcVar7 = gpGlobals->pStringBase;
    bVar12 = CARRY4(uVar2,(uint)pcVar7);
    bVar13 = (byte *)(pcVar7 + uVar2) == (byte *)0x0;
    pbVar10 = (byte *)(pcVar7 + uVar2);
    pbVar11 = (byte *)"momentary_rot_button";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar12 = *pbVar10 < *pbVar11;
      bVar13 = *pbVar10 == *pbVar11;
      pbVar10 = pbVar10 + (uint)bVar14 * -2 + 1;
      pbVar11 = pbVar11 + (uint)bVar14 * -2 + 1;
    } while (bVar13);
                    /* Unresolved local var: CMomentaryRotButton * pEntity@[???] */
    if (((!bVar12 && !bVar13) == bVar12) && (pvVar3 = peVar9->pvPrivateData, pvVar3 != (void *)0x0))
    {
      iVar8 = *(int *)((int)pvVar3 + 4);
      if ((float)this_00 <= 0.0) {
        *(vec_t *)(iVar8 + 0x5c) = g_vecZero.x;
        vVar4 = g_vecZero.y;
        *(vec_t *)(iVar8 + 100) = vVar5;
        *(vec_t *)(iVar8 + 0x60) = vVar4;
        iVar8 = *(int *)((int)pvVar3 + 4);
        *(undefined4 *)(iVar8 + 0x50) = *(undefined4 *)((int)pvVar3 + 0x520);
        *(undefined4 *)(iVar8 + 0x54) = *(undefined4 *)((int)pvVar3 + 0x524);
        *(undefined4 *)(iVar8 + 0x58) = *(undefined4 *)((int)pvVar3 + 0x528);
        *(undefined4 *)(*(int *)((int)pvVar3 + 4) + 0x104) = 0xbf800000;
        *(undefined4 *)((int)pvVar3 + 0x10) = 0;
        *(undefined4 *)((int)pvVar3 + 0x14) = 0;
        pcVar7 = p1Var6->pStringBase;
      }
      else {
        fVar15 = -*(float *)((int)pvVar3 + 0x51c);
        *(float *)(iVar8 + 0x5c) = fVar15 * *(float *)(iVar8 + 0x44);
        *(float *)(iVar8 + 0x60) = *(float *)(iVar8 + 0x48) * fVar15;
        *(float *)(iVar8 + 100) = *(float *)(iVar8 + 0x4c) * fVar15;
        *(float *)(*(int *)((int)pvVar3 + 4) + 0x104) =
             *(float *)(*(int *)((int)pvVar3 + 4) + 0x100) + 0.1;
        pcVar7 = p1Var6->pStringBase;
      }
    }
  }
  if ((0.0 < (float)this_00) &&
     (((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
      target != 0)) {
    UpdateTarget(this_00,in_stack_00000008);
    return;
  }
  return;
}


// CMomentaryRotButton::UpdateSelfReturn  @ 00074db0  (line 1151)

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


// env_spark  @ 00074e60  (line 1164)

void env_spark(entvars_t *param_1)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
  if (param_1 == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      param_1 = &peVar2->v;
    }
  }
  if ((param_1->pContainingEntity != (edict_t *)0x0) &&
     (param_1->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x478,param_1);
  *puVar1 = &PTR__CEnvSpark_00148e68;
  puVar1[1] = param_1;
  return;
}


// CEnvSpark::~CEnvSpark  @ 00075030  (line 1171)

/* DWARF original prototype: void ~CEnvSpark(CEnvSpark * this, int __in_chrg) */

void __thiscall CEnvSpark::~CEnvSpark(CEnvSpark *this,int __in_chrg)

{
  return;
}


// CEnvSpark::Restore  @ 00072af0  (line 1195)

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


// CEnvSpark::Save  @ 00072c10  (line 1195)

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


// env_debris  @ 00074ed0  (line 1198)

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
  *puVar1 = &PTR__CEnvSpark_00148e68;
  puVar1[1] = pev;
  return;
}


// CEnvSpark::Spawn  @ 00073430  (line 1201)

/* DWARF original prototype: void Spawn(CEnvSpark * this) */

void __thiscall CEnvSpark::Spawn(CEnvSpark *this)

{
  float fVar1;
  entvars_t *peVar2;
  uint uVar3;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
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
  UNRECOVERED_JUMPTABLE = (this->super_CBaseEntity)._vptr_CBaseEntity[3];
  if (UNRECOVERED_JUMPTABLE == Precache) {
    (*g_engfuncs.pfnPrecacheSound)("buttons/spark1.wav");
    (*g_engfuncs.pfnPrecacheSound)("buttons/spark2.wav");
    (*g_engfuncs.pfnPrecacheSound)("buttons/spark3.wav");
    (*g_engfuncs.pfnPrecacheSound)("buttons/spark4.wav");
    (*g_engfuncs.pfnPrecacheSound)("buttons/spark5.wav");
                    /* WARNING: Could not recover jumptable at 0x0007352e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnPrecacheSound)("buttons/spark6.wav");
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00073551. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// CEnvSpark::Precache  @ 000714c0  (line 1228)

/* DWARF original prototype: void Precache(CEnvSpark * this) */

void __thiscall CEnvSpark::Precache(CEnvSpark *this)

{
  (*g_engfuncs.pfnPrecacheSound)("buttons/spark1.wav");
  (*g_engfuncs.pfnPrecacheSound)("buttons/spark2.wav");
  (*g_engfuncs.pfnPrecacheSound)("buttons/spark3.wav");
  (*g_engfuncs.pfnPrecacheSound)("buttons/spark4.wav");
  (*g_engfuncs.pfnPrecacheSound)("buttons/spark5.wav");
                    /* WARNING: Could not recover jumptable at 0x00071510. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("buttons/spark6.wav");
  return;
}


// CEnvSpark::KeyValue  @ 00071b30  (line 1238)

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


// CEnvSpark::SparkThink  @ 00073560  (line 1256)

/* DWARF original prototype: void SparkThink(CEnvSpark * this) */

void __thiscall CEnvSpark::SparkThink(CEnvSpark *this)

{
  float fVar1;
  entvars_t *peVar2;
  longdouble lVar3;
  Vector local_18;
  
  fVar1 = gpGlobals->time;
  peVar2 = (this->super_CBaseEntity).pev;
  lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,this->m_flDelay);
                    /* Unresolved local var: Vector tmp@[???]
                       Unresolved local var: float flVolume@[???] */
  peVar2->nextthink = (float)((longdouble)(fVar1 + 0.1) + lVar3);
  peVar2 = (this->super_CBaseEntity).pev;
  local_18.z = (peVar2->size).z * 0.5 + (peVar2->origin).z;
  local_18.y = (peVar2->size).y * 0.5 + (peVar2->origin).y;
  local_18.x = (peVar2->size).x * 0.5 + (peVar2->origin).x;
  UTIL_Sparks(&local_18);
  lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.25,0.75);
  fVar1 = (float)((longdouble)0.4 * lVar3);
  lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
  switch((int)(lVar3 * (longdouble)6.0)) {
  case 0:
    EMIT_SOUND_DYN(peVar2->pContainingEntity,2,"buttons/spark1.wav",fVar1,0.8,0,100);
    return;
  case 1:
    EMIT_SOUND_DYN(peVar2->pContainingEntity,2,"buttons/spark2.wav",fVar1,0.8,0,100);
    return;
  case 2:
    EMIT_SOUND_DYN(peVar2->pContainingEntity,2,"buttons/spark3.wav",fVar1,0.8,0,100);
    return;
  case 3:
    EMIT_SOUND_DYN(peVar2->pContainingEntity,2,"buttons/spark4.wav",fVar1,0.8,0,100);
    return;
  case 4:
    EMIT_SOUND_DYN(peVar2->pContainingEntity,2,"buttons/spark5.wav",fVar1,0.8,0,100);
    return;
  case 5:
    EMIT_SOUND_DYN(peVar2->pContainingEntity,2,"buttons/spark6.wav",fVar1,0.8,0,100);
  }
  return;
}


// CEnvSpark::SparkStart  @ 00071520  (line 1262)

/* DWARF original prototype: void SparkStart(CEnvSpark * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CEnvSpark::SparkStart
          (CEnvSpark *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,float value
          )

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  _2globalvars_t *p1Var4;
  longdouble lVar5;
  
  p1Var4 = gpGlobals;
  fVar1 = this->m_flDelay;
  (this->super_CBaseEntity).m_pfnUse.__pfn = SparkStop;
  peVar3 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnUse.__delta = 0;
  (this->super_CBaseEntity).m_pfnThink.__pfn = SparkThink;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  fVar2 = p1Var4->time;
  lVar5 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,fVar1);
  peVar3->nextthink = (float)((longdouble)0.1 + lVar5 + (longdouble)fVar2);
  return;
}


// CEnvSpark::SparkStop  @ 00071590  (line 1269)

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


// CButtonTarget::~CButtonTarget  @ 00075020  (line 1277)

/* DWARF original prototype: void ~CButtonTarget(CButtonTarget * this, int __in_chrg) */

void __thiscall CButtonTarget::~CButtonTarget(CButtonTarget *this,int __in_chrg)

{
  return;
}


// button_target  @ 00074f40  (line 1287)

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
  *puVar1 = &PTR__CButtonTarget_00148f74;
  puVar1[1] = pev;
  return;
}


// CButtonTarget::Spawn  @ 000715c0  (line 1290)

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


// CButtonTarget::Use  @ 00072590  (line 1301)

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


// CButtonTarget::ObjectCaps  @ 00071640  (line 1316)

/* DWARF original prototype: int ObjectCaps(CButtonTarget * this) */

int __thiscall CButtonTarget::ObjectCaps(CButtonTarget *this)

{
  int iVar1;
  
                    /* Unresolved local var: int caps@[???] */
  iVar1 = 0;
  if ((((this->super_CBaseEntity).pev)->spawnflags & 1U) != 0) {
    iVar1 = 8;
  }
  return iVar1;
}


// CButtonTarget::TakeDamage  @ 00073310  (line 1324)

/* DWARF original prototype: int TakeDamage(CButtonTarget * this, entvars_t * pevInflictor,
   entvars_t * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CButtonTarget::TakeDamage
          (CButtonTarget *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  int iVar3;
  edict_t *peVar4;
  CBaseEntity *pActivator;
  
  p_Var1 = (this->super_CBaseEntity)._vptr_CBaseEntity[0x2d];
  peVar4 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar4 == (edict_t *)0x0) &&
     (peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar4 == (edict_t *)0x0)) {
    pActivator = (CBaseEntity *)0x0;
  }
  else {
    pActivator = peVar4->pvPrivateData;
  }
  if (p_Var1 == Use) {
    iVar3 = CBaseEntity::ShouldToggle
                      (&this->super_CBaseEntity,USE_TOGGLE,
                       (int)((this->super_CBaseEntity).pev)->frame);
    if (iVar3 != 0) {
      peVar2 = (this->super_CBaseEntity).pev;
      peVar2->frame = 1.0 - peVar2->frame;
      if (((this->super_CBaseEntity).pev)->frame == 0.0) {
        CBaseEntity::SUB_UseTargets(&this->super_CBaseEntity,pActivator,USE_OFF,0.0);
      }
      else {
        CBaseEntity::SUB_UseTargets(&this->super_CBaseEntity,pActivator,USE_ON,0.0);
      }
    }
  }
  else {
    (*p_Var1)(this,pActivator,this,3,0);
  }
  return 1;
}


