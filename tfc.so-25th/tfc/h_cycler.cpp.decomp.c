// Ghidra decompilation of functions from tfc/h_cycler.cpp
// 42 functions, ordered by original source line

// CCycler::~CCycler  @ 000a3660  (line 30)

/* DWARF original prototype: void ~CCycler(CCycler * this, int __in_chrg) */

void __thiscall CCycler::~CCycler(CCycler *this,int __in_chrg)

{
  return;
}


// CCycler::ObjectCaps  @ 000a3610  (line 34)

/* DWARF original prototype: int ObjectCaps(CCycler * this) */

int __thiscall CCycler::ObjectCaps(CCycler *this)

{
  return 10;
}


// CCycler::IsAlive  @ 000a3620  (line 42)

/* DWARF original prototype: BOOL IsAlive(CCycler * this) */

BOOL __thiscall CCycler::IsAlive(CCycler *this)

{
  return 0;
}


// CCycler::Restore  @ 000a2d90  (line 56)

/* DWARF original prototype: int Restore(CCycler * this, CRestore * restore) */

int __thiscall CCycler::Restore(CCycler *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Restore(&this->super_CBaseMonster,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CCycler",this,m_SaveData,1);
  }
  return iVar2;
}


// CCycler::Save  @ 000a2e50  (line 56)

/* DWARF original prototype: int Save(CCycler * this, CSave * save) */

int __thiscall CCycler::Save(CCycler *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Save(&this->super_CBaseMonster,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CCycler",this,m_SaveData,1);
  }
  return iVar2;
}


// CGenericCycler::~CGenericCycler  @ 000a36b0  (line 62)

/* DWARF original prototype: void ~CGenericCycler(CGenericCycler * this, int __in_chrg) */

void __thiscall CGenericCycler::~CGenericCycler(CGenericCycler *this,int __in_chrg)

{
  return;
}


// CGenericCycler::Spawn  @ 000a36c0  (line 65)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CGenericCycler * this) */

void __thiscall CGenericCycler::Spawn(CGenericCycler *this)

