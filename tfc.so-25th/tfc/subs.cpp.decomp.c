// Ghidra decompilation of functions from tfc/subs.cpp
// 30 functions, ordered by original source line

// CPointEntity::Spawn  @ 000f1270  (line 36)

/* DWARF original prototype: void Spawn(CPointEntity * this) */

void __thiscall CPointEntity::Spawn(CPointEntity *this)

{
  ((this->super_CBaseEntity).pev)->solid = 0;
  return;
}


// CNullEntity::~CNullEntity  @ 000f2710  (line 41)

/* DWARF original prototype: void ~CNullEntity(CNullEntity * this, int __in_chrg) */

void __thiscall CNullEntity::~CNullEntity(CNullEntity *this,int __in_chrg)

{
  return;
}


// CNullEntity::Spawn  @ 000f1280  (line 50)

/* DWARF original prototype: void Spawn(CNullEntity * this) */

void __thiscall CNullEntity::Spawn(CNullEntity *this)

{
                    /* WARNING: Could not recover jumptable at 0x000f1291. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnRemoveEntity)(((this->super_CBaseEntity).pev)->pContainingEntity);
  return;
}


// info_null  @ 000f1700  (line 53)

void info_null(entvars_t *pev)

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
  *puVar1 = &PTR__CNullEntity_0015b7e4;
  puVar1[1] = pev;
  return;
}


// info_landmark  @ 000f1850  (line 58)

void info_landmark(entvars_t *pev)

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


// CBaseEntity::UpdateOnRemove  @ 000f18c0  (line 62)

/* DWARF original prototype: void UpdateOnRemove(CBaseEntity * this) */

void __thiscall CBaseEntity::UpdateOnRemove(CBaseEntity *this)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  entvars_t *peVar4;
  int iVar5;
  
                    /* Unresolved local var: int i@[???] */
  peVar4 = this->pev;
  if (((peVar4->flags & 0x10000) != 0) && (0 < WorldGraph.m_cLinks)) {
    iVar3 = 0;
    iVar2 = 0;
    iVar5 = WorldGraph.m_cLinks;
    do {
      while (*(entvars_t **)((WorldGraph.m_pLinkPool)->m_szLinkEntModelname + iVar3 + -4) != peVar4)
      {
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x18;
        if (iVar5 <= iVar2) goto LAB_000f1920;
      }
      pcVar1 = (WorldGraph.m_pLinkPool)->m_szLinkEntModelname + iVar3 + -4;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x18;
      peVar4 = this->pev;
      iVar5 = WorldGraph.m_cLinks;
    } while (iVar2 < WorldGraph.m_cLinks);
  }
LAB_000f1920:
  if (peVar4->globalname != 0) {
    CGlobalState::EntitySetState(&gGlobalState,peVar4->globalname,GLOBAL_DEAD);
  }
  return;
}


// CBaseEntity::SUB_Remove  @ 000f1950  (line 84)

/* DWARF original prototype: void SUB_Remove(CBaseEntity * this) */

void __thiscall CBaseEntity::SUB_Remove(CBaseEntity *this)

{
  char *pcVar1;
  int iVar2;
  entvars_t *peVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int i@[???] */
  peVar3 = this->pev;
  if (((peVar3->flags & 0x10000) != 0) && (0 < WorldGraph.m_cLinks)) {
    iVar4 = 0;
    iVar2 = 0;
    iVar5 = WorldGraph.m_cLinks;
    do {
      while (*(entvars_t **)((WorldGraph.m_pLinkPool)->m_szLinkEntModelname + iVar4 + -4) != peVar3)
      {
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0x18;
        if (iVar5 <= iVar2) goto LAB_000f19b0;
      }
      pcVar1 = (WorldGraph.m_pLinkPool)->m_szLinkEntModelname + iVar4 + -4;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 0x18;
      peVar3 = this->pev;
      iVar5 = WorldGraph.m_cLinks;
    } while (iVar2 < WorldGraph.m_cLinks);
  }
LAB_000f19b0:
  if (peVar3->globalname != 0) {
    CGlobalState::EntitySetState(&gGlobalState,peVar3->globalname,GLOBAL_DEAD);
    peVar3 = this->pev;
  }
  if (0.0 < peVar3->health) {
    peVar3->health = 0.0;
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"SUB_Remove called on entity with health > 0\n");
    peVar3 = this->pev;
  }
                    /* WARNING: Could not recover jumptable at 0x000f1a16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnRemoveEntity)(peVar3->pContainingEntity);
  return;
}


// CBaseEntity::SUB_DoNothing  @ 000f1a20  (line 99)

/* DWARF original prototype: void SUB_DoNothing(CBaseEntity * this) */

