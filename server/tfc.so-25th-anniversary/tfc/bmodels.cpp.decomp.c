// Ghidra decompilation of functions from tfc/bmodels.cpp
// 55 functions, ordered by original source line

// VecBModelOrigin  @ 00070a90  (line 39)

Vector * VecBModelOrigin(Vector *__return_storage_ptr__,entvars_t *pevBModel)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = (pevBModel->size).z;
  fVar2 = (pevBModel->absmin).z;
  fVar3 = (pevBModel->size).y;
  fVar4 = (pevBModel->absmin).y;
  __return_storage_ptr__->x = (pevBModel->size).x * 0.5 + (pevBModel->absmin).x;
  __return_storage_ptr__->y = fVar3 * 0.5 + fVar4;
  __return_storage_ptr__->z = fVar1 * 0.5 + fVar2;
  return __return_storage_ptr__;
}


// CFuncWall::~CFuncWall  @ 000710f0  (line 48)

/* DWARF original prototype: void ~CFuncWall(CFuncWall * this, int __in_chrg) */

void __thiscall CFuncWall::~CFuncWall(CFuncWall *this,int __in_chrg)

{
  return;
}


// CFuncWall::ObjectCaps  @ 000710a0  (line 55)

/* DWARF original prototype: int ObjectCaps(CFuncWall * this) */

int __thiscall CFuncWall::ObjectCaps(CFuncWall *this)

{
  return 0;
}


// func_wall  @ 00070ae0  (line 58)

void func_wall(entvars_t *pev)

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
  *puVar1 = &PTR__CFuncWall_00147b48;
  puVar1[1] = pev;
  return;
}


// CFuncWall::Spawn  @ 0006eaf0  (line 61)

/* DWARF original prototype: void Spawn(CFuncWall * this) */

void __thiscall CFuncWall::Spawn(CFuncWall *this)

{
  int *piVar1;
  entvars_t *peVar2;
  
  peVar2 = (this->super_CBaseEntity).pev;
  (peVar2->angles).x = g_vecZero.x;
  (peVar2->angles).y = g_vecZero.y;
  (peVar2->angles).z = g_vecZero.z;
  ((this->super_CBaseEntity).pev)->movetype = 7;
  ((this->super_CBaseEntity).pev)->solid = 4;
  peVar2 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + peVar2->model);
  piVar1 = &((this->super_CBaseEntity).pev)->flags;
  *piVar1 = *piVar1 | 0x2000000;
  return;
}


// CFuncWall::Use  @ 0006ffc0  (line 73)

/* DWARF original prototype: void Use(CFuncWall * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncWall::Use(CFuncWall *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
              float value)

{
  entvars_t *peVar1;
  int iVar2;
  
  iVar2 = CBaseEntity::ShouldToggle
                    (&this->super_CBaseEntity,useType,(int)((this->super_CBaseEntity).pev)->frame);
  if (iVar2 != 0) {
    peVar1 = (this->super_CBaseEntity).pev;
    peVar1->frame = 1.0 - peVar1->frame;
  }
  return;
}


// CFuncWallToggle::~CFuncWallToggle  @ 00071150  (line 81)

/* DWARF original prototype: void ~CFuncWallToggle(CFuncWallToggle * this, int __in_chrg) */

void __thiscall CFuncWallToggle::~CFuncWallToggle(CFuncWallToggle *this,int __in_chrg)

{
  return;
}


// func_wall_toggle  @ 00070b50  (line 91)

void func_wall_toggle(entvars_t *pev)

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
  *puVar1 = &PTR__CFuncWallToggle_00147c54;
  puVar1[1] = pev;
  return;
}


// CFuncWallToggle::Spawn  @ 00070190  (line 94)

/* DWARF original prototype: void Spawn(CFuncWallToggle * this) */

void __thiscall CFuncWallToggle::Spawn(CFuncWallToggle *this)

