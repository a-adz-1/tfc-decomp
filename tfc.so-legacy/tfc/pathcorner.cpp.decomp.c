// Ghidra decompilation of functions from tfc/pathcorner.cpp
// 23 functions, ordered by original source line

// CPathCorner::GetDelay  @ 000f9b80  (line 25)

/* DWARF original prototype: float GetDelay(CPathCorner * this) */

float __thiscall CPathCorner::GetDelay(CPathCorner *this)

{
  return this->m_flWait;
}


// path_corner  @ 000f8f00  (line 36)

void path_corner(entvars_t *pev)

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
  *puVar1 = &PTR__CPathCorner_00186ce8;
  puVar1[1] = pev;
  return;
}


// CPathCorner::Restore  @ 000f8be0  (line 44)

/* DWARF original prototype: int Restore(CPathCorner * this, CRestore * restore) */

int __thiscall CPathCorner::Restore(CPathCorner *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore((CBaseEntity *)this,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CPathCorner",this,m_SaveData,1);
  }
  return iVar2;
}


// CPathCorner::Save  @ 000f8ca0  (line 44)

/* DWARF original prototype: int Save(CPathCorner * this, CSave * save) */

int __thiscall CPathCorner::Save(CPathCorner *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save((CBaseEntity *)this,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CPathCorner",this,m_SaveData,1);
  }
  return iVar2;
}


// CPathCorner::KeyValue  @ 000f8d80  (line 50)

/* DWARF original prototype: void KeyValue(CPathCorner * this, KeyValueData * pkvd) */

void __thiscall CPathCorner::KeyValue(CPathCorner *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  double dVar5;
  
  bVar4 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar1 = 5;
  pcVar2 = pkvd->szKeyName;
  pcVar3 = "wait";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (!bVar4) {
    CBaseEntity::KeyValue((CBaseEntity *)this,pkvd);
    return;
  }
  dVar5 = strtod(pkvd->szValue,(char **)0x0);
  this->m_flWait = (float)dVar5;
  pkvd->fHandled = 1;
  return;
}


// CPathCorner::Spawn  @ 000f8a40  (line 64)

/* DWARF original prototype: void Spawn(CPathCorner * this) */

void __thiscall CPathCorner::Spawn(CPathCorner *this)

{
  return;
}


// CPathTrack::Restore  @ 000f8b80  (line 125)

/* DWARF original prototype: int Restore(CPathTrack * this, CRestore * restore) */

int __thiscall CPathTrack::Restore(CPathTrack *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore((CBaseEntity *)this,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CPathTrack",this,m_SaveData,5);
  }
  return iVar2;
}


// CPathTrack::Save  @ 000f8c40  (line 125)

/* DWARF original prototype: int Save(CPathTrack * this, CSave * save) */

int __thiscall CPathTrack::Save(CPathTrack *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save((CBaseEntity *)this,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CPathTrack",this,m_SaveData,5);
  }
  return iVar2;
}


// path_track  @ 000f8f70  (line 126)

void path_track(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x488,pev);
  *puVar1 = &PTR__CPathTrack_00186e08;
  puVar1[1] = pev;
  return;
}


// CPathTrack::KeyValue  @ 000f8d00  (line 132)

/* DWARF original prototype: void KeyValue(CPathTrack * this, KeyValueData * pkvd) */

void __thiscall CPathTrack::KeyValue(CPathTrack *this,KeyValueData *pkvd)

{
  string_t sVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar2 = 8;
  pcVar3 = pkvd->szKeyName;
  pcVar4 = "altpath";
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
  sVar1 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
  this->m_altName = sVar1;
  pkvd->fHandled = 1;
  return;
}


// CPathTrack::Use  @ 000f8ac0  (line 143)