void __thiscall CBaseEntity::SUB_DoNothing(CBaseEntity *this)

{
  return;
}


// CBaseDelay::Restore  @ 000f14a0  (line 110)

/* DWARF original prototype: int Restore(CBaseDelay * this, CRestore * restore) */

int __thiscall CBaseDelay::Restore(CBaseDelay *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore(&this->super_CBaseEntity,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CBaseDelay",this,m_SaveData,2);
  }
  return iVar2;
}


// CBaseDelay::Save  @ 000f1500  (line 110)

/* DWARF original prototype: int Save(CBaseDelay * this, CSave * save) */

int __thiscall CBaseDelay::Save(CBaseDelay *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save(&this->super_CBaseEntity,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CBaseDelay",this,m_SaveData,2);
  }
  return iVar2;
}


// CBaseDelay::KeyValue  @ 000f1330  (line 113)

/* DWARF original prototype: void KeyValue(CBaseDelay * this, KeyValueData * pkvd) */

void __thiscall CBaseDelay::KeyValue(CBaseDelay *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  double dVar5;
  
  bVar4 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar1 = 6;
  pcVar2 = pkvd->szKeyName;
  pcVar3 = "delay";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    dVar5 = strtod(pkvd->szValue,(char **)0x0);
    this->m_flDelay = (float)dVar5;
    pkvd->fHandled = 1;
  }
  else {
    iVar1 = 0xb;
    bVar4 = false;
    pcVar2 = pkvd->szKeyName;
    pcVar3 = "killtarget";
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
    iVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    this->m_iszKillTarget = iVar1;
    pkvd->fHandled = 1;
  }
  return;
}


// CBaseEntity::SUB_UseTargets  @ 000f1b10  (line 147)

/* DWARF original prototype: void SUB_UseTargets(CBaseEntity * this, CBaseEntity * pActivator,
   USE_TYPE useType, float value) */

void __thiscall
CBaseEntity::SUB_UseTargets(CBaseEntity *this,CBaseEntity *pActivator,USE_TYPE useType,float value)

{
  string_t sVar1;
  
  sVar1 = this->pev->target;
  if (sVar1 != 0) {
    FireTargets(gpGlobals->pStringBase + sVar1,pActivator,this,useType,value);
  }
  return;
}


// FireTargets  @ 000f1a30  (line 159)

void FireTargets(char *targetName,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
                float value)

{
  int *piVar1;
  int iVar2;
  edict_t *peVar3;
  
                    /* Unresolved local var: edict_t * pentTarget@[???] */
  if (targetName != (char *)0x0) {
                    /* Unresolved local var: edict_t * pentTarget@[???] */
    peVar3 = (edict_t *)0x0;
    (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"Firing: (%s)\n",targetName);
                    /* Unresolved local var: CBaseEntity * pTarget@[DW_OP_reg7(EDI)] */
    while (peVar3 = (*g_engfuncs.pfnFindEntityByString)(peVar3,"targetname",targetName),
          peVar3 != (edict_t *)0x0) {
      iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3);
      if (iVar2 == 0) {
        return;
      }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      piVar1 = peVar3->pvPrivateData;
      if ((piVar1 != (int *)0x0) && ((*(byte *)(piVar1[1] + 0x1a7) & 0x40) == 0)) {
        (*g_engfuncs.pfnAlertMessage)
                  (at_aiconsole,"Found: %s, firing (%s)\n",
                   gpGlobals->pStringBase + *(int *)piVar1[1],targetName);
        (**(code **)(*piVar1 + 0xb4))(piVar1,pActivator,pCaller,useType,value);
      }
    }
  }
  return;
}


