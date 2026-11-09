// Ghidra decompilation of functions from tfc/effects.cpp
// 130 functions, ordered by original source line

// info_target  @ 000cc750  (line 27)

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
  *puVar1 = &PTR__CPointEntity_0018c688;
  puVar1[1] = pev;
  return;
}


// CBubbling::ObjectCaps  @ 000d0230  (line 42)

/* DWARF original prototype: int ObjectCaps(CBubbling * this) */

int __thiscall CBubbling::ObjectCaps(CBubbling *this)

{
  return 0;
}


// env_bubbles  @ 000cc7c0  (line 51)

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
  *puVar1 = &PTR__CBubbling_0017cfe8;
  puVar1[1] = pev;
  return;
}


// CBubbling::Restore  @ 000ca540  (line 62)

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


// CBubbling::Save  @ 000ca780  (line 62)

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


// CBubbling::Spawn  @ 000c9570  (line 68)

/* DWARF original prototype: void Spawn(CBubbling * this) */

void __thiscall CBubbling::Spawn(CBubbling *this)

{
  float fVar1;
  entvars_t *peVar2;
  globalvars_t *pgVar3;
  vec_t vVar4;
  
                    /* Unresolved local var: int speed@[???] */
  (*(this->super_CBaseEntity)._vptr_CBaseEntity[3])(this);
  peVar2 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + peVar2->model);
  ((this->super_CBaseEntity).pev)->solid = 0;
  ((this->super_CBaseEntity).pev)->renderamt = 0.0;
  ((this->super_CBaseEntity).pev)->rendermode = 2;
  peVar2 = (this->super_CBaseEntity).pev;
  fVar1 = peVar2->speed;
  if (fVar1 <= 0.0) {
    fVar1 = -fVar1;
  }
  (peVar2->rendercolor).x = (float)((int)fVar1 >> 8);
  (((this->super_CBaseEntity).pev)->rendercolor).y = (float)((int)fVar1 & 0xff);
  peVar2 = (this->super_CBaseEntity).pev;
  vVar4 = 0.0;
  if (peVar2->speed < 0.0) {
    vVar4 = 1.0;
  }
  (peVar2->rendercolor).z = vVar4;
  pgVar3 = gpGlobals;
  peVar2 = (this->super_CBaseEntity).pev;
  if ((peVar2->spawnflags & 1) == 0) {
    (this->super_CBaseEntity).m_pfnThink.__pfn = FizzThink;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    peVar2->nextthink = pgVar3->time + 2.0;
    this->m_state = 1;
    return;
  }
  this->m_state = 0;
  return;
}


// CBubbling::Precache  @ 000c96a0  (line 94)

/* DWARF original prototype: void Precache(CBubbling * this) */

void __thiscall CBubbling::Precache(CBubbling *this)

{
  int iVar1;
  
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("sprites/bubble.spr");
  this->m_bubbleModel = iVar1;
  return;
}


// CBubbling::Use  @ 000ca870  (line 100)

/* DWARF original prototype: void Use(CBubbling * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CBubbling::Use(CBubbling *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
              float value)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = CBaseEntity::ShouldToggle(&this->super_CBaseEntity,useType,this->m_state);
  if (iVar3 == 0) {
    uVar4 = this->m_state;
    pgVar2 = gpGlobals;
  }
  else {
    uVar4 = (uint)(this->m_state == 0);
    this->m_state = uVar4;
    pgVar2 = gpGlobals;
  }
  gpGlobals = pgVar2;
  if (uVar4 == 0) {
    peVar1 = (this->super_CBaseEntity).pev;
    (this->super_CBaseEntity).m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    peVar1->nextthink = 0.0;
    return;
  }
  (this->super_CBaseEntity).m_pfnThink.__pfn = FizzThink;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  ((this->super_CBaseEntity).pev)->nextthink = pgVar2->time + 0.1;
  return;
}


// CBubbling::KeyValue  @ 000cb380  (line 118)

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


// CBubbling::FizzThink  @ 000ca0e0  (line 140)

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


// beam  @ 000cc830  (line 160)

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
  *puVar1 = &PTR__CBeam_0017d108;
  puVar1[1] = pev;
  return;
}


// CBeam::Spawn  @ 000c96c0  (line 163)

/* DWARF original prototype: void Spawn(CBeam * this) */

void __thiscall CBeam::Spawn(CBeam *this)

{
  ((this->super_CBaseEntity).pev)->solid = 0;
                    /* WARNING: Could not recover jumptable at 0x000c96d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseEntity)._vptr_CBaseEntity[3])();
  return;
}


// CBeam::Precache  @ 000c96e0  (line 169)

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
    peVar3->sequence = uVar1 & 0xfff | (peVar3->sequence & 0xf000U) << 0xc;
    peVar3 = (this->super_CBaseEntity).pev;
    peVar2 = (*g_engfuncs.pfnPEntityOfEntIndex)(uVar1);
    peVar3->owner = peVar2;
    peVar3 = (this->super_CBaseEntity).pev;
  }
  if (peVar3->aiment != (edict_t *)0x0) {
    uVar1 = (*g_engfuncs.pfnIndexOfEdict)(peVar3->aiment);
    peVar3 = (this->super_CBaseEntity).pev;
    peVar3->skin = uVar1 & 0xfff | (peVar3->skin & 0xf000U) << 0xc;
    peVar3 = (this->super_CBaseEntity).pev;
    peVar2 = (*g_engfuncs.pfnPEntityOfEntIndex)(uVar1);
    peVar3->aiment = peVar2;
  }
  return;
}


// CBeam::SetStartEntity  @ 000cc8a0  (line 177)

/* DWARF original prototype: void SetStartEntity(CBeam * this, int entityIndex) */

void __thiscall CBeam::SetStartEntity(CBeam *this,int entityIndex)

{
  entvars_t *peVar1;
  edict_t *peVar2;
  
  peVar1 = (this->super_CBaseEntity).pev;
  peVar1->sequence = entityIndex & 0xfffU | (peVar1->sequence & 0xf000U) << 0xc;
  peVar1 = (this->super_CBaseEntity).pev;
  peVar2 = (*g_engfuncs.pfnPEntityOfEntIndex)(entityIndex);
  peVar1->owner = peVar2;
  return;
}


// CBeam::SetEndEntity  @ 000cc900  (line 183)

/* DWARF original prototype: void SetEndEntity(CBeam * this, int entityIndex) */

void __thiscall CBeam::SetEndEntity(CBeam *this,int entityIndex)

{
  entvars_t *peVar1;
  edict_t *peVar2;
  
  peVar1 = (this->super_CBaseEntity).pev;
  peVar1->skin = entityIndex & 0xfffU | (peVar1->skin & 0xf000U) << 0xc;
  peVar1 = (this->super_CBaseEntity).pev;
  peVar2 = (*g_engfuncs.pfnPEntityOfEntIndex)(entityIndex);
  peVar1->aiment = peVar2;
  return;
}


// CBeam::GetStartPos  @ 000cc960  (line 191)

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


// CBeam::GetEndPos  @ 000cc9a0  (line 202)

/* DWARF original prototype: Vector * GetEndPos(CBeam * this) */

Vector * __thiscall CBeam::GetEndPos(CBeam *this)

{
  entvars_t *peVar1;
  edict_t *peVar2;
  uint uVar3;
  
  peVar1 = (this->super_CBaseEntity).pev;
                    /* Unresolved local var: int type@[DW_OP_reg2(EDX)]
                       Unresolved local var: edict_t * pent@[???] */
  uVar3 = peVar1->rendermode & 0xf;
  if ((uVar3 != 3) && (uVar3 != 0)) {
    peVar2 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar1->skin & 0xfff);
    if (peVar2 != (edict_t *)0x0) {
      return &(peVar2->v).origin;
    }
    peVar1 = (this->super_CBaseEntity).pev;
  }
                    /* Unresolved local var: int type@[???]
                       Unresolved local var: edict_t * pent@[???] */
  return &peVar1->angles;
}


// CBeam::BeamCreate  @ 000ccac0  (line 217)

CBeam * CBeam::BeamCreate(char *pSpriteName,int width)

{
  edict_t *peVar1;
  CBeam *this;
  entvars_t *pev;
  
                    /* Unresolved local var: CBeam * pBeam@[DW_OP_reg6(ESI)]
                       Unresolved local var: entvars_t * pev@[???] */
  peVar1 = (*g_engfuncs.pfnCreateEntity)();
  pev = (entvars_t *)0x0;
  if (peVar1 != (edict_t *)0x0) {
    pev = &peVar1->v;
  }
  if ((pev->pContainingEntity == (edict_t *)0x0) ||
     (this = pev->pContainingEntity->pvPrivateData, this == (CBeam *)0x0)) {
    this = CBaseEntity::operator_new(0x474,pev);
    (this->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CBeam_0017d108;
    (this->super_CBaseEntity).pev = pev;
  }
  else {
    pev = (this->super_CBaseEntity).pev;
  }
  pev->classname = (int)&DAT_0017ccc8 - (int)gpGlobals->pStringBase;
  BeamInit(this,pSpriteName,width);
  return this;
}


// CBeam::BeamInit  @ 000cca00  (line 229)

/* DWARF original prototype: void BeamInit(CBeam * this, char * pSpriteName, int width) */

void __thiscall CBeam::BeamInit(CBeam *this,char *pSpriteName,int width)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = &((this->super_CBaseEntity).pev)->flags;
  *piVar1 = *piVar1 | 0x20000000;
  (((this->super_CBaseEntity).pev)->rendercolor).x = 255.0;
  (((this->super_CBaseEntity).pev)->rendercolor).y = 255.0;
  (((this->super_CBaseEntity).pev)->rendercolor).z = 255.0;
  ((this->super_CBaseEntity).pev)->renderamt = 255.0;
  ((this->super_CBaseEntity).pev)->body = 0;
  ((this->super_CBaseEntity).pev)->frame = 0.0;
  ((this->super_CBaseEntity).pev)->animtime = 0.0;
  ((this->super_CBaseEntity).pev)->model = (int)pSpriteName - (int)gpGlobals->pStringBase;
  iVar2 = (*g_engfuncs.pfnPrecacheModel)(pSpriteName);
  ((this->super_CBaseEntity).pev)->modelindex = iVar2;
  ((this->super_CBaseEntity).pev)->scale = (float)width;
  ((this->super_CBaseEntity).pev)->skin = 0;
  ((this->super_CBaseEntity).pev)->sequence = 0;
  ((this->super_CBaseEntity).pev)->rendermode = 0;
  return;
}


// CBeam::PointsInit  @ 000ccee0  (line 246)

/* DWARF original prototype: void PointsInit(CBeam * this, Vector * start, Vector * end) */

void __thiscall CBeam::PointsInit(CBeam *this,Vector *start,Vector *end)

{
  int *piVar1;
  entvars_t *peVar2;
  
  piVar1 = &((this->super_CBaseEntity).pev)->rendermode;
  *piVar1 = *piVar1 & 0xf0;
  peVar2 = (this->super_CBaseEntity).pev;
  (peVar2->origin).x = start->x;
  (peVar2->origin).y = start->y;
  (peVar2->origin).z = start->z;
  peVar2 = (this->super_CBaseEntity).pev;
  (peVar2->angles).x = end->x;
  (peVar2->angles).y = end->y;
  (peVar2->angles).z = end->z;
  piVar1 = &((this->super_CBaseEntity).pev)->sequence;
  *piVar1 = *piVar1 & 0xfff;
  piVar1 = &((this->super_CBaseEntity).pev)->skin;
  *piVar1 = *piVar1 & 0xfff;
  RelinkBeam(this);
  return;
}


// CBeam::HoseInit  @ 000cce70  (line 257)

/* DWARF original prototype: void HoseInit(CBeam * this, Vector * start, Vector * direction) */

void __thiscall CBeam::HoseInit(CBeam *this,Vector *start,Vector *direction)

{
  int *piVar1;
  entvars_t *peVar2;
  
  peVar2 = (this->super_CBaseEntity).pev;
  peVar2->rendermode = peVar2->rendermode & 0xf0U | 3;
  peVar2 = (this->super_CBaseEntity).pev;
  (peVar2->origin).x = start->x;
  (peVar2->origin).y = start->y;
  (peVar2->origin).z = start->z;
  peVar2 = (this->super_CBaseEntity).pev;
  (peVar2->angles).x = direction->x;
  (peVar2->angles).y = direction->y;
  (peVar2->angles).z = direction->z;
  piVar1 = &((this->super_CBaseEntity).pev)->sequence;
  *piVar1 = *piVar1 & 0xfff;
  piVar1 = &((this->super_CBaseEntity).pev)->skin;
  *piVar1 = *piVar1 & 0xfff;
  RelinkBeam(this);
  return;
}


// CBeam::PointEntInit  @ 000ccdd0  (line 268)

/* DWARF original prototype: void PointEntInit(CBeam * this, Vector * start, int endIndex) */

void __thiscall CBeam::PointEntInit(CBeam *this,Vector *start,int endIndex)

