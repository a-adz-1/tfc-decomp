// Ghidra decompilation of functions from tfc/effects.cpp
// 141 functions, ordered by original source line

// info_target  @ 0008d740  (line 27)

void info_target(entvars_t *pev)

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


// CBubbling::~CBubbling  @ 000920e0  (line 30)

/* DWARF original prototype: void ~CBubbling(CBubbling * this, int __in_chrg) */

void __thiscall CBubbling::~CBubbling(CBubbling *this,int __in_chrg)

{
  return;
}


// CBubbling::ObjectCaps  @ 00091fe0  (line 42)

/* DWARF original prototype: int ObjectCaps(CBubbling * this) */

int __thiscall CBubbling::ObjectCaps(CBubbling *this)

{
  return 0;
}


// env_bubbles  @ 0008d7b0  (line 51)

void env_bubbles(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x484,pev);
  *puVar1 = &PTR__CBubbling_0014c41c;
  puVar1[1] = pev;
  return;
}


// CBubbling::Restore  @ 0008c220  (line 62)

/* DWARF original prototype: int Restore(CBubbling * this, CRestore * restore) */

int __thiscall CBubbling::Restore(CBubbling *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore(&this->super_CBaseEntity,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CBubbling",this,m_SaveData,3);
  }
  return iVar2;
}


// CBubbling::Save  @ 0008c400  (line 62)

/* DWARF original prototype: int Save(CBubbling * this, CSave * save) */

int __thiscall CBubbling::Save(CBubbling *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save(&this->super_CBaseEntity,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CBubbling",this,m_SaveData,3);
  }
  return iVar2;
}


// CBubbling::Spawn  @ 0008c610  (line 68)

/* DWARF original prototype: void Spawn(CBubbling * this) */

void __thiscall CBubbling::Spawn(CBubbling *this)

{
  float fVar1;
  _func_int_varargs *p_Var2;
  entvars_t *peVar3;
  vec_t vVar4;
  _2globalvars_t *p1Var5;
  int iVar6;
  
                    /* Unresolved local var: int speed@[???] */
  p_Var2 = (this->super_CBaseEntity)._vptr_CBaseEntity[3];
  if (p_Var2 == Precache) {
    iVar6 = (*g_engfuncs.pfnPrecacheModel)("sprites/bubble.spr");
    this->m_bubbleModel = iVar6;
  }
  else {
    (*p_Var2)(this);
  }
  peVar3 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar3->pContainingEntity,gpGlobals->pStringBase + peVar3->model);
  ((this->super_CBaseEntity).pev)->solid = 0;
  ((this->super_CBaseEntity).pev)->renderamt = 0.0;
  ((this->super_CBaseEntity).pev)->rendermode = 2;
  peVar3 = (this->super_CBaseEntity).pev;
  fVar1 = peVar3->speed;
  if (fVar1 <= 0.0) {
    fVar1 = -fVar1;
  }
  (peVar3->rendercolor).x = (float)((int)fVar1 >> 8);
  (((this->super_CBaseEntity).pev)->rendercolor).y = (float)((int)fVar1 & 0xff);
  peVar3 = (this->super_CBaseEntity).pev;
  vVar4 = 1.0;
  if (0.0 <= peVar3->speed) {
    vVar4 = 0.0;
  }
  (peVar3->rendercolor).z = vVar4;
  p1Var5 = gpGlobals;
  peVar3 = (this->super_CBaseEntity).pev;
  if ((peVar3->spawnflags & 1) != 0) {
    this->m_state = 0;
    return;
  }
  (this->super_CBaseEntity).m_pfnThink.__pfn = FizzThink;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar3->nextthink = p1Var5->time + 2.0;
  this->m_state = 1;
  return;
}


// CBubbling::Precache  @ 0008a390  (line 94)

/* DWARF original prototype: void Precache(CBubbling * this) */

void __thiscall CBubbling::Precache(CBubbling *this)

{
  int iVar1;
  
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("sprites/bubble.spr");
  this->m_bubbleModel = iVar1;
  return;
}


// CBubbling::Use  @ 0008c000  (line 100)

/* DWARF original prototype: void Use(CBubbling * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CBubbling::Use(CBubbling *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
              float value)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  int iVar3;
  uint uVar4;
  
  iVar3 = CBaseEntity::ShouldToggle(&this->super_CBaseEntity,useType,this->m_state);
  if (iVar3 == 0) {
    uVar4 = this->m_state;
    p1Var2 = gpGlobals;
  }
  else {
    uVar4 = (uint)(this->m_state == 0);
    this->m_state = uVar4;
    p1Var2 = gpGlobals;
  }
  gpGlobals = p1Var2;
  if (uVar4 == 0) {
    peVar1 = (this->super_CBaseEntity).pev;
    (this->super_CBaseEntity).m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    peVar1->nextthink = 0.0;
    return;
  }
  (this->super_CBaseEntity).m_pfnThink.__pfn = FizzThink;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  ((this->super_CBaseEntity).pev)->nextthink = p1Var2->time + 0.1;
  return;
}


// CBubbling::KeyValue  @ 0008a920  (line 118)

/* DWARF original prototype: void KeyValue(CBubbling * this, KeyValueData * pkvd) */

void __thiscall CBubbling::KeyValue(CBubbling *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
  bVar7 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar3 = 8;
  pcVar5 = pkvd->szKeyName;
  pcVar4 = pcVar5;
  pcVar6 = "density";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar4 == *pcVar6;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    this->m_density = lVar2;
    pkvd->fHandled = 1;
  }
  else {
    iVar3 = 10;
    bVar7 = false;
    pcVar4 = pcVar5;
    pcVar6 = "frequency";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
      this->m_frequency = lVar2;
      pkvd->fHandled = 1;
    }
    else {
      iVar3 = 8;
      bVar7 = false;
      pcVar4 = "current";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar5 == *pcVar4;
        pcVar5 = pcVar5 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar7);
      if (!bVar7) {
        CBaseEntity::KeyValue(&this->super_CBaseEntity,pkvd);
        return;
      }
      peVar1 = (this->super_CBaseEntity).pev;
      lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
      peVar1->speed = (float)lVar2;
      pkvd->fHandled = 1;
    }
  }
  return;
}


// CBubbling::FizzThink  @ 0008aa50  (line 140)

/* DWARF original prototype: void FizzThink(CBubbling * this) */

void __thiscall CBubbling::FizzThink(CBubbling *this)

{
  _func_void_int *p_Var1;
  int iVar2;
  Vector local_18;
  
  VecBModelOrigin(&local_18,(this->super_CBaseEntity).pev);
  (*g_engfuncs.pfnMessageBegin)(5,0x17,&local_18.x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x69);
  p_Var1 = g_engfuncs.pfnWriteShort;
  iVar2 = (*g_engfuncs.pfnIndexOfEdict)(((this->super_CBaseEntity).pev)->pContainingEntity);
  (*p_Var1)((int)(short)iVar2);
  (*g_engfuncs.pfnWriteShort)((int)(short)this->m_bubbleModel);
  (*g_engfuncs.pfnWriteByte)(this->m_density);
  (*g_engfuncs.pfnMessageEnd)();
  if (this->m_frequency < 0x14) {
    ((this->super_CBaseEntity).pev)->nextthink =
         (gpGlobals->time + 2.5) - (float)this->m_frequency * 0.1;
    return;
  }
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 0.5;
  return;
}


// beam  @ 0008d820  (line 160)

void beam(entvars_t *pev)

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
  *puVar1 = &PTR__CBeam_0014c528;
  puVar1[1] = pev;
  return;
}


// CBeam::Spawn  @ 0008a3b0  (line 163)

/* DWARF original prototype: void Spawn(CBeam * this) */

void __thiscall CBeam::Spawn(CBeam *this)

{
  ((this->super_CBaseEntity).pev)->solid = 0;
                    /* WARNING: Could not recover jumptable at 0x0008a3c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseEntity)._vptr_CBaseEntity[3])();
  return;
}


// CBeam::Precache  @ 0008a3d0  (line 169)

/* DWARF original prototype: void Precache(CBeam * this) */

void __thiscall CBeam::Precache(CBeam *this)

{
  uint uVar1;
  edict_t *peVar2;
  entvars_t *peVar3;
  
  peVar3 = (this->super_CBaseEntity).pev;
  if (peVar3->owner != (edict_t *)0x0) {
    uVar1 = (*g_engfuncs.pfnIndexOfEdict)(peVar3->owner);
    peVar3 = (this->super_CBaseEntity).pev;
    peVar3->sequence = (peVar3->sequence & 0xf000U) << 0xc | uVar1 & 0xfff;
    peVar3 = (this->super_CBaseEntity).pev;
    peVar2 = (*g_engfuncs.pfnPEntityOfEntIndex)(uVar1);
    peVar3->owner = peVar2;
    peVar3 = (this->super_CBaseEntity).pev;
  }
  if (peVar3->aiment != (edict_t *)0x0) {
    uVar1 = (*g_engfuncs.pfnIndexOfEdict)(peVar3->aiment);
    peVar3 = (this->super_CBaseEntity).pev;
    peVar3->skin = (peVar3->skin & 0xf000U) << 0xc | uVar1 & 0xfff;
    peVar3 = (this->super_CBaseEntity).pev;
    peVar2 = (*g_engfuncs.pfnPEntityOfEntIndex)(uVar1);
    peVar3->aiment = peVar2;
  }
  return;
}


// CBeam::SetStartEntity  @ 0008d890  (line 177)

/* DWARF original prototype: void SetStartEntity(CBeam * this, int entityIndex) */

void __thiscall CBeam::SetStartEntity(CBeam *this,int entityIndex)

{
  entvars_t *peVar1;
  edict_t *peVar2;
  
  peVar1 = (this->super_CBaseEntity).pev;
  peVar1->sequence = (peVar1->sequence & 0xf000U) << 0xc | entityIndex & 0xfffU;
  peVar1 = (this->super_CBaseEntity).pev;
  peVar2 = (*g_engfuncs.pfnPEntityOfEntIndex)(entityIndex);
  peVar1->owner = peVar2;
  return;
}


// CBeam::SetEndEntity  @ 0008d8f0  (line 183)

/* DWARF original prototype: void SetEndEntity(CBeam * this, int entityIndex) */

void __thiscall CBeam::SetEndEntity(CBeam *this,int entityIndex)

{
  entvars_t *peVar1;
  edict_t *peVar2;
  
  peVar1 = (this->super_CBaseEntity).pev;
  peVar1->skin = (peVar1->skin & 0xf000U) << 0xc | entityIndex & 0xfffU;
  peVar1 = (this->super_CBaseEntity).pev;
  peVar2 = (*g_engfuncs.pfnPEntityOfEntIndex)(entityIndex);
  peVar1->aiment = peVar2;
  return;
}


// CBeam::GetStartPos  @ 0008d950  (line 191)

/* DWARF original prototype: Vector * GetStartPos(CBeam * this) */

Vector * __thiscall CBeam::GetStartPos(CBeam *this)

{
  entvars_t *peVar1;
  edict_t *peVar2;
  
  peVar1 = (this->super_CBaseEntity).pev;
  if ((peVar1->rendermode & 0xfU) == 2) {
                    /* Unresolved local var: edict_t * pent@[???] */
    peVar2 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar1->sequence & 0xfff);
    peVar1 = &peVar2->v;
  }
  return &peVar1->origin;
}


// CBeam::GetEndPos  @ 0008d990  (line 202)

/* DWARF original prototype: Vector * GetEndPos(CBeam * this) */

Vector * __thiscall CBeam::GetEndPos(CBeam *this)

{
  edict_t *peVar1;
  entvars_t *peVar2;
  uint uVar3;
  
                    /* Unresolved local var: int type@[???]
                       Unresolved local var: edict_t * pent@[???] */
  peVar2 = (this->super_CBaseEntity).pev;
  uVar3 = peVar2->rendermode & 0xf;
  if ((uVar3 != 0) && (uVar3 != 3)) {
    peVar1 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar2->skin & 0xfff);
    if (peVar1 != (edict_t *)0x0) {
      return &(peVar1->v).origin;
    }
    peVar2 = (this->super_CBaseEntity).pev;
  }
  return &peVar2->angles;
}


// CBeam::BeamCreate  @ 0008d9e0  (line 217)

CBeam * CBeam::BeamCreate(char *pSpriteName,int width)

{
  int *piVar1;
  _2globalvars_t *p1Var2;
  edict_t *peVar3;
  int iVar4;
  CBeam *pCVar5;
  entvars_t *pev;
  
                    /* Unresolved local var: CBeam * pBeam@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar3 = (*g_engfuncs.pfnCreateEntity)();
  pev = (entvars_t *)0x0;
  if (peVar3 != (edict_t *)0x0) {
    pev = &peVar3->v;
  }
  if ((pev->pContainingEntity == (edict_t *)0x0) ||
     (pCVar5 = pev->pContainingEntity->pvPrivateData, pCVar5 == (CBeam *)0x0)) {
    pCVar5 = CBaseEntity::operator_new(0x474,pev);
    (pCVar5->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CBeam_0014c528;
    (pCVar5->super_CBaseEntity).pev = pev;
  }
  else {
    pev = (pCVar5->super_CBaseEntity).pev;
  }
  pev->classname = (int)&DAT_0014c0ee - (int)gpGlobals->pStringBase;
  p1Var2 = gpGlobals;
  piVar1 = &((pCVar5->super_CBaseEntity).pev)->flags;
  *piVar1 = *piVar1 | 0x20000000;
  (((pCVar5->super_CBaseEntity).pev)->rendercolor).x = 255.0;
  (((pCVar5->super_CBaseEntity).pev)->rendercolor).y = 255.0;
  (((pCVar5->super_CBaseEntity).pev)->rendercolor).z = 255.0;
  ((pCVar5->super_CBaseEntity).pev)->renderamt = 255.0;
  ((pCVar5->super_CBaseEntity).pev)->body = 0;
  ((pCVar5->super_CBaseEntity).pev)->frame = 0.0;
  ((pCVar5->super_CBaseEntity).pev)->animtime = 0.0;
  ((pCVar5->super_CBaseEntity).pev)->model = (int)pSpriteName - (int)p1Var2->pStringBase;
  iVar4 = (*g_engfuncs.pfnPrecacheModel)(pSpriteName);
  ((pCVar5->super_CBaseEntity).pev)->modelindex = iVar4;
  ((pCVar5->super_CBaseEntity).pev)->scale = (float)width;
  ((pCVar5->super_CBaseEntity).pev)->skin = 0;
  ((pCVar5->super_CBaseEntity).pev)->sequence = 0;
  ((pCVar5->super_CBaseEntity).pev)->rendermode = 0;
  return pCVar5;
}


// CBeam::BeamInit  @ 0008db30  (line 229)

/* DWARF original prototype: void BeamInit(CBeam * this, char * pSpriteName, int width) */

void __thiscall CBeam::BeamInit(CBeam *this,char *pSpriteName,int width)

{
  int *piVar1;
  _2globalvars_t *p1Var2;
  int iVar3;
  
  p1Var2 = gpGlobals;
  piVar1 = &((this->super_CBaseEntity).pev)->flags;
  *piVar1 = *piVar1 | 0x20000000;
  (((this->super_CBaseEntity).pev)->rendercolor).x = 255.0;
  (((this->super_CBaseEntity).pev)->rendercolor).y = 255.0;
  (((this->super_CBaseEntity).pev)->rendercolor).z = 255.0;
  ((this->super_CBaseEntity).pev)->renderamt = 255.0;
  ((this->super_CBaseEntity).pev)->body = 0;
  ((this->super_CBaseEntity).pev)->frame = 0.0;
  ((this->super_CBaseEntity).pev)->animtime = 0.0;
  ((this->super_CBaseEntity).pev)->model = (int)pSpriteName - (int)p1Var2->pStringBase;
  iVar3 = (*g_engfuncs.pfnPrecacheModel)(pSpriteName);
  ((this->super_CBaseEntity).pev)->modelindex = iVar3;
  ((this->super_CBaseEntity).pev)->scale = (float)width;
  ((this->super_CBaseEntity).pev)->skin = 0;
  ((this->super_CBaseEntity).pev)->sequence = 0;
  ((this->super_CBaseEntity).pev)->rendermode = 0;
  return;
}


// CBeam::PointsInit  @ 0008dc00  (line 246)

/* DWARF original prototype: void PointsInit(CBeam * this, Vector * start, Vector * end) */

void __thiscall CBeam::PointsInit(CBeam *this,Vector *start,Vector *end)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  uint uVar5;
  edict_t *peVar6;
  Vector *pVVar7;
  entvars_t *peVar8;
  Vector *pVVar9;
  
  piVar1 = &((this->super_CBaseEntity).pev)->rendermode;
  *piVar1 = *piVar1 & 0xf0;
  peVar8 = (this->super_CBaseEntity).pev;
  (peVar8->origin).x = start->x;
  (peVar8->origin).y = start->y;
  (peVar8->origin).z = start->z;
  peVar8 = (this->super_CBaseEntity).pev;
  (peVar8->angles).x = end->x;
  (peVar8->angles).y = end->y;
  (peVar8->angles).z = end->z;
  piVar1 = &((this->super_CBaseEntity).pev)->sequence;
  *piVar1 = *piVar1 & 0xfff;
  piVar1 = &((this->super_CBaseEntity).pev)->skin;
  *piVar1 = *piVar1 & 0xfff;
  peVar8 = (this->super_CBaseEntity).pev;
                    /* Unresolved local var: Vector * startPos@[???]
                       Unresolved local var: Vector * endPos@[???] */
  uVar5 = peVar8->rendermode & 0xf;
  peVar4 = peVar8;
  if (uVar5 == 2) {
                    /* Unresolved local var: edict_t * pent@[???] */
    peVar6 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar8->sequence & 0xfff);
    peVar8 = (this->super_CBaseEntity).pev;
    peVar4 = &peVar6->v;
    uVar5 = peVar8->rendermode & 0xf;
  }
  pVVar9 = &peVar4->origin;
                    /* Unresolved local var: int type@[???]
                       Unresolved local var: edict_t * pent@[???] */
  if ((uVar5 != 0) && (uVar5 != 3)) {
    peVar6 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar8->skin & 0xfff);
    if (peVar6 != (edict_t *)0x0) {
      pVVar7 = &(peVar6->v).origin;
      peVar8 = (this->super_CBaseEntity).pev;
      goto LAB_0008dcb3;
    }
    peVar8 = (this->super_CBaseEntity).pev;
  }
  pVVar7 = &peVar8->angles;
LAB_0008dcb3:
  fVar2 = pVVar9->x;
  if (pVVar7->x < pVVar9->x) {
    fVar2 = pVVar7->x;
  }
  (peVar8->mins).x = fVar2;
  fVar2 = pVVar9->y;
  if (pVVar7->y < pVVar9->y) {
    fVar2 = pVVar7->y;
  }
  (((this->super_CBaseEntity).pev)->mins).y = fVar2;
  fVar2 = pVVar9->z;
  if (pVVar7->z < pVVar9->z) {
    fVar2 = pVVar7->z;
  }
  (((this->super_CBaseEntity).pev)->mins).z = fVar2;
  fVar2 = pVVar7->x;
  if (pVVar7->x <= pVVar9->x) {
    fVar2 = pVVar9->x;
  }
  (((this->super_CBaseEntity).pev)->maxs).x = fVar2;
  fVar2 = pVVar7->y;
  if (pVVar7->y <= pVVar9->y) {
    fVar2 = pVVar9->y;
  }
  (((this->super_CBaseEntity).pev)->maxs).y = fVar2;
  fVar2 = pVVar7->z;
  if (pVVar7->z <= pVVar9->z) {
    fVar2 = pVVar9->z;
  }
  (((this->super_CBaseEntity).pev)->maxs).z = fVar2;
  peVar8 = (this->super_CBaseEntity).pev;
  fVar2 = (peVar8->origin).z;
  fVar3 = (peVar8->origin).y;
  (peVar8->mins).x = (peVar8->mins).x - (peVar8->origin).x;
  (peVar8->mins).y = (peVar8->mins).y - fVar3;
  (peVar8->mins).z = (peVar8->mins).z - fVar2;
  peVar8 = (this->super_CBaseEntity).pev;
  fVar2 = (peVar8->origin).z;
  fVar3 = (peVar8->origin).y;
  (peVar8->maxs).x = (peVar8->maxs).x - (peVar8->origin).x;
  (peVar8->maxs).y = (peVar8->maxs).y - fVar3;
  (peVar8->maxs).z = (peVar8->maxs).z - fVar2;
  peVar8 = (this->super_CBaseEntity).pev;
  UTIL_SetSize(peVar8,&peVar8->mins,&peVar8->maxs);
  peVar8 = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(peVar8,&peVar8->origin);
  return;
}


// CBeam::HoseInit  @ 0008de00  (line 257)

/* DWARF original prototype: void HoseInit(CBeam * this, Vector * start, Vector * direction) */

void __thiscall CBeam::HoseInit(CBeam *this,Vector *start,Vector *direction)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  uint uVar5;
  edict_t *peVar6;
  Vector *pVVar7;
  entvars_t *peVar8;
  Vector *pVVar9;
  
  peVar8 = (this->super_CBaseEntity).pev;
  peVar8->rendermode = peVar8->rendermode & 0xf0U | 3;
  peVar8 = (this->super_CBaseEntity).pev;
  (peVar8->origin).x = start->x;
  (peVar8->origin).y = start->y;
  (peVar8->origin).z = start->z;
  peVar8 = (this->super_CBaseEntity).pev;
  (peVar8->angles).x = direction->x;
  (peVar8->angles).y = direction->y;
  (peVar8->angles).z = direction->z;
  piVar1 = &((this->super_CBaseEntity).pev)->sequence;
  *piVar1 = *piVar1 & 0xfff;
  piVar1 = &((this->super_CBaseEntity).pev)->skin;
  *piVar1 = *piVar1 & 0xfff;
  peVar8 = (this->super_CBaseEntity).pev;
                    /* Unresolved local var: Vector * startPos@[???]
                       Unresolved local var: Vector * endPos@[???] */
  uVar5 = peVar8->rendermode & 0xf;
  peVar4 = peVar8;
  if (uVar5 == 2) {
                    /* Unresolved local var: edict_t * pent@[???] */
    peVar6 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar8->sequence & 0xfff);
    peVar8 = (this->super_CBaseEntity).pev;
    peVar4 = &peVar6->v;
    uVar5 = peVar8->rendermode & 0xf;
  }
  pVVar9 = &peVar4->origin;
                    /* Unresolved local var: int type@[???]
                       Unresolved local var: edict_t * pent@[???] */
  if ((uVar5 != 0) && (uVar5 != 3)) {
    peVar6 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar8->skin & 0xfff);
    if (peVar6 != (edict_t *)0x0) {
      pVVar7 = &(peVar6->v).origin;
      peVar8 = (this->super_CBaseEntity).pev;
      goto LAB_0008dec3;
    }
    peVar8 = (this->super_CBaseEntity).pev;
  }
  pVVar7 = &peVar8->angles;
LAB_0008dec3:
  fVar2 = pVVar9->x;
  if (pVVar7->x < pVVar9->x) {
    fVar2 = pVVar7->x;
  }
  (peVar8->mins).x = fVar2;
  fVar2 = pVVar9->y;
  if (pVVar7->y < pVVar9->y) {
    fVar2 = pVVar7->y;
  }
  (((this->super_CBaseEntity).pev)->mins).y = fVar2;
  fVar2 = pVVar9->z;
  if (pVVar7->z < pVVar9->z) {
    fVar2 = pVVar7->z;
  }
  (((this->super_CBaseEntity).pev)->mins).z = fVar2;
  fVar2 = pVVar7->x;
  if (pVVar7->x <= pVVar9->x) {
    fVar2 = pVVar9->x;
  }
  (((this->super_CBaseEntity).pev)->maxs).x = fVar2;
  fVar2 = pVVar7->y;
  if (pVVar7->y <= pVVar9->y) {
    fVar2 = pVVar9->y;
  }
  (((this->super_CBaseEntity).pev)->maxs).y = fVar2;
  fVar2 = pVVar7->z;
  if (pVVar7->z <= pVVar9->z) {
    fVar2 = pVVar9->z;
  }
  (((this->super_CBaseEntity).pev)->maxs).z = fVar2;
  peVar8 = (this->super_CBaseEntity).pev;
  fVar2 = (peVar8->origin).z;
  fVar3 = (peVar8->origin).y;
  (peVar8->mins).x = (peVar8->mins).x - (peVar8->origin).x;
  (peVar8->mins).y = (peVar8->mins).y - fVar3;
  (peVar8->mins).z = (peVar8->mins).z - fVar2;
  peVar8 = (this->super_CBaseEntity).pev;
  fVar2 = (peVar8->origin).z;
  fVar3 = (peVar8->origin).y;
  (peVar8->maxs).x = (peVar8->maxs).x - (peVar8->origin).x;
  (peVar8->maxs).y = (peVar8->maxs).y - fVar3;
  (peVar8->maxs).z = (peVar8->maxs).z - fVar2;
  peVar8 = (this->super_CBaseEntity).pev;
  UTIL_SetSize(peVar8,&peVar8->mins,&peVar8->maxs);
  peVar8 = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(peVar8,&peVar8->origin);
  return;
}