// DelayedUse  @ 000f1e60  (line 181)

void DelayedUse(entvars_t *pev)

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
  *puVar1 = &PTR__CBaseDelay_0015b8f0;
  puVar1[1] = pev;
  return;
}


// CBaseDelay::SUB_UseTargets  @ 000f1b60  (line 184)

/* DWARF original prototype: void SUB_UseTargets(CBaseDelay * this, CBaseEntity * pActivator,
   USE_TYPE useType, float value) */

void __thiscall
CBaseDelay::SUB_UseTargets(CBaseDelay *this,CBaseEntity *pActivator,USE_TYPE useType,float value)

{
  string_t sVar1;
  entvars_t *peVar2;
  CBaseEntity *in_EAX;
  edict_t *peVar3;
  int iVar4;
  undefined4 *puVar5;
  USE_TYPE in_ECX;
  CBaseEntity *in_EDX;
  entvars_t *local_20;
  
  if ((float)in_EAX[1]._vptr_CBaseEntity != 0.0) {
                    /* Unresolved local var: CBaseDelay * pTemp@[DW_OP_reg1(ECX)]
                       Unresolved local var: entvars_t * pev@[???] */
    peVar3 = (*g_engfuncs.pfnCreateEntity)();
    local_20 = (entvars_t *)0x0;
    if (peVar3 != (edict_t *)0x0) {
      local_20 = &peVar3->v;
    }
    if ((local_20->pContainingEntity == (edict_t *)0x0) ||
       (puVar5 = local_20->pContainingEntity->pvPrivateData, puVar5 == (undefined4 *)0x0)) {
      puVar5 = CBaseEntity::operator_new(0x47c,local_20);
      *puVar5 = &PTR__CBaseDelay_0015b8f0;
      puVar5[1] = local_20;
    }
    else {
      local_20 = (entvars_t *)puVar5[1];
    }
    local_20->classname = (int)"DelayedUse" - (int)gpGlobals->pStringBase;
    *(float *)(puVar5[1] + 0x104) = gpGlobals->time + (float)in_EAX[1]._vptr_CBaseEntity;
    puVar5[4] = DelayThink;
    puVar5[5] = 0;
    *(USE_TYPE *)(puVar5[1] + 0x180) = in_ECX;
    peVar2 = in_EAX[1].pev;
    puVar5[0x11d] = 0;
    puVar5[0x11e] = peVar2;
    *(string_t *)(puVar5[1] + 0x1c8) = in_EAX->pev->target;
    return;
  }
  if (in_EAX[1].pev != (entvars_t *)0x0) {
                    /* Unresolved local var: edict_t * pentKillTarget@[???] */
    (*g_engfuncs.pfnAlertMessage)
              (at_aiconsole,"KillTarget: %s\n",
               gpGlobals->pStringBase + (int)&(in_EAX[1].pev)->classname);
    peVar3 = (*g_engfuncs.pfnFindEntityByString)
                       ((edict_t *)0x0,"targetname",
                        gpGlobals->pStringBase + (int)&(in_EAX[1].pev)->classname);
    if (peVar3 != (edict_t *)0x0) {
      iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3);
      while (iVar4 != 0) {
        UTIL_Remove(peVar3->pvPrivateData);
        (*g_engfuncs.pfnAlertMessage)
                  (at_aiconsole,"killing %s\n",gpGlobals->pStringBase + (peVar3->v).classname);
        peVar3 = (*g_engfuncs.pfnFindEntityByString)
                           (peVar3,"targetname",
                            gpGlobals->pStringBase + (int)&(in_EAX[1].pev)->classname);
        if (peVar3 == (edict_t *)0x0) break;
        iVar4 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3);
      }
    }
  }
  sVar1 = in_EAX->pev->target;
  if (sVar1 != 0) {
    FireTargets(gpGlobals->pStringBase + sVar1,in_EDX,in_EAX,in_ECX,(float)this);
    return;
  }
  return;
}


