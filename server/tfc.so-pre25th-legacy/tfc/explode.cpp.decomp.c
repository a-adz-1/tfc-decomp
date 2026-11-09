// Ghidra decompilation of functions from tfc/explode.cpp
// 13 functions, ordered by original source line

// CShower::ObjectCaps  @ 000d2590  (line 29)

/* DWARF original prototype: int ObjectCaps(CShower * this) */

int __thiscall CShower::ObjectCaps(CShower *this)

{
  return -0x80000000;
}


// spark_shower  @ 000d23d0  (line 32)

void spark_shower(entvars_t *pev)

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
  *puVar1 = &PTR__CShower_0017e4c8;
  puVar1[1] = pev;
  return;
}


// CShower::Spawn  @ 000d2100  (line 35)

/* DWARF original prototype: void Spawn(CShower * this) */

void __thiscall CShower::Spawn(CShower *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  vec_t vVar5;
  globalvars_t *pgVar6;
  longdouble lVar7;
  
  peVar4 = (this->super_CBaseEntity).pev;
  lVar7 = (longdouble)(*g_engfuncs.pfnRandomFloat)(200.0,300.0);
  fVar2 = (peVar4->angles).z;
  fVar3 = (peVar4->angles).y;
  (peVar4->velocity).x = (float)(lVar7 * (longdouble)(peVar4->angles).x);
  (peVar4->velocity).y = (float)((longdouble)fVar3 * lVar7);
  (peVar4->velocity).z = (float)((longdouble)fVar2 * lVar7);
  peVar4 = (this->super_CBaseEntity).pev;
  fVar2 = (peVar4->velocity).x;
  lVar7 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-100.0,100.0);
  (peVar4->velocity).x = (float)(lVar7 + (longdouble)fVar2);
  peVar4 = (this->super_CBaseEntity).pev;
  fVar2 = (peVar4->velocity).y;
  lVar7 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-100.0,100.0);
  (peVar4->velocity).y = (float)(lVar7 + (longdouble)fVar2);
  peVar4 = (this->super_CBaseEntity).pev;
  fVar2 = (peVar4->velocity).z;
  if (0.0 <= fVar2) {
    (peVar4->velocity).z = fVar2 + 200.0;
  }
  else {
    (peVar4->velocity).z = fVar2 - 200.0;
  }
  pgVar6 = gpGlobals;
  ((this->super_CBaseEntity).pev)->movetype = 10;
  ((this->super_CBaseEntity).pev)->gravity = 0.5;
  ((this->super_CBaseEntity).pev)->nextthink = pgVar6->time + 0.1;
  ((this->super_CBaseEntity).pev)->solid = 0;
  (*g_engfuncs.pfnSetModel)(((this->super_CBaseEntity).pev)->pContainingEntity,"models/grenade.mdl")
  ;
  UTIL_SetSize((this->super_CBaseEntity).pev,&g_vecZero,&g_vecZero);
  piVar1 = &((this->super_CBaseEntity).pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  peVar4 = (this->super_CBaseEntity).pev;
  lVar7 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.5,1.5);
  vVar5 = g_vecZero.x;
  peVar4->speed = (float)lVar7;
  peVar4 = (this->super_CBaseEntity).pev;
  (peVar4->angles).x = vVar5;
  (peVar4->angles).y = g_vecZero.y;
  (peVar4->angles).z = g_vecZero.z;
  return;
}


// CShower::Think  @ 000d2090  (line 57)

/* DWARF original prototype: void Think(CShower * this) */

void __thiscall CShower::Think(CShower *this)

{
  int *piVar1;
  entvars_t *peVar2;
  
  UTIL_Sparks(&((this->super_CBaseEntity).pev)->origin);
  peVar2 = (this->super_CBaseEntity).pev;
  peVar2->speed = peVar2->speed - 0.1;
  peVar2 = (this->super_CBaseEntity).pev;
  if (peVar2->speed <= 0.0) {
    UTIL_Remove(&this->super_CBaseEntity);
  }
  else {
    peVar2->nextthink = gpGlobals->time + 0.1;
  }
  piVar1 = &((this->super_CBaseEntity).pev)->flags;
  *piVar1 = *piVar1 & 0xfffffdff;
  return;
}


// CShower::Touch  @ 000d1b50  (line 69)

/* DWARF original prototype: void Touch(CShower * this, CBaseEntity * pOther) */