/* DWARF original prototype: void Use(CPathTrack * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CPathTrack::Use(CPathTrack *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
               float value)

{
  int *piVar1;
  entvars_t *peVar2;
  int iVar3;
  uint uVar4;
  
                    /* Unresolved local var: int on@[???] */
  peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if (this->m_paltpath == (CPathTrack *)0x0) {
                    /* Unresolved local var: int on@[DW_OP_reg6(ESI)] */
    uVar4 = peVar2->spawnflags & 1U ^ 1;
    iVar3 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,uVar4);
    if (iVar3 != 0) {
      peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
      if (uVar4 == 0) {
        piVar1 = &peVar2->spawnflags;
        *piVar1 = *piVar1 & 0xfffffffe;
      }
      else {
        piVar1 = &peVar2->spawnflags;
        *piVar1 = *piVar1 | 1;
      }
    }
  }
  else {
    uVar4 = (uint)((peVar2->spawnflags & 0x8000) == 0);
    iVar3 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,uVar4);
    if (iVar3 != 0) {
      peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
      if (uVar4 == 0) {
        piVar1 = &peVar2->spawnflags;
        *piVar1 = *piVar1 & 0xffff7fff;
        return;
      }
      piVar1 = &peVar2->spawnflags;
      *piVar1 = *piVar1 | 0x8000;
    }
  }
  return;
}


// CPathTrack::Link  @ 000f8fe0  (line 174)

/* DWARF original prototype: void Link(CPathTrack * this) */

void __thiscall CPathTrack::Link(CPathTrack *this)

{
  string_t sVar1;
  CPathTrack *pCVar2;
  globalvars_t *pgVar3;
  edict_t *peVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  byte bVar9;
  
  bVar9 = 0;
                    /* Unresolved local var: edict_t * pentTarget@[???] */
  sVar1 = ((this->super_CPointEntity).super_CBaseEntity.pev)->target;
  if (sVar1 != 0) {
    peVar4 = (*g_engfuncs.pfnFindEntityByString)
                       ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + sVar1);
    if (peVar4 != (edict_t *)0x0) {
      iVar5 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4);
      pgVar3 = gpGlobals;
      if (iVar5 != 0) {
        bVar8 = gpGlobals->pStringBase + (peVar4->v).classname == (char *)0x0;
        iVar5 = 0xb;
        pcVar6 = gpGlobals->pStringBase + (peVar4->v).classname;
        pcVar7 = "path_track";
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar8 = *pcVar6 == *pcVar7;
          pcVar6 = pcVar6 + (uint)bVar9 * -2 + 1;
          pcVar7 = pcVar7 + (uint)bVar9 * -2 + 1;
        } while (bVar8);
        if (bVar8) {
          pCVar2 = peVar4->pvPrivateData;
          this->m_pnext = pCVar2;
          if (pCVar2 != (CPathTrack *)0x0) {
            iVar5 = strcmp(pgVar3->pStringBase +
                           ((this->super_CPointEntity).super_CBaseEntity.pev)->targetname,
                           pgVar3->pStringBase + pCVar2->m_altName);
            if (iVar5 != 0) {
              pCVar2->m_pprevious = this;
            }
          }
        }
        else {
          this->m_pnext = (CPathTrack *)0x0;
        }
        goto LAB_000f9008;
      }
    }
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"Dead end link %s\n",
               gpGlobals->pStringBase + ((this->super_CPointEntity).super_CBaseEntity.pev)->target);
  }