{
  int *piVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  
  peVar2 = (this->super_CBaseEntity).pev;
  peVar2->rendermode = peVar2->rendermode & 0xf0U | 1;
  peVar2 = (this->super_CBaseEntity).pev;
  (peVar2->origin).x = start->x;
  (peVar2->origin).y = start->y;
  (peVar2->origin).z = start->z;
  peVar2 = (this->super_CBaseEntity).pev;
  peVar2->skin = endIndex & 0xfffU | (peVar2->skin & 0xf000U) << 0xc;
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


// CBeam::EntsInit  @ 000ccd00  (line 278)

/* DWARF original prototype: void EntsInit(CBeam * this, int startIndex, int endIndex) */

void __thiscall CBeam::EntsInit(CBeam *this,int startIndex,int endIndex)

{
  int *piVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  
  peVar2 = (this->super_CBaseEntity).pev;
  peVar2->rendermode = peVar2->rendermode & 0xf0U | 2;
  peVar2 = (this->super_CBaseEntity).pev;
  peVar2->sequence = startIndex & 0xfffU | (peVar2->sequence & 0xf000U) << 0xc;
  peVar2 = (this->super_CBaseEntity).pev;
  peVar3 = (*g_engfuncs.pfnPEntityOfEntIndex)(startIndex);
  peVar2->owner = peVar3;
  peVar2 = (this->super_CBaseEntity).pev;
  peVar2->skin = endIndex & 0xfffU | (peVar2->skin & 0xf000U) << 0xc;
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


// CBeam::RelinkBeam  @ 000ccb50  (line 289)

/* DWARF original prototype: void RelinkBeam(CBeam * this) */

void __thiscall CBeam::RelinkBeam(CBeam *this)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  uint uVar4;
  Vector *pVVar5;
  edict_t *peVar6;
  entvars_t *peVar7;
  Vector *pVVar8;
  
                    /* Unresolved local var: Vector * startPos@[???]
                       Unresolved local var: Vector * endPos@[???] */
  peVar7 = (this->super_CBaseEntity).pev;
  uVar4 = peVar7->rendermode & 0xf;
  peVar3 = peVar7;
  if (uVar4 == 2) {
                    /* Unresolved local var: edict_t * pent@[???] */
    peVar6 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar7->sequence & 0xfff);
    peVar7 = (this->super_CBaseEntity).pev;
    peVar3 = &peVar6->v;
    uVar4 = peVar7->rendermode & 0xf;
  }
  pVVar8 = &peVar3->origin;
                    /* Unresolved local var: int type@[???]
                       Unresolved local var: edict_t * pent@[???] */
  if ((uVar4 != 3) && (uVar4 != 0)) {
    peVar6 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar7->skin & 0xfff);
    if (peVar6 != (edict_t *)0x0) {
      pVVar5 = &(peVar6->v).origin;
      peVar7 = (this->super_CBaseEntity).pev;
      goto LAB_000ccb7d;
    }
    peVar7 = (this->super_CBaseEntity).pev;
  }
                    /* Unresolved local var: int type@[???]
                       Unresolved local var: edict_t * pent@[???] */
  pVVar5 = &peVar7->angles;