{
  int *piVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  
  peVar2 = (this->super_CFuncWall).super_CBaseEntity.pev;
  (peVar2->angles).x = g_vecZero.x;
  (peVar2->angles).y = g_vecZero.y;
  (peVar2->angles).z = g_vecZero.z;
  ((this->super_CFuncWall).super_CBaseEntity.pev)->movetype = 7;
  p1Var3 = gpGlobals;
  ((this->super_CFuncWall).super_CBaseEntity.pev)->solid = 4;
  peVar2 = (this->super_CFuncWall).super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,p1Var3->pStringBase + peVar2->model);
  piVar1 = &((this->super_CFuncWall).super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 | 0x2000000;
  peVar2 = (this->super_CFuncWall).super_CBaseEntity.pev;
  if ((peVar2->spawnflags & 1) != 0) {
    peVar2->solid = 0;
    piVar1 = &((this->super_CFuncWall).super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 0x80;
    peVar2 = (this->super_CFuncWall).super_CBaseEntity.pev;
    UTIL_SetOrigin(peVar2,&peVar2->origin);
  }
  return;
}


// CFuncWallToggle::TurnOff  @ 00070bc0  (line 102)

/* DWARF original prototype: void TurnOff(CFuncWallToggle * this) */

void __thiscall CFuncWallToggle::TurnOff(CFuncWallToggle *this)

{
  int *piVar1;
  entvars_t *pev;
  
  ((this->super_CFuncWall).super_CBaseEntity.pev)->solid = 0;
  piVar1 = &((this->super_CFuncWall).super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  pev = (this->super_CFuncWall).super_CBaseEntity.pev;
  UTIL_SetOrigin(pev,&pev->origin);
  return;
}


// CFuncWallToggle::TurnOn  @ 00070c00  (line 110)

/* DWARF original prototype: void TurnOn(CFuncWallToggle * this) */

void __thiscall CFuncWallToggle::TurnOn(CFuncWallToggle *this)

{
  int *piVar1;
  entvars_t *pev;
  
  ((this->super_CFuncWall).super_CBaseEntity.pev)->solid = 4;
  piVar1 = &((this->super_CFuncWall).super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 & 0xffffff7f;
  pev = (this->super_CFuncWall).super_CBaseEntity.pev;
  UTIL_SetOrigin(pev,&pev->origin);
  return;
}


// CFuncWallToggle::IsOn  @ 00070c40  (line 119)

/* DWARF original prototype: BOOL IsOn(CFuncWallToggle * this) */

BOOL __thiscall CFuncWallToggle::IsOn(CFuncWallToggle *this)

{
  return (uint)(((this->super_CFuncWall).super_CBaseEntity.pev)->solid != 0);
}


// CFuncWallToggle::Use  @ 0006faa0  (line 126)

/* DWARF original prototype: void Use(CFuncWallToggle * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncWallToggle::Use
          (CFuncWallToggle *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  int *piVar1;
  entvars_t *pev;
  int iVar2;
  
                    /* Unresolved local var: int status@[???] */
  if (((this->super_CFuncWall).super_CBaseEntity.pev)->solid == 0) {
    iVar2 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,0);
    if (iVar2 == 0) {
      return;
    }
    ((this->super_CFuncWall).super_CBaseEntity.pev)->solid = 4;
    piVar1 = &((this->super_CFuncWall).super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 & 0xffffff7f;
  }
  else {
    iVar2 = CBaseEntity::ShouldToggle((CBaseEntity *)this,useType,1);
    if (iVar2 == 0) {
      return;
    }
                    /* Unresolved local var: int status@[???] */
    ((this->super_CFuncWall).super_CBaseEntity.pev)->solid = 0;
    piVar1 = &((this->super_CFuncWall).super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 0x80;
  }
  pev = (this->super_CFuncWall).super_CBaseEntity.pev;
  UTIL_SetOrigin(pev,&pev->origin);
  return;
}


// CFuncConveyor::~CFuncConveyor  @ 00071140  (line 142)

/* DWARF original prototype: void ~CFuncConveyor(CFuncConveyor * this, int __in_chrg) */

void __thiscall CFuncConveyor::~CFuncConveyor(CFuncConveyor *this,int __in_chrg)

{
  return;
}


// func_conveyor  @ 00070c60  (line 150)

void func_conveyor(entvars_t *pev)

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
  *puVar1 = &PTR__CFuncConveyor_00147d60;
  puVar1[1] = pev;
  return;
}


// CFuncConveyor::Spawn  @ 000702f0  (line 152)

/* DWARF original prototype: void Spawn(CFuncConveyor * this) */

void __thiscall CFuncConveyor::Spawn(CFuncConveyor *this)

{
  int *piVar1;
  float fVar2;
  vec_t vVar3;
  _2globalvars_t *p1Var4;
  uint uVar5;
  entvars_t *peVar6;
  
  SetMovedir((this->super_CFuncWall).super_CBaseEntity.pev);
  peVar6 = (this->super_CFuncWall).super_CBaseEntity.pev;
  (peVar6->angles).x = g_vecZero.x;
  (peVar6->angles).y = g_vecZero.y;
  (peVar6->angles).z = g_vecZero.z;
  ((this->super_CFuncWall).super_CBaseEntity.pev)->movetype = 7;
  p1Var4 = gpGlobals;
  ((this->super_CFuncWall).super_CBaseEntity.pev)->solid = 4;
  peVar6 = (this->super_CFuncWall).super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar6->pContainingEntity,p1Var4->pStringBase + peVar6->model);
  piVar1 = &((this->super_CFuncWall).super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 | 0x2000000;
  peVar6 = (this->super_CFuncWall).super_CBaseEntity.pev;
  uVar5 = peVar6->spawnflags;
  if ((uVar5 & 1) == 0) {
    peVar6->flags = peVar6->flags | 4;
    peVar6 = (this->super_CFuncWall).super_CBaseEntity.pev;
    uVar5 = peVar6->spawnflags;
  }
  if ((uVar5 & 2) != 0) {
    peVar6->solid = 0;
    ((this->super_CFuncWall).super_CBaseEntity.pev)->skin = 0;
    peVar6 = (this->super_CFuncWall).super_CBaseEntity.pev;
  }
  fVar2 = peVar6->speed;
  if (fVar2 == 0.0) {
    peVar6->speed = 100.0;
    peVar6 = (this->super_CFuncWall).super_CBaseEntity.pev;
    fVar2 = peVar6->speed;
  }
                    /* Unresolved local var: int speedCode@[???] */
  vVar3 = 1.0;
  if (0.0 <= fVar2) {
    vVar3 = 0.0;
  }
  (peVar6->rendercolor).x = vVar3;
  (((this->super_CFuncWall).super_CBaseEntity.pev)->rendercolor).y =
       (float)((int)(ABS(fVar2) * 16.0) >> 8);
  (((this->super_CFuncWall).super_CBaseEntity.pev)->rendercolor).z =
       (float)((int)(ABS(fVar2) * 16.0) & 0xff);
  return;
}


// CFuncConveyor::UpdateSpeed  @ 00070cd0  (line 175)

/* DWARF original prototype: void UpdateSpeed(CFuncConveyor * this, float speed) */

void __thiscall CFuncConveyor::UpdateSpeed(CFuncConveyor *this,float speed)

{
  entvars_t *peVar1;
  
                    /* Unresolved local var: int speedCode@[???] */
  peVar1 = (this->super_CFuncWall).super_CBaseEntity.pev;
  if (speed < 0.0) {
    (peVar1->rendercolor).x = 1.0;
  }
  else {
    (peVar1->rendercolor).x = 0.0;
  }
  (((this->super_CFuncWall).super_CBaseEntity.pev)->rendercolor).y =
       (float)((int)(ABS(speed) * 16.0) >> 8);
  (((this->super_CFuncWall).super_CBaseEntity.pev)->rendercolor).z =
       (float)((int)(ABS(speed) * 16.0) & 0xff);
  return;
}


// CFuncConveyor::Use  @ 0006eb70  (line 190)

/* DWARF original prototype: void Use(CFuncConveyor * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncConveyor::Use(CFuncConveyor *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType
                  ,float value)

{
  float fVar1;
  entvars_t *peVar2;
  vec_t vVar3;
  uint uVar4;
  
  peVar2 = (this->super_CFuncWall).super_CBaseEntity.pev;
  peVar2->speed = -peVar2->speed;
  peVar2 = (this->super_CFuncWall).super_CBaseEntity.pev;
  fVar1 = peVar2->speed;
                    /* Unresolved local var: int speedCode@[???] */
  uVar4 = (uint)(ABS(fVar1) * 16.0);
  vVar3 = 1.0;
  if (0.0 <= fVar1) {
    vVar3 = 0.0;
  }
  (peVar2->rendercolor).x = vVar3;
  (((this->super_CFuncWall).super_CBaseEntity.pev)->rendercolor).y = (float)((int)uVar4 >> 8);
  (((this->super_CFuncWall).super_CBaseEntity.pev)->rendercolor).z = (float)(uVar4 & 0xff);
  return;
}


// CFuncIllusionary::~CFuncIllusionary  @ 00071130  (line 203)

/* DWARF original prototype: void ~CFuncIllusionary(CFuncIllusionary * this, int __in_chrg) */

void __thiscall CFuncIllusionary::~CFuncIllusionary(CFuncIllusionary *this,int __in_chrg)

{
  return;
}


// CFuncIllusionary::ObjectCaps  @ 000710b0  (line 209)

/* DWARF original prototype: int ObjectCaps(CFuncIllusionary * this) */

int __thiscall CFuncIllusionary::ObjectCaps(CFuncIllusionary *this)

{
  return 0;
}


// func_illusionary  @ 00070d40  (line 212)

void func_illusionary(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x514,pev);
  *puVar1 = &PTR__CFuncIllusionary_00147e6c;
  puVar1[1] = pev;
  return;
}


// CFuncIllusionary::KeyValue  @ 0006fdb0  (line 215)

/* DWARF original prototype: void KeyValue(CFuncIllusionary * this, KeyValueData * pkvd) */

void __thiscall CFuncIllusionary::KeyValue(CFuncIllusionary *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  double dVar6;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar2 = 5;
  pcVar3 = pkvd->szKeyName;
  pcVar4 = "skin";
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
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  dVar6 = strtod(pkvd->szValue,(char **)0x0);
  peVar1->skin = (int)dVar6;
  pkvd->fHandled = 1;
  return;
}


// CFuncIllusionary::Spawn  @ 0006ebf0  (line 226)

/* DWARF original prototype: void Spawn(CFuncIllusionary * this) */