// CBeam::PointEntInit  @ 0008e010  (line 268)

/* DWARF original prototype: void PointEntInit(CBeam * this, Vector * start, int endIndex) */

void __thiscall CBeam::PointEntInit(CBeam *this,Vector *start,int endIndex)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  edict_t *peVar5;
  uint uVar6;
  Vector *pVVar7;
  entvars_t *peVar8;
  Vector *pVVar9;
  
  peVar8 = (this->super_CBaseEntity).pev;
  peVar8->rendermode = peVar8->rendermode & 0xf0U | 1;
  peVar8 = (this->super_CBaseEntity).pev;
  (peVar8->origin).x = start->x;
  (peVar8->origin).y = start->y;
  (peVar8->origin).z = start->z;
  peVar8 = (this->super_CBaseEntity).pev;
  peVar8->skin = (peVar8->skin & 0xf000U) << 0xc | endIndex & 0xfffU;
  peVar8 = (this->super_CBaseEntity).pev;
  peVar5 = (*g_engfuncs.pfnPEntityOfEntIndex)(endIndex);
  peVar8->aiment = peVar5;
  piVar1 = &((this->super_CBaseEntity).pev)->sequence;
  *piVar1 = *piVar1 & 0xfff;
  piVar1 = &((this->super_CBaseEntity).pev)->skin;
  *piVar1 = *piVar1 & 0xfff;
  peVar8 = (this->super_CBaseEntity).pev;
                    /* Unresolved local var: Vector * startPos@[???]
                       Unresolved local var: Vector * endPos@[???] */
  uVar6 = peVar8->rendermode & 0xf;
  peVar4 = peVar8;
  if (uVar6 == 2) {
                    /* Unresolved local var: edict_t * pent@[???] */
    peVar5 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar8->sequence & 0xfff);
    peVar8 = (this->super_CBaseEntity).pev;
    peVar4 = &peVar5->v;
    uVar6 = peVar8->rendermode & 0xf;
  }
  pVVar9 = &peVar4->origin;
                    /* Unresolved local var: int type@[???]
                       Unresolved local var: edict_t * pent@[???] */
  if ((uVar6 != 0) && (uVar6 != 3)) {
    peVar5 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar8->skin & 0xfff);
    if (peVar5 != (edict_t *)0x0) {
      pVVar7 = &(peVar5->v).origin;
      peVar8 = (this->super_CBaseEntity).pev;
      goto LAB_0008e0f3;
    }
    peVar8 = (this->super_CBaseEntity).pev;
  }
  pVVar7 = &peVar8->angles;
LAB_0008e0f3:
  fVar2 = pVVar9->x;
  if (pVVar7->x < pVVar9->x) {
    fVar2 = pVVar7->x;
  }
  (peVar8->mins).x = fVar2;
  fVar2 = pVVar9->y;
  if (pVVar7->y < pVVar9->y) {
    fVar2 = pVVar7->y;
  }
  (((this->super_CBaseEntity).pev)->mins).y = fVar2;
  fVar2 = pVVar9->z;
  if (pVVar7->z < pVVar9->z) {
    fVar2 = pVVar7->z;
  }
  (((this->super_CBaseEntity).pev)->mins).z = fVar2;
  fVar2 = pVVar7->x;
  if (pVVar7->x <= pVVar9->x) {
    fVar2 = pVVar9->x;
  }
  (((this->super_CBaseEntity).pev)->maxs).x = fVar2;
  fVar2 = pVVar7->y;
  if (pVVar7->y <= pVVar9->y) {
    fVar2 = pVVar9->y;
  }
  (((this->super_CBaseEntity).pev)->maxs).y = fVar2;
  fVar2 = pVVar7->z;
  if (pVVar7->z <= pVVar9->z) {
    fVar2 = pVVar9->z;
  }
  (((this->super_CBaseEntity).pev)->maxs).z = fVar2;
  peVar8 = (this->super_CBaseEntity).pev;
  fVar2 = (peVar8->origin).z;
  fVar3 = (peVar8->origin).y;
  (peVar8->mins).x = (peVar8->mins).x - (peVar8->origin).x;
  (peVar8->mins).y = (peVar8->mins).y - fVar3;
  (peVar8->mins).z = (peVar8->mins).z - fVar2;
  peVar8 = (this->super_CBaseEntity).pev;
  fVar2 = (peVar8->origin).z;
  fVar3 = (peVar8->origin).y;
  (peVar8->maxs).x = (peVar8->maxs).x - (peVar8->origin).x;
  (peVar8->maxs).y = (peVar8->maxs).y - fVar3;
  (peVar8->maxs).z = (peVar8->maxs).z - fVar2;
  peVar8 = (this->super_CBaseEntity).pev;
  UTIL_SetSize(peVar8,&peVar8->mins,&peVar8->maxs);
  peVar8 = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(peVar8,&peVar8->origin);
  return;
}


// CBeam::EntsInit  @ 0008e3f0  (line 278)

/* DWARF original prototype: void EntsInit(CBeam * this, int startIndex, int endIndex) */

void __thiscall CBeam::EntsInit(CBeam *this,int startIndex,int endIndex)

{
  int *piVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  
  peVar2 = (this->super_CBaseEntity).pev;
  peVar2->rendermode = peVar2->rendermode & 0xf0U | 2;
  peVar2 = (this->super_CBaseEntity).pev;
  peVar2->sequence = (peVar2->sequence & 0xf000U) << 0xc | startIndex & 0xfffU;
  peVar2 = (this->super_CBaseEntity).pev;
  peVar3 = (*g_engfuncs.pfnPEntityOfEntIndex)(startIndex);
  peVar2->owner = peVar3;
  peVar2 = (this->super_CBaseEntity).pev;
  peVar2->skin = (peVar2->skin & 0xf000U) << 0xc | endIndex & 0xfffU;
  peVar2 = (this->super_CBaseEntity).pev;
  peVar3 = (*g_engfuncs.pfnPEntityOfEntIndex)(endIndex);
  peVar2->aiment = peVar3;
  piVar1 = &((this->super_CBaseEntity).pev)->sequence;
  *piVar1 = *piVar1 & 0xfff;
  piVar1 = &((this->super_CBaseEntity).pev)->skin;
  *piVar1 = *piVar1 & 0xfff;
  RelinkBeam(this);
  return;
}


// CBeam::RelinkBeam  @ 0008e240  (line 289)

/* DWARF original prototype: void RelinkBeam(CBeam * this) */

void __thiscall CBeam::RelinkBeam(CBeam *this)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  uint uVar4;
  edict_t *peVar5;
  Vector *pVVar6;
  entvars_t *peVar7;
  Vector *pVVar8;
  
                    /* Unresolved local var: Vector * startPos@[???]
                       Unresolved local var: Vector * endPos@[???] */
  peVar7 = (this->super_CBaseEntity).pev;
  uVar4 = peVar7->rendermode & 0xf;
  peVar3 = peVar7;
  if (uVar4 == 2) {
                    /* Unresolved local var: edict_t * pent@[???] */
    peVar5 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar7->sequence & 0xfff);
    peVar7 = (this->super_CBaseEntity).pev;
    peVar3 = &peVar5->v;
    uVar4 = peVar7->rendermode & 0xf;
  }
  pVVar8 = &peVar3->origin;
                    /* Unresolved local var: int type@[???]
                       Unresolved local var: edict_t * pent@[???] */
  if ((uVar4 != 0) && (uVar4 != 3)) {
    peVar5 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar7->skin & 0xfff);
    if (peVar5 != (edict_t *)0x0) {
      pVVar6 = &(peVar5->v).origin;
      peVar7 = (this->super_CBaseEntity).pev;
      goto LAB_0008e2a3;
    }
    peVar7 = (this->super_CBaseEntity).pev;
  }
  pVVar6 = &peVar7->angles;
LAB_0008e2a3:
  fVar1 = pVVar8->x;
  if (pVVar6->x < pVVar8->x) {
    fVar1 = pVVar6->x;
  }
  (peVar7->mins).x = fVar1;
  fVar1 = pVVar8->y;
  if (pVVar6->y < pVVar8->y) {
    fVar1 = pVVar6->y;
  }
  (((this->super_CBaseEntity).pev)->mins).y = fVar1;
  fVar1 = pVVar8->z;
  if (pVVar6->z < pVVar8->z) {
    fVar1 = pVVar6->z;
  }
  (((this->super_CBaseEntity).pev)->mins).z = fVar1;
  fVar1 = pVVar6->x;
  if (pVVar6->x <= pVVar8->x) {
    fVar1 = pVVar8->x;
  }
  (((this->super_CBaseEntity).pev)->maxs).x = fVar1;
  fVar1 = pVVar6->y;
  if (pVVar6->y <= pVVar8->y) {
    fVar1 = pVVar8->y;
  }
  (((this->super_CBaseEntity).pev)->maxs).y = fVar1;
  fVar1 = pVVar6->z;
  if (pVVar6->z <= pVVar8->z) {
    fVar1 = pVVar8->z;
  }
  (((this->super_CBaseEntity).pev)->maxs).z = fVar1;
  peVar7 = (this->super_CBaseEntity).pev;
  fVar1 = (peVar7->origin).z;
  fVar2 = (peVar7->origin).y;
  (peVar7->mins).x = (peVar7->mins).x - (peVar7->origin).x;
  (peVar7->mins).y = (peVar7->mins).y - fVar2;
  (peVar7->mins).z = (peVar7->mins).z - fVar1;
  peVar7 = (this->super_CBaseEntity).pev;
  fVar1 = (peVar7->origin).z;
  fVar2 = (peVar7->origin).y;
  (peVar7->maxs).x = (peVar7->maxs).x - (peVar7->origin).x;
  (peVar7->maxs).y = (peVar7->maxs).y - fVar2;
  (peVar7->maxs).z = (peVar7->maxs).z - fVar1;
  peVar7 = (this->super_CBaseEntity).pev;
  UTIL_SetSize(peVar7,&peVar7->mins,&peVar7->maxs);
  peVar7 = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(peVar7,&peVar7->origin);
  return;
}


// CBeam::TriggerTouch  @ 0008eb00  (line 321)

/* DWARF original prototype: void TriggerTouch(CBeam * this, CBaseEntity * pOther) */

void __thiscall CBeam::TriggerTouch(CBeam *this,CBaseEntity *pOther)

{
  edict_t *peVar1;
  int *piVar2;
  
  if ((pOther->pev->flags & 0x28) != 0) {
    peVar1 = ((this->super_CBaseEntity).pev)->owner;
    if (peVar1 != (edict_t *)0x0) {
                    /* Unresolved local var: CBaseEntity * pOwner@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      piVar2 = peVar1->pvPrivateData;
      (**(code **)(*piVar2 + 0xb4))(piVar2,pOther,this,3,0);
    }
                    /* WARNING: Could not recover jumptable at 0x0008eb61. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Firing targets!!!\n");
    return;
  }
  return;
}


// CBeam::RandomTargetname  @ 0008eb80  (line 335)

/* DWARF original prototype: CBaseEntity * RandomTargetname(CBeam * this, char * szName) */

CBaseEntity * __thiscall CBeam::RandomTargetname(CBeam *this,char *szName)

{
  int iVar1;
  int32 iVar2;
  CBaseEntity *pStartEntity;
  int iVar3;
  CBaseEntity *pCVar4;
  
                    /* Unresolved local var: int total@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pNewEntity@[???] */
  pStartEntity = (CBaseEntity *)0x0;
  iVar3 = 0;
  pCVar4 = (CBaseEntity *)0x0;
  while( true ) {
    pStartEntity = UTIL_FindEntityByTargetname(pStartEntity,szName);
    if (pStartEntity == (CBaseEntity *)0x0) break;
    iVar1 = iVar3 + 1;
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,iVar3);
    iVar3 = iVar1;
    if (iVar2 < 1) {
      pCVar4 = pStartEntity;
    }
  }
  return pCVar4;
}


// CBeam::DoSparks  @ 0008ebd0  (line 351)

/* DWARF original prototype: void DoSparks(CBeam * this, Vector * start, Vector * end) */

void __thiscall CBeam::DoSparks(CBeam *this,Vector *start,Vector *end)

{
  uint uVar1;
  
  uVar1 = ((this->super_CBaseEntity).pev)->spawnflags;
  if ((uVar1 & 0x30) != 0) {
    if ((uVar1 & 0x10) != 0) {
      UTIL_Sparks(start);
      uVar1 = ((this->super_CBaseEntity).pev)->spawnflags;
    }
    if ((uVar1 & 0x20) != 0) {
      UTIL_Sparks(end);
      return;
    }
  }
  return;
}


// env_lightning  @ 0008ec40  (line 358)

void env_lightning(entvars_t *param_1)

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
  puVar1 = CBaseEntity::operator_new(0x4a8,param_1);
  *puVar1 = &PTR__CLightning_0014c634;
  puVar1[1] = param_1;
  return;
}


// CLightning::~CLightning  @ 000920d0  (line 366)

/* DWARF original prototype: void ~CLightning(CLightning * this, int __in_chrg) */

void __thiscall CLightning::~CLightning(CLightning *this,int __in_chrg)

{
  return;
}


// env_beam  @ 0008ecb0  (line 412)

void env_beam(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x4a8,pev);
  *puVar1 = &PTR__CLightning_0014c634;
  puVar1[1] = pev;
  return;
}


// CLightning::Restore  @ 0008c1c0  (line 450)

/* DWARF original prototype: int Restore(CLightning * this, CRestore * restore) */

int __thiscall CLightning::Restore(CLightning *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore((CBaseEntity *)this,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CLightning",this,m_SaveData,0xd);
  }
  return iVar2;
}


// CLightning::Save  @ 0008c3a0  (line 450)

/* DWARF original prototype: int Save(CLightning * this, CSave * save) */

int __thiscall CLightning::Save(CLightning *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save((CBaseEntity *)this,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CLightning",this,m_SaveData,0xd);
  }
  return iVar2;
}


// CLightning::Spawn  @ 0008c950  (line 454)

/* DWARF original prototype: void Spawn(CLightning * this) */

void __thiscall CLightning::Spawn(CLightning *this)

{
  _func_int_varargs *p_Var1;
  _2globalvars_t *p1Var2;
  int iVar3;
  entvars_t *peVar4;
  
  if (this->m_iszSpriteName == 0) {
    (this->super_CBeam).super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (this->super_CBeam).super_CBaseEntity.m_pfnThink.__delta = 0;
  }
  else {
    ((this->super_CBeam).super_CBaseEntity.pev)->solid = 0;
    p_Var1 = (this->super_CBeam).super_CBaseEntity._vptr_CBaseEntity[3];
    if (p_Var1 == Precache) {
      iVar3 = (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + this->m_iszSpriteName);
      this->m_spriteTexture = iVar3;
      CBeam::Precache(&this->super_CBeam);
    }
    else {
      (*p_Var1)(this);
    }
    p1Var2 = gpGlobals;
    ((this->super_CBeam).super_CBaseEntity.pev)->dmgtime = gpGlobals->time;
    peVar4 = (this->super_CBeam).super_CBaseEntity.pev;
    if ((this->m_life != 0.0) || ((peVar4->spawnflags & 8) != 0)) {
      this->m_active = 0;
      if (peVar4->targetname != 0) {
        (this->super_CBeam).super_CBaseEntity.m_pfnUse.__pfn = StrikeUse;
        (this->super_CBeam).super_CBaseEntity.m_pfnUse.__delta = 0;
        if ((peVar4->targetname != 0) && ((peVar4->spawnflags & 1) == 0)) {
          return;
        }
      }
      (this->super_CBeam).super_CBaseEntity.m_pfnThink.__pfn = StrikeThink;
      (this->super_CBeam).super_CBaseEntity.m_pfnThink.__delta = 0;
      peVar4->nextthink = p1Var2->time + 1.0;
      return;
    }
    (this->super_CBeam).super_CBaseEntity.m_pfnThink.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr *)0x0;
    (this->super_CBeam).super_CBaseEntity.m_pfnThink.__delta = 0;
    if (0.0 < peVar4->dmg) {
      (this->super_CBeam).super_CBaseEntity.m_pfnThink.__pfn = DamageThink;
      peVar4->nextthink = p1Var2->time + 0.1;
      peVar4 = (this->super_CBeam).super_CBaseEntity.pev;
    }
    if (peVar4->targetname != 0) {
      if ((peVar4->spawnflags & 1) == 0) {
        peVar4->effects = 0x80;
        peVar4 = (this->super_CBeam).super_CBaseEntity.pev;
        this->m_active = 0;
        peVar4->nextthink = 0.0;
      }
      else {
        this->m_active = 1;
      }
      (this->super_CBeam).super_CBaseEntity.m_pfnUse.__pfn = ToggleUse;
      (this->super_CBeam).super_CBaseEntity.m_pfnUse.__delta = 0;
      return;
    }
  }
  return;
}


// CLightning::Precache  @ 0008d050  (line 503)

/* DWARF original prototype: void Precache(CLightning * this) */

void __thiscall CLightning::Precache(CLightning *this)

{
  int iVar1;
  uint uVar2;
  edict_t *peVar3;
  entvars_t *peVar4;
  
  iVar1 = (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + this->m_iszSpriteName);
  this->m_spriteTexture = iVar1;
  peVar4 = (this->super_CBeam).super_CBaseEntity.pev;
  if (peVar4->owner != (edict_t *)0x0) {
    uVar2 = (*g_engfuncs.pfnIndexOfEdict)(peVar4->owner);
    peVar4 = (this->super_CBeam).super_CBaseEntity.pev;
    peVar4->sequence = (peVar4->sequence & 0xf000U) << 0xc | uVar2 & 0xfff;
    peVar4 = (this->super_CBeam).super_CBaseEntity.pev;
    peVar3 = (*g_engfuncs.pfnPEntityOfEntIndex)(uVar2);
    peVar4->owner = peVar3;
    peVar4 = (this->super_CBeam).super_CBaseEntity.pev;
  }
  if (peVar4->aiment != (edict_t *)0x0) {
    uVar2 = (*g_engfuncs.pfnIndexOfEdict)(peVar4->aiment);
    peVar4 = (this->super_CBeam).super_CBaseEntity.pev;
    peVar4->skin = (peVar4->skin & 0xf000U) << 0xc | uVar2 & 0xfff;
    peVar4 = (this->super_CBeam).super_CBaseEntity.pev;
    peVar3 = (*g_engfuncs.pfnPEntityOfEntIndex)(uVar2);
    peVar4->aiment = peVar3;
  }
  return;
}


// CLightning::Activate  @ 00090420  (line 510)

/* DWARF original prototype: void Activate(CLightning * this) */

void __thiscall CLightning::Activate(CLightning *this)

{
  if ((this->m_life == 0.0) && ((((this->super_CBeam).super_CBaseEntity.pev)->spawnflags & 8) == 0))
  {
    BeamUpdateVars(this);
    return;
  }
  return;
}


// CLightning::KeyValue  @ 0008ab40  (line 517)

/* DWARF original prototype: void KeyValue(CLightning * this, KeyValueData * pkvd) */

void __thiscall CLightning::KeyValue(CLightning *this,KeyValueData *pkvd)

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
  iVar3 = 0xf;
  pcVar5 = pkvd->szKeyName;
  pcVar4 = pcVar5;
  pcVar6 = "LightningStart";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar4 == *pcVar6;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    iVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    this->m_iszStartEntity = iVar3;
    pkvd->fHandled = 1;
  }
  else {
    iVar3 = 0xd;
    bVar7 = false;
    pcVar4 = pcVar5;
    pcVar6 = "LightningEnd";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar4 == *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      iVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
      this->m_iszEndEntity = iVar3;
      pkvd->fHandled = 1;
    }
    else {
      iVar3 = 5;
      bVar7 = false;
      pcVar4 = pcVar5;
      pcVar6 = "life";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar4 == *pcVar6;
        pcVar4 = pcVar4 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar7);
      if (bVar7) {
        dVar8 = strtod(pkvd->szValue,(char **)0x0);
        this->m_life = (float)dVar8;
        pkvd->fHandled = 1;
      }
      else {
        iVar3 = 10;
        bVar7 = false;
        pcVar4 = pcVar5;
        pcVar6 = "BoltWidth";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar7 = *pcVar4 == *pcVar6;
          pcVar4 = pcVar4 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar7);
        if (bVar7) {
          lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
          this->m_boltWidth = lVar2;
          pkvd->fHandled = 1;
        }
        else {
          iVar3 = 0xf;
          bVar7 = false;
          pcVar4 = pcVar5;
          pcVar6 = "NoiseAmplitude";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar7 = *pcVar4 == *pcVar6;
            pcVar4 = pcVar4 + 1;
            pcVar6 = pcVar6 + 1;
          } while (bVar7);
          if (bVar7) {
            lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
            this->m_noiseAmplitude = lVar2;
            pkvd->fHandled = 1;
          }
          else {
            iVar3 = 0xe;
            bVar7 = false;
            pcVar4 = pcVar5;
            pcVar6 = "TextureScroll";
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar7 = *pcVar4 == *pcVar6;
              pcVar4 = pcVar4 + 1;
              pcVar6 = pcVar6 + 1;
            } while (bVar7);
            if (bVar7) {
              lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
              this->m_speed = lVar2;
              pkvd->fHandled = 1;
            }
            else {
              iVar3 = 0xb;
              bVar7 = false;
              pcVar4 = pcVar5;
              pcVar6 = "StrikeTime";
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar7 = *pcVar4 == *pcVar6;
                pcVar4 = pcVar4 + 1;
                pcVar6 = pcVar6 + 1;
              } while (bVar7);
              if (bVar7) {
                dVar8 = strtod(pkvd->szValue,(char **)0x0);
                this->m_restrike = (float)dVar8;
                pkvd->fHandled = 1;
              }
              else {
                iVar3 = 8;
                bVar7 = false;
                pcVar4 = pcVar5;
                pcVar6 = "texture";
                do {
                  if (iVar3 == 0) break;
                  iVar3 = iVar3 + -1;
                  bVar7 = *pcVar4 == *pcVar6;
                  pcVar4 = pcVar4 + 1;
                  pcVar6 = pcVar6 + 1;
                } while (bVar7);
                if (bVar7) {
                  iVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
                  this->m_iszSpriteName = iVar3;
                  pkvd->fHandled = 1;
                }
                else {
                  iVar3 = 0xb;
                  bVar7 = false;
                  pcVar4 = pcVar5;
                  pcVar6 = "framestart";
                  do {
                    if (iVar3 == 0) break;
                    iVar3 = iVar3 + -1;
                    bVar7 = *pcVar4 == *pcVar6;
                    pcVar4 = pcVar4 + 1;
                    pcVar6 = pcVar6 + 1;
                  } while (bVar7);
                  if (bVar7) {
                    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                    this->m_frameStart = lVar2;
                    pkvd->fHandled = 1;
                  }
                  else {
                    iVar3 = 7;
                    bVar7 = false;
                    pcVar4 = pcVar5;
                    pcVar6 = "Radius";
                    do {
                      if (iVar3 == 0) break;
                      iVar3 = iVar3 + -1;
                      bVar7 = *pcVar4 == *pcVar6;
                      pcVar4 = pcVar4 + 1;
                      pcVar6 = pcVar6 + 1;
                    } while (bVar7);
                    if (bVar7) {
                      dVar8 = strtod(pkvd->szValue,(char **)0x0);
                      this->m_radius = (float)dVar8;
                      pkvd->fHandled = 1;
                    }
                    else {
                      iVar3 = 7;
                      bVar7 = false;
                      pcVar4 = "damage";
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
                      peVar1 = (this->super_CBeam).super_CBaseEntity.pev;
                      dVar8 = strtod(pkvd->szValue,(char **)0x0);
                      peVar1->dmg = (float)dVar8;
                      pkvd->fHandled = 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}


// CLightning::ToggleUse  @ 0008d120  (line 579)

/* DWARF original prototype: void ToggleUse(CLightning * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CLightning::ToggleUse
          (CLightning *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  int *piVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  int iVar4;
  edict_t *peVar5;
  uint uVar6;
  entvars_t *peVar7;
  Vector *position;
  
  iVar4 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,this->m_active);
  if (iVar4 != 0) {
    if (this->m_active == 0) {
      this->m_active = 1;
      piVar1 = &((this->super_CBeam).super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 & 0xffffff7f;
      peVar7 = (this->super_CBeam).super_CBaseEntity.pev;
                    /* Unresolved local var: int type@[???]
                       Unresolved local var: edict_t * pent@[???] */
      uVar6 = peVar7->rendermode & 0xf;
      if ((uVar6 == 0) || (uVar6 == 3)) {
        position = &peVar7->angles;
      }
      else {
        peVar5 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar7->skin & 0xfff);
        if (peVar5 == (edict_t *)0x0) {
          peVar7 = (this->super_CBeam).super_CBaseEntity.pev;
          position = &peVar7->angles;
          uVar6 = peVar7->rendermode & 0xf;
        }
        else {
          peVar7 = (this->super_CBeam).super_CBaseEntity.pev;
          position = &(peVar5->v).origin;
          uVar6 = peVar7->rendermode & 0xf;
        }
      }
      peVar2 = peVar7;
      if (uVar6 == 2) {
                    /* Unresolved local var: edict_t * pent@[???] */
        peVar5 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar7->sequence & 0xfff);
        peVar7 = (this->super_CBeam).super_CBaseEntity.pev;
        peVar2 = &peVar5->v;
      }
      uVar6 = peVar7->spawnflags;
      if ((uVar6 & 0x30) != 0) {
        if ((uVar6 & 0x10) != 0) {
          UTIL_Sparks(&peVar2->origin);
          peVar7 = (this->super_CBeam).super_CBaseEntity.pev;
          uVar6 = peVar7->spawnflags;
        }
        if ((uVar6 & 0x20) != 0) {
          UTIL_Sparks(position);
          peVar7 = (this->super_CBeam).super_CBaseEntity.pev;
        }
      }
      p1Var3 = gpGlobals;
      if (0.0 < peVar7->dmg) {
        peVar7->nextthink = gpGlobals->time;
        ((this->super_CBeam).super_CBaseEntity.pev)->dmgtime = p1Var3->time;
        return;
      }
    }
    else {
      peVar7 = (this->super_CBeam).super_CBaseEntity.pev;
      this->m_active = 0;
      piVar1 = &peVar7->effects;
      *piVar1 = *piVar1 | 0x80;
      ((this->super_CBeam).super_CBaseEntity.pev)->nextthink = 0.0;
    }
  }
  return;
}