// CBaseDelay::SUB_UseTargets  @ 000f1ed0  (line 185)

/* DWARF original prototype: void SUB_UseTargets(CBaseDelay * this, CBaseEntity * pActivator,
   USE_TYPE useType, float value) */

void __thiscall
CBaseDelay::SUB_UseTargets(CBaseDelay *this,CBaseEntity *pActivator,USE_TYPE useType,float value)

{
  int iVar1;
  
  if (pActivator != (CBaseEntity *)0x0) {
    iVar1 = (*pActivator->_vptr_CBaseEntity[10])(pActivator);
    if (iVar1 != 2) goto LAB_000f1f04;
  }
  DoResults(&this->super_CBaseEntity,(CBasePlayer *)pActivator,1);
LAB_000f1f04:
  if ((((this->super_CBaseEntity).pev)->target == 0) && (this->m_iszKillTarget == 0)) {
    return;
  }
  SUB_UseTargets((CBaseDelay *)value,pActivator,useType,value);
  return;
}


// SetMovedir  @ 000f1f80  (line 260)

void SetMovedir(entvars_t *pev)

{
  float fVar1;
  _2globalvars_t *p1Var2;
  
  if ((pev->angles).x == 0.0) {
    fVar1 = (pev->angles).y;
    if (fVar1 == -1.0) {
      if ((pev->angles).z == 0.0) {
        (pev->movedir).x = 0.0;
        (pev->movedir).y = 0.0;
        (pev->movedir).z = 1.0;
        goto LAB_000f1ff2;
      }
    }
    else if ((fVar1 == -2.0) && ((pev->angles).z == 0.0)) {
      (pev->movedir).x = 0.0;
      (pev->movedir).y = 0.0;
      (pev->movedir).z = -1.0;
      goto LAB_000f1ff2;
    }
  }
  UTIL_MakeVectors(&pev->angles);
  p1Var2 = gpGlobals;
  (pev->movedir).x = (gpGlobals->v_forward).x;
  (pev->movedir).y = (p1Var2->v_forward).y;
  (pev->movedir).z = (p1Var2->v_forward).z;
LAB_000f1ff2:
  (pev->angles).x = g_vecZero.x;
  (pev->angles).y = g_vecZero.y;
  (pev->angles).z = g_vecZero.z;
  return;
}


// CBaseDelay::DelayThink  @ 000f1de0  (line 278)

/* DWARF original prototype: void DelayThink(CBaseDelay * this) */

void __thiscall CBaseDelay::DelayThink(CBaseDelay *this)

