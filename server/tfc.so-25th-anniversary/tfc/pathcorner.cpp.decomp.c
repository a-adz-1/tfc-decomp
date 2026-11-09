// Ghidra decompilation of functions from tfc/pathcorner.cpp
// 24 functions, ordered by original source line

// CPathCorner::~CPathCorner  @ 000c0960  (line 20)

/* DWARF original prototype: void ~CPathCorner(CPathCorner * this, int __in_chrg) */

void __thiscall CPathCorner::~CPathCorner(CPathCorner *this,int __in_chrg)

{
  return;
}


// CPathCorner::GetDelay  @ 000c0940  (line 25)

/* DWARF original prototype: float GetDelay(CPathCorner * this) */

float __thiscall CPathCorner::GetDelay(CPathCorner *this)

{
  return this->m_flWait;
}


// path_corner  @ 000bfbd0  (line 36)

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
  *puVar1 = &PTR__CPathCorner_00155de4;
  puVar1[1] = pev;
  return;
}


// CPathCorner::Restore  @ 000bf890  (line 44)

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


// CPathCorner::Save  @ 000bf950  (line 44)

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


// CPathCorner::KeyValue  @ 000bf6d0  (line 50)

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


// CPathCorner::Spawn  @ 000bf4f0  (line 62)

/* DWARF original prototype: void Spawn(CPathCorner * this) */

void __thiscall CPathCorner::Spawn(CPathCorner *this)

{
  return;
}


// CPathTrack::Restore  @ 000bf830  (line 125)

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


// CPathTrack::Save  @ 000bf8f0  (line 125)

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


// path_track  @ 000bfc40  (line 126)

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
  *puVar1 = &PTR__CPathTrack_00155ef0;
  puVar1[1] = pev;
  return;
}


// CPathTrack::KeyValue  @ 000bf650  (line 132)

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


// CPathTrack::Use  @ 000bf760  (line 143)

/* DWARF original prototype: void Use(CPathTrack * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CPathTrack::Use(CPathTrack *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
               float value)

{
  int *piVar1;
  entvars_t *peVar2;
  uint uVar3;
  int iVar4;
  
                    /* Unresolved local var: int on@[???] */
  peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if (this->m_paltpath == (CPathTrack *)0x0) {
                    /* Unresolved local var: int on@[???] */
    uVar3 = peVar2->spawnflags & 1;
    iVar4 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,uVar3 ^ 1);
    if (iVar4 != 0) {
      peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
      if (uVar3 == 0) {
        piVar1 = &peVar2->spawnflags;
        *piVar1 = *piVar1 | 1;
      }
      else {
        piVar1 = &peVar2->spawnflags;
        *piVar1 = *piVar1 & 0xfffffffe;
      }
    }
  }
  else {
    uVar3 = peVar2->spawnflags & 0x8000;
    iVar4 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,(uint)(uVar3 == 0));
    if (iVar4 != 0) {
      peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
      if (uVar3 != 0) {
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


// CPathTrack::Link  @ 000bfcb0  (line 174)

/* DWARF original prototype: void Link(CPathTrack * this) */

void __thiscall CPathTrack::Link(CPathTrack *this)

{
  string_t sVar1;
  CPathTrack *pCVar2;
  _2globalvars_t *p1Var3;
  edict_t *peVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  byte bVar9;
  
                    /* Unresolved local var: edict_t * pentTarget@[???] */
  bVar9 = 0;
  sVar1 = ((this->super_CPointEntity).super_CBaseEntity.pev)->target;
  if (sVar1 != 0) {
    peVar4 = (*g_engfuncs.pfnFindEntityByString)
                       ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + sVar1);
    if (peVar4 != (edict_t *)0x0) {
      iVar5 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4);
      p1Var3 = gpGlobals;
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
          this->m_pnext = pCVar2;
          if ((this != (CPathTrack *)0x0) && (pCVar2 != (CPathTrack *)0x0)) {
            iVar5 = strcmp(p1Var3->pStringBase +
                           ((this->super_CPointEntity).super_CBaseEntity.pev)->targetname,
                           p1Var3->pStringBase + pCVar2->m_altName);
            if (iVar5 != 0) {
              pCVar2->m_pprevious = this;
            }
          }
        }
        else {
          this->m_pnext = (CPathTrack *)0x0;
        }
        goto LAB_000bfcd8;
      }
    }
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"Dead end link %s\n",
               gpGlobals->pStringBase + ((this->super_CPointEntity).super_CBaseEntity.pev)->target);
  }