LAB_000f9008:
  if (this->m_altName != 0) {
    peVar4 = (*g_engfuncs.pfnFindEntityByString)
                       ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_altName);
    if (peVar4 != (edict_t *)0x0) {
      iVar5 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4);
      pgVar3 = gpGlobals;
      if (iVar5 != 0) {
        iVar5 = 0xb;
        bVar8 = gpGlobals->pStringBase + (peVar4->v).classname == (char *)0x0;
        pcVar6 = gpGlobals->pStringBase + (peVar4->v).classname;
        pcVar7 = "path_track";
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar8 = *pcVar6 == *pcVar7;
          pcVar6 = pcVar6 + (uint)bVar9 * -2 + 1;
          pcVar7 = pcVar7 + (uint)bVar9 * -2 + 1;
        } while (bVar8);
        if (bVar8) {
          pCVar2 = peVar4->pvPrivateData;
          this->m_paltpath = pCVar2;
          if (pCVar2 != (CPathTrack *)0x0) {
            iVar5 = strcmp(pgVar3->pStringBase +
                           ((this->super_CPointEntity).super_CBaseEntity.pev)->targetname,
                           pgVar3->pStringBase + pCVar2->m_altName);
            if (iVar5 != 0) {
              pCVar2->m_pprevious = this;
            }
          }
        }
        else {
          this->m_paltpath = (CPathTrack *)0x0;
        }
      }
    }
  }
  return;
}


// CPathTrack::Spawn  @ 000f8a50  (line 211)

/* DWARF original prototype: void Spawn(CPathTrack * this) */

void __thiscall CPathTrack::Spawn(CPathTrack *this)

{
  Vector local_24;
  Vector local_18;
  
  ((this->super_CPointEntity).super_CBaseEntity.pev)->solid = 1;
  local_18.x = 8.0;
  local_18.y = 8.0;
  local_18.z = 8.0;
  local_24.x = -8.0;
  local_24.y = -8.0;
  local_24.z = -8.0;
  UTIL_SetSize((this->super_CPointEntity).super_CBaseEntity.pev,&local_24,&local_18);
  this->m_pnext = (CPathTrack *)0x0;
  this->m_pprevious = (CPathTrack *)0x0;
  return;
}


// CPathTrack::Activate  @ 000f91f0  (line 226)

/* DWARF original prototype: void Activate(CPathTrack * this) */

void __thiscall CPathTrack::Activate(CPathTrack *this)

{
  if (((this->super_CPointEntity).super_CBaseEntity.pev)->targetname == 0) {
    return;
  }
  Link(this);
  return;
}


// CPathTrack::ValidPath  @ 000f9210  (line 232)

/* DWARF original prototype: CPathTrack * ValidPath(CPathTrack * this, CPathTrack * ppath, int
   testFlag) */

CPathTrack * __thiscall CPathTrack::ValidPath(CPathTrack *this,CPathTrack *ppath,int testFlag)