void __thiscall CFuncIllusionary::Spawn(CFuncIllusionary *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (peVar1->angles).x = g_vecZero.x;
  (peVar1->angles).y = g_vecZero.y;
  (peVar1->angles).z = g_vecZero.z;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->movetype
       = 0;
  ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->solid = 0
  ;
  peVar1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar1->pContainingEntity,gpGlobals->pStringBase + peVar1->model);
  return;
}


// CFuncMonsterClip::~CFuncMonsterClip  @ 00071120  (line 250)

/* DWARF original prototype: void ~CFuncMonsterClip(CFuncMonsterClip * this, int __in_chrg) */

void __thiscall CFuncMonsterClip::~CFuncMonsterClip(CFuncMonsterClip *this,int __in_chrg)

{
  return;
}


// CFuncMonsterClip::Use  @ 000710c0  (line 254)

/* DWARF original prototype: void Use(CFuncMonsterClip * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncMonsterClip::Use
          (CFuncMonsterClip *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  return;
}


// func_monsterclip  @ 00070db0  (line 257)

void func_monsterclip(entvars_t *pev)

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
  *puVar1 = &PTR__CFuncMonsterClip_00147f7c;
  puVar1[1] = pev;
  return;
}


// CFuncMonsterClip::Spawn  @ 00070240  (line 260)

/* DWARF original prototype: void Spawn(CFuncMonsterClip * this) */

void __thiscall CFuncMonsterClip::Spawn(CFuncMonsterClip *this)

{
  int *piVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  longdouble lVar4;
  
  peVar2 = (this->super_CFuncWall).super_CBaseEntity.pev;
  (peVar2->angles).x = g_vecZero.x;
  (peVar2->angles).y = g_vecZero.y;
  (peVar2->angles).z = g_vecZero.z;
  ((this->super_CFuncWall).super_CBaseEntity.pev)->movetype = 7;
  p1Var3 = gpGlobals;
  ((this->super_CFuncWall).super_CBaseEntity.pev)->solid = 4;
  peVar2 = (this->super_CFuncWall).super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,p1Var3->pStringBase + peVar2->model);
  piVar1 = &((this->super_CFuncWall).super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 | 0x2000000;
  lVar4 = (longdouble)(*g_engfuncs.pfnCVarGetFloat)("showtriggers");
  if (lVar4 == (longdouble)0) {
    ((this->super_CFuncWall).super_CBaseEntity.pev)->effects = 0x80;
  }
  piVar1 = &((this->super_CFuncWall).super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 | 0x800000;
  return;
}


// CFuncRotating::~CFuncRotating  @ 00071110  (line 269)

/* DWARF original prototype: void ~CFuncRotating(CFuncRotating * this, int __in_chrg) */

void __thiscall CFuncRotating::~CFuncRotating(CFuncRotating *this,int __in_chrg)

{
  return;
}


// CFuncRotating::ObjectCaps  @ 000710d0  (line 283)

/* DWARF original prototype: int ObjectCaps(CFuncRotating * this) */

int __thiscall CFuncRotating::ObjectCaps(CFuncRotating *this)

{
  return 0;
}


// CFuncRotating::Restore  @ 0006fea0  (line 305)

/* DWARF original prototype: int Restore(CFuncRotating * this, CRestore * restore) */

int __thiscall CFuncRotating::Restore(CFuncRotating *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore(&this->super_CBaseEntity,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CFuncRotating",this,m_SaveData,5);
  }
  return iVar2;
}


// CFuncRotating::Save  @ 0006ff60  (line 305)

/* DWARF original prototype: int Save(CFuncRotating * this, CSave * save) */

int __thiscall CFuncRotating::Save(CFuncRotating *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save(&this->super_CBaseEntity,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CFuncRotating",this,m_SaveData,5);
  }
  return iVar2;
}


// func_rotating  @ 00070e20  (line 308)

void func_rotating(entvars_t *pev)

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
  *puVar1 = &PTR__CFuncRotating_00148088;
  puVar1[1] = pev;
  return;
}


// CFuncRotating::KeyValue  @ 0006f1b0  (line 311)

/* DWARF original prototype: void KeyValue(CFuncRotating * this, KeyValueData * pkvd) */

void __thiscall CFuncRotating::KeyValue(CFuncRotating *this,KeyValueData *pkvd)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  long lVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  double dVar10;
  float local_18;
  float local_14;
  float local_10;
  
  bVar9 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar5 = 0xc;
  pcVar7 = pkvd->szKeyName;
  pcVar6 = pcVar7;
  pcVar8 = "fanfriction";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar6 == *pcVar8;
    pcVar6 = pcVar6 + 1;
    pcVar8 = pcVar8 + 1;
  } while (bVar9);
  if (bVar9) {
    dVar10 = strtod(pkvd->szValue,(char **)0x0);
    this->m_flFanFriction = (float)dVar10 / 100.0;
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 7;
  bVar9 = false;
  pcVar6 = pcVar7;
  pcVar8 = "Volume";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar6 == *pcVar8;
    pcVar6 = pcVar6 + 1;
    pcVar8 = pcVar8 + 1;
  } while (bVar9);
  if (bVar9) {
    dVar10 = strtod(pkvd->szValue,(char **)0x0);
    fVar2 = (float)dVar10 / 10.0;
    if (fVar2 <= 1.0) {
      fVar3 = 0.0;
      if (0.0 <= fVar2) {
        fVar3 = fVar2;
      }
      this->m_flVolume = fVar3;
    }
    else {
      this->m_flVolume = 1.0;
    }
LAB_0006f275:
    pkvd->fHandled = 1;
    return;
  }
  iVar5 = 0xc;
  bVar9 = false;
  pcVar6 = pcVar7;
  pcVar8 = "spawnorigin";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar9 = *pcVar6 == *pcVar8;
    pcVar6 = pcVar6 + 1;
    pcVar8 = pcVar8 + 1;
  } while (bVar9);
  if (bVar9) {
                    /* Unresolved local var: Vector tmp@[???] */
    UTIL_StringToVector(&local_18,pkvd->szValue);
    if (((local_18 != g_vecZero.x) || (local_14 != g_vecZero.y)) || (local_10 != g_vecZero.z)) {
      peVar1 = (this->super_CBaseEntity).pev;
      (peVar1->origin).x = local_18;
      (peVar1->origin).y = local_14;
      (peVar1->origin).z = local_10;
      return;
    }
  }
  else {
    iVar5 = 7;
    bVar9 = false;
    pcVar6 = "sounds";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar9 = *pcVar7 == *pcVar6;
      pcVar7 = pcVar7 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar9);
    if (bVar9) {
      lVar4 = strtol(pkvd->szValue,(char **)0x0,10);
      this->m_sounds = lVar4;
      goto LAB_0006f275;
    }
    CBaseEntity::KeyValue(&this->super_CBaseEntity,pkvd);
  }
  return;
}


// CFuncRotating::Spawn  @ 0006ef40  (line 358)

/* DWARF original prototype: void Spawn(CFuncRotating * this) */

void __thiscall CFuncRotating::Spawn(CFuncRotating *this)