LAB_000bfcd8:
  if (this->m_altName != 0) {
    peVar4 = (*g_engfuncs.pfnFindEntityByString)
                       ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_altName);
    if (peVar4 != (edict_t *)0x0) {
      iVar5 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4);
      p1Var3 = gpGlobals;
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
          if ((this != (CPathTrack *)0x0) && (pCVar2 != (CPathTrack *)0x0)) {
            iVar5 = strcmp(p1Var3->pStringBase +
                           ((this->super_CPointEntity).super_CBaseEntity.pev)->targetname,
                           p1Var3->pStringBase + pCVar2->m_altName);
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


// CPathTrack::Spawn  @ 000bf500  (line 211)

/* DWARF original prototype: void Spawn(CPathTrack * this) */

void __thiscall CPathTrack::Spawn(CPathTrack *this)

{
  Vector local_24;
  Vector local_18;
  
  local_18.x = 8.0;
  local_18.y = 8.0;
  local_18.z = 8.0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->solid = 1;
  local_24.x = -8.0;
  local_24.y = -8.0;
  local_24.z = -8.0;
  UTIL_SetSize((this->super_CPointEntity).super_CBaseEntity.pev,&local_24,&local_18);
  this->m_pnext = (CPathTrack *)0x0;
  this->m_pprevious = (CPathTrack *)0x0;
  return;
}


// CPathTrack::Activate  @ 000bf9b0  (line 226)

/* DWARF original prototype: void Activate(CPathTrack * this) */

void __thiscall CPathTrack::Activate(CPathTrack *this)

{
  entvars_t *peVar1;
  string_t sVar2;
  CPathTrack *pCVar3;
  _2globalvars_t *p1Var4;
  edict_t *peVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  byte bVar10;
  
  bVar10 = 0;
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if (peVar1->targetname == 0) {
    return;
  }
                    /* Unresolved local var: edict_t * pentTarget@[???] */
  sVar2 = peVar1->target;
  if (sVar2 != 0) {
    peVar5 = (*g_engfuncs.pfnFindEntityByString)
                       ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + sVar2);
    if ((peVar5 == (edict_t *)0x0) ||
       (iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5), p1Var4 = gpGlobals, iVar6 == 0)) {
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"Dead end link %s\n",
                 gpGlobals->pStringBase + ((this->super_CPointEntity).super_CBaseEntity.pev)->target
                );
    }
    else {
      iVar6 = 0xb;
      bVar9 = gpGlobals->pStringBase + (peVar5->v).classname == (char *)0x0;
      pcVar7 = gpGlobals->pStringBase + (peVar5->v).classname;
      pcVar8 = "path_track";
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar9 = *pcVar7 == *pcVar8;
        pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
        pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
      } while (bVar9);
      if (bVar9) {
        pCVar3 = peVar5->pvPrivateData;
        this->m_pnext = pCVar3;
        if (((this != (CPathTrack *)0x0) && (pCVar3 != (CPathTrack *)0x0)) &&
           (iVar6 = strcmp(p1Var4->pStringBase +
                           ((this->super_CPointEntity).super_CBaseEntity.pev)->targetname,
                           p1Var4->pStringBase + pCVar3->m_altName), iVar6 != 0)) {
          pCVar3->m_pprevious = this;
        }
      }
      else {
        this->m_pnext = (CPathTrack *)0x0;
      }
    }
  }
  if (((this->m_altName != 0) &&
      (peVar5 = (*g_engfuncs.pfnFindEntityByString)
                          ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_altName),
      peVar5 != (edict_t *)0x0)) &&
     (iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5), p1Var4 = gpGlobals, iVar6 != 0)) {
    iVar6 = 0xb;
    bVar9 = gpGlobals->pStringBase + (peVar5->v).classname == (char *)0x0;
    pcVar7 = gpGlobals->pStringBase + (peVar5->v).classname;
    pcVar8 = "path_track";
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar9 = *pcVar7 == *pcVar8;
      pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
      pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
    } while (bVar9);
    if (bVar9) {
      pCVar3 = peVar5->pvPrivateData;
      this->m_paltpath = pCVar3;
      if (((this != (CPathTrack *)0x0) && (pCVar3 != (CPathTrack *)0x0)) &&
         (iVar6 = strcmp(p1Var4->pStringBase +
                         ((this->super_CPointEntity).super_CBaseEntity.pev)->targetname,
                         p1Var4->pStringBase + pCVar3->m_altName), iVar6 != 0)) {
        pCVar3->m_pprevious = this;
      }
    }
    else {
      this->m_paltpath = (CPathTrack *)0x0;
    }
  }
  return;
}