{
  entvars_t *peVar1;
  CBaseEntity *pActivator;
  USE_TYPE useType;
  float in_stack_fffffff0;
  
  pActivator = (CBaseEntity *)0x0;
  useType = USE_ON;
  DoResults(&this->super_CBaseEntity,(CBasePlayer *)0x0,1);
  peVar1 = (this->super_CBaseEntity).pev;
  if ((peVar1->target != 0) || (this->m_iszKillTarget != 0)) {
    SUB_UseTargets((CBaseDelay *)0x0,pActivator,useType,in_stack_fffffff0);
    peVar1 = (this->super_CBaseEntity).pev;
  }
                    /* WARNING: Could not recover jumptable at 0x000f1e3b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnRemoveEntity)(peVar1->pContainingEntity);
  return;
}


// CBaseToggle::Restore  @ 000f13e0  (line 308)

/* DWARF original prototype: int Restore(CBaseToggle * this, CRestore * restore) */

int __thiscall CBaseToggle::Restore(CBaseToggle *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseAnimating::Restore(&this->super_CBaseAnimating,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CBaseToggle",this,m_SaveData,0x13);
  }
  return iVar2;
}


// CBaseToggle::Save  @ 000f1440  (line 308)

/* DWARF original prototype: int Save(CBaseToggle * this, CSave * save) */

int __thiscall CBaseToggle::Save(CBaseToggle *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseAnimating::Save(&this->super_CBaseAnimating,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CBaseToggle",this,m_SaveData,0x13);
  }
  return iVar2;
}


// CBaseToggle::KeyValue  @ 000f1560  (line 312)

/* DWARF original prototype: void KeyValue(CBaseToggle * this, KeyValueData * pkvd) */

void __thiscall CBaseToggle::KeyValue(CBaseToggle *this,KeyValueData *pkvd)

{
  string_t sVar1;
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
  pcVar5 = "lip";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar3 == *pcVar5;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    dVar7 = strtod(pkvd->szValue,(char **)0x0);
    this->m_flLip = (float)dVar7;
    pkvd->fHandled = 1;
  }
  else {
    iVar2 = 5;
    bVar6 = false;
    pcVar3 = pcVar4;
    pcVar5 = "wait";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar3 == *pcVar5;
      pcVar3 = pcVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      dVar7 = strtod(pkvd->szValue,(char **)0x0);
      this->m_flWait = (float)dVar7;
      pkvd->fHandled = 1;
    }
    else {
      iVar2 = 7;
      bVar6 = false;
      pcVar3 = pcVar4;
      pcVar5 = "master";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
        this->m_sMaster = sVar1;
        pkvd->fHandled = 1;
      }
      else {
        iVar2 = 9;
        bVar6 = false;
        pcVar3 = pcVar4;
        pcVar5 = "distance";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar6 = *pcVar3 == *pcVar5;
          pcVar3 = pcVar3 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (bVar6) {
          dVar7 = strtod(pkvd->szValue,(char **)0x0);
          this->m_flMoveDistance = (float)dVar7;
          pkvd->fHandled = 1;
        }
        else {
          iVar2 = 6;
          bVar6 = false;
          pcVar3 = pcVar4;
          pcVar5 = "delay";
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar6 = *pcVar3 == *pcVar5;
            pcVar3 = pcVar3 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar6);
          if (bVar6) {
            dVar7 = strtod(pkvd->szValue,(char **)0x0);
            (this->super_CBaseAnimating).super_CBaseDelay.m_flDelay = (float)dVar7;
            pkvd->fHandled = 1;
          }
          else {
            iVar2 = 0xb;
            bVar6 = false;
            pcVar3 = "killtarget";
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
            iVar2 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
            (this->super_CBaseAnimating).super_CBaseDelay.m_iszKillTarget = iVar2;
            pkvd->fHandled = 1;
          }
        }
      }
    }
  }
  return;
}


// CBaseToggle::LinearMove  @ 000f2090  (line 346)

/* DWARF original prototype: void LinearMove(CBaseToggle * this, Vector vecDest, float flSpeed) */