LAB_000ccb7d:
  fVar1 = pVVar5->x;
  if (pVVar8->x < pVVar5->x) {
    fVar1 = pVVar8->x;
  }
  (peVar7->mins).x = fVar1;
  fVar1 = pVVar5->y;
  if (pVVar8->y < pVVar5->y) {
    fVar1 = pVVar8->y;
  }
  (((this->super_CBaseEntity).pev)->mins).y = fVar1;
  fVar1 = pVVar5->z;
  if (pVVar8->z < pVVar5->z) {
    fVar1 = pVVar8->z;
  }
  (((this->super_CBaseEntity).pev)->mins).z = fVar1;
  fVar1 = pVVar8->x;
  if (pVVar8->x <= pVVar5->x) {
    fVar1 = pVVar5->x;
  }
  (((this->super_CBaseEntity).pev)->maxs).x = fVar1;
  fVar1 = pVVar8->y;
  if (pVVar8->y <= pVVar5->y) {
    fVar1 = pVVar5->y;
  }
  (((this->super_CBaseEntity).pev)->maxs).y = fVar1;
  fVar1 = pVVar8->z;
  if (pVVar8->z <= pVVar5->z) {
    fVar1 = pVVar5->z;
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


// CBeam::TriggerTouch  @ 000cd7f0  (line 321)

/* DWARF original prototype: void TriggerTouch(CBeam * this, CBaseEntity * pOther) */

void __thiscall CBeam::TriggerTouch(CBeam *this,CBaseEntity *pOther)

{
  edict_t *peVar1;
  int *piVar2;
  
  if ((pOther->pev->flags & 0x28) != 0) {
    peVar1 = ((this->super_CBaseEntity).pev)->owner;
    if (peVar1 != (edict_t *)0x0) {
                    /* Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg1(ECX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      piVar2 = peVar1->pvPrivateData;
      (**(code **)(*piVar2 + 0xb4))(piVar2,pOther,this,3,0);
    }
                    /* WARNING: Could not recover jumptable at 0x000cd856. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnAlertMessage)(at_console,"Firing targets!!!\n");
    return;
  }
  return;
}


// CBeam::RandomTargetname  @ 000cd870  (line 335)

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


// CBeam::DoSparks  @ 000cd8c0  (line 351)

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


// env_lightning  @ 000cd930  (line 411)

void env_lightning(entvars_t *pev)

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
  *puVar1 = &PTR__CLightning_0017d228;
  puVar1[1] = pev;
  return;
}


// env_beam  @ 000cd9a0  (line 412)

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
  *puVar1 = &PTR__CLightning_0017d228;
  puVar1[1] = pev;
  return;
}


// CLightning::Restore  @ 000ca4e0  (line 450)

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


// CLightning::Save  @ 000ca720  (line 450)

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


// CLightning::Spawn  @ 000cab70  (line 454)

/* DWARF original prototype: void Spawn(CLightning * this) */

void __thiscall CLightning::Spawn(CLightning *this)

{
  globalvars_t *pgVar1;
  entvars_t *peVar2;
  
  if (this->m_iszSpriteName == 0) {
    (this->super_CBeam).super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (this->super_CBeam).super_CBaseEntity.m_pfnThink.__delta = 0;
  }
  else {
    ((this->super_CBeam).super_CBaseEntity.pev)->solid = 0;
    (*(this->super_CBeam).super_CBaseEntity._vptr_CBaseEntity[3])(this);
    pgVar1 = gpGlobals;
    ((this->super_CBeam).super_CBaseEntity.pev)->dmgtime = gpGlobals->time;
    peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
    if ((this->m_life == 0.0) && ((peVar2->spawnflags & 8) == 0)) {
      (this->super_CBeam).super_CBaseEntity.m_pfnThink.__pfn =
           (_func___thiscall_void_CBaseEntity_ptr *)0x0;
      (this->super_CBeam).super_CBaseEntity.m_pfnThink.__delta = 0;
      if (0.0 < peVar2->dmg) {
        (this->super_CBeam).super_CBaseEntity.m_pfnThink.__pfn = DamageThink;
        peVar2->nextthink = pgVar1->time + 0.1;
        peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
      }
      if (peVar2->targetname != 0) {
        if ((peVar2->spawnflags & 1) == 0) {
          peVar2->effects = 0x80;
          peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
          this->m_active = 0;
          peVar2->nextthink = 0.0;
        }
        else {
          this->m_active = 1;
        }
        (this->super_CBeam).super_CBaseEntity.m_pfnUse.__pfn = ToggleUse;
        (this->super_CBeam).super_CBaseEntity.m_pfnUse.__delta = 0;
        return;
      }
    }
    else {
      this->m_active = 0;
      if (peVar2->targetname != 0) {
        (this->super_CBeam).super_CBaseEntity.m_pfnUse.__pfn = StrikeUse;
        (this->super_CBeam).super_CBaseEntity.m_pfnUse.__delta = 0;
        if ((peVar2->targetname != 0) && ((peVar2->spawnflags & 1) == 0)) {
          return;
        }
      }
      (this->super_CBeam).super_CBaseEntity.m_pfnThink.__pfn = StrikeThink;
      (this->super_CBeam).super_CBaseEntity.m_pfnThink.__delta = 0;
      peVar2->nextthink = pgVar1->time + 1.0;
    }
  }
  return;
}


// CLightning::Precache  @ 000c9790  (line 503)

/* DWARF original prototype: void Precache(CLightning * this) */

void __thiscall CLightning::Precache(CLightning *this)

{
  int iVar1;
  
  iVar1 = (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + this->m_iszSpriteName);
  this->m_spriteTexture = iVar1;
  CBeam::Precache(&this->super_CBeam);
  return;
}


// CLightning::Activate  @ 000cf060  (line 510)

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


// CLightning::KeyValue  @ 000cba70  (line 517)

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


// CLightning::ToggleUse  @ 000cc1a0  (line 579)

/* DWARF original prototype: void ToggleUse(CLightning * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CLightning::ToggleUse
          (CLightning *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  int *piVar1;
  entvars_t *peVar2;
  globalvars_t *pgVar3;
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
                    /* Unresolved local var: int type@[DW_OP_reg1(ECX)]
                       Unresolved local var: edict_t * pent@[???] */
      uVar6 = peVar7->rendermode & 0xf;
      if ((uVar6 == 3) || (uVar6 == 0)) {
        position = &peVar7->angles;
      }
      else {
                    /* Unresolved local var: int type@[???]
                       Unresolved local var: edict_t * pent@[???] */
        peVar5 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar7->skin & 0xfff);
        if (peVar5 == (edict_t *)0x0) {
          peVar7 = (this->super_CBeam).super_CBaseEntity.pev;
          position = &peVar7->angles;
        }
        else {
          peVar7 = (this->super_CBeam).super_CBaseEntity.pev;
          position = &(peVar5->v).origin;
        }
        uVar6 = peVar7->rendermode & 0xf;
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
      pgVar3 = gpGlobals;
      if (0.0 < peVar7->dmg) {
        peVar7->nextthink = gpGlobals->time;
        ((this->super_CBeam).super_CBaseEntity.pev)->dmgtime = pgVar3->time;
        return;
      }
    }
    else {
      this->m_active = 0;
      piVar1 = &((this->super_CBeam).super_CBaseEntity.pev)->effects;
      *piVar1 = *piVar1 | 0x80;
      ((this->super_CBeam).super_CBaseEntity.pev)->nextthink = 0.0;
    }
  }
  return;
}


// CLightning::StrikeUse  @ 000ca7e0  (line 603)

/* DWARF original prototype: void StrikeUse(CLightning * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CLightning::StrikeUse
          (CLightning *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  globalvars_t *pgVar1;
  int iVar2;
  
  iVar2 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,this->m_active);
  pgVar1 = gpGlobals;
  if (iVar2 != 0) {
    if (this->m_active == 0) {
      (this->super_CBeam).super_CBaseEntity.m_pfnThink.__pfn = StrikeThink;
      (this->super_CBeam).super_CBaseEntity.m_pfnThink.__delta = 0;
      ((this->super_CBeam).super_CBaseEntity.pev)->nextthink = pgVar1->time + 0.1;
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


// IsPointEntity  @ 000cb9f0  (line 623)

int __regparm3 IsPointEntity(CBaseEntity *pEnt)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  
  uVar1 = pEnt->pev->classname;
  uVar4 = 1;
  bVar7 = CARRY4((uint)gpGlobals->pStringBase,uVar1);
  pbVar2 = (byte *)(gpGlobals->pStringBase + uVar1);
  bVar8 = pbVar2 == (byte *)0x0;
  iVar3 = 0xc;
  pbVar5 = pbVar2;
  pbVar6 = (byte *)"info_target";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pbVar5 < *pbVar6;
    bVar8 = *pbVar5 == *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  } while (bVar8);
  bVar7 = (!bVar7 && !bVar8) == bVar7;
  if (!bVar7) {
    iVar3 = 0xe;
    pbVar5 = pbVar2;
    pbVar6 = (byte *)"info_landmark";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pbVar5 == *pbVar6;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    } while (bVar7);
    if (!bVar7) {
      iVar3 = 0xc;
      pbVar5 = (byte *)"path_corner";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pbVar2 == *pbVar5;
        pbVar2 = pbVar2 + 1;
        pbVar5 = pbVar5 + 1;
      } while (bVar7);
      uVar4 = (uint)bVar7;
    }
  }
  return uVar4;
}


// IsPointEntity  @ 000cda10  (line 624)

int IsPointEntity(CBaseEntity *pEnt)

{
  int iVar1;
  
  if (pEnt->pev->modelindex != 0) {
    iVar1 = IsPointEntity(pEnt);
    return iVar1;
  }
  return 1;
}


// CLightning::StrikeThink  @ 000ce6f0  (line 635)

/* DWARF original prototype: void StrikeThink(CLightning * this) */

void __thiscall CLightning::StrikeThink(CLightning *this)

{
  int iVar1;
  char *pcVar2;
  entvars_t *peVar3;
  float fVar4;
  _func_void_int *p_Var5;
  int32 iVar6;
  int iVar7;
  int iVar8;
  entvars_t *peVar9;
  uint uVar10;
  CBaseEntity *pCVar11;
  CBaseEntity *pEnt;
  CBaseEntity *pCVar12;
  CBaseEntity *pCVar13;
  longdouble extraout_ST0;
  TraceResult local_54;
  
                    /* Unresolved local var: CBaseEntity * pStart@[???]
                       Unresolved local var: CBaseEntity * pEnd@[???] */
  if (this->m_life != 0.0) {
    peVar3 = (this->super_CBeam).super_CBaseEntity.pev;
    fVar4 = this->m_life + gpGlobals->time;
    if ((peVar3->spawnflags & 4) == 0) {
      peVar3->nextthink = fVar4 + this->m_restrike;
    }
    else {
      (*g_engfuncs.pfnRandomFloat)(0.0,this->m_restrike);
      peVar3->nextthink = (float)(extraout_ST0 + (longdouble)fVar4);
    }
  }
  this->m_active = 1;
  if (this->m_iszEndEntity == 0) {
    iVar7 = this->m_iszStartEntity;
    if (iVar7 == 0) {
      RandomArea(this);
      return;
    }
                    /* Unresolved local var: CBaseEntity * pStart@[???] */
    pCVar11 = (CBaseEntity *)0x0;
    pcVar2 = gpGlobals->pStringBase;
    iVar8 = 0;
    pCVar13 = (CBaseEntity *)0x0;
    while (pCVar11 = UTIL_FindEntityByTargetname(pCVar11,pcVar2 + iVar7),
          pCVar11 != (CBaseEntity *)0x0) {
                    /* Unresolved local var: int total@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pNewEntity@[???] */
      iVar1 = iVar8 + 1;
      iVar6 = (*g_engfuncs.pfnRandomLong)(0,iVar8);
      iVar8 = iVar1;
      if (iVar6 < 1) {
        pCVar13 = pCVar11;
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
  pCVar11 = (CBaseEntity *)0x0;
  iVar7 = this->m_iszStartEntity;
  pcVar2 = gpGlobals->pStringBase;
  iVar8 = 0;
  pCVar13 = (CBaseEntity *)0x0;
  while (pCVar11 = UTIL_FindEntityByTargetname(pCVar11,pcVar2 + iVar7),
        pCVar11 != (CBaseEntity *)0x0) {
                    /* Unresolved local var: int total@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pNewEntity@[???] */
    iVar1 = iVar8 + 1;
    iVar6 = (*g_engfuncs.pfnRandomLong)(0,iVar8);
    iVar8 = iVar1;
    if (iVar6 < 1) {
      pCVar13 = pCVar11;
    }
  }
  pcVar2 = gpGlobals->pStringBase;
  iVar7 = this->m_iszEndEntity;
  pCVar11 = (CBaseEntity *)0x0;
  pEnt = (CBaseEntity *)0x0;
  iVar8 = 0;
  while (pCVar11 = UTIL_FindEntityByTargetname(pCVar11,pcVar2 + iVar7),
        pCVar11 != (CBaseEntity *)0x0) {
                    /* Unresolved local var: int total@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pNewEntity@[???] */
    iVar1 = iVar8 + 1;
    iVar6 = (*g_engfuncs.pfnRandomLong)(0,iVar8);
    iVar8 = iVar1;
    if (iVar6 < 1) {
      pEnt = pCVar11;
    }
  }
  if (pEnt == (CBaseEntity *)0x0) {
    return;
  }
  if (pCVar13 == (CBaseEntity *)0x0) {
    return;
  }
  if (((((pCVar13->pev->modelindex == 0) || (iVar7 = IsPointEntity(pCVar13), iVar7 != 0)) ||
       (pEnt->pev->modelindex == 0)) || (iVar7 = IsPointEntity(pEnt), iVar7 != 0)) &&
     ((((this->super_CBeam).super_CBaseEntity.pev)->spawnflags & 8) != 0)) {
    return;
  }
  (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
  iVar7 = pCVar13->pev->modelindex;
  pCVar11 = pEnt;
  pCVar12 = pCVar13;
  if ((iVar7 == 0) || (iVar8 = IsPointEntity(pCVar13), iVar8 != 0)) {
    if (((pEnt->pev->modelindex != 0) &&
        (iVar8 = IsPointEntity(pEnt), pCVar11 = pCVar13, pCVar12 = pEnt, iVar8 == 0)) ||
       (pCVar11 = pEnt, pCVar12 = pCVar13, iVar7 != 0)) goto LAB_000cec2e;
LAB_000cece6:
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnWriteCoord)((pCVar13->pev->origin).x);
    (*g_engfuncs.pfnWriteCoord)((pCVar13->pev->origin).y);
    (*g_engfuncs.pfnWriteCoord)((pCVar13->pev->origin).z);
  }
  else {
    if ((pEnt->pev->modelindex != 0) && (iVar7 = IsPointEntity(pEnt), iVar7 == 0)) {
      if ((((this->super_CBeam).super_CBaseEntity.pev)->spawnflags & 8) == 0) {
        (*g_engfuncs.pfnWriteByte)(8);
      }
      else {
        (*g_engfuncs.pfnWriteByte)(0x18);
      }
      p_Var5 = g_engfuncs.pfnWriteShort;
      iVar7 = (*g_engfuncs.pfnIndexOfEdict)(pCVar13->pev->pContainingEntity);
      (*p_Var5)(iVar7);
      p_Var5 = g_engfuncs.pfnWriteShort;
      iVar7 = (*g_engfuncs.pfnIndexOfEdict)(pEnt->pev->pContainingEntity);
      (*p_Var5)(iVar7);
      goto LAB_000ce9d7;
    }
LAB_000cec2e:
    iVar7 = IsPointEntity(pCVar12);
    pEnt = pCVar11;
    pCVar13 = pCVar12;
    if (iVar7 != 0) goto LAB_000cece6;
    (*g_engfuncs.pfnWriteByte)(1);
    p_Var5 = g_engfuncs.pfnWriteShort;
    iVar7 = (*g_engfuncs.pfnIndexOfEdict)(pCVar12->pev->pContainingEntity);
    (*p_Var5)(iVar7);
  }
  (*g_engfuncs.pfnWriteCoord)((pEnt->pev->origin).x);
  (*g_engfuncs.pfnWriteCoord)((pEnt->pev->origin).y);
  (*g_engfuncs.pfnWriteCoord)((pEnt->pev->origin).z);
LAB_000ce9d7:
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
  peVar3 = pEnt->pev;
  peVar9 = (this->super_CBeam).super_CBaseEntity.pev;
  uVar10 = peVar9->spawnflags;
  if ((uVar10 & 0x30) != 0) {
    if ((uVar10 & 0x10) != 0) {
      UTIL_Sparks(&pCVar13->pev->origin);
      peVar9 = (this->super_CBeam).super_CBaseEntity.pev;
      uVar10 = peVar9->spawnflags;
    }
    if ((uVar10 & 0x20) != 0) {
      UTIL_Sparks(&peVar3->origin);
      peVar9 = (this->super_CBeam).super_CBaseEntity.pev;
    }
  }
  if (0.0 < peVar9->dmg) {
                    /* Unresolved local var: TraceResult tr@[???] */
    UTIL_TraceLine(&pCVar13->pev->origin,&pEnt->pev->origin,dont_ignore_monsters,(edict_t *)0x0,
                   &local_54);
    ((this->super_CBeam).super_CBaseEntity.pev)->dmgtime = gpGlobals->time - 1.0;
    CBeam::BeamDamage(&this->super_CBeam,&local_54);
  }
  return;
}


// CBeam::BeamDamage  @ 000cda40  (line 740)

/* DWARF original prototype: void BeamDamage(CBeam * this, TraceResult * ptr) */

void __thiscall CBeam::BeamDamage(CBeam *this,TraceResult *ptr)

{
  int *piVar1;
  code *pcVar2;
  float fVar3;
  float __x;
  int iVar4;
  int32 iVar5;
  entvars_t *peVar6;
  float local_2c;
  float local_28;
  float local_24;
  
  RelinkBeam(this);
                    /* Unresolved local var: CBaseEntity * pHit@[DW_OP_reg7(EDI)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((ptr->flFraction != 1.0) && (ptr->pHit != (edict_t *)0x0)) &&
     (piVar1 = ptr->pHit->pvPrivateData, piVar1 != (int *)0x0)) {
    ClearMultiDamage();
    pcVar2 = *(code **)(*piVar1 + 0x30);
    peVar6 = (this->super_CBaseEntity).pev;
    fVar3 = (ptr->vecEndPos).z - (peVar6->origin).z;
    local_28 = (ptr->vecEndPos).y - (peVar6->origin).y;
    local_2c = (ptr->vecEndPos).x - (peVar6->origin).x;
                    /* Unresolved local var: float flLen@[???] */
    __x = fVar3 * fVar3 + local_28 * local_28 + local_2c * local_2c;
    local_24 = SQRT(__x);
    if (NAN(local_24)) {
      local_24 = sqrtf(__x);
      peVar6 = (this->super_CBaseEntity).pev;
    }
    if (local_24 == 0.0) {
      local_2c = 0.0;
      local_28 = 0.0;
      local_24 = 1.0;
    }
    else {
      local_24 = 1.0 / local_24;
      local_2c = local_2c * local_24;
      local_28 = local_28 * local_24;
      local_24 = local_24 * fVar3;
    }
    (*pcVar2)(piVar1,peVar6,(gpGlobals->time - peVar6->dmgtime) * peVar6->dmg,&local_2c,ptr,0x400);
    peVar6 = (this->super_CBaseEntity).pev;
    ApplyMultiDamage(peVar6,peVar6);
    peVar6 = (this->super_CBaseEntity).pev;
    if ((peVar6->spawnflags & 0x40) == 0) goto LAB_000cdb93;
    iVar4 = (**(code **)(*piVar1 + 0x8c))(piVar1);
    if (iVar4 != 0) {
      iVar5 = (*g_engfuncs.pfnRandomLong)(0,4);
      UTIL_DecalTrace(ptr,iVar5 + 0x1c);
    }
  }
  peVar6 = (this->super_CBaseEntity).pev;
LAB_000cdb93:
  peVar6->dmgtime = gpGlobals->time;
  return;
}


// CLightning::DamageThink  @ 000cdc20  (line 762)

/* DWARF original prototype: void DamageThink(CLightning * this) */

void __thiscall CLightning::DamageThink(CLightning *this)

{
  edict_t *peVar1;
  entvars_t *peVar2;
  uint uVar3;
  Vector *vecEnd;
  TraceResult local_44;
  
                    /* Unresolved local var: TraceResult tr@[???] */
  ((this->super_CBeam).super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
                    /* Unresolved local var: int type@[DW_OP_reg2(EDX)]
                       Unresolved local var: edict_t * pent@[???] */
  uVar3 = peVar2->rendermode & 0xf;
  if ((uVar3 == 3) || (uVar3 == 0)) {
    vecEnd = &peVar2->angles;
  }
  else {
                    /* Unresolved local var: int type@[???]
                       Unresolved local var: edict_t * pent@[???] */
    peVar1 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar2->skin & 0xfff);
    if (peVar1 == (edict_t *)0x0) {
      peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
      vecEnd = &peVar2->angles;
    }
    else {
      peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
      vecEnd = &(peVar1->v).origin;
    }
    uVar3 = peVar2->rendermode & 0xf;
  }
  if (uVar3 == 2) {
                    /* Unresolved local var: edict_t * pent@[???] */
    peVar1 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar2->sequence & 0xfff);
    peVar2 = &peVar1->v;
  }
  UTIL_TraceLine(&peVar2->origin,vecEnd,dont_ignore_monsters,(edict_t *)0x0,&local_44);
  CBeam::BeamDamage(&this->super_CBeam,&local_44);
  return;
}


// CLightning::Zap  @ 000cc310  (line 771)

/* DWARF original prototype: void Zap(CLightning * this, Vector * vecSrc, Vector * vecDest) */

void __thiscall CLightning::Zap(CLightning *this,Vector *vecSrc,Vector *vecDest)

{
  uint uVar1;
  int in_EAX;
  Vector *in_ECX;
  Vector *in_EDX;
  
  (*g_engfuncs.pfnMessageBegin)(0,0x17,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteCoord)(in_EDX->x);
  (*g_engfuncs.pfnWriteCoord)(in_EDX->y);
  (*g_engfuncs.pfnWriteCoord)(in_EDX->z);
  (*g_engfuncs.pfnWriteCoord)(in_ECX->x);
  (*g_engfuncs.pfnWriteCoord)(in_ECX->y);
  (*g_engfuncs.pfnWriteCoord)(in_ECX->z);
  (*g_engfuncs.pfnWriteShort)(*(int *)(in_EAX + 0x498));
  (*g_engfuncs.pfnWriteByte)(*(int *)(in_EAX + 0x4a0));
  (*g_engfuncs.pfnWriteByte)((int)*(float *)(*(int *)(in_EAX + 4) + 0x138));
  (*g_engfuncs.pfnWriteByte)((int)(*(float *)(in_EAX + 0x480) * 10.0));
  (*g_engfuncs.pfnWriteByte)(*(int *)(in_EAX + 0x484));
  (*g_engfuncs.pfnWriteByte)(*(int *)(in_EAX + 0x488));
  (*g_engfuncs.pfnWriteByte)((int)*(float *)(*(int *)(in_EAX + 4) + 0x150));
  (*g_engfuncs.pfnWriteByte)((int)*(float *)(*(int *)(in_EAX + 4) + 0x154));
  (*g_engfuncs.pfnWriteByte)((int)*(float *)(*(int *)(in_EAX + 4) + 0x158));
  (*g_engfuncs.pfnWriteByte)((int)*(float *)(*(int *)(in_EAX + 4) + 0x14c));
  (*g_engfuncs.pfnWriteByte)(*(int *)(in_EAX + 0x490));
  (*g_engfuncs.pfnMessageEnd)();
  uVar1 = *(uint *)(*(int *)(in_EAX + 4) + 0x1a0);
  if ((uVar1 & 0x30) != 0) {
    if ((uVar1 & 0x10) != 0) {
      UTIL_Sparks(in_EDX);
      uVar1 = *(uint *)(*(int *)(in_EAX + 4) + 0x1a0);
    }
    if ((uVar1 & 0x20) != 0) {
      UTIL_Sparks(in_ECX);
      return;
    }
  }
  return;
}


// CLightning::Zap  @ 000cdef0  (line 772)

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


// CLightning::RandomArea  @ 000ce0a0  (line 813)

/* DWARF original prototype: void RandomArea(CLightning * this) */

void __thiscall CLightning::RandomArea(CLightning *this)

{
  entvars_t *peVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  CLightning *this_00;
  Vector *vecEnd;
  Vector *vecDest;
  float local_c8;
  float local_c4;
  float local_c0;
  TraceResult local_b0;
  TraceResult local_78;
  Vector local_40;
  Vector local_34;
  Vector local_28 [2];
  
  iVar2 = 10;
  do {
    peVar1 = (this->super_CBeam).super_CBaseEntity.pev;
    local_40.x = (peVar1->origin).x;
    local_40.y = (peVar1->origin).y;
    local_40.z = (peVar1->origin).z;
    lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
    lVar4 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
    lVar5 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
                    /* Unresolved local var: float flLen@[???] */
    lVar6 = (longdouble)(float)lVar4;
    lVar7 = (longdouble)(float)lVar3;
    lVar7 = lVar7 * lVar7 + lVar6 * lVar6 + lVar5 * lVar5;
    lVar6 = SQRT(lVar7);
    if (NAN(lVar6)) {
      fVar8 = sqrtf((float)lVar7);
      lVar6 = (longdouble)fVar8;
      lVar5 = (longdouble)(float)lVar5;
    }
    lVar7 = (longdouble)0;
    if (lVar6 == lVar7) {
      local_c4 = 1.0;
      lVar3 = lVar7;
    }
    else {
      lVar6 = (longdouble)1.0 / lVar6;
      local_c4 = (float)((longdouble)(float)lVar3 * lVar6);
      lVar7 = (longdouble)(float)lVar4 * lVar6;
      lVar3 = lVar6 * lVar5;
    }
    local_c0 = (float)lVar3;
    local_c8 = (float)lVar7;
    fVar8 = this->m_radius;
    local_34.z = local_c4 * fVar8 + local_40.z;
    local_34.y = local_c8 * fVar8 + local_40.y;
    local_34.x = fVar8 * local_c0 + local_40.x;
    UTIL_TraceLine(&local_40,&local_34,ignore_monsters,
                   ((this->super_CBeam).super_CBaseEntity.pev)->pContainingEntity,&local_b0);
                    /* Unresolved local var: int iLoops@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecDir1@[???]
                       Unresolved local var: TraceResult tr1@[???]
                       Unresolved local var: Vector vecDir2@[???]
                       Unresolved local var: TraceResult tr2@[???] */
    if (local_b0.flFraction != 1.0) {
      do {
        lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
        fVar8 = (float)lVar3;
        lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
        fVar10 = (float)lVar3;
        lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
      } while ((longdouble)0 <
               (longdouble)fVar8 * (longdouble)local_c4 +
               (longdouble)fVar10 * (longdouble)local_c8 + (longdouble)local_c0 * lVar3);
                    /* Unresolved local var: float flLen@[???] */
      lVar6 = (longdouble)fVar8 * (longdouble)fVar8 +
              (longdouble)fVar10 * (longdouble)fVar10 + lVar3 * lVar3;
      lVar4 = SQRT(lVar6);
      if (NAN(lVar4)) {
        fVar9 = sqrtf((float)lVar6);
        lVar4 = (longdouble)fVar9;
        lVar3 = (longdouble)(float)lVar3;
      }
      lVar6 = (longdouble)0;
      if (lVar4 == lVar6) {
        lVar7 = (longdouble)1;
        lVar3 = lVar6;
      }
      else {
        lVar4 = (longdouble)1.0 / lVar4;
        lVar7 = (longdouble)fVar8 * lVar4;
        lVar6 = lVar3 * lVar4;
        lVar3 = (longdouble)fVar10 * lVar4;
      }
      lVar4 = (longdouble)this->m_radius;
      local_28[0].x = (vec_t)(lVar6 * lVar4 + (longdouble)local_40.x);
      local_28[0].y = (vec_t)(lVar3 * lVar4 + (longdouble)local_40.y);
      local_28[0].z = (vec_t)(lVar7 * lVar4 + (longdouble)local_40.z);
      UTIL_TraceLine(&local_40,local_28,ignore_monsters,
                     ((this->super_CBeam).super_CBaseEntity.pev)->pContainingEntity,&local_78);
      if (local_78.flFraction != 1.0) {
        fVar8 = (local_b0.vecEndPos.z - local_78.vecEndPos.z) *
                (local_b0.vecEndPos.z - local_78.vecEndPos.z) +
                (local_b0.vecEndPos.y - local_78.vecEndPos.y) *
                (local_b0.vecEndPos.y - local_78.vecEndPos.y) +
                (local_b0.vecEndPos.x - local_78.vecEndPos.x) *
                (local_b0.vecEndPos.x - local_78.vecEndPos.x);
        fVar10 = SQRT(fVar8);
        if (NAN(fVar10)) {
          fVar10 = sqrtf(fVar8);
        }
        if (this->m_radius * 0.1 <= fVar10) {
          vecEnd = &local_78.vecEndPos;
          this_00 = (CLightning *)&local_b0.vecEndPos;
          vecDest = (Vector *)0x1;
          UTIL_TraceLine((Vector *)this_00,vecEnd,ignore_monsters,
                         ((this->super_CBeam).super_CBaseEntity.pev)->pContainingEntity,&local_78);
          if (local_78.flFraction == 1.0) {
            Zap(this_00,vecEnd,vecDest);
            return;
          }
        }
      }
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// CLightning::RandomPoint  @ 000ce4f0  (line 855)

/* DWARF original prototype: void RandomPoint(CLightning * this, Vector * vecSrc) */

void __thiscall CLightning::RandomPoint(CLightning *this,Vector *vecSrc)

{
  float fVar1;
  float fVar2;
  int iVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  float fVar9;
  CLightning *this_00;
  CLightning *__x;
  Vector *vecSrc_00;
  Vector *vecDest;
  TraceResult local_6c;
  Vector local_28 [2];
  
  iVar3 = 10;
  while( true ) {
                    /* Unresolved local var: int iLoops@[???]
                       Unresolved local var: Vector vecDir1@[???]
                       Unresolved local var: TraceResult tr1@[???] */
    lVar4 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
    lVar5 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
    lVar6 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
                    /* Unresolved local var: float flLen@[???] */
    lVar7 = (longdouble)(float)lVar5;
    lVar8 = (longdouble)(float)lVar4;
    lVar8 = lVar8 * lVar8 + lVar7 * lVar7 + lVar6 * lVar6;
    lVar7 = SQRT(lVar8);
    if (NAN(lVar7)) {
      fVar9 = sqrtf((float)lVar8);
      lVar7 = (longdouble)fVar9;
      lVar6 = (longdouble)(float)lVar6;
    }
    lVar8 = (longdouble)0;
    if (lVar7 == lVar8) {
      lVar4 = (longdouble)1;
      lVar5 = lVar8;
    }
    else {
      lVar7 = (longdouble)1.0 / lVar7;
      lVar4 = (longdouble)(float)lVar4 * lVar7;
      lVar8 = (longdouble)(float)lVar5 * lVar7;
      lVar5 = lVar7 * lVar6;
    }
    lVar7 = (longdouble)this->m_radius;
    vecDest = (Vector *)0x1;
    local_28[0].x = (vec_t)(lVar5 * lVar7 + (longdouble)vecSrc->x);
    local_28[0].y = (vec_t)(lVar8 * lVar7 + (longdouble)vecSrc->y);
    local_28[0].z = (vec_t)(lVar4 * lVar7 + (longdouble)vecSrc->z);
    this_00 = (CLightning *)vecSrc;
    vecSrc_00 = local_28;
    UTIL_TraceLine(vecSrc,local_28,ignore_monsters,
                   ((this->super_CBeam).super_CBaseEntity.pev)->pContainingEntity,&local_6c);
    fVar9 = local_6c.vecEndPos.z - vecSrc->z;
    fVar2 = local_6c.vecEndPos.y - vecSrc->y;
    fVar1 = local_6c.vecEndPos.x - vecSrc->x;
    __x = (CLightning *)(fVar9 * fVar9 + fVar2 * fVar2 + fVar1 * fVar1);
    fVar9 = SQRT((float)__x);
    if (NAN(fVar9)) {
      fVar9 = sqrtf((float)__x);
      this_00 = __x;
    }
    if ((this->m_radius * 0.1 <= fVar9) && (local_6c.flFraction != 1.0)) break;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return;
    }
  }
  Zap(this_00,vecSrc_00,vecDest);
  return;
}


// CLightning::BeamUpdateVars  @ 000ced50  (line 879)

/* WARNING: Variable defined which should be unmapped: pointStart */
/* DWARF original prototype: void BeamUpdateVars(CLightning * this) */

void __thiscall CLightning::BeamUpdateVars(CLightning *this)

{
  int *piVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  edict_t *peVar4;
  uint uVar5;
  edict_t *peVar6;
  CBaseEntity *pCVar7;
  int iVar8;
  int iVar9;
  edict_t *peVar10;
  int pointStart;
  
                    /* Unresolved local var: int beamType@[???]
                       Unresolved local var: int pointEnd@[???]
                       Unresolved local var: edict_t * pStart@[???]
                       Unresolved local var: edict_t * pEnd@[???] */
  peVar3 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_iszStartEntity);
  peVar4 = (*g_engfuncs.pfnFindEntityByString)
                     ((edict_t *)0x0,"targetname",gpGlobals->pStringBase + this->m_iszEndEntity);
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg0(EAX)] */
  peVar6 = peVar3;
  if ((peVar3 == (edict_t *)0x0) &&
     (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 == (edict_t *)0x0)) {
    pCVar7 = (CBaseEntity *)0x0;
  }
  else {
    pCVar7 = peVar6->pvPrivateData;
  }
  iVar9 = 1;
  if (pCVar7->pev->modelindex != 0) {
    iVar9 = IsPointEntity(pCVar7);
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg0(EAX)] */
  peVar6 = peVar4;
  if ((peVar4 == (edict_t *)0x0) &&
     (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 == (edict_t *)0x0)) {
    pCVar7 = (CBaseEntity *)0x0;
  }
  else {
    pCVar7 = peVar6->pvPrivateData;
  }
  iVar8 = 1;
  if (pCVar7->pev->modelindex != 0) {
    iVar8 = IsPointEntity(pCVar7);
  }
  ((this->super_CBeam).super_CBaseEntity.pev)->skin = 0;
  ((this->super_CBeam).super_CBaseEntity.pev)->sequence = 0;
  ((this->super_CBeam).super_CBaseEntity.pev)->rendermode = 0;
  piVar1 = &((this->super_CBeam).super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 | 0x20000000;
  ((this->super_CBeam).super_CBaseEntity.pev)->model = this->m_iszSpriteName;
  ((this->super_CBeam).super_CBaseEntity.pev)->modelindex = this->m_spriteTexture;
  if (iVar8 == 0 && iVar9 == 0) {
    peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
    peVar2->rendermode = peVar2->rendermode & 0xf0U | 2;
    uVar5 = (*g_engfuncs.pfnIndexOfEdict)(peVar3);
    peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
    peVar2->sequence = uVar5 & 0xfff | (peVar2->sequence & 0xf000U) << 0xc;
    peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
    peVar6 = (*g_engfuncs.pfnPEntityOfEntIndex)(uVar5);
    peVar2->owner = peVar6;
  }
  else {
    peVar6 = peVar4;
    peVar10 = peVar3;
    if ((iVar9 != 0) && (peVar6 = peVar3, peVar10 = peVar4, iVar8 != 0)) {
      piVar1 = &((this->super_CBeam).super_CBaseEntity.pev)->rendermode;
      *piVar1 = *piVar1 & 0xf0;
      peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
      (peVar2->origin).x = (peVar3->v).origin.x;
      (peVar2->origin).y = (peVar3->v).origin.y;
      (peVar2->origin).z = (peVar3->v).origin.z;
      peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
      (peVar2->angles).x = (peVar4->v).origin.x;
      (peVar2->angles).y = (peVar4->v).origin.y;
      (peVar2->angles).z = (peVar4->v).origin.z;
      goto LAB_000cef31;
    }
    peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
    peVar2->rendermode = peVar2->rendermode & 0xf0U | 1;
    peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
    (peVar2->origin).x = (peVar6->v).origin.x;
    (peVar2->origin).y = (peVar6->v).origin.y;
    (peVar2->origin).z = (peVar6->v).origin.z;
    peVar4 = peVar10;
  }
  uVar5 = (*g_engfuncs.pfnIndexOfEdict)(peVar4);
  peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
  peVar2->skin = uVar5 & 0xfff | (peVar2->skin & 0xf000U) << 0xc;
  peVar2 = (this->super_CBeam).super_CBaseEntity.pev;
  peVar6 = (*g_engfuncs.pfnPEntityOfEntIndex)(uVar5);
  peVar2->aiment = peVar6;
LAB_000cef31:
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


// env_laser  @ 000cf0a0  (line 943)

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
  *puVar1 = &PTR__CLaser_0017d348;
  puVar1[1] = pev;
  return;
}


// CLaser::Restore  @ 000ca480  (line 952)

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


// CLaser::Save  @ 000ca6c0  (line 952)

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


// CLaser::Spawn  @ 000ccf50  (line 955)

/* DWARF original prototype: void Spawn(CLaser * this) */

void __thiscall CLaser::Spawn(CLaser *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  char *pcVar7;
  edict_t *peVar8;
  entvars_t *peVar9;
  CSprite *pCVar10;
  globalvars_t *pgVar11;
  entvars_t *peVar12;
  
  peVar9 = (this->super_CBeam).super_CBaseEntity.pev;
  if (peVar9->model == 0) {
    (this->super_CBeam).super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    (this->super_CBeam).super_CBaseEntity.m_pfnThink.__delta = 0;
  }
  else {
    peVar9->solid = 0;
    (*(this->super_CBeam).super_CBaseEntity._vptr_CBaseEntity[3])(this);
    peVar9 = (this->super_CBeam).super_CBaseEntity.pev;
    (this->super_CBeam).super_CBaseEntity.m_pfnThink.__pfn = StrikeThink;
    (this->super_CBeam).super_CBaseEntity.m_pfnThink.__delta = 0;
    piVar1 = &peVar9->flags;
    *piVar1 = *piVar1 | 0x20000000;
    peVar9 = (this->super_CBeam).super_CBaseEntity.pev;
    peVar9->rendermode = peVar9->rendermode & 0xf0;
    peVar12 = (this->super_CBeam).super_CBaseEntity.pev;
    (peVar12->origin).x = (peVar9->origin).x;
    (peVar12->origin).y = (peVar9->origin).y;
    (peVar12->origin).z = (peVar9->origin).z;
    peVar12 = (this->super_CBeam).super_CBaseEntity.pev;
    (peVar12->angles).x = (peVar9->origin).x;
    (peVar12->angles).y = (peVar9->origin).y;
    (peVar12->angles).z = (peVar9->origin).z;
    piVar1 = &((this->super_CBeam).super_CBaseEntity.pev)->sequence;
    *piVar1 = *piVar1 & 0xfff;
    piVar1 = &((this->super_CBeam).super_CBaseEntity.pev)->skin;
    *piVar1 = *piVar1 & 0xfff;
    CBeam::RelinkBeam(&this->super_CBeam);
    if ((this->m_pSprite == (CSprite *)0x0) && (iVar6 = this->m_iszSpriteName, iVar6 != 0)) {
                    /* Unresolved local var: CSprite * pSprite@[DW_OP_reg6(ESI)]
                       Unresolved local var: entvars_t * pev@[???] */
      peVar9 = (this->super_CBeam).super_CBaseEntity.pev;
      pcVar7 = gpGlobals->pStringBase;
      peVar8 = (*g_engfuncs.pfnCreateEntity)();
      peVar12 = (entvars_t *)0x0;
      if (peVar8 != (edict_t *)0x0) {
        peVar12 = &peVar8->v;
      }
      if ((peVar12->pContainingEntity == (edict_t *)0x0) ||
         (pCVar10 = peVar12->pContainingEntity->pvPrivateData, pCVar10 == (CSprite *)0x0)) {
        pCVar10 = CBaseEntity::operator_new(0x47c,peVar12);
        (pCVar10->super_CPointEntity).super_CBaseEntity._vptr_CBaseEntity =
             (_func_int_varargs **)&PTR__CSprite_0017d588;
        (pCVar10->super_CPointEntity).super_CBaseEntity.pev = peVar12;
      }
      else {
        peVar12 = (pCVar10->super_CPointEntity).super_CBaseEntity.pev;
      }
      peVar12->model = (string_t)(pcVar7 + (iVar6 - (int)gpGlobals->pStringBase));
      peVar12 = (pCVar10->super_CPointEntity).super_CBaseEntity.pev;
      (peVar12->origin).x = (peVar9->origin).x;
      (peVar12->origin).y = (peVar9->origin).y;
      (peVar12->origin).z = (peVar9->origin).z;
      (*(pCVar10->super_CPointEntity).super_CBaseEntity._vptr_CBaseEntity[2])(pCVar10);
      ((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->classname =
           (int)"env_sprite" - (int)gpGlobals->pStringBase;
      ((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->solid = 0;
      ((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->movetype = 8;
      ((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
      pgVar11 = gpGlobals;
      peVar9 = (pCVar10->super_CPointEntity).super_CBaseEntity.pev;
      if (((peVar9->framerate != 0.0) && (1.0 < pCVar10->m_maxFrame)) ||
         ((peVar9->spawnflags & 2) != 0)) {
        (pCVar10->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = CSprite::AnimateThink;
        (pCVar10->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
        peVar9->nextthink = pgVar11->time;
        pCVar10->m_lastTime = pgVar11->time;
        peVar9 = (pCVar10->super_CPointEntity).super_CBaseEntity.pev;
      }
      peVar9->frame = 0.0;
      peVar9 = (this->super_CBeam).super_CBaseEntity.pev;
      this->m_pSprite = pCVar10;
      iVar6 = peVar9->renderfx;
      fVar2 = (peVar9->rendercolor).y;
      fVar3 = (peVar9->rendercolor).z;
      fVar4 = (peVar9->rendercolor).x;
      fVar5 = peVar9->renderamt;
      ((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->rendermode = 3;
      (((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).x = (float)(int)fVar4;
      (((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).y = (float)(int)fVar2;
      (((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).z = (float)(int)fVar3;
      ((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->renderamt = (float)(int)fVar5;
      ((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->renderfx = iVar6;
    }
    else {
      this->m_pSprite = (CSprite *)0x0;
    }
    peVar9 = (this->super_CBeam).super_CBaseEntity.pev;
    if ((peVar9->targetname == 0) || ((peVar9->spawnflags & 1) != 0)) {
      peVar9->effects = peVar9->effects & 0xffffff7f;
      pCVar10 = this->m_pSprite;
      pgVar11 = gpGlobals;
      if (pCVar10 != (CSprite *)0x0) {
        ((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
        pgVar11 = gpGlobals;
        peVar9 = (pCVar10->super_CPointEntity).super_CBaseEntity.pev;
        if (((peVar9->framerate != 0.0) && (1.0 < pCVar10->m_maxFrame)) ||
           ((peVar9->spawnflags & 2) != 0)) {
          (pCVar10->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = CSprite::AnimateThink;
          (pCVar10->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
          peVar9->nextthink = pgVar11->time;
          pCVar10->m_lastTime = pgVar11->time;
          peVar9 = (pCVar10->super_CPointEntity).super_CBaseEntity.pev;
        }
        peVar9->frame = 0.0;
      }
      ((this->super_CBeam).super_CBaseEntity.pev)->dmgtime = pgVar11->time;
      ((this->super_CBeam).super_CBaseEntity.pev)->nextthink = pgVar11->time;
    }
    else {
      peVar9->effects = peVar9->effects | 0x80;
      ((this->super_CBeam).super_CBaseEntity.pev)->nextthink = 0.0;
      pCVar10 = this->m_pSprite;
      if (pCVar10 != (CSprite *)0x0) {
        ((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->effects = 0x80;
        ((pCVar10->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
      }
    }
  }
  return;
}


// CLaser::Precache  @ 000ca1d0  (line 984)

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
                    /* WARNING: Could not recover jumptable at 0x000ca242. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + this->m_iszSpriteName);
  return;
}


// CLaser::KeyValue  @ 000cb790  (line 992)

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


// CLaser::IsOn  @ 000cf110  (line 1040)

/* DWARF original prototype: int IsOn(CLaser * this) */

int __thiscall CLaser::IsOn(CLaser *this)

{
  return (uint)((((this->super_CBeam).super_CBaseEntity.pev)->effects & 0x80) == 0);
}


// CLaser::TurnOff  @ 000cf130  (line 1047)

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


// CLaser::TurnOn  @ 000cf180  (line 1056)

/* DWARF original prototype: void TurnOn(CLaser * this) */

void __thiscall CLaser::TurnOn(CLaser *this)

{
  int *piVar1;
  CSprite *pCVar2;
  globalvars_t *pgVar3;
  entvars_t *peVar4;
  
  pgVar3 = gpGlobals;
  piVar1 = &((this->super_CBeam).super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 & 0xffffff7f;
  pCVar2 = this->m_pSprite;
  if (pCVar2 == (CSprite *)0x0) goto LAB_000cf211;
  ((pCVar2->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
  pgVar3 = gpGlobals;
  peVar4 = (pCVar2->super_CPointEntity).super_CBaseEntity.pev;
  if (NAN(peVar4->framerate)) {
    if (1.0 < pCVar2->m_maxFrame) goto LAB_000cf1e0;
LAB_000cf1d1:
    if ((peVar4->spawnflags & 2) != 0) goto LAB_000cf1e0;
  }
  else {
    if ((peVar4->framerate == 0.0) || (pCVar2->m_maxFrame <= 1.0)) goto LAB_000cf1d1;
LAB_000cf1e0:
    (pCVar2->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = CSprite::AnimateThink;
    (pCVar2->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar4->nextthink = pgVar3->time;
    pCVar2->m_lastTime = pgVar3->time;
    peVar4 = (pCVar2->super_CPointEntity).super_CBaseEntity.pev;
  }
  peVar4->frame = 0.0;
LAB_000cf211:
  ((this->super_CBeam).super_CBaseEntity.pev)->dmgtime = pgVar3->time;
  ((this->super_CBeam).super_CBaseEntity.pev)->nextthink = pgVar3->time;
  return;
}


// CLaser::Use  @ 000cf250  (line 1066)

/* DWARF original prototype: void Use(CLaser * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CLaser::Use(CLaser *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,float value)

{
  int *piVar1;
  CSprite *pCVar2;
  int iVar3;
  uint currentState;
  
                    /* Unresolved local var: int active@[???] */
  currentState = (uint)((((this->super_CBeam).super_CBaseEntity.pev)->effects & 0x80) == 0);
  iVar3 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,currentState);
  if (iVar3 != 0) {
    if (currentState == 0) {
      TurnOn(this);
      return;
    }
    piVar1 = &((this->super_CBeam).super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 0x80;
    ((this->super_CBeam).super_CBaseEntity.pev)->nextthink = 0.0;
    pCVar2 = this->m_pSprite;
    if (pCVar2 != (CSprite *)0x0) {
                    /* Unresolved local var: int active@[???] */
      ((pCVar2->super_CPointEntity).super_CBaseEntity.pev)->effects = 0x80;
      ((pCVar2->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
    }
  }
  return;
}


// CLaser::FireAtPoint  @ 000cf300  (line 1083)

/* DWARF original prototype: void FireAtPoint(CLaser * this, TraceResult * tr) */

void __thiscall CLaser::FireAtPoint(CLaser *this,TraceResult *tr)

{
  uint uVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  entvars_t *peVar4;
  
  peVar4 = (this->super_CBeam).super_CBaseEntity.pev;
  (peVar4->angles).x = (tr->vecEndPos).x;
  (peVar4->angles).y = (tr->vecEndPos).y;
  (peVar4->angles).z = (tr->vecEndPos).z;
  if (this->m_pSprite != (CSprite *)0x0) {
    UTIL_SetOrigin((this->m_pSprite->super_CPointEntity).super_CBaseEntity.pev,&tr->vecEndPos);
  }
  CBeam::BeamDamage(&this->super_CBeam,tr);
  peVar4 = (this->super_CBeam).super_CBaseEntity.pev;
  peVar2 = peVar4;
  if ((peVar4->rendermode & 0xfU) == 2) {
                    /* Unresolved local var: edict_t * pent@[???] */
    peVar3 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar4->sequence & 0xfff);
    peVar4 = (this->super_CBeam).super_CBaseEntity.pev;
    peVar2 = &peVar3->v;
  }
  uVar1 = peVar4->spawnflags;
  if ((uVar1 & 0x30) != 0) {
    if ((uVar1 & 0x10) != 0) {
      UTIL_Sparks(&peVar2->origin);
      uVar1 = ((this->super_CBeam).super_CBaseEntity.pev)->spawnflags;
    }
    if ((uVar1 & 0x20) != 0) {
      UTIL_Sparks(&tr->vecEndPos);
      return;
    }
  }
  return;
}


// CLaser::StrikeThink  @ 000cdd10  (line 1093)

/* DWARF original prototype: void StrikeThink(CLaser * this) */

void __thiscall CLaser::StrikeThink(CLaser *this)

{
  int iVar1;
  string_t sVar2;
  char *pcVar3;
  uint uVar4;
  entvars_t *peVar5;
  int32 iVar6;
  entvars_t *peVar7;
  edict_t *peVar8;
  CBaseEntity *pStartEntity;
  int iVar9;
  CBaseEntity *pCVar10;
  TraceResult local_54;
  
                    /* Unresolved local var: CBaseEntity * pEnd@[???]
                       Unresolved local var: TraceResult tr@[???] */
  pStartEntity = (CBaseEntity *)0x0;
  sVar2 = ((this->super_CBeam).super_CBaseEntity.pev)->message;
  pcVar3 = gpGlobals->pStringBase;
  iVar9 = 0;
  pCVar10 = (CBaseEntity *)0x0;
  while (pStartEntity = UTIL_FindEntityByTargetname(pStartEntity,pcVar3 + sVar2),
        pStartEntity != (CBaseEntity *)0x0) {
                    /* Unresolved local var: int total@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pNewEntity@[???] */
    iVar1 = iVar9 + 1;
    iVar6 = (*g_engfuncs.pfnRandomLong)(0,iVar9);
    iVar9 = iVar1;
    if (iVar6 < 1) {
      pCVar10 = pStartEntity;
    }
  }
  if (pCVar10 != (CBaseEntity *)0x0) {
    peVar7 = pCVar10->pev;
    (this->m_firePosition).x = (peVar7->origin).x;
    (this->m_firePosition).y = (peVar7->origin).y;
    (this->m_firePosition).z = (peVar7->origin).z;
  }
  UTIL_TraceLine(&((this->super_CBeam).super_CBaseEntity.pev)->origin,&this->m_firePosition,
                 dont_ignore_monsters,(edict_t *)0x0,&local_54);
  peVar7 = (this->super_CBeam).super_CBaseEntity.pev;
  (peVar7->angles).x = local_54.vecEndPos.x;
  (peVar7->angles).y = local_54.vecEndPos.y;
  (peVar7->angles).z = local_54.vecEndPos.z;
  if (this->m_pSprite != (CSprite *)0x0) {
    UTIL_SetOrigin((this->m_pSprite->super_CPointEntity).super_CBaseEntity.pev,&local_54.vecEndPos);
  }
  CBeam::BeamDamage(&this->super_CBeam,&local_54);
  peVar7 = (this->super_CBeam).super_CBaseEntity.pev;
  peVar5 = peVar7;
  if ((peVar7->rendermode & 0xfU) == 2) {
                    /* Unresolved local var: edict_t * pent@[???] */
    peVar8 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar7->sequence & 0xfff);
    peVar5 = &peVar8->v;
    peVar7 = (this->super_CBeam).super_CBaseEntity.pev;
  }
  uVar4 = peVar7->spawnflags;
  if ((uVar4 & 0x30) != 0) {
    if ((uVar4 & 0x10) != 0) {
      UTIL_Sparks(&peVar5->origin);
      peVar7 = (this->super_CBeam).super_CBaseEntity.pev;
      uVar4 = peVar7->spawnflags;
    }
    if ((uVar4 & 0x20) != 0) {
      UTIL_Sparks(&local_54.vecEndPos);
      peVar7 = (this->super_CBeam).super_CBaseEntity.pev;
    }
  }
  peVar7->nextthink = gpGlobals->time + 0.1;
  return;
}


// env_glow  @ 000cf3d0  (line 1122)

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
  *puVar1 = &PTR__CGlow_0017d468;
  puVar1[1] = pev;
  return;
}


// CGlow::Restore  @ 000ca420  (line 1130)

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


// CGlow::Save  @ 000ca660  (line 1130)

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


// CGlow::Spawn  @ 000c97d0  (line 1133)

/* DWARF original prototype: void Spawn(CGlow * this) */

void __thiscall CGlow::Spawn(CGlow *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  int iVar3;
  globalvars_t *pgVar4;
  
  ((this->super_CPointEntity).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->frame = 0.0;
  (*g_engfuncs.pfnPrecacheModel)
            (gpGlobals->pStringBase + ((this->super_CPointEntity).super_CBaseEntity.pev)->model);
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar1->pContainingEntity,gpGlobals->pStringBase + peVar1->model);
  iVar3 = (*g_engfuncs.pfnModelFrames)
                    (((this->super_CPointEntity).super_CBaseEntity.pev)->modelindex);
  pgVar4 = gpGlobals;
  this->m_maxFrame = (float)iVar3 - 1.0;
  pgVar2 = gpGlobals;
  if (1.0 < (float)iVar3 - 1.0) {
    peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
    pgVar4 = pgVar2;
    if (NAN(peVar1->framerate)) {
      peVar1->nextthink = gpGlobals->time + 0.1;
    }
    else if (peVar1->framerate != 0.0) {
      peVar1->nextthink = gpGlobals->time + 0.1;
    }
  }
  this->m_lastTime = pgVar4->time;
  return;
}


// CGlow::Think  @ 000cadf0  (line 1151)

/* DWARF original prototype: void Think(CGlow * this) */

void __thiscall CGlow::Think(CGlow *this)

{
  globalvars_t *pgVar1;
  entvars_t *peVar2;
  ushort in_FPUStatusWord;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  double dVar6;
  
  peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
  lVar3 = (longdouble)gpGlobals->time;
  lVar4 = (longdouble)this->m_maxFrame;
  pgVar1 = gpGlobals;
  if ((longdouble)0 < lVar4) {
    lVar3 = lVar3 - (longdouble)this->m_lastTime;
    lVar5 = (longdouble)peVar2->framerate * lVar3 + (longdouble)peVar2->frame;
    do {
      lVar5 = lVar5 - (longdouble)(unkint10)(lVar5 / lVar4) * lVar4;
    } while ((in_FPUStatusWord & 0x400) != 0);
    if (NAN(lVar5)) {
      dVar6 = fmod((double)(lVar3 * (longdouble)peVar2->framerate + (longdouble)peVar2->frame),
                   (double)this->m_maxFrame);
      lVar5 = (longdouble)dVar6;
    }
    pgVar1 = gpGlobals;
    peVar2->frame = (float)lVar5;
    peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
    lVar3 = (longdouble)pgVar1->time;
  }
  peVar2->nextthink = (float)((longdouble)0.1 + lVar3);
  this->m_lastTime = pgVar1->time;
  return;
}


// CGlow::Animate  @ 000cf440  (line 1160)

/* DWARF original prototype: void Animate(CGlow * this, float frames) */

void __thiscall CGlow::Animate(CGlow *this,float frames)

{
  entvars_t *peVar1;
  ushort in_FPUStatusWord;
  longdouble lVar2;
  longdouble lVar3;
  double dVar4;
  
  lVar2 = (longdouble)this->m_maxFrame;
  if ((longdouble)0 < lVar2) {
    peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
    lVar3 = (longdouble)frames + (longdouble)peVar1->frame;
    do {
      lVar3 = lVar3 - (longdouble)(unkint10)(lVar3 / lVar2) * lVar2;
    } while ((in_FPUStatusWord & 0x400) != 0);
    if (NAN(lVar3)) {
      dVar4 = fmod((double)(frames + peVar1->frame),(double)this->m_maxFrame);
      lVar3 = (longdouble)dVar4;
    }
    peVar1->frame = (float)lVar3;
    return;
  }
  return;
}


// env_sprite  @ 000cf4b0  (line 1166)

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
  *puVar1 = &PTR__CSprite_0017d588;
  puVar1[1] = pev;
  return;
}


// CSprite::Restore  @ 000ca3c0  (line 1174)

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


// CSprite::Save  @ 000ca600  (line 1174)

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


// CSprite::Spawn  @ 000cc4c0  (line 1177)

/* DWARF original prototype: void Spawn(CSprite * this) */

void __thiscall CSprite::Spawn(CSprite *this)

{
  float fVar1;
  globalvars_t *pgVar2;
  int iVar3;
  entvars_t *peVar4;
  
  ((this->super_CPointEntity).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->frame = 0.0;
  (*(this->super_CPointEntity).super_CBaseEntity._vptr_CBaseEntity[3])(this);
  peVar4 = (this->super_CPointEntity).super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar4->pContainingEntity,gpGlobals->pStringBase + peVar4->model);
  iVar3 = (*g_engfuncs.pfnModelFrames)
                    (((this->super_CPointEntity).super_CBaseEntity.pev)->modelindex);
  peVar4 = (this->super_CPointEntity).super_CBaseEntity.pev;
  this->m_maxFrame = (float)iVar3 - 1.0;
  if ((peVar4->targetname != 0) && ((peVar4->spawnflags & 1) == 0)) {
    peVar4->effects = 0x80;
    ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
    peVar4 = (this->super_CPointEntity).super_CBaseEntity.pev;
    fVar1 = (peVar4->angles).y;
    goto code_r0x000cc64b;
  }
  peVar4->effects = 0;
  pgVar2 = gpGlobals;
  peVar4 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if (NAN(peVar4->framerate)) {
    if (1.0 < this->m_maxFrame) goto LAB_000cc60c;
LAB_000cc603:
    if ((peVar4->spawnflags & 2) != 0) goto LAB_000cc60c;
  }
  else {
    if ((peVar4->framerate == 0.0) || (this->m_maxFrame <= 1.0)) goto LAB_000cc603;
LAB_000cc60c:
    (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = AnimateThink;
    (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar4->nextthink = pgVar2->time;
    this->m_lastTime = pgVar2->time;
    peVar4 = (this->super_CPointEntity).super_CBaseEntity.pev;
  }
  peVar4->frame = 0.0;
  peVar4 = (this->super_CPointEntity).super_CBaseEntity.pev;
  fVar1 = (peVar4->angles).y;
code_r0x000cc64b:
  if (fVar1 != 0.0) {
    if ((peVar4->angles).z == 0.0) {
      (peVar4->angles).z = fVar1;
      (((this->super_CPointEntity).super_CBaseEntity.pev)->angles).y = 0.0;
    }
    return;
  }
  return;
}


// CSprite::Precache  @ 000caac0  (line 1202)

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


// CSprite::SpriteInit  @ 000cf520  (line 1218)

/* DWARF original prototype: void SpriteInit(CSprite * this, char * pSpriteName, Vector * origin) */

void __thiscall CSprite::SpriteInit(CSprite *this,char *pSpriteName,Vector *origin)

{
  entvars_t *peVar1;
  
  ((this->super_CPointEntity).super_CBaseEntity.pev)->model =
       (int)pSpriteName - (int)gpGlobals->pStringBase;
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  (peVar1->origin).x = origin->x;
  (peVar1->origin).y = origin->y;
  (peVar1->origin).z = origin->z;
                    /* WARNING: Could not recover jumptable at 0x000cf56e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CPointEntity).super_CBaseEntity._vptr_CBaseEntity[2])();
  return;
}


// CSprite::SpriteCreate  @ 000cf570  (line 1225)

CSprite * CSprite::SpriteCreate(char *pSpriteName,Vector *origin,BOOL animate)

{
  globalvars_t *pgVar1;
  edict_t *peVar2;
  entvars_t *peVar3;
  CSprite *pCVar4;
  
                    /* Unresolved local var: CSprite * pSprite@[DW_OP_reg7(EDI)]
                       Unresolved local var: entvars_t * pev@[???] */
  peVar2 = (*g_engfuncs.pfnCreateEntity)();
  peVar3 = (entvars_t *)0x0;
  if (peVar2 != (edict_t *)0x0) {
    peVar3 = &peVar2->v;
  }
  if ((peVar3->pContainingEntity == (edict_t *)0x0) ||
     (pCVar4 = peVar3->pContainingEntity->pvPrivateData, pCVar4 == (CSprite *)0x0)) {
    pCVar4 = CBaseEntity::operator_new(0x47c,peVar3);
    (pCVar4->super_CPointEntity).super_CBaseEntity._vptr_CBaseEntity =
         (_func_int_varargs **)&PTR__CSprite_0017d588;
    (pCVar4->super_CPointEntity).super_CBaseEntity.pev = peVar3;
  }
  else {
    peVar3 = (pCVar4->super_CPointEntity).super_CBaseEntity.pev;
  }
  peVar3->model = (int)pSpriteName - (int)gpGlobals->pStringBase;
  peVar3 = (pCVar4->super_CPointEntity).super_CBaseEntity.pev;
  (peVar3->origin).x = origin->x;
  (peVar3->origin).y = origin->y;
  (peVar3->origin).z = origin->z;
  (*(pCVar4->super_CPointEntity).super_CBaseEntity._vptr_CBaseEntity[2])(pCVar4);
  ((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->classname =
       (int)"env_sprite" - (int)gpGlobals->pStringBase;
  ((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->solid = 0;
  ((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->movetype = 8;
  if (animate != 0) {
    ((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
    pgVar1 = gpGlobals;
    peVar3 = (pCVar4->super_CPointEntity).super_CBaseEntity.pev;
    if (((peVar3->framerate != 0.0) && (1.0 < pCVar4->m_maxFrame)) ||
       ((peVar3->spawnflags & 2) != 0)) {
      (pCVar4->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = AnimateThink;
      (pCVar4->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
      peVar3->nextthink = pgVar1->time;
      pCVar4->m_lastTime = pgVar1->time;
      peVar3 = (pCVar4->super_CPointEntity).super_CBaseEntity.pev;
    }
    peVar3->frame = 0.0;
    return pCVar4;
  }
  return pCVar4;
}


// CSprite::AnimateThink  @ 000cbd60  (line 1239)

/* DWARF original prototype: void AnimateThink(CSprite * this) */

void __thiscall CSprite::AnimateThink(CSprite *this)

{
  globalvars_t *pgVar1;
  entvars_t *peVar2;
  ushort in_FPUStatusWord;
  longdouble lVar3;
  longdouble lVar4;
  double dVar5;
  
  pgVar1 = gpGlobals;
  peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
  peVar2->frame = (gpGlobals->time - this->m_lastTime) * peVar2->framerate + peVar2->frame;
  peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
  lVar3 = (longdouble)peVar2->frame;
  lVar4 = (longdouble)this->m_maxFrame;
  if (lVar4 < lVar3) {
    if ((peVar2->spawnflags & 2) == 0) {
      if ((longdouble)0 < lVar4) {
        do {
          lVar3 = lVar3 - (longdouble)(unkint10)(lVar3 / lVar4) * lVar4;
        } while ((in_FPUStatusWord & 0x400) != 0);
        if (NAN(lVar3)) {
          dVar5 = fmod((double)peVar2->frame,(double)this->m_maxFrame);
          lVar3 = (longdouble)dVar5;
          pgVar1 = gpGlobals;
        }
        peVar2->frame = (float)lVar3;
        peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
      }
    }
    else {
      peVar2->effects = 0x80;
      ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
      peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
    }
  }
  peVar2->nextthink = pgVar1->time + 0.1;
  this->m_lastTime = pgVar1->time;
  return;
}


// CSprite::AnimateUntilDead  @ 000cf6c0  (line 1247)

/* DWARF original prototype: void AnimateUntilDead(CSprite * this) */

void __thiscall CSprite::AnimateUntilDead(CSprite *this)

{
  globalvars_t *pgVar1;
  entvars_t *peVar2;
  ushort in_FPUStatusWord;
  longdouble lVar3;
  longdouble lVar4;
  double dVar5;
  
  pgVar1 = gpGlobals;
  peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if (peVar2->dmgtime < gpGlobals->time) {
    UTIL_Remove((CBaseEntity *)this);
    return;
  }
  peVar2->frame = (gpGlobals->time - this->m_lastTime) * peVar2->framerate + peVar2->frame;
  peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
  lVar3 = (longdouble)peVar2->frame;
  lVar4 = (longdouble)this->m_maxFrame;
  if (lVar4 < lVar3) {
    if ((peVar2->spawnflags & 2) == 0) {
      if ((longdouble)0 < lVar4) {
        do {
          lVar3 = lVar3 - (longdouble)(unkint10)(lVar3 / lVar4) * lVar4;
        } while ((in_FPUStatusWord & 0x400) != 0);
        if (NAN(lVar3)) {
          dVar5 = fmod((double)peVar2->frame,(double)this->m_maxFrame);
          lVar3 = (longdouble)dVar5;
          pgVar1 = gpGlobals;
        }
        peVar2->frame = (float)lVar3;
        peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
      }
    }
    else {
      peVar2->effects = 0x80;
      ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
      peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
    }
  }
  peVar2->nextthink = pgVar1->time + 0.1;
  this->m_lastTime = pgVar1->time;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = pgVar1->time;
  return;
}


// CSprite::Expand  @ 000cf7d0  (line 1258)

/* DWARF original prototype: void Expand(CSprite * this, float scaleSpeed, float fadeSpeed) */

void __thiscall CSprite::Expand(CSprite *this,float scaleSpeed,float fadeSpeed)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  
  ((this->super_CPointEntity).super_CBaseEntity.pev)->speed = scaleSpeed;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->health = fadeSpeed;
  pgVar2 = gpGlobals;
  (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = ExpandThink;
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar1->nextthink = pgVar2->time;
  this->m_lastTime = pgVar2->time;
  return;
}


// CSprite::ExpandThink  @ 000ca2e0  (line 1269)

/* DWARF original prototype: void ExpandThink(CSprite * this) */

void __thiscall CSprite::ExpandThink(CSprite *this)

{
  entvars_t *peVar1;
  float fVar2;
  globalvars_t *pgVar3;
  
  pgVar3 = gpGlobals;
                    /* Unresolved local var: float frametime@[???] */
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  fVar2 = gpGlobals->time - this->m_lastTime;
  peVar1->scale = peVar1->speed * fVar2 + peVar1->scale;
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  peVar1->renderamt = peVar1->renderamt - fVar2 * peVar1->health;
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if (0.0 < peVar1->renderamt) {
    peVar1->nextthink = pgVar3->time + 0.1;
    this->m_lastTime = pgVar3->time;
    return;
  }
                    /* Unresolved local var: float frametime@[???] */
  peVar1->renderamt = 0.0;
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CSprite::Animate  @ 000cf820  (line 1287)

/* DWARF original prototype: void Animate(CSprite * this, float frames) */

void __thiscall CSprite::Animate(CSprite *this,float frames)

{
  entvars_t *peVar1;
  ushort in_FPUStatusWord;
  longdouble lVar2;
  longdouble lVar3;
  double dVar4;
  
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  peVar1->frame = peVar1->frame + frames;
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  lVar2 = (longdouble)peVar1->frame;
  lVar3 = (longdouble)this->m_maxFrame;
  if (lVar3 < lVar2) {
    if ((peVar1->spawnflags & 2) != 0) {
      peVar1->effects = 0x80;
      ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
      return;
    }
    if ((longdouble)0 < lVar3) {
      do {
        lVar2 = lVar2 - (longdouble)(unkint10)(lVar2 / lVar3) * lVar3;
      } while ((in_FPUStatusWord & 0x400) != 0);
      if (NAN(lVar2)) {
        dVar4 = fmod((double)peVar1->frame,(double)this->m_maxFrame);
        lVar2 = (longdouble)dVar4;
      }
      peVar1->frame = (float)lVar2;
      return;
    }
  }
  return;
}


// CSprite::TurnOff  @ 000cf8e0  (line 1305)

/* DWARF original prototype: void TurnOff(CSprite * this) */

void __thiscall CSprite::TurnOff(CSprite *this)

{
  ((this->super_CPointEntity).super_CBaseEntity.pev)->effects = 0x80;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
  return;
}


// CSprite::TurnOn  @ 000cf900  (line 1312)

/* DWARF original prototype: void TurnOn(CSprite * this) */

void __thiscall CSprite::TurnOn(CSprite *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  
  ((this->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
  pgVar2 = gpGlobals;
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if (((peVar1->framerate == 0.0) || (this->m_maxFrame <= 1.0)) && ((peVar1->spawnflags & 2) == 0))
  {
    peVar1->frame = 0.0;
    return;
  }
  (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = AnimateThink;
  (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar1->nextthink = pgVar2->time;
  this->m_lastTime = pgVar2->time;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->frame = 0.0;
  return;
}


// CSprite::Use  @ 000cc680  (line 1325)

/* DWARF original prototype: void Use(CSprite * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CSprite::Use(CSprite *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,float value
            )

{
  globalvars_t *pgVar1;
  int iVar2;
  entvars_t *peVar3;
  uint currentState;
  
                    /* Unresolved local var: int on@[???] */
  currentState = (uint)(((this->super_CPointEntity).super_CBaseEntity.pev)->effects != 0x80);
  iVar2 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,currentState);
  if (iVar2 != 0) {
                    /* Unresolved local var: int on@[???] */
    peVar3 = (this->super_CPointEntity).super_CBaseEntity.pev;
    if (currentState == 0) {
      peVar3->effects = 0;
      pgVar1 = gpGlobals;
      peVar3 = (this->super_CPointEntity).super_CBaseEntity.pev;
      if (((peVar3->framerate != 0.0) && (1.0 < this->m_maxFrame)) ||
         ((peVar3->spawnflags & 2) != 0)) {
        (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = AnimateThink;
        (this->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
        peVar3->nextthink = pgVar1->time;
        this->m_lastTime = pgVar1->time;
        peVar3 = (this->super_CPointEntity).super_CBaseEntity.pev;
      }
      peVar3->frame = 0.0;
      return;
    }
    peVar3->effects = 0x80;
    ((this->super_CPointEntity).super_CBaseEntity.pev)->nextthink = 0.0;
  }
  return;
}


// CGibShooter::Restore  @ 000ca360  (line 1376)

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


// CGibShooter::Save  @ 000ca5a0  (line 1376)

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


// gibshooter  @ 000cf990  (line 1377)

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
  *puVar1 = &PTR__CGibShooter_0017d6a8;
  puVar1[1] = pev;
  return;
}


// CGibShooter::Precache  @ 000ca250  (line 1381)

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


// CGibShooter::KeyValue  @ 000cb100  (line 1394)

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


// CGibShooter::Use  @ 000c98e0  (line 1422)

/* DWARF original prototype: void Use(CGibShooter * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CGibShooter::Use(CGibShooter *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
                float value)

{
  globalvars_t *pgVar1;
  
  pgVar1 = gpGlobals;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__pfn = ShootThink;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__delta = 0;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->nextthink = pgVar1->time;
  return;
}


// CGibShooter::Spawn  @ 000ca000  (line 1428)

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


// CGibShooter::CreateGib  @ 000cace0  (line 1450)

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
  this_00 = (CGib *)0x0;
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
      (this_00->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CGib_0017af88;
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
  }
  return this_00;
}


// CGibShooter::ShootThink  @ 000cbe40  (line 1470)

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
  globalvars_t *pgVar12;
  int iVar13;
  longdouble extraout_ST0;
  longdouble lVar14;
  longdouble extraout_ST0_00;
  longdouble lVar15;
  longdouble extraout_ST0_01;
  longdouble lVar16;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  longdouble extraout_ST0_04;
  longdouble lVar17;
  longdouble lVar18;
  float fVar19;
  
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
  lVar18 = (longdouble)
           (float)((longdouble)
                   (float)((longdouble)fVar4 * extraout_ST0 * lVar14 + (longdouble)fVar2) +
                  (longdouble)fVar7 * extraout_ST0_00 * lVar15) +
           (longdouble)(gpGlobals->v_up).z * extraout_ST0_01 * lVar16;
  lVar17 = (longdouble)
           (float)((longdouble)
                   (float)((longdouble)fVar3 * extraout_ST0 * lVar14 + (longdouble)fVar1) +
                  (longdouble)fVar6 * extraout_ST0_00 * lVar15) +
           (longdouble)(gpGlobals->v_up).y * extraout_ST0_01 * lVar16;
  lVar15 = (longdouble)
           (float)((longdouble)
                   (float)((longdouble)fVar5 * extraout_ST0 * lVar14 + (longdouble)fVar19) +
                  extraout_ST0_00 * (longdouble)fVar8 * lVar15) +
           extraout_ST0_01 * (longdouble)(gpGlobals->v_up).x * lVar16;
                    /* Unresolved local var: float flLen@[???] */
  lVar16 = lVar18 * lVar18 + lVar17 * lVar17 + lVar15 * lVar15;
  lVar14 = SQRT(lVar16);
  if (NAN(lVar14)) {
    fVar19 = sqrtf((float)lVar16);
    lVar14 = (longdouble)fVar19;
    lVar18 = (longdouble)(float)lVar18;
    lVar17 = (longdouble)(float)lVar17;
    lVar15 = (longdouble)(float)lVar15;
  }
  lVar16 = (longdouble)0;
  if (lVar14 == lVar16) {
    lVar18 = (longdouble)1;
    lVar14 = lVar16;
  }
  else {
    lVar14 = (longdouble)1.0 / lVar14;
    lVar18 = lVar18 * lVar14;
    lVar16 = lVar14 * lVar15;
    lVar14 = lVar17 * lVar14;
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
    *(float *)(iVar11 + 0x20) = (float)lVar16 * fVar19;
    *(float *)(iVar11 + 0x24) = (float)lVar14 * fVar19;
    *(float *)(iVar11 + 0x28) = (float)lVar18 * fVar19;
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
    lVar18 = extraout_ST0_04 * (longdouble)fVar2;
    *(float *)(iVar13 + 0x480) = (float)lVar18;
    if (lVar18 < (longdouble)(fVar19 - fVar1)) {
      *(float *)(*(int *)(iVar13 + 4) + 0x104) = (float)(lVar18 + (longdouble)gpGlobals->time);
      *(undefined4 *)(iVar13 + 0x480) = 0;
    }
  }
  iVar13 = this->m_iGibs + -1;
  this->m_iGibs = iVar13;
  if (0 < iVar13) {
    return;
  }
  peVar10 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  if ((peVar10->spawnflags & 1) == 0) {
    (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__delta = 0;
    pgVar12 = gpGlobals;
    (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
    peVar10->nextthink = pgVar12->time;
    return;
  }
  iVar13 = this->m_iGibCapacity;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__delta = 0;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  this->m_iGibs = iVar13;
  peVar10->nextthink = gpGlobals->time;
  return;
}


// env_shooter  @ 000cfa00  (line 1528)

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
  *puVar1 = &PTR__CEnvShooter_0017d7c8;
  puVar1[1] = pev;
  return;
}


// CEnvShooter::KeyValue  @ 000cb250  (line 1531)

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
                    /* Unresolved local var: int iNoise@[DW_OP_reg0(EAX)] */
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


// CEnvShooter::Precache  @ 000ca0a0  (line 1573)

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


// CEnvShooter::CreateGib  @ 000caea0  (line 1580)

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
                       Unresolved local var: int bodyPart@[???]
                       Unresolved local var: entvars_t * pev@[???] */
  peVar3 = (*g_engfuncs.pfnCreateEntity)();
  peVar5 = (entvars_t *)0x0;
  if (peVar3 != (edict_t *)0x0) {
    peVar5 = &peVar3->v;
  }
  if ((peVar5->pContainingEntity == (edict_t *)0x0) ||
     (this_00 = peVar5->pContainingEntity->pvPrivateData, this_00 == (CGib *)0x0)) {
    this_00 = CBaseEntity::operator_new(0x484,peVar5);
    (this_00->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CGib_0017af88;
    (this_00->super_CBaseEntity).pev = peVar5;
  }
  CGib::Spawn(this_00,gpGlobals->pStringBase +
                      ((this->super_CGibShooter).super_CBaseDelay.super_CBaseEntity.pev)->model);
  iVar1 = ((this->super_CGibShooter).super_CBaseDelay.super_CBaseEntity.pev)->body;
  iVar4 = 0;
  if (1 < iVar1) {
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


// test_effect  @ 000cfa70  (line 1624)

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
  *puVar1 = &PTR__CTestEffect_0017d8e8;
  puVar1[1] = pev;
  return;
}


// CTestEffect::Spawn  @ 000c9910  (line 1627)

/* DWARF original prototype: void Spawn(CTestEffect * this) */

void __thiscall CTestEffect::Spawn(CTestEffect *this)

{
                    /* WARNING: Could not recover jumptable at 0x000c9919. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[3])();
  return;
}


// CTestEffect::Precache  @ 000c9920  (line 1633)

/* DWARF original prototype: void Precache(CTestEffect * this) */

void __thiscall CTestEffect::Precache(CTestEffect *this)

{
                    /* WARNING: Could not recover jumptable at 0x000c992e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)("sprites/lgtning.spr");
  return;
}


// CTestEffect::TestThink  @ 000cd320  (line 1637)

/* DWARF original prototype: void TestThink(CTestEffect * this) */

void __thiscall CTestEffect::TestThink(CTestEffect *this)

{
  CBeam **ppCVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  edict_t *peVar6;
  CBeam *this_00;
  int iVar7;
  int iVar8;
  globalvars_t *pgVar9;
  entvars_t *peVar10;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble lVar11;
  longdouble lVar12;
  longdouble lVar13;
  longdouble lVar14;
  float fVar15;
  TraceResult local_5c;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float t@[???] */
  iVar7 = this->m_iBeam;
  fVar3 = gpGlobals->time;
  fVar4 = this->m_flStartTime;
  pgVar9 = gpGlobals;
  if (iVar7 < 0x18) {
                    /* Unresolved local var: CBeam * pBeam@[???]
                       Unresolved local var: entvars_t * pev@[???] */
    peVar6 = (*g_engfuncs.pfnCreateEntity)();
    peVar10 = (entvars_t *)0x0;
    if (peVar6 != (edict_t *)0x0) {
      peVar10 = &peVar6->v;
    }
    if ((peVar10->pContainingEntity == (edict_t *)0x0) ||
       (this_00 = peVar10->pContainingEntity->pvPrivateData, this_00 == (CBeam *)0x0)) {
      this_00 = CBaseEntity::operator_new(0x474,peVar10);
      (this_00->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CBeam_0017d108;
      (this_00->super_CBaseEntity).pev = peVar10;
    }
    else {
      peVar10 = (this_00->super_CBaseEntity).pev;
    }
    peVar10->classname = (int)&DAT_0017ccc8 - (int)gpGlobals->pStringBase;
    pgVar9 = gpGlobals;
    piVar2 = &((this_00->super_CBaseEntity).pev)->flags;
    *piVar2 = *piVar2 | 0x20000000;
    (((this_00->super_CBaseEntity).pev)->rendercolor).x = 255.0;
    (((this_00->super_CBaseEntity).pev)->rendercolor).y = 255.0;
    (((this_00->super_CBaseEntity).pev)->rendercolor).z = 255.0;
    ((this_00->super_CBaseEntity).pev)->renderamt = 255.0;
    ((this_00->super_CBaseEntity).pev)->body = 0;
    ((this_00->super_CBaseEntity).pev)->frame = 0.0;
    ((this_00->super_CBaseEntity).pev)->animtime = 0.0;
    ((this_00->super_CBaseEntity).pev)->model =
         (int)"sprites/lgtning.spr" - (int)pgVar9->pStringBase;
    iVar7 = (*g_engfuncs.pfnPrecacheModel)("sprites/lgtning.spr");
    ((this_00->super_CBaseEntity).pev)->modelindex = iVar7;
    ((this_00->super_CBaseEntity).pev)->scale = 100.0;
    ((this_00->super_CBaseEntity).pev)->skin = 0;
    ((this_00->super_CBaseEntity).pev)->sequence = 0;
    ((this_00->super_CBaseEntity).pev)->rendermode = 0;
    peVar10 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    local_24.x = (peVar10->origin).x;
    local_24.y = (peVar10->origin).y;
    local_24.z = (peVar10->origin).z;
    (*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
    (*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
    (*g_engfuncs.pfnRandomFloat)(-1.0,1.0);
    lVar11 = (longdouble)(float)extraout_ST0_00;
    lVar12 = (longdouble)(float)extraout_ST0;
    lVar14 = lVar12 * lVar12 + lVar11 * lVar11 + extraout_ST0_01 * extraout_ST0_01;
    lVar12 = SQRT(lVar14);
    lVar11 = extraout_ST0_01;
    if (NAN(lVar12)) {
      fVar15 = sqrtf((float)lVar14);
      lVar12 = (longdouble)fVar15;
      lVar11 = (longdouble)(float)extraout_ST0_01;
    }
    lVar14 = (longdouble)0;
    if (lVar12 == lVar14) {
      lVar13 = (longdouble)1;
      lVar11 = lVar14;
    }
    else {
      lVar12 = (longdouble)1.0 / lVar12;
      lVar13 = (longdouble)(float)extraout_ST0 * lVar12;
      lVar14 = (longdouble)(float)extraout_ST0_00 * lVar12;
      lVar11 = lVar12 * lVar11;
    }
    lVar12 = (longdouble)128.0;
    local_18.x = (vec_t)(lVar11 * lVar12 + (longdouble)local_24.x);
    local_18.y = (vec_t)(lVar14 * lVar12 + (longdouble)local_24.y);
    local_18.z = (vec_t)(lVar13 * lVar12 + (longdouble)local_24.z);
    UTIL_TraceLine(&local_24,&local_18,ignore_monsters,
                   ((this->super_CBaseDelay).super_CBaseEntity.pev)->pContainingEntity,&local_5c);
    piVar2 = &((this_00->super_CBaseEntity).pev)->rendermode;
    *piVar2 = *piVar2 & 0xf0;
    peVar10 = (this_00->super_CBaseEntity).pev;
    (peVar10->origin).x = local_24.x;
    (peVar10->origin).y = local_24.y;
    (peVar10->origin).z = local_24.z;
    peVar10 = (this_00->super_CBaseEntity).pev;
    (peVar10->angles).x = local_5c.vecEndPos.x;
    (peVar10->angles).y = local_5c.vecEndPos.y;
    (peVar10->angles).z = local_5c.vecEndPos.z;
    piVar2 = &((this_00->super_CBaseEntity).pev)->sequence;
    *piVar2 = *piVar2 & 0xfff;
    piVar2 = &((this_00->super_CBaseEntity).pev)->skin;
    *piVar2 = *piVar2 & 0xfff;
    CBeam::RelinkBeam(this_00);
    pgVar9 = gpGlobals;
    (((this_00->super_CBaseEntity).pev)->rendercolor).x = 255.0;
    (((this_00->super_CBaseEntity).pev)->rendercolor).y = 180.0;
    (((this_00->super_CBaseEntity).pev)->rendercolor).z = 100.0;
    ((this_00->super_CBaseEntity).pev)->scale = 100.0;
    ((this_00->super_CBaseEntity).pev)->animtime = 12.0;
    iVar7 = this->m_iBeam;
    fVar15 = pgVar9->time;
    this->m_pBeam[iVar7] = this_00;
    this->m_flBeamTime[iVar7] = fVar15;
    iVar7 = iVar7 + 1;
    this->m_iBeam = iVar7;
  }
  if (3.0 <= fVar3 - fVar4) {
    iVar8 = 0;
    if (0 < iVar7) {
      do {
        ppCVar1 = this->m_pBeam + iVar8;
        iVar8 = iVar8 + 1;
        UTIL_Remove(&(*ppCVar1)->super_CBaseEntity);
        pgVar9 = gpGlobals;
      } while (iVar8 < this->m_iBeam);
    }
    fVar3 = pgVar9->time;
    this->m_iBeam = 0;
    (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__pfn =
         (_func___thiscall_void_CBaseEntity_ptr *)0x0;
    (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__delta = 0;
    this->m_flStartTime = fVar3;
    return;
  }
  if (0 < iVar7) {
    pfVar5 = this->m_flBeamTime;
                    /* Unresolved local var: CBeam * pbeam@[DW_OP_reg6(ESI)]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: float flLen@[???] */
    iVar7 = 0;
    do {
      fVar3 = *pfVar5;
      iVar7 = iVar7 + 1;
      ppCVar1 = (CBeam **)(pfVar5 + -0x18);
      pfVar5 = pfVar5 + 1;
      (((*ppCVar1)->super_CBaseEntity).pev)->renderamt =
           (float)(int)(((pgVar9->time - fVar3) / ((this->m_flStartTime + 3.0) - fVar3)) * 255.0);
    } while (iVar7 < this->m_iBeam);
  }
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->nextthink = pgVar9->time + 0.1;
  return;
}


// CTestEffect::Use  @ 000c9930  (line 1704)

/* DWARF original prototype: void Use(CTestEffect * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CTestEffect::Use(CTestEffect *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
                float value)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  
  pgVar2 = gpGlobals;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__pfn = TestThink;
  peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar1->nextthink = pgVar2->time + 0.1;
  this->m_flStartTime = pgVar2->time;
  return;
}


// env_blood  @ 000cfae0  (line 1732)

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
  *puVar1 = &PTR__CBlood_0017da08;
  puVar1[1] = pev;
  return;
}


// CBlood::Spawn  @ 000c9fc0  (line 1742)

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


// CBlood::KeyValue  @ 000cb4b0  (line 1752)

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
                    /* Unresolved local var: int color@[DW_OP_reg0(EAX)] */
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


// CBlood::Direction  @ 000cfb50  (line 1779)

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


// CBlood::BloodPosition  @ 000cfba0  (line 1788)

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


// CBlood::Use  @ 000cfca0  (line 1807)

/* DWARF original prototype: void Use(CBlood * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CBlood::Use(CBlood *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,float value)

{
  float fVar1;
  entvars_t *peVar2;
  uint uVar3;
  int color;
  Vector *local_b4;
  TraceResult TStack_a8;
  Vector local_70;
  Vector local_64;
  Vector local_58;
  Vector local_4c;
  Vector local_40;
  Vector local_34;
  Vector local_28 [2];
  
  peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
  uVar3 = peVar2->spawnflags;
  fVar1 = peVar2->dmg;
  color = peVar2->impulse;
  if ((uVar3 & 2) == 0) {
    if ((uVar3 & 1) == 0) {
      local_4c.x = (peVar2->movedir).x;
      local_4c.y = (peVar2->movedir).y;
      local_4c.z = (peVar2->movedir).z;
    }
    else {
      UTIL_RandomBloodVector(&local_4c);
    }
    local_b4 = &local_4c;
    BloodPosition(&local_58,this,pActivator);
    UTIL_BloodDrips(&local_58,local_b4,color,(int)fVar1);
    peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
    uVar3 = peVar2->spawnflags;
  }
  else {
    if ((uVar3 & 1) == 0) {
      local_64.x = (peVar2->movedir).x;
      local_64.y = (peVar2->movedir).y;
      local_64.z = (peVar2->movedir).z;
    }
    else {
      UTIL_RandomBloodVector(&local_64);
    }
    local_b4 = &local_64;
    BloodPosition(&local_70,this,pActivator);
    UTIL_BloodStream(&local_70,local_b4,color,(int)fVar1);
    peVar2 = (this->super_CPointEntity).super_CBaseEntity.pev;
    uVar3 = peVar2->spawnflags;
  }
  if ((uVar3 & 8) != 0) {
                    /* Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector start@[???]
                       Unresolved local var: TraceResult tr@[???] */
    if ((uVar3 & 1) == 0) {
      local_40.x = (peVar2->movedir).x;
      local_40.y = (peVar2->movedir).y;
      local_40.z = (peVar2->movedir).z;
    }
    else {
      UTIL_RandomBloodVector(&local_40);
    }
    BloodPosition(&local_34,this,pActivator);
    fVar1 = ((this->super_CPointEntity).super_CBaseEntity.pev)->dmg;
    local_28[0].z = local_40.z * fVar1 + local_40.z * fVar1 + local_34.z;
    local_28[0].y = local_40.y * fVar1 + local_40.y * fVar1 + local_34.y;
    local_28[0].x = fVar1 * local_40.x + fVar1 * local_40.x + local_34.x;
    UTIL_TraceLine(&local_34,local_28,ignore_monsters,(edict_t *)0x0,&TStack_a8);
    if (TStack_a8.flFraction != 1.0) {
      UTIL_BloodDecalTrace(&TStack_a8,((this->super_CPointEntity).super_CBaseEntity.pev)->impulse);
    }
  }
  return;
}


// env_shake  @ 000cff50  (line 1847)

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
  *puVar1 = &PTR__CShake_0017db28;
  puVar1[1] = pev;
  return;
}


// CShake::Spawn  @ 000c9970  (line 1862)

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


// CShake::KeyValue  @ 000cb590  (line 1874)

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


// env_fade  @ 000cffc0  (line 1921)

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
  *puVar1 = &PTR__CFade_0017dc48;
  puVar1[1] = pev;
  return;
}


// CFade::Spawn  @ 000c99c0  (line 1929)

/* DWARF original prototype: void Spawn(CFade * this) */

void __thiscall CFade::Spawn(CFade *this)

{
  ((this->super_CPointEntity).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->effects = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->frame = 0.0;
  return;
}


// CFade::KeyValue  @ 000cb6d0  (line 1938)

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


// CFade::Use  @ 000c9f00  (line 1955)

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


// env_message  @ 000d0030  (line 1979)

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
  *puVar1 = &PTR__CMessage_0017dd68;
  puVar1[1] = pev;
  return;
}


// CMessage::Spawn  @ 000c9a00  (line 1983)

/* DWARF original prototype: void Spawn(CMessage * this) */

void __thiscall CMessage::Spawn(CMessage *this)

{
  entvars_t *peVar1;
  int iVar2;
  float fVar3;
  
  (*(this->super_CPointEntity).super_CBaseEntity._vptr_CBaseEntity[3])(this);
  ((this->super_CPointEntity).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CPointEntity).super_CBaseEntity.pev)->movetype = 0;
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  iVar2 = peVar1->impulse;
  if (iVar2 == 2) {
    peVar1->speed = 0.8;
  }
  else if (iVar2 == 3) {
    peVar1->speed = 0.0;
  }
  else {
    fVar3 = 2.0;
    if (iVar2 == 1) {
      fVar3 = 1.25;
    }
    peVar1->speed = fVar3;
  }
  ((this->super_CPointEntity).super_CBaseEntity.pev)->impulse = 0;
  peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
  if (peVar1->scale <= 0.0) {
    peVar1->scale = 1.0;
  }
  return;
}


// CMessage::Precache  @ 000ca2a0  (line 2018)

/* DWARF original prototype: void Precache(CMessage * this) */

void __thiscall CMessage::Precache(CMessage *this)

{
  string_t sVar1;
  
  sVar1 = ((this->super_CPointEntity).super_CBaseEntity.pev)->noise;
  if (sVar1 == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000ca2cf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)(gpGlobals->pStringBase + sVar1);
  return;
}


// CMessage::KeyValue  @ 000caff0  (line 2023)

/* DWARF original prototype: void KeyValue(CMessage * this, KeyValueData * pkvd) */

void __thiscall CMessage::KeyValue(CMessage *this,KeyValueData *pkvd)

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
  iVar4 = 0xd;
  pcVar6 = pkvd->szKeyName;
  pcVar5 = pcVar6;
  pcVar7 = "messagesound";
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pcVar5 == *pcVar7;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar8);
  if (bVar8) {
    peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
    sVar3 = (*g_engfuncs.pfnAllocString)(pkvd->szValue);
    peVar1->noise = sVar3;
    pkvd->fHandled = 1;
  }
  else {
    iVar4 = 0xe;
    bVar8 = false;
    pcVar5 = pcVar6;
    pcVar7 = "messagevolume";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar8 = *pcVar5 == *pcVar7;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar8);
    if (bVar8) {
      peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
      dVar9 = strtod(pkvd->szValue,(char **)0x0);
      peVar1->scale = (float)((longdouble)dVar9 * (longdouble)0.1);
      pkvd->fHandled = 1;
    }
    else {
      iVar4 = 0x13;
      bVar8 = false;
      pcVar5 = "messageattenuation";
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
      peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
      lVar2 = strtol(pkvd->szValue,(char **)0x0,10);
      peVar1->impulse = lVar2;
      pkvd->fHandled = 1;
    }
  }
  return;
}


// CMessage::Use  @ 000c9dd0  (line 2045)

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


// CEnvFunnel::Precache  @ 000c9aa0  (line 2087)

/* DWARF original prototype: void Precache(CEnvFunnel * this) */

void __thiscall CEnvFunnel::Precache(CEnvFunnel *this)

{
  int iVar1;
  
  iVar1 = (*g_engfuncs.pfnPrecacheModel)("sprites/flare6.spr");
  this->m_iSprite = iVar1;
  return;
}


// env_funnel  @ 000d00a0  (line 2091)

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
  *puVar1 = &PTR__CEnvFunnel_0017de88;
  puVar1[1] = pev;
  return;
}


// CEnvFunnel::Use  @ 000c9ac0  (line 2094)

/* DWARF original prototype: void Use(CEnvFunnel * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CEnvFunnel::Use(CEnvFunnel *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
               float value)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  
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
  pgVar2 = gpGlobals;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  (this->super_CBaseDelay).super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar1->nextthink = pgVar2->time;
  return;
}


// CEnvFunnel::Spawn  @ 000c9b90  (line 2119)

/* DWARF original prototype: void Spawn(CEnvFunnel * this) */

void __thiscall CEnvFunnel::Spawn(CEnvFunnel *this)

{
  (*(this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[3])(this);
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->effects = 0x80;
  return;
}


// CEnvBeverage::Precache  @ 000c9bc0  (line 2139)

/* DWARF original prototype: void Precache(CEnvBeverage * this) */

void __thiscall CEnvBeverage::Precache(CEnvBeverage *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/can.mdl");
                    /* WARNING: Could not recover jumptable at 0x000c9be1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("weapons/g_bounce3.wav");
  return;
}


// env_beverage  @ 000d0110  (line 2144)

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
  *puVar1 = &PTR__CEnvBeverage_0017dfa8;
  puVar1[1] = pev;
  return;
}


// CEnvBeverage::Use  @ 000ca9e0  (line 2147)

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
                    /* Unresolved local var: CBaseEntity * pCan@[???] */
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
    ((this->super_CBaseDelay).super_CBaseEntity.pev)->frags = 1.0;
    peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
    peVar1->health = peVar1->health - 1.0;
    return;
  }
  return;
}


// CEnvBeverage::Spawn  @ 000c9bf0  (line 2174)

/* DWARF original prototype: void Spawn(CEnvBeverage * this) */

void __thiscall CEnvBeverage::Spawn(CEnvBeverage *this)

{
  entvars_t *peVar1;
  
  (*(this->super_CBaseDelay).super_CBaseEntity._vptr_CBaseEntity[3])(this);
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->solid = 0;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->effects = 0x80;
  ((this->super_CBaseDelay).super_CBaseEntity.pev)->frags = 0.0;
  peVar1 = (this->super_CBaseDelay).super_CBaseEntity.pev;
  if (peVar1->health == 0.0) {
    peVar1->health = 10.0;
  }
  return;
}


// CItemSoda::Precache  @ 000c9c50  (line 2200)

/* DWARF original prototype: void Precache(CItemSoda * this) */

void __thiscall CItemSoda::Precache(CItemSoda *this)

{
  return;
}


// item_sodacan  @ 000d0180  (line 2202)

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
  *puVar1 = &PTR__CItemSoda_0017e0c8;
  puVar1[1] = pev;
  return;
}


// CItemSoda::Spawn  @ 000c9c60  (line 2205)

/* DWARF original prototype: void Spawn(CItemSoda * this) */

void __thiscall CItemSoda::Spawn(CItemSoda *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  Vector local_24;
  Vector local_18;
  
  (*(this->super_CBaseEntity)._vptr_CBaseEntity[3])(this);
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
  pgVar2 = gpGlobals;
  (this->super_CBaseEntity).m_pfnThink.__pfn = CanThink;
  peVar1 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar1->nextthink = pgVar2->time + 0.5;
  return;
}


// CItemSoda::CanThink  @ 000c9d10  (line 2218)

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


// CItemSoda::CanTouch  @ 000ca910  (line 2228)

/* DWARF original prototype: void CanTouch(CItemSoda * this, CBaseEntity * pOther) */

void __thiscall CItemSoda::CanTouch(CItemSoda *this,CBaseEntity *pOther)

{
  globalvars_t *pgVar1;
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
  pgVar1 = gpGlobals;
  ((this->super_CBaseEntity).pev)->effects = 0x80;
  (this->super_CBaseEntity).m_pfnTouch.__pfn =
       (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0;
  peVar3 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
  (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_Remove;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar3->nextthink = pgVar1->time;
  return;
}


// CShake::Use  @ 000c9f80  (line 2250)

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