{
  if (((ppath != (CPathTrack *)0x0) && (testFlag != 0)) &&
     ((((ppath->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 1) != 0)) {
    ppath = (CPathTrack *)0x0;
  }
  return ppath;
}


// CPathTrack::Project  @ 000f8e10  (line 243)

/* DWARF original prototype: void Project(CPathTrack * this, CPathTrack * pstart, CPathTrack * pend,
   Vector * origin, float dist) */

void __thiscall
CPathTrack::Project(CPathTrack *this,CPathTrack *pstart,CPathTrack *pend,Vector *origin,float dist)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  int in_EAX;
  int iVar6;
  float *in_ECX;
  int in_EDX;
  float fVar7;
  
                    /* Unresolved local var: Vector dir@[???] */
  iVar3 = *(int *)(in_EAX + 4);
  iVar6 = *(int *)(in_EDX + 4);
  fVar5 = *(float *)(iVar6 + 0x10) - *(float *)(iVar3 + 0x10);
  fVar1 = *(float *)(iVar6 + 0xc) - *(float *)(iVar3 + 0xc);
  fVar2 = *(float *)(iVar6 + 8) - *(float *)(iVar3 + 8);
                    /* Unresolved local var: float flLen@[???] */
  fVar4 = fVar5 * fVar5 + fVar1 * fVar1 + fVar2 * fVar2;
  fVar7 = SQRT(fVar4);
  if (NAN(fVar7)) {
    fVar7 = sqrtf(fVar4);
    iVar6 = *(int *)(in_EDX + 4);
  }
  fVar4 = 0.0;
  if (fVar7 == 0.0) {
    fVar5 = 1.0;
    fVar7 = fVar4;
  }
  else {
    fVar7 = 1.0 / fVar7;
    fVar5 = fVar5 * fVar7;
    fVar4 = fVar7 * fVar2;
    fVar7 = fVar1 * fVar7;
  }
  fVar1 = *(float *)(iVar6 + 0x10);
  fVar2 = *(float *)(iVar6 + 0xc);
  *in_ECX = (float)this * fVar4 + *(float *)(iVar6 + 8);
  in_ECX[1] = fVar7 * (float)this + fVar2;
  in_ECX[2] = fVar5 * (float)this + fVar1;
  return;
}


// CPathTrack::Project  @ 000f9240  (line 244)

/* DWARF original prototype: void Project(CPathTrack * this, CPathTrack * pstart, CPathTrack * pend,
   Vector * origin, float dist) */

void __thiscall
CPathTrack::Project(CPathTrack *this,CPathTrack *pstart,CPathTrack *pend,Vector *origin,float dist)

{
  if ((pend != (CPathTrack *)0x0) && (pstart != (CPathTrack *)0x0)) {
    Project((CPathTrack *)dist,pstart,pend,origin,dist);
    return;
  }
  return;
}


// CPathTrack::GetNext  @ 000f9270  (line 254)

/* DWARF original prototype: CPathTrack * GetNext(CPathTrack * this) */

CPathTrack * __thiscall CPathTrack::GetNext(CPathTrack *this)

{
  CPathTrack *pCVar1;
  
  pCVar1 = this->m_paltpath;
  if ((pCVar1 == (CPathTrack *)0x0) ||
     ((((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8004U) != 0x8000)) {
    pCVar1 = this->m_pnext;
  }
  return pCVar1;
}


// CPathTrack::GetPrevious  @ 000f92a0  (line 264)

/* DWARF original prototype: CPathTrack * GetPrevious(CPathTrack * this) */

CPathTrack * __thiscall CPathTrack::GetPrevious(CPathTrack *this)

{
  CPathTrack *pCVar1;
  
  pCVar1 = this->m_paltpath;
  if ((pCVar1 == (CPathTrack *)0x0) ||
     ((((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8004U) != 0x8004)) {
    pCVar1 = this->m_pprevious;
  }
  return pCVar1;
}


// CPathTrack::SetPrevious  @ 000f92d0  (line 274)

/* DWARF original prototype: void SetPrevious(CPathTrack * this, CPathTrack * pprev) */

void __thiscall CPathTrack::SetPrevious(CPathTrack *this,CPathTrack *pprev)

{
  int iVar1;
  
  if (pprev != (CPathTrack *)0x0) {
    iVar1 = strcmp(gpGlobals->pStringBase +
                   ((pprev->super_CPointEntity).super_CBaseEntity.pev)->targetname,
                   gpGlobals->pStringBase + this->m_altName);
    if (iVar1 != 0) {
      this->m_pprevious = pprev;
    }
  }
  return;
}


// CPathTrack::LookAhead  @ 000f9330  (line 283)

/* DWARF original prototype: CPathTrack * LookAhead(CPathTrack * this, Vector * origin, float dist,
   int move) */

CPathTrack * __thiscall CPathTrack::LookAhead(CPathTrack *this,Vector *origin,float dist,int move)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  CPathTrack *pCVar8;
  CPathTrack *pCVar9;
  CPathTrack *pCVar10;
  float fVar11;
  float fVar12;
  CPathTrack *in_stack_ffffff78;
  CPathTrack *in_stack_ffffff7c;
  Vector *in_stack_ffffff80;
  float in_stack_ffffff84;
  CPathTrack *local_14;
  float local_10;
  
                    /* Unresolved local var: CPathTrack * pcurrent@[???]
                       Unresolved local var: float originalDist@[???]
                       Unresolved local var: Vector currentPos@[???] */
  fVar1 = origin->x;
  fVar2 = origin->y;
  local_10 = origin->z;
  pCVar8 = (CPathTrack *)dist;
  if (dist < 0.0) {
    local_14 = (CPathTrack *)-dist;
    while( true ) {
      pCVar8 = this;
      if ((float)local_14 <= 0.0) {
        origin->x = fVar1;
        origin->y = fVar2;
        origin->z = local_10;
        return pCVar8;
      }
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: float length@[???] */
      peVar3 = (pCVar8->super_CPointEntity).super_CBaseEntity.pev;
      fVar12 = (peVar3->origin).z - local_10;
      fVar5 = (peVar3->origin).y - fVar2;
      fVar7 = (peVar3->origin).x - fVar1;
      fVar6 = fVar12 * fVar12 + fVar5 * fVar5 + fVar7 * fVar7;
      fVar11 = SQRT(fVar6);
      if (NAN(fVar11)) {
        fVar11 = sqrtf(fVar6);
      }
      if (fVar11 != 0.0) {
        if ((float)local_14 < fVar11) {
          fVar11 = (float)local_14 / fVar11;
          origin->x = fVar7 * fVar11 + fVar1;
          origin->y = fVar5 * fVar11 + fVar2;
          origin->z = fVar12 * fVar11 + local_10;
          return pCVar8;
        }
        local_14 = (CPathTrack *)((float)local_14 - fVar11);
        peVar3 = (pCVar8->super_CPointEntity).super_CBaseEntity.pev;
        fVar1 = (peVar3->origin).x;
        fVar2 = (peVar3->origin).y;
        local_10 = (peVar3->origin).z;
        origin->x = fVar1;
        origin->y = fVar2;
        origin->z = local_10;
        this = pCVar8->m_paltpath;
        if (((this == (CPathTrack *)0x0) ||
            (pCVar9 = this,
            (((pCVar8->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8004U) != 0x8004))
           && (pCVar9 = pCVar8->m_pprevious, pCVar8->m_pprevious == (CPathTrack *)0x0)) {
          return (CPathTrack *)0x0;
        }
        if ((move != 0) &&
           ((((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 1) != 0)) {
          return (CPathTrack *)0x0;
        }
        if (this != (CPathTrack *)0x0) {
          uVar4 = ((pCVar8->super_CPointEntity).super_CBaseEntity.pev)->spawnflags;
          goto joined_r0x000f96fc;
        }
        goto LAB_000f95d2;
      }
      this = pCVar8->m_paltpath;
      if (((this == (CPathTrack *)0x0) ||
          (pCVar9 = this,
          (((pCVar8->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8004U) != 0x8004))
         && (pCVar9 = pCVar8->m_pprevious, pCVar8->m_pprevious == (CPathTrack *)0x0)) break;
      if ((move != 0) &&
         ((((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 1) != 0)) {
        return (CPathTrack *)0x0;
      }
      if (this == (CPathTrack *)0x0) goto LAB_000f95d2;
      uVar4 = ((pCVar8->super_CPointEntity).super_CBaseEntity.pev)->spawnflags;
joined_r0x000f96fc:
      if ((uVar4 & 0x8004) != 0x8004) {
LAB_000f95d2:
        this = pCVar8->m_pprevious;
      }
    }
    if (move == 0) {
      if ((this == (CPathTrack *)0x0) ||
         ((((pCVar8->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8004U) != 0x8000)) {
        this = pCVar8->m_pnext;
      }
      if (this != (CPathTrack *)0x0) {
        Project(local_14,in_stack_ffffff78,in_stack_ffffff7c,in_stack_ffffff80,in_stack_ffffff84);
      }
    }
  }
  else {
    while( true ) {
      if ((float)pCVar8 <= 0.0) {
        origin->x = fVar1;
        origin->y = fVar2;
        origin->z = local_10;
        return this;
      }
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: float length@[???] */
      pCVar9 = this->m_paltpath;
      if (((pCVar9 == (CPathTrack *)0x0) ||
          (pCVar10 = pCVar9,
          (((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8004U) != 0x8000)) &&
         (pCVar10 = this->m_pnext, this->m_pnext == (CPathTrack *)0x0)) break;
      if ((move != 0) &&
         ((((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 1) != 0)) {
        return (CPathTrack *)0x0;
      }
      if ((pCVar9 == (CPathTrack *)0x0) ||
         ((((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8004U) != 0x8000)) {
        pCVar9 = this->m_pnext;
      }
      peVar3 = (pCVar9->super_CPointEntity).super_CBaseEntity.pev;
      fVar6 = (peVar3->origin).z - local_10;
      fVar11 = (peVar3->origin).y - fVar2;
      fVar5 = (peVar3->origin).x - fVar1;
      fVar7 = fVar6 * fVar6 + fVar5 * fVar5 + fVar11 * fVar11;
      fVar12 = SQRT(fVar7);
      if (NAN(fVar12)) {
        fVar12 = sqrtf(fVar7);
      }
      if (fVar12 == 0.0) {
        pCVar9 = this->m_paltpath;
        if ((pCVar9 == (CPathTrack *)0x0) ||
           ((((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8004U) != 0x8000)) {
          pCVar9 = this->m_pnext;
        }
        pCVar10 = pCVar9->m_paltpath;
        if ((((pCVar10 == (CPathTrack *)0x0) ||
             ((((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8004U) != 0x8000
             )) && (pCVar10 = pCVar9->m_pnext, pCVar10 == (CPathTrack *)0x0)) ||
           ((move != 0 &&
            ((((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 1) != 0)))) {
          if ((float)pCVar8 != dist) {
            return this;
          }
          return (CPathTrack *)0x0;
        }
      }
      if ((float)pCVar8 < fVar12) {
        fVar12 = (float)pCVar8 / fVar12;
        origin->x = fVar5 * fVar12 + fVar1;
        origin->y = fVar11 * fVar12 + fVar2;
        origin->z = fVar12 * fVar6 + local_10;
        return this;
      }
      pCVar9 = this->m_paltpath;
      if ((pCVar9 == (CPathTrack *)0x0) ||
         ((((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8004U) != 0x8000)) {
        pCVar9 = this->m_pnext;
        peVar3 = (pCVar9->super_CPointEntity).super_CBaseEntity.pev;
        fVar1 = (peVar3->origin).x;
        fVar2 = (peVar3->origin).y;
        local_10 = (peVar3->origin).z;
      }
      else {
        peVar3 = (pCVar9->super_CPointEntity).super_CBaseEntity.pev;
        fVar1 = (peVar3->origin).x;
        fVar2 = (peVar3->origin).y;
        local_10 = (peVar3->origin).z;
      }
      origin->x = fVar1;
      origin->y = fVar2;
      origin->z = local_10;
      this = pCVar9;
      pCVar8 = (CPathTrack *)((float)pCVar8 - fVar12);
    }
    if (move == 0) {
      if ((pCVar9 == (CPathTrack *)0x0) ||
         ((((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8004U) != 0x8004)) {
        pCVar9 = this->m_pprevious;
      }
      if (pCVar9 != (CPathTrack *)0x0) {
        Project(pCVar8,in_stack_ffffff78,in_stack_ffffff7c,in_stack_ffffff80,in_stack_ffffff84);
        return (CPathTrack *)0x0;
      }
    }
  }
  return (CPathTrack *)0x0;
}


// CPathTrack::Nearest  @ 000f9990  (line 366)

/* DWARF original prototype: CPathTrack * Nearest(CPathTrack * this, Vector origin) */

CPathTrack * __thiscall CPathTrack::Nearest(CPathTrack *this,Vector origin)

{
  entvars_t *peVar1;
  float fVar2;
  CPathTrack *pCVar3;
  CPathTrack *pCVar4;
  CPathTrack *pCVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  
                    /* Unresolved local var: int deadCount@[???]
                       Unresolved local var: float minDist@[???]
                       Unresolved local var: float dist@[???]
                       Unresolved local var: Vector delta@[???]
                       Unresolved local var: CPathTrack * ppath@[???]
                       Unresolved local var: CPathTrack * pnearest@[???] */
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  fVar7 = *(float *)((int)origin.x + 4) - (peVar1->origin).y;
  fVar8 = *(float *)origin.x - (peVar1->origin).x;
  fVar7 = fVar7 * fVar7 + fVar8 * fVar8 + 0.0;
  fVar8 = SQRT(fVar7);
  if (NAN(fVar8)) {
    fVar8 = sqrtf(fVar7);
  }
  pCVar4 = this->m_paltpath;
  if ((pCVar4 == (CPathTrack *)0x0) ||
     ((((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8004U) != 0x8000)) {
    pCVar4 = this->m_pnext;
  }
  iVar6 = 10000;
  pCVar3 = this;
  do {
    pCVar5 = pCVar4;
    if (pCVar4 == this) {
      return pCVar3;
    }
    while( true ) {
      if (pCVar5 == (CPathTrack *)0x0) {
        return pCVar3;
      }
      iVar6 = iVar6 + -1;
      if (iVar6 == 0) {
        (*g_engfuncs.pfnAlertMessage)
                  (at_error,"Bad sequence of path_tracks from %s",
                   gpGlobals->pStringBase +
                   ((this->super_CPointEntity).super_CBaseEntity.pev)->targetname);
        return (CPathTrack *)0x0;
      }
      peVar1 = (pCVar5->super_CPointEntity).super_CBaseEntity.pev;
      fVar2 = *(float *)((int)origin.x + 4) - (peVar1->origin).y;
      fVar7 = *(float *)origin.x - (peVar1->origin).x;
      fVar2 = fVar2 * fVar2 + fVar7 * fVar7 + 0.0;
      fVar7 = SQRT(fVar2);
      if (NAN(fVar7)) {
        fVar7 = sqrtf(fVar2);
      }
      if (fVar7 < fVar8) {
        pCVar3 = pCVar5;
        fVar8 = fVar7;
      }
      pCVar4 = pCVar5->m_paltpath;
      if ((pCVar4 != (CPathTrack *)0x0) &&
         ((((pCVar5->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8004U) == 0x8000))
      break;
      pCVar5 = pCVar5->m_pnext;
      if (pCVar5 == this) {
        return pCVar3;
      }
    }
  } while( true );
}


// CPathTrack::Instance  @ 000f9b20  (line 404)

CPathTrack * CPathTrack::Instance(edict_t *pent)

{
  entvars_t *peVar1;
  CPathTrack *pCVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  
  peVar1 = (entvars_t *)0x0;
  if (pent != (edict_t *)0x0) {
    peVar1 = &pent->v;
  }
  iVar3 = 0xb;
  bVar6 = CARRY4((uint)gpGlobals->pStringBase,peVar1->classname);
  pbVar4 = (byte *)(gpGlobals->pStringBase + peVar1->classname);
  bVar7 = pbVar4 == (byte *)0x0;
  pbVar5 = (byte *)"path_track";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pbVar4 < *pbVar5;
    bVar7 = *pbVar4 == *pbVar5;
    pbVar4 = pbVar4 + 1;
    pbVar5 = pbVar5 + 1;
  } while (bVar7);
  pCVar2 = (CPathTrack *)0x0;
  if (((!bVar6 && !bVar7) == bVar6) && (pent != (edict_t *)0x0)) {
    pCVar2 = pent->pvPrivateData;
  }
  return pCVar2;
}