void __thiscall CShower::Touch(CShower *this,CBaseEntity *pOther)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  
  peVar3 = (this->super_CBaseEntity).pev;
  if ((peVar3->flags & 0x200) == 0) {
    fVar1 = 0.6;
  }
  else {
    fVar1 = 0.1;
  }
  (peVar3->velocity).x = fVar1 * (peVar3->velocity).x;
  (peVar3->velocity).y = (peVar3->velocity).y * fVar1;
  (peVar3->velocity).z = (peVar3->velocity).z * fVar1;
  peVar3 = (this->super_CBaseEntity).pev;
  fVar1 = (peVar3->velocity).x;
  fVar2 = (peVar3->velocity).y;
  if (fVar2 * fVar2 + fVar1 * fVar1 < 10.0) {
    peVar3->speed = 0.0;
  }
  return;
}


// CEnvExplosion::Restore  @ 000d2280  (line 101)

/* DWARF original prototype: int Restore(CEnvExplosion * this, CRestore * restore) */

int __thiscall CEnvExplosion::Restore(CEnvExplosion *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Restore(&this->super_CBaseMonster,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CEnvExplosion",this,m_SaveData,2);
  }
  return iVar2;
}


// CEnvExplosion::Save  @ 000d22e0  (line 101)

/* DWARF original prototype: int Save(CEnvExplosion * this, CSave * save) */

int __thiscall CEnvExplosion::Save(CEnvExplosion *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Save(&this->super_CBaseMonster,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CEnvExplosion",this,m_SaveData,2);
  }
  return iVar2;
}


// env_explosion  @ 000d2440  (line 102)

void env_explosion(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6c4,pev);
  *puVar1 = &PTR__CEnvExplosion_0017e5e8;
  puVar1[1] = pev;
  return;
}


// CEnvExplosion::KeyValue  @ 000d2340  (line 105)

/* DWARF original prototype: void KeyValue(CEnvExplosion * this, KeyValueData * pkvd) */

void __thiscall CEnvExplosion::KeyValue(CEnvExplosion *this,KeyValueData *pkvd)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  bVar5 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar2 = 0xb;
  pcVar3 = pkvd->szKeyName;
  pcVar4 = "iMagnitude";
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
  lVar1 = strtol(pkvd->szValue,(char **)0x0,10);
  this->m_iMagnitude = lVar1;
  pkvd->fHandled = 1;
  return;
}


// CEnvExplosion::Spawn  @ 000d1bc0  (line 116)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CEnvExplosion * this) */

void __thiscall CEnvExplosion::Spawn(CEnvExplosion *this)

{
  float fVar1;
  int iVar2;
  
                    /* Unresolved local var: float flSpriteScale@[???] */
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->effects = 0x80;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 0;
  iVar2 = 10;
  fVar1 = (float)(this->m_iMagnitude + -0x32) * 0.6;
  if (10.0 <= fVar1) {
    iVar2 = (int)fVar1;
  }
  this->m_spriteScale = iVar2;
  return;
}


// CEnvExplosion::Use  @ 000d1d10  (line 146)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Use(CEnvExplosion * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CEnvExplosion::Use(CEnvExplosion *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType
                  ,float value)