{
  entvars_t *peVar1;
  uint uVar2;
  
  this->m_pitch = 99.0;
  if (this->m_flVolume == 0.0) {
    this->m_flVolume = 1.0;
  }
  peVar1 = (this->super_CBaseEntity).pev;
  this->m_flAttenuation = 0.8;
  if ((peVar1->spawnflags & 0x80U) == 0) {
    if ((peVar1->spawnflags & 0x100U) != 0) {
      this->m_flAttenuation = 1.25;
    }
  }
  else {
    this->m_flAttenuation = 2.0;
  }
  if (this->m_flFanFriction == 0.0) {
    this->m_flFanFriction = 1.0;
    uVar2 = peVar1->spawnflags;
  }
  else {
    uVar2 = peVar1->spawnflags;
  }
  if ((uVar2 & 4) == 0) {
    if ((uVar2 & 8) == 0) {
      (peVar1->movedir).x = 0.0;
      (peVar1->movedir).y = 1.0;
      (peVar1->movedir).z = 0.0;
    }
    else {
      (peVar1->movedir).x = 1.0;
      (peVar1->movedir).y = 0.0;
      (peVar1->movedir).z = 0.0;
    }
  }
  else {
    (peVar1->movedir).x = 0.0;
    (peVar1->movedir).y = 0.0;
    (peVar1->movedir).z = 1.0;
  }
  peVar1 = (this->super_CBaseEntity).pev;
  uVar2 = peVar1->spawnflags;
  if ((uVar2 & 2) != 0) {
    (peVar1->movedir).x = -(peVar1->movedir).x;
    (peVar1->movedir).y = -(peVar1->movedir).y;
    (peVar1->movedir).z = -(peVar1->movedir).z;
    peVar1 = (this->super_CBaseEntity).pev;
    uVar2 = peVar1->spawnflags;
  }
  if ((uVar2 & 0x40) == 0) {
    peVar1->solid = 4;
    ((this->super_CBaseEntity).pev)->movetype = 7;
  }
  else {
    peVar1->solid = 0;
    ((this->super_CBaseEntity).pev)->skin = -1;
    ((this->super_CBaseEntity).pev)->movetype = 7;
  }
  peVar1 = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(peVar1,&peVar1->origin);
  peVar1 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar1->pContainingEntity,gpGlobals->pStringBase + peVar1->model);
  peVar1 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnUse.__pfn = RotatingUse;
  (this->super_CBaseEntity).m_pfnUse.__delta = 0;
  if (peVar1->speed <= 0.0) {
    peVar1->speed = 0.0;
    peVar1 = (this->super_CBaseEntity).pev;
  }
  uVar2 = peVar1->spawnflags;
  if ((uVar2 & 1) != 0) {
    (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_CallUseToggle;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    peVar1->nextthink = peVar1->ltime + 1.5;
    uVar2 = ((this->super_CBaseEntity).pev)->spawnflags;
  }
  if ((uVar2 & 0x20) != 0) {
    (this->super_CBaseEntity).m_pfnTouch.__pfn = HurtTouch;
    (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0006f0d7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseEntity)._vptr_CBaseEntity[3])();
  return;
}


// CFuncRotating::Precache  @ 0006ec60  (line 443)

/* DWARF original prototype: void Precache(CFuncRotating * this) */

void __thiscall CFuncRotating::Precache(CFuncRotating *this)

{
  entvars_t *peVar1;
  char *pcVar2;
  string_t sVar3;
  
                    /* Unresolved local var: char * szSoundFile@[???] */
  peVar1 = (this->super_CBaseEntity).pev;
  sVar3 = peVar1->message;
  if ((sVar3 == 0) || (pcVar2 = gpGlobals->pStringBase + sVar3, *pcVar2 == '\0')) {
    switch(this->m_sounds) {
    default:
      sVar3 = (*g_engfuncs.pfnAllocString)("common/null.wav");
      peVar1->noise3 = sVar3;
      break;
    case 1:
      (*g_engfuncs.pfnPrecacheSound)("fans/fan1.wav");
      peVar1 = (this->super_CBaseEntity).pev;
      sVar3 = (*g_engfuncs.pfnAllocString)("fans/fan1.wav");
      peVar1->noise3 = sVar3;
      break;
    case 2:
      (*g_engfuncs.pfnPrecacheSound)("fans/fan2.wav");
      peVar1 = (this->super_CBaseEntity).pev;
      sVar3 = (*g_engfuncs.pfnAllocString)("fans/fan2.wav");
      peVar1->noise3 = sVar3;
      break;
    case 3:
      (*g_engfuncs.pfnPrecacheSound)("fans/fan3.wav");
      peVar1 = (this->super_CBaseEntity).pev;
      sVar3 = (*g_engfuncs.pfnAllocString)("fans/fan3.wav");
      peVar1->noise3 = sVar3;
      break;
    case 4:
      (*g_engfuncs.pfnPrecacheSound)("fans/fan4.wav");
      peVar1 = (this->super_CBaseEntity).pev;
      sVar3 = (*g_engfuncs.pfnAllocString)("fans/fan4.wav");
      peVar1->noise3 = sVar3;
      break;
    case 5:
      (*g_engfuncs.pfnPrecacheSound)("fans/fan5.wav");
      peVar1 = (this->super_CBaseEntity).pev;
      sVar3 = (*g_engfuncs.pfnAllocString)("fans/fan5.wav");
      peVar1->noise3 = sVar3;
    }
  }
  else {
    (*g_engfuncs.pfnPrecacheSound)(pcVar2);
    peVar1 = (this->super_CBaseEntity).pev;
    sVar3 = (*g_engfuncs.pfnAllocString)(pcVar2);
    peVar1->noise3 = sVar3;
  }
  peVar1 = (this->super_CBaseEntity).pev;
  if ((((peVar1->avelocity).x == g_vecZero.x) && ((peVar1->avelocity).y == g_vecZero.y)) &&
     ((peVar1->avelocity).z == g_vecZero.z)) {
    return;
  }
  (this->super_CBaseEntity).m_pfnThink.__pfn = SpinUp;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar1->nextthink = peVar1->ltime + 1.5;
  return;
}


// CFuncRotating::HurtTouch  @ 0006f3a0  (line 513)

/* DWARF original prototype: void HurtTouch(CFuncRotating * this, CBaseEntity * pOther) */

void __thiscall CFuncRotating::HurtTouch(CFuncRotating *this,CBaseEntity *pOther)

