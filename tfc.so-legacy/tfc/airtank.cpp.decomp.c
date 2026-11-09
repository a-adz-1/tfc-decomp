// Ghidra decompilation of functions from tfc/airtank.cpp
// 10 functions, ordered by original source line

// CAirtank::BloodColor  @ 000ad7b0  (line 24)

/* DWARF original prototype: int BloodColor(CAirtank * this) */

int __thiscall CAirtank::BloodColor(CAirtank *this)

{
  return -1;
}


// item_airtank  @ 000ad130  (line 36)

/* WARNING: Type propagation algorithm not settling */

void item_airtank(entvars_t *pev)

{
  CGrenade *this;
  edict_t *peVar1;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar1 != (edict_t *)0x0) {
      pev = &peVar1->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  this = CBaseEntity::operator_new(0x6dc,pev);
  CGrenade::CGrenade(this);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CAirtank_00177b48;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// CAirtank::Restore  @ 000acf60  (line 42)

/* DWARF original prototype: int Restore(CAirtank * this, CRestore * restore) */

int __thiscall CAirtank::Restore(CAirtank *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Restore((CBaseMonster *)this,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CAirtank",this,m_SaveData,1);
  }
  return iVar2;
}


// CAirtank::Save  @ 000acfc0  (line 42)

/* DWARF original prototype: int Save(CAirtank * this, CSave * save) */

int __thiscall CAirtank::Save(CAirtank *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseMonster::Save((CBaseMonster *)this,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CAirtank",this,m_SaveData,1);
  }
  return iVar2;
}


// CAirtank::Spawn  @ 000ace60  (line 46)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CAirtank * this) */

void __thiscall CAirtank::Spawn(CAirtank *this)

{
  int *piVar1;
  entvars_t *peVar2;
  Vector local_24;
  Vector local_18;
  
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0xc))(this);
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->movetype = 5;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->solid = 2;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/w_oxygen.mdl");
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_18.z = 36.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  peVar2 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar2,&peVar2->origin);
  peVar2 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = TankTouch;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = TankThink;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  piVar1 = &peVar2->flags;
  *piVar1 = *piVar1 | 0x20;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->takedamage = 1.0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->health = 20.0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->dmg = 50.0;
  this->m_state = 1;
  return;
}


// CAirtank::Precache  @ 000acd80  (line 67)

/* DWARF original prototype: void Precache(CAirtank * this) */

void __thiscall CAirtank::Precache(CAirtank *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/w_oxygen.mdl");
                    /* WARNING: Could not recover jumptable at 0x000acda1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("doors/aliendoor3.wav");
  return;
}


// CAirtank::Killed  @ 000acdb0  (line 74)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Killed(CAirtank * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, int iGib) */

void __thiscall
CAirtank::Killed(CAirtank *this,entvars_t *pevInflictor,entvars_t *pevAttacker,int iGib)

{
  entvars_t *peVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  local_1c = 0xbf800000;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->owner = pevAttacker->pContainingEntity;
  local_24 = 0;
  local_20 = 0;
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  local_18 = (peVar1->origin).x;
  local_14 = (peVar1->origin).y;
  local_10 = (peVar1->origin).z;
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0x218))
            (this,&local_18,&local_24);
  return;
}


// CAirtank::TankThink  @ 000ace20  (line 84)

/* DWARF original prototype: void TankThink(CAirtank * this) */

void __thiscall CAirtank::TankThink(CAirtank *this)

{
  this->m_state = 1;
  CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)this,USE_TOGGLE,0.0);
  return;
}


// CAirtank::TankTouch  @ 000ad020  (line 92)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TankTouch(CAirtank * this, CBaseEntity * pOther) */

void __thiscall CAirtank::TankTouch(CAirtank *this,CBaseEntity *pOther)

{
  if ((pOther->pev->flags & 8) != 0) {
    if (this->m_state == 0) {
      EMIT_SOUND_DYN(((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                     pContainingEntity,4,"player/pl_swim2.wav",1.0,0.8,0,100);
      return;
    }
    pOther->pev->air_finished = gpGlobals->time + 12.0;
    EMIT_SOUND_DYN(((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,
                   "doors/aliendoor3.wav",1.0,0.8,0,100);
    ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
     super_CBaseDelay.super_CBaseEntity.pev)->nextthink = gpGlobals->time + 30.0;
    this->m_state = 0;
    CBaseDelay::SUB_UseTargets((CBaseDelay *)this,(CBaseEntity *)this,USE_TOGGLE,1.0);
  }
  return;
}


// CBaseEntity::Illumination  @ 000ad550  (line 113)

/* DWARF original prototype: int Illumination(CBaseEntity * this) */

int __thiscall CBaseEntity::Illumination(CBaseEntity *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000ad566. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*g_engfuncs.pfnGetEntityIllum)(this->pev->pContainingEntity);
  return iVar1;
}