// CLightning::StrikeUse  @ 0008bf70  (line 603)

/* DWARF original prototype: void StrikeUse(CLightning * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CLightning::StrikeUse
          (CLightning *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  _2globalvars_t *p1Var1;
  int iVar2;
  
  iVar2 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,this->m_active);
  p1Var1 = gpGlobals;
  if (iVar2 != 0) {
    if (this->m_active == 0) {
      (this->super_CBeam).super_CBaseEntity.m_pfnThink.__pfn = StrikeThink;
      (this->super_CBeam).super_CBaseEntity.m_pfnThink.__delta = 0;
      ((this->super_CBeam).super_CBaseEntity.pev)->nextthink = p1Var1->time + 0.1;
    }
    else {
      this->m_active = 0;
      (this->super_CBeam).super_CBaseEntity.m_pfnThink.__pfn =
           (_func___thiscall_void_CBaseEntity_ptr *)0x0;
      (this->super_CBeam).super_CBaseEntity.m_pfnThink.__delta = 0;
    }
    if ((((this->super_CBeam).super_CBaseEntity.pev)->spawnflags & 2) == 0) {
      (this->super_CBeam).super_CBaseEntity.m_pfnUse.__pfn =
           (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *)
           0x0;
      (this->super_CBeam).super_CBaseEntity.m_pfnUse.__delta = 0;
    }
  }
  return;
}


// IsPointEntity  @ 0008ed20  (line 624)

int IsPointEntity(CBaseEntity *pEnt)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  if (pEnt->pev->modelindex != 0) {
    iVar1 = 0xc;
    pcVar2 = gpGlobals->pStringBase + pEnt->pev->classname;
    bVar5 = pcVar2 == (char *)0x0;
    pcVar3 = pcVar2;
    pcVar4 = "info_target";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      iVar1 = 0xe;
      pcVar3 = pcVar2;
      pcVar4 = "info_landmark";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (!bVar5) {
        iVar1 = 0xc;
        pcVar3 = "path_corner";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar5 = *pcVar2 == *pcVar3;
          pcVar2 = pcVar2 + 1;
          pcVar3 = pcVar3 + 1;
        } while (bVar5);
        return (uint)bVar5;
      }
    }
  }
  return 1;
}


// CLightning::StrikeThink  @ 0008f780  (line 635)

/* DWARF original prototype: void StrikeThink(CLightning * this) */

void __thiscall CLightning::StrikeThink(CLightning *this)

{
  int iVar1;
  float fVar2;
  _func_void_int *p_Var3;
  int32 iVar4;
  entvars_t *peVar5;
  entvars_t *peVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  CBaseEntity *pCVar12;
  CBaseEntity *pCVar13;
  byte *pbVar14;
  char *pcVar15;
  byte *pbVar16;
  char *pcVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  byte bVar21;
  longdouble extraout_ST0;
  char *local_84;
  CBaseEntity *local_7c;
  char *local_78;
  char *local_70;
  string_t local_64;
  _1TraceResult local_54;
  
                    /* Unresolved local var: CBaseEntity * pStart@[???]
                       Unresolved local var: CBaseEntity * pEnd@[???] */
  bVar21 = 0;
  if (this->m_life != 0.0) {
    peVar6 = (this->super_CBeam).super_CBaseEntity.pev;
    fVar2 = this->m_life + gpGlobals->time;
    if ((peVar6->spawnflags & 4) == 0) {
      peVar6->nextthink = fVar2 + this->m_restrike;
    }
    else {
      (*g_engfuncs.pfnRandomFloat)(0.0,this->m_restrike);
      peVar6->nextthink = (float)(extraout_ST0 + (longdouble)fVar2);
    }
  }
  this->m_active = 1;
  if (this->m_iszEndEntity == 0) {
    iVar8 = this->m_iszStartEntity;
    if (iVar8 == 0) {
      RandomArea(this);
      return;
    }
                    /* Unresolved local var: CBaseEntity * pStart@[???] */
                    /* Unresolved local var: int total@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pNewEntity@[???] */
    pCVar12 = (CBaseEntity *)0x0;
    pcVar10 = gpGlobals->pStringBase;
    iVar9 = 0;
    pCVar13 = (CBaseEntity *)0x0;
    while (pCVar12 = UTIL_FindEntityByTargetname(pCVar12,pcVar10 + iVar8),
          pCVar12 != (CBaseEntity *)0x0) {
      iVar1 = iVar9 + 1;
      iVar4 = (*g_engfuncs.pfnRandomLong)(0,iVar9);
      iVar9 = iVar1;
      if (iVar4 < 1) {
        pCVar13 = pCVar12;
      }
    }
    if (pCVar13 != (CBaseEntity *)0x0) {
      RandomPoint(this,&pCVar13->pev->origin);
      return;
    }
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"env_beam: unknown entity \"%s\"\n",
               gpGlobals->pStringBase + this->m_iszStartEntity);
    return;
  }
                    /* Unresolved local var: int total@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pNewEntity@[???] */
  pCVar13 = (CBaseEntity *)0x0;
  iVar8 = this->m_iszStartEntity;
  pcVar10 = gpGlobals->pStringBase;
  iVar9 = 0;
  local_7c = (CBaseEntity *)0x0;
  while (pCVar13 = UTIL_FindEntityByTargetname(pCVar13,pcVar10 + iVar8),
        pCVar13 != (CBaseEntity *)0x0) {
    iVar1 = iVar9 + 1;
    iVar4 = (*g_engfuncs.pfnRandomLong)(0,iVar9);
    iVar9 = iVar1;
    if (iVar4 < 1) {
      local_7c = pCVar13;
    }
  }
  iVar8 = this->m_iszEndEntity;
                    /* Unresolved local var: int total@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pNewEntity@[???] */
  pcVar10 = gpGlobals->pStringBase;
  pCVar13 = (CBaseEntity *)0x0;
  pCVar12 = (CBaseEntity *)0x0;
  iVar9 = 0;
  while (pCVar13 = UTIL_FindEntityByTargetname(pCVar13,pcVar10 + iVar8),
        pCVar13 != (CBaseEntity *)0x0) {
    iVar1 = iVar9 + 1;
    iVar4 = (*g_engfuncs.pfnRandomLong)(0,iVar9);
    iVar9 = iVar1;
    if (iVar4 < 1) {
      pCVar12 = pCVar13;
    }
  }
  if (local_7c == (CBaseEntity *)0x0) {
    return;
  }
  if (pCVar12 == (CBaseEntity *)0x0) {
    return;
  }
  if (local_7c->pev->modelindex == 0) {
LAB_0008fa40:
    if ((((this->super_CBeam).super_CBaseEntity.pev)->spawnflags & 8) != 0) {
      return;
    }
  }
  else {
    uVar11 = local_7c->pev->classname;
    pcVar10 = gpGlobals->pStringBase;
    bVar18 = CARRY4(uVar11,(uint)pcVar10);
    pbVar7 = (byte *)(pcVar10 + uVar11);
    bVar20 = pbVar7 == (byte *)0x0;
    iVar8 = 0xc;
    pbVar14 = pbVar7;
    pbVar16 = (byte *)"info_target";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar18 = *pbVar14 < *pbVar16;
      bVar20 = *pbVar14 == *pbVar16;
      pbVar14 = pbVar14 + (uint)bVar21 * -2 + 1;
      pbVar16 = pbVar16 + (uint)bVar21 * -2 + 1;
    } while (bVar20);
    bVar19 = (!bVar18 && !bVar20) < bVar18;
    if ((!bVar18 && !bVar20) == bVar18) goto LAB_0008fa40;
    iVar8 = 0xe;
    bVar18 = false;
    pbVar14 = pbVar7;
    pbVar16 = (byte *)"info_landmark";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar19 = *pbVar14 < *pbVar16;
      bVar18 = *pbVar14 == *pbVar16;
      pbVar14 = pbVar14 + (uint)bVar21 * -2 + 1;
      pbVar16 = pbVar16 + (uint)bVar21 * -2 + 1;
    } while (bVar18);
    if ((!bVar19 && !bVar18) == bVar19) goto LAB_0008fa40;
    iVar8 = 0xc;
    bVar18 = false;
    pbVar14 = (byte *)"path_corner";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar18 = *pbVar7 == *pbVar14;
      pbVar7 = pbVar7 + (uint)bVar21 * -2 + 1;
      pbVar14 = pbVar14 + (uint)bVar21 * -2 + 1;
    } while (bVar18);
    if ((bVar18) || (pCVar12->pev->modelindex == 0)) goto LAB_0008fa40;
    pcVar10 = pcVar10 + pCVar12->pev->classname;
    bVar18 = pcVar10 == (char *)0x0;
    iVar8 = 0xc;
    pcVar15 = pcVar10;
    pcVar17 = "info_target";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar18 = *pcVar15 == *pcVar17;
      pcVar15 = pcVar15 + (uint)bVar21 * -2 + 1;
      pcVar17 = pcVar17 + (uint)bVar21 * -2 + 1;
    } while (bVar18);
    if (bVar18) goto LAB_0008fa40;
    iVar8 = 0xe;
    bVar18 = false;
    pcVar15 = pcVar10;
    pcVar17 = "info_landmark";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar18 = *pcVar15 == *pcVar17;
      pcVar15 = pcVar15 + (uint)bVar21 * -2 + 1;
      pcVar17 = pcVar17 + (uint)bVar21 * -2 + 1;
    } while (bVar18);
    if (bVar18) goto LAB_0008fa40;
    iVar8 = 0xc;
    bVar18 = false;
    pcVar15 = "path_corner";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar18 = *pcVar10 == *pcVar15;
      pcVar10 = pcVar10 + (uint)bVar21 * -2 + 1;
      pcVar15 = pcVar15 + (uint)bVar21 * -2 + 1;
    } while (bVar18);
    if (bVar18) goto LAB_0008fa40;
  }
  (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
  peVar6 = local_7c->pev;
  iVar8 = peVar6->modelindex;
  if (iVar8 == 0) {
    if (pCVar12->pev->modelindex != 0) {
      iVar9 = 0xc;
      local_78 = gpGlobals->pStringBase;
      local_70 = local_78 + pCVar12->pev->classname;
      bVar18 = local_70 == (char *)0x0;
      pcVar10 = local_70;
      pcVar15 = "info_target";
      do {
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        bVar18 = *pcVar10 == *pcVar15;
        pcVar10 = pcVar10 + (uint)bVar21 * -2 + 1;
        pcVar15 = pcVar15 + (uint)bVar21 * -2 + 1;
      } while (bVar18);
      if (!bVar18) {
LAB_0008fb6e:
        iVar9 = 0xe;
        pcVar10 = local_70;
        pcVar15 = "info_landmark";
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          bVar18 = *pcVar10 == *pcVar15;
          pcVar10 = pcVar10 + (uint)bVar21 * -2 + 1;
          pcVar15 = pcVar15 + (uint)bVar21 * -2 + 1;
        } while (bVar18);
        if (!bVar18) {
          iVar9 = 0xc;
          pcVar10 = local_70;
          pcVar15 = "path_corner";
          do {
            if (iVar9 == 0) break;
            iVar9 = iVar9 + -1;
            bVar18 = *pcVar10 == *pcVar15;
            pcVar10 = pcVar10 + (uint)bVar21 * -2 + 1;
            pcVar15 = pcVar15 + (uint)bVar21 * -2 + 1;
          } while (bVar18);
          if (bVar18) goto LAB_0008fb83;
          bVar18 = false;
          pCVar13 = local_7c;
          local_7c = pCVar12;
          goto LAB_0008fbc1;
        }
LAB_0008fb83:
        if (iVar8 != 0) goto LAB_0008fb8f;
      }
    }
  }
  else {
    local_64 = peVar6->classname;
    local_78 = gpGlobals->pStringBase;
    pcVar10 = local_78 + local_64;
    bVar18 = pcVar10 == (char *)0x0;
    iVar9 = 0xc;
    pcVar15 = pcVar10;
    pcVar17 = "info_target";
    do {
      if (iVar9 == 0) break;
      iVar9 = iVar9 + -1;
      bVar18 = *pcVar15 == *pcVar17;
      pcVar15 = pcVar15 + (uint)bVar21 * -2 + 1;
      pcVar17 = pcVar17 + (uint)bVar21 * -2 + 1;
    } while (bVar18);
    if (bVar18) {
LAB_0008fb30:
      peVar5 = pCVar12->pev;
      iVar9 = peVar5->modelindex;
LAB_0008fb39:
      if (iVar9 != 0) {
        local_78 = gpGlobals->pStringBase;
        local_70 = local_78 + peVar5->classname;
        iVar9 = strcmp(local_70,"info_target");
        bVar18 = iVar9 == 0;
        if (!bVar18) goto LAB_0008fb6e;
LAB_0008fb8f:
        local_64 = peVar6->classname;
      }
    }
    else {
      iVar9 = 0xe;
      bVar18 = false;
      pcVar15 = pcVar10;
      pcVar17 = "info_landmark";
      do {
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        bVar18 = *pcVar15 == *pcVar17;
        pcVar15 = pcVar15 + (uint)bVar21 * -2 + 1;
        pcVar17 = pcVar17 + (uint)bVar21 * -2 + 1;
      } while (bVar18);
      if (bVar18) goto LAB_0008fb30;
      peVar5 = pCVar12->pev;
      iVar9 = 0xc;
      bVar18 = false;
      pcVar15 = "path_corner";
      do {
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        bVar18 = *pcVar10 == *pcVar15;
        pcVar10 = pcVar10 + (uint)bVar21 * -2 + 1;
        pcVar15 = pcVar15 + (uint)bVar21 * -2 + 1;
      } while (bVar18);
      if (bVar18) {
        iVar9 = peVar5->modelindex;
        goto LAB_0008fb39;
      }
      if (peVar5->modelindex != 0) {
        iVar9 = 0xc;
        local_84 = "info_target";
        local_78 = local_78 + peVar5->classname;
        bVar18 = local_78 == (char *)0x0;
        pcVar10 = local_78;
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          bVar18 = *pcVar10 == *local_84;
          pcVar10 = pcVar10 + (uint)bVar21 * -2 + 1;
          local_84 = local_84 + (uint)bVar21 * -2 + 1;
        } while (bVar18);
        if (!bVar18) {
          iVar9 = 0xe;
          bVar18 = false;
          pcVar10 = local_78;
          pcVar15 = "info_landmark";
          do {
            if (iVar9 == 0) break;
            iVar9 = iVar9 + -1;
            bVar18 = *pcVar10 == *pcVar15;
            pcVar10 = pcVar10 + (uint)bVar21 * -2 + 1;
            pcVar15 = pcVar15 + (uint)bVar21 * -2 + 1;
          } while (bVar18);
          if (!bVar18) {
            iVar9 = 0xc;
            bVar18 = false;
            pcVar10 = "path_corner";
            do {
              if (iVar9 == 0) break;
              iVar9 = iVar9 + -1;
              bVar18 = *local_78 == *pcVar10;
              local_78 = local_78 + (uint)bVar21 * -2 + 1;
              pcVar10 = pcVar10 + (uint)bVar21 * -2 + 1;
            } while (bVar18);
            if (!bVar18) {
              if ((((this->super_CBeam).super_CBaseEntity.pev)->spawnflags & 8) == 0) {
                (*g_engfuncs.pfnWriteByte)(8);
              }
              else {
                (*g_engfuncs.pfnWriteByte)(0x18);
              }
              p_Var3 = g_engfuncs.pfnWriteShort;
              iVar8 = (*g_engfuncs.pfnIndexOfEdict)(local_7c->pev->pContainingEntity);
              (*p_Var3)(iVar8);
              p_Var3 = g_engfuncs.pfnWriteShort;
              iVar8 = (*g_engfuncs.pfnIndexOfEdict)(pCVar12->pev->pContainingEntity);
              (*p_Var3)(iVar8);
              goto LAB_0008fd56;
            }
          }
        }
        local_78 = gpGlobals->pStringBase;
        iVar9 = 0xc;
        local_70 = local_78 + peVar5->classname;
        bVar18 = local_70 == (char *)0x0;
        pcVar10 = local_70;
        pcVar15 = "info_target";
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          bVar18 = *pcVar10 == *pcVar15;
          pcVar10 = pcVar10 + (uint)bVar21 * -2 + 1;
          pcVar15 = pcVar15 + (uint)bVar21 * -2 + 1;
        } while (bVar18);
        if (!bVar18) {
          bVar18 = false;
          goto LAB_0008fb6e;
        }
      }
    }
    iVar8 = 0xc;
    local_84 = "info_target";
    local_70 = local_78 + local_64;
    bVar18 = local_70 == (char *)0x0;
    pcVar10 = local_70;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar18 = *pcVar10 == *local_84;
      pcVar10 = pcVar10 + (uint)bVar21 * -2 + 1;
      local_84 = local_84 + (uint)bVar21 * -2 + 1;
    } while (bVar18);
    pCVar13 = pCVar12;
    if (!bVar18) {
LAB_0008fbc1:
      iVar8 = 0xe;
      pcVar10 = local_70;
      pcVar15 = "info_landmark";
      do {
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        bVar18 = *pcVar10 == *pcVar15;
        pcVar10 = pcVar10 + (uint)bVar21 * -2 + 1;
        pcVar15 = pcVar15 + (uint)bVar21 * -2 + 1;
      } while (bVar18);
      pCVar12 = pCVar13;
      if (!bVar18) {
        iVar8 = 0xc;
        pcVar10 = "path_corner";
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          bVar18 = *local_70 == *pcVar10;
          local_70 = local_70 + (uint)bVar21 * -2 + 1;
          pcVar10 = pcVar10 + (uint)bVar21 * -2 + 1;
        } while (bVar18);
        if (!bVar18) {
          (*g_engfuncs.pfnWriteByte)(1);
          p_Var3 = g_engfuncs.pfnWriteShort;
          iVar8 = (*g_engfuncs.pfnIndexOfEdict)(local_7c->pev->pContainingEntity);
          (*p_Var3)(iVar8);
          (*g_engfuncs.pfnWriteCoord)((pCVar13->pev->origin).x);
          (*g_engfuncs.pfnWriteCoord)((pCVar13->pev->origin).y);
          (*g_engfuncs.pfnWriteCoord)((pCVar13->pev->origin).z);
          goto LAB_0008fd56;
        }
      }
    }
  }
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteCoord)((local_7c->pev->origin).x);
  (*g_engfuncs.pfnWriteCoord)((local_7c->pev->origin).y);
  (*g_engfuncs.pfnWriteCoord)((local_7c->pev->origin).z);
  (*g_engfuncs.pfnWriteCoord)((pCVar12->pev->origin).x);
  (*g_engfuncs.pfnWriteCoord)((pCVar12->pev->origin).y);
  (*g_engfuncs.pfnWriteCoord)((pCVar12->pev->origin).z);
LAB_0008fd56:
  (*g_engfuncs.pfnWriteShort)(this->m_spriteTexture);
  (*g_engfuncs.pfnWriteByte)(this->m_frameStart);
  (*g_engfuncs.pfnWriteByte)((int)((this->super_CBeam).super_CBaseEntity.pev)->framerate);
  (*g_engfuncs.pfnWriteByte)((int)(this->m_life * 10.0));
  (*g_engfuncs.pfnWriteByte)(this->m_boltWidth);
  (*g_engfuncs.pfnWriteByte)(this->m_noiseAmplitude);
  (*g_engfuncs.pfnWriteByte)((int)(((this->super_CBeam).super_CBaseEntity.pev)->rendercolor).x);
  (*g_engfuncs.pfnWriteByte)((int)(((this->super_CBeam).super_CBaseEntity.pev)->rendercolor).y);
  (*g_engfuncs.pfnWriteByte)((int)(((this->super_CBeam).super_CBaseEntity.pev)->rendercolor).z);
  (*g_engfuncs.pfnWriteByte)((int)((this->super_CBeam).super_CBaseEntity.pev)->renderamt);
  (*g_engfuncs.pfnWriteByte)(this->m_speed);
  (*g_engfuncs.pfnMessageEnd)();
  peVar6 = (this->super_CBeam).super_CBaseEntity.pev;
  uVar11 = peVar6->spawnflags;
  if ((uVar11 & 0x30) != 0) {
    peVar5 = pCVar12->pev;
    if ((uVar11 & 0x10) != 0) {
      UTIL_Sparks(&local_7c->pev->origin);
      peVar6 = (this->super_CBeam).super_CBaseEntity.pev;
      uVar11 = peVar6->spawnflags;
    }
    if ((uVar11 & 0x20) != 0) {
      UTIL_Sparks(&peVar5->origin);
      peVar6 = (this->super_CBeam).super_CBaseEntity.pev;
    }
  }
  if (0.0 < peVar6->dmg) {
                    /* Unresolved local var: TraceResult tr@[???] */
    UTIL_TraceLine(&local_7c->pev->origin,&pCVar12->pev->origin,dont_ignore_monsters,(edict_t *)0x0,
                   &local_54);
    ((this->super_CBeam).super_CBaseEntity.pev)->dmgtime = gpGlobals->time - 1.0;
    CBeam::BeamDamage(&this->super_CBeam,&local_54);
  }
  return;
}


// CBeam::BeamDamage  @ 0008edb0  (line 740)

/* DWARF original prototype: void BeamDamage(CBeam * this, 11TraceResult * ptr) */

void __thiscall CBeam::BeamDamage(CBeam *this,_1TraceResult *ptr)