{
  float fVar1;
  entvars_t *peVar2;
  entvars_t *peVar3;
  float fVar4;
  float __x;
  float fVar5;
  float fVar6;
  float fVar7;
  
                    /* Unresolved local var: entvars_t * pevOther@[???] */
  peVar2 = pOther->pev;
  if (peVar2->takedamage != 0.0) {
    peVar3 = (this->super_CBaseEntity).pev;
    fVar1 = (peVar3->avelocity).x;
    fVar7 = (peVar3->avelocity).y;
    fVar6 = (peVar3->avelocity).z;
    fVar1 = fVar6 * fVar6 + fVar7 * fVar7 + fVar1 * fVar1;
    fVar7 = SQRT(fVar1);
    if (NAN(fVar7)) {
      fVar7 = sqrtf(fVar1);
    }
    peVar3->dmg = fVar7 / 10.0;
    peVar3 = (this->super_CBaseEntity).pev;
    (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar3,peVar3,peVar3->dmg,1);
    peVar3 = (this->super_CBaseEntity).pev;
    fVar1 = peVar3->dmg;
    fVar7 = (peVar2->origin).z - ((peVar3->size).z * 0.5 + (peVar3->absmin).z);
    fVar5 = (peVar2->origin).y - ((peVar3->size).y * 0.5 + (peVar3->absmin).y);
    fVar4 = (peVar2->origin).x - ((peVar3->size).x * 0.5 + (peVar3->absmin).x);
                    /* Unresolved local var: float flLen@[???] */
    __x = fVar7 * fVar7 + fVar5 * fVar5 + fVar4 * fVar4;
    fVar6 = SQRT(__x);
    if (NAN(fVar6)) {
      fVar6 = sqrtf(__x);
    }
    if (fVar6 == 0.0) {
      fVar4 = 0.0;
      fVar7 = 1.0;
      fVar6 = fVar4;
    }
    else {
      fVar6 = 1.0 / fVar6;
      fVar7 = fVar7 * fVar6;
      fVar4 = fVar6 * fVar4;
      fVar6 = fVar5 * fVar6;
    }
    (peVar2->velocity).x = fVar4 * fVar1;
    (peVar2->velocity).y = fVar6 * fVar1;
    (peVar2->velocity).z = fVar7 * fVar1;
  }
  return;
}


// CFuncRotating::RampPitchVol  @ 00070e90  (line 536)

/* DWARF original prototype: void RampPitchVol(CFuncRotating * this, int fUp) */

void __thiscall CFuncRotating::RampPitchVol(CFuncRotating *this,int fUp)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  uint uVar4;
  uint uVar5;
  int pitch;
  uint uVar6;
  
                    /* Unresolved local var: Vector vecAVel@[???]
                       Unresolved local var: vec_t vecCur@[???]
                       Unresolved local var: vec_t vecFinal@[???]
                       Unresolved local var: float fpct@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: float fpitch@[???]
                       Unresolved local var: int pitch@[???] */
  peVar3 = (this->super_CBaseEntity).pev;
  fVar1 = (peVar3->avelocity).x;
  fVar2 = (peVar3->avelocity).y;
  if (fVar1 == 0.0) {
    if (fVar2 == 0.0) {
      uVar4 = (uint)(peVar3->avelocity).z;
    }
    else {
      uVar4 = (uint)fVar2;
    }
  }
  else {
    uVar4 = (uint)fVar1;
  }
  fVar1 = (peVar3->movedir).x;
  if ((fVar1 == 0.0) && (fVar1 = (peVar3->movedir).y, fVar1 == 0.0)) {
    fVar1 = (peVar3->movedir).z;
  }
  uVar5 = (uint)(fVar1 * peVar3->speed);
  uVar6 = (int)uVar5 >> 0x1f;
  fVar1 = (float)(int)((uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f)) /
          (float)(int)((uVar5 ^ uVar6) - uVar6);
  pitch = (int)(fVar1 * 70.0 + 30.0);
  if (pitch == 100) {
    pitch = 99;
  }
  EMIT_SOUND_DYN(peVar3->pContainingEntity,6,gpGlobals->pStringBase + peVar3->noise3,
                 this->m_flVolume * fVar1,this->m_flAttenuation,0xc0,pitch);
  return;
}


// CFuncRotating::SpinUp  @ 00070430  (line 581)

/* DWARF original prototype: void SpinUp(CFuncRotating * this) */

void __thiscall CFuncRotating::SpinUp(CFuncRotating *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  entvars_t *peVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  uint uVar10;
  int iVar11;
  int pitch;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  
                    /* Unresolved local var: Vector vecAVel@[???] */
  peVar6 = (this->super_CBaseEntity).pev;
  peVar6->nextthink = peVar6->ltime + 0.1;
  peVar6 = (this->super_CBaseEntity).pev;
  fVar3 = peVar6->speed * this->m_flFanFriction;
  fVar1 = (peVar6->movedir).z;
  fVar2 = (peVar6->movedir).y;
  (peVar6->avelocity).x = fVar3 * (peVar6->movedir).x + (peVar6->avelocity).x;
  (peVar6->avelocity).y = fVar2 * fVar3 + (peVar6->avelocity).y;
  (peVar6->avelocity).z = fVar1 * fVar3 + (peVar6->avelocity).z;
  peVar6 = (this->super_CBaseEntity).pev;
  fVar2 = (peVar6->avelocity).x;
  fVar3 = (peVar6->avelocity).y;
  fVar4 = (peVar6->movedir).x;
  fVar5 = peVar6->speed;
  fVar7 = fVar4 * fVar5;
  uVar10 = (uint)fVar2;
  fVar1 = (peVar6->avelocity).z;
  uVar12 = (int)uVar10 >> 0x1f;
  iVar11 = (uVar10 ^ uVar12) - uVar12;
  uVar10 = (uint)fVar7;
  uVar12 = (int)uVar10 >> 0x1f;
  iVar13 = (uVar10 ^ uVar12) - uVar12;
  if (((iVar11 < iVar13) ||
      (fVar8 = (peVar6->movedir).y * fVar5, uVar12 = (int)fVar3 >> 0x1f, uVar14 = (uint)fVar8,
      uVar10 = (int)uVar14 >> 0x1f,
      (int)(((int)fVar3 ^ uVar12) - uVar12) < (int)((uVar14 ^ uVar10) - uVar10))) ||
     (uVar15 = (uint)fVar1, fVar9 = (peVar6->movedir).z * fVar5, uVar12 = (int)uVar15 >> 0x1f,
     uVar14 = (uint)fVar9, uVar10 = (int)uVar14 >> 0x1f,
     (int)((uVar15 ^ uVar12) - uVar12) < (int)((uVar14 ^ uVar10) - uVar10))) {
                    /* Unresolved local var: Vector vecAVel@[???]
                       Unresolved local var: vec_t vecCur@[???]
                       Unresolved local var: vec_t vecFinal@[???]
                       Unresolved local var: float fpct@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: float fpitch@[???]
                       Unresolved local var: int pitch@[???] */
    if (fVar2 == 0.0) {
      if (fVar3 == 0.0) {
        fVar3 = fVar1;
      }
      uVar10 = (int)fVar3 >> 0x1f;
      iVar11 = ((int)fVar3 ^ uVar10) - uVar10;
    }
    if (fVar4 == 0.0) {
      fVar1 = (peVar6->movedir).y;
      if (fVar1 == 0.0) {
        fVar1 = (peVar6->movedir).z;
      }
      uVar10 = (int)(fVar5 * fVar1) >> 0x1f;
      iVar13 = ((int)(fVar5 * fVar1) ^ uVar10) - uVar10;
    }
    pitch = (int)(((float)iVar11 / (float)iVar13) * 70.0 + 30.0);
    if (pitch == 100) {
      pitch = 99;
    }
    EMIT_SOUND_DYN(peVar6->pContainingEntity,6,gpGlobals->pStringBase + peVar6->noise3,
                   this->m_flVolume * ((float)iVar11 / (float)iVar13),this->m_flAttenuation,0xc0,
                   pitch);
  }
  else {
    (peVar6->avelocity).x = fVar7;
    (peVar6->avelocity).y = fVar8;
    (peVar6->avelocity).z = fVar9;
    peVar6 = (this->super_CBaseEntity).pev;
    EMIT_SOUND_DYN(peVar6->pContainingEntity,6,gpGlobals->pStringBase + peVar6->noise3,
                   this->m_flVolume,this->m_flAttenuation,0xc0,100);
    peVar6 = (this->super_CBaseEntity).pev;
    (this->super_CBaseEntity).m_pfnThink.__pfn = Rotate;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    peVar6->nextthink = peVar6->ltime + 10.0;
  }
  return;
}