void __thiscall CBaseToggle::LinearMove(CBaseToggle *this,Vector vecDest,float flSpeed)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float __x;
  entvars_t *peVar4;
  float fVar5;
  
                    /* Unresolved local var: Vector vecDestDelta@[???]
                       Unresolved local var: float flTravelTime@[???] */
  (this->m_vecFinalDest).x = *(vec_t *)vecDest.x;
  (this->m_vecFinalDest).y = *(vec_t *)((int)vecDest.x + 4);
  (this->m_vecFinalDest).z = *(vec_t *)((int)vecDest.x + 8);
  peVar4 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (peVar4->origin).x;
  fVar2 = (peVar4->origin).y;
  if (*(float *)vecDest.x == fVar1) {
    fVar3 = *(float *)((int)vecDest.x + 8);
    fVar5 = (peVar4->origin).z;
    if ((*(float *)((int)vecDest.x + 4) == fVar2) && (fVar3 == fVar5)) {
      LinearMoveDone(this);
      return;
    }
  }
  else {
    fVar3 = *(float *)((int)vecDest.x + 8);
    fVar5 = (peVar4->origin).z;
  }
  fVar3 = fVar3 - fVar5;
  fVar2 = *(float *)((int)vecDest.x + 4) - fVar2;
  fVar1 = *(float *)vecDest.x - fVar1;
  __x = fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1;
  fVar5 = SQRT(__x);
  if (NAN(fVar5)) {
    fVar5 = sqrtf(__x);
    peVar4 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  }
  fVar5 = fVar5 / vecDest.y;
  peVar4->nextthink = peVar4->ltime + fVar5;
  peVar4 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = LinearMoveDone;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  (peVar4->velocity).x = fVar1 / fVar5;
  (peVar4->velocity).y = fVar2 / fVar5;
  (peVar4->velocity).z = fVar3 / fVar5;
  return;
}


// CBaseToggle::LinearMoveDone  @ 000f2210  (line 380)

/* DWARF original prototype: void LinearMoveDone(CBaseToggle * this) */