{
  entvars_t *peVar1;
  char *pcVar2;
  Vector local_34;
  Vector local_28 [2];
  
  peVar1 = (this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  local_28[0].x = 16.0;
  local_28[0].y = 16.0;
  pcVar2 = gpGlobals->pStringBase + peVar1->model;
  local_28[0].z = 72.0;
  local_34.x = -16.0;
  local_34.y = -16.0;
  local_34.z = 0.0;
  if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {
    (*g_engfuncs.pfnAlertMessage)
              (at_error,"cycler at %.0f %.0f %0.f missing modelname",(double)(peVar1->origin).x,
               (double)(peVar1->origin).y,(double)(peVar1->origin).z);
    (*g_engfuncs.pfnRemoveEntity)
              (((this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  }
  else {
    peVar1->classname = (int)"cycler" - (int)gpGlobals->pStringBase;
    (*g_engfuncs.pfnPrecacheModel)(pcVar2);
    (*g_engfuncs.pfnSetModel)
              (((this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,pcVar2);
    CBaseAnimating::InitBoneControllers((CBaseAnimating *)this);
    ((this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
     super_CBaseDelay.super_CBaseEntity.pev)->solid = 3;
    ((this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
     super_CBaseDelay.super_CBaseEntity.pev)->movetype = 0;
    ((this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
     super_CBaseDelay.super_CBaseEntity.pev)->takedamage = 1.0;
    ((this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
     super_CBaseDelay.super_CBaseEntity.pev)->effects = 0;
    ((this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
     super_CBaseDelay.super_CBaseEntity.pev)->health = 80000.0;
    ((this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
     super_CBaseDelay.super_CBaseEntity.pev)->yaw_speed = 5.0;
    peVar1 = (this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    peVar1->ideal_yaw = (peVar1->angles).y;
    (**(code **)((int)(this->super_CCycler).super_CBaseMonster.super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity +
                0x114))(this,0x168);
    peVar1 = (this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    (this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.m_flFrameRate =
         75.0;
    (this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.m_flGroundSpeed
         = 0.0;
    peVar1->nextthink = peVar1->nextthink + 1.0;
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
    peVar1 = (this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    if ((peVar1->sequence == 0) && (peVar1->frame == 0.0)) {
      (this->super_CCycler).m_animate = 1;
    }
    else {
      (this->super_CCycler).m_animate = 0;
      peVar1->framerate = 0.0;
      peVar1 = (this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev;
    }
    UTIL_SetSize(peVar1,&local_34,local_28);
  }
  return;
}


// cycler  @ 000a3170  (line 67)

void cycler(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6c0,pev);
  *puVar1 = &PTR__CGenericCycler_001514cc;
  puVar1[1] = pev;
  return;
}


// CCyclerProbe::~CCyclerProbe  @ 000a36a0  (line 75)

/* DWARF original prototype: void ~CCyclerProbe(CCyclerProbe * this, int __in_chrg) */

void __thiscall CCyclerProbe::~CCyclerProbe(CCyclerProbe *this,int __in_chrg)

{
  return;
}


// cycler_prdroid  @ 000a31e0  (line 80)

void cycler_prdroid(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6c0,pev);
  *puVar1 = &PTR__CCyclerProbe_001516ec;
  puVar1[1] = pev;
  return;
}


// CCyclerProbe::Spawn  @ 000a2fd0  (line 82)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CCyclerProbe * this) */

void __thiscall CCyclerProbe::Spawn(CCyclerProbe *this)

{
  _2globalvars_t *p1Var1;
  entvars_t *peVar2;
  Vector local_24;
  Vector local_18;
  
  p1Var1 = gpGlobals;
  local_24.x = -16.0;
  peVar2 = (this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  local_24.y = -16.0;
  (peVar2->origin).x = (peVar2->origin).x + 0.0;
  (peVar2->origin).y = (peVar2->origin).y + 0.0;
  (peVar2->origin).z = (peVar2->origin).z + 16.0;
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 16.0;
  local_24.z = -16.0;
  ((this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->classname = (int)"cycler" - (int)p1Var1->pStringBase;
  (*g_engfuncs.pfnPrecacheModel)("models/prdroid.mdl");
  (*g_engfuncs.pfnSetModel)
            (((this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/prdroid.mdl");
  CBaseAnimating::InitBoneControllers((CBaseAnimating *)this);
  ((this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 3;
  ((this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 0;
  ((this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 1.0;
  ((this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->effects = 0;
  ((this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->health = 80000.0;
  ((this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->yaw_speed = 5.0;
  peVar2 = (this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  peVar2->ideal_yaw = (peVar2->angles).y;
  (**(code **)((int)(this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0x114))(this,0x168);
  peVar2 = (this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.m_flFrameRate =
       75.0;
  (this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.m_flGroundSpeed =
       0.0;
  peVar2->nextthink = peVar2->nextthink + 1.0;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  peVar2 = (this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  if ((peVar2->sequence == 0) && (peVar2->frame == 0.0)) {
    (this->super_CCycler).m_animate = 1;
  }
  else {
    (this->super_CCycler).m_animate = 0;
    peVar2->framerate = 0.0;
    peVar2 = (this->super_CCycler).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
  }
  UTIL_SetSize(peVar2,&local_24,&local_18);
  return;
}


// CCycler::GenericCyclerSpawn  @ 000a3250  (line 92)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void GenericCyclerSpawn(CCycler * this, char * szModel, Vector vecMin,
   Vector vecMax) */

void __thiscall CCycler::GenericCyclerSpawn(CCycler *this,char *szModel,Vector vecMin,Vector vecMax)

{
  entvars_t *peVar1;
  
  if ((szModel != (char *)0x0) && (*szModel != '\0')) {
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->classname = (int)"cycler" - (int)gpGlobals->pStringBase;
    (*g_engfuncs.pfnPrecacheModel)(szModel);
    (*g_engfuncs.pfnSetModel)
              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity,szModel);
    CBaseAnimating::InitBoneControllers((CBaseAnimating *)this);
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->solid = 3;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->movetype = 0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->takedamage = 1.0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->effects = 0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->health = 80000.0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->yaw_speed = 5.0;
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    peVar1->ideal_yaw = (peVar1->angles).y;
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x45])(this,0x168);
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_flFrameRate = 75.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_flGroundSpeed = 0.0;
    peVar1->nextthink = peVar1->nextthink + 1.0;
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((peVar1->sequence == 0) && (peVar1->frame == 0.0)) {
      this->m_animate = 1;
    }
    else {
      this->m_animate = 0;
      peVar1->framerate = 0.0;
      peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    UTIL_SetSize(peVar1,(Vector *)vecMin.x,(Vector *)vecMin.y);
    return;
  }
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnAlertMessage)
            (at_error,"cycler at %.0f %.0f %0.f missing modelname",(double)(peVar1->origin).x,
             (double)(peVar1->origin).y,(double)(peVar1->origin).z);
                    /* WARNING: Could not recover jumptable at 0x000a32d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnRemoveEntity)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  return;
}


// CCycler::Spawn  @ 000a2650  (line 111)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CCycler * this) */

void __thiscall CCycler::Spawn(CCycler *this)

{
  entvars_t *peVar1;
  
  CBaseAnimating::InitBoneControllers((CBaseAnimating *)this);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 3;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 1.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->effects = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->health = 80000.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->yaw_speed = 5.0;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar1->ideal_yaw = (peVar1->angles).y;
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x45])(this,0x168);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_flFrameRate = 75.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_flGroundSpeed = 0.0;
  peVar1->nextthink = peVar1->nextthink + 1.0;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar1->sequence == 0) && (peVar1->frame == 0.0)) {
    this->m_animate = 1;
    return;
  }
  this->m_animate = 0;
  peVar1->framerate = 0.0;
  return;
}


// CCycler::Think  @ 000a2c70  (line 147)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Think(CCycler * this) */

void __thiscall CCycler::Think(CCycler *this)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  if (this->m_animate != 0) {
    CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  }
  p1Var2 = gpGlobals;
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceFinished != 0)
     && ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceLoops == 0)) {
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->animtime = gpGlobals->time;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->framerate = 1.0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceFinished = 0;
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_flLastEventCheck =
         p1Var2->time;
    peVar1->frame = 0.0;
    if (this->m_animate == 0) {
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->framerate = 0.0;
    }
  }
  return;
}


// CCycler::Use  @ 000a2350  (line 172)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Use(CCycler * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CCycler::Use(CCycler *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,float value
            )

{
  entvars_t *peVar1;
  bool bVar2;
  
  bVar2 = this->m_animate == 0;
  this->m_animate = (uint)bVar2;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (!bVar2) {
    peVar1->framerate = 0.0;
    return;
  }
  peVar1->framerate = 1.0;
  return;
}


// CCycler::TakeDamage  @ 000a2ba0  (line 185)

/* DWARF original prototype: int TakeDamage(CCycler * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CCycler::TakeDamage(CCycler *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
                   int bitsDamageType)

{
  int *piVar1;
  entvars_t *peVar2;
  
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (this->m_animate == 0) {
    peVar2->framerate = 1.0;
    CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.1);
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->framerate = 0.0;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"sequence: %d, frame %.0f\n",peVar2->sequence,(double)peVar2->frame);
    return 0;
  }
  piVar1 = &peVar2->sequence;
  *piVar1 = *piVar1 + 1;
  CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_flFrameRate == 0.0) {
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->sequence = 0;
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
  }
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->frame = 0.0;
  return 0;
}


// CCyclerSprite::~CCyclerSprite  @ 000a3690  (line 213)

/* DWARF original prototype: void ~CCyclerSprite(CCyclerSprite * this, int __in_chrg) */

void __thiscall CCyclerSprite::~CCyclerSprite(CCyclerSprite *this,int __in_chrg)

{
  return;
}


// CCyclerSprite::ObjectCaps  @ 000a3630  (line 219)

/* DWARF original prototype: int ObjectCaps(CCyclerSprite * this) */

int __thiscall CCyclerSprite::ObjectCaps(CCyclerSprite *this)

{
  return -0x7ffffff6;
}


// cycler_sprite  @ 000a3440  (line 233)

void cycler_sprite(entvars_t *pev)

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
  *puVar1 = &PTR__CCyclerSprite_00151b2c;
  puVar1[1] = pev;
  return;
}


// CCyclerSprite::Restore  @ 000a2ae0  (line 242)

/* DWARF original prototype: int Restore(CCyclerSprite * this, CRestore * restore) */

int __thiscall CCyclerSprite::Restore(CCyclerSprite *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore(&this->super_CBaseEntity,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CCyclerSprite",this,m_SaveData,3);
  }
  return iVar2;
}


// CCyclerSprite::Save  @ 000a2b40  (line 242)

/* DWARF original prototype: int Save(CCyclerSprite * this, CSave * save) */

int __thiscall CCyclerSprite::Save(CCyclerSprite *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save(&this->super_CBaseEntity,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CCyclerSprite",this,m_SaveData,3);
  }
  return iVar2;
}


// CCyclerSprite::Spawn  @ 000a2390  (line 246)

/* DWARF original prototype: void Spawn(CCyclerSprite * this) */

void __thiscall CCyclerSprite::Spawn(CCyclerSprite *this)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  int iVar3;
  
  ((this->super_CBaseEntity).pev)->solid = 3;
  ((this->super_CBaseEntity).pev)->movetype = 0;
  ((this->super_CBaseEntity).pev)->takedamage = 1.0;
  ((this->super_CBaseEntity).pev)->effects = 0;
  p1Var2 = gpGlobals;
  ((this->super_CBaseEntity).pev)->frame = 0.0;
  ((this->super_CBaseEntity).pev)->nextthink = p1Var2->time + 0.1;
  this->m_animate = 1;
  peVar1 = (this->super_CBaseEntity).pev;
  this->m_lastTime = p1Var2->time;
  (*g_engfuncs.pfnPrecacheModel)(p1Var2->pStringBase + peVar1->model);
  peVar1 = (this->super_CBaseEntity).pev;
  (*g_engfuncs.pfnSetModel)(peVar1->pContainingEntity,gpGlobals->pStringBase + peVar1->model);
  iVar3 = (*g_engfuncs.pfnModelFrames)(((this->super_CBaseEntity).pev)->modelindex);
  this->m_maxFrame = (float)iVar3 - 1.0;
  return;
}


// CCyclerSprite::Think  @ 000a2f20  (line 265)

/* DWARF original prototype: void Think(CCyclerSprite * this) */

void __thiscall CCyclerSprite::Think(CCyclerSprite *this)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  double dVar3;
  
  p1Var2 = gpGlobals;
  if ((this->m_animate != 0) && (1.0 < this->m_maxFrame)) {
    peVar1 = (this->super_CBaseEntity).pev;
    peVar1->frame = (gpGlobals->time - this->m_lastTime) * peVar1->framerate + peVar1->frame;
    if (0.0 < this->m_maxFrame) {
      peVar1 = (this->super_CBaseEntity).pev;
      dVar3 = fmod((double)peVar1->frame,(double)this->m_maxFrame);
      peVar1->frame = (float)dVar3;
      p1Var2 = gpGlobals;
    }
  }
  ((this->super_CBaseEntity).pev)->nextthink = p1Var2->time + 0.1;
  this->m_lastTime = p1Var2->time;
  return;
}


// CCyclerSprite::Use  @ 000a2470  (line 275)

/* DWARF original prototype: void Use(CCyclerSprite * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CCyclerSprite::Use(CCyclerSprite *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType
                  ,float value)

{
  this->m_animate = (uint)(this->m_animate == 0);
                    /* WARNING: Could not recover jumptable at 0x000a24b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnAlertMessage)(at_console,"Sprite: %s\n");
  return;
}


// CCyclerSprite::TakeDamage  @ 000a2eb0  (line 282)

/* DWARF original prototype: int TakeDamage(CCyclerSprite * this, entvars_t * pevInflictor,
   entvars_t * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CCyclerSprite::TakeDamage
          (CCyclerSprite *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  entvars_t *peVar1;
  double dVar2;
  
  if (1.0 < this->m_maxFrame) {
    peVar1 = (this->super_CBaseEntity).pev;
    peVar1->frame = peVar1->frame + 1.0;
    if (0.0 < this->m_maxFrame) {
      peVar1 = (this->super_CBaseEntity).pev;
      dVar2 = fmod((double)peVar1->frame,(double)this->m_maxFrame);
      peVar1->frame = (float)dVar2;
    }
  }
  return 1;
}


// CCyclerSprite::Animate  @ 000a34b0  (line 291)

/* DWARF original prototype: void Animate(CCyclerSprite * this, float frames) */

void __thiscall CCyclerSprite::Animate(CCyclerSprite *this,float frames)

{
  entvars_t *peVar1;
  double dVar2;
  
  peVar1 = (this->super_CBaseEntity).pev;
  peVar1->frame = peVar1->frame + frames;
  if (0.0 < this->m_maxFrame) {
    peVar1 = (this->super_CBaseEntity).pev;
    dVar2 = fmod((double)peVar1->frame,(double)this->m_maxFrame);
    peVar1->frame = (float)dVar2;
  }
  return;
}


// CWeaponCycler::~CWeaponCycler  @ 000a3680  (line 303)

/* DWARF original prototype: void ~CWeaponCycler(CWeaponCycler * this, int __in_chrg) */

void __thiscall CWeaponCycler::~CWeaponCycler(CWeaponCycler *this,int __in_chrg)

{
  return;
}


// CWeaponCycler::iItemSlot  @ 000a3640  (line 307)

/* DWARF original prototype: int iItemSlot(CWeaponCycler * this) */

int __thiscall CWeaponCycler::iItemSlot(CWeaponCycler *this)

{
  return 1;
}


// CWeaponCycler::GetItemInfo  @ 000a3650  (line 308)

/* DWARF original prototype: int GetItemInfo(CWeaponCycler * this, ItemInfo * p) */

int __thiscall CWeaponCycler::GetItemInfo(CWeaponCycler *this,ItemInfo *p)

{
  return 0;
}


// cycler_weapon  @ 000a3510  (line 317)

void cycler_weapon(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x4fc,pev);
  *puVar1 = &PTR__CWeaponCycler_00151c38;
  puVar1[1] = pev;
  return;
}


// CWeaponCycler::Spawn  @ 000a2750  (line 321)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CWeaponCycler * this) */

void __thiscall CWeaponCycler::Spawn(CWeaponCycler *this)

{
  entvars_t *peVar1;
  _2globalvars_t *p1Var2;
  Vector local_24;
  Vector local_18;
  
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 3;
  p1Var2 = gpGlobals;
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 0;
  (*g_engfuncs.pfnPrecacheModel)
            (p1Var2->pStringBase +
             ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->model);
  peVar1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (*g_engfuncs.pfnSetModel)(peVar1->pContainingEntity,gpGlobals->pStringBase + peVar1->model);
  peVar1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  this->m_iszModel = peVar1->model;
  this->m_iModel = peVar1->modelindex;
  UTIL_SetOrigin(peVar1,&peVar1->origin);
  local_24.z = 0.0;
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 16.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  UTIL_SetSize((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = CBasePlayerItem::DefaultTouch;
  (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  return;
}


// CWeaponCycler::Deploy  @ 000a24c0  (line 338)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL Deploy(CWeaponCycler * this) */

BOOL __thiscall CWeaponCycler::Deploy(CWeaponCycler *this)

{
  ((((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
   super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->viewmodel =
       this->m_iszModel;
  (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
  m_flNextAttack = 1.0;
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x59])(this,0,0);
  (this->super_CBasePlayerWeapon).m_iClip = 0;
  return 1;
}


// CWeaponCycler::Holster  @ 000a3580  (line 349)

/* DWARF original prototype: void Holster(CWeaponCycler * this) */

void __thiscall CWeaponCycler::Holster(CWeaponCycler *this)

{
  (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.m_pPlayer)->super_CBaseMonster).
  m_flNextAttack = 0.5;
  return;
}


// CWeaponCycler::PrimaryAttack  @ 000a2520  (line 354)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PrimaryAttack(CWeaponCycler * this) */

void __thiscall CWeaponCycler::PrimaryAttack(CWeaponCycler *this)

{
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x59])
            (this,((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev)->sequence,0);
  (this->super_CBasePlayerWeapon).m_flNextPrimaryAttack = 0.3;
  return;
}


// CWeaponCycler::SecondaryAttack  @ 000a2840  (line 361)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SecondaryAttack(CWeaponCycler * this) */

void __thiscall CWeaponCycler::SecondaryAttack(CWeaponCycler *this)

{
  entvars_t *peVar1;
  void *pmodel;
  float local_14;
  float local_10 [3];
  
                    /* Unresolved local var: float flFrameRate@[???]
                       Unresolved local var: float flGroundSpeed@[???]
                       Unresolved local var: void * pmodel@[???] */
  peVar1 = (this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  peVar1->sequence = (peVar1->sequence + 1) % 8;
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->modelindex = this->m_iModel;
  pmodel = (*g_engfuncs.pfnGetModelPtr)
                     (((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  GetSequenceInfo(pmodel,(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev,&local_14,local_10);
  ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->modelindex = 0;
  if (local_14 == 0.0) {
    ((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->sequence = 0;
  }
  (*(this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x59])
            (this,((this->super_CBasePlayerWeapon).super_CBasePlayerItem.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev)->sequence,0);
  (this->super_CBasePlayerWeapon).m_flNextSecondaryAttack = 0.3;
  return;
}


// CWreckage::~CWreckage  @ 000a3670  (line 384)

/* DWARF original prototype: void ~CWreckage(CWreckage * this, int __in_chrg) */

void __thiscall CWreckage::~CWreckage(CWreckage *this,int __in_chrg)

{
  return;
}


// CWreckage::Restore  @ 000a2d30  (line 400)

/* DWARF original prototype: int Restore(CWreckage * this, CRestore * restore) */

int __thiscall CWreckage::Restore(CWreckage *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Restore(&this->super_CBaseMonster,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CWreckage",this,m_SaveData,1);
  }
  return iVar2;
}


// CWreckage::Save  @ 000a2df0  (line 400)

/* DWARF original prototype: int Save(CWreckage * this, CSave * save) */

int __thiscall CWreckage::Save(CWreckage *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Save(&this->super_CBaseMonster,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CWreckage",this,m_SaveData,1);
  }
  return iVar2;
}


// cycler_wreckage  @ 000a35a0  (line 403)

void cycler_wreckage(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6c0,pev);
  *puVar1 = &PTR__CWreckage_00151dc8;
  puVar1[1] = pev;
  return;
}


// CWreckage::Spawn  @ 000a2560  (line 406)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CWreckage * this) */

void __thiscall CWreckage::Spawn(CWreckage *this)

{
  string_t sVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 0.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->effects = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->frame = 0.0;
  p1Var3 = gpGlobals;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  sVar1 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->model;
  if (sVar1 != 0) {
    (*g_engfuncs.pfnPrecacheModel)(p1Var3->pStringBase + sVar1);
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (*g_engfuncs.pfnSetModel)(peVar2->pContainingEntity,gpGlobals->pStringBase + peVar2->model);
    p1Var3 = gpGlobals;
  }
  this->m_flStartTime = (int)p1Var3->time;
  return;
}


// CWreckage::Precache  @ 000a2620  (line 427)

/* DWARF original prototype: void Precache(CWreckage * this) */

void __thiscall CWreckage::Precache(CWreckage *this)

{
  string_t sVar1;
  
  sVar1 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->model;
  if (sVar1 == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000a264a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheModel)(gpGlobals->pStringBase + sVar1);
  return;
}


// CWreckage::Think  @ 000a2900  (line 432)

/* DWARF original prototype: void Think(CWreckage * this) */

void __thiscall CWreckage::Think(CWreckage *this)

{
  float fVar1;
  _2globalvars_t *p1Var2;
  _func_void_int *p_Var3;
  entvars_t *peVar4;
  int32 iVar5;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: Vector VecSrc@[???] */
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  p1Var2 = gpGlobals;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.2;
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = peVar4->dmgtime;
  if (fVar1 != 0.0) {
    if (fVar1 < p1Var2->time) {
      UTIL_Remove((CBaseEntity *)this);
      return;
    }
    (*g_engfuncs.pfnRandomFloat)(0.0,fVar1 - (float)this->m_flStartTime);
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((longdouble)peVar4->dmgtime - (longdouble)gpGlobals->time < extraout_ST0) {
      return;
    }
  }
                    /* Unresolved local var: Vector VecSrc@[???] */
  (*g_engfuncs.pfnRandomFloat)((peVar4->absmin).x,(peVar4->absmax).x);
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_18 = (float)extraout_ST0_00;
  (*g_engfuncs.pfnRandomFloat)((peVar4->absmin).y,(peVar4->absmax).y);
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_14 = (float)extraout_ST0_01;
  (*g_engfuncs.pfnRandomFloat)((peVar4->absmin).z,(peVar4->absmax).z);
  local_10 = (float)extraout_ST0_02;
  (*g_engfuncs.pfnMessageBegin)(4,0x17,&local_18,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(5);
  (*g_engfuncs.pfnWriteCoord)(local_18);
  (*g_engfuncs.pfnWriteCoord)(local_14);
  (*g_engfuncs.pfnWriteCoord)(local_10);
  (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexSmoke);
  p_Var3 = g_engfuncs.pfnWriteByte;
  iVar5 = (*g_engfuncs.pfnRandomLong)(0,0x31);
  (*p_Var3)(iVar5 + 0x32);
  p_Var3 = g_engfuncs.pfnWriteByte;
  iVar5 = (*g_engfuncs.pfnRandomLong)(0,3);
  (*p_Var3)(iVar5 + 8);
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