// CPathTrack::ValidPath  @ 000bfed0  (line 232)

/* DWARF original prototype: CPathTrack * ValidPath(CPathTrack * this, CPathTrack * ppath, int
   testFlag) */

CPathTrack * __thiscall CPathTrack::ValidPath(CPathTrack *this,CPathTrack *ppath,int testFlag)

{
  if (ppath == (CPathTrack *)0x0) {
    ppath = (CPathTrack *)0x0;
  }
  else if (testFlag != 0) {
    if ((((ppath->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 1) != 0) {
      ppath = (CPathTrack *)0x0;
    }
    return ppath;
  }
  return ppath;
}


// CPathTrack::Project  @ 000bf570  (line 243)

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
  fVar4 = *(float *)(iVar6 + 0x10) - *(float *)(iVar3 + 0x10);
  fVar5 = *(float *)(iVar6 + 0xc) - *(float *)(iVar3 + 0xc);
  fVar2 = *(float *)(iVar6 + 8) - *(float *)(iVar3 + 8);
                    /* Unresolved local var: float flLen@[???] */
  fVar1 = fVar4 * fVar4 + fVar5 * fVar5 + fVar2 * fVar2;
  fVar7 = SQRT(fVar1);
  if (NAN(fVar7)) {
    fVar7 = sqrtf(fVar1);
    iVar6 = *(int *)(in_EDX + 4);
  }
  if (fVar7 == 0.0) {
    fVar4 = 1.0;
    fVar5 = 0.0;
    fVar7 = 0.0;
  }
  else {
    fVar7 = 1.0 / fVar7;
    fVar4 = fVar4 * fVar7;
    fVar5 = fVar5 * fVar7;
    fVar7 = fVar7 * fVar2;
  }
  fVar1 = *(float *)(iVar6 + 0x10);
  fVar2 = *(float *)(iVar6 + 0xc);
  *in_ECX = fVar7 * (float)this + *(float *)(iVar6 + 8);
  in_ECX[1] = fVar5 * (float)this + fVar2;
  in_ECX[2] = fVar4 * (float)this + fVar1;
  return;
}


// CPathTrack::Project  @ 000bff00  (line 244)

/* DWARF original prototype: void Project(CPathTrack * this, CPathTrack * pstart, CPathTrack * pend,
   Vector * origin, float dist) */

void __thiscall
CPathTrack::Project(CPathTrack *this,CPathTrack *pstart,CPathTrack *pend,Vector *origin,float dist)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  float fVar4;
  float fVar5;
  entvars_t *peVar6;
  float fVar7;
  
  if ((pstart != (CPathTrack *)0x0) && (pend != (CPathTrack *)0x0)) {
                    /* Unresolved local var: Vector dir@[???] */
    peVar3 = (pstart->super_CPointEntity).super_CBaseEntity.pev;
    peVar6 = (pend->super_CPointEntity).super_CBaseEntity.pev;
    fVar4 = (peVar6->origin).z - (peVar3->origin).z;
    fVar5 = (peVar6->origin).y - (peVar3->origin).y;
    fVar2 = (peVar6->origin).x - (peVar3->origin).x;
                    /* Unresolved local var: float flLen@[???] */
    fVar1 = fVar4 * fVar4 + fVar5 * fVar5 + fVar2 * fVar2;
    fVar7 = SQRT(fVar1);
    if (NAN(fVar7)) {
      fVar7 = sqrtf(fVar1);
      peVar6 = (pend->super_CPointEntity).super_CBaseEntity.pev;
    }
    if (fVar7 == 0.0) {
      fVar4 = 1.0;
      fVar5 = 0.0;
      fVar7 = 0.0;
    }
    else {
      fVar7 = 1.0 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar7 = fVar7 * fVar2;
    }
    fVar1 = (peVar6->origin).z;
    fVar2 = (peVar6->origin).y;
    origin->x = fVar7 * dist + (peVar6->origin).x;
    origin->y = fVar5 * dist + fVar2;
    origin->z = fVar4 * dist + fVar1;
  }
  return;
}