// CFuncRotating::SpinDown  @ 00070740  (line 611)

/* DWARF original prototype: void SpinDown(CFuncRotating * this) */

void __thiscall CFuncRotating::SpinDown(CFuncRotating *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  entvars_t *peVar5;
  _2globalvars_t *p1Var6;
  uint uVar7;
  int pitch;
  uint uVar8;
  uint uVar9;
  float local_14;
  
                    /* Unresolved local var: Vector vecAVel@[???]
                       Unresolved local var: vec_t vecdir@[???] */
  peVar5 = (this->super_CBaseEntity).pev;
  peVar5->nextthink = peVar5->ltime + 0.1;
  peVar5 = (this->super_CBaseEntity).pev;
  fVar3 = peVar5->speed * this->m_flFanFriction;
  fVar1 = (peVar5->movedir).z;
  fVar2 = (peVar5->movedir).y;
  (peVar5->avelocity).x = (peVar5->avelocity).x - fVar3 * (peVar5->movedir).x;
  (peVar5->avelocity).y = (peVar5->avelocity).y - fVar2 * fVar3;
  (peVar5->avelocity).z = (peVar5->avelocity).z - fVar1 * fVar3;
  p1Var6 = gpGlobals;
  peVar5 = (this->super_CBaseEntity).pev;
  local_14 = (peVar5->avelocity).x;
  fVar1 = (peVar5->avelocity).y;
  fVar2 = (peVar5->avelocity).z;
  fVar3 = (peVar5->movedir).x;
  fVar4 = fVar3;
  if ((fVar3 == 0.0) && (fVar4 = (peVar5->movedir).y, fVar4 == 0.0)) {
    fVar4 = (peVar5->movedir).z;
  }
  if (((((fVar4 <= 0.0) || (0.0 < local_14)) || (0.0 < fVar1)) || (0.0 < fVar2)) &&
     (((0.0 <= fVar4 || (local_14 < 0.0)) || ((fVar1 < 0.0 || (fVar2 < 0.0)))))) {
                    /* Unresolved local var: Vector vecAVel@[???]
                       Unresolved local var: vec_t vecCur@[???]
                       Unresolved local var: vec_t vecFinal@[???]
                       Unresolved local var: float fpct@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: float fpitch@[???]
                       Unresolved local var: int pitch@[???] */
    if ((local_14 == 0.0) && (local_14 = fVar2, fVar1 != 0.0)) {
      local_14 = fVar1;
    }
    uVar8 = (int)local_14 >> 0x1f;
    if ((fVar3 == 0.0) && (fVar3 = (peVar5->movedir).y, fVar3 == 0.0)) {
      fVar3 = (peVar5->movedir).z;
    }
    uVar7 = (uint)(fVar3 * peVar5->speed);
    uVar9 = (int)uVar7 >> 0x1f;
    fVar1 = (float)(int)(((int)local_14 ^ uVar8) - uVar8) / (float)(int)((uVar7 ^ uVar9) - uVar9);
    pitch = (int)(fVar1 * 70.0 + 30.0);
    if (pitch == 100) {
      pitch = 99;
    }
    EMIT_SOUND_DYN(peVar5->pContainingEntity,6,gpGlobals->pStringBase + peVar5->noise3,
                   this->m_flVolume * fVar1,this->m_flAttenuation,0xc0,pitch);
    return;
  }
  (peVar5->avelocity).x = g_vecZero.x;
  (peVar5->avelocity).y = g_vecZero.y;
  (peVar5->avelocity).z = g_vecZero.z;
  peVar5 = (this->super_CBaseEntity).pev;
  EMIT_SOUND_DYN(peVar5->pContainingEntity,6,p1Var6->pStringBase + peVar5->noise3,0.0,0.0,0x20,
                 (int)this->m_pitch);
  peVar5 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnThink.__pfn = Rotate;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar5->nextthink = peVar5->ltime + 10.0;
  return;
}


// CFuncRotating::Rotate  @ 0006ee60  (line 650)

/* DWARF original prototype: void Rotate(CFuncRotating * this) */

void __thiscall CFuncRotating::Rotate(CFuncRotating *this)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseEntity).pev;
  peVar1->nextthink = peVar1->ltime + 10.0;
  return;
}


// CFuncRotating::RotatingUse  @ 0006f540  (line 657)

/* DWARF original prototype: void RotatingUse(CFuncRotating * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CFuncRotating::RotatingUse
          (CFuncRotating *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  float fVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  
  peVar4 = (this->super_CBaseEntity).pev;
  if ((peVar4->spawnflags & 0x10) == 0) {
    if ((((peVar4->avelocity).x == g_vecZero.x) && ((peVar4->avelocity).y == g_vecZero.y)) &&
       ((peVar4->avelocity).z == g_vecZero.z)) {
      EMIT_SOUND_DYN(peVar4->pContainingEntity,6,gpGlobals->pStringBase + peVar4->noise3,
                     this->m_flVolume,this->m_flAttenuation,0,100);
      peVar4 = (this->super_CBaseEntity).pev;
      fVar1 = peVar4->speed;
      fVar2 = (peVar4->movedir).z;
      fVar3 = (peVar4->movedir).y;
      (peVar4->avelocity).x = fVar1 * (peVar4->movedir).x;
      (peVar4->avelocity).y = fVar3 * fVar1;
      (peVar4->avelocity).z = fVar2 * fVar1;
      peVar4 = (this->super_CBaseEntity).pev;
      (this->super_CBaseEntity).m_pfnThink.__pfn = Rotate;
      (this->super_CBaseEntity).m_pfnThink.__delta = 0;
      peVar4->nextthink = peVar4->ltime + 10.0;
      return;
    }
  }
  else if (((g_vecZero.x == (peVar4->avelocity).x) && (g_vecZero.y == (peVar4->avelocity).y)) &&
          ((peVar4->avelocity).z == g_vecZero.z)) {
    (this->super_CBaseEntity).m_pfnThink.__pfn = SpinUp;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    EMIT_SOUND_DYN(peVar4->pContainingEntity,6,gpGlobals->pStringBase + peVar4->noise3,0.01,
                   this->m_flAttenuation,0,0x1e);
    peVar4 = (this->super_CBaseEntity).pev;
    peVar4->nextthink = peVar4->ltime + 0.1;
    return;
  }
  (this->super_CBaseEntity).m_pfnThink.__pfn = SpinDown;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar4->nextthink = peVar4->ltime + 0.1;
  return;
}


// CFuncRotating::Blocked  @ 0006ee80  (line 710)

/* DWARF original prototype: void Blocked(CFuncRotating * this, CBaseEntity * pOther) */

void __thiscall CFuncRotating::Blocked(CFuncRotating *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseEntity).pev;
  (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar1,peVar1,peVar1->dmg,1);
  return;
}


// CPendulum::~CPendulum  @ 00071100  (line 895)

/* DWARF original prototype: void ~CPendulum(CPendulum * this, int __in_chrg) */