{
  int *piVar1;
  code *pcVar2;
  float fVar3;
  float __x;
  uint uVar4;
  entvars_t *peVar5;
  int32 iVar6;
  float local_28;
  float local_24;
  float local_20;
  
  RelinkBeam(this);
                    /* Unresolved local var: CBaseEntity * pHit@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((ptr->flFraction != 1.0) && (ptr->pHit != (edict_t *)0x0)) &&
     (piVar1 = ptr->pHit->pvPrivateData, piVar1 != (int *)0x0)) {
    ClearMultiDamage();
    pcVar2 = *(code **)(*piVar1 + 0x30);
    peVar5 = (this->super_CBaseEntity).pev;
    fVar3 = (ptr->vecEndPos).z - (peVar5->origin).z;
    local_24 = (ptr->vecEndPos).y - (peVar5->origin).y;
    local_28 = (ptr->vecEndPos).x - (peVar5->origin).x;
                    /* Unresolved local var: float flLen@[???] */
    __x = fVar3 * fVar3 + local_24 * local_24 + local_28 * local_28;
    local_20 = SQRT(__x);
    if (NAN(local_20)) {
      local_20 = sqrtf(__x);
      peVar5 = (this->super_CBaseEntity).pev;
    }
    if (local_20 == 0.0) {
      local_28 = 0.0;
      local_24 = 0.0;
      local_20 = 1.0;
    }
    else {
      local_20 = 1.0 / local_20;
      local_28 = local_28 * local_20;
      local_24 = local_24 * local_20;
      local_20 = local_20 * fVar3;
    }
    (*pcVar2)(piVar1,peVar5,(gpGlobals->time - peVar5->dmgtime) * peVar5->dmg,&local_28,ptr,0x400);
    peVar5 = (this->super_CBaseEntity).pev;
    ApplyMultiDamage(peVar5,peVar5);
    peVar5 = (this->super_CBaseEntity).pev;
    if ((peVar5->spawnflags & 0x40) == 0) goto LAB_0008eef3;
    if (*(code **)(*piVar1 + 0x8c) == CBaseEntity::IsBSPModel) {
      if (*(int *)(piVar1[1] + 0x10c) != 4) {
        uVar4 = (uint)(*(int *)(piVar1[1] + 0x108) == 0xd);
        goto LAB_0008eee2;
      }
    }
    else {
      uVar4 = (**(code **)(*piVar1 + 0x8c))(piVar1);
LAB_0008eee2:
      if (uVar4 == 0) goto LAB_0008eef0;
    }
    iVar6 = (*g_engfuncs.pfnRandomLong)(0,4);
    UTIL_DecalTrace(ptr,iVar6 + 0x1c);
  }
LAB_0008eef0:
  peVar5 = (this->super_CBaseEntity).pev;
LAB_0008eef3:
  peVar5->dmgtime = gpGlobals->time;
  return;
}


// CLightning::DamageThink  @ 0008e840  (line 762)

/* DWARF original prototype: void DamageThink(CLightning * this) */

void __thiscall CLightning::DamageThink(CLightning *this)

{
  int *piVar1;
  code *pcVar2;
  float fVar3;
  float __x;
  edict_t *peVar4;
  entvars_t *peVar5;
  int32 iVar6;
  uint uVar7;
  Vector *vecEnd;
  float local_60;
  float local_5c;
  float local_58;
  _1TraceResult local_54;
  
                    /* Unresolved local var: TraceResult tr@[???] */
  ((this->super_CBeam).super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  peVar5 = (this->super_CBeam).super_CBaseEntity.pev;
                    /* Unresolved local var: int type@[???]
                       Unresolved local var: edict_t * pent@[???] */
  uVar7 = peVar5->rendermode & 0xf;
  if ((uVar7 == 0) || (uVar7 == 3)) {
    vecEnd = &peVar5->angles;
  }
  else {
    peVar4 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar5->skin & 0xfff);
    if (peVar4 == (edict_t *)0x0) {
      peVar5 = (this->super_CBeam).super_CBaseEntity.pev;
      vecEnd = &peVar5->angles;
      uVar7 = peVar5->rendermode & 0xf;
    }
    else {
      peVar5 = (this->super_CBeam).super_CBaseEntity.pev;
      vecEnd = &(peVar4->v).origin;
      uVar7 = peVar5->rendermode & 0xf;
    }
  }
  if (uVar7 == 2) {
                    /* Unresolved local var: edict_t * pent@[???] */
    peVar4 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar5->sequence & 0xfff);
    peVar5 = &peVar4->v;
  }
  UTIL_TraceLine(&peVar5->origin,vecEnd,dont_ignore_monsters,(edict_t *)0x0,&local_54);
  CBeam::RelinkBeam(&this->super_CBeam);
                    /* Unresolved local var: CBaseEntity * pHit@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((local_54.flFraction != 1.0) && (local_54.pHit != (edict_t *)0x0)) &&
     (piVar1 = (local_54.pHit)->pvPrivateData, piVar1 != (int *)0x0)) {
    ClearMultiDamage();
    pcVar2 = *(code **)(*piVar1 + 0x30);
    peVar5 = (this->super_CBeam).super_CBaseEntity.pev;
    fVar3 = local_54.vecEndPos.z - (peVar5->origin).z;
    local_5c = local_54.vecEndPos.y - (peVar5->origin).y;
    local_60 = local_54.vecEndPos.x - (peVar5->origin).x;
                    /* Unresolved local var: float flLen@[???] */
    __x = fVar3 * fVar3 + local_5c * local_5c + local_60 * local_60;
    local_58 = SQRT(__x);
    if (NAN(local_58)) {
      local_58 = sqrtf(__x);
      peVar5 = (this->super_CBeam).super_CBaseEntity.pev;
    }
    if (local_58 == 0.0) {
      local_60 = 0.0;
      local_5c = 0.0;
      local_58 = 1.0;
    }
    else {
      local_58 = 1.0 / local_58;
      local_60 = local_60 * local_58;
      local_5c = local_5c * local_58;
      local_58 = local_58 * fVar3;
    }
    (*pcVar2)(piVar1,peVar5,(gpGlobals->time - peVar5->dmgtime) * peVar5->dmg,&local_60,&local_54,
              0x400);
    peVar5 = (this->super_CBeam).super_CBaseEntity.pev;
    ApplyMultiDamage(peVar5,peVar5);
    peVar5 = (this->super_CBeam).super_CBaseEntity.pev;
    if ((peVar5->spawnflags & 0x40) == 0) goto LAB_0008ea03;
    if (*(code **)(*piVar1 + 0x8c) == CBaseEntity::IsBSPModel) {
      if (*(int *)(piVar1[1] + 0x10c) != 4) {
        uVar7 = (uint)(*(int *)(piVar1[1] + 0x108) == 0xd);
        goto LAB_0008e9fb;
      }
    }
    else {
      uVar7 = (**(code **)(*piVar1 + 0x8c))(piVar1);
LAB_0008e9fb:
      if (uVar7 == 0) goto LAB_0008ea00;
    }
    iVar6 = (*g_engfuncs.pfnRandomLong)(0,4);
    UTIL_DecalTrace(&local_54,iVar6 + 0x1c);
  }
LAB_0008ea00:
  peVar5 = (this->super_CBeam).super_CBaseEntity.pev;
LAB_0008ea03:
  peVar5->dmgtime = gpGlobals->time;
  return;
}


// CLightning::Zap  @ 0008efc0  (line 772)

/* DWARF original prototype: void Zap(CLightning * this, Vector * vecSrc, Vector * vecDest) */

void __thiscall CLightning::Zap(CLightning *this,Vector *vecSrc,Vector *vecDest)

{
  uint uVar1;
  
  (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteCoord)(vecSrc->x);
  (*g_engfuncs.pfnWriteCoord)(vecSrc->y);
  (*g_engfuncs.pfnWriteCoord)(vecSrc->z);
  (*g_engfuncs.pfnWriteCoord)(vecDest->x);
  (*g_engfuncs.pfnWriteCoord)(vecDest->y);
  (*g_engfuncs.pfnWriteCoord)(vecDest->z);
  (*g_engfuncs.pfnWriteShort)(this->m_spriteTexture);
  (*g_engfuncs.pfnWriteByte)(this->m_frameStart);
  (*g_engfuncs.pfnWriteByte)((int)((this->super_CBeam).super_CBaseEntity.pev)->framerate);
  (*g_engfuncs.pfnWriteByte)((int)(this->m_life * 10.0));
  (*g_engfuncs.pfnWriteByte)(this->m_boltWidth);
  (*g_engfuncs.pfnWriteByte)(this->m_noiseAmplitude);
  (*g_engfuncs.pfnWriteByte)((int)(((this->super_CBeam).super_CBaseEntity.pev)->rendercolor).x);
  (*g_engfuncs.pfnWriteByte)((int)(((this->super_CBeam).super_CBaseEntity.pev)->rendercolor).y);
  (*g_engfuncs.pfnWriteByte)((int)(((this->super_CBeam).super_CBaseEntity.pev)->rendercolor).z);
  (*g_engfuncs.pfnWriteByte)((int)((this->super_CBeam).super_CBaseEntity.pev)->renderamt);
  (*g_engfuncs.pfnWriteByte)(this->m_speed);
  (*g_engfuncs.pfnMessageEnd)();
  uVar1 = ((this->super_CBeam).super_CBaseEntity.pev)->spawnflags;
  if ((uVar1 & 0x30) != 0) {
    if ((uVar1 & 0x10) != 0) {
      UTIL_Sparks(vecSrc);
      uVar1 = ((this->super_CBeam).super_CBaseEntity.pev)->spawnflags;
    }
    if ((uVar1 & 0x20) != 0) {
      UTIL_Sparks(vecDest);
      return;
    }
  }
  return;
}


// CLightning::RandomArea  @ 0008f180  (line 813)

/* DWARF original prototype: void RandomArea(CLightning * this) */

void __thiscall CLightning::RandomArea(CLightning *this)

{
  entvars_t *peVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float local_bc;
  float local_b8;
  float local_b4;
  int local_b0;
  Vector local_a4;
  Vector local_98;
  _1TraceResult local_8c;
  _1TraceResult local_54;
  
                    /* Unresolved local var: int iLoops@[???] */
  local_b0 = 10;
  do {
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecDir1@[???]
                       Unresolved local var: TraceResult tr1@[???]
                       Unresolved local var: Vector vecDir2@[???]
                       Unresolved local var: TraceResult tr2@[???] */
    peVar1 = (this->super_CBeam).super_CBaseEntity.pev;
    local_a4.x = (peVar1->origin).x;
    local_a4.y = (peVar1->origin).y;
    local_a4.z = (peVar1->origin).z;
    lVar2 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
    lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
    lVar4 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
                    /* Unresolved local var: float flLen@[???] */
    lVar5 = (longdouble)(float)lVar3;
    lVar6 = (longdouble)(float)lVar2;
    lVar6 = lVar6 * lVar6 + lVar5 * lVar5 + lVar4 * lVar4;
    lVar5 = SQRT(lVar6);
    if (NAN(lVar5)) {
      fVar7 = sqrtf((float)lVar6);
      lVar5 = (longdouble)fVar7;
      lVar4 = (longdouble)(float)lVar4;
    }
    if (lVar5 == (longdouble)0) {
      local_bc = 0.0;
      local_b8 = 1.0;
      local_b4 = 0.0;
    }
    else {
      lVar5 = (longdouble)1.0 / lVar5;
      local_b8 = (float)((longdouble)(float)lVar2 * lVar5);
      local_bc = (float)((longdouble)(float)lVar3 * lVar5);
      local_b4 = (float)(lVar5 * lVar4);
    }
    fVar7 = this->m_radius;
    local_54.fInOpen = (int)(local_b8 * fVar7 + local_a4.z);
    local_54.fStartSolid = (int)(local_bc * fVar7 + local_a4.y);
    local_54.fAllSolid = (int)(fVar7 * local_b4 + local_a4.x);
    UTIL_TraceLine(&local_a4,(Vector *)&local_54,ignore_monsters,
                   ((this->super_CBeam).super_CBaseEntity.pev)->pContainingEntity,&local_8c);
    if (local_8c.flFraction != 1.0) {
      do {
        lVar2 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
        fVar7 = (float)lVar2;
        lVar2 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
        fVar9 = (float)lVar2;
        lVar2 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
      } while ((longdouble)0 <
               (longdouble)fVar7 * (longdouble)local_b8 +
               (longdouble)fVar9 * (longdouble)local_bc + (longdouble)local_b4 * lVar2);
                    /* Unresolved local var: float flLen@[???] */
      lVar5 = (longdouble)fVar7 * (longdouble)fVar7 +
              lVar2 * lVar2 + (longdouble)fVar9 * (longdouble)fVar9;
      lVar3 = SQRT(lVar5);
      if (NAN(lVar3)) {
        fVar8 = sqrtf((float)lVar5);
        lVar3 = (longdouble)fVar8;
        lVar2 = (longdouble)(float)lVar2;
      }
      if (lVar3 == (longdouble)0) {
        lVar5 = (longdouble)1;
        lVar6 = (longdouble)0;
        lVar2 = lVar6;
      }
      else {
        lVar3 = (longdouble)1.0 / lVar3;
        lVar5 = (longdouble)fVar7 * lVar3;
        lVar6 = (longdouble)fVar9 * lVar3;
        lVar2 = lVar3 * lVar2;
      }
      local_98.x = (vec_t)(lVar2 * (longdouble)this->m_radius + (longdouble)local_a4.x);
      local_98.y = (vec_t)(lVar6 * (longdouble)this->m_radius + (longdouble)local_a4.y);
      local_98.z = (vec_t)(lVar5 * (longdouble)this->m_radius + (longdouble)local_a4.z);
      UTIL_TraceLine(&local_a4,&local_98,ignore_monsters,
                     ((this->super_CBeam).super_CBaseEntity.pev)->pContainingEntity,&local_54);
      if (local_54.flFraction != 1.0) {
        fVar7 = (local_8c.vecEndPos.z - local_54.vecEndPos.z) *
                (local_8c.vecEndPos.z - local_54.vecEndPos.z) +
                (local_8c.vecEndPos.y - local_54.vecEndPos.y) *
                (local_8c.vecEndPos.y - local_54.vecEndPos.y) +
                (local_8c.vecEndPos.x - local_54.vecEndPos.x) *
                (local_8c.vecEndPos.x - local_54.vecEndPos.x);
        fVar9 = SQRT(fVar7);
        if (NAN(fVar9)) {
          fVar9 = sqrtf(fVar7);
        }
        if (this->m_radius * 0.1 <= fVar9) {
          UTIL_TraceLine(&local_8c.vecEndPos,&local_54.vecEndPos,ignore_monsters,
                         ((this->super_CBeam).super_CBaseEntity.pev)->pContainingEntity,&local_54);
          if (local_54.flFraction == 1.0) {
            Zap(this,&local_8c.vecEndPos,&local_54.vecEndPos);
            return;
          }
        }
      }
    }
    local_b0 = local_b0 + -1;
  } while (local_b0 != 0);
  return;
}


// CLightning::RandomPoint  @ 0008f590  (line 855)

/* DWARF original prototype: void RandomPoint(CLightning * this, Vector * vecSrc) */

void __thiscall CLightning::RandomPoint(CLightning *this,Vector *vecSrc)

{
  float fVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  float fVar7;
  float fVar8;
  int local_74;
  Vector local_60;
  _1TraceResult local_54;
  
                    /* Unresolved local var: int iLoops@[???] */
  local_74 = 10;
  while( true ) {
    lVar2 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
    lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
    lVar4 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
    lVar5 = (longdouble)(float)lVar3;
    lVar6 = (longdouble)(float)lVar2;
    lVar6 = lVar6 * lVar6 + lVar5 * lVar5 + lVar4 * lVar4;
    lVar5 = SQRT(lVar6);
    if (NAN(lVar5)) {
      fVar7 = sqrtf((float)lVar6);
      lVar5 = (longdouble)fVar7;
      lVar4 = (longdouble)(float)lVar4;
    }
    if (lVar5 == (longdouble)0) {
      lVar2 = (longdouble)1;
      lVar3 = (longdouble)0;
      lVar5 = lVar3;
    }
    else {
                    /* Unresolved local var: Vector vecDir1@[???]
                       Unresolved local var: TraceResult tr1@[???]
                       Unresolved local var: float flLen@[???] */
      lVar5 = (longdouble)1.0 / lVar5;
      lVar2 = (longdouble)(float)lVar2 * lVar5;
      lVar3 = (longdouble)(float)lVar3 * lVar5;
      lVar5 = lVar5 * lVar4;
    }
    local_60.x = (vec_t)(lVar5 * (longdouble)this->m_radius + (longdouble)vecSrc->x);
    local_60.y = (vec_t)(lVar3 * (longdouble)this->m_radius + (longdouble)vecSrc->y);
    local_60.z = (vec_t)(lVar2 * (longdouble)this->m_radius + (longdouble)vecSrc->z);
    UTIL_TraceLine(vecSrc,&local_60,ignore_monsters,
                   ((this->super_CBeam).super_CBaseEntity.pev)->pContainingEntity,&local_54);
    fVar7 = local_54.vecEndPos.z - vecSrc->z;
    fVar1 = local_54.vecEndPos.y - vecSrc->y;
    fVar8 = local_54.vecEndPos.x - vecSrc->x;
    fVar7 = fVar7 * fVar7 + fVar1 * fVar1 + fVar8 * fVar8;
    fVar8 = SQRT(fVar7);
    if (NAN(fVar8)) {
      fVar8 = sqrtf(fVar7);
    }
    if ((this->m_radius * 0.1 <= fVar8) && (local_54.flFraction != 1.0)) break;
    local_74 = local_74 + -1;
    if (local_74 == 0) {
      return;
    }
  }
  Zap(this,vecSrc,&local_54.vecEndPos);
  return;
}


// CLightning::BeamUpdateVars  @ 0008fff0  (line 879)

/* DWARF original prototype: void BeamUpdateVars(CLightning * this) */

void __thiscall CLightning::BeamUpdateVars(CLightning *this)

{
  int *piVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  edict_t *peVar4;
  char *pcVar5;
  uint uVar6;
  edict_t *peVar7;
  void *pvVar8;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  char *pcVar12;
  byte *pbVar13;
  char *pcVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  byte bVar20;
  
                    /* Unresolved local var: int beamType@[???]
                       Unresolved local var: int pointStart@[???]
                       Unresolved local var: int pointEnd@[???]
                       Unresolved local var: edict_t * pStart@[???]
                       Unresolved local var: edict_t * pEnd@[???] */
  bVar20 = 0;
  peVar3 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_iszStartEntity);
  peVar4 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_iszEndEntity);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  peVar7 = peVar3;
  if ((peVar3 == (edict_t *)0x0) &&
     (peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar7 == (edict_t *)0x0)) {
    pvVar8 = (void *)0x0;
  }
  else {
    pvVar8 = peVar7->pvPrivateData;
  }
  bVar19 = true;
  if ((*(int **)((int)pvVar8 + 4))[0x2d] != 0) {
    iVar9 = 0xc;
    pcVar5 = gpGlobals->pStringBase + **(int **)((int)pvVar8 + 4);
    bVar17 = pcVar5 == (char *)0x0;
    pcVar12 = pcVar5;
    pcVar14 = "info_target";
    do {
      if (iVar9 == 0) break;
      iVar9 = iVar9 + -1;
      bVar17 = *pcVar12 == *pcVar14;
      pcVar12 = pcVar12 + (uint)bVar20 * -2 + 1;
      pcVar14 = pcVar14 + (uint)bVar20 * -2 + 1;
    } while (bVar17);
    if (!bVar17) {
      iVar9 = 0xe;
      pcVar12 = pcVar5;
      pcVar14 = "info_landmark";
      do {
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        bVar17 = *pcVar12 == *pcVar14;
        pcVar12 = pcVar12 + (uint)bVar20 * -2 + 1;
        pcVar14 = pcVar14 + (uint)bVar20 * -2 + 1;
      } while (bVar17);
      if (!bVar17) {
        iVar9 = 0xc;
        pcVar12 = "path_corner";
        bVar19 = bVar17;
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          bVar19 = *pcVar5 == *pcVar12;
          pcVar5 = pcVar5 + (uint)bVar20 * -2 + 1;
          pcVar12 = pcVar12 + (uint)bVar20 * -2 + 1;
        } while (bVar19);
      }
    }
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  peVar7 = peVar4;
  if ((peVar4 == (edict_t *)0x0) &&
     (peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar7 == (edict_t *)0x0)) {
    pvVar8 = (void *)0x0;
  }
  else {
    pvVar8 = peVar7->pvPrivateData;
  }
  bVar17 = true;
  uVar6 = 0;
  if ((*(uint **)((int)pvVar8 + 4))[0x2d] != 0) {
    uVar6 = **(uint **)((int)pvVar8 + 4);
    bVar15 = CARRY4(uVar6,(uint)gpGlobals->pStringBase);
    pbVar10 = (byte *)(gpGlobals->pStringBase + uVar6);
    bVar18 = pbVar10 == (byte *)0x0;
    iVar9 = 0xc;
    pbVar11 = pbVar10;
    pbVar13 = (byte *)"info_target";
    do {
      if (iVar9 == 0) break;
      iVar9 = iVar9 + -1;
      bVar15 = *pbVar11 < *pbVar13;
      bVar18 = *pbVar11 == *pbVar13;
      pbVar11 = pbVar11 + (uint)bVar20 * -2 + 1;
      pbVar13 = pbVar13 + (uint)bVar20 * -2 + 1;
    } while (bVar18);
    bVar16 = false;
    bVar15 = (!bVar15 && !bVar18) == bVar15;
    uVar6 = 0;
    if (!bVar15) {
      iVar9 = 0xe;
      pbVar11 = pbVar10;
      pbVar13 = (byte *)"info_landmark";
      do {
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        bVar16 = *pbVar11 < *pbVar13;
        bVar15 = *pbVar11 == *pbVar13;
        pbVar11 = pbVar11 + (uint)bVar20 * -2 + 1;
        pbVar13 = pbVar13 + (uint)bVar20 * -2 + 1;
      } while (bVar15);
      bVar18 = false;
      bVar15 = (!bVar16 && !bVar15) == bVar16;
      uVar6 = 0;
      if (!bVar15) {
        iVar9 = 0xc;
        pbVar11 = (byte *)"path_corner";
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          bVar18 = *pbVar10 < *pbVar11;
          bVar15 = *pbVar10 == *pbVar11;
          pbVar10 = pbVar10 + (uint)bVar20 * -2 + 1;
          pbVar11 = pbVar11 + (uint)bVar20 * -2 + 1;
        } while (bVar15);
        uVar6 = 0;
        if ((!bVar18 && !bVar15) != bVar18) {
          uVar6 = 1;
          bVar17 = false;
        }
      }
    }
  }
  ((this->super_CBeam).super_CBaseEntity.pev)->skin = 0;
  ((this->super_CBeam).super_CBaseEntity.pev)->sequence = 0;
  ((this->super_CBeam).super_CBaseEntity.pev)->rendermode = 0;
  piVar1 = &((this->super_CBeam).super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 | 0x20000000;
  ((this->super_CBeam).super_CBaseEntity.pev)->model = this->m_iszSpriteName;
  ((this->super_CBeam).super_CBaseEntity.pev)->modelindex = this->m_spriteTexture;
  if (bVar19 || bVar17) {
    peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
    if (bVar19) {
      peVar2->rendermode = uVar6 | peVar2->rendermode & 0xf0U;
      peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
      (peVar2->origin).x = (peVar3->v).origin.x;
      (peVar2->origin).y = (peVar3->v).origin.y;
      (peVar2->origin).z = (peVar3->v).origin.z;
      if (bVar17) {
        peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
        (peVar2->angles).x = (peVar4->v).origin.x;
        (peVar2->angles).y = (peVar4->v).origin.y;
        (peVar2->angles).z = (peVar4->v).origin.z;
        goto LAB_00090235;
      }
    }
    else {
      peVar2->rendermode = peVar2->rendermode & 0xf0U | 1;
      peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
      (peVar2->origin).x = (peVar4->v).origin.x;
      (peVar2->origin).y = (peVar4->v).origin.y;
      (peVar2->origin).z = (peVar4->v).origin.z;
      peVar4 = peVar3;
    }
  }
  else {
    peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
    peVar2->rendermode = peVar2->rendermode & 0xf0U | 2;
    uVar6 = (*g_engfuncs.pfnIndexOfEdict)(peVar3);
    peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
    peVar2->sequence = (peVar2->sequence & 0xf000U) << 0xc | uVar6 & 0xfff;
    peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
    peVar7 = (*g_engfuncs.pfnPEntityOfEntIndex)(uVar6);
    peVar2->owner = peVar7;
  }
  uVar6 = (*g_engfuncs.pfnIndexOfEdict)(peVar4);
  peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
  peVar2->skin = (peVar2->skin & 0xf000U) << 0xc | uVar6 & 0xfff;
  peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
  peVar7 = (*g_engfuncs.pfnPEntityOfEntIndex)(uVar6);
  peVar2->aiment = peVar7;
LAB_00090235:
  CBeam::RelinkBeam(&this->super_CBeam);
  ((this->super_CBeam).super_CBaseEntity.pev)->scale = (float)this->m_boltWidth;
  ((this->super_CBeam).super_CBaseEntity.pev)->body = this->m_noiseAmplitude;
  ((this->super_CBeam).super_CBaseEntity.pev)->frame = (float)this->m_frameStart;
  ((this->super_CBeam).super_CBaseEntity.pev)->animtime = (float)this->m_speed;
  peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
  if ((peVar2->spawnflags & 0x80U) != 0) {
    peVar2->rendermode = peVar2->rendermode & 0xfU | 0x40;
    return;
  }
  if ((peVar2->spawnflags & 0x100U) != 0) {
    peVar2->rendermode = peVar2->rendermode & 0xfU | 0x80;
  }
  return;
}