// CPathTrack::GetNext  @ 000bffe0  (line 254)

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


// CPathTrack::GetPrevious  @ 000c0010  (line 264)

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


// CPathTrack::SetPrevious  @ 000c0040  (line 274)

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


// CPathTrack::LookAhead  @ 000c00a0  (line 283)

/* DWARF original prototype: CPathTrack * LookAhead(CPathTrack * this, Vector * origin, float dist,
   int move) */

CPathTrack * __thiscall CPathTrack::LookAhead(CPathTrack *this,Vector *origin,float dist,int move)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  CPathTrack *pCVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  CPathTrack *pCVar9;
  entvars_t *peVar10;
  CPathTrack *pCVar11;
  float fVar12;
  CPathTrack *in_stack_ffffffb8;
  CPathTrack *in_stack_ffffffbc;
  Vector *in_stack_ffffffc0;
  float in_stack_ffffffc4;
  float local_38;
  
                    /* Unresolved local var: CPathTrack * pcurrent@[???]
                       Unresolved local var: float originalDist@[???]
                       Unresolved local var: Vector currentPos@[???] */
  fVar1 = origin->x;
  local_38 = origin->y;
  fVar2 = origin->z;
  pCVar5 = (CPathTrack *)dist;
  if (dist < 0.0) {
    pCVar5 = (CPathTrack *)-dist;
    if (0.0 < (float)pCVar5) {
      do {
        peVar10 = (this->super_CPointEntity).super_CBaseEntity.pev;
        fVar7 = (peVar10->origin).z - fVar2;
        fVar8 = (peVar10->origin).y - local_38;
        fVar6 = (peVar10->origin).x - fVar1;
        fVar4 = fVar7 * fVar7 + fVar6 * fVar6 + fVar8 * fVar8;
        fVar12 = SQRT(fVar4);
        if (NAN(fVar12)) {
          fVar12 = sqrtf(fVar4);
        }
        if (fVar12 == 0.0) {
          pCVar11 = this->m_paltpath;
          if ((pCVar11 == (CPathTrack *)0x0) ||
             (peVar10 = (this->super_CPointEntity).super_CBaseEntity.pev,
             (peVar10->spawnflags & 0x8004U) != 0x8004)) {
            pCVar9 = this->m_pprevious;
            if (pCVar9 == (CPathTrack *)0x0) {
              if (move != 0) {
                return (CPathTrack *)0x0;
              }
              if ((pCVar11 == (CPathTrack *)0x0) ||
                 ((((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8004U) !=
                  0x8000)) {
                pCVar11 = this->m_pnext;
              }
              if (pCVar11 != (CPathTrack *)0x0) {
                if (this != (CPathTrack *)0x0) {
                  Project(pCVar5,in_stack_ffffffb8,in_stack_ffffffbc,in_stack_ffffffc0,
                          in_stack_ffffffc4);
                  return (CPathTrack *)0x0;
                }
                return (CPathTrack *)0x0;
              }
              return (CPathTrack *)0x0;
            }
            if ((move != 0) &&
               ((((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 1) != 0)) {
              return (CPathTrack *)0x0;
            }
            if (pCVar11 != (CPathTrack *)0x0) {
              peVar10 = (this->super_CPointEntity).super_CBaseEntity.pev;
              goto LAB_000c046e;
            }
          }
          else {
            pCVar9 = pCVar11;
            if (move != 0) {
              if ((((pCVar11->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 1) != 0) {
                return (CPathTrack *)0x0;
              }
LAB_000c046e:
              uVar3 = peVar10->spawnflags;
joined_r0x000c057c:
              pCVar9 = pCVar11;
              if ((uVar3 & 0x8004) != 0x8004) {
                pCVar9 = this->m_pprevious;
              }
            }
          }
        }
        else {
          if ((float)pCVar5 < fVar12) {
            fVar12 = (float)pCVar5 / fVar12;
            origin->x = fVar6 * fVar12 + fVar1;
            origin->y = fVar8 * fVar12 + local_38;
            origin->z = fVar7 * fVar12 + fVar2;
            return this;
          }
          peVar10 = (this->super_CPointEntity).super_CBaseEntity.pev;
          pCVar5 = (CPathTrack *)((float)pCVar5 - fVar12);
          fVar1 = (peVar10->origin).x;
          local_38 = (peVar10->origin).y;
          fVar2 = (peVar10->origin).z;
          origin->x = fVar1;
          origin->y = local_38;
          origin->z = fVar2;
          pCVar11 = this->m_paltpath;
          if ((pCVar11 == (CPathTrack *)0x0) ||
             (peVar10 = (this->super_CPointEntity).super_CBaseEntity.pev,
             (peVar10->spawnflags & 0x8004U) != 0x8004)) {
            pCVar9 = this->m_pprevious;
            if (pCVar9 == (CPathTrack *)0x0) {
              return (CPathTrack *)0x0;
            }
            if ((move != 0) &&
               ((((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 1) != 0)) {
              return (CPathTrack *)0x0;
            }
            if (pCVar11 != (CPathTrack *)0x0) {
              peVar10 = (this->super_CPointEntity).super_CBaseEntity.pev;
              goto LAB_000c056c;
            }
          }
          else {
            pCVar9 = pCVar11;
            if (move != 0) {
              if ((((pCVar11->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 1) != 0) {
                return (CPathTrack *)0x0;
              }
LAB_000c056c:
              uVar3 = peVar10->spawnflags;
              goto joined_r0x000c057c;
            }
          }
        }
        this = pCVar9;
        if ((float)pCVar5 <= 0.0) {
          origin->x = fVar1;
          origin->y = local_38;
          origin->z = fVar2;
          return pCVar9;
        }
      } while( true );
    }
  }
  else {
    while (0.0 < (float)pCVar5) {
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: float length@[???] */
      pCVar11 = this->m_paltpath;
      if ((pCVar11 == (CPathTrack *)0x0) ||
         (peVar10 = (this->super_CPointEntity).super_CBaseEntity.pev,
         (peVar10->spawnflags & 0x8004U) != 0x8000)) {
        pCVar9 = this->m_pnext;
        if (pCVar9 == (CPathTrack *)0x0) {
          if (move != 0) {
            return (CPathTrack *)0x0;
          }
          if ((pCVar11 == (CPathTrack *)0x0) ||
             ((((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8004U) != 0x8004))
          {
            pCVar11 = this->m_pprevious;
          }
          if ((pCVar11 != (CPathTrack *)0x0) && (this != (CPathTrack *)0x0)) {
            Project(pCVar5,in_stack_ffffffb8,in_stack_ffffffbc,in_stack_ffffffc0,in_stack_ffffffc4);
            return (CPathTrack *)0x0;
          }
          return (CPathTrack *)0x0;
        }
        if ((move != 0) &&
           ((((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 1) != 0)) {
          return (CPathTrack *)0x0;
        }
        if (pCVar11 != (CPathTrack *)0x0) {
          peVar10 = (this->super_CPointEntity).super_CBaseEntity.pev;
          goto LAB_000c0134;
        }
      }
      else {
        pCVar9 = pCVar11;
        if (move != 0) {
          if ((((pCVar11->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 1) != 0) {
            return (CPathTrack *)0x0;
          }
LAB_000c0134:
          pCVar9 = pCVar11;
          if ((peVar10->spawnflags & 0x8004U) != 0x8000) {
            pCVar9 = this->m_pnext;
          }
        }
      }
      peVar10 = (pCVar9->super_CPointEntity).super_CBaseEntity.pev;
      fVar4 = (peVar10->origin).z - fVar2;
      fVar8 = (peVar10->origin).y - local_38;
      fVar7 = (peVar10->origin).x - fVar1;
      fVar6 = fVar4 * fVar4 + fVar8 * fVar8 + fVar7 * fVar7;
      fVar12 = SQRT(fVar6);
      if (NAN(fVar12)) {
        fVar12 = sqrtf(fVar6);
      }
      if (fVar12 == 0.0) {
        pCVar11 = this->m_paltpath;
        if ((pCVar11 == (CPathTrack *)0x0) ||
           ((((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8004U) != 0x8000)) {
          pCVar11 = this->m_pnext;
        }
        pCVar9 = pCVar11->m_paltpath;
        if ((((pCVar9 == (CPathTrack *)0x0) ||
             ((((pCVar11->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8004U) !=
              0x8000)) && (pCVar9 = pCVar11->m_pnext, pCVar9 == (CPathTrack *)0x0)) ||
           ((move != 0 &&
            ((((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 1) != 0)))) {
          if ((float)pCVar5 != dist) {
            return this;
          }
          return (CPathTrack *)0x0;
        }
      }
      if ((float)pCVar5 < fVar12) {
        fVar12 = (float)pCVar5 / fVar12;
        origin->x = fVar7 * fVar12 + fVar1;
        origin->y = local_38 + fVar8 * fVar12;
        origin->z = fVar12 * fVar4 + fVar2;
        return this;
      }
      pCVar11 = this->m_paltpath;
      if ((pCVar11 == (CPathTrack *)0x0) ||
         ((((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8004U) != 0x8000)) {
        pCVar11 = this->m_pnext;
        peVar10 = (pCVar11->super_CPointEntity).super_CBaseEntity.pev;
        fVar1 = (peVar10->origin).x;
        local_38 = (peVar10->origin).y;
        fVar2 = (peVar10->origin).z;
      }
      else {
        peVar10 = (pCVar11->super_CPointEntity).super_CBaseEntity.pev;
        fVar1 = (peVar10->origin).x;
        local_38 = (peVar10->origin).y;
        fVar2 = (peVar10->origin).z;
      }
      origin->x = fVar1;
      origin->y = local_38;
      origin->z = fVar2;
      this = pCVar11;
      pCVar5 = (CPathTrack *)((float)pCVar5 - fVar12);
    }
  }
  origin->x = fVar1;
  origin->y = local_38;
  origin->z = fVar2;
  return this;
}


// CPathTrack::Nearest  @ 000c0760  (line 366)

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
    if (pCVar4 == (CPathTrack *)0x0) {
      return pCVar3;
    }
    while( true ) {
      if (pCVar5 == this) {
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
      if (pCVar5 == (CPathTrack *)0x0) {
        return pCVar3;
      }
    }
  } while( true );
}


// CPathTrack::Instance  @ 000c08e0  (line 404)

CPathTrack * CPathTrack::Instance(edict_t *pent)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  if (pent != (edict_t *)0x0) {
    iVar1 = 0xb;
    bVar4 = gpGlobals->pStringBase + (pent->v).classname == (char *)0x0;
    pcVar2 = gpGlobals->pStringBase + (pent->v).classname;
    pcVar3 = "path_track";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return pent->pvPrivateData;
    }
  }
  return (CPathTrack *)0x0;
}