void __thiscall CPendulum::~CPendulum(CPendulum *this,int __in_chrg)

{
  return;
}


// CPendulum::ObjectCaps  @ 000710e0  (line 905)

/* DWARF original prototype: int ObjectCaps(CPendulum * this) */

int __thiscall CPendulum::ObjectCaps(CPendulum *this)

{
  return 0;
}


// func_pendulum  @ 00070ff0  (line 922)

void func_pendulum(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x4a4,pev);
  *puVar1 = &PTR__CPendulum_00148194;
  puVar1[1] = pev;
  return;
}


// CPendulum::Restore  @ 0006fe40  (line 936)

/* DWARF original prototype: int Restore(CPendulum * this, CRestore * restore) */

int __thiscall CPendulum::Restore(CPendulum *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore(&this->super_CBaseEntity,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CPendulum",this,m_SaveData,8);
  }
  return iVar2;
}


// CPendulum::Save  @ 0006ff00  (line 936)

/* DWARF original prototype: int Save(CPendulum * this, CSave * save) */

int __thiscall CPendulum::Save(CPendulum *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save(&this->super_CBaseEntity,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CPendulum",this,m_SaveData,8);
  }
  return iVar2;
}


// CPendulum::KeyValue  @ 0006fcf0  (line 941)

/* DWARF original prototype: void KeyValue(CPendulum * this, KeyValueData * pkvd) */

void __thiscall CPendulum::KeyValue(CPendulum *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  double dVar5;
  
  bVar4 = &stack0x00000000 == (undefined1 *)0x3c;
  iVar1 = 9;
  pcVar2 = pkvd->szKeyName;
  pcVar3 = "distance";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    dVar5 = strtod(pkvd->szValue,(char **)0x0);
    this->m_distance = (float)dVar5;
    pkvd->fHandled = 1;
  }
  else {
    iVar1 = 5;
    bVar4 = false;
    pcVar2 = pkvd->szKeyName;
    pcVar3 = "damp";
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
    dVar5 = strtod(pkvd->szValue,(char **)0x0);
    this->m_damp = (float)((longdouble)dVar5 * (longdouble)0.001);
    pkvd->fHandled = 1;
  }
  return;
}


// CPendulum::Spawn  @ 0006fb50  (line 958)

/* DWARF original prototype: void Spawn(CPendulum * this) */

void __thiscall CPendulum::Spawn(CPendulum *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  _2globalvars_t *p1Var6;
  entvars_t *peVar7;
  
  CBaseToggle::AxisDir((this->super_CBaseEntity).pev);
  peVar7 = (this->super_CBaseEntity).pev;
  peVar7->solid = -(uint)((peVar7->spawnflags & 8U) == 0) & 4;
  ((this->super_CBaseEntity).pev)->movetype = 7;
  peVar7 = (this->super_CBaseEntity).pev;
  UTIL_SetOrigin(peVar7,&peVar7->origin);
  peVar7 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar7->pContainingEntity,gpGlobals->pStringBase + peVar7->model);
  fVar1 = this->m_distance;
  if (fVar1 != 0.0) {
    peVar7 = (this->super_CBaseEntity).pev;
    fVar2 = peVar7->speed;
    if (fVar2 == 0.0) {
      peVar7->speed = 100.0;
      peVar7 = (this->super_CBaseEntity).pev;
      fVar2 = peVar7->speed;
      fVar1 = this->m_distance;
    }
    this->m_accel = (fVar2 * fVar2) / (ABS(fVar1) + ABS(fVar1));
    fVar1 = fVar1 * 0.5;
    this->m_maxSpeed = peVar7->speed;
    (this->m_start).x = (peVar7->angles).x;
    (this->m_start).y = (peVar7->angles).y;
    (this->m_start).z = (peVar7->angles).z;
    fVar2 = (peVar7->movedir).z;
    fVar3 = (peVar7->angles).z;
    fVar4 = (peVar7->movedir).y;
    fVar5 = (peVar7->angles).y;
    (this->m_center).x = fVar1 * (peVar7->movedir).x + (peVar7->angles).x;
    (this->m_center).y = fVar4 * fVar1 + fVar5;
    (this->m_center).z = fVar2 * fVar1 + fVar3;
    p1Var6 = gpGlobals;
    if ((peVar7->spawnflags & 1) != 0) {
      (this->super_CBaseEntity).m_pfnThink.__pfn = CBaseEntity::SUB_CallUseToggle;
      (this->super_CBaseEntity).m_pfnThink.__delta = 0;
      peVar7->nextthink = p1Var6->time + 0.1;
      peVar7 = (this->super_CBaseEntity).pev;
    }
    peVar7->speed = 0.0;
    peVar7 = (this->super_CBaseEntity).pev;
    (this->super_CBaseEntity).m_pfnUse.__pfn = PendulumUse;
    (this->super_CBaseEntity).m_pfnUse.__delta = 0;
    if ((peVar7->spawnflags & 2) != 0) {
      (this->super_CBaseEntity).m_pfnTouch.__pfn = RopeTouch;
      (this->super_CBaseEntity).m_pfnTouch.__delta = 0;
    }
  }
  return;
}


// CPendulum::PendulumUse  @ 0006f720  (line 997)

/* DWARF original prototype: void PendulumUse(CPendulum * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CPendulum::PendulumUse
          (CPendulum *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,float value
          )

{
  float fVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  vec_t vVar5;
  float fVar6;
  
  peVar4 = (this->super_CBaseEntity).pev;
  if (peVar4->speed == 0.0) {
    peVar4->nextthink = peVar4->ltime + 0.1;
    fVar1 = gpGlobals->time;
    this->m_dampSpeed = this->m_maxSpeed;
    (this->super_CBaseEntity).m_pfnThink.__pfn = Swing;
    this->m_time = fVar1;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    return;
  }
  if ((peVar4->spawnflags & 0x10U) != 0) {
                    /* Unresolved local var: float delta@[???] */
    fVar6 = CBaseToggle::AxisDelta(peVar4->spawnflags,&peVar4->angles,&this->m_start);
    peVar4 = (this->super_CBaseEntity).pev;
    fVar1 = this->m_maxSpeed;
    fVar2 = (peVar4->movedir).z;
    fVar3 = (peVar4->movedir).y;
    (peVar4->avelocity).x = fVar1 * (peVar4->movedir).x;
    (peVar4->avelocity).y = fVar3 * fVar1;
    (peVar4->avelocity).z = fVar2 * fVar1;
    peVar4 = (this->super_CBaseEntity).pev;
    peVar4->nextthink = fVar6 / this->m_maxSpeed + peVar4->ltime;
    (this->super_CBaseEntity).m_pfnThink.__pfn = Stop;
    (this->super_CBaseEntity).m_pfnThink.__delta = 0;
    return;
  }
  peVar4->speed = 0.0;
  vVar5 = g_vecZero.x;
  peVar4 = (this->super_CBaseEntity).pev;
  (this->super_CBaseEntity).m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  (peVar4->avelocity).x = vVar5;
  (peVar4->avelocity).y = g_vecZero.y;
  (peVar4->avelocity).z = g_vecZero.z;
  return;
}


// CPendulum::Stop  @ 0006eec0  (line 1028)

/* DWARF original prototype: void Stop(CPendulum * this) */