// env_laser  @ 00090460  (line 943)

void env_laser(entvars_t *pev)

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
  *puVar1 = &PTR__CLaser_0014c740;
  puVar1[1] = pev;
  return;
}


// CLaser::Restore  @ 0008c160  (line 952)

/* DWARF original prototype: int Restore(CLaser * this, CRestore * restore) */

int __thiscall CLaser::Restore(CLaser *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore((CBaseEntity *)this,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CLaser",this,m_SaveData,3);
  }
  return iVar2;
}


// CLaser::Save  @ 0008c340  (line 952)

/* DWARF original prototype: int Save(CLaser * this, CSave * save) */

int __thiscall CLaser::Save(CLaser *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save((CBaseEntity *)this,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CLaser",this,m_SaveData,3);
  }
  return iVar2;
}


// CLaser::Spawn  @ 00091160  (line 955)

/* DWARF original prototype: void Spawn(CLaser * this) */

void __thiscall CLaser::Spawn(CLaser *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  _func_int_varargs *p_Var6;
  entvars_t *peVar7;
  int iVar8;
  CSprite *pCVar9;
  entvars_t *peVar10;
  _2globalvars_t *p1Var11;
  
  peVar10 = (this->super_CBeam).super_CBaseEntity.pev;
  if (peVar10->model == 0) {
    (this->super_CBeam).super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (this->super_CBeam).super_CBaseEntity.m_pfnThink.__delta = 0;
  }
  else {
    peVar10->solid = 0;
    p_Var6 = (this->super_CBeam).super_CBaseEntity._vptr_CBaseEntity[3];
    if (p_Var6 == Precache) {
      peVar10 = (this->super_CBeam).super_CBaseEntity.pev;
      iVar8 = (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + peVar10->model);
      peVar10->modelindex = iVar8;
      if (this->m_iszSpriteName != 0) {
        (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + this->m_iszSpriteName);
      }
    }
    else {
      (*p_Var6)(this);
    }
    peVar10 = (this->super_CBeam).super_CBaseEntity.pev;
    (this->super_CBeam).super_CBaseEntity.m_pfnThink.__pfn = StrikeThink;
    (this->super_CBeam).super_CBaseEntity.m_pfnThink.__delta = 0;
    piVar1 = &peVar10->flags;
    *piVar1 = *piVar1 | 0x20000000;
    peVar10 = (this->super_CBeam).super_CBaseEntity.pev;
    peVar10->rendermode = peVar10->rendermode & 0xf0;
    peVar7 = (this->super_CBeam).super_CBaseEntity.pev;
    (peVar7->origin).x = (peVar10->origin).x;
    (peVar7->origin).y = (peVar10->origin).y;
    (peVar7->origin).z = (peVar10->origin).z;
    peVar7 = (this->super_CBeam).super_CBaseEntity.pev;
    (peVar7->angles).x = (peVar10->origin).x;
    (peVar7->angles).y = (peVar10->origin).y;
    (peVar7->angles).z = (peVar10->origin).z;
    piVar1 = &((this->super_CBeam).super_CBaseEntity.pev)->sequence;
    *piVar1 = *piVar1 & 0xfff;
    piVar1 = &((this->super_CBeam).super_CBaseEntity.pev)->skin;
    *piVar1 = *piVar1 & 0xfff;
    CBeam::RelinkBeam(&this->super_CBeam);
    if ((this->m_pSprite == (CSprite *)0x0) && (this->m_iszSpriteName != 0)) {
      pCVar9 = CSprite::SpriteCreate
                         (gpGlobals->pStringBase + this->m_iszSpriteName,
                          &((this->super_CBeam).super_CBaseEntity.pev)->origin,1);
      this->m_pSprite = pCVar9;
      if (pCVar9 != (CSprite *)0x0) {
        peVar10 = (this->super_CBeam).super_CBaseEntity.pev;
        fVar2 = peVar10->renderamt;
        iVar8 = peVar10->renderfx;
        fVar3 = (peVar10->rendercolor).z;
        fVar4 = (peVar10->rendercolor).y;
        fVar5 = (peVar10->rendercolor).x;
        ((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->rendermode = 3;
        (((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).x = (float)(int)fVar5;
        (((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).y = (float)(int)fVar4;
        (((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).z = (float)(int)fVar3;
        ((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->renderamt = (float)(int)fVar2;
        ((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->renderfx = iVar8;
      }
    }
    else {
      this->m_pSprite = (CSprite *)0x0;
    }
    peVar10 = (this->super_CBeam).super_CBaseEntity.pev;
    if ((peVar10->targetname == 0) || ((peVar10->spawnflags & 1) != 0)) {
      peVar10->effects = peVar10->effects & 0xffffff7f;
      pCVar9 = this->m_pSprite;
      p1Var11 = gpGlobals;
      if (pCVar9 != (CSprite *)0x0) {
        ((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
        p1Var11 = gpGlobals;
        peVar10 = (pCVar9->super_CPointEntity).super_CBaseEntity.pev;
        if (((peVar10->framerate != 0.0) && (1.0 < pCVar9->m_maxFrame)) ||
           ((peVar10->spawnflags & 2) != 0)) {
          (pCVar9->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = CSprite::AnimateThink;
          (pCVar9->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
          peVar10->nextthink = p1Var11->time;
          peVar10 = (pCVar9->super_CPointEntity).super_CBaseEntity.pev;
          pCVar9->m_lastTime = p1Var11->time;
        }
        peVar10->frame = 0.0;
      }
      ((this->super_CBeam).super_CBaseEntity.pev)->dmgtime = p1Var11->time;
      ((this->super_CBeam).super_CBaseEntity.pev)->nextthink = p1Var11->time;
      return;
    }
    peVar10->effects = peVar10->effects | 0x80;
    ((this->super_CBeam).super_CBaseEntity.pev)->nextthink = 0.0;
    pCVar9 = this->m_pSprite;
    if (pCVar9 != (CSprite *)0x0) {
      ((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->effects = 0x80;
      ((pCVar9->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
      return;
    }
  }
  return;
}


// CLaser::Precache  @ 0008a480  (line 984)

/* DWARF original prototype: void Precache(CLaser * this) */

void __thiscall CLaser::Precache(CLaser *this)

{
  entvars_t *peVar1;
  int iVar2;
  
  peVar1 = (this->super_CBeam).super_CBaseEntity.pev;
  iVar2 = (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + peVar1->model);
  peVar1->modelindex = iVar2;
  if (this->m_iszSpriteName == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0008a4ed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + this->m_iszSpriteName);
  return;
}


// CLaser::KeyValue  @ 0008af70  (line 992)

/* DWARF original prototype: void KeyValue(CLaser * this, KeyValueData * pkvd) */

void __thiscall CLaser::KeyValue(CLaser *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  long lVar2;
  string_t sVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  double dVar9;
  
  bVar8 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar4 = 0xc;
  pcVar6 = pkvd->szKeyName;
  pcVar5 = pcVar6;
  pcVar7 = "LaserTarget";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar5 == *pcVar7;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar8);
  if (bVar8) {
    peVar1 = (this->super_CBeam).super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    peVar1->message = sVar3;
    pkvd->fHandled = 1;
  }
  else {
    iVar4 = 6;
    bVar8 = false;
    pcVar5 = pcVar6;
    pcVar7 = "width";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar8 = *pcVar5 == *pcVar7;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar8);
    if (bVar8) {
      dVar9 = strtod(pkvd->szValue,(char **)0x0);
      ((this->super_CBeam).super_CBaseEntity.pev)->scale = (float)(int)dVar9;
      pkvd->fHandled = 1;
    }
    else {
      iVar4 = 0xf;
      bVar8 = false;
      pcVar5 = pcVar6;
      pcVar7 = "NoiseAmplitude";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar8 = *pcVar5 == *pcVar7;
        pcVar5 = pcVar5 + 1;
        pcVar7 = pcVar7 + 1;
      } while (bVar8);
      if (bVar8) {
        lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
        ((this->super_CBeam).super_CBaseEntity.pev)->body = lVar2;
        pkvd->fHandled = 1;
      }
      else {
        iVar4 = 0xe;
        bVar8 = false;
        pcVar5 = pcVar6;
        pcVar7 = "TextureScroll";
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar8 = *pcVar5 == *pcVar7;
          pcVar5 = pcVar5 + 1;
          pcVar7 = pcVar7 + 1;
        } while (bVar8);
        if (bVar8) {
          lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
          ((this->super_CBeam).super_CBaseEntity.pev)->animtime = (float)lVar2;
          pkvd->fHandled = 1;
        }
        else {
          iVar4 = 8;
          bVar8 = false;
          pcVar5 = pcVar6;
          pcVar7 = "texture";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar8 = *pcVar5 == *pcVar7;
            pcVar5 = pcVar5 + 1;
            pcVar7 = pcVar7 + 1;
          } while (bVar8);
          if (bVar8) {
            peVar1 = (this->super_CBeam).super_CBaseEntity.pev;
            sVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
            peVar1->model = sVar3;
            pkvd->fHandled = 1;
          }
          else {
            iVar4 = 10;
            bVar8 = false;
            pcVar5 = pcVar6;
            pcVar7 = "EndSprite";
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar8 = *pcVar5 == *pcVar7;
              pcVar5 = pcVar5 + 1;
              pcVar7 = pcVar7 + 1;
            } while (bVar8);
            if (bVar8) {
              iVar4 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
              this->m_iszSpriteName = iVar4;
              pkvd->fHandled = 1;
            }
            else {
              iVar4 = 0xb;
              bVar8 = false;
              pcVar5 = pcVar6;
              pcVar7 = "framestart";
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar8 = *pcVar5 == *pcVar7;
                pcVar5 = pcVar5 + 1;
                pcVar7 = pcVar7 + 1;
              } while (bVar8);
              if (bVar8) {
                peVar1 = (this->super_CBeam).super_CBaseEntity.pev;
                lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
                peVar1->frame = (float)lVar2;
                pkvd->fHandled = 1;
              }
              else {
                iVar4 = 7;
                bVar8 = false;
                pcVar5 = "damage";
                do {
                  if (iVar4 == 0) break;
                  iVar4 = iVar4 + -1;
                  bVar8 = *pcVar6 == *pcVar5;
                  pcVar6 = pcVar6 + 1;
                  pcVar5 = pcVar5 + 1;
                } while (bVar8);
                if (!bVar8) {
                  CBaseEntity::KeyValue((CBaseEntity *)this,pkvd);
                  return;
                }
                peVar1 = (this->super_CBeam).super_CBaseEntity.pev;
                dVar9 = strtod(pkvd->szValue,(char **)0x0);
                peVar1->dmg = (float)dVar9;
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


// CLaser::IsOn  @ 000904d0  (line 1040)

/* DWARF original prototype: int IsOn(CLaser * this) */

int __thiscall CLaser::IsOn(CLaser *this)

{
  return (uint)((((this->super_CBeam).super_CBaseEntity.pev)->effects & 0x80) == 0);
}


// CLaser::TurnOff  @ 000904f0  (line 1047)

/* DWARF original prototype: void TurnOff(CLaser * this) */

void __thiscall CLaser::TurnOff(CLaser *this)

{
  int *piVar1;
  CSprite *pCVar2;
  
  piVar1 = &((this->super_CBeam).super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  ((this->super_CBeam).super_CBaseEntity.pev)->nextthink = 0.0;
  pCVar2 = this->m_pSprite;
  if (pCVar2 != (CSprite *)0x0) {
    ((pCVar2->super_CPointEntity).super_CBaseEntity.pev)->effects = 0x80;
    ((pCVar2->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
  }
  return;
}


// CLaser::TurnOn  @ 00090540  (line 1056)

/* DWARF original prototype: void TurnOn(CLaser * this) */

void __thiscall CLaser::TurnOn(CLaser *this)

{
  int *piVar1;
  CSprite *pCVar2;
  _2globalvars_t *p1Var3;
  entvars_t *peVar4;
  
  p1Var3 = gpGlobals;
  piVar1 = &((this->super_CBeam).super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 & 0xffffff7f;
  pCVar2 = this->m_pSprite;
  if (pCVar2 != (CSprite *)0x0) {
    ((pCVar2->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
    p1Var3 = gpGlobals;
    peVar4 = (pCVar2->super_CPointEntity).super_CBaseEntity.pev;
    if (((peVar4->framerate != 0.0) && (1.0 < pCVar2->m_maxFrame)) ||
       ((peVar4->spawnflags & 2) != 0)) {
      (pCVar2->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = CSprite::AnimateThink;
      (pCVar2->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
      peVar4->nextthink = p1Var3->time;
      peVar4 = (pCVar2->super_CPointEntity).super_CBaseEntity.pev;
      pCVar2->m_lastTime = p1Var3->time;
    }
    peVar4->frame = 0.0;
  }
  ((this->super_CBeam).super_CBaseEntity.pev)->dmgtime = p1Var3->time;
  ((this->super_CBeam).super_CBaseEntity.pev)->nextthink = p1Var3->time;
  return;
}


// CLaser::Use  @ 0008d4e0  (line 1066)

/* DWARF original prototype: void Use(CLaser * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CLaser::Use(CLaser *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,float value)

{
  int *piVar1;
  CSprite *pCVar2;
  int iVar3;
  entvars_t *peVar4;
  _2globalvars_t *p1Var5;
  
                    /* Unresolved local var: int active@[???] */
  if ((((this->super_CBeam).super_CBaseEntity.pev)->effects & 0x80) == 0) {
    iVar3 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,1);
    if (iVar3 != 0) {
                    /* Unresolved local var: int active@[???] */
      piVar1 = &((this->super_CBeam).super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 | 0x80;
      ((this->super_CBeam).super_CBaseEntity.pev)->nextthink = 0.0;
      pCVar2 = this->m_pSprite;
      if (pCVar2 != (CSprite *)0x0) {
        ((pCVar2->super_CPointEntity).super_CBaseEntity.pev)->effects = 0x80;
        ((pCVar2->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
        return;
      }
    }
  }
  else {
    iVar3 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,0);
    p1Var5 = gpGlobals;
    if (iVar3 != 0) {
      piVar1 = &((this->super_CBeam).super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 & 0xffffff7f;
      pCVar2 = this->m_pSprite;
      if (pCVar2 != (CSprite *)0x0) {
        ((pCVar2->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
        p1Var5 = gpGlobals;
        peVar4 = (pCVar2->super_CPointEntity).super_CBaseEntity.pev;
        if (((peVar4->framerate != 0.0) && (1.0 < pCVar2->m_maxFrame)) ||
           ((peVar4->spawnflags & 2) != 0)) {
          (pCVar2->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = CSprite::AnimateThink;
          (pCVar2->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
          peVar4->nextthink = p1Var5->time;
          peVar4 = (pCVar2->super_CPointEntity).super_CBaseEntity.pev;
          pCVar2->m_lastTime = p1Var5->time;
        }
        peVar4->frame = 0.0;
      }
      ((this->super_CBeam).super_CBaseEntity.pev)->dmgtime = p1Var5->time;
      ((this->super_CBeam).super_CBaseEntity.pev)->nextthink = p1Var5->time;
      return;
    }
  }
  return;
}


// CLaser::FireAtPoint  @ 00090610  (line 1083)

/* DWARF original prototype: void FireAtPoint(CLaser * this, TraceResult * tr) */

void __thiscall CLaser::FireAtPoint(CLaser *this,TraceResult *tr)

{
  int *piVar1;
  code *pcVar2;
  float fVar3;
  float __x;
  entvars_t *peVar4;
  uint uVar5;
  entvars_t *peVar6;
  int32 iVar7;
  edict_t *peVar8;
  float local_28;
  float local_24;
  float local_20;
  
  peVar6 = (this->super_CBeam).super_CBaseEntity.pev;
  (peVar6->angles).x = (tr->vecEndPos).x;
  (peVar6->angles).y = (tr->vecEndPos).y;
  (peVar6->angles).z = (tr->vecEndPos).z;
  if (this->m_pSprite != (CSprite *)0x0) {
    UTIL_SetOrigin((this->m_pSprite->super_CPointEntity).super_CBaseEntity.pev,&tr->vecEndPos);
  }
  CBeam::RelinkBeam(&this->super_CBeam);
                    /* Unresolved local var: CBaseEntity * pHit@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((tr->flFraction != 1.0) && (tr->pHit != (edict_t *)0x0)) &&
     (piVar1 = tr->pHit->pvPrivateData, piVar1 != (int *)0x0)) {
    ClearMultiDamage();
    pcVar2 = *(code **)(*piVar1 + 0x30);
    peVar6 = (this->super_CBeam).super_CBaseEntity.pev;
    fVar3 = (tr->vecEndPos).z - (peVar6->origin).z;
    local_24 = (tr->vecEndPos).y - (peVar6->origin).y;
    local_28 = (tr->vecEndPos).x - (peVar6->origin).x;
                    /* Unresolved local var: float flLen@[???] */
    __x = fVar3 * fVar3 + local_24 * local_24 + local_28 * local_28;
    local_20 = SQRT(__x);
    if (NAN(local_20)) {
      local_20 = sqrtf(__x);
      peVar6 = (this->super_CBeam).super_CBaseEntity.pev;
    }
    if (local_20 == 0.0) {
      local_28 = 0.0;
      local_24 = 0.0;
      local_20 = 1.0;
    }
    else {
      local_20 = 1.0 / local_20;
      local_28 = local_28 * local_20;
      local_24 = local_24 * local_20;
      local_20 = local_20 * fVar3;
    }
    (*pcVar2)(piVar1,peVar6,(gpGlobals->time - peVar6->dmgtime) * peVar6->dmg,&local_28,tr,0x400);
    peVar6 = (this->super_CBeam).super_CBaseEntity.pev;
    ApplyMultiDamage(peVar6,peVar6);
    peVar6 = (this->super_CBeam).super_CBaseEntity.pev;
    if ((peVar6->spawnflags & 0x40) == 0) goto LAB_00090783;
    if (*(code **)(*piVar1 + 0x8c) == CBaseEntity::IsBSPModel) {
      if (*(int *)(piVar1[1] + 0x10c) != 4) {
        uVar5 = (uint)(*(int *)(piVar1[1] + 0x108) == 0xd);
        goto LAB_0009076d;
      }
    }
    else {
      uVar5 = (**(code **)(*piVar1 + 0x8c))(piVar1);
LAB_0009076d:
      if (uVar5 == 0) goto LAB_00090780;
    }
    iVar7 = (*g_engfuncs.pfnRandomLong)(0,4);
    UTIL_DecalTrace(tr,iVar7 + 0x1c);
  }
LAB_00090780:
  peVar6 = (this->super_CBeam).super_CBaseEntity.pev;
LAB_00090783:
  peVar6->dmgtime = gpGlobals->time;
  peVar6 = (this->super_CBeam).super_CBaseEntity.pev;
  peVar4 = peVar6;
  if ((peVar6->rendermode & 0xfU) == 2) {
                    /* Unresolved local var: edict_t * pent@[???] */
    peVar8 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar6->sequence & 0xfff);
    peVar6 = (this->super_CBeam).super_CBaseEntity.pev;
    peVar4 = &peVar8->v;
  }
  uVar5 = peVar6->spawnflags;
  if ((uVar5 & 0x30) != 0) {
    if ((uVar5 & 0x10) != 0) {
      UTIL_Sparks(&peVar4->origin);
      uVar5 = ((this->super_CBeam).super_CBaseEntity.pev)->spawnflags;
    }
    if ((uVar5 & 0x20) != 0) {
      UTIL_Sparks(&tr->vecEndPos);
      return;
    }
  }
  return;
}


// CLaser::StrikeThink  @ 000908d0  (line 1093)

/* DWARF original prototype: void StrikeThink(CLaser * this) */

void __thiscall CLaser::StrikeThink(CLaser *this)

{
  int iVar1;
  string_t sVar2;
  char *pcVar3;
  entvars_t *peVar4;
  int32 iVar5;
  CBaseEntity *pCVar6;
  int iVar7;
  CBaseEntity *pStartEntity;
  TraceResult local_54;
  
                    /* Unresolved local var: CBaseEntity * pEnd@[???]
                       Unresolved local var: TraceResult tr@[???] */
                    /* Unresolved local var: int total@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pNewEntity@[???] */
  sVar2 = ((this->super_CBeam).super_CBaseEntity.pev)->message;
  pcVar3 = gpGlobals->pStringBase;
  pStartEntity = (CBaseEntity *)0x0;
  pCVar6 = (CBaseEntity *)0x0;
  iVar7 = 0;
  while( true ) {
    pStartEntity = UTIL_FindEntityByTargetname(pStartEntity,pcVar3 + sVar2);
    if (pStartEntity == (CBaseEntity *)0x0) break;
    iVar1 = iVar7 + 1;
    iVar5 = (*g_engfuncs.pfnRandomLong)(0,iVar7);
    iVar7 = iVar1;
    if (iVar5 < 1) {
      pCVar6 = pStartEntity;
    }
  }
  if (pCVar6 != (CBaseEntity *)0x0) {
    peVar4 = pCVar6->pev;
    (this->m_firePosition).x = (peVar4->origin).x;
    (this->m_firePosition).y = (peVar4->origin).y;
    (this->m_firePosition).z = (peVar4->origin).z;
  }
  UTIL_TraceLine(&((this->super_CBeam).super_CBaseEntity.pev)->origin,&this->m_firePosition,
                 dont_ignore_monsters,(edict_t *)0x0,&local_54);
  FireAtPoint(this,&local_54);
  ((this->super_CBeam).super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  return;
}


// CGlow::~CGlow  @ 000920b0  (line 1108)

/* DWARF original prototype: void ~CGlow(CGlow * this, int __in_chrg) */

void __thiscall CGlow::~CGlow(CGlow *this,int __in_chrg)

{
  return;
}


// env_glow  @ 000909d0  (line 1122)

void env_glow(entvars_t *pev)

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
  *puVar1 = &PTR__CGlow_0014c84c;
  puVar1[1] = pev;
  return;
}


// CGlow::Restore  @ 0008c100  (line 1130)

/* DWARF original prototype: int Restore(CGlow * this, CRestore * restore) */

int __thiscall CGlow::Restore(CGlow *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore((CBaseEntity *)this,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CGlow",this,m_SaveData,2);
  }
  return iVar2;
}


// CGlow::Save  @ 0008c2e0  (line 1130)

/* DWARF original prototype: int Save(CGlow * this, CSave * save) */

int __thiscall CGlow::Save(CGlow *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save((CBaseEntity *)this,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CGlow",this,m_SaveData,2);
  }
  return iVar2;
}


// CGlow::Spawn  @ 0008a500  (line 1133)

/* DWARF original prototype: void Spawn(CGlow * this) */

void __thiscall CGlow::Spawn(CGlow *this)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  int iVar3;
  
  ((this->super_CPointEntity).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
  p1Var2 = gpGlobals;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->frame = 0.0;
  (*g_engfuncs.pfnPrecacheModel)
            (p1Var2->pStringBase + ((this->super_CPointEntity).super_CBaseEntity.pev)->model);
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar1->pContainingEntity,gpGlobals->pStringBase + peVar1->model);
  iVar3 = (*g_engfuncs.pfnModelFrames)
                    (((this->super_CPointEntity).super_CBaseEntity.pev)->modelindex);
  this->m_maxFrame = (float)iVar3 - 1.0;
  p1Var2 = gpGlobals;
  if ((1.0 < (float)iVar3 - 1.0) &&
     (peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev, peVar1->framerate != 0.0)) {
    peVar1->nextthink = gpGlobals->time + 0.1;
  }
  this->m_lastTime = p1Var2->time;
  return;
}


// CGlow::Think  @ 0008c7e0  (line 1151)

/* DWARF original prototype: void Think(CGlow * this) */

void __thiscall CGlow::Think(CGlow *this)

{
  float fVar1;
  _2globalvars_t *p1Var2;
  entvars_t *peVar3;
  double dVar4;
  
  fVar1 = gpGlobals->time;
  peVar3 = (this->super_CPointEntity).super_CBaseEntity.pev;
  p1Var2 = gpGlobals;
  if (0.0 < this->m_maxFrame) {
    dVar4 = fmod((double)((fVar1 - this->m_lastTime) * peVar3->framerate + peVar3->frame),
                 (double)this->m_maxFrame);
    p1Var2 = gpGlobals;
    peVar3->frame = (float)dVar4;
    peVar3 = (this->super_CPointEntity).super_CBaseEntity.pev;
    fVar1 = p1Var2->time;
  }
  peVar3->nextthink = fVar1 + 0.1;
  this->m_lastTime = p1Var2->time;
  return;
}


// CGlow::Animate  @ 00090a40  (line 1160)

/* DWARF original prototype: void Animate(CGlow * this, float frames) */

void __thiscall CGlow::Animate(CGlow *this,float frames)

{
  entvars_t *peVar1;
  double dVar2;
  
  if (0.0 < this->m_maxFrame) {
    peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
    dVar2 = fmod((double)(frames + peVar1->frame),(double)this->m_maxFrame);
    peVar1->frame = (float)dVar2;
  }
  return;
}


// env_sprite  @ 00090a90  (line 1166)

void env_sprite(entvars_t *pev)

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
  *puVar1 = &PTR__CSprite_0014c958;
  puVar1[1] = pev;
  return;
}


// CSprite::Restore  @ 0008c0a0  (line 1174)

/* DWARF original prototype: int Restore(CSprite * this, CRestore * restore) */

int __thiscall CSprite::Restore(CSprite *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore((CBaseEntity *)this,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CSprite",this,m_SaveData,2);
  }
  return iVar2;
}


// CSprite::Save  @ 0008c280  (line 1174)

/* DWARF original prototype: int Save(CSprite * this, CSave * save) */

int __thiscall CSprite::Save(CSprite *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save((CBaseEntity *)this,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CSprite",this,m_SaveData,2);
  }
  return iVar2;
}


// CSprite::Spawn  @ 0008d2b0  (line 1177)

/* DWARF original prototype: void Spawn(CSprite * this) */

void __thiscall CSprite::Spawn(CSprite *this)

{
  float fVar1;
  _func_int_varargs *p_Var2;
  edict_t *peVar3;
  _2globalvars_t *p1Var4;
  int iVar5;
  int iVar6;
  entvars_t *peVar7;
  
  ((this->super_CPointEntity).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->frame = 0.0;
  p_Var2 = (this->super_CPointEntity).super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var2 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)
              (gpGlobals->pStringBase + ((this->super_CPointEntity).super_CBaseEntity.pev)->model);
    peVar7 = (this->super_CPointEntity).super_CBaseEntity.pev;
    peVar3 = peVar7->aiment;
    if (peVar3 == (edict_t *)0x0) {
      peVar7->skin = 0;
      ((this->super_CPointEntity).super_CBaseEntity.pev)->body = 0;
    }
    else {
      iVar6 = peVar7->body;
      iVar5 = (*g_engfuncs.pfnIndexOfEdict)(peVar3);
      peVar7->skin = iVar5;
      ((this->super_CPointEntity).super_CBaseEntity.pev)->body = iVar6;
      ((this->super_CPointEntity).super_CBaseEntity.pev)->aiment = peVar3;
      ((this->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0xc;
    }
  }
  else {
    (*p_Var2)(this);
  }
  peVar7 = (this->super_CPointEntity).super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar7->pContainingEntity,gpGlobals->pStringBase + peVar7->model);
  iVar6 = (*g_engfuncs.pfnModelFrames)
                    (((this->super_CPointEntity).super_CBaseEntity.pev)->modelindex);
  peVar7 = (this->super_CPointEntity).super_CBaseEntity.pev;
  this->m_maxFrame = (float)iVar6 - 1.0;
  if ((peVar7->targetname == 0) || ((peVar7->spawnflags & 1) != 0)) {
    peVar7->effects = 0;
    p1Var4 = gpGlobals;
    peVar7 = (this->super_CPointEntity).super_CBaseEntity.pev;
    if (((peVar7->framerate != 0.0) && (1.0 < this->m_maxFrame)) || ((peVar7->spawnflags & 2) != 0))
    {
      (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = AnimateThink;
      (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
      peVar7->nextthink = p1Var4->time;
      peVar7 = (this->super_CPointEntity).super_CBaseEntity.pev;
      this->m_lastTime = p1Var4->time;
    }
    peVar7->frame = 0.0;
  }
  else {
    peVar7->effects = 0x80;
    ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
  }
  peVar7 = (this->super_CPointEntity).super_CBaseEntity.pev;
  fVar1 = (peVar7->angles).y;
  if ((fVar1 != 0.0) && ((peVar7->angles).z == 0.0)) {
    (peVar7->angles).z = fVar1;
    (((this->super_CPointEntity).super_CBaseEntity.pev)->angles).y = 0.0;
  }
  return;
}


// CSprite::Precache  @ 0008a5f0  (line 1202)

/* DWARF original prototype: void Precache(CSprite * this) */

void __thiscall CSprite::Precache(CSprite *this)

{
  entvars_t *peVar1;
  edict_t *peVar2;
  int iVar3;
  int iVar4;
  
  (*g_engfuncs.pfnPrecacheModel)
            (gpGlobals->pStringBase + ((this->super_CPointEntity).super_CBaseEntity.pev)->model);
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  peVar2 = peVar1->aiment;
  if (peVar2 == (edict_t *)0x0) {
    peVar1->skin = 0;
    ((this->super_CPointEntity).super_CBaseEntity.pev)->body = 0;
  }
  else {
    iVar3 = peVar1->body;
    iVar4 = (*g_engfuncs.pfnIndexOfEdict)(peVar2);
    peVar1->skin = iVar4;
    ((this->super_CPointEntity).super_CBaseEntity.pev)->body = iVar3;
    ((this->super_CPointEntity).super_CBaseEntity.pev)->aiment = peVar2;
    ((this->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0xc;
  }
  return;
}


// CSprite::SpriteInit  @ 00090b00  (line 1218)

/* DWARF original prototype: void SpriteInit(CSprite * this, char * pSpriteName, Vector * origin) */

void __thiscall CSprite::SpriteInit(CSprite *this,char *pSpriteName,Vector *origin)

{
  float fVar1;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  edict_t *peVar2;
  _2globalvars_t *p1Var3;
  int iVar4;
  int iVar5;
  entvars_t *peVar6;
  
  p1Var3 = gpGlobals;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->model =
       (int)pSpriteName - (int)gpGlobals->pStringBase;
  peVar6 = (this->super_CPointEntity).super_CBaseEntity.pev;
  (peVar6->origin).x = origin->x;
  (peVar6->origin).y = origin->y;
  (peVar6->origin).z = origin->z;
  UNRECOVERED_JUMPTABLE = (this->super_CPointEntity).super_CBaseEntity._vptr_CBaseEntity[2];
  if (UNRECOVERED_JUMPTABLE != Spawn) {
                    /* WARNING: Could not recover jumptable at 0x00090d6b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  ((this->super_CPointEntity).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->frame = 0.0;
  UNRECOVERED_JUMPTABLE = (this->super_CPointEntity).super_CBaseEntity._vptr_CBaseEntity[3];
  if (UNRECOVERED_JUMPTABLE == Precache) {
    (*g_engfuncs.pfnPrecacheModel)
              (p1Var3->pStringBase + ((this->super_CPointEntity).super_CBaseEntity.pev)->model);
    peVar6 = (this->super_CPointEntity).super_CBaseEntity.pev;
    peVar2 = peVar6->aiment;
    if (peVar2 == (edict_t *)0x0) {
      peVar6->skin = 0;
      ((this->super_CPointEntity).super_CBaseEntity.pev)->body = 0;
    }
    else {
      iVar5 = peVar6->body;
      iVar4 = (*g_engfuncs.pfnIndexOfEdict)(peVar2);
      peVar6->skin = iVar4;
      ((this->super_CPointEntity).super_CBaseEntity.pev)->body = iVar5;
      ((this->super_CPointEntity).super_CBaseEntity.pev)->aiment = peVar2;
      ((this->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0xc;
    }
  }
  else {
    (*UNRECOVERED_JUMPTABLE)(this);
  }
  peVar6 = (this->super_CPointEntity).super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar6->pContainingEntity,gpGlobals->pStringBase + peVar6->model);
  iVar5 = (*g_engfuncs.pfnModelFrames)
                    (((this->super_CPointEntity).super_CBaseEntity.pev)->modelindex);
  peVar6 = (this->super_CPointEntity).super_CBaseEntity.pev;
  this->m_maxFrame = (float)iVar5 - 1.0;
  if ((peVar6->targetname == 0) || ((peVar6->spawnflags & 1) != 0)) {
    peVar6->effects = 0;
    p1Var3 = gpGlobals;
    peVar6 = (this->super_CPointEntity).super_CBaseEntity.pev;
    if (((peVar6->framerate != 0.0) && (1.0 < this->m_maxFrame)) || ((peVar6->spawnflags & 2) != 0))
    {
      (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = AnimateThink;
      (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
      peVar6->nextthink = p1Var3->time;
      peVar6 = (this->super_CPointEntity).super_CBaseEntity.pev;
      this->m_lastTime = p1Var3->time;
    }
    peVar6->frame = 0.0;
  }
  else {
    peVar6->effects = 0x80;
    ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
  }
  peVar6 = (this->super_CPointEntity).super_CBaseEntity.pev;
  fVar1 = (peVar6->angles).y;
  if ((fVar1 != 0.0) && ((peVar6->angles).z == 0.0)) {
    (peVar6->angles).z = fVar1;
    (((this->super_CPointEntity).super_CBaseEntity.pev)->angles).y = 0.0;
  }
  return;
}


// CSprite::SpriteCreate  @ 00090da0  (line 1225)

CSprite * CSprite::SpriteCreate(char *pSpriteName,Vector *origin,BOOL animate)

{
  float fVar1;
  _func_int_varargs *p_Var2;
  edict_t *peVar3;
  int iVar4;
  int iVar5;
  entvars_t *peVar6;
  CSprite *pCVar7;
  _2globalvars_t *p1Var8;
  entvars_t *local_20;
  
                    /* Unresolved local var: CSprite * pSprite@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar3 = (*g_engfuncs.pfnCreateEntity)();
  local_20 = (entvars_t *)0x0;
  if (peVar3 != (edict_t *)0x0) {
    local_20 = &peVar3->v;
  }
  if ((local_20->pContainingEntity == (edict_t *)0x0) ||
     (pCVar7 = local_20->pContainingEntity->pvPrivateData, pCVar7 == (CSprite *)0x0)) {
    pCVar7 = CBaseEntity::operator_new(0x47c,local_20);
    (pCVar7->super_CPointEntity).super_CBaseEntity._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CSprite_0014c958;
    (pCVar7->super_CPointEntity).super_CBaseEntity.pev = local_20;
  }
  else {
    local_20 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
  }
  p1Var8 = gpGlobals;
  local_20->model = (int)pSpriteName - (int)gpGlobals->pStringBase;
  peVar6 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
  (peVar6->origin).x = origin->x;
  (peVar6->origin).y = origin->y;
  (peVar6->origin).z = origin->z;
  p_Var2 = (pCVar7->super_CPointEntity).super_CBaseEntity._vptr_CBaseEntity[2];
  if (p_Var2 == Spawn) {
    ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->solid = 0;
    ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0;
    ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
    ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->frame = 0.0;
    p_Var2 = (pCVar7->super_CPointEntity).super_CBaseEntity._vptr_CBaseEntity[3];
    if (p_Var2 == Precache) {
      (*g_engfuncs.pfnPrecacheModel)
                (p1Var8->pStringBase + ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->model);
      peVar6 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
      peVar3 = peVar6->aiment;
      if (peVar3 == (edict_t *)0x0) {
        peVar6->skin = 0;
        ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->body = 0;
      }
      else {
        iVar5 = peVar6->body;
        iVar4 = (*g_engfuncs.pfnIndexOfEdict)(peVar3);
        peVar6->skin = iVar4;
        ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->body = iVar5;
        ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->aiment = peVar3;
        ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0xc;
      }
    }
    else {
      (*p_Var2)(pCVar7);
    }
    peVar6 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
    (*g_engfuncs.pfnSetModel)(peVar6->pContainingEntity,gpGlobals->pStringBase + peVar6->model);
    iVar5 = (*g_engfuncs.pfnModelFrames)
                      (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->modelindex);
    peVar6 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
    pCVar7->m_maxFrame = (float)iVar5 - 1.0;
    p1Var8 = gpGlobals;
    if ((peVar6->targetname == 0) || ((peVar6->spawnflags & 1) != 0)) {
      peVar6->effects = 0;
      p1Var8 = gpGlobals;
      peVar6 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
      if (((peVar6->framerate != 0.0) && (1.0 < pCVar7->m_maxFrame)) ||
         ((peVar6->spawnflags & 2) != 0)) {
        (pCVar7->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = AnimateThink;
        (pCVar7->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
        peVar6->nextthink = p1Var8->time;
        peVar6 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
        pCVar7->m_lastTime = p1Var8->time;
      }
      peVar6->frame = 0.0;
    }
    else {
      peVar6->effects = 0x80;
      ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
    }
    peVar6 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
    fVar1 = (peVar6->angles).y;
    if ((fVar1 != 0.0) && ((peVar6->angles).z == 0.0)) {
      (peVar6->angles).z = fVar1;
      (((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->angles).y = 0.0;
      peVar6 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
    }
  }
  else {
    (*p_Var2)(pCVar7);
    peVar6 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
    p1Var8 = gpGlobals;
  }
  peVar6->classname = (int)"env_sprite" - (int)p1Var8->pStringBase;
  ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->solid = 0;
  ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->movetype = 8;
  if (animate != 0) {
    ((pCVar7->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
    p1Var8 = gpGlobals;
    peVar6 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
    if (((peVar6->framerate != 0.0) && (1.0 < pCVar7->m_maxFrame)) ||
       ((peVar6->spawnflags & 2) != 0)) {
      (pCVar7->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = AnimateThink;
      (pCVar7->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
      peVar6->nextthink = p1Var8->time;
      peVar6 = (pCVar7->super_CPointEntity).super_CBaseEntity.pev;
      pCVar7->m_lastTime = p1Var8->time;
    }
    peVar6->frame = 0.0;
    return pCVar7;
  }
  return pCVar7;
}


// CSprite::AnimateThink  @ 0008cc20  (line 1239)

/* DWARF original prototype: void AnimateThink(CSprite * this) */

void __thiscall CSprite::AnimateThink(CSprite *this)

{
  float fVar1;
  _2globalvars_t *p1Var2;
  entvars_t *peVar3;
  double dVar4;
  
  p1Var2 = gpGlobals;
  peVar3 = (this->super_CPointEntity).super_CBaseEntity.pev;
  peVar3->frame = (gpGlobals->time - this->m_lastTime) * peVar3->framerate + peVar3->frame;
  peVar3 = (this->super_CPointEntity).super_CBaseEntity.pev;
  fVar1 = this->m_maxFrame;
  if (fVar1 < peVar3->frame) {
    if ((peVar3->spawnflags & 2) == 0) {
      if (0.0 < fVar1) {
        dVar4 = fmod((double)peVar3->frame,(double)fVar1);
        p1Var2 = gpGlobals;
        peVar3->frame = (float)dVar4;
        peVar3 = (this->super_CPointEntity).super_CBaseEntity.pev;
      }
    }
    else {
      peVar3->effects = 0x80;
      ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
      peVar3 = (this->super_CPointEntity).super_CBaseEntity.pev;
    }
  }
  peVar3->nextthink = p1Var2->time + 0.1;
  this->m_lastTime = p1Var2->time;
  return;
}


// CSprite::AnimateUntilDead  @ 000914a0  (line 1247)

/* DWARF original prototype: void AnimateUntilDead(CSprite * this) */

void __thiscall CSprite::AnimateUntilDead(CSprite *this)

{
  float fVar1;
  _2globalvars_t *p1Var2;
  entvars_t *peVar3;
  double dVar4;
  
  p1Var2 = gpGlobals;
  peVar3 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if (peVar3->dmgtime < gpGlobals->time) {
    UTIL_Remove((CBaseEntity *)this);
    return;
  }
  peVar3->frame = (gpGlobals->time - this->m_lastTime) * peVar3->framerate + peVar3->frame;
  peVar3 = (this->super_CPointEntity).super_CBaseEntity.pev;
  fVar1 = this->m_maxFrame;
  if (fVar1 < peVar3->frame) {
    if ((peVar3->spawnflags & 2) == 0) {
      if (0.0 < fVar1) {
        dVar4 = fmod((double)peVar3->frame,(double)fVar1);
        p1Var2 = gpGlobals;
        peVar3->frame = (float)dVar4;
        peVar3 = (this->super_CPointEntity).super_CBaseEntity.pev;
      }
    }
    else {
      peVar3->effects = 0x80;
      ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
      peVar3 = (this->super_CPointEntity).super_CBaseEntity.pev;
    }
  }
  peVar3->nextthink = p1Var2->time + 0.1;
  peVar3 = (this->super_CPointEntity).super_CBaseEntity.pev;
  this->m_lastTime = p1Var2->time;
  peVar3->nextthink = p1Var2->time;
  return;
}


// CSprite::Expand  @ 000915a0  (line 1258)

/* DWARF original prototype: void Expand(CSprite * this, float scaleSpeed, float fadeSpeed) */

void __thiscall CSprite::Expand(CSprite *this,float scaleSpeed,float fadeSpeed)

{
  _2globalvars_t *p1Var1;
  
  ((this->super_CPointEntity).super_CBaseEntity.pev)->speed = scaleSpeed;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->health = fadeSpeed;
  p1Var1 = gpGlobals;
  (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = ExpandThink;
  (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = p1Var1->time;
  this->m_lastTime = p1Var1->time;
  return;
}


// CSprite::ExpandThink  @ 0008b310  (line 1269)

/* DWARF original prototype: void ExpandThink(CSprite * this) */

void __thiscall CSprite::ExpandThink(CSprite *this)

{
  entvars_t *peVar1;
  float fVar2;
  _2globalvars_t *p1Var3;
  
                    /* Unresolved local var: float frametime@[???] */
  p1Var3 = gpGlobals;
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  fVar2 = gpGlobals->time - this->m_lastTime;
  peVar1->scale = peVar1->speed * fVar2 + peVar1->scale;
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  peVar1->renderamt = peVar1->renderamt - fVar2 * peVar1->health;
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if (0.0 < peVar1->renderamt) {
    peVar1->nextthink = p1Var3->time + 0.1;
    this->m_lastTime = p1Var3->time;
    return;
  }
  peVar1->renderamt = 0.0;
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CSprite::Animate  @ 00091600  (line 1287)

/* DWARF original prototype: void Animate(CSprite * this, float frames) */

void __thiscall CSprite::Animate(CSprite *this,float frames)

{
  float fVar1;
  entvars_t *peVar2;
  double dVar3;
  
  peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
  peVar2->frame = peVar2->frame + frames;
  peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
  fVar1 = this->m_maxFrame;
  if (fVar1 < peVar2->frame) {
    if ((peVar2->spawnflags & 2) != 0) {
      peVar2->effects = 0x80;
      ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
      return;
    }
    if (0.0 < fVar1) {
      dVar3 = fmod((double)peVar2->frame,(double)fVar1);
      peVar2->frame = (float)dVar3;
    }
  }
  return;
}


// CSprite::TurnOff  @ 000916b0  (line 1305)

/* DWARF original prototype: void TurnOff(CSprite * this) */

void __thiscall CSprite::TurnOff(CSprite *this)

{
  ((this->super_CPointEntity).super_CBaseEntity.pev)->effects = 0x80;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
  return;
}


// CSprite::TurnOn  @ 000916d0  (line 1312)

/* DWARF original prototype: void TurnOn(CSprite * this) */

void __thiscall CSprite::TurnOn(CSprite *this)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  
  ((this->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
  p1Var2 = gpGlobals;
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if (((peVar1->framerate == 0.0) || (this->m_maxFrame <= 1.0)) && ((peVar1->spawnflags & 2) == 0))
  {
    peVar1->frame = 0.0;
    return;
  }
  (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = AnimateThink;
  (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar1->nextthink = p1Var2->time;
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  this->m_lastTime = p1Var2->time;
  peVar1->frame = 0.0;
  return;
}


// CSprite::Use  @ 0008d640  (line 1325)

/* DWARF original prototype: void Use(CSprite * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CSprite::Use(CSprite *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,float value
            )

{
  int iVar1;
  _2globalvars_t *p1Var2;
  int iVar3;
  entvars_t *peVar4;
  
                    /* Unresolved local var: int on@[???] */
  iVar1 = ((this->super_CPointEntity).super_CBaseEntity.pev)->effects;
  iVar3 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,(uint)(iVar1 != 0x80));
  if (iVar3 != 0) {
                    /* Unresolved local var: int on@[???] */
    peVar4 = (this->super_CPointEntity).super_CBaseEntity.pev;
    if (iVar1 == 0x80) {
      peVar4->effects = 0;
      p1Var2 = gpGlobals;
      peVar4 = (this->super_CPointEntity).super_CBaseEntity.pev;
      if (((peVar4->framerate != 0.0) && (1.0 < this->m_maxFrame)) ||
         ((peVar4->spawnflags & 2) != 0)) {
        (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = AnimateThink;
        (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
        peVar4->nextthink = p1Var2->time;
        peVar4 = (this->super_CPointEntity).super_CBaseEntity.pev;
        this->m_lastTime = p1Var2->time;
      }
      peVar4->frame = 0.0;
      return;
    }
    peVar4->effects = 0x80;
    ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
  }
  return;
}


// CGibShooter::~CGibShooter  @ 00092000  (line 1341)

/* DWARF original prototype: void ~CGibShooter(CGibShooter * this, int __in_chrg) */

void __thiscall CGibShooter::~CGibShooter(CGibShooter *this,int __in_chrg)

{
  return;
}


// CGibShooter::Restore  @ 0008beb0  (line 1376)

/* DWARF original prototype: int Restore(CGibShooter * this, CRestore * restore) */

int __thiscall CGibShooter::Restore(CGibShooter *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseDelay::Restore(&this->super_CBaseDelay,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CGibShooter",this,m_SaveData,7);
  }
  return iVar2;
}


// CGibShooter::Save  @ 0008bf10  (line 1376)

/* DWARF original prototype: int Save(CGibShooter * this, CSave * save) */

int __thiscall CGibShooter::Save(CGibShooter *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseDelay::Save(&this->super_CBaseDelay,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CGibShooter",this,m_SaveData,7);
  }
  return iVar2;
}


// gibshooter  @ 00091760  (line 1377)

void gibshooter(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x498,pev);
  *puVar1 = &PTR__CGibShooter_0014ca64;
  puVar1[1] = pev;
  return;
}


// CGibShooter::Precache  @ 0008c460  (line 1381)

/* DWARF original prototype: void Precache(CGibShooter * this) */

void __thiscall CGibShooter::Precache(CGibShooter *this)

{
  int iVar1;
  
  if (g_Language != 1) {
    iVar1 = (*g_engfuncs.pfnPrecacheModel)("models/hgibs.mdl");
    this->m_iGibModelIndex = iVar1;
    return;
  }
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("models/germanygibs.mdl");
  this->m_iGibModelIndex = iVar1;
  return;
}


// CGibShooter::KeyValue  @ 0008b3a0  (line 1394)

/* DWARF original prototype: void KeyValue(CGibShooter * this, KeyValueData * pkvd) */

void __thiscall CGibShooter::KeyValue(CGibShooter *this,KeyValueData *pkvd)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  double dVar7;
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar2 = 8;
  pcVar4 = pkvd->szKeyName;
  pcVar3 = pcVar4;
  pcVar5 = "m_iGibs";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar3 == *pcVar5;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
    this->m_iGibCapacity = lVar1;
    this->m_iGibs = lVar1;
    pkvd->fHandled = 1;
  }
  else {
    iVar2 = 0xd;
    bVar6 = false;
    pcVar3 = pcVar4;
    pcVar5 = "m_flVelocity";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar3 == *pcVar5;
      pcVar3 = pcVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      dVar7 = strtod(pkvd->szValue,(char **)0x0);
      this->m_flGibVelocity = (float)dVar7;
      pkvd->fHandled = 1;
    }
    else {
      iVar2 = 0xd;
      bVar6 = false;
      pcVar3 = pcVar4;
      pcVar5 = "m_flVariance";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        dVar7 = strtod(pkvd->szValue,(char **)0x0);
        this->m_flVariance = (float)dVar7;
        pkvd->fHandled = 1;
      }
      else {
        iVar2 = 0xc;
        bVar6 = false;
        pcVar3 = "m_flGibLife";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar6 = *pcVar4 == *pcVar3;
          pcVar4 = pcVar4 + 1;
          pcVar3 = pcVar3 + 1;
        } while (bVar6);
        if (!bVar6) {
          CBaseDelay::KeyValue(&this->super_CBaseDelay,pkvd);
          return;
        }
        dVar7 = strtod(pkvd->szValue,(char **)0x0);
        this->m_flGibLife = (float)dVar7;
        pkvd->fHandled = 1;
      }
    }
  }
  return;
}


// CGibShooter::Use  @ 0008a6a0  (line 1422)

/* DWARF original prototype: void Use(CGibShooter * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CGibShooter::Use(CGibShooter *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
                float value)

{
  _2globalvars_t *p1Var1;
  
  p1Var1 = gpGlobals;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__pfn = ShootThink;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__delta = 0;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->nextthink = p1Var1->time;
  return;
}


// CGibShooter::Spawn  @ 0008b4f0  (line 1428)

/* DWARF original prototype: void Spawn(CGibShooter * this) */

void __thiscall CGibShooter::Spawn(CGibShooter *this)

{
  entvars_t *peVar1;
  int iVar2;
  
  (*(this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[3])(this);
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->effects = 0x80;
  if ((this->super_CBaseDelay).m_flDelay == 0.0) {
    (this->super_CBaseDelay).m_flDelay = 0.1;
  }
  if (this->m_flGibLife == 0.0) {
    this->m_flGibLife = 25.0;
  }
  SetMovedir((this->super_CBaseDelay).super_CBaseEntity.pev);
  peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  iVar2 = (*g_engfuncs.pfnModelFrames)(this->m_iGibModelIndex);
  peVar1->body = iVar2;
  return;
}


// CGibShooter::CreateGib  @ 0008cb00  (line 1450)

/* DWARF original prototype: CGib * CreateGib(CGibShooter * this) */

CGib * __thiscall CGibShooter::CreateGib(CGibShooter *this)

{
  edict_t *peVar1;
  int iVar2;
  int32 iVar3;
  CGib *this_00;
  entvars_t *peVar4;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: CGib * pGib@[DW_OP_reg3(EBX)] */
  (*g_engfuncs.pfnCVarGetFloat)("violence_hgibs");
  if (extraout_ST0 != (longdouble)0) {
                    /* Unresolved local var: entvars_t * pev@[???] */
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    peVar4 = (entvars_t *)0x0;
    if (peVar1 != (edict_t *)0x0) {
      peVar4 = &peVar1->v;
    }
    if ((peVar4->pContainingEntity == (edict_t *)0x0) ||
       (this_00 = peVar4->pContainingEntity->pvPrivateData, this_00 == (CGib *)0x0)) {
      this_00 = CBaseEntity::operator_new(0x484,peVar4);
      (this_00->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CGib_0014a448;
      (this_00->super_CBaseEntity).pev = peVar4;
    }
    CGib::Spawn(this_00,"models/hgibs.mdl");
    this_00->m_bloodColor = 0xf7;
    iVar2 = ((this->super_CBaseDelay).super_CBaseEntity.pev)->body;
    if (iVar2 < 2) {
      (*g_engfuncs.pfnAlertMessage)(at_aiconsole,"GibShooter Body is <= 1!\n");
      iVar2 = ((this->super_CBaseDelay).super_CBaseEntity.pev)->body;
    }
    peVar4 = (this_00->super_CBaseEntity).pev;
    iVar3 = (*g_engfuncs.pfnRandomLong)(1,iVar2 + -1);
    peVar4->body = iVar3;
    return this_00;
  }
  return (CGib *)0x0;
}


// CGibShooter::ShootThink  @ 0008ccf0  (line 1470)

/* DWARF original prototype: void ShootThink(CGibShooter * this) */

void __thiscall CGibShooter::ShootThink(CGibShooter *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  entvars_t *peVar10;
  int iVar11;
  _2globalvars_t *p1Var12;
  int iVar13;
  longdouble extraout_ST0;
  longdouble lVar14;
  longdouble extraout_ST0_00;
  longdouble lVar15;
  longdouble extraout_ST0_01;
  longdouble lVar16;
  longdouble lVar17;
  longdouble lVar18;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  longdouble extraout_ST0_04;
  float fVar19;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* Unresolved local var: Vector vecShootDir@[???]
                       Unresolved local var: CGib * pGib@[???] */
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->nextthink =
       gpGlobals->time + (this->super_CBaseDelay).m_flDelay;
  peVar10 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  fVar19 = (peVar10->movedir).x;
  fVar1 = (peVar10->movedir).y;
  fVar2 = (peVar10->movedir).z;
  fVar3 = this->m_flVariance;
  (*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
  fVar4 = (gpGlobals->v_right).z;
  lVar14 = (longdouble)fVar3;
  fVar3 = (gpGlobals->v_right).y;
  fVar5 = (gpGlobals->v_right).x;
  fVar6 = this->m_flVariance;
  (*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
  fVar7 = (gpGlobals->v_forward).z;
  lVar15 = (longdouble)fVar6;
  fVar6 = (gpGlobals->v_forward).y;
  fVar8 = (gpGlobals->v_forward).x;
  fVar9 = this->m_flVariance;
  (*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
  lVar16 = (longdouble)fVar9;
  lVar17 = (longdouble)(gpGlobals->v_up).z * extraout_ST0_01 * lVar16 +
           (longdouble)
           (float)((longdouble)
                   (float)((longdouble)fVar4 * extraout_ST0 * lVar14 + (longdouble)fVar2) +
                  (longdouble)fVar7 * extraout_ST0_00 * lVar15);
  lVar18 = (longdouble)(gpGlobals->v_up).y * extraout_ST0_01 * lVar16 +
           (longdouble)
           (float)((longdouble)fVar6 * extraout_ST0_00 * lVar15 +
                  (longdouble)(float)((longdouble)fVar1 + (longdouble)fVar3 * extraout_ST0 * lVar14)
                  );
  lVar15 = (longdouble)(gpGlobals->v_up).x * extraout_ST0_01 * lVar16 +
           (longdouble)
           (float)((longdouble)
                   (float)(extraout_ST0 * (longdouble)fVar5 * lVar14 + (longdouble)fVar19) +
                  extraout_ST0_00 * (longdouble)fVar8 * lVar15);
                    /* Unresolved local var: float flLen@[???] */
  lVar16 = lVar17 * lVar17 + lVar18 * lVar18 + lVar15 * lVar15;
  lVar14 = SQRT(lVar16);
  if (NAN(lVar14)) {
    fVar19 = sqrtf((float)lVar16);
    lVar14 = (longdouble)fVar19;
    lVar15 = (longdouble)(float)lVar15;
    lVar18 = (longdouble)(float)lVar18;
    lVar17 = (longdouble)(float)lVar17;
  }
  if (lVar14 == (longdouble)0) {
    local_1c = 0.0;
    local_18 = 1.0;
    local_14 = 0.0;
  }
  else {
    lVar14 = (longdouble)1.0 / lVar14;
    local_18 = (float)(lVar17 * lVar14);
    local_1c = (float)(lVar18 * lVar14);
    local_14 = (float)(lVar14 * lVar15);
  }
  iVar13 = (*(this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[0x41])(this);
  if (iVar13 != 0) {
                    /* Unresolved local var: float thinkTime@[???] */
    peVar10 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    iVar11 = *(int *)(iVar13 + 4);
    *(vec_t *)(iVar11 + 8) = (peVar10->origin).x;
    *(vec_t *)(iVar11 + 0xc) = (peVar10->origin).y;
    *(vec_t *)(iVar11 + 0x10) = (peVar10->origin).z;
    fVar19 = this->m_flGibVelocity;
    iVar11 = *(int *)(iVar13 + 4);
    *(float *)(iVar11 + 0x20) = local_14 * fVar19;
    *(float *)(iVar11 + 0x24) = local_1c * fVar19;
    *(float *)(iVar11 + 0x28) = fVar19 * local_18;
    iVar11 = *(int *)(iVar13 + 4);
    (*g_engfuncs.pfnRandomFloat)(100.0,200.0);
    *(float *)(iVar11 + 0x5c) = (float)extraout_ST0_02;
    iVar11 = *(int *)(iVar13 + 4);
    (*g_engfuncs.pfnRandomFloat)(100.0,300.0);
    *(float *)(iVar11 + 0x60) = (float)extraout_ST0_03;
    fVar19 = *(float *)(*(int *)(iVar13 + 4) + 0x104);
    fVar1 = gpGlobals->time;
    fVar2 = this->m_flGibLife;
    (*g_engfuncs.pfnRandomFloat)(0.95,1.05);
    lVar14 = extraout_ST0_04 * (longdouble)fVar2;
    *(float *)(iVar13 + 0x480) = (float)lVar14;
    if (lVar14 < (longdouble)(fVar19 - fVar1)) {
      *(float *)(*(int *)(iVar13 + 4) + 0x104) = (float)(lVar14 + (longdouble)gpGlobals->time);
      *(undefined4 *)(iVar13 + 0x480) = 0;
    }
  }
  iVar13 = this->m_iGibs + -1;
  this->m_iGibs = iVar13;
  p1Var12 = gpGlobals;
  if (0 < iVar13) {
    return;
  }
  peVar10 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  if ((peVar10->spawnflags & 1) == 0) {
    (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar10->nextthink = p1Var12->time;
    return;
  }
  iVar13 = this->m_iGibCapacity;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__delta = 0;
  this->m_iGibs = iVar13;
  peVar10->nextthink = gpGlobals->time;
  return;
}


// CEnvShooter::~CEnvShooter  @ 00092090  (line 1520)

/* DWARF original prototype: void ~CEnvShooter(CEnvShooter * this, int __in_chrg) */

void __thiscall CEnvShooter::~CEnvShooter(CEnvShooter *this,int __in_chrg)

{
  return;
}


// env_shooter  @ 000917d0  (line 1528)

void env_shooter(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x498,pev);
  *puVar1 = &PTR__CEnvShooter_0014cb74;
  puVar1[1] = pev;
  return;
}


// CEnvShooter::KeyValue  @ 0008bbe0  (line 1531)

/* DWARF original prototype: void KeyValue(CEnvShooter * this, KeyValueData * pkvd) */

void __thiscall CEnvShooter::KeyValue(CEnvShooter *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  long lVar2;
  string_t sVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
  bVar7 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar4 = 0xb;
  pcVar5 = pkvd->szKeyName;
  pcVar6 = "shootmodel";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar7 = *pcVar5 == *pcVar6;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    peVar1 = (this->super_CGibShooter).super_CBaseDelay.super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    peVar1->model = sVar3;
    pkvd->fHandled = 1;
  }
  else {
    iVar4 = 0xc;
    bVar7 = false;
    pcVar5 = pkvd->szKeyName;
    pcVar6 = "shootsounds";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar7 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (!bVar7) {
      CGibShooter::KeyValue(&this->super_CGibShooter,pkvd);
      return;
    }
                    /* Unresolved local var: int iNoise@[???] */
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    pkvd->fHandled = 1;
    switch(lVar2) {
    case 0:
      (this->super_CGibShooter).m_iGibMaterial = 0;
      break;
    case 1:
      (this->super_CGibShooter).m_iGibMaterial = 1;
      break;
    case 2:
      (this->super_CGibShooter).m_iGibMaterial = 2;
      break;
    case 3:
      (this->super_CGibShooter).m_iGibMaterial = 3;
      break;
    case 4:
      (this->super_CGibShooter).m_iGibMaterial = 8;
      break;
    default:
      (this->super_CGibShooter).m_iGibMaterial = 9;
    }
  }
  return;
}


// CEnvShooter::Precache  @ 0008b730  (line 1573)

/* DWARF original prototype: void Precache(CEnvShooter * this) */

void __thiscall CEnvShooter::Precache(CEnvShooter *this)

{
  int iVar1;
  
  iVar1 = (*g_engfuncs.pfnPrecacheModel)
                    (gpGlobals->pStringBase +
                     ((this->super_CGibShooter).super_CBaseDelay.super_CBaseEntity.pev)->model);
  (this->super_CGibShooter).m_iGibModelIndex = iVar1;
  CBreakable::MaterialSoundPrecache((this->super_CGibShooter).m_iGibMaterial);
  return;
}


// CEnvShooter::CreateGib  @ 0008b5d0  (line 1580)

/* DWARF original prototype: CGib * CreateGib(CEnvShooter * this) */

CGib * __thiscall CEnvShooter::CreateGib(CEnvShooter *this)

{
  int iVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  int32 iVar4;
  CGib *this_00;
  entvars_t *peVar5;
  
                    /* Unresolved local var: CGib * pGib@[DW_OP_reg3(EBX)]
                       Unresolved local var: int bodyPart@[???] */
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar3 = (*g_engfuncs.pfnCreateEntity)();
  peVar5 = (entvars_t *)0x0;
  if (peVar3 != (edict_t *)0x0) {
    peVar5 = &peVar3->v;
  }
  if ((peVar5->pContainingEntity == (edict_t *)0x0) ||
     (this_00 = peVar5->pContainingEntity->pvPrivateData, this_00 == (CGib *)0x0)) {
    this_00 = CBaseEntity::operator_new(0x484,peVar5);
    (this_00->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CGib_0014a448;
    (this_00->super_CBaseEntity).pev = peVar5;
  }
  CGib::Spawn(this_00,gpGlobals->pStringBase +
                      ((this->super_CGibShooter).super_CBaseDelay.super_CBaseEntity.pev)->model);
  iVar1 = ((this->super_CGibShooter).super_CBaseDelay.super_CBaseEntity.pev)->body;
  if (iVar1 < 2) {
    iVar4 = 0;
  }
  else {
    iVar4 = (*g_engfuncs.pfnRandomLong)(0,iVar1 + -1);
  }
  ((this_00->super_CBaseEntity).pev)->body = iVar4;
  this_00->m_bloodColor = -1;
  this_00->m_material = (this->super_CGibShooter).m_iGibMaterial;
  ((this_00->super_CBaseEntity).pev)->rendermode =
       ((this->super_CGibShooter).super_CBaseDelay.super_CBaseEntity.pev)->rendermode;
  ((this_00->super_CBaseEntity).pev)->renderamt =
       ((this->super_CGibShooter).super_CBaseDelay.super_CBaseEntity.pev)->renderamt;
  peVar5 = (this->super_CGibShooter).super_CBaseDelay.super_CBaseEntity.pev;
  peVar2 = (this_00->super_CBaseEntity).pev;
  (peVar2->rendercolor).x = (peVar5->rendercolor).x;
  (peVar2->rendercolor).y = (peVar5->rendercolor).y;
  (peVar2->rendercolor).z = (peVar5->rendercolor).z;
  ((this_00->super_CBaseEntity).pev)->renderfx =
       ((this->super_CGibShooter).super_CBaseDelay.super_CBaseEntity.pev)->renderfx;
  ((this_00->super_CBaseEntity).pev)->scale =
       ((this->super_CGibShooter).super_CBaseDelay.super_CBaseEntity.pev)->scale;
  ((this_00->super_CBaseEntity).pev)->skin =
       ((this->super_CGibShooter).super_CBaseDelay.super_CBaseEntity.pev)->skin;
  return this_00;
}


// CTestEffect::~CTestEffect  @ 00092080  (line 1607)

/* DWARF original prototype: void ~CTestEffect(CTestEffect * this, int __in_chrg) */

void __thiscall CTestEffect::~CTestEffect(CTestEffect *this,int __in_chrg)

{
  return;
}


// test_effect  @ 00091840  (line 1624)

void test_effect(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x548,pev);
  *puVar1 = &PTR__CTestEffect_0014cc84;
  puVar1[1] = pev;
  return;
}


// CTestEffect::Spawn  @ 0008c590  (line 1627)

/* DWARF original prototype: void Spawn(CTestEffect * this) */

void __thiscall CTestEffect::Spawn(CTestEffect *this)

{
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[3];
  if (UNRECOVERED_JUMPTABLE == Precache) {
                    /* WARNING: Could not recover jumptable at 0x0008c5a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnPrecacheModel)("sprites/lgtning.spr");
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0008c5b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// CTestEffect::Precache  @ 0008a6d0  (line 1633)

/* DWARF original prototype: void Precache(CTestEffect * this) */

void __thiscall CTestEffect::Precache(CTestEffect *this)

{
                    /* WARNING: Could not recover jumptable at 0x0008a6d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("sprites/lgtning.spr");
  return;
}


// CTestEffect::TestThink  @ 0008e4c0  (line 1637)

/* DWARF original prototype: void TestThink(CTestEffect * this) */

void __thiscall CTestEffect::TestThink(CTestEffect *this)

{
  int *piVar1;
  CBeam **ppCVar2;
  float fVar3;
  float fVar4;
  entvars_t *peVar5;
  float *pfVar6;
  CBeam *this_00;
  int iVar7;
  int iVar8;
  _2globalvars_t *p1Var9;
  longdouble lVar10;
  longdouble lVar11;
  longdouble lVar12;
  longdouble lVar13;
  longdouble lVar14;
  float fVar15;
  Vector local_5c;
  Vector local_50;
  _1TraceResult local_44;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float t@[???] */
  iVar8 = this->m_iBeam;
  fVar3 = gpGlobals->time;
  fVar4 = this->m_flStartTime;
  p1Var9 = gpGlobals;
  if (iVar8 < 0x18) {
                    /* Unresolved local var: CBeam * pbeam@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecDir@[???] */
    this_00 = CBeam::BeamCreate("sprites/lgtning.spr",100);
    peVar5 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    local_5c.x = (peVar5->origin).x;
    local_5c.y = (peVar5->origin).y;
    local_5c.z = (peVar5->origin).z;
    lVar10 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
    lVar11 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
    lVar12 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
                    /* Unresolved local var: float flLen@[???] */
    lVar13 = (longdouble)(float)lVar11;
    lVar14 = (longdouble)(float)lVar10;
    lVar14 = lVar14 * lVar14 + lVar13 * lVar13 + lVar12 * lVar12;
    lVar13 = SQRT(lVar14);
    if (NAN(lVar13)) {
      fVar15 = sqrtf((float)lVar14);
      lVar13 = (longdouble)fVar15;
      lVar12 = (longdouble)(float)lVar12;
    }
    if (lVar13 == (longdouble)0) {
      lVar10 = (longdouble)0;
      lVar14 = (longdouble)128.0;
      lVar11 = lVar10;
    }
    else {
      lVar13 = (longdouble)1.0 / lVar13;
      lVar14 = (longdouble)(float)lVar10 * lVar13 * (longdouble)128.0;
      lVar10 = (longdouble)(float)lVar11 * lVar13 * (longdouble)128.0;
      lVar11 = lVar13 * lVar12 * (longdouble)128.0;
    }
    local_50.x = (vec_t)(lVar11 + (longdouble)local_5c.x);
    local_50.y = (vec_t)(lVar10 + (longdouble)local_5c.y);
    local_50.z = (vec_t)(lVar14 + (longdouble)local_5c.z);
    UTIL_TraceLine(&local_5c,&local_50,ignore_monsters,
                   ((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,&local_44);
    piVar1 = &((this_00->super_CBaseEntity).pev)->rendermode;
    *piVar1 = *piVar1 & 0xf0;
    peVar5 = (this_00->super_CBaseEntity).pev;
    (peVar5->origin).x = local_5c.x;
    (peVar5->origin).y = local_5c.y;
    (peVar5->origin).z = local_5c.z;
    peVar5 = (this_00->super_CBaseEntity).pev;
    (peVar5->angles).x = local_44.vecEndPos.x;
    (peVar5->angles).y = local_44.vecEndPos.y;
    (peVar5->angles).z = local_44.vecEndPos.z;
    piVar1 = &((this_00->super_CBaseEntity).pev)->sequence;
    *piVar1 = *piVar1 & 0xfff;
    piVar1 = &((this_00->super_CBaseEntity).pev)->skin;
    *piVar1 = *piVar1 & 0xfff;
    CBeam::RelinkBeam(this_00);
    p1Var9 = gpGlobals;
    (((this_00->super_CBaseEntity).pev)->rendercolor).x = 255.0;
    (((this_00->super_CBaseEntity).pev)->rendercolor).y = 180.0;
    (((this_00->super_CBaseEntity).pev)->rendercolor).z = 100.0;
    ((this_00->super_CBaseEntity).pev)->scale = 100.0;
    ((this_00->super_CBaseEntity).pev)->animtime = 12.0;
    iVar7 = this->m_iBeam;
    iVar8 = iVar7 + 1;
    this->m_flBeamTime[iVar7] = p1Var9->time;
    this->m_pBeam[iVar7] = this_00;
    this->m_iBeam = iVar8;
  }
  if (3.0 <= fVar3 - fVar4) {
    if (0 < iVar8) {
      iVar8 = 0;
      do {
        ppCVar2 = this->m_pBeam + iVar8;
        iVar8 = iVar8 + 1;
        UTIL_Remove(&(*ppCVar2)->super_CBaseEntity);
        p1Var9 = gpGlobals;
      } while (iVar8 < this->m_iBeam);
    }
    fVar3 = p1Var9->time;
    this->m_iBeam = 0;
    (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr *)0x0;
    this->m_flStartTime = fVar3;
    (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__delta = 0;
    return;
  }
  iVar7 = 0;
  pfVar6 = this->m_flBeamTime;
  if (0 < iVar8) {
    do {
      iVar7 = iVar7 + 1;
      ((((CBeam *)pfVar6[-0x18])->super_CBaseEntity).pev)->renderamt =
           (float)(int)(((p1Var9->time - *pfVar6) / ((this->m_flStartTime + 3.0) - *pfVar6)) * 255.0
                       );
      pfVar6 = pfVar6 + 1;
    } while (iVar7 < this->m_iBeam);
  }
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->nextthink = p1Var9->time + 0.1;
  return;
}


// CTestEffect::Use  @ 0008a6e0  (line 1704)

/* DWARF original prototype: void Use(CTestEffect * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CTestEffect::Use(CTestEffect *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
                float value)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  
  p1Var2 = gpGlobals;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__pfn = TestThink;
  peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar1->nextthink = p1Var2->time + 0.1;
  this->m_flStartTime = p1Var2->time;
  return;
}


// CBlood::~CBlood  @ 00092070  (line 1713)

/* DWARF original prototype: void ~CBlood(CBlood * this, int __in_chrg) */

void __thiscall CBlood::~CBlood(CBlood *this,int __in_chrg)

{
  return;
}


// env_blood  @ 000918b0  (line 1732)

void env_blood(entvars_t *pev)

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
  *puVar1 = &PTR__CBlood_0014cd90;
  puVar1[1] = pev;
  return;
}


// CBlood::Spawn  @ 0008b590  (line 1742)

/* DWARF original prototype: void Spawn(CBlood * this) */

void __thiscall CBlood::Spawn(CBlood *this)

{
  ((this->super_CPointEntity).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->frame = 0.0;
  SetMovedir((this->super_CPointEntity).super_CBaseEntity.pev);
  return;
}


// CBlood::KeyValue  @ 0008bd00  (line 1752)

/* DWARF original prototype: void KeyValue(CBlood * this, KeyValueData * pkvd) */

void __thiscall CBlood::KeyValue(CBlood *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  double dVar7;
  
  bVar6 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar3 = 6;
  pcVar4 = pkvd->szKeyName;
  pcVar5 = "color";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
                    /* Unresolved local var: int color@[???] */
    lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
    peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
    if (lVar2 == 1) {
      peVar1->impulse = 0xc3;
    }
    else {
      peVar1->impulse = 0xf7;
    }
  }
  else {
    iVar3 = 7;
    bVar6 = false;
    pcVar4 = pkvd->szKeyName;
    pcVar5 = "amount";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (!bVar6) {
      CBaseEntity::KeyValue((CBaseEntity *)this,pkvd);
      return;
    }
    dVar7 = strtod(pkvd->szValue,(char **)0x0);
    ((this->super_CPointEntity).super_CBaseEntity.pev)->dmg = (float)dVar7;
  }
  pkvd->fHandled = 1;
  return;
}


// CBlood::Direction  @ 00091920  (line 1779)

/* DWARF original prototype: Vector Direction(CBlood * this) */

Vector * __thiscall CBlood::Direction(Vector *__return_storage_ptr__,CBlood *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if ((peVar1->spawnflags & 1) == 0) {
    __return_storage_ptr__->x = (peVar1->movedir).x;
    __return_storage_ptr__->y = (peVar1->movedir).y;
    __return_storage_ptr__->z = (peVar1->movedir).z;
    return __return_storage_ptr__;
  }
  UTIL_RandomBloodVector(__return_storage_ptr__);
  return __return_storage_ptr__;
}


// CBlood::BloodPosition  @ 00091980  (line 1788)

/* DWARF original prototype: Vector BloodPosition(CBlood * this, CBaseEntity * pActivator) */

Vector * __thiscall
CBlood::BloodPosition(Vector *__return_storage_ptr__,CBlood *this,CBaseEntity *pActivator)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  entvars_t *peVar5;
  edict_t *peVar6;
  longdouble lVar7;
  longdouble lVar8;
  longdouble lVar9;
  
  peVar5 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if ((peVar5->spawnflags & 4) != 0) {
                    /* Unresolved local var: edict_t * pPlayer@[???] */
    peVar6 = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
    if (peVar6 != (edict_t *)0x0) {
      lVar7 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-10.0,10.0);
      lVar8 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-10.0,10.0);
      lVar9 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-10.0,10.0);
      fVar1 = (peVar6->v).origin.z;
      fVar2 = (peVar6->v).view_ofs.z;
      fVar3 = (peVar6->v).origin.y;
      fVar4 = (peVar6->v).view_ofs.y;
      __return_storage_ptr__->x =
           (float)((longdouble)(peVar6->v).origin.x + (longdouble)(peVar6->v).view_ofs.x + lVar9);
      __return_storage_ptr__->y = fVar3 + fVar4 + (float)lVar8;
      __return_storage_ptr__->z = fVar1 + fVar2 + (float)lVar7;
      return __return_storage_ptr__;
    }
    peVar5 = (this->super_CPointEntity).super_CBaseEntity.pev;
  }
  __return_storage_ptr__->x = (peVar5->origin).x;
  __return_storage_ptr__->y = (peVar5->origin).y;
  __return_storage_ptr__->z = (peVar5->origin).z;
  return __return_storage_ptr__;
}


// CBlood::Use  @ 00091a80  (line 1807)

/* DWARF original prototype: void Use(CBlood * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CBlood::Use(CBlood *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,float value)

{
  float fVar1;
  entvars_t *peVar2;
  uint uVar3;
  int color;
  Vector local_78;
  Vector local_6c;
  Vector local_60;
  _1TraceResult local_54;
  
  peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
  uVar3 = peVar2->spawnflags;
  fVar1 = peVar2->dmg;
  color = peVar2->impulse;
  if ((uVar3 & 2) == 0) {
    if ((uVar3 & 1) == 0) {
      local_54.fAllSolid = (int)(peVar2->movedir).x;
      local_54.fStartSolid = (int)(peVar2->movedir).y;
      local_54.fInOpen = (int)(peVar2->movedir).z;
    }
    else {
      UTIL_RandomBloodVector((Vector *)&local_54);
    }
    BloodPosition(&local_60,this,pActivator);
    UTIL_BloodDrips(&local_60,(Vector *)&local_54,color,(int)fVar1);
    peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
    uVar3 = peVar2->spawnflags;
  }
  else {
    if ((uVar3 & 1) == 0) {
      local_54.fAllSolid = (int)(peVar2->movedir).x;
      local_54.fStartSolid = (int)(peVar2->movedir).y;
      local_54.fInOpen = (int)(peVar2->movedir).z;
    }
    else {
      UTIL_RandomBloodVector((Vector *)&local_54);
    }
    BloodPosition(&local_60,this,pActivator);
    UTIL_BloodStream(&local_60,(Vector *)&local_54,color,(int)fVar1);
    peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
    uVar3 = peVar2->spawnflags;
  }
  if ((uVar3 & 8) != 0) {
                    /* Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector start@[???]
                       Unresolved local var: TraceResult tr@[???] */
    if ((uVar3 & 1) == 0) {
      local_78.x = (peVar2->movedir).x;
      local_78.y = (peVar2->movedir).y;
      local_78.z = (peVar2->movedir).z;
    }
    else {
      UTIL_RandomBloodVector(&local_78);
    }
    BloodPosition(&local_6c,this,pActivator);
    fVar1 = ((this->super_CPointEntity).super_CBaseEntity.pev)->dmg;
    local_60.z = local_78.z * fVar1 + local_78.z * fVar1 + local_6c.z;
    local_60.y = local_78.y * fVar1 + local_78.y * fVar1 + local_6c.y;
    local_60.x = fVar1 * local_78.x + fVar1 * local_78.x + local_6c.x;
    UTIL_TraceLine(&local_6c,&local_60,ignore_monsters,(edict_t *)0x0,&local_54);
    if (local_54.flFraction != 1.0) {
      UTIL_BloodDecalTrace(&local_54,((this->super_CPointEntity).super_CBaseEntity.pev)->impulse);
    }
  }
  return;
}


// CShake::~CShake  @ 00092060  (line 1828)

/* DWARF original prototype: void ~CShake(CShake * this, int __in_chrg) */

void __thiscall CShake::~CShake(CShake *this,int __in_chrg)

{
  return;
}


// env_shake  @ 00091d00  (line 1847)

void env_shake(entvars_t *pev)

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
  *puVar1 = &PTR__CShake_0014ce9c;
  puVar1[1] = pev;
  return;
}


// CShake::Spawn  @ 0008a720  (line 1862)

/* DWARF original prototype: void Spawn(CShake * this) */

void __thiscall CShake::Spawn(CShake *this)

{
  entvars_t *peVar1;
  
  ((this->super_CPointEntity).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->frame = 0.0;
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if ((peVar1->spawnflags & 1) != 0) {
    peVar1->dmg = 0.0;
  }
  return;
}


// CShake::KeyValue  @ 0008b1d0  (line 1874)

/* DWARF original prototype: void KeyValue(CShake * this, KeyValueData * pkvd) */

void __thiscall CShake::KeyValue(CShake *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  double dVar6;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar1 = 10;
  pcVar3 = pkvd->szKeyName;
  pcVar2 = pcVar3;
  pcVar4 = "amplitude";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar5 = *pcVar2 == *pcVar4;
    pcVar2 = pcVar2 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    dVar6 = strtod(pkvd->szValue,(char **)0x0);
    ((this->super_CPointEntity).super_CBaseEntity.pev)->scale = (float)dVar6;
    pkvd->fHandled = 1;
  }
  else {
    iVar1 = 10;
    bVar5 = false;
    pcVar2 = pcVar3;
    pcVar4 = "frequency";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      dVar6 = strtod(pkvd->szValue,(char **)0x0);
      ((this->super_CPointEntity).super_CBaseEntity.pev)->dmg_save = (float)dVar6;
      pkvd->fHandled = 1;
    }
    else {
      iVar1 = 9;
      bVar5 = false;
      pcVar2 = pcVar3;
      pcVar4 = "duration";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pcVar2 == *pcVar4;
        pcVar2 = pcVar2 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        dVar6 = strtod(pkvd->szValue,(char **)0x0);
        ((this->super_CPointEntity).super_CBaseEntity.pev)->dmg_take = (float)dVar6;
        pkvd->fHandled = 1;
      }
      else {
        iVar1 = 7;
        bVar5 = false;
        pcVar2 = "radius";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar5 = *pcVar3 == *pcVar2;
          pcVar3 = pcVar3 + 1;
          pcVar2 = pcVar2 + 1;
        } while (bVar5);
        if (!bVar5) {
          CBaseEntity::KeyValue((CBaseEntity *)this,pkvd);
          return;
        }
        dVar6 = strtod(pkvd->szValue,(char **)0x0);
        ((this->super_CPointEntity).super_CBaseEntity.pev)->dmg = (float)dVar6;
        pkvd->fHandled = 1;
      }
    }
  }
  return;
}


// CShake::Use  @ 0008b780  (line 1901)

/* DWARF original prototype: void Use(CShake * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CShake::Use(CShake *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,float value)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  UTIL_ScreenShake(&peVar1->origin,peVar1->scale,peVar1->dmg_save,peVar1->dmg_take,peVar1->dmg);
  return;
}


// CFade::~CFade  @ 00092050  (line 1906)

/* DWARF original prototype: void ~CFade(CFade * this, int __in_chrg) */

void __thiscall CFade::~CFade(CFade *this,int __in_chrg)

{
  return;
}


// env_fade  @ 00091d70  (line 1921)

void env_fade(entvars_t *pev)

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
  *puVar1 = &PTR__CFade_0014cfa8;
  puVar1[1] = pev;
  return;
}


// CFade::Spawn  @ 0008a770  (line 1929)

/* DWARF original prototype: void Spawn(CFade * this) */

void __thiscall CFade::Spawn(CFade *this)

{
  ((this->super_CPointEntity).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->frame = 0.0;
  return;
}


// CFade::KeyValue  @ 0008bb20  (line 1938)

/* DWARF original prototype: void KeyValue(CFade * this, KeyValueData * pkvd) */

void __thiscall CFade::KeyValue(CFade *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  double dVar5;
  
  bVar4 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar1 = 9;
  pcVar2 = pkvd->szKeyName;
  pcVar3 = "duration";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    dVar5 = strtod(pkvd->szValue,(char **)0x0);
    ((this->super_CPointEntity).super_CBaseEntity.pev)->dmg_take = (float)dVar5;
    pkvd->fHandled = 1;
  }
  else {
    iVar1 = 9;
    bVar4 = false;
    pcVar2 = pkvd->szKeyName;
    pcVar3 = "holdtime";
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
    ((this->super_CPointEntity).super_CBaseEntity.pev)->dmg_save = (float)dVar5;
    pkvd->fHandled = 1;
  }
  return;
}


// CFade::Use  @ 0008b7d0  (line 1955)

/* DWARF original prototype: void Use(CFade * this, CBaseEntity * pActivator, CBaseEntity * pCaller,
   USE_TYPE useType, float value) */

void __thiscall
CFade::Use(CFade *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,float value)

{
  entvars_t *peVar1;
  uint flags;
  
                    /* Unresolved local var: int fadeFlags@[???] */
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  flags = peVar1->spawnflags & 1U ^ 1;
  if ((peVar1->spawnflags & 2U) != 0) {
    flags = flags | 2;
  }
  UTIL_ScreenFadeAll(&peVar1->rendercolor,peVar1->dmg_take,peVar1->dmg_save,(int)peVar1->renderamt,
                     flags);
  CBaseEntity::SUB_UseTargets((CBaseEntity *)this,(CBaseEntity *)this,USE_TOGGLE,0.0);
  return;
}


// CMessage::~CMessage  @ 00092040  (line 1969)

/* DWARF original prototype: void ~CMessage(CMessage * this, int __in_chrg) */

void __thiscall CMessage::~CMessage(CMessage *this,int __in_chrg)

{
  return;
}


// env_message  @ 00091de0  (line 1979)

void env_message(entvars_t *pev)

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
  *puVar1 = &PTR__CMessage_0014d0b4;
  puVar1[1] = pev;
  return;
}


// CMessage::Spawn  @ 0008c870  (line 1983)

/* DWARF original prototype: void Spawn(CMessage * this) */

void __thiscall CMessage::Spawn(CMessage *this)

{
  _func_int_varargs *p_Var1;
  int iVar2;
  float fVar3;
  entvars_t *peVar4;
  
  p_Var1 = (this->super_CPointEntity).super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    peVar4 = (this->super_CPointEntity).super_CBaseEntity.pev;
    if (peVar4->noise != 0) {
      (*g_engfuncs.pfnPrecacheSound)(gpGlobals->pStringBase + peVar4->noise);
      peVar4 = (this->super_CPointEntity).super_CBaseEntity.pev;
    }
  }
  else {
    (*p_Var1)(this);
    peVar4 = (this->super_CPointEntity).super_CBaseEntity.pev;
  }
  peVar4->solid = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0;
  peVar4 = (this->super_CPointEntity).super_CBaseEntity.pev;
  iVar2 = peVar4->impulse;
  if (iVar2 == 2) {
    peVar4->speed = 0.8;
  }
  else if (iVar2 == 3) {
    peVar4->speed = 0.0;
  }
  else {
    fVar3 = 1.25;
    if (iVar2 != 1) {
      fVar3 = 2.0;
    }
    peVar4->speed = fVar3;
  }
  ((this->super_CPointEntity).super_CBaseEntity.pev)->impulse = 0;
  peVar4 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if (peVar4->scale <= 0.0) {
    peVar4->scale = 1.0;
  }
  return;
}


// CMessage::Precache  @ 0008a7b0  (line 2018)

/* DWARF original prototype: void Precache(CMessage * this) */

void __thiscall CMessage::Precache(CMessage *this)

{
  string_t sVar1;
  
  sVar1 = ((this->super_CPointEntity).super_CBaseEntity.pev)->noise;
  if (sVar1 == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0008a7da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)(gpGlobals->pStringBase + sVar1);
  return;
}


// CMessage::KeyValue  @ 0008ae30  (line 2023)

/* DWARF original prototype: void KeyValue(CMessage * this, KeyValueData * pkvd) */

void __thiscall CMessage::KeyValue(CMessage *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  long lVar2;
  string_t sVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  double dVar11;
  
  bVar8 = &stack0x00000000 < (undefined1 *)0x2c;
  bVar10 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar4 = 0xd;
  pbVar6 = (byte *)pkvd->szKeyName;
  pbVar5 = pbVar6;
  pbVar7 = (byte *)"messagesound";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pbVar5 < *pbVar7;
    bVar10 = *pbVar5 == *pbVar7;
    pbVar5 = pbVar5 + 1;
    pbVar7 = pbVar7 + 1;
  } while (bVar10);
  bVar9 = (!bVar8 && !bVar10) < bVar8;
  if ((!bVar8 && !bVar10) == bVar8) {
    peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    peVar1->noise = sVar3;
    pkvd->fHandled = 1;
    return;
  }
  iVar4 = 0xe;
  bVar8 = false;
  pbVar5 = pbVar6;
  pbVar7 = (byte *)"messagevolume";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar9 = *pbVar5 < *pbVar7;
    bVar8 = *pbVar5 == *pbVar7;
    pbVar5 = pbVar5 + 1;
    pbVar7 = pbVar7 + 1;
  } while (bVar8);
  if ((!bVar9 && !bVar8) == bVar9) {
    peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
    dVar11 = strtod(pkvd->szValue,(char **)0x0);
    peVar1->scale = (float)((longdouble)dVar11 * (longdouble)0.1);
    pkvd->fHandled = 1;
    return;
  }
  iVar4 = 0x13;
  bVar8 = false;
  pbVar5 = (byte *)"messageattenuation";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pbVar6 == *pbVar5;
    pbVar6 = pbVar6 + 1;
    pbVar5 = pbVar5 + 1;
  } while (bVar8);
  if (!bVar8) {
    CBaseEntity::KeyValue((CBaseEntity *)this,pkvd);
    return;
  }
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
  peVar1->impulse = lVar2;
  pkvd->fHandled = 1;
  return;
}


// CMessage::Use  @ 0008b910  (line 2045)

/* DWARF original prototype: void Use(CMessage * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CMessage::Use(CMessage *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
             float value)

{
  edict_t *pEdict;
  entvars_t *peVar1;
  
                    /* Unresolved local var: edict_t * pPlayer@[???] */
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if ((peVar1->spawnflags & 2) == 0) {
    if ((pActivator == (CBaseEntity *)0x0) || ((pActivator->pev->flags & 8) == 0)) {
      pEdict = (*g_engfuncs.pfnPEntityOfEntIndex)(1);
      peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
    }
    else {
      pEdict = pActivator->pev->pContainingEntity;
    }
    if (pEdict != (edict_t *)0x0) {
      UTIL_ShowMessage(gpGlobals->pStringBase + peVar1->message,pEdict);
      peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
    }
  }
  else {
    UTIL_ShowMessageAll(gpGlobals->pStringBase + peVar1->message);
    peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  }
  if (peVar1->noise != 0) {
    EMIT_SOUND_DYN(peVar1->pContainingEntity,4,gpGlobals->pStringBase + peVar1->noise,peVar1->scale,
                   peVar1->speed,0,100);
    peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  }
  if ((peVar1->spawnflags & 1) != 0) {
    UTIL_Remove((CBaseEntity *)this);
  }
  CBaseEntity::SUB_UseTargets((CBaseEntity *)this,(CBaseEntity *)this,USE_TOGGLE,0.0);
  return;
}


// CEnvFunnel::~CEnvFunnel  @ 00092030  (line 2076)

/* DWARF original prototype: void ~CEnvFunnel(CEnvFunnel * this, int __in_chrg) */

void __thiscall CEnvFunnel::~CEnvFunnel(CEnvFunnel *this,int __in_chrg)

{
  return;
}


// CEnvFunnel::Precache  @ 0008a7e0  (line 2087)

/* DWARF original prototype: void Precache(CEnvFunnel * this) */

void __thiscall CEnvFunnel::Precache(CEnvFunnel *this)

{
  int iVar1;
  
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("sprites/flare6.spr");
  this->m_iSprite = iVar1;
  return;
}


// env_funnel  @ 00091e50  (line 2091)

void env_funnel(entvars_t *pev)

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
  *puVar1 = &PTR__CEnvFunnel_0014d1c0;
  puVar1[1] = pev;
  return;
}


// CEnvFunnel::Use  @ 0008a800  (line 2094)

/* DWARF original prototype: void Use(CEnvFunnel * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CEnvFunnel::Use(CEnvFunnel *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
               float value)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  
  (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(100);
  (*g_engfuncs.pfnWriteCoord)((((this->super_CBaseDelay).super_CBaseEntity.pev)->origin).x);
  (*g_engfuncs.pfnWriteCoord)((((this->super_CBaseDelay).super_CBaseEntity.pev)->origin).y);
  (*g_engfuncs.pfnWriteCoord)((((this->super_CBaseDelay).super_CBaseEntity.pev)->origin).z);
  (*g_engfuncs.pfnWriteShort)(this->m_iSprite);
  if ((((this->super_CBaseDelay).super_CBaseEntity.pev)->spawnflags & 1) == 0) {
    (*g_engfuncs.pfnWriteShort)(0);
  }
  else {
    (*g_engfuncs.pfnWriteShort)(1);
  }
  (*g_engfuncs.pfnMessageEnd)();
  p1Var2 = gpGlobals;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar1->nextthink = p1Var2->time;
  return;
}


// CEnvFunnel::Spawn  @ 0008c5c0  (line 2119)

/* DWARF original prototype: void Spawn(CEnvFunnel * this) */

void __thiscall CEnvFunnel::Spawn(CEnvFunnel *this)

{
  _func_int_varargs *p_Var1;
  int iVar2;
  
  p_Var1 = (this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    iVar2 = (*g_engfuncs.pfnPrecacheModel)("sprites/flare6.spr");
    this->m_iSprite = iVar2;
  }
  else {
    (*p_Var1)(this);
  }
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->effects = 0x80;
  return;
}


// CEnvBeverage::~CEnvBeverage  @ 00092020  (line 2130)

/* DWARF original prototype: void ~CEnvBeverage(CEnvBeverage * this, int __in_chrg) */

void __thiscall CEnvBeverage::~CEnvBeverage(CEnvBeverage *this,int __in_chrg)

{
  return;
}


// CEnvBeverage::Precache  @ 0008a8e0  (line 2139)

/* DWARF original prototype: void Precache(CEnvBeverage * this) */

void __thiscall CEnvBeverage::Precache(CEnvBeverage *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/can.mdl");
                    /* WARNING: Could not recover jumptable at 0x0008a8fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("weapons/g_bounce3.wav");
  return;
}


// env_beverage  @ 00091ec0  (line 2144)

void env_beverage(entvars_t *pev)

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
  *puVar1 = &PTR__CEnvBeverage_0014d2cc;
  puVar1[1] = pev;
  return;
}


// CEnvBeverage::Use  @ 0008bde0  (line 2147)

/* DWARF original prototype: void Use(CEnvBeverage * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CEnvBeverage::Use(CEnvBeverage *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
                 float value)

{
  entvars_t *peVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  int32 iVar4;
  
                    /* Unresolved local var: CBaseEntity * pCan@[???] */
  peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  if ((peVar1->frags == 0.0) && (0.0 < peVar1->health)) {
    pCVar3 = CBaseEntity::Create("item_sodacan",&peVar1->origin,&peVar1->angles,
                                 peVar1->pContainingEntity);
    iVar2 = ((this->super_CBaseDelay).super_CBaseEntity.pev)->skin;
    if (iVar2 == 6) {
      peVar1 = pCVar3->pev;
      iVar4 = (*g_engfuncs.pfnRandomLong)(0,5);
      peVar1->skin = iVar4;
    }
    else {
      pCVar3->pev->skin = iVar2;
    }
                    /* Unresolved local var: CBaseEntity * pCan@[???] */
    ((this->super_CBaseDelay).super_CBaseEntity.pev)->frags = 1.0;
    peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    peVar1->health = peVar1->health - 1.0;
  }
  return;
}


// CEnvBeverage::Spawn  @ 0008c760  (line 2174)

/* DWARF original prototype: void Spawn(CEnvBeverage * this) */

void __thiscall CEnvBeverage::Spawn(CEnvBeverage *this)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  
  p_Var1 = (this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/can.mdl");
    (*g_engfuncs.pfnPrecacheSound)("weapons/g_bounce3.wav");
  }
  else {
    (*p_Var1)(this);
  }
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->effects = 0x80;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->frags = 0.0;
  peVar2 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  if (peVar2->health == 0.0) {
    peVar2->health = 10.0;
  }
  return;
}


// CItemSoda::~CItemSoda  @ 00092010  (line 2189)

/* DWARF original prototype: void ~CItemSoda(CItemSoda * this, int __in_chrg) */

void __thiscall CItemSoda::~CItemSoda(CItemSoda *this,int __in_chrg)

{
  return;
}


// CItemSoda::Precache  @ 0008a910  (line 2199)

/* DWARF original prototype: void Precache(CItemSoda * this) */

void __thiscall CItemSoda::Precache(CItemSoda *this)

{
  return;
}


// item_sodacan  @ 00091f30  (line 2202)

void item_sodacan(entvars_t *pev)

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
  *puVar1 = &PTR__CItemSoda_0014d3d8;
  puVar1[1] = pev;
  return;
}


// CItemSoda::Spawn  @ 0008c4b0  (line 2205)

/* DWARF original prototype: void Spawn(CItemSoda * this) */

void __thiscall CItemSoda::Spawn(CItemSoda *this)

{
  _func_int_varargs *p_Var1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  Vector local_24;
  Vector local_18;
  
  p_Var1 = (this->super_CBaseEntity)._vptr_CBaseEntity[3];
  if (p_Var1 != Precache) {
    (*p_Var1)(this);
  }
  ((this->super_CBaseEntity).pev)->solid = 0;
  ((this->super_CBaseEntity).pev)->movetype = 6;
  (*g_engfuncs.pfnSetModel)(((this->super_CBaseEntity).pev)->pContainingEntity,"models/can.mdl");
  local_18.x = 0.0;
  local_18.y = 0.0;
  local_18.z = 0.0;
  local_24.x = 0.0;
  local_24.y = 0.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CBaseEntity).pev,&local_24,&local_18);
  p1Var3 = gpGlobals;
  (this->super_CBaseEntity).m_pfnThink.__pfn = CanThink;
  peVar2 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar2->nextthink = p1Var3->time + 0.5;
  return;
}


// CItemSoda::CanThink  @ 0008b850  (line 2218)

/* DWARF original prototype: void CanThink(CItemSoda * this) */

void __thiscall CItemSoda::CanThink(CItemSoda *this)

{
  Vector local_24;
  Vector local_18;
  
  EMIT_SOUND_DYN(((this->super_CBaseEntity).pev)->pContainingEntity,1,"weapons/g_bounce3.wav",1.0,
                 0.8,0,100);
  local_24.z = 0.0;
  ((this->super_CBaseEntity).pev)->solid = 1;
  local_18.x = 8.0;
  local_18.y = 8.0;
  local_18.z = 8.0;
  local_24.x = -8.0;
  local_24.y = -8.0;
  UTIL_SetSize((this->super_CBaseEntity).pev,&local_24,&local_18);
  (this->super_CBaseEntity).m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  (this->super_CBaseEntity).m_pfnTouch.__pfn = CanTouch;
  (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
  return;
}


// CItemSoda::CanTouch  @ 0008ba50  (line 2228)

/* DWARF original prototype: void CanTouch(CItemSoda * this, CBaseEntity * pOther) */

void __thiscall CItemSoda::CanTouch(CItemSoda *this,CBaseEntity *pOther)

{
  _2globalvars_t *p1Var1;
  int iVar2;
  entvars_t *peVar3;
  
  if ((pOther->pev->flags & 8) == 0) {
    return;
  }
  (*pOther->_vptr_CBaseEntity[0xe])(pOther,0x3f800000,0);
  peVar3 = (this->super_CBaseEntity).pev;
  if (peVar3->owner != (edict_t *)0x0) {
    iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar3->owner);
    peVar3 = (this->super_CBaseEntity).pev;
    if (iVar2 != 0) {
      (peVar3->owner->v).frags = 0.0;
      peVar3 = (this->super_CBaseEntity).pev;
    }
  }
  peVar3->solid = 0;
  ((this->super_CBaseEntity).pev)->movetype = 0;
  ((this->super_CBaseEntity).pev)->effects = 0x80;
  p1Var1 = gpGlobals;
  (this->super_CBaseEntity).m_pfnTouch.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  peVar3 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
  (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar3->nextthink = p1Var1->time;
  return;
}