{
  float fVar1;
  globalvars_t *pgVar2;
  uint uVar3;
  entvars_t *peVar4;
  int32 iVar5;
  int iVar6;
  longdouble extraout_ST0;
  TraceResult local_6c;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSpot@[???] */
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->model = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 0;
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_34.z = (peVar4->origin).z + 8.0;
  local_34.y = (peVar4->origin).y + 0.0;
  local_34.x = (peVar4->origin).x + 0.0;
  local_28[0].x = local_34.x + 0.0;
  local_28[0].y = local_34.y + 0.0;
  local_28[0].z = local_34.z - 40.0;
  UTIL_TraceLine(&local_34,local_28,ignore_monsters,peVar4->pContainingEntity,&local_6c);
  if (local_6c.flFraction == 1.0) {
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    uVar3 = peVar4->spawnflags;
  }
  else {
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar1 = (float)(this->m_iMagnitude + -0x18);
    (peVar4->origin).x = fVar1 * local_6c.vecPlaneNormal.x * 0.6 + local_6c.vecEndPos.x;
    (peVar4->origin).y = local_6c.vecPlaneNormal.y * fVar1 * 0.6 + local_6c.vecEndPos.y;
    (peVar4->origin).z = local_6c.vecPlaneNormal.z * fVar1 * 0.6 + local_6c.vecEndPos.z;
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    uVar3 = peVar4->spawnflags;
  }
  if ((uVar3 & 0x10) == 0) {
    (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
    if ((longdouble)0.5 <= extraout_ST0) {
      UTIL_DecalTrace(&local_6c,0xc);
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      uVar3 = peVar4->spawnflags;
    }
    else {
      UTIL_DecalTrace(&local_6c,0xb);
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      uVar3 = peVar4->spawnflags;
    }
  }
  if ((uVar3 & 4) == 0) {
    (*g_engfuncs.pfnMessageBegin)(5,0x17,&(peVar4->origin).x,(edict_t *)0x0);
    (*g_engfuncs.pfnWriteByte)(3);
    (*g_engfuncs.pfnWriteCoord)
              ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->origin).x);
    (*g_engfuncs.pfnWriteCoord)
              ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->origin).y);
    (*g_engfuncs.pfnWriteCoord)
              ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->origin).z);
    (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexFireball);
    uVar3 = (uint)(byte)this->m_spriteScale;
  }
  else {
    (*g_engfuncs.pfnMessageBegin)(5,0x17,&(peVar4->origin).x,(edict_t *)0x0);
    (*g_engfuncs.pfnWriteByte)(3);
    (*g_engfuncs.pfnWriteCoord)
              ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->origin).x);
    (*g_engfuncs.pfnWriteCoord)
              ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->origin).y);
    (*g_engfuncs.pfnWriteCoord)
              ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->origin).z);
    (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexFireball);
    uVar3 = 0;
  }
  (*g_engfuncs.pfnWriteByte)(uVar3);
  (*g_engfuncs.pfnWriteByte)(0xf);
  (*g_engfuncs.pfnWriteByte)(3);
  (*g_engfuncs.pfnMessageEnd)();
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar4->spawnflags & 1) == 0) {
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x7f])
              (this,peVar4,peVar4,(float)this->m_iMagnitude,0,0x40);
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  pgVar2 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = Smoke;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar4->nextthink = pgVar2->time + 0.3;
                    /* Unresolved local var: int sparkCount@[???] */
                    /* Unresolved local var: int i@[???] */
  if (((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->spawnflags & 0x20) == 0) &&
     (iVar5 = (*g_engfuncs.pfnRandomLong)(0,3), 0 < iVar5)) {
    iVar6 = 0;
    do {
      iVar6 = iVar6 + 1;
      CBaseEntity::Create("spark_shower",
                          &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->origin,&local_6c.vecPlaneNormal
                          ,(edict_t *)0x0);
    } while (iVar6 != iVar5);
    return;
  }
  return;
}


// CEnvExplosion::Smoke  @ 000d1c40  (line 231)

/* DWARF original prototype: void Smoke(CEnvExplosion * this) */

void __thiscall CEnvExplosion::Smoke(CEnvExplosion *this)

{
  entvars_t *peVar1;
  uint uVar2;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  uVar2 = peVar1->spawnflags;
  if ((uVar2 & 8) == 0) {
    (*g_engfuncs.pfnMessageBegin)(5,0x17,&(peVar1->origin).x,(edict_t *)0x0);
    (*g_engfuncs.pfnWriteByte)(5);
    (*g_engfuncs.pfnWriteCoord)
              ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->origin).x);
    (*g_engfuncs.pfnWriteCoord)
              ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->origin).y);
    (*g_engfuncs.pfnWriteCoord)
              ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->origin).z);
    (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexSmoke);
    (*g_engfuncs.pfnWriteByte)((uint)(byte)this->m_spriteScale);
    (*g_engfuncs.pfnWriteByte)(0xc);
    (*g_engfuncs.pfnMessageEnd)();
    uVar2 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->spawnflags;
  }
  if ((uVar2 & 2) != 0) {
    return;
  }
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// ExplosionCreate  @ 000d24b0  (line 254)

void ExplosionCreate(Vector *center,Vector *angles,edict_t *pOwner,int magnitude,BOOL doDamage)

{
  int *piVar1;
  CBaseEntity *pCVar2;
  char local_9c [128];
  undefined1 local_1c [4];
  char *local_18;
  char *local_14;
  
                    /* Unresolved local var: KeyValueData kvd@[???]
                       Unresolved local var: char[128] buf@[???]
                       Unresolved local var: CBaseEntity * pExplosion@[???] */
  pCVar2 = CBaseEntity::Create("env_explosion",center,angles,pOwner);
  sprintf(local_9c,"%3d",magnitude);
  local_18 = "iMagnitude";
  local_14 = local_9c;
  (*pCVar2->_vptr_CBaseEntity[4])(pCVar2,local_1c);
  if (doDamage == 0) {
    piVar1 = &pCVar2->pev->spawnflags;
    *piVar1 = *piVar1 | 1;
  }
  (*pCVar2->_vptr_CBaseEntity[2])(pCVar2);
  (*pCVar2->_vptr_CBaseEntity[0x2d])(pCVar2,0,0,3,0);
  return;
}