void __thiscall CBaseToggle::LinearMoveDone(CBaseToggle *this)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  Vector vecDest;
  _func___thiscall_void_CBaseToggle_ptr *p_Var4;
  CBaseToggle *pCVar5;
  float fVar6;
  vec_t in_stack_ffffffe0;
  float in_stack_ffffffe4;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: Vector delta@[???]
                       Unresolved local var: float error@[???] */
  peVar1 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  fVar2 = (this->m_vecFinalDest).z - (peVar1->origin).z;
  fVar3 = (this->m_vecFinalDest).y - (peVar1->origin).y;
  fVar6 = (this->m_vecFinalDest).x - (peVar1->origin).x;
  fVar2 = fVar2 * fVar2 + fVar3 * fVar3 + fVar6 * fVar6;
  fVar6 = SQRT(fVar2);
  if (NAN(fVar6)) {
    fVar6 = sqrtf(fVar2);
  }
  if (0.03125 < fVar6) {
    local_18 = (this->m_vecFinalDest).x;
    local_14 = (this->m_vecFinalDest).y;
    local_10 = (this->m_vecFinalDest).z;
    vecDest.y = 100.0;
    vecDest.x = (vec_t)&local_18;
    vecDest.z = in_stack_ffffffe0;
    LinearMove(this,vecDest,in_stack_ffffffe4);
    return;
  }
                    /* Unresolved local var: Vector delta@[???]
                       Unresolved local var: float error@[???] */
  UTIL_SetOrigin((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev,
                 &this->m_vecFinalDest);
  peVar1 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->velocity).x = g_vecZero.x;
  (peVar1->velocity).y = g_vecZero.y;
  (peVar1->velocity).z = g_vecZero.z;
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->nextthink = -1.0;
  p_Var4 = (this->m_pfnCallWhenMoveDone).__pfn;
  if (p_Var4 != (_func___thiscall_void_CBaseToggle_ptr *)0x0) {
    pCVar5 = (CBaseToggle *)
             ((int)&(this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                    _vptr_CBaseEntity + (this->m_pfnCallWhenMoveDone).__delta);
    if (((uint)p_Var4 & 1) != 0) {
      p_Var4 = *(_func___thiscall_void_CBaseToggle_ptr **)
                (p_Var4 + (int)(pCVar5->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                               _vptr_CBaseEntity + -1);
    }
    (*p_Var4)(pCVar5);
  }
  return;
}


// CBaseToggle::IsLockedByMaster  @ 000f2330  (line 397)

/* DWARF original prototype: BOOL IsLockedByMaster(CBaseToggle * this) */

BOOL __thiscall CBaseToggle::IsLockedByMaster(CBaseToggle *this)

{
  int iVar1;
  
  if (this->m_sMaster != 0) {
    iVar1 = UTIL_IsMasterTriggered(this->m_sMaster);
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}


// CBaseToggle::AngularMove  @ 000f2370  (line 414)

/* DWARF original prototype: void AngularMove(CBaseToggle * this, Vector vecDestAngle, float
   flSpeed) */

void __thiscall CBaseToggle::AngularMove(CBaseToggle *this,Vector vecDestAngle,float flSpeed)

{
  float fVar1;
  float fVar2;
  float fVar3;
  vec_t vVar4;
  _func___thiscall_void_CBaseToggle_ptr *UNRECOVERED_JUMPTABLE;
  float __x;
  entvars_t *peVar5;
  CBaseToggle *pCVar6;
  float fVar7;
  
                    /* Unresolved local var: Vector vecDestDelta@[???]
                       Unresolved local var: float flTravelTime@[???] */
  vVar4 = *(vec_t *)vecDestAngle.x;
  (this->m_vecFinalAngle).x = vVar4;
  (this->m_vecFinalAngle).y = *(vec_t *)((int)vecDestAngle.x + 4);
  (this->m_vecFinalAngle).z = *(vec_t *)((int)vecDestAngle.x + 8);
  peVar5 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = (peVar5->angles).x;
  fVar2 = (peVar5->angles).y;
  if (*(float *)vecDestAngle.x == fVar1) {
    fVar3 = *(float *)((int)vecDestAngle.x + 8);
    fVar7 = (peVar5->angles).z;
    if ((*(float *)((int)vecDestAngle.x + 4) == fVar2) && (fVar3 == fVar7)) {
      (peVar5->angles).x = vVar4;
      (peVar5->angles).y = (this->m_vecFinalAngle).y;
      (peVar5->angles).z = (this->m_vecFinalAngle).z;
      peVar5 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
      (peVar5->avelocity).x = g_vecZero.x;
      (peVar5->avelocity).y = g_vecZero.y;
      (peVar5->avelocity).z = g_vecZero.z;
      ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->nextthink = -1.0;
      UNRECOVERED_JUMPTABLE = (this->m_pfnCallWhenMoveDone).__pfn;
      if (UNRECOVERED_JUMPTABLE == (_func___thiscall_void_CBaseToggle_ptr *)0x0) {
        return;
      }
      pCVar6 = (CBaseToggle *)
               ((int)&(this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                      _vptr_CBaseEntity + (this->m_pfnCallWhenMoveDone).__delta);
      if (((uint)UNRECOVERED_JUMPTABLE & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x000f24f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(pCVar6);
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x000f250e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(UNRECOVERED_JUMPTABLE +
                  (int)(pCVar6->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                       _vptr_CBaseEntity + -1))();
      return;
    }
  }
  else {
    fVar3 = *(float *)((int)vecDestAngle.x + 8);
    fVar7 = (peVar5->angles).z;
  }
  fVar3 = fVar3 - fVar7;
  fVar2 = *(float *)((int)vecDestAngle.x + 4) - fVar2;
  fVar1 = *(float *)vecDestAngle.x - fVar1;
  __x = fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1;
  fVar7 = SQRT(__x);
  if (NAN(fVar7)) {
    fVar7 = sqrtf(__x);
    peVar5 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  }
  fVar7 = fVar7 / vecDestAngle.y;
  peVar5->nextthink = peVar5->ltime + fVar7;
  peVar5 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__pfn = AngularMoveDone
  ;
  (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.m_pfnThink.__delta = 0;
  (peVar5->avelocity).x = fVar1 / fVar7;
  (peVar5->avelocity).y = fVar2 / fVar7;
  (peVar5->avelocity).z = fVar3 / fVar7;
  return;
}


// CBaseToggle::AngularMoveDone  @ 000f12a0  (line 448)

/* DWARF original prototype: void AngularMoveDone(CBaseToggle * this) */

void __thiscall CBaseToggle::AngularMoveDone(CBaseToggle *this)

{
  entvars_t *peVar1;
  _func___thiscall_void_CBaseToggle_ptr *UNRECOVERED_JUMPTABLE;
  CBaseToggle *pCVar2;
  
  peVar1 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->angles).x = (this->m_vecFinalAngle).x;
  (peVar1->angles).y = (this->m_vecFinalAngle).y;
  (peVar1->angles).z = (this->m_vecFinalAngle).z;
  peVar1 = (this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->avelocity).x = g_vecZero.x;
  (peVar1->avelocity).y = g_vecZero.y;
  (peVar1->avelocity).z = g_vecZero.z;
  ((this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->nextthink = -1.0;
  UNRECOVERED_JUMPTABLE = (this->m_pfnCallWhenMoveDone).__pfn;
  if (UNRECOVERED_JUMPTABLE == (_func___thiscall_void_CBaseToggle_ptr *)0x0) {
    return;
  }
  pCVar2 = (CBaseToggle *)
           ((int)&(this->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
           + (this->m_pfnCallWhenMoveDone).__delta);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x000f1308. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(pCVar2);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000f131a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(UNRECOVERED_JUMPTABLE +
              (int)(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                   _vptr_CBaseEntity + -1))();
  return;
}


// CBaseToggle::AxisValue  @ 000f2550  (line 458)

float CBaseToggle::AxisValue(int flags,Vector *angles)

{
  if ((flags & 0x40U) != 0) {
    return angles->z;
  }
  if ((flags & 0x80U) == 0) {
    return angles->y;
  }
  return angles->x;
}


// CBaseToggle::AxisDir  @ 000f2580  (line 469)

void CBaseToggle::AxisDir(entvars_t *pev)

{
  if ((pev->spawnflags & 0x40U) != 0) {
    (pev->movedir).x = 0.0;
    (pev->movedir).y = 0.0;
    (pev->movedir).z = 1.0;
    return;
  }
  if ((pev->spawnflags & 0x80U) == 0) {
    (pev->movedir).x = 0.0;
    (pev->movedir).y = 1.0;
    (pev->movedir).z = 0.0;
    return;
  }
  (pev->movedir).x = 1.0;
  (pev->movedir).y = 0.0;
  (pev->movedir).z = 0.0;
  return;
}


// CBaseToggle::AxisDelta  @ 000f25f0  (line 480)

float CBaseToggle::AxisDelta(int flags,Vector *angle1,Vector *angle2)

{
  if ((flags & 0x40U) != 0) {
    return angle1->z - angle2->z;
  }
  if ((flags & 0x80U) == 0) {
    return angle1->y - angle2->y;
  }
  return angle1->x - angle2->x;
}


// FEntIsVisible  @ 000f2630  (line 502)

BOOL FEntIsVisible(entvars_t *pev,entvars_t *pevTarget)

{
  uint uVar1;
  Vector local_5c;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: Vector vecSpot1@[???]
                       Unresolved local var: Vector vecSpot2@[???]
                       Unresolved local var: TraceResult tr@[???] */
  local_5c.z = (pev->origin).z + (pev->view_ofs).z;
  local_5c.y = (pev->origin).y + (pev->view_ofs).y;
  local_5c.x = (pev->origin).x + (pev->view_ofs).x;
  local_50.z = (pevTarget->origin).z + (pevTarget->view_ofs).z;
  local_50.y = (pevTarget->origin).y + (pevTarget->view_ofs).y;
  local_50.x = (pevTarget->origin).x + (pevTarget->view_ofs).x;
  UTIL_TraceLine(&local_5c,&local_50,ignore_monsters,pev->pContainingEntity,&local_44);
  if (((local_44.fInOpen == 0) || (uVar1 = 0, local_44.fInWater == 0)) &&
     (uVar1 = (uint)!NAN(local_44.flFraction), local_44.flFraction != 1.0)) {
    uVar1 = 0;
  }
  return uVar1;
}