void __thiscall CPendulum::Stop(CPendulum *this)

{
  entvars_t *peVar1;
  vec_t vVar2;
  
  peVar1 = (this->super_CBaseEntity).pev;
  (peVar1->angles).x = (this->m_start).x;
  (peVar1->angles).y = (this->m_start).y;
  (peVar1->angles).z = (this->m_start).z;
  ((this->super_CBaseEntity).pev)->speed = 0.0;
  vVar2 = g_vecZero.x;
  (this->super_CBaseEntity).m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
  (this->super_CBaseEntity).m_pfnThink.__delta = 0;
  peVar1 = (this->super_CBaseEntity).pev;
  (peVar1->avelocity).x = vVar2;
  (peVar1->avelocity).y = g_vecZero.y;
  (peVar1->avelocity).z = g_vecZero.z;
  return;
}


// CPendulum::Blocked  @ 0006ef20  (line 1038)

/* DWARF original prototype: void Blocked(CPendulum * this, CBaseEntity * pOther) */

void __thiscall CPendulum::Blocked(CPendulum *this,CBaseEntity *pOther)

{
  this->m_time = gpGlobals->time;
  return;
}


// CPendulum::Swing  @ 0006f840  (line 1043)

/* DWARF original prototype: void Swing(CPendulum * this) */

void __thiscall CPendulum::Swing(CPendulum *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  vec_t vVar4;
  entvars_t *peVar5;
  float fVar6;
  
                    /* Unresolved local var: float delta@[???]
                       Unresolved local var: float dt@[???] */
  peVar5 = (this->super_CBaseEntity).pev;
  fVar6 = CBaseToggle::AxisDelta(peVar5->spawnflags,&peVar5->angles,&this->m_center);
  fVar3 = gpGlobals->time - this->m_time;
  this->m_time = gpGlobals->time;
  fVar1 = this->m_accel;
  if ((fVar6 <= 0.0) || (fVar1 <= 0.0)) {
    peVar5 = (this->super_CBaseEntity).pev;
    peVar5->speed = fVar1 * fVar3 + peVar5->speed;
  }
  else {
    peVar5 = (this->super_CBaseEntity).pev;
    peVar5->speed = peVar5->speed - fVar1 * fVar3;
  }
  peVar5 = (this->super_CBaseEntity).pev;
  fVar6 = peVar5->speed;
  fVar1 = this->m_maxSpeed;
  if ((fVar1 < fVar6) || (fVar1 = -fVar1, fVar6 < fVar1)) {
    peVar5->speed = fVar1;
    peVar5 = (this->super_CBaseEntity).pev;
    fVar6 = peVar5->speed;
  }
  fVar1 = (peVar5->movedir).z;
  fVar2 = (peVar5->movedir).y;
  (peVar5->avelocity).x = fVar6 * (peVar5->movedir).x;
  (peVar5->avelocity).y = fVar2 * fVar6;
  (peVar5->avelocity).z = fVar1 * fVar6;
  peVar5 = (this->super_CBaseEntity).pev;
  peVar5->nextthink = peVar5->ltime + 0.1;
  if (this->m_damp != 0.0) {
    peVar5 = (this->super_CBaseEntity).pev;
    fVar1 = this->m_dampSpeed - this->m_damp * this->m_dampSpeed * fVar3;
    this->m_dampSpeed = fVar1;
    if (fVar1 < 30.0) {
      (peVar5->angles).x = (this->m_center).x;
      (peVar5->angles).y = (this->m_center).y;
      (peVar5->angles).z = (this->m_center).z;
      vVar4 = g_vecZero.x;
      ((this->super_CBaseEntity).pev)->speed = 0.0;
      peVar5 = (this->super_CBaseEntity).pev;
      (this->super_CBaseEntity).m_pfnThink.__pfn = (_func___thiscall_void_CBaseEntity_ptr *)0x0;
      (this->super_CBaseEntity).m_pfnThink.__delta = 0;
      (peVar5->avelocity).x = vVar4;
      (peVar5->avelocity).y = g_vecZero.y;
      (peVar5->avelocity).z = g_vecZero.z;
      return;
    }
    if ((fVar1 < peVar5->speed) || (fVar1 = -fVar1, peVar5->speed < fVar1)) {
      peVar5->speed = fVar1;
    }
  }
  return;
}


// CPendulum::Touch  @ 00070010  (line 1085)

/* DWARF original prototype: void Touch(CPendulum * this, CBaseEntity * pOther) */

void __thiscall CPendulum::Touch(CPendulum *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  entvars_t *peVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float __x;
  float fVar6;
  float fVar7;
  
                    /* Unresolved local var: entvars_t * pevOther@[???]
                       Unresolved local var: float damage@[???] */
  peVar1 = (this->super_CBaseEntity).pev;
  if ((0.0 < peVar1->dmg) && (peVar2 = pOther->pev, peVar2->takedamage != 0.0)) {
    fVar3 = peVar1->dmg * peVar1->speed * 0.01;
    fVar4 = -fVar3;
    if (0.0 <= fVar3) {
      fVar4 = fVar3;
    }
    (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar1,peVar1,fVar4,1);
    peVar1 = (this->super_CBaseEntity).pev;
    fVar5 = (peVar2->origin).z - ((peVar1->size).z * 0.5 + (peVar1->absmin).z);
    fVar6 = (peVar2->origin).y - ((peVar1->size).y * 0.5 + (peVar1->absmin).y);
    fVar3 = (peVar2->origin).x - ((peVar1->size).x * 0.5 + (peVar1->absmin).x);
                    /* Unresolved local var: float flLen@[???] */
    __x = fVar5 * fVar5 + fVar6 * fVar6 + fVar3 * fVar3;
    fVar7 = SQRT(__x);
    if (NAN(fVar7)) {
      fVar7 = sqrtf(__x);
    }
    if (fVar7 == 0.0) {
      fVar5 = 1.0;
      fVar7 = 0.0;
      fVar6 = 0.0;
    }
    else {
      fVar7 = 1.0 / fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
      fVar7 = fVar7 * fVar3;
    }
    (peVar2->velocity).x = fVar7 * fVar4;
    (peVar2->velocity).y = fVar6 * fVar4;
    (peVar2->velocity).z = fVar5 * fVar4;
  }
  return;
}


// CPendulum::RopeTouch  @ 0006fa30  (line 1108)

/* DWARF original prototype: void RopeTouch(CPendulum * this, CBaseEntity * pOther) */

void __thiscall CPendulum::RopeTouch(CPendulum *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  entvars_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pevOther@[???] */
  peVar1 = pOther->pev;
  if ((peVar1->flags & 8) != 0) {
    peVar2 = (this->super_CBaseEntity).pev;
    if (peVar2->enemy != peVar1->pContainingEntity) {
      peVar2->enemy = peVar1->pContainingEntity;
      (peVar1->velocity).x = g_vecZero.x;
      (peVar1->velocity).y = g_vecZero.y;
      (peVar1->velocity).z = g_vecZero.z;
      peVar1->movetype = 0;
    }
    return;
  }
                    /* Unresolved local var: entvars_t * pevOther@[???] */
                    /* WARNING: Could not recover jumptable at 0x0006fa92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnAlertMessage)(at_console,"Not a client\n");
  return;
}


